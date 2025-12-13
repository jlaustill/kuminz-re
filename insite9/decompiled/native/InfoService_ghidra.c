/*
 * Decompiled from: InfoService.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(int *param_1)

{
  undefined4 *puVar1;
  
  if (*param_1 == 0) {
    puVar1 = (undefined4 *)operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 1;
    }
    *param_1 = (int)puVar1;
  }
  *(int *)*param_1 = *(int *)*param_1 + 1;
  return;
}



// Function: FUN_10001029 at 10001029

undefined4 __fastcall FUN_10001029(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) {
      return *(undefined4 *)*param_1;
    }
    operator_delete((void *)*param_1);
    *param_1 = 0;
  }
  return 0;
}



// Function: FUN_1000104b at 1000104b

void __fastcall FUN_1000104b(int *param_1)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_10001029(param_1 + 1);
    if (iVar1 == 0) {
      RegCloseKey((HKEY)*param_1);
    }
  }
  *param_1 = 0;
  return;
}



// Function: FUN_1000106c at 1000106c

int * __thiscall FUN_1000106c(void *this,int *param_1)

{
  *(int *)this = *param_1;
  *(undefined4 *)((int)this + 4) = 0;
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
    FUN_10001000(param_1 + 1);
  }
  *(int *)((int)this + 4) = param_1[1];
  return (int *)this;
}



// Function: FUN_10001099 at 10001099

void __fastcall FUN_10001099(int *param_1)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_10001029(param_1 + 1);
    if (iVar1 == 0) {
      RegCloseKey((HKEY)*param_1);
    }
  }
  *param_1 = 0;
  return;
}



// Function: FUN_1000109e at 1000109e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000109e(int *param_1)

{
  FUN_1000104b(param_1);
  return;
}



// Function: FUN_100010e1 at 100010e1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_100010e1(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10001119 at 10001119

short * __cdecl FUN_10001119(short *param_1,short param_2,int param_3)

{
  if (param_3 != 0) {
    do {
      if (*param_1 == param_2) {
        return param_1;
      }
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return (short *)0x0;
}



// Function: FUN_1000113a at 1000113a

int __cdecl FUN_1000113a(ushort *param_1,ushort *param_2,int param_3)

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



// Function: FUN_1000116e at 1000116e

void __thiscall FUN_1000116e(void *this,int param_1)

{
  *(int *)((int)this + 8) = *(int *)((int)this + 4) - param_1;
  return;
}



// Function: FUN_1000117e at 1000117e

undefined4 __fastcall FUN_1000117e(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10001182 at 10001182

void __thiscall FUN_10001182(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_1001fc0c,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: AfxCrtErrorCheck at 100011cf

/* Library Function - Single Match
    int __cdecl AfxCrtErrorCheck(int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

int __cdecl AfxCrtErrorCheck(int param_1)

{
  int extraout_EAX;
  int extraout_EAX_00;
  
  if (param_1 != 0) {
    if (param_1 == 0xc) {
      AfxThrowMemoryException();
      return extraout_EAX_00;
    }
    if (((param_1 == 0x16) || (param_1 == 0x22)) || (param_1 != 0x50)) {
      AfxThrowInvalidArgException();
      return extraout_EAX;
    }
  }
  return param_1;
}



// Function: AtlMultiply<unsigned_long> at 100011f9

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



// Function: FUN_1000121b at 1000121b

void FUN_1000121b(int param_1)

{
  code *pcVar1;
  
  if (param_1 == -0x7ff8fff2) {
    AfxThrowMemoryException();
  }
  AfxThrowOleException(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_10001235 at 10001235

void __cdecl FUN_10001235(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  AfxCrtErrorCheck(eVar1);
  return;
}



// Function: _AtlGetStringResourceImage at 10001255

/* Library Function - Single Match
    struct ATL::ATLSTRINGRESOURCEIMAGE const * __cdecl ATL::_AtlGetStringResourceImage(struct
   HINSTANCE__ *,struct HRSRC__ *,unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ATLSTRINGRESOURCEIMAGE * __cdecl
ATL::_AtlGetStringResourceImage(HINSTANCE__ *param_1,HRSRC__ *param_2,uint param_3)

{
  HGLOBAL hResData;
  ushort *puVar1;
  DWORD DVar2;
  ushort *puVar3;
  uint uVar4;
  
  hResData = LoadResource(param_1,param_2);
  if (hResData == (HGLOBAL)0x0) {
    return (ATLSTRINGRESOURCEIMAGE *)0x0;
  }
  puVar1 = (ushort *)LockResource(hResData);
  if (puVar1 != (ushort *)0x0) {
    DVar2 = SizeofResource(param_1,param_2);
    puVar3 = (ushort *)(DVar2 + (int)puVar1);
    for (uVar4 = param_3 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (puVar3 <= puVar1) {
        return (ATLSTRINGRESOURCEIMAGE *)0x0;
      }
      puVar1 = puVar1 + *puVar1 + 1;
    }
    if (puVar1 < puVar3) {
      return (ATLSTRINGRESOURCEIMAGE *)(-(uint)(*puVar1 != 0) & (uint)puVar1);
    }
  }
  return (ATLSTRINGRESOURCEIMAGE *)0x0;
}



// Function: AtlGetStringResourceImage at 100012b0

/* Library Function - Single Match
    struct ATL::ATLSTRINGRESOURCEIMAGE const * __cdecl ATL::AtlGetStringResourceImage(struct
   HINSTANCE__ *,unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

ATLSTRINGRESOURCEIMAGE * __cdecl ATL::AtlGetStringResourceImage(HINSTANCE__ *param_1,uint param_2)

{
  HRSRC pHVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  
  pHVar1 = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if (pHVar1 == (HRSRC)0x0) {
    return (ATLSTRINGRESOURCEIMAGE *)0x0;
  }
  pAVar2 = _AtlGetStringResourceImage(param_1,pHVar1,param_2);
  return pAVar2;
}



// Function: FUN_100012e0 at 100012e0

ATLSTRINGRESOURCEIMAGE * __cdecl FUN_100012e0(uint param_1)

{
  HINSTANCE__ *pHVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  int iVar3;
  
  pAVar2 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10030d6c,0);
  iVar3 = 1;
  while ((pHVar1 != (HINSTANCE__ *)0x0 && (pAVar2 == (ATLSTRINGRESOURCEIMAGE *)0x0))) {
    pAVar2 = ATL::AtlGetStringResourceImage(pHVar1,param_1);
    pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10030d6c,iVar3);
    iVar3 = iVar3 + 1;
  }
  return pAVar2;
}



// Function: FUN_1000131f at 1000131f

int * FUN_1000131f(int *param_1,int *param_2)

{
  int *piVar1;
  
  if (param_1 == (int *)0x0) {
    param_2 = (int *)0x0;
  }
  else {
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *param_1 = (int)param_2;
  }
  return param_2;
}



// Function: FUN_10001352 at 10001352

int * __thiscall FUN_10001352(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_10001378 at 10001378

int __thiscall FUN_10001378(void *this,undefined4 param_1)

{
  int iVar1;
  void *local_8;
  
  local_8 = this;
  iVar1 = Ordinal_7(param_1);
  if (iVar1 != 0) {
    local_8 = (void *)0x0;
                    /* WARNING: Load size is inaccurate */
    iVar1 = Ordinal_313(*this,param_1,&local_8);
    if (-1 < iVar1) {
                    /* WARNING: Load size is inaccurate */
      Ordinal_6(*this);
      *(void **)this = local_8;
    }
  }
  return iVar1;
}



// Function: FUN_100013ba at 100013ba

bool __cdecl FUN_100013ba(uint param_1,int *param_2)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  int iVar2;
  
  pAVar1 = FUN_100012e0(param_1);
  if (pAVar1 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    *param_2 = 0;
  }
  else {
    iVar2 = Ordinal_4(pAVar1 + 2,*(undefined2 *)pAVar1);
    *param_2 = iVar2;
  }
  return *param_2 != 0;
}



// Function: FUN_100013ed at 100013ed

void __fastcall FUN_100013ed(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 100013f6

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
                    /* WARNING: Could not recover jumptable at 0x1000143f. Too many branches */
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



// Function: Close at 1000144d

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



// Function: Open at 10001468

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



// Function: FUN_100014b7 at 100014b7

LSTATUS __thiscall FUN_100014b7(void *this,LPBYTE param_1,LPCWSTR param_2,LPDWORD param_3)

{
  short sVar1;
  LPDWORD lpcbData;
  LSTATUS LVar2;
  undefined4 *extraout_ECX;
  uint uVar3;
  
  lpcbData = param_3;
  if (param_3 == (LPDWORD)0x0) {
    FUN_1000121b(-0x7fffbffb);
    this = extraout_ECX;
  }
  param_3 = (LPDWORD)0x0;
                    /* WARNING: Load size is inaccurate */
  LVar2 = RegQueryValueExW(*this,param_2,(LPDWORD)0x0,(LPDWORD)&param_3,param_1,lpcbData);
  if (param_1 == (LPBYTE)0x0) {
    return LVar2;
  }
  uVar3 = *lpcbData;
  if (uVar3 == 0) {
    param_1[0] = '\0';
    param_1[1] = '\0';
    return LVar2;
  }
  if (param_3 != (LPDWORD)0x0) {
    if (param_3 < (LPDWORD)0x3) {
      if ((uVar3 & 1) != 0) goto LAB_10001530;
      sVar1 = *(short *)(param_1 + ((uVar3 & 0xfffffffe) - 2));
    }
    else {
      if ((((param_3 != (LPDWORD)0x7) || ((uVar3 & 1) != 0)) || (uVar3 = uVar3 >> 1, uVar3 == 0)) ||
         (*(short *)(param_1 + uVar3 * 2 + -2) != 0)) goto LAB_10001530;
      if (uVar3 < 2) {
        return LVar2;
      }
      sVar1 = *(short *)(param_1 + uVar3 * 2 + -4);
    }
    if (sVar1 == 0) {
      return LVar2;
    }
  }
LAB_10001530:
  param_1[0] = '\0';
  param_1[1] = '\0';
  return 0xd;
}



// Function: FID_conflict:_Inside at 10001546

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



// Function: FUN_10001582 at 10001582

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001582(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000158e;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100261e8);
}



// Function: FUN_10001613 at 10001613

void __fastcall FUN_10001613(int param_1)

{
  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 8) != 0)) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  return;
}



// Function: FUN_10001627 at 10001627

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10001627(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_10001657 at 10001657

long __thiscall FUN_10001657(void *this,void *param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  void *pvVar3;
  int iVar4;
  ulong local_10;
  ulong local_c;
  ulong local_8;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 != (void *)0x0) && ((*this == 0 || (param_2 != 0)))) {
    if ((int)param_2 < 0) {
      return -0x7ff8ffa9;
    }
    uVar1 = Ordinal_7(*this);
    local_c = 0;
    local_8 = 0;
    local_10 = 0;
    lVar2 = ATL::AtlAdd<unsigned_long>(&local_8,uVar1,param_2);
    if (lVar2 < 0) {
      return lVar2;
    }
    lVar2 = ATL::AtlMultiply<unsigned_long>(&local_10,local_8,2);
    if (lVar2 < 0) {
      return lVar2;
    }
    lVar2 = ATL::AtlMultiply<unsigned_long>(&local_c,uVar1,2);
    if (lVar2 < 0) {
      return lVar2;
    }
    pvVar3 = (void *)Ordinal_4(0,local_8);
    if (pvVar3 == (void *)0x0) {
      return -0x7ff8fff2;
    }
                    /* WARNING: Load size is inaccurate */
    iVar4 = Ordinal_7(*this);
    if (iVar4 != 0) {
                    /* WARNING: Load size is inaccurate */
      FUN_10001235(pvVar3,local_10,*this,local_c);
    }
    FUN_10001235((void *)((int)pvVar3 + uVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar3 + local_8 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar3;
  }
  return 0;
}



// Function: FUN_10001743 at 10001743

void __thiscall FUN_10001743(void *this,uint param_1)

{
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  FUN_100013ba(param_1,(int *)this);
  return;
}



// Function: FUN_10001764 at 10001764

LSTATUS __fastcall FUN_10001764(undefined4 *param_1)

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



// Function: FUN_10001769 at 10001769

uint __thiscall FUN_10001769(void *this,ushort *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  void *pvVar5;
  ushort *puVar6;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar4 = *(uint *)((int)this + 0x10) - param_2, param_3 <= uVar4)) {
      pvVar5 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar5 = *this;
      }
      puVar6 = (ushort *)((int)pvVar5 + param_2 * 2);
      uVar1 = *param_1;
      param_2 = uVar4 + (1 - param_3);
      while (puVar3 = (ushort *)FUN_10001119((short *)puVar6,uVar1,param_2), puVar3 != (ushort *)0x0
            ) {
        iVar2 = FUN_1000113a(puVar3,param_1,param_3);
        if (iVar2 == 0) {
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)puVar3 - (int)this >> 1;
        }
        param_2 = param_2 + (-1 - ((int)puVar3 - (int)puVar6 >> 1));
        puVar6 = puVar3 + 1;
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FID_conflict:_Tidy at 10001808

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



// Function: FUN_10001851 at 10001851

void __thiscall FUN_10001851(void *this,LPCWSTR param_1,REGSAM param_2,PHKEY param_3)

{
  *param_3 = (HKEY)0x0;
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(LPCWSTR *)param_1;
  }
                    /* WARNING: Load size is inaccurate */
  RegOpenKeyExW(*this,param_1,0,param_2,param_3);
  return;
}



// Function: FUN_10001878 at 10001878

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001878(undefined4 *param_1)

{
  *param_1 = CErrorDialogHelper::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_100018b8 at 100018b8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100018b8(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CErrorDialogHelper::vftable;
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001909 at 10001909

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10001909(void *this,undefined4 *param_1,LPCWSTR param_2,REGSAM param_3)

{
  HKEY local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10001915;
  local_14[0] = (HKEY)0x0;
  FUN_10001851(this,param_2,param_3,local_14);
  *param_1 = local_14[0];
  param_1[1] = 0;
  return;
}



// Function: FUN_1000194b at 1000194b

void __thiscall FUN_1000194b(void *this,LPDWORD param_1,LPBYTE param_2,LPDWORD param_3)

{
  LPCWSTR lpValueName;
  
  lpValueName = (LPCWSTR)((int)this + 8);
  if (7 < *(uint *)((int)this + 0x1c)) {
    lpValueName = *(LPCWSTR *)lpValueName;
  }
                    /* WARNING: Load size is inaccurate */
  RegQueryValueExW(*this,lpValueName,(LPDWORD)0x0,param_1,param_2,param_3);
  return;
}



// Function: FUN_10001972 at 10001972

void * __thiscall FUN_10001972(void *this,LPCWSTR param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = lstrlenW(param_1);
  lVar2 = FUN_10001657(this,param_1,uVar1);
  if (lVar2 < 0) {
    FUN_1000121b(lVar2);
  }
  return this;
}



// Function: ~basic_string<> at 1000199d

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



// Function: FUN_100019a7 at 100019a7

undefined4 * __thiscall FUN_100019a7(void *this,uint param_1,uint param_2)

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



// Function: FUN_10001a28 at 10001a28

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10001a28(void *this,uint param_1)

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
  FUN_10001582((char *)(param_1 + 1));
  FUN_10001abd();
  return;
}



// Function: Catch@10001a8f at 10001a8f

undefined * Catch_10001a8f(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001582((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001ab7;
}



// Function: FUN_10001abd at 10001abd

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001abd(void)

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



// Function: Catch@10001b0b at 10001b0b

void Catch_10001b0b(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001b20 at 10001b20

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001b20(int *param_1)

{
  FID_conflict__Tidy(param_1 + 2,'\x01',0);
  FUN_1000104b(param_1);
  return;
}



// Function: FUN_10001b52 at 10001b52

undefined4 * __thiscall FUN_10001b52(void *this,byte param_1)

{
  FUN_100018b8((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001b71 at 10001b71

void __thiscall FUN_10001b71(void *this,undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + 0xc);
  if ((int *)*piVar1 != (int *)*param_1) {
    FUN_1000131f(piVar1,(int *)*param_1);
  }
  (**(code **)(*(int *)*piVar1 + 0x20))((int *)*piVar1,(undefined4 *)((int)this + 4));
  *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 4);
  return;
}



// Function: FUN_10001ba4 at 10001ba4

void __thiscall FUN_10001ba4(void *this,undefined4 *param_1)

{
  if (*(int **)((int)this + 0x10) != (int *)*param_1) {
    FUN_1000131f((int *)((int)this + 0x10),(int *)*param_1);
  }
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return;
}



// Function: FUN_10001bca at 10001bca

bool __fastcall FUN_10001bca(undefined4 *param_1)

{
  LPCWSTR lpValueName;
  LSTATUS LVar1;
  
  lpValueName = (LPCWSTR)(param_1 + 2);
  if (7 < (uint)param_1[7]) {
    lpValueName = *(LPCWSTR *)lpValueName;
  }
  LVar1 = RegQueryValueExW((HKEY)*param_1,lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                           (LPDWORD)0x0);
  return (bool)('\x01' - (LVar1 != 0));
}



// Function: FUN_10001beb at 10001beb

bool __thiscall FUN_10001beb(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001a28(this,param_1);
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



// Function: FUN_10001c55 at 10001c55

undefined4 * __thiscall FUN_10001c55(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint extraout_EAX;
  uint uVar2;
  int extraout_EAX_00;
  int iVar3;
  void *pvVar4;
  
  uVar2 = param_1[4];
  if (uVar2 < param_2) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
  }
  if (uVar2 - param_2 < param_3) {
    param_3 = uVar2 - param_2;
  }
  iVar3 = *(int *)((int)this + 0x10);
  if (-iVar3 - 1U <= param_3) {
    std::_Xlength_error("string too long");
    iVar3 = extraout_EAX_00;
  }
  if (param_3 != 0) {
    uVar2 = iVar3 + param_3;
    bVar1 = FUN_10001beb(this,uVar2,'\0');
    if (bVar1) {
      if (7 < (uint)param_1[5]) {
        param_1 = (undefined4 *)*param_1;
      }
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      memcpy((void *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2),
             (void *)((int)param_1 + param_2 * 2),param_3 * 2);
      *(uint *)((int)this + 0x10) = uVar2;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      *(undefined2 *)((int)pvVar4 + uVar2 * 2) = 0;
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10001cfa at 10001cfa

void __thiscall FUN_10001cfa(void *this,uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if ((uVar1 <= param_1) && (*(uint *)((int)this + 0x14) != param_1)) {
    bVar2 = FUN_10001beb(this,param_1,'\x01');
    if (bVar2) {
      *(uint *)((int)this + 0x10) = uVar1;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        this = *this;
      }
      *(undefined2 *)((int)this + uVar1 * 2) = 0;
    }
  }
  return;
}



// Function: FUN_10001d33 at 10001d33

undefined4 * __thiscall FUN_10001d33(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int extraout_EAX;
  int iVar3;
  void *pvVar4;
  
  uVar2 = FID_conflict__Inside(this,param_1);
  if ((char)uVar2 == '\0') {
    iVar3 = *(int *)((int)this + 0x10);
    if (-iVar3 - 1U <= param_2) {
      std::_Xlength_error("string too long");
      iVar3 = extraout_EAX;
    }
    if (param_2 != 0) {
      uVar2 = iVar3 + param_2;
      bVar1 = FUN_10001beb(this,uVar2,'\0');
      if (bVar1) {
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        memcpy((void *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2),param_1,param_2 * 2);
        *(uint *)((int)this + 0x10) = uVar2;
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        *(undefined2 *)((int)pvVar4 + uVar2 * 2) = 0;
      }
    }
  }
  else {
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    this = FUN_10001c55(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001dd5 at 10001dd5

undefined4 * __thiscall FUN_10001dd5(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_100019a7(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_100019a7(this,0,param_2);
  }
  else {
    bVar1 = FUN_10001beb(pvVar3,uVar4,'\0');
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



// Function: FUN_10001e71 at 10001e71

undefined4 * __thiscall
FUN_10001e71(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,
            uint param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 *extraout_EAX;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 *puVar6;
  void *pvVar7;
  uint uVar8;
  uint extraout_EDX;
  undefined4 *puVar9;
  
  uVar8 = *(uint *)((int)this + 0x10);
  if ((uVar8 < param_1) || ((uint)param_3[4] < param_4)) {
    std::_Xout_of_range("invalid string position");
    pcVar1 = (code *)swi(3);
    puVar9 = (undefined4 *)(*pcVar1)();
    return puVar9;
  }
  puVar9 = (undefined4 *)(uVar8 - param_1);
  if (puVar9 < param_2) {
    param_2 = puVar9;
  }
  puVar6 = (undefined4 *)(param_3[4] - param_4);
  if (puVar6 < param_5) {
    param_5 = (uint)puVar6;
  }
  uVar8 = uVar8 - (int)param_2;
  puVar6 = param_2;
  if (-param_5 - 1 <= uVar8) {
    std::_Xlength_error("string too long");
    puVar6 = extraout_EAX;
    uVar8 = extraout_EDX;
  }
  puVar9 = (undefined4 *)((int)puVar9 - (int)puVar6);
  uVar8 = uVar8 + param_5;
  if (*(uint *)((int)this + 0x10) < uVar8) {
    FUN_10001beb(this,uVar8,'\0');
    puVar6 = param_2;
  }
  if ((undefined4 *)this != param_3) {
    pvVar5 = this;
    param_2 = (undefined4 *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      param_2 = *this;
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
    }
    memmove((void *)((int)pvVar5 + (param_1 + param_5) * 2),
            (void *)((int)param_2 + ((int)puVar6 + param_1) * 2),(int)puVar9 * 2);
    if (7 < (uint)param_3[5]) {
      param_3 = (undefined4 *)*param_3;
    }
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
    }
    memcpy((void *)((int)pvVar5 + param_1 * 2),(void *)((int)param_3 + param_4 * 2),param_5 * 2);
    goto LAB_10002144;
  }
  pvVar4 = this;
  pvVar5 = this;
  if (puVar6 < param_5) {
    if (param_4 <= param_1) {
      pvVar7 = this;
      param_2 = (undefined4 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        param_2 = *this;
                    /* WARNING: Load size is inaccurate */
        pvVar7 = *this;
      }
      memmove((void *)((int)pvVar7 + (param_1 + param_5) * 2),
              (void *)((int)param_2 + ((int)puVar6 + param_1) * 2),(int)puVar9 * 2);
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      goto LAB_10001fb8;
    }
    if (param_4 < param_1 + (int)puVar6) {
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      memmove((void *)((int)pvVar4 + param_1 * 2),(void *)((int)pvVar5 + param_4 * 2),
              (int)puVar6 * 2);
      pvVar5 = this;
      param_3 = (undefined4 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        param_3 = *this;
                    /* WARNING: Load size is inaccurate */
        pvVar5 = *this;
      }
      iVar2 = ((int)param_2 + param_1) * 2;
      memmove((void *)((int)pvVar5 + (param_1 + param_5) * 2),(void *)(iVar2 + (int)param_3),
              (int)puVar9 * 2);
      pvVar4 = this;
      pvVar5 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      memmove((void *)(iVar2 + (int)pvVar4),(void *)((int)pvVar5 + (param_4 + param_5) * 2),
              (param_5 - (int)param_2) * 2);
      goto LAB_10002144;
    }
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar5 = *this;
    }
    memmove((void *)((int)pvVar4 + (param_1 + param_5) * 2),
            (void *)((int)pvVar5 + (param_1 + (int)puVar6) * 2),(int)puVar9 * 2);
    pvVar4 = this;
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar5 = *this;
    }
    pvVar5 = (void *)((int)pvVar5 + ((param_4 - (int)param_2) + param_5) * 2);
    pvVar4 = (void *)((int)pvVar4 + param_1 * 2);
  }
  else {
    pvVar3 = this;
    pvVar7 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
      pvVar7 = *this;
    }
    memmove((void *)((int)pvVar3 + param_1 * 2),(void *)((int)pvVar7 + param_4 * 2),param_5 * 2);
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar5 = *this;
    }
    param_4 = (int)param_2 + param_1;
    param_1 = param_1 + param_5;
    param_5 = (uint)puVar9;
LAB_10001fb8:
    pvVar5 = (void *)((int)pvVar5 + param_4 * 2);
    pvVar4 = (void *)((int)pvVar4 + param_1 * 2);
  }
  memmove(pvVar4,pvVar5,param_5 * 2);
LAB_10002144:
  *(uint *)((int)this + 0x10) = uVar8;
  pvVar5 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar5 = *this;
  }
  *(undefined2 *)((int)pvVar5 + uVar8 * 2) = 0;
  return (undefined4 *)this;
}



// Function: FID_conflict:assign at 10002174

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
    bVar1 = FUN_10001beb(this,param_2,'\0');
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
    this = FUN_10001dd5(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_100021f2 at 100021f2

undefined2 * __thiscall FUN_100021f2(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FUN_10001dd5(this,param_1,param_2,param_3);
  return (undefined2 *)this;
}



// Function: basic_string<> at 1000221d

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(unsigned short const
   *,unsigned int)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(wchar_t const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

undefined2 * __thiscall basic_string<>(void *this,undefined4 *param_1,uint param_2)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FID_conflict_assign(this,param_1,param_2);
  return (undefined2 *)this;
}



// Function: basic_string<> at 10002245

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > const &)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > const &)
   
   Library: Visual Studio 2010 Release */

undefined2 * __thiscall basic_string<>(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FUN_10001dd5(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: FUN_1000226d at 1000226d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000226d(void *this,void *param_1,uint param_2,uint param_3)

{
  FUN_100021f2(param_1,(undefined4 *)this,param_2,param_3);
  return param_1;
}



// Function: FUN_100022a6 at 100022a6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_100022a6(void *this,void *param_1)

{
  int iVar1;
  LPCWSTR lpValueName;
  undefined1 local_30 [16];
  DWORD local_20 [2];
  DWORD local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x100022b2;
  local_20[1] = 0;
  lpValueName = (LPCWSTR)((int)this + 8);
  local_18[0] = 0;
  if (7 < *(uint *)((int)this + 0x1c)) {
    lpValueName = *(LPCWSTR *)lpValueName;
  }
                    /* WARNING: Load size is inaccurate */
  RegQueryValueExW(*this,lpValueName,(LPDWORD)0x0,local_20,(LPBYTE)0x0,local_18);
  iVar1 = -local_18[0];
  *(DWORD **)((int)local_18 + iVar1 + -0x1c) = local_18;
  *(undefined1 **)((int)local_18 + iVar1 + -0x20) = local_30 + iVar1;
  *(undefined4 *)(&stack0xffffffc4 + iVar1) = 0;
  *(undefined4 *)((int)local_20 + iVar1 + -0x20) = 0x100022f2;
  FUN_1000194b(this,*(LPDWORD *)(&stack0xffffffc4 + iVar1),
               *(LPBYTE *)((int)local_18 + iVar1 + -0x20),
               *(LPDWORD *)((int)local_18 + iVar1 + -0x1c));
  *(DWORD *)((int)local_18 + iVar1 + -0x1c) = (local_18[0] >> 1) - 1;
  *(undefined1 **)((int)local_18 + iVar1 + -0x20) = local_30 + iVar1;
  *(undefined4 *)(&stack0xffffffc4 + iVar1) = 0x10002302;
  basic_string<>(param_1,*(undefined4 **)((int)local_18 + iVar1 + -0x20),
                 *(uint *)((int)local_18 + iVar1 + -0x1c));
  local_8 = 0;
  local_20[1] = 1;
  FUN_100173c1();
  return;
}



// Function: FUN_1000231a at 1000231a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000231a(void *this,int *param_1,undefined4 *param_2)

{
  FUN_1000106c(this,param_1);
  basic_string<>((void *)((int)this + 8),param_2);
  return this;
}



// Function: FUN_10002350 at 10002350

undefined2 * __thiscall FUN_10002350(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10002382 at 10002382

undefined4 * __thiscall FUN_10002382(void *this,undefined4 *param_1)

{
  if ((undefined4 *)this != param_1) {
    FID_conflict__Tidy(this,'\x01',0);
    if ((uint)param_1[5] < 8) {
      memmove(this,param_1,param_1[4] * 2 + 2);
    }
    else {
      *(undefined4 *)this = *param_1;
      *param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    param_1[4] = 0;
    param_1[5] = 7;
    *(undefined2 *)param_1 = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_100023df at 100023df

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100023df(void *this,void *param_1)

{
  FUN_100022a6(this,param_1);
  return param_1;
}



// Function: FUN_1000240d at 1000240d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000240d(void *this,void *param_1,undefined4 *param_2)

{
  FUN_1000231a(param_1,(int *)this,param_2);
  return param_1;
}



// Function: basic_string<> at 1000243f

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(class
   std::basic_string<unsigned short,struct std::char_traits<unsigned short>,class
   std::allocator<unsigned short> > &&)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > &&)
   
   Library: Visual Studio 2010 Release */

undefined2 * __thiscall basic_string<>(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FUN_10002382(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_10002464 at 10002464

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10002464(void *this,void *param_1,undefined4 *param_2)

{
  FUN_1000240d(this,param_1,param_2);
  return param_1;
}



// Function: FUN_10002495 at 10002495

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10002495(undefined2 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_10001cfa(param_1,param_3[4] + param_2[4]);
  FUN_10001c55(param_1,param_2,0,0xffffffff);
  FUN_10001c55(param_1,param_3,0,0xffffffff);
  return param_1;
}



// Function: FUN_100024f9 at 100024f9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100024f9(void *param_1,void *param_2,wchar_t *param_3)

{
  size_t sVar1;
  undefined4 *puVar2;
  
  sVar1 = wcslen(param_3);
  puVar2 = FUN_10001d33(param_2,(undefined4 *)param_3,sVar1);
  basic_string<>(param_1,puVar2);
  return param_1;
}



// Function: FUN_1000253c at 1000253c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000253c(void *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  uint uVar2;
  
  basic_string<>(param_1,param_2);
  puVar1 = DAT_1002eed8;
  if (DAT_1002eeec < 8) {
    puVar1 = (ushort *)&DAT_1002eed8;
  }
  uVar2 = FUN_10001769(param_1,puVar1,0,(uint)DAT_1002eee8);
  while (uVar2 != 0xffffffff) {
    FUN_10001e71(param_1,uVar2,DAT_1002eee8,(undefined4 *)&DAT_1002eef4,0,0xffffffff);
    puVar1 = DAT_1002eed8;
    if (DAT_1002eeec < 8) {
      puVar1 = (ushort *)&DAT_1002eed8;
    }
    uVar2 = FUN_10001769(param_1,puVar1,0,(uint)DAT_1002eee8);
  }
  while( true ) {
    puVar1 = DAT_1002eea0;
    if (DAT_1002eeb4 < 8) {
      puVar1 = (ushort *)&DAT_1002eea0;
    }
    uVar2 = FUN_10001769(param_1,puVar1,0,(uint)DAT_1002eeb0);
    if (uVar2 == 0xffffffff) break;
    FUN_10001e71(param_1,uVar2,DAT_1002eeb0,(undefined4 *)&DAT_1002eebc,0,0xffffffff);
  }
  return param_1;
}



// Function: FUN_1000260e at 1000260e

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000260e(undefined2 *param_1,LPCWSTR param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  void *this;
  int local_78 [2];
  undefined2 *local_70;
  int local_6c [2];
  char local_61;
  int local_60 [9];
  int local_3c [2];
  undefined4 local_34 [11];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_70 = param_1;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_6c[0] = param_4;
  local_6c[1] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 3;
  FUN_10001909(local_6c,local_78,param_2,0xf003f);
  local_8._0_1_ = 5;
  FUN_1000104b(local_6c);
  puVar1 = (undefined4 *)FUN_10002464(local_78,local_3c,param_3);
  local_8._0_1_ = 7;
  local_61 = FUN_10001bca(puVar1);
  local_8._0_1_ = 5;
  FUN_10001b20(local_3c);
  if (local_61 != '\0') {
    this = FUN_10002464(local_78,local_60,param_3);
    local_8._0_1_ = 8;
    FUN_100023df(this,local_34);
    local_8._0_1_ = 9;
    FUN_10002382(param_1,local_34);
    local_8._0_1_ = 8;
    FID_conflict__Tidy(local_34,'\x01',0);
    local_8._0_1_ = 5;
    FUN_10001b20(local_60);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000104b(local_78);
  local_8 = 0;
  FUN_1000270e();
  return;
}



// Function: Catch@10002701 at 10002701

undefined * Catch_10002701(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000270b;
}



// Function: FUN_1000270e at 1000270e

void FUN_1000270e(void)

{
  FUN_100173d0();
  return;
}



// Function: FUN_10002716 at 10002716

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10002716(CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  *param_1,undefined4 *param_2,CSimpleStringT<wchar_t,1> *param_3)

{
  int *piVar1;
  code *pcVar2;
  wchar_t *pwVar3;
  int iVar4;
  int local_5c;
  int *local_58;
  int *local_54;
  wchar_t *local_50;
  undefined1 local_4c [28];
  undefined4 local_30 [10];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_54 = (int *)0x0;
  local_58 = (int *)0x0;
  local_8 = 4;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(param_1);
  piVar1 = (int *)*param_2;
  pwVar3 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_(param_3);
  if (pwVar3 == (wchar_t *)0x0) {
    local_50 = (wchar_t *)0x0;
  }
  else {
    local_50 = (wchar_t *)Ordinal_2(pwVar3);
    if (local_50 == (wchar_t *)0x0) {
      FUN_1000121b(-0x7ff8fff2);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  local_8._0_1_ = 5;
  iVar4 = (**(code **)(*piVar1 + 0xdc))(piVar1,local_50,&local_54);
  local_8._0_1_ = 4;
  Ordinal_6(local_50);
  if (-1 < iVar4) {
    local_5c = 0;
    (**(code **)(*local_54 + 0x20))(local_54,&local_5c);
    if (0 < local_5c) {
      iVar4 = (**(code **)(*local_54 + 0x1c))(local_54,local_5c + -1,&local_58);
      if (-1 < iVar4) {
        local_50 = (wchar_t *)0x0;
        local_8._0_1_ = 6;
        iVar4 = (**(code **)(*local_58 + 0x68))(local_58,&local_50);
        if (-1 < iVar4) {
          FUN_10002350(local_30,local_50);
          local_8._0_1_ = 7;
          pwVar3 = (wchar_t *)FUN_1000253c(local_4c,local_30);
          local_8._0_1_ = 8;
          if (7 < *(uint *)(pwVar3 + 10)) {
            pwVar3 = *(wchar_t **)pwVar3;
          }
          ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
          operator=(param_1,pwVar3);
          local_8._0_1_ = 7;
          FID_conflict__Tidy(local_4c,'\x01',0);
          local_8._0_1_ = 6;
          FID_conflict__Tidy(local_30,'\x01',0);
        }
        local_8._0_1_ = 4;
        Ordinal_6(local_50);
      }
    }
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_58 != (int *)0x0) {
    (**(code **)(*local_58 + 8))(local_58);
  }
  local_8 = 0;
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54);
  }
  FUN_100173c1();
  return;
}



// Function: FUN_10002881 at 10002881

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10002881(int *param_1)

{
  int iVar1;
  LSTATUS LVar2;
  size_t sVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  ulong uVar6;
  DWORD local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  LPCWSTR *local_290;
  undefined2 local_28c [14];
  undefined1 local_270 [28];
  undefined2 local_254 [8];
  undefined4 local_244;
  undefined4 local_240;
  LPCWSTR *local_238 [4];
  int local_228;
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x290;
  local_29c = 0;
  local_298 = 0;
  local_294 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_2a0 = 0x208;
  local_240 = 7;
  local_244 = 0;
  local_254[0] = 0;
  if ((DAT_1002ee48 & 1) == 0) {
    DAT_1002ee48 = DAT_1002ee48 | 1;
    local_8._0_1_ = 2;
    FUN_10002350(&DAT_1002ee2c,L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Shell");
    _atexit((_func_4879 *)&LAB_1001de2c);
  }
  if ((DAT_1002ee48 & 2) == 0) {
    DAT_1002ee48 = DAT_1002ee48 | 2;
    local_8._0_1_ = 3;
    FUN_10002350(&DAT_1002ee10,L"HelpMapDB");
    _atexit((_func_4879 *)&LAB_1001de1d);
  }
  local_8._0_1_ = 1;
  iVar1 = Open(&local_29c,(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",0x2001f);
  if (iVar1 == 0) {
    LVar2 = FUN_100014b7(&local_29c,(LPBYTE)&local_21c,L"LanguageExt",&local_2a0);
    if (LVar2 == 0) {
      sVar3 = wcslen(&local_21c);
      FID_conflict_assign(local_254,(undefined4 *)&local_21c,sVar3);
    }
  }
  Ordinal_6(*param_1);
  *param_1 = 0;
  FUN_100013ba(0xfa2,param_1);
  FUN_1000260e((undefined2 *)local_238,(LPCWSTR)&DAT_1002ee2c,(undefined4 *)&DAT_1002ee10,
               -0x7ffffffe);
  local_8._0_1_ = 4;
  puVar4 = (undefined4 *)FUN_1000226d(local_238,local_270,0,local_228 - 0xe);
  local_8._0_1_ = 5;
  FUN_10002382(local_238,puVar4);
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_270,'\x01',0);
  puVar5 = FUN_10002495(local_28c,local_238,(undefined4 *)local_254);
  local_8._0_1_ = 6;
  puVar4 = (undefined4 *)FUN_100024f9(local_270,puVar5,L"\\base.chm.");
  local_8._0_1_ = 7;
  FUN_10002382(local_238,puVar4);
  local_8._0_1_ = 6;
  FID_conflict__Tidy(local_270,'\x01',0);
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_28c,'\x01',0);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  local_290 = local_238[0];
  uVar6 = lstrlenW((LPCWSTR)local_238[0]);
  FUN_10001657(param_1,local_290,uVar6);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_254,'\x01',0);
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_29c);
  FUN_100173c1();
  return;
}



// Function: FUN_10002af7 at 10002af7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> * __thiscall
FUN_10002af7(void *this,
            CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            *param_1)

{
  LPCOLESTR pOVar1;
  int iVar2;
  int *piVar3;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *pCVar4;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  LPCOLESTR local_24;
  undefined4 local_20;
  int *local_1c;
  wchar_t *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0;
  local_28 = 0;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(param_1);
  local_28 = 1;
  local_20 = 0;
  local_8 = 1;
  local_1c = *(int **)((int)this + 0x10);
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 4))(local_1c);
  }
  local_8._0_1_ = 3;
  piVar3 = *(int **)((int)this + 0xc);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x18))(piVar3,*(undefined4 *)((int)this + 8),0,&local_1c);
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 0x14))(local_1c,&local_20);
    local_14[0] = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,5);
    pOVar1 = (LPCOLESTR)Ordinal_2(L"Microsoft.XMLDOM");
    local_24 = pOVar1;
    if (pOVar1 == (LPCOLESTR)0x0) {
      pOVar1 = (LPCOLESTR)FUN_1000121b(-0x7ff8fff2);
    }
    local_8._0_1_ = 6;
    local_18 = (wchar_t *)FUN_10001182(local_14,pOVar1,(LPUNKNOWN)0x0,0x17);
    local_8._0_1_ = 5;
    Ordinal_6(local_24);
    if (-1 < (int)local_18) {
      local_2c = 0;
      iVar2 = (**(code **)(*local_14[0] + 0x104))(local_14[0],local_20,&local_2c);
      if (-1 < iVar2) {
        local_18 = (wchar_t *)0x0;
        local_8._0_1_ = 7;
        piVar3 = FUN_1001023a((int *)&local_24,(undefined4 *)&DAT_1002ee84);
        local_8._0_1_ = 8;
        FUN_10001352(&local_18,piVar3);
        local_8._0_1_ = 7;
        Ordinal_6(local_24);
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                    *)&local_24,local_18);
        local_8._0_1_ = 9;
        pCVar4 = (CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  *)FUN_10002716(local_30,local_14,(CSimpleStringT<wchar_t,1> *)&local_24);
        local_8._0_1_ = 10;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        operator=(param_1,pCVar4);
        local_8._0_1_ = 9;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  (local_30);
        local_8._0_1_ = 7;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                    *)&local_24);
        local_8._0_1_ = 5;
        Ordinal_6(local_18);
      }
    }
    local_8._0_1_ = 3;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_20);
  return param_1;
}



// Function: FUN_10002c85 at 10002c85

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> * __thiscall
FUN_10002c85(void *this,
            CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            *param_1)

{
  LPCOLESTR pOVar1;
  int iVar2;
  int *piVar3;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *pCVar4;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  LPCOLESTR local_24;
  undefined4 local_20;
  int *local_1c;
  wchar_t *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0;
  local_28 = 0;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(param_1);
  local_28 = 1;
  local_20 = 0;
  local_8 = 1;
  local_1c = *(int **)((int)this + 0x10);
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 4))(local_1c);
  }
  local_8._0_1_ = 3;
  piVar3 = *(int **)((int)this + 0xc);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x18))(piVar3,*(undefined4 *)((int)this + 8),0,&local_1c);
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 0x14))(local_1c,&local_20);
    local_14[0] = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,5);
    pOVar1 = (LPCOLESTR)Ordinal_2(L"Microsoft.XMLDOM");
    local_24 = pOVar1;
    if (pOVar1 == (LPCOLESTR)0x0) {
      pOVar1 = (LPCOLESTR)FUN_1000121b(-0x7ff8fff2);
    }
    local_8._0_1_ = 6;
    local_18 = (wchar_t *)FUN_10001182(local_14,pOVar1,(LPUNKNOWN)0x0,0x17);
    local_8._0_1_ = 5;
    Ordinal_6(local_24);
    if (-1 < (int)local_18) {
      local_2c = 0;
      iVar2 = (**(code **)(*local_14[0] + 0x104))(local_14[0],local_20,&local_2c);
      if (-1 < iVar2) {
        local_18 = (wchar_t *)0x0;
        local_8._0_1_ = 7;
        piVar3 = FUN_1001023a((int *)&local_24,(undefined4 *)&DAT_1002ee4c);
        local_8._0_1_ = 8;
        FUN_10001352(&local_18,piVar3);
        local_8._0_1_ = 7;
        Ordinal_6(local_24);
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                    *)&local_24,local_18);
        local_8._0_1_ = 9;
        pCVar4 = (CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  *)FUN_10002716(local_30,local_14,(CSimpleStringT<wchar_t,1> *)&local_24);
        local_8._0_1_ = 10;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        operator=(param_1,pCVar4);
        local_8._0_1_ = 9;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  (local_30);
        local_8._0_1_ = 7;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                    *)&local_24);
        local_8._0_1_ = 5;
        Ordinal_6(local_18);
      }
    }
    local_8._0_1_ = 3;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_20);
  return param_1;
}



// Function: FUN_10002e13 at 10002e13

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> * __thiscall
FUN_10002e13(void *this,
            CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            *param_1)

{
  LPCOLESTR pOVar1;
  int iVar2;
  int *piVar3;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *pCVar4;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  LPCOLESTR local_24;
  undefined4 local_20;
  int *local_1c;
  wchar_t *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0;
  local_28 = 0;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(param_1);
  local_28 = 1;
  local_20 = 0;
  local_8 = 1;
  local_1c = *(int **)((int)this + 0x10);
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 4))(local_1c);
  }
  local_8._0_1_ = 3;
  piVar3 = *(int **)((int)this + 0xc);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x18))(piVar3,*(undefined4 *)((int)this + 8),0,&local_1c);
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 0x14))(local_1c,&local_20);
    local_14[0] = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,5);
    pOVar1 = (LPCOLESTR)Ordinal_2(L"Microsoft.XMLDOM");
    local_24 = pOVar1;
    if (pOVar1 == (LPCOLESTR)0x0) {
      pOVar1 = (LPCOLESTR)FUN_1000121b(-0x7ff8fff2);
    }
    local_8._0_1_ = 6;
    local_18 = (wchar_t *)FUN_10001182(local_14,pOVar1,(LPUNKNOWN)0x0,0x17);
    local_8._0_1_ = 5;
    Ordinal_6(local_24);
    if (-1 < (int)local_18) {
      local_2c = 0;
      iVar2 = (**(code **)(*local_14[0] + 0x104))(local_14[0],local_20,&local_2c);
      if (-1 < iVar2) {
        local_18 = (wchar_t *)0x0;
        local_8._0_1_ = 7;
        piVar3 = FUN_1001023a((int *)&local_24,(undefined4 *)&DAT_1002ee68);
        local_8._0_1_ = 8;
        FUN_10001352(&local_18,piVar3);
        local_8._0_1_ = 7;
        Ordinal_6(local_24);
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                    *)&local_24,local_18);
        local_8._0_1_ = 9;
        pCVar4 = (CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  *)FUN_10002716(local_30,local_14,(CSimpleStringT<wchar_t,1> *)&local_24);
        local_8._0_1_ = 10;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        operator=(param_1,pCVar4);
        local_8._0_1_ = 9;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  (local_30);
        local_8._0_1_ = 7;
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                  ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                    *)&local_24);
        local_8._0_1_ = 5;
        Ordinal_6(local_18);
      }
    }
    local_8._0_1_ = 3;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_20);
  return param_1;
}



// Function: FUN_10002fa1 at 10002fa1

undefined * FUN_10002fa1(void)

{
  return &DAT_1001fe60;
}



// Function: FUN_10002fa7 at 10002fa7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> * __cdecl
FUN_10002fa7(CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
             *param_1,
            CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            *param_2,CSimpleStringT<wchar_t,1> *param_3)

{
  IAtlStringMgr *pIVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  wchar_t *pwVar5;
  
  pIVar1 = ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
           GetManager(param_2);
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(param_1,pIVar1)
  ;
  iVar2 = ATL::CSimpleStringT<wchar_t,1>::GetLength(param_3);
  pwVar3 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_(param_3);
  iVar4 = ATL::CSimpleStringT<wchar_t,1>::GetLength((CSimpleStringT<wchar_t,1> *)param_2);
  pwVar5 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                     ((CSimpleStringT<wchar_t,1> *)param_2);
  ATL::CSimpleStringT<wchar_t,1>::Concatenate
            ((CSimpleStringT<wchar_t,1> *)param_1,pwVar5,iVar4,pwVar3,iVar2);
  return param_1;
}



// Function: FUN_10003016 at 10003016

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> * __cdecl
FUN_10003016(CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
             *param_1,
            CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            *param_2,wchar_t *param_3)

{
  IAtlStringMgr *pIVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  
  pIVar1 = ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
           GetManager(param_2);
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(param_1,pIVar1)
  ;
  iVar2 = ATL::CSimpleStringT<wchar_t,1>::StringLength(param_3);
  iVar3 = ATL::CSimpleStringT<wchar_t,1>::GetLength((CSimpleStringT<wchar_t,1> *)param_2);
  pwVar4 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                     ((CSimpleStringT<wchar_t,1> *)param_2);
  ATL::CSimpleStringT<wchar_t,1>::Concatenate
            ((CSimpleStringT<wchar_t,1> *)param_1,pwVar4,iVar3,param_3,iVar2);
  return param_1;
}



// Function: FUN_1000307f at 1000307f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> * __cdecl
FUN_1000307f(CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
             *param_1,wchar_t *param_2,
            CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            *param_3)

{
  IAtlStringMgr *pIVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  
  pIVar1 = ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
           GetManager(param_3);
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(param_1,pIVar1)
  ;
  iVar2 = ATL::CSimpleStringT<wchar_t,1>::GetLength((CSimpleStringT<wchar_t,1> *)param_3);
  pwVar3 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                     ((CSimpleStringT<wchar_t,1> *)param_3);
  iVar4 = ATL::CSimpleStringT<wchar_t,1>::StringLength(param_2);
  ATL::CSimpleStringT<wchar_t,1>::Concatenate
            ((CSimpleStringT<wchar_t,1> *)param_1,param_2,iVar4,pwVar3,iVar2);
  return param_1;
}



// Function: FUN_100030e8 at 100030e8

void __fastcall FUN_100030e8(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_100030ef at 100030ef

undefined4 * __thiscall FUN_100030ef(void *this,byte param_1)

{
  FUN_100030e8((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000310e at 1000310e

void FUN_1000310e(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1000311e at 1000311e

void FUN_1000311e(void)

{
  return;
}



// Function: FUN_1000311f at 1000311f

void __fastcall FUN_1000311f(int param_1)

{
  EnableWindow(*(HWND *)(param_1 + 0x20),0);
  return;
}



// Function: FUN_1000312b at 1000312b

void __fastcall FUN_1000312b(int param_1)

{
  EnableWindow(*(HWND *)(param_1 + 0x20),1);
  return;
}



// Function: FUN_10003137 at 10003137

CListBox * __thiscall FUN_10003137(void *this,byte param_1)

{
  CListBox::~CListBox((CListBox *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CListBox *)this;
}



// Function: FUN_10003156 at 10003156

undefined4 __thiscall FUN_10003156(void *this,int param_1,undefined4 param_2)

{
  HANDLE hProcess;
  SIZE_T dwSize;
  
  *(undefined4 *)((int)this + 4) = param_2;
  dwSize = 0xd;
  *(undefined4 *)this = 0x42444c7;
  *(undefined1 *)((int)this + 8) = 0xe9;
  *(int *)((int)this + 9) = (param_1 - (int)this) + -0xd;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,this,dwSize);
  return 1;
}



// Function: FUN_1000318b at 1000318b

void __fastcall FUN_1000318b(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FreeStdCallThunk((void *)*param_1);
  }
  return;
}



// Function: FUN_10003198 at 10003198

void __thiscall FUN_10003198(void *this,int param_1,undefined4 param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    pvVar1 = __AllocStdCallThunk_cmn();
    *(void **)this = pvVar1;
    if (pvVar1 == (void *)0x0) {
      return;
    }
  }
                    /* WARNING: Load size is inaccurate */
  FUN_10003156(*this,param_1,param_2);
  return;
}



// Function: FUN_100031c0 at 100031c0

void __thiscall FUN_100031c0(void *this,HWND param_1)

{
  uint uVar1;
  HMONITOR hMonitor;
  BOOL BVar2;
  HWND pHVar3;
  int iVar4;
  int Y;
  int X;
  int iVar5;
  tagMONITORINFO local_60;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
                    /* WARNING: Load size is inaccurate */
  uVar1 = GetWindowLongW(*this,-0x10);
  if (param_1 == (HWND)0x0) {
    if ((uVar1 & 0x40000000) == 0) {
                    /* WARNING: Load size is inaccurate */
      param_1 = GetWindow(*this,4);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      param_1 = GetParent(*this);
    }
  }
                    /* WARNING: Load size is inaccurate */
  GetWindowRect(*this,&local_38);
  if ((uVar1 & 0x40000000) == 0) {
    if (param_1 == (HWND)0x0) {
LAB_10003242:
                    /* WARNING: Load size is inaccurate */
      pHVar3 = *this;
    }
    else {
      uVar1 = GetWindowLongW(param_1,-0x10);
      if (((uVar1 & 0x10000000) == 0) || ((uVar1 & 0x20000000) != 0)) {
        param_1 = (HWND)0x0;
      }
      pHVar3 = param_1;
      if (param_1 == (HWND)0x0) goto LAB_10003242;
    }
    hMonitor = MonitorFromWindow(pHVar3,2);
    if (hMonitor == (HMONITOR)0x0) goto LAB_10003339;
    local_60.cbSize = 0x28;
    BVar2 = GetMonitorInfoW(hMonitor,&local_60);
    if (BVar2 == 0) goto LAB_10003339;
    local_28.left = local_60.rcWork.left;
    local_28.top = local_60.rcWork.top;
    local_28.right = local_60.rcWork.right;
    local_28.bottom = local_60.rcWork.bottom;
    if (param_1 == (HWND)0x0) {
      local_18.left = local_60.rcWork.left;
      local_18.top = local_60.rcWork.top;
      local_18.right = local_60.rcWork.right;
      local_18.bottom = local_60.rcWork.bottom;
    }
    else {
      GetWindowRect(param_1,&local_18);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    pHVar3 = GetParent(*this);
    GetClientRect(pHVar3,&local_28);
    GetClientRect(param_1,&local_18);
    MapWindowPoints(param_1,pHVar3,(LPPOINT)&local_18,2);
  }
  iVar4 = local_38.right - local_38.left;
  iVar5 = local_38.bottom - local_38.top;
  X = (local_18.left + local_18.right) / 2 - iVar4 / 2;
  Y = (local_18.top + local_18.bottom) / 2 - iVar5 / 2;
  if (local_28.right < X + iVar4) {
    X = local_28.right - iVar4;
  }
  if (X < local_28.left) {
    X = local_28.left;
  }
  if (local_28.bottom < Y + iVar5) {
    Y = local_28.bottom - iVar5;
  }
  if (Y < local_28.top) {
    Y = local_28.top;
  }
                    /* WARNING: Load size is inaccurate */
  SetWindowPos(*this,(HWND)0x0,X,Y,-1,-1,0x15);
LAB_10003339:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000334a at 1000334a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000334a(int param_1)

{
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0xc));
  }
  return;
}



// Function: FUN_10003370 at 10003370

undefined4 __thiscall FUN_10003370(void *this,HWND param_1)

{
  int iVar1;
  LONG LVar2;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 8))();
  iVar1 = FUN_10003198((void *)((int)this + 0x14),iVar1,this);
  if ((iVar1 != 0) && (LVar2 = SetWindowLongW(param_1,-4,*(LONG *)((int)this + 0x14)), LVar2 != 0))
  {
    *(LONG *)((int)this + 0x20) = LVar2;
    *(HWND *)((int)this + 4) = param_1;
    return 1;
  }
  return 0;
}



// Function: FUN_100033b0 at 100033b0

undefined4 __thiscall FUN_100033b0(void *this,undefined4 param_1,ushort param_2)

{
  EndDialog(*(HWND *)((int)this + 4),(uint)param_2);
  return 0;
}



// Function: FUN_100033c7 at 100033c7

void __thiscall FUN_100033c7(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  HWND pHVar2;
  BOOL BVar3;
  tagRECT local_28;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  MoveWindow(*(HWND *)((int)this + 4),param_1,param_2,param_3 - param_1,param_4 - param_2,1);
  GetWindowRect(*(HWND *)((int)this + 4),&local_28);
  pHVar2 = GetDlgItem(*(HWND *)((int)this + 4),1);
  GetWindowRect(pHVar2,(LPRECT)local_18);
  BVar3 = ScreenToClient(*(HWND *)((int)this + 4),(LPPOINT)local_18);
  if (BVar3 != 0) {
    ScreenToClient(*(HWND *)((int)this + 4),(LPPOINT)(local_18 + 8));
  }
  iVar1 = (local_28.bottom - local_28.top) + -0x3c;
  MoveWindow(pHVar2,local_18._0_4_,iVar1,local_18._8_4_ - local_18._0_4_,
             ((local_28.bottom - local_28.top) + -0x25) - iVar1,1);
  pHVar2 = GetDlgItem(*(HWND *)((int)this + 4),9);
  GetWindowRect(pHVar2,(LPRECT)local_18);
  BVar3 = ScreenToClient(*(HWND *)((int)this + 4),(LPPOINT)local_18);
  if (BVar3 != 0) {
    ScreenToClient(*(HWND *)((int)this + 4),(LPPOINT)(local_18 + 8));
  }
  iVar1 = (local_28.bottom - local_28.top) + -0x3c;
  MoveWindow(pHVar2,local_18._0_4_,iVar1,local_18._8_4_ - local_18._0_4_,
             ((local_28.bottom - local_28.top) + -0x25) - iVar1,1);
  InvalidateRect(*(HWND *)((int)this + 4),(RECT *)0x0,1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100034d0 at 100034d0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100034d0(void *this,int *param_1)

{
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_100034fe at 100034fe

int * __thiscall FUN_100034fe(void *this,int param_1)

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
      FUN_1000121b(-0x7ff8fff2);
    }
    *(undefined4 *)this = 0;
  }
  return (int *)this;
}



// Function: Copy at 1000353b

/* Library Function - Single Match
    public: wchar_t * __thiscall ATL::CComBSTR::Copy(void)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

wchar_t * __thiscall ATL::CComBSTR::Copy(CComBSTR *this)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  
  pwVar2 = *(wchar_t **)this;
  if (pwVar2 == (wchar_t *)0x0) {
    return pwVar2;
  }
  uVar1 = Ordinal_149(pwVar2);
  pwVar2 = (wchar_t *)Ordinal_150(*(undefined4 *)this,uVar1);
  return pwVar2;
}



// Function: FUN_10003558 at 10003558

void __fastcall FUN_10003558(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10003560 at 10003560

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003560(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  return;
}



// Function: FUN_10003590 at 10003590

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003590(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



// Function: FUN_100035c6 at 100035c6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_100035c6(void *this,int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  bool bVar4;
  undefined1 *puVar5;
  wchar_t *pwVar6;
  HWND hWnd;
  BOOL BVar7;
  UINT Msg;
  WPARAM wParam;
  undefined4 local_4c;
  int local_48;
  int local_44;
  wchar_t *local_40;
  undefined4 *local_20;
  int local_1c;
  wchar_t *local_18;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_14 [12];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  puVar5 = &LAB_10018b4f;
  iVar1 = *param_1;
  local_20 = (undefined4 *)this;
  do {
    if (iVar1 == 0) {
      return puVar5;
    }
    local_18 = (wchar_t *)0x0;
    local_8 = 0;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_14);
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar1 = *param_1;
    local_1c = -0x7fffbffb;
    if (((iVar1 == 0x1f5) || (iVar1 == 0x192)) || (iVar1 == 0x193)) {
      local_1c = 0;
    }
    else {
      uVar2 = param_1[2];
      Ordinal_6(0);
      local_18 = (wchar_t *)0x0;
      bVar4 = FUN_100013ba(uVar2,(int *)&local_18);
      if (bVar4) {
        ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
        operator=(local_14,local_18);
        local_1c = 0;
      }
    }
    puVar3 = local_20;
    if (*param_1 == 100) {
      pwVar6 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                         ((CSimpleStringT<wchar_t,1> *)local_14);
      hWnd = (HWND)*local_20;
LAB_10003783:
      SetWindowTextW(hWnd,pwVar6);
    }
    else {
      hWnd = GetDlgItem((HWND)*local_20,param_1[1]);
      if (((-1 < local_1c) && (BVar7 = IsWindow((HWND)*puVar3), BVar7 != 0)) &&
         (BVar7 = IsWindow(hWnd), BVar7 != 0)) {
        iVar1 = *param_1;
        if ((iVar1 == 200) || (iVar1 == 300)) {
          ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
          Replace(local_14,L"\\r\\n",L"\r\n");
          pwVar6 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                             ((CSimpleStringT<wchar_t,1> *)local_14);
          goto LAB_10003783;
        }
        if (iVar1 == 500) {
          local_44 = param_1[4];
          local_48 = param_1[5];
          local_4c = 7;
          local_40 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                               ((CSimpleStringT<wchar_t,1> *)local_14);
          pwVar6 = (wchar_t *)&local_4c;
          wParam = param_1[3];
          Msg = 0x1061;
        }
        else if (iVar1 == 0x1f5) {
          pwVar6 = (wchar_t *)(uint)*(ushort *)(param_1 + 4);
          wParam = param_1[3];
          Msg = 0x101e;
        }
        else if (iVar1 == 400) {
          pwVar6 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                             ((CSimpleStringT<wchar_t,1> *)local_14);
          wParam = 0;
          Msg = 0x143;
        }
        else if (iVar1 == 0x191) {
          pwVar6 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                             ((CSimpleStringT<wchar_t,1> *)local_14);
          wParam = param_1[3];
          Msg = 0x14a;
        }
        else if (iVar1 == 0x192) {
          pwVar6 = (wchar_t *)0x0;
          wParam = param_1[3];
          Msg = 0x14e;
        }
        else {
          if (iVar1 != 0x193) goto LAB_10003789;
          pwVar6 = (wchar_t *)param_1[4];
          wParam = param_1[3];
          Msg = 0x151;
        }
        SendMessageW(hWnd,Msg,wParam,(LPARAM)pwVar6);
      }
    }
LAB_10003789:
    param_1 = param_1 + 6;
    local_8 = local_8 & 0xffffff00;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_14);
    local_8 = 0xffffffff;
    puVar5 = (undefined1 *)Ordinal_6(local_18);
    iVar1 = *param_1;
  } while( true );
}



// Function: FUN_100037b8 at 100037b8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_100037b8(void *param_1)

{
  int iVar1;
  uint uVar2;
  LPCWSTR local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x100037c4;
  GetWindowRect(*(HWND *)((int)param_1 + 4),&local_24);
  local_28 = (LPCWSTR)0x0;
  local_8 = 0;
  if (*(char *)((int)param_1 + 0xb8) == '\x01') {
    iVar1 = 0x1c0;
    Ordinal_6(0);
    uVar2 = 0x70;
  }
  else {
    iVar1 = 0x8c;
    Ordinal_6(0);
    uVar2 = 0x71;
  }
  local_28 = (LPCWSTR)0x0;
  FUN_100013ba(uVar2,(int *)&local_28);
  SetWindowTextW(*(HWND *)((int)param_1 + 0x7c),local_28);
  FUN_100033c7(param_1,local_24.left,local_24.top,local_24.right,local_24.top + iVar1);
  local_8 = 0xffffffff;
  Ordinal_6(local_28);
  FUN_100173c1();
  return;
}



// Function: FUN_1000385e at 1000385e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000385e(int param_1)

{
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *pCVar1;
  wchar_t *lpString;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_28 [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_24 [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_20 [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_1c [4];
  wchar_t *local_18;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_14 [12];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x1000386a;
  FUN_10002af7((void *)(param_1 + 0x24),local_20);
  local_8 = 0;
  FUN_10002c85((void *)(param_1 + 0x24),local_1c);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_18 = (wchar_t *)0x0;
  local_8._0_1_ = 2;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_14);
  local_8._0_1_ = 3;
  Ordinal_6(0);
  local_18 = (wchar_t *)0x0;
  FUN_100013ba(0x6b,(int *)&local_18);
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::operator=
            (local_14,local_18);
  pCVar1 = FUN_10003016(local_28,local_20,L"\r\n");
  local_8._0_1_ = 4;
  pCVar1 = FUN_10002fa7(local_24,pCVar1,(CSimpleStringT<wchar_t,1> *)local_1c);
  local_8._0_1_ = 5;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  operator+=(local_14,(CSimpleStringT<wchar_t,1> *)pCVar1);
  local_8._0_1_ = 4;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_24);
  local_8._0_1_ = 3;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_28);
  lpString = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                       ((CSimpleStringT<wchar_t,1> *)local_14);
  SetDlgItemTextW(*(HWND *)(param_1 + 4),0xd8,lpString);
  local_8._0_1_ = 2;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_14);
  local_8._0_1_ = 1;
  Ordinal_6(local_18);
  local_8 = (uint)local_8._1_3_ << 8;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_1c);
  local_8 = 0xffffffff;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_20);
  return;
}



// Function: FUN_10003962 at 10003962

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003962(void *this,int param_1)

{
  *(undefined ***)this = CErrorDialogHelper::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  FUN_10001627((void *)((int)this + 0xc),(int *)(param_1 + 0xc));
  FUN_10001627((void *)((int)this + 0x10),(int *)(param_1 + 0x10));
  return (undefined4 *)this;
}



// Function: FUN_100039b2 at 100039b2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100039b2(int param_1)

{
  HWND pHVar1;
  LRESULT LVar2;
  int iVar3;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *pCVar4;
  wchar_t *lpString;
  undefined **local_b8 [8];
  HWND local_98;
  undefined4 local_44 [5];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_30 [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_2c [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_28 [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_24 [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_20 [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_1c [4];
  wchar_t *local_18;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_14 [12];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa8;
  local_8 = 0x100039c1;
  FUN_10003962(local_44,param_1 + 0x24);
  local_8 = 0;
  CWnd::CWnd((CWnd *)local_b8);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_b8[0] = CListBox::vftable;
  local_8._0_1_ = 2;
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 4),0xd9);
  CWnd::Attach((CWnd *)local_b8,pHVar1);
  LVar2 = SendMessageW(local_98,0x188,0,0);
  FUN_1000116e(local_44,LVar2);
  FUN_10002c85(local_44,local_24);
  local_8._0_1_ = 3;
  FUN_10002e13(local_44,local_20);
  local_8._0_1_ = 4;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_14);
  local_18 = (wchar_t *)0x0;
  local_8._0_1_ = 6;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_1c);
  local_8._0_1_ = 7;
  Ordinal_6(0);
  local_18 = (wchar_t *)0x0;
  FUN_100013ba(0x66,(int *)&local_18);
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::operator=
            (local_1c,local_18);
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::operator=
            (local_14,local_24);
  iVar3 = ATL::CSimpleStringT<wchar_t,1>::GetLength((CSimpleStringT<wchar_t,1> *)local_20);
  if (0 < iVar3) {
    pCVar4 = FUN_1000307f(local_28,L"\r\n\r\n",local_1c);
    local_8._0_1_ = 8;
    pCVar4 = FUN_10003016(local_30,pCVar4,L" ");
    local_8._0_1_ = 9;
    pCVar4 = FUN_10002fa7(local_2c,pCVar4,(CSimpleStringT<wchar_t,1> *)local_20);
    local_8._0_1_ = 10;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    operator+=(local_14,(CSimpleStringT<wchar_t,1> *)pCVar4);
    local_8._0_1_ = 9;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_2c);
    local_8._0_1_ = 8;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_30);
    local_8._0_1_ = 7;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_28);
  }
  lpString = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                       ((CSimpleStringT<wchar_t,1> *)local_14);
  SetDlgItemTextW(*(HWND *)(param_1 + 4),0xda,lpString);
  CWnd::Detach((CWnd *)local_b8);
  local_8._0_1_ = 6;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_1c);
  local_8._0_1_ = 5;
  Ordinal_6(local_18);
  local_8._0_1_ = 4;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_14);
  local_8._0_1_ = 3;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_20);
  local_8._0_1_ = 2;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_24);
  local_8 = (uint)local_8._1_3_ << 8;
  CListBox::~CListBox((CListBox *)local_b8);
  local_8 = 0xffffffff;
  FUN_100018b8(local_44);
  return;
}



// Function: FUN_10003b96 at 10003b96

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003b96(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  piVar2 = param_1 + 1;
  piVar1 = (int *)*piVar2;
  if (piVar1 != (int *)0x0) {
    *piVar2 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar2 = (int *)*piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return;
}



// Function: FUN_10003bde at 10003bde

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003bde(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  piVar2 = param_1 + 1;
  piVar1 = (int *)*piVar2;
  if (piVar1 != (int *)0x0) {
    *piVar2 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar2 = (int *)*piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return;
}



// Function: FUN_10003c26 at 10003c26

undefined4 * __thiscall FUN_10003c26(void *this,byte param_1)

{
  FUN_10003b96((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003c45 at 10003c45

undefined4 * __thiscall FUN_10003c45(void *this,byte param_1)

{
  FUN_10003bde((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003c64 at 10003c64

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003c64(void *this,int *param_1)

{
  FUN_100034d0((void *)((int)this + 4),param_1);
  *(undefined ***)this =
       TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  return (undefined4 *)this;
}



// Function: FUN_10003c98 at 10003c98

void __fastcall FUN_10003c98(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: CComBSTR at 10003cb0

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(class ATL::CComBSTR const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = Copy(param_1);
  *(wchar_t **)this = pwVar1;
  if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
    FUN_1000121b(-0x7ff8fff2);
  }
  return this;
}



// Function: FUN_10003cde at 10003cde

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003cde(int param_1)

{
  FUN_10003560(param_1);
  return;
}



// Function: FUN_10003cfc at 10003cfc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10003cfc(int param_1)

{
  FUN_10003590(param_1);
  *(code **)(param_1 + 0x20) = DefWindowProcW_exref;
  return param_1;
}



// Function: FUN_10003d2a at 10003d2a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003d2a(int param_1)

{
  Ordinal_6(*(undefined4 *)(param_1 + 0x38));
  FUN_10003560(param_1);
  return;
}



// Function: FUN_10003d59 at 10003d59

undefined4 __fastcall FUN_10003d59(void *param_1)

{
  *(bool *)((int)param_1 + 0xb8) = *(char *)((int)param_1 + 0xb8) == '\0';
  FUN_100037b8(param_1);
  return 0;
}



// Function: FUN_10003d74 at 10003d74

undefined4 __fastcall FUN_10003d74(int param_1)

{
  FUN_100039b2(param_1);
  return 0;
}



// Function: FUN_10003d7e at 10003d7e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003d7e(int param_1)

{
  int iVar1;
  HWND pHVar2;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *pCVar3;
  wchar_t *lParam;
  int iVar4;
  uint uVar5;
  undefined **local_b4 [8];
  HWND local_94;
  undefined4 local_40 [5];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_2c [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_28 [4];
  undefined4 local_24;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_20 [4];
  int local_1c;
  uint local_18;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_14 [12];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa4;
  local_8 = 0x10003d8d;
  iVar1 = param_1 + 0x24;
  FUN_10003962(local_40,iVar1);
  local_8 = 0;
  CWnd::CWnd((CWnd *)local_b4);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_b4[0] = CListBox::vftable;
  local_8._0_1_ = 2;
  pHVar2 = GetDlgItem(*(HWND *)(param_1 + 4),0xd9);
  CWnd::Attach((CWnd *)local_b4,pHVar2);
  local_24 = 0xf;
  SendMessageW(local_94,0x192,1,(LPARAM)&local_24);
  local_1c = 0;
  local_18 = 0;
  FUN_1000117e(iVar1);
  do {
    FUN_10002af7(local_40,local_20);
    local_8._0_1_ = 3;
    FUN_10002c85(local_40,local_14);
    local_8._0_1_ = 4;
    pCVar3 = FUN_10003016(local_28,local_20,L"\t");
    local_8._0_1_ = 5;
    pCVar3 = FUN_10002fa7(local_2c,pCVar3,(CSimpleStringT<wchar_t,1> *)local_14);
    local_8._0_1_ = 6;
    lParam = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                       ((CSimpleStringT<wchar_t,1> *)pCVar3);
    SendMessageW(local_94,0x180,0,(LPARAM)lParam);
    local_8._0_1_ = 5;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_2c);
    local_8 = CONCAT31(local_8._1_3_,4);
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_28);
    iVar4 = ATL::CSimpleStringT<wchar_t,1>::GetLength((CSimpleStringT<wchar_t,1> *)local_14);
    if (local_1c < iVar4) {
      local_1c = ATL::CSimpleStringT<wchar_t,1>::GetLength((CSimpleStringT<wchar_t,1> *)local_14);
    }
    FUN_10001613((int)local_40);
    local_8._0_1_ = 3;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_14);
    local_8._0_1_ = 2;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_20);
    local_18 = local_18 + 1;
    uVar5 = FUN_1000117e(iVar1);
  } while (local_18 <= uVar5);
  SendMessageW(local_94,0x194,(local_1c + 7) * 5,0);
  SendMessageW(local_94,0x186,0,0);
  CWnd::Detach((CWnd *)local_b4);
  local_8 = (uint)local_8._1_3_ << 8;
  CListBox::~CListBox((CListBox *)local_b4);
  local_8 = 0xffffffff;
  FUN_100018b8(local_40);
  return;
}



// Function: FUN_10003f22 at 10003f22

undefined4 __thiscall FUN_10003f22(void *this,int *param_1)

{
  if ((*(int *)((int)this + 0x20) == 0) && (param_1 != (int *)0x0)) {
    FUN_1000131f((int *)((int)this + 0x20),param_1);
  }
  return 0;
}



// Function: FUN_10003f42 at 10003f42

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003f42(undefined4 *param_1)

{
  *param_1 = CComErrorHandlerException::vftable;
  FID_conflict__Tidy(param_1 + 4,'\x01',0);
  return;
}



// Function: FUN_10003f6d at 10003f6d

undefined4 * __thiscall FUN_10003f6d(void *this,byte param_1)

{
  FUN_10003f42((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003f8c at 10003f8c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003f8c(undefined4 *param_1)

{
  FUN_10003cfc((int)param_1);
  param_1[9] = 0xff0000;
  param_1[10] = 0xff0000;
  *param_1 = CStaticLink::vftable;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  return param_1;
}



// Function: FUN_10003fdb at 10003fdb

undefined4 __cdecl
FUN_10003fdb(HWND param_1,uint param_2,WPARAM param_3,LPARAM param_4,LRESULT *param_5)

{
  LRESULT LVar1;
  
  if (param_2 < 0x2112) {
    if ((param_2 == 0x2111) ||
       ((0x202a < param_2 && (((param_2 < 0x2030 || (param_2 == 0x2039)) || (param_2 == 0x204e))))))
    {
LAB_1000402f:
      LVar1 = DefWindowProcW(param_1,param_2 - 0x2000,param_3,param_4);
      *param_5 = LVar1;
      return 1;
    }
  }
  else if ((0x2113 < param_2) &&
          ((param_2 < 0x2116 || ((0x2131 < param_2 && ((param_2 < 0x2139 || (param_2 == 0x2210))))))
          )) goto LAB_1000402f;
  return 0;
}



// Function: FUN_1000404e at 1000404e

void __thiscall
FUN_1000404e(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  *(undefined4 *)((int)this + 0x20) = param_5;
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)((int)this + 8) = param_3;
  *(undefined4 *)((int)this + 0xc) = param_4;
  *(undefined4 *)((int)this + 0x1c) = 0x24;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  return;
}



// Function: FUN_10004086 at 10004086

undefined4 __thiscall FUN_10004086(void *this,uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint dwNewLong;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = GetWindowLongW(*this,-0x10);
  dwNewLong = ~param_1 & uVar1 | param_2;
  if (uVar1 == dwNewLong) {
    uVar2 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    SetWindowLongW(*this,-0x10,dwNewLong);
    if (param_3 != 0) {
                    /* WARNING: Load size is inaccurate */
      SetWindowPos(*this,(HWND)0x0,0,0,0,0,param_3 | 0x17);
    }
    uVar2 = 1;
  }
  return uVar2;
}



// Function: FUN_100040d5 at 100040d5

LRESULT FUN_100040d5(int *param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int *piVar1;
  UINT Msg;
  int iVar2;
  LONG LVar3;
  undefined1 local_2c [36];
  LONG local_8;
  
  Msg = param_2;
  piVar1 = param_1;
  FUN_1000404e(local_2c,param_1[1],param_2,param_3,param_4,1);
  param_2 = piVar1[6];
  param_1 = (int *)0x0;
  piVar1[6] = (int)local_2c;
  iVar2 = (**(code **)*piVar1)(piVar1[1],Msg,param_3,param_4,&param_1,0);
  if (iVar2 == 0) {
    if (Msg == 0x82) {
      local_8 = GetWindowLongW((HWND)piVar1[1],-4);
      param_1 = (int *)CallWindowProcW((WNDPROC)piVar1[8],(HWND)piVar1[1],0x82,param_3,param_4);
      if (((code *)piVar1[8] != DefWindowProcW_exref) &&
         (LVar3 = GetWindowLongW((HWND)piVar1[1],-4), LVar3 == local_8)) {
        SetWindowLongW((HWND)piVar1[1],-4,piVar1[8]);
      }
      piVar1[7] = piVar1[7] | 1;
    }
    else {
      param_1 = (int *)CallWindowProcW((WNDPROC)piVar1[8],(HWND)piVar1[1],Msg,param_3,param_4);
    }
  }
  if (((piVar1[7] & 1U) == 0) || (param_2 != 0)) {
    piVar1[6] = param_2;
  }
  else {
    iVar2 = piVar1[1];
    piVar1[7] = piVar1[7] & 0xfffffffe;
    piVar1[1] = 0;
    piVar1[6] = 0;
    (**(code **)(*piVar1 + 0xc))(iVar2);
  }
  return (LRESULT)param_1;
}



// Function: FUN_100041cb at 100041cb

undefined4 __fastcall FUN_100041cb(int param_1)

{
  HDC hdc;
  
  if (*(int *)(param_1 + 0x34) != 0) {
    hdc = GetDC(*(HWND *)(param_1 + 4));
    SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x34));
    ReleaseDC(*(HWND *)(param_1 + 4),hdc);
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  if (*(HGDIOBJ *)(param_1 + 0x30) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  return 0;
}



// Function: FUN_10004211 at 10004211

void __thiscall FUN_10004211(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  POINT pt;
  BOOL BVar1;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0x3c) == 0) {
    *(undefined4 *)((int)this + 0x3c) = 1;
    RedrawWindow(*(HWND *)((int)this + 4),(RECT *)0x0,(HRGN)0x0,0x105);
    SetCapture(*(HWND *)((int)this + 4));
  }
  else {
    GetClientRect(*(HWND *)((int)this + 4),&local_18);
    pt.y = (int)(short)((uint)param_3 >> 0x10);
    pt.x = (int)(short)param_3;
    BVar1 = PtInRect(&local_18,pt);
    if (BVar1 == 0) {
      *(undefined4 *)((int)this + 0x3c) = 0;
      ReleaseCapture();
      RedrawWindow(*(HWND *)((int)this + 4),(RECT *)0x0,(HRGN)0x0,0x105);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100042a0 at 100042a0

void __thiscall FUN_100042a0(void *this,undefined4 param_1,HDC param_2)

{
  uint uVar1;
  HANDLE h;
  HFONT pHVar2;
  HGDIOBJ pvVar3;
  COLORREF color;
  int c;
  LOGFONTW *pv;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  FUN_10004086((void *)((int)this + 4),0,0x100,0);
  uVar1 = GetWindowLongW(*(HWND *)((int)this + 4),-0x10);
  if ((uVar1 & 0xff) < 3) {
    if (*(int *)((int)this + 0x30) == 0) {
      pv = &local_64;
      c = 0x5c;
      h = (HANDLE)SendMessageW(*(HWND *)((int)this + 4),0x31,0,0);
      GetObjectW(h,c,pv);
      local_64.lfUnderline = '\x01';
      pHVar2 = CreateFontIndirectW(&local_64);
      *(HFONT *)((int)this + 0x30) = pHVar2;
    }
    pvVar3 = SelectObject(param_2,*(HGDIOBJ *)((int)this + 0x30));
    if (*(int *)((int)this + 0x34) == 0) {
      *(HGDIOBJ *)((int)this + 0x34) = pvVar3;
    }
    if (*(int *)((int)this + 0x2c) == 0) {
      color = *(COLORREF *)((int)this + 0x24);
    }
    else {
      color = *(COLORREF *)((int)this + 0x28);
    }
    SetTextColor(param_2,color);
    SetBkMode(param_2,1);
    GetStockObject(5);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004369 at 10004369

undefined * FUN_10004369(void)

{
  return FUN_100040d5;
}



// Function: FUN_1000436f at 1000436f

undefined4 __thiscall
FUN_1000436f(void *this,HWND param_1,uint param_2,HDC param_3,LPARAM param_4,LRESULT *param_5,
            int param_6)

{
  LRESULT LVar1;
  HCURSOR hCursor;
  int iVar2;
  
  if (param_6 != 0) {
    return 0;
  }
  if (param_2 == 0x2111) {
LAB_10004387:
    *param_5 = 0;
  }
  else {
    if (param_2 == 0x2138) {
      LVar1 = FUN_100042a0(this,0x2138,param_3);
    }
    else {
      if (param_2 == 0x20) {
        hCursor = LoadCursorW(DAT_10030d74,(LPCWSTR)0xd6);
        SetCursor(hCursor);
        goto LAB_10004387;
      }
      if (param_2 == 2) {
        LVar1 = FUN_100041cb((int)this);
      }
      else {
        if (param_2 != 0x200) {
          iVar2 = FUN_10003fdb(param_1,param_2,(WPARAM)param_3,param_4,param_5);
          if (iVar2 != 0) {
            return 1;
          }
          return 0;
        }
        LVar1 = FUN_10004211(this,0x200,param_3,param_4);
      }
    }
    *param_5 = LVar1;
  }
  return 1;
}



// Function: FUN_10004429 at 10004429

void * __thiscall FUN_10004429(void *this,byte param_1)

{
  FUN_10003d2a((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10004448 at 10004448

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10004448(void *this,undefined4 *param_1,undefined1 param_2)

{
  FUN_10003590((int)this);
  *(undefined ***)this = CErrorDlg::vftable;
  *(undefined4 *)((int)this + 0x20) = 0;
  FUN_10001878((undefined4 *)((int)this + 0x24));
  FUN_10003f8c((undefined4 *)((int)this + 0x38));
  FUN_10003f8c((undefined4 *)((int)this + 0x78));
  *(undefined1 *)((int)this + 0xb8) = param_2;
  FUN_10001b71((void *)((int)this + 0x24),param_1);
  return (undefined4 *)this;
}



// Function: FUN_100044be at 100044be

int FUN_100044be(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined1 local_28 [36];
  
  uVar3 = param_2;
  piVar2 = param_1;
  FUN_1000404e(local_28,param_1[1],param_2,param_3,param_4,1);
  iVar1 = piVar2[6];
  param_1 = (int *)0x0;
  piVar2[6] = (int)local_28;
  param_4 = (**(code **)*piVar2)(piVar2[1],uVar3,param_3,param_4,&param_1,0);
  piVar2[6] = iVar1;
  if (param_4 == 0) {
    if (uVar3 == 0x82) {
      piVar2[7] = piVar2[7] | 1;
    }
  }
  else if ((uVar3 < 0x2e) ||
          (((((0x2f < uVar3 && (uVar3 != 0x37)) && (uVar3 != 0x39)) && (uVar3 != 0x110)) &&
           ((uVar3 < 0x132 || (0x138 < uVar3)))))) {
    if ((*(byte *)(piVar2 + 7) & 1) == 0) {
      SetWindowLongW((HWND)piVar2[1],0,(LONG)param_1);
    }
  }
  else {
    param_4 = (int)param_1;
  }
  if (((piVar2[7] & 1U) != 0) && (piVar2[6] == 0)) {
    iVar1 = piVar2[1];
    piVar2[7] = piVar2[7] & 0xfffffffe;
    piVar2[1] = 0;
    (**(code **)(*piVar2 + 0xc))(iVar1);
  }
  return param_4;
}



// Function: FUN_1000458f at 1000458f

LRESULT __thiscall
FUN_1000458f(void *this,uint param_1,uint param_2,HWND param_3,undefined4 *param_4)

{
  uint nIDDlgItem;
  HWND pHVar1;
  LRESULT LVar2;
  
  pHVar1 = param_3;
  if (param_1 < 0x4f) {
    if (param_1 == 0x4e) {
      pHVar1 = (HWND)param_3->unused;
    }
    else if (param_1 == 0x2b) {
      if (param_2 == 0) goto LAB_10004640;
      pHVar1 = (HWND)param_3[5].unused;
    }
    else if (param_1 == 0x2c) {
      if (param_2 == 0) goto LAB_10004640;
      nIDDlgItem = param_3[1].unused;
LAB_1000462b:
      pHVar1 = GetDlgItem(*(HWND *)((int)this + 4),nIDDlgItem);
    }
    else if (param_1 == 0x2d) {
      if (param_2 == 0) goto LAB_10004640;
      pHVar1 = (HWND)param_3[3].unused;
    }
    else {
      if (param_1 < 0x2e) goto LAB_10004640;
      if (0x2f < param_1) {
        if ((param_1 != 0x39) || (param_2 == 0)) goto LAB_10004640;
        pHVar1 = (HWND)param_3[2].unused;
      }
    }
  }
  else if (param_1 == 0x111) {
    if (param_3 == (HWND)0x0) goto LAB_10004640;
  }
  else {
    if (param_1 < 0x114) goto LAB_10004640;
    if (0x115 < param_1) {
      if (param_1 < 0x132) goto LAB_10004640;
      if (0x138 < param_1) {
        if (param_1 != 0x210) goto LAB_10004640;
        if (1 < (param_2 & 0xffff) - 1) {
          nIDDlgItem = param_2 >> 0x10;
          goto LAB_1000462b;
        }
      }
    }
  }
  if (pHVar1 != (HWND)0x0) {
    LVar2 = SendMessageW(pHVar1,param_1 + 0x2000,param_2,(LPARAM)param_3);
    return LVar2;
  }
LAB_10004640:
  *param_4 = 0;
  return 1;
}



// Function: FUN_10004662 at 10004662

undefined * FUN_10004662(void)

{
  return FUN_100044be;
}



// Function: FUN_10004668 at 10004668

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004668(int param_1)

{
  int *piVar1;
  
  FUN_10003d2a(param_1 + 0x78);
  FUN_10003d2a(param_1 + 0x38);
  FUN_100018b8((undefined4 *)(param_1 + 0x24));
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10003560(param_1);
  return;
}



// Function: FUN_100046cb at 100046cb

void * __thiscall FUN_100046cb(void *this,byte param_1)

{
  FUN_10004668((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100046ea at 100046ea

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100046ea(void *this,undefined4 *param_1,undefined1 param_2)

{
  FUN_10003590((int)this);
  *(undefined ***)this = CErrorDlg::vftable;
  *(undefined4 *)((int)this + 0x20) = 0;
  FUN_10001878((undefined4 *)((int)this + 0x24));
  FUN_10003f8c((undefined4 *)((int)this + 0x38));
  FUN_10003f8c((undefined4 *)((int)this + 0x78));
  *(undefined1 *)((int)this + 0xb8) = param_2;
  FUN_10001ba4((void *)((int)this + 0x24),param_1);
  return (undefined4 *)this;
}



// Function: FUN_10004760 at 10004760

void __fastcall FUN_10004760(int param_1)

{
  FUN_1000385e(param_1);
  FUN_10003d7e(param_1);
  FUN_100039b2(param_1);
  return;
}



// Function: FUN_10004777 at 10004777

undefined4 __fastcall FUN_10004777(int *param_1)

{
  int *piVar1;
  HWND pHVar2;
  int local_8;
  
  local_8 = param_1[1];
  piVar1 = (int *)(**(code **)(*param_1 + 0x10))();
  FUN_100035c6(&local_8,piVar1);
  pHVar2 = GetDesktopWindow();
  FUN_100031c0(param_1 + 1,pHVar2);
  pHVar2 = GetDlgItem((HWND)param_1[1],0xd7);
  FUN_10003370(param_1 + 0x1e,pHVar2);
  FUN_100034fe(param_1 + 0x2c,0x10020110);
  FUN_100037b8(param_1);
  FUN_10004760((int)param_1);
  return 1;
}



// Function: FUN_100047e8 at 100047e8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100047e8(void *this,int param_1)

{
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  basic_string<>((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  return (undefined4 *)this;
}



// Function: FUN_10004838 at 10004838

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_10004838(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
            undefined4 param_5)

{
  size_t sVar1;
  
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined2 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  sVar1 = wcslen(param_4);
  FID_conflict_assign((void *)((int)this + 0x10),(undefined4 *)param_4,sVar1);
  *(undefined4 *)((int)this + 0x2c) = param_5;
  return (undefined4 *)this;
}



// Function: FUN_1000489f at 1000489f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000489f(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_74 [48];
  undefined1 local_44 [60];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x100048ab;
  FUN_10004838(local_44,param_1,0,param_2,(wchar_t *)&PTR_1001fc90,0);
  local_8 = 0;
  FUN_100047e8(local_74,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_74,(ThrowInfo *)&DAT_10026afc);
}



// Function: FUN_100048e1 at 100048e1

void __thiscall FUN_100048e1(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 < 0)) {
    *(undefined1 *)this = 1;
    FUN_1000489f(param_1,*(undefined4 *)((int)this + 4));
  }
  return;
}



// Function: FUN_10004901 at 10004901

int __thiscall FUN_10004901(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_100048e1((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_1000491d at 1000491d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_1000491d(void *this,int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_2c [4];
  void *local_1c;
  int *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  piVar1 = (int *)((int)this + 4);
  *piVar1 = 0;
  local_8 = 1;
  *(undefined ***)this =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_1c = this;
  local_18 = piVar1;
  FUN_10003c98(local_2c);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_14[0] = 0;
  local_8._0_1_ = 3;
  if (param_2[4] == 0) {
    iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,local_14);
    FUN_10004901(local_2c,iVar2);
  }
  else {
    piVar3 = FUN_1001023a((int *)&param_2,param_2);
    local_8._0_1_ = 4;
    FUN_10001352(local_14,piVar3);
    local_8._0_1_ = 3;
    Ordinal_6(param_2);
  }
  local_18 = (int *)0x0;
  local_8._0_1_ = 6;
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1,&local_18);
  FUN_10004901(local_2c,iVar2);
  iVar2 = (**(code **)(*local_18 + 0x24))(local_18,local_14[0],piVar1);
  FUN_10004901(local_2c,iVar2);
  if (param_3[4] != 0) {
    piVar3 = FUN_1001023a((int *)&param_1,param_3);
    local_8._0_1_ = 7;
    iVar2 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,*piVar3);
    FUN_10004901(local_2c,iVar2);
    local_8._0_1_ = 6;
    Ordinal_6(param_1);
  }
  local_8._0_1_ = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6(local_14[0]);
  return (undefined4 *)this;
}



// Function: FUN_10004a32 at 10004a32

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10004a32(void *this,void *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_2c [4];
  undefined4 local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x10004a3e;
  local_1c = 0;
  FUN_10003c98(local_2c);
  local_18 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  piVar1 = FUN_1001023a((int *)&param_2,param_2);
  local_8._0_1_ = 4;
  iVar2 = (**(code **)(**(int **)((int)this + 4) + 0x30))
                    (*(int **)((int)this + 4),*piVar1,1,&local_18);
  FUN_10004901(local_2c,iVar2);
  local_8._0_1_ = 3;
  Ordinal_6(param_2);
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 6;
  if (local_18 != (int *)0x0) {
    iVar2 = (**(code **)*local_18)(local_18,&DAT_1001ff18,local_14);
    FUN_10004901(local_2c,iVar2);
  }
  FUN_10003c64(param_1,local_14[0]);
  local_1c = 1;
  local_8._0_1_ = 3;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return param_1;
}



// Function: FUN_10004af7 at 10004af7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10004af7(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 local_24 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0;
  local_14 = 0;
  FUN_10003c98(local_24);
  local_8 = 1;
  Ordinal_8(param_1);
  local_14 = 1;
  if (*(int *)((int)this + 4) != 0) {
    iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x28))(*(int **)((int)this + 4),param_1);
    FUN_10004901(local_24,iVar1);
  }
  return param_1;
}



// Function: FUN_10004b51 at 10004b51

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_10004b51(void *param_1)

{
  int iVar1;
  undefined4 local_30 [4];
  undefined1 local_20 [8];
  undefined4 local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10004b5d;
  FUN_10003c98(local_30);
  local_8 = 0;
  FUN_10004af7(param_1,local_20);
  local_8._0_1_ = 1;
  iVar1 = FUN_1000fd88(3,(int)local_20,0,0x409);
  FUN_10004901(local_30,iVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(local_20);
  return local_18;
}



// Function: FUN_10004bb5 at 10004bb5

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10004bb5(int param_1)

{
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *this;
  wchar_t *lpString;
  ulong uVar1;
  undefined4 *puVar2;
  undefined4 local_80 [4];
  undefined4 local_70 [2];
  undefined4 local_68;
  undefined4 local_64;
  LPVOID local_60;
  CComBSTR local_5c [4];
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_58 [4];
  int *local_54;
  undefined2 local_50 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_34 [8];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb8;
  local_8 = 0x10004bc4;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_58);
  local_60 = (LPVOID)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 3;
  CoCreateInstance((IID *)&DAT_1001fe50,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001fef0,&local_60);
  ATL::CComBSTR::CComBSTR(local_5c,(CComBSTR *)&DAT_1002ef10);
  local_8._0_1_ = 4;
  FUN_10001378(local_5c,DAT_1002ef14);
  this = FUN_10002af7((void *)(param_1 + 0x24),
                      (CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                       *)&local_54);
  local_8._0_1_ = 5;
  lpString = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                       ((CSimpleStringT<wchar_t,1> *)this);
  uVar1 = lstrlenW(lpString);
  FUN_10001657(local_5c,lpString,uVar1);
  local_8._0_1_ = 4;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             &local_54);
  local_64 = 0;
  local_68 = 0xffffffff;
  local_54 = (int *)0x0;
  local_8._0_1_ = 9;
  (**(code **)**(undefined4 **)(param_1 + 0x20))
            (*(undefined4 **)(param_1 + 0x20),&DAT_1001ff00,&local_54);
  local_3c = 7;
  local_40 = 0;
  local_50[0] = 0;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  local_8._0_1_ = 0xb;
  FUN_1000491d(local_70,local_54,(undefined4 *)local_34,(undefined4 *)local_50);
  local_8._0_1_ = 0xd;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8._0_1_ = 0xe;
  FID_conflict__Tidy(local_50,'\x01',0);
  puVar2 = (undefined4 *)FUN_10010413(local_50,DAT_1002ef18);
  local_8._0_1_ = 0xf;
  FUN_10004a32(local_70,local_80,puVar2);
  local_8._0_1_ = 0x11;
  FID_conflict__Tidy(local_50,'\x01',0);
  local_68 = FUN_10004b51(local_80);
  local_8._0_1_ = 0xe;
  FUN_10003bde(local_80);
  local_8._0_1_ = 9;
  FUN_10003b96(local_70);
  local_8 = CONCAT31(local_8._1_3_,7);
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54);
  }
  local_8 = 6;
  FUN_10004d5b();
  return;
}



// Function: Catch@10004d48 at 10004d48

undefined * Catch_10004d48(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -100) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  return &DAT_10004d59;
}



// Function: FUN_10004d5b at 10004d5b

void FUN_10004d5b(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  
  (**(code **)(**(int **)(unaff_EBP + -0x5c) + 0xc))
            (*(int **)(unaff_EBP + -0x5c),*(undefined4 *)(unaff_EBP + -100));
  piVar1 = (int *)(**(code **)(**(int **)(unaff_EBP + -0x5c) + 0x18))
                            (*(int **)(unaff_EBP + -0x5c),*(undefined4 *)(unaff_EBP + -0x58));
  if (piVar1 == unaff_EBX) {
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    operator=((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
              (unaff_EBP + -0x54),*(wchar_t **)(unaff_EBP + -0x60));
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x60));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x58));
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar1 = *(int **)(unaff_EBP + -0x5c);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(int **)(unaff_EBP + -4) = unaff_EBX;
  FUN_10004dc6();
  return;
}



// Function: Catch@10004dba at 10004dba

undefined * Catch_10004dba(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10004dc4;
}



// Function: FUN_10004dc6 at 10004dc6

void FUN_10004dc6(void)

{
  int iVar1;
  wchar_t *_Str;
  size_t sVar2;
  LPWSTR lpCommandLine;
  LPCWSTR unaff_EBX;
  int unaff_EBP;
  
  iVar1 = ATL::CSimpleStringT<wchar_t,1>::GetLength
                    ((CSimpleStringT<wchar_t,1> *)(unaff_EBP + -0x54));
  if (0 < iVar1) {
    FUN_10002350((void *)(unaff_EBP + -0x30),L"hh.exe ");
    *(undefined1 *)(unaff_EBP + -4) = 0x16;
    _Str = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                     ((CSimpleStringT<wchar_t,1> *)(unaff_EBP + -0x54));
    sVar2 = wcslen(_Str);
    FUN_10001d33((void *)(unaff_EBP + -0x30),(undefined4 *)_Str,sVar2);
    *(undefined4 *)(unaff_EBP + -0xc0) = 0x44;
    *(LPCWSTR *)(unaff_EBP + -0xbc) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0xb8) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0xb4) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0xb0) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0xac) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0xa8) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0xa4) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0xa0) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x9c) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x98) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x94) = unaff_EBX;
    *(undefined2 *)(unaff_EBP + -0x90) = 0;
    *(undefined2 *)(unaff_EBP + -0x8e) = 0;
    *(LPCWSTR *)(unaff_EBP + -0x8c) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x84) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x88) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x80) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x6c) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x68) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x74) = unaff_EBX;
    *(LPCWSTR *)(unaff_EBP + -0x70) = unaff_EBX;
    lpCommandLine = *(LPWSTR *)(unaff_EBP + -0x30);
    if (*(uint *)(unaff_EBP + -0x1c) < 8) {
      lpCommandLine = (LPWSTR)(unaff_EBP + -0x30);
    }
    CreateProcessW(unaff_EBX,lpCommandLine,(LPSECURITY_ATTRIBUTES)unaff_EBX,
                   (LPSECURITY_ATTRIBUTES)unaff_EBX,(BOOL)unaff_EBX,0x20,unaff_EBX,unaff_EBX,
                   (LPSTARTUPINFOW)(unaff_EBP + -0xc0),(LPPROCESS_INFORMATION)(unaff_EBP + -0x74));
    *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x30),'\x01',(int)unaff_EBX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x54));
  FUN_100173d0();
  return;
}



// Function: FUN_10004ecd at 10004ecd

undefined4 __fastcall FUN_10004ecd(int param_1)

{
  FUN_10004bb5(param_1);
  return 0;
}



// Function: FUN_10004ee6 at 10004ee6

undefined4 __thiscall
FUN_10004ee6(void *this,undefined4 param_1,uint param_2,uint param_3,HWND param_4,LRESULT *param_5,
            int param_6)

{
  uint uVar1;
  short sVar2;
  LRESULT LVar3;
  ushort uVar4;
  
  uVar1 = param_3;
  if (param_6 != 0) {
    return 0;
  }
  if (param_2 == 0x110) {
    LVar3 = FUN_10004777((int *)this);
LAB_10004f0f:
    *param_5 = LVar3;
    return 1;
  }
  if (param_2 == 0x53) {
    LVar3 = FUN_10004bb5((int)this);
    goto LAB_10004f0f;
  }
  if (param_2 != 0x111) {
LAB_10004fdc:
    param_3 = 1;
    LVar3 = FUN_1000458f(this,param_2,uVar1,param_4,&param_3);
    *param_5 = LVar3;
    if (param_3 == 0) {
      return 0;
    }
    return 1;
  }
  sVar2 = (short)param_3;
  if (sVar2 == 1) {
    uVar4 = 1;
  }
  else {
    if (sVar2 != 2) {
      if (sVar2 == 0xd7) {
        LVar3 = FUN_10003d59(this);
      }
      else if (sVar2 == 9) {
        LVar3 = FUN_10004ecd((int)this);
      }
      else {
        if ((sVar2 != 0xd9) || ((short)(param_3 >> 0x10) != 1)) goto LAB_10004fdc;
        LVar3 = FUN_10003d74((int)this);
      }
      goto LAB_10004f5e;
    }
    uVar4 = 2;
  }
  LVar3 = FUN_100033b0(this,param_3 >> 0x10,uVar4);
LAB_10004f5e:
  *param_5 = LVar3;
  return 1;
}



// Function: FUN_10005006 at 10005006

int * __thiscall FUN_10005006(void *this,int param_1)

{
  int iVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  iVar1 = Ordinal_2(param_1);
  *(int *)this = iVar1;
  if ((iVar1 == 0) && (param_1 != 0)) {
    FUN_10018360(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_1000503c at 1000503c

void __fastcall FUN_1000503c(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  return;
}



// Function: FUN_1000505c at 1000505c

undefined2 * __thiscall FUN_1000505c(void *this,int param_1)

{
  int iVar1;
  
  *(undefined2 *)this = 8;
  iVar1 = Ordinal_2(param_1);
  *(int *)((int)this + 8) = iVar1;
  if ((iVar1 == 0) && (param_1 != 0)) {
    FUN_10018360(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_1000508e at 1000508e

void * __thiscall FUN_1000508e(void *this,undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_10(this,param_1);
  if (iVar1 < 0) {
    FUN_10018360(iVar1);
  }
  return this;
}



// Function: FUN_100050af at 100050af

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100050af(void *this,void *param_1)

{
  int iVar1;
  undefined1 local_24 [16];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x100050bb;
  local_14 = 0;
  Ordinal_8(local_24);
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x34))(this,local_24);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_100201c4);
  }
  memcpy_s(param_1,0x10,local_24,0x10);
  return param_1;
}



// Function: FUN_10005114 at 10005114

undefined4 __fastcall FUN_10005114(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[0xb].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_100201d4);
  }
  return 0;
}



// Function: FUN_10005142 at 10005142

ULONG __fastcall FUN_10005142(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[0xc].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_100201e4);
  }
  return UVar1;
}



// Function: FUN_10005166 at 10005166

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005166(undefined4 *param_1)

{
  *param_1 = CFaultsHelpDBReader::vftable;
  FUN_1000783a(param_1);
  return;
}



// Function: FUN_1000518a at 1000518a

void __fastcall FUN_1000518a(int *param_1)

{
  if (*param_1 == 0) {
    FUN_10018360(0x80004003);
  }
  return;
}



// Function: FUN_1000519b at 1000519b

void __fastcall FUN_1000519b(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)FUN_10018360(0x80004003);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  *param_1 = 0;
  return;
}



// Function: FUN_100051b9 at 100051b9

bool __cdecl FUN_100051b9(int param_1,int *param_2)

{
  if (param_1 != 0) {
    FUN_10018360(0x80004003);
  }
  return *param_2 == 0;
}



// Function: FUN_100051d7 at 100051d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100051d7(void *this,int param_1)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_10005006(this_00,param_1);
  }
  *(int **)this = piVar1;
  if (piVar1 == (int *)0x0) {
    FUN_10018360(0x8007000e);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005224 at 10005224

undefined1 __fastcall FUN_10005224(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if (*(IUnknown **)(param_1 + 4) != (IUnknown *)0x0) {
    iVar1 = FUN_10005114(*(IUnknown **)(param_1 + 4));
    if (iVar1 == 1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



// Function: FUN_1000523e at 1000523e

undefined4 * __thiscall FUN_1000523e(void *this,byte param_1)

{
  FUN_10005166((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000525d at 1000525d

int __thiscall FUN_1000525d(void *this,uint param_1)

{
  uint extraout_EAX;
  undefined4 *extraout_ECX;
  
  if (*(uint *)((int)this + 0x10) <= param_1) {
    std::_Xout_of_range("invalid string position");
    param_1 = extraout_EAX;
    this = extraout_ECX;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  return (int)this + param_1 * 2;
}



// Function: FUN_10005282 at 10005282

uint __thiscall FUN_10005282(void *this,ushort *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  
  if (param_3 == 0) {
    if (*(uint *)((int)this + 0x10) <= param_2) {
      param_2 = *(uint *)((int)this + 0x10);
    }
  }
  else {
    if (param_3 <= *(uint *)((int)this + 0x10)) {
      uVar2 = *(uint *)((int)this + 0x10) - param_3;
      if (uVar2 <= param_2) {
        param_2 = uVar2;
      }
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      puVar6 = (ushort *)((int)pvVar3 + param_2 * 2);
      uVar1 = *param_1;
      while( true ) {
        if ((*puVar6 == uVar1) && (iVar4 = FUN_1000113a(puVar6,param_1,param_3), iVar4 == 0)) {
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)puVar6 - (int)this >> 1;
        }
        puVar5 = (ushort *)this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          puVar5 = *this;
        }
        if (puVar6 == puVar5) break;
        puVar6 = puVar6 + -1;
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_1000530e at 1000530e

LONG __fastcall FUN_1000530e(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    FUN_1000503c(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



// Function: FUN_10005339 at 10005339

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10005339(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *in_stack_00000008;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10005345;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x28))
                    (this,*in_stack_00000008,in_stack_00000008[1],in_stack_00000008[2],
                     in_stack_00000008[3],local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10020228);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_10005390 at 10005390

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10005390(void *this,ulong *param_1)

{
  int iVar1;
  ulong local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x1000539c;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x54))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_100201e4);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_100053db at 100053db

int * __thiscall FUN_100053db(void *this,int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    FUN_10018360(0x80004003);
  }
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if ((piVar1 != (int *)0x0) && (*(undefined4 *)this = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1000540b at 1000540b

HRESULT __thiscall FUN_1000540b(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((uint)param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10020208,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10020238,&param_3);
    if (HVar2 < 0) goto LAB_10005487;
    HVar2 = OleRun(param_3);
    if (-1 < HVar2) {
      HVar2 = (*param_3->lpVtbl->QueryInterface)(param_3,(IID *)&DAT_10020208,(void **)this);
    }
    (*param_3->lpVtbl->Release)(param_3);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_10005487:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_10005492 at 10005492

HRESULT __thiscall FUN_10005492(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((uint)param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10020218,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10020238,&param_3);
    if (HVar2 < 0) goto LAB_1000550e;
    HVar2 = OleRun(param_3);
    if (-1 < HVar2) {
      HVar2 = (*param_3->lpVtbl->QueryInterface)(param_3,(IID *)&DAT_10020218,(void **)this);
    }
    (*param_3->lpVtbl->Release)(param_3);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_1000550e:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_10005519 at 10005519

int * __thiscall FUN_10005519(void *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != *(int *)param_1) {
    Ordinal_6(*this);
    pwVar1 = ATL::CComBSTR::Copy(param_1);
    *(wchar_t **)this = pwVar1;
    if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
      FUN_1000121b(-0x7ff8fff2);
    }
  }
  return (int *)this;
}



// Function: FUN_10005554 at 10005554

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_10005554(int param_1)

{
  int *this;
  char cVar1;
  int *piVar2;
  undefined4 local_18;
  
  local_18 = 0;
  this = (int *)(param_1 + 4);
  if (*this != 0) {
    cVar1 = FUN_10005224(param_1);
    if (cVar1 != '\0') {
      piVar2 = (int *)FUN_1000518a(this);
      local_18 = (**(code **)(*piVar2 + 0x3c))(piVar2);
      FUN_1000519b(this);
      FUN_100053db(this,0);
    }
  }
  return local_18;
}



// Function: Catch@100055ae at 100055ae

undefined4 Catch_100055ae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100055a5;
}



// Function: FUN_100055b8 at 100055b8

void __fastcall FUN_100055b8(undefined4 *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    FUN_1000530e((int *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_100055cb at 100055cb

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_100055cb(int *param_1)

{
  bool bVar1;
  char cVar2;
  HRESULT HVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_28 [3];
  undefined4 local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x100055d7;
  FUN_10003c98(local_28);
  local_1c = 0;
  local_8 = 1;
  piVar4 = param_1 + 1;
  bVar1 = FUN_100051b9(0,piVar4);
  if (bVar1) {
    HVar3 = FUN_1000540b(piVar4,(IID *)&DAT_10020248,(LPUNKNOWN)0x0,(LPUNKNOWN)0x17);
    if (HVar3 < 0) {
      FUN_10004901(local_28,-0x7ffff8fa);
    }
  }
  cVar2 = FUN_10005224((int)param_1);
  if (cVar2 == '\0') {
    piVar4 = (int *)FUN_1000518a(piVar4);
    piVar5 = FUN_100051d7(local_18,*param_1);
    local_8._0_1_ = 2;
    if (DAT_1002f228 == (undefined4 *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = *DAT_1002f228;
    }
    if (DAT_1002f224 == (undefined4 *)0x0) {
      uVar9 = 0;
    }
    else {
      uVar9 = *DAT_1002f224;
    }
    if (*piVar5 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(undefined4 *)*piVar5;
    }
    iVar7 = (**(code **)(*piVar4 + 0x50))(piVar4,uVar6,uVar9,uVar8,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18[0] != (int *)0x0) {
      FUN_1000530e(local_18[0]);
      local_18[0] = (int *)0x0;
    }
    if (iVar7 < 0) {
      FUN_10004901(local_28,-0x7ffff8ff);
    }
  }
  return local_1c;
}



// Function: Catch@100056ac at 100056ac

undefined4 Catch_100056ac(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000569f;
}



// Function: FUN_100056b6 at 100056b6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100056b6(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  short *psVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 local_48 [3];
  undefined4 local_3c;
  void *local_38;
  undefined1 *local_34;
  undefined2 local_30 [20];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0;
  local_34 = &stack0xffffffa0;
  pvVar4 = this;
  uVar5 = param_2;
  local_38 = this;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffa0,(CComBSTR *)&param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_1000919f(this,pvVar4,uVar5);
  local_8._0_1_ = 2;
  *(undefined ***)this = CFaultsHelpDBReader::vftable;
  *(undefined4 *)((int)this + 0x30) = param_3;
  FUN_10003c98(local_48);
  local_8._0_1_ = 3;
  local_3c = 0;
  puVar1 = (undefined4 *)
           FUN_1000260e(local_30,(LPCWSTR)&DAT_1002f144,(undefined4 *)&DAT_1002f17c,-0x7ffffffe);
  local_8._0_1_ = 4;
  FUN_10002382((void *)((int)this + 4),puVar1);
  local_8 = CONCAT31(local_8._1_3_,3);
  FID_conflict__Tidy(local_30,'\x01',0);
  if (*(int *)((int)this + 0x14) == 0) {
    FUN_10004901(local_48,-0x7ffff8fc);
  }
  psVar2 = (short *)FUN_1000525d((void *)((int)this + 4),*(int *)((int)this + 0x14) - 1);
  if (*psVar2 != 0x5c) {
    sVar3 = wcslen(L"\\");
    FUN_10001d33((void *)((int)this + 4),(undefined4 *)&DAT_10020258,sVar3);
  }
  local_8 = 0xffffffff;
  Ordinal_6();
  FUN_100173c1();
  return;
}



// Function: FUN_10005796 at 10005796

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10005796(void *this,int param_1,wchar_t *param_2,undefined2 *param_3)

{
  int iVar1;
  HRESULT HVar2;
  IUnknown *This;
  ULONG UVar3;
  undefined4 *puVar4;
  int *piVar5;
  void *pvVar6;
  int **ppiVar7;
  undefined1 *puVar8;
  undefined1 local_7c [16];
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  void *local_5c;
  int *local_58;
  undefined4 local_54 [3];
  undefined4 local_48;
  int *local_44;
  undefined2 *local_40;
  int local_3c;
  IUnknown *local_38;
  undefined2 local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_40 = param_3;
  local_8 = 1;
  local_5c = this;
  FUN_10003c98(local_54);
  local_48 = 0;
  local_38 = (IUnknown *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  iVar1 = FUN_100055cb((int *)this);
  FUN_10004901(local_54,iVar1);
  HVar2 = FUN_10005492(&local_38,(IID *)&DAT_1002025c,(LPUNKNOWN)0x0,(LPUNKNOWN)0x17);
  if (HVar2 < 0) {
    FUN_10004901(local_54,-0x7ffff8fa);
  }
  This = local_38;
  if (local_38 != (IUnknown *)0x0) goto LAB_10005812;
  while( true ) {
    do {
      do {
        do {
          This = (IUnknown *)FUN_10018360(0x80004003);
LAB_10005812:
          (*This->lpVtbl[3].AddRef)(This);
          local_6c = DAT_1002ede0;
          uStack_68 = DAT_1002ede4;
          uStack_64 = DAT_1002ede8;
          uStack_60 = DAT_1002edec;
          FUN_1000505c(local_7c,param_1);
          local_8._0_1_ = 5;
        } while (local_38 == (IUnknown *)0x0);
        UVar3 = (*local_38->lpVtbl[0xd].AddRef)(local_38);
        local_8._0_1_ = 4;
        Ordinal_9(local_7c);
        if ((int)UVar3 < 0) {
          FUN_10004901(local_54,-0x7ffff8fb);
        }
      } while (local_38 == (IUnknown *)0x0);
      (*local_38->lpVtbl[3].AddRef)(local_38);
      local_3c = 0;
    } while (local_38 == (IUnknown *)0x0);
    UVar3 = (*local_38->lpVtbl[8].Release)(local_38);
    if (((int)UVar3 < 0) || (local_3c < 1)) break;
    if (local_38 != (IUnknown *)0x0) {
      UVar3 = FUN_10005142(local_38);
      FUN_10004901(local_54,UVar3);
      puVar4 = (undefined4 *)FUN_10010413(local_34,param_2);
      local_8._0_1_ = 6;
      if (7 < (uint)puVar4[5]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_1000505c(&local_6c,(int)puVar4);
      local_8._0_1_ = 7;
      if (local_38 != (IUnknown *)0x0) {
        piVar5 = (int *)FUN_10005390(local_38,(ulong *)&local_44);
        local_8._0_1_ = 8;
        ppiVar7 = &local_58;
        pvVar6 = (void *)FUN_1000518a(piVar5);
        piVar5 = (int *)FUN_10005339(pvVar6,ppiVar7);
        local_8._0_1_ = 9;
        puVar8 = local_7c;
        pvVar6 = (void *)FUN_1000518a(piVar5);
        pvVar6 = FUN_100050af(pvVar6,puVar8);
        local_8._0_1_ = 10;
        FUN_1000508e(local_40,pvVar6);
        local_8._0_1_ = 9;
        Ordinal_9(local_7c);
        local_8._0_1_ = 8;
        if (local_58 != (int *)0x0) {
          (**(code **)(*local_58 + 8))(local_58);
        }
        local_8._0_1_ = 7;
        if (local_44 != (int *)0x0) {
          (**(code **)(*local_44 + 8))(local_44);
        }
        local_8._0_1_ = 6;
        Ordinal_9(&local_6c);
        local_8._0_1_ = 4;
        FID_conflict__Tidy(local_34,'\x01',0);
LAB_100059a3:
        iVar1 = FUN_10005554((int)local_5c);
        FUN_10004901(local_54,iVar1);
        local_8 = 3;
        FUN_100059cc();
        return;
      }
    }
  }
  *local_40 = 1;
  goto LAB_100059a3;
}



// Function: Catch@100059bd at 100059bd

undefined * Catch_100059bd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 3;
  return &DAT_100059ca;
}



// Function: FUN_100059cc at 100059cc

void FUN_100059cc(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  
  if (*(int **)(unaff_EBP + -0x34) != unaff_EBX) {
    FUN_1000519b((int *)(unaff_EBP + -0x34));
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  piVar1 = *(int **)(unaff_EBP + -0x34);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
  FUN_100173d0();
  return;
}



// Function: FUN_10005a0c at 10005a0c

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10005a0c(void *this,void *param_1)

{
  char cVar1;
  int iVar2;
  wchar_t *pwVar3;
  wchar_t *extraout_ECX;
  wchar_t *extraout_ECX_00;
  wchar_t *extraout_ECX_01;
  wchar_t *extraout_ECX_02;
  undefined *puVar4;
  short *psVar5;
  undefined4 local_244 [4];
  short local_234 [4];
  int local_22c;
  undefined1 *local_224;
  undefined1 *local_220;
  int local_21c;
  wchar_t local_218 [264];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x238;
  local_8 = 0x10005a1b;
  FUN_10003c98(local_244);
  local_8 = 1;
  cVar1 = FUN_10005224(0x1002f570);
  if (cVar1 == '\0') {
                    /* WARNING: Load size is inaccurate */
    iVar2 = (**(code **)(*this + 0xc))();
    if (iVar2 < 0) {
      FUN_10004901(local_244,iVar2);
    }
  }
  pwVar3 = DAT_1002efa0;
  if (DAT_1002efb4 < 8) {
    pwVar3 = (wchar_t *)&DAT_1002efa0;
  }
  _swprintf(local_218,pwVar3);
  local_21c = Ordinal_2();
  if (local_21c == 0) {
    FUN_1000121b(-0x7ff8fff2);
  }
  local_8._0_1_ = 2;
  Ordinal_8();
  local_8._0_1_ = 3;
  local_234[0] = 1;
  psVar5 = local_234;
  local_224 = &stack0xfffffd98;
  puVar4 = &DAT_1002f080;
  pwVar3 = extraout_ECX;
  FUN_1001023a((int *)&stack0xfffffd98,(undefined4 *)&DAT_1002f080);
  local_8._0_1_ = 4;
  local_220 = &stack0xfffffd94;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd94,(CComBSTR *)&local_21c);
  local_8._0_1_ = 3;
  iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar3,psVar5);
  FUN_10004901(local_244,iVar2);
  if (local_234[0] == 1) {
    pwVar3 = DAT_1002f010;
    if (DAT_1002f024 < 8) {
      pwVar3 = (wchar_t *)&DAT_1002f010;
    }
    _swprintf(local_218,pwVar3);
    FUN_100034fe(&local_21c,(int)local_218);
    psVar5 = local_234;
    local_220 = &stack0xfffffd98;
    puVar4 = &DAT_1002f080;
    pwVar3 = extraout_ECX_00;
    FUN_1001023a((int *)&stack0xfffffd98,(undefined4 *)&DAT_1002f080);
    local_8._0_1_ = 6;
    local_224 = &stack0xfffffd94;
    ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd94,(CComBSTR *)&local_21c);
    local_8._0_1_ = 3;
    iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar3,psVar5);
    FUN_10004901(local_244,iVar2);
    if (local_234[0] == 1) {
      pwVar3 = DAT_1002f02c;
      if (DAT_1002f040 < 8) {
        pwVar3 = (wchar_t *)&DAT_1002f02c;
      }
      _swprintf(local_218,pwVar3);
      *(undefined4 *)((int)this + 0x30) = 2;
      FUN_100034fe(&local_21c,(int)local_218);
      psVar5 = local_234;
      local_220 = &stack0xfffffd98;
      puVar4 = &DAT_1002f080;
      pwVar3 = extraout_ECX_01;
      FUN_1001023a((int *)&stack0xfffffd98,(undefined4 *)&DAT_1002f080);
      local_8._0_1_ = 8;
      local_224 = &stack0xfffffd94;
      ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd94,(CComBSTR *)&local_21c);
      local_8._0_1_ = 3;
      iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar3,psVar5);
      FUN_10004901(local_244,iVar2);
      if (local_234[0] == 1) {
        pwVar3 = DAT_1002f048;
        if (DAT_1002f05c < 8) {
          pwVar3 = (wchar_t *)&DAT_1002f048;
        }
        _swprintf(local_218,pwVar3);
        FUN_100034fe(&local_21c,(int)local_218);
        psVar5 = local_234;
        local_220 = &stack0xfffffd98;
        puVar4 = &DAT_1002f080;
        pwVar3 = extraout_ECX_02;
        FUN_1001023a((int *)&stack0xfffffd98,(undefined4 *)&DAT_1002f080);
        local_8._0_1_ = 10;
        local_224 = &stack0xfffffd94;
        ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd94,(CComBSTR *)&local_21c);
        local_8._0_1_ = 3;
        iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar3,psVar5);
        FUN_10004901(local_244,iVar2);
        if (local_234[0] == 1) {
          FUN_10004901(local_244,-0x7ffff8fd);
        }
      }
    }
  }
  if (local_234[0] == 8) {
    FUN_100034fe(param_1,local_22c);
  }
  else {
    FUN_10004901(local_244,-0x7ffff8f9);
  }
  local_8._0_1_ = 2;
  Ordinal_9();
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6();
  local_8 = 0xffffffff;
  FUN_100173d0();
  return;
}



// Function: Catch@10005d59 at 10005d59

undefined4 Catch_10005d59(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10005d47;
}



// Function: FUN_10005d63 at 10005d63

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10005d63(void *this,void *param_1)

{
  char cVar1;
  int iVar2;
  wchar_t *pwVar3;
  uint uVar4;
  wchar_t *extraout_ECX;
  wchar_t *extraout_ECX_00;
  wchar_t *extraout_ECX_01;
  wchar_t *extraout_ECX_02;
  undefined *puVar5;
  short *psVar6;
  undefined4 local_248 [4];
  short local_238 [4];
  int local_230;
  undefined1 *local_228;
  undefined1 *local_224;
  int local_220;
  void *local_21c;
  wchar_t local_218 [264];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_8 = 0x10005d72;
  local_21c = this;
  FUN_10003c98(local_248);
  local_8 = 1;
  cVar1 = FUN_10005224(0x1002f570);
  if (cVar1 == '\0') {
                    /* WARNING: Load size is inaccurate */
    iVar2 = (**(code **)(*this + 0xc))();
    if (iVar2 < 0) {
      FUN_10004901(local_248,iVar2);
    }
  }
  pwVar3 = DAT_1002efa0;
  if (DAT_1002efb4 < 8) {
    pwVar3 = (wchar_t *)&DAT_1002efa0;
  }
  _swprintf(local_218,pwVar3);
  local_220 = Ordinal_2();
  if (local_220 == 0) {
    FUN_1000121b(-0x7ff8fff2);
  }
  local_8._0_1_ = 2;
  Ordinal_8();
  local_8._0_1_ = 3;
  local_238[0] = 1;
  psVar6 = local_238;
  local_224 = &stack0xfffffd94;
  puVar5 = &DAT_1002f0b8;
  pwVar3 = extraout_ECX;
  FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f0b8);
  local_8._0_1_ = 4;
  local_228 = &stack0xfffffd90;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_220);
  local_8._0_1_ = 3;
  iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar5,pwVar3,psVar6);
  FUN_10004901(local_248,iVar2);
  if (local_238[0] == 1) {
    pwVar3 = DAT_1002f010;
    if (DAT_1002f024 < 8) {
      pwVar3 = (wchar_t *)&DAT_1002f010;
    }
    _swprintf(local_218,pwVar3);
    FUN_100034fe(&local_220,(int)local_218);
    psVar6 = local_238;
    local_228 = &stack0xfffffd94;
    puVar5 = &DAT_1002f0b8;
    pwVar3 = extraout_ECX_00;
    FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f0b8);
    local_8._0_1_ = 6;
    local_224 = &stack0xfffffd90;
    ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_220);
    local_8._0_1_ = 3;
    iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar5,pwVar3,psVar6);
    FUN_10004901(local_248,iVar2);
    if (local_238[0] == 1) {
      pwVar3 = DAT_1002f02c;
      if (DAT_1002f040 < 8) {
        pwVar3 = (wchar_t *)&DAT_1002f02c;
      }
      _swprintf(local_218,pwVar3);
      FUN_100034fe(&local_220,(int)local_218);
      psVar6 = local_238;
      local_228 = &stack0xfffffd94;
      puVar5 = &DAT_1002f0b8;
      pwVar3 = extraout_ECX_01;
      FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f0b8);
      local_8._0_1_ = 8;
      local_224 = &stack0xfffffd90;
      ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_220);
      local_8._0_1_ = 3;
      iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar5,pwVar3,psVar6);
      FUN_10004901(local_248,iVar2);
      if (local_238[0] == 1) {
        pwVar3 = DAT_1002f048;
        if (DAT_1002f05c < 8) {
          pwVar3 = (wchar_t *)&DAT_1002f048;
        }
        _swprintf(local_218,pwVar3);
        FUN_100034fe(&local_220,(int)local_218);
        psVar6 = local_238;
        local_228 = &stack0xfffffd94;
        puVar5 = &DAT_1002f0b8;
        pwVar3 = extraout_ECX_02;
        FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f0b8);
        local_8._0_1_ = 10;
        local_224 = &stack0xfffffd90;
        ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_220);
        local_8._0_1_ = 3;
        iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar5,pwVar3,psVar6);
        FUN_10004901(local_248,iVar2);
        if (local_238[0] == 1) {
          FUN_10004901(local_248,-0x7ffff8fd);
        }
      }
    }
  }
  if (local_238[0] == 3) {
    FUN_100101c3((int *)&local_21c,local_230);
    local_8._0_1_ = 0xc;
    uVar4 = Ordinal_7();
    if (uVar4 < 2) {
      ATL::CComBSTR::CComBSTR((CComBSTR *)&local_224,(CComBSTR *)&local_21c);
      local_8._0_1_ = 0xd;
      FUN_100034fe(&local_21c,0x1002026c);
      FUN_10001378(&local_21c,local_224);
      local_8._0_1_ = 0xc;
      Ordinal_6();
    }
    FUN_10005519(param_1,(CComBSTR *)&local_21c);
    local_8._0_1_ = 3;
    Ordinal_6();
  }
  else {
    FUN_10004901(local_248,-0x7ffff8f9);
  }
  local_8._0_1_ = 2;
  Ordinal_9();
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6();
  local_8 = 0xffffffff;
  FUN_100173d0();
  return;
}



// Function: Catch@10006136 at 10006136

undefined4 Catch_10006136(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10006124;
}



// Function: FUN_10006140 at 10006140

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10006140(void *this,wchar_t *param_1,void *param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  LPCWSTR pWVar5;
  CComBSTR *pCVar6;
  undefined4 local_74 [3];
  undefined4 local_68;
  void *local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50 [7];
  undefined2 local_34 [22];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0;
  local_64 = this;
  FUN_10003c98(local_74);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_68 = 0;
  local_8._0_1_ = 2;
  if (*(int *)((int)this + 0x30) == 2) {
    FUN_100034fe(param_2,0x1001fc90);
  }
  else {
    FUN_10010413(local_34,param_1);
    local_8._0_1_ = 3;
    local_5c = 0x2d;
    uVar1 = FUN_10005282(local_34,(ushort *)&local_5c,0xffffffff,1);
    FUN_1000226d(local_34,local_50,DAT_1002f218 + 1 + uVar1,0xffffffff);
    local_58 = 0;
    local_8._0_1_ = 5;
    piVar2 = FUN_1001023a(&local_5c,local_50);
    local_8._0_1_ = 6;
    FUN_10001352(&local_58,piVar2);
    local_8._0_1_ = 5;
    Ordinal_6(local_5c);
    puVar3 = DAT_1002f198;
    if (DAT_1002f1ac < 8) {
      puVar3 = &DAT_1002f198;
    }
    FUN_100034fe(param_2,(int)puVar3);
    local_60 = 0;
    local_8._0_1_ = 7;
    iVar4 = FUN_10005d63(local_64,&local_60);
    FUN_10004901(local_74,iVar4);
    iVar4 = FUN_10001378(param_2,local_60);
    if (-1 < iVar4) goto LAB_1000624c;
    do {
      while( true ) {
        do {
          FUN_1000121b(iVar4);
LAB_1000624c:
          pWVar5 = DAT_1002f1ec;
          if (DAT_1002f200 < 8) {
            pWVar5 = (LPCWSTR)&DAT_1002f1ec;
          }
          FUN_10001972(param_2,pWVar5);
          iVar4 = FUN_10001378(param_2,local_58);
        } while (iVar4 < 0);
        FUN_10001972(param_2,L".htm#");
        local_54 = Ordinal_2(&PTR_1001fc90);
        if (local_54 != 0) break;
        iVar4 = -0x7ff8fff2;
      }
      local_8._0_1_ = 8;
      if ((*(int *)((int)local_64 + 0x30) == 0) || (*(int *)((int)local_64 + 0x30) != 1)) {
        pCVar6 = (CComBSTR *)&DAT_1002ef60;
      }
      else {
        pCVar6 = (CComBSTR *)&DAT_1002ef64;
      }
      FUN_10005519(&local_54,pCVar6);
      iVar4 = FUN_10001378(param_2,local_54);
    } while (iVar4 < 0);
    local_8._0_1_ = 7;
    Ordinal_6(local_54);
    local_8._0_1_ = 5;
    Ordinal_6(local_60);
    local_8._0_1_ = 4;
    Ordinal_6(local_58);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_50,'\x01',0);
    local_8 = CONCAT31(local_8._1_3_,2);
    FID_conflict__Tidy(local_34,'\x01',0);
  }
  local_8 = 1;
  FUN_10006326();
  return;
}



// Function: Catch@10006313 at 10006313

undefined * Catch_10006313(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10006320;
}



// Function: FUN_10006326 at 10006326

void FUN_10006326(void)

{
  int unaff_EBP;
  code *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (*unaff_ESI)(*(undefined4 *)(unaff_EBP + 8));
  FUN_100173d0();
  return;
}



// Function: AtlCoTaskMemCAlloc at 1000633a

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



// Function: FUN_10006367 at 10006367

LPVOID __cdecl FUN_10006367(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10006397 at 10006397

bool __cdecl FUN_10006397(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100063c4 at 100063c4

undefined4 __thiscall FUN_100063c4(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return 0;
}



// Function: Init at 100063d3

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



// Function: FUN_100063fc at 100063fc

void __fastcall FUN_100063fc(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_1000640e at 1000640e

DWORD FUN_1000640e(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10006423 at 10006423

uint __cdecl FUN_10006423(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10006439 at 10006439

void __fastcall FUN_10006439(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_1000644e at 1000644e

undefined4 __fastcall FUN_1000644e(undefined4 *param_1)

{
  int iVar1;
  DWORD cchLength;
  
  iVar1 = Ordinal_7(*param_1);
  if (iVar1 != 0) {
    cchLength = Ordinal_7(*param_1);
    CharLowerBuffW((LPWSTR)*param_1,cchLength);
  }
  return 0;
}



// Function: FUN_10006472 at 10006472

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10006472(undefined4 *param_1)

{
  FUN_10009c27((int)param_1);
  *param_1 = ATL::CComObject<class_CHelpDBReaderImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CHelpDBReaderImpl>::vftable;
  (**(code **)(*DAT_1002f230 + 4))();
  return param_1;
}



// Function: _InlineIsEqualGUID at 100064b2

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



// Function: FUN_100064e2 at 100064e2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100064e2(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CHelpDBReaderImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CHelpDBReaderImpl>::vftable;
  param_1[2] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_10009c05((int)param_1);
  return;
}



// Function: FUN_10006527 at 10006527

undefined4 * __thiscall FUN_10006527(void *this,byte param_1)

{
  FUN_100064e2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006546 at 10006546

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006546(int param_1)

{
  FUN_10009c05(param_1);
  return;
}



// Function: FUN_10006564 at 10006564

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10006564(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10006592 at 10006592

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006592(void *this,undefined4 param_1)

{
  FUN_10009c27((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CHelpDBReaderImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CHelpDBReaderImpl>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FID_conflict:RegCreateKeyExW at 100065cd

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
                    /* WARNING: Could not recover jumptable at 0x10006622. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 10006630

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
                    /* WARNING: Could not recover jumptable at 0x10006673. Too many branches */
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



// Function: InlineIsEqualUnknown at 10006682

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



// Function: FUN_100066b0 at 100066b0

void __cdecl FUN_100066b0(short *param_1,int param_2,short *param_3)

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



// Function: DeleteSubKey at 100066fe

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_1002f238 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_1002f234 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_1002f238 = '\x01';
    }
    if (DAT_1002f234 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_1002f234)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Create at 1000676e

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



// Function: SetStringValue at 100067d6

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



// Function: FUN_1000680d at 1000680d

LSTATUS __thiscall FUN_1000680d(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10006850 at 10006850

undefined4 __fastcall FUN_10006850(undefined4 *param_1)

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



// Function: FUN_10006870 at 10006870

undefined4 * __thiscall FUN_10006870(void *this,ulong param_1)

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



// Function: FUN_100068a6 at 100068a6

void __fastcall FUN_100068a6(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100068b0 at 100068b0

undefined4 __thiscall FUN_100068b0(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10006367(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10001235((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_1000693e at 1000693e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000693e(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x1000694a;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_1002f25c & 1) == 0) {
    DAT_1002f25c = DAT_1002f25c | 1;
    DAT_1002f240 = 8;
    _DAT_1002f248 = 0x4008;
    _DAT_1002f250 = 0x13;
    DAT_1002f23c = &DAT_10020bac;
    DAT_1002f244 = &DAT_10020ba8;
    _DAT_1002f24c = &DAT_10020ba4;
    _DAT_1002f254 = &DAT_10020ba0;
    _DAT_1002f258 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_1002f23c)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x100069c1;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_1002f240)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_100069cd;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_100069cd:
  *(undefined4 *)(puVar4 + -4) = 0x100069d2;
  return uVar2;
}



// Function: FUN_100069e6 at 100069e6

int __cdecl FUN_100069e6(ushort param_1)

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



// Function: FUN_10006a1c at 10006a1c

undefined4 __cdecl FUN_10006a1c(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10020d00)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_10020d04)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10006a4a at 10006a4a

LPCWSTR __cdecl FUN_10006a4a(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10006a77 at 10006a77

undefined4 FUN_10006a77(ushort param_1)

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



// Function: FUN_10006a9d at 10006a9d

void __fastcall FUN_10006a9d(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10006a77(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_10006abf at 10006abf

undefined4 __thiscall FUN_10006abf(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10006a9d((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10006850((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10006a77(*pWVar2);
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



// Function: FUN_10006bd5 at 10006bd5

undefined4 FUN_10006bd5(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_10020be0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10020c10);
  return 1;
}



// Function: FUN_10006c04 at 10006c04

bool FUN_10006c04(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10006c39 at 10006c39

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006c39(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10006abf(this,param_1), -1 < iVar1)) {
    FUN_10006a9d((undefined4 *)this);
    iVar1 = FUN_10006abf(this,local_2008);
    if (-1 < iVar1) {
      FUN_10006abf(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006c9e at 10006c9e

undefined4 FUN_10006c9e(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1002f22c;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: AtlInternalQueryInterface at 10006cbd

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
          if (pcVar1 == (code *)0x1) goto LAB_10006cf1;
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
LAB_10006cf1:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10006d5e at 10006d5e

void FUN_10006d5e(void)

{
  return;
}



// Function: FUN_10006d61 at 10006d61

void __fastcall FUN_10006d61(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10006d7b at 10006d7b

void __fastcall FUN_10006d7b(undefined4 *param_1)

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



// Function: FUN_10006da8 at 10006da8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10006da8(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_100194bb;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10006dd2 at 10006dd2

int __thiscall FUN_10006dd2(void *this,undefined4 *param_1)

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



// Function: FUN_10006e09 at 10006e09

void __fastcall FUN_10006e09(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10006e13 at 10006e13

void __thiscall FUN_10006e13(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_1000121b(-0x7ff8fff2);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10006e38

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_1000121b(lVar1);
  }
  return local_8;
}



// Function: FUN_10006e5d at 10006e5d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006e5d(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x24);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006472(puVar1);
    }
    uVar2 = FUN_10006ec2();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10006ead at 10006ead

undefined * Catch_10006ead(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006ebf;
}



// Function: FUN_10006ec2 at 10006ec2

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006ec2(void)

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



// Function: FUN_10006ef2 at 10006ef2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006ef2(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CHelpDBReaderImpl>::vftable;
  FUN_10006592((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1002f230 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10006f35 at 10006f35

long FUN_10006f35(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10020c50,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10006f81 at 10006f81

void FUN_10006f81(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10006f94 at 10006f94

void FUN_10006f94(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10006fa7 at 10006fa7

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10006fa7(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10006fa7(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_100173c1();
  return;
}



// Function: FUN_1000708c at 1000708c

undefined4 __fastcall FUN_1000708c(int *param_1)

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
LAB_100070d1:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_100070d1;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10006d7b(param_1);
  return 0;
}



// Function: FUN_100070e3 at 100070e3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100070e3(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_100068b0(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10006d61(local_14);
  }
  return uVar1;
}



// Function: FUN_1000712a at 1000712a

void FUN_1000712a(int param_1)

{
  FUN_1000708c((int *)(param_1 + 4));
  return;
}



// Function: FUN_10007141 at 10007141

void __fastcall FUN_10007141(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10007151 at 10007151

void __fastcall FUN_10007151(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10006e09(param_1);
    return;
  }
  return;
}



// Function: FUN_1000715e at 1000715e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000715e(int param_1)

{
  FUN_10006da8((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000717f at 1000717f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000717f(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_100071d3 at 100071d3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100071d3(undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10007207 at 10007207

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007207(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x2c);
    if (this != (void *)0x0) {
      FUN_10006ef2(this,param_1);
    }
    uVar1 = FUN_10007276();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10007261 at 10007261

undefined * Catch_10007261(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007273;
}



// Function: FUN_10007276 at 10007276

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007276(void)

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



// Function: FUN_100072a0 at 100072a0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100072a0(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CHelpDBReaderImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_10009c05((int)(param_1 + 2));
  return;
}



// Function: FUN_100072e6 at 100072e6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100072e6(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10006564(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_10007321 at 10007321

undefined4 FUN_10007321(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_1000735f at 1000735f

undefined4 FUN_1000735f(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1002f230 + 8))();
  }
  else {
    (**(code **)(*DAT_1002f230 + 4))();
  }
  return 0;
}



// Function: FUN_1000737e at 1000737e

undefined4 * __thiscall FUN_1000737e(void *this,byte param_1)

{
  FUN_100072a0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000739d at 1000739d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000739d(int *param_1)

{
  FUN_1000708c(param_1);
  FUN_10006d7b(param_1);
  return;
}



// Function: FUN_100073c7 at 100073c7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100073c7(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_1000708c(param_1 + 1);
  FUN_1000739d(param_1 + 1);
  return;
}



// Function: FUN_100073fb at 100073fb

undefined4 FUN_100073fb(void)

{
  return 0x80004001;
}



// Function: FUN_10007403 at 10007403

undefined4 FUN_10007403(void)

{
  return 1;
}



// Function: FUN_10007409 at 10007409

undefined4 * __thiscall FUN_10007409(void *this,byte param_1)

{
  FUN_100073c7((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007428 at 10007428

undefined4 __fastcall FUN_10007428(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10006dd2((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10007469 at 10007469

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10007469(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10007475;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10006870(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10006c9e(&local_5d);
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
LAB_1000755e:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_100075d2;
                }
                iVar3 = FUN_10006850((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_100068b0(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_100075f8;
                  goto LAB_1000759a;
                }
                local_55 = '\0';
              }
              else {
LAB_1000759a:
                if (local_55 != '\0') goto LAB_100075d2;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_100070e3(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_100075f8;
                local_56 = '\0';
              }
              goto LAB_100075d2;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_100070e3(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_1000755e;
            }
LAB_100075f8:
            local_5c = -0x7ff8fff2;
            goto LAB_100074d9;
          }
LAB_100075d2:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_10006a4a(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_100074d9;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                AfxCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_10007428(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_100070e3(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_100075f8;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_1000766b;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_100074d9;
            }
            iVar3 = FUN_100068b0(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_100075f8;
          }
          else {
            iVar3 = FUN_100068b0(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_1000766b:
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
LAB_100074d9:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_100173c1();
  return;
}



// Function: FUN_100076d6 at 100076d6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100076d6(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10006da8((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_10007707 at 10007707

undefined4 * __thiscall FUN_10007707(void *this,byte param_1)

{
  FUN_100076d6((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007726 at 10007726

undefined4 __thiscall FUN_10007726(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_1000717f(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 1000777d

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
    FUN_10006e13(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100077ac

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
    FUN_10006e13(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100077db

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
    FUN_10006e13(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000780a at 1000780a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_1000780a(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uStackY_28;
  
  uStackY_28 = 0x10007823;
  FUN_10005519(this,(CComBSTR *)&param_1);
  puVar1 = &uStackY_28;
  uStackY_28 = 0x10007830;
  Ordinal_6();
  puVar1[-1] = 0x10007837;
  return 0;
}



// Function: FUN_1000783a at 1000783a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000783a(undefined4 *param_1)

{
  *param_1 = CHelpDBReader::vftable;
  Ordinal_6(param_1[10]);
  Ordinal_6(param_1[8]);
  FID_conflict__Tidy(param_1 + 1,'\x01',0);
  return;
}



// Function: FUN_10007882 at 10007882

void FUN_10007882(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10006e5d(0,param_2,param_3);
    return;
  }
  FUN_10007207(param_1,param_2,param_3);
  return;
}



// Function: FUN_100078a2 at 100078a2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100078a2(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = ATL::CComClassFactorySingleton<class_CHelpDBReaderImpl>::vftable;
  piVar1 = (int *)param_1[0xb];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_100076d6(param_1);
  return;
}



// Function: FUN_100078e4 at 100078e4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100078e4(undefined4 *param_1)

{
  FUN_10009c27((int)param_1);
  *param_1 = ATL::CComObjectCached<class_CHelpDBReaderImpl>::vftable;
  param_1[1] = ATL::CComObjectCached<class_CHelpDBReaderImpl>::vftable;
  return param_1;
}



// Function: FUN_10007919 at 10007919

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007919(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_CHelpDBReaderImpl>::vftable;
  param_1[1] = ATL::CComObjectCached<class_CHelpDBReaderImpl>::vftable;
  param_1[2] = 0xc0000001;
  FUN_10009c05((int)param_1);
  return;
}



// Function: FUN_1000794f at 1000794f

undefined4 * __thiscall FUN_1000794f(void *this,byte param_1)

{
  FUN_10007919((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000796e at 1000796e

int FUN_1000796e(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 2) {
    (**(code **)(*DAT_1002f230 + 4))();
  }
  return iVar1;
}



// Function: FUN_10007992 at 10007992

int FUN_10007992(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 2;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[2];
  if (*piVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x10))(1);
    }
  }
  else if (iVar2 == 1) {
    (**(code **)(*DAT_1002f230 + 8))();
  }
  return iVar2;
}



// Function: QueryInterface at 100079c5

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10020c50,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100079df at 100079df

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100079df(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x24);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100078e4(puVar1);
    }
    uVar2 = FUN_10007a4f();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10007a35 at 10007a35

undefined * Catch_10007a35(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007a47;
}



// Function: FUN_10007a4f at 10007a4f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007a4f(void)

{
  int in_EAX;
  int unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (in_EAX != unaff_EBX) {
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 1;
    *(int *)(unaff_EBP + -0x18) = unaff_EBX;
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -1;
  }
  *unaff_ESI = in_EAX;
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10007a69 at 10007a69

void FUN_10007a69(int param_1)

{
  FUN_10007992((int *)(param_1 + -4));
  return;
}



// Function: FUN_10007a73 at 10007a73

void FUN_10007a73(int param_1)

{
  FUN_1000796e(param_1 + -4);
  return;
}



// Function: FUN_10007a7d at 10007a7d

void FUN_10007a7d(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10007a87 at 10007a87

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

int * FUN_10007a87(int param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = (int *)0x80004003;
  piVar4 = (int *)0x0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if (param_2 == (int *)0x0) {
      if ((*(int *)(param_1 + 0x28) == 0) && (piVar2 = (int *)(param_1 + 0x2c), *piVar2 == 0)) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        if ((*(int *)(param_1 + 0x28) == 0) && (*piVar2 == 0)) {
          iVar3 = FUN_100079df(&param_2);
          piVar1 = param_2;
          *(int *)(param_1 + 0x28) = iVar3;
          if (-1 < iVar3) {
            iVar3 = (**(code **)*param_2)(param_2,&DAT_10020238,piVar2);
            *(int *)(param_1 + 0x28) = iVar3;
            piVar4 = piVar1;
            if (iVar3 < 0) {
              (**(code **)(*piVar1 + 0x10))(1);
            }
          }
        }
        FUN_10007b32();
      }
      piVar2 = *(int **)(param_1 + 0x28);
      if (piVar2 == piVar4) {
        piVar2 = (int *)(**(code **)**(undefined4 **)(param_1 + 0x2c))
                                  (*(undefined4 **)(param_1 + 0x2c),param_3,param_4);
      }
    }
    else {
      piVar2 = (int *)0x80040110;
    }
  }
  return piVar2;
}



// Function: FUN_10007b32 at 10007b32

void FUN_10007b32(void)

{
  int unaff_ESI;
  
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 8));
  return;
}



// Function: FUN_10007b3f at 10007b3f

undefined4 * __thiscall FUN_10007b3f(void *this,byte param_1)

{
  FUN_100078a2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007b5e at 10007b5e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10007b5e(undefined4 *param_1)

{
  FUN_100072e6(param_1);
  *param_1 = ATL::CComClassFactorySingleton<class_CHelpDBReaderImpl>::vftable;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1;
}



// Function: FUN_10007b96 at 10007b96

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007b96(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_10016bb7(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10007c04();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10007bf0 at 10007bf0

undefined * Catch_10007bf0(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x34));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007c02;
}



// Function: FUN_10007c04 at 10007c04

void FUN_10007c04(void)

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
  uVar4 = FUN_10016bb7(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10007c5d();
  return;
}



// Function: Catch@10007c46 at 10007c46

undefined * Catch_10007c46(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x38));
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10007c5b;
}



// Function: FUN_10007c5d at 10007c5d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10007c5d(void)

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
    FUN_10001235(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10001235(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_10007726(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_10007cb9;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_10007cb9:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_10007cf1 at 10007cf1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007cf1(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_10007b96(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10006d61(local_14);
  }
  return iVar1;
}



// Function: FUN_10007d4c at 10007d4c

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10007d4c(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uStack_214c;
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
  puStack_c = &LAB_1001982c;
  local_10 = ExceptionList;
  uStack_214c = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_214c;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_214c;
  iVar1 = FUN_10006abf(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_1000693e(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_100080de;
  FUN_10006a9d((undefined4 *)this);
  iVar1 = FUN_10006abf(this,local_2018);
  if (iVar1 < 0) goto LAB_100080de;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_100080ba:
    if (uVar2 != 0) {
      FUN_10006423(uVar2);
      goto LAB_100080de;
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
        FUN_10007fea();
        return;
      }
      goto LAB_100080de;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10006d61((int *)&local_2124);
      goto LAB_100080ba;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10007e78();
      return;
    }
  }
  FUN_10006abf(this,param_3);
LAB_100080de:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10007e61 at 10007e61

undefined * Catch_10007e61(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x2138));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10007e76;
}



// Function: FUN_10007e78 at 10007e78

void FUN_10007e78(void)

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
    pWVar2 = (WCHAR *)FUN_1000680d(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10006e09((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_10006abf(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
  }
  else {
    FUN_10006423((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100080f6;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10007fc4 at 10007fc4

undefined * Catch_10007fc4(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x2134));
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10007fdc;
}



// Function: FUN_10007fea at 10007fea

void FUN_10007fea(void)

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
      FUN_10006e09((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_100069e6(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10006e09((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_10006abf(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
    }
    else {
      FUN_10006423(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100080f6;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100080fa at 100080fa

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100080fa(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_1001988b;
  local_10 = ExceptionList;
  local_14 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_1000815e:
  iVar3 = FUN_10006abf(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_1000816e:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_100085cb:
    if (*param_1 == L'}') goto LAB_1000816e;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_10006abf(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000816e;
      if (param_3 == 0) goto LAB_100082ad;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_10006a4a(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_10006bd5(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10006fa7(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_100082ad;
        }
        iVar3 = FUN_10006abf(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10006c39(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_100086ca;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_10008749;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_1000816e;
    }
LAB_100082ad:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_10006abf(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000816e;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10006a4a(param_1,L'\\');
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
          AfxCrtErrorCheck(eVar7);
          iVar3 = FUN_10006abf(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10006c39(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_100080fa(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_10006abf(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_10008768;
          iVar3 = FUN_10006abf(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10007d4c(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_100086cf;
        }
      }
      goto LAB_1000816e;
    }
    iVar3 = FUN_10006abf(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_10006abf(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_1000816e;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10007d4c(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_100086ca;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_10008749;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10006423(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_10008749:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_1000816e;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10006c39(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_10006c04(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_10006bd5(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10006fa7(&local_2234,local_21c);
        }
        goto LAB_100085cb;
      }
      bVar2 = FUN_10006c04(local_2234);
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
            FUN_10006423(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_10008749;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_100086ca:
          ATL::CRegKey::Close(pCVar8);
LAB_100086cf:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_100080fa(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_1000815e;
            goto LAB_1000816e;
          }
        }
        goto LAB_100085cb;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_100085cb;
    }
LAB_10008768:
    FUN_10006423(uVar6);
    goto LAB_1000816e;
  }
  goto LAB_100085cb;
}



// Function: FUN_10008791 at 10008791

undefined4 * __thiscall FUN_10008791(void *this,byte param_1)

{
  FUN_1000783a((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100087b0 at 100087b0

undefined4 * __thiscall
FUN_100087b0(void *this,uint param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  void *pvVar5;
  void *pvVar6;
  undefined4 *puVar7;
  uint extraout_ECX;
  uint uVar8;
  
  uVar8 = *(uint *)((int)this + 0x10);
  if ((param_1 <= uVar8) && (param_3 <= (uint)param_2[4])) {
    uVar4 = param_2[4] - param_3;
    if (uVar4 < param_4) {
      param_4 = uVar4;
    }
    if (-uVar8 - 1 <= param_4) {
      std::_Xlength_error("string too long");
      uVar8 = extraout_ECX;
    }
    if (param_4 != 0) {
      uVar8 = uVar8 + param_4;
      bVar3 = FUN_10001beb(this,uVar8,'\0');
      if (bVar3) {
        pvVar5 = this;
        pvVar6 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          pvVar5 = *this;
          pvVar6 = *this;
        }
        iVar2 = param_1 * 2;
        memmove((void *)((int)pvVar5 + (param_1 + param_4) * 2),(void *)((int)pvVar6 + iVar2),
                (*(int *)((int)this + 0x10) - param_1) * 2);
        if ((undefined4 *)this == param_2) {
          if (param_1 < param_3) {
            param_3 = param_3 + param_4;
          }
          pvVar5 = this;
          pvVar6 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar6 = *this;
          }
          memmove((void *)(iVar2 + (int)pvVar5),(void *)((int)pvVar6 + param_3 * 2),param_4 * 2);
        }
        else {
          if (7 < (uint)param_2[5]) {
            param_2 = (undefined4 *)*param_2;
          }
          pvVar6 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            pvVar6 = *this;
          }
          memcpy((void *)(iVar2 + (int)pvVar6),(void *)((int)param_2 + param_3 * 2),param_4 * 2);
        }
        *(uint *)((int)this + 0x10) = uVar8;
        pvVar6 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar6 = *this;
        }
        *(undefined2 *)((int)pvVar6 + uVar8 * 2) = 0;
      }
    }
    return (undefined4 *)this;
  }
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  puVar7 = (undefined4 *)(*pcVar1)();
  return puVar7;
}



// Function: FUN_100088e5 at 100088e5

undefined4 * __thiscall FUN_100088e5(void *this,uint param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  uint extraout_EAX;
  uint extraout_EAX_00;
  void *pvVar3;
  void *pvVar4;
  
  uVar2 = FID_conflict__Inside(this,param_2);
  if ((char)uVar2 == '\0') {
    uVar2 = *(uint *)((int)this + 0x10);
    if (uVar2 < param_1) {
      std::_Xout_of_range("invalid string position");
      uVar2 = extraout_EAX;
    }
    if (-uVar2 - 1 <= param_3) {
      std::_Xlength_error("string too long");
      uVar2 = extraout_EAX_00;
    }
    if (param_3 != 0) {
      uVar2 = uVar2 + param_3;
      bVar1 = FUN_10001beb(this,uVar2,'\0');
      if (bVar1) {
        pvVar3 = this;
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          pvVar3 = *this;
          pvVar4 = *this;
        }
        memmove((void *)((int)pvVar3 + (param_1 + param_3) * 2),(void *)((int)pvVar4 + param_1 * 2),
                (*(int *)((int)this + 0x10) - param_1) * 2);
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        memcpy((void *)(param_1 * 2 + (int)pvVar4),param_2,param_3 * 2);
        *(uint *)((int)this + 0x10) = uVar2;
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        *(undefined2 *)((int)pvVar4 + uVar2 * 2) = 0;
      }
    }
  }
  else {
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    this = FUN_100087b0(this,param_1,(undefined4 *)this,(int)param_2 - (int)pvVar4 >> 1,param_3);
  }
  return (undefined4 *)this;
}



// Function: FUN_100089dd at 100089dd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100089dd(undefined4 *param_1)

{
  FUN_10007b5e(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactorySingleton<class_CHelpDBReaderImpl>_>::
             vftable;
  return param_1;
}



// Function: FUN_10008a0b at 10008a0b

LONG FUN_10008a0b(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1002f230 + 4))();
  }
  return LVar1;
}



// Function: FUN_10008a35 at 10008a35

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008a35(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactorySingleton<class_CHelpDBReaderImpl>_>::
             vftable;
  param_1[1] = 0xc0000001;
  FUN_100078a2(param_1);
  return;
}



// Function: FUN_10008a64 at 10008a64

undefined4 * __thiscall FUN_10008a64(void *this,byte param_1)

{
  FUN_10008a35((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008a83 at 10008a83

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10008a83(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10007469(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_10008b79:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10008ace:
  if ((((sVar1 == 0) || (iVar3 = FUN_10006abf(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10006a1c(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_10006abf(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_10008b6b;
  if (param_2 == 0) {
    iVar3 = FUN_100080fa(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_10008b6b;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_100080fa(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_100080fa(this,local_2008,pHVar4,0,0);
LAB_10008b6b:
      CoTaskMemFree(local_200c);
      goto LAB_10008b79;
    }
  }
  FUN_10006a9d((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10008ace;
}



// Function: FUN_10008bba at 10008bba

void __thiscall FUN_10008bba(void *this,uint param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_100088e5(this,param_1,(undefined4 *)param_2,sVar1);
  return;
}



// Function: Catch@10008c3b at 10008c3b

undefined1 * Catch_10008c3b(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10008c4d;
}



// Function: FUN_10008c95 at 10008c95

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008c95(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  DWORD DVar2;
  int local_424;
  HMODULE local_420;
  undefined1 *local_41c;
  undefined1 auStack_418 [1040];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x428;
  local_424 = 0;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_420 = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (local_420 == (HMODULE)0x0) {
    FUN_1000640e();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (pvVar1 = LoadResource(local_420,hResInfo), pvVar1 == (HGLOBAL)0x0)) {
      FUN_1000640e();
    }
    else {
      DVar2 = SizeofResource(local_420,hResInfo);
      if (DVar2 <= DVar2 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,DVar2 + 1);
        local_8 = 1;
        FUN_10008d7d();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10006e09(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10006d61(&local_424);
  FUN_100173d0();
  return;
}



// Function: Catch@10008d5d at 10008d5d

undefined * Catch_10008d5d(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x434));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10008d75;
}



// Function: FUN_10008d7d at 10008d7d

void FUN_10008d7d(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x428),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000640e();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10008a83((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10006e09((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10006d61((int *)(unaff_EBP + -0x420));
  FUN_100173d0();
  return;
}



// Function: FUN_10008e07 at 10008e07

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008e07(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10008c95(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10006d61(local_14);
  return uVar1;
}



// Function: FUN_10008e48 at 10008e48

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008e48(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10008c95(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10006d61(local_14);
  return uVar1;
}



// Function: FUN_10008e88 at 10008e88

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10008e88(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_10007cf1(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_10030d70;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10030d70,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000640e();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10006d61((int *)&local_a48);
        goto LAB_10008f01;
      }
      FUN_100066b0(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10006397(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10006d61((int *)&local_a48);
          goto LAB_10008f01;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10007cf1(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10007cf1(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10008e48(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10008e07(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10006d61((int *)&local_a48);
  }
LAB_10008f01:
  local_8 = 0xffffffff;
  FUN_100073c7(&local_a5c);
  FUN_100173c1();
  return;
}



// Function: FUN_1000907f at 1000907f

void FUN_1000907f(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10008e88(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10009088 at 10009088

void FUN_10009088(int param_1)

{
  FUN_10008e88((int *)&DAT_100303c8,0x7c,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_100090a0 at 100090a0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100090a0(void)

{
  HANDLE pvVar1;
  size_t sVar2;
  int extraout_ECX;
  int iVar3;
  _WIN32_FIND_DATAW local_29c;
  LPCWSTR *local_4c [4];
  int local_3c;
  uint local_38;
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x290;
  local_8 = 0x100090af;
  FUN_1000260e((undefined2 *)local_4c,(LPCWSTR)&DAT_1002f450,(undefined4 *)&DAT_1002f46c,-0x7ffffffe
              );
  local_8 = 0;
  if (local_3c != 0) {
    if (local_38 < 8) {
      local_4c[0] = (LPCWSTR *)local_4c;
    }
    pvVar1 = FindFirstFileW((LPCWSTR)local_4c[0],&local_29c);
    if (pvVar1 != (HANDLE)0xffffffff) {
      local_1c = 7;
      local_20 = 0;
      local_30[0] = 0;
      FUN_10001dd5(local_30,(undefined4 *)&DAT_1002f434,0,0xffffffff);
      local_8._0_1_ = 1;
      FUN_10001c55(local_30,local_4c,0,0xffffffff);
      sVar2 = wcslen(L";");
      FUN_10001d33(local_30,(undefined4 *)&DAT_10021048,sVar2);
      iVar3 = extraout_ECX;
      FUN_1001023a((int *)&stack0xfffffd5c,(undefined4 *)local_30);
      local_8._0_1_ = 1;
      FUN_1000780a(&DAT_1002f570,iVar3);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__Tidy(local_30,'\x01',0);
    }
  }
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_4c,'\x01',0);
  FUN_100173c1();
  return;
}



// Function: FUN_1000919f at 1000919f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000919f(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  short *psVar2;
  size_t sVar3;
  undefined4 local_44 [3];
  undefined4 local_38;
  void *local_34;
  undefined2 local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  *(undefined ***)this = CHelpDBReader::vftable;
  *(undefined4 *)((int)this + 0x18) = 7;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_34 = this;
  ATL::CComBSTR::CComBSTR((CComBSTR *)((int)this + 0x20),(CComBSTR *)&param_1);
  *(undefined4 *)((int)this + 0x24) = param_2;
  *(undefined4 *)((int)this + 0x28) = 0;
  local_8._0_1_ = 3;
  FUN_10003c98(local_44);
  local_8._0_1_ = 4;
  local_38 = 0;
  puVar1 = (undefined4 *)
           FUN_1000260e(local_30,(LPCWSTR)&DAT_1002f488,(undefined4 *)&DAT_1002f4a4,-0x7ffffffe);
  local_8._0_1_ = 5;
  FUN_10002382((void *)((int)this + 4),puVar1);
  local_8 = CONCAT31(local_8._1_3_,4);
  FID_conflict__Tidy(local_30,'\x01',0);
  if (*(int *)((int)this + 0x14) == 0) {
    FUN_10004901(local_44,-0x7ffff8fc);
  }
  psVar2 = (short *)FUN_1000525d((void *)((int)this + 4),*(int *)((int)this + 0x14) - 1);
  if (*psVar2 != 0x5c) {
    sVar3 = wcslen(L"\\");
    FUN_10001d33((void *)((int)this + 4),(undefined4 *)&DAT_10020258,sVar3);
  }
  local_8 = 0xffffffff;
  Ordinal_6(param_1);
  FUN_100173c1();
  return;
}



// Function: FUN_10009285 at 10009285

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10009285(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 *this_00;
  int iVar1;
  int *piVar2;
  HANDLE pvVar3;
  ulong uVar4;
  undefined4 uStack_2a4;
  undefined4 local_288 [3];
  undefined4 local_27c;
  int local_278;
  undefined1 *local_274;
  undefined4 local_270;
  undefined4 local_26c;
  _WIN32_FIND_DATAW local_268;
  undefined4 local_8;
  undefined4 uStack_4;
  
  this_00 = param_2;
  uStack_4 = 0x278;
  local_8 = 0;
  FUN_10003c98(local_288);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_27c = 0;
  local_8._0_1_ = 2;
  FUN_10005519((void *)((int)this + 0x28),(CComBSTR *)((int)this + 0x20));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)((int)this + 0x24);
  local_270 = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 4))();
  if (iVar1 < 0) {
    uStack_2a4 = 0x100092f1;
    FUN_10004901(local_288,iVar1);
  }
  local_26c = 0;
  local_8._0_1_ = 4;
  local_274 = (undefined1 *)&uStack_2a4;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&uStack_2a4,(CComBSTR *)&param_1);
                    /* WARNING: Load size is inaccurate */
  local_8 = CONCAT31(local_8._1_3_,4);
  local_274 = (undefined1 *)(**(code **)(*this + 8))();
  if ((int)local_274 < 0) {
    FUN_100034fe(&local_26c,0x1001fc90);
  }
  piVar2 = FUN_1001023a(&local_278,(undefined4 *)((int)this + 4));
  local_8._0_1_ = 6;
  FUN_10001352(this_00,piVar2);
  local_8 = CONCAT31(local_8._1_3_,4);
  Ordinal_6(local_278);
  FUN_10001378(this_00,local_270);
  pvVar3 = FindFirstFileW((LPCWSTR)*this_00,&local_268);
  if (pvVar3 == (HANDLE)0xffffffff) {
    FUN_10004901(local_288,-0x7ffff8f5);
  }
  FUN_10004901(local_288,(int)local_274);
  iVar1 = Ordinal_7(local_26c);
  if (iVar1 != 0) {
    uVar4 = lstrlenW(L"::/");
    FUN_10001657(this_00,&DAT_1002104c,uVar4);
    FUN_10001378(this_00,local_26c);
  }
  local_8._0_1_ = 3;
  Ordinal_6(local_26c);
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6(local_270);
  local_8 = 1;
  FUN_10009416();
  return;
}



// Function: Catch@10009403 at 10009403

undefined * Catch_10009403(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10009410;
}



// Function: FUN_10009416 at 10009416

void FUN_10009416(void)

{
  int unaff_EBP;
  code *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (*unaff_ESI)(*(undefined4 *)(unaff_EBP + 8));
  FUN_100173d0();
  return;
}



// Function: FUN_1000942d at 1000942d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000942d(void *this,void *param_1)

{
  char cVar1;
  wchar_t *pwVar2;
  int iVar3;
  wchar_t *extraout_ECX;
  wchar_t *extraout_ECX_00;
  wchar_t *extraout_ECX_01;
  wchar_t *extraout_ECX_02;
  undefined *puVar4;
  short *psVar5;
  CComBSTR *pCVar6;
  undefined4 local_248 [3];
  int local_23c;
  short local_238 [4];
  int local_230;
  undefined1 *local_228;
  undefined1 *local_224;
  int local_220;
  int local_21c;
  wchar_t local_218 [264];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_8 = 0x1000943c;
  FUN_10003c98(local_248);
  local_23c = 0;
  local_220 = 0;
  local_8 = 1;
  cVar1 = FUN_10005224(0x1002f570);
                    /* WARNING: Load size is inaccurate */
  if ((cVar1 == '\0') && (local_220 = (**(code **)(*this + 0xc))(), local_220 < 0)) {
    FUN_10004901(local_248,local_220);
  }
  pwVar2 = DAT_1002f2ac;
  if (DAT_1002f2c0 < 8) {
    pwVar2 = (wchar_t *)&DAT_1002f2ac;
  }
  _swprintf(local_218,pwVar2);
  local_21c = Ordinal_2();
  if (local_21c == 0) {
    FUN_1000121b(-0x7ff8fff2);
  }
  local_8._0_1_ = 2;
  Ordinal_8();
  local_8._0_1_ = 3;
  local_238[0] = 1;
  psVar5 = local_238;
  local_224 = &stack0xfffffd94;
  puVar4 = &DAT_1002f3c4;
  pwVar2 = extraout_ECX;
  FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f3c4);
  local_8._0_1_ = 4;
  local_228 = &stack0xfffffd90;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_21c);
  local_8._0_1_ = 3;
  iVar3 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar2,psVar5);
  FUN_10004901(local_248,iVar3);
  if (local_238[0] == 1) {
    pwVar2 = DAT_1002f300;
    if (DAT_1002f314 < 8) {
      pwVar2 = (wchar_t *)&DAT_1002f300;
    }
    _swprintf(local_218,pwVar2);
    FUN_100034fe(&local_21c,(int)local_218);
    psVar5 = local_238;
    local_228 = &stack0xfffffd94;
    puVar4 = &DAT_1002f3c4;
    pwVar2 = extraout_ECX_00;
    FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f3c4);
    local_8._0_1_ = 6;
    local_224 = &stack0xfffffd90;
    ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_21c);
    local_8._0_1_ = 3;
    iVar3 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar2,psVar5);
    FUN_10004901(local_248,iVar3);
    if (local_238[0] != 1) {
      pCVar6 = (CComBSTR *)&DAT_1002f298;
      goto LAB_10009752;
    }
    pwVar2 = DAT_1002f31c;
    if (DAT_1002f330 < 8) {
      pwVar2 = (wchar_t *)&DAT_1002f31c;
    }
    _swprintf(local_218,pwVar2);
    FUN_100034fe(&local_21c,(int)local_218);
    psVar5 = local_238;
    local_228 = &stack0xfffffd94;
    puVar4 = &DAT_1002f3c4;
    pwVar2 = extraout_ECX_01;
    FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f3c4);
    local_8._0_1_ = 8;
    local_224 = &stack0xfffffd90;
    ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_21c);
    local_8._0_1_ = 3;
    iVar3 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar2,psVar5);
    FUN_10004901(local_248,iVar3);
    if (local_238[0] == 1) {
      pwVar2 = DAT_1002f338;
      if (DAT_1002f34c < 8) {
        pwVar2 = (wchar_t *)&DAT_1002f338;
      }
      _swprintf(local_218,pwVar2);
      FUN_10005519((void *)((int)this + 0x28),(CComBSTR *)&DAT_1002f298);
      *(undefined4 *)((int)this + 0x2c) = 0xffffffff;
      FUN_100034fe(&local_21c,(int)local_218);
      psVar5 = local_238;
      local_228 = &stack0xfffffd94;
      puVar4 = &DAT_1002f3c4;
      pwVar2 = extraout_ECX_02;
      FUN_1001023a((int *)&stack0xfffffd94,(undefined4 *)&DAT_1002f3c4);
      local_8._0_1_ = 10;
      local_224 = &stack0xfffffd90;
      ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd90,(CComBSTR *)&local_21c);
      local_8._0_1_ = 3;
      iVar3 = FUN_10005796(&DAT_1002f570,(int)puVar4,pwVar2,psVar5);
      FUN_10004901(local_248,iVar3);
      if (local_238[0] == 1) {
        FUN_10004901(local_248,-0x7ffff8fe);
      }
    }
    else {
      FUN_10005519((void *)((int)this + 0x28),(CComBSTR *)((int)this + 0x20));
      *(undefined4 *)((int)this + 0x2c) = 0xffffffff;
    }
  }
  else {
    pCVar6 = (CComBSTR *)((int)this + 0x20);
LAB_10009752:
    FUN_10005519((void *)((int)this + 0x28),pCVar6);
    *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)((int)this + 0x24);
  }
  if (local_23c == 0) {
    if (local_238[0] == 8) {
      FUN_100034fe(param_1,local_230);
      iVar3 = local_220;
      if (-1 < local_220) goto LAB_100097a5;
    }
    else {
      iVar3 = -0x7ffff8f9;
    }
    FUN_10004901(local_248,iVar3);
  }
LAB_100097a5:
  local_8._0_1_ = 2;
  Ordinal_9();
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6();
  local_8 = 0xffffffff;
  FUN_100173d0();
  return;
}



// Function: Catch@100097db at 100097db

undefined4 Catch_100097db(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100097c9;
}



// Function: FUN_100097e5 at 100097e5

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100097e5(void *this,undefined4 param_1,void *param_2)

{
  char cVar1;
  int iVar2;
  wchar_t *pwVar3;
  ushort **ppuVar4;
  int *piVar5;
  wchar_t *extraout_ECX;
  wchar_t *extraout_ECX_00;
  undefined *puVar6;
  short *psVar7;
  undefined4 local_280 [3];
  undefined4 local_274;
  short local_270 [4];
  wchar_t *local_268;
  wchar_t *local_260;
  wchar_t *local_25c;
  int local_258;
  undefined1 *local_254;
  undefined4 local_250 [7];
  undefined4 local_234 [7];
  wchar_t local_218 [264];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x278;
  local_8 = 0;
  FUN_10003c98(local_280);
  local_274 = 0;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  cVar1 = FUN_10005224(0x1002f570);
  if (cVar1 == '\0') {
                    /* WARNING: Load size is inaccurate */
    iVar2 = (**(code **)(*this + 0xc))();
    if (iVar2 < 0) {
      FUN_10004901(local_280,iVar2);
    }
  }
  pwVar3 = DAT_1002f2c8;
  if (DAT_1002f2dc < 8) {
    pwVar3 = (wchar_t *)&DAT_1002f2c8;
  }
  _swprintf(local_218,pwVar3);
  local_258 = Ordinal_2();
  if (local_258 == 0) {
    FUN_1000121b(-0x7ff8fff2);
  }
  local_8._0_1_ = 3;
  Ordinal_8();
  local_8._0_1_ = 4;
  local_270[0] = 1;
  psVar7 = local_270;
  local_254 = &stack0xfffffd58;
  puVar6 = &DAT_1002f3e0;
  pwVar3 = extraout_ECX;
  FUN_1001023a((int *)&stack0xfffffd58,(undefined4 *)&DAT_1002f3e0);
  local_8._0_1_ = 5;
  local_25c = (wchar_t *)&stack0xfffffd54;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd54,(CComBSTR *)&local_258);
  local_8._0_1_ = 4;
  iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar6,pwVar3,psVar7);
  FUN_10004901(local_280,iVar2);
  if (local_270[0] == 1) {
    iVar2 = -0x7ffff8fd;
  }
  else {
    if (local_270[0] == 8) {
      local_25c = (wchar_t *)0x0;
      local_8._0_1_ = 7;
      FUN_100034fe(&local_25c,(int)local_268);
      FUN_10010413((undefined2 *)local_234,local_25c);
      local_8._0_1_ = 8;
      ppuVar4 = (ushort **)DAT_1002f4dc;
      if (DAT_1002f4f0 < 8) {
        ppuVar4 = &DAT_1002f4dc;
      }
      local_254 = (undefined1 *)FUN_10001769(local_234,(ushort *)ppuVar4,0,DAT_1002f4ec);
      if (local_254 != (undefined1 *)0xffffffff) {
        pwVar3 = DAT_1002f3a8;
        if (DAT_1002f3bc < 8) {
          pwVar3 = (wchar_t *)&DAT_1002f3a8;
        }
        _swprintf(local_218,pwVar3);
        FUN_100034fe(&local_258,(int)local_218);
        psVar7 = local_270;
        local_260 = (wchar_t *)&stack0xfffffd58;
        puVar6 = &DAT_1002f418;
        pwVar3 = extraout_ECX_00;
        FUN_1001023a((int *)&stack0xfffffd58,(undefined4 *)&DAT_1002f418);
        local_8._0_1_ = 9;
        ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffd54,(CComBSTR *)&local_258);
        local_8._0_1_ = 8;
        iVar2 = FUN_10005796(&DAT_1002f570,(int)puVar6,pwVar3,psVar7);
        FUN_10004901(local_280,iVar2);
        if (local_270[0] == 1) {
          ATL::CComBSTR::CComBSTR((CComBSTR *)&local_260,(CComBSTR *)((int)this + 0x28));
          local_8._0_1_ = 0xc;
          iVar2 = FUN_1000644e(&local_260);
          FUN_10004901(local_280,iVar2);
          FUN_10008bba(local_234,(uint)(local_254 + 5),local_260);
          local_8._0_1_ = 8;
          Ordinal_6();
        }
        else if (local_270[0] == 8) {
          FUN_10010413((undefined2 *)local_250,local_268);
          local_8._0_1_ = 0xb;
          FUN_100087b0(local_234,(uint)(local_254 + 5),local_250,0,0xffffffff);
          local_8._0_1_ = 8;
          FID_conflict__Tidy(local_250,'\x01',0);
        }
      }
      piVar5 = FUN_1001023a((int *)&local_254,local_234);
      local_8._0_1_ = 0xd;
      FUN_10001352(param_2,piVar5);
      local_8 = CONCAT31(local_8._1_3_,8);
      Ordinal_6();
      iVar2 = Ordinal_7();
      if (iVar2 == 0) {
        FUN_10004901(local_280,-0x7ffff8fd);
      }
      local_8._0_1_ = 7;
      FID_conflict__Tidy(local_234,'\x01',0);
      local_8._0_1_ = 4;
      Ordinal_6();
      goto LAB_10009b53;
    }
    iVar2 = -0x7ffff8f9;
  }
  FUN_10004901(local_280,iVar2);
LAB_10009b53:
  local_8._0_1_ = 3;
  Ordinal_9();
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6();
  local_8 = 0xffffffff;
  Ordinal_6();
  FUN_100173d0();
  return;
}



// Function: Catch@10009b96 at 10009b96

undefined4 Catch_10009b96(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10009b7b;
}



// Function: FUN_10009ba3 at 10009ba3

undefined4 FUN_10009ba3(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_1002d8e8 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_10009bcf at 10009bcf

undefined4 FUN_10009bcf(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return 0;
}



// Function: FUN_10009be1 at 10009be1

undefined4 FUN_10009be1(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return 0;
}



// Function: FUN_10009bf3 at 10009bf3

undefined4 FUN_10009bf3(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return 0;
}



// Function: FUN_10009c05 at 10009c05

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009c05(int param_1)

{
  Ordinal_6(*(undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_10009c27 at 10009c27

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10009c27(int param_1)

{
  CComBSTR *this;
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_50 [4];
  undefined1 *local_40;
  int local_3c;
  void *local_38;
  undefined4 local_34 [4];
  int local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x10009c33;
  *(undefined4 *)(param_1 + 8) = 0;
  this = (CComBSTR *)(param_1 + 0xc);
  local_3c = param_1;
  ATL::CComBSTR::CComBSTR(this,(CComBSTR *)&DAT_1002f5b0);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 9999;
  *(undefined4 *)(param_1 + 0x18) = 2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  FUN_10003c98(local_50);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  FUN_1000260e((undefined2 *)local_34,(LPCWSTR)&DAT_1002f578,(undefined4 *)&DAT_1002f594,-0x7ffffffe
              );
  local_8._0_1_ = 3;
  if (local_24 == 0) {
    FUN_10004901(local_50,-0x7ffff8fc);
  }
  piVar1 = FUN_1001023a((int *)&local_38,local_34);
  local_8._0_1_ = 4;
  FUN_10001352(this,piVar1);
  local_8._0_1_ = 3;
  Ordinal_6();
  uVar2 = 0x30;
  local_38 = operator_new(0x30);
  local_8._0_1_ = 5;
  if (local_38 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x10);
    local_40 = &stack0xffffffa4;
    ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffa4,this);
    local_8._0_1_ = 5;
    uVar2 = FUN_1000919f(local_38,uVar2,uVar3);
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  local_8 = CONCAT31(local_8._1_3_,2);
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = 1;
  FUN_10009d33();
  return;
}



// Function: Catch@10009d23 at 10009d23

undefined * Catch_10009d23(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10009d30;
}



// Function: FUN_10009d33 at 10009d33

void FUN_10009d33(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100173d0();
  return;
}



// Function: FUN_10009d3f at 10009d3f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009d3f(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  void *this;
  int iVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 local_58 [3];
  undefined4 local_4c;
  undefined4 *local_48;
  void *local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x10009d4b;
  local_3c = param_1;
  local_38 = param_2;
  local_48 = param_4;
  FUN_10003c98(local_58);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_4c = 0;
  local_40 = Ordinal_2();
  if (local_40 != 0) goto LAB_10009d89;
  while( true ) {
    FUN_1000121b(-0x7ff8fff2);
LAB_10009d89:
    local_8._0_1_ = 2;
    if (param_3 == 0) {
      if (*(int *)(param_1 + 0x1c) != 0) {
        if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x18))();
        }
        local_8._0_1_ = 3;
        uVar4 = 0x30;
        local_44 = operator_new(0x30);
        local_8._0_1_ = 4;
        if (local_44 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar5 = *(undefined4 *)(param_1 + 0xc);
          ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff88,(CComBSTR *)(param_1 + 8));
          local_8 = CONCAT31(local_8._1_3_,4);
          uVar4 = FUN_1000919f(local_44,uVar4,uVar5);
        }
        *(undefined4 *)(param_1 + 0x18) = uVar4;
        local_8 = 2;
        FUN_10009ebf();
        return;
      }
      iVar1 = FUN_100063c4(*(void **)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xc));
      FUN_10004901(local_58,iVar1);
    }
    else if (param_3 == 1) {
      if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x18))();
      }
      local_8._0_1_ = 7;
      uVar4 = 0x34;
      local_44 = operator_new(0x34);
      local_8._0_1_ = 8;
      if (local_44 == (void *)0x0) {
        this = (void *)0x0;
      }
      else {
        uVar5 = *(undefined4 *)(param_1 + 0x14);
        uVar3 = *(undefined4 *)(param_1 + 0x10);
        ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff84,(CComBSTR *)(param_1 + 8));
        local_8._0_1_ = 8;
        this = (void *)FUN_100056b6(local_44,uVar4,uVar3,uVar5);
      }
      local_8 = CONCAT31(local_8._1_3_,7);
      *(void **)(param_1 + 0x18) = this;
      *(undefined4 *)(param_1 + 0x1c) = 1;
      iVar1 = FUN_100063c4(this,*(undefined4 *)(param_1 + 0x10));
      FUN_10004901(local_58,iVar1);
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
    }
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar1 = -0x7ffff8f8;
      goto LAB_10009f28;
    }
    piVar6 = &local_40;
    if (local_38 == 0) break;
    iVar1 = Ordinal_2();
    if (iVar1 != 0) {
LAB_10009f01:
      local_8._0_1_ = 2;
      iVar1 = FUN_10009285(*(void **)(param_1 + 0x18),iVar1,piVar6);
      pwVar2 = ATL::CComBSTR::Copy((CComBSTR *)&local_40);
      *local_48 = pwVar2;
LAB_10009f28:
      FUN_10004901(local_58,iVar1);
      local_8 = 1;
      FUN_1000a1a2();
      return;
    }
  }
  iVar1 = 0;
  goto LAB_10009f01;
}



// Function: Catch@10009e1d at 10009e1d

undefined * Catch_10009e1d(void)

{
  int unaff_EBP;
  
  FUN_10004901((void *)(unaff_EBP + -0x54),-0x7ffff8fc);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10009e37;
}



// Function: Catch@10009ea0 at 10009ea0

undefined * Catch_10009ea0(void)

{
  int unaff_EBP;
  
  FUN_10004901((void *)(unaff_EBP + -0x54),-0x7ffff8fc);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10009eba;
}



// Function: FUN_10009ebf at 10009ebf

void FUN_10009ebf(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  wchar_t *pwVar5;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  *(undefined4 **)(unaff_ESI + 0x1c) = unaff_EBX;
  do {
    iVar3 = FUN_100063c4(*(void **)(unaff_ESI + 0x18),*(undefined4 *)(unaff_ESI + 0xc));
    FUN_10004901((void *)(unaff_EBP + -0x54),iVar3);
LAB_10009ed6:
    if (*(undefined4 **)(unaff_ESI + 0x18) == unaff_EBX) {
      iVar3 = -0x7ffff8f8;
LAB_10009f28:
      FUN_10004901((void *)(unaff_EBP + -0x54),iVar3);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_1000a1a2();
      return;
    }
    puVar1 = (undefined4 *)(unaff_EBP + -0x3c);
    *(undefined1 **)(unaff_EBP + -0x58) = &stack0xfffffff8;
    puVar4 = unaff_EBX;
    if ((*(undefined4 **)(unaff_EBP + -0x34) == unaff_EBX) ||
       (puVar4 = (undefined4 *)Ordinal_2(), puVar4 != unaff_EBX)) {
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      pvVar2 = *(void **)(unaff_ESI + 0x18);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar3 = FUN_10009285(pvVar2,puVar4,puVar1);
      pwVar5 = ATL::CComBSTR::Copy((CComBSTR *)(unaff_EBP + -0x3c));
      **(undefined4 **)(unaff_EBP + -0x44) = pwVar5;
      goto LAB_10009f28;
    }
    FUN_1000121b(-0x7ff8fff2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (*(undefined4 **)(unaff_EBP + 0x10) != unaff_EBX) {
      if ((int)*(undefined4 **)(unaff_EBP + 0x10) - (int)unaff_EBX == 1) {
        if (*(undefined4 **)(unaff_ESI + 0x18) != unaff_EBX) {
          (**(code **)**(undefined4 **)(unaff_ESI + 0x18))();
        }
        *(undefined1 *)(unaff_EBP + -4) = 7;
        uVar7 = 0x34;
        puVar1 = (undefined4 *)operator_new(0x34);
        *(undefined4 **)(unaff_EBP + -0x40) = puVar1;
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if (puVar1 == unaff_EBX) {
          pvVar2 = (void *)0x0;
        }
        else {
          uVar8 = *(undefined4 *)(unaff_ESI + 0x14);
          uVar6 = *(undefined4 *)(unaff_ESI + 0x10);
          *(undefined1 **)(unaff_EBP + -0x58) = &stack0xfffffff4;
          ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffff4,(CComBSTR *)(unaff_ESI + 8));
          *(undefined1 *)(unaff_EBP + -4) = 9;
          *(undefined1 *)(unaff_EBP + -4) = 8;
          pvVar2 = (void *)FUN_100056b6(*(void **)(unaff_EBP + -0x40),uVar7,uVar6,uVar8);
        }
        *(undefined1 *)(unaff_EBP + -4) = 7;
        *(void **)(unaff_ESI + 0x18) = pvVar2;
        *(undefined4 *)(unaff_ESI + 0x1c) = 1;
        iVar3 = FUN_100063c4(pvVar2,*(undefined4 *)(unaff_ESI + 0x10));
        FUN_10004901((void *)(unaff_EBP + -0x54),iVar3);
        *(undefined4 *)(unaff_EBP + -4) = 2;
      }
      goto LAB_10009ed6;
    }
    if (*(undefined4 **)(unaff_ESI + 0x1c) != unaff_EBX) {
      if (*(undefined4 **)(unaff_ESI + 0x18) != unaff_EBX) {
        (**(code **)**(undefined4 **)(unaff_ESI + 0x18))();
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar7 = 0x30;
      puVar1 = (undefined4 *)operator_new(0x30);
      *(undefined4 **)(unaff_EBP + -0x40) = puVar1;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      if (puVar1 == unaff_EBX) {
        uVar7 = 0;
      }
      else {
        uVar8 = *(undefined4 *)(unaff_ESI + 0xc);
        *(undefined1 **)(unaff_EBP + -0x58) = &stack0xfffffff8;
        ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffff8,(CComBSTR *)(unaff_ESI + 8));
        *(undefined1 *)(unaff_EBP + -4) = 5;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        uVar7 = FUN_1000919f(*(void **)(unaff_EBP + -0x40),uVar7,uVar8);
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      *(undefined4 *)(unaff_ESI + 0x18) = uVar7;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_10009ebf();
      return;
    }
  } while( true );
}



// Function: Catch@10009f3c at 10009f3c

undefined * Catch_10009f3c(void)

{
  HWND pHVar1;
  int iVar2;
  wchar_t *pwVar3;
  ulong uVar4;
  int unaff_EBP;
  code *pcVar5;
  LPCWSTR pWVar6;
  LPCWSTR pWVar7;
  undefined4 uVar8;
  UINT UVar9;
  
  iVar2 = *(int *)(unaff_EBP + -0x48);
  if (iVar2 == -0x7ffff8ff) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    pcVar5 = Ordinal_6_exref;
    Ordinal_6(0);
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    FUN_100013ba(0xfa2,(int *)(unaff_EBP + -0x34));
    Ordinal_6(0);
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    FUN_100013ba(0xfa1,(int *)(unaff_EBP + -0x38));
    FUN_1000260e((undefined2 *)(unaff_EBP + -0x30),(LPCWSTR)&DAT_1002f768,
                 (undefined4 *)&DAT_1002f784,-0x7ffffffe);
    *(undefined1 *)(unaff_EBP + -4) = 0x11;
    pWVar6 = *(LPCWSTR *)(unaff_EBP + -0x30);
    if (*(uint *)(unaff_EBP + -0x1c) < 8) {
      pWVar6 = (LPCWSTR)(unaff_EBP + -0x30);
    }
    uVar4 = lstrlenW(pWVar6);
    FUN_10001657((void *)(unaff_EBP + -0x34),pWVar6,uVar4);
    UVar9 = 0x2030;
    pWVar6 = *(LPCWSTR *)(unaff_EBP + -0x38);
    pWVar7 = *(LPCWSTR *)(unaff_EBP + -0x34);
    pHVar1 = GetForegroundWindow();
    MessageBoxW(pHVar1,pWVar7,pWVar6,UVar9);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x30),'\x01',0);
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
LAB_1000a185:
    (*pcVar5)(*(undefined4 *)(unaff_EBP + -0x38));
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    uVar8 = *(undefined4 *)(unaff_EBP + -0x34);
  }
  else {
    if (iVar2 == -0x7ffff8fd) {
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 0x16;
      pcVar5 = Ordinal_6_exref;
      Ordinal_6(0);
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      FUN_100013ba(4000,(int *)(unaff_EBP + -0x34));
      Ordinal_6(0);
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      FUN_100013ba(0xfa1,(int *)(unaff_EBP + -0x38));
      UVar9 = 0x2031;
      pWVar6 = *(LPCWSTR *)(unaff_EBP + -0x38);
      pWVar7 = *(LPCWSTR *)(unaff_EBP + -0x34);
      pHVar1 = GetForegroundWindow();
      iVar2 = MessageBoxW(pHVar1,pWVar7,pWVar6,UVar9);
      if (iVar2 == 1) {
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x48) = 1;
        FUN_100034fe((void *)(unaff_EBP + -0x3c),0x1001fc90);
        pwVar3 = ATL::CComBSTR::Copy((CComBSTR *)(unaff_EBP + -0x3c));
        **(undefined4 **)(unaff_EBP + -0x44) = pwVar3;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      goto LAB_1000a185;
    }
    if (iVar2 == -0x7ffff8f5) {
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      pcVar5 = Ordinal_6_exref;
      Ordinal_6(0);
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      FUN_100013ba(0xfa2,(int *)(unaff_EBP + -0x34));
      Ordinal_6(0);
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      FUN_100013ba(0xfa1,(int *)(unaff_EBP + -0x38));
      FUN_10001378((void *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x3c));
      UVar9 = 0x2030;
      pWVar6 = *(LPCWSTR *)(unaff_EBP + -0x38);
      pWVar7 = *(LPCWSTR *)(unaff_EBP + -0x34);
      pHVar1 = GetForegroundWindow();
      MessageBoxW(pHVar1,pWVar7,pWVar6,UVar9);
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      goto LAB_1000a185;
    }
    if (iVar2 != -0x7ffff8f4) goto LAB_1000a193;
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0x12;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0x13;
    pcVar5 = Ordinal_6_exref;
    Ordinal_6(0);
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    FUN_100013ba(0xfa1,(int *)(unaff_EBP + -0x34));
    FUN_10001878((undefined4 *)(unaff_EBP + -0x28));
    *(undefined1 *)(unaff_EBP + -4) = 0x14;
    FUN_10002881((int *)(unaff_EBP + -0x38));
    UVar9 = 0;
    pWVar6 = *(LPCWSTR *)(unaff_EBP + -0x34);
    pWVar7 = *(LPCWSTR *)(unaff_EBP + -0x38);
    pHVar1 = GetForegroundWindow();
    MessageBoxW(pHVar1,pWVar7,pWVar6,UVar9);
    *(undefined1 *)(unaff_EBP + -4) = 0x13;
    FUN_100018b8((undefined4 *)(unaff_EBP + -0x28));
    *(undefined1 *)(unaff_EBP + -4) = 0x12;
    Ordinal_6(*(undefined4 *)(unaff_EBP + -0x34));
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    uVar8 = *(undefined4 *)(unaff_EBP + -0x38);
  }
  (*pcVar5)(uVar8);
LAB_1000a193:
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000a1a0;
}



// Function: FUN_1000a1a2 at 1000a1a2

void FUN_1000a1a2(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x3c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100173d0();
  return;
}



// Function: FUN_1000a1bd at 1000a1bd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_1000a1bd(undefined1 *param_1,int param_2,void *param_3,undefined2 *param_4)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 local_2c [3];
  undefined4 local_20;
  undefined1 *local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x1000a1c9;
  FUN_10003c98(local_2c);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_20 = 0;
  local_18[0] = Ordinal_2();
  puVar1 = param_1;
  if (local_18[0] != 0) goto LAB_1000a1f5;
  while( true ) {
    param_1 = puVar1;
    FUN_1000121b(-0x7ff8fff2);
LAB_1000a1f5:
    local_8._0_1_ = 1;
    if (param_4 == (undefined2 *)0x0) {
      FUN_10004901(local_2c,-0x7fffbffd);
    }
    local_8._0_1_ = 2;
    uVar2 = (undefined1)local_8;
    local_8._0_1_ = 2;
    if (param_3 == (void *)0x0) {
      local_8._0_1_ = uVar2;
      if ((*(int *)(param_1 + 0x1c) != 0) || (*(int *)(param_1 + 0x18) == 0)) {
        if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x18))();
        }
        local_8._0_1_ = 3;
        uVar7 = 0x30;
        pvVar4 = operator_new(0x30);
        local_8._0_1_ = 4;
        if (pvVar4 == (void *)0x0) {
          uVar7 = 0;
        }
        else {
          uVar8 = *(undefined4 *)(param_1 + 0xc);
          local_1c = &stack0xffffffb8;
          ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffb8,(CComBSTR *)(param_1 + 8));
          local_8 = CONCAT31(local_8._1_3_,4);
          uVar7 = FUN_1000919f(pvVar4,uVar7,uVar8);
        }
        *(undefined4 *)(param_1 + 0x18) = uVar7;
        local_8 = 2;
        FUN_1000a345();
        return;
      }
      iVar5 = FUN_100063c4(*(void **)(param_1 + 0x18),*(undefined4 *)(param_1 + 0xc));
      FUN_10004901(local_2c,iVar5);
      uVar2 = (undefined1)local_8;
    }
    else if (param_3 == (void *)0x1) {
      if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0x18))();
      }
      local_8._0_1_ = 7;
      uVar7 = 0x34;
      param_3 = operator_new(0x34);
      local_8._0_1_ = 8;
      if (param_3 == (void *)0x0) {
        pvVar4 = (void *)0x0;
      }
      else {
        uVar8 = *(undefined4 *)(param_1 + 0x14);
        uVar6 = *(undefined4 *)(param_1 + 0x10);
        local_1c = &stack0xffffffb4;
        ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffb4,(CComBSTR *)(param_1 + 8));
        local_8._0_1_ = 8;
        pvVar4 = (void *)FUN_100056b6(param_3,uVar7,uVar6,uVar8);
      }
      local_8 = CONCAT31(local_8._1_3_,7);
      *(void **)(param_1 + 0x18) = pvVar4;
      *(undefined4 *)(param_1 + 0x1c) = 1;
      iVar5 = FUN_100063c4(pvVar4,*(undefined4 *)(param_1 + 0x10));
      FUN_10004901(local_2c,iVar5);
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      uVar2 = (undefined1)local_8;
    }
    local_8._0_1_ = uVar2;
    if (*(int *)(param_1 + 0x18) == 0) {
      FUN_10004901(local_2c,-0x7ffff8f8);
      goto LAB_1000a3c1;
    }
    piVar9 = local_18;
    if (param_2 == 0) break;
    iVar5 = Ordinal_2();
    puVar1 = &stack0xffffffb8;
    if (iVar5 != 0) {
LAB_1000a387:
      local_8 = CONCAT31(local_8._1_3_,2);
      iVar5 = FUN_10009285(*(void **)(param_1 + 0x18),iVar5,piVar9);
      FUN_10004901(local_2c,iVar5);
      if (local_18[0] == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0xffff;
      }
      *param_4 = uVar3;
LAB_1000a3c1:
      local_8 = 1;
      FUN_1000a3d9();
      return;
    }
  }
  iVar5 = 0;
  goto LAB_1000a387;
}



// Function: Catch@1000a29e at 1000a29e

undefined * Catch_1000a29e(void)

{
  int unaff_EBP;
  
  FUN_10004901((void *)(unaff_EBP + -0x28),-0x7ffff8fc);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_1000a2b8;
}



// Function: Catch@1000a326 at 1000a326

undefined * Catch_1000a326(void)

{
  int unaff_EBP;
  
  FUN_10004901((void *)(unaff_EBP + -0x28),-0x7ffff8fc);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_1000a340;
}



// Function: FUN_1000a345 at 1000a345

void FUN_1000a345(void)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  *(undefined4 **)(unaff_ESI + 0x1c) = unaff_EBX;
  do {
    iVar4 = FUN_100063c4(*(void **)(unaff_ESI + 0x18),*(undefined4 *)(unaff_ESI + 0xc));
    FUN_10004901((void *)(unaff_EBP + -0x28),iVar4);
LAB_1000a35c:
    if (*(undefined4 **)(unaff_ESI + 0x18) == unaff_EBX) {
      FUN_10004901((void *)(unaff_EBP + -0x28),-0x7ffff8f8);
LAB_1000a3c1:
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_1000a3d9();
      return;
    }
    puVar2 = (undefined4 *)(unaff_EBP + -0x14);
    *(undefined1 **)(unaff_EBP + 8) = &stack0xfffffff8;
    puVar5 = unaff_EBX;
    if ((*(undefined4 **)(unaff_EBP + 0xc) == unaff_EBX) ||
       (puVar5 = (undefined4 *)Ordinal_2(), puVar5 != unaff_EBX)) {
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      pvVar3 = *(void **)(unaff_ESI + 0x18);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar4 = FUN_10009285(pvVar3,puVar5,puVar2);
      FUN_10004901((void *)(unaff_EBP + -0x28),iVar4);
      if (*(undefined4 **)(unaff_EBP + -0x14) == unaff_EBX) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xffff;
      }
      **(undefined2 **)(unaff_EBP + 0x14) = uVar1;
      goto LAB_1000a3c1;
    }
    FUN_1000121b(-0x7ff8fff2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (*(undefined4 **)(unaff_EBP + 0x14) == unaff_EBX) {
      FUN_10004901((void *)(unaff_EBP + -0x28),-0x7fffbffd);
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    unaff_ESI = *(int *)(unaff_EBP + 8);
    if (*(undefined4 **)(unaff_EBP + 0x10) != unaff_EBX) {
      if ((int)*(undefined4 **)(unaff_EBP + 0x10) - (int)unaff_EBX == 1) {
        if (*(undefined4 **)(unaff_ESI + 0x18) != unaff_EBX) {
          (**(code **)**(undefined4 **)(unaff_ESI + 0x18))();
        }
        *(undefined1 *)(unaff_EBP + -4) = 7;
        uVar7 = 0x34;
        puVar2 = (undefined4 *)operator_new(0x34);
        *(undefined4 **)(unaff_EBP + 0x10) = puVar2;
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if (puVar2 == unaff_EBX) {
          pvVar3 = (void *)0x0;
        }
        else {
          uVar8 = *(undefined4 *)(unaff_ESI + 0x14);
          uVar6 = *(undefined4 *)(unaff_ESI + 0x10);
          *(undefined1 **)(unaff_EBP + -0x18) = &stack0xfffffff4;
          ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffff4,(CComBSTR *)(unaff_ESI + 8));
          *(undefined1 *)(unaff_EBP + -4) = 9;
          *(undefined1 *)(unaff_EBP + -4) = 8;
          pvVar3 = (void *)FUN_100056b6(*(void **)(unaff_EBP + 0x10),uVar7,uVar6,uVar8);
        }
        *(undefined1 *)(unaff_EBP + -4) = 7;
        *(void **)(unaff_ESI + 0x18) = pvVar3;
        *(undefined4 *)(unaff_ESI + 0x1c) = 1;
        iVar4 = FUN_100063c4(pvVar3,*(undefined4 *)(unaff_ESI + 0x10));
        FUN_10004901((void *)(unaff_EBP + -0x28),iVar4);
        *(undefined4 *)(unaff_EBP + -4) = 2;
      }
      goto LAB_1000a35c;
    }
    if ((*(undefined4 **)(unaff_ESI + 0x1c) != unaff_EBX) ||
       (*(undefined4 **)(unaff_ESI + 0x18) == unaff_EBX)) {
      if (*(undefined4 **)(unaff_ESI + 0x18) != unaff_EBX) {
        (**(code **)**(undefined4 **)(unaff_ESI + 0x18))();
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar7 = 0x30;
      puVar2 = (undefined4 *)operator_new(0x30);
      *(undefined4 **)(unaff_EBP + 0x10) = puVar2;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      if (puVar2 == unaff_EBX) {
        uVar7 = 0;
      }
      else {
        uVar8 = *(undefined4 *)(unaff_ESI + 0xc);
        *(undefined1 **)(unaff_EBP + -0x18) = &stack0xfffffff8;
        ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffff8,(CComBSTR *)(unaff_ESI + 8));
        *(undefined1 *)(unaff_EBP + -4) = 5;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        uVar7 = FUN_1000919f(*(void **)(unaff_EBP + 0x10),uVar7,uVar8);
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      *(undefined4 *)(unaff_ESI + 0x18) = uVar7;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_1000a345();
      return;
    }
  } while( true );
}



// Function: Catch@1000a3ca at 1000a3ca

undefined * Catch_1000a3ca(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000a3d7;
}



// Function: FUN_1000a3d9 at 1000a3d9

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a3d9(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return *(undefined4 *)(unaff_EBP + -0x1c);
}



// Function: FUN_1000a3f4 at 1000a3f4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a3f4(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_2c [3];
  undefined4 local_20;
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x1000a400;
  FUN_10003c98(local_2c);
  local_8 = 0;
  local_20 = 0;
  local_18 = Ordinal_2();
  if (local_18 == 0) {
    FUN_1000121b(-0x7ff8fff2);
  }
  puVar1 = param_2;
  local_8._0_1_ = 1;
  if (param_2 == (undefined4 *)0x0) {
    FUN_10004901(local_2c,-0x7fffbffd);
  }
  local_8._0_1_ = 2;
  if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x18))();
  }
  *(undefined4 *)(param_1 + 0x1c) = 1;
  uVar5 = 0x34;
  pvVar2 = operator_new(0x34);
  local_8._0_1_ = 3;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    uVar6 = *(undefined4 *)(param_1 + 0x14);
    uVar4 = *(undefined4 *)(param_1 + 0x10);
    local_1c = &stack0xffffffb4;
    ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffb4,(CComBSTR *)(param_1 + 8));
    local_8._0_1_ = 3;
    pvVar2 = (void *)FUN_100056b6(pvVar2,uVar5,uVar4,uVar6);
  }
  local_8._0_1_ = 2;
  *(void **)(param_1 + 0x18) = pvVar2;
  iVar3 = FUN_100063c4(pvVar2,*(undefined4 *)(param_1 + 0x10));
  FUN_10004901(local_2c,iVar3);
  param_2 = (undefined4 *)0x0;
  local_8._0_1_ = 5;
  iVar3 = FUN_10005d63(*(void **)(param_1 + 0x18),&param_2);
  FUN_10004901(local_2c,iVar3);
  *puVar1 = param_2;
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6();
  local_8 = 0;
  Ordinal_6();
  return local_20;
}



// Function: Catch@1000a500 at 1000a500

undefined4 Catch_1000a500(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000a4e4;
}



// Function: FUN_1000a50d at 1000a50d

void __fastcall FUN_1000a50d(undefined4 *param_1)

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



// Function: FUN_1000a526 at 1000a526

int __thiscall FUN_1000a526(void *this,uint param_1)

{
  int iVar1;
  _Locimp *p_Var2;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  if (param_1 < *(uint *)(iVar1 + 0xc)) {
    iVar3 = *(int *)(*(int *)(iVar1 + 8) + param_1 * 4);
  }
  else {
    iVar3 = 0;
  }
  if ((iVar3 == 0) && (*(char *)(iVar1 + 0x14) != '\0')) {
    p_Var2 = std::locale::_Getgloballocale();
    if (param_1 < *(uint *)(p_Var2 + 0xc)) {
      iVar3 = *(int *)(*(int *)(p_Var2 + 8) + param_1 * 4);
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}



// Function: FUN_1000a561 at 1000a561

void __thiscall FUN_1000a561(void *this,int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(bool *)((int)this + 0x50) = param_2 == 1;
  *(undefined1 *)((int)this + 0x49) = 0;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (param_1 != 0) {
    *(int *)((int)this + 0x10) = param_1 + 8;
    *(int *)((int)this + 0x14) = param_1 + 8;
    *(int *)((int)this + 0x20) = param_1;
    *(int *)((int)this + 0x24) = param_1;
    *(int *)((int)this + 0x30) = param_1 + 4;
    *(int *)((int)this + 0x34) = param_1 + 4;
  }
  *(int *)((int)this + 0x54) = param_1;
  uVar1 = DAT_1002f894;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x4c) = uVar1;
  return;
}



// Function: FUN_1000a5ae at 1000a5ae

void __thiscall FUN_1000a5ae(void *this,codecvt_base *param_1)

{
  bool bVar1;
  
  bVar1 = std::codecvt_base::always_noconv(param_1);
  if (bVar1) {
    *(undefined4 *)((int)this + 0x44) = 0;
  }
  else {
    *(codecvt_base **)((int)this + 0x44) = param_1;
    std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  }
  return;
}



// Function: _Reset_back at 1000a5db

/* Library Function - Single Match
    private: void __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::_Reset_back(void)
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back
          (basic_filebuf<char,struct_std::char_traits<char>_> *this)

{
  undefined4 uVar1;
  
  if ((basic_filebuf<char,struct_std::char_traits<char>_> *)**(int **)(this + 0x10) == this + 0x48)
  {
    uVar1 = *(undefined4 *)(this + 0x40);
    **(int **)(this + 0x10) = *(int *)(this + 0x3c);
    **(undefined4 **)(this + 0x20) = uVar1;
    **(undefined4 **)(this + 0x30) = 0;
  }
  return;
}



// Function: FUN_1000a5fc at 1000a5fc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

facet * __cdecl FUN_1000a5fc(locale *param_1)

{
  uint uVar1;
  facet *pfVar2;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  facet *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x1000a608;
  std::_Lockit::_Lockit(local_18,0);
  local_8 = 0;
  local_14[0] = DAT_1002f898;
  uVar1 = std::locale::id::operator_unsigned_int((id *)id_exref);
  pfVar2 = (facet *)FUN_1000a526(param_1,uVar1);
  if ((pfVar2 == (facet *)0x0) && (pfVar2 = local_14[0], local_14[0] == (facet *)0x0)) {
    uVar1 = std::codecvt<char,char,int>::_Getcat(local_14,param_1);
    pfVar2 = local_14[0];
    if (uVar1 == 0xffffffff) {
      std::bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_10027fc8);
    }
    DAT_1002f898 = local_14[0];
    std::locale::facet::_Incref(local_14[0]);
    Facet_Register(pfVar2);
  }
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_18);
  return pfVar2;
}



// Function: FUN_1000a6a0 at 1000a6a0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000a6a0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000a6ac;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0xaaaaaab) &&
     (pvVar1 = operator_new((int)param_1 * 0x18), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100261e8);
}



// Function: FUN_1000a6ff at 1000a6ff

void __fastcall FUN_1000a6ff(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x15) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x15) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x15) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x15) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x15) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: QueryStringValue at 1000a745

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
              (*(short *)((int)param_2 + ((local_8 & 0xfffffffe) - 2)) != 0)) goto LAB_1000a781;
    }
    *puVar2 = local_8 >> 1;
    lVar4 = 0;
  }
  else {
LAB_1000a781:
    lVar4 = 0xd;
  }
  return lVar4;
}



// Function: _Chassign at 1000a7b4

/* Library Function - Single Match
    public: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Chassign(unsigned int,unsigned int,char)
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Chassign
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          uint param_1,uint param_2,char param_3)

{
  if (param_2 == 1) {
    if (0xf < *(uint *)(this + 0x14)) {
      this = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)this;
    }
    this[param_1] =
         (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)param_3;
  }
  else {
    if (0xf < *(uint *)(this + 0x14)) {
      this = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)this;
    }
    memset(this + param_1,(int)param_3,param_2);
  }
  return;
}



// Function: FUN_1000a7f0 at 1000a7f0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1000a7f0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000a7fc;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_100261e8);
  }
  return;
}



// Function: FUN_1000a84a at 1000a84a

undefined4 FUN_1000a84a(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_1002d908 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000a876 at 1000a876

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a876(void)

{
  AFX_MODULE_STATE *pAVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000a882;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10017051();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return 0;
}



// Function: FUN_1000a8a6 at 1000a8a6

void FUN_1000a8a6(void)

{
  if (DAT_10030d74 != (HMODULE)0x0) {
    FreeLibrary(DAT_10030d74);
  }
  return;
}



// Function: FUN_1000a8b7 at 1000a8b7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a8b7(int param_1)

{
  Ordinal_6(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_1000a8d9 at 1000a8d9

void __fastcall FUN_1000a8d9(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_1000a8e3 at 1000a8e3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_1000a8e3(void *this,int param_1)

{
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  *(undefined ***)this = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  FUN_1000a561(this,param_1,0);
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_1000a91e at 1000a91e

void __fastcall FUN_1000a91e(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _lock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_1000a92e at 1000a92e

void __fastcall FUN_1000a92e(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _unlock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_1000a93e at 1000a93e

uint __fastcall FUN_1000a93e(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if ((pcVar3 != (char *)0x0) &&
     (iVar1 = **(int **)(param_1 + 0x30), iVar2 = **(int **)(param_1 + 0x20),
     pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1),
     pcVar3 < (char *)(iVar1 + iVar2))) {
    pbVar4 = (byte *)std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
    return (uint)*pbVar4;
  }
  uVar5 = (**(code **)(*(int *)param_1 + 0x1c))();
  uVar6 = 0xffffffff;
  if (uVar5 != 0xffffffff) {
    (**(code **)(*(int *)param_1 + 0x10))(uVar5);
    uVar6 = uVar5;
  }
  return uVar6;
}



// Function: FUN_1000a98c at 1000a98c

undefined4 __fastcall FUN_1000a98c(int *param_1)

{
  int iVar1;
  
  if (param_1[0x15] != 0) {
    iVar1 = (**(code **)(*param_1 + 0xc))(0xffffffff);
    if (iVar1 != -1) {
      iVar1 = fflush((FILE *)param_1[0x15]);
      if (iVar1 < 0) {
        return 0xffffffff;
      }
    }
  }
  return 0;
}



// Function: _Set_back at 1000a9b8

/* Library Function - Single Match
    private: void __thiscall std::basic_filebuf<char,struct std::char_traits<char>
   >::_Set_back(void)
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::basic_filebuf<char,struct_std::char_traits<char>_>::_Set_back
          (basic_filebuf<char,struct_std::char_traits<char>_> *this)

{
  basic_filebuf<char,struct_std::char_traits<char>_> *pbVar1;
  basic_filebuf<char,struct_std::char_traits<char>_> *pbVar2;
  
  pbVar2 = (basic_filebuf<char,struct_std::char_traits<char>_> *)**(int **)(this + 0x10);
  pbVar1 = this + 0x48;
  if (pbVar2 != pbVar1) {
    *(basic_filebuf<char,struct_std::char_traits<char>_> **)(this + 0x3c) = pbVar2;
    *(int *)(this + 0x40) = **(int **)(this + 0x30) + **(int **)(this + 0x20);
  }
  **(int **)(this + 0x10) = (int)pbVar1;
  **(int **)(this + 0x20) = (int)pbVar1;
  **(undefined4 **)(this + 0x30) = this + (0x49 - (int)pbVar1);
  return;
}



// Function: FUN_1000a9ec at 1000a9ec

int __cdecl FUN_1000a9ec(undefined1 *param_1,FILE *param_2)

{
  int iVar1;
  uint3 uVar2;
  
  iVar1 = fgetc(param_2);
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if (iVar1 == -1) {
    return (uint)uVar2 << 8;
  }
  *param_1 = (char)iVar1;
  return CONCAT31(uVar2,1);
}



// Function: FUN_1000aa0b at 1000aa0b

bool __cdecl FUN_1000aa0b(char param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = fputc((int)param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_1000aa28 at 1000aa28

bool __cdecl FUN_1000aa28(byte *param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = ungetc((uint)*param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_1000aa47 at 1000aa47

uint __thiscall FUN_1000aa47(void *this,uint param_1)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  uVar4 = param_1;
  if (((pcVar2 == (char *)0x0) ||
      (pcVar2 = (char *)**(uint **)((int)this + 0x10),
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
      pcVar3 <= pcVar2)) ||
     ((uVar4 != 0xffffffff &&
      (pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                          ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
      (byte)pcVar2[-1] != uVar4)))) {
    if ((*(FILE **)((int)this + 0x54) != (FILE *)0x0) && (uVar4 != 0xffffffff)) {
      if (*(int *)((int)this + 0x44) == 0) {
        param_1 = CONCAT13((char)uVar4,(undefined3)param_1);
        bVar1 = FUN_1000aa28((byte *)((int)&param_1 + 3),*(FILE **)((int)this + 0x54));
        if (bVar1) {
          return uVar4;
        }
      }
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      if (pcVar2 != (char *)((int)this + 0x48)) {
        *(char *)((int)this + 0x48) = (char)uVar4;
        std::basic_filebuf<char,struct_std::char_traits<char>_>::_Set_back
                  ((basic_filebuf<char,struct_std::char_traits<char>_> *)this);
        return uVar4;
      }
    }
    uVar4 = 0xffffffff;
  }
  else {
    std::basic_streambuf<char,struct_std::char_traits<char>_>::_Gndec
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    uVar4 = -(uint)(uVar4 != 0xffffffff) & uVar4;
  }
  return uVar4;
}



// Function: FUN_1000aae2 at 1000aae2

void * __thiscall FUN_1000aae2(void *this,char *param_1,size_t param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(FILE **)((int)this + 0x54) != (FILE *)0x0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0 && param_3 == 0)) {
      iVar1 = 4;
    }
    iVar1 = setvbuf(*(FILE **)((int)this + 0x54),param_1,iVar1,param_2);
    if (iVar1 == 0) {
      FUN_1000a561(this,*(int *)((int)this + 0x54),1);
      return this;
    }
  }
  return (void *)0x0;
}



// Function: FUN_1000ab2d at 1000ab2d

void __thiscall FUN_1000ab2d(void *this,locale *param_1)

{
  facet *pfVar1;
  
  pfVar1 = FUN_1000a5fc(param_1);
  FUN_1000a5ae(this,(codecvt_base *)pfVar1);
  return;
}



// Function: FUN_1000ab49 at 1000ab49

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_1000ab49(void *this,char *param_1,int param_2,int param_3)

{
  _iobuf *p_Var1;
  locale *plVar2;
  facet *pfVar3;
  
  if ((*(int *)((int)this + 0x54) == 0) &&
     (p_Var1 = std::_Fiopen(param_1,param_2,param_3), p_Var1 != (_iobuf *)0x0)) {
    FUN_1000a561(this,(int)p_Var1,1);
    plVar2 = (locale *)
             std::basic_streambuf<char,struct_std::char_traits<char>_>::getloc
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pfVar3 = FUN_1000a5fc(plVar2);
    FUN_1000a5ae(this,(codecvt_base *)pfVar3);
    FUN_1000a50d(&param_3);
    return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
  }
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
}



// Function: FUN_1000abb6 at 1000abb6

undefined4 * __thiscall FUN_1000abb6(void *this,int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if ((int)puVar2[3] < *param_1) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  return puVar2;
}



// Function: FUN_1000abe2 at 1000abe2

void __fastcall FUN_1000abe2(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x15) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x15) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x15) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x15) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_1000ac1d at 1000ac1d

void __thiscall FUN_1000ac1d(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x15) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)((int)this + 4) + 4)) {
    *(int **)(*(int *)((int)this + 4) + 4) = piVar1;
  }
  else {
    piVar2 = *(int **)(param_1 + 4);
    if (param_1 == *piVar2) {
      *piVar2 = (int)piVar1;
    }
    else {
      piVar2[2] = (int)piVar1;
    }
  }
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}



// Function: FUN_1000ac62 at 1000ac62

void __thiscall FUN_1000ac62(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x15) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)((int)this + 4) + 4)) {
    *(int *)(*(int *)((int)this + 4) + 4) = iVar1;
  }
  else {
    piVar2 = (int *)param_1[1];
    if (param_1 == (int *)piVar2[2]) {
      piVar2[2] = iVar1;
    }
    else {
      *piVar2 = iVar1;
    }
  }
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}



// Function: FUN_1000aca9 at 1000aca9

void __fastcall FUN_1000aca9(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000a6a0((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 5) = 0;
  return;
}



// Function: FUN_1000acd0 at 1000acd0

undefined4 * __thiscall FUN_1000acd0(void *this,uint param_1,uint param_2)

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



// Function: FUN_1000ad4a at 1000ad4a

void __fastcall FUN_1000ad4a(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000ad61 at 1000ad61

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ad61(int param_1)

{
  int *piVar1;
  
  FUN_1000a8a6();
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000ad9b at 1000ad9b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT FUN_1000ad9b(undefined4 param_1,undefined4 param_2)

{
  AFX_MODULE_STATE *pAVar1;
  HRESULT HVar2;
  AFX_MAINTAIN_STATE2 local_24 [16];
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x1000ada7;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10017051();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_24,pAVar1);
  local_14[0] = (int *)0x0;
  local_8 = 2;
  HVar2 = CoCreateInstance((IID *)&DAT_10021ca0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100210e8,local_14);
  if (-1 < HVar2) {
    HVar2 = (**(code **)*local_14[0])(local_14[0],&DAT_100210e8,param_2);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_24);
  return HVar2;
}



// Function: FUN_1000ae15 at 1000ae15

void __thiscall FUN_1000ae15(void *this,char *param_1,int param_2,int param_3)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = FUN_1000ab49((void *)((int)this + 0x18),param_1,param_2,param_3);
                    /* WARNING: Load size is inaccurate */
  if (pbVar1 == (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)(*(int *)(*this + 4) + (int)this),2
               ,false);
  }
  else {
    std::basic_ios<char,struct_std::char_traits<char>_>::clear
              ((basic_ios<char,struct_std::char_traits<char>_> *)(*(int *)(*this + 4) + (int)this),0
               ,false);
  }
  return;
}



// Function: FUN_1000ae52 at 1000ae52

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ae52(int param_1)

{
  Ordinal_6(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_1000ae74 at 1000ae74

int __fastcall FUN_1000ae74(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_1000a6a0((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x15) = 1;
  return param_1;
}



// Function: FUN_1000aeab at 1000aeab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000aeab(void *this,byte param_1)

{
  Ordinal_6(*(undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000aee0 at 1000aee0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000aee0(int param_1,DWORD *param_2,DWORD *param_3)

{
  DWORD DVar1;
  DWORD *lpArguments;
  DWORD *extraout_ECX;
  
  lpArguments = (DWORD *)0x0;
  if (param_1 != 0) goto LAB_1000af04;
  do {
    RaiseException(0xc0000005,1,(DWORD)lpArguments,lpArguments);
    lpArguments = extraout_ECX;
LAB_1000af04:
  } while ((param_2 == lpArguments) || (param_3 == lpArguments));
  *param_2 = (DWORD)param_3;
  DVar1 = GetCurrentThreadId();
  param_2[1] = DVar1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  param_2[2] = *(DWORD *)(param_1 + 0x1c);
  *(DWORD **)(param_1 + 0x1c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000af56 at 1000af56

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000af56(int param_1)

{
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  int *piVar4;
  int *piVar5;
  
  iVar2 = param_1;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));
    piVar5 = *(int **)(iVar2 + 0x1c);
    if (piVar5 != (int *)0x0) {
      DVar3 = GetCurrentThreadId();
      piVar4 = (int *)0x0;
      do {
        if (piVar5[1] == DVar3) {
          if (piVar4 == (int *)0x0) {
            *(int *)(iVar2 + 0x1c) = piVar5[2];
          }
          else {
            piVar4[2] = piVar5[2];
          }
          param_1 = *piVar5;
          break;
        }
        piVar1 = piVar5 + 2;
        piVar4 = piVar5;
        piVar5 = (int *)*piVar1;
      } while ((int *)*piVar1 != (int *)0x0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));
  }
  return param_1;
}



// Function: _Tidy at 1000afd7

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



// Function: FUN_1000b01b at 1000b01b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_1000b01b(void *this,uint param_1)

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
  FUN_1000a7f0((char *)(param_1 + 1));
  FUN_1000b0ab();
  return;
}



// Function: Catch@1000b07d at 1000b07d

undefined * Catch_1000b07d(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_1000a7f0((char *)(iVar1 + 1));
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000b0a5;
}



// Function: FUN_1000b0ab at 1000b0ab

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000b0ab(void)

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



// Function: Catch@1000b0f4 at 1000b0f4

void Catch_1000b0f4(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x1c),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b109 at 1000b109

undefined4 FUN_1000b109(int param_1,int *param_2)

{
  if ((*(int *)(param_1 + 8) == 0) && (param_2 != (int *)0x0)) {
    FUN_1000131f((int *)(param_1 + 8),param_2);
  }
  return 0;
}



// Function: FUN_1000b12c at 1000b12c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * FUN_1000b12c(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)&LAB_10019fb4;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_2[1] = 0;
    puVar1 = param_2;
  }
  return puVar1;
}



// Function: FUN_1000b166 at 1000b166

void __fastcall
FUN_1000b166(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_1000b170 at 1000b170

bool __thiscall FUN_1000b170(void *this,uint param_1,char param_2)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *extraout_ECX;
  
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_1000b01b(this,param_1);
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



// Function: FUN_1000b1d5 at 1000b1d5

void FUN_1000b1d5(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *dwNewLong;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_1000af56(0x10030da8);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)param_1;
    iVar2 = (**(code **)(*piVar1 + 8))();
    FUN_10003198(piVar1 + 5,iVar2,piVar1);
    dwNewLong = (code *)piVar1[5];
    SetWindowLongW(param_1,4,(LONG)dwNewLong);
    (*dwNewLong)(param_1,param_2,param_3,param_4);
  }
  return;
}



// Function: FUN_1000b222 at 1000b222

void __cdecl FUN_1000b222(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000b12c(param_2,param_3);
  return;
}



// Function: FUN_1000b235 at 1000b235

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_1000b235(void *this,uint param_1,char param_2)

{
  uint uVar1;
  bool bVar2;
  int extraout_EAX;
  int iVar3;
  void *pvVar4;
  
  iVar3 = *(int *)((int)this + 0x10);
  if (-iVar3 - 1U <= param_1) {
    std::_Xlength_error("string too long");
    iVar3 = extraout_EAX;
  }
  if (param_1 != 0) {
    uVar1 = iVar3 + param_1;
    bVar2 = FUN_1000b170(this,uVar1,'\0');
    if (bVar2) {
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Chassign
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 this,*(uint *)((int)this + 0x10),param_1,param_2);
      *(uint *)((int)this + 0x10) = uVar1;
      pvVar4 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      *(undefined1 *)((int)pvVar4 + uVar1) = 0;
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_1000b296 at 1000b296

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_1000b296(void *this,uint param_1,char param_2)

{
  bool bVar1;
  void *pvVar2;
  void *extraout_ECX;
  
  pvVar2 = this;
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    pvVar2 = extraout_ECX;
  }
  bVar1 = FUN_1000b170(pvVar2,param_1,'\0');
  if (bVar1) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Chassign
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
               0,param_1,param_2);
    *(uint *)((int)this + 0x10) = param_1;
    pvVar2 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar2 = *this;
    }
    *(undefined1 *)((int)pvVar2 + param_1) = 0;
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_1000b2e4 at 1000b2e4

INT_PTR __thiscall FUN_1000b2e4(void *this,HWND param_1,LPARAM param_2)

{
  int iVar1;
  INT_PTR IVar2;
  
  iVar1 = FUN_10003198((void *)((int)this + 0x14),0,0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    IVar2 = -1;
  }
  else {
    FUN_1000aee0(0x10030da8,(DWORD *)((int)this + 8),(DWORD *)this);
    IVar2 = DialogBoxParamW(DAT_10030d74,(LPCWSTR)0x68,param_1,FUN_1000b1d5,param_2);
  }
  return IVar2;
}



// Function: FUN_1000b334 at 1000b334

undefined4 * __thiscall
FUN_1000b334(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *extraout_EAX;
  void *pvVar4;
  void *pvVar5;
  uint extraout_ECX;
  
  uVar2 = FID_conflict__Inside(this,param_3);
  if ((char)uVar2 == '\0') {
    uVar2 = *(uint *)((int)this + 0x10);
    if (uVar2 < param_1) {
      std::_Xout_of_range("invalid string position");
      uVar2 = extraout_ECX;
    }
    puVar3 = (undefined4 *)(uVar2 - param_1);
    if (puVar3 < param_2) {
      param_2 = puVar3;
    }
    if (-(int)param_4 - 1U <= uVar2 - (int)param_2) {
      std::_Xlength_error("string too long");
      puVar3 = extraout_EAX;
    }
    if (param_4 < param_2) {
      pvVar4 = this;
      pvVar5 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
        pvVar5 = *this;
      }
      memmove((void *)((int)pvVar4 + ((int)param_4 + param_1) * 2),
              (void *)((int)pvVar5 + (param_1 + (int)param_2) * 2),((int)puVar3 - (int)param_2) * 2)
      ;
    }
    if ((param_4 != (undefined4 *)0x0) || (param_2 != (undefined4 *)0x0)) {
      uVar2 = (*(int *)((int)this + 0x10) - (int)param_2) + (int)param_4;
      bVar1 = FUN_10001beb(this,uVar2,'\0');
      if (bVar1) {
        if (param_2 < param_4) {
          pvVar4 = this;
          pvVar5 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar4 = *this;
            pvVar5 = *this;
          }
          memmove((void *)((int)pvVar4 + ((int)param_4 + param_1) * 2),
                  (void *)((int)pvVar5 + ((int)param_2 + param_1) * 2),
                  ((int)puVar3 - (int)param_2) * 2);
        }
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar5 = *this;
        }
        memcpy((void *)((int)pvVar5 + param_1 * 2),param_3,(int)param_4 * 2);
        *(uint *)((int)this + 0x10) = uVar2;
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar5 = *this;
        }
        *(undefined2 *)((int)pvVar5 + uVar2 * 2) = 0;
      }
    }
  }
  else {
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
    }
    this = FUN_10001e71(this,param_1,param_2,(undefined4 *)this,(int)param_3 - (int)pvVar5 >> 1,
                        (uint)param_4);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b493 at 1000b493

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000b493(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  int iVar1;
  char *pcVar2;
  char ****ppppcVar3;
  int iVar4;
  char *local_3c;
  char *local_38;
  char local_31;
  char ***local_30 [4];
  int local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x1000b49f;
  pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if ((pcVar2 == (char *)0x0) ||
     (iVar4 = **(int **)(param_1 + 0x30), iVar1 = **(int **)(param_1 + 0x20),
     pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1),
     (char *)(iVar4 + iVar1) <= pcVar2)) {
    if (*(int *)(param_1 + 0x54) != 0) {
      std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back
                ((basic_filebuf<char,struct_std::char_traits<char>_> *)param_1);
      if (*(int *)(param_1 + 0x44) != 0) {
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
        local_8 = 0;
LAB_1000b5b3:
        while (iVar4 = fgetc(*(FILE **)(param_1 + 0x54)), iVar4 != -1) {
          FUN_1000b235(local_30,1,(char)iVar4);
          ppppcVar3 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar3 = local_30;
          }
          iVar4 = std::codecvt<char,char,int>::in
                            (*(codecvt<char,char,int> **)(param_1 + 0x44),(int *)(param_1 + 0x4c),
                             (char *)ppppcVar3,(char *)((int)ppppcVar3 + local_20),&local_38,
                             &local_31,(char *)local_30,&local_3c);
          if (iVar4 < 0) break;
          if (1 < iVar4) {
            if (iVar4 == 3) goto code_r0x1000b56d;
            break;
          }
          if (local_3c != &local_31) {
            ppppcVar3 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar3 = local_30;
            }
            pcVar2 = (char *)((int)ppppcVar3 + (local_20 - (int)local_38));
            while (0 < (int)pcVar2) {
              pcVar2 = pcVar2 + -1;
              ungetc((int)local_38[(int)pcVar2],*(FILE **)(param_1 + 0x54));
            }
            break;
          }
          ppppcVar3 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar3 = local_30;
          }
          FUN_1000acd0(local_30,0,(int)local_38 - (int)ppppcVar3);
        }
        goto LAB_1000b5c5;
      }
      local_31 = '\0';
      FUN_1000a9ec(&local_31,*(FILE **)(param_1 + 0x54));
    }
  }
  else {
    std::basic_streambuf<char,struct_std::char_traits<char>_>::_Gninc(param_1);
  }
LAB_1000b4cc:
  FUN_100173c1();
  return;
code_r0x1000b56d:
  if (local_20 != 0) goto code_r0x1000b572;
  goto LAB_1000b5b3;
code_r0x1000b572:
  ppppcVar3 = (char ****)local_30[0];
  if (local_1c < 0x10) {
    ppppcVar3 = local_30;
  }
  memcpy_s(&local_31,1,ppppcVar3,1);
LAB_1000b5c5:
  local_8 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,true,0);
  goto LAB_1000b4cc;
}



// Function: FUN_1000b60c at 1000b60c

void __cdecl FUN_1000b60c(undefined4 param_1,void *param_2)

{
  FUN_1000aeab(param_2,0);
  return;
}



// Function: FUN_1000b61b at 1000b61b

void __thiscall
FUN_1000b61b(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x1ffffffd < uVar3) {
    this = (void *)((int)this + 0xd);
    FUN_1000b60c(this,param_4 + 3);
    operator_delete(param_4);
    std::_Xlength_error("map/set<T> too long");
    uVar3 = extraout_EAX;
  }
  *(uint *)((int)this + 8) = uVar3 + 1;
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
  iVar4 = param_4[1];
  piVar5 = param_4;
  do {
    if (*(char *)(iVar4 + 0x14) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x14) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x14) == '\0') {
LAB_1000b6ea:
        *(undefined1 *)(piVar1 + 5) = 1;
        *(undefined1 *)(iVar4 + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_1000ac1d(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
        FUN_1000ac62(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x14) == '\0') goto LAB_1000b6ea;
      if (piVar5 == (int *)*piVar1) {
        FUN_1000ac62(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x14) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
      FUN_1000ac1d(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_1000b753 at 1000b753

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000b753(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000aca9((int)this);
  FUN_1000b222((int)this + 0xd,(undefined4 *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@1000b790 at 1000b790

void Catch_1000b790(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b7a3 at 1000b7a3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000b7a3(void *this,undefined4 *param_1)

{
  HWND pHVar1;
  INT_PTR IVar2;
  undefined1 local_cc [196];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xbc;
  local_8 = 0x1000b7b2;
  FUN_10004448(local_cc,param_1,0);
  local_8 = 0;
  FUN_10003f22(local_cc,*(int **)((int)this + 0x14));
  pHVar1 = GetActiveWindow();
  if (pHVar1 == (HWND)0x0) {
    pHVar1 = FindWindowW(L"{C64400AC-259D-491d-BD78-8ACDA17676AE}",(LPCWSTR)0x0);
  }
  IVar2 = FUN_1000b2e4(local_cc,pHVar1,0);
  if (IVar2 == -1) {
    GetLastError();
  }
  local_8 = 0xffffffff;
  FUN_10004668((int)local_cc);
  return 0;
}



// Function: FUN_1000b81e at 1000b81e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000b81e(void *this,undefined4 *param_1)

{
  HWND pHVar1;
  INT_PTR IVar2;
  LPARAM LVar3;
  undefined1 local_cc [196];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xbc;
  local_8 = 0x1000b82d;
  FUN_100046ea(local_cc,param_1,0);
  local_8 = 0;
  FUN_10003f22(local_cc,*(int **)((int)this + 0x14));
  LVar3 = 0;
  pHVar1 = GetActiveWindow();
  IVar2 = FUN_1000b2e4(local_cc,pHVar1,LVar3);
  if (IVar2 == -1) {
    GetLastError();
  }
  local_8 = 0xffffffff;
  FUN_10004668((int)local_cc);
  return 0;
}



// Function: FUN_1000b889 at 1000b889

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000b889(void *this,int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char ****ppppcVar4;
  size_t sVar5;
  char cVar6;
  size_t _Count;
  char *local_3c;
  char *local_38;
  char local_34;
  char acStack_33 [3];
  char ***local_30 [4];
  uint local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x1000b895;
  if (param_1 != -1) {
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    cVar6 = (char)param_1;
    if ((pcVar2 == (char *)0x0) ||
       (iVar3 = **(int **)((int)this + 0x34), iVar1 = **(int **)((int)this + 0x24),
       pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                          ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       (char *)(iVar3 + iVar1) <= pcVar2)) {
      if (*(int *)((int)this + 0x54) != 0) {
        std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back
                  ((basic_filebuf<char,struct_std::char_traits<char>_> *)this);
        if (*(int *)((int)this + 0x44) == 0) {
          FUN_1000aa0b(cVar6,*(FILE **)((int)this + 0x54));
        }
        else {
          _local_34 = CONCAT31(acStack_33,cVar6);
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
          FUN_1000b296(local_30,8,'\0');
          local_8 = 0;
          while( true ) {
            ppppcVar4 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar4 = local_30;
            }
            iVar3 = std::codecvt<char,char,int>::out
                              (*(codecvt<char,char,int> **)((int)this + 0x44),
                               (int *)((int)this + 0x4c),&local_34,acStack_33,&local_3c,
                               (char *)ppppcVar4,(char *)((int)ppppcVar4 + local_20),&local_38);
            if (iVar3 < 0) goto LAB_1000b9d6;
            if (1 < iVar3) break;
            ppppcVar4 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar4 = local_30;
            }
            _Count = (int)local_38 - (int)ppppcVar4;
            if (_Count != 0) {
              ppppcVar4 = (char ****)local_30[0];
              if (local_1c < 0x10) {
                ppppcVar4 = local_30;
              }
              sVar5 = fwrite(ppppcVar4,1,_Count,*(FILE **)((int)this + 0x54));
              if (_Count != sVar5) goto LAB_1000b9d6;
            }
            *(undefined1 *)((int)this + 0x49) = 1;
            if (local_3c != &local_34) goto LAB_1000b9d6;
            if (_Count == 0) {
              if (0x1f < local_20) goto LAB_1000b9d6;
              FUN_1000b235(local_30,8,'\0');
            }
          }
          if (iVar3 == 3) {
            FUN_1000aa0b((char)_local_34,*(FILE **)((int)this + 0x54));
          }
LAB_1000b9d6:
          local_8 = 0xffffffff;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_30,true,0);
        }
      }
    }
    else {
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      *pcVar2 = cVar6;
    }
  }
  FUN_100173c1();
  return;
}



// Function: FUN_1000b9f1 at 1000b9f1

void __thiscall FUN_1000b9f1(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x15);
  while (cVar1 == '\0') {
    FUN_1000b9f1(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_1000b60c((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  return;
}



// Function: FUN_1000ba35 at 1000ba35

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000ba35(int *param_1)

{
  int iVar1;
  char ******ppppppcVar2;
  size_t sVar3;
  size_t _Count;
  char *local_34;
  char *****local_30 [4];
  int local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x1000ba41;
  if (((param_1[0x11] != 0) && (*(char *)((int)param_1 + 0x49) != '\0')) &&
     (iVar1 = (**(code **)(*param_1 + 0xc))(0xffffffff), iVar1 != -1)) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char *****)((uint)local_30[0] & 0xffffff00);
    FUN_1000b296(local_30,8,'\0');
    local_8 = 0;
LAB_1000ba8a:
    ppppppcVar2 = (char ******)local_30[0];
    if (local_1c < 0x10) {
      ppppppcVar2 = local_30;
    }
    iVar1 = std::codecvt<char,char,int>::unshift
                      ((codecvt<char,char,int> *)param_1[0x11],param_1 + 0x13,(char *)ppppppcVar2,
                       (char *)((int)ppppppcVar2 + local_20),&local_34);
    if (iVar1 == 0) {
      *(undefined1 *)((int)param_1 + 0x49) = 0;
    }
    else if (iVar1 != 1) goto LAB_1000bab9;
    ppppppcVar2 = (char ******)local_30[0];
    if (local_1c < 0x10) {
      ppppppcVar2 = local_30;
    }
    _Count = (int)local_34 - (int)ppppppcVar2;
    if (_Count != 0) {
      ppppppcVar2 = (char ******)local_30[0];
      if (local_1c < 0x10) {
        ppppppcVar2 = local_30;
      }
      sVar3 = fwrite(ppppppcVar2,1,_Count,(FILE *)param_1[0x15]);
      if (_Count != sVar3) goto LAB_1000bab9;
    }
    if (*(char *)((int)param_1 + 0x49) == '\0') goto LAB_1000bab9;
    if (_Count == 0) {
      FUN_1000b235(local_30,8,'\0');
    }
    goto LAB_1000ba8a;
  }
LAB_1000bb2d:
  FUN_100173c1();
  return;
LAB_1000bab9:
  local_8 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,true,0);
  goto LAB_1000bb2d;
}



// Function: FUN_1000bb33 at 1000bb33

void __thiscall FUN_1000bb33(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x15) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_1000abe2((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x15) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x15) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000bb7d;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar7[1] = (int)piVar5;
      }
      *piVar5 = (int)piVar7;
      param_2[2] = piVar2[2];
      *(int **)(piVar2[2] + 4) = param_2;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = param_2;
    }
    else {
      piVar6 = (int *)piVar2[1];
      if ((int *)*piVar6 == piVar2) {
        *piVar6 = (int)param_2;
      }
      else {
        piVar6[2] = (int)param_2;
      }
    }
    param_2[1] = piVar2[1];
    iVar1 = param_2[5];
    *(char *)(param_2 + 5) = (char)piVar2[5];
    *(char *)(piVar2 + 5) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_1000bb7d:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x15) == '\0') {
      piVar7[1] = (int)piVar5;
    }
    if (*(int **)(*(int *)((int)this + 4) + 4) == piVar2) {
      *(int **)(*(int *)((int)this + 4) + 4) = piVar7;
    }
    else if ((int *)*piVar5 == piVar2) {
      *piVar5 = (int)piVar7;
    }
    else {
      piVar5[2] = (int)piVar7;
    }
    if ((int *)**(int **)((int)this + 4) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x15) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x15) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[5] != '\x01') {
LAB_1000bd5a:
    FUN_1000b60c((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000bd0e:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[5] != '\x01'))
  goto LAB_1000bd56;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_1000ac1d(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(*piVar5 + 0x14) != '\x01') || (*(char *)(piVar5[2] + 0x14) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x14) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x14) = 1;
          *(undefined1 *)(piVar5 + 5) = 0;
          FUN_1000ac62(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 5) = (char)piVar6[5];
        *(undefined1 *)(piVar6 + 5) = 1;
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        FUN_1000ac1d(this,(int)piVar6);
        goto LAB_1000bd56;
      }
LAB_1000bd05:
      *(undefined1 *)(piVar5 + 5) = 0;
    }
  }
  else {
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_1000ac62(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(piVar5[2] + 0x14) == '\x01') && (*(char *)(*piVar5 + 0x14) == '\x01'))
      goto LAB_1000bd05;
      if (*(char *)(*piVar5 + 0x14) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        *(undefined1 *)(piVar5 + 5) = 0;
        FUN_1000ac1d(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 5) = (char)piVar6[5];
      *(undefined1 *)(piVar6 + 5) = 1;
      *(undefined1 *)(*piVar5 + 0x14) = 1;
      FUN_1000ac62(this,piVar6);
LAB_1000bd56:
      *(undefined1 *)(piVar7 + 5) = 1;
      goto LAB_1000bd5a;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000bd0e;
}



// Function: FUN_1000bd90 at 1000bd90

void __thiscall FUN_1000bd90(void *this,undefined4 *param_1,int *param_2,char param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *local_c;
  bool local_8;
  
  piVar2 = *(int **)((int)this + 4);
  piVar1 = param_2 + 3;
  local_8 = true;
  local_c = piVar2;
  if (*(char *)(piVar2[1] + 0x15) == '\0') {
    piVar3 = (int *)piVar2[1];
    do {
      local_c = piVar3;
      if (param_3 == '\0') {
        local_8 = *piVar1 < local_c[3];
      }
      else {
        local_8 = *piVar1 <= local_c[3];
      }
      if (local_8 == false) {
        piVar3 = (int *)local_c[2];
      }
      else {
        piVar3 = (int *)*local_c;
      }
    } while (*(char *)((int)piVar3 + 0x15) == '\0');
  }
  _param_3 = local_c;
  if (local_8 != false) {
    if (local_c == (int *)*piVar2) {
      local_8 = true;
      goto LAB_1000bdf5;
    }
    FUN_1000a6ff((int *)&param_3);
  }
  piVar2 = _param_3;
  if (*piVar1 <= _param_3[3]) {
    FUN_1000b60c((int)this + 0xd,piVar1);
    operator_delete(param_2);
    *param_1 = piVar2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_1000bdf5:
  puVar4 = (undefined4 *)FUN_1000b61b(this,(undefined4 *)&param_3,local_8,local_c,param_2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_1000be4f at 1000be4f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000be4f(int *param_1)

{
  wchar_t *pwVar1;
  HWND pHVar2;
  int iVar3;
  undefined2 *this;
  LPCWSTR lpFileName;
  HANDLE pvVar4;
  UINT UVar5;
  ULONG_PTR dwData;
  undefined4 *puVar6;
  ULONG_PTR local_2c0;
  LPCWSTR local_2bc;
  int local_2b8;
  wchar_t *local_2b4;
  UINT local_2b0;
  LPCWSTR local_2ac;
  wchar_t *local_2a8;
  wchar_t *local_2a4;
  _WIN32_FIND_DATAW local_2a0;
  undefined1 local_50 [8];
  undefined4 local_48 [5];
  undefined4 local_34;
  undefined4 local_30;
  undefined **local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined **local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2b0;
  local_8 = 0x1000be5e;
  if (*param_1 != 0) {
    local_2c0 = 0;
    local_2b0 = 0;
    local_2a4 = (wchar_t *)0x0;
    local_2b4 = (wchar_t *)0x0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    local_2b8 = 0;
    (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1,&local_2b8);
    FUN_100034fe(&local_2a4,local_2b8);
    Ordinal_6(local_2b8);
    (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1,&local_2c0);
    (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_2b0);
    Ordinal_6(0);
    local_2b4 = (wchar_t *)0x0;
    FUN_100013ba(0x69,(int *)&local_2b4);
    pwVar1 = wcsstr(local_2a4,local_2b4);
    if (pwVar1 == (wchar_t *)0x0) {
      ATL::CComBSTR::CComBSTR((CComBSTR *)&local_2a8,(CComBSTR *)&local_2a4);
      local_8._0_1_ = 2;
      pwVar1 = wcsstr(local_2a8,L"::");
      iVar3 = (int)pwVar1 - (int)local_2a8;
      this = FUN_10002350(&local_30,local_2a8);
      local_8._0_1_ = 3;
      lpFileName = (LPCWSTR)FUN_1000226d(this,local_50,0,iVar3 >> 1);
      local_8._0_1_ = 4;
      if (7 < *(uint *)(lpFileName + 10)) {
        lpFileName = *(LPCWSTR *)lpFileName;
      }
      pvVar4 = FindFirstFileW(lpFileName,&local_2a0);
      local_8._0_1_ = 3;
      FID_conflict__Tidy(local_50,'\x01',0);
      local_8._0_1_ = 2;
      FID_conflict__Tidy(&local_30,'\x01',0);
      if (pvVar4 == (HANDLE)0xffffffff) {
        local_2bc = (LPCWSTR)0x0;
        local_2ac = (LPCWSTR)0x0;
        local_8._0_1_ = 6;
        Ordinal_6(0);
        local_2ac = (LPCWSTR)0x0;
        FUN_100013ba(0xfa1,(int *)&local_2ac);
        FUN_10001878(local_48);
        local_8._0_1_ = 7;
        FUN_10002881((int *)&local_2bc);
        MessageBoxW((HWND)0x0,local_2bc,local_2ac,0x30);
        local_8._0_1_ = 6;
        FUN_100018b8(local_48);
        local_8._0_1_ = 5;
        Ordinal_6(local_2ac);
        local_8._0_1_ = 2;
        Ordinal_6(local_2bc);
      }
      else {
        if (local_2b0 == 3) {
          local_2c = &PTR_1001fc90;
          local_18 = &PTR_1001fc90;
          puVar6 = &local_34;
          local_34 = 0x20;
          local_30 = 0;
          local_28 = 0;
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
          UVar5 = 3;
        }
        else {
          puVar6 = (undefined4 *)0x0;
          UVar5 = local_2b0;
        }
        pwVar1 = local_2a4;
        pHVar2 = GetDesktopWindow();
        _HtmlHelpW_16(pHVar2,pwVar1,UVar5,puVar6);
      }
      local_8._0_1_ = 1;
      Ordinal_6(local_2a8);
    }
    else {
      pwVar1 = local_2a4;
      UVar5 = local_2b0;
      dwData = local_2c0;
      pHVar2 = GetDesktopWindow();
      WinHelpW(pHVar2,pwVar1,UVar5,dwData);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(local_2b4);
    local_8 = 0xffffffff;
    Ordinal_6(local_2a4);
  }
  FUN_100173c1();
  return;
}



// Function: FUN_1000c0c1 at 1000c0c1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000c0c1(void)

{
  undefined4 *puVar1;
  wchar_t *pwVar2;
  int iVar3;
  LSTATUS LVar4;
  size_t sVar5;
  uint uVar6;
  undefined4 *puVar7;
  wchar_t ***pppwVar8;
  HMODULE Value;
  uint uVar9;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined4 local_46c;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_468 [4];
  DWORD local_464;
  wchar_t **local_460;
  wchar_t **local_45c [4];
  undefined4 *local_44c;
  uint local_448;
  wchar_t **local_440 [4];
  undefined4 local_430;
  uint local_42c;
  wchar_t local_424 [260];
  wchar_t local_21c [266];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x474;
  local_480 = 0;
  local_47c = 0;
  local_478 = 0;
  local_42c = 7;
  local_430 = 0;
  local_440[0] = (wchar_t **)((uint)local_440[0] & 0xffff0000);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            (local_468,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\infosrvc");
  local_8._0_1_ = 2;
  uVar9 = 0x2001f;
  pwVar2 = ATL::CSimpleStringT<wchar_t,1>::operator_wchar_t_const_
                     ((CSimpleStringT<wchar_t,1> *)local_468);
  iVar3 = Open(&local_480,(HKEY)0x80000002,pwVar2,uVar9);
  if (iVar3 == 0) {
    local_464 = 0x208;
    LVar4 = FUN_100014b7(&local_480,(LPBYTE)local_21c,L"ResourceDLL",&local_464);
    if (LVar4 == 0) {
      local_474 = 0;
      local_470 = 0;
      local_46c = 0;
      local_8._0_1_ = 3;
      iVar3 = Open(&local_474,(HKEY)0x80000002,
                   L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",0x2001f);
      if (iVar3 == 0) {
        local_448 = 7;
        local_44c = (undefined4 *)0x0;
        local_45c[0] = (wchar_t **)((uint)local_45c[0] & 0xffff0000);
        local_8 = CONCAT31(local_8._1_3_,4);
        local_464 = 0x208;
        LVar4 = FUN_100014b7(&local_474,(LPBYTE)local_424,L"LanguageExt",&local_464);
        if (LVar4 == 0) {
          sVar5 = wcslen(local_21c);
          FID_conflict_assign(local_440,(undefined4 *)local_21c,sVar5);
          sVar5 = wcslen(local_424);
          FID_conflict_assign(local_45c,(undefined4 *)local_424,sVar5);
          puVar1 = local_44c;
          local_460 = (wchar_t **)0x5f;
          uVar9 = FUN_10005282(local_440,(ushort *)&local_460,0xffffffff,1);
          local_460 = (wchar_t **)0x2e;
          uVar6 = FUN_10005282(local_440,(ushort *)&local_460,0xffffffff,1);
          if ((uVar9 != 0xffffffff) && ((undefined4 *)((uVar6 - uVar9) + -1) == local_44c)) {
            local_460 = local_45c[0];
            if (local_448 < 8) {
              local_460 = (wchar_t **)local_45c;
            }
            puVar7 = (undefined4 *)wcslen((wchar_t *)local_460);
            FUN_1000b334(local_440,uVar9 + 1,puVar1,local_460,puVar7);
          }
          pppwVar8 = (wchar_t ***)local_440[0];
          if (local_42c < 8) {
            pppwVar8 = local_440;
          }
          wcscpy(local_21c,(wchar_t *)pppwVar8);
        }
        ATL::CRegKey::Close((CRegKey *)&local_474);
        local_8._0_1_ = 3;
        FID_conflict__Tidy(local_45c,'\x01',0);
      }
      local_8._0_1_ = 2;
      ATL::CRegKey::Close((CRegKey *)&local_474);
    }
    ATL::CRegKey::Close((CRegKey *)&local_480);
    pppwVar8 = (wchar_t ***)local_440[0];
    if (local_42c < 8) {
      pppwVar8 = local_440;
    }
    Value = LoadLibraryW((LPCWSTR)pppwVar8);
    if (Value != (HMODULE)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10030dac);
      InterlockedExchange(&DAT_10030d74,(LONG)Value);
      DAT_10030d70 = Value;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10030dac);
    }
  }
  local_8._0_1_ = 1;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_468);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_440,'\x01',0);
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_480);
  FUN_100173c1();
  return;
}



// Function: FUN_1000c3a2 at 1000c3a2

void __fastcall FUN_1000c3a2(void *param_1)

{
  FUN_1000b9f1(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000c3c9 at 1000c3c9

void __thiscall FUN_1000c3c9(void *this,undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int unaff_EDI;
  bool bVar5;
  void *local_c;
  void *local_8;
  
  local_c = this;
  local_8 = this;
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (((pcVar3 == (char *)((int)this + 0x48)) && (param_4 == 1)) &&
     (*(int *)((int)this + 0x44) == 0)) {
    bVar5 = param_2 != 0;
    param_2 = param_2 + -1;
    param_3 = param_3 + -1 + (uint)bVar5;
  }
  if ((((*(int *)((int)this + 0x54) != 0) && (cVar2 = FUN_1000ba35((int *)this), cVar2 != '\0')) &&
      (((param_2 == 0 && param_3 == 0 && (param_4 == 1)) ||
       (iVar4 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(param_4,param_3),unaff_EDI),
       iVar4 == 0)))) &&
     (iVar4 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c), iVar4 == 0)) {
    std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back
              ((basic_filebuf<char,struct_std::char_traits<char>_> *)this);
    param_1[2] = local_c;
    param_1[3] = local_8;
    uVar1 = *(undefined4 *)((int)this + 0x4c);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[4] = uVar1;
    return;
  }
  uVar1 = *(undefined4 *)(_BADOFF_exref + 4);
  *param_1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_1000c483 at 1000c483

void __thiscall
FUN_1000c483(void *this,undefined4 *param_1,int param_2,int param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_4;
  local_8 = param_5;
  if (*(int *)((int)this + 0x54) != 0) {
    cVar2 = FUN_1000ba35((int *)this);
    if (cVar2 != '\0') {
      iVar3 = fsetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c);
      if (iVar3 == 0) {
        if (param_2 != 0 || param_3 != 0) {
          iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(1,param_3),unaff_EDI);
          if (iVar3 != 0) goto LAB_1000c516;
        }
        iVar3 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c);
        if (iVar3 == 0) {
          *(undefined4 *)((int)this + 0x4c) = param_6;
          std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back
                    ((basic_filebuf<char,struct_std::char_traits<char>_> *)this);
          *param_1 = 0;
          param_1[1] = 0;
          param_1[2] = local_c;
          param_1[3] = local_8;
          uVar4 = *(undefined4 *)((int)this + 0x4c);
          goto LAB_1000c531;
        }
      }
    }
  }
LAB_1000c516:
  uVar1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = *(undefined4 *)(_BADOFF_exref + 4);
  uVar4 = 0;
  *param_1 = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
LAB_1000c531:
  param_1[4] = uVar4;
  return;
}



// Function: FUN_1000c53b at 1000c53b

basic_streambuf<char,struct_std::char_traits<char>_> * __fastcall
FUN_1000c53b(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char cVar1;
  int iVar2;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar3;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    cVar1 = FUN_1000ba35((int *)param_1);
    pbVar3 = param_1;
    if (cVar1 == '\0') {
      pbVar3 = (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
    }
    iVar2 = fclose(*(FILE **)(param_1 + 0x54));
    if (iVar2 == 0) goto LAB_1000c564;
  }
  pbVar3 = (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
LAB_1000c564:
  param_1[0x50] = (basic_streambuf<char,struct_std::char_traits<char>_>)0x0;
  param_1[0x49] = (basic_streambuf<char,struct_std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init(param_1);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x4c) = DAT_1002f894;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return pbVar3;
}



// Function: FUN_1000c586 at 1000c586

void __thiscall FUN_1000c586(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_1000c3a2(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_1000abe2((int *)&param_2);
      FUN_1000bb33(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000c5d9 at 1000c5d9

undefined4 * __thiscall FUN_1000c5d9(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  char cVar4;
  int *piVar5;
  void *local_c;
  void *pvStack_8;
  
  piVar2 = param_3;
  local_c = this;
  pvStack_8 = this;
  if (*(int *)((int)this + 8) == 0) {
    FUN_1000b61b(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)((int)this + 4);
  piVar5 = param_2;
  if (param_2 == (int *)*piVar1) {
    if (param_2[3] <= param_3[3]) goto LAB_1000c6a3;
    cVar4 = '\x01';
    goto LAB_1000c696;
  }
  if (param_2 == piVar1) {
    param_2 = (int *)piVar1[2];
    if (param_3[3] <= param_2[3]) goto LAB_1000c6a3;
  }
  else {
    if (param_3[3] < param_2[3]) {
      param_3 = param_2;
      FUN_1000a6ff((int *)&param_3);
      if (piVar2[3] <= param_3[3]) goto LAB_1000c65f;
      cVar4 = *(char *)(param_3[2] + 0x15);
      param_2 = param_3;
    }
    else {
LAB_1000c65f:
      if (piVar2[3] <= param_2[3]) {
LAB_1000c6a3:
        puVar3 = (undefined4 *)FUN_1000bd90(this,&local_c,piVar2,'\0');
        *param_1 = *puVar3;
        return param_1;
      }
      param_3 = param_2;
      FUN_1000abe2((int *)&param_3);
      if ((param_3 != *(int **)((int)this + 4)) && (param_3[3] <= piVar2[3])) goto LAB_1000c6a3;
      cVar4 = *(char *)(param_2[2] + 0x15);
      piVar5 = param_3;
    }
    if (cVar4 == '\0') {
      cVar4 = '\x01';
      goto LAB_1000c696;
    }
  }
  cVar4 = '\0';
  piVar5 = param_2;
LAB_1000c696:
  FUN_1000b61b(this,param_1,cVar4,piVar5,piVar2);
  return param_1;
}



// Function: FUN_1000c6bf at 1000c6bf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000c6bf(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_1000c0c1();
  return param_1;
}



// Function: FUN_1000c6f5 at 1000c6f5

void __fastcall FUN_1000c6f5(int *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = FUN_1000c53b((basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + 6));
  if (pbVar1 == (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(*param_1 + 4) + (int)param_1),2,false);
  }
  return;
}



// Function: FUN_1000c716 at 1000c716

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c716(basic_filebuf<char,struct_std::char_traits<char>_> *param_1)

{
  *(undefined ***)param_1 = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  if (*(int *)(param_1 + 0x54) != 0) {
    std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back(param_1);
  }
  if (param_1[0x50] != (basic_filebuf<char,struct_std::char_traits<char>_>)0x0) {
    FUN_1000c53b((basic_streambuf<char,struct_std::char_traits<char>_> *)param_1);
  }
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)param_1);
  return;
}



// Function: FUN_1000c75b at 1000c75b

basic_filebuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_1000c75b(void *this,byte param_1)

{
  FUN_1000c716((basic_filebuf<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_filebuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_1000c77a at 1000c77a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_1000c77a(undefined2 *param_1,wchar_t *param_2,undefined4 *param_3)

{
  size_t sVar1;
  
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  sVar1 = wcslen(param_2);
  FUN_10001cfa(param_1,param_3[4] + sVar1);
  sVar1 = wcslen(param_2);
  FUN_10001d33(param_1,(undefined4 *)param_2,sVar1);
  FUN_10001c55(param_1,param_3,0,0xffffffff);
  return param_1;
}



// Function: FUN_1000c7ec at 1000c7ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000c7ec(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 0xc;
  local_8 = 0x1000c7f8;
  piVar1 = FUN_1000abb6(this,param_1);
  if ((piVar1 == *(int **)((int)this + 4)) || (*piVar2 < piVar1[3])) {
    local_1c = *param_1;
    local_18 = 0;
    local_14 = 0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    piVar2 = (int *)FUN_1000b753(this,&local_1c);
    FUN_1000c5d9(this,&param_1,piVar1,piVar2);
    piVar1 = param_1;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(local_18);
    local_8 = 0xffffffff;
    Ordinal_6(0);
  }
  return piVar1 + 4;
}



// Function: FUN_1000c866 at 1000c866

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c866(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000c586(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000c8a0 at 1000c8a0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_iostream<char,struct_std::char_traits<char>_> * __thiscall
FUN_1000c8a0(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined **)this = &DAT_10021250;
    *(undefined ***)((int)this + 0x10) = &PTR_10021248;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + 0x70));
  }
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)this,
             (basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18));
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_fstream<char,struct_std::char_traits<char>_>::vftable;
  FUN_1000a8e3((basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18),0);
  return (basic_iostream<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_1000c90e at 1000c90e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c90e(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x70) + 4) + -0x70 + param_1) =
       std::basic_fstream<char,struct_std::char_traits<char>_>::vftable;
  FUN_1000c716((basic_filebuf<char,struct_std::char_traits<char>_> *)(param_1 + -0x58));
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)(param_1 + -0x58));
  return;
}



// Function: FUN_1000c94b at 1000c94b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_1000c94b(void *this,undefined4 param_1,undefined4 param_2)

{
  int *this_00;
  undefined1 *puVar1;
  CComBSTR *pCVar2;
  
  pCVar2 = (CComBSTR *)&param_2;
  this_00 = FUN_1000c7ec((void *)((int)this + 4),&param_1);
  FUN_10005519(this_00,pCVar2);
  puVar1 = &stack0xffffffd8;
  Ordinal_6();
  *(undefined4 *)(puVar1 + -4) = 0x1000c984;
  return;
}



// Function: FUN_1000c987 at 1000c987

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c987(void *param_1)

{
  FUN_1000c866(param_1);
  return;
}



// Function: FUN_1000c9a5 at 1000c9a5

void __fastcall FUN_1000c9a5(int param_1)

{
  FUN_1000c90e(param_1 + 0x70);
                    /* WARNING: Could not recover jumptable at 0x1000c9b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(param_1 + 0x70));
  return;
}



// Function: FUN_1000c9b9 at 1000c9b9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000c9b9(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000c9c5;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_1000ae74(param_1);
  return local_18;
}



// Function: FUN_1000c9e5 at 1000c9e5

void * __thiscall FUN_1000c9e5(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x70);
  FUN_1000c9a5((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_1000ca07 at 1000ca07

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000ca07(undefined4 *param_1)

{
  *param_1 = 0;
  FUN_1000c9b9((int)(param_1 + 1));
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000ca3d at 1000ca3d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000ca3d(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 local_24 [4];
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  *(undefined4 *)this = 0;
  local_8 = 1;
  local_14 = this;
  FUN_1000c9b9((int)this + 4);
  local_8._0_1_ = 2;
  FUN_10003c98(local_24);
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = (**(code **)*param_1)(param_1,&DAT_10021118,this);
  FUN_10004901(local_24,iVar1);
  return (undefined4 *)this;
}



// Function: FUN_1000ca95 at 1000ca95

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ca95(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000c866(param_1 + 1);
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000cae5 at 1000cae5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_1000cae5(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  undefined4 local_40 [3];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  wchar_t *local_28;
  undefined4 uStack_24;
  int local_20;
  int local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x1000caf1;
  FUN_10003c98(local_40);
  local_18[0] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  local_1c = *(int *)param_1[2];
  while (iVar4 = local_1c, local_1c != param_1[2]) {
    piVar1 = FUN_100101c3(&local_20,*(int *)(local_1c + 0xc));
    local_8._0_1_ = 3;
    iVar2 = FUN_10001378(local_18,*piVar1);
    if (-1 < iVar2) goto LAB_1000cb41;
    do {
      do {
        FUN_1000121b(iVar2);
LAB_1000cb41:
        local_8._0_1_ = 2;
        Ordinal_6(local_20);
        iVar2 = FUN_10001378(local_18,DAT_10030360);
      } while (iVar2 < 0);
      pwVar3 = ATL::CComBSTR::Copy((CComBSTR *)(iVar4 + 0x10));
      FUN_10001972(local_18,pwVar3);
      iVar2 = FUN_10001378(local_18,DAT_10030360);
    } while (iVar2 < 0);
    FUN_1000abe2(&local_1c);
  }
  Ordinal_8(&local_30);
  local_8._0_1_ = 4;
  local_30 = CONCAT22(local_30._2_2_,8);
  local_28 = ATL::CComBSTR::Copy((CComBSTR *)local_18);
  iVar4 = (**(code **)(*(int *)*param_1 + 0x1c))
                    ((int *)*param_1,local_30,uStack_2c,local_28,uStack_24);
  FUN_10004901(local_40,iVar4);
  FUN_1000c3a2(param_1 + 1);
  local_8._0_1_ = 2;
  Ordinal_9(&local_30);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_18[0]);
  return local_34;
}



// Function: Catch@1000cc01 at 1000cc01

undefined4 Catch_1000cc01(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000cbf4;
}



// Function: FUN_1000cc0b at 1000cc0b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000cc0b(wchar_t *param_1)

{
  LPCWSTR **pppWVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar5;
  undefined *puVar6;
  wchar_t *pwVar7;
  _func_basic_ostream<char,struct_std::char_traits<char>_>_ptr_basic_ostream<char,struct_std::char_traits<char>_>_ptr
  *p_Var8;
  int local_358 [4];
  basic_ostream<char,struct_std::char_traits<char>_> local_348 [96];
  basic_ios<char,struct_std::char_traits<char>_> local_2e8 [72];
  ulong local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_294;
  undefined2 local_290 [14];
  undefined4 local_274 [7];
  char **local_258 [5];
  uint local_244;
  LPCWSTR *local_23c [4];
  undefined4 local_22c;
  uint local_228;
  wchar_t local_220;
  undefined1 local_21e [534];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x348;
  local_29c = 0;
  local_298 = 0;
  local_294 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_228 = 7;
  local_22c = 0;
  local_23c[0] = (LPCWSTR *)((uint)local_23c[0] & 0xffff0000);
  FUN_10001dd5(local_23c,(undefined4 *)&DAT_10030364,0,0xffffffff);
  local_8._0_1_ = 2;
  pppWVar1 = (LPCWSTR **)local_23c[0];
  if (local_228 < 8) {
    pppWVar1 = local_23c;
  }
  iVar2 = Open(&local_29c,(HKEY)0x80000002,(LPCWSTR)pppWVar1,0x2001f);
  if (iVar2 == 0) {
    local_220 = L'\0';
    memset(local_21e,0,0x208);
    local_2a0 = 0x20a;
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_29c,L"UserSettings",&local_220,&local_2a0);
    if (lVar3 == 0) {
      FUN_1000c8a0(local_358,1);
      local_8._0_1_ = 3;
      FUN_1000c77a((undefined2 *)local_274,&local_220,(undefined4 *)&DAT_10030380);
      local_8._0_1_ = 4;
      FUN_1001067c((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_258,local_274);
      local_8._0_1_ = 5;
      if (local_244 < 0x10) {
        local_258[0] = (char **)local_258;
      }
      FUN_1000ae15(local_358,(char *)local_258[0],0xe,0x40);
      puVar4 = (undefined4 *)FUN_10010413(local_290,param_1);
      local_8._0_1_ = 6;
      if (7 < (uint)puVar4[5]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      pwVar7 = L"Activity Log Component initialization failed...";
      puVar6 = &DAT_10021258;
      p_Var8 = endl_exref;
      pbVar5 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_348,puVar4)
      ;
      pbVar5 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar5,puVar6);
      pbVar5 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar5,pwVar7);
      std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar5,p_Var8);
      local_8._0_1_ = 5;
      FID_conflict__Tidy(local_290,'\x01',0);
      FUN_1000c6f5(local_358);
      local_8._0_1_ = 4;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_258,true,0);
      local_8._0_1_ = 3;
      FID_conflict__Tidy(local_274,'\x01',0);
      local_8._0_1_ = 2;
      FUN_1000c90e((int)local_2e8);
      std::basic_ios<char,struct_std::char_traits<char>_>::
      ~basic_ios<char,struct_std::char_traits<char>_>(local_2e8);
    }
  }
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_23c,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  ATL::CRegKey::Close((CRegKey *)&local_29c);
  local_8 = 0xffffffff;
  Ordinal_6(param_1);
  FUN_100173c1();
  return;
}



// Function: FUN_1000ce35 at 1000ce35

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined * FUN_1000ce35(int *param_1)

{
  int *piVar1;
  AFX_MODULE_STATE *pAVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined *puVar5;
  undefined4 extraout_ECX;
  wchar_t *extraout_ECX_00;
  undefined4 uVar6;
  int aiStack_84 [5];
  int local_70 [5];
  undefined4 local_5c [5];
  AFX_MAINTAIN_STATE2 local_48 [16];
  undefined1 *local_38;
  int *local_34;
  int local_30;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_2c [4];
  undefined *local_28;
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> local_24 [4];
  uint local_20;
  int *local_1c;
  int *local_18 [4];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x1000ce41;
  pAVar2 = (AFX_MODULE_STATE *)FUN_10017051();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_48,pAVar2);
  piVar1 = param_1;
  local_8 = 0;
  local_34 = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))();
  }
  local_1c = (int *)0x0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_18[0] = (int *)0x0;
  local_8._0_1_ = 6;
  FUN_10001878(local_5c);
  local_8._0_1_ = 7;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_2c);
  local_8._0_1_ = 8;
  local_28 = (undefined *)(**(code **)*piVar1)();
  if ((int)local_28 < 0) {
    local_28 = (undefined *)(**(code **)*piVar1)(piVar1,&DAT_10021108);
    if ((int)local_28 < 0) {
      local_8._0_1_ = 7;
      ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
      ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_2c);
      local_8._0_1_ = 6;
      FUN_100018b8(local_5c);
      local_8._0_1_ = 4;
      if (local_18[0] != (int *)0x0) {
        (**(code **)(*local_18[0] + 8))();
      }
      local_8._0_1_ = 2;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      (**(code **)(*piVar1 + 8))();
      local_8 = 0xffffffff;
      AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_48);
      return (undefined *)0x80004005;
    }
    FUN_10001ba4(local_5c,local_18);
  }
  else {
    FUN_10001b71(local_5c,&local_1c);
  }
  local_20 = 0;
  iVar3 = FUN_1000117e((int)local_5c);
  if (iVar3 + 1U <= local_20) {
    local_8._0_1_ = 7;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>(local_2c);
    local_8._0_1_ = 6;
    FUN_100018b8(local_5c);
    local_8._0_1_ = 4;
    if (local_18[0] != (int *)0x0) {
      (**(code **)(*local_18[0] + 8))();
    }
    local_8._0_1_ = 2;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))();
    }
    local_8 = 0xffffffff;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_48);
    return local_28;
  }
  FUN_10002af7(local_5c,local_24);
  local_8._0_1_ = 0xc;
  pwVar4 = ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
           AllocSysString(local_24);
  if (pwVar4 == (wchar_t *)0x0) {
    param_1 = (int *)0x0;
  }
  else {
    param_1 = (int *)Ordinal_2();
    if (param_1 == (int *)0x0) {
      FUN_1000121b(-0x7ff8fff2);
      FUN_1000ca07(aiStack_84);
      local_8._0_1_ = 0x12;
      local_38 = &stack0xffffff5c;
      pwVar4 = extraout_ECX_00;
      ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff5c,(CComBSTR *)&param_1);
      local_8._0_1_ = 0x12;
      FUN_1000cc0b(pwVar4);
      local_8 = CONCAT31(local_8._1_3_,0x11);
      FUN_1000ca95(aiStack_84);
      return &DAT_1000cfc3;
    }
  }
  local_8._0_1_ = 0xe;
  FUN_1000ca3d(local_70,*(undefined4 **)(local_30 + 0x14));
  local_8._0_1_ = 0xf;
  local_38 = &stack0xffffff5c;
  uVar6 = extraout_ECX;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff5c,(CComBSTR *)&param_1);
  local_8._0_1_ = 0xf;
  FUN_1000c94b(local_70,0xf,uVar6);
  FUN_1000cae5(local_70);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_1000ca95(local_70);
  local_8 = 0xd;
  puVar5 = FUN_1000cfc5();
  return puVar5;
}



// Function: Catch@1000cf7f at 1000cf7f

undefined * Catch_1000cf7f(void)

{
  wchar_t *extraout_ECX;
  int unaff_EBP;
  wchar_t *pwVar1;
  
  FUN_1000ca07((undefined4 *)(unaff_EBP + -0x80));
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  *(undefined1 **)(unaff_EBP + -0x34) = &stack0xfffffffc;
  pwVar1 = extraout_ECX;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffffc,(CComBSTR *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  FUN_1000cc0b(pwVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_1000ca95((int *)(unaff_EBP + -0x80));
  *(undefined4 *)(unaff_EBP + -4) = 0xd;
  return &DAT_1000cfc3;
}



// Function: FUN_1000cfc5 at 1000cfc5

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined * FUN_1000cfc5(void)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined *puVar3;
  undefined4 extraout_ECX;
  wchar_t *extraout_ECX_00;
  wchar_t *unaff_EBX;
  int unaff_EBP;
  undefined4 uVar4;
  
  FUN_10001613(unaff_EBP + -0x58);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  Ordinal_6();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x20));
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
  iVar1 = FUN_1000117e(unaff_EBP + -0x58);
  if (iVar1 + 1U <= *(uint *)(unaff_EBP + -0x1c)) {
    *(undefined1 *)(unaff_EBP + -4) = 7;
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
              ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *
               )(unaff_EBP + -0x28));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_100018b8((undefined4 *)(unaff_EBP + -0x58));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (*(wchar_t **)(unaff_EBP + -0x14) != unaff_EBX) {
      (**(code **)(*(int *)*(wchar_t **)(unaff_EBP + -0x14) + 8))();
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (*(wchar_t **)(unaff_EBP + -0x18) != unaff_EBX) {
      (**(code **)(*(int *)*(wchar_t **)(unaff_EBP + -0x18) + 8))();
    }
    *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
    if (*(wchar_t **)(unaff_EBP + -0x30) != unaff_EBX) {
      (**(code **)(*(int *)*(wchar_t **)(unaff_EBP + -0x30) + 8))();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x44));
    return *(undefined **)(unaff_EBP + -0x24);
  }
  FUN_10002af7((void *)(unaff_EBP + -0x58),
               (CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *
               )(unaff_EBP + -0x20));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  pwVar2 = ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
           AllocSysString((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                           *)(unaff_EBP + -0x20));
  if (pwVar2 == unaff_EBX) {
    *(wchar_t **)(unaff_EBP + 8) = unaff_EBX;
  }
  else {
    pwVar2 = (wchar_t *)Ordinal_2();
    *(wchar_t **)(unaff_EBP + 8) = pwVar2;
    if (pwVar2 == unaff_EBX) {
      FUN_1000121b(-0x7ff8fff2);
      FUN_1000ca07((undefined4 *)(unaff_EBP + -0x80));
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      *(undefined1 **)(unaff_EBP + -0x34) = &stack0xfffffff8;
      pwVar2 = extraout_ECX_00;
      ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffff8,(CComBSTR *)(unaff_EBP + 8));
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      FUN_1000cc0b(pwVar2);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_1000ca95((int *)(unaff_EBP + -0x80));
      *(undefined4 *)(unaff_EBP + -4) = 0xd;
      return &DAT_1000cfc3;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_1000ca3d((void *)(unaff_EBP + -0x6c),*(undefined4 **)(*(int *)(unaff_EBP + -0x2c) + 0x14));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  *(undefined1 **)(unaff_EBP + -0x34) = &stack0xfffffff8;
  uVar4 = extraout_ECX;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xfffffff8,(CComBSTR *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_1000c94b((void *)(unaff_EBP + -0x6c),0xf,uVar4);
  FUN_1000cae5((undefined4 *)(unaff_EBP + -0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_1000ca95((int *)(unaff_EBP + -0x6c));
  *(undefined4 *)(unaff_EBP + -4) = 0xd;
  puVar3 = FUN_1000cfc5();
  return puVar3;
}



// Function: FUN_1000d0a9 at 1000d0a9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000d0a9(int param_1,int *param_2)

{
  AFX_MODULE_STATE *pAVar1;
  int iVar2;
  AFX_MAINTAIN_STATE2 local_30 [16];
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x1000d0b5;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10017051();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_30,pAVar1);
  local_8 = 0;
  local_20 = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 8;
  FUN_1000ce35(param_2);
  iVar2 = (**(code **)*param_2)(param_2,&DAT_100210f8,&local_1c);
  if (iVar2 < 0) {
    iVar2 = (**(code **)*param_2)(param_2,&DAT_10021108,&local_18);
    if (iVar2 < 0) {
      iVar2 = (**(code **)*param_2)(param_2,&DAT_1001fc1c,local_14);
      if (iVar2 < 0) {
        local_8._0_1_ = 6;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_8._0_1_ = 4;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        local_8._0_1_ = 2;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
      }
      else {
        iVar2 = FUN_1000be4f((int *)local_14);
        local_8._0_1_ = 6;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_8._0_1_ = 4;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        local_8._0_1_ = 2;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
      }
    }
    else {
      iVar2 = FUN_1000b81e((void *)(param_1 + -0xc),&local_18);
      local_8._0_1_ = 6;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      local_8._0_1_ = 4;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_8._0_1_ = 2;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
  }
  else {
    iVar2 = FUN_1000b7a3((void *)(param_1 + -0xc),&local_1c);
    local_8._0_1_ = 6;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    local_8._0_1_ = 4;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    local_8._0_1_ = 2;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  (**(code **)(*param_2 + 8))(param_2);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_30);
  return iVar2;
}



// Function: FUN_1000d269 at 1000d269

undefined ** FUN_1000d269(void)

{
  return &PTR_LAB_10021ce0;
}



// Function: FUN_1000d26f at 1000d26f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000d26f(undefined4 *param_1)

{
  FUN_1000c6bf((int)param_1);
  *param_1 = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  (**(code **)(*DAT_1002f230 + 4))();
  return param_1;
}



// Function: FUN_1000d2bd at 1000d2bd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000d2bd(undefined4 *param_1)

{
  FUN_100102db((int)param_1);
  *param_1 = ATL::CComObject<class_CProgressDlg>::vftable;
  param_1[1] = ATL::CComObject<class_CProgressDlg>::vftable;
  (**(code **)(*DAT_1002f230 + 4))();
  return param_1;
}



// Function: FUN_1000d2fd at 1000d2fd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000d2fd(int param_1)

{
  FUN_1000ad61(param_1);
  return;
}



// Function: FUN_1000d31b at 1000d31b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000d31b(int param_1)

{
  FUN_10010159(param_1);
  return;
}



// Function: FUN_1000d339 at 1000d339

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000d339(void *this,undefined4 param_1)

{
  FUN_1000c6bf((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CInformationServiceImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CInformationServiceImpl>::vftable
  ;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CInformationServiceImpl>::vftable
  ;
  *(undefined ***)((int)this + 0xc) =
       ATL::CComContainedObject<class_CInformationServiceImpl>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000d382 at 1000d382

undefined4 __fastcall FUN_1000d382(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000d386 at 1000d386

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000d386(void *this,undefined4 param_1)

{
  FUN_100102db((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CProgressDlg>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CProgressDlg>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000d3c1 at 1000d3c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000d3c1(void *this,byte param_1)

{
  FUN_10010159((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000d3f2 at 1000d3f2

bool __cdecl FUN_1000d3f2(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: FUN_1000d40c at 1000d40c

void __cdecl FUN_1000d40c(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  AfxCrtErrorCheck(eVar1);
  return;
}



// Function: AtlComQIPtrAssign at 1000d429

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



// Function: Attach at 1000d460

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



// Function: FUN_1000d47f at 1000d47f

undefined4 __fastcall FUN_1000d47f(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1000d483 at 1000d483

int __fastcall FUN_1000d483(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: FUN_1000d49a at 1000d49a

undefined4 __thiscall FUN_1000d49a(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_100303a8 = *param_3;
    DAT_100303ac = param_3[1];
    DAT_100303b0 = param_3[2];
    DAT_100303b4 = param_3[3];
  }
  piVar2 = DAT_10030ddc;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10030ddc, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10030ddc = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10030ddc;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10030de0; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_1000d4f8 at 1000d4f8

void FUN_1000d4f8(int param_1)

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



// Function: FUN_1000d53b at 1000d53b

uint __fastcall FUN_1000d53b(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 1;
}



// Function: FUN_1000d545 at 1000d545

uint __fastcall FUN_1000d545(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 2;
}



// Function: FUN_1000d54f at 1000d54f

uint __fastcall FUN_1000d54f(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 4;
}



// Function: FUN_1000d559 at 1000d559

uint __fastcall FUN_1000d559(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 8;
}



// Function: FUN_1000d563 at 1000d563

uint __fastcall FUN_1000d563(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 0x10;
}



// Function: FUN_1000d56d at 1000d56d

uint __fastcall FUN_1000d56d(int param_1)

{
  return *(uint *)(param_1 + 0xac) & 0x20;
}



// Function: FUN_1000d577 at 1000d577

undefined4 FUN_1000d577(void)

{
  return 0;
}



// Function: FUN_1000d57a at 1000d57a

undefined4 FUN_1000d57a(void)

{
  return 5000;
}



// Function: AtlAdd<unsigned_long> at 1000d5ca

/* Library Function - Single Match
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Release */

long __cdecl ATL::AtlAdd<unsigned_long>(ulong *param_1,ulong param_2,ulong param_3)

{
  if (-param_2 - 1 < param_3) {
    return -0x7ff8fdea;
  }
  *param_1 = param_2 + param_3;
  return 0;
}



// Function: AtlAddThrow<> at 1000d5ee

/* Library Function - Multiple Matches With Same Base Name
    unsigned int __cdecl ATL::AtlAddThrow<unsigned int>(unsigned int,unsigned int)
    unsigned long __cdecl ATL::AtlAddThrow<unsigned long>(unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Release */

ulong __cdecl AtlAddThrow<>(ulong param_1,ulong param_2)

{
  long lVar1;
  ulong local_8;
  
  lVar1 = ATL::AtlAdd<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_1000121b(lVar1);
  }
  return local_8;
}



// Function: FUN_1000d618 at 1000d618

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CWinApp * __thiscall FUN_1000d618(void *this,byte param_1)

{
  CWinApp::~CWinApp((CWinApp *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CWinApp *)this;
}



// Function: FUN_1000d649 at 1000d649

void __fastcall FUN_1000d649(CWinApp *param_1)

{
  FUN_1000d49a(&DAT_100303c8,(int *)&PTR_DAT_1002dae8,*(undefined4 *)(param_1 + 0x44),
               (undefined4 *)&DAT_10021c70);
  CWinApp::InitInstance(param_1);
  return;
}



// Function: DllCanUnloadNow at 1000d66b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT DllCanUnloadNow(void)

{
  AFX_MODULE_STATE *pAVar1;
  long lVar2;
  HRESULT HVar3;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
                    /* 0xd66b  1  DllCanUnloadNow */
  uStack_4 = 0x10;
  local_8 = 0x1000d677;
  pAVar1 = (AFX_MODULE_STATE *)FUN_10017051();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,pAVar1);
  HVar3 = 0;
  local_8 = 0;
  lVar2 = AfxDllCanUnloadNow();
  if ((lVar2 != 0) || (DAT_100303d0 != 0)) {
    HVar3 = 1;
  }
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return HVar3;
}



// Function: FUN_1000d6b2 at 1000d6b2

void FUN_1000d6b2(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d6e4 at 1000d6e4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d6e4(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000d26f(puVar1);
    }
    uVar2 = FUN_1000d749();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000d734 at 1000d734

undefined * Catch_1000d734(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d746;
}



// Function: FUN_1000d749 at 1000d749

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d749(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[4] = unaff_ESI[4] + 1;
    unaff_ESI[4] = unaff_ESI[4] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x14))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000d779 at 1000d779

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d779(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x184);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000d2bd(puVar1);
    }
    uVar2 = FUN_1000d7e1();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000d7cc at 1000d7cc

undefined * Catch_1000d7cc(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d7de;
}



// Function: FUN_1000d7e1 at 1000d7e1

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d7e1(void)

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



// Function: FUN_1000d811 at 1000d811

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000d811(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CInformationServiceImpl>::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_1000ad61((int)param_1);
  return;
}



// Function: FUN_1000d864 at 1000d864

undefined4 FUN_1000d864(int param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: Release at 1000d874

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  int *piVar1;
  ulong uVar2;
  int *in_stack_00000004;
  
  piVar1 = in_stack_00000004 + 4;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_stack_00000004[4];
  if ((*piVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x14))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 1000d895

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10021e80,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000d8af at 1000d8af

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000d8af(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CInformationServiceImpl>::vftable;
  FUN_1000d339((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1002f230 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000d8f2 at 1000d8f2

long FUN_1000d8f2(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10021e80,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000d93e at 1000d93e

void FUN_1000d93e(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_1000d951 at 1000d951

void FUN_1000d951(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_1000d964 at 1000d964

void FUN_1000d964(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))(*(undefined4 **)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_1000d97c at 1000d97c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000d97c(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CProgressDlg>::vftable;
  param_1[1] = ATL::CComObject<class_CProgressDlg>::vftable;
  param_1[2] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_10010159((int)param_1);
  return;
}



// Function: FUN_1000d9c1 at 1000d9c1

undefined4 FUN_1000d9c1(int param_1)

{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return *(undefined4 *)(param_1 + 8);
}



// Function: Release at 1000d9d1

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



// Function: QueryInterface at 1000d9f2

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10021f84,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000da0c at 1000da0c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000da0c(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CProgressDlg>::vftable;
  FUN_1000d386((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1002f230 + 4))();
  return (undefined4 *)this;
}



// Function: Release at 1000da4f

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



// Function: FUN_1000da70 at 1000da70

long FUN_1000da70(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10021f84,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000dabc at 1000dabc

void FUN_1000dabc(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_1000dad4 at 1000dad4

undefined4 * __thiscall FUN_1000dad4(void *this,byte param_1)

{
  FUN_1000d811((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000daf3 at 1000daf3

undefined4 * __thiscall FUN_1000daf3(void *this,byte param_1)

{
  FUN_1000d97c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000db12 at 1000db12

void FUN_1000db12(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000d964(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000db1c at 1000db1c

void FUN_1000db1c(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_1000db26 at 1000db26

void FUN_1000db26(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_1000db30 at 1000db30

void FUN_1000db30(int param_1)

{
  FUN_10006f94(param_1 + -4);
  return;
}



// Function: FUN_1000db3a at 1000db3a

void FUN_1000db3a(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000d964(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000db44 at 1000db44

void FUN_1000db44(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000db4e at 1000db4e

void FUN_1000db4e(int param_1)

{
  FUN_10006f81(param_1 + -4);
  return;
}



// Function: FUN_1000db58 at 1000db58

void FUN_1000db58(int param_1)

{
  FUN_1000d951(param_1 + -4);
  return;
}



// Function: FUN_1000db62 at 1000db62

void FUN_1000db62(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000db6c at 1000db6c

void FUN_1000db6c(int param_1)

{
  FUN_1000d951(param_1 + -8);
  return;
}



// Function: FUN_1000db76 at 1000db76

void FUN_1000db76(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000db80 at 1000db80

void FUN_1000db80(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000db8a at 1000db8a

void FUN_1000db8a(int param_1)

{
  FUN_1000d864(param_1 + -4);
  return;
}



// Function: FUN_1000db94 at 1000db94

void FUN_1000db94(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000dabc(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000db9e at 1000db9e

void FUN_1000db9e(int param_1)

{
  FUN_1000d951(param_1 + -0xc);
  return;
}



// Function: FUN_1000dba8 at 1000dba8

void FUN_1000dba8(int param_1)

{
  FUN_1000d93e(param_1 + -4);
  return;
}



// Function: FUN_1000dbb2 at 1000dbb2

void FUN_1000dbb2(int param_1)

{
  FUN_1000d864(param_1 + -8);
  return;
}



// Function: FUN_1000dbbc at 1000dbbc

void FUN_1000dbbc(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_1000dbc6 at 1000dbc6

void FUN_1000dbc6(int param_1)

{
  FUN_1000d93e(param_1 + -8);
  return;
}



// Function: FUN_1000dbd0 at 1000dbd0

void FUN_1000dbd0(int param_1)

{
  FUN_1000d9c1(param_1 + -4);
  return;
}



// Function: FUN_1000dbda at 1000dbda

void FUN_1000dbda(int param_1)

{
  FUN_1000d864(param_1 + -0xc);
  return;
}



// Function: FUN_1000dbe4 at 1000dbe4

void FUN_1000dbe4(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000d964(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000dbee at 1000dbee

void FUN_1000dbee(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_1000dbf8 at 1000dbf8

void FUN_1000dbf8(int param_1)

{
  FUN_1000d93e(param_1 + -0xc);
  return;
}



// Function: _AtlVerifyStackAvailable at 1000dc02

/* WARNING: Function: __SEH_prolog4_GS replaced with injection: SEH_prolog4 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    bool __cdecl ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(unsigned long)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

bool __cdecl ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(ulong param_1)

{
  undefined1 uVar1;
  long lVar2;
  undefined1 local_38 [4];
  ulong local_28;
  undefined1 local_21;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x1000dc0e;
  local_21 = 1;
  local_8 = 0;
  local_28 = 0;
  lVar2 = AtlAdd<unsigned_long>(&local_28,param_1,0x2000);
  if (lVar2 < 0) {
    local_21 = 0;
  }
  else {
    local_1c = local_38 + -local_28;
  }
  local_8 = 0xfffffffe;
  uVar1 = FUN_10017658();
  return (bool)uVar1;
}



// Function: FUN_1000dc78 at 1000dc78

int __fastcall FUN_1000dc78(int param_1)

{
  long lVar1;
  
  FUN_1000d483(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1002f230 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1003039c = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_1000dcb9 at 1000dcb9

void __fastcall FUN_1000dcb9(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_1000d4f8((int)piVar1);
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



// Function: FUN_1000dcf2 at 1000dcf2

void __fastcall FUN_1000dcf2(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_1000d4f8((int)piVar1);
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



// Function: FUN_1000dcf7 at 1000dcf7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000dcf7(int param_1)

{
  FUN_1000dcb9(param_1);
  return;
}



// Function: FUN_1000dd15 at 1000dd15

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000dd15(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x1000dd24;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_1000deef;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000640e();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_1000dd82;
      FUN_1000d40c(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        AfxCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_1000debf;
      }
    }
    else {
LAB_1000debf:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_1000dd82:
  local_8 = 0xffffffff;
  FUN_10006d61(&local_248);
LAB_1000deef:
  FUN_100173c1();
  return;
}



// Function: FUN_1000def7 at 1000def7

void __fastcall FUN_1000def7(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10030ddc;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10030ddc, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10030de0; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_1000dcb9(param_1);
  return;
}



// Function: FUN_1000df49 at 1000df49

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000df49(void *this,wchar_t *param_1)

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
  uStack_4 = 0x18;
  local_8 = 0x1000df55;
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
      local_18 = (uint *)FUN_10016bb7(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_1000d580,
                   (_func_void_void_ptr *)&LAB_1000d5a9);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_1000e001();
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



// Function: Catch@1000dfe9 at 1000dfe9

undefined * Catch_1000dfe9(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000dffb;
}



// Function: FUN_1000e001 at 1000e001

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e001(void)

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



// Function: FUN_1000e0b9 at 1000e0b9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000e0b9(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_1000d5a9);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_1000e116 at 1000e116

void FUN_1000e116(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_1000e0b9(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_1000e149 at 1000e149

undefined4 * __thiscall FUN_1000e149(void *this,ulong param_1)

{
  ulong _Size;
  undefined4 *puVar1;
  
  _Size = AtlAddThrow<>(param_1,8);
  puVar1 = (undefined4 *)malloc(_Size);
  if (puVar1 != (undefined4 *)0x0) {
                    /* WARNING: Load size is inaccurate */
    *puVar1 = *this;
    *(undefined4 **)this = puVar1;
    puVar1 = puVar1 + 2;
  }
  return puVar1;
}



// Function: FUN_1000e175 at 1000e175

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_1000e175(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_10020238,&local_18);
    (**(code **)*param_1)(param_1,&DAT_10020238,local_14);
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



// Function: FUN_1000e200 at 1000e200

int __fastcall FUN_1000e200(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_1000e204 at 1000e204

int __fastcall FUN_1000e204(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_1000e208 at 1000e208

void __fastcall FUN_1000e208(CWinApp *param_1)

{
  FUN_1000def7(0x100303c8);
  CWinApp::ExitInstance(param_1);
  return;
}



// Function: FUN_1000e21d at 1000e21d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e21d(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x20);
    if (this != (void *)0x0) {
      FUN_1000d8af(this,param_1);
    }
    uVar1 = FUN_1000e28c();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000e277 at 1000e277

undefined * Catch_1000e277(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e289;
}



// Function: FUN_1000e28c at 1000e28c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e28c(void)

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



// Function: FUN_1000e2b6 at 1000e2b6

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e2b6(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x18c);
    if (this != (void *)0x0) {
      FUN_1000da0c(this,param_1);
    }
    uVar1 = FUN_1000e328();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000e313 at 1000e313

undefined * Catch_1000e313(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e325;
}



// Function: FUN_1000e328 at 1000e328

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e328(void)

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



// Function: FUN_1000e352 at 1000e352

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e352(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



// Function: FUN_1000e38a at 1000e38a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e38a(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CInformationServiceImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_1000ad61((int)(param_1 + 2));
  return;
}



// Function: FUN_1000e3d0 at 1000e3d0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e3d0(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CProgressDlg>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_10010159((int)(param_1 + 2));
  return;
}



// Function: FUN_1000e416 at 1000e416

undefined4 * __thiscall FUN_1000e416(void *this,byte param_1)

{
  FUN_1000e38a((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e435 at 1000e435

undefined4 * __thiscall FUN_1000e435(void *this,byte param_1)

{
  FUN_1000e3d0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e454 at 1000e454

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e454(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if ((*(byte *)(param_1 + 0x14) & 2) != 0) {
    for (piVar2 = *(int **)(param_1 + 8); piVar2 != *(int **)(param_1 + 0xc); piVar2 = piVar2 + 1) {
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
    operator_delete__(*(void **)(param_1 + 8));
  }
  piVar2 = *(int **)(param_1 + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return;
}



// Function: FUN_1000e4b1 at 1000e4b1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_1000e4b1(undefined4 *param_1)

{
  FUN_1000dc78((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_100303b8 = param_1;
  return param_1;
}



// Function: FUN_1000e4e6 at 1000e4e6

void __fastcall FUN_1000e4e6(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000e4f1 at 1000e4f1

void __fastcall FUN_1000e4f1(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000e4fc at 1000e4fc

HRESULT __thiscall FUN_1000e4fc(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1002300c,(LPUNKNOWN)0x0,1,(IID *)&DAT_1002212c,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_1000e548 at 1000e548

undefined4 FUN_1000e548(void)

{
  return 0x80004005;
}



// Function: FUN_1000e550 at 1000e550

void FUN_1000e550(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&PTR_1001fc90);
  return;
}



// Function: FUN_1000e56a at 1000e56a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000e56a(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_1000dcb9((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e5a1 at 1000e5a1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000e5a1(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_10022ffc), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_1002301c,(LPUNKNOWN)0x0,1,(IID *)&DAT_100221b4,&local_1a8
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
          goto LAB_1000e82c;
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
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Required Categories");
      AfxCrtErrorCheck(eVar4);
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
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      AfxCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Implemented Categories");
      AfxCrtErrorCheck(eVar4);
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
      FUN_10006d61(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_1000e82c:
  FUN_100173c1();
  return;
}



// Function: FUN_1000e8bf at 1000e8bf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000e8bf(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_1000dd15(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10006c9e((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_1000e98f at 1000e98f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000e98f(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_1000dd15(param_1,param_2,&local_22c,&local_228);
  if (-1 < iVar2) {
    pWVar6 = (WCHAR *)0x0;
    local_224 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar2 = (**(code **)(*local_228 + 0x24))(local_228,0xffffffff,0,0,0,&local_224);
    if ((-1 < iVar2) && (local_224 != (wchar_t *)0x0)) {
      _MaxCount = Ordinal_7(local_224);
      eVar3 = wcsncpy_s(local_21c,0x104,local_224,_MaxCount);
      AfxCrtErrorCheck(eVar3);
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
    iVar2 = FUN_10006c9e(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_1000eb51;
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
LAB_1000eb51:
  FUN_100173c1();
  return;
}



// Function: FUN_1000eb59 at 1000eb59

int FUN_1000eb59(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000d3f2(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_1000e5a1((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_1000e98f(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000ebdf at 1000ebdf

int FUN_1000ebdf(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000d3f2(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_1000e5a1((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_1000e8bf(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000ec66 at 1000ec66

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_1000ec66(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_10020238,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_1000ed21;
          }
          else {
LAB_1000ed21:
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



// Function: FUN_1000ed51 at 1000ed51

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000ed51(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_1000eda1();
  return uVar1;
}



// Function: Catch@1000ed89 at 1000ed89

undefined * Catch_1000ed89(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ed9b;
}



// Function: FUN_1000eda1 at 1000eda1

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000eda1(void)

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
    *(LPCRITICAL_SECTION *)(unaff_EBP + -0x20) = lpCriticalSection;
    *(undefined1 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    EnterCriticalSection(lpCriticalSection);
    *(undefined1 *)(unaff_EBP + -0x1c) = 1;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    unaff_ESI[2] = *(undefined4 *)(unaff_EDI + 8);
    *(undefined4 **)(unaff_EDI + 8) = unaff_ESI;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    LeaveCriticalSection(lpCriticalSection);
    *(undefined1 *)(unaff_EBP + -0x1c) = 0;
  }
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_1000edfc at 1000edfc

IUnknown * __thiscall FUN_1000edfc(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_1000e175(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_10022214);
  }
  return pIVar2;
}



// Function: FUN_1000ee29 at 1000ee29

void FUN_1000ee29(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000d6e4(0,param_2,param_3);
    return;
  }
  FUN_1000e21d(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000ee49 at 1000ee49

void FUN_1000ee49(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000d779(0,param_2,param_3);
    return;
  }
  FUN_1000e2b6(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000ee69 at 1000ee69

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ee69(int param_1)

{
  FUN_1000e454(param_1);
  return;
}



// Function: FUN_1000ee87 at 1000ee87

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000ee87(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10030de4);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_10020238,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10030de4);
          if (*piVar2 != 0) goto LAB_1000ef1b;
        }
        else {
LAB_1000ef1b:
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
  piVar2 = FUN_1000ec66((int *)&DAT_10030dd4,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_1000ef53 at 1000ef53

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000ef53(void *this,undefined4 param_1)

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
  local_8 = 0x1000ef62;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_1000f198;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1002f230 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_100303a8,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_10030d70,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_1000f162;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10006d61((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_100220bc,&local_224);
        if (-1 < iVar2) {
          FUN_1000edfc(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_1002f230 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_1002f230 + 4;
        }
        pcVar4 = FUN_1000e116;
        pvVar5 = this;
        FUN_1000ed51(iVar2);
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
LAB_1000f162:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_1000df49(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_1000f198:
  FUN_100173c1();
  return;
}



// Function: FUN_1000f1a0 at 1000f1a0

void FUN_1000f1a0(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000eb59(0x10030dd4,param_1,param_2);
  if ((-1 < iVar1) && (DAT_100303a0 != (code *)0x0)) {
    (*DAT_100303a0)(DAT_10030d70);
  }
  return;
}



// Function: FUN_1000f1ce at 1000f1ce

void FUN_1000f1ce(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_100303a4 != (code *)0x0) && (iVar1 = (*DAT_100303a4)(), iVar1 < 0)) {
    return;
  }
  FUN_1000ebdf(0x10030dd4,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 1000f1f4

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0xf1f4  2  DllGetClassObject */
  piVar1 = FUN_1000ee87(&DAT_100303c8,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_1000f202 at 1000f202

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000f202(undefined4 *param_1)

{
  FUN_1001386d((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_1002f230 + 4))();
  return param_1;
}



// Function: FUN_1000f23b at 1000f23b

undefined4 FUN_1000f23b(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// Function: FUN_1000f24d at 1000f24d

bool FUN_1000f24d(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 4;
  return param_2 != uVar1;
}



// Function: FUN_1000f27a at 1000f27a

undefined4 FUN_1000f27a(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: Release at 1000f28a

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  int *piVar1;
  ulong uVar2;
  int *in_stack_00000004;
  
  piVar1 = in_stack_00000004 + 6;
  *piVar1 = *piVar1 + -1;
  uVar2 = in_stack_00000004[6];
  if ((*piVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x1c))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 1000f2ab

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10022248,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000f2c5 at 1000f2c5

uint FUN_1000f2c5(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = param_2;
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  if ((param_3 == (int *)0x0) || ((1 < param_2 && (param_4 == (uint *)0x0)))) {
    param_2 = 0x80004003;
  }
  else if (((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
          (*(int *)(param_1 + 0x10) == 0)) {
    param_2 = 0x80004005;
  }
  else {
    uVar2 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
    bVar5 = uVar2 <= param_2;
    param_2 = (uint)(uVar2 < param_2);
    if (bVar5) {
      uVar4 = uVar2;
    }
    piVar3 = param_3;
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar4;
    }
    while (uVar4 != 0) {
      uVar4 = uVar4 - 1;
      uVar2 = FUN_100121f0(piVar3,*(int **)(param_1 + 0x10));
      if ((int)uVar2 < 0) {
        for (; param_3 < piVar3; param_3 = param_3 + 1) {
          piVar1 = (int *)*param_3;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
        }
        if (param_4 == (uint *)0x0) {
          return uVar2;
        }
        *param_4 = 0;
        return uVar2;
      }
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 4;
      piVar3 = piVar3 + 1;
    }
  }
  return param_2;
}



// Function: FUN_1000f383 at 1000f383

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000f383(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_1000e454((int)param_1);
  return;
}



// Function: FUN_1000f3c1 at 1000f3c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000f3c1(undefined4 *param_1)

{
  FUN_100072e6(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_1000f3ef at 1000f3ef

LONG FUN_1000f3ef(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1002f230 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 1000f42e

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10020fe4,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000f448 at 1000f448

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000f448(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100076d6(param_1);
  return;
}



// Function: FUN_1000f477 at 1000f477

undefined4 * __thiscall FUN_1000f477(void *this,byte param_1)

{
  FUN_1000f448((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f496 at 1000f496

undefined4 * __thiscall FUN_1000f496(void *this,byte param_1)

{
  FUN_1000f383((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f4b5 at 1000f4b5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000f4b5(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000f202(puVar1);
    }
    uVar2 = FUN_1000f518();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000f501 at 1000f501

undefined * Catch_1000f501(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000f513;
}



// Function: FUN_1000f518 at 1000f518

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000f518(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x14) != unaff_EDI) {
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
  }
  *unaff_ESI = *(int *)(unaff_EBP + -0x14);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000f52f at 1000f52f

int __thiscall FUN_1000f52f(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000d3f2(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_1000e5a1((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_1000f1a0(param_1,param_2);
  return iVar5;
}



// Function: FUN_1000f59e at 1000f59e

int __thiscall FUN_1000f59e(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000d3f2(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_1000e5a1((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_1000f1ce(param_1,param_2);
  return iVar5;
}



// Function: FUN_1000f60d at 1000f60d

undefined4 __thiscall FUN_1000f60d(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_1000ef53(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_1000f64d at 1000f64d

undefined4 __thiscall
FUN_1000f64d(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_1000ef53(this,param_4);
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



// Function: FUN_1000f6ee at 1000f6ee

void __thiscall
FUN_1000f6ee(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_1000ef53(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: DllRegisterServer at 1000f731

void DllRegisterServer(void)

{
                    /* 0xf731  3  DllRegisterServer */
  FUN_1000f52f(&DAT_100303c8,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 1000f740

void DllUnregisterServer(void)

{
                    /* 0xf740  4  DllUnregisterServer */
  FUN_1000f59e(&DAT_100303c8,1,(void *)0x0);
  return;
}



// Function: FUN_1000f74f at 1000f74f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000f74f(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000f202(puVar1);
    }
    FUN_1000f7b6();
    return;
  }
  FUN_100173d0();
  return;
}



// Function: Catch@1000f79f at 1000f79f

undefined * Catch_1000f79f(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000f7b1;
}



// Function: FUN_1000f7b6 at 1000f7b6

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000f7b6(void)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != unaff_EBX) {
    *(int **)(unaff_EBP + -0x1c) = unaff_EBX;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(int **)(unaff_EBP + -0x18) = unaff_EBX;
    lVar3 = ATL::AtlMultiply<unsigned_long>((ulong *)(unaff_EBP + -0x18),4,(ulong)unaff_EBX);
    if ((int)unaff_EBX <= lVar3) {
      uVar1 = *(uint *)(unaff_EBP + -0x18);
      if ((uVar1 < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(uVar1), bVar2)) {
        *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
      }
      else {
        register0x00000010 = (BADSPACEBASE *)FUN_1000e149((void *)(unaff_EBP + -0x1c),uVar1);
      }
      if ((int *)register0x00000010 == unaff_EBX) {
        (**(code **)(*unaff_ESI + 0x1c))(1);
      }
      else {
        iVar4 = FUN_10013897(unaff_ESI,(int)register0x00000010,(int)register0x00000010,
                             *(int **)(unaff_EBP + 8),3);
        if ((iVar4 < (int)unaff_EBX) || (iVar4 = (**(code **)*unaff_ESI)(), iVar4 < (int)unaff_EBX))
        {
          (**(code **)(*unaff_ESI + 0x1c))(1);
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10006d61((int *)(unaff_EBP + -0x1c));
  }
  *(undefined4 *)(unaff_EBP + -0x38) = 0x1000f771;
  FUN_100173d0();
  return;
}



// Function: FUN_1000f86b at 1000f86b

undefined4 FUN_1000f86b(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000f60d(&PTR_DAT_1002e2fc,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000f88f at 1000f88f

void FUN_1000f88f(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000f64d(&PTR_DAT_1002e2fc,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000f8af at 1000f8af

void FUN_1000f8af(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_1000f6ee(&PTR_DAT_1002e2fc,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: Catch@1000f91b at 1000f91b

undefined1 * Catch_1000f91b(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000f92d;
}



// Function: FUN_1000f975 at 1000f975

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000f975(int *param_1,void **param_2)

{
  int *piVar1;
  int *local_1c;
  int local_18;
  uint local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xc;
  local_8 = 0x1000f981;
  local_14 = 0;
  local_18 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    local_18 = FUN_1000f4b5(&local_1c);
    if (-1 < local_18) {
      if ((*(byte *)(param_1 + 5) & 2) == 0) {
        param_1 = (int *)param_1[1];
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 4))(param_1);
        }
        local_8 = 3;
        local_14 = 2;
      }
      else {
        (**(code **)(*param_1 + 4))(param_1);
        local_8 = 1;
        local_14 = 1;
      }
      local_18 = FUN_10013897(local_1c,piVar1[2],piVar1[3],param_1,0);
      if ((local_14 & 2) != 0) {
        local_14 = local_14 & 0xfffffffd;
        local_8 = 1;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      local_8 = 0xffffffff;
      if ((local_14 & 1) != 0) {
        local_14 = local_14 & 0xfffffffe;
        local_8 = 0xffffffff;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      if (-1 < local_18) {
        local_1c[4] = piVar1[4];
        local_18 = ATL::AtlInternalQueryInterface
                             (local_1c,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10022248,(_GUID *)&DAT_10022260
                              ,param_2);
        if (-1 < local_18) {
          return local_18;
        }
      }
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 0x1c))(1);
      }
    }
  }
  return local_18;
}



// Function: FUN_1000fa88 at 1000fa88

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000fa88(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10006d61(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10008c95(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10006d61(local_14);
  }
  return uVar1;
}



// Function: FUN_1000fae4 at 1000fae4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000fae4(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10006d61(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10008c95(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10006d61(local_14);
  }
  return uVar1;
}



// Function: FUN_1000fb3f at 1000fb3f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000fb3f(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_10007cf1(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_10030d70;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10030d70,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000640e();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10006d61((int *)&local_a48);
        goto LAB_1000fbc1;
      }
      FUN_100066b0(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10006397(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10006d61((int *)&local_a48);
          goto LAB_1000fbc1;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10007cf1(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10007cf1(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_1000fae4(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_1000fa88(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10006d61((int *)&local_a48);
  }
LAB_1000fbc1:
  local_8 = 0xffffffff;
  FUN_100073c7(&local_a60);
  FUN_100173c1();
  return;
}



// Function: FUN_1000fd42 at 1000fd42

void FUN_1000fd42(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_1000fb3f(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000fd4b at 1000fd4b

void FUN_1000fd4b(int param_1)

{
  FUN_10008e88((int *)&DAT_100303c8,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000fd63 at 1000fd63

void FUN_1000fd63(int param_1)

{
  FUN_10008e88((int *)&DAT_100303c8,0x6e,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000fd7b at 1000fd7b

bool __cdecl FUN_1000fd7b(int param_1)

{
  return param_1 != 0;
}



// Function: FUN_1000fd88 at 1000fd88

void __cdecl FUN_1000fd88(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_1000fda9 at 1000fda9

undefined4 FUN_1000fda9(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  if (param_3 == 0) {
    uVar2 = 0x80004003;
  }
  else {
    FUN_10010730((void *)(param_1 + 8),param_3);
    bVar1 = FUN_10010c60((void *)(param_1 + 8),param_2);
    if (bVar1) {
      uVar2 = 0;
    }
  }
  return uVar2;
}



// Function: FUN_1000fde5 at 1000fde5

undefined4 FUN_1000fde5(int param_1,undefined2 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_2 = 0;
    cVar1 = FUN_10010847(param_1 + 8);
    if (cVar1 != '\0') {
      *param_2 = 0xffff;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000fe18 at 1000fe18

undefined4 FUN_1000fe18(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  cVar1 = FUN_100106d2((void *)(param_1 + 8),param_2 == 1);
  if (cVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000fe44 at 1000fe44

undefined4 FUN_1000fe44(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  uVar1 = FUN_10010813((void *)(param_1 + 8),param_2 == 1);
  if ((char)uVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000fe70 at 1000fe70

undefined4 FUN_1000fe70(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  cVar1 = FUN_10010701((void *)(param_1 + 8),param_2 == 1);
  if (cVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000fe9c at 1000fe9c

undefined4 FUN_1000fe9c(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  uVar1 = FUN_100107c0((void *)(param_1 + 8),param_2 == 1);
  if ((char)uVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000fec8 at 1000fec8

undefined4 FUN_1000fec8(int param_1,undefined2 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_2 = 0;
    bVar1 = FUN_100106ca(param_1 + 8);
    if (bVar1) {
      *param_2 = 0xffff;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000fefb at 1000fefb

undefined4 FUN_1000fefb(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    FUN_1001074c((void *)(param_1 + 8),param_3);
    FUN_1001075d((void *)(param_1 + 8),&param_2);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ff2d at 1000ff2d

undefined4 FUN_1000ff2d(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    FUN_10010730((void *)(param_1 + 8),param_2);
    FUN_10010ce1((void *)(param_1 + 8));
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ff5b at 1000ff5b

undefined4 FUN_1000ff5b(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    FUN_10010730((void *)(param_1 + 8),param_3);
    FUN_10010c60((void *)(param_1 + 8),*param_3 + param_2);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ff90 at 1000ff90

undefined4 FUN_1000ff90(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  uVar1 = FUN_1001076e((void *)(param_1 + 8),param_2,param_3);
  if ((char)uVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000ffb7 at 1000ffb7

undefined4 FUN_1000ffb7(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  uVar1 = FUN_10010bf4((void *)(param_1 + 8),param_2);
  if ((char)uVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000ffdb at 1000ffdb

undefined4 FUN_1000ffdb(int param_1,HWND param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80004005;
  bVar1 = FUN_1000fd7b(param_3);
  uVar2 = FUN_10016929((void *)(param_1 + 8),param_2,bVar1);
  if ((char)uVar2 != '\0') {
    uVar3 = 0;
  }
  return uVar3;
}



// Function: FUN_1001000e at 1001000e

undefined4 FUN_1001000e(int param_1)

{
  FUN_10010b84(param_1 + 8);
  return 0;
}



// Function: FUN_10010022 at 10010022

undefined4 FUN_10010022(int param_1,int param_2)

{
  FUN_10010853((void *)(param_1 + 8),param_2 != 0);
  return 0;
}



// Function: FUN_10010041 at 10010041

undefined4 FUN_10010041(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  iVar1 = FUN_10010863((void *)(param_1 + 8),param_2 == 1);
  if ((char)iVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1001006d at 1001006d

undefined4 FUN_1001006d(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  uVar1 = FUN_1001087f((void *)(param_1 + 8),(undefined4 *)&stack0x00000008,
                       (undefined4 *)&stack0x0000000c);
  if ((char)uVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10010096 at 10010096

undefined4 FUN_10010096(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  cVar1 = FUN_100108ae((void *)(param_1 + 8),param_2);
  if (cVar1 != '\0') {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: AtlW2AHelper at 100100ba

/* Library Function - Multiple Matches With Same Base Name
    char * __stdcall AtlW2AHelper(char *,unsigned short const *,int,unsigned int)
    char * __stdcall AtlW2AHelper(char *,wchar_t const *,int,unsigned int)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

uint AtlW2AHelper(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 == (LPSTR)0x0) || (param_2 == (LPCWSTR)0x0)) {
    uVar2 = 0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    uVar2 = -(uint)(iVar1 != 0) & (uint)param_1;
  }
  return uVar2;
}



// Function: _Inside at 100100f2

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



// Function: FUN_1001012d at 1001012d

undefined4 FUN_1001012d(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_1002e318 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_10010159 at 10010159

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10010159(int param_1)

{
  FUN_1001120c((undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_1001017a at 1001017a

undefined2 * __thiscall FUN_1001017a(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_10010191;
  while( true ) {
    FUN_1000121b(iVar1);
LAB_10010191:
    *(undefined2 *)this = 8;
    iVar1 = Ordinal_2(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (param_1 == 0)) break;
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
  return (undefined2 *)this;
}



// Function: FUN_100101c3 at 100101c3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __cdecl FUN_100101c3(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined2 local_24 [4];
  int local_1c;
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_14 = 0;
  local_24[0] = 3;
  local_1c = param_2;
  local_8 = 1;
  FUN_1000fd88(8,(int)local_24,0,0x409);
  if (local_1c == 0) {
    *param_1 = 0;
  }
  else {
    iVar2 = Ordinal_2(local_1c);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      FUN_1000121b(-0x7ff8fff2);
      pcVar1 = (code *)swi(3);
      piVar3 = (int *)(*pcVar1)();
      return piVar3;
    }
  }
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(local_24);
  return param_1;
}



// Function: FUN_1001023a at 1001023a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __cdecl FUN_1001023a(int *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar2 = Ordinal_2(param_2);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      FUN_1000121b(-0x7ff8fff2);
      pcVar1 = (code *)swi(3);
      piVar3 = (int *)(*pcVar1)();
      return piVar3;
    }
  }
  return param_1;
}



// Function: FUN_1001028c at 1001028c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1001028c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_2(&PTR_1001fc90);
  if (iVar1 == 0) {
    FUN_1000121b(-0x7ff8fff2);
  }
  uVar2 = (**(code **)(*param_1 + 0x20))(param_1,iVar1);
  Ordinal_6(iVar1);
  return uVar2;
}



// Function: FUN_100102db at 100102db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_100102db(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_1001167b((undefined4 *)(param_1 + 0xc));
  return param_1;
}



// Function: FUN_10010304 at 10010304

undefined4 * __thiscall FUN_10010304(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_1000acd0(this,_Size + uVar4,0xffffffff);
    FUN_1000acd0(this,0,param_2);
  }
  else {
    bVar1 = FUN_1000b170(this,_Size,'\0');
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



// Function: assign at 1001039e

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
           FUN_10010304(this,(undefined4 *)this,(int)param_1 - (int)pbVar2,param_2);
  }
  else {
    bVar1 = FUN_1000b170(this,param_2,'\0');
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



// Function: FUN_10010413 at 10010413

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10010413(undefined2 *param_1,wchar_t *param_2)

{
  if (param_2 == (wchar_t *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    FUN_10002350(param_1,param_2);
  }
  return param_1;
}



// Function: FUN_10010465 at 10010465

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10010465(int param_1,wchar_t *param_2)

{
  int iVar1;
  int *piVar2;
  int *extraout_ECX;
  int local_38;
  int local_30 [10];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10010471;
  if (param_2 == (wchar_t *)0x0) {
    local_38 = 0;
LAB_10010485:
    local_8 = 0;
    iVar1 = Ordinal_7(local_38);
    local_8 = 0xffffffff;
    Ordinal_6(local_38);
    piVar2 = local_30;
    if (iVar1 == 0) {
      piVar2 = (int *)FUN_10002350(piVar2,L" ");
      local_8 = 1;
      FUN_100152b4((void *)(param_1 + 8),piVar2);
      local_8 = 0xffffffff;
      FID_conflict__Tidy(local_30,'\x01',0);
      goto LAB_10010521;
    }
  }
  else {
    local_38 = Ordinal_2(param_2);
    if (local_38 != 0) goto LAB_10010485;
    FUN_1000121b(-0x7ff8fff2);
    piVar2 = extraout_ECX;
  }
  FUN_10002350(piVar2,param_2);
  local_8 = 2;
  FUN_100152b4((void *)(param_1 + 8),local_30);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
LAB_10010521:
  FUN_100173c1();
  return;
}



// Function: FUN_1001052c at 1001052c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1001052c(int param_1,wchar_t *param_2)

{
  undefined4 local_30 [10];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10010538;
  FUN_10002350(local_30,param_2);
  local_8 = 0;
  FUN_10015360((void *)(param_1 + 8),local_30);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100173c1();
  return;
}



// Function: FUN_1001057e at 1001057e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1001057e(int param_1,wchar_t *param_2)

{
  undefined4 local_30 [10];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x1001058a;
  FUN_10002350(local_30,param_2);
  local_8 = 0;
  FUN_10015329((void *)(param_1 + 8),local_30);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100173c1();
  return;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 100105d0

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



// Function: FUN_100105ff at 100105ff

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl
FUN_100105ff(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            LPCWSTR param_2)

{
  int iVar1;
  char *pcVar2;
  CHAR local_28 [16];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x1001060b;
  local_18 = 0;
  if (param_2 == (LPCWSTR)0x0) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  }
  else {
    iVar1 = lstrlenW(param_2);
    if (iVar1 + 1 < 0x40000000) {
      pcVar2 = (char *)AtlW2AHelper(local_28,param_2,(iVar1 + 1) * 2,3);
    }
    else {
      pcVar2 = (char *)0x0;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1,pcVar2);
  }
  local_8 = 0;
  local_18 = 1;
  FUN_100173c1();
  return;
}



// Function: FUN_1001067c at 1001067c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __cdecl
FUN_1001067c(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            undefined4 *param_2)

{
  int *piVar1;
  int local_18 [4];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10010688;
  local_18[1] = 0;
  piVar1 = FUN_1001023a(local_18,param_2);
  local_8 = 1;
  FUN_100105ff(param_1,(LPCWSTR)*piVar1);
  local_18[1] = 1;
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(local_18[0]);
  return param_1;
}



// Function: FUN_100106c4 at 100106c4

undefined * FUN_100106c4(void)

{
  return &DAT_1002237c;
}



// Function: FUN_100106ca at 100106ca

bool __fastcall FUN_100106ca(int param_1)

{
  return *(int *)(param_1 + 4) != 0;
}



// Function: FUN_100106d2 at 100106d2

undefined1 __thiscall FUN_100106d2(void *this,char param_1)

{
  int *piVar1;
  
  if (param_1 != *(char *)((int)this + 0x2d)) {
    *(char *)((int)this + 0x2d) = param_1;
    piVar1 = *(int **)((int)this + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xa4))(piVar1,(param_1 == '\0') - 1);
    }
  }
  return 1;
}



// Function: FUN_10010701 at 10010701

undefined1 __thiscall FUN_10010701(void *this,char param_1)

{
  int *piVar1;
  
  if (param_1 != *(char *)((int)this + 0x2c)) {
    *(char *)((int)this + 0x2c) = param_1;
    piVar1 = *(int **)((int)this + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x9c))(piVar1,(param_1 == '\0') - 1);
    }
  }
  return 1;
}



// Function: FUN_10010730 at 10010730

bool __thiscall FUN_10010730(void *this,undefined4 param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)((int)this + 0x28) != 0;
  if (bVar1) {
    (**(code **)(**(int **)((int)this + 0x28) + 0x70))(*(int **)((int)this + 0x28),param_1);
  }
  return bVar1;
}



// Function: FUN_1001074c at 1001074c

undefined4 __thiscall FUN_1001074c(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)((int)this + 0x34);
  *param_1 = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



// Function: FUN_1001075d at 1001075d

undefined4 __thiscall FUN_1001075d(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *(undefined4 *)((int)this + 0x34) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



// Function: FUN_1001076e at 1001076e

undefined4 __thiscall FUN_1001076e(void *this,undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)this + 0x28);
  *(undefined4 *)((int)this + 0x38) = param_1;
  *(undefined4 *)((int)this + 0x3c) = param_2;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x8c))(piVar1,param_1);
    piVar1 = (int *)(**(code **)(**(int **)((int)this + 0x28) + 0x94))
                              (*(int **)((int)this + 0x28),param_2);
  }
  return CONCAT31((int3)((uint)piVar1 >> 8),1);
}



// Function: FUN_100107a7 at 100107a7

undefined4 __thiscall FUN_100107a7(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_1 = *(undefined4 *)((int)this + 0x38);
  uVar1 = *(undefined4 *)((int)this + 0x3c);
  *param_2 = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



// Function: FUN_100107c0 at 100107c0

undefined4 __thiscall FUN_100107c0(void *this,char param_1)

{
  undefined4 in_EAX;
  undefined3 uVar2;
  uint nCmdShow;
  HWND hWnd;
  BOOL BVar1;
  
  uVar2 = (undefined3)((uint)in_EAX >> 8);
  if (param_1 != *(char *)((int)this + 0x30)) {
    *(char *)((int)this + 0x30) = param_1;
    nCmdShow = -(uint)(param_1 != '\0') & 5;
    hWnd = GetDlgItem(*(HWND *)((int)this + 4),0xdc);
    BVar1 = ShowWindow(hWnd,nCmdShow);
    uVar2 = (int3)((uint)BVar1 >> 8);
  }
  return CONCAT31(uVar2,1);
}



// Function: FUN_100107f4 at 100107f4

void __cdecl FUN_100107f4(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + -8) == 0xdddd)) {
    free((int *)(param_1 + -8));
  }
  return;
}



// Function: FUN_10010813 at 10010813

undefined4 __thiscall FUN_10010813(void *this,char param_1)

{
  undefined4 in_EAX;
  undefined3 uVar2;
  uint nCmdShow;
  HWND hWnd;
  BOOL BVar1;
  
  uVar2 = (undefined3)((uint)in_EAX >> 8);
  if (param_1 != *(char *)((int)this + 0x2e)) {
    *(char *)((int)this + 0x2e) = param_1;
    nCmdShow = -(uint)(param_1 != '\0') & 5;
    hWnd = GetDlgItem(*(HWND *)((int)this + 4),0xbc8);
    BVar1 = ShowWindow(hWnd,nCmdShow);
    uVar2 = (int3)((uint)BVar1 >> 8);
  }
  return CONCAT31(uVar2,1);
}



// Function: FUN_10010847 at 10010847

void __fastcall FUN_10010847(int param_1)

{
  if (*(char *)(param_1 + 0x2f) != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
  }
  return;
}



// Function: FUN_10010853 at 10010853

void __thiscall FUN_10010853(void *this,undefined1 param_1)

{
  *(undefined1 *)((int)this + 0x115) = param_1;
  return;
}



// Function: FUN_10010863 at 10010863

int __thiscall FUN_10010863(void *this,char param_1)

{
  char *pcVar1;
  uint3 uVar3;
  int iVar2;
  
  pcVar1 = (char *)((int)this + 0x116);
  uVar3 = (uint3)((uint)pcVar1 >> 8);
  if (param_1 == *pcVar1) {
    iVar2 = (uint)uVar3 << 8;
  }
  else {
    *pcVar1 = param_1;
    iVar2 = CONCAT31(uVar3,1);
  }
  return iVar2;
}



// Function: FUN_1001087f at 1001087f

undefined4 __thiscall FUN_1001087f(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = Ordinal_2(*param_1);
  *(undefined4 *)((int)this + 0x118) = uVar1;
  uVar1 = Ordinal_2(*param_2);
  *(undefined4 *)((int)this + 0x11c) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



// Function: FUN_100108ae at 100108ae

undefined1 __thiscall FUN_100108ae(void *this,int param_1)

{
  *(bool *)((int)this + 0x121) = param_1 != 0;
  return 1;
}



// Function: FUN_100108c4 at 100108c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CWnd * __fastcall FUN_100108c4(CWnd *param_1)

{
  CWnd::CWnd(param_1);
  *(undefined ***)param_1 = CButton::vftable;
  return param_1;
}



// Function: FUN_100108f0 at 100108f0

CButton * __thiscall FUN_100108f0(void *this,byte param_1)

{
  CButton::~CButton((CButton *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CButton *)this;
}



// Function: FUN_1001090f at 1001090f

int __cdecl FUN_1001090f(int param_1)

{
  if (*(short *)(param_1 + 2) == -1) {
    return param_1 + 0x10;
  }
  return param_1 + 8;
}



// Function: FUN_1001092a at 1001092a

uint __cdecl FUN_1001092a(uint *param_1)

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



// Function: FUN_100109b0 at 100109b0

uint __cdecl FUN_100109b0(int param_1,int param_2)

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



// Function: FUN_10010a13 at 10010a13

uint * FUN_10010a13(uint *param_1)

{
  bool bVar1;
  uint *puVar2;
  ushort *puVar3;
  uint uVar4;
  void *pvVar5;
  uint *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  short *psVar9;
  uint uVar10;
  uint uVar11;
  rsize_t rVar12;
  void *local_14;
  uint local_10;
  int local_c;
  
  puVar2 = param_1;
  local_14 = (void *)FUN_1001092a(param_1);
  rVar12 = (int)local_14 - (int)param_1;
  uVar8 = (uint)(*(short *)((int)param_1 + 2) == -1);
  puVar3 = (ushort *)FUN_1001090f((int)param_1);
  uVar4 = (uint)*puVar3;
  bVar1 = false;
  uVar10 = rVar12;
  param_1 = (uint *)local_14;
  local_10 = uVar4;
  if (uVar4 != 0) {
    do {
      pvVar5 = (void *)FUN_100109b0((int)param_1,uVar8);
      if (uVar8 == 0) {
        psVar9 = (short *)((int)param_1 + 0x12);
      }
      else {
        psVar9 = (short *)((int)param_1 + 0x18);
      }
      if (*psVar9 == 0x7b) {
        bVar1 = true;
      }
      else {
        uVar10 = (int)pvVar5 + (uVar10 - (int)param_1);
      }
      local_10 = local_10 - 1;
      param_1 = (uint *)pvVar5;
    } while (local_10 != 0);
    if (bVar1) {
      puVar6 = (uint *)GlobalAlloc(0,uVar10);
      FUN_10001235(puVar6,uVar10,puVar2,rVar12);
      param_1 = (uint *)((int)puVar6 + rVar12);
      uVar11 = uVar10 - rVar12;
      if (uVar11 <= uVar10) goto LAB_10010ad7;
LAB_10010acd:
      FUN_1000121b(-0x7fffbffb);
LAB_10010ad7:
      puVar7 = (undefined2 *)FUN_1001090f((int)puVar6);
      local_c = 0;
      *puVar7 = 0;
      uVar10 = uVar11;
      do {
        pvVar5 = (void *)FUN_100109b0((int)local_14,uVar8);
        psVar9 = (short *)((int)local_14 + 0x18);
        if (uVar8 == 0) {
          psVar9 = (short *)((int)local_14 + 0x12);
        }
        uVar11 = uVar10;
        if (*psVar9 != 0x7b) {
          rVar12 = (int)pvVar5 - (int)local_14;
          FUN_10001235(param_1,uVar10,local_14,rVar12);
          param_1 = (uint *)((int)param_1 + rVar12);
          uVar11 = uVar10 - rVar12;
          local_14 = pvVar5;
          if (uVar10 < uVar11) goto LAB_10010acd;
          psVar9 = (short *)FUN_1001090f((int)puVar6);
          *psVar9 = *psVar9 + 1;
        }
        local_c = local_c + 1;
        uVar10 = uVar11;
        local_14 = pvVar5;
        if ((int)uVar4 <= local_c) {
          return puVar6;
        }
      } while( true );
    }
  }
  return puVar2;
}



// Function: FUN_10010b4a at 10010b4a

int FUN_10010b4a(HWND param_1,LRESULT *param_2)

{
  int iVar1;
  LRESULT LVar2;
  
  if (param_2 == (LRESULT *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    LVar2 = SendMessageW(param_1,DAT_100303c0,0,0);
    *param_2 = LVar2;
    iVar1 = (-(uint)(LVar2 != 0) & 0x7fffbffb) + 0x80004005;
  }
  return iVar1;
}



// Function: FUN_10010b84 at 10010b84

undefined4 __fastcall FUN_10010b84(int param_1)

{
  int *piVar1;
  HWND hWnd;
  uint uVar2;
  
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  hWnd = *(HWND *)(param_1 + 4);
  if (hWnd != (HWND)0x0) {
    if (*(char *)(param_1 + 0x114) == '\0') {
      hWnd = (HWND)DestroyWindow(hWnd);
      if (hWnd == (HWND)0x0) {
        uVar2 = *(uint *)(param_1 + 0x118);
        if (uVar2 != 0) {
          uVar2 = Ordinal_6(uVar2);
        }
        if (*(int *)(param_1 + 0x11c) != 0) {
          uVar2 = Ordinal_6(*(int *)(param_1 + 0x11c));
        }
        return uVar2 & 0xffffff00;
      }
    }
    else {
      EndDialog(hWnd,0);
      hWnd = (HWND)CloseHandle(*(HANDLE *)(param_1 + 0x10c));
    }
  }
  return CONCAT31((int3)((uint)hWnd >> 8),1);
}



// Function: FUN_10010bf4 at 10010bf4

undefined4 __thiscall FUN_10010bf4(void *this,undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_EDX;
  ulonglong uVar5;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)((int)this + 0x40) = param_1;
  uVar3 = 0;
  if (*(int *)((int)this + 0x28) != 0) {
    local_c = 0;
    local_10 = 0;
    local_8 = 0;
    FUN_10010730(this,&local_c);
    FUN_100107a7(this,&local_10,&local_8);
    iVar4 = local_8 - local_c;
    local_8 = local_8 - local_10;
    piVar1 = *(int **)((int)this + 0x28);
    iVar2 = *piVar1;
    uVar5 = FUN_100177a0(iVar4,extraout_EDX);
    uVar3 = (**(code **)(iVar2 + 0x84))(piVar1,(int)uVar5);
  }
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}



// Function: FUN_10010c60 at 10010c60

bool __thiscall FUN_10010c60(void *this,int param_1)

{
  int *piVar1;
  HWND pHVar2;
  BOOL BVar3;
  
  if ((*(char *)((int)this + 0x120) == '\0') && (param_1 < 100)) {
    BVar3 = 1;
    pHVar2 = GetDlgItem(*(HWND *)((int)this + 4),0xbc8);
    EnableWindow(pHVar2,BVar3);
  }
  piVar1 = *(int **)((int)this + 0x28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x74))(piVar1,param_1);
  }
  if (*(char *)((int)this + 0x2c) != '\0') {
    FUN_10010bf4(this,*(undefined4 *)((int)this + 0x40));
  }
  if (99 < param_1) {
    BVar3 = 0;
    pHVar2 = GetDlgItem(*(HWND *)((int)this + 4),0xbc8);
    EnableWindow(pHVar2,BVar3);
    *(undefined1 *)((int)this + 0x120) = 0;
  }
  return piVar1 != (int *)0x0;
}



// Function: FUN_10010ce1 at 10010ce1

void __fastcall FUN_10010ce1(void *param_1)

{
  int local_8;
  
  local_8 = 0;
  FUN_10010730(param_1,&local_8);
  local_8 = local_8 + *(int *)((int)param_1 + 0x34);
  FUN_10010c60(param_1,local_8);
  return;
}



// Function: FUN_10010d09 at 10010d09

undefined4 FUN_10010d09(void *param_1)

{
  void *pvVar1;
  bool bVar2;
  int iVar3;
  void *this;
  int local_8;
  
  pvVar1 = param_1;
  do {
    bVar2 = FUN_100106ca((int)pvVar1);
  } while (!bVar2);
  param_1 = (void *)0x0;
  local_8 = 0;
  FUN_100107a7(this,&param_1,&local_8);
  if ((int)param_1 < local_8) {
    iVar3 = local_8 - (int)param_1;
    do {
      Sleep(1000);
      FUN_10010ce1(pvVar1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_10010b84((int)pvVar1);
  return 0;
}



// Function: FUN_10010d63 at 10010d63

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_10010d63(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined1 uVar3;
  undefined1 local_414 [4];
  undefined4 *local_410;
  int local_40c;
  int local_408;
  short local_404 [2];
  void *local_400;
  undefined1 local_3fc [1012];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x404;
  local_8 = 0x10010d72;
  local_410 = param_2;
  *param_2 = 0;
  if ((((param_1 == (int *)0x0) ||
       (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_404,2,&local_408), iVar1 < 0)) ||
      (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_414,4,&local_408), iVar1 < 0)) ||
     (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_40c,4,&local_408), iVar1 < 0))
  goto LAB_10010f1f;
  uVar3 = local_40c == 0;
  if (local_40c == 0) {
LAB_10010e95:
    if (((local_404[0] == 0x37a) || (local_404[0] == 0x37b)) &&
       (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_400,4,&local_408), -1 < iVar1)) {
      for (local_400 = (void *)((int)local_400 - 4); local_400 != (void *)0x0;
          local_400 = (void *)((int)local_400 - local_408)) {
        pvVar2 = local_400;
        if ((void *)0x3e7 < local_400) {
          pvVar2 = (void *)0x3e8;
        }
        (**(code **)(*param_1 + 0xc))(param_1,local_3fc,pvVar2,&local_408);
      }
    }
  }
  else {
    iVar1 = local_40c;
    if (-1 < local_40c) goto LAB_10010dfe;
    iVar1 = -0x7ff8ffa9;
    while( true ) {
      iVar1 = FUN_1000121b(iVar1);
LAB_10010dfe:
      if ((bool)uVar3) break;
      local_400 = (void *)Ordinal_4(0,iVar1);
      uVar3 = local_400 == (void *)0x0;
      if (!(bool)uVar3) goto LAB_10010e08;
      iVar1 = -0x7ff8fff2;
      local_400 = (void *)0x0;
    }
    local_400 = (void *)0x0;
LAB_10010e08:
    pvVar2 = local_400;
    local_8 = 0;
    iVar1 = Ordinal_7(local_400);
    if (iVar1 != 0) {
      memset(pvVar2,0,local_40c * 2 + 2);
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,pvVar2,local_40c * 2,&local_408);
      if (-1 < iVar1) {
        local_400 = (void *)0x0;
        *local_410 = pvVar2;
        local_8 = 0xffffffff;
        Ordinal_6(0);
        goto LAB_10010e95;
      }
    }
    local_8 = 0xffffffff;
    Ordinal_6(pvVar2);
  }
LAB_10010f1f:
  FUN_100173c1();
  return;
}



// Function: FUN_10010f25 at 10010f25

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10010f25(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10010f4a at 10010f4a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10010f4a(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10010f79 at 10010f79

void __fastcall FUN_10010f79(int *param_1)

{
  FUN_100107f4(*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10010f89 at 10010f89

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10010f89(void *this,int param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined2 *)(*this + param_1 * 2);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = *param_2;
  }
  return;
}



// Function: FUN_10010fc0 at 10010fc0

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10010fc0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_68 [4];
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c [5];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_30 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10001743(&local_30,0x78);
  local_34 = 0;
  local_8._0_1_ = 2;
  FUN_10001743(&local_34,0x79);
  local_40 = 0;
  local_8._0_1_ = 3;
  FUN_10001743(&local_40,0x7a);
  local_44 = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_10001743(&local_44,0x7b);
  uVar2 = local_30;
  uVar1 = local_34;
  local_68[2] = local_40;
  local_68[3] = local_44;
  local_28 = 0;
  local_24 = 1;
  local_20 = 2;
  local_1c[0] = 3;
  local_30 = 0;
  local_68[0] = uVar2;
  local_34 = 0;
  local_68[1] = uVar1;
  local_48 = local_40;
  local_40 = 0;
  local_4c = local_44;
  local_44 = 0;
  local_54 = 0;
  local_58 = 4;
  local_3c = Ordinal_15(8,1,&local_58);
  local_2c = Ordinal_26(local_3c,&local_28,uVar2);
  local_2c = Ordinal_26(local_3c,&local_24,uVar1);
  local_2c = Ordinal_26(local_3c,&local_20,local_48);
  local_2c = Ordinal_26(local_3c,local_1c,local_4c);
  local_2c = (**(code **)(**(int **)(local_50 + 0x28) + 0xac))(*(int **)(local_50 + 0x28),&local_3c)
  ;
  for (local_38 = 0; local_38 < 4; local_38 = local_38 + 1) {
    Ordinal_6(local_68[local_38]);
  }
  local_8._0_1_ = 3;
  Ordinal_6(local_44);
  local_8._0_1_ = 2;
  Ordinal_6(local_40);
  local_8._0_1_ = 1;
  Ordinal_6(local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_30);
  local_8 = 0xffffffff;
  FUN_100173d0();
  return;
}



// Function: Catch@10011112 at 10011112

undefined4 Catch_10011112(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x28) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10011109;
}



// Function: FUN_10011123 at 10011123

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_10011123(void *this,int param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  HWND pHVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uStackY_2c;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar4 = param_3;
  uStack_4 = 0;
  local_8 = 0x1001112f;
  puVar8 = (undefined4 *)auStack_20;
  if (param_3 == (int *)0x0) {
    iVar6 = -0x7fffbffd;
  }
  else {
    *param_3 = 0;
                    /* WARNING: Load size is inaccurate */
    iVar6 = -0x7ff8fa73;
    puVar8 = &uStackY_2c;
    uStackY_2c = 0x10011151;
    pHVar7 = GetDlgItem(*this,param_1);
    if (pHVar7 != (HWND)0x0) {
      *piVar4 = 0;
      param_3 = (int *)0x0;
      local_8 = 1;
      puVar8[-1] = &param_3;
      puVar8[-2] = pHVar7;
      puVar8[-3] = 0x1001116b;
      iVar6 = FUN_10010b4a((HWND)puVar8[-2],(LRESULT *)puVar8[-1]);
      piVar5 = param_3;
      if (-1 < iVar6) {
        puVar1 = (undefined4 *)*param_3;
        puVar8[-1] = piVar4;
        puVar8[-2] = param_2;
        puVar8[-3] = piVar5;
        pcVar2 = (code *)*puVar1;
        puVar9 = puVar8 + -4;
        puVar8 = puVar8 + -4;
        *puVar9 = 0x1001117d;
        iVar6 = (*pcVar2)();
      }
      local_8 = 0xffffffff;
      if (piVar5 != (int *)0x0) {
        iVar3 = *piVar5;
        *(int **)((int)puVar8 + -4) = piVar5;
        pcVar2 = *(code **)(iVar3 + 8);
        puVar10 = (undefined4 *)((int)puVar8 + -8);
        puVar8 = (undefined4 *)((int)puVar8 + -8);
        *puVar10 = 0x1001118d;
        (*pcVar2)();
      }
    }
  }
  *(undefined4 *)((int)puVar8 + -4) = 0x10011194;
  return iVar6;
}



// Function: FUN_10011197 at 10011197

undefined4 __thiscall FUN_10011197(void *this,undefined2 *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  uint _Count;
  undefined8 uVar6;
  
  iVar5 = *(int *)((int)this + 4);
  iVar1 = *(int *)((int)this + 8);
  if (iVar5 == iVar1) {
                    /* WARNING: Load size is inaccurate */
    puVar2 = *this;
    uVar6 = CONCAT44(puVar2,iVar1);
    if ((puVar2 <= param_1) && (uVar6 = CONCAT44(puVar2,iVar1), param_1 < puVar2 + iVar1)) {
      uVar6 = FUN_1000121b(-0x7fffbffb);
      iVar5 = extraout_ECX;
    }
    if ((int)uVar6 == 0) {
      _Count = 1;
LAB_100111d9:
      pvVar3 = _recalloc((void *)((ulonglong)uVar6 >> 0x20),_Count,2);
      if (pvVar3 != (void *)0x0) {
        *(uint *)((int)this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_100111ef;
      }
    }
    else {
      _Count = iVar5 * 2;
      if ((-1 < (int)_Count) && (_Count < 0x40000000)) goto LAB_100111d9;
    }
    uVar4 = 0;
  }
  else {
LAB_100111ef:
    FUN_10010f89(this,*(int *)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    uVar4 = 1;
  }
  return uVar4;
}



// Function: FUN_1001120c at 1001120c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1001120c(undefined4 *param_1)

{
  *param_1 = CProgressDlgImpl::vftable;
  FUN_10010b84((int)param_1);
  FID_conflict__Tidy(param_1 + 0x57,'\x01',0);
  FID_conflict__Tidy(param_1 + 0x50,'\x01',0);
  FID_conflict__Tidy(param_1 + 0x49,'\x01',0);
  CButton::~CButton((CButton *)(param_1 + 0x26));
  FID_conflict__Tidy(param_1 + 0x1f,'\x01',0);
  FID_conflict__Tidy(param_1 + 0x18,'\x01',0);
  FID_conflict__Tidy(param_1 + 0x11,'\x01',0);
  FUN_10003560((int)param_1);
  return;
}



// Function: FUN_100112b0 at 100112b0

int __cdecl FUN_100112b0(uint param_1,ushort *param_2,int *param_3)

{
  int iVar1;
  
  while( true ) {
    if (param_2 == (ushort *)0x0) {
      return 0;
    }
    iVar1 = *(int *)(param_2 + 2);
    if (*param_2 == param_1) break;
    param_2 = (ushort *)((int)param_2 + iVar1 + 8);
  }
  if (param_2[1] == 0x378) {
    return 0;
  }
  *param_3 = (int)(param_2 + 1);
  return iVar1 + 6;
}



// Function: FUN_100112ee at 100112ee

undefined4 __cdecl FUN_100112ee(int param_1,int param_2)

{
  short *psVar1;
  
  if (param_2 == 0) {
    psVar1 = (short *)(param_1 + 0x12);
  }
  else {
    psVar1 = (short *)(param_1 + 0x18);
  }
  return CONCAT31((int3)((uint)psVar1 >> 8),*psVar1 == 0x7b);
}



// Function: FUN_1001130b at 1001130b

void __thiscall
FUN_1001130b(void *this,LPCWSTR param_1,HWND param_2,int *param_3,LPCWSTR param_4,DWORD param_5,
            DWORD param_6,HMENU param_7,LPVOID param_8)

{
  HWND pHVar1;
  
  if (param_3 == (int *)0x0) {
    param_3 = &DAT_1002db54;
  }
  pHVar1 = CreateWindowExW(param_6,param_1,param_4,param_5,*param_3,param_3[1],param_3[2] - *param_3
                           ,param_3[3] - param_3[1],param_2,param_7,DAT_10030d70,param_8);
  *(HWND *)this = pHVar1;
  return;
}



// Function: FUN_1001135d at 1001135d

int FUN_1001135d(HWND param_1,LRESULT *param_2)

{
  int iVar1;
  LRESULT LVar2;
  
  if (param_2 == (LRESULT *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    LVar2 = SendMessageW(param_1,DAT_100303bc,0,0);
    *param_2 = LVar2;
    iVar1 = (-(uint)(LVar2 != 0) & 0x7fffbffb) + 0x80004005;
  }
  return iVar1;
}



// Function: FUN_10011397 at 10011397

int FUN_10011397(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 == 0x110) && (iVar1 = (**(code **)(*param_1 + 0x10))(0x136), iVar1 < 0)) {
    param_1[9] = iVar1;
    if ((char)param_1[8] != '\0') {
      EndDialog((HWND)param_1[1],-1);
    }
    return 0;
  }
  iVar1 = FUN_100044be(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_100113e3 at 100113e3

undefined * FUN_100113e3(void)

{
  return FUN_10011397;
}



// Function: FUN_100113e9 at 100113e9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_100113e9(void *this,undefined4 param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uStackY_30;
  int *piStackY_2c;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  puVar5 = (undefined4 *)auStack_20;
  if (param_2 == (int *)0x0) {
    iVar4 = -0x7fffbffd;
  }
  else {
    *param_2 = 0;
    param_2 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    piStackY_2c = (int *)0x1001141c;
    iVar4 = FUN_1001135d(*this,(LRESULT *)&param_2);
    piVar3 = param_2;
    puVar5 = (undefined4 *)auStack_20;
    if (-1 < iVar4) {
      piStackY_2c = param_2;
      puVar5 = &uStackY_30;
      uStackY_30 = 0x1001142e;
      iVar4 = (**(code **)*param_2)();
    }
    local_8 = 0xffffffff;
    if (piVar3 != (int *)0x0) {
      iVar1 = *piVar3;
      *(int **)((int)puVar5 + -4) = piVar3;
      pcVar2 = *(code **)(iVar1 + 8);
      puVar6 = (undefined4 *)((int)puVar5 + -8);
      puVar5 = (undefined4 *)((int)puVar5 + -8);
      *puVar6 = 0x1001143e;
      (*pcVar2)();
    }
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x10011445;
  return iVar4;
}



// Function: FUN_10011448 at 10011448

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10011448(int param_1)

{
  HWND hWnd;
  wchar_t *local_34;
  LPCWSTR *local_30 [5];
  uint local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_34 = (wchar_t *)0x0;
  local_8 = 0;
  Ordinal_6(0);
  local_34 = (wchar_t *)0x0;
  FUN_100013ba(0x77,(int *)&local_34);
  FUN_10010413((undefined2 *)local_30,local_34);
  local_8._0_1_ = 1;
  if (local_1c < 8) {
    local_30[0] = (LPCWSTR *)local_30;
  }
  hWnd = GetDlgItem(*(HWND *)(param_1 + 4),0xbc8);
  SetWindowTextW(hWnd,(LPCWSTR)local_30[0]);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  Ordinal_6(local_34);
  FUN_100173c1();
  return;
}



// Function: FUN_100114c7 at 100114c7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_100114c7(int param_1)

{
  FUN_10003590(param_1);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  return param_1;
}



// Function: FUN_100114f8 at 100114f8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100114f8(int param_1)

{
  int *piVar1;
  
  Ordinal_6(*(undefined4 *)(param_1 + 0xe8));
  piVar1 = *(int **)(param_1 + 0xdc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xd8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x7c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x78);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x74);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x70);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x6c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x68);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 100);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10010f4a(param_1 + 0x38);
  FUN_10003560(param_1);
  return;
}



// Function: FUN_1001165d at 1001165d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1001165d(int param_1)

{
  FUN_100114f8(param_1);
  return;
}



// Function: FUN_1001167b at 1001167b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1001167b(undefined4 *param_1)

{
  FUN_100114c7((int)param_1);
  *param_1 = CProgressDlgImpl::vftable;
  param_1[10] = 0;
  param_1[0xb] = 0x101;
  *(undefined1 *)(param_1 + 0xc) = 0;
  param_1[0xd] = 10;
  param_1[0xe] = 0;
  param_1[0xf] = 100;
  param_1[0x10] = 0;
  param_1[0x16] = 7;
  param_1[0x15] = 0;
  *(undefined2 *)(param_1 + 0x11) = 0;
  param_1[0x1d] = 7;
  param_1[0x1c] = 0;
  *(undefined2 *)(param_1 + 0x18) = 0;
  param_1[0x24] = 7;
  param_1[0x23] = 0;
  *(undefined2 *)(param_1 + 0x1f) = 0;
  FUN_100108c4((CWnd *)(param_1 + 0x26));
  param_1[0x43] = 0;
  *(undefined2 *)(param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x116) = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  *(undefined2 *)(param_1 + 0x48) = 0x101;
  param_1[0x4e] = 7;
  param_1[0x4d] = 0;
  *(undefined2 *)(param_1 + 0x49) = 0;
  param_1[0x55] = 7;
  param_1[0x54] = 0;
  *(undefined2 *)(param_1 + 0x50) = 0;
  param_1[0x5c] = 7;
  param_1[0x5b] = 0;
  *(undefined2 *)(param_1 + 0x57) = 0;
  return param_1;
}



// Function: FUN_1001177a at 1001177a

undefined4 * __thiscall FUN_1001177a(void *this,byte param_1)

{
  FUN_1001120c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10011799 at 10011799

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10011799(int param_1)

{
  DWORD DVar1;
  
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_10003cfc(param_1);
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
  return param_1;
}



// Function: FUN_100118e4 at 100118e4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100118e4(void *this,undefined4 param_1)

{
  FUN_10011799((int)this);
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
  return (undefined4 *)this;
}



// Function: FUN_1001195e at 1001195e

LPWSTR __cdecl FUN_1001195e(LPWSTR param_1,LPCWSTR param_2)

{
  LPWSTR pWVar1;
  
  if (param_1 != (LPWSTR)0x0) {
    do {
      pWVar1 = param_2;
      if (*param_1 == L'\0') {
        return (LPWSTR)0x0;
      }
      for (; (pWVar1 != (LPCWSTR)0x0 && (*pWVar1 != L'\0')); pWVar1 = CharNextW(pWVar1)) {
        if (*param_1 == *pWVar1) {
          pWVar1 = CharNextW(param_1);
          return pWVar1;
        }
      }
      param_1 = CharNextW(param_1);
    } while (param_1 != (LPWSTR)0x0);
  }
  return (LPWSTR)0x0;
}



// Function: FUN_100119a3 at 100119a3

void __fastcall FUN_100119a3(undefined4 *param_1)

{
  HWND hWnd;
  int iVar1;
  WCHAR local_18 [8];
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  hWnd = GetParent((HWND)*param_1);
  iVar1 = GetClassNameW(hWnd,local_18,8);
  if (iVar1 != 0) {
    lstrcmpW(local_18,L"#32770");
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100119ec at 100119ec

void __fastcall FUN_100119ec(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar1 + 8))(piVar1);
  return;
}



// Function: FUN_100119fa at 100119fa

void FUN_100119fa(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



// Function: FUN_10011a1e at 10011a1e

undefined4 FUN_10011a1e(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) ^ (param_2 ^ *(uint *)(param_1 + 0x7c)) & 1;
  return 0;
}



// Function: FUN_10011a36 at 10011a36

undefined4 FUN_10011a36(int param_1,short *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    bVar2 = (byte)*(uint *)(param_1 + 0x7c) & 1;
    *param_2 = ((ushort)bVar2 - (ushort)bVar2) - (ushort)((*(uint *)(param_1 + 0x7c) & 1) != 0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011a60 at 10011a60

undefined4 FUN_10011a60(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x80);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011a82 at 10011a82

undefined4 FUN_10011a82(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x84);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011aa4 at 10011aa4

undefined4 FUN_10011aa4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x88);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011ac6 at 10011ac6

undefined4 FUN_10011ac6(int param_1,short *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    bVar2 = (byte)*(uint *)(param_1 + 0x7c) & 2;
    *param_2 = ((ushort)bVar2 - (ushort)bVar2) - (ushort)((*(uint *)(param_1 + 0x7c) & 2) != 0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011af0 at 10011af0

undefined4 FUN_10011af0(int param_1,short *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    bVar2 = (byte)*(uint *)(param_1 + 0x7c) & 4;
    *param_2 = ((ushort)bVar2 - (ushort)bVar2) - (ushort)((*(uint *)(param_1 + 0x7c) & 4) != 0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011b1a at 10011b1a

undefined4 FUN_10011b1a(int param_1,short *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    bVar2 = (byte)*(uint *)(param_1 + 0x7c) & 8;
    *param_2 = ((ushort)bVar2 - (ushort)bVar2) - (ushort)((*(uint *)(param_1 + 0x7c) & 8) != 0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011b44 at 10011b44

void FUN_10011b44(undefined4 param_1,undefined2 *param_2)

{
  *param_2 = 0;
  return;
}



// Function: FUN_10011b53 at 10011b53

undefined4 FUN_10011b53(undefined4 param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 0;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011b6f at 10011b6f

undefined4 FUN_10011b6f(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x94);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011b91 at 10011b91

undefined4 FUN_10011b91(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x98) = param_2;
  return 0;
}



// Function: FUN_10011ba6 at 10011ba6

undefined4 FUN_10011ba6(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x98);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011bc8 at 10011bc8

undefined4 FUN_10011bc8(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 5 ^ *(uint *)(param_1 + 0x7c)) & 0x20;
  return 0;
}



// Function: FUN_10011be4 at 10011be4

undefined4 FUN_10011be4(int param_1,short *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    bVar2 = (byte)*(uint *)(param_1 + 0x7c) & 0x20;
    *param_2 = ((ushort)bVar2 - (ushort)bVar2) - (ushort)((*(uint *)(param_1 + 0x7c) & 0x20) != 0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011c0e at 10011c0e

undefined4 FUN_10011c0e(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 6 ^ *(uint *)(param_1 + 0x7c)) & 0x40;
  return 0;
}



// Function: FUN_10011c2a at 10011c2a

undefined4 FUN_10011c2a(int param_1,short *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    bVar2 = (byte)*(uint *)(param_1 + 0x7c) & 0x40;
    *param_2 = ((ushort)bVar2 - (ushort)bVar2) - (ushort)((*(uint *)(param_1 + 0x7c) & 0x40) != 0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011c54 at 10011c54

undefined4 FUN_10011c54(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = Ordinal_2(*(undefined4 *)(param_1 + 0x9c));
    *param_2 = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011c7e at 10011c7e

undefined4 FUN_10011c7e(void)

{
  return 0x80004001;
}



// Function: FUN_10011c86 at 10011c86

undefined4 FUN_10011c86(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + -0x28);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10011ca5 at 10011ca5

undefined4 FUN_10011ca5(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 2;
  return 0;
}



// Function: FUN_10011cb5 at 10011cb5

undefined4 FUN_10011cb5(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffffd;
  return 0;
}



// Function: FUN_10011cc5 at 10011cc5

void FUN_10011cc5(int param_1,int *param_2)

{
  BOOL BVar1;
  HWND hWnd;
  tagPOINT local_18;
  tagPOINT local_10;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
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
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10011d65 at 10011d65

undefined4 FUN_10011d65(void)

{
  return 0;
}



// Function: FUN_10011d6a at 10011d6a

uint FUN_10011d6a(int param_1)

{
  return ~*(uint *)(param_1 + 0x9c) & 1;
}



// Function: FUN_10011d7f at 10011d7f

uint FUN_10011d7f(int param_1)

{
  return ~(*(uint *)(param_1 + 0x6c) >> 4) & 1;
}



// Function: FUN_10011d94 at 10011d94

undefined4 FUN_10011d94(int param_1,int param_2)

{
  if (param_2 == 0) {
    ReleaseCapture();
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xffffffef;
  }
  else {
    SetCapture(*(HWND *)(param_1 + -0x28));
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 0x10;
  }
  return 0;
}



// Function: FUN_10011dc4 at 10011dc4

uint FUN_10011dc4(int param_1)

{
  return ~(*(uint *)(param_1 + 0x6c) >> 5) & 1;
}



// Function: FUN_10011dd9 at 10011dd9

undefined4 FUN_10011dd9(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x6c) =
       *(uint *)(param_1 + 0x6c) ^ (param_2 << 5 ^ *(uint *)(param_1 + 0x6c)) & 0x20;
  return 0;
}



// Function: FUN_10011df4 at 10011df4

void FUN_10011df4(int param_1,undefined4 param_2,byte param_3,undefined4 *param_4)

{
  HDC pHVar1;
  HBITMAP h;
  HGDIOBJ ho;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  if ((param_4 == (undefined4 *)0x0) || (*(char *)(param_1 + 0x30) == '\0')) goto LAB_10011ec9;
  pHVar1 = GetDC(*(HWND *)(param_1 + -0x28));
  *param_4 = pHVar1;
  if ((pHVar1 == (HDC)0x0) || (*(undefined1 *)(param_1 + 0x30) = 0, (param_3 & 1) != 0))
  goto LAB_10011ec9;
  GetClientRect(*(HWND *)(param_1 + -0x28),&local_18);
  if (((param_3 & 4) != 0) && (pHVar1 = CreateCompatibleDC((HDC)*param_4), pHVar1 != (HDC)0x0)) {
    h = CreateCompatibleBitmap
                  ((HDC)*param_4,local_18.right - local_18.left,local_18.bottom - local_18.top);
    if (h != (HBITMAP)0x0) {
      ho = SelectObject(pHVar1,h);
      if (ho != (HGDIOBJ)0x0) {
        DeleteObject(ho);
        *(undefined4 *)(param_1 + 0x2c) = *param_4;
        *param_4 = pHVar1;
        goto LAB_10011eb3;
      }
      DeleteObject(h);
    }
    DeleteDC(pHVar1);
  }
LAB_10011eb3:
  if ((param_3 & 2) != 0) {
    FillRect((HDC)*param_4,&local_18,(HBRUSH)0x6);
  }
LAB_10011ec9:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10011ed9 at 10011ed9

void FUN_10011ed9(int param_1,HDC param_2)

{
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_10011f55 at 10011f55

undefined4 FUN_10011f55(int param_1,RECT *param_2,BOOL param_3)

{
  InvalidateRect(*(HWND *)(param_1 + -0x28),param_2,param_3);
  return 0;
}



// Function: FUN_10011f70 at 10011f70

undefined4 FUN_10011f70(int param_1,HRGN param_2,BOOL param_3)

{
  InvalidateRgn(*(HWND *)(param_1 + -0x28),param_2,param_3);
  return 0;
}



// Function: FUN_10011f8b at 10011f8b

undefined4 FUN_10011f8b(void)

{
  return 0;
}



// Function: FUN_10011f90 at 10011f90

undefined4 FUN_10011f90(void)

{
  return 0;
}



// Function: FUN_10011f95 at 10011f95

undefined4 FUN_10011f95(void)

{
  return 0x80004001;
}



// Function: FUN_10011f9d at 10011f9d

undefined4 FUN_10011f9d(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x68) =
       *(uint *)(param_1 + 0x68) ^ (param_2 << 5 ^ *(uint *)(param_1 + 0x68)) & 0x20;
  return 0;
}



// Function: FUN_10011fb8 at 10011fb8

undefined4 FUN_10011fb8(void)

{
  return 0x80004001;
}



// Function: FUN_10011fc0 at 10011fc0

void FUN_10011fc0(void)

{
  return;
}



// Function: FUN_10011fc3 at 10011fc3

void FUN_10011fc3(void)

{
  return;
}



// Function: FUN_10011fc6 at 10011fc6

undefined4 FUN_10011fc6(void)

{
  return 0x80004001;
}



// Function: FUN_10011fce at 10011fce

undefined4 FUN_10011fce(int param_1,int param_2)

{
  *(uint *)(param_1 + 100) =
       *(uint *)(param_1 + 100) ^ (param_2 << 7 ^ *(uint *)(param_1 + 100)) & 0x80;
  return 0;
}



// Function: FUN_10011fec at 10011fec

void FUN_10011fec(int *param_1,int *param_2)

{
  HDC hdc;
  int iVar1;
  int nNumber;
  
  if (param_1 != (int *)0x0) goto LAB_10012000;
  do {
    FUN_1000121b(-0x7fffbffd);
LAB_10012000:
  } while (param_2 == (int *)0x0);
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



// Function: FUN_10012061 at 10012061

void FUN_10012061(int *param_1,int *param_2)

{
  HDC hdc;
  int iVar1;
  int nDenominator;
  
  if (param_1 != (int *)0x0) goto LAB_10012075;
  do {
    FUN_1000121b(-0x7fffbffd);
LAB_10012075:
  } while (param_2 == (int *)0x0);
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



// Function: FUN_100120d6 at 100120d6

void __fastcall FUN_100120d6(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100120e3 at 100120e3

undefined4 FUN_100120e3(int param_1,undefined4 param_2,undefined4 *param_3)

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
    if (puVar1 == (undefined4 *)0x0) {
      *param_3 = 0;
      uVar2 = 0x80004005;
    }
    else {
      uVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
    }
  }
  return uVar2;
}



// Function: FUN_1001211e at 1001211e

undefined4 FUN_1001211e(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_1001213b at 1001213b

undefined4 __thiscall FUN_1001213b(void *this,int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10012162 at 10012162

void FUN_10012162(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 4))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_10012175 at 10012175

void FUN_10012175(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 8))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_10012188 at 10012188

void FUN_10012188(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x2c))(*(undefined4 **)(param_1 + 0x2c),param_2,param_3);
  return;
}



// Function: FUN_100121a0 at 100121a0

undefined4 __fastcall FUN_100121a0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}



// Function: FUN_100121a4 at 100121a4

LONG __thiscall FUN_100121a4(void *this,int param_1)

{
  int iVar1;
  LONG LVar2;
  LONG LVar3;
  
  iVar1 = *(int *)((int)this + 0x14);
  LVar2 = GetWindowLongW(*(HWND *)((int)this + 4),-4);
  LVar3 = 0;
  if ((param_1 != 0) || (iVar1 == LVar2)) {
    LVar3 = SetWindowLongW(*(HWND *)((int)this + 4),-4,*(LONG *)((int)this + 0x20));
    if (LVar3 != 0) {
      *(code **)((int)this + 0x20) = DefWindowProcW_exref;
      LVar3 = *(LONG *)((int)this + 4);
      *(undefined4 *)((int)this + 4) = 0;
    }
  }
  return LVar3;
}



// Function: FUN_100121f0 at 100121f0

undefined4 __cdecl FUN_100121f0(int *param_1,int *param_2)

{
  int *piVar1;
  int *extraout_ECX;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    param_2 = (int *)FUN_1000121b(-0x7fffbffb);
    param_1 = extraout_ECX;
  }
  piVar1 = (int *)*param_2;
  *param_1 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}



// Function: FUN_1001221d at 1001221d

void FUN_1001221d(int param_1)

{
  FUN_10012175(param_1 + -0x24);
  return;
}



// Function: FUN_10012227 at 10012227

void FUN_10012227(int param_1)

{
  FUN_10012162(param_1 + -0x1c);
  return;
}



// Function: FUN_10012231 at 10012231

void FUN_10012231(int param_1)

{
  FUN_10012175(param_1 + -8);
  return;
}



// Function: FUN_1001223b at 1001223b

void FUN_1001223b(int param_1)

{
  FUN_10012175(param_1 + -0x28);
  return;
}



// Function: FUN_10012245 at 10012245

void FUN_10012245(int param_1)

{
  FUN_10012162(param_1 + -0x20);
  return;
}



// Function: FUN_1001224f at 1001224f

void FUN_1001224f(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -0x1c,param_2,param_3);
  return;
}



// Function: FUN_10012259 at 10012259

void FUN_10012259(int param_1)

{
  FUN_10012175(param_1 + -0xc);
  return;
}



// Function: FUN_10012263 at 10012263

void FUN_10012263(int param_1)

{
  FUN_10012162(param_1 + -4);
  return;
}



// Function: FUN_1001226d at 1001226d

void FUN_1001226d(int param_1)

{
  FUN_10012162(param_1 + -0x24);
  return;
}



// Function: FUN_10012277 at 10012277

void FUN_10012277(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -0x20,param_2,param_3);
  return;
}



// Function: FUN_10012281 at 10012281

void FUN_10012281(int param_1)

{
  FUN_10012175(param_1 + -0x10);
  return;
}



// Function: FUN_1001228b at 1001228b

void FUN_1001228b(int param_1)

{
  FUN_10012162(param_1 + -8);
  return;
}



// Function: FUN_10012295 at 10012295

void FUN_10012295(int param_1)

{
  FUN_10012162(param_1 + -0x28);
  return;
}



// Function: FUN_1001229f at 1001229f

void FUN_1001229f(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_100122a9 at 100122a9

void FUN_100122a9(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -0x24,param_2,param_3);
  return;
}



// Function: FUN_100122b3 at 100122b3

void FUN_100122b3(int param_1)

{
  FUN_10012175(param_1 + -0x14);
  return;
}



// Function: FUN_100122bd at 100122bd

void FUN_100122bd(int param_1)

{
  FUN_10012162(param_1 + -0xc);
  return;
}



// Function: FUN_100122c7 at 100122c7

void FUN_100122c7(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_100122d1 at 100122d1

void FUN_100122d1(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -0x28,param_2,param_3);
  return;
}



// Function: FUN_100122db at 100122db

void FUN_100122db(int param_1)

{
  FUN_10012162(param_1 + -0x10);
  return;
}



// Function: FUN_100122e5 at 100122e5

void FUN_100122e5(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_100122ef at 100122ef

void FUN_100122ef(int param_1)

{
  FUN_10012175(param_1 + -0x1c);
  return;
}



// Function: FUN_100122f9 at 100122f9

void __thiscall FUN_100122f9(void *this,byte param_1)

{
  FUN_10014078((void *)((int)this + -0x38),param_1);
  return;
}



// Function: FUN_10012301 at 10012301

void FUN_10012301(int param_1)

{
  FUN_10012162(param_1 + -0x14);
  return;
}



// Function: FUN_1001230b at 1001230b

void FUN_1001230b(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_10012315 at 10012315

void FUN_10012315(int param_1)

{
  FUN_10012175(param_1 + -0x20);
  return;
}



// Function: FUN_1001231f at 1001231f

void FUN_1001231f(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10012188(param_1 + -0x14,param_2,param_3);
  return;
}



// Function: FUN_10012329 at 10012329

void FUN_10012329(int param_1)

{
  FUN_10012175(param_1 + -4);
  return;
}



// Function: FUN_10012333 at 10012333

void __thiscall FUN_10012333(void *this,GUID *param_1)

{
  int iVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  iVar1 = Ordinal_2(local_88);
  *(int *)this = iVar1;
  if (iVar1 == 0) {
    FUN_1000121b(-0x7ff8fff2);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001238a at 1001238a

undefined4 __thiscall
FUN_1001238a(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
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
  FUN_10012061((int *)((int)this + 0xac),(int *)((int)this + 0xa4));
  piVar1 = *(int **)((int)this + 100);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x44))(piVar1,1,(int *)((int)this + 0xa4));
  }
  piVar1 = *(int **)((int)this + 0x74);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,(int)this + 0xb4,(int)this + 0xb4);
  }
  if ((*(byte *)((int)this + 0x98) & 8) != 0) {
    (**(code **)(*(int *)((int)this + 0x2c) + 100))((int *)((int)this + 0x2c),0,1);
  }
  *param_4 = 0;
  return 0;
}



// Function: FUN_10012423 at 10012423

undefined4 __thiscall
FUN_10012423(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
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



// Function: FUN_10012465 at 10012465

undefined4 __thiscall
FUN_10012465(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  int *piVar1;
  undefined4 local_8;
  
  local_8 = 0;
  if ((((*(uint *)((int)this + 0x98) & 1) != 0) && ((*(uint *)((int)this + 0x98) & 8) != 0)) &&
     (piVar1 = *(int **)((int)this + 0x74), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x24))(piVar1,param_1,param_2,param_3,&local_8);
  }
  *param_4 = 0;
  return local_8;
}



// Function: FUN_100124a2 at 100124a2

void __thiscall FUN_100124a2(void *this)

{
  HDC pHVar1;
  HBRUSH hbr;
  HDC hdc;
  HGDIOBJ h;
  HBRUSH hbr_00;
  undefined4 *in_stack_00000010;
  tagPAINTSTRUCT local_58;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0x70) == 0) {
    pHVar1 = BeginPaint(*(HWND *)((int)this + 4),&local_58);
    if (pHVar1 == (HDC)0x0) goto LAB_10012609;
    GetClientRect(*(HWND *)((int)this + 4),&local_18);
    hbr = CreateSolidBrush(*(COLORREF *)((int)this + 0xcc));
    if (hbr != (HBRUSH)0x0) {
      FillRect(pHVar1,&local_18,hbr);
LAB_10012507:
      DeleteObject(hbr);
    }
  }
  else {
    if ((*(byte *)((int)this + 0x98) & 8) == 0) {
      *in_stack_00000010 = 0;
      goto LAB_10012609;
    }
    pHVar1 = BeginPaint(*(HWND *)((int)this + 4),&local_58);
    if (pHVar1 == (HDC)0x0) goto LAB_10012609;
    GetClientRect(*(HWND *)((int)this + 4),&local_18);
    hbr = (HBRUSH)CreateCompatibleBitmap
                            (pHVar1,local_18.right - local_18.left,local_18.bottom - local_18.top);
    if (hbr != (HBRUSH)0x0) {
      hdc = CreateCompatibleDC(pHVar1);
      if (hdc != (HDC)0x0) {
        h = SelectObject(hdc,hbr);
        if (h != (HGDIOBJ)0x0) {
          hbr_00 = CreateSolidBrush(*(COLORREF *)((int)this + 0xcc));
          if (hbr_00 != (HBRUSH)0x0) {
            FillRect(hdc,&local_18,hbr_00);
            DeleteObject(hbr_00);
            (**(code **)(**(int **)((int)this + 0x70) + 0xc))
                      (*(int **)((int)this + 0x70),1,0xffffffff,0,0,0,hdc,(int)this + 0xb4,
                       (int)this + 0xb4,0,0);
            BitBlt(pHVar1,0,0,local_18.right,local_18.bottom,hdc,0,0,0xcc0020);
          }
          SelectObject(hdc,h);
        }
        DeleteDC(hdc);
      }
      goto LAB_10012507;
    }
  }
  EndPaint(*(HWND *)((int)this + 4),&local_58);
LAB_10012609:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001261a at 1001261a

undefined4 FUN_1001261a(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004003;
  if (param_3 != (undefined4 *)0x0) {
    puVar1 = *(undefined4 **)(param_1 + 0x3c);
    if (puVar1 == (undefined4 *)0x0) {
      *param_3 = 0;
      uVar2 = 0x80040004;
    }
    else {
      uVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
    }
  }
  return uVar2;
}



// Function: FUN_1001264a at 1001264a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1001264a(int param_1,int *param_2)

{
  HANDLE h;
  HDC hdc;
  int iVar1;
  HWND pHVar2;
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
  int *local_74;
  int local_70 [4];
  undefined2 local_60;
  byte local_5c;
  byte local_5b;
  byte local_5a;
  byte local_59;
  undefined1 local_54 [76];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x90;
  local_8 = 0x10012659;
  local_80 = param_2;
  if (param_2 == (int *)0x0) goto LAB_100127b8;
  local_74 = (int *)(param_1 + 0x8c);
  *param_2 = 0;
  if (*local_74 == 0) {
    local_78 = 0;
    local_8 = 0;
    h = GetStockObject(0x11);
    if ((h != (HGDIOBJ)0x0) || (h = GetStockObject(0xd), h != (HGDIOBJ)0x0)) {
      GetObjectW(h,0x5c,local_70);
      local_9c = local_54;
      local_90 = local_60;
      local_8e = (ushort)local_59;
      local_8c = (uint)local_5c;
      local_88 = (uint)local_5b;
      local_84 = (uint)local_5a;
      local_a0 = 0x20;
      local_7c = local_70[0];
      if (local_70[0] < 0) {
        local_7c = -local_70[0];
      }
      if (*(HWND *)(param_1 + -0x48) == (HWND)0x0) {
        pHVar2 = GetDesktopWindow();
        hdc = GetDC(pHVar2);
        if (hdc != (HDC)0x0) {
          iVar1 = GetDeviceCaps(hdc,0x5a);
          pHVar2 = GetDesktopWindow();
          goto LAB_1001276c;
        }
      }
      else {
        hdc = GetDC(*(HWND *)(param_1 + -0x48));
        if (hdc != (HDC)0x0) {
          iVar1 = GetDeviceCaps(hdc,0x5a);
          pHVar2 = *(HWND *)(param_1 + -0x48);
LAB_1001276c:
          ReleaseDC(pHVar2,hdc);
          local_98 = (local_7c * 720000) / iVar1;
          local_94 = 0;
          Ordinal_420(&local_a0,&DAT_10022804,local_74);
          local_8 = 0xffffffff;
          FUN_10006d61(&local_78);
          goto LAB_100127b2;
        }
      }
    }
    FUN_1000640e();
    local_8 = 0xffffffff;
    FUN_10006d61(&local_78);
  }
  else {
LAB_100127b2:
    FUN_1001213b(local_74,local_80);
  }
LAB_100127b8:
  FUN_100173c1();
  return;
}



// Function: FUN_100127c0 at 100127c0

undefined4 FUN_100127c0(int param_1,int param_2)

{
  FUN_100034fe((void *)(param_1 + 0x9c),param_2);
  return 0;
}



// Function: FUN_100127da at 100127da

int FUN_100127da(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = -0x7fffbffd;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    puVar1 = *(undefined4 **)(param_1 + 0x14);
    if ((puVar1 == (undefined4 *)0x0) ||
       (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10022814,param_2), iVar2 < 0)) {
      iVar2 = (*(code *)**(undefined4 **)(param_1 + -4))
                        ((undefined4 *)(param_1 + -4),&DAT_10022814,param_2);
    }
  }
  return iVar2;
}



// Function: FUN_1001281a at 1001281a

undefined4 FUN_1001281a(int param_1)

{
  int *piVar1;
  HDC hDC;
  undefined4 uVar2;
  
  hDC = GetDC(*(HWND *)(param_1 + -0x24));
  if (hDC == (HDC)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x48);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1,1,0xffffffff,0,0,0,hDC,param_1 + 0x8c,param_1 + 0x8c,0,0);
    }
    ReleaseDC(*(HWND *)(param_1 + -0x24),hDC);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1001286d at 1001286d

undefined4 FUN_1001286d(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
  OleLockRunning(*(LPUNKNOWN *)(param_1 + 0x38),1,0);
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffff7;
  (**(code **)**(undefined4 **)(param_1 + 0x38))
            (*(undefined4 **)(param_1 + 0x38),&DAT_10022824,param_1 + 0x48);
  return 0;
}



// Function: FUN_100128a1 at 100128a1

undefined4 FUN_100128a1(int param_1)

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



// Function: FUN_100128c2 at 100128c2

undefined4 FUN_100128c2(int param_1,undefined4 param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
  OleLockRunning(*(LPUNKNOWN *)(param_1 + 0x38),1,0);
  if ((param_3 & 1) != 0) {
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 8;
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x38))
                      (*(undefined4 **)(param_1 + 0x38),&DAT_10022834,param_1 + 0x48);
    if (-1 < iVar2) goto LAB_1001290f;
  }
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffff7;
  (**(code **)**(undefined4 **)(param_1 + 0x38))
            (*(undefined4 **)(param_1 + 0x38),&DAT_10022824,param_1 + 0x48);
LAB_1001290f:
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,param_1 + 0x88,param_1 + 0x88);
  }
  return 0;
}



// Function: FUN_1001292b at 1001292b

undefined4 FUN_1001292b(int param_1)

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



// Function: FUN_1001294c at 1001294c

undefined4 FUN_1001294c(int param_1,UINT param_2,WPARAM param_3,LPARAM param_4,LRESULT *param_5)

{
  LRESULT LVar1;
  
  LVar1 = CallWindowProcW(*(WNDPROC *)(param_1 + -0xc),*(HWND *)(param_1 + -0x28),param_2,param_3,
                          param_4);
  *param_5 = LVar1;
  return 0;
}



// Function: FUN_10012972 at 10012972

undefined4 FUN_10012972(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = (**(code **)**(undefined4 **)(param_1 + 0x34))
                      (*(undefined4 **)(param_1 + 0x34),&DAT_10021fb4,param_2);
  }
  return uVar1;
}



// Function: FUN_10012999 at 10012999

void __thiscall FUN_10012999(void *this,HWND param_1)

{
  int iVar1;
  
  iVar1 = FUN_10003370(this,param_1);
  *(uint *)((int)this + 200) =
       *(uint *)((int)this + 200) ^ (iVar1 << 4 ^ *(uint *)((int)this + 200)) & 0x10;
  return;
}



// Function: FUN_100129be at 100129be

void __fastcall FUN_100129be(void *param_1)

{
  uint *puVar1;
  LONG LVar2;
  
  puVar1 = (uint *)((int)param_1 + 200);
  if ((*(byte *)puVar1 & 0x10) == 0) {
    DestroyWindow(*(HWND *)((int)param_1 + 4));
  }
  else {
    LVar2 = FUN_100121a4(param_1,1);
    if (LVar2 != 0) {
      *puVar1 = *puVar1 & 0xffffffef;
      return;
    }
  }
  return;
}



// Function: FUN_100129e5 at 100129e5

undefined4 FUN_100129e5(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_4 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_4 = 0;
    piVar1 = *(int **)(param_1 + 0x9c);
    uVar2 = 0x80004002;
    if (piVar1 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2,param_3,param_4);
    }
  }
  return uVar2;
}



// Function: FUN_10012a1c at 10012a1c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10012a1c(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10012a41 at 10012a41

LRESULT __fastcall FUN_10012a41(int param_1)

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



// Function: FUN_10012a65 at 10012a65

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10012a65(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022844,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10012aa0 at 10012aa0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10012aa0(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022854,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10012adb at 10012adb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10012adb(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022864,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10012b16 at 10012b16

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10012b16(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022874,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10012be5 at 10012be5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10012be5(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 4;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    local_14[0] = (int *)0x0;
    param_1 = (int *)0x0;
    local_8 = 3;
    iVar2 = (**(code **)*piVar1)(piVar1,&DAT_10021edc,local_14);
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(*local_14[0] + 0x10))(local_14[0],param_2,&param_1), -1 < iVar2)) {
      iVar2 = (**(code **)(*param_1 + 0x18))(param_1,param_3);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  return iVar2;
}



// Function: FUN_10012dfb at 10012dfb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10012dfb(int param_1)

{
  FUN_10003560(param_1);
  return;
}



// Function: FUN_10012e19 at 10012e19

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10012e19(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10003560(param_1);
  return;
}



// Function: FUN_10012e55 at 10012e55

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_10012e55(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10012e61;
  FUN_10012a65(local_14,*(undefined4 **)((int)this + 0x60));
  local_8 = 0;
  if ((local_14[0] != (int *)0x0) &&
     (iVar1 = (**(code **)(*local_14[0] + 0x14))(local_14[0],param_3), iVar1 == 0)) {
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    return 1;
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return 0;
}



// Function: FUN_10012eb5 at 10012eb5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10012eb5(int param_1)

{
  int *piVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10012ec1;
  if ((*(uint *)(param_1 + 0x98) & 0x40) == 0) {
    *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) | 0x40;
    piVar1 = *(int **)(param_1 + 0x70);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1,1,0,0);
    }
    if (*(int *)(param_1 + 0x94) != -0x32323233) {
      FUN_10012be5(*(int **)(param_1 + 0x60),param_1 + 0x80,*(int *)(param_1 + 0x94));
      *(undefined4 *)(param_1 + 0x94) = 0xcdcdcdcd;
    }
    piVar1 = *(int **)(param_1 + 100);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x50))(piVar1,*(undefined4 *)(param_1 + 0x9c));
      (**(code **)(**(int **)(param_1 + 100) + 0x18))(*(int **)(param_1 + 100),1);
      (**(code **)(**(int **)(param_1 + 100) + 0xc))(*(int **)(param_1 + 100),0);
    }
    if (*(int *)(param_1 + 0x60) != 0) {
      local_14[0] = (int *)0x0;
      local_8 = 1;
      (**(code **)**(undefined4 **)(param_1 + 0x60))
                (*(undefined4 **)(param_1 + 0x60),&DAT_100228b8,local_14);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 0xc))(local_14[0],0);
      }
      local_8 = 0xffffffff;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    piVar1 = *(int **)(param_1 + 0x70);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x70) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0x90) = 0;
    piVar1 = *(int **)(param_1 + 0x74);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x74) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 100);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 100) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 0x60);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x60) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 0x6c);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x6c) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 0x68);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x68) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) & 0xffffffa4;
    if (*(HACCEL *)(param_1 + 0xc4) != (HACCEL)0x0) {
      DestroyAcceleratorTable(*(HACCEL *)(param_1 + 0xc4));
      *(undefined4 *)(param_1 + 0xc4) = 0;
    }
  }
  return;
}



// Function: FUN_10013007 at 10013007

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10013007(void *this)

{
  undefined4 *puVar1;
  HWND pHVar2;
  BOOL BVar3;
  undefined4 *in_stack_00000010;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10013013;
  *(uint *)((int)this + 0x98) = *(uint *)((int)this + 0x98) | 0x20;
  if ((*(uint *)((int)this + 0x98) & 0x40) == 0) {
    if ((*(int *)((int)this + 100) != 0) && ((*(uint *)((int)this + 0x98) & 2) == 0)) {
      local_14[0] = (int *)0x0;
      local_8 = 1;
                    /* WARNING: Load size is inaccurate */
      puVar1 = (undefined4 *)(**(code **)(*this + 0x10))();
      (**(code **)*puVar1)(puVar1,&DAT_10022854,local_14);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(**(int **)((int)this + 100) + 0x2c))
                  (*(int **)((int)this + 100),0xfffffffc,0,local_14[0],0,
                   *(undefined4 *)((int)this + 4),(int)this + 0xb4);
      }
      local_8 = 0xffffffff;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    if ((*(byte *)((int)this + 0x98) & 8) == 0) {
      pHVar2 = GetFocus();
      BVar3 = IsChild(*(HWND *)((int)this + 4),pHVar2);
      if (BVar3 != 0) goto LAB_100130b6;
      pHVar2 = GetWindow(*(HWND *)((int)this + 4),5);
    }
    else {
      pHVar2 = *(HWND *)((int)this + 4);
    }
    SetFocus(pHVar2);
  }
LAB_100130b6:
  *in_stack_00000010 = 0;
  return 0;
}



// Function: FUN_100130c5 at 100130c5

undefined4 __thiscall
FUN_100130c5(void *this,UINT param_1,WPARAM param_2,LPARAM param_3,undefined4 *param_4)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = (int *)(**(code **)(*this + 0x10))();
  (**(code **)(*piVar1 + 4))(piVar1);
  CallWindowProcW(*(WNDPROC *)((int)this + 0x20),*(HWND *)((int)this + 4),param_1,param_2,param_3);
  FUN_10012eb5((int)this);
  *param_4 = 0;
  return 0;
}



// Function: FUN_100130ff at 100130ff

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100130ff(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3,param_4,local_14,&DAT_10022ffc,0,0)
  ;
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar1;
}



// Function: FUN_10013152 at 10013152

undefined4 FUN_10013152(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0x54) != param_2) {
    FUN_1000131f((int *)(param_1 + 0x54),param_2);
  }
  return 0;
}



// Function: FUN_1001316f at 1001316f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_1001316f(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  uVar1 = (**(code **)(*param_1 + 0x28))
                    (param_1,param_2,param_3,param_4,local_14,&DAT_10022ffc,0,param_5);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar1;
}



// Function: FUN_100131c3 at 100131c3

uint FUN_100131c3(uint param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
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



// Function: FUN_10013201 at 10013201

undefined4 FUN_10013201(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0x80004003;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x34);
    if (piVar1 == (int *)0x0) {
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x98);
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x9c);
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,param_2 + 4,param_2 + 8);
    }
  }
  return uVar2;
}



// Function: FUN_10013246 at 10013246

uint FUN_10013246(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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



// Function: FUN_10013282 at 10013282

undefined4 FUN_10013282(int param_1)

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



// Function: FUN_1001329b at 1001329b

undefined4 FUN_1001329b(int param_1)

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



// Function: FUN_100132b4 at 100132b4

undefined4 FUN_100132b4(int param_1,int param_2)

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



// Function: FUN_100132d5 at 100132d5

undefined4 FUN_100132d5(int param_1,int param_2)

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



// Function: FUN_100132f6 at 100132f6

undefined4 FUN_100132f6(int param_1,int param_2)

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



// Function: FUN_10013317 at 10013317

undefined4 FUN_10013317(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)

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



// Function: FUN_10013349 at 10013349

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10013349(int param_1,undefined4 *param_2,GUID *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10013355;
  piVar1 = *(int **)(param_1 + 0x34);
  local_14[0] = 1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)FUN_10012333(&param_1,param_3);
    local_8 = 0;
    (**(code **)(*piVar1 + 0x40))
              (piVar1,*param_2,param_2[1],param_2[2],param_2[3],*puVar2,param_4,local_14);
    local_8 = 0xffffffff;
    Ordinal_6(param_1);
  }
  return local_14[0];
}



// Function: FUN_100133ab at 100133ab

int FUN_100133ab(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  LPVOID pvVar4;
  int iVar5;
  
  iVar5 = 1;
  if (param_2 == (int *)0x0) {
    iVar5 = -0x7fffbffd;
  }
  else {
    *param_2 = 0;
    piVar1 = *(int **)(param_1 + 0x34);
    if (piVar1 == (int *)0x0) {
      iVar3 = Ordinal_7(*(undefined4 *)(param_1 + 0xa0));
      if (iVar3 != 0) {
        iVar5 = lstrlenW(*(LPCWSTR *)(param_1 + 0xa0));
        pvVar4 = CoTaskMemAlloc((iVar5 + 1) * 2);
        if (pvVar4 == (LPVOID)0x0) {
          iVar5 = -0x7ff8fff2;
        }
        else {
          bVar2 = FUN_10006397(pvVar4,iVar5 + 1,*(LPCWSTR *)(param_1 + 0xa0));
          if (bVar2) {
            *param_2 = (int)pvVar4;
            iVar5 = 0;
          }
          else {
            iVar5 = -0x7fffbffb;
          }
        }
      }
    }
    else {
      iVar5 = (**(code **)(*piVar1 + 0x44))(piVar1,param_2,param_3);
      if ((iVar5 < 0) || (*param_2 == 0)) {
        iVar5 = 1;
      }
    }
  }
  return iVar5;
}



// Function: FUN_1001344e at 1001344e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_1001344e(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uStack_30;
  int *piStack_2c;
  undefined4 uStack_28;
  int **ppiStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar4 = param_3;
  uStack_4 = 0;
  puVar7 = (undefined4 *)auStack_20;
  if (param_3 == (int *)0x0) {
    iVar6 = -0x7fffbffd;
    goto LAB_100134cb;
  }
  *param_3 = 0;
  iVar6 = -0x7fffbfff;
  if (*(int *)(param_1 + 0x34) == 0) goto LAB_100134cb;
  param_3 = (int *)0x0;
  local_8 = 1;
  piStack_2c = *(int **)(param_1 + 0x34);
  ppiStack_24 = &param_3;
  uStack_28 = param_2;
  puVar7 = &uStack_30;
  uStack_30 = 0x10013495;
  iVar6 = (**(code **)(*piStack_2c + 0x48))();
  piVar5 = param_3;
  if ((iVar6 < 0) || (param_3 == (int *)0x0)) {
LAB_100134b6:
    iVar6 = -0x7fffbfff;
  }
  else {
    puVar1 = (undefined4 *)*param_3;
    puVar7[-1] = piVar4;
    puVar7[-2] = &DAT_100228c8;
    puVar7[-3] = piVar5;
    pcVar2 = (code *)*puVar1;
    puVar8 = puVar7 + -4;
    puVar7 = puVar7 + -4;
    *puVar8 = 0x100134ab;
    iVar6 = (*pcVar2)();
    if ((iVar6 < 0) || (*piVar4 == 0)) goto LAB_100134b6;
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    iVar3 = *param_3;
    *(int **)((int)puVar7 + -4) = param_3;
    pcVar2 = *(code **)(iVar3 + 8);
    puVar9 = (undefined4 *)((int)puVar7 + -8);
    puVar7 = (undefined4 *)((int)puVar7 + -8);
    *puVar9 = 0x100134c9;
    (*pcVar2)();
  }
LAB_100134cb:
  *(undefined4 *)((int)puVar7 + -4) = 0x100134d0;
  return iVar6;
}



// Function: FUN_100134d3 at 100134d3

int FUN_100134d3(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *param_2 = 0;
    piVar1 = *(int **)(param_1 + 0x34);
    if (piVar1 == (int *)0x0) {
      iVar2 = FUN_1001213b((void *)(param_1 + 0x30),param_2);
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1);
      if ((iVar2 < 0) || (*param_2 == 0)) {
        iVar2 = -0x7fffbffe;
      }
    }
  }
  return iVar2;
}



// Function: FUN_10013516 at 10013516

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10013516(void *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  void *pvVar2;
  int *cb;
  code *unaff_EDI;
  int local_14;
  
  pvVar2 = param_1;
  if (param_4 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_4 = 0;
  local_14 = 1;
  if (*(int *)((int)param_1 + 0x34) == 0) {
    return 1;
  }
  param_1 = (void *)0x0;
  cb = *(int **)((int)pvVar2 + 0x34);
  if (param_3 == 0) {
    param_3 = 0;
LAB_10013562:
    local_14 = (**(code **)(*cb + 0x50))(cb,param_2,param_3,&param_1);
    unaff_EDI = Ordinal_6_exref;
    Ordinal_6(param_3);
    if ((local_14 < 0) || (iVar1 = Ordinal_7(param_1), iVar1 == 0)) {
      local_14 = 1;
      goto LAB_100135f5;
    }
    iVar1 = Ordinal_7(param_1);
    cb = (int *)(iVar1 * 2 + 2);
    pvVar2 = CoTaskMemAlloc((SIZE_T)cb);
    *param_4 = pvVar2;
    if (pvVar2 == (LPVOID)0x0) {
      Ordinal_6(param_1);
      return -0x7ff8fff2;
    }
  }
  else {
    param_3 = Ordinal_2(param_3);
    if (param_3 != 0) goto LAB_10013562;
    pvVar2 = (void *)FUN_1000121b(-0x7ff8fff2);
  }
  FUN_10001235(pvVar2,(rsize_t)cb,param_1,(rsize_t)cb);
LAB_100135f5:
  (*unaff_EDI)(param_1);
  return local_14;
}



// Function: FUN_10013609 at 10013609

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int * FUN_10013609(int *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uStack_30;
  int *piStack_2c;
  undefined4 uStack_28;
  int **ppiStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar5 = param_3;
  piVar1 = param_1;
  uStack_4 = 0;
  puVar6 = (undefined4 *)auStack_20;
  if (param_3 == (int *)0x0) {
    param_3 = (int *)0x80004003;
  }
  else {
    *param_3 = 0;
    param_3 = (int *)0x1;
    if (param_1[0xd] != 0) {
      param_1 = (int *)0x0;
      local_8 = 1;
      piStack_2c = (int *)piVar1[0xd];
      ppiStack_24 = &param_1;
      uStack_28 = param_2;
      puVar6 = &uStack_30;
      uStack_30 = 0x1001364b;
      param_3 = (int *)(**(code **)(*piStack_2c + 0x54))();
      if (param_1 != (int *)0x0) {
        puVar6[-1] = piVar5;
        piVar1 = piVar1 + -9;
        puVar2 = (undefined4 *)*piVar1;
        puVar6[-2] = &DAT_100228d8;
        puVar6[-3] = piVar1;
        pcVar3 = (code *)*puVar2;
        puVar7 = puVar6 + -4;
        puVar6 = puVar6 + -4;
        *puVar7 = 0x10013661;
        param_3 = (int *)(*pcVar3)();
      }
      if (((int)param_3 < 0) || (*piVar5 == 0)) {
        param_3 = (int *)0x1;
      }
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        iVar4 = *param_1;
        *(int **)((int)puVar6 + -4) = param_1;
        pcVar3 = *(code **)(iVar4 + 8);
        puVar8 = (undefined4 *)((int)puVar6 + -8);
        puVar6 = (undefined4 *)((int)puVar6 + -8);
        *puVar8 = 0x10013685;
        (*pcVar3)();
      }
    }
  }
  *(undefined4 *)((int)puVar6 + -4) = 0x1001368d;
  return param_3;
}



// Function: FUN_10013690 at 10013690

undefined4 FUN_10013690(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 8) != param_2) {
    FUN_1000131f((int *)(param_1 + 8),param_2);
  }
  return 0;
}



// Function: FUN_100136ad at 100136ad

LRESULT __thiscall
FUN_100136ad(void *this,uint param_1,uint param_2,HWND param_3,undefined4 *param_4)

{
  int *piVar1;
  uint uVar2;
  HWND lParam;
  BOOL BVar3;
  uint nIDDlgItem;
  HWND pHVar4;
  LRESULT LVar5;
  
  lParam = param_3;
  uVar2 = param_1;
  pHVar4 = lParam;
  if (param_1 < 0x4f) {
    if (param_1 == 0x4e) {
      pHVar4 = (HWND)param_3->unused;
    }
    else if (param_1 == 0x2b) {
      if ((param_3->unused == 1) && (BVar3 = IsWindow((HWND)param_3[5].unused), BVar3 == 0))
      goto LAB_10013776;
      pHVar4 = (HWND)lParam[5].unused;
    }
    else if (param_1 == 0x2c) {
      if (param_3->unused == 1) goto LAB_10013776;
      nIDDlgItem = param_3[1].unused;
LAB_10013761:
      pHVar4 = GetDlgItem(*(HWND *)((int)this + 4),nIDDlgItem);
    }
    else if (param_1 == 0x2d) {
      pHVar4 = (HWND)param_3[3].unused;
    }
    else {
      if (param_1 < 0x2e) goto LAB_10013776;
      if (0x2f < param_1) {
        if (param_1 != 0x39) goto LAB_10013776;
        pHVar4 = (HWND)param_3[2].unused;
      }
    }
  }
  else if (param_1 == 0x111) {
    if (param_3 == (HWND)0x0) goto LAB_10013776;
  }
  else {
    if (param_1 < 0x114) goto LAB_10013776;
    if (0x115 < param_1) {
      if (param_1 < 0x132) goto LAB_10013776;
      if (0x138 < param_1) {
        if (param_1 != 0x210) goto LAB_10013776;
        FUN_10012a41((int)this);
        if (1 < (param_2 & 0xffff) - 1) {
          nIDDlgItem = param_2 >> 0x10;
          goto LAB_10013761;
        }
      }
    }
  }
  if (pHVar4 != (HWND)0x0) {
    if ((*(uint *)((int)this + 0x98) & 8) == 0) {
      LVar5 = SendMessageW(pHVar4,uVar2 + 0x2000,param_2,(LPARAM)lParam);
      return LVar5;
    }
    param_1 = 0;
    if ((*(uint *)((int)this + 0x98) & 1) == 0) {
      return 0;
    }
    piVar1 = *(int **)((int)this + 0x74);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    (**(code **)(*piVar1 + 0x24))(piVar1,uVar2 + 0x2000,param_2,lParam,&param_1);
    return param_1;
  }
LAB_10013776:
  *param_4 = 0;
  return 1;
}



// Function: FUN_100137cf at 100137cf

undefined4 FUN_100137cf(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x38;
  }
  if (*(int **)(iVar1 + 0x3c) != param_2) {
    FUN_1000131f((int *)(iVar1 + 0x3c),param_2);
  }
  return 0;
}



// Function: FUN_100137f7 at 100137f7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100137f7(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_100228e8,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10013832 at 10013832

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10013832(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_100228f8,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001386d at 1001386d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1001386d(int param_1)

{
  FUN_1000e352(param_1);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10013897 at 10013897

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10013897(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  
  if (param_4 == 3) {
    lVar1 = (ulonglong)(uint)(param_2 - param_1 >> 2) * 4;
    uVar2 = FUN_10016bb7(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    *(undefined4 *)((int)this + 8) = uVar2;
    uVar2 = FUN_100138f7();
    return uVar2;
  }
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  if (*(int **)((int)this + 4) != param_3) {
    FUN_1000131f((int *)((int)this + 4),param_3);
  }
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 8);
  *(int *)((int)this + 0x14) = param_4;
  return 0;
}



// Function: Catch@100138df at 100138df

undefined * Catch_100138df(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100138f1;
}



// Function: FUN_100138f7 at 100138f7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100138f7(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 8);
  if (*(int *)(unaff_ESI + 8) == 0) {
    uVar2 = 0x8007000e;
  }
  else {
    for (piVar4 = *(int **)(unaff_EBP + 8); piVar4 != unaff_EDI; piVar4 = piVar4 + 1) {
      iVar3 = FUN_100121f0(*(int **)(unaff_ESI + 0x10),piVar4);
      *(int *)(unaff_EBP + 0xc) = iVar3;
      if (iVar3 < 0) {
        piVar4 = *(int **)(unaff_ESI + 8);
        while (piVar4 < *(int **)(unaff_ESI + 0x10)) {
          piVar1 = (int *)*piVar4;
          piVar4 = piVar4 + 1;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
        }
        operator_delete__(*(void **)(unaff_ESI + 8));
        *(undefined4 *)(unaff_ESI + 0x10) = 0;
        *(undefined4 *)(unaff_ESI + 0xc) = 0;
        *(undefined4 *)(unaff_ESI + 8) = 0;
        return *(undefined4 *)(unaff_EBP + 0xc);
      }
      *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 4;
    }
    *(int *)(unaff_ESI + 0xc) =
         *(int *)(unaff_ESI + 8) + ((int)unaff_EDI - *(int *)(unaff_EBP + 8) >> 2) * 4;
    if (*(int **)(unaff_ESI + 4) != *(int **)(unaff_EBP + 0x10)) {
      FUN_1000131f((int *)(unaff_ESI + 4),*(int **)(unaff_EBP + 0x10));
    }
    *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 8);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_EBP + 0x14);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_100139a0 at 100139a0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_100139a0(void *this)

{
  undefined4 *puVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 **ppuVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int *in_stack_00000010;
  undefined4 *puStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x100139ac;
  ppuVar7 = (undefined4 **)auStack_20;
  *in_stack_00000010 = 0;
  if ((*(uint *)((int)this + 0xa0) & 0x4000) == 0) {
    puStack_24 = &stack0x00000010;
    FUN_10013007(this);
    ppuVar7 = (undefined4 **)auStack_20;
  }
  else if ((*(int *)((int)this + 100) != 0) && ((*(byte *)((int)this + 0x98) & 1) == 0)) {
    in_stack_00000010 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    ppuVar6 = &puStack_24;
    puStack_24 = (undefined4 *)0x100139dc;
    puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
    puVar1 = (undefined4 *)*puVar5;
    ppuVar6[-1] = &stack0x00000010;
    ppuVar6[-2] = (undefined4 *)&DAT_10022854;
    ppuVar6[-3] = puVar5;
    pcVar2 = (code *)*puVar1;
    ppuVar7 = ppuVar6 + -4;
    ppuVar6[-4] = (undefined4 *)0x100139ea;
    (*pcVar2)();
    if (in_stack_00000010 != (int *)0x0) {
      piVar3 = *(int **)((int)this + 100);
      iVar4 = *piVar3;
      *(int *)((int)ppuVar7 + -4) = (int)this + 0xb4;
      *(undefined4 *)((int)ppuVar7 + -8) = *(undefined4 *)((int)this + 4);
      *(undefined4 *)((int)ppuVar7 + -0xc) = 0;
      *(int **)((int)ppuVar7 + -0x10) = in_stack_00000010;
      *(undefined4 *)((int)ppuVar7 + -0x14) = 0;
      *(undefined4 *)((int)ppuVar7 + -0x18) = 0xfffffffb;
      *(int **)((int)ppuVar7 + -0x1c) = piVar3;
      pcVar2 = *(code **)(iVar4 + 0x2c);
      puVar8 = (undefined4 *)((int)ppuVar7 + -0x20);
      ppuVar7 = (undefined4 **)((int)ppuVar7 + -0x20);
      *puVar8 = 0x10013a09;
      (*pcVar2)();
    }
    local_8 = 0xffffffff;
    if (in_stack_00000010 != (int *)0x0) {
      iVar4 = *in_stack_00000010;
      *(int **)((int)ppuVar7 + -4) = in_stack_00000010;
      pcVar2 = *(code **)(iVar4 + 8);
      puVar9 = (undefined4 *)((int)ppuVar7 + -8);
      ppuVar7 = (undefined4 **)((int)ppuVar7 + -8);
      *puVar9 = 0x10013a1a;
      (*pcVar2)();
    }
  }
  *(undefined4 *)((int)ppuVar7 + -4) = 0x10013a2f;
  return 0;
}



// Function: FUN_10013a32 at 10013a32

undefined4 FUN_10013a32(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0x58) != param_2) {
    FUN_1000131f((int *)(param_1 + 0x58),param_2);
  }
  return 0;
}



// Function: FUN_10013a4f at 10013a4f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10013a4f(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10013a5b;
  uVar1 = 0;
  FUN_100137f7(local_14,*(undefined4 **)((int)this + 0x60));
  local_8 = 0;
  if (local_14[0] != (int *)0x0) {
    uVar1 = (**(code **)(*local_14[0] + 0x14))(local_14[0],param_1);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar1;
}



// Function: FUN_10013a98 at 10013a98

undefined4 FUN_10013a98(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x80) = param_2;
  FUN_10013a4f((void *)(param_1 + -0x4c),0xfffffd43);
  (**(code **)(*(int *)(param_1 + -0x20) + 100))((int *)(param_1 + -0x20),0,0);
  return 0;
}



// Function: FUN_10013ac9 at 10013ac9

undefined4 FUN_10013ac9(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x84) = param_2;
  FUN_10013a4f((void *)(param_1 + -0x4c),0xfffffd40);
  return 0;
}



// Function: FUN_10013aeb at 10013aeb

undefined4 FUN_10013aeb(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x88) = param_2;
  FUN_10013a4f((void *)(param_1 + -0x4c),0xfffffd3f);
  return 0;
}



// Function: FUN_10013b0d at 10013b0d

undefined4 FUN_10013b0d(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ (param_2 * 2 ^ *(uint *)(param_1 + 0x7c)) & 2;
  FUN_10013a4f((void *)(param_1 + -0x4c),0xfffffd3b);
  return 0;
}



// Function: FUN_10013b35 at 10013b35

undefined4 FUN_10013b35(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 2 ^ *(uint *)(param_1 + 0x7c)) & 4;
  FUN_10013a4f((void *)(param_1 + -0x4c),0xfffffd37);
  return 0;
}



// Function: FUN_10013b5e at 10013b5e

undefined4 FUN_10013b5e(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0x8c) != param_2) {
    FUN_1000131f((int *)(param_1 + 0x8c),param_2);
  }
  FUN_10013a4f((void *)(param_1 + -0x4c),0xfffffd41);
  return 0;
}



// Function: FUN_10013b8d at 10013b8d

undefined4 FUN_10013b8d(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 3 ^ *(uint *)(param_1 + 0x7c)) & 8;
  FUN_10013a4f((void *)(param_1 + -0x4c),0xfffffd3e);
  return 0;
}



// Function: FUN_10013bb6 at 10013bb6

undefined4 FUN_10013bb6(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x94) = param_2;
  FUN_10013a4f((void *)(param_1 + -0x4c),0xffffffff);
  return 0;
}



// Function: FUN_10013bd5 at 10013bd5

int FUN_10013bd5(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = FUN_100137cf(param_1,param_2);
  if ((-1 < iVar3) && (puVar1 = *(undefined4 **)(param_1 + 4), puVar1 != (undefined4 *)0x0)) {
    iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10022908,param_1 + 0xa4);
  }
  if ((param_2 == (int *)0x0) && (piVar2 = *(int **)(param_1 + 0xa4), piVar2 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return iVar3;
}



// Function: FUN_10013c2b at 10013c2b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10013c2b(void *this,int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  LPRECT lpRect;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10013c37;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)((int)this + 0x60);
  if ((int *)*piVar1 != param_1) {
    FUN_1000131f(piVar1,param_1);
  }
  local_14 = 0;
  piVar7 = (int *)((int)this + 100);
  (**(code **)*param_1)(param_1,&DAT_10022954,piVar7);
  piVar3 = (int *)*piVar7;
  if (piVar3 != (int *)0x0) {
    puVar2 = (uint *)((int)this + 0xa0);
    (**(code **)(*piVar3 + 0x58))(piVar3,1,puVar2);
    if ((*puVar2 & 0x20000) != 0) {
                    /* WARNING: Load size is inaccurate */
      puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
      FUN_10012aa0(&local_20,puVar5);
      local_8 = 0;
      (**(code **)(*(int *)*piVar7 + 0xc))((int *)*piVar7,local_20);
      local_8 = 0xffffffff;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
    }
    if ((char)param_2 == '\0') {
      FUN_10012adb(&param_2,(undefined4 *)*piVar7);
      local_8 = 3;
      if (param_2 == (int *)0x0) {
        if (param_3 != 0) {
          FUN_10012b16(&local_20,(undefined4 *)*piVar7);
          local_8._0_1_ = 4;
          if (local_20 != (int *)0x0) {
            local_14 = (**(code **)(*local_20 + 0x14))(local_20,param_3);
          }
          local_8 = CONCAT31(local_8._1_3_,3);
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          goto LAB_10013d2f;
        }
      }
      else {
        if (param_3 == 0) {
          local_14 = (**(code **)(*param_2 + 0x20))(param_2);
        }
        else {
          local_14 = (**(code **)(*param_2 + 0x14))(param_2,param_3);
        }
LAB_10013d2f:
        if (local_14 < 0) {
          if ((*puVar2 & 0x20000) != 0) {
            (**(code **)(*(int *)*piVar7 + 0xc))((int *)*piVar7,0);
          }
          *puVar2 = 0;
          piVar3 = (int *)*piVar7;
          if (piVar3 != (int *)0x0) {
            *piVar7 = 0;
            (**(code **)(*piVar3 + 8))(piVar3);
          }
          piVar3 = (int *)*piVar1;
          piVar7 = param_2;
          if (piVar3 != (int *)0x0) {
            *piVar1 = 0;
            (**(code **)(*piVar3 + 8))(piVar3);
            piVar7 = param_2;
          }
          goto LAB_10013fb5;
        }
      }
      local_8 = 0xffffffff;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    if ((*puVar2 & 0x20000) == 0) {
                    /* WARNING: Load size is inaccurate */
      puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
      FUN_10012aa0(&param_2,puVar5);
      local_8 = 0xb;
      (**(code **)(*(int *)*piVar7 + 0xc))((int *)*piVar7,param_2);
      local_8 = 0xffffffff;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    *(undefined4 *)((int)this + 0x90) = 0;
    piVar1 = (int *)((int)this + 0x70);
    local_14 = (*(code *)**(undefined4 **)*piVar7)((undefined4 *)*piVar7,&DAT_10022944,piVar1);
    if (local_14 < 0) {
      local_14 = (*(code *)**(undefined4 **)*piVar7)((undefined4 *)*piVar7,&DAT_10022934,piVar1);
      if (local_14 < 0) {
        local_14 = (*(code *)**(undefined4 **)*piVar7)((undefined4 *)*piVar7,&DAT_10022924,piVar1);
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
    puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
    FUN_10013832(&local_18,puVar5);
    local_8 = 0xe;
    (**(code **)(*(int *)*piVar7 + 0x4c))((int *)*piVar7,local_18,(int)this + 0x9c);
    piVar1 = (int *)*piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1,1,0,local_18);
    }
    (**(code **)(*(int *)*piVar7 + 0x14))((int *)*piVar7,L"AXWIN",0);
    if ((*(uint *)((int)this + 0xa0) & 0x400) == 0) {
      lpRect = (LPRECT)((int)this + 0xb4);
      GetClientRect(*(HWND *)((int)this + 4),lpRect);
      *(int *)((int)this + 0xac) = *(int *)((int)this + 0xbc) - lpRect->left;
      *(int *)((int)this + 0xb0) = *(int *)((int)this + 0xc0) - *(int *)((int)this + 0xb8);
      FUN_10012061((int *)((int)this + 0xac),(int *)((int)this + 0xa4));
      (**(code **)(*(int *)*piVar7 + 0x44))((int *)*piVar7,1,(int)this + 0xa4);
      (**(code **)(*(int *)*piVar7 + 0x48))((int *)*piVar7,1,(int)this + 0xa4);
      FUN_10011fec((int *)((int)this + 0xa4),(int *)((int)this + 0xac));
      *(LONG *)((int)this + 0xbc) = lpRect->left + *(int *)((int)this + 0xac);
      *(int *)((int)this + 0xc0) = *(int *)((int)this + 0xb0) + *(int *)((int)this + 0xb8);
                    /* WARNING: Load size is inaccurate */
      puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
      FUN_10012aa0(&param_2,puVar5);
      local_8._0_1_ = 0xf;
      local_14 = (**(code **)(*(int *)*piVar7 + 0x2c))
                           ((int *)*piVar7,0xfffffffb,0,param_2,0,*(undefined4 *)((int)this + 4),
                            lpRect);
      RedrawWindow(*(HWND *)((int)this + 4),(RECT *)0x0,(HRGN)0x0,0x507);
      local_8 = CONCAT31(local_8._1_3_,0xe);
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  local_1c = (int *)0x0;
  local_8 = 0x15;
  (**(code **)*param_1)(param_1,&DAT_100228b8,&local_1c);
  piVar1 = local_1c;
  piVar7 = local_1c;
  if (local_1c != (int *)0x0) {
    iVar4 = *local_1c;
                    /* WARNING: Load size is inaccurate */
    uVar6 = (**(code **)(*this + 0x10))();
    (**(code **)(iVar4 + 0xc))(piVar1,uVar6);
    piVar7 = local_1c;
  }
LAB_10013fb5:
  local_8 = 0xffffffff;
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 8))(piVar7);
  }
  return local_14;
}



// Function: FUN_10013fc8 at 10013fc8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10013fc8(undefined4 *param_1)

{
  FUN_1001386d((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumUnknown,&struct___s_GUID_const__GUID_00000100_0000_0000_c000_000000000046,struct_IUnknown*,class_ATL::_CopyInterface<struct_IUnknown>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_1002f230 + 4))();
  return param_1;
}



// Function: QueryInterface at 10014001

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10022988,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1001401b at 1001401b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1001401b(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumUnknown,&struct___s_GUID_const__GUID_00000100_0000_0000_c000_000000000046,struct_IUnknown*,class_ATL::_CopyInterface<struct_IUnknown>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_1000e454((int)param_1);
  return;
}



// Function: FUN_10014059 at 10014059

undefined4 * __thiscall FUN_10014059(void *this,byte param_1)

{
  FUN_1001401b((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10014078 at 10014078

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10014078(void *this,byte param_1)

{
  FUN_100114f8((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100140a9 at 100140a9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100140a9(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10013fc8(puVar1);
    }
    uVar2 = FUN_1001410c();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100140f5 at 100140f5

undefined * Catch_100140f5(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10014107;
}



// Function: FUN_1001410c at 1001410c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1001410c(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x14) != unaff_EDI) {
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
  }
  *unaff_ESI = *(int *)(unaff_EBP + -0x14);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10014123 at 10014123

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10014123(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_10003cfc(param_1);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return param_1;
}



// Function: FUN_10014159 at 10014159

undefined4 __thiscall
FUN_10014159(void *this,undefined4 param_1,uint param_2,uint param_3,HWND param_4,LRESULT *param_5,
            int param_6)

{
  int iVar1;
  LRESULT *pLVar2;
  undefined4 uVar3;
  LRESULT LVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  
  pLVar2 = param_5;
  if (param_6 == 0) {
    uVar6 = 1;
    if (param_2 == 0x14) {
      iVar1 = *(int *)((int)this + 0x70);
      *param_5 = 1;
joined_r0x100141b6:
      if (iVar1 != 0) {
        return 1;
      }
    }
    else {
      if (param_2 == 0xf) {
        param_6 = 1;
        LVar4 = FUN_100124a2(this);
LAB_100141b0:
        *pLVar2 = LVar4;
        iVar1 = param_6;
        goto joined_r0x100141b6;
      }
      if (param_2 == 5) {
        param_6 = 1;
        LVar4 = FUN_1001238a(this,5,param_3,param_4,&param_6);
        goto LAB_100141b0;
      }
      if (param_2 == 0x21) {
        param_6 = 1;
        LVar4 = FUN_100139a0(this);
        goto LAB_100141b0;
      }
      if (param_2 == 7) {
        param_6 = 1;
        LVar4 = FUN_10013007(this);
        goto LAB_100141b0;
      }
      if (param_2 == 8) {
        *(uint *)((int)this + 0x98) = *(uint *)((int)this + 0x98) & 0xffffffdf;
        *param_5 = 0;
      }
    }
    if (((*(uint *)((int)this + 0x98) & 8) != 0) && (param_2 - 0x200 < 0xf)) {
      param_5 = (LRESULT *)(-(uint)((*(uint *)((int)this + 0x98) & 0x10) != 0) & 3);
      if (param_5 == (LRESULT *)0x0) {
        piVar5 = *(int **)((int)this + 0x70);
        if (piVar5 == (int *)0x0) goto LAB_10014259;
        (**(code **)(*piVar5 + 0x30))
                  (piVar5,1,(int)this + 0xb4,(int)(short)param_4,(int)(short)((uint)param_4 >> 0x10)
                   ,0,&param_5);
      }
      if (param_5 == (LRESULT *)0x3) {
        uVar3 = 0x200;
        if (((((param_2 != 0x200) && (uVar3 = 0x202, param_2 != 0x202)) &&
             (uVar3 = 0x205, param_2 != 0x205)) &&
            ((uVar3 = 0x208, param_2 != 0x208 && (uVar3 = 0x201, param_2 != 0x201)))) &&
           (((uVar3 = 0x204, param_2 != 0x204 &&
             ((uVar3 = 0x207, param_2 != 0x207 && (uVar3 = 0x203, param_2 != 0x203)))) &&
            (uVar3 = 0x206, param_2 != 0x206)))) {
          if (param_2 != 0x209) goto LAB_10014259;
          uVar3 = 0x209;
        }
        param_6 = 1;
        LVar4 = FUN_10012465(this,uVar3,param_3,param_4,&param_6);
        *pLVar2 = LVar4;
        if (param_6 != 0) {
          return 1;
        }
      }
    }
LAB_10014259:
    if ((*(uint *)((int)this + 0x98) >> 2 & *(uint *)((int)this + 0x98) & 8) == 0) {
LAB_100144c8:
      if (param_2 == 2) {
        param_6 = 1;
        LVar4 = FUN_100130c5(this,2,param_3,(LPARAM)param_4,&param_6);
        goto LAB_10014291;
      }
    }
    else {
      uVar7 = 0x100;
      if (((((param_2 != 0x100) && (uVar7 = 0x101, param_2 != 0x101)) &&
           (uVar7 = 0x102, param_2 != 0x102)) &&
          (((uVar7 = 0x103, param_2 != 0x103 && (uVar7 = 0x104, param_2 != 0x104)) &&
           ((uVar7 = 0x105, param_2 != 0x105 &&
            ((uVar7 = 0x107, param_2 != 0x107 && (uVar7 = param_2, param_2 != 0x53)))))))) &&
         (param_2 != 0x1f)) {
        if (param_2 == 0x286) {
          param_6 = 1;
          LVar4 = FUN_10012423(this,0x286,param_3,param_4,&param_6);
          *pLVar2 = LVar4;
          if (param_6 != 0) {
            return 1;
          }
        }
        else {
          if (param_2 == 0x209) goto LAB_10014287;
          if ((param_2 < 0x281) || (0x291 < param_2)) goto LAB_100144c8;
        }
        param_6 = 1;
        LVar4 = FUN_10012423(this,param_2,param_3,param_4,&param_6);
        *pLVar2 = LVar4;
        if (param_6 != 0) {
          return 1;
        }
        goto LAB_100144c8;
      }
LAB_10014287:
      param_6 = 1;
      LVar4 = FUN_10012423(this,uVar7,param_3,param_4,&param_6);
LAB_10014291:
      *pLVar2 = LVar4;
      if (param_6 != 0) {
        return 1;
      }
    }
    if ((*(byte *)((int)this + 200) & 8) != 0) {
      param_6 = 1;
      LVar4 = FUN_100136ad(this,param_2,param_3,param_4,&param_6);
      *pLVar2 = LVar4;
      if (param_6 != 0) {
        return 1;
      }
    }
    if (param_2 == DAT_100303bc) {
                    /* WARNING: Load size is inaccurate */
      piVar5 = (int *)(**(code **)(*this + 0x10))();
LAB_100142e4:
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    else {
      if (param_2 != DAT_100303c0) {
        if (param_2 == 0x37f) {
          LVar4 = FUN_10012e55(this,0x37f,param_3,param_4);
          *pLVar2 = LVar4;
          return 1;
        }
        goto LAB_10014525;
      }
      piVar5 = *(int **)((int)this + 0x60);
      if (piVar5 != (int *)0x0) goto LAB_100142e4;
    }
    *pLVar2 = (LRESULT)piVar5;
  }
  else {
LAB_10014525:
    uVar6 = 0;
  }
  return uVar6;
}



// Function: FUN_1001452e at 1001452e

int FUN_1001452e(int param_1,int *param_2,HWND param_3)

{
  void *this;
  HWND hWnd;
  BOOL BVar1;
  bool bVar2;
  undefined4 local_8;
  
  this = (void *)(param_1 + -0x24);
  local_8 = 1;
  FUN_10012eb5((int)this);
  hWnd = *(HWND *)(param_1 + -0x20);
  if ((hWnd != (HWND)0x0) && (hWnd != param_3)) {
    RedrawWindow(hWnd,(RECT *)0x0,(HRGN)0x0,0x507);
    FUN_100129be(this);
  }
  BVar1 = IsWindow(param_3);
  if (BVar1 != 0) {
    bVar2 = *(HWND *)(param_1 + -0x20) != param_3;
    if (bVar2) {
      FUN_10012999(this,param_3);
    }
    local_8 = FUN_10013c2b(this,param_2,(int *)0x1,0);
    if (local_8 < 0) {
      FUN_10012eb5((int)this);
      if (*(HWND *)(param_1 + -0x20) != (HWND)0x0) {
        RedrawWindow(*(HWND *)(param_1 + -0x20),(RECT *)0x0,(HRGN)0x0,0x507);
        if (bVar2) {
          FUN_100129be(this);
        }
      }
    }
  }
  return local_8;
}



// Function: FUN_10014980 at 10014980

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10014980(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10013fc8(puVar1);
    }
    iVar2 = FUN_100149df();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@100149ca at 100149ca

undefined * Catch_100149ca(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100149dc;
}



// Function: FUN_100149df at 100149df

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100149df(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI == (int *)0x0) {
    iVar1 = -0x7ff8fff2;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x2c);
    iVar1 = 3;
    piVar2 = (int *)(**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + -0x34) + 0x10))();
    iVar1 = FUN_10013897(unaff_ESI,unaff_EBP + -0x18,unaff_EBP + -0x14,piVar2,iVar1);
    if ((iVar1 < 0) || (iVar1 = (**(code **)*unaff_ESI)(), iVar1 < 0)) {
      (**(code **)(*unaff_ESI + 0x1c))(1);
    }
  }
  return iVar1;
}



// Function: FUN_10014a39 at 10014a39

undefined4 FUN_10014a39(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000f60d(&PTR_DAT_1002ea04,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10014a5d at 10014a5d

void FUN_10014a5d(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000f64d(&PTR_DAT_1002ea04,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10014a7d at 10014a7d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10014a7d(int *param_1,void **param_2)

{
  int *piVar1;
  int *local_1c;
  int local_18;
  uint local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xc;
  local_8 = 0x10014a89;
  local_14 = 0;
  local_18 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    local_18 = FUN_100140a9(&local_1c);
    if (-1 < local_18) {
      if ((*(byte *)(param_1 + 5) & 2) == 0) {
        param_1 = (int *)param_1[1];
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 4))(param_1);
        }
        local_8 = 3;
        local_14 = 2;
      }
      else {
        (**(code **)(*param_1 + 4))(param_1);
        local_8 = 1;
        local_14 = 1;
      }
      local_18 = FUN_10013897(local_1c,piVar1[2],piVar1[3],param_1,0);
      if ((local_14 & 2) != 0) {
        local_14 = local_14 & 0xfffffffd;
        local_8 = 1;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      local_8 = 0xffffffff;
      if ((local_14 & 1) != 0) {
        local_14 = local_14 & 0xfffffffe;
        local_8 = 0xffffffff;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      if (-1 < local_18) {
        local_1c[4] = piVar1[4];
        local_18 = ATL::AtlInternalQueryInterface
                             (local_1c,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10022988,(_GUID *)&DAT_100229a0
                              ,param_2);
        if (-1 < local_18) {
          return local_18;
        }
      }
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 0x1c))(1);
      }
    }
  }
  return local_18;
}



// Function: FUN_10014b90 at 10014b90

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10014b90(undefined4 *param_1)

{
  FUN_10014123((int)param_1);
  *param_1 = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  (**(code **)(*DAT_1002f230 + 4))();
  return param_1;
}



// Function: FUN_10014bd0 at 10014bd0

undefined4 FUN_10014bd0(void)

{
  return 0x800401a1;
}



// Function: FUN_10014bd8 at 10014bd8

undefined4 FUN_10014bd8(void)

{
  return 0;
}



// Function: FUN_10014bdd at 10014bdd

undefined4 FUN_10014bdd(void)

{
  return 0;
}



// Function: FUN_10014be2 at 10014be2

undefined4 FUN_10014be2(void)

{
  return 1;
}



// Function: FUN_10014be8 at 10014be8

undefined4 FUN_10014be8(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10014bf8 at 10014bf8

void FUN_10014bf8(int param_1,_GUID *param_2,void **param_3)

{
  ATL::AtlInternalQueryInterface
            ((void *)(param_1 + -0x24),(_ATL_INTMAP_ENTRY *)&PTR_DAT_10022a24,param_2,param_3);
  return;
}



// Function: FUN_10014c16 at 10014c16

ATOM FUN_10014c16(int param_1,WNDCLASSEXW *param_2)

{
  ATOM AVar1;
  
  if ((param_1 == 0) || (param_2 == (WNDCLASSEXW *)0x0)) {
    AVar1 = 0;
  }
  else {
    AVar1 = RegisterClassExW(param_2);
    param_2 = (WNDCLASSEXW *)(uint)AVar1;
    if (AVar1 != 0) {
      FUN_10011197((void *)(param_1 + 0x20),(undefined2 *)&param_2);
    }
  }
  return AVar1;
}



// Function: FUN_10014c55 at 10014c55

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10014c55(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[10] = 0xc0000001;
  FUN_10014f7f((int)param_1);
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_10012e19((int)param_1);
  return;
}



// Function: FUN_10014c9f at 10014c9f

undefined4 * __thiscall FUN_10014c9f(void *this,byte param_1)

{
  FUN_10014c55((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10014cbe at 10014cbe

void FUN_10014cbe(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *dwNewLong;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_1000af56(0x10030da8);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)param_1;
    iVar2 = (**(code **)(*piVar1 + 8))();
    FUN_10003198(piVar1 + 5,iVar2,piVar1);
    dwNewLong = (code *)piVar1[5];
    SetWindowLongW(param_1,-4,(LONG)dwNewLong);
    (*dwNewLong)(param_1,param_2,param_3,param_4);
  }
  return;
}



// Function: FUN_10014d0b at 10014d0b

HWND __thiscall
FUN_10014d0b(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,ushort param_7,LPVOID param_8)

{
  int iVar1;
  HWND pHVar2;
  
  iVar1 = FUN_10003198((void *)((int)this + 0x14),0,0);
  if (iVar1 == 0) {
    SetLastError(0xe);
  }
  else if (param_7 != 0) {
    FUN_1000aee0(0x10030da8,(DWORD *)((int)this + 8),(DWORD *)this);
    if ((param_6 == (HMENU)0x0) && ((param_4 & 0x40000000) != 0)) {
      param_6 = (HMENU)this;
    }
    if (param_2 == (int *)0x0) {
      param_2 = &DAT_1002db54;
    }
    pHVar2 = CreateWindowExW(param_5,(LPCWSTR)(uint)param_7,param_3,param_4,*param_2,param_2[1],
                             param_2[2] - *param_2,param_2[3] - param_2[1],param_1,param_6,
                             DAT_10030d70,param_8);
    return pHVar2;
  }
  return (HWND)0x0;
}



// Function: FUN_10014d9f at 10014d9f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 __cdecl FUN_10014d9f(int param_1,int param_2,WNDCLASSEXW *param_3,UINT *param_4)

{
  wchar_t *_Dst;
  LPCWSTR lpszClass;
  undefined2 uVar1;
  ATOM AVar2;
  BOOL BVar3;
  HINSTANCE pHVar4;
  HCURSOR pHVar5;
  int iVar6;
  tagWNDCLASSEXW *ptVar7;
  WNDCLASSEXW *pWVar8;
  tagWNDCLASSEXW local_80;
  tagWNDCLASSEXW local_50;
  LPCRITICAL_SECTION local_20;
  undefined1 local_1c;
  WNDPROC local_18;
  LPCWSTR local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x70;
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (WNDCLASSEXW *)0x0)) ||
     (param_4 == (UINT *)0x0)) {
LAB_10014e4e:
    uVar1 = 0;
  }
  else {
    if ((short)param_3[1].cbWndExtra == 0) {
      local_20 = (LPCRITICAL_SECTION)(param_2 + 4);
      local_1c = 0;
      local_8 = 0;
      EnterCriticalSection(local_20);
      local_1c = 1;
      if ((short)param_3[1].cbWndExtra == 0) {
        if ((LPCWSTR)param_3[1].cbSize == (LPCWSTR)0x0) {
          if (param_3[1].cbClsExtra == 0) {
            pHVar4 = *(HINSTANCE *)(param_1 + 8);
          }
          else {
            pHVar4 = (HINSTANCE)0x0;
          }
          pHVar5 = LoadCursorW(pHVar4,(LPCWSTR)param_3[1].lpfnWndProc);
          param_3->hCursor = pHVar5;
        }
        else {
          local_14 = param_3->lpszClassName;
          local_18 = param_3->lpfnWndProc;
          local_50.cbSize = 0x30;
          BVar3 = GetClassInfoExW((HINSTANCE)0x0,(LPCWSTR)param_3[1].cbSize,&local_50);
          if (BVar3 == 0) {
            BVar3 = GetClassInfoExW(*(HINSTANCE *)(param_1 + 4),(LPCWSTR)param_3[1].cbSize,&local_50
                                   );
            if (BVar3 == 0) {
              local_8 = 0xffffffff;
              LeaveCriticalSection(local_20);
              goto LAB_10014e4e;
            }
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
        pHVar4 = *(HINSTANCE *)(param_1 + 4);
        param_3->style = param_3->style & 0xffffbfff;
        param_3->hInstance = pHVar4;
        if (param_3->lpszClassName == (LPCWSTR)0x0) {
          _Dst = (wchar_t *)((int)&param_3[1].cbWndExtra + 2);
          swprintf_s(_Dst,0x25,L"ATL:%p",param_3);
          param_3->lpszClassName = _Dst;
        }
        lpszClass = param_3->lpszClassName;
        pWVar8 = param_3;
        ptVar7 = &local_80;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          ptVar7->cbSize = pWVar8->cbSize;
          pWVar8 = (WNDCLASSEXW *)&pWVar8->style;
          ptVar7 = (tagWNDCLASSEXW *)&ptVar7->style;
        }
        BVar3 = GetClassInfoExW(param_3->hInstance,lpszClass,&local_80);
        *(short *)&param_3[1].cbWndExtra = (short)BVar3;
        if ((short)BVar3 == 0) {
          AVar2 = FUN_10014c16(param_2,param_3);
          *(ATOM *)&param_3[1].cbWndExtra = AVar2;
        }
      }
      local_8 = 0xffffffff;
      LeaveCriticalSection(local_20);
    }
    if (param_3[1].cbSize != 0) {
      *param_4 = param_3[1].style;
    }
    uVar1 = (undefined2)param_3[1].cbWndExtra;
  }
  return uVar1;
}



// Function: FUN_10014f16 at 10014f16

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10014f16(undefined4 *param_1)

{
  FUN_10014123((int)param_1);
  *param_1 = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  (**(code **)(*DAT_1002f230 + 4))();
  return param_1;
}



// Function: FUN_10014f56 at 10014f56

undefined4 FUN_10014f56(void)

{
  return 0;
}



// Function: FUN_10014f5b at 10014f5b

undefined4 FUN_10014f5b(int param_1)

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



// Function: FUN_10014f7f at 10014f7f

void __fastcall FUN_10014f7f(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (*(HWND *)(param_1 + 4) != (HWND)0x0) {
    DestroyWindow(*(HWND *)(param_1 + 4));
  }
  return;
}



// Function: FUN_10014fa3 at 10014fa3

void FUN_10014fa3(int param_1,_GUID *param_2,void **param_3)

{
  ATL::AtlInternalQueryInterface
            ((void *)(param_1 + -0x24),(_ATL_INTMAP_ENTRY *)&PTR_DAT_10022ad0,param_2,param_3);
  return;
}



// Function: FUN_10014fc1 at 10014fc1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10014fc1(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[10] = 0xc0000001;
  FUN_10014f7f((int)param_1);
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_10012e19((int)param_1);
  return;
}



// Function: FUN_1001500b at 1001500b

undefined4 * __thiscall FUN_1001500b(void *this,byte param_1)

{
  FUN_10014fc1((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001502a at 1001502a

undefined4 FUN_1001502a(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 8) != param_2) {
    FUN_1000131f((int *)(param_1 + 8),param_2);
  }
  return 0;
}



// Function: FUN_10015047 at 10015047

void FUN_10015047(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_1000f6ee(&PTR_DAT_1002ea04,param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                       param_8,param_9);
  if (((iVar2 == -0x7ffdfffd) || (iVar2 == -0x7ffd7fd5)) &&
     (piVar1 = *(int **)(param_1 + 8), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    if ((-1 < iVar2) && ((param_5 & 4) != 0)) {
      FUN_10013a4f((void *)(param_1 + -0x4c),param_2);
    }
  }
  return;
}



// Function: FUN_100150be at 100150be

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100150be(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComPolyObject<class_ATL::CAxHostWindow>::vftable;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)this;
  }
  FUN_100118e4((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1002f230 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10015108 at 10015108

long FUN_10015108(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10022b08,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10015154 at 10015154

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10015154(undefined4 *param_1)

{
  *param_1 = ATL::CComPolyObject<class_ATL::CAxHostWindow>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10012eb5((int)(param_1 + 2));
  (**(code **)(*DAT_1002f230 + 8))();
  FUN_100114f8((int)(param_1 + 2));
  return;
}



// Function: FUN_100151a1 at 100151a1

undefined4 * __thiscall FUN_100151a1(void *this,byte param_1)

{
  FUN_10015154((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100151c0 at 100151c0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100151c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x30);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10014b90(puVar1);
    }
    uVar2 = FUN_10015223();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1001520c at 1001520c

undefined * Catch_1001520c(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001521e;
}



// Function: FUN_10015223 at 10015223

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10015223(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x14) != unaff_EDI) {
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
  }
  *unaff_ESI = *(int *)(unaff_EBP + -0x14);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1001523a at 1001523a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1001523a(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x30);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10014f16(puVar1);
    }
    uVar2 = FUN_1001529d();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10015286 at 10015286

undefined * Catch_10015286(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015298;
}



// Function: FUN_1001529d at 1001529d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1001529d(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x14) != unaff_EDI) {
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
  }
  *unaff_ESI = *(int *)(unaff_EBP + -0x14);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100152b4 at 100152b4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_100152b4(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x100152c0;
  uVar6 = 0;
  puVar4 = FUN_10001dd5((void *)((int)this + 0x7c),param_1,0,0xffffffff);
  puVar8 = auStack_20;
  if (*(int *)((int)this + 0x28) != 0) {
    if (7 < (uint)param_1[5]) {
      param_1 = (int *)*param_1;
    }
    if (param_1 == (int *)0x0) {
      param_1 = (int *)0x0;
    }
    else {
      puVar8 = &stack0xffffffd8;
      param_1 = (int *)Ordinal_2();
      if (param_1 == (int *)0x0) {
        *(undefined4 *)(puVar8 + -4) = 0x8007000e;
        *(undefined4 *)(puVar8 + -8) = 0x10015328;
        FUN_1000121b(*(int *)(puVar8 + -4));
        pcVar3 = (code *)swi(3);
        uVar5 = (*pcVar3)();
        return uVar5;
      }
    }
    local_8 = 0;
    piVar1 = *(int **)((int)this + 0x28);
    *(int **)(puVar8 + -4) = param_1;
    iVar2 = *piVar1;
    *(int **)(puVar8 + -8) = piVar1;
    pcVar3 = *(code **)(iVar2 + 0x7c);
    puVar7 = puVar8 + -0xc;
    *(undefined4 *)(puVar8 + -0xc) = 0x100152f7;
    (*pcVar3)();
    local_8 = 0xffffffff;
    *(int **)(puVar7 + -4) = param_1;
    puVar8 = puVar7 + -8;
    *(undefined4 *)(puVar7 + -8) = 0x10015304;
    puVar4 = (undefined4 *)Ordinal_6();
    uVar6 = 1;
  }
  *(undefined4 *)(puVar8 + -4) = 0x1001530d;
  return CONCAT31((int3)((uint)puVar4 >> 8),uVar6);
}



// Function: FUN_10015329 at 10015329

undefined4 __thiscall FUN_10015329(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  LPCWSTR lpString;
  
  lpString = (LPCWSTR)((int)this + 0x44);
  puVar1 = FUN_10001dd5(lpString,param_1,0,0xffffffff);
  if (*(HWND *)((int)this + 4) != (HWND)0x0) {
    if (7 < *(uint *)((int)this + 0x58)) {
      lpString = *(LPCWSTR *)lpString;
    }
    puVar1 = (undefined4 *)SetWindowTextW(*(HWND *)((int)this + 4),lpString);
  }
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}



// Function: FUN_10015360 at 10015360

undefined4 __thiscall FUN_10015360(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  HWND hWnd;
  LPCWSTR lpString;
  
  lpString = (LPCWSTR)((int)this + 0x60);
  puVar1 = FUN_10001dd5(lpString,param_1,0,0xffffffff);
  if (*(HWND *)((int)this + 4) != (HWND)0x0) {
    if (7 < *(uint *)((int)this + 0x74)) {
      lpString = *(LPCWSTR *)lpString;
    }
    hWnd = GetDlgItem(*(HWND *)((int)this + 4),0xdc);
    puVar1 = (undefined4 *)SetWindowTextW(hWnd,lpString);
  }
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}



// Function: FUN_100153a3 at 100153a3

void __thiscall FUN_100153a3(void *this,UINT *param_1)

{
  FUN_10014d9f(0x10030d6c,0x10030da8,(WNDCLASSEXW *)this,param_1);
  return;
}



// Function: FUN_100153c3 at 100153c3

int FUN_100153c3(int param_1,int *param_2,int *param_3,LPRECT param_4,LPRECT param_5,
                undefined4 *param_6)

{
  int *this;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  HACCEL pHVar5;
  HWND pHVar6;
  undefined8 local_c;
  
  iVar1 = param_1;
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if ((((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) || (param_4 == (LPRECT)0x0)) ||
     (param_5 == (LPRECT)0x0)) {
    piVar4 = (int *)0x80004003;
  }
  else {
    piVar4 = (int *)(param_1 + 0x3c);
    if (*piVar4 == 0) {
      iVar3 = FUN_100151c0(&param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      (*(code *)**(undefined4 **)(param_1 + 0x24))
                ((undefined4 *)(param_1 + 0x24),&DAT_10022a54,piVar4);
    }
    this = (int *)(iVar1 + 0x40);
    if (*this == 0) {
      iVar3 = FUN_1001523a(&param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      (*(code *)**(undefined4 **)(param_1 + 0x24))
                ((undefined4 *)(param_1 + 0x24),&DAT_10022a64,this);
    }
    piVar4 = (int *)FUN_1001213b((void *)(iVar1 + 0x3c),param_2);
    if ((-1 < (int)piVar4) &&
       (param_2 = (int *)FUN_1001213b(this,param_3), piVar4 = param_2, -1 < (int)param_2)) {
      GetClientRect(*(HWND *)(iVar1 + -0x28),param_4);
      GetClientRect(*(HWND *)(iVar1 + -0x28),param_5);
      if (*(int *)(iVar1 + 0x98) == 0) {
        local_c._1_3_ = (uint3)((uint)(int)local_c >> 8) & 0xff;
        local_c._4_4_ = local_c._4_4_ & 0xffff0000;
        local_c._0_4_ = (uint)local_c._1_3_ << 8;
        pHVar5 = CreateAcceleratorTableW((LPACCEL)&local_c,1);
        *(HACCEL *)(iVar1 + 0x98) = pHVar5;
      }
      puVar2 = param_6;
      *param_6 = 0x14;
      param_6[1] = *(uint *)(iVar1 + 0x6c) >> 2 & 1;
      pHVar6 = GetParent(*(HWND *)(iVar1 + -0x28));
      puVar2[2] = pHVar6;
      puVar2[3] = *(undefined4 *)(iVar1 + 0x98);
      puVar2[4] = (uint)(*(int *)(iVar1 + 0x98) != 0);
      piVar4 = param_2;
    }
  }
  return (int)piVar4;
}



// Function: FUN_10015500 at 10015500

void __thiscall
FUN_10015500(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  ushort uVar1;
  
  if (DAT_1002eb58 == 0) {
    DAT_1002eb58 = 0;
  }
  uVar1 = FUN_100153a3(&DAT_1002eb28,(UINT *)((int)this + 0x20));
  if (param_4 == 0) {
    param_4 = 0x56000000;
  }
  if (param_3 == (LPCWSTR)0x0) {
    param_3 = (LPCWSTR)0x0;
  }
  FUN_10014d0b(this,param_1,param_2,param_3,param_4,param_5,param_6,uVar1,param_7);
  return;
}



// Function: FUN_1001555f at 1001555f

void __thiscall
FUN_1001555f(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  ushort uVar1;
  
  if (DAT_1002ec98 == 0) {
    DAT_1002ec98 = 0;
  }
  uVar1 = FUN_100153a3(&DAT_1002ec68,(UINT *)((int)this + 0x20));
  if (param_4 == 0) {
    param_4 = 0x56000000;
  }
  if (param_3 == (LPCWSTR)0x0) {
    param_3 = (LPCWSTR)0x0;
  }
  FUN_10014d0b(this,param_1,param_2,param_3,param_4,param_5,param_6,uVar1,param_7);
  return;
}



// Function: FUN_100155be at 100155be

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100155be(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0xf4);
    if (this != (void *)0x0) {
      FUN_100150be(this,param_1);
    }
    uVar1 = FUN_10015630();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1001561b at 1001561b

undefined * Catch_1001561b(void)

{
  int unaff_EBP;
  
  CException::Delete(*(CException **)(unaff_EBP + -0x20));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001562d;
}



// Function: FUN_10015630 at 10015630

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10015630(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[1] = unaff_ESI[1] + 1;
    unaff_ESI[1] = unaff_ESI[1] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0xc))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10015660 at 10015660

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10015660(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  HWND pHVar3;
  LPCWSTR pWVar4;
  int iVar5;
  HMENU hMenu;
  int *lParam;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  DWORD local_60;
  char local_59;
  int local_58;
  LPCWSTR **local_54 [5];
  uint local_40;
  tagRECT local_38;
  wchar_t local_28 [16];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 1;
  lParam = (int *)(param_1 + 0x28);
  FUN_10011123((void *)(param_1 + 4),0xdd,&DAT_1002233c,lParam);
  (**(code **)(*(int *)*lParam + 0x8c))((int *)*lParam,*(undefined4 *)(param_1 + 0x38));
  (**(code **)(*(int *)*lParam + 0x94))((int *)*lParam,*(undefined4 *)(param_1 + 0x3c));
  puVar1 = (undefined4 *)(param_1 + 0x7c);
  if (7 < *(uint *)(param_1 + 0x90)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  if (puVar1 == (undefined4 *)0x0) {
    local_58 = 0;
  }
  else {
    local_58 = Ordinal_2(puVar1);
    if (local_58 == 0) {
      FUN_1000121b(-0x7ff8fff2);
      goto LAB_10015876;
    }
  }
  local_8._0_1_ = 2;
  (**(code **)(*(int *)*lParam + 0x7c))((int *)*lParam,local_58);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_58);
  (**(code **)(*(int *)*lParam + 0x9c))((int *)*lParam,(*(char *)(param_1 + 0x2c) == '\0') - 1);
  if (*(char *)(param_1 + 0x2c) == '\x01') {
    FUN_10010fc0();
  }
  (**(code **)(*(int *)*lParam + 0xa4))((int *)*lParam,(*(char *)(param_1 + 0x2d) == '\0') - 1);
  uVar2 = -(uint)(*(char *)(param_1 + 0x2e) != '\0') & 5;
  pHVar3 = GetDlgItem(*(HWND *)(param_1 + 4),0xbc8);
  ShowWindow(pHVar3,uVar2);
  uVar2 = -(uint)(*(char *)(param_1 + 0x30) != '\0') & 5;
  pHVar3 = GetDlgItem(*(HWND *)(param_1 + 4),0xdc);
  ShowWindow(pHVar3,uVar2);
  pWVar4 = (LPCWSTR)(param_1 + 0x44);
  if (7 < *(uint *)(param_1 + 0x58)) {
    pWVar4 = *(LPCWSTR *)pWVar4;
  }
  SetWindowTextW(*(HWND *)(param_1 + 4),pWVar4);
  pWVar4 = (LPCWSTR)(param_1 + 0x60);
  if (7 < *(uint *)(param_1 + 0x74)) {
    pWVar4 = *(LPCWSTR *)pWVar4;
  }
  pHVar3 = GetDlgItem(*(HWND *)(param_1 + 4),0xdc);
  SetWindowTextW(pHVar3,pWVar4);
  FUN_10011448(param_1);
  lParam = (int *)0x0;
  local_60 = GetSystemMetrics(0);
  local_58 = GetSystemMetrics(1);
  GetWindowRect(*(HWND *)(param_1 + 4),&local_38);
  SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x0,
               (int)((local_38.left - local_38.right) + local_60) / 2,
               ((local_38.top - local_38.bottom) + local_58) / 2,0,0,5);
  FUN_10002350(local_54,L"software\\cummins\\intelect\\insite\\6.0\\users\\Administrator\\General");
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),4);
  if (local_40 < 8) {
    local_54[0] = (LPCWSTR **)local_54;
  }
  iVar5 = Open(&local_6c,(HKEY)0x80000002,(LPCWSTR)local_54[0],0x2001f);
  if (iVar5 == 0) {
    local_60 = 0x14;
    FUN_100014b7(&local_6c,(LPBYTE)local_28,L"EnableKeySwitchTimer",&local_60);
    iVar5 = wcscmp(L"TRUE",local_28);
    local_59 = '\x01' - (iVar5 != 0);
  }
LAB_10015876:
  SendMessageW(*(HWND *)(param_1 + 0xb8),0xf1,(uint)(local_59 == '\0'),(LPARAM)lParam);
  ATL::CRegKey::Close((CRegKey *)&local_6c);
  if (*(char *)(param_1 + 0x115) != '\0') {
    uVar2 = GetWindowLongW(*(HWND *)(param_1 + 4),-0x10);
    *(undefined1 *)(param_1 + 0x115) = 0;
    SetWindowLongW(*(HWND *)(param_1 + 4),-0x10,uVar2 | 0x80000);
    hMenu = GetSystemMenu(*(HWND *)(param_1 + 4),(BOOL)lParam);
    EnableMenuItem(hMenu,0xf060,1);
  }
  local_8._0_1_ = 3;
  ATL::CRegKey::Close((CRegKey *)&local_6c);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_54,'\x01',(int)lParam);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(lParam);
  local_8 = 0xffffffff;
  Ordinal_6(lParam);
  FUN_100173c1();
  return;
}



// Function: FUN_10015916 at 10015916

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10015916(void *param_1)

{
  HANDLE hEvent;
  int iVar1;
  HWND hWnd;
  BOOL bEnable;
  wchar_t *local_34;
  int local_30 [10];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10015922;
  hEvent = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,L"WOProgressCancelEvent");
  ResetEvent(hEvent);
  if (*(char *)((int)param_1 + 0x116) == '\x01') {
    iVar1 = MessageBoxW(*(HWND *)((int)param_1 + 4),*(LPCWSTR *)((int)param_1 + 0x11c),
                        *(LPCWSTR *)((int)param_1 + 0x118),0x24);
    if (iVar1 == 6) {
      *(undefined1 *)((int)param_1 + 0x2f) = 1;
      local_34 = (wchar_t *)0x0;
      local_8 = 0;
      Ordinal_6(0);
      local_34 = (wchar_t *)0x0;
      FUN_100013ba(0xfa3,(int *)&local_34);
      FUN_10002350(local_30,local_34);
      local_8._0_1_ = 1;
      FUN_100152b4(param_1,local_30);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__Tidy(local_30,'\x01',0);
      bEnable = 0;
      hWnd = GetDlgItem(*(HWND *)((int)param_1 + 4),0xbc8);
      EnableWindow(hWnd,bEnable);
      local_8 = 0xffffffff;
      Ordinal_6(local_34);
    }
    else {
      *(undefined1 *)((int)param_1 + 0x2f) = 0;
    }
  }
  SetEvent(hEvent);
  FUN_100173c1();
  return;
}



// Function: FUN_100159ec at 100159ec

undefined4 FUN_100159ec(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(int *)(param_1 + -0x20) == 0) {
      FUN_10015500((void *)(param_1 + -0x24),(HWND)0x0,(int *)0x0,L"AXWIN Frame Window",0xcf0000,0,
                   (HMENU)0x0,(LPVOID)0x0);
    }
    *param_2 = *(undefined4 *)(param_1 + -0x20);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10015a35 at 10015a35

undefined4 FUN_10015a35(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    if (*(int *)(param_1 + -0x20) == 0) {
      FUN_1001555f((void *)(param_1 + -0x24),(HWND)0x0,(int *)0x0,L"AXWIN UI Window",0xcf0000,0,
                   (HMENU)0x0,(LPVOID)0x0);
    }
    *param_2 = *(undefined4 *)(param_1 + -0x20);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10015a85 at 10015a85

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10015a85(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10015a91;
  FUN_100161ef();
  local_14[0] = (int *)0x0;
  local_18 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  iVar1 = FUN_100155be((undefined4 *)0x0,&DAT_10020238,local_14);
  if (iVar1 < 0) {
LAB_10015b21:
    if (param_4 == (undefined4 *)0x0) goto LAB_10015b52;
    if (-1 < iVar1) {
      *param_4 = local_14[0];
      local_14[0] = (int *)0x0;
      goto LAB_10015b52;
    }
  }
  else {
    local_1c = (int *)0x0;
    local_8._0_1_ = 5;
    (**(code **)*local_14[0])(local_14[0],&DAT_10022bd4,&local_1c);
    if (param_1 == 0) {
      param_1 = 0;
LAB_10015ade:
      local_8._0_1_ = 6;
      iVar1 = (**(code **)(*local_1c + 0x28))
                        (local_1c,param_1,param_2,param_3,&local_18,param_6,param_7,param_8);
      local_8._0_1_ = 5;
      Ordinal_6(param_1);
      local_8._0_1_ = 3;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      goto LAB_10015b21;
    }
    param_1 = Ordinal_2(param_1);
    if (param_1 != 0) goto LAB_10015ade;
    param_4 = (undefined4 *)FUN_1000121b(-0x7ff8fff2);
  }
  *param_4 = 0;
LAB_10015b52:
  if (param_5 != (undefined4 *)0x0) {
    if (iVar1 < 0) {
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
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar1;
}



// Function: FUN_10015b95 at 10015b95

undefined4 __fastcall FUN_10015b95(void *param_1)

{
  if (*(char *)((int)param_1 + 0x116) == '\x01') {
    FUN_10015916(param_1);
  }
  else {
    *(undefined1 *)((int)param_1 + 0x2f) = 1;
  }
  return 0;
}



// Function: FUN_10015bae at 10015bae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall
FUN_10015bae(void *this,int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  iVar2 = FUN_100113e9(this,&DAT_10022578,(int *)local_14);
  if (iVar2 < 0) {
                    /* WARNING: Load size is inaccurate */
    iVar2 = FUN_10015a85(param_1,*this,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    local_18 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
                    /* WARNING: Load size is inaccurate */
    iVar2 = (**(code **)(*local_14[0] + 0x28))
                      (local_14[0],param_1,*this,param_2,&local_18,param_5,param_6,param_7);
    piVar1 = local_18;
    if (-1 < iVar2) {
      if (param_4 != (undefined4 *)0x0) {
        local_18 = (int *)0x0;
        *param_4 = piVar1;
      }
      if (param_3 != (undefined4 *)0x0) {
        iVar2 = (**(code **)*local_14[0])(local_14[0],&DAT_10020238,param_3);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



// Function: FUN_10015c79 at 10015c79

undefined4 __thiscall
FUN_10015c79(void *this,undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,int param_6)

{
  undefined4 uVar1;
  
  if (param_6 == 0) {
    if (param_2 == 0x110) {
      uVar1 = FUN_10015660((int)this);
    }
    else {
      if (((param_2 != 0x111) || ((short)param_3 != 0xbc8)) || ((short)((uint)param_3 >> 0x10) != 0)
         ) goto LAB_10015cd9;
      uVar1 = FUN_10015b95(this);
    }
    *param_5 = uVar1;
    uVar1 = 1;
  }
  else {
LAB_10015cd9:
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100161ef at 100161ef

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_100161ef(void)

{
  ATOM AVar1;
  BOOL BVar2;
  tagWNDCLASSEXW local_4c;
  undefined *local_1c;
  undefined1 local_18;
  uint local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_1c = &DAT_10030dac;
  local_18 = 0;
  local_8 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10030dac);
  local_18 = 1;
  DAT_100303bc = RegisterWindowMessageW(L"WM_ATLGETHOST");
  DAT_100303c0 = RegisterWindowMessageW(L"WM_ATLGETCONTROL");
  local_4c.cbSize = 0x30;
  BVar2 = GetClassInfoExW(DAT_10030d70,L"AtlAxWin100",&local_4c);
  if (BVar2 == 0) {
    local_4c.cbSize = 0x30;
    local_4c.style = 8;
    local_4c.lpfnWndProc = (WNDPROC)&LAB_10015ce0;
    local_4c.cbClsExtra = 0;
    local_4c.cbWndExtra = 0;
    local_4c.hInstance = DAT_10030d70;
    local_4c.hIcon = (HICON)0x0;
    local_4c.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_4c.hbrBackground = (HBRUSH)0x6;
    local_4c.lpszMenuName = (LPCWSTR)0x0;
    local_4c.lpszClassName = L"AtlAxWin100";
    local_4c.hIconSm = (HICON)0x0;
    AVar1 = RegisterClassExW(&local_4c);
    local_14[0] = (uint)AVar1;
    if (AVar1 != 0) {
      FUN_10011197(&DAT_10030dc8,(undefined2 *)local_14);
      goto LAB_100162bf;
    }
  }
  else {
LAB_100162bf:
    memset(&local_4c,0,0x30);
    local_4c.cbSize = 0x30;
    local_14[0] = GetClassInfoExW(DAT_10030d70,L"AtlAxWinLic100",&local_4c);
    if (local_14[0] != 0) goto LAB_10016360;
    local_4c.cbSize = 0x30;
    local_4c.style = 8;
    local_4c.lpfnWndProc = (WNDPROC)&LAB_10015f3f;
    local_4c.cbClsExtra = 0;
    local_4c.cbWndExtra = 0;
    local_4c.hInstance = DAT_10030d70;
    local_4c.hIcon = (HICON)0x0;
    local_4c.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_4c.hbrBackground = (HBRUSH)0x6;
    local_4c.lpszMenuName = (LPCWSTR)0x0;
    local_4c.lpszClassName = L"AtlAxWinLic100";
    local_4c.hIconSm = (HICON)0x0;
    AVar1 = RegisterClassExW(&local_4c);
    local_14[0] = (uint)AVar1;
    if (AVar1 != 0) {
      FUN_10011197(&DAT_10030dc8,(undefined2 *)local_14);
      local_14[0] = 1;
      goto LAB_10016360;
    }
  }
  local_14[0] = 0;
LAB_10016360:
  local_8 = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10030dac);
  return local_14[0];
}



// Function: FUN_10016377 at 10016377

INT_PTR __cdecl
FUN_10016377(HMODULE param_1,LPCWSTR param_2,HWND param_3,DLGPROC param_4,LPARAM param_5)

{
  HRSRC hResInfo;
  HRSRC hResInfo_00;
  HGLOBAL pvVar1;
  LPCDLGTEMPLATEW pDVar2;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR local_10;
  LPVOID local_c;
  DWORD local_8;
  
  FUN_100161ef();
  local_10 = -1;
  hResInfo = FindResourceW(param_1,param_2,(LPCWSTR)0x5);
  if (hResInfo != (HRSRC)0x0) {
    hResInfo_00 = FindResourceW(param_1,param_2,(LPCWSTR)0xf0);
    local_c = (LPVOID)0x0;
    if (hResInfo_00 != (HRSRC)0x0) {
      pvVar1 = LoadResource(param_1,hResInfo_00);
      local_c = LockResource(pvVar1);
    }
    local_8 = 0;
    pvVar1 = LoadResource(param_1,hResInfo);
    if ((pvVar1 == (HGLOBAL)0x0) ||
       (pDVar2 = (LPCDLGTEMPLATEW)LockResource(pvVar1), pDVar2 == (LPCDLGTEMPLATEW)0x0)) {
      local_8 = GetLastError();
    }
    else {
      hDialogTemplate = (LPCDLGTEMPLATEW)FUN_10010a13(pDVar2,local_c);
      local_10 = DialogBoxIndirectParamW(param_1,hDialogTemplate,param_3,param_4,param_5);
      if ((local_10 == 0) || (local_10 == -1)) {
        local_8 = GetLastError();
      }
      if (hDialogTemplate != pDVar2) {
        pvVar1 = GlobalHandle(hDialogTemplate);
        GlobalFree(pvVar1);
      }
    }
    if (local_8 != 0) {
      SetLastError(local_8);
    }
    return local_10;
  }
  return -1;
}



// Function: FUN_1001644c at 1001644c

HWND __cdecl
FUN_1001644c(HMODULE param_1,LPCWSTR param_2,HWND param_3,DLGPROC param_4,LPARAM param_5)

{
  HRSRC hResInfo;
  HRSRC hResInfo_00;
  HGLOBAL pvVar1;
  LPCDLGTEMPLATEW pDVar2;
  LPCDLGTEMPLATEW lpTemplate;
  HWND local_10;
  LPVOID local_c;
  DWORD local_8;
  
  FUN_100161ef();
  local_10 = (HWND)0x0;
  hResInfo = FindResourceW(param_1,param_2,(LPCWSTR)0x5);
  if (hResInfo != (HRSRC)0x0) {
    hResInfo_00 = FindResourceW(param_1,param_2,(LPCWSTR)0xf0);
    local_c = (LPVOID)0x0;
    if (hResInfo_00 != (HRSRC)0x0) {
      pvVar1 = LoadResource(param_1,hResInfo_00);
      local_c = LockResource(pvVar1);
    }
    local_8 = 0;
    pvVar1 = LoadResource(param_1,hResInfo);
    if ((pvVar1 == (HGLOBAL)0x0) ||
       (pDVar2 = (LPCDLGTEMPLATEW)LockResource(pvVar1), pDVar2 == (LPCDLGTEMPLATEW)0x0)) {
      local_8 = GetLastError();
    }
    else {
      lpTemplate = (LPCDLGTEMPLATEW)FUN_10010a13(pDVar2,local_c);
      local_10 = CreateDialogIndirectParamW(param_1,lpTemplate,param_3,param_4,param_5);
      if (local_10 == (HWND)0x0) {
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
    return local_10;
  }
  return (HWND)0x0;
}



// Function: FUN_1001651c at 1001651c

INT_PTR __thiscall FUN_1001651c(void *this,HWND param_1,LPARAM param_2)

{
  INT_PTR IVar1;
  
  FUN_1000aee0(0x10030da8,(DWORD *)((int)this + 8),(DWORD *)this);
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x20) = 1;
  IVar1 = FUN_10016377(DAT_10030d74,(LPCWSTR)0x136,param_1,FUN_1000b1d5,param_2);
  if (((int)*(DWORD *)((int)this + 0x24) < 0) && (IVar1 == -1)) {
    SetLastError(*(DWORD *)((int)this + 0x24));
  }
  return IVar1;
}



// Function: FUN_10016575 at 10016575

HWND __thiscall FUN_10016575(void *this,HWND param_1,LPARAM param_2)

{
  HWND pHVar1;
  
  FUN_1000aee0(0x10030da8,(DWORD *)((int)this + 8),(DWORD *)this);
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x20) = 0;
  pHVar1 = FUN_1001644c(DAT_10030d74,(LPCWSTR)0x136,param_1,FUN_1000b1d5,param_2);
  if ((*(int *)((int)this + 0x24) < 0) && (pHVar1 != (HWND)0x0)) {
    DestroyWindow(*(HWND *)((int)this + 4));
    SetLastError(*(DWORD *)((int)this + 0x24));
    pHVar1 = (HWND)0x0;
  }
  return pHVar1;
}



// Function: FUN_100165d3 at 100165d3

undefined4 FUN_100165d3(void *param_1)

{
  FUN_1001651c(param_1,*(HWND *)((int)param_1 + 0x110),0);
  return 0;
}



// Function: FUN_100165ec at 100165ec

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100165ec(void *this,ushort param_1)

{
  DWORD *pDVar1;
  ushort uVar2;
  uint uVar3;
  HWND hWnd;
  short sVar4;
  HRSRC pHVar5;
  HGLOBAL pvVar6;
  uint *puVar7;
  ushort *puVar8;
  DWORD *pDVar9;
  undefined4 uVar10;
  SIZE_T dwBytes;
  LPVOID pvVar11;
  DWORD DVar12;
  DWORD DVar13;
  HMENU pHVar14;
  ushort *local_48;
  undefined4 local_3c;
  HWND local_38;
  int local_34;
  uint local_30;
  LPSTREAM local_2c;
  HWND local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x100165f8;
  pHVar5 = FindResourceW(DAT_10030d74,(LPCWSTR)(uint)param_1,(LPCWSTR)0xf0);
  local_48 = (ushort *)0x0;
  local_28 = (HWND)0x0;
  if ((pHVar5 != (HRSRC)0x0) && (pvVar6 = LoadResource(DAT_10030d74,pHVar5), pvVar6 != (HGLOBAL)0x0)
     ) {
    local_48 = (ushort *)LockResource(pvVar6);
  }
  pHVar5 = FindResourceW(DAT_10030d74,(LPCWSTR)(uint)param_1,(LPCWSTR)0x5);
  if (pHVar5 != (HRSRC)0x0) {
    pvVar6 = LoadResource(DAT_10030d74,pHVar5);
    if ((pvVar6 == (HGLOBAL)0x0) || (puVar7 = (uint *)LockResource(pvVar6), puVar7 == (uint *)0x0))
    {
      local_28 = (HWND)FUN_1000640e();
    }
    else {
      local_30 = (uint)(*(short *)((int)puVar7 + 2) == -1);
      puVar8 = (ushort *)FUN_1001090f((int)puVar7);
      uVar2 = *puVar8;
      pDVar9 = (DWORD *)FUN_1001092a(puVar7);
      local_38 = GetWindow(*(HWND *)((int)this + 4),5);
      local_34 = 0;
      if (uVar2 != 0) {
        do {
          if (local_30 == 0) {
            DVar13 = (DWORD)(ushort)pDVar9[4];
          }
          else {
            DVar13 = pDVar9[5];
          }
          uVar10 = FUN_100112ee((int)pDVar9,local_30);
          if ((char)uVar10 == '\0') {
            if ((ushort)local_34 != 0) {
              local_38 = GetWindow(local_38,2);
            }
          }
          else {
            local_28 = (HWND)0x0;
            dwBytes = FUN_100112b0(DVar13,local_48,(int *)&local_28);
            local_2c = (IStream *)0x0;
            local_8 = 1;
            if (dwBytes != 0) {
              pvVar6 = GlobalAlloc(0x42,dwBytes);
              if (pvVar6 == (HGLOBAL)0x0) {
                local_28 = (HWND)0x8007000e;
              }
              else {
                pvVar11 = GlobalLock(pvVar6);
                if (pvVar11 != (LPVOID)0x0) {
                  FUN_10001235(pvVar11,dwBytes,local_28,dwBytes);
                  GlobalUnlock(pvVar6);
                  CreateStreamOnHGlobal(pvVar6,1,&local_2c);
                  goto LAB_10016743;
                }
                local_28 = (HWND)FUN_1000640e();
              }
LAB_1001690c:
              local_8 = 0xffffffff;
              if (local_2c != (IStream *)0x0) {
                (*local_2c->lpVtbl->Release)(local_2c);
              }
              break;
            }
LAB_10016743:
            local_3c = 0;
            local_8 = CONCAT31(local_8._1_3_,4);
            local_28 = (HWND)FUN_10010d63((int *)local_2c,&local_3c);
            if (-1 < (int)local_28) {
              local_28 = (HWND)0x0;
              FUN_100161ef();
              uVar3 = local_30;
              pDVar1 = pDVar9 + 6;
              if (local_30 == 0) {
                pDVar1 = (DWORD *)((int)pDVar9 + 0x12);
                sVar4 = (short)pDVar9[2];
              }
              else {
                sVar4 = (short)pDVar9[3];
              }
              local_24.left = (LONG)sVar4;
              if (local_30 == 0) {
                sVar4 = *(short *)((int)pDVar9 + 10);
              }
              else {
                sVar4 = *(short *)((int)pDVar9 + 0xe);
              }
              local_24.top = (LONG)sVar4;
              if (local_30 == 0) {
                sVar4 = (short)pDVar9[3];
              }
              else {
                sVar4 = (short)pDVar9[4];
              }
              local_24.right = sVar4 + local_24.left;
              if (local_30 == 0) {
                sVar4 = *(short *)((int)pDVar9 + 0xe);
              }
              else {
                sVar4 = *(short *)((int)pDVar9 + 0x12);
              }
              local_24.bottom = sVar4 + local_24.top;
              MapDialogRect(*(HWND *)((int)this + 4),&local_24);
              if (uVar3 == 0) {
                pHVar14 = (HMENU)(uint)(ushort)pDVar9[4];
              }
              else {
                pHVar14 = (HMENU)pDVar9[5];
              }
              if (local_30 == 0) {
                DVar13 = 0;
                DVar12 = *pDVar9;
              }
              else {
                DVar13 = pDVar9[1];
                DVar12 = pDVar9[2];
              }
              FUN_1001130b(&local_28,L"AtlAxWinLic100",*(HWND *)((int)this + 4),&local_24.left,
                           (LPCWSTR)0x0,DVar12 | 0x10000,DVar13,pHVar14,(LPVOID)0x0);
              hWnd = local_28;
              if (local_28 == (HWND)0x0) {
                local_28 = (HWND)FUN_1000640e();
              }
              else {
                if ((local_30 != 0) && (*pDVar9 != 0)) {
                  SetWindowContextHelpId(local_28,*pDVar9);
                }
                local_28 = (HWND)FUN_10015bae(&local_28,(int)pDVar1,local_2c,(undefined4 *)0x0,
                                              (undefined4 *)0x0,&DAT_10022ffc,0,local_3c);
                if ((int)local_28 < 0) {
                  local_8 = CONCAT31(local_8._1_3_,1);
                  Ordinal_6(local_3c);
                  goto LAB_1001690c;
                }
                if ((ushort)local_34 == 0) {
                  local_38 = (HWND)0x0;
                }
                SetWindowPos(hWnd,local_38,0,0,0,0,0x13);
                local_38 = hWnd;
              }
            }
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_6(local_3c);
            local_8 = 0xffffffff;
            if (local_2c != (IStream *)0x0) {
              (*local_2c->lpVtbl->Release)(local_2c);
            }
          }
          pDVar9 = (DWORD *)FUN_100109b0((int)pDVar9,local_30);
          local_34 = local_34 + 1;
        } while ((ushort)local_34 < uVar2);
      }
    }
  }
  FUN_100173c1();
  return;
}



// Function: FUN_10016929 at 10016929

uint __thiscall FUN_10016929(void *this,HWND param_1,char param_2)

{
  HWND pHVar1;
  HWND pHVar2;
  LPARAM LVar3;
  
  *(char *)((int)this + 0x114) = param_2;
  *(undefined1 *)((int)this + 0x2f) = 0;
  if (param_2 == '\0') {
    pHVar1 = FUN_10016575(this,param_1,0);
    pHVar2 = *(HWND *)((int)this + 4);
  }
  else {
    *(HWND *)((int)this + 0x110) = param_1;
    if (*(char *)((int)this + 0x121) == '\0') {
      pHVar1 = (HWND)CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10010d09,this,0,(LPDWORD)&param_2
                                 );
      *(HWND *)((int)this + 0x10c) = pHVar1;
      if (pHVar1 != (HWND)0x0) {
        LVar3 = 0;
        *(undefined1 *)((int)this + 0x121) = 1;
        pHVar2 = GetActiveWindow();
        pHVar1 = (HWND)FUN_1001651c(this,pHVar2,LVar3);
        goto LAB_1001698a;
      }
      goto LAB_10016970;
    }
    pHVar1 = (HWND)CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100165d3,this,0,(LPDWORD)&param_2);
    *(HWND *)((int)this + 0x10c) = pHVar1;
    pHVar2 = pHVar1;
  }
  if (pHVar2 != (HWND)0x0) {
LAB_1001698a:
    return CONCAT31((int3)((uint)pHVar1 >> 8),1);
  }
LAB_10016970:
  return (uint)pHVar1 & 0xffffff00;
}



// Function: StringCchCopyA at 100169b9

/* Library Function - Single Match
    long __stdcall StringCchCopyA(char *,unsigned int,char const *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2015 Release */

long StringCchCopyA(char *param_1,uint param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  iVar1 = 0;
  if ((param_2 == 0) || (0x7fffffff < param_2)) {
    iVar1 = -0x7ff8ffa9;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  lVar2 = 0;
  if (param_2 != 0) {
    iVar3 = 0x7ffffffe - param_2;
    iVar1 = (int)param_3 - (int)param_1;
    do {
      if ((iVar3 + param_2 == 0) || (param_1[iVar1] == '\0')) break;
      *param_1 = param_1[iVar1];
      param_1 = param_1 + 1;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
    if (param_2 != 0) goto LAB_10016a11;
  }
  param_1 = param_1 + -1;
  lVar2 = -0x7ff8ff86;
LAB_10016a11:
  *param_1 = '\0';
  return lVar2;
}



// Function: GetRegisteredLocation at 10016a1c

/* Library Function - Single Match
    int __stdcall GetRegisteredLocation(char *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2015 Release */

int GetRegisteredLocation(char *param_1)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD local_11c;
  DWORD local_118;
  char *local_114;
  HKEY local_110;
  BYTE local_10c [259];
  undefined1 local_9;
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  local_114 = param_1;
  LVar1 = RegOpenKeyExA((HKEY)0x80000000,
                        "CLSID\\{ADB880A6-D8FF-11CF-9377-00AA003B7A11}\\InprocServer32",0,0x20019,
                        &local_110);
  if (LVar1 == 0) {
    local_11c = 0x104;
    local_118 = 1;
    LVar1 = RegQueryValueExA(local_110,(LPCSTR)0x0,(LPDWORD)0x0,&local_118,local_10c,&local_11c);
    if (LVar1 == 0) {
      local_9 = 0;
      if (local_118 == 2) {
        ExpandEnvironmentStringsA((LPCSTR)local_10c,local_114,0x104);
      }
      else {
        StringCchCopyA(local_114,0x104,(char *)local_10c);
      }
    }
    RegCloseKey(local_110);
  }
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}



// Function: _HtmlHelpW@16 at 10016b02

/* Library Function - Single Match
    _HtmlHelpW@16
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2015 Release */

void _HtmlHelpW_16(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char local_10c [260];
  uint local_8;
  
  local_8 = DAT_1002edc8 ^ (uint)&stack0xfffffffc;
  if ((DAT_10030964 == (HMODULE)0x0) && (DAT_10030960 == 0)) {
    iVar1 = GetRegisteredLocation(local_10c);
    if (iVar1 != 0) {
      DAT_10030964 = LoadLibraryA(local_10c);
    }
    if (DAT_10030964 != (HMODULE)0x0) goto LAB_10016b81;
    DAT_10030964 = LoadLibraryA("hhctrl.ocx");
    if (DAT_10030964 != (HMODULE)0x0) goto LAB_10016b81;
LAB_10016b73:
    DAT_10030960 = 1;
  }
  else {
LAB_10016b81:
    if (DAT_1003095c == (FARPROC)0x0) {
      DAT_1003095c = GetProcAddress(DAT_10030964,(LPCSTR)0xf);
      if (DAT_1003095c == (FARPROC)0x0) goto LAB_10016b73;
    }
    (*DAT_1003095c)(param_1,param_2,param_3,param_4);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016bb7 at 10016bb7

void FUN_10016bb7(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_10016bc2 at 10016bc2

void __fastcall FUN_10016bc2(int param_1)

{
  facet *pfVar1;
  
  pfVar1 = std::locale::facet::_Decref(*(facet **)(param_1 + 4));
  if (pfVar1 != (facet *)0x0) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: Facet_Register at 10016bd8

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
    *puVar1 = DAT_10030968;
    puVar1[1] = param_1;
  }
  DAT_10030968 = puVar1;
  return;
}



// Function: FUN_10016c02 at 10016c02

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10016c02(void)

{
  undefined4 *puVar1;
  _Lockit local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10016c0e;
  std::_Lockit::_Lockit(local_14,0);
  local_8 = 0;
  while (puVar1 = DAT_10030968, DAT_10030968 != (undefined4 *)0x0) {
    DAT_10030968 = (undefined4 *)*DAT_10030968;
    FUN_10016bc2((int)puVar1);
    operator_delete(puVar1);
  }
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_14);
  return;
}



// Function: FUN_10017006 at 10017006

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

long FUN_10017006(HWND__ *param_1,uint param_2,uint param_3,long param_4)

{
  long lVar1;
  AFX_MAINTAIN_STATE2 local_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x10017012;
  FUN_1000d577();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_20,(AFX_MODULE_STATE *)&DAT_10030990);
  local_8 = 0;
  lVar1 = AfxWndProc(param_1,param_2,param_3,param_4);
  local_8 = 0xffffffff;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_20);
  return lVar1;
}



// Function: FUN_10017051 at 10017051

undefined * FUN_10017051(void)

{
  return &DAT_10030990;
}



// Function: FUN_10017057 at 10017057

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10017057(HINSTANCE__ *param_1,int param_2)

{
  _AFX_THREAD_STATE *p_Var1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  CDynLinkLibrary *this;
  AFX_MODULE_STATE *pAVar5;
  AFX_MAINTAIN_STATE2 local_34 [20];
  undefined4 local_20;
  _AFX_THREAD_STATE *local_1c;
  int *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x10017063;
  if (param_2 != 1) {
    if (param_2 == 0) {
      pAVar5 = AfxSetModuleState((AFX_MODULE_STATE *)&DAT_10030990);
      p_Var1 = AfxGetThreadState();
      *(AFX_MODULE_STATE **)(p_Var1 + 8) = pAVar5;
      piVar4 = (int *)FUN_100172b6();
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x70))();
      }
      AfxLockTempMaps();
      AfxUnlockTempMaps(-1);
      AfxWinTerm();
      AfxTermExtensionModule((AFX_EXTENSION_MODULE *)&DAT_1003097c,1);
      if (DAT_10030974 != 0) {
        p_Var1 = AfxGetThreadState();
        AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
      }
    }
    else if (param_2 == 3) {
      AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(local_34,(AFX_MODULE_STATE *)&DAT_10030990);
      local_8 = 3;
      AfxLockTempMaps();
      AfxUnlockTempMaps(-1);
      AfxTermThread(param_1);
      local_8 = 0xffffffff;
      AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(local_34);
    }
    return 1;
  }
  AfxCoreInitModule();
  p_Var1 = AfxGetThreadState();
  uVar3 = *(undefined4 *)(p_Var1 + 8);
  local_20 = uVar3;
  local_1c = p_Var1;
  iVar2 = AfxWinInit(param_1,(HINSTANCE__ *)0x0,(wchar_t *)&PTR_1001fc90,0);
  if (iVar2 == 0) {
LAB_1001709a:
    AfxWinTerm();
    uVar3 = FUN_1001712d();
    return uVar3;
  }
  piVar4 = (int *)FUN_100172b6();
  local_18 = piVar4;
  if (piVar4 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar4 + 0x58))();
    if (iVar2 == 0) {
      (**(code **)(*piVar4 + 0x70))();
      goto LAB_1001709a;
    }
  }
  *(undefined4 *)(p_Var1 + 8) = uVar3;
  AfxInitExtensionModule((AFX_EXTENSION_MODULE *)&DAT_1003097c,param_1);
  local_8 = 0;
  this = (CDynLinkLibrary *)FUN_100172a4(0x40);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (CDynLinkLibrary *)0x0) {
    CDynLinkLibrary::CDynLinkLibrary(this,(AFX_EXTENSION_MODULE *)&DAT_1003097c,0);
  }
  local_8 = 0xffffffff;
  uVar3 = FUN_1001712d();
  return uVar3;
}



// Function: Catch@10017104 at 10017104

undefined * Catch_10017104(void)

{
  int unaff_EBP;
  
  if (*(CException **)(unaff_EBP + -0x20) != (CException *)0x0) {
    CException::Delete(*(CException **)(unaff_EBP + -0x20));
  }
  (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x70))();
  AfxWinTerm();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10017127;
}



// Function: FUN_1001712d at 1001712d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1001712d(void)

{
  _AFX_THREAD_STATE *p_Var1;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = unaff_EBX;
  p_Var1 = AfxGetThreadState();
  AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
  return *(undefined4 *)(unaff_EBP + 0xc);
}



// Function: _RawDllMain@12 at 100171e7

/* Library Function - Single Match
    _RawDllMain@12
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 _RawDllMain_12(undefined4 param_1,int param_2)

{
  HLOCAL hMem;
  _AFX_THREAD_STATE *p_Var1;
  AFX_MODULE_STATE *pAVar2;
  
  if (param_2 == 1) {
    hMem = LocalAlloc(0,0x2000);
    if (hMem == (HLOCAL)0x0) {
      return 0;
    }
    LocalFree(hMem);
    p_Var1 = AfxGetThreadState();
    pAVar2 = AfxSetModuleState((AFX_MODULE_STATE *)&DAT_10030990);
    *(AFX_MODULE_STATE **)(p_Var1 + 8) = pAVar2;
  }
  else if ((param_2 == 0) && (DAT_10030974 == 0)) {
    p_Var1 = AfxGetThreadState();
    AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
  }
  return 1;
}



// Function: _DllMain@12 at 10017245

/* Library Function - Single Match
    _DllMain@12
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 _DllMain_12(HINSTANCE__ *param_1,int param_2)

{
  AFX_MODULE_STATE *pAVar1;
  _AFX_THREAD_STATE *p_Var2;
  undefined4 uVar3;
  
  if (DAT_10030974 != 0) {
    if (param_2 == 1) {
      pAVar1 = AfxGetModuleState();
      *(HINSTANCE__ **)(pAVar1 + 8) = param_1;
      p_Var2 = AfxGetThreadState();
      AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var2 + 8));
    }
    else if (param_2 != 0) goto LAB_1001727e;
    return 1;
  }
LAB_1001727e:
  uVar3 = FUN_10017057(param_1,param_2);
  return uVar3;
}



// Function: FUN_10017284 at 10017284

AFX_MODULE_STATE * __thiscall FUN_10017284(void *this,byte param_1)

{
  AFX_MODULE_STATE::~AFX_MODULE_STATE((AFX_MODULE_STATE *)this);
  if ((param_1 & 1) != 0) {
    CNoTrackObject::operator_delete(this);
  }
  return (AFX_MODULE_STATE *)this;
}



// Function: FUN_100172a4 at 100172a4

void FUN_100172a4(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_100172b6 at 100172b6

undefined4 FUN_100172b6(void)

{
  AFX_MODULE_STATE *pAVar1;
  
  pAVar1 = AfxGetModuleState();
  return *(undefined4 *)(pAVar1 + 4);
}



// Function: __security_check_cookie at 100172c6

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1002edc8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 100172d5

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002edc8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 10017308

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002edc8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1001733e

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002edc8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 10017374

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002edc8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 100173ad

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



// Function: FUN_100173c1 at 100173c1

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100173c1(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_100173d0 at 100173d0

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100173d0(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 100173df

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



// Function: __alloca_probe_16 at 10017450

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// Function: __alloca_probe_8 at 10017466

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



// Function: __onexit at 1001747c

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
  
  local_8 = &DAT_1002a500;
  uStack_c = 0x10017488;
  local_20[0] = DecodePointer(DAT_10030e10);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10030e10);
    local_24 = DecodePointer(DAT_10030e0c);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10030e10 = EncodePointer(local_20[0]);
    DAT_10030e0c = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10017514();
  }
  return p_Var1;
}



// Function: FUN_10017514 at 10017514

void FUN_10017514(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1001751d

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 10017540

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



// Function: __SEH_prolog4 at 10017580

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002edc8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 100175c5

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



// Function: FUN_100175d9 at 100175d9

void __cdecl
FUN_100175d9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1002edc8,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __SEH_prolog4_GS at 10017610

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_2 */
/* Library Function - Single Match
    __SEH_prolog4_GS
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __SEH_prolog4_GS(undefined4 param_1,int param_2)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002edc8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: FUN_10017658 at 10017658

/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_10017658(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x1c) ^ unaff_EBP);
  return;
}



// Function: `eh_vector_constructor_iterator' at 10017667

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
  FUN_100176b4();
  return;
}



// Function: FUN_100176b4 at 100176b4

void FUN_100176b4(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __ArrayUnwind at 100176cc

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



// Function: `eh_vector_destructor_iterator' at 1001772a

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
  FUN_10017775();
  return;
}



// Function: FUN_10017775 at 10017775

void FUN_10017775(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: FUN_100177a0 at 100177a0

ulonglong __fastcall FUN_100177a0(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint local_20;
  float fStack_1c;
  
  if (DAT_10030e04 == 0) {
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



// Function: __CRT_INIT@12 at 10017899

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
    if (DAT_10030a3c < 1) {
      return 0;
    }
    DAT_10030a3c = DAT_10030a3c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10030e00,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10030dfc == 2) {
      param_2 = (int *)DecodePointer(DAT_10030e10);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10030e0c);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10030e10);
            piVar8 = (int *)DecodePointer(DAT_10030e0c);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10030e0c = (PVOID)encoded_null();
        DAT_10030e10 = DAT_10030e0c;
      }
      DAT_10030dfc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10030e00,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10030e00,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10030dfc == 0) {
      DAT_10030dfc = 1;
      iVar5 = initterm_e(&DAT_1001fbf0,&DAT_1001fbfc);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1001f770,&DAT_1001fbec);
      DAT_10030dfc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10030e00,0);
    }
    if ((DAT_10030e08 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10030e08), BVar2 != 0)) {
      (*DAT_10030e08)(param_1,2,param_3);
    }
    DAT_10030a3c = DAT_10030a3c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10017aa3

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HINSTANCE__ *param_3)

{
  int iVar1;
  undefined4 local_20;
  
  _DAT_1002edd0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10030a3c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          ((local_20 = __RawDllMainProxy_12(param_3,(int)param_2), local_20 != 0 &&
           (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)))) {
    local_20 = _DllMain_12(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      _DllMain_12(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
      __RawDllMainProxy_12(param_3,0);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1);
      if (iVar1 == 0) {
        local_20 = 0;
      }
      if (local_20 != 0) {
        local_20 = __RawDllMainProxy_12(param_3,(int)param_2);
      }
    }
  }
  FUN_10017bae();
  return local_20;
}



// Function: FUN_10017bae at 10017bae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10017bae(void)

{
  _DAT_1002edd0 = 0xffffffff;
  return;
}



// Function: entry at 10017bb9

void entry(HINSTANCE__ *param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 10017bdc

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
  
  _DAT_10030b58 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10030b5c = &stack0x00000004;
  _DAT_10030a98 = 0x10001;
  _DAT_10030a40 = 0xc0000409;
  _DAT_10030a44 = 1;
  local_32c = DAT_1002edc8;
  local_328 = DAT_1002edcc;
  _DAT_10030a4c = unaff_retaddr;
  _DAT_10030b24 = in_GS;
  _DAT_10030b28 = in_FS;
  _DAT_10030b2c = in_ES;
  _DAT_10030b30 = in_DS;
  _DAT_10030b34 = unaff_EDI;
  _DAT_10030b38 = unaff_ESI;
  _DAT_10030b3c = unaff_EBX;
  _DAT_10030b40 = in_EDX;
  _DAT_10030b44 = in_ECX;
  _DAT_10030b48 = in_EAX;
  _DAT_10030b4c = unaff_EBP;
  DAT_10030b50 = unaff_retaddr;
  _DAT_10030b54 = in_CS;
  _DAT_10030b60 = in_SS;
  DAT_10030a90 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10022ff4);
  if (DAT_10030a90 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __ValidateImageBase at 10017d70

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



// Function: __FindPESection at 10017db0

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



// Function: __IsNonwritableInCurrentImage at 10017e00

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
  
  pcStack_10 = FUN_100175d9;
  local_14 = ExceptionList;
  local_c = DAT_1002edc8 ^ 0x1002a5a8;
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



// Function: ___security_init_cookie at 10017ed4

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
  if ((DAT_1002edc8 == 0xbb40e64e) || ((DAT_1002edc8 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1002edc8 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1002edc8 == 0xbb40e64e) {
      DAT_1002edc8 = 0xbb40e64f;
    }
    else if ((DAT_1002edc8 & 0xffff0000) == 0) {
      DAT_1002edc8 = DAT_1002edc8 | (DAT_1002edc8 | 0x4711) << 0x10;
    }
    DAT_1002edcc = ~DAT_1002edc8;
  }
  else {
    DAT_1002edcc = ~DAT_1002edc8;
  }
  return;
}



// Function: FUN_10017f82 at 10017f82

int __fastcall FUN_10017f82(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10017fa7 at 10017fa7

void __fastcall FUN_10017fa7(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  RemoveAll((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 10017fbf

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
LAB_1001800d:
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
        goto LAB_1001800d;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_1001801c at 1001801c

undefined4 * __fastcall FUN_1001801c(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10017f82((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1002304c;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_1003039c = 1;
  }
  return param_1;
}



// Function: __FreeStdCallThunk_cmn at 1001805c

/* Library Function - Single Match
    void __cdecl __FreeStdCallThunk_cmn(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void __cdecl __FreeStdCallThunk_cmn(void *param_1)

{
  HANDLE hHeap;
  DWORD dwFlags;
  
  if (DAT_10030da4 == (PSLIST_HEADER)0x1) {
    dwFlags = 0;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,param_1);
    return;
  }
  InterlockedPushEntrySList(DAT_10030da4,(PSINGLE_LIST_ENTRY)param_1);
  return;
}



// Function: __InitializeThunkPool at 10018088

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
    DAT_10030da4 = 1;
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
  DAT_10030da4 = DVar4;
  return 1;
}



// Function: FreeStdCallThunk at 100180f6

/* Library Function - Multiple Matches With Same Base Name
    void __stdcall __FreeStdCallThunk(void *)
    void __stdcall ATL::__FreeStdCallThunk(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void FreeStdCallThunk(void *param_1)

{
  __FreeStdCallThunk_cmn(param_1);
  return;
}



// Function: __AllocStdCallThunk_cmn at 10018108

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
  
  if ((DAT_10030da4 != (PSLIST_HEADER)0x0) || (iVar1 = __InitializeThunkPool(), iVar1 != 0)) {
    if (DAT_10030da4 == (PSLIST_HEADER)0x1) {
      dwBytes = 0xd;
      dwFlags = 0;
      hHeap = GetProcessHeap();
      pvVar2 = HeapAlloc(hHeap,dwFlags,dwBytes);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
    }
    else {
      p_Var3 = InterlockedPopEntrySList(DAT_10030da4);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        return p_Var3;
      }
      p_Var3 = (PSINGLE_LIST_ENTRY)VirtualAlloc((LPVOID)0x0,0x1000,0x1000,0x40);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        p_Var4 = InterlockedPopEntrySList(DAT_10030da4);
        if (p_Var4 != (PSINGLE_LIST_ENTRY)0x0) {
          VirtualFree(p_Var3,0,0x8000);
          return p_Var4;
        }
        p_Var4 = p_Var3 + 0x3fc;
        do {
          InterlockedPushEntrySList(DAT_10030da4,p_Var3);
          p_Var3 = p_Var3 + 4;
        } while (p_Var3 < p_Var4);
        return p_Var3;
      }
    }
  }
  return (void *)0x0;
}



// Function: AtlWinModuleInit at 100181ab

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleInit(struct ATL::_ATL_WIN_MODULE70 *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

long ATL::AtlWinModuleInit(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  if ((param_1 == (_ATL_WIN_MODULE70 *)0x0) || (*(int *)param_1 != 0x2c)) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    lVar1 = CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  }
  return lVar1;
}



// Function: RemoveAll at 100181d3

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



// Function: FUN_100181f2 at 100181f2

int __fastcall FUN_100181f2(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 10018217

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_10018224:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_10018224;
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



// Function: FUN_1001828d at 1001828d

_ATL_WIN_MODULE70 * __fastcall FUN_1001828d(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_100181f2((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_1003039c = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: FUN_100182b5 at 100182b5

void __fastcall FUN_100182b5(int *param_1)

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



// Function: FUN_100182f9 at 100182f9

int __fastcall FUN_100182f9(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10018312 at 10018312

undefined4 * __fastcall FUN_10018312(undefined4 *param_1)

{
  long lVar1;
  
  FUN_100182f9((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &PTR_PTR_1002a618;
  param_1[3] = &DAT_1002a61c;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_1003039c = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10018360 at 10018360

void FUN_10018360(undefined4 param_1)

{
  (*(code *)PTR_FUN_1002edd8)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 10018380

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
    HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_10020c74,&param_2);
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
  (*(code *)PTR_FUN_1002edd8)(param_1);
  return;
}



// Function: FUN_10018430 at 10018430

void FUN_10018430(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__1002305c;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1002a5c4);
}



// Function: _com_error at 10018470

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1002305c;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 100184b0

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1002305c;
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



// Function: __IsNonwritableInCurrentImage at 10018552

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Enum "SectionFlags": Some values do not have unique names */
/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2010 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  uint uVar1;
  int in_ECX;
  IMAGE_SECTION_HEADER *pIVar2;
  uint local_20;
  
  pIVar2 = &IMAGE_SECTION_HEADER_10000208;
  for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
    if (((uint)pIVar2->VirtualAddress <= in_ECX + 0xf0000000U) &&
       (in_ECX + 0xf0000000U < (pIVar2->Misc).PhysicalAddress + pIVar2->VirtualAddress))
    goto LAB_100185d4;
    pIVar2 = pIVar2 + 1;
  }
  pIVar2 = (IMAGE_SECTION_HEADER *)0x0;
LAB_100185d4:
  if (pIVar2 == (IMAGE_SECTION_HEADER *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = ~(pIVar2->Characteristics >> 0x1f) & 1;
  }
  return uVar1;
}



// Function: __RawDllMainProxy@12 at 10018612

/* WARNING: Removing unreachable block (ram,0x10018635) */
/* Library Function - Single Match
    __RawDllMainProxy@12
   
   Library: Visual Studio 2010 Release */

undefined4 __RawDllMainProxy_12(undefined4 param_1,int param_2)

{
  HLOCAL hMem;
  _AFX_THREAD_STATE *p_Var1;
  AFX_MODULE_STATE *pAVar2;
  BOOL BVar3;
  PBYTE unaff_EBP;
  
  BVar3 = __IsNonwritableInCurrentImage(unaff_EBP);
  if (BVar3 == 0) {
    return 0;
  }
  if (param_2 == 1) {
    hMem = LocalAlloc(0,0x2000);
    if (hMem == (HLOCAL)0x0) {
      return 0;
    }
    LocalFree(hMem);
    p_Var1 = AfxGetThreadState();
    pAVar2 = AfxSetModuleState((AFX_MODULE_STATE *)&DAT_10030990);
    *(AFX_MODULE_STATE **)(p_Var1 + 8) = pAVar2;
  }
  else if ((param_2 == 0) && (DAT_10030974 == 0)) {
    p_Var1 = AfxGetThreadState();
    AfxSetModuleState(*(AFX_MODULE_STATE **)(p_Var1 + 8));
  }
  return 1;
}



// Function: Unwind@10018640 at 10018640

void Unwind_10018640(void)

{
  int unaff_EBP;
  
  FUN_10001099(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018663 at 10018663

void Unwind_10018663(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018666. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018687 at 10018687

void Unwind_10018687(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100186aa at 100186aa

void Unwind_100186aa(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100186b2 at 100186b2

void Unwind_100186b2(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100186bd at 100186bd

void Unwind_100186bd(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100186c5 at 100186c5

void Unwind_100186c5(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@100186eb at 100186eb

void Unwind_100186eb(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100186f6 at 100186f6

void Unwind_100186f6(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10018701 at 10018701

void Unwind_10018701(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018709 at 10018709

void Unwind_10018709(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001872c at 1001872c

void Unwind_1001872c(void)

{
  int unaff_EBP;
  
  FUN_10001099(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018734 at 10018734

void Unwind_10018734(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000109e(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018783 at 10018783

void Unwind_10018783(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100187b7 at 100187b7

void Unwind_100187b7(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100187f5 at 100187f5

void Unwind_100187f5(void)

{
  int unaff_EBP;
  
  FUN_10001099(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100187fd at 100187fd

void Unwind_100187fd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10018823 at 10018823

void Unwind_10018823(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001b20(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018857 at 10018857

void Unwind_10018857(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x78) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x78) = *(uint *)(unaff_EBP + -0x78) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + -0x6c));
    return;
  }
  return;
}



// Function: Unwind@10018870 at 10018870

void Unwind_10018870(void)

{
  int unaff_EBP;
  
  FUN_10001099((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10018878 at 10018878

void Unwind_10018878(void)

{
  int unaff_EBP;
  
  FUN_1000109e((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10018880 at 10018880

void Unwind_10018880(void)

{
  int unaff_EBP;
  
  FUN_1000109e((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10018888 at 10018888

void Unwind_10018888(void)

{
  int unaff_EBP;
  
  FUN_10001099((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10018890 at 10018890

void Unwind_10018890(void)

{
  int unaff_EBP;
  
  FUN_10001b20((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10018898 at 10018898

void Unwind_10018898(void)

{
  int unaff_EBP;
  
  FUN_10001b20((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100188a0 at 100188a0

void Unwind_100188a0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100188a8 at 100188a8

void Unwind_100188a8(void)

{
  int unaff_EBP;
  
  FUN_10001099((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100188d5 at 100188d5

void Unwind_100188d5(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100188dd at 100188dd

void Unwind_100188dd(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100188e5 at 100188e5

void Unwind_100188e5(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100188ed at 100188ed

void Unwind_100188ed(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100188f5 at 100188f5

void Unwind_100188f5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x60) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x60) = *(uint *)(unaff_EBP + -0x60) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10018908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
              (*(CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                 **)(unaff_EBP + -0x5c));
    return;
  }
  return;
}



// Function: Unwind@1001890f at 1001890f

void Unwind_1001890f(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10018917 at 10018917

void Unwind_10018917(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001891f at 1001891f

void Unwind_1001891f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018927 at 10018927

void Unwind_10018927(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001892f at 1001892f

void Unwind_1001892f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10018937 at 10018937

void Unwind_10018937(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10018964 at 10018964

void Unwind_10018964(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x298));
  return;
}



// Function: Unwind@1001896f at 1001896f

void Unwind_1001896f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@1001897a at 1001897a

void Unwind_1001897a(void)

{
  DAT_1002ee48 = DAT_1002ee48 & 0xfffffffe;
  return;
}



// Function: Unwind@10018988 at 10018988

void Unwind_10018988(void)

{
  DAT_1002ee48 = DAT_1002ee48 & 0xfffffffd;
  return;
}



// Function: Unwind@10018996 at 10018996

void Unwind_10018996(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@100189a1 at 100189a1

void Unwind_100189a1(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@100189ac at 100189ac

void Unwind_100189ac(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x288));
  return;
}



// Function: Unwind@100189b7 at 100189b7

void Unwind_100189b7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@100189ea at 100189ea

void Unwind_100189ea(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x24) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x100189fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
              (*(CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018a04 at 10018a04

void Unwind_10018a04(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018a0c at 10018a0c

void Unwind_10018a0c(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018a14 at 10018a14

void Unwind_10018a14(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018a1c at 10018a1c

void Unwind_10018a1c(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a24 at 10018a24

void Unwind_10018a24(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a2c at 10018a2c

void Unwind_10018a2c(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018a34 at 10018a34

void Unwind_10018a34(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018a3c at 10018a3c

void Unwind_10018a3c(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018a44 at 10018a44

void Unwind_10018a44(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018a47. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018a4d at 10018a4d

void Unwind_10018a4d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018a56 at 10018a56

void Unwind_10018a56(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a5e at 10018a5e

void Unwind_10018a5e(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018a81 at 10018a81

void Unwind_10018a81(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10018a94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
    ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
              (*(CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
                 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018ab6 at 10018ab6

void Unwind_10018ab6(void)

{
  int unaff_EBP;
  
  FUN_1000318b((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10018adc at 10018adc

void Unwind_10018adc(void)

{
  int unaff_EBP;
  
  FUN_1000334a(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10018ae7 at 10018ae7

void Unwind_10018ae7(void)

{
  int unaff_EBP;
  
  FUN_1000318b((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10018b0d at 10018b0d

void Unwind_10018b0d(void)

{
  int unaff_EBP;
  
  FUN_1000318b((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@10018b18 at 10018b18

void Unwind_10018b18(void)

{
  int unaff_EBP;
  
  FUN_1000334a(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10018b3e at 10018b3e

void Unwind_10018b3e(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018b46 at 10018b46

void Unwind_10018b46(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018b49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018b6a at 10018b6a

void Unwind_10018b6a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018b97 at 10018b97

void Unwind_10018b97(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018b9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018ba0 at 10018ba0

void Unwind_10018ba0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018ba3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018ba9 at 10018ba9

void Unwind_10018ba9(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018bb1 at 10018bb1

void Unwind_10018bb1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018bb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018bba at 10018bba

void Unwind_10018bba(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018bbd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018bc3 at 10018bc3

void Unwind_10018bc3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018bc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018be7 at 10018be7

void Unwind_10018be7(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10018bf2 at 10018bf2

void Unwind_10018bf2(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10018c18 at 10018c18

void Unwind_10018c18(void)

{
  int unaff_EBP;
  
  FUN_100018b8((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10018c20 at 10018c20

void Unwind_10018c20(void)

{
  int unaff_EBP;
  
  CWnd::~CWnd((CWnd *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@10018c2b at 10018c2b

void Unwind_10018c2b(void)

{
  int unaff_EBP;
  
  CListBox::~CListBox((CListBox *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@10018c36 at 10018c36

void Unwind_10018c36(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018c39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018c3f at 10018c3f

void Unwind_10018c3f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018c42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018c48 at 10018c48

void Unwind_10018c48(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018c4b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018c51 at 10018c51

void Unwind_10018c51(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018c59 at 10018c59

void Unwind_10018c59(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018c62 at 10018c62

void Unwind_10018c62(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018c65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018c6b at 10018c6b

void Unwind_10018c6b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018c6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c74 at 10018c74

void Unwind_10018c74(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018c77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018c9b at 10018c9b

void Unwind_10018c9b(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018ca6 at 10018ca6

void Unwind_10018ca6(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018cc9 at 10018cc9

void Unwind_10018cc9(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018cef at 10018cef

void Unwind_10018cef(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d12 at 10018d12

void Unwind_10018d12(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d1a at 10018d1a

void Unwind_10018d1a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10018d25 at 10018d25

void Unwind_10018d25(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d2d at 10018d2d

void Unwind_10018d2d(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d50 at 10018d50

void Unwind_10018d50(void)

{
  int unaff_EBP;
  
  FUN_100018b8((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10018d58 at 10018d58

void Unwind_10018d58(void)

{
  int unaff_EBP;
  
  CWnd::~CWnd((CWnd *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10018d63 at 10018d63

void Unwind_10018d63(void)

{
  int unaff_EBP;
  
  CListBox::~CListBox((CListBox *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10018d6e at 10018d6e

void Unwind_10018d6e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018d71. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018d77 at 10018d77

void Unwind_10018d77(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018d7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d80 at 10018d80

void Unwind_10018d80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018d83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018d89 at 10018d89

void Unwind_10018d89(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018d8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018db0 at 10018db0

void Unwind_10018db0(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018db8 at 10018db8

void Unwind_10018db8(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018dc0 at 10018dc0

void Unwind_10018dc0(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10018de6 at 10018de6

void Unwind_10018de6(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018dee at 10018dee

void Unwind_10018dee(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10018df9 at 10018df9

void Unwind_10018df9(void)

{
  int unaff_EBP;
  
  FUN_100018b8((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@10018e04 at 10018e04

void Unwind_10018e04(void)

{
  int unaff_EBP;
  
  FUN_10003d2a(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@10018e0f at 10018e0f

void Unwind_10018e0f(void)

{
  int unaff_EBP;
  
  FUN_10003d2a(*(int *)(unaff_EBP + -0x10) + 0x78);
  return;
}



// Function: Unwind@10018e1a at 10018e1a

void Unwind_10018e1a(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018e22 at 10018e22

void Unwind_10018e22(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e2a at 10018e2a

void Unwind_10018e2a(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e4d at 10018e4d

void Unwind_10018e4d(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e55 at 10018e55

void Unwind_10018e55(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e5d at 10018e5d

void Unwind_10018e5d(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e65 at 10018e65

void Unwind_10018e65(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018e6d at 10018e6d

void Unwind_10018e6d(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10018e78 at 10018e78

void Unwind_10018e78(void)

{
  int unaff_EBP;
  
  FUN_100018b8((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@10018e83 at 10018e83

void Unwind_10018e83(void)

{
  int unaff_EBP;
  
  FUN_10003d2a(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@10018e8e at 10018e8e

void Unwind_10018e8e(void)

{
  int unaff_EBP;
  
  FUN_10003d2a(*(int *)(unaff_EBP + -0x10) + 0x78);
  return;
}



// Function: Unwind@10018eb4 at 10018eb4

void Unwind_10018eb4(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10018eda at 10018eda

void Unwind_10018eda(void)

{
  int unaff_EBP;
  
  FUN_10003f42((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10018f07 at 10018f07

void Unwind_10018f07(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f0f at 10018f0f

void Unwind_10018f0f(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@10018f1a at 10018f1a

void Unwind_10018f1a(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018f22 at 10018f22

void Unwind_10018f22(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f2a at 10018f2a

void Unwind_10018f2a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10018f32 at 10018f32

void Unwind_10018f32(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f3a at 10018f3a

void Unwind_10018f3a(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f42 at 10018f42

void Unwind_10018f42(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018f4a at 10018f4a

void Unwind_10018f4a(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f6d at 10018f6d

void Unwind_10018f6d(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018f75 at 10018f75

void Unwind_10018f75(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f7d at 10018f7d

void Unwind_10018f7d(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f85 at 10018f85

void Unwind_10018f85(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10018f8d at 10018f8d

void Unwind_10018f8d(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f95 at 10018f95

void Unwind_10018f95(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f9d at 10018f9d

void Unwind_10018f9d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_10003bde(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10018fb6 at 10018fb6

void Unwind_10018fb6(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018fbe at 10018fbe

void Unwind_10018fbe(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018fe1 at 10018fe1

void Unwind_10018fe1(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018fe9 at 10018fe9

void Unwind_10018fe9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003558(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001901d at 1001901d

void Unwind_1001901d(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019025 at 10019025

void Unwind_10019025(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10019048 at 10019048

void Unwind_10019048(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001904b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019051 at 10019051

void Unwind_10019051(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019059 at 10019059

void Unwind_10019059(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019061 at 10019061

void Unwind_10019061(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019069 at 10019069

void Unwind_10019069(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001906c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10019072 at 10019072

void Unwind_10019072(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001907a at 1001907a

void Unwind_1001907a(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10019082 at 10019082

void Unwind_10019082(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001908a at 1001908a

void Unwind_1001908a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019092 at 10019092

void Unwind_10019092(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001909a at 1001909a

void Unwind_1001909a(void)

{
  int unaff_EBP;
  
  FUN_10003b96((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@100190a2 at 100190a2

void Unwind_100190a2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100190aa at 100190aa

void Unwind_100190aa(void)

{
  int unaff_EBP;
  
  FUN_10003bde((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@100190b2 at 100190b2

void Unwind_100190b2(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100190ba at 100190ba

void Unwind_100190ba(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100190c2 at 100190c2

void Unwind_100190c2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100190f2 at 100190f2

void Unwind_100190f2(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10003558(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019126 at 10019126

void Unwind_10019126(void)

{
  int unaff_EBP;
  
  FUN_1000783a(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019149 at 10019149

void Unwind_10019149(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001916e at 1001916e

void Unwind_1001916e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_100120d6(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100191bd at 100191bd

void Unwind_100191bd(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100191c5 at 100191c5

void Unwind_100191c5(void)

{
  int unaff_EBP;
  
  FUN_100055b8((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100191e8 at 100191e8

void Unwind_100191e8(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100191f0 at 100191f0

void Unwind_100191f0(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100191f8 at 100191f8

void Unwind_100191f8(void)

{
  int unaff_EBP;
  
  FUN_1000783a(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019200 at 10019200

void Unwind_10019200(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10019208 at 10019208

void Unwind_10019208(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019235 at 10019235

void Unwind_10019235(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001923d at 1001923d

void Unwind_1001923d(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019245 at 10019245

void Unwind_10019245(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001924d at 1001924d

void Unwind_1001924d(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019255 at 10019255

void Unwind_10019255(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x78);
  return;
}



// Function: Unwind@1001925d at 1001925d

void Unwind_1001925d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019265 at 10019265

void Unwind_10019265(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@1001926d at 1001926d

void Unwind_1001926d(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019275 at 10019275

void Unwind_10019275(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001927d at 1001927d

void Unwind_1001927d(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x78);
  return;
}



// Function: Unwind@100192aa at 100192aa

void Unwind_100192aa(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@100192b5 at 100192b5

void Unwind_100192b5(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x218));
  return;
}



// Function: Unwind@100192c0 at 100192c0

void Unwind_100192c0(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x230);
  return;
}



// Function: Unwind@100192cb at 100192cb

void Unwind_100192cb(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100192d6 at 100192d6

void Unwind_100192d6(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@100192e1 at 100192e1

void Unwind_100192e1(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@100192ec at 100192ec

void Unwind_100192ec(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100192f7 at 100192f7

void Unwind_100192f7(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019302 at 10019302

void Unwind_10019302(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001930d at 1001930d

void Unwind_1001930d(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019318 at 10019318

void Unwind_10019318(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001934b at 1001934b

void Unwind_1001934b(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10019356 at 10019356

void Unwind_10019356(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019361 at 10019361

void Unwind_10019361(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x234);
  return;
}



// Function: Unwind@1001936c at 1001936c

void Unwind_1001936c(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019377 at 10019377

void Unwind_10019377(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10019382 at 10019382

void Unwind_10019382(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001938d at 1001938d

void Unwind_1001938d(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019398 at 10019398

void Unwind_10019398(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100193a3 at 100193a3

void Unwind_100193a3(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100193ae at 100193ae

void Unwind_100193ae(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100193b9 at 100193b9

void Unwind_100193b9(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100193c4 at 100193c4

void Unwind_100193c4(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x218));
  return;
}



// Function: Unwind@100193cf at 100193cf

void Unwind_100193cf(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019402 at 10019402

void Unwind_10019402(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001940a at 1001940a

void Unwind_1001940a(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019412 at 10019412

void Unwind_10019412(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001941a at 1001941a

void Unwind_1001941a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019422 at 10019422

void Unwind_10019422(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001942a at 1001942a

void Unwind_1001942a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019432 at 10019432

void Unwind_10019432(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001943a at 1001943a

void Unwind_1001943a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10019467 at 10019467

void Unwind_10019467(void)

{
  int unaff_EBP;
  
  FUN_10009c05(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001948a at 1001948a

void Unwind_1001948a(void)

{
  DAT_1002f25c = DAT_1002f25c & 0xfffffffe;
  return;
}



// Function: Unwind@100194b3 at 100194b3

void Unwind_100194b3(void)

{
  int unaff_EBP;
  
  FUN_100063fc(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194f1 at 100194f1

void Unwind_100194f1(void)

{
  int unaff_EBP;
  
  FUN_10006546(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10019517 at 10019517

void Unwind_10019517(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001954a at 1001954a

void Unwind_1001954a(void)

{
  int unaff_EBP;
  
  FUN_10006da8((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019570 at 10019570

void Unwind_10019570(void)

{
  FUN_1000311e();
  return;
}



// Function: Unwind@10019587 at 10019587

void Unwind_10019587(void)

{
  FUN_1000311e();
  return;
}



// Function: Unwind@100195ba at 100195ba

void Unwind_100195ba(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195c2 at 100195c2

void Unwind_100195c2(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100195e8 at 100195e8

void Unwind_100195e8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001960d at 1001960d

void Unwind_1001960d(void)

{
  int unaff_EBP;
  
  FUN_10006546(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10019618 at 10019618

void Unwind_10019618(void)

{
  int unaff_EBP;
  
  FUN_10009c05(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001963b at 1001963b

void Unwind_1001963b(void)

{
  int unaff_EBP;
  
  FUN_10006da8((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019646 at 10019646

void Unwind_10019646(void)

{
  int unaff_EBP;
  
  FUN_1000715e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001966c at 1001966c

void Unwind_1001966c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006d7b(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001968f at 1001968f

void Unwind_1001968f(void)

{
  int unaff_EBP;
  
  FUN_1000739d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100196b5 at 100196b5

void Unwind_100196b5(void)

{
  int unaff_EBP;
  
  FUN_100068a6(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@100196e2 at 100196e2

void Unwind_100196e2(void)

{
  int unaff_EBP;
  
  FUN_1000715e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100196ed at 100196ed

void Unwind_100196ed(void)

{
  int unaff_EBP;
  
  FUN_10006da8((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019713 at 10019713

void Unwind_10019713(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001971e at 1001971e

void Unwind_1001971e(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10019729 at 10019729

void Unwind_10019729(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001974f at 1001974f

void Unwind_1001974f(void)

{
  int unaff_EBP;
  
  FUN_100076d6(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019757 at 10019757

void Unwind_10019757(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10019762 at 10019762

void Unwind_10019762(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019785 at 10019785

void Unwind_10019785(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100197aa at 100197aa

void Unwind_100197aa(void)

{
  int unaff_EBP;
  
  FUN_100076d6(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100197b2 at 100197b2

void Unwind_100197b2(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100197ba at 100197ba

void Unwind_100197ba(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@100197e0 at 100197e0

void Unwind_100197e0(void)

{
  int unaff_EBP;
  
  FUN_10007141((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100197e8 at 100197e8

void Unwind_100197e8(void)

{
  int unaff_EBP;
  
  FUN_10007141((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001980b at 1001980b

void Unwind_1001980b(void)

{
  int unaff_EBP;
  
  FUN_10007151((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10019816 at 10019816

void Unwind_10019816(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10019821 at 10019821

void Unwind_10019821(void)

{
  int unaff_EBP;
  
  FUN_10007151((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10019854 at 10019854

void Unwind_10019854(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@1001985f at 1001985f

void Unwind_1001985f(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@1001986a at 1001986a

void Unwind_1001986a(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@10019875 at 10019875

void Unwind_10019875(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@10019880 at 10019880

void Unwind_10019880(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@100198b3 at 100198b3

void Unwind_100198b3(void)

{
  int unaff_EBP;
  
  FUN_100078a2(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100198d6 at 100198d6

void Unwind_100198d6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100198fb at 100198fb

void Unwind_100198fb(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x420));
  return;
}



// Function: Unwind@10019906 at 10019906

void Unwind_10019906(void)

{
  int unaff_EBP;
  
  FUN_10007151((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10019939 at 10019939

void Unwind_10019939(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001995c at 1001995c

void Unwind_1001995c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006d7b(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10019967 at 10019967

void Unwind_10019967(void)

{
  int unaff_EBP;
  
  FUN_1000739d((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@10019972 at 10019972

void Unwind_10019972(void)

{
  int unaff_EBP;
  
  FUN_100073c7((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1001997d at 1001997d

void Unwind_1001997d(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100199b0 at 100199b0

void Unwind_100199b0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100199b8 at 100199b8

void Unwind_100199b8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100199c0 at 100199c0

void Unwind_100199c0(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x29c));
  return;
}



// Function: Unwind@100199f3 at 100199f3

void Unwind_100199f3(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100199fb at 100199fb

void Unwind_100199fb(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x30) + 4));
  return;
}



// Function: Unwind@10019a06 at 10019a06

void Unwind_10019a06(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x30) + 0x20));
  return;
}



// Function: Unwind@10019a11 at 10019a11

void Unwind_10019a11(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x30) + 0x28));
  return;
}



// Function: Unwind@10019a1c at 10019a1c

void Unwind_10019a1c(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019a24 at 10019a24

void Unwind_10019a24(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019a51 at 10019a51

void Unwind_10019a51(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019a59 at 10019a59

void Unwind_10019a59(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@10019a64 at 10019a64

void Unwind_10019a64(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x26c));
  return;
}



// Function: Unwind@10019a6f at 10019a6f

void Unwind_10019a6f(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x268));
  return;
}



// Function: Unwind@10019a7a at 10019a7a

void Unwind_10019a7a(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x270));
  return;
}



// Function: Unwind@10019a85 at 10019a85

void Unwind_10019a85(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x274));
  return;
}



// Function: Unwind@10019ab8 at 10019ab8

void Unwind_10019ab8(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10019ac3 at 10019ac3

void Unwind_10019ac3(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x218));
  return;
}



// Function: Unwind@10019ace at 10019ace

void Unwind_10019ace(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x234);
  return;
}



// Function: Unwind@10019ad9 at 10019ad9

void Unwind_10019ad9(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019ae4 at 10019ae4

void Unwind_10019ae4(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10019aef at 10019aef

void Unwind_10019aef(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10019afa at 10019afa

void Unwind_10019afa(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019b05 at 10019b05

void Unwind_10019b05(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10019b10 at 10019b10

void Unwind_10019b10(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019b1b at 10019b1b

void Unwind_10019b1b(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10019b26 at 10019b26

void Unwind_10019b26(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019b59 at 10019b59

void Unwind_10019b59(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019b61 at 10019b61

void Unwind_10019b61(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@10019b6c at 10019b6c

void Unwind_10019b6c(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x254));
  return;
}



// Function: Unwind@10019b77 at 10019b77

void Unwind_10019b77(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x26c);
  return;
}



// Function: Unwind@10019b82 at 10019b82

void Unwind_10019b82(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10019b8d at 10019b8d

void Unwind_10019b8d(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10019b98 at 10019b98

void Unwind_10019b98(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -600));
  return;
}



// Function: Unwind@10019ba3 at 10019ba3

void Unwind_10019ba3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x230));
  return;
}



// Function: Unwind@10019bae at 10019bae

void Unwind_10019bae(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x25c));
  return;
}



// Function: Unwind@10019bb9 at 10019bb9

void Unwind_10019bb9(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x284));
  return;
}



// Function: Unwind@10019bc4 at 10019bc4

void Unwind_10019bc4(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@10019bcf at 10019bcf

void Unwind_10019bcf(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x25c));
  return;
}



// Function: Unwind@10019bda at 10019bda

void Unwind_10019bda(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10019c0d at 10019c0d

void Unwind_10019c0d(void)

{
  FUN_100013ed((undefined4 *)&DAT_1002f570);
  return;
}



// Function: Unwind@10019c17 at 10019c17

void Unwind_10019c17(void)

{
  FUN_100120d6((int *)&DAT_1002f574);
  return;
}



// Function: Unwind@10019c3c at 10019c3c

void Unwind_10019c3c(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10019c62 at 10019c62

void Unwind_10019c62(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0xc));
  return;
}



// Function: Unwind@10019c6d at 10019c6d

void Unwind_10019c6d(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019c75 at 10019c75

void Unwind_10019c75(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019c7d at 10019c7d

void Unwind_10019c7d(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019c85 at 10019c85

void Unwind_10019c85(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019c8f at 10019c8f

void Unwind_10019c8f(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019cbc at 10019cbc

void Unwind_10019cbc(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019cc4 at 10019cc4

void Unwind_10019cc4(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019ccc at 10019ccc

void Unwind_10019ccc(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019cd6 at 10019cd6

void Unwind_10019cd6(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019cde at 10019cde

void Unwind_10019cde(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019ce8 at 10019ce8

void Unwind_10019ce8(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019cf0 at 10019cf0

void Unwind_10019cf0(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019cf8 at 10019cf8

void Unwind_10019cf8(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019d00 at 10019d00

void Unwind_10019d00(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019d08 at 10019d08

void Unwind_10019d08(void)

{
  int unaff_EBP;
  
  FUN_100018b8((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019d10 at 10019d10

void Unwind_10019d10(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019d18 at 10019d18

void Unwind_10019d18(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019d20 at 10019d20

void Unwind_10019d20(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019d28 at 10019d28

void Unwind_10019d28(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019d30 at 10019d30

void Unwind_10019d30(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019d38 at 10019d38

void Unwind_10019d38(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019d40 at 10019d40

void Unwind_10019d40(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019d6d at 10019d6d

void Unwind_10019d6d(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019d75 at 10019d75

void Unwind_10019d75(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019d7d at 10019d7d

void Unwind_10019d7d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10019d87 at 10019d87

void Unwind_10019d87(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019d8f at 10019d8f

void Unwind_10019d8f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10019d99 at 10019d99

void Unwind_10019d99(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019da1 at 10019da1

void Unwind_10019da1(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019dc4 at 10019dc4

void Unwind_10019dc4(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019dcc at 10019dcc

void Unwind_10019dcc(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019dd4 at 10019dd4

void Unwind_10019dd4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019dde at 10019dde

void Unwind_10019dde(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019de6 at 10019de6

void Unwind_10019de6(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019e09 at 10019e09

void Unwind_10019e09(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e2d at 10019e2d

void Unwind_10019e2d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019e51 at 10019e51

void Unwind_10019e51(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019e77 at 10019e77

void Unwind_10019e77(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019e7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e9b at 10019e9b

void Unwind_10019e9b(void)

{
  int unaff_EBP;
  
  FUN_1000a50d((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10019ebe at 10019ebe

void Unwind_10019ebe(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@10019ec9 at 10019ec9

void Unwind_10019ec9(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019eec at 10019eec

void Unwind_10019eec(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019ef4 at 10019ef4

void Unwind_10019ef4(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019efc at 10019efc

void Unwind_10019efc(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019f04 at 10019f04

void Unwind_10019f04(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019f27 at 10019f27

void Unwind_10019f27(void)

{
  int unaff_EBP;
  
  FUN_1000a8b7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019f2f at 10019f2f

void Unwind_10019f2f(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019f55 at 10019f55

void Unwind_10019f55(void)

{
  int unaff_EBP;
  
  FUN_1000ad4a((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f93 at 10019f93

void Unwind_10019f93(void)

{
  FUN_1000311e();
  return;
}



// Function: Unwind@10019fa1 at 10019fa1

void Unwind_10019fa1(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019fac at 10019fac

void Unwind_10019fac(void)

{
  int unaff_EBP;
  
  FUN_1000a8b7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019fea at 10019fea

void Unwind_10019fea(void)

{
  int unaff_EBP;
  
  FUN_10004668(unaff_EBP + -200);
  return;
}



// Function: Unwind@1001a013 at 1001a013

void Unwind_1001a013(void)

{
  int unaff_EBP;
  
  FUN_1000b166((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a040 at 1001a040

void Unwind_1001a040(void)

{
  int unaff_EBP;
  
  FUN_1000b166((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a06d at 1001a06d

void Unwind_1001a06d(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x2a0));
  return;
}



// Function: Unwind@1001a078 at 1001a078

void Unwind_1001a078(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x2b0));
  return;
}



// Function: Unwind@1001a083 at 1001a083

void Unwind_1001a083(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@1001a08e at 1001a08e

void Unwind_1001a08e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a096 at 1001a096

void Unwind_1001a096(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001a09e at 1001a09e

void Unwind_1001a09e(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x2b8));
  return;
}



// Function: Unwind@1001a0a9 at 1001a0a9

void Unwind_1001a0a9(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x2a8));
  return;
}



// Function: Unwind@1001a0b4 at 1001a0b4

void Unwind_1001a0b4(void)

{
  int unaff_EBP;
  
  FUN_100018b8((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a0e4 at 1001a0e4

void Unwind_1001a0e4(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x47c));
  return;
}



// Function: Unwind@1001a0ef at 1001a0ef

void Unwind_1001a0ef(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@1001a0fa at 1001a0fa

void Unwind_1001a0fa(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x464));
  return;
}



// Function: Unwind@1001a106 at 1001a106

void Unwind_1001a106(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x470));
  return;
}



// Function: Unwind@1001a111 at 1001a111

void Unwind_1001a111(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x458));
  return;
}



// Function: Unwind@1001a144 at 1001a144

void Unwind_1001a144(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a14c at 1001a14c

void Unwind_1001a14c(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1001a172 at 1001a172

void Unwind_1001a172(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a17a at 1001a17a

void Unwind_1001a17a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a182 at 1001a182

void Unwind_1001a182(void)

{
  int unaff_EBP;
  
  FUN_1000a8b7(unaff_EBP + -0x18);
  return;
}



// Function: Unwind@1001a18a at 1001a18a

void Unwind_1001a18a(void)

{
  int unaff_EBP;
  
  FUN_1000ae52(unaff_EBP + -0x18);
  return;
}



// Function: Unwind@1001a192 at 1001a192

void Unwind_1001a192(void)

{
  int unaff_EBP;
  
  FUN_1000a8b7(unaff_EBP + -0x18);
  return;
}



// Function: Unwind@1001a19a at 1001a19a

void Unwind_1001a19a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a1bd at 1001a1bd

void Unwind_1001a1bd(void)

{
  int unaff_EBP;
  
  FUN_1000a8d9(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a1e0 at 1001a1e0

void Unwind_1001a1e0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001a1f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<char,struct_std::char_traits<char>_>::
    ~basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x70));
    return;
  }
  return;
}



// Function: Unwind@1001a1fd at 1001a1fd

void Unwind_1001a1fd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a203. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001a209 at 1001a209

void Unwind_1001a209(void)

{
  int unaff_EBP;
  
  FUN_1000c716((basic_filebuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001a22f at 1001a22f

void Unwind_1001a22f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a235. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1001a23b at 1001a23b

void Unwind_1001a23b(void)

{
  int unaff_EBP;
  
  FUN_1000c716((basic_filebuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1001a261 at 1001a261

void Unwind_1001a261(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a284 at 1001a284

void Unwind_1001a284(void)

{
  int unaff_EBP;
  
  FUN_1000c866(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a2a7 at 1001a2a7

void Unwind_1001a2a7(void)

{
  int unaff_EBP;
  
  FUN_1000a8d9(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a2af at 1001a2af

void Unwind_1001a2af(void)

{
  int unaff_EBP;
  
  FUN_1000c866(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a2d2 at 1001a2d2

void Unwind_1001a2d2(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a2da at 1001a2da

void Unwind_1001a2da(void)

{
  int unaff_EBP;
  
  FUN_10010f25(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a2e2 at 1001a2e2

void Unwind_1001a2e2(void)

{
  int unaff_EBP;
  
  FUN_1000c987((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a308 at 1001a308

void Unwind_1001a308(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a310 at 1001a310

void Unwind_1001a310(void)

{
  int unaff_EBP;
  
  FUN_10010f25(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a318 at 1001a318

void Unwind_1001a318(void)

{
  int unaff_EBP;
  
  FUN_1000c987((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a323 at 1001a323

void Unwind_1001a323(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a346 at 1001a346

void Unwind_1001a346(void)

{
  int unaff_EBP;
  
  FUN_10010f25(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a34e at 1001a34e

void Unwind_1001a34e(void)

{
  int unaff_EBP;
  
  FUN_1000c987((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a359 at 1001a359

void Unwind_1001a359(void)

{
  int unaff_EBP;
  
  FUN_1000c866(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a361 at 1001a361

void Unwind_1001a361(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a384 at 1001a384

void Unwind_1001a384(void)

{
  int unaff_EBP;
  
  FUN_100030e8((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001a38c at 1001a38c

void Unwind_1001a38c(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a394 at 1001a394

void Unwind_1001a394(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a39c at 1001a39c

void Unwind_1001a39c(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001a3bf at 1001a3bf

void Unwind_1001a3bf(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a3c7 at 1001a3c7

void Unwind_1001a3c7(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x298));
  return;
}



// Function: Unwind@1001a3d2 at 1001a3d2

void Unwind_1001a3d2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1001a3dd at 1001a3dd

void Unwind_1001a3dd(void)

{
  int unaff_EBP;
  
  FUN_1000c9a5(unaff_EBP + -0x354);
  return;
}



// Function: Unwind@1001a3e8 at 1001a3e8

void Unwind_1001a3e8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x270));
  return;
}



// Function: Unwind@1001a3f3 at 1001a3f3

void Unwind_1001a3f3(void)

{
  int unaff_EBP;
  
  FUN_1000b166((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x254));
  return;
}



// Function: Unwind@1001a3fe at 1001a3fe

void Unwind_1001a3fe(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x28c));
  return;
}



// Function: Unwind@1001a431 at 1001a431

void Unwind_1001a431(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a439 at 1001a439

void Unwind_1001a439(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a441 at 1001a441

void Unwind_1001a441(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a449 at 1001a449

void Unwind_1001a449(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a451 at 1001a451

void Unwind_1001a451(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a459 at 1001a459

void Unwind_1001a459(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a461 at 1001a461

void Unwind_1001a461(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a469 at 1001a469

void Unwind_1001a469(void)

{
  int unaff_EBP;
  
  FUN_100018b8((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001a471 at 1001a471

void Unwind_1001a471(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a474. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a47a at 1001a47a

void Unwind_1001a47a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a47d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ATL::CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>::
  ~CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>
            ((CStringT<wchar_t,class_StrTraitMFC_DLL<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_> *)
             (unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a483 at 1001a483

void Unwind_1001a483(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a48b at 1001a48b

void Unwind_1001a48b(void)

{
  int unaff_EBP;
  
  FUN_1000ca95((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001a493 at 1001a493

void Unwind_1001a493(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a49b at 1001a49b

void Unwind_1001a49b(void)

{
  int unaff_EBP;
  
  FUN_1000ca95((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001a4a3 at 1001a4a3

void Unwind_1001a4a3(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a4ab at 1001a4ab

void Unwind_1001a4ab(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a4b3 at 1001a4b3

void Unwind_1001a4b3(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a4bb at 1001a4bb

void Unwind_1001a4bb(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a4c3 at 1001a4c3

void Unwind_1001a4c3(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a4cb at 1001a4cb

void Unwind_1001a4cb(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a4d3 at 1001a4d3

void Unwind_1001a4d3(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a4f9 at 1001a4f9

void Unwind_1001a4f9(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a501 at 1001a501

void Unwind_1001a501(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a509 at 1001a509

void Unwind_1001a509(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a511 at 1001a511

void Unwind_1001a511(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a519 at 1001a519

void Unwind_1001a519(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a521 at 1001a521

void Unwind_1001a521(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a529 at 1001a529

void Unwind_1001a529(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a531 at 1001a531

void Unwind_1001a531(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a539 at 1001a539

void Unwind_1001a539(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a541 at 1001a541

void Unwind_1001a541(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a549 at 1001a549

void Unwind_1001a549(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a551 at 1001a551

void Unwind_1001a551(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a559 at 1001a559

void Unwind_1001a559(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a561 at 1001a561

void Unwind_1001a561(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a569 at 1001a569

void Unwind_1001a569(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a571 at 1001a571

void Unwind_1001a571(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a579 at 1001a579

void Unwind_1001a579(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a581 at 1001a581

void Unwind_1001a581(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a589 at 1001a589

void Unwind_1001a589(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a591 at 1001a591

void Unwind_1001a591(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a599 at 1001a599

void Unwind_1001a599(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a5a1 at 1001a5a1

void Unwind_1001a5a1(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a5a9 at 1001a5a9

void Unwind_1001a5a9(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a5b1 at 1001a5b1

void Unwind_1001a5b1(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a5b9 at 1001a5b9

void Unwind_1001a5b9(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a5dc at 1001a5dc

void Unwind_1001a5dc(void)

{
  int unaff_EBP;
  
  FUN_10010159(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a5ff at 1001a5ff

void Unwind_1001a5ff(void)

{
  int unaff_EBP;
  
  FUN_1000ad61(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a622 at 1001a622

void Unwind_1001a622(void)

{
  int unaff_EBP;
  
  CWinApp::~CWinApp(*(CWinApp **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a645 at 1001a645

void Unwind_1001a645(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a69e at 1001a69e

void Unwind_1001a69e(void)

{
  int unaff_EBP;
  
  FUN_1000d2fd(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a6c4 at 1001a6c4

void Unwind_1001a6c4(void)

{
  int unaff_EBP;
  
  FUN_1000d31b(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a6ea at 1001a6ea

void Unwind_1001a6ea(void)

{
  int unaff_EBP;
  
  FUN_1000dcf2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a70d at 1001a70d

void Unwind_1001a70d(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1001a740 at 1001a740

void Unwind_1001a740(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a74a at 1001a74a

void Unwind_1001a74a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a76d at 1001a76d

void Unwind_1001a76d(void)

{
  int unaff_EBP;
  
  FUN_100013ed(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a790 at 1001a790

void Unwind_1001a790(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a798 at 1001a798

void Unwind_1001a798(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a7a0 at 1001a7a0

void Unwind_1001a7a0(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a7a8 at 1001a7a8

void Unwind_1001a7a8(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a7b0 at 1001a7b0

void Unwind_1001a7b0(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a7b8 at 1001a7b8

void Unwind_1001a7b8(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a7db at 1001a7db

void Unwind_1001a7db(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a800 at 1001a800

void Unwind_1001a800(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a825 at 1001a825

void Unwind_1001a825(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a82d at 1001a82d

void Unwind_1001a82d(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a853 at 1001a853

void Unwind_1001a853(void)

{
  int unaff_EBP;
  
  FUN_1000d2fd(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a85e at 1001a85e

void Unwind_1001a85e(void)

{
  int unaff_EBP;
  
  FUN_1000ad61(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a881 at 1001a881

void Unwind_1001a881(void)

{
  int unaff_EBP;
  
  FUN_1000d31b(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001a88c at 1001a88c

void Unwind_1001a88c(void)

{
  int unaff_EBP;
  
  FUN_10010159(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a8af at 1001a8af

void Unwind_1001a8af(void)

{
  int unaff_EBP;
  
  FUN_1000dcf2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a8b7 at 1001a8b7

void Unwind_1001a8b7(void)

{
  int unaff_EBP;
  
  FUN_1000dcf7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a8da at 1001a8da

void Unwind_1001a8da(void)

{
  int unaff_EBP;
  
  FUN_1000dcf7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a8e2 at 1001a8e2

void Unwind_1001a8e2(void)

{
  int unaff_EBP;
  
  FUN_1000dcf2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a905 at 1001a905

void Unwind_1001a905(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a910 at 1001a910

void Unwind_1001a910(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a91b at 1001a91b

void Unwind_1001a91b(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a926 at 1001a926

void Unwind_1001a926(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a931 at 1001a931

void Unwind_1001a931(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a93c at 1001a93c

void Unwind_1001a93c(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1001a947 at 1001a947

void Unwind_1001a947(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1001a952 at 1001a952

void Unwind_1001a952(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@1001a95d at 1001a95d

void Unwind_1001a95d(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a968 at 1001a968

void Unwind_1001a968(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001a99b at 1001a99b

void Unwind_1001a99b(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a9a3 at 1001a9a3

void Unwind_1001a9a3(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a9ab at 1001a9ab

void Unwind_1001a9ab(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a9b3 at 1001a9b3

void Unwind_1001a9b3(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a9bb at 1001a9bb

void Unwind_1001a9bb(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a9de at 1001a9de

void Unwind_1001a9de(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001a9e9 at 1001a9e9

void Unwind_1001a9e9(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001a9f4 at 1001a9f4

void Unwind_1001a9f4(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001a9ff at 1001a9ff

void Unwind_1001a9ff(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001aa0a at 1001aa0a

void Unwind_1001aa0a(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001aa15 at 1001aa15

void Unwind_1001aa15(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001aa48 at 1001aa48

void Unwind_1001aa48(void)

{
  int unaff_EBP;
  
  FUN_1000ad4a((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001aa6b at 1001aa6b

void Unwind_1001aa6b(void)

{
  int unaff_EBP;
  
  FUN_1000e454(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aa8e at 1001aa8e

void Unwind_1001aa8e(void)

{
  int unaff_EBP;
  
  FUN_1000ad4a((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aab1 at 1001aab1

void Unwind_1001aab1(void)

{
  int unaff_EBP;
  
  FUN_1000ad4a((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1001aabc at 1001aabc

void Unwind_1001aabc(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001aac7 at 1001aac7

void Unwind_1001aac7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001aad2 at 1001aad2

void Unwind_1001aad2(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001aadd at 1001aadd

void Unwind_1001aadd(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001aae8 at 1001aae8

void Unwind_1001aae8(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001aaf3 at 1001aaf3

void Unwind_1001aaf3(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001aafe at 1001aafe

void Unwind_1001aafe(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001ab09 at 1001ab09

void Unwind_1001ab09(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001ab14 at 1001ab14

void Unwind_1001ab14(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001ab1f at 1001ab1f

void Unwind_1001ab1f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001ab52 at 1001ab52

void Unwind_1001ab52(void)

{
  int unaff_EBP;
  
  FUN_1000ee69(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ab5a at 1001ab5a

void Unwind_1001ab5a(void)

{
  int unaff_EBP;
  
  FUN_1000e454(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ab7d at 1001ab7d

void Unwind_1001ab7d(void)

{
  int unaff_EBP;
  
  FUN_100076d6(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001abbb at 1001abbb

void Unwind_1001abbb(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001abe8 at 1001abe8

void Unwind_1001abe8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ac0d at 1001ac0d

void Unwind_1001ac0d(void)

{
  int unaff_EBP;
  
  thunk_FUN_10006d7b(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001ac18 at 1001ac18

void Unwind_1001ac18(void)

{
  int unaff_EBP;
  
  FUN_1000739d((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1001ac23 at 1001ac23

void Unwind_1001ac23(void)

{
  int unaff_EBP;
  
  FUN_100073c7((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1001ac2e at 1001ac2e

void Unwind_1001ac2e(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001ac61 at 1001ac61

void Unwind_1001ac61(void)

{
  CWinApp::~CWinApp((CWinApp *)&DAT_100303f8);
  return;
}



// Function: Unwind@1001ac86 at 1001ac86

void Unwind_1001ac86(void)

{
  FUN_1000dcf7(0x100303c8);
  return;
}



// Function: Unwind@1001ac90 at 1001ac90

void Unwind_1001ac90(void)

{
  FUN_1000dcf2(0x100303c8);
  return;
}



// Function: Unwind@1001acb5 at 1001acb5

void Unwind_1001acb5(void)

{
  int unaff_EBP;
  
  FUN_1001120c((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001acdb at 1001acdb

void Unwind_1001acdb(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1001ace3 at 1001ace3

void Unwind_1001ace3(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100013ed(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001ad17 at 1001ad17

void Unwind_1001ad17(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100013ed(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001ad4b at 1001ad4b

void Unwind_1001ad4b(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ad6e at 1001ad6e

void Unwind_1001ad6e(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ad76 at 1001ad76

void Unwind_1001ad76(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ad7e at 1001ad7e

void Unwind_1001ad7e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001adab at 1001adab

void Unwind_1001adab(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001add8 at 1001add8

void Unwind_1001add8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000b166(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001ae16 at 1001ae16

void Unwind_1001ae16(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae1e at 1001ae1e

void Unwind_1001ae1e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000b166(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001ae52 at 1001ae52

void Unwind_1001ae52(void)

{
  int unaff_EBP;
  
  CWnd::~CWnd(*(CWnd **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae75 at 1001ae75

void Unwind_1001ae75(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x3fc));
  return;
}



// Function: Unwind@1001aea8 at 1001aea8

void Unwind_1001aea8(void)

{
  FUN_1000311e();
  return;
}



// Function: Unwind@1001aeda at 1001aeda

void Unwind_1001aeda(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001aee2 at 1001aee2

void Unwind_1001aee2(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001aeea at 1001aeea

void Unwind_1001aeea(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001aef2 at 1001aef2

void Unwind_1001aef2(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001af1f at 1001af1f

void Unwind_1001af1f(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af27 at 1001af27

void Unwind_1001af27(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@1001af32 at 1001af32

void Unwind_1001af32(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001af3d at 1001af3d

void Unwind_1001af3d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1001af48 at 1001af48

void Unwind_1001af48(void)

{
  int unaff_EBP;
  
  CButton::~CButton((CButton *)(*(int *)(unaff_EBP + -0x10) + 0x98));
  return;
}



// Function: Unwind@1001af56 at 1001af56

void Unwind_1001af56(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x124));
  return;
}



// Function: Unwind@1001af64 at 1001af64

void Unwind_1001af64(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x140));
  return;
}



// Function: Unwind@1001af72 at 1001af72

void Unwind_1001af72(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x15c));
  return;
}



// Function: Unwind@1001af80 at 1001af80

void Unwind_1001af80(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af88 at 1001af88

void Unwind_1001af88(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001afab at 1001afab

void Unwind_1001afab(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001afb3 at 1001afb3

void Unwind_1001afb3(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001afbb at 1001afbb

void Unwind_1001afbb(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001afde at 1001afde

void Unwind_1001afde(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001afe6 at 1001afe6

void Unwind_1001afe6(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b013 at 1001b013

void Unwind_1001b013(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b01b at 1001b01b

void Unwind_1001b01b(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b03e at 1001b03e

void Unwind_1001b03e(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b046 at 1001b046

void Unwind_1001b046(void)

{
  int unaff_EBP;
  
  FUN_10010f4a(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@1001b051 at 1001b051

void Unwind_1001b051(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@1001b05c at 1001b05c

void Unwind_1001b05c(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001b067 at 1001b067

void Unwind_1001b067(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@1001b072 at 1001b072

void Unwind_1001b072(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001b07d at 1001b07d

void Unwind_1001b07d(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001b088 at 1001b088

void Unwind_1001b088(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@1001b093 at 1001b093

void Unwind_1001b093(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001b09e at 1001b09e

void Unwind_1001b09e(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@1001b0a9 at 1001b0a9

void Unwind_1001b0a9(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1001b0b4 at 1001b0b4

void Unwind_1001b0b4(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@1001b0c2 at 1001b0c2

void Unwind_1001b0c2(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@1001b0d0 at 1001b0d0

void Unwind_1001b0d0(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe8));
  return;
}



// Function: Unwind@1001b0de at 1001b0de

void Unwind_1001b0de(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b0e6 at 1001b0e6

void Unwind_1001b0e6(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b0ee at 1001b0ee

void Unwind_1001b0ee(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b0f6 at 1001b0f6

void Unwind_1001b0f6(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b0fe at 1001b0fe

void Unwind_1001b0fe(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b106 at 1001b106

void Unwind_1001b106(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b10e at 1001b10e

void Unwind_1001b10e(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b116 at 1001b116

void Unwind_1001b116(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b11e at 1001b11e

void Unwind_1001b11e(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b126 at 1001b126

void Unwind_1001b126(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b12e at 1001b12e

void Unwind_1001b12e(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b136 at 1001b136

void Unwind_1001b136(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b13e at 1001b13e

void Unwind_1001b13e(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b161 at 1001b161

void Unwind_1001b161(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b169 at 1001b169

void Unwind_1001b169(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@1001b174 at 1001b174

void Unwind_1001b174(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001b17f at 1001b17f

void Unwind_1001b17f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1001b18a at 1001b18a

void Unwind_1001b18a(void)

{
  int unaff_EBP;
  
  CButton::~CButton((CButton *)(*(int *)(unaff_EBP + -0x10) + 0x98));
  return;
}



// Function: Unwind@1001b198 at 1001b198

void Unwind_1001b198(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x124));
  return;
}



// Function: Unwind@1001b1a6 at 1001b1a6

void Unwind_1001b1a6(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x140));
  return;
}



// Function: Unwind@1001b1b4 at 1001b1b4

void Unwind_1001b1b4(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x15c));
  return;
}



// Function: Unwind@1001b1dd at 1001b1dd

void Unwind_1001b1dd(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b1e5 at 1001b1e5

void Unwind_1001b1e5(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b1ed at 1001b1ed

void Unwind_1001b1ed(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b1f5 at 1001b1f5

void Unwind_1001b1f5(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b200 at 1001b200

void Unwind_1001b200(void)

{
  int unaff_EBP;
  
  FUN_10010f4a(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@1001b20b at 1001b20b

void Unwind_1001b20b(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b213 at 1001b213

void Unwind_1001b213(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@1001b21e at 1001b21e

void Unwind_1001b21e(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b226 at 1001b226

void Unwind_1001b226(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001b231 at 1001b231

void Unwind_1001b231(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b239 at 1001b239

void Unwind_1001b239(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@1001b244 at 1001b244

void Unwind_1001b244(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b24c at 1001b24c

void Unwind_1001b24c(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001b257 at 1001b257

void Unwind_1001b257(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b25f at 1001b25f

void Unwind_1001b25f(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001b26a at 1001b26a

void Unwind_1001b26a(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b272 at 1001b272

void Unwind_1001b272(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@1001b27d at 1001b27d

void Unwind_1001b27d(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b285 at 1001b285

void Unwind_1001b285(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001b290 at 1001b290

void Unwind_1001b290(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b298 at 1001b298

void Unwind_1001b298(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@1001b2a3 at 1001b2a3

void Unwind_1001b2a3(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b2ab at 1001b2ab

void Unwind_1001b2ab(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1001b2b6 at 1001b2b6

void Unwind_1001b2b6(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b2be at 1001b2be

void Unwind_1001b2be(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@1001b2cc at 1001b2cc

void Unwind_1001b2cc(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b2d4 at 1001b2d4

void Unwind_1001b2d4(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@1001b2e2 at 1001b2e2

void Unwind_1001b2e2(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe8));
  return;
}



// Function: Unwind@1001b30b at 1001b30b

void Unwind_1001b30b(void)

{
  int unaff_EBP;
  
  FUN_100114f8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b32e at 1001b32e

void Unwind_1001b32e(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001b35e at 1001b35e

void Unwind_1001b35e(void)

{
  int unaff_EBP;
  
  FUN_10010f25(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b366 at 1001b366

void Unwind_1001b366(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b389 at 1001b389

void Unwind_1001b389(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b391 at 1001b391

void Unwind_1001b391(void)

{
  int unaff_EBP;
  
  FUN_10010f25(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3b4 at 1001b3b4

void Unwind_1001b3b4(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3bc at 1001b3bc

void Unwind_1001b3bc(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3c4 at 1001b3c4

void Unwind_1001b3c4(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3cc at 1001b3cc

void Unwind_1001b3cc(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3d4 at 1001b3d4

void Unwind_1001b3d4(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3dc at 1001b3dc

void Unwind_1001b3dc(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3ff at 1001b3ff

void Unwind_1001b3ff(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b407 at 1001b407

void Unwind_1001b407(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b40f at 1001b40f

void Unwind_1001b40f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b43c at 1001b43c

void Unwind_1001b43c(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b444 at 1001b444

void Unwind_1001b444(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b467 at 1001b467

void Unwind_1001b467(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b46f at 1001b46f

void Unwind_1001b46f(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001b47a at 1001b47a

void Unwind_1001b47a(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b482 at 1001b482

void Unwind_1001b482(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b48a at 1001b48a

void Unwind_1001b48a(void)

{
  int unaff_EBP;
  
  FUN_10003560(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4ad at 1001b4ad

void Unwind_1001b4ad(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4b5 at 1001b4b5

void Unwind_1001b4b5(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4bd at 1001b4bd

void Unwind_1001b4bd(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4c5 at 1001b4c5

void Unwind_1001b4c5(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4cd at 1001b4cd

void Unwind_1001b4cd(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4f0 at 1001b4f0

void Unwind_1001b4f0(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b4f8 at 1001b4f8

void Unwind_1001b4f8(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b500 at 1001b500

void Unwind_1001b500(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b523 at 1001b523

void Unwind_1001b523(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b546 at 1001b546

void Unwind_1001b546(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b54e at 1001b54e

void Unwind_1001b54e(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b556 at 1001b556

void Unwind_1001b556(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b579 at 1001b579

void Unwind_1001b579(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b581 at 1001b581

void Unwind_1001b581(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b5a4 at 1001b5a4

void Unwind_1001b5a4(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b5ac at 1001b5ac

void Unwind_1001b5ac(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b5b4 at 1001b5b4

void Unwind_1001b5b4(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b5f2 at 1001b5f2

void Unwind_1001b5f2(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001b5fa at 1001b5fa

void Unwind_1001b5fa(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001b602 at 1001b602

void Unwind_1001b602(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001b625 at 1001b625

void Unwind_1001b625(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b62d at 1001b62d

void Unwind_1001b62d(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b635 at 1001b635

void Unwind_1001b635(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b658 at 1001b658

void Unwind_1001b658(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b660 at 1001b660

void Unwind_1001b660(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b668 at 1001b668

void Unwind_1001b668(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b670 at 1001b670

void Unwind_1001b670(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b678 at 1001b678

void Unwind_1001b678(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b680 at 1001b680

void Unwind_1001b680(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b688 at 1001b688

void Unwind_1001b688(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b690 at 1001b690

void Unwind_1001b690(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b698 at 1001b698

void Unwind_1001b698(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6a0 at 1001b6a0

void Unwind_1001b6a0(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6a8 at 1001b6a8

void Unwind_1001b6a8(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6b0 at 1001b6b0

void Unwind_1001b6b0(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6b8 at 1001b6b8

void Unwind_1001b6b8(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6c0 at 1001b6c0

void Unwind_1001b6c0(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6c8 at 1001b6c8

void Unwind_1001b6c8(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6d0 at 1001b6d0

void Unwind_1001b6d0(void)

{
  int unaff_EBP;
  
  FUN_10012a1c((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6d8 at 1001b6d8

void Unwind_1001b6d8(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6e0 at 1001b6e0

void Unwind_1001b6e0(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b6e8 at 1001b6e8

void Unwind_1001b6e8(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6f0 at 1001b6f0

void Unwind_1001b6f0(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b6f8 at 1001b6f8

void Unwind_1001b6f8(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b700 at 1001b700

void Unwind_1001b700(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b708 at 1001b708

void Unwind_1001b708(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b72b at 1001b72b

void Unwind_1001b72b(void)

{
  int unaff_EBP;
  
  FUN_1000ee69(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b769 at 1001b769

void Unwind_1001b769(void)

{
  int unaff_EBP;
  
  FUN_10003cde(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b771 at 1001b771

void Unwind_1001b771(void)

{
  int unaff_EBP;
  
  FUN_10012dfb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b779 at 1001b779

void Unwind_1001b779(void)

{
  int unaff_EBP;
  
  FUN_100120d6(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b781 at 1001b781

void Unwind_1001b781(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001b7a7 at 1001b7a7

void Unwind_1001b7a7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001b7af at 1001b7af

void Unwind_1001b7af(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001b7b7 at 1001b7b7

void Unwind_1001b7b7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001b7bf at 1001b7bf

void Unwind_1001b7bf(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001b7c7 at 1001b7c7

void Unwind_1001b7c7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b7cf at 1001b7cf

void Unwind_1001b7cf(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b7d7 at 1001b7d7

void Unwind_1001b7d7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b7df at 1001b7df

void Unwind_1001b7df(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001b7e7 at 1001b7e7

void Unwind_1001b7e7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001b7ef at 1001b7ef

void Unwind_1001b7ef(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@1001b7f7 at 1001b7f7

void Unwind_1001b7f7(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@1001b7ff at 1001b7ff

void Unwind_1001b7ff(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001b807 at 1001b807

void Unwind_1001b807(void)

{
  int unaff_EBP;
  
  FUN_10003558(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@1001b80f at 1001b80f

void Unwind_1001b80f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@1001b84d at 1001b84d

void Unwind_1001b84d(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b855 at 1001b855

void Unwind_1001b855(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10010f25((int *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b86e at 1001b86e

void Unwind_1001b86e(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b876 at 1001b876

void Unwind_1001b876(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_10010f25((int *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b88f at 1001b88f

void Unwind_1001b88f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b897 at 1001b897

void Unwind_1001b897(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b8ba at 1001b8ba

void Unwind_1001b8ba(void)

{
  int unaff_EBP;
  
  FUN_10012e19(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b8dd at 1001b8dd

void Unwind_1001b8dd(void)

{
  int unaff_EBP;
  
  FUN_1000ad4a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b900 at 1001b900

void Unwind_1001b900(void)

{
  int unaff_EBP;
  
  FUN_1001165d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b926 at 1001b926

void Unwind_1001b926(void)

{
  int unaff_EBP;
  
  FUN_1001165d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b931 at 1001b931

void Unwind_1001b931(void)

{
  int unaff_EBP;
  
  FUN_100114f8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b98a at 1001b98a

void Unwind_1001b98a(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b9ad at 1001b9ad

void Unwind_1001b9ad(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b9d2 at 1001b9d2

void Unwind_1001b9d2(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001b9da at 1001b9da

void Unwind_1001b9da(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001b9e2 at 1001b9e2

void Unwind_1001b9e2(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001b9ea at 1001b9ea

void Unwind_1001b9ea(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001b9f2 at 1001b9f2

void Unwind_1001b9f2(void)

{
  int unaff_EBP;
  
  FUN_10001764((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001ba1f at 1001ba1f

void Unwind_1001ba1f(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ba27 at 1001ba27

void Unwind_1001ba27(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ba54 at 1001ba54

void Unwind_1001ba54(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ba5c at 1001ba5c

void Unwind_1001ba5c(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ba64 at 1001ba64

void Unwind_1001ba64(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ba6c at 1001ba6c

void Unwind_1001ba6c(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ba74 at 1001ba74

void Unwind_1001ba74(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ba7c at 1001ba7c

void Unwind_1001ba7c(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ba84 at 1001ba84

void Unwind_1001ba84(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ba8c at 1001ba8c

void Unwind_1001ba8c(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ba94 at 1001ba94

void Unwind_1001ba94(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ba9c at 1001ba9c

void Unwind_1001ba9c(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001babf at 1001babf

void Unwind_1001babf(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bac7 at 1001bac7

void Unwind_1001bac7(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bacf at 1001bacf

void Unwind_1001bacf(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bad7 at 1001bad7

void Unwind_1001bad7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001badf at 1001badf

void Unwind_1001badf(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bae7 at 1001bae7

void Unwind_1001bae7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001baef at 1001baef

void Unwind_1001baef(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb12 at 1001bb12

void Unwind_1001bb12(void)

{
  int unaff_EBP;
  
  FUN_10010f79((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bb1a at 1001bb1a

void Unwind_1001bb1a(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bb22 at 1001bb22

void Unwind_1001bb22(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bb2a at 1001bb2a

void Unwind_1001bb2a(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001bb32 at 1001bb32

void Unwind_1001bb32(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bb3a at 1001bb3a

void Unwind_1001bb3a(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bb42 at 1001bb42

void Unwind_1001bb42(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bb4a at 1001bb4a

void Unwind_1001bb4a(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bb52 at 1001bb52

void Unwind_1001bb52(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bb5a at 1001bb5a

void Unwind_1001bb5a(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bb62 at 1001bb62

void Unwind_1001bb62(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bb6a at 1001bb6a

void Unwind_1001bb6a(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bb97 at 1001bb97

void Unwind_1001bb97(void)

{
  int unaff_EBP;
  
  FUN_10010f79((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bb9f at 1001bb9f

void Unwind_1001bb9f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bba7 at 1001bba7

void Unwind_1001bba7(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bbaf at 1001bbaf

void Unwind_1001bbaf(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001bbb7 at 1001bbb7

void Unwind_1001bbb7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bbbf at 1001bbbf

void Unwind_1001bbbf(void)

{
  int unaff_EBP;
  
  FUN_10006d61((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bbc7 at 1001bbc7

void Unwind_1001bbc7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bbcf at 1001bbcf

void Unwind_1001bbcf(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bbd7 at 1001bbd7

void Unwind_1001bbd7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bbdf at 1001bbdf

void Unwind_1001bbdf(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bbe7 at 1001bbe7

void Unwind_1001bbe7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bbef at 1001bbef

void Unwind_1001bbef(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bbf7 at 1001bbf7

void Unwind_1001bbf7(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bbff at 1001bbff

void Unwind_1001bbff(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bc2c at 1001bc2c

void Unwind_1001bc2c(void)

{
  int unaff_EBP;
  
  FUN_1000ad4a((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bc4f at 1001bc4f

void Unwind_1001bc4f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bc57 at 1001bc57

void Unwind_1001bc57(void)

{
  int unaff_EBP;
  
  FUN_10010f25((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bc5f at 1001bc5f

void Unwind_1001bc5f(void)

{
  int unaff_EBP;
  
  FUN_100013ed((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001bc67 at 1001bc67

void Unwind_1001bc67(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bc6f at 1001bc6f

void Unwind_1001bc6f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bc77 at 1001bc77

void Unwind_1001bc77(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bc7f at 1001bc7f

void Unwind_1001bc7f(void)

{
  int unaff_EBP;
  
  FUN_100120d6((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001bcac at 1001bcac

void Unwind_1001bcac(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bcaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bcd0 at 1001bcd0

void Unwind_1001bcd0(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bcf3 at 1001bcf3

void Unwind_1001bcf3(void)

{
  int unaff_EBP;
  
  FUN_1000310e(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bcfc at 1001bcfc

void Unwind_1001bcfc(void)

{
  int unaff_EBP;
  
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2((AFX_MAINTAIN_STATE2 *)(unaff_EBP + -0x30));
  return;
}



// Function: FUN_1001ddf0 at 1001ddf0

void FUN_1001ddf0(void)

{
  FID_conflict__Tidy(&DAT_1002ee4c,'\x01',0);
  return;
}



// Function: FUN_1001ddff at 1001ddff

void FUN_1001ddff(void)

{
  FID_conflict__Tidy(&DAT_1002ee68,'\x01',0);
  return;
}



// Function: FUN_1001de0e at 1001de0e

void FUN_1001de0e(void)

{
  FID_conflict__Tidy(&DAT_1002ee84,'\x01',0);
  return;
}



// Function: FUN_1001de3b at 1001de3b

void FUN_1001de3b(void)

{
  FID_conflict__Tidy(&DAT_1002eef4,'\x01',0);
  return;
}



// Function: FUN_1001de4a at 1001de4a

void FUN_1001de4a(void)

{
  FID_conflict__Tidy(&DAT_1002eebc,'\x01',0);
  return;
}



// Function: FUN_1001de59 at 1001de59

void FUN_1001de59(void)

{
  FID_conflict__Tidy(&DAT_1002eea0,'\x01',0);
  return;
}



// Function: FUN_1001de68 at 1001de68

void FUN_1001de68(void)

{
  FID_conflict__Tidy(&DAT_1002eed8,'\x01',0);
  return;
}



// Function: FUN_1001de77 at 1001de77

void FUN_1001de77(void)

{
  Ordinal_6(DAT_1002ef10);
  return;
}



// Function: FUN_1001de84 at 1001de84

void FUN_1001de84(void)

{
  Ordinal_6(DAT_1002ef14);
  return;
}



// Function: FUN_1001de91 at 1001de91

void FUN_1001de91(void)

{
  Ordinal_6(DAT_1002ef18);
  return;
}



// Function: FUN_1001de9e at 1001de9e

void FUN_1001de9e(void)

{
  Ordinal_6(DAT_1002ef54);
  return;
}



// Function: FUN_1001deab at 1001deab

void FUN_1001deab(void)

{
  Ordinal_6(DAT_1002ef58);
  return;
}



// Function: FUN_1001deb8 at 1001deb8

void FUN_1001deb8(void)

{
  Ordinal_6(DAT_1002ef5c);
  return;
}



// Function: FUN_1001dec5 at 1001dec5

void FUN_1001dec5(void)

{
  Ordinal_6(DAT_1002ef60);
  return;
}



// Function: FUN_1001ded2 at 1001ded2

void FUN_1001ded2(void)

{
  Ordinal_6(DAT_1002ef64);
  return;
}



// Function: FUN_1001dedf at 1001dedf

void FUN_1001dedf(void)

{
  FID_conflict__Tidy(&DAT_1002ef1c,'\x01',0);
  return;
}



// Function: FUN_1001deee at 1001deee

void FUN_1001deee(void)

{
  FID_conflict__Tidy(&DAT_1002ef38,'\x01',0);
  return;
}



// Function: FUN_1001defd at 1001defd

void FUN_1001defd(void)

{
  FID_conflict__Tidy(&DAT_1002ef68,'\x01',0);
  return;
}



// Function: FUN_1001df0c at 1001df0c

void FUN_1001df0c(void)

{
  FID_conflict__Tidy(&DAT_1002ef84,'\x01',0);
  return;
}



// Function: FUN_1001df1b at 1001df1b

void FUN_1001df1b(void)

{
  FID_conflict__Tidy(&DAT_1002efa0,'\x01',0);
  return;
}



// Function: FUN_1001df2a at 1001df2a

void FUN_1001df2a(void)

{
  FID_conflict__Tidy(&DAT_1002efbc,'\x01',0);
  return;
}



// Function: FUN_1001df39 at 1001df39

void FUN_1001df39(void)

{
  FID_conflict__Tidy(&DAT_1002efd8,'\x01',0);
  return;
}



// Function: FUN_1001df48 at 1001df48

void FUN_1001df48(void)

{
  FID_conflict__Tidy(&DAT_1002eff4,'\x01',0);
  return;
}



// Function: FUN_1001df57 at 1001df57

void FUN_1001df57(void)

{
  FID_conflict__Tidy(&DAT_1002f010,'\x01',0);
  return;
}



// Function: FUN_1001df66 at 1001df66

void FUN_1001df66(void)

{
  FID_conflict__Tidy(&DAT_1002f02c,'\x01',0);
  return;
}



// Function: FUN_1001df75 at 1001df75

void FUN_1001df75(void)

{
  FID_conflict__Tidy(&DAT_1002f048,'\x01',0);
  return;
}



// Function: FUN_1001df84 at 1001df84

void FUN_1001df84(void)

{
  FID_conflict__Tidy(&DAT_1002f064,'\x01',0);
  return;
}



// Function: FUN_1001df93 at 1001df93

void FUN_1001df93(void)

{
  FID_conflict__Tidy(&DAT_1002f080,'\x01',0);
  return;
}



// Function: FUN_1001dfa2 at 1001dfa2

void FUN_1001dfa2(void)

{
  FID_conflict__Tidy(&DAT_1002f09c,'\x01',0);
  return;
}



// Function: FUN_1001dfb1 at 1001dfb1

void FUN_1001dfb1(void)

{
  FID_conflict__Tidy(&DAT_1002f0b8,'\x01',0);
  return;
}



// Function: FUN_1001dfc0 at 1001dfc0

void FUN_1001dfc0(void)

{
  FID_conflict__Tidy(&DAT_1002f0d4,'\x01',0);
  return;
}



// Function: FUN_1001dfcf at 1001dfcf

void FUN_1001dfcf(void)

{
  FID_conflict__Tidy(&DAT_1002f0f0,'\x01',0);
  return;
}



// Function: FUN_1001dfde at 1001dfde

void FUN_1001dfde(void)

{
  FID_conflict__Tidy(&DAT_1002f10c,'\x01',0);
  return;
}



// Function: FUN_1001dfed at 1001dfed

void FUN_1001dfed(void)

{
  FID_conflict__Tidy(&DAT_1002f128,'\x01',0);
  return;
}



// Function: FUN_1001dffc at 1001dffc

void FUN_1001dffc(void)

{
  FID_conflict__Tidy(&DAT_1002f144,'\x01',0);
  return;
}



// Function: FUN_1001e00b at 1001e00b

void FUN_1001e00b(void)

{
  FID_conflict__Tidy(&DAT_1002f160,'\x01',0);
  return;
}



// Function: FUN_1001e01a at 1001e01a

void FUN_1001e01a(void)

{
  FID_conflict__Tidy(&DAT_1002f17c,'\x01',0);
  return;
}



// Function: FUN_1001e029 at 1001e029

void FUN_1001e029(void)

{
  FID_conflict__Tidy(&DAT_1002f198,'\x01',0);
  return;
}



// Function: FUN_1001e038 at 1001e038

void FUN_1001e038(void)

{
  FID_conflict__Tidy(&DAT_1002f1b4,'\x01',0);
  return;
}



// Function: FUN_1001e047 at 1001e047

void FUN_1001e047(void)

{
  FID_conflict__Tidy(&DAT_1002f1d0,'\x01',0);
  return;
}



// Function: FUN_1001e056 at 1001e056

void FUN_1001e056(void)

{
  FID_conflict__Tidy(&DAT_1002f1ec,'\x01',0);
  return;
}



// Function: FUN_1001e065 at 1001e065

void FUN_1001e065(void)

{
  FID_conflict__Tidy(&DAT_1002f208,'\x01',0);
  return;
}



// Function: FUN_1001e074 at 1001e074

void FUN_1001e074(void)

{
  if (DAT_1002f224 != (int *)0x0) {
    FUN_1000530e(DAT_1002f224);
    DAT_1002f224 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e08b at 1001e08b

void FUN_1001e08b(void)

{
  if (DAT_1002f228 != (int *)0x0) {
    FUN_1000530e(DAT_1002f228);
    DAT_1002f228 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e0a2 at 1001e0a2

void FUN_1001e0a2(void)

{
  Ordinal_6(DAT_1002f298);
  return;
}



// Function: FUN_1001e0af at 1001e0af

void FUN_1001e0af(void)

{
  Ordinal_6(DAT_1002f29c);
  return;
}



// Function: FUN_1001e0bc at 1001e0bc

void FUN_1001e0bc(void)

{
  Ordinal_6(DAT_1002f2a0);
  return;
}



// Function: FUN_1001e0c9 at 1001e0c9

void FUN_1001e0c9(void)

{
  Ordinal_6(DAT_1002f2a4);
  return;
}



// Function: FUN_1001e0d6 at 1001e0d6

void FUN_1001e0d6(void)

{
  Ordinal_6(DAT_1002f2a8);
  return;
}



// Function: FUN_1001e0e3 at 1001e0e3

void FUN_1001e0e3(void)

{
  FUN_100071d3((undefined4 *)&DAT_1002f570);
  return;
}



// Function: FUN_1001e0ed at 1001e0ed

void FUN_1001e0ed(void)

{
  FID_conflict__Tidy(&DAT_1002f260,'\x01',0);
  return;
}



// Function: FUN_1001e0fc at 1001e0fc

void FUN_1001e0fc(void)

{
  FID_conflict__Tidy(&DAT_1002f27c,'\x01',0);
  return;
}



// Function: FUN_1001e10b at 1001e10b

void FUN_1001e10b(void)

{
  FID_conflict__Tidy(&DAT_1002f2ac,'\x01',0);
  return;
}



// Function: FUN_1001e11a at 1001e11a

void FUN_1001e11a(void)

{
  FID_conflict__Tidy(&DAT_1002f2c8,'\x01',0);
  return;
}



// Function: FUN_1001e129 at 1001e129

void FUN_1001e129(void)

{
  FID_conflict__Tidy(&DAT_1002f2e4,'\x01',0);
  return;
}



// Function: FUN_1001e138 at 1001e138

void FUN_1001e138(void)

{
  FID_conflict__Tidy(&DAT_1002f300,'\x01',0);
  return;
}



// Function: FUN_1001e147 at 1001e147

void FUN_1001e147(void)

{
  FID_conflict__Tidy(&DAT_1002f31c,'\x01',0);
  return;
}



// Function: FUN_1001e156 at 1001e156

void FUN_1001e156(void)

{
  FID_conflict__Tidy(&DAT_1002f338,'\x01',0);
  return;
}



// Function: FUN_1001e165 at 1001e165

void FUN_1001e165(void)

{
  FID_conflict__Tidy(&DAT_1002f354,'\x01',0);
  return;
}



// Function: FUN_1001e174 at 1001e174

void FUN_1001e174(void)

{
  FID_conflict__Tidy(&DAT_1002f370,'\x01',0);
  return;
}



// Function: FUN_1001e183 at 1001e183

void FUN_1001e183(void)

{
  FID_conflict__Tidy(&DAT_1002f38c,'\x01',0);
  return;
}



// Function: FUN_1001e192 at 1001e192

void FUN_1001e192(void)

{
  FID_conflict__Tidy(&DAT_1002f3a8,'\x01',0);
  return;
}



// Function: FUN_1001e1a1 at 1001e1a1

void FUN_1001e1a1(void)

{
  FID_conflict__Tidy(&DAT_1002f3c4,'\x01',0);
  return;
}



// Function: FUN_1001e1b0 at 1001e1b0

void FUN_1001e1b0(void)

{
  FID_conflict__Tidy(&DAT_1002f3e0,'\x01',0);
  return;
}



// Function: FUN_1001e1bf at 1001e1bf

void FUN_1001e1bf(void)

{
  FID_conflict__Tidy(&DAT_1002f3fc,'\x01',0);
  return;
}



// Function: FUN_1001e1ce at 1001e1ce

void FUN_1001e1ce(void)

{
  FID_conflict__Tidy(&DAT_1002f418,'\x01',0);
  return;
}



// Function: FUN_1001e1dd at 1001e1dd

void FUN_1001e1dd(void)

{
  FID_conflict__Tidy(&DAT_1002f434,'\x01',0);
  return;
}



// Function: FUN_1001e1ec at 1001e1ec

void FUN_1001e1ec(void)

{
  FID_conflict__Tidy(&DAT_1002f450,'\x01',0);
  return;
}



// Function: FUN_1001e1fb at 1001e1fb

void FUN_1001e1fb(void)

{
  FID_conflict__Tidy(&DAT_1002f46c,'\x01',0);
  return;
}



// Function: FUN_1001e20a at 1001e20a

void FUN_1001e20a(void)

{
  FID_conflict__Tidy(&DAT_1002f488,'\x01',0);
  return;
}



// Function: FUN_1001e219 at 1001e219

void FUN_1001e219(void)

{
  FID_conflict__Tidy(&DAT_1002f4a4,'\x01',0);
  return;
}



// Function: FUN_1001e228 at 1001e228

void FUN_1001e228(void)

{
  FID_conflict__Tidy(&DAT_1002f4c0,'\x01',0);
  return;
}



// Function: FUN_1001e237 at 1001e237

void FUN_1001e237(void)

{
  FID_conflict__Tidy(&DAT_1002f4dc,'\x01',0);
  return;
}



// Function: FUN_1001e246 at 1001e246

void FUN_1001e246(void)

{
  FID_conflict__Tidy(&DAT_1002f4f8,'\x01',0);
  return;
}



// Function: FUN_1001e255 at 1001e255

void FUN_1001e255(void)

{
  FID_conflict__Tidy(&DAT_1002f514,'\x01',0);
  return;
}



// Function: FUN_1001e264 at 1001e264

void FUN_1001e264(void)

{
  FID_conflict__Tidy(&DAT_1002f530,'\x01',0);
  return;
}



// Function: FUN_1001e273 at 1001e273

void FUN_1001e273(void)

{
  FID_conflict__Tidy(&DAT_1002f54c,'\x01',0);
  return;
}



// Function: FUN_1001e282 at 1001e282

void FUN_1001e282(void)

{
  if (DAT_1002f568 != (int *)0x0) {
    FUN_1000530e(DAT_1002f568);
    DAT_1002f568 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e299 at 1001e299

void FUN_1001e299(void)

{
  if (DAT_1002f56c != (int *)0x0) {
    FUN_1000530e(DAT_1002f56c);
    DAT_1002f56c = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e2b0 at 1001e2b0

void FUN_1001e2b0(void)

{
  Ordinal_6(DAT_1002f5b0);
  return;
}



// Function: FUN_1001e2bd at 1001e2bd

void FUN_1001e2bd(void)

{
  Ordinal_6(DAT_1002f5b4);
  return;
}



// Function: FUN_1001e2ca at 1001e2ca

void FUN_1001e2ca(void)

{
  Ordinal_6(DAT_1002f5b8);
  return;
}



// Function: FUN_1001e2d7 at 1001e2d7

void FUN_1001e2d7(void)

{
  Ordinal_6(DAT_1002f5bc);
  return;
}



// Function: FUN_1001e2e4 at 1001e2e4

void FUN_1001e2e4(void)

{
  Ordinal_6(DAT_1002f5c0);
  return;
}



// Function: FUN_1001e2f1 at 1001e2f1

void FUN_1001e2f1(void)

{
  Ordinal_6(DAT_1002f888);
  return;
}



// Function: FUN_1001e2fe at 1001e2fe

void FUN_1001e2fe(void)

{
  Ordinal_6(DAT_1002f88c);
  return;
}



// Function: FUN_1001e30b at 1001e30b

void FUN_1001e30b(void)

{
  Ordinal_6(DAT_1002f890);
  return;
}



// Function: FUN_1001e318 at 1001e318

void FUN_1001e318(void)

{
  FID_conflict__Tidy(&DAT_1002f578,'\x01',0);
  return;
}



// Function: FUN_1001e327 at 1001e327

void FUN_1001e327(void)

{
  FID_conflict__Tidy(&DAT_1002f594,'\x01',0);
  return;
}



// Function: FUN_1001e336 at 1001e336

void FUN_1001e336(void)

{
  FID_conflict__Tidy(&DAT_1002f5c4,'\x01',0);
  return;
}



// Function: FUN_1001e345 at 1001e345

void FUN_1001e345(void)

{
  FID_conflict__Tidy(&DAT_1002f5e0,'\x01',0);
  return;
}



// Function: FUN_1001e354 at 1001e354

void FUN_1001e354(void)

{
  FID_conflict__Tidy(&DAT_1002f5fc,'\x01',0);
  return;
}



// Function: FUN_1001e363 at 1001e363

void FUN_1001e363(void)

{
  FID_conflict__Tidy(&DAT_1002f618,'\x01',0);
  return;
}



// Function: FUN_1001e372 at 1001e372

void FUN_1001e372(void)

{
  FID_conflict__Tidy(&DAT_1002f634,'\x01',0);
  return;
}



// Function: FUN_1001e381 at 1001e381

void FUN_1001e381(void)

{
  FID_conflict__Tidy(&DAT_1002f650,'\x01',0);
  return;
}



// Function: FUN_1001e390 at 1001e390

void FUN_1001e390(void)

{
  FID_conflict__Tidy(&DAT_1002f66c,'\x01',0);
  return;
}



// Function: FUN_1001e39f at 1001e39f

void FUN_1001e39f(void)

{
  FID_conflict__Tidy(&DAT_1002f688,'\x01',0);
  return;
}



// Function: FUN_1001e3ae at 1001e3ae

void FUN_1001e3ae(void)

{
  FID_conflict__Tidy(&DAT_1002f6a4,'\x01',0);
  return;
}



// Function: FUN_1001e3bd at 1001e3bd

void FUN_1001e3bd(void)

{
  FID_conflict__Tidy(&DAT_1002f6c0,'\x01',0);
  return;
}



// Function: FUN_1001e3cc at 1001e3cc

void FUN_1001e3cc(void)

{
  FID_conflict__Tidy(&DAT_1002f6dc,'\x01',0);
  return;
}



// Function: FUN_1001e3db at 1001e3db

void FUN_1001e3db(void)

{
  FID_conflict__Tidy(&DAT_1002f6f8,'\x01',0);
  return;
}



// Function: FUN_1001e3ea at 1001e3ea

void FUN_1001e3ea(void)

{
  FID_conflict__Tidy(&DAT_1002f714,'\x01',0);
  return;
}



// Function: FUN_1001e3f9 at 1001e3f9

void FUN_1001e3f9(void)

{
  FID_conflict__Tidy(&DAT_1002f730,'\x01',0);
  return;
}



// Function: FUN_1001e408 at 1001e408

void FUN_1001e408(void)

{
  FID_conflict__Tidy(&DAT_1002f74c,'\x01',0);
  return;
}



// Function: FUN_1001e417 at 1001e417

void FUN_1001e417(void)

{
  FID_conflict__Tidy(&DAT_1002f768,'\x01',0);
  return;
}



// Function: FUN_1001e426 at 1001e426

void FUN_1001e426(void)

{
  FID_conflict__Tidy(&DAT_1002f784,'\x01',0);
  return;
}



// Function: FUN_1001e435 at 1001e435

void FUN_1001e435(void)

{
  FID_conflict__Tidy(&DAT_1002f7a0,'\x01',0);
  return;
}



// Function: FUN_1001e444 at 1001e444

void FUN_1001e444(void)

{
  FID_conflict__Tidy(&DAT_1002f7bc,'\x01',0);
  return;
}



// Function: FUN_1001e453 at 1001e453

void FUN_1001e453(void)

{
  FID_conflict__Tidy(&DAT_1002f7d8,'\x01',0);
  return;
}



// Function: FUN_1001e462 at 1001e462

void FUN_1001e462(void)

{
  FID_conflict__Tidy(&DAT_1002f7f4,'\x01',0);
  return;
}



// Function: FUN_1001e471 at 1001e471

void FUN_1001e471(void)

{
  FID_conflict__Tidy(&DAT_1002f810,'\x01',0);
  return;
}



// Function: FUN_1001e480 at 1001e480

void FUN_1001e480(void)

{
  FID_conflict__Tidy(&DAT_1002f82c,'\x01',0);
  return;
}



// Function: FUN_1001e48f at 1001e48f

void FUN_1001e48f(void)

{
  FID_conflict__Tidy(&DAT_1002f848,'\x01',0);
  return;
}



// Function: FUN_1001e49e at 1001e49e

void FUN_1001e49e(void)

{
  FID_conflict__Tidy(&DAT_1002f864,'\x01',0);
  return;
}



// Function: FUN_1001e4ad at 1001e4ad

void FUN_1001e4ad(void)

{
  if (DAT_1002f880 != (int *)0x0) {
    FUN_1000530e(DAT_1002f880);
    DAT_1002f880 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e4c4 at 1001e4c4

void FUN_1001e4c4(void)

{
  if (DAT_1002f884 != (int *)0x0) {
    FUN_1000530e(DAT_1002f884);
    DAT_1002f884 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e4db at 1001e4db

void FUN_1001e4db(void)

{
  Ordinal_6(DAT_10030360);
  return;
}



// Function: FUN_1001e4e8 at 1001e4e8

void FUN_1001e4e8(void)

{
  Ordinal_6(DAT_1002f89c);
  return;
}



// Function: FUN_1001e4f5 at 1001e4f5

void FUN_1001e4f5(void)

{
  Ordinal_6(DAT_1002f8a0);
  return;
}



// Function: FUN_1001e502 at 1001e502

void FUN_1001e502(void)

{
  Ordinal_6(DAT_1002f8a4);
  return;
}



// Function: FUN_1001e50f at 1001e50f

void FUN_1001e50f(void)

{
  FID_conflict__Tidy(&DAT_1002f8a8,'\x01',0);
  return;
}



// Function: FUN_1001e51e at 1001e51e

void FUN_1001e51e(void)

{
  FID_conflict__Tidy(&DAT_1002f8c4,'\x01',0);
  return;
}



// Function: FUN_1001e52d at 1001e52d

void FUN_1001e52d(void)

{
  FID_conflict__Tidy(&DAT_1002f8e0,'\x01',0);
  return;
}



// Function: FUN_1001e53c at 1001e53c

void FUN_1001e53c(void)

{
  FID_conflict__Tidy(&DAT_1002f8fc,'\x01',0);
  return;
}



// Function: FUN_1001e54b at 1001e54b

void FUN_1001e54b(void)

{
  FID_conflict__Tidy(&DAT_1002f918,'\x01',0);
  return;
}



// Function: FUN_1001e55a at 1001e55a

void FUN_1001e55a(void)

{
  FID_conflict__Tidy(&DAT_1002f934,'\x01',0);
  return;
}



// Function: FUN_1001e569 at 1001e569

void FUN_1001e569(void)

{
  FID_conflict__Tidy(&DAT_1002f950,'\x01',0);
  return;
}



// Function: FUN_1001e578 at 1001e578

void FUN_1001e578(void)

{
  FID_conflict__Tidy(&DAT_1002f96c,'\x01',0);
  return;
}



// Function: FUN_1001e587 at 1001e587

void FUN_1001e587(void)

{
  FID_conflict__Tidy(&DAT_1002f988,'\x01',0);
  return;
}



// Function: FUN_1001e596 at 1001e596

void FUN_1001e596(void)

{
  FID_conflict__Tidy(&DAT_1002f9a4,'\x01',0);
  return;
}



// Function: FUN_1001e5a5 at 1001e5a5

void FUN_1001e5a5(void)

{
  FID_conflict__Tidy(&DAT_1002f9c0,'\x01',0);
  return;
}



// Function: FUN_1001e5b4 at 1001e5b4

void FUN_1001e5b4(void)

{
  FID_conflict__Tidy(&DAT_1002f9dc,'\x01',0);
  return;
}



// Function: FUN_1001e5c3 at 1001e5c3

void FUN_1001e5c3(void)

{
  FID_conflict__Tidy(&DAT_1002f9f8,'\x01',0);
  return;
}



// Function: FUN_1001e5d2 at 1001e5d2

void FUN_1001e5d2(void)

{
  FID_conflict__Tidy(&DAT_1002fa14,'\x01',0);
  return;
}



// Function: FUN_1001e5e1 at 1001e5e1

void FUN_1001e5e1(void)

{
  FID_conflict__Tidy(&DAT_1002fa30,'\x01',0);
  return;
}



// Function: FUN_1001e5f0 at 1001e5f0

void FUN_1001e5f0(void)

{
  FID_conflict__Tidy(&DAT_1002fa4c,'\x01',0);
  return;
}



// Function: FUN_1001e5ff at 1001e5ff

void FUN_1001e5ff(void)

{
  FID_conflict__Tidy(&DAT_1002fa68,'\x01',0);
  return;
}



// Function: FUN_1001e60e at 1001e60e

void FUN_1001e60e(void)

{
  FID_conflict__Tidy(&DAT_1002fa84,'\x01',0);
  return;
}



// Function: FUN_1001e61d at 1001e61d

void FUN_1001e61d(void)

{
  FID_conflict__Tidy(&DAT_1002faa0,'\x01',0);
  return;
}



// Function: FUN_1001e62c at 1001e62c

void FUN_1001e62c(void)

{
  FID_conflict__Tidy(&DAT_1002fabc,'\x01',0);
  return;
}



// Function: FUN_1001e63b at 1001e63b

void FUN_1001e63b(void)

{
  FID_conflict__Tidy(&DAT_1002fad8,'\x01',0);
  return;
}



// Function: FUN_1001e64a at 1001e64a

void FUN_1001e64a(void)

{
  FID_conflict__Tidy(&DAT_1002faf4,'\x01',0);
  return;
}



// Function: FUN_1001e659 at 1001e659

void FUN_1001e659(void)

{
  FID_conflict__Tidy(&DAT_1002fb10,'\x01',0);
  return;
}



// Function: FUN_1001e668 at 1001e668

void FUN_1001e668(void)

{
  FID_conflict__Tidy(&DAT_1002fb2c,'\x01',0);
  return;
}



// Function: FUN_1001e677 at 1001e677

void FUN_1001e677(void)

{
  FID_conflict__Tidy(&DAT_1002fb48,'\x01',0);
  return;
}



// Function: FUN_1001e686 at 1001e686

void FUN_1001e686(void)

{
  FID_conflict__Tidy(&DAT_1002fb64,'\x01',0);
  return;
}



// Function: FUN_1001e695 at 1001e695

void FUN_1001e695(void)

{
  FID_conflict__Tidy(&DAT_1002fb80,'\x01',0);
  return;
}



// Function: FUN_1001e6a4 at 1001e6a4

void FUN_1001e6a4(void)

{
  FID_conflict__Tidy(&DAT_1002fb9c,'\x01',0);
  return;
}



// Function: FUN_1001e6b3 at 1001e6b3

void FUN_1001e6b3(void)

{
  FID_conflict__Tidy(&DAT_1002fbb8,'\x01',0);
  return;
}



// Function: FUN_1001e6c2 at 1001e6c2

void FUN_1001e6c2(void)

{
  FID_conflict__Tidy(&DAT_1002fbd4,'\x01',0);
  return;
}



// Function: FUN_1001e6d1 at 1001e6d1

void FUN_1001e6d1(void)

{
  FID_conflict__Tidy(&DAT_1002fbf0,'\x01',0);
  return;
}



// Function: FUN_1001e6e0 at 1001e6e0

void FUN_1001e6e0(void)

{
  FID_conflict__Tidy(&DAT_1002fc0c,'\x01',0);
  return;
}



// Function: FUN_1001e6ef at 1001e6ef

void FUN_1001e6ef(void)

{
  FID_conflict__Tidy(&DAT_1002fc28,'\x01',0);
  return;
}



// Function: FUN_1001e6fe at 1001e6fe

void FUN_1001e6fe(void)

{
  FID_conflict__Tidy(&DAT_1002fc44,'\x01',0);
  return;
}



// Function: FUN_1001e70d at 1001e70d

void FUN_1001e70d(void)

{
  FID_conflict__Tidy(&DAT_1002fc60,'\x01',0);
  return;
}



// Function: FUN_1001e71c at 1001e71c

void FUN_1001e71c(void)

{
  FID_conflict__Tidy(&DAT_1002fc7c,'\x01',0);
  return;
}



// Function: FUN_1001e72b at 1001e72b

void FUN_1001e72b(void)

{
  FID_conflict__Tidy(&DAT_1002fc98,'\x01',0);
  return;
}



// Function: FUN_1001e73a at 1001e73a

void FUN_1001e73a(void)

{
  FID_conflict__Tidy(&DAT_1002fcb4,'\x01',0);
  return;
}



// Function: FUN_1001e749 at 1001e749

void FUN_1001e749(void)

{
  FID_conflict__Tidy(&DAT_1002fcd0,'\x01',0);
  return;
}



// Function: FUN_1001e758 at 1001e758

void FUN_1001e758(void)

{
  FID_conflict__Tidy(&DAT_1002fcec,'\x01',0);
  return;
}



// Function: FUN_1001e767 at 1001e767

void FUN_1001e767(void)

{
  FID_conflict__Tidy(&DAT_1002fd08,'\x01',0);
  return;
}



// Function: FUN_1001e776 at 1001e776

void FUN_1001e776(void)

{
  FID_conflict__Tidy(&DAT_1002fd24,'\x01',0);
  return;
}



// Function: FUN_1001e785 at 1001e785

void FUN_1001e785(void)

{
  FID_conflict__Tidy(&DAT_1002fd40,'\x01',0);
  return;
}



// Function: FUN_1001e794 at 1001e794

void FUN_1001e794(void)

{
  FID_conflict__Tidy(&DAT_1002fd5c,'\x01',0);
  return;
}



// Function: FUN_1001e7a3 at 1001e7a3

void FUN_1001e7a3(void)

{
  FID_conflict__Tidy(&DAT_1002fd78,'\x01',0);
  return;
}



// Function: FUN_1001e7b2 at 1001e7b2

void FUN_1001e7b2(void)

{
  FID_conflict__Tidy(&DAT_1002fd94,'\x01',0);
  return;
}



// Function: FUN_1001e7c1 at 1001e7c1

void FUN_1001e7c1(void)

{
  FID_conflict__Tidy(&DAT_1002fdb0,'\x01',0);
  return;
}



// Function: FUN_1001e7d0 at 1001e7d0

void FUN_1001e7d0(void)

{
  FID_conflict__Tidy(&DAT_1002fdcc,'\x01',0);
  return;
}



// Function: FUN_1001e7df at 1001e7df

void FUN_1001e7df(void)

{
  FID_conflict__Tidy(&DAT_1002fde8,'\x01',0);
  return;
}



// Function: FUN_1001e7ee at 1001e7ee

void FUN_1001e7ee(void)

{
  FID_conflict__Tidy(&DAT_1002fe04,'\x01',0);
  return;
}



// Function: FUN_1001e7fd at 1001e7fd

void FUN_1001e7fd(void)

{
  FID_conflict__Tidy(&DAT_1002fe20,'\x01',0);
  return;
}



// Function: FUN_1001e80c at 1001e80c

void FUN_1001e80c(void)

{
  FID_conflict__Tidy(&DAT_1002fe3c,'\x01',0);
  return;
}



// Function: FUN_1001e81b at 1001e81b

void FUN_1001e81b(void)

{
  FID_conflict__Tidy(&DAT_1002fe58,'\x01',0);
  return;
}



// Function: FUN_1001e82a at 1001e82a

void FUN_1001e82a(void)

{
  FID_conflict__Tidy(&DAT_1002fe74,'\x01',0);
  return;
}



// Function: FUN_1001e839 at 1001e839

void FUN_1001e839(void)

{
  FID_conflict__Tidy(&DAT_1002fe90,'\x01',0);
  return;
}



// Function: FUN_1001e848 at 1001e848

void FUN_1001e848(void)

{
  FID_conflict__Tidy(&DAT_1002feac,'\x01',0);
  return;
}



// Function: FUN_1001e857 at 1001e857

void FUN_1001e857(void)

{
  FID_conflict__Tidy(&DAT_1002fec8,'\x01',0);
  return;
}



// Function: FUN_1001e866 at 1001e866

void FUN_1001e866(void)

{
  FID_conflict__Tidy(&DAT_1002fee4,'\x01',0);
  return;
}



// Function: FUN_1001e875 at 1001e875

void FUN_1001e875(void)

{
  FID_conflict__Tidy(&DAT_1002ff00,'\x01',0);
  return;
}



// Function: FUN_1001e884 at 1001e884

void FUN_1001e884(void)

{
  FID_conflict__Tidy(&DAT_1002ff1c,'\x01',0);
  return;
}



// Function: FUN_1001e893 at 1001e893

void FUN_1001e893(void)

{
  FID_conflict__Tidy(&DAT_1002ff38,'\x01',0);
  return;
}



// Function: FUN_1001e8a2 at 1001e8a2

void FUN_1001e8a2(void)

{
  FID_conflict__Tidy(&DAT_1002ff54,'\x01',0);
  return;
}



// Function: FUN_1001e8b1 at 1001e8b1

void FUN_1001e8b1(void)

{
  FID_conflict__Tidy(&DAT_1002ff70,'\x01',0);
  return;
}



// Function: FUN_1001e8c0 at 1001e8c0

void FUN_1001e8c0(void)

{
  FID_conflict__Tidy(&DAT_1002ff8c,'\x01',0);
  return;
}



// Function: FUN_1001e8cf at 1001e8cf

void FUN_1001e8cf(void)

{
  FID_conflict__Tidy(&DAT_1002ffa8,'\x01',0);
  return;
}



// Function: FUN_1001e8de at 1001e8de

void FUN_1001e8de(void)

{
  FID_conflict__Tidy(&DAT_1002ffc4,'\x01',0);
  return;
}



// Function: FUN_1001e8ed at 1001e8ed

void FUN_1001e8ed(void)

{
  FID_conflict__Tidy(&DAT_1002ffe0,'\x01',0);
  return;
}



// Function: FUN_1001e8fc at 1001e8fc

void FUN_1001e8fc(void)

{
  FID_conflict__Tidy(&DAT_1002fffc,'\x01',0);
  return;
}



// Function: FUN_1001e90b at 1001e90b

void FUN_1001e90b(void)

{
  FID_conflict__Tidy(&DAT_10030018,'\x01',0);
  return;
}



// Function: FUN_1001e91a at 1001e91a

void FUN_1001e91a(void)

{
  FID_conflict__Tidy(&DAT_10030034,'\x01',0);
  return;
}



// Function: FUN_1001e929 at 1001e929

void FUN_1001e929(void)

{
  FID_conflict__Tidy(&DAT_10030050,'\x01',0);
  return;
}



// Function: FUN_1001e938 at 1001e938

void FUN_1001e938(void)

{
  FID_conflict__Tidy(&DAT_1003006c,'\x01',0);
  return;
}



// Function: FUN_1001e947 at 1001e947

void FUN_1001e947(void)

{
  FID_conflict__Tidy(&DAT_10030088,'\x01',0);
  return;
}



// Function: FUN_1001e956 at 1001e956

void FUN_1001e956(void)

{
  FID_conflict__Tidy(&DAT_100300a4,'\x01',0);
  return;
}



// Function: FUN_1001e965 at 1001e965

void FUN_1001e965(void)

{
  FID_conflict__Tidy(&DAT_100300c0,'\x01',0);
  return;
}



// Function: FUN_1001e974 at 1001e974

void FUN_1001e974(void)

{
  FID_conflict__Tidy(&DAT_100300dc,'\x01',0);
  return;
}



// Function: FUN_1001e983 at 1001e983

void FUN_1001e983(void)

{
  FID_conflict__Tidy(&DAT_100300f8,'\x01',0);
  return;
}



// Function: FUN_1001e992 at 1001e992

void FUN_1001e992(void)

{
  FID_conflict__Tidy(&DAT_10030114,'\x01',0);
  return;
}



// Function: FUN_1001e9a1 at 1001e9a1

void FUN_1001e9a1(void)

{
  FID_conflict__Tidy(&DAT_10030130,'\x01',0);
  return;
}



// Function: FUN_1001e9b0 at 1001e9b0

void FUN_1001e9b0(void)

{
  FID_conflict__Tidy(&DAT_1003014c,'\x01',0);
  return;
}



// Function: FUN_1001e9bf at 1001e9bf

void FUN_1001e9bf(void)

{
  FID_conflict__Tidy(&DAT_10030168,'\x01',0);
  return;
}



// Function: FUN_1001e9ce at 1001e9ce

void FUN_1001e9ce(void)

{
  FID_conflict__Tidy(&DAT_10030184,'\x01',0);
  return;
}



// Function: FUN_1001e9dd at 1001e9dd

void FUN_1001e9dd(void)

{
  FID_conflict__Tidy(&DAT_100301a0,'\x01',0);
  return;
}



// Function: FUN_1001e9ec at 1001e9ec

void FUN_1001e9ec(void)

{
  FID_conflict__Tidy(&DAT_100301bc,'\x01',0);
  return;
}



// Function: FUN_1001e9fb at 1001e9fb

void FUN_1001e9fb(void)

{
  FID_conflict__Tidy(&DAT_100301d8,'\x01',0);
  return;
}



// Function: FUN_1001ea0a at 1001ea0a

void FUN_1001ea0a(void)

{
  FID_conflict__Tidy(&DAT_100301f4,'\x01',0);
  return;
}



// Function: FUN_1001ea19 at 1001ea19

void FUN_1001ea19(void)

{
  FID_conflict__Tidy(&DAT_10030210,'\x01',0);
  return;
}



// Function: FUN_1001ea28 at 1001ea28

void FUN_1001ea28(void)

{
  FID_conflict__Tidy(&DAT_1003022c,'\x01',0);
  return;
}



// Function: FUN_1001ea37 at 1001ea37

void FUN_1001ea37(void)

{
  FID_conflict__Tidy(&DAT_10030248,'\x01',0);
  return;
}



// Function: FUN_1001ea46 at 1001ea46

void FUN_1001ea46(void)

{
  FID_conflict__Tidy(&DAT_10030264,'\x01',0);
  return;
}



// Function: FUN_1001ea55 at 1001ea55

void FUN_1001ea55(void)

{
  FID_conflict__Tidy(&DAT_10030280,'\x01',0);
  return;
}



// Function: FUN_1001ea64 at 1001ea64

void FUN_1001ea64(void)

{
  FID_conflict__Tidy(&DAT_1003029c,'\x01',0);
  return;
}



// Function: FUN_1001ea73 at 1001ea73

void FUN_1001ea73(void)

{
  FID_conflict__Tidy(&DAT_100302b8,'\x01',0);
  return;
}



// Function: FUN_1001ea82 at 1001ea82

void FUN_1001ea82(void)

{
  FID_conflict__Tidy(&DAT_100302d4,'\x01',0);
  return;
}



// Function: FUN_1001ea91 at 1001ea91

void FUN_1001ea91(void)

{
  FID_conflict__Tidy(&DAT_100302f0,'\x01',0);
  return;
}



// Function: FUN_1001eaa0 at 1001eaa0

void FUN_1001eaa0(void)

{
  FID_conflict__Tidy(&DAT_1003030c,'\x01',0);
  return;
}



// Function: FUN_1001eaaf at 1001eaaf

void FUN_1001eaaf(void)

{
  FID_conflict__Tidy(&DAT_10030328,'\x01',0);
  return;
}



// Function: FUN_1001eabe at 1001eabe

void FUN_1001eabe(void)

{
  FID_conflict__Tidy(&DAT_10030344,'\x01',0);
  return;
}



// Function: FUN_1001eacd at 1001eacd

void FUN_1001eacd(void)

{
  FID_conflict__Tidy(&DAT_10030364,'\x01',0);
  return;
}



// Function: FUN_1001eadc at 1001eadc

void FUN_1001eadc(void)

{
  FID_conflict__Tidy(&DAT_10030380,'\x01',0);
  return;
}



// Function: FUN_1001eaeb at 1001eaeb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001eaeb(void)

{
  CWinApp::~CWinApp((CWinApp *)&DAT_100303f8);
  return;
}



// Function: FUN_1001eb0b at 1001eb0b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eb0b(void)

{
  _DAT_100303c8 = ATL::CComModule::vftable;
  FUN_1000dcb9(0x100303c8);
  return;
}



// Function: FUN_1001eb35 at 1001eb35

void FUN_1001eb35(void)

{
  Ordinal_6(DAT_10030600);
  return;
}



// Function: FUN_1001eb42 at 1001eb42

void FUN_1001eb42(void)

{
  Ordinal_6(DAT_10030604);
  return;
}



// Function: FUN_1001eb4f at 1001eb4f

void FUN_1001eb4f(void)

{
  Ordinal_6(DAT_10030608);
  return;
}



// Function: FUN_1001eb5c at 1001eb5c

void FUN_1001eb5c(void)

{
  FID_conflict__Tidy(&DAT_100304b0,'\x01',0);
  return;
}



// Function: FUN_1001eb6b at 1001eb6b

void FUN_1001eb6b(void)

{
  FID_conflict__Tidy(&DAT_100304cc,'\x01',0);
  return;
}



// Function: FUN_1001eb7a at 1001eb7a

void FUN_1001eb7a(void)

{
  FID_conflict__Tidy(&DAT_100304e8,'\x01',0);
  return;
}



// Function: FUN_1001eb89 at 1001eb89

void FUN_1001eb89(void)

{
  FID_conflict__Tidy(&DAT_1003060c,'\x01',0);
  return;
}



// Function: FUN_1001eb98 at 1001eb98

void FUN_1001eb98(void)

{
  FID_conflict__Tidy(&DAT_10030628,'\x01',0);
  return;
}



// Function: FUN_1001eba7 at 1001eba7

void FUN_1001eba7(void)

{
  FID_conflict__Tidy(&DAT_10030644,'\x01',0);
  return;
}



// Function: FUN_1001ebb6 at 1001ebb6

void FUN_1001ebb6(void)

{
  FID_conflict__Tidy(&DAT_10030520,'\x01',0);
  return;
}



// Function: FUN_1001ebc5 at 1001ebc5

void FUN_1001ebc5(void)

{
  FID_conflict__Tidy(&DAT_1003053c,'\x01',0);
  return;
}



// Function: FUN_1001ebd4 at 1001ebd4

void FUN_1001ebd4(void)

{
  FID_conflict__Tidy(&DAT_10030504,'\x01',0);
  return;
}



// Function: FUN_1001ebe3 at 1001ebe3

void FUN_1001ebe3(void)

{
  FID_conflict__Tidy(&DAT_10030660,'\x01',0);
  return;
}



// Function: FUN_1001ebf2 at 1001ebf2

void FUN_1001ebf2(void)

{
  FID_conflict__Tidy(&DAT_1003067c,'\x01',0);
  return;
}



// Function: FUN_1001ec01 at 1001ec01

void FUN_1001ec01(void)

{
  FID_conflict__Tidy(&DAT_10030558,'\x01',0);
  return;
}



// Function: FUN_1001ec10 at 1001ec10

void FUN_1001ec10(void)

{
  FID_conflict__Tidy(&DAT_10030574,'\x01',0);
  return;
}



// Function: FUN_1001ec1f at 1001ec1f

void FUN_1001ec1f(void)

{
  FID_conflict__Tidy(&DAT_10030590,'\x01',0);
  return;
}



// Function: FUN_1001ec2e at 1001ec2e

void FUN_1001ec2e(void)

{
  FID_conflict__Tidy(&DAT_100305ac,'\x01',0);
  return;
}



// Function: FUN_1001ec3d at 1001ec3d

void FUN_1001ec3d(void)

{
  FID_conflict__Tidy(&DAT_100305c8,'\x01',0);
  return;
}



// Function: FUN_1001ec4c at 1001ec4c

void FUN_1001ec4c(void)

{
  FID_conflict__Tidy(&DAT_100305e4,'\x01',0);
  return;
}



// Function: FUN_1001ec5b at 1001ec5b

void FUN_1001ec5b(void)

{
  Ordinal_6(DAT_100307cc);
  return;
}



// Function: FUN_1001ec68 at 1001ec68

void FUN_1001ec68(void)

{
  Ordinal_6(DAT_10030950);
  return;
}



// Function: FUN_1001ec75 at 1001ec75

void FUN_1001ec75(void)

{
  Ordinal_6(DAT_10030954);
  return;
}



// Function: FUN_1001ec82 at 1001ec82

void FUN_1001ec82(void)

{
  Ordinal_6(DAT_10030914);
  return;
}



// Function: FUN_1001ec8f at 1001ec8f

void FUN_1001ec8f(void)

{
  Ordinal_6(DAT_100308ec);
  return;
}



// Function: FUN_1001ec9c at 1001ec9c

void FUN_1001ec9c(void)

{
  Ordinal_6(DAT_100308f0);
  return;
}



// Function: FUN_1001eca9 at 1001eca9

void FUN_1001eca9(void)

{
  Ordinal_6(DAT_10030908);
  return;
}



// Function: FUN_1001ecb6 at 1001ecb6

void FUN_1001ecb6(void)

{
  Ordinal_6(DAT_10030904);
  return;
}



// Function: FUN_1001ecc3 at 1001ecc3

void FUN_1001ecc3(void)

{
  Ordinal_6(DAT_1003090c);
  return;
}



// Function: FUN_1001ecd0 at 1001ecd0

void FUN_1001ecd0(void)

{
  Ordinal_6(DAT_100308f8);
  return;
}



// Function: FUN_1001ecdd at 1001ecdd

void FUN_1001ecdd(void)

{
  Ordinal_6(DAT_100308f4);
  return;
}



// Function: FUN_1001ecea at 1001ecea

void FUN_1001ecea(void)

{
  Ordinal_6(DAT_10030900);
  return;
}



// Function: FUN_1001ecf7 at 1001ecf7

void FUN_1001ecf7(void)

{
  Ordinal_6(DAT_100308e8);
  return;
}



// Function: FUN_1001ed04 at 1001ed04

void FUN_1001ed04(void)

{
  Ordinal_6(DAT_10030910);
  return;
}



// Function: FUN_1001ed11 at 1001ed11

void FUN_1001ed11(void)

{
  Ordinal_6(DAT_100308fc);
  return;
}



// Function: FUN_1001ed1e at 1001ed1e

void FUN_1001ed1e(void)

{
  FID_conflict__Tidy(&DAT_100306d0,'\x01',0);
  return;
}



// Function: FUN_1001ed2d at 1001ed2d

void FUN_1001ed2d(void)

{
  FID_conflict__Tidy(&DAT_100306b4,'\x01',0);
  return;
}



// Function: FUN_1001ed3c at 1001ed3c

void FUN_1001ed3c(void)

{
  FID_conflict__Tidy(&DAT_10030698,'\x01',0);
  return;
}



// Function: FUN_1001ed4b at 1001ed4b

void FUN_1001ed4b(void)

{
  FID_conflict__Tidy(&DAT_1003085c,'\x01',0);
  return;
}



// Function: FUN_1001ed5a at 1001ed5a

void FUN_1001ed5a(void)

{
  FID_conflict__Tidy(&DAT_100307b0,'\x01',0);
  return;
}



// Function: FUN_1001ed69 at 1001ed69

void FUN_1001ed69(void)

{
  FID_conflict__Tidy(&DAT_100308b0,'\x01',0);
  return;
}



// Function: FUN_1001ed78 at 1001ed78

void FUN_1001ed78(void)

{
  FID_conflict__Tidy(&DAT_100306ec,'\x01',0);
  return;
}



// Function: FUN_1001ed87 at 1001ed87

void FUN_1001ed87(void)

{
  FID_conflict__Tidy(&DAT_10030808,'\x01',0);
  return;
}



// Function: FUN_1001ed96 at 1001ed96

void FUN_1001ed96(void)

{
  FID_conflict__Tidy(&DAT_10030878,'\x01',0);
  return;
}



// Function: FUN_1001eda5 at 1001eda5

void FUN_1001eda5(void)

{
  FID_conflict__Tidy(&DAT_10030840,'\x01',0);
  return;
}



// Function: FUN_1001edb4 at 1001edb4

void FUN_1001edb4(void)

{
  FID_conflict__Tidy(&DAT_10030894,'\x01',0);
  return;
}



// Function: FUN_1001edc3 at 1001edc3

void FUN_1001edc3(void)

{
  FID_conflict__Tidy(&DAT_100307d0,'\x01',0);
  return;
}



// Function: FUN_1001edd2 at 1001edd2

void FUN_1001edd2(void)

{
  FID_conflict__Tidy(&DAT_10030794,'\x01',0);
  return;
}



// Function: FUN_1001ede1 at 1001ede1

void FUN_1001ede1(void)

{
  FID_conflict__Tidy(&DAT_10030708,'\x01',0);
  return;
}



// Function: FUN_1001edf0 at 1001edf0

void FUN_1001edf0(void)

{
  FID_conflict__Tidy(&DAT_100307ec,'\x01',0);
  return;
}



// Function: FUN_1001edff at 1001edff

void FUN_1001edff(void)

{
  FID_conflict__Tidy(&DAT_10030724,'\x01',0);
  return;
}



// Function: FUN_1001ee0e at 1001ee0e

void FUN_1001ee0e(void)

{
  FID_conflict__Tidy(&DAT_1003075c,'\x01',0);
  return;
}



// Function: FUN_1001ee1d at 1001ee1d

void FUN_1001ee1d(void)

{
  FID_conflict__Tidy(&DAT_10030824,'\x01',0);
  return;
}



// Function: FUN_1001ee2c at 1001ee2c

void FUN_1001ee2c(void)

{
  FID_conflict__Tidy(&DAT_100308cc,'\x01',0);
  return;
}



// Function: FUN_1001ee3b at 1001ee3b

void FUN_1001ee3b(void)

{
  FID_conflict__Tidy(&DAT_10030740,'\x01',0);
  return;
}



// Function: FUN_1001ee4a at 1001ee4a

void FUN_1001ee4a(void)

{
  FID_conflict__Tidy(&DAT_10030778,'\x01',0);
  return;
}



// Function: FUN_1001ee59 at 1001ee59

void FUN_1001ee59(void)

{
  FID_conflict__Tidy(&DAT_10030918,'\x01',0);
  return;
}



// Function: FUN_1001ee68 at 1001ee68

void FUN_1001ee68(void)

{
  FID_conflict__Tidy(&DAT_10030934,'\x01',0);
  return;
}



// Function: FUN_1001ee77 at 1001ee77

void FUN_1001ee77(void)

{
  FUN_10016c02();
  return;
}



// Function: FUN_1001ee81 at 1001ee81

void FUN_1001ee81(void)

{
  AFX_MODULE_STATE::~AFX_MODULE_STATE((AFX_MODULE_STATE *)&DAT_10030990);
  return;
}



// Function: FUN_1001ee8b at 1001ee8b

void FUN_1001ee8b(void)

{
  FUN_10017fa7(0x10030d6c);
  return;
}



// Function: FUN_1001ee95 at 1001ee95

void FUN_1001ee95(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_10030da8,DAT_10030d70);
  RemoveAll((undefined4 *)&DAT_10030dc8);
  return;
}



// Function: FUN_1001eeaf at 1001eeaf

void FUN_1001eeaf(void)

{
  FUN_100182b5((int *)&DAT_10030dd4);
  return;
}



// Function: FUN_1001eec0 at 1001eec0

void FUN_1001eec0(void)

{
  Ordinal_9(&DAT_1002ede0);
  return;
}



