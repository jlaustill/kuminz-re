/*
 * Decompiled from: GanttChartFX.dll
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



// Function: AtlMultiply<unsigned_long> at 1000104a

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



// Function: AtlCoTaskMemCAlloc at 1000106c

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



// Function: FUN_10001099 at 10001099

LPVOID __cdecl FUN_10001099(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_100010c9 at 100010c9

bool __cdecl FUN_100010c9(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100010f6 at 100010f6

void FUN_100010f6(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_1000b678);
}



// Function: AtlCrtErrorCheck at 1000110e

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
    if (param_1 == 0x16) goto LAB_10001136;
    if (param_1 == 0x22) goto LAB_10001136;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_100010f6(uVar1);
LAB_10001136:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_10001146 at 10001146

void __cdecl FUN_10001146(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10001166 at 10001166

void __cdecl FUN_10001166(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 10001183

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



// Function: FUN_100011ac at 100011ac

void __fastcall FUN_100011ac(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100011be at 100011be

DWORD FUN_100011be(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_100011d3 at 100011d3

uint __cdecl FUN_100011d3(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_100011e9 at 100011e9

void __fastcall FUN_100011e9(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 100011f2

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
                    /* WARNING: Could not recover jumptable at 0x1000123b. Too many branches */
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



// Function: FID_conflict:RegCreateKeyExW at 10001249

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
                    /* WARNING: Could not recover jumptable at 0x1000129e. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 100012ac

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
                    /* WARNING: Could not recover jumptable at 0x100012ef. Too many branches */
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



// Function: FUN_100012fe at 100012fe

void __cdecl FUN_100012fe(short *param_1,int param_2,short *param_3)

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



// Function: FUN_1000134c at 1000134c

int __fastcall FUN_1000134c(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 10001363

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_1000e574 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_1000e570 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_1000e574 = '\x01';
    }
    if (DAT_1000e570 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_1000e570)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Close at 100013d3

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



// Function: Create at 100013ee

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



// Function: Open at 10001456

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



// Function: SetStringValue at 100014a5

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



// Function: FUN_100014dc at 100014dc

LSTATUS __thiscall FUN_100014dc(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_1000151f at 1000151f

undefined4 __fastcall FUN_1000151f(undefined4 *param_1)

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



// Function: FUN_1000153f at 1000153f

undefined4 * __thiscall FUN_1000153f(void *this,ulong param_1)

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



// Function: FUN_10001575 at 10001575

void __fastcall FUN_10001575(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_1000157f at 1000157f

undefined4 __thiscall FUN_1000157f(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10001099(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10001146((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_1000160d at 1000160d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000160d(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x10001619;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_1000e598 & 1) == 0) {
    DAT_1000e598 = DAT_1000e598 | 1;
    DAT_1000e57c = 8;
    _DAT_1000e584 = 0x4008;
    _DAT_1000e58c = 0x13;
    DAT_1000e578 = &DAT_1000a36c;
    DAT_1000e580 = &DAT_1000a368;
    _DAT_1000e588 = &DAT_1000a364;
    _DAT_1000e590 = &DAT_1000a360;
    _DAT_1000e594 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_1000e578)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x10001690;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_1000e57c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_1000169c;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_1000169c:
  *(undefined4 *)(puVar4 + -4) = 0x100016a1;
  return uVar2;
}



// Function: FUN_100016b5 at 100016b5

int __cdecl FUN_100016b5(ushort param_1)

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



// Function: FUN_100016eb at 100016eb

undefined4 __cdecl FUN_100016eb(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1000a468)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1000a46c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10001719 at 10001719

LPCWSTR __cdecl FUN_10001719(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10001746 at 10001746

undefined4 FUN_10001746(ushort param_1)

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



// Function: FUN_1000176c at 1000176c

void __fastcall FUN_1000176c(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10001746(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_1000178e at 1000178e

undefined4 __thiscall FUN_1000178e(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_1000176c((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_1000151f((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10001746(*pWVar2);
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



// Function: FUN_100018a4 at 100018a4

undefined4 FUN_100018a4(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1000a3c0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1000a3f0);
  return 1;
}



// Function: FUN_100018d3 at 100018d3

bool FUN_100018d3(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10001908 at 10001908

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10001908(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1000e52c ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_1000178e(this,param_1), -1 < iVar1)) {
    FUN_1000176c((undefined4 *)this);
    iVar1 = FUN_1000178e(this,local_2008);
    if (-1 < iVar1) {
      FUN_1000178e(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000196d at 1000196d

undefined4 FUN_1000196d(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1000e554;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000198c at 1000198c

undefined4 __thiscall FUN_1000198c(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_1000e55c = *param_3;
    DAT_1000e560 = param_3[1];
    DAT_1000e564 = param_3[2];
    DAT_1000e568 = param_3[3];
  }
  piVar2 = DAT_1000e82c;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_1000e82c, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_1000e82c = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_1000e82c;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_1000e830; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_100019ea at 100019ea

void FUN_100019ea(int param_1)

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



// Function: DllCanUnloadNow at 10001a2d

HRESULT DllCanUnloadNow(void)

{
                    /* 0x1a2d  1  DllCanUnloadNow */
  return (uint)(DAT_1000e5a4 != 0);
}



// Function: FUN_10001a60 at 10001a60

void __fastcall FUN_10001a60(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10001a75 at 10001a75

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10001a75(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10001aa3 at 10001aa3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10001aa3(undefined4 *param_1)

{
  FUN_10005dfc((int)param_1);
  *param_1 = ATL::CComObject<class_CGanttChartFXImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CGanttChartFXImpl>::vftable;
  (**(code **)(*DAT_1000e558 + 4))();
  return param_1;
}



// Function: AtlComQIPtrAssign at 10001ae3

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



// Function: Attach at 10001b1a

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



// Function: InlineIsEqualUnknown at 10001b39

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



// Function: AtlInternalQueryInterface at 10001b67

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
          if (pcVar1 == (code *)0x1) goto LAB_10001b9b;
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
LAB_10001b9b:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10001c31 at 10001c31

undefined4 FUN_10001c31(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_10001c4e at 10001c4e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001c4e(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CGanttChartFXImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CGanttChartFXImpl>::vftable;
  param_1[2] = 0xc0000001;
  (**(code **)(*DAT_1000e558 + 8))();
  FUN_1000590c((int)param_1);
  return;
}



// Function: FUN_10001c93 at 10001c93

undefined4 FUN_10001c93(int param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return *(undefined4 *)(param_1 + 8);
}



// Function: Release at 10001ca3

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
    (**(code **)(*in_stack_00000004 + 0x10))(1);
  }
  return uVar2;
}



// Function: FUN_10001cc4 at 10001cc4

undefined4 * __thiscall FUN_10001cc4(void *this,byte param_1)

{
  FUN_10001c4e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001ce3 at 10001ce3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001ce3(int param_1)

{
  FUN_1000590c(param_1);
  return;
}



// Function: FUN_10001d01 at 10001d01

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10001d01(void *this,undefined4 param_1)

{
  FUN_10005dfc((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CGanttChartFXImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CGanttChartFXImpl>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10001d3c at 10001d3c

void FUN_10001d3c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10001d4f at 10001d4f

void FUN_10001d4f(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10001d62 at 10001d62

void FUN_10001d62(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_10001d7a at 10001d7a

undefined4 __fastcall FUN_10001d7a(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10001d7e at 10001d7e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10001d7e(void *this,byte param_1)

{
  FUN_1000590c((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10001daf at 10001daf

void __fastcall FUN_10001daf(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10001dc9 at 10001dc9

void __fastcall FUN_10001dc9(undefined4 *param_1)

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



// Function: FUN_10001df6 at 10001df6

void __fastcall FUN_10001df6(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001e03 at 10001e03

void FUN_10001e03(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_10001e0d at 10001e0d

void FUN_10001e0d(int param_1)

{
  FUN_10001d4f(param_1 + -4);
  return;
}



// Function: FUN_10001e17 at 10001e17

void FUN_10001e17(int param_1)

{
  FUN_10001c93(param_1 + -4);
  return;
}



// Function: FUN_10001e21 at 10001e21

void FUN_10001e21(int param_1)

{
  FUN_10001d3c(param_1 + -4);
  return;
}



// Function: FUN_10001e2b at 10001e2b

void FUN_10001e2b(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10001d62(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10001e35 at 10001e35

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001e35(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_100084b3;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10001e5f at 10001e5f

int __thiscall FUN_10001e5f(void *this,undefined4 *param_1)

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



// Function: FUN_10001e96 at 10001e96

void __fastcall FUN_10001e96(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10001ea0 at 10001ea0

void __thiscall FUN_10001ea0(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_100010f6(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10001ec5

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_100010f6(lVar1);
  }
  return local_8;
}



// Function: FUN_10001eea at 10001eea

void FUN_10001eea(void)

{
  return;
}



// Function: FUN_10001eeb at 10001eeb

int __fastcall FUN_10001eeb(int param_1)

{
  long lVar1;
  
  FUN_1000134c(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1000e558 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1000e548 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10001f2c at 10001f2c

void __fastcall FUN_10001f2c(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_100019ea((int)piVar1);
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



// Function: FUN_10001f65 at 10001f65

void __fastcall FUN_10001f65(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_100019ea((int)piVar1);
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



// Function: FUN_10001f6a at 10001f6a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001f6a(int param_1)

{
  FUN_10001f2c(param_1);
  return;
}



// Function: FUN_10001f8d at 10001f8d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10001f8d(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10001f8d(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_100079dd();
  return;
}



// Function: FUN_10002072 at 10002072

undefined4 __fastcall FUN_10002072(int *param_1)

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
LAB_100020b7:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_100020b7;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10001dc9(param_1);
  return 0;
}



// Function: FUN_100020c9 at 100020c9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100020c9(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_1000157f(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10001daf(local_14);
  }
  return uVar1;
}



// Function: FUN_10002110 at 10002110

void FUN_10002110(int param_1)

{
  FUN_10002072((int *)(param_1 + 4));
  return;
}



// Function: FUN_10002122 at 10002122

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10002122(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x10002131;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_100022fc;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_100011be();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_1000218f;
      FUN_10001166(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_100022cc;
      }
    }
    else {
LAB_100022cc:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_1000218f:
  local_8 = 0xffffffff;
  FUN_10001daf(&local_248);
LAB_100022fc:
  FUN_100079dd();
  return;
}



// Function: FUN_10002304 at 10002304

void __fastcall FUN_10002304(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_1000e82c;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_1000e82c, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_1000e830; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10001f2c(param_1);
  return;
}



// Function: FUN_10002356 at 10002356

undefined4 FUN_10002356(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_1000198c(&DAT_1000e59c,(int *)&PTR_DAT_1000e000,param_1,(undefined4 *)&DAT_1000a370);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10002304(0x1000e59c);
  }
  return 1;
}



// Function: FUN_10002398 at 10002398

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10002398(void *this,wchar_t *param_1)

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
  local_8 = 0x100023a4;
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
      local_18 = (uint *)FUN_100076d2(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10001c08,
                   (_func_void_void_ptr *)&LAB_10001a3c);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_10002448();
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



// Function: Catch@10002438 at 10002438

undefined * Catch_10002438(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002442;
}



// Function: FUN_10002448 at 10002448

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10002448(void)

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



// Function: FUN_10002500 at 10002500

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10002500(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10001a3c);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_1000255d at 1000255d

void FUN_1000255d(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10002500(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10002590 at 10002590

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10002590(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10001aa3(puVar1);
    }
    uVar2 = FUN_100025ed();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100025e0 at 100025e0

undefined * Catch_100025e0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100025ea;
}



// Function: FUN_100025ed at 100025ed

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100025ed(void)

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
      (**(code **)(*unaff_ESI + 0x10))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: QueryInterface at 1000261d

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000a698,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10002637 at 10002637

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10002637(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CGanttChartFXImpl>::vftable;
  FUN_10001d01((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1000e558 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000267a at 1000267a

undefined4 FUN_1000267a(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: Release at 1000268a

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



// Function: FUN_100026ab at 100026ab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100026ab(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CGanttChartFXImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1000e558 + 8))();
  FUN_1000590c((int)(param_1 + 2));
  return;
}



// Function: FUN_100026f1 at 100026f1

long FUN_100026f1(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000a698,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000273d at 1000273d

undefined4 * __thiscall FUN_1000273d(void *this,byte param_1)

{
  FUN_100026ab((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002761 at 10002761

void __fastcall FUN_10002761(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10002771 at 10002771

void __fastcall FUN_10002771(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10001e96(param_1);
    return;
  }
  return;
}



// Function: FUN_1000277e at 1000277e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000277e(int param_1)

{
  FUN_10001e35((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000279f at 1000279f

void FUN_1000279f(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100027a9 at 100027a9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_100027a9(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_100027fd at 100027fd

void __fastcall FUN_100027fd(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10002814 at 10002814

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_10002814(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&PTR_1000a7a0,&local_18);
    (**(code **)*param_1)(param_1,&PTR_1000a7a0,local_14);
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



// Function: FUN_1000289f at 1000289f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_1000289f(undefined4 *param_1)

{
  FUN_10001eeb((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_1000e56c = param_1;
  return param_1;
}



// Function: FUN_100028d4 at 100028d4

void __fastcall FUN_100028d4(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100028df at 100028df

void __fastcall FUN_100028df(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100028ea at 100028ea

HRESULT __thiscall FUN_100028ea(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1000ac6c,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000a7dc,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10002936 at 10002936

undefined4 FUN_10002936(void)

{
  return 0x80004005;
}



// Function: FUN_1000293e at 1000293e

void FUN_1000293e(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_1000a7ec);
  return;
}



// Function: FUN_10002958 at 10002958

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10002958(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10001f2c((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000298f at 1000298f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000298f(int *param_1)

{
  FUN_10002072(param_1);
  FUN_10001dc9(param_1);
  return;
}



// Function: FUN_100029b9 at 100029b9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100029b9(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_10002072(param_1 + 1);
  FUN_1000298f(param_1 + 1);
  return;
}



// Function: FUN_100029ed at 100029ed

undefined4 FUN_100029ed(void)

{
  return 0x80004001;
}



// Function: FUN_100029f5 at 100029f5

undefined4 FUN_100029f5(void)

{
  return 1;
}



// Function: FUN_100029fb at 100029fb

undefined4 FUN_100029fb(void)

{
  return 0;
}



// Function: FUN_10002a00 at 10002a00

undefined4 * __thiscall FUN_10002a00(void *this,byte param_1)

{
  FUN_100029b9((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002a1f at 10002a1f

undefined4 __fastcall FUN_10002a1f(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10001e5f((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10002a60 at 10002a60

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10002a60(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10002a6c;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_1000153f(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_1000196d(&local_5d);
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
LAB_10002b55:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_10002bc9;
                }
                iVar3 = FUN_1000151f((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_1000157f(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_10002bef;
                  goto LAB_10002b91;
                }
                local_55 = '\0';
              }
              else {
LAB_10002b91:
                if (local_55 != '\0') goto LAB_10002bc9;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_100020c9(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_10002bef;
                local_56 = '\0';
              }
              goto LAB_10002bc9;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_100020c9(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_10002b55;
            }
LAB_10002bef:
            local_5c = -0x7ff8fff2;
            goto LAB_10002ad0;
          }
LAB_10002bc9:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_10001719(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_10002ad0;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_10002a1f(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_100020c9(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_10002bef;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_10002c62;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_10002ad0;
            }
            iVar3 = FUN_1000157f(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_10002bef;
          }
          else {
            iVar3 = FUN_1000157f(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_10002c62:
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
LAB_10002ad0:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_100079dd();
  return;
}



// Function: FUN_10002ccd at 10002ccd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10002ccd(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_1000ac5c), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_1000ac7c,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000a8dc,&local_1a8
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
          goto LAB_10002f58;
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
      FUN_10001daf(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_10002f58:
  FUN_100079dd();
  return;
}



// Function: FUN_10002feb at 10002feb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10002feb(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_10002122(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_1000196d((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_100030bb at 100030bb

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100030bb(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_10002122(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_1000196d(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_1000327d;
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
LAB_1000327d:
  FUN_100079dd();
  return;
}



// Function: FUN_10003285 at 10003285

int FUN_10003285(int param_1,int param_2,void *param_3)

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
          param_1 = FUN_10002ccd((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_100030bb(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000330b at 1000330b

int FUN_1000330b(int param_1,int param_2,void *param_3)

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
          iVar6 = FUN_10002ccd((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_10002feb(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10003392 at 10003392

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10003392(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&PTR_1000a7a0,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_1000344d;
          }
          else {
LAB_1000344d:
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



// Function: FUN_1000347d at 1000347d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000347d(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_100034c2();
  return uVar1;
}



// Function: Catch@100034b2 at 100034b2

undefined * Catch_100034b2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100034bc;
}



// Function: FUN_100034c2 at 100034c2

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100034c2(void)

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



// Function: FUN_1000351d at 1000351d

int __fastcall FUN_1000351d(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_10003521 at 10003521

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003521(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10001e35((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_10003552 at 10003552

undefined4 FUN_10003552(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10003590 at 10003590

undefined4 FUN_10003590(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1000e558 + 8))();
  }
  else {
    (**(code **)(*DAT_1000e558 + 4))();
  }
  return 0;
}



// Function: FUN_100035af at 100035af

undefined4 * __thiscall FUN_100035af(void *this,byte param_1)

{
  FUN_10003521((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100035ce at 100035ce

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100035ce(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x1c);
    if (this != (void *)0x0) {
      FUN_10002637(this,param_1);
    }
    uVar1 = FUN_10003635();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10003628 at 10003628

undefined * Catch_10003628(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003632;
}



// Function: FUN_10003635 at 10003635

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003635(void)

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



// Function: FUN_1000365f at 1000365f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000365f(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10001a75(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_1000369a at 1000369a

undefined4 __thiscall FUN_1000369a(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_100027a9(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 100036f1

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
    FUN_10001ea0(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10003720

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
    FUN_10001ea0(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000374f

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
    FUN_10001ea0(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000377e at 1000377e

IUnknown * __thiscall FUN_1000377e(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_10002814(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1000a958);
  }
  return pIVar2;
}



// Function: FUN_100037ab at 100037ab

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100037ab(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_100076d2(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10003811();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10003805 at 10003805

undefined * Catch_10003805(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000380f;
}



// Function: FUN_10003811 at 10003811

void FUN_10003811(void)

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
  uVar4 = FUN_100076d2(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10003862();
  return;
}



// Function: Catch@10003853 at 10003853

undefined * Catch_10003853(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10003860;
}



// Function: FUN_10003862 at 10003862

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10003862(void)

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
    FUN_10001146(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10001146(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_1000369a(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_100038be;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_100038be:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_100038f6 at 100038f6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100038f6(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_100037ab(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10001daf(local_14);
  }
  return iVar1;
}



// Function: FUN_10003951 at 10003951

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003951(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_10008a1c;
  local_10 = ExceptionList;
  uStack_2144 = DAT_1000e52c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_1000178e(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_1000160d(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_10003cca;
  FUN_1000176c((undefined4 *)this);
  iVar1 = FUN_1000178e(this,local_2018);
  if (iVar1 < 0) goto LAB_10003cca;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_10003ca6:
    if (uVar2 != 0) {
      FUN_100011d3(uVar2);
      goto LAB_10003cca;
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
        FUN_10003bd9();
        return;
      }
      goto LAB_10003cca;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10001daf((int *)&local_2124);
      goto LAB_10003ca6;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10003a72();
      return;
    }
  }
  FUN_1000178e(this,param_3);
LAB_10003cca:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10003a66 at 10003a66

undefined * Catch_10003a66(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10003a70;
}



// Function: FUN_10003a72 at 10003a72

void FUN_10003a72(void)

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
    pWVar2 = (WCHAR *)FUN_100014dc(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10001e96((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_1000178e(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_100011d3((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10003ce2;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10003bbe at 10003bbe

undefined * Catch_10003bbe(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10003bcb;
}



// Function: FUN_10003bd9 at 10003bd9

void FUN_10003bd9(void)

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
      FUN_10001e96((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_100016b5(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10001e96((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_1000178e(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_100011d3(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10003ce2;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10003ce6 at 10003ce6

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003ce6(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_10008a7b;
  local_10 = ExceptionList;
  local_14 = DAT_1000e52c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_10003d4a:
  iVar3 = FUN_1000178e(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_10003d5a:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_100041b7:
    if (*param_1 == L'}') goto LAB_10003d5a;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_1000178e(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10003d5a;
      if (param_3 == 0) goto LAB_10003e99;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_10001719(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_100018a4(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10001f8d(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_10003e99;
        }
        iVar3 = FUN_1000178e(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10001908(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_100042b6;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_10004335;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_10003d5a;
    }
LAB_10003e99:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_1000178e(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10003d5a;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10001719(param_1,L'\\');
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
          iVar3 = FUN_1000178e(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10001908(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_10003ce6(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_1000178e(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_10004354;
          iVar3 = FUN_1000178e(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10003951(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_100042bb;
        }
      }
      goto LAB_10003d5a;
    }
    iVar3 = FUN_1000178e(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_1000178e(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_10003d5a;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10003951(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_100042b6;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_10004335;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_100011d3(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_10004335:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_10003d5a;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10001908(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_100018d3(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_100018a4(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10001f8d(&local_2234,local_21c);
        }
        goto LAB_100041b7;
      }
      bVar2 = FUN_100018d3(local_2234);
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
            FUN_100011d3(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_10004335;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_100042b6:
          ATL::CRegKey::Close(pCVar8);
LAB_100042bb:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_10003ce6(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_10003d4a;
            goto LAB_10003d5a;
          }
        }
        goto LAB_100041b7;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_100041b7;
    }
LAB_10004354:
    FUN_100011d3(uVar6);
    goto LAB_10003d5a;
  }
  goto LAB_100041b7;
}



// Function: FUN_1000437d at 1000437d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000437d(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000e834);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&PTR_1000a7a0,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000e834);
          if (*piVar2 != 0) goto LAB_10004411;
        }
        else {
LAB_10004411:
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
  piVar2 = FUN_10003392((int *)&DAT_1000e824,param_1,param_2,param_3);
  return piVar2;
}



// Function: DllGetClassObject at 10004449

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x4449  2  DllGetClassObject */
  piVar1 = FUN_1000437d(&DAT_1000e59c,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_10004457 at 10004457

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10004457(void *this,undefined4 param_1)

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
  local_8 = 0x10004466;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_1000469c;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1000e558 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_1000e55c,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_1000e850,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10004666;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001daf((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_1000a770,&local_224);
        if (-1 < iVar2) {
          FUN_1000377e(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_1000e558 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_1000e558 + 4;
        }
        pcVar4 = FUN_1000255d;
        pvVar5 = this;
        FUN_1000347d(iVar2);
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
LAB_10004666:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10002398(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_1000469c:
  FUN_100079dd();
  return;
}



// Function: FUN_100046a4 at 100046a4

void FUN_100046a4(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10002590(0,param_2,param_3);
    return;
  }
  FUN_100035ce(param_1,param_2,param_3);
  return;
}



// Function: FUN_100046c4 at 100046c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100046c4(undefined4 *param_1)

{
  FUN_1000365f(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_100046f2 at 100046f2

LONG FUN_100046f2(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1000e558 + 4))();
  }
  return LVar1;
}



// Function: FUN_1000471c at 1000471c

LONG FUN_1000471c(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1000e558 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 1000475b

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000a984,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10004775 at 10004775

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004775(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10003521(param_1);
  return;
}



// Function: FUN_100047a4 at 100047a4

undefined4 * __thiscall FUN_100047a4(void *this,byte param_1)

{
  FUN_10004775((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100047c3 at 100047c3

void FUN_100047c3(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10003285(0x1000e824,param_1,param_2);
  if ((-1 < iVar1) && (DAT_1000e54c != (code *)0x0)) {
    (*DAT_1000e54c)(DAT_1000e850);
  }
  return;
}



// Function: FUN_100047f1 at 100047f1

void FUN_100047f1(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_1000e550 != (code *)0x0) && (iVar1 = (*DAT_1000e550)(), iVar1 < 0)) {
    return;
  }
  FUN_1000330b(0x1000e824,param_1,param_2);
  return;
}



// Function: FUN_10004817 at 10004817

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10004817(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1000e52c ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10002a60(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_1000490d:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10004862:
  if ((((sVar1 == 0) || (iVar3 = FUN_1000178e(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_100016eb(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_1000178e(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_100048ff;
  if (param_2 == 0) {
    iVar3 = FUN_10003ce6(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_100048ff;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_10003ce6(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_10003ce6(this,local_2008,pHVar4,0,0);
LAB_100048ff:
      CoTaskMemFree(local_200c);
      goto LAB_1000490d;
    }
  }
  FUN_1000176c((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10004862;
}



// Function: FUN_1000494e at 1000494e

int __thiscall FUN_1000494e(void *this,int param_1,void *param_2)

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
        iVar5 = FUN_10002ccd((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_100047c3(param_1,param_2);
  return iVar5;
}



// Function: FUN_100049bd at 100049bd

int __thiscall FUN_100049bd(void *this,int param_1,void *param_2)

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
        iVar5 = FUN_10002ccd((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_100047f1(param_1,param_2);
  return iVar5;
}



// Function: DllRegisterServer at 10004a2c

void DllRegisterServer(void)

{
                    /* 0x4a2c  3  DllRegisterServer */
  FUN_1000494e(&DAT_1000e59c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10004a3b

void DllUnregisterServer(void)

{
                    /* 0x4a3b  4  DllUnregisterServer */
  FUN_100049bd(&DAT_1000e59c,1,(void *)0x0);
  return;
}



// Function: FUN_10004a4a at 10004a4a

undefined4 __thiscall FUN_10004a4a(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10004457(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10004a8a at 10004a8a

undefined4 __thiscall
FUN_10004a8a(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10004457(this,param_4);
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



// Function: FUN_10004b2b at 10004b2b

void __thiscall
FUN_10004b2b(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10004457(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10004b6e at 10004b6e

undefined4 FUN_10004b6e(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10004a4a(&PTR_DAT_1000e49c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10004b92 at 10004b92

void FUN_10004b92(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10004a8a(&PTR_DAT_1000e49c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10004bb2 at 10004bb2

void FUN_10004bb2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10004b2b(&PTR_DAT_1000e49c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: Catch@10004c1e at 10004c1e

undefined1 * Catch_10004c1e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10004c28;
}



// Function: FUN_10004c70 at 10004c70

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10004c70(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_100011be();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_100011be();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_10004d4a();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10001e96(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10001daf(&local_42c);
  FUN_100079ec();
  return;
}



// Function: Catch@10004d35 at 10004d35

undefined * Catch_10004d35(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10004d42;
}



// Function: FUN_10004d4a at 10004d4a

void FUN_10004d4a(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_100011be();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10004817((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10001e96((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001daf((int *)(unaff_EBP + -0x428));
  FUN_100079ec();
  return;
}



// Function: FUN_10004dd4 at 10004dd4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004dd4(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10004c70(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001daf(local_14);
  return uVar1;
}



// Function: FUN_10004e15 at 10004e15

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004e15(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001daf(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10004c70(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001daf(local_14);
  }
  return uVar1;
}



// Function: FUN_10004e71 at 10004e71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004e71(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10004c70(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001daf(local_14);
  return uVar1;
}



// Function: FUN_10004eb1 at 10004eb1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004eb1(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001daf(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10004c70(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001daf(local_14);
  }
  return uVar1;
}



// Function: FUN_10004f0c at 10004f0c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10004f0c(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_100038f6(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_1000e850;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1000e850,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_100011be();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001daf((int *)&local_a48);
        goto LAB_10004f8e;
      }
      FUN_100012fe(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_100010c9(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001daf((int *)&local_a48);
          goto LAB_10004f8e;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_100038f6(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_100038f6(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10004eb1(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_10004e15(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001daf((int *)&local_a48);
  }
LAB_10004f8e:
  local_8 = 0xffffffff;
  FUN_100029b9(&local_a60);
  FUN_100079dd();
  return;
}



// Function: FUN_1000510f at 1000510f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000510f(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_100038f6(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_1000e850;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_1000e850,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_100011be();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001daf((int *)&local_a48);
        goto LAB_10005188;
      }
      FUN_100012fe(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_100010c9(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001daf((int *)&local_a48);
          goto LAB_10005188;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_100038f6(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_100038f6(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10004e71(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10004dd4(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001daf((int *)&local_a48);
  }
LAB_10005188:
  local_8 = 0xffffffff;
  FUN_100029b9(&local_a5c);
  FUN_100079dd();
  return;
}



// Function: FUN_10005306 at 10005306

void FUN_10005306(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_10004f0c(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000530f at 1000530f

void FUN_1000530f(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_1000510f(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10005318 at 10005318

void FUN_10005318(int param_1)

{
  FUN_1000510f((int *)&DAT_1000e59c,0xc9,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005333 at 10005333

int __cdecl FUN_10005333(ushort *param_1,ushort *param_2,int param_3)

{
  if (param_3 != 0) {
    do {
      if (*param_1 != *param_2) {
        return (-(uint)(*param_1 < *param_2) & 0xfffffffe) + 1;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return 0;
}



// Function: AtlThrowLastWin32 at 10005367

/* Library Function - Single Match
    void __stdcall ATL::AtlThrowLastWin32(void)
   
   Library: Visual Studio 2010 Release */

void ATL::AtlThrowLastWin32(void)

{
  code *pcVar1;
  DWORD DVar2;
  
  DVar2 = GetLastError();
  if (0 < (int)DVar2) {
    DVar2 = DVar2 & 0xffff | 0x80070000;
  }
  FUN_100010f6(DVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: QueryStringValue at 10005382

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::QueryStringValue(wchar_t const *,wchar_t *,unsigned long
   *)
   
   Library: Visual Studio 2010 Release */

long __thiscall
ATL::CRegKey::QueryStringValue(CRegKey *this,wchar_t *param_1,wchar_t *param_2,ulong *param_3)

{
  ulong uVar1;
  ulong *puVar2;
  LSTATUS LVar3;
  long lVar4;
  uint local_8;
  
  puVar2 = param_3;
  uVar1 = *param_3;
  *param_3 = 0;
  local_8 = uVar1 * 2;
  LVar3 = RegQueryValueExW(*(HKEY *)this,param_1,(LPDWORD)0x0,(LPDWORD)&param_3,(LPBYTE)param_2,
                           &local_8);
  if (LVar3 != 0) {
    return LVar3;
  }
  if ((param_3 == (ulong *)0x1) || (param_3 == (ulong *)0x2)) {
    if (param_2 != (wchar_t *)0x0) {
      if (local_8 == 0) {
        *param_2 = L'\0';
      }
      else if (((local_8 & 1) != 0) ||
              (*(short *)((int)param_2 + ((local_8 & 0xfffffffe) - 2)) != 0)) goto LAB_100053be;
    }
    *puVar2 = local_8 >> 1;
    lVar4 = 0;
  }
  else {
LAB_100053be:
    lVar4 = 0xd;
  }
  return lVar4;
}



// Function: FUN_10005416 at 10005416

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_10005416(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_1000544e at 1000544e

ULONG __fastcall FUN_1000544e(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[2].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1000aa24);
  }
  return UVar1;
}



// Function: FUN_1000546f at 1000546f

undefined4 __thiscall FUN_1000546f(void *this,IID *param_1,void **param_2)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x390))(this,param_1,param_2);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000aa24);
  }
  return 0;
}



// Function: FUN_100054a8 at 100054a8

uint __fastcall FUN_100054a8(IUnknown *param_1)

{
  uint uVar1;
  uint extraout_EAX;
  
  uVar1 = (*param_1->lpVtbl[0x4c].AddRef)(param_1);
  if ((int)uVar1 < 0) {
    _com_issue_errorex(uVar1,param_1,(_GUID *)&DAT_1000aa24);
    uVar1 = extraout_EAX;
  }
  return uVar1 & 0xffff0000;
}



// Function: FUN_100054dc at 100054dc

undefined4 __fastcall FUN_100054dc(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[0x4c].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1000aa24);
  }
  return 0;
}



// Function: FUN_10005512 at 10005512

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10005512(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 0x10;
  local_1c = 0;
  local_8 = 0;
  local_18[0] = 0;
  (**(code **)(*param_2 + 0x20))(param_2,local_18);
  iVar2 = 1;
  while( true ) {
    if (local_18[0] < iVar2) {
      return local_1c;
    }
    param_2 = (int *)0x0;
    (**(code **)(*piVar1 + 0x1c))(piVar1,iVar2,&param_2);
    local_1c = (**(code **)(*param_1 + 0x38))(param_1,iVar2,param_2);
    if (local_1c < 0) break;
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@10005586 at 10005586

undefined4 Catch_10005586(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000557b;
}



// Function: FUN_10005590 at 10005590

undefined4 FUN_10005590(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 8);
  }
  return 0;
}



// Function: FUN_100055a8 at 100055a8

undefined4 FUN_100055a8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return 0;
}



// Function: FUN_100055ba at 100055ba

undefined4 FUN_100055ba(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_1000e4f0 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_100055e6 at 100055e6

void __fastcall FUN_100055e6(int *param_1)

{
  if (*param_1 == 0) {
    FUN_100076e0(0x80004003);
  }
  return;
}



// Function: FUN_100055f7 at 100055f7

uint __thiscall FUN_100055f7(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

{
  undefined4 *extraout_EAX;
  uint uVar1;
  uint extraout_ECX;
  uint extraout_EDX;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
    std::_Xout_of_range("invalid string position");
    this = extraout_EAX;
    param_1 = extraout_ECX;
    uVar1 = extraout_EDX;
  }
  if (uVar1 - param_1 < param_2) {
    param_2 = uVar1 - param_1;
  }
  uVar1 = param_2;
  if (param_4 <= param_2) {
    uVar1 = param_4;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  uVar1 = FUN_10005333((ushort *)((int)this + param_1 * 2),param_3,uVar1);
  if (uVar1 == 0) {
    if (param_2 < param_4) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (uint)(param_2 != param_4);
    }
  }
  return uVar1;
}



// Function: _Inside at 1000565b

/* Library Function - Single Match
    public: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Inside(char const *)
   
   Library: Visual Studio 2010 Release */

bool __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Inside
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  
  if (param_1 != (char *)0x0) {
    pbVar1 = this;
    if (0xf < *(uint *)(this + 0x14)) {
      pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                this;
    }
    if (pbVar1 <= param_1) {
      pbVar1 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  this;
      }
      if (param_1 < pbVar1 + *(int *)(this + 0x10)) {
        return true;
      }
    }
  }
  return false;
}



// Function: FID_conflict:_Inside at 10005696

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



// Function: FUN_100056d2 at 100056d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100056d2(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100056de;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1000c170);
}



// Function: FUN_10005731 at 10005731

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_10005731(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000573d;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1000c170);
  }
  return;
}



// Function: FUN_100057bd at 100057bd

void __cdecl FUN_100057bd(int *param_1,size_t param_2,void *param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int *unaff_ESI;
  undefined4 uVar3;
  
  if (param_1 != (int *)0x0) goto LAB_100057d3;
  do {
    uVar3 = 0x80070057;
    while( true ) {
      FUN_100010f6(uVar3);
LAB_100057d3:
      if (((int)param_2 < 0) || (param_3 == (void *)0x0)) break;
      pvVar2 = (void *)*param_1;
      if (pvVar2 == param_3) {
        if ((int)param_2 <= param_4) goto LAB_1000580c;
        pvVar2 = calloc(param_2,1);
LAB_10005827:
        *param_1 = (int)pvVar2;
LAB_1000580e:
        iVar1 = *param_1;
        param_1 = unaff_ESI;
        if (iVar1 != 0) {
          return;
        }
      }
      else {
        if ((int)param_2 <= param_4) {
          free(pvVar2);
LAB_1000580c:
          *param_1 = (int)param_3;
          goto LAB_1000580e;
        }
        pvVar2 = _recalloc(pvVar2,param_2,1);
        if (pvVar2 != (void *)0x0) goto LAB_10005827;
      }
      uVar3 = 0x8007000e;
    }
  } while( true );
}



// Function: FUN_1000582b at 1000582b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

LPWSTR __cdecl FUN_1000582b(LPCSTR param_1,int param_2)

{
  int cchWideChar;
  LPWSTR lpWideCharStr;
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
LAB_1000589c:
    lpWideCharStr = (LPWSTR)0x0;
  }
  else {
    local_14[0] = 0;
    local_8 = 0;
    cchWideChar = MultiByteToWideChar(3,0,param_1,param_2,(LPWSTR)0x0,0);
    iVar1 = cchWideChar;
    if (param_2 == -1) {
      iVar1 = cchWideChar + -1;
    }
    lpWideCharStr = (LPWSTR)Ordinal_4(0,iVar1);
    if (lpWideCharStr != (LPWSTR)0x0) {
      iVar1 = MultiByteToWideChar(3,0,param_1,param_2,lpWideCharStr,cchWideChar);
      if (iVar1 != cchWideChar) {
        Ordinal_6(lpWideCharStr);
        local_8 = 0xffffffff;
        FUN_10001daf(local_14);
        goto LAB_1000589c;
      }
    }
    local_8 = 0xffffffff;
    FUN_10001daf(local_14);
  }
  return lpWideCharStr;
}



// Function: CComBSTR at 100058b5

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(char const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,char *param_1)

{
  LPWSTR pWVar1;
  
  if (param_1 != (char *)0x0) {
    pWVar1 = FUN_1000582b(param_1,-1);
    *(LPWSTR *)this = pWVar1;
    if (pWVar1 != (LPWSTR)0x0) {
      return this;
    }
    FUN_100010f6(0x8007000e);
  }
  *(undefined4 *)this = 0;
  return this;
}



// Function: FUN_100058e7 at 100058e7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100058e7(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000590c at 1000590c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000590c(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000593b at 1000593b

void FUN_1000593b(int param_1,undefined4 *param_2)

{
  (**(code **)*param_2)(param_2,&DAT_1000aa24,param_1 + 0xc);
  return;
}



// Function: FUN_10005956 at 10005956

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005956(int param_1)

{
  if (*(IUnknown **)(param_1 + 0xc) == (IUnknown *)0x0) {
                    /* WARNING: Subroutine does not return */
    _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
  }
  FUN_1000544e(*(IUnknown **)(param_1 + 0xc));
  return 0;
}



// Function: Catch@10005996 at 10005996

undefined4 Catch_10005996(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000598b;
}



// Function: FUN_100059a0 at 100059a0

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100059a0(int param_1,wchar_t *param_2)

{
  int *piVar1;
  size_t sVar2;
  undefined4 *puVar3;
  wchar_t *local_224;
  CHAR local_220;
  undefined1 local_21f [535];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x218;
  local_8 = 0x100059af;
  local_224 = param_2;
  sVar2 = wcslen(param_2);
  local_220 = '\0';
  memset(local_21f,0,0x207);
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
    _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
  }
  WideCharToMultiByte(0,0x400,local_224,sVar2 * 2,&local_220,sVar2 * 2,(LPCSTR)0x0,(LPBOOL)0x0);
  piVar1 = *(int **)(param_1 + 0xc);
  puVar3 = (undefined4 *)ATL::CComBSTR::CComBSTR((CComBSTR *)&local_224,&local_220);
  local_8._0_1_ = 1;
  (**(code **)(*piVar1 + 0x30c))(piVar1,2,*puVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_224);
  local_8 = 0xffffffff;
  FUN_100079ec();
  return;
}



// Function: Catch@10005a6d at 10005a6d

undefined4 Catch_10005a6d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10005a5f;
}



// Function: FUN_10005a77 at 10005a77

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10005a77(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(void **)(param_1 + 0xc) != (void *)0x0) &&
      (iVar1 = FUN_1000546f(*(void **)(param_1 + 0xc),(IID *)0x1,(void **)0x0), -1 < iVar1)) &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x2ec))
                        (*(int **)(param_1 + 0xc),0,param_2,(double)param_3), -1 < iVar1)) {
    uVar2 = FUN_100054a8(*(IUnknown **)(param_1 + 0xc));
    if (-1 < (short)uVar2) {
      return (int)(short)uVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@10005af7 at 10005af7

undefined4 Catch_10005af7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10005aec;
}



// Function: FUN_10005b01 at 10005b01

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10005b01(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int local_1c;
  int local_18 [4];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 0x10;
  local_1c = 0;
  local_8 = 0;
  local_18[0] = 0;
  (**(code **)(*param_2 + 0x20))(param_2,local_18);
  iVar2 = 1;
  while( true ) {
    if (local_18[0] < iVar2) {
      return local_1c;
    }
    param_2 = (int *)Ordinal_2(&DAT_1000a7ec);
    if (param_2 == (int *)0x0) {
      FUN_100010f6(0x8007000e);
    }
    local_8._0_1_ = 1;
    (**(code **)(*piVar1 + 0x1c))(piVar1,iVar2,&param_2);
    local_1c = (**(code **)(*param_1 + 0x50))(param_1,iVar2 + -1,param_2);
    if (local_1c < 0) break;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(param_2);
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@10005b9a at 10005b9a

undefined4 Catch_10005b9a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10005b8f;
}



// Function: FUN_10005ba4 at 10005ba4

void __thiscall FUN_10005ba4(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FUN_100055f7(this,0,*(uint *)((int)this + 0x10),(ushort *)param_1,sVar1);
  return;
}



// Function: FID_conflict:_Tidy at 10005bc9

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



// Function: FUN_10005c12 at 10005c12

void __fastcall FUN_10005c12(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: FUN_10005c24 at 10005c24

undefined4 * __thiscall FUN_10005c24(void *this,uint param_1,uint param_2)

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
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar3 = *this;
    }
    memmove((void *)((int)pvVar4 + param_1),(void *)((int)pvVar3 + param_2 + param_1),
            uVar1 - param_2);
    iVar2 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar2;
    pvVar3 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
    }
    *(undefined1 *)((int)pvVar3 + iVar2) = 0;
  }
  return (undefined4 *)this;
}



// Function: Init at 10005c9e

/* Library Function - Single Match
    private: void __thiscall ATL::CW2AEX<128>::Init(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

void __thiscall ATL::CW2AEX<128>::Init(CW2AEX<128> *this,wchar_t *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  size_t cbMultiByte;
  bool bVar4;
  
  if (param_1 == (wchar_t *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
    iVar1 = iVar1 + 1;
    FUN_100057bd((int *)this,iVar1 * 4,this + 4,0x80);
    iVar2 = WideCharToMultiByte(param_2,0,param_1,iVar1,*(LPSTR *)this,iVar1 * 4,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    bVar4 = iVar2 == 0;
    if (bVar4) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        cbMultiByte = WideCharToMultiByte(param_2,0,param_1,iVar1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                          (LPBOOL)0x0);
        FUN_100057bd((int *)this,cbMultiByte,this + 4,0x80);
        iVar1 = WideCharToMultiByte(param_2,0,param_1,iVar1,*(LPSTR *)this,cbMultiByte,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        bVar4 = iVar1 == 0;
      }
      if (bVar4) {
        AtlThrowLastWin32();
      }
    }
  }
  return;
}



// Function: FUN_10005d60 at 10005d60

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10005d60(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x20))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000aa14);
  }
  *param_1 = 0;
  return;
}



// Function: FUN_10005dae at 10005dae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10005dae(void *this,ulong *param_1)

{
  int iVar1;
  ulong local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10005dba;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x240))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000aa24);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_10005dfc at 10005dfc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005dfc(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// Function: FUN_10005e27 at 10005e27

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10005e27(int param_1,wchar_t *param_2)

{
  int *piVar1;
  size_t sVar2;
  undefined4 *puVar3;
  undefined4 local_230;
  int *local_22c;
  int *local_228;
  int local_224;
  CHAR local_220;
  undefined1 local_21f [535];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x220;
  local_224 = 0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    local_224 = -0x7fffbffd;
  }
  else {
    local_228 = (int *)0x0;
    local_22c = (int *)0x0;
    local_8._1_3_ = 0;
    local_8._0_1_ = 4;
    local_224 = (**(code **)(**(int **)(param_1 + 0xc) + 0x240))
                          (*(int **)(param_1 + 0xc),&local_228);
    if (-1 < local_224) {
      local_224 = (**(code **)(*local_228 + 0x20))(local_228,2,&local_22c);
      if (-1 < local_224) {
        sVar2 = wcslen(param_2);
        local_220 = '\0';
        memset(local_21f,0,0x207);
        WideCharToMultiByte(0,0x400,param_2,sVar2 * 2,&local_220,sVar2 * 2,(LPCSTR)0x0,(LPBOOL)0x0);
        piVar1 = local_22c;
        puVar3 = (undefined4 *)ATL::CComBSTR::CComBSTR((CComBSTR *)&local_230,&local_220);
        local_8._0_1_ = 5;
        local_224 = (**(code **)(*piVar1 + 0xb0))(piVar1,*puVar3);
        local_8._0_1_ = 4;
        Ordinal_6(local_230);
        if (-1 < local_224) {
          local_8._0_1_ = 2;
          if (local_22c != (int *)0x0) {
            (**(code **)(*local_22c + 8))(local_22c);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          if (local_228 != (int *)0x0) {
            (**(code **)(*local_228 + 8))(local_228);
          }
          local_8 = 0xffffffff;
          FUN_100079ec();
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@10005f80 at 10005f80

undefined4 Catch_10005f80(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10005f72;
}



// Function: FUN_10005f8a at 10005f8a

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10005f8a(int param_1,wchar_t *param_2)

{
  int *piVar1;
  size_t sVar2;
  undefined4 *puVar3;
  undefined4 local_230;
  int *local_22c;
  int *local_228;
  int local_224;
  CHAR local_220;
  undefined1 local_21f [535];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x220;
  local_224 = 0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    local_224 = -0x7fffbffd;
  }
  else {
    local_228 = (int *)0x0;
    local_22c = (int *)0x0;
    local_8._1_3_ = 0;
    local_8._0_1_ = 4;
    local_224 = (**(code **)(**(int **)(param_1 + 0xc) + 0x240))
                          (*(int **)(param_1 + 0xc),&local_228);
    if (-1 < local_224) {
      local_224 = (**(code **)(*local_228 + 0x20))(local_228,0,&local_22c);
      if (-1 < local_224) {
        sVar2 = wcslen(param_2);
        local_220 = '\0';
        memset(local_21f,0,0x207);
        WideCharToMultiByte(0,0x400,param_2,sVar2 * 2,&local_220,sVar2 * 2,(LPCSTR)0x0,(LPBOOL)0x0);
        piVar1 = local_22c;
        puVar3 = (undefined4 *)ATL::CComBSTR::CComBSTR((CComBSTR *)&local_230,&local_220);
        local_8._0_1_ = 5;
        local_224 = (**(code **)(*piVar1 + 0xb0))(piVar1,*puVar3);
        local_8._0_1_ = 4;
        Ordinal_6(local_230);
        if (-1 < local_224) {
          local_8._0_1_ = 2;
          if (local_22c != (int *)0x0) {
            (**(code **)(*local_22c + 8))(local_22c);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          if (local_228 != (int *)0x0) {
            (**(code **)(*local_228 + 8))(local_228);
          }
          local_8 = 0xffffffff;
          FUN_100079ec();
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@100060e2 at 100060e2

undefined4 Catch_100060e2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100060d4;
}



// Function: FUN_100060ec at 100060ec

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x100061af) */
/* WARNING: Removing unreachable block (ram,0x100061c3) */

int FUN_100060ec(int param_1,float param_2,float param_3)

{
  int iVar1;
  
  if ((((*(int *)(param_1 + 0xc) != 0) &&
       (iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x240))(*(int **)(param_1 + 0xc)),
       -1 < iVar1)) && (iVar1 = (**(code **)(iRam00000000 + 0x20))(0,0), -1 < iVar1)) &&
     (((iVar1 = (**(code **)(iRam00000000 + 0x20))(0,(double)param_2), -1 < iVar1 &&
       (iVar1 = (**(code **)(iRam00000000 + 0x28))(0,(double)param_3), -1 < iVar1)) &&
      (iVar1 = (**(code **)(iRam00000000 + 0x50))(0), -1 < iVar1)))) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@100061d9 at 100061d9

undefined4 Catch_100061d9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100061ce;
}



// Function: FUN_100061e3 at 100061e3

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x100062a1) */
/* WARNING: Removing unreachable block (ram,0x100062b5) */

int FUN_100061e3(int param_1,float param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((*(int *)(param_1 + 0xc) != 0) &&
       (iVar1 = FUN_1000546f(*(void **)(param_1 + 0xc),(IID *)0x2,(void **)0x1), -1 < iVar1)) &&
      (iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x244))(*(int **)(param_1 + 0xc)),
      -1 < iVar1)) &&
     ((iVar1 = (**(code **)(iRam00000000 + 0x20))(0,0), -1 < iVar1 &&
      (iVar1 = (**(code **)(iRam00000000 + 0x48))(0,(double)param_2), -1 < iVar1)))) {
    uVar2 = FUN_100054a8(*(IUnknown **)(param_1 + 0xc));
    if (-1 < (short)uVar2) {
      return (int)(short)uVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@100062cb at 100062cb

undefined4 Catch_100062cb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100062c0;
}



// Function: FUN_100062d5 at 100062d5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100062d5(void **param_1,int *param_2)

{
  void **ppvVar1;
  undefined4 uVar2;
  int iVar3;
  float local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_8;
  undefined4 uStack_4;
  
  ppvVar1 = param_1;
  uStack_4 = 0x18;
  local_18 = 0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (param_1[3] == (void *)0x0) {
    local_18 = -0x7fffbffd;
  }
  else {
    local_24 = (int *)0x0;
    local_8._1_3_ = 0;
    local_8._0_1_ = 2;
    param_1 = (void **)0x0;
    local_18 = (**(code **)(*param_2 + 0x20))(param_2,&param_1);
                    /* WARNING: Load size is inaccurate */
    if (((-1 < local_18) && (local_18 = FUN_1000546f(ppvVar1[3],(IID *)0x2,param_1), -1 < local_18))
       && (local_18 = (**(code **)(*ppvVar1[3] + 0x244))(ppvVar1[3],&local_24), -1 < local_18)) {
      local_1c = 0;
      while( true ) {
        iVar3 = (int)(short)local_1c;
        if ((int)param_1 <= iVar3) break;
        local_20 = (int *)0x0;
        local_8._0_1_ = 4;
        local_18 = (**(code **)(*local_24 + 0x20))(local_24,local_1c,&local_20);
        if (local_18 < 0) goto LAB_100062fa;
        local_28 = 0.0;
        (**(code **)(*param_2 + 0x1c))(param_2,iVar3 + 1,&local_28);
        local_18 = (**(code **)(*local_20 + 0x48))(local_20,(double)local_28);
        if (local_18 < 0) goto LAB_100062fa;
        local_8._0_1_ = 2;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
        }
        local_1c = local_1c + 1;
      }
      uVar2 = FUN_100054a8((IUnknown *)ppvVar1[3]);
      local_18 = (int)(short)uVar2;
      if (-1 < local_18) {
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_24 != (int *)0x0) {
          (**(code **)(*local_24 + 8))(local_24);
        }
        return local_18;
      }
    }
  }
LAB_100062fa:
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@10006404 at 10006404

undefined4 Catch_10006404(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100063f9;
}



// Function: ~basic_string<> at 1000640e

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



// Function: FUN_10006418 at 10006418

undefined4 * __thiscall FUN_10006418(void *this,uint param_1,uint param_2)

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



// Function: _Tidy at 10006499

/* Library Function - Single Match
    public: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Tidy(bool,unsigned int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2019 Release */

void __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          bool param_1,uint param_2)

{
  void *_Src;
  
  if ((param_1) && (0xf < *(uint *)(this + 0x14))) {
    _Src = *(void **)this;
    if (param_2 != 0) {
      memcpy(this,_Src,param_2);
    }
    operator_delete(_Src);
  }
  *(uint *)(this + 0x10) = param_2;
  *(undefined4 *)(this + 0x14) = 0xf;
  this[param_2] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  return;
}



// Function: FUN_100064dd at 100064dd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_100064dd(void *this,uint param_1)

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
  FUN_100056d2((char *)(param_1 + 1));
  FUN_10006572();
  return;
}



// Function: Catch@10006544 at 10006544

undefined * Catch_10006544(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100056d2((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000656c;
}



// Function: FUN_10006572 at 10006572

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10006572(void)

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



// Function: Catch@100065c0 at 100065c0

void Catch_100065c0(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100065d5 at 100065d5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_100065d5(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 | 0xf;
  if (uVar3 != 0xffffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = 0xfffffffe, uVar1 <= -uVar2 - 2)) {
      param_1 = uVar2 + uVar1;
    }
  }
  FUN_10005731((char *)(param_1 + 1));
  FUN_10006665();
  return;
}



// Function: Catch@10006637 at 10006637

undefined * Catch_10006637(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_10005731((char *)(iVar1 + 1));
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000665f;
}



// Function: FUN_10006665 at 10006665

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10006665(void)

{
  size_t _Size;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  int unaff_EBP;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_ESI;
  uint unaff_EDI;
  
  _Size = *(size_t *)(unaff_EBP + 0xc);
  if (_Size != 0) {
    pbVar1 = unaff_ESI;
    if (0xf < *(uint *)(unaff_ESI + 0x14)) {
      pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                unaff_ESI;
    }
    memcpy(*(void **)(unaff_EBP + -0x18),pbVar1,_Size);
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (unaff_ESI,true,0);
  pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
            (unaff_EBP + -0x18);
  *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)unaff_ESI =
       pbVar1;
  *(uint *)(unaff_ESI + 0x14) = unaff_EDI;
  *(size_t *)(unaff_ESI + 0x10) = _Size;
  if (unaff_EDI < 0x10) {
    pbVar1 = unaff_ESI;
  }
  pbVar1[_Size] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  return;
}



// Function: Catch@100066ae at 100066ae

void Catch_100066ae(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x1c),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100066c3 at 100066c3

void __fastcall
FUN_100066c3(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_100066cd at 100066cd

bool __thiscall FUN_100066cd(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_100064dd(this,param_1);
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



// Function: FUN_10006737 at 10006737

bool __thiscall FUN_10006737(void *this,uint param_1,char param_2)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *extraout_ECX;
  
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_100065d5(this,param_1);
  }
  else if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        this = *this;
      }
      *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this =
           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    }
  }
  else {
    uVar1 = *(uint *)((int)this + 0x10);
    if (param_1 < *(uint *)((int)this + 0x10)) {
      uVar1 = param_1;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
               true,uVar1);
  }
  return param_1 != 0;
}



// Function: FUN_1000679c at 1000679c

undefined4 * __thiscall FUN_1000679c(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10006418(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10006418(this,0,param_2);
  }
  else {
    bVar1 = FUN_100066cd(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 10006838

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
    bVar1 = FUN_100066cd(this,param_2,'\0');
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
    this = FUN_1000679c(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_100068b6 at 100068b6

undefined4 * __thiscall FUN_100068b6(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint extraout_EAX;
  uint uVar2;
  void *pvVar3;
  uint extraout_ECX;
  uint uVar4;
  uint _Size;
  
  uVar2 = param_1[4];
  uVar4 = param_2;
  if (uVar2 < param_2) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
    uVar4 = extraout_ECX;
  }
  _Size = uVar2 - uVar4;
  if (param_3 < uVar2 - uVar4) {
    _Size = param_3;
  }
  if ((undefined4 *)this == param_1) {
    FUN_10005c24(this,_Size + uVar4,0xffffffff);
    FUN_10005c24(this,0,param_2);
  }
  else {
    bVar1 = FUN_10006737(this,_Size,'\0');
    if (bVar1) {
      if (0xf < (uint)param_1[5]) {
        param_1 = (undefined4 *)*param_1;
      }
      pvVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      memcpy(pvVar3,(void *)((int)param_1 + param_2),_Size);
      *(uint *)((int)this + 0x10) = _Size;
      pvVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      *(undefined1 *)((int)pvVar3 + _Size) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: assign at 10006950

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1,uint param_2)

{
  bool bVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  
  bVar1 = _Inside(this,param_1);
  if (bVar1) {
    pbVar2 = this;
    if (0xf < *(uint *)(this + 0x14)) {
      pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                this;
    }
    this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
           FUN_100068b6(this,(undefined4 *)this,(int)param_1 - (int)pbVar2,param_2);
  }
  else {
    bVar1 = FUN_10006737(this,param_2,'\0');
    if (bVar1) {
      pbVar2 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  this;
      }
      memcpy(pbVar2,param_1,param_2);
      *(uint *)(this + 0x10) = param_2;
      pbVar2 = this;
      if (0xf < *(uint *)(this + 0x14)) {
        pbVar2 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  this;
      }
      pbVar2[param_2] =
           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    }
  }
  return this;
}



// Function: FUN_100069c5 at 100069c5

undefined2 * __thiscall FUN_100069c5(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_100069f7 at 100069f7

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_100069f7(undefined2 *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  uint uVar5;
  ushort **ppuVar6;
  undefined4 uVar7;
  ulong local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined1 local_254 [28];
  undefined1 local_238 [16];
  uint local_228;
  wchar_t local_21c;
  undefined1 local_21a [530];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 600;
  local_8 = 0x10006a06;
  if ((param_1 == (undefined2 *)0x0) || (param_2 == (undefined4 *)0x0)) goto LAB_10006f2d;
  local_260 = 0;
  local_25c = 0;
  local_258 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_264 = 0x208;
  FUN_100069c5(local_254,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\CS\\Locale\\");
  local_8._0_1_ = 1;
  iVar2 = Open(&local_260,(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_260,L"LanguageExt",&local_21c,&local_264);
    if (lVar3 == 0) {
      FUN_100069c5(local_238,&local_21c);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_228 == 0) {
        sVar4 = wcslen(L"EN");
        FID_conflict_assign(local_238,(undefined4 *)&DAT_1000aa6c,sVar4);
      }
      ppuVar6 = (ushort **)DAT_1000e5cc;
      if (DAT_1000e5e0 < 8) {
        ppuVar6 = &DAT_1000e5cc;
      }
      uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e5dc);
      if (uVar5 == 0) {
LAB_10006ede:
        uVar1 = 0;
        uVar7 = 0x4e4;
      }
      else {
        ppuVar6 = (ushort **)DAT_1000e5e8;
        if (DAT_1000e5fc < 8) {
          ppuVar6 = &DAT_1000e5e8;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e5f8);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e604;
        if (DAT_1000e618 < 8) {
          ppuVar6 = &DAT_1000e604;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e614);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e6ac;
        if (DAT_1000e6c0 < 8) {
          ppuVar6 = &DAT_1000e6ac;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e6bc);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e674;
        if (DAT_1000e688 < 8) {
          ppuVar6 = &DAT_1000e674;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e684);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e690;
        if (DAT_1000e6a4 < 8) {
          ppuVar6 = &DAT_1000e690;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e6a0);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e700;
        if (DAT_1000e714 < 8) {
          ppuVar6 = &DAT_1000e700;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e710);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e71c;
        if (DAT_1000e730 < 8) {
          ppuVar6 = &DAT_1000e71c;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e72c);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e738;
        if (DAT_1000e74c < 8) {
          ppuVar6 = &DAT_1000e738;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e748);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e754;
        if (DAT_1000e768 < 8) {
          ppuVar6 = &DAT_1000e754;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e764);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e770;
        if (DAT_1000e784 < 8) {
          ppuVar6 = &DAT_1000e770;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e780);
        if (uVar5 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e78c;
        if (DAT_1000e7a0 < 8) {
          ppuVar6 = &DAT_1000e78c;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e79c);
        if (uVar5 == 0) goto LAB_10006ede;
        iVar2 = FUN_10005ba4(local_238,DAT_1000e7a8);
        if (iVar2 == 0) goto LAB_10006ede;
        iVar2 = FUN_10005ba4(local_238,DAT_1000e7ac);
        if (iVar2 == 0) goto LAB_10006ede;
        iVar2 = FUN_10005ba4(local_238,DAT_1000e7b0);
        if (iVar2 == 0) goto LAB_10006ede;
        ppuVar6 = (ushort **)DAT_1000e620;
        if (DAT_1000e634 < 8) {
          ppuVar6 = &DAT_1000e620;
        }
        uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e630);
        if (uVar5 == 0) {
          uVar1 = 0xa2;
          uVar7 = 0x4e6;
        }
        else {
          ppuVar6 = (ushort **)DAT_1000e63c;
          if (DAT_1000e650 < 8) {
            ppuVar6 = &DAT_1000e63c;
          }
          uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e64c);
          if (uVar5 == 0) {
            uVar1 = 0x86;
            uVar7 = 0x3a8;
          }
          else {
            ppuVar6 = (ushort **)DAT_1000e658;
            if (DAT_1000e66c < 8) {
              ppuVar6 = &DAT_1000e658;
            }
            uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e668);
            if (uVar5 == 0) {
              uVar1 = 0x80;
              uVar7 = 0x3a4;
            }
            else {
              ppuVar6 = (ushort **)DAT_1000e6c8;
              if (DAT_1000e6dc < 8) {
                ppuVar6 = &DAT_1000e6c8;
              }
              uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e6d8);
              if (uVar5 == 0) {
                uVar1 = 0x81;
                uVar7 = 0x3b5;
              }
              else {
                ppuVar6 = (ushort **)DAT_1000e6e4;
                if (DAT_1000e6f8 < 8) {
                  ppuVar6 = &DAT_1000e6e4;
                }
                uVar5 = FUN_100055f7(local_238,0,local_228,(ushort *)ppuVar6,DAT_1000e6f4);
                if (uVar5 != 0) {
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
                }
                uVar1 = 0xcc;
                uVar7 = 0x4e3;
              }
            }
          }
        }
      }
      *param_1 = uVar1;
      *param_2 = uVar7;
      local_8._0_1_ = 1;
      FID_conflict__Tidy(local_238,'\x01',0);
    }
    ATL::CRegKey::Close((CRegKey *)&local_260);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_254,'\x01',0);
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_260);
LAB_10006f2d:
  FUN_100079dd();
  return;
}



// Function: FUN_10006f33 at 10006f33

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10006f33(undefined2 *param_1,wchar_t *param_2)

{
  if (param_2 == (wchar_t *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    FUN_100069c5(param_1,param_2);
  }
  return param_1;
}



// Function: FUN_10006f85 at 10006f85

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000732d) */

int FUN_10006f85(int param_1)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  int **ppiVar4;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_18 = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    local_18 = -0x7fffbffb;
  }
  else {
    local_2c = (int *)0x0;
    local_30 = (int *)&DAT_000004e4;
    FUN_100069f7((undefined2 *)&local_2c,&local_30);
    local_28 = (int *)0x0;
    local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
    local_8._0_1_ = 4;
    local_18 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1e4))(*(int **)(param_1 + 0xc));
    if ((-1 < local_18) &&
       (local_18 = (*(code *)*puRam00000000)(0,&DAT_1000aa5c,&local_28), -1 < local_18)) {
      (**(code **)(*local_28 + 0x48))(local_28,local_2c);
      local_18 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1e8))(*(int **)(param_1 + 0xc),0);
      piVar1 = (int *)FUN_10005dae(*(void **)(param_1 + 0xc),(ulong *)&local_2c);
      local_8._0_1_ = 5;
      ppiVar4 = &local_30;
      pvVar2 = (void *)FUN_100055e6(piVar1);
      piVar1 = (int *)FUN_10005d60(pvVar2,ppiVar4);
      local_8._0_1_ = 6;
      piVar1 = (int *)FUN_100055e6(piVar1);
      local_18 = (**(code **)(*piVar1 + 0x68))(piVar1,0);
      local_8._0_1_ = 5;
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
      local_8._0_1_ = 4;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      piVar1 = (int *)FUN_10005dae(*(void **)(param_1 + 0xc),(ulong *)&local_2c);
      local_8._0_1_ = 7;
      ppiVar4 = &local_30;
      pvVar2 = (void *)FUN_100055e6(piVar1);
      piVar1 = (int *)FUN_10005d60(pvVar2,ppiVar4);
      local_8._0_1_ = 8;
      piVar1 = (int *)FUN_100055e6(piVar1);
      local_18 = (**(code **)(*piVar1 + 0x68))(piVar1,0);
      local_8._0_1_ = 7;
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
      local_8._0_1_ = 4;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      piVar1 = (int *)FUN_10005dae(*(void **)(param_1 + 0xc),(ulong *)&local_2c);
      local_8._0_1_ = 9;
      ppiVar4 = &local_30;
      pvVar2 = (void *)FUN_100055e6(piVar1);
      piVar1 = (int *)FUN_10005d60(pvVar2,ppiVar4);
      local_8._0_1_ = 10;
      piVar1 = (int *)FUN_100055e6(piVar1);
      local_18 = (**(code **)(*piVar1 + 200))(piVar1,0);
      local_8._0_1_ = 9;
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
      local_8._0_1_ = 4;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      piVar1 = (int *)FUN_10005dae(*(void **)(param_1 + 0xc),(ulong *)&local_2c);
      local_8._0_1_ = 0xb;
      ppiVar4 = &local_30;
      pvVar2 = (void *)FUN_100055e6(piVar1);
      piVar1 = (int *)FUN_10005d60(pvVar2,ppiVar4);
      local_8._0_1_ = 0xc;
      piVar1 = (int *)FUN_100055e6(piVar1);
      local_18 = (**(code **)(*piVar1 + 200))(piVar1,0);
      local_8._0_1_ = 0xb;
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
      local_8._0_1_ = 4;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
    }
    (**(code **)(**(int **)(param_1 + 0xc) + 0xfc))(*(int **)(param_1 + 0xc),3);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x34))(*(int **)(param_1 + 0xc),0x14);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x104))(*(int **)(param_1 + 0xc),0);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x2a4))(*(int **)(param_1 + 0xc),0);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x2b4))(*(int **)(param_1 + 0xc),0);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x2ac))(*(int **)(param_1 + 0xc),0);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x2c4))(*(int **)(param_1 + 0xc),0);
    (**(code **)(**(int **)(param_1 + 0xc) + 700))(*(int **)(param_1 + 0xc),0);
    FUN_100054dc(*(IUnknown **)(param_1 + 0xc));
    (**(code **)(**(int **)(param_1 + 0xc) + 0x6c))(*(int **)(param_1 + 0xc),0x28);
    local_24 = (int *)0x0;
    local_20 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,0x10);
    local_18 = (**(code **)(**(int **)(param_1 + 0xc) + 0x23c))(*(int **)(param_1 + 0xc),&local_24);
    if ((((-1 < local_18) && (local_18 = (**(code **)(*local_24 + 0x20))(local_24,0), -1 < local_18)
         ) && (local_18 = (**(code **)(*local_20 + 0xb0))(local_20), -1 < local_18)) &&
       (local_18 = FUN_1000546f(*(void **)(param_1 + 0xc),(IID *)0x1,(void **)0x1), -1 < local_18))
    {
      for (local_1c = 0; local_1c < *(uint *)(param_1 + 8); local_1c = local_1c + 1) {
        (**(code **)(**(int **)(param_1 + 0xc) + 0x2ec))(*(int **)(param_1 + 0xc),0,local_1c,0);
      }
      uVar3 = FUN_100054a8(*(IUnknown **)(param_1 + 0xc));
      local_18 = (int)(short)uVar3;
      if (-1 < local_18) {
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 0xe;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))();
        }
        local_8._0_1_ = 4;
        if (local_24 != (int *)0x0) {
          (**(code **)(*local_24 + 8))();
        }
        local_8._0_1_ = 2;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))();
        }
        return local_18;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@10007343 at 10007343

undefined4 Catch_10007343(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10007338;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 1000734d

/* Library Function - Single Match
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(char const *)
   
   Library: Visual Studio 2010 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0xf;
  *this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  sVar1 = strlen(param_1);
  assign(this,param_1,sVar1);
  return this;
}



// Function: FUN_1000737c at 1000737c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl
FUN_1000737c(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            wchar_t *param_2)

{
  char *pcVar1;
  undefined4 local_a4;
  uint local_a0;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_9c;
  char *local_98;
  char local_94 [140];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_8 = 0x1000738b;
  local_a4 = 0;
  local_9c = param_1;
  local_a0 = 0x4e4;
  FUN_100069f7((undefined2 *)&local_a4,&local_a0);
  if (7 < *(uint *)(param_2 + 10)) {
    param_2 = *(wchar_t **)param_2;
  }
  local_98 = local_94;
  ATL::CW2AEX<128>::Init((CW2AEX<128> *)&local_98,param_2,local_a0);
  pcVar1 = local_98;
  local_8 = 0;
  if (local_98 != local_94) {
    free(local_98);
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_9c,pcVar1);
  local_8 = 0;
  FUN_100079dd();
  return;
}



// Function: FUN_10007437 at 10007437

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl
FUN_10007437(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            wchar_t *param_2)

{
  wchar_t *pwVar1;
  undefined2 local_30 [20];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10007443;
  pwVar1 = FUN_10006f33(local_30,param_2);
  local_8 = 1;
  FUN_1000737c(param_1,pwVar1);
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100079dd();
  return;
}



// Function: FUN_10007484 at 10007484

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10007484(int param_1,undefined4 param_2,wchar_t *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 local_44;
  int *local_40;
  int *local_3c;
  int local_38;
  char **local_34 [5];
  uint local_20;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_38 = 0;
  local_3c = (int *)0x0;
  local_40 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 4;
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 == (int *)0x0) {
    local_38 = -0x7fffbffd;
  }
  else {
    local_38 = (**(code **)(*piVar1 + 0x240))(piVar1,&local_3c);
    if (-1 < local_38) {
      local_38 = (**(code **)(*local_3c + 0x20))(local_3c,2,&local_40);
      if (-1 < local_38) {
        FUN_10007437((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_34,param_3);
        piVar1 = local_40;
        local_8._0_1_ = 5;
        if (local_20 < 0x10) {
          local_34[0] = (char **)local_34;
        }
        puVar2 = (undefined4 *)ATL::CComBSTR::CComBSTR((CComBSTR *)&local_44,(char *)local_34[0]);
        local_8._0_1_ = 6;
        local_38 = (**(code **)(*piVar1 + 0xd0))(piVar1,param_2,*puVar2);
        local_8._0_1_ = 5;
        Ordinal_6(local_44);
        if (-1 < local_38) {
          local_8._0_1_ = 4;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_34,true,0);
          local_8._0_1_ = 2;
          if (local_40 != (int *)0x0) {
            (**(code **)(*local_40 + 8))(local_40);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          if (local_3c != (int *)0x0) {
            (**(code **)(*local_3c + 8))(local_3c);
          }
          local_8 = 0xffffffff;
          FUN_100079ec();
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@1000758e at 1000758e

undefined4 Catch_1000758e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10007583;
}



// Function: FUN_10007598 at 10007598

void __fastcall FUN_10007598(int *param_1)

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



// Function: FUN_100075dc at 100075dc

int __fastcall FUN_100075dc(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_100075f5 at 100075f5

undefined4 * __fastcall FUN_100075f5(undefined4 *param_1)

{
  long lVar1;
  
  FUN_100075dc((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1000cba8;
  param_1[3] = &DAT_1000cba8;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_1000e548 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10007636 at 10007636

void __fastcall FUN_10007636(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10007655 at 10007655

int __fastcall FUN_10007655(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1000767a at 1000767a

void __fastcall FUN_1000767a(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_10007636((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10007692 at 10007692

undefined4 * __fastcall FUN_10007692(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10007655((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1000acac;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_1000e548 = 1;
  }
  return param_1;
}



// Function: FUN_100076d2 at 100076d2

void FUN_100076d2(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_100076e0 at 100076e0

void FUN_100076e0(undefined4 param_1)

{
  (*(code *)PTR_FUN_1000e4f4)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 10007700

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
    HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1000a6e8,&param_2);
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
  (*(code *)PTR_FUN_1000e4f4)(param_1);
  return;
}



// Function: FUN_100077b0 at 100077b0

void FUN_100077b0(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__1000acbc;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1000caa8);
}



// Function: _com_error at 100077f0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1000acbc;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 10007830

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1000acbc;
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



// Function: FID_conflict:`vector_deleting_destructor' at 1000788a

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



// Function: __security_check_cookie at 100078e2

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1000e52c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 100078f1

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000e52c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 10007924

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000e52c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1000795a

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000e52c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 10007990

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000e52c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 100079c9

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



// Function: FUN_100079dd at 100079dd

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100079dd(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_100079ec at 100079ec

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100079ec(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __alloca_probe at 10007a00

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



// Function: `eh_vector_constructor_iterator' at 10007a32

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
  FUN_10007a7f();
  return;
}



// Function: FUN_10007a7f at 10007a7f

void FUN_10007a7f(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 10007a97

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



// Function: `eh_vector_destructor_iterator' at 10007af5

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
  FUN_10007b40();
  return;
}



// Function: FUN_10007b40 at 10007b40

void FUN_10007b40(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 10007b64

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
  
  local_8 = &DAT_1000cb40;
  uStack_c = 0x10007b70;
  local_20[0] = DecodePointer(DAT_1000ebc4);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1000ebc4);
    local_24 = DecodePointer(DAT_1000ebc0);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1000ebc4 = EncodePointer(local_20[0]);
    DAT_1000ebc0 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10007bfc();
  }
  return p_Var1;
}



// Function: FUN_10007bfc at 10007bfc

void FUN_10007bfc(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10007c05

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: FUN_10007ca7 at 10007ca7

void __cdecl
FUN_10007ca7(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1000e52c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 10007cd0

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



// Function: __alloca_probe_8 at 10007ce6

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



// Function: __CRT_INIT@12 at 10007d4a

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
    if (DAT_1000e884 < 1) {
      return 0;
    }
    DAT_1000e884 = DAT_1000e884 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1000ebb8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1000ebb4 == 2) {
      param_2 = (int *)DecodePointer(DAT_1000ebc4);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1000ebc0);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1000ebc4);
            piVar8 = (int *)DecodePointer(DAT_1000ebc0);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1000ebc0 = (PVOID)encoded_null();
        DAT_1000ebc4 = DAT_1000ebc0;
      }
      DAT_1000ebb4 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1000ebb8,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1000ebb8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1000ebb4 == 0) {
      DAT_1000ebb4 = 1;
      iVar5 = initterm_e(&DAT_1000a230,&DAT_1000a238);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1000a1bc,&DAT_1000a22c);
      DAT_1000ebb4 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1000ebb8,0);
    }
    if ((DAT_1000ebbc != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1000ebbc), BVar2 != 0)) {
      (*DAT_1000ebbc)(param_1,2,param_3);
    }
    DAT_1000e884 = DAT_1000e884 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10007f54

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10007ff4) */
/* WARNING: Removing unreachable block (ram,0x10007fa1) */
/* WARNING: Removing unreachable block (ram,0x10008021) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1000e540 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1000e884 == 0)) {
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
  FUN_1000805f();
  return local_20;
}



// Function: FUN_1000805f at 1000805f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000805f(void)

{
  _DAT_1000e540 = 0xffffffff;
  return;
}



// Function: entry at 1000806a

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1000808d

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
  
  _DAT_1000e9a0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1000e9a4 = &stack0x00000004;
  _DAT_1000e8e0 = 0x10001;
  _DAT_1000e888 = 0xc0000409;
  _DAT_1000e88c = 1;
  local_32c = DAT_1000e52c;
  local_328 = DAT_1000e530;
  _DAT_1000e894 = unaff_retaddr;
  _DAT_1000e96c = in_GS;
  _DAT_1000e970 = in_FS;
  _DAT_1000e974 = in_ES;
  _DAT_1000e978 = in_DS;
  _DAT_1000e97c = unaff_EDI;
  _DAT_1000e980 = unaff_ESI;
  _DAT_1000e984 = unaff_EBX;
  _DAT_1000e988 = in_EDX;
  _DAT_1000e98c = in_ECX;
  _DAT_1000e990 = in_EAX;
  _DAT_1000e994 = unaff_EBP;
  DAT_1000e998 = unaff_retaddr;
  _DAT_1000e99c = in_CS;
  _DAT_1000e9a8 = in_SS;
  DAT_1000e8d8 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1000accc);
  if (DAT_1000e8d8 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 100081a0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1000e52c ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 100081e5

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



// Function: __ValidateImageBase at 10008270

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



// Function: __FindPESection at 100082b0

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



// Function: __IsNonwritableInCurrentImage at 10008300

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
  
  pcStack_10 = FUN_10007ca7;
  local_14 = ExceptionList;
  local_c = DAT_1000e52c ^ 0x1000cb88;
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



// Function: ___security_init_cookie at 100083d4

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
  if ((DAT_1000e52c == 0xbb40e64e) || ((DAT_1000e52c & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1000e52c = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1000e52c == 0xbb40e64e) {
      DAT_1000e52c = 0xbb40e64f;
    }
    else if ((DAT_1000e52c & 0xffff0000) == 0) {
      DAT_1000e52c = DAT_1000e52c | (DAT_1000e52c | 0x4711) << 0x10;
    }
    DAT_1000e530 = ~DAT_1000e52c;
  }
  else {
    DAT_1000e530 = ~DAT_1000e52c;
  }
  return;
}



// Function: Unwind@10008482 at 10008482

void Unwind_10008482(void)

{
  DAT_1000e598 = DAT_1000e598 & 0xfffffffe;
  return;
}



// Function: Unwind@100084ab at 100084ab

void Unwind_100084ab(void)

{
  int unaff_EBP;
  
  FUN_100011ac(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100084ce at 100084ce

void Unwind_100084ce(void)

{
  int unaff_EBP;
  
  FUN_1000590c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100084f1 at 100084f1

void Unwind_100084f1(void)

{
  int unaff_EBP;
  
  FUN_10001f65(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008514 at 10008514

void Unwind_10008514(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10008547 at 10008547

void Unwind_10008547(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1000857a at 1000857a

void Unwind_1000857a(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10008584 at 10008584

void Unwind_10008584(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100085a7 at 100085a7

void Unwind_100085a7(void)

{
  int unaff_EBP;
  
  FUN_100011e9(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100085e5 at 100085e5

void Unwind_100085e5(void)

{
  int unaff_EBP;
  
  FUN_10001ce3(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1000860b at 1000860b

void Unwind_1000860b(void)

{
  int unaff_EBP;
  
  FUN_10001ce3(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10008616 at 10008616

void Unwind_10008616(void)

{
  int unaff_EBP;
  
  FUN_1000590c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008639 at 10008639

void Unwind_10008639(void)

{
  int unaff_EBP;
  
  FUN_10001e35((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000865f at 1000865f

void Unwind_1000865f(void)

{
  FUN_10001eea();
  return;
}



// Function: Unwind@10008676 at 10008676

void Unwind_10008676(void)

{
  FUN_10001eea();
  return;
}



// Function: Unwind@100086a9 at 100086a9

void Unwind_100086a9(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100086b1 at 100086b1

void Unwind_100086b1(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100086b9 at 100086b9

void Unwind_100086b9(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100086c1 at 100086c1

void Unwind_100086c1(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100086c9 at 100086c9

void Unwind_100086c9(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100086d1 at 100086d1

void Unwind_100086d1(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100086f4 at 100086f4

void Unwind_100086f4(void)

{
  int unaff_EBP;
  
  FUN_10001f65(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100086fc at 100086fc

void Unwind_100086fc(void)

{
  int unaff_EBP;
  
  FUN_10001f6a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000871f at 1000871f

void Unwind_1000871f(void)

{
  int unaff_EBP;
  
  FUN_10001f6a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008727 at 10008727

void Unwind_10008727(void)

{
  int unaff_EBP;
  
  FUN_10001f65(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000874a at 1000874a

void Unwind_1000874a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10001dc9(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000876d at 1000876d

void Unwind_1000876d(void)

{
  int unaff_EBP;
  
  FUN_1000298f((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10008793 at 10008793

void Unwind_10008793(void)

{
  int unaff_EBP;
  
  FUN_10001575(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@100087c0 at 100087c0

void Unwind_100087c0(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100087cb at 100087cb

void Unwind_100087cb(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100087d6 at 100087d6

void Unwind_100087d6(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100087e1 at 100087e1

void Unwind_100087e1(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100087ec at 100087ec

void Unwind_100087ec(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100087f7 at 100087f7

void Unwind_100087f7(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@10008802 at 10008802

void Unwind_10008802(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1000880d at 1000880d

void Unwind_1000880d(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@10008818 at 10008818

void Unwind_10008818(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10008823 at 10008823

void Unwind_10008823(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10008856 at 10008856

void Unwind_10008856(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000885e at 1000885e

void Unwind_1000885e(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008866 at 10008866

void Unwind_10008866(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000886e at 1000886e

void Unwind_1000886e(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008876 at 10008876

void Unwind_10008876(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008899 at 10008899

void Unwind_10008899(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@100088a4 at 100088a4

void Unwind_100088a4(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100088af at 100088af

void Unwind_100088af(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100088ba at 100088ba

void Unwind_100088ba(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100088c5 at 100088c5

void Unwind_100088c5(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100088d0 at 100088d0

void Unwind_100088d0(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008903 at 10008903

void Unwind_10008903(void)

{
  int unaff_EBP;
  
  FUN_100027fd((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10008926 at 10008926

void Unwind_10008926(void)

{
  int unaff_EBP;
  
  FUN_100027fd((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10008949 at 10008949

void Unwind_10008949(void)

{
  int unaff_EBP;
  
  FUN_1000277e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10008954 at 10008954

void Unwind_10008954(void)

{
  int unaff_EBP;
  
  FUN_10001e35((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000897a at 1000897a

void Unwind_1000897a(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000899f at 1000899f

void Unwind_1000899f(void)

{
  int unaff_EBP;
  
  FUN_10001e35((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100089aa at 100089aa

void Unwind_100089aa(void)

{
  int unaff_EBP;
  
  FUN_1000277e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100089d0 at 100089d0

void Unwind_100089d0(void)

{
  int unaff_EBP;
  
  FUN_10002761((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100089d8 at 100089d8

void Unwind_100089d8(void)

{
  int unaff_EBP;
  
  FUN_10002761((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100089fb at 100089fb

void Unwind_100089fb(void)

{
  int unaff_EBP;
  
  FUN_10002771((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10008a06 at 10008a06

void Unwind_10008a06(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10008a11 at 10008a11

void Unwind_10008a11(void)

{
  int unaff_EBP;
  
  FUN_10002771((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10008a44 at 10008a44

void Unwind_10008a44(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@10008a4f at 10008a4f

void Unwind_10008a4f(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@10008a5a at 10008a5a

void Unwind_10008a5a(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@10008a65 at 10008a65

void Unwind_10008a65(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@10008a70 at 10008a70

void Unwind_10008a70(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@10008aa3 at 10008aa3

void Unwind_10008aa3(void)

{
  int unaff_EBP;
  
  FUN_100027fd((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10008ac6 at 10008ac6

void Unwind_10008ac6(void)

{
  int unaff_EBP;
  
  FUN_100027fd((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@10008ad1 at 10008ad1

void Unwind_10008ad1(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10008adc at 10008adc

void Unwind_10008adc(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008ae7 at 10008ae7

void Unwind_10008ae7(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008af2 at 10008af2

void Unwind_10008af2(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008afd at 10008afd

void Unwind_10008afd(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008b08 at 10008b08

void Unwind_10008b08(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10008b13 at 10008b13

void Unwind_10008b13(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10008b1e at 10008b1e

void Unwind_10008b1e(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10008b29 at 10008b29

void Unwind_10008b29(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008b34 at 10008b34

void Unwind_10008b34(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008b67 at 10008b67

void Unwind_10008b67(void)

{
  int unaff_EBP;
  
  FUN_10003521(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008b8a at 10008b8a

void Unwind_10008b8a(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10008baf at 10008baf

void Unwind_10008baf(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@10008bba at 10008bba

void Unwind_10008bba(void)

{
  int unaff_EBP;
  
  FUN_10002771((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10008bed at 10008bed

void Unwind_10008bed(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008c10 at 10008c10

void Unwind_10008c10(void)

{
  int unaff_EBP;
  
  thunk_FUN_10001dc9(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10008c1b at 10008c1b

void Unwind_10008c1b(void)

{
  int unaff_EBP;
  
  FUN_1000298f((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10008c26 at 10008c26

void Unwind_10008c26(void)

{
  int unaff_EBP;
  
  FUN_100029b9((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@10008c31 at 10008c31

void Unwind_10008c31(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10008c64 at 10008c64

void Unwind_10008c64(void)

{
  int unaff_EBP;
  
  thunk_FUN_10001dc9(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10008c6f at 10008c6f

void Unwind_10008c6f(void)

{
  int unaff_EBP;
  
  FUN_1000298f((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@10008c7a at 10008c7a

void Unwind_10008c7a(void)

{
  int unaff_EBP;
  
  FUN_100029b9((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10008c85 at 10008c85

void Unwind_10008c85(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10008cb8 at 10008cb8

void Unwind_10008cb8(void)

{
  FUN_10001f6a(0x1000e59c);
  return;
}



// Function: Unwind@10008cc2 at 10008cc2

void Unwind_10008cc2(void)

{
  FUN_10001f65(0x1000e59c);
  return;
}



// Function: Unwind@10008d02 at 10008d02

void Unwind_10008d02(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10008d05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10008d26 at 10008d26

void Unwind_10008d26(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10008d29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008d4a at 10008d4a

void Unwind_10008d4a(void)

{
  int unaff_EBP;
  
  FUN_10001daf((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008d6d at 10008d6d

void Unwind_10008d6d(void)

{
  int unaff_EBP;
  
  FUN_10001df6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008d90 at 10008d90

void Unwind_10008d90(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10008d9b at 10008d9b

void Unwind_10008d9b(void)

{
  int unaff_EBP;
  
  FUN_10001df6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10008dd9 at 10008dd9

void Unwind_10008dd9(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10008e27 at 10008e27

void Unwind_10008e27(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10008e4a at 10008e4a

void Unwind_10008e4a(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001df6(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10008e7e at 10008e7e

void Unwind_10008e7e(void)

{
  int unaff_EBP;
  
  FUN_10001df6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10008e86 at 10008e86

void Unwind_10008e86(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10008eac at 10008eac

void Unwind_10008eac(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008eb7 at 10008eb7

void Unwind_10008eb7(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008ec2 at 10008ec2

void Unwind_10008ec2(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008ecd at 10008ecd

void Unwind_10008ecd(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008ed8 at 10008ed8

void Unwind_10008ed8(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@10008ee3 at 10008ee3

void Unwind_10008ee3(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008eee at 10008eee

void Unwind_10008eee(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008f21 at 10008f21

void Unwind_10008f21(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008f2c at 10008f2c

void Unwind_10008f2c(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008f37 at 10008f37

void Unwind_10008f37(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008f42 at 10008f42

void Unwind_10008f42(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008f4d at 10008f4d

void Unwind_10008f4d(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@10008f58 at 10008f58

void Unwind_10008f58(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10008f63 at 10008f63

void Unwind_10008f63(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10008f96 at 10008f96

void Unwind_10008f96(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10008f9e at 10008f9e

void Unwind_10008f9e(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10008fa6 at 10008fa6

void Unwind_10008fa6(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10008fae at 10008fae

void Unwind_10008fae(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10008fb6 at 10008fb6

void Unwind_10008fb6(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10008fbe at 10008fbe

void Unwind_10008fbe(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10008fe1 at 10008fe1

void Unwind_10008fe1(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10008fe9 at 10008fe9

void Unwind_10008fe9(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10008ff1 at 10008ff1

void Unwind_10008ff1(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10008ff9 at 10008ff9

void Unwind_10008ff9(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10009001 at 10009001

void Unwind_10009001(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10009009 at 10009009

void Unwind_10009009(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000902c at 1000902c

void Unwind_1000902c(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10009034 at 10009034

void Unwind_10009034(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000903c at 1000903c

void Unwind_1000903c(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10009044 at 10009044

void Unwind_10009044(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000904c at 1000904c

void Unwind_1000904c(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10009054 at 10009054

void Unwind_10009054(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100090ad at 100090ad

void Unwind_100090ad(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x25c));
  return;
}



// Function: Unwind@100090b8 at 100090b8

void Unwind_100090b8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@100090c3 at 100090c3

void Unwind_100090c3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@100090f6 at 100090f6

void Unwind_100090f6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000912a at 1000912a

void Unwind_1000912a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10009132 at 10009132

void Unwind_10009132(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000913a at 1000913a

void Unwind_1000913a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10009142 at 10009142

void Unwind_10009142(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000914a at 1000914a

void Unwind_1000914a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10009152 at 10009152

void Unwind_10009152(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000915a at 1000915a

void Unwind_1000915a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10009162 at 10009162

void Unwind_10009162(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000916a at 1000916a

void Unwind_1000916a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10009172 at 10009172

void Unwind_10009172(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000917a at 1000917a

void Unwind_1000917a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10009182 at 10009182

void Unwind_10009182(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000918a at 1000918a

void Unwind_1000918a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10009192 at 10009192

void Unwind_10009192(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000919a at 1000919a

void Unwind_1000919a(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100091a2 at 100091a2

void Unwind_100091a2(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100091aa at 100091aa

void Unwind_100091aa(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100091b2 at 100091b2

void Unwind_100091b2(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100091ba at 100091ba

void Unwind_100091ba(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100091c2 at 100091c2

void Unwind_100091c2(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100091e5 at 100091e5

void Unwind_100091e5(void)

{
  int unaff_EBP;
  
  FUN_10005c12((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@100091f0 at 100091f0

void Unwind_100091f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xa4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xa4) = *(uint *)(unaff_EBP + -0xa4) & 0xfffffffe;
    FUN_100066c3(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + -0x98));
    return;
  }
  return;
}



// Function: Unwind@1000923a at 1000923a

void Unwind_1000923a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009242 at 10009242

void Unwind_10009242(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_100066c3(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@10009280 at 10009280

void Unwind_10009280(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10009288 at 10009288

void Unwind_10009288(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10009290 at 10009290

void Unwind_10009290(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10009298 at 10009298

void Unwind_10009298(void)

{
  int unaff_EBP;
  
  FUN_100058e7((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100092a0 at 100092a0

void Unwind_100092a0(void)

{
  int unaff_EBP;
  
  FUN_100066c3((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100092a8 at 100092a8

void Unwind_100092a8(void)

{
  int unaff_EBP;
  
  FUN_100011e9((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100092b0 at 100092b0

void Unwind_100092b0(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100092b8 at 100092b8

void Unwind_100092b8(void)

{
  int unaff_EBP;
  
  FUN_10001df6((int *)(unaff_EBP + -0x38));
  return;
}



// Function: FUN_100095dc at 100095dc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100095dc(void)

{
  _DAT_1000e59c = ATL::CComModule::vftable;
  FUN_10001f2c(0x1000e59c);
  return;
}



// Function: FUN_10009606 at 10009606

void FUN_10009606(void)

{
  Ordinal_6(DAT_1000e7a8);
  return;
}



// Function: FUN_10009613 at 10009613

void FUN_10009613(void)

{
  Ordinal_6(DAT_1000e7ac);
  return;
}



// Function: FUN_10009620 at 10009620

void FUN_10009620(void)

{
  Ordinal_6(DAT_1000e7b0);
  return;
}



// Function: FUN_1000962d at 1000962d

void FUN_1000962d(void)

{
  FID_conflict__Tidy(&DAT_1000e5cc,'\x01',0);
  return;
}



// Function: FUN_1000963c at 1000963c

void FUN_1000963c(void)

{
  FID_conflict__Tidy(&DAT_1000e5e8,'\x01',0);
  return;
}



// Function: FUN_1000964b at 1000964b

void FUN_1000964b(void)

{
  FID_conflict__Tidy(&DAT_1000e604,'\x01',0);
  return;
}



// Function: FUN_1000965a at 1000965a

void FUN_1000965a(void)

{
  FID_conflict__Tidy(&DAT_1000e620,'\x01',0);
  return;
}



// Function: FUN_10009669 at 10009669

void FUN_10009669(void)

{
  FID_conflict__Tidy(&DAT_1000e63c,'\x01',0);
  return;
}



// Function: FUN_10009678 at 10009678

void FUN_10009678(void)

{
  FID_conflict__Tidy(&DAT_1000e658,'\x01',0);
  return;
}



// Function: FUN_10009687 at 10009687

void FUN_10009687(void)

{
  FID_conflict__Tidy(&DAT_1000e674,'\x01',0);
  return;
}



// Function: FUN_10009696 at 10009696

void FUN_10009696(void)

{
  FID_conflict__Tidy(&DAT_1000e690,'\x01',0);
  return;
}



// Function: FUN_100096a5 at 100096a5

void FUN_100096a5(void)

{
  FID_conflict__Tidy(&DAT_1000e6ac,'\x01',0);
  return;
}



// Function: FUN_100096b4 at 100096b4

void FUN_100096b4(void)

{
  FID_conflict__Tidy(&DAT_1000e6c8,'\x01',0);
  return;
}



// Function: FUN_100096c3 at 100096c3

void FUN_100096c3(void)

{
  FID_conflict__Tidy(&DAT_1000e6e4,'\x01',0);
  return;
}



// Function: FUN_100096d2 at 100096d2

void FUN_100096d2(void)

{
  FID_conflict__Tidy(&DAT_1000e700,'\x01',0);
  return;
}



// Function: FUN_100096e1 at 100096e1

void FUN_100096e1(void)

{
  FID_conflict__Tidy(&DAT_1000e71c,'\x01',0);
  return;
}



// Function: FUN_100096f0 at 100096f0

void FUN_100096f0(void)

{
  FID_conflict__Tidy(&DAT_1000e738,'\x01',0);
  return;
}



// Function: FUN_100096ff at 100096ff

void FUN_100096ff(void)

{
  FID_conflict__Tidy(&DAT_1000e754,'\x01',0);
  return;
}



// Function: FUN_1000970e at 1000970e

void FUN_1000970e(void)

{
  FID_conflict__Tidy(&DAT_1000e770,'\x01',0);
  return;
}



// Function: FUN_1000971d at 1000971d

void FUN_1000971d(void)

{
  FID_conflict__Tidy(&DAT_1000e78c,'\x01',0);
  return;
}



// Function: FUN_1000972c at 1000972c

void FUN_1000972c(void)

{
  FID_conflict__Tidy(&DAT_1000e7ec,'\x01',0);
  return;
}



// Function: FUN_1000973b at 1000973b

void FUN_1000973b(void)

{
  FID_conflict__Tidy(&DAT_1000e7d0,'\x01',0);
  return;
}



// Function: FUN_1000974a at 1000974a

void FUN_1000974a(void)

{
  FID_conflict__Tidy(&DAT_1000e7b4,'\x01',0);
  return;
}



// Function: FUN_10009759 at 10009759

void FUN_10009759(void)

{
  FID_conflict__Tidy(&DAT_1000e808,'\x01',0);
  return;
}



// Function: FUN_10009768 at 10009768

void FUN_10009768(void)

{
  FUN_10007598((int *)&DAT_1000e824);
  return;
}



// Function: FUN_10009772 at 10009772

void FUN_10009772(void)

{
  FUN_1000767a(0x1000e84c);
  return;
}



