/*
 * Decompiled from: VersionService.dll
 * Using Ghidra 11.4.1
 */

// Function: AtlW2AHelper at 10001000

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



// Function: FUN_10001038 at 10001038

void FUN_10001038(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_1000cca8);
}



// Function: FUN_10001050 at 10001050

uint FUN_10001050(byte param_1)

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



// Function: FUN_1000107c at 1000107c

void __fastcall FUN_1000107c(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FID_conflict:RegOpenKeyExA at 10001085

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
                    /* WARNING: Could not recover jumptable at 0x100010ce. Too many branches */
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



// Function: Close at 100010dc

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



// Function: Open at 100010f7

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



// Function: FUN_10001146 at 10001146

void FUN_10001146(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*extraout_ECX,extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000116c at 1000116c

void FUN_1000116c(void)

{
  exception *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(exception **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = std::bad_alloc::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::exception::~exception(this);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10001196 at 10001196

exception * FUN_10001196(void)

{
  exception *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(exception **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = std::bad_alloc::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::exception::~exception(this);
  if ((*(byte *)(unaff_EBP + 8) & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_100011d5 at 100011d5

void __fastcall FUN_100011d5(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: _Inside at 100011ef

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



// Function: FID_conflict:_Inside at 1000122a

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



// Function: FUN_10001266 at 10001266

void * FUN_10001266(void)

{
  uint uVar1;
  void *pvVar2;
  int unaff_EBP;
  
  FUN_10009190();
  uVar1 = *(uint *)(unaff_EBP + 8);
  pvVar2 = (void *)0x0;
  if (uVar1 != 0) {
    if (uVar1 < 0x80000000) {
      pvVar2 = operator_new(uVar1 * 2);
      if (pvVar2 != (void *)0x0) goto LAB_100012c0;
    }
    *(undefined4 *)(unaff_EBP + 8) = 0;
    std::exception::exception((exception *)(unaff_EBP + -0x18),(char **)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = std::bad_alloc::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException((void *)(unaff_EBP + -0x18),(ThrowInfo *)&DAT_1000cd08);
  }
LAB_100012c0:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return pvVar2;
}



// Function: FUN_100012cc at 100012cc

void FUN_100012cc(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  FUN_10009190();
  if ((*(int *)(unaff_EBP + 8) != 0) &&
     (pvVar1 = operator_new(*(uint *)(unaff_EBP + 8)), pvVar1 == (void *)0x0)) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
    std::exception::exception((exception *)(unaff_EBP + -0x18),(char **)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = std::bad_alloc::vftable;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException((void *)(unaff_EBP + -0x18),(ThrowInfo *)&DAT_1000cd08);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000132d at 1000132d

exception * FUN_1000132d(void)

{
  exception *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(exception **)(unaff_EBP + -0x10) = this;
  std::exception::exception(this,*(exception **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined ***)this = std::bad_alloc::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_10001366 at 10001366

undefined4 FUN_10001366(void)

{
  int cchWideChar;
  LPWSTR lpWideCharStr;
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_10009190();
  if ((*(int *)(unaff_EBP + 8) == 0) || (*(int *)(unaff_EBP + 0xc) == 0)) {
LAB_100013da:
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cchWideChar = MultiByteToWideChar(3,0,*(LPCSTR *)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc),
                                      (LPWSTR)0x0,0);
    iVar1 = cchWideChar;
    if (*(int *)(unaff_EBP + 0xc) == -1) {
      iVar1 = cchWideChar + -1;
    }
    lpWideCharStr = (LPWSTR)Ordinal_4(0,iVar1);
    *(LPWSTR *)(unaff_EBP + -0x14) = lpWideCharStr;
    if (lpWideCharStr != (LPWSTR)0x0) {
      iVar1 = MultiByteToWideChar(3,0,*(LPCSTR *)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc),
                                  lpWideCharStr,cchWideChar);
      if (iVar1 != cchWideChar) {
        Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_100011d5((int *)(unaff_EBP + -0x10));
        goto LAB_100013da;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100011d5((int *)(unaff_EBP + -0x10));
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_100013fc at 100013fc

void __fastcall
FUN_100013fc(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

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



// Function: CComBSTR at 10001458

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(char const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,char *param_1)

{
  int iVar1;
  
  if (param_1 != (char *)0x0) {
    iVar1 = FUN_10001366();
    *(int *)this = iVar1;
    if (iVar1 != 0) {
      return this;
    }
    FUN_10001038(0x8007000e);
  }
  *(undefined4 *)this = 0;
  return this;
}



// Function: FUN_1000148a at 1000148a

LSTATUS __fastcall FUN_1000148a(undefined4 *param_1)

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



// Function: FUN_1000148f at 1000148f

int * FUN_1000148f(void)

{
  int *piVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  if ((*(byte *)(unaff_EBP + 8) & 2) == 0) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    Ordinal_6(*extraout_ECX);
    piVar1 = extraout_ECX;
    if ((*(byte *)(unaff_EBP + 8) & 1) != 0) {
      operator_delete(extraout_ECX);
    }
  }
  else {
    piVar1 = extraout_ECX + -1;
    _eh_vector_destructor_iterator_(extraout_ECX,0xc,*piVar1,FUN_10001146);
    if ((*(byte *)(unaff_EBP + 8) & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar1;
}



// Function: FID_conflict:_Tidy at 100014f5

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



// Function: FUN_1000153e at 1000153e

undefined4 * __thiscall FUN_1000153e(void *this,uint param_1,uint param_2)

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



// Function: FUN_100015b8 at 100015b8

int * FUN_100015b8(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (7 < (uint)puVar2[5]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  if (puVar2 == (undefined4 *)0x0) {
    piVar4 = *(int **)(unaff_EBP + 8);
    *piVar4 = 0;
  }
  else {
    iVar3 = Ordinal_2(puVar2,extraout_ECX);
    piVar4 = *(int **)(unaff_EBP + 8);
    *piVar4 = iVar3;
    if (iVar3 == 0) {
      FUN_10001038(0x8007000e);
      pcVar1 = (code *)swi(3);
      piVar4 = (int *)(*pcVar1)();
      return piVar4;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar4;
}



// Function: FUN_1000160f at 1000160f

void FUN_1000160f(void)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)(unaff_EBP + -0x10)
       = this;
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_100013fc(this);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(this);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10001648 at 10001648

ushort __fastcall
FUN_10001648(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  
  puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if (puVar2 == (ushort *)0x0) {
    return 0xffff;
  }
  puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::egptr
                     (param_1);
  puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if (puVar3 < puVar2) {
LAB_100016dd:
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                       (param_1);
    uVar1 = *puVar2;
  }
  else {
    if (((byte)param_1[0x40] & 4) == 0) {
      puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         (param_1);
      if (puVar2 != (ushort *)0x0) {
        puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           (param_1);
        puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           (param_1);
        if (puVar2 <= puVar3) {
          puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr(param_1);
          if (*(ushort **)(param_1 + 0x3c) <= puVar2) goto LAB_100016ea;
        }
        puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           (param_1);
        if (*(ushort **)(param_1 + 0x3c) < puVar2) {
          puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr(param_1);
          *(ushort **)(param_1 + 0x3c) = puVar2;
        }
        puVar2 = *(ushort **)(param_1 + 0x3c);
        puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           (param_1);
        puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback(param_1);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
                  (param_1,puVar4,puVar3,puVar2);
        goto LAB_100016dd;
      }
    }
LAB_100016ea:
    uVar1 = 0xffff;
  }
  return uVar1;
}



// Function: FUN_100016f2 at 100016f2

void __thiscall
FUN_100016f2(void *this,uint *param_1,uint param_2,uint param_3,int param_4,byte param_5)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  bool bVar6;
  
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
      if (param_2 == 0 && param_3 == 0) goto LAB_10001824;
    }
    else {
      if (param_4 == 2) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
LAB_10001889:
        bVar6 = CARRY4(param_2,iVar2 >> 1);
        param_2 = param_2 + (iVar2 >> 1);
        param_3 = param_3 + (iVar2 >> 0x1f) + (uint)bVar6;
      }
      else {
        if (param_4 == 1) {
          puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          iVar2 = (int)puVar3 - (int)puVar1;
          goto LAB_10001889;
        }
        if (param_4 != 0) {
          param_2 = *(uint *)_BADOFF_exref;
          param_3 = *(uint *)(_BADOFF_exref + 4);
        }
      }
      if (-1 < (int)param_3) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
        iVar5 = iVar2 >> 0x1f;
        if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= (uint)(iVar2 >> 1)))))
        {
          puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,((int)puVar1 - (int)puVar3 >> 1) + param_2);
          goto LAB_10001824;
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
LAB_1000176f:
      bVar6 = CARRY4(param_2,iVar2 >> 1);
      param_2 = param_2 + (iVar2 >> 1);
      param_3 = param_3 + (iVar2 >> 0x1f) + (uint)bVar6;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        iVar2 = (int)puVar3 - (int)puVar1;
        goto LAB_1000176f;
      }
LAB_10001781:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    else if (param_4 != 0) goto LAB_10001781;
    if (-1 < (int)param_3) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
      iVar5 = iVar2 >> 0x1f;
      if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= (uint)(iVar2 >> 1))))) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   ((int)puVar1 - (int)puVar3 >> 1) + param_2);
        if (((param_5 & 2) != 0) &&
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
        goto LAB_10001824;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_10001824:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_1000191a at 1000191a

void __thiscall FUN_1000191a(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint in_stack_00000020;
  
  uVar6 = param_4 + param_2;
  uVar7 = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
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
  if ((uVar6 != *(uint *)_BADOFF_exref) || (uVar7 != *(uint *)(_BADOFF_exref + 4))) {
    if (((in_stack_00000020 & 1) == 0) ||
       (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this), puVar1 == (ushort *)0x0)) {
      if ((((in_stack_00000020 & 2) != 0) &&
          (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                    pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), puVar1 != (ushort *)0x0)) && (-1 < (int)uVar7)) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
        iVar5 = iVar2 >> 0x1f;
        if (((int)uVar7 <= iVar5) && (((int)uVar7 < iVar5 || (uVar6 <= (uint)(iVar2 >> 1))))) {
          puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this);
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,((int)puVar1 - (int)puVar3 >> 1) + uVar6);
          goto LAB_10001a88;
        }
      }
    }
    else if (-1 < (int)uVar7) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      iVar2 = *(int *)((int)this + 0x3c) - (int)puVar1;
      iVar5 = iVar2 >> 0x1f;
      if (((int)uVar7 <= iVar5) && (((int)uVar7 < iVar5 || (uVar6 <= (uint)(iVar2 >> 1))))) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                 eback((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this);
        puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   ((int)puVar1 - (int)puVar3 >> 1) + uVar6);
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
        goto LAB_10001a88;
      }
    }
    uVar6 = *(uint *)_BADOFF_exref;
    uVar7 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_10001a88:
  param_1[1] = uVar7;
  *param_1 = uVar6;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10001aa2 at 10001aa2

ushort __thiscall FUN_10001aa2(void *this,ushort param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  
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
  if ((*(byte *)((int)this + 0x40) & 2) != 0) {
    return 0xffff;
  }
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if (puVar1 == (ushort *)0x0) {
    uVar7 = 0;
  }
  else {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::epptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    uVar7 = (int)puVar2 - (int)puVar1 >> 1;
  }
  uVar4 = uVar7 >> 1;
  if (uVar4 < 0x20) {
    uVar4 = 0x20;
  }
  else if (uVar4 == 0) {
    return 0xffff;
  }
  do {
    if (uVar7 <= 0x7fffffff - uVar4) break;
    uVar4 = uVar4 >> 1;
  } while (uVar4 != 0);
  if (uVar4 == 0) {
    return 0xffff;
  }
  puVar1 = (ushort *)FUN_10001266();
  puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((uVar7 == 0) || (memcpy(puVar1,puVar2,uVar7 * 2), uVar7 == 0)) {
    *(ushort **)((int)this + 0x3c) = puVar1;
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
               puVar1,puVar1 + uVar4 + uVar7);
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      puVar3 = puVar1 + 1;
      puVar5 = puVar1;
      goto LAB_10001c4a;
    }
  }
  else {
    *(ushort **)((int)this + 0x3c) = puVar1 + (*(int *)((int)this + 0x3c) - (int)puVar2 >> 1);
    puVar3 = puVar1 + uVar4 + uVar7;
    puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    puVar5 = puVar1 + ((int)puVar5 - (int)puVar2 >> 1);
    puVar6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbase
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
               puVar1 + ((int)puVar6 - (int)puVar2 >> 1),puVar5,puVar3);
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      puVar3 = puVar3 + 1;
      puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      puVar5 = puVar1 + ((int)puVar5 - (int)puVar2 >> 1);
      goto LAB_10001c4a;
    }
  }
  puVar5 = (ushort *)0x0;
  puVar3 = puVar1;
LAB_10001c4a:
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,puVar1
             ,puVar5,puVar3);
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(puVar2);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Pninc
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  *puVar1 = param_1;
  return param_1;
}



// Function: FUN_10001c7d at 10001c7d

ushort __thiscall FUN_10001c7d(void *this,ushort param_1)

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
    if ((puVar1 < puVar2) &&
       (((param_1 == 0xffff ||
         (puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this), param_1 == puVar1[-1])) || ((*(byte *)((int)this + 0x40) & 2) == 0)))
       ) {
      std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,-1
                );
      if (param_1 != 0xffff) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        *puVar1 = param_1;
        return param_1;
      }
      return 0;
    }
  }
  return 0xffff;
}



// Function: FUN_10001cf5 at 10001cf5

void * __thiscall FUN_10001cf5(void *this,byte param_1)

{
  FUN_1000160f();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: ~basic_string<> at 10001d14

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



// Function: FUN_10001d1e at 10001d1e

undefined4 * __thiscall FUN_10001d1e(void *this,uint param_1,uint param_2)

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



// Function: _Tidy at 10001d9f

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



// Function: FUN_10001de3 at 10001de3

void FUN_10001de3(void)

{
  void *pvVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  if ((*(uint *)(unaff_EBP + 8) | 7) < 0x7fffffff) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0x14);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) >> 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pvVar1 = FUN_10001266();
  *(void **)(unaff_EBP + -0x18) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001e7f();
  return;
}



// Function: Catch@10001e51 at 10001e51

undefined * Catch_10001e51(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar1 = FUN_10001266();
  *(void **)(unaff_EBP + -0x18) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001e79;
}



// Function: FUN_10001e7f at 10001e7f

void FUN_10001e7f(void)

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
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch@10001ed6 at 10001ed6

void Catch_10001ed6(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001eeb at 10001eeb

void FUN_10001eeb(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  if ((*(uint *)(unaff_EBP + 8) | 0xf) != 0xffffffff) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0x14);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) >> 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_100012cc();
  *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001f82();
  return;
}



// Function: Catch@10001f54 at 10001f54

undefined * Catch_10001f54(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = FUN_100012cc();
  *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001f7c;
}



// Function: FUN_10001f82 at 10001f82

void FUN_10001f82(void)

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
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch@10001fd4 at 10001fd4

void Catch_10001fd4(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x1c),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001fe9 at 10001fe9

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * FUN_10001fe9(void)

{
  undefined4 uVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)(unaff_EBP + -0x10)
       = this;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(this);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  uVar2 = FUN_10001050((byte)uVar1);
  *(undefined4 *)(this + 0x3c) = 0;
  *(uint *)(this + 0x40) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_10002030 at 10002030

void __fastcall
FUN_10002030(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_1000203a at 1000203a

bool __thiscall FUN_1000203a(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001de3();
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



// Function: FUN_100020a4 at 100020a4

bool __thiscall FUN_100020a4(void *this,uint param_1,char param_2)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *extraout_ECX;
  
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001eeb();
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



// Function: FUN_10002109 at 10002109

undefined4 * __thiscall FUN_10002109(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10001d1e(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10001d1e(this,0,param_2);
  }
  else {
    bVar1 = FUN_1000203a(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 100021a5

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
    bVar1 = FUN_1000203a(this,param_2,'\0');
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
    this = FUN_10002109(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002223 at 10002223

undefined4 * __thiscall FUN_10002223(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_1000153e(this,_Size + uVar4,0xffffffff);
    FUN_1000153e(this,0,param_2);
  }
  else {
    bVar1 = FUN_100020a4(this,_Size,'\0');
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



// Function: basic_string<> at 100022bd

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



// Function: basic_string<> at 100022e5

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
  FUN_10002109(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: assign at 1000230d

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
           FUN_10002223(this,(undefined4 *)this,(int)param_1 - (int)pbVar2,param_2);
  }
  else {
    bVar1 = FUN_100020a4(this,param_2,'\0');
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



// Function: FUN_10002382 at 10002382

undefined2 * __thiscall FUN_10002382(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_100023b4 at 100023b4

undefined4 * __thiscall FUN_100023b4(void *this,undefined4 *param_1)

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



// Function: FUN_10002411 at 10002411

undefined2 * FUN_10002411(void)

{
  undefined2 *puVar1;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    puVar1 = *(undefined2 **)(unaff_EBP + 8);
    *(undefined4 *)(puVar1 + 10) = 7;
    *(undefined4 *)(puVar1 + 8) = 0;
    *puVar1 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  else {
    FUN_10002382(*(void **)(unaff_EBP + 8),*(wchar_t **)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    puVar1 = *(undefined2 **)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar1;
}



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 1000246a

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



// Function: basic_string<> at 10002499

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
  FUN_100023b4(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_100024be at 100024be

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_100024be(void *this,
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



// Function: FUN_10002516 at 10002516

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

undefined1 * FUN_10002516(void)

{
  int iVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    puVar3 = *(undefined1 **)(unaff_EBP + 8);
    *(undefined4 *)(puVar3 + 0x14) = 0xf;
    *(undefined4 *)(puVar3 + 0x10) = 0;
    *puVar3 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  else {
    iVar1 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 0xc));
    if (iVar1 + 1 < 0x40000000) {
      pcVar2 = (char *)AtlW2AHelper(&stack0xfffffff4,*(LPCWSTR *)(unaff_EBP + 0xc),(iVar1 + 1) * 2,3
                                   );
    }
    else {
      pcVar2 = (char *)0x0;
    }
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
              (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + 8),pcVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    puVar3 = *(undefined1 **)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar3;
}



// Function: FUN_1000259c at 1000259c

undefined4 FUN_1000259c(void)

{
  ushort *puVar1;
  ushort *puVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  int unaff_EBP;
  uint uVar3;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (((byte)this[0x40] & 2) == 0) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       (this);
    if (puVar1 != (ushort *)0x0) {
      puVar1 = *(ushort **)(this + 0x3c);
      puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         (this);
      if (puVar1 < puVar2) {
        puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           (this);
      }
      puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbase
                         (this);
      uVar3 = (int)puVar1 - (int)puVar2 >> 1;
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbase
                         (this);
      basic_string<>((void *)(unaff_EBP + -0x2c),(undefined4 *)puVar1,uVar3);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      basic_string<>(*(void **)(unaff_EBP + 8),(undefined4 *)(unaff_EBP + -0x2c));
      goto LAB_10002677;
    }
  }
  if (((byte)this[0x40] & 4) == 0) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                       (this);
    if (puVar1 == (ushort *)0x0) goto LAB_10002651;
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       (this);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::egptr
                       (this);
    uVar3 = (int)puVar2 - (int)puVar1 >> 1;
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::eback
                       (this);
    basic_string<>((void *)(unaff_EBP + -0x2c),(undefined4 *)puVar1,uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 2;
  }
  else {
LAB_10002651:
    *(undefined4 *)(unaff_EBP + -0x18) = 7;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined2 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 3;
  }
  basic_string<>(*(void **)(unaff_EBP + 8),(undefined4 *)(unaff_EBP + -0x2c));
LAB_10002677:
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FID_conflict__Tidy((void *)(unaff_EBP + -0x2c),'\x01',0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_1000269b at 1000269b

undefined4 FUN_1000269b(void)

{
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_100015b8();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_10002516();
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: _InlineIsEqualGUID at 100026eb

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



// Function: FUN_1000271b at 1000271b

undefined4 FUN_1000271b(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10011244 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_10002747 at 10002747

undefined4 FUN_10002747(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 0x4354650;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10002764 at 10002764

void __fastcall FUN_10002764(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10002771 at 10002771

void __thiscall FUN_10002771(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_14;
  
  HVar1 = CLSIDFromProgID(param_1,&local_14);
  if (-1 < HVar1) {
    CoCreateInstance(&local_14,param_2,param_3,(IID *)&DAT_1000b6b8,(LPVOID *)this);
  }
  return;
}



// Function: FUN_100027a6 at 100027a6

void __fastcall FUN_100027a6(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100027b8 at 100027b8

void __thiscall FUN_100027b8(void *this,int param_1,int param_2)

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
  uVar1 = DAT_10011a90;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x4c) = uVar1;
  return;
}



// Function: FUN_10002805 at 10002805

void __thiscall FUN_10002805(void *this,codecvt_base *param_1)

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



// Function: _Reset_back at 10002832

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



// Function: FUN_10002853 at 10002853

void __fastcall FUN_10002853(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_1000285a at 1000285a

undefined4 * __thiscall FUN_1000285a(void *this,byte param_1)

{
  FUN_10002853((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002879 at 10002879

LSTATUS __thiscall FUN_10002879(void *this,LPBYTE param_1,LPCWSTR param_2,LPDWORD param_3)

{
  short sVar1;
  LPDWORD lpcbData;
  LSTATUS LVar2;
  undefined4 *extraout_ECX;
  uint uVar3;
  
  lpcbData = param_3;
  if (param_3 == (LPDWORD)0x0) {
    FUN_10001038(0x80004005);
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
      if ((uVar3 & 1) != 0) goto LAB_100028f2;
      sVar1 = *(short *)(param_1 + ((uVar3 & 0xfffffffe) - 2));
    }
    else {
      if ((((param_3 != (LPDWORD)0x7) || ((uVar3 & 1) != 0)) || (uVar3 = uVar3 >> 1, uVar3 == 0)) ||
         (*(short *)(param_1 + uVar3 * 2 + -2) != 0)) goto LAB_100028f2;
      if (uVar3 < 2) {
        return LVar2;
      }
      sVar1 = *(short *)(param_1 + uVar3 * 2 + -4);
    }
    if (sVar1 == 0) {
      return LVar2;
    }
  }
LAB_100028f2:
  param_1[0] = '\0';
  param_1[1] = '\0';
  return 0xd;
}



// Function: FUN_10002908 at 10002908

void FUN_10002908(void)

{
  return;
}



// Function: FUN_10002909 at 10002909

void __fastcall FUN_10002909(undefined4 *param_1)

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



// Function: FUN_10002922 at 10002922

int __thiscall FUN_10002922(void *this,uint param_1)

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



// Function: FUN_1000295d at 1000295d

void __fastcall FUN_1000295d(int *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,struct_std::char_traits<char>_> *)
                      (*(int *)(*(int *)*param_1 + 4) + *param_1));
  if (pbVar1 != (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
    pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        (*(int *)(*(int *)*param_1 + 4) + *param_1));
                    /* WARNING: Could not recover jumptable at 0x10002987. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pbVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_1000298c at 1000298c

void FUN_1000298c(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int unaff_EBP;
  
  FUN_10009190();
  *(LPCRITICAL_SECTION *)(unaff_EBP + -0x10) = lpCriticalSection;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(char *)&lpCriticalSection[1].DebugInfo != '\0') {
    *(undefined1 *)&lpCriticalSection[1].DebugInfo = 0;
    DeleteCriticalSection(lpCriticalSection);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100029bb at 100029bb

int * __thiscall FUN_100029bb(void *this,int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar1;
  
  *(int **)this = param_1;
  pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*param_1 + 4) + (int)param_1));
  if (pbVar1 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
                    /* WARNING: Load size is inaccurate */
    pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**this + 4) + (int)*this));
    (**(code **)(*(int *)pbVar1 + 4))();
  }
  return (int *)this;
}



// Function: FUN_100029f4 at 100029f4

void __fastcall FUN_100029f4(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar1;
  
  pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*(int *)*param_1 + 4) + *param_1));
  if (pbVar1 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*(int *)*param_1 + 4) + *param_1));
                    /* WARNING: Could not recover jumptable at 0x10002a1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pbVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_10002a23 at 10002a23

int * __thiscall FUN_10002a23(void *this,int *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  *(int **)this = param_1;
  pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,struct_std::char_traits<char>_> *)
                      (*(int *)(*param_1 + 4) + (int)param_1));
  if (pbVar1 != (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
                    /* WARNING: Load size is inaccurate */
    pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        (*(int *)(**this + 4) + (int)*this));
    (**(code **)(*(int *)pbVar1 + 4))();
  }
  return (int *)this;
}



// Function: _Chassign at 10002a5c

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



// Function: FUN_10002a98 at 10002a98

basic_streambuf<char,struct_std::char_traits<char>_> * FUN_10002a98(void)

{
  int iVar1;
  basic_streambuf<char,struct_std::char_traits<char>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10) = this;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>(this);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined ***)this = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  FUN_100027b8(this,iVar1,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_10002ada at 10002ada

void __fastcall FUN_10002ada(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _lock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_10002aea at 10002aea

void __fastcall FUN_10002aea(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _unlock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: _Set_back at 10002afa

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



// Function: FUN_10002b2e at 10002b2e

int __cdecl FUN_10002b2e(undefined1 *param_1,FILE *param_2)

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



// Function: FUN_10002b4d at 10002b4d

bool __cdecl FUN_10002b4d(char param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = fputc((int)param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_10002b6a at 10002b6a

bool __cdecl FUN_10002b6a(byte *param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = ungetc((uint)*param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_10002b89 at 10002b89

uint __fastcall FUN_10002b89(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

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



// Function: FUN_10002bd7 at 10002bd7

void * __thiscall FUN_10002bd7(void *this,char *param_1,size_t param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(FILE **)((int)this + 0x54) != (FILE *)0x0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0 && param_3 == 0)) {
      iVar1 = 4;
    }
    iVar1 = setvbuf(*(FILE **)((int)this + 0x54),param_1,iVar1,param_2);
    if (iVar1 == 0) {
      FUN_100027b8(this,*(int *)((int)this + 0x54),1);
      return this;
    }
  }
  return (void *)0x0;
}



// Function: FUN_10002c22 at 10002c22

undefined4 __fastcall FUN_10002c22(int *param_1)

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



// Function: FUN_10002c4e at 10002c4e

void __fastcall FUN_10002c4e(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10002c66 at 10002c66

facet * FUN_10002c66(void)

{
  code *this;
  uint uVar1;
  facet *this_00;
  int unaff_EBP;
  
  FUN_10009190();
  std::_Lockit::_Lockit((_Lockit *)(unaff_EBP + -0x14),0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  this = id_exref;
  *(facet **)(unaff_EBP + -0x10) = DAT_10011a94;
  uVar1 = std::locale::id::operator_unsigned_int((id *)this);
  this_00 = (facet *)FUN_10002922(*(void **)(unaff_EBP + 8),uVar1);
  if ((this_00 == (facet *)0x0) &&
     (this_00 = *(facet **)(unaff_EBP + -0x10), this_00 == (facet *)0x0)) {
    uVar1 = std::codecvt<char,char,int>::_Getcat
                      ((facet **)(unaff_EBP + -0x10),*(locale **)(unaff_EBP + 8));
    if (uVar1 == 0xffffffff) {
      std::bad_cast::bad_cast((bad_cast *)(unaff_EBP + -0x20),"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException((void *)(unaff_EBP + -0x20),(ThrowInfo *)&DAT_1000cff4);
    }
    this_00 = *(facet **)(unaff_EBP + -0x10);
    DAT_10011a94 = this_00;
    std::locale::facet::_Incref(this_00);
    Facet_Register(this_00);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this_00;
}



// Function: FUN_10002d15 at 10002d15

uint __thiscall FUN_10002d15(void *this,uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *(int *)((int)this + 8) - *this;
  if (-(uVar1 >> 1) - 1 < uVar1) {
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



// Function: FUN_10002d3c at 10002d3c

void FUN_10002d3c(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  FUN_10009190();
  puVar1 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = **(undefined1 **)(unaff_EBP + 0xc);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002d6e at 10002d6e

int __cdecl FUN_10002d6e(void *param_1,int param_2,void *param_3)

{
  void *pvVar1;
  
  pvVar1 = memmove(param_3,param_1,param_2 - (int)param_1);
  return (int)pvVar1 + (param_2 - (int)param_1);
}



// Function: FUN_10002d8d at 10002d8d

void FUN_10002d8d(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  FUN_10009190();
  puVar1 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + 8) = puVar1;
  *(undefined1 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = **(undefined1 **)(unaff_EBP + 0xc);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002dc0 at 10002dc0

void FUN_10002dc0(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000295d(extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002de3 at 10002de3

void FUN_10002de3(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000298c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002e09 at 10002e09

void * FUN_10002e09(void)

{
  int *piVar1;
  bool bVar2;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  void *this;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(void **)(unaff_EBP + -0x10) = this;
  FUN_100029bb(this,piVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar2 = std::ios_base::good((ios_base *)(*(int *)(*piVar1 + 4) + (int)piVar1));
  if (bVar2) {
    pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::tie
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*piVar1 + 4) + (int)piVar1));
    if (pbVar3 != (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
      pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::tie
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*piVar1 + 4) + (int)piVar1));
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::flush(pbVar3);
    }
  }
  bVar2 = std::ios_base::good((ios_base *)(*(int *)(*piVar1 + 4) + (int)piVar1));
  *(bool *)((int)this + 4) = bVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_10002e85 at 10002e85

void FUN_10002e85(void)

{
  bool bVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               *extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100029f4(extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002ec4 at 10002ec4

undefined4 * FUN_10002ec4(void)

{
  undefined4 *this;
  LPCOLESTR pOVar1;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  this = *(undefined4 **)(unaff_EBP + 8);
  *this = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  if (*(char *)(unaff_EBP + 0xc) == '\0') {
    pOVar1 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
    *(LPCOLESTR *)(unaff_EBP + 0xc) = pOVar1;
    if (pOVar1 == (LPCOLESTR)0x0) goto LAB_10002f02;
  }
  else {
    pOVar1 = (LPCOLESTR)Ordinal_2(L"Microsoft.FreeThreadedXMLDOM");
    *(LPCOLESTR *)(unaff_EBP + 0xc) = pOVar1;
    if (pOVar1 != (LPCOLESTR)0x0) {
      *(undefined4 *)(unaff_EBP + -4) = 3;
      goto LAB_10002f30;
    }
LAB_10002f02:
    FUN_10001038(0x8007000e);
  }
  *(undefined4 *)(unaff_EBP + -4) = 2;
LAB_10002f30:
  FUN_10002771(this,pOVar1,(LPUNKNOWN)0x0,0x17);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  Ordinal_6(pOVar1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_10002f56 at 10002f56

undefined4 * FUN_10002f56(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *extraout_ECX = 0;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 1;
  memset(extraout_ECX + 1,0,0x18);
  *(undefined1 *)(extraout_ECX + 7) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_10002f97 at 10002f97

void FUN_10002f97(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = extraout_ECX + 8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000298c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002fc7 at 10002fc7

int __thiscall FUN_10002fc7(void *this,int *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)*param_1) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int *)this = *param_1;
    *param_1 = 0;
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10002ff0 at 10002ff0

void FUN_10002ff0(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  iVar1 = *(int *)(*(int *)(extraout_ECX + -0x50) + 4);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined ***)(iVar1 + -0x50 + extraout_ECX) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1000160f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (extraout_ECX + -0x48));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10003035 at 10003035

uint __thiscall FUN_10003035(void *this,uint param_1)

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
        bVar1 = FUN_10002b6a((byte *)((int)&param_1 + 3),*(FILE **)((int)this + 0x54));
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



// Function: FUN_100030d0 at 100030d0

void __fastcall FUN_100030d0(void *param_1)

{
  facet *pfVar1;
  
  pfVar1 = FUN_10002c66();
  FUN_10002805(param_1,(codecvt_base *)pfVar1);
  return;
}



// Function: FUN_100030ec at 100030ec

basic_streambuf<char,struct_std::char_traits<char>_> * FUN_100030ec(void)

{
  _iobuf *p_Var1;
  facet *pfVar2;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar3;
  basic_streambuf<char,struct_std::char_traits<char>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  if (*(int *)(this + 0x54) == 0) {
    p_Var1 = std::_Fiopen(*(char **)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc),
                          *(int *)(unaff_EBP + 0x10));
    if (p_Var1 != (_iobuf *)0x0) {
      FUN_100027b8(this,(int)p_Var1,1);
      std::basic_streambuf<char,struct_std::char_traits<char>_>::getloc(this);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      pfVar2 = FUN_10002c66();
      FUN_10002805(this,(codecvt_base *)pfVar2);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_10002909((undefined4 *)(unaff_EBP + 0x10));
      pbVar3 = this;
      goto LAB_10003150;
    }
  }
  pbVar3 = (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
LAB_10003150:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return pbVar3;
}



// Function: FUN_1000315f at 1000315f

void FUN_1000315f(void)

{
  uint uVar1;
  int *piVar2;
  ushort uVar3;
  uint uVar4;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar5;
  ushort *puVar6;
  int unaff_EBP;
  undefined4 unaff_EDI;
  __int64 _Var7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  
  FUN_10009190();
  uVar10 = (undefined2)unaff_EDI;
  uVar11 = (undefined2)((uint)unaff_EDI >> 0x10);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  puVar6 = *(ushort **)(unaff_EBP + 0xc);
  uVar1 = *(uint *)(puVar6 + 8);
  piVar2 = *(int **)(unaff_EBP + 8);
  _Var7 = std::ios_base::width((ios_base *)(*(int *)(*piVar2 + 4) + (int)piVar2));
  if ((_Var7 < 0) ||
     ((((int)((ulonglong)_Var7 >> 0x20) == 0 || _Var7 < 0 && ((int)_Var7 == 0)) ||
      (_Var7 = std::ios_base::width((ios_base *)(*(int *)(*piVar2 + 4) + (int)piVar2)),
      (uint)_Var7 <= uVar1)))) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
  }
  else {
    _Var7 = std::ios_base::width((ios_base *)(*(int *)(*piVar2 + 4) + (int)piVar2));
    *(uint *)(unaff_EBP + -0x18) = (int)_Var7 - uVar1;
  }
  FUN_10002e09();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(char *)(unaff_EBP + -0x1c) == '\0') {
    *(undefined4 *)(unaff_EBP + -0x14) = 4;
    FUN_100032f2();
    return;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar4 = std::ios_base::flags((ios_base *)(*(int *)(*piVar2 + 4) + (int)piVar2));
  if ((uVar4 & 0x1c0) == 0x40) {
LAB_1000323c:
    if (7 < *(uint *)(puVar6 + 10)) {
      puVar6 = *(ushort **)puVar6;
    }
    uVar8 = 0;
    uVar9 = 0;
    pbVar5 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*piVar2 + 4) + (int)piVar2));
    _Var7 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputn
                      (pbVar5,puVar6,CONCAT26(uVar11,CONCAT24(uVar10,CONCAT22(uVar9,uVar8))));
    if (((uint)_Var7 != uVar1) || ((int)((ulonglong)_Var7 >> 0x20) != 0)) {
      *(undefined4 *)(unaff_EBP + -0x14) = 4;
      goto LAB_10003276;
    }
  }
  else {
    while (*(int *)(unaff_EBP + -0x18) != 0) {
      uVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*piVar2 + 4) + (int)piVar2));
      pbVar5 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*piVar2 + 4) + (int)piVar2));
      uVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar5,uVar3);
      if (uVar3 == 0xffff) {
        *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 4;
        break;
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -1;
    }
    if (*(int *)(unaff_EBP + -0x14) == 0) goto LAB_1000323c;
  }
  while (*(int *)(unaff_EBP + -0x18) != 0) {
    uVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                      ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       (*(int *)(*piVar2 + 4) + (int)piVar2));
    pbVar5 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*piVar2 + 4) + (int)piVar2));
    uVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                      (pbVar5,uVar3);
    if (uVar3 == 0xffff) {
      *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 4;
      break;
    }
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -1;
  }
LAB_10003276:
  std::ios_base::width((ios_base *)(*(int *)(*piVar2 + 4) + (int)piVar2),0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_100032f2();
  return;
}



// Function: Catch@100032d1 at 100032d1

undefined * Catch_100032d1(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100032ef;
}



// Function: FUN_100032f2 at 100032f2

void FUN_100032f2(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10002e85();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10003321 at 10003321

void __cdecl
FUN_10003321(undefined4 *param_1,byte *param_2,byte *param_3,byte *param_4,byte param_5)

{
  for (; param_2 != param_3; param_2 = param_2 + 1) {
    *param_4 = *param_2 ^ param_5;
    param_4 = param_4 + 1;
  }
  *param_1 = param_4;
  return;
}



// Function: FUN_10003346 at 10003346

int * FUN_10003346(void)

{
  bool bVar1;
  basic_streambuf<char,struct_std::char_traits<char>_> *this;
  int iVar2;
  int *piVar3;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  piVar3 = *(int **)(unaff_EBP + 8);
  FUN_10002a23((void *)(unaff_EBP + -0x20),piVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar1 = std::basic_istream<char,struct_std::char_traits<char>_>::_Ipfx
                    (*(basic_istream<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x20),
                     false);
  *(bool *)(unaff_EBP + -0x1c) = bVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (bVar1) {
    *(undefined1 *)(unaff_EBP + -4) = 2;
    this = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,struct_std::char_traits<char>_> *)
                      (*(int *)(*piVar3 + 4) + (int)piVar3));
    iVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sbumpc(this);
    *(int *)(unaff_EBP + -0x18) = iVar2;
    if (iVar2 == -1) {
      *(undefined4 *)(unaff_EBP + -0x14) = 3;
    }
    else {
      **(undefined1 **)(unaff_EBP + 0xc) = (char)iVar2;
    }
    *(undefined4 *)(unaff_EBP + -4) = 1;
    piVar3 = (int *)FUN_100033da();
    return piVar3;
  }
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios<char,struct_std::char_traits<char>_> *)(*(int *)(*piVar3 + 4) + (int)piVar3)
             ,*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000295d((int *)(unaff_EBP + -0x20));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}



// Function: Catch@100033b8 at 100033b8

undefined * Catch_100033b8(void)

{
  int unaff_EBP;
  
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios<char,struct_std::char_traits<char>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100033d7;
}



// Function: FUN_100033da at 100033da

void FUN_100033da(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios<char,struct_std::char_traits<char>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000295d((int *)(unaff_EBP + -0x20));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10003409 at 10003409

void FUN_10003409(void)

{
  FUN_10002d3c();
  return;
}



// Function: FUN_1000341c at 1000341c

void FUN_1000341c(void *param_1,int param_2,void *param_3)

{
  FUN_10002d6e(param_1,param_2,param_3);
  return;
}



// Function: FUN_10003438 at 10003438

void FUN_10003438(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = CComErrorHandlerException::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FID_conflict__Tidy(extraout_ECX + 4,'\x01',0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10003468 at 10003468

void * __thiscall FUN_10003468(void *this,byte param_1)

{
  FUN_10003438();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10003487 at 10003487

void __fastcall FUN_10003487(int param_1)

{
  FUN_10002ff0();
                    /* WARNING: Could not recover jumptable at 0x10003495. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x50))
  ;
  return;
}



// Function: FUN_1000349b at 1000349b

void * __thiscall FUN_1000349b(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x50);
  FUN_10003487((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_100034bd at 100034bd

void __fastcall FUN_100034bd(_Container_base0 *param_1)

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



// Function: FUN_100034e0 at 100034e0

undefined4 * __cdecl
FUN_100034e0(undefined4 *param_1,byte *param_2,byte *param_3,byte *param_4,byte param_5)

{
  if (param_2 != param_3) {
    FUN_10003321(param_1,param_2,param_3,param_4,param_5);
    return param_1;
  }
  *param_1 = param_4;
  return param_1;
}



// Function: FUN_1000350f at 1000350f

/* WARNING: Removing unreachable block (ram,0x10003529) */

void FUN_1000350f(void)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  _Container_base0 *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if ((uint)(*(int *)(this + 8) - *(int *)this) < *(uint *)(unaff_EBP + 8)) {
    pvVar3 = (void *)FUN_100012cc();
    *(void **)(unaff_EBP + -0x14) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_1000341c(*(void **)this,*(int *)(this + 4),pvVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    pvVar1 = *(void **)this;
    iVar2 = *(int *)(this + 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    std::_Container_base0::_Orphan_all(this);
    *(int *)(this + 8) = *(int *)(unaff_EBP + 8) + (int)pvVar3;
    *(int *)(this + 4) = (iVar2 - (int)pvVar1) + (int)pvVar3;
    *(void **)this = pvVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch@1000359e at 1000359e

void Catch_1000359e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100035b1 at 100035b1

void FUN_100035b1(void)

{
  FUN_10002d8d();
  return;
}



// Function: FUN_100035c3 at 100035c3

undefined4 * __thiscall FUN_100035c3(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_1000203a(this,uVar2,'\0');
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



// Function: FUN_10003668 at 10003668

undefined4 FUN_10003668(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_10002f56();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_10003694 at 10003694

basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> * FUN_10003694(void)

{
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> **)(unaff_EBP + -0x14) =
       this;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *(undefined ***)this = &PTR_1000b7b0;
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(this + 0x50));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (this,(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                  (this + 4),false);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  FUN_10001fe9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_10003713 at 10003713

void __fastcall FUN_10003713(int *param_1)

{
  bool bVar1;
  int *piVar2;
  
  if (*param_1 != 0) {
    piVar2 = FUN_10003346();
    bVar1 = std::ios_base::operator!((ios_base *)(*(int *)(*piVar2 + 4) + (int)piVar2));
    if (bVar1) {
      *param_1 = 0;
    }
  }
  return;
}



// Function: FUN_1000373e at 1000373e

void __thiscall FUN_1000373e(void *this,uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if ((uVar1 <= param_1) && (*(uint *)((int)this + 0x14) != param_1)) {
    bVar2 = FUN_1000203a(this,param_1,'\x01');
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



// Function: FUN_10003777 at 10003777

undefined4 * __thiscall
FUN_10003777(void *this,uint param_1,undefined4 *param_2,uint param_3,uint param_4)

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
      bVar3 = FUN_1000203a(this,uVar8,'\0');
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



// Function: FUN_100038ac at 100038ac

undefined4 * __thiscall FUN_100038ac(void *this,undefined4 *param_1,uint param_2)

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
      bVar1 = FUN_1000203a(this,uVar2,'\0');
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
    this = FUN_100035c3(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: reserve at 1000394e

/* Library Function - Single Match
    public: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::reserve(unsigned int)
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::reserve
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)(this + 0x10);
  if ((uVar1 <= param_1) && (*(uint *)(this + 0x14) != param_1)) {
    bVar2 = FUN_100020a4(this,param_1,'\x01');
    if (bVar2) {
      *(uint *)(this + 0x10) = uVar1;
      if (0xf < *(uint *)(this + 0x14)) {
        this = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                this;
      }
      this[uVar1] = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>)
                    0x0;
    }
  }
  return;
}



// Function: FUN_10003985 at 10003985

void __thiscall FUN_10003985(void *this,int param_1)

{
  uint uVar1;
  uint extraout_EAX;
  int extraout_ECX;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  iVar2 = *this;
  uVar1 = *(int *)((int)this + 4) - iVar2;
  if (-param_1 - 1U < uVar1) {
    std::_Xlength_error("vector<T> too long");
    uVar1 = extraout_EAX;
    iVar2 = extraout_ECX;
  }
  if ((uint)(*(int *)((int)this + 8) - iVar2) < uVar1 + param_1) {
    FUN_10002d15(this,uVar1 + param_1);
    FUN_1000350f();
  }
  return;
}



// Function: FUN_100039c8 at 100039c8

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_100039c8(void *this,uint param_1,char param_2)

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
    bVar2 = FUN_100020a4(this,uVar1,'\0');
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



// Function: FUN_10003a29 at 10003a29

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10003a29(void *this,uint param_1,char param_2)

{
  bool bVar1;
  void *pvVar2;
  void *extraout_ECX;
  
  pvVar2 = this;
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    pvVar2 = extraout_ECX;
  }
  bVar1 = FUN_100020a4(pvVar2,param_1,'\0');
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



// Function: basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> at 10003a77

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
  FUN_10002223(this,(undefined4 *)param_1,0,0xffffffff);
  return this;
}



// Function: FUN_10003a9d at 10003a9d

uint FUN_10003a9d(void)

{
  int iVar1;
  FILE *pFVar2;
  char *pcVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 uVar6;
  void *_Src;
  int iVar7;
  basic_streambuf<char,struct_std::char_traits<char>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(this);
  if ((pcVar3 != (char *)0x0) &&
     (iVar7 = **(int **)(this + 0x30), iVar1 = **(int **)(this + 0x20),
     pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(this),
     pcVar3 < (char *)(iVar7 + iVar1))) {
    pbVar4 = (byte *)std::basic_streambuf<char,struct_std::char_traits<char>_>::_Gninc(this);
    uVar5 = (uint)*pbVar4;
    goto LAB_10003b09;
  }
  if (*(int *)(this + 0x54) != 0) {
    std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back
              ((basic_filebuf<char,struct_std::char_traits<char>_> *)this);
    if (*(int *)(this + 0x44) != 0) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0xf;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined1 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
LAB_10003bca:
      do {
        iVar7 = fgetc(*(FILE **)(this + 0x54));
        if (iVar7 == -1) {
LAB_10003bd9:
          uVar5 = 0xffffffff;
          goto LAB_10003bdc;
        }
        FUN_100039c8((void *)(unaff_EBP + -0x34),1,(char)iVar7);
        pcVar3 = *(char **)(unaff_EBP + -0x34);
        if (*(uint *)(unaff_EBP + -0x20) < 0x10) {
          pcVar3 = (char *)(unaff_EBP + -0x34);
        }
        iVar7 = std::codecvt<char,char,int>::in
                          (*(codecvt<char,char,int> **)(this + 0x44),(int *)(this + 0x4c),pcVar3,
                           pcVar3 + *(int *)(unaff_EBP + -0x24),(char **)(unaff_EBP + -0x14),
                           (char *)(unaff_EBP + -0xd),(char *)(unaff_EBP + -0xc),
                           (char **)(unaff_EBP + -0x18));
        if (iVar7 < 0) goto LAB_10003bd9;
        if (iVar7 < 2) {
          iVar7 = *(int *)(unaff_EBP + -0x34);
          if (*(int *)(unaff_EBP + -0x18) != unaff_EBP + -0xd) {
            if (*(uint *)(unaff_EBP + -0x20) < 0x10) {
              iVar7 = unaff_EBP + -0x34;
            }
            iVar7 = (iVar7 - *(int *)(unaff_EBP + -0x14)) + *(int *)(unaff_EBP + -0x24);
            while (0 < iVar7) {
              iVar7 = iVar7 + -1;
              ungetc((int)*(char *)(iVar7 + *(int *)(unaff_EBP + -0x14)),*(FILE **)(this + 0x54));
            }
            goto LAB_10003c1d;
          }
          if (*(uint *)(unaff_EBP + -0x20) < 0x10) {
            iVar7 = unaff_EBP + -0x34;
          }
          FUN_1000153e((void *)(unaff_EBP + -0x34),0,*(int *)(unaff_EBP + -0x14) - iVar7);
          goto LAB_10003bca;
        }
        if (iVar7 != 3) goto LAB_10003bd9;
      } while (*(int *)(unaff_EBP + -0x24) == 0);
      _Src = *(void **)(unaff_EBP + -0x34);
      if (*(uint *)(unaff_EBP + -0x20) < 0x10) {
        _Src = (void *)(unaff_EBP + -0x34);
      }
      memcpy_s((void *)(unaff_EBP + -0xd),1,_Src,1);
LAB_10003c1d:
      uVar5 = (uint)*(byte *)(unaff_EBP + -0xd);
LAB_10003bdc:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 (unaff_EBP + -0x34),true,0);
      goto LAB_10003b09;
    }
    pFVar2 = *(FILE **)(this + 0x54);
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
    uVar6 = FUN_10002b2e((undefined1 *)(unaff_EBP + -0xd),pFVar2);
    if ((char)uVar6 != '\0') {
      uVar5 = (uint)*(byte *)(unaff_EBP + -0xd);
      goto LAB_10003b09;
    }
  }
  uVar5 = 0xffffffff;
LAB_10003b09:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}



// Function: FUN_10003c23 at 10003c23

void FUN_10003c23(void)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
   (unaff_EBP + -0x14) = this;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::reserve
            (this,*(int *)(unaff_EBP + 0xc) - *(int *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (*(char **)(unaff_EBP + 8) != *(char **)(unaff_EBP + 0xc)) {
    FUN_100039c8(*(void **)(unaff_EBP + -0x14),1,**(char **)(unaff_EBP + 8));
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch@10003c78 at 10003c78

void Catch_10003c78(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x14),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10003c8d at 10003c8d

void __thiscall FUN_10003c8d(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < uVar1) && (*this <= param_1)) {
    if (uVar1 == *(uint *)((int)this + 8)) {
      FUN_10003985(this,1);
    }
    FUN_10003409();
  }
  else {
    if (uVar1 == *(uint *)((int)this + 8)) {
      FUN_10003985(this,1);
    }
    FUN_100035b1();
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}



// Function: FUN_10003cee at 10003cee

int FUN_10003cee(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  void *_Str;
  size_t sVar6;
  basic_streambuf<char,struct_std::char_traits<char>_> *this;
  char *pcVar7;
  char cVar8;
  int unaff_EBP;
  size_t _Count;
  
  FUN_10009190();
  iVar4 = *(int *)(unaff_EBP + 8);
  if (iVar4 == -1) {
    iVar4 = 0;
  }
  else {
    pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(this);
    cVar8 = (char)iVar4;
    if ((pcVar5 == (char *)0x0) ||
       (iVar1 = **(int **)(this + 0x34), iVar2 = **(int **)(this + 0x24),
       pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(this),
       (char *)(iVar1 + iVar2) <= pcVar5)) {
      if (*(int *)(this + 0x54) != 0) {
        std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back
                  ((basic_filebuf<char,struct_std::char_traits<char>_> *)this);
        if (*(int *)(this + 0x44) != 0) {
          *(char *)(unaff_EBP + -0x10) = cVar8;
          *(undefined4 *)(unaff_EBP + -0x20) = 0xf;
          *(undefined4 *)(unaff_EBP + -0x24) = 0;
          *(undefined1 *)(unaff_EBP + -0x34) = 0;
          FUN_10003a29((void *)(unaff_EBP + -0x34),8,'\0');
          *(undefined4 *)(unaff_EBP + -4) = 0;
LAB_10003d92:
          pcVar5 = *(char **)(unaff_EBP + -0x34);
          if (*(uint *)(unaff_EBP + -0x20) < 0x10) {
            pcVar5 = (char *)(unaff_EBP + -0x34);
            pcVar7 = pcVar5;
          }
          else {
            pcVar7 = *(char **)(unaff_EBP + -0x34);
          }
          iVar4 = std::codecvt<char,char,int>::out
                            (*(codecvt<char,char,int> **)(this + 0x44),(int *)(this + 0x4c),
                             (char *)(unaff_EBP + -0x10),(char *)(unaff_EBP + -0xf),
                             (char **)(unaff_EBP + -0x18),pcVar7,
                             pcVar5 + *(int *)(unaff_EBP + -0x24),(char **)(unaff_EBP + -0x14));
          if (iVar4 < 0) goto LAB_10003e43;
          if (iVar4 < 2) {
            iVar4 = *(int *)(unaff_EBP + -0x34);
            if (*(uint *)(unaff_EBP + -0x20) < 0x10) {
              iVar4 = unaff_EBP + -0x34;
            }
            _Count = *(int *)(unaff_EBP + -0x14) - iVar4;
            if (_Count != 0) {
              _Str = *(void **)(unaff_EBP + -0x34);
              if (*(uint *)(unaff_EBP + -0x20) < 0x10) {
                _Str = (void *)(unaff_EBP + -0x34);
              }
              sVar6 = fwrite(_Str,1,_Count,*(FILE **)(this + 0x54));
              if (_Count != sVar6) goto LAB_10003e43;
            }
            this[0x49] = (basic_streambuf<char,struct_std::char_traits<char>_>)0x1;
            if (*(int *)(unaff_EBP + -0x18) == unaff_EBP + -0x10) goto code_r0x10003e0b;
          }
          else if ((iVar4 != 3) ||
                  (bVar3 = FUN_10002b4d((char)*(undefined4 *)(unaff_EBP + -0x10),
                                        *(FILE **)(this + 0x54)), !bVar3)) goto LAB_10003e43;
          iVar4 = *(int *)(unaff_EBP + 8);
LAB_10003e46:
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(unaff_EBP + -0x34),true,0);
          goto LAB_10003d39;
        }
        bVar3 = FUN_10002b4d(cVar8,*(FILE **)(this + 0x54));
        if (bVar3) goto LAB_10003d39;
      }
      iVar4 = -1;
    }
    else {
      pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc(this);
      *pcVar5 = cVar8;
    }
  }
LAB_10003d39:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
code_r0x10003e0b:
  if (_Count == 0) {
    if (0x1f < *(uint *)(unaff_EBP + -0x24)) {
LAB_10003e43:
      iVar4 = -1;
      goto LAB_10003e46;
    }
    FUN_100039c8((void *)(unaff_EBP + -0x34),8,'\0');
  }
  goto LAB_10003d92;
}



// Function: FUN_10003e62 at 10003e62

undefined1 FUN_10003e62(void)

{
  int iVar1;
  char *pcVar2;
  void *_Str;
  size_t sVar3;
  int *extraout_ECX;
  char *pcVar4;
  undefined1 uVar5;
  int unaff_EBP;
  size_t _Count;
  
  FUN_10009190();
  if ((extraout_ECX[0x11] == 0) || (*(char *)((int)extraout_ECX + 0x49) == '\0')) {
    uVar5 = 1;
  }
  else {
    iVar1 = (**(code **)(*extraout_ECX + 0xc))(0xffffffff);
    if (iVar1 == -1) {
      uVar5 = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x18) = 0xf;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined1 *)(unaff_EBP + -0x2c) = 0;
      FUN_10003a29((void *)(unaff_EBP + -0x2c),8,'\0');
      *(undefined4 *)(unaff_EBP + -4) = 0;
      while( true ) {
        pcVar2 = *(char **)(unaff_EBP + -0x2c);
        if (*(uint *)(unaff_EBP + -0x18) < 0x10) {
          pcVar2 = (char *)(unaff_EBP + -0x2c);
          pcVar4 = pcVar2;
        }
        else {
          pcVar4 = *(char **)(unaff_EBP + -0x2c);
        }
        iVar1 = std::codecvt<char,char,int>::unshift
                          ((codecvt<char,char,int> *)extraout_ECX[0x11],extraout_ECX + 0x13,pcVar4,
                           pcVar2 + *(int *)(unaff_EBP + -0x1c),(char **)(unaff_EBP + -0x10));
        if (iVar1 != 0) break;
        *(undefined1 *)((int)extraout_ECX + 0x49) = 0;
LAB_10003f08:
        iVar1 = *(int *)(unaff_EBP + -0x2c);
        if (*(uint *)(unaff_EBP + -0x18) < 0x10) {
          iVar1 = unaff_EBP + -0x2c;
        }
        _Count = *(int *)(unaff_EBP + -0x10) - iVar1;
        if (_Count != 0) {
          _Str = *(void **)(unaff_EBP + -0x2c);
          if (*(uint *)(unaff_EBP + -0x18) < 0x10) {
            _Str = (void *)(unaff_EBP + -0x2c);
          }
          sVar3 = fwrite(_Str,1,_Count,(FILE *)extraout_ECX[0x15]);
          if (_Count != sVar3) goto LAB_10003ee8;
        }
        if (*(char *)((int)extraout_ECX + 0x49) == '\0') goto LAB_10003f59;
        if (_Count == 0) {
          FUN_100039c8((void *)(unaff_EBP + -0x2c),8,'\0');
        }
      }
      if (iVar1 == 1) goto LAB_10003f08;
      if (iVar1 != 3) {
LAB_10003ee8:
        uVar5 = 0;
        goto LAB_10003eea;
      }
LAB_10003f59:
      uVar5 = 1;
LAB_10003eea:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 (unaff_EBP + -0x2c),true,0);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}



// Function: FUN_10003f6d at 10003f6d

undefined1 * __fastcall FUN_10003f6d(undefined1 *param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *param_1 = 0;
  FUN_10003c23();
  return param_1;
}



// Function: FUN_10003f96 at 10003f96

undefined4 * FUN_10003f96(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  iVar1 = *(int *)(unaff_EBP + 8);
  *extraout_ECX = CComErrorHandlerException::vftable;
  extraout_ECX[1] = *(undefined4 *)(iVar1 + 4);
  extraout_ECX[2] = *(undefined4 *)(iVar1 + 8);
  extraout_ECX[3] = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  basic_string<>(extraout_ECX + 4,(undefined4 *)(iVar1 + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xb] = *(undefined4 *)(iVar1 + 0x2c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_10003ff0 at 10003ff0

undefined4 * FUN_10003ff0(void)

{
  wchar_t *_Str;
  size_t sVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *extraout_ECX = CComErrorHandlerException::vftable;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 7;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined2 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _Str = *(wchar_t **)(unaff_EBP + 0x14);
  extraout_ECX[1] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[2] = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[3] = *(undefined4 *)(unaff_EBP + 0x10);
  sVar1 = wcslen(_Str);
  FID_conflict_assign(extraout_ECX + 4,*(undefined4 **)(unaff_EBP + 0x14),sVar1);
  extraout_ECX[0xb] = *(undefined4 *)(unaff_EBP + 0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_10004060 at 10004060

void __thiscall FUN_10004060(void *this,undefined4 *param_1,int param_2,int param_3,int param_4)

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
  if ((((*(int *)((int)this + 0x54) != 0) && (cVar2 = FUN_10003e62(), cVar2 != '\0')) &&
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



// Function: FUN_1000411a at 1000411a

void __thiscall
FUN_1000411a(void *this,undefined4 *param_1,int param_2,int param_3,undefined4 param_4,
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
    cVar2 = FUN_10003e62();
    if (cVar2 != '\0') {
      iVar3 = fsetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c);
      if (iVar3 == 0) {
        if (param_2 != 0 || param_3 != 0) {
          iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(1,param_3),unaff_EDI);
          if (iVar3 != 0) goto LAB_100041ad;
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
          goto LAB_100041c8;
        }
      }
    }
  }
LAB_100041ad:
  uVar1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = *(undefined4 *)(_BADOFF_exref + 4);
  uVar4 = 0;
  *param_1 = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
LAB_100041c8:
  param_1[4] = uVar4;
  return;
}



// Function: FUN_100041d2 at 100041d2

basic_streambuf<char,struct_std::char_traits<char>_> * __fastcall
FUN_100041d2(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char cVar1;
  int iVar2;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar3;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    cVar1 = FUN_10003e62();
    pbVar3 = param_1;
    if (cVar1 == '\0') {
      pbVar3 = (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
    }
    iVar2 = fclose(*(FILE **)(param_1 + 0x54));
    if (iVar2 == 0) goto LAB_100041fb;
  }
  pbVar3 = (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
LAB_100041fb:
  param_1[0x50] = (basic_streambuf<char,struct_std::char_traits<char>_>)0x0;
  param_1[0x49] = (basic_streambuf<char,struct_std::char_traits<char>_>)0x0;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init(param_1);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x4c) = DAT_10011a90;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return pbVar3;
}



// Function: FUN_1000421d at 1000421d

void FUN_1000421d(void)

{
  int unaff_EBP;
  
  FUN_10009190();
  FUN_10003ff0();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x68);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -100);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x60);
  *(undefined ***)(unaff_EBP + -0x3c) = CComErrorHandlerException::vftable;
  basic_string<>((void *)(unaff_EBP + -0x2c),(undefined4 *)(unaff_EBP + -0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x40);
  *(undefined1 *)(unaff_EBP + -4) = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)(unaff_EBP + -0x3c),(ThrowInfo *)&DAT_1000d480);
}



// Function: FUN_10004287 at 10004287

void __cdecl
FUN_10004287(undefined4 *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            void *param_6)

{
  while (param_2 != param_4) {
    FUN_10003c8d(param_6,(uint)&param_3);
    FUN_10003713(&param_2);
  }
  *param_1 = param_6;
  return;
}



// Function: FUN_100042af at 100042af

void FUN_100042af(void)

{
  basic_filebuf<char,struct_std::char_traits<char>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(basic_filebuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(this + 0x54) != 0) {
    std::basic_filebuf<char,struct_std::char_traits<char>_>::_Reset_back(this);
  }
  if (this[0x50] != (basic_filebuf<char,struct_std::char_traits<char>_>)0x0) {
    FUN_100041d2((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100042fb at 100042fb

void * __thiscall FUN_100042fb(void *this,byte param_1)

{
  FUN_100042af();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000431a at 1000431a

undefined2 * FUN_1000431a(void)

{
  undefined2 *this;
  undefined4 uVar1;
  size_t sVar2;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  this = *(undefined2 **)(unaff_EBP + 8);
  *(undefined4 *)(this + 10) = 7;
  *(undefined4 *)(this + 8) = 0;
  *this = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x10);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  sVar2 = wcslen(*(wchar_t **)(unaff_EBP + 0x10));
  FUN_1000373e(this,sVar2 + *(int *)(unaff_EBP + -0x14));
  FUN_100035c3(this,*(undefined4 **)(unaff_EBP + 0xc),0,0xffffffff);
  sVar2 = wcslen(*(wchar_t **)(unaff_EBP + 0x10));
  FUN_100038ac(this,*(undefined4 **)(unaff_EBP + 0x10),sVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_1000439c at 1000439c

undefined4 FUN_1000439c(void)

{
  undefined4 *this;
  undefined4 *puVar1;
  int unaff_EBP;
  
  FUN_10009190();
  puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
  this = *(undefined4 **)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (((uint)(puVar1[5] - puVar1[4]) < (uint)this[4]) &&
     ((uint)puVar1[4] <= (uint)(this[5] - this[4]))) {
    puVar1 = FUN_10003777(this,0,puVar1,0,0xffffffff);
    basic_string<>(*(void **)(unaff_EBP + 8),puVar1);
  }
  else {
    puVar1 = FUN_100035c3(puVar1,this,0,0xffffffff);
    basic_string<>(*(void **)(unaff_EBP + 8),puVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_10004412 at 10004412

void __thiscall FUN_10004412(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 < 0)) {
    *(undefined1 *)this = 1;
    FUN_1000421d();
  }
  return;
}



// Function: FUN_10004432 at 10004432

undefined4 * __cdecl
FUN_10004432(undefined4 *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            void *param_6)

{
  FUN_10004287(param_1,param_2,param_3,param_4,param_5,param_6);
  return param_1;
}



// Function: FUN_10004457 at 10004457

undefined1 * FUN_10004457(void)

{
  undefined1 *this;
  byte *pbVar1;
  byte *pbVar2;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  pbVar2 = *(byte **)(unaff_EBP + 0xc);
  if (*(uint *)(unaff_EBP + 0x20) < 0x10) {
    pbVar2 = (byte *)(unaff_EBP + 0xc);
  }
  pbVar1 = *(byte **)(unaff_EBP + 0xc);
  if (*(uint *)(unaff_EBP + 0x20) < 0x10) {
    pbVar1 = (byte *)(unaff_EBP + 0xc);
  }
  FUN_100034e0((undefined4 *)(unaff_EBP + -0x14),pbVar1,pbVar2 + *(int *)(unaff_EBP + 0x1c),pbVar2,
               0xd);
  this = *(undefined1 **)(unaff_EBP + 8);
  *(undefined4 *)(this + 0x14) = 0xf;
  *(undefined4 *)(this + 0x10) = 0;
  *this = 0;
  FUN_100024be(this,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                    (unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + 0xc),true,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_100044e0 at 100044e0

undefined4 FUN_100044e0(void)

{
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_1000259c();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_10004516 at 10004516

basic_istream<char,struct_std::char_traits<char>_> * FUN_10004516(void)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  basic_istream<char,struct_std::char_traits<char>_> *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(basic_istream<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x14) = this;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    *(undefined ***)this = &PTR_1000b7c4;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)(this + 0x68));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  std::basic_istream<char,struct_std::char_traits<char>_>::
  basic_istream<char,struct_std::char_traits<char>_>
            (this,(basic_streambuf<char,struct_std::char_traits<char>_> *)(this + 0x10),false);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined ***)(this + *(int *)(*(int *)this + 4)) =
       std::basic_ifstream<char,struct_std::char_traits<char>_>::vftable;
  FUN_10002a98();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pbVar1 = FUN_100030ec();
  if (pbVar1 == (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)(this + *(int *)(*(int *)this + 4))
               ,2,false);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}



// Function: FUN_100045b6 at 100045b6

void FUN_100045b6(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  iVar1 = *(int *)(*(int *)(extraout_ECX + -0x68) + 4);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined ***)(iVar1 + -0x68 + extraout_ECX) =
       std::basic_ifstream<char,struct_std::char_traits<char>_>::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_100042af();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::basic_istream<char,struct_std::char_traits<char>_>::
  ~basic_istream<char,struct_std::char_traits<char>_>
            ((basic_istream<char,struct_std::char_traits<char>_> *)(extraout_ECX + -0x58));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100045fa at 100045fa

void __cdecl
FUN_100045fa(undefined4 *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            void *param_6)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  puVar1 = FUN_10004432(&local_8,param_2,param_3,param_4,param_5,param_6);
  *param_1 = *puVar1;
  return;
}



// Function: FUN_10004622 at 10004622

int __thiscall FUN_10004622(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_10004412((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_1000463e at 1000463e

undefined4 FUN_1000463e(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    FUN_10003694();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),7);
    FUN_100044e0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piVar4 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = *piVar4;
    *piVar4 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002ff0();
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x70));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_100046eb at 100046eb

undefined4 FUN_100046eb(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    FUN_10003694();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),6);
    FUN_100044e0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piVar4 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = *piVar4;
    *piVar4 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002ff0();
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x70));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_10004798 at 10004798

undefined4 FUN_10004798(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    FUN_10003694();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),0x110);
    FUN_100044e0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piVar4 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = *piVar4;
    *piVar4 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002ff0();
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x70));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_1000484b at 1000484b

undefined4 FUN_1000484b(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    FUN_10003694();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),0);
    FUN_100044e0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piVar4 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = *piVar4;
    *piVar4 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002ff0();
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x70));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_100048f7 at 100048f7

undefined4 FUN_100048f7(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    FUN_10003694();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),0xb55);
    FUN_100044e0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piVar4 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = *piVar4;
    *piVar4 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002ff0();
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x70));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_100049aa at 100049aa

undefined4 FUN_100049aa(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x40))(*(int **)(unaff_EBP + 8),unaff_EBP + 0xc);
    FUN_10003694();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_10002411();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_1000315f();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),0xb55);
    FUN_100044e0();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    piVar4 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    iVar2 = *piVar4;
    *piVar4 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_10002ff0();
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x70));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_10004aab at 10004aab

undefined4 FUN_10004aab(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int unaff_EBP;
  
  FUN_10009190();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    FUN_10003694();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),7);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),0);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),6);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),0);
    FUN_1000315f();
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xc0),0x110);
    FUN_100044e0();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piVar4 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = *piVar4;
    *piVar4 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x28),'\x01',0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002ff0();
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x70));
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_10004ba7 at 10004ba7

void __fastcall FUN_10004ba7(int param_1)

{
  FUN_100045b6();
                    /* WARNING: Could not recover jumptable at 0x10004bb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(param_1 + 0x68));
  return;
}



// Function: FUN_10004bbb at 10004bbb

void * __thiscall FUN_10004bbb(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x68);
  FUN_10004ba7((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_10004bdd at 10004bdd

undefined4 FUN_10004bdd(void)

{
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_10004516();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::ios_base::unsetf
            ((ios_base *)(unaff_EBP + -0xd8 + *(int *)(*(int *)(unaff_EBP + -0xd8) + 4)),1);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(int *)(unaff_EBP + -0x14) = unaff_EBP + -0xd8;
  FUN_10003713((int *)(unaff_EBP + -0x14));
  FUN_100045fa((undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + -0x14),
               *(undefined4 *)(unaff_EBP + -0x10),0,*(undefined4 *)(unaff_EBP + 0x24),
               (void *)(unaff_EBP + -0x28));
  FUN_10003f6d(*(undefined1 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -0x18) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_100034bd((_Container_base0 *)(unaff_EBP + -0x28));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_100045b6();
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(unaff_EBP + -0x70));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + 0xc),true,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_10004cbe at 10004cbe

undefined4 FUN_10004cbe(void)

{
  int iVar1;
  LSTATUS LVar2;
  size_t sVar3;
  undefined4 *puVar4;
  int *piVar5;
  char *pcVar6;
  undefined2 *puVar7;
  undefined4 extraout_ECX;
  int unaff_EBP;
  code *pcVar8;
  undefined2 *puStack_3cc;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffc50;
  *(undefined4 *)(unaff_EBP + -0x2c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  puVar7 = *(undefined2 **)(unaff_EBP + 8);
  *(undefined4 *)(puVar7 + 10) = 7;
  *(undefined4 *)(puVar7 + 8) = 0;
  *puVar7 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x4c) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_10002c4e((undefined4 *)(unaff_EBP + -0x3c));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  *(undefined4 *)(unaff_EBP + -0x54) = 7;
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  *(undefined2 *)(unaff_EBP + -0x68) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  *(undefined4 *)(unaff_EBP + -0x70) = 7;
  *(undefined4 *)(unaff_EBP + -0x74) = 0;
  *(undefined2 *)(unaff_EBP + -0x84) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  iVar1 = Open((void *)(unaff_EBP + -0x48),(HKEY)0x80000002,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths\\",0x2001f);
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x208;
    LVar2 = FUN_10002879((void *)(unaff_EBP + -0x48),(LPBYTE)(unaff_EBP + -0x3b0),L"Libraries",
                         (LPDWORD)(unaff_EBP + -0x1c));
    if (LVar2 == 0) {
      sVar3 = wcslen((wchar_t *)(unaff_EBP + -0x3b0));
      FID_conflict_assign((void *)(unaff_EBP + -0x84),(undefined4 *)(unaff_EBP + -0x3b0),sVar3);
      puVar4 = (undefined4 *)FUN_1000431a();
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_100023b4((void *)(unaff_EBP + -0x84),puVar4);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FID_conflict__Tidy((void *)(unaff_EBP + -0xa0),'\x01',0);
    }
  }
  *(undefined2 ***)(unaff_EBP + -0x1c) = &puStack_3cc;
  FUN_1000269b();
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10004bdd();
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  *(undefined2 ***)(unaff_EBP + -0x1c) = &puStack_3cc;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &puStack_3cc,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0xf4));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10004457();
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  piVar5 = FUN_10002ec4();
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FUN_10002fc7((void *)(unaff_EBP + -0x28),piVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  if (*(int **)(unaff_EBP + -0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EBP + -0x1c) + 8))();
  }
  piVar5 = *(int **)(unaff_EBP + -0x28);
  pcVar8 = Ordinal_6_exref;
  if (piVar5 != (int *)0x0) {
    pcVar6 = *(char **)(unaff_EBP + -0xbc);
    if (*(uint *)(unaff_EBP + -0xa8) < 0x10) {
      pcVar6 = (char *)(unaff_EBP + -0xbc);
    }
    ATL::CComBSTR::CComBSTR((CComBSTR *)(unaff_EBP + -0x1c),pcVar6);
    *(undefined1 *)(unaff_EBP + -4) = 0x12;
    iVar1 = (**(code **)(*piVar5 + 0x104))();
    FUN_10004622((void *)(unaff_EBP + -0x3c),iVar1);
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    pcVar8 = Ordinal_6_exref;
    Ordinal_6();
    if (*(short *)(unaff_EBP + -0x24) == -1) {
      iVar1 = (**(code **)(*piVar5 + 0x94))();
      FUN_10004622((void *)(unaff_EBP + -0x3c),iVar1);
      if (*(int *)(unaff_EBP + -0x30) == 0) {
        iVar1 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))();
        FUN_10004622((void *)(unaff_EBP + -0x3c),iVar1);
        if (*(int *)(unaff_EBP + -0x30) == 0) {
          puVar4 = (undefined4 *)FUN_10002411();
          *(undefined1 *)(unaff_EBP + -4) = 0x13;
          FUN_100023b4((void *)(unaff_EBP + -0x68),puVar4);
          *(undefined1 *)(unaff_EBP + -4) = 0xf;
          FID_conflict__Tidy((void *)(unaff_EBP + -0xa0),'\x01',0);
          *(undefined1 *)(unaff_EBP + -0x11) = 1;
        }
      }
      Ordinal_6();
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      iVar1 = Ordinal_2();
      *(int *)(unaff_EBP + 0xc) = iVar1;
      if (iVar1 == 0) {
        puStack_3cc = (undefined2 *)0x10004f7a;
        FUN_10001038(0x8007000e);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      puStack_3cc = *(undefined2 **)(unaff_EBP + 0xc);
      iVar1 = (**(code **)(*piVar5 + 0x94))(piVar5);
      FUN_10004622((void *)(unaff_EBP + -0x3c),iVar1);
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
      if (*(int *)(unaff_EBP + -0x30) == 0) {
        iVar1 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))();
        FUN_10004622((void *)(unaff_EBP + -0x3c),iVar1);
        if (*(int *)(unaff_EBP + -0x30) == 0) {
          puVar7 = FUN_10002411();
          *(undefined2 **)(unaff_EBP + 0xc) = puVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0x15;
          puStack_3cc = FUN_1000431a();
          *(undefined1 *)(unaff_EBP + -4) = 0x16;
          puVar4 = (undefined4 *)FUN_1000439c();
          *(undefined1 *)(unaff_EBP + -4) = 0x17;
          FUN_100023b4((void *)(unaff_EBP + -0x68),puVar4);
          *(undefined1 *)(unaff_EBP + -4) = 0x16;
          FID_conflict__Tidy((void *)(unaff_EBP + -0xa0),'\x01',0);
          *(undefined1 *)(unaff_EBP + -4) = 0x15;
          FID_conflict__Tidy((void *)(unaff_EBP + -0x1a8),'\x01',0);
          *(undefined1 *)(unaff_EBP + -4) = 0xf;
          FID_conflict__Tidy((void *)(unaff_EBP + -0xd8),'\x01',0);
        }
      }
      if (*(char *)(unaff_EBP + -0x11) == '\x01') {
        FUN_10002109(*(void **)(unaff_EBP + 8),(undefined4 *)(unaff_EBP + -0x68),0,0xffffffff);
        goto LAB_1000513c;
      }
    }
  }
  FUN_10003694();
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x18c),7);
  FUN_1000315f();
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x18c),0);
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x18c),6);
  FUN_1000315f();
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x18c),0);
  FUN_1000315f();
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x18c),0x110);
  puVar4 = (undefined4 *)FUN_100044e0();
  *(undefined1 *)(unaff_EBP + -4) = 0x19;
  FUN_100023b4(*(void **)(unaff_EBP + 8),puVar4);
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  FID_conflict__Tidy((void *)(unaff_EBP + -0xd8),'\x01',0);
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_10003487(unaff_EBP + -0x18c);
  piVar5 = *(int **)(unaff_EBP + -0x28);
LAB_1000513c:
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0xbc),true,0);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0xf4),true,0);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x48));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FID_conflict__Tidy((void *)(unaff_EBP + -0x84),'\x01',0);
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  if (*(int **)(unaff_EBP + -0x20) != (int *)0x0) {
    (**(code **)(**(int **)(unaff_EBP + -0x20) + 8))();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x1b;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))();
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  (*pcVar8)();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FID_conflict__Tidy((void *)(unaff_EBP + -0x68),'\x01',0);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: Catch@100051d8 at 100051d8

undefined4 Catch_100051d8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100051c4;
}



// Function: FUN_100051e2 at 100051e2

undefined4 FUN_100051e2(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0x80004003;
  }
  else {
    iVar2 = Ordinal_2(L"//XML_RESOURCE//RESOURCE//STRING[@ID=101]");
    *(int *)(unaff_EBP + 0xc) = iVar2;
    if (iVar2 == 0) {
      FUN_10001038(0x8007000e);
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_10004cbe();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    piVar3 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    iVar2 = *piVar3;
    *piVar3 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x30),'\x01',0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: Catch@10005297 at 10005297

undefined4 Catch_10005297(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10005283;
}



// Function: FUN_100052a8 at 100052a8

undefined4 FUN_100052a8(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar1 = *(int **)(unaff_EBP + 0xc);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0x80004003;
  }
  else {
    iVar2 = Ordinal_2(L"//XML_RESOURCE//RESOURCE//STRING[@ID=103]");
    *(int *)(unaff_EBP + 0xc) = iVar2;
    if (iVar2 == 0) {
      FUN_10001038(0x8007000e);
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_10004cbe();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    piVar3 = FUN_100015b8();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    iVar2 = *piVar3;
    *piVar3 = 0;
    *piVar1 = iVar2;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FID_conflict__Tidy((void *)(unaff_EBP + -0x30),'\x01',0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: Catch@1000535d at 1000535d

undefined4 Catch_1000535d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10005349;
}



// Function: FUN_1000536e at 1000536e

bool __cdecl FUN_1000536e(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 10005388

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



// Function: AtlCoTaskMemCAlloc at 100053aa

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



// Function: FUN_100053d7 at 100053d7

LPVOID __cdecl FUN_100053d7(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10005407 at 10005407

bool __cdecl FUN_10005407(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_10005434 at 10005434

undefined4 * FUN_10005434(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_10003668();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = ATL::CComObject<class_CVersionProvider>::vftable;
  extraout_ECX[1] = ATL::CComObject<class_CVersionProvider>::vftable;
  (**(code **)(*DAT_10011820 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_1000547b at 1000547b

undefined4 FUN_1000547b(undefined4 param_1,undefined4 *param_2)

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



// Function: AtlCrtErrorCheck at 10005498

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
    if (param_1 == 0x16) goto LAB_100054c0;
    if (param_1 == 0x22) goto LAB_100054c0;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_10001038(uVar1);
LAB_100054c0:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_100054d0 at 100054d0

void __cdecl FUN_100054d0(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_100054f0 at 100054f0

void __cdecl FUN_100054f0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 1000550d

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



// Function: FUN_10005536 at 10005536

DWORD FUN_10005536(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_1000554b at 1000554b

uint __cdecl FUN_1000554b(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: AtlComQIPtrAssign at 10005561

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



// Function: Attach at 10005598

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



// Function: FID_conflict:RegCreateKeyExW at 100055b7

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
                    /* WARNING: Could not recover jumptable at 0x1000560c. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 1000561a

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
                    /* WARNING: Could not recover jumptable at 0x1000565d. Too many branches */
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



// Function: InlineIsEqualUnknown at 1000566c

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



// Function: FUN_1000569a at 1000569a

undefined4 __fastcall FUN_1000569a(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1000569e at 1000569e

void __cdecl FUN_1000569e(short *param_1,int param_2,short *param_3)

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



// Function: FUN_100056ec at 100056ec

int __fastcall FUN_100056ec(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 10005703

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10011ad4 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10011ad0 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10011ad4 = '\x01';
    }
    if (DAT_10011ad0 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10011ad0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Create at 10005773

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



// Function: SetStringValue at 100057db

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



// Function: FUN_10005812 at 10005812

LSTATUS __thiscall FUN_10005812(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10005855 at 10005855

undefined4 __fastcall FUN_10005855(undefined4 *param_1)

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



// Function: FUN_10005875 at 10005875

undefined4 * __thiscall FUN_10005875(void *this,ulong param_1)

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



// Function: FUN_100058ab at 100058ab

void __fastcall FUN_100058ab(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100058b5 at 100058b5

undefined4 __thiscall FUN_100058b5(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_100053d7(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_100054d0((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10005943 at 10005943

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10005943(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  uint uVar3;
  
  FUN_10009190();
  uVar3 = 0;
  if ((DAT_10011af8 & 1) == 0) {
    DAT_10011af8 = DAT_10011af8 | 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    DAT_10011adc = 8;
    _DAT_10011ae4 = 0x4008;
    _DAT_10011aec = 0x13;
    DAT_10011ad8 = &DAT_1000b4e4;
    DAT_10011ae0 = &DAT_1000b4e0;
    _DAT_10011ae8 = &DAT_1000b4dc;
    _DAT_10011af0 = &DAT_1000b4d8;
    _DAT_10011af4 = 0x11;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  do {
    iVar1 = lstrcmpiW(*(LPCWSTR *)(unaff_EBP + 8),(LPCWSTR)(&DAT_10011ad8)[uVar3 * 2]);
    if (iVar1 == 0) {
      **(undefined2 **)(unaff_EBP + 0xc) = (&DAT_10011adc)[uVar3 * 4];
      uVar2 = 1;
      goto LAB_100059d1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  uVar2 = 0;
LAB_100059d1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_100059f1 at 100059f1

int __cdecl FUN_100059f1(ushort param_1)

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



// Function: FUN_10005a27 at 10005a27

undefined4 __cdecl FUN_10005a27(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1000baf8)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1000bafc)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10005a55 at 10005a55

LPCWSTR __cdecl FUN_10005a55(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10005a82 at 10005a82

undefined4 FUN_10005a82(ushort param_1)

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



// Function: FUN_10005aa8 at 10005aa8

void __fastcall FUN_10005aa8(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10005a82(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_10005aca at 10005aca

undefined4 __thiscall FUN_10005aca(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10005aa8((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10005855((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10005a82(*pWVar2);
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



// Function: FUN_10005be0 at 10005be0

undefined4 FUN_10005be0(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1000b508;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1000b538);
  return 1;
}



// Function: FUN_10005c0f at 10005c0f

bool FUN_10005c0f(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10005c44 at 10005c44

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int __thiscall FUN_10005c44(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2004 [4094];
  undefined4 uStack_8;
  
  uStack_8 = 0x10005c51;
  if (*param_1 == 0x3d) {
    iVar1 = FUN_10005aca(this,param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    FUN_10005aa8((undefined4 *)this);
    iVar1 = FUN_10005aca(this,local_2004);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_10005aca(this,param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  return 0;
}



// Function: FUN_10005c95 at 10005c95

undefined4 FUN_10005c95(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1001181c;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10005cb4 at 10005cb4

undefined4 __thiscall FUN_10005cb4(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10011824 = *param_3;
    DAT_10011828 = param_3[1];
    DAT_1001182c = param_3[2];
    DAT_10011830 = param_3[3];
  }
  piVar2 = DAT_10011b34;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10011b34, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10011b34 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10011b34;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10011b38; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: AtlInternalQueryInterface at 10005d12

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
          if (pcVar1 == (code *)0x1) goto LAB_10005d46;
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
LAB_10005d46:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10005db3 at 10005db3

void FUN_10005db3(int param_1)

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



// Function: FUN_10005dfc at 10005dfc

void FUN_10005dfc(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0xffffffff;
  extraout_ECX[1] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10005e2a at 10005e2a

void __fastcall FUN_10005e2a(undefined4 *param_1)

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



// Function: FUN_10005e57 at 10005e57

int __thiscall FUN_10005e57(void *this,undefined4 *param_1)

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



// Function: FUN_10005e8e at 10005e8e

void __fastcall FUN_10005e8e(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10005e98 at 10005e98

void __thiscall FUN_10005e98(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_10001038(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10005ebd

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_10001038(lVar1);
  }
  return local_8;
}



// Function: DllCanUnloadNow at 10005ee2

HRESULT DllCanUnloadNow(void)

{
                    /* 0x5ee2  1  DllCanUnloadNow */
  return (uint)(DAT_10011b04 != 0);
}



// Function: FUN_10005eee at 10005eee

void __fastcall FUN_10005eee(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10005f03 at 10005f03

void FUN_10005f03(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = ATL::CComObject<class_CVersionProvider>::vftable;
  extraout_ECX[1] = ATL::CComObject<class_CVersionProvider>::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0xc0000001;
  (**(code **)(*DAT_10011820 + 8))();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10002f97();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10005f4f at 10005f4f

void FUN_10005f4f(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: Release at 10005f63

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return LVar1;
}



// Function: QueryInterface at 10005f90

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000ba54,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10005faa at 10005faa

void * __thiscall FUN_10005faa(void *this,byte param_1)

{
  FUN_10005f03();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10005fc9 at 10005fc9

void FUN_10005fc9(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10005fd3 at 10005fd3

void FUN_10005fd3(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_10005fdd at 10005fdd

void FUN_10005fdd(int param_1)

{
  FUN_10005f4f(param_1 + -4);
  return;
}



// Function: FUN_10005fe7 at 10005fe7

int __fastcall FUN_10005fe7(int param_1)

{
  long lVar1;
  
  FUN_100056ec(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10011820 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10011810 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10006028 at 10006028

void __fastcall FUN_10006028(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10005db3((int)piVar1);
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



// Function: FUN_10006061 at 10006061

void __fastcall FUN_10006061(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10005db3((int)piVar1);
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



// Function: FUN_10006066 at 10006066

void FUN_10006066(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10006028(extraout_ECX);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10006089 at 10006089

int FUN_10006089(void)

{
  int iVar1;
  LSTATUS LVar2;
  undefined4 *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = Open((void *)(unaff_EBP + -0x1c),(HKEY)*this,*(LPCWSTR *)(unaff_EBP + 8),this[1] | 0x2001f
              );
  if (iVar1 == 0) {
    do {
      *(undefined4 *)(unaff_EBP + -0x10) = 0x100;
      LVar2 = RegEnumKeyExW(*(HKEY *)(unaff_EBP + -0x1c),0,(LPWSTR)(unaff_EBP + -0x224),
                            (LPDWORD)(unaff_EBP + -0x10),(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            (PFILETIME)(unaff_EBP + -0x24));
      if (LVar2 != 0) {
        ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
        iVar1 = DeleteSubKey(this,*(LPCWSTR *)(unaff_EBP + 8));
        break;
      }
      iVar1 = FUN_10006089();
    } while (iVar1 == 0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
  }
  else {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}



// Function: FUN_10006149 at 10006149

undefined4 __fastcall FUN_10006149(int *param_1)

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
LAB_1000618e:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_1000618e;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10005e2a(param_1);
  return 0;
}



// Function: FUN_100061a0 at 100061a0

undefined4 FUN_100061a0(void)

{
  undefined4 uVar1;
  int iVar2;
  void *this;
  int unaff_EBP;
  
  FUN_10009190();
  uVar1 = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar2 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 8));
    uVar1 = FUN_100058b5(this,*(void **)(unaff_EBP + 8),iVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100011d5((int *)(unaff_EBP + -0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}



// Function: FUN_100061ee at 100061ee

void FUN_100061ee(int param_1)

{
  FUN_10006149((int *)(param_1 + 4));
  return;
}



// Function: FUN_10006200 at 10006200

DWORD FUN_10006200(void)

{
  uint uVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  LPCWSTR lpsz;
  uint uVar4;
  int iVar5;
  errno_t eVar6;
  WCHAR WVar7;
  int unaff_EBP;
  LPCWSTR pWVar8;
  LPCWSTR pWVar9;
  
  FUN_10009190();
  if ((*(undefined4 **)(unaff_EBP + 0x10) == (undefined4 *)0x0) ||
     (puVar2 = *(undefined4 **)(unaff_EBP + 0x14), puVar2 == (undefined4 *)0x0)) {
    DVar3 = 0x80004003;
    goto LAB_100063a2;
  }
  **(undefined4 **)(unaff_EBP + 0x10) = 0;
  *puVar2 = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DVar3 = GetModuleFileNameW(*(HMODULE *)(unaff_EBP + 8),(LPWSTR)(unaff_EBP + -0x238),0x104);
  if (DVar3 == 0) {
    DVar3 = FUN_10005536();
  }
  else if (DVar3 == 0x104) {
    DVar3 = 0x8007007a;
  }
  else {
    lpsz = (LPCWSTR)(unaff_EBP + -0x238);
    if (*(short *)(unaff_EBP + -0x238) == 0) {
LAB_100062b4:
      *(LPCWSTR *)(unaff_EBP + 8) = lpsz;
    }
    else {
      WVar7 = *(WCHAR *)(unaff_EBP + -0x238);
      pWVar8 = (LPCWSTR)0x0;
      do {
        pWVar9 = lpsz;
        if ((WVar7 != L'.') && (pWVar9 = pWVar8, WVar7 == L'\\')) {
          pWVar9 = (LPCWSTR)0x0;
        }
        lpsz = CharNextW(lpsz);
        WVar7 = *lpsz;
        pWVar8 = pWVar9;
      } while (WVar7 != L'\0');
      if (pWVar9 == (LPCWSTR)0x0) goto LAB_100062b4;
      *(LPCWSTR *)(unaff_EBP + 8) = pWVar9;
    }
    if (*(int *)(unaff_EBP + 0xc) == 0) {
LAB_10006301:
      DVar3 = Ordinal_161(unaff_EBP + -0x238,puVar2);
      if ((int)DVar3 < 0) {
        *(undefined4 *)(unaff_EBP + -0x1c) = 0x74002e;
        iVar5 = *(int *)(unaff_EBP + 8) - (unaff_EBP + -0x238) >> 1;
        *(undefined4 *)(unaff_EBP + -0x18) = 0x62006c;
        *(undefined2 *)(unaff_EBP + -0x14) = 0;
        if (0x104 < iVar5 + 5U) goto LAB_10006393;
        eVar6 = wcscpy_s(*(wchar_t **)(unaff_EBP + 8),0x10e - iVar5,(wchar_t *)(unaff_EBP + -0x1c));
        ATL::AtlCrtErrorCheck(eVar6);
        DVar3 = Ordinal_161(unaff_EBP + -0x238,*(undefined4 *)(unaff_EBP + 0x14));
        if ((int)DVar3 < 0) goto LAB_10006258;
      }
      iVar5 = Ordinal_2(unaff_EBP + -0x238);
      **(int **)(unaff_EBP + 0x10) = iVar5;
      if (iVar5 == 0) {
        DVar3 = 0x8007000e;
      }
    }
    else {
      uVar4 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 0xc));
      uVar1 = uVar4 + DVar3;
      if (((DVar3 <= uVar1) && (uVar4 <= uVar1)) && (uVar1 < 0x10e)) {
        FUN_100054f0((wchar_t *)(unaff_EBP + -0x238 + DVar3 * 2),0x10e - DVar3,
                     *(wchar_t **)(unaff_EBP + 0xc));
        goto LAB_10006301;
      }
LAB_10006393:
      DVar3 = 0x80004005;
    }
  }
LAB_10006258:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100011d5((int *)(unaff_EBP + -0x10));
LAB_100063a2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar3;
}



// Function: FUN_100063b3 at 100063b3

void FUN_100063b3(void)

{
  int *piVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = (int *)*extraout_ECX;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,extraout_ECX);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100063dd at 100063dd

void __fastcall FUN_100063dd(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10011b34;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10011b34, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10011b38; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10006028(param_1);
  return;
}



// Function: FUN_1000642f at 1000642f

undefined4 FUN_1000642f(void)

{
  int *piVar1;
  wchar_t *pwVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  int extraout_ECX;
  uint uVar7;
  int unaff_EBP;
  CComBSTR *this;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,unaff_EBP + -0x20);
  if (-1 < iVar3) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    uVar4 = (uint)*(ushort *)(*(int *)(unaff_EBP + -0x20) + 0x2c);
    *(uint *)(extraout_ECX + 0x18) = uVar4;
    *(undefined4 *)(extraout_ECX + 0x14) = 0;
    if (uVar4 != 0) {
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar4 = *(uint *)(extraout_ECX + 0x18);
      uVar7 = -(uint)((int)((ulonglong)uVar4 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar4 * 0xc);
      puVar5 = (uint *)FUN_1000911a(-(uint)(0xfffffffb < uVar7) | uVar7 + 4);
      *(uint **)(unaff_EBP + -0x14) = puVar5;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (puVar5 == (uint *)0x0) {
        puVar5 = (uint *)0x0;
      }
      else {
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
        _eh_vector_constructor_iterator_(puVar5,0xc,uVar4,FUN_10005dfc,FUN_10001146);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(uint **)(unaff_EBP + -0x18) = puVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uVar6 = FUN_100064e6();
      return uVar6;
    }
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (0 < *(int *)(extraout_ECX + 0x18)) {
      this = *(CComBSTR **)(unaff_EBP + -0x18);
      do {
        iVar3 = (**(code **)(*piVar1 + 0x14))
                          (piVar1,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x1c);
        if (-1 < iVar3) {
          *(undefined4 *)(unaff_EBP + 8) = 0;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          iVar3 = (**(code **)(*piVar1 + 0x30))
                            (piVar1,**(undefined4 **)(unaff_EBP + -0x1c),unaff_EBP + 8,0,0,0);
          if (-1 < iVar3) {
            pwVar2 = *(wchar_t **)(unaff_EBP + 8);
            *(undefined4 *)(unaff_EBP + 8) = 0;
            ATL::CComBSTR::Attach(this,pwVar2);
            uVar6 = Ordinal_7(*(undefined4 *)this);
            *(undefined4 *)(this + 4) = uVar6;
            *(undefined4 *)(this + 8) = **(undefined4 **)(unaff_EBP + -0x1c);
          }
          (**(code **)(*piVar1 + 0x50))(piVar1,*(undefined4 *)(unaff_EBP + -0x1c));
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        this = this + 0xc;
      } while (*(int *)(unaff_EBP + -0x14) < *(int *)(extraout_ECX + 0x18));
    }
    *(undefined4 *)(extraout_ECX + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
    (**(code **)(*piVar1 + 0x4c))(piVar1,*(undefined4 *)(unaff_EBP + -0x20));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: Catch@100064d6 at 100064d6

undefined * Catch_100064d6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100064e0;
}



// Function: FUN_100064e6 at 100064e6

undefined4 FUN_100064e6(void)

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
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_100065a7 at 100065a7

void FUN_100065a7(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      FUN_1000148f();
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_100065df at 100065df

void __fastcall FUN_100065df(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_100065ef at 100065ef

void __fastcall FUN_100065ef(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10005e8e(param_1);
    return;
  }
  return;
}



// Function: FUN_100065fc at 100065fc

void FUN_100065fc(void)

{
  undefined4 *puVar1;
  int *extraout_ECX;
  int iVar2;
  int unaff_EBP;
  
  FUN_10009190();
  iVar2 = *(int *)(unaff_EBP + 8) * 4;
  puVar1 = (undefined4 *)(*extraout_ECX + iVar2);
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 **)(unaff_EBP + -0x14) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = **(undefined4 **)(unaff_EBP + 0xc);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  puVar1 = (undefined4 *)(extraout_ECX[1] + iVar2);
  *(undefined4 **)(unaff_EBP + 0xc) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = **(undefined4 **)(unaff_EBP + 0x10);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10006658 at 10006658

void __fastcall FUN_10006658(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000666f at 1000666f

undefined1 FUN_1000666f(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined1 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  if (*extraout_ECX == 0) {
    if (*(int *)(unaff_EBP + 8) == 0) {
      uVar3 = 1;
      goto LAB_100066f5;
    }
  }
  else {
    puVar1 = *(undefined4 **)(unaff_EBP + 8);
    if (puVar1 != (undefined4 *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      (*(code *)**(undefined4 **)*extraout_ECX)
                ((undefined4 *)*extraout_ECX,&DAT_1000bccc,unaff_EBP + -0x14);
      (**(code **)*puVar1)(puVar1,&DAT_1000bccc,unaff_EBP + -0x10);
      *(bool *)(unaff_EBP + 0xb) = *(int *)(unaff_EBP + -0x14) == *(int *)(unaff_EBP + -0x10);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      piVar2 = *(int **)(unaff_EBP + -0x10);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      piVar2 = *(int **)(unaff_EBP + -0x14);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      uVar3 = *(undefined1 *)(unaff_EBP + 0xb);
      goto LAB_100066f5;
    }
  }
  uVar3 = 0;
LAB_100066f5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_10006704 at 10006704

undefined4 FUN_10006704(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10005cb4(&DAT_10011afc,(int *)&PTR_DAT_100113f8,param_1,(undefined4 *)&DAT_1000b99c);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_100063dd(0x10011afc);
  }
  return 1;
}



// Function: FUN_10006746 at 10006746

int FUN_10006746(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (*(undefined4 **)(unaff_EBP + 0x10) == (undefined4 *)0x0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return -0x7fffbffd;
  }
  **(undefined4 **)(unaff_EBP + 0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8007000e;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pvVar1 = operator_new(0x28);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_10005434();
  }
  *(undefined4 **)(unaff_EBP + -0x14) = puVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar3 = FUN_100067b1();
  return iVar3;
}



// Function: Catch@100067a1 at 100067a1

undefined * Catch_100067a1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100067ab;
}



// Function: FUN_100067b1 at 100067b1

int FUN_100067b1(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 2;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10005eee((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if (unaff_EBX == 0) {
      unaff_EBX = (**(code **)*unaff_ESI)();
      if (unaff_EBX == 0) goto LAB_100067f3;
    }
    (**(code **)(*unaff_ESI + 0x10))(1);
  }
LAB_100067f3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EBX;
}



// Function: FUN_10006806 at 10006806

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_10006806(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_10005fe7((int)extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = ATL::CComModule::vftable;
  _DAT_10011834 = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_10006842 at 10006842

void __fastcall FUN_10006842(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000684d at 1000684d

void __fastcall FUN_1000684d(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10006858 at 10006858

HRESULT __thiscall FUN_10006858(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1000bf20,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000bd08,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_100068a4 at 100068a4

undefined4 FUN_100068a4(void)

{
  return 0x80004005;
}



// Function: FUN_100068ac at 100068ac

void FUN_100068ac(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_1000b7b8);
  return;
}



// Function: FUN_100068c6 at 100068c6

undefined4 * FUN_100068c6(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = ATL::CComModule::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10006028((int)extraout_ECX);
  if ((*(byte *)(unaff_EBP + 8) & 1) != 0) {
    operator_delete(extraout_ECX);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_10006904 at 10006904

void FUN_10006904(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_10006149(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10005e2a(*(undefined4 **)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10006933 at 10006933

void FUN_10006933(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = ATL::CRegObject::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_10006149(extraout_ECX + 1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10006904();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000696e at 1000696e

undefined4 FUN_1000696e(void)

{
  return 0x80004001;
}



// Function: FUN_10006976 at 10006976

undefined4 FUN_10006976(void)

{
  return 1;
}



// Function: FUN_1000697c at 1000697c

undefined4 FUN_1000697c(void)

{
  return 0;
}



// Function: FUN_10006981 at 10006981

void * __thiscall FUN_10006981(void *this,byte param_1)

{
  FUN_10006933();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100069a0 at 100069a0

undefined4 __fastcall FUN_100069a0(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10005e57((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_100069e1 at 100069e1

undefined4 FUN_100069e1(void)

{
  int *piVar1;
  WCHAR WVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  LPWSTR pWVar7;
  LPCWSTR pWVar8;
  rsize_t _MaxCount;
  errno_t eVar9;
  LPCWSTR pWVar10;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  pWVar8 = *(LPCWSTR *)(unaff_EBP + 8);
  if ((pWVar8 == (LPCWSTR)0x0) || (*(undefined4 **)(unaff_EBP + 0xc) == (undefined4 *)0x0)) {
    uVar5 = 0x80004003;
  }
  else {
    **(undefined4 **)(unaff_EBP + 0xc) = 0;
    iVar4 = lstrlenW(pWVar8);
    FUN_10005875((void *)(unaff_EBP + -0x24),iVar4 * 2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + -0x1c) == 0) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
      uVar5 = 0x8007000e;
    }
    else {
      *extraout_ECX = (int)pWVar8;
      *(undefined1 *)(unaff_EBP + -0xe) = 0;
      iVar4 = FUN_10005c95((undefined1 *)(unaff_EBP + -0xe));
      *(int *)(unaff_EBP + -0x14) = iVar4;
      if (-1 < iVar4) {
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        *(undefined1 *)(unaff_EBP + 0xb) = 0;
        WVar2 = *pWVar8;
        while (WVar2 != L'\0') {
          if (*(char *)(unaff_EBP + -0xe) == '\x01') {
            if (((*(int *)(unaff_EBP + -0x18) != 0) ||
                (pwVar6 = wcsstr((wchar_t *)*extraout_ECX,L"HKCR"), pwVar6 == (wchar_t *)0x0)) ||
               (pwVar6 != (LPCWSTR)*extraout_ECX)) {
LAB_10006ad7:
              if (*(short *)*extraout_ECX == 0x27) {
                if (*(char *)(unaff_EBP + 0xb) == '\0') {
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                  goto LAB_10006b4b;
                }
                iVar4 = FUN_10005855(extraout_ECX);
                if (iVar4 == 0) {
                  pWVar7 = CharNextW((LPCWSTR)*extraout_ECX);
                  *extraout_ECX = (int)pWVar7;
                  iVar4 = FUN_100058b5((void *)(unaff_EBP + -0x24),pWVar7,1);
                  if (iVar4 == 0) goto LAB_10006b71;
                  goto LAB_10006b13;
                }
                *(undefined1 *)(unaff_EBP + 0xb) = 0;
              }
              else {
LAB_10006b13:
                if (*(char *)(unaff_EBP + 0xb) != '\0') goto LAB_10006b4b;
              }
              sVar3 = *(short *)*extraout_ECX;
              if (sVar3 == 0x7b) {
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
              }
              if (sVar3 == 0x7d) {
                piVar1 = (int *)(unaff_EBP + -0x18);
                *piVar1 = *piVar1 + -1;
                if ((*piVar1 == 0) && (*(char *)(unaff_EBP + -0xd) == '\x01')) {
                  iVar4 = FUN_100061a0();
                  if (iVar4 == 0) goto LAB_10006b71;
                  *(undefined1 *)(unaff_EBP + -0xd) = 0;
                }
              }
              goto LAB_10006b4b;
            }
            pWVar7 = CharNextW((LPCWSTR)*extraout_ECX);
            *extraout_ECX = (int)pWVar7;
            pWVar7 = CharNextW(pWVar7);
            *extraout_ECX = (int)pWVar7;
            pWVar7 = CharNextW(pWVar7);
            *extraout_ECX = (int)pWVar7;
            pWVar7 = CharNextW(pWVar7);
            *extraout_ECX = (int)pWVar7;
            iVar4 = FUN_100061a0();
            if (iVar4 != 0) {
              *(undefined1 *)(unaff_EBP + -0xd) = 1;
              goto LAB_10006ad7;
            }
LAB_10006b71:
            *(undefined4 *)(unaff_EBP + -0x14) = 0x8007000e;
            goto LAB_10006a52;
          }
LAB_10006b4b:
          pWVar8 = (LPCWSTR)*extraout_ECX;
          if (*pWVar8 == L'%') {
            pWVar7 = CharNextW(pWVar8);
            *extraout_ECX = (int)pWVar7;
            if (*pWVar7 != L'%') {
              pWVar8 = FUN_10005a55(pWVar7,L'%');
              if (pWVar8 != (LPCWSTR)0x0) {
                _MaxCount = (int)pWVar8 - *extraout_ECX >> 1;
                if (0x1f < (int)_MaxCount) {
                  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
                  goto LAB_10006a52;
                }
                eVar9 = wcsncpy_s((wchar_t *)(unaff_EBP + -100),0x20,(wchar_t *)*extraout_ECX,
                                  _MaxCount);
                ATL::AtlCrtErrorCheck(eVar9);
                iVar4 = FUN_100069a0(extraout_ECX[1]);
                if (iVar4 != 0) {
                  iVar4 = FUN_100061a0();
                  if (iVar4 == 0) goto LAB_10006b71;
                  pWVar10 = (LPCWSTR)*extraout_ECX;
                  while (pWVar10 != pWVar8) {
                    pWVar10 = CharNextW((LPCWSTR)*extraout_ECX);
                    *extraout_ECX = (int)pWVar10;
                  }
                  goto LAB_10006be4;
                }
              }
              *(undefined4 *)(unaff_EBP + -0x14) = 0x80020009;
              goto LAB_10006a52;
            }
            iVar4 = FUN_100058b5((void *)(unaff_EBP + -0x24),pWVar7,1);
            if (iVar4 == 0) goto LAB_10006b71;
          }
          else {
            iVar4 = FUN_100058b5((void *)(unaff_EBP + -0x24),pWVar8,1);
            if (iVar4 == 0) {
              *(undefined4 *)(unaff_EBP + -0x14) = 0x8007000e;
              break;
            }
          }
LAB_10006be4:
          pWVar7 = CharNextW((LPCWSTR)*extraout_ECX);
          *extraout_ECX = (int)pWVar7;
          WVar2 = *pWVar7;
        }
        if (-1 < *(int *)(unaff_EBP + -0x14)) {
          uVar5 = *(undefined4 *)(unaff_EBP + -0x1c);
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          *(undefined4 *)(unaff_EBP + -0x24) = 0;
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          **(undefined4 **)(unaff_EBP + 0xc) = uVar5;
        }
      }
LAB_10006a52:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      CoTaskMemFree(*(LPVOID *)(unaff_EBP + -0x1c));
      uVar5 = *(undefined4 *)(unaff_EBP + -0x14);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}



// Function: FUN_10006c58 at 10006c58

int FUN_10006c58(void)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  errno_t eVar3;
  LSTATUS LVar4;
  int iVar5;
  int *piVar6;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  piVar6 = *(int **)(unaff_EBP + 0xc);
  if (((piVar6 != (int *)0x0) &&
      (iVar5 = _InlineIsEqualGUID(*(int **)(unaff_EBP + 8),(int *)&DAT_1000bf10), iVar5 == 0)) &&
     (HVar2 = CoCreateInstance((IID *)&DAT_1000bf30,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000be04,
                               (LPVOID *)(unaff_EBP + -0x10)), -1 < HVar2)) {
    *(int **)(unaff_EBP + 0xc) = piVar6;
    if (*piVar6 != 0) {
      while( true ) {
        puVar1 = (undefined4 *)piVar6[1];
        *(undefined4 *)(unaff_EBP + -0x38) = *puVar1;
        *(undefined4 *)(unaff_EBP + -0x34) = puVar1[1];
        *(undefined4 *)(unaff_EBP + -0x30) = puVar1[2];
        *(undefined4 *)(unaff_EBP + -0x2c) = puVar1[3];
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          iVar5 = **(int **)(unaff_EBP + -0x10);
          if (*piVar6 == 1) {
            (**(code **)(iVar5 + 0x18))();
          }
          else {
            (**(code **)(iVar5 + 0x20))
                      (*(int **)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 8),1,
                       unaff_EBP + -0x38);
          }
        }
        else {
          iVar5 = **(int **)(unaff_EBP + -0x10);
          if (*piVar6 == 1) {
            iVar5 = (**(code **)(iVar5 + 0x14))();
          }
          else {
            iVar5 = (**(code **)(iVar5 + 0x1c))(*(int **)(unaff_EBP + -0x10));
          }
          if (iVar5 < 0) {
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            piVar6 = *(int **)(unaff_EBP + -0x10);
            if (piVar6 != (int *)0x0) {
              (**(code **)(*piVar6 + 8))(piVar6);
            }
            goto LAB_10006e86;
          }
        }
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 8;
        if (**(int **)(unaff_EBP + 0xc) == 0) break;
        piVar6 = *(int **)(unaff_EBP + 0xc);
      }
    }
    if (*(int *)(unaff_EBP + 0x10) == 0) {
      StringFromGUID2(*(GUID **)(unaff_EBP + 8),(LPOLESTR)(unaff_EBP + -0x1b8),0x40);
      *(undefined4 *)(unaff_EBP + 0xc) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      eVar3 = wcscpy_s((wchar_t *)(unaff_EBP + -0x138),0x80,L"CLSID\\");
      ATL::AtlCrtErrorCheck(eVar3);
      eVar3 = wcscat_s((wchar_t *)(unaff_EBP + -0x138),0x80,(wchar_t *)(unaff_EBP + -0x1b8));
      ATL::AtlCrtErrorCheck(eVar3);
      eVar3 = wcscat_s((wchar_t *)(unaff_EBP + -0x138),0x80,L"\\Required Categories");
      ATL::AtlCrtErrorCheck(eVar3);
      *(undefined4 *)(unaff_EBP + -0x28) = 0x80000000;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 8;
      *(undefined4 *)(unaff_EBP + 8) = 0;
      iVar5 = Open((void *)(unaff_EBP + -0x1c),(HKEY)0x80000000,(LPCWSTR)(unaff_EBP + -0x138),
                   0x20019);
      if (iVar5 == 0) {
        LVar4 = RegQueryInfoKeyW(*(HKEY *)(unaff_EBP + -0x1c),(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)(unaff_EBP + 8),(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
        *(LSTATUS *)(unaff_EBP + 0x10) = LVar4;
        ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
        if ((*(int *)(unaff_EBP + 0x10) == 0) && (*(int *)(unaff_EBP + 8) == 0)) {
          DeleteSubKey((void *)(unaff_EBP + -0x28),(LPCWSTR)(unaff_EBP + -0x138));
        }
      }
      eVar3 = wcscpy_s((wchar_t *)(unaff_EBP + -0x138),0x80,L"CLSID\\");
      ATL::AtlCrtErrorCheck(eVar3);
      eVar3 = wcscat_s((wchar_t *)(unaff_EBP + -0x138),0x80,(wchar_t *)(unaff_EBP + -0x1b8));
      ATL::AtlCrtErrorCheck(eVar3);
      eVar3 = wcscat_s((wchar_t *)(unaff_EBP + -0x138),0x80,L"\\Implemented Categories");
      ATL::AtlCrtErrorCheck(eVar3);
      iVar5 = Open((void *)(unaff_EBP + -0x1c),(HKEY)0x80000000,(LPCWSTR)(unaff_EBP + -0x138),
                   0x20019);
      if (iVar5 == 0) {
        LVar4 = RegQueryInfoKeyW(*(HKEY *)(unaff_EBP + -0x1c),(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)(unaff_EBP + 8),(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
        ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
        if ((LVar4 == 0) && (*(int *)(unaff_EBP + 8) == 0)) {
          DeleteSubKey((void *)(unaff_EBP + -0x28),(LPCWSTR)(unaff_EBP + -0x138));
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 7;
      ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
      *(undefined1 *)(unaff_EBP + -4) = 6;
      ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x28));
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_100011d5((int *)(unaff_EBP + 0xc));
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar6 = *(int **)(unaff_EBP + -0x10);
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 8))(piVar6);
  }
  iVar5 = 0;
LAB_10006e86:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar5;
}



// Function: FUN_10006f03 at 10006f03

DWORD FUN_10006f03(void)

{
  int iVar1;
  int *piVar2;
  DWORD DVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  DVar3 = FUN_10006200();
  if ((-1 < (int)DVar3) &&
     (DVar3 = (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x1c))
                        (*(int **)(unaff_EBP + -0x10),unaff_EBP + 8), -1 < (int)DVar3)) {
    *(undefined1 *)(unaff_EBP + 0xf) = 0;
    DVar3 = FUN_10005c95((undefined1 *)(unaff_EBP + 0xf));
    if (-1 < (int)DVar3) {
      if (((*(char *)(unaff_EBP + 0xf) != '\x01') ||
          (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
         (pFVar4 = GetProcAddress(hModule,"UnRegisterTypeLibForUser"), pFVar4 == (FARPROC)0x0)) {
        pFVar4 = Ordinal_186_exref;
      }
      iVar1 = *(int *)(unaff_EBP + 8);
      DVar3 = (*pFVar4)(iVar1,(uint)*(ushort *)(iVar1 + 0x18),(uint)*(ushort *)(iVar1 + 0x1a),
                        *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
      (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x30))
                (*(int **)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 8));
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  piVar2 = *(int **)(unaff_EBP + -0x10);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar3;
}



// Function: FUN_10006fdd at 10006fdd

DWORD FUN_10006fdd(void)

{
  WCHAR WVar1;
  int *piVar2;
  LPCWSTR lpsz;
  DWORD DVar3;
  int iVar4;
  rsize_t _MaxCount;
  errno_t eVar5;
  LPWSTR pWVar6;
  HMODULE hModule;
  FARPROC pFVar7;
  int unaff_EBP;
  int iVar8;
  LPCWSTR pWVar9;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  DVar3 = FUN_10006200();
  if (-1 < (int)DVar3) {
    iVar8 = 0;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    iVar4 = (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x24))
                      (*(int **)(unaff_EBP + -0x10),0xffffffff,0,0,0,unaff_EBP + 8);
    if ((-1 < iVar4) && (*(int *)(unaff_EBP + 8) != 0)) {
      _MaxCount = Ordinal_7(*(undefined4 *)(unaff_EBP + 8));
      eVar5 = wcsncpy_s((wchar_t *)(unaff_EBP + -0x21c),0x104,*(wchar_t **)(unaff_EBP + 8),_MaxCount
                       );
      ATL::AtlCrtErrorCheck(eVar5);
      pWVar9 = (LPCWSTR)(unaff_EBP + -0x21c);
      *(undefined2 *)(unaff_EBP + -0x16) = 0;
      WVar1 = *(WCHAR *)(unaff_EBP + -0x21c);
      lpsz = pWVar9;
      while (WVar1 != L'\0') {
        pWVar6 = CharNextW(lpsz);
        WVar1 = *lpsz;
        if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
          pWVar9 = pWVar6;
        }
        lpsz = pWVar6;
        WVar1 = *pWVar6;
      }
      *(undefined2 *)(unaff_EBP + -0x21c + ((int)pWVar9 - (unaff_EBP + -0x21c) >> 1) * 2) = 0;
      iVar8 = unaff_EBP + -0x21c;
    }
    *(undefined1 *)(unaff_EBP + 0xf) = 0;
    DVar3 = FUN_10005c95((undefined1 *)(unaff_EBP + 0xf));
    if ((int)DVar3 < 0) {
      *(undefined1 *)(unaff_EBP + -4) = 2;
      Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
      *(undefined1 *)(unaff_EBP + -4) = 0;
      piVar2 = *(int **)(unaff_EBP + -0x10);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
      goto LAB_1000715e;
    }
    if (((*(char *)(unaff_EBP + 0xf) != '\x01') ||
        (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
       (pFVar7 = GetProcAddress(hModule,"RegisterTypeLibForUser"), pFVar7 == (FARPROC)0x0)) {
      pFVar7 = Ordinal_163_exref;
    }
    DVar3 = (*pFVar7)(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14),iVar8);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  piVar2 = *(int **)(unaff_EBP + -0x10);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x14));
LAB_1000715e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar3;
}



// Function: FUN_1000716f at 1000716f

DWORD FUN_1000716f(DWORD param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  bool bVar3;
  undefined3 extraout_var;
  DWORD DVar4;
  int *piVar5;
  
  DVar2 = param_1;
  if (param_1 == 0) {
    param_1 = 0x80070057;
  }
  else {
    piVar5 = *(int **)(param_1 + 8);
    param_1 = 0;
    if (piVar5 < *(int **)(DVar2 + 0xc)) {
      do {
        puVar1 = (undefined4 *)*piVar5;
        if ((puVar1 != (undefined4 *)0x0) &&
           ((param_3 == (void *)0x0 ||
            (bVar3 = FUN_1000536e(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          DVar4 = (*(code *)puVar1[1])(1);
          if ((int)DVar4 < 0) {
            return DVar4;
          }
          (*(code *)puVar1[7])(1);
          param_1 = FUN_10006c58();
          if ((int)param_1 < 0) {
            return param_1;
          }
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 < *(int **)(DVar2 + 0xc));
      if ((int)param_1 < 0) {
        return param_1;
      }
    }
    if (param_2 != 0) {
      param_1 = FUN_10006fdd();
    }
  }
  return param_1;
}



// Function: FUN_100071f5 at 100071f5

DWORD FUN_100071f5(DWORD param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  bool bVar3;
  undefined3 extraout_var;
  DWORD DVar4;
  int *piVar5;
  
  DVar2 = param_1;
  if (param_1 == 0) {
    param_1 = 0x80070057;
  }
  else {
    param_1 = 0;
    piVar5 = *(int **)(DVar2 + 8);
    if (piVar5 < *(int **)(DVar2 + 0xc)) {
      do {
        puVar1 = (undefined4 *)*piVar5;
        if ((puVar1 != (undefined4 *)0x0) &&
           ((param_3 == (void *)0x0 ||
            (bVar3 = FUN_1000536e(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          (*(code *)puVar1[7])(0);
          DVar4 = FUN_10006c58();
          if ((int)DVar4 < 0) {
            return DVar4;
          }
          param_1 = (*(code *)puVar1[1])(0);
          if ((int)param_1 < 0) {
            return param_1;
          }
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 < *(int **)(DVar2 + 0xc));
      if ((int)param_1 < 0) {
        return param_1;
      }
    }
    if (param_2 != 0) {
      param_1 = FUN_10006f03();
    }
  }
  return param_1;
}



// Function: FUN_1000727c at 1000727c

undefined4 FUN_1000727c(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int unaff_EBP;
  int *piVar5;
  
  FUN_10009190();
  if (*(undefined4 **)(unaff_EBP + 0x14) == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    piVar1 = *(int **)(unaff_EBP + 8);
    **(undefined4 **)(unaff_EBP + 0x14) = 0;
    if (piVar1 == (int *)0x0) {
      uVar3 = 0x80070057;
    }
    else if (*piVar1 == 0) {
      uVar3 = 0x8000ffff;
    }
    else {
      piVar5 = (int *)piVar1[2];
      *(undefined4 *)(unaff_EBP + 8) = 0;
      for (; piVar5 < (int *)piVar1[3]; piVar5 = piVar5 + 1) {
        puVar2 = (undefined4 *)*piVar5;
        if (((puVar2 != (undefined4 *)0x0) && (puVar2[2] != 0)) &&
           (iVar4 = _InlineIsEqualGUID(*(int **)(unaff_EBP + 0xc),(int *)*puVar2), iVar4 != 0)) {
          piVar5 = puVar2 + 4;
          if (*piVar5 == 0) {
            lpCriticalSection = (LPCRITICAL_SECTION)(piVar1 + 4);
            *(LPCRITICAL_SECTION *)(unaff_EBP + -0x14) = lpCriticalSection;
            *(undefined1 *)(unaff_EBP + -0x10) = 0;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            EnterCriticalSection(lpCriticalSection);
            *(undefined4 *)(unaff_EBP + 8) = 0;
            iVar4 = *piVar5;
            *(undefined1 *)(unaff_EBP + -0x10) = 1;
            if (iVar4 == 0) {
              uVar3 = (*(code *)puVar2[2])(puVar2[3],&DAT_1000bccc,piVar5);
              *(undefined4 *)(unaff_EBP + 8) = uVar3;
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            LeaveCriticalSection(lpCriticalSection);
            iVar4 = *piVar5;
            *(undefined1 *)(unaff_EBP + -0x10) = 0;
            if (iVar4 != 0) goto LAB_1000733a;
          }
          else {
LAB_1000733a:
            uVar3 = (*(code *)**(undefined4 **)*piVar5)
                              ((undefined4 *)*piVar5,*(undefined4 *)(unaff_EBP + 0x10),
                               *(undefined4 *)(unaff_EBP + 0x14));
            *(undefined4 *)(unaff_EBP + 8) = uVar3;
          }
          if ((**(int **)(unaff_EBP + 0x14) != 0) || (*(int *)(unaff_EBP + 8) != 0))
          goto LAB_1000735f;
          break;
        }
      }
      *(undefined4 *)(unaff_EBP + 8) = 0x80040111;
LAB_1000735f:
      uVar3 = *(undefined4 *)(unaff_EBP + 8);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: FUN_10007373 at 10007373

undefined4 FUN_10007373(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  if (*(int *)(unaff_EBP + 8) == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x80070057;
  }
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pvVar1 = operator_new(0xc);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar2 = FUN_100073bf();
  return uVar2;
}



// Function: Catch@100073af at 100073af

undefined * Catch_100073af(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100073b9;
}



// Function: FUN_100073bf at 100073bf

undefined4 FUN_100073bf(void)

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
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_10007423 at 10007423

void FUN_10007423(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = ATL::CComClassFactory::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX + 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000298c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10007459 at 10007459

undefined4 FUN_10007459(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10007497 at 10007497

undefined4 FUN_10007497(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10011820 + 8))();
  }
  else {
    (**(code **)(*DAT_10011820 + 4))();
  }
  return 0;
}



// Function: FUN_100074b6 at 100074b6

void * __thiscall FUN_100074b6(void *this,byte param_1)

{
  FUN_10007423();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100074d5 at 100074d5

undefined4 __fastcall FUN_100074d5(undefined4 *param_1)

{
  void *pvVar1;
  
  pvVar1 = _recalloc((void *)*param_1,param_1[2] + 1,4);
  if (pvVar1 != (void *)0x0) {
    *param_1 = pvVar1;
    pvVar1 = _recalloc((void *)param_1[1],param_1[2] + 1,4);
    if (pvVar1 != (void *)0x0) {
      param_1[1] = pvVar1;
      FUN_100065fc();
      param_1[2] = param_1[2] + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 1000752c

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
    FUN_10005e98(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000755b

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
    FUN_10005e98(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000758a

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
    FUN_10005e98(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100075b9 at 100075b9

IUnknown * __thiscall FUN_100075b9(void *this,undefined4 *param_1)

{
  char cVar1;
  IUnknown *pIVar2;
  
  cVar1 = FUN_1000666f();
  if (cVar1 == '\0') {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1000be80);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  return pIVar2;
}



// Function: FUN_100075e6 at 100075e6

int FUN_100075e6(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = FUN_10006746();
  }
  else if (param_3 == (undefined4 *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    *param_3 = 0;
    iVar1 = -0x7ffbfef0;
  }
  return iVar1;
}



// Function: FUN_10007617 at 10007617

undefined4 * FUN_10007617(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_10002f56();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = ATL::CComClassFactory::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_1000764d at 1000764d

undefined4 FUN_1000764d(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  *(undefined4 *)(unaff_EBP + -0x30) = extraout_ECX;
  if ((*(int *)(unaff_EBP + 8) != 0) && (*(int *)(unaff_EBP + 0xc) != 0)) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    iVar3 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 8));
    uVar1 = iVar3 * 2 + 2;
    *(uint *)(unaff_EBP + -0x28) = uVar1;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    lVar2 = (ulonglong)uVar1 * 2;
    uVar4 = FUN_1000911a(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uVar4 = FUN_100076ba();
    return uVar4;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: Catch@100076ae at 100076ae

undefined * Catch_100076ae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100076b8;
}



// Function: FUN_100076ba at 100076ba

void FUN_100076ba(void)

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
  uVar4 = FUN_1000911a(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_1000770b();
  return;
}



// Function: Catch@100076fc at 100076fc

undefined * Catch_100076fc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10007709;
}



// Function: FUN_1000770b at 1000770b

bool FUN_1000770b(void)

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
    FUN_100054d0(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_100054d0(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_100074d5(*(undefined4 **)(unaff_EBP + -0x30));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_10007767;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_10007767:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_100077a8 at 100077a8

int FUN_100077a8(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_10009190();
  if ((*(int *)(unaff_EBP + 0xc) == 0) || (*(int *)(unaff_EBP + 0x10) == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar1 = FUN_1000764d();
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100011d5((int *)(unaff_EBP + -0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}



// Function: FUN_1000780a at 1000780a

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

uint FUN_1000780a(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *this;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffdedc;
  *(undefined4 **)(unaff_EBP + -0x1c) = this;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  uVar2 = FUN_10005aca(this,(undefined2 *)(unaff_EBP + -0x2124));
  if ((int)uVar2 < 0) goto LAB_10007b05;
  iVar3 = FUN_10005943();
  if (iVar3 == 0) {
    uVar2 = 0x80020009;
    goto LAB_10007b05;
  }
  FUN_10005aa8(this);
  uVar2 = FUN_10005aca(this,(undefined2 *)(unaff_EBP + -0x2124));
  if ((int)uVar2 < 0) goto LAB_10007b05;
  sVar1 = *(short *)(unaff_EBP + -0x14);
  if (sVar1 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue
                      (*(CRegKey **)(unaff_EBP + 8),*(wchar_t **)(unaff_EBP + 0xc),
                       (wchar_t *)(unaff_EBP + -0x2124),1);
LAB_10007ae7:
    if (uVar2 != 0) {
      uVar2 = FUN_1000554b(uVar2);
      goto LAB_10007b05;
    }
  }
  else {
    if (sVar1 == 0x11) {
      uVar2 = lstrlenW((LPCWSTR)(unaff_EBP + -0x2124));
      *(uint *)(unaff_EBP + -0x14) = uVar2;
      if ((uVar2 & 1) == 0) {
        *(int *)(unaff_EBP + -0x18) = (int)uVar2 / 2;
        *(undefined4 *)(unaff_EBP + -0x124) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 4;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        Allocate((void *)(unaff_EBP + -0x124),(int)uVar2 / 2);
        *(undefined4 *)(unaff_EBP + -4) = 4;
        uVar2 = FUN_10007a23();
        return uVar2;
      }
      uVar2 = 0x80004005;
      goto LAB_10007b05;
    }
    if (sVar1 == 0x13) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      Ordinal_277(unaff_EBP + -0x2124,0,0,unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x14);
      uVar2 = RegSetValueExW((HKEY)**(undefined4 **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),0,
                             4,(BYTE *)(unaff_EBP + -0x20),4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_100011d5((int *)(unaff_EBP + -0x18));
      goto LAB_10007ae7;
    }
    if (sVar1 == 0x4008) {
      iVar3 = lstrlenW((LPCWSTR)(unaff_EBP + -0x2124));
      *(undefined4 *)(unaff_EBP + -0x124) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      Allocate((void *)(unaff_EBP + -0x124),iVar3 + 2);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar2 = FUN_100078e3();
      return uVar2;
    }
  }
  uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x1c),*(undefined2 **)(unaff_EBP + 0x10));
  if (-1 < (int)uVar2) {
    uVar2 = 0;
  }
LAB_10007b05:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: Catch@100078d7 at 100078d7

undefined * Catch_100078d7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100078e1;
}



// Function: FUN_100078e3 at 100078e3

uint FUN_100078e3(void)

{
  WCHAR WVar1;
  LPWSTR lpsz;
  LPCWSTR lpsz_00;
  WCHAR *pWVar2;
  uint uVar3;
  int unaff_EBP;
  WCHAR *unaff_EDI;
  
  pWVar2 = *(WCHAR **)(unaff_EBP + -0x124);
  if (pWVar2 == unaff_EDI) {
    pWVar2 = (WCHAR *)0xe;
  }
  else {
    lpsz_00 = (LPCWSTR)(unaff_EBP + -0x2124);
    WVar1 = *(WCHAR *)(unaff_EBP + -0x2124);
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
    pWVar2 = (WCHAR *)FUN_10005812(*(void **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),
                                   *(LPCWSTR *)(unaff_EBP + -0x124));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x124) != unaff_EBP + -0x120) {
    FUN_10005e8e((undefined4 *)(unaff_EBP + -0x124));
  }
  if (pWVar2 == unaff_EDI) {
    uVar3 = FUN_10005aca(*(void **)(unaff_EBP + -0x1c),*(undefined2 **)(unaff_EBP + 0x10));
    if ((int)unaff_EDI <= (int)uVar3) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = FUN_1000554b((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}



// Function: Catch@10007a11 at 10007a11

undefined * Catch_10007a11(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10007a1e;
}



// Function: FUN_10007a23 at 10007a23

uint FUN_10007a23(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  size_t unaff_EBX;
  int unaff_EBP;
  uint unaff_EDI;
  
  if (*(uint *)(unaff_EBP + -0x124) == unaff_EDI) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x124) != unaff_EBP + -0x120) {
      FUN_10005e8e((undefined4 *)(unaff_EBP + -0x124));
    }
    uVar2 = 0x80004005;
  }
  else {
    memset(*(void **)(unaff_EBP + -0x124),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP + -0x14)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP + -0x124));
        iVar3 = FUN_100059f1(*(ushort *)(unaff_EBP + -0x2124 + unaff_EDI * 2));
        *pbVar1 = *pbVar1 | (char)iVar3 << (4U - (char)((unaff_EDI & 1) << 2) & 0x1f);
        unaff_EDI = unaff_EDI + 1;
      } while ((int)unaff_EDI < *(int *)(unaff_EBP + -0x14));
      unaff_EDI = 0;
    }
    uVar2 = RegSetValueExW((HKEY)**(undefined4 **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),
                           unaff_EDI,3,*(BYTE **)(unaff_EBP + -0x124),unaff_EBX);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(int *)(unaff_EBP + -0x124) != unaff_EBP + -0x120) {
      FUN_10005e8e((undefined4 *)(unaff_EBP + -0x124));
    }
    if (uVar2 == unaff_EDI) {
      uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x1c),*(undefined2 **)(unaff_EBP + 0x10));
      if ((int)unaff_EDI <= (int)uVar2) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = FUN_1000554b(uVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_10007b16 at 10007b16

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

uint FUN_10007b16(void)

{
  LPCWSTR lpString1;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  LPCWSTR pWVar5;
  uint uVar6;
  undefined4 uVar7;
  errno_t eVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  void *extraout_ECX;
  void *this;
  CRegKey *pCVar9;
  int unaff_EBP;
  
  FUN_10009190();
  *(void **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  lpString1 = *(LPCWSTR *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + 0x14);
  this = extraout_ECX;
LAB_10007b47:
  uVar2 = FUN_10005aca(this,lpString1);
  do {
    if ((int)uVar2 < 0) {
LAB_10007b57:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2c));
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar2;
    }
LAB_10007ed6:
    if (*lpString1 == L'}') goto LAB_10007b57;
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    iVar3 = lstrcmpiW(lpString1,L"Delete");
    *(uint *)(unaff_EBP + 8) = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(lpString1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),lpString1);
      if ((int)uVar2 < 0) goto LAB_10007b57;
      if (*(int *)(unaff_EBP + 0x10) == 0) goto LAB_10007c4c;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      pWVar5 = FUN_10005a55(lpString1,L'\\');
      if (pWVar5 != (LPCWSTR)0x0) {
        *(undefined1 *)(unaff_EBP + -4) = 0;
        ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
        goto LAB_10007fdd;
      }
      iVar3 = FUN_10005be0(lpString1);
      if (iVar3 != 0) {
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        FUN_10006089();
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      if (*(int *)(unaff_EBP + 8) == 0) {
        *(undefined1 *)(unaff_EBP + -4) = 0;
        ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c));
        goto LAB_10007c4c;
      }
      uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),lpString1);
      if ((-1 < (int)uVar2) &&
         (uVar2 = FUN_10005c44(*(void **)(unaff_EBP + -0x10),lpString1), -1 < (int)uVar2)) {
        *(undefined1 *)(unaff_EBP + -4) = 0;
        pCVar9 = (CRegKey *)(unaff_EBP + -0x1c);
        goto LAB_10007f88;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      pCVar9 = (CRegKey *)(unaff_EBP + -0x1c);
      goto LAB_10007ff5;
    }
LAB_10007c4c:
    iVar3 = lstrcmpiW(lpString1,L"NoRemove");
    if (iVar3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),lpString1);
      if ((int)uVar2 < 0) goto LAB_10007b57;
    }
    iVar3 = lstrcmpiW(lpString1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10005a55(lpString1,L'\\');
      if (pWVar5 != (LPCWSTR)0x0) goto LAB_10007fdd;
      if (*(int *)(unaff_EBP + 0x10) == 0) {
        if (*(int *)(unaff_EBP + 0x14) == 0) {
          uVar7 = Open((void *)(unaff_EBP + -0x2c),*(HKEY *)(unaff_EBP + 0xc),lpString1,0x20019);
          *(undefined4 *)(unaff_EBP + 8) = uVar7;
        }
        else {
          *(undefined4 *)(unaff_EBP + 8) = 2;
        }
        if (*(int *)(unaff_EBP + 8) != 0) {
          *(undefined4 *)(unaff_EBP + 0x14) = 1;
        }
        eVar8 = wcsncpy_s((wchar_t *)(unaff_EBP + -0x25c),0x104,lpString1,0xffffffff);
        ATL::AtlCrtErrorCheck(eVar8);
        uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),lpString1);
        if (((-1 < (int)uVar2) &&
            (uVar2 = FUN_10005c44(*(void **)(unaff_EBP + -0x10),lpString1), -1 < (int)uVar2)) &&
           (((*lpString1 != L'{' || (iVar3 = lstrlenW(lpString1), iVar3 != 1)) ||
            (((uVar2 = FUN_10007b16(), -1 < (int)uVar2 || (*(int *)(unaff_EBP + 0x14) != 0)) &&
             (uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),lpString1), -1 < (int)uVar2))))))
        break;
      }
      else {
        iVar3 = Open((void *)(unaff_EBP + -0x2c),*(HKEY *)(unaff_EBP + 0xc),lpString1,0x2001f);
        if (((iVar3 != 0) &&
            (iVar3 = Open((void *)(unaff_EBP + -0x2c),*(HKEY *)(unaff_EBP + 0xc),lpString1,0x20019),
            iVar3 != 0)) &&
           (uVar6 = Create((void *)(unaff_EBP + -0x2c),*(HKEY *)(unaff_EBP + 0xc),lpString1,
                           (LPWSTR)0x0,0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0),
           uVar6 != 0)) goto LAB_10008011;
        uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),lpString1);
        if ((-1 < (int)uVar2) && ((*lpString1 != L'=' || (uVar2 = FUN_1000780a(), -1 < (int)uVar2)))
           ) goto LAB_10007f8d;
      }
      goto LAB_10007b57;
    }
    uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),(undefined2 *)(unaff_EBP + -0x225c));
    if (((int)uVar2 < 0) ||
       (uVar2 = FUN_10005aca(*(void **)(unaff_EBP + -0x10),lpString1), (int)uVar2 < 0))
    goto LAB_10007b57;
    if (*lpString1 != L'=') {
LAB_10007fdd:
      uVar2 = 0x80020009;
      goto LAB_10007b57;
    }
    if (*(int *)(unaff_EBP + 0x10) != 0) {
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      uVar2 = FUN_1000780a();
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      if (-1 < (int)uVar2) {
        *(undefined1 *)(unaff_EBP + -4) = 0;
        pCVar9 = (CRegKey *)(unaff_EBP + -0x38);
        goto LAB_10007f88;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      pCVar9 = (CRegKey *)(unaff_EBP + -0x38);
      goto LAB_10007ff5;
    }
    if ((*(int *)(unaff_EBP + 0x14) == 0) && (*(int *)(unaff_EBP + -0x20) != 0)) {
      *(undefined4 *)(unaff_EBP + -0x50) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x48) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar2 = Open((void *)(unaff_EBP + -0x50),*(HKEY *)(unaff_EBP + 0xc),(LPCWSTR)0x0,0x20006);
      if ((uVar2 != 0) ||
         ((uVar2 = RegDeleteValueW(*(HKEY *)(unaff_EBP + -0x50),(LPCWSTR)(unaff_EBP + -0x225c)),
          uVar2 != 0 && (uVar2 != 2)))) {
        uVar2 = FUN_1000554b(uVar2);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        pCVar9 = (CRegKey *)(unaff_EBP + -0x50);
LAB_10007ff5:
        ATL::CRegKey::Close(pCVar9);
        goto LAB_10007b57;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x50));
    }
    uVar2 = FUN_10005c44(*(void **)(unaff_EBP + -0x10),lpString1);
  } while( true );
  iVar3 = *(int *)(unaff_EBP + -0x54);
  *(int *)(unaff_EBP + 0x14) = iVar3;
  if (*(int *)(unaff_EBP + 8) != 2) {
    if (*(int *)(unaff_EBP + 8) == 0) {
      if ((iVar3 != 0) &&
         (bVar1 = FUN_10005c0f(*(HKEY *)(unaff_EBP + -0x2c)), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar3 = FUN_10005be0((LPCWSTR)(unaff_EBP + -0x25c));
        if ((iVar3 != 0) && (*(int *)(unaff_EBP + -0x20) != 0)) {
          FUN_10006089();
        }
        goto LAB_10007ed6;
      }
      bVar1 = FUN_10005c0f(*(HKEY *)(unaff_EBP + -0x2c));
      *(uint *)(unaff_EBP + 8) = CONCAT31(extraout_var_00,bVar1);
      uVar6 = ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2c));
      if (uVar6 == 0) {
        if ((*(int *)(unaff_EBP + -0x20) != 0) && (*(int *)(unaff_EBP + 8) == 0)) {
          *(undefined4 *)(unaff_EBP + -0x44) = 0;
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          *(undefined4 *)(unaff_EBP + -0x3c) = 0;
          *(undefined1 *)(unaff_EBP + -4) = 4;
          *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + 0xc);
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          *(undefined4 *)(unaff_EBP + -0x3c) = 0;
          uVar6 = DeleteSubKey((void *)(unaff_EBP + -0x44),(LPCWSTR)(unaff_EBP + -0x25c));
          *(undefined4 *)(unaff_EBP + -0x44) = 0;
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          *(undefined4 *)(unaff_EBP + -0x3c) = 0;
          if (uVar6 != 0) {
            uVar2 = FUN_1000554b(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 0;
            pCVar9 = (CRegKey *)(unaff_EBP + -0x44);
            goto LAB_10007ff5;
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          pCVar9 = (CRegKey *)(unaff_EBP + -0x44);
LAB_10007f88:
          ATL::CRegKey::Close(pCVar9);
LAB_10007f8d:
          if (((*(int *)(unaff_EBP + 0x10) != 0) && (*lpString1 == L'{')) &&
             (iVar3 = lstrlenW(lpString1), iVar3 == 1)) {
            uVar2 = FUN_10007b16();
            if ((int)uVar2 < 0) goto LAB_10007b57;
            this = *(void **)(unaff_EBP + -0x10);
            goto LAB_10007b47;
          }
        }
        goto LAB_10007ed6;
      }
    }
    else {
      if (iVar3 != 0) goto LAB_10007ed6;
      uVar6 = *(uint *)(unaff_EBP + 8);
    }
LAB_10008011:
    uVar2 = FUN_1000554b(uVar6);
    goto LAB_10007b57;
  }
  goto LAB_10007ed6;
}



// Function: FUN_10008034 at 10008034

undefined4 FUN_10008034(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int *piVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  
  FUN_10009190();
  piVar4 = *(int **)(unaff_EBP + 0x10);
  *piVar4 = 0;
  puVar5 = *(undefined4 **)(extraout_ECX + 0x2c);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (puVar5 != (undefined4 *)0x0) {
    for (; (int *)*puVar5 != (int *)0x0; puVar5 = puVar5 + 9) {
      if ((puVar5[2] != 0) &&
         (iVar2 = _InlineIsEqualGUID(*(int **)(unaff_EBP + 8),(int *)*puVar5), iVar2 != 0)) {
        piVar1 = puVar5 + 4;
        if (*piVar1 == 0) {
          *(undefined **)(unaff_EBP + -0x18) = &DAT_10011b3c;
          *(undefined1 *)(unaff_EBP + -0x14) = 0;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10011b3c);
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          iVar2 = *piVar1;
          *(undefined1 *)(unaff_EBP + -0x14) = 1;
          if (iVar2 == 0) {
            uVar3 = (*(code *)puVar5[2])(puVar5[3],&DAT_1000bccc,piVar1);
            *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10011b3c);
          iVar2 = *piVar1;
          piVar4 = *(int **)(unaff_EBP + 0x10);
          *(undefined1 *)(unaff_EBP + -0x14) = 0;
          if (iVar2 != 0) goto LAB_100080cc;
        }
        else {
LAB_100080cc:
          uVar3 = (*(code *)**(undefined4 **)*piVar1)
                            ((undefined4 *)*piVar1,*(undefined4 *)(unaff_EBP + 0xc),piVar4);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
        }
        if ((*piVar4 != 0) || (*(int *)(unaff_EBP + -0x10) != 0)) goto LAB_100080f9;
        break;
      }
    }
  }
  uVar3 = FUN_1000727c();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
LAB_100080f9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}



// Function: FUN_1000810d at 1000810d

undefined4 FUN_1000810d(void)

{
  int *piVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar3;
  DWORD DVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  code *pcVar5;
  undefined4 *puVar6;
  
  FUN_10009190();
  if ((extraout_ECX[3] != 0) && (extraout_ECX[5] != 0)) {
    uVar2 = 0;
    goto LAB_100082ee;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10011820 + 0x10);
  *(LPCRITICAL_SECTION *)(unaff_EBP + -0x28) = lpCriticalSection;
  *(LPCRITICAL_SECTION *)(unaff_EBP + -0x24) = lpCriticalSection;
  *(undefined1 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(unaff_EBP + -0x20) = 1;
  *(undefined4 *)(unaff_EBP + -0x10) = 0x80004005;
  if (extraout_ECX[3] == 0) {
    piVar1 = (int *)extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar3 = _InlineIsEqualGUID(&DAT_10011824,piVar1);
    if (((iVar3 == 0) || (*(short *)(extraout_ECX + 2) != -1)) ||
       (*(short *)((int)extraout_ECX + 10) != -1)) {
      uVar2 = Ordinal_162(piVar1,*(undefined2 *)(extraout_ECX + 2),
                          *(undefined2 *)((int)extraout_ECX + 10),*(undefined4 *)(unaff_EBP + 8),
                          unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
    }
    else {
      DVar4 = GetModuleFileNameW(DAT_10011b58,(LPWSTR)(unaff_EBP + -0x230),0x104);
      if ((DVar4 == 0) || (DVar4 == 0x104)) goto LAB_100082c3;
      *(undefined4 *)(unaff_EBP + 8) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar2 = Ordinal_161(unaff_EBP + -0x230,unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_100011d5((int *)(unaff_EBP + 8));
    }
    if (-1 < *(int *)(unaff_EBP + -0x10)) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      iVar3 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x18))
                        (*(int **)(unaff_EBP + -0x14),*extraout_ECX,unaff_EBP + -0x18);
      *(int *)(unaff_EBP + -0x10) = iVar3;
      if (-1 < iVar3) {
        piVar1 = *(int **)(unaff_EBP + -0x18);
        *(int **)(unaff_EBP + 8) = piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        *(undefined1 *)(unaff_EBP + -4) = 5;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 7;
        iVar3 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                          (*(undefined4 **)(unaff_EBP + -0x18),&DAT_1000bcb0,unaff_EBP + -0x1c);
        if (-1 < iVar3) {
          FUN_100075b9((void *)(unaff_EBP + 8),(undefined4 *)(unaff_EBP + -0x1c));
        }
        extraout_ECX[3] = *(undefined4 *)(unaff_EBP + 8);
        iVar3 = DAT_10011820;
        *(undefined4 *)(unaff_EBP + 8) = 0;
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = iVar3 + 4;
        }
        pcVar5 = FUN_100065a7;
        puVar6 = extraout_ECX;
        FUN_10007373();
        *(undefined1 *)(unaff_EBP + -4) = 5;
        piVar1 = *(int **)(unaff_EBP + -0x1c);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1,iVar3,pcVar5,puVar6);
        }
        *(undefined1 *)(unaff_EBP + -4) = 3;
        piVar1 = *(int **)(unaff_EBP + 8);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
        }
      }
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));
      *(undefined1 *)(unaff_EBP + -4) = 0;
      piVar1 = *(int **)(unaff_EBP + -0x18);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
LAB_100082c3:
  if ((extraout_ECX[3] != 0) && (extraout_ECX[5] == 0)) {
    uVar2 = FUN_1000642f();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x28));
  uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -0x20) = 0;
LAB_100082ee:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_100082fe at 100082fe

void FUN_100082fe(int param_1,void *param_2)

{
  DWORD DVar1;
  
  DVar1 = FUN_1000716f(0x10011b2c,param_1,param_2);
  if ((-1 < (int)DVar1) && (DAT_10011814 != (code *)0x0)) {
    (*DAT_10011814)(DAT_10011b58);
  }
  return;
}



// Function: FUN_1000832c at 1000832c

void FUN_1000832c(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_10011818 != (code *)0x0) && (iVar1 = (*DAT_10011818)(), iVar1 < 0)) {
    return;
  }
  FUN_100071f5(0x10011b2c,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 10008352

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  HRESULT HVar1;
  
                    /* 0x8352  2  DllGetClassObject */
  HVar1 = FUN_10008034();
  return HVar1;
}



// Function: FUN_10008360 at 10008360

undefined4 * FUN_10008360(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_10007617();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}



// Function: FUN_10008395 at 10008395

LONG FUN_10008395(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10011820 + 4))();
  }
  return LVar1;
}



// Function: FUN_100083bf at 100083bf

LONG FUN_100083bf(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10011820 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 100083fe

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000beac,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10008418 at 10008418

void FUN_10008418(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[1] = 0xc0000001;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10007423();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000844c at 1000844c

void * __thiscall FUN_1000844c(void *this,byte param_1)

{
  FUN_10008418();
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000846b at 1000846b

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

uint __thiscall FUN_1000846b(void *this,undefined4 param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  WCHAR local_2008 [4096];
  short *local_8;
  
  local_8 = (short *)0x0;
  uVar3 = FUN_100069e1();
  if (-1 < (int)uVar3) {
    *(short **)this = local_8;
    sVar1 = *local_8;
    while( true ) {
      if ((sVar1 == 0) || (uVar3 = FUN_10005aca(this,local_2008), (int)uVar3 < 0))
      goto LAB_10008530;
      iVar4 = FUN_10005a27(local_2008);
      if (iVar4 == 0) break;
      uVar3 = FUN_10005aca(this,local_2008);
      if ((int)uVar3 < 0) goto LAB_10008530;
      if (local_2008[0] != L'{') break;
      if (param_2 == 0) {
        uVar3 = FUN_10007b16();
        if ((int)uVar3 < 0) goto LAB_10008530;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar2 = *this;
        uVar3 = FUN_10007b16();
        if ((int)uVar3 < 0) {
          *(undefined4 *)this = uVar2;
          FUN_10007b16();
          goto LAB_10008530;
        }
      }
      FUN_10005aa8((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
      sVar1 = **this;
    }
    uVar3 = 0x80020009;
LAB_10008530:
    CoTaskMemFree(local_8);
  }
  return uVar3;
}



// Function: FUN_1000856f at 1000856f

int __thiscall FUN_1000856f(void *this,int param_1,void *param_2)

{
  bool bVar1;
  void *pvVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  
  piVar3 = *(int **)((int)this + 0x2c);
  iVar4 = 0;
  if ((piVar3 != (int *)0x0) && (pvVar2 = (void *)*piVar3, pvVar2 != (void *)0x0)) {
    do {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_1000536e(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar4 = (*(code *)piVar3[1])(1);
        if (iVar4 < 0) {
          return iVar4;
        }
        (*(code *)piVar3[7])(1);
        iVar4 = FUN_10006c58();
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      piVar3 = piVar3 + 9;
      pvVar2 = (void *)*piVar3;
    } while (pvVar2 != (void *)0x0);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  iVar4 = FUN_100082fe(param_1,param_2);
  return iVar4;
}



// Function: FUN_100085de at 100085de

int __thiscall FUN_100085de(void *this,int param_1,void *param_2)

{
  bool bVar1;
  void *pvVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  
  piVar3 = *(int **)((int)this + 0x2c);
  iVar4 = 0;
  if ((piVar3 != (int *)0x0) && (pvVar2 = (void *)*piVar3, pvVar2 != (void *)0x0)) {
    do {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_1000536e(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        (*(code *)piVar3[7])(0);
        iVar4 = FUN_10006c58();
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (*(code *)piVar3[1])(0);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      piVar3 = piVar3 + 9;
      pvVar2 = (void *)*piVar3;
    } while (pvVar2 != (void *)0x0);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  iVar4 = FUN_1000832c(param_1,param_2);
  return iVar4;
}



// Function: FUN_1000864d at 1000864d

undefined4 __thiscall FUN_1000864d(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_1000810d();
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_1000868d at 1000868d

undefined4 __thiscall
FUN_1000868d(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_1000810d();
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



// Function: FUN_1000872e at 1000872e

void __thiscall
FUN_1000872e(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_1000810d();
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: DllRegisterServer at 10008771

void DllRegisterServer(void)

{
                    /* 0x8771  3  DllRegisterServer */
  FUN_1000856f(&DAT_10011afc,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10008780

void DllUnregisterServer(void)

{
                    /* 0x8780  4  DllUnregisterServer */
  FUN_100085de(&DAT_10011afc,1,(void *)0x0);
  return;
}



// Function: FUN_1000878f at 1000878f

undefined4 FUN_1000878f(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000864d(&PTR_DAT_100117c0,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100087b3 at 100087b3

void FUN_100087b3(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000868d(&PTR_DAT_100117c0,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100087d3 at 100087d3

void FUN_100087d3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_1000872e(&PTR_DAT_100117c0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100087e1 at 100087e1

uint FUN_100087e1(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  if (*(undefined4 **)(unaff_EBP + 0x10) == (undefined4 *)0x0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x80004003;
  }
  **(undefined4 **)(unaff_EBP + 0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x8007000e;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pvVar1 = operator_new(0x28);
  *(void **)(unaff_EBP + -0x1c) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_10008360();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = puVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar3 = FUN_10008856();
  return uVar3;
}



// Function: Catch@10008846 at 10008846

undefined * Catch_10008846(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008850;
}



// Function: FUN_10008856 at 10008856

uint FUN_10008856(void)

{
  uint uVar1;
  int unaff_EBP;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[9] = *(int *)(unaff_EBP + 8);
    uVar1 = FUN_10005eee((int)(unaff_ESI + 1));
    unaff_EDI = uVar1;
    if (-1 < (int)uVar1) {
      unaff_EDI = 0;
    }
    if (uVar1 < 0x80000000) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_1000888e;
    }
    (**(code **)(*unaff_ESI + 0x14))(1);
  }
LAB_1000888e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_100088a1 at 100088a1

DWORD FUN_100088a1(void)

{
  HMODULE hModule;
  DWORD DVar1;
  HRSRC hResInfo;
  HGLOBAL pvVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffbdc;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x424) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  hModule = LoadLibraryExW(*(LPCWSTR *)(unaff_EBP + 8),(HANDLE)0x0,2);
  *(HMODULE *)(unaff_EBP + -0x18) = hModule;
  if (hModule == (HMODULE)0x0) {
    DVar1 = FUN_10005536();
    goto LAB_100089aa;
  }
  hResInfo = FindResourceW(hModule,*(LPCWSTR *)(unaff_EBP + 0xc),*(LPCWSTR *)(unaff_EBP + 0x10));
  if (hResInfo == (HRSRC)0x0) {
LAB_10008903:
    DVar1 = FUN_10005536();
  }
  else {
    pvVar2 = LoadResource(hModule,hResInfo);
    *(HGLOBAL *)(unaff_EBP + 0x10) = pvVar2;
    if (pvVar2 == (HGLOBAL)0x0) goto LAB_10008903;
    DVar1 = SizeofResource(hModule,hResInfo);
    *(DWORD *)(unaff_EBP + 8) = DVar1;
    if (DVar1 <= DVar1 + 1) {
      *(undefined1 *)(unaff_EBP + -4) = 2;
      Allocate((void *)(unaff_EBP + -0x424),DVar1 + 1);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      DVar1 = FUN_10008962();
      return DVar1;
    }
    DVar1 = 0x8007000e;
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x18));
LAB_100089aa:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + -0x424) != unaff_EBP + -0x420) {
    FUN_10005e8e((undefined4 *)(unaff_EBP + -0x424));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100011d5((int *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar1;
}



// Function: Catch@10008950 at 10008950

undefined * Catch_10008950(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000895d;
}



// Function: FUN_10008962 at 10008962

DWORD FUN_10008962(void)

{
  DWORD DVar1;
  uint uVar2;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x424) == unaff_EBX) {
    uVar2 = 0x8007000e;
  }
  else {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + 0x10),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x424),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      uVar2 = FUN_10005536();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x424) + DVar1 * 2) = 0;
      uVar2 = FUN_1000846b((void *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x424),
                           *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x18));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x424) != unaff_EBP + -0x420) {
    FUN_10005e8e((undefined4 *)(unaff_EBP + -0x424));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100011d5((int *)(unaff_EBP + -0x14));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}



// Function: FUN_100089e5 at 100089e5

DWORD FUN_100089e5(void)

{
  DWORD DVar1;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DVar1 = FUN_100088a1();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100011d5((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar1;
}



// Function: FUN_10008a2d at 10008a2d

DWORD FUN_10008a2d(void)

{
  DWORD DVar1;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(int *)(unaff_EBP + 0x10) == 0) || (*(int *)(unaff_EBP + 0x14) == 0)) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100011d5((int *)(unaff_EBP + -0x10));
    DVar1 = 0x80070057;
  }
  else {
    DVar1 = FUN_100088a1();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100011d5((int *)(unaff_EBP + -0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar1;
}



// Function: FUN_10008a90 at 10008a90

DWORD FUN_10008a90(void)

{
  DWORD DVar1;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DVar1 = FUN_100088a1();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100011d5((int *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar1;
}



// Function: FUN_10008ad7 at 10008ad7

DWORD FUN_10008ad7(void)

{
  DWORD DVar1;
  int unaff_EBP;
  
  FUN_10009190();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(int *)(unaff_EBP + 0x10) == 0) || (*(int *)(unaff_EBP + 0x14) == 0)) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100011d5((int *)(unaff_EBP + -0x10));
    DVar1 = 0x80070057;
  }
  else {
    DVar1 = FUN_100088a1();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_100011d5((int *)(unaff_EBP + -0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar1;
}



// Function: FUN_10008b39 at 10008b39

DWORD FUN_10008b39(void)

{
  HMODULE pHVar1;
  bool bVar2;
  DWORD DVar3;
  HMODULE pHVar4;
  int iVar5;
  int unaff_EBP;
  int *piVar6;
  
  FUN_10009190();
  *(undefined ***)(unaff_EBP + -0x20) = ATL::CRegObject::vftable;
  *(int *)(unaff_EBP + -0x24) = unaff_EBP + -0x1c;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  piVar6 = *(int **)(unaff_EBP + 0x14);
  if (piVar6 != (int *)0x0) {
    for (; *piVar6 != 0; piVar6 = piVar6 + 2) {
      FUN_100077a8();
    }
  }
  DVar3 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x14))(unaff_EBP + -0x20);
  if (-1 < (int)DVar3) {
    *(undefined4 *)(unaff_EBP + 0x14) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    pHVar1 = DAT_10011b58;
    DVar3 = GetModuleFileNameW(DAT_10011b58,(LPWSTR)(unaff_EBP + -0x22c),0x104);
    if (DVar3 == 0) {
      DVar3 = FUN_10005536();
    }
    else {
      if (DVar3 == 0x104) {
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_100011d5((int *)(unaff_EBP + 0x14));
        DVar3 = 0x8007007a;
        goto LAB_10008b9c;
      }
      FUN_1000569e((short *)(unaff_EBP + -0xa54),0x208,(short *)(unaff_EBP + -0x22c));
      if ((pHVar1 == (HMODULE)0x0) || (pHVar4 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar4)) {
        *(undefined2 *)(unaff_EBP + -0x644) = 0x22;
        bVar2 = FUN_10005407((void *)(unaff_EBP + -0x642),0x20b,(LPCWSTR)(unaff_EBP + -0xa54));
        if (!bVar2) {
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_100011d5((int *)(unaff_EBP + 0x14));
          DVar3 = 0x80004005;
          goto LAB_10008b9c;
        }
        iVar5 = lstrlenW((LPCWSTR)(unaff_EBP + -0x644));
        *(undefined2 *)(unaff_EBP + -0x644 + iVar5 * 2) = 0x22;
        *(undefined2 *)(unaff_EBP + -0x642 + iVar5 * 2) = 0;
      }
      DVar3 = FUN_100077a8();
      if ((-1 < (int)DVar3) && (DVar3 = FUN_100077a8(), -1 < (int)DVar3)) {
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          DVar3 = FUN_10008ad7();
        }
        else {
          DVar3 = FUN_10008a2d();
        }
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_100011d5((int *)(unaff_EBP + 0x14));
  }
LAB_10008b9c:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10006933();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar3;
}



// Function: FUN_10008d0b at 10008d0b

DWORD FUN_10008d0b(void)

{
  HMODULE pHVar1;
  bool bVar2;
  DWORD DVar3;
  HMODULE pHVar4;
  int iVar5;
  int unaff_EBP;
  int *piVar6;
  
  FUN_10009190();
  *(undefined ***)(unaff_EBP + -0x20) = ATL::CRegObject::vftable;
  *(int *)(unaff_EBP + -0x24) = unaff_EBP + -0x1c;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  piVar6 = *(int **)(unaff_EBP + 0x14);
  if (piVar6 != (int *)0x0) {
    for (; *piVar6 != 0; piVar6 = piVar6 + 2) {
      FUN_100077a8();
    }
  }
  DVar3 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x14))(unaff_EBP + -0x20);
  if (-1 < (int)DVar3) {
    *(undefined4 *)(unaff_EBP + 0x14) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    pHVar1 = DAT_10011b58;
    DVar3 = GetModuleFileNameW(DAT_10011b58,(LPWSTR)(unaff_EBP + -0x22c),0x104);
    if (DVar3 == 0) {
      DVar3 = FUN_10005536();
    }
    else {
      if (DVar3 == 0x104) {
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_100011d5((int *)(unaff_EBP + 0x14));
        DVar3 = 0x8007007a;
        goto LAB_10008d6e;
      }
      FUN_1000569e((short *)(unaff_EBP + -0xa54),0x208,(short *)(unaff_EBP + -0x22c));
      if ((pHVar1 == (HMODULE)0x0) || (pHVar4 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar4)) {
        *(undefined2 *)(unaff_EBP + -0x644) = 0x22;
        bVar2 = FUN_10005407((void *)(unaff_EBP + -0x642),0x20b,(LPCWSTR)(unaff_EBP + -0xa54));
        if (!bVar2) {
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_100011d5((int *)(unaff_EBP + 0x14));
          DVar3 = 0x80004005;
          goto LAB_10008d6e;
        }
        iVar5 = lstrlenW((LPCWSTR)(unaff_EBP + -0x644));
        *(undefined2 *)(unaff_EBP + -0x644 + iVar5 * 2) = 0x22;
        *(undefined2 *)(unaff_EBP + -0x642 + iVar5 * 2) = 0;
      }
      DVar3 = FUN_100077a8();
      if ((-1 < (int)DVar3) && (DVar3 = FUN_100077a8(), -1 < (int)DVar3)) {
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          DVar3 = FUN_10008a90();
        }
        else {
          DVar3 = FUN_100089e5();
        }
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_100011d5((int *)(unaff_EBP + 0x14));
  }
LAB_10008d6e:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10006933();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DVar3;
}



// Function: FUN_10008edd at 10008edd

void FUN_10008edd(void)

{
  FUN_10008b39();
  return;
}



// Function: FUN_10008ee6 at 10008ee6

void FUN_10008ee6(void)

{
  FUN_10008d0b();
  return;
}



// Function: FUN_10008eef at 10008eef

void FUN_10008eef(void)

{
  FUN_10008d0b();
  return;
}



// Function: FUN_10008f07 at 10008f07

void __fastcall FUN_10008f07(int *param_1)

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



// Function: FUN_10008f4b at 10008f4b

int __fastcall FUN_10008f4b(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10008f64 at 10008f64

undefined4 * __fastcall FUN_10008f64(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10008f4b((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1000e2a0;
  param_1[3] = &DAT_1000e2a0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10011810 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10008fa5 at 10008fa5

void __fastcall FUN_10008fa5(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10008fc4 at 10008fc4

int __fastcall FUN_10008fc4(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10008fe9 at 10008fe9

void __fastcall FUN_10008fe9(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_10008fa5((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10009001 at 10009001

undefined4 * __fastcall FUN_10009001(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10008fc4((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1000bf60;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10011810 = 1;
  }
  return param_1;
}



// Function: FUN_1000908a at 1000908a

void __fastcall FUN_1000908a(int param_1)

{
  facet *pfVar1;
  
  pfVar1 = std::locale::facet::_Decref(*(facet **)(param_1 + 4));
  if (pfVar1 != (facet *)0x0) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: Facet_Register at 100090a0

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
    *puVar1 = DAT_10011b8c;
    puVar1[1] = param_1;
  }
  DAT_10011b8c = puVar1;
  return;
}



// Function: FUN_100090ca at 100090ca

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100090ca(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  FUN_10009836(4);
  std::_Lockit::_Lockit((_Lockit *)(unaff_EBP + -0x10),0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (puVar1 = DAT_10011b8c, DAT_10011b8c != (undefined4 *)0x0) {
    DAT_10011b8c = (undefined4 *)*DAT_10011b8c;
    FUN_1000908a((int)puVar1);
    operator_delete(puVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_1000911a at 1000911a

void FUN_1000911a(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000912c

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



// Function: FUN_10009190 at 10009190

void FUN_10009190(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}



// Function: __alloca_probe_16 at 10009230

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



// Function: __alloca_probe_8 at 10009246

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



// Function: __ArrayUnwind at 10009262

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



// Function: `eh_vector_destructor_iterator' at 100092c0

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
  FUN_1000930b();
  return;
}



// Function: FUN_1000930b at 1000930b

void FUN_1000930b(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 10009336

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
  
  local_8 = &DAT_1000e218;
  uStack_c = 0x10009342;
  local_20[0] = DecodePointer(DAT_10011ed4);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10011ed4);
    local_24 = DecodePointer(DAT_10011ed0);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10011ed4 = EncodePointer(local_20[0]);
    DAT_10011ed0 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_100093ce();
  }
  return p_Var1;
}



// Function: FUN_100093ce at 100093ce

void FUN_100093ce(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 100093d7

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 10009400

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



// Function: `eh_vector_constructor_iterator' at 1000942b

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
  FUN_10009478();
  return;
}



// Function: FUN_10009478 at 10009478

void FUN_10009478(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __CRT_INIT@12 at 100094e4

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
    if (DAT_10011b94 < 1) {
      return 0;
    }
    DAT_10011b94 = DAT_10011b94 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10011ec8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10011ec4 == 2) {
      param_2 = (int *)DecodePointer(DAT_10011ed4);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10011ed0);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10011ed4);
            piVar8 = (int *)DecodePointer(DAT_10011ed0);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10011ed0 = (PVOID)encoded_null();
        DAT_10011ed4 = DAT_10011ed0;
      }
      DAT_10011ec4 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10011ec8,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10011ec8,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10011ec4 == 0) {
      DAT_10011ec4 = 1;
      iVar5 = initterm_e(&DAT_1000b3ac,&DAT_1000b3b4);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1000b32c,&DAT_1000b3a8);
      DAT_10011ec4 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10011ec8,0);
    }
    if ((DAT_10011ecc != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10011ecc), BVar2 != 0)) {
      (*DAT_10011ecc)(param_1,2,param_3);
    }
    DAT_10011b94 = DAT_10011b94 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 100096ee

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000978e) */
/* WARNING: Removing unreachable block (ram,0x1000973b) */
/* WARNING: Removing unreachable block (ram,0x100097bb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10011800 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10011b94 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10006704(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10006704(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_100097f9();
  return local_20;
}



// Function: FUN_100097f9 at 100097f9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100097f9(void)

{
  _DAT_10011800 = 0xffffffff;
  return;
}



// Function: entry at 10009804

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: __security_check_cookie at 10009827

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10011808) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FUN_10009836 at 10009836

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */

void __cdecl FUN_10009836(int param_1)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10011808 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 10009869

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



// Function: __SEH_prolog4 at 10009890

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10011808 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 100098d5

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



// Function: FUN_100098e9 at 100098e9

void __cdecl
FUN_100098e9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10011808,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 10009980

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



// Function: __FindPESection at 100099c0

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



// Function: __IsNonwritableInCurrentImage at 10009a10

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
  
  pcStack_10 = FUN_100098e9;
  local_14 = ExceptionList;
  local_c = DAT_10011808 ^ 0x1000e280;
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



// Function: ___security_init_cookie at 10009ae4

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
  if ((DAT_10011808 == 0xbb40e64e) || ((DAT_10011808 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10011808 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10011808 == 0xbb40e64e) {
      DAT_10011808 = 0xbb40e64f;
    }
    else if ((DAT_10011808 & 0xffff0000) == 0) {
      DAT_10011808 = DAT_10011808 | (DAT_10011808 | 0x4711) << 0x10;
    }
    DAT_1001180c = ~DAT_10011808;
  }
  else {
    DAT_1001180c = ~DAT_10011808;
  }
  return;
}



// Function: ___report_gsfailure at 10009b7f

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
  
  _DAT_10011cb8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10011cbc = &stack0x00000004;
  _DAT_10011bf8 = 0x10001;
  _DAT_10011ba0 = 0xc0000409;
  _DAT_10011ba4 = 1;
  local_32c = DAT_10011808;
  local_328 = DAT_1001180c;
  _DAT_10011bac = unaff_retaddr;
  _DAT_10011c84 = in_GS;
  _DAT_10011c88 = in_FS;
  _DAT_10011c8c = in_ES;
  _DAT_10011c90 = in_DS;
  _DAT_10011c94 = unaff_EDI;
  _DAT_10011c98 = unaff_ESI;
  _DAT_10011c9c = unaff_EBX;
  _DAT_10011ca0 = in_EDX;
  _DAT_10011ca4 = in_ECX;
  _DAT_10011ca8 = in_EAX;
  _DAT_10011cac = unaff_EBP;
  DAT_10011cb0 = unaff_retaddr;
  _DAT_10011cb4 = in_CS;
  _DAT_10011cc0 = in_SS;
  DAT_10011bf0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1000bf7c);
  if (DAT_10011bf0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: Unwind@10009c9e at 10009c9e

void Unwind_10009c9e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009ca1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009cb1 at 10009cb1

void Unwind_10009cb1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009cb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10009cc4 at 10009cc4

void Unwind_10009cc4(void)

{
  int unaff_EBP;
  
  FUN_1000107c(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009cd6 at 10009cd6

void Unwind_10009cd6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000107c(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10009d0d at 10009d0d

void Unwind_10009d0d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009d20 at 10009d20

void Unwind_10009d20(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002030(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10009d43 at 10009d43

void Unwind_10009d43(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009d4b at 10009d4b

void Unwind_10009d4b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10009d64 at 10009d64

void Unwind_10009d64(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009d6c at 10009d6c

void Unwind_10009d6c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009d7e at 10009d7e

void Unwind_10009d7e(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009d86 at 10009d86

void Unwind_10009d86(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002030(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10009da9 at 10009da9

void Unwind_10009da9(void)

{
  int unaff_EBP;
  
  FUN_100027a6(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009dbb at 10009dbb

void Unwind_10009dbb(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009dbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009dce at 10009dce

void Unwind_10009dce(void)

{
  FUN_10002908();
  return;
}



// Function: Unwind@10009de6 at 10009de6

void Unwind_10009de6(void)

{
  int unaff_EBP;
  
  FUN_1000295d(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009df8 at 10009df8

void Unwind_10009df8(void)

{
  FUN_1000298c();
  return;
}



// Function: Unwind@10009e0d at 10009e0d

void Unwind_10009e0d(void)

{
  int unaff_EBP;
  
  FUN_100029f4(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009e1f at 10009e1f

void Unwind_10009e1f(void)

{
  int unaff_EBP;
  
  FUN_10002764(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10009e27 at 10009e27

void Unwind_10009e27(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100063b3();
    return;
  }
  return;
}



// Function: Unwind@10009e40 at 10009e40

void Unwind_10009e40(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10009e48 at 10009e48

void Unwind_10009e48(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10009e5a at 10009e5a

void Unwind_10009e5a(void)

{
  int unaff_EBP;
  
  FUN_100027a6(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009e62 at 10009e62

void Unwind_10009e62(void)

{
  FUN_1000298c();
  return;
}



// Function: Unwind@10009e77 at 10009e77

void Unwind_10009e77(void)

{
  FUN_10002de3();
  return;
}



// Function: Unwind@10009e82 at 10009e82

void Unwind_10009e82(void)

{
  FUN_1000298c();
  return;
}



// Function: Unwind@10009e97 at 10009e97

void Unwind_10009e97(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009e9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10009ea3 at 10009ea3

void Unwind_10009ea3(void)

{
  FUN_1000160f();
  return;
}



// Function: Unwind@10009eb8 at 10009eb8

void Unwind_10009eb8(void)

{
  int unaff_EBP;
  
  FUN_10002909((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@10009eca at 10009eca

void Unwind_10009eca(void)

{
  FUN_10002e85();
  return;
}



// Function: Unwind@10009edc at 10009edc

void Unwind_10009edc(void)

{
  int unaff_EBP;
  
  FUN_1000295d((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10009ee4 at 10009ee4

void Unwind_10009ee4(void)

{
  FUN_10002dc0();
  return;
}



// Function: Unwind@10009eec at 10009eec

void Unwind_10009eec(void)

{
  int unaff_EBP;
  
  FUN_1000295d((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10009f08 at 10009f08

void Unwind_10009f08(void)

{
  FUN_10002de3();
  return;
}



// Function: Unwind@10009f1d at 10009f1d

void Unwind_10009f1d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10009f33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@10009f3a at 10009f3a

void Unwind_10009f3a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@10009f46 at 10009f46

void Unwind_10009f46(void)

{
  FUN_1000160f();
  return;
}



// Function: Unwind@10009f65 at 10009f65

void Unwind_10009f65(void)

{
  int unaff_EBP;
  
  FUN_10002030((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10009f77 at 10009f77

void Unwind_10009f77(void)

{
  int unaff_EBP;
  
  FUN_10002030((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009f89 at 10009f89

void Unwind_10009f89(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10009f9e at 10009f9e

void Unwind_10009f9e(void)

{
  FUN_10003438();
  return;
}



// Function: Unwind@10009fa6 at 10009fa6

void Unwind_10009fa6(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009fb8 at 10009fb8

void Unwind_10009fb8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009fbb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009fcb at 10009fcb

void Unwind_10009fcb(void)

{
  int unaff_EBP;
  
  FUN_10002030((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10009fd3 at 10009fd3

void Unwind_10009fd3(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002030(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10009ff6 at 10009ff6

void Unwind_10009ff6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000a019 at 1000a019

void Unwind_1000a019(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1000a02f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<char,struct_std::char_traits<char>_>::
    ~basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x68));
    return;
  }
  return;
}



// Function: Unwind@1000a036 at 1000a036

void Unwind_1000a036(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a03c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<char,struct_std::char_traits<char>_>::
  ~basic_istream<char,struct_std::char_traits<char>_>
            ((basic_istream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x10));
  return;
}



// Function: Unwind@1000a042 at 1000a042

void Unwind_1000a042(void)

{
  FUN_100042af();
  return;
}



// Function: Unwind@1000a057 at 1000a057

void Unwind_1000a057(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a05d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<char,struct_std::char_traits<char>_>::
  ~basic_istream<char,struct_std::char_traits<char>_>
            ((basic_istream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1000a063 at 1000a063

void Unwind_1000a063(void)

{
  FUN_100042af();
  return;
}



// Function: Unwind@1000a078 at 1000a078

void Unwind_1000a078(void)

{
  int unaff_EBP;
  
  FUN_10003487(unaff_EBP + -0xc0);
  return;
}



// Function: Unwind@1000a083 at 1000a083

void Unwind_1000a083(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000a08b at 1000a08b

void Unwind_1000a08b(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a09d at 1000a09d

void Unwind_1000a09d(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a0a5 at 1000a0a5

void Unwind_1000a0a5(void)

{
  int unaff_EBP;
  
  FUN_10003487(unaff_EBP + -0xc0);
  return;
}



// Function: Unwind@1000a0b0 at 1000a0b0

void Unwind_1000a0b0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000a0b8 at 1000a0b8

void Unwind_1000a0b8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000a0c0 at 1000a0c0

void Unwind_1000a0c0(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a0d2 at 1000a0d2

void Unwind_1000a0d2(void)

{
  int unaff_EBP;
  
  FUN_10002030((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a0da at 1000a0da

void Unwind_1000a0da(void)

{
  int unaff_EBP;
  
  FUN_10004ba7(unaff_EBP + -0xd8);
  return;
}



// Function: Unwind@1000a0e5 at 1000a0e5

void Unwind_1000a0e5(void)

{
  int unaff_EBP;
  
  thunk_FUN_100034bd((_Container_base0 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000a0ed at 1000a0ed

void Unwind_1000a0ed(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_10002030(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                  (unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000a110 at 1000a110

void Unwind_1000a110(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x4c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x4c) = *(uint *)(unaff_EBP + -0x4c) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000a129 at 1000a129

void Unwind_1000a129(void)

{
  int unaff_EBP;
  
  FUN_10002853((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000a131 at 1000a131

void Unwind_1000a131(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000a139 at 1000a139

void Unwind_1000a139(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a141 at 1000a141

void Unwind_1000a141(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000a149 at 1000a149

void Unwind_1000a149(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a151 at 1000a151

void Unwind_1000a151(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000a159 at 1000a159

void Unwind_1000a159(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a161 at 1000a161

void Unwind_1000a161(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1000a16c at 1000a16c

void Unwind_1000a16c(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000a174 at 1000a174

void Unwind_1000a174(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1000a17f at 1000a17f

void Unwind_1000a17f(void)

{
  int unaff_EBP;
  
  FUN_10002030(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a187 at 1000a187

void Unwind_1000a187(void)

{
  int unaff_EBP;
  
  FUN_10002030((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@1000a192 at 1000a192

void Unwind_1000a192(void)

{
  int unaff_EBP;
  
  FUN_10002030(*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
                (unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a19a at 1000a19a

void Unwind_1000a19a(void)

{
  int unaff_EBP;
  
  FUN_10002030((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1000a1a5 at 1000a1a5

void Unwind_1000a1a5(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a1ad at 1000a1ad

void Unwind_1000a1ad(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a1b5 at 1000a1b5

void Unwind_1000a1b5(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a1bd at 1000a1bd

void Unwind_1000a1bd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1000a1c8 at 1000a1c8

void Unwind_1000a1c8(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a1d0 at 1000a1d0

void Unwind_1000a1d0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1000a1db at 1000a1db

void Unwind_1000a1db(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x1a8));
  return;
}



// Function: Unwind@1000a1e6 at 1000a1e6

void Unwind_1000a1e6(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1000a1f1 at 1000a1f1

void Unwind_1000a1f1(void)

{
  int unaff_EBP;
  
  FUN_10003487(unaff_EBP + -0x18c);
  return;
}



// Function: Unwind@1000a1fc at 1000a1fc

void Unwind_1000a1fc(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1000a207 at 1000a207

void Unwind_1000a207(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000a20f at 1000a20f

void Unwind_1000a20f(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000a221 at 1000a221

void Unwind_1000a221(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a229 at 1000a229

void Unwind_1000a229(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000a231 at 1000a231

void Unwind_1000a231(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a243 at 1000a243

void Unwind_1000a243(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a24b at 1000a24b

void Unwind_1000a24b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000a253 at 1000a253

void Unwind_1000a253(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a265 at 1000a265

void Unwind_1000a265(void)

{
  DAT_10011af8 = DAT_10011af8 & 0xfffffffe;
  return;
}



// Function: Unwind@1000a27d at 1000a27d

void Unwind_1000a27d(void)

{
  FUN_10002f97();
  return;
}



// Function: Unwind@1000a28f at 1000a28f

void Unwind_1000a28f(void)

{
  int unaff_EBP;
  
  FUN_10006061(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a2a1 at 1000a2a1

void Unwind_1000a2a1(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a2b3 at 1000a2b3

void Unwind_1000a2b3(void)

{
  int unaff_EBP;
  
  FUN_100011d5((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a2c5 at 1000a2c5

void Unwind_1000a2c5(void)

{
  int unaff_EBP;
  
  FUN_10002764(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a2d7 at 1000a2d7

void Unwind_1000a2d7(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a2e1 at 1000a2e1

void Unwind_1000a2e1(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a2f3 at 1000a2f3

void Unwind_1000a2f3(void)

{
  FUN_10002908();
  return;
}



// Function: Unwind@1000a30a at 1000a30a

void Unwind_1000a30a(void)

{
  FUN_10002908();
  return;
}



// Function: Unwind@1000a32c at 1000a32c

void Unwind_1000a32c(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a334 at 1000a334

void Unwind_1000a334(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a33c at 1000a33c

void Unwind_1000a33c(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a344 at 1000a344

void Unwind_1000a344(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a34c at 1000a34c

void Unwind_1000a34c(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a354 at 1000a354

void Unwind_1000a354(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a370 at 1000a370

void Unwind_1000a370(void)

{
  int unaff_EBP;
  
  FUN_10006061(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a378 at 1000a378

void Unwind_1000a378(void)

{
  FUN_10006066();
  return;
}



// Function: Unwind@1000a38a at 1000a38a

void Unwind_1000a38a(void)

{
  FUN_10006066();
  return;
}



// Function: Unwind@1000a392 at 1000a392

void Unwind_1000a392(void)

{
  int unaff_EBP;
  
  FUN_10006061(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a3a4 at 1000a3a4

void Unwind_1000a3a4(void)

{
  int unaff_EBP;
  
  thunk_FUN_10005e2a(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a3b6 at 1000a3b6

void Unwind_1000a3b6(void)

{
  FUN_10006904();
  return;
}



// Function: Unwind@1000a3cb at 1000a3cb

void Unwind_1000a3cb(void)

{
  int unaff_EBP;
  
  FUN_100058ab(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1000a3dd at 1000a3dd

void Unwind_1000a3dd(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a3e5 at 1000a3e5

void Unwind_1000a3e5(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a3ed at 1000a3ed

void Unwind_1000a3ed(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a3f5 at 1000a3f5

void Unwind_1000a3f5(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a3fd at 1000a3fd

void Unwind_1000a3fd(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a405 at 1000a405

void Unwind_1000a405(void)

{
  int unaff_EBP;
  
  FUN_100011d5((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a40d at 1000a40d

void Unwind_1000a40d(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000a415 at 1000a415

void Unwind_1000a415(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a41d at 1000a41d

void Unwind_1000a41d(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a425 at 1000a425

void Unwind_1000a425(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a437 at 1000a437

void Unwind_1000a437(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a43f at 1000a43f

void Unwind_1000a43f(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a447 at 1000a447

void Unwind_1000a447(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a44f at 1000a44f

void Unwind_1000a44f(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a457 at 1000a457

void Unwind_1000a457(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a469 at 1000a469

void Unwind_1000a469(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a471 at 1000a471

void Unwind_1000a471(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a479 at 1000a479

void Unwind_1000a479(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a481 at 1000a481

void Unwind_1000a481(void)

{
  int unaff_EBP;
  
  FUN_1000107c((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a489 at 1000a489

void Unwind_1000a489(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a491 at 1000a491

void Unwind_1000a491(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a4a3 at 1000a4a3

void Unwind_1000a4a3(void)

{
  int unaff_EBP;
  
  FUN_10006658((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a4b5 at 1000a4b5

void Unwind_1000a4b5(void)

{
  int unaff_EBP;
  
  FUN_10006658((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a4c7 at 1000a4c7

void Unwind_1000a4c7(void)

{
  FUN_10002de3();
  return;
}



// Function: Unwind@1000a4d2 at 1000a4d2

void Unwind_1000a4d2(void)

{
  FUN_1000298c();
  return;
}



// Function: Unwind@1000a4e7 at 1000a4e7

void Unwind_1000a4e7(void)

{
  FUN_10002de3();
  return;
}



// Function: Unwind@1000a4fc at 1000a4fc

void Unwind_1000a4fc(void)

{
  int unaff_EBP;
  
  FUN_100065df((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a504 at 1000a504

void Unwind_1000a504(void)

{
  int unaff_EBP;
  
  FUN_100065df((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a516 at 1000a516

void Unwind_1000a516(void)

{
  int unaff_EBP;
  
  FUN_100065ef((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@1000a521 at 1000a521

void Unwind_1000a521(void)

{
  int unaff_EBP;
  
  FUN_100011d5((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a529 at 1000a529

void Unwind_1000a529(void)

{
  int unaff_EBP;
  
  FUN_100065ef((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@1000a53e at 1000a53e

void Unwind_1000a53e(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000a546 at 1000a546

void Unwind_1000a546(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a54e at 1000a54e

void Unwind_1000a54e(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000a556 at 1000a556

void Unwind_1000a556(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000a55e at 1000a55e

void Unwind_1000a55e(void)

{
  int unaff_EBP;
  
  FUN_1000148a((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000a570 at 1000a570

void Unwind_1000a570(void)

{
  int unaff_EBP;
  
  FUN_10006658((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a582 at 1000a582

void Unwind_1000a582(void)

{
  int unaff_EBP;
  
  FUN_10006658((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000a58a at 1000a58a

void Unwind_1000a58a(void)

{
  int unaff_EBP;
  
  FUN_100011d5((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a592 at 1000a592

void Unwind_1000a592(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a59a at 1000a59a

void Unwind_1000a59a(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a5a2 at 1000a5a2

void Unwind_1000a5a2(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a5aa at 1000a5aa

void Unwind_1000a5aa(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a5b2 at 1000a5b2

void Unwind_1000a5b2(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a5ba at 1000a5ba

void Unwind_1000a5ba(void)

{
  FUN_100063b3();
  return;
}



// Function: Unwind@1000a5c2 at 1000a5c2

void Unwind_1000a5c2(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a5ca at 1000a5ca

void Unwind_1000a5ca(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a5d2 at 1000a5d2

void Unwind_1000a5d2(void)

{
  int unaff_EBP;
  
  FUN_10002764((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a5e4 at 1000a5e4

void Unwind_1000a5e4(void)

{
  FUN_10007423();
  return;
}



// Function: Unwind@1000a5f6 at 1000a5f6

void Unwind_1000a5f6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a60a at 1000a60a

void Unwind_1000a60a(void)

{
  int unaff_EBP;
  
  FUN_100011d5((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a612 at 1000a612

void Unwind_1000a612(void)

{
  int unaff_EBP;
  
  FUN_100065ef((int *)(unaff_EBP + -0x424));
  return;
}



// Function: Unwind@1000a627 at 1000a627

void Unwind_1000a627(void)

{
  int unaff_EBP;
  
  thunk_FUN_10005e2a(*(undefined4 **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000a62f at 1000a62f

void Unwind_1000a62f(void)

{
  FUN_10006904();
  return;
}



// Function: Unwind@1000a637 at 1000a637

void Unwind_1000a637(void)

{
  FUN_10006933();
  return;
}



// Function: Unwind@1000a63f at 1000a63f

void Unwind_1000a63f(void)

{
  int unaff_EBP;
  
  FUN_100011d5((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1000a651 at 1000a651

void Unwind_1000a651(void)

{
  FUN_10006066();
  return;
}



// Function: Unwind@1000a65b at 1000a65b

void Unwind_1000a65b(void)

{
  FUN_10006061(0x10011afc);
  return;
}



// Function: Unwind@1000a66f at 1000a66f

void Unwind_1000a66f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a672. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_1000a9cc at 1000a9cc

void FUN_1000a9cc(void)

{
  Ordinal_6(DAT_1001196c);
  return;
}



// Function: FUN_1000a9d9 at 1000a9d9

void FUN_1000a9d9(void)

{
  Ordinal_6(DAT_10011a88);
  return;
}



// Function: FUN_1000a9e6 at 1000a9e6

void FUN_1000a9e6(void)

{
  Ordinal_6(DAT_10011a8c);
  return;
}



// Function: FUN_1000a9f3 at 1000a9f3

void FUN_1000a9f3(void)

{
  FID_conflict__Tidy(&DAT_10011870,'\x01',0);
  return;
}



// Function: FUN_1000aa02 at 1000aa02

void FUN_1000aa02(void)

{
  FID_conflict__Tidy(&DAT_10011854,'\x01',0);
  return;
}



// Function: FUN_1000aa11 at 1000aa11

void FUN_1000aa11(void)

{
  FID_conflict__Tidy(&DAT_10011838,'\x01',0);
  return;
}



// Function: FUN_1000aa20 at 1000aa20

void FUN_1000aa20(void)

{
  FID_conflict__Tidy(&DAT_100119fc,'\x01',0);
  return;
}



// Function: FUN_1000aa2f at 1000aa2f

void FUN_1000aa2f(void)

{
  FID_conflict__Tidy(&DAT_10011950,'\x01',0);
  return;
}



// Function: FUN_1000aa3e at 1000aa3e

void FUN_1000aa3e(void)

{
  FID_conflict__Tidy(&DAT_10011a50,'\x01',0);
  return;
}



// Function: FUN_1000aa4d at 1000aa4d

void FUN_1000aa4d(void)

{
  FID_conflict__Tidy(&DAT_1001188c,'\x01',0);
  return;
}



// Function: FUN_1000aa5c at 1000aa5c

void FUN_1000aa5c(void)

{
  FID_conflict__Tidy(&DAT_100119a8,'\x01',0);
  return;
}



// Function: FUN_1000aa6b at 1000aa6b

void FUN_1000aa6b(void)

{
  FID_conflict__Tidy(&DAT_10011a18,'\x01',0);
  return;
}



// Function: FUN_1000aa7a at 1000aa7a

void FUN_1000aa7a(void)

{
  FID_conflict__Tidy(&DAT_100119e0,'\x01',0);
  return;
}



// Function: FUN_1000aa89 at 1000aa89

void FUN_1000aa89(void)

{
  FID_conflict__Tidy(&DAT_10011a34,'\x01',0);
  return;
}



// Function: FUN_1000aa98 at 1000aa98

void FUN_1000aa98(void)

{
  FID_conflict__Tidy(&DAT_10011970,'\x01',0);
  return;
}



// Function: FUN_1000aaa7 at 1000aaa7

void FUN_1000aaa7(void)

{
  FID_conflict__Tidy(&DAT_10011934,'\x01',0);
  return;
}



// Function: FUN_1000aab6 at 1000aab6

void FUN_1000aab6(void)

{
  FID_conflict__Tidy(&DAT_100118a8,'\x01',0);
  return;
}



// Function: FUN_1000aac5 at 1000aac5

void FUN_1000aac5(void)

{
  FID_conflict__Tidy(&DAT_1001198c,'\x01',0);
  return;
}



// Function: FUN_1000aad4 at 1000aad4

void FUN_1000aad4(void)

{
  FID_conflict__Tidy(&DAT_100118c4,'\x01',0);
  return;
}



// Function: FUN_1000aae3 at 1000aae3

void FUN_1000aae3(void)

{
  FID_conflict__Tidy(&DAT_100118fc,'\x01',0);
  return;
}



// Function: FUN_1000aaf2 at 1000aaf2

void FUN_1000aaf2(void)

{
  FID_conflict__Tidy(&DAT_100119c4,'\x01',0);
  return;
}



// Function: FUN_1000ab01 at 1000ab01

void FUN_1000ab01(void)

{
  FID_conflict__Tidy(&DAT_10011a6c,'\x01',0);
  return;
}



// Function: FUN_1000ab10 at 1000ab10

void FUN_1000ab10(void)

{
  FID_conflict__Tidy(&DAT_100118e0,'\x01',0);
  return;
}



// Function: FUN_1000ab1f at 1000ab1f

void FUN_1000ab1f(void)

{
  FID_conflict__Tidy(&DAT_10011918,'\x01',0);
  return;
}



// Function: FUN_1000ab2e at 1000ab2e

void FUN_1000ab2e(void)

{
  FID_conflict__Tidy(&DAT_10011a98,'\x01',0);
  return;
}



// Function: FUN_1000ab3d at 1000ab3d

void FUN_1000ab3d(void)

{
  FID_conflict__Tidy(&DAT_10011ab4,'\x01',0);
  return;
}



// Function: FUN_1000ab4c at 1000ab4c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ab4c(void)

{
  int unaff_EBP;
  
  FUN_10009190();
  _DAT_10011afc = ATL::CComModule::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10006028(0x10011afc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000ab7a at 1000ab7a

void FUN_1000ab7a(void)

{
  FUN_10008f07((int *)&DAT_10011b2c);
  return;
}



// Function: FUN_1000ab84 at 1000ab84

void FUN_1000ab84(void)

{
  FUN_10008fe9(0x10011b54);
  return;
}



// Function: FUN_1000ab8e at 1000ab8e

void FUN_1000ab8e(void)

{
  FUN_100090ca();
  return;
}



