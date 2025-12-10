/*
 * Decompiled from: TextFileStream.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10001000(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10001040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c1d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10001000(param_1);
  ExceptionList = local_10;
  return;
}



// Function: `vector_deleting_destructor' at 100010a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: void * __thiscall ATL::CComTypeInfoHolder::stringdispid::`vector deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2012 Debug */

void * __thiscall
ATL::CComTypeInfoHolder::stringdispid::_vector_deleting_destructor_(stringdispid *this,uint param_1)

{
  if ((param_1 & 2) == 0) {
    FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)this);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    _eh_vector_destructor_iterator_
              (this,0xc,*(int *)(this + -4),
               FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>);
    if ((param_1 & 1) != 0) {
      operator_delete__(this + -4);
    }
    this = this + -4;
  }
  return this;
}



// Function: FUN_10001120 at 10001120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10001120(LPCRITICAL_SECTION param_1,DWORD param_2)

{
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return;
}



// Function: FUN_10001150 at 10001150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10001150(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  IUnknown *pIVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ce12;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    pIVar1 = (IUnknown *)FUN_1001aa60(0x28);
    local_8._0_1_ = 1;
    if (pIVar1 != (IUnknown *)0x0) {
      FUN_10001e90(pIVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_10001213();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000120d at 1000120d

undefined * Catch_1000120d(void)

{
  return &DAT_1000121c;
}



// Function: FUN_10001213 at 10001213

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10001213(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_1000d3d0(*(void **)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 8));
    FUN_100099c0();
    uVar1 = FUN_1000ea50(*(int *)(unaff_EBP + -0x18) + 4);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_100086d0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_1000e9d0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    FUN_10009a10();
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10001310 at 10001310

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10001310(IUnknownVtbl *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == (IUnknownVtbl *)0x0) {
    local_8 = FUN_10008050(0,param_2,param_3);
  }
  else {
    local_8 = FUN_10007e90(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_10001360 at 10001360

undefined4 FUN_10001360(void)

{
  return 0;
}



// Function: FUN_10001370 at 10001370

void FUN_10001370(void)

{
  return;
}



// Function: FUN_10001380 at 10001380

undefined4 FUN_10001380(void)

{
  return 0;
}



// Function: FUN_10001390 at 10001390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001390(int param_1)

{
  FUN_1000e850((int *)&DAT_100298d4,0x65,param_1,(int *)0x0);
  return;
}



// Function: DllGetClassObject at 100013b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  undefined8 uVar1;
  
                    /* 0x13b0  2  DllGetClassObject */
  uVar1 = FUN_10008980(&DAT_100298d4,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)uVar1;
}



// Function: DllCanUnloadNow at 100013e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT DllCanUnloadNow(void)

{
  int iVar1;
  uint local_8;
  
                    /* 0x13e0  1  DllCanUnloadNow */
  iVar1 = FUN_10008e00(0x100298d4);
  local_8 = (uint)(iVar1 != 0);
  return local_8;
}



// Function: DllRegisterServer at 10001420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllRegisterServer(void)

{
                    /* 0x1420  3  DllRegisterServer */
  FUN_1000b9f0(&DAT_100298d4,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10001440

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void DllUnregisterServer(void)

{
                    /* 0x1440  4  DllUnregisterServer */
  FUN_1000d950(&DAT_100298d4,1,(void *)0x0);
  return;
}



// Function: FUN_10001460 at 10001460

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCSTR __cdecl FUN_10001460(LPSTR param_1)

{
  LPCSTR local_8;
  
  if (param_1 == (LPSTR)0x0) {
    local_8 = (LPCSTR)0x0;
  }
  else {
    local_8 = (LPCSTR)0x0;
    for (; *param_1 != '\0'; param_1 = CharNextA(param_1)) {
      if (*param_1 == '.') {
        local_8 = param_1;
      }
      else if (*param_1 == '\\') {
        local_8 = (LPCSTR)0x0;
      }
    }
    if (local_8 == (LPCSTR)0x0) {
      local_8 = param_1;
    }
  }
  return local_8;
}



// Function: FUN_10001500 at 10001500

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10001500(LPWSTR param_1)

{
  WCHAR WVar1;
  int iVar2;
  LPWSTR pWVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1 == (LPWSTR)0x0) {
    iVar2 = 0;
  }
  else {
    local_8 = param_1;
    local_c = param_1;
    while (*local_c != L'\0') {
      pWVar3 = CharNextW(local_c);
      if (((*local_c == L'\\') || (*local_c == L'/')) ||
         (WVar1 = *local_c, local_c = pWVar3, WVar1 == L':')) {
        local_c = pWVar3;
        local_8 = pWVar3;
      }
    }
    iVar2 = (int)local_8 - (int)param_1 >> 1;
  }
  return iVar2;
}



// Function: FUN_100015a0 at 100015a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_100015a0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_100097b0(&DAT_100298d4,0x10029000,param_1,(undefined4 *)&DAT_1001f99c);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_1000d700(0x100298d4);
  }
  return 1;
}



// Function: FUN_10001600 at 10001600

undefined4 __cdecl FUN_10001600(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10001610 at 10001610

undefined4 __cdecl FUN_10001610(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10001620 at 10001620

void FUN_10001620(void)

{
  return;
}



// Function: FUN_10001630 at 10001630

void FUN_10001630(void)

{
  return;
}



// Function: FUN_10001640 at 10001640

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10001640(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  IUnknown *pIVar2;
  undefined4 extraout_EDX;
  ulonglong uVar3;
  _GUID *p_Var4;
  
  puVar1 = (undefined4 *)FUN_10003d90(param_1);
  uVar3 = FUN_10009d00((int *)this,extraout_EDX,puVar1);
  if ((uVar3 & 0xff) == 0) {
    p_Var4 = (_GUID *)&DAT_1001f63c;
    pIVar2 = (IUnknown *)FUN_10003d90(param_1);
    ATL::AtlComQIPtrAssign((IUnknown **)this,pIVar2,p_Var4);
  }
  else {
    FUN_10003db0((undefined4 *)this);
  }
  return;
}



// Function: AtlAdd<> at 100016a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlAdd<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

HRESULT __cdecl AtlAdd<>(int *param_1,int param_2,uint param_3)

{
  HRESULT HVar1;
  
  if (-param_2 - 1U < param_3) {
    HVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  else {
    *param_1 = param_2 + param_3;
    HVar1 = 0;
  }
  return HVar1;
}



// Function: AtlAddThrow<unsigned_long> at 100016e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    unsigned long __cdecl ATL::AtlAddThrow<unsigned long>(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

ulong __cdecl ATL::AtlAddThrow<unsigned_long>(ulong param_1,ulong param_2)

{
  HRESULT HVar1;
  ulong local_c [2];
  
  local_c[0] = 0xcccccccc;
  local_c[1] = 0xcccccccc;
  HVar1 = AtlAdd<>((int *)local_c,param_1,param_2);
  if (HVar1 < 0) {
    FUN_10007680(HVar1);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10001740);
  return local_c[0];
}



// Function: AtlMultiply<int> at 10001760

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<int>(int *,int,int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

long __cdecl ATL::AtlMultiply<int>(int *param_1,int param_2,int param_3)

{
  long lVar1;
  longlong lVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  lVar2 = __allmul(param_2,param_2 >> 0x1f,param_3,param_3 >> 0x1f);
  local_8 = (uint)((ulonglong)lVar2 >> 0x20);
  if ((((int)local_8 < 1) && ((local_c = (uint)lVar2, lVar2 < 0 || (local_c < 0x80000000)))) &&
     ((local_8 < 0x80000000 || ((-2 < (int)local_8 && (0x7fffffff < local_c)))))) {
    *param_1 = local_c;
    lVar1 = 0;
  }
  else {
    lVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  return lVar1;
}



// Function: AtlMultiply<> at 100017e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlMultiply<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

HRESULT __cdecl AtlMultiply<>(undefined4 *param_1,uint param_2,uint param_3)

{
  HRESULT HVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_8 == 0) {
    local_c = (undefined4)((ulonglong)param_2 * (ulonglong)param_3);
    *param_1 = local_c;
    HVar1 = 0;
  }
  else {
    HVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  return HVar1;
}



// Function: AtlMultiply<unsigned_long> at 10001840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

long __cdecl ATL::AtlMultiply<unsigned_long>(ulong *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_8 == 0) {
    local_c = (ulong)((ulonglong)param_2 * (ulonglong)param_3);
    *param_1 = local_c;
    lVar1 = 0;
  }
  else {
    lVar1 = _HRESULT_FROM_WIN32(0x216);
  }
  return lVar1;
}



// Function: AtlMultiplyThrow<unsigned_int> at 100018a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  HRESULT HVar1;
  uint local_c [2];
  
  local_c[0] = 0xcccccccc;
  local_c[1] = 0xcccccccc;
  HVar1 = AtlMultiply<>(local_c,param_1,param_2);
  if (HVar1 < 0) {
    FUN_10007680(HVar1);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10001900);
  return local_c[0];
}



// Function: QueryInterface<> at 10001920

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: long __stdcall IUnknown::QueryInterface<struct IAccessor>(struct IAccessor * *)
    public: long __stdcall IUnknown::QueryInterface<struct IColumnsInfo>(struct IColumnsInfo * *)
    public: long __stdcall IUnknown::QueryInterface<struct IHTMLDocument2>(struct IHTMLDocument2 *
   *)
    public: long __stdcall IUnknown::QueryInterface<struct IHTMLElement>(struct IHTMLElement * *)
     7 names - too many to list
   
   Library: Visual Studio 2012 Debug */

void QueryInterface<>(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_1001f64c,param_2);
  return;
}



// Function: FUN_10001950 at 10001950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10001950(uint param_1)

{
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) && (local_8 = operator_new(param_1), local_8 == (void *)0x0)) {
    std::_Xbad_alloc();
  }
  return local_8;
}



// Function: FUN_100019b0 at 100019b0

undefined4 __cdecl FUN_100019b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100019c0 at 100019c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_100019c0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10001b50(param_2);
  FUN_10001ab0(this,param_1,uVar1);
  return;
}



// Function: FUN_10001a00 at 10001a00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001a00(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c211;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10003bb0(4,param_1);
  local_8 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_10001b50(param_2);
    *puVar1 = *puVar2;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001ab0 at 10001ab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10001ab0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10001b50(param_3);
  FUN_10001a00(param_2,uVar1);
  return;
}



// Function: FUN_10001ae0 at 10001ae0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001ae0(void)

{
  FUN_10001b30();
  return;
}



// Function: FUN_10001b10 at 10001b10

void FUN_10001b10(void)

{
  return;
}



// Function: FUN_10001b30 at 10001b30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10001b30(void)

{
  FUN_10001b10();
  return;
}



// Function: FUN_10001b50 at 10001b50

undefined4 __cdecl FUN_10001b50(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10001b60 at 10001b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10001b60(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c238;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002540(param_1);
  local_8 = 0;
  FUN_100098e0();
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001bd0 at 10001bd0

undefined4 * __fastcall FUN_10001bd0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001bf0 at 10001bf0

undefined4 * __fastcall FUN_10001bf0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001c10 at 10001c10

undefined4 * __fastcall FUN_10001c10(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001c30 at 10001c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __thiscall FUN_10001c30(void *this,IUnknownVtbl *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c276;
  local_10 = ExceptionList;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  IUnknown::IUnknown((IUnknown *)this);
  ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *)((int)this + 4));
  local_8 = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CTextFileStreamObj>::vftable;
  FUN_10001ce0((void *)((int)this + 0x10),param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*DAT_1002987c + 4))(uVar1);
  ExceptionList = local_10;
  return (IUnknown *)this;
}



// Function: FUN_10001ce0 at 10001ce0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __thiscall FUN_10001ce0(void *this,IUnknownVtbl *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c2a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000ffb0((IUnknown *)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CTextFileStreamObj>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CTextFileStreamObj>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CTextFileStreamObj>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CTextFileStreamObj>::vftable;
  *(IUnknownVtbl **)((int)this + 0x10) = param_1;
  ExceptionList = local_10;
  return (IUnknown *)this;
}



// Function: FUN_10001d80 at 10001d80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10001d80(void *this,undefined4 param_1,char param_2)

{
  int iVar1;
  
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  if (param_2 != '\0') {
    iVar1 = FUN_1000a220((undefined4 *)this);
    if (iVar1 < 0) {
      FUN_10007680(iVar1);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10001de0 at 10001de0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10001de0(IUnknown *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c2d8;
  local_10 = ExceptionList;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000ffb0(param_1);
  local_8 = 0;
  param_1->lpVtbl = (IUnknownVtbl *)ATL::CComObject<class_CTextFileStreamObj>::vftable;
  param_1[1].lpVtbl = (IUnknownVtbl *)ATL::CComObject<class_CTextFileStreamObj>::vftable;
  param_1[2].lpVtbl = (IUnknownVtbl *)ATL::CComObject<class_CTextFileStreamObj>::vftable;
  param_1[3].lpVtbl = (IUnknownVtbl *)ATL::CComObject<class_CTextFileStreamObj>::vftable;
  (**(code **)(*DAT_1002987c + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001e90 at 10001e90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10001e90(IUnknown *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c308;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002680(param_1);
  param_1->lpVtbl = (IUnknownVtbl *)ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001f00 at 10001f00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> * __fastcall
FUN_10001f00(CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c343;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>(param_1);
  local_8 = 0;
  ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *)(param_1 + 4));
  ExceptionList = local_10;
  return param_1;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10001f70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c368;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)this);
  ExceptionList = local_10;
  return this;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10001fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c398;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)this);
  ExceptionList = local_10;
  return this;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10002030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c3c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)this);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10002090 at 10002090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10002090(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c3f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CComPtrBase<>(this,*param_1);
  ExceptionList = local_10;
  return this;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10002100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c428;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)this);
  ExceptionList = local_10;
  return this;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10002160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c458;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)this);
  ExceptionList = local_10;
  return this;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 100021c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c488;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)this);
  ExceptionList = local_10;
  return this;
}



// Function: CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> at 10002220

/* Library Function - Single Match
    protected: __thiscall ATL::CHeapPtrBase<unsigned short,class
   ATL::CCRTAllocator>::CHeapPtrBase<unsigned short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  *(undefined4 *)this = 0;
  return this;
}



// Function: CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> at 10002240

/* Library Function - Single Match
    protected: __thiscall ATL::CHeapPtrBase<unsigned short,class
   ATL::CCRTAllocator>::CHeapPtrBase<unsigned short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  *(undefined4 *)this = 0;
  return this;
}



// Function: CComPtrBase<> at 10002260

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    protected: __thiscall ATL::CComPtrBase<struct IDispatch>::CComPtrBase<struct IDispatch>(struct
   IDispatch *)
    protected: __thiscall ATL::CComPtrBase<struct IHTMLDocument2>::CComPtrBase<struct
   IHTMLDocument2>(struct IHTMLDocument2 *)
    protected: __thiscall ATL::CComPtrBase<struct IHTMLOptionButtonElement>::CComPtrBase<struct
   IHTMLOptionButtonElement>(struct IHTMLOptionButtonElement *)
    protected: __thiscall ATL::CComPtrBase<struct IHTMLOptionElement>::CComPtrBase<struct
   IHTMLOptionElement>(struct IHTMLOptionElement *)
     17 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

int * __thiscall CComPtrBase<>(void *this,int param_1)

{
  *(int *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**this + 4))(*this);
  }
  return (int *)this;
}



// Function: CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> at 100022b0

/* Library Function - Single Match
    protected: __thiscall ATL::CHeapPtrBase<unsigned short,class
   ATL::CCRTAllocator>::CHeapPtrBase<unsigned short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  *(undefined4 *)this = 0;
  return this;
}



// Function: CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> at 100022d0

/* Library Function - Single Match
    protected: __thiscall ATL::CHeapPtrBase<unsigned short,class
   ATL::CCRTAllocator>::CHeapPtrBase<unsigned short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  *(undefined4 *)this = 0;
  return this;
}



// Function: CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> at 100022f0

/* Library Function - Single Match
    protected: __thiscall ATL::CHeapPtrBase<unsigned short,class
   ATL::CCRTAllocator>::CHeapPtrBase<unsigned short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  *(undefined4 *)this = 0;
  return this;
}



// Function: FUN_10002310 at 10002310

undefined4 * __fastcall FUN_10002310(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_10002350 at 10002350

undefined4 * __fastcall FUN_10002350(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002370 at 10002370

undefined4 * __fastcall FUN_10002370(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002390 at 10002390

undefined4 * __fastcall FUN_10002390(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100023b0 at 100023b0

undefined4 * __thiscall FUN_100023b0(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_100023e0 at 100023e0

undefined4 * __thiscall FUN_100023e0(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10002410 at 10002410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10002410(int param_1)

{
  FUN_10002440(param_1);
  return param_1;
}



// Function: FUN_10002440 at 10002440

int __fastcall FUN_10002440(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_10002470 at 10002470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10002470(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: IUnknown at 100024a0

/* Library Function - Single Match
    public: __thiscall IUnknown::IUnknown(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

IUnknown * __thiscall IUnknown::IUnknown(IUnknown *this)

{
  return this;
}



// Function: FUN_100024c0 at 100024c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_100024c0(char *param_1)

{
  undefined1 local_c [4];
  void *local_8;
  
  local_c = (undefined1  [4])0xcccccccc;
  IUnknown::IUnknown((IUnknown *)(local_c + 3));
  FUN_10002410((int)local_8);
  FUN_1000f140(local_8,'\0',0);
  FUN_1000f3d0(local_8,param_1);
  return local_8;
}



// Function: FUN_10002520 at 10002520

undefined4 * __thiscall FUN_10002520(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10002540 at 10002540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10002540(int param_1)

{
  HRESULT HVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c4bb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)(param_1 + 4));
  local_8 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1002987c = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  HVar1 = FUN_10009720((LPCRITICAL_SECTION)(param_1 + 0x10));
  if (HVar1 < 0) {
    DAT_10029890 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10002600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c4e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100027d0((CComCriticalSection *)this);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10002660 at 10002660

undefined4 * __fastcall FUN_10002660(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002680 at 10002680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10002680(IUnknown *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c51b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002a40(param_1);
  FUN_10001f00((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)(param_1 + 1));
  param_1->lpVtbl = (IUnknownVtbl *)ATL::CComClassFactory::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: CComCriticalSection at 10002700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CComCriticalSection::CComCriticalSection(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CComCriticalSection * __thiscall
ATL::CComCriticalSection::CComCriticalSection(CComCriticalSection *this)

{
  memset(this,0,0x18);
  return this;
}



// Function: FUN_10002730 at 10002730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10002730(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c548;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001b60((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10029894 = param_1;
  ExceptionList = local_10;
  return param_1;
}



// Function: CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> at 100027b0

/* Library Function - Single Match
    protected: __thiscall ATL::CHeapPtrBase<unsigned short,class
   ATL::CCRTAllocator>::CHeapPtrBase<unsigned short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  *(undefined4 *)this = 0;
  return this;
}



// Function: FUN_100027d0 at 100027d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

CComCriticalSection * __fastcall FUN_100027d0(CComCriticalSection *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c578;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CComCriticalSection::CComCriticalSection(param_1);
  param_1[0x18] = (CComCriticalSection)0x0;
  ExceptionList = local_10;
  return param_1;
}



// Function: CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10002840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> * __thiscall
ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
          (CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c5a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002310((undefined4 *)this);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100028a0 at 100028a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100028a0(void *this,int param_1)

{
  void *pvVar1;
  
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  pvVar1 = ATL::AtlCoTaskMemCAlloc(*(ulong *)((int)this + 4),1);
  *(void **)((int)this + 8) = pvVar1;
  if (*(int *)((int)this + 8) != 0) {
    **(undefined1 **)((int)this + 8) = 0;
  }
  return (undefined4 *)this;
}



// Function: CRegKey at 10002910

/* Library Function - Single Match
    public: __thiscall ATL::CRegKey::CRegKey(struct HKEY__ *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

CRegKey * __thiscall ATL::CRegKey::CRegKey(CRegKey *this,HKEY__ *param_1)

{
  *(HKEY__ **)this = param_1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}



// Function: CRegKey at 10002950

/* Library Function - Single Match
    public: __thiscall ATL::CRegKey::CRegKey(class ATL::CAtlTransactionManager *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

CRegKey * __thiscall ATL::CRegKey::CRegKey(CRegKey *this,CAtlTransactionManager *param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(CAtlTransactionManager **)(this + 8) = param_1;
  return this;
}



// Function: FUN_10002990 at 10002990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10002990(IUnknown *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c5db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002a70(param_1);
  param_1->lpVtbl = (IUnknownVtbl *)ATL::CRegObject::vftable;
  ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            ((CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *)(param_1 + 1));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002a10 at 10002a10

undefined4 * __thiscall FUN_10002a10(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)this = 0;
  return (undefined4 *)this;
}



// Function: FUN_10002a40 at 10002a40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10002a40(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: FUN_10002a70 at 10002a70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10002a70(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: IUnknown at 10002aa0

/* Library Function - Single Match
    public: __thiscall IUnknown::IUnknown(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

IUnknown * __thiscall IUnknown::IUnknown(IUnknown *this)

{
  return this;
}



// Function: _ATL_COM_MODULE70 at 10002ac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

_ATL_COM_MODULE70 * __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c60b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CComCriticalSection::CComCriticalSection((CComCriticalSection *)(this + 0xc));
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10002b30 at 10002b30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002b30(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c638;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002c80(param_1);
  *param_1 = std::_Generic_error_category::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002ba0 at 10002ba0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002ba0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002b30(param_1);
  *param_1 = std::_Iostream_error_category::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002c10 at 10002c10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002c10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c698;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002b30(param_1);
  *param_1 = std::_System_error_category::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002c80 at 10002c80

undefined4 * __fastcall FUN_10002c80(undefined4 *param_1)

{
  *param_1 = std::error_category::vftable;
  return param_1;
}



// Function: FUN_10002ca0 at 10002ca0

undefined4 * __thiscall FUN_10002ca0(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  return (undefined4 *)this;
}



// Function: FUN_10002cd0 at 10002cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10002cd0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c6c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002660(param_1);
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  ExceptionList = local_10;
  return param_1;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10002d50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall
FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(CPropertySet *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c6f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  CPropertySet::~CPropertySet(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> at 10002db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::~CAtlSafeAllocBufferManager<class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
          (CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *this)

{
  void *pvVar1;
  
  while (*(int *)this != 0) {
    pvVar1 = *(void **)this;
    *(undefined4 *)this = **(undefined4 **)this;
    FUN_10008890(pvVar1);
  }
  return;
}



// Function: ~CAutoVectorPtr<> at 10002e00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CAutoVectorPtr<char>::~CAutoVectorPtr<char>(void)
    public: __thiscall ATL::CAutoVectorPtr<unsigned short>::~CAutoVectorPtr<unsigned short>(void)
    public: __thiscall ATL::CAutoVectorPtr<int>::~CAutoVectorPtr<int>(void)
    public: __thiscall ATL::CAutoVectorPtr<unsigned long>::~CAutoVectorPtr<unsigned long>(void)
     9 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall ~CAutoVectorPtr<>(undefined4 *param_1)

{
  Free(param_1);
  return;
}



// Function: ~CAutoVectorPtr<> at 10002e30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CAutoVectorPtr<char>::~CAutoVectorPtr<char>(void)
    public: __thiscall ATL::CAutoVectorPtr<unsigned short>::~CAutoVectorPtr<unsigned short>(void)
    public: __thiscall ATL::CAutoVectorPtr<int>::~CAutoVectorPtr<int>(void)
    public: __thiscall ATL::CAutoVectorPtr<unsigned long>::~CAutoVectorPtr<unsigned long>(void)
     9 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall ~CAutoVectorPtr<>(undefined4 *param_1)

{
  Free(param_1);
  return;
}



// Function: FUN_10002e60 at 10002e60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10002e60(_ATL_WIN_MODULE70 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001c736;
  local_10 = ExceptionList;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = ATL::CComAggObject<class_CTextFileStreamObj>::vftable;
  local_8 = 1;
  *(undefined4 *)(param_1 + 4) = 0xc0000001;
  ATL::_ATL_WIN_MODULE70::~_ATL_WIN_MODULE70(param_1);
  (**(code **)(*DAT_1002987c + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int)(param_1 + 0x10));
  local_8 = 0xffffffff;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10002f10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c768;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10010090(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002f70 at 10002f70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10002f70(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_1000d7e0(param_1);
  }
  return;
}



// Function: FUN_10002fa0 at 10002fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10002fa0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c798;
  local_10 = ExceptionList;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CTextFileStreamObj>::vftable;
  param_1[1] = ATL::CComObject<class_CTextFileStreamObj>::vftable;
  param_1[2] = ATL::CComObject<class_CTextFileStreamObj>::vftable;
  param_1[3] = ATL::CComObject<class_CTextFileStreamObj>::vftable;
  local_8 = 0;
  param_1[4] = 0xc0000001;
  ATL::CComCriticalSection::~CComCriticalSection((CComCriticalSection *)(param_1 + 4));
  (**(code **)(*DAT_1002987c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10010090((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003060 at 10003060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003060(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c7c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  ATL::CComCriticalSection::~CComCriticalSection((CComCriticalSection *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10003710(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100030e0 at 100030e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100030e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c803;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((LPCRITICAL_SECTION)(param_1 + 4))
  ;
  local_8 = 0xffffffff;
  FUN_10003810();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10003150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c828;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003810();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 100031b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c858;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10003210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c888;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10003270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c8b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 100032d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c8e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10003330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c918;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CComPtrBase<struct_IAccessibleProxy> at 10003390

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CComPtrBase<struct IAccessibleProxy>::~CComPtrBase<struct
   IAccessibleProxy>(void)
    public: __thiscall ATL::CComPtrBase<struct IApplicationDestinations>::~CComPtrBase<struct
   IApplicationDestinations>(void)
    public: __thiscall ATL::CComPtrBase<struct IBindCtx>::~CComPtrBase<struct IBindCtx>(void)
    public: __thiscall ATL::CComPtrBase<struct IColumnsInfo>::~CComPtrBase<struct
   IColumnsInfo>(void)
     85 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CComPtrBase<struct_IAccessibleProxy>(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FID_conflict:~CComPtrBase<struct_IAccessibleProxy> at 100033e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CComPtrBase<struct IAccessibleProxy>::~CComPtrBase<struct
   IAccessibleProxy>(void)
    public: __thiscall ATL::CComPtrBase<struct IApplicationDestinations>::~CComPtrBase<struct
   IApplicationDestinations>(void)
    public: __thiscall ATL::CComPtrBase<struct IBindCtx>::~CComPtrBase<struct IBindCtx>(void)
    public: __thiscall ATL::CComPtrBase<struct IColumnsInfo>::~CComPtrBase<struct
   IColumnsInfo>(void)
     85 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CComPtrBase<struct_IAccessibleProxy>(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FID_conflict:~CComPtrBase<struct_IAccessibleProxy> at 10003430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CComPtrBase<struct IAccessibleProxy>::~CComPtrBase<struct
   IAccessibleProxy>(void)
    public: __thiscall ATL::CComPtrBase<struct IApplicationDestinations>::~CComPtrBase<struct
   IApplicationDestinations>(void)
    public: __thiscall ATL::CComPtrBase<struct IBindCtx>::~CComPtrBase<struct IBindCtx>(void)
    public: __thiscall ATL::CComPtrBase<struct IColumnsInfo>::~CComPtrBase<struct
   IColumnsInfo>(void)
     85 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CComPtrBase<struct_IAccessibleProxy>(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FID_conflict:~CComPtrBase<struct_IAccessibleProxy> at 10003480

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CComPtrBase<struct IAccessibleProxy>::~CComPtrBase<struct
   IAccessibleProxy>(void)
    public: __thiscall ATL::CComPtrBase<struct IApplicationDestinations>::~CComPtrBase<struct
   IApplicationDestinations>(void)
    public: __thiscall ATL::CComPtrBase<struct IBindCtx>::~CComPtrBase<struct IBindCtx>(void)
    public: __thiscall ATL::CComPtrBase<struct IColumnsInfo>::~CComPtrBase<struct
   IColumnsInfo>(void)
     85 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CComPtrBase<struct_IAccessibleProxy>(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FID_conflict:~CComPtrBase<struct_IAccessibleProxy> at 100034d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CComPtrBase<struct IAccessibleProxy>::~CComPtrBase<struct
   IAccessibleProxy>(void)
    public: __thiscall ATL::CComPtrBase<struct IApplicationDestinations>::~CComPtrBase<struct
   IApplicationDestinations>(void)
    public: __thiscall ATL::CComPtrBase<struct IBindCtx>::~CComPtrBase<struct IBindCtx>(void)
    public: __thiscall ATL::CComPtrBase<struct IColumnsInfo>::~CComPtrBase<struct
   IColumnsInfo>(void)
     85 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CComPtrBase<struct_IAccessibleProxy>(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10003520 at 10003520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003520(int *param_1)

{
  FUN_1000c730(param_1);
  return;
}



// Function: ~CTempBuffer<> at 10003550

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 10003590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 100035d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: OnInitialUpdate at 10003610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: void __thiscall CControlBar::OnInitialUpdate(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall CControlBar::OnInitialUpdate(CControlBar *this)

{
  FUN_1000f140(this,'\x01',0);
  return;
}



// Function: ~CPropertySet at 10003640

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall CPropertySet::~CPropertySet(void)
   
   Library: Visual Studio 2012 Debug */

void __thiscall CPropertySet::~CPropertySet(CPropertySet *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c94b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000d610((int)this);
  local_8 = 0xffffffff;
  ATL::_ATL_COM_MODULE70::~_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)(this + 4));
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 100036b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall
FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c978;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003830(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003710 at 10003710

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003710(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c9ab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  FUN_100030e0((int)(param_1 + 1));
  ExceptionList = local_10;
  return;
}



// Function: ~CComCriticalSection at 10003780

/* Library Function - Single Match
    public: __thiscall ATL::CComCriticalSection::~CComCriticalSection(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __thiscall ATL::CComCriticalSection::~CComCriticalSection(CComCriticalSection *this)

{
  return;
}



// Function: FUN_100037a0 at 100037a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100037a0(CPropertySet *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003810 at 10003810

void FUN_10003810(void)

{
  return;
}



// Function: FUN_10003830 at 10003830

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003830(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    FUN_1000d6c0(param_1);
  }
  local_8 = 0xffffffff;
  ATL::CComCriticalSection::~CComCriticalSection((CComCriticalSection *)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CPaneContainerGC at 100038b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CAtlComModule::~CAtlComModule(void)
    public: __thiscall CPaneContainerGC::~CPaneContainerGC(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CPaneContainerGC(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10007c20(param_1);
  local_8 = 0xffffffff;
  FUN_10003520(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003920 at 10003920

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003920(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: ~CRegKey at 10003960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CRegKey::~CRegKey(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __thiscall ATL::CRegKey::~CRegKey(CRegKey *this)

{
  Close(this);
  return;
}



// Function: FUN_10003990 at 10003990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003990(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca6b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  FUN_10007cb0((int)param_1);
  local_8 = 0xffffffff;
  FID_conflict__CPaneContainerGC(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: ~_ATL_COM_MODULE70 at 10003a10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::~_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __thiscall ATL::_ATL_COM_MODULE70::~_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ca9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  CComCriticalSection::~CComCriticalSection((CComCriticalSection *)(this + 0xc));
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10003a70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cac8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CRectTracker(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10003ad0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001caf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> at 10003b30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CHeapPtr<unsigned short,class ATL::CCRTAllocator>::~CHeapPtr<unsigned
   short,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CStringT<unsigned short,class ATL::StrTraitATL<unsigned short,class
   ATL::ChTraitsCRT<unsigned short> > >::~CStringT<unsigned short,class ATL::StrTraitATL<unsigned
   short,class ATL::ChTraitsCRT<unsigned short> > >(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001cb28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CRectTracker at 10003b90

/* Library Function - Multiple Matches With Different Base Names
    protected: virtual __thiscall CDialogImpl::~CDialogImpl(void)
    public: virtual __thiscall ATL::CFixedStringMgr::~CFixedStringMgr(void)
    public: virtual __thiscall CGlobalUtils::~CGlobalUtils(void)
    public: virtual __thiscall CMFCControlBarImpl::~CMFCControlBarImpl(void)
     15 names - too many to list
   
   Library: Visual Studio 2012 Debug */

void __fastcall FID_conflict__CRectTracker(undefined4 *param_1)

{
  *param_1 = std::error_category::vftable;
  return;
}



// Function: FUN_10003bb0 at 10003bb0

undefined4 __cdecl FUN_10003bb0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10003bc0 at 10003bc0

void FUN_10003bc0(void)

{
  return;
}



// Function: operator! at 10003bd0

/* Library Function - Single Match
    public: bool __thiscall ATL::CComBSTR::operator!(void)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

bool __thiscall ATL::CComBSTR::operator!(CComBSTR *this)

{
  return *(int *)this == 0;
}



// Function: FUN_10003c10 at 10003c10

bool __thiscall FUN_10003c10(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_10003c50 at 10003c50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10003c50(CComBSTR *param_1)

{
  ATL::CComBSTR::operator!(param_1);
  return;
}



// Function: FUN_10003c80 at 10003c80

bool __thiscall FUN_10003c80(void *this,int param_1)

{
  return this == (void *)param_1;
}



// Function: FUN_10003cc0 at 10003cc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined1 __thiscall FUN_10003cc0(void *this,undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  
  iVar2 = FUN_1000f4d0((int)param_1);
  this_00 = (void *)FUN_1000f4d0((int)this);
  bVar1 = FUN_10003c80(this_00,iVar2);
  if (bVar1) {
    iVar2 = FUN_1000fdc0((undefined4 *)this);
    iVar3 = FUN_1000fdc0(param_1);
    if (iVar2 == iVar3) {
      return 1;
    }
  }
  return 0;
}



// Function: FID_conflict:operator!= at 10003d40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: bool __thiscall ATL::CComPtrBase<struct IApplicationDestinations>::operator!=(struct
   IApplicationDestinations *)const 
    public: bool __thiscall ATL::CComPtrBase<struct IChapteredRowset>::operator!=(struct
   IChapteredRowset *)const 
    public: bool __thiscall ATL::CComPtrBase<struct ICustomDestinationList>::operator!=(struct
   ICustomDestinationList *)const 
    public: bool __thiscall ATL::CComPtrBase<struct IDispatch>::operator!=(struct IDispatch *)const 
     34 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

bool __fastcall FID_conflict_operator__(CComBSTR *param_1)

{
  char cVar1;
  
  cVar1 = FUN_10003c50(param_1);
  return cVar1 == '\0';
}



// Function: FUN_10003d90 at 10003d90

undefined4 __fastcall FUN_10003d90(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003db0 at 10003db0

undefined4 __fastcall FUN_10003db0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003dd0 at 10003dd0

undefined4 __fastcall FUN_10003dd0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003df0 at 10003df0

undefined4 __fastcall FUN_10003df0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003e10 at 10003e10

undefined4 __fastcall FUN_10003e10(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003e30 at 10003e30

undefined4 __fastcall FUN_10003e30(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003e50 at 10003e50

undefined4 __fastcall FUN_10003e50(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003e70 at 10003e70

undefined4 __fastcall FUN_10003e70(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003e90 at 10003e90

undefined4 __fastcall FUN_10003e90(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003eb0 at 10003eb0

undefined4 __fastcall FUN_10003eb0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003ed0 at 10003ed0

undefined4 __fastcall FUN_10003ed0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003ef0 at 10003ef0

undefined4 __fastcall FUN_10003ef0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003f10 at 10003f10

undefined4 __fastcall FUN_10003f10(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003f30 at 10003f30

undefined4 __fastcall FUN_10003f30(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003f50 at 10003f50

undefined4 __fastcall FUN_10003f50(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003f70 at 10003f70

undefined4 __fastcall FUN_10003f70(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003f90 at 10003f90

undefined4 __fastcall FUN_10003f90(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003fb0 at 10003fb0

undefined4 __fastcall FUN_10003fb0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003fd0 at 10003fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

_ATL_WIN_MODULE70 * __thiscall FUN_10003fd0(void *this,uint param_1)

{
  FUN_10002e60((_ATL_WIN_MODULE70 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (_ATL_WIN_MODULE70 *)this;
}



// Function: FUN_10004010 at 10004010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10004010(void *this,uint param_1)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10004050 at 10004050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004050(void *this,uint param_1)

{
  FUN_10002fa0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004090 at 10004090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004090(void *this,uint param_1)

{
  FUN_10003060((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100040d0 at 100040d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100040d0(void *this,uint param_1)

{
  FUN_10003710((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004110 at 10004110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

CPropertySet * __thiscall FUN_10004110(void *this,uint param_1)

{
  FUN_100037a0((CPropertySet *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (CPropertySet *)this;
}



// Function: FUN_10004150 at 10004150

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004150(void *this,uint param_1)

{
  FUN_10003990((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004190 at 10004190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004190(void *this,uint param_1)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100041d0 at 100041d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100041d0(void *this,uint param_1)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004210 at 10004210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10004210(void *this,uint param_1)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FID_conflict:`scalar_deleting_destructor' at 10004250

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    protected: virtual void * __thiscall CDialogImpl::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall ATL::CFixedStringMgr::`scalar deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall CGlobalUtils::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall CMFCControlBarImpl::`scalar deleting destructor'(unsigned int)
     15 names - too many to list
   
   Library: Visual Studio 2012 Debug */

undefined4 * __thiscall FID_conflict__scalar_deleting_destructor_(void *this,uint param_1)

{
  FID_conflict__CRectTracker((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004290 at 10004290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10004290(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10009b00(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}



// Function: FUN_10004360 at 10004360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10004360(void *param_1,undefined4 param_2,char *param_3,wchar_t *param_4)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  uint *puVar4;
  uint local_60 [2];
  void *local_58;
  void *local_54;
  undefined4 local_4c [3];
  void *local_40 [2];
  uint local_38;
  undefined4 local_30 [3];
  void *local_24 [2];
  uint local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cb60;
  local_10 = ExceptionList;
  puVar4 = local_60;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  ExceptionList = &local_10;
  local_14 = param_1;
  if ((param_3 == (char *)0x0) || (param_4 == (wchar_t *)0x0)) {
    uVar2 = 0;
  }
  else {
    local_18 = 0;
    sVar1 = strlen(param_3);
    local_1c = sVar1 + 1;
    local_24[0] = (void *)0x0;
    local_54 = (void *)FUN_1001aa8e(local_1c);
    local_24[0] = local_54;
    FUN_10001bf0(local_30);
    local_8 = 0;
    FUN_100079a0(local_30,local_24[0]);
    sVar1 = FUN_1000fc90(param_4);
    local_38 = sVar1 * 2 + 2;
    local_40[0] = (void *)0x0;
    local_58 = (void *)FUN_1001aa8e(-(uint)((int)((ulonglong)local_38 * 2 >> 0x20) != 0) |
                                    (uint)((ulonglong)local_38 * 2));
    local_40[0] = local_58;
    FUN_10001c10(local_4c);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_100079c0(local_4c,local_40[0]);
    if ((local_24[0] == (void *)0x0) || (local_40[0] == (void *)0x0)) {
      local_18 = -0x7ff8fff2;
    }
    else {
      FUN_1000f920(local_24[0],local_1c,param_3,local_1c);
      FUN_1000f920(local_40[0],local_38,param_4,local_38);
      iVar3 = FUN_10004290(local_14,local_24,local_40);
      if (iVar3 == 0) {
        local_18 = -0x7ff8fff2;
      }
    }
    if (-1 < local_18) {
      FUN_100083a0(local_30);
      FUN_100083d0(local_4c);
    }
    local_60[0] = (uint)(-1 < local_18);
    local_60[1] = local_60[0];
    local_8 = local_8 & 0xffffff00;
    ~CAutoVectorPtr<>(local_4c);
    local_8 = 0xffffffff;
    ~CAutoVectorPtr<>(local_30);
    uVar2 = local_60[1];
    param_2 = extraout_EDX;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10004544);
  ExceptionList = local_10;
  return CONCAT44(param_2,uVar2);
}



// Function: FUN_100045a0 at 100045a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_100045a0(void *this,LPCSTR param_1)

{
  LPSTR pCVar1;
  undefined8 uVar2;
  
  pCVar1 = CharNextA(param_1);
  uVar2 = FUN_10005770(this,param_1,(int)pCVar1 - (int)param_1);
  return uVar2;
}



// Function: FUN_10004600 at 10004600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10004600(int *param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_10008970();
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",ppuVar1);
  return;
}



// Function: FUN_10004650 at 10004650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10004650(int param_1)

{
  FUN_10009990((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10004670 at 10004670

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10004670(int param_1)

{
  FUN_1000a700((undefined4 *)(param_1 + 0x10));
  return;
}



// Function: FUN_10004689 at 10004689

void FUN_10004689(int param_1)

{
  FUN_10004670(param_1 + -4);
  return;
}



// Function: FUN_10004693 at 10004693

void FUN_10004693(int param_1)

{
  FUN_10004670(param_1 + -8);
  return;
}



// Function: FUN_1000469d at 1000469d

void FUN_1000469d(int param_1)

{
  FUN_10004670(param_1 + -0xc);
  return;
}



// Function: FUN_100046b0 at 100046b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100046b0(int param_1)

{
  FUN_10009960((LONG *)(param_1 + 0x10));
  return;
}



// Function: FUN_100046c9 at 100046c9

void FUN_100046c9(int param_1)

{
  FUN_100046b0(param_1 + -4);
  return;
}



// Function: FUN_100046d3 at 100046d3

void FUN_100046d3(int param_1)

{
  FUN_100046b0(param_1 + -8);
  return;
}



// Function: FUN_100046dd at 100046dd

void FUN_100046dd(int param_1)

{
  FUN_100046b0(param_1 + -0xc);
  return;
}



// Function: FUN_100046f0 at 100046f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_100046f0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009960((LONG *)(param_1 + 4));
  if (iVar1 == 2) {
    (**(code **)(*DAT_1002987c + 4))();
  }
  return iVar1;
}



// Function: FUN_10004740 at 10004740

undefined4 FUN_10004740(void)

{
  return 1;
}



// Function: FUN_10004750 at 10004750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10004750(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPSTR *ppCVar7;
  undefined8 uVar8;
  LPSTR local_6c [3];
  int local_60;
  LPSTR local_5c;
  LPSTR local_58;
  _RTC_ALLOCA_NODE *local_50 [2];
  LPSTR local_48;
  undefined4 local_44;
  int local_40;
  LPSTR local_3c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_34 [12];
  wchar_t *local_28;
  UINT local_24;
  ulong local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cb88;
  local_10 = ExceptionList;
  ppCVar7 = local_6c;
  for (iVar6 = 0x17; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50[0] = (_RTC_ALLOCA_NODE *)0x0;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    FUN_1000a2e0();
    local_24 = FUN_1000e9f0();
    FUN_10001bd0((undefined4 *)local_34);
    local_8 = 0;
    local_28 = param_2;
    if (param_2 == (wchar_t *)0x0) {
      local_58 = (LPSTR)0x0;
    }
    else {
      sVar4 = wcslen(param_2);
      local_1c[0] = sVar4 + 1;
      lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
      if (lVar5 < 0) {
        local_5c = (LPSTR)0x0;
      }
      else {
        if (((int)local_1c[0] < 0x401) && (cVar3 = FUN_1000eae0(local_1c[0]), cVar3 != '\0')) {
          local_60 = local_1c[0] + 0x24;
          iVar6 = -(local_1c[0] + 0x24);
          local_6c[2] = &stack0xffffff84;
          *(_RTC_ALLOCA_NODE ***)((int)local_6c + iVar6 + -0x14) = local_50;
          iVar2 = local_60;
          pCVar1 = local_6c[2];
          *(undefined4 *)((int)local_6c + iVar6 + -0x18) = 0x1000485a;
          _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_6c + iVar6 + -0x14));
          local_6c[1] = local_6c[2] + 0x20;
          local_6c[2] = local_6c[1];
        }
        else {
          local_6c[1] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                               CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                         (local_34,local_1c[0]);
        }
        local_5c = FUN_10007930(local_6c[1],local_28,local_1c[0],local_24);
      }
      local_58 = local_5c;
    }
    local_3c = local_58;
    if (local_58 == (LPSTR)0x0) {
      local_44 = 0x8007000e;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
    }
    else {
      uVar8 = FUN_10004360((void *)(param_1 + 4),local_58,local_58,param_3);
      local_40 = (int)uVar8;
      FUN_1000d890();
      if (local_40 == 0) {
        local_6c[0] = (LPSTR)0x8007000e;
      }
      else {
        local_6c[0] = (LPSTR)0x0;
      }
      local_48 = local_6c[0];
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
    }
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10004940,local_50[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100049a0 at 100049a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_100049a0(void *this,wchar_t *param_1)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  size_t sVar5;
  int iVar6;
  LPSTR *ppCVar7;
  undefined8 uVar8;
  LPSTR local_68 [2];
  int local_60;
  LPSTR local_5c;
  char *local_58;
  _RTC_ALLOCA_NODE *local_50 [2];
  undefined4 local_48;
  undefined4 local_44;
  char *local_40;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_38 [12];
  wchar_t *local_2c;
  UINT local_28;
  ulong local_20 [2];
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cbb8;
  local_10 = ExceptionList;
  ppCVar7 = local_68;
  for (iVar6 = 0x16; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_18 = this;
  if (param_1 != (wchar_t *)0x0) {
    local_28 = FUN_1000e9f0();
    FUN_10001bd0((undefined4 *)local_38);
    local_8 = 0;
    local_2c = param_1;
    if (param_1 == (wchar_t *)0x0) {
      local_58 = (char *)0x0;
    }
    else {
      sVar5 = wcslen(param_1);
      local_20[0] = sVar5 + 1;
      lVar4 = ATL::AtlMultiply<int>((int *)local_20,local_20[0],2);
      if (lVar4 < 0) {
        local_5c = (LPSTR)0x0;
      }
      else {
        if (((int)local_20[0] < 0x401) && (cVar3 = FUN_1000eae0(local_20[0]), cVar3 != '\0')) {
          local_60 = local_20[0] + 0x24;
          iVar6 = -(local_20[0] + 0x24);
          local_68[1] = &stack0xffffff88;
          *(_RTC_ALLOCA_NODE ***)((int)local_68 + iVar6 + -0x14) = local_50;
          iVar2 = local_60;
          pCVar1 = local_68[1];
          *(undefined4 *)((int)local_68 + iVar6 + -0x18) = 0x10004a9b;
          _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_68 + iVar6 + -0x14));
          local_68[0] = local_68[1] + 0x20;
          local_68[1] = local_68[0];
        }
        else {
          local_68[0] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                               CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                         (local_38,local_20[0]);
        }
        local_5c = FUN_10007930(local_68[0],local_2c,local_20[0],local_28);
      }
      local_58 = local_5c;
    }
    local_40 = local_58;
    if (local_58 == (char *)0x0) {
      local_44 = 0;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_38);
    }
    else {
      sVar5 = strlen(local_58);
      uVar8 = FUN_10005770(local_18,local_40,sVar5);
      local_48 = (undefined4)uVar8;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_38);
    }
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10004b60,local_50[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004bc0 at 10004bc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10004bc0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined4 local_c;
  
  if (this == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = (int)this + 4;
  }
  uVar1 = FUN_10006a40(param_2,param_1,local_c,param_1,param_2);
  return uVar1;
}



// Function: FUN_10004c10 at 10004c10

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_10004c10(void *this,void *param_1,LPCSTR param_2,undefined1 *param_3)

{
  LPWSTR pWVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPCSTR unaff_EDI;
  LPWSTR *ppWVar7;
  uint uStack_12e4;
  LPWSTR local_12d4 [3];
  int iStack_12c8;
  LPWSTR pWStack_12c4;
  LPWSTR pWStack_12c0;
  uint local_12bc;
  _RTC_ALLOCA_NODE *local_12b4 [3];
  undefined4 uStack_12a8;
  undefined4 auStack_129c [66];
  uint uStack_1194;
  size_t sStack_1190;
  LPWSTR pWStack_118c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> aCStack_1184 [8];
  BYTE *pBStack_117c;
  UINT UStack_1174;
  ulong auStack_116c [9];
  undefined4 local_1148 [66];
  uint local_1040;
  undefined4 local_103c;
  ulong local_1038;
  ushort local_1030 [6];
  BYTE local_1024 [4100];
  int local_20;
  undefined4 *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cc01;
  local_10 = ExceptionList;
  ppWVar7 = local_12d4;
  for (iVar6 = 0x4b0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppWVar7 = (LPWSTR)0xcccccccc;
    ppWVar7 = ppWVar7 + 1;
  }
  uStack_12e4 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_12e4;
  ExceptionList = &local_10;
  local_12b4[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_1030[0] = 0;
  local_1038 = 0;
  local_103c = 0;
  local_1c = (undefined4 *)this;
  local_18 = uStack_12e4;
  local_20 = FUN_1000a3b0(this,local_1024);
  if (-1 < local_20) {
    iVar6 = FUN_1000e8b0((LPCSTR)local_1024,local_1030);
    if (iVar6 == 0) {
      FUN_10008950();
    }
    else {
      FUN_1000d4f0(local_1c);
      local_20 = FUN_1000a3b0(local_1c,local_1024);
      if (-1 < local_20) {
        local_12bc = (uint)local_1030[0];
        if (local_12bc < 0x14) {
          if (local_12bc == 0x13) {
            UStack_1174 = FUN_1000e9f0();
            FUN_10001bd0((undefined4 *)aCStack_1184);
            local_8 = 3;
            pBStack_117c = local_1024;
            if (pBStack_117c == (BYTE *)0x0) {
              pWStack_12c0 = (LPWSTR)0x0;
            }
            else {
              sVar4 = strlen((char *)pBStack_117c);
              auStack_116c[0] = sVar4 + 1;
              lVar5 = ATL::AtlMultiply<int>((int *)auStack_116c,auStack_116c[0],2);
              if (lVar5 < 0) {
                pWStack_12c4 = (LPWSTR)0x0;
              }
              else {
                if (((int)auStack_116c[0] < 0x401) &&
                   (cVar3 = FUN_1000eae0(auStack_116c[0]), cVar3 != '\0')) {
                  iStack_12c8 = auStack_116c[0] + 0x24;
                  iVar6 = -(auStack_116c[0] + 0x24);
                  local_14 = (undefined1 *)&uStack_12e4;
                  local_12d4[2] = (LPWSTR)&uStack_12e4;
                  *(_RTC_ALLOCA_NODE ***)((int)local_12d4 + iVar6 + -0x14) = local_12b4;
                  iVar2 = iStack_12c8;
                  pWVar1 = local_12d4[2];
                  *(undefined4 *)((int)local_12d4 + iVar6 + -0x18) = 0x1000505a;
                  _RTC_AllocaHelper((undefined1 *)pWVar1,iVar2,
                                    *(undefined4 **)((int)local_12d4 + iVar6 + -0x14));
                  local_12d4[1] = (LPWSTR)((int)local_12d4[2] + 0x20);
                  local_12d4[2] = local_12d4[1];
                }
                else {
                  local_12d4[1] =
                       (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                               CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                         (aCStack_1184,auStack_116c[0]);
                }
                pWStack_12c4 = FUN_100058b0(local_12d4[1],(LPCSTR)pBStack_117c,auStack_116c[0] >> 1,
                                            UStack_1174);
              }
              pWStack_12c0 = pWStack_12c4;
            }
            pWStack_118c = pWStack_12c0;
            if (pWStack_12c0 == (LPWSTR)0x0) {
              uStack_12a8 = 0x8007000e;
              local_8 = 0xffffffff;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(aCStack_1184);
              goto LAB_10005332;
            }
            Ordinal_277(pWStack_12c0,0);
            uStack_12e4 = 0x10005119;
            local_1038 = FUN_1000d220(param_1,param_2);
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(aCStack_1184);
          }
          else if (local_12bc == 8) {
            local_1038 = FUN_1000d330(param_1,param_2,local_1024,1);
          }
          else if (local_12bc == 0x11) {
            sStack_1190 = strlen((char *)local_1024);
            if ((sStack_1190 & 1) == 0) {
              uStack_1194 = (int)sStack_1190 / 2;
              FUN_10002390(auStack_129c);
              local_8 = 5;
              Allocate(auStack_129c,uStack_1194);
              FUN_100051b4();
              return;
            }
            goto LAB_10005332;
          }
        }
        else if (local_12bc == 0x4008) {
          sVar4 = strlen((char *)local_1024);
          local_1040 = sVar4 + 2;
          FUN_10002350(local_1148);
          local_8 = 1;
          Allocate(local_1148,local_1040);
          FUN_10004daf(unaff_EDI);
          return;
        }
        if (local_1038 == 0) {
          local_20 = FUN_1000a3b0(local_1c,param_3);
        }
        else {
          local_103c = 0x204;
          FUN_10006110(local_1038);
        }
      }
    }
  }
LAB_10005332:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10005370,local_12b4[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10004da9 at 10004da9

undefined * Catch_10004da9(void)

{
  return &DAT_10004db8;
}



// Function: FUN_10004daf at 10004daf

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10004daf(LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  LPSTR pCVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  LSTATUS LVar7;
  uint unaff_EBP;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  iVar2 = FUN_10003e10((undefined4 *)(unaff_EBP - 0x1144));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 0x1034) = 0xe;
  }
  else {
    uVar3 = FUN_10003e10((undefined4 *)(unaff_EBP - 0x1144));
    *(undefined4 *)(unaff_EBP - 0x114c) = uVar3;
    *(uint *)(unaff_EBP - 0x1150) = unaff_EBP - 0x1020;
    *(undefined4 *)(unaff_EBP - 0x103c) = 0;
    while (**(char **)(unaff_EBP - 0x1150) != '\0') {
      pCVar4 = CharNextA(param_1);
      param_1 = (LPCSTR)0x10004e20;
      *(LPSTR *)(unaff_EBP - 0x1154) = pCVar4;
      if ((**(char **)(unaff_EBP - 0x1150) == '\\') && (**(char **)(unaff_EBP - 0x1154) == '0')) {
        **(undefined1 **)(unaff_EBP - 0x114c) = 0;
        *(int *)(unaff_EBP - 0x114c) = *(int *)(unaff_EBP - 0x114c) + 1;
        pCVar4 = CharNextA(*(LPCSTR *)(unaff_EBP - 0x1154));
        *(LPSTR *)(unaff_EBP - 0x1150) = pCVar4;
      }
      else {
        **(undefined1 **)(unaff_EBP - 0x114c) = **(undefined1 **)(unaff_EBP - 0x1150);
        BVar5 = IsDBCSLeadByte(**(BYTE **)(unaff_EBP - 0x1150));
        if (BVar5 != 0) {
          *(int *)(unaff_EBP - 0x114c) = *(int *)(unaff_EBP - 0x114c) + 1;
          *(int *)(unaff_EBP - 0x1150) = *(int *)(unaff_EBP - 0x1150) + 1;
          if (**(char **)(unaff_EBP - 0x1150) == '\0') break;
          **(undefined1 **)(unaff_EBP - 0x114c) = **(undefined1 **)(unaff_EBP - 0x1150);
        }
        *(int *)(unaff_EBP - 0x114c) = *(int *)(unaff_EBP - 0x114c) + 1;
        *(int *)(unaff_EBP - 0x1150) = *(int *)(unaff_EBP - 0x1150) + 1;
      }
      *(int *)(unaff_EBP - 0x103c) = *(int *)(unaff_EBP - 0x103c) + 1;
    }
    **(undefined1 **)(unaff_EBP - 0x114c) = 0;
    *(int *)(unaff_EBP - 0x114c) = *(int *)(unaff_EBP - 0x114c) + 1;
    **(undefined1 **)(unaff_EBP - 0x114c) = 0;
    pBVar6 = (BYTE *)FUN_10003e10((undefined4 *)(unaff_EBP - 0x1144));
    LVar7 = FUN_1000d270(*(void **)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + 0xc),pBVar6);
    *(LSTATUS *)(unaff_EBP - 0x1034) = LVar7;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ~CTempBuffer<>((int *)(unaff_EBP - 0x1144));
  if (*(int *)(unaff_EBP - 0x1034) == 0) {
    uVar3 = FUN_1000a3b0(*(void **)(unaff_EBP - 0x18),*(undefined1 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP - 0x1c) = uVar3;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x1038) = 0x204;
    FUN_10006110(*(ulong *)(unaff_EBP - 0x1034));
  }
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_10005370,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 0x12b0));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x12d4) = 0x10005367;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: Catch@100051ae at 100051ae

undefined * Catch_100051ae(void)

{
  return &DAT_100051bd;
}



// Function: FUN_100051b4 at 100051b4

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_100051b4(void)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  BYTE *lpData;
  HKEY hKey;
  LSTATUS LVar3;
  undefined4 uVar4;
  uint unaff_EBP;
  LPCSTR lpValueName;
  DWORD Reserved;
  DWORD dwType;
  size_t _Size;
  DWORD cbData;
  
  *(undefined4 *)(unaff_EBP - 4) = 4;
  iVar1 = FUN_10003e50((undefined4 *)(unaff_EBP - 0x1298));
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP - 0x12a8) = 0x80004005;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    ~CTempBuffer<>((int *)(unaff_EBP - 0x1298));
  }
  else {
    _Size = *(size_t *)(unaff_EBP - 0x1190);
    iVar1 = 0;
    _Dst = (void *)FUN_10003e50((undefined4 *)(unaff_EBP - 0x1298));
    memset(_Dst,iVar1,_Size);
    *(undefined4 *)(unaff_EBP - 0x12a0) = 0;
    while (*(int *)(unaff_EBP - 0x12a0) < *(int *)(unaff_EBP - 0x118c)) {
      iVar1 = FUN_10003e50((undefined4 *)(unaff_EBP - 0x1298));
      *(int *)(unaff_EBP - 0x12d0) = iVar1 + *(int *)(unaff_EBP - 0x12a0) / 2;
      uVar2 = FUN_10007ae0(*(char *)((unaff_EBP - 0x1020) + *(int *)(unaff_EBP - 0x12a0)));
      **(byte **)(unaff_EBP - 0x12d0) =
           **(byte **)(unaff_EBP - 0x12d0) |
           (byte)((uVar2 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP - 0x12a0) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP - 0x12a0) = *(int *)(unaff_EBP - 0x12a0) + 1;
    }
    cbData = *(DWORD *)(unaff_EBP - 0x1190);
    lpData = (BYTE *)FUN_10003e50((undefined4 *)(unaff_EBP - 0x1298));
    dwType = 3;
    Reserved = 0;
    lpValueName = *(LPCSTR *)(unaff_EBP + 0xc);
    hKey = (HKEY)FUN_10003e90(*(undefined4 **)(unaff_EBP + 8));
    LVar3 = RegSetValueExA(hKey,lpValueName,Reserved,dwType,lpData,cbData);
    *(LSTATUS *)(unaff_EBP - 0x1034) = LVar3;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    ~CTempBuffer<>((int *)(unaff_EBP - 0x1298));
    if (*(int *)(unaff_EBP - 0x1034) == 0) {
      uVar4 = FUN_1000a3b0(*(void **)(unaff_EBP - 0x18),*(undefined1 **)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP - 0x1c) = uVar4;
    }
    else {
      *(undefined4 *)(unaff_EBP - 0x1038) = 0x204;
      FUN_10006110(*(ulong *)(unaff_EBP - 0x1034));
    }
  }
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_10005370,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 0x12b0));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar2 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x12d4) = 0x10005367;
  __security_check_cookie(uVar2 ^ unaff_EBP);
  return;
}



// Function: Allocate at 10005430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: void * __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::Allocate(unsigned long)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void * __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
          (CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *this,ulong param_1)

{
  ulong uVar1;
  CAtlSafeAllocBufferNode *this_00;
  void *pvVar2;
  
  uVar1 = AtlAddThrow<unsigned_long>(param_1,8);
  this_00 = (CAtlSafeAllocBufferNode *)FUN_10005560(uVar1);
  if (this_00 == (CAtlSafeAllocBufferNode *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)this_00 = *(undefined4 *)this;
    *(CAtlSafeAllocBufferNode **)this = this_00;
    pvVar2 = CAtlSafeAllocBufferNode::GetData(this_00);
  }
  return pvVar2;
}



// Function: Allocate at 100054a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_10005590(this,uVar1);
  return;
}



// Function: Allocate at 100054e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_100055e0(this,uVar1);
  return;
}



// Function: Allocate at 10005520

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_10005630(this,uVar1);
  return;
}



// Function: FUN_10005560 at 10005560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10005560(size_t param_1)

{
  malloc(param_1);
  return;
}



// Function: FUN_10005590 at 10005590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10005590(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    AllocateHeap(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100055e0 at 100055e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_100055e0(void *this,uint param_1)

{
  if (param_1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    AllocateHeap(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10005630 at 10005630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10005630(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    AllocateHeap(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: AllocateHeap at 10005680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10005560(param_1);
  if (iVar1 == 0) {
    FUN_10007680(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: AllocateHeap at 100056d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10005560(param_1);
  if (iVar1 == 0) {
    FUN_10007680(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: AllocateHeap at 10005720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10005560(param_1);
  if (iVar1 == 0) {
    FUN_10007680(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: FUN_10005770 at 10005770

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10005770(void *this,void *param_1,rsize_t param_2)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
                    /* WARNING: Load size is inaccurate */
  pvVar2 = (void *)(*this + 1 + param_2);
                    /* WARNING: Load size is inaccurate */
  if ((*this < (int)pvVar2) && ((int)param_2 < (int)pvVar2)) {
    if (*(int *)((int)this + 4) <= (int)pvVar2) {
      while (*(int *)((int)this + 4) <= (int)pvVar2) {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          uVar3 = 0;
          this = pvVar2;
          goto LAB_10005896;
        }
        *(int *)((int)this + 4) = *(int *)((int)this + 4) << 1;
      }
      uVar4 = FUN_10005a50(*(LPVOID *)((int)this + 8),*(ulong *)((int)this + 4),1);
      if ((int)uVar4 == 0) {
        uVar3 = 0;
        this = (void *)((ulonglong)uVar4 >> 0x20);
        goto LAB_10005896;
      }
      *(int *)((int)this + 8) = (int)uVar4;
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((*this < 0) || (*(int *)((int)this + 4) <= *this)) ||
       (*(int *)((int)this + 4) < *(int *)((int)this + 4) - *this)) {
      uVar3 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      FUN_1000f920((void *)(*(int *)((int)this + 8) + *this),*(int *)((int)this + 4) - *this,param_1
                   ,param_2);
                    /* WARNING: Load size is inaccurate */
      *(rsize_t *)this = *this + param_2;
      piVar1 = (int *)((int)this + 8);
                    /* WARNING: Load size is inaccurate */
      this = *this;
      *(undefined1 *)(*piVar1 + (int)this) = 0;
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
LAB_10005896:
  return CONCAT44(this,uVar3);
}



// Function: FUN_100058b0 at 100058b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPWSTR FUN_100058b0(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  
  if ((param_1 == (LPWSTR)0x0) || (param_2 == (LPCSTR)0x0)) {
    param_1 = (LPWSTR)0x0;
  }
  else {
    *param_1 = L'\0';
    iVar1 = MultiByteToWideChar(param_4,0,param_2,-1,param_1,param_3);
    if (iVar1 == 0) {
      param_1 = (LPWSTR)0x0;
    }
  }
  return param_1;
}



// Function: FUN_10005920 at 10005920

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10005920(int param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  if (param_1 == 0) {
    ATL::_AtlRaiseException(0xc0000005,1);
  }
  local_8 = *(undefined4 **)(param_1 + 8);
  while (local_8 != (undefined4 *)0x0) {
    (*(code *)*local_8)(local_8[1]);
    puVar1 = (undefined4 *)local_8[2];
    operator_delete(local_8);
    local_8 = puVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: AtlCoTaskMemCAlloc at 100059c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    void * __cdecl ATL::AtlCoTaskMemCAlloc(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void * __cdecl ATL::AtlCoTaskMemCAlloc(ulong param_1,ulong param_2)

{
  LPVOID pvVar1;
  ulong local_10 [3];
  
  local_10[1] = 0xcccccccc;
  local_10[2] = 0xcccccccc;
  local_10[0] = 0;
  local_10[2] = AtlMultiply<unsigned_long>(local_10,param_1,param_2);
  if ((int)local_10[2] < 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = CoTaskMemAlloc(local_10[0]);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10005a34);
  return pvVar1;
}



// Function: FUN_10005a50 at 10005a50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_10005a50(LPVOID param_1,ulong param_2,ulong param_3)

{
  LPVOID pvVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  ulong local_10 [3];
  
  local_10[1] = 0xcccccccc;
  local_10[2] = 0xcccccccc;
  local_10[0] = 0;
  local_10[2] = ATL::AtlMultiply<unsigned_long>(local_10,param_2,param_3);
  if ((int)local_10[2] < 0) {
    pvVar1 = (LPVOID)0x0;
    uVar2 = extraout_EDX;
  }
  else {
    pvVar1 = CoTaskMemRealloc(param_1,local_10[0]);
    uVar2 = extraout_EDX_00;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10005ac8);
  return CONCAT44(uVar2,pvVar1);
}



// Function: FUN_10005af0 at 10005af0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10005af0(undefined4 param_1,int *param_2,int *param_3,int *param_4,undefined4 param_5,
            int *param_6)

{
  uint uVar1;
  PVOID pvVar2;
  int iVar3;
  undefined4 **ppuVar4;
  undefined4 *local_40 [5];
  undefined4 local_2c [3];
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cc38;
  local_10 = ExceptionList;
  ppuVar4 = local_40;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined4 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_6 == (int *)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    *param_6 = 0;
    if (param_3 == (int *)0x0) {
      iVar3 = -0x7ff8ffa9;
    }
    else if (*param_3 == 0) {
      iVar3 = -0x7fff0001;
    }
    else {
      local_14 = 0;
      for (local_18 = (int *)param_3[2]; local_18 < (int *)param_3[3]; local_18 = local_18 + 1) {
        if (((*local_18 != 0) && (local_1c = (undefined4 *)*local_18, local_1c[2] != 0)) &&
           (iVar3 = FID_conflict__AfxIsEqualGUID(param_4,(int *)*local_1c), iVar3 != 0)) {
          local_20 = (int *)local_1c[4];
          if (*local_20 == 0) {
            FUN_10001d80(local_2c,param_3 + 4,'\0');
            local_8 = 0;
            local_14 = FUN_1000a220(local_2c);
            if (local_14 < 0) {
              local_8 = 0xffffffff;
              FUN_10002f70(local_2c);
              break;
            }
            if (*local_20 == 0) {
              local_14 = (*(code *)local_1c[2])(local_1c[3],&DAT_1001f428,local_40 + 2,uVar1);
              uVar1 = 0x10005c41;
              if (-1 < local_14) {
                pvVar2 = EncodePointer(local_40[2]);
                uVar1 = 0x10005c5d;
                *local_20 = (int)pvVar2;
              }
            }
            local_8 = 0xffffffff;
            FUN_10002f70(local_2c);
          }
          if (*local_20 != 0) {
            local_40[0] = (undefined4 *)DecodePointer((PVOID)*local_20);
            local_14 = (**(code **)*local_40[0])(local_40[0],param_5,param_6,0x10005c8e,uVar1);
          }
          break;
        }
      }
      iVar3 = local_14;
      param_2 = param_6;
      if ((*param_6 == 0) && (local_14 == 0)) {
        local_14 = -0x7ffbfeef;
        iVar3 = local_14;
      }
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10005d00);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar3);
}



// Function: FUN_10005d30 at 10005d30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10005d30(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *local_c;
  int local_8;
  
  if (param_1 == 0) {
    local_8 = -0x7ff8ffa9;
  }
  else {
    local_8 = 0;
    for (local_c = *(int **)(param_1 + 8); local_c < *(int **)(param_1 + 0xc); local_c = local_c + 1
        ) {
      if ((*local_c != 0) &&
         ((puVar1 = (undefined4 *)*local_c, param_3 == (void *)0x0 ||
          (bVar2 = _IsEqualGUID(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        piVar3 = (int *)(*(code *)puVar1[6])(1,0x10005dc3);
        local_8 = FUN_10006b80((GUID *)*puVar1,piVar3,0x10005de1);
        if (local_8 < 0) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_100072f0(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return local_8;
}



// Function: FUN_10005e40 at 10005e40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10005e40(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  undefined8 uVar4;
  int *local_c;
  int local_8;
  
  if (param_1 == 0) {
    local_8 = -0x7ff8ffa9;
  }
  else {
    local_8 = 0;
    for (local_c = *(int **)(param_1 + 8); local_c < *(int **)(param_1 + 0xc); local_c = local_c + 1
        ) {
      if ((*local_c != 0) &&
         ((puVar1 = (undefined4 *)*local_c, param_3 == (void *)0x0 ||
          (bVar2 = _IsEqualGUID(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        piVar3 = (int *)(*(code *)puVar1[6])(0);
        local_8 = FUN_10006b80((GUID *)*puVar1,piVar3,0x10005ed3);
        if ((local_8 < 0) || (local_8 = (*(code *)puVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      uVar4 = FUN_100076d0(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
      local_8 = (int)uVar4;
    }
  }
  return local_8;
}



// Function: AtlComQIPtrAssign at 10005f40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    struct IUnknown * __stdcall ATL::AtlComQIPtrAssign(struct IUnknown * *,struct IUnknown *,struct
   _GUID const &)
   
   Library: Visual Studio 2012 Debug */

IUnknown * ATL::AtlComQIPtrAssign(IUnknown **param_1,IUnknown *param_2,_GUID *param_3)

{
  IUnknown *This;
  HRESULT HVar1;
  
  if (param_1 != (IUnknown **)0x0) {
    This = *param_1;
    if ((param_2 == (IUnknown *)0x0) ||
       (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,param_3,param_1), HVar1 < 0)) {
      *param_1 = (IUnknown *)0x0;
    }
    if (This != (IUnknown *)0x0) {
      (*This->lpVtbl->Release)(This);
    }
    return *param_1;
  }
  return (IUnknown *)0x0;
}



// Function: AtlCrtErrorCheck at 10005fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_10007680(0x80004005);
    break;
  case 0xc:
    FUN_10007680(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_10007680(0x80070057);
  }
  return param_1;
}



// Function: FUN_100060a0 at 100060a0

undefined4 FUN_100060a0(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_100298a0;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: AtlHresultFromLastError at 100060d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    long __cdecl ATL::AtlHresultFromLastError(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

long __cdecl ATL::AtlHresultFromLastError(void)

{
  DWORD x;
  HRESULT HVar1;
  
  x = GetLastError();
  HVar1 = _HRESULT_FROM_WIN32(x);
  return HVar1;
}



// Function: FUN_10006110 at 10006110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10006110(ulong param_1)

{
  _HRESULT_FROM_WIN32(param_1);
  return;
}



// Function: FUN_10006130 at 10006130

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10006130(int param_1,int *param_2,_GUID *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_c;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    local_c = -0x7ff8ffa9;
  }
  else if (param_4 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    iVar1 = ATL::InlineIsEqualUnknown(param_3);
    if (iVar1 == 0) {
      for (; param_2[2] != 0; param_2 = param_2 + 3) {
        iVar1 = *param_2;
        if ((iVar1 == 0) ||
           (iVar2 = FID_conflict__AfxIsEqualGUID((int *)*param_2,(int *)param_3), iVar2 != 0)) {
          if (param_2[2] == 1) {
            piVar3 = (int *)(param_1 + param_2[1]);
            (**(code **)(*piVar3 + 4))(piVar3);
            *param_4 = piVar3;
            return 0;
          }
          local_c = (*(code *)param_2[2])(param_1,param_3,param_4,param_2[1]);
          if (local_c == 0) {
            return 0;
          }
          if ((iVar1 != 0) && (local_c < 0)) goto LAB_10006286;
        }
      }
      local_c = -0x7fffbffe;
LAB_10006286:
      *param_4 = 0;
    }
    else {
      piVar3 = (int *)(param_1 + param_2[1]);
      (**(code **)(*piVar3 + 4))(piVar3);
      *param_4 = piVar3;
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_100062b0 at 100062b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_100062b0(HMODULE param_1,wchar_t *param_2,int *param_3,undefined4 *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPWSTR *ppWVar7;
  LPWSTR local_1e8 [2];
  int local_1e0;
  LPWSTR local_1dc;
  LPWSTR local_1d8;
  LPWSTR local_1d4;
  LPWSTR local_1d0;
  int local_1cc;
  LPWSTR local_1c8;
  LPWSTR local_1c4;
  LPSTR local_1c0;
  LPSTR local_1bc;
  int local_1b8;
  LPSTR local_1b4;
  char *local_1b0;
  _RTC_ALLOCA_NODE *local_1a8 [2];
  int local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  HRESULT local_188;
  long local_184;
  char local_17c [12];
  int local_170;
  LPWSTR local_16c;
  uint local_168;
  size_t local_164;
  char *local_160;
  LPCSTR local_15c;
  long local_158;
  DWORD local_154;
  CHAR local_14c [280];
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_34 [8];
  char *local_2c;
  wchar_t *local_28;
  UINT local_24;
  ulong local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cc68;
  local_10 = ExceptionList;
  ppWVar7 = local_1e8;
  for (iVar6 = 0x76; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppWVar7 = (LPWSTR)0xcccccccc;
    ppWVar7 = ppWVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1a8[0] = (_RTC_ALLOCA_NODE *)0x0;
  if ((param_3 != (int *)0x0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    local_24 = FUN_1000e9f0();
    FUN_10001bd0((undefined4 *)local_34);
    local_8 = 0;
    local_154 = GetModuleFileNameA(param_1,local_14c,0x104);
    if (local_154 == 0) {
      local_184 = ATL::AtlHresultFromLastError();
      local_8 = 0xffffffff;
      local_158 = local_184;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
    }
    else if (local_154 == 0x104) {
      local_188 = _HRESULT_FROM_WIN32(0x7a);
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
    }
    else {
      local_15c = (LPCSTR)0x0;
      local_15c = FUN_10001460(local_14c);
      if (param_2 != (wchar_t *)0x0) {
        local_28 = param_2;
        if (param_2 == (wchar_t *)0x0) {
          local_1b0 = (char *)0x0;
        }
        else {
          sVar4 = wcslen(param_2);
          local_1c[0] = sVar4 + 1;
          lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
          if (lVar5 < 0) {
            local_1b4 = (LPSTR)0x0;
          }
          else {
            if (((int)local_1c[0] < 0x401) && (cVar3 = FUN_1000eae0(local_1c[0]), cVar3 != '\0')) {
              local_1b8 = local_1c[0] + 0x24;
              iVar6 = -(local_1c[0] + 0x24);
              local_1bc = &stack0xfffffe04;
              *(_RTC_ALLOCA_NODE ***)((int)local_1e8 + iVar6 + -0x18) = local_1a8;
              iVar2 = local_1b8;
              pCVar1 = local_1bc;
              *(undefined4 *)((int)local_1e8 + iVar6 + -0x1c) = 0x100064a5;
              _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_1e8 + iVar6 + -0x18));
              local_1c0 = local_1bc + 0x20;
              local_1bc = local_1c0;
            }
            else {
              local_1c0 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                 CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                           (local_34,local_1c[0]);
            }
            local_1b4 = FUN_10007930(local_1c0,local_28,local_1c[0],local_24);
          }
          local_1b0 = local_1b4;
        }
        local_160 = local_1b0;
        if (local_1b0 == (char *)0x0) {
          local_18c = 0x8007000e;
          local_8 = 0xffffffff;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
          goto LAB_10006977;
        }
        local_164 = strlen(local_1b0);
        local_168 = local_154 + local_164;
        if (((local_168 < local_154) || (local_168 < local_164)) || (0x10d < local_168)) {
          local_190 = 0x80004005;
          local_8 = 0xffffffff;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
          goto LAB_10006977;
        }
        ATL::Checked::strcpy_s(local_14c + local_154,0x10e - local_154,local_160);
      }
      local_2c = local_14c;
      if (local_2c == (char *)0x0) {
        local_1c4 = (LPWSTR)0x0;
      }
      else {
        sVar4 = strlen(local_2c);
        local_1c[0] = sVar4 + 1;
        lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
        if (lVar5 < 0) {
          local_1c8 = (LPWSTR)0x0;
        }
        else {
          if (((int)local_1c[0] < 0x401) && (cVar3 = FUN_1000eae0(local_1c[0]), cVar3 != '\0')) {
            local_1cc = local_1c[0] + 0x24;
            local_1d0 = (LPWSTR)&stack0xfffffe04;
            _RTC_AllocaHelper(&stack0xfffffe04,local_1cc,local_1a8);
            local_1d4 = (LPWSTR)((int)local_1d0 + 0x20);
            local_1d0 = local_1d4;
          }
          else {
            local_1d4 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                          (local_34,local_1c[0]);
          }
          local_1c8 = FUN_100058b0(local_1d4,local_2c,local_1c[0] >> 1,local_24);
        }
        local_1c4 = local_1c8;
      }
      local_16c = local_1c4;
      if (local_1c4 == (LPWSTR)0x0) {
        local_194 = 0x8007000e;
        local_8 = 0xffffffff;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
      }
      else {
        local_170 = Ordinal_161();
        if (local_170 < 0) {
          builtin_strncpy(local_17c,".tlb",5);
          if ((char *)0x104 < local_15c + (5 - (int)local_14c)) {
            local_198 = 0x80004005;
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
            goto LAB_10006977;
          }
          ATL::Checked::strcpy_s(local_15c,0x10e - ((int)local_15c - (int)local_14c),local_17c);
          local_2c = local_14c;
          if (local_2c == (char *)0x0) {
            local_1d8 = (LPWSTR)0x0;
          }
          else {
            sVar4 = strlen(local_2c);
            local_1c[0] = sVar4 + 1;
            lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
            if (lVar5 < 0) {
              local_1dc = (LPWSTR)0x0;
            }
            else {
              if (((int)local_1c[0] < 0x401) && (cVar3 = FUN_1000eae0(local_1c[0]), cVar3 != '\0'))
              {
                local_1e0 = local_1c[0] + 0x24;
                local_1e8[1] = (LPWSTR)&stack0xfffffe04;
                _RTC_AllocaHelper(&stack0xfffffe04,local_1e0,local_1a8);
                local_1e8[0] = (LPWSTR)((int)local_1e8[1] + 0x20);
                local_1e8[1] = local_1e8[0];
              }
              else {
                local_1e8[0] = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                       CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                                       Allocate(local_34,local_1c[0]);
              }
              local_1dc = FUN_100058b0(local_1e8[0],local_2c,local_1c[0] >> 1,local_24);
            }
            local_1d8 = local_1dc;
          }
          local_16c = local_1d8;
          if (local_1d8 == (LPWSTR)0x0) {
            local_19c = 0x8007000e;
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
            goto LAB_10006977;
          }
          local_170 = Ordinal_161();
        }
        if (-1 < local_170) {
          iVar6 = Ordinal_2();
          *param_3 = iVar6;
          if (*param_3 == 0) {
            local_170 = -0x7ff8fff2;
            (**(code **)(*(int *)*param_4 + 8))();
            *param_4 = 0;
          }
        }
        local_1a0 = local_170;
        local_8 = 0xffffffff;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
      }
    }
  }
LAB_10006977:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_100069b4,local_1a8[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006a40 at 10006a40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall
FUN_10006a40(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cc98;
  local_10 = ExceptionList;
  local_24 = 0xcccccccc;
  local_20 = 0xcccccccc;
  local_1c = 0xcccccccc;
  local_18 = (undefined4 *)0xcccccccc;
  local_14 = -0x33333334;
  ExceptionList = &local_10;
  if (param_3 == 0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    local_14 = 0;
    uVar2 = FUN_1001aa60(0xc);
    param_2 = (undefined4)((ulonglong)uVar2 >> 0x20);
    local_18 = (undefined4 *)uVar2;
    if (local_18 == (undefined4 *)0x0) {
      local_14 = -0x7ff8fff2;
      iVar1 = local_14;
    }
    else {
      *local_18 = param_4;
      local_18[1] = param_5;
      FUN_10001d80(&local_24,param_3 + 0xc,'\0');
      local_8 = 0;
      local_14 = FUN_1000a220(&local_24);
      if (local_14 < 0) {
        operator_delete(local_18);
      }
      else {
        local_18[2] = *(undefined4 *)(param_3 + 8);
        *(undefined4 **)(param_3 + 8) = local_18;
      }
      local_8 = 0xffffffff;
      FUN_10002f70(&local_24);
      iVar1 = local_14;
      param_2 = extraout_EDX;
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10006b64);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar1);
}



// Function: FUN_10006b80 at 10006b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10006b80(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  char cVar2;
  LPVOID *ppv;
  size_t sVar3;
  long lVar4;
  HKEY pHVar5;
  int iVar6;
  LPSTR *ppCVar7;
  undefined8 uVar8;
  LPSTR pCVar9;
  LPDWORD pDVar10;
  LPDWORD pDVar11;
  DWORD *pDVar12;
  LPDWORD pDVar13;
  LPDWORD pDVar14;
  LPDWORD pDVar15;
  LPDWORD pDVar16;
  LPDWORD pDVar17;
  char *pcVar18;
  LPDWORD pDVar19;
  REGSAM RVar20;
  PFILETIME p_Var21;
  LPSTR local_1f4 [2];
  int local_1ec;
  LPSTR local_1e8;
  LPSTR local_1e4;
  int *local_1e0;
  int *local_1dc;
  int *local_1d8;
  int *local_1d4;
  _RTC_ALLOCA_NODE *local_1cc [2];
  undefined4 local_1c4;
  int local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  int local_1b0;
  DWORD local_1a8 [3];
  CRegKey local_19c [20];
  CRegKey local_188 [20];
  char local_174 [132];
  LPSTR local_f0;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_e8 [12];
  wchar_t *local_dc;
  UINT local_d8;
  ulong local_d0 [3];
  OLECHAR local_c4 [68];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int *local_28;
  HRESULT local_24;
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> local_1c [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cce9;
  local_10 = ExceptionList;
  ppCVar7 = local_1f4;
  for (iVar6 = 0x79; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1cc[0] = (_RTC_ALLOCA_NODE *)0x0;
  ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_1c);
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    local_1b4 = 0;
    local_8 = 0xffffffff;
    FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_1c);
  }
  else {
    iVar6 = FID_conflict__AfxIsEqualGUID((int *)param_1,(int *)&DAT_100215ec);
    if (iVar6 == 0) {
      ppv = (LPVOID *)FUN_10003f10(local_1c);
      local_24 = CoCreateInstance((IID *)&DAT_1002233c,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001f62c,ppv);
      if (local_24 < 0) {
        local_1bc = 0;
        local_8 = 0xffffffff;
        FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_1c);
      }
      else {
        local_24 = 0;
        for (local_28 = param_2; *local_28 != 0; local_28 = local_28 + 2) {
          puVar1 = (undefined4 *)local_28[1];
          local_3c = *puVar1;
          local_38 = puVar1[1];
          local_34 = puVar1[2];
          local_30 = puVar1[3];
          if (param_3 == 0) {
            if (*local_28 == 1) {
              local_1dc = (int *)FUN_10003eb0((undefined4 *)local_1c);
              (**(code **)(*local_1dc + 0x18))(local_1dc,param_1,1,&local_3c);
            }
            else {
              local_1e0 = (int *)FUN_10003eb0((undefined4 *)local_1c);
              (**(code **)(*local_1e0 + 0x20))(local_1e0,param_1,1,&local_3c);
            }
          }
          else {
            if (*local_28 == 1) {
              local_1d4 = (int *)FUN_10003eb0((undefined4 *)local_1c);
              local_24 = (**(code **)(*local_1d4 + 0x14))(local_1d4,param_1,1,&local_3c);
            }
            else {
              local_1d8 = (int *)FUN_10003eb0((undefined4 *)local_1c);
              local_24 = (**(code **)(*local_1d8 + 0x1c))(local_1d8,param_1,1,&local_3c);
            }
            if (local_24 < 0) {
              local_1c0 = local_24;
              local_8 = 0xffffffff;
              FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_1c);
              goto LAB_100071c8;
            }
          }
        }
        if (param_3 == 0) {
          StringFromGUID2(param_1,local_c4,0x40);
          local_d8 = FUN_1000e9f0();
          FUN_10001bd0((undefined4 *)local_e8);
          local_8._0_1_ = 1;
          local_dc = local_c4;
          if (local_dc == (wchar_t *)0x0) {
            local_1e4 = (LPSTR)0x0;
          }
          else {
            sVar3 = wcslen(local_dc);
            local_d0[0] = sVar3 + 1;
            lVar4 = ATL::AtlMultiply<int>((int *)local_d0,local_d0[0],2);
            if (lVar4 < 0) {
              local_1e8 = (LPSTR)0x0;
            }
            else {
              if (((int)local_d0[0] < 0x401) && (cVar2 = FUN_1000eae0(local_d0[0]), cVar2 != '\0'))
              {
                local_1ec = local_d0[0] + 0x24;
                local_1f4[1] = &stack0xfffffdfc;
                _RTC_AllocaHelper(&stack0xfffffdfc,local_1ec,local_1cc);
                local_1f4[0] = local_1f4[1] + 0x20;
                local_1f4[1] = local_1f4[0];
              }
              else {
                local_1f4[0] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                      CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                                (local_e8,local_d0[0]);
              }
              local_1e8 = FUN_10007930(local_1f4[0],local_dc,local_d0[0],local_d8);
            }
            local_1e4 = local_1e8;
          }
          local_f0 = local_1e4;
          if (local_1e4 != (LPSTR)0x0) {
            ATL::Checked::strcpy_s(local_174,0x80,"CLSID\\");
            ATL::Checked::strcpy_s(local_174,0x80,local_f0);
            ATL::Checked::strcpy_s(local_174,0x80,"\\Required Categories");
            ATL::CRegKey::CRegKey(local_188,(HKEY__ *)0x80000000);
            local_8._0_1_ = 2;
            ATL::CRegKey::CRegKey(local_19c,(CAtlTransactionManager *)0x0);
            local_8 = CONCAT31(local_8._1_3_,3);
            local_1a8[0] = 0;
            RVar20 = 0x20019;
            pcVar18 = local_174;
            pHVar5 = (HKEY)FUN_10003e90((undefined4 *)local_188);
            uVar8 = FUN_1000a620(local_19c,pHVar5,pcVar18,RVar20);
            local_1b0 = (int)uVar8;
            if (local_1b0 == 0) {
              p_Var21 = (PFILETIME)0x0;
              pDVar19 = (LPDWORD)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar16 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = local_1a8;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = (LPDWORD)0x0;
              pCVar9 = (LPSTR)0x0;
              pHVar5 = (HKEY)FUN_10003e90((undefined4 *)local_19c);
              local_1b0 = RegQueryInfoKeyA(pHVar5,pCVar9,pDVar10,pDVar11,pDVar12,pDVar13,pDVar14,
                                           pDVar15,pDVar16,pDVar17,pDVar19,p_Var21);
              ATL::CRegKey::Close(local_19c);
              if ((local_1b0 == 0) && (local_1a8[0] == 0)) {
                FUN_10008300(local_188,local_174);
              }
            }
            ATL::Checked::strcpy_s(local_174,0x80,"CLSID\\");
            ATL::Checked::strcpy_s(local_174,0x80,local_f0);
            ATL::Checked::strcpy_s(local_174,0x80,"\\Implemented Categories");
            RVar20 = 0x20019;
            pcVar18 = local_174;
            pHVar5 = (HKEY)FUN_10003e90((undefined4 *)local_188);
            uVar8 = FUN_1000a620(local_19c,pHVar5,pcVar18,RVar20);
            local_1b0 = (int)uVar8;
            if (local_1b0 == 0) {
              p_Var21 = (PFILETIME)0x0;
              pDVar19 = (LPDWORD)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar16 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = local_1a8;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = (LPDWORD)0x0;
              pCVar9 = (LPSTR)0x0;
              pHVar5 = (HKEY)FUN_10003e90((undefined4 *)local_19c);
              local_1b0 = RegQueryInfoKeyA(pHVar5,pCVar9,pDVar10,pDVar11,pDVar12,pDVar13,pDVar14,
                                           pDVar15,pDVar16,pDVar17,pDVar19,p_Var21);
              ATL::CRegKey::Close(local_19c);
              if ((local_1b0 == 0) && (local_1a8[0] == 0)) {
                FUN_10008300(local_188,local_174);
              }
            }
            local_8._0_1_ = 2;
            ATL::CRegKey::~CRegKey(local_19c);
            local_8._0_1_ = 1;
            ATL::CRegKey::~CRegKey(local_188);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_e8);
        }
        local_1c4 = 0;
        local_8 = 0xffffffff;
        FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_1c);
      }
    }
    else {
      local_1b8 = 0;
      local_8 = 0xffffffff;
      FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_1c);
    }
  }
LAB_100071c8:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_10007204,local_1cc[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100072f0 at 100072f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10007436) */

void FUN_100072f0(HMODULE param_1,wchar_t *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  rsize_t rVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int **ppiVar9;
  wchar_t *pwVar10;
  int *local_278;
  int local_274;
  int local_270;
  uint local_26c;
  undefined4 local_268;
  HMODULE local_264;
  char local_259 [5];
  FARPROC local_254;
  wchar_t *local_24c [3];
  wchar_t local_240 [259];
  undefined2 uStack_3a;
  wchar_t *local_34;
  int local_30;
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> local_28 [12];
  undefined4 local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cd3b;
  local_10 = ExceptionList;
  ppiVar9 = &local_278;
  for (iVar8 = 0x9a; iVar8 != 0; iVar8 = iVar8 + -1) {
    *ppiVar9 = (int *)0xcccccccc;
    ppiVar9 = ppiVar9 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002660(local_1c);
  local_8 = 0;
  ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_28);
  local_8._0_1_ = 1;
  puVar2 = (undefined4 *)FUN_10003f70(local_28);
  piVar3 = (int *)FUN_10003fb0(local_1c);
  local_30 = FUN_100062b0(param_1,param_2,piVar3,puVar2);
  if (-1 < local_30) {
    local_34 = (wchar_t *)0x0;
    FUN_10002660(local_24c);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_278 = (int *)FUN_10003ef0((undefined4 *)local_28);
    uVar4 = FUN_10003fb0(local_24c);
    local_30 = (**(code **)(*local_278 + 0x24))(local_278,0xffffffff,0,0,0,uVar4);
    uVar4 = 0x100073cb;
    if ((-1 < local_30) && (bVar1 = FID_conflict_operator__((CComBSTR *)local_24c), bVar1)) {
      rVar5 = FUN_10009ee0(local_24c);
      FUN_1000fde0(local_240,0x104,local_24c[0],rVar5);
      local_268 = 0x206;
      uStack_3a = 0;
      iVar8 = FUN_10001500(local_240);
      local_26c = iVar8 << 1;
      if (0x207 < local_26c) {
        ___report_rangecheckfailure();
      }
      *(undefined2 *)((int)local_240 + local_26c) = 0;
      local_34 = local_240;
    }
    local_254 = (FARPROC)0x0;
    local_259[0] = '\0';
    local_30 = FUN_100060a0(local_259);
    if (local_30 < 0) {
      local_8._0_1_ = 1;
      local_270 = local_30;
      FUN_10001000(local_24c);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_28);
      local_8 = 0xffffffff;
      FUN_10001000(local_1c);
      goto LAB_100075bd;
    }
    if (local_259[0] == '\x01') {
      local_264 = GetModuleHandleW(L"OLEAUT32.DLL");
      uVar4 = 0x10007518;
      if (local_264 != (HMODULE)0x0) {
        local_254 = GetProcAddress(local_264,"RegisterTypeLibForUser");
        uVar4 = 0x10007542;
      }
    }
    if (local_254 == (FARPROC)0x0) {
      local_254 = Ordinal_163_exref;
    }
    pwVar10 = local_34;
    uVar6 = FUN_10003e70(local_1c);
    uVar7 = FUN_10003dd0((undefined4 *)local_28);
    local_30 = (*local_254)(uVar7,uVar6,pwVar10,uVar4);
    local_8._0_1_ = 1;
    FUN_10001000(local_24c);
  }
  local_274 = local_30;
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_28);
  local_8 = 0xffffffff;
  FUN_10001000(local_1c);
LAB_100075bd:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100075f8);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007680 at 10007680

void FUN_10007680(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xcccccccc;
  local_8 = 0xcccccccc;
  puVar1 = FUN_10002520(&local_c,param_1);
  local_8 = *puVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_8,(ThrowInfo *)&DAT_10025c64);
}



// Function: FUN_100076d0 at 100076d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100076d0(HMODULE param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int **ppiVar4;
  undefined4 uVar5;
  int *local_5c [2];
  int local_54;
  int local_50;
  HMODULE local_4c;
  char local_41 [5];
  FARPROC local_3c;
  int local_34 [2];
  int local_2c;
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> local_24 [12];
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cd80;
  local_10 = ExceptionList;
  ppiVar4 = local_5c;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppiVar4 = (int *)0xcccccccc;
    ppiVar4 = ppiVar4 + 1;
  }
  ExceptionList = &local_10;
  FUN_10002660(local_18);
  local_8 = 0;
  ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_24);
  local_8._0_1_ = 1;
  puVar1 = (undefined4 *)FUN_10003f70(local_24);
  piVar2 = (int *)FUN_10003fb0(local_18);
  local_2c = FUN_100062b0(param_1,param_2,piVar2,puVar1);
  if (-1 < local_2c) {
    local_5c[1] = (int *)FUN_10003ef0((undefined4 *)local_24);
    local_2c = (**(code **)(*local_5c[1] + 0x1c))(local_5c[1],local_34);
    uVar5 = 0x10007773;
    if (-1 < local_2c) {
      local_3c = (FARPROC)0x0;
      local_41[0] = '\0';
      local_2c = FUN_100060a0(local_41);
      if (local_2c < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        local_50 = local_2c;
        FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_24);
        local_8 = 0xffffffff;
        FUN_10001000(local_18);
        iVar3 = local_50;
        uVar5 = extraout_EDX;
        goto LAB_10007891;
      }
      if (local_41[0] == '\x01') {
        local_4c = GetModuleHandleW(L"OLEAUT32.DLL");
        uVar5 = 0x100077e3;
        if (local_4c != (HMODULE)0x0) {
          local_3c = GetProcAddress(local_4c,"UnRegisterTypeLibForUser");
          uVar5 = 0x10007804;
        }
      }
      if (local_3c == (FARPROC)0x0) {
        local_3c = Ordinal_186_exref;
      }
      local_2c = (*local_3c)(local_34[0],(uint)*(ushort *)(local_34[0] + 0x18),
                             (uint)*(ushort *)(local_34[0] + 0x1a),
                             *(undefined4 *)(local_34[0] + 0x10),*(undefined4 *)(local_34[0] + 0x14)
                             ,uVar5);
      uVar5 = 0x10007844;
      local_5c[0] = (int *)FUN_10003ef0((undefined4 *)local_24);
      (**(code **)(*local_5c[0] + 0x30))(local_5c[0],local_34[0],uVar5);
    }
  }
  local_54 = local_2c;
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_24);
  local_8 = 0xffffffff;
  FUN_10001000(local_18);
  iVar3 = local_54;
  uVar5 = extraout_EDX_00;
LAB_10007891:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_100078c0);
  ExceptionList = local_10;
  return CONCAT44(uVar5,iVar3);
}



// Function: FUN_10007930 at 10007930

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPSTR FUN_10007930(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  
  if ((param_1 == (LPSTR)0x0) || (param_2 == (LPCWSTR)0x0)) {
    param_1 = (LPSTR)0x0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      param_1 = (LPSTR)0x0;
    }
  }
  return param_1;
}



// Function: FUN_100079a0 at 100079a0

void __thiscall FUN_100079a0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_100079c0 at 100079c0

void __thiscall FUN_100079c0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: Attach at 100079e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CComBSTR::Attach(unsigned short *)
    public: void __thiscall ATL::CComBSTR::Attach(wchar_t *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __thiscall Attach(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(int *)this = param_1;
  }
  return;
}



// Function: FUN_10007a30 at 10007a30

void __thiscall FUN_10007a30(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_10007a70 at 10007a70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10007a70(LPCSTR param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0xb < local_c) {
      return 1;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_s_AppID_1001f71c)[local_c]);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return 0;
}



// Function: FUN_10007ae0 at 10007ae0

uint __cdecl FUN_10007ae0(char param_1)

{
  uint uVar1;
  
  switch(param_1) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    uVar1 = (int)param_1 - 0x30;
    break;
  default:
    uVar1 = 0;
    break;
  case 'A':
  case 'B':
  case 'C':
  case 'D':
  case 'E':
  case 'F':
    uVar1 = (int)param_1 - 0x37;
    break;
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
    uVar1 = (int)param_1 - 0x57;
  }
  return uVar1;
}



// Function: FUN_10007b80 at 10007b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10007b80(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(stringdispid **)(param_1 + 0x14) != (stringdispid *)0x0) {
      ATL::CComTypeInfoHolder::stringdispid::_vector_deleting_destructor_
                (*(stringdispid **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10007c20 at 10007c20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10007c20(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c;
  
  local_c = 0;
  while( true ) {
    iVar1 = FUN_10008e40((int)param_1);
    if (iVar1 <= local_c) break;
    puVar2 = (undefined4 *)FUN_10008db0(param_1,local_c);
    operator_delete__((void *)*puVar2);
    puVar2 = (undefined4 *)FUN_10009540(param_1,local_c);
    operator_delete__((void *)*puVar2);
    local_c = local_c + 1;
  }
  FUN_1000c730(param_1);
  return 0;
}



// Function: FUN_10007cb0 at 10007cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10007cb0(int param_1)

{
  undefined4 uVar1;
  
  FUN_1000a2e0();
  uVar1 = FUN_10007c20((int *)(param_1 + 4));
  FUN_1000d890();
  return uVar1;
}



// Function: Close at 10007d00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::Close(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

long __thiscall ATL::CRegKey::Close(CRegKey *this)

{
  LSTATUS local_c;
  
  local_c = 0;
  if (*(int *)this != 0) {
    local_c = RegCloseKey(*(HKEY *)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  return local_c;
}



// Function: FUN_10007d70 at 10007d70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall
FUN_10007d70(void *this,HKEY param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4,REGSAM param_5,
            LPSECURITY_ATTRIBUTES param_6,DWORD *param_7)

{
  DWORD extraout_EDX;
  DWORD extraout_EDX_00;
  DWORD extraout_EDX_01;
  DWORD DVar1;
  int local_28;
  long local_24;
  HKEY local_1c;
  undefined4 local_18;
  undefined4 local_14;
  DWORD local_10 [2];
  CRegKey *local_8;
  
  local_18 = 0xcccccccc;
  local_14 = 0xcccccccc;
  local_10[0] = 0xcccccccc;
  local_10[1] = 0xcccccccc;
  local_1c = (HKEY)0x0;
  local_8 = (CRegKey *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_28 = RegCreateKeyExA(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_1c,local_10)
    ;
    DVar1 = extraout_EDX_00;
  }
  else {
    local_28 = FUN_1000afe0(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,
                            param_6,&local_1c,local_10);
    DVar1 = extraout_EDX;
  }
  local_24 = local_28;
  if (param_7 != (DWORD *)0x0) {
    *param_7 = local_10[0];
    DVar1 = local_10[0];
  }
  if (local_28 == 0) {
    local_24 = ATL::CRegKey::Close(local_8);
    *(HKEY *)local_8 = local_1c;
    DVar1 = extraout_EDX_01;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10007e64);
  return CONCAT44(DVar1,local_24);
}



// Function: FUN_10007e90 at 10007e90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10007e90(IUnknownVtbl *param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001cdb2;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    this = (void *)FUN_1001aa60(0x128);
    local_8._0_1_ = 1;
    if (this != (void *)0x0) {
      FUN_10001c30(this,param_1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar1 = FUN_10007f56();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10007f50 at 10007f50

undefined * Catch_10007f50(void)

{
  return &DAT_10007f5f;
}



// Function: FUN_10007f56 at 10007f56

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10007f56(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_1000d3f0();
    FUN_100099c0();
    iVar1 = FUN_1000ea00(*(int *)(unaff_EBP + -0x18));
    *(int *)(unaff_EBP + -0x14) = iVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_10008680(*(int *)(unaff_EBP + -0x18));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_1000e9d0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    FUN_10009a10();
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10008050 at 10008050

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10008050(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  IUnknown *pIVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001cde2;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    pIVar1 = (IUnknown *)FUN_1001aa60(0x118);
    local_8._0_1_ = 1;
    if (pIVar1 != (IUnknown *)0x0) {
      FUN_10001de0(pIVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_10008116();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10008110 at 10008110

undefined * Catch_10008110(void)

{
  return &DAT_1000811f;
}



// Function: FUN_10008116 at 10008116

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10008116(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_1000d3f0();
    FUN_100099e0(*(int *)(unaff_EBP + -0x18));
    uVar1 = FUN_1000ea50(*(int *)(unaff_EBP + -0x18) + 0x10);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x14))
                        (*(undefined4 *)(unaff_EBP + -0x18));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_1000e9d0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    FUN_10009a30(*(int *)(unaff_EBP + -0x18));
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x28);
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x10))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10008220 at 10008220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_10008220(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 == 0) || (iVar1 = ATL::InlineIsEqualUnknown(param_3), iVar1 != 0)) {
      local_8 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
    }
    else {
      local_8 = 0x80040110;
    }
  }
  return local_8;
}



// Function: FUN_100082a0 at 100082a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100082a0(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_100082d0 at 100082d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100082d0(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10008300 at 10008300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10008300(void *this,LPCSTR param_1)

{
  if (*(int *)((int)this + 8) == 0) {
                    /* WARNING: Load size is inaccurate */
    RegDeleteKeyA(*this,param_1);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_1000b0f0(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_10008360 at 10008360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10008360(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegDeleteValueA(*this,param_1);
  return;
}



// Function: FUN_100083a0 at 100083a0

undefined4 __fastcall FUN_100083a0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_100083d0 at 100083d0

undefined4 __fastcall FUN_100083d0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10008400 at 10008400

undefined4 __fastcall FUN_10008400(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10008430 at 10008430

undefined4 __fastcall FUN_10008430(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10008460 at 10008460

undefined4 __fastcall FUN_10008460(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = param_1[2];
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return uVar1;
}



// Function: FUN_100084b0 at 100084b0

undefined4 __fastcall FUN_100084b0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return uVar1;
}



// Function: FUN_10008500 at 10008500

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10008500(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if ((*(char *)*param_1 == '\'') && (pCVar1 = CharNextA((LPCSTR)*param_1), *pCVar1 != '\'')) {
    return 1;
  }
  return 0;
}



// Function: FUN_10008570 at 10008570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10008570(void *this,undefined4 param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_c = FUN_10008e60(this,param_1);
  }
  return local_c;
}



// Function: FUN_100085d0 at 100085d0

void __cdecl FUN_100085d0(short *param_1,int param_2,short *param_3)

{
  short *psVar1;
  uint local_8;
  
  if (param_2 != 0) {
    local_8 = 0;
    for (; (local_8 < param_2 - 1U && (*param_3 != 0)); param_3 = param_3 + 1) {
      *param_1 = *param_3;
      psVar1 = param_1 + 1;
      if ((*param_3 == 0x27) && (local_8 = local_8 + 1, local_8 < param_2 - 1U)) {
        *psVar1 = *param_3;
        psVar1 = param_1 + 2;
      }
      param_1 = psVar1;
      local_8 = local_8 + 1;
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10008680 at 10008680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10008680(int param_1)

{
  FUN_100086d0();
  (**(code **)(*(int *)(param_1 + 0x10) + 0x14))(param_1 + 0x10);
  return;
}



// Function: FUN_100086d0 at 100086d0

undefined4 FUN_100086d0(void)

{
  return 0;
}



// Function: FUN_100086f0 at 100086f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100086f0(void)

{
  FUN_10009790();
  return;
}



// Function: ~_ATL_WIN_MODULE70 at 10008720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::_ATL_WIN_MODULE70::~_ATL_WIN_MODULE70(void)
   
   Library: Visual Studio 2015 Debug */

void __thiscall ATL::_ATL_WIN_MODULE70::~_ATL_WIN_MODULE70(_ATL_WIN_MODULE70 *this)

{
  CComCriticalSection::~CComCriticalSection((CComCriticalSection *)(this + 4));
  CComCriticalSection::~CComCriticalSection((CComCriticalSection *)(this + 0x20));
  return;
}



// Function: ~CComCriticalSection at 10008760

/* Library Function - Single Match
    public: __thiscall ATL::CComCriticalSection::~CComCriticalSection(void)
   
   Library: Visual Studio 2015 Debug */

void __thiscall ATL::CComCriticalSection::~CComCriticalSection(CComCriticalSection *this)

{
  return;
}



// Function: FUN_10008780 at 10008780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10008780(void *this,undefined4 *param_1)

{
  bool bVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (*(int *)((int)this + 8) <= local_c) {
      return -1;
    }
                    /* WARNING: Load size is inaccurate */
    bVar1 = FUN_10009cd0(*(LPCSTR *)(*this + local_c * 4),(LPCSTR)*param_1);
    if (bVar1) break;
    local_c = local_c + 1;
  }
  return local_c;
}



// Function: Free at 100087f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned short>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
     9 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: Free at 10008840

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned short>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
     9 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10008890 at 10008890

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10008890(void *param_1)

{
  free(param_1);
  return;
}



// Function: FreeHeap at 100088c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10008890((void *)*param_1);
  return;
}



// Function: FreeHeap at 100088f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10008890((void *)*param_1);
  return;
}



// Function: FreeHeap at 10008920

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10008890((void *)*param_1);
  return;
}



// Function: FUN_10008950 at 10008950

undefined4 FUN_10008950(void)

{
  return 0x80020009;
}



// Function: FUN_10008970 at 10008970

undefined ** FUN_10008970(void)

{
  return &PTR_1001ff18;
}



// Function: FUN_10008980 at 10008980

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10008980(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ce38;
  local_10 = ExceptionList;
  local_28 = 0xcccccccc;
  local_24 = 0xcccccccc;
  local_20 = 0xcccccccc;
  local_1c = (int *)0xcccccccc;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_3 = 0;
  local_18 = 0;
  local_14 = this;
  if (*(int *)((int)this + 0x2c) != 0) {
    for (local_1c = *(int **)((int)this + 0x2c); *local_1c != 0; local_1c = local_1c + 9) {
      if ((local_1c[2] != 0) &&
         (iVar2 = FID_conflict__AfxIsEqualGUID(param_1,(int *)*local_1c), iVar2 != 0)) {
        if (local_1c[4] == 0) {
          FUN_10001d80(&local_28,&DAT_1002996c,'\0');
          local_8 = 0;
          local_18 = FUN_1000a220(&local_28);
          if (local_18 < 0) {
            local_8 = 0xffffffff;
            FUN_10002f70(&local_28);
            break;
          }
          if (local_1c[4] == 0) {
            local_18 = (*(code *)local_1c[2])(local_1c[3],&DAT_1001f428,local_1c + 4,uVar1);
            uVar1 = 0x10008a8a;
          }
          local_8 = 0xffffffff;
          FUN_10002f70(&local_28);
        }
        if (local_1c[4] != 0) {
          local_18 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_2,param_3,uVar1);
        }
        break;
      }
    }
  }
  if ((*param_3 == 0) && (local_18 == 0)) {
    uVar3 = FUN_10005af0(param_2,param_1,(int *)&DAT_1002995c,param_1,param_2,param_3);
    param_3 = (int *)((ulonglong)uVar3 >> 0x20);
    local_18 = (int)uVar3;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10008b34);
  ExceptionList = local_10;
  return CONCAT44(param_3,local_18);
}



// Function: GetData at 10008b50

/* Library Function - Single Match
    public: void * __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::CAtlSafeAllocBufferNode::GetData(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void * __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
CAtlSafeAllocBufferNode::GetData(CAtlSafeAllocBufferNode *this)

{
  return this + 8;
}



// Function: FUN_10008b70 at 10008b70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10008b70(void *this,undefined4 *param_1)

{
  int local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_c = CoCreateInstance((IID *)&DAT_1002182c,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001f454,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_c) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_c;
}



// Function: FUN_10008c20 at 10008c20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10008c20(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10008c50(&PTR_DAT_10029068,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008c50 at 10008c50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall
FUN_10008c50(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  size_t sVar1;
  void *_Buf1;
  int iVar2;
  size_t _Size;
  void *_Buf2;
  int local_14;
  int local_c;
  
  local_c = FUN_10008570(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = -0x7fffbffb;
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      sVar1 = FUN_1000fc90((wchar_t *)*param_2);
      local_14 = *(int *)((int)this + 0x18);
      do {
        do {
          local_14 = local_14 + -1;
          if (local_14 < 0) goto LAB_10008d63;
        } while (sVar1 != *(size_t *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc));
        _Size = *(int *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc) << 1;
        _Buf2 = (void *)*param_2;
        _Buf1 = (void *)FUN_10003e70((undefined4 *)(*(int *)((int)this + 0x14) + local_14 * 0xc));
        iVar2 = memcmp(_Buf1,_Buf2,_Size);
      } while (iVar2 != 0);
      *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + local_14 * 0xc);
      local_c = 0;
    }
LAB_10008d63:
    if (local_c < 0) {
      local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                          (*(undefined4 *)((int)this + 0xc),param_2,param_3,param_5);
    }
  }
  return local_c;
}



// Function: FUN_10008db0 at 10008db0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10008db0(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    ATL::_AtlRaiseException(0xc000008c,1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this + param_1 * 4;
}



// Function: FUN_10008e00 at 10008e00

undefined4 __fastcall FUN_10008e00(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10008e20 at 10008e20

undefined4 __fastcall FUN_10008e20(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10008e40 at 10008e40

undefined4 __fastcall FUN_10008e40(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10008e60 at 10008e60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10008e60(void *this,undefined4 param_1)

{
  char cVar1;
  HMODULE hModule;
  size_t sVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  LPWSTR *ppWVar8;
  undefined8 uVar9;
  CHAR *lpFilename;
  DWORD nSize;
  LPWSTR local_1c0 [2];
  int local_1b8;
  LPWSTR local_1b4;
  LPWSTR local_1b0;
  _RTC_ALLOCA_NODE *local_1a8 [2];
  int local_1a0;
  undefined4 local_19c;
  int local_198;
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> local_190 [12];
  int local_184 [3];
  CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> local_178 [8];
  LPWSTR local_170;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_168 [8];
  char *local_160;
  UINT local_158;
  ulong local_150 [2];
  DWORD local_148;
  CHAR local_140 [268];
  int *local_34 [2];
  int local_2c;
  undefined4 local_24 [3];
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ce94;
  local_10 = ExceptionList;
  ppWVar8 = local_1c0;
  for (iVar7 = 0x6c; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppWVar8 = (LPWSTR)0xcccccccc;
    ppWVar8 = ppWVar8 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1a8[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_18 = (undefined4 *)this;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10001d80(local_24,(int)DAT_1002987c + 0x10,'\0');
    local_8 = 0;
    local_2c = FUN_1000a220(local_24);
    if (local_2c < 0) {
      local_8 = 0xffffffff;
      local_198 = local_2c;
      FUN_10002f70(local_24);
    }
    else {
      local_2c = -0x7fffbffb;
      if (local_18[3] == 0) {
        local_34[0] = (int *)0x0;
        iVar7 = FID_conflict__AfxIsEqualGUID((int *)&DAT_10029880,(int *)local_18[1]);
        if (((iVar7 == 0) || (*(short *)(local_18 + 2) != -1)) ||
           (*(short *)((int)local_18 + 10) != -1)) {
          local_2c = Ordinal_162(local_18[1],*(undefined2 *)(local_18 + 2),
                                 *(undefined2 *)((int)local_18 + 10),param_1);
        }
        else {
          nSize = 0x104;
          lpFilename = local_140;
          hModule = (HMODULE)FUN_10008e20(0x10029924);
          local_148 = GetModuleFileNameA(hModule,lpFilename,nSize);
          if ((local_148 != 0) && (local_148 != 0x104)) {
            local_158 = FUN_1000e9f0();
            FUN_10001bd0((undefined4 *)local_168);
            local_8._0_1_ = 1;
            local_160 = local_140;
            if (local_160 == (char *)0x0) {
              local_1b0 = (LPWSTR)0x0;
            }
            else {
              sVar2 = strlen(local_160);
              local_150[0] = sVar2 + 1;
              lVar3 = ATL::AtlMultiply<int>((int *)local_150,local_150[0],2);
              if (lVar3 < 0) {
                local_1b4 = (LPWSTR)0x0;
              }
              else {
                if (((int)local_150[0] < 0x401) &&
                   (cVar1 = FUN_1000eae0(local_150[0]), cVar1 != '\0')) {
                  local_1b8 = local_150[0] + 0x24;
                  local_1c0[1] = (LPWSTR)&stack0xfffffe30;
                  _RTC_AllocaHelper(&stack0xfffffe30,local_1b8,local_1a8);
                  local_1c0[0] = (LPWSTR)((int)local_1c0[1] + 0x20);
                  local_1c0[1] = local_1c0[0];
                }
                else {
                  local_1c0[0] = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                                         Allocate(local_168,local_150[0]);
                }
                local_1b4 = FUN_100058b0(local_1c0[0],local_160,local_150[0] >> 1,local_158);
              }
              local_1b0 = local_1b4;
            }
            local_170 = local_1b0;
            if (local_1b0 == (LPWSTR)0x0) {
              local_19c = 0x8007000e;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_168);
              local_8 = 0xffffffff;
              FUN_10002f70(local_24);
              goto LAB_10009301;
            }
            local_2c = Ordinal_161(local_1b0,local_34);
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_168);
          }
        }
        if (-1 < local_2c) {
          ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
          CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_178);
          local_8._0_1_ = 2;
          uVar4 = FUN_10003f50(local_178);
          local_2c = (**(code **)(*local_34[0] + 0x18))(local_34[0],*local_18,uVar4);
          uVar4 = 0x100091e8;
          if (-1 < local_2c) {
            FUN_10002090(local_184,(int *)local_178);
            local_8._0_1_ = 3;
            ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
            CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_190);
            local_8 = CONCAT31(local_8._1_3_,4);
            uVar5 = FUN_10003f30(local_190);
            puVar6 = (undefined4 *)FUN_10003ed0((undefined4 *)local_178);
            iVar7 = QueryInterface<>(puVar6,uVar5);
            if (-1 < iVar7) {
              FUN_10001640(local_184,(undefined4 *)local_190);
            }
            uVar5 = FUN_10008400(local_184);
            local_18[3] = uVar5;
            FUN_10004bc0(DAT_1002987c,FUN_10007b80,local_18);
            local_8._0_1_ = 3;
            FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_190);
            local_8._0_1_ = 2;
            FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_184);
          }
          (**(code **)(*local_34[0] + 8))(local_34[0],uVar4);
          local_8 = (uint)local_8._1_3_ << 8;
          FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)local_178);
        }
      }
      else {
        local_2c = 0;
      }
      if ((local_18[3] != 0) && (local_18[5] == 0)) {
        uVar9 = FUN_10009f30((int *)local_18[3]);
        local_2c = (int)uVar9;
      }
      local_1a0 = local_2c;
      local_8 = 0xffffffff;
      FUN_10002f70(local_24);
    }
  }
LAB_10009301:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000933c,local_1a8[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009420 at 10009420

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_10009420(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      local_c = FUN_10008e60(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(undefined4 *)((int)this + 0xc));
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_100094b0 at 100094b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100094b0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_100094e0(&PTR_DAT_10029068,param_2,param_3,param_4);
  return;
}



// Function: FUN_100094e0 at 100094e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_100094e0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_10009420(this,param_2,param_3);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: GetTypeInfoCount at 10009520

/* Library Function - Single Match
    public: virtual long __stdcall CWnd::XAccessible::GetTypeInfoCount(unsigned int *)
   
   Library: Visual Studio */

long CWnd::XAccessible::GetTypeInfoCount(uint *param_1)

{
  long lVar1;
  undefined4 *in_stack_00000008;
  
  if (in_stack_00000008 == (undefined4 *)0x0) {
    lVar1 = -0x7fffbffd;
  }
  else {
    *in_stack_00000008 = 1;
    lVar1 = 0;
  }
  return lVar1;
}



// Function: FUN_10009540 at 10009540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10009540(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    ATL::_AtlRaiseException(0xc000008c,1);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: FUN_10009590 at 10009590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __cdecl FUN_10009590(LPCSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_DAT_1001fb60)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_1001fb64 + local_8 * 8);
}



// Function: FUN_10009600 at 10009600

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10009600(HKEY param_1)

{
  LSTATUS LVar1;
  undefined4 extraout_EDX;
  undefined4 uVar2;
  uint local_18;
  DWORD local_10 [3];
  
  local_10[1] = 0xcccccccc;
  local_10[0] = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_10,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar1 == 0) {
    local_18 = (uint)(local_10[0] != 0);
  }
  else {
    local_18 = 0;
  }
  uVar2 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009694);
  return CONCAT44(uVar2,local_18);
}



// Function: FUN_100096c0 at 100096c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100096c0(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_100096f0 at 100096f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100096f0(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_10009720 at 10009720

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT __fastcall FUN_10009720(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  DWORD x;
  undefined4 local_c;
  
  local_c = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    x = GetLastError();
    local_c = _HRESULT_FROM_WIN32(x);
  }
  return local_c;
}



// Function: FUN_10009790 at 10009790

undefined4 FUN_10009790(void)

{
  return 0;
}



// Function: FUN_100097b0 at 100097b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_100097b0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_10;
  int *local_c;
  
  if (param_3 != (undefined4 *)0x0) {
    _DAT_10029880 = *param_3;
    _DAT_10029884 = param_3[1];
    _DAT_10029888 = param_3[2];
    _DAT_1002988c = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_c = *(int **)((int)this + 0x2c); *local_c != 0; local_c = local_c + 9) {
      (*(code *)local_c[8])(1);
    }
  }
  for (local_10 = DAT_10029964; local_10 < DAT_10029968; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x1c))(1);
    }
  }
  return 0;
}



// Function: FUN_100098a0 at 100098a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

HRESULT __fastcall FUN_100098a0(LPCRITICAL_SECTION param_1)

{
  HRESULT HVar1;
  
  HVar1 = FUN_10009720(param_1);
  if (-1 < HVar1) {
    *(undefined1 *)&param_1[1].DebugInfo = 1;
  }
  return HVar1;
}



// Function: FUN_100098e0 at 100098e0

void FUN_100098e0(void)

{
  return;
}



// Function: InlineIsEqualUnknown at 100098f0

/* Library Function - Single Match
    int __stdcall ATL::InlineIsEqualUnknown(struct _GUID const &)
   
   Library: Visual Studio 2012 Debug */

int ATL::InlineIsEqualUnknown(_GUID *param_1)

{
  int iVar1;
  int local_8;
  
  if ((((param_1->Data1 == 0) &&
       (iVar1._0_2_ = param_1->Data2, iVar1._2_2_ = param_1->Data3, iVar1 == 0)) &&
      (*(int *)param_1->Data4 == 0xc0)) && (*(int *)(param_1->Data4 + 4) == 0x46000000)) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_10009960 at 10009960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009960(LONG *param_1)

{
  FUN_100096c0(param_1);
  return;
}



// Function: FUN_10009990 at 10009990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009990(LONG *param_1)

{
  FUN_100096f0(param_1);
  return;
}



// Function: FUN_100099c0 at 100099c0

void FUN_100099c0(void)

{
  return;
}



// Function: FUN_100099e0 at 100099e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100099e0(int param_1)

{
  FUN_10009960((LONG *)(param_1 + 0x10));
  return;
}



// Function: FUN_10009a10 at 10009a10

void FUN_10009a10(void)

{
  return;
}



// Function: FUN_10009a30 at 10009a30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009a30(int param_1)

{
  CRect::SwapLeftRight((CRect *)(param_1 + 0x10));
  return;
}



// Function: FUN_10009a60 at 10009a60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10009a60(int param_1,int *param_2,_GUID *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_10006130(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: SwapLeftRight at 10009aa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: void __thiscall CRect::SwapLeftRight(void)
   
   Library: Visual Studio 2015 Debug */

void __thiscall CRect::SwapLeftRight(CRect *this)

{
  FUN_100082a0((LONG *)this);
  return;
}



// Function: SwapLeftRight at 10009ad0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: void __thiscall CRect::SwapLeftRight(void)
   
   Library: Visual Studio 2015 Debug */

void __thiscall CRect::SwapLeftRight(CRect *this)

{
  FUN_100082d0((LONG *)this);
  return;
}



// Function: FUN_10009b00 at 10009b00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10009b00(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cef3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  pvVar1 = (void *)FUN_10001600(4,*this + param_1 * 4);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_100023b0(pvVar1,param_2);
  }
  local_8 = 0xffffffff;
  pvVar1 = (void *)FUN_10001610(4,*(int *)((int)this + 4) + param_1 * 4);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_100023e0(pvVar1,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009c00 at 10009c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10009c00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10009c40(&PTR_DAT_10029068,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10009c40 at 10009c40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall
FUN_10009c40(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 local_c;
  
  local_c = FUN_10008570(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
                        (*(undefined4 *)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,
                         param_8,param_9);
  }
  return local_c;
}



// Function: FUN_10009cc1 at 10009cc1

undefined8 __fastcall FUN_10009cc1(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = CTextFileStreamObj_IsDirty(param_1,param_2,param_3 + -8);
  return uVar1;
}



// Function: FUN_10009cd0 at 10009cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_10009cd0(LPCSTR param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = lstrcmpiA(param_1,param_2);
  return iVar1 == 0;
}



// Function: FUN_10009d00 at 10009d00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10009d00(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  uint uVar2;
  uint3 uVar5;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar6;
  undefined4 uVar7;
  int local_28 [3];
  int local_1c [2];
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cf20;
  local_10 = ExceptionList;
  local_28[0] = -0x33333334;
  local_28[1] = 0xcccccccc;
  local_28[2] = 0xcccccccc;
  local_1c[0] = -0x33333334;
  local_1c[1] = 0xcccccccc;
  uVar2 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar5 = (uint3)((uint)param_1 >> 8);
  local_14 = param_1;
  if ((*param_1 == 0) && (param_3 == (undefined4 *)0x0)) {
    iVar4 = CONCAT31(uVar5,1);
  }
  else if ((*param_1 == 0) || (param_3 == (undefined4 *)0x0)) {
    iVar4 = (uint)uVar5 << 8;
  }
  else {
    ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
    CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
              ((CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *)local_1c);
    local_8 = 0;
    ATL::CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>::
    CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
              ((CHeapPtr<unsigned_short,class_ATL::CCRTAllocator> *)local_28);
    local_8._0_1_ = 1;
    uVar3 = FUN_10003f90(local_1c);
    (*(code *)**(undefined4 **)*local_14)(*local_14,&DAT_1001f428,uVar3,uVar2);
    uVar7 = 0x10009db3;
    uVar3 = FUN_10003f90(local_28);
    (**(code **)*param_3)(param_3,&DAT_1001f428,uVar3,uVar7);
    iVar4 = FUN_10003df0(local_28);
    bVar1 = FUN_10003c10(local_1c,iVar4);
    local_8 = (uint)local_8._1_3_ << 8;
    FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_28);
    local_8 = 0xffffffff;
    uVar6 = FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>(local_1c);
    param_2 = (undefined4)((ulonglong)uVar6 >> 0x20);
    iVar4 = CONCAT31((int3)((ulonglong)uVar6 >> 8),bVar1);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10009e38);
  ExceptionList = local_10;
  return CONCAT44(param_2,iVar4);
}



// Function: FUN_10009e70 at 10009e70

undefined4 FUN_10009e70(undefined1 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 9:
  case 10:
  case 0xd:
  case 0x20:
    uVar1 = 1;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10009ee0 at 10009ee0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10009ee0(undefined4 *param_1)

{
  Ordinal_7(*param_1);
  return;
}



// Function: FUN_10009f30 at 10009f30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10009f30(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint **ppuVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  uint *local_54 [3];
  uint local_48;
  undefined4 local_40 [3];
  uint *local_34 [2];
  int local_2c;
  uint *local_28;
  int local_24;
  int local_1c [2];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cf5a;
  local_10 = ExceptionList;
  ppuVar4 = local_54;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar4 = (uint *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  ExceptionList = &local_10;
  piVar9 = param_1;
  uVar5 = (**(code **)(*param_1 + 0xc))(param_1,local_1c,DAT_10029830 ^ (uint)&stack0xfffffffc);
  local_24 = (int)uVar5;
  if (-1 < local_24) {
    local_28 = (uint *)0x0;
    *(uint *)(local_14 + 0x18) = (uint)*(ushort *)(local_1c[0] + 0x2c);
    *(undefined4 *)(local_14 + 0x14) = 0;
    if (*(int *)(local_14 + 0x18) != 0) {
      local_48 = *(uint *)(local_14 + 0x18);
      uVar3 = -(uint)((int)((ulonglong)local_48 * 0xc >> 0x20) != 0) |
              (uint)((ulonglong)local_48 * 0xc);
      local_54[1] = (uint *)FUN_1001aa8e(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
      local_8 = 0;
      if (local_54[1] == (uint *)0x0) {
        local_54[0] = (uint *)0x0;
      }
      else {
        *local_54[1] = local_48;
        _eh_vector_constructor_iterator_
                  (local_54[1] + 1,0xc,local_48,FUN_10002cd0,
                   FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>);
        local_54[0] = local_54[1] + 1;
      }
      local_54[2] = local_54[0];
      local_8 = 0xffffffff;
      local_28 = local_54[0];
      if (local_54[0] == (uint *)0x0) {
        (**(code **)(*param_1 + 0x4c))(param_1,local_1c[0]);
        uVar5 = CONCAT44(extraout_EDX,local_24);
        uVar1 = 0x8007000e;
        goto LAB_1000a1a8;
      }
    }
    for (local_2c = 0; local_2c < *(int *)(local_14 + 0x18); local_2c = local_2c + 1) {
      iVar2 = (**(code **)(*param_1 + 0x14))(param_1,local_2c,local_34);
      piVar9 = (int *)0x1000a0b8;
      if (-1 < iVar2) {
        FUN_10002660(local_40);
        local_8 = 1;
        uVar8 = 0;
        uVar7 = 0;
        uVar6 = 0;
        uVar1 = FUN_10003fb0(local_40);
        iVar2 = (**(code **)(*param_1 + 0x30))(param_1,*local_34[0],uVar1,uVar6,uVar7,uVar8);
        uVar1 = 0x1000a0fb;
        if (-1 < iVar2) {
          iVar2 = FUN_10008430(local_40);
          Attach(local_28 + local_2c * 3,iVar2);
          uVar1 = FUN_10003e70(local_28 + local_2c * 3);
          uVar3 = Ordinal_7(uVar1);
          uVar1 = 0x1000a134;
          local_28[local_2c * 3 + 1] = uVar3;
          local_28[local_2c * 3 + 2] = *local_34[0];
        }
        (**(code **)(*param_1 + 0x50))(param_1,local_34[0],uVar1);
        piVar9 = (int *)0x1000a16e;
        local_8 = 0xffffffff;
        FUN_10001000(local_40);
      }
    }
    *(uint **)(local_14 + 0x14) = local_28;
    (**(code **)(*param_1 + 0x4c))(param_1,local_1c[0],piVar9);
    uVar5 = CONCAT44(extraout_EDX_00,local_24);
  }
  uVar1 = 0;
LAB_1000a1a8:
  uVar6 = (undefined4)((ulonglong)uVar5 >> 0x20);
  local_24 = (int)uVar5;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000a1d8);
  ExceptionList = local_10;
  return CONCAT44(uVar6,uVar1);
}



// Function: FUN_1000a220 at 1000a220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_1000a220(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000a2a0((LPCRITICAL_SECTION)*param_1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 1) = 1;
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_1000a270 at 1000a270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000a270(int param_1)

{
  FUN_100096c0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000a2a0 at 1000a2a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000a2a0(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  return 0;
}



// Function: FUN_1000a2e0 at 1000a2e0

undefined4 FUN_1000a2e0(void)

{
  return 0;
}



// Function: FUN_1000a300 at 1000a300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000a300(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1002987c + 8))();
  }
  else {
    (**(code **)(*DAT_1002987c + 4))();
  }
  return 0;
}



// Function: FUN_1000a360 at 1000a360

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000a360(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_10008780(this,param_1);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_10009540(this,iVar1);
    uVar2 = *puVar3;
  }
  return uVar2;
}



// Function: FUN_1000a3b0 at 1000a3b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __thiscall FUN_1000a3b0(void *this,undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  LPSTR pCVar3;
  int iVar4;
  LPCSTR pCVar5;
  int local_24;
  undefined1 *local_1c;
  int local_18;
  undefined1 *local_10;
  
  puVar1 = param_1;
  pCVar5 = (LPCSTR)0x1000a3df;
  FUN_1000d4f0((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  if (**this == '\0') {
    uVar2 = FUN_10008950();
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (**this == '\'') {
                    /* WARNING: Load size is inaccurate */
      pCVar3 = CharNextA(*this);
      pCVar5 = (LPCSTR)0x1000a429;
      *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
      while ((**this != '\0' && (iVar4 = FUN_10008500((undefined4 *)this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == '\'') {
                    /* WARNING: Load size is inaccurate */
          pCVar3 = CharNextA(*this);
          pCVar5 = (LPCSTR)0x1000a470;
          *(LPSTR *)this = pCVar3;
        }
                    /* WARNING: Load size is inaccurate */
        local_10 = *this;
        pCVar3 = CharNextA(pCVar5);
        pCVar5 = (LPCSTR)0x1000a492;
        *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_10;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_10008950();
          return uVar2;
        }
        for (local_18 = 0; local_18 < iVar4; local_18 = local_18 + 1) {
          *param_1 = *local_10;
          param_1 = param_1 + 1;
          local_10 = local_10 + 1;
        }
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == '\0') {
        uVar2 = FUN_10008950();
        return uVar2;
      }
      *param_1 = 0;
                    /* WARNING: Load size is inaccurate */
      pCVar3 = CharNextA(*this);
      *(LPSTR *)this = pCVar3;
    }
    else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      while ((**this != '\0' && (iVar4 = FUN_10009e70(**this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        local_1c = *this;
        pCVar3 = CharNextA(pCVar5);
        pCVar5 = (LPCSTR)0x1000a591;
        *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_1c;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_10008950();
          return uVar2;
        }
        for (local_24 = 0; local_24 < iVar4; local_24 = local_24 + 1) {
          *param_1 = *local_1c;
          param_1 = param_1 + 1;
          local_1c = local_1c + 1;
        }
      }
      *param_1 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000a620 at 1000a620

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_1000a620(void *this,HKEY param_1,LPCSTR param_2,REGSAM param_3)

{
  int extraout_EDX;
  int local_1c;
  long local_18;
  HKEY local_10;
  undefined4 local_c;
  CRegKey *local_8;
  
  local_c = 0xcccccccc;
  local_10 = (HKEY)0x0;
  local_8 = (CRegKey *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_1c = RegOpenKeyExA(param_1,param_2,0,param_3,&local_10);
  }
  else {
    local_1c = FUN_1000b1c0(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_10);
  }
  local_18 = local_1c;
  if (local_1c == 0) {
    local_18 = ATL::CRegKey::Close(local_8);
    *(HKEY *)local_8 = local_10;
    local_1c = extraout_EDX;
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000a6e0);
  return CONCAT44(local_1c,local_18);
}



// Function: FUN_1000a700 at 1000a700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000a700(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 4))(*param_1);
  return;
}



// Function: FUN_1000a740 at 1000a740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000a740(void *this,undefined4 param_1,undefined4 param_2)

{
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  (**(code **)**this)(*this,param_1,param_2);
  return;
}



// Function: FUN_1000a790 at 1000a790

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000a790(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 8))(*param_1);
  return;
}



// Function: FUN_1000a7d0 at 1000a7d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000a7d0(void *this,char *param_1,undefined4 *param_2)

{
  size_t sVar1;
  LPSTR pCVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  LPCSTR in_stack_ffffff6c;
  uchar local_80 [36];
  size_t local_5c;
  LPCSTR local_58;
  int local_54;
  wchar_t *local_50;
  wchar_t *local_4c;
  char local_46;
  char local_45;
  int local_44;
  char local_39 [5];
  int local_34;
  undefined4 local_2c [2];
  int local_24;
  int local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cf88;
  local_10 = ExceptionList;
  puVar6 = (undefined4 *)&stack0xffffff6c;
  for (iVar5 = 0x21; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (int *)this;
  if ((param_1 != (char *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    sVar1 = strlen(param_1);
    local_1c = sVar1 << 1;
    FUN_100028a0(local_2c,local_1c);
    local_8 = 0;
    if (local_24 == 0) {
      local_8 = 0xffffffff;
      FUN_10003920((int)local_2c);
    }
    else {
      *local_18 = (int)param_1;
      local_34 = 0;
      local_39[0] = '\0';
      local_34 = FUN_100060a0(local_39);
      if (local_34 < 0) {
        local_8 = 0xffffffff;
        FUN_10003920((int)local_2c);
      }
      else {
        local_44 = 0;
        local_45 = '\0';
        local_46 = '\0';
        while (*(char *)*local_18 != '\0') {
          if (local_39[0] == '\x01') {
            local_4c = L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses";
            local_50 = L"\r\n\t}\r\n}\r\n";
            if (local_44 == 0) {
              local_54 = 0;
              local_54 = FUN_1000f280((char *)*local_18,0x1001fbd0);
              if ((local_54 != 0) && (local_54 == *local_18)) {
                pCVar2 = CharNextA(in_stack_ffffff6c);
                in_stack_ffffff6c = (LPCSTR)0x1000a957;
                *local_18 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_18);
                *local_18 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_18);
                *local_18 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_18);
                *local_18 = (int)pCVar2;
                iVar5 = FUN_100049a0(local_2c,local_4c);
                if (iVar5 == 0) {
                  local_34 = -0x7ff8fff2;
                  break;
                }
                local_45 = '\x01';
              }
            }
            if (*(char *)*local_18 == '\'') {
              if (local_46 == '\0') {
                local_46 = '\x01';
              }
              else {
                iVar5 = FUN_10008500(local_18);
                if (iVar5 == 0) {
                  pCVar2 = CharNextA((LPCSTR)*local_18);
                  *local_18 = (int)pCVar2;
                  uVar7 = FUN_100045a0(local_2c,(LPCSTR)*local_18);
                  if ((int)uVar7 == 0) {
                    local_34 = -0x7ff8fff2;
                    break;
                  }
                }
                else {
                  local_46 = '\0';
                }
              }
            }
            if ((local_46 == '\0') && (*(char *)*local_18 == '{')) {
              local_44 = local_44 + 1;
            }
            if ((((local_46 == '\0') && (*(char *)*local_18 == '}')) &&
                (local_44 = local_44 + -1, local_44 == 0)) && (local_45 == '\x01')) {
              iVar5 = FUN_100049a0(local_2c,local_50);
              if (iVar5 == 0) {
                local_34 = -0x7ff8fff2;
                break;
              }
              local_45 = '\0';
            }
          }
          if (*(char *)*local_18 == '%') {
            pCVar2 = CharNextA((LPCSTR)*local_18);
            *local_18 = (int)pCVar2;
            if (*(char *)*local_18 == '%') {
              uVar7 = FUN_100045a0(local_2c,(LPCSTR)*local_18);
              if ((int)uVar7 == 0) {
                local_34 = -0x7ff8fff2;
                break;
              }
            }
            else {
              local_58 = FUN_1000d540((LPSTR)*local_18,'%');
              if (local_58 == (LPCSTR)0x0) {
                local_34 = FUN_10008950();
                break;
              }
              if (0x1f < (int)local_58 - *local_18) {
                local_34 = -0x7fffbffb;
                break;
              }
              local_5c = (int)local_58 - *local_18;
              FUN_1000fd70(local_80,0x20,(uchar *)*local_18,local_5c);
              pwVar3 = (wchar_t *)FUN_1000d5b0(local_18[1]);
              if (pwVar3 == (wchar_t *)0x0) {
                local_34 = FUN_10008950();
                break;
              }
              iVar5 = FUN_100049a0(local_2c,pwVar3);
              if (iVar5 == 0) {
                local_34 = -0x7ff8fff2;
                break;
              }
              while ((LPCSTR)*local_18 != local_58) {
                pCVar2 = CharNextA((LPCSTR)*local_18);
                *local_18 = (int)pCVar2;
              }
            }
          }
          else {
            uVar7 = FUN_100045a0(local_2c,(LPCSTR)*local_18);
            if ((int)uVar7 == 0) {
              local_34 = -0x7ff8fff2;
              break;
            }
          }
          pCVar2 = CharNextA((LPCSTR)*local_18);
          *local_18 = (int)pCVar2;
        }
        if (-1 < local_34) {
          uVar4 = FUN_10008460(local_2c);
          *param_2 = uVar4;
        }
        local_8 = 0xffffffff;
        FUN_10003920((int)local_2c);
      }
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000ac78);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000acc0 at 1000acc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000acc0(int *param_1,_GUID *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    local_8 = 0x80004003;
  }
  else {
    *param_3 = 0;
    local_8 = 0;
    iVar1 = ATL::InlineIsEqualUnknown(param_2);
    if (iVar1 == 0) {
      local_8 = InternalQueryInterface(param_1 + 4,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return local_8;
}



// Function: FUN_1000ad50 at 1000ad50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000ad50(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000a740((void *)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_1000ad71 at 1000ad71

void FUN_1000ad71(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000ad50(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000ad7b at 1000ad7b

void FUN_1000ad7b(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000ad50(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000ad85 at 1000ad85

void FUN_1000ad85(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000ad50(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: QueryInterface at 1000ad90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: virtual long __stdcall ATL::CComObject<class ATL::CComEnum<struct
   IEnumConnectionPoints,&struct __s_GUID const _GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct
   IConnectionPoint *,class ATL::_CopyInterface<struct IConnectionPoint>,class
   ATL::CComMultiThreadModel> >::QueryInterface(struct _GUID const &,void * *)
    public: virtual long __stdcall ATL::CComObject<class ATL::CComEnum<struct
   IEnumConnections,&struct __s_GUID const _GUID_b196b287_bab4_101a_b69c_00aa00341d07,struct
   tagCONNECTDATA,class ATL::_Copy<struct tagCONNECTDATA>,class ATL::CComMultiThreadModel>
   >::QueryInterface(struct _GUID const &,void * *)
    public: virtual long __stdcall ATL::CComObject<class CTextImageEventSink<class CVsTextSpanSet>
   >::QueryInterface(struct _GUID const &,void * *)
    public: virtual long __stdcall ATL::CComObject<class CTextLinesEventSink<class CVsTextSpanSet>
   >::QueryInterface(struct _GUID const &,void * *)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void QueryInterface(void *param_1,_GUID *param_2,undefined4 *param_3)

{
  InternalQueryInterface(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000adae at 1000adae

void FUN_1000adae(int param_1,_GUID *param_2,undefined4 *param_3)

{
  QueryInterface((void *)(param_1 + -4),param_2,param_3);
  return;
}



// Function: FUN_1000adb8 at 1000adb8

void FUN_1000adb8(int param_1,_GUID *param_2,undefined4 *param_3)

{
  QueryInterface((void *)(param_1 + -8),param_2,param_3);
  return;
}



// Function: FUN_1000adc2 at 1000adc2

void FUN_1000adc2(int param_1,_GUID *param_2,undefined4 *param_3)

{
  QueryInterface((void *)(param_1 + -0xc),param_2,param_3);
  return;
}



// Function: QueryInterface at 1000add0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: virtual long __stdcall ATL::CComObject<class ATL::CComEnum<struct
   IEnumConnectionPoints,&struct __s_GUID const _GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct
   IConnectionPoint *,class ATL::_CopyInterface<struct IConnectionPoint>,class
   ATL::CComMultiThreadModel> >::QueryInterface(struct _GUID const &,void * *)
    public: virtual long __stdcall ATL::CComObject<class ATL::CComEnum<struct
   IEnumConnections,&struct __s_GUID const _GUID_b196b287_bab4_101a_b69c_00aa00341d07,struct
   tagCONNECTDATA,class ATL::_Copy<struct tagCONNECTDATA>,class ATL::CComMultiThreadModel>
   >::QueryInterface(struct _GUID const &,void * *)
    public: virtual long __stdcall ATL::CComObject<class CTextImageEventSink<class CVsTextSpanSet>
   >::QueryInterface(struct _GUID const &,void * *)
    public: virtual long __stdcall ATL::CComObject<class CTextLinesEventSink<class CVsTextSpanSet>
   >::QueryInterface(struct _GUID const &,void * *)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void QueryInterface(void *param_1,_GUID *param_2,undefined4 *param_3)

{
  InternalQueryInterface(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000adf0 at 1000adf0

undefined4 FUN_1000adf0(void)

{
  return 0x80004001;
}



// Function: FUN_1000ae00 at 1000ae00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000ae00(LPCSTR param_1)

{
  PFILETIME lpftLastWriteTime;
  LSTATUS LVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  int local_160 [4];
  CHAR local_150 [264];
  CHAR local_48 [12];
  DWORD local_3c [3];
  int local_30;
  CRegKey local_28 [16];
  undefined4 *local_18;
  PFILETIME local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cfb8;
  local_10 = ExceptionList;
  piVar3 = local_160;
  for (iVar2 = 0x54; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = -0x33333334;
    piVar3 = piVar3 + 1;
  }
  lpftLastWriteTime = (PFILETIME)(DAT_10029830 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_14 = lpftLastWriteTime;
  ATL::CRegKey::CRegKey(local_28,(CAtlTransactionManager *)0x0);
  local_8 = 0;
  uVar4 = FUN_1000a620(local_28,(HKEY)*local_18,param_1,local_18[1] | 0x2001f);
  local_30 = (int)uVar4;
  if (local_30 == 0) {
    do {
      local_48[0] = '\0';
      local_48[1] = '\x01';
      local_48[2] = '\0';
      local_48[3] = '\0';
      LVar1 = RegEnumKeyExA((HKEY)0x0,(DWORD)local_150,local_48,(LPDWORD)0x0,(LPDWORD)0x0,(LPSTR)0x0
                            ,local_3c,lpftLastWriteTime);
      lpftLastWriteTime = (PFILETIME)0x1000aed1;
      if (LVar1 != 0) {
        ATL::CRegKey::Close(local_28);
        local_160[0] = FUN_10008300(local_18,param_1);
        local_8 = 0xffffffff;
        ATL::CRegKey::~CRegKey(local_28);
        goto LAB_1000af45;
      }
      local_30 = FUN_1000ae00(local_150);
    } while (local_30 == 0);
    local_8 = 0xffffffff;
    local_160[1] = local_30;
    ATL::CRegKey::~CRegKey(local_28);
  }
  else {
    local_8 = 0xffffffff;
    local_160[2] = local_30;
    ATL::CRegKey::~CRegKey(local_28);
  }
LAB_1000af45:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000af80);
  ExceptionList = local_10;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000afe0 at 1000afe0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1000afe0(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,LPSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegCreateKeyExA(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                              param_9);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    uVar4 = 0x1000b01f;
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                        *this,0,0x1000b04a,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000b0f0 at 1000b0f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000b0f0(void *this,HKEY param_1,LPCSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegDeleteKeyA(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    uVar4 = 0x1000b12b;
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0,0x1000b153,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000b1c0 at 1000b1c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall
FUN_1000b1c0(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegOpenKeyExA(param_1,param_2,param_3,param_4,param_5);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    uVar4 = 0x1000b1fb;
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,*this,0,0x1000b226,uVar4);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_1000b2a0 at 1000b2a0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000b2a0(void *this,char *param_1,int param_2)

{
  int iVar1;
  HKEY *ppHVar2;
  HKEY local_102c [3];
  LPVOID local_1020 [2];
  int local_1018;
  uchar local_1010 [4100];
  undefined4 *local_c;
  uint local_8;
  
  ppHVar2 = local_102c;
  for (iVar1 = 0x40a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppHVar2 = (HKEY)0xcccccccc;
    ppHVar2 = ppHVar2 + 1;
  }
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_1018 = 0;
  local_1020[0] = (LPVOID)0x0;
  local_c = (undefined4 *)this;
  local_1018 = FUN_1000a7d0(this,param_1,local_1020);
  if (-1 < local_1018) {
    *local_c = local_1020[0];
    while( true ) {
      if ((*(char *)*local_c == '\0') ||
         (local_1018 = FUN_1000a3b0(local_c,local_1010), local_1018 < 0)) goto LAB_1000b474;
      local_102c[1] = (HKEY)FUN_10009590((LPCSTR)local_1010);
      if (local_102c[1] == (HKEY)0x0) break;
      local_1018 = FUN_1000a3b0(local_c,local_1010);
      if (local_1018 < 0) goto LAB_1000b474;
      if (local_1010[0] != '{') {
        local_1018 = FUN_10008950();
        goto LAB_1000b474;
      }
      if (param_2 == 0) {
        local_1018 = FUN_1000bad0(local_1010,local_102c[1],0,0);
        if (local_1018 < 0) goto LAB_1000b474;
      }
      else {
        local_102c[0] = (HKEY)*local_c;
        local_1018 = FUN_1000bad0(local_1010,local_102c[1],param_2,0);
        if (local_1018 < 0) {
          *local_c = local_102c[0];
          FUN_1000bad0(local_1010,local_102c[1],0,0);
          goto LAB_1000b474;
        }
      }
      FUN_1000d4f0(local_c);
    }
    local_1018 = FUN_10008950();
LAB_1000b474:
    CoTaskMemFree(local_1020[0]);
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000b4c0);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b4f0 at 1000b4f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000b4f0(wchar_t *param_1,LPCSTR param_2,LPCSTR param_3)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPSTR *ppCVar7;
  uint uStack_4b0;
  LPSTR local_4a0 [2];
  int local_498;
  LPSTR local_494;
  LPCSTR local_490;
  _RTC_ALLOCA_NODE *local_488 [2];
  long lStack_480;
  undefined4 local_47c;
  LPCSTR local_478;
  int local_470 [258];
  HGLOBAL local_68;
  DWORD local_64;
  HGLOBAL local_60;
  HRSRC local_5c;
  HMODULE local_58;
  undefined1 local_50 [12];
  long local_44;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_3c [12];
  wchar_t *local_30;
  UINT local_2c;
  ulong local_24 [2];
  undefined4 local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001cff3;
  local_10 = ExceptionList;
  ppCVar7 = local_4a0;
  for (iVar6 = 0x123; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  uStack_4b0 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4b0;
  ExceptionList = &local_10;
  local_488[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_18 = uStack_4b0;
  local_2c = FUN_1000e9f0();
  FUN_10001bd0((undefined4 *)local_3c);
  local_8 = 0;
  FUN_10002a10(local_50,local_1c);
  FUN_10002370(local_470);
  local_8._0_1_ = 1;
  local_30 = param_1;
  if (param_1 == (wchar_t *)0x0) {
    local_490 = (LPCSTR)0x0;
    goto LAB_1000b676;
  }
  sVar4 = wcslen(param_1);
  local_24[0] = sVar4 + 1;
  lVar5 = ATL::AtlMultiply<int>((int *)local_24,local_24[0],2);
  if (lVar5 < 0) {
    local_494 = (LPSTR)0x0;
  }
  else {
    if ((int)local_24[0] < 0x401) {
      cVar3 = FUN_1000eae0(local_24[0]);
      if (cVar3 == '\0') goto LAB_1000b63a;
      local_498 = local_24[0] + 0x24;
      iVar6 = -(local_24[0] + 0x24);
      local_4a0[1] = &stack0xfffffb4c;
      local_14 = &stack0xfffffb4c;
      *(_RTC_ALLOCA_NODE ***)((int)local_4a0 + iVar6 + -0x18) = local_488;
      iVar2 = local_498;
      pCVar1 = local_4a0[1];
      *(undefined4 *)((int)local_4a0 + iVar6 + -0x1c) = 0x1000b625;
      _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_4a0 + iVar6 + -0x18));
      local_4a0[0] = local_4a0[1] + 0x20;
      local_4a0[1] = local_4a0[0];
    }
    else {
LAB_1000b63a:
      local_4a0[0] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                            CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                      (local_3c,local_24[0]);
    }
    local_494 = FUN_10007930(local_4a0[0],local_30,local_24[0],local_2c);
  }
  local_490 = local_494;
LAB_1000b676:
  local_478 = local_490;
  if (local_490 == (LPCSTR)0x0) {
    local_47c = 0x8007000e;
    local_8 = (uint)local_8._1_3_ << 8;
    ~CTempBuffer<>(local_470);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_3c);
  }
  else {
    local_58 = LoadLibraryExA(local_490,(HANDLE)0x0,0x60);
    if (local_58 == (HMODULE)0x0) {
      local_58 = LoadLibraryExA(local_478,(HANDLE)0x0,2);
    }
    if (local_58 == (HMODULE)0x0) {
      local_44 = ATL::AtlHresultFromLastError();
    }
    else {
      local_5c = FindResourceA(local_58,param_2,param_3);
      if (local_5c == (HRSRC)0x0) {
        local_44 = ATL::AtlHresultFromLastError();
      }
      else {
        local_60 = LoadResource(local_58,local_5c);
        if (local_60 == (HGLOBAL)0x0) {
          local_44 = ATL::AtlHresultFromLastError();
        }
        else {
          local_64 = SizeofResource(local_58,local_5c);
          local_68 = local_60;
          if (local_64 <= local_64 + 1) {
            local_8 = CONCAT31(local_8._1_3_,2);
            Allocate(local_470,local_64 + 1);
            FUN_1000b7c4();
            return;
          }
          local_44 = -0x7ff8fff2;
        }
      }
    }
    if (local_58 != (HMODULE)0x0) {
      FreeLibrary(local_58);
    }
    lStack_480 = local_44;
    local_8 = (uint)local_8._1_3_ << 8;
    ~CTempBuffer<>(local_470);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_3c);
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000b8bc,local_488[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000b7be at 1000b7be

undefined * Catch_1000b7be(void)

{
  return &DAT_1000b7cd;
}



// Function: FUN_1000b7c4 at 1000b7c4

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000b7c4(void)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint unaff_EBP;
  rsize_t rVar6;
  void *pvVar7;
  rsize_t rVar8;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  iVar2 = FUN_10003e30((undefined4 *)(unaff_EBP - 0x46c));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 0x40) = 0x8007000e;
  }
  else {
    rVar8 = *(rsize_t *)(unaff_EBP - 0x60);
    pvVar7 = *(void **)(unaff_EBP - 100);
    rVar6 = *(rsize_t *)(unaff_EBP - 0x60);
    pvVar3 = (void *)FUN_10003e30((undefined4 *)(unaff_EBP - 0x46c));
    FUN_1000f920(pvVar3,rVar6,pvVar7,rVar8);
    iVar2 = FUN_10003e30((undefined4 *)(unaff_EBP - 0x46c));
    *(undefined1 *)(iVar2 + *(int *)(unaff_EBP - 0x60)) = 0;
    iVar2 = *(int *)(unaff_EBP + 0x14);
    pcVar4 = (char *)FUN_10003e30((undefined4 *)(unaff_EBP - 0x46c));
    uVar5 = FUN_1000b2a0((void *)(unaff_EBP - 0x4c),pcVar4,iVar2);
    *(undefined4 *)(unaff_EBP - 0x40) = uVar5;
  }
  if (*(int *)(unaff_EBP - 0x54) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP - 0x54));
  }
  *(undefined4 *)(unaff_EBP - 0x47c) = *(undefined4 *)(unaff_EBP - 0x40);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  ~CTempBuffer<>((int *)(unaff_EBP - 0x46c));
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP - 0x38));
  _RTC_CheckStackVars2(unaff_EBP,(int *)&DAT_1000b8bc,*(_RTC_ALLOCA_NODE **)(unaff_EBP - 0x484));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x4a0) = 0x1000b8b4;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: FUN_1000b940 at 1000b940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000b940(int param_1,void *param_2)

{
  int local_c;
  
  local_c = DelRegTree(&DAT_1002995c,param_1,param_2);
  if ((-1 < local_c) && (DAT_10029898 != (code *)0x0)) {
    local_c = (*DAT_10029898)(DAT_10029928);
  }
  return local_c;
}



// Function: DelRegTree at 1000b9c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall CWinApp::DelRegTree(struct HKEY__ *,class ATL::CStringT<char,class
   StrTraitMFC<char,class ATL::ChTraitsCRT<char> > > const &,class ATL::CAtlTransactionManager *)
    public: long __thiscall CWinApp::DelRegTree(struct HKEY__ *,class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > const &,class ATL::CAtlTransactionManager
   *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall DelRegTree(void *this,int param_1,void *param_2)

{
  FUN_10005d30((int)this,param_1,param_2);
  return;
}



// Function: FUN_1000b9f0 at 1000b9f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000b9f0(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int *local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = _IsEqualGUID(param_2,(void *)*local_10), CONCAT31(extraout_var,bVar1) != 0)) {
        local_c = (*(code *)local_10[1])(1);
        if (local_c < 0) break;
        piVar2 = (int *)(*(code *)local_10[7])(1,0x1000ba69);
        local_c = FUN_10006b80((GUID *)*local_10,piVar2,0x1000ba87);
        if (local_c < 0) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_1000b940(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_1000bad0 at 1000bad0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000bad0(uchar *param_1,HKEY param_2,int param_3,int param_4)

{
  LPCSTR lpString1;
  LPCSTR pCVar1;
  HKEY pHVar2;
  size_t sVar3;
  int iVar4;
  LPCSTR unaff_EDI;
  uint *puVar5;
  undefined8 uVar6;
  uint local_11cc [4];
  undefined4 local_11bc;
  int local_11b8;
  undefined4 local_11b4;
  undefined4 local_11b0;
  int local_11ac;
  CRegKey local_11a4 [16];
  int local_1194;
  CRegKey local_118c [20];
  CRegKey local_1178 [20];
  CHAR local_1164 [4104];
  CRegKey local_15c [16];
  uint local_14c;
  int local_148;
  int local_144;
  int local_140;
  uchar local_138 [264];
  ulong local_30;
  HKEY local_28 [4];
  void *local_18;
  LPCSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d054;
  local_10 = ExceptionList;
  puVar5 = local_11cc;
  for (iVar4 = 0x46f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  lpString1 = (LPCSTR)(DAT_10029830 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_14 = lpString1;
  ATL::CRegKey::CRegKey((CRegKey *)local_28,(CAtlTransactionManager *)0x0);
  local_8 = 0;
  local_140 = 1;
  local_144 = param_4;
  local_148 = 0;
  local_148 = FUN_1000a3b0(local_18,param_1);
  if (-1 < local_148) {
LAB_1000bb87:
    if (*param_1 == '}') goto LAB_1000c3d1;
    local_140 = 1;
    iVar4 = lstrcmpiA(lpString1,unaff_EDI);
    unaff_EDI = (LPCSTR)0x1000bbba;
    local_11cc[0] = (uint)(iVar4 == 0);
    local_14c = local_11cc[0];
    iVar4 = lstrcmpiA((LPCSTR)param_1,"ForceRemove");
    lpString1 = (LPCSTR)0x1000bbfa;
    if ((iVar4 == 0) || (local_14c != 0)) {
      local_148 = FUN_1000a3b0(local_18,param_1);
      if (local_148 < 0) goto LAB_1000c3d1;
      if (param_3 == 0) goto LAB_1000bd57;
      ATL::CRegKey::CRegKey(local_15c,(CAtlTransactionManager *)0x0);
      local_8._0_1_ = 1;
      pCVar1 = FUN_1000d540((LPSTR)param_1,'\\');
      if (pCVar1 == (LPCSTR)0x0) {
        iVar4 = FUN_10007a70((LPCSTR)param_1);
        if (iVar4 != 0) {
          FUN_10007a30(local_15c,param_2);
          FUN_1000ae00((LPCSTR)param_1);
          FUN_100084b0((undefined4 *)local_15c);
        }
        if (local_14c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::~CRegKey(local_15c);
          goto LAB_1000bd57;
        }
        local_148 = FUN_1000a3b0(local_18,param_1);
        if (local_148 < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::~CRegKey(local_15c);
        }
        else {
          local_148 = FUN_1000d410(local_18,(char *)param_1);
          if (-1 < local_148) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::CRegKey::~CRegKey(local_15c);
            goto LAB_1000c366;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::~CRegKey(local_15c);
        }
        goto LAB_1000c3d1;
      }
      local_11b0 = FUN_10008950();
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::~CRegKey(local_15c);
      local_8 = 0xffffffff;
      ATL::CRegKey::~CRegKey((CRegKey *)local_28);
      goto LAB_1000c3f2;
    }
LAB_1000bd57:
    iVar4 = lstrcmpiA((LPCSTR)param_1,"NoRemove");
    if (iVar4 == 0) {
      local_140 = 0;
      local_148 = FUN_1000a3b0(local_18,param_1);
      if (local_148 < 0) goto LAB_1000c3d1;
    }
    iVar4 = lstrcmpiA((LPCSTR)param_1,"Val");
    lpString1 = (LPCSTR)0x1000bdb9;
    if (iVar4 == 0) {
      local_148 = FUN_1000a3b0(local_18,local_1164);
      if ((local_148 < 0) || (local_148 = FUN_1000a3b0(local_18,param_1), local_148 < 0))
      goto LAB_1000c3d1;
      if (*param_1 != '=') {
        local_11b4 = FUN_10008950();
        local_8 = 0xffffffff;
        ATL::CRegKey::~CRegKey((CRegKey *)local_28);
        goto LAB_1000c3f2;
      }
      if (param_3 != 0) {
        ATL::CRegKey::CRegKey(local_1178,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 2;
        FUN_10007a30(local_1178,param_2);
        local_148 = FUN_10004c10(local_18,local_1178,local_1164,param_1);
        FUN_100084b0((undefined4 *)local_1178);
        if (-1 < local_148) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::~CRegKey(local_1178);
          goto LAB_1000c366;
        }
        local_11b8 = local_148;
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::~CRegKey(local_1178);
        local_8 = 0xffffffff;
        ATL::CRegKey::~CRegKey((CRegKey *)local_28);
        goto LAB_1000c3f2;
      }
      if ((param_4 == 0) && (local_140 != 0)) {
        ATL::CRegKey::CRegKey(local_118c,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 3;
        uVar6 = FUN_1000a620(local_118c,param_2,(LPCSTR)0x0,0x20006);
        local_30 = (ulong)uVar6;
        if (local_30 != 0) {
          local_148 = FUN_10006110(local_30);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::~CRegKey(local_118c);
          goto LAB_1000c3d1;
        }
        local_30 = FUN_10008360(local_118c,local_1164);
        if ((local_30 != 0) && (local_30 != 2)) {
          local_148 = FUN_10006110(local_30);
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::~CRegKey(local_118c);
          goto LAB_1000c3d1;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::~CRegKey(local_118c);
      }
      local_148 = FUN_1000d410(local_18,(char *)param_1);
joined_r0x1000bfc6:
      if (local_148 < 0) goto LAB_1000c3d1;
      goto LAB_1000bb87;
    }
    pCVar1 = FUN_1000d540((LPSTR)param_1,'\\');
    if (pCVar1 != (LPCSTR)0x0) {
      local_11bc = FUN_10008950();
      local_8 = 0xffffffff;
      ATL::CRegKey::~CRegKey((CRegKey *)local_28);
      goto LAB_1000c3f2;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        uVar6 = FUN_1000a620(local_28,param_2,(LPCSTR)param_1,0x20019);
        local_30 = (ulong)uVar6;
      }
      else {
        local_30 = 2;
      }
      if (local_30 != 0) {
        param_4 = 1;
      }
      FUN_1000fd70(local_138,0x104,param_1,0xffffffff);
      local_148 = FUN_1000a3b0(local_18,param_1);
      if (((local_148 < 0) || (local_148 = FUN_1000d410(local_18,(char *)param_1), local_148 < 0))
         || (((*param_1 == '{' && (sVar3 = strlen((char *)param_1), sVar3 == 1)) &&
             (((local_148 = FUN_1000bad0(param_1,local_28[0],0,param_4), local_148 < 0 &&
               (param_4 == 0)) || (local_148 = FUN_1000a3b0(local_18,param_1), local_148 < 0))))))
      goto LAB_1000c3d1;
      param_4 = local_144;
      if (local_30 == 2) goto LAB_1000bb87;
      if (local_30 != 0) {
        if (local_144 == 0) goto LAB_1000c222;
        goto LAB_1000bb87;
      }
      if (local_144 != 0) {
        pHVar2 = (HKEY)FUN_10003e90(local_28);
        uVar6 = FUN_10009600(pHVar2);
        if ((int)uVar6 != 0) {
          iVar4 = FUN_10007a70((LPCSTR)local_138);
          if ((iVar4 != 0) && (local_140 != 0)) {
            FUN_1000ae00((LPCSTR)local_138);
          }
          goto LAB_1000bb87;
        }
      }
      pHVar2 = (HKEY)FUN_10003e90(local_28);
      uVar6 = FUN_10009600(pHVar2);
      local_1194 = (int)uVar6;
      local_30 = ATL::CRegKey::Close((CRegKey *)local_28);
      if (local_30 != 0) {
        local_11cc[2] = FUN_10006110(local_30);
        local_8 = 0xffffffff;
        ATL::CRegKey::~CRegKey((CRegKey *)local_28);
        goto LAB_1000c3f2;
      }
      if ((local_140 != 0) && (local_1194 == 0)) {
        ATL::CRegKey::CRegKey(local_11a4,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 4;
        FUN_10007a30(local_11a4,param_2);
        local_30 = FUN_10008300(local_11a4,(LPCSTR)local_138);
        FUN_100084b0((undefined4 *)local_11a4);
        if (local_30 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::~CRegKey(local_11a4);
          goto LAB_1000c366;
        }
        local_148 = FUN_10006110(local_30);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::CRegKey::~CRegKey(local_11a4);
        goto LAB_1000c3d1;
      }
    }
    else {
      uVar6 = FUN_1000a620(local_28,param_2,(LPCSTR)param_1,0x2001f);
      local_30 = (ulong)uVar6;
      if (local_30 != 0) {
        uVar6 = FUN_1000a620(local_28,param_2,(LPCSTR)param_1,0x20019);
        local_30 = (ulong)uVar6;
        if (local_30 != 0) {
          uVar6 = FUN_10007d70(local_28,param_2,(LPCSTR)param_1,(LPSTR)0x0,0,0x2001f,
                               (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0);
          local_30 = (ulong)uVar6;
          if (local_30 != 0) {
            local_11cc[3] = FUN_10006110(local_30);
            local_8 = 0xffffffff;
            ATL::CRegKey::~CRegKey((CRegKey *)local_28);
            goto LAB_1000c3f2;
          }
        }
      }
      local_148 = FUN_1000a3b0(local_18,param_1);
      if ((local_148 < 0) ||
         ((*param_1 == '=' &&
          (local_148 = FUN_10004c10(local_18,local_28,(LPCSTR)0x0,param_1), local_148 < 0))))
      goto LAB_1000c3d1;
    }
LAB_1000c366:
    if (((param_3 != 0) && (*param_1 == '{')) && (sVar3 = strlen((char *)param_1), sVar3 == 1)) {
      local_148 = FUN_1000bad0(param_1,local_28[0],param_3,0);
      if (-1 < local_148) {
        local_148 = FUN_1000a3b0(local_18,param_1);
        goto joined_r0x1000bfc6;
      }
      goto LAB_1000c3d1;
    }
    goto LAB_1000bb87;
  }
  local_8 = 0xffffffff;
  local_11ac = local_148;
  ATL::CRegKey::~CRegKey((CRegKey *)local_28);
LAB_1000c3f2:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000c430);
  ExceptionList = local_10;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_1000c222:
  local_148 = FUN_10006110(local_30);
LAB_1000c3d1:
  local_11cc[1] = local_148;
  local_8 = 0xffffffff;
  ATL::CRegKey::~CRegKey((CRegKey *)local_28);
  goto LAB_1000c3f2;
}



// Function: Release at 1000c4d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual unsigned long __stdcall ATL::CComObjectNoLock<class
   ATL::CAccessibleProxy>::Release(void)
   
   Library: Visual Studio 2012 Debug */

ulong ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::Release(void)

{
  ulong extraout_EAX;
  int *in_stack_00000004;
  
  CRect::SwapLeftRight((CRect *)(in_stack_00000004 + 1));
  if ((extraout_EAX == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0xc))(1);
  }
  return extraout_EAX;
}



// Function: FUN_1000c550 at 1000c550

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000c550(int param_1)

{
  FUN_1000a790((undefined4 *)(param_1 + 0x10));
  return;
}



// Function: FUN_1000c569 at 1000c569

void FUN_1000c569(int param_1)

{
  FUN_1000c550(param_1 + -4);
  return;
}



// Function: FUN_1000c573 at 1000c573

void FUN_1000c573(int param_1)

{
  FUN_1000c550(param_1 + -8);
  return;
}



// Function: FUN_1000c57d at 1000c57d

void FUN_1000c57d(int param_1)

{
  FUN_1000c550(param_1 + -0xc);
  return;
}



// Function: Release at 1000c590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual unsigned long __stdcall ATL::CComObjectNoLock<class
   ATL::CAccessibleProxy>::Release(void)
   
   Library: Visual Studio 2012 Debug */

ulong ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::Release(void)

{
  ulong extraout_EAX;
  int *in_stack_00000004;
  
  CRect::SwapLeftRight((CRect *)(in_stack_00000004 + 4));
  if ((extraout_EAX == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x10))(1);
  }
  return extraout_EAX;
}



// Function: FUN_1000c606 at 1000c606

void FUN_1000c606(void)

{
  ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000c610 at 1000c610

void FUN_1000c610(void)

{
  ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000c61a at 1000c61a

void FUN_1000c61a(void)

{
  ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_1000c630 at 1000c630

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000c630(int *param_1)

{
  int extraout_EAX;
  
  CRect::SwapLeftRight((CRect *)(param_1 + 1));
  if (extraout_EAX == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (extraout_EAX == 1) {
    (**(code **)(*DAT_1002987c + 8))();
  }
  return extraout_EAX;
}



// Function: FUN_1000c6d0 at 1000c6d0

undefined4 FUN_1000c6d0(void)

{
  return 0;
}



// Function: FUN_1000c6e0 at 1000c6e0

undefined4 FUN_1000c6e0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80004003;
  }
  else if (param_4 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0x80004001;
  }
  return uVar1;
}



// Function: FUN_1000c710 at 1000c710

undefined4 FUN_1000c710(void)

{
  undefined4 uVar1;
  int in_stack_00000010;
  
  if (in_stack_00000010 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0x80004001;
  }
  return uVar1;
}



// Function: FUN_1000c730 at 1000c730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000c730(int *param_1)

{
  int local_c;
  
  if (*param_1 != 0) {
    for (local_c = 0; local_c < param_1[2]; local_c = local_c + 1) {
    }
    free((void *)*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return;
}



// Function: FUN_1000c7e0 at 1000c7e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000c7e0(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_64 [2];
  int local_5c;
  LPSTR local_58;
  LPCSTR local_54;
  _RTC_ALLOCA_NODE *local_4c [2];
  undefined4 local_44;
  undefined4 local_40;
  LPCSTR local_3c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_34 [12];
  wchar_t *local_28;
  UINT local_24;
  ulong local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d088;
  local_10 = ExceptionList;
  ppCVar7 = local_64;
  for (iVar6 = 0x15; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_4c[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_24 = FUN_1000e9f0();
  FUN_10001bd0((undefined4 *)local_34);
  local_8 = 0;
  local_28 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_54 = (LPCSTR)0x0;
    goto LAB_1000c902;
  }
  sVar4 = wcslen(param_4);
  local_1c[0] = sVar4 + 1;
  lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
  if (lVar5 < 0) {
    local_58 = (LPSTR)0x0;
  }
  else {
    if ((int)local_1c[0] < 0x401) {
      cVar3 = FUN_1000eae0(local_1c[0]);
      if (cVar3 == '\0') goto LAB_1000c8d5;
      local_5c = local_1c[0] + 0x24;
      iVar6 = -(local_1c[0] + 0x24);
      local_64[1] = &stack0xffffff8c;
      *(_RTC_ALLOCA_NODE ***)((int)local_64 + iVar6 + -0x14) = local_4c;
      iVar2 = local_5c;
      pCVar1 = local_64[1];
      *(undefined4 *)((int)local_64 + iVar6 + -0x18) = 0x1000c8c9;
      _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_64 + iVar6 + -0x14));
      local_64[0] = local_64[1] + 0x20;
      local_64[1] = local_64[0];
    }
    else {
LAB_1000c8d5:
      local_64[0] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                           CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                     (local_34,local_1c[0]);
    }
    local_58 = FUN_10007930(local_64[0],local_28,local_1c[0],local_24);
  }
  local_54 = local_58;
LAB_1000c902:
  local_3c = local_54;
  if (local_54 == (LPCSTR)0x0) {
    local_40 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
  else {
    local_44 = FUN_1000b4f0(param_2,(LPCSTR)(uint)param_3,local_54);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000c98c,local_4c[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c9f0 at 1000c9f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000c9f0(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_80 [2];
  int local_78;
  LPSTR local_74;
  LPCSTR local_70;
  LPSTR local_6c;
  LPSTR local_68;
  int local_64;
  LPSTR local_60;
  LPSTR local_5c;
  _RTC_ALLOCA_NODE *local_54 [2];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  LPCSTR local_40;
  LPSTR local_3c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_34 [12];
  wchar_t *local_28;
  UINT local_24;
  ulong local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d0b8;
  local_10 = ExceptionList;
  ppCVar7 = local_80;
  for (iVar6 = 0x1c; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_24 = FUN_1000e9f0();
  FUN_10001bd0((undefined4 *)local_34);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_44 = 0x80070057;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
    goto LAB_1000cc65;
  }
  local_28 = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_5c = (LPSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_3);
    local_1c[0] = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
    if (lVar5 < 0) {
      local_60 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000eae0(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1000cb0f;
        local_64 = local_1c[0] + 0x24;
        iVar6 = -(local_1c[0] + 0x24);
        local_68 = &stack0xffffff70;
        *(_RTC_ALLOCA_NODE ***)((int)local_80 + iVar6 + -0x14) = local_54;
        iVar2 = local_64;
        pCVar1 = local_68;
        *(undefined4 *)((int)local_80 + iVar6 + -0x18) = 0x1000cb03;
        _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_80 + iVar6 + -0x14));
        local_6c = local_68 + 0x20;
        local_68 = local_6c;
      }
      else {
LAB_1000cb0f:
        local_6c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_34,local_1c[0]);
      }
      local_60 = FUN_10007930(local_6c,local_28,local_1c[0],local_24);
    }
    local_5c = local_60;
  }
  local_3c = local_5c;
  local_28 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_70 = (LPCSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_4);
    local_1c[0] = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
    if (lVar5 < 0) {
      local_74 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000eae0(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1000cbe0;
        local_78 = local_1c[0] + 0x24;
        local_80[1] = &stack0xffffff70;
        _RTC_AllocaHelper(&stack0xffffff70,local_78,local_54);
        local_80[0] = local_80[1] + 0x20;
        local_80[1] = local_80[0];
      }
      else {
LAB_1000cbe0:
        local_80[0] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                             CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                       (local_34,local_1c[0]);
      }
      local_74 = FUN_10007930(local_80[0],local_28,local_1c[0],local_24);
    }
    local_70 = local_74;
  }
  local_40 = local_70;
  if ((local_3c == (LPCSTR)0x0) || (local_70 == (LPCSTR)0x0)) {
    local_48 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
  else {
    local_4c = FUN_1000b4f0(param_2,local_3c,local_70);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
LAB_1000cc65:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&LAB_1000cc9c,local_54[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000cd00 at 1000cd00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000cd00(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_64 [2];
  int local_5c;
  LPSTR local_58;
  LPCSTR local_54;
  _RTC_ALLOCA_NODE *local_4c [2];
  undefined4 local_44;
  undefined4 local_40;
  LPCSTR local_3c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_34 [12];
  wchar_t *local_28;
  UINT local_24;
  ulong local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d0e8;
  local_10 = ExceptionList;
  ppCVar7 = local_64;
  for (iVar6 = 0x15; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_4c[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_24 = FUN_1000e9f0();
  FUN_10001bd0((undefined4 *)local_34);
  local_8 = 0;
  local_28 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_54 = (LPCSTR)0x0;
    goto LAB_1000ce22;
  }
  sVar4 = wcslen(param_4);
  local_1c[0] = sVar4 + 1;
  lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
  if (lVar5 < 0) {
    local_58 = (LPSTR)0x0;
  }
  else {
    if ((int)local_1c[0] < 0x401) {
      cVar3 = FUN_1000eae0(local_1c[0]);
      if (cVar3 == '\0') goto LAB_1000cdf5;
      local_5c = local_1c[0] + 0x24;
      iVar6 = -(local_1c[0] + 0x24);
      local_64[1] = &stack0xffffff8c;
      *(_RTC_ALLOCA_NODE ***)((int)local_64 + iVar6 + -0x14) = local_4c;
      iVar2 = local_5c;
      pCVar1 = local_64[1];
      *(undefined4 *)((int)local_64 + iVar6 + -0x18) = 0x1000cde9;
      _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_64 + iVar6 + -0x14));
      local_64[0] = local_64[1] + 0x20;
      local_64[1] = local_64[0];
    }
    else {
LAB_1000cdf5:
      local_64[0] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                           CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                     (local_34,local_1c[0]);
    }
    local_58 = FUN_10007930(local_64[0],local_28,local_1c[0],local_24);
  }
  local_54 = local_58;
LAB_1000ce22:
  local_3c = local_54;
  if (local_54 == (LPCSTR)0x0) {
    local_40 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
  else {
    local_44 = FUN_1000b4f0(param_2,(LPCSTR)(uint)param_3,local_54);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000ceac,local_4c[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000cf10 at 1000cf10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000cf10(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  LPSTR *ppCVar7;
  LPSTR local_80 [2];
  int local_78;
  LPSTR local_74;
  LPCSTR local_70;
  LPSTR local_6c;
  LPSTR local_68;
  int local_64;
  LPSTR local_60;
  LPSTR local_5c;
  _RTC_ALLOCA_NODE *local_54 [2];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  LPCSTR local_40;
  LPSTR local_3c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_34 [12];
  wchar_t *local_28;
  UINT local_24;
  ulong local_1c [2];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d118;
  local_10 = ExceptionList;
  ppCVar7 = local_80;
  for (iVar6 = 0x1c; iVar6 != 0; iVar6 = iVar6 + -1) {
    *ppCVar7 = (LPSTR)0xcccccccc;
    ppCVar7 = ppCVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_24 = FUN_1000e9f0();
  FUN_10001bd0((undefined4 *)local_34);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_44 = 0x80070057;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
    goto LAB_1000d185;
  }
  local_28 = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_5c = (LPSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_3);
    local_1c[0] = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
    if (lVar5 < 0) {
      local_60 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000eae0(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1000d02f;
        local_64 = local_1c[0] + 0x24;
        iVar6 = -(local_1c[0] + 0x24);
        local_68 = &stack0xffffff70;
        *(_RTC_ALLOCA_NODE ***)((int)local_80 + iVar6 + -0x14) = local_54;
        iVar2 = local_64;
        pCVar1 = local_68;
        *(undefined4 *)((int)local_80 + iVar6 + -0x18) = 0x1000d023;
        _RTC_AllocaHelper(pCVar1,iVar2,*(undefined4 **)((int)local_80 + iVar6 + -0x14));
        local_6c = local_68 + 0x20;
        local_68 = local_6c;
      }
      else {
LAB_1000d02f:
        local_6c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_34,local_1c[0]);
      }
      local_60 = FUN_10007930(local_6c,local_28,local_1c[0],local_24);
    }
    local_5c = local_60;
  }
  local_3c = local_5c;
  local_28 = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_70 = (LPCSTR)0x0;
  }
  else {
    sVar4 = wcslen(param_4);
    local_1c[0] = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
    if (lVar5 < 0) {
      local_74 = (LPSTR)0x0;
    }
    else {
      if ((int)local_1c[0] < 0x401) {
        cVar3 = FUN_1000eae0(local_1c[0]);
        if (cVar3 == '\0') goto LAB_1000d100;
        local_78 = local_1c[0] + 0x24;
        local_80[1] = &stack0xffffff70;
        _RTC_AllocaHelper(&stack0xffffff70,local_78,local_54);
        local_80[0] = local_80[1] + 0x20;
        local_80[1] = local_80[0];
      }
      else {
LAB_1000d100:
        local_80[0] = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                             CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                       (local_34,local_1c[0]);
      }
      local_74 = FUN_10007930(local_80[0],local_28,local_1c[0],local_24);
    }
    local_70 = local_74;
  }
  local_40 = local_70;
  if ((local_3c == (LPCSTR)0x0) || (local_70 == (LPCSTR)0x0)) {
    local_48 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
  else {
    local_4c = FUN_1000b4f0(param_2,local_3c,local_70);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_34);
  }
LAB_1000d185:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000d1bc,local_54[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d220 at 1000d220

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000d220(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExA(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_1000d270 at 1000d270

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000d270(void *this,LPCSTR param_1,BYTE *param_2)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  DWORD local_10;
  BYTE *local_c;
  
  if (param_2 == (BYTE *)0x0) {
    LVar1 = 0xd;
  }
  else {
    local_10 = 0;
    local_c = param_2;
    do {
      sVar2 = strlen((char *)local_c);
      iVar3 = sVar2 + 1;
      local_c = local_c + iVar3;
      local_10 = local_10 + iVar3;
    } while (iVar3 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExA(*this,param_1,0,7,param_2,local_10);
  }
  return LVar1;
}



// Function: FUN_1000d330 at 1000d330

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LSTATUS __thiscall FUN_1000d330(void *this,LPCSTR param_1,BYTE *param_2,DWORD param_3)

{
  LSTATUS LVar1;
  size_t sVar2;
  
  if (param_2 == (BYTE *)0x0) {
    LVar1 = 0xd;
  }
  else {
    sVar2 = strlen((char *)param_2);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExA(*this,param_1,0,param_3,param_2,sVar2 + 1);
  }
  return LVar1;
}



// Function: FUN_1000d3d0 at 1000d3d0

void __thiscall FUN_1000d3d0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}



// Function: FUN_1000d3f0 at 1000d3f0

void FUN_1000d3f0(void)

{
  return;
}



// Function: FUN_1000d410 at 1000d410

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000d410(void *this,char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_1018;
  undefined1 local_1014 [4100];
  int local_10;
  undefined4 *local_c;
  uint local_8;
  
  puVar2 = &local_1018;
  for (iVar1 = 0x405; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_c = (undefined4 *)this;
  if ((*param_1 == '=') && (local_10 = FUN_1000a3b0(this,param_1), -1 < local_10)) {
    FUN_1000d4f0(local_c);
    local_10 = FUN_1000a3b0(local_c,local_1014);
    if (-1 < local_10) {
      local_10 = FUN_1000a3b0(local_c,param_1);
    }
  }
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1000d4d4);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d4f0 at 1000d4f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000d4f0(undefined4 *param_1)

{
  int iVar1;
  LPSTR pCVar2;
  
  while( true ) {
    iVar1 = FUN_10009e70(*(undefined1 *)*param_1);
    if (iVar1 == 0) break;
    pCVar2 = CharNextA((LPCSTR)*param_1);
    *param_1 = pCVar2;
  }
  return;
}



// Function: FUN_1000d540 at 1000d540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCSTR __cdecl FUN_1000d540(LPSTR param_1,char param_2)

{
  LPSTR pCVar1;
  LPCSTR local_8;
  
  local_8 = (LPCSTR)0x0;
  if (param_1 == (LPSTR)0x0) {
    pCVar1 = (LPCSTR)0x0;
  }
  else {
    for (; (pCVar1 = local_8, *param_1 != '\0' && (pCVar1 = param_1, *param_1 != param_2));
        param_1 = CharNextA(param_1)) {
    }
  }
  return pCVar1;
}



// Function: FUN_1000d5b0 at 1000d5b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000d5b0(int param_1)

{
  undefined4 uVar1;
  
  FUN_1000a2e0();
  uVar1 = FUN_1000a360((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
  FUN_1000d890();
  return uVar1;
}



// Function: FUN_1000d610 at 1000d610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000d610(int param_1)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_1 == 0) {
        local_c = 0;
      }
      else {
        local_c = param_1 + 4;
      }
      FUN_10005920(local_c);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(undefined4 *)(param_1 + 0x28));
    }
    FUN_1000d6c0((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_1000d6c0 at 1000d6c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000d6c0(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return 0;
}



// Function: FUN_1000d700 at 1000d700

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000d700(int param_1)

{
  int *local_10;
  int *local_c;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    for (local_c = *(int **)(param_1 + 0x2c); *local_c != 0; local_c = local_c + 9) {
      if (local_c[4] != 0) {
        (**(code **)(*(int *)local_c[4] + 8))(local_c[4]);
      }
      local_c[4] = 0;
      (*(code *)local_c[8])(0);
    }
  }
  for (local_10 = DAT_10029964; local_10 < DAT_10029968; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x1c))(0);
    }
  }
  FUN_1000d610(param_1);
  return;
}



// Function: FUN_1000d7e0 at 1000d7e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000d7e0(undefined4 *param_1)

{
  FUN_1000d850((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_1000d820 at 1000d820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000d820(int param_1)

{
  FUN_100082a0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000d850 at 1000d850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_1000d850(LPCRITICAL_SECTION param_1)

{
  LeaveCriticalSection(param_1);
  return 0;
}



// Function: FUN_1000d890 at 1000d890

undefined4 FUN_1000d890(void)

{
  return 0;
}



// Function: FUN_1000d8b0 at 1000d8b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000d8b0(int param_1,void *param_2)

{
  int local_c;
  
  local_c = 0;
  if (DAT_1002989c != (code *)0x0) {
    local_c = (*DAT_1002989c)();
  }
  if (-1 < local_c) {
    local_c = DelRegTree(&DAT_1002995c,param_1,param_2);
  }
  return local_c;
}



// Function: DelRegTree at 1000d920

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall CWinApp::DelRegTree(struct HKEY__ *,class ATL::CStringT<char,class
   StrTraitMFC<char,class ATL::ChTraitsCRT<char> > > const &,class ATL::CAtlTransactionManager *)
    public: long __thiscall CWinApp::DelRegTree(struct HKEY__ *,class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > const &,class ATL::CAtlTransactionManager
   *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall DelRegTree(void *this,int param_1,void *param_2)

{
  FUN_10005e40((int)this,param_1,param_2);
  return;
}



// Function: FUN_1000d950 at 1000d950

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_1000d950(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int *local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = _IsEqualGUID(param_2,(void *)*local_10), CONCAT31(extraout_var,bVar1) != 0)) {
        piVar2 = (int *)(*(code *)local_10[7])(0);
        local_c = FUN_10006b80((GUID *)*local_10,piVar2,0x1000d9c9);
        if ((local_c < 0) || (local_c = (*(code *)local_10[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_1000d8b0(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_1000da30 at 1000da30

undefined4 FUN_1000da30(void)

{
  return 0x80004005;
}



// Function: FUN_1000da40 at 1000da40

undefined4 FUN_1000da40(void)

{
  return 0x80004005;
}



// Function: FUN_1000da50 at 1000da50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000da50(int *param_1,ushort param_2,int param_3,int *param_4)

{
  char cVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  HMODULE pHVar5;
  int iVar6;
  int *piVar7;
  LPCSTR lpModuleName;
  int local_a00;
  LPWSTR local_9fc;
  LPWSTR local_9f8;
  int local_9f4;
  LPWSTR local_9f0;
  LPWSTR local_9ec;
  _RTC_ALLOCA_NODE *local_9e4 [2];
  int local_9dc;
  int local_9d8;
  int local_9d4;
  uint local_9d0;
  undefined4 local_9cc;
  undefined4 local_9c8;
  HRESULT local_9c4;
  long local_9c0;
  int local_9bc;
  int local_9b8;
  wchar_t *local_9b4;
  size_t local_9b0;
  wchar_t local_9a8;
  undefined1 local_9a6 [1050];
  int local_58c;
  wchar_t local_584 [522];
  LPWSTR local_170;
  DWORD local_16c;
  HMODULE local_168;
  CHAR local_160 [268];
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_54 [8];
  char *local_4c;
  UINT local_44;
  ulong local_3c [2];
  int local_34;
  IUnknown local_2c [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d150;
  local_10 = ExceptionList;
  piVar7 = &local_a00;
  for (iVar6 = 0x27c; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar7 = -0x33333334;
    piVar7 = piVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_9e4[0] = (_RTC_ALLOCA_NODE *)0x0;
  FUN_10002990(local_2c);
  local_8 = 0;
  local_34 = FUN_100086f0();
  if (local_34 < 0) {
    local_8 = 0xffffffff;
    local_9b8 = local_34;
    FUN_10003990(local_2c);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10004750((int)local_2c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_34 = (**(code **)(*param_1 + 0x14))(local_2c);
    if (local_34 < 0) {
      local_8 = 0xffffffff;
      local_9bc = local_34;
      FUN_10003990(local_2c);
    }
    else {
      local_44 = FUN_1000e9f0();
      FUN_10001bd0((undefined4 *)local_54);
      local_8._0_1_ = 1;
      local_168 = (HMODULE)FUN_10008e20(0x10029924);
      local_16c = GetModuleFileNameA(local_168,local_160,0x104);
      lpModuleName = (LPCSTR)0x1000db9b;
      if (local_16c == 0) {
        local_9c0 = ATL::AtlHresultFromLastError();
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
        local_8 = 0xffffffff;
        FUN_10003990(local_2c);
      }
      else if (local_16c == 0x104) {
        local_9c4 = _HRESULT_FROM_WIN32(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
        local_8 = 0xffffffff;
        FUN_10003990(local_2c);
      }
      else {
        local_170 = (LPWSTR)0x0;
        local_4c = local_160;
        if (local_4c == (char *)0x0) {
          local_9ec = (LPWSTR)0x0;
        }
        else {
          sVar3 = strlen(local_4c);
          local_3c[0] = sVar3 + 1;
          lVar4 = ATL::AtlMultiply<int>((int *)local_3c,local_3c[0],2);
          if (lVar4 < 0) {
            local_9f0 = (LPWSTR)0x0;
          }
          else {
            if (((int)local_3c[0] < 0x401) && (cVar1 = FUN_1000eae0(local_3c[0]), cVar1 != '\0')) {
              local_9f4 = local_3c[0] + 0x24;
              local_9f8 = (LPWSTR)&stack0xfffff5f4;
              _RTC_AllocaHelper(&stack0xfffff5f4,local_9f4,local_9e4);
              local_9fc = (LPWSTR)((int)local_9f8 + 0x20);
              local_9f8 = local_9fc;
            }
            else {
              local_9fc = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                            (local_54,local_3c[0]);
            }
            local_9f0 = FUN_100058b0(local_9fc,local_4c,local_3c[0] >> 1,local_44);
          }
          local_9ec = local_9f0;
        }
        local_170 = local_9ec;
        if (local_9ec == (LPWSTR)0x0) {
          local_9c8 = 0x8007000e;
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
          local_8 = 0xffffffff;
          FUN_10003990(local_2c);
        }
        else {
          FUN_100085d0(local_584,0x208,local_9ec);
          if ((local_168 == (HMODULE)0x0) ||
             (pHVar5 = GetModuleHandleA(lpModuleName), local_168 == pHVar5)) {
            local_9a8 = L'\"';
            bVar2 = FUN_1000fc20(local_9a6,0x20b,local_584);
            if (!bVar2) {
              local_9cc = 0x80004005;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
              local_8 = 0xffffffff;
              FUN_10003990(local_2c);
              goto LAB_1000dfba;
            }
            local_9b0 = FUN_1000fc90(&local_9a8);
            *(undefined2 *)(local_9a6 + local_9b0 * 2 + -2) = 0x22;
            local_9d0 = local_9b0 * 2 + 2;
            if (0x417 < local_9d0) {
              ___report_rangecheckfailure();
            }
            *(undefined2 *)(local_9a6 + (local_9d0 - 2)) = 0;
            local_58c = FUN_10004750((int)local_2c,L"Module",&local_9a8);
          }
          else {
            local_58c = FUN_10004750((int)local_2c,L"Module",local_584);
          }
          if (local_58c < 0) {
            local_9d4 = local_58c;
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
            local_8 = 0xffffffff;
            FUN_10003990(local_2c);
          }
          else {
            local_58c = FUN_10004750((int)local_2c,L"Module_Raw",local_584);
            if (local_58c < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              local_9d8 = local_58c;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
              local_8 = 0xffffffff;
              FUN_10003990(local_2c);
            }
            else {
              local_9b4 = L"REGISTRY";
              if (param_3 == 0) {
                local_a00 = FUN_1000cd00(local_2c,local_170,param_2,L"REGISTRY");
              }
              else {
                local_a00 = FUN_1000c7e0(local_2c,local_170,param_2,L"REGISTRY");
              }
              local_34 = local_a00;
              local_9dc = local_a00;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
              local_8 = 0xffffffff;
              FUN_10003990(local_2c);
            }
          }
        }
      }
    }
  }
LAB_1000dfba:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000dff4,local_9e4[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e0b0 at 1000e0b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000e0b0(int *param_1,char *param_2,int param_3,int *param_4)

{
  bool bVar1;
  char cVar2;
  HMODULE pHVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  int *piVar7;
  LPCSTR lpModuleName;
  int local_a1c;
  LPWSTR local_a18;
  LPWSTR local_a14;
  int local_a10;
  LPWSTR local_a0c;
  wchar_t *local_a08;
  LPWSTR local_a04;
  LPWSTR local_a00;
  int local_9fc;
  LPWSTR local_9f8;
  LPWSTR local_9f4;
  _RTC_ALLOCA_NODE *local_9ec [2];
  int local_9e4;
  undefined4 local_9e0;
  int local_9dc;
  int local_9d8;
  uint local_9d4;
  undefined4 local_9d0;
  undefined4 local_9cc;
  HRESULT local_9c8;
  long local_9c4;
  int local_9c0;
  int local_9bc;
  wchar_t *local_9b8;
  wchar_t *local_9b4;
  size_t local_9b0;
  wchar_t local_9a8;
  undefined1 local_9a6 [1050];
  int local_58c;
  wchar_t local_584 [522];
  LPWSTR local_170;
  DWORD local_16c;
  HMODULE local_168;
  CHAR local_160 [268];
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_54 [8];
  char *local_4c;
  UINT local_44;
  ulong local_3c [2];
  int local_34;
  IUnknown local_2c [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d190;
  local_10 = ExceptionList;
  piVar7 = &local_a1c;
  for (iVar6 = 0x283; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar7 = -0x33333334;
    piVar7 = piVar7 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_9ec[0] = (_RTC_ALLOCA_NODE *)0x0;
  FUN_10002990(local_2c);
  local_8 = 0;
  local_34 = FUN_100086f0();
  if (local_34 < 0) {
    local_8 = 0xffffffff;
    local_9bc = local_34;
    FUN_10003990(local_2c);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10004750((int)local_2c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_34 = (**(code **)(*param_1 + 0x14))(local_2c);
    if (local_34 < 0) {
      local_8 = 0xffffffff;
      local_9c0 = local_34;
      FUN_10003990(local_2c);
    }
    else {
      local_44 = FUN_1000e9f0();
      FUN_10001bd0((undefined4 *)local_54);
      local_8._0_1_ = 1;
      local_168 = (HMODULE)FUN_10008e20(0x10029924);
      local_16c = GetModuleFileNameA(local_168,local_160,0x104);
      lpModuleName = (LPCSTR)0x1000e1fb;
      if (local_16c == 0) {
        local_9c4 = ATL::AtlHresultFromLastError();
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
        local_8 = 0xffffffff;
        FUN_10003990(local_2c);
      }
      else if (local_16c == 0x104) {
        local_9c8 = _HRESULT_FROM_WIN32(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
        local_8 = 0xffffffff;
        FUN_10003990(local_2c);
      }
      else {
        local_170 = (LPWSTR)0x0;
        local_4c = local_160;
        if (local_4c == (char *)0x0) {
          local_9f4 = (LPWSTR)0x0;
        }
        else {
          sVar4 = strlen(local_4c);
          local_3c[0] = sVar4 + 1;
          lVar5 = ATL::AtlMultiply<int>((int *)local_3c,local_3c[0],2);
          if (lVar5 < 0) {
            local_9f8 = (LPWSTR)0x0;
          }
          else {
            if (((int)local_3c[0] < 0x401) && (cVar2 = FUN_1000eae0(local_3c[0]), cVar2 != '\0')) {
              local_9fc = local_3c[0] + 0x24;
              local_a00 = (LPWSTR)&stack0xfffff5d8;
              _RTC_AllocaHelper(&stack0xfffff5d8,local_9fc,local_9ec);
              local_a04 = (LPWSTR)((int)local_a00 + 0x20);
              local_a00 = local_a04;
            }
            else {
              local_a04 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                            (local_54,local_3c[0]);
            }
            local_9f8 = FUN_100058b0(local_a04,local_4c,local_3c[0] >> 1,local_44);
          }
          local_9f4 = local_9f8;
        }
        local_170 = local_9f4;
        if (local_9f4 == (LPWSTR)0x0) {
          local_9cc = 0x8007000e;
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
          local_8 = 0xffffffff;
          FUN_10003990(local_2c);
        }
        else {
          FUN_100085d0(local_584,0x208,local_9f4);
          if ((local_168 == (HMODULE)0x0) ||
             (pHVar3 = GetModuleHandleA(lpModuleName), local_168 == pHVar3)) {
            local_9a8 = L'\"';
            bVar1 = FUN_1000fc20(local_9a6,0x20b,local_584);
            if (!bVar1) {
              local_9d0 = 0x80004005;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
              local_8 = 0xffffffff;
              FUN_10003990(local_2c);
              goto LAB_1000e75b;
            }
            local_9b0 = FUN_1000fc90(&local_9a8);
            *(undefined2 *)(local_9a6 + local_9b0 * 2 + -2) = 0x22;
            local_9d4 = local_9b0 * 2 + 2;
            if (0x417 < local_9d4) {
              ___report_rangecheckfailure();
            }
            *(undefined2 *)(local_9a6 + (local_9d4 - 2)) = 0;
            local_58c = FUN_10004750((int)local_2c,L"Module",&local_9a8);
          }
          else {
            local_58c = FUN_10004750((int)local_2c,L"Module",local_584);
          }
          if (local_58c < 0) {
            local_9d8 = local_58c;
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
            local_8 = 0xffffffff;
            FUN_10003990(local_2c);
          }
          else {
            local_58c = FUN_10004750((int)local_2c,L"Module_Raw",local_584);
            if (local_58c < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              local_9dc = local_58c;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
              local_8 = 0xffffffff;
              FUN_10003990(local_2c);
            }
            else {
              local_9b4 = L"REGISTRY";
              local_4c = param_2;
              if (param_2 == (char *)0x0) {
                local_a08 = (wchar_t *)0x0;
              }
              else {
                sVar4 = strlen(param_2);
                local_3c[0] = sVar4 + 1;
                lVar5 = ATL::AtlMultiply<int>((int *)local_3c,local_3c[0],2);
                if (lVar5 < 0) {
                  local_a0c = (LPWSTR)0x0;
                }
                else {
                  if (((int)local_3c[0] < 0x401) &&
                     (cVar2 = FUN_1000eae0(local_3c[0]), cVar2 != '\0')) {
                    local_a10 = local_3c[0] + 0x24;
                    local_a14 = (LPWSTR)&stack0xfffff5d8;
                    _RTC_AllocaHelper(&stack0xfffff5d8,local_a10,local_9ec);
                    local_a18 = (LPWSTR)((int)local_a14 + 0x20);
                    local_a14 = local_a18;
                  }
                  else {
                    local_a18 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                        CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                                        Allocate(local_54,local_3c[0]);
                  }
                  local_a0c = FUN_100058b0(local_a18,local_4c,local_3c[0] >> 1,local_44);
                }
                local_a08 = local_a0c;
              }
              local_9b8 = local_a08;
              if (local_a08 == (wchar_t *)0x0) {
                local_9e0 = 0x8007000e;
                local_8 = (uint)local_8._1_3_ << 8;
                ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
                local_8 = 0xffffffff;
                FUN_10003990(local_2c);
              }
              else {
                if (param_3 == 0) {
                  local_a1c = FUN_1000cf10(local_2c,local_170,local_a08,local_9b4);
                }
                else {
                  local_a1c = FUN_1000c9f0(local_2c,local_170,local_a08,local_9b4);
                }
                local_34 = local_a1c;
                local_9e4 = local_a1c;
                local_8 = (uint)local_8._1_3_ << 8;
                ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_54);
                local_8 = 0xffffffff;
                FUN_10003990(local_2c);
              }
            }
          }
        }
      }
    }
  }
LAB_1000e75b:
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000e798,local_9ec[0]);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e850 at 1000e850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e850(int *param_1,ushort param_2,int param_3,int *param_4)

{
  FUN_1000da50(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000e880 at 1000e880

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000e880(int *param_1,char *param_2,int param_3,int *param_4)

{
  FUN_1000e0b0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000e8b0 at 1000e8b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000e8b0(LPCSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d1ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_100298cc & 1) == 0) {
    DAT_100298cc = DAT_100298cc | 1;
    _DAT_100298ac = &DAT_1001f5d8;
    _DAT_100298b0 = 8;
    _DAT_100298b4 = &DAT_1001f5dc;
    _DAT_100298b8 = 0x4008;
    _DAT_100298bc = &DAT_1001f5e0;
    _DAT_100298c0 = 0x13;
    _DAT_100298c4 = &DAT_1001f5e4;
    _DAT_100298c8 = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,*(LPCSTR *)(&DAT_100298ac + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_100298b0 + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000e9d0 at 1000e9d0

undefined4 FUN_1000e9d0(void)

{
  return 0;
}



// Function: FUN_1000e9f0 at 1000e9f0

undefined4 FUN_1000e9f0(void)

{
  return 3;
}



// Function: FUN_1000ea00 at 1000ea00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_1000ea00(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_1000ea50(param_1 + 0x20);
  if (-1 < local_c) {
    local_c = FUN_1000ea80();
  }
  return local_c;
}



// Function: FUN_1000ea50 at 1000ea50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_1000ea50(int param_1)

{
  FUN_100098a0((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000ea80 at 1000ea80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000ea80(void)

{
  FUN_10009790();
  return;
}



// Function: _AtlRaiseException at 1000eab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    void __cdecl ATL::_AtlRaiseException(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __cdecl ATL::_AtlRaiseException(ulong param_1,ulong param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: FUN_1000eae0 at 1000eae0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_1000eae0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 **ppuVar4;
  uint local_6c;
  undefined1 *local_5c [2];
  int local_54;
  _RTC_ALLOCA_NODE *local_4c [3];
  undefined1 *local_40;
  HRESULT local_3c;
  int local_34 [3];
  undefined1 local_25;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  undefined *local_c;
  undefined4 local_8;
  
  local_c = &DAT_10024bc0;
  pcStack_10 = FUN_1001abab;
  local_14 = ExceptionList;
  ppuVar4 = local_5c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined1 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  local_c = (undefined *)((uint)local_c ^ DAT_10029830);
  local_6c = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_6c;
  ExceptionList = &local_14;
  local_4c[0] = (_RTC_ALLOCA_NODE *)0x0;
  local_25 = 1;
  local_8 = 0;
  local_34[0] = 0;
  local_20 = local_6c;
  local_3c = AtlAdd<>(local_34,param_1,0x2000);
  if (local_3c < 0) {
    local_25 = 0;
  }
  else {
    local_54 = local_34[0] + 0x24;
    iVar3 = -(local_34[0] + 0x24);
    local_5c[1] = (undefined1 *)((int)&local_6c + iVar3);
    local_1c = (undefined1 *)((int)&local_6c + iVar3);
    *(_RTC_ALLOCA_NODE ***)((int)local_5c + iVar3 + -0x14) = local_4c;
    iVar2 = local_54;
    puVar1 = local_5c[1];
    *(undefined4 *)((int)local_5c + iVar3 + -0x18) = 0x1000eb88;
    _RTC_AllocaHelper(puVar1,iVar2,*(undefined4 **)((int)local_5c + iVar3 + -0x14));
    local_5c[1] = local_5c[1] + 0x20;
    local_40 = local_5c[1];
  }
  local_8 = 0xfffffffe;
  _RTC_CheckStackVars2((int)&stack0xfffffffc,(int *)&DAT_1000ec18,local_4c[0]);
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ec70 at 1000ec70

undefined8 FUN_1000ec70(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uStack_3c;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d1f0;
  local_10 = ExceptionList;
  local_2c = (undefined1  [4])0xcccccccc;
  local_28 = 0xcccccccc;
  local_24 = 0xcccccccc;
  local_20 = 0xcccccccc;
  uStack_3c = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_1c = param_1 | 0xf;
  uVar1 = FUN_1000f8c0();
  if (uVar1 < local_1c) {
    local_1c = param_1;
  }
  else if (local_1c / 3 < *(uint *)(local_18 + 0x14) >> 1) {
    iVar2 = FUN_1000f8c0();
    if (iVar2 - (*(uint *)(local_18 + 0x14) >> 1) < *(uint *)(local_18 + 0x14)) {
      local_1c = FUN_1000f8c0();
    }
    else {
      local_1c = (*(uint *)(local_18 + 0x14) >> 1) + *(int *)(local_18 + 0x14);
    }
  }
  local_8 = 0;
  uVar1 = local_1c + 1;
  FUN_1000eed0((IUnknown *)(local_2c + 3));
  local_24 = FUN_1000f2a0(uVar1);
  uVar3 = FUN_1000eda9();
  return uVar3;
}



// Function: Catch@1000ed4c at 1000ed4c

void Catch_1000ed4c(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = *(int *)(unaff_EBP + -0x18) + 1;
  FUN_1000eed0((IUnknown *)(unaff_EBP + -0x26));
  uVar2 = FUN_1000f2a0(uVar1);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
  FUN_1000ed93();
  return;
}



// Function: Catch@1000ed78 at 1000ed78

void Catch_1000ed78(void)

{
  int unaff_EBP;
  
  FUN_1000f140(*(void **)(unaff_EBP + -0x14),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000ed93 at 1000ed93

undefined * FUN_1000ed93(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000edb2;
}



// Function: FUN_1000eda9 at 1000eda9

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_1000eda9(void)

{
  undefined4 *puVar1;
  IUnknown *this;
  int unaff_EBP;
  undefined8 uVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    sVar4 = *(size_t *)(unaff_EBP + 0xc);
    puVar1 = FUN_1000f0a0(*(undefined4 **)(unaff_EBP + -0x14));
    FUN_1000f4f0(*(void **)(unaff_EBP + -0x20),puVar1,sVar4);
  }
  FUN_1000f140(*(void **)(unaff_EBP + -0x14),'\x01',0);
  iVar5 = unaff_EBP + -0x20;
  uVar3 = *(undefined4 *)(unaff_EBP + -0x14);
  this = FUN_1000eed0((IUnknown *)(unaff_EBP + -0x27));
  FUN_100019c0(this,uVar3,iVar5);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  uVar2 = FUN_1000ee60(*(void **)(unaff_EBP + -0x14),*(int *)(unaff_EBP + 0xc));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1000ee44);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_1000ee60 at 1000ee60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000ee60(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 local_c;
  void *local_8;
  
  local_c = 0xcccccc;
  *(int *)((int)this + 0x10) = param_1;
  puVar2 = (undefined1 *)((int)&local_c + 3);
  local_8 = this;
  puVar1 = FUN_1000f0a0((undefined4 *)this);
  FUN_1000f4a0((undefined1 *)((int)puVar1 + param_1),puVar2);
  return;
}



// Function: FUN_1000eeb0 at 1000eeb0

undefined ** FUN_1000eeb0(void)

{
  return &PTR_DAT_1001fdc4;
}



// Function: FUN_1000eec0 at 1000eec0

undefined ** FUN_1000eec0(void)

{
  return &PTR_DAT_1001fe90;
}



// Function: FUN_1000eed0 at 1000eed0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * FUN_1000eed0(IUnknown *param_1)

{
  FUN_10002470(param_1);
  return param_1;
}



// Function: FUN_1000ef00 at 1000ef00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __thiscall FUN_1000ef00(void *this,uint param_1,char param_2)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = FUN_1000f8c0();
  if (uVar1 < param_1) {
    FUN_1000f200();
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_1000ec70(param_1);
  }
  else if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      FUN_1000ee60(this,0);
    }
  }
  else {
    if (param_1 < *(uint *)((int)this + 0x10)) {
      local_c = param_1;
    }
    else {
      local_c = *(size_t *)((int)this + 0x10);
    }
    FUN_1000f140(this,'\x01',local_c);
  }
  return param_1 != 0;
}



// Function: FUN_1000efd0 at 1000efd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_1000efd0(void *this,undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (in_EAX = FUN_1000f0a0((undefined4 *)this), in_EAX <= param_1)) {
    puVar1 = FUN_1000f0a0((undefined4 *)this);
    in_EAX = (undefined4 *)((int)puVar1 + *(int *)((int)this + 0x10));
    if (param_1 < in_EAX) {
      return CONCAT31((int3)((uint)in_EAX >> 8),1);
    }
  }
  return (uint)in_EAX & 0xffffff00;
}



// Function: InternalQueryInterface at 1000f020

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CComEnum<struct IEnumConnectionPoints,&struct __s_GUID const
   _GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct IConnectionPoint *,class
   ATL::_CopyInterface<struct IConnectionPoint>,class
   ATL::CComMultiThreadModel>::_InternalQueryInterface(struct _GUID const &,void * *)
    public: long __thiscall ATL::CComEnum<struct IEnumConnections,&struct __s_GUID const
   _GUID_b196b287_bab4_101a_b69c_00aa00341d07,struct tagCONNECTDATA,class ATL::_Copy<struct
   tagCONNECTDATA>,class ATL::CComMultiThreadModel>::_InternalQueryInterface(struct _GUID const
   &,void * *)
    public: long __thiscall CTextImageEventSink<class
   CVsTextSpanSet>::_InternalQueryInterface(struct _GUID const &,void * *)
    public: long __thiscall CTextLinesEventSink<class
   CVsTextSpanSet>::_InternalQueryInterface(struct _GUID const &,void * *)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __thiscall InternalQueryInterface(void *this,_GUID *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_1000eeb0();
  FUN_10009a60((int)this,(int *)ppuVar1,param_1,param_2);
  return;
}



// Function: InternalQueryInterface at 1000f060

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CComEnum<struct IEnumConnectionPoints,&struct __s_GUID const
   _GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct IConnectionPoint *,class
   ATL::_CopyInterface<struct IConnectionPoint>,class
   ATL::CComMultiThreadModel>::_InternalQueryInterface(struct _GUID const &,void * *)
    public: long __thiscall ATL::CComEnum<struct IEnumConnections,&struct __s_GUID const
   _GUID_b196b287_bab4_101a_b69c_00aa00341d07,struct tagCONNECTDATA,class ATL::_Copy<struct
   tagCONNECTDATA>,class ATL::CComMultiThreadModel>::_InternalQueryInterface(struct _GUID const
   &,void * *)
    public: long __thiscall CTextImageEventSink<class
   CVsTextSpanSet>::_InternalQueryInterface(struct _GUID const &,void * *)
    public: long __thiscall CTextLinesEventSink<class
   CVsTextSpanSet>::_InternalQueryInterface(struct _GUID const &,void * *)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __thiscall InternalQueryInterface(void *this,_GUID *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_1000eec0();
  FUN_10009a60((int)this,(int *)ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_1000f0a0 at 1000f0a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000f0a0(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (0xf < (uint)param_1[5]) {
    local_c = (undefined4 *)FUN_100019b0(*param_1);
  }
  return local_c;
}



// Function: FUN_1000f0f0 at 1000f0f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_1000f0f0(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (0xf < (uint)param_1[5]) {
    local_c = (undefined4 *)FUN_100019b0(*param_1);
  }
  return local_c;
}



// Function: FUN_1000f140 at 1000f140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000f140(void *this,char param_1,size_t param_2)

{
  void *pvVar1;
  size_t sVar2;
  undefined1 local_10 [3];
  undefined1 uStack_d;
  void *local_c;
  void *local_8;
  
  _local_10 = 0xcccccccc;
  local_c = (void *)0xcccccccc;
  local_8 = this;
  if ((param_1 != '\0') && (0xf < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    local_c = *this;
    FUN_1000eed0((IUnknown *)(local_10 + 3));
    FUN_10001ae0();
    if (param_2 != 0) {
      sVar2 = param_2;
      pvVar1 = (void *)FUN_100019b0(local_c);
      FUN_1000f4f0(local_8,pvVar1,sVar2);
    }
    pvVar1 = local_c;
    FUN_1000eed0((IUnknown *)(local_10 + 2));
    FUN_1000f540(pvVar1);
  }
  *(undefined4 *)((int)local_8 + 0x14) = 0xf;
  FUN_1000ee60(local_8,param_2);
  return;
}



// Function: FUN_1000f200 at 1000f200

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f200(void)

{
  std::_Xlength_error("string too long");
  return;
}



// Function: FUN_1000f240 at 1000f240

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f240(void)

{
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: FUN_1000f280 at 1000f280

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1000f280(char *param_1,int param_2)

{
  strchr(param_1,param_2);
  return;
}



// Function: FUN_1000f2a0 at 1000f2a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f2a0(uint param_1)

{
  FUN_1000f2d0(param_1);
  return;
}



// Function: FUN_1000f2d0 at 1000f2d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f2d0(uint param_1)

{
  FUN_10001950(param_1);
  return;
}



// Function: FUN_1000f300 at 1000f300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000f300(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 local_c;
  
  uVar2 = FUN_1000fcc0((int)param_1);
  if (uVar2 < param_2) {
    FUN_1000f240();
  }
  iVar3 = FUN_1000fcc0((int)param_1);
  local_c = iVar3 - param_2;
  if (param_3 < local_c) {
    local_c = param_3;
  }
  if ((undefined4 *)this == param_1) {
    FUN_1000f710(this,param_2 + local_c);
    FUN_1000f750(this,0,param_2);
  }
  else {
    bVar1 = FUN_1000ef00(this,local_c,'\0');
    if (bVar1) {
      uVar2 = local_c;
      puVar4 = FUN_1000f0f0(param_1);
      pvVar5 = (void *)((int)puVar4 + param_2);
      puVar4 = FUN_1000f0a0((undefined4 *)this);
      FUN_1000f4f0(puVar4,pvVar5,uVar2);
      FUN_1000ee60(this,local_c);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f3d0 at 1000f3d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000f3d0(void *this,char *param_1)

{
  size_t sVar1;
  
  sVar1 = FUN_1000f810(param_1);
  FUN_1000f410(this,(undefined4 *)param_1,sVar1);
  return;
}



// Function: FUN_1000f410 at 1000f410

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000f410(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_1000efd0(this,param_1);
  if ((uVar2 & 0xff) == 0) {
    bVar1 = FUN_1000ef00(this,param_2,'\0');
    if (bVar1) {
      uVar2 = param_2;
      puVar3 = FUN_1000f0a0((undefined4 *)this);
      FUN_1000f4f0(puVar3,param_1,uVar2);
      FUN_1000ee60(this,param_2);
    }
  }
  else {
    puVar3 = FUN_1000f0a0((undefined4 *)this);
    this = FUN_1000f300(this,(undefined4 *)this,(int)param_1 - (int)puVar3,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f4a0 at 1000f4a0

void __cdecl FUN_1000f4a0(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  return;
}



// Function: FUN_1000f4b0 at 1000f4b0

undefined4 __fastcall FUN_1000f4b0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000f4d0 at 1000f4d0

undefined4 __fastcall FUN_1000f4d0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000f4f0 at 1000f4f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_1000f4f0(void *param_1,void *param_2,size_t param_3)

{
  undefined4 local_8;
  
  if (param_3 == 0) {
    local_8 = param_1;
  }
  else {
    local_8 = memcpy(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000f540 at 1000f540

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f540(void *param_1)

{
  FUN_1000f570(param_1);
  return;
}



// Function: FUN_1000f570 at 1000f570

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f570(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1000f5a0 at 1000f5a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_1000f5a0(void *param_1,int param_2)

{
  char *pcVar1;
  undefined *puVar2;
  
  pcVar1 = std::_Syserror_map(param_2);
  if (pcVar1 == (char *)0x0) {
    puVar2 = FUN_1000fd60();
    FUN_10002ca0(param_1,param_2,puVar2);
  }
  else {
    puVar2 = FUN_1000f800();
    FUN_10002ca0(param_1,param_2,puVar2);
  }
  return param_1;
}



// Function: FUN_1000f610 at 1000f610

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_1000f610(void *this,void *param_1,undefined4 param_2)

{
  FUN_10002ca0(param_1,param_2,this);
  return param_1;
}



// Function: FUN_1000f650 at 1000f650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined1 __thiscall FUN_1000f650(void *this,undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_1000f4b0((int)param_1);
  bVar1 = FUN_10003c80(this,iVar2);
  if ((bVar1) && (iVar2 = FUN_1000fda0(param_1), iVar2 == param_2)) {
    return 1;
  }
  return 0;
}



// Function: FUN_1000f6b0 at 1000f6b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_1000f6b0(void *this,undefined4 param_1,undefined4 param_2)

{
  void *this_00;
  undefined4 local_10;
  undefined4 local_c;
  void *local_8;
  
  local_10 = 0xcccccccc;
  local_c = 0xcccccccc;
                    /* WARNING: Load size is inaccurate */
  local_8 = this;
  this_00 = (void *)(**(code **)(*this + 0xc))(&local_10,param_1,param_2);
  FUN_10003cc0(this_00,(undefined4 *)0x1000f6f1);
  return;
}



// Function: FUN_1000f710 at 1000f710

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_1000f710(void *this,uint param_1)

{
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000f240();
  }
  FUN_1000ee60(this,param_1);
  return this;
}



// Function: FUN_1000f750 at 1000f750

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_1000f750(void *this,uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000f240();
  }
  if (param_2 < *(int *)((int)this + 0x10) - param_1) {
    if (param_2 != 0) {
      puVar1 = FUN_1000f0a0((undefined4 *)this);
      iVar2 = *(int *)((int)this + 0x10) - param_2;
      FUN_1000fb70((void *)((int)puVar1 + param_1),(void *)((int)((int)puVar1 + param_1) + param_2),
                   iVar2 - param_1);
      FUN_1000ee60(this,iVar2);
    }
  }
  else {
    FUN_1000ee60(this,param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f800 at 1000f800

undefined * FUN_1000f800(void)

{
  return &DAT_10029904;
}



// Function: FUN_1000f810 at 1000f810

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

size_t __cdecl FUN_1000f810(char *param_1)

{
  undefined4 local_8;
  
  if (*param_1 == '\0') {
    local_8 = 0;
  }
  else {
    local_8 = strlen(param_1);
  }
  return local_8;
}



// Function: FUN_1000f850 at 1000f850

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f850(void)

{
  FUN_1000f8a0();
  return;
}



// Function: FUN_1000f880 at 1000f880

undefined4 FUN_1000f880(void)

{
  return 0xffffffff;
}



// Function: FUN_1000f8a0 at 1000f8a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1000f8a0(void)

{
  FUN_1000f880();
  return;
}



// Function: FUN_1000f8c0 at 1000f8c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_1000f8c0(void)

{
  uint uVar1;
  int local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  local_10 = (undefined1  [4])0xcccccccc;
  local_c = 0xcccccccc;
  FUN_1000eed0((IUnknown *)(local_10 + 3));
  uVar1 = FUN_1000f850();
  if (uVar1 < 2) {
    local_14 = 1;
  }
  else {
    local_14 = uVar1 - 1;
  }
  return local_14;
}



// Function: FUN_1000f920 at 1000f920

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1000f920(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000f960 at 1000f960

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000f960(undefined4 param_1,int param_2)

{
  char *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d229;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = std::_Syserror_map(param_2);
  if (local_20 == (char *)0x0) {
    local_20 = "unknown error";
  }
  FUN_100024c0(local_20);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fa10 at 1000fa10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000fa10(undefined4 param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d269;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 == 1) {
    FUN_100024c0("iostream stream error");
  }
  else {
    FUN_1000f960(param_1,param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fac0 at 1000fac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 FUN_1000fac0(undefined4 param_1,int param_2)

{
  char *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d2a9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = std::_Winerror_map(param_2);
  if (local_20 == (char *)0x0) {
    local_20 = "unknown error";
  }
  FUN_100024c0(local_20);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000fb70 at 1000fb70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_1000fb70(void *param_1,void *param_2,size_t param_3)

{
  undefined4 local_8;
  
  if (param_3 == 0) {
    local_8 = param_1;
  }
  else {
    local_8 = memmove(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_1000fbc0 at 1000fbc0

char * FUN_1000fbc0(void)

{
  return "generic";
}



// Function: FUN_1000fbe0 at 1000fbe0

char * FUN_1000fbe0(void)

{
  return "iostream";
}



// Function: FUN_1000fc00 at 1000fc00

char * FUN_1000fc00(void)

{
  return "system";
}



// Function: FUN_1000fc20 at 1000fc20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_1000fc20(void *param_1,int param_2,wchar_t *param_3)

{
  size_t sVar1;
  errno_t eVar2;
  
  sVar1 = FUN_1000fc90(param_3);
  eVar2 = memcpy_s(param_1,param_2 << 1,param_3,sVar1 * 2 + 2);
  return eVar2 == 0;
}



// Function: FUN_1000fc90 at 1000fc90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

size_t __cdecl FUN_1000fc90(wchar_t *param_1)

{
  size_t sVar1;
  
  if (param_1 == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = wcslen(param_1);
  }
  return sVar1;
}



// Function: FUN_1000fcc0 at 1000fcc0

undefined4 __fastcall FUN_1000fcc0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: strcpy_s at 1000fce0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    void __cdecl ATL::Checked::strcpy_s(char *,unsigned int,char const *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __cdecl ATL::Checked::strcpy_s(char *param_1,uint param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcat_s(param_1,param_2,param_3);
  AtlCrtErrorCheck(eVar1);
  return;
}



// Function: strcpy_s at 1000fd20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    void __cdecl ATL::Checked::strcpy_s(char *,unsigned int,char const *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __cdecl ATL::Checked::strcpy_s(char *param_1,uint param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = ::strcpy_s(param_1,param_2,param_3);
  AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000fd60 at 1000fd60

undefined * FUN_1000fd60(void)

{
  return &DAT_1002990c;
}



// Function: FUN_1000fd70 at 1000fd70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1000fd70(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
  int iVar1;
  
  iVar1 = FUN_1000ff50(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(iVar1);
  return;
}



// Function: FUN_1000fda0 at 1000fda0

undefined4 __fastcall FUN_1000fda0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000fdc0 at 1000fdc0

undefined4 __fastcall FUN_1000fdc0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000fde0 at 1000fde0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1000fde0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: _HRESULT_FROM_WIN32 at 1000fe20

/* Library Function - Single Match
    _HRESULT_FROM_WIN32
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

HRESULT __cdecl _HRESULT_FROM_WIN32(ulong x)

{
  undefined4 local_8;
  
  if ((int)x < 1) {
    local_8 = x;
  }
  else {
    local_8 = x & 0xffff | 0x80070000;
  }
  return local_8;
}



// Function: FID_conflict:_AfxIsEqualGUID at 1000fe60

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _AfxIsEqualGUID(struct _GUID const &,struct _GUID const &)
    _InlineIsEqualGUID
   
   Library: Visual Studio 2012 Debug */

undefined4 __cdecl FID_conflict__AfxIsEqualGUID(int *param_1,int *param_2)

{
  undefined4 local_8;
  
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



// Function: _IsEqualGUID at 1000ff00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    _IsEqualGUID
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

bool __cdecl _IsEqualGUID(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return iVar1 == 0;
}



// Function: FUN_1000ff50 at 1000ff50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_1000ff50(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
  _mbsnbcpy_s(param_1,param_2,param_3,param_4);
  return;
}



// Function: strchr at 1000ff80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Same Base Name
    char * __cdecl strchr(char *,int)
    char * __cdecl strchr(char * const,int)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

char * __cdecl strchr(char *_Str,int _Val)

{
  uchar *puVar1;
  
  puVar1 = _mbsstr((uchar *)_Str,(uchar *)_Val);
  return (char *)puVar1;
}



// Function: FUN_1000ffb0 at 1000ffb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_1000ffb0(IUnknown *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d2fc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001f00((CHeapPtrBase<unsigned_short,class_ATL::CCRTAllocator> *)(param_1 + 4));
  local_8 = 0;
  FUN_10013710(param_1);
  FUN_10013680(param_1 + 1);
  FUN_100136e0(param_1 + 2);
  FUN_10012fa0(param_1 + 3);
  FUN_10013430((LPCRITICAL_SECTION)(param_1 + 0xc));
  local_8._0_1_ = 1;
  FUN_100138a0(param_1 + 0x12);
  local_8._0_1_ = 2;
  FUN_10013190(param_1 + 0x14,1);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10013d00(param_1 + 0x12,"");
  *(undefined1 *)&param_1[0x44].lpVtbl = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10010090 at 10010090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10010090(int param_1)

{
  ulong uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001d343;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 3;
  uVar1 = CPropertySection::GetCount((CPropertySection *)(param_1 + 0x50));
  if ((uVar1 & 0xff) != 0) {
    FUN_100156e0((int *)(param_1 + 0x50));
  }
  local_8._0_1_ = 2;
  FUN_100140b0(param_1 + 0x50);
  local_8._0_1_ = 1;
  FUN_10013b90((int *)(param_1 + 0x48));
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__CPaneContainerGC((LPCRITICAL_SECTION)(param_1 + 0x30));
  local_8 = 0xffffffff;
  FUN_100030e0(param_1 + 0x10);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010140 at 10010140

undefined4 FUN_10010140(void)

{
  return 0;
}



// Function: CTextFileStreamObj_Read at 10010160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 CTextFileStreamObj_Read(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return 1;
    }
    iVar1 = FID_conflict__AfxIsEqualGUID((int *)(&PTR_DAT_100295f8)[local_8],param_2);
    if (iVar1 != 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: CTextFileStreamObj_Read at 100101c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Read(int param_1,char *param_2,undefined4 param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  __int64 _Var4;
  undefined8 uVar5;
  uint uStack_6c;
  undefined4 local_5c [12];
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_20 [12];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d36e;
  local_10 = ExceptionList;
  puVar3 = local_5c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_6c = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_6c;
  ExceptionList = &local_10;
  FUN_10012f60(local_20,param_1 + 0x28);
  local_28 = 0;
  local_8 = 1;
  local_2c = 0;
  if (param_2 == (char *)0x0) {
    assertFailure((uchar *)"TextFileStreamObj.cpp");
  }
  else {
    bVar1 = std::ios_base::eof((ios_base *)(param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4))
                              );
    if (!bVar1) {
      std::basic_istream<char,struct_std::char_traits<char>_>::read
                ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x48),param_2,
                 0x1001024c00000000);
      bVar1 = std::ios_base::fail((ios_base *)
                                  (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
      if ((!bVar1) ||
         (bVar1 = std::ios_base::eof((ios_base *)
                                     (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4))),
         bVar1)) {
        uStack_6c = 0x1001031e;
        bVar1 = std::ios_base::eof((ios_base *)
                                   (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
        uStack_6c = 0x10010325;
        if (bVar1) {
          std::basic_ios<char,struct_std::char_traits<char>_>::clear
                    ((basic_ios<char,struct_std::char_traits<char>_> *)
                     (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
          _Var4 = std::basic_istream<char,struct_std::char_traits<char>_>::gcount
                            ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x48))
          ;
          local_2c = (undefined4)_Var4;
          uStack_6c = 0x10010364;
        }
        else {
          local_2c = param_3;
        }
      }
      else {
        std::basic_ios<char,struct_std::char_traits<char>_>::clear
                  ((basic_ios<char,struct_std::char_traits<char>_> *)
                   (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
        assertFailure((uchar *)"TextFileStreamObj.cpp");
      }
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_2c;
    }
  }
  uVar5 = CTextFileStreamObj_Write();
  return uVar5;
}



// Function: Catch@100103a5 at 100103a5

undefined * Catch_100103a5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x30),"TextFileStreamObj.cpp",0xb8,
                       "CTextFileStreamObj::Read",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x50) = uVar2;
  return &DAT_1001047d;
}



// Function: Catch@100103f1 at 100103f1

undefined * Catch_100103f1(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x48),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x48),"TextFileStreamObj.cpp",0xb8,
                       "CTextFileStreamObj::Read",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x54) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10010452;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return &DAT_10010467;
}



// Function: CTextFileStreamObj_Write at 1001045e

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Write(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10013940((undefined4 *)(unaff_EBP + -0x1c));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x58);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100104d8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: CTextFileStreamObj_Write at 10010510

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Write(int param_1,char *param_2,undefined4 param_3,undefined4 *param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 local_5c [12];
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_20 [12];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d399;
  local_10 = ExceptionList;
  puVar4 = local_5c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = &stack0xffffff94;
  ExceptionList = &local_10;
  FUN_10012f60(local_20,param_1 + 0x28);
  local_28 = 0;
  local_8 = 1;
  local_2c = 0;
  if (param_2 == (char *)0x0) {
    assertFailure((uchar *)"TextFileStreamObj.cpp");
  }
  else {
    std::basic_ostream<char,struct_std::char_traits<char>_>::write
              ((basic_ostream<char,struct_std::char_traits<char>_> *)(param_1 + 0x58),param_2,
               (ulonglong)uVar2 << 0x20);
    bVar1 = std::ios_base::fail((ios_base *)
                                (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
    if (bVar1) {
      std::basic_ios<char,struct_std::char_traits<char>_>::clear
                ((basic_ios<char,struct_std::char_traits<char>_> *)
                 (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
      assertFailure((uchar *)"TextFileStreamObj.cpp");
    }
    else {
      local_2c = param_3;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_2c;
    }
    *(undefined1 *)(param_1 + 0x108) = 1;
  }
  uVar5 = CTextFileStreamObj_Seek();
  return uVar5;
}



// Function: Catch@1001064f at 1001064f

undefined * Catch_1001064f(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x30),"TextFileStreamObj.cpp",0xed,
                       "CTextFileStreamObj::Write",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x50) = uVar2;
  return &DAT_10010727;
}



// Function: Catch@1001069b at 1001069b

undefined * Catch_1001069b(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x48),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x48),"TextFileStreamObj.cpp",0xed,
                       "CTextFileStreamObj::Write",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x54) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x100106fc;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return &DAT_10010711;
}



// Function: CTextFileStreamObj_Seek at 10010708

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Seek(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10013940((undefined4 *)(unaff_EBP + -0x1c));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x58);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10010784);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: CTextFileStreamObj_Seek at 100107c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Seek(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  uint uStack_90;
  int local_80 [19];
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined1 local_20 [12];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d3c4;
  local_10 = ExceptionList;
  piVar4 = local_80;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = -0x33333334;
    piVar4 = piVar4 + 1;
  }
  uStack_90 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  FUN_10012f60(local_20,param_1 + 0x28);
  local_28 = 0;
  local_8 = 1;
  local_2c = 1;
  local_30 = param_2;
  local_34 = 0;
  if (param_3 == 0) {
    local_80[0] = param_4;
    if (param_4 == 0) {
      local_2c = 0;
    }
    else if (param_4 == 1) {
      local_2c = 1;
    }
    else if (param_4 == 2) {
      local_2c = 2;
    }
    else {
      assertFailure((uchar *)"TextFileStreamObj.cpp");
    }
    if (param_5 == (undefined4 *)0x0) {
      std::basic_istream<char,struct_std::char_traits<char>_>::seekg
                ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x48),
                 (longlong)local_30,local_2c);
      bVar1 = std::ios_base::fail((ios_base *)
                                  (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
      if (bVar1) {
        std::basic_ios<char,struct_std::char_traits<char>_>::clear
                  ((basic_ios<char,struct_std::char_traits<char>_> *)
                   (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
        assertFailure((uchar *)"TextFileStreamObj.cpp");
      }
    }
    else {
      param_5[1] = 0;
      std::basic_istream<char,struct_std::char_traits<char>_>::seekg
                ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x48),
                 (longlong)local_30,local_2c);
      bVar1 = std::ios_base::fail((ios_base *)
                                  (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
      if (bVar1) {
        std::basic_ios<char,struct_std::char_traits<char>_>::clear
                  ((basic_ios<char,struct_std::char_traits<char>_> *)
                   (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
        assertFailure((uchar *)"TextFileStreamObj.cpp");
      }
      else {
        puVar2 = (uint *)std::basic_istream<char,struct_std::char_traits<char>_>::tellg
                                   ((basic_istream<char,struct_std::char_traits<char>_> *)
                                    (param_1 + 0x48));
        uVar5 = FUN_10013ef0(puVar2);
        *param_5 = (int)uVar5;
      }
    }
  }
  else {
    assertFailure((uchar *)"TextFileStreamObj.cpp");
  }
  uVar5 = FUN_10010ac3();
  return uVar5;
}



// Function: Catch@10010a0a at 10010a0a

undefined * Catch_10010a0a(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x38),"TextFileStreamObj.cpp",0x140,
                       "CTextFileStreamObj::Seek",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_10010ae2;
}



// Function: Catch@10010a56 at 10010a56

undefined * Catch_10010a56(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x50),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x50),"TextFileStreamObj.cpp",0x140,
                       "CTextFileStreamObj::Seek",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x74) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10010ab7;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return &DAT_10010acc;
}



// Function: FUN_10010ac3 at 10010ac3

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10010ac3(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10013940((undefined4 *)(unaff_EBP + -0x1c));
  uVar1 = *(undefined4 *)(unaff_EBP + -0x78);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10010b40);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: CTextFileStreamObj_CopyTo at 10010b80

undefined4 CTextFileStreamObj_CopyTo(void)

{
  return 0x80004001;
}



// Function: CTextFileStreamObj_CopyTo at 10010b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void CTextFileStreamObj_CopyTo(int param_1,int *param_2,uint param_3,int param_4,int *param_5,int *param_6)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  __int64 _Var4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uStack_4a4;
  undefined4 local_494 [12];
  int local_464;
  int local_460;
  int local_458;
  int local_454;
  uint local_448;
  int local_444;
  uint local_43c;
  char local_434;
  undefined1 local_433 [1027];
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_24 [12];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d3f2;
  local_10 = ExceptionList;
  puVar3 = local_494;
  for (iVar2 = 0x120; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_4a4 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4a4;
  ExceptionList = &local_10;
  local_18 = uStack_4a4;
  FUN_10012f60(local_24,param_1 + 0x28);
  local_2c = 0;
  local_8 = 1;
  local_30 = 0x400;
  local_434 = '\0';
  memset(local_433,0,0x3ff);
  local_43c = 0x400;
  if (param_4 == 0) {
    local_460 = 0;
    local_464 = 0;
    local_444 = 0;
    local_454 = 0;
    if (param_2 == (int *)0x0) {
      assertFailure((uchar *)"TextFileStreamObj.cpp");
    }
    else {
      local_448 = 0x400;
      while ((param_3 != 0 && (local_448 != 0))) {
        if (param_3 < local_43c) {
          local_43c = param_3;
        }
        bVar1 = std::ios_base::eof((ios_base *)
                                   (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
        if (bVar1) {
          local_448 = 0;
        }
        else {
          std::basic_istream<char,struct_std::char_traits<char>_>::read
                    ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x48),
                     &local_434,CONCAT44(0x10010cb8,(int)local_43c >> 0x1f));
          uVar8 = 0x10010ce8;
          bVar1 = std::ios_base::fail((ios_base *)
                                      (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
          uVar7 = 0x10010d07;
          if (bVar1) {
            std::basic_ios<char,struct_std::char_traits<char>_>::clear
                      ((basic_ios<char,struct_std::char_traits<char>_> *)
                       (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
            uVar6 = 0x10010d31;
            pcVar5 = "An error occurred while reading the file";
            assertFailure((uchar *)"TextFileStreamObj.cpp");
          }
          else {
            bVar1 = std::ios_base::eof((ios_base *)
                                       (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)));
            uVar6 = 0x10010d70;
            if (bVar1) {
              local_448 = local_43c;
              std::basic_ios<char,struct_std::char_traits<char>_>::clear
                        ((basic_ios<char,struct_std::char_traits<char>_> *)
                         (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
              pcVar5 = (char *)0x10010da6;
            }
            else {
              _Var4 = std::basic_istream<char,struct_std::char_traits<char>_>::gcount
                                ((basic_istream<char,struct_std::char_traits<char>_> *)
                                 (param_1 + 0x48));
              local_448 = (uint)_Var4;
              pcVar5 = (char *)0x10010dbd;
            }
          }
          local_460 = local_460 + local_448;
          (**(code **)(*param_2 + 0x10))
                    (param_2,&local_434,local_448,&local_458,pcVar5,uVar6,uVar7,uVar8);
          uStack_4a4 = 0x10010e01;
          local_464 = local_464 + local_458;
          param_3 = param_3 - local_43c;
        }
      }
    }
    if (param_5 != (int *)0x0) {
      param_5[1] = local_444;
      *param_5 = local_460;
    }
    if (param_6 != (int *)0x0) {
      param_6[1] = local_454;
      *param_6 = local_464;
    }
  }
  else {
    assertFailure((uchar *)"TextFileStreamObj.cpp");
  }
  CTextFileStreamObj_Commit();
  return;
}



// Function: Catch@10010eb5 at 10010eb5

undefined * Catch_10010eb5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x468),"TextFileStreamObj.cpp",0x1ad,
                       "CTextFileStreamObj::CopyTo",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x488) = uVar2;
  return &DAT_10010fa2;
}



// Function: Catch@10010f07 at 10010f07

undefined * Catch_10010f07(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x480),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x480),"TextFileStreamObj.cpp",0x1ad,
                       "CTextFileStreamObj::CopyTo",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x48c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10010f74;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x480));
  return &DAT_10010f89;
}



// Function: CTextFileStreamObj_Commit at 10010f80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void CTextFileStreamObj_Commit(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  *(undefined4 *)(unaff_EBP - 0x490) = *(undefined4 *)(unaff_EBP - 0x28);
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10013940((undefined4 *)(unaff_EBP - 0x20));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011014);
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10011000;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CTextFileStreamObj_Commit at 10011090

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Commit(int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  basic_ostream<char,struct_std::char_traits<char>_> **ppbVar4;
  undefined8 uVar5;
  uint uStack_60;
  basic_ostream<char,struct_std::char_traits<char>_> *local_50 [13];
  undefined1 local_1c [8];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d422;
  local_10 = ExceptionList;
  ppbVar4 = local_50;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppbVar4 = (basic_ostream<char,struct_std::char_traits<char>_> *)0xcccccccc;
    ppbVar4 = ppbVar4 + 1;
  }
  uStack_60 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  FUN_10017250(local_1c,0);
  local_8 = 0;
  uVar2 = CPropertySection::GetCount((CPropertySection *)(param_1 + 0x48));
  if ((uVar2 & 0xff) != 0) {
    local_50[2] = std::basic_ostream<char,struct_std::char_traits<char>_>::flush
                            ((basic_ostream<char,struct_std::char_traits<char>_> *)(param_1 + 0x58))
    ;
    bVar1 = std::ios_base::fail((ios_base *)(local_50[2] + *(int *)(*(int *)local_50[2] + 4)));
    if (!bVar1) goto LAB_10011148;
  }
  assertFailure((uchar *)"TextFileStreamObj.cpp");
LAB_10011148:
  uVar5 = CTextFileStreamObj_Revert();
  return uVar5;
}



// Function: Catch@1001114d at 1001114d

undefined * Catch_1001114d(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x24),"TextFileStreamObj.cpp",0x348,
                       "CTextFileStreamObj::Commit",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar2;
  return &DAT_1001121d;
}



// Function: Catch@10011199 at 10011199

undefined * Catch_10011199(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x3c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x3c),"TextFileStreamObj.cpp",0x348,
                       "CTextFileStreamObj::Commit",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x4c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100111fa;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x3c));
  return &DAT_1001120f;
}



// Function: CTextFileStreamObj_Revert at 10011206

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Revert(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = FUN_10017670((undefined4 *)(unaff_EBP + -0x18));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011260);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: CTextFileStreamObj_Revert at 100112a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Revert(int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  undefined1 **ppuVar4;
  undefined8 uVar5;
  undefined1 auStack_80 [8];
  undefined4 uStack_78;
  uint uStack_60;
  undefined1 *local_50 [13];
  undefined1 local_1c [8];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d445;
  local_10 = ExceptionList;
  ppuVar4 = local_50;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppuVar4 = (undefined1 *)0xcccccccc;
    ppuVar4 = ppuVar4 + 1;
  }
  uStack_60 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  FUN_10017250(local_1c,0);
  local_8 = 0;
  uVar2 = CPropertySection::GetCount((CPropertySection *)(param_1 + 0x48));
  if ((uVar2 & 0xff) == 0) {
    uStack_78 = 0x10011384;
    assertFailure((uchar *)"TextFileStreamObj.cpp");
    FUN_10017550(local_1c,-0x7fffbffb);
  }
  else {
    bVar1 = std::ios_base::eof((ios_base *)(param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4))
                              );
    if (bVar1) {
      std::basic_ios<char,struct_std::char_traits<char>_>::clear
                ((basic_ios<char,struct_std::char_traits<char>_> *)
                 (param_1 + 0x48 + *(int *)(*(int *)(param_1 + 0x48) + 4)),0,false);
    }
    local_50[2] = auStack_80;
    FUN_100133f0(auStack_80,0,0);
    std::basic_istream<char,struct_std::char_traits<char>_>::seekg
              ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x48));
  }
  uVar5 = FUN_10011452();
  return uVar5;
}



// Function: Catch@10011399 at 10011399

undefined * Catch_10011399(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x24),"TextFileStreamObj.cpp",0x36d,
                       "CTextFileStreamObj::Revert",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar2;
  return &DAT_10011469;
}



// Function: Catch@100113e5 at 100113e5

undefined * Catch_100113e5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x3c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x3c),"TextFileStreamObj.cpp",0x36d,
                       "CTextFileStreamObj::Revert",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x4c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10011446;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x3c));
  return &DAT_1001145b;
}



// Function: FUN_10011452 at 10011452

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10011452(void)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = FUN_10017670((undefined4 *)(unaff_EBP + -0x18));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100114ac);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(extraout_EDX,uVar1);
}



// Function: FUN_100114f0 at 100114f0

undefined4 FUN_100114f0(void)

{
  return 0x80004001;
}



// Function: FUN_10011500 at 10011500

undefined4 FUN_10011500(void)

{
  return 0x80004001;
}



// Function: FUN_10011510 at 10011510

undefined4 FUN_10011510(void)

{
  return 0x80004001;
}



// Function: CTextFileStreamObj_GetClassID at 10011520

undefined4 CTextFileStreamObj_GetClassID(void)

{
  return 0x80004001;
}



// Function: CTextFileStreamObj_GetClassID at 10011530

undefined8 CTextFileStreamObj_GetClassID(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_54;
  undefined4 local_44 [11];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d468;
  local_10 = ExceptionList;
  puVar2 = local_44;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_54 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 0;
  *param_2 = 0xf4da2d74;
  param_2[1] = 0x11d5bc06;
  param_2[2] = 0x400e9a0;
  param_2[3] = 0xb03196ac;
  uVar3 = CTextFileStreamObj_IsDirty(0x400e9a0,0xb03196ac);
  return uVar3;
}



// Function: Catch@100115a4 at 100115a4

undefined * Catch_100115a4(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"TextFileStreamObj.cpp",0x2f2,
                       "CTextFileStreamObj::GetClassID",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
  return &DAT_10011674;
}



// Function: Catch@100115f0 at 100115f0

undefined * Catch_100115f0(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"TextFileStreamObj.cpp",0x2f2,
                       "CTextFileStreamObj::GetClassID",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10011651;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_10011666;
}



// Function: CTextFileStreamObj_IsDirty at 1001165d

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CTextFileStreamObj_IsDirty(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100116b4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CTextFileStreamObj_IsDirty at 100116e0

undefined8 __fastcall CTextFileStreamObj_IsDirty(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_54;
  undefined4 local_44 [11];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d48b;
  local_10 = ExceptionList;
  puVar2 = local_44;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_54 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = (uint)(*(byte *)(param_3 + 0x10c) == 0);
  uVar3 = CTextFileStreamObj_Load((uint)*(byte *)(param_3 + 0x10c),param_2);
  return uVar3;
}



// Function: Catch@10011743 at 10011743

undefined * Catch_10011743(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"TextFileStreamObj.cpp",0x2e0,
                       "CTextFileStreamObj::IsDirty",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
  return &DAT_10011813;
}



// Function: Catch@1001178f at 1001178f

undefined * Catch_1001178f(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"TextFileStreamObj.cpp",0x2e0,
                       "CTextFileStreamObj::IsDirty",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100117f0;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_10011805;
}



// Function: CTextFileStreamObj_Load at 100117fc

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall CTextFileStreamObj_Load(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011854);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CTextFileStreamObj_Load at 10011880

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* WARNING: Removing unreachable block (ram,0x10011983) */
/* WARNING: Removing unreachable block (ram,0x100119ac) */
/* WARNING: Removing unreachable block (ram,0x10011989) */
/* WARNING: Removing unreachable block (ram,0x100119b3) */

void CTextFileStreamObj_Load(int param_1,int param_2,uint param_3)

{
  wchar_t *_Name;
  ulong uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  _stat64i32 *_Stat;
  uint uStack_bc;
  undefined4 local_ac [12];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  _stat64i32 local_6c;
  int local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined1 local_24 [12];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d4b9;
  local_10 = ExceptionList;
  puVar4 = local_ac;
  for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uStack_bc = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_bc;
  ExceptionList = &local_10;
  local_18 = uStack_bc;
  FUN_10012f60(local_24,param_1 + 0x2c);
  local_2c = 0;
  local_8 = 1;
  if (param_3 == 0x4000000) {
    FUN_100156e0((int *)(param_1 + 0x4c));
  }
  else {
    local_30 = 99;
    local_34 = 0;
    FUN_10013dd0((void *)(param_1 + 0x44),param_2);
    if ((param_3 & 0xf) == 0) {
      local_30 = 0x61;
    }
    if ((param_3 & 1) != 0) {
      local_30 = 0x33;
    }
    if ((param_3 & 2) != 0) {
      local_30 = 99;
    }
    if ((param_3 & 0x40) != 0) {
      local_34 = 0;
    }
    _Stat = &local_6c;
    _Name = (wchar_t *)FUN_10014010((int *)(param_1 + 0x44));
    local_38 = _wstat64i32(_Name,_Stat);
    if ((param_3 & 0x1000) != 0) {
      local_30 = 0x33;
    }
    uVar1 = CPropertySection::GetCount((CPropertySection *)(param_1 + 0x4c));
    if ((uVar1 & 0xff) != 0) {
      FUN_100156e0((int *)(param_1 + 0x4c));
    }
    if (((local_30 & 0x40) != 0) && (local_38 == -1)) {
      local_74 = FUN_10013f20((int *)(param_1 + 0x44));
      assertFailure((uchar *)"TextFileStreamObj.cpp");
    }
    if (((local_30 & 2) != 0) && ((local_6c.st_mode & 0x80) == 0)) {
      local_78 = FUN_10013f20((int *)(param_1 + 0x44));
      assertFailure((uchar *)"TextFileStreamObj.cpp");
    }
    iVar3 = 0x40;
    uVar5 = local_30;
    puVar2 = (ushort *)FUN_10014010((int *)(param_1 + 0x44));
    FUN_10015cd0((void *)(param_1 + 0x4c),puVar2,uVar5,iVar3);
    uVar1 = CPropertySection::GetCount((CPropertySection *)(param_1 + 0x4c));
    if ((uVar1 & 0xff) == 0) {
      local_7c = FUN_10013f20((int *)(param_1 + 0x44));
      assertFailure((uchar *)"TextFileStreamObj.cpp");
    }
  }
  CTextFileStreamObj_Save();
  return;
}



// Function: Catch@10011ad5 at 10011ad5

undefined * Catch_10011ad5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x80),"TextFileStreamObj.cpp",0x234,
                       "CTextFileStreamObj::Load",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0xa0) = uVar2;
  return &DAT_10011bbf;
}



// Function: Catch@10011b24 at 10011b24

undefined * Catch_10011b24(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x98),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x98),"TextFileStreamObj.cpp",0x234,
                       "CTextFileStreamObj::Load",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0xa4) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10011b91;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x98));
  return &DAT_10011ba6;
}



// Function: CTextFileStreamObj_Save at 10011b9d

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void CTextFileStreamObj_Save(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  *(undefined4 *)(unaff_EBP - 0xa8) = *(undefined4 *)(unaff_EBP - 0x28);
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10013940((undefined4 *)(unaff_EBP - 0x20));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10011c30);
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10011c1d;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CTextFileStreamObj_Save at 10011c80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void CTextFileStreamObj_Save(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  bool bVar2;
  ushort *puVar3;
  ulong uVar4;
  int iVar5;
  undefined1 **ppuVar6;
  __int64 _Var7;
  char *in_stack_fffffa94;
  int iVar8;
  uint uStack_554;
  undefined1 *local_544 [13];
  undefined4 local_510;
  int local_508 [4];
  basic_ostream<char,struct_std::char_traits<char>_> local_4f8 [184];
  char local_440 [1028];
  undefined4 local_3c;
  int local_34 [2];
  undefined4 local_2c;
  undefined1 local_24 [12];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d507;
  local_10 = ExceptionList;
  ppuVar6 = local_544;
  for (iVar5 = 0x14c; iVar5 != 0; iVar5 = iVar5 + -1) {
    *ppuVar6 = (undefined1 *)0xcccccccc;
    ppuVar6 = ppuVar6 + 1;
  }
  uStack_554 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_554;
  ExceptionList = &local_10;
  local_18 = uStack_554;
  FUN_10012f60(local_24,param_1 + 0x2c);
  local_2c = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_100137f0(local_34,param_2);
  local_8._0_1_ = 2;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if ((param_2 == 0) ||
     (bVar2 = FUN_10013ea0(local_34,(int *)(param_1 + 0x44)), uVar1 = (undefined1)local_8, !bVar2))
  {
    local_8._0_1_ = uVar1;
    FUN_10014010((int *)(param_1 + 0x44));
    (**(code **)(*(int *)(param_1 + 4) + 0x20))();
    *(undefined1 *)(param_1 + 0x10c) = 0;
  }
  else if (param_3 == 1) {
    local_2c = 0x80004001;
  }
  else {
    local_3c = 0x400;
    FUN_10013190(local_508,1);
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar8 = 0x40;
    iVar5 = 3;
    puVar3 = (ushort *)FUN_10014010(local_34);
    FUN_10015cd0(local_508,puVar3,iVar5,iVar8);
    uVar4 = CPropertySection::GetCount((CPropertySection *)local_508);
    if ((uVar4 & 0xff) == 0) {
      in_stack_fffffa94 = "TextFileStreamObj.cpp";
      assertFailure((uchar *)"TextFileStreamObj.cpp");
    }
    local_544[3] = &stack0xfffffa94;
    FUN_100133f0(&stack0xfffffa94,0,0);
    std::basic_istream<char,struct_std::char_traits<char>_>::seekg
              ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x4c));
    while (bVar2 = std::ios_base::eof((ios_base *)
                                      (param_1 + 0x4c + *(int *)(*(int *)(param_1 + 0x4c) + 4))),
          !bVar2) {
      local_510 = 0;
      std::basic_istream<char,struct_std::char_traits<char>_>::read
                ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x4c),local_440,
                 0x10011dd100000000);
      bVar2 = std::ios_base::fail((ios_base *)
                                  (param_1 + 0x4c + *(int *)(*(int *)(param_1 + 0x4c) + 4)));
      if (bVar2) {
        std::basic_ios<char,struct_std::char_traits<char>_>::clear
                  ((basic_ios<char,struct_std::char_traits<char>_> *)
                   (param_1 + 0x4c + *(int *)(*(int *)(param_1 + 0x4c) + 4)),0,false);
        in_stack_fffffa94 = "\v\x01";
        assertFailure((uchar *)"TextFileStreamObj.cpp");
      }
      else {
        bVar2 = std::ios_base::eof((ios_base *)
                                   (param_1 + 0x4c + *(int *)(*(int *)(param_1 + 0x4c) + 4)));
        if (bVar2) {
          _Var7 = std::basic_istream<char,struct_std::char_traits<char>_>::gcount
                            ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 0x4c))
          ;
          local_510 = (undefined4)_Var7;
          std::basic_ios<char,struct_std::char_traits<char>_>::clear
                    ((basic_ios<char,struct_std::char_traits<char>_> *)
                     (param_1 + 0x4c + *(int *)(*(int *)(param_1 + 0x4c) + 4)),0,false);
          in_stack_fffffa94 = (char *)0x10011ed9;
        }
        else {
          local_510 = 0x400;
        }
      }
      std::basic_ostream<char,struct_std::char_traits<char>_>::write
                (local_4f8,local_440,ZEXT48(in_stack_fffffa94) << 0x20);
      bVar2 = std::ios_base::fail((ios_base *)((int)local_508 + *(int *)(local_508[0] + 4)));
      if (bVar2) {
        assertFailure((uchar *)"TextFileStreamObj.cpp");
      }
    }
    uVar4 = CPropertySection::GetCount((CPropertySection *)local_508);
    if ((uVar4 & 0xff) != 0) {
      FUN_100156e0(local_508);
    }
    local_8._0_1_ = 2;
    FUN_100140b0((int)local_508);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10013b90(local_34);
  FUN_10012096();
  return;
}



// Function: Catch@10011fcb at 10011fcb

undefined * Catch_10011fcb(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x514),"TextFileStreamObj.cpp",0x29d,
                       "CTextFileStreamObj::Save",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x538) = uVar2;
  return &DAT_100120b8;
}



// Function: Catch@1001201d at 1001201d

undefined * Catch_1001201d(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x52c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x52c),"TextFileStreamObj.cpp",0x29d,
                       "CTextFileStreamObj::Save",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x53c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uStack0000001c = 0x1001208a;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x52c));
  return &DAT_1001209f;
}



// Function: FUN_10012096 at 10012096

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012096(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  *(undefined4 *)(unaff_EBP - 0x540) = *(undefined4 *)(unaff_EBP - 0x28);
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10013940((undefined4 *)(unaff_EBP - 0x20));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_1001212c);
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10012116;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CTextFileStreamObj_GetCurFile at 100121b0

undefined4 CTextFileStreamObj_GetCurFile(void)

{
  return 0x80004001;
}



// Function: CTextFileStreamObj_GetCurFile at 100121c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void CTextFileStreamObj_GetCurFile(int param_1,int *param_2)

{
  wchar_t *pwVar1;
  void *pvVar2;
  int iVar3;
  int **ppiVar4;
  uint uStack_98;
  int *local_88 [4];
  int local_78;
  char local_71;
  IMalloc *local_48 [3];
  CControlBar local_3c [28];
  int local_20;
  HRESULT local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001d547;
  local_10 = ExceptionList;
  ppiVar4 = local_88;
  for (iVar3 = 0x1d; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppiVar4 = (int *)0xcccccccc;
    ppiVar4 = ppiVar4 + 1;
  }
  uStack_98 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  ExceptionList = &local_10;
  local_1c = 0;
  local_8 = 0;
  local_18 = uStack_98;
  FUN_10013350(L"*.txt");
  local_8._0_1_ = 1;
  local_88[0] = FUN_10013740(&local_78,"");
  local_8._0_1_ = 2;
  local_88[1] = local_88[0];
  local_71 = FUN_10013ea0((void *)(param_1 + 0x44),local_88[0]);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10013b90(&local_78);
  if (local_71 != '\0') {
    pwVar1 = (wchar_t *)FUN_10013f70((int *)(param_1 + 0x44));
    FUN_10013cd0(local_3c,pwVar1);
  }
  iVar3 = FUN_10016680((int)local_3c);
  local_20 = iVar3 * 2 + 4;
  local_1c = CoGetMalloc(1,local_48);
  if (local_1c < 0) {
    assertFailure((uchar *)"TextFileStreamObj.cpp");
  }
  pvVar2 = (*local_48[0]->lpVtbl->Alloc)(local_48[0],local_20 + 2);
  *param_2 = (int)pvVar2;
  if (*param_2 == 0) {
    assertFailure((uchar *)"TextFileStreamObj.cpp");
  }
  else {
    pwVar1 = (wchar_t *)FUN_10015620((undefined4 *)local_3c);
    wcscpy((wchar_t *)*param_2,pwVar1);
  }
  local_8 = local_8 & 0xffffff00;
  CControlBar::OnInitialUpdate(local_3c);
  FUN_10012400();
  return;
}



// Function: Catch@10012347 at 10012347

undefined * Catch_10012347(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x50),"TextFileStreamObj.cpp",0x2ce,
                       "CTextFileStreamObj::GetCurFile",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x78) = uVar2;
  return &DAT_10012417;
}



// Function: Catch@10012393 at 10012393

undefined * Catch_10012393(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x68),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x68),"TextFileStreamObj.cpp",0x2ce,
                       "CTextFileStreamObj::GetCurFile",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x7c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x100123f4;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x68));
  return &DAT_10012409;
}



// Function: FUN_10012400 at 10012400

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012400(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012464);
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1001244f;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CTextFileStreamObj_Load2 at 100124c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_Load2(int param_1,wchar_t *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_60;
  undefined4 local_50 [12];
  CComBSTR local_20 [8];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001d57f;
  local_10 = ExceptionList;
  puVar3 = local_50;
  for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_60 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 0;
  ATL::CComBSTR::CComBSTR(local_20,param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = FUN_10009ee0((undefined4 *)local_20);
  if (iVar2 == 0) {
    local_18 = (**(code **)(*(int *)(param_1 + -8) + 0x14))(param_1 + -8,0,param_3);
  }
  else {
    uVar1 = FUN_10003e70((undefined4 *)local_20);
    local_18 = (**(code **)(*(int *)(param_1 + -8) + 0x14))(param_1 + -8,uVar1,param_3);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_10001000((undefined4 *)local_20);
  uVar4 = FUN_10012640(extraout_ECX,extraout_EDX);
  return uVar4;
}



// Function: Catch@10012587 at 10012587

undefined * Catch_10012587(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x28),"TextFileStreamObj.cpp",0x30c,
                       "CTextFileStreamObj::Load",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar2;
  return &DAT_10012657;
}



// Function: Catch@100125d3 at 100125d3

undefined * Catch_100125d3(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x40),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x40),"TextFileStreamObj.cpp",0x30c,
                       "CTextFileStreamObj::Load",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x4c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10012634;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return &DAT_10012649;
}



// Function: FUN_10012640 at 10012640

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10012640(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012698);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_100126e0 at 100126e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_100126e0(int param_1,wchar_t *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uStack_60;
  undefined4 local_50 [12];
  CComBSTR local_20 [8];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001d5aa;
  local_10 = ExceptionList;
  puVar3 = local_50;
  for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uStack_60 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 0;
  ATL::CComBSTR::CComBSTR(local_20,param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = FUN_10009ee0((undefined4 *)local_20);
  if (iVar2 == 0) {
    local_18 = (**(code **)(*(int *)(param_1 + -8) + 0x18))(param_1 + -8,0,param_3);
  }
  else {
    uVar1 = FUN_10003e70((undefined4 *)local_20);
    local_18 = (**(code **)(*(int *)(param_1 + -8) + 0x18))(param_1 + -8,uVar1,param_3);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_10001000((undefined4 *)local_20);
  uVar4 = FUN_10012860(extraout_ECX,extraout_EDX);
  return uVar4;
}



// Function: Catch@100127a7 at 100127a7

undefined * Catch_100127a7(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x28),"TextFileStreamObj.cpp",0x324,
                       "CTextFileStreamObj::Save",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar2;
  return &DAT_10012877;
}



// Function: Catch@100127f3 at 100127f3

undefined * Catch_100127f3(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x40),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x40),"TextFileStreamObj.cpp",0x324,
                       "CTextFileStreamObj::Save",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x4c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x10012854;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return &DAT_10012869;
}



// Function: FUN_10012860 at 10012860

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10012860(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_100128b8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: CTextFileStreamObj_get_CurrentFileName at 10012900

undefined4 CTextFileStreamObj_get_CurrentFileName(void)

{
  return 0x80004001;
}



// Function: CTextFileStreamObj_get_CurrentFileName at 10012910

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 CTextFileStreamObj_get_CurrentFileName(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  undefined8 uVar3;
  uint uStack_54;
  undefined4 local_44 [11];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d5cd;
  local_10 = ExceptionList;
  puVar2 = local_44;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_54 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 0;
  uVar3 = (**(code **)(*(int *)(param_1 + -8) + 0x20))(param_1 + -8,param_2);
  local_18 = (undefined4)uVar3;
  uVar3 = FUN_10012a39(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
  return uVar3;
}



// Function: Catch@10012980 at 10012980

undefined * Catch_10012980(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"TextFileStreamObj.cpp",0x334,
                       "CTextFileStreamObj::get_CurrentFileName",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
  return &DAT_10012a50;
}



// Function: Catch@100129cc at 100129cc

undefined * Catch_100129cc(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x34),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10014360();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x34),"TextFileStreamObj.cpp",0x334,
                       "CTextFileStreamObj::get_CurrentFileName",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10012a2d;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return &DAT_10012a42;
}



// Function: FUN_10012a39 at 10012a39

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __fastcall FUN_10012a39(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10012a90);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT44(param_2,uVar1);
}



// Function: FUN_10012ac0 at 10012ac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10012ac0(uint param_1)

{
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x7fffffff < param_1 || (local_8 = operator_new(param_1 << 1), local_8 == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  return local_8;
}



// Function: FUN_10012b20 at 10012b20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_10012b20(undefined1 *param_1,FILE *param_2)

{
  int iVar1;
  undefined1 local_8;
  
  iVar1 = fgetc(param_2);
  if (iVar1 != -1) {
    local_8 = (undefined1)iVar1;
    *param_1 = local_8;
  }
  return iVar1 != -1;
}



// Function: FUN_10012b70 at 10012b70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_10012b70(char param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = fputc((int)param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_10012bc0 at 10012bc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __cdecl FUN_10012bc0(byte *param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = ungetc((uint)*param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_10012c10 at 10012c10

undefined4 __cdecl FUN_10012c10(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10012c20 at 10012c20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10012c20(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10012db0(param_2);
  FUN_10012d10(this,param_1,uVar1);
  return;
}



// Function: FUN_10012c60 at 10012c60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012c60(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d601;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10003bb0(4,param_1);
  local_8 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_10012db0(param_2);
    *puVar1 = *puVar2;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10012d10 at 10012d10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10012d10(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10012db0(param_3);
  FUN_10012c60(param_2,uVar1);
  return;
}



// Function: FUN_10012d40 at 10012d40

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012d40(void)

{
  FUN_10012d90();
  return;
}



// Function: FUN_10012d70 at 10012d70

void FUN_10012d70(void)

{
  return;
}



// Function: FUN_10012d90 at 10012d90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10012d90(void)

{
  FUN_10012d70();
  return;
}



// Function: FUN_10012db0 at 10012db0

undefined4 __cdecl FUN_10012db0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10012dc0 at 10012dc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __cdecl FUN_10012dc0(locale *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  facet **ppfVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  facet *local_44;
  bad_cast local_40 [12];
  facet *local_34;
  facet *local_30;
  uint local_2c;
  facet *local_24 [3];
  _Lockit local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d632;
  local_10 = ExceptionList;
  ppfVar4 = &local_44;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *ppfVar4 = (facet *)0xcccccccc;
    ppfVar4 = ppfVar4 + 1;
  }
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_18,0);
  uVar6 = 0x10012e0a;
  local_8 = 0;
  local_24[0] = (facet *)DAT_10029920;
  local_2c = std::locale::id::operator_unsigned_int((id *)id_exref);
  uVar5 = 0x10012e2e;
  local_30 = (facet *)FUN_10014c00(param_1,local_2c);
  if (local_30 == (facet *)0x0) {
    if (local_24[0] == (facet *)0x0) {
      uVar2 = std::codecvt<char,char,int>::_Getcat(local_24,param_1);
      if (uVar2 == 0xffffffff) {
        std::bad_cast::bad_cast(local_40,"bad cast");
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_40,(ThrowInfo *)&DAT_10026720);
      }
      local_30 = local_24[0];
      DAT_10029920 = (int *)local_24[0];
      local_34 = local_24[0];
      (**(code **)(*(int *)local_24[0] + 4))(0x10012e73,uVar5,uVar6,uVar1);
      Facet_Register(local_34);
    }
    else {
      local_30 = local_24[0];
    }
  }
  local_44 = local_30;
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_18);
  uVar5 = extraout_EDX;
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10012f24);
  ExceptionList = local_10;
  return CONCAT44(uVar5,local_44);
}



// Function: FUN_10012f60 at 10012f60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10012f60(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  FUN_10014430((undefined4 *)this);
  return (undefined4 *)this;
}



// Function: FUN_10012fa0 at 10012fa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10012fa0(IUnknown *param_1)

{
  FID_conflict_IOleInPlaceObject(param_1);
  return param_1;
}



// Function: FUN_10012fd0 at 10012fd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __fastcall FUN_10012fd0(int param_1)

{
  FUN_10013080(param_1);
  return param_1;
}



// Function: FUN_10013000 at 10013000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10013000(void *this,undefined4 param_1)

{
  FUN_10014540();
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10013040 at 10013040

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10013040(void *this,undefined4 param_1)

{
  FUN_10013000(this,param_1);
  return this;
}



// Function: FUN_10013080 at 10013080

int __fastcall FUN_10013080(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_100130b0 at 100130b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_100130b0(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: IUnknown at 100130e0

/* Library Function - Single Match
    public: __thiscall IUnknown::IUnknown(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

IUnknown * __thiscall IUnknown::IUnknown(IUnknown *this)

{
  return this;
}



// Function: FUN_10013100 at 10013100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10013100(void *this,char **param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d662;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  local_8 = 0;
  *(undefined ***)this = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  FUN_10014d80(this,param_1,0);
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10013190 at 10013190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

basic_iostream<char,struct_std::char_traits<char>_> * __thiscall
FUN_10013190(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d6c6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    *(undefined ***)this = &PTR_10020df8;
    *(undefined **)((int)this + 0x10) = &DAT_10020e00;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + 0x78));
    local_8 = 0;
  }
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)this,
             (basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18));
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_fstream<char,struct_std::char_traits<char>_>::vftable;
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  *(int *)((int)this + *(int *)(*this + 4) + -4) = *(int *)(*this + 4) + -0x78;
  FUN_10013100((void *)((int)this + 0x18),(char **)0x0);
  ExceptionList = local_10;
  return (basic_iostream<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_100132a0 at 100132a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_100132a0(uint param_1,char param_2)

{
  undefined1 local_c [4];
  void *local_8;
  
  local_c = (undefined1  [4])0xcccccccc;
  IUnknown::IUnknown((IUnknown *)(local_c + 3));
  FUN_10002410((int)local_8);
  FUN_1000f140(local_8,'\0',0);
  FUN_10015380(local_8,param_1,param_2);
  return local_8;
}



// Function: FUN_10013300 at 10013300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_10013300(void)

{
  undefined1 local_c [4];
  void *local_8;
  
  local_c = (undefined1  [4])0xcccccccc;
  IUnknown::IUnknown((IUnknown *)(local_c + 3));
  FUN_10002410((int)local_8);
  FUN_1000f140(local_8,'\0',0);
  return local_8;
}



// Function: FUN_10013350 at 10013350

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * FUN_10013350(wchar_t *param_1)

{
  undefined1 local_c [4];
  void *local_8;
  
  local_c = (undefined1  [4])0xcccccccc;
  IUnknown::IUnknown((IUnknown *)(local_c + 3));
  FUN_10012fd0((int)local_8);
  FUN_10015110(local_8,'\0',0);
  FUN_100154c0(local_8,param_1);
  return local_8;
}



// Function: FUN_100133b0 at 100133b0

undefined4 * __thiscall
FUN_100133b0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 0x10) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100133f0 at 100133f0

undefined4 * __thiscall FUN_100133f0(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  return (undefined4 *)this;
}



// Function: FUN_10013430 at 10013430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LPCRITICAL_SECTION __fastcall FUN_10013430(LPCRITICAL_SECTION param_1)

{
  HRESULT HVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d6f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CComCriticalSection::CComCriticalSection((CComCriticalSection *)param_1);
  local_8 = 0;
  HVar1 = FUN_10009720(param_1);
  if (HVar1 < 0) {
    FUN_10007680(HVar1);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: CComBSTR at 100134c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(wchar_t const *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,wchar_t *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    uVar2 = Ordinal_2(param_1);
    *(undefined4 *)this = uVar2;
    bVar1 = operator!(this);
    if (bVar1) {
      FUN_10007680(0x8007000e);
    }
  }
  return this;
}



// Function: FUN_10013530 at 10013530

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10013530(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return (undefined4 *)this;
}



// Function: FUN_10013580 at 10013580

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10013580(void *this,int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = Ordinal_2(param_1);
  *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
  if ((*this == 0) && (param_1 != 0)) {
    _com_issue_error(-0x7ff8fff2);
  }
  return (int *)this;
}



// Function: FID_conflict:IOleInPlaceObject at 100135f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall IOleContainer::IOleContainer(void)
    public: __thiscall IOleInPlaceObject::IOleInPlaceObject(void)
    public: __thiscall IOleInPlaceSite::IOleInPlaceSite(void)
    public: __thiscall IOleInPlaceSiteEx::IOleInPlaceSiteEx(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

IUnknown * __fastcall FID_conflict_IOleInPlaceObject(IUnknown *param_1)

{
  FID_conflict_IOleUILinkContainerA(param_1);
  return param_1;
}



// Function: FID_conflict:IOleUILinkContainerA at 10013620

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall IClassFactory::IClassFactory(void)
    public: __thiscall IConnectionPointContainer::IConnectionPointContainer(void)
    public: __thiscall IDispatch::IDispatch(void)
    public: __thiscall IOleUILinkContainerA::IOleUILinkContainerA(void)
     12 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

IUnknown * __fastcall FID_conflict_IOleUILinkContainerA(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: FID_conflict:IOleUILinkContainerA at 10013650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall IClassFactory::IClassFactory(void)
    public: __thiscall IConnectionPointContainer::IConnectionPointContainer(void)
    public: __thiscall IDispatch::IDispatch(void)
    public: __thiscall IOleUILinkContainerA::IOleUILinkContainerA(void)
     12 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

IUnknown * __fastcall FID_conflict_IOleUILinkContainerA(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: FUN_10013680 at 10013680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10013680(IUnknown *param_1)

{
  FID_conflict_IOleUILinkContainerA(param_1);
  return param_1;
}



// Function: FID_conflict:IOleUILinkContainerA at 100136b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall IClassFactory::IClassFactory(void)
    public: __thiscall IConnectionPointContainer::IConnectionPointContainer(void)
    public: __thiscall IDispatch::IDispatch(void)
    public: __thiscall IOleUILinkContainerA::IOleUILinkContainerA(void)
     12 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

IUnknown * __fastcall FID_conflict_IOleUILinkContainerA(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: FUN_100136e0 at 100136e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_100136e0(IUnknown *param_1)

{
  FID_conflict_IOleUILinkContainerA(param_1);
  return param_1;
}



// Function: FUN_10013710 at 10013710

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * __fastcall FUN_10013710(IUnknown *param_1)

{
  IUnknown::IUnknown(param_1);
  return param_1;
}



// Function: FUN_10013740 at 10013740

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10013740(void *this,LPCSTR param_1)

{
  void *this_00;
  undefined4 *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d72b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = (void *)FUN_10013cb0(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_20 = (undefined4 *)0x0;
  }
  else {
    local_20 = FUN_10013530(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(undefined4 **)this = local_20;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_100137f0 at 100137f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_100137f0(void *this,int param_1)

{
  void *this_00;
  int *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d75b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = (void *)FUN_10013cb0(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_20 = (int *)0x0;
  }
  else {
    local_20 = FUN_10013580(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(int **)this = local_20;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_100138a0 at 100138a0

undefined4 * __fastcall FUN_100138a0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: _com_error at 100138c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(long,struct IErrorInfo *,bool)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug, Visual Studio 2012 Debug */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(undefined ***)this = vftable;
  *(long *)(this + 4) = param_1;
  *(IErrorInfo **)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  if ((*(int *)(this + 8) != 0) && (param_3)) {
    (**(code **)(**(int **)(this + 8) + 4))(*(undefined4 *)(this + 8));
  }
  return this;
}



// Function: FUN_10013940 at 10013940

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013940(undefined4 *param_1)

{
  FUN_100144f0(param_1);
  return;
}



// Function: FUN_10013970 at 10013970

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013970(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d792;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  local_8 = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_10015000(param_1);
  }
  if (param_1[0x4c] != (basic_streambuf<char,struct_std::char_traits<char>_>)0x0) {
    FUN_10015650((int *)param_1);
  }
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013a10 at 10013a10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013a10(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d7d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(param_1 + -0x78 + *(int *)(*(int *)(param_1 + -0x78) + 4)) =
       std::basic_fstream<char,struct_std::char_traits<char>_>::vftable;
  *(int *)(param_1 + -0x7c + *(int *)(*(int *)(param_1 + -0x78) + 4)) =
       *(int *)(*(int *)(param_1 + -0x78) + 4) + -0x78;
  local_8 = 0;
  FUN_10013970((basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + -0x60));
  local_8 = 0xffffffff;
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)(param_1 + -0x58));
  ExceptionList = local_10;
  return;
}



// Function: OnInitialUpdate at 10013ac0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: void __thiscall CControlBar::OnInitialUpdate(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

void __thiscall CControlBar::OnInitialUpdate(CControlBar *this)

{
  FUN_10015110(this,'\x01',0);
  return;
}



// Function: FID_conflict:~CPaneContainerGC at 10013af0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CAtlComModule::~CAtlComModule(void)
    public: __thiscall CPaneContainerGC::~CPaneContainerGC(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__CPaneContainerGC(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d7f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000d6c0(param_1);
  local_8 = 0xffffffff;
  ATL::CComCriticalSection::~CComCriticalSection((CComCriticalSection *)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~COleControlSiteFactory at 10013b60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall Microsoft::WRL::Module<5,class
   Platform::Details::InProcModule>::~Module<5,class Platform::Details::InProcModule>(void)
    public: virtual __thiscall Gdiplus::Bitmap::~Bitmap(void)
    public: virtual __thiscall CArchivePropExchange::~CArchivePropExchange(void)
    public: __thiscall CMapStringToString::CAssoc::~CAssoc(void)
     13 names - too many to list
   
   Library: Visual Studio 2012 Debug */

void __fastcall FID_conflict__COleControlSiteFactory(int *param_1)

{
  FUN_10014b10(param_1);
  return;
}



// Function: FUN_10013b90 at 10013b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013b90(int *param_1)

{
  FUN_10014b90(param_1);
  return;
}



// Function: ~_com_error at 10013bc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual __thiscall _com_error::~_com_error(void)
   
   Libraries: Visual Studio 2010 Debug, Visual Studio 2012 Debug */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  *(undefined ***)this = vftable;
  if (*(int *)(this + 8) != 0) {
    (**(code **)(**(int **)(this + 8) + 8))(*(undefined4 *)(this + 8));
  }
  if (*(int *)(this + 0xc) != 0) {
    LocalFree(*(HLOCAL *)(this + 0xc));
  }
  return;
}



// Function: FUN_10013c30 at 10013c30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10013c30(int *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0xcccccccc;
  if ((*param_1 != 0) &&
     (puVar1 = (undefined4 *)(**(code **)(*(int *)*param_1 + 8))(), puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1,0x10013c6d,uVar2);
  }
  return;
}



// Function: FUN_10013cb0 at 10013cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10013cb0(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_10013cd0 at 10013cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10013cd0(void *this,wchar_t *param_1)

{
  FUN_100154c0(this,param_1);
  return;
}



// Function: FUN_10013d00 at 10013d00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10013d00(void *this,LPCSTR param_1)

{
  LPCSTR pCVar1;
  void *this_00;
  undefined4 *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d82b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 != (LPCSTR)0x0) && (pCVar1 = (LPCSTR)FUN_10013fc0((int *)this), pCVar1 == param_1)) {
    ExceptionList = local_10;
    return (int *)this;
  }
  FUN_10014b90((int *)this);
  this_00 = (void *)FUN_10013cb0(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_20 = (undefined4 *)0x0;
  }
  else {
    local_20 = FUN_10013530(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(undefined4 **)this = local_20;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10013dd0 at 10013dd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __thiscall FUN_10013dd0(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  int *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d85b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 != 0) && (iVar1 = FUN_10014010((int *)this), iVar1 == param_1)) {
    ExceptionList = local_10;
    return (int *)this;
  }
  FUN_10014b90((int *)this);
  this_00 = (void *)FUN_10013cb0(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_20 = (int *)0x0;
  }
  else {
    local_20 = FUN_10013580(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(int **)this = local_20;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10013ea0 at 10013ea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __thiscall FUN_10013ea0(void *this,int *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_100145c0(this,param_1);
  return uVar1 != 0;
}



// Function: FUN_10013ef0 at 10013ef0

undefined8 __fastcall FUN_10013ef0(uint *param_1)

{
  return CONCAT44(param_1[1] + param_1[3] + (uint)CARRY4(*param_1,param_1[2]),*param_1 + param_1[2])
  ;
}



// Function: FUN_10013f20 at 10013f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10013f20(int *param_1)

{
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_10014370((undefined4 *)*param_1);
  }
  return local_c;
}



// Function: FUN_10013f70 at 10013f70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10013f70(int *param_1)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_100143b0(*param_1);
    local_c = *puVar1;
  }
  return local_c;
}



// Function: FUN_10013fc0 at 10013fc0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10013fc0(int *param_1)

{
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_10014370((undefined4 *)*param_1);
  }
  return local_c;
}



// Function: FUN_10014010 at 10014010

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10014010(int *param_1)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_100143b0(*param_1);
    local_c = *puVar1;
  }
  return local_c;
}



// Function: FUN_10014060 at 10014060

undefined4 __fastcall FUN_10014060(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014080 at 10014080

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014080(undefined4 *param_1)

{
  FUN_10014060(param_1);
  return;
}



// Function: FUN_100140b0 at 100140b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100140b0(int param_1)

{
  FUN_10013a10(param_1 + 0x78);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(param_1 + 0x78));
  return;
}



// Function: FUN_100140ee at 100140ee

void __thiscall FUN_100140ee(void *this,uint param_1)

{
  FUN_10014140((void *)((int)this - *(int *)((int)this + -4)),param_1);
  return;
}



// Function: FUN_10014100 at 10014100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10014100(void *this,uint param_1)

{
  FUN_10013970((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10014140 at 10014140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10014140(void *this,uint param_1)

{
  FUN_100140b0((int)this + -0x78);
  if ((param_1 & 1) != 0) {
    operator_delete((void *)((int)this + -0x78));
  }
  return (int)this + -0x78;
}



// Function: FID_conflict:`scalar_deleting_destructor' at 10014190

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall Microsoft::WRL::Module<5,class
   Platform::Details::InProcModule>::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall Gdiplus::Bitmap::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall CArchivePropExchange::`scalar deleting destructor'(unsigned
   int)
    public: void * __thiscall CMapStringToString::CAssoc::`scalar deleting destructor'(unsigned int)
     14 names - too many to list
   
   Library: Visual Studio 2012 Debug */

int * __thiscall FID_conflict__scalar_deleting_destructor_(void *this,uint param_1)

{
  FID_conflict__COleControlSiteFactory((int *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: `scalar_deleting_destructor' at 100141d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2010 Debug, Visual Studio 2012 Debug */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  ~_com_error(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10014210 at 10014210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_10014210(void *this,undefined4 *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint local_38 [7];
  ushort *local_1c;
  ushort *local_18;
  uint local_14;
  uint local_c;
  undefined4 *local_8;
  
  puVar5 = local_38;
  for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
                    /* WARNING: Load size is inaccurate */
  local_8 = (undefined4 *)this;
  local_c = Ordinal_7(*this);
  uVar3 = Ordinal_7(*param_1,0x10014241);
  local_14 = local_c;
  if (uVar3 < local_c) {
    local_14 = uVar3;
  }
  puVar1 = (ushort *)*param_1;
  puVar2 = (ushort *)*local_8;
  do {
    local_18 = puVar2;
    local_1c = puVar1;
    if (local_14 == 0) {
      if (local_c < uVar3) {
        return 0xffffffff;
      }
      local_38[0] = (uint)(local_c != uVar3);
      return local_38[0];
    }
    puVar1 = local_1c + 1;
    puVar2 = local_18 + 1;
    local_14 = local_14 - 1;
  } while (*local_18 == *local_1c);
  return (uint)*local_18 - (uint)*local_1c;
}



// Function: FUN_10014360 at 10014360

undefined4 * FUN_10014360(void)

{
  return &DAT_1001f9bc;
}



// Function: FUN_10014370 at 10014370

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10014370(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (param_1[1] == 0) {
    pCVar1 = ConvertBSTRToString((LPCWSTR)*param_1);
    param_1[1] = pCVar1;
  }
  return param_1[1];
}



// Function: FUN_100143b0 at 100143b0

undefined4 __fastcall FUN_100143b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100143d0 at 100143d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_100143d0(int *param_1)

{
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = Ordinal_7(*param_1);
  }
  return local_c;
}



// Function: FUN_10014430 at 10014430

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014430(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) == '\0') {
    FUN_1000a2a0((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}



// Function: FUN_10014470 at 10014470

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

LONG __fastcall FUN_10014470(void *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)((int)param_1 + 8));
  if ((LVar1 == 0) && (param_1 != (void *)0x0)) {
    FID_conflict__scalar_deleting_destructor_(param_1,1);
  }
  return LVar1;
}



// Function: FUN_100144f0 at 100144f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100144f0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_1000d850((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10014528 at 10014528

void __fastcall FUN_10014528(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1001452e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<char,struct_std::char_traits<char>_>::_Add_vtordisp1
            ((basic_istream<char,struct_std::char_traits<char>_> *)
             ((param_1 - *(int *)(param_1 + -4)) + -0x60));
  return;
}



// Function: FUN_10014534 at 10014534

void __fastcall FUN_10014534(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1001453a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<char,struct_std::char_traits<char>_>::_Add_vtordisp2
            ((basic_ostream<char,struct_std::char_traits<char>_> *)
             ((param_1 - *(int *)(param_1 + -4)) + -0x60));
  return;
}



// Function: FUN_10014540 at 10014540

void FUN_10014540(void)

{
  return;
}



// Function: FUN_10014560 at 10014560

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10014560(void *this,int param_1,size_t param_2,char param_3)

{
  undefined4 *puVar1;
  char cVar2;
  char *pcVar3;
  
  if (param_2 == 1) {
    pcVar3 = &param_3;
    puVar1 = FUN_1000f0a0((undefined4 *)this);
    FUN_1000f4a0((undefined1 *)((int)puVar1 + param_1),pcVar3);
  }
  else {
    cVar2 = param_3;
    puVar1 = FUN_1000f0a0((undefined4 *)this);
    FUN_10015590((void *)((int)puVar1 + param_1),param_2,cVar2);
  }
  return;
}



// Function: FUN_100145c0 at 100145c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_100145c0(void *this,int *param_1)

{
  uint uVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == *param_1) {
    uVar1 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*this == 0) {
      iVar2 = FUN_10015a10(param_1);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else if (*param_1 == 0) {
      iVar2 = FUN_10015a10((int *)this);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar1 = FUN_10014210(*this,(undefined4 *)*param_1);
    }
  }
  return uVar1;
}



// Function: FUN_10014640 at 10014640

undefined8 FUN_10014640(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uStack_3c;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d880;
  local_10 = ExceptionList;
  local_2c = (undefined1  [4])0xcccccccc;
  local_28 = 0xcccccccc;
  local_24 = 0xcccccccc;
  local_20 = 0xcccccccc;
  uStack_3c = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_1c = param_1 | 7;
  uVar1 = FUN_10015ad0();
  if (uVar1 < local_1c) {
    local_1c = param_1;
  }
  else if (local_1c / 3 < *(uint *)(local_18 + 0x14) >> 1) {
    iVar2 = FUN_10015ad0();
    if (iVar2 - (*(uint *)(local_18 + 0x14) >> 1) < *(uint *)(local_18 + 0x14)) {
      local_1c = FUN_10015ad0();
    }
    else {
      local_1c = (*(uint *)(local_18 + 0x14) >> 1) + *(int *)(local_18 + 0x14);
    }
  }
  local_8 = 0;
  uVar1 = local_1c + 1;
  FUN_10014bd0((IUnknown *)(local_2c + 3));
  local_24 = FUN_10015290(uVar1);
  uVar3 = FUN_10014779();
  return uVar3;
}



// Function: Catch@1001471c at 1001471c

void Catch_1001471c(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = *(int *)(unaff_EBP + -0x18) + 1;
  FUN_10014bd0((IUnknown *)(unaff_EBP + -0x26));
  uVar2 = FUN_10015290(uVar1);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
  FUN_10014763();
  return;
}



// Function: Catch@10014748 at 10014748

void Catch_10014748(void)

{
  int unaff_EBP;
  
  FUN_10015110(*(void **)(unaff_EBP + -0x14),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10014763 at 10014763

undefined * FUN_10014763(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10014782;
}



// Function: FUN_10014779 at 10014779

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10014779(void)

{
  undefined4 *puVar1;
  IUnknown *this;
  int unaff_EBP;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    iVar4 = *(int *)(unaff_EBP + 0xc);
    puVar1 = FUN_10014f60(*(undefined4 **)(unaff_EBP + -0x14));
    FUN_10015730(*(void **)(unaff_EBP + -0x20),puVar1,iVar4);
  }
  FUN_10015110(*(void **)(unaff_EBP + -0x14),'\x01',0);
  iVar4 = unaff_EBP + -0x20;
  uVar3 = *(undefined4 *)(unaff_EBP + -0x14);
  this = FUN_10014bd0((IUnknown *)(unaff_EBP + -0x27));
  FUN_10012c20(this,uVar3,iVar4);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  uVar2 = FUN_10014ab0(*(void **)(unaff_EBP + -0x14),*(int *)(unaff_EBP + 0xc));
  _RTC_CheckStackVars(unaff_EBP,(int *)&DAT_10014814);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_10014830 at 10014830

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014830(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  void *_Str;
  int iVar7;
  size_t sVar8;
  int *piVar9;
  char *pcVar10;
  size_t _Size;
  FILE *_File;
  char **ppcVar11;
  int local_6c;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  int local_54;
  int local_50;
  size_t local_4c;
  CControlBar local_44 [32];
  char *local_24 [2];
  undefined4 local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d8a8;
  local_10 = ExceptionList;
  piVar9 = &local_6c;
  for (iVar7 = 0x17; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = -0x33333334;
    piVar9 = piVar9 + 1;
  }
  uVar2 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  local_14 = uVar2;
  if ((param_1[0x10] != 0) && (*(char *)((int)param_1 + 0x45) != '\0')) {
    local_1c = 8;
    uVar3 = FUN_100157e0();
    local_50 = (**(code **)(*local_18 + 0xc))(uVar3,uVar2);
    local_54 = FUN_100157e0();
    bVar1 = FUN_100157f0(&local_54,&local_50);
    if (!bVar1) {
      FUN_100132a0(8,'\0');
      local_8 = 0;
      while( true ) {
        ppcVar11 = local_24;
        puVar4 = (undefined4 *)FUN_100155e0(local_44,local_58);
        iVar7 = FUN_10014080(puVar4);
        iVar5 = FUN_1000fcc0((int)local_44);
        pcVar10 = (char *)(iVar7 + iVar5);
        puVar4 = (undefined4 *)FUN_100155e0(local_44,local_5c);
        pcVar6 = (char *)FUN_10014080(puVar4);
        local_6c = std::codecvt<char,char,int>::unshift
                             ((codecvt<char,char,int> *)local_18[0x10],local_18 + 0x12,pcVar6,
                              pcVar10,ppcVar11);
        if (local_6c == 0) {
          *(undefined1 *)((int)local_18 + 0x45) = 0;
        }
        else if (local_6c != 1) {
          if (local_6c == 3) {
            local_67 = 1;
            local_8 = 0xffffffff;
            CControlBar::OnInitialUpdate(local_44);
          }
          else {
            local_68 = 0;
            local_8 = 0xffffffff;
            CControlBar::OnInitialUpdate(local_44);
          }
          goto LAB_10014a4e;
        }
        puVar4 = (undefined4 *)FUN_100155e0(local_44,local_60);
        iVar7 = FUN_10014080(puVar4);
        sVar8 = (int)local_24[0] - iVar7;
        local_4c = sVar8;
        if (sVar8 != 0) {
          _File = (FILE *)local_18[0x14];
          _Size = 1;
          puVar4 = (undefined4 *)FUN_100155e0(local_44,local_64);
          _Str = (void *)FUN_10014080(puVar4);
          sVar8 = fwrite(_Str,_Size,sVar8,_File);
          if (local_4c != sVar8) {
            local_65 = 0;
            local_8 = 0xffffffff;
            CControlBar::OnInitialUpdate(local_44);
            goto LAB_10014a4e;
          }
        }
        if (*(char *)((int)local_18 + 0x45) == '\0') break;
        if (local_4c == 0) {
          FUN_100152f0(local_44,8,'\0');
        }
      }
      local_66 = 1;
      local_8 = 0xffffffff;
      CControlBar::OnInitialUpdate(local_44);
    }
  }
LAB_10014a4e:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10014a84);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10014ab0 at 10014ab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10014ab0(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  undefined4 local_c;
  void *local_8;
  
  local_c = 0xcccc;
  *(int *)((int)this + 0x10) = param_1;
  puVar2 = (undefined2 *)((int)&local_c + 2);
  local_8 = this;
  puVar1 = FUN_10014f60((undefined4 *)this);
  FUN_100155c0((undefined2 *)((int)puVar1 + param_1 * 2),puVar2);
  return;
}



// Function: FUN_10014b10 at 10014b10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014b10(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    operator_delete__((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}



// Function: FUN_10014b90 at 10014b90

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014b90(int *param_1)

{
  if (*param_1 != 0) {
    FUN_10014470((void *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10014bd0 at 10014bd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

IUnknown * FUN_10014bd0(IUnknown *param_1)

{
  FUN_100130b0(param_1);
  return param_1;
}



// Function: FUN_10014c00 at 10014c00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int __thiscall FUN_10014c00(void *this,uint param_1)

{
  _Locimp *p_Var1;
  int local_18;
  int local_14;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 < *(uint *)(*this + 0xc)) {
                    /* WARNING: Load size is inaccurate */
    local_14 = *(int *)(*(int *)(*this + 8) + param_1 * 4);
  }
  else {
    local_14 = 0;
  }
  local_18 = local_14;
                    /* WARNING: Load size is inaccurate */
  if ((local_14 == 0) && (*(char *)(*this + 0x14) != '\0')) {
    p_Var1 = std::locale::_Getgloballocale();
    if (param_1 < *(uint *)(p_Var1 + 0xc)) {
      local_18 = *(int *)(*(int *)(p_Var1 + 8) + param_1 * 4);
    }
    else {
      local_18 = 0;
    }
  }
  return local_18;
}



// Function: FUN_10014cb0 at 10014cb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

bool __thiscall FUN_10014cb0(void *this,uint param_1,char param_2)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = FUN_10015ad0();
  if (uVar1 < param_1) {
    FUN_10015210();
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10014640(param_1);
  }
  else if ((param_2 == '\0') || (7 < param_1)) {
    if (param_1 == 0) {
      FUN_10014ab0(this,0);
    }
  }
  else {
    if (param_1 < *(uint *)((int)this + 0x10)) {
      local_c = param_1;
    }
    else {
      local_c = *(uint *)((int)this + 0x10);
    }
    FUN_10015110(this,'\x01',local_c);
  }
  return param_1 != 0;
}



// Function: FUN_10014d80 at 10014d80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10014d80(void *this,char **param_1,int param_2)

{
  *(bool *)((int)this + 0x4c) = param_2 == 1;
  *(undefined1 *)((int)this + 0x45) = 0;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (param_1 != (char **)0x0) {
    std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,param_1 + 2,param_1,
               (int *)(param_1 + 1),param_1 + 2,param_1,(int *)(param_1 + 1));
  }
  *(char ***)((int)this + 0x50) = param_1;
  *(undefined4 *)((int)this + 0x48) = DAT_1002991c;
  *(undefined4 *)((int)this + 0x40) = 0;
  return;
}



// Function: FUN_10014e70 at 10014e70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10014e70(void *this,codecvt_base *param_1)

{
  bool bVar1;
  
  bVar1 = std::codecvt_base::always_noconv(param_1);
  if (bVar1) {
    *(undefined4 *)((int)this + 0x40) = 0;
  }
  else {
    *(codecvt_base **)((int)this + 0x40) = param_1;
    std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  }
  return;
}



// Function: FUN_10014ed0 at 10014ed0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __thiscall FUN_10014ed0(void *this,undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (in_EAX = FUN_10014f60((undefined4 *)this), in_EAX <= param_1)) {
    puVar1 = FUN_10014f60((undefined4 *)this);
    in_EAX = (undefined4 *)((int)puVar1 + *(int *)((int)this + 0x10) * 2);
    if (param_1 < in_EAX) {
      return CONCAT31((int3)((uint)in_EAX >> 8),1);
    }
  }
  return (uint)in_EAX & 0xffffff00;
}



// Function: FUN_10014f20 at 10014f20

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10014f20(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    _lock_file(*(FILE **)(param_1 + 0x50));
  }
  return;
}



// Function: FUN_10014f60 at 10014f60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10014f60(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = (undefined4 *)FUN_10012c10(*param_1);
  }
  return local_c;
}



// Function: FUN_10014fb0 at 10014fb0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __fastcall FUN_10014fb0(undefined4 *param_1)

{
  undefined4 *local_c;
  
  local_c = param_1;
  if (7 < (uint)param_1[5]) {
    local_c = (undefined4 *)FUN_10012c10(*param_1);
  }
  return local_c;
}



// Function: FUN_10015000 at 10015000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10015000(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = (basic_streambuf<char,struct_std::char_traits<char>_> *)
           std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
  if (pbVar1 == param_1 + 0x44) {
    std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
              (param_1,*(char **)(param_1 + 0x38),*(char **)(param_1 + 0x3c),
               *(char **)(param_1 + 0x3c));
  }
  return;
}



// Function: FUN_10015070 at 10015070

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10015070(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  char *pcVar2;
  
  pbVar1 = (basic_streambuf<char,struct_std::char_traits<char>_> *)
           std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
  if (pbVar1 != param_1 + 0x44) {
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    *(char **)(param_1 + 0x38) = pcVar2;
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
    *(char **)(param_1 + 0x3c) = pcVar2;
  }
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
            (param_1,(char *)(param_1 + 0x44),(char *)(param_1 + 0x44),(char *)(param_1 + 0x45));
  return;
}



// Function: FUN_10015110 at 10015110

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10015110(void *this,char param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  undefined1 local_10 [3];
  undefined1 uStack_d;
  void *local_c;
  void *local_8;
  
  _local_10 = 0xcccccccc;
  local_c = (void *)0xcccccccc;
  local_8 = this;
  if ((param_1 != '\0') && (7 < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    local_c = *this;
    FUN_10014bd0((IUnknown *)(local_10 + 3));
    FUN_10012d40();
    if (param_2 != 0) {
      iVar2 = param_2;
      pvVar1 = (void *)FUN_10012c10(local_c);
      FUN_10015730(local_8,pvVar1,iVar2);
    }
    pvVar1 = local_c;
    FUN_10014bd0((IUnknown *)(local_10 + 2));
    FUN_10015780(pvVar1);
  }
  *(undefined4 *)((int)local_8 + 0x14) = 7;
  FUN_10014ab0(local_8,param_2);
  return;
}



// Function: FUN_100151d0 at 100151d0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100151d0(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    _unlock_file(*(FILE **)(param_1 + 0x50));
  }
  return;
}



// Function: FUN_10015210 at 10015210

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015210(void)

{
  std::_Xlength_error("string too long");
  return;
}



// Function: FUN_10015250 at 10015250

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015250(void)

{
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: FUN_10015290 at 10015290

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015290(uint param_1)

{
  FUN_100152c0(param_1);
  return;
}



// Function: FUN_100152c0 at 100152c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100152c0(uint param_1)

{
  FUN_10012ac0(param_1);
  return;
}



// Function: FUN_100152f0 at 100152f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100152f0(void *this,uint param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (-*(int *)((int)this + 0x10) - 1U <= param_1) {
    FUN_1000f200();
  }
  if (param_1 != 0) {
    uVar2 = *(int *)((int)this + 0x10) + param_1;
    bVar1 = FUN_1000ef00(this,uVar2,'\0');
    if (bVar1) {
      FUN_10014560(this,*(int *)((int)this + 0x10),param_1,param_2);
      FUN_1000ee60(this,uVar2);
    }
  }
  return this;
}



// Function: FUN_10015380 at 10015380

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10015380(void *this,uint param_1,char param_2)

{
  bool bVar1;
  
  if (param_1 == 0xffffffff) {
    FUN_1000f200();
  }
  bVar1 = FUN_1000ef00(this,param_1,'\0');
  if (bVar1) {
    FUN_10014560(this,0,param_1,param_2);
    FUN_1000ee60(this,param_1);
  }
  return this;
}



// Function: FUN_100153f0 at 100153f0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_100153f0(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 local_c;
  
  uVar2 = FUN_10016680((int)param_1);
  if (uVar2 < param_2) {
    FUN_10015250();
  }
  iVar3 = FUN_10016680((int)param_1);
  local_c = iVar3 - param_2;
  if (param_3 < local_c) {
    local_c = param_3;
  }
  if ((undefined4 *)this == param_1) {
    FUN_10015820(this,param_2 + local_c);
    FUN_10015860(this,0,param_2);
  }
  else {
    bVar1 = FUN_10014cb0(this,local_c,'\0');
    if (bVar1) {
      uVar2 = local_c;
      puVar4 = FUN_10014fb0(param_1);
      pvVar5 = (void *)((int)puVar4 + param_2 * 2);
      puVar4 = FUN_10014f60((undefined4 *)this);
      FUN_10015730(puVar4,pvVar5,uVar2);
      FUN_10014ab0(this,local_c);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_100154c0 at 100154c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_100154c0(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = FUN_100159c0(param_1);
  FUN_10015500(this,(undefined4 *)param_1,sVar1);
  return;
}



// Function: FUN_10015500 at 10015500

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10015500(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_10014ed0(this,param_1);
  if ((uVar2 & 0xff) == 0) {
    bVar1 = FUN_10014cb0(this,param_2,'\0');
    if (bVar1) {
      uVar2 = param_2;
      puVar3 = FUN_10014f60((undefined4 *)this);
      FUN_10015730(puVar3,param_1,uVar2);
      FUN_10014ab0(this,param_2);
    }
  }
  else {
    puVar3 = FUN_10014f60((undefined4 *)this);
    this = FUN_100153f0(this,(undefined4 *)this,(int)param_1 - (int)puVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10015590 at 10015590

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10015590(void *param_1,size_t param_2,char param_3)

{
  memset(param_1,(int)param_3,param_2);
  return;
}



// Function: FUN_100155c0 at 100155c0

void __cdecl FUN_100155c0(undefined2 *param_1,undefined2 *param_2)

{
  *param_1 = *param_2;
  return;
}



// Function: FUN_100155e0 at 100155e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100155e0(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_1000f0a0((undefined4 *)this);
  FUN_10013040(param_1,puVar1);
  return param_1;
}



// Function: FUN_10015620 at 10015620

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10015620(undefined4 *param_1)

{
  FUN_10014fb0(param_1);
  return;
}



// Function: FUN_10015650 at 10015650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int * __fastcall FUN_10015650(int *param_1)

{
  char cVar1;
  int iVar2;
  int *local_c;
  
  if (param_1[0x14] == 0) {
    local_c = (int *)0x0;
  }
  else {
    cVar1 = FUN_10014830(param_1);
    local_c = param_1;
    if (cVar1 == '\0') {
      local_c = (int *)0x0;
    }
    iVar2 = fclose((FILE *)param_1[0x14]);
    if (iVar2 != 0) {
      local_c = (int *)0x0;
    }
  }
  FUN_10014d80(param_1,(char **)0x0,2);
  return local_c;
}



// Function: FUN_100156e0 at 100156e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_100156e0(int *param_1)

{
  int *piVar1;
  
  piVar1 = FUN_10015650(param_1 + 6);
  if (piVar1 == (int *)0x0) {
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               ((int)param_1 + *(int *)(*param_1 + 4)),2,false);
  }
  return;
}



// Function: FUN_10015730 at 10015730

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10015730(void *param_1,void *param_2,int param_3)

{
  undefined4 local_8;
  
  if (param_3 == 0) {
    local_8 = param_1;
  }
  else {
    local_8 = (void *)FUN_10016ca0(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_10015780 at 10015780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015780(void *param_1)

{
  FUN_100157b0(param_1);
  return;
}



// Function: FUN_100157b0 at 100157b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_100157b0(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_100157e0 at 100157e0

undefined4 FUN_100157e0(void)

{
  return 0xffffffff;
}



// Function: FUN_100157f0 at 100157f0

bool __cdecl FUN_100157f0(int *param_1,int *param_2)

{
  return *param_1 == *param_2;
}



// Function: FUN_10015820 at 10015820

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_10015820(void *this,uint param_1)

{
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_10015250();
  }
  FUN_10014ab0(this,param_1);
  return this;
}



// Function: FUN_10015860 at 10015860

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 * __thiscall FUN_10015860(void *this,uint param_1,uint param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_10015250();
  }
  if (param_2 < *(int *)((int)this + 0x10) - param_1) {
    if (param_2 != 0) {
      puVar2 = FUN_10014f60((undefined4 *)this);
      pvVar1 = (void *)((int)puVar2 + param_1 * 2);
      iVar3 = *(int *)((int)this + 0x10) - param_2;
      FUN_10015b30(pvVar1,(void *)((int)pvVar1 + param_2 * 2),iVar3 - param_1);
      FUN_10014ab0(this,iVar3);
    }
  }
  else {
    FUN_10014ab0(this,param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10015910 at 10015910

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10015910(void *this,locale *param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10012dc0(param_1);
  FUN_10014e70(this,(codecvt_base *)uVar1);
  return;
}



// Function: FUN_10015950 at 10015950

bool __fastcall FUN_10015950(int param_1)

{
  return *(int *)(param_1 + 0x50) != 0;
}



// Function: GetCount at 10015990

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */
/* Library Function - Single Match
    public: unsigned long __thiscall CPropertySection::GetCount(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

ulong __thiscall CPropertySection::GetCount(CPropertySection *this)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_10015950((int)(this + 0x18));
  return CONCAT31(extraout_var,bVar1);
}



// Function: FUN_100159c0 at 100159c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

size_t __cdecl FUN_100159c0(wchar_t *param_1)

{
  undefined4 local_8;
  
  if (*param_1 == L'\0') {
    local_8 = 0;
  }
  else {
    local_8 = wcslen(param_1);
  }
  return local_8;
}



// Function: FUN_10015a10 at 10015a10

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_10015a10(int *param_1)

{
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_100143d0((int *)*param_1);
  }
  return local_c;
}



// Function: FUN_10015a60 at 10015a60

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015a60(void)

{
  FUN_10015ab0();
  return;
}



// Function: FUN_10015a90 at 10015a90

undefined4 FUN_10015a90(void)

{
  return 0x7fffffff;
}



// Function: FUN_10015ab0 at 10015ab0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015ab0(void)

{
  FUN_10015a90();
  return;
}



// Function: FUN_10015ad0 at 10015ad0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

int FUN_10015ad0(void)

{
  uint uVar1;
  int local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  local_10 = (undefined1  [4])0xcccccccc;
  local_c = 0xcccccccc;
  FUN_10014bd0((IUnknown *)(local_10 + 3));
  uVar1 = FUN_10015a60();
  if (uVar1 < 2) {
    local_14 = 1;
  }
  else {
    local_14 = uVar1 - 1;
  }
  return local_14;
}



// Function: FUN_10015b30 at 10015b30

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __cdecl FUN_10015b30(void *param_1,void *param_2,int param_3)

{
  undefined4 local_8;
  
  if (param_3 == 0) {
    local_8 = param_1;
  }
  else {
    local_8 = (void *)FUN_10016cd0(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_10015b80 at 10015b80

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

uint __cdecl FUN_10015b80(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint local_c;
  uint local_8;
  
  uVar1 = FUN_100157e0();
  if (*param_1 == uVar1) {
    iVar2 = FUN_100157e0();
    local_c = (uint)(iVar2 == 0);
    local_8 = local_c;
  }
  else {
    local_8 = *param_1;
  }
  return local_8;
}



// Function: FUN_10015be0 at 10015be0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10015be0(void *this,ushort *param_1,int param_2,int param_3)

{
  locale *plVar1;
  undefined8 uVar2;
  int local_1c;
  _iobuf *local_18;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d8d8;
  local_10 = ExceptionList;
  local_1c = -0x33333334;
  local_18 = (_iobuf *)0xcccccccc;
  ExceptionList = &local_10;
  if ((*(int *)((int)this + 0x50) == 0) &&
     (local_14 = (basic_streambuf<char,struct_std::char_traits<char>_> *)this,
     local_18 = std::_Fiopen(param_1,param_2,param_3), local_18 != (_iobuf *)0x0)) {
    FUN_10014d80(local_14,&local_18->_ptr,1);
    plVar1 = (locale *)std::basic_streambuf<char,struct_std::char_traits<char>_>::getloc(local_14);
    local_8 = 0;
    uVar2 = FUN_10012dc0(plVar1);
    FUN_10014e70(local_14,(codecvt_base *)uVar2);
    local_8 = 0xffffffff;
    FUN_10013c30(&local_1c);
    ExceptionList = local_10;
    return local_14;
  }
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
}



// Function: FUN_10015cd0 at 10015cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __thiscall FUN_10015cd0(void *this,ushort *param_1,int param_2,int param_3)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = FUN_10015be0((void *)((int)this + 0x18),param_1,param_2,param_3);
  if (pbVar1 == (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
                    /* WARNING: Load size is inaccurate */
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + *(int *)(*this + 4)),2
               ,false);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    std::basic_ios<char,struct_std::char_traits<char>_>::clear
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + *(int *)(*this + 4)),0
               ,false);
  }
  return;
}



// Function: FUN_10015d50 at 10015d50

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_10015d50(uint param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  void *_Str;
  uint uVar7;
  int iVar8;
  size_t sVar9;
  uint *puVar10;
  size_t _Size;
  FILE *pFVar11;
  char **ppcVar12;
  uint local_98 [4];
  uint local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined1 local_78 [4];
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  int local_68;
  size_t local_64;
  CControlBar local_5c [32];
  char *local_3c [3];
  char *local_30 [3];
  char local_21;
  char local_20 [4];
  undefined4 local_1c;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d908;
  local_10 = ExceptionList;
  puVar10 = local_98;
  for (iVar8 = 0x22; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar10 = 0xcccccccc;
    puVar10 = puVar10 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_68 = FUN_100157e0();
  bVar1 = FUN_100157f0(&local_68,(int *)&param_1);
  if (bVar1) {
    FUN_10015b80(&param_1);
  }
  else {
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_18);
    if (pcVar3 != (char *)0x0) {
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_18);
      pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(local_18);
      if (pcVar3 < pcVar4) {
        cVar2 = FUN_10016770((undefined1 *)&param_1);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc(local_18);
        *pcVar3 = cVar2;
        goto LAB_100160c8;
      }
    }
    if (*(int *)(local_18 + 0x50) == 0) {
      FUN_100157e0();
    }
    else {
      FUN_10015000(local_18);
      if (*(int *)(local_18 + 0x40) == 0) {
        pFVar11 = *(FILE **)(local_18 + 0x50);
        cVar2 = FUN_10016770((undefined1 *)&param_1);
        bVar1 = FUN_10012b70(cVar2,pFVar11);
        if (bVar1) {
          local_98[2] = param_1;
        }
        else {
          local_98[2] = FUN_100157e0();
        }
      }
      else {
        local_1c = 8;
        local_21 = FUN_10016770((undefined1 *)&param_1);
        FUN_100132a0(8,'\0');
        local_8 = 0;
        while( true ) {
          ppcVar12 = local_3c;
          puVar5 = (undefined4 *)FUN_100155e0(local_5c,local_6c);
          iVar8 = FUN_10014080(puVar5);
          iVar6 = FUN_1000fcc0((int)local_5c);
          pcVar4 = (char *)(iVar8 + iVar6);
          puVar5 = (undefined4 *)FUN_100155e0(local_5c,local_70);
          pcVar3 = (char *)FUN_10014080(puVar5);
          local_98[1] = std::codecvt<char,char,int>::out
                                  (*(codecvt<char,char,int> **)(local_18 + 0x40),
                                   (int *)(local_18 + 0x48),&local_21,local_20,local_30,pcVar3,
                                   pcVar4,ppcVar12);
          if ((int)local_98[1] < 0) break;
          if (1 < (int)local_98[1]) {
            if (local_98[1] == 3) {
              bVar1 = FUN_10012b70(local_21,*(FILE **)(local_18 + 0x50));
              if (bVar1) {
                local_98[0] = param_1;
              }
              else {
                local_98[0] = FUN_100157e0();
              }
              local_88 = local_98[0];
              local_8 = 0xffffffff;
              CControlBar::OnInitialUpdate(local_5c);
              goto LAB_100160c8;
            }
            break;
          }
          puVar5 = (undefined4 *)FUN_100155e0(local_5c,local_74);
          iVar8 = FUN_10014080(puVar5);
          sVar9 = (int)local_3c[0] - iVar8;
          local_64 = sVar9;
          if (sVar9 != 0) {
            pFVar11 = *(FILE **)(local_18 + 0x50);
            _Size = 1;
            puVar5 = (undefined4 *)FUN_100155e0(local_5c,local_78);
            _Str = (void *)FUN_10014080(puVar5);
            sVar9 = fwrite(_Str,_Size,sVar9,pFVar11);
            if (local_64 != sVar9) {
              local_7c = FUN_100157e0();
              local_8 = 0xffffffff;
              CControlBar::OnInitialUpdate(local_5c);
              goto LAB_100160c8;
            }
          }
          local_18[0x45] = (basic_streambuf<char,struct_std::char_traits<char>_>)0x1;
          if (local_30[0] != &local_21) {
            local_80 = param_1;
            local_8 = 0xffffffff;
            CControlBar::OnInitialUpdate(local_5c);
            goto LAB_100160c8;
          }
          if (local_64 == 0) {
            uVar7 = FUN_1000fcc0((int)local_5c);
            if (0x1f < uVar7) {
              local_84 = FUN_100157e0();
              local_8 = 0xffffffff;
              CControlBar::OnInitialUpdate(local_5c);
              goto LAB_100160c8;
            }
            FUN_100152f0(local_5c,8,'\0');
          }
        }
        local_98[3] = FUN_100157e0();
        local_8 = 0xffffffff;
        CControlBar::OnInitialUpdate(local_5c);
      }
    }
  }
LAB_100160c8:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016104);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016300 at 10016300

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 __thiscall FUN_10016300(void *this,void *param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_14 = 0xcccccccc;
  local_10 = 0xcccccccc;
  local_c = 0xcccccccc;
  local_8 = (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
  pbVar2 = (basic_streambuf<char,struct_std::char_traits<char>_> *)
           std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  iVar5 = 0x10016330;
  if (((pbVar2 == local_8 + 0x44) && (param_4 == 1)) && (*(int *)(local_8 + 0x40) == 0)) {
    bVar4 = param_2 == 0;
    param_2 = param_2 + -1;
    param_3 = param_3 - (uint)bVar4;
  }
  if (*(int *)(local_8 + 0x50) != 0) {
    cVar1 = FUN_10014830((int *)local_8);
    if (cVar1 != '\0') {
      if ((param_2 != 0 || param_3 != 0) || (param_4 != 1)) {
        iVar5 = _fseeki64(*(FILE **)(local_8 + 0x50),CONCAT44(param_4,param_3),iVar5);
        if (iVar5 != 0) goto LAB_100163cb;
      }
      iVar5 = fgetpos(*(FILE **)(local_8 + 0x50),(fpos_t *)&local_14);
      if (iVar5 == 0) {
        FUN_10015000(local_8);
        FUN_100133b0(param_1,*(int *)(local_8 + 0x48),local_14,local_10);
        uVar3 = extraout_EDX_00;
        goto LAB_10016407;
      }
    }
  }
LAB_100163cb:
  FUN_100133f0(param_1,*(undefined4 *)_BADOFF_exref,*(undefined4 *)(_BADOFF_exref + 4));
  uVar3 = extraout_EDX;
LAB_10016407:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_1001642c);
  return CONCAT44(uVar3,param_1);
}



// Function: FUN_10016450 at 10016450

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined8 FUN_10016450(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  longlong lVar4;
  undefined8 local_14;
  undefined4 local_c;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_14 = -0x3333333333333334;
  local_c = 0xcccccccc;
  local_14 = FUN_100165c0((int)&stack0x00000008);
  lVar4 = FUN_10013ef0((uint *)&stack0x00000008);
  lVar4 = lVar4 - local_14;
  if (*(int *)(local_8 + 0x50) != 0) {
    cVar1 = FUN_10014830((int *)local_8);
    if (cVar1 != '\0') {
      iVar2 = fsetpos(*(FILE **)(local_8 + 0x50),&local_14);
      if (iVar2 == 0) {
        if (lVar4 != 0) {
          iVar2 = _fseeki64(*(FILE **)(local_8 + 0x50),CONCAT44(1,(int)((ulonglong)lVar4 >> 0x20)),
                            0x100164cf);
          if (iVar2 != 0) goto LAB_10016523;
        }
        iVar2 = fgetpos(*(FILE **)(local_8 + 0x50),&local_14);
        if (iVar2 == 0) {
          uVar3 = FUN_100166a0((int)&stack0x00000008);
          *(undefined4 *)(local_8 + 0x48) = uVar3;
          FUN_10015000(local_8);
          FUN_100133b0(param_1,*(undefined4 *)(local_8 + 0x48),(undefined4)local_14,local_14._4_4_);
          uVar3 = extraout_EDX_00;
          goto LAB_1001656d;
        }
      }
    }
  }
LAB_10016523:
  FUN_100133f0(param_1,*(undefined4 *)_BADOFF_exref,*(undefined4 *)(_BADOFF_exref + 4));
  uVar3 = extraout_EDX;
LAB_1001656d:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016590);
  return CONCAT44(uVar3,param_1);
}



// Function: FUN_100165c0 at 100165c0

undefined8 __fastcall FUN_100165c0(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}



// Function: FUN_100165e0 at 100165e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void * __thiscall FUN_100165e0(void *this,char *param_1,size_t param_2,int param_3)

{
  int iVar1;
  int local_c;
  
  if (*(int *)((int)this + 0x50) != 0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0 && param_3 == 0)) {
      local_c = 4;
    }
    else {
      local_c = 0;
    }
    iVar1 = setvbuf(*(FILE **)((int)this + 0x50),param_1,local_c,param_2);
    if (iVar1 == 0) {
      FUN_10014d80(this,*(char ***)((int)this + 0x50),1);
      return this;
    }
  }
  return (void *)0x0;
}



// Function: FUN_10016680 at 10016680

undefined4 __fastcall FUN_10016680(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_100166a0 at 100166a0

undefined4 __fastcall FUN_100166a0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_100166c0 at 100166c0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

undefined4 __fastcall FUN_100166c0(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  int local_c;
  int *local_8;
  
  local_10 = -0x33333334;
  local_c = -0x33333334;
  if (param_1[0x14] != 0) {
    local_8 = param_1;
    uVar2 = FUN_100157e0();
    local_c = (**(code **)(*local_8 + 0xc))(uVar2);
    local_10 = FUN_100157e0();
    bVar1 = FUN_100157f0(&local_10,&local_c);
    if ((!bVar1) && (iVar3 = fflush((FILE *)local_8[0x14]), iVar3 < 0)) {
      return 0xffffffff;
    }
  }
  return 0;
}



// Function: FUN_10016770 at 10016770

undefined1 __cdecl FUN_10016770(undefined1 *param_1)

{
  return *param_1;
}



// Function: FUN_10016780 at 10016780

undefined1 __cdecl FUN_10016780(undefined1 *param_1)

{
  return *param_1;
}



// Function: FUN_10016790 at 10016790

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __fastcall FUN_10016790(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  bool bVar1;
  undefined1 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined3 extraout_var;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  undefined3 extraout_var_00;
  void *_Src;
  undefined3 extraout_var_01;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  char **ppcVar11;
  char **ppcVar12;
  rsize_t _MaxCount;
  int local_9c [4];
  undefined1 local_8c [4];
  undefined1 local_88 [4];
  undefined4 local_84;
  undefined1 local_80 [4];
  undefined1 local_7c [4];
  undefined1 local_78 [4];
  undefined4 local_74;
  int local_70;
  int local_6c;
  char *local_64 [3];
  char *local_58 [3];
  char local_49;
  char local_48 [8];
  CControlBar local_40 [35];
  undefined1 local_1d [5];
  basic_streambuf<char,struct_std::char_traits<char>_> *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d938;
  local_10 = ExceptionList;
  piVar9 = local_9c;
  for (iVar8 = 0x23; iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar9 = -0x33333334;
    piVar9 = piVar9 + 1;
  }
  local_14 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_18);
    pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(local_18);
    if (pcVar3 < pcVar4) {
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Gninc(local_18);
      FUN_10016780(pcVar3);
      goto LAB_10016aeb;
    }
  }
  if (*(int *)(local_18 + 0x50) == 0) {
    FUN_100157e0();
  }
  else {
    FUN_10015000(local_18);
    if (*(int *)(local_18 + 0x40) == 0) {
      local_1d[0] = 0;
      bVar1 = FUN_10012b20(local_1d,*(FILE **)(local_18 + 0x50));
      if (bVar1) {
        uVar2 = FUN_10016780(local_1d);
        local_9c[1] = CONCAT31(extraout_var,uVar2);
      }
      else {
        local_9c[1] = FUN_100157e0();
      }
    }
    else {
      FUN_10013300();
      local_8 = 0;
LAB_100168b6:
      do {
        local_70 = fgetc(*(FILE **)(local_18 + 0x50));
        if (local_70 == -1) {
          local_74 = FUN_100157e0();
          local_8 = 0xffffffff;
          CControlBar::OnInitialUpdate(local_40);
          goto LAB_10016aeb;
        }
        FUN_100152f0(local_40,1,(char)local_70);
        ppcVar12 = local_58;
        pcVar3 = local_48;
        pcVar4 = &local_49;
        ppcVar11 = local_64;
        puVar5 = (undefined4 *)FUN_100155e0(local_40,local_78);
        iVar8 = FUN_10014080(puVar5);
        iVar6 = FUN_1000fcc0((int)local_40);
        pcVar10 = (char *)(iVar8 + iVar6);
        puVar5 = (undefined4 *)FUN_100155e0(local_40,local_7c);
        pcVar7 = (char *)FUN_10014080(puVar5);
        local_9c[0] = std::codecvt<char,char,int>::in
                                (*(codecvt<char,char,int> **)(local_18 + 0x40),
                                 (int *)(local_18 + 0x48),pcVar7,pcVar10,ppcVar11,pcVar4,pcVar3,
                                 ppcVar12);
        _MaxCount = 0x10016966;
        if (local_9c[0] < 0) {
LAB_10016ab5:
          local_9c[2] = FUN_100157e0();
          local_8 = 0xffffffff;
          CControlBar::OnInitialUpdate(local_40);
          goto LAB_10016aeb;
        }
        if (local_9c[0] < 2) {
          if (local_58[0] != &local_49) {
            puVar5 = (undefined4 *)FUN_100155e0(local_40,local_80);
            iVar8 = FUN_10014080(puVar5);
            iVar6 = FUN_1000fcc0((int)local_40);
            local_6c = (iVar8 + iVar6) - (int)local_64[0];
            while (0 < local_6c) {
              local_6c = local_6c + -1;
              ungetc((int)local_64[0][local_6c],*(FILE **)(local_18 + 0x50));
            }
            uVar2 = FUN_10016780(&local_49);
            local_84 = CONCAT31(extraout_var_00,uVar2);
            local_8 = 0xffffffff;
            CControlBar::OnInitialUpdate(local_40);
            goto LAB_10016aeb;
          }
          puVar5 = (undefined4 *)FUN_100155e0(local_40,local_88);
          iVar8 = FUN_10014080(puVar5);
          FUN_1000f750(local_40,0,(int)local_64[0] - iVar8);
          goto LAB_100168b6;
        }
        if (local_9c[0] != 3) goto LAB_10016ab5;
        iVar8 = FUN_1000fcc0((int)local_40);
      } while (iVar8 == 0);
      puVar5 = (undefined4 *)FUN_100155e0(local_40,local_8c);
      _Src = (void *)FUN_10014080(puVar5);
      memcpy_s(&local_49,1,_Src,_MaxCount);
      uVar2 = FUN_10016780(&local_49);
      local_9c[3] = CONCAT31(extraout_var_01,uVar2);
      local_8 = 0xffffffff;
      CControlBar::OnInitialUpdate(local_40);
    }
  }
LAB_10016aeb:
  _RTC_CheckStackVars((int)&stack0xfffffffc,(int *)&DAT_10016b24);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016ca0 at 10016ca0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10016ca0(void *param_1,void *param_2,int param_3)

{
  memcpy(param_1,param_2,param_3 << 1);
  return;
}



// Function: FUN_10016cd0 at 10016cd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void __cdecl FUN_10016cd0(void *param_1,void *param_2,int param_3)

{
  memmove(param_1,param_2,param_3 << 1);
  return;
}



// Function: FUN_10016d00 at 10016d00

undefined4 * __thiscall FUN_10016d00(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d968;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_10016ee0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016d80 at 10016d80

int * __thiscall FUN_10016d80(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != param_1) {
    *(int **)this = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_10016db0 at 10016db0

int * __thiscall FUN_10016db0(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != param_1) {
    *(int **)this = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_10016de0 at 10016de0

void * __thiscall FUN_10016de0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_10016ee0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10016e60 at 10016e60

void * __thiscall FUN_10016e60(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001d9c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_10016fa0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10016ee0 at 10016ee0

int __thiscall FUN_10016ee0(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001d9f8;
  local_10 = ExceptionList;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar2 + 8))(piVar2,uVar1);
    }
    iVar3 = -0x7fffbffe;
  }
  else {
    piVar2 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar2 = extraout_EAX;
    }
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_1001f4e8,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    pvVar4 = (void *)0x0;
    if (-1 < iVar3) {
      pvVar4 = local_14;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(void **)this = pvVar4;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10016fa0 at 10016fa0

int __thiscall FUN_10016fa0(void *this,int *param_1)

{
  uint uVar1;
  int *extraout_EAX;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001da28;
  local_10 = ExceptionList;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)this = 0;
      (**(code **)(*piVar2 + 8))(piVar2,uVar1);
    }
    iVar3 = -0x7fffbffe;
  }
  else {
    piVar2 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar2 = extraout_EAX;
    }
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10020f00,&local_14);
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    pvVar4 = (void *)0x0;
    if (-1 < iVar3) {
      pvVar4 = local_14;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(void **)this = pvVar4;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10017060 at 10017060

undefined4 * __fastcall FUN_10017060(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100170b0 at 100170b0

undefined4 * __fastcall FUN_100170b0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10017120 at 10017120

undefined4 * __thiscall FUN_10017120(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  code *pcVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)this = 0;
  HVar2 = FUN_10018a80(this,param_1,param_2,param_3);
  if ((HVar2 < 0) && (HVar2 != -0x7fffbffe)) {
    _com_issue_error(HVar2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  return (undefined4 *)this;
}



// Function: FUN_10017160 at 10017160

int * __thiscall FUN_10017160(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_10017190 at 10017190

int * __thiscall FUN_10017190(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_100171b0 at 100171b0

undefined4 * __thiscall FUN_100171b0(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_100171f0 at 100171f0

int * __thiscall FUN_100171f0(void *this,int param_1)

{
  undefined **local_14;
  DWORD local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (param_1 == 0) {
    local_10 = GetLastError();
    if (0 < (int)local_10) {
      local_10 = local_10 & 0xffff | 0x80070000;
    }
    local_14 = _com_error::vftable;
    local_c = 0;
    local_8 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10026bb8);
  }
  return (int *)this;
}



// Function: FUN_10017250 at 10017250

int * __thiscall FUN_10017250(void *this,int param_1)

{
  undefined **local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (-1 < param_1) {
    return (int *)this;
  }
  local_10 = param_1;
  local_14 = _com_error::vftable;
  local_c = 0;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10026bb8);
}



// Function: FUN_10017290 at 10017290

int * __thiscall FUN_10017290(void *this,int param_1,char param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  if ((param_2 == '\0') || (param_1 == 0)) {
    *(int *)this = param_1;
  }
  else {
    uVar2 = Ordinal_149(param_1);
    iVar3 = Ordinal_150(param_1,uVar2);
    *(int *)this = iVar3;
    if (iVar3 == 0) {
      _com_issue_error(-0x7ff8fff2);
      pcVar1 = (code *)swi(3);
      piVar4 = (int *)(*pcVar1)();
      return piVar4;
    }
  }
  return (int *)this;
}



// Function: FUN_100172e0 at 100172e0

int * __thiscall FUN_100172e0(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  if (iVar1 != 0) {
    InterlockedIncrement((LONG *)(iVar1 + 8));
  }
  return (int *)this;
}



// Function: FUN_10017310 at 10017310

undefined4 * __thiscall FUN_10017310(void *this,int param_1,char param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dabb;
  local_10 = ExceptionList;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = (int *)operator_new(0xc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    if ((param_2 != '\0') && (param_1 != 0)) {
      uVar3 = Ordinal_149(param_1,uVar1);
      iVar4 = Ordinal_150(param_1,uVar3);
      *piVar2 = iVar4;
      if (iVar4 != 0) goto LAB_10017392;
      _com_issue_error(-0x7ff8fff2);
    }
    *piVar2 = param_1;
  }
LAB_10017392:
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: _com_error at 100173c0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Library: Visual Studio 2012 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: FUN_10017400 at 10017400

void __fastcall FUN_10017400(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dae8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10029830 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017450 at 10017450

void __fastcall FUN_10017450(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001db18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10029830 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100174a0 at 100174a0

void __fastcall FUN_100174a0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100174b0 at 100174b0

void __fastcall FUN_100174b0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100174c0 at 100174c0

void __fastcall FUN_100174c0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100174d0 at 100174d0

void __fastcall FUN_100174d0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100174e0 at 100174e0

void __fastcall FUN_100174e0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100174f0 at 100174f0

int * __thiscall FUN_100174f0(void *this,int param_1)

{
  undefined **local_14;
  DWORD local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (param_1 == 0) {
    local_10 = GetLastError();
    if (0 < (int)local_10) {
      local_10 = local_10 & 0xffff | 0x80070000;
    }
    local_14 = _com_error::vftable;
    local_c = 0;
    local_8 = 0;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10026bb8);
  }
  return (int *)this;
}



// Function: FUN_10017550 at 10017550

int * __thiscall FUN_10017550(void *this,int param_1)

{
  undefined **local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(int *)this = param_1;
  if (-1 < param_1) {
    return (int *)this;
  }
  local_10 = param_1;
  local_14 = _com_error::vftable;
  local_c = 0;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10026bb8);
}



// Function: FUN_10017590 at 10017590

int * __thiscall FUN_10017590(void *this,int *param_1)

{
  int iVar1;
  
  if ((int *)this != param_1) {
    FUN_10014b90((int *)this);
    iVar1 = *param_1;
    *(int *)this = iVar1;
    if (iVar1 != 0) {
      InterlockedIncrement((LONG *)(iVar1 + 8));
    }
  }
  return (int *)this;
}



// Function: FUN_100175c0 at 100175c0

uint __thiscall FUN_100175c0(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this == 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_100175e0 at 100175e0

uint __thiscall FUN_100175e0(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this == 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10017600 at 10017600

uint __thiscall FUN_10017600(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this != 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10017620 at 10017620

uint __thiscall FUN_10017620(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    return (uint)(*this != 0);
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10017670 at 10017670

undefined4 __fastcall FUN_10017670(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10017690 at 10017690

void __fastcall FUN_10017690(int *param_1)

{
  code *pcVar1;
  
  if (*param_1 != 0) {
    return;
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_10017710 at 10017710

int * __fastcall FUN_10017710(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10017730 at 10017730

int * __fastcall FUN_10017730(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10017750 at 10017750

ULONG __fastcall FUN_10017750(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[8].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10020e9c);
  }
  return UVar1;
}



// Function: FUN_10017790 at 10017790

void FUN_10017790(IID *param_1,LPCSTR param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_100177b0(param_1,param_2,0,(LPCSTR)0x0,param_3,param_4);
  return;
}



// Function: FUN_100177b0 at 100177b0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_100177b0(IID *param_1,LPCSTR param_2,int param_3,LPCSTR param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint uVar3;
  char cVar4;
  LPWSTR pWVar5;
  LPWSTR pWVar6;
  long lVar7;
  LPCSTR pCVar8;
  undefined4 *_Memory;
  uint local_30;
  char *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001db48;
  local_10 = ExceptionList;
  local_30 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_30;
  if (param_2 == (LPCSTR)0x0) goto LAB_10017926;
  _Memory = (undefined4 *)0x0;
  local_18 = (undefined4 *)0x0;
  local_8 = 0;
  pCVar8 = param_2;
  do {
    cVar4 = *pCVar8;
    pCVar8 = pCVar8 + 1;
  } while (cVar4 != '\0');
  pcVar1 = pCVar8 + (1 - (int)(param_2 + 1));
  uVar3 = (int)pcVar1 * 2;
  if ((((int)pcVar1 >> 0x1f) << 1 | (uint)pcVar1 >> 0x1f) + (uint)(0x7fffffff < uVar3) == 0) {
    if (((int)uVar3 < 0x401) && (cVar4 = FUN_1000eae0(uVar3), cVar4 != '\0')) {
      pWVar5 = (LPWSTR)&local_30;
    }
    else {
      pWVar5 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                       CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                 ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)&local_18,
                                  uVar3);
      _Memory = local_18;
    }
    pWVar5 = FUN_100058b0(pWVar5,param_2,(uint)pcVar1 & 0x7fffffff,3);
    if (pWVar5 != (LPWSTR)0x0) {
      pWVar6 = (LPWSTR)0x0;
      if (param_4 == (LPCSTR)0x0) {
LAB_100178e4:
        FUN_10017950(param_1,pWVar5,param_3,(int)pWVar6,param_5,param_6,(HINSTANCE)0x0);
      }
      else {
        pCVar8 = param_4;
        do {
          cVar4 = *pCVar8;
          pCVar8 = pCVar8 + 1;
        } while (cVar4 != '\0');
        local_1c = pCVar8 + (1 - (int)(param_4 + 1));
        lVar7 = ATL::AtlMultiply<int>((int *)&local_1c,(int)local_1c,2);
        pcVar1 = local_1c;
        if (-1 < lVar7) {
          if (((int)local_1c < 0x401) && (cVar4 = FUN_1000eae0((int)local_1c), cVar4 != '\0')) {
            pWVar6 = (LPWSTR)&local_30;
          }
          else {
            pWVar6 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                             CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                       ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)
                                        &local_18,(ulong)pcVar1);
            _Memory = local_18;
          }
          pWVar6 = FUN_100058b0(pWVar6,param_4,(uint)pcVar1 >> 1,3);
          if (pWVar6 != (LPWSTR)0x0) goto LAB_100178e4;
        }
      }
    }
  }
  local_8 = 0xffffffff;
  while (_Memory != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*_Memory;
    local_18 = puVar2;
    free(_Memory);
    _Memory = puVar2;
  }
LAB_10017926:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017950 at 10017950

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10017950(IID *param_1,LPWSTR param_2,int param_3,int param_4,undefined4 param_5,int param_6
                 ,HINSTANCE param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  errno_t eVar5;
  LPWSTR pWVar6;
  char *pcVar7;
  undefined4 *_Memory;
  uint local_440;
  LPOLESTR local_424;
  undefined4 *local_420;
  int *local_41c;
  int *local_418;
  CHAR local_414 [1024];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001dbbd;
  local_10 = ExceptionList;
  local_440 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Memory = (undefined4 *)0x0;
  local_420 = (undefined4 *)0x0;
  local_8 = 0;
  local_414[0] = '\0';
  local_14 = local_440;
  if (((uint)param_2 & 0xffff0000) == 0) {
    local_41c = (int *)((uint)param_2 & 0xffff);
    iVar4 = LoadStringA(param_7,(UINT)local_41c,local_414,0x400);
    if (iVar4 == 0) {
      eVar5 = strcpy_s(local_414,0x400,"Unknown Error");
      ATL::AtlCrtErrorCheck(eVar5);
    }
    pcVar7 = local_414;
    do {
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    pcVar7 = pcVar7 + (1 - (int)(local_414 + 1));
    uVar2 = (int)pcVar7 * 2;
    if ((((int)pcVar7 >> 0x1f) << 1 | (uint)pcVar7 >> 0x1f) + (uint)(0x7fffffff < uVar2) == 0) {
      if (((int)uVar2 < 0x401) && (cVar3 = FUN_1000eae0(uVar2), cVar3 != '\0')) {
        pWVar6 = (LPWSTR)&local_440;
      }
      else {
        pWVar6 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                   ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)
                                    &local_420,uVar2);
        _Memory = local_420;
      }
      param_2 = FUN_100058b0(pWVar6,local_414,(uint)pcVar7 & 0x7fffffff,3);
      if (param_2 != (LPWSTR)0x0) goto LAB_10017aaf;
    }
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
              ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)&local_420);
  }
  else {
LAB_10017aaf:
    local_418 = (int *)0x0;
    local_8._0_1_ = 2;
    iVar4 = Ordinal_202(&local_418);
    if (-1 < iVar4) {
      local_41c = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      (**(code **)(*local_418 + 0xc))(local_418,param_5);
      ProgIDFromCLSID(param_1,&local_424);
      if (local_424 != (LPOLESTR)0x0) {
        (**(code **)(*local_418 + 0x10))(local_418,local_424);
      }
      if ((param_3 != 0) && (param_4 != 0)) {
        (**(code **)(*local_418 + 0x1c))(local_418,param_3);
        (**(code **)(*local_418 + 0x18))(local_418,param_4);
      }
      CoTaskMemFree(local_424);
      (**(code **)(*local_418 + 0x14))(local_418,param_2);
      iVar4 = (**(code **)*local_418)(local_418,&DAT_1001f4e8,&local_41c);
      if (-1 < iVar4) {
        Ordinal_201(0,local_41c);
      }
      local_8._0_1_ = 2;
      if (local_41c != (int *)0x0) {
        (**(code **)(*local_41c + 8))(local_41c);
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_418 != (int *)0x0) {
      (**(code **)(*local_418 + 8))(local_418);
    }
    local_8 = 0xffffffff;
    while (_Memory != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*_Memory;
      local_420 = puVar1;
      free(_Memory);
      _Memory = puVar1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017c20 at 10017c20

void __thiscall FUN_10017c20(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(int *)this = param_1;
  return;
}



// Function: FUN_10017c40 at 10017c40

void __thiscall FUN_10017c40(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(int *)this = param_1;
  return;
}



// Function: throwExceptionWithFileInfo at 10017c60

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void throwExceptionWithFileInfo(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  int *piVar1;
  undefined1 *puVar2;
  LPSTR pCVar3;
  HRESULT HVar4;
  void *this;
  uint uStack_207c;
  LPUNKNOWN local_2054;
  undefined1 *local_2050;
  int *local_204c;
  undefined4 local_2048;
  undefined4 local_2044;
  undefined4 local_2040;
  void *local_203c;
  undefined8 local_2038;
  undefined8 local_2030;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dc7f;
  local_10 = ExceptionList;
  uStack_207c = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_207c;
  ExceptionList = &local_10;
  local_2044 = param_2;
  local_2048 = param_4;
  local_2038 = param_5;
  local_2030 = param_6;
  local_2040 = *(undefined4 *)((int)param_1 + 4);
  local_18 = uStack_207c;
  FUN_10018b10(param_1,&local_204c);
  piVar1 = local_204c;
  local_8 = 0;
  if ((local_204c != (int *)0x0) && (local_204c[1] == 0)) {
    pCVar3 = ConvertBSTRToString((LPCWSTR)*local_204c);
    piVar1[1] = (int)pCVar3;
  }
  local_203c = (void *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_10020ef0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001f428,&local_2054
                          );
  if (-1 < HVar4) {
    HVar4 = OleRun(local_2054);
    if (-1 < HVar4) {
      HVar4 = (*local_2054->lpVtbl->QueryInterface)(local_2054,(IID *)&DAT_10020eac,&local_203c);
    }
    (*local_2054->lpVtbl->Release)(local_2054);
    if (-1 < HVar4) goto LAB_10017d92;
  }
  local_203c = (void *)0x0;
  if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
    _com_issue_error(HVar4);
  }
LAB_10017d92:
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_2050 = &stack0xffffdf80;
  puVar2 = &stack0xffffdf80;
  if (local_204c != (int *)0x0) {
    InterlockedIncrement(local_204c + 2);
    puVar2 = local_2050;
  }
  local_2050 = puVar2;
  local_8._0_1_ = 3;
  this = (void *)FUN_10017690((int *)&local_203c);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10019080(this,local_204c);
  local_8 = 1;
  FUN_10017f25();
  return;
}



// Function: Catch@10017de5 at 10017de5

undefined * Catch_10017de5(void)

{
  IUnknown *extraout_ECX;
  int *extraout_ECX_00;
  void *extraout_ECX_01;
  void *extraout_ECX_02;
  IUnknown *extraout_ECX_03;
  int *extraout_ECX_04;
  void *extraout_ECX_05;
  void *pvVar1;
  IUnknown *extraout_ECX_06;
  IUnknown *pIVar2;
  int unaff_EBP;
  int *piVar3;
  
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX;
  }
  FUN_10017750(pIVar2);
  if (*(LPCSTR *)(unaff_EBP + -0x2058) == (LPCSTR)0x0) {
    *(undefined1 *)(unaff_EBP + -0x2014) = 0;
    piVar3 = (int *)0x1fff;
    memset((void *)(unaff_EBP + -0x2013),0,0x1fff);
    FUN_10018d70((ushort)*(undefined4 *)(unaff_EBP + -0x203c),(LPSTR)(unaff_EBP + -0x2014));
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    FUN_10013740(&stack0xfffffffc,(LPCSTR)(unaff_EBP + -0x2014));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_01;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10018e00(pvVar1,piVar3);
  }
  else {
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    piVar3 = extraout_ECX_00;
    FUN_10013740(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP + -0x2058));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_02;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_10018e00(pvVar1,piVar3);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_03;
  }
  FUN_10018ec0(pIVar2);
  *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
  piVar3 = extraout_ECX_04;
  FUN_10013740(&stack0xfffffffc,"");
  *(undefined1 *)(unaff_EBP + -4) = 7;
  pvVar1 = *(void **)(unaff_EBP + -0x2038);
  if (pvVar1 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar1 = extraout_ECX_05;
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_10018ef0(pvVar1,piVar3);
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_06;
  }
  FUN_10018fb0(pIVar2);
  return &DAT_10017f12;
}



// Function: FUN_10017f25 at 10017f25

/* WARNING: Removing unreachable block (ram,0x100181d2) */

void FUN_10017f25(void)

{
  int *piVar1;
  IUnknown *pIVar2;
  undefined4 *puVar3;
  uchar *puVar4;
  ULONG UVar5;
  int *extraout_EAX;
  int *piVar6;
  int *piVar7;
  LPSTR pCVar8;
  LPCSTR pCVar9;
  undefined4 uVar10;
  LONG LVar11;
  int *extraout_ECX;
  int *extraout_ECX_00;
  void *extraout_ECX_01;
  int *extraout_ECX_02;
  void *extraout_ECX_03;
  void *extraout_ECX_04;
  void *pvVar12;
  undefined4 uVar13;
  void *extraout_ECX_05;
  uchar *unaff_EBX;
  uint unaff_EBP;
  int unaff_EDI;
  undefined4 uStack00000004;
  
  *(undefined8 *)(unaff_EBP - 0x2024) = 0;
  *(undefined8 *)(unaff_EBP - 0x201c) = 0;
  if (*(int **)(unaff_EDI + 8) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EDI + 8) + 4))();
  }
  piVar1 = *(int **)(unaff_EDI + 8);
  *(int **)(unaff_EBP - 0x204c) = piVar1;
  *(undefined1 *)(unaff_EBP - 4) = 8;
  if (piVar1 != (int *)0x0) {
    if (piVar1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    (**(code **)(*piVar1 + 0xc))(piVar1);
  }
  puVar4 = _mbsrchr(unaff_EBX,0x2f);
  if (puVar4 == (uchar *)0x0) {
    puVar4 = _mbsrchr(unaff_EBX,0x5c);
  }
  else {
    puVar4 = puVar4 + 1;
  }
  if (puVar4 != (uchar *)0x0) {
    unaff_EBX = puVar4 + 1;
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[8].Release)(pIVar2);
  piVar7 = extraout_ECX;
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10020e9c);
    piVar7 = extraout_ECX_00;
  }
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  FUN_10013740(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 9;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_01;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_10018e00(pvVar12,piVar7);
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  piVar7 = extraout_ECX_02;
  FUN_10013740(&stack0xfffffffc,(LPCSTR)unaff_EBX);
  *(undefined1 *)(unaff_EBP - 4) = 10;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_03;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_10018ef0(pvVar12,piVar7);
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[4].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10020e9c);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  uVar10 = *(undefined4 *)(unaff_EBP - 0x203c);
  uVar13 = uVar10;
  UVar5 = (*pIVar2->lpVtbl[5].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10020e9c);
  }
  if (*(char *)(unaff_EBP + 0x28) != '\0') {
    *(undefined4 *)(unaff_EBP - 0x203c) = 0;
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 8))(piVar7,uVar13);
    }
    *(undefined4 *)(unaff_EBP - 0x203c) = 0;
    Ordinal_202(unaff_EBP - 0x203c);
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar7 = extraout_EAX;
    }
    (**(code **)(*piVar7 + 0xc))(piVar7,unaff_EBP - 0x2024);
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    pvVar12 = *(void **)(unaff_EBP - 0x2038);
    if (pvVar12 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar12 = extraout_ECX_04;
    }
    piVar6 = FUN_10018c50(pvVar12,(undefined4 *)(unaff_EBP - 0x2040));
    *(undefined1 *)(unaff_EBP - 4) = 0xc;
    if ((undefined4 *)*piVar6 == (undefined4 *)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined4 *)*piVar6;
    }
    (**(code **)(*piVar7 + 0x14))(piVar7,uVar13);
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    FUN_10013b90((int *)(unaff_EBP - 0x2040));
    FUN_10016d00((void *)(unaff_EBP - 0x2040),(int *)(unaff_EBP - 0x203c));
    *(undefined1 *)(unaff_EBP - 4) = 0xd;
    piVar7 = *(int **)(unaff_EBP - 0x2040);
    if (piVar7 != (int *)0x0) {
      if (piVar7 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      (**(code **)(*piVar7 + 4))(piVar7);
      *(undefined ***)(unaff_EBP - 0x2068) = _com_error::vftable;
      *(undefined4 *)(unaff_EBP - 0x2064) = uVar10;
      *(int **)(unaff_EBP - 0x2060) = piVar7;
      *(undefined4 *)(unaff_EBP - 0x205c) = 0;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException((void *)(unaff_EBP - 0x2068),(ThrowInfo *)&DAT_10026bb8);
    }
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    *(undefined1 *)(unaff_EBP - 4) = 8;
    piVar7 = *(int **)(unaff_EBP - 0x203c);
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 8))(piVar7);
    }
  }
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_05;
  }
  piVar7 = FUN_10018c50(pvVar12,(undefined4 *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 0xe;
  puVar3 = (undefined4 *)*piVar7;
  if (puVar3 == (undefined4 *)0x0) {
    pCVar9 = (LPCSTR)0x0;
  }
  else {
    if (puVar3[1] == 0) {
      pCVar8 = ConvertBSTRToString((LPCWSTR)*puVar3);
      puVar3[1] = pCVar8;
    }
    pCVar9 = (LPCSTR)puVar3[1];
  }
  uVar10 = FUN_100177b0((IID *)(unaff_EBP - 0x2034),pCVar9,0,(LPCSTR)0x0,unaff_EBP - 0x2024,uVar10);
  *(undefined4 *)(unaff_EBP - 0x2040) = uVar10;
  *(undefined1 *)(unaff_EBP - 4) = 8;
  piVar7 = *(int **)(unaff_EBP - 0x2044);
  if (piVar7 != (int *)0x0) {
    LVar11 = InterlockedDecrement(piVar7 + 2);
    if ((LVar11 == 0) && (piVar7 != (int *)0x0)) {
      if (*piVar7 != 0) {
        Ordinal_6(*piVar7);
        *piVar7 = 0;
      }
      if ((void *)piVar7[1] != (void *)0x0) {
        operator_delete((void *)piVar7[1]);
        piVar7[1] = 0;
      }
      operator_delete(piVar7);
    }
    *(undefined4 *)(unaff_EBP - 0x2044) = 0;
  }
  *(undefined1 *)(unaff_EBP - 4) = 1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP - 4) = 0;
  piVar1 = *(int **)(unaff_EBP - 0x2038);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP - 0x2048);
  if (piVar1 != (int *)0x0) {
    LVar11 = InterlockedDecrement(piVar1 + 2);
    if ((LVar11 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
        *piVar1 = 0;
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete((void *)piVar1[1]);
        piVar1[1] = 0;
      }
      operator_delete(piVar1);
    }
    *(undefined4 *)(unaff_EBP - 0x2048) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack00000004 = 0x10018347;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10018350 at 10018350

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_10018350(undefined4 param_1,uchar *param_2)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_10018590(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100183c0 at 100183c0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_100183c0(uchar *param_1)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_10018590(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: assertFailure at 10018430

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl assertFailure(uchar *param_1)

{
  char *in_stack_00000014;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000014,&stack0x00000018);
  FUN_10018590(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100184a0 at 100184a0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_100184a0(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_10018590(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018510 at 10018510

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_10018510(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_10018590(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018590 at 10018590

/* WARNING: Removing unreachable block (ram,0x1001875e) */

void __cdecl FUN_10018590(uchar *param_1)

{
  byte bVar1;
  IID *pIVar2;
  int *piVar3;
  void **ppvObject;
  HRESULT HVar4;
  uint uVar5;
  int *extraout_EAX;
  IUnknown *extraout_EAX_00;
  int iVar6;
  ULONG UVar7;
  uchar *puVar8;
  undefined4 **ppuVar9;
  IUnknown *extraout_EAX_01;
  IUnknown *pIVar10;
  int *extraout_EAX_02;
  int *extraout_EAX_03;
  int *piVar11;
  byte *pbVar12;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  IUnknown *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  IUnknown *extraout_ECX_07;
  IUnknown *extraout_ECX_08;
  undefined4 uVar13;
  undefined4 *puVar14;
  bool bVar15;
  int in_stack_00000014;
  byte *in_stack_00000018;
  undefined4 in_stack_00000020;
  LPCSTR in_stack_00000024;
  undefined **local_3c [2];
  int *local_34;
  undefined4 local_30;
  int *local_2c;
  undefined4 *local_28;
  IID *local_24;
  LPUNKNOWN local_20;
  int *local_1c;
  int *local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001dd03;
  local_10 = ExceptionList;
  ppvObject = (void **)(DAT_10029830 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 1;
  local_14 = (IUnknown *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_10020ef0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_1001f428,&local_20);
  if (HVar4 < 0) {
LAB_10018624:
    local_14 = (IUnknown *)0x0;
    if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
      _com_issue_error(HVar4);
    }
  }
  else {
    HVar4 = OleRun(local_20);
    if (-1 < HVar4) {
      HVar4 = (*local_20->lpVtbl->QueryInterface)(local_20,(IID *)&DAT_10020eac,&local_14);
    }
    (*local_20->lpVtbl->Release)(local_20);
    if (HVar4 < 0) goto LAB_10018624;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pbVar12 = PTR_s_APPEND_10029814;
  do {
    bVar1 = *in_stack_00000018;
    bVar15 = bVar1 < *pbVar12;
    if (bVar1 != *pbVar12) {
LAB_10018670:
      uVar5 = -(uint)bVar15 | 1;
      goto LAB_10018675;
    }
    if (bVar1 == 0) break;
    bVar1 = in_stack_00000018[1];
    bVar15 = bVar1 < pbVar12[1];
    if (bVar1 != pbVar12[1]) goto LAB_10018670;
    in_stack_00000018 = in_stack_00000018 + 2;
    pbVar12 = pbVar12 + 2;
  } while (bVar1 != 0);
  uVar5 = 0;
LAB_10018675:
  if (uVar5 == 0) {
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_18 = (int *)0x0;
    Ordinal_200(0);
    if (local_18 != (int *)0x0) {
      FUN_10016e60(&local_1c,(int *)&local_18);
      local_24 = (IID *)0x0;
      piVar11 = local_18;
      if (local_18 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
        piVar11 = extraout_EAX;
      }
      (**(code **)(*piVar11 + 0x14))(piVar11);
      pIVar2 = local_24;
      if (local_24 != (IID *)0x0) {
        local_2c = (int *)operator_new(0xc);
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        if (local_2c == (int *)0x0) {
          local_2c = (int *)0x0;
        }
        else {
          local_2c[1] = 0;
          local_2c[2] = 1;
          *local_2c = (int)pIVar2;
        }
        local_8._0_1_ = 2;
        if (local_2c == (int *)0x0) {
          _com_issue_error(-0x7ff8fff2);
        }
        local_8._0_1_ = 4;
        pIVar10 = local_14;
        if (local_14 == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
          pIVar10 = extraout_EAX_00;
        }
        (*pIVar10->lpVtbl[9].QueryInterface)(pIVar10,local_24,ppvObject);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10013b90((int *)&local_2c);
      }
    }
  }
  if (local_1c == (int *)0x0) {
    local_1c = (int *)0x0;
    Ordinal_202();
    local_2c = (int *)&stack0xffffffb4;
    piVar11 = local_1c;
    piVar3 = (int *)&stack0xffffffb4;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 4))(local_1c);
      piVar3 = local_2c;
    }
    local_2c = piVar3;
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
    iVar6 = FUN_10016ee0(&local_18,piVar11);
    if ((iVar6 < 0) && (iVar6 != -0x7fffbffe)) {
      _com_issue_error(iVar6);
    }
  }
  pIVar10 = local_14;
  if (local_1c == (int *)0x0) {
    local_8._0_1_ = 1;
    if (local_14 != (IUnknown *)0x0) {
      (*local_14->lpVtbl->Release)(local_14);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
    ExceptionList = local_10;
    return;
  }
  puVar14 = (undefined4 *)0x0;
  local_28 = (undefined4 *)0x0;
  local_8 = CONCAT31(local_8._1_3_,6);
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[8].Release)(pIVar10);
  piVar11 = extraout_ECX;
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10020e9c);
    piVar11 = extraout_ECX_00;
  }
  pIVar10 = local_14;
  if (in_stack_00000014 == 1) {
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
    piVar11 = extraout_ECX_02;
  }
  else {
    if (in_stack_00000014 != 2) {
      if (in_stack_00000014 != 3) goto LAB_1001886f;
      if (local_14 == (IUnknown *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
      if ((int)UVar7 < 0) {
        _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10020eac);
      }
    }
    pIVar10 = local_14;
    if (local_14 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar7 = (*pIVar10->lpVtbl[10].AddRef)(pIVar10);
    piVar11 = extraout_ECX_01;
  }
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10020eac);
    piVar11 = extraout_ECX_03;
  }
LAB_1001886f:
  local_2c = (int *)&stack0xffffffb4;
  FUN_10013740(&stack0xffffffb4,in_stack_00000024);
  local_8._0_1_ = 7;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_04;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10018e00(pIVar10,piVar11);
  puVar8 = _mbsrchr(param_1,0x2f);
  if (puVar8 == (uchar *)0x0) {
    puVar8 = _mbsrchr(param_1,0x5c);
    piVar11 = extraout_ECX_06;
  }
  else {
    puVar8 = puVar8 + 1;
    piVar11 = extraout_ECX_05;
  }
  if (puVar8 != (uchar *)0x0) {
    param_1 = puVar8 + 1;
  }
  local_2c = (int *)&stack0xffffffb4;
  FUN_10013740(&stack0xffffffb4,(LPCSTR)param_1);
  local_8._0_1_ = 8;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_07;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10018ef0(pIVar10,piVar11);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[4].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10020e9c);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[5].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10020e9c);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_08;
  }
  ppuVar9 = (undefined4 **)FUN_10018c50(pIVar10,&local_2c);
  local_8._0_1_ = 9;
  if (&local_28 != ppuVar9) {
    FUN_10014b90((int *)&local_28);
    puVar14 = *ppuVar9;
    local_28 = puVar14;
    if (puVar14 != (undefined4 *)0x0) {
      InterlockedIncrement(puVar14 + 2);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_10013b90((int *)&local_2c);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_EAX_01;
  }
  (*pIVar10->lpVtbl->Release)(pIVar10);
  local_14 = (IUnknown *)0x0;
  piVar11 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar11 = extraout_EAX_02;
  }
  (**(code **)(*piVar11 + 0xc))(piVar11,in_stack_00000020);
  piVar11 = local_1c;
  if (local_1c == (int *)0x0) {
    _com_issue_error(-0x7fffbffd);
    piVar11 = extraout_EAX_03;
  }
  if (puVar14 == (undefined4 *)0x0) {
    uVar13 = 0;
  }
  else {
    uVar13 = *puVar14;
  }
  (**(code **)(*piVar11 + 0x14))(piVar11,uVar13);
  Ordinal_201(0,local_18);
  local_3c[0] = _com_error::vftable;
  local_34 = local_18;
  local_30 = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 4))(local_18);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_3c,(ThrowInfo *)&DAT_10026bb8);
}



// Function: FUN_10018a80 at 10018a80

HRESULT __thiscall FUN_10018a80(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((uint)param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10020eac,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_1001f428,&param_3);
    if (HVar2 < 0) goto LAB_10018af9;
    HVar2 = OleRun(param_3);
    if (-1 < HVar2) {
      HVar2 = (*param_3->lpVtbl->QueryInterface)(param_3,(IID *)&DAT_10020eac,(void **)this);
    }
    (*param_3->lpVtbl->Release)(param_3);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_10018af9:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_10018b10 at 10018b10

undefined4 * __thiscall FUN_10018b10(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dd44;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 8);
  local_14 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1,&local_14,DAT_10029830 ^ (uint)&stack0xfffffffc);
  }
  uVar2 = local_14;
  puVar3 = (undefined4 *)operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0;
    puVar3[2] = 1;
    *puVar3 = uVar2;
  }
  local_8 = 0;
  *param_1 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10018bd0 at 10018bd0

undefined4 __fastcall FUN_10018bd0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    return *(undefined4 *)(param_1 + 8);
  }
  return 0;
}



// Function: FUN_10018c50 at 10018c50

undefined4 * __thiscall FUN_10018c50(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *extraout_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001dd84;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  iVar2 = (**(code **)(*this + 0x3c))(this,&local_14,DAT_10029830 ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_10020e9c);
  }
  uVar1 = local_14;
  puVar3 = (undefined4 *)operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0;
    puVar3[2] = 1;
    *puVar3 = uVar1;
  }
  local_8 = 0;
  *param_1 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
    param_1 = extraout_ECX;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10018d10 at 10018d10

uint __cdecl FUN_10018d10(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10018d30 at 10018d30

uchar * __cdecl FUN_10018d30(uchar *param_1)

{
  uchar *puVar1;
  
  puVar1 = _mbsrchr(param_1,0x2f);
  if (puVar1 == (uchar *)0x0) {
    puVar1 = _mbsrchr(param_1,0x5c);
  }
  else {
    puVar1 = puVar1 + 1;
  }
  if (puVar1 == (uchar *)0x0) {
    return param_1;
  }
  return puVar1 + 1;
}



// Function: FUN_10018d70 at 10018d70

undefined4 __cdecl FUN_10018d70(ushort param_1,LPSTR param_2)

{
  FormatMessageA(0x1200,(LPCVOID)0x0,(uint)param_1,0x400,param_2,0x2000,(va_list *)0x0);
  return 0;
}



// Function: FUN_10018da0 at 10018da0

void __fastcall FUN_10018da0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[10].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10020eac);
  }
  return;
}



// Function: FUN_10018dd0 at 10018dd0

void __fastcall FUN_10018dd0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[9].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10020eac);
  }
  return;
}



// Function: FUN_10018e00 at 10018e00

void __thiscall FUN_10018e00(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001dda8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x28))(this,iVar1,DAT_10029830 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10020e9c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018ec0 at 10018ec0

void __fastcall FUN_10018ec0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[5].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10020e9c);
  }
  return;
}



// Function: FUN_10018ef0 at 10018ef0

void __thiscall FUN_10018ef0(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ddd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x30))(this,iVar1,DAT_10029830 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10020e9c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018fb0 at 10018fb0

void __fastcall FUN_10018fb0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[4].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10020e9c);
  }
  return;
}



// Function: FUN_10018fe0 at 10018fe0

void __fastcall FUN_10018fe0(int *param_1)

{
  int *piVar1;
  code *pcVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
    return;
  }
  _com_issue_error(-0x7fffbffd);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



// Function: FUN_10019080 at 10019080

HRESULT __thiscall FUN_10019080(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001de08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x6c))(this,iVar1,DAT_10029830 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10020e9c);
  }
  local_8 = 0xffffffff;
  if (((param_1 != (int *)0x0) && (LVar2 = InterlockedDecrement(param_1 + 2), LVar2 == 0)) &&
     (param_1 != (int *)0x0)) {
    if (*param_1 != 0) {
      Ordinal_6(*param_1);
      *param_1 = 0;
    }
    if ((void *)param_1[1] != (void *)0x0) {
      operator_delete((void *)param_1[1]);
      param_1[1] = 0;
    }
    operator_delete(param_1);
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10019150 at 10019150

void __cdecl FUN_10019150(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10019170 at 10019170

void FUN_10019170(uchar *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x10019174. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _mbsrchr(param_1,param_2);
  return;
}



// Function: CAtlBaseModule at 100192f7

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::CAtlBaseModule(void)
   
   Library: Visual Studio 2012 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  HRESULT HVar1;
  
  _ATL_BASE_MODULE70::_ATL_BASE_MODULE70((_ATL_BASE_MODULE70 *)this);
  *(undefined4 *)this = 0x38;
  *(undefined4 *)(this + 8) = 0x10000000;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined4 *)(this + 0xc) = 0xb00;
  *(undefined **)(this + 0x10) = &DAT_1002316c;
  HVar1 = FUN_10009720((LPCRITICAL_SECTION)(this + 0x14));
  if (HVar1 < 0) {
    DAT_10029890 = 1;
  }
  return this;
}



// Function: FUN_10019335 at 10019335

undefined4 * __thiscall FUN_10019335(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: _ATL_BASE_MODULE70 at 10019345

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(void)
   
   Library: Visual Studio 2012 Release */

_ATL_BASE_MODULE70 * __thiscall
ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(_ATL_BASE_MODULE70 *this)

{
  memset(this + 0x14,0,0x18);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  return this;
}



// Function: ~CAtlBaseModule at 1001936d

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(CAtlBaseModule *this)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
  RemoveAll((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
             *)(this + 0x2c));
  return;
}



// Function: operator[] at 1001938b

/* Library Function - Single Match
    public: struct HINSTANCE__ * & __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::operator[](int)
   
   Library: Visual Studio 2012 Release */

HINSTANCE__ ** __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
operator[](CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
           *this,int param_1)

{
  code *pcVar1;
  HINSTANCE__ **ppHVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)(this + 4))) {
    return (HINSTANCE__ **)(*(int *)this + param_1 * 4);
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  ppHVar2 = (HINSTANCE__ **)(*pcVar1)();
  return ppHVar2;
}



// Function: Add at 100193b5

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::Add(struct HINSTANCE__ * const &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::Add
          (CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
           *this,HINSTANCE__ **param_1)

{
  undefined4 *puVar1;
  HINSTANCE__ **_Memory;
  code *pcVar2;
  void *pvVar3;
  int iVar4;
  uint _Count;
  
  iVar4 = *(int *)(this + 8);
  if (*(int *)(this + 4) == iVar4) {
    _Memory = *(HINSTANCE__ ***)this;
    if ((_Memory <= param_1) && (param_1 < _Memory + iVar4)) {
      FUN_10007680(0x80004005);
      pcVar2 = (code *)swi(3);
      iVar4 = (*pcVar2)();
      return iVar4;
    }
    if (iVar4 == 0) {
      _Count = 1;
LAB_100193ec:
      pvVar3 = _recalloc(_Memory,_Count,4);
      if (pvVar3 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_10019401;
      }
    }
    else {
      _Count = *(int *)(this + 4) * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_100193ec;
    }
    iVar4 = 0;
  }
  else {
LAB_10019401:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar4 = 1;
  }
  return iVar4;
}



// Function: AddResourceInstance at 1001942d

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::AddResourceInstance(struct HINSTANCE__ *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

bool __thiscall ATL::CAtlBaseModule::AddResourceInstance(CAtlBaseModule *this,HINSTANCE__ *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  iVar1 = CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
          ::Add((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                 *)(this + 0x2c),&param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  return iVar1 != 0;
}



// Function: GetHInstanceAt at 10019460

/* Library Function - Single Match
    public: struct HINSTANCE__ * __thiscall ATL::CAtlBaseModule::GetHInstanceAt(int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

HINSTANCE__ * __thiscall ATL::CAtlBaseModule::GetHInstanceAt(CAtlBaseModule *this,int param_1)

{
  HINSTANCE__ **ppHVar1;
  HINSTANCE__ *pHVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  if ((*(int *)(this + 0x30) < param_1) || (param_1 < 0)) {
    pHVar2 = (HINSTANCE__ *)0x0;
  }
  else if (param_1 == *(int *)(this + 0x30)) {
    pHVar2 = *(HINSTANCE__ **)(this + 8);
  }
  else {
    ppHVar1 = CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
              ::operator[]((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                            *)(this + 0x2c),param_1);
    pHVar2 = *ppHVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  return pHVar2;
}



// Function: InternalSetAtIndex at 100194a9

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CSimpleArray<unsigned long,class
   ATL::CSimpleArrayEqualHelper<unsigned long> >::InternalSetAtIndex(int,unsigned long const &)
    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::InternalSetAtIndex(int,struct HINSTANCE__ *
   const &)
    public: void __thiscall ATL::CSimpleArray<class CDHtmlControlSink *,class
   ATL::CSimpleArrayEqualHelper<class CDHtmlControlSink *> >::InternalSetAtIndex(int,class
   CDHtmlControlSink * const &)
    public: void __thiscall ATL::CSimpleArray<class CDHtmlElementEventSink *,class
   ATL::CSimpleArrayEqualHelper<class CDHtmlElementEventSink *> >::InternalSetAtIndex(int,class
   CDHtmlElementEventSink * const &)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void __thiscall InternalSetAtIndex(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined4 *)(*this + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return;
}



// Function: RemoveAll at 100194c3

/* Library Function - Single Match
    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAll(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

void __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
RemoveAll(CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
          *this)

{
  if (*(int *)this != 0) {
    free(*(void **)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// Function: RemoveAt at 100194e0

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAt(int)
   
   Library: Visual Studio 2012 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
RemoveAt(CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
         *this,int param_1)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 < 0) || (iVar2 = *(int *)(this + 4), iVar2 <= param_1)) {
    iVar2 = 0;
  }
  else {
    if (param_1 != iVar2 + -1) {
      uVar3 = (iVar2 - param_1) * 4;
      pvVar1 = (void *)(*(int *)this + param_1 * 4);
      Checked::memmove_s(pvVar1,uVar3,(void *)((int)pvVar1 + 4),uVar3 - 4);
    }
    *(int *)(this + 4) = *(int *)(this + 4) + -1;
    iVar2 = 1;
  }
  return iVar2;
}



// Function: RemoveResourceInstance at 10019528

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::RemoveResourceInstance(struct HINSTANCE__ *)
   
   Library: Visual Studio 2012 Release */

bool __thiscall
ATL::CAtlBaseModule::RemoveResourceInstance(CAtlBaseModule *this,HINSTANCE__ *param_1)

{
  HINSTANCE__ **ppHVar1;
  bool bVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  bVar2 = false;
  iVar3 = 0;
  if (0 < *(int *)(this + 0x30)) {
    do {
      ppHVar1 = CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                ::operator[]((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                              *)(this + 0x2c),iVar3);
      if (*ppHVar1 == param_1) {
        CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
        RemoveAt((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                  *)(this + 0x2c),iVar3);
        bVar2 = true;
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 0x30));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  return bVar2;
}



// Function: memmove_s at 10019585

/* Library Function - Single Match
    void __cdecl ATL::Checked::memmove_s(void *,unsigned int,void const *,unsigned int)
   
   Library: Visual Studio 2012 Release */

void __cdecl ATL::Checked::memmove_s(void *param_1,uint param_2,void *param_3,uint param_4)

{
  errno_t eVar1;
  
  eVar1 = ::memmove_s(param_1,param_2,param_3,param_4);
  AtlCrtErrorCheck(eVar1);
  return;
}



// Function: CAtlComModule at 100195a4

/* Library Function - Single Match
    public: __thiscall ATL::CAtlComModule::CAtlComModule(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

CAtlComModule * __thiscall ATL::CAtlComModule::CAtlComModule(CAtlComModule *this)

{
  HRESULT HVar1;
  
  _ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)this);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined **)(this + 8) = &DAT_10026de8;
  *(undefined **)(this + 0xc) = &DAT_10026de8;
  HVar1 = FUN_10009720((LPCRITICAL_SECTION)(this + 0x10));
  if (HVar1 < 0) {
    DAT_10029890 = 1;
  }
  else {
    *(undefined4 *)this = 0x28;
  }
  return this;
}



// Function: _ATL_COM_MODULE70 at 100195e3

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

_ATL_COM_MODULE70 * __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  memset(this + 0x10,0,0x18);
  return this;
}



// Function: Term at 10019600

/* Library Function - Single Match
    public: void __thiscall ATL::CAtlComModule::Term(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall ATL::CAtlComModule::Term(CAtlComModule *this)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  if (*(int *)this != 0) {
    piVar3 = *(int **)(this + 8);
    if (piVar3 < *(int **)(this + 0xc)) {
      do {
        if ((*piVar3 != 0) && (piVar1 = *(int **)(*piVar3 + 0x10), *piVar1 != 0)) {
          piVar2 = (int *)DecodePointer((PVOID)*piVar1);
          (**(code **)(*piVar2 + 8))(piVar2);
          *piVar1 = 0;
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 < *(int **)(this + 0xc));
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x10));
    *(undefined4 *)this = 0;
  }
  return;
}



// Function: `vector_constructor_iterator' at 1001964a

/* Library Function - Single Match
    void __stdcall `vector constructor iterator'(void *,unsigned int,int,void * (__thiscall*)(void
   *))
   
   Library: Visual Studio 2012 Release */

void _vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_ptr_void_ptr *param_4)

{
  int iVar1;
  void *unaff_EDI;
  
  for (iVar1 = param_3 + -1; -1 < iVar1; iVar1 = iVar1 + -1) {
    (*param_4)(unaff_EDI);
  }
  return;
}



// Function: `vector_destructor_iterator' at 10019669

/* Library Function - Single Match
    void __stdcall `vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void _vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  return;
}



// Function: _com_dispatch_method at 10019690

/* Library Function - Single Match
    long __cdecl _com_dispatch_method(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,...)
   
   Library: Visual Studio 2012 Release */

long __cdecl
_com_dispatch_method
          (IDispatch *param_1,long param_2,ushort param_3,ushort param_4,void *param_5,
          ushort *param_6,...)

{
  long lVar1;
  IErrorInfo *local_8;
  
  lVar1 = _com_invoke_helper(param_1,param_2,param_3,param_4,param_5,param_6,&stack0x0000001c,
                             &local_8);
  if (lVar1 < 0) {
    (*(code *)PTR_FUN_10029818)(lVar1,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_propget at 100196d0

/* Library Function - Single Match
    long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2012 Release */

long _com_dispatch_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_propput at 100196f0

/* Library Function - Single Match
    long __cdecl _com_dispatch_propput(struct IDispatch *,long,unsigned short,...)
   
   Library: Visual Studio 2012 Release */

long __cdecl _com_dispatch_propput(IDispatch *param_1,long param_2,ushort param_3,...)

{
  ushort uVar1;
  long lVar2;
  IErrorInfo *local_c;
  ushort local_8 [2];
  
  local_8[0] = param_3;
  local_8[1] = 0;
  if ((param_3 == 9) || (uVar1 = 4, param_3 == 0xd)) {
    uVar1 = 8;
  }
  lVar2 = _com_invoke_helper(param_1,param_2,uVar1,0,(void *)0x0,local_8,&stack0x00000010,&local_c);
  if (lVar2 < 0) {
    (*(code *)PTR_FUN_10029818)(lVar2,local_c);
  }
  return lVar2;
}



// Function: _com_issue_error at 10019750

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Library: Visual Studio 2012 Release */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_10029818)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 10019770

/* Library Function - Single Match
    void __stdcall _com_issue_errorex(long,struct IUnknown *,struct _GUID const &)
   
   Library: Visual Studio 2012 Release */

void _com_issue_errorex(long param_1,IUnknown *param_2,_GUID *param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 **ppuVar3;
  void **unaff_ESI;
  undefined4 **local_8;
  
  local_8 = (undefined4 **)0x0;
  ppuVar3 = (undefined4 **)0x0;
  if ((param_2 != (IUnknown *)0x0) &&
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1001f9dc,&param_2),
     ppuVar3 = local_8, -1 < HVar1)) {
    HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
    (*param_2->lpVtbl->Release)(param_2);
    ppuVar3 = local_8;
    if (HVar1 == 0) {
      local_8 = &local_8;
      iVar2 = Ordinal_200(0);
      local_8 = (undefined4 **)(~-(uint)(iVar2 != 0) & (uint)local_8);
      (*(code *)PTR_FUN_10029818)(param_1,local_8);
      return;
    }
  }
  local_8 = ppuVar3;
  (*(code *)PTR_FUN_10029818)(param_1);
  return;
}



// Function: FUN_100197f0 at 100197f0

void FUN_100197f0(undefined *param_1)

{
  PTR_FUN_10029818 = param_1;
  return;
}



// Function: _variant_t at 10019800

/* Library Function - Single Match
    public: __thiscall _variant_t::_variant_t(long,unsigned short)
   
   Library: Visual Studio 2012 Release */

_variant_t * __thiscall _variant_t::_variant_t(_variant_t *this,long param_1,ushort param_2)

{
  code *pcVar1;
  _variant_t *p_Var2;
  
  if (param_2 != 3) {
    if (param_2 == 10) goto LAB_1001981f;
    if (param_2 != 0xb) {
      _com_issue_error(-0x7ff8ffa9);
      pcVar1 = (code *)swi(3);
      p_Var2 = (_variant_t *)(*pcVar1)();
      return p_Var2;
    }
  }
  if (param_2 != 10) {
    if (param_2 == 0xb) {
      *(undefined2 *)this = 0xb;
      *(ushort *)(this + 8) = -(ushort)(param_1 != 0);
      return this;
    }
    *(undefined2 *)this = 3;
    *(long *)(this + 8) = param_1;
    return this;
  }
LAB_1001981f:
  *(undefined2 *)this = 10;
  *(long *)(this + 8) = param_1;
  return this;
}



// Function: ConvertBSTRToString at 10019890

/* Library Function - Multiple Matches With Same Base Name
    char * __stdcall _com_util::ConvertBSTRToString(unsigned short *)
    char * __stdcall _com_util::ConvertBSTRToString(wchar_t *)
   
   Library: Visual Studio 2012 Release */

LPSTR ConvertBSTRToString(LPCWSTR param_1)

{
  WCHAR WVar1;
  code *pcVar2;
  uint cbMultiByte;
  DWORD DVar3;
  LPSTR pCVar4;
  int iVar5;
  LPCWSTR pWVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001de30;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return (LPSTR)0x0;
  }
  pWVar6 = param_1;
  do {
    WVar1 = *pWVar6;
    pWVar6 = pWVar6 + 1;
  } while (WVar1 != L'\0');
  iVar5 = ((int)pWVar6 - (int)(param_1 + 1) >> 1) + 1;
  ExceptionList = &local_10;
  cbMultiByte = WideCharToMultiByte(0,0,param_1,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (cbMultiByte == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
    _com_issue_error(DVar3);
  }
  local_8 = 0;
  pCVar4 = (LPSTR)operator_new(cbMultiByte);
  local_8 = 0xffffffff;
  if (pCVar4 != (LPSTR)0x0) {
    iVar5 = WideCharToMultiByte(0,0,param_1,iVar5,pCVar4,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar5 == 0) {
      operator_delete(pCVar4);
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
      _com_issue_error(DVar3);
    }
    ExceptionList = local_10;
    return pCVar4;
  }
  _com_issue_error(-0x7ff8fff2);
  pcVar2 = (code *)swi(3);
  pCVar4 = (LPSTR)(*pcVar2)();
  return pCVar4;
}



// Function: Catch_All@10019993 at 10019993

undefined * Catch_All_10019993(void)

{
  return &DAT_10019999;
}



// Function: ConvertStringToBSTR at 100199b0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Multiple Matches With Same Base Name
    unsigned short * __stdcall _com_util::ConvertStringToBSTR(char const *)
    wchar_t * __stdcall _com_util::ConvertStringToBSTR(char const *)
   
   Library: Visual Studio 2012 Release */

void ConvertStringToBSTR(LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  int cchWideChar;
  DWORD DVar3;
  LPWSTR lpWideCharStr;
  int extraout_EAX;
  uint local_3c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = FUN_1001abab;
  local_14 = ExceptionList;
  local_c = DAT_10029830 ^ 0x10026bf0;
  uVar1 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_14;
  local_3c = uVar1;
  if (param_1 != (LPCSTR)0x0) {
    iVar2 = lstrlenA(param_1);
    iVar2 = iVar2 + 1;
    cchWideChar = MultiByteToWideChar(0,0,param_1,iVar2,(LPWSTR)0x0,0);
    if (cchWideChar == 0) {
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
      _com_issue_error(DVar3);
    }
    local_8 = 0;
    if (cchWideChar < 0x1000) {
      lpWideCharStr = (LPWSTR)&local_3c;
    }
    else {
      lpWideCharStr = (LPWSTR)malloc(cchWideChar * 2);
    }
    local_8 = 0xfffffffe;
    if (lpWideCharStr == (LPWSTR)0x0) {
      _com_issue_error(-0x7ff8fff2);
      iVar2 = extraout_EAX;
    }
    iVar2 = MultiByteToWideChar(0,0,param_1,iVar2,lpWideCharStr,cchWideChar);
    if (iVar2 == 0) {
      if (0xfff < cchWideChar) {
        free(lpWideCharStr);
      }
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
      _com_issue_error(DVar3);
    }
    iVar2 = Ordinal_2(lpWideCharStr);
    if (0xfff < cchWideChar) {
      free(lpWideCharStr);
    }
    if (iVar2 == 0) {
      _com_issue_error(-0x7ff8fff2);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10019b30 at 10019b30

uint FUN_10019b30(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_10019b50 at 10019b50

void FUN_10019b50(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_1;
  local_c = param_2;
  local_14 = _com_error::vftable;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10026bb8);
}



// Function: _com_dispatch_raw_method at 10019b80

/* Library Function - Single Match
    long __cdecl _com_dispatch_raw_method(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,...)
   
   Library: Visual Studio 2012 Release */

long __cdecl
_com_dispatch_raw_method
          (IDispatch *param_1,long param_2,ushort param_3,ushort param_4,void *param_5,
          ushort *param_6,...)

{
  long lVar1;
  IErrorInfo *local_8;
  
  lVar1 = _com_invoke_helper(param_1,param_2,param_3,param_4,param_5,param_6,&stack0x0000001c,
                             &local_8);
  if (lVar1 < 0) {
    Ordinal_201(0,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_raw_propget at 10019bc0

/* Library Function - Single Match
    long __stdcall _com_dispatch_raw_propget(struct IDispatch *,long,unsigned short,void *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

long _com_dispatch_raw_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_raw_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_raw_propput at 10019be0

/* Library Function - Single Match
    long __cdecl _com_dispatch_raw_propput(struct IDispatch *,long,unsigned short,...)
   
   Library: Visual Studio 2012 Release */

long __cdecl _com_dispatch_raw_propput(IDispatch *param_1,long param_2,ushort param_3,...)

{
  ushort uVar1;
  long lVar2;
  IErrorInfo *local_c;
  ushort local_8 [2];
  
  local_8[0] = param_3;
  local_8[1] = 0;
  if ((param_3 == 9) || (uVar1 = 4, param_3 == 0xd)) {
    uVar1 = 8;
  }
  lVar2 = _com_invoke_helper(param_1,param_2,uVar1,0,(void *)0x0,local_8,&stack0x00000010,&local_c);
  if (lVar2 < 0) {
    Ordinal_201(0,local_c);
  }
  return lVar2;
}



// Function: _com_invoke_helper at 10019c40

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    long __cdecl _com_invoke_helper(struct IDispatch *,long,unsigned short,unsigned short,void
   *,unsigned short const *,char *,struct IErrorInfo * *)
   
   Library: Visual Studio 2012 Release */

long __cdecl
_com_invoke_helper(IDispatch *param_1,long param_2,ushort param_3,ushort param_4,void *param_5,
                  ushort *param_6,char *param_7,IErrorInfo **param_8)

{
  ushort uVar1;
  short *psVar2;
  long lVar3;
  ushort uVar4;
  short *psVar5;
  undefined4 *puVar6;
  int *piVar7;
  ushort *puVar8;
  uint uVar9;
  uint *puVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  uint *puVar15;
  undefined2 in_stack_0000000e;
  undefined2 in_stack_00000012;
  uint uStack_9c;
  uint local_8c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ushort *local_4c;
  uint *local_48;
  undefined1 *local_44;
  undefined4 *local_40;
  int local_3c;
  uint local_38;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined4 uStack_24;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = FUN_1001abab;
  local_14 = ExceptionList;
  local_c = DAT_10029830 ^ 0x10026c68;
  local_8c = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_8c;
  ExceptionList = &local_14;
  local_20 = local_8c;
  puVar15 = &local_8c;
  if (param_1 == (IDispatch *)0x0) goto LAB_10019fb5;
  if (param_8 != (IErrorInfo **)0x0) {
    *param_8 = (IErrorInfo *)0x0;
  }
  local_44 = (undefined1 *)0x0;
  local_40 = (undefined4 *)0x0;
  local_3c = 0;
  local_38 = 0;
  puVar15 = &local_8c;
  if (param_6 != (ushort *)0x0) {
    local_3c = lstrlenW((LPCWSTR)param_6);
    puVar15 = (uint *)local_1c;
  }
  local_1c = (undefined1 *)puVar15;
  local_54 = 0xfffffffd;
  if ((param_3 & 0xc) != 0) {
    puVar15 = (uint *)local_1c;
    if (local_3c == 0) goto LAB_10019fb5;
    local_38 = 1;
    local_40 = &local_54;
  }
  if (local_3c != 0) {
    local_1c = (undefined1 *)&local_8c;
    local_34 = &local_8c;
    local_8 = 0xfffffffe;
    uStack_9c = 0x10019d0c;
    memset(&local_8c,0,local_3c * 0x10);
    local_44 = (undefined1 *)&local_8c;
    local_4c = param_6;
    puVar10 = &uStack_9c + local_3c * 4;
    local_48 = puVar10;
    puVar15 = &local_8c;
    if (*param_6 != 0) {
      piVar14 = (int *)(&stack0xffffff6c + local_3c * 0x10);
      piVar7 = (int *)(param_7 + -4);
      local_48 = (uint *)0x5;
      local_50 = 0xe;
      piVar11 = (int *)(param_7 + -8);
      do {
        uVar1 = *local_4c;
        uVar4 = uVar1 & 0xf7ff;
        *(ushort *)puVar10 = uVar4;
        if (0x4002 < uVar4) {
          switch(uVar4) {
          case 0x4003:
          case 0x4004:
          case 0x4005:
          case 0x4006:
          case 0x4007:
          case 0x4008:
          case 0x4009:
          case 0x400a:
          case 0x400b:
          case 0x400c:
          case 0x400d:
          case 0x400e:
          case 0x4010:
          case 0x4011:
          case 0x4012:
          case 0x4013:
          case 0x4014:
          case 0x4015:
          case 0x4016:
          case 0x4017:
          case 0x4019:
          case 0x4024:
            break;
          default:
switchD_10019d85_caseD_f:
            puVar15 = (uint *)local_1c;
            if ((uVar1 & 0x2000) == 0) goto LAB_10019fb5;
          }
switchD_10019d85_caseD_3:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *piVar14 = *piVar7;
          goto LAB_10019e70;
        }
        if (uVar4 == 0x4002) goto switchD_10019d85_caseD_3;
        switch(uVar4) {
        case 2:
        case 0x12:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *(short *)piVar14 = (short)*piVar7;
          break;
        case 3:
        case 8:
        case 9:
        case 10:
        case 0xd:
        case 0x13:
        case 0x16:
        case 0x17:
        case 0x19:
        case 0x24:
          goto switchD_10019d85_caseD_3;
        case 4:
          *(ushort *)puVar10 = 5;
        case 5:
        case 7:
          piVar12 = piVar11 + 2;
          piVar7 = piVar7 + 2;
          *(undefined8 *)piVar14 = *(undefined8 *)piVar12;
          break;
        case 6:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          piVar11 = (int *)*piVar7;
          *piVar14 = *piVar11;
          piVar14[1] = piVar11[1];
          break;
        case 0xb:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *(ushort *)piVar14 = -(ushort)((short)*piVar7 != 0);
          break;
        case 0xc:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          puVar15 = (uint *)*piVar7;
          *puVar10 = *puVar15;
          puVar10[1] = puVar15[1];
          puVar10[2] = puVar15[2];
          puVar10[3] = puVar15[3];
          break;
        case 0xe:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          puVar15 = (uint *)*piVar7;
          *puVar10 = *puVar15;
          puVar10[1] = puVar15[1];
          puVar10[2] = puVar15[2];
          puVar10[3] = puVar15[3];
          *(ushort *)puVar10 = 0xe;
          break;
        default:
          goto switchD_10019d85_caseD_f;
        case 0x10:
        case 0x11:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *(char *)piVar14 = (char)*piVar7;
          break;
        case 0x14:
        case 0x15:
          piVar12 = piVar11 + 2;
          piVar7 = piVar7 + 2;
          *piVar14 = *piVar12;
          piVar14[1] = piVar11[3];
        }
LAB_10019e70:
        puVar10 = puVar10 + -4;
        piVar14 = piVar14 + -4;
        local_4c = local_4c + 1;
        piVar11 = piVar12;
        puVar15 = local_34;
      } while (*local_4c != 0);
    }
    psVar5 = (short *)(puVar15 + local_38 * 4);
    puVar8 = param_6 + (local_3c - local_38) + -1;
    iVar13 = 0;
    if (param_6 <= puVar8) {
      while (puVar15 = local_34, (*puVar8 & 0xbfff) == 0x80c) {
        psVar2 = psVar5;
        if ((*puVar8 & 0x4000) != 0) {
          psVar2 = *(short **)(psVar5 + 4);
        }
        if ((*psVar2 != 10) || (*(int *)(psVar2 + 4) != -0x7ffdfffc)) break;
        iVar13 = iVar13 + 1;
        psVar5 = psVar5 + 8;
        puVar8 = puVar8 + -1;
        if (puVar8 < param_6) break;
      }
    }
    if (iVar13 != 0) {
      uVar9 = 0;
      if (local_38 != 0) {
        puVar6 = puVar15 + iVar13 * 4;
        do {
          *puVar6 = *puVar15;
          puVar6[1] = puVar15[1];
          puVar6[2] = puVar15[2];
          puVar6[3] = puVar15[3];
          uVar9 = uVar9 + 1;
          puVar15 = puVar15 + 4;
          puVar6 = puVar6 + 4;
        } while (uVar9 < local_38);
      }
      local_3c = local_3c - iVar13;
      local_44 = local_44 + iVar13 * 0x10;
    }
  }
  Ordinal_8();
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0xffffffff;
  uStack_9c = -(uint)(param_4 != 0) & (uint)&local_30;
  iVar13 = (**(code **)(*(int *)param_1 + 0x18))(param_1,param_2,&DAT_1001f400,0,_param_3,&local_44)
  ;
  if (iVar13 < 0) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    if (iVar13 == -0x7ffdfff7) {
      _com_handle_excepinfo((tagEXCEPINFO *)&local_78,param_8);
      puVar15 = (uint *)local_1c;
    }
    goto LAB_10019fb5;
  }
  puVar15 = (uint *)local_1c;
  if ((param_4 == 0) || (param_5 == (void *)0x0)) goto LAB_10019fb5;
  if ((param_4 != 0xc) &&
     ((param_4 != (ushort)local_30 &&
      (iVar13 = Ordinal_12(&local_30,&local_30,0,_param_4), iVar13 < 0)))) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    goto LAB_10019fb5;
  }
  puVar15 = (uint *)local_1c;
  if (param_4 < 0x4003) {
    if (param_4 != 0x4002) {
      switch(param_4) {
      case 2:
      case 0xb:
      case 0x12:
        *(ushort *)param_5 = CONCAT11(uStack_27,local_28);
        break;
      case 3:
      case 8:
      case 9:
      case 10:
      case 0xd:
      case 0x13:
      case 0x16:
      case 0x17:
      case 0x19:
      case 0x24:
        goto switchD_1001a05f_caseD_3;
      case 4:
        *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
        break;
      case 5:
      case 7:
        *(ulonglong *)param_5 = CONCAT44(uStack_24,CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)))
        ;
        break;
      case 6:
      case 0x14:
      case 0x15:
        *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
        *(undefined4 *)((int)param_5 + 4) = uStack_24;
        break;
      case 0xc:
      case 0xe:
        *(undefined4 *)param_5 = local_30;
        *(undefined4 *)((int)param_5 + 4) = local_2c;
        *(uint *)((int)param_5 + 8) = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
        *(undefined4 *)((int)param_5 + 0xc) = uStack_24;
        break;
      default:
        goto switchD_1001a05f_caseD_f;
      case 0x10:
      case 0x11:
        *(undefined1 *)param_5 = local_28;
      }
      goto LAB_10019fb5;
    }
  }
  else {
    switch(param_4) {
    case 0x4003:
    case 0x4004:
    case 0x4005:
    case 0x4006:
    case 0x4007:
    case 0x4008:
    case 0x4009:
    case 0x400a:
    case 0x400b:
    case 0x400c:
    case 0x400d:
    case 0x400e:
    case 0x4010:
    case 0x4011:
    case 0x4012:
    case 0x4013:
    case 0x4014:
    case 0x4015:
    case 0x4016:
    case 0x4017:
    case 0x4019:
    case 0x4024:
      break;
    default:
switchD_1001a05f_caseD_f:
      if ((param_4 & 0x2000) == 0) {
        Ordinal_9(&local_30);
        puVar15 = (uint *)local_1c;
        goto LAB_10019fb5;
      }
    }
  }
switchD_1001a05f_caseD_3:
  *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
LAB_10019fb5:
  local_1c = (undefined1 *)puVar15;
  ExceptionList = local_14;
  lVar3 = __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return lVar3;
}



// Function: FUN_1001a1f0 at 1001a1f0

int FUN_1001a1f0(ushort param_1)

{
  if (0xfdff < param_1) {
    return -0x7ffb0001;
  }
  return param_1 + 0x80040200;
}



// Function: _com_handle_excepinfo at 1001a220

/* Library Function - Single Match
    long __stdcall _com_handle_excepinfo(struct tagEXCEPINFO &,struct IErrorInfo * *)
   
   Library: Visual Studio 2012 Release */

long _com_handle_excepinfo(tagEXCEPINFO *param_1,IErrorInfo **param_2)

{
  ushort uVar1;
  tagEXCEPINFO *ptVar2;
  IErrorInfo **ppIVar3;
  int iVar4;
  
  ptVar2 = param_1;
  if (*(code **)(param_1 + 0x18) != (code *)0x0) {
    (**(code **)(param_1 + 0x18))(param_1);
  }
  ppIVar3 = param_2;
  param_1 = (tagEXCEPINFO *)0x0;
  if (param_2 != (IErrorInfo **)0x0) {
    iVar4 = Ordinal_202(&param_1);
    if (-1 < iVar4) {
      (**(code **)(*(int *)param_1 + 0xc))(param_1,&DAT_1001f444);
      if (*(int *)(ptVar2 + 4) != 0) {
        (**(code **)(*(int *)param_1 + 0x10))(param_1,*(int *)(ptVar2 + 4));
      }
      if (*(int *)(ptVar2 + 8) != 0) {
        (**(code **)(*(int *)param_1 + 0x14))(param_1,*(int *)(ptVar2 + 8));
      }
      if (*(int *)(ptVar2 + 0xc) != 0) {
        (**(code **)(*(int *)param_1 + 0x18))(param_1,*(int *)(ptVar2 + 0xc));
      }
      (**(code **)(*(int *)param_1 + 0x1c))(param_1,*(undefined4 *)(ptVar2 + 0x10));
      iVar4 = (*(code *)**(undefined4 **)param_1)(param_1,&DAT_1001f4e8,ppIVar3);
      if (iVar4 < 0) {
        *ppIVar3 = (IErrorInfo *)0x0;
      }
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
  }
  if (*(int *)(ptVar2 + 4) != 0) {
    Ordinal_6(*(int *)(ptVar2 + 4));
  }
  if (*(int *)(ptVar2 + 8) != 0) {
    Ordinal_6(*(int *)(ptVar2 + 8));
  }
  if (*(int *)(ptVar2 + 0xc) != 0) {
    Ordinal_6(*(int *)(ptVar2 + 0xc));
  }
  uVar1 = *(ushort *)ptVar2;
  if (uVar1 != 0) {
    if (0xfdff < uVar1) {
      return -0x7ffb0001;
    }
    return uVar1 + 0x80040200;
  }
  return *(long *)(ptVar2 + 0x1c);
}



// Function: `eh_vector_destructor_iterator' at 1001a316

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *))
   
   Library: Visual Studio 2012 Release */

void _eh_vector_destructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffd0;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffd0);
  }
  FUN_1001a375();
  return;
}



// Function: FUN_1001a375 at 1001a375

void FUN_1001a375(void)

{
  int in_EAX;
  uint unaff_EBX;
  int unaff_EBP;
  void *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(unaff_ESI,unaff_EBX,unaff_EDI,*(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: FUN_1001a385 at 1001a385

undefined4 __cdecl FUN_1001a385(undefined4 *param_1)

{
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 != -0x1f928c9d) {
    return 0;
  }
  terminate();
  return extraout_EAX;
}



// Function: __ArrayUnwind at 1001a39e

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

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



// Function: __security_check_cookie at 1001a402

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Library: Visual Studio 2012 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10029830) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: _RTC_AllocaHelper at 1001a411

/* Library Function - Single Match
    @_RTC_AllocaHelper@12
   
   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019
   __fastcall _RTC_AllocaHelper,12 */

void __fastcall _RTC_AllocaHelper(undefined1 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (((param_1 != (undefined1 *)0x0) && (param_2 != 0)) &&
     (iVar1 = param_2, puVar2 = param_1, param_3 != (undefined4 *)0x0)) {
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0xcc;
      puVar2 = puVar2 + 1;
    }
    *(undefined4 *)(param_1 + 4) = *param_3;
    *(int *)(param_1 + 0xc) = param_2;
    *param_3 = param_1;
  }
  return;
}



// Function: _RTC_CheckStackVars2 at 1001a443

/* Library Function - Single Match
    @_RTC_CheckStackVars2@12
   
   Library: Visual Studio 2012 Release
   __fastcall _RTC_CheckStackVars2,12 */

void __fastcall _RTC_CheckStackVars2(int param_1,int *param_2,_RTC_ALLOCA_NODE *param_3)

{
  int iVar1;
  _RTC_ALLOCA_NODE *p_Var2;
  int iVar3;
  void *unaff_retaddr;
  int local_8;
  
  if ((param_2 != (int *)0x0) && (local_8 = 0, 0 < *param_2)) {
    iVar3 = 0;
    do {
      iVar1 = param_2[1];
      if ((*(int *)(*(int *)(iVar3 + iVar1) + -4 + param_1) != -0x33333334) ||
         (*(int *)(*(int *)(iVar3 + 4 + iVar1) + *(int *)(iVar3 + iVar1) + param_1) != -0x33333334))
      {
        _RTC_StackFailure(unaff_retaddr,*(char **)(iVar3 + 8 + iVar1));
      }
      local_8 = local_8 + 1;
      iVar3 = iVar3 + 0xc;
    } while (local_8 < *param_2);
  }
  iVar3 = 0;
  p_Var2 = param_3;
  if (param_3 != (_RTC_ALLOCA_NODE *)0x0) {
    do {
      p_Var2 = *(_RTC_ALLOCA_NODE **)(p_Var2 + 4);
      iVar3 = iVar3 + 1;
    } while (p_Var2 != (_RTC_ALLOCA_NODE *)0x0);
    for (; param_3 != (_RTC_ALLOCA_NODE *)0x0; param_3 = *(_RTC_ALLOCA_NODE **)(param_3 + 4)) {
      if ((((*(int *)param_3 != -0x33333334) || (*(int *)(param_3 + 0x14) != -0x33333334)) ||
          (*(int *)(param_3 + 0x18) != -0x33333334)) || (*(int *)(param_3 + 0x1c) != -0x33333334)) {
        _RTC_AllocaFailure(unaff_retaddr,param_3,iVar3);
      }
      if (*(int *)(param_3 + *(int *)(param_3 + 0xc) + -4) != -0x33333334) {
        _RTC_AllocaFailure(unaff_retaddr,param_3,iVar3);
      }
      iVar3 = iVar3 + -1;
    }
  }
  return;
}



// Function: _RTC_CheckStackVars at 1001a507

/* Library Function - Single Match
    @_RTC_CheckStackVars@8
   
   Library: Visual Studio 2012 Release
   __fastcall _RTC_CheckStackVars,8 */

void __fastcall _RTC_CheckStackVars(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *unaff_retaddr;
  
  iVar2 = 0;
  if (0 < *param_2) {
    iVar3 = 0;
    do {
      iVar1 = param_2[1];
      if ((*(int *)(*(int *)(iVar3 + iVar1) + -4 + param_1) != -0x33333334) ||
         (*(int *)(*(int *)(iVar3 + 4 + iVar1) + *(int *)(iVar3 + iVar1) + param_1) != -0x33333334))
      {
        _RTC_StackFailure(unaff_retaddr,*(char **)(iVar3 + 8 + iVar1));
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar2 < *param_2);
  }
  return;
}



// Function: __RTC_CheckEsp at 1001a55d

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __RTC_CheckEsp
   
   Library: Visual Studio 2012 Release */

undefined8 __fastcall __RTC_CheckEsp(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  bool in_ZF;
  void *unaff_retaddr;
  
  if (in_ZF) {
    return CONCAT44(param_2,in_EAX);
  }
  _RTC_Failure(unaff_retaddr,0);
  return CONCAT44(param_2,in_EAX);
}



// Function: `eh_vector_constructor_iterator' at 1001a5c0

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void
   *),void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void _eh_vector_constructor_iterator_
               (void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4,
               _func_void_void_ptr *param_5)

{
  int iVar1;
  void *in_stack_ffffffcc;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    (*param_4)(in_stack_ffffffcc);
  }
  FUN_1001a618();
  return;
}



// Function: FUN_1001a618 at 1001a618

void FUN_1001a618(void)

{
  int in_EAX;
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  void *unaff_EDI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(unaff_EDI,unaff_EBX,unaff_ESI,*(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 1001a670

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 2012 Release */

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
  
  local_8 = &DAT_10026ce8;
  uStack_c = 0x1001a67c;
  local_20[0] = DecodePointer(DAT_10029d24);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10029d24);
    local_24 = DecodePointer(DAT_10029d20);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10029d24 = EncodePointer(local_20[0]);
    DAT_10029d20 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1001a70c();
  }
  return p_Var1;
}



// Function: FUN_1001a70c at 1001a70c

void FUN_1001a70c(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1001a715

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2012 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: ___raise_securityfailure at 1001a72a

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_10029ce4 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_10029ce4 == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}



// Function: ___report_gsfailure at 1001a767

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___report_gsfailure(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
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
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_10029ac0 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_10029ac8 = (undefined4)uVar9;
  _DAT_10029ad8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_10029adc = &stack0x00000004;
  _DAT_10029a18 = 0x10001;
  _DAT_100299c8 = 0xc0000409;
  _DAT_100299cc = 1;
  _DAT_100299d8 = 1;
  DAT_100299dc = 2;
  _DAT_100299d4 = unaff_retaddr;
  _DAT_10029aa4 = in_GS;
  _DAT_10029aa8 = in_FS;
  _DAT_10029aac = in_ES;
  _DAT_10029ab0 = in_DS;
  _DAT_10029ab4 = unaff_EDI;
  _DAT_10029ab8 = unaff_ESI;
  _DAT_10029abc = unaff_EBX;
  _DAT_10029ac4 = uVar3;
  _DAT_10029acc = unaff_EBP;
  DAT_10029ad0 = unaff_retaddr;
  _DAT_10029ad4 = in_CS;
  _DAT_10029ae0 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10023234);
  return;
}



// Function: ___report_rangecheckfailure at 1001a860

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}



// Function: ___report_securityfailure at 1001a86c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___report_securityfailure(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
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
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_10029ac0 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_10029ac8 = (undefined4)uVar9;
  _DAT_10029ad8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_10029adc = &param_1;
  _DAT_100299c8 = 0xc0000409;
  _DAT_100299cc = 1;
  _DAT_100299d8 = 1;
  DAT_100299dc = param_1;
  _DAT_100299d4 = unaff_retaddr;
  _DAT_10029aa4 = in_GS;
  _DAT_10029aa8 = in_FS;
  _DAT_10029aac = in_ES;
  _DAT_10029ab0 = in_DS;
  _DAT_10029ab4 = unaff_EDI;
  _DAT_10029ab8 = unaff_ESI;
  _DAT_10029abc = unaff_EBX;
  _DAT_10029ac4 = uVar3;
  _DAT_10029acc = unaff_EBP;
  DAT_10029ad0 = unaff_retaddr;
  _DAT_10029ad4 = in_CS;
  _DAT_10029ae0 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10023234);
  return;
}



// Function: ___report_securityfailureEx at 1001a93a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_securityfailureEx
   
   Library: Visual Studio 2012 Release */

void __cdecl ___report_securityfailureEx(undefined4 param_1,uint param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
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
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  uint local_8;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_10029ad8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_10029adc = &param_1;
  _DAT_100299c8 = 0xc0000409;
  _DAT_100299cc = 1;
  if ((param_2 != 0) && (param_3 == 0)) {
    param_2 = 0;
  }
  if (0xe < param_2) {
    param_2 = param_2 - 1;
  }
  _DAT_100299d8 = param_2 + 1;
  DAT_100299dc = param_1;
  _DAT_100299d4 = unaff_retaddr;
  _DAT_10029aa4 = in_GS;
  _DAT_10029aa8 = in_FS;
  _DAT_10029aac = in_ES;
  _DAT_10029ab0 = in_DS;
  _DAT_10029ab4 = unaff_EDI;
  _DAT_10029ab8 = unaff_ESI;
  _DAT_10029abc = unaff_EBX;
  _DAT_10029ac4 = uVar3;
  _DAT_10029acc = unaff_EBP;
  DAT_10029ad0 = unaff_retaddr;
  _DAT_10029ad4 = in_CS;
  _DAT_10029ae0 = in_SS;
  for (local_8 = 0; _DAT_10029ac0 = (undefined4)((ulonglong)uVar9 >> 0x20),
      _DAT_10029ac8 = (undefined4)uVar9, local_8 < param_2; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_100299e0 + local_8 * 4) = *(undefined4 *)(param_3 + local_8 * 4);
    uVar9 = CONCAT44(_DAT_10029ac0,_DAT_10029ac8);
  }
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10023234);
  return;
}



// Function: FUN_1001aa60 at 1001aa60

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_1001aa60(uint param_1)

{
  operator_new(param_1);
  FUN_1001aa88();
  return;
}



// Function: Catch_All@1001aa7b at 1001aa7b

undefined * Catch_All_1001aa7b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  return &DAT_1001aa85;
}



// Function: FUN_1001aa88 at 1001aa88

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001aa88(void)

{
  return;
}



// Function: FUN_1001aa8e at 1001aa8e

void FUN_1001aa8e(uint param_1)

{
  FUN_1001aa60(param_1);
  return;
}



// Function: FUN_1001aa97 at 1001aa97

void __cdecl FUN_1001aa97(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1001aaa5 at 1001aaa5

void __cdecl FUN_1001aaa5(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// Function: __allmul at 1001ab10

/* Library Function - Single Match
    __allmul
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2015 Debug */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



// Function: __alloca_probe_16 at 1001ab50

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio 2012 Release */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// Function: __alloca_probe_8 at 1001ab66

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



// Function: __alloca_probe at 1001ab80

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



// Function: FUN_1001abab at 1001abab

void __cdecl
FUN_1001abab(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10029830,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1001abde

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall CDaoRelationFieldInfo::`vector deleting destructor'(unsigned
   int)
    public: virtual void * __thiscall type_info::`vector deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

type_info * __thiscall FID_conflict__vector_deleting_destructor_(void *this,byte param_1)

{
  type_info *ptVar1;
  
  if ((param_1 & 2) == 0) {
    type_info::~type_info((type_info *)this);
    ptVar1 = (type_info *)this;
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    ptVar1 = (type_info *)((int)this + -4);
    _eh_vector_destructor_iterator_(this,0xc,*(int *)ptVar1,type_info::~type_info);
    if ((param_1 & 1) != 0) {
      operator_delete(ptVar1);
    }
  }
  return ptVar1;
}



// Function: __CRT_INIT@12 at 1001ace7

/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 2012 Release */

undefined4 __CRT_INIT_12(int *param_1,int *param_2,int *param_3)

{
  bool bVar1;
  void *pvVar2;
  void *pvVar3;
  int *_Memory;
  int *piVar4;
  PVOID pvVar5;
  code *pcVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  BOOL BVar10;
  
  if (param_2 == (int *)0x0) {
    if (DAT_10029cec < 1) {
      return 0;
    }
    DAT_10029cec = DAT_10029cec + -1;
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_10029d14 != (void *)0x0) {
        pvVar3 = DAT_10029d14;
        pvVar2 = DAT_10029d14;
      }
      DAT_10029d14 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_1001ad3a;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_1001ad3a:
    if (DAT_10029d18 == 2) {
      _Memory = (int *)DecodePointer(DAT_10029d24);
      if (_Memory != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10029d20);
        param_1 = piVar4;
        param_2 = _Memory;
        param_3 = _Memory;
        while (piVar4 = piVar4 + -1, _Memory <= piVar4) {
          if ((*piVar4 != 0) && (pvVar5 = EncodePointer((PVOID)0x0), (PVOID)*piVar4 != pvVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            pvVar5 = EncodePointer((PVOID)0x0);
            *piVar4 = (int)pvVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10029d24);
            piVar8 = (int *)DecodePointer(DAT_10029d20);
            if ((param_2 != piVar7) || (_Memory = param_3, param_1 != piVar8)) {
              piVar4 = piVar8;
              _Memory = piVar7;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        if (_Memory != (int *)0xffffffff) {
          free(_Memory);
        }
        DAT_10029d20 = EncodePointer((PVOID)0x0);
        DAT_10029d24 = DAT_10029d20;
      }
      DAT_10029d18 = 0;
      if (!bVar1) {
        LOCK();
        DAT_10029d14 = (void *)0x0;
        UNLOCK();
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_10029d14 != (void *)0x0) {
        pvVar3 = DAT_10029d14;
        pvVar2 = DAT_10029d14;
      }
      DAT_10029d14 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_1001ae55;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_1001ae55:
    if (DAT_10029d18 == 0) {
      DAT_10029d18 = 1;
      iVar9 = initterm_e(&DAT_1001f358,&DAT_1001f364);
      if (iVar9 != 0) {
        return 0;
      }
      initterm(&DAT_1001f318,&DAT_1001f354);
      DAT_10029d18 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      LOCK();
      DAT_10029d14 = (void *)0x0;
      UNLOCK();
    }
    if ((DAT_10029d1c != (code *)0x0) &&
       (BVar10 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10029d1c), BVar10 != 0)) {
      (*DAT_10029d1c)(param_1,2,param_3);
    }
    DAT_10029cec = DAT_10029cec + 1;
  }
  return 1;
}



// Function: entry at 1001aedc

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_1,param_2,param_3);
  return;
}



// Function: ___DllMainCRTStartup at 1001aeff

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001afb0) */
/* WARNING: Removing unreachable block (ram,0x1001af46) */
/* WARNING: Removing unreachable block (ram,0x1001afe2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2012 Release */

uint __cdecl ___DllMainCRTStartup(HMODULE param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  _DAT_10029874 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10029cec == 0)) {
    uVar1 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (uVar1 = __CRT_INIT_12(&param_1->unused,param_2,param_3), uVar1 != 0)) {
    uVar1 = FUN_100015a0(param_1,(int)param_2);
    if ((param_2 == (int *)0x1) && (uVar1 == 0)) {
      FUN_100015a0(param_1,0);
      __CRT_INIT_12(&param_1->unused,(int *)0x0,param_3);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar2 = __CRT_INIT_12(&param_1->unused,param_2,param_3);
      uVar1 = uVar1 & -(uint)(iVar2 != 0);
    }
  }
  FUN_1001b027();
  return uVar1;
}



// Function: FUN_1001b027 at 1001b027

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b027(void)

{
  _DAT_10029874 = 0xffffffff;
  return;
}



// Function: __SEH_prolog4 at 1001b060

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10029830 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1001b0a5

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



// Function: DebuggerProbe at 1001b0b9

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    int __cdecl DebuggerProbe(unsigned long)
   
   Library: Visual Studio 2012 Release */

int __cdecl DebuggerProbe(ulong param_1)

{
  ULONG_PTR local_38;
  ulong local_34;
  byte *local_30;
  byte local_1d [17];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x1001b0c5;
  local_1d[0] = 0;
  local_38 = 0x1001;
  local_34 = param_1;
  local_30 = local_1d;
  local_8 = 0;
  RaiseException(0x406d1388,0,6,&local_38);
  return (uint)local_1d[0];
}



// Function: DebuggerRuntime at 1001b11b

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    int __cdecl DebuggerRuntime(unsigned long,int,void *,wchar_t const *)
   
   Library: Visual Studio 2012 Release */

int __cdecl DebuggerRuntime(ulong param_1,int param_2,void *param_3,wchar_t *param_4)

{
  ULONG_PTR local_38;
  ulong local_34;
  int local_30;
  void *local_2c;
  byte *local_28;
  wchar_t *local_24;
  byte local_1d [17];
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x1001b127;
  local_1d[0] = 0;
  local_38 = 0x1002;
  local_34 = param_1;
  local_30 = param_2;
  local_2c = param_3;
  local_28 = local_1d;
  local_24 = param_4;
  local_8 = 0;
  RaiseException(0x406d1388,0,6,&local_38);
  return (uint)local_1d[0];
}



// Function: _RTC_AllocaFailure at 1001b18f

/* Library Function - Single Match
    void __cdecl _RTC_AllocaFailure(void *,struct _RTC_ALLOCA_NODE *,int)
   
   Library: Visual Studio 2012 Release */

void __cdecl _RTC_AllocaFailure(void *param_1,_RTC_ALLOCA_NODE *param_2,int param_3)

{
  int iVar1;
  HMODULE hModule;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined *puVar8;
  CHAR local_144 [244];
  char local_50 [52];
  char local_1c [20];
  uint local_8;
  
  iVar1 = DAT_10029870;
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  if (DAT_10029870 != -1) {
    hModule = LoadLibraryExW(L"user32.dll",(HANDLE)0x0,0x800);
    if ((((hModule == (HMODULE)0x0) &&
         ((DVar2 = GetLastError(), DVar2 != 0x57 ||
          (hModule = LoadLibraryW(L"user32.dll"), hModule == (HMODULE)0x0)))) ||
        (DAT_10029cf0 = GetProcAddress(hModule,"wsprintfA"), hModule == (HMODULE)0x0)) ||
       ((param_2 == (_RTC_ALLOCA_NODE *)0x0 || (DAT_10029cf0 == (FARPROC)0x0)))) {
      failwithmessage(param_1,iVar1,4,
                      "Stack area around _alloca memory reserved by this function is corrupted\n");
    }
    else {
      (*DAT_10029cf0)(local_144,"%s%s%p%s%ld%s%d%s",
                      "Stack area around _alloca memory reserved by this function is corrupted",
                      "\nAddress: 0x",param_2 + 0x20,"\nSize: ",*(int *)(param_2 + 0xc) + -0x24,
                      "\nAllocation number within this function: ",param_3,"\nData: <");
      _getMemBlockDataString
                (local_1c,local_50,(char *)(param_2 + 0x20),*(int *)(param_2 + 0xc) - 0x24);
      pcVar7 = local_50;
      puVar8 = &DAT_100237dc;
      puVar6 = &DAT_100237e0;
      pcVar5 = local_1c;
      pcVar4 = "%s%s%s%s";
      iVar3 = lstrlenA(local_144);
      (*DAT_10029cf0)(local_144 + iVar3,pcVar4,pcVar5,puVar6,pcVar7,puVar8);
      failwithmessage(param_1,iVar1,4,local_144);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: _RTC_Failure at 1001b2e6

/* Library Function - Single Match
    void __cdecl _RTC_Failure(void *,int)
   
   Library: Visual Studio 2012 Release */

void __cdecl _RTC_Failure(void *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  if ((uint)param_2 < 5) {
    iVar1 = *(int *)(&DAT_10029860 + param_2 * 4);
    pcVar2 = (&PTR_s_The_value_of_ESP_was_not_properl_100232b4)[param_2];
  }
  else {
    pcVar2 = "Unknown Runtime Check Error\n\r";
    iVar1 = 1;
    param_2 = 5;
  }
  if (iVar1 != -1) {
    failwithmessage(param_1,iVar1,param_2,pcVar2);
  }
  return;
}



// Function: _RTC_StackFailure at 1001b322

/* Library Function - Single Match
    void __cdecl _RTC_StackFailure(void *,char const *)
   
   Library: Visual Studio 2012 Release */

void __cdecl _RTC_StackFailure(void *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 local_40c;
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_40c = param_1;
  if (DAT_10029868 == -1) goto LAB_1001b402;
  if (*param_2 == '\0') {
LAB_1001b3e4:
    pcVar2 = "Stack corrupted near unknown variable";
  }
  else {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((char *)0x400 < pcVar2 + (0x2d - (int)(param_2 + 1))) goto LAB_1001b3e4;
    pcVar2 = local_408;
    iVar3 = 0;
    do {
      cVar1 = "Stack around the variable \'"[iVar3];
      local_408[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      pcVar5 = param_2;
    } while (cVar1 != '\0');
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar6 = (int)pcVar5 - (int)param_2;
    pcVar5 = (char *)((int)&local_40c + 3);
    do {
      pcVar7 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar7 != '\0');
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *param_2;
      param_2 = param_2 + 1;
      pcVar5 = pcVar5 + 1;
    }
    pcVar5 = "\' was corrupted.";
    do {
      pcVar7 = pcVar5;
      pcVar5 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    pcVar5 = (char *)((int)&local_40c + 3);
    do {
      pcVar8 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar8 != '\0');
    pcVar8 = "\' was corrupted.";
    for (uVar6 = (uint)(pcVar7 + -0x10023263) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = (uint)(pcVar7 + -0x10023263) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  failwithmessage(param_1,DAT_10029868,2,pcVar2);
LAB_1001b402:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: _getMemBlockDataString at 1001b40e

/* Library Function - Single Match
    void __cdecl _getMemBlockDataString(char *,char *,char *,unsigned int)
   
   Library: Visual Studio 2012 Release */

void __cdecl _getMemBlockDataString(char *param_1,char *param_2,char *param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0;
  pcVar3 = param_2;
  pcVar5 = param_1;
  while( true ) {
    uVar2 = param_4;
    if (0xf < param_4) {
      uVar2 = 0x10;
    }
    if (uVar2 <= uVar4) break;
    cVar1 = pcVar5[(int)param_3 - (int)param_1];
    (*DAT_10029cf0)(pcVar3,"%.2X ",cVar1);
    *pcVar5 = cVar1;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 3;
    pcVar5 = pcVar5 + 1;
  }
  param_1[uVar4] = '\0';
  param_2[uVar4 * 3] = '\0';
  return;
}



// Function: failwithmessage at 1001b477

/* Library Function - Single Match
    void __cdecl failwithmessage(void *,int,int,char const *)
   
   Library: Visual Studio 2012 Release */

void __cdecl failwithmessage(void *param_1,int param_2,int param_3,char *param_4)

{
  bool bVar1;
  code *pcVar2;
  uint cchWideChar;
  int iVar3;
  BOOL BVar4;
  char *pcVar5;
  char *pcVar6;
  int local_e40;
  code *local_e3c;
  char *local_e38;
  wchar_t *local_e34;
  WCHAR local_e30 [512];
  CHAR local_a30 [780];
  CHAR local_724 [780];
  wchar_t local_418 [260];
  wchar_t local_210 [260];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  local_e3c = (code *)0x0;
  local_e38 = param_4;
  pcVar2 = (code *)FUN_1001b744();
  if (pcVar2 == (code *)0x0) {
    local_e3c = (code *)FUN_1001b73e();
  }
  cchWideChar = MultiByteToWideChar(0xfde9,0,local_e38,-1,(LPWSTR)0x0,0);
  if (cchWideChar < 0x200) {
    iVar3 = MultiByteToWideChar(0xfde9,0,local_e38,-1,local_e30,cchWideChar);
    if (iVar3 == 0) goto LAB_1001b50b;
    local_e34 = local_e30;
  }
  else {
LAB_1001b50b:
    local_e34 = L"Runtime Check Error.\n\r Unable to display RTC Message.";
  }
  iVar3 = DebuggerProbe(0x1002);
  if (iVar3 == 0) {
    bVar1 = true;
  }
  else {
    iVar3 = DebuggerRuntime(param_3,*(int *)(&DAT_100232cc + param_3 * 4),param_1,local_e34);
    if (iVar3 != 0) goto LAB_1001b650;
    bVar1 = false;
  }
  if ((local_e3c != (code *)0x0) || (pcVar2 != (code *)0x0)) {
    if (bVar1) {
      BVar4 = IsDebuggerPresent();
      if (BVar4 != 0) goto LAB_1001b64f;
    }
    _RTC_GetSrcLine((uchar *)((int)param_1 + -5),local_210,0x104,&local_e40,local_418,0x104);
    if (pcVar2 == (code *)0x0) {
      pcVar6 = "Unknown Filename";
      iVar3 = WideCharToMultiByte(0xfde9,0,local_210,-1,local_724,0x30a,(LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar3 != 0) {
        pcVar6 = local_724;
      }
      pcVar5 = "Unknown Module Name";
      iVar3 = WideCharToMultiByte(0xfde9,0,local_418,-1,local_a30,0x30a,(LPCSTR)0x0,(LPBOOL)0x0);
      if (iVar3 != 0) {
        pcVar5 = local_a30;
      }
      iVar3 = (*local_e3c)(param_2,pcVar6,local_e40,pcVar5,"Run-Time Check Failure #%d - %s",param_3
                           ,local_e38);
    }
    else {
      iVar3 = (*pcVar2)(param_2,local_210,local_e40,local_418,L"Run-Time Check Failure #%d - %s",
                        param_3,local_e34);
    }
    if (iVar3 != 1) {
LAB_1001b650:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_1001b64f:
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



// Function: __RTC_UninitUse at 1001b65f

/* Library Function - Single Match
    __RTC_UninitUse
   
   Library: Visual Studio 2012 Release */

void __cdecl __RTC_UninitUse(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  void *unaff_retaddr;
  char local_408 [1024];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  if (DAT_1002986c == -1) goto LAB_1001b732;
  if (param_1 == (char *)0x0) {
LAB_1001b717:
    pcVar2 = "A variable is being used without being initialized.";
  }
  else {
    pcVar2 = param_1;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((char *)0x400 < pcVar2 + (0x3a - (int)(param_1 + 1))) goto LAB_1001b717;
    pcVar2 = local_408;
    iVar3 = 0;
    do {
      cVar1 = "The variable \'"[iVar3];
      local_408[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
      pcVar5 = param_1;
    } while (cVar1 != '\0');
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar6 = (int)pcVar5 - (int)param_1;
    pcVar5 = &stack0xfffffbf7;
    do {
      pcVar7 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar7 != '\0');
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *param_1;
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
    }
    pcVar5 = "\' is being used without being initialized.";
    do {
      pcVar7 = pcVar5;
      pcVar5 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    pcVar5 = &stack0xfffffbf7;
    do {
      pcVar8 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar8 != '\0');
    pcVar8 = "\' is being used without being initialized.";
    for (uVar6 = (uint)(pcVar7 + -0x10023287) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = (uint)(pcVar7 + -0x10023287) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  failwithmessage(unaff_retaddr,DAT_1002986c,3,pcVar2);
LAB_1001b732:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001b73e at 1001b73e

undefined4 FUN_1001b73e(void)

{
  return DAT_10029cf4;
}



// Function: FUN_1001b744 at 1001b744

undefined4 FUN_1001b744(void)

{
  return DAT_10029cf8;
}



// Function: FUN_1001b74a at 1001b74a

undefined * __cdecl FUN_1001b74a(uint param_1)

{
  if (param_1 < 5) {
    return (&PTR_s_Stack_pointer_corruption_10023824)[param_1];
  }
  return (undefined *)0x0;
}



// Function: FUN_1001b766 at 1001b766

undefined4 __cdecl FUN_1001b766(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10029cf4;
  DAT_10029cf8 = 0;
  DAT_10029cf4 = param_1;
  return uVar1;
}



// Function: FUN_1001b780 at 1001b780

undefined4 __cdecl FUN_1001b780(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_10029cf8;
  DAT_10029cf4 = 0;
  DAT_10029cf8 = param_1;
  return uVar1;
}



// Function: __RTC_SetErrorType at 1001b79a

/* Library Function - Single Match
    __RTC_SetErrorType
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 __cdecl __RTC_SetErrorType(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 5) {
    uVar1 = *(undefined4 *)(&DAT_10029860 + param_1 * 4);
    *(undefined4 *)(&DAT_10029860 + param_1 * 4) = param_2;
    return uVar1;
  }
  return 0xffffffff;
}



// Function: __EH_epilog3 at 1001b7ee

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



// Function: __EH_prolog3_catch at 1001b889

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10029830 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __FindPESection at 1001b910

/* Library Function - Single Match
    __FindPESection
   
   Library: Visual Studio 2012 Release */

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



// Function: __IsNonwritableInCurrentImage at 1001b960

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2012 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_1001abab;
  local_14 = ExceptionList;
  local_c = DAT_10029830 ^ 0x10026dc8;
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



// Function: __ValidateImageBase at 1001ba20

/* Library Function - Single Match
    __ValidateImageBase
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  uint uVar1;
  
  if (*(short *)pImageBase != 0x5a4d) {
    return 0;
  }
  uVar1 = 0;
  if (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550) {
    uVar1 = (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b)
    ;
  }
  return uVar1;
}



// Function: ___security_init_cookie at 1001ba51

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2012 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_18;
  _FILETIME local_10;
  uint local_8;
  
  local_10.dwLowDateTime = 0;
  local_10.dwHighDateTime = 0;
  if ((DAT_10029830 == 0xbb40e64e) || ((DAT_10029830 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_10029830 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_10029830 == 0xbb40e64e) {
      DAT_10029830 = 0xbb40e64f;
    }
    else if ((DAT_10029830 & 0xffff0000) == 0) {
      DAT_10029830 = DAT_10029830 | (DAT_10029830 | 0x4711) << 0x10;
    }
    DAT_10029834 = ~DAT_10029830;
  }
  else {
    DAT_10029834 = ~DAT_10029830;
  }
  return;
}



// Function: GetPdbDllFromInstallPath at 1001bb62

/* Library Function - Single Match
    struct HINSTANCE__ * __cdecl GetPdbDllFromInstallPath(void)
   
   Library: Visual Studio 2012 Release */

HINSTANCE__ * __cdecl GetPdbDllFromInstallPath(void)

{
  HMODULE pHVar1;
  DWORD DVar2;
  FARPROC pFVar3;
  FARPROC pFVar4;
  int iVar5;
  HINSTANCE__ *pHVar6;
  uint uVar7;
  uint uVar8;
  wchar_t *pwVar9;
  WCHAR *pWVar10;
  int local_220;
  FARPROC local_21c;
  undefined4 local_218;
  uint local_214;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_10029830 ^ (uint)&stack0xfffffffc;
  pHVar1 = LoadLibraryExW(L"ADVAPI32.DLL",(HANDLE)0x0,0x800);
  if ((((pHVar1 != (HMODULE)0x0) ||
       ((DVar2 = GetLastError(), DVar2 == 0x57 &&
        (pHVar1 = LoadLibraryW(L"ADVAPI32.DLL"), pHVar1 != (HMODULE)0x0)))) &&
      (pFVar3 = GetProcAddress(pHVar1,"RegOpenKeyExW"), pFVar3 != (FARPROC)0x0)) &&
     ((local_21c = GetProcAddress(pHVar1,"RegQueryValueExW"), local_21c != (FARPROC)0x0 &&
      (pFVar4 = GetProcAddress(pHVar1,"RegCloseKey"), pFVar4 != (FARPROC)0x0)))) {
    iVar5 = (*pFVar3)(0x80000002,L"SOFTWARE\\Microsoft\\VisualStudio\\11.0\\Setup\\VS",0,1,
                      &local_218);
    if (iVar5 == 0) {
      local_214 = 0x208;
      iVar5 = (*local_21c)(local_218,L"EnvironmentDirectory",0,&local_220,local_210,&local_214);
      (*pFVar4)(local_218);
      FreeLibrary(pHVar1);
      if ((((iVar5 == 0) && (local_220 == 1)) && ((local_214 & 1) == 0)) &&
         ((uVar7 = local_214 >> 1, 1 < uVar7 && (uVar8 = uVar7 - 1, local_210[uVar8] == L'\0')))) {
        if (local_210[uVar7 - 2] != L'\\') {
          local_210[uVar8] = L'\\';
          uVar8 = uVar7;
        }
        if ((0xd < -uVar8 - 1) && (uVar8 + 0xd < 0x105)) {
          pwVar9 = L"MSPDB110.DLL";
          pWVar10 = local_210 + uVar8;
          for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined4 *)pWVar10 = *(undefined4 *)pwVar9;
            pwVar9 = pwVar9 + 2;
            pWVar10 = pWVar10 + 2;
          }
          *pWVar10 = *pwVar9;
          pHVar1 = LoadLibraryExW(local_210,(HANDLE)0x0,0x900);
          if ((pHVar1 == (HMODULE)0x0) && (DVar2 = GetLastError(), DVar2 == 0x57)) {
            LoadLibraryExW(local_210,(HANDLE)0x0,8);
          }
        }
      }
    }
    else {
      FreeLibrary(pHVar1);
    }
  }
  pHVar6 = (HINSTANCE__ *)__security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return pHVar6;
}



// Function: _RTC_GetSrcLine at 1001bd15

/* Library Function - Single Match
    int __cdecl _RTC_GetSrcLine(unsigned char *,wchar_t *,unsigned long,int *,wchar_t *,unsigned
   long)
   
   Library: Visual Studio 2012 Release */

int __cdecl
_RTC_GetSrcLine(uchar *param_1,wchar_t *param_2,ulong param_3,int *param_4,wchar_t *param_5,
               ulong param_6)

{
  char cVar1;
  SIZE_T SVar2;
  DWORD DVar3;
  uint *puVar4;
  FARPROC pFVar5;
  int iVar6;
  HANDLE pvVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uchar *lpAddress;
  uint uVar11;
  int iVar12;
  uint uVar13;
  _MEMORY_BASIC_INFORMATION local_48;
  undefined1 local_2c [4];
  undefined4 local_28;
  int local_24;
  int *local_20;
  int local_1c;
  uint local_18;
  int *local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  *param_4 = 0;
  *param_2 = L'\0';
  lpAddress = param_1 + -1;
  SVar2 = VirtualQuery(lpAddress,&local_48,0x1c);
  if ((((SVar2 == 0) ||
       (DVar3 = GetModuleFileNameW((HMODULE)local_48.AllocationBase,param_5,param_6), DVar3 == 0))
      || ((short)*(int *)local_48.AllocationBase != 0x5a4d)) ||
     ((((HMODULE)((int)local_48.AllocationBase + 0x3c))->unused < 1 ||
      (piVar8 = (int *)((int)(int *)local_48.AllocationBase +
                       ((HMODULE)((int)local_48.AllocationBase + 0x3c))->unused), *piVar8 != 0x4550)
      ))) {
    return 0;
  }
  uVar9 = (uint)*(ushort *)((int)piVar8 + 6);
  uVar11 = (int)lpAddress - (int)local_48.AllocationBase;
  uVar10 = 0;
  uVar13 = 0;
  if (uVar9 != 0) {
    puVar4 = (uint *)(*(ushort *)(piVar8 + 5) + 0x24 + (int)piVar8);
    do {
      if ((*puVar4 <= uVar11) && (uVar10 = uVar11 - *puVar4, uVar11 < puVar4[-1])) break;
      uVar13 = uVar13 + 1;
      puVar4 = puVar4 + 10;
    } while (uVar13 < uVar9);
  }
  if (uVar13 == uVar9) {
    return 0;
  }
  if (DAT_10029d09 == '\0') {
    if (DAT_10029d04 != (HMODULE)0x0) {
      return 0;
    }
    if (DAT_10029d08 == '\0') {
      DAT_10029d08 = '\x01';
      DAT_10029d04 = GetPdbDllFromInstallPath();
    }
    else {
      DAT_10029d04 = (HMODULE)0x0;
    }
    if (DAT_10029d04 == (HMODULE)0x0) {
      return 0;
    }
    DAT_10029d09 = '\x01';
  }
  pFVar5 = GetProcAddress(DAT_10029d04,"PDBOpenValidate5");
  if (pFVar5 != (FARPROC)0x0) {
    iVar12 = 0;
    iVar6 = (*pFVar5)(param_5,0,0,0,local_2c,0,0,&local_14);
    if (iVar6 != 0) {
      local_1c = 0;
      iVar6 = (**(code **)*local_14)();
      if ((iVar6 == 0x1329141) &&
         (iVar6 = (**(code **)(*local_14 + 0x1c))(0,&DAT_10023a1c,&local_20), iVar6 != 0)) {
        iVar6 = (**(code **)(*local_20 + 0x20))(uVar13 + 1,uVar10,&local_10,0,0,0);
        if (iVar6 != 0) {
          local_8 = (int *)0x0;
          cVar1 = (**(code **)(*local_10 + 0x68))(&local_8);
          if ((cVar1 != '\0') && (local_8 != (int *)0x0)) {
            puVar4 = (uint *)0x0;
            do {
              iVar12 = (**(code **)(*local_8 + 8))();
              if (iVar12 == 0) goto LAB_1001becd;
              cVar1 = (**(code **)(*local_8 + 0xc))(0,&local_18,&param_1,&local_24,&local_c,0);
              if (cVar1 == '\0') goto LAB_1001bedc;
            } while (((((uint)param_1 & 0xffff) != uVar13 + 1) || (uVar10 < local_18)) ||
                    (local_24 + local_18 <= uVar10));
            if ((local_c != 0) && (local_c < 0x1fffffff)) {
              SVar2 = local_c << 3;
              DVar3 = 0;
              pvVar7 = GetProcessHeap();
              puVar4 = (uint *)HeapAlloc(pvVar7,DVar3,SVar2);
              if (puVar4 != (uint *)0x0) {
                cVar1 = (**(code **)(*local_8 + 0xc))(&local_28,0,0,0,&local_c,puVar4);
                if ((cVar1 != '\0') && (*puVar4 <= uVar10 - local_18)) {
                  uVar9 = 1;
                  if (1 < local_c) {
                    do {
                      if (uVar10 - local_18 < puVar4[uVar9 * 2]) break;
                      uVar9 = uVar9 + 1;
                    } while (uVar9 < local_c);
                  }
                  *param_4 = puVar4[uVar9 * 2 + -1] & 0xffffff;
                  cVar1 = (**(code **)(*local_10 + 0x70))(local_28,param_2,&param_3,0,0,0);
                  if (cVar1 != '\0') {
                    local_1c = 1;
                  }
                }
LAB_1001becd:
                DVar3 = 0;
                pvVar7 = GetProcessHeap();
                HeapFree(pvVar7,DVar3,puVar4);
              }
            }
LAB_1001bedc:
            (**(code **)*local_8)();
            iVar12 = local_1c;
          }
          (**(code **)(*local_10 + 0x40))();
        }
        (**(code **)(*local_20 + 0x38))();
      }
      (**(code **)(*local_14 + 0x2c))();
      return iVar12;
    }
  }
  return 0;
}



// Function: ~_Fac_node at 1001bfda

/* Library Function - Single Match
    public: __thiscall std::_Fac_node::~_Fac_node(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall std::_Fac_node::~_Fac_node(_Fac_node *this)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(this + 4) + 8))();
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  return;
}



// Function: FUN_1001bfef at 1001bfef

void FUN_1001bfef(void)

{
  _Fac_node *this;
  
  while (this = DAT_10029d0c, DAT_10029d0c != (_Fac_node *)0x0) {
    DAT_10029d0c = *(_Fac_node **)DAT_10029d0c;
    std::_Fac_node::~_Fac_node(this);
    operator_delete(this);
  }
  return;
}



// Function: `scalar_deleting_destructor' at 1001c013

/* Library Function - Single Match
    public: void * __thiscall std::_Fac_node::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

void * __thiscall std::_Fac_node::_scalar_deleting_destructor_(_Fac_node *this,uint param_1)

{
  ~_Fac_node(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: Facet_Register at 1001c032

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
    *puVar1 = DAT_10029d0c;
    puVar1[1] = param_1;
  }
  DAT_10029d0c = puVar1;
  return;
}



// Function: Unwind@1001c1d0 at 1001c1d0

void Unwind_1001c1d0(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c200 at 1001c200

void Unwind_1001c200(void)

{
  FUN_10003bc0();
  return;
}



// Function: Unwind@1001c230 at 1001c230

void Unwind_1001c230(void)

{
  int unaff_EBP;
  
  CPropertySet::~CPropertySet(*(CPropertySet **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c260 at 1001c260

void Unwind_1001c260(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>();
  return;
}



// Function: Unwind@1001c26b at 1001c26b

void Unwind_1001c26b(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c2a0 at 1001c2a0

void Unwind_1001c2a0(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c2d0 at 1001c2d0

void Unwind_1001c2d0(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c300 at 1001c300

void Unwind_1001c300(void)

{
  int unaff_EBP;
  
  FUN_10003710(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c330 at 1001c330

void Unwind_1001c330(void)

{
  FUN_10003810();
  return;
}



// Function: Unwind@1001c338 at 1001c338

void Unwind_1001c338(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            ((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c360 at 1001c360

void Unwind_1001c360(void)

{
  FUN_10003810();
  return;
}



// Function: Unwind@1001c390 at 1001c390

void Unwind_1001c390(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c3c0 at 1001c3c0

void Unwind_1001c3c0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c3f0 at 1001c3f0

void Unwind_1001c3f0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c420 at 1001c420

void Unwind_1001c420(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c450 at 1001c450

void Unwind_1001c450(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c480 at 1001c480

void Unwind_1001c480(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c4b0 at 1001c4b0

void Unwind_1001c4b0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_COM_MODULE70::~_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)(*(int *)(unaff_EBP + -0x10) + 4))
  ;
  return;
}



// Function: Unwind@1001c4e0 at 1001c4e0

void Unwind_1001c4e0(void)

{
  int unaff_EBP;
  
  FUN_10003830(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c510 at 1001c510

void Unwind_1001c510(void)

{
  int unaff_EBP;
  
  FUN_100030e0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001c540 at 1001c540

void Unwind_1001c540(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(CPropertySet **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c570 at 1001c570

void Unwind_1001c570(void)

{
  int unaff_EBP;
  
  ATL::CComCriticalSection::~CComCriticalSection(*(CComCriticalSection **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c5a0 at 1001c5a0

void Unwind_1001c5a0(void)

{
  int unaff_EBP;
  
  FUN_10003520(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c5d0 at 1001c5d0

void Unwind_1001c5d0(void)

{
  int unaff_EBP;
  
  FID_conflict__CPaneContainerGC((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c600 at 1001c600

void Unwind_1001c600(void)

{
  int unaff_EBP;
  
  ATL::CComCriticalSection::~CComCriticalSection
            ((CComCriticalSection *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001c630 at 1001c630

void Unwind_1001c630(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c660 at 1001c660

void Unwind_1001c660(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c690 at 1001c690

void Unwind_1001c690(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c6c0 at 1001c6c0

void Unwind_1001c6c0(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c6f0 at 1001c6f0

void Unwind_1001c6f0(void)

{
  int unaff_EBP;
  
  CPropertySet::~CPropertySet(*(CPropertySet **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c720 at 1001c720

void Unwind_1001c720(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>();
  return;
}



// Function: Unwind@1001c72b at 1001c72b

void Unwind_1001c72b(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001c760 at 1001c760

void Unwind_1001c760(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c790 at 1001c790

void Unwind_1001c790(void)

{
  int unaff_EBP;
  
  FUN_10010090(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c7c0 at 1001c7c0

void Unwind_1001c7c0(void)

{
  int unaff_EBP;
  
  FUN_10003710(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c7f0 at 1001c7f0

void Unwind_1001c7f0(void)

{
  FUN_10003810();
  return;
}



// Function: Unwind@1001c7f8 at 1001c7f8

void Unwind_1001c7f8(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            ((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c820 at 1001c820

void Unwind_1001c820(void)

{
  FUN_10003810();
  return;
}



// Function: Unwind@1001c850 at 1001c850

void Unwind_1001c850(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c880 at 1001c880

void Unwind_1001c880(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c8b0 at 1001c8b0

void Unwind_1001c8b0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c8e0 at 1001c8e0

void Unwind_1001c8e0(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c910 at 1001c910

void Unwind_1001c910(void)

{
  int unaff_EBP;
  
  FID_conflict__CComPtrBase<struct_IAccessibleProxy>(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c940 at 1001c940

void Unwind_1001c940(void)

{
  int unaff_EBP;
  
  ATL::_ATL_COM_MODULE70::~_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)(*(int *)(unaff_EBP + -0x10) + 4))
  ;
  return;
}



// Function: Unwind@1001c970 at 1001c970

void Unwind_1001c970(void)

{
  int unaff_EBP;
  
  FUN_10003830(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c9a0 at 1001c9a0

void Unwind_1001c9a0(void)

{
  int unaff_EBP;
  
  FUN_100030e0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001c9d0 at 1001c9d0

void Unwind_1001c9d0(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(CPropertySet **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ca00 at 1001ca00

void Unwind_1001ca00(void)

{
  int unaff_EBP;
  
  ATL::CComCriticalSection::~CComCriticalSection(*(CComCriticalSection **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ca30 at 1001ca30

void Unwind_1001ca30(void)

{
  int unaff_EBP;
  
  FUN_10003520(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ca60 at 1001ca60

void Unwind_1001ca60(void)

{
  int unaff_EBP;
  
  FID_conflict__CPaneContainerGC((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001ca90 at 1001ca90

void Unwind_1001ca90(void)

{
  int unaff_EBP;
  
  ATL::CComCriticalSection::~CComCriticalSection
            ((CComCriticalSection *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001cac0 at 1001cac0

void Unwind_1001cac0(void)

{
  int unaff_EBP;
  
  FID_conflict__CRectTracker(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001caf0 at 1001caf0

void Unwind_1001caf0(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb20 at 1001cb20

void Unwind_1001cb20(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>
            (*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001cb50 at 1001cb50

void Unwind_1001cb50(void)

{
  int unaff_EBP;
  
  ~CAutoVectorPtr<>((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001cb58 at 1001cb58

void Unwind_1001cb58(void)

{
  int unaff_EBP;
  
  ~CAutoVectorPtr<>((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001cb80 at 1001cb80

void Unwind_1001cb80(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001cbb0 at 1001cbb0

void Unwind_1001cbb0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001cbe0 at 1001cbe0

void Unwind_1001cbe0(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x1144));
  return;
}



// Function: Unwind@1001cbeb at 1001cbeb

void Unwind_1001cbeb(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1180));
  return;
}



// Function: Unwind@1001cbf6 at 1001cbf6

void Unwind_1001cbf6(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x1298));
  return;
}



// Function: Unwind@1001cc30 at 1001cc30

void Unwind_1001cc30(void)

{
  int unaff_EBP;
  
  FUN_10002f70((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001cc60 at 1001cc60

void Unwind_1001cc60(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001cc90 at 1001cc90

void Unwind_1001cc90(void)

{
  int unaff_EBP;
  
  FUN_10002f70((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ccc0 at 1001ccc0

void Unwind_1001ccc0(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ccc8 at 1001ccc8

void Unwind_1001ccc8(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001ccd3 at 1001ccd3

void Unwind_1001ccd3(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x184));
  return;
}



// Function: Unwind@1001ccde at 1001ccde

void Unwind_1001ccde(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x198));
  return;
}



// Function: Unwind@1001cd20 at 1001cd20

void Unwind_1001cd20(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cd28 at 1001cd28

void Unwind_1001cd28(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001cd30 at 1001cd30

void Unwind_1001cd30(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@1001cd70 at 1001cd70

void Unwind_1001cd70(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001cd78 at 1001cd78

void Unwind_1001cd78(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001cda0 at 1001cda0

void Unwind_1001cda0(void)

{
  int unaff_EBP;
  
  FUN_1001aa97(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001cdd0 at 1001cdd0

void Unwind_1001cdd0(void)

{
  int unaff_EBP;
  
  FUN_1001aa97(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ce00 at 1001ce00

void Unwind_1001ce00(void)

{
  int unaff_EBP;
  
  FUN_1001aa97(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ce30 at 1001ce30

void Unwind_1001ce30(void)

{
  int unaff_EBP;
  
  FUN_10002f70((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ce60 at 1001ce60

void Unwind_1001ce60(void)

{
  int unaff_EBP;
  
  FUN_10002f70((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ce68 at 1001ce68

void Unwind_1001ce68(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x164));
  return;
}



// Function: Unwind@1001ce73 at 1001ce73

void Unwind_1001ce73(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x174));
  return;
}



// Function: Unwind@1001ce7e at 1001ce7e

void Unwind_1001ce7e(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x180));
  return;
}



// Function: Unwind@1001ce89 at 1001ce89

void Unwind_1001ce89(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x18c));
  return;
}



// Function: Unwind@1001cec0 at 1001cec0

void Unwind_1001cec0(void)

{
  FUN_10001620();
  return;
}



// Function: Unwind@1001ced9 at 1001ced9

void Unwind_1001ced9(void)

{
  FUN_10001630();
  return;
}



// Function: Unwind@1001cf10 at 1001cf10

void Unwind_1001cf10(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001cf18 at 1001cf18

void Unwind_1001cf18(void)

{
  int unaff_EBP;
  
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001cf40 at 1001cf40

void Unwind_1001cf40(void)

{
  int unaff_EBP;
  
  FUN_1001aaa5(*(void **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001cf52 at 1001cf52

void Unwind_1001cf52(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001cf80 at 1001cf80

void Unwind_1001cf80(void)

{
  int unaff_EBP;
  
  FUN_10003920(unaff_EBP + -0x28);
  return;
}



// Function: Unwind@1001cfb0 at 1001cfb0

void Unwind_1001cfb0(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001cfe0 at 1001cfe0

void Unwind_1001cfe0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001cfe8 at 1001cfe8

void Unwind_1001cfe8(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x46c));
  return;
}



// Function: Unwind@1001d020 at 1001d020

void Unwind_1001d020(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001d028 at 1001d028

void Unwind_1001d028(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x158));
  return;
}



// Function: Unwind@1001d033 at 1001d033

void Unwind_1001d033(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x1174));
  return;
}



// Function: Unwind@1001d03e at 1001d03e

void Unwind_1001d03e(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x1188));
  return;
}



// Function: Unwind@1001d049 at 1001d049

void Unwind_1001d049(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::~CRegKey((CRegKey *)(unaff_EBP + -0x11a0));
  return;
}



// Function: Unwind@1001d080 at 1001d080

void Unwind_1001d080(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d0b0 at 1001d0b0

void Unwind_1001d0b0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d0e0 at 1001d0e0

void Unwind_1001d0e0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d110 at 1001d110

void Unwind_1001d110(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d140 at 1001d140

void Unwind_1001d140(void)

{
  int unaff_EBP;
  
  FUN_10003990((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d148 at 1001d148

void Unwind_1001d148(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d180 at 1001d180

void Unwind_1001d180(void)

{
  int unaff_EBP;
  
  FUN_10003990((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001d188 at 1001d188

void Unwind_1001d188(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d1c0 at 1001d1c0

void Unwind_1001d1c0(void)

{
  DAT_100298cc = DAT_100298cc & 0xfffffffe;
  return;
}



// Function: Unwind@1001d210 at 1001d210

void Unwind_1001d210(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    CControlBar::OnInitialUpdate(*(CControlBar **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001d250 at 1001d250

void Unwind_1001d250(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    CControlBar::OnInitialUpdate(*(CControlBar **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001d290 at 1001d290

void Unwind_1001d290(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    CControlBar::OnInitialUpdate(*(CControlBar **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001d2d0 at 1001d2d0

void Unwind_1001d2d0(void)

{
  int unaff_EBP;
  
  FUN_100030e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001d2db at 1001d2db

void Unwind_1001d2db(void)

{
  int unaff_EBP;
  
  FID_conflict__CPaneContainerGC((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001d2e6 at 1001d2e6

void Unwind_1001d2e6(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@1001d2f1 at 1001d2f1

void Unwind_1001d2f1(void)

{
  int unaff_EBP;
  
  FUN_100140b0(*(int *)(unaff_EBP + -0x10) + 0x50);
  return;
}



// Function: Unwind@1001d317 at 1001d317

void Unwind_1001d317(void)

{
  int unaff_EBP;
  
  FUN_100030e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001d322 at 1001d322

void Unwind_1001d322(void)

{
  int unaff_EBP;
  
  FID_conflict__CPaneContainerGC((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001d32d at 1001d32d

void Unwind_1001d32d(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@1001d338 at 1001d338

void Unwind_1001d338(void)

{
  int unaff_EBP;
  
  FUN_100140b0(*(int *)(unaff_EBP + -0x10) + 0x50);
  return;
}



// Function: Unwind@1001d35e at 1001d35e

void Unwind_1001d35e(void)

{
  int unaff_EBP;
  
  FUN_10013940((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d366 at 1001d366

void Unwind_1001d366(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001d389 at 1001d389

void Unwind_1001d389(void)

{
  int unaff_EBP;
  
  FUN_10013940((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d391 at 1001d391

void Unwind_1001d391(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001d3b4 at 1001d3b4

void Unwind_1001d3b4(void)

{
  int unaff_EBP;
  
  FUN_10013940((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d3bc at 1001d3bc

void Unwind_1001d3bc(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001d3df at 1001d3df

void Unwind_1001d3df(void)

{
  int unaff_EBP;
  
  FUN_10013940((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001d3e7 at 1001d3e7

void Unwind_1001d3e7(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x480));
  return;
}



// Function: Unwind@1001d41a at 1001d41a

void Unwind_1001d41a(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001d43d at 1001d43d

void Unwind_1001d43d(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001d460 at 1001d460

void Unwind_1001d460(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001d483 at 1001d483

void Unwind_1001d483(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001d4a6 at 1001d4a6

void Unwind_1001d4a6(void)

{
  int unaff_EBP;
  
  FUN_10013940((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001d4ae at 1001d4ae

void Unwind_1001d4ae(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001d4e1 at 1001d4e1

void Unwind_1001d4e1(void)

{
  int unaff_EBP;
  
  FUN_10013940((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001d4e9 at 1001d4e9

void Unwind_1001d4e9(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001d4f1 at 1001d4f1

void Unwind_1001d4f1(void)

{
  int unaff_EBP;
  
  FUN_100140b0(unaff_EBP + -0x504);
  return;
}



// Function: Unwind@1001d4fc at 1001d4fc

void Unwind_1001d4fc(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x52c));
  return;
}



// Function: Unwind@1001d52f at 1001d52f

void Unwind_1001d52f(void)

{
  int unaff_EBP;
  
  CControlBar::OnInitialUpdate((CControlBar *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001d537 at 1001d537

void Unwind_1001d537(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001d53f at 1001d53f

void Unwind_1001d53f(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001d56f at 1001d56f

void Unwind_1001d56f(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d577 at 1001d577

void Unwind_1001d577(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001d59a at 1001d59a

void Unwind_1001d59a(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001d5a2 at 1001d5a2

void Unwind_1001d5a2(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001d5c5 at 1001d5c5

void Unwind_1001d5c5(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001d5f0 at 1001d5f0

void Unwind_1001d5f0(void)

{
  FUN_10003bc0();
  return;
}



// Function: Unwind@1001d620 at 1001d620

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d620(void)

{
  int unaff_EBP;
  
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001d650 at 1001d650

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d650(void)

{
  int unaff_EBP;
  
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d680 at 1001d680

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d680(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    ~basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x78));
    return;
  }
  return;
}



// Function: Unwind@1001d6a6 at 1001d6a6

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d6a6(void)

{
  int unaff_EBP;
  
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@1001d6bb at 1001d6bb

void Unwind_1001d6bb(void)

{
  int unaff_EBP;
  
  FUN_10013970((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001d6f0 at 1001d6f0

void Unwind_1001d6f0(void)

{
  int unaff_EBP;
  
  ATL::CComCriticalSection::~CComCriticalSection(*(CComCriticalSection **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d720 at 1001d720

void Unwind_1001d720(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d750 at 1001d750

void Unwind_1001d750(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d780 at 1001d780

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d780(void)

{
  int unaff_EBP;
  
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d7b0 at 1001d7b0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void Unwind_1001d7b0(void)

{
  int unaff_EBP;
  
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1001d7c5 at 1001d7c5

void Unwind_1001d7c5(void)

{
  int unaff_EBP;
  
  FUN_10013970((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x60));
  return;
}



// Function: Unwind@1001d7f0 at 1001d7f0

void Unwind_1001d7f0(void)

{
  int unaff_EBP;
  
  ATL::CComCriticalSection::~CComCriticalSection(*(CComCriticalSection **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d820 at 1001d820

void Unwind_1001d820(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d850 at 1001d850

void Unwind_1001d850(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d8a0 at 1001d8a0

void Unwind_1001d8a0(void)

{
  int unaff_EBP;
  
  CControlBar::OnInitialUpdate((CControlBar *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001d8d0 at 1001d8d0

void Unwind_1001d8d0(void)

{
  int unaff_EBP;
  
  FUN_10013c30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001d900 at 1001d900

void Unwind_1001d900(void)

{
  int unaff_EBP;
  
  CControlBar::OnInitialUpdate((CControlBar *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001d930 at 1001d930

void Unwind_1001d930(void)

{
  int unaff_EBP;
  
  CControlBar::OnInitialUpdate((CControlBar *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001d960 at 1001d960

void Unwind_1001d960(void)

{
  int unaff_EBP;
  
  FUN_100174d0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d990 at 1001d990

void Unwind_1001d990(void)

{
  int unaff_EBP;
  
  FUN_100174d0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d9c0 at 1001d9c0

void Unwind_1001d9c0(void)

{
  int unaff_EBP;
  
  FUN_100174e0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001d9f0 at 1001d9f0

void Unwind_1001d9f0(void)

{
  int unaff_EBP;
  
  FUN_100174d0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001da20 at 1001da20

void Unwind_1001da20(void)

{
  int unaff_EBP;
  
  FUN_100174e0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001da50 at 1001da50

void Unwind_1001da50(void)

{
  int unaff_EBP;
  
  FUN_100174a0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001da80 at 1001da80

void Unwind_1001da80(void)

{
  int unaff_EBP;
  
  FUN_100174b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dab0 at 1001dab0

void Unwind_1001dab0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dae0 at 1001dae0

void Unwind_1001dae0(void)

{
  int unaff_EBP;
  
  FUN_100174a0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001db10 at 1001db10

void Unwind_1001db10(void)

{
  int unaff_EBP;
  
  FUN_100174b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001db40 at 1001db40

void Unwind_1001db40(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001db70 at 1001db70

void Unwind_1001db70(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@1001db7b at 1001db7b

void Unwind_1001db7b(void)

{
  int unaff_EBP;
  
  FUN_100174a0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@1001db86 at 1001db86

void Unwind_1001db86(void)

{
  int unaff_EBP;
  
  FUN_10017400((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@1001db91 at 1001db91

void Unwind_1001db91(void)

{
  int unaff_EBP;
  
  FUN_100174b0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1001db9c at 1001db9c

void Unwind_1001db9c(void)

{
  int unaff_EBP;
  
  FUN_10017450((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1001dba7 at 1001dba7

void Unwind_1001dba7(void)

{
  int unaff_EBP;
  
  FUN_100174b0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1001dbb2 at 1001dbb2

void Unwind_1001dbb2(void)

{
  int unaff_EBP;
  
  FUN_100174a0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@1001dbf0 at 1001dbf0

void Unwind_1001dbf0(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@1001dbfb at 1001dbfb

void Unwind_1001dbfb(void)

{
  int unaff_EBP;
  
  FUN_100174c0((int *)(unaff_EBP + -0x2038));
  return;
}



// Function: Unwind@1001dc06 at 1001dc06

void Unwind_1001dc06(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1001dc11 at 1001dc11

void Unwind_1001dc11(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1001dc1c at 1001dc1c

void Unwind_1001dc1c(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1001dc27 at 1001dc27

void Unwind_1001dc27(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1001dc32 at 1001dc32

void Unwind_1001dc32(void)

{
  int unaff_EBP;
  
  FUN_100174e0((int *)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1001dc3d at 1001dc3d

void Unwind_1001dc3d(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@1001dc48 at 1001dc48

void Unwind_1001dc48(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@1001dc53 at 1001dc53

void Unwind_1001dc53(void)

{
  int unaff_EBP;
  
  FUN_100174d0((int *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@1001dc5e at 1001dc5e

void Unwind_1001dc5e(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@1001dc69 at 1001dc69

void Unwind_1001dc69(void)

{
  int unaff_EBP;
  
  FUN_100174e0((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@1001dc74 at 1001dc74

void Unwind_1001dc74(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x2044));
  return;
}



// Function: Unwind@1001dcb0 at 1001dcb0

void Unwind_1001dcb0(void)

{
  int unaff_EBP;
  
  FUN_100174d0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001dcb8 at 1001dcb8

void Unwind_1001dcb8(void)

{
  int unaff_EBP;
  
  FUN_100174e0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001dcc0 at 1001dcc0

void Unwind_1001dcc0(void)

{
  int unaff_EBP;
  
  FUN_100174c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001dcc8 at 1001dcc8

void Unwind_1001dcc8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001dcd3 at 1001dcd3

void Unwind_1001dcd3(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001dcdb at 1001dcdb

void Unwind_1001dcdb(void)

{
  int unaff_EBP;
  
  FUN_100174d0(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001dce3 at 1001dce3

void Unwind_1001dce3(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001dceb at 1001dceb

void Unwind_1001dceb(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001dcf3 at 1001dcf3

void Unwind_1001dcf3(void)

{
  int unaff_EBP;
  
  FUN_10013b90(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001dcfb at 1001dcfb

void Unwind_1001dcfb(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001dd20 at 1001dd20

void Unwind_1001dd20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001dd2b at 1001dd2b

void Unwind_1001dd2b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10013b90(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001dd60 at 1001dd60

void Unwind_1001dd60(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001dd6b at 1001dd6b

void Unwind_1001dd6b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10013b90(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001dda0 at 1001dda0

void Unwind_1001dda0(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ddd0 at 1001ddd0

void Unwind_1001ddd0(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001de00 at 1001de00

void Unwind_1001de00(void)

{
  int unaff_EBP;
  
  FUN_10013b90((int *)(unaff_EBP + 8));
  return;
}



// Function: FUN_1001de70 at 1001de70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001de70(void)

{
  FUN_10002b30((undefined4 *)&DAT_10029904);
  _atexit(FUN_1001e0e0);
  return;
}



// Function: FUN_1001dea0 at 1001dea0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dea0(void)

{
  FUN_10002ba0((undefined4 *)&DAT_10029908);
  _atexit(FUN_1001e100);
  return;
}



// Function: FUN_1001ded0 at 1001ded0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001ded0(void)

{
  FUN_10002c10((undefined4 *)&DAT_1002990c);
  _atexit(FUN_1001e120);
  return;
}



// Function: FUN_1001df00 at 1001df00

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001df00(void)

{
  FUN_10002730((undefined4 *)&DAT_100298d4);
  _atexit(FUN_1001e140);
  return;
}



// Function: FUN_1001df30 at 1001df30

void FUN_1001df30(void)

{
  return;
}



// Function: FUN_1001df50 at 1001df50

void FUN_1001df50(void)

{
  return;
}



// Function: FUN_1001df70 at 1001df70

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001df70(void)

{
  FUN_10002b30((undefined4 *)&DAT_10029904);
  _atexit(FUN_1001e160);
  return;
}



// Function: FUN_1001dfa0 at 1001dfa0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dfa0(void)

{
  FUN_10002ba0((undefined4 *)&DAT_10029908);
  _atexit(FUN_1001e180);
  return;
}



// Function: FUN_1001dfd0 at 1001dfd0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001dfd0(void)

{
  FUN_10002c10((undefined4 *)&DAT_1002990c);
  _atexit(FUN_1001e1a0);
  return;
}



// Function: FUN_1001e000 at 1001e000

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e000(void)

{
  std::locale::id::id((id *)&DAT_10029914,0);
  return;
}



// Function: FUN_1001e030 at 1001e030

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e030(void)

{
  std::locale::id::id((id *)&DAT_10029918,0);
  return;
}



// Function: FUN_1001e060 at 1001e060

void FUN_1001e060(void)

{
  return;
}



// Function: FUN_1001e080 at 1001e080

void FUN_1001e080(void)

{
  return;
}



// Function: FUN_1001e0e0 at 1001e0e0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e0e0(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)&DAT_10029904);
  return;
}



// Function: FUN_1001e100 at 1001e100

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e100(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)&DAT_10029908);
  return;
}



// Function: FUN_1001e120 at 1001e120

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e120(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)&DAT_1002990c);
  return;
}



// Function: FUN_1001e140 at 1001e140

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e140(void)

{
  FUN_100037a0((CPropertySet *)&DAT_100298d4);
  return;
}



// Function: FUN_1001e160 at 1001e160

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e160(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)&DAT_10029904);
  return;
}



// Function: FUN_1001e180 at 1001e180

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e180(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)&DAT_10029908);
  return;
}



// Function: FUN_1001e1a0 at 1001e1a0

/* WARNING: Function: __RTC_CheckEsp replaced with injection: __RTC_CheckEsp */

void FUN_1001e1a0(void)

{
  FID_conflict__CHeapPtr<unsigned_short,class_ATL::CCRTAllocator>((undefined4 *)&DAT_1002990c);
  return;
}



// Function: FUN_1001e1b6 at 1001e1b6

void FUN_1001e1b6(void)

{
  ATL::CAtlBaseModule::~CAtlBaseModule((CAtlBaseModule *)&DAT_10029924);
  return;
}



// Function: FUN_1001e1c0 at 1001e1c0

void FUN_1001e1c0(void)

{
  ATL::CAtlComModule::Term((CAtlComModule *)&DAT_1002995c);
  return;
}



// Function: FUN_1001e1d0 at 1001e1d0

void FUN_1001e1d0(void)

{
  Ordinal_9(&DAT_10029820);
  return;
}



// Function: FUN_1001e1dc at 1001e1dc

void FUN_1001e1dc(void)

{
  FUN_1001bfef();
  return;
}



