/*
 * Decompiled from: ATXSLTConvert.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(undefined4 *param_1)

{
  *param_1 = CSyncObjectBase::vftable;
  return;
}



// Function: FUN_10001007 at 10001007

void __fastcall FUN_10001007(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10001012 at 10001012

void __fastcall FUN_10001012(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10001042 at 10001042

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_10001042(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_1000107a at 1000107a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000107a(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001086;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10011ca0);
}



// Function: FID_conflict:_Tidy at 1000110b

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



// Function: ~basic_string<> at 10001154

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



// Function: FUN_1000115e at 1000115e

undefined4 * __thiscall FUN_1000115e(void *this,uint param_1,uint param_2)

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



// Function: FUN_100011df at 100011df

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_100011df(void *this,uint param_1)

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
  FUN_1000107a((char *)(param_1 + 1));
  FUN_10001274();
  return;
}



// Function: Catch@10001246 at 10001246

undefined * Catch_10001246(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_1000107a((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000126e;
}



// Function: FUN_10001274 at 10001274

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001274(void)

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



// Function: Catch@100012c2 at 100012c2

void Catch_100012c2(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100012d7 at 100012d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100012d7(undefined4 *param_1)

{
  *param_1 = CCriticalSection::vftable;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  FID_conflict__Tidy(param_1 + 7,'\x01',0);
  *param_1 = CSyncObjectBase::vftable;
  return;
}



// Function: FUN_1000131f at 1000131f

bool __thiscall FUN_1000131f(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_100011df(this,param_1);
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



// Function: FUN_10001389 at 10001389

undefined4 * __thiscall FUN_10001389(void *this,byte param_1)

{
  FUN_100012d7((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100013a8 at 100013a8

undefined4 * __thiscall FUN_100013a8(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_1000115e(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_1000115e(this,0,param_2);
  }
  else {
    bVar1 = FUN_1000131f(pvVar3,uVar4,'\0');
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



// Function: FUN_10001444 at 10001444

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10001444(undefined4 *param_1)

{
  *param_1 = CSyncObjectBase::vftable;
  *param_1 = CCriticalSection::vftable;
  param_1[0xb] = 0;
  param_1[0xc] = 7;
  *(undefined2 *)(param_1 + 7) = 0;
  FUN_100013a8(param_1 + 7,(undefined4 *)&stack0x00000004,0,0xffffffff);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  FID_conflict__Tidy(&stack0x00000004,'\x01',0);
  return param_1;
}



// Function: FUN_100014b0 at 100014b0

int __cdecl FUN_100014b0(ushort *param_1,ushort *param_2,int param_3)

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



// Function: FUN_100014e4 at 100014e4

void FUN_100014e4(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10011e1c);
}



// Function: AtlCrtErrorCheck at 100014fc

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
    if (param_1 == 0x16) goto LAB_10001524;
    if (param_1 == 0x22) goto LAB_10001524;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_100014e4(uVar1);
LAB_10001524:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_10001534 at 10001534

void __cdecl FUN_10001534(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: _AtlGetStringResourceImage at 10001554

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



// Function: AtlGetStringResourceImage at 100015af

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



// Function: FUN_100015df at 100015df

int * FUN_100015df(int *param_1,int *param_2)

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



// Function: AtlComQIPtrAssign at 10001612

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



// Function: FUN_10001649 at 10001649

int * __thiscall FUN_10001649(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_1000166f at 1000166f

int __thiscall FUN_1000166f(void *this,undefined4 param_1)

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



// Function: FUN_100016b1 at 100016b1

bool __cdecl FUN_100016b1(HINSTANCE__ *param_1,uint param_2,int *param_3)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  int iVar2;
  
  pAVar1 = ATL::AtlGetStringResourceImage(param_1,param_2);
  if (pAVar1 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    *param_3 = 0;
  }
  else {
    iVar2 = Ordinal_4(pAVar1 + 2,*(undefined2 *)pAVar1);
    *param_3 = iVar2;
  }
  return *param_3 != 0;
}



// Function: FUN_100016e8 at 100016e8

void __fastcall FUN_100016e8(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 100016f1

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
                    /* WARNING: Could not recover jumptable at 0x1000173a. Too many branches */
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



// Function: Close at 10001748

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



// Function: Open at 10001763

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



// Function: FUN_100017b2 at 100017b2

LSTATUS __thiscall FUN_100017b2(void *this,LPBYTE param_1,LPCWSTR param_2,LPDWORD param_3)

{
  short sVar1;
  LPDWORD lpcbData;
  LSTATUS LVar2;
  undefined4 *extraout_ECX;
  uint uVar3;
  
  lpcbData = param_3;
  if (param_3 == (LPDWORD)0x0) {
    FUN_100014e4(0x80004005);
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
      if ((uVar3 & 1) != 0) goto LAB_1000182b;
      sVar1 = *(short *)(param_1 + ((uVar3 & 0xfffffffe) - 2));
    }
    else {
      if ((((param_3 != (LPDWORD)0x7) || ((uVar3 & 1) != 0)) || (uVar3 = uVar3 >> 1, uVar3 == 0)) ||
         (*(short *)(param_1 + uVar3 * 2 + -2) != 0)) goto LAB_1000182b;
      if (uVar3 < 2) {
        return LVar2;
      }
      sVar1 = *(short *)(param_1 + uVar3 * 2 + -4);
    }
    if (sVar1 == 0) {
      return LVar2;
    }
  }
LAB_1000182b:
  param_1[0] = '\0';
  param_1[1] = '\0';
  return 0xd;
}



// Function: QueryStringValue at 10001841

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
              (*(short *)((int)param_2 + ((local_8 & 0xfffffffe) - 2)) != 0)) goto LAB_1000187d;
    }
    *puVar2 = local_8 >> 1;
    lVar4 = 0;
  }
  else {
LAB_1000187d:
    lVar4 = 0xd;
  }
  return lVar4;
}



// Function: FUN_100018b0 at 100018b0

void FUN_100018b0(LONG *param_1)

{
  LONG LVar1;
  
  if (param_1 != (LONG *)PTR_DAT_10016088) {
    LVar1 = InterlockedDecrement(param_1);
    if (LVar1 < 1) {
      operator_delete__(param_1);
    }
  }
  return;
}



// Function: FUN_100018d6 at 100018d6

void FUN_100018d6(UINT param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_10016b30,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = L'\0';
  }
  return;
}



// Function: FUN_1000191f at 1000191f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000191f(void)

{
  int iVar1;
  undefined **ppuVar2;
  int local_18;
  
  ppuVar2 = &PTR_u_Reserved_10016090;
  local_18 = 0;
  while( true ) {
    iVar1 = wcscmp((wchar_t *)*ppuVar2,L"");
    if (iVar1 == 0) break;
    local_18 = local_18 + 1;
    ppuVar2 = ppuVar2 + 1;
  }
  return local_18;
}



// Function: Catch@10001963 at 10001963

undefined4 Catch_10001963(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000195a;
}



// Function: FUN_10001971 at 10001971

void __cdecl FUN_10001971(int param_1,int param_2,int *param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  ushort *puVar10;
  bool bVar11;
  int local_10;
  int local_c;
  
  uVar5 = Ordinal_7(param_1);
  uVar6 = uVar5 & 0x80000003;
  bVar11 = uVar6 == 0;
  if ((int)uVar6 < 0) {
    bVar11 = (uVar6 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if (bVar11) {
    local_c = 0;
    if (3 < (int)uVar5) {
      local_10 = 3;
      puVar10 = (ushort *)(param_1 + 4);
      do {
        pcVar7 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
                        (uint)puVar10[-2]);
        pcVar8 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
                        (uint)puVar10[-1]);
        bVar2 = (char)pcVar8 - 0x38;
        pcVar8 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
                        (uint)*puVar10);
        bVar3 = (char)pcVar8 - 0x38;
        pcVar9 = strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
                        (uint)puVar10[1]);
        bVar4 = (char)pcVar9 - 0x38;
        *(byte *)(local_c + param_2) = bVar2 >> 4 | ((char)pcVar7 + -0x38) * '\x04';
        if (bVar3 == 0x40) {
          local_c = local_c + 1;
          break;
        }
        *(byte *)(local_c + 1 + param_2) = bVar3 >> 2 | bVar2 * '\x10';
        if (bVar4 == 0x40) {
          local_c = local_c + 2;
          break;
        }
        local_10 = local_10 + 4;
        iVar1 = local_c + 3;
        puVar10 = puVar10 + 4;
        *(byte *)(local_c + 2 + param_2) = (char)pcVar8 << 6 | bVar4;
        local_c = iVar1;
      } while (local_10 < (int)uVar5);
    }
    *param_3 = local_c;
  }
  else {
    *param_3 = -1;
  }
  return;
}



// Function: FUN_10001a76 at 10001a76

void __fastcall FUN_10001a76(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10001a90 at 10001a90

void __thiscall FUN_10001a90(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_1000f800,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001add at 10001add

void __fastcall FUN_10001add(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x21) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x21) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x21) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x21) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_10001b18 at 10001b18

void __fastcall FUN_10001b18(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x2d) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x2d) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x2d) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x2d) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_10001b53 at 10001b53

void __cdecl FUN_10001b53(wchar_t *param_1,wchar_t *param_2)

{
  wcscat_s(param_1,0x104,param_2);
  return;
}



// Function: FUN_10001b6c at 10001b6c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001b6c(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001b78;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x71c71c8) &&
     (pvVar1 = operator_new((int)param_1 * 0x24), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10011ca0);
}



// Function: FUN_10001bcb at 10001bcb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001bcb(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001bd7;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x924924a) &&
     (pvVar1 = operator_new((int)param_1 * 0x1c), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10011ca0);
}



// Function: FID_conflict:_Inside at 10001c2a

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



// Function: AtlAdd<> at 10001c66

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



// Function: FUN_10001c8a at 10001c8a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_10001c8a(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001c96;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10011ca0);
  }
  return;
}



// Function: FUN_10001ce4 at 10001ce4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

LPWSTR __cdecl FUN_10001ce4(LPCSTR param_1,int param_2)

{
  int cchWideChar;
  LPWSTR lpWideCharStr;
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
LAB_10001d55:
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
        FUN_10001a76(local_14);
        goto LAB_10001d55;
      }
    }
    local_8 = 0xffffffff;
    FUN_10001a76(local_14);
  }
  return lpWideCharStr;
}



// Function: FUN_10001d6e at 10001d6e

int * __thiscall FUN_10001d6e(void *this,int param_1)

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
      FUN_100014e4(0x8007000e);
    }
    *(undefined4 *)this = 0;
  }
  return (int *)this;
}



// Function: Copy at 10001dab

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



// Function: FUN_10001dc8 at 10001dc8

undefined4 __thiscall FUN_10001dc8(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    pwVar2 = ATL::CComBSTR::Copy((CComBSTR *)this);
    *param_1 = pwVar2;
                    /* WARNING: Load size is inaccurate */
    if ((pwVar2 == (wchar_t *)0x0) && (*this != 0)) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10001dfb at 10001dfb

long __thiscall FUN_10001dfb(void *this,void *param_1,uint param_2)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
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
    iVar2 = AtlAdd<>((int *)&local_8,uVar1,param_2);
    if (iVar2 < 0) {
      return iVar2;
    }
    lVar3 = ATL::AtlMultiply<unsigned_long>(&local_10,local_8,2);
    if (lVar3 < 0) {
      return lVar3;
    }
    lVar3 = ATL::AtlMultiply<unsigned_long>(&local_c,uVar1,2);
    if (lVar3 < 0) {
      return lVar3;
    }
    pvVar4 = (void *)Ordinal_4(0,local_8);
    if (pvVar4 == (void *)0x0) {
      return -0x7ff8fff2;
    }
                    /* WARNING: Load size is inaccurate */
    iVar2 = Ordinal_7(*this);
    if (iVar2 != 0) {
                    /* WARNING: Load size is inaccurate */
      FUN_10001534(pvVar4,local_10,*this,local_c);
    }
    FUN_10001534((void *)((int)pvVar4 + uVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar4 + local_8 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar4;
  }
  return 0;
}



// Function: FUN_10001ee7 at 10001ee7

void __thiscall FUN_10001ee7(void *this,HINSTANCE__ *param_1,uint param_2)

{
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  FUN_100016b1(param_1,param_2,(int *)this);
  return;
}



// Function: CComBSTR at 10001f0c

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(char const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,char *param_1)

{
  LPWSTR pWVar1;
  
  if (param_1 != (char *)0x0) {
    pWVar1 = FUN_10001ce4(param_1,-1);
    *(LPWSTR *)this = pWVar1;
    if (pWVar1 != (LPWSTR)0x0) {
      return this;
    }
    FUN_100014e4(0x8007000e);
  }
  *(undefined4 *)this = 0;
  return this;
}



// Function: FUN_10001f3e at 10001f3e

undefined4 * __thiscall FUN_10001f3e(void *this,LPCSTR param_1)

{
  LPWSTR pWVar1;
  
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  pWVar1 = FUN_10001ce4(param_1,-1);
  *(LPWSTR *)this = pWVar1;
  if ((pWVar1 == (LPWSTR)0x0) && (param_1 != (LPCSTR)0x0)) {
    FUN_100014e4(0x8007000e);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001f74 at 10001f74

void __fastcall FUN_10001f74(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10001f7c at 10001f7c

undefined2 * __thiscall FUN_10001f7c(void *this,CComBSTR *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_10001f94;
  while( true ) {
    FUN_100014e4(iVar1);
LAB_10001f94:
    *(undefined2 *)this = 8;
    pwVar2 = ATL::CComBSTR::Copy(param_1);
    *(wchar_t **)((int)this + 8) = pwVar2;
    if ((pwVar2 != (wchar_t *)0x0) || (*(int *)param_1 == 0)) break;
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
  return (undefined2 *)this;
}



// Function: FUN_10001fc7 at 10001fc7

undefined2 * __thiscall FUN_10001fc7(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_10001fde;
  while( true ) {
    FUN_100014e4(iVar1);
LAB_10001fde:
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



// Function: FUN_10002010 at 10002010

LSTATUS __fastcall FUN_10002010(undefined4 *param_1)

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



// Function: FUN_10002015 at 10002015

void __fastcall FUN_10002015(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_10016088) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
  }
  return;
}



// Function: FUN_10002041 at 10002041

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10002041(void *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    *(undefined **)this = PTR_DAT_1001608c;
    return 1;
  }
  FUN_1000b8f8(param_1 * 2 + 0xe);
  uVar1 = FUN_1000208f();
  return uVar1;
}



// Function: Catch@1000207c at 1000207c

undefined * Catch_1000207c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002086;
}



// Function: FUN_1000208f at 1000208f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000208f(void)

{
  undefined4 *in_EAX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = 1;
    *(undefined2 *)((int)in_EAX + unaff_ESI * 2 + 0xc) = 0;
    in_EAX[1] = unaff_ESI;
    in_EAX[2] = unaff_ESI;
    *unaff_EDI = in_EAX + 3;
  }
  return;
}



// Function: FUN_100020b6 at 100020b6

int __thiscall FUN_100020b6(void *this,int param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  uint _Size;
  undefined4 local_8;
  
  iVar1 = param_1 + param_3;
  local_8 = 1;
  if ((iVar1 < param_1) || (iVar1 < param_3)) {
    local_8 = 0;
  }
  else if (iVar1 != 0) {
    local_8 = FUN_10002041(this,iVar1);
    if (local_8 != 0) {
      _Size = param_1 * 2;
      if (_Size <= iVar1 * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
        memcpy(*this,param_2,_Size);
      }
      if ((uint)(param_3 * 2) <= (iVar1 - param_1) * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
        memcpy((void *)(*this + _Size),param_4,param_3 * 2);
      }
    }
  }
  return local_8;
}



// Function: FUN_1000213b at 1000213b

void __thiscall FUN_1000213b(void *this,int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  
  if (param_1 != 0) {
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    if (*(LONG *)((int)pvVar1 + -0xc) < 2) {
      if (*(int *)((int)pvVar1 + -8) + param_1 <= *(int *)((int)pvVar1 + -4)) {
        if ((uint)(param_1 * 2) <= *(int *)((int)pvVar1 + -4) * 2 + 2U) {
          memcpy((void *)((int)pvVar1 + *(int *)((int)pvVar1 + -8) * 2),param_2,param_1 * 2);
        }
                    /* WARNING: Load size is inaccurate */
        *(int *)(*this + -8) = *(int *)(*this + -8) + param_1;
                    /* WARNING: Load size is inaccurate */
        *(undefined2 *)(*this + *(int *)(*this + -8) * 2) = 0;
        return;
      }
    }
    iVar2 = FUN_100020b6(this,*(int *)((int)pvVar1 + -8),pvVar1,param_1,param_2);
    if (iVar2 != 0) {
      FUN_100018b0((LONG *)((int)pvVar1 + -0xc));
    }
  }
  return;
}



// Function: FUN_100021b4 at 100021b4

void __fastcall FUN_100021b4(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_10016088) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
    *param_1 = (int)PTR_DAT_1001608c;
  }
  return;
}



// Function: FUN_100021e7 at 100021e7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_100021e7(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_100018fe);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10002244 at 10002244

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002244(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10002269 at 10002269

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10002269(int param_1,void *param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x10002275;
  if (param_1 == -1) {
    FUN_10001d6e(param_2,0x1000f510);
    puVar2 = auStack_20;
  }
  else {
    piVar1 = FUN_1000a738(&param_1,param_1);
    local_8 = 0;
    FUN_10001649(param_2,piVar1);
    local_8 = 0xffffffff;
    puVar2 = &stack0xffffffd8;
    Ordinal_6();
  }
  *(undefined4 *)(puVar2 + -4) = 0x100022b7;
  return;
}



// Function: FUN_100022ba at 100022ba

void * __thiscall FUN_100022ba(void *this,char *param_1,void *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  size_t _MaxCount;
  
  if ((param_3 != 0) || (*(void **)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(void **)((int)this + 0x10)) &&
       (uVar4 = (int)*(void **)((int)this + 0x10) - (int)param_2, param_3 <= uVar4)) {
      _MaxCount = uVar4 + (1 - param_3);
      pvVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      param_2 = (void *)((int)param_2 + (int)pvVar3);
      cVar1 = *param_1;
      while (pvVar3 = memchr(param_2,(int)cVar1,_MaxCount), pvVar3 != (void *)0x0) {
        iVar2 = memcmp(pvVar3,param_1,param_3);
        if (iVar2 == 0) {
          if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (void *)((int)pvVar3 - (int)this);
        }
        _MaxCount = (int)param_2 + ((_MaxCount - 1) - (int)pvVar3);
        cVar1 = *param_1;
        param_2 = (void *)((int)pvVar3 + 1);
      }
    }
    param_2 = (void *)0xffffffff;
  }
  return param_2;
}



// Function: FUN_10002359 at 10002359

void __fastcall FUN_10002359(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10002363 at 10002363

uint __thiscall FUN_10002363(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = (*(int *)((int)this + 8) - *this) / 0x1c;
  if (0x9249249 - (uVar1 >> 1) < uVar1) {
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



// Function: FUN_10002392 at 10002392

void __thiscall FUN_10002392(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x21) == '\0') {
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



// Function: FUN_100023d7 at 100023d7

void __thiscall FUN_100023d7(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x21) == '\0') {
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



// Function: FUN_1000241e at 1000241e

void __thiscall FUN_1000241e(void *this,int param_1)

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



// Function: FUN_10002463 at 10002463

void __thiscall FUN_10002463(void *this,int *param_1)

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



// Function: FUN_100024aa at 100024aa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_100024aa(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_1000f834,&local_18);
    (**(code **)*param_1)(param_1,&DAT_1000f834,local_14);
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



// Function: FUN_10002535 at 10002535

uint __thiscall FUN_10002535(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
  uVar1 = FUN_100014b0((ushort *)((int)this + param_1 * 2),param_3,uVar1);
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



// Function: FUN_10002599 at 10002599

void __thiscall FUN_10002599(void *this,ushort *param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(ushort **)param_1;
  }
  FUN_10002535(this,0,*(uint *)((int)this + 0x10),param_1,*puVar1);
  return;
}



// Function: FUN_100025ba at 100025ba

undefined4 * __thiscall FUN_100025ba(void *this,uint param_1,uint param_2)

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



// Function: CComBSTR at 10002634

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(class ATL::CComBSTR const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = Copy(param_1);
  *(wchar_t **)this = pwVar1;
  if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
    FUN_100014e4(0x8007000e);
  }
  return this;
}



// Function: FUN_10002662 at 10002662

int * __thiscall FUN_10002662(void *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != *(int *)param_1) {
    Ordinal_6(*this);
    pwVar1 = ATL::CComBSTR::Copy(param_1);
    *(wchar_t **)this = pwVar1;
    if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
      FUN_100014e4(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_1000269d at 1000269d

void * __thiscall FUN_1000269d(void *this,LPCWSTR param_1)

{
  uint uVar1;
  long lVar2;
  
  uVar1 = lstrlenW(param_1);
  lVar2 = FUN_10001dfb(this,param_1,uVar1);
  if (lVar2 < 0) {
    FUN_100014e4(lVar2);
  }
  return this;
}



// Function: FUN_100026c8 at 100026c8

void * __thiscall FUN_100026c8(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    iVar1 = lstrlenW(param_1);
  }
  FUN_1000213b(this,iVar1,param_1);
  return this;
}



// Function: FUN_100026f0 at 100026f0

int __thiscall FUN_100026f0(void *this,int param_1)

{
  uint _Size;
  void *_Src;
  int iVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  _Src = *this;
  if ((1 < *(LONG *)((int)_Src + -0xc)) || (*(int *)((int)_Src + -4) < param_1)) {
    iVar1 = *(int *)((int)_Src + -8);
    if (param_1 < iVar1) {
      param_1 = iVar1;
    }
    iVar2 = FUN_10002041(this,param_1);
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
    FUN_100018b0((LONG *)((int)_Src + -0xc));
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10002755 at 10002755

undefined4 __thiscall
FUN_10002755(void *this,undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = param_2 + param_4;
  if (iVar1 == 0) {
    *param_1 = PTR_DAT_1001608c;
    local_8 = 1;
  }
  else if ((param_2 <= iVar1) && (iVar2 = FUN_10002041(param_1,iVar1), iVar2 != 0)) {
    if ((uint)(param_2 * 2) <= iVar1 * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
      memcpy((void *)*param_1,(void *)(*this + param_3 * 2),param_2 * 2);
    }
    local_8 = 1;
  }
  return local_8;
}



// Function: FUN_100027cb at 100027cb

void __fastcall FUN_100027cb(int *param_1)

{
  uint _Size;
  void *_Src;
  int iVar1;
  
  _Src = (void *)*param_1;
  if (1 < *(int *)((int)_Src + -0xc)) {
    FUN_100021b4(param_1);
    iVar1 = FUN_10002041(param_1,*(int *)((int)_Src + -8));
    if (iVar1 != 0) {
      _Size = *(int *)((int)_Src + -8) * 2 + 2;
      if (_Size <= *(int *)(*param_1 + -4) * 2 + 2U) {
        memcpy((void *)*param_1,_Src,_Size);
      }
    }
  }
  return;
}



// Function: FUN_1000280c at 1000280c

void __thiscall FUN_1000280c(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((1 < *(int *)(*this + -0xc)) || (*(int *)(*this + -4) < param_1)) {
    FUN_100021b4((int *)this);
    FUN_10002041(this,param_1);
  }
  return;
}



// Function: FUN_1000283a at 1000283a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000283a(int param_1)

{
  int iVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  iVar1 = 0;
  if ((*(int *)(param_1 + 0x8c) == 0) && (*(int *)(param_1 + 0x90) != 0)) {
    local_14[0] = (int *)0x0;
    local_8 = 1;
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x90))
                      (*(undefined4 **)(param_1 + 0x90),&DAT_1000f824,local_14);
    if (-1 < iVar1) {
      (**(code **)(*local_14[0] + 0x20))(local_14[0],(int *)(param_1 + 0x8c));
    }
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  return iVar1;
}



// Function: FUN_100028a1 at 100028a1

int __fastcall FUN_100028a1(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10001b6c((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x20) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x21) = 1;
  return param_1;
}



// Function: _Tidy at 100028d8

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



// Function: FUN_1000291c at 1000291c

IUnknown * __thiscall FUN_1000291c(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_100024aa(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1000f844);
  }
  return pIVar2;
}



// Function: FUN_10002949 at 10002949

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002949(int param_1)

{
  FID_conflict__Tidy((void *)(param_1 + 4),'\x01',0);
  return;
}



// Function: FUN_1000296e at 1000296e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_1000296e(void *this,uint param_1)

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
  FUN_10001c8a((char *)(param_1 + 1));
  FUN_100029fe();
  return;
}



// Function: Catch@100029d0 at 100029d0

undefined * Catch_100029d0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_10001c8a((char *)(iVar1 + 1));
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100029f8;
}



// Function: FUN_100029fe at 100029fe

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100029fe(void)

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



// Function: Catch@10002a47 at 10002a47

void Catch_10002a47(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x1c),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10002a5c at 10002a5c

void __thiscall FUN_10002a5c(void *this,int param_1)

{
  FUN_100027cb((int *)this);
  if (param_1 == -1) {
                    /* WARNING: Load size is inaccurate */
    param_1 = lstrlenW(*this);
  }
                    /* WARNING: Load size is inaccurate */
  *(int *)(*this + -8) = param_1;
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(*this + param_1 * 2) = 0;
  return;
}



// Function: FUN_10002a89 at 10002a89

void __thiscall FUN_10002a89(void *this,int param_1,void *param_2)

{
  uint _Size;
  int iVar1;
  
  iVar1 = FUN_1000280c(this,param_1);
  if (iVar1 != 0) {
    _Size = param_1 * 2;
    if (_Size <= _Size + 2) {
                    /* WARNING: Load size is inaccurate */
      memcpy(*this,param_2,_Size);
    }
                    /* WARNING: Load size is inaccurate */
    *(int *)(*this + -8) = param_1;
                    /* WARNING: Load size is inaccurate */
    *(undefined2 *)(_Size + *this) = 0;
  }
  return;
}



// Function: FUN_10002aca at 10002aca

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10002aca(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int local_38 [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int local_18;
  int local_8;
  undefined4 uStack_4;
  
  iVar2 = param_1;
  uStack_4 = 0x28;
  local_20 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_18 = FUN_1000283a(param_1);
  param_1 = FUN_1000b30d((int)param_3);
  local_1c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = FUN_1000b30d(param_2);
  if (-1 < local_18) {
    piVar1 = *(int **)(iVar2 + 0x8c);
    if (piVar1 != (int *)0x0) {
      local_18 = (**(code **)(*piVar1 + 0x6c))(piVar1,param_1,iVar3,&local_1c);
    }
    if (((-1 < local_18) && (local_1c == (int *)0x0)) && (iVar3 != 0)) {
      local_18 = (**(code **)(**(int **)(iVar2 + 0x8c) + 0x6c))
                           (*(int **)(iVar2 + 0x8c),0,iVar3,&local_1c);
    }
  }
  FUN_1000a67f(local_38);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_24 = 0;
  local_8._0_1_ = 5;
  pcVar4 = Ordinal_6_exref;
  if (local_1c != (int *)0x0) {
    param_2 = 0;
    (**(code **)(*local_1c + 0x24))(local_1c,&param_2);
    FUN_1000a738(&local_28,param_2);
    param_1 = 0;
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_10002662(&param_1,(CComBSTR *)&DAT_1001685c);
    iVar3 = FUN_1000166f(&param_1,local_28);
    if (-1 < iVar3) goto LAB_10002bba;
    do {
      FUN_100014e4(iVar3);
LAB_10002bba:
      iVar3 = FUN_1000166f(&param_1,DAT_10016860);
    } while (iVar3 < 0);
    param_3 = (int *)0x0;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),9);
    local_18 = (**(code **)(**(int **)(iVar2 + 0x84) + 0x94))
                         (*(int **)(iVar2 + 0x84),param_1,&param_3);
    if ((-1 < local_18) && (param_3 != (int *)0x0)) {
      FUN_1000a6e2(local_38,param_3);
      FUN_1000af32(local_38);
      FUN_1000a602(local_38);
      FUN_1000166f(&local_20,local_24);
    }
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_8._0_1_ = 7;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 8))(param_3);
    }
    pcVar4 = Ordinal_6_exref;
    local_8._0_1_ = 6;
    Ordinal_6(param_1);
    local_8._0_1_ = 5;
    Ordinal_6(local_28);
  }
  FUN_10001dc8(&local_20,param_4);
  (*pcVar4)(local_20);
  local_20 = 0;
  local_8._0_1_ = 4;
  (*pcVar4)(local_24);
  local_8._0_1_ = 3;
  FUN_1000a6ac(local_38);
  local_8._0_1_ = 1;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  (*pcVar4)(0);
  return 0;
}



// Function: Catch@10002ca9 at 10002ca9

undefined * Catch_10002ca9(void)

{
  int unaff_EBP;
  
  FUN_10001dc8(*(void **)(unaff_EBP + -0x28),*(undefined4 **)(unaff_EBP + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002cbe;
}



// Function: Catch@10002cc0 at 10002cc0

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 Catch_10002cc0(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar2 = Ordinal_2(L"UNKNOWN EXCEPTION ( CATCon::GetFaultDesc )");
  *(int *)(unaff_EBP + 8) = iVar2;
  if (iVar2 != 0) {
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    FUN_10001dc8((void *)(unaff_EBP + 8),*(undefined4 **)(unaff_EBP + 0x14));
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    return 0x10002c9f;
  }
  iVar2 = -0x7ff8fff2;
  do {
    FUN_100014e4(iVar2);
    iVar2 = FUN_1000166f((void *)(unaff_EBP + 8),DAT_10016860);
  } while (iVar2 < (int)unaff_EBX);
  *(int **)(unaff_EBP + 0x10) = unaff_EBX;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x84) + 0x94))
                    (*(int **)(unaff_ESI + 0x84),*(undefined4 *)(unaff_EBP + 8),unaff_EBP + 0x10);
  *(int *)(unaff_EBP + -0x14) = iVar2;
  if (((int)unaff_EBX <= iVar2) && (*(int **)(unaff_EBP + 0x10) != unaff_EBX)) {
    FUN_1000a6e2((void *)(unaff_EBP + -0x34),*(int **)(unaff_EBP + 0x10));
    FUN_1000af32((undefined4 *)(unaff_EBP + -0x34));
    FUN_1000a602((int *)(unaff_EBP + -0x34));
    FUN_1000166f((void *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x20));
  }
  *(undefined1 *)(unaff_EBP + -4) = 10;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  piVar1 = *(int **)(unaff_EBP + 0x10);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 6;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x24));
  FUN_10001dc8((void *)(unaff_EBP + -0x1c),*(undefined4 **)(unaff_EBP + 0x14));
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x1c));
  *(int **)(unaff_EBP + -0x1c) = unaff_EBX;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x20));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_1000a6ac((int *)(unaff_EBP + -0x34));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar1 = *(int **)(unaff_EBP + -0x18);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  Ordinal_6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0;
}



// Function: FUN_10002d02 at 10002d02

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10002d02(int param_1,int *param_2)

{
  int iVar1;
  wchar_t **pExceptionObject;
  LSTATUS LVar2;
  undefined4 local_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  wchar_t *local_23c;
  DWORD local_238;
  wchar_t *local_234;
  wchar_t *local_230;
  LPCOLESTR local_22c;
  int local_228;
  int *local_224;
  BYTE local_220 [536];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x250;
  local_8 = 0x10002d11;
  local_228 = param_1;
  FUN_10001d6e((void *)(param_1 + 8),0x1000f510);
  local_8 = 0;
  if (*(int **)(param_1 + 0x90) != param_2) {
    FUN_100015df((int *)(param_1 + 0x90),param_2);
  }
  local_24c = 0;
  local_248 = 0;
  local_244 = 0;
  local_8._0_1_ = 1;
  local_240 = 0;
  local_238 = 0x208;
  memset(local_220,0,0x104);
  iVar1 = Open(&local_24c,(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{1332CA33-AB73-4B5B-95AE-051831C69A91}"
               ,0x20019);
  if (iVar1 == 0) {
    LVar2 = FUN_100017b2(&local_24c,local_220,L"FaultsXMLFile",&local_238);
    if (LVar2 == 0) {
      local_224 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,3);
      local_22c = (LPCOLESTR)Ordinal_2(L"Microsoft.FreeThreadedXMLDOM");
      if (local_22c == (LPCOLESTR)0x0) {
        FUN_100014e4(0x8007000e);
      }
      local_8._0_1_ = 4;
      FUN_10001a90(&local_224,local_22c,(LPUNKNOWN)0x0,0x17);
      local_8._0_1_ = 3;
      Ordinal_6(local_22c);
      (**(code **)(*local_224 + 0x110))(local_224,0);
      local_260 = (uint)local_260._2_2_ << 0x10;
      FUN_10001fc7(&local_260,(int)local_220);
      local_8._0_1_ = 5;
      iVar1 = (**(code **)(*local_224 + 0xe8))
                        (local_224,local_260,uStack_25c,uStack_258,uStack_254,&local_240);
      local_8._0_1_ = 3;
      Ordinal_9(&local_260);
      if (iVar1 == 0) {
        FUN_1000291c((void *)(local_228 + 0x84),&local_224);
      }
      if (*(int *)(local_228 + 0x84) != 0) {
        local_8._0_1_ = 1;
        if (local_224 != (int *)0x0) {
          (**(code **)(*local_224 + 8))(local_224);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_24c);
        local_8 = 0xffffffff;
        FUN_1000baa8();
        return;
      }
      local_234 = L"Could not open Faults XML file";
      pExceptionObject = &local_234;
    }
    else {
      local_230 = L"Could not open the needed registry value";
      pExceptionObject = &local_230;
    }
  }
  else {
    local_23c = L"Could not open the needed registry path";
    pExceptionObject = &local_23c;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_100121ec);
}



// Function: Catch@10002f21 at 10002f21

undefined * Catch_10002f21(void)

{
  int unaff_EBP;
  
  FUN_10001f3e((void *)(*(int *)(unaff_EBP + -0x224) + 8),*(LPCSTR *)(unaff_EBP + -0x24c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002f3f;
}



// Function: Catch@10002f41 at 10002f41

undefined4 Catch_10002f41(void)

{
  int unaff_EBP;
  
  FUN_10001d6e((void *)(*(int *)(unaff_EBP + -0x224) + 8),0x1000f8b0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10002f17;
}



// Function: FUN_10002f5e at 10002f5e

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10002f5e(int param_1)

{
  int iVar1;
  wchar_t **pExceptionObject;
  LSTATUS LVar2;
  undefined4 local_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  wchar_t *local_23c;
  DWORD local_238;
  wchar_t *local_234;
  wchar_t *local_230;
  LPCOLESTR local_22c;
  int local_228;
  int *local_224;
  BYTE local_220 [536];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x250;
  local_8 = 0x10002f6d;
  local_228 = param_1;
  FUN_10001d6e((void *)(param_1 + 8),0x1000f510);
  local_24c = 0;
  local_248 = 0;
  local_244 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_240 = 0;
  local_238 = 0x208;
  memset(local_220,0,0x104);
  iVar1 = Open(&local_24c,(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{1ECBBE0A-836B-11D4-8A76-00062999E309}"
               ,0x20019);
  if (iVar1 == 0) {
    LVar2 = FUN_100017b2(&local_24c,local_220,L"StyleSheetTranslatorLocation",&local_238);
    if (LVar2 == 0) {
      local_224 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,3);
      local_22c = (LPCOLESTR)Ordinal_2(L"Microsoft.FreeThreadedXMLDOM");
      if (local_22c == (LPCOLESTR)0x0) {
        FUN_100014e4(0x8007000e);
      }
      local_8._0_1_ = 4;
      FUN_10001a90(&local_224,local_22c,(LPUNKNOWN)0x0,0x17);
      local_8._0_1_ = 3;
      Ordinal_6(local_22c);
      (**(code **)(*local_224 + 0x110))(local_224,0);
      local_260 = (uint)local_260._2_2_ << 0x10;
      FUN_10001fc7(&local_260,(int)local_220);
      local_8._0_1_ = 5;
      iVar1 = (**(code **)(*local_224 + 0xe8))
                        (local_224,local_260,uStack_25c,uStack_258,uStack_254,&local_240);
      local_8._0_1_ = 3;
      Ordinal_9(&local_260);
      if (iVar1 == 0) {
        FUN_1000291c((void *)(local_228 + 0x88),&local_224);
      }
      if (*(int *)(local_228 + 0x88) != 0) {
        local_8._0_1_ = 1;
        if (local_224 != (int *)0x0) {
          (**(code **)(*local_224 + 8))(local_224);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_24c);
        local_8 = 0xffffffff;
        FUN_1000baa8();
        return;
      }
      local_234 = L"Could not open ECM Images Style Sheet Translator XML file";
      pExceptionObject = &local_234;
    }
    else {
      local_230 = L"Could not open the needed registry value";
      pExceptionObject = &local_230;
    }
  }
  else {
    local_23c = L"Could not open the needed registry path";
    pExceptionObject = &local_23c;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_100121ec);
}



// Function: Catch@10003169 at 10003169

undefined * Catch_10003169(void)

{
  int unaff_EBP;
  
  FUN_10001d6e((void *)(*(int *)(unaff_EBP + -0x224) + 8),*(int *)(unaff_EBP + -0x24c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003187;
}



// Function: Catch@10003189 at 10003189

undefined4 Catch_10003189(void)

{
  int unaff_EBP;
  
  FUN_10001d6e((void *)(*(int *)(unaff_EBP + -0x224) + 8),0x1000f8b0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000315f;
}



// Function: FUN_100031a6 at 100031a6

void __fastcall
FUN_100031a6(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_100031b0 at 100031b0

bool __thiscall FUN_100031b0(void *this,uint param_1,char param_2)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *extraout_ECX;
  
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_1000296e(this,param_1);
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



// Function: FUN_10003215 at 10003215

void * __thiscall FUN_10003215(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    iVar1 = lstrlenW(param_1);
  }
  FUN_10002a89(this,iVar1,param_1);
  return this;
}



// Function: FUN_1000323d at 1000323d

int __thiscall FUN_1000323d(void *this,LPCWSTR param_1,size_t *param_2)

{
  size_t *arglist;
  size_t *psVar1;
  WCHAR WVar2;
  LPCWSTR lpsz;
  uint uVar3;
  LPWSTR pWVar4;
  int iVar5;
  size_t sVar6;
  uint local_14;
  int local_10;
  size_t local_c;
  size_t local_8;
  
  arglist = param_2;
  local_10 = 0;
  WVar2 = *param_1;
  lpsz = param_1;
  do {
    if (WVar2 == L'\0') {
      iVar5 = FUN_100026f0(this,local_10);
      if (iVar5 != 0) {
                    /* WARNING: Load size is inaccurate */
        wvsprintfW(*this,param_1,(va_list)arglist);
        FUN_10002a5c(this,-1);
        iVar5 = 1;
      }
      return iVar5;
    }
    if (*lpsz == L'%') {
      lpsz = CharNextW(lpsz);
      WVar2 = *lpsz;
      if (WVar2 == L'%') goto LAB_10003514;
      sVar6 = 0;
      local_c = 0;
      if (WVar2 == L'\0') {
LAB_100032d6:
        local_c = _wtoi(lpsz);
        while ((*lpsz != L'\0' && (iVar5 = iswdigit(*lpsz), iVar5 != 0))) {
          lpsz = CharNextW(lpsz);
        }
      }
      else {
        do {
          if (WVar2 == L'#') {
            local_10 = local_10 + 2;
          }
          else if (WVar2 == L'*') {
            local_c = *param_2;
            param_2 = param_2 + 1;
          }
          else if ((((WVar2 != L'-') && (WVar2 != L'+')) && (WVar2 != L'0')) && (WVar2 != L' '))
          break;
          lpsz = CharNextW(lpsz);
          WVar2 = *lpsz;
        } while (WVar2 != L'\0');
        if (local_c == 0) goto LAB_100032d6;
      }
      local_8 = 0;
      if (*lpsz == L'.') {
        lpsz = CharNextW(lpsz);
        if (*lpsz == L'*') {
          local_8 = *param_2;
          lpsz = CharNextW(lpsz);
          param_2 = param_2 + 1;
        }
        else {
          local_8 = _wtoi(lpsz);
          while ((*lpsz != L'\0' && (iVar5 = iswdigit(*lpsz), iVar5 != 0))) {
            lpsz = CharNextW(lpsz);
          }
        }
      }
      psVar1 = param_2;
      WVar2 = *lpsz;
      local_14 = 0;
      if (((WVar2 == L'I') && (lpsz[1] == L'6')) && (lpsz[2] == L'4')) {
        lpsz = lpsz + 3;
        local_14 = 0x40000;
      }
      else {
        if (((WVar2 != L'F') && (WVar2 != L'L')) && (WVar2 != L'N')) {
          if (WVar2 == L'h') {
            local_14 = 0x10000;
          }
          else {
            if (WVar2 != L'l') goto LAB_100033a1;
            local_14 = 0x20000;
          }
        }
        lpsz = CharNextW(lpsz);
      }
LAB_100033a1:
      uVar3 = (ushort)*lpsz | local_14;
      if (uVar3 < 0x10064) {
        if ((uVar3 != 0x10063) && (uVar3 != 0x43)) {
          if (uVar3 == 0x53) goto LAB_10003493;
          if (uVar3 != 99) {
            if (uVar3 == 0x73) {
              if ((LPCWSTR)*param_2 == (LPCWSTR)0x0) goto LAB_10003443;
              sVar6 = lstrlenW((LPCWSTR)*param_2);
              goto LAB_100034a8;
            }
            if (uVar3 != 0x10043) {
              if (uVar3 != 0x10053) goto LAB_100033e5;
              goto LAB_10003493;
            }
          }
        }
LAB_10003451:
        sVar6 = 2;
LAB_100034ba:
        param_2 = psVar1 + 1;
        if ((int)sVar6 <= (int)local_c) {
          sVar6 = local_c;
        }
        if ((local_8 != 0) && ((int)local_8 <= (int)sVar6)) {
          sVar6 = local_8;
        }
      }
      else {
        if (uVar3 != 0x10073) {
          if (uVar3 != 0x20043) {
            if (uVar3 == 0x20053) {
LAB_1000347b:
              if ((wchar_t *)*param_2 == (wchar_t *)0x0) goto LAB_10003443;
              sVar6 = wcslen((wchar_t *)*param_2);
              goto LAB_100034a8;
            }
            if (uVar3 != 0x20063) {
              if (uVar3 == 0x20073) goto LAB_1000347b;
              goto LAB_100033e5;
            }
          }
          goto LAB_10003451;
        }
LAB_10003493:
        if ((LPCSTR)*param_2 == (LPCSTR)0x0) {
LAB_10003443:
          sVar6 = 6;
          goto LAB_100034ba;
        }
        sVar6 = lstrlenA((LPCSTR)*param_2);
LAB_100034a8:
        param_2 = param_2 + 1;
        if ((int)sVar6 < 1) {
          sVar6 = 1;
        }
        if (sVar6 != 0) goto LAB_100034ba;
LAB_100033e5:
        uVar3 = (uint)(ushort)*lpsz;
        if (uVar3 < 0x6a) {
          if (uVar3 == 0x69) goto LAB_100034e7;
          if ((uVar3 != 0x45) && (uVar3 != 0x47)) {
            if ((uVar3 == 0x58) || (uVar3 == 100)) goto LAB_100034e7;
            if (2 < uVar3 - 0x65) goto LAB_1000350f;
          }
          OutputDebugStringW(
                            L"Floating point (%%e, %%f, %%g, and %%G) is not supported by the WTL::CString class."
                            );
          DebugBreak();
        }
        else if (uVar3 == 0x6e) {
          param_2 = param_2 + 1;
        }
        else {
          if (uVar3 == 0x6f) {
LAB_100034e7:
            if ((local_14 & 0x40000) == 0) goto LAB_100034f6;
            param_2 = param_2 + 2;
          }
          else {
            if (uVar3 != 0x70) {
              if ((uVar3 != 0x75) && (uVar3 != 0x78)) goto LAB_1000350f;
              goto LAB_100034e7;
            }
LAB_100034f6:
            param_2 = param_2 + 1;
          }
          sVar6 = 0x20;
          if (0x1f < (int)(local_8 + local_c)) {
            sVar6 = local_8 + local_c;
          }
        }
      }
LAB_1000350f:
      local_10 = local_10 + sVar6;
    }
    else {
LAB_10003514:
      pWVar4 = CharNextW(lpsz);
      local_10 = local_10 + ((int)pWVar4 - (int)lpsz >> 1);
    }
    lpsz = CharNextW(lpsz);
    WVar2 = *lpsz;
  } while( true );
}



// Function: FUN_1000355f at 1000355f

void __thiscall FUN_1000355f(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  iVar1 = FUN_100018d6(param_1,local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_100026f0(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_100018d6(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_10002a5c(this,-1);
  }
  else {
    FUN_10003215(this,local_208);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003608 at 10003608

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10003608(undefined *param_1,int param_2,int param_3,wchar_t *param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int *local_40;
  undefined *local_3c;
  int local_38;
  undefined2 local_34 [8];
  uint local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_3c = param_1;
  local_44 = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 1;
  if (param_3 == 0) {
    local_48 = 0;
LAB_10003643:
    local_8._0_1_ = 2;
    local_38 = FUN_1000b30d(local_48);
    local_4c = FUN_1000283a((int)param_1);
    local_40 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
    iVar2 = FUN_1000b30d(param_2);
    if (-1 < local_4c) {
      piVar1 = *(int **)(param_1 + 0x8c);
      if (piVar1 != (int *)0x0) {
        local_4c = (**(code **)(*piVar1 + 0x6c))(piVar1,local_38,iVar2,&local_40);
      }
      if (((-1 < local_4c) && (local_40 == (int *)0x0)) && (iVar2 != 0)) {
        local_4c = (**(code **)(**(int **)(param_1 + 0x8c) + 0x6c))
                             (*(int **)(param_1 + 0x8c),0,iVar2,&local_40);
      }
    }
    FUN_1000b4f3(local_34,param_4);
    param_1 = wcslen_exref;
    local_8._0_1_ = 5;
    if ((local_4c != 0) && (local_40 == (int *)0x0)) goto LAB_1000382e;
    local_38 = 0;
    sVar3 = wcslen(L"FMI");
    uVar4 = FUN_10002535(local_34,0,local_24,(ushort *)&DAT_1000fdb8,sVar3);
    if (uVar4 != 0) goto LAB_10003726;
    (**(code **)(*local_40 + 0x30))(local_40,&local_38);
  }
  else {
    local_48 = Ordinal_2(param_3);
    if (local_48 != 0) goto LAB_10003643;
    FUN_100014e4(0x8007000e);
LAB_10003726:
    uVar4 = (*(code *)param_1)(L"FMI2");
    uVar4 = FUN_10002535(local_34,0,local_24,(ushort *)L"FMI2",uVar4);
    if (uVar4 == 0) {
      (**(code **)(*local_40 + 0x34))(local_40,&local_38);
    }
    else {
      uVar4 = (*(code *)param_1)(&DAT_1000fda4);
      uVar4 = FUN_10002535(local_34,0,local_24,(ushort *)&DAT_1000fda4,uVar4);
      if (uVar4 == 0) {
        (**(code **)(*local_40 + 0x2c))(local_40,&local_38);
      }
      else {
        uVar4 = (*(code *)param_1)(&DAT_1000fd9c);
        uVar4 = FUN_10002535(local_34,0,local_24,(ushort *)&DAT_1000fd9c,uVar4);
        if (uVar4 == 0) {
          (**(code **)(*local_40 + 0x28))(local_40,&local_38);
        }
        else {
          uVar4 = (*(code *)param_1)(&DAT_1000fd94);
          uVar4 = FUN_10002535(local_34,0,local_24,(ushort *)&DAT_1000fd94,uVar4);
          if (uVar4 != 0) {
            uVar4 = (*(code *)param_1)(L"Lamp");
            uVar4 = FUN_10002535(local_34,0,local_24,(ushort *)L"Lamp",uVar4);
            if (uVar4 == 0) {
              local_3c = (undefined *)0x0;
              local_8._0_1_ = 6;
              (**(code **)(*local_40 + 0x3c))(local_40,&local_3c);
              FUN_1000166f(&local_44,local_3c);
              Ordinal_6(local_3c);
              local_3c = (undefined *)0x0;
              local_8._0_1_ = 5;
              Ordinal_6(0);
            }
            goto LAB_1000382e;
          }
          (**(code **)(*local_40 + 0x38))(local_40,&local_38);
        }
      }
    }
  }
  FUN_10002269(local_38,&local_44);
LAB_1000382e:
  FUN_10001dc8(&local_44,param_5);
  Ordinal_6(local_44);
  local_44 = 0;
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8._0_1_ = 2;
  if (local_40 != (int *)0x0) {
    (**(code **)(*local_40 + 8))(local_40);
  }
  local_8._0_1_ = 1;
  Ordinal_6(local_48);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  local_8 = 0xffffffff;
  FUN_1000baa8();
  return;
}



// Function: Catch@10003888 at 10003888

undefined * Catch_10003888(void)

{
  int unaff_EBP;
  
  FUN_10001dc8(*(void **)(unaff_EBP + -0x54),*(undefined4 **)(unaff_EBP + -0x4c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000389d;
}



// Function: Catch@1000389f at 1000389f

undefined4 Catch_1000389f(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_EBX;
  int unaff_EBP;
  code *unaff_ESI;
  
  iVar4 = Ordinal_2(L"UNKNOWN EXCEPTION ( CATCon::GetFaultAttribute )");
  *(int *)(unaff_EBP + -0x44) = iVar4;
  if (iVar4 != 0) {
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_10001dc8((void *)(unaff_EBP + -0x44),*(undefined4 **)(unaff_EBP + -0x4c));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    Ordinal_6(*(undefined4 *)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    return 0x1000387e;
  }
  FUN_100014e4(0x8007000e);
  uVar2 = (*unaff_ESI)(L"FMI2");
  uVar2 = FUN_10002535((void *)(unaff_EBP + -0x30),(uint)unaff_EBX,*(uint *)(unaff_EBP + -0x20),
                       (ushort *)L"FMI2",uVar2);
  if (uVar2 == 0) {
    (**(code **)(**(int **)(unaff_EBP + -0x3c) + 0x34))
              (*(int **)(unaff_EBP + -0x3c),unaff_EBP + -0x34);
  }
  else {
    uVar2 = (*unaff_ESI)(&DAT_1000fda4);
    uVar2 = FUN_10002535((void *)(unaff_EBP + -0x30),(uint)unaff_EBX,*(uint *)(unaff_EBP + -0x20),
                         (ushort *)&DAT_1000fda4,uVar2);
    if (uVar2 == 0) {
      (**(code **)(**(int **)(unaff_EBP + -0x3c) + 0x2c))
                (*(int **)(unaff_EBP + -0x3c),unaff_EBP + -0x34);
    }
    else {
      uVar2 = (*unaff_ESI)(&DAT_1000fd9c);
      uVar2 = FUN_10002535((void *)(unaff_EBP + -0x30),(uint)unaff_EBX,*(uint *)(unaff_EBP + -0x20),
                           (ushort *)&DAT_1000fd9c,uVar2);
      if (uVar2 == 0) {
        (**(code **)(**(int **)(unaff_EBP + -0x3c) + 0x28))
                  (*(int **)(unaff_EBP + -0x3c),unaff_EBP + -0x34);
      }
      else {
        uVar2 = (*unaff_ESI)(&DAT_1000fd94);
        uVar2 = FUN_10002535((void *)(unaff_EBP + -0x30),(uint)unaff_EBX,
                             *(uint *)(unaff_EBP + -0x20),(ushort *)&DAT_1000fd94,uVar2);
        if (uVar2 != 0) {
          uVar2 = (*unaff_ESI)(L"Lamp");
          uVar2 = FUN_10002535((void *)(unaff_EBP + -0x30),(uint)unaff_EBX,
                               *(uint *)(unaff_EBP + -0x20),(ushort *)L"Lamp",uVar2);
          if (uVar2 == 0) {
            *(int **)(unaff_EBP + -0x38) = unaff_EBX;
            *(undefined1 *)(unaff_EBP + -4) = 6;
            (**(code **)(**(int **)(unaff_EBP + -0x3c) + 0x3c))
                      (*(int **)(unaff_EBP + -0x3c),unaff_EBP + -0x38);
            FUN_1000166f((void *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x38));
            Ordinal_6(*(undefined4 *)(unaff_EBP + -0x38));
            *(int **)(unaff_EBP + -0x38) = unaff_EBX;
            *(undefined1 *)(unaff_EBP + -4) = 5;
            Ordinal_6(*(undefined4 *)(unaff_EBP + -0x38));
          }
          goto LAB_1000382e;
        }
        (**(code **)(**(int **)(unaff_EBP + -0x3c) + 0x38))
                  (*(int **)(unaff_EBP + -0x3c),unaff_EBP + -0x34);
      }
    }
  }
  FUN_10002269(*(int *)(unaff_EBP + -0x34),(void *)(unaff_EBP + -0x40));
LAB_1000382e:
  FUN_10001dc8((void *)(unaff_EBP + -0x40),*(undefined4 **)(unaff_EBP + -0x4c));
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x40));
  *(int **)(unaff_EBP + -0x40) = unaff_EBX;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FID_conflict__Tidy((void *)(unaff_EBP + -0x30),'\x01',(int)unaff_EBX);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  piVar1 = *(int **)(unaff_EBP + -0x3c);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x44));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  Ordinal_6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar3 = FUN_1000baa8();
  return uVar3;
}



// Function: FUN_100038db at 100038db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100038db(void *this,byte param_1)

{
  FID_conflict__Tidy((void *)((int)this + 4),'\x01',0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FID_conflict:assign at 10003913

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
    bVar1 = FUN_1000131f(this,param_2,'\0');
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
    this = FUN_100013a8(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003991 at 10003991

undefined4 * __thiscall FUN_10003991(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_100025ba(this,_Size + uVar4,0xffffffff);
    FUN_100025ba(this,0,param_2);
  }
  else {
    bVar1 = FUN_100031b0(this,_Size,'\0');
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



// Function: FUN_10003a2b at 10003a2b

undefined4 * __thiscall FUN_10003a2b(void *this,LPCWSTR param_1)

{
  uint _Size;
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_1001608c;
  if (param_1 != (LPCWSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_1000355f(this,(uint)param_1 & 0xffff);
    }
    else {
      iVar1 = lstrlenW(param_1);
      if (((iVar1 != 0) && (iVar2 = FUN_10002041(this,iVar1), iVar2 != 0)) &&
         (_Size = iVar1 * 2, _Size <= _Size + 2)) {
                    /* WARNING: Load size is inaccurate */
        memcpy(*this,param_1,_Size);
      }
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10003a8e at 10003a8e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10003a8e(void *this,undefined4 *param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*(int *)(*this + -8) < param_2) {
      param_2 = *(int *)(*this + -8);
    }
  }
  *param_1 = PTR_DAT_1001608c;
                    /* WARNING: Load size is inaccurate */
  FUN_10002755(this,param_1,param_2,*(int *)(*this + -8) - param_2,0);
  return param_1;
}



// Function: FUN_10003ae9 at 10003ae9

void __cdecl FUN_10003ae9(void *param_1,LPCWSTR param_2)

{
  FUN_1000323d(param_1,param_2,(size_t *)&stack0x0000000c);
  return;
}



// Function: FUN_10003afd at 10003afd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10003afd(void *this,int param_1)

{
  void *this_00;
  wchar_t *pwVar1;
  undefined *local_220;
  wchar_t local_21c;
  undefined1 local_21a [530];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x210;
  local_220 = PTR_DAT_1001608c;
  local_8 = 0;
  FUN_10003ae9(&local_220,L"%d");
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  this_00 = (void *)((int)this + 0x54);
  FUN_10003215(this_00,L"<ErrorInfo>");
  FUN_100026c8(this_00,L"<ErrorNumber>");
  _itow_s(param_1,&local_21c,0x104,10);
  FUN_100026c8(this_00,&local_21c);
  FUN_100026c8(this_00,L"</ErrorNumber>");
  FUN_100026c8(this_00,L"<Description>");
  if (param_1 == 99000) {
    FUN_100026c8(this_00,L"The XML Resource File could not be located.");
    FUN_100026c8(this_00,L"</Description>");
    FUN_100026c8(this_00,L"<Suggestion>");
    FUN_100026c8(this_00,L"Make sure the ");
    FUN_1000213b(this_00,*(int *)((int)*(void **)((int)this + 8) + -8),*(void **)((int)this + 8));
    FUN_100026c8(this_00,L" file is located in the \"");
    FUN_1000213b(this_00,*(int *)((int)*(void **)((int)this + 0x4c) + -8),
                 *(void **)((int)this + 0x4c));
    FUN_100026c8(this_00,L"\" folder. ");
    pwVar1 = L"Make sure XMLResources registry key is pointing to the correct location.";
  }
  else if (param_1 == 0x182b9) {
    FUN_100026c8(this_00,L"The XML Resource File does not contain a string table.");
    FUN_100026c8(this_00,L"</Description>");
    FUN_100026c8(this_00,L"<Suggestion>");
    FUN_100026c8(this_00,L"Make sure the \"");
    FUN_1000213b(this_00,*(int *)((int)*(void **)((int)this + 8) + -8),*(void **)((int)this + 8));
    FUN_100026c8(this_00,L"\" file located in the \"");
    FUN_1000213b(this_00,*(int *)((int)*(void **)((int)this + 0x4c) + -8),
                 *(void **)((int)this + 0x4c));
    pwVar1 = L"\" folder contains a string table with RESOURCE[Tag=1001].";
  }
  else {
    if (param_1 != 0x182ba) goto LAB_10003d20;
    FUN_100026c8(this_00,L"The XML Resource string was not found.");
    FUN_100026c8(this_00,L"</Description>");
    FUN_100026c8(this_00,L"<Suggestion>");
    FUN_100026c8(this_00,L"Make sure the \"");
    FUN_1000213b(this_00,*(int *)((int)*(void **)((int)this + 8) + -8),*(void **)((int)this + 8));
    FUN_100026c8(this_00,L"\" file located in the \"");
    FUN_1000213b(this_00,*(int *)((int)*(void **)((int)this + 0x4c) + -8),
                 *(void **)((int)this + 0x4c));
    FUN_100026c8(this_00,L"\" folder contains a string with STRING[ID=");
    FUN_1000213b(this_00,*(int *)(local_220 + -8),local_220);
    pwVar1 = L"].";
  }
  FUN_100026c8(this_00,pwVar1);
  FUN_100026c8(this_00,L"</Suggestion>");
LAB_10003d20:
  FUN_100026c8(this_00,L"</ErrorInfo>");
  local_8 = 0xffffffff;
  FUN_10002015((int *)&local_220);
  FUN_1000ba99();
  return;
}



// Function: FUN_10003d43 at 10003d43

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10003d43(undefined4 *param_1)

{
  int iVar1;
  long lVar2;
  undefined4 local_458;
  undefined4 uStack_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  ulong local_448 [2];
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  short local_434 [2];
  wchar_t *local_430;
  int local_42c;
  wchar_t local_428 [260];
  wchar_t local_220 [268];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x448;
  local_448[1] = 0;
  local_440 = 0;
  local_43c = 0;
  local_438 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  iVar1 = Open(&local_440,(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths",0x2001f);
  if (iVar1 == 0) {
    local_430 = (wchar_t *)0x208;
    lVar2 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_440,L"XMLResources",local_428,(ulong *)&local_430);
    if (lVar2 == 0) {
      wcscpy_s(local_220,0x104,local_428);
      FUN_10003a2b(&local_42c,local_428);
      local_8._0_1_ = 2;
      FUN_10003a8e(&local_42c,&local_430,1);
      local_8 = CONCAT31(local_8._1_3_,3);
      iVar1 = wcscmp(local_430,L"\\");
      if (iVar1 != 0) {
        wcscat_s(local_220,0x104,L"\\");
      }
      FUN_10003215(param_1 + 0x13,local_220);
      FUN_10001b53(local_220,(wchar_t *)param_1[2]);
      local_8._0_1_ = 2;
      FUN_10002015((int *)&local_430);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_10002015(&local_42c);
      ATL::CRegKey::Close((CRegKey *)&local_440);
      iVar1 = Open(&local_440,(HKEY)0x80000002,
                   L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",0x2001f);
      if (iVar1 == 0) {
        local_448[0] = 0x208;
        lVar2 = ATL::CRegKey::QueryStringValue
                          ((CRegKey *)&local_440,L"LanguageExt",local_428,local_448);
        if (lVar2 == 0) {
          wcscat_s(local_220,0x104,L"_");
          wcscat_s(local_220,0x104,local_428);
          wcscat_s(local_220,0x104,L".xml");
        }
        else {
          wcscat_s(local_220,0x104,L"_en.xml");
        }
        ATL::CRegKey::Close((CRegKey *)&local_440);
      }
      else {
        wcscat_s(local_220,0x104,L"_en.xml");
      }
      (**(code **)(*(int *)*param_1 + 0x110))((int *)*param_1,0);
      local_42c = Ordinal_2(local_220);
      if (local_42c == 0) {
        FUN_100014e4(0x8007000e);
      }
      local_8._0_1_ = 4;
      local_458 = (uint)local_458._2_2_ << 0x10;
      FUN_10001f7c(&local_458,(CComBSTR *)&local_42c);
      local_8._0_1_ = 5;
      iVar1 = (**(code **)(*(int *)*param_1 + 0xe8))
                        ((int *)*param_1,local_458,uStack_454,uStack_450,uStack_44c,local_434);
      local_8._0_1_ = 4;
      Ordinal_9(&local_458);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(local_42c);
      if ((iVar1 < 0) || (local_434[0] != -1)) {
        FUN_10003215(param_1 + 0x14,local_220);
        FUN_10003afd(param_1,99000);
      }
      else {
        local_448[1] = 1;
      }
      local_8 = local_8 & 0xffffff00;
      ATL::CRegKey::Close((CRegKey *)&local_440);
      local_8 = 0xffffffff;
      FUN_1000baa8();
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@10004028 at 10004028

undefined4 Catch_10004028(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10004015;
}



// Function: FUN_10004032 at 10004032

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10004032(void)

{
  int iVar1;
  long lVar2;
  HMODULE pHVar3;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  int local_434;
  wchar_t *local_430;
  ulong local_42c;
  wchar_t local_428 [260];
  wchar_t local_220 [268];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x434;
  local_440 = 0;
  local_43c = 0;
  local_438 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  iVar1 = Open(&local_440,(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths",0x2001f);
  if (iVar1 == 0) {
    local_42c = 0x208;
    lVar2 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_440,L"DllResources",local_428,&local_42c);
    if (lVar2 == 0) {
      wcscpy_s(local_220,0x104,local_428);
      FUN_10003a2b(&local_42c,local_428);
      local_8._0_1_ = 2;
      FUN_10003a8e(&local_42c,&local_430,1);
      local_8 = CONCAT31(local_8._1_3_,3);
      iVar1 = wcscmp(local_430,L"\\");
      if (iVar1 != 0) {
        wcscat_s(local_220,0x104,L"\\");
      }
      FUN_10003215((void *)(local_434 + 0x4c),local_220);
      FUN_10001b53(local_220,*(wchar_t **)(local_434 + 8));
      local_8._0_1_ = 2;
      FUN_10002015((int *)&local_430);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_10002015((int *)&local_42c);
      ATL::CRegKey::Close((CRegKey *)&local_440);
      iVar1 = Open(&local_440,(HKEY)0x80000002,
                   L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",0x2001f);
      if (iVar1 == 0) {
        local_430 = (wchar_t *)0x208;
        lVar2 = ATL::CRegKey::QueryStringValue
                          ((CRegKey *)&local_440,L"LanguageExt",local_428,(ulong *)&local_430);
        if (lVar2 == 0) {
          wcscat_s(local_220,0x104,L"_");
          wcscat_s(local_220,0x104,local_428);
          wcscat_s(local_220,0x104,L".dll");
        }
        else {
          wcscat_s(local_220,0x104,L"_en.dll");
        }
        ATL::CRegKey::Close((CRegKey *)&local_440);
      }
      else {
        wcscat_s(local_220,0x104,L"_en.dll");
      }
      pHVar3 = LoadLibraryW(local_220);
      *(HMODULE *)(local_434 + 4) = pHVar3;
      if (pHVar3 == (HMODULE)0x0) {
        FUN_10003215((void *)(local_434 + 0x50),local_220);
      }
      local_8 = local_8 & 0xffffff00;
      ATL::CRegKey::Close((CRegKey *)&local_440);
      local_8 = 0xffffffff;
      FUN_1000baa8();
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: Catch@1000428f at 1000428f

undefined4 Catch_1000428f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000427c;
}



// Function: FUN_10004299 at 10004299

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10004299(void *this,uint param_1,void *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  int local_1c;
  undefined *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x100042a5;
  (**(code **)(*(int *)((int)this + 0xc) + 4))();
  local_2c = 0x80004005;
  *(uint *)((int)this + 0x58) = param_1;
  if (*(int *)((int)this + 0x48) == 1) {
    local_8 = 0;
    cVar1 = FUN_10001ee7(param_2,*(HINSTANCE__ **)((int)this + 4),param_1);
    if (cVar1 == '\x01') {
      local_2c = 0;
    }
    local_8 = 0xffffffff;
    Ordinal_6(0);
  }
  else {
    if (*(int *)((int)this + 0x44) != 0) {
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      local_24 = Ordinal_2(L".//RESOURCE[@Tag = \"");
      if (local_24 != 0) goto LAB_1000431f;
      do {
        iVar2 = -0x7ff8fff2;
        while( true ) {
          FUN_100014e4(iVar2);
LAB_1000431f:
          local_8._0_1_ = 2;
          FUN_1000269d(&local_24,L"1001");
          FUN_1000269d(&local_24,L"\"]");
          local_20 = (int *)0x0;
          local_8._0_1_ = 4;
                    /* WARNING: Load size is inaccurate */
          iVar2 = (**(code **)(**this + 0x94))(*this,local_24,&local_20);
          if ((iVar2 < 0) || (local_20 == (int *)0x0)) {
            FUN_10003afd(this,0x182b9);
            goto LAB_10004467;
          }
          local_1c = Ordinal_2(L"STRING[@ID = \"");
          if (local_1c == 0) break;
          local_18[0] = PTR_DAT_1001608c;
          local_8._0_1_ = 6;
          FUN_10003ae9(local_18,L"%d");
          if (local_18[0] == (undefined *)0x0) {
            param_1 = 0;
            goto LAB_100043b7;
          }
          param_1 = Ordinal_2(local_18[0]);
          if (param_1 == 0) break;
LAB_100043b7:
          local_8._0_1_ = 7;
          iVar2 = FUN_1000166f(&local_1c,param_1);
          if (-1 < iVar2) {
            local_8._0_1_ = 6;
            Ordinal_6(param_1);
            FUN_1000269d(&local_1c,L"\"]");
            local_28 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,9);
            iVar2 = (**(code **)(*local_20 + 0x94))(local_20,local_1c,&local_28);
            if ((iVar2 < 0) || (local_28 == (int *)0x0)) {
              FUN_10003afd(this,0x182ba);
            }
            else {
              (**(code **)(*local_28 + 0x68))(local_28,param_2);
              local_2c = 0;
            }
            local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
            local_8._0_1_ = 6;
            if (local_28 != (int *)0x0) {
              (**(code **)(*local_28 + 8))(local_28);
            }
            local_8._0_1_ = 5;
            FUN_10002015((int *)local_18);
            local_8._0_1_ = 4;
            Ordinal_6(local_1c);
LAB_10004467:
            local_8._0_1_ = 2;
            if (local_20 != (int *)0x0) {
              (**(code **)(*local_20 + 8))(local_20);
            }
            local_8 = CONCAT31(local_8._1_3_,1);
            Ordinal_6(local_24);
            local_8 = 0xffffffff;
            goto LAB_100044b7;
          }
        }
      } while( true );
    }
    FUN_10003afd(this,99000);
  }
LAB_100044b7:
  (**(code **)(*(int *)((int)this + 0xc) + 8))();
  return local_2c;
}



// Function: Catch@1000448f at 1000448f

undefined * Catch_1000448f(void)

{
  int unaff_EBP;
  
  FUN_10003afd(*(void **)(unaff_EBP + -0x2c),99000);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100044a6;
}



// Function: basic_string<> at 100044ca

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
  FUN_100013a8(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 100044f2

/* Library Function - Single Match
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > const &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  *(undefined4 *)(this + 0x14) = 0xf;
  *(undefined4 *)(this + 0x10) = 0;
  *this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  FUN_10003991(this,(undefined4 *)param_1,0,0xffffffff);
  return this;
}



// Function: FUN_10004518 at 10004518

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10004518(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  LPCOLESTR pOVar3;
  int iVar4;
  
  iVar2 = FUN_1000191f();
  if (iVar2 == -1) {
    return -0x7fffbffb;
  }
  if (0 < param_1) {
    if (iVar2 < param_1) {
      return -0x7fffbffb;
    }
    *(int *)((int)this + 0x48) = param_2;
    if (param_2 == 1) {
      FUN_10003215((void *)((int)this + 8),(LPCWSTR)(&PTR_u_Reserved_100160c0)[param_1]);
      iVar2 = FUN_10004032();
      *(int *)((int)this + 0x44) = iVar2;
      if (iVar2 == 0) {
        return -0x7fffbffb;
      }
    }
    else {
      FUN_10003215((void *)((int)this + 8),(LPCWSTR)(&PTR_u_Reserved_10016090)[param_1]);
                    /* WARNING: Load size is inaccurate */
      piVar1 = *this;
      if (piVar1 != (int *)0x0) {
        *(undefined4 *)this = 0;
        (**(code **)(*piVar1 + 8))(piVar1);
                    /* WARNING: Load size is inaccurate */
        if (*this != 0) {
          FUN_100015df((int *)this,(int *)0x0);
        }
      }
      pOVar3 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
      if (pOVar3 == (LPCOLESTR)0x0) {
        FUN_100014e4(0x8007000e);
      }
      iVar2 = FUN_10001a90(this,pOVar3,(LPUNKNOWN)0x0,0x17);
      Ordinal_6(pOVar3);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar4 = FUN_10003d43((undefined4 *)this);
      *(int *)((int)this + 0x44) = iVar4;
      if (iVar4 == 0) {
                    /* WARNING: Load size is inaccurate */
        piVar1 = *this;
        if (piVar1 != (int *)0x0) {
          *(undefined4 *)this = 0;
          (**(code **)(*piVar1 + 8))(piVar1);
        }
                    /* WARNING: Load size is inaccurate */
        if (*this == 0) {
          return iVar2;
        }
        FUN_100015df((int *)this,(int *)0x0);
        return iVar2;
      }
    }
    return 0;
  }
  return -0x7fffbffb;
}



// Function: FUN_1000461c at 1000461c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000461c(int param_1,wchar_t *param_2,undefined4 *param_3)

{
  wchar_t wVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_14[0] = 0;
  local_1c = 0;
  local_18 = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  iVar2 = wcsncmp(L"CEC0",param_2,4);
  if (iVar2 == 0) {
    uVar3 = 0x6c;
  }
  else {
    wVar1 = param_2[8];
    if (wVar1 == L'0') {
      uVar3 = 0x6e;
    }
    else {
      if (wVar1 != L'1') {
        if (wVar1 == L'2') {
          uVar3 = 0x70;
        }
        else if (wVar1 == L'3') {
          uVar3 = 0x72;
        }
        else if (wVar1 == L'9') {
          uVar3 = 0x73;
        }
        else {
          uVar3 = 0x74;
        }
        uVar4 = 0x71;
        goto LAB_1000468d;
      }
      uVar3 = 0x6f;
    }
  }
  uVar4 = 0x6d;
LAB_1000468d:
  FUN_10004299((void *)(param_1 + 0x14),uVar3,&local_1c);
  FUN_10004299((void *)(param_1 + 0x14),uVar4,&local_18);
  FUN_10002662(local_14,(CComBSTR *)&local_1c);
  uVar3 = lstrlenW(L" / ");
  FUN_10001dfb(local_14,&DAT_10010408,uVar3);
  FUN_1000166f(local_14,local_18);
  FUN_10001dc8(local_14,param_3);
  local_8._0_1_ = 1;
  Ordinal_6(local_18);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_1c);
  local_8 = 0xffffffff;
  Ordinal_6(local_14[0]);
  return 0;
}



// Function: FUN_1000470d at 1000470d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000470d(int param_1)

{
  int iVar1;
  wchar_t **pExceptionObject;
  LSTATUS LVar2;
  undefined4 local_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  wchar_t *local_240;
  wchar_t *local_23c;
  DWORD local_238;
  wchar_t *local_234;
  undefined4 local_230;
  LPCOLESTR local_22c;
  int local_228;
  int *local_224;
  BYTE local_220 [536];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x254;
  local_8 = 0x1000471c;
  local_228 = param_1;
  *(undefined1 *)(param_1 + 0x10) = 0;
  FUN_10001d6e((void *)(param_1 + 8),0x1000f510);
  local_8 = 0;
  iVar1 = FUN_10004518((void *)(param_1 + 0x14),3,1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 0x10) = 1;
  }
  local_24c = 0;
  local_248 = 0;
  local_244 = 0;
  local_8._0_1_ = 1;
  local_230 = 0;
  local_238 = 0x208;
  memset(local_220,0,0x104);
  iVar1 = Open(&local_24c,(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{6C62E21C-145A-4039-8515-4DCB4CBF2404}"
               ,0x20019);
  if (iVar1 == 0) {
    LVar2 = FUN_100017b2(&local_24c,local_220,L"AuditTrailFile",&local_238);
    if (LVar2 == 0) {
      local_224 = (int *)0x0;
      local_250 = 0;
      local_8 = CONCAT31(local_8._1_3_,5);
      local_22c = (LPCOLESTR)Ordinal_2(L"Microsoft.FreeThreadedXMLDOM");
      if (local_22c == (LPCOLESTR)0x0) {
        FUN_100014e4(0x8007000e);
      }
      local_8._0_1_ = 6;
      FUN_10001a90(&local_224,local_22c,(LPUNKNOWN)0x0,0x17);
      local_8._0_1_ = 5;
      Ordinal_6(local_22c);
      (**(code **)(*local_224 + 0x110))(local_224,0);
      local_260 = (uint)local_260._2_2_ << 0x10;
      FUN_10001fc7(&local_260,(int)local_220);
      local_8._0_1_ = 7;
      iVar1 = (**(code **)(*local_224 + 0xe8))
                        (local_224,local_260,uStack_25c,uStack_258,uStack_254,&local_230);
      local_8._0_1_ = 5;
      Ordinal_9(&local_260);
      if (iVar1 == 0) {
        FUN_1000291c((void *)(local_228 + 0x80),&local_224);
      }
      if (*(int *)(local_228 + 0x80) != 0) {
        local_8._0_1_ = 1;
        if (local_224 != (int *)0x0) {
          (**(code **)(*local_224 + 8))(local_224);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::Close((CRegKey *)&local_24c);
        local_8 = 0xffffffff;
        FUN_1000baa8();
        return;
      }
      local_234 = L"Could not open AuditTrail XML file";
      pExceptionObject = &local_234;
    }
    else {
      local_23c = L"Could not open the needed registry value";
      pExceptionObject = &local_23c;
    }
  }
  else {
    local_240 = L"Could not open the needed registry path";
    pExceptionObject = &local_240;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_100121ec);
}



// Function: Catch@1000493e at 1000493e

undefined * Catch_1000493e(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x224);
  FUN_10001f3e((void *)(iVar1 + 8),*(LPCSTR *)(unaff_EBP + -0x260));
  *(undefined1 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004960;
}



// Function: Catch@10004962 at 10004962

undefined4 Catch_10004962(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x224);
  FUN_10001d6e((void *)(iVar1 + 8),0x1000f8b0);
  *(undefined1 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10004934;
}



// Function: FUN_10004983 at 10004983

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_10004983(void *this,undefined1 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *param_1 = 0;
  FUN_10003991(param_1,(undefined4 *)this,param_2,param_3);
  return param_1;
}



// Function: FUN_100049c7 at 100049c7

undefined2 * __thiscall FUN_100049c7(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_100049f9 at 100049f9

void __thiscall FUN_100049f9(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return;
}



// Function: FUN_10004a19 at 10004a19

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 *
FUN_10004a19(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000cca5;
  if (param_1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0
     ) {
    puVar1 = (undefined1 *)
             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
             basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       (param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10004a47 at 10004a47

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __cdecl
FUN_10004a47(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000cca5;
  if (param_1 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0
     ) {
    puVar1 = (undefined1 *)
             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
             basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       (param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10004a76 at 10004a76

void __cdecl
FUN_10004a76(undefined4 param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_2,true,0);
  return;
}



// Function: FUN_10004a87 at 10004a87

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10004a87(undefined4 *param_1)

{
  undefined4 **ppuVar1;
  int iVar2;
  undefined4 *puVar3;
  uint in_stack_00000018;
  void *in_stack_00000020;
  int *in_stack_00000024;
  int iStack_64;
  undefined4 in_stack_ffffffb8;
  int *in_stack_ffffffbc;
  int local_38 [3];
  void *local_2c;
  int local_28;
  int *local_24;
  undefined1 *local_20;
  wchar_t *local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_2c = in_stack_00000020;
  local_28 = 0;
  local_18[0] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  FUN_10001d6e(local_18,0x100105d0);
  ppuVar1 = (undefined4 **)param_1;
  if (in_stack_00000018 < 8) {
    ppuVar1 = &param_1;
  }
  if (ppuVar1 == (undefined4 **)0x0) {
    local_20 = (undefined1 *)0x0;
  }
  else {
    local_20 = (undefined1 *)Ordinal_2();
    if (local_20 == (undefined1 *)0x0) goto LAB_10004af3;
  }
  local_8._0_1_ = 3;
  iVar2 = FUN_1000166f(local_18,local_20);
  puVar3 = in_stack_00000024;
  if (-1 < iVar2) goto LAB_10004afd;
  while( true ) {
    FUN_100014e4(iVar2);
LAB_10004afd:
    local_8._0_1_ = 2;
    Ordinal_6();
    FUN_1000269d(local_18,L"\"]");
    local_24 = (int *)0x0;
    local_8._0_1_ = 5;
    local_28 = (**(code **)(*(int *)*puVar3 + 0x94))();
    Ordinal_6();
    local_18[0] = 0;
    if (local_28 != 0) goto LAB_10004bc3;
    FUN_1000a67f(local_38);
    local_1c = (wchar_t *)0x0;
    local_8._0_1_ = 7;
    iStack_64 = 0x10004b64;
    FUN_1000a6e2(local_38,local_24);
    local_20 = (undefined1 *)&iStack_64;
    iStack_64 = Ordinal_2(L"Resource");
    in_stack_00000024 = &iStack_64;
    if (iStack_64 != 0) break;
LAB_10004af3:
    iVar2 = -0x7ff8fff2;
    puVar3 = in_stack_00000024;
  }
  local_8._0_1_ = 7;
  FUN_1000b1a2(local_38,in_stack_ffffffb8,in_stack_ffffffbc);
  FUN_100049f9(local_2c,local_1c);
  Ordinal_6();
  local_1c = (wchar_t *)0x0;
  FUN_1000a602(local_38);
  local_8._0_1_ = 6;
  Ordinal_6();
  local_8._0_1_ = 5;
  FUN_1000a6ac(local_38);
LAB_10004bc3:
  local_8._0_1_ = 2;
  if (local_24 != (int *)0x0) {
    iStack_64 = 0x10004bd8;
    (**(code **)(*local_24 + 8))();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  iStack_64 = 0x10004bdf;
  Ordinal_6();
  local_8 = 0;
  FUN_10004c0b();
  return;
}



// Function: Catch@10004be4 at 10004be4

undefined * Catch_10004be4(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_retaddr;
  int iStack_20;
  wchar_t *pwVar4;
  
  pwVar4 = L"UNKNOWN EXCEPTION ( CATCon::internalAuditXMLMap )";
  iVar3 = Ordinal_2();
  if (iVar3 != 0) {
    Ordinal_6();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    return &DAT_10004c09;
  }
  do {
    FUN_100014e4(0x8007000e);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    Ordinal_6();
    FUN_1000269d((void *)(unaff_EBP + -0x14),L"\"]");
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    uVar1 = (**(code **)(*(int *)*unaff_EBX + 0x94))();
    *(undefined4 *)(unaff_EBP + -0x24) = uVar1;
    Ordinal_6();
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (*(int *)(unaff_EBP + -0x24) != 0) goto LAB_10004bc3;
    FUN_1000a67f((undefined4 *)(unaff_EBP + -0x34));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    iStack_20 = 0x10004b64;
    FUN_1000a6e2((void *)(unaff_EBP + -0x34),*(int **)(unaff_EBP + -0x20));
    unaff_EBX = &iStack_20;
    *(int **)(unaff_EBP + -0x1c) = &iStack_20;
    iStack_20 = Ordinal_2(L"Resource");
  } while (iStack_20 == 0);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_1000b1a2((void *)(unaff_EBP + -0x34),pwVar4,unaff_retaddr);
  FUN_100049f9(*(void **)(unaff_EBP + -0x28),*(wchar_t **)(unaff_EBP + -0x18));
  Ordinal_6();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_1000a602((int *)(unaff_EBP + -0x34));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  Ordinal_6();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_1000a6ac((int *)(unaff_EBP + -0x34));
LAB_10004bc3:
  *(undefined1 *)(unaff_EBP + -4) = 9;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (*(int **)(unaff_EBP + -0x20) != (int *)0x0) {
    iStack_20 = 0x10004bd8;
    (**(code **)(**(int **)(unaff_EBP + -0x20) + 8))();
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iStack_20 = 0x10004bdf;
  Ordinal_6();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar2 = (undefined *)FUN_10004c0b();
  return puVar2;
}



// Function: FUN_10004c0b at 10004c0b

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004c0b(void)

{
  int unaff_EBP;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__Tidy((void *)(unaff_EBP + 8),'\x01',unaff_EDI);
  return *(undefined4 *)(unaff_EBP + -0x24);
}



// Function: FUN_10004c25 at 10004c25

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10004c25(int param_1,int param_2,undefined4 *param_3)

{
  size_t sVar1;
  undefined4 ***pppuVar2;
  int iVar3;
  int local_68;
  wchar_t *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int *local_54;
  undefined2 local_50 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 **local_34 [4];
  undefined4 local_24;
  uint local_20;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = (undefined4 **)((uint)local_34[0] & 0xffff0000);
  local_3c = 7;
  local_40 = 0;
  local_50[0] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  if (param_2 == 0) {
    local_60 = (wchar_t *)0x0;
  }
  else {
    local_60 = (wchar_t *)Ordinal_2(param_2);
    if (local_60 == (wchar_t *)0x0) goto LAB_10004cbd;
  }
  local_8._0_1_ = 3;
  sVar1 = wcslen(local_60);
  FID_conflict_assign(local_34,(undefined4 *)local_60,sVar1);
  local_58 = 0;
  local_8._0_1_ = 4;
  FUN_10001d6e(&local_58,0x1001065c);
  pppuVar2 = (undefined4 ***)local_34[0];
  if (local_20 < 8) {
    pppuVar2 = local_34;
  }
  if (pppuVar2 != (undefined4 ***)0x0) goto LAB_10004cc7;
  local_68 = 0;
  while( true ) {
    local_8._0_1_ = 5;
    iVar3 = FUN_1000166f(&local_58,local_68);
    if (-1 < iVar3) break;
    while( true ) {
      pppuVar2 = (undefined4 ***)FUN_100014e4(iVar3);
LAB_10004cc7:
      local_68 = Ordinal_2(pppuVar2);
      if (local_68 != 0) break;
LAB_10004cbd:
      iVar3 = -0x7ff8fff2;
    }
  }
  local_8._0_1_ = 4;
  Ordinal_6(local_68);
  FUN_1000269d(&local_58,L"\"]");
  local_54 = (int *)0x0;
  local_8._0_1_ = 7;
  iVar3 = (**(code **)(**(int **)(param_1 + 0x88) + 0x94))
                    (*(int **)(param_1 + 0x88),local_58,&local_54);
  Ordinal_6(local_58);
  local_58 = 0;
  if (iVar3 == 0) {
    local_5c = 0;
    local_8._0_1_ = 8;
    (**(code **)(*local_54 + 0x68))(local_54,&local_5c);
    FUN_10001dc8(&local_5c,param_3);
    Ordinal_6(local_5c);
    local_5c = 0;
    local_8._0_1_ = 7;
    Ordinal_6(0);
  }
  local_8._0_1_ = 4;
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))(local_54);
  }
  local_8._0_1_ = 3;
  Ordinal_6(0);
  local_8._0_1_ = 2;
  Ordinal_6(local_60);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_50,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1000baa8();
  return;
}



// Function: Catch@10004db6 at 10004db6

undefined * Catch_10004db6(void)

{
  int unaff_EBP;
  
  FUN_10001dc8(*(void **)(unaff_EBP + -0x68),*(undefined4 **)(unaff_EBP + -0x60));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004dcb;
}



// Function: Catch@10004dcd at 10004dcd

undefined4 Catch_10004dcd(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_EDI;
  
  iVar3 = Ordinal_2(L"UNKNOWN EXCEPTION ( CATCon::GetImageHeader )");
  *(int *)(unaff_EBP + -0x50) = iVar3;
  if (iVar3 != 0) {
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_10001dc8((void *)(unaff_EBP + -0x50),*(undefined4 **)(unaff_EBP + -0x60));
    *(undefined1 *)(unaff_EBP + -4) = 10;
    Ordinal_6(*(undefined4 *)(unaff_EBP + -0x50));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    return 0x10004dac;
  }
  do {
    iVar3 = -0x7ff8fff2;
    while( true ) {
      uVar1 = FUN_100014e4(iVar3);
      piVar2 = (int *)Ordinal_2(uVar1);
      *(int **)(unaff_EBP + -100) = piVar2;
      if (piVar2 == unaff_EBX) break;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      iVar3 = FUN_1000166f((void *)(unaff_EBP + -0x54),*(undefined4 *)(unaff_EBP + -100));
      if ((int)unaff_EBX <= iVar3) {
        *(undefined1 *)(unaff_EBP + -4) = 4;
        Ordinal_6(*(undefined4 *)(unaff_EBP + -100));
        FUN_1000269d((void *)(unaff_EBP + -0x54),L"\"]");
        *(int **)(unaff_EBP + -0x50) = unaff_EBX;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        *(undefined1 *)(unaff_EBP + -4) = 7;
        piVar2 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x88) + 0x94))
                                  (*(int **)(unaff_EDI + 0x88),*(undefined4 *)(unaff_EBP + -0x54),
                                   unaff_EBP + -0x50);
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x54));
        *(int **)(unaff_EBP + -0x54) = unaff_EBX;
        if (piVar2 == unaff_EBX) {
          *(int **)(unaff_EBP + -0x58) = unaff_EBX;
          *(undefined1 *)(unaff_EBP + -4) = 8;
          (**(code **)(**(int **)(unaff_EBP + -0x50) + 0x68))
                    (*(int **)(unaff_EBP + -0x50),unaff_EBP + -0x58);
          FUN_10001dc8((void *)(unaff_EBP + -0x58),*(undefined4 **)(unaff_EBP + -0x60));
          Ordinal_6(*(undefined4 *)(unaff_EBP + -0x58));
          *(int **)(unaff_EBP + -0x58) = unaff_EBX;
          *(undefined1 *)(unaff_EBP + -4) = 7;
          Ordinal_6(*(undefined4 *)(unaff_EBP + -0x58));
        }
        *(undefined1 *)(unaff_EBP + -4) = 9;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        piVar2 = *(int **)(unaff_EBP + -0x50);
        if (piVar2 != unaff_EBX) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
        *(undefined1 *)(unaff_EBP + -4) = 3;
        Ordinal_6();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x5c));
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FID_conflict__Tidy((void *)(unaff_EBP + -0x4c),'\x01',(int)unaff_EBX);
        *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
        FID_conflict__Tidy((void *)(unaff_EBP + -0x30),'\x01',(int)unaff_EBX);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar1 = FUN_1000baa8();
        return uVar1;
      }
    }
  } while( true );
}



// Function: FUN_10004e09 at 10004e09

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10004e09(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  if ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this !=
      param_1) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
               true,0);
    if (*(uint *)(param_1 + 0x14) < 0x10) {
      memmove(this,param_1,*(int *)(param_1 + 0x10) + 1);
    }
    else {
      *(undefined4 *)this = *(undefined4 *)param_1;
      *(undefined4 *)param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_10004e61 at 10004e61

void __cdecl
FUN_10004e61(undefined4 param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)

{
  FUN_10004a19(param_2,param_3);
  return;
}



// Function: FUN_10004e74 at 10004e74

void __cdecl FUN_10004e74(undefined4 param_1,void *param_2)

{
  FUN_100038db(param_2,0);
  return;
}



// Function: FUN_10004e83 at 10004e83

void __cdecl
FUN_10004e83(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,
            undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    FUN_10004a76(param_3,param_1);
  }
  return;
}



// Function: basic_string<> at 10004ea2

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > &&)
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(char const * const)
   
   Library: Visual Studio */

undefined1 * __thiscall
basic_string<>(void *this,
              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined1 *)this = 0;
  FUN_10004e09(this,param_1);
  return (undefined1 *)this;
}



// Function: FUN_10004ec5 at 10004ec5

void __thiscall FUN_10004ec5(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_10001b18((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_10004f0f;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x2d) == '\0') {
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
    iVar1 = param_2[0xb];
    *(char *)(param_2 + 0xb) = (char)piVar2[0xb];
    *(char *)(piVar2 + 0xb) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_10004f0f:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x2d) == '\0') {
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
      if (*(char *)((int)piVar7 + 0x2d) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x2d) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x2d) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x2d) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[0xb] != '\x01') {
LAB_100050ec:
    FUN_10004e74((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_100050a0:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xb] != '\x01'))
  goto LAB_100050e8;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_1000241e(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x2c) = 1;
          *(undefined1 *)(piVar5 + 0xb) = 0;
          FUN_10002463(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        FUN_1000241e(this,(int)piVar6);
        goto LAB_100050e8;
      }
LAB_10005097:
      *(undefined1 *)(piVar5 + 0xb) = 0;
    }
  }
  else {
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10002463(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
      goto LAB_10005097;
      if (*(char *)(*piVar5 + 0x2c) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        *(undefined1 *)(piVar5 + 0xb) = 0;
        FUN_1000241e(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(*piVar5 + 0x2c) = 1;
      FUN_10002463(this,piVar6);
LAB_100050e8:
      *(undefined1 *)(piVar7 + 0xb) = 1;
      goto LAB_100050ec;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_100050a0;
}



// Function: FUN_10005122 at 10005122

void __thiscall FUN_10005122(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_10005122(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10004e74((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_10005166 at 10005166

void __cdecl
FUN_10005166(undefined4 param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)

{
  FUN_10004a47(param_2,param_3);
  return;
}



// Function: FUN_10005178 at 10005178

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 *
FUN_10005178(void *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000cca5;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_100051a6 at 100051a6

void __fastcall FUN_100051a6(void *param_1)

{
  FUN_10005122(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_100051cd at 100051cd

void __cdecl
FUN_100051cd(undefined4 param_1,void *param_2,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)

{
  FUN_10005178(param_2,param_3);
  return;
}



// Function: FUN_100051e0 at 100051e0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl
FUN_100051e0(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,
            void *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    FUN_100051cd(param_4,param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: Catch@10005224 at 10005224

void Catch_10005224(void)

{
  int unaff_EBP;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  
  for (pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                 (unaff_EBP + -0x14);
      pbVar1 != *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                 (unaff_EBP + 0x10); pbVar1 = pbVar1 + 0x1c) {
    FUN_10004a76(*(undefined4 *)(unaff_EBP + 0x14),pbVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10005246 at 10005246

void __fastcall FUN_10005246(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_10004e83(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  param_1,*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                            **)(param_1 + 4),param_1 + 0xc);
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10005281 at 10005281

void __thiscall FUN_10005281(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_100051a6(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_10001b18((int *)&param_2);
      FUN_10004ec5(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: _Uninitialized_move<> at 100052d4

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
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,
          void *param_3,undefined4 param_4)

{
  FUN_100051e0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100052f3 at 100052f3

void __fastcall FUN_100052f3(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_10004e83(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  param_1,*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                            **)(param_1 + 4),param_1 + 0xc);
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_100052f8 at 100052f8

void __thiscall
FUN_100052f8(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,
            void *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_10005314 at 10005314

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005314(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10005281(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000534e at 1000534e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000534e(void *this,char *param_1)

{
  int iVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  void *pvVar3;
  
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    pvVar3 = FUN_10001bcb(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_100052f8(this,*this,
                 *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  ((int)this + 4),pvVar3);
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    pbVar2 = *this;
    if (pbVar2 != (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x0) {
      FUN_10004e83(pbVar2,*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                            **)((int)this + 4),(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(void **)((int)this + 8) = (void *)((int)param_1 * 0x1c + (int)pvVar3);
    *(void **)((int)this + 4) = (void *)(((iVar1 - (int)pbVar2) / 0x1c) * 0x1c + (int)pvVar3);
    *(void **)this = pvVar3;
  }
  return;
}



// Function: Catch@100053f5 at 100053f5

void Catch_100053f5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10005408 at 10005408

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005408(void *param_1)

{
  FUN_10005314(param_1);
  return;
}



// Function: FUN_10005426 at 10005426

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005426(int param_1)

{
  FUN_10005314((void *)(param_1 + 4));
  return;
}



// Function: FUN_1000544e at 1000544e

void __thiscall FUN_1000544e(void *this,int param_1)

{
  uint uVar1;
  char *pcVar2;
  int extraout_ECX;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar3 = *this;
  uVar1 = (*(int *)((int)this + 4) - iVar3) / 0x1c;
  if (0x9249249U - param_1 < uVar1) {
    std::_Xlength_error("vector<T> too long");
    iVar3 = extraout_ECX;
  }
  uVar1 = uVar1 + param_1;
  if ((uint)((*(int *)((int)this + 8) - iVar3) / 0x1c) < uVar1) {
    pcVar2 = (char *)FUN_10002363(this,uVar1);
    FUN_1000534e(this,pcVar2);
  }
  return;
}



// Function: FUN_100054a3 at 100054a3

void __thiscall
FUN_100054a3(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  
  pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
            ((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < pbVar1) && (pbVar2 = *this, pbVar2 <= param_1)) {
    if (pbVar1 == *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                   ((int)this + 8)) {
      FUN_1000544e(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
              ((((int)param_1 - (int)pbVar2) / 0x1c) * 0x1c + *this);
  }
  else if (pbVar1 == *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       **)((int)this + 8)) {
    FUN_1000544e(this,1);
  }
  FUN_100051cd((int)this + 0xc,*(void **)((int)this + 4),param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  return;
}



// Function: FUN_10005503 at 10005503

void __thiscall
FUN_10005503(void *this,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  
  pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
            ((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < pbVar1) && (pbVar2 = *this, pbVar2 <= param_1)) {
    if (pbVar1 == *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                   ((int)this + 8)) {
      FUN_1000544e(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    FUN_10004e61((int)this + 0xc,
                 *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  ((int)this + 4),
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 ((((int)param_1 - (int)pbVar2) / 0x1c) * 0x1c + *this));
  }
  else {
    if (pbVar1 == *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                   ((int)this + 8)) {
      FUN_1000544e(this,1);
    }
    FUN_10005166((int)this + 0xc,
                 *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  ((int)this + 4),param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  return;
}



// Function: FUN_10005570 at 10005570

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10005570(int param_1,LPCWSTR param_2,wchar_t *param_3,undefined4 *param_4)

{
  size_t sVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  ushort *puVar4;
  void *pvVar5;
  uint uVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar7;
  code *unaff_ESI;
  undefined4 *in_stack_fffffcd4;
  LPCWSTR pWVar8;
  LPCWSTR *ppWVar9;
  CComBSTR local_2f0 [4];
  int local_2ec [3];
  int local_2e0;
  int local_2dc;
  undefined4 local_2d8;
  int local_2d0;
  undefined4 local_2cc;
  undefined4 *local_2c8;
  int *local_2c4;
  undefined4 local_2c0;
  int local_2bc;
  wchar_t *local_2b8;
  int local_2b4;
  undefined4 local_2b0;
  undefined1 *local_2ac;
  undefined1 *local_2a8;
  int *local_2a4;
  wchar_t *local_2a0;
  undefined4 local_29c;
  char local_295;
  LPCWSTR local_294;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_290 [28];
  undefined4 local_274 [4];
  undefined4 local_264;
  undefined4 local_260;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_258 [28];
  undefined4 ***local_23c [4];
  undefined4 local_22c;
  uint local_228;
  wchar_t local_220 [268];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2e8;
  local_2d0 = param_1;
  local_294 = param_2;
  local_2a0 = param_3;
  local_2c8 = param_4;
  local_2c0 = 0;
  local_2b0 = 0;
  local_260 = 7;
  local_264 = 0;
  local_274[0]._0_2_ = 0;
  local_8._1_3_ = 0;
  local_228 = 7;
  local_22c = 0;
  local_23c[0] = (undefined4 ***)((uint)local_23c[0] & 0xffff0000);
  local_8._0_1_ = 3;
  if (param_3 == (wchar_t *)0x0) {
    local_2b8 = (wchar_t *)0x0;
  }
  else {
    local_2b8 = (wchar_t *)Ordinal_2();
    if (local_2b8 == (wchar_t *)0x0) goto LAB_100056a6;
  }
  local_8._0_1_ = 4;
  sVar1 = wcslen(local_2b8);
  FID_conflict_assign(local_274,(undefined4 *)local_2b8,sVar1);
  unaff_ESI = (code *)(param_1 + 0x80);
  local_2ac = &stack0xfffffcd4;
  basic_string<>(&stack0xfffffcd4,local_274);
  local_8._0_1_ = 4;
  iVar2 = FUN_10004a87(in_stack_fffffcd4);
  local_29c = 0;
  local_8._0_1_ = 6;
  if (iVar2 == 0) {
    FUN_10001d6e(&local_29c,0x10010760);
    ppppuVar3 = (undefined4 ****)local_23c[0];
    if (local_228 < 8) {
      ppppuVar3 = local_23c;
    }
    if (ppppuVar3 != (undefined4 ****)0x0) goto LAB_100056b0;
    local_2a8 = (undefined1 *)0x0;
    while( true ) {
      local_8._0_1_ = 7;
      iVar2 = FUN_1000166f(&local_29c,local_2a8);
      if (-1 < iVar2) break;
LAB_100056ab:
      while( true ) {
        FUN_100014e4(iVar2);
LAB_100056b0:
        local_2a8 = (undefined1 *)Ordinal_2();
        if (local_2a8 != (undefined1 *)0x0) break;
LAB_100056a6:
        iVar2 = -0x7ff8fff2;
      }
    }
  }
  else {
    FUN_10001d6e(&local_29c,0x10010760);
    local_2ac = (undefined1 *)Ordinal_2();
    if (local_2ac == (undefined1 *)0x0) goto LAB_100056a6;
    local_8._0_1_ = 8;
    iVar2 = FUN_1000166f(&local_29c,local_2ac);
    if (iVar2 < 0) goto LAB_100056ab;
  }
  local_8._0_1_ = 6;
  Ordinal_6();
  FUN_1000269d(&local_29c,L"\"]");
  local_2c4 = (int *)0x0;
  local_8._0_1_ = 10;
  (**(code **)(**(int **)unaff_ESI + 0x94))();
  Ordinal_6();
  local_29c = 0;
  if (*(char *)(local_2d0 + 0x10) == '\0') {
    ATL::CComBSTR::CComBSTR(local_2f0,(CComBSTR *)(local_2d0 + 8));
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_2f0,(ThrowInfo *)&DAT_10012a1c);
  }
  FUN_1000b574(local_290,local_294);
  local_2e0 = 0;
  local_2dc = 0;
  local_2d8 = 0;
  local_8._0_1_ = 0xc;
  puVar4 = FUN_1000b4f3((undefined2 *)local_258,local_2a0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  local_2c0 = 1;
  iVar2 = FUN_10002599(&DAT_10016840,puVar4);
  unaff_ESI = (code *)&DAT_1001074c;
  if (iVar2 == 0) {
    sVar1 = strlen(",");
    pvVar5 = FUN_100022ba(local_290,",",(void *)0x0,sVar1);
    local_295 = '\0';
    if (pvVar5 != (void *)0xffffffff) goto LAB_10005828;
  }
  local_295 = '\x01';
LAB_10005828:
  local_8._0_1_ = 0xc;
  local_8._1_3_ = 0;
  local_2c0 = 0;
  FID_conflict__Tidy(local_258,'\x01',0);
  if (local_295 == '\0') {
    local_294 = (LPCWSTR)0x0;
    sVar1 = strlen(",");
    pWVar8 = (LPCWSTR)0x0;
    while (local_2a4 = (int *)FUN_100022ba(local_290,",",pWVar8,sVar1),
          local_2a4 != (int *)0xffffffff) {
      if ((int)local_2a4 - (int)local_294 != 0) {
        FUN_10004983(local_290,local_258,(uint)local_294,(int)local_2a4 - (int)local_294);
        local_8._0_1_ = 0x10;
        FUN_10005503(&local_2e0,local_258);
        local_8._0_1_ = 0xc;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  (local_258,true,0);
      }
      local_294 = (LPCWSTR)((int)local_2a4 + 1);
      sVar1 = strlen(",");
      pWVar8 = local_294;
    }
  }
  else {
    uVar6 = Ordinal_7();
    local_2a0 = (wchar_t *)((uVar6 >> 2) * 3);
    local_2ac = (undefined1 *)malloc((size_t)local_2a0);
    if (local_294 == (LPCWSTR)0x0) {
      local_2a8 = (undefined1 *)0x0;
    }
    else {
      local_2a8 = (undefined1 *)Ordinal_2();
      if (local_2a8 == (undefined1 *)0x0) goto LAB_100056a6;
    }
    local_8 = CONCAT31(local_8._1_3_,0xe);
    FUN_10001971((int)local_2a8,(int)local_2ac,(int *)&local_2a0);
    local_2a8 = (undefined1 *)0x0;
    for (unaff_ESI = (code *)0x0; (int)unaff_ESI < (int)local_2a0; unaff_ESI = unaff_ESI + 1) {
      for (local_2b4 = 0; local_2b4 < 8; local_2b4 = local_2b4 + 1) {
        if (((byte)unaff_ESI[(int)local_2ac] & (byte)(1 << ((byte)local_2b4 & 0x1f))) != 0) {
          pbVar7 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   FUN_1000b752(local_258,local_2b4 + (int)unaff_ESI * 8);
          local_8._0_1_ = 0xf;
          FUN_100054a3(&local_2e0,pbVar7);
          local_8 = CONCAT31(local_8._1_3_,0xe);
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    (local_258,true,0);
        }
      }
    }
    local_8._0_1_ = 0xc;
    Ordinal_6();
  }
  FUN_1000a67f(local_2ec);
  local_8._0_1_ = 0x11;
  local_2ac = (undefined1 *)((local_2dc - local_2e0) / 0x1c);
  for (local_2bc = 0; local_2bc < (int)local_2ac; local_2bc = local_2bc + 1) {
    FUN_1000a7af((char *)(local_2bc * 0x1c + local_2e0));
    _swprintf(local_220,L"AUDIT_CODE[@BitNumber = \"%i\"]");
    local_2a0 = (wchar_t *)Ordinal_2();
    if (local_2a0 == (wchar_t *)0x0) goto LAB_100056a6;
    local_2cc = 0;
    local_294 = (LPCWSTR)0x0;
    if (*(int *)(local_2d0 + 0x80) != 0) {
      local_2a4 = (int *)0x0;
      local_8._0_1_ = 0x16;
      iVar2 = (**(code **)(*local_2c4 + 0x94))();
      if ((-1 < iVar2) && (local_2a4 != (int *)0x0)) {
        FUN_1000a6e2(local_2ec,local_2a4);
        FUN_1000af32(local_2ec);
        ppWVar9 = &local_294;
        unaff_ESI = (code *)&stack0xfffffcf8;
        local_2a8 = &stack0xfffffcf8;
        iVar2 = Ordinal_2();
        if (iVar2 == 0) goto LAB_100056a6;
        local_8._0_1_ = 0x16;
        FUN_1000b1a2(local_2ec,iVar2,(int *)ppWVar9);
        FUN_1000a602(local_2ec);
        FUN_1000166f(&local_2b0,local_294);
        unaff_ESI = lstrlenW_exref;
        uVar6 = lstrlenW(L" - ");
        FUN_10001dfb(&local_2b0,&DAT_100106fc,uVar6);
        FUN_1000166f(&local_2b0,local_2cc);
        uVar6 = lstrlenW(L", ");
        FUN_10001dfb(&local_2b0,&DAT_100106f4,uVar6);
      }
      local_8._0_1_ = 0x14;
      if (local_2a4 != (int *)0x0) {
        (**(code **)(*local_2a4 + 8))();
      }
    }
    local_8._0_1_ = 0x13;
    Ordinal_6();
    local_8._0_1_ = 0x12;
    Ordinal_6();
    local_8._0_1_ = 0x11;
    Ordinal_6();
  }
  FUN_10001dc8(&local_2b0,local_2c8);
  Ordinal_6();
  local_2b0 = 0;
  local_8._0_1_ = 0xc;
  FUN_1000a6ac(local_2ec);
  local_8._0_1_ = 0xb;
  FUN_10005246((_Container_base0 *)&local_2e0);
  local_8._0_1_ = 10;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (local_290,true,0);
  local_8._0_1_ = 6;
  if (local_2c4 != (int *)0x0) {
    (**(code **)(*local_2c4 + 8))();
  }
  local_8._0_1_ = 4;
  Ordinal_6();
  local_8._0_1_ = 3;
  Ordinal_6();
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_23c,'\x01',0);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_274,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6();
  local_8 = 0xffffffff;
  FUN_1000baa8();
  return;
}



// Function: Catch@10005c8c at 10005c8c

undefined * Catch_10005c8c(void)

{
  int unaff_EBP;
  
  FUN_10001dc8(*(void **)(unaff_EBP + -0x2f4),*(undefined4 **)(unaff_EBP + -0x2c4));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005ca7;
}



// Function: Catch@10005ca9 at 10005ca9

undefined4 Catch_10005ca9(void)

{
  undefined4 uVar1;
  int *piVar2;
  ushort *puVar3;
  size_t sVar4;
  void *pvVar5;
  uint uVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar7;
  int *piVar8;
  int iVar9;
  char cVar10;
  int *unaff_EBX;
  int unaff_EBP;
  code *unaff_ESI;
  
  iVar9 = Ordinal_2();
  *(int *)(unaff_EBP + -0x29c) = iVar9;
  if (iVar9 != 0) {
    *(undefined1 *)(unaff_EBP + -4) = 0x1b;
    FUN_10001dc8((void *)(unaff_EBP + -0x29c),*(undefined4 **)(unaff_EBP + -0x2c4));
    *(undefined1 *)(unaff_EBP + -4) = 0x1a;
    Ordinal_6(*(undefined4 *)(unaff_EBP + -0x29c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    return 0x10005c82;
  }
LAB_100056a6:
  iVar9 = -0x7ff8fff2;
  do {
    uVar1 = FUN_100014e4(iVar9);
    piVar2 = (int *)Ordinal_2(uVar1);
    *(int **)(unaff_EBP + -0x2a4) = piVar2;
    if (piVar2 == unaff_EBX) goto LAB_100056a6;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    iVar9 = FUN_1000166f((void *)(unaff_EBP + -0x298),*(undefined4 *)(unaff_EBP + -0x2a4));
  } while (iVar9 < (int)unaff_EBX);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x2a4));
  FUN_1000269d((void *)(unaff_EBP + -0x298),L"\"]");
  *(int **)(unaff_EBP + -0x2c0) = unaff_EBX;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  (**(code **)(**(int **)unaff_ESI + 0x94))
            (*(int **)unaff_ESI,*(undefined4 *)(unaff_EBP + -0x298),unaff_EBP + -0x2c0);
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x298));
  *(int **)(unaff_EBP + -0x298) = unaff_EBX;
  cVar10 = (char)unaff_EBX;
  if (*(char *)(*(int *)(unaff_EBP + -0x2cc) + 0x10) == cVar10) {
    ATL::CComBSTR::CComBSTR
              ((CComBSTR *)(unaff_EBP + -0x2ec),(CComBSTR *)(*(int *)(unaff_EBP + -0x2cc) + 8));
                    /* WARNING: Subroutine does not return */
    _CxxThrowException((void *)(unaff_EBP + -0x2ec),(ThrowInfo *)&DAT_10012a1c);
  }
  FUN_1000b574((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x28c),*(LPCWSTR *)(unaff_EBP + -0x290));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  *(int **)(unaff_EBP + -0x2dc) = unaff_EBX;
  *(int **)(unaff_EBP + -0x2d8) = unaff_EBX;
  *(int **)(unaff_EBP + -0x2d4) = unaff_EBX;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  puVar3 = FUN_1000b4f3((undefined2 *)(unaff_EBP + -0x254),*(wchar_t **)(unaff_EBP + -0x29c));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  *(undefined4 *)(unaff_EBP + -700) = 1;
  iVar9 = FUN_10002599(&DAT_10016840,puVar3);
  unaff_ESI = (code *)&DAT_1001074c;
  if (iVar9 == 0) {
    sVar4 = strlen(",");
    pvVar5 = FUN_100022ba((void *)(unaff_EBP + -0x28c),",",unaff_EBX,sVar4);
    *(char *)(unaff_EBP + -0x291) = cVar10;
    if (pvVar5 == (void *)0xffffffff) goto LAB_10005821;
  }
  else {
LAB_10005821:
    *(undefined1 *)(unaff_EBP + -0x291) = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xc;
  *(undefined4 *)(unaff_EBP + -700) = 1;
  *(uint *)(unaff_EBP + -700) = *(uint *)(unaff_EBP + -700) & 0xfffffffe;
  FID_conflict__Tidy((void *)(unaff_EBP + -0x254),'\x01',(int)unaff_EBX);
  if (*(char *)(unaff_EBP + -0x291) == cVar10) {
    *(int **)(unaff_EBP + -0x290) = unaff_EBX;
    sVar4 = strlen(",");
    piVar2 = unaff_EBX;
    while( true ) {
      pvVar5 = FUN_100022ba((void *)(unaff_EBP + -0x28c),",",piVar2,sVar4);
      *(void **)(unaff_EBP + -0x2a0) = pvVar5;
      if (pvVar5 == (void *)0xffffffff) break;
      uVar6 = (int)pvVar5 - *(int *)(unaff_EBP + -0x290);
      if (uVar6 != 0) {
        FUN_10004983((void *)(unaff_EBP + -0x28c),(undefined1 *)(unaff_EBP + -0x254),
                     *(uint *)(unaff_EBP + -0x290),uVar6);
        *(undefined1 *)(unaff_EBP + -4) = 0x10;
        FUN_10005503((void *)(unaff_EBP + -0x2dc),
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(unaff_EBP + -0x254));
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   (unaff_EBP + -0x254),true,(uint)unaff_EBX);
      }
      *(int *)(unaff_EBP + -0x290) = *(int *)(unaff_EBP + -0x2a0) + 1;
      sVar4 = strlen(",");
      piVar2 = *(int **)(unaff_EBP + -0x290);
    }
    goto LAB_10005950;
  }
  uVar6 = Ordinal_7(*(undefined4 *)(unaff_EBP + -0x290));
  sVar4 = (uVar6 >> 2) * 3;
  *(size_t *)(unaff_EBP + -0x29c) = sVar4;
  pvVar5 = malloc(sVar4);
  *(void **)(unaff_EBP + -0x2a8) = pvVar5;
  if (*(int **)(unaff_EBP + -0x290) != unaff_EBX) goto LAB_10005890;
  piVar2 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -0x2a4) = 0;
  goto LAB_100058aa;
LAB_10005890:
  piVar2 = (int *)Ordinal_2(*(undefined4 *)(unaff_EBP + -0x290));
  *(int **)(unaff_EBP + -0x2a4) = piVar2;
  if (piVar2 != unaff_EBX) {
LAB_100058aa:
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    FUN_10001971((int)piVar2,*(int *)(unaff_EBP + -0x2a8),(int *)(unaff_EBP + -0x29c));
    *(int **)(unaff_EBP + -0x2a4) = unaff_EBX;
    for (unaff_ESI = (code *)0x0; *(code **)(unaff_EBP + -0x2f0) = unaff_ESI,
        (int)unaff_ESI < *(int *)(unaff_EBP + -0x29c); unaff_ESI = unaff_ESI + 1) {
      *(int **)(unaff_EBP + -0x2b0) = unaff_EBX;
      while (*(int *)(unaff_EBP + -0x2b0) < 8) {
        if (((byte)unaff_ESI[*(int *)(unaff_EBP + -0x2a8)] &
            (byte)(1 << ((byte)*(undefined4 *)(unaff_EBP + -0x2b0) & 0x1f))) != 0) {
          pbVar7 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   FUN_1000b752((undefined1 *)(unaff_EBP + -0x254),
                                *(int *)(unaff_EBP + -0x2b0) + (int)unaff_ESI * 8);
          *(undefined1 *)(unaff_EBP + -4) = 0xf;
          FUN_100054a3((void *)(unaff_EBP + -0x2dc),pbVar7);
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(unaff_EBP + -0x254),true,(uint)unaff_EBX);
        }
        *(int *)(unaff_EBP + -0x2b0) = *(int *)(unaff_EBP + -0x2b0) + 1;
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    Ordinal_6(*(undefined4 *)(unaff_EBP + -0x2a4));
LAB_10005950:
    FUN_1000a67f((undefined4 *)(unaff_EBP + -0x2e8));
    *(undefined1 *)(unaff_EBP + -4) = 0x11;
    *(int *)(unaff_EBP + -0x2a8) =
         (*(int *)(unaff_EBP + -0x2d8) - *(int *)(unaff_EBP + -0x2dc)) / 0x1c;
    *(int **)(unaff_EBP + -0x2b8) = unaff_EBX;
    do {
      if (*(int *)(unaff_EBP + -0x2a8) <= *(int *)(unaff_EBP + -0x2b8)) {
        FUN_10001dc8((void *)(unaff_EBP + -0x2ac),*(undefined4 **)(unaff_EBP + -0x2c4));
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x2ac));
        *(int **)(unaff_EBP + -0x2ac) = unaff_EBX;
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        FUN_1000a6ac((int *)(unaff_EBP + -0x2e8));
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        FUN_10005246((_Container_base0 *)(unaff_EBP + -0x2dc));
        *(undefined1 *)(unaff_EBP + -4) = 10;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   (unaff_EBP + -0x28c),true,(uint)unaff_EBX);
        *(undefined1 *)(unaff_EBP + -4) = 0x19;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        piVar2 = *(int **)(unaff_EBP + -0x2c0);
        if (piVar2 != unaff_EBX) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
        *(undefined1 *)(unaff_EBP + -4) = 4;
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x298));
        *(undefined1 *)(unaff_EBP + -4) = 3;
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x2b4));
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FID_conflict__Tidy((void *)(unaff_EBP + -0x238),'\x01',(int)unaff_EBX);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FID_conflict__Tidy((void *)(unaff_EBP + -0x270),'\x01',(int)unaff_EBX);
        *(char *)(unaff_EBP + -4) = cVar10;
        Ordinal_6();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar1 = FUN_1000baa8();
        return uVar1;
      }
      uVar1 = FUN_1000a7af((char *)(*(int *)(unaff_EBP + -0x2b8) * 0x1c +
                                   *(int *)(unaff_EBP + -0x2dc)));
      _swprintf((wchar_t *)(unaff_EBP + -0x21c),L"AUDIT_CODE[@BitNumber = \"%i\"]",uVar1);
      piVar2 = (int *)Ordinal_2(unaff_EBP + -0x21c);
      *(int **)(unaff_EBP + -0x29c) = piVar2;
      if (piVar2 == unaff_EBX) break;
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      *(int **)(unaff_EBP + -0x2c8) = unaff_EBX;
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      *(int **)(unaff_EBP + -0x290) = unaff_EBX;
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      if (*(int **)(*(int *)(unaff_EBP + -0x2cc) + 0x80) != unaff_EBX) {
        *(int **)(unaff_EBP + -0x2a0) = unaff_EBX;
        *(undefined1 *)(unaff_EBP + -4) = 0x15;
        *(undefined1 *)(unaff_EBP + -4) = 0x16;
        iVar9 = (**(code **)(**(int **)(unaff_EBP + -0x2c0) + 0x94))
                          (*(int **)(unaff_EBP + -0x2c0),*(undefined4 *)(unaff_EBP + -0x29c),
                           unaff_EBP + -0x2a0);
        if (((int)unaff_EBX <= iVar9) && (*(int **)(unaff_EBP + -0x2a0) != unaff_EBX)) {
          FUN_1000a6e2((void *)(unaff_EBP + -0x2e8),*(int **)(unaff_EBP + -0x2a0));
          FUN_1000af32((undefined4 *)(unaff_EBP + -0x2e8));
          piVar2 = (int *)(unaff_EBP + -0x290);
          unaff_ESI = (code *)&stack0xfffffffc;
          *(undefined1 **)(unaff_EBP + -0x2a4) = &stack0xfffffffc;
          piVar8 = (int *)Ordinal_2(L"Code");
          if (piVar8 == unaff_EBX) break;
          *(undefined1 *)(unaff_EBP + -4) = 0x17;
          *(undefined1 *)(unaff_EBP + -4) = 0x16;
          FUN_1000b1a2((void *)(unaff_EBP + -0x2e8),piVar8,piVar2);
          FUN_1000a602((int *)(unaff_EBP + -0x2e8));
          FUN_1000166f((void *)(unaff_EBP + -0x2ac),*(undefined4 *)(unaff_EBP + -0x290));
          unaff_ESI = lstrlenW_exref;
          uVar6 = lstrlenW(L" - ");
          FUN_10001dfb((void *)(unaff_EBP + -0x2ac),&DAT_100106fc,uVar6);
          FUN_1000166f((void *)(unaff_EBP + -0x2ac),*(undefined4 *)(unaff_EBP + -0x2c8));
          uVar6 = lstrlenW(L", ");
          FUN_10001dfb((void *)(unaff_EBP + -0x2ac),&DAT_100106f4,uVar6);
        }
        *(undefined1 *)(unaff_EBP + -4) = 0x18;
        *(undefined1 *)(unaff_EBP + -4) = 0x14;
        if (*(int **)(unaff_EBP + -0x2a0) != unaff_EBX) {
          (**(code **)(**(int **)(unaff_EBP + -0x2a0) + 8))();
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      Ordinal_6();
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      Ordinal_6();
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      Ordinal_6(*(undefined4 *)(unaff_EBP + -0x29c));
      *(int *)(unaff_EBP + -0x2b8) = *(int *)(unaff_EBP + -0x2b8) + 1;
    } while( true );
  }
  goto LAB_100056a6;
}



// Function: FUN_10005cf1 at 10005cf1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_10005cf1(undefined4 param_1,int param_2)

{
  FUN_10005426(param_2);
  return;
}



// Function: FUN_10005d0f at 10005d0f

void __thiscall FUN_10005d0f(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x21) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_10001add((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x21) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x21) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_10005d59;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x21) == '\0') {
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
    iVar1 = param_2[8];
    *(char *)(param_2 + 8) = (char)piVar2[8];
    *(char *)(piVar2 + 8) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_10005d59:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
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
      if (*(char *)((int)piVar7 + 0x21) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x21) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x21) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x21) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[8] != '\x01') {
LAB_10005f36:
    FUN_10005cf1((int)this + 0xd,(int)(piVar2 + 3));
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_10005eea:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[8] != '\x01'))
  goto LAB_10005f32;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[8] == '\0') {
      *(undefined1 *)(piVar5 + 8) = 1;
      *(undefined1 *)(piVar6 + 8) = 0;
      FUN_10002392(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x21) == '\0') {
      if ((*(char *)(*piVar5 + 0x20) != '\x01') || (*(char *)(piVar5[2] + 0x20) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x20) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x20) = 1;
          *(undefined1 *)(piVar5 + 8) = 0;
          FUN_100023d7(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 8) = (char)piVar6[8];
        *(undefined1 *)(piVar6 + 8) = 1;
        *(undefined1 *)(piVar5[2] + 0x20) = 1;
        FUN_10002392(this,(int)piVar6);
        goto LAB_10005f32;
      }
LAB_10005ee1:
      *(undefined1 *)(piVar5 + 8) = 0;
    }
  }
  else {
    if ((char)piVar5[8] == '\0') {
      *(undefined1 *)(piVar5 + 8) = 1;
      *(undefined1 *)(piVar6 + 8) = 0;
      FUN_100023d7(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x21) == '\0') {
      if ((*(char *)(piVar5[2] + 0x20) == '\x01') && (*(char *)(*piVar5 + 0x20) == '\x01'))
      goto LAB_10005ee1;
      if (*(char *)(*piVar5 + 0x20) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x20) = 1;
        *(undefined1 *)(piVar5 + 8) = 0;
        FUN_10002392(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 8) = (char)piVar6[8];
      *(undefined1 *)(piVar6 + 8) = 1;
      *(undefined1 *)(*piVar5 + 0x20) = 1;
      FUN_100023d7(this,piVar6);
LAB_10005f32:
      *(undefined1 *)(piVar7 + 8) = 1;
      goto LAB_10005f36;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_10005eea;
}



// Function: FUN_10005f6c at 10005f6c

void __thiscall FUN_10005f6c(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x21);
  while (cVar1 == '\0') {
    FUN_10005f6c(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10005cf1((int)this + 0xd,(int)(param_1 + 3));
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}



// Function: FUN_10005fb0 at 10005fb0

void __fastcall FUN_10005fb0(void *param_1)

{
  FUN_10005f6c(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10005fd7 at 10005fd7

void __thiscall FUN_10005fd7(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10005fb0(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_10001add((int *)&param_2);
      FUN_10005d0f(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000602a at 1000602a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000602a(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10005fd7(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_10006064 at 10006064

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006064(void *param_1)

{
  FUN_1000602a(param_1);
  return;
}



// Function: FUN_10006082 at 10006082

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10006082(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000608e;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_100028a1(param_1);
  return local_18;
}



// Function: FUN_100060ae at 100060ae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100060ae(undefined4 *param_1)

{
  undefined1 auStack_44 [20];
  undefined4 uStack_30;
  
  *param_1 = 0;
  param_1[1] = 0;
  uStack_30 = 0x100060da;
  FUN_10003a2b(param_1 + 2,L"");
  FUN_100049c7(auStack_44,L"CXMLResourceDocument_READ");
  FUN_10001444(param_1 + 3);
  param_1[0x11] = 0;
  param_1[0x12] = 1;
  uStack_30 = 0x10006114;
  FUN_10003a2b(param_1 + 0x13,L"");
  uStack_30 = 0x10006121;
  FUN_10003a2b(param_1 + 0x14,L"");
  uStack_30 = 0x1000612e;
  FUN_10003a2b(param_1 + 0x15,L"");
  param_1[0x16] = 0;
  FUN_10006082((int)(param_1 + 0x17));
  return param_1;
}



// Function: FUN_1000614a at 1000614a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000614a(int *param_1)

{
  int *piVar1;
  
  FUN_1000602a(param_1 + 0x17);
  FUN_10002015(param_1 + 0x15);
  FUN_10002015(param_1 + 0x14);
  FUN_10002015(param_1 + 0x13);
  FUN_100012d7(param_1 + 3);
  FUN_10002015(param_1 + 2);
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100061c3 at 100061c3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_100061c3(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_100060ae((undefined4 *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  return param_1;
}



// Function: _InlineIsEqualGUID at 1000623e

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



// Function: FUN_1000626e at 1000626e

bool __cdecl FUN_1000626e(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 10006288

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



// Function: AtlCoTaskMemCAlloc at 100062aa

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



// Function: FUN_100062d7 at 100062d7

LPVOID __cdecl FUN_100062d7(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10006307 at 10006307

bool __cdecl FUN_10006307(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_10006334 at 10006334

void __cdecl FUN_10006334(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 10006351

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



// Function: FUN_1000637a at 1000637a

void __fastcall FUN_1000637a(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_1000638c at 1000638c

DWORD FUN_1000638c(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_100063a1 at 100063a1

uint __cdecl FUN_100063a1(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FID_conflict:RegCreateKeyExW at 100063b7

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
                    /* WARNING: Could not recover jumptable at 0x1000640c. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 1000641a

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
                    /* WARNING: Could not recover jumptable at 0x1000645d. Too many branches */
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



// Function: FUN_1000646c at 1000646c

undefined4 __fastcall FUN_1000646c(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10006470 at 10006470

void __cdecl FUN_10006470(short *param_1,int param_2,short *param_3)

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



// Function: FUN_100064be at 100064be

int __fastcall FUN_100064be(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 100064d5

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10016878 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10016874 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10016878 = '\x01';
    }
    if (DAT_10016874 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10016874)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Create at 10006545

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



// Function: SetStringValue at 100065ad

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



// Function: FUN_100065e4 at 100065e4

LSTATUS __thiscall FUN_100065e4(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10006627 at 10006627

undefined4 __fastcall FUN_10006627(undefined4 *param_1)

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



// Function: FUN_10006647 at 10006647

undefined4 * __thiscall FUN_10006647(void *this,ulong param_1)

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



// Function: FUN_1000667d at 1000667d

void __fastcall FUN_1000667d(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10006687 at 10006687

undefined4 __thiscall FUN_10006687(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_100062d7(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10001534((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10006715 at 10006715

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10006715(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x10006721;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_1001689c & 1) == 0) {
    DAT_1001689c = DAT_1001689c | 1;
    DAT_10016880 = 8;
    _DAT_10016888 = 0x4008;
    _DAT_10016890 = 0x13;
    DAT_1001687c = &DAT_1000f498;
    DAT_10016884 = &DAT_1000f494;
    _DAT_1001688c = &DAT_1000f490;
    _DAT_10016894 = &DAT_1000f48c;
    _DAT_10016898 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_1001687c)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x10006798;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_10016880)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_100067a4;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_100067a4:
  *(undefined4 *)(puVar4 + -4) = 0x100067a9;
  return uVar2;
}



// Function: FUN_100067bd at 100067bd

int __cdecl FUN_100067bd(ushort param_1)

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



// Function: FUN_100067f3 at 100067f3

undefined4 __cdecl FUN_100067f3(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10010898)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1001089c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10006821 at 10006821

LPCWSTR __cdecl FUN_10006821(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_1000684e at 1000684e

undefined4 FUN_1000684e(ushort param_1)

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



// Function: FUN_10006874 at 10006874

void __fastcall FUN_10006874(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_1000684e(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_10006896 at 10006896

undefined4 __thiscall FUN_10006896(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10006874((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10006627((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_1000684e(*pWVar2);
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



// Function: FUN_100069ac at 100069ac

undefined4 FUN_100069ac(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1000f79c;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1000f7cc);
  return 1;
}



// Function: FUN_100069db at 100069db

bool FUN_100069db(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10006a10 at 10006a10

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006a10(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10006896(this,param_1), -1 < iVar1)) {
    FUN_10006874((undefined4 *)this);
    iVar1 = FUN_10006896(this,local_2008);
    if (-1 < iVar1) {
      FUN_10006896(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006a75 at 10006a75

undefined4 FUN_10006a75(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10016828;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10006a94 at 10006a94

undefined4 __thiscall FUN_10006a94(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10016830 = *param_3;
    DAT_10016834 = param_3[1];
    DAT_10016838 = param_3[2];
    DAT_1001683c = param_3[3];
  }
  piVar2 = DAT_10016b68;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10016b68, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10016b68 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10016b68;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10016b6c; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10006af2 at 10006af2

void FUN_10006af2(int param_1)

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



// Function: DllCanUnloadNow at 10006b38

HRESULT DllCanUnloadNow(void)

{
                    /* 0x6b38  1  DllCanUnloadNow */
  return (uint)(DAT_100168a8 != 0);
}



// Function: FUN_10006b47 at 10006b47

void __fastcall FUN_10006b47(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10006b5c at 10006b5c

void __fastcall FUN_10006b5c(undefined4 *param_1)

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



// Function: FUN_10006b89 at 10006b89

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10006b89(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10006bb7 at 10006bb7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10006bb7(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_1000d0f2;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10006be1 at 10006be1

int __thiscall FUN_10006be1(void *this,undefined4 *param_1)

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



// Function: FUN_10006c18 at 10006c18

void __fastcall FUN_10006c18(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10006c22 at 10006c22

void __thiscall FUN_10006c22(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_100014e4(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10006c47

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_100014e4(lVar1);
  }
  return local_8;
}



// Function: FUN_10006c6c at 10006c6c

void FUN_10006c6c(void)

{
  return;
}



// Function: FUN_10006c6d at 10006c6d

int __fastcall FUN_10006c6d(int param_1)

{
  long lVar1;
  
  FUN_100064be(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1001682c = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10016864 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10006cae at 10006cae

void __fastcall FUN_10006cae(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10006af2((int)piVar1);
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



// Function: FUN_10006ce7 at 10006ce7

void __fastcall FUN_10006ce7(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10006af2((int)piVar1);
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



// Function: FUN_10006cec at 10006cec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006cec(int param_1)

{
  FUN_10006cae(param_1);
  return;
}



// Function: FUN_10006d0a at 10006d0a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10006d0a(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10006d0a(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_1000ba99();
  return;
}



// Function: FUN_10006def at 10006def

undefined4 __fastcall FUN_10006def(int *param_1)

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
LAB_10006e34:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_10006e34;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10006b5c(param_1);
  return 0;
}



// Function: FUN_10006e46 at 10006e46

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10006e46(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_10006687(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10001a76(local_14);
  }
  return uVar1;
}



// Function: FUN_10006e8d at 10006e8d

void FUN_10006e8d(int param_1)

{
  FUN_10006def((int *)(param_1 + 4));
  return;
}



// Function: FUN_10006e9f at 10006e9f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10006e9f(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x10006eae;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_10007079;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000638c();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_10006f0c;
      FUN_10006334(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_10007049;
      }
    }
    else {
LAB_10007049:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_10006f0c:
  local_8 = 0xffffffff;
  FUN_10001a76(&local_248);
LAB_10007079:
  FUN_1000ba99();
  return;
}



// Function: FUN_10007081 at 10007081

void __fastcall FUN_10007081(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10016b68;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10016b68, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10016b6c; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10006cae(param_1);
  return;
}



// Function: FUN_100070d3 at 100070d3

undefined4 FUN_100070d3(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10006a94(&DAT_100168a0,(int *)&PTR_DAT_10016180,param_1,(undefined4 *)&DAT_10010814);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10007081(0x100168a0);
  }
  return 1;
}



// Function: FUN_10007115 at 10007115

void __fastcall FUN_10007115(undefined4 *param_1)

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



// Function: FUN_1000711a at 1000711a

void __fastcall FUN_1000711a(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000712a at 1000712a

void __fastcall FUN_1000712a(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10006c18(param_1);
    return;
  }
  return;
}



// Function: FUN_10007137 at 10007137

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007137(int param_1)

{
  FUN_10006bb7((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10007158 at 10007158

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10007158(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_100071ac at 100071ac

void __fastcall FUN_100071ac(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100071c3 at 100071c3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_100071c3(undefined4 *param_1)

{
  FUN_10006c6d((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10016870 = param_1;
  return param_1;
}



// Function: FUN_100071f8 at 100071f8

void __fastcall FUN_100071f8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10007203 at 10007203

void __fastcall FUN_10007203(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000720e at 1000720e

HRESULT __thiscall FUN_1000720e(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_10010f20,(LPUNKNOWN)0x0,1,(IID *)&DAT_10010a88,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_1000725a at 1000725a

undefined4 FUN_1000725a(void)

{
  return 0x80004005;
}



// Function: FUN_10007262 at 10007262

void FUN_10007262(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_1000f510);
  return;
}



// Function: FUN_1000727c at 1000727c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000727c(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10006cae((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100072b3 at 100072b3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100072b3(int *param_1)

{
  FUN_10006def(param_1);
  FUN_10006b5c(param_1);
  return;
}



// Function: FUN_100072dd at 100072dd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100072dd(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_10006def(param_1 + 1);
  FUN_100072b3(param_1 + 1);
  return;
}



// Function: FUN_10007311 at 10007311

undefined4 FUN_10007311(void)

{
  return 0x80004001;
}



// Function: FUN_10007319 at 10007319

undefined4 FUN_10007319(void)

{
  return 1;
}



// Function: FUN_1000731f at 1000731f

undefined4 FUN_1000731f(void)

{
  return 0;
}



// Function: FUN_10007324 at 10007324

undefined4 * __thiscall FUN_10007324(void *this,byte param_1)

{
  FUN_100072dd((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007343 at 10007343

undefined4 __fastcall FUN_10007343(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10006be1((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10007384 at 10007384

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10007384(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10007390;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10006647(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10006a75(&local_5d);
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
LAB_10007479:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_100074ed;
                }
                iVar3 = FUN_10006627((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_10006687(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_10007513;
                  goto LAB_100074b5;
                }
                local_55 = '\0';
              }
              else {
LAB_100074b5:
                if (local_55 != '\0') goto LAB_100074ed;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_10006e46(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_10007513;
                local_56 = '\0';
              }
              goto LAB_100074ed;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_10006e46(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_10007479;
            }
LAB_10007513:
            local_5c = -0x7ff8fff2;
            goto LAB_100073f4;
          }
LAB_100074ed:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_10006821(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_100073f4;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_10007343(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_10006e46(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_10007513;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_10007586;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_100073f4;
            }
            iVar3 = FUN_10006687(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_10007513;
          }
          else {
            iVar3 = FUN_10006687(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_10007586:
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
LAB_100073f4:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_1000ba99();
  return;
}



// Function: FUN_100075f1 at 100075f1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100075f1(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_10010f10), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_10010f30,(LPUNKNOWN)0x0,1,(IID *)&DAT_10010b84,&local_1a8
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
          goto LAB_1000787c;
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
      FUN_10001a76(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_1000787c:
  FUN_1000ba99();
  return;
}



// Function: FUN_1000790f at 1000790f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000790f(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_10006e9f(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10006a75((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_100079df at 100079df

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100079df(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_10006e9f(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_10006a75(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10007ba1;
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
LAB_10007ba1:
  FUN_1000ba99();
  return;
}



// Function: FUN_10007ba9 at 10007ba9

int FUN_10007ba9(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000626e(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_100075f1((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_100079df(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10007c2f at 10007c2f

int FUN_10007c2f(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000626e(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_100075f1((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_1000790f(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10007cb6 at 10007cb6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10007cb6(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_1000f834,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_10007d71;
          }
          else {
LAB_10007d71:
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



// Function: FUN_10007da1 at 10007da1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007da1(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10006bb7((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: InlineIsEqualUnknown at 10007dd2

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



// Function: FUN_10007e00 at 10007e00

undefined4 FUN_10007e00(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10007e3e at 10007e3e

undefined4 FUN_10007e3e(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1001682c + 8))();
  }
  else {
    (**(code **)(*DAT_1001682c + 4))();
  }
  return 0;
}



// Function: FUN_10007e5d at 10007e5d

undefined4 * __thiscall FUN_10007e5d(void *this,byte param_1)

{
  FUN_10007da1((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007e7c at 10007e7c

undefined4 __thiscall FUN_10007e7c(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10007158(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 10007ed3

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
    FUN_10006c22(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10007f02

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
    FUN_10006c22(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10007f31

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
    FUN_10006c22(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10007f60 at 10007f60

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10007f60(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10006b89(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_10007f9b at 10007f9b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007f9b(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1000b8f8(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10008001();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10007ff5 at 10007ff5

undefined * Catch_10007ff5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007fff;
}



// Function: FUN_10008001 at 10008001

void FUN_10008001(void)

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
  uVar4 = FUN_1000b8f8(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10008052();
  return;
}



// Function: Catch@10008043 at 10008043

undefined * Catch_10008043(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10008050;
}



// Function: FUN_10008052 at 10008052

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10008052(void)

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
    FUN_10001534(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10001534(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_10007e7c(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_100080ae;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_100080ae:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_100080e6 at 100080e6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100080e6(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_10007f9b(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10001a76(local_14);
  }
  return iVar1;
}



// Function: FUN_10008141 at 10008141

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10008141(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1000d4e6;
  local_10 = ExceptionList;
  uStack_2144 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_10006896(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10006715(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_100084ba;
  FUN_10006874((undefined4 *)this);
  iVar1 = FUN_10006896(this,local_2018);
  if (iVar1 < 0) goto LAB_100084ba;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_10008496:
    if (uVar2 != 0) {
      FUN_100063a1(uVar2);
      goto LAB_100084ba;
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
        FUN_100083c9();
        return;
      }
      goto LAB_100084ba;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10001a76((int *)&local_2124);
      goto LAB_10008496;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10008262();
      return;
    }
  }
  FUN_10006896(this,param_3);
LAB_100084ba:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10008256 at 10008256

undefined * Catch_10008256(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10008260;
}



// Function: FUN_10008262 at 10008262

void FUN_10008262(void)

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
    pWVar2 = (WCHAR *)FUN_100065e4(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10006c18((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_10006896(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_100063a1((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100084d2;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100083ae at 100083ae

undefined * Catch_100083ae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_100083bb;
}



// Function: FUN_100083c9 at 100083c9

void FUN_100083c9(void)

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
      FUN_10006c18((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_100067bd(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10006c18((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_10006896(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_100063a1(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100084d2;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100084d6 at 100084d6

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100084d6(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_1000d545;
  local_10 = ExceptionList;
  local_14 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_1000853a:
  iVar3 = FUN_10006896(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_1000854a:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_100089a7:
    if (*param_1 == L'}') goto LAB_1000854a;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_10006896(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000854a;
      if (param_3 == 0) goto LAB_10008689;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_10006821(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_100069ac(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10006d0a(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_10008689;
        }
        iVar3 = FUN_10006896(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10006a10(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_10008aa6;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_10008b25;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_1000854a;
    }
LAB_10008689:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_10006896(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000854a;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10006821(param_1,L'\\');
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
          iVar3 = FUN_10006896(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10006a10(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_100084d6(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_10006896(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_10008b44;
          iVar3 = FUN_10006896(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10008141(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_10008aab;
        }
      }
      goto LAB_1000854a;
    }
    iVar3 = FUN_10006896(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_10006896(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_1000854a;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10008141(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_10008aa6;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_10008b25;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_100063a1(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_10008b25:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_1000854a;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10006a10(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_100069db(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_100069ac(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10006d0a(&local_2234,local_21c);
        }
        goto LAB_100089a7;
      }
      bVar2 = FUN_100069db(local_2234);
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
            FUN_100063a1(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_10008b25;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_10008aa6:
          ATL::CRegKey::Close(pCVar8);
LAB_10008aab:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_100084d6(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_1000853a;
            goto LAB_1000854a;
          }
        }
        goto LAB_100089a7;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_100089a7;
    }
LAB_10008b44:
    FUN_100063a1(uVar6);
    goto LAB_1000854a;
  }
  goto LAB_100089a7;
}



// Function: FUN_10008b6d at 10008b6d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10008b6d(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10016b70);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_1000f834,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10016b70);
          if (*piVar2 != 0) goto LAB_10008c01;
        }
        else {
LAB_10008c01:
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
  piVar2 = FUN_10007cb6((int *)&DAT_10016b60,param_1,param_2,param_3);
  return piVar2;
}



// Function: DllGetClassObject at 10008c39

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x8c39  2  DllGetClassObject */
  piVar1 = FUN_10008b6d(&DAT_100168a0,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_10008c47 at 10008c47

void FUN_10008c47(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10007ba9(0x10016b60,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10016868 != (code *)0x0)) {
    (*DAT_10016868)(DAT_10016b2c);
  }
  return;
}



// Function: FUN_10008c75 at 10008c75

void FUN_10008c75(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_1001686c != (code *)0x0) && (iVar1 = (*DAT_1001686c)(), iVar1 < 0)) {
    return;
  }
  FUN_10007c2f(0x10016b60,param_1,param_2);
  return;
}



// Function: FUN_10008c9b at 10008c9b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10008c9b(undefined4 *param_1)

{
  FUN_10007f60(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: AtlInternalQueryInterface at 10008cc9

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
          if (pcVar1 == (code *)0x1) goto LAB_10008cfd;
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
LAB_10008cfd:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10008d6a at 10008d6a

LONG FUN_10008d6a(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1001682c + 4))();
  }
  return LVar1;
}



// Function: FUN_10008d94 at 10008d94

LONG FUN_10008d94(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1001682c + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 10008dd3

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10010c1c,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10008ded at 10008ded

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008ded(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10007da1(param_1);
  return;
}



// Function: FUN_10008e1c at 10008e1c

undefined4 * __thiscall FUN_10008e1c(void *this,byte param_1)

{
  FUN_10008ded((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008e3b at 10008e3b

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10008e3b(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10007384(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_10008f31:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10008e86:
  if ((((sVar1 == 0) || (iVar3 = FUN_10006896(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_100067f3(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_10006896(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_10008f23;
  if (param_2 == 0) {
    iVar3 = FUN_100084d6(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_10008f23;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_100084d6(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_100084d6(this,local_2008,pHVar4,0,0);
LAB_10008f23:
      CoTaskMemFree(local_200c);
      goto LAB_10008f31;
    }
  }
  FUN_10006874((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10008e86;
}



// Function: FUN_10008f72 at 10008f72

int __thiscall FUN_10008f72(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000626e(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_100075f1((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_10008c47(param_1,param_2);
  return iVar5;
}



// Function: FUN_10008fe1 at 10008fe1

int __thiscall FUN_10008fe1(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000626e(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_100075f1((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_10008c75(param_1,param_2);
  return iVar5;
}



// Function: DllRegisterServer at 10009050

int DllRegisterServer(void)

{
  int iVar1;
  
                    /* 0x9050  3  DllRegisterServer */
  FUN_10008f72(&DAT_100168a0,1,(void *)0x0);
  iVar1 = FUN_1000a353(0x7dd95801,0x11cf9882,0xaa00a99f,0xc4426c00,
                       L"Con1trols that are safely scriptable");
  if (-1 < iVar1) {
    FUN_1000a40b(&DAT_10010824,0x7dd95801,0x11cf9882,0xaa00a99f,0xc4426c00);
  }
  return iVar1;
}



// Function: DllUnregisterServer at 100090a9

void DllUnregisterServer(void)

{
                    /* 0x90a9  4  DllUnregisterServer */
  FUN_10008fe1(&DAT_100168a0,1,(void *)0x0);
  return;
}



// Function: Catch@10009116 at 10009116

undefined1 * Catch_10009116(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10009120;
}



// Function: FUN_10009168 at 10009168

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009168(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_1000638c();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_1000638c();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_10009242();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10006c18(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10001a76(&local_42c);
  FUN_1000baa8();
  return;
}



// Function: Catch@1000922d at 1000922d

undefined * Catch_1000922d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000923a;
}



// Function: FUN_10009242 at 10009242

void FUN_10009242(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000638c();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10008e3b((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10006c18((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001a76((int *)(unaff_EBP + -0x428));
  FUN_1000baa8();
  return;
}



// Function: FUN_100092cc at 100092cc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100092cc(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10009168(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001a76(local_14);
  return uVar1;
}



// Function: FUN_1000930d at 1000930d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000930d(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001a76(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10009168(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001a76(local_14);
  }
  return uVar1;
}



// Function: FUN_10009369 at 10009369

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009369(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10009168(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001a76(local_14);
  return uVar1;
}



// Function: FUN_100093a9 at 100093a9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100093a9(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001a76(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10009168(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001a76(local_14);
  }
  return uVar1;
}



// Function: FUN_10009404 at 10009404

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009404(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_100080e6(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_10016b2c;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10016b2c,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000638c();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001a76((int *)&local_a48);
        goto LAB_10009486;
      }
      FUN_10006470(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10006307(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001a76((int *)&local_a48);
          goto LAB_10009486;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_100080e6(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_100080e6(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_100093a9(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_1000930d(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001a76((int *)&local_a48);
  }
LAB_10009486:
  local_8 = 0xffffffff;
  FUN_100072dd(&local_a60);
  FUN_1000ba99();
  return;
}



// Function: FUN_10009607 at 10009607

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009607(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_100080e6(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_10016b2c;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10016b2c,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000638c();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001a76((int *)&local_a48);
        goto LAB_10009680;
      }
      FUN_10006470(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10006307(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001a76((int *)&local_a48);
          goto LAB_10009680;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_100080e6(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_100080e6(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10009369(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_100092cc(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001a76((int *)&local_a48);
  }
LAB_10009680:
  local_8 = 0xffffffff;
  FUN_100072dd(&local_a5c);
  FUN_1000ba99();
  return;
}



// Function: FUN_100097fe at 100097fe

void FUN_100097fe(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_10009404(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10009807 at 10009807

void FUN_10009807(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10009607(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10009810 at 10009810

void FUN_10009810(int param_1)

{
  FUN_10009607((int *)&DAT_100168a0,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10009828 at 10009828

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009828(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x90);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x88);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x84);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x80);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000614a((int *)(param_1 + 0x14));
  Ordinal_6(*(undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_100098ec at 100098ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100098ec(int param_1)

{
  FUN_10009828(param_1);
  return;
}



// Function: FUN_1000990a at 1000990a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000990a(void *this,undefined4 param_1)

{
  FUN_100061c3((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CATCon>::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  return (undefined4 *)this;
}



// Function: Attach at 1000993e

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



// Function: FUN_10009986 at 10009986

undefined4 FUN_10009986(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_100099a3 at 100099a3

void __fastcall FUN_100099a3(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100099b0 at 100099b0

void FUN_100099b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 4))(*(int **)(param_1 + 4));
  return;
}



// Function: FUN_100099c3 at 100099c3

void FUN_100099c3(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4));
  return;
}



// Function: FUN_100099d6 at 100099d6

void FUN_100099d6(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4),param_2,param_3);
  return;
}



// Function: FUN_100099ee at 100099ee

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100099ee(void *this,wchar_t *param_1)

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
  local_8 = 0x100099fa;
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
      local_18 = (uint *)FUN_1000b8f8(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_1000995d,
                   (_func_void_void_ptr *)&LAB_100018fe);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_10009a9e();
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



// Function: Catch@10009a8e at 10009a8e

undefined * Catch_10009a8e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009a98;
}



// Function: FUN_10009a9e at 10009a9e

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009a9e(void)

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



// Function: FUN_10009b56 at 10009b56

void FUN_10009b56(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_100021e7(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10009b89 at 10009b89

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009b89(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_10009bce();
  return uVar1;
}



// Function: Catch@10009bbe at 10009bbe

undefined * Catch_10009bbe(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009bc8;
}



// Function: FUN_10009bce at 10009bce

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009bce(void)

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



// Function: FUN_10009c29 at 10009c29

IUnknown * __thiscall FUN_10009c29(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_100024aa(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_10010d20);
  }
  return pIVar2;
}



// Function: FUN_10009c56 at 10009c56

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10009c56(void *this,undefined4 param_1)

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
  local_8 = 0x10009c65;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10009e9b;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1001682c + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_10016830,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_10016b2c,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10009e65;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001a76((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_10010d10,&local_224);
        if (-1 < iVar2) {
          FUN_10009c29(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_1001682c == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_1001682c + 4;
        }
        pcVar4 = FUN_10009b56;
        pvVar5 = this;
        FUN_10009b89(iVar2);
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
LAB_10009e65:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_100099ee(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10009e9b:
  FUN_1000ba99();
  return;
}



// Function: FUN_10009ea3 at 10009ea3

undefined4 __thiscall FUN_10009ea3(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10009c56(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10009ee3 at 10009ee3

undefined4 __thiscall
FUN_10009ee3(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10009c56(this,param_4);
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



// Function: FUN_10009f84 at 10009f84

void __thiscall
FUN_10009f84(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10009c56(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10009fc7 at 10009fc7

undefined4 FUN_10009fc7(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10009ea3(&PTR_DAT_10016538,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10009feb at 10009feb

void FUN_10009feb(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10009ee3(&PTR_DAT_10016538,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000a00b at 1000a00b

void FUN_1000a00b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10009f84(&PTR_DAT_10016538,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000a019 at 1000a019

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000a019(undefined4 *param_1)

{
  FUN_100061c3((int)param_1);
  *param_1 = ATL::CComObject<class_CATCon>::vftable;
  (**(code **)(*DAT_1001682c + 4))();
  return param_1;
}



// Function: FUN_1000a052 at 1000a052

undefined4 FUN_1000a052(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: Release at 1000a062

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
    (**(code **)(*in_stack_00000004 + 0x3c))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 1000a083

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10010d74,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000a09d at 1000a09d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a09d(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CATCon>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1001682c + 8))();
  FUN_10009828((int)param_1);
  return;
}



// Function: FUN_1000a0db at 1000a0db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000a0db(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CATCon>::vftable;
  FUN_1000990a((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1001682c + 4))();
  return (undefined4 *)this;
}



// Function: Release at 1000a11e

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



// Function: FUN_1000a13f at 1000a13f

long FUN_1000a13f(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10010d74,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000a18b at 1000a18b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a18b(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CATCon>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1001682c + 8))();
  FUN_10009828((int)(param_1 + 2));
  return;
}



// Function: FUN_1000a1d1 at 1000a1d1

undefined4 * __thiscall FUN_1000a1d1(void *this,byte param_1)

{
  FUN_1000a09d((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a1f0 at 1000a1f0

undefined4 * __thiscall FUN_1000a1f0(void *this,byte param_1)

{
  FUN_1000a18b((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a20f at 1000a20f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a20f(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x94);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000a019(puVar1);
    }
    uVar2 = FUN_1000a26f();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000a262 at 1000a262

undefined * Catch_1000a262(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a26c;
}



// Function: FUN_1000a26f at 1000a26f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a26f(void)

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
      (**(code **)(*unaff_ESI + 0x3c))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000a29f at 1000a29f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a29f(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x9c);
    if (this != (void *)0x0) {
      FUN_1000a0db(this,param_1);
    }
    uVar1 = FUN_1000a309();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000a2fc at 1000a2fc

undefined * Catch_1000a2fc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a306;
}



// Function: FUN_1000a309 at 1000a309

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a309(void)

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



// Function: FUN_1000a333 at 1000a333

void FUN_1000a333(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000a20f(0,param_2,param_3);
    return;
  }
  FUN_1000a29f(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000a353 at 1000a353

void __cdecl
FUN_1000a353(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            wchar_t *param_5)

{
  HRESULT HVar1;
  size_t _Count;
  int *local_120;
  undefined4 local_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 local_10c;
  wchar_t local_108 [128];
  uint local_8;
  
  local_8 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  local_120 = (int *)0x0;
  HVar1 = CoCreateInstance((IID *)&DAT_10010f30,(LPUNKNOWN)0x0,1,(IID *)&DAT_10010b84,&local_120);
  if (-1 < HVar1) {
    local_11c = param_1;
    uStack_118 = param_2;
    uStack_114 = param_3;
    uStack_110 = param_4;
    local_10c = 0x409;
    _Count = wcslen(param_5);
    if (0x7f < (int)_Count) {
      _Count = 0x7f;
    }
    wcsncpy(local_108,param_5,_Count);
    local_108[_Count] = L'\0';
    (**(code **)(*local_120 + 0xc))(local_120,1,&local_11c);
    (**(code **)(*local_120 + 8))(local_120);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a40b at 1000a40b

void __cdecl
FUN_1000a40b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  HRESULT HVar1;
  int *local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = DAT_1001680c ^ (uint)&stack0xfffffffc;
  local_1c = (int *)0x0;
  HVar1 = CoCreateInstance((IID *)&DAT_10010f30,(LPUNKNOWN)0x0,1,(IID *)&DAT_10010b84,&local_1c);
  if (-1 < HVar1) {
    local_18 = param_2;
    uStack_14 = param_3;
    uStack_10 = param_4;
    uStack_c = param_5;
    (**(code **)(*local_1c + 0x14))(local_1c,param_1,1,&local_18);
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a47d at 1000a47d

void __fastcall FUN_1000a47d(undefined4 *param_1)

{
  *param_1 = CGenericException::vftable;
  return;
}



// Function: FUN_1000a484 at 1000a484

undefined4 * __thiscall FUN_1000a484(void *this,byte param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a4a4 at 1000a4a4

void __thiscall FUN_1000a4a4(void *this,int param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return;
}



// Function: AtlW2AHelper at 1000a4c8

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



// Function: FUN_1000a500 at 1000a500

void __cdecl FUN_1000a500(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_1000a521 at 1000a521

undefined4 __thiscall FUN_1000a521(void *this,int *param_1)

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



// Function: FUN_1000a548 at 1000a548

uint FUN_1000a548(byte param_1)

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



// Function: _Inside at 1000a574

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



// Function: FUN_1000a5af at 1000a5af

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a5af(undefined4 *param_1)

{
  *param_1 = CGenericExceptionEx::vftable;
  Ordinal_6(param_1[4]);
  *param_1 = CGenericException::vftable;
  return;
}



// Function: FUN_1000a5e3 at 1000a5e3

undefined4 * __thiscall FUN_1000a5e3(void *this,byte param_1)

{
  FUN_1000a5af((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a602 at 1000a602

undefined4 __fastcall FUN_1000a602(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[1] = 0;
    return 0;
  }
  return 0x80004003;
}



// Function: FUN_1000a623 at 1000a623

void __fastcall FUN_1000a623(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  
  if (((byte)param_1[0x40] & 1) != 0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
    if (pcVar1 == (char *)0x0) {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
    }
    else {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(param_1);
    }
    std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    operator_delete(pcVar1);
  }
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
            (param_1,(char *)0x0,(char *)0x0,(char *)0x0);
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setp(param_1,(char *)0x0,(char *)0x0);
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}



// Function: FUN_1000a67f at 1000a67f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a67f(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 1;
  return;
}



// Function: FUN_1000a6ac at 1000a6ac

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_1000a6ac(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000d9c0;
  if (param_1[1] != 0) {
    puVar2 = (undefined1 *)FUN_1000a602(param_1);
  }
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_1000a6e2 at 1000a6e2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_1000a6e2(void *this,int *param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uStack_28;
  int *piStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar3 = param_1;
  uStack_4 = 0;
  local_8 = 0x1000a6ee;
  puVar5 = (undefined4 *)auStack_20;
  if (param_1 == (int *)0x0) {
    *(undefined4 *)((int)this + 4) = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*this == 0) {
      piStack_24 = param_1;
      puVar4 = &uStack_28;
      uStack_28 = 0x1000a705;
      (**(code **)(*param_1 + 4))();
      local_8 = 1;
      puVar4[-1] = this;
      puVar4[-2] = 0x1000a714;
      FUN_1000a521(&param_1,(int *)puVar4[-1]);
      *(undefined4 *)((int)this + 4) = 1;
      uVar6 = 0;
      local_8 = 0xffffffff;
      iVar1 = *piVar3;
      puVar4[-1] = piVar3;
      pcVar2 = *(code **)(iVar1 + 8);
      puVar5 = puVar4 + -2;
      puVar4[-2] = 0x1000a723;
      (*pcVar2)();
      goto LAB_1000a72e;
    }
  }
  uVar6 = 0x80004003;
LAB_1000a72e:
  *(undefined4 *)((int)puVar5 + -4) = 0x1000a735;
  return uVar6;
}



// Function: FUN_1000a738 at 1000a738

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __cdecl FUN_1000a738(int *param_1,int param_2)

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
  FUN_1000a500(8,(int)local_24,0,0x409);
  if (local_1c == 0) {
    *param_1 = 0;
  }
  else {
    iVar2 = Ordinal_2(local_1c);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      FUN_100014e4(0x8007000e);
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



// Function: FUN_1000a7af at 1000a7af

void __cdecl FUN_1000a7af(char *param_1)

{
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(char **)param_1;
  }
  atol(param_1);
  return;
}



// Function: FUN_1000a7c7 at 1000a7c7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a7c7(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  *(undefined ***)param_1 =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  FUN_1000a623(param_1);
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>(param_1);
  return;
}



// Function: FUN_1000a7f9 at 1000a7f9

uint __fastcall FUN_1000a7f9(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  byte *pbVar4;
  uint uVar5;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
  pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar2 < pcVar1) {
LAB_1000a88c:
    pbVar4 = (byte *)std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
    uVar5 = (uint)*pbVar4;
  }
  else {
    if (((byte)param_1[0x40] & 4) == 0) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
      if (pcVar1 != (char *)0x0) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
        if (pcVar1 <= pcVar2) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
          if (*(char **)(param_1 + 0x3c) <= pcVar1) goto LAB_1000a899;
        }
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
        if (*(char **)(param_1 + 0x3c) < pcVar1) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
          *(char **)(param_1 + 0x3c) = pcVar1;
        }
        pcVar1 = *(char **)(param_1 + 0x3c);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
        std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                  (param_1,pcVar3,pcVar2,pcVar1);
        goto LAB_1000a88c;
      }
    }
LAB_1000a899:
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



// Function: FUN_1000a89f at 1000a89f

void __thiscall
FUN_1000a89f(void *this,uint *param_1,uint param_2,uint param_3,int param_4,byte param_5)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((pcVar1 != (char *)0x0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     *(char **)((int)this + 0x3c) < pcVar1)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    *(char **)((int)this + 0x3c) = pcVar1;
  }
  if (((param_5 & 1) == 0) ||
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 == (char *)0x0)) {
    if (((param_5 & 2) == 0) ||
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       pcVar1 == (char *)0x0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_1000aaa5;
    }
    else {
      if (param_4 == 2) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
LAB_1000aa22:
        bVar6 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + ((int)uVar4 >> 0x1f) + (uint)bVar6;
      }
      else {
        if (param_4 == 1) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          uVar4 = (int)pcVar2 - (int)pcVar1;
          goto LAB_1000aa22;
        }
        if (param_4 != 0) {
          param_2 = *(uint *)_BADOFF_exref;
          param_3 = *(uint *)(_BADOFF_exref + 4);
        }
      }
      if (-1 < (int)param_3) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        iVar5 = (int)uVar4 >> 0x1f;
        if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= uVar4)))) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::pbump
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                     (int)(pcVar2 + (param_2 - (int)pcVar1)));
          goto LAB_1000aaa5;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
LAB_1000a91a:
      bVar6 = CARRY4(param_2,uVar4);
      param_2 = param_2 + uVar4;
      param_3 = param_3 + ((int)uVar4 >> 0x1f) + (uint)bVar6;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = (int)pcVar2 - (int)pcVar1;
        goto LAB_1000a91a;
      }
LAB_1000a92d:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    else if (param_4 != 0) goto LAB_1000a92d;
    if (-1 < (int)param_3) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
      iVar5 = (int)uVar4 >> 0x1f;
      if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= uVar4)))) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                  ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                   (int)(pcVar2 + (param_2 - (int)pcVar1)));
        if (((param_5 & 2) != 0) &&
           (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
           pcVar1 != (char *)0x0)) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar2,
                     pcVar1);
        }
        goto LAB_1000aaa5;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_1000aaa5:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_1000aabf at 1000aabf

void __thiscall FUN_1000aabf(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint in_stack_00000020;
  
  uVar7 = param_4 + param_2;
  uVar6 = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((pcVar1 != (char *)0x0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     *(char **)((int)this + 0x3c) < pcVar1)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    *(char **)((int)this + 0x3c) = pcVar1;
  }
  if ((uVar7 != *(uint *)_BADOFF_exref) || (uVar6 != *(uint *)(_BADOFF_exref + 4))) {
    if (((in_stack_00000020 & 1) == 0) ||
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       pcVar1 == (char *)0x0)) {
      if ((((in_stack_00000020 & 2) != 0) &&
          (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
          pcVar1 != (char *)0x0)) && (-1 < (int)uVar6)) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        iVar5 = (int)uVar4 >> 0x1f;
        if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar7 <= uVar4)))) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::pbump
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                     (int)(pcVar2 + (uVar7 - (int)pcVar1)));
          goto LAB_1000ac22;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
      iVar5 = (int)uVar4 >> 0x1f;
      if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar7 <= uVar4)))) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                  ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                   (int)(pcVar2 + (uVar7 - (int)pcVar1)));
        if (((in_stack_00000020 & 2) != 0) &&
           (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
           pcVar1 != (char *)0x0)) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar2,
                     pcVar1);
        }
        goto LAB_1000ac22;
      }
    }
    uVar7 = *(uint *)_BADOFF_exref;
    uVar6 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_1000ac22:
  *param_1 = uVar7;
  param_1[1] = uVar6;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_1000ac3c at 1000ac3c

int __thiscall FUN_1000ac3c(void *this,int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  uint local_8;
  
  if ((((*(byte *)((int)this + 0x40) & 8) != 0) &&
      (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                          ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
      pcVar1 != (char *)0x0)) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 < *(char **)((int)this + 0x3c))) {
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar1 = *(char **)((int)this + 0x3c);
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar1,pcVar2);
  }
  if (param_1 == -1) {
    return 0;
  }
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    if (pcVar2 < pcVar1) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      *pcVar1 = (char)param_1;
      return param_1;
    }
  }
  if ((*(byte *)((int)this + 0x40) & 2) != 0) {
    return -1;
  }
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (pcVar1 == (char *)0x0) {
    local_8 = 0;
  }
  else {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    local_8 = (int)pcVar2 - (int)pcVar1;
  }
  uVar7 = local_8 >> 1;
  if (uVar7 < 0x20) {
    uVar7 = 0x20;
  }
  else if (uVar7 == 0) {
    return -1;
  }
  do {
    if (local_8 <= 0x7fffffff - uVar7) break;
    uVar7 = uVar7 >> 1;
  } while (uVar7 != 0);
  if (uVar7 == 0) {
    return -1;
  }
  pcVar1 = (char *)(uVar7 + local_8);
  pcVar2 = (char *)FUN_10001c8a(pcVar1);
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (local_8 == 0) {
    *(char **)((int)this + 0x3c) = pcVar2;
    std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar2,
               pcVar2 + (int)pcVar1);
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      pcVar1 = pcVar2 + 1;
      pcVar5 = pcVar2;
      goto LAB_1000adc6;
    }
  }
  else {
    memcpy(pcVar2,pcVar3,local_8);
    *(int *)((int)this + 0x3c) = (int)(pcVar2 + (*(int *)((int)this + 0x3c) - (int)pcVar3));
    iVar4 = (int)pcVar2 - (int)pcVar3;
    pcVar1 = pcVar2 + (int)pcVar1;
    pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar5 = pcVar5 + iVar4;
    pcVar6 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar6 + iVar4,pcVar5,
               pcVar1);
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      pcVar1 = pcVar1 + 1;
      pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      pcVar5 = pcVar5 + iVar4;
      goto LAB_1000adc6;
    }
  }
  pcVar5 = (char *)0x0;
  pcVar1 = pcVar2;
LAB_1000adc6:
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar2,pcVar5,pcVar1);
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(pcVar3);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  *pcVar1 = (char)param_1;
  return param_1;
}



// Function: FUN_1000adf6 at 1000adf6

int __thiscall FUN_1000adf6(void *this,int param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    if ((pcVar1 < pcVar2) &&
       (((param_1 == -1 ||
         (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
         (char)param_1 == pcVar1[-1])) || ((*(byte *)((int)this + 0x40) & 2) == 0)))) {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,-1);
      if (param_1 != -1) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        *pcVar1 = (char)param_1;
        return param_1;
      }
      return 0;
    }
  }
  return -1;
}



// Function: FUN_1000ae62 at 1000ae62

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_1000ae62(void *this,byte param_1)

{
  FUN_1000a7c7((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_1000ae81 at 1000ae81

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_1000ae81(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)((int)this + 4) = param_3;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  *(undefined ***)this = CGenericExceptionEx::vftable;
  *(undefined4 *)((int)this + 0x10) = 0;
  FUN_10002662((undefined4 *)((int)this + 0x10),(CComBSTR *)&param_4);
  Ordinal_6(param_4);
  return (undefined4 *)this;
}



// Function: FUN_1000aee2 at 1000aee2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000aee2(void *this,int param_1)

{
  *(undefined ***)this = CGenericException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined ***)this = CGenericExceptionEx::vftable;
  ATL::CComBSTR::CComBSTR((CComBSTR *)((int)this + 0x10),(CComBSTR *)(param_1 + 0x10));
  return (undefined4 *)this;
}



// Function: FUN_1000af32 at 1000af32

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000af32(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined1 *puStack00000004;
  undefined1 local_44 [20];
  undefined1 local_30 [24];
  int local_18;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_18 = 0;
  local_8 = 0;
  local_18 = (**(code **)(*(int *)*param_1 + 0x68))();
  if (local_18 < 0) {
    puStack00000004 = &stack0xffffffa0;
    local_8 = local_8 & 0xffffff00;
    puVar1 = FUN_1000ae81(local_44,local_18,0,0,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000aee2(local_30,(int)puVar1);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_30,(ThrowInfo *)&DAT_10013928);
  }
  return local_18;
}



// Function: Catch@1000af9e at 1000af9e

undefined * Catch_1000af9e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000afb1;
}



// Function: Catch@1000afb3 at 1000afb3

undefined4 Catch_1000afb3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000af93;
}



// Function: FUN_1000afbd at 1000afbd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000afbd(void *this,undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 *pExceptionObject;
  undefined1 local_8c [20];
  undefined1 local_78 [20];
  undefined1 local_64 [20];
  undefined1 local_50 [20];
  undefined1 local_3c [24];
  undefined1 *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 5;
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 == (int *)0x0) {
    local_24 = &stack0xffffff60;
    local_8._1_3_ = 0;
    local_8._0_1_ = 5;
    puVar2 = FUN_1000ae81(local_8c,0x80004003,0,0,0);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_1000aee2(local_3c,(int)puVar2);
    pExceptionObject = local_3c;
  }
  else {
    local_18 = (**(code **)(*piVar1 + 0x44))(piVar1);
    if (local_18 < 0) {
      local_24 = &stack0xffffff60;
      local_8._0_1_ = 5;
      puVar2 = FUN_1000ae81(local_8c,local_18,0,0,0);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_1000aee2(local_50,(int)puVar2);
      pExceptionObject = local_50;
    }
    else {
      if (local_20 != (int *)0x0) {
        local_18 = (**(code **)(*local_20 + 0x1c))(local_20,param_1);
        if (local_18 == 0) {
          local_18 = (**(code **)(*local_1c + 0x20))(local_1c);
          if (local_18 < 0) {
            local_24 = &stack0xffffff60;
            local_8._0_1_ = 5;
            puVar2 = FUN_1000ae81(local_8c,local_18,0,0,0);
            local_8 = CONCAT31(local_8._1_3_,0xd);
            FUN_1000aee2(local_78,(int)puVar2);
            pExceptionObject = local_78;
            goto LAB_1000b025;
          }
        }
        else {
          local_18 = -0x7fffbffb;
        }
        local_8._0_1_ = 3;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))();
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))();
        }
        local_8 = 0xffffffff;
        Ordinal_6();
        return local_18;
      }
      local_24 = &stack0xffffff60;
      local_8._0_1_ = 5;
      puVar2 = FUN_1000ae81(local_8c,0x80004003,0,0,0);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      FUN_1000aee2(local_64,(int)puVar2);
      pExceptionObject = local_64;
    }
  }
LAB_1000b025:
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_10013928);
}



// Function: Catch@1000b163 at 1000b163

undefined * Catch_1000b163(void)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  int unaff_EBP;
  
  uVar1 = *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 0xc);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  puVar2 = *(undefined2 **)(unaff_EBP + 0xc);
  *puVar2 = 10;
  *(undefined4 *)(puVar2 + 4) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000b182;
}



// Function: Catch@1000b184 at 1000b184

undefined4 Catch_1000b184(void)

{
  undefined2 *puVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  puVar1 = *(undefined2 **)(unaff_EBP + 0xc);
  *puVar1 = 10;
  *(undefined4 *)(puVar1 + 4) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000b14b;
}



// Function: FUN_1000b1a2 at 1000b1a2

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_1000b1a2(void *this,undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *pExceptionObject;
  undefined4 extraout_ECX;
  undefined4 uVar4;
  undefined1 local_70 [20];
  undefined1 local_5c [20];
  undefined1 local_48 [20];
  short local_34;
  int local_2c;
  undefined1 *local_20;
  int local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_18[0] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  Ordinal_8();
  local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    param_2 = (int *)&stack0xffffff78;
    local_8._0_1_ = 3;
    puVar3 = FUN_1000ae81(local_70,0x80004003,0,0,0);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_1000aee2(local_48,(int)puVar3);
    pExceptionObject = local_48;
LAB_1000b206:
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_10013928);
  }
  local_20 = &stack0xffffff74;
  uVar4 = extraout_ECX;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff74,(CComBSTR *)&param_1);
  local_8._0_1_ = 3;
  local_1c = FUN_1000afbd(this,uVar4);
  piVar1 = param_2;
  if (local_1c == 0) {
    if (local_34 != 8) {
      param_2 = (int *)&stack0xffffff78;
      local_8._0_1_ = 3;
      puVar3 = FUN_1000ae81(local_70,0x80004005,0,0,0);
      local_8 = CONCAT31(local_8._1_3_,8);
      FUN_1000aee2(local_5c,(int)puVar3);
      pExceptionObject = local_5c;
      goto LAB_1000b206;
    }
    if ((*param_2 != 0) && (*param_2 != -0x33333334)) {
      Ordinal_6();
    }
    FUN_10001d6e(local_18,local_2c);
    iVar2 = local_18[0];
    local_18[0] = 0;
    *piVar1 = iVar2;
  }
  else {
    local_1c = -0x7fffbffb;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_9();
  local_8 = 1;
  FUN_1000b2d7();
  return;
}



// Function: Catch@1000b2bf at 1000b2bf

undefined * Catch_1000b2bf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000b2d5;
}



// Function: FUN_1000b2d7 at 1000b2d7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b2d7(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: Catch@1000b2f9 at 1000b2f9

undefined * Catch_1000b2f9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000b2d5;
}



// Function: FUN_1000b30d at 1000b30d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_1000b30d(int param_1)

{
  undefined2 local_20 [4];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000b319;
  local_20[0] = 0;
  FUN_10001fc7(local_20,param_1);
  local_8 = 0;
  FUN_1000a500(3,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  Ordinal_9(local_20);
  return local_18;
}



// Function: FUN_1000b35c at 1000b35c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000b35c(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x60) + 4) + -0x60 + param_1) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  FUN_1000a7c7((basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + -0x48));
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)(param_1 + -0x48));
  return;
}



// Function: FUN_1000b399 at 1000b399

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_1000b399(void *this,byte param_1)

{
  uint uVar1;
  
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  *(undefined ***)this =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  uVar1 = FUN_1000a548(param_1);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0x40) = uVar1;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_1000b3d9 at 1000b3d9

void __fastcall FUN_1000b3d9(int param_1)

{
  FUN_1000b35c(param_1 + 0x60);
                    /* WARNING: Could not recover jumptable at 0x1000b3e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(param_1 + 0x60));
  return;
}



// Function: FUN_1000b3ed at 1000b3ed

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_iostream<char,struct_std::char_traits<char>_> * __thiscall
FUN_1000b3ed(void *this,byte param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined **)this = &DAT_10010e58;
    *(undefined **)((int)this + 0x10) = &DAT_10010e50;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + 0x60));
  }
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)this,
             (basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18));
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  FUN_1000b399((basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18),param_1);
  return (basic_iostream<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_1000b45c at 1000b45c

void * __thiscall FUN_1000b45c(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x60);
  FUN_1000b3d9((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: assign at 1000b47e

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
           FUN_10003991(this,(undefined4 *)this,(int)param_1 - (int)pbVar2,param_2);
  }
  else {
    bVar1 = FUN_100031b0(this,param_2,'\0');
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



// Function: FUN_1000b4f3 at 1000b4f3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_1000b4f3(undefined2 *param_1,wchar_t *param_2)

{
  if (param_2 == (wchar_t *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    FUN_100049c7(param_1,param_2);
  }
  return param_1;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 1000b545

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



// Function: FUN_1000b574 at 1000b574

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl
FUN_1000b574(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
            LPCWSTR param_2)

{
  int iVar1;
  char *pcVar2;
  CHAR local_28 [16];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x1000b580;
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
  FUN_1000ba99();
  return;
}



// Function: FUN_1000b5f1 at 1000b5f1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000b5f1(void *this,undefined1 *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [16];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x1000b5fd;
  if (((*(byte *)((int)this + 0x40) & 2) == 0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 != (char *)0x0)) {
    pcVar1 = *(char **)((int)this + 0x3c);
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    if (pcVar1 < pcVar2) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    }
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)0x0;
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
              (local_30,pcVar3,(int)pcVar1 - (int)pcVar2);
    local_8 = 1;
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
    FUN_10004e09(param_1,local_30);
  }
  else {
    if (((*(byte *)((int)this + 0x40) & 4) == 0) &&
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       pcVar1 != (char *)0x0)) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
                (local_30,pcVar3,(int)pcVar2 - (int)pcVar1);
      local_8 = 2;
    }
    else {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0;
      local_8 = 3;
    }
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
    FUN_10004e09(param_1,local_30);
  }
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (local_30,true,0);
  FUN_1000ba99();
  return;
}



// Function: FUN_1000b721 at 1000b721

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_1000b721(void *this,undefined1 *param_1)

{
  FUN_1000b5f1((void *)((int)this + 0x18),param_1);
  return param_1;
}



// Function: FUN_1000b752 at 1000b752

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __cdecl FUN_1000b752(undefined1 *param_1,long param_2)

{
  undefined1 local_bc [16];
  basic_ostream<char,struct_std::char_traits<char>_> local_ac [80];
  basic_ios<char,struct_std::char_traits<char>_> local_5c [72];
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_8 = 0x1000b761;
  local_14 = 0;
  FUN_1000b3ed(local_bc,3,1);
  local_8 = 1;
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_ac,param_2);
  FUN_1000b721(local_bc,param_1);
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_1000b35c((int)local_5c);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>(local_5c);
  return param_1;
}



// Function: FUN_1000b7be at 1000b7be

void __fastcall FUN_1000b7be(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000b7dd at 1000b7dd

int __fastcall FUN_1000b7dd(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1000b802 at 1000b802

void __fastcall FUN_1000b802(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1000b7be((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000b81a at 1000b81a

undefined4 * __fastcall FUN_1000b81a(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000b7dd((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10010f70;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10016864 = 1;
  }
  return param_1;
}



// Function: FUN_1000b85a at 1000b85a

void __fastcall FUN_1000b85a(int *param_1)

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



// Function: FUN_1000b89e at 1000b89e

int __fastcall FUN_1000b89e(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1000b8b7 at 1000b8b7

undefined4 * __fastcall FUN_1000b8b7(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000b89e((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_10013e08;
  param_1[3] = &DAT_10013e08;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10016864 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1000b8f8 at 1000b8f8

void FUN_1000b8f8(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000b940

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



// Function: __security_check_cookie at 1000b99e

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1001680c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 1000b9ad

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001680c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 1000b9e0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001680c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1000ba16

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001680c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 1000ba4c

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001680c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 1000ba85

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



// Function: FUN_1000ba99 at 1000ba99

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000ba99(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_1000baa8 at 1000baa8

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000baa8(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __ArrayUnwind at 1000bae8

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



// Function: `eh_vector_destructor_iterator' at 1000bb46

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
  FUN_1000bb91();
  return;
}



// Function: FUN_1000bb91 at 1000bb91

void FUN_1000bb91(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 1000bbb0

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
  
  local_8 = &DAT_10013d80;
  uStack_c = 0x1000bbbc;
  local_20[0] = DecodePointer(DAT_10016ecc);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10016ecc);
    local_24 = DecodePointer(DAT_10016ec8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10016ecc = EncodePointer(local_20[0]);
    DAT_10016ec8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000bc48();
  }
  return p_Var1;
}



// Function: FUN_1000bc48 at 1000bc48

void FUN_1000bc48(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000bc51

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 1000bc70

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



// Function: `eh_vector_constructor_iterator' at 1000bc9b

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
  FUN_1000bce8();
  return;
}



// Function: FUN_1000bce8 at 1000bce8

void FUN_1000bce8(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: FUN_1000bd57 at 1000bd57

void __cdecl
FUN_1000bd57(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1001680c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 1000bd80

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



// Function: __alloca_probe_8 at 1000bd96

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



// Function: __CRT_INIT@12 at 1000bdfe

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
    if (DAT_10016b88 < 1) {
      return 0;
    }
    DAT_10016b88 = DAT_10016b88 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10016ec0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10016ebc == 2) {
      param_2 = (int *)DecodePointer(DAT_10016ecc);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10016ec8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10016ecc);
            piVar8 = (int *)DecodePointer(DAT_10016ec8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10016ec8 = (PVOID)encoded_null();
        DAT_10016ecc = DAT_10016ec8;
      }
      DAT_10016ebc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10016ec0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10016ec0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10016ebc == 0) {
      DAT_10016ebc = 1;
      iVar5 = initterm_e(&DAT_1000f30c,&DAT_1000f314);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1000f28c,&DAT_1000f308);
      DAT_10016ebc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10016ec0,0);
    }
    if ((DAT_10016ec4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10016ec4), BVar2 != 0)) {
      (*DAT_10016ec4)(param_1,2,param_3);
    }
    DAT_10016b88 = DAT_10016b88 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1000c008

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000c0a8) */
/* WARNING: Removing unreachable block (ram,0x1000c055) */
/* WARNING: Removing unreachable block (ram,0x1000c0d5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10016820 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10016b88 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_100070d3(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_100070d3(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000c113();
  return local_20;
}



// Function: FUN_1000c113 at 1000c113

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000c113(void)

{
  _DAT_10016820 = 0xffffffff;
  return;
}



// Function: entry at 1000c11e

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1000c141

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
  
  _DAT_10016ca8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10016cac = &stack0x00000004;
  _DAT_10016be8 = 0x10001;
  _DAT_10016b90 = 0xc0000409;
  _DAT_10016b94 = 1;
  local_32c = DAT_1001680c;
  local_328 = DAT_10016810;
  _DAT_10016b9c = unaff_retaddr;
  _DAT_10016c74 = in_GS;
  _DAT_10016c78 = in_FS;
  _DAT_10016c7c = in_ES;
  _DAT_10016c80 = in_DS;
  _DAT_10016c84 = unaff_EDI;
  _DAT_10016c88 = unaff_ESI;
  _DAT_10016c8c = unaff_EBX;
  _DAT_10016c90 = in_EDX;
  _DAT_10016c94 = in_ECX;
  _DAT_10016c98 = in_EAX;
  _DAT_10016c9c = unaff_EBP;
  DAT_10016ca0 = unaff_retaddr;
  _DAT_10016ca4 = in_CS;
  _DAT_10016cb0 = in_SS;
  DAT_10016be0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10010f8c);
  if (DAT_10016be0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1000c250

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001680c ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000c295

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



// Function: __ValidateImageBase at 1000c320

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



// Function: __FindPESection at 1000c360

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



// Function: __IsNonwritableInCurrentImage at 1000c3b0

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
  
  pcStack_10 = FUN_1000bd57;
  local_14 = ExceptionList;
  local_c = DAT_1001680c ^ 0x10013de8;
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



// Function: ___security_init_cookie at 1000c484

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
  if ((DAT_1001680c == 0xbb40e64e) || ((DAT_1001680c & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1001680c = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1001680c == 0xbb40e64e) {
      DAT_1001680c = 0xbb40e64f;
    }
    else if ((DAT_1001680c & 0xffff0000) == 0) {
      DAT_1001680c = DAT_1001680c | (DAT_1001680c | 0x4711) << 0x10;
    }
    DAT_10016810 = ~DAT_1001680c;
  }
  else {
    DAT_10016810 = ~DAT_1001680c;
  }
  return;
}



// Function: Unwind@1000c532 at 1000c532

void Unwind_1000c532(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000c535. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c571 at 1000c571

void Unwind_1000c571(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c579 at 1000c579

void Unwind_1000c579(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1000c59f at 1000c59f

void Unwind_1000c59f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000c5a7 at 1000c5a7

void Unwind_1000c5a7(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c5af at 1000c5af

void Unwind_1000c5af(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1000c5d5 at 1000c5d5

void Unwind_1000c5d5(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c613 at 1000c613

void Unwind_1000c613(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000c616. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c637 at 1000c637

void Unwind_1000c637(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c675 at 1000c675

void Unwind_1000c675(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c698 at 1000c698

void Unwind_1000c698(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000c6bb at 1000c6bb

void Unwind_1000c6bb(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c6c3 at 1000c6c3

void Unwind_1000c6c3(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c6cb at 1000c6cb

void Unwind_1000c6cb(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c6d3 at 1000c6d3

void Unwind_1000c6d3(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c6db at 1000c6db

void Unwind_1000c6db(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c6e3 at 1000c6e3

void Unwind_1000c6e3(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c706 at 1000c706

void Unwind_1000c706(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c70e at 1000c70e

void Unwind_1000c70e(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c716 at 1000c716

void Unwind_1000c716(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c739 at 1000c739

void Unwind_1000c739(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c77a at 1000c77a

void Unwind_1000c77a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c782 at 1000c782

void Unwind_1000c782(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c78a at 1000c78a

void Unwind_1000c78a(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c792 at 1000c792

void Unwind_1000c792(void)

{
  int unaff_EBP;
  
  FUN_1000a6ac((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000c79a at 1000c79a

void Unwind_1000c79a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000c7a2 at 1000c7a2

void Unwind_1000c7a2(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000c7aa at 1000c7aa

void Unwind_1000c7aa(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000c7b2 at 1000c7b2

void Unwind_1000c7b2(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1000c7ba at 1000c7ba

void Unwind_1000c7ba(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1000c7c2 at 1000c7c2

void Unwind_1000c7c2(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1000c7ca at 1000c7ca

void Unwind_1000c7ca(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c7d2 at 1000c7d2

void Unwind_1000c7d2(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000c7f5 at 1000c7f5

void Unwind_1000c7f5(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@1000c800 at 1000c800

void Unwind_1000c800(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c80b at 1000c80b

void Unwind_1000c80b(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c816 at 1000c816

void Unwind_1000c816(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000c821 at 1000c821

void Unwind_1000c821(void)

{
  int unaff_EBP;
  
  FUN_10001f74(unaff_EBP + -0x25c);
  return;
}



// Function: Unwind@1000c82c at 1000c82c

void Unwind_1000c82c(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c85f at 1000c85f

void Unwind_1000c85f(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@1000c86a at 1000c86a

void Unwind_1000c86a(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c875 at 1000c875

void Unwind_1000c875(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c880 at 1000c880

void Unwind_1000c880(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000c88b at 1000c88b

void Unwind_1000c88b(void)

{
  int unaff_EBP;
  
  FUN_10001f74(unaff_EBP + -0x25c);
  return;
}



// Function: Unwind@1000c896 at 1000c896

void Unwind_1000c896(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c8c9 at 1000c8c9

void Unwind_1000c8c9(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000c8d1 at 1000c8d1

void Unwind_1000c8d1(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000c8d9 at 1000c8d9

void Unwind_1000c8d9(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000c8e1 at 1000c8e1

void Unwind_1000c8e1(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000c8e9 at 1000c8e9

void Unwind_1000c8e9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000c8f1 at 1000c8f1

void Unwind_1000c8f1(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000c8f9 at 1000c8f9

void Unwind_1000c8f9(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000c901 at 1000c901

void Unwind_1000c901(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000c92e at 1000c92e

void Unwind_1000c92e(void)

{
  int unaff_EBP;
  
  FUN_10002949(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c936 at 1000c936

void Unwind_1000c936(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c95c at 1000c95c

void Unwind_1000c95c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002015(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000c990 at 1000c990

void Unwind_1000c990(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1000c9c3 at 1000c9c3

void Unwind_1000c9c3(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@1000c9ce at 1000c9ce

void Unwind_1000c9ce(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000c9d9 at 1000c9d9

void Unwind_1000c9d9(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(unaff_EBP + -0x42c));
  return;
}



// Function: Unwind@1000c9e4 at 1000c9e4

void Unwind_1000c9e4(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000c9ef at 1000c9ef

void Unwind_1000c9ef(void)

{
  int unaff_EBP;
  
  FUN_10001f74(unaff_EBP + -0x454);
  return;
}



// Function: Unwind@1000ca22 at 1000ca22

void Unwind_1000ca22(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@1000ca2d at 1000ca2d

void Unwind_1000ca2d(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000ca38 at 1000ca38

void Unwind_1000ca38(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(unaff_EBP + -0x42c));
  return;
}



// Function: Unwind@1000ca6b at 1000ca6b

void Unwind_1000ca6b(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000ca73 at 1000ca73

void Unwind_1000ca73(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000ca7b at 1000ca7b

void Unwind_1000ca7b(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000ca83 at 1000ca83

void Unwind_1000ca83(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000ca8b at 1000ca8b

void Unwind_1000ca8b(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ca93 at 1000ca93

void Unwind_1000ca93(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000ca9b at 1000ca9b

void Unwind_1000ca9b(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000caa3 at 1000caa3

void Unwind_1000caa3(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000caab at 1000caab

void Unwind_1000caab(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000cab3 at 1000cab3

void Unwind_1000cab3(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000cabb at 1000cabb

void Unwind_1000cabb(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000cade at 1000cade

void Unwind_1000cade(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000cb01 at 1000cb01

void Unwind_1000cb01(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cb09 at 1000cb09

void Unwind_1000cb09(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cb11 at 1000cb11

void Unwind_1000cb11(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cb34 at 1000cb34

void Unwind_1000cb34(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@1000cb3f at 1000cb3f

void Unwind_1000cb3f(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000cb4a at 1000cb4a

void Unwind_1000cb4a(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000cb55 at 1000cb55

void Unwind_1000cb55(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@1000cb60 at 1000cb60

void Unwind_1000cb60(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@1000cb6b at 1000cb6b

void Unwind_1000cb6b(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000cb76 at 1000cb76

void Unwind_1000cb76(void)

{
  int unaff_EBP;
  
  FUN_10001f74(unaff_EBP + -0x25c);
  return;
}



// Function: Unwind@1000cb81 at 1000cb81

void Unwind_1000cb81(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@1000cb8c at 1000cb8c

void Unwind_1000cb8c(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000cbbf at 1000cbbf

void Unwind_1000cbbf(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000cbc7 at 1000cbc7

void Unwind_1000cbc7(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cbcf at 1000cbcf

void Unwind_1000cbcf(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000cbd7 at 1000cbd7

void Unwind_1000cbd7(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000cbdf at 1000cbdf

void Unwind_1000cbdf(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000cbe7 at 1000cbe7

void Unwind_1000cbe7(void)

{
  int unaff_EBP;
  
  FUN_1000a6ac((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000cbef at 1000cbef

void Unwind_1000cbef(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cbf7 at 1000cbf7

void Unwind_1000cbf7(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000cbff at 1000cbff

void Unwind_1000cbff(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000cc22 at 1000cc22

void Unwind_1000cc22(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000cc2a at 1000cc2a

void Unwind_1000cc2a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000cc32 at 1000cc32

void Unwind_1000cc32(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1000cc3a at 1000cc3a

void Unwind_1000cc3a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000cc42 at 1000cc42

void Unwind_1000cc42(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1000cc4a at 1000cc4a

void Unwind_1000cc4a(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cc52 at 1000cc52

void Unwind_1000cc52(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cc5a at 1000cc5a

void Unwind_1000cc5a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1000cc62 at 1000cc62

void Unwind_1000cc62(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cc6a at 1000cc6a

void Unwind_1000cc6a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cc97 at 1000cc97

void Unwind_1000cc97(void)

{
  FUN_10006c6c();
  return;
}



// Function: Unwind@1000ccdb at 1000ccdb

void Unwind_1000ccdb(void)

{
  int unaff_EBP;
  
  FUN_10002359(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cd19 at 1000cd19

void Unwind_1000cd19(void)

{
  int unaff_EBP;
  
  FUN_10005314(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cd3c at 1000cd3c

void Unwind_1000cd3c(void)

{
  int unaff_EBP;
  
  FUN_10005408((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000cd47 at 1000cd47

void Unwind_1000cd47(void)

{
  int unaff_EBP;
  
  FUN_10005314(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cd6a at 1000cd6a

void Unwind_1000cd6a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x2ac));
  return;
}



// Function: Unwind@1000cd75 at 1000cd75

void Unwind_1000cd75(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x270));
  return;
}



// Function: Unwind@1000cd80 at 1000cd80

void Unwind_1000cd80(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1000cd8b at 1000cd8b

void Unwind_1000cd8b(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x2b4));
  return;
}



// Function: Unwind@1000cd96 at 1000cd96

void Unwind_1000cd96(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x2a8));
  return;
}



// Function: Unwind@1000cda1 at 1000cda1

void Unwind_1000cda1(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x298));
  return;
}



// Function: Unwind@1000cdac at 1000cdac

void Unwind_1000cdac(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@1000cdb7 at 1000cdb7

void Unwind_1000cdb7(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x2a8));
  return;
}



// Function: Unwind@1000cdc2 at 1000cdc2

void Unwind_1000cdc2(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x2c0));
  return;
}



// Function: Unwind@1000cdcd at 1000cdcd

void Unwind_1000cdcd(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x2c0));
  return;
}



// Function: Unwind@1000cdd8 at 1000cdd8

void Unwind_1000cdd8(void)

{
  int unaff_EBP;
  
  FUN_100031a6((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x28c));
  return;
}



// Function: Unwind@1000cde3 at 1000cde3

void Unwind_1000cde3(void)

{
  int unaff_EBP;
  
  FUN_100052f3((_Container_base0 *)(unaff_EBP + -0x2dc));
  return;
}



// Function: Unwind@1000cdee at 1000cdee

void Unwind_1000cdee(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -700) & 1) != 0) {
    *(uint *)(unaff_EBP + -700) = *(uint *)(unaff_EBP + -700) & 0xfffffffe;
    ~basic_string<>((void *)(unaff_EBP + -0x254));
    return;
  }
  return;
}



// Function: Unwind@1000ce10 at 1000ce10

void Unwind_1000ce10(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@1000ce1b at 1000ce1b

void Unwind_1000ce1b(void)

{
  int unaff_EBP;
  
  FUN_100031a6((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x254));
  return;
}



// Function: Unwind@1000ce26 at 1000ce26

void Unwind_1000ce26(void)

{
  int unaff_EBP;
  
  FUN_1000a6ac((int *)(unaff_EBP + -0x2e8));
  return;
}



// Function: Unwind@1000ce31 at 1000ce31

void Unwind_1000ce31(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x29c));
  return;
}



// Function: Unwind@1000ce3c at 1000ce3c

void Unwind_1000ce3c(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x2c8));
  return;
}



// Function: Unwind@1000ce47 at 1000ce47

void Unwind_1000ce47(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x290));
  return;
}



// Function: Unwind@1000ce52 at 1000ce52

void Unwind_1000ce52(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x2a0));
  return;
}



// Function: Unwind@1000ce5d at 1000ce5d

void Unwind_1000ce5d(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x2a0));
  return;
}



// Function: Unwind@1000ce68 at 1000ce68

void Unwind_1000ce68(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x2a4));
  return;
}



// Function: Unwind@1000ce73 at 1000ce73

void Unwind_1000ce73(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x2a0));
  return;
}



// Function: Unwind@1000ce7e at 1000ce7e

void Unwind_1000ce7e(void)

{
  int unaff_EBP;
  
  FUN_100031a6((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x254));
  return;
}



// Function: Unwind@1000ce89 at 1000ce89

void Unwind_1000ce89(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x2c0));
  return;
}



// Function: Unwind@1000ce94 at 1000ce94

void Unwind_1000ce94(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x29c));
  return;
}



// Function: Unwind@1000cec7 at 1000cec7

void Unwind_1000cec7(void)

{
  int unaff_EBP;
  
  FUN_10005426(*(int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000ceea at 1000ceea

void Unwind_1000ceea(void)

{
  int unaff_EBP;
  
  FUN_1000602a(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf0d at 1000cf0d

void Unwind_1000cf0d(void)

{
  int unaff_EBP;
  
  FUN_10002359(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf15 at 1000cf15

void Unwind_1000cf15(void)

{
  int unaff_EBP;
  
  FUN_1000602a(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf38 at 1000cf38

void Unwind_1000cf38(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf40 at 1000cf40

void Unwind_1000cf40(void)

{
  int unaff_EBP;
  
  FUN_10002244(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf48 at 1000cf48

void Unwind_1000cf48(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000cf53 at 1000cf53

void Unwind_1000cf53(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf5b at 1000cf5b

void Unwind_1000cf5b(void)

{
  int unaff_EBP;
  
  FUN_100012d7((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1000cf66 at 1000cf66

void Unwind_1000cf66(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000cf71 at 1000cf71

void Unwind_1000cf71(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 0x50));
  return;
}



// Function: Unwind@1000cf7c at 1000cf7c

void Unwind_1000cf7c(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@1000cf87 at 1000cf87

void Unwind_1000cf87(void)

{
  int unaff_EBP;
  
  FUN_10006064((void *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1000cfad at 1000cfad

void Unwind_1000cfad(void)

{
  int unaff_EBP;
  
  FUN_10002244(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cfb5 at 1000cfb5

void Unwind_1000cfb5(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000cfc0 at 1000cfc0

void Unwind_1000cfc0(void)

{
  int unaff_EBP;
  
  FUN_100012d7((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1000cfcb at 1000cfcb

void Unwind_1000cfcb(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000cfd6 at 1000cfd6

void Unwind_1000cfd6(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 0x50));
  return;
}



// Function: Unwind@1000cfe1 at 1000cfe1

void Unwind_1000cfe1(void)

{
  int unaff_EBP;
  
  FUN_10002015((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@1000cfec at 1000cfec

void Unwind_1000cfec(void)

{
  int unaff_EBP;
  
  FUN_10006064((void *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1000cff7 at 1000cff7

void Unwind_1000cff7(void)

{
  int unaff_EBP;
  
  FUN_1000602a(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cfff at 1000cfff

void Unwind_1000cfff(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d022 at 1000d022

void Unwind_1000d022(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000d02d at 1000d02d

void Unwind_1000d02d(void)

{
  int unaff_EBP;
  
  FUN_1000614a((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000d038 at 1000d038

void Unwind_1000d038(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d040 at 1000d040

void Unwind_1000d040(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}



// Function: Unwind@1000d04e at 1000d04e

void Unwind_1000d04e(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d056 at 1000d056

void Unwind_1000d056(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@1000d064 at 1000d064

void Unwind_1000d064(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d06c at 1000d06c

void Unwind_1000d06c(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}



// Function: Unwind@1000d07a at 1000d07a

void Unwind_1000d07a(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d082 at 1000d082

void Unwind_1000d082(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}



// Function: Unwind@1000d090 at 1000d090

void Unwind_1000d090(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d098 at 1000d098

void Unwind_1000d098(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x90));
  return;
}



// Function: Unwind@1000d0c1 at 1000d0c1

void Unwind_1000d0c1(void)

{
  DAT_1001689c = DAT_1001689c & 0xfffffffe;
  return;
}



// Function: Unwind@1000d0ea at 1000d0ea

void Unwind_1000d0ea(void)

{
  int unaff_EBP;
  
  FUN_1000637a(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d10d at 1000d10d

void Unwind_1000d10d(void)

{
  int unaff_EBP;
  
  FUN_10006ce7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d130 at 1000d130

void Unwind_1000d130(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000d163 at 1000d163

void Unwind_1000d163(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1000d196 at 1000d196

void Unwind_1000d196(void)

{
  int unaff_EBP;
  
  FUN_10006bb7((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d1bc at 1000d1bc

void Unwind_1000d1bc(void)

{
  FUN_10006c6c();
  return;
}



// Function: Unwind@1000d1d3 at 1000d1d3

void Unwind_1000d1d3(void)

{
  FUN_10006c6c();
  return;
}



// Function: Unwind@1000d206 at 1000d206

void Unwind_1000d206(void)

{
  int unaff_EBP;
  
  FUN_10006ce7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d20e at 1000d20e

void Unwind_1000d20e(void)

{
  int unaff_EBP;
  
  FUN_10006cec(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d231 at 1000d231

void Unwind_1000d231(void)

{
  int unaff_EBP;
  
  FUN_10006cec(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d239 at 1000d239

void Unwind_1000d239(void)

{
  int unaff_EBP;
  
  FUN_10006ce7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d25c at 1000d25c

void Unwind_1000d25c(void)

{
  int unaff_EBP;
  
  FUN_10007115(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d27f at 1000d27f

void Unwind_1000d27f(void)

{
  int unaff_EBP;
  
  FUN_100072b3((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d2a5 at 1000d2a5

void Unwind_1000d2a5(void)

{
  int unaff_EBP;
  
  FUN_1000667d(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1000d2d2 at 1000d2d2

void Unwind_1000d2d2(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d2dd at 1000d2dd

void Unwind_1000d2dd(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d2e8 at 1000d2e8

void Unwind_1000d2e8(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d2f3 at 1000d2f3

void Unwind_1000d2f3(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d2fe at 1000d2fe

void Unwind_1000d2fe(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d309 at 1000d309

void Unwind_1000d309(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1000d314 at 1000d314

void Unwind_1000d314(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1000d31f at 1000d31f

void Unwind_1000d31f(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@1000d32a at 1000d32a

void Unwind_1000d32a(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d335 at 1000d335

void Unwind_1000d335(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000d368 at 1000d368

void Unwind_1000d368(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d370 at 1000d370

void Unwind_1000d370(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d378 at 1000d378

void Unwind_1000d378(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d380 at 1000d380

void Unwind_1000d380(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d388 at 1000d388

void Unwind_1000d388(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d3ab at 1000d3ab

void Unwind_1000d3ab(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000d3b6 at 1000d3b6

void Unwind_1000d3b6(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d3c1 at 1000d3c1

void Unwind_1000d3c1(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d3cc at 1000d3cc

void Unwind_1000d3cc(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000d3d7 at 1000d3d7

void Unwind_1000d3d7(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d3e2 at 1000d3e2

void Unwind_1000d3e2(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d415 at 1000d415

void Unwind_1000d415(void)

{
  int unaff_EBP;
  
  FUN_100071ac((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d438 at 1000d438

void Unwind_1000d438(void)

{
  int unaff_EBP;
  
  FUN_10007137(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000d443 at 1000d443

void Unwind_1000d443(void)

{
  int unaff_EBP;
  
  FUN_10006bb7((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d469 at 1000d469

void Unwind_1000d469(void)

{
  int unaff_EBP;
  
  FUN_10006bb7((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000d474 at 1000d474

void Unwind_1000d474(void)

{
  int unaff_EBP;
  
  FUN_10007137(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000d49a at 1000d49a

void Unwind_1000d49a(void)

{
  int unaff_EBP;
  
  FUN_1000711a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d4a2 at 1000d4a2

void Unwind_1000d4a2(void)

{
  int unaff_EBP;
  
  FUN_1000711a((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d4c5 at 1000d4c5

void Unwind_1000d4c5(void)

{
  int unaff_EBP;
  
  FUN_1000712a((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000d4d0 at 1000d4d0

void Unwind_1000d4d0(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1000d4db at 1000d4db

void Unwind_1000d4db(void)

{
  int unaff_EBP;
  
  FUN_1000712a((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000d50e at 1000d50e

void Unwind_1000d50e(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@1000d519 at 1000d519

void Unwind_1000d519(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@1000d524 at 1000d524

void Unwind_1000d524(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@1000d52f at 1000d52f

void Unwind_1000d52f(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@1000d53a at 1000d53a

void Unwind_1000d53a(void)

{
  int unaff_EBP;
  
  FUN_10002010((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1000d56d at 1000d56d

void Unwind_1000d56d(void)

{
  int unaff_EBP;
  
  FUN_100071ac((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d590 at 1000d590

void Unwind_1000d590(void)

{
  int unaff_EBP;
  
  FUN_10007da1(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d5b3 at 1000d5b3

void Unwind_1000d5b3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d5d8 at 1000d5d8

void Unwind_1000d5d8(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000d5e3 at 1000d5e3

void Unwind_1000d5e3(void)

{
  int unaff_EBP;
  
  FUN_1000712a((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000d616 at 1000d616

void Unwind_1000d616(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d639 at 1000d639

void Unwind_1000d639(void)

{
  int unaff_EBP;
  
  FUN_10007115(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000d644 at 1000d644

void Unwind_1000d644(void)

{
  int unaff_EBP;
  
  FUN_100072b3((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000d64f at 1000d64f

void Unwind_1000d64f(void)

{
  int unaff_EBP;
  
  FUN_100072dd((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000d65a at 1000d65a

void Unwind_1000d65a(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000d68d at 1000d68d

void Unwind_1000d68d(void)

{
  int unaff_EBP;
  
  FUN_10007115(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000d698 at 1000d698

void Unwind_1000d698(void)

{
  int unaff_EBP;
  
  FUN_100072b3((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000d6a3 at 1000d6a3

void Unwind_1000d6a3(void)

{
  int unaff_EBP;
  
  FUN_100072dd((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000d6ae at 1000d6ae

void Unwind_1000d6ae(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000d6e1 at 1000d6e1

void Unwind_1000d6e1(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000d6ec at 1000d6ec

void Unwind_1000d6ec(void)

{
  int unaff_EBP;
  
  FUN_1000614a((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000d6f7 at 1000d6f7

void Unwind_1000d6f7(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}



// Function: Unwind@1000d705 at 1000d705

void Unwind_1000d705(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@1000d713 at 1000d713

void Unwind_1000d713(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}



// Function: Unwind@1000d721 at 1000d721

void Unwind_1000d721(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x8c));
  return;
}



// Function: Unwind@1000d72f at 1000d72f

void Unwind_1000d72f(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(*(int *)(unaff_EBP + -0x10) + 0x90));
  return;
}



// Function: Unwind@1000d73d at 1000d73d

void Unwind_1000d73d(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d745 at 1000d745

void Unwind_1000d745(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d74d at 1000d74d

void Unwind_1000d74d(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d755 at 1000d755

void Unwind_1000d755(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d75d at 1000d75d

void Unwind_1000d75d(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d780 at 1000d780

void Unwind_1000d780(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d78a at 1000d78a

void Unwind_1000d78a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d7ad at 1000d7ad

void Unwind_1000d7ad(void)

{
  int unaff_EBP;
  
  FUN_100071ac((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d7d0 at 1000d7d0

void Unwind_1000d7d0(void)

{
  int unaff_EBP;
  
  FUN_100071ac((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1000d7db at 1000d7db

void Unwind_1000d7db(void)

{
  int unaff_EBP;
  
  FUN_10001a76((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000d7e6 at 1000d7e6

void Unwind_1000d7e6(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d7f1 at 1000d7f1

void Unwind_1000d7f1(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d7fc at 1000d7fc

void Unwind_1000d7fc(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000d807 at 1000d807

void Unwind_1000d807(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000d812 at 1000d812

void Unwind_1000d812(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000d81d at 1000d81d

void Unwind_1000d81d(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000d828 at 1000d828

void Unwind_1000d828(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000d833 at 1000d833

void Unwind_1000d833(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000d83e at 1000d83e

void Unwind_1000d83e(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000d871 at 1000d871

void Unwind_1000d871(void)

{
  int unaff_EBP;
  
  FUN_10009828(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d894 at 1000d894

void Unwind_1000d894(void)

{
  int unaff_EBP;
  
  FUN_100098ec(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1000d8ba at 1000d8ba

void Unwind_1000d8ba(void)

{
  int unaff_EBP;
  
  FUN_100098ec(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1000d8c5 at 1000d8c5

void Unwind_1000d8c5(void)

{
  int unaff_EBP;
  
  FUN_10009828(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d903 at 1000d903

void Unwind_1000d903(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d928 at 1000d928

void Unwind_1000d928(void)

{
  FUN_10006cec(0x100168a0);
  return;
}



// Function: Unwind@1000d932 at 1000d932

void Unwind_1000d932(void)

{
  FUN_10006ce7(0x100168a0);
  return;
}



// Function: Unwind@1000d957 at 1000d957

void Unwind_1000d957(void)

{
  int unaff_EBP;
  
  FUN_1000a47d(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d95f at 1000d95f

void Unwind_1000d95f(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000d985 at 1000d985

void Unwind_1000d985(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d98d at 1000d98d

void Unwind_1000d98d(void)

{
  int unaff_EBP;
  
  FUN_10002244(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d9b0 at 1000d9b0

void Unwind_1000d9b0(void)

{
  int unaff_EBP;
  
  FUN_10002244(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d9b8 at 1000d9b8

void Unwind_1000d9b8(void)

{
  int unaff_EBP;
  
  FUN_100099a3(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d9db at 1000d9db

void Unwind_1000d9db(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d9e3 at 1000d9e3

void Unwind_1000d9e3(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d9eb at 1000d9eb

void Unwind_1000d9eb(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000da0e at 1000da0e

void Unwind_1000da0e(void)

{
  int unaff_EBP;
  
  FUN_10001f74(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1000da16 at 1000da16

void Unwind_1000da16(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100016e8(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000da4a at 1000da4a

void Unwind_1000da4a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1000da52 at 1000da52

void Unwind_1000da52(void)

{
  int unaff_EBP;
  
  FUN_1000a47d(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da5a at 1000da5a

void Unwind_1000da5a(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000da80 at 1000da80

void Unwind_1000da80(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000da88 at 1000da88

void Unwind_1000da88(void)

{
  int unaff_EBP;
  
  FUN_1000a5af((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000daab at 1000daab

void Unwind_1000daab(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000dab3 at 1000dab3

void Unwind_1000dab3(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000dabb at 1000dabb

void Unwind_1000dabb(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000dac3 at 1000dac3

void Unwind_1000dac3(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dacb at 1000dacb

void Unwind_1000dacb(void)

{
  int unaff_EBP;
  
  FUN_10002244((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dad3 at 1000dad3

void Unwind_1000dad3(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000dadb at 1000dadb

void Unwind_1000dadb(void)

{
  int unaff_EBP;
  
  FUN_1000a5af((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000dae6 at 1000dae6

void Unwind_1000dae6(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000daee at 1000daee

void Unwind_1000daee(void)

{
  int unaff_EBP;
  
  FUN_1000a5af((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000daf9 at 1000daf9

void Unwind_1000daf9(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000db01 at 1000db01

void Unwind_1000db01(void)

{
  int unaff_EBP;
  
  FUN_1000a5af((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000db0c at 1000db0c

void Unwind_1000db0c(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000db14 at 1000db14

void Unwind_1000db14(void)

{
  int unaff_EBP;
  
  FUN_1000a5af((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000db1f at 1000db1f

void Unwind_1000db1f(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000db27 at 1000db27

void Unwind_1000db27(void)

{
  int unaff_EBP;
  
  FUN_100099a3((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000db4d at 1000db4d

void Unwind_1000db4d(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000db55 at 1000db55

void Unwind_1000db55(void)

{
  int unaff_EBP;
  
  FUN_100016e8((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000db5d at 1000db5d

void Unwind_1000db5d(void)

{
  int unaff_EBP;
  
  FUN_10001f74(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@1000db65 at 1000db65

void Unwind_1000db65(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db6d at 1000db6d

void Unwind_1000db6d(void)

{
  int unaff_EBP;
  
  FUN_1000a5af((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1000db75 at 1000db75

void Unwind_1000db75(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000db7d at 1000db7d

void Unwind_1000db7d(void)

{
  int unaff_EBP;
  
  FUN_100016e8(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db85 at 1000db85

void Unwind_1000db85(void)

{
  int unaff_EBP;
  
  FUN_1000a5af((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1000dba8 at 1000dba8

void Unwind_1000dba8(void)

{
  int unaff_EBP;
  
  FUN_10001f74(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@1000dbcb at 1000dbcb

void Unwind_1000dbcb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dbd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000dbd7 at 1000dbd7

void Unwind_1000dbd7(void)

{
  int unaff_EBP;
  
  FUN_1000a7c7((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000dbfd at 1000dbfd

void Unwind_1000dbfd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dc00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dc21 at 1000dc21

void Unwind_1000dc21(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1000dc37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<char,struct_std::char_traits<char>_>::
    ~basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x60));
    return;
  }
  return;
}



// Function: Unwind@1000dc3e at 1000dc3e

void Unwind_1000dc3e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000dc44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1000dc4a at 1000dc4a

void Unwind_1000dc4a(void)

{
  int unaff_EBP;
  
  FUN_1000a7c7((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1000dc70 at 1000dc70

void Unwind_1000dc70(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000dca4 at 1000dca4

void Unwind_1000dca4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_100031a6(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000dce2 at 1000dce2

void Unwind_1000dce2(void)

{
  int unaff_EBP;
  
  FUN_100031a6((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000dcea at 1000dcea

void Unwind_1000dcea(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffe;
    FUN_100031a6(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + -0x3c));
    return;
  }
  return;
}



// Function: Unwind@1000dd03 at 1000dd03

void Unwind_1000dd03(void)

{
  int unaff_EBP;
  
  FUN_100031a6((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000dd0b at 1000dd0b

void Unwind_1000dd0b(void)

{
  int unaff_EBP;
  
  FUN_100031a6((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000dd38 at 1000dd38

void Unwind_1000dd38(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100031a6(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000dd6c at 1000dd6c

void Unwind_1000dd6c(void)

{
  int unaff_EBP;
  
  FUN_1000b3d9(unaff_EBP + -0xb8);
  return;
}



// Function: Unwind@1000dd77 at 1000dd77

void Unwind_1000dd77(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100031a6(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: FUN_1000e0f6 at 1000e0f6

void FUN_1000e0f6(void)

{
  Ordinal_6(DAT_1001685c);
  return;
}



// Function: FUN_1000e103 at 1000e103

void FUN_1000e103(void)

{
  Ordinal_6(DAT_10016860);
  return;
}



// Function: FUN_1000e110 at 1000e110

void FUN_1000e110(void)

{
  FID_conflict__Tidy(&DAT_10016840,'\x01',0);
  return;
}



// Function: FUN_1000e11f at 1000e11f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000e11f(void)

{
  _DAT_100168a0 = ATL::CComModule::vftable;
  FUN_10006cae(0x100168a0);
  return;
}



// Function: FUN_1000e149 at 1000e149

void FUN_1000e149(void)

{
  Ordinal_6(DAT_10016a04);
  return;
}



// Function: FUN_1000e156 at 1000e156

void FUN_1000e156(void)

{
  Ordinal_6(DAT_10016b20);
  return;
}



// Function: FUN_1000e163 at 1000e163

void FUN_1000e163(void)

{
  Ordinal_6(DAT_10016b24);
  return;
}



// Function: FUN_1000e170 at 1000e170

void FUN_1000e170(void)

{
  FID_conflict__Tidy(&DAT_10016908,'\x01',0);
  return;
}



// Function: FUN_1000e17f at 1000e17f

void FUN_1000e17f(void)

{
  FID_conflict__Tidy(&DAT_100168ec,'\x01',0);
  return;
}



// Function: FUN_1000e18e at 1000e18e

void FUN_1000e18e(void)

{
  FID_conflict__Tidy(&DAT_100168d0,'\x01',0);
  return;
}



// Function: FUN_1000e19d at 1000e19d

void FUN_1000e19d(void)

{
  FID_conflict__Tidy(&DAT_10016a94,'\x01',0);
  return;
}



// Function: FUN_1000e1ac at 1000e1ac

void FUN_1000e1ac(void)

{
  FID_conflict__Tidy(&DAT_100169e8,'\x01',0);
  return;
}



// Function: FUN_1000e1bb at 1000e1bb

void FUN_1000e1bb(void)

{
  FID_conflict__Tidy(&DAT_10016ae8,'\x01',0);
  return;
}



// Function: FUN_1000e1ca at 1000e1ca

void FUN_1000e1ca(void)

{
  FID_conflict__Tidy(&DAT_10016924,'\x01',0);
  return;
}



// Function: FUN_1000e1d9 at 1000e1d9

void FUN_1000e1d9(void)

{
  FID_conflict__Tidy(&DAT_10016a40,'\x01',0);
  return;
}



// Function: FUN_1000e1e8 at 1000e1e8

void FUN_1000e1e8(void)

{
  FID_conflict__Tidy(&DAT_10016ab0,'\x01',0);
  return;
}



// Function: FUN_1000e1f7 at 1000e1f7

void FUN_1000e1f7(void)

{
  FID_conflict__Tidy(&DAT_10016a78,'\x01',0);
  return;
}



// Function: FUN_1000e206 at 1000e206

void FUN_1000e206(void)

{
  FID_conflict__Tidy(&DAT_10016acc,'\x01',0);
  return;
}



// Function: FUN_1000e215 at 1000e215

void FUN_1000e215(void)

{
  FID_conflict__Tidy(&DAT_10016a08,'\x01',0);
  return;
}



// Function: FUN_1000e224 at 1000e224

void FUN_1000e224(void)

{
  FID_conflict__Tidy(&DAT_100169cc,'\x01',0);
  return;
}



// Function: FUN_1000e233 at 1000e233

void FUN_1000e233(void)

{
  FID_conflict__Tidy(&DAT_10016940,'\x01',0);
  return;
}



// Function: FUN_1000e242 at 1000e242

void FUN_1000e242(void)

{
  FID_conflict__Tidy(&DAT_10016a24,'\x01',0);
  return;
}



// Function: FUN_1000e251 at 1000e251

void FUN_1000e251(void)

{
  FID_conflict__Tidy(&DAT_1001695c,'\x01',0);
  return;
}



// Function: FUN_1000e260 at 1000e260

void FUN_1000e260(void)

{
  FID_conflict__Tidy(&DAT_10016994,'\x01',0);
  return;
}



// Function: FUN_1000e26f at 1000e26f

void FUN_1000e26f(void)

{
  FID_conflict__Tidy(&DAT_10016a5c,'\x01',0);
  return;
}



// Function: FUN_1000e27e at 1000e27e

void FUN_1000e27e(void)

{
  FID_conflict__Tidy(&DAT_10016b04,'\x01',0);
  return;
}



// Function: FUN_1000e28d at 1000e28d

void FUN_1000e28d(void)

{
  FID_conflict__Tidy(&DAT_10016978,'\x01',0);
  return;
}



// Function: FUN_1000e29c at 1000e29c

void FUN_1000e29c(void)

{
  FID_conflict__Tidy(&DAT_100169b0,'\x01',0);
  return;
}



// Function: FUN_1000e2ab at 1000e2ab

void FUN_1000e2ab(void)

{
  FUN_1000b802(0x10016b28);
  return;
}



// Function: FUN_1000e2b5 at 1000e2b5

void FUN_1000e2b5(void)

{
  FUN_1000b85a((int *)&DAT_10016b60);
  return;
}



