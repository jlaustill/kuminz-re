/*
 * Decompiled from: AuditTrail.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

undefined4 FUN_10001000(void)

{
  return 0;
}



// Function: FUN_10001010 at 10001010

void FUN_10001010(int param_1)

{
  FUN_1000bbb0((int *)&DAT_10035390,0x65,param_1,(int *)0x0);
  return;
}



// Function: FUN_10001030 at 10001030

void FUN_10001030(int param_1)

{
  FUN_1000bbb0((int *)&DAT_10035390,0x66,param_1,(int *)0x0);
  return;
}



// Function: FUN_10001050 at 10001050

undefined4 FUN_10001050(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022bc2;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)FUN_10021550(0x28);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10001a70(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_100010f6();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100010f0 at 100010f0

undefined * Catch_100010f0(void)

{
  return &DAT_100010ff;
}



// Function: FUN_100010f6 at 100010f6

undefined4 FUN_100010f6(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_1000aa30(*(void **)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 8));
    FUN_10007c60();
    uVar1 = FUN_1000bd60(*(int *)(unaff_EBP + -0x14) + 4);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_10006ea0();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000bd00();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_10007c90();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100011d0 at 100011d0

undefined4 FUN_100011d0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = FUN_100069a0(0,param_2,param_3);
  }
  else {
    local_8 = FUN_10006820(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: FUN_10001210 at 10001210

void FUN_10001210(void)

{
  return;
}



// Function: FUN_10001220 at 10001220

undefined4 FUN_10001220(void)

{
  return 0;
}



// Function: DllGetClassObject at 10001230

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x1230  2  DllGetClassObject */
  iVar1 = FUN_10007080(&DAT_10035390,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: DllCanUnloadNow at 10001250

HRESULT DllCanUnloadNow(void)

{
  int iVar1;
  uint local_8;
  
                    /* 0x1250  1  DllCanUnloadNow */
  iVar1 = FUN_100072d0(0x10035390);
  local_8 = (uint)(iVar1 != 0);
  return local_8;
}



// Function: DllRegisterServer at 10001280

void DllRegisterServer(void)

{
                    /* 0x1280  3  DllRegisterServer */
  FUN_100094d0(&DAT_10035390,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 100012a0

void DllUnregisterServer(void)

{
                    /* 0x12a0  4  DllUnregisterServer */
  FUN_1000ae10(&DAT_10035390,1,(void *)0x0);
  return;
}



// Function: FUN_100012c0 at 100012c0

LPCSTR __cdecl FUN_100012c0(LPSTR param_1)

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



// Function: FUN_10001330 at 10001330

int FUN_10001330(LPWSTR param_1)

{
  WCHAR WVar1;
  int iVar2;
  LPWSTR pWVar3;
  undefined4 local_10;
  undefined4 local_8;
  
  if (param_1 == (LPWSTR)0x0) {
    iVar2 = 0;
  }
  else {
    local_10 = param_1;
    local_8 = param_1;
    while (*local_8 != L'\0') {
      pWVar3 = CharNextW(local_8);
      if (((*local_8 == L'\\') || (*local_8 == L'/')) ||
         (WVar1 = *local_8, local_8 = pWVar3, WVar1 == L':')) {
        local_10 = pWVar3;
        local_8 = pWVar3;
      }
    }
    iVar2 = (int)local_10 - (int)param_1 >> 1;
  }
  return iVar2;
}



// Function: FUN_100013a0 at 100013a0

undefined4 FUN_100013a0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10007aa0(&DAT_10035390,0x10035000,param_1,(undefined4 *)&DAT_10029a0c);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_1000ac90(0x10035390);
  }
  return 1;
}



// Function: FUN_100013f0 at 100013f0

undefined4 __cdecl FUN_100013f0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10001400 at 10001400

undefined4 __cdecl FUN_10001400(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10001410 at 10001410

void FUN_10001410(void)

{
  return;
}



// Function: FUN_10001420 at 10001420

void FUN_10001420(void)

{
  return;
}



// Function: FUN_10001430 at 10001430

void __thiscall FUN_10001430(void *this,undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_100034f0(param_1);
  cVar1 = FUN_10007e10(this,puVar2);
  if (cVar1 == '\0') {
    puVar3 = &DAT_10029d9c;
    puVar2 = (undefined4 *)FUN_100034f0(param_1);
    FUN_10004eb0((int *)this,puVar2,puVar3);
  }
  else {
    FUN_10003500((undefined4 *)this);
  }
  return;
}



// Function: AtlAdd<> at 10001480

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlAdd<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Debug */

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



// Function: AtlAddThrow<unsigned_long> at 100014b0

/* Library Function - Single Match
    unsigned long __cdecl ATL::AtlAddThrow<unsigned long>(unsigned long,unsigned long)
   
   Library: Visual Studio 2010 Debug */

ulong __cdecl ATL::AtlAddThrow<unsigned_long>(ulong param_1,ulong param_2)

{
  ulong local_c;
  HRESULT local_8;
  
  local_8 = AtlAdd<>((int *)&local_c,param_1,param_2);
  if (local_8 < 0) {
    FUN_10006230(local_8);
  }
  return local_c;
}



// Function: AtlMultiply<int> at 100014f0

/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<int>(int *,int,int)
   
   Library: Visual Studio 2010 Debug */

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



// Function: AtlMultiply<> at 10001560

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlMultiply<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Debug */

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



// Function: AtlMultiply<> at 100015a0

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlMultiply<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Debug */

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



// Function: AtlMultiplyThrow<unsigned_int> at 100015e0

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  uint local_c;
  HRESULT local_8;
  
  local_8 = AtlMultiply<>(&local_c,param_1,param_2);
  if (local_8 < 0) {
    FUN_10006230(local_8);
  }
  return local_c;
}



// Function: QueryInterface<> at 10001620

/* Library Function - Multiple Matches With Same Base Name
    public: long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface<struct
   IAccessibleProxy>(struct IAccessibleProxy * *)
    public: long __stdcall IUnknown::QueryInterface<struct IAccessor>(struct IAccessor * *)
    public: long __stdcall IUnknown::QueryInterface<struct IColumnsInfo>(struct IColumnsInfo * *)
    public: long __stdcall IUnknown::QueryInterface<struct IHTMLDocument2>(struct IHTMLDocument2 *
   *)
     8 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void QueryInterface<>(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_10029dc0,param_2);
  return;
}



// Function: FUN_10001640 at 10001640

void * __cdecl FUN_10001640(uint param_1)

{
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) && (local_8 = operator_new(param_1), local_8 == (void *)0x0)) {
    std::_Xbad_alloc();
  }
  return local_8;
}



// Function: addressof<> at 10001680

/* Library Function - Multiple Matches With Same Base Name
    char * __cdecl std::addressof<char>(char &)
    unsigned short * __cdecl std::addressof<unsigned short>(unsigned short &)
    wchar_t * __cdecl std::addressof<wchar_t>(wchar_t &)
   
   Library: Visual Studio 2012 Release */

undefined4 __cdecl addressof<>(undefined4 param_1)

{
  return param_1;
}



// Function: construct<> at 10001690

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<char> >::construct<char *,char *
   &>(char * *,char * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::construct<unsigned short *,unsigned short * &>(unsigned short * *,unsigned short * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<wchar_t> >::construct<wchar_t
   *,wchar_t * &>(wchar_t * *,wchar_t * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<struct std::_Container_proxy>
   >::construct<struct std::_Container_proxy,struct std::_Container_proxy>(struct
   std::_Container_proxy *,struct std::_Container_proxy &&)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

void __thiscall construct<>(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_2);
  construct<>(this,param_1,uVar1);
  return;
}



// Function: construct<> at 100016c0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::allocator<char>::construct<char *,char * &>(char * *,char * &)
    public: void __thiscall std::allocator<unsigned short>::construct<unsigned short *,unsigned
   short * &>(unsigned short * *,unsigned short * &)
    public: void __thiscall std::allocator<wchar_t>::construct<wchar_t *,wchar_t * &>(wchar_t *
   *,wchar_t * &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void construct<>(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021f51;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)forward<>(4,param_1);
  local_8 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)forward<>(param_2);
    *puVar1 = *puVar2;
  }
  ExceptionList = local_10;
  return;
}



// Function: construct<> at 10001750

/* Library Function - Multiple Matches With Same Base Name
    public: static void __cdecl std::allocator_traits<class std::allocator<char> >::construct<char
   *,char * &>(class std::allocator<char> &,char * *,char * &)
    public: static void __cdecl std::allocator_traits<class std::allocator<unsigned short>
   >::construct<unsigned short *,unsigned short * &>(class std::allocator<unsigned short> &,unsigned
   short * *,unsigned short * &)
    public: static void __cdecl std::allocator_traits<class std::allocator<wchar_t>
   >::construct<wchar_t *,wchar_t * &>(class std::allocator<wchar_t> &,wchar_t * *,wchar_t * &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __cdecl construct<>(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_3);
  construct<>(param_2,uVar1);
  return;
}



// Function: destroy<> at 10001770

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<char> >::destroy<char *>(char * *)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::destroy<unsigned short *>(unsigned short * *)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<wchar_t> >::destroy<wchar_t
   *>(wchar_t * *)
   
   Library: Visual Studio 2012 Release */

void destroy<>(void)

{
  destroy<>();
  return;
}



// Function: FUN_10001790 at 10001790

void FUN_10001790(void)

{
  return;
}



// Function: destroy<> at 100017a0

/* Library Function - Multiple Matches With Same Base Name
    public: static void __cdecl std::allocator_traits<class std::allocator<char> >::destroy<char
   *>(class std::allocator<char> &,char * *)
    public: static void __cdecl std::allocator_traits<class std::allocator<unsigned short>
   >::destroy<unsigned short *>(class std::allocator<unsigned short> &,unsigned short * *)
    public: static void __cdecl std::allocator_traits<class std::allocator<wchar_t>
   >::destroy<wchar_t *>(class std::allocator<wchar_t> &,wchar_t * *)
    public: static void __cdecl std::allocator_traits<class std::allocator<struct
   std::_Container_proxy> >::destroy<struct std::_Container_proxy>(class std::allocator<struct
   std::_Container_proxy> &,struct std::_Container_proxy *)
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

void destroy<>(void)

{
  FUN_10001790();
  return;
}



// Function: forward<> at 100017c0

/* Library Function - Multiple Matches With Same Base Name
    char * & __cdecl std::forward<char * &>(char * &)
    unsigned short * & __cdecl std::forward<unsigned short * &>(unsigned short * &)
    wchar_t * & __cdecl std::forward<wchar_t * &>(wchar_t * &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 __cdecl forward<>(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100017d0 at 100017d0

int __fastcall FUN_100017d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021f78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002000(param_1);
  local_8 = 0;
  FUN_10007b80();
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001830 at 10001830

undefined4 * __fastcall FUN_10001830(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001850 at 10001850

undefined4 * __fastcall FUN_10001850(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001870 at 10001870

undefined4 * __fastcall FUN_10001870(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001890 at 10001890

undefined4 * __thiscall FUN_10001890(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021fb6;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100024c0(this);
  FUN_10001b30((undefined4 *)((int)this + 4));
  local_8 = 0;
  *(undefined ***)this = &PTR_FUN_1002afbc;
  FUN_10001920((void *)((int)this + 0xc),param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*DAT_10035308 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001920 at 10001920

undefined4 * __thiscall FUN_10001920(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10021fe8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000ce60((int)this);
  *(undefined ***)this = &PTR_FUN_1002af58;
  *(undefined ***)((int)this + 4) = &PTR_LAB_1002af88;
  *(undefined ***)((int)this + 8) = &PTR_LAB_1002afac;
  *(undefined4 *)((int)this + 0xc) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: CComCritSecLock<class_ATL::CComCriticalSection> at 100019a0

/* Library Function - Single Match
    public: __thiscall ATL::CComCritSecLock<class ATL::CComCriticalSection>::CComCritSecLock<class
   ATL::CComCriticalSection>(class ATL::CComCriticalSection &,bool)
   
   Library: Visual Studio 2012 Debug */

CComCritSecLock<class_ATL::CComCriticalSection> * __thiscall
ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
CComCritSecLock<class_ATL::CComCriticalSection>
          (CComCritSecLock<class_ATL::CComCriticalSection> *this,CComCriticalSection *param_1,
          bool param_2)

{
  int iVar1;
  
  *(CComCriticalSection **)this = param_1;
  this[4] = (CComCritSecLock<class_ATL::CComCriticalSection>)0x0;
  if (param_2) {
    iVar1 = FUN_100081c0((undefined4 *)this);
    if (iVar1 < 0) {
      FUN_10006230(iVar1);
    }
  }
  return this;
}



// Function: FUN_100019f0 at 100019f0

undefined4 * __fastcall FUN_100019f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022018;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000ce60((int)param_1);
  local_8 = 0;
  *param_1 = &PTR_QueryInterface_1002aef0;
  param_1[1] = &PTR_LAB_1002af24;
  param_1[2] = &PTR_LAB_1002af48;
  (**(code **)(*DAT_10035308 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001a70 at 10001a70

undefined4 * __fastcall FUN_10001a70(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022048;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002120(param_1);
  *param_1 = &PTR_QueryInterface_1002aed4;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001ad0 at 10001ad0

undefined4 * __fastcall FUN_10001ad0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022083;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002210(param_1);
  local_8 = 0;
  FUN_100020b0((CComCriticalSection *)(param_1 + 1));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001b30 at 10001b30

undefined4 * __fastcall FUN_10001b30(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100220a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002210(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001b80 at 10001b80

undefined4 * __fastcall FUN_10001b80(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100220d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001d70(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001bd0 at 10001bd0

undefined4 * __fastcall FUN_10001bd0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022108;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001d90(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001c20 at 10001c20

void * __thiscall FUN_10001c20(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022138;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CComPtrBase<>(this,*param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10001c80 at 10001c80

undefined4 * __fastcall FUN_10001c80(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022168;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001df0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001cd0 at 10001cd0

undefined4 * __fastcall FUN_10001cd0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022198;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001e10(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001d20 at 10001d20

undefined4 * __fastcall FUN_10001d20(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100221c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001e30(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001d70 at 10001d70

undefined4 * __fastcall FUN_10001d70(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001d90 at 10001d90

undefined4 * __fastcall FUN_10001d90(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: CComPtrBase<> at 10001db0

/* Library Function - Multiple Matches With Same Base Name
    protected: __thiscall ATL::CComPtrBase<struct IShellItem>::CComPtrBase<struct IShellItem>(struct
   IShellItem *)
    protected: __thiscall ATL::CComPtrBase<struct IUnknown>::CComPtrBase<struct IUnknown>(struct
   IUnknown *)
    protected: __thiscall ATL::CComPtrBase<struct IXMLDOMNode>::CComPtrBase<struct
   IXMLDOMNode>(struct IXMLDOMNode *)
    protected: __thiscall ATL::CComPtrBase<struct IXMLDOMNodeList>::CComPtrBase<struct
   IXMLDOMNodeList>(struct IXMLDOMNodeList *)
   
   Library: Visual Studio 2010 Debug */

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



// Function: FUN_10001df0 at 10001df0

undefined4 * __fastcall FUN_10001df0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001e10 at 10001e10

undefined4 * __fastcall FUN_10001e10(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001e30 at 10001e30

undefined4 * __fastcall FUN_10001e30(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001e50 at 10001e50

undefined4 * __fastcall FUN_10001e50(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_10001e80 at 10001e80

undefined4 * __fastcall FUN_10001e80(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001ea0 at 10001ea0

undefined4 * __fastcall FUN_10001ea0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001ec0 at 10001ec0

undefined4 * __fastcall FUN_10001ec0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001ee0 at 10001ee0

undefined4 * __thiscall FUN_10001ee0(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10001f00 at 10001f00

undefined4 * __thiscall FUN_10001f00(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: _String_alloc<> at 10001f20

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_String_alloc<0,struct std::_String_base_types<char,class
   std::allocator<char> > >::_String_alloc<0,struct std::_String_base_types<char,class
   std::allocator<char> > >(class std::allocator<char> const &)
    public: __thiscall std::_String_alloc<0,struct std::_String_base_types<unsigned short,class
   std::allocator<unsigned short> > >::_String_alloc<0,struct std::_String_base_types<unsigned
   short,class std::allocator<unsigned short> > >(class std::allocator<unsigned short> const &)
    public: __thiscall std::_String_alloc<0,struct std::_String_base_types<wchar_t,class
   std::allocator<wchar_t> > >::_String_alloc<0,struct std::_String_base_types<wchar_t,class
   std::allocator<wchar_t> > >(class std::allocator<wchar_t> const &)
   
   Library: Visual Studio 2012 Release */

int __fastcall _String_alloc<>(int param_1)

{
  _String_val<>(param_1);
  return param_1;
}



// Function: _String_val<> at 10001f40

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_String_val<struct std::_Simple_types<char> >::_String_val<struct
   std::_Simple_types<char> >(void)
    public: __thiscall std::_String_val<struct std::_Simple_types<unsigned short>
   >::_String_val<struct std::_Simple_types<unsigned short> >(void)
    public: __thiscall std::_String_val<struct std::_Simple_types<wchar_t> >::_String_val<struct
   std::_Simple_types<wchar_t> >(void)
   
   Library: Visual Studio 2012 Release */

int __fastcall _String_val<>(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_10001f70 at 10001f70

undefined4 __fastcall FUN_10001f70(undefined4 param_1)

{
  allocator<>(param_1);
  return param_1;
}



// Function: allocator<> at 10001f90

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::allocator<char>::allocator<char>(void)
    public: __thiscall std::allocator<unsigned short>::allocator<unsigned short>(void)
    public: __thiscall std::allocator<wchar_t>::allocator<wchar_t>(void)
   
   Library: Visual Studio 2012 Release */

undefined4 __fastcall allocator<>(undefined4 param_1)

{
  return param_1;
}



// Function: basic_string<> at 10001fa0

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(unsigned short const *)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(wchar_t const *)
   
   Library: Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
basic_string<>(void *this,char *param_1)

{
  undefined1 local_5;
  
  allocator<>(&local_5);
  _String_alloc<>((int)this);
  FID_conflict__Tidy(this,'\0',0);
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this,
             param_1);
  return (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)this;
}



// Function: FUN_10001fe0 at 10001fe0

undefined4 * __thiscall FUN_10001fe0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10002000 at 10002000

int __fastcall FUN_10002000(int param_1)

{
  long lVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100221fb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100024d0(param_1 + 4);
  local_8 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10035308 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1003531c = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100020b0 at 100020b0

CComCriticalSection * __fastcall FUN_100020b0(CComCriticalSection *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022228;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002230(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002100 at 10002100

undefined4 * __fastcall FUN_10002100(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002120 at 10002120

undefined4 * __fastcall FUN_10002120(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002225b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002480(param_1);
  FUN_10001ad0(param_1 + 1);
  *param_1 = &PTR_purecall_1002ae18;
  ExceptionList = local_10;
  return param_1;
}



// Function: CComCriticalSection at 10002190

/* Library Function - Single Match
    public: __thiscall ATL::CComCriticalSection::CComCriticalSection(void)
   
   Library: Visual Studio */

CComCriticalSection * __thiscall
ATL::CComCriticalSection::CComCriticalSection(CComCriticalSection *this)

{
  memset(this,0,0x18);
  return this;
}



// Function: FUN_100021b0 at 100021b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_100021b0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022288;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100017d0((int)param_1);
  *param_1 = &PTR_FUN_1002ab8c;
  _DAT_10035320 = param_1;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002210 at 10002210

undefined4 * __fastcall FUN_10002210(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002230 at 10002230

CComCriticalSection * __fastcall FUN_10002230(CComCriticalSection *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100222b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CComCriticalSection::CComCriticalSection(param_1);
  param_1[0x18] = (CComCriticalSection)0x0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002290 at 10002290

undefined4 * __fastcall FUN_10002290(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100222e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001e50(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100022e0 at 100022e0

undefined4 * __thiscall FUN_100022e0(void *this,int param_1)

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



// Function: CRegKey at 10002340

/* Library Function - Single Match
    public: __thiscall ATL::CRegKey::CRegKey(struct HKEY__ *)
   
   Library: Visual Studio 2010 Debug */

CRegKey * __thiscall ATL::CRegKey::CRegKey(CRegKey *this,HKEY__ *param_1)

{
  *(HKEY__ **)this = param_1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}



// Function: CRegKey at 10002370

/* Library Function - Single Match
    public: __thiscall ATL::CRegKey::CRegKey(class ATL::CAtlTransactionManager *)
   
   Library: Visual Studio 2010 Debug */

CRegKey * __thiscall ATL::CRegKey::CRegKey(CRegKey *this,CAtlTransactionManager *param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(CAtlTransactionManager **)(this + 8) = param_1;
  return this;
}



// Function: FUN_100023a0 at 100023a0

undefined4 * __fastcall FUN_100023a0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002231b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100024a0(param_1);
  *param_1 = &PTR_FUN_1002abb4;
  FUN_10002290(param_1 + 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002410 at 10002410

undefined4 * __thiscall FUN_10002410(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)this = 0;
  return (undefined4 *)this;
}



// Function: FUN_10002440 at 10002440

undefined4 * __thiscall FUN_10002440(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return (undefined4 *)this;
}



// Function: FUN_10002480 at 10002480

undefined4 __fastcall FUN_10002480(undefined4 param_1)

{
  FUN_100024c0(param_1);
  return param_1;
}



// Function: FUN_100024a0 at 100024a0

undefined4 __fastcall FUN_100024a0(undefined4 param_1)

{
  FUN_100024c0(param_1);
  return param_1;
}



// Function: FUN_100024c0 at 100024c0

undefined4 __fastcall FUN_100024c0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100024d0 at 100024d0

int __fastcall FUN_100024d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002234b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CComCriticalSection::CComCriticalSection((CComCriticalSection *)(param_1 + 0xc));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002530 at 10002530

undefined4 * __fastcall FUN_10002530(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022378;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100026f0(param_1);
  *param_1 = std::_Generic_error_category::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002590 at 10002590

undefined4 * __fastcall FUN_10002590(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100223a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002530(param_1);
  *param_1 = std::_Iostream_error_category::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100025f0 at 100025f0

undefined4 * __fastcall FUN_100025f0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100223d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002530(param_1);
  *param_1 = std::_System_error_category::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002650 at 10002650

int * __thiscall FUN_10002650(void *this,LPCSTR param_1)

{
  void *this_00;
  undefined4 *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002240b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = (void *)FUN_10003370(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_1c = (undefined4 *)0x0;
  }
  else {
    local_1c = FUN_10002440(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(undefined4 **)this = local_1c;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_100026f0 at 100026f0

undefined4 * __fastcall FUN_100026f0(undefined4 *param_1)

{
  *param_1 = std::error_category::vftable;
  return param_1;
}



// Function: FUN_10002710 at 10002710

undefined4 * __thiscall FUN_10002710(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  return (undefined4 *)this;
}



// Function: FUN_10002740 at 10002740

undefined4 * __fastcall FUN_10002740(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022438;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002100(param_1);
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  ExceptionList = local_10;
  return param_1;
}



// Function: FID_conflict:~bad_alloc at 100027b0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022468;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e50(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> at 10002800

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::~CAtlSafeAllocBufferManager<class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
          (CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *this)

{
  void *pvVar1;
  
  while (*(int *)this != 0) {
    pvVar1 = *(void **)this;
    *(undefined4 *)this = **(undefined4 **)this;
    FUN_10006fd0(pvVar1);
  }
  return;
}



// Function: FUN_10002840 at 10002840

void __fastcall FUN_10002840(undefined4 *param_1)

{
  Free(param_1);
  return;
}



// Function: FUN_10002860 at 10002860

void __fastcall FUN_10002860(undefined4 *param_1)

{
  Free(param_1);
  return;
}



// Function: FUN_10002880 at 10002880

void __fastcall FUN_10002880(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100224a6;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_1002afbc;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  FUN_10006ed0();
  (**(code **)(*DAT_10035308 + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FID_conflict__bad_alloc((int)(param_1 + 3));
  local_8 = 0xffffffff;
  _anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal((_ExceptionPtr_normal *)(param_1 + 1))
  ;
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002910

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100224d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  CCIAuditTrail_Initialize(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~CComCritSecLock<class_ATL::CComCriticalSection> at 10002960

/* Library Function - Single Match
    public: __thiscall ATL::CComCritSecLock<class ATL::CComCriticalSection>::~CComCritSecLock<class
   ATL::CComCriticalSection>(void)
   
   Library: Visual Studio */

void __thiscall
ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
~CComCritSecLock<class_ATL::CComCriticalSection>
          (CComCritSecLock<class_ATL::CComCriticalSection> *this)

{
  if (this[4] != (CComCritSecLock<class_ATL::CComCriticalSection>)0x0) {
    FUN_1000ad30((undefined4 *)this);
  }
  return;
}



// Function: FUN_10002980 at 10002980

void __fastcall FUN_10002980(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022508;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = &PTR_QueryInterface_1002aef0;
  param_1[1] = &PTR_LAB_1002af24;
  param_1[2] = &PTR_LAB_1002af48;
  local_8 = 0;
  param_1[3] = 0xc0000001;
  FUN_10006f00();
  (**(code **)(*DAT_10035308 + 8))(uVar1);
  local_8 = 0xffffffff;
  CCIAuditTrail_Initialize((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002a10 at 10002a10

void __fastcall FUN_10002a10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022538;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_QueryInterface_1002aed4;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  FUN_10006f00();
  local_8 = 0xffffffff;
  FUN_10002f20(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~_ExceptionPtr_static<> at 10002a80

/* Library Function - Multiple Matches With Same Base Name
    public: virtual __thiscall `anonymous namespace'::_ExceptionPtr_static<class
   std::bad_alloc>::~_ExceptionPtr_static<class std::bad_alloc>(void)
    public: virtual __thiscall `anonymous namespace'::_ExceptionPtr_static<class
   std::bad_exception>::~_ExceptionPtr_static<class std::bad_exception>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall ~_ExceptionPtr_static<>(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022573;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FID_conflict__bad_alloc((LPCRITICAL_SECTION)(param_1 + 4));
  local_8 = 0xffffffff;
  FUN_10002ff0();
  ExceptionList = local_10;
  return;
}



// Function: ~_ExceptionPtr_normal at 10002ae0

/* Library Function - Single Match
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __thiscall
_anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal(_ExceptionPtr_normal *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022598;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002ff0();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002b30

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100225c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002cc0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002b80

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100225f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002cf0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002bd0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022628;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002d20(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002c20

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022658;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002d50(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002c70

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022688;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002d80(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002cc0 at 10002cc0

void __fastcall FUN_10002cc0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002cf0 at 10002cf0

void __fastcall FUN_10002cf0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002d20 at 10002d20

void __fastcall FUN_10002d20(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002d50 at 10002d50

void __fastcall FUN_10002d50(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002d80 at 10002d80

void __fastcall FUN_10002d80(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002db0 at 10002db0

void __fastcall FUN_10002db0(int *param_1)

{
  FUN_1000a130(param_1);
  return;
}



// Function: ~CTempBuffer<> at 10002dd0

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 10002df0

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: ~CTempBuffer<> at 10002e10

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::~CTempBuffer<unsigned char,128,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>(void)
    public: __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::~CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall ~CTempBuffer<>(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FreeHeap(param_1);
  }
  return;
}



// Function: ~basic_string<> at 10002e30

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::~basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(void)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::~basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(void)
   
   Library: Visual Studio 2012 Release */

void __fastcall ~basic_string<>(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10002e50 at 10002e50

void __fastcall FUN_10002e50(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100226bb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000abf0(param_1);
  local_8 = 0xffffffff;
  FUN_10003190();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10002eb0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100226e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003000(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002f00 at 10002f00

void __fastcall FUN_10002f00(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10002f20 at 10002f20

void __fastcall FUN_10002f20(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002271b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_purecall_1002ae18;
  local_8 = 0xffffffff;
  ~_ExceptionPtr_static<>((int)(param_1 + 1));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002f80 at 10002f80

void FUN_10002f80(void)

{
  return;
}



// Function: FUN_10002f90 at 10002f90

void __fastcall FUN_10002f90(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022748;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_1002ab8c;
  local_8 = 0xffffffff;
  FID_conflict__bad_alloc((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002ff0 at 10002ff0

void FUN_10002ff0(void)

{
  return;
}



// Function: FUN_10003000 at 10003000

void __fastcall FUN_10003000(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022778;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    FUN_1000ac70(param_1);
  }
  local_8 = 0xffffffff;
  FUN_10002f80();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CAtlWinModule at 10003070

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CAtlWinModule::~CAtlWinModule(void)
    public: __thiscall CPaneContainerGC::~CPaneContainerGC(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2010 Debug */

void __fastcall FID_conflict__CAtlWinModule(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100227a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10006660(param_1);
  local_8 = 0xffffffff;
  FUN_10002db0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100030d0 at 100030d0

void __fastcall FUN_100030d0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100030f0 at 100030f0

void __fastcall FUN_100030f0(CRegKey *param_1)

{
  ATL::CRegKey::Close(param_1);
  return;
}



// Function: FUN_10003110 at 10003110

void __fastcall FUN_10003110(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100227db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = &PTR_FUN_1002abb4;
  local_8 = 0;
  FUN_100066e0((int)param_1);
  local_8 = 0xffffffff;
  FID_conflict__CAtlWinModule(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003170 at 10003170

void __fastcall FUN_10003170(int *param_1)

{
  FUN_1000c0c0(param_1);
  return;
}



// Function: FUN_10003190 at 10003190

void FUN_10003190(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002280b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002f80();
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 100031e0

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022838;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100032f0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10003230

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022868;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__bad_alloc(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~bad_alloc at 10003280

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022898;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FID_conflict__bad_alloc(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100032d0 at 100032d0

void __fastcall FUN_100032d0(int *param_1)

{
  Clear(param_1);
  return;
}



// Function: FUN_100032f0 at 100032f0

void __fastcall FUN_100032f0(undefined4 *param_1)

{
  *param_1 = std::error_category::vftable;
  return;
}



// Function: FID_conflict:~bad_alloc at 10003310

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100228c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002f00(param_1);
  ExceptionList = local_10;
  return;
}



// Function: forward<> at 10003360

/* Library Function - Multiple Matches With Same Base Name
    char * & __cdecl std::forward<char * &>(char * &)
    unsigned short * & __cdecl std::forward<unsigned short * &>(unsigned short * &)
    wchar_t * & __cdecl std::forward<wchar_t * &>(wchar_t * &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 __cdecl forward<>(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10003370 at 10003370

void __cdecl FUN_10003370(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_10003390 at 10003390

void FUN_10003390(void)

{
  return;
}



// Function: FUN_100033a0 at 100033a0

bool __fastcall FUN_100033a0(int *param_1)

{
  return *param_1 == 0;
}



// Function: FUN_100033d0 at 100033d0

bool __thiscall FUN_100033d0(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_10003400 at 10003400

void __fastcall FUN_10003400(int *param_1)

{
  FUN_100033a0(param_1);
  return;
}



// Function: operator== at 10003420

/* Library Function - Single Match
    public: bool __thiscall std::error_category::operator==(class std::error_category const &)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

bool __thiscall std::error_category::operator==(error_category *this,error_category *param_1)

{
  return this == param_1;
}



// Function: operator== at 10003450

/* Library Function - Single Match
    public: bool __thiscall std::error_condition::operator==(class std::error_condition const
   &)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

bool __thiscall std::error_condition::operator==(error_condition *this,error_condition *param_1)

{
  bool bVar1;
  error_category *peVar2;
  error_category *this_00;
  int iVar3;
  int iVar4;
  
  peVar2 = (error_category *)FUN_1000c630((int)param_1);
  this_00 = (error_category *)FUN_1000c630((int)this);
  bVar1 = error_category::operator==(this_00,peVar2);
  if (bVar1) {
    iVar3 = value(this);
    iVar4 = value(param_1);
    if (iVar3 == iVar4) {
      return true;
    }
  }
  return false;
}



// Function: FUN_100034b0 at 100034b0

bool __fastcall FUN_100034b0(int *param_1)

{
  char cVar1;
  
  cVar1 = FUN_10003400(param_1);
  return cVar1 == '\0';
}



// Function: FUN_100034f0 at 100034f0

undefined4 __fastcall FUN_100034f0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003500 at 10003500

undefined4 __fastcall FUN_10003500(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003510 at 10003510

undefined4 __fastcall FUN_10003510(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003520 at 10003520

undefined4 __fastcall FUN_10003520(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003530 at 10003530

undefined4 __fastcall FUN_10003530(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003540 at 10003540

undefined4 __fastcall FUN_10003540(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003550 at 10003550

undefined4 __fastcall FUN_10003550(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003560 at 10003560

undefined4 __fastcall FUN_10003560(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003570 at 10003570

undefined4 __fastcall FUN_10003570(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003580 at 10003580

undefined4 __fastcall FUN_10003580(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003590 at 10003590

undefined4 __fastcall FUN_10003590(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100035a0 at 100035a0

undefined4 __fastcall FUN_100035a0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100035b0 at 100035b0

undefined4 __fastcall FUN_100035b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100035c0 at 100035c0

undefined4 __fastcall FUN_100035c0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100035d0 at 100035d0

undefined4 __fastcall FUN_100035d0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100035e0 at 100035e0

undefined4 __fastcall FUN_100035e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100035f0 at 100035f0

undefined4 __fastcall FUN_100035f0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003600 at 10003600

undefined4 __fastcall FUN_10003600(undefined4 param_1)

{
  return param_1;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10003610

/* Library Function - Multiple Matches With Different Base Names
    public: void * __thiscall Concurrency::details::GlobalCore::`vector deleting
   destructor'(unsigned int)
    public: void * __thiscall Concurrency::location::`vector deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

undefined4 * __thiscall FID_conflict__vector_deleting_destructor_(void *this,uint param_1)

{
  if ((param_1 & 2) == 0) {
    FID_conflict__bad_alloc((undefined4 *)this);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    _eh_vector_destructor_iterator_(this,0xc,*(int *)((int)this + -4),FID_conflict__bad_alloc);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)this + -4));
    }
    this = (void *)((int)this + -4);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003680 at 10003680

undefined4 * __thiscall FUN_10003680(void *this,uint param_1)

{
  FUN_10002880((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100036b0 at 100036b0

undefined4 * __thiscall FUN_100036b0(void *this,uint param_1)

{
  FUN_10002980((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100036e0 at 100036e0

undefined4 * __thiscall FUN_100036e0(void *this,uint param_1)

{
  FUN_10002a10((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003710 at 10003710

undefined4 * __thiscall FUN_10003710(void *this,uint param_1)

{
  FUN_10002f20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003740 at 10003740

undefined4 * __thiscall FUN_10003740(void *this,uint param_1)

{
  FUN_10002f90((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003770 at 10003770

undefined4 * __thiscall FUN_10003770(void *this,uint param_1)

{
  FUN_10003110((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100037a0 at 100037a0

int * __thiscall FUN_100037a0(void *this,uint param_1)

{
  FUN_10003170((int *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_100037d0 at 100037d0

undefined4 * __thiscall FUN_100037d0(void *this,uint param_1)

{
  FID_conflict__bad_alloc((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003800 at 10003800

undefined4 * __thiscall FUN_10003800(void *this,uint param_1)

{
  FID_conflict__bad_alloc((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003830 at 10003830

undefined4 * __thiscall FUN_10003830(void *this,uint param_1)

{
  FID_conflict__bad_alloc((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003860 at 10003860

undefined4 * __thiscall FUN_10003860(void *this,uint param_1)

{
  FUN_100032f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003890 at 10003890

undefined4 __thiscall FUN_10003890(void *this,undefined4 *param_1,undefined4 *param_2)

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
      FUN_10007d10(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}



// Function: FUN_10003930 at 10003930

undefined4 __thiscall FUN_10003930(void *this,char *param_1,wchar_t *param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  void *local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022900;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 == (char *)0x0) || (param_2 == (wchar_t *)0x0)) {
    uVar1 = 0;
  }
  else {
    local_1c = 0;
    sVar2 = strlen(param_1);
    local_20 = sVar2 + 1;
    local_18 = (void *)0x0;
    local_18 = (void *)FUN_1002157e(local_20);
    FUN_10001850(&local_2c);
    local_8 = 0;
    FUN_10006450(&local_2c,local_18);
    sVar2 = FUN_1000cbd0(param_2);
    local_24 = sVar2 * 2 + 2;
    local_14 = (void *)0x0;
    local_14 = (void *)FUN_1002157e(-(uint)((int)((ulonglong)local_24 * 2 >> 0x20) != 0) |
                                    (uint)((ulonglong)local_24 * 2));
    FUN_10001870(&local_28);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10006470(&local_28,local_14);
    if ((local_18 == (void *)0x0) || (local_14 == (void *)0x0)) {
      local_1c = -0x7ff8fff2;
    }
    else {
      FUN_1000c930(local_18,local_20,param_1,local_20);
      FUN_1000c930(local_14,local_24,param_2,local_24);
      iVar3 = FUN_10003890(this,&local_18,&local_14);
      if (iVar3 == 0) {
        local_1c = -0x7ff8fff2;
      }
    }
    if (-1 < local_1c) {
      detach(&local_2c);
      detach(&local_28);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_10002860(&local_28);
    local_8 = 0xffffffff;
    uVar1 = 0x10003ad1;
    FUN_10002840(&local_2c);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10003af0 at 10003af0

void __thiscall FUN_10003af0(void *this,LPCSTR param_1)

{
  LPSTR pCVar1;
  
  pCVar1 = CharNextA(param_1);
  FUN_100048f0(this,param_1,(int)pCVar1 - (int)param_1);
  return;
}



// Function: FUN_10003b20 at 10003b20

void FUN_10003b20(int *param_1)

{
  undefined *puVar1;
  
  puVar1 = FUN_10007070();
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",puVar1);
  return;
}



// Function: FUN_10003b50 at 10003b50

void FUN_10003b50(int param_1)

{
  FUN_10007c20((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10003b70 at 10003b70

void FUN_10003b70(int param_1)

{
  FUN_10008580((undefined4 *)(param_1 + 0xc));
  return;
}



// Function: FUN_10003ba0 at 10003ba0

void FUN_10003ba0(int param_1)

{
  FUN_10007c00((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_10003bd0 at 10003bd0

int FUN_10003bd0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10007c00((LONG *)(param_1 + 4));
  if (iVar1 == 2) {
    (**(code **)(*DAT_10035308 + 4))();
  }
  return iVar1;
}



// Function: FUN_10003c10 at 10003c10

undefined4 FUN_10003c10(void)

{
  return 1;
}



// Function: FUN_10003c20 at 10003c20

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10003c20(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_4c;
  undefined4 local_48;
  UINT local_44;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined4 local_34;
  LPSTR local_30;
  LPSTR local_2c;
  char *local_28;
  char *local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022928;
  local_10 = ExceptionList;
  local_4c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_4c;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    FUN_10008240();
    local_44 = FUN_1000bd10();
    FUN_10001830((undefined4 *)local_20);
    local_8 = 0;
    local_1c = param_2;
    if (param_2 == (wchar_t *)0x0) {
      local_28 = (char *)0x0;
    }
    else {
      sVar2 = wcslen(param_2);
      local_18 = sVar2 + 1;
      lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
      if (lVar3 < 0) {
        local_30 = (LPSTR)0x0;
      }
      else {
        if (((int)local_18 < 0x401) && (cVar1 = FUN_1000bde0(local_18), cVar1 != '\0')) {
          local_38 = (undefined1 *)&local_4c;
          local_2c = (LPSTR)&local_4c;
        }
        else {
          local_2c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                            CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                      (local_20,local_18);
        }
        local_30 = FUN_10006400(local_2c,local_1c,local_18,local_44);
      }
      local_28 = local_30;
    }
    local_24 = local_28;
    if (local_28 == (char *)0x0) {
      local_3c = 0x8007000e;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    }
    else {
      local_40 = FUN_10003930((void *)(param_1 + 4),local_28,param_3);
      FUN_1000ad90();
      if (local_40 == 0) {
        local_34 = 0x8007000e;
      }
      else {
        local_34 = 0;
      }
      local_48 = local_34;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    }
  }
  ExceptionList = local_10;
  local_4c = 0x10003db4;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003dc0 at 10003dc0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10003dc0(void *this,wchar_t *param_1)

{
  char cVar1;
  long lVar2;
  size_t sVar3;
  uint local_48;
  undefined4 local_44;
  undefined1 *local_40;
  void *local_3c;
  undefined4 local_38;
  UINT local_34;
  char *local_30;
  LPSTR local_2c;
  LPSTR local_28;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_24 [4];
  char *local_20;
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022958;
  local_10 = ExceptionList;
  local_48 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = this;
  local_14 = local_48;
  if (param_1 != (wchar_t *)0x0) {
    local_34 = FUN_1000bd10();
    FUN_10001830((undefined4 *)local_24);
    local_8 = 0;
    local_1c = param_1;
    if (param_1 == (wchar_t *)0x0) {
      local_30 = (char *)0x0;
    }
    else {
      sVar3 = wcslen(param_1);
      local_18 = sVar3 + 1;
      lVar2 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
      if (lVar2 < 0) {
        local_28 = (LPSTR)0x0;
      }
      else {
        if (((int)local_18 < 0x401) && (cVar1 = FUN_1000bde0(local_18), cVar1 != '\0')) {
          local_40 = (undefined1 *)&local_48;
          local_2c = (LPSTR)&local_48;
        }
        else {
          local_2c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                            CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                      (local_24,local_18);
        }
        local_28 = FUN_10006400(local_2c,local_1c,local_18,local_34);
      }
      local_30 = local_28;
    }
    local_20 = local_30;
    if (local_30 == (char *)0x0) {
      local_38 = 0;
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_24);
    }
    else {
      sVar3 = strlen(local_30);
      local_44 = FUN_100048f0(local_3c,local_20,sVar3);
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_24);
    }
  }
  ExceptionList = local_10;
  local_48 = 0x10003f22;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003f30 at 10003f30

void __thiscall FUN_10003f30(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 local_c;
  
  if (this == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = (int)this + 4;
  }
  FUN_10005810(local_c,param_1,param_2);
  return;
}



// Function: FUN_10003f70 at 10003f70

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10003f70(void *this,void *param_1,LPCSTR param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  UINT UVar3;
  size_t sVar4;
  long lVar5;
  uint uStack_1298;
  undefined1 auStack_1274 [4];
  LPWSTR pWStack_1270;
  LPWSTR pWStack_1268;
  LPWSTR pWStack_1264;
  LPWSTR pWStack_1260;
  BYTE *pBStack_1258;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> aCStack_1254 [4];
  size_t sStack_1250;
  uint uStack_124c;
  uint local_1248;
  uint local_1244;
  ushort local_1240 [2];
  undefined4 *local_123c;
  ulong local_1234;
  ulong uStack_1230;
  int local_122c;
  undefined4 local_1220 [65];
  undefined4 auStack_111c [65];
  BYTE local_1018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100229a1;
  local_10 = ExceptionList;
  uStack_1298 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1298;
  ExceptionList = &local_10;
  local_1240[0] = 0;
  local_1234 = 0;
  local_123c = (undefined4 *)this;
  local_18 = uStack_1298;
  local_122c = FUN_100082d0(this,local_1018);
  if (-1 < local_122c) {
    iVar2 = FUN_1000bbf0((LPCSTR)local_1018,local_1240);
    if (iVar2 == 0) {
      FUN_10007050();
    }
    else {
      FUN_1000ab20(local_123c);
      local_122c = FUN_100082d0(local_123c,local_1018);
      if (-1 < local_122c) {
        local_1244 = (uint)local_1240[0];
        if (local_1244 < 0x14) {
          if (local_1244 == 0x13) {
            UVar3 = FUN_1000bd10();
            FUN_10001830((undefined4 *)aCStack_1254);
            local_8 = 3;
            pBStack_1258 = local_1018;
            if (pBStack_1258 == (BYTE *)0x0) {
              pWStack_1264 = (LPWSTR)0x0;
            }
            else {
              sVar4 = strlen((char *)pBStack_1258);
              uStack_1230 = sVar4 + 1;
              lVar5 = ATL::AtlMultiply<int>((int *)&uStack_1230,uStack_1230,2);
              if (lVar5 < 0) {
                pWStack_1270 = (LPWSTR)0x0;
              }
              else {
                if (((int)uStack_1230 < 0x401) && (cVar1 = FUN_1000bde0(uStack_1230), cVar1 != '\0')
                   ) {
                  pWStack_1268 = (LPWSTR)&uStack_1298;
                  local_14 = (undefined1 *)&uStack_1298;
                }
                else {
                  pWStack_1268 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                                         Allocate(aCStack_1254,uStack_1230);
                }
                pWStack_1270 = FUN_10004a10(pWStack_1268,(LPCSTR)pBStack_1258,uStack_1230 >> 1,UVar3
                                           );
              }
              pWStack_1264 = pWStack_1270;
            }
            pWStack_1260 = pWStack_1264;
            if (pWStack_1264 == (LPWSTR)0x0) {
              local_8 = 0xffffffff;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(aCStack_1254);
              goto LAB_10004643;
            }
            Ordinal_277(pWStack_1264,0,0,auStack_1274);
            local_1234 = FUN_1000a8f0(param_1,param_2);
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(aCStack_1254);
          }
          else if (local_1244 == 8) {
            local_1234 = FUN_1000a9c0(param_1,param_2,local_1018,1);
          }
          else if (local_1244 == 0x11) {
            sStack_1250 = strlen((char *)local_1018);
            if ((sStack_1250 & 1) == 0) {
              uStack_124c = (int)sStack_1250 / 2;
              FUN_10001ec0(auStack_111c);
              local_8 = 5;
              Allocate(auStack_111c,uStack_124c);
              FUN_100044c2();
              return;
            }
            goto LAB_10004643;
          }
        }
        else if (local_1244 == 0x4008) {
          sVar4 = strlen((char *)local_1018);
          local_1248 = sVar4 + 2;
          FUN_10001e80(local_1220);
          local_8 = 1;
          Allocate(local_1220,local_1248);
          FUN_10004112();
          return;
        }
        if (local_1234 == 0) {
          local_122c = FUN_100082d0(local_123c,param_3);
        }
        else {
          FUN_10005010(local_1234);
        }
      }
    }
  }
LAB_10004643:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000410c at 1000410c

undefined * Catch_1000410c(void)

{
  return &DAT_1000411b;
}



// Function: FUN_10004112 at 10004112

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10004112(void)

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
  iVar2 = FUN_10003530((undefined4 *)(unaff_EBP - 0x121c));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 0x1230) = 0xe;
  }
  else {
    uVar3 = FUN_10003530((undefined4 *)(unaff_EBP - 0x121c));
    *(undefined4 *)(unaff_EBP - 0x1220) = uVar3;
    *(uint *)(unaff_EBP - 0x1224) = unaff_EBP - 0x1014;
    *(undefined4 *)(unaff_EBP - 0x1244) = 0;
    while (**(char **)(unaff_EBP - 0x1224) != '\0') {
      pCVar4 = CharNextA(*(LPCSTR *)(unaff_EBP - 0x1224));
      *(LPSTR *)(unaff_EBP - 0x1258) = pCVar4;
      if ((**(char **)(unaff_EBP - 0x1224) == '\\') && (**(char **)(unaff_EBP - 0x1258) == '0')) {
        **(undefined1 **)(unaff_EBP - 0x1220) = 0;
        *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
        pCVar4 = CharNextA(*(LPCSTR *)(unaff_EBP - 0x1258));
        *(LPSTR *)(unaff_EBP - 0x1224) = pCVar4;
      }
      else {
        **(undefined1 **)(unaff_EBP - 0x1220) = **(undefined1 **)(unaff_EBP - 0x1224);
        BVar5 = IsDBCSLeadByte(**(BYTE **)(unaff_EBP - 0x1224));
        if (BVar5 != 0) {
          *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
          *(int *)(unaff_EBP - 0x1224) = *(int *)(unaff_EBP - 0x1224) + 1;
          if (**(char **)(unaff_EBP - 0x1224) == '\0') break;
          **(undefined1 **)(unaff_EBP - 0x1220) = **(undefined1 **)(unaff_EBP - 0x1224);
        }
        *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
        *(int *)(unaff_EBP - 0x1224) = *(int *)(unaff_EBP - 0x1224) + 1;
      }
      *(int *)(unaff_EBP - 0x1244) = *(int *)(unaff_EBP - 0x1244) + 1;
    }
    **(undefined1 **)(unaff_EBP - 0x1220) = 0;
    *(int *)(unaff_EBP - 0x1220) = *(int *)(unaff_EBP - 0x1220) + 1;
    **(undefined1 **)(unaff_EBP - 0x1220) = 0;
    pBVar6 = (BYTE *)FUN_10003530((undefined4 *)(unaff_EBP - 0x121c));
    LVar7 = FUN_1000a920(*(void **)(unaff_EBP + 8),*(LPCSTR *)(unaff_EBP + 0xc),pBVar6);
    *(LSTATUS *)(unaff_EBP - 0x1230) = LVar7;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ~CTempBuffer<>((int *)(unaff_EBP - 0x121c));
  if (*(int *)(unaff_EBP - 0x1230) == 0) {
    uVar3 = FUN_100082d0(*(void **)(unaff_EBP - 0x1238),*(undefined1 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP - 0x1228) = uVar3;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x1280) = 0x204;
    FUN_10005010(*(ulong *)(unaff_EBP - 0x1230));
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x1288) = 0x10004661;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: Catch@100044bc at 100044bc

undefined * Catch_100044bc(void)

{
  return &DAT_100044cb;
}



// Function: FUN_100044c2 at 100044c2

/* WARNING: Unable to track spacebase fully for stack */

void FUN_100044c2(void)

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
  iVar1 = FUN_10003550((undefined4 *)(unaff_EBP - 0x1118));
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP - 0x1278) = 0x80004005;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    ~CTempBuffer<>((int *)(unaff_EBP - 0x1118));
  }
  else {
    _Size = *(size_t *)(unaff_EBP - 0x1248);
    iVar1 = 0;
    _Dst = (void *)FUN_10003550((undefined4 *)(unaff_EBP - 0x1118));
    memset(_Dst,iVar1,_Size);
    *(undefined4 *)(unaff_EBP - 0x1234) = 0;
    while (*(int *)(unaff_EBP - 0x1234) < *(int *)(unaff_EBP - 0x124c)) {
      iVar1 = FUN_10003550((undefined4 *)(unaff_EBP - 0x1118));
      *(int *)(unaff_EBP - 0x1268) = iVar1 + *(int *)(unaff_EBP - 0x1234) / 2;
      uVar2 = FUN_10006540(*(char *)((unaff_EBP - 0x1014) + *(int *)(unaff_EBP - 0x1234)));
      **(byte **)(unaff_EBP - 0x1268) =
           **(byte **)(unaff_EBP - 0x1268) |
           (byte)((uVar2 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP - 0x1234) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP - 0x1234) = *(int *)(unaff_EBP - 0x1234) + 1;
    }
    cbData = *(DWORD *)(unaff_EBP - 0x1248);
    lpData = (BYTE *)FUN_10003550((undefined4 *)(unaff_EBP - 0x1118));
    dwType = 3;
    Reserved = 0;
    lpValueName = *(LPCSTR *)(unaff_EBP + 0xc);
    hKey = (HKEY)FUN_10003570(*(undefined4 **)(unaff_EBP + 8));
    LVar3 = RegSetValueExA(hKey,lpValueName,Reserved,dwType,lpData,cbData);
    *(LSTATUS *)(unaff_EBP - 0x1230) = LVar3;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    ~CTempBuffer<>((int *)(unaff_EBP - 0x1118));
    if (*(int *)(unaff_EBP - 0x1230) == 0) {
      uVar4 = FUN_100082d0(*(void **)(unaff_EBP - 0x1238),*(undefined1 **)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP - 0x1228) = uVar4;
    }
    else {
      *(undefined4 *)(unaff_EBP - 0x1280) = 0x204;
      FUN_10005010(*(ulong *)(unaff_EBP - 0x1230));
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar2 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x1288) = 0x10004661;
  __security_check_cookie(uVar2 ^ unaff_EBP);
  return;
}



// Function: Allocate at 10004670

/* Library Function - Single Match
    public: void * __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::Allocate(unsigned long)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void * __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
          (CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *this,ulong param_1)

{
  ulong uVar1;
  CAtlSafeAllocBufferNode *this_00;
  void *pvVar2;
  
  uVar1 = AtlAddThrow<unsigned_long>(param_1,8);
  this_00 = (CAtlSafeAllocBufferNode *)FUN_10004750(uVar1);
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



// Function: Allocate at 100046c0

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_10004770(this,uVar1);
  return;
}



// Function: Allocate at 100046f0

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_100047b0(this,uVar1);
  return;
}



// Function: Allocate at 10004720

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  FUN_100047f0(this,uVar1);
  return;
}



// Function: FUN_10004750 at 10004750

void __cdecl FUN_10004750(size_t param_1)

{
  malloc(param_1);
  return;
}



// Function: FUN_10004770 at 10004770

undefined4 __thiscall FUN_10004770(void *this,uint param_1)

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



// Function: FUN_100047b0 at 100047b0

undefined4 __thiscall FUN_100047b0(void *this,uint param_1)

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



// Function: FUN_100047f0 at 100047f0

undefined4 __thiscall FUN_100047f0(void *this,uint param_1)

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



// Function: AllocateHeap at 10004830

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10004750(param_1);
  if (iVar1 == 0) {
    FUN_10006230(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: AllocateHeap at 10004870

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10004750(param_1);
  if (iVar1 == 0) {
    FUN_10006230(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: AllocateHeap at 100048b0

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::AllocateHeap(unsigned int)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall AllocateHeap(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10004750(param_1);
  if (iVar1 == 0) {
    FUN_10006230(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: FUN_100048f0 at 100048f0

undefined4 __thiscall FUN_100048f0(void *this,void *param_1,rsize_t param_2)

{
  int iVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this + 1 + param_2;
                    /* WARNING: Load size is inaccurate */
  if ((*this < iVar1) && ((int)param_2 < iVar1)) {
    if (*(int *)((int)this + 4) <= iVar1) {
      while (*(int *)((int)this + 4) <= iVar1) {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          return 0;
        }
        *(int *)((int)this + 4) = *(int *)((int)this + 4) << 1;
      }
      pvVar3 = FUN_10004b10(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),1);
      if (pvVar3 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar3;
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((*this < 0) || (*(int *)((int)this + 4) <= *this)) ||
       (*(int *)((int)this + 4) < *(int *)((int)this + 4) - *this)) {
      uVar2 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      FUN_1000c930((void *)(*(int *)((int)this + 8) + *this),*(int *)((int)this + 4) - *this,param_1
                   ,param_2);
                    /* WARNING: Load size is inaccurate */
      *(rsize_t *)this = *this + param_2;
                    /* WARNING: Load size is inaccurate */
      *(undefined1 *)(*(int *)((int)this + 8) + *this) = 0;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10004a10 at 10004a10

LPWSTR FUN_10004a10(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

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



// Function: AtlCallTermFunc at 10004a60

/* Library Function - Single Match
    void __stdcall ATL::AtlCallTermFunc(struct ATL::_ATL_MODULE70 *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void ATL::AtlCallTermFunc(_ATL_MODULE70 *param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  if (param_1 == (_ATL_MODULE70 *)0x0) {
    _AtlRaiseException(0xc0000005,1);
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



// Function: AtlCoTaskMemCAlloc at 10004ad0

/* Library Function - Single Match
    void * __cdecl ATL::AtlCoTaskMemCAlloc(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void * __cdecl ATL::AtlCoTaskMemCAlloc(ulong param_1,ulong param_2)

{
  HRESULT HVar1;
  void *pvVar2;
  SIZE_T local_8;
  
  local_8 = 0;
  HVar1 = AtlMultiply<>(&local_8,param_1,param_2);
  if (HVar1 < 0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = CoTaskMemAlloc(local_8);
  }
  return pvVar2;
}



// Function: FUN_10004b10 at 10004b10

LPVOID __cdecl FUN_10004b10(LPVOID param_1,uint param_2,uint param_3)

{
  HRESULT HVar1;
  LPVOID pvVar2;
  SIZE_T local_8;
  
  local_8 = 0;
  HVar1 = AtlMultiply<>(&local_8,param_2,param_3);
  if (HVar1 < 0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    pvVar2 = CoTaskMemRealloc(param_1,local_8);
  }
  return pvVar2;
}



// Function: FUN_10004b50 at 10004b50

int FUN_10004b50(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  PVOID pvVar3;
  CComCritSecLock<class_ATL::CComCriticalSection> local_30 [8];
  PVOID local_28;
  undefined4 *local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100229d8;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_4 == (int *)0x0) {
    local_14 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    if (param_1 == (int *)0x0) {
      local_14 = -0x7ff8ffa9;
    }
    else if (*param_1 == 0) {
      local_14 = -0x7fff0001;
    }
    else {
      local_14 = 0;
      for (local_18 = (int *)param_1[2]; local_18 < (int *)param_1[3]; local_18 = local_18 + 1) {
        if (((*local_18 != 0) && (local_1c = (undefined4 *)*local_18, local_1c[2] != 0)) &&
           (iVar2 = FUN_1000cd40(param_2,(int *)*local_1c), iVar2 != 0)) {
          local_20 = (int *)local_1c[4];
          if (*local_20 == 0) {
            ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
            CComCritSecLock<class_ATL::CComCriticalSection>
                      (local_30,(CComCriticalSection *)(param_1 + 4),false);
            local_8 = 0;
            local_14 = FUN_100081c0((undefined4 *)local_30);
            if (local_14 < 0) {
              local_8 = 0xffffffff;
              ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
              ~CComCritSecLock<class_ATL::CComCriticalSection>(local_30);
              break;
            }
            if ((*local_20 == 0) &&
               (local_14 = (*(code *)local_1c[2])(local_1c[3],&DAT_10029b80,&local_28,uVar1),
               -1 < local_14)) {
              pvVar3 = EncodePointer(local_28);
              *local_20 = (int)pvVar3;
            }
            local_8 = 0xffffffff;
            ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
            ~CComCritSecLock<class_ATL::CComCriticalSection>(local_30);
          }
          if (*local_20 != 0) {
            local_24 = (undefined4 *)DecodePointer((PVOID)*local_20);
            local_14 = (**(code **)*local_24)(local_24,param_3,param_4);
          }
          break;
        }
      }
      if ((*param_4 == 0) && (local_14 == 0)) {
        local_14 = -0x7ffbfeef;
      }
    }
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10004d10 at 10004d10

int FUN_10004d10(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
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
          (bVar2 = FUN_1000cde0(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        iVar4 = 1;
        piVar3 = (int *)(*(code *)puVar1[6])();
        local_8 = FUN_10005900((GUID *)*puVar1,piVar3,iVar4);
        if (local_8 < 0) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10005f30(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return local_8;
}



// Function: FUN_10004de0 at 10004de0

int FUN_10004de0(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
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
          (bVar2 = FUN_1000cde0(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar4 = 0;
        piVar3 = (int *)(*(code *)puVar1[6])();
        local_8 = FUN_10005900((GUID *)*puVar1,piVar3,iVar4);
        if ((local_8 < 0) || (local_8 = (*(code *)puVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10006260(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return local_8;
}



// Function: FUN_10004eb0 at 10004eb0

int FUN_10004eb0(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if ((param_2 == (undefined4 *)0x0) ||
       (iVar2 = (**(code **)*param_2)(param_2,param_3,param_1), iVar2 < 0)) {
      *param_1 = 0;
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    return *param_1;
  }
  return 0;
}



// Function: AtlCrtErrorCheck at 10004f10

/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug, Visual
   Studio 2012 Debug */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_10006230(0x80004005);
    break;
  case 0xc:
    FUN_10006230(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_10006230(0x80070057);
  }
  return param_1;
}



// Function: FUN_10004fc0 at 10004fc0

undefined4 FUN_10004fc0(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1003532c;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10004ff0 at 10004ff0

void FUN_10004ff0(void)

{
  DWORD x;
  
  x = GetLastError();
  _HRESULT_FROM_WIN32(x);
  return;
}



// Function: FUN_10005010 at 10005010

void __cdecl FUN_10005010(ulong param_1)

{
  _HRESULT_FROM_WIN32(param_1);
  return;
}



// Function: FUN_10005030 at 10005030

int FUN_10005030(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_8;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    local_8 = -0x7ff8ffa9;
  }
  else if (param_4 == (undefined4 *)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    iVar1 = FUN_10007b90(param_3);
    if (iVar1 == 0) {
      for (; param_2[2] != 0; param_2 = param_2 + 3) {
        iVar1 = *param_2;
        if ((iVar1 == 0) || (iVar2 = FUN_1000cd40((int *)*param_2,param_3), iVar2 != 0)) {
          if (param_2[2] == 1) {
            piVar3 = (int *)(param_1 + param_2[1]);
            (**(code **)(*piVar3 + 4))(piVar3);
            *param_4 = piVar3;
            return 0;
          }
          local_8 = (*(code *)param_2[2])(param_1,param_3,param_4,param_2[1]);
          if (local_8 == 0) {
            return 0;
          }
          if ((iVar1 != 0) && (local_8 < 0)) goto LAB_10005156;
        }
      }
      local_8 = -0x7fffbffe;
LAB_10005156:
      *param_4 = 0;
    }
    else {
      piVar3 = (int *)(param_1 + param_2[1]);
      (**(code **)(*piVar3 + 4))(piVar3);
      *param_4 = piVar3;
      local_8 = 0;
    }
  }
  return local_8;
}



// Function: FUN_10005170 at 10005170

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10005170(HMODULE param_1,wchar_t *param_2,int *param_3,undefined4 *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  int iVar4;
  uint local_1b4;
  HRESULT local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined1 *local_1a4;
  int local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined1 *local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined1 *local_184;
  LPSTR local_180;
  LPSTR local_17c;
  size_t local_178;
  LPWSTR local_174;
  LPWSTR local_170;
  LPWSTR local_16c;
  LPWSTR local_168;
  char *local_164;
  LPWSTR local_160;
  LPWSTR local_15c;
  uint local_158;
  char *local_154;
  wchar_t *local_150;
  UINT local_14c;
  LPCSTR local_148;
  int local_144;
  LPWSTR local_140;
  DWORD local_13c;
  char *local_138;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_134 [4];
  ulong local_130;
  CHAR local_12c [272];
  char local_1c [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022a0b;
  local_10 = ExceptionList;
  local_1b4 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_1b4;
  if ((param_3 != (int *)0x0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    local_14c = FUN_1000bd10();
    FUN_10001830((undefined4 *)local_134);
    local_8 = 0;
    local_13c = GetModuleFileNameA(param_1,local_12c,0x104);
    if (local_13c == 0) {
      local_1a8 = FUN_10004ff0();
      local_8 = 0xffffffff;
      local_18c = local_1a8;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
    }
    else if (local_13c == 0x104) {
      local_1b0 = _HRESULT_FROM_WIN32(0x7a);
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
    }
    else {
      local_148 = (LPCSTR)0x0;
      local_148 = FUN_100012c0(local_12c);
      if (param_2 != (wchar_t *)0x0) {
        local_150 = param_2;
        if (param_2 == (wchar_t *)0x0) {
          local_164 = (char *)0x0;
        }
        else {
          sVar2 = wcslen(param_2);
          local_130 = sVar2 + 1;
          lVar3 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
          if (lVar3 < 0) {
            local_180 = (LPSTR)0x0;
          }
          else {
            if (((int)local_130 < 0x401) && (cVar1 = FUN_1000bde0(local_130), cVar1 != '\0')) {
              local_184 = (undefined1 *)&local_1b4;
              local_17c = (LPSTR)&local_1b4;
            }
            else {
              local_17c = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                 CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                           (local_134,local_130);
            }
            local_180 = FUN_10006400(local_17c,local_150,local_130,local_14c);
          }
          local_164 = local_180;
        }
        local_154 = local_164;
        if (local_164 == (char *)0x0) {
          local_1ac = 0x8007000e;
          local_8 = 0xffffffff;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
          goto LAB_100057ec;
        }
        local_178 = strlen(local_164);
        local_158 = local_13c + local_178;
        if (((local_158 < local_13c) || (local_158 < local_178)) || (0x10d < local_158)) {
          local_194 = 0x80004005;
          local_8 = 0xffffffff;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
          goto LAB_100057ec;
        }
        FUN_1000cc40(local_12c + local_13c,0x10e - local_13c,local_154);
      }
      local_138 = local_12c;
      if (local_138 == (char *)0x0) {
        local_15c = (LPWSTR)0x0;
      }
      else {
        sVar2 = strlen(local_138);
        local_130 = sVar2 + 1;
        lVar3 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
        if (lVar3 < 0) {
          local_16c = (LPWSTR)0x0;
        }
        else {
          if (((int)local_130 < 0x401) && (cVar1 = FUN_1000bde0(local_130), cVar1 != '\0')) {
            local_1a4 = (undefined1 *)&local_1b4;
            local_174 = (LPWSTR)&local_1b4;
          }
          else {
            local_174 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                          (local_134,local_130);
          }
          local_16c = FUN_10004a10(local_174,local_138,local_130 >> 1,local_14c);
        }
        local_15c = local_16c;
      }
      local_140 = local_15c;
      if (local_15c == (LPWSTR)0x0) {
        local_19c = 0x8007000e;
        local_8 = 0xffffffff;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
      }
      else {
        local_144 = Ordinal_161();
        if (local_144 < 0) {
          builtin_strncpy(local_1c,".tlb",5);
          if ((char *)0x104 < local_148 + (5 - (int)local_12c)) {
            local_188 = 0x80004005;
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
            goto LAB_100057ec;
          }
          FUN_1000cc40(local_148,0x10e - ((int)local_148 - (int)local_12c),local_1c);
          local_138 = local_12c;
          if (local_138 == (char *)0x0) {
            local_170 = (LPWSTR)0x0;
          }
          else {
            sVar2 = strlen(local_138);
            local_130 = sVar2 + 1;
            lVar3 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
            if (lVar3 < 0) {
              local_168 = (LPWSTR)0x0;
            }
            else {
              if (((int)local_130 < 0x401) && (cVar1 = FUN_1000bde0(local_130), cVar1 != '\0')) {
                local_190 = &stack0xfffffe44;
                local_160 = (LPWSTR)&stack0xfffffe44;
              }
              else {
                local_160 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                    CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                              (local_134,local_130);
              }
              local_168 = FUN_10004a10(local_160,local_138,local_130 >> 1,local_14c);
            }
            local_170 = local_168;
          }
          local_140 = local_170;
          if (local_170 == (LPWSTR)0x0) {
            local_198 = 0x8007000e;
            local_8 = 0xffffffff;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
            goto LAB_100057ec;
          }
          local_144 = Ordinal_161(local_170,param_4);
        }
        if (-1 < local_144) {
          iVar4 = Ordinal_2(local_140);
          *param_3 = iVar4;
          if (*param_3 == 0) {
            local_144 = -0x7ff8fff2;
            (**(code **)(*(int *)*param_4 + 8))(*param_4);
            *param_4 = 0;
          }
        }
        local_1a0 = local_144;
        local_8 = 0xffffffff;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_134);
      }
    }
  }
LAB_100057ec:
  ExceptionList = local_10;
  local_1b4 = 0x10005807;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005810 at 10005810

int FUN_10005810(int param_1,undefined4 param_2,undefined4 param_3)

{
  CComCritSecLock<class_ATL::CComCriticalSection> local_28 [8];
  undefined4 *local_20;
  undefined4 *local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022a48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    local_18 = -0x7ff8ffa9;
  }
  else {
    local_18 = 0;
    local_1c = (undefined4 *)FUN_10021550(0xc);
    if (local_1c == (undefined4 *)0x0) {
      local_18 = -0x7ff8fff2;
    }
    else {
      *local_1c = param_2;
      local_1c[1] = param_3;
      local_14 = local_1c;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      CComCritSecLock<class_ATL::CComCriticalSection>
                (local_28,(CComCriticalSection *)(param_1 + 0xc),false);
      local_8 = 0;
      local_18 = FUN_100081c0((undefined4 *)local_28);
      if (local_18 < 0) {
        local_20 = local_14;
        operator_delete(local_14);
      }
      else {
        local_14[2] = *(undefined4 *)(param_1 + 8);
        *(undefined4 **)(param_1 + 8) = local_14;
      }
      local_8 = 0xffffffff;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      ~CComCritSecLock<class_ATL::CComCriticalSection>(local_28);
    }
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10005900 at 10005900

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10005900(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  LPVOID *ppv;
  size_t sVar4;
  long lVar5;
  HKEY pHVar6;
  LPSTR pCVar7;
  LPDWORD pDVar8;
  LPDWORD pDVar9;
  DWORD *pDVar10;
  LPDWORD pDVar11;
  LPDWORD pDVar12;
  LPDWORD pDVar13;
  LPDWORD pDVar14;
  LPDWORD pDVar15;
  char *pcVar16;
  LPDWORD pDVar17;
  REGSAM RVar18;
  PFILETIME p_Var19;
  uint local_19c;
  undefined1 *local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  UINT local_184;
  CRegKey local_180 [12];
  int local_174;
  CRegKey local_170 [12];
  int *local_164;
  int *local_160;
  int *local_15c;
  LPSTR local_158;
  int *local_154;
  LPSTR local_150;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_14c [4];
  LPSTR local_148;
  wchar_t *local_144;
  LPSTR local_140;
  DWORD local_13c;
  int *local_138;
  HRESULT local_134;
  ulong local_130;
  long local_12c;
  int local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  OLECHAR local_114 [64];
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022a9c;
  local_10 = ExceptionList;
  local_19c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_19c;
  FUN_10001b80(&local_128);
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    local_190 = 0;
    local_8 = 0xffffffff;
    FID_conflict__bad_alloc(&local_128);
  }
  else {
    iVar3 = FUN_1000cd40((int *)param_1,(int *)&DAT_1002e9b4);
    if (iVar3 == 0) {
      ppv = (LPVOID *)FUN_100035b0(&local_128);
      local_134 = CoCreateInstance((IID *)&DAT_1002f704,(LPUNKNOWN)0x0,1,(IID *)&DAT_1002a418,ppv);
      if (local_134 < 0) {
        local_188 = 0;
        local_8 = 0xffffffff;
        FID_conflict__bad_alloc(&local_128);
      }
      else {
        local_134 = 0;
        for (local_138 = param_2; *local_138 != 0; local_138 = local_138 + 2) {
          puVar1 = (undefined4 *)local_138[1];
          local_124 = *puVar1;
          local_120 = puVar1[1];
          local_11c = puVar1[2];
          local_118 = puVar1[3];
          if (param_3 == 0) {
            if (*local_138 == 1) {
              local_160 = (int *)FUN_10003580(&local_128);
              (**(code **)(*local_160 + 0x18))(local_160,param_1,1,&local_124);
            }
            else {
              local_15c = (int *)FUN_10003580(&local_128);
              (**(code **)(*local_15c + 0x20))(local_15c,param_1,1,&local_124);
            }
          }
          else {
            if (*local_138 == 1) {
              local_154 = (int *)FUN_10003580(&local_128);
              local_134 = (**(code **)(*local_154 + 0x14))(local_154,param_1,1,&local_124);
            }
            else {
              local_164 = (int *)FUN_10003580(&local_128);
              local_134 = (**(code **)(*local_164 + 0x1c))(local_164,param_1,1,&local_124);
            }
            if (local_134 < 0) {
              local_174 = local_134;
              local_8 = 0xffffffff;
              FID_conflict__bad_alloc(&local_128);
              goto LAB_10005f0e;
            }
          }
        }
        if (param_3 == 0) {
          StringFromGUID2(param_1,local_114,0x40);
          local_184 = FUN_1000bd10();
          FUN_10001830((undefined4 *)local_14c);
          local_8._0_1_ = 1;
          local_144 = local_114;
          if (local_144 == (wchar_t *)0x0) {
            local_158 = (LPSTR)0x0;
          }
          else {
            sVar4 = wcslen(local_144);
            local_130 = sVar4 + 1;
            lVar5 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
            if (lVar5 < 0) {
              local_148 = (LPSTR)0x0;
            }
            else {
              if (((int)local_130 < 0x401) && (cVar2 = FUN_1000bde0(local_130), cVar2 != '\0')) {
                local_198 = (undefined1 *)&local_19c;
                local_150 = (LPSTR)&local_19c;
              }
              else {
                local_150 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                   CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                             (local_14c,local_130);
              }
              local_148 = FUN_10006400(local_150,local_144,local_130,local_184);
            }
            local_158 = local_148;
          }
          local_140 = local_158;
          if (local_158 != (LPSTR)0x0) {
            FUN_1000cc40(local_94,0x80,"CLSID\\");
            FUN_1000cc10(local_94,0x80,local_140);
            FUN_1000cc10(local_94,0x80,"\\Required Categories");
            ATL::CRegKey::CRegKey(local_180,(HKEY__ *)0x80000000);
            local_8._0_1_ = 2;
            ATL::CRegKey::CRegKey(local_170,(CAtlTransactionManager *)0x0);
            local_8 = CONCAT31(local_8._1_3_,3);
            local_13c = 0;
            RVar18 = 0x20019;
            pcVar16 = local_94;
            pHVar6 = (HKEY)FUN_10003570((undefined4 *)local_180);
            local_12c = FUN_100084f0(local_170,pHVar6,pcVar16,RVar18);
            if (local_12c == 0) {
              p_Var19 = (PFILETIME)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = (LPDWORD)0x0;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = &local_13c;
              pDVar9 = (LPDWORD)0x0;
              pDVar8 = (LPDWORD)0x0;
              pCVar7 = (LPSTR)0x0;
              pHVar6 = (HKEY)FUN_10003570((undefined4 *)local_170);
              local_12c = RegQueryInfoKeyA(pHVar6,pCVar7,pDVar8,pDVar9,pDVar10,pDVar11,pDVar12,
                                           pDVar13,pDVar14,pDVar15,pDVar17,p_Var19);
              ATL::CRegKey::Close(local_170);
              if ((local_12c == 0) && (local_13c == 0)) {
                FUN_10006bc0(local_180,local_94);
              }
            }
            FUN_1000cc40(local_94,0x80,"CLSID\\");
            FUN_1000cc10(local_94,0x80,local_140);
            FUN_1000cc10(local_94,0x80,"\\Implemented Categories");
            RVar18 = 0x20019;
            pcVar16 = local_94;
            pHVar6 = (HKEY)FUN_10003570((undefined4 *)local_180);
            local_12c = FUN_100084f0(local_170,pHVar6,pcVar16,RVar18);
            if (local_12c == 0) {
              p_Var19 = (PFILETIME)0x0;
              pDVar17 = (LPDWORD)0x0;
              pDVar15 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = (LPDWORD)0x0;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = &local_13c;
              pDVar9 = (LPDWORD)0x0;
              pDVar8 = (LPDWORD)0x0;
              pCVar7 = (LPSTR)0x0;
              pHVar6 = (HKEY)FUN_10003570((undefined4 *)local_170);
              local_12c = RegQueryInfoKeyA(pHVar6,pCVar7,pDVar8,pDVar9,pDVar10,pDVar11,pDVar12,
                                           pDVar13,pDVar14,pDVar15,pDVar17,p_Var19);
              ATL::CRegKey::Close(local_170);
              if ((local_12c == 0) && (local_13c == 0)) {
                FUN_10006bc0(local_180,local_94);
              }
            }
            local_8._0_1_ = 2;
            FUN_100030f0(local_170);
            local_8._0_1_ = 1;
            FUN_100030f0(local_180);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_14c);
        }
        local_194 = 0;
        local_8 = 0xffffffff;
        FID_conflict__bad_alloc(&local_128);
      }
    }
    else {
      local_18c = 0;
      local_8 = 0xffffffff;
      FID_conflict__bad_alloc(&local_128);
    }
  }
LAB_10005f0e:
  ExceptionList = local_10;
  local_19c = 0x10005f29;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005f30 at 10005f30

/* WARNING: Removing unreachable block (ram,0x10006077) */

void FUN_10005f30(HMODULE param_1,wchar_t *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  rsize_t rVar5;
  int iVar6;
  HMODULE hModule;
  undefined4 uVar7;
  wchar_t *local_23c;
  FARPROC local_234;
  undefined4 local_230;
  int local_22c;
  wchar_t *local_228;
  int local_224;
  char local_21d;
  wchar_t local_21c [259];
  undefined2 uStack_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022af1;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002100(&local_230);
  local_8 = 0;
  FUN_10001cd0(&local_22c);
  local_8._0_1_ = 1;
  puVar2 = (undefined4 *)FUN_100035e0(&local_22c);
  piVar3 = (int *)FUN_10003600(&local_230);
  local_224 = FUN_10005170(param_1,param_2,piVar3,puVar2);
  if (-1 < local_224) {
    local_23c = (wchar_t *)0x0;
    FUN_10002100(&local_228);
    local_8 = CONCAT31(local_8._1_3_,2);
    piVar3 = (int *)FUN_100035a0(&local_22c);
    uVar4 = FUN_10003600(&local_228);
    local_224 = (**(code **)(*piVar3 + 0x24))(piVar3,0xffffffff,0,0,0,uVar4);
    if ((-1 < local_224) && (bVar1 = FUN_100034b0((int *)&local_228), bVar1)) {
      rVar5 = FUN_10007f60(&local_228);
      FUN_1000ccd0(local_21c,0x104,local_228,rVar5);
      uStack_16 = 0;
      iVar6 = FUN_10001330(local_21c);
      if (0x207 < (uint)(iVar6 * 2)) {
        ___report_rangecheckfailure();
      }
      local_21c[iVar6] = L'\0';
      local_23c = local_21c;
    }
    local_234 = (FARPROC)0x0;
    local_21d = '\0';
    local_224 = FUN_10004fc0(&local_21d);
    if (local_224 < 0) {
      local_8._0_1_ = 1;
      FUN_10002f00(&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__bad_alloc(&local_22c);
      local_8 = 0xffffffff;
      FUN_10002f00(&local_230);
      goto LAB_1000620a;
    }
    if ((local_21d == '\x01') &&
       (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
      local_234 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    }
    if (local_234 == (FARPROC)0x0) {
      local_234 = Ordinal_163_exref;
    }
    uVar4 = FUN_10003560(&local_230);
    uVar7 = FUN_10003510(&local_22c);
    local_224 = (*local_234)(uVar7,uVar4,local_23c);
    local_8._0_1_ = 1;
    FUN_10002f00(&local_228);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__bad_alloc(&local_22c);
  local_8 = 0xffffffff;
  FUN_10002f00(&local_230);
LAB_1000620a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006230 at 10006230

void FUN_10006230(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 local_c [4];
  undefined4 local_8;
  
  puVar1 = FUN_10001fe0(local_c,param_1);
  local_8 = *puVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_8,(ThrowInfo *)&DAT_10031794);
}



// Function: FUN_10006260 at 10006260

int FUN_10006260(HMODULE param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  HMODULE hModule;
  undefined4 local_28;
  FARPROC local_24;
  int local_20;
  int local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022b30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002100(&local_28);
  local_8 = 0;
  FUN_10001cd0(&local_20);
  local_8._0_1_ = 1;
  puVar1 = (undefined4 *)FUN_100035e0(&local_20);
  piVar2 = (int *)FUN_10003600(&local_28);
  local_18 = FUN_10005170(param_1,param_2,piVar2,puVar1);
  if (-1 < local_18) {
    piVar2 = (int *)FUN_100035a0(&local_20);
    local_18 = (**(code **)(*piVar2 + 0x1c))(piVar2,&local_1c);
    if (-1 < local_18) {
      local_24 = (FARPROC)0x0;
      local_11 = '\0';
      iVar3 = FUN_10004fc0(&local_11);
      local_18 = iVar3;
      if (iVar3 < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FID_conflict__bad_alloc(&local_20);
        local_8 = 0xffffffff;
        FUN_10002f00(&local_28);
        ExceptionList = local_10;
        return iVar3;
      }
      if ((local_11 == '\x01') &&
         (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
        local_24 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
      }
      if (local_24 == (FARPROC)0x0) {
        local_24 = Ordinal_186_exref;
      }
      local_18 = (*local_24)(local_1c,(uint)*(ushort *)(local_1c + 0x18),
                             (uint)*(ushort *)(local_1c + 0x1a),*(undefined4 *)(local_1c + 0x10),
                             *(undefined4 *)(local_1c + 0x14));
      piVar2 = (int *)FUN_100035a0(&local_20);
      (**(code **)(*piVar2 + 0x30))(piVar2,local_1c);
    }
  }
  iVar3 = local_18;
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__bad_alloc(&local_20);
  local_8 = 0xffffffff;
  FUN_10002f00(&local_28);
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10006400 at 10006400

LPSTR FUN_10006400(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

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



// Function: FUN_10006450 at 10006450

void __thiscall FUN_10006450(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10006470 at 10006470

void __thiscall FUN_10006470(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: Attach at 10006490

/* Library Function - Single Match
    public: void __thiscall ATL::CComBSTR::Attach(wchar_t *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __thiscall ATL::CComBSTR::Attach(CComBSTR *this,wchar_t *param_1)

{
  if (*(wchar_t **)this != param_1) {
    Ordinal_6(*(undefined4 *)this);
    *(wchar_t **)this = param_1;
  }
  return;
}



// Function: FUN_100064c0 at 100064c0

void __thiscall FUN_100064c0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_100064f0 at 100064f0

undefined4 FUN_100064f0(LPCSTR param_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xb < local_8) {
      return 1;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_s_AppID_1002aa0c)[local_8]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: FUN_10006540 at 10006540

uint __cdecl FUN_10006540(char param_1)

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



// Function: FUN_100065e0 at 100065e0

void FUN_100065e0(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FID_conflict__vector_deleting_destructor_(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10006660 at 10006660

undefined4 __fastcall FUN_10006660(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8;
  
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_10007310((int)param_1);
    if (iVar1 <= local_8) break;
    puVar2 = (undefined4 *)FUN_10007290(param_1,local_8);
    operator_delete__((void *)*puVar2);
    puVar2 = (undefined4 *)FUN_10007920(param_1,local_8);
    operator_delete__((void *)*puVar2);
    local_8 = local_8 + 1;
  }
  FUN_1000a130(param_1);
  return 0;
}



// Function: FUN_100066e0 at 100066e0

undefined4 FUN_100066e0(int param_1)

{
  undefined4 uVar1;
  
  FUN_10008240();
  uVar1 = FUN_10006660((int *)(param_1 + 4));
  FUN_1000ad90();
  return uVar1;
}



// Function: Close at 10006720

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::Close(void)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

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



// Function: FUN_10006770 at 10006770

long __thiscall
FUN_10006770(void *this,HKEY param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4,REGSAM param_5,
            LPSECURITY_ATTRIBUTES param_6,DWORD *param_7)

{
  DWORD local_18;
  int local_14;
  long local_10;
  HKEY local_c;
  CRegKey *local_8;
  
  local_c = (HKEY)0x0;
  local_8 = (CRegKey *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_14 = RegCreateKeyExA(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_c,&local_18)
    ;
  }
  else {
    local_14 = FUN_10008c90(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,
                            param_6,&local_c,&local_18);
  }
  local_10 = local_14;
  if (param_7 != (DWORD *)0x0) {
    *param_7 = local_18;
  }
  if (local_14 == 0) {
    local_10 = ATL::CRegKey::Close(local_8);
    *(HKEY *)local_8 = local_c;
  }
  return local_10;
}



// Function: FUN_10006820 at 10006820

undefined4 FUN_10006820(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022b62;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    this = (void *)FUN_10021550(0x90);
    local_8._0_1_ = 1;
    if (this != (void *)0x0) {
      FUN_10001890(this,param_1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar1 = FUN_100068c9();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@100068c3 at 100068c3

undefined * Catch_100068c3(void)

{
  return &DAT_100068d2;
}



// Function: FUN_100068c9 at 100068c9

undefined4 FUN_100068c9(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_1000aa50();
    FUN_10007c60();
    iVar1 = FUN_1000bd20(*(int *)(unaff_EBP + -0x14));
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_10006e70();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar2 = FUN_1000bd00();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    FUN_10007c90();
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100069a0 at 100069a0

undefined4 FUN_100069a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10022b92;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)FUN_10021550(0x84);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100019f0(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_10006a49();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10006a43 at 10006a43

undefined * Catch_10006a43(void)

{
  return &DAT_10006a52;
}



// Function: FUN_10006a49 at 10006a49

undefined4 FUN_10006a49(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_1000aa50();
    FUN_10007c40(*(int *)(unaff_EBP + -0x14));
    uVar1 = FUN_1000bd60(*(int *)(unaff_EBP + -0x14) + 0xc);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_10006ea0();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000bd00();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_10007c70(*(int *)(unaff_EBP + -0x14));
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x14))
                        (*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x30))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10006b20 at 10006b20

undefined4 FUN_10006b20(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 == 0) || (iVar1 = FUN_10007b90(param_3), iVar1 != 0)) {
      local_8 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
    }
    else {
      local_8 = 0x80040110;
    }
  }
  return local_8;
}



// Function: FUN_10006b80 at 10006b80

void FUN_10006b80(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10006ba0 at 10006ba0

void FUN_10006ba0(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10006bc0 at 10006bc0

void __thiscall FUN_10006bc0(void *this,LPCSTR param_1)

{
  if (*(int *)((int)this + 8) == 0) {
                    /* WARNING: Load size is inaccurate */
    RegDeleteKeyA(*this,param_1);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_10008d50(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_10006c10 at 10006c10

void __thiscall FUN_10006c10(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegDeleteValueA(*this,param_1);
  return;
}



// Function: detach at 10006c40

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: detach at 10006c70

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: detach at 10006ca0

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: detach at 10006cd0

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall __crt_unique_heap_ptr<char const ,struct
   __crt_internal_free_policy>::detach(void)
    public: wchar_t const * __thiscall __crt_unique_heap_ptr<wchar_t const ,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_internal_free_policy>::detach(void)
    public: char * __thiscall __crt_unique_heap_ptr<char,struct
   __crt_public_free_policy>::detach(void)
     31 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

undefined4 __fastcall detach(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10006d00 at 10006d00

undefined4 __fastcall FUN_10006d00(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = param_1[2];
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return uVar1;
}



// Function: FUN_10006d40 at 10006d40

undefined4 __fastcall FUN_10006d40(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return uVar1;
}



// Function: FUN_10006d80 at 10006d80

undefined4 __fastcall FUN_10006d80(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if ((*(char *)*param_1 == '\'') && (pCVar1 = CharNextA((LPCSTR)*param_1), *pCVar1 != '\'')) {
    return 1;
  }
  return 0;
}



// Function: FUN_10006dd0 at 10006dd0

void __cdecl FUN_10006dd0(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10006e70 at 10006e70

void FUN_10006e70(void)

{
  FUN_10006ea0();
  FUN_10006ea0();
  return;
}



// Function: FUN_10006ea0 at 10006ea0

undefined4 FUN_10006ea0(void)

{
  return 0;
}



// Function: FUN_10006eb0 at 10006eb0

void FUN_10006eb0(void)

{
  FUN_10007a90();
  return;
}



// Function: FUN_10006ed0 at 10006ed0

void FUN_10006ed0(void)

{
  FUN_10006f00();
  FUN_10006f00();
  return;
}



// Function: FUN_10006f00 at 10006f00

void FUN_10006f00(void)

{
  return;
}



// Function: FUN_10006f10 at 10006f10

int __thiscall FUN_10006f10(void *this,undefined4 *param_1)

{
  bool bVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (*(int *)((int)this + 8) <= local_8) {
      return -1;
    }
                    /* WARNING: Load size is inaccurate */
    bVar1 = FUN_10007df0(*(LPCSTR *)(*this + local_8 * 4),(LPCSTR)*param_1);
    if (bVar1) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}



// Function: Free at 10006f70

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<void *>::Free(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: Free at 10006fa0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall ATL::CAutoVectorPtr<char>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<int>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<unsigned long>::Free(void)
    public: void __thiscall ATL::CAutoVectorPtr<void *>::Free(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall Free(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10006fd0 at 10006fd0

void __cdecl FUN_10006fd0(void *param_1)

{
  free(param_1);
  return;
}



// Function: FreeHeap at 10006ff0

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10006fd0((void *)*param_1);
  return;
}



// Function: FreeHeap at 10007010

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10006fd0((void *)*param_1);
  return;
}



// Function: FreeHeap at 10007030

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,10,class ATL::CCRTAllocator>::FreeHeap(void)
    private: void __thiscall ATL::CTempBuffer<wchar_t,128,class ATL::CCRTAllocator>::FreeHeap(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

void __fastcall FreeHeap(undefined4 *param_1)

{
  FUN_10006fd0((void *)*param_1);
  return;
}



// Function: FUN_10007050 at 10007050

undefined4 FUN_10007050(void)

{
  return 0x80020009;
}



// Function: FUN_10007070 at 10007070

undefined * FUN_10007070(void)

{
  return &DAT_1002aeec;
}



// Function: FUN_10007080 at 10007080

int __thiscall FUN_10007080(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  CComCritSecLock<class_ATL::CComCriticalSection> local_24 [8];
  void *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022be8;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_3 = 0;
  local_18 = 0;
  local_1c = this;
  if (*(int *)((int)this + 0x2c) != 0) {
    for (local_14 = *(int **)((int)this + 0x2c); *local_14 != 0; local_14 = local_14 + 9) {
      if ((local_14[2] != 0) && (iVar2 = FUN_1000cd40(param_1,(int *)*local_14), iVar2 != 0)) {
        if (local_14[4] == 0) {
          ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
          CComCritSecLock<class_ATL::CComCriticalSection>
                    (local_24,(CComCriticalSection *)&DAT_100356cc,false);
          local_8 = 0;
          local_18 = FUN_100081c0((undefined4 *)local_24);
          if (local_18 < 0) {
            local_8 = 0xffffffff;
            ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
            ~CComCritSecLock<class_ATL::CComCriticalSection>(local_24);
            break;
          }
          if (local_14[4] == 0) {
            local_18 = (*(code *)local_14[2])(local_14[3],&DAT_10029b80,local_14 + 4,uVar1);
          }
          local_8 = 0xffffffff;
          ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
          ~CComCritSecLock<class_ATL::CComCriticalSection>(local_24);
        }
        if (local_14[4] != 0) {
          local_18 = (*(code *)**(undefined4 **)local_14[4])(local_14[4],param_2,param_3);
        }
        break;
      }
    }
  }
  if ((*param_3 == 0) && (local_18 == 0)) {
    local_18 = FUN_10004b50((int *)&DAT_100356bc,param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: GetData at 100071f0

/* Library Function - Single Match
    public: void * __thiscall ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class
   ATL::CCRTAllocator>::CAtlSafeAllocBufferNode::GetData(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void * __thiscall
ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
CAtlSafeAllocBufferNode::GetData(CAtlSafeAllocBufferNode *this)

{
  return this + 8;
}



// Function: FUN_10007210 at 10007210

int __thiscall FUN_10007210(void *this,undefined4 *param_1)

{
  int local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_c = CoCreateInstance((IID *)&DAT_1002ebf4,(LPUNKNOWN)0x0,1,(IID *)&DAT_10029bfc,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_c) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_c;
}



// Function: FUN_10007290 at 10007290

int __thiscall FUN_10007290(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    ATL::_AtlRaiseException(0xc000008c,1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this + param_1 * 4;
}



// Function: FUN_100072d0 at 100072d0

undefined4 __fastcall FUN_100072d0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100072f0 at 100072f0

undefined4 __fastcall FUN_100072f0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10007310 at 10007310

undefined4 __fastcall FUN_10007310(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10007330 at 10007330

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10007330(void *this,undefined4 param_1)

{
  char cVar1;
  int iVar2;
  HMODULE hModule;
  size_t sVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  CHAR *lpFilename;
  DWORD nSize;
  uint local_170;
  UINT local_16c;
  undefined4 local_168;
  int local_164;
  int local_160;
  undefined1 *local_15c;
  CComCritSecLock<class_ATL::CComCriticalSection> local_158 [8];
  LPWSTR local_150;
  LPWSTR local_14c;
  DWORD local_148;
  LPWSTR local_144;
  LPWSTR local_140;
  char *local_13c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_138 [4];
  int local_134;
  int local_130;
  int local_12c;
  int *local_128;
  ulong local_124;
  int local_120;
  undefined4 *local_11c;
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022c47;
  local_10 = ExceptionList;
  local_170 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_11c = (undefined4 *)this;
  local_14 = local_170;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
    CComCritSecLock<class_ATL::CComCriticalSection>
              (local_158,(CComCriticalSection *)((int)DAT_10035308 + 0x10),false);
    local_8 = 0;
    local_120 = FUN_100081c0((undefined4 *)local_158);
    if (local_120 < 0) {
      local_8 = 0xffffffff;
      local_164 = local_120;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      ~CComCritSecLock<class_ATL::CComCriticalSection>(local_158);
    }
    else {
      local_120 = -0x7fffbffb;
      if (local_11c[3] == 0) {
        local_128 = (int *)0x0;
        iVar2 = FUN_1000cd40((int *)&DAT_1003530c,(int *)local_11c[1]);
        if (((iVar2 == 0) || (*(short *)(local_11c + 2) != -1)) ||
           (*(short *)((int)local_11c + 10) != -1)) {
          local_120 = Ordinal_162(local_11c[1],*(undefined2 *)(local_11c + 2),
                                  *(undefined2 *)((int)local_11c + 10),param_1,&local_128);
        }
        else {
          nSize = 0x104;
          lpFilename = local_118;
          hModule = (HMODULE)FUN_100072f0(0x10035684);
          local_148 = GetModuleFileNameA(hModule,lpFilename,nSize);
          if ((local_148 != 0) && (local_148 != 0x104)) {
            local_16c = FUN_1000bd10();
            FUN_10001830((undefined4 *)local_138);
            local_8._0_1_ = 1;
            local_13c = local_118;
            if (local_13c == (char *)0x0) {
              local_150 = (LPWSTR)0x0;
            }
            else {
              sVar3 = strlen(local_13c);
              local_124 = sVar3 + 1;
              lVar4 = ATL::AtlMultiply<int>((int *)&local_124,local_124,2);
              if (lVar4 < 0) {
                local_14c = (LPWSTR)0x0;
              }
              else {
                if (((int)local_124 < 0x401) && (cVar1 = FUN_1000bde0(local_124), cVar1 != '\0')) {
                  local_15c = (undefined1 *)&local_170;
                  local_140 = (LPWSTR)&local_170;
                }
                else {
                  local_140 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                      CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                                (local_138,local_124);
                }
                local_14c = FUN_10004a10(local_140,local_13c,local_124 >> 1,local_16c);
              }
              local_150 = local_14c;
            }
            local_144 = local_150;
            if (local_150 == (LPWSTR)0x0) {
              local_168 = 0x8007000e;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_138);
              local_8 = 0xffffffff;
              ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
              ~CComCritSecLock<class_ATL::CComCriticalSection>(local_158);
              goto LAB_100077d1;
            }
            local_120 = Ordinal_161(local_150,&local_128);
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_138);
          }
        }
        if (-1 < local_120) {
          FUN_10001c80(&local_12c);
          local_8._0_1_ = 2;
          uVar5 = FUN_100035d0(&local_12c);
          local_120 = (**(code **)(*local_128 + 0x18))(local_128,*local_11c,uVar5);
          if (-1 < local_120) {
            FUN_10001c20(&local_134,&local_12c);
            local_8._0_1_ = 3;
            FUN_10001bd0(&local_130);
            local_8 = CONCAT31(local_8._1_3_,4);
            uVar5 = FUN_100035c0(&local_130);
            puVar6 = (undefined4 *)FUN_10003590(&local_12c);
            iVar2 = QueryInterface<>(puVar6,uVar5);
            if (-1 < iVar2) {
              FUN_10001430(&local_134,&local_130);
            }
            uVar5 = detach(&local_134);
            local_11c[3] = uVar5;
            FUN_10003f30(DAT_10035308,FUN_100065e0,local_11c);
            local_8._0_1_ = 3;
            FID_conflict__bad_alloc(&local_130);
            local_8._0_1_ = 2;
            FID_conflict__bad_alloc(&local_134);
          }
          (**(code **)(*local_128 + 8))(local_128);
          local_8 = (uint)local_8._1_3_ << 8;
          FID_conflict__bad_alloc(&local_12c);
        }
      }
      else {
        local_120 = 0;
      }
      if ((local_11c[3] != 0) && (local_11c[5] == 0)) {
        local_120 = FUN_10007f80((int *)local_11c[3]);
      }
      local_160 = local_120;
      local_8 = 0xffffffff;
      ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
      ~CComCritSecLock<class_ATL::CComCriticalSection>(local_158);
    }
  }
LAB_100077d1:
  ExceptionList = local_10;
  local_170 = 0x100077ec;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007800 at 10007800

undefined4 __thiscall FUN_10007800(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      local_c = FUN_10007330(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(undefined4 *)((int)this + 0xc));
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_10007870 at 10007870

void FUN_10007870(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_100078b0(&PTR_DAT_100350ac,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007890 at 10007890

void FUN_10007890(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_100078b0(&PTR_DAT_10035090,param_2,param_3,param_4);
  return;
}



// Function: FUN_100078b0 at 100078b0

undefined4 __thiscall FUN_100078b0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_10007800(this,param_2,param_3);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: GetTypeInfoCount at 100078e0

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



// Function: GetTypeInfoCount at 10007900

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



// Function: FUN_10007920 at 10007920

int __thiscall FUN_10007920(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    ATL::_AtlRaiseException(0xc000008c,1);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: FUN_10007960 at 10007960

undefined4 __cdecl FUN_10007960(LPCSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,(&PTR_DAT_1002abd0)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_1002abd4 + local_8 * 8);
}



// Function: FUN_100079b0 at 100079b0

bool FUN_100079b0(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10007a10 at 10007a10

void FUN_10007a10(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_10007a30 at 10007a30

void FUN_10007a30(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: Init at 10007a50

/* Library Function - Single Match
    public: long __thiscall ATL::CComCriticalSection::Init(void)
   
   Library: Visual Studio 2010 Debug */

long __thiscall ATL::CComCriticalSection::Init(CComCriticalSection *this)

{
  BOOL BVar1;
  DWORD x;
  undefined4 local_8;
  
  local_8 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)this,0);
  if (BVar1 == 0) {
    x = GetLastError();
    local_8 = _HRESULT_FROM_WIN32(x);
  }
  return local_8;
}



// Function: FUN_10007a90 at 10007a90

undefined4 FUN_10007a90(void)

{
  return 0;
}



// Function: FUN_10007aa0 at 10007aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_10007aa0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_c;
  int *local_8;
  
  if (param_3 != (undefined4 *)0x0) {
    _DAT_1003530c = *param_3;
    _DAT_10035310 = param_3[1];
    _DAT_10035314 = param_3[2];
    _DAT_10035318 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_c = *(int **)((int)this + 0x2c); *local_c != 0; local_c = local_c + 9) {
      (*(code *)local_c[8])(1);
    }
  }
  for (local_8 = DAT_100356c4; local_8 < DAT_100356c8; local_8 = local_8 + 1) {
    if (*local_8 != 0) {
      (**(code **)(*local_8 + 0x1c))(1);
    }
  }
  return 0;
}



// Function: FUN_10007b50 at 10007b50

long __fastcall FUN_10007b50(CComCriticalSection *param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init(param_1);
  if (-1 < lVar1) {
    param_1[0x18] = (CComCriticalSection)0x1;
  }
  return lVar1;
}



// Function: FUN_10007b80 at 10007b80

void FUN_10007b80(void)

{
  return;
}



// Function: FUN_10007b90 at 10007b90

undefined4 FUN_10007b90(int *param_1)

{
  undefined4 local_8;
  
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



// Function: FUN_10007c00 at 10007c00

void __fastcall FUN_10007c00(LONG *param_1)

{
  FUN_10007a10(param_1);
  return;
}



// Function: FUN_10007c20 at 10007c20

void __fastcall FUN_10007c20(LONG *param_1)

{
  FUN_10007a30(param_1);
  return;
}



// Function: FUN_10007c40 at 10007c40

void __fastcall FUN_10007c40(int param_1)

{
  FUN_10007c00((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_10007c60 at 10007c60

void FUN_10007c60(void)

{
  return;
}



// Function: FUN_10007c70 at 10007c70

void __fastcall FUN_10007c70(int param_1)

{
  FUN_10007cd0((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_10007c90 at 10007c90

void FUN_10007c90(void)

{
  return;
}



// Function: FUN_10007ca0 at 10007ca0

int FUN_10007ca0(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_10005030(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_10007cd0 at 10007cd0

void __fastcall FUN_10007cd0(LONG *param_1)

{
  FUN_10006b80(param_1);
  return;
}



// Function: FUN_10007cf0 at 10007cf0

void __fastcall FUN_10007cf0(LONG *param_1)

{
  FUN_10006ba0(param_1);
  return;
}



// Function: FUN_10007d10 at 10007d10

void __thiscall FUN_10007d10(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022ca3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  pvVar1 = (void *)FUN_100013f0(4,*this + param_1 * 4);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_10001ee0(pvVar1,param_2);
  }
  local_8 = 0xffffffff;
  pvVar1 = (void *)FUN_10001400(4,*(int *)((int)this + 4) + param_1 * 4);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_10001f00(pvVar1,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007df0 at 10007df0

bool __cdecl FUN_10007df0(LPCSTR param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = lstrcmpiA(param_1,param_2);
  return iVar1 == 0;
}



// Function: FUN_10007e10 at 10007e10

undefined1 __thiscall FUN_10007e10(void *this,undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022cd0;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*this == 0) && (param_1 == (undefined4 *)0x0)) {
    local_11 = 1;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*this == 0) || (param_1 == (undefined4 *)0x0)) {
      local_11 = 0;
    }
    else {
      local_18 = (undefined4 *)this;
      FUN_10001d20(&local_20);
      local_8 = 0;
      FUN_10001d20(&local_1c);
      local_8._0_1_ = 1;
      uVar2 = FUN_100035f0(&local_20);
      (*(code *)**(undefined4 **)*local_18)(*local_18,&DAT_10029b80,uVar2,uVar1);
      uVar2 = FUN_100035f0(&local_1c);
      (**(code **)*param_1)(param_1,&DAT_10029b80,uVar2);
      iVar3 = FUN_10003520(&local_1c);
      local_11 = FUN_100033d0(&local_20,iVar3);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__bad_alloc(&local_1c);
      local_8 = 0xffffffff;
      FID_conflict__bad_alloc(&local_20);
    }
  }
  ExceptionList = local_10;
  return local_11;
}



// Function: FUN_10007f00 at 10007f00

undefined4 FUN_10007f00(undefined1 param_1)

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



// Function: FUN_10007f60 at 10007f60

void __fastcall FUN_10007f60(undefined4 *param_1)

{
  Ordinal_7(*param_1);
  return;
}



// Function: FUN_10007f80 at 10007f80

undefined4 FUN_10007f80(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint *local_34;
  int local_30;
  undefined4 local_2c;
  uint *local_28;
  uint local_24;
  uint *local_20;
  int local_1c;
  uint *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022d0a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_30,DAT_100352f8 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar1) {
    local_18 = (uint *)0x0;
    *(uint *)(local_1c + 0x18) = (uint)*(ushort *)(local_30 + 0x2c);
    *(undefined4 *)(local_1c + 0x14) = 0;
    if (*(int *)(local_1c + 0x18) != 0) {
      local_24 = *(uint *)(local_1c + 0x18);
      uVar4 = -(uint)((int)((ulonglong)local_24 * 0xc >> 0x20) != 0) |
              (uint)((ulonglong)local_24 * 0xc);
      local_20 = (uint *)FUN_1002157e(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
      local_8 = 0;
      if (local_20 == (uint *)0x0) {
        local_34 = (uint *)0x0;
      }
      else {
        *local_20 = local_24;
        _eh_vector_constructor_iterator_
                  (local_20 + 1,0xc,local_24,FUN_10002740,FID_conflict__bad_alloc);
        local_34 = local_20 + 1;
      }
      local_8 = 0xffffffff;
      local_18 = local_34;
      if (local_34 == (uint *)0x0) {
        (**(code **)(*param_1 + 0x4c))(param_1,local_30);
        ExceptionList = local_10;
        return 0x8007000e;
      }
    }
    for (local_14 = 0; local_14 < *(int *)(local_1c + 0x18); local_14 = local_14 + 1) {
      iVar1 = (**(code **)(*param_1 + 0x14))(param_1,local_14,&local_28);
      if (-1 < iVar1) {
        FUN_10002100(&local_2c);
        local_8 = 1;
        uVar7 = 0;
        uVar6 = 0;
        uVar5 = 0;
        uVar2 = FUN_10003600(&local_2c);
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,*local_28,uVar2,uVar5,uVar6,uVar7);
        if (-1 < iVar1) {
          pwVar3 = (wchar_t *)detach(&local_2c);
          ATL::CComBSTR::Attach((CComBSTR *)(local_18 + local_14 * 3),pwVar3);
          uVar2 = FUN_10003560(local_18 + local_14 * 3);
          uVar4 = Ordinal_7(uVar2);
          local_18[local_14 * 3 + 1] = uVar4;
          local_18[local_14 * 3 + 2] = *local_28;
        }
        (**(code **)(*param_1 + 0x50))(param_1,local_28);
        local_8 = 0xffffffff;
        FUN_10002f00(&local_2c);
      }
    }
    *(uint **)(local_1c + 0x14) = local_18;
    (**(code **)(*param_1 + 0x4c))(param_1,local_30);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_100081c0 at 100081c0

int __fastcall FUN_100081c0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10008220((LPCRITICAL_SECTION)*param_1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 1) = 1;
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_10008200 at 10008200

void __fastcall FUN_10008200(int param_1)

{
  FUN_10007a10((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10008220 at 10008220

undefined4 __fastcall FUN_10008220(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  return 0;
}



// Function: FUN_10008240 at 10008240

undefined4 FUN_10008240(void)

{
  return 0;
}



// Function: FUN_10008250 at 10008250

undefined4 FUN_10008250(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10035308 + 8))();
  }
  else {
    (**(code **)(*DAT_10035308 + 4))();
  }
  return 0;
}



// Function: FUN_10008290 at 10008290

undefined4 __thiscall FUN_10008290(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_10006f10(this,param_1);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_10007920(this,iVar1);
    uVar2 = *puVar3;
  }
  return uVar2;
}



// Function: FUN_100082d0 at 100082d0

undefined4 __thiscall FUN_100082d0(void *this,undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  LPSTR pCVar3;
  int iVar4;
  int local_18;
  int local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  
  puVar1 = param_1;
  FUN_1000ab20((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  if (**this == '\0') {
    uVar2 = FUN_10007050();
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (**this == '\'') {
                    /* WARNING: Load size is inaccurate */
      pCVar3 = CharNextA(*this);
      *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
      while ((**this != '\0' && (iVar4 = FUN_10006d80((undefined4 *)this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == '\'') {
                    /* WARNING: Load size is inaccurate */
          pCVar3 = CharNextA(*this);
          *(LPSTR *)this = pCVar3;
        }
                    /* WARNING: Load size is inaccurate */
        local_c = *this;
                    /* WARNING: Load size is inaccurate */
        pCVar3 = CharNextA(*this);
        *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_c;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_10007050();
          return uVar2;
        }
        for (local_14 = 0; local_14 < iVar4; local_14 = local_14 + 1) {
          *param_1 = *local_c;
          param_1 = param_1 + 1;
          local_c = local_c + 1;
        }
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == '\0') {
        uVar2 = FUN_10007050();
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
      while ((**this != '\0' && (iVar4 = FUN_10007f00(**this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        local_10 = *this;
                    /* WARNING: Load size is inaccurate */
        pCVar3 = CharNextA(*this);
        *(LPSTR *)this = pCVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_10;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_10007050();
          return uVar2;
        }
        for (local_18 = 0; local_18 < iVar4; local_18 = local_18 + 1) {
          *param_1 = *local_10;
          param_1 = param_1 + 1;
          local_10 = local_10 + 1;
        }
      }
      *param_1 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_100084f0 at 100084f0

long __thiscall FUN_100084f0(void *this,HKEY param_1,LPCSTR param_2,REGSAM param_3)

{
  int local_14;
  long local_10;
  HKEY local_c;
  CRegKey *local_8;
  
  local_c = (HKEY)0x0;
  local_8 = (CRegKey *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_14 = RegOpenKeyExA(param_1,param_2,0,param_3,&local_c);
  }
  else {
    local_14 = FUN_10008de0(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_c);
  }
  local_10 = local_14;
  if (local_14 == 0) {
    local_10 = ATL::CRegKey::Close(local_8);
    *(HKEY *)local_8 = local_c;
  }
  return local_10;
}



// Function: FUN_10008580 at 10008580

void __fastcall FUN_10008580(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 4))(*param_1);
  return;
}



// Function: FUN_100085a0 at 100085a0

void __thiscall FUN_100085a0(void *this,undefined4 param_1,undefined4 param_2)

{
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  (**(code **)**this)(*this,param_1,param_2);
  return;
}



// Function: FUN_100085d0 at 100085d0

void __fastcall FUN_100085d0(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 8))(*param_1);
  return;
}



// Function: FUN_100085f0 at 100085f0

void __thiscall FUN_100085f0(void *this,char *param_1,undefined4 *param_2)

{
  size_t sVar1;
  LPSTR pCVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined4 local_5c [2];
  int local_54;
  char *local_50;
  LPCSTR local_4c;
  int local_48;
  char local_41;
  int local_40;
  char local_3a;
  char local_39;
  int *local_38;
  undefined1 local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022d38;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = (int *)this;
  if ((param_1 != (char *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    sVar1 = strlen(param_1);
    FUN_100022e0(local_5c,sVar1 << 1);
    local_8 = 0;
    if (local_54 == 0) {
      local_8 = 0xffffffff;
      FUN_100030d0((int)local_5c);
    }
    else {
      *local_38 = (int)param_1;
      local_40 = 0;
      local_41 = '\0';
      local_40 = FUN_10004fc0(&local_41);
      if (local_40 < 0) {
        local_8 = 0xffffffff;
        FUN_100030d0((int)local_5c);
      }
      else {
        local_48 = 0;
        local_3a = '\0';
        local_39 = '\0';
        while (*(char *)*local_38 != '\0') {
          if (local_41 == '\x01') {
            if (local_48 == 0) {
              local_50 = (char *)0x0;
              local_50 = _tcschr((char *)*local_38,0x1002ac40);
              if ((local_50 != (char *)0x0) && (local_50 == (char *)*local_38)) {
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
                iVar3 = FUN_10003dc0(local_5c,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
                if (iVar3 == 0) {
                  local_40 = -0x7ff8fff2;
                  break;
                }
                local_3a = '\x01';
              }
            }
            if (*(char *)*local_38 == '\'') {
              if (local_39 == '\0') {
                local_39 = '\x01';
              }
              else {
                iVar3 = FUN_10006d80(local_38);
                if (iVar3 == 0) {
                  pCVar2 = CharNextA((LPCSTR)*local_38);
                  *local_38 = (int)pCVar2;
                  iVar3 = FUN_10003af0(local_5c,(LPCSTR)*local_38);
                  if (iVar3 == 0) {
                    local_40 = -0x7ff8fff2;
                    break;
                  }
                }
                else {
                  local_39 = '\0';
                }
              }
            }
            if ((local_39 == '\0') && (*(char *)*local_38 == '{')) {
              local_48 = local_48 + 1;
            }
            if ((((local_39 == '\0') && (*(char *)*local_38 == '}')) &&
                (local_48 = local_48 + -1, local_48 == 0)) && (local_3a == '\x01')) {
              iVar3 = FUN_10003dc0(local_5c,L"\r\n\t}\r\n}\r\n");
              if (iVar3 == 0) {
                local_40 = -0x7ff8fff2;
                break;
              }
              local_3a = '\0';
            }
          }
          if (*(char *)*local_38 == '%') {
            pCVar2 = CharNextA((LPCSTR)*local_38);
            *local_38 = (int)pCVar2;
            if (*(char *)*local_38 == '%') {
              iVar3 = FUN_10003af0(local_5c,(LPCSTR)*local_38);
              if (iVar3 == 0) {
                local_40 = -0x7ff8fff2;
                break;
              }
            }
            else {
              local_4c = FUN_1000ab60((LPSTR)*local_38,'%');
              if (local_4c == (LPCSTR)0x0) {
                local_40 = FUN_10007050();
                break;
              }
              if (0x1f < (int)local_4c - *local_38) {
                local_40 = -0x7fffbffb;
                break;
              }
              ATL::Checked::memmove_s(local_34,0x20,(void *)*local_38,(int)local_4c - *local_38);
              pwVar4 = (wchar_t *)FUN_1000abb0(local_38[1]);
              if (pwVar4 == (wchar_t *)0x0) {
                local_40 = FUN_10007050();
                break;
              }
              iVar3 = FUN_10003dc0(local_5c,pwVar4);
              if (iVar3 == 0) {
                local_40 = -0x7ff8fff2;
                break;
              }
              while ((LPCSTR)*local_38 != local_4c) {
                pCVar2 = CharNextA((LPCSTR)*local_38);
                *local_38 = (int)pCVar2;
              }
            }
          }
          else {
            iVar3 = FUN_10003af0(local_5c,(LPCSTR)*local_38);
            if (iVar3 == 0) {
              local_40 = -0x7ff8fff2;
              break;
            }
          }
          pCVar2 = CharNextA((LPCSTR)*local_38);
          *local_38 = (int)pCVar2;
        }
        if (-1 < local_40) {
          uVar5 = FUN_10006d00(local_5c);
          *param_2 = uVar5;
        }
        local_8 = 0xffffffff;
        FUN_100030d0((int)local_5c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008a00 at 10008a00

long FUN_10008a00(int *param_1,_GUID *param_2,void **param_3)

{
  int iVar1;
  long local_8;
  
  if (param_3 == (void **)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    *param_3 = (void *)0x0;
    local_8 = 0;
    iVar1 = FUN_10007b90((int *)param_2);
    if (iVar1 == 0) {
      local_8 = ATL::CAccessibleProxy::_InternalQueryInterface
                          ((CAccessibleProxy *)(param_1 + 3),param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return local_8;
}



// Function: FUN_10008a70 at 10008a70

void FUN_10008a70(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100085a0((void *)(param_1 + 0xc),param_2,param_3);
  return;
}



// Function: QueryInterface at 10008aa0

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::CAccessibleProxy::_InternalQueryInterface
                    ((CAccessibleProxy *)param_1,(_GUID *)param_2,in_stack_0000000c);
  return lVar1;
}



// Function: QueryInterface at 10008ad0

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::CAccessibleProxy::_InternalQueryInterface
                    ((CAccessibleProxy *)param_1,(_GUID *)param_2,in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10008af0 at 10008af0

undefined4 FUN_10008af0(void)

{
  return 0x80004001;
}



// Function: FUN_10008b00 at 10008b00

void FUN_10008b00(LPCSTR param_1)

{
  LSTATUS LVar1;
  _FILETIME local_140;
  undefined4 local_138;
  long local_134;
  int local_130;
  HKEY local_12c [3];
  DWORD local_120;
  undefined4 *local_11c;
  long local_118;
  CHAR local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022d6b;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ATL::CRegKey::CRegKey((CRegKey *)local_12c,(CAtlTransactionManager *)0x0);
  local_8 = 0;
  local_118 = FUN_100084f0(local_12c,(HKEY)*local_11c,param_1,local_11c[1] | 0x2001f);
  if (local_118 == 0) {
    do {
      local_120 = 0x100;
      LVar1 = RegEnumKeyExA(local_12c[0],0,local_114,&local_120,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0
                            ,&local_140);
      if (LVar1 != 0) {
        ATL::CRegKey::Close((CRegKey *)local_12c);
        local_138 = FUN_10006bc0(local_11c,param_1);
        local_8 = 0xffffffff;
        FUN_100030f0((CRegKey *)local_12c);
        goto LAB_10008c6b;
      }
      local_118 = FUN_10008b00(local_114);
    } while (local_118 == 0);
    local_8 = 0xffffffff;
    local_130 = local_118;
    FUN_100030f0((CRegKey *)local_12c);
  }
  else {
    local_8 = 0xffffffff;
    local_134 = local_118;
    FUN_100030f0((CRegKey *)local_12c);
  }
LAB_10008c6b:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008c90 at 10008c90

LSTATUS __thiscall
FUN_10008c90(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,LPSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
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
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                        *this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_10008d50 at 10008d50

LSTATUS __thiscall FUN_10008d50(void *this,HKEY param_1,LPCSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegDeleteKeyA(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_10008de0 at 10008de0

LSTATUS __thiscall
FUN_10008de0(void *this,HKEY param_1,LPCSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegOpenKeyExA(param_1,param_2,param_3,param_4,param_5);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedA");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_10008e80 at 10008e80

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10008e80(void *this,char *param_1,int param_2)

{
  undefined4 uVar1;
  LPVOID local_1018;
  HKEY local_1014;
  undefined4 *local_1010;
  int local_100c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_100c = 0;
  local_1018 = (LPVOID)0x0;
  local_1010 = (undefined4 *)this;
  local_100c = FUN_100085f0(this,param_1,&local_1018);
  if (-1 < local_100c) {
    *local_1010 = local_1018;
    while( true ) {
      if ((*(char *)*local_1010 == '\0') ||
         (local_100c = FUN_100082d0(local_1010,local_1008), local_100c < 0)) goto LAB_10009068;
      local_1014 = (HKEY)FUN_10007960(local_1008);
      if (local_1014 == (HKEY)0x0) break;
      local_100c = FUN_100082d0(local_1010,local_1008);
      if (local_100c < 0) goto LAB_10009068;
      if (local_1008[0] != '{') {
        local_100c = FUN_10007050();
        goto LAB_10009068;
      }
      if (param_2 == 0) {
        local_100c = FUN_10009580(local_1008,local_1014,0,0);
        if (local_100c < 0) goto LAB_10009068;
      }
      else {
        uVar1 = *local_1010;
        local_100c = FUN_10009580(local_1008,local_1014,param_2,0);
        if (local_100c < 0) {
          *local_1010 = uVar1;
          FUN_10009580(local_1008,local_1014,0,0);
          goto LAB_10009068;
        }
      }
      FUN_1000ab20(local_1010);
    }
    local_100c = FUN_10007050();
LAB_10009068:
    CoTaskMemFree(local_1018);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009090 at 10009090

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10009090(wchar_t *param_1,LPCSTR param_2,LPCSTR param_3)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint uStack_47c;
  undefined1 local_46c [8];
  undefined4 local_464;
  undefined1 *local_460;
  undefined4 local_45c;
  undefined4 uStack_458;
  HGLOBAL local_454;
  UINT local_450;
  LPCSTR local_44c;
  LPSTR local_448;
  HGLOBAL local_444;
  LPSTR local_440;
  LPCSTR local_43c;
  HRSRC local_438;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_434 [4];
  wchar_t *local_430;
  undefined4 local_42c;
  DWORD local_428;
  ulong local_424;
  HMODULE local_420;
  int local_41c [257];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022db6;
  local_10 = ExceptionList;
  uStack_47c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_47c;
  ExceptionList = &local_10;
  local_18 = uStack_47c;
  local_450 = FUN_1000bd10();
  FUN_10001830((undefined4 *)local_434);
  local_8 = 0;
  FUN_10002410(local_46c,local_464);
  FUN_10001ea0(local_41c);
  local_8._0_1_ = 1;
  local_430 = param_1;
  if (param_1 == (wchar_t *)0x0) {
    local_44c = (LPCSTR)0x0;
    goto LAB_100091fa;
  }
  sVar2 = wcslen(param_1);
  local_424 = sVar2 + 1;
  lVar3 = ATL::AtlMultiply<int>((int *)&local_424,local_424,2);
  if (lVar3 < 0) {
    local_440 = (LPSTR)0x0;
  }
  else {
    if ((int)local_424 < 0x401) {
      cVar1 = FUN_1000bde0(local_424);
      if (cVar1 == '\0') goto LAB_100091af;
      local_460 = (undefined1 *)&uStack_47c;
      local_448 = (LPSTR)&uStack_47c;
      local_14 = (undefined1 *)&uStack_47c;
    }
    else {
LAB_100091af:
      local_448 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                   (local_434,local_424);
    }
    local_440 = FUN_10006400(local_448,local_430,local_424,local_450);
  }
  local_44c = local_440;
LAB_100091fa:
  local_43c = local_44c;
  if (local_44c == (LPCSTR)0x0) {
    local_45c = 0x8007000e;
    local_8 = (uint)local_8._1_3_ << 8;
    ~CTempBuffer<>(local_41c);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_434);
  }
  else {
    local_420 = LoadLibraryExA(local_44c,(HANDLE)0x0,0x60);
    if (local_420 == (HMODULE)0x0) {
      local_420 = LoadLibraryExA(local_43c,(HANDLE)0x0,2);
    }
    if (local_420 == (HMODULE)0x0) {
      local_42c = FUN_10004ff0();
    }
    else {
      local_438 = FindResourceA(local_420,param_2,param_3);
      if (local_438 == (HRSRC)0x0) {
        local_42c = FUN_10004ff0();
      }
      else {
        local_444 = LoadResource(local_420,local_438);
        if (local_444 == (HGLOBAL)0x0) {
          local_42c = FUN_10004ff0();
        }
        else {
          local_428 = SizeofResource(local_420,local_438);
          local_454 = local_444;
          if (local_428 <= local_428 + 1) {
            local_8 = CONCAT31(local_8._1_3_,2);
            Allocate(local_41c,local_428 + 1);
            FUN_10009363();
            return;
          }
          local_42c = 0x8007000e;
        }
      }
    }
    if (local_420 != (HMODULE)0x0) {
      FreeLibrary(local_420);
    }
    uStack_458 = local_42c;
    local_8 = (uint)local_8._1_3_ << 8;
    ~CTempBuffer<>(local_41c);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_434);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000935d at 1000935d

undefined * Catch_1000935d(void)

{
  return &DAT_1000936c;
}



// Function: FUN_10009363 at 10009363

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10009363(void)

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
  iVar2 = FUN_10003540((undefined4 *)(unaff_EBP - 0x418));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP - 0x428) = 0x8007000e;
  }
  else {
    rVar8 = *(rsize_t *)(unaff_EBP - 0x424);
    pvVar7 = *(void **)(unaff_EBP - 0x450);
    rVar6 = *(rsize_t *)(unaff_EBP - 0x424);
    pvVar3 = (void *)FUN_10003540((undefined4 *)(unaff_EBP - 0x418));
    FUN_1000c930(pvVar3,rVar6,pvVar7,rVar8);
    iVar2 = FUN_10003540((undefined4 *)(unaff_EBP - 0x418));
    *(undefined1 *)(iVar2 + *(int *)(unaff_EBP - 0x424)) = 0;
    iVar2 = *(int *)(unaff_EBP + 0x14);
    pcVar4 = (char *)FUN_10003540((undefined4 *)(unaff_EBP - 0x418));
    uVar5 = FUN_10008e80((void *)(unaff_EBP - 0x468),pcVar4,iVar2);
    *(undefined4 *)(unaff_EBP - 0x428) = uVar5;
  }
  if (*(int *)(unaff_EBP - 0x41c) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP - 0x41c));
  }
  *(undefined4 *)(unaff_EBP - 0x454) = *(undefined4 *)(unaff_EBP - 0x428);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  ~CTempBuffer<>((int *)(unaff_EBP - 0x418));
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP - 0x430));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar1 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x46c) = 0x10009454;
  __security_check_cookie(uVar1 ^ unaff_EBP);
  return;
}



// Function: FUN_10009460 at 10009460

int FUN_10009460(int param_1,void *param_2)

{
  int local_8;
  
  local_8 = FUN_100094b0(&DAT_100356bc,param_1,param_2);
  if ((-1 < local_8) && (DAT_10035324 != (code *)0x0)) {
    local_8 = (*DAT_10035324)(DAT_10035688);
  }
  return local_8;
}



// Function: FUN_100094b0 at 100094b0

void __thiscall FUN_100094b0(void *this,int param_1,void *param_2)

{
  FUN_10004d10((int)this,param_1,param_2);
  return;
}



// Function: FUN_100094d0 at 100094d0

int __thiscall FUN_100094d0(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = *(int **)((int)this + 0x2c);
  if (local_8 != (int *)0x0) {
    for (; *local_8 != 0; local_8 = local_8 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_1000cde0(param_2,(void *)*local_8), CONCAT31(extraout_var,bVar1) != 0)) {
        local_c = (*(code *)local_8[1])(1);
        if (local_c < 0) break;
        iVar3 = 1;
        piVar2 = (int *)(*(code *)local_8[7])();
        local_c = FUN_10005900((GUID *)*local_8,piVar2,iVar3);
        if (local_c < 0) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_10009460(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_10009580 at 10009580

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10009580(LPCSTR param_1,HKEY param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  LPCSTR pCVar3;
  HKEY pHVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t sVar5;
  CRegKey local_1184 [12];
  int local_1178;
  CRegKey local_1174 [12];
  int local_1168;
  CRegKey local_1164 [12];
  int local_1158;
  undefined4 local_1154;
  undefined4 local_1150;
  undefined4 local_114c;
  uint local_1148;
  CRegKey local_1144 [12];
  uint local_1138;
  int local_1134;
  HKEY local_1130 [3];
  void *local_1124;
  ulong local_1120;
  int local_111c;
  CHAR local_1118 [4096];
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022e17;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ATL::CRegKey::CRegKey((CRegKey *)local_1130,(CAtlTransactionManager *)0x0);
  local_8 = 0;
  local_1134 = 1;
  local_1158 = param_4;
  local_111c = 0;
  local_111c = FUN_100082d0(local_1124,param_1);
  if (-1 < local_111c) {
LAB_1000962d:
    if (*param_1 == '}') goto LAB_10009f24;
    local_1134 = 1;
    iVar2 = lstrcmpiA(param_1,"Delete");
    local_1138 = (uint)(iVar2 == 0);
    local_1148 = local_1138;
    iVar2 = lstrcmpiA(param_1,"ForceRemove");
    if ((iVar2 == 0) || (local_1148 != 0)) {
      local_111c = FUN_100082d0(local_1124,param_1);
      if (local_111c < 0) goto LAB_10009f24;
      if (param_3 == 0) goto LAB_100097fd;
      ATL::CRegKey::CRegKey(local_1144,(CAtlTransactionManager *)0x0);
      local_8._0_1_ = 1;
      pCVar3 = FUN_1000ab60(param_1,'\\');
      if (pCVar3 == (LPCSTR)0x0) {
        iVar2 = FUN_100064f0(param_1);
        if (iVar2 != 0) {
          FUN_100064c0(local_1144,param_2);
          FUN_10008b00(param_1);
          FUN_10006d40((undefined4 *)local_1144);
        }
        if (local_1148 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100030f0(local_1144);
          goto LAB_100097fd;
        }
        local_111c = FUN_100082d0(local_1124,param_1);
        if (local_111c < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100030f0(local_1144);
        }
        else {
          local_111c = FUN_1000aa60(local_1124,param_1);
          if (-1 < local_111c) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100030f0(local_1144);
            goto LAB_10009eb0;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100030f0(local_1144);
        }
        goto LAB_10009f24;
      }
      local_1150 = FUN_10007050();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100030f0(local_1144);
      local_8 = 0xffffffff;
      FUN_100030f0((CRegKey *)local_1130);
      goto LAB_10009f48;
    }
LAB_100097fd:
    iVar2 = lstrcmpiA(param_1,"NoRemove");
    if (iVar2 == 0) {
      local_1134 = 0;
      local_111c = FUN_100082d0(local_1124,param_1);
      if (local_111c < 0) goto LAB_10009f24;
    }
    iVar2 = lstrcmpiA(param_1,"Val");
    if (iVar2 == 0) {
      local_111c = FUN_100082d0(local_1124,local_1118);
      if ((local_111c < 0) || (local_111c = FUN_100082d0(local_1124,param_1), local_111c < 0))
      goto LAB_10009f24;
      if (*param_1 != '=') {
        local_1154 = FUN_10007050();
        local_8 = 0xffffffff;
        FUN_100030f0((CRegKey *)local_1130);
        goto LAB_10009f48;
      }
      if (param_3 != 0) {
        ATL::CRegKey::CRegKey(local_1164,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 2;
        FUN_100064c0(local_1164,param_2);
        local_111c = FUN_10003f70(local_1124,local_1164,local_1118,param_1);
        FUN_10006d40((undefined4 *)local_1164);
        if (-1 < local_111c) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100030f0(local_1164);
          goto LAB_10009eb0;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100030f0(local_1164);
        local_8 = 0xffffffff;
        FUN_100030f0((CRegKey *)local_1130);
        goto LAB_10009f48;
      }
      if ((param_4 == 0) && (local_1134 != 0)) {
        ATL::CRegKey::CRegKey(local_1174,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 3;
        local_1120 = FUN_100084f0(local_1174,param_2,(LPCSTR)0x0,0x20006);
        if (local_1120 != 0) {
          local_111c = FUN_10005010(local_1120);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100030f0(local_1174);
          goto LAB_10009f24;
        }
        local_1120 = FUN_10006c10(local_1174,local_1118);
        if ((local_1120 != 0) && (local_1120 != 2)) {
          local_111c = FUN_10005010(local_1120);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100030f0(local_1174);
          goto LAB_10009f24;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100030f0(local_1174);
      }
      local_111c = FUN_1000aa60(local_1124,param_1);
joined_r0x10009a87:
      if (local_111c < 0) goto LAB_10009f24;
      goto LAB_1000962d;
    }
    pCVar3 = FUN_1000ab60(param_1,'\\');
    if (pCVar3 != (LPCSTR)0x0) {
      FUN_10007050();
      local_8 = 0xffffffff;
      FUN_100030f0((CRegKey *)local_1130);
      goto LAB_10009f48;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        local_1120 = FUN_100084f0(local_1130,param_2,param_1,0x20019);
      }
      else {
        local_1120 = 2;
      }
      if (local_1120 != 0) {
        param_4 = 1;
      }
      ATL::Checked::memmove_s(local_118,0x104,param_1,0xffffffff);
      local_111c = FUN_100082d0(local_1124,param_1);
      if (((local_111c < 0) || (local_111c = FUN_1000aa60(local_1124,param_1), local_111c < 0)) ||
         (((*param_1 == '{' && (sVar5 = strlen(param_1), sVar5 == 1)) &&
          (((local_111c = FUN_10009580(param_1,local_1130[0],0,param_4), local_111c < 0 &&
            (param_4 == 0)) || (local_111c = FUN_100082d0(local_1124,param_1), local_111c < 0))))))
      goto LAB_10009f24;
      param_4 = local_1158;
      if (local_1120 == 2) goto LAB_1000962d;
      if (local_1120 != 0) {
        if (local_1158 == 0) goto LAB_10009d38;
        goto LAB_1000962d;
      }
      if (local_1158 != 0) {
        pHVar4 = (HKEY)FUN_10003570(local_1130);
        bVar1 = FUN_100079b0(pHVar4);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          iVar2 = FUN_100064f0(local_118);
          if ((iVar2 != 0) && (local_1134 != 0)) {
            FUN_10008b00(local_118);
          }
          goto LAB_1000962d;
        }
      }
      pHVar4 = (HKEY)FUN_10003570(local_1130);
      bVar1 = FUN_100079b0(pHVar4);
      local_1168 = CONCAT31(extraout_var_00,bVar1);
      local_1120 = ATL::CRegKey::Close((CRegKey *)local_1130);
      if (local_1120 != 0) {
        FUN_10005010(local_1120);
        local_8 = 0xffffffff;
        FUN_100030f0((CRegKey *)local_1130);
        goto LAB_10009f48;
      }
      if ((local_1134 != 0) && (local_1168 == 0)) {
        ATL::CRegKey::CRegKey(local_1184,(CAtlTransactionManager *)0x0);
        local_8._0_1_ = 4;
        FUN_100064c0(local_1184,param_2);
        local_1120 = FUN_10006bc0(local_1184,local_118);
        FUN_10006d40((undefined4 *)local_1184);
        if (local_1120 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100030f0(local_1184);
          goto LAB_10009eb0;
        }
        local_111c = FUN_10005010(local_1120);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100030f0(local_1184);
        goto LAB_10009f24;
      }
    }
    else {
      local_1120 = FUN_100084f0(local_1130,param_2,param_1,0x2001f);
      if (((local_1120 != 0) &&
          (local_1120 = FUN_100084f0(local_1130,param_2,param_1,0x20019), local_1120 != 0)) &&
         (local_1120 = FUN_10006770(local_1130,param_2,param_1,(LPSTR)0x0,0,0x2001f,
                                    (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0), local_1120 != 0)) {
        local_114c = FUN_10005010(local_1120);
        local_8 = 0xffffffff;
        FUN_100030f0((CRegKey *)local_1130);
        goto LAB_10009f48;
      }
      local_111c = FUN_100082d0(local_1124,param_1);
      if ((local_111c < 0) ||
         ((*param_1 == '=' &&
          (local_111c = FUN_10003f70(local_1124,local_1130,(LPCSTR)0x0,param_1), local_111c < 0))))
      goto LAB_10009f24;
    }
LAB_10009eb0:
    if (((param_3 != 0) && (*param_1 == '{')) && (sVar5 = strlen(param_1), sVar5 == 1)) {
      local_111c = FUN_10009580(param_1,local_1130[0],param_3,0);
      if (-1 < local_111c) {
        local_111c = FUN_100082d0(local_1124,param_1);
        goto joined_r0x10009a87;
      }
      goto LAB_10009f24;
    }
    goto LAB_1000962d;
  }
  local_8 = 0xffffffff;
  local_1178 = local_111c;
  FUN_100030f0((CRegKey *)local_1130);
LAB_10009f48:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_10009d38:
  local_111c = FUN_10005010(local_1120);
LAB_10009f24:
  local_8 = 0xffffffff;
  FUN_100030f0((CRegKey *)local_1130);
  goto LAB_10009f48;
}



// Function: Release at 10009f70

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  ulong uVar1;
  int *in_stack_00000004;
  
  uVar1 = FUN_10007cf0(in_stack_00000004 + 1);
  if ((uVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0xc))(1);
  }
  return uVar1;
}



// Function: FUN_10009fc0 at 10009fc0

void FUN_10009fc0(int param_1)

{
  FUN_100085d0((undefined4 *)(param_1 + 0xc));
  return;
}



// Function: Release at 10009ff0

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  ulong uVar1;
  int *in_stack_00000004;
  
  uVar1 = FUN_10007cd0(in_stack_00000004 + 3);
  if ((uVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x30))(1);
  }
  return uVar1;
}



// Function: FUN_1000a060 at 1000a060

int FUN_1000a060(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10007cd0(param_1 + 1);
  if (iVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (iVar1 == 1) {
    (**(code **)(*DAT_10035308 + 8))();
  }
  return iVar1;
}



// Function: FUN_1000a0d0 at 1000a0d0

undefined4 FUN_1000a0d0(void)

{
  return 0;
}



// Function: FUN_1000a0e0 at 1000a0e0

LONG __fastcall FUN_1000a0e0(void *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)((int)param_1 + 8));
  if ((LVar1 == 0) && (param_1 != (void *)0x0)) {
    FUN_100037a0(param_1,1);
  }
  return LVar1;
}



// Function: FUN_1000a130 at 1000a130

void __fastcall FUN_1000a130(int *param_1)

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



// Function: FUN_1000a1b0 at 1000a1b0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000a1b0(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_44;
  undefined4 local_40;
  UINT local_3c;
  undefined4 local_38;
  undefined1 *local_34;
  LPCSTR local_30;
  LPSTR local_2c;
  LPSTR local_28;
  LPCSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022e48;
  local_10 = ExceptionList;
  local_44 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_44;
  local_3c = FUN_1000bd10();
  FUN_10001830((undefined4 *)local_20);
  local_8 = 0;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_24 = (LPCSTR)0x0;
    goto LAB_1000a295;
  }
  sVar2 = wcslen(param_4);
  local_18 = sVar2 + 1;
  lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
  if (lVar3 < 0) {
    local_2c = (LPSTR)0x0;
  }
  else {
    if ((int)local_18 < 0x401) {
      cVar1 = FUN_1000bde0(local_18);
      if (cVar1 == '\0') goto LAB_1000a268;
      local_34 = (undefined1 *)&local_44;
      local_28 = (LPSTR)&local_44;
    }
    else {
LAB_1000a268:
      local_28 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                        CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                  (local_20,local_18);
    }
    local_2c = FUN_10006400(local_28,local_1c,local_18,local_3c);
  }
  local_24 = local_2c;
LAB_1000a295:
  local_30 = local_24;
  if (local_24 == (LPCSTR)0x0) {
    local_38 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_40 = FUN_10009090(param_2,(LPCSTR)(uint)param_3,local_24);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  ExceptionList = local_10;
  local_44 = 0x1000a300;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a310 at 1000a310

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000a310(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_5c;
  undefined4 local_58;
  undefined1 *local_54;
  undefined4 local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  LPSTR local_44;
  LPSTR local_40;
  LPSTR local_3c;
  LPCSTR local_38;
  UINT local_34;
  LPSTR local_30;
  LPSTR local_2c;
  LPCSTR local_28;
  LPSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022e78;
  local_10 = ExceptionList;
  local_5c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_5c;
  local_34 = FUN_1000bd10();
  FUN_10001830((undefined4 *)local_20);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_48 = 0x80070057;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    goto LAB_1000a523;
  }
  local_1c = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_3c = (LPSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_3);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_2c = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000bde0(local_18);
        if (cVar1 == '\0') goto LAB_1000a3f2;
        local_54 = (undefined1 *)&local_5c;
        local_40 = (LPSTR)&local_5c;
      }
      else {
LAB_1000a3f2:
        local_40 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_2c = FUN_10006400(local_40,local_1c,local_18,local_34);
    }
    local_3c = local_2c;
  }
  local_30 = local_3c;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_38 = (LPCSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_4);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_24 = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000bde0(local_18);
        if (cVar1 == '\0') goto LAB_1000a49e;
        local_4c = (undefined1 *)&local_5c;
        local_44 = (LPSTR)&local_5c;
      }
      else {
LAB_1000a49e:
        local_44 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_24 = FUN_10006400(local_44,local_1c,local_18,local_34);
    }
    local_38 = local_24;
  }
  local_28 = local_38;
  if ((local_30 == (LPCSTR)0x0) || (local_38 == (LPCSTR)0x0)) {
    local_50 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_58 = FUN_10009090(param_2,local_30,local_38);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
LAB_1000a523:
  ExceptionList = local_10;
  local_5c = 0x1000a53b;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a550 at 1000a550

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000a550(undefined4 param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_44;
  undefined4 local_40;
  UINT local_3c;
  undefined4 local_38;
  undefined1 *local_34;
  LPCSTR local_30;
  LPSTR local_2c;
  LPSTR local_28;
  LPCSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022ea8;
  local_10 = ExceptionList;
  local_44 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_44;
  local_3c = FUN_1000bd10();
  FUN_10001830((undefined4 *)local_20);
  local_8 = 0;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_24 = (LPCSTR)0x0;
    goto LAB_1000a635;
  }
  sVar2 = wcslen(param_4);
  local_18 = sVar2 + 1;
  lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
  if (lVar3 < 0) {
    local_2c = (LPSTR)0x0;
  }
  else {
    if ((int)local_18 < 0x401) {
      cVar1 = FUN_1000bde0(local_18);
      if (cVar1 == '\0') goto LAB_1000a608;
      local_34 = (undefined1 *)&local_44;
      local_28 = (LPSTR)&local_44;
    }
    else {
LAB_1000a608:
      local_28 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                        CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                  (local_20,local_18);
    }
    local_2c = FUN_10006400(local_28,local_1c,local_18,local_3c);
  }
  local_24 = local_2c;
LAB_1000a635:
  local_30 = local_24;
  if (local_24 == (LPCSTR)0x0) {
    local_38 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_40 = FUN_10009090(param_2,(LPCSTR)(uint)param_3,local_24);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  ExceptionList = local_10;
  local_44 = 0x1000a6a0;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a6b0 at 1000a6b0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000a6b0(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  char cVar1;
  size_t sVar2;
  long lVar3;
  uint local_5c;
  undefined4 local_58;
  undefined1 *local_54;
  undefined4 local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  LPSTR local_44;
  LPSTR local_40;
  LPSTR local_3c;
  LPCSTR local_38;
  UINT local_34;
  LPSTR local_30;
  LPSTR local_2c;
  LPCSTR local_28;
  LPSTR local_24;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_20 [4];
  wchar_t *local_1c;
  ulong local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022ed8;
  local_10 = ExceptionList;
  local_5c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_5c;
  local_34 = FUN_1000bd10();
  FUN_10001830((undefined4 *)local_20);
  local_8 = 0;
  if ((param_3 == (wchar_t *)0x0) || (param_4 == (wchar_t *)0x0)) {
    local_48 = 0x80070057;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
    goto LAB_1000a8c3;
  }
  local_1c = param_3;
  if (param_3 == (wchar_t *)0x0) {
    local_3c = (LPSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_3);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_2c = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000bde0(local_18);
        if (cVar1 == '\0') goto LAB_1000a792;
        local_54 = (undefined1 *)&local_5c;
        local_40 = (LPSTR)&local_5c;
      }
      else {
LAB_1000a792:
        local_40 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_2c = FUN_10006400(local_40,local_1c,local_18,local_34);
    }
    local_3c = local_2c;
  }
  local_30 = local_3c;
  local_1c = param_4;
  if (param_4 == (wchar_t *)0x0) {
    local_38 = (LPCSTR)0x0;
  }
  else {
    sVar2 = wcslen(param_4);
    local_18 = sVar2 + 1;
    lVar3 = ATL::AtlMultiply<int>((int *)&local_18,local_18,2);
    if (lVar3 < 0) {
      local_24 = (LPSTR)0x0;
    }
    else {
      if ((int)local_18 < 0x401) {
        cVar1 = FUN_1000bde0(local_18);
        if (cVar1 == '\0') goto LAB_1000a83e;
        local_4c = (undefined1 *)&local_5c;
        local_44 = (LPSTR)&local_5c;
      }
      else {
LAB_1000a83e:
        local_44 = (LPSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                          CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                    (local_20,local_18);
      }
      local_24 = FUN_10006400(local_44,local_1c,local_18,local_34);
    }
    local_38 = local_24;
  }
  local_28 = local_38;
  if ((local_30 == (LPCSTR)0x0) || (local_38 == (LPCSTR)0x0)) {
    local_50 = 0x8007000e;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
  else {
    local_58 = FUN_10009090(param_2,local_30,local_38);
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_20);
  }
LAB_1000a8c3:
  ExceptionList = local_10;
  local_5c = 0x1000a8db;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a8f0 at 1000a8f0

void __thiscall FUN_1000a8f0(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExA(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_1000a920 at 1000a920

LSTATUS __thiscall FUN_1000a920(void *this,LPCSTR param_1,BYTE *param_2)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  DWORD local_10;
  BYTE *local_8;
  
  if (param_2 == (BYTE *)0x0) {
    LVar1 = 0xd;
  }
  else {
    local_10 = 0;
    local_8 = param_2;
    do {
      sVar2 = strlen((char *)local_8);
      iVar3 = sVar2 + 1;
      local_8 = local_8 + iVar3;
      local_10 = local_10 + iVar3;
    } while (iVar3 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExA(*this,param_1,0,7,param_2,local_10);
  }
  return LVar1;
}



// Function: FUN_1000a9c0 at 1000a9c0

LSTATUS __thiscall FUN_1000a9c0(void *this,LPCSTR param_1,BYTE *param_2,DWORD param_3)

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



// Function: FUN_1000aa30 at 1000aa30

void __thiscall FUN_1000aa30(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}



// Function: FUN_1000aa50 at 1000aa50

void FUN_1000aa50(void)

{
  return;
}



// Function: FUN_1000aa60 at 1000aa60

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000aa60(void *this,char *param_1)

{
  int iVar1;
  undefined1 local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == '=') && (iVar1 = FUN_100082d0(this,param_1), -1 < iVar1)) {
    FUN_1000ab20((undefined4 *)this);
    iVar1 = FUN_100082d0(this,local_1008);
    if (-1 < iVar1) {
      FUN_100082d0(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ab20 at 1000ab20

void __fastcall FUN_1000ab20(undefined4 *param_1)

{
  int iVar1;
  LPSTR pCVar2;
  
  while( true ) {
    iVar1 = FUN_10007f00(*(undefined1 *)*param_1);
    if (iVar1 == 0) break;
    pCVar2 = CharNextA((LPCSTR)*param_1);
    *param_1 = pCVar2;
  }
  return;
}



// Function: FUN_1000ab60 at 1000ab60

LPCSTR __cdecl FUN_1000ab60(LPSTR param_1,char param_2)

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



// Function: FUN_1000abb0 at 1000abb0

undefined4 __fastcall FUN_1000abb0(int param_1)

{
  undefined4 uVar1;
  
  FUN_10008240();
  uVar1 = FUN_10008290((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
  FUN_1000ad90();
  return uVar1;
}



// Function: FUN_1000abf0 at 1000abf0

void __fastcall FUN_1000abf0(int param_1)

{
  undefined4 local_c;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_1 == 0) {
        local_c = (_ATL_MODULE70 *)0x0;
      }
      else {
        local_c = (_ATL_MODULE70 *)(param_1 + 4);
      }
      ATL::AtlCallTermFunc(local_c);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(undefined4 *)(param_1 + 0x28));
    }
    FUN_1000ac70((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_1000ac70 at 1000ac70

undefined4 __fastcall FUN_1000ac70(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return 0;
}



// Function: FUN_1000ac90 at 1000ac90

void __fastcall FUN_1000ac90(int param_1)

{
  int *local_c;
  int *local_8;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    for (local_8 = *(int **)(param_1 + 0x2c); *local_8 != 0; local_8 = local_8 + 9) {
      if (local_8[4] != 0) {
        (**(code **)(*(int *)local_8[4] + 8))(local_8[4]);
      }
      local_8[4] = 0;
      (*(code *)local_8[8])(0);
    }
  }
  for (local_c = DAT_100356c4; local_c < DAT_100356c8; local_c = local_c + 1) {
    if (*local_c != 0) {
      (**(code **)(*local_c + 0x1c))(0);
    }
  }
  FUN_1000abf0(param_1);
  return;
}



// Function: FUN_1000ad30 at 1000ad30

void __fastcall FUN_1000ad30(undefined4 *param_1)

{
  FUN_1000ad70((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_1000ad50 at 1000ad50

void __fastcall FUN_1000ad50(int param_1)

{
  FUN_10006b80((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000ad70 at 1000ad70

undefined4 __fastcall FUN_1000ad70(LPCRITICAL_SECTION param_1)

{
  LeaveCriticalSection(param_1);
  return 0;
}



// Function: FUN_1000ad90 at 1000ad90

undefined4 FUN_1000ad90(void)

{
  return 0;
}



// Function: FUN_1000ada0 at 1000ada0

int __thiscall FUN_1000ada0(void *this,int param_1,void *param_2)

{
  int local_8;
  
  local_8 = 0;
  if (DAT_10035328 != (code *)0x0) {
    local_8 = (*DAT_10035328)(this);
  }
  if (-1 < local_8) {
    local_8 = FUN_1000adf0(&DAT_100356bc,param_1,param_2);
  }
  return local_8;
}



// Function: FUN_1000adf0 at 1000adf0

void __thiscall FUN_1000adf0(void *this,int param_1,void *param_2)

{
  FUN_10004de0((int)this,param_1,param_2);
  return;
}



// Function: FUN_1000ae10 at 1000ae10

int __thiscall FUN_1000ae10(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = *(int **)((int)this + 0x2c);
  if (local_8 != (int *)0x0) {
    for (; *local_8 != 0; local_8 = local_8 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_1000cde0(param_2,(void *)*local_8), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar3 = 0;
        piVar2 = (int *)(*(code *)local_8[7])();
        local_c = FUN_10005900((GUID *)*local_8,piVar2,iVar3);
        if ((local_c < 0) || (local_c = (*(code *)local_8[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_1000ada0(this,param_1,param_2);
  }
  return local_c;
}



// Function: FUN_1000aec0 at 1000aec0

undefined4 FUN_1000aec0(void)

{
  return 0x80004005;
}



// Function: FUN_1000aed0 at 1000aed0

undefined4 FUN_1000aed0(void)

{
  return 0x80004005;
}



// Function: FUN_1000aef0 at 1000aef0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000aef0(int *param_1,ushort param_2,int param_3,int *param_4)

{
  char cVar1;
  bool bVar2;
  UINT UVar3;
  DWORD DVar4;
  long lVar5;
  HMODULE pHVar6;
  size_t sVar7;
  LPWSTR local_990;
  LPWSTR local_988;
  LPWSTR local_980;
  int local_974;
  undefined4 local_970 [5];
  HMODULE local_95c;
  char *local_958;
  LPWSTR local_954;
  int local_950;
  ulong local_94c;
  int local_948;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_944 [4];
  wchar_t local_940 [520];
  wchar_t local_530;
  undefined2 local_52e [523];
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022f16;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100023a0(local_970);
  local_8 = 0;
  local_948 = FUN_10006eb0();
  if (local_948 < 0) {
    local_8 = 0xffffffff;
    FUN_10003110(local_970);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10003c20((int)local_970,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_948 = (**(code **)(*param_1 + 0x14))();
    if (local_948 < 0) {
      local_8 = 0xffffffff;
      FUN_10003110(local_970);
    }
    else {
      UVar3 = FUN_1000bd10();
      FUN_10001830((undefined4 *)local_944);
      local_8._0_1_ = 1;
      local_95c = (HMODULE)FUN_100072f0(0x10035684);
      DVar4 = GetModuleFileNameA(local_95c,local_118,0x104);
      if (DVar4 == 0) {
        FUN_10004ff0();
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
        local_8 = 0xffffffff;
        FUN_10003110(local_970);
      }
      else if (DVar4 == 0x104) {
        _HRESULT_FROM_WIN32(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
        local_8 = 0xffffffff;
        FUN_10003110(local_970);
      }
      else {
        local_954 = (LPWSTR)0x0;
        local_958 = local_118;
        if (local_958 == (char *)0x0) {
          local_990 = (LPWSTR)0x0;
        }
        else {
          sVar7 = strlen(local_958);
          local_94c = sVar7 + 1;
          lVar5 = ATL::AtlMultiply<int>((int *)&local_94c,local_94c,2);
          if (lVar5 < 0) {
            local_988 = (LPWSTR)0x0;
          }
          else {
            if (((int)local_94c < 0x401) && (cVar1 = FUN_1000bde0(local_94c), cVar1 != '\0')) {
              local_980 = (LPWSTR)&stack0xfffff63c;
            }
            else {
              local_980 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                            (local_944,local_94c);
            }
            local_988 = FUN_10004a10(local_980,local_958,local_94c >> 1,UVar3);
          }
          local_990 = local_988;
        }
        local_954 = local_990;
        if (local_990 == (LPWSTR)0x0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
          local_8 = 0xffffffff;
          FUN_10003110(local_970);
        }
        else {
          FUN_10006dd0(local_940,0x208,local_990);
          if ((local_95c == (HMODULE)0x0) ||
             (pHVar6 = GetModuleHandleA((LPCSTR)0x0), local_95c == pHVar6)) {
            local_530 = L'\"';
            bVar2 = FUN_1000cb80(local_52e,0x20b,local_940);
            if (!bVar2) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
              local_8 = 0xffffffff;
              FUN_10003110(local_970);
              goto LAB_1000b486;
            }
            sVar7 = FUN_1000cbd0(&local_530);
            local_52e[sVar7 - 1] = 0x22;
            if (0x417 < sVar7 * 2 + 2) {
              ___report_rangecheckfailure();
            }
            local_52e[sVar7] = 0;
            local_950 = FUN_10003c20((int)local_970,L"Module",&local_530);
          }
          else {
            local_950 = FUN_10003c20((int)local_970,L"Module",local_940);
          }
          if (local_950 < 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
            local_8 = 0xffffffff;
            FUN_10003110(local_970);
          }
          else {
            local_950 = FUN_10003c20((int)local_970,L"Module_Raw",local_940);
            if (local_950 < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
              local_8 = 0xffffffff;
              FUN_10003110(local_970);
            }
            else {
              if (param_3 == 0) {
                local_974 = FUN_1000a550(local_970,local_954,param_2,L"REGISTRY");
              }
              else {
                local_974 = FUN_1000a1b0(local_970,local_954,param_2,L"REGISTRY");
              }
              local_948 = local_974;
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_944);
              local_8 = 0xffffffff;
              FUN_10003110(local_970);
            }
          }
        }
      }
    }
  }
LAB_1000b486:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b4b0 at 1000b4b0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000b4b0(int *param_1,char *param_2,int param_3,int *param_4)

{
  bool bVar1;
  char cVar2;
  UINT UVar3;
  DWORD DVar4;
  HMODULE pHVar5;
  size_t sVar6;
  long lVar7;
  LPWSTR local_9a4;
  LPWSTR local_99c;
  LPWSTR local_998;
  LPWSTR local_994;
  LPWSTR local_988;
  int local_984;
  wchar_t *local_978;
  undefined4 local_974 [5];
  HMODULE local_960;
  wchar_t *local_95c;
  LPWSTR local_958;
  int local_954;
  char *local_950;
  int local_94c;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_948 [4];
  ulong local_944;
  wchar_t local_940 [520];
  wchar_t local_530;
  undefined2 local_52e [523];
  CHAR local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022f56;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100023a0(local_974);
  local_8 = 0;
  local_94c = FUN_10006eb0();
  if (local_94c < 0) {
    local_8 = 0xffffffff;
    FUN_10003110(local_974);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10003c20((int)local_974,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
      }
    }
    local_94c = (**(code **)(*param_1 + 0x14))();
    if (local_94c < 0) {
      local_8 = 0xffffffff;
      FUN_10003110(local_974);
    }
    else {
      UVar3 = FUN_1000bd10();
      FUN_10001830((undefined4 *)local_948);
      local_8._0_1_ = 1;
      local_960 = (HMODULE)FUN_100072f0(0x10035684);
      DVar4 = GetModuleFileNameA(local_960,local_118,0x104);
      if (DVar4 == 0) {
        FUN_10004ff0();
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
        local_8 = 0xffffffff;
        FUN_10003110(local_974);
      }
      else if (DVar4 == 0x104) {
        _HRESULT_FROM_WIN32(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
        ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
        local_8 = 0xffffffff;
        FUN_10003110(local_974);
      }
      else {
        local_958 = (LPWSTR)0x0;
        local_950 = local_118;
        if (local_950 == (char *)0x0) {
          local_9a4 = (LPWSTR)0x0;
        }
        else {
          sVar6 = strlen(local_950);
          local_944 = sVar6 + 1;
          lVar7 = ATL::AtlMultiply<int>((int *)&local_944,local_944,2);
          if (lVar7 < 0) {
            local_99c = (LPWSTR)0x0;
          }
          else {
            if (((int)local_944 < 0x401) && (cVar2 = FUN_1000bde0(local_944), cVar2 != '\0')) {
              local_994 = (LPWSTR)&stack0xfffff624;
            }
            else {
              local_994 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                            (local_948,local_944);
            }
            local_99c = FUN_10004a10(local_994,local_950,local_944 >> 1,UVar3);
          }
          local_9a4 = local_99c;
        }
        local_958 = local_9a4;
        if (local_9a4 == (LPWSTR)0x0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
          ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
          local_8 = 0xffffffff;
          FUN_10003110(local_974);
        }
        else {
          FUN_10006dd0(local_940,0x208,local_9a4);
          if ((local_960 == (HMODULE)0x0) ||
             (pHVar5 = GetModuleHandleA((LPCSTR)0x0), local_960 == pHVar5)) {
            local_530 = L'\"';
            bVar1 = FUN_1000cb80(local_52e,0x20b,local_940);
            if (!bVar1) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
              local_8 = 0xffffffff;
              FUN_10003110(local_974);
              goto LAB_1000bb89;
            }
            sVar6 = FUN_1000cbd0(&local_530);
            local_52e[sVar6 - 1] = 0x22;
            if (0x417 < sVar6 * 2 + 2) {
              ___report_rangecheckfailure();
            }
            local_52e[sVar6] = 0;
            local_954 = FUN_10003c20((int)local_974,L"Module",&local_530);
          }
          else {
            local_954 = FUN_10003c20((int)local_974,L"Module",local_940);
          }
          if (local_954 < 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
            ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
            local_8 = 0xffffffff;
            FUN_10003110(local_974);
          }
          else {
            local_954 = FUN_10003c20((int)local_974,L"Module_Raw",local_940);
            if (local_954 < 0) {
              local_8 = (uint)local_8._1_3_ << 8;
              ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
              ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
              local_8 = 0xffffffff;
              FUN_10003110(local_974);
            }
            else {
              local_950 = param_2;
              if (param_2 == (char *)0x0) {
                local_978 = (wchar_t *)0x0;
              }
              else {
                sVar6 = strlen(param_2);
                local_944 = sVar6 + 1;
                lVar7 = ATL::AtlMultiply<int>((int *)&local_944,local_944,2);
                if (lVar7 < 0) {
                  local_998 = (LPWSTR)0x0;
                }
                else {
                  if (((int)local_944 < 0x401) && (cVar2 = FUN_1000bde0(local_944), cVar2 != '\0'))
                  {
                    local_988 = (LPWSTR)&stack0xfffff624;
                  }
                  else {
                    local_988 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                                        CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                                        Allocate(local_948,local_944);
                  }
                  local_998 = FUN_10004a10(local_988,local_950,local_944 >> 1,UVar3);
                }
                local_978 = local_998;
              }
              local_95c = local_978;
              if (local_978 == (wchar_t *)0x0) {
                local_8 = (uint)local_8._1_3_ << 8;
                ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
                local_8 = 0xffffffff;
                FUN_10003110(local_974);
              }
              else {
                if (param_3 == 0) {
                  local_984 = FUN_1000a6b0(local_974,local_958,local_978,L"REGISTRY");
                }
                else {
                  local_984 = FUN_1000a310(local_974,local_958,local_978,L"REGISTRY");
                }
                local_94c = local_984;
                local_8 = (uint)local_8._1_3_ << 8;
                ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
                ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_948);
                local_8 = 0xffffffff;
                FUN_10003110(local_974);
              }
            }
          }
        }
      }
    }
  }
LAB_1000bb89:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000bbb0 at 1000bbb0

void FUN_1000bbb0(int *param_1,ushort param_2,int param_3,int *param_4)

{
  FUN_1000aef0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000bbd0 at 1000bbd0

void FUN_1000bbd0(int *param_1,char *param_2,int param_3,int *param_4)

{
  FUN_1000b4b0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000bbf0 at 1000bbf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000bbf0(LPCSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10022f8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_10035358 & 1) == 0) {
    DAT_10035358 = DAT_10035358 | 1;
    _DAT_10035338 = &DAT_10029a3c;
    _DAT_1003533c = 8;
    _DAT_10035340 = &DAT_10029a40;
    _DAT_10035344 = 0x4008;
    _DAT_10035348 = &DAT_10029a44;
    _DAT_1003534c = 0x13;
    _DAT_10035350 = &DAT_10029a48;
    _DAT_10035354 = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiA(param_1,*(LPCSTR *)(&DAT_10035338 + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_1003533c + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000bd00 at 1000bd00

undefined4 FUN_1000bd00(void)

{
  return 0;
}



// Function: FUN_1000bd10 at 1000bd10

undefined4 FUN_1000bd10(void)

{
  return 3;
}



// Function: FUN_1000bd20 at 1000bd20

int __fastcall FUN_1000bd20(int param_1)

{
  undefined4 local_8;
  
  local_8 = FUN_1000bd60(param_1 + 0x18);
  if (-1 < local_8) {
    local_8 = FUN_1000bd80();
  }
  return local_8;
}



// Function: FUN_1000bd60 at 1000bd60

void __fastcall FUN_1000bd60(int param_1)

{
  FUN_10007b50((CComCriticalSection *)(param_1 + 4));
  return;
}



// Function: FUN_1000bd80 at 1000bd80

void FUN_1000bd80(void)

{
  FUN_10007a90();
  return;
}



// Function: FUN_1000bda0 at 1000bda0

void __cdecl FUN_1000bda0(LPCRITICAL_SECTION param_1,DWORD param_2)

{
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return;
}



// Function: _AtlRaiseException at 1000bdc0

/* Library Function - Single Match
    void __cdecl ATL::_AtlRaiseException(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __cdecl ATL::_AtlRaiseException(ulong param_1,ulong param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: FUN_1000bde0 at 1000bde0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_1000bde0(int param_1)

{
  HRESULT HVar1;
  uint local_4c;
  int local_28;
  undefined1 local_21;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_100216bb;
  local_14 = ExceptionList;
  local_c = DAT_100352f8 ^ 0x10030698;
  local_4c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_4c;
  ExceptionList = &local_14;
  local_21 = 1;
  local_8 = 0;
  local_28 = 0;
  local_20 = local_4c;
  HVar1 = AtlAdd<>(&local_28,param_1,0x2000);
  if (HVar1 < 0) {
    local_21 = 0;
  }
  else {
    local_1c = (undefined1 *)((int)&local_4c - local_28);
  }
  local_8 = 0xfffffffe;
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000bed0 at 1000bed0

void __thiscall FUN_1000bed0(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uStack_34;
  uint local_20;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022fb0;
  local_10 = ExceptionList;
  uStack_34 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  local_20 = param_1 | 0xf;
  uVar1 = FID_conflict_max_size();
  if (uVar1 < local_20) {
    local_20 = param_1;
  }
  else if (local_20 / 3 < *(uint *)((int)this + 0x14) >> 1) {
    iVar2 = FID_conflict_max_size();
    if (iVar2 - (*(uint *)((int)this + 0x14) >> 1) < *(uint *)((int)this + 0x14)) {
      local_20 = FID_conflict_max_size();
    }
    else {
      local_20 = (*(uint *)((int)this + 0x14) >> 1) + *(int *)((int)this + 0x14);
    }
  }
  local_8 = 0;
  local_20 = local_20 + 1;
  Getal(&local_15);
  allocate(local_20);
  FUN_1000bff2();
  return;
}



// Function: Catch@1000bf95 at 1000bf95

void Catch_1000bf95(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = *(int *)(unaff_EBP + -0x1c) + 1;
  Getal(unaff_EBP + -0x12);
  uVar2 = allocate(uVar1);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
  FUN_1000bfdc();
  return;
}



// Function: Catch@1000bfc1 at 1000bfc1

void Catch_1000bfc1(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x18),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000bfdc at 1000bfdc

undefined * FUN_1000bfdc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000bffb;
}



// Function: FUN_1000bff2 at 1000bff2

void FUN_1000bff2(void)

{
  char *pcVar1;
  void *this;
  int unaff_EBP;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    uVar3 = *(uint *)(unaff_EBP + 0xc);
    pcVar1 = std::_String_val<struct_std::_Simple_types<char>_>::_Myptr
                       (*(_String_val<struct_std::_Simple_types<char>_> **)(unaff_EBP + -0x18));
    std::char_traits<char>::copy(*(char **)(unaff_EBP + -0x20),pcVar1,uVar3);
  }
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x18),'\x01',0);
  iVar4 = unaff_EBP + -0x20;
  uVar2 = *(undefined4 *)(unaff_EBP + -0x18);
  this = (void *)Getal(unaff_EBP + -0x13);
  construct<>(this,uVar2,iVar4);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
  std::basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
            (*(basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
               **)(unaff_EBP + -0x18),*(uint *)(unaff_EBP + 0xc));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: _Eos at 1000c080

/* Library Function - Single Match
    protected: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Eos(unsigned int)
   
   Library: Visual Studio 2003 Debug */

void __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
          (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
           *this,uint param_1)

{
  char *pcVar1;
  undefined1 *puVar2;
  undefined1 local_5;
  
  local_5 = 0;
  *(uint *)(this + 0x10) = param_1;
  puVar2 = &local_5;
  pcVar1 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                     ((_String_val<struct_std::_Simple_types<char>_> *)this);
  FUN_1000c600(pcVar1 + param_1,puVar2);
  return;
}



// Function: FUN_1000c0c0 at 1000c0c0

void __fastcall FUN_1000c0c0(int *param_1)

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



// Function: Clear at 1000c120

/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall Concurrency::cancellation_token::_Clear(void)
    private: void __thiscall Concurrency::cancellation_token_registration::_Clear(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __fastcall Clear(int *param_1)

{
  if (*param_1 != 0) {
    FUN_1000a0e0((void *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: _GetEntries at 1000c150

/* Library Function - Single Match
    public: static struct ATL::_ATL_INTMAP_ENTRY const * __stdcall
   ATL::CAccessibleProxy::_GetEntries(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_ATL_INTMAP_ENTRY * ATL::CAccessibleProxy::_GetEntries(void)

{
  return (_ATL_INTMAP_ENTRY *)&PTR_DAT_1002ae8c;
}



// Function: _GetEntries at 1000c160

/* Library Function - Single Match
    public: static struct ATL::_ATL_INTMAP_ENTRY const * __stdcall
   ATL::CAccessibleProxy::_GetEntries(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_ATL_INTMAP_ENTRY * ATL::CAccessibleProxy::_GetEntries(void)

{
  return (_ATL_INTMAP_ENTRY *)&PTR_DAT_1002ae30;
}



// Function: Getal at 1000c170

/* Library Function - Multiple Matches With Same Base Name
    public: struct std::_Wrap_alloc<class std::allocator<char> > __thiscall
   std::_String_alloc<0,struct std::_String_base_types<char,class std::allocator<char> >
   >::_Getal(void)const 
    public: struct std::_Wrap_alloc<class std::allocator<unsigned short> > __thiscall
   std::_String_alloc<0,struct std::_String_base_types<unsigned short,class std::allocator<unsigned
   short> > >::_Getal(void)const 
    public: struct std::_Wrap_alloc<class std::allocator<wchar_t> > __thiscall
   std::_String_alloc<0,struct std::_String_base_types<wchar_t,class std::allocator<wchar_t> >
   >::_Getal(void)const 
   
   Library: Visual Studio 2012 Release */

undefined4 Getal(undefined4 param_1)

{
  FUN_10001f70(param_1);
  return param_1;
}



// Function: _Grow at 1000c190

/* Library Function - Single Match
    public: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Grow(unsigned int,bool)
   
   Library: Visual Studio 2012 Release */

bool __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Grow
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          uint param_1,bool param_2)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = FID_conflict_max_size();
  if (uVar1 < param_1) {
    FUN_1000c400();
  }
  if (*(uint *)(this + 0x14) < param_1) {
    FUN_1000bed0(this,param_1);
  }
  else if ((param_2) && (param_1 < 0x10)) {
    if (param_1 < *(uint *)(this + 0x10)) {
      local_c = param_1;
    }
    else {
      local_c = *(uint *)(this + 0x10);
    }
    FID_conflict__Tidy(this,'\x01',local_c);
  }
  else if (param_1 == 0) {
    basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
              ((basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                *)this,0);
  }
  return param_1 != 0;
}



// Function: _Inside at 1000c240

/* Library Function - Single Match
    public: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Inside(char const *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

bool __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Inside
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1)

{
  char *pcVar1;
  
  if (((param_1 != (char *)0x0) &&
      (pcVar1 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                          ((_String_val<struct_std::_Simple_types<char>_> *)this), pcVar1 <= param_1
      )) && (pcVar1 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                                ((_String_val<struct_std::_Simple_types<char>_> *)this),
            param_1 < pcVar1 + *(int *)(this + 0x10))) {
    return true;
  }
  return false;
}



// Function: _InternalQueryInterface at 1000c280

/* Library Function - Single Match
    public: long __thiscall ATL::CAccessibleProxy::_InternalQueryInterface(struct _GUID const &,void
   * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long __thiscall
ATL::CAccessibleProxy::_InternalQueryInterface(CAccessibleProxy *this,_GUID *param_1,void **param_2)

{
  _ATL_INTMAP_ENTRY *p_Var1;
  int iVar2;
  
  p_Var1 = _GetEntries();
  iVar2 = FUN_10007ca0((int)this,(int *)p_Var1,(int *)param_1,param_2);
  return iVar2;
}



// Function: _InternalQueryInterface at 1000c2b0

/* Library Function - Single Match
    public: long __thiscall ATL::CAccessibleProxy::_InternalQueryInterface(struct _GUID const &,void
   * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long __thiscall
ATL::CAccessibleProxy::_InternalQueryInterface(CAccessibleProxy *this,_GUID *param_1,void **param_2)

{
  _ATL_INTMAP_ENTRY *p_Var1;
  int iVar2;
  
  p_Var1 = _GetEntries();
  iVar2 = FUN_10007ca0((int)this,(int *)p_Var1,(int *)param_1,param_2);
  return iVar2;
}



// Function: _Myptr at 1000c2e0

/* Library Function - Single Match
    public: char const * __thiscall std::_String_val<struct std::_Simple_types<char>
   >::_Myptr(void)const 
   
   Library: Visual Studio 2012 Release */

char * __thiscall
std::_String_val<struct_std::_Simple_types<char>_>::_Myptr
          (_String_val<struct_std::_Simple_types<char>_> *this)

{
  _String_val<struct_std::_Simple_types<char>_> *local_c;
  
  local_c = this;
  if (0xf < *(uint *)(this + 0x14)) {
    local_c = (_String_val<struct_std::_Simple_types<char>_> *)addressof<>(*(undefined4 *)this);
  }
  return (char *)local_c;
}



// Function: _Myptr at 1000c320

/* Library Function - Single Match
    public: char const * __thiscall std::_String_val<struct std::_Simple_types<char>
   >::_Myptr(void)const 
   
   Library: Visual Studio 2012 Release */

char * __thiscall
std::_String_val<struct_std::_Simple_types<char>_>::_Myptr
          (_String_val<struct_std::_Simple_types<char>_> *this)

{
  _String_val<struct_std::_Simple_types<char>_> *local_c;
  
  local_c = this;
  if (0xf < *(uint *)(this + 0x14)) {
    local_c = (_String_val<struct_std::_Simple_types<char>_> *)addressof<>(*(undefined4 *)this);
  }
  return (char *)local_c;
}



// Function: FID_conflict:_Tidy at 1000c360

/* Library Function - Multiple Matches With Different Base Names
    public: void __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_Tidy(bool,unsigned int)
    public: void __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_Tidy(bool,unsigned int)
   
   Library: Visual Studio 2012 Release */

void __thiscall FID_conflict__Tidy(void *this,char param_1,uint param_2)

{
  char *pcVar1;
  void *pvVar2;
  uint uVar3;
  undefined1 local_6;
  undefined1 local_5;
  
  if ((param_1 != '\0') && (0xf < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    pvVar2 = *this;
    Getal(&local_5);
    destroy<>();
    if (param_2 != 0) {
      uVar3 = param_2;
      pcVar1 = (char *)addressof<>(pvVar2);
      std::char_traits<char>::copy((char *)this,pcVar1,uVar3);
    }
    Getal(&local_6);
    deallocate(pvVar2);
  }
  *(undefined4 *)((int)this + 0x14) = 0xf;
  std::basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
            ((basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
              *)this,param_2);
  return;
}



// Function: FUN_1000c400 at 1000c400

void FUN_1000c400(void)

{
  std::_Xlength_error("string too long");
  return;
}



// Function: FUN_1000c420 at 1000c420

void FUN_1000c420(void)

{
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: _tcschr at 1000c440

/* Library Function - Single Match
    char * __cdecl _tcschr(char *,unsigned int)
   
   Library: Visual Studio 2005 Debug */

char * __cdecl _tcschr(char *param_1,uint param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)__tcschr((uchar *)param_1,(uchar *)param_2);
  return pcVar1;
}



// Function: allocate at 1000c460

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall std::_Wrap_alloc<class std::allocator<char> >::allocate(unsigned int)
    public: unsigned short * __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *
   __thiscall std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > >::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __thiscall
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::allocate(unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void allocate(uint param_1)

{
  allocate(param_1);
  return;
}



// Function: allocate at 1000c480

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall std::allocator<char>::allocate(unsigned int)
    public: unsigned short * __thiscall std::allocator<unsigned short>::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *
   __thiscall std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned
   char> > >::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __thiscall std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >::allocate(unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void allocate(uint param_1)

{
  FUN_10001640(param_1);
  return;
}



// Function: assign at 1000c4a0

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   const &,unsigned int,unsigned int)
   
   Library: Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,
          uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint local_c;
  
  uVar2 = FUN_1000cbf0((int)param_1);
  if (uVar2 < param_2) {
    FUN_1000c420();
  }
  iVar3 = FUN_1000cbf0((int)param_1);
  local_c = iVar3 - param_2;
  if (param_3 < local_c) {
    local_c = param_3;
  }
  if (this == param_1) {
    erase(this,param_2 + local_c);
    erase(this,0,param_2);
  }
  else {
    bVar1 = _Grow(this,local_c,false);
    if (bVar1) {
      uVar2 = local_c;
      pcVar4 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                         ((_String_val<struct_std::_Simple_types<char>_> *)param_1);
      pcVar4 = pcVar4 + param_2;
      pcVar5 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                         ((_String_val<struct_std::_Simple_types<char>_> *)this);
      char_traits<char>::copy(pcVar5,pcVar4,uVar2);
      basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
                ((basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                  *)this,local_c);
    }
  }
  return this;
}



// Function: assign at 1000c550

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const *)
   
   Library: Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  
  uVar1 = char_traits<char>::length(param_1);
  pbVar2 = assign(this,param_1,uVar1);
  return pbVar2;
}



// Function: assign at 1000c580

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const *,unsigned int)
   
   Library: Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1,uint param_2)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  
  bVar1 = _Inside(this,param_1);
  if (bVar1) {
    pcVar2 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                       ((_String_val<struct_std::_Simple_types<char>_> *)this);
    this = assign(this,this,(int)param_1 - (int)pcVar2,param_2);
  }
  else {
    bVar1 = _Grow(this,param_2,false);
    if (bVar1) {
      uVar3 = param_2;
      pcVar2 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                         ((_String_val<struct_std::_Simple_types<char>_> *)this);
      char_traits<char>::copy(pcVar2,param_1,uVar3);
      basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
                ((basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                  *)this,param_2);
    }
  }
  return this;
}



// Function: FUN_1000c600 at 1000c600

void __cdecl FUN_1000c600(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  return;
}



// Function: FUN_1000c610 at 1000c610

undefined4 __fastcall FUN_1000c610(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000c630 at 1000c630

undefined4 __fastcall FUN_1000c630(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: copy at 1000c650

/* Library Function - Single Match
    public: static char * __cdecl std::char_traits<char>::copy(char *,char const *,unsigned int)
   
   Library: Visual Studio 2012 Release */

char * __cdecl std::char_traits<char>::copy(char *param_1,char *param_2,uint param_3)

{
  undefined4 local_8;
  
  if (param_3 == 0) {
    local_8 = param_1;
  }
  else {
    local_8 = (char *)memcpy(param_1,param_2,param_3);
  }
  return local_8;
}



// Function: deallocate at 1000c680

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<char> >::deallocate(char
   *,unsigned int)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::deallocate(unsigned short *,unsigned int)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<wchar_t> >::deallocate(wchar_t
   *,unsigned int)
   
   Library: Visual Studio 2012 Release */

void deallocate(void *param_1)

{
  deallocate(param_1);
  return;
}



// Function: deallocate at 1000c6a0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::allocator<char>::deallocate(char *,unsigned int)
    public: void __thiscall std::allocator<unsigned char>::deallocate(unsigned char *,unsigned int)
    public: void __thiscall std::allocator<unsigned short>::deallocate(unsigned short *,unsigned
   int)
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >::deallocate(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,unsigned int)
     7 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void deallocate(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1000c6c0 at 1000c6c0

void * FUN_1000c6c0(void *param_1,int param_2)

{
  char *pcVar1;
  undefined *puVar2;
  
  pcVar1 = std::_Syserror_map(param_2);
  if (pcVar1 == (char *)0x0) {
    puVar2 = FUN_1000cc70();
    FUN_10002710(param_1,param_2,puVar2);
  }
  else {
    puVar2 = FUN_1000c870();
    FUN_10002710(param_1,param_2,puVar2);
  }
  return param_1;
}



// Function: default_error_condition at 1000c710

/* Library Function - Multiple Matches With Same Base Name
    public: virtual class std::error_condition __thiscall
   std::_System_error_category::default_error_condition(int)const 
    public: virtual class std::error_condition __thiscall
   std::error_category::default_error_condition(int)const 
   
   Library: Visual Studio */

void * __thiscall default_error_condition(void *this,void *param_1,undefined4 param_2)

{
  FUN_10002710(param_1,param_2,this);
  return param_1;
}



// Function: equivalent at 1000c730

/* Library Function - Single Match
    public: virtual bool __thiscall std::error_category::equivalent(class std::error_code const
   &,int)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

bool __thiscall
std::error_category::equivalent(error_category *this,error_code *param_1,int param_2)

{
  bool bVar1;
  error_category *peVar2;
  int iVar3;
  
  peVar2 = (error_category *)FUN_1000c610((int)param_1);
  bVar1 = operator==(this,peVar2);
  if ((bVar1) && (iVar3 = error_code::value(param_1), iVar3 == param_2)) {
    return true;
  }
  return false;
}



// Function: equivalent at 1000c780

/* Library Function - Single Match
    public: virtual bool __thiscall std::error_category::equivalent(int,class std::error_condition
   const &)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

bool __thiscall
std::error_category::equivalent(error_category *this,int param_1,error_condition *param_2)

{
  bool bVar1;
  error_condition *this_00;
  error_condition *peVar2;
  error_condition local_10 [8];
  error_category *local_8;
  
  peVar2 = local_10;
  local_8 = this;
  this_00 = (error_condition *)(**(code **)(*(int *)this + 0xc))(peVar2,param_1,param_2);
  bVar1 = error_condition::operator==(this_00,peVar2);
  return bVar1;
}



// Function: erase at 1000c7b0

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::erase(unsigned int)
   
   Library: Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::erase
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          uint param_1)

{
  if (*(uint *)(this + 0x10) < param_1) {
    FUN_1000c420();
  }
  basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
            ((basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
              *)this,param_1);
  return this;
}



// Function: erase at 1000c7e0

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::erase(unsigned int,unsigned int)
   
   Library: Visual Studio 2012 Release */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::erase
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          uint param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (*(uint *)(this + 0x10) < param_1) {
    FUN_1000c420();
  }
  if (param_2 < *(int *)(this + 0x10) - param_1) {
    if (param_2 != 0) {
      pcVar2 = _String_val<struct_std::_Simple_types<char>_>::_Myptr
                         ((_String_val<struct_std::_Simple_types<char>_> *)this);
      iVar1 = *(int *)(this + 0x10);
      FUN_1000cb10(pcVar2 + param_1,pcVar2 + param_1 + param_2,(iVar1 - param_2) - param_1);
      basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
                ((basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                  *)this,iVar1 - param_2);
    }
  }
  else {
    basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>::_Eos
              ((basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                *)this,param_1);
  }
  return this;
}



// Function: FUN_1000c870 at 1000c870

undefined * FUN_1000c870(void)

{
  return &DAT_10035404;
}



// Function: length at 1000c880

/* Library Function - Single Match
    public: static unsigned int __cdecl std::char_traits<char>::length(char const *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

uint __cdecl std::char_traits<char>::length(char *param_1)

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



// Function: max_size at 1000c8b0

/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::_Wrap_alloc<class std::allocator<char>
   >::max_size(void)const 
    public: unsigned int __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::max_size(void)const 
    public: unsigned int __thiscall std::_Wrap_alloc<class std::allocator<wchar_t>
   >::max_size(void)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __fastcall max_size(allocator<char> *param_1)

{
  std::allocator_traits<class_std::allocator<char>_>::max_size(param_1);
  return;
}



// Function: FUN_1000c8d0 at 1000c8d0

undefined4 FUN_1000c8d0(void)

{
  return 0xffffffff;
}



// Function: max_size at 1000c8e0

/* Library Function - Single Match
    public: static unsigned int __cdecl std::allocator_traits<class std::allocator<char>
   >::max_size(class std::allocator<char> const &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

uint __cdecl std::allocator_traits<class_std::allocator<char>_>::max_size(allocator<char> *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1000c8d0();
  return uVar1;
}



// Function: FID_conflict:max_size at 1000c8f0

/* Library Function - Multiple Matches With Different Base Names
    public: unsigned int __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::max_size(void)const 
    public: unsigned int __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::max_size(void)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

int FID_conflict_max_size(void)

{
  allocator<char> *paVar1;
  uint uVar2;
  int local_10;
  undefined1 local_5;
  
  paVar1 = (allocator<char> *)Getal(&local_5);
  uVar2 = max_size(paVar1);
  if (uVar2 < 2) {
    local_10 = 1;
  }
  else {
    local_10 = uVar2 - 1;
  }
  return local_10;
}



// Function: FUN_1000c930 at 1000c930

void __cdecl FUN_1000c930(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000c960 at 1000c960

void * FUN_1000c960(void *param_1,int param_2)

{
  char *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10022fe9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = std::_Syserror_map(param_2);
  if (local_18 == (char *)0x0) {
    local_18 = "unknown error";
  }
  basic_string<>(param_1,local_18);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c9f0 at 1000c9f0

void * FUN_1000c9f0(void *param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023029;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 == 1) {
    basic_string<>(param_1,"iostream stream error");
  }
  else {
    FUN_1000c960(param_1,param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ca80 at 1000ca80

void * FUN_1000ca80(void *param_1,int param_2)

{
  char *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023069;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = std::_Winerror_map(param_2);
  if (local_18 == (char *)0x0) {
    local_18 = "unknown error";
  }
  basic_string<>(param_1,local_18);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000cb10 at 1000cb10

void * __cdecl FUN_1000cb10(void *param_1,void *param_2,size_t param_3)

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



// Function: FUN_1000cb50 at 1000cb50

char * FUN_1000cb50(void)

{
  return "generic";
}



// Function: FUN_1000cb60 at 1000cb60

char * FUN_1000cb60(void)

{
  return "iostream";
}



// Function: FUN_1000cb70 at 1000cb70

char * FUN_1000cb70(void)

{
  return "system";
}



// Function: FUN_1000cb80 at 1000cb80

bool __cdecl FUN_1000cb80(void *param_1,int param_2,wchar_t *param_3)

{
  size_t sVar1;
  errno_t eVar2;
  
  sVar1 = FUN_1000cbd0(param_3);
  eVar2 = memcpy_s(param_1,param_2 << 1,param_3,sVar1 * 2 + 2);
  return eVar2 == 0;
}



// Function: FUN_1000cbd0 at 1000cbd0

size_t __cdecl FUN_1000cbd0(wchar_t *param_1)

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



// Function: FUN_1000cbf0 at 1000cbf0

undefined4 __fastcall FUN_1000cbf0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000cc10 at 1000cc10

void __cdecl FUN_1000cc10(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcat_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000cc40 at 1000cc40

void __cdecl FUN_1000cc40(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000cc70 at 1000cc70

undefined * FUN_1000cc70(void)

{
  return &DAT_1003540c;
}



// Function: memmove_s at 1000cc80

/* Library Function - Single Match
    void __cdecl ATL::Checked::memmove_s(void *,unsigned int,void const *,unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug, Visual
   Studio 2012 Debug */

void __cdecl ATL::Checked::memmove_s(void *param_1,uint param_2,void *param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_1000ce20((uchar *)param_1,param_2,(uchar *)param_3,param_4);
  AtlCrtErrorCheck(iVar1);
  return;
}



// Function: value at 1000ccb0

/* Library Function - Single Match
    public: int __thiscall std::error_code::value(void)const 
   
   Library: Visual Studio */

int __thiscall std::error_code::value(error_code *this)

{
  return *(int *)this;
}



// Function: value at 1000ccc0

/* Library Function - Single Match
    public: int __thiscall std::error_condition::value(void)const 
   
   Libraries: Visual Studio 2010 Debug, Visual Studio 2010 Release, Visual Studio 2012 Debug, Visual
   Studio 2012 Release */

int __thiscall std::error_condition::value(error_condition *this)

{
  return *(int *)this;
}



// Function: FUN_1000ccd0 at 1000ccd0

void __cdecl FUN_1000ccd0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: _HRESULT_FROM_WIN32 at 1000cd00

/* Library Function - Single Match
    _HRESULT_FROM_WIN32
   
   Library: Visual Studio */

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



// Function: FUN_1000cd40 at 1000cd40

undefined4 __cdecl FUN_1000cd40(int *param_1,int *param_2)

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



// Function: FUN_1000cde0 at 1000cde0

bool __cdecl FUN_1000cde0(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return iVar1 == 0;
}



// Function: FUN_1000ce20 at 1000ce20

void __cdecl FUN_1000ce20(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
  _mbsnbcpy_s(param_1,param_2,param_3,param_4);
  return;
}



// Function: __tcschr at 1000ce40

/* Library Function - Single Match
    __tcschr
   
   Library: Visual Studio 2005 Debug */

void __cdecl __tcschr(uchar *param_1,uchar *param_2)

{
  _mbsstr(param_1,param_2);
  return;
}



// Function: FUN_1000ce60 at 1000ce60

int __fastcall FUN_1000ce60(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100230e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001ad0((undefined4 *)(param_1 + 0xc));
  local_8 = 0;
  FUN_10013140(param_1);
  FUN_10013120(param_1 + 4);
  FUN_10013640(param_1 + 8);
  FUN_10013410((CComCriticalSection *)(param_1 + 0x2c));
  local_8._0_1_ = 1;
  FUN_10013240((undefined4 *)(param_1 + 0x44));
  local_8._0_1_ = 2;
  FUN_100137a0((undefined4 *)(param_1 + 0x48));
  local_8._0_1_ = 3;
  FUN_100137a0((undefined4 *)(param_1 + 0x4c));
  local_8._0_1_ = 4;
  FUN_10019990((undefined4 *)(param_1 + 0x54));
  local_8._0_1_ = 5;
  FUN_100132e0((undefined4 *)(param_1 + 0x60));
  local_8._0_1_ = 6;
  FUN_10013290((undefined4 *)(param_1 + 0x68));
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_10013880((undefined4 *)(param_1 + 0x6c));
  FUN_10015d00((void *)(param_1 + 0x54),0xffffffff);
  ExceptionList = local_10;
  return param_1;
}



// Function: CCIAuditTrail_Initialize at 1000cf50

void __fastcall CCIAuditTrail_Initialize(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002315b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._0_1_ = 6;
  local_8._1_3_ = 0;
  FUN_10013a80((int *)(param_1 + 0x68));
  local_8._0_1_ = 5;
  FUN_10013ac0((int *)(param_1 + 0x60));
  local_8._0_1_ = 4;
  ~_ExceptionPtr_static<>((int *)(param_1 + 0x54));
  local_8._0_1_ = 3;
  FUN_100032d0((int *)(param_1 + 0x4c));
  local_8._0_1_ = 2;
  FUN_100032d0((int *)(param_1 + 0x48));
  local_8._0_1_ = 1;
  FUN_10013a60((int *)(param_1 + 0x44));
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__CAtlWinModule((LPCRITICAL_SECTION)(param_1 + 0x2c));
  local_8 = 0xffffffff;
  ~_ExceptionPtr_static<>(param_1 + 0xc);
  ExceptionList = local_10;
  return;
}



// Function: CCIAuditTrail_Initialize at 1000d010

void CCIAuditTrail_Initialize(void *param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  uint uStack_27c;
  int local_250;
  int *local_24c;
  int *local_248;
  int *local_244;
  int local_23c;
  undefined4 local_238;
  undefined4 local_234;
  int local_230;
  char local_22a;
  char local_229;
  uint local_228;
  char local_221;
  char local_220 [260];
  char local_11c [260];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100231d0;
  local_10 = ExceptionList;
  uStack_27c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_27c;
  ExceptionList = &local_10;
  local_228 = 0;
  local_8 = 0;
  local_18 = uStack_27c;
  puVar1 = &uStack_27c;
  if (param_2 == 0) {
    FUN_10019ce0(0x67,0x20,PTR_s_Initialization_of_AuditTrail_com_100350e8,
                 "CCIAuditTrail::Initialize(CICalDataServer* pCalDataServer,                     BSTR toolIntance, BSTR toolVersion))"
                 ,2,(IID *)0x0,"CIAuditTrail.cpp",0x90);
    FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  FID_conflict_operator_((void *)((int)param_1 + 0x44),param_2);
  FUN_10013f40((void *)((int)param_1 + 0x48),param_3);
  FUN_10013f40((void *)((int)param_1 + 0x4c),param_4);
  FUN_1000f300(param_1);
  if (*(int *)((int)param_1 + 0x50) == 2) goto LAB_1000d34a;
  FUN_100137a0(&local_230);
  local_8._0_1_ = 1;
  local_221 = '\0';
  if (param_3 == 0) {
LAB_1000d163:
    local_234 = 1;
  }
  else {
    local_24c = FUN_10002650(&local_23c,"");
    local_8 = CONCAT31(local_8._1_3_,2);
    local_228 = local_228 | 1;
    bVar2 = FUN_100141b0((void *)((int)param_1 + 0x48),local_24c);
    if (bVar2) goto LAB_1000d163;
    local_234 = 0;
  }
  local_22a = (char)local_234;
  local_8 = 1;
  if ((local_228 & 1) != 0) {
    local_228 = local_228 & 0xfffffffe;
    FUN_100032d0(&local_23c);
  }
  if (local_22a == '\0') {
    iVar3 = FUN_10015cb0((int *)((int)param_1 + 0x48));
    if (iVar3 == 0xc) {
      if (param_4 == 0) {
LAB_1000d269:
        local_238 = 1;
      }
      else {
        local_248 = FUN_10002650(&local_250,"");
        local_8 = CONCAT31(local_8._1_3_,3);
        local_228 = local_228 | 2;
        local_244 = local_248;
        bVar2 = FUN_100141b0((void *)((int)param_1 + 0x4c),local_248);
        if (bVar2) goto LAB_1000d269;
        local_238 = 0;
      }
      local_229 = (char)local_238;
      local_8 = 1;
      if ((local_228 & 2) != 0) {
        local_228 = local_228 & 0xfffffffd;
        FUN_100032d0(&local_250);
      }
      if (local_229 == '\0') {
        iVar3 = FUN_10015cb0((int *)((int)param_1 + 0x4c));
        if (iVar3 != 8) {
          sprintf(local_220,
                  "Size of ToolVersion parameter is incorrect.Expected to be %lu bytes(hex value)",8
                 );
          FUN_10013e90(&local_230,local_220);
          local_221 = '\x01';
        }
      }
      else {
        FUN_10013e90(&local_230,
                     "Invalid ToolVersion has been provided for Audit Trail Initialization");
        local_221 = '\x01';
      }
    }
    else {
      sprintf(local_11c,
              "Size of ToolInstance parameter is incorrect.Expected to be %lu bytes(hex value).",0xc
             );
      FUN_10013e90(&local_230,local_11c);
      local_221 = '\x01';
    }
  }
  else {
    FUN_10013e90(&local_230,"Invalid ToolInstance has been provided for Audit Trail Initialization")
    ;
    local_221 = '\x01';
  }
  if (local_221 == '\x01') {
    FUN_10014400(&local_230);
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  local_8 = local_8 & 0xffffff00;
  FUN_100032d0(&local_230);
LAB_1000d34a:
  FUN_1000d41a();
  return;
}



// Function: Catch@1000d34f at 1000d34f

undefined * Catch_1000d34f(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -600),"CIAuditTrail.cpp",0xce,
                       "CCIAuditTrail::Initialize",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x23c) = uVar2;
  return &DAT_1000d434;
}



// Function: Catch@1000d3a1 at 1000d3a1

undefined * Catch_1000d3a1(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x268),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x268),"CIAuditTrail.cpp",0xce,
                       "CCIAuditTrail::Initialize",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x250) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uStack0000001c = 0x1000d40e;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x268));
  return &DAT_1000d423;
}



// Function: FUN_1000d41a at 1000d41a

void FUN_1000d41a(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000d45d;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CCIAuditTrail_SetChangeCodeBits at 1000d470

void CCIAuditTrail_SetChangeCodeBits(void *param_1,short *param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  IUnknown *pIVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined2 *puVar15;
  _GUID *p_Var16;
  uint uStack_1e0;
  undefined4 local_1d0 [15];
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  uint local_170;
  undefined2 local_16c [4];
  undefined4 local_164;
  int local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 *local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_130 [4];
  uint *local_12c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_128;
  CComBSTR local_124 [4];
  undefined4 *local_120;
  int local_11c [2];
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  long local_100;
  double local_fc;
  long local_f4;
  long local_f0;
  long local_ec;
  int *local_e8;
  int local_e4;
  int *local_e0;
  long local_dc;
  undefined4 local_d8;
  long local_d4;
  long local_d0;
  int *local_cc;
  int *local_c8;
  int *local_c4;
  long local_c0;
  int *local_bc;
  int *local_b8;
  int *local_b4;
  long local_b0;
  int *local_ac;
  int *local_a8;
  int *local_a4;
  int *local_a0;
  long local_9c;
  long local_98;
  int local_94;
  undefined4 local_90;
  int local_8c;
  int local_88;
  size_t local_84;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_80 [4];
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_7c [4];
  int local_78;
  int local_74;
  uint local_70;
  void *local_6c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_68 [4];
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  char local_4d;
  int local_4c;
  size_t local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  char local_32 [2];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [24];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100232ae;
  local_10 = ExceptionList;
  uStack_1e0 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1e0;
  ExceptionList = &local_10;
  local_58 = 0;
  local_8 = 0;
  local_18 = uStack_1e0;
  cVar1 = FUN_10012730(0,(void *)((int)param_1 + 0x44));
  if (cVar1 == '\0') {
    FUN_10019ce0(0x66,0x20,PTR_s_Data_source_not_initialized_100350e4,
                 "CCIAuditTrail::SetChangeCodeBits ()",2,(IID *)0x0,"CIAuditTrail.cpp",0x20f);
    FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
code_r0x1000e061:
    CCIAuditTrail_get_CurrentRecordIndex();
    return;
  }
  uVar3 = FUN_1000f4b0(param_1);
  if (uVar3 == 1) {
    FUN_1000f300(param_1);
  }
  if ((*(int *)((int)param_1 + 0x50) != 0) && (*(int *)((int)param_1 + 0x50) != 1)) {
    local_58 = 0x80004001;
    goto code_r0x1000e061;
  }
  FUN_10011e00(&local_44,
               (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               ((int)param_1 + 0x68));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_c4 = (int *)FUN_10014550(&local_44);
  local_f4 = (**(code **)(*local_c4 + 0x34))(local_c4);
  if (local_f4 < 0) {
    p_Var16 = (_GUID *)&DAT_1002c6c4;
    pIVar4 = (IUnknown *)FUN_10014360(&local_44);
    _com_issue_errorex(local_f4,pIVar4,p_Var16);
  }
  FUN_10013860(&local_110);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_e8 = (int *)FUN_10014550(&local_44);
  local_f0 = (**(code **)(*local_e8 + 0x28))(local_e8,&local_110);
  if (local_f0 < 0) {
    p_Var16 = (_GUID *)&DAT_1002c6c4;
    pIVar4 = (IUnknown *)FUN_10014360(&local_44);
    _com_issue_errorex(local_f0,pIVar4,p_Var16);
  }
  local_38 = 0;
  Ordinal_23(local_108,&local_38);
  FUN_10019bb0(0x96,PTR_s_Started_setting__audit_trail_cod_1003512c);
  local_8._0_1_ = 3;
  local_94 = *(int *)((int)param_1 + 0x6c);
  local_60 = *(int *)((int)param_1 + 0x70);
  local_5c = *(int *)((int)param_1 + 0x74);
  local_84 = *(size_t *)((int)param_1 + 0x78);
  local_e4 = *(int *)((int)param_1 + 0x80);
  local_70 = (uint)*(byte *)(local_38 + local_94);
  local_4c = FUN_10011d00(local_70,local_5c);
  local_40 = local_84 * local_4c;
  local_fc = 0.0;
  local_128 = FUN_10011720(local_130,*(int *)((int)param_1 + 0x50));
  local_8._0_1_ = 4;
  local_114 = local_128;
  FUN_10011f40(local_68,local_128);
  local_8._0_1_ = 6;
  FUN_10013a80((int *)local_130);
  FUN_10012080(&local_88,local_68);
  local_8 = CONCAT31(local_8._1_3_,7);
  local_a4 = (int *)FUN_100145e0(&local_88);
  local_d4 = (**(code **)(*local_a4 + 0x1c))(local_a4,local_11c);
  if (local_d4 < 0) {
    p_Var16 = (_GUID *)&DAT_1002c6d4;
    pIVar4 = (IUnknown *)FUN_10014390(&local_88);
    _com_issue_errorex(local_d4,pIVar4,p_Var16);
  }
  FUN_10013660(&local_54,local_11c[0],'\0');
  local_8 = CONCAT31(local_8._1_3_,8);
  bVar2 = FUN_100141b0(&local_54,(int *)&DAT_10035420);
  if (!bVar2) {
    bVar2 = FUN_100141b0(&local_54,(int *)&DAT_10035458);
    if (!bVar2) {
      local_ac = (int *)FUN_10014610((int *)local_68);
      local_ec = (**(code **)(*local_ac + 0x28))(local_ac,&local_fc);
      if (local_ec < 0) {
        p_Var16 = (_GUID *)&DAT_1002c6e4;
        pIVar4 = (IUnknown *)FUN_100143a0((undefined4 *)local_68);
        _com_issue_errorex(local_ec,pIVar4,p_Var16);
      }
      FUN_10012120(&local_8c,local_68);
      local_8._0_1_ = 9;
      FUN_100133c0((undefined4 *)local_7c);
      local_8 = CONCAT31(local_8._1_3_,10);
      local_b4 = (int *)FUN_10014700(&local_8c);
      piVar7 = FID_conflict_operator_((int *)local_7c);
      local_dc = (**(code **)(*local_b4 + 0x4c))(local_b4,piVar7);
      if (local_dc < 0) {
        p_Var16 = (_GUID *)&DAT_1002c6a4;
        pIVar4 = (IUnknown *)FUN_100143e0(&local_8c);
        _com_issue_errorex(local_dc,pIVar4,p_Var16);
      }
      FUN_100121c0(&local_74,local_7c);
      local_8._0_1_ = 0xb;
      FUN_10002100(&local_90);
      local_8 = CONCAT31(local_8._1_3_,0xc);
      local_bc = (int *)FUN_100146d0(&local_74);
      uVar8 = FUN_10003600(&local_90);
      local_100 = (**(code **)(*local_bc + 0x2c))(local_bc,uVar8);
      if (local_100 < 0) {
        p_Var16 = (_GUID *)&DAT_1002c704;
        pIVar4 = (IUnknown *)FUN_100143d0(&local_74);
        _com_issue_errorex(local_100,pIVar4,p_Var16);
      }
      local_148 = (undefined4 *)ATL::CComBSTR::CComBSTR(local_124,"HRS");
      local_8._0_1_ = 0xd;
      local_120 = local_148;
      local_4d = FUN_10014170(&local_90,local_148);
      local_8 = CONCAT31(local_8._1_3_,0xc);
      FUN_10002f00((undefined4 *)local_124);
      if (local_4d != '\0') {
        iVar5 = FUN_10010f70(&local_54);
        local_fc = (double)iVar5;
      }
      local_8._0_1_ = 0xb;
      FUN_10002f00(&local_90);
      local_8._0_1_ = 10;
      FUN_10013b60(&local_74);
      local_8._0_1_ = 9;
      FUN_10013ba0((int *)local_7c);
      local_8 = CONCAT31(local_8._1_3_,8);
      FUN_10013b80(&local_8c);
      goto LAB_1000d94e;
    }
  }
  iVar5 = FUN_10010f70(&local_54);
  local_fc = (double)iVar5;
LAB_1000d94e:
  local_32[0] = '\0';
  local_4c = FUN_100103b0(param_1,(short *)(local_38 + local_40 + local_60),(int)local_fc,&local_4c,
                          local_5c,local_32);
  local_70 = FUN_10011d30(local_4c,local_5c);
  *(undefined1 *)(local_38 + local_94) = (undefined1)local_70;
  if (local_32[0] == '\x01') {
    local_40 = local_84 * local_4c;
    memset((void *)(local_38 + local_40 + local_60),0,local_84);
  }
  local_40 = ((local_e4 - local_60) / local_5c) * local_4c + local_60;
  local_15c = ((local_e4 - local_60) / local_5c - *(int *)((int)param_1 + 0x7c)) * 8;
  FUN_10013860(local_16c);
  local_8._0_1_ = 0xe;
  local_6c = (void *)0x0;
  basic_string<>(local_30);
  local_8 = CONCAT31(local_8._1_3_,0xf);
  local_3c = 0;
  pcVar6 = (char *)FUN_10014400((int *)((int)param_1 + 0x4c));
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
            (local_30,pcVar6);
  puVar15 = local_16c;
  uVar3 = FUN_10015c90((int)local_30);
  iVar5 = FUN_10015c50((_String_val<struct_std::_Simple_types<char>_> *)local_30);
  local_48 = FUN_1001ca70(iVar5,uVar3,puVar15);
  if (local_48 != 0) {
    Ordinal_23(local_164,&local_6c);
    memcpy((void *)(local_38 + local_40),local_6c,local_48);
    local_3c = local_3c + local_48;
    Ordinal_24(local_164);
  }
  pcVar6 = (char *)FUN_10014400((int *)((int)param_1 + 0x48));
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
            (local_30,pcVar6);
  puVar15 = local_16c;
  uVar3 = FUN_10015c90((int)local_30);
  iVar5 = FUN_10015c50((_String_val<struct_std::_Simple_types<char>_> *)local_30);
  local_48 = FUN_1001ca70(iVar5,uVar3,puVar15);
  if (local_48 != 0) {
    Ordinal_23(local_164,&local_6c);
    memcpy((void *)(local_38 + local_40 + local_3c),local_6c,local_48);
    local_3c = local_3c + local_48;
    Ordinal_24(local_164);
  }
  local_170 = CCIAuditTrail_UpdateChangeCodeBits(&local_fc);
  local_12c = &local_170;
  memcpy((void *)(local_38 + local_40 + local_3c),local_12c,4);
  local_3c = local_3c + 4;
  CCIAuditTrail_UpdateChangeCodeBits(param_1,param_2,local_38 + local_40 + local_3c,&local_15c);
  local_144 = local_110;
  local_140 = local_10c;
  local_13c = local_108;
  local_138 = local_104;
  local_cc = (int *)FUN_10014550(&local_44);
  local_9c = (**(code **)(*local_cc + 0x24))(local_cc,local_144,local_140,local_13c,local_138);
  if (local_9c < 0) {
    p_Var16 = (_GUID *)&DAT_1002c6c4;
    pIVar4 = (IUnknown *)FUN_10014360(&local_44);
    _com_issue_errorex(local_9c,pIVar4,p_Var16);
  }
  local_a0 = (int *)FUN_10014550(&local_44);
  local_58 = (**(code **)(*local_a0 + 0x30))(local_a0);
  if (local_58 < 0) {
    FUN_10013320(&local_64);
    local_8 = CONCAT31(local_8._1_3_,0x10);
    local_a8 = (int *)FUN_100145b0((int *)((int)param_1 + 0x44));
    piVar7 = FID_conflict_operator_(&local_64);
    local_b0 = (**(code **)(*local_a8 + 0x20))(local_a8,piVar7);
    if (local_b0 < 0) {
      p_Var16 = (_GUID *)&DAT_1002c674;
      pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)((int)param_1 + 0x44));
      _com_issue_errorex(local_b0,pIVar4,p_Var16);
    }
    local_134 = FUN_10010240(local_4c);
    FUN_10017fc0(&local_64,(void *)(local_38 + local_40));
    FUN_10013290((undefined4 *)local_80);
    local_8 = CONCAT31(local_8._1_3_,0x11);
    local_b8 = (int *)FUN_100145b0((int *)((int)param_1 + 0x44));
    piVar7 = FID_conflict_operator_((int *)local_80);
    uVar8 = FUN_10014430((int *)&DAT_10035468);
    uVar9 = FUN_10014390((undefined4 *)((int)param_1 + 0x68));
    local_c0 = (**(code **)(*local_b8 + 0x30))(local_b8,uVar9,uVar8,piVar7);
    if (local_c0 < 0) {
      p_Var16 = (_GUID *)&DAT_1002c674;
      pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)((int)param_1 + 0x44));
      _com_issue_errorex(local_c0,pIVar4,p_Var16);
    }
    local_32[1] = 0;
    memset(local_32 + 1,local_70,1);
    FUN_1001d320(local_1d0);
    local_8._0_1_ = 0x12;
    FUN_1001d560(local_1d0,1,local_32 + 1);
    puVar10 = (undefined4 *)FUN_1001d420((int)local_1d0);
    local_194 = *puVar10;
    local_190 = puVar10[1];
    local_18c = puVar10[2];
    local_188 = puVar10[3];
    FUN_10013820(&local_184,&local_194);
    local_8._0_1_ = 0x13;
    FUN_10011d60(&local_78,local_80);
    local_8 = CONCAT31(local_8._1_3_,0x14);
    local_d8 = 0;
    local_c8 = (int *)FUN_10014520(&local_78);
    local_d0 = (**(code **)(*local_c8 + 0x1c))(local_c8,&local_d8);
    if (local_d0 < 0) {
      p_Var16 = (_GUID *)&DAT_1002c684;
      pIVar4 = (IUnknown *)FUN_10014350(&local_78);
      _com_issue_errorex(local_d0,pIVar4,p_Var16);
    }
    local_158 = local_184;
    local_154 = local_180;
    local_150 = local_17c;
    local_14c = local_178;
    local_e0 = (int *)FUN_100146a0(&local_64);
    uVar8 = *(undefined4 *)((int)param_1 + 100);
    uVar9 = local_158;
    uVar12 = local_154;
    uVar13 = local_150;
    uVar14 = local_14c;
    uVar11 = FUN_10014380((undefined4 *)((int)param_1 + 0x44));
    local_98 = (**(code **)(*local_e0 + 0x28))
                         (local_e0,1,local_d8,0,0,0,uVar11,uVar9,uVar12,uVar13,uVar14,uVar8);
    if (local_98 < 0) {
      p_Var16 = (_GUID *)&DAT_1002c694;
      pIVar4 = (IUnknown *)FUN_100143c0(&local_64);
      _com_issue_errorex(local_98,pIVar4,p_Var16);
    }
    local_58 = 0;
    local_8._0_1_ = 0x13;
    FUN_10013a00(&local_78);
    local_8._0_1_ = 0x12;
    FUN_10013df0(&local_184);
    local_8._0_1_ = 0x11;
    FUN_1001d3a0(local_1d0);
    local_8._0_1_ = 0x10;
    FUN_10013a80((int *)local_80);
    local_8 = CONCAT31(local_8._1_3_,0xf);
    FUN_10013b00(&local_64);
  }
  Ordinal_24(local_108);
  FUN_10019bb0(0x97,PTR_s_Setting__audit_trail_codes_in_th_10035130);
  local_8._0_1_ = 0xe;
  ~basic_string<>(local_30);
  local_8._0_1_ = 8;
  FUN_10013df0(local_16c);
  local_8._0_1_ = 7;
  FUN_100032d0(&local_54);
  local_8._0_1_ = 6;
  FUN_10013a80(&local_88);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10013aa0((int *)local_68);
  CCIAuditTrail_SetChangeCodeBits();
  return;
}



// Function: Catch@1000dfbc at 1000dfbc

void Catch_1000dfbc(void)

{
  int unaff_EBP;
  
  Ordinal_24(*(undefined4 *)(unaff_EBP + -0x104));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: CCIAuditTrail_SetChangeCodeBits at 1000dfd8

void CCIAuditTrail_SetChangeCodeBits(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10013df0(unaff_EBP + -0x10c);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_10013a20((int *)(unaff_EBP + -0x40));
  CCIAuditTrail_get_CurrentRecordIndex();
  return;
}



// Function: Catch@1000e066 at 1000e066

undefined * Catch_1000e066(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x194),"CIAuditTrail.cpp",0x215,
                       "CCIAuditTrail::SetChangeCodeBits",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x114) = uVar2;
  return &DAT_1000e14b;
}



// Function: Catch@1000e0b8 at 1000e0b8

undefined * Catch_1000e0b8(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x1a4),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x1a4),"CIAuditTrail.cpp",0x215,
                       "CCIAuditTrail::SetChangeCodeBits",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x170) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  uStack0000001c = 0x1000e125;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1a4));
  return &DAT_1000e13a;
}



// Function: CCIAuditTrail_get_CurrentRecordIndex at 1000e131

void CCIAuditTrail_get_CurrentRecordIndex(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000e175;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CCIAuditTrail_get_CurrentRecordIndex at 1000e180

void CCIAuditTrail_get_CurrentRecordIndex(void *param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100232de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  cVar1 = FUN_10012730(0,(void *)((int)param_1 + 0x44));
  if (cVar1 == '\0') {
    FUN_10019ce0(0x66,0x20,PTR_s_Data_source_not_initialized_100350e4,
                 "CCIAuditTrail::get_CurrentRecordIndex",2,(IID *)0x0,"CIAuditTrail.cpp",0x310);
    FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
  }
  else {
    uVar2 = FUN_1000f4b0(param_1);
    if (uVar2 == 1) {
      FUN_1000f300(param_1);
    }
    if (*(int *)((int)param_1 + 0x50) == 2) {
      iVar3 = FUN_1000fb20();
      *param_2 = iVar3;
    }
    else {
      iVar3 = FUN_1000f680();
      *param_2 = iVar3;
    }
  }
  CCIAuditTrail_get_AuditTrailRecords();
  return;
}



// Function: Catch@1000e25e at 1000e25e

undefined * Catch_1000e25e(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1c),"CIAuditTrail.cpp",0x317,
                       "CCIAuditTrail::get_CurrentRecordIndex",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_1000e32e;
}



// Function: Catch@1000e2aa at 1000e2aa

undefined * Catch_1000e2aa(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x2c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x2c),"CIAuditTrail.cpp",0x317,
                       "CCIAuditTrail::get_CurrentRecordIndex",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x1000e30b;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return &DAT_1000e320;
}



// Function: CCIAuditTrail_get_AuditTrailRecords at 1000e317

undefined4 CCIAuditTrail_get_AuditTrailRecords(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CCIAuditTrail_get_AuditTrailRecords at 1000e350

void CCIAuditTrail_get_AuditTrailRecords(void *param_1,int param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  IUnknown *pIVar4;
  _GUID *p_Var5;
  uint uStack_a8;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  long local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  long local_28;
  int local_24;
  undefined4 *local_20;
  int local_1c;
  ushort local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002331c;
  local_10 = ExceptionList;
  uStack_a8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_a8;
  ExceptionList = &local_10;
  local_8 = 0;
  puVar1 = &uStack_a8;
  if (param_2 == 0) {
    FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  cVar2 = FUN_10012730(0,(void *)((int)param_1 + 0x44));
  if (cVar2 == '\0') {
    FUN_10019ce0(0x66,0x20,PTR_s_Data_source_not_initialized_100350e4,
                 "CCIAuditTrail::get_AuditTrailRecords",2,(IID *)0x0,"CIAuditTrail.cpp",0x2dc);
    FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
  }
  else {
    uVar3 = FUN_1000f4b0(param_1);
    if (uVar3 == 1) {
      FUN_1000f300(param_1);
    }
    FUN_100132e0(&local_1c);
    local_8._0_1_ = 1;
    FUN_10014df0(&local_1c,(IID *)&DAT_1002b7d4,(LPUNKNOWN)0x0,0x17);
    FUN_10013860(&local_84);
    local_8._0_1_ = 2;
    FUN_10013860(&local_64);
    local_8 = CONCAT31(local_8._1_3_,3);
    local_64 = CONCAT22(local_64._2_2_,3);
    local_38 = 0;
    local_34 = (int *)FUN_10014640((int *)((int)param_1 + 0x60));
    local_28 = (**(code **)(*local_34 + 0x20))(local_34,&local_38);
    if (local_28 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c6f4;
      pIVar4 = (IUnknown *)FUN_100143b0((undefined4 *)((int)param_1 + 0x60));
      _com_issue_errorex(local_28,pIVar4,p_Var5);
    }
    for (local_18 = 0; (int)(uint)local_18 < local_38; local_18 = local_18 + 1) {
      local_6c = (uint)local_18;
      local_74 = local_64;
      local_70 = local_60;
      local_68 = local_58;
      local_5c = local_6c;
      local_30 = (int *)FUN_10014640((int *)((int)param_1 + 0x60));
      local_24 = (**(code **)(*local_30 + 0x24))
                           (local_30,local_74,local_70,local_6c,local_68,&local_84);
      if (local_24 < 0) {
        p_Var5 = (_GUID *)&DAT_1002c6f4;
        pIVar4 = (IUnknown *)FUN_100143b0((undefined4 *)((int)param_1 + 0x60));
        _com_issue_errorex(local_24,pIVar4,p_Var5);
      }
      local_50 = local_84;
      local_4c = local_80;
      local_48 = local_7c;
      local_44 = local_78;
      local_2c = (int *)FUN_10014640(&local_1c);
      (**(code **)(*local_2c + 0x28))(local_2c,local_50,local_4c,local_48,local_44);
    }
    local_20 = (undefined4 *)FUN_10014640(&local_1c);
    local_3c = (**(code **)*local_20)(local_20,&DAT_10029a88,param_2);
    if (local_3c < 0) {
      p_Var5 = (_GUID *)&DAT_1002c6f4;
      pIVar4 = (IUnknown *)FUN_100143b0(&local_1c);
      _com_issue_errorex(local_3c,pIVar4,p_Var5);
    }
    local_8._0_1_ = 2;
    FUN_10013df0(&local_64);
    local_8._0_1_ = 1;
    FUN_10013df0(&local_84);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10013ac0(&local_1c);
  }
  FUN_1000e6e2();
  return;
}



// Function: Catch@1000e61d at 1000e61d

undefined * Catch_1000e61d(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x84),"CIAuditTrail.cpp",0x2e2,
                       "CCIAuditTrail::get_AuditTrailRecords",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x50) = uVar2;
  return &DAT_1000e6f9;
}



// Function: Catch@1000e66c at 1000e66c

undefined * Catch_1000e66c(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x94),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x94),"CIAuditTrail.cpp",0x2e2,
                       "CCIAuditTrail::get_AuditTrailRecords",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uStack0000001c = 0x1000e6d6;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x94));
  return &DAT_1000e6eb;
}



// Function: FUN_1000e6e2 at 1000e6e2

undefined4 FUN_1000e6e2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CCIAuditTrail_Clear at 1000e720

void CCIAuditTrail_Clear(void *param_1)

{
  bool bVar1;
  uint uVar2;
  IUnknown *pIVar3;
  int *piVar4;
  undefined4 uVar5;
  _GUID *p_Var6;
  uint uStack_d0;
  undefined1 local_b0 [24];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int *local_70;
  long local_6c;
  long local_68;
  int *local_64;
  int *local_60;
  int *local_5c;
  undefined4 *local_58;
  long local_54;
  int *local_50;
  long local_4c;
  ULONG local_48;
  long local_44;
  long local_40;
  int *local_3c;
  int local_38;
  int local_34;
  short local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023380;
  local_10 = ExceptionList;
  uStack_d0 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_d0;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 0;
  bVar1 = FUN_10013ff0((void *)((int)param_1 + 0x44),0);
  if (bVar1) {
    FUN_10019ce0(0x66,0x20,PTR_s_Data_source_not_initialized_100350e4,
                 "CCIAuditTrail::get_CurrentRecordIndex",2,(IID *)0x0,"CIAuditTrail.cpp",0x227);
    FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
  }
  uVar2 = FUN_1000f4b0(param_1);
  if (uVar2 == 1) {
    FUN_1000f300(param_1);
  }
  if ((*(int *)((int)param_1 + 0x50) == 0) || (*(int *)((int)param_1 + 0x50) == 1)) {
    FUN_10011e00(&local_20,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 ((int)param_1 + 0x68));
    local_8._0_1_ = 1;
    FUN_10013860(&local_80);
    local_8 = CONCAT31(local_8._1_3_,2);
    local_70 = (int *)FUN_10014550(&local_20);
    local_44 = (**(code **)(*local_70 + 0x28))(local_70,&local_80);
    if (local_44 < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6c4;
      pIVar3 = (IUnknown *)FUN_10014360(&local_20);
      _com_issue_errorex(local_44,pIVar3,p_Var6);
    }
    local_34 = 0;
    Ordinal_23(local_78,&local_34);
    *(undefined1 *)(local_34 + *(int *)((int)param_1 + 0x6c)) = 0;
    memset((void *)(local_34 + *(int *)((int)param_1 + 0x70)),0,
           *(int *)((int)param_1 + 0x78) * *(int *)((int)param_1 + 0x74));
    Ordinal_24(local_78);
    local_98 = local_80;
    local_94 = local_7c;
    local_90 = local_78;
    local_8c = local_74;
    local_5c = (int *)FUN_10014550(&local_20);
    local_4c = (**(code **)(*local_5c + 0x24))(local_5c,local_98,local_94,local_90,local_8c);
    if (local_4c < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6c4;
      pIVar3 = (IUnknown *)FUN_10014360(&local_20);
      _com_issue_errorex(local_4c,pIVar3,p_Var6);
    }
    local_64 = (int *)FUN_10014550(&local_20);
    local_18 = (**(code **)(*local_64 + 0x30))(local_64);
    if (local_18 < 0) {
      for (local_24 = 0; local_24 < *(int *)((int)param_1 + 0x74); local_24 = local_24 + 1) {
        local_84 = FUN_10010240(local_24);
        FUN_10018210(local_84);
      }
      local_18 = 0;
    }
    local_8._0_1_ = 1;
    FUN_10013df0(&local_80);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10013a20(&local_20);
  }
  else {
    FUN_100131d0(&local_1c);
    local_8 = CONCAT31(local_8._1_3_,3);
    local_54 = FUN_10014d30(&local_1c,(IID *)&DAT_1002a9c8,(LPUNKNOWN)0x0,0x17);
    if (local_54 < 0) {
      p_Var6 = (_GUID *)&DAT_1002aab0;
      pIVar3 = (IUnknown *)FUN_10014340(&local_1c);
      _com_issue_errorex(local_54,pIVar3,p_Var6);
    }
    FUN_10013320(&local_28);
    local_8._0_1_ = 4;
    FUN_100133c0(&local_2c);
    local_8 = CONCAT31(local_8._1_3_,5);
    local_3c = (int *)FUN_100145b0((int *)((int)param_1 + 0x44));
    piVar4 = FID_conflict_operator_(&local_28);
    local_6c = (**(code **)(*local_3c + 0x20))(local_3c,piVar4);
    if (local_6c < 0) {
      p_Var6 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)param_1 + 0x44));
      _com_issue_errorex(local_6c,pIVar3,p_Var6);
    }
    local_60 = (int *)FUN_100146a0(&local_28);
    piVar4 = FID_conflict_operator_(&local_2c);
    local_68 = (**(code **)(*local_60 + 0x20))(local_60,piVar4);
    if (local_68 < 0) {
      p_Var6 = (_GUID *)&DAT_1002c694;
      pIVar3 = (IUnknown *)FUN_100143c0(&local_28);
      _com_issue_errorex(local_68,pIVar3,p_Var6);
    }
    FUN_10013160(&local_38);
    local_8 = CONCAT31(local_8._1_3_,6);
    local_58 = (undefined4 *)FUN_10014730(&local_2c);
    piVar4 = FID_conflict_operator_(&local_38);
    local_40 = (**(code **)*local_58)(local_58,&DAT_1002a7f8,piVar4);
    if (local_40 < 0) {
      p_Var6 = (_GUID *)&DAT_10029bd8;
      pIVar3 = (IUnknown *)FUN_100143f0(&local_2c);
      _com_issue_errorex(local_40,pIVar3,p_Var6);
    }
    FUN_10013860(local_b0);
    local_8 = CONCAT31(local_8._1_3_,7);
    pIVar3 = (IUnknown *)FUN_100144f0(&local_1c);
    local_48 = FUN_10014f40(pIVar3);
    if ((int)local_48 < 0) {
      p_Var6 = (_GUID *)&DAT_1002aab0;
      pIVar3 = (IUnknown *)FUN_10014340(&local_1c);
      _com_issue_errorex(local_48,pIVar3,p_Var6);
    }
    local_50 = (int *)FUN_10014670(&local_38);
    uVar5 = FUN_10014340(&local_1c);
    local_18 = (**(code **)(*local_50 + 0x2c))(local_50,uVar5);
    if (local_18 < 0) {
      pIVar3 = (IUnknown *)FUN_100144f0(&local_1c);
      local_30 = FUN_100152c0(pIVar3);
      if (local_30 == -5) {
        FUN_10019ce0(0x68,0x20,PTR_s_Module_does_not_support_ClearAud_100350f4,
                     "CCIAuditTrail::Clear()",8,(IID *)0x0,"CIAuditTrail.cpp",0x28c);
        local_18 = 0;
      }
      else {
        _com_issue_error(local_18);
      }
    }
    local_8._0_1_ = 6;
    FUN_10013df0(local_b0);
    local_8._0_1_ = 5;
    FID_conflict__bad_alloc(&local_38);
    local_8._0_1_ = 4;
    FUN_10013ba0(&local_2c);
    local_8._0_1_ = 3;
    FUN_10013b00(&local_28);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_100139e0(&local_1c);
  }
  CCIAuditTrail_put_Group();
  return;
}



// Function: Catch@1000ebdd at 1000ebdd

undefined * Catch_1000ebdd(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x9c),"CIAuditTrail.cpp",0x296,"CCIAuditTrail::Clear"
                       ,*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x98) = uVar2;
  return &DAT_1000ecc2;
}



// Function: Catch@1000ec2f at 1000ec2f

undefined * Catch_1000ec2f(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0xbc),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0xbc),"CIAuditTrail.cpp",0x296,"CCIAuditTrail::Clear",
                       *puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x84) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uStack0000001c = 0x1000ec9c;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0xbc));
  return &DAT_1000ecb1;
}



// Function: CCIAuditTrail_put_Group at 1000eca8

undefined4 CCIAuditTrail_put_Group(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: CCIAuditTrail_put_Group at 1000ecf0

void CCIAuditTrail_put_Group(int param_1,undefined4 param_2)

{
  uint uStack_4c;
  undefined1 local_2c [24];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100233ae;
  local_10 = ExceptionList;
  uStack_4c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4c;
  ExceptionList = &local_10;
  FUN_100130f0(local_2c,param_1 + 0x28);
  local_8 = 1;
  FUN_10015d00((void *)(param_1 + 0x50),param_2);
  CCIAuditTrail_get_Group();
  return;
}



// Function: Catch@1000ed4a at 1000ed4a

undefined * Catch_1000ed4a(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x20),"CIAuditTrail.cpp",0x32a,
                       "CCIAuditTrail::put_Group",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_1000ee22;
}



// Function: Catch@1000ed96 at 1000ed96

undefined * Catch_1000ed96(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x38),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x38),"CIAuditTrail.cpp",0x32a,
                       "CCIAuditTrail::put_Group",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x1000edf7;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &DAT_1000ee0c;
}



// Function: CCIAuditTrail_get_Group at 1000ee03

undefined4 CCIAuditTrail_get_Group(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10013950((undefined4 *)(unaff_EBP + -0x28));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x1c);
}



// Function: CCIAuditTrail_get_Group at 1000ee70

void CCIAuditTrail_get_Group(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uStack_4c;
  undefined1 local_2c [24];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100233d9;
  local_10 = ExceptionList;
  uStack_4c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4c;
  ExceptionList = &local_10;
  FUN_100130f0(local_2c,param_1 + 0x28);
  local_8 = 1;
  if (param_2 == (undefined4 *)0x0) {
    FUN_10019a70(param_1 + 0x50,(uchar *)"CIAuditTrail.cpp");
  }
  uVar1 = FUN_10015c70(param_1 + 0x50);
  *param_2 = uVar1;
  CCIAuditTrail_GetIDsOfNames();
  return;
}



// Function: Catch@1000eefb at 1000eefb

undefined * Catch_1000eefb(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x20),"CIAuditTrail.cpp",0x344,
                       "CCIAuditTrail::get_Group",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  return &DAT_1000efd3;
}



// Function: Catch@1000ef47 at 1000ef47

undefined * Catch_1000ef47(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x38),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x38),"CIAuditTrail.cpp",0x344,
                       "CCIAuditTrail::get_Group",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uStack0000001c = 0x1000efa8;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return &DAT_1000efbd;
}



// Function: CCIAuditTrail_GetIDsOfNames at 1000efb4

undefined4 CCIAuditTrail_GetIDsOfNames(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10013950((undefined4 *)(unaff_EBP + -0x28));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x1c);
}



// Function: CCIAuditTrail_GetIDsOfNames at 1000f020

int CCIAuditTrail_GetIDsOfNames(int param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                uint *param_6)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100233fc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = FUN_10014fc0(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 < 0) {
    iVar1 = FUN_10014f90(param_1 + 4,param_2,param_3,param_4,param_5,param_6);
    if (iVar1 < 0) {
      iVar1 = FUN_1000f1bd();
      return iVar1;
    }
    *param_6 = *param_6 | 0x20000;
  }
  else {
    *param_6 = *param_6 | 0x10000;
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: Catch@1000f104 at 1000f104

undefined * Catch_1000f104(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x20),"CIAuditTrail.cpp",0x368,
                       "CCIAuditTrail::GetIDsOfNames",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar2;
  return &DAT_1000f1d4;
}



// Function: Catch@1000f150 at 1000f150

undefined * Catch_1000f150(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x30),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_100152b0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x30),"CIAuditTrail.cpp",0x368,
                       "CCIAuditTrail::GetIDsOfNames",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x1000f1b1;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return &DAT_1000f1c6;
}



// Function: FUN_1000f1bd at 1000f1bd

undefined4 FUN_1000f1bd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_1000f200 at 1000f200

undefined4
FUN_1000f200(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 local_8;
  
  local_8 = 0x80020003;
  if ((param_2 & 0xffff0000) == 0x10000) {
    local_8 = FUN_10015410(param_1,param_2 & 0xffff,param_3,param_4,param_5,param_6,param_7,param_8,
                           param_9);
  }
  else if ((param_2 & 0xffff0000) == 0x20000) {
    local_8 = FUN_100153d0(param_1 + 4,param_2 & 0xffff,param_3,param_4,param_5,param_6,param_7,
                           param_8,param_9);
  }
  return local_8;
}



// Function: FUN_1000f2b0 at 1000f2b0

undefined4 FUN_1000f2b0(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (1 < local_8) {
      return 1;
    }
    iVar1 = FUN_1000cd40((int *)(&PTR_DAT_10035170)[local_8],param_2);
    if (iVar1 != 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}



// Function: FUN_1000f300 at 1000f300

void __fastcall FUN_1000f300(void *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = FUN_1001b4b0((int *)((int)param_1 + 0x44));
  *(undefined4 *)((int)param_1 + 100) = uVar1;
  piVar2 = (int *)FUN_100145b0((int *)((int)param_1 + 0x44));
  (**(code **)(*piVar2 + 0x4c))(piVar2,*(undefined4 *)((int)param_1 + 100));
  uVar1 = FUN_1000f9d0(param_1,(int *)((int)param_1 + 0x44));
  *(undefined4 *)((int)param_1 + 0x50) = uVar1;
  if ((*(int *)((int)param_1 + 0x50) == 0) || (*(int *)((int)param_1 + 0x50) == 1)) {
    piVar2 = (int *)FUN_100145b0((int *)((int)param_1 + 0x44));
    piVar3 = FID_conflict_operator_((int *)((int)param_1 + 0x68));
    uVar1 = FUN_10014430((int *)&DAT_10035428);
    iVar4 = (**(code **)(*piVar2 + 0x30))(piVar2,0,uVar1,piVar3);
    if (iVar4 < 0) {
      FUN_10019ce0(0x67,0x20,PTR_s_Could_not_find_DataStructure_Aud_100350ec,
                   "CCIAuditTrail::Initialize()",2,(IID *)0x0,"CIAuditTrail.cpp",0xec);
      FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
    }
    FUN_100118d0((int)param_1);
  }
  else {
    piVar2 = (int *)FUN_100145b0((int *)((int)param_1 + 0x44));
    piVar3 = FID_conflict_operator_((int *)((int)param_1 + 0x68));
    uVar1 = FUN_10014430((int *)&DAT_10035464);
    iVar4 = (**(code **)(*piVar2 + 0x30))(piVar2,0,uVar1,piVar3);
    if (iVar4 < 0) {
      FUN_10019ce0(0x67,0x20,PTR_s_Could_not_find_ConfigFile__Audit_100350f0,
                   "CCIAuditTrail::Initialize()",2,(IID *)0x0,"CIAuditTrail.cpp",0x102);
      FUN_10019a70((int)param_1 + 0x54,(uchar *)"CIAuditTrail.cpp");
    }
  }
  FUN_1000fe60((int)param_1);
  return;
}



// Function: FUN_1000f4b0 at 1000f4b0

uint __fastcall FUN_1000f4b0(void *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  _GUID *p_Var5;
  uint local_40;
  int local_3c;
  long local_38;
  int *local_34;
  long local_30;
  int *local_2c;
  long local_28;
  int *local_24;
  int local_20;
  uint local_1c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_18 [4];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023427;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  local_14 = param_1;
  iVar1 = FUN_1000f9d0(param_1,(int *)((int)param_1 + 0x44));
  if (*(int *)((int)local_14 + 0x50) != iVar1) {
    local_1c = 1;
  }
  if (local_1c == 0) {
    FUN_10013290((undefined4 *)local_18);
    local_8 = 0;
    if ((*(int *)((int)local_14 + 0x50) == 0) || (*(int *)((int)local_14 + 0x50) == 1)) {
      local_24 = (int *)FUN_100145b0((int *)((int)local_14 + 0x44));
      piVar2 = FID_conflict_operator_((int *)local_18);
      uVar3 = FUN_10014430((int *)&DAT_10035428);
      local_28 = (**(code **)(*local_24 + 0x30))(local_24,0,uVar3,piVar2);
      if (local_28 < 0) {
        p_Var5 = (_GUID *)&DAT_1002c674;
        pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_14 + 0x44));
        _com_issue_errorex(local_28,pIVar4,p_Var5);
      }
    }
    else {
      local_2c = (int *)FUN_100145b0((int *)((int)local_14 + 0x44));
      piVar2 = FID_conflict_operator_((int *)local_18);
      uVar3 = FUN_10014430((int *)&DAT_10035464);
      local_30 = (**(code **)(*local_2c + 0x30))(local_2c,0,uVar3,piVar2);
      if (local_30 < 0) {
        p_Var5 = (_GUID *)&DAT_1002c674;
        pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_14 + 0x44));
        _com_issue_errorex(local_30,pIVar4,p_Var5);
      }
    }
    FUN_10011e00(&local_20,local_18);
    local_8 = CONCAT31(local_8._1_3_,1);
    local_3c = 0;
    local_34 = (int *)FUN_10014550(&local_20);
    local_38 = (**(code **)(*local_34 + 0x20))(local_34,&local_3c);
    if (local_38 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c6c4;
      pIVar4 = (IUnknown *)FUN_10014360(&local_20);
      _com_issue_errorex(local_38,pIVar4,p_Var5);
    }
    local_40 = (uint)(local_3c != *(int *)((int)local_14 + 0x80));
    local_1c = local_40;
    local_8 = local_8 & 0xffffff00;
    FUN_10013a20(&local_20);
    local_8 = 0xffffffff;
    FUN_10013a80((int *)local_18);
  }
  ExceptionList = local_10;
  return local_1c;
}



// Function: FUN_1000f680 at 1000f680

int FUN_1000f680(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  _GUID *p_Var5;
  double local_4c;
  int local_44;
  int local_40;
  long local_3c;
  int *local_38;
  long local_34;
  int *local_30;
  long local_2c;
  int *local_28;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_24 [4];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023452;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10013290((undefined4 *)local_24);
  local_8 = 0;
  local_28 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
  piVar2 = FID_conflict_operator_((int *)local_24);
  uVar3 = FUN_10014430((int *)&DAT_10035444);
  local_2c = (**(code **)(*local_28 + 0x30))(local_28,0,uVar3,piVar2,uVar1);
  if (local_2c < 0) {
    p_Var5 = (_GUID *)&DAT_1002c674;
    pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x44));
    _com_issue_errorex(local_2c,pIVar4,p_Var5);
  }
  FUN_10011f40(&local_20,local_24);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_4c = 0.0;
  local_30 = (int *)FUN_10014610(&local_20);
  local_34 = (**(code **)(*local_30 + 0x28))(local_30,&local_4c);
  if (local_34 < 0) {
    p_Var5 = (_GUID *)&DAT_1002c6e4;
    pIVar4 = (IUnknown *)FUN_100143a0(&local_20);
    _com_issue_errorex(local_34,pIVar4,p_Var5);
  }
  local_40 = 0;
  local_18 = (int)local_4c;
  local_1c = 0;
  local_38 = (int *)FUN_10014640((int *)(local_14 + 0x60));
  local_3c = (**(code **)(*local_38 + 0x20))(local_38,&local_1c);
  if (local_3c < 0) {
    p_Var5 = (_GUID *)&DAT_1002c6f4;
    pIVar4 = (IUnknown *)FUN_100143b0((undefined4 *)(local_14 + 0x60));
    _com_issue_errorex(local_3c,pIVar4,p_Var5);
  }
  if ((local_18 < 0) || (local_1c < local_18)) {
    FUN_10019a70(local_14 + 0x54,(uchar *)"CIAuditTrail.cpp");
  }
  local_44 = FUN_10011d00(local_18,local_1c);
  local_8 = local_8 & 0xffffff00;
  local_40 = local_44;
  FUN_10013aa0(&local_20);
  local_8 = 0xffffffff;
  FUN_10013a80((int *)local_24);
  ExceptionList = local_10;
  return local_44;
}



// Function: FUN_1000f850 at 1000f850

undefined4 FUN_1000f850(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  _GUID *p_Var5;
  undefined4 local_38;
  long local_34;
  int *local_30;
  long local_2c;
  int *local_28;
  long local_24;
  int *local_20;
  int local_1c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002347d;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10013290((undefined4 *)local_18);
  local_8 = 0;
  if (*(int *)(local_14 + 0x50) == 2) {
    local_20 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
    piVar2 = FID_conflict_operator_((int *)local_18);
    uVar3 = FUN_10014430((int *)&DAT_10035464);
    local_24 = (**(code **)(*local_20 + 0x30))(local_20,0,uVar3,piVar2);
    if (local_24 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x44));
      _com_issue_errorex(local_24,pIVar4,p_Var5);
    }
  }
  else {
    local_28 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
    piVar2 = FID_conflict_operator_((int *)local_18);
    uVar3 = FUN_10014430((int *)&DAT_10035470);
    local_2c = (**(code **)(*local_28 + 0x30))(local_28,0,uVar3,piVar2,uVar1);
    if (local_2c < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x44));
      _com_issue_errorex(local_2c,pIVar4,p_Var5);
    }
  }
  FUN_10011ea0(&local_1c,local_18);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_38 = 0xffffffff;
  local_30 = (int *)FUN_10014580(&local_1c);
  local_34 = (**(code **)(*local_30 + 0x24))(local_30,&local_38);
  if (local_34 < 0) {
    p_Var5 = (_GUID *)&DAT_1002c6b4;
    pIVar4 = (IUnknown *)FUN_10014370(&local_1c);
    _com_issue_errorex(local_34,pIVar4,p_Var5);
  }
  uVar3 = local_38;
  local_8 = local_8 & 0xffffff00;
  FUN_10013a40(&local_1c);
  local_8 = 0xffffffff;
  FUN_10013a80((int *)local_18);
  ExceptionList = local_10;
  return uVar3;
}



// Function: FUN_1000f9d0 at 1000f9d0

undefined4 __thiscall FUN_1000f9d0(void *this,int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  IUnknown *pIVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  _GUID *p_Var7;
  int local_24;
  long local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100234a0;
  local_10 = ExceptionList;
  uVar2 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = (int *)FUN_100145b0(param_1);
  local_20 = (**(code **)(*local_1c + 0x5c))(local_1c,&local_24,uVar2);
  if (local_20 < 0) {
    p_Var7 = (_GUID *)&DAT_1002c674;
    pIVar3 = (IUnknown *)FUN_10014380(param_1);
    _com_issue_errorex(local_20,pIVar3,p_Var7);
  }
  FUN_10013700(&local_14,local_24);
  local_8 = 0;
  Ordinal_6(local_24);
  pcVar4 = (char *)FUN_10014460((int *)&DAT_10035424);
  pcVar5 = (char *)FUN_10014400(&local_14);
  iVar6 = FUN_10015d20(pcVar5,pcVar4);
  if (iVar6 == 0) {
    pcVar4 = (char *)FUN_10014400((int *)&DAT_1003546c);
    pcVar5 = (char *)FUN_10014400(&local_14);
    iVar6 = FUN_10015d20(pcVar5,pcVar4);
    if (iVar6 == 0) {
      pcVar4 = (char *)FUN_10014400((int *)&DAT_10035478);
      pcVar5 = (char *)FUN_10014400(&local_14);
      iVar6 = FUN_10015d20(pcVar5,pcVar4);
      if (iVar6 == 0) {
        FUN_10019a70((int)this + 0x54,(uchar *)"CIAuditTrail.cpp");
      }
      else {
        local_18 = 2;
      }
    }
    else {
      local_18 = 1;
    }
  }
  else {
    local_18 = 0;
  }
  uVar1 = local_18;
  local_8 = 0xffffffff;
  FUN_100032d0(&local_14);
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_1000fb20 at 1000fb20

int FUN_1000fb20(void)

{
  int *piVar1;
  undefined4 uVar2;
  IUnknown *pIVar3;
  undefined4 *puVar4;
  _GUID *p_Var5;
  double local_94;
  double local_8c;
  int local_84;
  int local_80;
  double local_7c;
  int *local_74;
  int *local_70;
  int *local_6c;
  long local_68;
  int *local_64;
  int local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  int local_50;
  long local_4c;
  int local_48;
  long local_44;
  long local_40;
  double local_3c;
  int local_34;
  int local_30;
  int local_2c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_28 [4];
  short local_24;
  int local_20;
  short local_1c;
  char local_15;
  short local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100234e3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_48 = 0;
  local_50 = 0;
  local_1c = 0;
  FUN_10013290((undefined4 *)local_28);
  local_8 = 0;
  FUN_100131f0(&local_2c);
  local_8._0_1_ = 1;
  local_6c = (int *)FUN_100145b0((int *)(local_20 + 0x44));
  piVar1 = FID_conflict_operator_((int *)local_28);
  local_74 = FUN_10002650(&local_84,"ConfigFile._ECM_Run_Time");
  local_8._0_1_ = 2;
  local_70 = local_74;
  uVar2 = FUN_10014430(local_74);
  local_60 = (**(code **)(*local_6c + 0x30))(local_6c,0,uVar2,piVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100032d0(&local_84);
  if (local_60 < 0) {
    p_Var5 = (_GUID *)&DAT_1002c674;
    pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)(local_20 + 0x44));
    _com_issue_errorex(local_60,pIVar3,p_Var5);
  }
  FUN_10012580(&local_2c,local_28);
  local_5c = (int *)FUN_10014550(&local_2c);
  local_4c = (**(code **)(*local_5c + 0x38))(local_5c,3);
  if (local_4c < 0) {
    p_Var5 = (_GUID *)&DAT_1002c6c4;
    pIVar3 = (IUnknown *)FUN_10014360(&local_2c);
    _com_issue_errorex(local_4c,pIVar3,p_Var5);
  }
  FUN_10011f40(&local_34,local_28);
  local_8 = CONCAT31(local_8._1_3_,3);
  local_7c = 0.0;
  local_64 = (int *)FUN_10014610(&local_34);
  local_40 = (**(code **)(*local_64 + 0x28))(local_64,&local_7c);
  if (local_40 < 0) {
    p_Var5 = (_GUID *)&DAT_1002c6e4;
    pIVar3 = (IUnknown *)FUN_100143a0(&local_34);
    _com_issue_errorex(local_40,pIVar3,p_Var5);
  }
  local_8c = local_7c;
  local_94 = 0.0;
  local_24 = 0;
  local_15 = '\x01';
  local_58 = (int *)FUN_10014640((int *)(local_20 + 0x60));
  local_68 = (**(code **)(*local_58 + 0x20))(local_58,&local_50);
  if (local_68 < 0) {
    p_Var5 = (_GUID *)&DAT_1002c6f4;
    pIVar3 = (IUnknown *)FUN_100143b0((undefined4 *)(local_20 + 0x60));
    _com_issue_errorex(local_68,pIVar3,p_Var5);
  }
  while (local_14 < local_50) {
    puVar4 = (undefined4 *)FUN_10010240((int)local_14);
    FUN_10012260(&local_30,puVar4);
    local_8 = CONCAT31(local_8._1_3_,4);
    local_54 = (int *)FUN_100144c0(&local_30);
    local_44 = (**(code **)(*local_54 + 0x28))(local_54,&local_48);
    if (local_44 < 0) {
      p_Var5 = (_GUID *)&DAT_10029d44;
      pIVar3 = (IUnknown *)FUN_10014330(&local_30);
      _com_issue_errorex(local_44,pIVar3,p_Var5);
    }
    local_3c = local_7c - (double)local_48;
    if ((local_8c <= local_3c) || (local_3c <= 0.0)) {
      if ((local_3c < 0.0) && (local_3c < local_94)) {
        local_24 = local_14;
        local_94 = local_3c;
      }
    }
    else {
      local_1c = local_14;
      local_15 = '\0';
      local_8c = local_3c;
    }
    local_14 = local_14 + 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_100139c0(&local_30);
  }
  if (local_15 != '\0') {
    local_1c = local_24;
  }
  local_80 = (int)local_1c;
  local_8._0_1_ = 1;
  FUN_10013aa0(&local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013a20(&local_2c);
  local_8 = 0xffffffff;
  FUN_10013a80((int *)local_28);
  ExceptionList = local_10;
  return local_80;
}



// Function: FUN_1000fe60 at 1000fe60

void __fastcall FUN_1000fe60(int param_1)

{
  bool bVar1;
  uint uVar2;
  IUnknown *pIVar3;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *prVar4;
  int iVar5;
  _GUID *p_Var6;
  int iVar7;
  undefined1 local_b4 [8];
  void *local_ac;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  uint local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_74;
  void *local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  int *local_54;
  void *local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  int *local_38;
  long local_34;
  long local_30;
  long local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  void *local_1c;
  int local_18;
  ushort local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023535;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = 0;
  local_18 = param_1;
  bVar1 = FUN_100140b0((void *)(param_1 + 0x60),0);
  if (bVar1) {
    FUN_10014df0((void *)(local_18 + 0x60),(IID *)&DAT_1002b7d4,(LPUNKNOWN)0x0,0x17);
  }
  else {
    local_54 = (int *)FUN_10014640((int *)(local_18 + 0x60));
    local_2c = (**(code **)(*local_54 + 0x20))();
    if (local_2c < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6f4;
      pIVar3 = (IUnknown *)FUN_100143b0((undefined4 *)(local_18 + 0x60));
      _com_issue_errorex(local_2c,pIVar3,p_Var6);
    }
  }
  local_58 = FUN_1000f850();
  for (local_14 = 0; (int)(uint)local_14 < local_58; local_14 = local_14 + 1) {
    if ((int)(uint)local_14 < local_20) {
      local_50 = (void *)0x0;
      local_50 = (void *)FUN_10010240((uint)local_14);
      iVar5 = *(int *)(local_18 + 0x50);
      uVar2 = (uint)local_14;
      iVar7 = iVar5;
      local_84 = boost::exception_detail::
                 refcount_ptr<struct_boost::exception_detail::error_info_container>::
                 refcount_ptr<struct_boost::exception_detail::error_info_container>
                           ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                            &stack0xffffff2c,
                            (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                            (local_18 + 0x44));
      local_8 = 0xffffffff;
      CCIAuditTrailRecord_Initialize(local_50,iVar5,uVar2,iVar7);
    }
    else {
      local_1c = (void *)0x0;
      FUN_10014bc0(&local_1c);
      iVar5 = *(int *)(local_18 + 0x50);
      uVar2 = (uint)local_14;
      prVar4 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               (local_18 + 0x44);
      local_5c = boost::exception_detail::
                 refcount_ptr<struct_boost::exception_detail::error_info_container>::
                 refcount_ptr<struct_boost::exception_detail::error_info_container>
                           ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                            &stack0xffffff2c,prVar4);
      local_8 = 0xffffffff;
      CCIAuditTrailRecord_Initialize(local_1c,prVar4,uVar2,iVar5);
      FUN_100134d0(&local_a4,local_1c);
      local_8 = 1;
      local_6c = local_a4;
      local_68 = local_a0;
      local_64 = local_9c;
      local_60 = local_98;
      local_24 = (int *)FUN_10014640((int *)(local_18 + 0x60));
      local_34 = (**(code **)(*local_24 + 0x28))(local_24,local_6c);
      if (local_34 < 0) {
        p_Var6 = (_GUID *)&DAT_1002c6f4;
        pIVar3 = (IUnknown *)FUN_100143b0((undefined4 *)(local_18 + 0x60));
        _com_issue_errorex(local_34,pIVar3,p_Var6);
      }
      local_8 = 0xffffffff;
      FUN_10013d20(&local_a4);
    }
  }
  for (; (int)(uint)local_14 < local_20; local_14 = local_14 + 1) {
    FUN_10013860(local_b4);
    local_8 = 3;
    FUN_10013860(&local_48);
    local_8 = CONCAT31(local_8._1_3_,4);
    local_48 = CONCAT22(local_48._2_2_,3);
    local_78 = (uint)local_14;
    local_80 = local_48;
    local_7c = local_44;
    local_74 = local_3c;
    local_40 = local_78;
    local_28 = (int *)FUN_10014640((int *)(local_18 + 0x60));
    local_30 = (**(code **)(*local_28 + 0x24))(local_28,local_80,local_7c);
    if (local_30 < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6f4;
      pIVar3 = (IUnknown *)FUN_100143b0((undefined4 *)(local_18 + 0x60));
      _com_issue_errorex(local_30,pIVar3,p_Var6);
    }
    local_70 = local_ac;
    FUN_10017f80(local_ac,0);
    local_94 = local_48;
    local_90 = local_44;
    local_8c = local_40;
    local_88 = local_3c;
    local_38 = (int *)FUN_10014640((int *)(local_18 + 0x60));
    local_4c = (**(code **)(*local_38 + 0x30))
                         (local_38,local_94,local_90,local_8c,local_88,local_b4);
    if (local_4c < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6f4;
      pIVar3 = (IUnknown *)FUN_100143b0((undefined4 *)(local_18 + 0x60));
      _com_issue_errorex(local_4c,pIVar3,p_Var6);
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_10013df0(&local_48);
    local_8 = 0xffffffff;
    FUN_10013df0(local_b4);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010240 at 10010240

undefined4 FUN_10010240(undefined4 param_1)

{
  uint uVar1;
  IUnknown *pIVar2;
  undefined4 *puVar3;
  _GUID *p_Var4;
  short local_58 [8];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  long local_20;
  int local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002356b;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100131b0(&local_14);
  local_8 = 0;
  local_24 = 0;
  FUN_10013860(&local_48);
  local_8._0_1_ = 1;
  FUN_10013860(local_58);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_48 = CONCAT22(local_48._2_2_,3);
  local_40 = param_1;
  local_38 = local_48;
  local_34 = local_44;
  local_30 = param_1;
  local_2c = local_3c;
  local_18 = (int *)FUN_10014640((int *)(local_1c + 0x60));
  local_20 = (**(code **)(*local_18 + 0x24))
                       (local_18,local_38,local_34,local_30,local_2c,local_58,uVar1);
  if (local_20 < 0) {
    p_Var4 = (_GUID *)&DAT_1002c6f4;
    pIVar2 = (IUnknown *)FUN_100143b0((undefined4 *)(local_1c + 0x60));
    _com_issue_errorex(local_20,pIVar2,p_Var4);
  }
  if (local_58[0] == 9) {
    FUN_10013e10(&local_14,local_58);
  }
  else {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  puVar3 = (undefined4 *)FUN_100152a0(&local_14);
  local_28 = *puVar3;
  local_8._0_1_ = 1;
  local_24 = local_28;
  FUN_10013df0(local_58);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013df0(&local_48);
  local_8 = 0xffffffff;
  FUN_100139c0(&local_14);
  ExceptionList = local_10;
  return local_28;
}



// Function: FUN_100103b0 at 100103b0

void __thiscall
FUN_100103b0(void *this,short *param_1,int param_2,int *param_3,int param_4,undefined1 *param_5)

{
  char cVar1;
  bool bVar2;
  LPCSTR pCVar3;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  char local_2d;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2c [24];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002359e;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  basic_string<>(local_2c);
  local_8 = 0;
  local_34 = 0;
  FUN_100137a0(&local_40);
  local_8._0_1_ = 1;
  FUN_100137a0(&local_44);
  local_8 = CONCAT31(local_8._1_3_,2);
  cVar1 = FUN_1001ccf0(param_1,4,local_2c);
  if (cVar1 == '\0') {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  pCVar3 = (LPCSTR)FUN_10015c50((_String_val<struct_std::_Simple_types<char>_> *)local_2c);
  FUN_10013e90(&local_44,pCVar3);
  local_34 = local_34 + 4;
  cVar1 = FUN_1001ccf0((short *)((int)param_1 + local_34),6,local_2c);
  if (cVar1 == '\0') {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  pCVar3 = (LPCSTR)FUN_10015c50((_String_val<struct_std::_Simple_types<char>_> *)local_2c);
  FUN_10013e90(&local_40,pCVar3);
  local_34 = local_34 + 6;
  local_38 = *(uint *)((int)param_1 + local_34);
  local_38 = FUN_1001d980(local_38,4,1,0,2);
  if (4294967295.0 <
      (double)(int)local_38 + *(double *)(&DAT_1002c7b0 + ((int)local_38 >> 0x1f) * -8)) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  local_3c = (int)(((double)(int)local_38 +
                   *(double *)(&DAT_1002c7b0 + ((int)local_38 >> 0x1f) * -8)) * 0.2);
  if ((4294967295.0 < (double)local_3c) || (local_3c < 0)) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  local_2d = '\0';
  bVar2 = FUN_100141b0(&local_40,(int *)((int)this + 0x48));
  if (((bVar2) && (bVar2 = FUN_100141b0(&local_44,(int *)((int)this + 0x4c)), bVar2)) &&
     (param_2 - local_3c < 0x4b0)) {
    local_2d = '\x01';
  }
  if (local_2d == '\0') {
    if (*param_3 == param_4 + -1) {
      *param_3 = 0;
    }
    else {
      *param_3 = *param_3 + 1;
    }
    *param_5 = 1;
  }
  local_8._0_1_ = 1;
  FUN_100032d0(&local_44);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100032d0(&local_40);
  local_8 = 0xffffffff;
  ~basic_string<>(local_2c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: CCIAuditTrail_UpdateChangeCodeBits at 10010660

void __thiscall CCIAuditTrail_UpdateChangeCodeBits(void *this,short *param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  IUnknown *pIVar4;
  uint uVar5;
  undefined4 uVar6;
  ushort in_FPUControlWord;
  float10 fVar7;
  _GUID *p_Var8;
  uint uStack_1c0;
  double local_18c;
  int local_184;
  uint local_180;
  uint local_17c;
  int *local_178;
  int *local_174;
  int local_170;
  long local_16c;
  int local_168;
  long local_164;
  long local_160;
  int *local_15c;
  int *local_158;
  int local_154;
  uint local_150;
  int local_14c;
  int local_148;
  int local_144;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_140 [4];
  short local_13c;
  short local_138;
  int local_134;
  uint local_12c;
  byte local_125;
  void *local_124;
  short local_120;
  byte local_119;
  char local_118 [256];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023605;
  local_10 = ExceptionList;
  uStack_1c0 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1c0;
  ExceptionList = &local_10;
  local_134 = 0;
  local_8 = 0;
  local_150 = 0;
  local_148 = 0;
  local_124 = this;
  local_18 = uStack_1c0;
  puVar1 = &uStack_1c0;
  if (*param_1 != 1) {
    FUN_10019a70((int)this + 0x54,(uchar *)"CIAuditTrail.cpp");
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  if ((param_1[1] & 0x100U) == 0) {
    FUN_10019a70((int)local_124 + 0x54,(uchar *)"CIAuditTrail.cpp");
  }
  local_150 = *(uint *)(param_1 + 8);
  if (*param_3 < (int)local_150) {
    FUN_10019a70((int)local_124 + 0x54,(uchar *)"CIAuditTrail.cpp");
  }
  local_134 = Ordinal_21(param_1);
  if (local_134 < 0) {
    FUN_10019a70((int)local_124 + 0x54,(uchar *)"CIAuditTrail.cpp");
  }
  Ordinal_23(param_1,&local_148);
  FUN_10013290((undefined4 *)local_140);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_158 = (int *)FUN_100145b0((int *)((int)local_124 + 0x44));
  piVar2 = FID_conflict_operator_((int *)local_140);
  uVar3 = FUN_10014430((int *)&DAT_10035438);
  local_16c = (**(code **)(*local_158 + 0x30))(local_158,0,uVar3,piVar2);
  if (local_16c < 0) {
    p_Var8 = (_GUID *)&DAT_1002c674;
    pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_124 + 0x44));
    _com_issue_errorex(local_16c,pIVar4,p_Var8);
  }
  FUN_10011e00(&local_14c,local_140);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_178 = (int *)FUN_10014550(&local_14c);
  local_164 = (**(code **)(*local_178 + 0x38))(local_178,1);
  if (local_164 < 0) {
    p_Var8 = (_GUID *)&DAT_1002c6c4;
    pIVar4 = (IUnknown *)FUN_10014360(&local_14c);
    _com_issue_errorex(local_164,pIVar4,p_Var8);
  }
  FUN_10011f40(&local_144,local_140);
  local_8._0_1_ = 3;
  for (local_12c = 0; local_12c < local_150; local_12c = local_12c + 1) {
    FUN_10013700(&local_170,*(int *)(local_148 + local_12c * 4));
    local_8._0_1_ = 4;
    local_174 = (int *)FUN_10014610(&local_144);
    uVar3 = FUN_10014430(&local_170);
    piVar2 = local_174;
    local_134 = (**(code **)(*local_174 + 0x1c))();
    if (local_134 < 0) {
      FUN_10013700(&local_168,*(int *)(local_148 + local_12c * 4));
      local_8._0_1_ = 5;
      uVar6 = FUN_10014400(&local_168);
      sprintf(local_118,"Unable to get the entity with name %s.",uVar6,piVar2,uVar3);
      FUN_10019ce0(0x65,0x20,local_118,"CCIAuditTrail::UpdateChangeCodeBits ()",2,(IID *)0x0,
                   "CIAuditTrail.cpp",0x54c);
      Ordinal_24(param_1);
      _com_issue_error(local_134);
      local_8._0_1_ = 4;
      FUN_100032d0(&local_168);
    }
    else {
      local_18c = 0.0;
      local_15c = (int *)FUN_10014610(&local_144);
      local_160 = (**(code **)(*local_15c + 0x28))(local_15c,&local_18c);
      if (local_160 < 0) {
        p_Var8 = (_GUID *)&DAT_1002c6e4;
        pIVar4 = (IUnknown *)FUN_100143a0(&local_144);
        _com_issue_errorex(local_160,pIVar4,p_Var8);
      }
      local_138 = (short)(int)local_18c;
      local_13c = (short)((int)((int)local_138 + ((int)local_138 >> 0x1f & 7U)) >> 3);
      uVar5 = (int)local_138 & 0x80000007;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
      }
      local_119 = *(byte *)(param_2 + local_13c);
      local_120 = 7 - (short)uVar5;
      fVar7 = (float10)FUN_10015ce0(2.0,(int)local_120);
      local_17c = in_FPUControlWord | 0xc00;
      local_184 = (int)ROUND(fVar7);
      local_125 = (byte)local_184;
      local_180 = in_FPUControlWord | 0xc00;
      local_154 = 1 << ((byte)local_120 & 0x1f);
      local_119 = local_119 & ~(byte)local_184 | (byte)local_154;
      *(byte *)(param_2 + local_13c) = local_119;
    }
    local_8._0_1_ = 3;
    FUN_100032d0(&local_170);
  }
  Ordinal_24(param_1);
  local_8._0_1_ = 2;
  FUN_10013aa0(&local_144);
  local_8._0_1_ = 1;
  FUN_10013a20(&local_14c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013a80((int *)local_140);
  FUN_10010cd5();
  return;
}



// Function: Catch@10010c14 at 10010c14

undefined * Catch_10010c14(void)

{
  int unaff_EBP;
  
  throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x194),"CIAuditTrail.cpp",0x553,
               "CCIAuditTrail::UpdateChangeCodeBits",0x4e49871fa8790e8a,0xb5781805b4255ea5);
  return &DAT_10010ce9;
}



// Function: Catch@10010c62 at 10010c62

undefined * Catch_10010c62(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x1ac),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  throwExceptionWithFileInfo((void *)(unaff_EBP + -0x1ac),"CIAuditTrail.cpp",0x553,
               "CCIAuditTrail::UpdateChangeCodeBits",0x4e49871fa8790e8a,0xb5781805b4255ea5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uStack0000001c = 0x10010ccf;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1ac));
  return &DAT_10010cde;
}



// Function: FUN_10010cd5 at 10010cd5

void FUN_10010cd5(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10010d08;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CCIAuditTrail_UpdateChangeCodeBits at 10010d10

uint CCIAuditTrail_UpdateChangeCodeBits(double *param_1)

{
  ushort in_FPUControlWord;
  double dVar1;
  double dVar2;
  uint local_74;
  uint local_6c;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  
  if ((4294967295.0 < *param_1) || (*param_1 <= 0.0 && *param_1 != 0.0)) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  dVar1 = (*param_1 - 0.0) / 0.2;
  if ((4294967295.0 < dVar1) || (dVar1 < 0.0)) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  dVar2 = floor(dVar1);
  if (dVar1 - dVar2 <= 0.5) {
    dVar1 = floor(dVar1);
    local_1c = in_FPUControlWord | 0xc00;
    local_74 = (uint)(longlong)ROUND(dVar1);
    local_c = local_74;
  }
  else {
    dVar1 = ceil(dVar1);
    local_18 = in_FPUControlWord | 0xc00;
    local_6c = (uint)(longlong)ROUND(dVar1);
    local_c = local_6c;
  }
  local_10 = local_c;
  dVar1 = (double)(int)local_c + *(double *)(&DAT_1002c7b0 + ((int)local_c >> 0x1f) * -8);
  if ((4294967295.0 < dVar1) || (dVar1 < 0.0)) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  dVar1 = dVar1 * 0.2 + 0.0;
  if ((4294967295.0 < dVar1) || (dVar1 < 0.0)) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  local_14 = (int *)FUN_100145b0((int *)(local_20 + 0x44));
  (**(code **)(*local_14 + 0x48))(local_14,&local_24);
  if (local_24 != 2) {
    local_c = FUN_1001d980(local_c,4,1,0,2);
  }
  return local_c;
}



// Function: FUN_10010f70 at 10010f70

int FUN_10010f70(void *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  IUnknown *pIVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  ushort in_FPUControlWord;
  _GUID *p_Var7;
  undefined1 *puVar8;
  undefined4 local_134 [4];
  undefined4 local_124 [4];
  undefined4 local_114 [10];
  undefined4 local_ec [10];
  undefined1 local_c4 [16];
  longlong local_b4;
  undefined1 local_ac [16];
  double local_9c;
  uint local_94;
  int local_90;
  uint local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  int local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  int *local_64;
  uint local_60;
  void *local_5c;
  int *local_58;
  long local_54;
  long local_50;
  int *local_4c;
  long local_48;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c [2];
  int local_24;
  int local_20;
  int local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023661;
  local_10 = ExceptionList;
  uVar2 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 0;
  FUN_10013320(&local_1c);
  local_8 = 0;
  local_64 = (int *)FUN_100145b0((int *)(local_24 + 0x44));
  piVar3 = FID_conflict_operator_(&local_1c);
  local_48 = (**(code **)(*local_64 + 0x20))(local_64,piVar3,uVar2);
  if (local_48 < 0) {
    p_Var7 = (_GUID *)&DAT_1002c674;
    pIVar4 = (IUnknown *)FUN_10014380((undefined4 *)(local_24 + 0x44));
    _com_issue_errorex(local_48,pIVar4,p_Var7);
  }
  bVar1 = FUN_100141b0(param_1,(int *)&DAT_1003548c);
  if (!bVar1) {
    bVar1 = FUN_100141b0(param_1,(int *)&DAT_10035420);
    if (!bVar1) {
      local_84 = 0x403a;
      FUN_10013860(local_ac);
      local_8 = CONCAT31(local_8._1_3_,3);
      local_4c = (int *)FUN_100146a0(&local_1c);
      puVar8 = local_ac;
      uVar5 = FUN_10014380((undefined4 *)(local_24 + 0x44));
      local_54 = (**(code **)(*local_4c + 0x24))(local_4c,3,local_84,0,4,0,0,uVar5,puVar8);
      if (local_54 < 0) {
        p_Var7 = (_GUID *)&DAT_1002c694;
        pIVar4 = (IUnknown *)FUN_100143c0(&local_1c);
        _com_issue_errorex(local_54,pIVar4,p_Var7);
      }
      puVar6 = Detach(local_ac,local_134);
      FUN_1001d260(local_ec,(short)*puVar6,puVar6[1],(short *)puVar6[2]);
      local_8._0_1_ = 4;
      local_5c = (void *)0x0;
      FUN_1001d480(local_ec,&local_5c);
      local_2c[0] = 0;
      memcpy(local_2c,local_5c,4);
      local_40 = local_2c[0];
      local_9c = ((double)local_2c[0] + *(double *)(&DAT_1002c7b0 + (local_2c[0] >> 0x1f) * -8)) *
                 0.131;
      local_6c = in_FPUControlWord | 0xc00;
      local_b4 = (longlong)ROUND(local_9c);
      local_2c[0] = (int)local_b4;
      local_20 = (int)local_b4;
      local_8._0_1_ = 3;
      FUN_1001d3a0(local_ec);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10013df0(local_ac);
      goto LAB_100113d6;
    }
  }
  local_80 = 4;
  FUN_10013860(local_c4);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_58 = (int *)FUN_100146a0(&local_1c);
  puVar8 = local_c4;
  uVar5 = FUN_10014380((undefined4 *)(local_24 + 0x44));
  local_50 = (**(code **)(*local_58 + 0x24))(local_58,3,local_80,0,10,0,0,uVar5,puVar8);
  if (local_50 < 0) {
    p_Var7 = (_GUID *)&DAT_1002c694;
    pIVar4 = (IUnknown *)FUN_100143c0(&local_1c);
    _com_issue_errorex(local_50,pIVar4,p_Var7);
  }
  puVar6 = Detach(local_c4,local_124);
  FUN_1001d260(local_114,(short)*puVar6,puVar6[1],(short *)puVar6[2]);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = (void *)0x0;
  FUN_1001d480(local_114,&local_18);
  bVar1 = FUN_100141b0(param_1,(int *)&DAT_10035420);
  if (bVar1) {
    local_60 = 0;
    memcpy(&local_60,(void *)((int)local_18 + 6),4);
    local_70 = local_60 | 0xc0;
    local_8c = ~local_70;
    local_78 = FUN_10011400(&local_8c,4);
    local_94 = local_78 * 6;
    local_68 = local_94 % 0x3c;
    local_90 = local_68 * 0x3c;
    local_14 = 0;
    local_30 = 0;
    local_38 = 0;
    local_34 = 0;
    local_88 = local_90;
    memcpy(&local_30,local_18,2);
    if (local_14 < local_30) {
      local_14 = local_30;
    }
    memcpy(&local_38,(void *)((int)local_18 + 2),2);
    if (local_14 < local_38) {
      local_14 = local_38;
    }
    memcpy(&local_34,(void *)((int)local_18 + 4),2);
    if (local_14 < local_34) {
      local_14 = local_34;
    }
    local_3c = local_14 * 0xe10;
    local_20 = local_88 + local_3c;
  }
  else {
    local_44 = 0;
    memcpy(&local_44,local_18,4);
    local_7c = FUN_1001d980(local_44,4,1,0,2);
    local_20 = local_7c * 0xb4;
  }
  local_8._0_1_ = 1;
  FUN_1001d3a0(local_114);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013df0(local_c4);
LAB_100113d6:
  local_74 = local_20;
  local_8 = 0xffffffff;
  FUN_10013b00(&local_1c);
  ExceptionList = local_10;
  return local_74;
}



// Function: FUN_10011400 at 10011400

int FUN_10011400(void *param_1,int param_2)

{
  int local_14;
  int local_10;
  int local_c;
  byte local_5;
  
  local_14 = 0;
  for (local_10 = 0; local_10 < param_2; local_10 = local_10 + 1) {
    memcpy(&local_5,param_1,1);
    for (local_c = 1; local_c < 9; local_c = local_c + 1) {
      if (((int)(uint)local_5 >> (8U - (char)local_c & 0x1f) & 0x1ffffffU) != 0) {
        local_14 = local_14 + 1;
      }
    }
    param_1 = (void *)((int)param_1 + 1);
  }
  return local_14;
}



// Function: FUN_100114a0 at 100114a0

int FUN_100114a0(void)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  IUnknown *pIVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  _GUID *p_Var8;
  int local_54;
  int local_44;
  long local_40;
  int *local_3c;
  long local_38;
  int *local_34;
  long local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_18 [4];
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100236b7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_10013290((undefined4 *)local_18);
  local_8._0_1_ = 2;
  FUN_100131f0(&local_20);
  local_8._0_1_ = 3;
  FUN_10013370((undefined4 *)local_14);
  local_8 = CONCAT31(local_8._1_3_,4);
  bVar1 = false;
  local_28 = 0;
  local_2c = (int *)FUN_10014700((int *)&stack0x00000004);
  piVar3 = FID_conflict_operator_((int *)local_14);
  local_30 = (**(code **)(*local_2c + 0x34))(local_2c,piVar3);
  if (local_30 < 0) {
    p_Var8 = (_GUID *)&DAT_1002c6a4;
    pIVar4 = (IUnknown *)FUN_100143e0((undefined4 *)&stack0x00000004);
    _com_issue_errorex(local_30,pIVar4,p_Var8);
  }
  do {
    bVar2 = FUN_100142b0(local_14,0);
    if (!bVar2) {
LAB_100116af:
      if (bVar1) {
        local_54 = local_28;
      }
      else {
        local_54 = -1;
      }
      local_8._0_1_ = 3;
      FUN_10013b80((int *)local_14);
      local_8._0_1_ = 2;
      FUN_10013a20(&local_20);
      local_8._0_1_ = 1;
      FUN_10013a80((int *)local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10013b80((int *)&stack0x00000004);
      local_8 = 0xffffffff;
      FUN_10002f00((undefined4 *)&stack0x00000008);
      ExceptionList = local_10;
      return local_54;
    }
    FUN_100126a0(local_18,local_14);
    FUN_10002100(&local_1c);
    local_8 = CONCAT31(local_8._1_3_,5);
    local_34 = (int *)FUN_100145e0((int *)local_18);
    uVar5 = FUN_10003600(&local_1c);
    local_38 = (**(code **)(*local_34 + 0x20))(local_34,uVar5);
    if (local_38 < 0) {
      p_Var8 = (_GUID *)&DAT_1002c6d4;
      pIVar4 = (IUnknown *)FUN_10014390((undefined4 *)local_18);
      _com_issue_errorex(local_38,pIVar4,p_Var8);
    }
    bVar2 = FUN_10014170(&local_1c,(undefined4 *)&stack0x00000008);
    if (bVar2) {
      bVar1 = true;
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_10002f00(&local_1c);
      goto LAB_100116af;
    }
    FUN_10012580(&local_20,local_18);
    local_44 = 0;
    local_3c = (int *)FUN_10014550(&local_20);
    local_40 = (**(code **)(*local_3c + 0x20))(local_3c,&local_44);
    if (local_40 < 0) {
      p_Var8 = (_GUID *)&DAT_1002c6c4;
      pIVar4 = (IUnknown *)FUN_10014360(&local_20);
      _com_issue_errorex(local_40,pIVar4,p_Var8);
    }
    local_28 = local_28 + local_44;
    FUN_10013370(&local_24);
    local_8 = CONCAT31(local_8._1_3_,6);
    piVar3 = (int *)FUN_10014700((int *)local_14);
    piVar6 = FID_conflict_operator_(&local_24);
    iVar7 = (**(code **)(*piVar3 + 0x24))(piVar3,piVar6);
    if (iVar7 < 0) {
      p_Var8 = (_GUID *)&DAT_1002c6a4;
      pIVar4 = (IUnknown *)FUN_100143e0((undefined4 *)local_14);
      _com_issue_errorex(iVar7,pIVar4,p_Var8);
    }
    FUN_10013e50(local_14,&local_24);
    local_8._0_1_ = 5;
    FUN_10013b80(&local_24);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_10002f00(&local_1c);
  } while( true );
}



// Function: FUN_10011720 at 10011720

refcount_ptr<struct_boost::exception_detail::error_info_container> *
FUN_10011720(refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1,int param_2
            )

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  IUnknown *pIVar5;
  undefined4 uVar6;
  _GUID *p_Var7;
  undefined4 uVar8;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100236f3;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar8 = 0;
  FUN_10013290((undefined4 *)local_18);
  local_8 = 1;
  if (param_2 == 0) {
    piVar2 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
    piVar3 = FID_conflict_operator_((int *)local_18);
    uVar8 = FUN_10014430((int *)&DAT_1003548c);
    iVar4 = (**(code **)(*piVar2 + 0x30))(piVar2,0,uVar8,piVar3);
    if (iVar4 < 0) {
      piVar2 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
      piVar3 = FID_conflict_operator_((int *)local_18);
      uVar8 = FUN_10014430((int *)&DAT_10035420);
      iVar4 = (**(code **)(*piVar2 + 0x30))(piVar2,0,uVar8,piVar3);
      if (iVar4 < 0) {
        piVar2 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
        piVar3 = FID_conflict_operator_((int *)local_18);
        uVar8 = FUN_10014430((int *)&DAT_10035458);
        iVar4 = (**(code **)(*piVar2 + 0x30))(piVar2,0,uVar8,piVar3);
        if (iVar4 < 0) {
          p_Var7 = (_GUID *)&DAT_1002c674;
          pIVar5 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x44));
          _com_issue_errorex(iVar4,pIVar5,p_Var7);
        }
      }
    }
  }
  else {
    piVar2 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
    piVar3 = FID_conflict_operator_((int *)local_18);
    uVar6 = FUN_10014430((int *)&DAT_10035454);
    iVar4 = (**(code **)(*piVar2 + 0x30))(piVar2,0,uVar6,piVar3,uVar1,uVar8);
    if (iVar4 < 0) {
      p_Var7 = (_GUID *)&DAT_1002c674;
      pIVar5 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x44));
      _com_issue_errorex(iVar4,pIVar5,p_Var7);
    }
  }
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>(param_1,local_18);
  local_8 = local_8 & 0xffffff00;
  FUN_10013a80((int *)local_18);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100118d0 at 100118d0

void __fastcall FUN_100118d0(int param_1)

{
  IUnknown *pIVar1;
  _GUID *p_Var2;
  int local_70;
  undefined4 local_6c;
  int *local_68;
  undefined4 local_64;
  int *local_60;
  int local_5c;
  long local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  long local_48;
  int local_44;
  int *local_40;
  long local_3c;
  long local_38;
  int *local_34;
  int local_30;
  int local_2c;
  int local_28;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_24 [4];
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_20 [4];
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023778;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  FUN_10011e00(&local_1c,
               (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               (param_1 + 0x68));
  local_8 = 0;
  local_28 = 0;
  local_34 = (int *)FUN_10014550(&local_1c);
  local_3c = (**(code **)(*local_34 + 0x20))();
  if (local_3c < 0) {
    p_Var2 = (_GUID *)&DAT_1002c6c4;
    pIVar1 = (IUnknown *)FUN_10014360(&local_1c);
    _com_issue_errorex(local_3c,pIVar1,p_Var2);
  }
  *(int *)(local_14 + 0x80) = local_28;
  FUN_10011fe0(local_24,(refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                        (local_14 + 0x68));
  local_8._0_1_ = 1;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff38,"Records");
  local_8._0_1_ = 2;
  local_64 = boost::exception_detail::
             refcount_ptr<struct_boost::exception_detail::error_info_container>::
             refcount_ptr<struct_boost::exception_detail::error_info_container>
                       ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                        &stack0xffffff34,local_24);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_5c = FUN_100114a0();
  local_18 = local_5c;
  if (local_5c == -1) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  *(int *)(local_14 + 0x70) = local_18;
  local_6c = ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff38,"CurrentRecordIndex");
  local_8._0_1_ = 4;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffff34,
             local_24);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_18 = FUN_100114a0();
  if (local_18 == -1) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  *(int *)(local_14 + 0x6c) = local_18;
  FUN_10013290((undefined4 *)local_20);
  local_8._0_1_ = 6;
  local_4c = (int *)FUN_100145b0((int *)(local_14 + 0x44));
  FID_conflict_operator_((int *)local_20);
  local_68 = FUN_10002650(&local_70,"DataStructures.Audit_Trail.Records[0]");
  local_8._0_1_ = 7;
  local_60 = local_68;
  FUN_10014430(local_68);
  local_44 = (**(code **)(*local_4c + 0x30))();
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_100032d0(&local_70);
  if (local_44 < 0) {
    p_Var2 = (_GUID *)&DAT_1002c674;
    pIVar1 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x44));
    _com_issue_errorex(local_44,pIVar1,p_Var2);
  }
  FUN_10012610(local_24,local_20);
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff28,"_audit_trail_codes");
  local_8._0_1_ = 8;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffff24,
             local_24);
  local_8 = CONCAT31(local_8._1_3_,6);
  local_18 = FUN_100114a0();
  if (local_18 == -1) {
    FUN_1001f090((uchar *)"CIAuditTrail.cpp");
  }
  *(int *)(local_14 + 0x7c) = local_18;
  local_54 = (int *)FUN_100145b0((int *)(local_14 + 0x44));
  FID_conflict_operator_((int *)local_20);
  FUN_10014430((int *)&DAT_10035470);
  local_38 = (**(code **)(*local_54 + 0x30))(local_54,0);
  if (local_38 < 0) {
    p_Var2 = (_GUID *)&DAT_1002c674;
    pIVar1 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x44));
    _com_issue_errorex(local_38,pIVar1,p_Var2);
  }
  FUN_10011ea0(&local_30,local_20);
  local_8 = CONCAT31(local_8._1_3_,10);
  local_2c = 0;
  local_40 = (int *)FUN_10014580(&local_30);
  local_48 = (**(code **)(*local_40 + 0x24))(local_40,&local_2c);
  if (local_48 < 0) {
    p_Var2 = (_GUID *)&DAT_1002c6b4;
    pIVar1 = (IUnknown *)FUN_10014370(&local_30);
    _com_issue_errorex(local_48,pIVar1,p_Var2);
  }
  *(int *)(local_14 + 0x74) = local_2c;
  FUN_10012580(&local_1c,local_20);
  local_50 = (int *)FUN_10014550(&local_1c);
  local_58 = (**(code **)(*local_50 + 0x20))(local_50,&local_28);
  if (local_58 < 0) {
    p_Var2 = (_GUID *)&DAT_1002c6c4;
    pIVar1 = (IUnknown *)FUN_10014360(&local_1c);
    _com_issue_errorex(local_58,pIVar1,p_Var2);
  }
  *(int *)(local_14 + 0x78) = local_28 / local_2c;
  local_8._0_1_ = 6;
  FUN_10013a40(&local_30);
  local_8._0_1_ = 1;
  FUN_10013a80((int *)local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013b80((int *)local_24);
  local_8 = 0xffffffff;
  FUN_10013a20(&local_1c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011d00 at 10011d00

int FUN_10011d00(int param_1,int param_2)

{
  if (param_1 == 0) {
    param_1 = param_2 + -1;
  }
  else {
    param_1 = param_1 + -1;
  }
  return param_1;
}



// Function: FUN_10011d30 at 10011d30

int FUN_10011d30(int param_1,int param_2)

{
  if (param_1 == param_2 + -1) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + 1;
  }
  return param_1;
}



// Function: FUN_10011d60 at 10011d60

undefined4 * __thiscall
FUN_10011d60(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100237a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012930();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011e00 at 10011e00

undefined4 * __thiscall
FUN_10011e00(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100237d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012a00();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011ea0 at 10011ea0

undefined4 * __thiscall
FUN_10011ea0(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012ad0();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011f40 at 10011f40

undefined4 * __thiscall
FUN_10011f40(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023838;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012ba0();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10011fe0 at 10011fe0

undefined4 * __thiscall
FUN_10011fe0(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023868;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012c70();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012080 at 10012080

undefined4 * __thiscall
FUN_10012080(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023898;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012d40();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012120 at 10012120

undefined4 * __thiscall
FUN_10012120(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100238c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012e10();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100121c0 at 100121c0

undefined4 * __thiscall
FUN_100121c0(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100238f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012fb0();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10012260 at 10012260

undefined4 * __thiscall FUN_10012260(void *this,undefined4 *param_1)

{
  int iVar1;
  
  *(undefined4 *)this = 0;
  iVar1 = FUN_100128c0(this,param_1);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  return (undefined4 *)this;
}



// Function: FID_conflict:operator= at 100122b0

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_100156c0((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 10012300

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_100156f0((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 10012350

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_10015720((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 100123a0

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_10015750((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 100123f0

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_10015780((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 10012440

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_100157b0((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 10012490

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_100157e0((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 100124e0

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_10015810((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 10012530

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_10015840((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_10012580 at 10012580

void * __thiscall
FUN_10012580(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023928;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012a00();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10012610 at 10012610

void * __thiscall
FUN_10012610(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023958;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012c70();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100126a0 at 100126a0

void * __thiscall
FUN_100126a0(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023988;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012ee0();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10012730 at 10012730

void __cdecl FUN_10012730(int param_1,void *param_2)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
  FUN_100141f0(param_2,0);
  return;
}



// Function: FUN_10012750 at 10012750

float10 __cdecl FUN_10012750(double param_1,uint param_2)

{
  undefined8 local_18;
  undefined8 local_10;
  undefined4 local_8;
  
  if ((int)param_2 < 0) {
    local_8 = -param_2;
  }
  else {
    local_8 = param_2;
  }
  local_10 = 1.0;
  while( true ) {
    if ((local_8 & 1) != 0) {
      local_10 = local_10 * param_1;
    }
    local_8 = local_8 >> 1;
    if (local_8 == 0) break;
    param_1 = param_1 * param_1;
  }
  if ((int)param_2 < 0) {
    local_18 = 1.0 / local_10;
  }
  else {
    local_18 = local_10;
  }
  return (float10)local_18;
}



// Function: FUN_100127e0 at 100127e0

int __thiscall FUN_100127e0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int local_14;
  void *local_10;
  int local_c;
  int local_8;
  
  local_10 = this;
  if (param_1 == (undefined4 *)0x0) {
    FID_conflict_operator_(this,0);
    local_8 = -0x7fffbffe;
  }
  else {
    piVar2 = &local_14;
    uVar1 = FUN_10015200();
    local_8 = (**(code **)*param_1)(param_1,uVar1,piVar2);
    if (local_8 < 0) {
      local_c = 0;
    }
    else {
      local_c = local_14;
    }
    Attach(local_10,local_c);
  }
  return local_8;
}



// Function: FUN_10012850 at 10012850

int __thiscall FUN_10012850(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int local_14;
  void *local_10;
  int local_c;
  int local_8;
  
  local_10 = this;
  if (param_1 == (undefined4 *)0x0) {
    FID_conflict_operator_(this,0);
    local_8 = -0x7fffbffe;
  }
  else {
    piVar2 = &local_14;
    uVar1 = FUN_10015200();
    local_8 = (**(code **)*param_1)(param_1,uVar1,piVar2);
    if (local_8 < 0) {
      local_c = 0;
    }
    else {
      local_c = local_14;
    }
    Attach(local_10,local_c);
  }
  return local_8;
}



// Function: FUN_100128c0 at 100128c0

int __thiscall FUN_100128c0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int local_14;
  void *local_10;
  int local_c;
  int local_8;
  
  local_10 = this;
  if (param_1 == (undefined4 *)0x0) {
    FID_conflict_operator_(this,0);
    local_8 = -0x7fffbffe;
  }
  else {
    piVar2 = &local_14;
    uVar1 = FUN_10015200();
    local_8 = (**(code **)*param_1)(param_1,uVar1,piVar2);
    if (local_8 < 0) {
      local_c = 0;
    }
    else {
      local_c = local_14;
    }
    Attach(local_10,local_c);
  }
  return local_8;
}



// Function: FUN_10012930 at 10012930

int FUN_10012930(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100239b8;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_10014230(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_100145e0((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015220();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013a80((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012a00 at 10012a00

int FUN_10012a00(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100239e8;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_10014230(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_100145e0((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015230();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013a80((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012ad0 at 10012ad0

int FUN_10012ad0(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023a18;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_10014230(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_100145e0((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015240();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013a80((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012ba0 at 10012ba0

int FUN_10012ba0(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023a48;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_10014230(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_100145e0((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015260();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013a80((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012c70 at 10012c70

int FUN_10012c70(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023a78;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_10014230(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_100145e0((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015290();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013a80((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012d40 at 10012d40

int FUN_10012d40(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023aa8;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_10014270(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_10014610((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015250();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013aa0((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012e10 at 10012e10

int FUN_10012e10(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023ad8;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_10014270(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_10014610((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015290();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013aa0((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012ee0 at 10012ee0

int FUN_10012ee0(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023b08;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_100142b0(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_10014700((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015250();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013b80((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10012fb0 at 10012fb0

int FUN_10012fb0(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023b38;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_100142f0(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_10014730((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015280();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013ba0((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10013080 at 10013080

undefined4 * __fastcall FUN_10013080(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023b68;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10015d40((int)param_1);
  local_8 = 0;
  *param_1 = &PTR_QueryInterface_1002c738;
  (**(code **)(*DAT_10035308 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100130f0 at 100130f0

undefined4 * __thiscall FUN_100130f0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  FUN_10015520((undefined4 *)this);
  return (undefined4 *)this;
}



// Function: FUN_10013120 at 10013120

undefined4 __fastcall FUN_10013120(undefined4 param_1)

{
  FUN_100135e0(param_1);
  return param_1;
}



// Function: FUN_10013140 at 10013140

undefined4 __fastcall FUN_10013140(undefined4 param_1)

{
  FUN_10013600(param_1);
  return param_1;
}



// Function: FUN_10013160 at 10013160

undefined4 * __fastcall FUN_10013160(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023b98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10013300(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100131b0 at 100131b0

undefined4 * __fastcall FUN_100131b0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100131d0 at 100131d0

undefined4 * __fastcall FUN_100131d0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100131f0 at 100131f0

undefined4 * __fastcall FUN_100131f0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 10013210

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_10015780((int *)this);
  return this;
}



// Function: FUN_10013240 at 10013240

undefined4 * __fastcall FUN_10013240(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 10013260

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_100157b0((int *)this);
  return this;
}



// Function: FUN_10013290 at 10013290

undefined4 * __fastcall FUN_10013290(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 100132b0

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_100157e0((int *)this);
  return this;
}



// Function: FUN_100132e0 at 100132e0

undefined4 * __fastcall FUN_100132e0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013300 at 10013300

undefined4 * __fastcall FUN_10013300(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10013320 at 10013320

undefined4 * __fastcall FUN_10013320(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 10013340

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_10015840((int *)this);
  return this;
}



// Function: FUN_10013370 at 10013370

undefined4 * __fastcall FUN_10013370(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 10013390

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_10015870((int *)this);
  return this;
}



// Function: FUN_100133c0 at 100133c0

undefined4 * __fastcall FUN_100133c0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: basic_string<> at 100133e0

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(void)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(void)
   
   Library: Visual Studio 2012 Release */

void * __fastcall basic_string<>(void *param_1)

{
  undefined1 local_5;
  
  allocator<>(&local_5);
  _String_alloc<>((int)param_1);
  FID_conflict__Tidy(param_1,'\0',0);
  return param_1;
}



// Function: FUN_10013410 at 10013410

CComCriticalSection * __fastcall FUN_10013410(CComCriticalSection *param_1)

{
  long lVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023bc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ATL::CComCriticalSection::CComCriticalSection(param_1);
  local_8 = 0;
  lVar1 = ATL::CComCriticalSection::Init(param_1);
  if (lVar1 < 0) {
    FUN_10006230(lVar1);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: CComBSTR at 10013480

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(char const *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,char *param_1)

{
  bool bVar1;
  LPWSTR pWVar2;
  
  if (param_1 == (char *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    pWVar2 = FUN_10014860(param_1,-1);
    *(LPWSTR *)this = pWVar2;
    bVar1 = FUN_100033a0((int *)this);
    if (bVar1) {
      FUN_10006230(0x8007000e);
    }
  }
  return this;
}



// Function: FUN_100134d0 at 100134d0

undefined2 * __thiscall FUN_100134d0(void *this,undefined4 param_1)

{
  *(undefined2 *)this = 9;
  *(undefined4 *)((int)this + 8) = param_1;
  if (*(int *)((int)this + 8) != 0) {
    (**(code **)(**(int **)((int)this + 8) + 4))(*(undefined4 *)((int)this + 8));
  }
  return (undefined2 *)this;
}



// Function: FUN_10013520 at 10013520

int * __thiscall FUN_10013520(void *this,int param_1,char param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  if ((param_2 == '\0') || (param_1 == 0)) {
    *(int *)this = param_1;
  }
  else {
    uVar1 = Ordinal_149(param_1);
    uVar1 = Ordinal_150(param_1,uVar1);
    *(undefined4 *)this = uVar1;
                    /* WARNING: Load size is inaccurate */
    if (*this == 0) {
      _com_issue_error(-0x7ff8fff2);
    }
  }
  return (int *)this;
}



// Function: FUN_10013590 at 10013590

int * __thiscall FUN_10013590(void *this,int param_1)

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



// Function: FUN_100135e0 at 100135e0

undefined4 __fastcall FUN_100135e0(undefined4 param_1)

{
  FUN_10013620(param_1);
  return param_1;
}



// Function: FUN_10013600 at 10013600

undefined4 __fastcall FUN_10013600(undefined4 param_1)

{
  FUN_10013620(param_1);
  return param_1;
}



// Function: FUN_10013620 at 10013620

undefined4 __fastcall FUN_10013620(undefined4 param_1)

{
  FUN_100024c0(param_1);
  return param_1;
}



// Function: FUN_10013640 at 10013640

undefined4 __fastcall FUN_10013640(undefined4 param_1)

{
  FUN_100024c0(param_1);
  return param_1;
}



// Function: FUN_10013660 at 10013660

int * __thiscall FUN_10013660(void *this,int param_1,char param_2)

{
  void *this_00;
  int *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023bfb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = (void *)FUN_10003370(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = FUN_10013520(this_00,param_1,param_2);
  }
  local_8 = 0xffffffff;
  *(int **)this = local_1c;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10013700 at 10013700

int * __thiscall FUN_10013700(void *this,int param_1)

{
  void *this_00;
  int *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023c2b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = (void *)FUN_10003370(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = FUN_10013590(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(int **)this = local_1c;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_100137a0 at 100137a0

undefined4 * __fastcall FUN_100137a0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: _com_error at 100137c0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(long,struct IErrorInfo *,bool)
   
   Library: Visual Studio 2005 Debug */

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



// Function: FUN_10013820 at 10013820

void * __thiscall FUN_10013820(void *this,undefined4 param_1)

{
  int iVar1;
  
  Ordinal_8(this);
  iVar1 = Ordinal_10(this,param_1);
  FUN_10014a90(iVar1);
  return this;
}



// Function: FUN_10013860 at 10013860

undefined4 __fastcall FUN_10013860(undefined4 param_1)

{
  Ordinal_8(param_1);
  return param_1;
}



// Function: FUN_10013880 at 10013880

undefined4 * __fastcall FUN_10013880(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



// Function: FUN_100138d0 at 100138d0

void __fastcall FUN_100138d0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023c58;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = &PTR_QueryInterface_1002c738;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  FUN_10006f00();
  (**(code **)(*DAT_10035308 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10013bc0((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013950 at 10013950

void __fastcall FUN_10013950(undefined4 *param_1)

{
  FUN_10015690(param_1);
  return;
}



// Function: FID_conflict:~bad_alloc at 10013970

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall `anonymous
   namespace'::_ExceptionPtr_normal::~_ExceptionPtr_normal(void)
    public: virtual __thiscall std::bad_alloc::~bad_alloc(void)
    public: virtual __thiscall std::bad_exception::~bad_exception(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall FID_conflict__bad_alloc(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023c88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10013ae0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100139c0 at 100139c0

void __fastcall FUN_100139c0(int *param_1)

{
  FUN_10015950(param_1);
  return;
}



// Function: FUN_100139e0 at 100139e0

void __fastcall FUN_100139e0(int *param_1)

{
  FUN_10015980(param_1);
  return;
}



// Function: FUN_10013a00 at 10013a00

void __fastcall FUN_10013a00(int *param_1)

{
  FUN_100159b0(param_1);
  return;
}



// Function: FUN_10013a20 at 10013a20

void __fastcall FUN_10013a20(int *param_1)

{
  FUN_100159e0(param_1);
  return;
}



// Function: FUN_10013a40 at 10013a40

void __fastcall FUN_10013a40(int *param_1)

{
  FUN_10015a10(param_1);
  return;
}



// Function: FUN_10013a60 at 10013a60

void __fastcall FUN_10013a60(int *param_1)

{
  FUN_10015a40(param_1);
  return;
}



// Function: FUN_10013a80 at 10013a80

void __fastcall FUN_10013a80(int *param_1)

{
  FUN_10015a70(param_1);
  return;
}



// Function: FUN_10013aa0 at 10013aa0

void __fastcall FUN_10013aa0(int *param_1)

{
  FUN_10015aa0(param_1);
  return;
}



// Function: FUN_10013ac0 at 10013ac0

void __fastcall FUN_10013ac0(int *param_1)

{
  FUN_10015ad0(param_1);
  return;
}



// Function: FUN_10013ae0 at 10013ae0

void __fastcall FUN_10013ae0(int *param_1)

{
  FUN_10015b00(param_1);
  return;
}



// Function: FUN_10013b00 at 10013b00

void __fastcall FUN_10013b00(int *param_1)

{
  FUN_10015b30(param_1);
  return;
}



// Function: FUN_10013b20 at 10013b20

void __fastcall FUN_10013b20(int *param_1)

{
  FUN_10015b60(param_1);
  return;
}



// Function: FUN_10013b40 at 10013b40

void __fastcall FUN_10013b40(int *param_1)

{
  FUN_10015b90(param_1);
  return;
}



// Function: FUN_10013b60 at 10013b60

void __fastcall FUN_10013b60(int *param_1)

{
  FUN_10015bc0(param_1);
  return;
}



// Function: FUN_10013b80 at 10013b80

void __fastcall FUN_10013b80(int *param_1)

{
  FUN_10015bf0(param_1);
  return;
}



// Function: FUN_10013ba0 at 10013ba0

void __fastcall FUN_10013ba0(int *param_1)

{
  FUN_10015c20(param_1);
  return;
}



// Function: FUN_10013bc0 at 10013bc0

void __fastcall FUN_10013bc0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023d34;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._0_1_ = 10;
  local_8._1_3_ = 0;
  FUN_10013a80((int *)(param_1 + 100));
  local_8._0_1_ = 9;
  ~_ExceptionPtr_static<>((int *)(param_1 + 0x50));
  local_8._0_1_ = 8;
  FUN_10013aa0((int *)(param_1 + 0x44));
  local_8._0_1_ = 7;
  FUN_10013a80((int *)(param_1 + 0x40));
  local_8._0_1_ = 6;
  FUN_10013a80((int *)(param_1 + 0x3c));
  local_8._0_1_ = 5;
  FUN_10013a80((int *)(param_1 + 0x38));
  local_8._0_1_ = 4;
  FUN_10013a80((int *)(param_1 + 0x34));
  local_8._0_1_ = 3;
  FUN_10013a80((int *)(param_1 + 0x30));
  local_8._0_1_ = 2;
  FUN_10013a80((int *)(param_1 + 0x2c));
  local_8._0_1_ = 1;
  FUN_10013a80((int *)(param_1 + 0x28));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013a60((int *)(param_1 + 0x24));
  local_8 = 0xffffffff;
  ~_ExceptionPtr_static<>(param_1 + 4);
  ExceptionList = local_10;
  return;
}



// Function: FID_conflict:~CAtlWinModule at 10013cc0

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CAtlWinModule::~CAtlWinModule(void)
    public: __thiscall CPaneContainerGC::~CPaneContainerGC(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2010 Debug */

void __fastcall FID_conflict__CAtlWinModule(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023d58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000ac70(param_1);
  local_8 = 0xffffffff;
  FUN_10002f80();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013d20 at 10013d20

void __fastcall FUN_10013d20(undefined4 param_1)

{
  FUN_10014ab0(param_1);
  return;
}



// Function: ~_ExceptionPtr_static<> at 10013d40

/* Library Function - Multiple Matches With Same Base Name
    public: virtual __thiscall `anonymous namespace'::_ExceptionPtr_static<class
   std::bad_alloc>::~_ExceptionPtr_static<class std::bad_alloc>(void)
    public: virtual __thiscall `anonymous namespace'::_ExceptionPtr_static<class
   std::bad_exception>::~_ExceptionPtr_static<class std::bad_exception>(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __fastcall ~_ExceptionPtr_static<>(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10023d93;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10013b20(param_1 + 1);
  local_8 = 0xffffffff;
  FUN_10013b40(param_1);
  ExceptionList = local_10;
  return;
}



// Function: ~_com_error at 10013da0

/* Library Function - Single Match
    public: virtual __thiscall _com_error::~_com_error(void)
   
   Library: Visual Studio 2005 Debug */

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



// Function: FUN_10013df0 at 10013df0

void __fastcall FUN_10013df0(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10013e10 at 10013e10

void * __thiscall FUN_10013e10(void *this,short *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10015570(this,param_1);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  return this;
}



// Function: FUN_10013e50 at 10013e50

void __thiscall FUN_10013e50(void *this,int *param_1)

{
  FID_conflict_operator_(this,*param_1);
  return;
}



// Function: operator= at 10013e70

/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::operator=(char const *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          char *param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  
  pbVar1 = assign(this,param_1);
  return pbVar1;
}



// Function: FUN_10013e90 at 10013e90

int * __thiscall FUN_10013e90(void *this,LPCSTR param_1)

{
  LPCSTR pCVar1;
  void *this_00;
  undefined4 *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023dbb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 != (LPCSTR)0x0) && (pCVar1 = (LPCSTR)FUN_10014460((int *)this), pCVar1 == param_1)) {
    ExceptionList = local_10;
    return (int *)this;
  }
  Clear((int *)this);
  this_00 = (void *)FUN_10003370(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_1c = (undefined4 *)0x0;
  }
  else {
    local_1c = FUN_10002440(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(undefined4 **)this = local_1c;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10013f40 at 10013f40

int * __thiscall FUN_10013f40(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  int *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023deb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 != 0) && (iVar1 = FUN_10014490((int *)this), iVar1 == param_1)) {
    ExceptionList = local_10;
    return (int *)this;
  }
  Clear((int *)this);
  this_00 = (void *)FUN_10003370(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = FUN_10013590(this_00,param_1);
  }
  local_8 = 0xffffffff;
  *(int **)this = local_1c;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_10013ff0 at 10013ff0

bool __thiscall FUN_10013ff0(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_10014030 at 10014030

bool __thiscall FUN_10014030(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_10014070 at 10014070

bool __thiscall FUN_10014070(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_100140b0 at 100140b0

bool __thiscall FUN_100140b0(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_100140f0 at 100140f0

bool __thiscall FUN_100140f0(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_10014130 at 10014130

bool __thiscall FUN_10014130(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_10014170 at 10014170

bool __thiscall FUN_10014170(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_314(*this,*param_1,0x400,0);
  return iVar1 == 1;
}



// Function: FUN_100141b0 at 100141b0

bool __thiscall FUN_100141b0(void *this,int *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_100158a0(this,param_1);
  return uVar1 == 0;
}



// Function: FUN_100141f0 at 100141f0

bool __thiscall FUN_100141f0(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_10013ff0(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_10014230 at 10014230

bool __thiscall FUN_10014230(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_10014030(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_10014270 at 10014270

bool __thiscall FUN_10014270(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_10014070(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_100142b0 at 100142b0

bool __thiscall FUN_100142b0(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_100140f0(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_100142f0 at 100142f0

bool __thiscall FUN_100142f0(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_10014130(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_10014330 at 10014330

undefined4 __fastcall FUN_10014330(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014340 at 10014340

undefined4 __fastcall FUN_10014340(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014350 at 10014350

undefined4 __fastcall FUN_10014350(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014360 at 10014360

undefined4 __fastcall FUN_10014360(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014370 at 10014370

undefined4 __fastcall FUN_10014370(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014380 at 10014380

undefined4 __fastcall FUN_10014380(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014390 at 10014390

undefined4 __fastcall FUN_10014390(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100143a0 at 100143a0

undefined4 __fastcall FUN_100143a0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100143b0 at 100143b0

undefined4 __fastcall FUN_100143b0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100143c0 at 100143c0

undefined4 __fastcall FUN_100143c0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100143d0 at 100143d0

undefined4 __fastcall FUN_100143d0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100143e0 at 100143e0

undefined4 __fastcall FUN_100143e0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100143f0 at 100143f0

undefined4 __fastcall FUN_100143f0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10014400 at 10014400

undefined4 __fastcall FUN_10014400(int *param_1)

{
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_10015310((undefined4 *)*param_1);
  }
  return local_c;
}



// Function: FUN_10014430 at 10014430

undefined4 __fastcall FUN_10014430(int *param_1)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_10015380(*param_1);
    local_c = *puVar1;
  }
  return local_c;
}



// Function: FUN_10014460 at 10014460

undefined4 __fastcall FUN_10014460(int *param_1)

{
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_10015310((undefined4 *)*param_1);
  }
  return local_c;
}



// Function: FUN_10014490 at 10014490

undefined4 __fastcall FUN_10014490(int *param_1)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_10015380(*param_1);
    local_c = *puVar1;
  }
  return local_c;
}



// Function: FUN_100144c0 at 100144c0

int __fastcall FUN_100144c0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_100144f0 at 100144f0

int __fastcall FUN_100144f0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014520 at 10014520

int __fastcall FUN_10014520(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014550 at 10014550

int __fastcall FUN_10014550(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014580 at 10014580

int __fastcall FUN_10014580(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_100145b0 at 100145b0

int __fastcall FUN_100145b0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_100145e0 at 100145e0

int __fastcall FUN_100145e0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014610 at 10014610

int __fastcall FUN_10014610(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014640 at 10014640

int __fastcall FUN_10014640(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014670 at 10014670

int __fastcall FUN_10014670(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_100146a0 at 100146a0

int __fastcall FUN_100146a0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_100146d0 at 100146d0

int __fastcall FUN_100146d0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014700 at 10014700

int __fastcall FUN_10014700(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_10014730 at 10014730

int __fastcall FUN_10014730(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FID_conflict:operator& at 10014760

/* Library Function - Multiple Matches With Different Base Names
    public: struct IBindCtx * * __thiscall _CIP<struct IBindCtx,&struct _GUID const
   IID_IBindCtx>::operator&(void)
    public: struct IBindStatusCallback * * __thiscall _CIP<struct IBindStatusCallback,&struct _GUID
   const IID_IBindStatusCallback>::operator&(void)
    public: struct IMoniker * * __thiscall _CIP<struct IMoniker,&struct _GUID const
   IID_IMoniker>::operator&(void)
    public: struct IStream * * __thiscall _CIP<struct IStream,&struct _GUID const
   IID_IStream>::operator&(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __fastcall FID_conflict_operator_(int *param_1)

{
  FUN_10015a70(param_1);
  *param_1 = 0;
  return param_1;
}



// Function: FID_conflict:operator& at 10014780

/* Library Function - Multiple Matches With Different Base Names
    public: struct IBindCtx * * __thiscall _CIP<struct IBindCtx,&struct _GUID const
   IID_IBindCtx>::operator&(void)
    public: struct IBindStatusCallback * * __thiscall _CIP<struct IBindStatusCallback,&struct _GUID
   const IID_IBindStatusCallback>::operator&(void)
    public: struct IMoniker * * __thiscall _CIP<struct IMoniker,&struct _GUID const
   IID_IMoniker>::operator&(void)
    public: struct IStream * * __thiscall _CIP<struct IStream,&struct _GUID const
   IID_IStream>::operator&(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __fastcall FID_conflict_operator_(int *param_1)

{
  FUN_10015b00(param_1);
  *param_1 = 0;
  return param_1;
}



// Function: FID_conflict:operator& at 100147a0

/* Library Function - Multiple Matches With Different Base Names
    public: struct IBindCtx * * __thiscall _CIP<struct IBindCtx,&struct _GUID const
   IID_IBindCtx>::operator&(void)
    public: struct IBindStatusCallback * * __thiscall _CIP<struct IBindStatusCallback,&struct _GUID
   const IID_IBindStatusCallback>::operator&(void)
    public: struct IMoniker * * __thiscall _CIP<struct IMoniker,&struct _GUID const
   IID_IMoniker>::operator&(void)
    public: struct IStream * * __thiscall _CIP<struct IStream,&struct _GUID const
   IID_IStream>::operator&(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __fastcall FID_conflict_operator_(int *param_1)

{
  FUN_10015b30(param_1);
  *param_1 = 0;
  return param_1;
}



// Function: FID_conflict:operator& at 100147c0

/* Library Function - Multiple Matches With Different Base Names
    public: struct IBindCtx * * __thiscall _CIP<struct IBindCtx,&struct _GUID const
   IID_IBindCtx>::operator&(void)
    public: struct IBindStatusCallback * * __thiscall _CIP<struct IBindStatusCallback,&struct _GUID
   const IID_IBindStatusCallback>::operator&(void)
    public: struct IMoniker * * __thiscall _CIP<struct IMoniker,&struct _GUID const
   IID_IMoniker>::operator&(void)
    public: struct IStream * * __thiscall _CIP<struct IStream,&struct _GUID const
   IID_IStream>::operator&(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __fastcall FID_conflict_operator_(int *param_1)

{
  FUN_10015bf0(param_1);
  *param_1 = 0;
  return param_1;
}



// Function: FID_conflict:operator& at 100147e0

/* Library Function - Multiple Matches With Different Base Names
    public: struct IBindCtx * * __thiscall _CIP<struct IBindCtx,&struct _GUID const
   IID_IBindCtx>::operator&(void)
    public: struct IBindStatusCallback * * __thiscall _CIP<struct IBindStatusCallback,&struct _GUID
   const IID_IBindStatusCallback>::operator&(void)
    public: struct IMoniker * * __thiscall _CIP<struct IMoniker,&struct _GUID const
   IID_IMoniker>::operator&(void)
    public: struct IStream * * __thiscall _CIP<struct IStream,&struct _GUID const
   IID_IStream>::operator&(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __fastcall FID_conflict_operator_(int *param_1)

{
  FUN_10015c20(param_1);
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10014800 at 10014800

undefined4 * __thiscall FUN_10014800(void *this,uint param_1)

{
  FUN_100138d0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10014830 at 10014830

_com_error * __thiscall FUN_10014830(void *this,uint param_1)

{
  _com_error::~_com_error((_com_error *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (_com_error *)this;
}



// Function: FUN_10014860 at 10014860

LPWSTR __cdecl FUN_10014860(LPCSTR param_1,int param_2)

{
  uint uVar1;
  LPWSTR pWVar2;
  int iVar3;
  CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> local_24 [4];
  UINT local_20;
  int local_1c;
  int local_18;
  LPWSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023e18;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
    pWVar2 = (LPWSTR)0x0;
  }
  else {
    local_20 = FUN_1000bd10();
    FUN_10001830((undefined4 *)local_24);
    local_8 = 0;
    local_14 = (LPWSTR)0x0;
    local_1c = MultiByteToWideChar(local_20,0,param_1,param_2,(LPWSTR)0x0,0);
    local_18 = local_1c;
    if (param_2 == -1) {
      local_18 = local_1c + -1;
    }
    local_14 = (LPWSTR)Ordinal_4(0,local_18,uVar1);
    if ((local_14 != (LPWSTR)0x0) &&
       (iVar3 = MultiByteToWideChar(local_20,0,param_1,param_2,local_14,local_1c), iVar3 != local_1c
       )) {
      Ordinal_6(local_14);
      local_8 = 0xffffffff;
      ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
      ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_24);
      ExceptionList = local_10;
      return (LPWSTR)0x0;
    }
    pWVar2 = local_14;
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>(local_24);
  }
  ExceptionList = local_10;
  return pWVar2;
}



// Function: FUN_10014970 at 10014970

void FUN_10014970(int param_1)

{
  FUN_10007c00((LONG *)(param_1 + 4));
  return;
}



// Function: Attach at 10014990

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_10015950((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 100149b0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_100159b0((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 100149d0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_100159e0((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 100149f0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_10015a10((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 10014a10

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_10015a70((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 10014a30

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_10015aa0((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 10014a50

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_10015bc0((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 10014a70

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_10015bf0((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: FUN_10014a90 at 10014a90

void __cdecl FUN_10014a90(int param_1)

{
  if (param_1 < 0) {
    _com_issue_error(param_1);
  }
  return;
}



// Function: FUN_10014ab0 at 10014ab0

void __fastcall FUN_10014ab0(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10014ad0 at 10014ad0

uint __thiscall FUN_10014ad0(void *this,undefined4 *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_20;
  ushort *local_10;
  ushort *local_c;
  uint local_8;
  
                    /* WARNING: Load size is inaccurate */
  uVar3 = Ordinal_7(*this);
  uVar4 = Ordinal_7(*param_1);
  local_8 = uVar3;
  if (uVar4 < uVar3) {
    local_8 = uVar4;
  }
                    /* WARNING: Load size is inaccurate */
  puVar1 = (ushort *)*param_1;
  puVar2 = *this;
  do {
    local_c = puVar2;
    local_10 = puVar1;
    if (local_8 == 0) {
      if (uVar3 < uVar4) {
        return 0xffffffff;
      }
      local_20 = (uint)(uVar3 != uVar4);
      return local_20;
    }
    puVar1 = local_10 + 1;
    puVar2 = local_c + 1;
    local_8 = local_8 - 1;
  } while (*local_c == *local_10);
  return (uint)*local_c - (uint)*local_10;
}



// Function: FUN_10014bc0 at 10014bc0

undefined4 FUN_10014bc0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023e52;
  local_10 = ExceptionList;
  if (param_1 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_1 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)FUN_10021550(0x68);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10013080(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_10014c64();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10014c5e at 10014c5e

undefined * Catch_10014c5e(void)

{
  return &DAT_10014c6d;
}



// Function: FUN_10014c64 at 10014c64

undefined4 FUN_10014c64(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_1000aa50();
    FUN_10015390(*(int *)(unaff_EBP + -0x14));
    uVar1 = FUN_1000bd60(*(int *)(unaff_EBP + -0x14) + 4);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_10006ea0();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x18)) {
      uVar1 = FUN_1000bd00();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    }
    FUN_100153b0(*(int *)(unaff_EBP + -0x14));
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x2c);
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x34))(1);
        *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
      }
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
  }
  **(undefined4 **)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10014d30 at 10014d30

int __thiscall FUN_10014d30(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  IID *pIVar1;
  void **ppvObject;
  LPVOID *ppv;
  LPUNKNOWN local_c;
  HRESULT local_8;
  
  FUN_10015980((int *)this);
  if ((param_3 & 0x14) == 0) {
    ppv = (LPVOID *)this;
    pIVar1 = (IID *)FUN_10015210();
    local_8 = CoCreateInstance(param_1,param_2,param_3,pIVar1,ppv);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10029b80,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        ppvObject = (void **)this;
        pIVar1 = (IID *)FUN_10015210();
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,pIVar1,ppvObject);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: FUN_10014df0 at 10014df0

int __thiscall FUN_10014df0(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  IID *pIVar1;
  void **ppvObject;
  LPVOID *ppv;
  LPUNKNOWN local_c;
  HRESULT local_8;
  
  FUN_10015ad0((int *)this);
  if ((param_3 & 0x14) == 0) {
    ppv = (LPVOID *)this;
    pIVar1 = (IID *)FUN_10015270();
    local_8 = CoCreateInstance(param_1,param_2,param_3,pIVar1,ppv);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10029b80,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        ppvObject = (void **)this;
        pIVar1 = (IID *)FUN_10015270();
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,pIVar1,ppvObject);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: Detach at 10014eb0

/* Library Function - Multiple Matches With Same Base Name
    public: struct tagVARIANT __thiscall COleSafeArray::Detach(void)
    public: struct tagVARIANT __thiscall COleVariant::Detach(void)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

undefined4 * __thiscall Detach(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *this;
  uVar2 = *(undefined4 *)((int)this + 4);
  uVar3 = *(undefined4 *)((int)this + 8);
  uVar4 = *(undefined4 *)((int)this + 0xc);
  *(undefined2 *)this = 0;
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  return param_1;
}



// Function: FUN_10014f00 at 10014f00

undefined4 __thiscall FUN_10014f00(void *this,undefined4 param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_c = FUN_10007330(this,param_1);
  }
  return local_c;
}



// Function: FUN_10014f40 at 10014f40

ULONG __fastcall FUN_10014f40(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[10].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002aab0);
  }
  return UVar1;
}



// Function: FUN_10014f90 at 10014f90

void FUN_10014f90(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10015020(&PTR_DAT_100350ac,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10014fc0 at 10014fc0

void FUN_10014fc0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10015020(&PTR_DAT_10035090,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10014ff0 at 10014ff0

void FUN_10014ff0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10015020(&PTR_DAT_10035138,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10015020 at 10015020

int __thiscall
FUN_10015020(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  size_t sVar1;
  void *_Buf1;
  int iVar2;
  size_t _Size;
  void *_Buf2;
  int local_10;
  int local_c;
  
  local_10 = FUN_10014f00(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_10 = -0x7fffbffb;
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      sVar1 = FUN_1000cbd0((wchar_t *)*param_2);
      local_c = *(int *)((int)this + 0x18);
      do {
        do {
          local_c = local_c + -1;
          if (local_c < 0) goto LAB_10015122;
        } while (sVar1 != *(size_t *)(*(int *)((int)this + 0x14) + 4 + local_c * 0xc));
        _Size = *(int *)(*(int *)((int)this + 0x14) + 4 + local_c * 0xc) << 1;
        _Buf2 = (void *)*param_2;
        _Buf1 = (void *)FUN_10003560((undefined4 *)(*(int *)((int)this + 0x14) + local_c * 0xc));
        iVar2 = memcmp(_Buf1,_Buf2,_Size);
      } while (iVar2 != 0);
      *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + local_c * 0xc);
      local_10 = 0;
    }
LAB_10015122:
    if (local_10 < 0) {
      local_10 = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                           (*(undefined4 *)((int)this + 0xc),param_2,param_3,param_5);
    }
  }
  return local_10;
}



// Function: FUN_10015160 at 10015160

undefined4 * FUN_10015160(void)

{
  return &DAT_100299ec;
}



// Function: FUN_10015170 at 10015170

undefined * FUN_10015170(void)

{
  return &DAT_1002aab0;
}



// Function: FUN_10015180 at 10015180

undefined * FUN_10015180(void)

{
  return &DAT_100298fc;
}



// Function: FUN_10015190 at 10015190

undefined * FUN_10015190(void)

{
  return &DAT_100298ec;
}



// Function: FUN_100151a0 at 100151a0

undefined * FUN_100151a0(void)

{
  return &DAT_1002990c;
}



// Function: FUN_100151b0 at 100151b0

undefined * FUN_100151b0(void)

{
  return &DAT_100298dc;
}



// Function: FUN_100151c0 at 100151c0

undefined * FUN_100151c0(void)

{
  return &DAT_1002991c;
}



// Function: FUN_100151d0 at 100151d0

undefined * FUN_100151d0(void)

{
  return &DAT_10029a88;
}



// Function: FUN_100151e0 at 100151e0

undefined * FUN_100151e0(void)

{
  return &DAT_10029a98;
}



// Function: FUN_100151f0 at 100151f0

undefined * FUN_100151f0(void)

{
  return &DAT_1002c6a4;
}



// Function: FUN_10015200 at 10015200

void FUN_10015200(void)

{
  FUN_10015160();
  return;
}



// Function: FUN_10015210 at 10015210

void FUN_10015210(void)

{
  FUN_10015170();
  return;
}



// Function: FUN_10015220 at 10015220

void FUN_10015220(void)

{
  FUN_10015180();
  return;
}



// Function: FUN_10015230 at 10015230

void FUN_10015230(void)

{
  FUN_10015190();
  return;
}



// Function: FUN_10015240 at 10015240

void FUN_10015240(void)

{
  FUN_100151a0();
  return;
}



// Function: FUN_10015250 at 10015250

void FUN_10015250(void)

{
  FUN_100151b0();
  return;
}



// Function: FUN_10015260 at 10015260

void FUN_10015260(void)

{
  FUN_100151c0();
  return;
}



// Function: FUN_10015270 at 10015270

void FUN_10015270(void)

{
  FUN_100151d0();
  return;
}



// Function: FUN_10015280 at 10015280

void FUN_10015280(void)

{
  FUN_100151e0();
  return;
}



// Function: FUN_10015290 at 10015290

void FUN_10015290(void)

{
  FUN_100151f0();
  return;
}



// Function: FUN_100152a0 at 100152a0

undefined4 __fastcall FUN_100152a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100152b0 at 100152b0

undefined * FUN_100152b0(void)

{
  return &DAT_10029a1c;
}



// Function: FUN_100152c0 at 100152c0

undefined2 __fastcall FUN_100152c0(IUnknown *param_1)

{
  HRESULT HVar1;
  void **in_stack_fffffff0;
  undefined2 local_8;
  
  local_8 = 0;
  HVar1 = (*param_1->lpVtbl[8].QueryInterface)(param_1,(IID *)&local_8,in_stack_fffffff0);
  if (HVar1 < 0) {
    _com_issue_errorex(0x1002aab0,param_1,(_GUID *)&DAT_1002aab0);
  }
  return local_8;
}



// Function: FUN_10015310 at 10015310

undefined4 __fastcall FUN_10015310(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (param_1[1] == 0) {
    pCVar1 = ConvertBSTRToString((LPCWSTR)*param_1);
    param_1[1] = pCVar1;
  }
  return param_1[1];
}



// Function: FUN_10015340 at 10015340

void FUN_10015340(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_100078b0(&PTR_DAT_10035138,param_2,param_3,param_4);
  return;
}



// Function: GetTypeInfoCount at 10015360

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



// Function: FUN_10015380 at 10015380

undefined4 __fastcall FUN_10015380(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10015390 at 10015390

void __fastcall FUN_10015390(int param_1)

{
  FUN_10007c00((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_100153b0 at 100153b0

void __fastcall FUN_100153b0(int param_1)

{
  FUN_10007cd0((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_100153d0 at 100153d0

void FUN_100153d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10015490(&PTR_DAT_100350ac,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10015410 at 10015410

void FUN_10015410(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10015490(&PTR_DAT_10035090,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10015450 at 10015450

void FUN_10015450(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10015490(&PTR_DAT_10035138,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10015490 at 10015490

undefined4 __thiscall
FUN_10015490(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 local_c;
  
  local_c = FUN_10014f00(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
                        (*(undefined4 *)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,
                         param_8,param_9);
  }
  return local_c;
}



// Function: FUN_100154f0 at 100154f0

undefined4 __fastcall FUN_100154f0(int *param_1)

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



// Function: FUN_10015520 at 10015520

void __fastcall FUN_10015520(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) == '\0') {
    FUN_10008220((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}



// Function: QueryInterface at 10015550

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::CAccessibleProxy::_InternalQueryInterface
                    ((CAccessibleProxy *)param_1,(_GUID *)param_2,in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10015570 at 10015570

int __thiscall FUN_10015570(void *this,short *param_1)

{
  undefined1 local_1c [8];
  undefined4 *local_14;
  void *local_c;
  int local_8;
  
  local_c = this;
  if (*param_1 == 9) {
    local_8 = FUN_100127e0(this,*(undefined4 **)(param_1 + 4));
  }
  else if (*param_1 == 0xd) {
    local_8 = FUN_10012850(this,*(undefined4 **)(param_1 + 4));
  }
  else {
    Ordinal_8(local_1c);
    local_8 = Ordinal_12(local_1c,param_1,0,9);
    if (-1 < local_8) {
      local_8 = FUN_100127e0(local_c,local_14);
    }
    if (local_8 == -0x7fffbffe) {
      Ordinal_8(local_1c);
      local_8 = Ordinal_12(local_1c,param_1,0,0xd);
      if (-1 < local_8) {
        local_8 = FUN_10012850(local_c,local_14);
      }
    }
    Ordinal_9(local_1c);
  }
  return local_8;
}



// Function: Release at 10015640

/* Library Function - Single Match
    public: virtual unsigned long __stdcall CMFCComObject<class
   ATL::CAccessibleProxy>::Release(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

ulong CMFCComObject<class_ATL::CAccessibleProxy>::Release(void)

{
  ulong uVar1;
  int *in_stack_00000004;
  
  uVar1 = FUN_10007cd0(in_stack_00000004 + 1);
  if ((uVar1 == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x34))(1);
  }
  return uVar1;
}



// Function: FUN_10015690 at 10015690

void __fastcall FUN_10015690(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_1000ad70((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100156c0 at 100156c0

void __fastcall FUN_100156c0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_100156f0 at 100156f0

void __fastcall FUN_100156f0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_10015720 at 10015720

void __fastcall FUN_10015720(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_10015750 at 10015750

void __fastcall FUN_10015750(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_10015780 at 10015780

void __fastcall FUN_10015780(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_100157b0 at 100157b0

void __fastcall FUN_100157b0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_100157e0 at 100157e0

void __fastcall FUN_100157e0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_10015810 at 10015810

void __fastcall FUN_10015810(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_10015840 at 10015840

void __fastcall FUN_10015840(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_10015870 at 10015870

void __fastcall FUN_10015870(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_100158a0 at 100158a0

uint __thiscall FUN_100158a0(void *this,int *param_1)

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
      iVar2 = FUN_10015cb0(param_1);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else if (*param_1 == 0) {
      iVar2 = FUN_10015cb0((int *)this);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar1 = FUN_10014ad0(*this,(undefined4 *)*param_1);
    }
  }
  return uVar1;
}



// Function: _GetEntries at 10015910

/* Library Function - Single Match
    public: static struct ATL::_ATL_INTMAP_ENTRY const * __stdcall
   ATL::CAccessibleProxy::_GetEntries(void)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

_ATL_INTMAP_ENTRY * ATL::CAccessibleProxy::_GetEntries(void)

{
  return (_ATL_INTMAP_ENTRY *)&PTR_DAT_1002c714;
}



// Function: _InternalQueryInterface at 10015920

/* Library Function - Single Match
    public: long __thiscall ATL::CAccessibleProxy::_InternalQueryInterface(struct _GUID const &,void
   * *)
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual
   Studio 2010 Debug */

long __thiscall
ATL::CAccessibleProxy::_InternalQueryInterface(CAccessibleProxy *this,_GUID *param_1,void **param_2)

{
  _ATL_INTMAP_ENTRY *p_Var1;
  int iVar2;
  
  p_Var1 = _GetEntries();
  iVar2 = FUN_10007ca0((int)this,(int *)p_Var1,(int *)param_1,param_2);
  return iVar2;
}



// Function: FUN_10015950 at 10015950

void __fastcall FUN_10015950(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015980 at 10015980

void __fastcall FUN_10015980(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100159b0 at 100159b0

void __fastcall FUN_100159b0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100159e0 at 100159e0

void __fastcall FUN_100159e0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015a10 at 10015a10

void __fastcall FUN_10015a10(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015a40 at 10015a40

void __fastcall FUN_10015a40(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015a70 at 10015a70

void __fastcall FUN_10015a70(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015aa0 at 10015aa0

void __fastcall FUN_10015aa0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015ad0 at 10015ad0

void __fastcall FUN_10015ad0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015b00 at 10015b00

void __fastcall FUN_10015b00(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015b30 at 10015b30

void __fastcall FUN_10015b30(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015b60 at 10015b60

void __fastcall FUN_10015b60(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015b90 at 10015b90

void __fastcall FUN_10015b90(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015bc0 at 10015bc0

void __fastcall FUN_10015bc0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015bf0 at 10015bf0

void __fastcall FUN_10015bf0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015c20 at 10015c20

void __fastcall FUN_10015c20(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10015c50 at 10015c50

void __fastcall FUN_10015c50(_String_val<struct_std::_Simple_types<char>_> *param_1)

{
  std::_String_val<struct_std::_Simple_types<char>_>::_Myptr(param_1);
  return;
}



// Function: FUN_10015c70 at 10015c70

undefined4 __fastcall FUN_10015c70(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10015c90 at 10015c90

undefined4 __fastcall FUN_10015c90(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_10015cb0 at 10015cb0

undefined4 __fastcall FUN_10015cb0(int *param_1)

{
  undefined4 local_c;
  
  if (*param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = FUN_100154f0((int *)*param_1);
  }
  return local_c;
}



// Function: FUN_10015ce0 at 10015ce0

void __cdecl FUN_10015ce0(double param_1,uint param_2)

{
  FUN_10012750(param_1,param_2);
  return;
}



// Function: FUN_10015d00 at 10015d00

void __thiscall FUN_10015d00(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 8) = param_1;
  return;
}



// Function: FUN_10015d20 at 10015d20

void __cdecl FUN_10015d20(char *param_1,char *param_2)

{
  strstr(param_1,param_2);
  return;
}



// Function: FUN_10015d40 at 10015d40

int __fastcall FUN_10015d40(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10023ef4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001ad0((undefined4 *)(param_1 + 4));
  local_8 = 0;
  FUN_10018e00(param_1);
  FUN_10013240((undefined4 *)(param_1 + 0x24));
  local_8._0_1_ = 1;
  FUN_10013290((undefined4 *)(param_1 + 0x28));
  local_8._0_1_ = 2;
  FUN_10013290((undefined4 *)(param_1 + 0x2c));
  local_8._0_1_ = 3;
  FUN_10013290((undefined4 *)(param_1 + 0x30));
  local_8._0_1_ = 4;
  FUN_10013290((undefined4 *)(param_1 + 0x34));
  local_8._0_1_ = 5;
  FUN_10013290((undefined4 *)(param_1 + 0x38));
  local_8._0_1_ = 6;
  FUN_10013290((undefined4 *)(param_1 + 0x3c));
  local_8._0_1_ = 7;
  FUN_10013290((undefined4 *)(param_1 + 0x40));
  local_8._0_1_ = 8;
  FUN_10018f20((undefined4 *)(param_1 + 0x44));
  local_8._0_1_ = 9;
  FUN_10019990((undefined4 *)(param_1 + 0x50));
  local_8._0_1_ = 10;
  FUN_10013290((undefined4 *)(param_1 + 100));
  local_8 = CONCAT31(local_8._1_3_,0xb);
  *(undefined4 *)(param_1 + 0x60) = 0;
  FUN_10015d00((void *)(param_1 + 0x50),0xffffffff);
  ExceptionList = local_10;
  return param_1;
}



// Function: CCIAuditTrailRecord_get_ToolInstance at 10015e60

void CCIAuditTrailRecord_get_ToolInstance(int param_1,int *param_2)

{
  char cVar1;
  bool bVar2;
  IUnknown *pIVar3;
  LPCSTR pCVar4;
  int iVar5;
  _GUID *p_Var6;
  uint uStack_90;
  undefined1 local_6c [24];
  int *local_54;
  long local_50;
  int local_4c;
  int *local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [24];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023f47;
  local_10 = ExceptionList;
  uStack_90 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_34 = 0;
  local_8 = 0;
  local_18 = uStack_90;
  cVar1 = FUN_10017fa0(param_1);
  if (cVar1 == '\0') {
    FUN_10019a70(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
  }
  else {
    FUN_10011e00(&local_40,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 100));
    local_8 = CONCAT31(local_8._1_3_,1);
    local_48 = (int *)FUN_10014550(&local_40);
    local_50 = (**(code **)(*local_48 + 0x34))(local_48);
    if (local_50 < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6c4;
      pIVar3 = (IUnknown *)FUN_10014360(&local_40);
      _com_issue_errorex(local_50,pIVar3,p_Var6);
    }
    FUN_10018f20(&local_38);
    local_8._0_1_ = 2;
    FUN_10018730(&local_38,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 0x2c));
    bVar2 = FUN_10014270(&local_38,0);
    if (bVar2) {
      local_54 = (int *)FUN_10014610(&local_38);
      local_34 = (**(code **)(*local_54 + 0x20))(local_54,param_2);
      if (local_34 < 0) {
        FUN_10019b10(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
      }
    }
    else {
      FUN_100131f0(&local_3c);
      local_8._0_1_ = 3;
      FUN_10013860(local_6c);
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_10012580(&local_3c,
                   (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                   (param_1 + 0x2c));
      local_44 = (int *)FUN_10014550(&local_3c);
      local_34 = (**(code **)(*local_44 + 0x28))(local_44,local_6c);
      if (local_34 < 0) {
        FUN_10019b10(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
      }
      basic_string<>(local_30);
      local_8._0_1_ = 5;
      FUN_1001c820((int)local_6c,local_30);
      pCVar4 = (LPCSTR)FUN_10015c50((_String_val<struct_std::_Simple_types<char>_> *)local_30);
      FUN_10002650(&local_4c,pCVar4);
      local_8._0_1_ = 6;
      iVar5 = FUN_10019740(&local_4c,'\x01');
      *param_2 = iVar5;
      local_8._0_1_ = 5;
      FUN_100032d0(&local_4c);
      local_8._0_1_ = 4;
      ~basic_string<>(local_30);
      local_8._0_1_ = 3;
      FUN_10013df0(local_6c);
      local_8._0_1_ = 2;
      FUN_10013a20(&local_3c);
    }
    local_8._0_1_ = 1;
    FUN_10013aa0(&local_38);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10013a20(&local_40);
  }
  FUN_1001616f();
  return;
}



// Function: Catch@100160b6 at 100160b6

undefined * Catch_100160b6(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x6c),"CIAuditTrailRecord.cpp",0x90,
                       "CCIAuditTrailRecord::get_ToolInstance",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x54) = uVar2;
  return &DAT_10016186;
}



// Function: Catch@10016102 at 10016102

undefined * Catch_10016102(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x7c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x7c),"CIAuditTrailRecord.cpp",0x90,
                       "CCIAuditTrailRecord::get_ToolInstance",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x58) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uStack0000001c = 0x10016163;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x7c));
  return &DAT_10016178;
}



// Function: FUN_1001616f at 1001616f

void FUN_1001616f(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100161ad;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CCIAuditTrailRecord_get_ToolVersion at 100161c0

void CCIAuditTrailRecord_get_ToolVersion(int param_1,int *param_2)

{
  char cVar1;
  bool bVar2;
  IUnknown *pIVar3;
  LPCSTR pCVar4;
  int iVar5;
  _GUID *p_Var6;
  uint uStack_90;
  undefined1 local_6c [24];
  int *local_54;
  long local_50;
  int local_4c;
  int *local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [24];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10023fa4;
  local_10 = ExceptionList;
  uStack_90 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_34 = 0;
  local_8 = 0;
  local_18 = uStack_90;
  cVar1 = FUN_10017fa0(param_1);
  if (cVar1 == '\0') {
    FUN_10019a70(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
  }
  else {
    FUN_10011e00(&local_40,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 100));
    local_8 = CONCAT31(local_8._1_3_,1);
    local_48 = (int *)FUN_10014550(&local_40);
    local_50 = (**(code **)(*local_48 + 0x34))(local_48);
    if (local_50 < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6c4;
      pIVar3 = (IUnknown *)FUN_10014360(&local_40);
      _com_issue_errorex(local_50,pIVar3,p_Var6);
    }
    FUN_10018f20(&local_38);
    local_8._0_1_ = 2;
    FUN_10018730(&local_38,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 0x30));
    bVar2 = FUN_10014270(&local_38,0);
    if (bVar2) {
      local_54 = (int *)FUN_10014610(&local_38);
      local_34 = (**(code **)(*local_54 + 0x20))(local_54,param_2);
      if (local_34 < 0) {
        FUN_10019b10(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
      }
    }
    else {
      FUN_100131f0(&local_3c);
      local_8._0_1_ = 3;
      FUN_10012580(&local_3c,
                   (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                   (param_1 + 0x30));
      FUN_10013860(local_6c);
      local_8 = CONCAT31(local_8._1_3_,4);
      local_44 = (int *)FUN_10014550(&local_3c);
      local_34 = (**(code **)(*local_44 + 0x28))(local_44,local_6c);
      if (local_34 < 0) {
        FUN_10019b10(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
      }
      basic_string<>(local_30);
      local_8._0_1_ = 5;
      FUN_1001c820((int)local_6c,local_30);
      pCVar4 = (LPCSTR)FUN_10015c50((_String_val<struct_std::_Simple_types<char>_> *)local_30);
      FUN_10002650(&local_4c,pCVar4);
      local_8._0_1_ = 6;
      iVar5 = FUN_10019740(&local_4c,'\x01');
      *param_2 = iVar5;
      local_8._0_1_ = 5;
      FUN_100032d0(&local_4c);
      local_8._0_1_ = 4;
      ~basic_string<>(local_30);
      local_8._0_1_ = 3;
      FUN_10013df0(local_6c);
      local_8._0_1_ = 2;
      FUN_10013a20(&local_3c);
    }
    local_8._0_1_ = 1;
    FUN_10013aa0(&local_38);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10013a20(&local_40);
  }
  FUN_100164d2();
  return;
}



// Function: Catch@10016419 at 10016419

undefined * Catch_10016419(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x6c),"CIAuditTrailRecord.cpp",0xd0,
                       "CCIAuditTrailRecord::get_ToolVersion",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x54) = uVar2;
  return &DAT_100164e9;
}



// Function: Catch@10016465 at 10016465

undefined * Catch_10016465(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x7c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x7c),"CIAuditTrailRecord.cpp",0xd0,
                       "CCIAuditTrailRecord::get_ToolVersion",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x58) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uStack0000001c = 0x100164c6;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x7c));
  return &DAT_100164db;
}



// Function: FUN_100164d2 at 100164d2

void FUN_100164d2(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10016510;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: CCIAuditTrailRecord_get_ToolId at 10016520

void CCIAuditTrailRecord_get_ToolId(int param_1,int *param_2)

{
  char cVar1;
  IUnknown *pIVar2;
  _GUID *p_Var3;
  uint uStack_60;
  double local_40 [2];
  int *local_2c;
  long local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10023fe1;
  local_10 = ExceptionList;
  uStack_60 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 0;
  cVar1 = FUN_10017fa0(param_1);
  if (cVar1 == '\0') {
    FUN_10019a70(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
  }
  else {
    FUN_10011e00(&local_20,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 100));
    local_8 = CONCAT31(local_8._1_3_,1);
    local_24 = (int *)FUN_10014550(&local_20);
    local_28 = (**(code **)(*local_24 + 0x34))(local_24);
    if (local_28 < 0) {
      p_Var3 = (_GUID *)&DAT_1002c6c4;
      pIVar2 = (IUnknown *)FUN_10014360(&local_20);
      _com_issue_errorex(local_28,pIVar2,p_Var3);
    }
    if (*(int *)(param_1 + 0x48) == 2) {
      FUN_10018f20(&local_1c);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_10018730(&local_1c,
                   (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                   (param_1 + 0x34));
      local_40[0] = 0.0;
      local_2c = (int *)FUN_10014610(&local_1c);
      local_18 = (**(code **)(*local_2c + 0x28))(local_2c,local_40);
      if (local_18 < 0) {
        FUN_10019b10(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
      }
      *param_2 = (int)local_40[0];
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_10013aa0(&local_1c);
    }
    else {
      local_18 = -0x7fffbfff;
    }
    local_8 = local_8 & 0xffffff00;
    FUN_10013a20(&local_20);
  }
  FUN_1001675b();
  return;
}



// Function: Catch@100166a2 at 100166a2

undefined * Catch_100166a2(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x34),"CIAuditTrailRecord.cpp",0x103,
                       "CCIAuditTrailRecord::get_ToolId",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  return &DAT_10016772;
}



// Function: Catch@100166ee at 100166ee

undefined * Catch_100166ee(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x4c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x4c),"CIAuditTrailRecord.cpp",0x103,
                       "CCIAuditTrailRecord::get_ToolId",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x1001674f;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return &DAT_10016764;
}



// Function: FUN_1001675b at 1001675b

undefined4 FUN_1001675b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: CCIAuditTrailRecord_get_ECM_RunTime at 100167a0

void CCIAuditTrailRecord_get_ECM_RunTime(int param_1,int *param_2)

{
  char cVar1;
  IUnknown *pIVar2;
  _GUID *p_Var3;
  uint uStack_60;
  double local_40 [2];
  int *local_2c;
  long local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10024014;
  local_10 = ExceptionList;
  uStack_60 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_20 = 0;
  local_8 = 0;
  cVar1 = FUN_10017fa0(param_1);
  if (cVar1 == '\0') {
    FUN_10019a70(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
  }
  else {
    FUN_10011e00(&local_1c,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 100));
    local_8 = CONCAT31(local_8._1_3_,1);
    local_24 = (int *)FUN_10014550(&local_1c);
    local_28 = (**(code **)(*local_24 + 0x34))(local_24);
    if (local_28 < 0) {
      p_Var3 = (_GUID *)&DAT_1002c6c4;
      pIVar2 = (IUnknown *)FUN_10014360(&local_1c);
      _com_issue_errorex(local_28,pIVar2,p_Var3);
    }
    FUN_10018f20(&local_18);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10018730(&local_18,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 0x38));
    local_40[0] = 0.0;
    local_2c = (int *)FUN_10014610(&local_18);
    local_20 = (**(code **)(*local_2c + 0x28))(local_2c,local_40);
    if (local_20 < 0) {
      FUN_10019b10(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
    }
    *param_2 = (int)local_40[0];
    local_8._0_1_ = 1;
    FUN_10013aa0(&local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10013a20(&local_1c);
  }
  FUN_100169c5();
  return;
}



// Function: Catch@1001690c at 1001690c

undefined * Catch_1001690c(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x34),"CIAuditTrailRecord.cpp",299,
                       "CCIAuditTrailRecord::get_ECM_RunTime",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  return &DAT_100169dc;
}



// Function: Catch@10016958 at 10016958

undefined * Catch_10016958(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x4c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x4c),"CIAuditTrailRecord.cpp",299,
                       "CCIAuditTrailRecord::get_ECM_RunTime",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x100169b9;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return &DAT_100169ce;
}



// Function: FUN_100169c5 at 100169c5

undefined4 FUN_100169c5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x1c);
}



// Function: CCIAuditTrailRecord_get_TimeStamp at 10016a00

undefined4 CCIAuditTrailRecord_get_TimeStamp(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  IUnknown *pIVar4;
  undefined4 uVar5;
  _GUID *p_Var6;
  uint uStack_5c;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10024047;
  local_10 = ExceptionList;
  uStack_5c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_5c;
  ExceptionList = &local_10;
  local_8 = 0;
  cVar1 = FUN_10017fa0(param_1);
  if (cVar1 == '\0') {
    FUN_10019a70(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
  }
  else {
    FUN_10011e00(&local_18,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 100));
    local_8 = CONCAT31(local_8._1_3_,1);
    piVar2 = (int *)FUN_10014550(&local_18);
    iVar3 = (**(code **)(*piVar2 + 0x34))(piVar2);
    if (iVar3 < 0) {
      p_Var6 = (_GUID *)&DAT_1002c6c4;
      pIVar4 = (IUnknown *)FUN_10014360(&local_18);
      _com_issue_errorex(iVar3,pIVar4,p_Var6);
    }
    if (*(int *)(param_1 + 0x48) != 2) {
      local_8 = local_8 & 0xffffff00;
      FUN_10013a20(&local_18);
      ExceptionList = local_10;
      return 0x80004001;
    }
    FUN_10018f20(&local_1c);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10018730(&local_1c,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 0x3c));
    piVar2 = (int *)FUN_10014610(&local_1c);
    iVar3 = (**(code **)(*piVar2 + 0x20))(piVar2,param_2);
    if (iVar3 < 0) {
      FUN_10019b10(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
    }
    local_8._0_1_ = 1;
    FUN_10013aa0(&local_1c);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10013a20(&local_18);
  }
  uVar5 = FUN_10016c32();
  return uVar5;
}



// Function: Catch@10016b79 at 10016b79

undefined * Catch_10016b79(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x38),"CIAuditTrailRecord.cpp",0x15a,
                       "CCIAuditTrailRecord::get_TimeStamp",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar2;
  return &DAT_10016c49;
}



// Function: Catch@10016bc5 at 10016bc5

undefined * Catch_10016bc5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x48),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x48),"CIAuditTrailRecord.cpp",0x15a,
                       "CCIAuditTrailRecord::get_TimeStamp",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x10016c26;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return &DAT_10016c3b;
}



// Function: FUN_10016c32 at 10016c32

undefined4 FUN_10016c32(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x1c);
}



// Function: FUN_10016c70 at 10016c70

void FUN_10016c70(int param_1,undefined4 *param_2)

{
  char cVar1;
  bool bVar2;
  IUnknown *pIVar3;
  int *piVar4;
  undefined4 *puVar5;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *prVar6;
  uint uVar7;
  ushort in_FPUControlWord;
  float10 fVar8;
  _GUID *p_Var9;
  uint uStack_130;
  int iStack_108;
  undefined1 auStack_104 [4];
  longlong local_100;
  undefined1 auStack_f8 [4];
  double local_f4;
  int aiStack_ec [2];
  undefined1 local_e4 [8];
  undefined4 local_dc;
  int local_d4;
  int iStack_d0;
  int iStack_c8;
  uint local_c4;
  uint local_c0;
  int iStack_bc;
  int local_b4;
  _Container_base0 local_b0 [12];
  refcount_ptr<struct_boost::exception_detail::error_info_container> arStack_a4 [4];
  int *local_a0;
  int local_9c;
  long local_98;
  int local_94;
  int local_90;
  int *local_8c;
  long local_88;
  long local_84;
  long local_80;
  int local_7c;
  int *local_78;
  int local_74;
  long local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  int *local_60;
  long local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 uStack_4c;
  short local_48;
  int iStack_44;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_40 [4];
  undefined4 uStack_3c;
  int local_38;
  int local_34;
  int local_30 [2];
  int local_28;
  uint local_24;
  byte local_1d;
  short local_1c;
  byte local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100240d1;
  local_10 = ExceptionList;
  uStack_130 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_130;
  ExceptionList = &local_10;
  local_8 = 0;
  cVar1 = FUN_10017fa0(param_1);
  if (cVar1 == '\0') {
    FUN_10019a70(param_1 + 0x50,(uchar *)"CIAuditTrailRecord.cpp");
  }
  else {
    FUN_10011e00(&local_54,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 100));
    local_8 = CONCAT31(local_8._1_3_,1);
    local_60 = (int *)FUN_10014550(&local_54);
    local_88 = (**(code **)(*local_60 + 0x34))(local_60);
    if (local_88 < 0) {
      p_Var9 = (_GUID *)&DAT_1002c6c4;
      pIVar3 = (IUnknown *)FUN_10014360(&local_54);
      _com_issue_errorex(local_88,pIVar3,p_Var9);
    }
    vector<>((undefined4 *)local_b0);
    local_8._0_1_ = 2;
    if (*(int *)(param_1 + 0x48) != 2) {
      FUN_10011e00(local_30,(refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                            (param_1 + 0x40));
      local_8._0_1_ = 3;
      FUN_10013860(local_e4);
      local_8 = CONCAT31(local_8._1_3_,4);
      local_64 = (int *)FUN_10014550(local_30);
      local_84 = (**(code **)(*local_64 + 0x28))(local_64,local_e4);
      if (local_84 < 0) {
        p_Var9 = (_GUID *)&DAT_1002c6c4;
        pIVar3 = (IUnknown *)FUN_10014360(local_30);
        _com_issue_errorex(local_84,pIVar3,p_Var9);
      }
      local_74 = 0;
      local_6c = (int *)FUN_10014550(local_30);
      local_98 = (**(code **)(*local_6c + 0x20))(local_6c,&local_74);
      if (local_98 < 0) {
        p_Var9 = (_GUID *)&DAT_1002c6c4;
        pIVar3 = (IUnknown *)FUN_10014360(local_30);
        _com_issue_errorex(local_98,pIVar3,p_Var9);
      }
      local_b4 = local_74 << 3;
      local_90 = 0;
      Ordinal_23(local_dc,&local_90);
      local_8._0_1_ = 5;
      for (local_24 = 0; (int)local_24 < local_b4; local_24 = local_24 + 1) {
        local_48 = (short)((int)(local_24 + ((int)local_24 >> 0x1f & 7U)) >> 3);
        uVar7 = local_24 & 0x80000007;
        if ((int)uVar7 < 0) {
          uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
        }
        local_15 = *(byte *)(local_90 + local_48);
        local_1c = 7 - (short)uVar7;
        fVar8 = (float10)FUN_10015ce0(2.0,(int)local_1c);
        local_c0 = in_FPUControlWord | 0xc00;
        local_d4 = (int)ROUND(fVar8);
        local_1d = (byte)local_d4;
        local_15 = (byte)((int)(uint)(local_15 & (byte)local_d4) >> ((byte)local_1c & 0x1f));
        if (local_15 != '\0') {
          CCIAuditTrailRecord_GetLogicalName(&local_7c,local_24);
          local_8._0_1_ = 6;
          FUN_10019860(local_b0,&local_7c);
          local_8._0_1_ = 5;
          FUN_100032d0(&local_7c);
        }
      }
      Ordinal_24(local_dc);
      CCIAuditTrailRecord_get_ActiveChangeCodes();
      return;
    }
    FUN_10011ea0(&local_28,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 0x40));
    local_8._0_1_ = 8;
    FUN_10011fe0(&local_50,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 (param_1 + 0x40));
    local_8 = CONCAT31(local_8._1_3_,9);
    local_58 = 0;
    local_a0 = (int *)FUN_10014580(&local_28);
    local_5c = (**(code **)(*local_a0 + 0x24))(local_a0,&local_58);
    if (local_5c < 0) {
      p_Var9 = (_GUID *)&DAT_1002c6b4;
      pIVar3 = (IUnknown *)FUN_10014370(&local_28);
      _com_issue_errorex(local_5c,pIVar3,p_Var9);
    }
    for (local_38 = 0; local_38 < local_58; local_38 = local_38 + 1) {
      FUN_10013370((undefined4 *)local_40);
      local_8 = CONCAT31(local_8._1_3_,10);
      local_68 = (int *)FUN_10014580(&local_28);
      local_70 = (**(code **)(*local_68 + 0x1c))(local_68,local_38);
      if (local_70 < 0) {
        p_Var9 = (_GUID *)&DAT_1002c6b4;
        pIVar3 = (IUnknown *)FUN_10014370(&local_28);
        _com_issue_errorex(local_70,pIVar3,p_Var9);
      }
      local_78 = (int *)FUN_10014700(&local_50);
      piVar4 = FID_conflict_operator_((int *)local_40);
      local_80 = (**(code **)(*local_78 + 0x34))(local_78,piVar4);
      if (local_80 < 0) {
        p_Var9 = (_GUID *)&DAT_1002c6a4;
        pIVar3 = (IUnknown *)FUN_100143e0(&local_50);
        _com_issue_errorex(local_80,pIVar3,p_Var9);
      }
      FUN_10018f20(&local_34);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      FUN_100187c0(&local_34,local_40);
      local_f4 = 0.0;
      local_8c = (int *)FUN_10014610(&local_34);
      local_94 = (**(code **)(*local_8c + 0x28))();
      if (local_94 < 0) {
        p_Var9 = (_GUID *)&DAT_1002c6e4;
        pIVar3 = (IUnknown *)FUN_100143a0(&local_34);
        _com_issue_errorex(local_94,pIVar3,p_Var9);
      }
      local_c4 = in_FPUControlWord | 0xc00;
      local_100 = (longlong)ROUND(local_f4);
      CCIAuditTrailRecord_GetLogicalName(&local_9c,(int)local_100);
      local_8._0_1_ = 0xc;
      FUN_10019860(local_b0,&local_9c);
      local_8._0_1_ = 0xb;
      FUN_100032d0(&local_9c);
      local_8._0_1_ = 10;
      FUN_10013aa0(&local_34);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_10013b80((int *)local_40);
    }
    local_8._0_1_ = 8;
    FUN_10013b80(&local_50);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10013a40(&local_28);
    aiStack_ec[0] = size((int *)local_b0);
    aiStack_ec[1] = 0;
    iStack_d0 = aiStack_ec[0];
    uStack_4c = Ordinal_15(8,1,aiStack_ec);
    Ordinal_23(uStack_4c,&iStack_c8);
    FUN_10018eb0(&uStack_3c);
    iStack_44 = 0;
    puVar5 = (undefined4 *)FID_conflict_begin(local_b0,auStack_f8);
    uStack_3c = *puVar5;
    while( true ) {
      piVar4 = (int *)FID_conflict_begin(local_b0,auStack_104);
      bVar2 = FID_conflict_operator__(&uStack_3c,piVar4);
      if (!bVar2) break;
      prVar6 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               FUN_100190d0(&uStack_3c);
      boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
      refcount_ptr<struct_boost::exception_detail::error_info_container>(arStack_a4,prVar6);
      local_8._0_1_ = 0xd;
      iStack_bc = FUN_10019740(arStack_a4,'\x01');
      *(int *)(iStack_c8 + iStack_44 * 4) = iStack_bc;
      iStack_44 = iStack_44 + 1;
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_100032d0((int *)arStack_a4);
      FUN_10019110(&uStack_3c,&iStack_108);
    }
    Ordinal_24();
    *param_2 = uStack_4c;
    local_8._0_1_ = 1;
    FUN_10018fd0(local_b0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10013a20(&local_54);
  }
  FUN_100173ca();
  return;
}



// Function: Catch@10016f27 at 10016f27

void Catch_10016f27(void)

{
  int unaff_EBP;
  
  Ordinal_24(*(undefined4 *)(unaff_EBP + -0xd8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: CCIAuditTrailRecord_get_ActiveChangeCodes at 10016f43

void CCIAuditTrailRecord_get_ActiveChangeCodes(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *prVar6;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10013df0(unaff_EBP + -0xe0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10013a20((int *)(unaff_EBP + -0x2c));
  iVar2 = size((int *)(unaff_EBP + -0xac));
  *(int *)(unaff_EBP + -0xcc) = iVar2;
  *(undefined4 *)(unaff_EBP + -0xe8) = *(undefined4 *)(unaff_EBP + -0xcc);
  *(undefined4 *)(unaff_EBP + -0xe4) = 0;
  uVar3 = Ordinal_15(8,1,unaff_EBP + -0xe8);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar3;
  Ordinal_23(*(undefined4 *)(unaff_EBP + -0x48),unaff_EBP + -0xc4);
  FUN_10018eb0((undefined4 *)(unaff_EBP + -0x38));
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  puVar4 = (undefined4 *)FID_conflict_begin((void *)(unaff_EBP + -0xac),(void *)(unaff_EBP + -0xf4))
  ;
  *(undefined4 *)(unaff_EBP + -0x38) = *puVar4;
  while( true ) {
    piVar5 = (int *)FID_conflict_begin((void *)(unaff_EBP + -0xac),(void *)(unaff_EBP + -0x100));
    bVar1 = FID_conflict_operator__((void *)(unaff_EBP + -0x38),piVar5);
    if (!bVar1) break;
    prVar6 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
             FUN_100190d0((undefined4 *)(unaff_EBP + -0x38));
    boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
    refcount_ptr<struct_boost::exception_detail::error_info_container>
              ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               (unaff_EBP + -0xa0),prVar6);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    iVar2 = FUN_10019740((void *)(unaff_EBP + -0xa0),'\x01');
    *(int *)(unaff_EBP + -0xb8) = iVar2;
    *(undefined4 *)(*(int *)(unaff_EBP + -0xc4) + *(int *)(unaff_EBP + -0x40) * 4) =
         *(undefined4 *)(unaff_EBP + -0xb8);
    *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_100032d0((int *)(unaff_EBP + -0xa0));
    FUN_10019110((void *)(unaff_EBP + -0x38),(int *)(unaff_EBP + -0x104));
  }
  Ordinal_24(*(undefined4 *)(unaff_EBP + -0x48));
  **(undefined4 **)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -0x48);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10018fd0((_Container_base0 *)(unaff_EBP + -0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_10013a20((int *)(unaff_EBP + -0x50));
  FUN_100173ca();
  return;
}



// Function: Catch@100172ff at 100172ff

undefined * Catch_100172ff(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x108),"CIAuditTrailRecord.cpp",0x1e9,
                       "CCIAuditTrailRecord::get_ActiveChangeCodes",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -200) = uVar2;
  return &DAT_100173e4;
}



// Function: Catch@10017351 at 10017351

undefined * Catch_10017351(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x11c),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  puVar1 = (undefined8 *)FUN_100192c0();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x11c),"CIAuditTrailRecord.cpp",0x1e9,
                       "CCIAuditTrailRecord::get_ActiveChangeCodes",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0xb4) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  uStack0000001c = 0x100173be;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x11c));
  return &DAT_100173d3;
}



// Function: FUN_100173ca at 100173ca

undefined4 FUN_100173ca(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: CCIAuditTrailRecord_Initialize at 10017410

void __thiscall CCIAuditTrailRecord_Initialize(void *this,undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  IUnknown *pIVar3;
  char *_Format;
  undefined4 uVar4;
  _GUID *p_Var5;
  uint uStack_1f4;
  int local_1d0;
  int *local_1cc;
  int *local_1c8;
  int *local_1c4;
  int *local_1c0;
  int *local_1bc;
  int *local_1b8;
  int *local_1b4;
  int *local_1b0;
  int *local_1ac;
  long local_1a8;
  int *local_1a4;
  int *local_1a0;
  int *local_19c;
  long local_198;
  int *local_194;
  int *local_190;
  int *local_18c;
  long local_188;
  long local_184;
  int *local_180;
  int *local_17c;
  long local_178;
  long local_174;
  int *local_170;
  long local_16c;
  long local_168;
  long local_164;
  int *local_160;
  long local_15c;
  long local_158;
  long local_154;
  int *local_150;
  long local_14c;
  long local_148;
  int local_144;
  int *local_140;
  long local_13c;
  long local_138;
  long local_134;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_130 [4];
  int local_12c;
  int local_128;
  int local_124;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_120 [4];
  void *local_11c;
  char local_118 [256];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_10024144;
  local_10 = ExceptionList;
  uStack_1f4 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1f4;
  ExceptionList = &local_10;
  local_8 = 1;
  uStack_7 = 0;
  local_11c = this;
  local_18 = uStack_1f4;
  FUN_10018ff0((void *)((int)this + 0x24),&param_1);
  *(int *)((int)local_11c + 0x48) = param_3;
  *(undefined4 *)((int)local_11c + 0x60) = param_2;
  uVar1 = FUN_1001b4b0((int *)((int)local_11c + 0x24));
  *(undefined4 *)((int)local_11c + 0x4c) = uVar1;
  local_17c = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
  (**(code **)(*local_17c + 0x4c))(local_17c,*(undefined4 *)((int)local_11c + 0x4c));
  FUN_10017f80(local_11c,1);
  FUN_10013290((undefined4 *)local_120);
  _local_8 = CONCAT31(uStack_7,2);
  if ((param_3 == 1) || (param_3 == 0)) {
    local_1c0 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 100));
    uVar1 = FUN_10014430((int *)&DAT_100354a0);
    local_13c = (**(code **)(*local_1c0 + 0x30))(local_1c0,0,uVar1,piVar2);
    if (local_13c < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_13c,pIVar3,p_Var5);
    }
    uVar1 = param_2;
    _Format = (char *)FUN_10014460((int *)&DAT_100354ac);
    sprintf(local_118,_Format,uVar1);
    local_18c = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x28));
    local_1cc = FUN_10002650(&local_1d0,local_118);
    local_8 = 3;
    local_1c8 = local_1cc;
    uVar1 = FUN_10014430(local_1cc);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 100));
    local_144 = (**(code **)(*local_18c + 0x30))(local_18c,uVar4,uVar1,piVar2);
    _local_8 = CONCAT31(uStack_7,2);
    FUN_100032d0(&local_1d0);
    if (local_144 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_144,pIVar3,p_Var5);
    }
    local_1c4 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x30));
    uVar1 = FUN_10014430((int *)&DAT_100354d8);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_14c = (**(code **)(*local_1c4 + 0x30))(local_1c4,uVar4,uVar1,piVar2);
    if (local_14c < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_14c,pIVar3,p_Var5);
    }
    local_194 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x2c));
    uVar1 = FUN_10014430((int *)&DAT_100354b4);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_154 = (**(code **)(*local_194 + 0x30))(local_194,uVar4,uVar1,piVar2);
    if (local_154 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_154,pIVar3,p_Var5);
    }
    local_1b8 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x38));
    uVar1 = FUN_10014430((int *)&DAT_10035500);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_15c = (**(code **)(*local_1b8 + 0x30))(local_1b8,uVar4,uVar1,piVar2);
    if (local_15c < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_15c,pIVar3,p_Var5);
    }
    local_19c = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x40));
    uVar1 = FUN_10014430((int *)&DAT_100354fc);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_164 = (**(code **)(*local_19c + 0x30))(local_19c,uVar4,uVar1,piVar2);
    if (local_164 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_164,pIVar3,p_Var5);
    }
    local_1b0 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)local_120);
    uVar1 = FUN_10014430((int *)&DAT_100354b0);
    local_16c = (**(code **)(*local_1b0 + 0x30))(local_1b0,0,uVar1,piVar2);
    if (local_16c < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_16c,pIVar3,p_Var5);
    }
  }
  else {
    local_1a4 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 100));
    uVar1 = FUN_10014430((int *)&DAT_100354dc);
    local_174 = (**(code **)(*local_1a4 + 0x30))(local_1a4,0,uVar1,piVar2);
    if (local_174 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_174,pIVar3,p_Var5);
    }
    FUN_10011ea0(&local_12c,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 ((int)local_11c + 100));
    local_8 = 4;
    FUN_10011fe0(&local_124,
                 (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                 ((int)local_11c + 100));
    local_8 = 5;
    FUN_10013370((undefined4 *)local_130);
    _local_8 = CONCAT31(uStack_7,6);
    local_1b4 = (int *)FUN_10014580(&local_12c);
    local_134 = (**(code **)(*local_1b4 + 0x1c))(local_1b4,param_2);
    if (local_134 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c6b4;
      pIVar3 = (IUnknown *)FUN_10014370(&local_12c);
      _com_issue_errorex(local_134,pIVar3,p_Var5);
    }
    local_1ac = (int *)FUN_10014700(&local_124);
    piVar2 = FID_conflict_operator_((int *)local_130);
    local_184 = (**(code **)(*local_1ac + 0x34))(local_1ac,piVar2);
    if (local_184 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c6a4;
      pIVar3 = (IUnknown *)FUN_100143e0(&local_124);
      _com_issue_errorex(local_184,pIVar3,p_Var5);
    }
    FUN_100126a0((void *)((int)local_11c + 0x28),local_130);
    local_1bc = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x34));
    uVar1 = FUN_10014430((int *)&DAT_100354c0);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_138 = (**(code **)(*local_1bc + 0x30))(local_1bc,uVar4,uVar1,piVar2);
    if (local_138 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_138,pIVar3,p_Var5);
    }
    local_140 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x30));
    uVar1 = FUN_10014430((int *)&DAT_100354d8);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_148 = (**(code **)(*local_140 + 0x30))(local_140,uVar4,uVar1,piVar2);
    if (local_148 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_148,pIVar3,p_Var5);
    }
    local_150 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x2c));
    uVar1 = FUN_10014430((int *)&DAT_100354b4);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_158 = (**(code **)(*local_150 + 0x30))(local_150,uVar4,uVar1,piVar2);
    if (local_158 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_158,pIVar3,p_Var5);
    }
    local_160 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x38));
    uVar1 = FUN_10014430((int *)&DAT_10035500);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_168 = (**(code **)(*local_160 + 0x30))(local_160,uVar4,uVar1,piVar2);
    if (local_168 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_168,pIVar3,p_Var5);
    }
    local_170 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x3c));
    uVar1 = FUN_10014430((int *)&DAT_100354a8);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_178 = (**(code **)(*local_170 + 0x30))(local_170,uVar4,uVar1,piVar2);
    if (local_178 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_178,pIVar3,p_Var5);
    }
    local_180 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)((int)local_11c + 0x40));
    uVar1 = FUN_10014430((int *)&DAT_100354fc);
    uVar4 = FUN_10014390((undefined4 *)((int)local_11c + 0x28));
    local_188 = (**(code **)(*local_180 + 0x30))(local_180,uVar4,uVar1,piVar2);
    if (local_188 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_188,pIVar3,p_Var5);
    }
    local_190 = (int *)FUN_100145b0((int *)((int)local_11c + 0x24));
    piVar2 = FID_conflict_operator_((int *)local_120);
    uVar1 = FUN_10014430((int *)&DAT_100354c8);
    local_198 = (**(code **)(*local_190 + 0x30))(local_190,0,uVar1,piVar2);
    if (local_198 < 0) {
      p_Var5 = (_GUID *)&DAT_1002c674;
      pIVar3 = (IUnknown *)FUN_10014380((undefined4 *)((int)local_11c + 0x24));
      _com_issue_errorex(local_198,pIVar3,p_Var5);
    }
    local_8 = 5;
    FUN_10013b80((int *)local_130);
    local_8 = 4;
    FUN_10013b80(&local_124);
    _local_8 = CONCAT31(uStack_7,2);
    FUN_10013a40(&local_12c);
  }
  FUN_10011e00(&local_128,local_120);
  _local_8 = CONCAT31(uStack_7,7);
  local_1a0 = (int *)FUN_10014550(&local_128);
  local_1a8 = (**(code **)(*local_1a0 + 0x38))(local_1a0,1);
  if (local_1a8 < 0) {
    p_Var5 = (_GUID *)&DAT_1002c6c4;
    pIVar3 = (IUnknown *)FUN_10014360(&local_128);
    _com_issue_errorex(local_1a8,pIVar3,p_Var5);
  }
  FUN_10018730((void *)((int)local_11c + 0x44),local_120);
  local_8 = 2;
  FUN_10013a20(&local_128);
  _local_8 = CONCAT31(uStack_7,1);
  FUN_10013a80((int *)local_120);
  FUN_10017f2f();
  return;
}



// Function: Catch@10017e6e at 10017e6e

undefined * Catch_10017e6e(void)

{
  int unaff_EBP;
  
  throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x1d0),"CIAuditTrailRecord.cpp",0x24a,
               "CCIAuditTrailRecord::Initialize",0x49095b2f4e052ee4,0xaf891c7a2cd8b69a);
  return &DAT_10017f43;
}



// Function: Catch@10017ebc at 10017ebc

undefined * Catch_10017ebc(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x1e0),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  throwExceptionWithFileInfo((void *)(unaff_EBP + -0x1e0),"CIAuditTrailRecord.cpp",0x24a,
               "CCIAuditTrailRecord::Initialize",0x49095b2f4e052ee4,0xaf891c7a2cd8b69a);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uStack0000001c = 0x10017f29;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1e0));
  return &DAT_10017f38;
}



// Function: FUN_10017f2f at 10017f2f

void FUN_10017f2f(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10013a60((int *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10017f71;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10017f80 at 10017f80

void __thiscall FUN_10017f80(void *this,undefined1 param_1)

{
  *(undefined1 *)((int)this + 0x5c) = param_1;
  return;
}



// Function: FUN_10017fa0 at 10017fa0

undefined1 __fastcall FUN_10017fa0(int param_1)

{
  return *(undefined1 *)(param_1 + 0x5c);
}



// Function: FUN_10017fc0 at 10017fc0

void FUN_10017fc0(int *param_1,void *param_2)

{
  uint uVar1;
  IUnknown *pIVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  _GUID *p_Var10;
  undefined4 local_a0 [10];
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
  undefined4 local_4c;
  void *local_48;
  void *local_44;
  long local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  undefined4 local_30;
  long local_2c;
  long local_28;
  int local_24;
  int local_20;
  void *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002418f;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10013860(&local_68);
  local_8 = 0;
  local_14 = 0;
  FUN_10011e00(&local_24,
               (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               (local_18 + 0x28));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_3c = (int *)FUN_10014550(&local_24);
  local_40 = (**(code **)(*local_3c + 0x20))(local_3c,&local_14,uVar1);
  if (local_40 < 0) {
    p_Var10 = (_GUID *)&DAT_1002c6c4;
    pIVar2 = (IUnknown *)FUN_10014360(&local_24);
    _com_issue_errorex(local_40,pIVar2,p_Var10);
  }
  local_44 = (void *)FUN_10020fb4(local_14);
  local_1c = local_44;
  memcpy(local_44,param_2,local_14);
  FUN_1001d320(local_a0);
  local_8._0_1_ = 2;
  FUN_1001d560(local_a0,local_14,local_1c);
  local_48 = local_1c;
  operator_delete__(local_1c);
  puVar3 = (undefined4 *)FUN_1001d420((int)local_a0);
  local_78 = *puVar3;
  local_74 = puVar3[1];
  local_70 = puVar3[2];
  local_6c = puVar3[3];
  FUN_10019010(&local_68,&local_78);
  FUN_10011d60(&local_20,
               (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               (local_18 + 0x28));
  local_8 = CONCAT31(local_8._1_3_,3);
  local_30 = 0;
  local_34 = (int *)FUN_10014520(&local_20);
  local_28 = (**(code **)(*local_34 + 0x1c))(local_34,&local_30);
  if (local_28 < 0) {
    p_Var10 = (_GUID *)&DAT_1002c684;
    pIVar2 = (IUnknown *)FUN_10014350(&local_20);
    _com_issue_errorex(local_28,pIVar2,p_Var10);
  }
  local_58 = local_68;
  local_54 = local_64;
  local_50 = local_60;
  local_4c = local_5c;
  local_38 = (int *)FUN_100146a0(param_1);
  uVar9 = *(undefined4 *)(local_18 + 0x4c);
  uVar5 = local_58;
  uVar6 = local_54;
  uVar7 = local_50;
  uVar8 = local_4c;
  uVar4 = FUN_10014380((undefined4 *)(local_18 + 0x24));
  local_2c = (**(code **)(*local_38 + 0x28))
                       (local_38,1,local_30,0,0,0,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);
  if (local_2c < 0) {
    p_Var10 = (_GUID *)&DAT_1002c694;
    pIVar2 = (IUnknown *)FUN_100143c0(param_1);
    _com_issue_errorex(local_2c,pIVar2,p_Var10);
  }
  local_8._0_1_ = 2;
  FUN_10013a00(&local_20);
  local_8._0_1_ = 1;
  FUN_1001d3a0(local_a0);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013a20(&local_24);
  local_8 = 0xffffffff;
  FUN_10013df0(&local_68);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018210 at 10018210

void __fastcall FUN_10018210(int param_1)

{
  uint uVar1;
  IUnknown *pIVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  _GUID *p_Var11;
  undefined4 local_ac [10];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  void *local_54;
  void *local_50;
  long local_4c;
  long local_48;
  long local_44;
  int *local_40;
  undefined4 local_3c;
  int *local_38;
  long local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  int local_24;
  void *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100241d8;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0;
  local_14 = param_1;
  FUN_10011e00(&local_28,
               (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               (param_1 + 0x28));
  local_8 = 0;
  local_40 = (int *)FUN_10014550(&local_28);
  local_44 = (**(code **)(*local_40 + 0x20))(local_40,&local_1c,uVar1);
  if (local_44 < 0) {
    p_Var11 = (_GUID *)&DAT_1002c6c4;
    pIVar2 = (IUnknown *)FUN_10014360(&local_28);
    _com_issue_errorex(local_44,pIVar2,p_Var11);
  }
  local_50 = (void *)FUN_10020fb4(local_1c);
  local_20 = local_50;
  memset(local_50,0,local_1c);
  FUN_1001d320(local_ac);
  local_8._0_1_ = 1;
  FUN_1001d560(local_ac,local_1c,local_20);
  local_54 = local_20;
  operator_delete__(local_20);
  FUN_10013860(&local_74);
  local_8._0_1_ = 2;
  puVar3 = (undefined4 *)FUN_1001d420((int)local_ac);
  local_84 = *puVar3;
  local_80 = puVar3[1];
  local_7c = puVar3[2];
  local_78 = puVar3[3];
  FUN_10019010(&local_74,&local_84);
  FUN_10011d60(&local_24,
               (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               (local_14 + 0x28));
  local_8 = CONCAT31(local_8._1_3_,3);
  local_3c = 0;
  local_38 = (int *)FUN_10014520(&local_24);
  local_4c = (**(code **)(*local_38 + 0x1c))(local_38,&local_3c);
  if (local_4c < 0) {
    p_Var11 = (_GUID *)&DAT_1002c684;
    pIVar2 = (IUnknown *)FUN_10014350(&local_24);
    _com_issue_errorex(local_4c,pIVar2,p_Var11);
  }
  FUN_10013320(&local_18);
  local_8 = CONCAT31(local_8._1_3_,4);
  local_2c = (int *)FUN_100145b0((int *)(local_14 + 0x24));
  piVar4 = FID_conflict_operator_(&local_18);
  local_48 = (**(code **)(*local_2c + 0x20))(local_2c,piVar4);
  if (local_48 < 0) {
    p_Var11 = (_GUID *)&DAT_1002c674;
    pIVar2 = (IUnknown *)FUN_10014380((undefined4 *)(local_14 + 0x24));
    _com_issue_errorex(local_48,pIVar2,p_Var11);
  }
  local_64 = local_74;
  local_60 = local_70;
  local_5c = local_6c;
  local_58 = local_68;
  local_30 = (int *)FUN_100146a0(&local_18);
  uVar10 = *(undefined4 *)(local_14 + 0x4c);
  uVar6 = local_64;
  uVar7 = local_60;
  uVar8 = local_5c;
  uVar9 = local_58;
  uVar5 = FUN_10014380((undefined4 *)(local_14 + 0x24));
  local_34 = (**(code **)(*local_30 + 0x28))
                       (local_30,1,local_3c,0,0,0,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10);
  if (local_34 < 0) {
    p_Var11 = (_GUID *)&DAT_1002c694;
    pIVar2 = (IUnknown *)FUN_100143c0(&local_18);
    _com_issue_errorex(local_34,pIVar2,p_Var11);
  }
  uVar1 = FUN_1001b550((int *)(local_14 + 0x24));
  if (uVar1 == 1) {
    Sleep(0x3cf);
  }
  local_8._0_1_ = 3;
  FUN_10013b00(&local_18);
  local_8._0_1_ = 2;
  FUN_10013a00(&local_24);
  local_8._0_1_ = 1;
  FUN_10013df0(&local_74);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1001d3a0(local_ac);
  local_8 = 0xffffffff;
  FUN_10013a20(&local_28);
  ExceptionList = local_10;
  return;
}



// Function: CCIAuditTrailRecord_GetLogicalName at 100184e0

void CCIAuditTrailRecord_GetLogicalName(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  IUnknown *pIVar3;
  _GUID *p_Var4;
  uint uStack_94;
  int local_5c;
  int *local_58;
  int local_54;
  int local_50;
  char local_4c [52];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002421f;
  local_10 = ExceptionList;
  uStack_94 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_94;
  ExceptionList = &local_10;
  local_18 = uStack_94;
  FUN_100137a0(&local_50);
  local_8 = 2;
  local_5c = 0;
  piVar1 = (int *)FUN_10014610((int *)(local_54 + 0x44));
  iVar2 = (**(code **)(*piVar1 + 0x24))
                    (piVar1,(double)param_2 + *(double *)(&DAT_1002c7b0 + (param_2 >> 0x1f) * -8));
  if (iVar2 < 0) {
    p_Var4 = (_GUID *)&DAT_1002c6e4;
    pIVar3 = (IUnknown *)FUN_100143a0((undefined4 *)(local_54 + 0x44));
    _com_issue_errorex(iVar2,pIVar3,p_Var4);
  }
  local_58 = (int *)FUN_10014610((int *)(local_54 + 0x44));
  iVar2 = (**(code **)(*local_58 + 0x20))(local_58,&local_5c);
  if (iVar2 < 0) {
    p_Var4 = (_GUID *)&DAT_1002c6e4;
    pIVar3 = (IUnknown *)FUN_100143a0((undefined4 *)(local_54 + 0x44));
    _com_issue_errorex(iVar2,pIVar3,p_Var4);
  }
  FUN_100191b0(&local_50,local_5c);
  iVar2 = FUN_10015cb0(&local_50);
  if (iVar2 == 0) {
    sprintf(local_4c,"ChangeCodeBit%u",param_2);
    FUN_10013e90(&local_50,local_4c);
  }
  FUN_100186cd();
  return;
}



// Function: Catch@10018618 at 10018618

undefined * Catch_10018618(void)

{
  int unaff_EBP;
  
  throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x70),"CIAuditTrailRecord.cpp",0x2a9,
               "CCIAuditTrailRecord::GetLogicalName",0x49095b2f4e052ee4,0xaf891c7a2cd8b69a);
  return &DAT_100186e1;
}



// Function: Catch@10018661 at 10018661

undefined * Catch_10018661(void)

{
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  _com_error::_com_error((_com_error *)(unaff_EBP + -0x80),-0x7fff0001,(IErrorInfo *)0x0,false);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  throwExceptionWithFileInfo((void *)(unaff_EBP + -0x80),"CIAuditTrailRecord.cpp",0x2a9,
               "CCIAuditTrailRecord::GetLogicalName",0x49095b2f4e052ee4,0xaf891c7a2cd8b69a);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uStack0000001c = 0x100186c7;
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x80));
  return &DAT_100186d6;
}



// Function: FUN_100186cd at 100186cd

void FUN_100186cd(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            (*(refcount_ptr<struct_boost::exception_detail::error_info_container> **)(unaff_EBP + 8)
             ,(refcount_ptr<struct_boost::exception_detail::error_info_container> *)
              (unaff_EBP - 0x4c));
  *(uint *)(unaff_EBP - 0x5c) = *(uint *)(unaff_EBP - 0x5c) | 1;
  *(undefined1 *)(unaff_EBP - 4) = 0;
  FUN_100032d0((int *)(unaff_EBP - 0x4c));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10018724;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10018730 at 10018730

void * __thiscall
FUN_10018730(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024258;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10012ba0();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100187c0 at 100187c0

void * __thiscall
FUN_100187c0(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024288;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_10018920();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10018850 at 10018850

void * __cdecl FUN_10018850(uint param_1)

{
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x3fffffff < param_1 || (local_8 = operator_new(param_1 << 2), local_8 == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  return local_8;
}



// Function: _Destroy_range<> at 100188a0

/* Library Function - Multiple Matches With Same Base Name
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > >(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,struct
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > &)
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > &)
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   Concurrency::details::_ContextCallback> > >(class Concurrency::details::_ContextCallback *,class
   Concurrency::details::_ContextCallback *,struct std::_Wrap_alloc<class std::allocator<class
   Concurrency::details::_ContextCallback> > &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __cdecl _Destroy_range<>(void *param_1,void *param_2,void *param_3)

{
  _Ptr_cat<>(param_1);
  _Destroy_range<>(param_1,param_2,param_3);
  return;
}



// Function: _Destroy_range<> at 100188e0

/* Library Function - Multiple Matches With Same Base Name
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > >(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,struct
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > &,struct std::_Nonscalar_ptr_iterator_tag)
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Wrap_alloc<class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > &,struct
   std::_Nonscalar_ptr_iterator_tag)
    void __cdecl std::_Destroy_range<struct std::_Wrap_alloc<class std::allocator<class
   Concurrency::details::_ContextCallback> > >(class Concurrency::details::_ContextCallback *,class
   Concurrency::details::_ContextCallback *,struct std::_Wrap_alloc<class std::allocator<class
   Concurrency::details::_ContextCallback> > &,struct std::_Nonscalar_ptr_iterator_tag)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __cdecl _Destroy_range<>(void *param_1,void *param_2,void *param_3)

{
  for (; param_1 != param_2; param_1 = (void *)((int)param_1 + 4)) {
    destroy<>(param_3,param_1);
  }
  return;
}



// Function: _Ptr_cat<> at 10018910

/* Library Function - Multiple Matches With Same Base Name
    struct std::_Nonscalar_ptr_iterator_tag __cdecl std::_Ptr_cat<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *)
    struct std::_Nonscalar_ptr_iterator_tag __cdecl std::_Ptr_cat<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined1 __fastcall _Ptr_cat<>(undefined4 param_1)

{
  undefined1 local_5;
  
  local_5 = (undefined1)((uint)param_1 >> 0x18);
  return local_5;
}



// Function: FUN_10018920 at 10018920

int FUN_10018920(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100242b8;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_100142b0(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_10014700((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_10015260();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013b80((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: _Umove<> at 100189f0

/* Library Function - Multiple Matches With Same Base Name
    protected: class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *
   __thiscall std::vector<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned
   char> >,class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > >::_Umove<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *>(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *)
    protected: class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > * __thiscall
   std::vector<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > >,class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > >
   >::_Umove<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > *>(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void _Umove<>(int param_1,int param_2,int param_3)

{
  undefined1 local_5;
  
  Getal(&local_5);
  _Uninitialized_move<>(param_1,param_2,param_3,&local_5);
  return;
}



// Function: FUN_10018a30 at 10018a30

void FUN_10018a30(int param_1,int param_2,int param_3,void *param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100242e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    construct<>(param_4,param_3,param_1);
    param_3 = param_3 + 4;
  }
  FUN_10018ac7();
  return;
}



// Function: FUN_10018a99 at 10018a99

void FUN_10018a99(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    destroy<>(*(void **)(unaff_EBP + 0x14),*(void **)(unaff_EBP + -0x14));
    FUN_10018a99();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10018aa2 at 10018aa2

void FUN_10018aa2(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    destroy<>(*(void **)(unaff_EBP + 0x14),*(void **)(unaff_EBP + -0x14));
    FUN_10018a99();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10018ac7 at 10018ac7

undefined4 FUN_10018ac7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 0x10);
}



// Function: _Uninitialized_move<> at 10018af0

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
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __cdecl _Uninitialized_move<>(int param_1,int param_2,int param_3,void *param_4)

{
  _Ptr_cat<>(param_1);
  _Val_type<>();
  FUN_10018a30(param_1,param_2,param_3,param_4);
  return;
}



// Function: _Val_type<> at 10018b40

/* Library Function - Multiple Matches With Same Base Name
    class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > * __cdecl
   std::_Val_type<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   *>(class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __cdecl std::_Val_type<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *>(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 _Val_type<>(void)

{
  return 0;
}



// Function: FUN_10018b50 at 10018b50

undefined4 __cdecl FUN_10018b50(undefined4 param_1)

{
  return param_1;
}



// Function: construct<> at 10018b60

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<char> >::construct<char *,char *
   &>(char * *,char * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::construct<unsigned short *,unsigned short * &>(unsigned short * *,unsigned short * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<wchar_t> >::construct<wchar_t
   *,wchar_t * &>(wchar_t * *,wchar_t * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<struct std::_Container_proxy>
   >::construct<struct std::_Container_proxy,struct std::_Container_proxy>(struct
   std::_Container_proxy *,struct std::_Container_proxy &&)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

void __thiscall construct<>(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_2);
  construct<>(this,param_1,uVar1);
  return;
}



// Function: construct<> at 10018b90

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >::construct<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > &&)
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >::construct<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > &&)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void construct<>(undefined4 param_1,undefined4 param_2)

{
  refcount_ptr<struct_boost::exception_detail::error_info_container> *this;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *prVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024311;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)forward<>(4,param_1);
  local_8 = 0;
  if (this != (refcount_ptr<struct_boost::exception_detail::error_info_container> *)0x0) {
    prVar1 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
             forward<>(param_2);
    boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
    refcount_ptr<struct_boost::exception_detail::error_info_container>(this,prVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: construct<> at 10018c20

/* Library Function - Multiple Matches With Same Base Name
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::construct<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >(class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   &,class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > &&)
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::construct<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > &,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > &&)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __cdecl construct<>(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_3);
  construct<>(param_2,uVar1);
  return;
}



// Function: construct<> at 10018c40

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<char> >::construct<char *,char *
   &>(char * *,char * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::construct<unsigned short *,unsigned short * &>(unsigned short * *,unsigned short * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<wchar_t> >::construct<wchar_t
   *,wchar_t * &>(wchar_t * *,wchar_t * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<struct std::_Container_proxy>
   >::construct<struct std::_Container_proxy,struct std::_Container_proxy>(struct
   std::_Container_proxy *,struct std::_Container_proxy &&)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

void __thiscall construct<>(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_2);
  construct<>(this,param_1,uVar1);
  return;
}



// Function: construct<> at 10018c70

/* Library Function - Multiple Matches With Same Base Name
    public: static void __cdecl std::allocator_traits<class std::allocator<char> >::construct<char
   *,char * &>(class std::allocator<char> &,char * *,char * &)
    public: static void __cdecl std::allocator_traits<class std::allocator<unsigned short>
   >::construct<unsigned short *,unsigned short * &>(class std::allocator<unsigned short> &,unsigned
   short * *,unsigned short * &)
    public: static void __cdecl std::allocator_traits<class std::allocator<wchar_t>
   >::construct<wchar_t *,wchar_t * &>(class std::allocator<wchar_t> &,wchar_t * *,wchar_t * &)
    public: static void __cdecl std::allocator_traits<class std::allocator<struct
   std::_Container_proxy> >::construct<struct std::_Container_proxy,struct
   std::_Container_proxy>(class std::allocator<struct std::_Container_proxy> &,struct
   std::_Container_proxy *,struct std::_Container_proxy &&)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

void __cdecl construct<>(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  refcount_ptr<struct_boost::exception_detail::error_info_container> *prVar1;
  
  prVar1 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)forward<>(param_3);
  FUN_10019700(param_2,prVar1);
  return;
}



// Function: construct<> at 10018c90

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<char> >::construct<char *,char *
   &>(char * *,char * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::construct<unsigned short *,unsigned short * &>(unsigned short * *,unsigned short * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<wchar_t> >::construct<wchar_t
   *,wchar_t * &>(wchar_t * *,wchar_t * &)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<struct std::_Container_proxy>
   >::construct<struct std::_Container_proxy,struct std::_Container_proxy>(struct
   std::_Container_proxy *,struct std::_Container_proxy &&)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

void __thiscall construct<>(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_2);
  construct<>(this,param_1,uVar1);
  return;
}



// Function: construct<> at 10018cc0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >::construct<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > &&)
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >::construct<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > &&)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void construct<>(undefined4 param_1,undefined4 param_2)

{
  refcount_ptr<struct_boost::exception_detail::error_info_container> *this;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *prVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024341;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)forward<>(4,param_1);
  local_8 = 0;
  if (this != (refcount_ptr<struct_boost::exception_detail::error_info_container> *)0x0) {
    prVar1 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
             forward<>(param_2);
    boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
    refcount_ptr<struct_boost::exception_detail::error_info_container>(this,prVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: construct<> at 10018d50

/* Library Function - Multiple Matches With Same Base Name
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::construct<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >(class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   &,class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > &&)
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::construct<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > &,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > &&)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __cdecl construct<>(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_3);
  construct<>(param_2,uVar1);
  return;
}



// Function: destroy<> at 10018d70

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > >::destroy<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::destroy<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<class
   Concurrency::details::_ContextCallback> >::destroy<class
   Concurrency::details::_ContextCallback>(class Concurrency::details::_ContextCallback *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void __thiscall destroy<>(void *this,void *param_1)

{
  destroy<>(this,param_1);
  return;
}



// Function: destroy<> at 10018d90

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >::destroy<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *)
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >::destroy<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void destroy<>(void *param_1)

{
  FUN_10019160(param_1,0);
  return;
}



// Function: destroy<> at 10018db0

/* Library Function - Multiple Matches With Same Base Name
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::_Func_impl<bool (__cdecl*)(enum Concurrency::agent_status const &),class
   std::allocator<int>,bool,enum Concurrency::agent_status const &> > >::destroy<class
   std::_Func_impl<bool (__cdecl*)(enum Concurrency::agent_status const &),class
   std::allocator<int>,bool,enum Concurrency::agent_status const &> >(class std::allocator<class
   std::_Func_impl<bool (__cdecl*)(enum Concurrency::agent_status const &),class
   std::allocator<int>,bool,enum Concurrency::agent_status const &> > &,class std::_Func_impl<bool
   (__cdecl*)(enum Concurrency::agent_status const &),class std::allocator<int>,bool,enum
   Concurrency::agent_status const &> *)
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::_Func_impl<class <lambda_0b644b0099f9cbc573e00435de85ed83>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> > >::destroy<class
   std::_Func_impl<class <lambda_0b644b0099f9cbc573e00435de85ed83>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> >(class std::allocator<class
   std::_Func_impl<class <lambda_0b644b0099f9cbc573e00435de85ed83>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> > &,class
   std::_Func_impl<class <lambda_0b644b0099f9cbc573e00435de85ed83>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> *)
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::_Func_impl<class <lambda_4471c1faea23acf00f5de6f001106c5d>,class
   std::allocator<int>,void,class Concurrency::message<enum Concurrency::agent_status> *> >
   >::destroy<class std::_Func_impl<class <lambda_4471c1faea23acf00f5de6f001106c5d>,class
   std::allocator<int>,void,class Concurrency::message<enum Concurrency::agent_status> *> >(class
   std::allocator<class std::_Func_impl<class <lambda_4471c1faea23acf00f5de6f001106c5d>,class
   std::allocator<int>,void,class Concurrency::message<enum Concurrency::agent_status> *> > &,class
   std::_Func_impl<class <lambda_4471c1faea23acf00f5de6f001106c5d>,class
   std::allocator<int>,void,class Concurrency::message<enum Concurrency::agent_status> *> *)
    public: static void __cdecl std::allocator_traits<class std::allocator<class
   std::_Func_impl<class <lambda_585d1183dd7288406f8b545e733d6ea7>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> > >::destroy<class
   std::_Func_impl<class <lambda_585d1183dd7288406f8b545e733d6ea7>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> >(class std::allocator<class
   std::_Func_impl<class <lambda_585d1183dd7288406f8b545e733d6ea7>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> > &,class
   std::_Func_impl<class <lambda_585d1183dd7288406f8b545e733d6ea7>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *> *)
     9 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

void __cdecl destroy<>(undefined4 param_1,void *param_2)

{
  destroy<>(param_2);
  return;
}



// Function: forward<> at 10018dd0

/* Library Function - Multiple Matches With Same Base Name
    class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > && __cdecl
   std::forward<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   >(class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > &)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > && __cdecl std::forward<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 __cdecl forward<>(undefined4 param_1)

{
  return param_1;
}



// Function: forward<> at 10018de0

/* Library Function - Multiple Matches With Same Base Name
    char * & __cdecl std::forward<char * &>(char * &)
    unsigned short * & __cdecl std::forward<unsigned short * &>(unsigned short * &)
    wchar_t * & __cdecl std::forward<wchar_t * &>(wchar_t * &)
    struct std::_Container_proxy && __cdecl std::forward<struct std::_Container_proxy>(struct
   std::_Container_proxy &)
     6 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release, Visual Studio 2015 Debug, Visual
   Studio 2015 Release */

undefined4 __cdecl forward<>(undefined4 param_1)

{
  return param_1;
}



// Function: forward<> at 10018df0

/* Library Function - Multiple Matches With Same Base Name
    class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > && __cdecl
   std::forward<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   >(class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > &)
    class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > && __cdecl std::forward<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 __cdecl forward<>(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10018e00 at 10018e00

undefined4 __fastcall FUN_10018e00(undefined4 param_1)

{
  FUN_10018f80(param_1);
  return param_1;
}



// Function: _Vector_alloc<> at 10018e20

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_Vector_alloc<0,struct std::_Vec_base_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >
   >::_Vector_alloc<0,struct std::_Vec_base_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > >(class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   const &)
    public: __thiscall std::_Vector_alloc<0,struct std::_Vec_base_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >::_Vector_alloc<0,struct
   std::_Vec_base_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > >,class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > > >(class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > const &)
   
   Library: Visual Studio 2012 Release */

undefined4 * __fastcall _Vector_alloc<>(undefined4 *param_1)

{
  _Vector_val<>(param_1);
  return param_1;
}



// Function: FID_conflict:_Vector_const_iterator<class_std::_Vector_val<struct_std::_Simple_types<class_std::shared_ptr<struct_Concurrency::details::_Task_impl<struct_std::pair<unsigned_char,class_Concurrency::details::_CancellationTokenState*>_>_>_>_>_> at 10018e40

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<char> > >::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<char> > >(char const *,struct std::_Container_base0 const *)
    public: __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<unsigned short> > >::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<unsigned short> > >(unsigned short const *,struct std::_Container_base0 const
   *)
    public: __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<wchar_t> > >::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<wchar_t> > >(wchar_t const *,struct std::_Container_base0 const *)
    public: __thiscall std::_Vector_const_iterator<class std::_Vector_val<struct
   std::_Simple_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   > > >::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > >(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,struct
   std::_Container_base0 const *)
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

undefined4 * __thiscall
FID_conflict__Vector_const_iterator<class_std::_Vector_val<struct_std::_Simple_types<class_std::shared_ptr<struct_Concurrency::details::_Task_impl<struct_std::pair<unsigned_char,class_Concurrency::details::_CancellationTokenState*>_>_>_>_>_>
          (void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_100192f0();
  return (undefined4 *)this;
}



// Function: FUN_10018e70 at 10018e70

undefined4 * __fastcall FUN_10018e70(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: _Vector_iterator<> at 10018e90

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >
   >::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,struct std::_Container_base0 const *)
    public: __thiscall std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >::_Vector_iterator<class
   std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > >(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,struct std::_Container_base0 const *)
   
   Library: Visual Studio 2012 Release */

void * __thiscall _Vector_iterator<>(void *this,undefined4 param_1)

{
  FID_conflict__Vector_const_iterator<class_std::_Vector_val<struct_std::_Simple_types<class_std::shared_ptr<struct_Concurrency::details::_Task_impl<struct_std::pair<unsigned_char,class_Concurrency::details::_CancellationTokenState*>_>_>_>_>_>
            (this,param_1);
  return this;
}



// Function: FUN_10018eb0 at 10018eb0

undefined4 * __fastcall FUN_10018eb0(undefined4 *param_1)

{
  FUN_10018e70(param_1);
  return param_1;
}



// Function: _Vector_val<> at 10018ed0

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > >::_Vector_val<struct
   std::_Simple_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   > >(void)
    public: __thiscall std::_Vector_val<struct std::_Simple_types<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::_Vector_val<struct
   std::_Simple_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > >(void)
   
   Library: Visual Studio 2012 Release */

undefined4 * __fastcall _Vector_val<>(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_10018f00 at 10018f00

undefined4 __fastcall FUN_10018f00(undefined4 param_1)

{
  allocator<>(param_1);
  return param_1;
}



// Function: FUN_10018f20 at 10018f20

undefined4 * __fastcall FUN_10018f20(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: allocator<> at 10018f40

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >(void)
    public: __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 __fastcall allocator<>(undefined4 param_1)

{
  return param_1;
}



// Function: vector<> at 10018f50

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::vector<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >,class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   >(void)
    public: __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >(void)
   
   Library: Visual Studio 2012 Release */

undefined4 * __fastcall vector<>(undefined4 *param_1)

{
  undefined1 local_5;
  
  allocator<>(&local_5);
  _Vector_alloc<>(param_1);
  return param_1;
}



// Function: FUN_10018f80 at 10018f80

undefined4 __fastcall FUN_10018f80(undefined4 param_1)

{
  FUN_10013620(param_1);
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 10018fa0

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_100192d0((int *)this);
  return this;
}



// Function: FUN_10018fd0 at 10018fd0

void __fastcall FUN_10018fd0(_Container_base0 *param_1)

{
  FUN_100195b0(param_1);
  return;
}



// Function: FUN_10018ff0 at 10018ff0

void __thiscall FUN_10018ff0(void *this,int *param_1)

{
  FID_conflict_operator_(this,*param_1);
  return;
}



// Function: FUN_10019010 at 10019010

void * __thiscall FUN_10019010(void *this,undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_10(this,param_1);
  FUN_10014a90(iVar1);
  return this;
}



// Function: FID_conflict:operator== at 10019040

/* Library Function - Multiple Matches With Different Base Names
    public: bool __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<char> > >::operator==(class std::_String_const_iterator<class
   std::_String_val<struct std::_Simple_types<char> > > const &)const 
    public: bool __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<unsigned short> > >::operator==(class std::_String_const_iterator<class
   std::_String_val<struct std::_Simple_types<unsigned short> > > const &)const 
    public: bool __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<wchar_t> > >::operator==(class std::_String_const_iterator<class
   std::_String_val<struct std::_Simple_types<wchar_t> > > const &)const 
    public: bool __thiscall std::_Vector_const_iterator<class std::_Vector_val<struct
   std::_Simple_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   > > >::operator==(class std::_Vector_const_iterator<class std::_Vector_val<struct
   std::_Simple_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   > > > const &)const 
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

undefined4 __thiscall FID_conflict_operator__(void *this,int *param_1)

{
  FUN_10019300();
                    /* WARNING: Load size is inaccurate */
  return CONCAT31((int3)((uint)*this >> 8),*this == *param_1);
}



// Function: FID_conflict:operator!= at 10019080

/* Library Function - Multiple Matches With Different Base Names
    public: bool __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<char> > >::operator!=(class std::_String_const_iterator<class
   std::_String_val<struct std::_Simple_types<char> > > const &)const 
    public: bool __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<unsigned short> > >::operator!=(class std::_String_const_iterator<class
   std::_String_val<struct std::_Simple_types<unsigned short> > > const &)const 
    public: bool __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<wchar_t> > >::operator!=(class std::_String_const_iterator<class
   std::_String_val<struct std::_Simple_types<wchar_t> > > const &)const 
    public: bool __thiscall std::_Vector_const_iterator<class std::_Vector_val<struct
   std::_Simple_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   > > >::operator!=(class std::_Vector_const_iterator<class std::_Vector_val<struct
   std::_Simple_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >
   > > > const &)const 
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

bool __thiscall FID_conflict_operator__(void *this,int *param_1)

{
  uint uVar1;
  
  uVar1 = FID_conflict_operator__(this,param_1);
  return (uVar1 & 0xff) == 0;
}



// Function: FUN_100190c0 at 100190c0

undefined4 __fastcall FUN_100190c0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100190d0 at 100190d0

void __fastcall FUN_100190d0(undefined4 *param_1)

{
  FUN_100190c0(param_1);
  return;
}



// Function: FUN_100190f0 at 100190f0

int * __fastcall FUN_100190f0(int *param_1)

{
  *param_1 = *param_1 + 4;
  return param_1;
}



// Function: FUN_10019110 at 10019110

int * __thiscall FUN_10019110(void *this,int *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  FUN_10019140((int *)this);
  *param_1 = iVar1;
  return param_1;
}



// Function: FUN_10019140 at 10019140

int * __fastcall FUN_10019140(int *param_1)

{
  FUN_100190f0(param_1);
  return param_1;
}



// Function: FUN_10019160 at 10019160

int * __thiscall FUN_10019160(void *this,uint param_1)

{
  FUN_100032d0((int *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_10019190 at 10019190

undefined4 __fastcall FUN_10019190(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100191b0 at 100191b0

void __thiscall FUN_100191b0(void *this,int param_1)

{
  int *piVar1;
  void *this_00;
  int *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002436b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  if (((param_1 != 0) && (*this != 0)) && (piVar1 = (int *)FUN_10015380(*this), *piVar1 == param_1))
  {
    ExceptionList = local_10;
    return;
  }
  Clear((int *)this);
  this_00 = (void *)FUN_10003370(0xc);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_1c = (int *)0x0;
  }
  else {
    local_1c = FUN_10013520(this_00,param_1,'\x01');
  }
  local_8 = 0xffffffff;
  *(int **)this = local_1c;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10019270 at 10019270

int __fastcall FUN_10019270(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    iVar2 = 0;
  }
  else {
    uVar1 = Ordinal_149(*param_1);
    iVar2 = Ordinal_150(*param_1,uVar1);
    if (iVar2 == 0) {
      _com_issue_error(-0x7ff8fff2);
    }
  }
  return iVar2;
}



// Function: FUN_100192c0 at 100192c0

undefined * FUN_100192c0(void)

{
  return &DAT_10029a2c;
}



// Function: FUN_100192d0 at 100192d0

void __fastcall FUN_100192d0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_10019190(*param_1);
  }
  return;
}



// Function: FUN_100192f0 at 100192f0

void FUN_100192f0(void)

{
  return;
}



// Function: FUN_10019300 at 10019300

void FUN_10019300(void)

{
  return;
}



// Function: FID_conflict:_Destroy at 10019310

/* Library Function - Multiple Matches With Different Base Names
    protected: void __thiscall std::vector<unsigned char,class std::allocator<unsigned char>
   >::_Destroy(unsigned char *,unsigned char *)
    protected: void __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::_Destroy(class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *,class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *)
    protected: void __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::_Destroy(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *,class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > *)
    protected: void __thiscall std::vector<class Concurrency::details::_ContextCallback,class
   std::allocator<class Concurrency::details::_ContextCallback> >::_Destroy(class
   Concurrency::details::_ContextCallback *,class Concurrency::details::_ContextCallback *)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void FID_conflict__Destroy(void *param_1,void *param_2)

{
  undefined1 local_5;
  
  Getal(&local_5);
  _Destroy_range<>(param_1,param_2,&local_5);
  return;
}



// Function: Getal at 10019340

/* Library Function - Multiple Matches With Same Base Name
    public: struct std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > > __thiscall std::_Vector_alloc<0,struct
   std::_Vec_base_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char>
   >,class std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned
   char> > > > >::_Getal(void)const 
    public: struct std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > __thiscall std::_Vector_alloc<0,struct
   std::_Vec_base_types<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > >,class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<struct
   std::pair<unsigned char,class Concurrency::details::_CancellationTokenState *> > > > >
   >::_Getal(void)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined4 Getal(undefined4 param_1)

{
  FUN_10018f00(param_1);
  return param_1;
}



// Function: FID_conflict:_Grow_to at 10019360

/* Library Function - Multiple Matches With Different Base Names
    protected: unsigned int __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::_Grow_to(unsigned
   int)const 
    protected: unsigned int __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::_Grow_to(unsigned int)const 
   
   Library: Visual Studio 2012 Release */

uint __thiscall FID_conflict__Grow_to(void *this,uint param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_8;
  
  local_10 = FID_conflict_capacity((int *)this);
  iVar1 = FID_conflict_max_size();
  if (iVar1 - (local_10 >> 1) < local_10) {
    local_10 = 0;
  }
  else {
    local_10 = (local_10 >> 1) + local_10;
  }
  local_8 = local_10;
  if (local_10 < param_1) {
    local_8 = param_1;
  }
  return local_8;
}



// Function: FUN_100193c0 at 100193c0

undefined1 __thiscall FUN_100193c0(void *this,uint param_1)

{
  undefined1 local_c;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < *(uint *)((int)this + 4)) && (*this <= param_1)) {
    local_c = 1;
  }
  else {
    local_c = 0;
  }
  return local_c;
}



// Function: FUN_10019400 at 10019400

void FUN_10019400(void)

{
  return;
}



// Function: FUN_10019410 at 10019410

void __thiscall FUN_10019410(void *this,uint param_1)

{
  int iVar1;
  uint uStack_34;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024390;
  local_10 = ExceptionList;
  uStack_34 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  Getal(&local_15);
  iVar1 = allocate(param_1);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  _Umove<>(*this,*(int *)((int)this + 4),iVar1);
  FUN_100194a5();
  return;
}



// Function: Catch@1001947b at 1001947b

void Catch_1001947b(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  pvVar1 = *(void **)(unaff_EBP + -0x1c);
  Getal(unaff_EBP + -0x12);
  deallocate(pvVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100194a5 at 100194a5

void FUN_100194a5(void)

{
  int iVar1;
  int unaff_EBP;
  void *pvVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = size(*(int **)(unaff_EBP + -0x18));
  *(int *)(unaff_EBP + -0x20) = iVar1;
  if (**(int **)(unaff_EBP + -0x18) != 0) {
    FID_conflict__Destroy
              ((void *)**(undefined4 **)(unaff_EBP + -0x18),
               *(void **)(*(int *)(unaff_EBP + -0x18) + 4));
    pvVar2 = (void *)**(undefined4 **)(unaff_EBP + -0x18);
    Getal(unaff_EBP + -0x13);
    deallocate(pvVar2);
  }
  std::_Container_base0::_Orphan_all(*(_Container_base0 **)(unaff_EBP + -0x18));
  *(int *)(*(int *)(unaff_EBP + -0x18) + 8) =
       *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + 8) * 4;
  *(int *)(*(int *)(unaff_EBP + -0x18) + 4) =
       *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x20) * 4;
  **(undefined4 **)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x1c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10019550 at 10019550

void __thiscall FUN_10019550(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_10019630((int)this);
  if (uVar1 < param_1) {
    iVar2 = FID_conflict_max_size();
    iVar3 = size((int *)this);
    if ((uint)(iVar2 - iVar3) < param_1) {
      FUN_10019650();
    }
    iVar2 = size((int *)this);
    uVar1 = FID_conflict__Grow_to(this,iVar2 + param_1);
    FUN_10019410(this,uVar1);
  }
  return;
}



// Function: FUN_100195b0 at 100195b0

void __fastcall FUN_100195b0(_Container_base0 *param_1)

{
  void *pvVar1;
  undefined1 local_5;
  
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FID_conflict__Destroy(*(void **)param_1,*(void **)(param_1 + 4));
    pvVar1 = *(void **)param_1;
    Getal(&local_5);
    deallocate(pvVar1);
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}



// Function: FUN_10019630 at 10019630

int __fastcall FUN_10019630(int param_1)

{
  return *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
}



// Function: FUN_10019650 at 10019650

void FUN_10019650(void)

{
  std::_Xlength_error("vector<T> too long");
  return;
}



// Function: allocate at 10019670

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall std::_Wrap_alloc<class std::allocator<char> >::allocate(unsigned int)
    public: unsigned short * __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *
   __thiscall std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > >::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __thiscall
   std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::allocate(unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void allocate(uint param_1)

{
  allocate(param_1);
  return;
}



// Function: allocate at 10019690

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall std::allocator<char>::allocate(unsigned int)
    public: unsigned short * __thiscall std::allocator<unsigned short>::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > *
   __thiscall std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned
   char> > >::allocate(unsigned int)
    public: class std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned
   char,class Concurrency::details::_CancellationTokenState *> > > * __thiscall std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > >::allocate(unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void allocate(uint param_1)

{
  FUN_10018850(param_1);
  return;
}



// Function: FID_conflict:begin at 100196b0

/* Library Function - Multiple Matches With Different Base Names
    public: class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > > __thiscall
   std::vector<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >,class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   >::begin(void)
    public: class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > > __thiscall std::vector<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::begin(void)
   
   Library: Visual Studio 2012 Release */

void * __thiscall FID_conflict_begin(void *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  _Vector_iterator<>(param_1,*this);
  return param_1;
}



// Function: FID_conflict:capacity at 100196e0

/* Library Function - Multiple Matches With Different Base Names
    public: unsigned int __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::capacity(void)const
   
    public: unsigned int __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::capacity(void)const 
   
   Library: Visual Studio 2012 Release */

int __fastcall FID_conflict_capacity(int *param_1)

{
  return param_1[2] - *param_1 >> 2;
}



// Function: FUN_10019700 at 10019700

void FUN_10019700(undefined4 param_1,
                 refcount_ptr<struct_boost::exception_detail::error_info_container> *param_2)

{
  refcount_ptr<struct_boost::exception_detail::error_info_container> *this;
  
  this = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)forward<>(4,param_1);
  if (this != (refcount_ptr<struct_boost::exception_detail::error_info_container> *)0x0) {
    boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
    refcount_ptr<struct_boost::exception_detail::error_info_container>(this,param_2);
  }
  return;
}



// Function: FUN_10019740 at 10019740

int __thiscall FUN_10019740(void *this,char param_1)

{
  int *piVar1;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    local_10 = 0;
  }
  else {
    if (param_1 == '\0') {
                    /* WARNING: Load size is inaccurate */
      piVar1 = (int *)FUN_10015380(*this);
      local_c = *piVar1;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      local_c = FUN_10019270(*this);
    }
    local_10 = local_c;
  }
  return local_10;
}



// Function: deallocate at 10019790

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::_Wrap_alloc<class std::allocator<char> >::deallocate(char
   *,unsigned int)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned char>
   >::deallocate(unsigned char *,unsigned int)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<unsigned short>
   >::deallocate(unsigned short *,unsigned int)
    public: void __thiscall std::_Wrap_alloc<class std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > > >::deallocate(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,unsigned int)
     7 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void deallocate(void *param_1)

{
  deallocate(param_1);
  return;
}



// Function: deallocate at 100197b0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall std::allocator<char>::deallocate(char *,unsigned int)
    public: void __thiscall std::allocator<unsigned char>::deallocate(unsigned char *,unsigned int)
    public: void __thiscall std::allocator<unsigned short>::deallocate(unsigned short *,unsigned
   int)
    public: void __thiscall std::allocator<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > >::deallocate(class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> > *,unsigned int)
     7 names - too many to list
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void deallocate(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FID_conflict:begin at 100197d0

/* Library Function - Multiple Matches With Different Base Names
    public: class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > > __thiscall
   std::vector<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >,class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   >::begin(void)
    public: class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > > __thiscall std::vector<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::begin(void)
    public: class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > > > __thiscall
   std::vector<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> >,class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   >::end(void)
    public: class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > > > __thiscall std::vector<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::end(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void * __thiscall FID_conflict_begin(void *this,void *param_1)

{
  _Vector_iterator<>(param_1,*(undefined4 *)((int)this + 4));
  return param_1;
}



// Function: max_size at 10019800

/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::max_size(void)const
   
    public: unsigned int __thiscall std::_Wrap_alloc<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::max_size(void)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void max_size(void)

{
  max_size();
  return;
}



// Function: FUN_10019820 at 10019820

undefined4 FUN_10019820(void)

{
  return 0x3fffffff;
}



// Function: max_size at 10019830

/* Library Function - Multiple Matches With Same Base Name
    public: static unsigned int __cdecl std::allocator_traits<class std::allocator<unsigned short>
   >::max_size(class std::allocator<unsigned short> const &)
    public: static unsigned int __cdecl std::allocator_traits<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::max_size(class
   std::allocator<class std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > >
   const &)
    public: static unsigned int __cdecl std::allocator_traits<class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::max_size(class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > const &)
    public: static unsigned int __cdecl std::allocator_traits<class std::allocator<wchar_t>
   >::max_size(class std::allocator<wchar_t> const &)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void max_size(void)

{
  FUN_10019820();
  return;
}



// Function: FID_conflict:max_size at 10019840

/* Library Function - Multiple Matches With Different Base Names
    public: unsigned int __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<unsigned char> >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<unsigned char> > > >::max_size(void)const
   
    public: unsigned int __thiscall std::vector<class std::shared_ptr<struct
   Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > >,class std::allocator<class
   std::shared_ptr<struct Concurrency::details::_Task_impl<struct std::pair<unsigned char,class
   Concurrency::details::_CancellationTokenState *> > > > >::max_size(void)const 
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

void FID_conflict_max_size(void)

{
  undefined1 local_5;
  
  Getal(&local_5);
  max_size();
  return;
}



// Function: FUN_10019860 at 10019860

void __thiscall FUN_10019860(void *this,undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 local_6;
  undefined1 local_5;
  
  uVar2 = FUN_10018b50(param_1);
  cVar1 = FUN_100193c0(this,uVar2);
  if (cVar1 == '\0') {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_10019550(this,1);
    }
    FUN_10019400();
    uVar5 = *(undefined4 *)((int)this + 4);
    pvVar4 = (void *)Getal(&local_6);
    construct<>(pvVar4,uVar5,param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  else {
    iVar3 = FUN_10018b50(param_1);
                    /* WARNING: Load size is inaccurate */
    iVar6 = *this;
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_10019550(this,1);
    }
    FUN_10019400();
                    /* WARNING: Load size is inaccurate */
    iVar6 = *this + (iVar3 - iVar6 >> 2) * 4;
    uVar5 = *(undefined4 *)((int)this + 4);
    pvVar4 = (void *)Getal(&local_5);
    construct<>(pvVar4,uVar5,iVar6);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  }
  return;
}



// Function: size at 10019970

/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall `anonymous namespace'::argument_list<char>::size(void)const 
    public: unsigned int __thiscall `anonymous namespace'::argument_list<char>::size(void)const 
    public: unsigned int __thiscall `anonymous namespace'::argument_list<char>::size(void)const 
    public: unsigned int __thiscall `anonymous namespace'::argument_list<wchar_t>::size(void)const 
     6 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2017 Debug, Visual Studio 2019 Debug */

int __fastcall size(int *param_1)

{
  return param_1[1] - *param_1 >> 2;
}



// Function: FUN_10019990 at 10019990

undefined4 * __fastcall FUN_10019990(undefined4 *param_1)

{
  int iVar1;
  IUnknown *pIVar2;
  _GUID *p_Var3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100243c3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001a620(param_1);
  local_8 = 0;
  FUN_1001a5a0(param_1 + 1);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = FUN_1001ab80(param_1 + 1,(IID *)&DAT_1002a4cc,(LPUNKNOWN)0x0,0x17);
  if (iVar1 < 0) {
    p_Var3 = (_GUID *)&DAT_1002a44c;
    pIVar2 = (IUnknown *)FUN_1001a920(param_1 + 1);
    _com_issue_errorex(iVar1,pIVar2,p_Var3);
  }
  iVar1 = FUN_1001ac40(param_1,(IID *)&DAT_1002a040,(LPUNKNOWN)0x0,0x17);
  if (iVar1 < 0) {
    p_Var3 = (_GUID *)&DAT_1002a44c;
    pIVar2 = (IUnknown *)FUN_1001a920(param_1 + 1);
    _com_issue_errorex(iVar1,pIVar2,p_Var3);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10019a70 at 10019a70

void __cdecl FUN_10019a70(undefined4 param_1,uchar *param_2)

{
  char *in_stack_00000018;
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_408 = '\0';
  memset(local_407,0,0x3ff);
  _vsnprintf(&local_408,0x3ff,in_stack_00000018,&stack0x0000001c);
  FUN_1001f090(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10019b10 at 10019b10

void __cdecl FUN_10019b10(undefined4 param_1,uchar *param_2)

{
  char *in_stack_0000001c;
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_408 = '\0';
  memset(local_407,0,0x3ff);
  _vsnprintf(&local_408,0x3ff,in_stack_0000001c,&stack0x00000020);
  FUN_1001f020(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10019bb0 at 10019bb0

void FUN_10019bb0(undefined4 param_1,LPCSTR param_2)

{
  void *this;
  undefined4 uVar1;
  IUnknown *pIVar2;
  int *piVar3;
  int local_34;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_30;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_18 [4];
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024406;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002650(&local_28,param_2);
  local_8 = 0;
  piVar3 = &local_34;
  this = (void *)FUN_1001a9a0((int *)local_14);
  local_30 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
             FUN_1001ad00(this,piVar3);
  local_8._0_1_ = 1;
  local_2c = local_30;
  FUN_1001a070(local_18,local_30);
  local_8._0_1_ = 3;
  FUN_1001a700(&local_34);
  FUN_10019f30(&local_24,local_18);
  local_8._0_1_ = 4;
  local_1c = (int *)FUN_1001aa00(&local_24);
  uVar1 = FUN_10014430(&local_28);
  (**(code **)(*local_1c + 0x50))(local_1c,uVar1);
  FUN_10019fd0(&local_20,local_14);
  local_8._0_1_ = 5;
  FUN_1001a930((undefined4 *)local_18);
  pIVar2 = (IUnknown *)FUN_1001a9d0(&local_20);
  FUN_1001ae50(pIVar2);
  local_8._0_1_ = 4;
  FUN_1001a6e0(&local_20);
  local_8._0_1_ = 3;
  FUN_1001a700(&local_24);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1001a6c0((int *)local_18);
  local_8 = 0xffffffff;
  FUN_100032d0(&local_28);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10019ce0 at 10019ce0

void FUN_10019ce0(undefined4 param_1,undefined4 param_2,LPCSTR param_3,LPCSTR param_4,
                 undefined4 param_5,IID *param_6,LPCSTR param_7,undefined4 param_8)

{
  void *this;
  IUnknown *pIVar1;
  int *piVar2;
  undefined4 uStack_70;
  int *piStack_68;
  int local_44;
  int local_40;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_3c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_38;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_28 [4];
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_24 [4];
  int local_20;
  int *local_1c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024469;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piStack_68 = (int *)0x10019d14;
  FUN_10002650(local_28,param_3);
  local_8 = 0;
  piStack_68 = (int *)0x10019d27;
  FUN_10002650(&local_44,param_4);
  local_8._0_1_ = 1;
  piStack_68 = (int *)0x10019d37;
  FUN_10002650(local_24,param_7);
  local_8._0_1_ = 2;
  uStack_70 = 0x10019d4e;
  local_2c = boost::exception_detail::
             refcount_ptr<struct_boost::exception_detail::error_info_container>::
             refcount_ptr<struct_boost::exception_detail::error_info_container>
                       ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                        &piStack_68,local_24);
  local_8._0_1_ = 3;
  uStack_70 = param_8;
  local_30 = FUN_10002650(&uStack_70,param_7);
  local_8._0_1_ = 4;
  local_34 = boost::exception_detail::
             refcount_ptr<struct_boost::exception_detail::error_info_container>::
             refcount_ptr<struct_boost::exception_detail::error_info_container>
                       ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                        &stack0xffffff8c,local_28);
  local_8._0_1_ = 5;
  piVar2 = &local_40;
  FUN_1001a9a0((int *)local_18);
  local_8._0_1_ = 2;
  local_3c = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
             FUN_1001aa90(piVar2);
  local_8._0_1_ = 6;
  piStack_68 = (int *)0x10019dd8;
  local_38 = local_3c;
  FUN_10019e90(&local_14,local_3c);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_1001a6a0(&local_40);
  if (param_6 != (IID *)0x0) {
    piStack_68 = (int *)0x10019df6;
    this = (void *)FUN_1001a970(&local_14);
    piStack_68 = (int *)0x10019dfd;
    FUN_1001ae90(this,param_6);
  }
  piStack_68 = (int *)FUN_1001a970(&local_14);
  local_1c = piStack_68;
  (**(code **)(*piStack_68 + 0x38))();
  uStack_70 = 0x10019e24;
  FUN_10019fd0(&local_20,local_18);
  local_8._0_1_ = 9;
  FUN_1001a930(&local_14);
  uStack_70 = 0x10019e39;
  pIVar1 = (IUnknown *)FUN_1001a9d0(&local_20);
  uStack_70 = 0x10019e40;
  FUN_1001ae50(pIVar1);
  local_8._0_1_ = 8;
  FUN_1001a6e0(&local_20);
  local_8._0_1_ = 2;
  FUN_1001a6c0(&local_14);
  local_8._0_1_ = 1;
  FUN_100032d0((int *)local_24);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100032d0(&local_44);
  local_8 = 0xffffffff;
  FUN_100032d0((int *)local_28);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10019e90 at 10019e90

undefined4 * __thiscall
FUN_10019e90(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024498;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_1001a200();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10019f30 at 10019f30

undefined4 * __thiscall
FUN_10019f30(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100244c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_1001a2d0();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10019fd0 at 10019fd0

undefined4 * __thiscall
FUN_10019fd0(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100244f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_1001a3a0();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001a070 at 1001a070

undefined4 * __thiscall
FUN_1001a070(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024528;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_1001a470();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FID_conflict:operator= at 1001a110

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_1001af00((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 1001a160

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_1001af60((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 1001a1b0

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_1001af90((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_1001a200 at 1001a200

int FUN_1001a200(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024558;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_1001a820(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_1001a940((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_1001ae10();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_1001a6a0((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_1001a2d0 at 1001a2d0

int FUN_1001a2d0(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024588;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_1001a860(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_1001a970((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_1001ae40();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_1001a6c0((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_1001a3a0 at 1001a3a0

int FUN_1001a3a0(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100245b8;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_1001a8a0(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_1001a9a0((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_1001ae30();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013b40((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_1001a470 at 1001a470

int FUN_1001a470(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100245e8;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_1001a8e0(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_1001aa00((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_1001ae10();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_1001a700((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 1001a540

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_1001aed0((int *)this);
  return this;
}



// Function: FUN_1001a570 at 1001a570

int * __thiscall FUN_1001a570(void *this,int param_1,char param_2)

{
  *(int *)this = param_1;
  if (param_2 != '\0') {
    FUN_1001aed0((int *)this);
  }
  return (int *)this;
}



// Function: FUN_1001a5a0 at 1001a5a0

undefined4 * __fastcall FUN_1001a5a0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 1001a5c0

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_1001af00((int *)this);
  return this;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 1001a5f0

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_1001af30((int *)this);
  return this;
}



// Function: FUN_1001a620 at 1001a620

undefined4 * __fastcall FUN_1001a620(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 1001a640

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_1001af90((int *)this);
  return this;
}



// Function: FUN_1001a670 at 1001a670

int * __thiscall FUN_1001a670(void *this,int param_1,char param_2)

{
  *(int *)this = param_1;
  if (param_2 != '\0') {
    FUN_1001af90((int *)this);
  }
  return (int *)this;
}



// Function: FUN_1001a6a0 at 1001a6a0

void __fastcall FUN_1001a6a0(int *param_1)

{
  FUN_1001afc0(param_1);
  return;
}



// Function: FUN_1001a6c0 at 1001a6c0

void __fastcall FUN_1001a6c0(int *param_1)

{
  FUN_1001aff0(param_1);
  return;
}



// Function: FUN_1001a6e0 at 1001a6e0

void __fastcall FUN_1001a6e0(int *param_1)

{
  FUN_1001b020(param_1);
  return;
}



// Function: FUN_1001a700 at 1001a700

void __fastcall FUN_1001a700(int *param_1)

{
  FUN_1001b050(param_1);
  return;
}



// Function: FUN_1001a720 at 1001a720

bool __thiscall FUN_1001a720(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_1001a760 at 1001a760

bool __thiscall FUN_1001a760(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_1001a7a0 at 1001a7a0

bool __thiscall FUN_1001a7a0(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_1001a7e0 at 1001a7e0

bool __thiscall FUN_1001a7e0(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_1001a820 at 1001a820

bool __thiscall FUN_1001a820(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_1001a720(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_1001a860 at 1001a860

bool __thiscall FUN_1001a860(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_1001a760(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_1001a8a0 at 1001a8a0

bool __thiscall FUN_1001a8a0(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_1001a7a0(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_1001a8e0 at 1001a8e0

bool __thiscall FUN_1001a8e0(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_1001a7e0(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_1001a920 at 1001a920

undefined4 __fastcall FUN_1001a920(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1001a930 at 1001a930

undefined4 __fastcall FUN_1001a930(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1001a940 at 1001a940

int __fastcall FUN_1001a940(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_1001a970 at 1001a970

int __fastcall FUN_1001a970(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_1001a9a0 at 1001a9a0

int __fastcall FUN_1001a9a0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_1001a9d0 at 1001a9d0

int __fastcall FUN_1001a9d0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_1001aa00 at 1001aa00

int __fastcall FUN_1001aa00(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: Attach at 1001aa30

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_1001aff0((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 1001aa50

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_1001b020((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 1001aa70

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_1001b050((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: FUN_1001aa90 at 1001aa90

void * FUN_1001aa90(void *param_1)

{
  ULONG UVar1;
  IUnknown *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10024641;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 3;
  FUN_10014430((int *)&stack0x00000024);
  FUN_10014430((int *)&stack0x0000001c);
  FUN_10014430((int *)&stack0x00000018);
  UVar1 = (*in_ECX->lpVtbl[3].AddRef)(in_ECX);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,in_ECX,(_GUID *)&DAT_1002a714);
  }
  FUN_1001a570(param_1,0,'\0');
  local_8._0_1_ = 2;
  FUN_100032d0((int *)&stack0x00000018);
  local_8._0_1_ = 1;
  FUN_100032d0((int *)&stack0x0000001c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100032d0((int *)&stack0x00000024);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001ab80 at 1001ab80

int __thiscall FUN_1001ab80(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  IID *pIVar1;
  void **ppvObject;
  LPVOID *ppv;
  LPUNKNOWN local_c;
  HRESULT local_8;
  
  FUN_10015b60((int *)this);
  if ((param_3 & 0x14) == 0) {
    ppv = (LPVOID *)this;
    pIVar1 = (IID *)FUN_1001ae00();
    local_8 = CoCreateInstance(param_1,param_2,param_3,pIVar1,ppv);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10029b80,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        ppvObject = (void **)this;
        pIVar1 = (IID *)FUN_1001ae00();
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,pIVar1,ppvObject);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: FUN_1001ac40 at 1001ac40

int __thiscall FUN_1001ac40(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  IID *pIVar1;
  void **ppvObject;
  LPVOID *ppv;
  LPUNKNOWN local_c;
  HRESULT local_8;
  
  FUN_10015b90((int *)this);
  if ((param_3 & 0x14) == 0) {
    ppv = (LPVOID *)this;
    pIVar1 = (IID *)FUN_1001ae20();
    local_8 = CoCreateInstance(param_1,param_2,param_3,pIVar1,ppv);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10029b80,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        ppvObject = (void **)this;
        pIVar1 = (IID *)FUN_1001ae20();
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,pIVar1,ppvObject);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: FUN_1001ad00 at 1001ad00

void * __thiscall FUN_1001ad00(void *this,void *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024679;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x1c))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002a714);
  }
  FUN_1001a670(param_1,0,'\0');
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001adb0 at 1001adb0

undefined * FUN_1001adb0(void)

{
  return &DAT_1002a44c;
}



// Function: FUN_1001adc0 at 1001adc0

undefined * FUN_1001adc0(void)

{
  return &DAT_1002a600;
}



// Function: FUN_1001add0 at 1001add0

undefined * FUN_1001add0(void)

{
  return &DAT_1002a714;
}



// Function: FUN_1001ade0 at 1001ade0

undefined * FUN_1001ade0(void)

{
  return &DAT_1002a734;
}



// Function: FUN_1001adf0 at 1001adf0

undefined * FUN_1001adf0(void)

{
  return &DAT_1002a680;
}



// Function: FUN_1001ae00 at 1001ae00

void FUN_1001ae00(void)

{
  FUN_1001adb0();
  return;
}



// Function: FUN_1001ae10 at 1001ae10

void FUN_1001ae10(void)

{
  FUN_1001adc0();
  return;
}



// Function: FUN_1001ae20 at 1001ae20

void FUN_1001ae20(void)

{
  FUN_1001add0();
  return;
}



// Function: FUN_1001ae30 at 1001ae30

void FUN_1001ae30(void)

{
  FUN_1001ade0();
  return;
}



// Function: FUN_1001ae40 at 1001ae40

void FUN_1001ae40(void)

{
  FUN_1001adf0();
  return;
}



// Function: FUN_1001ae50 at 1001ae50

ULONG __fastcall FUN_1001ae50(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[2].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a734);
  }
  return UVar1;
}



// Function: FUN_1001ae90 at 1001ae90

void __thiscall FUN_1001ae90(void *this,IID *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x48))(this,param_1);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002a600);
  }
  return;
}



// Function: FUN_1001aed0 at 1001aed0

void __fastcall FUN_1001aed0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001af00 at 1001af00

void __fastcall FUN_1001af00(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001af30 at 1001af30

void __fastcall FUN_1001af30(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001af60 at 1001af60

void __fastcall FUN_1001af60(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001af90 at 1001af90

void __fastcall FUN_1001af90(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001afc0 at 1001afc0

void __fastcall FUN_1001afc0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001aff0 at 1001aff0

void __fastcall FUN_1001aff0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001b020 at 1001b020

void __fastcall FUN_1001b020(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001b050 at 1001b050

void __fastcall FUN_1001b050(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001b080 at 1001b080

undefined4 __cdecl FUN_1001b080(int *param_1)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  IUnknown *pIVar4;
  int *piVar5;
  ushort uVar6;
  int *piVar7;
  int local_94;
  int *local_90;
  undefined4 local_8c;
  int *local_88;
  int local_84;
  undefined4 local_80;
  int *local_7c;
  int local_78;
  int *local_74;
  int *local_70;
  int local_6c;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_68;
  void *local_64;
  int local_60;
  void *local_5c;
  int *local_58;
  int local_54;
  int *local_50;
  refcount_ptr<struct_boost::exception_detail::error_info_container> *local_4c;
  int local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int local_38;
  undefined4 local_34;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_30 [4];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024731;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10013320(&local_38);
  local_8 = 0;
  local_3c = (int *)FUN_100145b0(param_1);
  FID_conflict_operator_(&local_38);
  (**(code **)(*local_3c + 0x20))();
  FUN_100133c0((undefined4 *)local_30);
  local_8._0_1_ = 1;
  local_44 = (int *)FUN_100146a0(&local_38);
  FID_conflict_operator_((int *)local_30);
  (**(code **)(*local_44 + 0x20))();
  FUN_1001b740(&local_48,local_30);
  local_8._0_1_ = 2;
  FUN_10002100(&local_34);
  local_8._0_1_ = 3;
  local_40 = (int *)FUN_10014670(&local_48);
  FUN_10003600(&local_34);
  (**(code **)(*local_40 + 0x34))();
  FUN_1001bb00(&local_20);
  local_8._0_1_ = 4;
  FUN_1001bee0(&local_20,(IID *)&DAT_1002e164,(LPUNKNOWN)0x0,0x17);
  uVar6 = 0;
  pvVar2 = (void *)FUN_1001bde0(&local_20);
  FUN_1001c370(pvVar2,uVar6);
  iVar3 = FUN_10003560(&local_34);
  local_88 = FUN_10013700(&stack0xffffff34,iVar3);
  local_8._0_1_ = 5;
  pIVar4 = (IUnknown *)FUN_1001bde0(&local_20);
  local_8._0_1_ = 4;
  FUN_1001c5e0(pIVar4);
  FUN_1001bc00(&local_28);
  local_8._0_1_ = 6;
  local_80 = boost::exception_detail::
             refcount_ptr<struct_boost::exception_detail::error_info_container>::
             refcount_ptr<struct_boost::exception_detail::error_info_container>
                       ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                        &stack0xffffff34,
                        (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
                        &DAT_10035640);
  local_8._0_1_ = 7;
  piVar5 = &local_60;
  FUN_1001bde0(&local_20);
  local_8._0_1_ = 6;
  local_58 = (int *)FUN_1001c530(piVar5);
  local_8._0_1_ = 8;
  FUN_1001bcc0(&local_28,local_58);
  local_8._0_1_ = 6;
  FUN_1001bc80(&local_60);
  pIVar4 = (IUnknown *)FUN_1001be70(&local_28);
  iVar3 = FUN_1001c1e0(pIVar4);
  if (iVar3 == 0) {
    FUN_1001bbb0(&local_18);
    local_8._0_1_ = 9;
    piVar5 = &local_94;
    pvVar2 = (void *)FUN_1001bde0(&local_20);
    local_68 = (refcount_ptr<struct_boost::exception_detail::error_info_container> *)
               FUN_1001c000(pvVar2,piVar5);
    local_8._0_1_ = 10;
    local_4c = local_68;
    FUN_1001b8d0(&local_18,local_68);
    local_8._0_1_ = 9;
    FUN_1001bc40(&local_94);
    piVar5 = &local_78;
    pvVar2 = (void *)FUN_1001be40(&local_18);
    local_90 = (int *)FUN_1001c0a0(pvVar2,piVar5);
    local_8._0_1_ = 0xb;
    local_70 = local_90;
    FUN_1001bca0(&local_18,local_90);
    local_8._0_1_ = 9;
    FUN_1001bc60(&local_78);
    piVar5 = &local_54;
    pvVar2 = (void *)FUN_1001be40(&local_18);
    local_50 = (int *)FUN_1001c0a0(pvVar2,piVar5);
    local_8._0_1_ = 0xc;
    FUN_1001bca0(&local_18,local_50);
    local_8._0_1_ = 9;
    FUN_1001bc60(&local_54);
    piVar7 = (int *)&DAT_10035600;
    piVar5 = &local_6c;
    pvVar2 = (void *)FUN_1001be40(&local_18);
    local_64 = FUN_1001c230(pvVar2,piVar5);
    local_8._0_1_ = 0xd;
    local_5c = local_64;
    local_11 = FUN_100141b0(local_64,piVar7);
    local_8._0_1_ = 9;
    FUN_100032d0(&local_6c);
    if (local_11 == '\0') {
      local_1c = 3;
    }
    else {
      local_1c = 4;
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_1001bc60(&local_18);
  }
  else {
    FUN_1001bbb0(&local_2c);
    local_8._0_1_ = 0xe;
    piVar5 = &local_84;
    pvVar2 = (void *)FUN_1001be70(&local_28);
    local_7c = (int *)FUN_1001c140(pvVar2,piVar5);
    local_8._0_1_ = 0xf;
    local_74 = local_7c;
    FUN_1001bca0(&local_2c,local_7c);
    local_8._0_1_ = 0xe;
    FUN_1001bc60(&local_84);
    piVar5 = &local_24;
    pvVar2 = (void *)FUN_1001be40(&local_2c);
    FUN_1001c2d0(pvVar2,piVar5);
    local_8 = CONCAT31(local_8._1_3_,0x10);
    bVar1 = FUN_100141b0(&local_24,(int *)&DAT_100355f8);
    if (bVar1) {
      local_1c = 4;
    }
    else {
      bVar1 = FUN_100141b0(&local_24,(int *)&DAT_10035668);
      if (bVar1) {
        local_1c = 3;
      }
      else {
        bVar1 = FUN_100141b0(&local_24,(int *)&DAT_10035628);
        if (bVar1) {
          local_1c = 2;
        }
        else {
          local_1c = 1;
        }
      }
    }
    local_8._0_1_ = 0xe;
    FUN_100032d0(&local_24);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_1001bc60(&local_2c);
  }
  local_8c = local_1c;
  local_8._0_1_ = 4;
  FUN_1001bc80(&local_28);
  local_8._0_1_ = 3;
  FUN_1001bc20(&local_20);
  local_8._0_1_ = 2;
  FUN_10002f00(&local_34);
  local_8._0_1_ = 1;
  FUN_10013ae0(&local_48);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013ba0((int *)local_30);
  local_8 = 0xffffffff;
  FUN_10013b00(&local_38);
  ExceptionList = local_10;
  return local_8c;
}



// Function: FUN_1001b4b0 at 1001b4b0

undefined4 __cdecl FUN_1001b4b0(int *param_1)

{
  int *piVar1;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_c = FUN_1001b080(param_1);
  local_10 = 1;
  piVar1 = (int *)FUN_100145b0(param_1);
  (**(code **)(*piVar1 + 0x48))(piVar1,&local_10);
  if (local_c == 4) {
    local_8 = 0;
  }
  else if (local_c == 3) {
    if (local_10 == 1) {
      local_8 = 4;
    }
    else if (local_10 == 2) {
      local_8 = 3;
    }
  }
  else if (local_c == 1) {
    local_8 = 2;
  }
  else if (local_c == 2) {
    local_8 = 1;
  }
  else {
    local_8 = 2;
  }
  return local_8;
}



// Function: FUN_1001b550 at 1001b550

uint __cdecl FUN_1001b550(int *param_1)

{
  uint uVar1;
  bool bVar2;
  void *this;
  int iVar3;
  IUnknown *pIVar4;
  int *piVar5;
  ushort uVar6;
  int local_38;
  int local_34;
  uint local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  refcount_ptr<struct_boost::exception_detail::error_info_container> local_1c [4];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002478f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10013320(&local_20);
  local_8 = 0;
  local_24 = (int *)FUN_100145b0(param_1);
  FID_conflict_operator_(&local_20);
  (**(code **)(*local_24 + 0x20))();
  FUN_100133c0((undefined4 *)local_1c);
  local_8._0_1_ = 1;
  local_28 = (int *)FUN_100146a0(&local_20);
  FID_conflict_operator_((int *)local_1c);
  (**(code **)(*local_28 + 0x20))();
  FUN_1001b740(&local_38,local_1c);
  local_8._0_1_ = 2;
  FUN_10002100(&local_18);
  local_8._0_1_ = 3;
  local_2c = (int *)FUN_10014670(&local_38);
  FUN_10003600(&local_18);
  (**(code **)(*local_2c + 0x34))();
  FUN_1001bb00(&local_14);
  local_8._0_1_ = 4;
  FUN_1001bee0(&local_14,(IID *)&DAT_1002e164,(LPUNKNOWN)0x0,0x17);
  uVar6 = 0;
  this = (void *)FUN_1001bde0(&local_14);
  FUN_1001c370(this,uVar6);
  iVar3 = FUN_10003560(&local_18);
  FUN_10013700(&stack0xffffff88,iVar3);
  local_8._0_1_ = 5;
  pIVar4 = (IUnknown *)FUN_1001bde0(&local_14);
  local_8._0_1_ = 4;
  FUN_1001c5e0(pIVar4);
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffff88,
             (refcount_ptr<struct_boost::exception_detail::error_info_container> *)&DAT_10035674);
  local_8._0_1_ = 6;
  piVar5 = &local_34;
  FUN_1001bde0(&local_14);
  local_8._0_1_ = 4;
  FUN_1001c680(piVar5);
  local_8._0_1_ = 7;
  bVar2 = FUN_1001bda0(&local_34,0);
  local_30 = (uint)!bVar2;
  uVar1 = local_30;
  local_8._0_1_ = 4;
  FUN_1001bc60(&local_34);
  local_8._0_1_ = 3;
  FUN_1001bc20(&local_14);
  local_8._0_1_ = 2;
  FUN_10002f00(&local_18);
  local_8._0_1_ = 1;
  FUN_10013ae0(&local_38);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10013ba0((int *)local_1c);
  local_8 = 0xffffffff;
  FUN_10013b00(&local_20);
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_1001b740 at 1001b740

undefined4 * __thiscall
FUN_1001b740(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100247b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_1001b960();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FID_conflict:operator= at 1001b7e0

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_1001c3b0((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 1001b830

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_1001c410((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FID_conflict:operator= at 1001b880

/* Library Function - Multiple Matches With Different Base Names
    public: class _CIP<struct IBindCtx,&struct _GUID const IID_IBindCtx> & __thiscall _CIP<struct
   IBindCtx,&struct _GUID const IID_IBindCtx>::operator=(struct IBindCtx *)
    public: class _CIP<struct IBindHost,&struct _GUID const IID_IBindHost> & __thiscall _CIP<struct
   IBindHost,&struct _GUID const IID_IBindHost>::operator=(struct IBindHost *)
    public: class _CIP<struct IBindStatusCallback,&struct _GUID const IID_IBindStatusCallback> &
   __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::operator=(struct IBindStatusCallback *)
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
     6 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

int * __thiscall FID_conflict_operator_(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    *(int *)this = param_1;
    FUN_1001c440((int *)this);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)this;
}



// Function: FUN_1001b8d0 at 1001b8d0

void * __thiscall
FUN_1001b8d0(void *this,refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100247e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
  refcount_ptr<struct_boost::exception_detail::error_info_container>
            ((refcount_ptr<struct_boost::exception_detail::error_info_container> *)&stack0xffffffd0,
             param_1);
  local_8 = 0xffffffff;
  iVar1 = FUN_1001ba30();
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001b960 at 1001b960

int FUN_1001b960(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024818;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_100142f0(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_10014730((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_1001bfd0();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_10013ba0((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_1001ba30 at 1001ba30

int FUN_1001ba30(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_24;
  void *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024848;
  local_10 = ExceptionList;
  uVar3 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = FUN_1001bd60(&stack0x00000004,0);
  if (bVar2) {
    local_18 = (undefined4 *)FUN_1001be10((int *)&stack0x00000004);
    piVar5 = &local_24;
    uVar4 = FUN_1001bff0();
    local_14 = (**(code **)*local_18)(local_18,uVar4,piVar5,uVar3);
    if (local_14 < 0) {
      local_1c = 0;
    }
    else {
      local_1c = local_24;
    }
    Attach(local_20,local_1c);
  }
  else {
    FID_conflict_operator_(local_20,0);
    local_14 = -0x7fffbffe;
  }
  iVar1 = local_14;
  local_8 = 0xffffffff;
  FUN_1001bc40((int *)&stack0x00000004);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_1001bb00 at 1001bb00

undefined4 * __fastcall FUN_1001bb00(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: refcount_ptr<struct_boost::exception_detail::error_info_container> at 1001bb20

/* Library Function - Single Match
    public: __thiscall boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container>::refcount_ptr<struct
   boost::exception_detail::error_info_container>(class boost::exception_detail::refcount_ptr<struct
   boost::exception_detail::error_info_container> const &)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

refcount_ptr<struct_boost::exception_detail::error_info_container> * __thiscall
boost::exception_detail::refcount_ptr<struct_boost::exception_detail::error_info_container>::
refcount_ptr<struct_boost::exception_detail::error_info_container>
          (refcount_ptr<struct_boost::exception_detail::error_info_container> *this,
          refcount_ptr<struct_boost::exception_detail::error_info_container> *param_1)

{
  *(undefined4 *)this = *(undefined4 *)param_1;
  FUN_1001c3e0((int *)this);
  return this;
}



// Function: FUN_1001bb50 at 1001bb50

int * __thiscall FUN_1001bb50(void *this,int param_1,char param_2)

{
  *(int *)this = param_1;
  if (param_2 != '\0') {
    FUN_1001c3e0((int *)this);
  }
  return (int *)this;
}



// Function: FUN_1001bb80 at 1001bb80

int * __thiscall FUN_1001bb80(void *this,int param_1,char param_2)

{
  *(int *)this = param_1;
  if (param_2 != '\0') {
    FUN_1001c410((int *)this);
  }
  return (int *)this;
}



// Function: FUN_1001bbb0 at 1001bbb0

undefined4 * __fastcall FUN_1001bbb0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001bbd0 at 1001bbd0

int * __thiscall FUN_1001bbd0(void *this,int param_1,char param_2)

{
  *(int *)this = param_1;
  if (param_2 != '\0') {
    FUN_1001c440((int *)this);
  }
  return (int *)this;
}



// Function: FUN_1001bc00 at 1001bc00

undefined4 * __fastcall FUN_1001bc00(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001bc20 at 1001bc20

void __fastcall FUN_1001bc20(int *param_1)

{
  FUN_1001c470(param_1);
  return;
}



// Function: FUN_1001bc40 at 1001bc40

void __fastcall FUN_1001bc40(int *param_1)

{
  FUN_1001c4a0(param_1);
  return;
}



// Function: FUN_1001bc60 at 1001bc60

void __fastcall FUN_1001bc60(int *param_1)

{
  FUN_1001c4d0(param_1);
  return;
}



// Function: FUN_1001bc80 at 1001bc80

void __fastcall FUN_1001bc80(int *param_1)

{
  FUN_1001c500(param_1);
  return;
}



// Function: FUN_1001bca0 at 1001bca0

void __thiscall FUN_1001bca0(void *this,int *param_1)

{
  FID_conflict_operator_(this,*param_1);
  return;
}



// Function: FUN_1001bcc0 at 1001bcc0

void __thiscall FUN_1001bcc0(void *this,int *param_1)

{
  FID_conflict_operator_(this,*param_1);
  return;
}



// Function: FUN_1001bce0 at 1001bce0

bool __thiscall FUN_1001bce0(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_1001bd20 at 1001bd20

bool __thiscall FUN_1001bd20(void *this,int param_1)

{
  if (param_1 != 0) {
    _com_issue_error(-0x7fffbffd);
  }
                    /* WARNING: Load size is inaccurate */
  return *this == 0;
}



// Function: FUN_1001bd60 at 1001bd60

bool __thiscall FUN_1001bd60(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_1001bce0(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_1001bda0 at 1001bda0

bool __thiscall FUN_1001bda0(void *this,int param_1)

{
  bool local_8;
  
  local_8 = FUN_1001bd20(this,param_1);
  local_8 = !local_8;
  return local_8;
}



// Function: FUN_1001bde0 at 1001bde0

int __fastcall FUN_1001bde0(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_1001be10 at 1001be10

int __fastcall FUN_1001be10(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_1001be40 at 1001be40

int __fastcall FUN_1001be40(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: FUN_1001be70 at 1001be70

int __fastcall FUN_1001be70(int *param_1)

{
  if (*param_1 == 0) {
    _com_issue_error(-0x7fffbffd);
  }
  return *param_1;
}



// Function: Attach at 1001bea0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_10015b00((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: Attach at 1001bec0

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall _CIP<struct IBindHost,&struct _GUID const IID_IBindHost>::Attach(struct
   IBindHost *)
    public: void __thiscall _CIP<struct IBindStatusCallback,&struct _GUID const
   IID_IBindStatusCallback>::Attach(struct IBindStatusCallback *)
    public: void __thiscall _CIP<struct IServiceProvider,&struct _GUID const
   IID_IServiceProvider>::Attach(struct IServiceProvider *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall Attach(void *this,int param_1)

{
  FUN_1001c4d0((int *)this);
  *(int *)this = param_1;
  return;
}



// Function: FUN_1001bee0 at 1001bee0

int __thiscall FUN_1001bee0(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  IID *pIVar1;
  void **ppvObject;
  LPVOID *ppv;
  LPUNKNOWN local_c;
  HRESULT local_8;
  
  FUN_1001c470((int *)this);
  if ((param_3 & 0x14) == 0) {
    ppv = (LPVOID *)this;
    pIVar1 = (IID *)FUN_1001bfe0();
    local_8 = CoCreateInstance(param_1,param_2,param_3,pIVar1,ppv);
  }
  else {
    local_8 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10029b80,&local_c);
    if (-1 < local_8) {
      local_8 = OleRun(local_c);
      if (-1 < local_8) {
        ppvObject = (void **)this;
        pIVar1 = (IID *)FUN_1001bfe0();
        local_8 = (*local_c->lpVtbl->QueryInterface)(local_c,pIVar1,ppvObject);
      }
      (*local_c->lpVtbl->Release)(local_c);
    }
  }
  if (local_8 < 0) {
    *(undefined4 *)this = 0;
  }
  return local_8;
}



// Function: FUN_1001bfa0 at 1001bfa0

undefined * FUN_1001bfa0(void)

{
  return &DAT_1002a7c8;
}



// Function: FUN_1001bfb0 at 1001bfb0

undefined * FUN_1001bfb0(void)

{
  return &DAT_1002a054;
}



// Function: FUN_1001bfc0 at 1001bfc0

undefined * FUN_1001bfc0(void)

{
  return &DAT_1002a160;
}



// Function: FUN_1001bfd0 at 1001bfd0

void FUN_1001bfd0(void)

{
  FUN_1001bfa0();
  return;
}



// Function: FUN_1001bfe0 at 1001bfe0

void FUN_1001bfe0(void)

{
  FUN_1001bfb0();
  return;
}



// Function: FUN_1001bff0 at 1001bff0

void FUN_1001bff0(void)

{
  FUN_1001bfc0();
  return;
}



// Function: FUN_1001c000 at 1001c000

void * __thiscall FUN_1001c000(void *this,void *param_1)

{
  int local_1c;
  int local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024889;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
                    /* WARNING: Load size is inaccurate */
  local_14 = (IUnknown *)this;
  local_18 = (**(code **)(*this + 0xb4))(this,&local_1c,DAT_100352f8 ^ (uint)&stack0xfffffffc,0);
  if (local_18 < 0) {
    _com_issue_errorex(local_18,local_14,(_GUID *)&DAT_1002a054);
  }
  FUN_1001bb50(param_1,local_1c,'\0');
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001c0a0 at 1001c0a0

void * __thiscall FUN_1001c0a0(void *this,void *param_1)

{
  int local_1c;
  int local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100248c9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
                    /* WARNING: Load size is inaccurate */
  local_14 = (IUnknown *)this;
  local_18 = (**(code **)(*this + 0x34))(this,&local_1c,DAT_100352f8 ^ (uint)&stack0xfffffffc,0);
  if (local_18 < 0) {
    _com_issue_errorex(local_18,local_14,(_GUID *)&DAT_1002a160);
  }
  FUN_1001bb80(param_1,local_1c,'\0');
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001c140 at 1001c140

void * __thiscall FUN_1001c140(void *this,void *param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024909;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x1c))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002a17c);
  }
  FUN_1001bb80(param_1,0,'\0');
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001c1e0 at 1001c1e0

undefined4 __fastcall FUN_1001c1e0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[2].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a17c);
  }
  return 0;
}



// Function: FUN_1001c230 at 1001c230

void * __thiscall FUN_1001c230(void *this,void *param_1)

{
  int local_1c;
  int local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024949;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
                    /* WARNING: Load size is inaccurate */
  local_14 = (IUnknown *)this;
  local_18 = (**(code **)(*this + 0x1c))(this,&local_1c,DAT_100352f8 ^ (uint)&stack0xfffffffc,0);
  if (local_18 < 0) {
    _com_issue_errorex(local_18,local_14,(_GUID *)&DAT_1002a160);
  }
  FUN_10013660(param_1,local_1c,'\0');
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001c2d0 at 1001c2d0

void * __thiscall FUN_1001c2d0(void *this,void *param_1)

{
  int local_1c;
  int local_18;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024989;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
                    /* WARNING: Load size is inaccurate */
  local_14 = (IUnknown *)this;
  local_18 = (**(code **)(*this + 0x68))(this,&local_1c,DAT_100352f8 ^ (uint)&stack0xfffffffc,0);
  if (local_18 < 0) {
    _com_issue_errorex(local_18,local_14,(_GUID *)&DAT_1002a160);
  }
  FUN_10013660(param_1,local_1c,'\0');
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001c370 at 1001c370

void __thiscall FUN_1001c370(void *this,ushort param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0xfc))(this,param_1);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002a054);
  }
  return;
}



// Function: FUN_1001c3b0 at 1001c3b0

void __fastcall FUN_1001c3b0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001c3e0 at 1001c3e0

void __fastcall FUN_1001c3e0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001c410 at 1001c410

void __fastcall FUN_1001c410(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001c440 at 1001c440

void __fastcall FUN_1001c440(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 4))(*param_1);
  }
  return;
}



// Function: FUN_1001c470 at 1001c470

void __fastcall FUN_1001c470(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001c4a0 at 1001c4a0

void __fastcall FUN_1001c4a0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001c4d0 at 1001c4d0

void __fastcall FUN_1001c4d0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001c500 at 1001c500

void __fastcall FUN_1001c500(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001c530 at 1001c530

void * FUN_1001c530(void *param_1)

{
  ULONG UVar1;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_100249d1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_10014430((int *)&stack0x00000008);
  UVar1 = (*local_14->lpVtbl[0x12].AddRef)(local_14);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,local_14,(_GUID *)&DAT_1002a054);
  }
  FUN_1001bbd0(param_1,0,'\0');
  local_8 = local_8 & 0xffffff00;
  FUN_100032d0((int *)&stack0x00000008);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001c5e0 at 1001c5e0

undefined2 __fastcall FUN_1001c5e0(IUnknown *param_1)

{
  ULONG UVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100249f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10014430((int *)&stack0x00000004);
  UVar1 = (*param_1->lpVtbl[0x15].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a054);
  }
  local_8 = 0xffffffff;
  FUN_100032d0((int *)&stack0x00000004);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1001c680 at 1001c680

void * FUN_1001c680(void *param_1)

{
  ULONG UVar1;
  IUnknown *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10024a41;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_10014430((int *)&stack0x00000008);
  UVar1 = (*local_14->lpVtbl[0xc].AddRef)(local_14);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,local_14,(_GUID *)&DAT_1002a160);
  }
  FUN_1001bb80(param_1,0,'\0');
  local_8 = local_8 & 0xffffff00;
  FUN_100032d0((int *)&stack0x00000008);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001c730 at 1001c730

undefined1 * __cdecl FUN_1001c730(undefined1 *param_1,undefined1 *param_2,undefined *param_3)

{
  char cVar1;
  
  if (param_1 == param_2) {
    return param_1;
  }
  do {
    cVar1 = (*(code *)param_3)(*param_1);
    if (cVar1 != '\0') {
      return param_1;
    }
    param_1 = param_1 + 1;
  } while (param_1 != param_2);
  return param_1;
}



// Function: FUN_1001c770 at 1001c770

void __cdecl FUN_1001c770(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  *param_2 = param_3;
  *param_1 = param_3;
  return;
}



// Function: FUN_1001c790 at 1001c790

undefined4 __cdecl FUN_1001c790(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001c7a0 at 1001c7a0

void __cdecl
FUN_1001c7a0(undefined4 *param_1,undefined1 *param_2,undefined1 *param_3,undefined *param_4)

{
  char cVar1;
  
  if (param_2 == param_3) {
    *param_1 = param_2;
    return;
  }
  do {
    cVar1 = (*(code *)param_4)(*param_2);
    if (cVar1 != '\0') break;
    param_2 = param_2 + 1;
  } while (param_2 != param_3);
  *param_1 = param_2;
  return;
}



// Function: FUN_1001c7e0 at 1001c7e0

undefined4 * __thiscall FUN_1001c7e0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1001c7f0 at 1001c7f0

undefined4 * __thiscall FUN_1001c7f0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1001c800 at 1001c800

bool __thiscall FUN_1001c800(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == *param_1;
}



// Function: FUN_1001c820 at 1001c820

undefined1 __cdecl
FUN_1001c820(int param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uStack_30;
  short *local_20;
  uint local_1c;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024b80;
  local_10 = ExceptionList;
  uStack_30 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  uVar1 = 0;
  local_15 = 0;
  local_8 = 0;
  local_20 = (short *)0x0;
  iVar2 = Ordinal_23(*(undefined4 *)(param_1 + 8),&local_20);
  if (-1 < iVar2) {
    local_1c = 0;
    iVar2 = Ordinal_19(*(undefined4 *)(param_1 + 8),1,&local_1c);
    if (-1 < iVar2) {
      local_1c = local_1c + 1;
      uVar1 = FUN_1001ccf0(local_20,local_1c,param_2);
      local_15 = uVar1;
    }
    Ordinal_24(*(undefined4 *)(param_1 + 8));
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: Catch@1001c8cb at 1001c8cb

undefined1 * Catch_1001c8cb(void)

{
  return &LAB_1001c8d1;
}



// Function: FUN_1001c8f0 at 1001c8f0

void __fastcall FUN_1001c8f0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = Ordinal_9(param_1);
  if (-1 < iVar2) {
    return;
  }
  _com_issue_error(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_1001c910 at 1001c910

void __cdecl FUN_1001c910(char *param_1,uint param_2,uint param_3,uint param_4,int *param_5)

{
  char ****ppppcVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  char ****ppppcVar5;
  char ****ppppcVar6;
  char ***local_2c [4];
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024ba8;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_5 = 0;
  if (((param_3 <= param_2) && (param_2 <= param_4)) || (param_3 == param_4)) {
    cVar2 = FUN_1001d090(param_1);
    if (cVar2 == '\x01') {
      iVar4 = FUN_1001cb80(param_1);
      *param_5 = iVar4;
    }
    else {
      basic_string<>(local_2c,param_1);
      local_8 = 0;
      ppppcVar6 = local_2c;
      if (0xf < local_18) {
        ppppcVar6 = (char ****)local_2c[0];
      }
      ppppcVar5 = local_2c;
      if (0xf < local_18) {
        ppppcVar5 = (char ****)local_2c[0];
      }
      ppppcVar1 = local_2c;
      if (0xf < local_18) {
        ppppcVar1 = (char ****)local_2c[0];
      }
      while ((ppppcVar1 != (char ****)((int)ppppcVar5 + local_1c) &&
             (bVar3 = FUN_1001d070(*(char *)ppppcVar1), !bVar3))) {
        ppppcVar1 = (char ****)((int)ppppcVar1 + 1);
      }
      if (ppppcVar1 == (char ****)((int)ppppcVar6 + local_1c)) {
        iVar4 = atoi(param_1);
        *param_5 = iVar4;
      }
      local_8 = 0xffffffff;
      if (0xf < local_18) {
        operator_delete(local_2c[0]);
      }
      local_18 = 0xf;
      local_1c = 0;
      local_2c[0] = (char ***)((uint)local_2c[0] & 0xffffff00);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001ca50 at 1001ca50

void __cdecl FUN_1001ca50(undefined4 *param_1,undefined2 *param_2)

{
  uint *puVar1;
  
  puVar1 = param_1 + 4;
  if (0xf < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  FUN_1001ca70((int)param_1,*puVar1,param_2);
  return;
}



// Function: FUN_1001ca70 at 1001ca70

size_t __cdecl FUN_1001ca70(int param_1,uint param_2,undefined2 *param_3)

{
  void *_Dst;
  long lVar1;
  uint _Size;
  size_t sVar2;
  uint uStack_38;
  char *local_24;
  size_t local_20;
  void *local_1c;
  char local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024bd0;
  local_10 = ExceptionList;
  uStack_38 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  sVar2 = 0;
  local_20 = 0;
  local_1c = (void *)0x0;
  local_8 = 0;
  if ((param_2 & 1) == 0) {
    local_24 = (char *)0x0;
    _Size = param_2 >> 1;
    _Dst = (void *)FUN_10020fb4(_Size);
    local_1c = _Dst;
    memset(_Dst,0,_Size);
    for (; (int)sVar2 < (int)_Size; sVar2 = sVar2 + 1) {
      local_18 = *(char *)(param_1 + sVar2 * 2);
      local_17 = *(undefined1 *)(param_1 + 1 + sVar2 * 2);
      local_16 = 0;
      lVar1 = strtol(&local_18,&local_24,0x10);
      *(char *)(sVar2 + (int)_Dst) = (char)lVar1;
    }
    sVar2 = FUN_1001cc10(_Dst,_Size,param_3);
    local_20 = sVar2;
    operator_delete__(_Dst);
  }
  ExceptionList = local_10;
  return sVar2;
}



// Function: Catch@1001cb39 at 1001cb39

undefined1 * Catch_1001cb39(void)

{
  int unaff_EBP;
  
  GetLastError();
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  return &LAB_1001cb57;
}



// Function: FUN_1001cb80 at 1001cb80

int __cdecl FUN_1001cb80(char *param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)_strupr(param_1);
  return (uint)pbVar1[7] +
         ((uint)pbVar1[6] +
          ((uint)pbVar1[5] +
           ((pbVar1[4] - 0x41) +
           ((uint)pbVar1[3] +
           (((uint)pbVar1[2] + (((uint)pbVar1[1] + (*pbVar1 - 0x41) * 10 + -0x30) * 5 + -0x18) * 2)
            * 5 + -0x18) * 2) * 0x1a) * 10 + -0x30) * 10 + -0x30) * 10 + 0x989650;
}



// Function: FUN_1001cc10 at 1001cc10

size_t __cdecl FUN_1001cc10(void *param_1,size_t param_2,undefined2 *param_3)

{
  int iVar1;
  size_t sVar2;
  uint uStack_34;
  size_t local_24 [3];
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024bf0;
  local_10 = ExceptionList;
  uStack_34 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  sVar2 = 0;
  local_24[2] = 0;
  local_8 = 0;
  FUN_1001c8f0(param_3);
  local_24[1] = 0;
  local_24[0] = param_2;
  *param_3 = 0x2011;
  iVar1 = Ordinal_15(0x11,1,local_24);
  *(int *)(param_3 + 4) = iVar1;
  if (iVar1 != 0) {
    local_18 = (void *)0x0;
    iVar1 = Ordinal_23(iVar1,&local_18);
    if (iVar1 == 0) {
      memcpy(local_18,param_1,param_2);
      iVar1 = Ordinal_24(*(undefined4 *)(param_3 + 4));
      if (iVar1 == 0) {
        sVar2 = param_2;
      }
    }
  }
  ExceptionList = local_10;
  return sVar2;
}



// Function: Catch@1001ccc0 at 1001ccc0

undefined1 * Catch_1001ccc0(void)

{
  int unaff_EBP;
  
  FUN_1001c8f0(*(undefined4 *)(unaff_EBP + 0x10));
  GetLastError();
  return &LAB_1001ccd4;
}



// Function: FUN_1001ccf0 at 1001ccf0

void __cdecl
FUN_1001ccf0(short *param_1,uint param_2,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)

{
  char *pcVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024c10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*param_1 != 0x7830) {
    pcVar1 = (char *)FUN_10020fb4(param_2 * 2 + 1);
    for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
      sprintf(pcVar1 + uVar2 * 2,"%02X",(uint)*(byte *)(uVar2 + (int)param_1));
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
              (param_3,pcVar1);
    operator_delete__(pcVar1);
    ExceptionList = local_10;
    return;
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=
            (param_3,(char *)param_1);
  ExceptionList = local_10;
  return;
}



// Function: Catch@1001cdcd at 1001cdcd

undefined1 * Catch_1001cdcd(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  GetLastError();
  return &LAB_1001cde4;
}



// Function: FUN_1001ce00 at 1001ce00

void __cdecl FUN_1001ce00(undefined4 *param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char local_2c;
  char local_28;
  char local_24;
  char local_20;
  undefined8 local_1f;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024c49;
  local_10 = ExceptionList;
  local_14 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = '\0';
  local_1f = 0;
  *param_1 = 0;
  local_8 = 0;
  if (param_2 - 10000000U < 0x27b25a81) {
    uVar6 = (param_2 - 10000000U) / 26000;
    uVar8 = (uVar6 % 1000) / 100;
    uVar7 = (param_2 - 10000000U) % 26000;
    uVar9 = (uVar7 % 1000) / 100;
    local_2c = (char)(uVar6 / 1000);
    local_20 = local_2c + 'A';
    cVar1 = (char)uVar8;
    cVar2 = (char)((uVar6 + (uVar8 + (uVar6 / 1000) * 10) * -100) / 10);
    local_28 = (char)uVar6;
    cVar3 = (char)(uVar7 / 1000);
    cVar4 = (char)uVar9;
    cVar5 = (char)((uVar7 + (uVar9 + (uVar7 / 1000) * 10) * -100) / 10);
    local_24 = (char)uVar7;
    local_1f = (ulonglong)
               CONCAT16((cVar3 + '\x02') * '\x18' + (cVar4 * '\n' + cVar5) * -10 + local_24,
                        CONCAT15(cVar5 + '0',
                                 CONCAT14(cVar4 + '0',
                                          CONCAT13(cVar3 + 'A',
                                                   CONCAT12((local_2c + '\x02') * '\x18' +
                                                            (cVar1 * '\n' + cVar2) * -10 + local_28,
                                                            CONCAT11(cVar2 + '0',cVar1 + '0'))))));
  }
  else {
    _itoa(param_2,&local_20,10);
  }
  FUN_10013e90(param_1,&local_20);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001cff0 at 1001cff0

undefined4 * __thiscall FUN_1001cff0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1001d010 at 1001d010

void __thiscall FUN_1001d010(void *this,undefined4 *param_1)

{
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  *param_1 = this;
  return;
}



// Function: FUN_1001d040 at 1001d040

void __thiscall FUN_1001d040(void *this,int *param_1)

{
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    *param_1 = *(int *)((int)this + 0x10) + *this;
    return;
  }
  *param_1 = *(int *)((int)this + 0x10) + (int)this;
  return;
}



// Function: FUN_1001d070 at 1001d070

bool __cdecl FUN_1001d070(char param_1)

{
  int iVar1;
  
  iVar1 = isdigit((int)param_1);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: FUN_1001d090 at 1001d090

void __cdecl FUN_1001d090(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char local_14 [4];
  char local_10;
  char local_f;
  char local_e;
  char local_d;
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((int)pcVar3 - (int)(param_1 + 1) == 8) {
    iVar2 = -(int)param_1;
    do {
      cVar1 = *param_1;
      param_1[(int)(local_14 + iVar2)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    _strupr(local_14);
    if ((((((byte)(local_14[0] + 0xbfU) < 0x1a) && ((byte)(local_14[1] - 0x30U) < 10)) &&
         ((byte)(local_14[2] - 0x30U) < 10)) &&
        (((byte)(local_14[3] - 0x30U) < 10 && ((byte)(local_10 + 0xbfU) < 0x1a)))) &&
       (((byte)(local_f - 0x30U) < 10 &&
        (((byte)(local_e - 0x30U) < 10 && ((byte)(local_d - 0x30U) < 10)))))) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001d150 at 1001d150

undefined4 * __thiscall FUN_1001d150(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024c7b;
  local_10 = ExceptionList;
  uVar2 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = (int)this + 8;
  *(undefined ***)this = CSafeArrayBuffer::vftable;
  Ordinal_8(iVar1,uVar2);
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined1 *)((int)this + 0x20) = 0;
  Ordinal_8(iVar1);
  uVar3 = FUN_1001d890(param_1);
  if ((char)uVar3 != '\0') {
    Ordinal_10(iVar1,param_1 + 8);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001d1e0 at 1001d1e0

undefined4 * __thiscall FUN_1001d1e0(void *this,size_t param_1,void *param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024cab;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = CSafeArrayBuffer::vftable;
  Ordinal_8((int)this + 8,uVar1);
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined1 *)((int)this + 0x20) = 0;
  FUN_1001d560(this,param_1,param_2);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001d260 at 1001d260

undefined4 * __thiscall FUN_1001d260(void *this,short param_1,undefined4 param_2,short *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  short local_14 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024cdb;
  local_10 = ExceptionList;
  uVar2 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = (int)this + 8;
  *(undefined ***)this = CSafeArrayBuffer::vftable;
  Ordinal_8(iVar1,uVar2);
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined1 *)((int)this + 0x20) = 0;
  Ordinal_8(iVar1);
  if ((((param_1 == 0x2011) && (param_3 != (short *)0x0)) && (*param_3 == 1)) &&
     (*(int *)(param_3 + 2) != 0)) {
    if (param_3[1] != 0) {
      iVar3 = Ordinal_77(param_3,local_14);
      if (iVar3 < 0) {
        ExceptionList = local_10;
        return (undefined4 *)this;
      }
      if (local_14[0] != 0x11) {
        ExceptionList = local_10;
        return (undefined4 *)this;
      }
    }
    Ordinal_10(iVar1,&param_1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001d320 at 1001d320

undefined4 * __fastcall FUN_1001d320(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024d0b;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CSafeArrayBuffer::vftable;
  Ordinal_8(param_1 + 2,uVar1);
  local_8 = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  Ordinal_8(param_1 + 2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001d3a0 at 1001d3a0

void __fastcall FUN_1001d3a0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024d3b;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CSafeArrayBuffer::vftable;
  local_8 = 0;
  FUN_1001d940((int)param_1);
  Ordinal_9(param_1 + 2,uVar1);
  if ((void *)param_1[6] != (void *)0x0) {
    operator_delete((void *)param_1[6]);
  }
  local_8 = 0xffffffff;
  Ordinal_9(param_1 + 2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001d420 at 1001d420

int __fastcall FUN_1001d420(int param_1)

{
  *(undefined1 *)(param_1 + 0x20) = 0;
  return param_1 + 8;
}



// Function: FUN_1001d450 at 1001d450

undefined4 * __thiscall FUN_1001d450(void *this,byte param_1)

{
  FUN_1001d3a0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001d480 at 1001d480

bool __thiscall FUN_1001d480(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_1001d890((int)this);
  if ((char)uVar1 != '\0') {
    iVar2 = Ordinal_23(*(undefined4 *)((int)this + 0x10),param_1);
    return -1 < iVar2;
  }
  return false;
}



// Function: FUN_1001d4c0 at 1001d4c0

uint __thiscall FUN_1001d4c0(void *this,short *param_1)

{
  code *pcVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  
  uVar3 = in_EAX & 0xffffff00;
  if ((*(int *)(param_1 + 4) != 0) && (*param_1 == 0x2011)) {
    iVar2 = Ordinal_9((void *)((int)this + 8));
    if (iVar2 < 0) {
      _com_issue_error(iVar2);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    memcpy_s((void *)((int)this + 8),0x10,param_1,0x10);
    *param_1 = 0;
    uVar3 = 1;
    *(undefined1 *)((int)this + 0x20) = 0;
  }
  return uVar3;
}



// Function: FUN_1001d520 at 1001d520

void __thiscall FUN_1001d520(void *this,undefined2 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = Ordinal_9(this);
  if (-1 < iVar2) {
    memcpy_s(this,0x10,param_1,0x10);
    *param_1 = 0;
    return;
  }
  _com_issue_error(iVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_1001d560 at 1001d560

undefined1 __thiscall FUN_1001d560(void *this,size_t param_1,void *param_2)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  size_t local_14 [2];
  void *local_c;
  undefined1 local_5;
  
  puVar1 = (undefined2 *)((int)this + 8);
  local_5 = 0;
  Ordinal_9(puVar1);
  Ordinal_8(puVar1);
  local_14[0] = param_1;
  local_14[1] = 0;
  uVar2 = Ordinal_15(0x11,1,local_14);
  *puVar1 = 0x2011;
  *(undefined4 *)((int)this + 0x10) = uVar2;
  iVar3 = Ordinal_23(uVar2,&local_c);
  if (param_2 == (void *)0x0) {
    if (iVar3 < 0) {
      return local_5;
    }
    memset(local_c,0,param_1);
    iVar3 = Ordinal_24(*(undefined4 *)((int)this + 0x10));
  }
  else {
    if (iVar3 < 0) {
      return local_5;
    }
    memcpy(local_c,param_2,param_1);
    iVar3 = Ordinal_24(*(undefined4 *)((int)this + 0x10));
  }
  if (iVar3 < 0) {
    return local_5;
  }
  *(undefined1 *)((int)this + 0x20) = 0;
  return 1;
}



// Function: FUN_1001d620 at 1001d620

bool __thiscall FUN_1001d620(void *this,uint param_1,void *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  size_t _Size;
  int iVar3;
  void *local_8;
  
  local_8 = this;
  uVar1 = FUN_1001d890((int)this);
  if (((char)uVar1 != '\0') && (uVar2 = FUN_1001d8f0((int)this), uVar2 <= param_1)) {
    _Size = FUN_1001d8f0((int)this);
    iVar3 = Ordinal_23(*(undefined4 *)((int)this + 0x10),&local_8);
    if (-1 < iVar3) {
      memcpy(param_2,local_8,_Size);
      iVar3 = Ordinal_24(*(undefined4 *)((int)this + 0x10));
      return -1 < iVar3;
    }
    return false;
  }
  return false;
}



// Function: FUN_1001d6a0 at 1001d6a0

undefined1 __thiscall FUN_1001d6a0(void *this,int param_1,size_t param_2,void *param_3)

{
  size_t _Size;
  void *_Src;
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  _Size = param_2;
  if (param_2 != 0) {
    uVar1 = FUN_1001d890((int)this);
    if ((char)uVar1 != '\0') {
      uVar2 = FUN_1001d8f0((int)this);
      _Src = param_3;
      if (param_1 + _Size <= uVar2) {
        if (param_3 != (void *)0x0) {
          iVar3 = Ordinal_23(*(undefined4 *)((int)this + 0x10),&param_2);
          if (-1 < iVar3) {
            memcpy((void *)(param_2 + param_1),_Src,_Size);
            iVar3 = Ordinal_24(*(undefined4 *)((int)this + 0x10));
            if (-1 < iVar3) {
              *(undefined1 *)((int)this + 0x20) = 0;
              return 1;
            }
          }
        }
        return 0;
      }
    }
  }
  return 0;
}



// Function: FUN_1001d730 at 1001d730

bool __thiscall FUN_1001d730(void *this,int param_1,size_t param_2,void *param_3)

{
  size_t _Size;
  void *_Dst;
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  _Size = param_2;
  if (((param_2 != 0) && (uVar1 = FUN_1001d890((int)this), (char)uVar1 != '\0')) &&
     (uVar2 = FUN_1001d8f0((int)this), _Dst = param_3, param_1 + _Size <= uVar2)) {
    if ((param_3 != (void *)0x0) &&
       (iVar3 = Ordinal_23(*(undefined4 *)((int)this + 0x10),&param_2), -1 < iVar3)) {
      memcpy(_Dst,(void *)(param_2 + param_1),_Size);
      iVar3 = Ordinal_24(*(undefined4 *)((int)this + 0x10));
      return -1 < iVar3;
    }
    return false;
  }
  return false;
}



// Function: FUN_1001d7c0 at 1001d7c0

void __thiscall FUN_1001d7c0(void *this,undefined8 *param_1)

{
  *(undefined1 *)((int)this + 0x20) = 0;
  *param_1 = *(undefined8 *)((int)this + 8);
  param_1[1] = *(undefined8 *)((int)this + 0x10);
  *(undefined2 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_1001d7f0 at 1001d7f0

void * __thiscall FUN_1001d7f0(void *this,char param_1)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  
  uVar2 = FUN_1001d8f0((int)this);
  pvVar3 = *(void **)((int)this + 0x18);
  if (pvVar3 != (void *)0x0) {
    if ((*(char *)((int)this + 0x20) != '\0') && (param_1 == '\0')) {
      return pvVar3;
    }
    if ((pvVar3 != (void *)0x0) && (*(uint *)((int)this + 0x1c) != uVar2)) {
      operator_delete(pvVar3);
      *(undefined4 *)((int)this + 0x18) = 0;
      *(undefined4 *)((int)this + 0x1c) = 0;
    }
  }
  if (uVar2 != 0) {
    if (*(int *)((int)this + 0x18) == 0) {
      pvVar3 = operator_new(uVar2);
      *(void **)((int)this + 0x18) = pvVar3;
    }
    if (*(void **)((int)this + 0x18) == (void *)0x0) {
      return (void *)0x0;
    }
    bVar1 = FUN_1001d620(this,uVar2,*(void **)((int)this + 0x18));
    if (!bVar1) {
      operator_delete(*(void **)((int)this + 0x18));
      *(undefined4 *)((int)this + 0x18) = 0;
      return *(void **)((int)this + 0x18);
    }
    *(uint *)((int)this + 0x1c) = uVar2;
    *(undefined1 *)((int)this + 0x20) = 1;
  }
  return *(void **)((int)this + 0x18);
}



// Function: FUN_1001d890 at 1001d890

undefined4 __fastcall FUN_1001d890(int param_1)

{
  short *psVar1;
  int local_8;
  
  psVar1 = (short *)0x2000;
  if ((((*(ushort *)(param_1 + 8) & 0x2000) != 0) &&
      (psVar1 = *(short **)(param_1 + 0x10), *psVar1 == 1)) && (*(int *)(psVar1 + 2) != 0)) {
    if (psVar1[1] != 0) {
      local_8 = param_1;
      psVar1 = (short *)Ordinal_77(psVar1,&local_8);
      if (((int)psVar1 < 0) || ((short)local_8 != 0x11)) goto LAB_1001d8d9;
    }
    return CONCAT31((int3)((uint)psVar1 >> 8),1);
  }
LAB_1001d8d9:
  *(undefined1 *)(param_1 + 0x20) = 0;
  return (uint)psVar1 & 0xffffff00;
}



// Function: FUN_1001d8f0 at 1001d8f0

int __fastcall FUN_1001d8f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  uVar1 = FUN_1001d890(param_1);
  if ((char)uVar1 == '\0') {
    return local_8;
  }
  iVar2 = Ordinal_19(*(undefined4 *)(param_1 + 0x10),1,&local_8);
  if (iVar2 < 0) {
    *(undefined1 *)(param_1 + 0x20) = 0;
    return 0;
  }
  return local_8 + 1;
}



// Function: FUN_1001d940 at 1001d940

undefined4 __fastcall FUN_1001d940(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_1001d890(param_1);
  if ((char)uVar1 == '\0') {
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 8);
  if (iVar2 < 1) {
    return CONCAT31((int3)((uint)*(int *)(param_1 + 0x10) >> 8),1);
  }
  do {
    uVar1 = Ordinal_24(*(undefined4 *)(param_1 + 0x10));
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}



// Function: FUN_1001d980 at 1001d980

uint __cdecl FUN_1001d980(uint param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 local_8;
  
  uVar1 = (undefined1)param_1;
  uVar2 = (undefined1)(param_1 >> 8);
  if (((param_5 & param_4) == 0) && (((param_4 & 3) != 0 || (param_5 != param_3)))) {
    switch(param_2) {
    case 1:
      goto switchD_1001d9ab_caseD_1;
    case 2:
      local_8._0_2_ = CONCAT11(uVar1,uVar2);
      local_8 = (uint)(ushort)local_8;
      return local_8;
    case 3:
      local_8._0_2_ = CONCAT11(uVar2,param_1._2_1_);
      local_8._0_3_ = CONCAT12(uVar1,(ushort)local_8);
      local_8 = (uint)(uint3)local_8;
      return local_8;
    case 4:
      local_8._0_2_ = CONCAT11(param_1._2_1_,param_1._3_1_);
      local_8._0_3_ = CONCAT12(uVar2,(ushort)local_8);
      local_8 = CONCAT13(uVar1,(uint3)local_8);
      return local_8;
    default:
switchD_1001d9ab_default:
      param_1 = 0x80070057;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&param_1,(ThrowInfo *)&DAT_100338f0);
    }
  }
  switch(param_2) {
  case 1:
switchD_1001d9ab_caseD_1:
    local_8 = param_1 & 0xff;
    return local_8;
  case 2:
    local_8 = param_1 & 0xffff;
    return local_8;
  case 3:
    local_8 = param_1 & 0xffffff;
    return local_8;
  case 4:
    return param_1;
  default:
    goto switchD_1001d9ab_default;
  }
}



// Function: FUN_1001daa0 at 1001daa0

undefined4 * __thiscall FUN_1001daa0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024d68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1001dc80(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001db20 at 1001db20

int * __thiscall FUN_1001db20(void *this,int *param_1)

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



// Function: FUN_1001db50 at 1001db50

int * __thiscall FUN_1001db50(void *this,int *param_1)

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



// Function: FUN_1001db80 at 1001db80

void * __thiscall FUN_1001db80(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024d98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1001dc80(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001dc00 at 1001dc00

void * __thiscall FUN_1001dc00(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10024dc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1001dd40(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001dc80 at 1001dc80

int __thiscall FUN_1001dc80(void *this,int *param_1)

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
  
  puStack_c = &LAB_10024df8;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
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
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10029e34,&local_14);
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



// Function: FUN_1001dd40 at 1001dd40

int __thiscall FUN_1001dd40(void *this,int *param_1)

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
  
  puStack_c = &LAB_10024e28;
  local_10 = ExceptionList;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
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
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_1002e2c0,&local_14);
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



// Function: FUN_1001de00 at 1001de00

undefined4 * __fastcall FUN_1001de00(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001de50 at 1001de50

undefined4 * __fastcall FUN_1001de50(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001dec0 at 1001dec0

undefined4 * __thiscall FUN_1001dec0(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  code *pcVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)this = 0;
  HVar2 = FUN_1001f6e0(this,param_1,param_2,param_3);
  if ((HVar2 < 0) && (HVar2 != -0x7fffbffe)) {
    _com_issue_error(HVar2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  return (undefined4 *)this;
}



// Function: FUN_1001df00 at 1001df00

int * __thiscall FUN_1001df00(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1001df30 at 1001df30

int * __thiscall FUN_1001df30(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1001df50 at 1001df50

undefined4 * __thiscall FUN_1001df50(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001df90 at 1001df90

int * __thiscall FUN_1001df90(void *this,int param_1)

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
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10033d58);
  }
  return (int *)this;
}



// Function: FUN_1001dff0 at 1001dff0

int * __thiscall FUN_1001dff0(void *this,int param_1)

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
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10033d58);
}



// Function: _com_error at 1001e030

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



// Function: FUN_1001e070 at 1001e070

void __fastcall FUN_1001e070(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024eb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100352f8 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001e0c0 at 1001e0c0

void __fastcall FUN_1001e0c0(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024ee8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_100352f8 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001e110 at 1001e110

void __fastcall FUN_1001e110(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1001e120 at 1001e120

void __fastcall FUN_1001e120(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1001e130 at 1001e130

void __fastcall FUN_1001e130(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1001e140 at 1001e140

void __fastcall FUN_1001e140(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1001e150 at 1001e150

void __fastcall FUN_1001e150(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1001e160 at 1001e160

int * __thiscall FUN_1001e160(void *this,int param_1)

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
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10033d58);
  }
  return (int *)this;
}



// Function: FUN_1001e1c0 at 1001e1c0

int * __thiscall FUN_1001e1c0(void *this,int param_1)

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
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10033d58);
}



// Function: FUN_1001e200 at 1001e200

int * __thiscall FUN_1001e200(void *this,int *param_1)

{
  int iVar1;
  
  if ((int *)this != param_1) {
    Clear((int *)this);
    iVar1 = *param_1;
    *(int *)this = iVar1;
    if (iVar1 != 0) {
      InterlockedIncrement((LONG *)(iVar1 + 8));
    }
  }
  return (int *)this;
}



// Function: FUN_1001e230 at 1001e230

uint __thiscall FUN_1001e230(void *this,int param_1)

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



// Function: FUN_1001e250 at 1001e250

uint __thiscall FUN_1001e250(void *this,int param_1)

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



// Function: FUN_1001e270 at 1001e270

uint __thiscall FUN_1001e270(void *this,int param_1)

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



// Function: FUN_1001e290 at 1001e290

uint __thiscall FUN_1001e290(void *this,int param_1)

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



// Function: FUN_1001e300 at 1001e300

void __fastcall FUN_1001e300(int *param_1)

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



// Function: FUN_1001e380 at 1001e380

int * __fastcall FUN_1001e380(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001e3a0 at 1001e3a0

int * __fastcall FUN_1001e3a0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001e3c0 at 1001e3c0

ULONG __fastcall FUN_1001e3c0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[8].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a438);
  }
  return UVar1;
}



// Function: FUN_1001e3f0 at 1001e3f0

void FUN_1001e3f0(IID *param_1,LPCSTR param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_1001e410(param_1,param_2,0,(LPCSTR)0x0,param_3,param_4);
  return;
}



// Function: FUN_1001e410 at 1001e410

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1001e410(IID *param_1,LPCSTR param_2,int param_3,LPCSTR param_4,undefined4 param_5,
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
  puStack_c = &LAB_10024f18;
  local_10 = ExceptionList;
  local_30 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_30;
  if (param_2 == (LPCSTR)0x0) goto LAB_1001e586;
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
    if (((int)uVar3 < 0x401) && (cVar4 = FUN_1000bde0(uVar3), cVar4 != '\0')) {
      pWVar5 = (LPWSTR)&local_30;
    }
    else {
      pWVar5 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                       CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                 ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)&local_18,
                                  uVar3);
      _Memory = local_18;
    }
    pWVar5 = FUN_10004a10(pWVar5,param_2,(uint)pcVar1 & 0x7fffffff,3);
    if (pWVar5 != (LPWSTR)0x0) {
      pWVar6 = (LPWSTR)0x0;
      if (param_4 == (LPCSTR)0x0) {
LAB_1001e544:
        FUN_1001e5b0(param_1,pWVar5,param_3,(int)pWVar6,param_5,param_6,(HINSTANCE)0x0);
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
          if (((int)local_1c < 0x401) && (cVar4 = FUN_1000bde0((int)local_1c), cVar4 != '\0')) {
            pWVar6 = (LPWSTR)&local_30;
          }
          else {
            pWVar6 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                             CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                       ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)
                                        &local_18,(ulong)pcVar1);
            _Memory = local_18;
          }
          pWVar6 = FUN_10004a10(pWVar6,param_4,(uint)pcVar1 >> 1,3);
          if (pWVar6 != (LPWSTR)0x0) goto LAB_1001e544;
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
LAB_1001e586:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001e5b0 at 1001e5b0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1001e5b0(IID *param_1,LPWSTR param_2,int param_3,int param_4,undefined4 param_5,int param_6
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
  
  puStack_c = &LAB_10024f8d;
  local_10 = ExceptionList;
  local_440 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
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
      if (((int)uVar2 < 0x401) && (cVar3 = FUN_1000bde0(uVar2), cVar3 != '\0')) {
        pWVar6 = (LPWSTR)&local_440;
      }
      else {
        pWVar6 = (LPWSTR)ATL::_ATL_SAFE_ALLOCA_IMPL::
                         CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::Allocate
                                   ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)
                                    &local_420,uVar2);
        _Memory = local_420;
      }
      param_2 = FUN_10004a10(pWVar6,local_414,(uint)pcVar7 & 0x7fffffff,3);
      if (param_2 != (LPWSTR)0x0) goto LAB_1001e70f;
    }
    local_8 = 0xffffffff;
    ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
    ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
              ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)&local_420);
  }
  else {
LAB_1001e70f:
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
      iVar4 = (**(code **)*local_418)(local_418,&DAT_10029e34,&local_41c);
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



// Function: FUN_1001e880 at 1001e880

void __thiscall FUN_1001e880(void *this,int param_1)

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



// Function: FUN_1001e8a0 at 1001e8a0

void __thiscall FUN_1001e8a0(void *this,int param_1)

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



// Function: throwExceptionWithFileInfo at 1001e8c0

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
  puStack_c = &LAB_1002504f;
  local_10 = ExceptionList;
  uStack_207c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_207c;
  ExceptionList = &local_10;
  local_2044 = param_2;
  local_2048 = param_4;
  local_2038 = param_5;
  local_2030 = param_6;
  local_2040 = *(undefined4 *)((int)param_1 + 4);
  local_18 = uStack_207c;
  FUN_1001f770(param_1,&local_204c);
  piVar1 = local_204c;
  local_8 = 0;
  if ((local_204c != (int *)0x0) && (local_204c[1] == 0)) {
    pCVar3 = ConvertBSTRToString((LPCWSTR)*local_204c);
    piVar1[1] = (int)pCVar3;
  }
  local_203c = (void *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_1002e2b0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10029b80,&local_2054
                          );
  if (-1 < HVar4) {
    HVar4 = OleRun(local_2054);
    if (-1 < HVar4) {
      HVar4 = (*local_2054->lpVtbl->QueryInterface)(local_2054,(IID *)&DAT_1002a460,&local_203c);
    }
    (*local_2054->lpVtbl->Release)(local_2054);
    if (-1 < HVar4) goto LAB_1001e9f2;
  }
  local_203c = (void *)0x0;
  if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
    _com_issue_error(HVar4);
  }
LAB_1001e9f2:
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
  this = (void *)FUN_1001e300((int *)&local_203c);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1001fcc0(this,local_204c);
  local_8 = 1;
  FUN_1001eb85();
  return;
}



// Function: Catch@1001ea45 at 1001ea45

undefined * Catch_1001ea45(void)

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
  FUN_1001e3c0(pIVar2);
  if (*(LPCSTR *)(unaff_EBP + -0x2058) == (LPCSTR)0x0) {
    *(undefined1 *)(unaff_EBP + -0x2014) = 0;
    piVar3 = (int *)0x1fff;
    memset((void *)(unaff_EBP + -0x2013),0,0x1fff);
    FUN_1001f9d0((ushort)*(undefined4 *)(unaff_EBP + -0x203c),(LPSTR)(unaff_EBP + -0x2014));
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    FUN_10002650(&stack0xfffffffc,(LPCSTR)(unaff_EBP + -0x2014));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_01;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_1001fa60(pvVar1,piVar3);
  }
  else {
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    piVar3 = extraout_ECX_00;
    FUN_10002650(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP + -0x2058));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_02;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_1001fa60(pvVar1,piVar3);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_03;
  }
  FUN_1001fb20(pIVar2);
  *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
  piVar3 = extraout_ECX_04;
  FUN_10002650(&stack0xfffffffc,(LPCSTR)&PTR_1002e2d8);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  pvVar1 = *(void **)(unaff_EBP + -0x2038);
  if (pvVar1 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar1 = extraout_ECX_05;
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_1001fb50(pvVar1,piVar3);
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_06;
  }
  FUN_1001fc10(pIVar2);
  return &DAT_1001eb72;
}



// Function: FUN_1001eb85 at 1001eb85

/* WARNING: Removing unreachable block (ram,0x1001ee32) */

void FUN_1001eb85(void)

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
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_1002a438);
    piVar7 = extraout_ECX_00;
  }
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  FUN_10002650(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 9;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_01;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_1001fa60(pvVar12,piVar7);
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  piVar7 = extraout_ECX_02;
  FUN_10002650(&stack0xfffffffc,(LPCSTR)unaff_EBX);
  *(undefined1 *)(unaff_EBP - 4) = 10;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_03;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_1001fb50(pvVar12,piVar7);
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[4].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_1002a438);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  uVar10 = *(undefined4 *)(unaff_EBP - 0x203c);
  uVar13 = uVar10;
  UVar5 = (*pIVar2->lpVtbl[5].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_1002a438);
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
    piVar6 = FUN_1001f8b0(pvVar12,(undefined4 *)(unaff_EBP - 0x2040));
    *(undefined1 *)(unaff_EBP - 4) = 0xc;
    if ((undefined4 *)*piVar6 == (undefined4 *)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined4 *)*piVar6;
    }
    (**(code **)(*piVar7 + 0x14))(piVar7,uVar13);
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    FUN_100032d0((int *)(unaff_EBP - 0x2040));
    FUN_1001daa0((void *)(unaff_EBP - 0x2040),(int *)(unaff_EBP - 0x203c));
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
      _CxxThrowException((void *)(unaff_EBP - 0x2068),(ThrowInfo *)&DAT_10033d58);
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
  piVar7 = FUN_1001f8b0(pvVar12,(undefined4 *)(unaff_EBP - 0x2044));
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
  uVar10 = FUN_1001e410((IID *)(unaff_EBP - 0x2034),pCVar9,0,(LPCSTR)0x0,unaff_EBP - 0x2024,uVar10);
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
  uStack00000004 = 0x1001efa7;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1001efb0 at 1001efb0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1001efb0(undefined4 param_1,uchar *param_2)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_1001f1f0(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f020 at 1001f020

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1001f020(uchar *param_1)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_1001f1f0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f090 at 1001f090

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1001f090(uchar *param_1)

{
  char *in_stack_00000014;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000014,&stack0x00000018);
  FUN_1001f1f0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f100 at 1001f100

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1001f100(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_1001f1f0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f170 at 1001f170

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1001f170(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_1001f1f0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f1f0 at 1001f1f0

/* WARNING: Removing unreachable block (ram,0x1001f3be) */

void __cdecl FUN_1001f1f0(uchar *param_1)

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
  
  puStack_c = &LAB_100250d3;
  local_10 = ExceptionList;
  ppvObject = (void **)(DAT_100352f8 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 1;
  local_14 = (IUnknown *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_1002e2b0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10029b80,&local_20);
  if (HVar4 < 0) {
LAB_1001f284:
    local_14 = (IUnknown *)0x0;
    if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
      _com_issue_error(HVar4);
    }
  }
  else {
    HVar4 = OleRun(local_20);
    if (-1 < HVar4) {
      HVar4 = (*local_20->lpVtbl->QueryInterface)(local_20,(IID *)&DAT_1002a460,&local_14);
    }
    (*local_20->lpVtbl->Release)(local_20);
    if (HVar4 < 0) goto LAB_1001f284;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pbVar12 = PTR_s_APPEND_100352c8;
  do {
    bVar1 = *in_stack_00000018;
    bVar15 = bVar1 < *pbVar12;
    if (bVar1 != *pbVar12) {
LAB_1001f2d0:
      uVar5 = -(uint)bVar15 | 1;
      goto LAB_1001f2d5;
    }
    if (bVar1 == 0) break;
    bVar1 = in_stack_00000018[1];
    bVar15 = bVar1 < pbVar12[1];
    if (bVar1 != pbVar12[1]) goto LAB_1001f2d0;
    in_stack_00000018 = in_stack_00000018 + 2;
    pbVar12 = pbVar12 + 2;
  } while (bVar1 != 0);
  uVar5 = 0;
LAB_1001f2d5:
  if (uVar5 == 0) {
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_18 = (int *)0x0;
    Ordinal_200(0);
    if (local_18 != (int *)0x0) {
      FUN_1001dc00(&local_1c,(int *)&local_18);
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
        FUN_100032d0((int *)&local_2c);
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
    iVar6 = FUN_1001dc80(&local_18,piVar11);
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
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002a438);
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
      if (in_stack_00000014 != 3) goto LAB_1001f4cf;
      if (local_14 == (IUnknown *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
      if ((int)UVar7 < 0) {
        _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002a460);
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
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002a460);
    piVar11 = extraout_ECX_03;
  }
LAB_1001f4cf:
  local_2c = (int *)&stack0xffffffb4;
  FUN_10002650(&stack0xffffffb4,in_stack_00000024);
  local_8._0_1_ = 7;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_04;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_1001fa60(pIVar10,piVar11);
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
  FUN_10002650(&stack0xffffffb4,(LPCSTR)param_1);
  local_8._0_1_ = 8;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_07;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_1001fb50(pIVar10,piVar11);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[4].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002a438);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[5].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_1002a438);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_08;
  }
  ppuVar9 = (undefined4 **)FUN_1001f8b0(pIVar10,&local_2c);
  local_8._0_1_ = 9;
  if (&local_28 != ppuVar9) {
    Clear((int *)&local_28);
    puVar14 = *ppuVar9;
    local_28 = puVar14;
    if (puVar14 != (undefined4 *)0x0) {
      InterlockedIncrement(puVar14 + 2);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_100032d0((int *)&local_2c);
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
  _CxxThrowException(local_3c,(ThrowInfo *)&DAT_10033d58);
}



// Function: FUN_1001f6e0 at 1001f6e0

HRESULT __thiscall FUN_1001f6e0(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((uint)param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_1002a460,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10029b80,&param_3);
    if (HVar2 < 0) goto LAB_1001f759;
    HVar2 = OleRun(param_3);
    if (-1 < HVar2) {
      HVar2 = (*param_3->lpVtbl->QueryInterface)(param_3,(IID *)&DAT_1002a460,(void **)this);
    }
    (*param_3->lpVtbl->Release)(param_3);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_1001f759:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_1001f770 at 1001f770

undefined4 * __thiscall FUN_1001f770(void *this,undefined4 *param_1)

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
  puStack_c = &LAB_10025114;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 8);
  local_14 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1,&local_14,DAT_100352f8 ^ (uint)&stack0xfffffffc);
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



// Function: FUN_1001f830 at 1001f830

undefined4 __fastcall FUN_1001f830(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    return *(undefined4 *)(param_1 + 8);
  }
  return 0;
}



// Function: FUN_1001f8b0 at 1001f8b0

undefined4 * __thiscall FUN_1001f8b0(void *this,undefined4 *param_1)

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
  puStack_c = &LAB_10025154;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  iVar2 = (**(code **)(*this + 0x3c))(this,&local_14,DAT_100352f8 ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_1002a438);
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



// Function: FUN_1001f970 at 1001f970

uint __cdecl FUN_1001f970(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_1001f990 at 1001f990

uchar * __cdecl FUN_1001f990(uchar *param_1)

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



// Function: FUN_1001f9d0 at 1001f9d0

undefined4 __cdecl FUN_1001f9d0(ushort param_1,LPSTR param_2)

{
  FormatMessageA(0x1200,(LPCVOID)0x0,(uint)param_1,0x400,param_2,0x2000,(va_list *)0x0);
  return 0;
}



// Function: FUN_1001fa00 at 1001fa00

void __fastcall FUN_1001fa00(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[10].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a460);
  }
  return;
}



// Function: FUN_1001fa30 at 1001fa30

void __fastcall FUN_1001fa30(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[9].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a460);
  }
  return;
}



// Function: FUN_1001fa60 at 1001fa60

void __thiscall FUN_1001fa60(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10025178;
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
  iVar1 = (**(code **)(*this + 0x28))(this,iVar1,DAT_100352f8 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002a438);
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



// Function: FUN_1001fb20 at 1001fb20

void __fastcall FUN_1001fb20(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[5].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a438);
  }
  return;
}



// Function: FUN_1001fb50 at 1001fb50

void __thiscall FUN_1001fb50(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100251a8;
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
  iVar1 = (**(code **)(*this + 0x30))(this,iVar1,DAT_100352f8 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002a438);
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



// Function: FUN_1001fc10 at 1001fc10

void __fastcall FUN_1001fc10(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[4].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1002a438);
  }
  return;
}



// Function: FUN_1001fc40 at 1001fc40

void __fastcall FUN_1001fc40(int *param_1)

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



// Function: FUN_1001fcc0 at 1001fcc0

HRESULT __thiscall FUN_1001fcc0(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100251d8;
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
  iVar1 = (**(code **)(*this + 0x6c))(this,iVar1,DAT_100352f8 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1002a438);
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



// Function: FUN_1001fd90 at 1001fd90

void __cdecl FUN_1001fd90(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1001fdb0 at 1001fdb0

void FUN_1001fdb0(uchar *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x1001fdb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _mbsrchr(param_1,param_2);
  return;
}



// Function: CAtlBaseModule at 1001ff7f

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::CAtlBaseModule(void)
   
   Library: Visual Studio 2012 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  long lVar1;
  
  _ATL_BASE_MODULE70::_ATL_BASE_MODULE70((_ATL_BASE_MODULE70 *)this);
  *(undefined4 *)this = 0x38;
  *(undefined4 *)(this + 8) = 0x10000000;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined4 *)(this + 0xc) = 0xb00;
  *(undefined **)(this + 0x10) = &DAT_1002ff44;
  lVar1 = CComCriticalSection::Init((CComCriticalSection *)(this + 0x14));
  if (lVar1 < 0) {
    DAT_1003531c = 1;
  }
  return this;
}



// Function: FUN_1001ffbd at 1001ffbd

undefined4 * __thiscall FUN_1001ffbd(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: _ATL_BASE_MODULE70 at 1001ffcd

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



// Function: ~CAtlBaseModule at 1001fff7

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



// Function: operator[] at 10020015

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



// Function: Add at 1002003f

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
      FUN_10006230(0x80004005);
      pcVar2 = (code *)swi(3);
      iVar4 = (*pcVar2)();
      return iVar4;
    }
    if (iVar4 == 0) {
      _Count = 1;
LAB_10020076:
      pvVar3 = _recalloc(_Memory,_Count,4);
      if (pvVar3 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_1002008b;
      }
    }
    else {
      _Count = *(int *)(this + 4) * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_10020076;
    }
    iVar4 = 0;
  }
  else {
LAB_1002008b:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar4 = 1;
  }
  return iVar4;
}



// Function: AddResourceInstance at 100200b7

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



// Function: GetHInstanceAt at 100200ea

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



// Function: InternalSetAtIndex at 10020133

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



// Function: RemoveAll at 1002014d

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



// Function: RemoveAt at 1002016a

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



// Function: RemoveResourceInstance at 100201b2

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



// Function: memmove_s at 1002020f

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



// Function: CAtlComModule at 1002022e

/* Library Function - Single Match
    public: __thiscall ATL::CAtlComModule::CAtlComModule(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

CAtlComModule * __thiscall ATL::CAtlComModule::CAtlComModule(CAtlComModule *this)

{
  long lVar1;
  
  _ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)this);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined **)(this + 8) = &DAT_10033f48;
  *(undefined **)(this + 0xc) = &DAT_10033f48;
  lVar1 = CComCriticalSection::Init((CComCriticalSection *)(this + 0x10));
  if (lVar1 < 0) {
    DAT_1003531c = 1;
  }
  else {
    *(undefined4 *)this = 0x28;
  }
  return this;
}



// Function: _ATL_COM_MODULE70 at 1002026d

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

_ATL_COM_MODULE70 * __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  memset(this + 0x10,0,0x18);
  return this;
}



// Function: Term at 1002028a

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



// Function: `vector_constructor_iterator' at 100202d4

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



// Function: `vector_destructor_iterator' at 100202f3

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



// Function: _com_dispatch_method at 10020320

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
    (*(code *)PTR_FUN_100352cc)(lVar1,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_propget at 10020360

/* Library Function - Single Match
    long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2012 Release */

long _com_dispatch_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_propput at 10020380

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
    (*(code *)PTR_FUN_100352cc)(lVar2,local_c);
  }
  return lVar2;
}



// Function: _com_issue_error at 100203e0

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Library: Visual Studio 2012 Release */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_100352cc)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 10020400

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
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_10029c70,&param_2),
     ppuVar3 = local_8, -1 < HVar1)) {
    HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
    (*param_2->lpVtbl->Release)(param_2);
    ppuVar3 = local_8;
    if (HVar1 == 0) {
      local_8 = &local_8;
      iVar2 = Ordinal_200(0);
      local_8 = (undefined4 **)(~-(uint)(iVar2 != 0) & (uint)local_8);
      (*(code *)PTR_FUN_100352cc)(param_1,local_8);
      return;
    }
  }
  local_8 = ppuVar3;
  (*(code *)PTR_FUN_100352cc)(param_1);
  return;
}



// Function: FUN_10020480 at 10020480

void FUN_10020480(undefined *param_1)

{
  PTR_FUN_100352cc = param_1;
  return;
}



// Function: _variant_t at 10020490

/* Library Function - Single Match
    public: __thiscall _variant_t::_variant_t(long,unsigned short)
   
   Library: Visual Studio 2012 Release */

_variant_t * __thiscall _variant_t::_variant_t(_variant_t *this,long param_1,ushort param_2)

{
  code *pcVar1;
  _variant_t *p_Var2;
  
  if (param_2 != 3) {
    if (param_2 == 10) goto LAB_100204af;
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
LAB_100204af:
  *(undefined2 *)this = 10;
  *(long *)(this + 8) = param_1;
  return this;
}



// Function: ConvertBSTRToString at 10020510

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
  puStack_c = &LAB_10025200;
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



// Function: Catch_All@10020613 at 10020613

undefined * Catch_All_10020613(void)

{
  return &DAT_10020619;
}



// Function: ConvertStringToBSTR at 10020630

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
  pcStack_10 = FUN_100216bb;
  local_14 = ExceptionList;
  local_c = DAT_100352f8 ^ 0x10033d90;
  uVar1 = DAT_100352f8 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_100207b0 at 100207b0

uint FUN_100207b0(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_100207d0 at 100207d0

void FUN_100207d0(undefined4 param_1,undefined4 param_2)

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
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10033d58);
}



// Function: _com_dispatch_raw_method at 10020800

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



// Function: _com_dispatch_raw_propget at 10020840

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



// Function: _com_dispatch_raw_propput at 10020860

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



// Function: _com_invoke_helper at 100208c0

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
  pcStack_10 = FUN_100216bb;
  local_14 = ExceptionList;
  local_c = DAT_100352f8 ^ 0x10033e08;
  local_8c = DAT_100352f8 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_8c;
  ExceptionList = &local_14;
  local_20 = local_8c;
  puVar15 = &local_8c;
  if (param_1 == (IDispatch *)0x0) goto LAB_10020c35;
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
    if (local_3c == 0) goto LAB_10020c35;
    local_38 = 1;
    local_40 = &local_54;
  }
  if (local_3c != 0) {
    local_1c = (undefined1 *)&local_8c;
    local_34 = &local_8c;
    local_8 = 0xfffffffe;
    uStack_9c = 0x1002098c;
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
switchD_10020a05_caseD_f:
            puVar15 = (uint *)local_1c;
            if ((uVar1 & 0x2000) == 0) goto LAB_10020c35;
          }
switchD_10020a05_caseD_3:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *piVar14 = *piVar7;
          goto LAB_10020af0;
        }
        if (uVar4 == 0x4002) goto switchD_10020a05_caseD_3;
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
          goto switchD_10020a05_caseD_3;
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
          goto switchD_10020a05_caseD_f;
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
LAB_10020af0:
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
  iVar13 = (**(code **)(*(int *)param_1 + 0x18))(param_1,param_2,&DAT_1002a6d0,0,_param_3,&local_44)
  ;
  if (iVar13 < 0) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    if (iVar13 == -0x7ffdfff7) {
      _com_handle_excepinfo((tagEXCEPINFO *)&local_78,param_8);
      puVar15 = (uint *)local_1c;
    }
    goto LAB_10020c35;
  }
  puVar15 = (uint *)local_1c;
  if ((param_4 == 0) || (param_5 == (void *)0x0)) goto LAB_10020c35;
  if ((param_4 != 0xc) &&
     ((param_4 != (ushort)local_30 &&
      (iVar13 = Ordinal_12(&local_30,&local_30,0,_param_4), iVar13 < 0)))) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    goto LAB_10020c35;
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
        goto switchD_10020cdf_caseD_3;
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
        goto switchD_10020cdf_caseD_f;
      case 0x10:
      case 0x11:
        *(undefined1 *)param_5 = local_28;
      }
      goto LAB_10020c35;
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
switchD_10020cdf_caseD_f:
      if ((param_4 & 0x2000) == 0) {
        Ordinal_9(&local_30);
        puVar15 = (uint *)local_1c;
        goto LAB_10020c35;
      }
    }
  }
switchD_10020cdf_caseD_3:
  *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
LAB_10020c35:
  local_1c = (undefined1 *)puVar15;
  ExceptionList = local_14;
  lVar3 = __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return lVar3;
}



// Function: FUN_10020e70 at 10020e70

int FUN_10020e70(ushort param_1)

{
  if (0xfdff < param_1) {
    return -0x7ffb0001;
  }
  return param_1 + 0x80040200;
}



// Function: _com_handle_excepinfo at 10020ea0

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
      (**(code **)(*(int *)param_1 + 0xc))(param_1,&DAT_10029bd8);
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
      iVar4 = (*(code *)**(undefined4 **)param_1)(param_1,&DAT_10029e34,ppIVar3);
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



// Function: FUN_10020fb4 at 10020fb4

void __cdecl FUN_10020fb4(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: `eh_vector_constructor_iterator' at 10020fca

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
  FUN_10021022();
  return;
}



// Function: FUN_10021022 at 10021022

void FUN_10021022(void)

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



// Function: `eh_vector_destructor_iterator' at 10021032

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
  FUN_10021091();
  return;
}



// Function: FUN_10021091 at 10021091

void FUN_10021091(void)

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



// Function: FUN_100210a1 at 100210a1

undefined4 __cdecl FUN_100210a1(undefined4 *param_1)

{
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 != -0x1f928c9d) {
    return 0;
  }
  terminate();
  return extraout_EAX;
}



// Function: __ArrayUnwind at 100210ba

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



// Function: __onexit at 10021160

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
  
  local_8 = &DAT_10033e88;
  uStack_c = 0x1002116c;
  local_20[0] = DecodePointer(DAT_10035a64);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10035a64);
    local_24 = DecodePointer(DAT_10035a60);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10035a64 = EncodePointer(local_20[0]);
    DAT_10035a60 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_100211fc();
  }
  return p_Var1;
}



// Function: FUN_100211fc at 100211fc

void FUN_100211fc(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10021205

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2012 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: ___raise_securityfailure at 1002121a

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_10035a44 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_10035a44 == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}



// Function: ___report_gsfailure at 10021257

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
  _DAT_10035820 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_10035828 = (undefined4)uVar9;
  _DAT_10035838 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_1003583c = &stack0x00000004;
  _DAT_10035778 = 0x10001;
  _DAT_10035728 = 0xc0000409;
  _DAT_1003572c = 1;
  _DAT_10035738 = 1;
  DAT_1003573c = 2;
  _DAT_10035734 = unaff_retaddr;
  _DAT_10035804 = in_GS;
  _DAT_10035808 = in_FS;
  _DAT_1003580c = in_ES;
  _DAT_10035810 = in_DS;
  _DAT_10035814 = unaff_EDI;
  _DAT_10035818 = unaff_ESI;
  _DAT_1003581c = unaff_EBX;
  _DAT_10035824 = uVar3;
  _DAT_1003582c = unaff_EBP;
  DAT_10035830 = unaff_retaddr;
  _DAT_10035834 = in_CS;
  _DAT_10035840 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_1003000c);
  return;
}



// Function: ___report_rangecheckfailure at 10021350

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}



// Function: ___report_securityfailure at 1002135c

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
  _DAT_10035820 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_10035828 = (undefined4)uVar9;
  _DAT_10035838 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_1003583c = &param_1;
  _DAT_10035728 = 0xc0000409;
  _DAT_1003572c = 1;
  _DAT_10035738 = 1;
  DAT_1003573c = param_1;
  _DAT_10035734 = unaff_retaddr;
  _DAT_10035804 = in_GS;
  _DAT_10035808 = in_FS;
  _DAT_1003580c = in_ES;
  _DAT_10035810 = in_DS;
  _DAT_10035814 = unaff_EDI;
  _DAT_10035818 = unaff_ESI;
  _DAT_1003581c = unaff_EBX;
  _DAT_10035824 = uVar3;
  _DAT_1003582c = unaff_EBP;
  DAT_10035830 = unaff_retaddr;
  _DAT_10035834 = in_CS;
  _DAT_10035840 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_1003000c);
  return;
}



// Function: ___report_securityfailureEx at 1002142a

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
  _DAT_10035838 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_1003583c = &param_1;
  _DAT_10035728 = 0xc0000409;
  _DAT_1003572c = 1;
  if ((param_2 != 0) && (param_3 == 0)) {
    param_2 = 0;
  }
  if (0xe < param_2) {
    param_2 = param_2 - 1;
  }
  _DAT_10035738 = param_2 + 1;
  DAT_1003573c = param_1;
  _DAT_10035734 = unaff_retaddr;
  _DAT_10035804 = in_GS;
  _DAT_10035808 = in_FS;
  _DAT_1003580c = in_ES;
  _DAT_10035810 = in_DS;
  _DAT_10035814 = unaff_EDI;
  _DAT_10035818 = unaff_ESI;
  _DAT_1003581c = unaff_EBX;
  _DAT_10035824 = uVar3;
  _DAT_1003582c = unaff_EBP;
  DAT_10035830 = unaff_retaddr;
  _DAT_10035834 = in_CS;
  _DAT_10035840 = in_SS;
  for (local_8 = 0; _DAT_10035820 = (undefined4)((ulonglong)uVar9 >> 0x20),
      _DAT_10035828 = (undefined4)uVar9, local_8 < param_2; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_10035740 + local_8 * 4) = *(undefined4 *)(param_3 + local_8 * 4);
    uVar9 = CONCAT44(_DAT_10035820,_DAT_10035828);
  }
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_1003000c);
  return;
}



// Function: FUN_10021550 at 10021550

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10021550(uint param_1)

{
  operator_new(param_1);
  FUN_10021578();
  return;
}



// Function: Catch_All@1002156b at 1002156b

undefined * Catch_All_1002156b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  return &DAT_10021575;
}



// Function: FUN_10021578 at 10021578

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10021578(void)

{
  return;
}



// Function: FUN_1002157e at 1002157e

void FUN_1002157e(uint param_1)

{
  FUN_10021550(param_1);
  return;
}



// Function: FUN_10021587 at 10021587

void __cdecl FUN_10021587(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_10021595 at 10021595

void __cdecl FUN_10021595(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// Function: __security_check_cookie at 100215f8

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Library: Visual Studio 2012 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_100352f8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __allmul at 10021620

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio 2010 Debug */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



// Function: __alloca_probe_16 at 10021660

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



// Function: __alloca_probe_8 at 10021676

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



// Function: __alloca_probe at 10021690

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



// Function: FUN_100216bb at 100216bb

void __cdecl
FUN_100216bb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_100352f8,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 100216ee

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



// Function: __CRT_INIT@12 at 100217a9

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
    if (DAT_10035a48 < 1) {
      return 0;
    }
    DAT_10035a48 = DAT_10035a48 + -1;
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_10035a54 != (void *)0x0) {
        pvVar3 = DAT_10035a54;
        pvVar2 = DAT_10035a54;
      }
      DAT_10035a54 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_100217fc;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_100217fc:
    if (DAT_10035a58 == 2) {
      _Memory = (int *)DecodePointer(DAT_10035a64);
      if (_Memory != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10035a60);
        param_1 = piVar4;
        param_2 = _Memory;
        param_3 = _Memory;
        while (piVar4 = piVar4 + -1, _Memory <= piVar4) {
          if ((*piVar4 != 0) && (pvVar5 = EncodePointer((PVOID)0x0), (PVOID)*piVar4 != pvVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            pvVar5 = EncodePointer((PVOID)0x0);
            *piVar4 = (int)pvVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10035a64);
            piVar8 = (int *)DecodePointer(DAT_10035a60);
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
        DAT_10035a60 = EncodePointer((PVOID)0x0);
        DAT_10035a64 = DAT_10035a60;
      }
      DAT_10035a58 = 0;
      if (!bVar1) {
        LOCK();
        DAT_10035a54 = (void *)0x0;
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
      if (DAT_10035a54 != (void *)0x0) {
        pvVar3 = DAT_10035a54;
        pvVar2 = DAT_10035a54;
      }
      DAT_10035a54 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_10021917;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_10021917:
    if (DAT_10035a58 == 0) {
      DAT_10035a58 = 1;
      iVar9 = initterm_e(&DAT_10029560,&DAT_1002956c);
      if (iVar9 != 0) {
        return 0;
      }
      initterm(&DAT_10029244,&DAT_1002955c);
      DAT_10035a58 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      LOCK();
      DAT_10035a54 = (void *)0x0;
      UNLOCK();
    }
    if ((DAT_10035a5c != (code *)0x0) &&
       (BVar10 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10035a5c), BVar10 != 0)) {
      (*DAT_10035a5c)(param_1,2,param_3);
    }
    DAT_10035a48 = DAT_10035a48 + 1;
  }
  return 1;
}



// Function: entry at 1002199e

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_1,param_2,param_3);
  return;
}



// Function: ___DllMainCRTStartup at 100219c1

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10021a72) */
/* WARNING: Removing unreachable block (ram,0x10021a08) */
/* WARNING: Removing unreachable block (ram,0x10021aa4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2012 Release */

uint __cdecl ___DllMainCRTStartup(HMODULE param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  _DAT_10035300 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10035a48 == 0)) {
    uVar1 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (uVar1 = __CRT_INIT_12(&param_1->unused,param_2,param_3), uVar1 != 0)) {
    uVar1 = FUN_100013a0(param_1,(int)param_2);
    if ((param_2 == (int *)0x1) && (uVar1 == 0)) {
      FUN_100013a0(param_1,0);
      __CRT_INIT_12(&param_1->unused,(int *)0x0,param_3);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar2 = __CRT_INIT_12(&param_1->unused,param_2,param_3);
      uVar1 = uVar1 & -(uint)(iVar2 != 0);
    }
  }
  FUN_10021ae9();
  return uVar1;
}



// Function: FUN_10021ae9 at 10021ae9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ae9(void)

{
  _DAT_10035300 = 0xffffffff;
  return;
}



// Function: __SEH_prolog4 at 10021b20

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100352f8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10021b65

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



// Function: __EH_epilog3 at 10021baa

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



// Function: __EH_prolog3_catch at 10021c45

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100352f8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __FindPESection at 10021cd0

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



// Function: __IsNonwritableInCurrentImage at 10021d20

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
  
  pcStack_10 = FUN_100216bb;
  local_14 = ExceptionList;
  local_c = DAT_100352f8 ^ 0x10033f28;
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



// Function: __ValidateImageBase at 10021de0

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



// Function: ___security_init_cookie at 10021e11

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
  if ((DAT_100352f8 == 0xbb40e64e) || ((DAT_100352f8 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_100352f8 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_100352f8 == 0xbb40e64e) {
      DAT_100352f8 = 0xbb40e64f;
    }
    else if ((DAT_100352f8 & 0xffff0000) == 0) {
      DAT_100352f8 = DAT_100352f8 | (DAT_100352f8 | 0x4711) << 0x10;
    }
    DAT_100352fc = ~DAT_100352f8;
  }
  else {
    DAT_100352fc = ~DAT_100352f8;
  }
  return;
}



// Function: Unwind@10021f40 at 10021f40

void Unwind_10021f40(void)

{
  FUN_10003390();
  return;
}



// Function: Unwind@10021f70 at 10021f70

void Unwind_10021f70(void)

{
  int unaff_EBP;
  
  FUN_10002e50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10021fa0 at 10021fa0

void Unwind_10021fa0(void)

{
  int unaff_EBP;
  
  _anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal
            ((_ExceptionPtr_normal *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10021fab at 10021fab

void Unwind_10021fab(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10021fe0 at 10021fe0

void Unwind_10021fe0(void)

{
  int unaff_EBP;
  
  CCIAuditTrail_Initialize(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022010 at 10022010

void Unwind_10022010(void)

{
  int unaff_EBP;
  
  CCIAuditTrail_Initialize(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022040 at 10022040

void Unwind_10022040(void)

{
  int unaff_EBP;
  
  FUN_10002f20(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022070 at 10022070

void Unwind_10022070(void)

{
  FUN_10002ff0();
  return;
}



// Function: Unwind@10022078 at 10022078

void Unwind_10022078(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100220a0 at 100220a0

void Unwind_100220a0(void)

{
  FUN_10002ff0();
  return;
}



// Function: Unwind@100220d0 at 100220d0

void Unwind_100220d0(void)

{
  int unaff_EBP;
  
  FUN_10002cc0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022100 at 10022100

void Unwind_10022100(void)

{
  int unaff_EBP;
  
  FUN_10002cf0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022130 at 10022130

void Unwind_10022130(void)

{
  int unaff_EBP;
  
  FUN_10002d20(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022160 at 10022160

void Unwind_10022160(void)

{
  int unaff_EBP;
  
  FUN_10002d20(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022190 at 10022190

void Unwind_10022190(void)

{
  int unaff_EBP;
  
  FUN_10002d50(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100221c0 at 100221c0

void Unwind_100221c0(void)

{
  int unaff_EBP;
  
  FUN_10002d80(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100221f0 at 100221f0

void Unwind_100221f0(void)

{
  FUN_10003190();
  return;
}



// Function: Unwind@10022220 at 10022220

void Unwind_10022220(void)

{
  int unaff_EBP;
  
  FUN_10003000(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022250 at 10022250

void Unwind_10022250(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10022280 at 10022280

void Unwind_10022280(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100222b0 at 100222b0

void Unwind_100222b0(void)

{
  FUN_10002f80();
  return;
}



// Function: Unwind@100222e0 at 100222e0

void Unwind_100222e0(void)

{
  int unaff_EBP;
  
  FUN_10002db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022310 at 10022310

void Unwind_10022310(void)

{
  int unaff_EBP;
  
  FID_conflict__CAtlWinModule((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10022340 at 10022340

void Unwind_10022340(void)

{
  FUN_10002f80();
  return;
}



// Function: Unwind@10022370 at 10022370

void Unwind_10022370(void)

{
  int unaff_EBP;
  
  FUN_100032f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100223a0 at 100223a0

void Unwind_100223a0(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100223d0 at 100223d0

void Unwind_100223d0(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022400 at 10022400

void Unwind_10022400(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10022430 at 10022430

void Unwind_10022430(void)

{
  int unaff_EBP;
  
  FUN_10002f00(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022460 at 10022460

void Unwind_10022460(void)

{
  int unaff_EBP;
  
  FUN_10002e50(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022490 at 10022490

void Unwind_10022490(void)

{
  int unaff_EBP;
  
  _anon_026BA49F::_ExceptionPtr_normal::~_ExceptionPtr_normal
            ((_ExceptionPtr_normal *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002249b at 1002249b

void Unwind_1002249b(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100224d0 at 100224d0

void Unwind_100224d0(void)

{
  int unaff_EBP;
  
  CCIAuditTrail_Initialize(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022500 at 10022500

void Unwind_10022500(void)

{
  int unaff_EBP;
  
  CCIAuditTrail_Initialize(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022530 at 10022530

void Unwind_10022530(void)

{
  int unaff_EBP;
  
  FUN_10002f20(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022560 at 10022560

void Unwind_10022560(void)

{
  FUN_10002ff0();
  return;
}



// Function: Unwind@10022568 at 10022568

void Unwind_10022568(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10022590 at 10022590

void Unwind_10022590(void)

{
  FUN_10002ff0();
  return;
}



// Function: Unwind@100225c0 at 100225c0

void Unwind_100225c0(void)

{
  int unaff_EBP;
  
  FUN_10002cc0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100225f0 at 100225f0

void Unwind_100225f0(void)

{
  int unaff_EBP;
  
  FUN_10002cf0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022620 at 10022620

void Unwind_10022620(void)

{
  int unaff_EBP;
  
  FUN_10002d20(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022650 at 10022650

void Unwind_10022650(void)

{
  int unaff_EBP;
  
  FUN_10002d50(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022680 at 10022680

void Unwind_10022680(void)

{
  int unaff_EBP;
  
  FUN_10002d80(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100226b0 at 100226b0

void Unwind_100226b0(void)

{
  FUN_10003190();
  return;
}



// Function: Unwind@100226e0 at 100226e0

void Unwind_100226e0(void)

{
  int unaff_EBP;
  
  FUN_10003000(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022710 at 10022710

void Unwind_10022710(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10022740 at 10022740

void Unwind_10022740(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022770 at 10022770

void Unwind_10022770(void)

{
  FUN_10002f80();
  return;
}



// Function: Unwind@100227a0 at 100227a0

void Unwind_100227a0(void)

{
  int unaff_EBP;
  
  FUN_10002db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100227d0 at 100227d0

void Unwind_100227d0(void)

{
  int unaff_EBP;
  
  FID_conflict__CAtlWinModule((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10022800 at 10022800

void Unwind_10022800(void)

{
  FUN_10002f80();
  return;
}



// Function: Unwind@10022830 at 10022830

void Unwind_10022830(void)

{
  int unaff_EBP;
  
  FUN_100032f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022860 at 10022860

void Unwind_10022860(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10022890 at 10022890

void Unwind_10022890(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100228c0 at 100228c0

void Unwind_100228c0(void)

{
  int unaff_EBP;
  
  FUN_10002f00(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100228f0 at 100228f0

void Unwind_100228f0(void)

{
  int unaff_EBP;
  
  FUN_10002840((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100228f8 at 100228f8

void Unwind_100228f8(void)

{
  int unaff_EBP;
  
  FUN_10002860((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022920 at 10022920

void Unwind_10022920(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022950 at 10022950

void Unwind_10022950(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022980 at 10022980

void Unwind_10022980(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x121c));
  return;
}



// Function: Unwind@1002298b at 1002298b

void Unwind_1002298b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1250));
  return;
}



// Function: Unwind@10022996 at 10022996

void Unwind_10022996(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x1118));
  return;
}



// Function: Unwind@100229d0 at 100229d0

void Unwind_100229d0(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10022a00 at 10022a00

void Unwind_10022a00(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@10022a40 at 10022a40

void Unwind_10022a40(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022a70 at 10022a70

void Unwind_10022a70(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@10022a7b at 10022a7b

void Unwind_10022a7b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x148));
  return;
}



// Function: Unwind@10022a86 at 10022a86

void Unwind_10022a86(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x17c));
  return;
}



// Function: Unwind@10022a91 at 10022a91

void Unwind_10022a91(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@10022ad0 at 10022ad0

void Unwind_10022ad0(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@10022adb at 10022adb

void Unwind_10022adb(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10022ae6 at 10022ae6

void Unwind_10022ae6(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10022b20 at 10022b20

void Unwind_10022b20(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10022b28 at 10022b28

void Unwind_10022b28(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022b50 at 10022b50

void Unwind_10022b50(void)

{
  int unaff_EBP;
  
  FUN_10021587(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022b80 at 10022b80

void Unwind_10022b80(void)

{
  int unaff_EBP;
  
  FUN_10021587(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022bb0 at 10022bb0

void Unwind_10022bb0(void)

{
  int unaff_EBP;
  
  FUN_10021587(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022be0 at 10022be0

void Unwind_10022be0(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10022c10 at 10022c10

void Unwind_10022c10(void)

{
  int unaff_EBP;
  
  ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
  ~CComCritSecLock<class_ATL::CComCriticalSection>
            ((CComCritSecLock<class_ATL::CComCriticalSection> *)(unaff_EBP + -0x154));
  return;
}



// Function: Unwind@10022c1b at 10022c1b

void Unwind_10022c1b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x134));
  return;
}



// Function: Unwind@10022c26 at 10022c26

void Unwind_10022c26(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x128));
  return;
}



// Function: Unwind@10022c31 at 10022c31

void Unwind_10022c31(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@10022c3c at 10022c3c

void Unwind_10022c3c(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@10022c70 at 10022c70

void Unwind_10022c70(void)

{
  FUN_10001410();
  return;
}



// Function: Unwind@10022c89 at 10022c89

void Unwind_10022c89(void)

{
  FUN_10001420();
  return;
}



// Function: Unwind@10022cc0 at 10022cc0

void Unwind_10022cc0(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022cc8 at 10022cc8

void Unwind_10022cc8(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10022cf0 at 10022cf0

void Unwind_10022cf0(void)

{
  int unaff_EBP;
  
  FUN_10021595(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022d02 at 10022d02

void Unwind_10022d02(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10022d30 at 10022d30

void Unwind_10022d30(void)

{
  int unaff_EBP;
  
  FUN_100030d0(unaff_EBP + -0x58);
  return;
}



// Function: Unwind@10022d60 at 10022d60

void Unwind_10022d60(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x128));
  return;
}



// Function: Unwind@10022da0 at 10022da0

void Unwind_10022da0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@10022dab at 10022dab

void Unwind_10022dab(void)

{
  int unaff_EBP;
  
  ~CTempBuffer<>((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10022de0 at 10022de0

void Unwind_10022de0(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x112c));
  return;
}



// Function: Unwind@10022deb at 10022deb

void Unwind_10022deb(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x1140));
  return;
}



// Function: Unwind@10022df6 at 10022df6

void Unwind_10022df6(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x1160));
  return;
}



// Function: Unwind@10022e01 at 10022e01

void Unwind_10022e01(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x1170));
  return;
}



// Function: Unwind@10022e0c at 10022e0c

void Unwind_10022e0c(void)

{
  int unaff_EBP;
  
  FUN_100030f0((CRegKey *)(unaff_EBP + -0x1180));
  return;
}



// Function: Unwind@10022e40 at 10022e40

void Unwind_10022e40(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022e70 at 10022e70

void Unwind_10022e70(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022ea0 at 10022ea0

void Unwind_10022ea0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022ed0 at 10022ed0

void Unwind_10022ed0(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10022f00 at 10022f00

void Unwind_10022f00(void)

{
  int unaff_EBP;
  
  FUN_10003110((undefined4 *)(unaff_EBP + -0x96c));
  return;
}



// Function: Unwind@10022f0b at 10022f0b

void Unwind_10022f0b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x940));
  return;
}



// Function: Unwind@10022f40 at 10022f40

void Unwind_10022f40(void)

{
  int unaff_EBP;
  
  FUN_10003110((undefined4 *)(unaff_EBP + -0x970));
  return;
}



// Function: Unwind@10022f4b at 10022f4b

void Unwind_10022f4b(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x944));
  return;
}



// Function: Unwind@10022f80 at 10022f80

void Unwind_10022f80(void)

{
  DAT_10035358 = DAT_10035358 & 0xfffffffe;
  return;
}



// Function: Unwind@10022fd0 at 10022fd0

void Unwind_10022fd0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10023010 at 10023010

void Unwind_10023010(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10023050 at 10023050

void Unwind_10023050(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10023090 at 10023090

void Unwind_10023090(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1002309b at 1002309b

void Unwind_1002309b(void)

{
  int unaff_EBP;
  
  FID_conflict__CAtlWinModule((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@100230a6 at 100230a6

void Unwind_100230a6(void)

{
  int unaff_EBP;
  
  FUN_10013a60((int *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@100230b1 at 100230b1

void Unwind_100230b1(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@100230bc at 100230bc

void Unwind_100230bc(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@100230c7 at 100230c7

void Unwind_100230c7(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@100230d2 at 100230d2

void Unwind_100230d2(void)

{
  int unaff_EBP;
  
  FUN_10013ac0((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@100230dd at 100230dd

void Unwind_100230dd(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@10023103 at 10023103

void Unwind_10023103(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1002310e at 1002310e

void Unwind_1002310e(void)

{
  int unaff_EBP;
  
  FID_conflict__CAtlWinModule((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10023119 at 10023119

void Unwind_10023119(void)

{
  int unaff_EBP;
  
  FUN_10013a60((int *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@10023124 at 10023124

void Unwind_10023124(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@1002312f at 1002312f

void Unwind_1002312f(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1002313a at 1002313a

void Unwind_1002313a(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@10023145 at 10023145

void Unwind_10023145(void)

{
  int unaff_EBP;
  
  FUN_10013ac0((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@10023150 at 10023150

void Unwind_10023150(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@10023176 at 10023176

void Unwind_10023176(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@10023181 at 10023181

void Unwind_10023181(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x224) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x224) = *(uint *)(unaff_EBP + -0x224) & 0xfffffffe;
    FUN_100032d0((int *)(unaff_EBP + -0x238));
    return;
  }
  return;
}



// Function: Unwind@100231a3 at 100231a3

void Unwind_100231a3(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x224) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x224) = *(uint *)(unaff_EBP + -0x224) & 0xfffffffd;
    FUN_100032d0((int *)(unaff_EBP + -0x24c));
    return;
  }
  return;
}



// Function: Unwind@100231c5 at 100231c5

void Unwind_100231c5(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x268));
  return;
}



// Function: Unwind@100231f8 at 100231f8

void Unwind_100231f8(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10023200 at 10023200

void Unwind_10023200(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x10c);
  return;
}



// Function: Unwind@1002320b at 1002320b

void Unwind_1002320b(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@10023216 at 10023216

void Unwind_10023216(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1002321e at 1002321e

void Unwind_1002321e(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10023229 at 10023229

void Unwind_10023229(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10023231 at 10023231

void Unwind_10023231(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1002323c at 1002323c

void Unwind_1002323c(void)

{
  int unaff_EBP;
  
  FUN_10013ba0((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10023244 at 10023244

void Unwind_10023244(void)

{
  int unaff_EBP;
  
  FUN_10013b60((int *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1002324c at 1002324c

void Unwind_1002324c(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10023257 at 10023257

void Unwind_10023257(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x120));
  return;
}



// Function: Unwind@10023262 at 10023262

void Unwind_10023262(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x168);
  return;
}



// Function: Unwind@1002326d at 1002326d

void Unwind_1002326d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10023275 at 10023275

void Unwind_10023275(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1002327d at 1002327d

void Unwind_1002327d(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10023285 at 10023285

void Unwind_10023285(void)

{
  int unaff_EBP;
  
  FUN_1001d3a0((undefined4 *)(unaff_EBP + -0x1cc));
  return;
}



// Function: Unwind@10023290 at 10023290

void Unwind_10023290(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x180);
  return;
}



// Function: Unwind@1002329b at 1002329b

void Unwind_1002329b(void)

{
  int unaff_EBP;
  
  FUN_10013a00((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100232a3 at 100232a3

void Unwind_100232a3(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100232d6 at 100232d6

void Unwind_100232d6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100232f9 at 100232f9

void Unwind_100232f9(void)

{
  int unaff_EBP;
  
  FUN_10013ac0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023301 at 10023301

void Unwind_10023301(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x80);
  return;
}



// Function: Unwind@10023309 at 10023309

void Unwind_10023309(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x60);
  return;
}



// Function: Unwind@10023311 at 10023311

void Unwind_10023311(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1002333a at 1002333a

void Unwind_1002333a(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023342 at 10023342

void Unwind_10023342(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x7c);
  return;
}



// Function: Unwind@1002334a at 1002334a

void Unwind_1002334a(void)

{
  int unaff_EBP;
  
  FUN_100139e0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023352 at 10023352

void Unwind_10023352(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002335a at 1002335a

void Unwind_1002335a(void)

{
  int unaff_EBP;
  
  FUN_10013ba0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10023362 at 10023362

void Unwind_10023362(void)

{
  int unaff_EBP;
  
  FID_conflict__bad_alloc((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002336a at 1002336a

void Unwind_1002336a(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0xac);
  return;
}



// Function: Unwind@10023375 at 10023375

void Unwind_10023375(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1002339e at 1002339e

void Unwind_1002339e(void)

{
  int unaff_EBP;
  
  FUN_10013950((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100233a6 at 100233a6

void Unwind_100233a6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100233c9 at 100233c9

void Unwind_100233c9(void)

{
  int unaff_EBP;
  
  FUN_10013950((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100233d1 at 100233d1

void Unwind_100233d1(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100233f4 at 100233f4

void Unwind_100233f4(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10023417 at 10023417

void Unwind_10023417(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002341f at 1002341f

void Unwind_1002341f(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023442 at 10023442

void Unwind_10023442(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002344a at 1002344a

void Unwind_1002344a(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002346d at 1002346d

void Unwind_1002346d(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023475 at 10023475

void Unwind_10023475(void)

{
  int unaff_EBP;
  
  FUN_10013a40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023498 at 10023498

void Unwind_10023498(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100234bb at 100234bb

void Unwind_100234bb(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100234c3 at 100234c3

void Unwind_100234c3(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100234cb at 100234cb

void Unwind_100234cb(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100234d3 at 100234d3

void Unwind_100234d3(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100234db at 100234db

void Unwind_100234db(void)

{
  int unaff_EBP;
  
  FUN_100139c0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10023501 at 10023501

void Unwind_10023501(void)

{
  int unaff_EBP;
  
  FUN_10013a60(*(int **)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1002350c at 1002350c

void Unwind_1002350c(void)

{
  int unaff_EBP;
  
  FUN_10013d20(unaff_EBP + -0xa0);
  return;
}



// Function: Unwind@10023517 at 10023517

void Unwind_10023517(void)

{
  int unaff_EBP;
  
  FUN_10013a60(*(int **)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10023522 at 10023522

void Unwind_10023522(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0xb0);
  return;
}



// Function: Unwind@1002352d at 1002352d

void Unwind_1002352d(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x44);
  return;
}



// Function: Unwind@10023553 at 10023553

void Unwind_10023553(void)

{
  int unaff_EBP;
  
  FUN_100139c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002355b at 1002355b

void Unwind_1002355b(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x44);
  return;
}



// Function: Unwind@10023563 at 10023563

void Unwind_10023563(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x54);
  return;
}



// Function: Unwind@10023586 at 10023586

void Unwind_10023586(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1002358e at 1002358e

void Unwind_1002358e(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023596 at 10023596

void Unwind_10023596(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100235c3 at 100235c3

void Unwind_100235c3(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x13c));
  return;
}



// Function: Unwind@100235ce at 100235ce

void Unwind_100235ce(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x148));
  return;
}



// Function: Unwind@100235d9 at 100235d9

void Unwind_100235d9(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x140));
  return;
}



// Function: Unwind@100235e4 at 100235e4

void Unwind_100235e4(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@100235ef at 100235ef

void Unwind_100235ef(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x164));
  return;
}



// Function: Unwind@100235fa at 100235fa

void Unwind_100235fa(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1ac));
  return;
}



// Function: Unwind@1002362d at 1002362d

void Unwind_1002362d(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023635 at 10023635

void Unwind_10023635(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0xc0);
  return;
}



// Function: Unwind@10023640 at 10023640

void Unwind_10023640(void)

{
  int unaff_EBP;
  
  FUN_1001d3a0((undefined4 *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@1002364b at 1002364b

void Unwind_1002364b(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0xa8);
  return;
}



// Function: Unwind@10023656 at 10023656

void Unwind_10023656(void)

{
  int unaff_EBP;
  
  FUN_1001d3a0((undefined4 *)(unaff_EBP + -0xe8));
  return;
}



// Function: Unwind@1002367f at 1002367f

void Unwind_1002367f(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10023687 at 10023687

void Unwind_10023687(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1002368f at 1002368f

void Unwind_1002368f(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023697 at 10023697

void Unwind_10023697(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002369f at 1002369f

void Unwind_1002369f(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100236a7 at 100236a7

void Unwind_100236a7(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100236af at 100236af

void Unwind_100236af(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100236d2 at 100236d2

void Unwind_100236d2(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100236da at 100236da

void Unwind_100236da(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffe;
    FUN_10013a80(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002370e at 1002370e

void Unwind_1002370e(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023716 at 10023716

void Unwind_10023716(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002371e at 1002371e

void Unwind_1002371e(void)

{
  int unaff_EBP;
  
  FUN_10002f00(*(undefined4 **)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10023729 at 10023729

void Unwind_10023729(void)

{
  int unaff_EBP;
  
  FUN_10013b80(*(int **)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10023734 at 10023734

void Unwind_10023734(void)

{
  int unaff_EBP;
  
  FUN_10002f00(*(undefined4 **)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1002373f at 1002373f

void Unwind_1002373f(void)

{
  int unaff_EBP;
  
  FUN_10013b80(*(int **)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1002374a at 1002374a

void Unwind_1002374a(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023752 at 10023752

void Unwind_10023752(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1002375a at 1002375a

void Unwind_1002375a(void)

{
  int unaff_EBP;
  
  FUN_10002f00(*(undefined4 **)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10023765 at 10023765

void Unwind_10023765(void)

{
  int unaff_EBP;
  
  FUN_10013b80(*(int **)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10023770 at 10023770

void Unwind_10023770(void)

{
  int unaff_EBP;
  
  FUN_10013a40((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100237a0 at 100237a0

void Unwind_100237a0(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100237d0 at 100237d0

void Unwind_100237d0(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023800 at 10023800

void Unwind_10023800(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023830 at 10023830

void Unwind_10023830(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023860 at 10023860

void Unwind_10023860(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023890 at 10023890

void Unwind_10023890(void)

{
  int unaff_EBP;
  
  FUN_10013aa0(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100238c0 at 100238c0

void Unwind_100238c0(void)

{
  int unaff_EBP;
  
  FUN_10013aa0(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100238f0 at 100238f0

void Unwind_100238f0(void)

{
  int unaff_EBP;
  
  FUN_10013ba0(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023920 at 10023920

void Unwind_10023920(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023950 at 10023950

void Unwind_10023950(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023980 at 10023980

void Unwind_10023980(void)

{
  int unaff_EBP;
  
  FUN_10013b80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100239b0 at 100239b0

void Unwind_100239b0(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100239e0 at 100239e0

void Unwind_100239e0(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023a10 at 10023a10

void Unwind_10023a10(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023a40 at 10023a40

void Unwind_10023a40(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023a70 at 10023a70

void Unwind_10023a70(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023aa0 at 10023aa0

void Unwind_10023aa0(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023ad0 at 10023ad0

void Unwind_10023ad0(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023b00 at 10023b00

void Unwind_10023b00(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023b30 at 10023b30

void Unwind_10023b30(void)

{
  int unaff_EBP;
  
  FUN_10013ba0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10023b60 at 10023b60

void Unwind_10023b60(void)

{
  int unaff_EBP;
  
  FUN_10013bc0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10023b90 at 10023b90

void Unwind_10023b90(void)

{
  int unaff_EBP;
  
  FUN_10013ae0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10023bc0 at 10023bc0

void Unwind_10023bc0(void)

{
  FUN_10002f80();
  return;
}



// Function: Unwind@10023bf0 at 10023bf0

void Unwind_10023bf0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023c20 at 10023c20

void Unwind_10023c20(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023c50 at 10023c50

void Unwind_10023c50(void)

{
  int unaff_EBP;
  
  FUN_10013bc0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10023c80 at 10023c80

void Unwind_10023c80(void)

{
  int unaff_EBP;
  
  FUN_10013ae0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10023cb0 at 10023cb0

void Unwind_10023cb0(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10023cbb at 10023cbb

void Unwind_10023cbb(void)

{
  int unaff_EBP;
  
  FUN_10013a60((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@10023cc6 at 10023cc6

void Unwind_10023cc6(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10023cd1 at 10023cd1

void Unwind_10023cd1(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10023cdc at 10023cdc

void Unwind_10023cdc(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10023ce7 at 10023ce7

void Unwind_10023ce7(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@10023cf2 at 10023cf2

void Unwind_10023cf2(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10023cfd at 10023cfd

void Unwind_10023cfd(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10023d08 at 10023d08

void Unwind_10023d08(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@10023d13 at 10023d13

void Unwind_10023d13(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@10023d1e at 10023d1e

void Unwind_10023d1e(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>((int *)(*(int *)(unaff_EBP + -0x10) + 0x50));
  return;
}



// Function: Unwind@10023d29 at 10023d29

void Unwind_10023d29(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@10023d50 at 10023d50

void Unwind_10023d50(void)

{
  FUN_10002f80();
  return;
}



// Function: Unwind@10023d80 at 10023d80

void Unwind_10023d80(void)

{
  int unaff_EBP;
  
  FUN_10013b40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10023d88 at 10023d88

void Unwind_10023d88(void)

{
  int unaff_EBP;
  
  FUN_10013b20((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10023db0 at 10023db0

void Unwind_10023db0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023de0 at 10023de0

void Unwind_10023de0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10023e10 at 10023e10

void Unwind_10023e10(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023e40 at 10023e40

void Unwind_10023e40(void)

{
  int unaff_EBP;
  
  FUN_10021587(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10023e70 at 10023e70

void Unwind_10023e70(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10023e7b at 10023e7b

void Unwind_10023e7b(void)

{
  int unaff_EBP;
  
  FUN_10013a60((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@10023e86 at 10023e86

void Unwind_10023e86(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10023e91 at 10023e91

void Unwind_10023e91(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10023e9c at 10023e9c

void Unwind_10023e9c(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10023ea7 at 10023ea7

void Unwind_10023ea7(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@10023eb2 at 10023eb2

void Unwind_10023eb2(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10023ebd at 10023ebd

void Unwind_10023ebd(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10023ec8 at 10023ec8

void Unwind_10023ec8(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@10023ed3 at 10023ed3

void Unwind_10023ed3(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@10023ede at 10023ede

void Unwind_10023ede(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>((int *)(*(int *)(unaff_EBP + -0x10) + 0x50));
  return;
}



// Function: Unwind@10023ee9 at 10023ee9

void Unwind_10023ee9(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@10023f0f at 10023f0f

void Unwind_10023f0f(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023f17 at 10023f17

void Unwind_10023f17(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023f1f at 10023f1f

void Unwind_10023f1f(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023f27 at 10023f27

void Unwind_10023f27(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@10023f2f at 10023f2f

void Unwind_10023f2f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10023f37 at 10023f37

void Unwind_10023f37(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10023f3f at 10023f3f

void Unwind_10023f3f(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10023f6c at 10023f6c

void Unwind_10023f6c(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10023f74 at 10023f74

void Unwind_10023f74(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10023f7c at 10023f7c

void Unwind_10023f7c(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10023f84 at 10023f84

void Unwind_10023f84(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@10023f8c at 10023f8c

void Unwind_10023f8c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10023f94 at 10023f94

void Unwind_10023f94(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10023f9c at 10023f9c

void Unwind_10023f9c(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10023fc9 at 10023fc9

void Unwind_10023fc9(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10023fd1 at 10023fd1

void Unwind_10023fd1(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10023fd9 at 10023fd9

void Unwind_10023fd9(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10023ffc at 10023ffc

void Unwind_10023ffc(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10024004 at 10024004

void Unwind_10024004(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002400c at 1002400c

void Unwind_1002400c(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1002402f at 1002402f

void Unwind_1002402f(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024037 at 10024037

void Unwind_10024037(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002403f at 1002403f

void Unwind_1002403f(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10024062 at 10024062

void Unwind_10024062(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1002406a at 1002406a

void Unwind_1002406a(void)

{
  int unaff_EBP;
  
  FUN_10018fd0((_Container_base0 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10024075 at 10024075

void Unwind_10024075(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002407d at 1002407d

void Unwind_1002407d(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0xe0);
  return;
}



// Function: Unwind@10024088 at 10024088

void Unwind_10024088(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10024090 at 10024090

void Unwind_10024090(void)

{
  int unaff_EBP;
  
  FUN_10013a40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024098 at 10024098

void Unwind_10024098(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100240a0 at 100240a0

void Unwind_100240a0(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100240a8 at 100240a8

void Unwind_100240a8(void)

{
  int unaff_EBP;
  
  FUN_10013aa0((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100240b0 at 100240b0

void Unwind_100240b0(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@100240bb at 100240bb

void Unwind_100240bb(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@100240c6 at 100240c6

void Unwind_100240c6(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@100240ef at 100240ef

void Unwind_100240ef(void)

{
  int unaff_EBP;
  
  FUN_10013a60((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100240f7 at 100240f7

void Unwind_100240f7(void)

{
  int unaff_EBP;
  
  FUN_10013a80((int *)(unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@10024102 at 10024102

void Unwind_10024102(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x1cc));
  return;
}



// Function: Unwind@1002410d at 1002410d

void Unwind_1002410d(void)

{
  int unaff_EBP;
  
  FUN_10013a40((int *)(unaff_EBP + -0x128));
  return;
}



// Function: Unwind@10024118 at 10024118

void Unwind_10024118(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -0x120));
  return;
}



// Function: Unwind@10024123 at 10024123

void Unwind_10024123(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@1002412e at 1002412e

void Unwind_1002412e(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@10024139 at 10024139

void Unwind_10024139(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1e0));
  return;
}



// Function: Unwind@1002416c at 1002416c

void Unwind_1002416c(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -100);
  return;
}



// Function: Unwind@10024174 at 10024174

void Unwind_10024174(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002417c at 1002417c

void Unwind_1002417c(void)

{
  int unaff_EBP;
  
  FUN_1001d3a0((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10024187 at 10024187

void Unwind_10024187(void)

{
  int unaff_EBP;
  
  FUN_10013a00((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100241ad at 100241ad

void Unwind_100241ad(void)

{
  int unaff_EBP;
  
  FUN_10013a20((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100241b5 at 100241b5

void Unwind_100241b5(void)

{
  int unaff_EBP;
  
  FUN_1001d3a0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@100241c0 at 100241c0

void Unwind_100241c0(void)

{
  int unaff_EBP;
  
  FUN_10013df0(unaff_EBP + -0x70);
  return;
}



// Function: Unwind@100241c8 at 100241c8

void Unwind_100241c8(void)

{
  int unaff_EBP;
  
  FUN_10013a00((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100241d0 at 100241d0

void Unwind_100241d0(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100241f6 at 100241f6

void Unwind_100241f6(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100241fe at 100241fe

void Unwind_100241fe(void)

{
  int unaff_EBP;
  
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10024206 at 10024206

void Unwind_10024206(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x5c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x5c) = *(uint *)(unaff_EBP + -0x5c) & 0xfffffffe;
    FUN_100032d0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10024250 at 10024250

void Unwind_10024250(void)

{
  int unaff_EBP;
  
  FUN_10013a80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10024280 at 10024280

void Unwind_10024280(void)

{
  int unaff_EBP;
  
  FUN_10013b80(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100242b0 at 100242b0

void Unwind_100242b0(void)

{
  int unaff_EBP;
  
  FUN_10013b80((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024300 at 10024300

void Unwind_10024300(void)

{
  FUN_10003390();
  return;
}



// Function: Unwind@10024330 at 10024330

void Unwind_10024330(void)

{
  FUN_10003390();
  return;
}



// Function: Unwind@10024360 at 10024360

void Unwind_10024360(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100243b0 at 100243b0

void Unwind_100243b0(void)

{
  int unaff_EBP;
  
  FUN_10013b40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100243b8 at 100243b8

void Unwind_100243b8(void)

{
  int unaff_EBP;
  
  FUN_10013b20((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100243de at 100243de

void Unwind_100243de(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100243e6 at 100243e6

void Unwind_100243e6(void)

{
  int unaff_EBP;
  
  FUN_1001a700((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100243ee at 100243ee

void Unwind_100243ee(void)

{
  int unaff_EBP;
  
  FUN_1001a6c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100243f6 at 100243f6

void Unwind_100243f6(void)

{
  int unaff_EBP;
  
  FUN_1001a700((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100243fe at 100243fe

void Unwind_100243fe(void)

{
  int unaff_EBP;
  
  FUN_1001a6e0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024421 at 10024421

void Unwind_10024421(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10024429 at 10024429

void Unwind_10024429(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10024431 at 10024431

void Unwind_10024431(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10024439 at 10024439

void Unwind_10024439(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10024441 at 10024441

void Unwind_10024441(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10024449 at 10024449

void Unwind_10024449(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10024451 at 10024451

void Unwind_10024451(void)

{
  int unaff_EBP;
  
  FUN_1001a6a0((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10024459 at 10024459

void Unwind_10024459(void)

{
  int unaff_EBP;
  
  FUN_1001a6c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024461 at 10024461

void Unwind_10024461(void)

{
  int unaff_EBP;
  
  FUN_1001a6e0((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024490 at 10024490

void Unwind_10024490(void)

{
  int unaff_EBP;
  
  FUN_1001a6a0(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100244c0 at 100244c0

void Unwind_100244c0(void)

{
  int unaff_EBP;
  
  FUN_1001a6c0(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100244f0 at 100244f0

void Unwind_100244f0(void)

{
  int unaff_EBP;
  
  FUN_10013b40(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10024520 at 10024520

void Unwind_10024520(void)

{
  int unaff_EBP;
  
  FUN_1001a700(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10024550 at 10024550

void Unwind_10024550(void)

{
  int unaff_EBP;
  
  FUN_1001a6a0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024580 at 10024580

void Unwind_10024580(void)

{
  int unaff_EBP;
  
  FUN_1001a6c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100245b0 at 100245b0

void Unwind_100245b0(void)

{
  int unaff_EBP;
  
  FUN_10013b40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100245e0 at 100245e0

void Unwind_100245e0(void)

{
  int unaff_EBP;
  
  FUN_1001a700((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024610 at 10024610

void Unwind_10024610(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 0x28));
  return;
}



// Function: Unwind@10024618 at 10024618

void Unwind_10024618(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@10024620 at 10024620

void Unwind_10024620(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 0x1c));
  return;
}



// Function: Unwind@10024628 at 10024628

void Unwind_10024628(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_1001a6a0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10024660 at 10024660

void Unwind_10024660(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_1001a700(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100246a0 at 100246a0

void Unwind_100246a0(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100246a8 at 100246a8

void Unwind_100246a8(void)

{
  int unaff_EBP;
  
  FUN_10013ba0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100246b0 at 100246b0

void Unwind_100246b0(void)

{
  int unaff_EBP;
  
  FUN_10013ae0((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100246b8 at 100246b8

void Unwind_100246b8(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100246c0 at 100246c0

void Unwind_100246c0(void)

{
  int unaff_EBP;
  
  FUN_1001bc20((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100246c8 at 100246c8

void Unwind_100246c8(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@100246d3 at 100246d3

void Unwind_100246d3(void)

{
  int unaff_EBP;
  
  FUN_1001bc80((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100246db at 100246db

void Unwind_100246db(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@100246e6 at 100246e6

void Unwind_100246e6(void)

{
  int unaff_EBP;
  
  FUN_1001bc80((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@100246ee at 100246ee

void Unwind_100246ee(void)

{
  int unaff_EBP;
  
  FUN_1001bc60((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100246f6 at 100246f6

void Unwind_100246f6(void)

{
  int unaff_EBP;
  
  FUN_1001bc40((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10024701 at 10024701

void Unwind_10024701(void)

{
  int unaff_EBP;
  
  FUN_1001bc60((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10024709 at 10024709

void Unwind_10024709(void)

{
  int unaff_EBP;
  
  FUN_1001bc60((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10024711 at 10024711

void Unwind_10024711(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10024719 at 10024719

void Unwind_10024719(void)

{
  int unaff_EBP;
  
  FUN_1001bc60((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10024721 at 10024721

void Unwind_10024721(void)

{
  int unaff_EBP;
  
  FUN_1001bc60((int *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10024729 at 10024729

void Unwind_10024729(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002474f at 1002474f

void Unwind_1002474f(void)

{
  int unaff_EBP;
  
  FUN_10013b00((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10024757 at 10024757

void Unwind_10024757(void)

{
  int unaff_EBP;
  
  FUN_10013ba0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002475f at 1002475f

void Unwind_1002475f(void)

{
  int unaff_EBP;
  
  FUN_10013ae0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10024767 at 10024767

void Unwind_10024767(void)

{
  int unaff_EBP;
  
  FUN_10002f00((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002476f at 1002476f

void Unwind_1002476f(void)

{
  int unaff_EBP;
  
  FUN_1001bc20((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024777 at 10024777

void Unwind_10024777(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1002477f at 1002477f

void Unwind_1002477f(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10024787 at 10024787

void Unwind_10024787(void)

{
  int unaff_EBP;
  
  FUN_1001bc60((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100247b0 at 100247b0

void Unwind_100247b0(void)

{
  int unaff_EBP;
  
  FUN_10013ba0(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100247e0 at 100247e0

void Unwind_100247e0(void)

{
  int unaff_EBP;
  
  FUN_1001bc40(*(int **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10024810 at 10024810

void Unwind_10024810(void)

{
  int unaff_EBP;
  
  FUN_10013ba0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024840 at 10024840

void Unwind_10024840(void)

{
  int unaff_EBP;
  
  FUN_1001bc40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024870 at 10024870

void Unwind_10024870(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_1001bc40(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100248b0 at 100248b0

void Unwind_100248b0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_1001bc60(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100248f0 at 100248f0

void Unwind_100248f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_1001bc60(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10024930 at 10024930

void Unwind_10024930(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_100032d0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10024970 at 10024970

void Unwind_10024970(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_100032d0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100249b0 at 100249b0

void Unwind_100249b0(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100249b8 at 100249b8

void Unwind_100249b8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_1001bc80(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100249f0 at 100249f0

void Unwind_100249f0(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024a20 at 10024a20

void Unwind_10024a20(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10024a28 at 10024a28

void Unwind_10024a28(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) & 0xfffffffe;
    FUN_1001bc60(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10024a60 at 10024a60

void Unwind_10024a60(void)

{
  FUN_100032f0((undefined4 *)&DAT_10035404);
  return;
}



// Function: Unwind@10024a90 at 10024a90

void Unwind_10024a90(void)

{
  FUN_100032f0((undefined4 *)&DAT_10035408);
  return;
}



// Function: Unwind@10024a9a at 10024a9a

void Unwind_10024a9a(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035408);
  return;
}



// Function: Unwind@10024ac0 at 10024ac0

void Unwind_10024ac0(void)

{
  FUN_100032f0((undefined4 *)&DAT_1003540c);
  return;
}



// Function: Unwind@10024aca at 10024aca

void Unwind_10024aca(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_1003540c);
  return;
}



// Function: Unwind@10024af0 at 10024af0

void Unwind_10024af0(void)

{
  FUN_100032f0((undefined4 *)&DAT_10035404);
  return;
}



// Function: Unwind@10024b20 at 10024b20

void Unwind_10024b20(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035408);
  return;
}



// Function: Unwind@10024b2a at 10024b2a

void Unwind_10024b2a(void)

{
  FUN_100032f0((undefined4 *)&DAT_10035408);
  return;
}



// Function: Unwind@10024b50 at 10024b50

void Unwind_10024b50(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_1003540c);
  return;
}



// Function: Unwind@10024b5a at 10024b5a

void Unwind_10024b5a(void)

{
  FUN_100032f0((undefined4 *)&DAT_1003540c);
  return;
}



// Function: Unwind@10024ba0 at 10024ba0

void Unwind_10024ba0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10024c30 at 10024c30

void Unwind_10024c30(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffe;
    FUN_100032d0(*(int **)(unaff_EBP + -0x3c));
    return;
  }
  return;
}



// Function: Unwind@10024c70 at 10024c70

void Unwind_10024c70(void)

{
  int unaff_EBP;
  
  FUN_10013df0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10024ca0 at 10024ca0

void Unwind_10024ca0(void)

{
  int unaff_EBP;
  
  FUN_10013df0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10024cd0 at 10024cd0

void Unwind_10024cd0(void)

{
  int unaff_EBP;
  
  FUN_10013df0(*(int *)(unaff_EBP + -0x14) + 8);
  return;
}



// Function: Unwind@10024d00 at 10024d00

void Unwind_10024d00(void)

{
  int unaff_EBP;
  
  FUN_10013df0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10024d30 at 10024d30

void Unwind_10024d30(void)

{
  int unaff_EBP;
  
  FUN_10013df0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10024d60 at 10024d60

void Unwind_10024d60(void)

{
  int unaff_EBP;
  
  FUN_1001e140(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024d90 at 10024d90

void Unwind_10024d90(void)

{
  int unaff_EBP;
  
  FUN_1001e140(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024dc0 at 10024dc0

void Unwind_10024dc0(void)

{
  int unaff_EBP;
  
  FUN_1001e150(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024df0 at 10024df0

void Unwind_10024df0(void)

{
  int unaff_EBP;
  
  FUN_1001e140((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024e20 at 10024e20

void Unwind_10024e20(void)

{
  int unaff_EBP;
  
  FUN_1001e150((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10024e50 at 10024e50

void Unwind_10024e50(void)

{
  int unaff_EBP;
  
  FUN_1001e110(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024e80 at 10024e80

void Unwind_10024e80(void)

{
  int unaff_EBP;
  
  FUN_1001e120(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024eb0 at 10024eb0

void Unwind_10024eb0(void)

{
  int unaff_EBP;
  
  FUN_1001e110(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024ee0 at 10024ee0

void Unwind_10024ee0(void)

{
  int unaff_EBP;
  
  FUN_1001e120(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10024f10 at 10024f10

void Unwind_10024f10(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10024f40 at 10024f40

void Unwind_10024f40(void)

{
  int unaff_EBP;
  
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>::
  ~CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator>
            ((CAtlSafeAllocBufferManager<class_ATL::CCRTAllocator> *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@10024f4b at 10024f4b

void Unwind_10024f4b(void)

{
  int unaff_EBP;
  
  FUN_1001e110((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10024f56 at 10024f56

void Unwind_10024f56(void)

{
  int unaff_EBP;
  
  FUN_1001e070((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10024f61 at 10024f61

void Unwind_10024f61(void)

{
  int unaff_EBP;
  
  FUN_1001e120((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10024f6c at 10024f6c

void Unwind_10024f6c(void)

{
  int unaff_EBP;
  
  FUN_1001e0c0((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10024f77 at 10024f77

void Unwind_10024f77(void)

{
  int unaff_EBP;
  
  FUN_1001e120((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10024f82 at 10024f82

void Unwind_10024f82(void)

{
  int unaff_EBP;
  
  FUN_1001e110((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10024fc0 at 10024fc0

void Unwind_10024fc0(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@10024fcb at 10024fcb

void Unwind_10024fcb(void)

{
  int unaff_EBP;
  
  FUN_1001e130((int *)(unaff_EBP + -0x2038));
  return;
}



// Function: Unwind@10024fd6 at 10024fd6

void Unwind_10024fd6(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10024fe1 at 10024fe1

void Unwind_10024fe1(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10024fec at 10024fec

void Unwind_10024fec(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10024ff7 at 10024ff7

void Unwind_10024ff7(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@10025002 at 10025002

void Unwind_10025002(void)

{
  int unaff_EBP;
  
  FUN_1001e150((int *)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@1002500d at 1002500d

void Unwind_1002500d(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10025018 at 10025018

void Unwind_10025018(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10025023 at 10025023

void Unwind_10025023(void)

{
  int unaff_EBP;
  
  FUN_1001e140((int *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@1002502e at 1002502e

void Unwind_1002502e(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10025039 at 10025039

void Unwind_10025039(void)

{
  int unaff_EBP;
  
  FUN_1001e150((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10025044 at 10025044

void Unwind_10025044(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x2044));
  return;
}



// Function: Unwind@10025080 at 10025080

void Unwind_10025080(void)

{
  int unaff_EBP;
  
  FUN_1001e140((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10025088 at 10025088

void Unwind_10025088(void)

{
  int unaff_EBP;
  
  FUN_1001e150((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10025090 at 10025090

void Unwind_10025090(void)

{
  int unaff_EBP;
  
  FUN_1001e130((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10025098 at 10025098

void Unwind_10025098(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100250a3 at 100250a3

void Unwind_100250a3(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100250ab at 100250ab

void Unwind_100250ab(void)

{
  int unaff_EBP;
  
  FUN_1001e140(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100250b3 at 100250b3

void Unwind_100250b3(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100250bb at 100250bb

void Unwind_100250bb(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100250c3 at 100250c3

void Unwind_100250c3(void)

{
  int unaff_EBP;
  
  FUN_100032d0(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100250cb at 100250cb

void Unwind_100250cb(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100250f0 at 100250f0

void Unwind_100250f0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100250fb at 100250fb

void Unwind_100250fb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_100032d0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10025130 at 10025130

void Unwind_10025130(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002513b at 1002513b

void Unwind_1002513b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_100032d0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10025170 at 10025170

void Unwind_10025170(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100251a0 at 100251a0

void Unwind_100251a0(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100251d0 at 100251d0

void Unwind_100251d0(void)

{
  int unaff_EBP;
  
  FUN_100032d0((int *)(unaff_EBP + 8));
  return;
}



// Function: FUN_10025240 at 10025240

void FUN_10025240(void)

{
  FUN_10002530((undefined4 *)&DAT_10035404);
  _atexit(FUN_100278c0);
  return;
}



// Function: FUN_10025260 at 10025260

void FUN_10025260(void)

{
  FUN_10002590((undefined4 *)&DAT_10035408);
  _atexit(FUN_100278d0);
  return;
}



// Function: FUN_10025280 at 10025280

void FUN_10025280(void)

{
  FUN_100025f0((undefined4 *)&DAT_1003540c);
  _atexit(FUN_100278e0);
  return;
}



// Function: FUN_100252a0 at 100252a0

void FUN_100252a0(void)

{
  std::locale::id::id((id *)&DAT_10035410,0);
  return;
}



// Function: FUN_100252c0 at 100252c0

void FUN_100252c0(void)

{
  std::locale::id::id((id *)&DAT_10035414,0);
  return;
}



// Function: FUN_100252e0 at 100252e0

void FUN_100252e0(void)

{
  FUN_10002650(&DAT_10035388,"DataStructures.Audit_Trail.CurrentRecordIndex");
  _atexit(FUN_100278f0);
  return;
}



// Function: FUN_10025310 at 10025310

void FUN_10025310(void)

{
  FUN_10002650(&DAT_100353f0,"DataStructures.Audit_Trail.RecordLength");
  _atexit(FUN_10027900);
  return;
}



// Function: FUN_10025340 at 10025340

void FUN_10025340(void)

{
  FUN_10002650(&DAT_10035360,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027910);
  return;
}



// Function: FUN_10025370 at 10025370

void FUN_10025370(void)

{
  FUN_10002650(&DAT_100353d8,"ConfigFile._Audit_Trail");
  _atexit(FUN_10027920);
  return;
}



// Function: FUN_100253a0 at 100253a0

void FUN_100253a0(void)

{
  FUN_10002650(&DAT_100353e4,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027930);
  return;
}



// Function: FUN_100253d0 at 100253d0

void FUN_100253d0(void)

{
  FUN_10002650(&DAT_100353e8,"ConfigFile._Audit_Trail[%d]");
  _atexit(FUN_10027940);
  return;
}



// Function: FUN_10025400 at 10025400

void FUN_10025400(void)

{
  FUN_10002650(&DAT_100353f8,"_audit_trail_codes");
  _atexit(FUN_10027950);
  return;
}



// Function: FUN_10025430 at 10025430

void FUN_10025430(void)

{
  FUN_10002650(&DAT_100353d0,"DataStructures.Audit_Trail.Records[%d]");
  _atexit(FUN_10027960);
  return;
}



// Function: FUN_10025460 at 10025460

void FUN_10025460(void)

{
  FUN_10002650(&DAT_1003538c,"_tool_id");
  _atexit(FUN_10027970);
  return;
}



// Function: FUN_10025490 at 10025490

void FUN_10025490(void)

{
  FUN_10002650(&DAT_10035380,"_tool_instance");
  _atexit(FUN_10027980);
  return;
}



// Function: FUN_100254c0 at 100254c0

void FUN_100254c0(void)

{
  FUN_10002650(&DAT_100353fc,"_ECM_Run_Time");
  _atexit(FUN_10027990);
  return;
}



// Function: FUN_100254f0 at 100254f0

void FUN_100254f0(void)

{
  FUN_10002650(&DAT_10035374,"_ECM_Real_Time");
  _atexit(FUN_100279a0);
  return;
}



// Function: FUN_10025520 at 10025520

void FUN_10025520(void)

{
  FUN_10002650(&DAT_100353d4,"_tool_version");
  _atexit(FUN_100279b0);
  return;
}



// Function: FUN_10025550 at 10025550

void FUN_10025550(void)

{
  FUN_10002650(&DAT_1003536c,"DataStructures.Audit_Trail");
  _atexit(FUN_100279c0);
  return;
}



// Function: FUN_10025580 at 10025580

void FUN_10025580(void)

{
  FUN_10002650(&DAT_100353c0,"DataStructures.Audit_Trail.TableLength");
  _atexit(FUN_100279d0);
  return;
}



// Function: FUN_100255b0 at 100255b0

void FUN_100255b0(void)

{
  FUN_10002650(&DAT_100353f4,"\"OFF\"");
  _atexit(FUN_100279e0);
  return;
}



// Function: FUN_100255e0 at 100255e0

void FUN_100255e0(void)

{
  FUN_10002650(&DAT_10035370,"\"ON\"");
  _atexit(FUN_100279f0);
  return;
}



// Function: FUN_10025610 at 10025610

void FUN_10025610(void)

{
  FUN_10002650(&DAT_100353dc,"CurrentRecordIndex");
  _atexit(FUN_10027a00);
  return;
}



// Function: FUN_10025640 at 10025640

void FUN_10025640(void)

{
  FUN_10002650(&DAT_1003537c,"DataStructures._audit_trail_code");
  _atexit(FUN_10027a10);
  return;
}



// Function: FUN_10025670 at 10025670

void FUN_10025670(void)

{
  FUN_10002650(&DAT_100353c4,"ConfigFile._audit_trail_code");
  _atexit(FUN_10027a20);
  return;
}



// Function: FUN_100256a0 at 100256a0

void FUN_100256a0(void)

{
  FUN_10002650(&DAT_10035378,"Records[%d]");
  _atexit(FUN_10027a30);
  return;
}



// Function: FUN_100256d0 at 100256d0

void FUN_100256d0(void)

{
  FUN_10002650(&DAT_10035368,"GTIS2");
  _atexit(FUN_10027a40);
  return;
}



// Function: FUN_10025700 at 10025700

void FUN_10025700(void)

{
  FUN_10002650(&DAT_100353e0,"GTIS38");
  _atexit(FUN_10027a50);
  return;
}



// Function: FUN_10025730 at 10025730

void FUN_10025730(void)

{
  FUN_10002650(&DAT_100353ec,"GTIS45");
  _atexit(FUN_10027a60);
  return;
}



// Function: FUN_10025760 at 10025760

void FUN_10025760(void)

{
  FUN_10002650(&DAT_10035400,"ConfigFile.RUN_TIME");
  _atexit(FUN_10027a70);
  return;
}



// Function: FUN_10025790 at 10025790

void FUN_10025790(void)

{
  FUN_10002650(&DAT_100353c8,"ConfigFile.ECM_Run_Time");
  _atexit(FUN_10027a80);
  return;
}



// Function: FUN_100257c0 at 100257c0

void FUN_100257c0(void)

{
  FUN_10002650(&DAT_1003535c,"ConfigFile._ECM_Run_Time");
  _atexit(FUN_10027a90);
  return;
}



// Function: FUN_100257f0 at 100257f0

void FUN_100257f0(void)

{
  FUN_10002650(&DAT_10035364,"ConfigFile.HOURS");
  _atexit(FUN_10027aa0);
  return;
}



// Function: FUN_10025820 at 10025820

void FUN_10025820(void)

{
  FUN_10002650(&DAT_100353cc,"ConfigFile.ECM_TIME");
  _atexit(FUN_10027ab0);
  return;
}



// Function: FUN_10025850 at 10025850

void FUN_10025850(void)

{
  FUN_100021b0((undefined4 *)&DAT_10035390);
  _atexit(FUN_10027ac0);
  return;
}



// Function: FUN_10025870 at 10025870

void FUN_10025870(void)

{
  return;
}



// Function: FUN_10025880 at 10025880

void FUN_10025880(void)

{
  return;
}



// Function: FUN_10025890 at 10025890

void FUN_10025890(void)

{
  FUN_10002530((undefined4 *)&DAT_10035404);
  _atexit(FUN_10027ad0);
  return;
}



// Function: FUN_100258b0 at 100258b0

void FUN_100258b0(void)

{
  FUN_10002590((undefined4 *)&DAT_10035408);
  _atexit(FUN_10027ae0);
  return;
}



// Function: FUN_100258d0 at 100258d0

void FUN_100258d0(void)

{
  FUN_100025f0((undefined4 *)&DAT_1003540c);
  _atexit(FUN_10027af0);
  return;
}



// Function: FUN_100258f0 at 100258f0

void FUN_100258f0(void)

{
  std::locale::id::id((id *)&DAT_10035410,0);
  return;
}



// Function: FUN_10025910 at 10025910

void FUN_10025910(void)

{
  std::locale::id::id((id *)&DAT_10035414,0);
  return;
}



// Function: FUN_10025930 at 10025930

void FUN_10025930(void)

{
  FUN_10002650(&DAT_10035444,"DataStructures.Audit_Trail.CurrentRecordIndex");
  _atexit(FUN_10027b00);
  return;
}



// Function: FUN_10025960 at 10025960

void FUN_10025960(void)

{
  FUN_10002650(&DAT_1003547c,"DataStructures.Audit_Trail.RecordLength");
  _atexit(FUN_10027b10);
  return;
}



// Function: FUN_10025990 at 10025990

void FUN_10025990(void)

{
  FUN_10002650(&DAT_1003541c,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027b20);
  return;
}



// Function: FUN_100259c0 at 100259c0

void FUN_100259c0(void)

{
  FUN_10002650(&DAT_10035464,"ConfigFile._Audit_Trail");
  _atexit(FUN_10027b30);
  return;
}



// Function: FUN_100259f0 at 100259f0

void FUN_100259f0(void)

{
  FUN_10002650(&DAT_10035470,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027b40);
  return;
}



// Function: FUN_10025a20 at 10025a20

void FUN_10025a20(void)

{
  FUN_10002650(&DAT_10035474,"ConfigFile._Audit_Trail[%d]");
  _atexit(FUN_10027b50);
  return;
}



// Function: FUN_10025a50 at 10025a50

void FUN_10025a50(void)

{
  FUN_10002650(&DAT_10035484,"_audit_trail_codes");
  _atexit(FUN_10027b60);
  return;
}



// Function: FUN_10025a80 at 10025a80

void FUN_10025a80(void)

{
  FUN_10002650(&DAT_1003545c,"DataStructures.Audit_Trail.Records[%d]");
  _atexit(FUN_10027b70);
  return;
}



// Function: FUN_10025ab0 at 10025ab0

void FUN_10025ab0(void)

{
  FUN_10002650(&DAT_10035448,"_tool_id");
  _atexit(FUN_10027b80);
  return;
}



// Function: FUN_10025ae0 at 10025ae0

void FUN_10025ae0(void)

{
  FUN_10002650(&DAT_1003543c,"_tool_instance");
  _atexit(FUN_10027b90);
  return;
}



// Function: FUN_10025b10 at 10025b10

void FUN_10025b10(void)

{
  FUN_10002650(&DAT_10035488,"_ECM_Run_Time");
  _atexit(FUN_10027ba0);
  return;
}



// Function: FUN_10025b40 at 10025b40

void FUN_10025b40(void)

{
  FUN_10002650(&DAT_10035430,"_ECM_Real_Time");
  _atexit(FUN_10027bb0);
  return;
}



// Function: FUN_10025b70 at 10025b70

void FUN_10025b70(void)

{
  FUN_10002650(&DAT_10035460,"_tool_version");
  _atexit(FUN_10027bc0);
  return;
}



// Function: FUN_10025ba0 at 10025ba0

void FUN_10025ba0(void)

{
  FUN_10002650(&DAT_10035428,"DataStructures.Audit_Trail");
  _atexit(FUN_10027bd0);
  return;
}



// Function: FUN_10025bd0 at 10025bd0

void FUN_10025bd0(void)

{
  FUN_10002650(&DAT_1003544c,"DataStructures.Audit_Trail.TableLength");
  _atexit(FUN_10027be0);
  return;
}



// Function: FUN_10025c00 at 10025c00

void FUN_10025c00(void)

{
  FUN_10002650(&DAT_10035480,"\"OFF\"");
  _atexit(FUN_10027bf0);
  return;
}



// Function: FUN_10025c30 at 10025c30

void FUN_10025c30(void)

{
  FUN_10002650(&DAT_1003542c,"\"ON\"");
  _atexit(FUN_10027c00);
  return;
}



// Function: FUN_10025c60 at 10025c60

void FUN_10025c60(void)

{
  FUN_10002650(&DAT_10035468,"CurrentRecordIndex");
  _atexit(FUN_10027c10);
  return;
}



// Function: FUN_10025c90 at 10025c90

void FUN_10025c90(void)

{
  FUN_10002650(&DAT_10035438,"DataStructures._audit_trail_code");
  _atexit(FUN_10027c20);
  return;
}



// Function: FUN_10025cc0 at 10025cc0

void FUN_10025cc0(void)

{
  FUN_10002650(&DAT_10035450,"ConfigFile._audit_trail_code");
  _atexit(FUN_10027c30);
  return;
}



// Function: FUN_10025cf0 at 10025cf0

void FUN_10025cf0(void)

{
  FUN_10002650(&DAT_10035434,"Records[%d]");
  _atexit(FUN_10027c40);
  return;
}



// Function: FUN_10025d20 at 10025d20

void FUN_10025d20(void)

{
  FUN_10002650(&DAT_10035424,"GTIS2");
  _atexit(FUN_10027c50);
  return;
}



// Function: FUN_10025d50 at 10025d50

void FUN_10025d50(void)

{
  FUN_10002650(&DAT_1003546c,"GTIS38");
  _atexit(FUN_10027c60);
  return;
}



// Function: FUN_10025d80 at 10025d80

void FUN_10025d80(void)

{
  FUN_10002650(&DAT_10035478,"GTIS45");
  _atexit(FUN_10027c70);
  return;
}



// Function: FUN_10025db0 at 10025db0

void FUN_10025db0(void)

{
  FUN_10002650(&DAT_1003548c,"ConfigFile.RUN_TIME");
  _atexit(FUN_10027c80);
  return;
}



// Function: FUN_10025de0 at 10025de0

void FUN_10025de0(void)

{
  FUN_10002650(&DAT_10035454,"ConfigFile.ECM_Run_Time");
  _atexit(FUN_10027c90);
  return;
}



// Function: FUN_10025e10 at 10025e10

void FUN_10025e10(void)

{
  FUN_10002650(&DAT_10035418,"ConfigFile._ECM_Run_Time");
  _atexit(FUN_10027ca0);
  return;
}



// Function: FUN_10025e40 at 10025e40

void FUN_10025e40(void)

{
  FUN_10002650(&DAT_10035420,"ConfigFile.HOURS");
  _atexit(FUN_10027cb0);
  return;
}



// Function: FUN_10025e70 at 10025e70

void FUN_10025e70(void)

{
  FUN_10002650(&DAT_10035458,"ConfigFile.ECM_TIME");
  _atexit(FUN_10027cc0);
  return;
}



// Function: FUN_10025ea0 at 10025ea0

void FUN_10025ea0(void)

{
  return;
}



// Function: FUN_10025eb0 at 10025eb0

void FUN_10025eb0(void)

{
  return;
}



// Function: FUN_10025ec0 at 10025ec0

void FUN_10025ec0(void)

{
  FUN_10002530((undefined4 *)&DAT_10035404);
  _atexit(FUN_10027cd0);
  return;
}



// Function: FUN_10025ee0 at 10025ee0

void FUN_10025ee0(void)

{
  FUN_10002590((undefined4 *)&DAT_10035408);
  _atexit(FUN_10027ce0);
  return;
}



// Function: FUN_10025f00 at 10025f00

void FUN_10025f00(void)

{
  FUN_100025f0((undefined4 *)&DAT_1003540c);
  _atexit(FUN_10027cf0);
  return;
}



// Function: FUN_10025f20 at 10025f20

void FUN_10025f20(void)

{
  std::locale::id::id((id *)&DAT_10035410,0);
  return;
}



// Function: FUN_10025f40 at 10025f40

void FUN_10025f40(void)

{
  std::locale::id::id((id *)&DAT_10035414,0);
  return;
}



// Function: FUN_10025f60 at 10025f60

void FUN_10025f60(void)

{
  FUN_10002650(&DAT_100354bc,"DataStructures.Audit_Trail.CurrentRecordIndex");
  _atexit(FUN_10027d00);
  return;
}



// Function: FUN_10025f90 at 10025f90

void FUN_10025f90(void)

{
  FUN_10002650(&DAT_100354f4,"DataStructures.Audit_Trail.RecordLength");
  _atexit(FUN_10027d10);
  return;
}



// Function: FUN_10025fc0 at 10025fc0

void FUN_10025fc0(void)

{
  FUN_10002650(&DAT_10035494,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027d20);
  return;
}



// Function: FUN_10025ff0 at 10025ff0

void FUN_10025ff0(void)

{
  FUN_10002650(&DAT_100354dc,"ConfigFile._Audit_Trail");
  _atexit(FUN_10027d30);
  return;
}



// Function: FUN_10026020 at 10026020

void FUN_10026020(void)

{
  FUN_10002650(&DAT_100354e8,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027d40);
  return;
}



// Function: FUN_10026050 at 10026050

void FUN_10026050(void)

{
  FUN_10002650(&DAT_100354ec,"ConfigFile._Audit_Trail[%d]");
  _atexit(FUN_10027d50);
  return;
}



// Function: FUN_10026080 at 10026080

void FUN_10026080(void)

{
  FUN_10002650(&DAT_100354fc,"_audit_trail_codes");
  _atexit(FUN_10027d60);
  return;
}



// Function: FUN_100260b0 at 100260b0

void FUN_100260b0(void)

{
  FUN_10002650(&DAT_100354d4,"DataStructures.Audit_Trail.Records[%d]");
  _atexit(FUN_10027d70);
  return;
}



// Function: FUN_100260e0 at 100260e0

void FUN_100260e0(void)

{
  FUN_10002650(&DAT_100354c0,"_tool_id");
  _atexit(FUN_10027d80);
  return;
}



// Function: FUN_10026110 at 10026110

void FUN_10026110(void)

{
  FUN_10002650(&DAT_100354b4,"_tool_instance");
  _atexit(FUN_10027d90);
  return;
}



// Function: FUN_10026140 at 10026140

void FUN_10026140(void)

{
  FUN_10002650(&DAT_10035500,"_ECM_Run_Time");
  _atexit(FUN_10027da0);
  return;
}



// Function: FUN_10026170 at 10026170

void FUN_10026170(void)

{
  FUN_10002650(&DAT_100354a8,"_ECM_Real_Time");
  _atexit(FUN_10027db0);
  return;
}



// Function: FUN_100261a0 at 100261a0

void FUN_100261a0(void)

{
  FUN_10002650(&DAT_100354d8,"_tool_version");
  _atexit(FUN_10027dc0);
  return;
}



// Function: FUN_100261d0 at 100261d0

void FUN_100261d0(void)

{
  FUN_10002650(&DAT_100354a0,"DataStructures.Audit_Trail");
  _atexit(FUN_10027dd0);
  return;
}



// Function: FUN_10026200 at 10026200

void FUN_10026200(void)

{
  FUN_10002650(&DAT_100354c4,"DataStructures.Audit_Trail.TableLength");
  _atexit(FUN_10027de0);
  return;
}



// Function: FUN_10026230 at 10026230

void FUN_10026230(void)

{
  FUN_10002650(&DAT_100354f8,"\"OFF\"");
  _atexit(FUN_10027df0);
  return;
}



// Function: FUN_10026260 at 10026260

void FUN_10026260(void)

{
  FUN_10002650(&DAT_100354a4,"\"ON\"");
  _atexit(FUN_10027e00);
  return;
}



// Function: FUN_10026290 at 10026290

void FUN_10026290(void)

{
  FUN_10002650(&DAT_100354e0,"CurrentRecordIndex");
  _atexit(FUN_10027e10);
  return;
}



// Function: FUN_100262c0 at 100262c0

void FUN_100262c0(void)

{
  FUN_10002650(&DAT_100354b0,"DataStructures._audit_trail_code");
  _atexit(FUN_10027e20);
  return;
}



// Function: FUN_100262f0 at 100262f0

void FUN_100262f0(void)

{
  FUN_10002650(&DAT_100354c8,"ConfigFile._audit_trail_code");
  _atexit(FUN_10027e30);
  return;
}



// Function: FUN_10026320 at 10026320

void FUN_10026320(void)

{
  FUN_10002650(&DAT_100354ac,"Records[%d]");
  _atexit(FUN_10027e40);
  return;
}



// Function: FUN_10026350 at 10026350

void FUN_10026350(void)

{
  FUN_10002650(&DAT_1003549c,"GTIS2");
  _atexit(FUN_10027e50);
  return;
}



// Function: FUN_10026380 at 10026380

void FUN_10026380(void)

{
  FUN_10002650(&DAT_100354e4,"GTIS38");
  _atexit(FUN_10027e60);
  return;
}



// Function: FUN_100263b0 at 100263b0

void FUN_100263b0(void)

{
  FUN_10002650(&DAT_100354f0,"GTIS45");
  _atexit(FUN_10027e70);
  return;
}



// Function: FUN_100263e0 at 100263e0

void FUN_100263e0(void)

{
  FUN_10002650(&DAT_10035504,"ConfigFile.RUN_TIME");
  _atexit(FUN_10027e80);
  return;
}



// Function: FUN_10026410 at 10026410

void FUN_10026410(void)

{
  FUN_10002650(&DAT_100354cc,"ConfigFile.ECM_Run_Time");
  _atexit(FUN_10027e90);
  return;
}



// Function: FUN_10026440 at 10026440

void FUN_10026440(void)

{
  FUN_10002650(&DAT_10035490,"ConfigFile._ECM_Run_Time");
  _atexit(FUN_10027ea0);
  return;
}



// Function: FUN_10026470 at 10026470

void FUN_10026470(void)

{
  FUN_10002650(&DAT_10035498,"ConfigFile.HOURS");
  _atexit(FUN_10027eb0);
  return;
}



// Function: FUN_100264a0 at 100264a0

void FUN_100264a0(void)

{
  FUN_10002650(&DAT_100354d0,"ConfigFile.ECM_TIME");
  _atexit(FUN_10027ec0);
  return;
}



// Function: FUN_100264d0 at 100264d0

void FUN_100264d0(void)

{
  return;
}



// Function: FUN_100264e0 at 100264e0

void FUN_100264e0(void)

{
  return;
}



// Function: FUN_100264f0 at 100264f0

void FUN_100264f0(void)

{
  FUN_10002530((undefined4 *)&DAT_10035404);
  _atexit(FUN_10027ed0);
  return;
}



// Function: FUN_10026510 at 10026510

void FUN_10026510(void)

{
  FUN_10002590((undefined4 *)&DAT_10035408);
  _atexit(FUN_10027ee0);
  return;
}



// Function: FUN_10026530 at 10026530

void FUN_10026530(void)

{
  FUN_100025f0((undefined4 *)&DAT_1003540c);
  _atexit(FUN_10027ef0);
  return;
}



// Function: FUN_10026550 at 10026550

void FUN_10026550(void)

{
  std::locale::id::id((id *)&DAT_10035410,0);
  return;
}



// Function: FUN_10026570 at 10026570

void FUN_10026570(void)

{
  std::locale::id::id((id *)&DAT_10035414,0);
  return;
}



// Function: FUN_10026590 at 10026590

void FUN_10026590(void)

{
  FUN_10002650(&DAT_10035534,"DataStructures.Audit_Trail.CurrentRecordIndex");
  _atexit(FUN_10027f00);
  return;
}



// Function: FUN_100265c0 at 100265c0

void FUN_100265c0(void)

{
  FUN_10002650(&DAT_1003556c,"DataStructures.Audit_Trail.RecordLength");
  _atexit(FUN_10027f10);
  return;
}



// Function: FUN_100265f0 at 100265f0

void FUN_100265f0(void)

{
  FUN_10002650(&DAT_1003550c,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027f20);
  return;
}



// Function: FUN_10026620 at 10026620

void FUN_10026620(void)

{
  FUN_10002650(&DAT_10035554,"ConfigFile._Audit_Trail");
  _atexit(FUN_10027f30);
  return;
}



// Function: FUN_10026650 at 10026650

void FUN_10026650(void)

{
  FUN_10002650(&DAT_10035560,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10027f40);
  return;
}



// Function: FUN_10026680 at 10026680

void FUN_10026680(void)

{
  FUN_10002650(&DAT_10035564,"ConfigFile._Audit_Trail[%d]");
  _atexit(FUN_10027f50);
  return;
}



// Function: FUN_100266b0 at 100266b0

void FUN_100266b0(void)

{
  FUN_10002650(&DAT_10035574,"_audit_trail_codes");
  _atexit(FUN_10027f60);
  return;
}



// Function: FUN_100266e0 at 100266e0

void FUN_100266e0(void)

{
  FUN_10002650(&DAT_1003554c,"DataStructures.Audit_Trail.Records[%d]");
  _atexit(FUN_10027f70);
  return;
}



// Function: FUN_10026710 at 10026710

void FUN_10026710(void)

{
  FUN_10002650(&DAT_10035538,"_tool_id");
  _atexit(FUN_10027f80);
  return;
}



// Function: FUN_10026740 at 10026740

void FUN_10026740(void)

{
  FUN_10002650(&DAT_1003552c,"_tool_instance");
  _atexit(FUN_10027f90);
  return;
}



// Function: FUN_10026770 at 10026770

void FUN_10026770(void)

{
  FUN_10002650(&DAT_10035578,"_ECM_Run_Time");
  _atexit(FUN_10027fa0);
  return;
}



// Function: FUN_100267a0 at 100267a0

void FUN_100267a0(void)

{
  FUN_10002650(&DAT_10035520,"_ECM_Real_Time");
  _atexit(FUN_10027fb0);
  return;
}



// Function: FUN_100267d0 at 100267d0

void FUN_100267d0(void)

{
  FUN_10002650(&DAT_10035550,"_tool_version");
  _atexit(FUN_10027fc0);
  return;
}



// Function: FUN_10026800 at 10026800

void FUN_10026800(void)

{
  FUN_10002650(&DAT_10035518,"DataStructures.Audit_Trail");
  _atexit(FUN_10027fd0);
  return;
}



// Function: FUN_10026830 at 10026830

void FUN_10026830(void)

{
  FUN_10002650(&DAT_1003553c,"DataStructures.Audit_Trail.TableLength");
  _atexit(FUN_10027fe0);
  return;
}



// Function: FUN_10026860 at 10026860

void FUN_10026860(void)

{
  FUN_10002650(&DAT_10035570,"\"OFF\"");
  _atexit(FUN_10027ff0);
  return;
}



// Function: FUN_10026890 at 10026890

void FUN_10026890(void)

{
  FUN_10002650(&DAT_1003551c,"\"ON\"");
  _atexit(FUN_10028000);
  return;
}



// Function: FUN_100268c0 at 100268c0

void FUN_100268c0(void)

{
  FUN_10002650(&DAT_10035558,"CurrentRecordIndex");
  _atexit(FUN_10028010);
  return;
}



// Function: FUN_100268f0 at 100268f0

void FUN_100268f0(void)

{
  FUN_10002650(&DAT_10035528,"DataStructures._audit_trail_code");
  _atexit(FUN_10028020);
  return;
}



// Function: FUN_10026920 at 10026920

void FUN_10026920(void)

{
  FUN_10002650(&DAT_10035540,"ConfigFile._audit_trail_code");
  _atexit(FUN_10028030);
  return;
}



// Function: FUN_10026950 at 10026950

void FUN_10026950(void)

{
  FUN_10002650(&DAT_10035524,"Records[%d]");
  _atexit(FUN_10028040);
  return;
}



// Function: FUN_10026980 at 10026980

void FUN_10026980(void)

{
  FUN_10002650(&DAT_10035514,"GTIS2");
  _atexit(FUN_10028050);
  return;
}



// Function: FUN_100269b0 at 100269b0

void FUN_100269b0(void)

{
  FUN_10002650(&DAT_1003555c,"GTIS38");
  _atexit(FUN_10028060);
  return;
}



// Function: FUN_100269e0 at 100269e0

void FUN_100269e0(void)

{
  FUN_10002650(&DAT_10035568,"GTIS45");
  _atexit(FUN_10028070);
  return;
}



// Function: FUN_10026a10 at 10026a10

void FUN_10026a10(void)

{
  FUN_10002650(&DAT_1003557c,"ConfigFile.RUN_TIME");
  _atexit(FUN_10028080);
  return;
}



// Function: FUN_10026a40 at 10026a40

void FUN_10026a40(void)

{
  FUN_10002650(&DAT_10035544,"ConfigFile.ECM_Run_Time");
  _atexit(FUN_10028090);
  return;
}



// Function: FUN_10026a70 at 10026a70

void FUN_10026a70(void)

{
  FUN_10002650(&DAT_10035508,"ConfigFile._ECM_Run_Time");
  _atexit(FUN_100280a0);
  return;
}



// Function: FUN_10026aa0 at 10026aa0

void FUN_10026aa0(void)

{
  FUN_10002650(&DAT_10035510,"ConfigFile.HOURS");
  _atexit(FUN_100280b0);
  return;
}



// Function: FUN_10026ad0 at 10026ad0

void FUN_10026ad0(void)

{
  FUN_10002650(&DAT_10035548,"ConfigFile.ECM_TIME");
  _atexit(FUN_100280c0);
  return;
}



// Function: FUN_10026b00 at 10026b00

void FUN_10026b00(void)

{
  return;
}



// Function: FUN_10026b10 at 10026b10

void FUN_10026b10(void)

{
  return;
}



// Function: FUN_10026b20 at 10026b20

void FUN_10026b20(void)

{
  FUN_10002650(&DAT_100355a8,"DataStructures.Audit_Trail.CurrentRecordIndex");
  _atexit(FUN_100280d0);
  return;
}



// Function: FUN_10026b50 at 10026b50

void FUN_10026b50(void)

{
  FUN_10002650(&DAT_100355e0,"DataStructures.Audit_Trail.RecordLength");
  _atexit(FUN_100280e0);
  return;
}



// Function: FUN_10026b80 at 10026b80

void FUN_10026b80(void)

{
  FUN_10002650(&DAT_10035584,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_100280f0);
  return;
}



// Function: FUN_10026bb0 at 10026bb0

void FUN_10026bb0(void)

{
  FUN_10002650(&DAT_100355c8,"ConfigFile._Audit_Trail");
  _atexit(FUN_10028100);
  return;
}



// Function: FUN_10026be0 at 10026be0

void FUN_10026be0(void)

{
  FUN_10002650(&DAT_100355d4,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_10028110);
  return;
}



// Function: FUN_10026c10 at 10026c10

void FUN_10026c10(void)

{
  FUN_10002650(&DAT_100355d8,"ConfigFile._Audit_Trail[%d]");
  _atexit(FUN_10028120);
  return;
}



// Function: FUN_10026c40 at 10026c40

void FUN_10026c40(void)

{
  FUN_10002650(&DAT_100355e8,"_audit_trail_codes");
  _atexit(FUN_10028130);
  return;
}



// Function: FUN_10026c70 at 10026c70

void FUN_10026c70(void)

{
  FUN_10002650(&DAT_100355c0,"DataStructures.Audit_Trail.Records[%d]");
  _atexit(FUN_10028140);
  return;
}



// Function: FUN_10026ca0 at 10026ca0

void FUN_10026ca0(void)

{
  FUN_10002650(&DAT_100355ac,"_tool_id");
  _atexit(FUN_10028150);
  return;
}



// Function: FUN_10026cd0 at 10026cd0

void FUN_10026cd0(void)

{
  FUN_10002650(&DAT_100355a4,"_tool_instance");
  _atexit(FUN_10028160);
  return;
}



// Function: FUN_10026d00 at 10026d00

void FUN_10026d00(void)

{
  FUN_10002650(&DAT_100355ec,"_ECM_Run_Time");
  _atexit(FUN_10028170);
  return;
}



// Function: FUN_10026d30 at 10026d30

void FUN_10026d30(void)

{
  FUN_10002650(&DAT_10035598,"_ECM_Real_Time");
  _atexit(FUN_10028180);
  return;
}



// Function: FUN_10026d60 at 10026d60

void FUN_10026d60(void)

{
  FUN_10002650(&DAT_100355c4,"_tool_version");
  _atexit(FUN_10028190);
  return;
}



// Function: FUN_10026d90 at 10026d90

void FUN_10026d90(void)

{
  FUN_10002650(&DAT_10035590,"DataStructures.Audit_Trail");
  _atexit(FUN_100281a0);
  return;
}



// Function: FUN_10026dc0 at 10026dc0

void FUN_10026dc0(void)

{
  FUN_10002650(&DAT_100355b0,"DataStructures.Audit_Trail.TableLength");
  _atexit(FUN_100281b0);
  return;
}



// Function: FUN_10026df0 at 10026df0

void FUN_10026df0(void)

{
  FUN_10002650(&DAT_100355e4,"\"OFF\"");
  _atexit(FUN_100281c0);
  return;
}



// Function: FUN_10026e20 at 10026e20

void FUN_10026e20(void)

{
  FUN_10002650(&DAT_10035594,"\"ON\"");
  _atexit(FUN_100281d0);
  return;
}



// Function: FUN_10026e50 at 10026e50

void FUN_10026e50(void)

{
  FUN_10002650(&DAT_100355cc,"CurrentRecordIndex");
  _atexit(FUN_100281e0);
  return;
}



// Function: FUN_10026e80 at 10026e80

void FUN_10026e80(void)

{
  FUN_10002650(&DAT_100355a0,"DataStructures._audit_trail_code");
  _atexit(FUN_100281f0);
  return;
}



// Function: FUN_10026eb0 at 10026eb0

void FUN_10026eb0(void)

{
  FUN_10002650(&DAT_100355b4,"ConfigFile._audit_trail_code");
  _atexit(FUN_10028200);
  return;
}



// Function: FUN_10026ee0 at 10026ee0

void FUN_10026ee0(void)

{
  FUN_10002650(&DAT_1003559c,"Records[%d]");
  _atexit(FUN_10028210);
  return;
}



// Function: FUN_10026f10 at 10026f10

void FUN_10026f10(void)

{
  FUN_10002650(&DAT_1003558c,"GTIS2");
  _atexit(FUN_10028220);
  return;
}



// Function: FUN_10026f40 at 10026f40

void FUN_10026f40(void)

{
  FUN_10002650(&DAT_100355d0,"GTIS38");
  _atexit(FUN_10028230);
  return;
}



// Function: FUN_10026f70 at 10026f70

void FUN_10026f70(void)

{
  FUN_10002650(&DAT_100355dc,"GTIS45");
  _atexit(FUN_10028240);
  return;
}



// Function: FUN_10026fa0 at 10026fa0

void FUN_10026fa0(void)

{
  FUN_10002650(&DAT_100355f0,"ConfigFile.RUN_TIME");
  _atexit(FUN_10028250);
  return;
}



// Function: FUN_10026fd0 at 10026fd0

void FUN_10026fd0(void)

{
  FUN_10002650(&DAT_100355b8,"ConfigFile.ECM_Run_Time");
  _atexit(FUN_10028260);
  return;
}



// Function: FUN_10027000 at 10027000

void FUN_10027000(void)

{
  FUN_10002650(&DAT_10035580,"ConfigFile._ECM_Run_Time");
  _atexit(FUN_10028270);
  return;
}



// Function: FUN_10027030 at 10027030

void FUN_10027030(void)

{
  FUN_10002650(&DAT_10035588,"ConfigFile.HOURS");
  _atexit(FUN_10028280);
  return;
}



// Function: FUN_10027060 at 10027060

void FUN_10027060(void)

{
  FUN_10002650(&DAT_100355bc,"ConfigFile.ECM_TIME");
  _atexit(FUN_10028290);
  return;
}



// Function: FUN_10027090 at 10027090

void FUN_10027090(void)

{
  FUN_10002650(&DAT_10035624,"DataStructures.Audit_Trail.CurrentRecordIndex");
  _atexit(FUN_100282a0);
  return;
}



// Function: FUN_100270c0 at 100270c0

void FUN_100270c0(void)

{
  FUN_10002650(&DAT_10035664,"DataStructures.Audit_Trail.RecordLength");
  _atexit(FUN_100282b0);
  return;
}



// Function: FUN_100270f0 at 100270f0

void FUN_100270f0(void)

{
  FUN_10002650(&DAT_100355fc,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_100282c0);
  return;
}



// Function: FUN_10027120 at 10027120

void FUN_10027120(void)

{
  FUN_10002650(&DAT_1003564c,"ConfigFile._Audit_Trail");
  _atexit(FUN_100282d0);
  return;
}



// Function: FUN_10027150 at 10027150

void FUN_10027150(void)

{
  FUN_10002650(&DAT_10035658,"DataStructures.Audit_Trail.Records");
  _atexit(FUN_100282e0);
  return;
}



// Function: FUN_10027180 at 10027180

void FUN_10027180(void)

{
  FUN_10002650(&DAT_1003565c,"ConfigFile._Audit_Trail[%d]");
  _atexit(FUN_100282f0);
  return;
}



// Function: FUN_100271b0 at 100271b0

void FUN_100271b0(void)

{
  FUN_10002650(&DAT_10035670,"_audit_trail_codes");
  _atexit(FUN_10028300);
  return;
}



// Function: FUN_100271e0 at 100271e0

void FUN_100271e0(void)

{
  FUN_10002650(&DAT_10035644,"DataStructures.Audit_Trail.Records[%d]");
  _atexit(FUN_10028310);
  return;
}



// Function: FUN_10027210 at 10027210

void FUN_10027210(void)

{
  FUN_10002650(&DAT_1003562c,"_tool_id");
  _atexit(FUN_10028320);
  return;
}



// Function: FUN_10027240 at 10027240

void FUN_10027240(void)

{
  FUN_10002650(&DAT_10035620,"_tool_instance");
  _atexit(FUN_10028330);
  return;
}



// Function: FUN_10027270 at 10027270

void FUN_10027270(void)

{
  FUN_10002650(&DAT_10035678,"_ECM_Run_Time");
  _atexit(FUN_10028340);
  return;
}



// Function: FUN_100272a0 at 100272a0

void FUN_100272a0(void)

{
  FUN_10002650(&DAT_10035614,"_ECM_Real_Time");
  _atexit(FUN_10028350);
  return;
}



// Function: FUN_100272d0 at 100272d0

void FUN_100272d0(void)

{
  FUN_10002650(&DAT_10035648,"_tool_version");
  _atexit(FUN_10028360);
  return;
}



// Function: FUN_10027300 at 10027300

void FUN_10027300(void)

{
  FUN_10002650(&DAT_1003560c,"DataStructures.Audit_Trail");
  _atexit(FUN_10028370);
  return;
}



// Function: FUN_10027330 at 10027330

void FUN_10027330(void)

{
  FUN_10002650(&DAT_10035630,"DataStructures.Audit_Trail.TableLength");
  _atexit(FUN_10028380);
  return;
}



// Function: FUN_10027360 at 10027360

void FUN_10027360(void)

{
  FUN_10002650(&DAT_1003566c,"\"OFF\"");
  _atexit(FUN_10028390);
  return;
}



// Function: FUN_10027390 at 10027390

void FUN_10027390(void)

{
  FUN_10002650(&DAT_10035610,"\"ON\"");
  _atexit(FUN_100283a0);
  return;
}



// Function: FUN_100273c0 at 100273c0

void FUN_100273c0(void)

{
  FUN_10002650(&DAT_10035650,"CurrentRecordIndex");
  _atexit(FUN_100283b0);
  return;
}



// Function: FUN_100273f0 at 100273f0

void FUN_100273f0(void)

{
  FUN_10002650(&DAT_10035628,"DEVCTRL_CPPJ1708_16_NOCRC");
  _atexit(FUN_100283c0);
  return;
}



// Function: FUN_10027420 at 10027420

void FUN_10027420(void)

{
  FUN_10002650(&DAT_10035668,"DEVCTRL_CPPJ1708_32");
  _atexit(FUN_100283d0);
  return;
}



// Function: FUN_10027450 at 10027450

void FUN_10027450(void)

{
  FUN_10002650(&DAT_100355f8,"DEVCTRL_CPPJ1939");
  _atexit(FUN_100283e0);
  return;
}



// Function: FUN_10027480 at 10027480

void FUN_10027480(void)

{
  FUN_10002650(&DAT_10035674,"/dclDeviceConfiguration/protocol/J1939");
  _atexit(FUN_100283f0);
  return;
}



// Function: FUN_100274b0 at 100274b0

void FUN_100274b0(void)

{
  FUN_10002650(&DAT_1003561c,"DataStructures._audit_trail_code");
  _atexit(FUN_10028400);
  return;
}



// Function: FUN_100274e0 at 100274e0

void FUN_100274e0(void)

{
  FUN_10002650(&DAT_10035634,"ConfigFile._audit_trail_code");
  _atexit(FUN_10028410);
  return;
}



// Function: FUN_10027510 at 10027510

void FUN_10027510(void)

{
  FUN_10002650(&DAT_10035618,"Records[%d]");
  _atexit(FUN_10028420);
  return;
}



// Function: FUN_10027540 at 10027540

void FUN_10027540(void)

{
  FUN_10002650(&DAT_10035608,"GTIS2");
  _atexit(FUN_10028430);
  return;
}



// Function: FUN_10027570 at 10027570

void FUN_10027570(void)

{
  FUN_10002650(&DAT_10035654,"GTIS38");
  _atexit(FUN_10028440);
  return;
}



// Function: FUN_100275a0 at 100275a0

void FUN_100275a0(void)

{
  FUN_10002650(&DAT_10035660,"GTIS45");
  _atexit(FUN_10028450);
  return;
}



// Function: FUN_100275d0 at 100275d0

void FUN_100275d0(void)

{
  FUN_10002650(&DAT_10035600,"J1939");
  _atexit(FUN_10028460);
  return;
}



// Function: FUN_10027600 at 10027600

void FUN_10027600(void)

{
  FUN_10002650(&DAT_1003567c,"ConfigFile.RUN_TIME");
  _atexit(FUN_10028470);
  return;
}



// Function: FUN_10027630 at 10027630

void FUN_10027630(void)

{
  FUN_10002650(&DAT_10035638,"ConfigFile.ECM_Run_Time");
  _atexit(FUN_10028480);
  return;
}



// Function: FUN_10027660 at 10027660

void FUN_10027660(void)

{
  FUN_10002650(&DAT_100355f4,"ConfigFile._ECM_Run_Time");
  _atexit(FUN_10028490);
  return;
}



// Function: FUN_10027690 at 10027690

void FUN_10027690(void)

{
  FUN_10002650(&DAT_10035604,"ConfigFile.HOURS");
  _atexit(FUN_100284a0);
  return;
}



// Function: FUN_100276c0 at 100276c0

void FUN_100276c0(void)

{
  FUN_10002650(&DAT_1003563c,"ConfigFile.ECM_TIME");
  _atexit(FUN_100284b0);
  return;
}



// Function: FUN_100276f0 at 100276f0

void FUN_100276f0(void)

{
  FUN_10002650(&DAT_10035640,"InstructionProtocol");
  _atexit(FUN_100284c0);
  return;
}



// Function: FUN_10027720 at 10027720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10027720(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024a6a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_10035404 = std::_Generic_error_category::vftable;
  local_8 = 0xffffffff;
  _atexit(FUN_100284d0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10027780 at 10027780

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10027780(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024aa4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_10035408 = std::_Iostream_error_category::vftable;
  local_8 = 0xffffffff;
  _atexit(FUN_10028520);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100277f0 at 100277f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100277f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10024ad4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_1003540c = std::_System_error_category::vftable;
  local_8 = 0xffffffff;
  _atexit(FUN_10028570);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100278c0 at 100278c0

void FUN_100278c0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035404);
  return;
}



// Function: FUN_100278d0 at 100278d0

void FUN_100278d0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035408);
  return;
}



// Function: FUN_100278e0 at 100278e0

void FUN_100278e0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_1003540c);
  return;
}



// Function: FUN_100278f0 at 100278f0

void FUN_100278f0(void)

{
  FUN_100032d0((int *)&DAT_10035388);
  return;
}



// Function: FUN_10027900 at 10027900

void FUN_10027900(void)

{
  FUN_100032d0((int *)&DAT_100353f0);
  return;
}



// Function: FUN_10027910 at 10027910

void FUN_10027910(void)

{
  FUN_100032d0((int *)&DAT_10035360);
  return;
}



// Function: FUN_10027920 at 10027920

void FUN_10027920(void)

{
  FUN_100032d0((int *)&DAT_100353d8);
  return;
}



// Function: FUN_10027930 at 10027930

void FUN_10027930(void)

{
  FUN_100032d0((int *)&DAT_100353e4);
  return;
}



// Function: FUN_10027940 at 10027940

void FUN_10027940(void)

{
  FUN_100032d0((int *)&DAT_100353e8);
  return;
}



// Function: FUN_10027950 at 10027950

void FUN_10027950(void)

{
  FUN_100032d0((int *)&DAT_100353f8);
  return;
}



// Function: FUN_10027960 at 10027960

void FUN_10027960(void)

{
  FUN_100032d0((int *)&DAT_100353d0);
  return;
}



// Function: FUN_10027970 at 10027970

void FUN_10027970(void)

{
  FUN_100032d0((int *)&DAT_1003538c);
  return;
}



// Function: FUN_10027980 at 10027980

void FUN_10027980(void)

{
  FUN_100032d0((int *)&DAT_10035380);
  return;
}



// Function: FUN_10027990 at 10027990

void FUN_10027990(void)

{
  FUN_100032d0((int *)&DAT_100353fc);
  return;
}



// Function: FUN_100279a0 at 100279a0

void FUN_100279a0(void)

{
  FUN_100032d0((int *)&DAT_10035374);
  return;
}



// Function: FUN_100279b0 at 100279b0

void FUN_100279b0(void)

{
  FUN_100032d0((int *)&DAT_100353d4);
  return;
}



// Function: FUN_100279c0 at 100279c0

void FUN_100279c0(void)

{
  FUN_100032d0((int *)&DAT_1003536c);
  return;
}



// Function: FUN_100279d0 at 100279d0

void FUN_100279d0(void)

{
  FUN_100032d0((int *)&DAT_100353c0);
  return;
}



// Function: FUN_100279e0 at 100279e0

void FUN_100279e0(void)

{
  FUN_100032d0((int *)&DAT_100353f4);
  return;
}



// Function: FUN_100279f0 at 100279f0

void FUN_100279f0(void)

{
  FUN_100032d0((int *)&DAT_10035370);
  return;
}



// Function: FUN_10027a00 at 10027a00

void FUN_10027a00(void)

{
  FUN_100032d0((int *)&DAT_100353dc);
  return;
}



// Function: FUN_10027a10 at 10027a10

void FUN_10027a10(void)

{
  FUN_100032d0((int *)&DAT_1003537c);
  return;
}



// Function: FUN_10027a20 at 10027a20

void FUN_10027a20(void)

{
  FUN_100032d0((int *)&DAT_100353c4);
  return;
}



// Function: FUN_10027a30 at 10027a30

void FUN_10027a30(void)

{
  FUN_100032d0((int *)&DAT_10035378);
  return;
}



// Function: FUN_10027a40 at 10027a40

void FUN_10027a40(void)

{
  FUN_100032d0((int *)&DAT_10035368);
  return;
}



// Function: FUN_10027a50 at 10027a50

void FUN_10027a50(void)

{
  FUN_100032d0((int *)&DAT_100353e0);
  return;
}



// Function: FUN_10027a60 at 10027a60

void FUN_10027a60(void)

{
  FUN_100032d0((int *)&DAT_100353ec);
  return;
}



// Function: FUN_10027a70 at 10027a70

void FUN_10027a70(void)

{
  FUN_100032d0((int *)&DAT_10035400);
  return;
}



// Function: FUN_10027a80 at 10027a80

void FUN_10027a80(void)

{
  FUN_100032d0((int *)&DAT_100353c8);
  return;
}



// Function: FUN_10027a90 at 10027a90

void FUN_10027a90(void)

{
  FUN_100032d0((int *)&DAT_1003535c);
  return;
}



// Function: FUN_10027aa0 at 10027aa0

void FUN_10027aa0(void)

{
  FUN_100032d0((int *)&DAT_10035364);
  return;
}



// Function: FUN_10027ab0 at 10027ab0

void FUN_10027ab0(void)

{
  FUN_100032d0((int *)&DAT_100353cc);
  return;
}



// Function: FUN_10027ac0 at 10027ac0

void FUN_10027ac0(void)

{
  FUN_10002f90((undefined4 *)&DAT_10035390);
  return;
}



// Function: FUN_10027ad0 at 10027ad0

void FUN_10027ad0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035404);
  return;
}



// Function: FUN_10027ae0 at 10027ae0

void FUN_10027ae0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035408);
  return;
}



// Function: FUN_10027af0 at 10027af0

void FUN_10027af0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_1003540c);
  return;
}



// Function: FUN_10027b00 at 10027b00

void FUN_10027b00(void)

{
  FUN_100032d0((int *)&DAT_10035444);
  return;
}



// Function: FUN_10027b10 at 10027b10

void FUN_10027b10(void)

{
  FUN_100032d0((int *)&DAT_1003547c);
  return;
}



// Function: FUN_10027b20 at 10027b20

void FUN_10027b20(void)

{
  FUN_100032d0((int *)&DAT_1003541c);
  return;
}



// Function: FUN_10027b30 at 10027b30

void FUN_10027b30(void)

{
  FUN_100032d0((int *)&DAT_10035464);
  return;
}



// Function: FUN_10027b40 at 10027b40

void FUN_10027b40(void)

{
  FUN_100032d0((int *)&DAT_10035470);
  return;
}



// Function: FUN_10027b50 at 10027b50

void FUN_10027b50(void)

{
  FUN_100032d0((int *)&DAT_10035474);
  return;
}



// Function: FUN_10027b60 at 10027b60

void FUN_10027b60(void)

{
  FUN_100032d0((int *)&DAT_10035484);
  return;
}



// Function: FUN_10027b70 at 10027b70

void FUN_10027b70(void)

{
  FUN_100032d0((int *)&DAT_1003545c);
  return;
}



// Function: FUN_10027b80 at 10027b80

void FUN_10027b80(void)

{
  FUN_100032d0((int *)&DAT_10035448);
  return;
}



// Function: FUN_10027b90 at 10027b90

void FUN_10027b90(void)

{
  FUN_100032d0((int *)&DAT_1003543c);
  return;
}



// Function: FUN_10027ba0 at 10027ba0

void FUN_10027ba0(void)

{
  FUN_100032d0((int *)&DAT_10035488);
  return;
}



// Function: FUN_10027bb0 at 10027bb0

void FUN_10027bb0(void)

{
  FUN_100032d0((int *)&DAT_10035430);
  return;
}



// Function: FUN_10027bc0 at 10027bc0

void FUN_10027bc0(void)

{
  FUN_100032d0((int *)&DAT_10035460);
  return;
}



// Function: FUN_10027bd0 at 10027bd0

void FUN_10027bd0(void)

{
  FUN_100032d0((int *)&DAT_10035428);
  return;
}



// Function: FUN_10027be0 at 10027be0

void FUN_10027be0(void)

{
  FUN_100032d0((int *)&DAT_1003544c);
  return;
}



// Function: FUN_10027bf0 at 10027bf0

void FUN_10027bf0(void)

{
  FUN_100032d0((int *)&DAT_10035480);
  return;
}



// Function: FUN_10027c00 at 10027c00

void FUN_10027c00(void)

{
  FUN_100032d0((int *)&DAT_1003542c);
  return;
}



// Function: FUN_10027c10 at 10027c10

void FUN_10027c10(void)

{
  FUN_100032d0((int *)&DAT_10035468);
  return;
}



// Function: FUN_10027c20 at 10027c20

void FUN_10027c20(void)

{
  FUN_100032d0((int *)&DAT_10035438);
  return;
}



// Function: FUN_10027c30 at 10027c30

void FUN_10027c30(void)

{
  FUN_100032d0((int *)&DAT_10035450);
  return;
}



// Function: FUN_10027c40 at 10027c40

void FUN_10027c40(void)

{
  FUN_100032d0((int *)&DAT_10035434);
  return;
}



// Function: FUN_10027c50 at 10027c50

void FUN_10027c50(void)

{
  FUN_100032d0((int *)&DAT_10035424);
  return;
}



// Function: FUN_10027c60 at 10027c60

void FUN_10027c60(void)

{
  FUN_100032d0((int *)&DAT_1003546c);
  return;
}



// Function: FUN_10027c70 at 10027c70

void FUN_10027c70(void)

{
  FUN_100032d0((int *)&DAT_10035478);
  return;
}



// Function: FUN_10027c80 at 10027c80

void FUN_10027c80(void)

{
  FUN_100032d0((int *)&DAT_1003548c);
  return;
}



// Function: FUN_10027c90 at 10027c90

void FUN_10027c90(void)

{
  FUN_100032d0((int *)&DAT_10035454);
  return;
}



// Function: FUN_10027ca0 at 10027ca0

void FUN_10027ca0(void)

{
  FUN_100032d0((int *)&DAT_10035418);
  return;
}



// Function: FUN_10027cb0 at 10027cb0

void FUN_10027cb0(void)

{
  FUN_100032d0((int *)&DAT_10035420);
  return;
}



// Function: FUN_10027cc0 at 10027cc0

void FUN_10027cc0(void)

{
  FUN_100032d0((int *)&DAT_10035458);
  return;
}



// Function: FUN_10027cd0 at 10027cd0

void FUN_10027cd0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035404);
  return;
}



// Function: FUN_10027ce0 at 10027ce0

void FUN_10027ce0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035408);
  return;
}



// Function: FUN_10027cf0 at 10027cf0

void FUN_10027cf0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_1003540c);
  return;
}



// Function: FUN_10027d00 at 10027d00

void FUN_10027d00(void)

{
  FUN_100032d0((int *)&DAT_100354bc);
  return;
}



// Function: FUN_10027d10 at 10027d10

void FUN_10027d10(void)

{
  FUN_100032d0((int *)&DAT_100354f4);
  return;
}



// Function: FUN_10027d20 at 10027d20

void FUN_10027d20(void)

{
  FUN_100032d0((int *)&DAT_10035494);
  return;
}



// Function: FUN_10027d30 at 10027d30

void FUN_10027d30(void)

{
  FUN_100032d0((int *)&DAT_100354dc);
  return;
}



// Function: FUN_10027d40 at 10027d40

void FUN_10027d40(void)

{
  FUN_100032d0((int *)&DAT_100354e8);
  return;
}



// Function: FUN_10027d50 at 10027d50

void FUN_10027d50(void)

{
  FUN_100032d0((int *)&DAT_100354ec);
  return;
}



// Function: FUN_10027d60 at 10027d60

void FUN_10027d60(void)

{
  FUN_100032d0((int *)&DAT_100354fc);
  return;
}



// Function: FUN_10027d70 at 10027d70

void FUN_10027d70(void)

{
  FUN_100032d0((int *)&DAT_100354d4);
  return;
}



// Function: FUN_10027d80 at 10027d80

void FUN_10027d80(void)

{
  FUN_100032d0((int *)&DAT_100354c0);
  return;
}



// Function: FUN_10027d90 at 10027d90

void FUN_10027d90(void)

{
  FUN_100032d0((int *)&DAT_100354b4);
  return;
}



// Function: FUN_10027da0 at 10027da0

void FUN_10027da0(void)

{
  FUN_100032d0((int *)&DAT_10035500);
  return;
}



// Function: FUN_10027db0 at 10027db0

void FUN_10027db0(void)

{
  FUN_100032d0((int *)&DAT_100354a8);
  return;
}



// Function: FUN_10027dc0 at 10027dc0

void FUN_10027dc0(void)

{
  FUN_100032d0((int *)&DAT_100354d8);
  return;
}



// Function: FUN_10027dd0 at 10027dd0

void FUN_10027dd0(void)

{
  FUN_100032d0((int *)&DAT_100354a0);
  return;
}



// Function: FUN_10027de0 at 10027de0

void FUN_10027de0(void)

{
  FUN_100032d0((int *)&DAT_100354c4);
  return;
}



// Function: FUN_10027df0 at 10027df0

void FUN_10027df0(void)

{
  FUN_100032d0((int *)&DAT_100354f8);
  return;
}



// Function: FUN_10027e00 at 10027e00

void FUN_10027e00(void)

{
  FUN_100032d0((int *)&DAT_100354a4);
  return;
}



// Function: FUN_10027e10 at 10027e10

void FUN_10027e10(void)

{
  FUN_100032d0((int *)&DAT_100354e0);
  return;
}



// Function: FUN_10027e20 at 10027e20

void FUN_10027e20(void)

{
  FUN_100032d0((int *)&DAT_100354b0);
  return;
}



// Function: FUN_10027e30 at 10027e30

void FUN_10027e30(void)

{
  FUN_100032d0((int *)&DAT_100354c8);
  return;
}



// Function: FUN_10027e40 at 10027e40

void FUN_10027e40(void)

{
  FUN_100032d0((int *)&DAT_100354ac);
  return;
}



// Function: FUN_10027e50 at 10027e50

void FUN_10027e50(void)

{
  FUN_100032d0((int *)&DAT_1003549c);
  return;
}



// Function: FUN_10027e60 at 10027e60

void FUN_10027e60(void)

{
  FUN_100032d0((int *)&DAT_100354e4);
  return;
}



// Function: FUN_10027e70 at 10027e70

void FUN_10027e70(void)

{
  FUN_100032d0((int *)&DAT_100354f0);
  return;
}



// Function: FUN_10027e80 at 10027e80

void FUN_10027e80(void)

{
  FUN_100032d0((int *)&DAT_10035504);
  return;
}



// Function: FUN_10027e90 at 10027e90

void FUN_10027e90(void)

{
  FUN_100032d0((int *)&DAT_100354cc);
  return;
}



// Function: FUN_10027ea0 at 10027ea0

void FUN_10027ea0(void)

{
  FUN_100032d0((int *)&DAT_10035490);
  return;
}



// Function: FUN_10027eb0 at 10027eb0

void FUN_10027eb0(void)

{
  FUN_100032d0((int *)&DAT_10035498);
  return;
}



// Function: FUN_10027ec0 at 10027ec0

void FUN_10027ec0(void)

{
  FUN_100032d0((int *)&DAT_100354d0);
  return;
}



// Function: FUN_10027ed0 at 10027ed0

void FUN_10027ed0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035404);
  return;
}



// Function: FUN_10027ee0 at 10027ee0

void FUN_10027ee0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_10035408);
  return;
}



// Function: FUN_10027ef0 at 10027ef0

void FUN_10027ef0(void)

{
  FID_conflict__bad_alloc((undefined4 *)&DAT_1003540c);
  return;
}



// Function: FUN_10027f00 at 10027f00

void FUN_10027f00(void)

{
  FUN_100032d0((int *)&DAT_10035534);
  return;
}



// Function: FUN_10027f10 at 10027f10

void FUN_10027f10(void)

{
  FUN_100032d0((int *)&DAT_1003556c);
  return;
}



// Function: FUN_10027f20 at 10027f20

void FUN_10027f20(void)

{
  FUN_100032d0((int *)&DAT_1003550c);
  return;
}



// Function: FUN_10027f30 at 10027f30

void FUN_10027f30(void)

{
  FUN_100032d0((int *)&DAT_10035554);
  return;
}



// Function: FUN_10027f40 at 10027f40

void FUN_10027f40(void)

{
  FUN_100032d0((int *)&DAT_10035560);
  return;
}



// Function: FUN_10027f50 at 10027f50

void FUN_10027f50(void)

{
  FUN_100032d0((int *)&DAT_10035564);
  return;
}



// Function: FUN_10027f60 at 10027f60

void FUN_10027f60(void)

{
  FUN_100032d0((int *)&DAT_10035574);
  return;
}



// Function: FUN_10027f70 at 10027f70

void FUN_10027f70(void)

{
  FUN_100032d0((int *)&DAT_1003554c);
  return;
}



// Function: FUN_10027f80 at 10027f80

void FUN_10027f80(void)

{
  FUN_100032d0((int *)&DAT_10035538);
  return;
}



// Function: FUN_10027f90 at 10027f90

void FUN_10027f90(void)

{
  FUN_100032d0((int *)&DAT_1003552c);
  return;
}



// Function: FUN_10027fa0 at 10027fa0

void FUN_10027fa0(void)

{
  FUN_100032d0((int *)&DAT_10035578);
  return;
}



// Function: FUN_10027fb0 at 10027fb0

void FUN_10027fb0(void)

{
  FUN_100032d0((int *)&DAT_10035520);
  return;
}



// Function: FUN_10027fc0 at 10027fc0

void FUN_10027fc0(void)

{
  FUN_100032d0((int *)&DAT_10035550);
  return;
}



// Function: FUN_10027fd0 at 10027fd0

void FUN_10027fd0(void)

{
  FUN_100032d0((int *)&DAT_10035518);
  return;
}



// Function: FUN_10027fe0 at 10027fe0

void FUN_10027fe0(void)

{
  FUN_100032d0((int *)&DAT_1003553c);
  return;
}



// Function: FUN_10027ff0 at 10027ff0

void FUN_10027ff0(void)

{
  FUN_100032d0((int *)&DAT_10035570);
  return;
}



// Function: FUN_10028000 at 10028000

void FUN_10028000(void)

{
  FUN_100032d0((int *)&DAT_1003551c);
  return;
}



// Function: FUN_10028010 at 10028010

void FUN_10028010(void)

{
  FUN_100032d0((int *)&DAT_10035558);
  return;
}



// Function: FUN_10028020 at 10028020

void FUN_10028020(void)

{
  FUN_100032d0((int *)&DAT_10035528);
  return;
}



// Function: FUN_10028030 at 10028030

void FUN_10028030(void)

{
  FUN_100032d0((int *)&DAT_10035540);
  return;
}



// Function: FUN_10028040 at 10028040

void FUN_10028040(void)

{
  FUN_100032d0((int *)&DAT_10035524);
  return;
}



// Function: FUN_10028050 at 10028050

void FUN_10028050(void)

{
  FUN_100032d0((int *)&DAT_10035514);
  return;
}



// Function: FUN_10028060 at 10028060

void FUN_10028060(void)

{
  FUN_100032d0((int *)&DAT_1003555c);
  return;
}



// Function: FUN_10028070 at 10028070

void FUN_10028070(void)

{
  FUN_100032d0((int *)&DAT_10035568);
  return;
}



// Function: FUN_10028080 at 10028080

void FUN_10028080(void)

{
  FUN_100032d0((int *)&DAT_1003557c);
  return;
}



// Function: FUN_10028090 at 10028090

void FUN_10028090(void)

{
  FUN_100032d0((int *)&DAT_10035544);
  return;
}



// Function: FUN_100280a0 at 100280a0

void FUN_100280a0(void)

{
  FUN_100032d0((int *)&DAT_10035508);
  return;
}



// Function: FUN_100280b0 at 100280b0

void FUN_100280b0(void)

{
  FUN_100032d0((int *)&DAT_10035510);
  return;
}



// Function: FUN_100280c0 at 100280c0

void FUN_100280c0(void)

{
  FUN_100032d0((int *)&DAT_10035548);
  return;
}



// Function: FUN_100280d0 at 100280d0

void FUN_100280d0(void)

{
  FUN_100032d0((int *)&DAT_100355a8);
  return;
}



// Function: FUN_100280e0 at 100280e0

void FUN_100280e0(void)

{
  FUN_100032d0((int *)&DAT_100355e0);
  return;
}



// Function: FUN_100280f0 at 100280f0

void FUN_100280f0(void)

{
  FUN_100032d0((int *)&DAT_10035584);
  return;
}



// Function: FUN_10028100 at 10028100

void FUN_10028100(void)

{
  FUN_100032d0((int *)&DAT_100355c8);
  return;
}



// Function: FUN_10028110 at 10028110

void FUN_10028110(void)

{
  FUN_100032d0((int *)&DAT_100355d4);
  return;
}



// Function: FUN_10028120 at 10028120

void FUN_10028120(void)

{
  FUN_100032d0((int *)&DAT_100355d8);
  return;
}



// Function: FUN_10028130 at 10028130

void FUN_10028130(void)

{
  FUN_100032d0((int *)&DAT_100355e8);
  return;
}



// Function: FUN_10028140 at 10028140

void FUN_10028140(void)

{
  FUN_100032d0((int *)&DAT_100355c0);
  return;
}



// Function: FUN_10028150 at 10028150

void FUN_10028150(void)

{
  FUN_100032d0((int *)&DAT_100355ac);
  return;
}



// Function: FUN_10028160 at 10028160

void FUN_10028160(void)

{
  FUN_100032d0((int *)&DAT_100355a4);
  return;
}



// Function: FUN_10028170 at 10028170

void FUN_10028170(void)

{
  FUN_100032d0((int *)&DAT_100355ec);
  return;
}



// Function: FUN_10028180 at 10028180

void FUN_10028180(void)

{
  FUN_100032d0((int *)&DAT_10035598);
  return;
}



// Function: FUN_10028190 at 10028190

void FUN_10028190(void)

{
  FUN_100032d0((int *)&DAT_100355c4);
  return;
}



// Function: FUN_100281a0 at 100281a0

void FUN_100281a0(void)

{
  FUN_100032d0((int *)&DAT_10035590);
  return;
}



// Function: FUN_100281b0 at 100281b0

void FUN_100281b0(void)

{
  FUN_100032d0((int *)&DAT_100355b0);
  return;
}



// Function: FUN_100281c0 at 100281c0

void FUN_100281c0(void)

{
  FUN_100032d0((int *)&DAT_100355e4);
  return;
}



// Function: FUN_100281d0 at 100281d0

void FUN_100281d0(void)

{
  FUN_100032d0((int *)&DAT_10035594);
  return;
}



// Function: FUN_100281e0 at 100281e0

void FUN_100281e0(void)

{
  FUN_100032d0((int *)&DAT_100355cc);
  return;
}



// Function: FUN_100281f0 at 100281f0

void FUN_100281f0(void)

{
  FUN_100032d0((int *)&DAT_100355a0);
  return;
}



// Function: FUN_10028200 at 10028200

void FUN_10028200(void)

{
  FUN_100032d0((int *)&DAT_100355b4);
  return;
}



// Function: FUN_10028210 at 10028210

void FUN_10028210(void)

{
  FUN_100032d0((int *)&DAT_1003559c);
  return;
}



// Function: FUN_10028220 at 10028220

void FUN_10028220(void)

{
  FUN_100032d0((int *)&DAT_1003558c);
  return;
}



// Function: FUN_10028230 at 10028230

void FUN_10028230(void)

{
  FUN_100032d0((int *)&DAT_100355d0);
  return;
}



// Function: FUN_10028240 at 10028240

void FUN_10028240(void)

{
  FUN_100032d0((int *)&DAT_100355dc);
  return;
}



// Function: FUN_10028250 at 10028250

void FUN_10028250(void)

{
  FUN_100032d0((int *)&DAT_100355f0);
  return;
}



// Function: FUN_10028260 at 10028260

void FUN_10028260(void)

{
  FUN_100032d0((int *)&DAT_100355b8);
  return;
}



// Function: FUN_10028270 at 10028270

void FUN_10028270(void)

{
  FUN_100032d0((int *)&DAT_10035580);
  return;
}



// Function: FUN_10028280 at 10028280

void FUN_10028280(void)

{
  FUN_100032d0((int *)&DAT_10035588);
  return;
}



// Function: FUN_10028290 at 10028290

void FUN_10028290(void)

{
  FUN_100032d0((int *)&DAT_100355bc);
  return;
}



// Function: FUN_100282a0 at 100282a0

void FUN_100282a0(void)

{
  FUN_100032d0((int *)&DAT_10035624);
  return;
}



// Function: FUN_100282b0 at 100282b0

void FUN_100282b0(void)

{
  FUN_100032d0((int *)&DAT_10035664);
  return;
}



// Function: FUN_100282c0 at 100282c0

void FUN_100282c0(void)

{
  FUN_100032d0((int *)&DAT_100355fc);
  return;
}



// Function: FUN_100282d0 at 100282d0

void FUN_100282d0(void)

{
  FUN_100032d0((int *)&DAT_1003564c);
  return;
}



// Function: FUN_100282e0 at 100282e0

void FUN_100282e0(void)

{
  FUN_100032d0((int *)&DAT_10035658);
  return;
}



// Function: FUN_100282f0 at 100282f0

void FUN_100282f0(void)

{
  FUN_100032d0((int *)&DAT_1003565c);
  return;
}



// Function: FUN_10028300 at 10028300

void FUN_10028300(void)

{
  FUN_100032d0((int *)&DAT_10035670);
  return;
}



// Function: FUN_10028310 at 10028310

void FUN_10028310(void)

{
  FUN_100032d0((int *)&DAT_10035644);
  return;
}



// Function: FUN_10028320 at 10028320

void FUN_10028320(void)

{
  FUN_100032d0((int *)&DAT_1003562c);
  return;
}



// Function: FUN_10028330 at 10028330

void FUN_10028330(void)

{
  FUN_100032d0((int *)&DAT_10035620);
  return;
}



// Function: FUN_10028340 at 10028340

void FUN_10028340(void)

{
  FUN_100032d0((int *)&DAT_10035678);
  return;
}



// Function: FUN_10028350 at 10028350

void FUN_10028350(void)

{
  FUN_100032d0((int *)&DAT_10035614);
  return;
}



// Function: FUN_10028360 at 10028360

void FUN_10028360(void)

{
  FUN_100032d0((int *)&DAT_10035648);
  return;
}



// Function: FUN_10028370 at 10028370

void FUN_10028370(void)

{
  FUN_100032d0((int *)&DAT_1003560c);
  return;
}



// Function: FUN_10028380 at 10028380

void FUN_10028380(void)

{
  FUN_100032d0((int *)&DAT_10035630);
  return;
}



// Function: FUN_10028390 at 10028390

void FUN_10028390(void)

{
  FUN_100032d0((int *)&DAT_1003566c);
  return;
}



// Function: FUN_100283a0 at 100283a0

void FUN_100283a0(void)

{
  FUN_100032d0((int *)&DAT_10035610);
  return;
}



// Function: FUN_100283b0 at 100283b0

void FUN_100283b0(void)

{
  FUN_100032d0((int *)&DAT_10035650);
  return;
}



// Function: FUN_100283c0 at 100283c0

void FUN_100283c0(void)

{
  FUN_100032d0((int *)&DAT_10035628);
  return;
}



// Function: FUN_100283d0 at 100283d0

void FUN_100283d0(void)

{
  FUN_100032d0((int *)&DAT_10035668);
  return;
}



// Function: FUN_100283e0 at 100283e0

void FUN_100283e0(void)

{
  FUN_100032d0((int *)&DAT_100355f8);
  return;
}



// Function: FUN_100283f0 at 100283f0

void FUN_100283f0(void)

{
  FUN_100032d0((int *)&DAT_10035674);
  return;
}



// Function: FUN_10028400 at 10028400

void FUN_10028400(void)

{
  FUN_100032d0((int *)&DAT_1003561c);
  return;
}



// Function: FUN_10028410 at 10028410

void FUN_10028410(void)

{
  FUN_100032d0((int *)&DAT_10035634);
  return;
}



// Function: FUN_10028420 at 10028420

void FUN_10028420(void)

{
  FUN_100032d0((int *)&DAT_10035618);
  return;
}



// Function: FUN_10028430 at 10028430

void FUN_10028430(void)

{
  FUN_100032d0((int *)&DAT_10035608);
  return;
}



// Function: FUN_10028440 at 10028440

void FUN_10028440(void)

{
  FUN_100032d0((int *)&DAT_10035654);
  return;
}



// Function: FUN_10028450 at 10028450

void FUN_10028450(void)

{
  FUN_100032d0((int *)&DAT_10035660);
  return;
}



// Function: FUN_10028460 at 10028460

void FUN_10028460(void)

{
  FUN_100032d0((int *)&DAT_10035600);
  return;
}



// Function: FUN_10028470 at 10028470

void FUN_10028470(void)

{
  FUN_100032d0((int *)&DAT_1003567c);
  return;
}



// Function: FUN_10028480 at 10028480

void FUN_10028480(void)

{
  FUN_100032d0((int *)&DAT_10035638);
  return;
}



// Function: FUN_10028490 at 10028490

void FUN_10028490(void)

{
  FUN_100032d0((int *)&DAT_100355f4);
  return;
}



// Function: FUN_100284a0 at 100284a0

void FUN_100284a0(void)

{
  FUN_100032d0((int *)&DAT_10035604);
  return;
}



// Function: FUN_100284b0 at 100284b0

void FUN_100284b0(void)

{
  FUN_100032d0((int *)&DAT_1003563c);
  return;
}



// Function: FUN_100284c0 at 100284c0

void FUN_100284c0(void)

{
  FUN_100032d0((int *)&DAT_10035640);
  return;
}



// Function: FUN_100284d0 at 100284d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100284d0(void)

{
  _DAT_10035404 = std::error_category::vftable;
  return;
}



// Function: FUN_10028520 at 10028520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10028520(void)

{
  _DAT_10035408 = std::error_category::vftable;
  return;
}



// Function: FUN_10028570 at 10028570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10028570(void)

{
  _DAT_1003540c = std::error_category::vftable;
  return;
}



// Function: FUN_100285b2 at 100285b2

void FUN_100285b2(void)

{
  ATL::CAtlBaseModule::~CAtlBaseModule((CAtlBaseModule *)&DAT_10035684);
  return;
}



// Function: FUN_100285bc at 100285bc

void FUN_100285bc(void)

{
  ATL::CAtlComModule::Term((CAtlComModule *)&DAT_100356bc);
  return;
}



// Function: FUN_100285d0 at 100285d0

void FUN_100285d0(void)

{
  Ordinal_9(&DAT_100352d0);
  return;
}



