/*
 * Decompiled from: FuelSystemTableResetGTIS45.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void FUN_10001000(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_100268b0);
}



// Function: AtlThrowLastWin32 at 10001018

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
  FUN_10001000(DVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: _AtlGetStringResourceImage at 10001033

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



// Function: AtlGetStringResourceImage at 1000108e

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



// Function: FUN_100010be at 100010be

ATLSTRINGRESOURCEIMAGE * __cdecl FUN_100010be(uint param_1)

{
  HINSTANCE__ *pHVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  int iVar3;
  
  pAVar2 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_1003133c,0);
  iVar3 = 1;
  while ((pHVar1 != (HINSTANCE__ *)0x0 && (pAVar2 == (ATLSTRINGRESOURCEIMAGE *)0x0))) {
    pAVar2 = ATL::AtlGetStringResourceImage(pHVar1,param_1);
    pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_1003133c,iVar3);
    iVar3 = iVar3 + 1;
  }
  return pAVar2;
}



// Function: FUN_100010fd at 100010fd

int * FUN_100010fd(int *param_1,int *param_2)

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



// Function: FUN_10001130 at 10001130

undefined4 __thiscall FUN_10001130(void *this,uint param_1,uint param_2,uint param_3)

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



// Function: FUN_1000117f at 1000117f

bool __cdecl FUN_1000117f(uint param_1,int *param_2)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  int iVar2;
  
  pAVar1 = FUN_100010be(param_1);
  if (pAVar1 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    *param_2 = 0;
  }
  else {
    iVar2 = Ordinal_4(pAVar1 + 2,*(undefined2 *)pAVar1);
    *param_2 = iVar2;
  }
  return *param_2 != 0;
}



// Function: FUN_100011b2 at 100011b2

void __fastcall FUN_100011b2(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_100011e0 at 100011e0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_100011e0(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10001239 at 10001239

int * __thiscall FUN_10001239(void *this,int param_1)

{
  int iVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  iVar1 = Ordinal_2(param_1);
  *(int *)this = iVar1;
  if ((iVar1 == 0) && (param_1 != 0)) {
    FUN_10017040(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_1000126f at 1000126f

void __fastcall FUN_1000126f(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  return;
}



// Function: FUN_1000128f at 1000128f

void __fastcall FUN_1000128f(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_100012a9 at 100012a9

void __thiscall FUN_100012a9(void *this)

{
  (**(code **)(*(int *)((int)this + 0x28) + 4))(0x53,0,0);
  return;
}



// Function: FUN_100012c1 at 100012c1

void __thiscall FUN_100012c1(void *this,WPARAM param_1)

{
                    /* WARNING: Load size is inaccurate */
  SendMessageW(*this,0x170,param_1,0);
  return;
}



// Function: FID_conflict:_Inside at 100012da

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



// Function: FUN_10001316 at 10001316

void __cdecl FUN_10001316(int *param_1,size_t param_2,void *param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int *unaff_ESI;
  undefined4 uVar3;
  
  if (param_1 != (int *)0x0) goto LAB_1000132c;
  do {
    uVar3 = 0x80070057;
    while( true ) {
      FUN_10001000(uVar3);
LAB_1000132c:
      if (((int)param_2 < 0) || (param_3 == (void *)0x0)) break;
      pvVar2 = (void *)*param_1;
      if (pvVar2 == param_3) {
        if ((int)param_2 <= param_4) goto LAB_10001365;
        pvVar2 = calloc(param_2,2);
LAB_10001380:
        *param_1 = (int)pvVar2;
LAB_10001367:
        iVar1 = *param_1;
        param_1 = unaff_ESI;
        if (iVar1 != 0) {
          return;
        }
      }
      else {
        if ((int)param_2 <= param_4) {
          free(pvVar2);
LAB_10001365:
          *param_1 = (int)param_3;
          goto LAB_10001367;
        }
        pvVar2 = _recalloc(pvVar2,param_2,2);
        if (pvVar2 != (void *)0x0) goto LAB_10001380;
      }
      uVar3 = 0x8007000e;
    }
  } while( true );
}



// Function: FUN_10001384 at 10001384

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001384(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001390;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10026910);
}



// Function: FUN_10001415 at 10001415

void __fastcall FUN_10001415(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_1000141c at 1000141c

undefined4 * __thiscall FUN_1000141c(void *this,byte param_1)

{
  FUN_10001415((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000143b at 1000143b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

LPWSTR __cdecl FUN_1000143b(LPCSTR param_1,int param_2)

{
  int cchWideChar;
  LPWSTR lpWideCharStr;
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
LAB_100014ac:
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
        FUN_1000128f(local_14);
        goto LAB_100014ac;
      }
    }
    local_8 = 0xffffffff;
    FUN_1000128f(local_14);
  }
  return lpWideCharStr;
}



// Function: FUN_100014c5 at 100014c5

int * __thiscall FUN_100014c5(void *this,int param_1)

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
      FUN_10001000(0x8007000e);
    }
    *(undefined4 *)this = 0;
  }
  return (int *)this;
}



// Function: Copy at 10001502

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



// Function: FUN_1000151f at 1000151f

void __thiscall FUN_1000151f(void *this,uint param_1)

{
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  FUN_1000117f(param_1,(int *)this);
  return;
}



// Function: CComBSTR at 10001540

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(char const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,char *param_1)

{
  LPWSTR pWVar1;
  
  if (param_1 != (char *)0x0) {
    pWVar1 = FUN_1000143b(param_1,-1);
    *(LPWSTR *)this = pWVar1;
    if (pWVar1 != (LPWSTR)0x0) {
      return this;
    }
    FUN_10001000(0x8007000e);
  }
  *(undefined4 *)this = 0;
  return this;
}



// Function: FUN_10001572 at 10001572

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10001572(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10001218);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_100015cf at 100015cf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100015cf(void *this,int param_1)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_10001239(this_00,param_1);
  }
  *(int **)this = piVar1;
  if (piVar1 == (int *)0x0) {
    FUN_10017040(0x8007000e);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000161c at 1000161c

undefined4 __thiscall FUN_1000161c(void *this,undefined4 param_1,ushort param_2)

{
  EndDialog(*(HWND *)((int)this + 4),(uint)param_2);
  return 0;
}



// Function: FID_conflict:_Tidy at 10001633

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



// Function: FUN_1000167c at 1000167c

void __fastcall FUN_1000167c(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: Init at 1000168e

/* Library Function - Single Match
    private: void __thiscall ATL::CA2WEX<128>::Init(char const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

void __thiscall ATL::CA2WEX<128>::Init(CA2WEX<128> *this,char *param_1,uint param_2)

{
  size_t cbMultiByte;
  int iVar1;
  DWORD DVar2;
  size_t cchWideChar;
  bool bVar3;
  
  if (param_1 == (char *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
    cbMultiByte = iVar1 + 1;
    FUN_10001316((int *)this,cbMultiByte,this + 4,0x80);
    iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*(LPWSTR *)this,cbMultiByte);
    bVar3 = iVar1 == 0;
    if (bVar3) {
      DVar2 = GetLastError();
      if (DVar2 == 0x7a) {
        cchWideChar = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,(LPWSTR)0x0,0);
        FUN_10001316((int *)this,cchWideChar,this + 4,0x80);
        iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*(LPWSTR *)this,cchWideChar);
        bVar3 = iVar1 == 0;
      }
      if (bVar3) {
        AtlThrowLastWin32();
      }
    }
  }
  return;
}



// Function: FUN_1000173f at 1000173f

void __fastcall FUN_1000173f(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: CComBSTR at 10001757

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(class ATL::CComBSTR const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = Copy(param_1);
  *(wchar_t **)this = pwVar1;
  if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
    FUN_10001000(0x8007000e);
  }
  return this;
}



// Function: FUN_10001785 at 10001785

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10001785(void *this,int *param_1,int *param_2)

{
  if (*(int **)((int)this + 0x5c) != param_1) {
    FUN_100010fd((int *)((int)this + 0x5c),param_1);
  }
  if (*(int **)((int)this + 0x60) != param_2) {
    FUN_100010fd((int *)((int)this + 0x60),param_2);
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



// Function: ~basic_string<> at 100017e6

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



// Function: FUN_100017f0 at 100017f0

undefined4 * __thiscall FUN_100017f0(void *this,uint param_1,uint param_2)

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



// Function: FUN_10001871 at 10001871

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10001871(void *this,uint param_1)

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
  FUN_10001384((char *)(param_1 + 1));
  FUN_10001906();
  return;
}



// Function: Catch@100018d8 at 100018d8

undefined * Catch_100018d8(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001384((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001900;
}



// Function: FUN_10001906 at 10001906

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001906(void)

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



// Function: Catch@10001954 at 10001954

void Catch_10001954(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001969 at 10001969

LONG __fastcall FUN_10001969(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    FUN_1000126f(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



// Function: FUN_10001994 at 10001994

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001994(undefined4 *param_1)

{
  *param_1 = CComErrorHandlerException::vftable;
  FID_conflict__Tidy(param_1 + 4,'\x01',0);
  return;
}



// Function: FUN_100019bf at 100019bf

undefined4 * __thiscall FUN_100019bf(void *this,byte param_1)

{
  FUN_10001994((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100019de at 100019de

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100019de(ushort param_1)

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
  undefined1 local_114 [268];
  undefined4 local_8;
  undefined4 uStack_4;
  
  hModule = DAT_10031344;
  uStack_4 = 0x23c;
  local_8 = 0x100019ed;
  local_220 = (ushort *)0x1;
  hResInfo = FindResourceW(DAT_10031344,(LPCWSTR)(uint)param_1,(LPCWSTR)0xf0);
  if ((hResInfo != (HRSRC)0x0) &&
     (hResData = LoadResource(hModule,hResInfo), hResData != (HGLOBAL)0x0)) {
    puVar2 = (ushort *)LockResource(hResData);
    puVar4 = puVar2;
    while ((puVar4 != (ushort *)0x0 && (uVar1 = *puVar2, uVar1 != 0))) {
      local_228 = *(int *)(puVar2 + 2);
      puVar4 = puVar2 + 4;
      if (puVar2[1] == 0x403) {
        local_21c = local_218;
        ATL::CA2WEX<128>::Init((CA2WEX<128> *)&local_21c,(char *)puVar4,3);
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
        local_248 = 0xffffffff;
        local_118 = local_114;
        local_24c = 1;
        ATL::CA2WEX<128>::Init((CA2WEX<128> *)&local_118,(char *)puVar4,3);
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
  FUN_100172f7();
  return;
}



// Function: FUN_10001b8a at 10001b8a

bool __thiscall FUN_10001b8a(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001871(this,param_1);
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



// Function: FUN_10001bf4 at 10001bf4

undefined4 * __thiscall FUN_10001bf4(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_100017f0(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_100017f0(this,0,param_2);
  }
  else {
    bVar1 = FUN_10001b8a(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 10001c90

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
    bVar1 = FUN_10001b8a(this,param_2,'\0');
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
    this = FUN_10001bf4(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: basic_string<> at 10001d0e

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
  FUN_10001bf4(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: FUN_10001d36 at 10001d36

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10001d36(void *this,int param_1)

{
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  basic_string<>((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  return (undefined4 *)this;
}



// Function: FUN_10001d86 at 10001d86

undefined2 * __thiscall FUN_10001d86(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10001db8 at 10001db8

undefined4 * __thiscall FUN_10001db8(void *this,undefined4 *param_1)

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



// Function: FUN_10001e15 at 10001e15

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_10001e15(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
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



// Function: FUN_10001e7c at 10001e7c

void __thiscall FUN_10001e7c(void *this,undefined4 *param_1)

{
  FUN_10001bf4((void *)((int)this + 0x40),param_1,0,0xffffffff);
  return;
}



// Function: basic_string<> at 10001e92

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
  FUN_10001db8(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_10001eb7 at 10001eb7

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10001eb7(undefined2 *param_1,uint param_2)

{
  undefined4 *puVar1;
  wchar_t *local_3c;
  char local_35;
  undefined1 local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_3c = (wchar_t *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_35 = FUN_1000151f(&local_3c,param_2);
  if (local_35 == '\0') {
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_35,(ThrowInfo *)&DAT_10026b4c);
  }
  puVar1 = (undefined4 *)FUN_10001d86(local_34,local_3c);
  local_8._0_1_ = 3;
  FUN_10001db8(param_1,puVar1);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_3c);
  local_8 = 0;
  FUN_10001f56();
  return;
}



// Function: Catch@10001f49 at 10001f49

undefined * Catch_10001f49(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10001f53;
}



// Function: FUN_10001f56 at 10001f56

void FUN_10001f56(void)

{
  FUN_10017306();
  return;
}



// Function: FUN_10001f5e at 10001f5e

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10001f5e(void *this)

{
  LPCWSTR pWVar1;
  HWND pHVar2;
  HWND pHVar3;
  HICON pHVar4;
  undefined4 *in_stack_00000010;
  
  FUN_100019de(100);
  *in_stack_00000010 = 0;
  pWVar1 = (LPCWSTR)FUN_10001eb7((undefined2 *)&stack0xffffffcc,0x79);
  if (7 < *(uint *)(pWVar1 + 10)) {
    pWVar1 = *(LPCWSTR *)pWVar1;
  }
  SetWindowTextW(*(HWND *)((int)this + 4),pWVar1);
  FID_conflict__Tidy(&stack0xffffffcc,'\x01',0);
  pWVar1 = (LPCWSTR)FUN_10001eb7((undefined2 *)&stack0xffffffcc,0x81);
  if (7 < *(uint *)(pWVar1 + 10)) {
    pWVar1 = *(LPCWSTR *)pWVar1;
  }
  pHVar2 = GetDlgItem(*(HWND *)((int)this + 4),9);
  SetWindowTextW(pHVar2,pWVar1);
  FID_conflict__Tidy(&stack0xffffffcc,'\x01',0);
  FUN_10001eb7((undefined2 *)&stack0xffffffcc,0x86);
  pHVar2 = *(HWND *)((int)this + 4);
  pHVar3 = GetDlgItem(pHVar2,1);
  SetWindowTextW(pHVar3,(LPCWSTR)pHVar2);
  FID_conflict__Tidy(&stack0xffffffcc,'\x01',0);
  pHVar2 = *(HWND *)((int)this + 4);
  pHVar3 = GetDlgItem(pHVar2,0x6e);
  SetWindowTextW(pHVar3,(LPCWSTR)pHVar2);
  pHVar2 = GetDlgItem(*(HWND *)((int)this + 4),0x6c);
  *(HWND *)((int)this + 0x3c) = pHVar2;
  FUN_10001130((void *)((int)this + 0x3c),0,3,0);
  pHVar4 = LoadIconW(DAT_10031344,(LPCWSTR)0x5);
  FUN_100012c1((void *)((int)this + 0x3c),(WPARAM)pHVar4);
  FUN_10017306();
  return;
}



// Function: Catch@10002088 at 10002088

undefined4 Catch_10002088(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000207d;
}



// Function: FUN_10002092 at 10002092

void __thiscall FUN_10002092(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 < 0)) {
    *(undefined1 *)this = 1;
    FUN_1000c8e5(param_1,*(undefined4 *)((int)this + 4));
  }
  return;
}



// Function: FUN_100020b2 at 100020b2

int __thiscall FUN_100020b2(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_10002092((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_100020ce at 100020ce

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100020ce(void *this,undefined4 *param_1)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  undefined4 local_38 [3];
  undefined4 uStack_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_1c = (int *)0x0;
  local_18[0] = (int *)0x0;
  local_28 = (int *)0x0;
  local_8._1_3_ = 0;
  local_24 = (int *)0x0;
  local_8._0_1_ = 7;
  FUN_1000173f(local_38);
  if (*(int *)((int)this + 0xc) != 0) {
    local_8._0_1_ = 9;
    iVar1 = (**(code **)**(undefined4 **)((int)this + 0xc))
                      (*(undefined4 **)((int)this + 0xc),&DAT_100209c0,&local_24);
    FUN_100020b2(local_38,iVar1);
    local_20 = (int *)0x0;
    local_8._0_1_ = 0xb;
    iVar1 = (**(code **)(*local_24 + 0x20))(local_24,&local_20);
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)*local_20)(local_20,&DAT_10020a1c,&local_28);
    FUN_100020b2(local_38,iVar1);
    HVar2 = CoCreateInstance((IID *)&DAT_100209b0,(LPUNKNOWN)0x0,0x17,(IID *)&PTR_10020a0c,&local_1c
                            );
    FUN_100020b2(local_38,HVar2);
    iVar1 = (**(code **)*local_1c)(local_1c,&DAT_10020a2c,local_18);
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)(*local_18[0] + 0x10))(local_18[0],*param_1);
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)(*local_18[0] + 0x20))(local_18[0],*(undefined4 *)((int)this + 4));
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)(*local_28 + 0xc))(local_28,local_1c);
    FUN_100020b2(local_38,iVar1);
    local_8 = CONCAT31(local_8._1_3_,9);
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
    local_8 = 8;
    uVar3 = FUN_10002214();
    return uVar3;
  }
  local_8._0_1_ = 5;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  local_8._0_1_ = 3;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return uStack_2c;
}



// Function: Catch@10002205 at 10002205

undefined * Catch_10002205(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 8;
  return &DAT_10002212;
}



// Function: FUN_10002214 at 10002214

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10002214(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_EDI;
  
  *(undefined1 *)(unaff_EBP + -4) = 5;
  piVar1 = *(int **)(unaff_EBP + -0x20);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  piVar1 = *(int **)(unaff_EBP + -0x24);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + -0x18);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return *(undefined4 *)(unaff_EBP + -0x28);
}



// Function: FUN_10002263 at 10002263

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10002263(void *this)

{
  int iVar1;
  undefined4 *in_stack_00000010;
  undefined4 uStack_4c;
  undefined4 local_30 [3];
  int local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x1000226f;
  FUN_1000173f(local_30);
  local_1c = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 8))();
  uStack_4c = 0x1000229d;
  FUN_100020b2(local_30,iVar1);
  local_18[0] = 0;
  local_8._0_1_ = 3;
  local_20 = (undefined1 *)&uStack_4c;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&uStack_4c,(CComBSTR *)&local_1c);
                    /* WARNING: Load size is inaccurate */
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = (**(code **)(*this + 0xc))();
  FUN_100020b2(local_30,iVar1);
  if (local_24 == 0) {
    iVar1 = FUN_100020ce(this,local_18);
    FUN_100020b2(local_30,iVar1);
  }
  local_8._0_1_ = 2;
  Ordinal_6(local_18[0]);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_1c);
  *in_stack_00000010 = 1;
  return local_24;
}



// Function: Catch@1000231b at 1000231b

undefined4 Catch_1000231b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10002303;
}



// Function: FUN_10002325 at 10002325

void __fastcall FUN_10002325(void *param_1)

{
  if (*(int **)((int)param_1 + 8) != *(int **)((int)param_1 + 0x34)) {
    FUN_100010fd((int *)((int)param_1 + 8),*(int **)((int)param_1 + 0x34));
  }
  if (*(int **)((int)param_1 + 0xc) != *(int **)((int)param_1 + 0x38)) {
    FUN_100010fd((int *)((int)param_1 + 0xc),*(int **)((int)param_1 + 0x38));
  }
  FUN_10002263(param_1);
  return;
}



// Function: _InlineIsEqualGUID at 10002365

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



// Function: FUN_10002395 at 10002395

bool __cdecl FUN_10002395(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 100023af

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



// Function: AtlCoTaskMemCAlloc at 100023d1

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



// Function: FUN_100023fe at 100023fe

LPVOID __cdecl FUN_100023fe(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_1000242e at 1000242e

bool __cdecl FUN_1000242e(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: AtlCrtErrorCheck at 1000245b

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
    if (param_1 == 0x16) goto LAB_10002483;
    if (param_1 == 0x22) goto LAB_10002483;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_10001000(uVar1);
LAB_10002483:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_10002493 at 10002493

void __cdecl FUN_10002493(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_100024b3 at 100024b3

void __cdecl FUN_100024b3(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 100024d0

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



// Function: FUN_100024f9 at 100024f9

void __fastcall FUN_100024f9(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_1000250b at 1000250b

DWORD FUN_1000250b(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10002520 at 10002520

uint __cdecl FUN_10002520(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FID_conflict:RegOpenKeyExA at 10002536

/* Library Function - Multiple Matches With Different Base Names
    public: long __thiscall ATL::CAtlTransactionManager::RegOpenKeyExA(struct HKEY__ *,char const
   *,unsigned long,unsigned long,struct HKEY__ * *)
    public: long __thiscall ATL::CAtlTransactionManager::RegOpenKeyExW(struct HKEY__ *,wchar_t const
   *,unsigned long,unsigned long,struct HKEY__ * *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

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
                    /* WARNING: Could not recover jumptable at 0x1000257f. Too many branches */
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



// Function: FID_conflict:RegCreateKeyExW at 1000258d

/* Library Function - Multiple Matches With Different Base Names
    public: long __thiscall ATL::CAtlTransactionManager::RegCreateKeyExA(struct HKEY__ *,char const
   *,unsigned long,char *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES * const,struct
   HKEY__ * *,unsigned long *)
    public: long __thiscall ATL::CAtlTransactionManager::RegCreateKeyExW(struct HKEY__ *,wchar_t
   const *,unsigned long,wchar_t *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES *
   const,struct HKEY__ * *,unsigned long *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

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
                    /* WARNING: Could not recover jumptable at 0x100025e2. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 100025f0

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
                    /* WARNING: Could not recover jumptable at 0x10002633. Too many branches */
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



// Function: FUN_10002642 at 10002642

undefined4 __fastcall FUN_10002642(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10002646 at 10002646

void __cdecl FUN_10002646(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10002694 at 10002694

int __fastcall FUN_10002694(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: FUN_100026ab at 100026ab

void __thiscall FUN_100026ab(void *this,LPCWSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*(int *)((int)this + 8) == 0) {
    RegDeleteKeyW(*this,param_1);
  }
  else {
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: FUN_100026cd at 100026cd

LSTATUS __fastcall FUN_100026cd(undefined4 *param_1)

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



// Function: FUN_100026e8 at 100026e8

void __thiscall
FUN_100026e8(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,REGSAM param_5,
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
    FUN_100026cd((undefined4 *)this);
    *(HKEY *)this = local_8;
  }
  return;
}



// Function: FUN_10002744 at 10002744

void __thiscall FUN_10002744(void *this,HKEY param_1,LPCWSTR param_2,REGSAM param_3)

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
    FUN_100026cd((undefined4 *)this);
    *(HKEY *)this = local_8;
  }
  return;
}



// Function: SetStringValue at 10002787

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



// Function: FUN_100027be at 100027be

LSTATUS __thiscall FUN_100027be(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10002801 at 10002801

undefined4 __fastcall FUN_10002801(undefined4 *param_1)

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



// Function: FUN_10002821 at 10002821

undefined4 * __thiscall FUN_10002821(void *this,ulong param_1)

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



// Function: FUN_10002857 at 10002857

void __fastcall FUN_10002857(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10002861 at 10002861

undefined4 __thiscall FUN_10002861(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_100023fe(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10002493((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_100028ef at 100028ef

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100028ef(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x100028fb;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_1002f838 & 1) == 0) {
    DAT_1002f838 = DAT_1002f838 | 1;
    DAT_1002f81c = 8;
    _DAT_1002f824 = 0x4008;
    _DAT_1002f82c = 0x13;
    DAT_1002f818 = &DAT_10021610;
    DAT_1002f820 = &DAT_1002160c;
    _DAT_1002f828 = &DAT_10021608;
    _DAT_1002f830 = &DAT_10021604;
    _DAT_1002f834 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_1002f818)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x10002972;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_1002f81c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_1000297e;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_1000297e:
  *(undefined4 *)(puVar4 + -4) = 0x10002983;
  return uVar2;
}



// Function: FUN_10002997 at 10002997

int __cdecl FUN_10002997(ushort param_1)

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



// Function: FUN_100029cd at 100029cd

undefined4 __cdecl FUN_100029cd(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10021808)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1002180c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_100029fb at 100029fb

LPCWSTR __cdecl FUN_100029fb(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10002a28 at 10002a28

undefined4 FUN_10002a28(ushort param_1)

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



// Function: FUN_10002a4e at 10002a4e

void __fastcall FUN_10002a4e(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10002a28(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_10002a70 at 10002a70

undefined4 __thiscall FUN_10002a70(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10002a4e((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10002801((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10002a28(*pWVar2);
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



// Function: FUN_10002b86 at 10002b86

undefined4 FUN_10002b86(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_10021770;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x100217a0);
  return 1;
}



// Function: FUN_10002bb5 at 10002bb5

bool FUN_10002bb5(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10002bea at 10002bea

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10002bea(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10002a70(this,param_1), -1 < iVar1)) {
    FUN_10002a4e((undefined4 *)this);
    iVar1 = FUN_10002a70(this,local_2008);
    if (-1 < iVar1) {
      FUN_10002a70(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002c4f at 10002c4f

undefined4 FUN_10002c4f(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_1002f810;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10002c6e at 10002c6e

undefined4 __thiscall FUN_10002c6e(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_1002f1c4 = *param_3;
    DAT_1002f1c8 = param_3[1];
    DAT_1002f1cc = param_3[2];
    DAT_1002f1d0 = param_3[3];
  }
  piVar2 = DAT_1003137c;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_1003137c, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_1003137c = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_1003137c;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10031380; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10002ccc at 10002ccc

void FUN_10002ccc(int param_1)

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



// Function: FUN_10002d0f at 10002d0f

void FUN_10002d0f(void)

{
  return;
}



// Function: FUN_10002d12 at 10002d12

void __fastcall FUN_10002d12(undefined4 *param_1)

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



// Function: FUN_10002d3f at 10002d3f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10002d3f(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_1001806d;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10002d69 at 10002d69

int __thiscall FUN_10002d69(void *this,undefined4 *param_1)

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



// Function: FUN_10002da0 at 10002da0

void __fastcall FUN_10002da0(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10002daa at 10002daa

void __thiscall FUN_10002daa(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_10001000(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10002dcf

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_10001000(lVar1);
  }
  return local_8;
}



// Function: DllCanUnloadNow at 10002df4

HRESULT DllCanUnloadNow(void)

{
                    /* 0x2df4  1  DllCanUnloadNow */
  return (uint)(DAT_1002ff5c != 0);
}



// Function: FUN_10002e03 at 10002e03

void __fastcall FUN_10002e03(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10002e18 at 10002e18

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10002e18(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10002e46 at 10002e46

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10002e46(undefined4 *param_1)

{
  FUN_10013c29((int)param_1);
  *param_1 = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[9] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[10] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x1a] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x1c] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x1d] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x37] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x3c] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  (**(code **)(*DAT_1002f1c0 + 4))();
  return param_1;
}



// Function: FUN_10002ebd at 10002ebd

short * __cdecl FUN_10002ebd(short *param_1,short param_2,int param_3)

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



// Function: FUN_10002ede at 10002ede

int __cdecl FUN_10002ede(ushort *param_1,ushort *param_2,int param_3)

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



// Function: FUN_10002f12 at 10002f12

void __thiscall
FUN_10002f12(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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



// Function: AtlComQIPtrAssign at 10002f4a

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



// Function: FUN_10002f81 at 10002f81

int * __thiscall FUN_10002f81(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: Attach at 10002fa7

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



// Function: FUN_10002fc6 at 10002fc6

int __thiscall FUN_10002fc6(void *this,undefined4 param_1)

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



// Function: FUN_10003008 at 10003008

void __cdecl FUN_10003008(wchar_t *param_1,ushort param_2,uint *param_3,uint *param_4)

{
  HDC hdc;
  int nNumerator;
  errno_t eVar1;
  uint uVar2;
  int nDenominator;
  tagSIZE local_b4;
  HGDIOBJ local_ac;
  HFONT local_a8;
  uint *local_a4;
  tagTEXTMETRICW local_a0;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
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
      eVar1 = wcsncpy_s(local_64.lfFaceName,0x20,param_1,0xffffffff);
      ATL::AtlCrtErrorCheck(eVar1);
      local_a8 = CreateFontIndirectW(&local_64);
      if (local_a8 != (HFONT)0x0) {
        local_ac = SelectObject(hdc,local_a8);
        GetTextMetricsW(hdc,&local_a0);
        GetTextExtentPointW(hdc,L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",0x34,
                            &local_b4);
        SelectObject(hdc,local_ac);
        DeleteObject(local_a8);
        *local_a4 = local_a0.tmHeight;
        param_3[1] = local_a0.tmExternalLeading + local_a0.tmHeight;
        *param_3 = (local_b4.cx + 0x1a) / 0x34;
        ReleaseDC((HWND)0x0,hdc);
        goto LAB_10003149;
      }
      ReleaseDC((HWND)0x0,hdc);
    }
  }
  uVar2 = GetDialogBaseUnits();
  *param_3 = uVar2 & 0xffff;
  param_3[1] = uVar2 >> 0x10;
  *local_a4 = uVar2 >> 0x10;
LAB_10003149:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: HasFont at 10003158

/* Library Function - Single Match
    int __cdecl HasFont(struct DLGTEMPLATE const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

int __cdecl HasFont(DLGTEMPLATE *param_1)

{
  uint uVar1;
  
  if (*(short *)((int)&param_1->style + 2) == -1) {
    uVar1._0_2_ = param_1->y;
    uVar1._2_2_ = param_1->cx;
  }
  else {
    uVar1 = param_1->style;
  }
  return uVar1 & 0x40;
}



// Function: GetFontSizeField at 10003175

/* Library Function - Single Match
    protected: static unsigned char * __cdecl CDialogTemplate::GetFontSizeField(struct DLGTEMPLATE
   const *)
   
   Library: Visual Studio 2010 Release */

uchar * __cdecl CDialogTemplate::GetFontSizeField(DLGTEMPLATE *param_1)

{
  DWORD *pDVar1;
  DLGTEMPLATE *pDVar2;
  
  if (*(short *)((int)&param_1->style + 2) == -1) {
    pDVar2 = (DLGTEMPLATE *)&param_1[1].cdit;
  }
  else {
    pDVar2 = param_1 + 1;
  }
  if ((WORD)pDVar2->style == 0xffff) {
    pDVar2 = (DLGTEMPLATE *)&pDVar2->dwExtendedStyle;
  }
  else {
    do {
      pDVar1 = &pDVar2->style;
      pDVar2 = (DLGTEMPLATE *)((int)&pDVar2->style + 2);
    } while ((WORD)*pDVar1 != 0);
  }
  if ((WORD)pDVar2->style == 0xffff) {
    pDVar2 = (DLGTEMPLATE *)&pDVar2->dwExtendedStyle;
  }
  else {
    do {
      pDVar1 = &pDVar2->style;
      pDVar2 = (DLGTEMPLATE *)((int)&pDVar2->style + 2);
    } while ((WORD)*pDVar1 != 0);
  }
  do {
    pDVar1 = &pDVar2->style;
    pDVar2 = (DLGTEMPLATE *)((int)&pDVar2->style + 2);
  } while ((WORD)*pDVar1 != 0);
  return (uchar *)pDVar2;
}



// Function: FUN_100031c7 at 100031c7

void __cdecl FUN_100031c7(int param_1,int *param_2)

{
  short sVar1;
  
  if (*(short *)(param_1 + 2) == -1) {
    *param_2 = (int)*(short *)(param_1 + 0x16);
    sVar1 = *(short *)(param_1 + 0x18);
  }
  else {
    *param_2 = (int)*(short *)(param_1 + 0xe);
    sVar1 = *(short *)(param_1 + 0x10);
  }
  param_2[1] = (int)sVar1;
  return;
}



// Function: InlineIsEqualUnknown at 100031f6

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



// Function: QueryStringValue at 10003224

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
              (*(short *)((int)param_2 + ((local_8 & 0xfffffffe) - 2)) != 0)) goto LAB_10003260;
    }
    *puVar2 = local_8 >> 1;
    lVar4 = 0;
  }
  else {
LAB_10003260:
    lVar4 = 0xd;
  }
  return lVar4;
}



// Function: AtlInternalQueryInterface at 10003293

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
          if (pcVar1 == (code *)0x1) goto LAB_100032c7;
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
LAB_100032c7:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10003334 at 10003334

undefined4 __thiscall FUN_10003334(void *this,int param_1,undefined4 param_2)

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



// Function: FUN_10003369 at 10003369

void __thiscall FUN_10003369(void *this,int param_1,undefined4 param_2)

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
  FUN_10003334(*this,param_1,param_2);
  return;
}



// Function: AtlAdd<> at 100033ba

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



// Function: FUN_100033de at 100033de

undefined4 __thiscall FUN_100033de(void *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    uVar1 = *(undefined4 *)((int)this + 0x30);
  }
  else if (param_1 == 2) {
    uVar1 = *(undefined4 *)((int)this + 0x34);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100033fa at 100033fa

int FUN_100033fa(undefined4 param_1,int param_2)

{
  return (uint)(param_2 == 0) * 2 + -0x7fffbfff;
}



// Function: FUN_10003410 at 10003410

undefined4 FUN_10003410(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x28;
  }
  if (param_2 == (int *)0x0) {
    piVar1 = *(int **)(iVar2 + 0x2c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x2c) != 0) {
      return 0x8000ffff;
    }
    *(int **)(iVar2 + 0x2c) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
  }
  return 0;
}



// Function: FUN_10003459 at 10003459

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003459(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x28;
  }
  if (param_3 == 0) {
    return 0x80004003;
  }
  if ((*(int *)(iVar3 + 0x30) != 0) && (*(int *)(iVar3 + 0x34) != 0)) {
    uVar4 = 0;
    if (*(int *)(iVar3 + 0x34) != 0) {
      do {
        piVar1 = *(int **)(*(int *)(iVar3 + 0x30) + uVar4 * 4);
        (**(code **)(*piVar1 + 8))(piVar1);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar3 + 0x34));
    }
    operator_delete__(*(void **)(iVar3 + 0x30));
  }
  *(undefined4 *)(iVar3 + 0x30) = 0;
  uVar2 = FUN_10017151(-(uint)((int)((ulonglong)param_2 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)param_2 * 4));
  *(undefined4 *)(iVar3 + 0x30) = uVar2;
  uVar2 = FUN_100034ea();
  return uVar2;
}



// Function: Catch@100034db at 100034db

undefined * Catch_100034db(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100034e5;
}



// Function: FUN_100034ea at 100034ea

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100034ea(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  uint uVar5;
  
  if (*(int *)(unaff_ESI + 0x30) == unaff_EBX) {
    uVar4 = 0x8007000e;
  }
  else {
    uVar5 = 0;
    uVar2 = *(uint *)(unaff_EBP + 0xc);
    if (uVar2 != 0) {
      do {
        puVar1 = (undefined4 *)(*(int *)(unaff_EBP + 0x10) + uVar5 * 4);
        *(undefined4 **)(unaff_EBP + 0xc) = puVar1;
        piVar3 = (int *)*puVar1;
        (**(code **)(*piVar3 + 4))(piVar3);
        *(undefined4 *)(*(int *)(unaff_ESI + 0x30) + uVar5 * 4) = **(undefined4 **)(unaff_EBP + 0xc)
        ;
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    *(uint *)(unaff_ESI + 0x34) = uVar2;
    uVar4 = 0;
  }
  return uVar4;
}



// Function: FUN_1000352d at 1000352d

undefined4 FUN_1000352d(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x28;
  }
  if (*(HWND *)(iVar1 + 8) == (HWND)0x0) {
    uVar2 = 0x8000ffff;
  }
  else {
    ShowWindow(*(HWND *)(iVar1 + 8),param_2);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000355c at 1000355c

undefined4 FUN_1000355c(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x28;
  }
  if (*(HWND *)(iVar1 + 8) == (HWND)0x0) {
    uVar2 = 0x8000ffff;
  }
  else if (param_2 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    MoveWindow(*(HWND *)(iVar1 + 8),*param_2,param_2[1],param_2[2] - *param_2,
               param_2[3] - param_2[1],1);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_100035af at 100035af

bool FUN_100035af(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x28;
  }
  return *(int *)(iVar1 + 0x50) == 0;
}



// Function: FUN_100035ce at 100035ce

bool FUN_100035ce(int param_1,LPMSG param_2)

{
  uint uVar1;
  char cVar2;
  BOOL BVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_1 + -0x28;
  }
  uVar1 = param_2->message;
  if (((uVar1 < 0x100) || (0x109 < uVar1)) && ((uVar1 < 0x200 || (0x20e < uVar1)))) {
    cVar2 = '\x01';
  }
  else {
    BVar3 = IsDialogMessageW(*(HWND *)(iVar4 + 8),param_2);
    cVar2 = '\x01' - (BVar3 != 0);
  }
  return (bool)cVar2;
}



// Function: FUN_10003619 at 10003619

undefined4 __fastcall FUN_10003619(int param_1)

{
  BOOL BVar1;
  
  if (((DAT_10031344 != (HMODULE)0x0) && (*(int *)(param_1 + 4) == 1)) &&
     (BVar1 = FreeLibrary(DAT_10031344), BVar1 != 1)) {
    return 0x80004005;
  }
  return 0;
}



// Function: FUN_10003642 at 10003642

undefined4 FUN_10003642(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_1000365f at 1000365f

uint __thiscall FUN_1000365f(void *this,ushort *param_1,uint param_2,uint param_3)

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
        if ((*puVar6 == uVar1) && (iVar4 = FUN_10002ede(puVar6,param_1,param_3), iVar4 == 0)) {
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



// Function: FUN_100036eb at 100036eb

undefined4 FUN_100036eb(int param_1)

{
  *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;
  return *(undefined4 *)(param_1 + 0xf4);
}



// Function: FUN_10003701 at 10003701

undefined4 FUN_10003701(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0xf4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0xf4);
  if ((*piVar1 == 0) && (param_1 != 0)) {
    (**(code **)(*(int *)(param_1 + 4) + 4))(1);
  }
  return uVar2;
}



// Function: FUN_1000372b at 1000372b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000372b(undefined4 *param_1)

{
  FUN_1000c848(param_1);
  *param_1 = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[6] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[7] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  (**(code **)(*DAT_1002f1c0 + 4))();
  return param_1;
}



// Function: FUN_10003780 at 10003780

undefined2 __fastcall FUN_10003780(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x18))();
  return *(undefined2 *)(&DAT_10021640 + (uVar1 & 0xffff) * 2);
}



// Function: FUN_10003791 at 10003791

void FUN_10003791(int param_1)

{
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_100313a0);
    InterlockedExchange(&DAT_10031344,param_1);
    DAT_10031340 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_100313a0);
  }
  return;
}



// Function: FUN_100037c8 at 100037c8

undefined4 FUN_100037c8(void)

{
  return DAT_10031344;
}



// Function: FUN_100037ce at 100037ce

undefined4 * __thiscall FUN_100037ce(void *this,int *param_1)

{
  int *piVar1;
  
  *(int **)this = param_1;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return (undefined4 *)this;
}



// Function: FUN_100037f4 at 100037f4

void __fastcall FUN_100037f4(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x10003807. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_1000380b at 1000380b

void __fastcall FUN_1000380b(int param_1)

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



// Function: FUN_10003848 at 10003848

void FUN_10003848(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x28));
  return;
}



// Function: FUN_1000385c at 1000385c

LONG FUN_1000385c(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x28));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_1000388a at 1000388a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000388a(int param_1)

{
  FUN_10013cee(param_1);
  return;
}



// Function: FUN_100038a8 at 100038a8

uint FUN_100038a8(byte param_1)

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



// Function: FUN_100038d4 at 100038d4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100038d4(void *this,undefined4 param_1)

{
  FUN_10013c29((int)this);
  *(undefined ***)this =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 4) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 0x24) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 0x28) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 0x68) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 0x70) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 0x74) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 0xdc) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined ***)((int)this + 0xf0) =
       ATL::CComContainedObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  *(undefined4 *)((int)this + 0xf4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10003949 at 10003949

void FUN_10003949(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xf4) + 4))(*(int **)(param_1 + 0xf4));
  return;
}



// Function: FUN_1000395f at 1000395f

void FUN_1000395f(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xf4) + 8))(*(int **)(param_1 + 0xf4));
  return;
}



// Function: FUN_10003975 at 10003975

void FUN_10003975(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xf4))(*(undefined4 **)(param_1 + 0xf4),param_2,param_3);
  return;
}



// Function: FUN_10003990 at 10003990

uint __thiscall FUN_10003990(void *this,uint param_1)

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



// Function: FUN_100039bf at 100039bf

int FUN_100039bf(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined1 local_28 [36];
  
  uVar3 = param_2;
  piVar2 = param_1;
  FUN_10002f12(local_28,param_1[1],param_2,param_3,param_4,1);
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



// Function: FUN_10003a90 at 10003a90

undefined4 __thiscall FUN_10003a90(void *this,undefined4 param_1,undefined4 param_2,int param_3)

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



// Function: FUN_10003ae4 at 10003ae4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10003ae4(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10003af0;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10026910);
}



// Function: FUN_10003b43 at 10003b43

uint __thiscall FUN_10003b43(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
  uVar1 = FUN_10002ede((ushort *)((int)this + param_1 * 2),param_3,uVar1);
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



// Function: FUN_10003ba7 at 10003ba7

void __fastcall FUN_10003ba7(int param_1)

{
  LPRECT lpRect;
  HWND hWnd;
  int iVar1;
  
  iVar1 = __RTDynamicCast(param_1,0,
                          &CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::
                           RTTI_Type_Descriptor,
                          &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar1 + 8);
  lpRect = (LPRECT)(param_1 + 0x44);
  GetClientRect(hWnd,lpRect);
  InvalidateRect(hWnd,lpRect,1);
  lpRect->left = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x54);
  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x58);
  UpdateWindow(hWnd);
  return;
}



// Function: FUN_10003bf7 at 10003bf7

void FUN_10003bf7(int param_1)

{
  FUN_1000395f(param_1 + -0x24);
  return;
}



// Function: FUN_10003c01 at 10003c01

void FUN_10003c01(int param_1)

{
  FUN_100036eb(param_1 + -0xf0);
  return;
}



// Function: FUN_10003c0e at 10003c0e

void __thiscall FUN_10003c0e(void *this,byte param_1)

{
  FUN_10003c19((void *)((int)this + -0xdc),param_1);
  return;
}



// Function: FUN_10003c19 at 10003c19

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10003c19(void *this,byte param_1)

{
  FUN_10013cee((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10003c4a at 10003c4a

void FUN_10003c4a(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003975(param_1 + -0x70,param_2,param_3);
  return;
}



// Function: FUN_10003c54 at 10003c54

void __thiscall FUN_10003c54(void *this,byte param_1)

{
  FUN_10003c19((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10003c5c at 10003c5c

void __thiscall FUN_10003c5c(void *this,byte param_1)

{
  FUN_10003cbe((void *)((int)this + -0x1c),param_1);
  return;
}



// Function: FUN_10003c64 at 10003c64

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003c64(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[6] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[7] = ATL::CComObject<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  param_1[10] = 0xc0000001;
  (**(code **)(*DAT_1002f1c0 + 8))();
  FUN_1000c897((int)param_1);
  return;
}



// Function: FUN_10003cbe at 10003cbe

undefined4 * __thiscall FUN_10003cbe(void *this,byte param_1)

{
  FUN_10003c64((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003cdd at 10003cdd

void FUN_10003cdd(int param_1)

{
  FUN_1000385c(param_1 + -0x1c);
  return;
}



// Function: FUN_10003ce7 at 10003ce7

void FUN_10003ce7(int param_1)

{
  FUN_1000395f(param_1 + -0x28);
  return;
}



// Function: FUN_10003cf1 at 10003cf1

void FUN_10003cf1(int param_1)

{
  FUN_10003701(param_1 + -0x24);
  return;
}



// Function: FUN_10003cfb at 10003cfb

void FUN_10003cfb(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003975(param_1 + -0xf0,param_2,param_3);
  return;
}



// Function: FUN_10003d08 at 10003d08

void __thiscall FUN_10003d08(void *this,byte param_1)

{
  FUN_10003d92((void *)((int)this + -0xdc),param_1);
  return;
}



// Function: FUN_10003d13 at 10003d13

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003d13(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[9] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[10] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x1a] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x1c] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x1d] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x37] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x3c] = ATL::CComObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0x3d] = 0xc0000001;
  (**(code **)(*DAT_1002f1c0 + 8))();
  FUN_10013cee((int)param_1);
  return;
}



// Function: FUN_10003d92 at 10003d92

undefined4 * __thiscall FUN_10003d92(void *this,byte param_1)

{
  FUN_10003d13((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003db1 at 10003db1

void __thiscall FUN_10003db1(void *this,byte param_1)

{
  FUN_10003c19((void *)((int)this + -0x28),param_1);
  return;
}



// Function: FUN_10003db9 at 10003db9

void FUN_10003db9(int param_1)

{
  FUN_10003848(param_1 + -0x18);
  return;
}



// Function: FUN_10003dc3 at 10003dc3

void __thiscall FUN_10003dc3(void *this,byte param_1)

{
  FUN_10003d92((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10003dcb at 10003dcb

void FUN_10003dcb(int param_1)

{
  FUN_10003949(param_1 + -0x24);
  return;
}



// Function: FUN_10003dd5 at 10003dd5

void FUN_10003dd5(int param_1)

{
  FUN_10003701(param_1 + -0x28);
  return;
}



// Function: FUN_10003ddf at 10003ddf

void FUN_10003ddf(int param_1)

{
  FUN_10003848(param_1 + -0x1c);
  return;
}



// Function: FUN_10003de9 at 10003de9

void FUN_10003de9(int param_1)

{
  FUN_10003949(param_1 + -0x28);
  return;
}



// Function: FUN_10003df3 at 10003df3

void __thiscall FUN_10003df3(void *this,byte param_1)

{
  FUN_10003d92((void *)((int)this + -0x28),param_1);
  return;
}



// Function: FUN_10003dfb at 10003dfb

void FUN_10003dfb(int param_1)

{
  FUN_100036eb(param_1 + -0x24);
  return;
}



// Function: FUN_10003e05 at 10003e05

void FUN_10003e05(int param_1)

{
  FUN_1000395f(param_1 + -0x70);
  return;
}



// Function: FUN_10003e0f at 10003e0f

void FUN_10003e0f(int param_1)

{
  FUN_100036eb(param_1 + -0x28);
  return;
}



// Function: FUN_10003e19 at 10003e19

void FUN_10003e19(int param_1)

{
  FUN_1000395f(param_1 + -0xf0);
  return;
}



// Function: FUN_10003e26 at 10003e26

void FUN_10003e26(int param_1)

{
  FUN_1000385c(param_1 + -0xc);
  return;
}



// Function: FUN_10003e30 at 10003e30

void FUN_10003e30(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003975(param_1 + -0x24,param_2,param_3);
  return;
}



// Function: FUN_10003e3a at 10003e3a

void FUN_10003e3a(int param_1)

{
  FUN_10003701(param_1 + -0x70);
  return;
}



// Function: FUN_10003e44 at 10003e44

void FUN_10003e44(int param_1)

{
  FUN_10003949(param_1 + -0x70);
  return;
}



// Function: FUN_10003e4e at 10003e4e

void FUN_10003e4e(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003975(param_1 + -0x28,param_2,param_3);
  return;
}



// Function: FUN_10003e58 at 10003e58

void FUN_10003e58(int param_1)

{
  FUN_10003701(param_1 + -0xf0);
  return;
}



// Function: FUN_10003e65 at 10003e65

void FUN_10003e65(int param_1)

{
  FUN_10003949(param_1 + -0xf0);
  return;
}



// Function: FUN_10003e72 at 10003e72

void FUN_10003e72(int param_1)

{
  FUN_10003848(param_1 + -0xc);
  return;
}



// Function: FUN_10003e7c at 10003e7c

void FUN_10003e7c(int param_1)

{
  FUN_100036eb(param_1 + -0x70);
  return;
}



// Function: FUN_10003e86 at 10003e86

void FUN_10003e86(int param_1)

{
  FUN_1000385c(param_1 + -0x18);
  return;
}



// Function: FUN_10003e90 at 10003e90

void __thiscall FUN_10003e90(void *this,GUID *param_1)

{
  int iVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  iVar1 = Ordinal_2(local_88);
  *(int *)this = iVar1;
  if (iVar1 == 0) {
    FUN_10001000(0x8007000e);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003ee7 at 10003ee7

long __thiscall FUN_10003ee7(void *this,void *param_1,uint param_2)

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
      FUN_10002493(pvVar4,local_10,*this,local_c);
    }
    FUN_10002493((void *)((int)pvVar4 + uVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar4 + local_8 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar4;
  }
  return 0;
}



// Function: FUN_10003fd3 at 10003fd3

int __fastcall FUN_10003fd3(int param_1)

{
  long lVar1;
  
  FUN_10002694(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1002f1c0 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_1002f804 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10004014 at 10004014

void __fastcall FUN_10004014(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002ccc((int)piVar1);
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



// Function: FUN_1000404d at 1000404d

void __fastcall FUN_1000404d(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002ccc((int)piVar1);
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



// Function: FUN_10004052 at 10004052

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004052(int param_1)

{
  FUN_10004014(param_1);
  return;
}



// Function: FUN_10004075 at 10004075

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10004075(void *this,LPCWSTR param_1)

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
  iVar1 = FUN_10002744(&local_224,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (iVar1 == 0) {
    do {
      local_218 = 0x100;
      LVar2 = RegEnumKeyExW(local_224,0,local_214,&local_218,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_230);
      if (LVar2 != 0) {
        FUN_100026cd(&local_224);
        FUN_100026ab(this,local_228);
        break;
      }
      iVar1 = FUN_10004075(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    FUN_100026cd(&local_224);
  }
  else {
    local_8 = 0xffffffff;
    FUN_100026cd(&local_224);
  }
  FUN_100172f7();
  return;
}



// Function: FUN_1000415a at 1000415a

undefined4 __fastcall FUN_1000415a(int *param_1)

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
LAB_1000419f:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_1000419f;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10002d12(param_1);
  return 0;
}



// Function: FUN_100041b1 at 100041b1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100041b1(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_10002861(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_1000128f(local_14);
  }
  return uVar1;
}



// Function: FUN_100041f8 at 100041f8

void FUN_100041f8(int param_1)

{
  FUN_1000415a((int *)(param_1 + 4));
  return;
}



// Function: FUN_1000420a at 1000420a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000420a(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x10004219;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_100043e4;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000250b();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_10004277;
      FUN_100024b3(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_100043b4;
      }
    }
    else {
LAB_100043b4:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_10004277:
  local_8 = 0xffffffff;
  FUN_1000128f(&local_248);
LAB_100043e4:
  FUN_100172f7();
  return;
}



// Function: FUN_100043ec at 100043ec

void __fastcall FUN_100043ec(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_1003137c;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_1003137c, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10031380; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10004014(param_1);
  return;
}



// Function: FUN_1000443e at 1000443e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000443e(void *this,wchar_t *param_1)

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
  local_8 = 0x1000444a;
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
      local_18 = (uint *)FUN_10017151(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10003391,
                   (_func_void_void_ptr *)&LAB_10001218);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_100044ee();
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



// Function: Catch@100044de at 100044de

undefined * Catch_100044de(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100044e8;
}



// Function: FUN_100044ee at 100044ee

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100044ee(void)

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



// Function: FUN_100045a6 at 100045a6

void FUN_100045a6(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10001572(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_100045de at 100045de

void __fastcall FUN_100045de(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_100045ee at 100045ee

void __fastcall FUN_100045ee(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10002da0(param_1);
    return;
  }
  return;
}



// Function: FUN_100045fb at 100045fb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100045fb(int param_1)

{
  FUN_10002d3f((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000461c at 1000461c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000461c(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_10004670 at 10004670

void __fastcall FUN_10004670(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10004687 at 10004687

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_10004687(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&PTR_10020a0c,&local_18);
    (**(code **)*param_1)(param_1,&PTR_10020a0c,local_14);
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



// Function: FUN_10004712 at 10004712

undefined4 FUN_10004712(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10002c6e(&DAT_1002ff54,(int *)&PTR_DAT_1002d1d8,param_1,(undefined4 *)&DAT_10023460);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_100043ec(0x1002ff54);
  }
  return 1;
}



// Function: FUN_10004754 at 10004754

undefined * FUN_10004754(void)

{
  return FUN_100039bf;
}



// Function: FUN_1000475a at 1000475a

undefined4 FUN_1000475a(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x30);
    if (*piVar2 != 0) {
      FUN_100010fd(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&PTR_10020a0c,piVar2);
  }
  return uVar1;
}



// Function: FUN_10004791 at 10004791

undefined4 FUN_10004791(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x34);
    if (*piVar2 != 0) {
      FUN_100010fd(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&PTR_10020a0c,piVar2);
  }
  return uVar1;
}



// Function: FUN_100047c8 at 100047c8

undefined4 FUN_100047c8(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x28;
  }
  if (*(HWND *)(iVar2 + 8) != (HWND)0x0) {
    BVar1 = IsWindow(*(HWND *)(iVar2 + 8));
    if (BVar1 != 0) {
      DestroyWindow(*(HWND *)(iVar2 + 8));
    }
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  return 0;
}



// Function: FUN_10004800 at 10004800

undefined4 FUN_10004800(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 8);
    if (*piVar2 != 0) {
      FUN_100010fd(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&PTR_10020a0c,piVar2);
  }
  return uVar1;
}



// Function: FUN_10004837 at 10004837

undefined4 FUN_10004837(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10021f14,param_1 + 4);
  }
  return uVar1;
}



// Function: Init at 1000485d

/* Library Function - Single Match
    private: void __thiscall ATL::CW2WEX<128>::Init(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall ATL::CW2WEX<128>::Init(CW2WEX<128> *this,wchar_t *param_1)

{
  rsize_t rVar1;
  int iVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar2 = lstrlenW(param_1);
    FUN_10001316((int *)this,iVar2 + 1U,this + 4,0x80);
    rVar1 = (iVar2 + 1U) * 2;
    FUN_10002493(*(void **)this,rVar1,param_1,rVar1);
  }
  return;
}



// Function: FUN_100048a3 at 100048a3

uint __thiscall FUN_100048a3(void *this,ushort *param_1,uint param_2,uint param_3)

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
      while (puVar3 = (ushort *)FUN_10002ebd((short *)puVar6,uVar1,param_2), puVar3 != (ushort *)0x0
            ) {
        iVar2 = FUN_10002ede(puVar3,param_1,param_3);
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



// Function: FUN_10004942 at 10004942

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10004942(void *this,int *param_1)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  
  FUN_100037ce(this,param_1);
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (this_00 = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
                 (*(int *)(*param_1 + 4) + 0x3c + (int)param_1),
     this_00 != (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush(this_00);
  }
  *(bool *)((int)this + 4) = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0;
  return this;
}



// Function: FUN_1000499a at 1000499a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000499a(int *param_1)

{
  bool bVar1;
  
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx
              ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)*param_1);
  }
  FUN_100037f4(param_1);
  return;
}



// Function: FUN_100049d2 at 100049d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100049d2(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  *(undefined ***)param_1 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_1000380b((int)param_1);
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  return;
}



// Function: FUN_10004a04 at 10004a04

undefined4 __fastcall FUN_10004a04(int param_1)

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



// Function: FUN_10004a68 at 10004a68

void __thiscall
FUN_10004a68(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

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
      if (param_2 == 0 && param_3 == 0) goto LAB_10004bf4;
    }
    else {
      if (param_4 == 2) {
        iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
LAB_10004b84:
        bVar5 = CARRY4(param_2,iVar3 >> 1);
        param_2 = param_2 + (iVar3 >> 1);
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar5;
      }
      else {
        if (param_4 == 1) {
          iVar3 = uVar2 - **(int **)((int)this + 0x10);
          goto LAB_10004b84;
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
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbump
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     ((int)(**(int **)((int)this + 0x10) - uVar2) >> 1) + param_2);
          goto LAB_10004bf4;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar1 = *(int *)((int)this + 0x3c);
LAB_10004ab3:
      iVar1 = iVar1 - **(int **)((int)this + 0x10);
      uVar2 = iVar1 >> 1;
      bVar5 = CARRY4(param_2,uVar2);
      param_2 = param_2 + uVar2;
      param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar5;
    }
    else if (param_4 == 1) {
      iVar1 = iVar3;
      if ((param_5 & 2) == 0) goto LAB_10004ab3;
LAB_10004acd:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    else if (param_4 != 0) goto LAB_10004acd;
    if (-1 < (int)param_3) {
      iVar1 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar4 = iVar1 >> 0x1f;
      if (((int)param_3 <= iVar4) && (((int)param_3 < iVar4 || (param_2 <= (uint)(iVar1 >> 1))))) {
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
                  ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
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
        goto LAB_10004bf4;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_10004bf4:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10004c0e at 10004c0e

short __thiscall FUN_10004c0e(void *this,short param_1)

{
  uint uVar1;
  
  uVar1 = **(uint **)((int)this + 0x20);
  if (((uVar1 == 0) || (uVar1 <= **(uint **)((int)this + 0x10))) ||
     ((param_1 != -1 &&
      ((param_1 != *(short *)(uVar1 - 2) && ((*(byte *)((int)this + 0x40) & 2) != 0)))))) {
    param_1 = -1;
  }
  else {
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,-1);
    if (param_1 == -1) {
      param_1 = 0;
    }
    else {
      *(short *)**(undefined4 **)((int)this + 0x20) = param_1;
    }
  }
  return param_1;
}



// Function: FUN_10004c6b at 10004c6b

void __thiscall FUN_10004c6b(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

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
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbump
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     ((int)(**(int **)((int)this + 0x10) - uVar1) >> 1) + uVar8);
          uVar7 = uVar6;
          uVar9 = uVar8;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      iVar4 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar5 = iVar4 >> 0x1f;
      if ((((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) &&
         (std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     (**(int **)((int)this + 0x10) - **(int **)((int)this + 0x20) >> 1) + uVar8),
         uVar7 = uVar6, uVar9 = uVar8, (in_stack_00000020 & 2) != 0)) {
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



// Function: FUN_10004d83 at 10004d83

void __fastcall FUN_10004d83(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10004d93 at 10004d93

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004d93(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x13c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10002e46(puVar1);
    }
    uVar2 = FUN_10004df3();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10004de6 at 10004de6

undefined * Catch_10004de6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004df0;
}



// Function: FUN_10004df3 at 10004df3

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10004df3(void)

{
  int iVar1;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(unaff_ESI[1] + 4))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10004e1e at 10004e1e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_10004e1e(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x48);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000372b(puVar1);
    }
    uVar2 = FUN_10004e7f();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10004e6f at 10004e6f

undefined * Catch_10004e6f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004e79;
}



// Function: FUN_10004e7f at 10004e7f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_10004e7f(void)

{
  uint uVar1;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    uVar1 = FUN_10002e03((int)(unaff_ESI + 10));
    unaff_EDI = uVar1;
    if (-1 < (int)uVar1) {
      unaff_EDI = 0;
    }
    if ((uVar1 < 0x80000000) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(unaff_ESI[7] + 0x10))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10004ebc at 10004ebc

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10004ebc(void *this,byte param_1)

{
  FUN_100049d2((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: Allocate at 10004edb

/* Library Function - Single Match
    public: bool __thiscall ATL::CHeapPtr<wchar_t,class ATL::CComAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

bool __thiscall
ATL::CHeapPtr<wchar_t,class_ATL::CComAllocator>::Allocate
          (CHeapPtr<wchar_t,class_ATL::CComAllocator> *this,uint param_1)

{
  long lVar1;
  LPVOID pvVar2;
  bool bVar3;
  ulong local_8;
  
  local_8 = 0;
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,2);
  if (lVar1 < 0) {
    bVar3 = false;
  }
  else {
    pvVar2 = CoTaskMemAlloc(local_8);
    bVar3 = pvVar2 != (LPVOID)0x0;
    *(LPVOID *)this = pvVar2;
  }
  return bVar3;
}



// Function: QueryInterface at 10004f14

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10021ba8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10004f2e at 10004f2e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10004f2e(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  FUN_100038d4((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1002f1c0 + 4))();
  return (undefined4 *)this;
}



// Function: Release at 10004f71

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



// Function: FUN_10004f92 at 10004f92

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004f92(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_1002f1c0 + 8))();
  FUN_10013cee((int)(param_1 + 2));
  return;
}



// Function: FUN_10004fd8 at 10004fd8

long FUN_10004fd8(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10021ba8,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: QueryInterface at 10005024

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10021d30,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000503e at 1000503e

undefined4 * __thiscall FUN_1000503e(void *this,byte param_1)

{
  FUN_10004f92((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000505d at 1000505d

void __thiscall FUN_1000505d(void *this)

{
  HWND hWnd;
  int iVar1;
  HDC hDC;
  undefined4 *in_stack_00000010;
  tagPAINTSTRUCT local_48;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  iVar1 = __RTDynamicCast(this,0,&CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::
                                  RTTI_Type_Descriptor,
                          &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar1 + 8);
  hDC = GetDC(hWnd);
  BeginPaint(hWnd,&local_48);
  if (((*(int *)((int)this + 0x1c) != 0) && (*(int *)((int)this + 0x18) != 0)) ||
     (*(int *)((int)this + 0x20) != 0)) {
    FUN_10003ba7((int)this);
    DrawFrameControl(hDC,(LPRECT)((int)this + 0x44),3,8);
    *(undefined4 *)((int)this + 0x1c) = 0;
    *(undefined4 *)((int)this + 0x20) = 0;
  }
  EndPaint(hWnd,&local_48);
  ReleaseDC(hWnd,hDC);
  *in_stack_00000010 = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005101 at 10005101

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10005101(int *param_1,wchar_t *param_2)

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
  local_8 = 0x1000510d;
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
  FUN_10004942(local_28,param_1);
  local_8 = 0;
  if (local_24 == '\0') {
    local_18 = 4;
    FUN_10005266();
    return;
  }
  local_8 = 1;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_100051be;
      uVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar3 == 0xffff) break;
      bVar5 = local_20 != 0;
      local_20 = local_20 + -1;
      local_1c = local_1c + -1 + (uint)bVar5;
    }
    local_18 = local_18 | 4;
LAB_100051be:
    if (local_18 != 0) goto LAB_100051e7;
  }
  _Var6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                    (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                      (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                     (ulonglong)CONCAT22(in_stack_ffffffca,in_stack_ffffffc8) << 0x20);
  if (((size_t)_Var6 == sVar4) && ((int)((ulonglong)_Var6 >> 0x20) == 0)) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_100051e7;
      uVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
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
LAB_100051e7:
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  local_8 = 0;
  FUN_10005266();
  return;
}



// Function: Catch@10005245 at 10005245

undefined * Catch_10005245(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005263;
}



// Function: FUN_10005266 at 10005266

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10005266(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000499a((int *)(unaff_EBP + -0x24));
  return;
}



// Function: FUN_1000528c at 1000528c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_1000528c(int *param_1,wchar_t *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  __int64 _Var5;
  undefined2 in_stack_ffffffcc;
  undefined2 in_stack_ffffffce;
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10005298;
  local_18 = 0;
  uVar1 = *(uint *)(param_2 + 8);
  uVar2 = *(uint *)(*(int *)(*param_1 + 4) + 0x20 + (int)param_1);
  iVar3 = *(int *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1);
  if ((iVar3 < 0) || (((iVar3 < 1 && (uVar2 == 0)) || (local_20 = iVar3, uVar2 <= uVar1)))) {
    local_1c = 0;
  }
  else {
    local_1c = uVar2 - uVar1;
  }
  FUN_10004942(local_24,param_1);
  local_8 = 0;
  if ((char)local_20 == '\0') {
    local_18 = 4;
    FUN_100053d5();
    return;
  }
  local_8 = 1;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) == 0x40) {
LAB_10005339:
    if (7 < *(uint *)(param_2 + 10)) {
      param_2 = *(wchar_t **)param_2;
    }
    _Var5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                      (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                        (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                       (ulonglong)CONCAT22(in_stack_ffffffce,in_stack_ffffffcc) << 0x20);
    if (((uint)_Var5 != uVar1) || ((int)((ulonglong)_Var5 >> 0x20) != 0)) {
      local_18 = 4;
      goto LAB_1000536d;
    }
  }
  else {
    for (; local_1c != 0; local_1c = local_1c + -1) {
      uVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar4 == 0xffff) {
        local_18 = local_18 | 4;
        break;
      }
    }
    if (local_18 == 0) goto LAB_10005339;
  }
  for (; local_1c != 0; local_1c = local_1c + -1) {
    uVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                      (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                        (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                       *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
    if (uVar4 == 0xffff) {
      local_18 = local_18 | 4;
      break;
    }
  }
LAB_1000536d:
  iVar3 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar3 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar3 + 0x24 + (int)param_1) = 0;
  local_8 = 0;
  FUN_100053d5();
  return;
}



// Function: Catch@100053b4 at 100053b4

undefined * Catch_100053b4(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100053d2;
}



// Function: FUN_100053d5 at 100053d5

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100053d5(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000499a((int *)(unaff_EBP + -0x20));
  return;
}



// Function: FUN_100053fb at 100053fb

void __thiscall FUN_100053fb(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FUN_10003b43(this,0,*(uint *)((int)this + 0x10),(ushort *)param_1,sVar1);
  return;
}



// Function: FUN_10005420 at 10005420

void FUN_10005420(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_1000542a at 1000542a

void FUN_1000542a(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x70),param_2);
  return;
}



// Function: FUN_10005434 at 10005434

void FUN_10005434(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xf0),param_2);
  return;
}



// Function: FUN_10005441 at 10005441

void FUN_10005441(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x18),param_2);
  return;
}



// Function: FUN_1000544b at 1000544b

void FUN_1000544b(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x1c),param_2);
  return;
}



// Function: FUN_10005455 at 10005455

void FUN_10005455(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x24),param_2);
  return;
}



// Function: FUN_1000545f at 1000545f

void FUN_1000545f(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x28),param_2);
  return;
}



// Function: FUN_10005469 at 10005469

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10005469(undefined4 *param_1)

{
  FUN_10003fd3((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_1002f814 = param_1;
  return param_1;
}



// Function: FUN_1000549e at 1000549e

void __fastcall FUN_1000549e(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100054a9 at 100054a9

void __fastcall FUN_100054a9(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100054b4 at 100054b4

HRESULT __thiscall FUN_100054b4(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_10023504,(LPUNKNOWN)0x0,1,(IID *)&DAT_10021fe0,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10005500 at 10005500

undefined4 FUN_10005500(void)

{
  return 0x80004005;
}



// Function: FUN_10005508 at 10005508

void FUN_10005508(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10020a3c);
  return;
}



// Function: FUN_10005522 at 10005522

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10005522(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10004014((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005559 at 10005559

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005559(int *param_1)

{
  FUN_1000415a(param_1);
  FUN_10002d12(param_1);
  return;
}



// Function: FUN_10005583 at 10005583

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005583(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_1000415a(param_1 + 1);
  FUN_10005559(param_1 + 1);
  return;
}



// Function: FUN_100055b7 at 100055b7

undefined4 FUN_100055b7(void)

{
  return 0x80004001;
}



// Function: FUN_100055bf at 100055bf

undefined4 FUN_100055bf(void)

{
  return 1;
}



// Function: FUN_100055c5 at 100055c5

undefined4 * __thiscall FUN_100055c5(void *this,byte param_1)

{
  FUN_10005583((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100055e4 at 100055e4

undefined4 __fastcall FUN_100055e4(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10002d69((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10005625 at 10005625

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10005625(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10005631;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10002821(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10002c4f(&local_5d);
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
LAB_1000571a:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_1000578e;
                }
                iVar3 = FUN_10002801((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_10002861(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_100057b4;
                  goto LAB_10005756;
                }
                local_55 = '\0';
              }
              else {
LAB_10005756:
                if (local_55 != '\0') goto LAB_1000578e;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_100041b1(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_100057b4;
                local_56 = '\0';
              }
              goto LAB_1000578e;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_100041b1(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_1000571a;
            }
LAB_100057b4:
            local_5c = -0x7ff8fff2;
            goto LAB_10005695;
          }
LAB_1000578e:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_100029fb(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_10005695;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_100055e4(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_100041b1(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_100057b4;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_10005827;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_10005695;
            }
            iVar3 = FUN_10002861(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_100057b4;
          }
          else {
            iVar3 = FUN_10002861(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_10005827:
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
LAB_10005695:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_100172f7();
  return;
}



// Function: FUN_10005892 at 10005892

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10005892(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  HRESULT HVar3;
  errno_t eVar4;
  LSTATUS LVar5;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  int local_1c0;
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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&PTR_100234f4), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_10023514,(LPUNKNOWN)0x0,1,(IID *)&DAT_100220dc,&local_1a8
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
          goto LAB_10005b1a;
        }
      }
      local_1ac = local_1ac + 2;
      iVar2 = *local_1ac;
    }
    if (param_3 == 0) {
      StringFromGUID2(local_1b0,local_194,0x40);
      local_1c0 = 0;
      local_8._0_1_ = 6;
      eVar4 = wcscpy_s(local_114,0x80,L"CLSID\\");
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Required Categories");
      ATL::AtlCrtErrorCheck(eVar4);
      local_1cc = 0x80000000;
      local_1c8 = 0;
      local_1c4 = 0;
      local_1bc = (HKEY)0x0;
      local_1b8 = 0;
      local_1b4 = 0;
      local_8 = CONCAT31(local_8._1_3_,8);
      local_1ac = (int *)0x0;
      iVar2 = FUN_10002744(&local_1bc,(HKEY)0x80000000,local_114,0x20019);
      if (iVar2 == 0) {
        local_1b0 = (GUID *)RegQueryInfoKeyW(local_1bc,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                             (LPDWORD)&local_1ac,(LPDWORD)0x0,(LPDWORD)0x0,
                                             (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                             (PFILETIME)0x0);
        FUN_100026cd(&local_1bc);
        if ((local_1b0 == (GUID *)0x0) && (local_1ac == (int *)0x0)) {
          RegDeleteKeyW((HKEY)0x80000000,local_114);
        }
      }
      eVar4 = wcscpy_s(local_114,0x80,L"CLSID\\");
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,local_194);
      ATL::AtlCrtErrorCheck(eVar4);
      eVar4 = wcscat_s(local_114,0x80,L"\\Implemented Categories");
      ATL::AtlCrtErrorCheck(eVar4);
      iVar2 = FUN_10002744(&local_1bc,(HKEY)0x80000000,local_114,0x20019);
      if (iVar2 == 0) {
        LVar5 = RegQueryInfoKeyW(local_1bc,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)&local_1ac
                                 ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)0x0,(PFILETIME)0x0);
        FUN_100026cd(&local_1bc);
        if ((LVar5 == 0) && (local_1ac == (int *)0x0)) {
          RegDeleteKeyW((HKEY)0x80000000,local_114);
        }
      }
      local_8._0_1_ = 7;
      FUN_100026cd(&local_1bc);
      local_8._0_1_ = 6;
      FUN_100026cd(&local_1cc);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_1000128f(&local_1c0);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_10005b1a:
  FUN_100172f7();
  return;
}



// Function: FUN_10005bad at 10005bad

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10005bad(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_1000420a(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10002c4f((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_10005c7d at 10005c7d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10005c7d(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_1000420a(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_10002c4f(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10005e3f;
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
LAB_10005e3f:
  FUN_100172f7();
  return;
}



// Function: FUN_10005e47 at 10005e47

int FUN_10005e47(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10002395(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_10005892((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_10005c7d(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10005ecd at 10005ecd

int FUN_10005ecd(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10002395(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_10005892((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_10005bad(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10005f54 at 10005f54

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10005f54(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&PTR_10020a0c,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_1000600f;
          }
          else {
LAB_1000600f:
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



// Function: FUN_1000603f at 1000603f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000603f(int param_1,DWORD *param_2,DWORD *param_3)

{
  DWORD DVar1;
  DWORD *lpArguments;
  DWORD *extraout_ECX;
  
  lpArguments = (DWORD *)0x0;
  if (param_1 != 0) goto LAB_10006063;
  do {
    RaiseException(0xc0000005,1,(DWORD)lpArguments,lpArguments);
    lpArguments = extraout_ECX;
LAB_10006063:
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



// Function: FUN_100060b5 at 100060b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100060b5(int param_1)

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



// Function: FUN_10006136 at 10006136

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006136(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_1000617b();
  return uVar1;
}



// Function: Catch@1000616b at 1000616b

undefined * Catch_1000616b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006175;
}



// Function: FUN_1000617b at 1000617b

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000617b(void)

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



// Function: FUN_100061d6 at 100061d6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100061d6(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10002d3f((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_10006207 at 10006207

undefined4 FUN_10006207(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10006245 at 10006245

undefined4 FUN_10006245(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_1002f1c0 + 8))();
  }
  else {
    (**(code **)(*DAT_1002f1c0 + 4))();
  }
  return 0;
}



// Function: FUN_10006264 at 10006264

undefined4 * __thiscall FUN_10006264(void *this,byte param_1)

{
  FUN_100061d6((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006283 at 10006283

undefined4 __thiscall FUN_10006283(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_1000461c(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 100062da

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
    FUN_10002daa(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10006309

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
    FUN_10002daa(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10006338

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
    FUN_10002daa(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10006367 at 10006367

IUnknown * __thiscall FUN_10006367(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_10004687(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_10022158);
  }
  return pIVar2;
}



// Function: FUN_10006394 at 10006394

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10006394(void *this,LPCWSTR param_1)

{
  LPCWSTR *ppWVar1;
  int iVar2;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  ulong local_428;
  wchar_t local_424;
  undefined1 local_422 [518];
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x42c;
  local_434 = 0;
  local_430 = 0;
  local_42c = 0;
  local_8 = 1;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_424 = L'\0';
  memset(local_422,0,0x206);
  local_428 = 0x208;
  ppWVar1 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar1 = &param_1;
  }
  iVar2 = FUN_10002744(&local_434,(HKEY)0x80000002,(LPCWSTR)ppWVar1,0x2001f);
  if (iVar2 == 0) {
    iVar2 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_434,L"XMLResource",&local_21c,&local_428);
    local_428 = 0x208;
  }
  ATL::CRegKey::QueryStringValue((CRegKey *)&local_434,L"FriendlyName",&local_424,&local_428);
  if ((iVar2 == 0) && (local_428 != 0)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0xc))(&local_21c,in_stack_00000020);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_100026cd(&local_434);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(&param_1,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_100064c5 at 100064c5

uint FUN_100064c5(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_10004e1e(0,param_2,param_3);
  }
  else if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    uVar1 = 0x80040110;
  }
  return uVar1;
}



// Function: FUN_100064f6 at 100064f6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100064f6(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000651c at 1000651c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000651c(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_100049d2((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x4c));
  *(code **)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) = _vftable__exref;
  return;
}



// Function: FUN_10006561 at 10006561

wchar_t __thiscall FUN_10006561(void *this,wchar_t param_1)

{
  char *pcVar1;
  void *pvVar2;
  byte bVar3;
  int iVar4;
  void *_Src;
  wchar_t *pwVar5;
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
  if (param_1 == L'\xffff') {
    return L'\0';
  }
  uVar8 = **(uint **)((int)this + 0x24);
  if ((uVar8 != 0) && (uVar8 < uVar8 + **(int **)((int)this + 0x34) * 2)) {
    pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *pwVar5 = param_1;
    return param_1;
  }
  if ((*(byte *)((int)this + 0x40) & 2) != 0) {
    return L'\xffff';
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
    return L'\xffff';
  }
  do {
    if (uVar8 <= 0x7fffffff - uVar7) break;
    uVar7 = uVar7 >> 1;
  } while (uVar7 != 0);
  if (uVar7 == 0) {
    return L'\xffff';
  }
  pcVar1 = (char *)(uVar7 + uVar8);
  _Dst = FUN_10001384(pcVar1);
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
      goto LAB_10006708;
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
      goto LAB_10006708;
    }
    **(undefined4 **)((int)this + 0x10) = _Dst;
    puVar6 = *(undefined4 **)((int)this + 0x20);
  }
  *puVar6 = 0;
  **(int **)((int)this + 0x30) = (int)_Dst >> 1;
LAB_10006708:
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *pwVar5 = param_1;
  return param_1;
}



// Function: FUN_10006732 at 10006732

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006732(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x144);
    if (this != (void *)0x0) {
      FUN_10004f2e(this,param_1);
    }
    uVar1 = FUN_1000679c();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000678f at 1000678f

undefined * Catch_1000678f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006799;
}



// Function: FUN_1000679c at 1000679c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000679c(void)

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



// Function: FUN_100067c6 at 100067c6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100067c6(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10002e18(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_10006801 at 10006801

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10006801(void *this,byte param_1)

{
  uint uVar1;
  
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  uVar1 = FUN_100038a8(param_1);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0x40) = uVar1;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10006841 at 10006841

undefined4 * __thiscall
FUN_10006841(void *this,uint param_1,undefined4 *param_2,uint param_3,uint param_4)

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
      bVar3 = FUN_10001b8a(this,uVar8,'\0');
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



// Function: FUN_10006976 at 10006976

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_10006976(DLGTEMPLATE *param_1,wchar_t *param_2,undefined2 *param_3)

{
  int iVar1;
  uchar *puVar2;
  errno_t eVar3;
  size_t sVar4;
  wchar_t *local_118;
  wchar_t local_114 [134];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x108;
  local_8 = 0x10006985;
  if (param_1 != (DLGTEMPLATE *)0x0) goto LAB_100069a3;
  do {
    FUN_10001000(0x80004005);
LAB_100069a3:
    iVar1 = HasFont(param_1);
    if (iVar1 == 0) goto LAB_10006a54;
  } while ((param_2 == (wchar_t *)0x0) || (param_3 == (undefined2 *)0x0));
  puVar2 = CDialogTemplate::GetFontSizeField(param_1);
  *param_3 = *(undefined2 *)puVar2;
  local_118 = local_114;
  ATL::CW2WEX<128>::Init
            ((CW2WEX<128> *)&local_118,
             (wchar_t *)(puVar2 + ((uint)(*(short *)((int)&param_1->style + 2) == -1) * 2 + 1) * 2))
  ;
  local_8 = 0;
  eVar3 = wcsncpy_s(param_2,0x20,local_118,0xffffffff);
  ATL::AtlCrtErrorCheck(eVar3);
  sVar4 = wcslen(param_2);
  if (0x1f < sVar4) {
    param_2[0x1f] = L'\0';
  }
  local_8 = 0xffffffff;
  if (local_118 != local_114) {
    free(local_118);
  }
LAB_10006a54:
  FUN_100172f7();
  return;
}



// Function: FUN_10006a5a at 10006a5a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006a5a(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_10017151(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10006ac0();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10006ab4 at 10006ab4

undefined * Catch_10006ab4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006abe;
}



// Function: FUN_10006ac0 at 10006ac0

void FUN_10006ac0(void)

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
  uVar4 = FUN_10017151(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10006b11();
  return;
}



// Function: Catch@10006b02 at 10006b02

undefined * Catch_10006b02(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10006b0f;
}



// Function: FUN_10006b11 at 10006b11

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10006b11(void)

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
    FUN_10002493(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10002493(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_10006283(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_10006b6d;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_10006b6d:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_10006ba5 at 10006ba5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10006ba5(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_10006a5a(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_1000128f(local_14);
  }
  return iVar1;
}



// Function: FUN_10006c00 at 10006c00

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006c00(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1001875c;
  local_10 = ExceptionList;
  uStack_2144 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_10002a70(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_100028ef(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_10006f79;
  FUN_10002a4e((undefined4 *)this);
  iVar1 = FUN_10002a70(this,local_2018);
  if (iVar1 < 0) goto LAB_10006f79;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_10006f55:
    if (uVar2 != 0) {
      FUN_10002520(uVar2);
      goto LAB_10006f79;
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
        FUN_10006e88();
        return;
      }
      goto LAB_10006f79;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_1000128f((int *)&local_2124);
      goto LAB_10006f55;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10006d21();
      return;
    }
  }
  FUN_10002a70(this,param_3);
LAB_10006f79:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10006d15 at 10006d15

undefined * Catch_10006d15(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10006d1f;
}



// Function: FUN_10006d21 at 10006d21

void FUN_10006d21(void)

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
    pWVar2 = (WCHAR *)FUN_100027be(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10002da0((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_10002a70(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_10002520((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10006f91;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10006e6d at 10006e6d

undefined * Catch_10006e6d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10006e7a;
}



// Function: FUN_10006e88 at 10006e88

void FUN_10006e88(void)

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
      FUN_10002da0((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_10002997(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10002da0((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_10002a70(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_10002520(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10006f91;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10006f95 at 10006f95

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006f95(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  HKEY *ppHVar8;
  HKEY local_2268;
  undefined4 local_2264;
  undefined4 local_2260;
  HKEY local_225c;
  undefined4 local_2258;
  undefined4 local_2254;
  HKEY local_2250;
  undefined4 local_224c;
  undefined4 local_2248;
  int local_2244;
  HKEY local_2240;
  undefined4 local_223c;
  undefined4 local_2238;
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
  puStack_c = &LAB_100187bb;
  local_10 = ExceptionList;
  local_14 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_10006ff9:
  iVar3 = FUN_10002a70(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_10007009:
      local_8 = 0xffffffff;
      FUN_100026cd(&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_10007466:
    if (*param_1 == L'}') goto LAB_10007009;
    local_2244 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_10002a70(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10007009;
      if (param_3 == 0) goto LAB_10007148;
      local_2240 = (HKEY)0x0;
      local_223c = 0;
      local_2238 = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_100029fb(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_10002b86(param_1);
        if (iVar3 != 0) {
          local_2240 = local_2228;
          local_223c = 0;
          local_2238 = 0;
          FUN_10004075(&local_2240,param_1);
          local_2240 = (HKEY)0x0;
          local_223c = 0;
          local_2238 = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100026cd(&local_2240);
          goto LAB_10007148;
        }
        iVar3 = FUN_10002a70(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10002bea(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          ppHVar8 = &local_2240;
          goto LAB_10007561;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar8 = &local_2240;
        goto LAB_100075e0;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100026cd(&local_2240);
      goto LAB_10007009;
    }
LAB_10007148:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2244 = 0;
      iVar3 = FUN_10002a70(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10007009;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_100029fb(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        if (param_3 == 0) {
          if (iVar1 == 0) {
            local_2224 = FUN_10002744(&local_2234,local_2228,param_1,0x20019);
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
          iVar3 = FUN_10002a70(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10002bea(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_10006f95(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_10002a70(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = FUN_10002744(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) &&
              (iVar3 = FUN_10002744(&local_2234,local_2228,param_1,0x20019), iVar3 != 0)) &&
             (uVar6 = FUN_100026e8(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                   (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_100075ff;
          iVar3 = FUN_10002a70(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10006c00(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_10007566;
        }
      }
      goto LAB_10007009;
    }
    iVar3 = FUN_10002a70(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_10002a70(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_10007009;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_2250 = local_2228;
      local_224c = 0;
      local_2248 = 0;
      iVar3 = FUN_10006c00(local_2220,(CRegKey *)&local_2250,local_221c,param_1);
      local_2250 = (HKEY)0x0;
      local_224c = 0;
      local_2248 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar8 = &local_2250;
        goto LAB_10007561;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ppHVar8 = &local_2250;
      goto LAB_100075e0;
    }
    if ((iVar1 == 0) && (local_2244 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = FUN_10002744(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10002520(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar8 = &local_2268;
LAB_100075e0:
        FUN_100026cd(ppHVar8);
        goto LAB_10007009;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_100026cd(&local_2268);
    }
    iVar3 = FUN_10002bea(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_10002bb5(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_10002b86(local_21c);
        if ((iVar3 != 0) && (local_2244 != 0)) {
          FUN_10004075(&local_2234,local_21c);
        }
        goto LAB_10007466;
      }
      bVar2 = FUN_10002bb5(local_2234);
      local_2224 = CONCAT31(extraout_var_00,bVar2);
      uVar6 = FUN_100026cd(&local_2234);
      if (uVar6 == 0) {
        if ((local_2244 != 0) && (local_2224 == 0)) {
          local_8._0_1_ = 4;
          local_225c = local_2228;
          local_2258 = 0;
          local_2254 = 0;
          uVar6 = RegDeleteKeyW(local_2228,local_21c);
          local_225c = (HKEY)0x0;
          local_2258 = 0;
          local_2254 = 0;
          if (uVar6 != 0) {
            FUN_10002520(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            ppHVar8 = &local_225c;
            goto LAB_100075e0;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ppHVar8 = &local_225c;
LAB_10007561:
          FUN_100026cd(ppHVar8);
LAB_10007566:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_10006f95(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_10006ff9;
            goto LAB_10007009;
          }
        }
        goto LAB_10007466;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_10007466;
    }
LAB_100075ff:
    FUN_10002520(uVar6);
    goto LAB_10007009;
  }
  goto LAB_10007466;
}



// Function: FUN_10007628 at 10007628

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10007628(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10031384);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&PTR_10020a0c,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10031384);
          if (*piVar2 != 0) goto LAB_100076bc;
        }
        else {
LAB_100076bc:
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
  piVar2 = FUN_10005f54((int *)&DAT_10031374,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_100076f4 at 100076f4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100076f4(void *this,undefined4 param_1)

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
  local_8 = 0x10007703;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10007939;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1002f1c0 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_1002f1c4,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_10031340,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10007903;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000128f((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_10021b94,&local_224);
        if (-1 < iVar2) {
          FUN_10006367(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_1002f1c0 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_1002f1c0 + 4;
        }
        pcVar4 = FUN_100045a6;
        pvVar5 = this;
        FUN_10006136(iVar2);
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
LAB_10007903:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_1000443e(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10007939:
  FUN_100172f7();
  return;
}



// Function: FUN_10007941 at 10007941

void FUN_10007941(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10005e47(0x10031374,param_1,param_2);
  if ((-1 < iVar1) && (DAT_1002f808 != (code *)0x0)) {
    (*DAT_1002f808)(DAT_10031340);
  }
  return;
}



// Function: FUN_1000796f at 1000796f

void FUN_1000796f(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_1002f80c != (code *)0x0) && (iVar1 = (*DAT_1002f80c)(), iVar1 < 0)) {
    return;
  }
  FUN_10005ecd(0x10031374,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 10007995

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x7995  2  DllGetClassObject */
  piVar1 = FUN_10007628(&DAT_1002ff54,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_100079a3 at 100079a3

undefined4 FUN_100079a3(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x38);
    if (*piVar2 != 0) {
      FUN_100010fd(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10021d7c,piVar2);
  }
  return uVar1;
}



// Function: FUN_100079da at 100079da

undefined4 FUN_100079da(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x3c);
    if (*piVar2 != 0) {
      FUN_100010fd(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10021f04,piVar2);
  }
  return uVar1;
}



// Function: FUN_10007a11 at 10007a11

void FUN_10007a11(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10004d93(0,param_2,param_3);
    return;
  }
  FUN_10006732(param_1,param_2,param_3);
  return;
}



// Function: FUN_10007a31 at 10007a31

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007a31(int param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)(param_1 + 0x50);
  FUN_1000651c((int)piVar1);
  *(code **)piVar1 = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}



// Function: FUN_10007a6a at 10007a6a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007a6a(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10007a90 at 10007a90

undefined4 * __thiscall
FUN_10007a90(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,
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
    FUN_10001b8a(this,uVar8,'\0');
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
    goto LAB_10007d63;
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
      goto LAB_10007bd7;
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
      goto LAB_10007d63;
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
LAB_10007bd7:
    pvVar5 = (void *)((int)pvVar5 + param_4 * 2);
    pvVar4 = (void *)((int)pvVar4 + param_1 * 2);
  }
  memmove(pvVar4,pvVar5,param_5 * 2);
LAB_10007d63:
  *(uint *)((int)this + 0x10) = uVar8;
  pvVar5 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar5 = *this;
  }
  *(undefined2 *)((int)pvVar5 + uVar8 * 2) = 0;
  return (undefined4 *)this;
}



// Function: FUN_10007d93 at 10007d93

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ATLSTRINGRESOURCEIMAGE * FUN_10007d93(ATLSTRINGRESOURCEIMAGE *param_1)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  
  pAVar1 = ATL::AtlGetStringResourceImage(DAT_10031344,(uint)param_1);
  pAVar2 = pAVar1;
  if (pAVar1 != (ATLSTRINGRESOURCEIMAGE *)0x0) {
    param_1 = (ATLSTRINGRESOURCEIMAGE *)0x0;
    ATL::CHeapPtr<wchar_t,class_ATL::CComAllocator>::Allocate
              ((CHeapPtr<wchar_t,class_ATL::CComAllocator> *)&param_1,*(ushort *)pAVar1 + 1);
    pAVar2 = param_1;
    if (param_1 != (ATLSTRINGRESOURCEIMAGE *)0x0) {
      FUN_10002493(param_1,(uint)*(ushort *)pAVar1 * 2 + 2,pAVar1 + 2,(uint)*(ushort *)pAVar1 * 2);
      *(undefined2 *)(pAVar2 + (uint)*(ushort *)pAVar1 * 2) = 0;
    }
    param_1 = (ATLSTRINGRESOURCEIMAGE *)0x0;
    CoTaskMemFree((LPVOID)0x0);
  }
  return pAVar2;
}



// Function: FUN_10007e12 at 10007e12

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10007e12(void *this,byte param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined ***)this = &PTR_100221a4;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
  }
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
             (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 4),false);
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_10006801((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 4),
               param_1 | 2);
  return (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10007e90 at 10007e90

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10007e90(undefined4 *param_1)

{
  FUN_100067c6(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_10007ebe at 10007ebe

LONG FUN_10007ebe(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1002f1c0 + 4))();
  }
  return LVar1;
}



// Function: FUN_10007ee8 at 10007ee8

LONG FUN_10007ee8(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1002f1c0 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 10007f27

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100221c8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10007f41 at 10007f41

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007f41(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100061d6(param_1);
  return;
}



// Function: FUN_10007f70 at 10007f70

undefined4 * __thiscall FUN_10007f70(void *this,byte param_1)

{
  FUN_10007f41((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007f8f at 10007f8f

void * __thiscall FUN_10007f8f(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x50);
  FUN_10007a31((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_10007fb1 at 10007fb1

undefined2 * __thiscall FUN_10007fb1(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FUN_10001bf4(this,param_1,param_2,param_3);
  return (undefined2 *)this;
}



// Function: FUN_10007fdc at 10007fdc

undefined4 * __thiscall FUN_10007fdc(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_10001b8a(this,uVar2,'\0');
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



// Function: FUN_10008081 at 10008081

undefined4 * __thiscall FUN_10008081(void *this,undefined4 *param_1,uint param_2)

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
      bVar1 = FUN_10001b8a(this,uVar2,'\0');
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
    this = FUN_10007fdc(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008123 at 10008123

undefined4 * __thiscall FUN_10008123(void *this,uint param_1,undefined4 *param_2,uint param_3)

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
      bVar1 = FUN_10001b8a(this,uVar2,'\0');
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
    this = FUN_10006841(this,param_1,(undefined4 *)this,(int)param_2 - (int)pvVar4 >> 1,param_3);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000821b at 1000821b

undefined4 * __thiscall
FUN_1000821b(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

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
      bVar1 = FUN_10001b8a(this,uVar2,'\0');
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
    this = FUN_10007a90(this,param_1,param_2,(undefined4 *)this,(int)param_3 - (int)pvVar5 >> 1,
                        (uint)param_4);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000837a at 1000837a

void FUN_1000837a(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *dwNewLong;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_100060b5(0x1003139c);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)param_1;
    iVar2 = (**(code **)(*piVar1 + 8))();
    FUN_10003369(piVar1 + 5,iVar2,piVar1);
    dwNewLong = (code *)piVar1[5];
    SetWindowLongW(param_1,4,(LONG)dwNewLong);
    (*dwNewLong)(param_1,param_2,param_3,param_4);
  }
  return;
}



// Function: FUN_100083c7 at 100083c7

void __thiscall FUN_100083c7(void *this,int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
                    /* WARNING: Load size is inaccurate */
  if (param_2 != *this) {
    *(int *)param_2[1] = *param_2;
    *(int *)(*param_2 + 4) = param_2[1];
    operator_delete(param_2);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  }
  *param_1 = iVar1;
  return;
}



// Function: FUN_100083ff at 100083ff

void __fastcall FUN_100083ff(int *param_1)

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



// Function: FUN_10008428 at 10008428

void __cdecl FUN_10008428(wchar_t *param_1,ushort param_2,int *param_3,char param_4)

{
  HMODULE hModule;
  HRSRC hResInfo;
  DLGTEMPLATE *pDVar1;
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
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  FUN_10003008(param_1,param_2,&local_54,&local_58);
  if (param_4 != '\0') {
    hModule = LoadLibraryW(L"COMCTL32.DLL");
    if (hModule != (HMODULE)0x0) {
      hResInfo = FindResourceW(hModule,(LPCWSTR)0x3ee,(LPCWSTR)0x5);
      if (hResInfo != (HRSRC)0x0) {
        pDVar1 = (DLGTEMPLATE *)LoadResource(hModule,hResInfo);
        if (pDVar1 != (DLGTEMPLATE *)0x0) {
          iVar2 = FUN_10006976(pDVar1,local_48,(undefined2 *)&local_4c);
          FreeLibrary(hModule);
          if (iVar2 != 0) {
            FUN_10003008(local_48,(ushort)local_4c,&local_60,&local_4c);
            pcVar3 = MulDiv_exref;
            iVar2 = MulDiv(*param_3,local_54,4);
            *param_3 = iVar2;
            iVar2 = MulDiv(param_3[1],local_5c,8);
            param_3[1] = iVar2;
            goto LAB_10008504;
          }
        }
      }
    }
  }
  pcVar3 = MulDiv_exref;
  iVar2 = MulDiv(*param_3,local_54,4);
  local_4c = 8;
  *param_3 = iVar2;
  iVar2 = param_3[1];
  local_58 = local_50;
LAB_10008504:
  iVar2 = (*pcVar3)(iVar2,local_58,local_4c);
  param_3[1] = iVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008517 at 10008517

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10008517(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10005625(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_1000860d:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10008562:
  if ((((sVar1 == 0) || (iVar3 = FUN_10002a70(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_100029cd(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_10002a70(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_100085ff;
  if (param_2 == 0) {
    iVar3 = FUN_10006f95(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_100085ff;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_10006f95(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_10006f95(this,local_2008,pHVar4,0,0);
LAB_100085ff:
      CoTaskMemFree(local_200c);
      goto LAB_1000860d;
    }
  }
  FUN_10002a4e((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10008562;
}



// Function: FUN_1000864e at 1000864e

int __thiscall FUN_1000864e(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10002395(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10005892((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_10007941(param_1,param_2);
  return iVar5;
}



// Function: FUN_100086bd at 100086bd

int __thiscall FUN_100086bd(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10002395(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10005892((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_1000796f(param_1,param_2);
  return iVar5;
}



// Function: FUN_1000872c at 1000872c

undefined4 __thiscall FUN_1000872c(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_100076f4(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_1000876c at 1000876c

undefined4 __thiscall
FUN_1000876c(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_100076f4(this,param_4);
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



// Function: FUN_1000880d at 1000880d

void __thiscall
FUN_1000880d(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_100076f4(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: DllRegisterServer at 10008850

void DllRegisterServer(void)

{
                    /* 0x8850  3  DllRegisterServer */
  FUN_1000864e(&DAT_1002ff54,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 1000885f

void DllUnregisterServer(void)

{
                    /* 0x885f  4  DllUnregisterServer */
  FUN_100086bd(&DAT_1002ff54,1,(void *)0x0);
  return;
}



// Function: FUN_1000886e at 1000886e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

long FUN_1000886e(ATLSTRINGRESOURCEIMAGE *param_1,LPCWSTR param_2)

{
  ATLSTRINGRESOURCEIMAGE *lpString;
  uint uVar1;
  long lVar2;
  int local_18;
  ATLSTRINGRESOURCEIMAGE *local_14;
  uint local_8;
  undefined4 uStack_4;
  
  lpString = param_1;
  uStack_4 = 8;
  if (param_1 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    param_1 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  }
  else {
    param_1 = param_1 + -0x28;
  }
  local_18 = 0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (param_2 == (LPCWSTR)0x0) {
    param_2 = (LPCWSTR)0x0;
LAB_1000889c:
    local_8._0_1_ = 1;
    lpString = FUN_10007d93(*(ATLSTRINGRESOURCEIMAGE **)(param_1 + 0x44));
    local_8._0_1_ = 4;
    local_14 = lpString;
    if (lpString == (ATLSTRINGRESOURCEIMAGE *)0x0) {
      local_8 = CONCAT31(local_8._1_3_,1);
      CoTaskMemFree((LPVOID)0x0);
      lVar2 = -0x7ff8fff2;
      goto LAB_100088ca;
    }
  }
  else {
    param_2 = (LPCWSTR)Ordinal_2(param_2);
    if (param_2 != (LPCWSTR)0x0) goto LAB_1000889c;
    FUN_10001000(0x8007000e);
  }
  uVar1 = lstrlenW(L"\\");
  lVar2 = FUN_10003ee7(&param_2,&DAT_1002220c,uVar1);
  if (lVar2 < 0) {
    local_8 = CONCAT31(local_8._1_3_,1);
    CoTaskMemFree(lpString);
  }
  else {
    uVar1 = lstrlenW((LPCWSTR)lpString);
    lVar2 = FUN_10003ee7(&param_2,lpString,uVar1);
    if (-1 < lVar2) {
      WinHelpW(*(HWND *)(param_1 + 8),param_2,8,0);
      local_8._0_1_ = 1;
      CoTaskMemFree(lpString);
      local_14 = (ATLSTRINGRESOURCEIMAGE *)0x0;
      local_8 = (uint)local_8._1_3_ << 8;
      Ordinal_6(param_2);
      local_8 = 0xffffffff;
      FUN_1000128f(&local_18);
      return 0;
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    CoTaskMemFree(lpString);
  }
LAB_100088ca:
  local_14 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(param_2);
  local_8 = 0xffffffff;
  FUN_1000128f(&local_18);
  return lVar2;
}



// Function: FUN_1000899d at 1000899d

undefined4 FUN_1000899d(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000872c(&PTR_DAT_1002e050,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100089c1 at 100089c1

void FUN_100089c1(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000876c(&PTR_DAT_1002e050,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100089e1 at 100089e1

void FUN_100089e1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_1000880d(&PTR_DAT_1002e050,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100089ef at 100089ef

undefined4 FUN_100089ef(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000872c(&PTR_DAT_1002e06c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10008a13 at 10008a13

void FUN_10008a13(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000876c(&PTR_DAT_1002e06c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008a33 at 10008a33

void FUN_10008a33(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_1000880d(&PTR_DAT_1002e06c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: Catch@10008a9f at 10008a9f

undefined1 * Catch_10008a9f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10008aa9;
}



// Function: FUN_10008af1 at 10008af1

void __thiscall FUN_10008af1(void *this,uint param_1,undefined4 *param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)wcslen(param_3);
  FUN_1000821b(this,param_1,param_2,(undefined4 *)param_3,puVar1);
  return;
}



// Function: FUN_10008b17 at 10008b17

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008b17(void *this,void *param_1,uint param_2,uint param_3)

{
  FUN_10007fb1(param_1,(undefined4 *)this,param_2,param_3);
  return param_1;
}



// Function: FUN_10008b50 at 10008b50

HWND __thiscall FUN_10008b50(void *this,HWND param_1,LPARAM param_2)

{
  int iVar1;
  HWND pHVar2;
  
  iVar1 = FUN_10003369((void *)((int)this + 0x14),0,0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    pHVar2 = (HWND)0x0;
  }
  else {
    FUN_1000603f(0x1003139c,(DWORD *)((int)this + 8),(DWORD *)this);
    pHVar2 = CreateDialogParamW(DAT_10031344,(LPCWSTR)0x65,param_1,FUN_1000837a,param_2);
  }
  return pHVar2;
}



// Function: basic_string<> at 10008b9f

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



// Function: FUN_10008bc7 at 10008bc7

void __fastcall FUN_10008bc7(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  int *piVar5;
  code *pcVar6;
  tagPOINT local_a8;
  tagPOINT local_a0;
  tagPOINT local_98;
  tagPOINT local_90;
  int local_88;
  LONG local_84;
  LONG local_80;
  int local_7c;
  HDWP local_78;
  int local_74;
  int *local_70;
  HWND local_6c;
  tagRECT local_68;
  tagRECT local_58;
  tagRECT local_48;
  tagRECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  local_74 = param_1;
  iVar3 = __RTDynamicCast(param_1,0,
                          &CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::
                           RTTI_Type_Descriptor,
                          &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  local_6c = *(HWND *)(iVar3 + 8);
  local_38.left = 0;
  local_38.top = 0;
  local_38.right = 0;
  local_38.bottom = 0;
  GetClientRect(local_6c,&local_38);
  piVar5 = (int *)**(int **)(param_1 + 0x5c);
  local_70 = piVar5;
  local_78 = BeginDeferWindowPos(*(int *)(param_1 + 0x60));
  if (piVar5 != *(int **)(param_1 + 0x5c)) {
    do {
      puVar1 = (undefined4 *)piVar5[2];
      if (puVar1 != (undefined4 *)0x0) {
        local_28.left = 0;
        local_28.top = 0;
        local_28.right = 0;
        local_28.bottom = 0;
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        BVar4 = GetWindowRect((HWND)*puVar1,&local_28);
        pcVar6 = ScreenToClient_exref;
        if (BVar4 != 0) {
          local_a0.x = local_28.right;
          local_a0.y = local_28.top;
          local_98.x = local_28.left;
          local_98.y = local_28.bottom;
          ScreenToClient((HWND)*puVar1,&local_a0);
          ScreenToClient((HWND)*puVar1,&local_98);
          local_28.right = local_a0.x;
          local_28.top = local_a0.y;
          local_28.left = local_98.x;
          local_28.bottom = local_98.y;
          local_68.left = 0;
          local_68.top = 0;
          local_68.right = 0;
          local_68.bottom = 0;
          GetWindowRect(local_6c,&local_68);
          if ((HWND)puVar1[0xb] == (HWND)0x0) {
            local_18.left = ((local_38.right - local_38.left) * puVar1[3]) / 100 + puVar1[5];
            local_18.top = ((local_38.bottom - local_38.top) * puVar1[4]) / 100 + puVar1[6];
          }
          else {
            local_58.left = 0;
            local_58.top = 0;
            local_58.right = 0;
            local_58.bottom = 0;
            GetWindowRect((HWND)puVar1[0xb],&local_58);
            local_90.x = local_58.left;
            local_90.y = local_58.top;
            local_a8.x = local_58.right;
            local_a8.y = local_58.bottom;
            ScreenToClient(local_6c,&local_90);
            ScreenToClient(local_6c,&local_a8);
            local_18.left = puVar1[5];
            local_58.left = local_90.x;
            local_58.top = local_90.y;
            local_58.right = local_a8.x;
            local_58.bottom = local_a8.y;
            local_18.top = local_a8.y;
            pcVar6 = ScreenToClient_exref;
          }
          if ((HWND)puVar1[0xc] == (HWND)0x0) {
            local_18.right = ((local_38.right - local_38.left) * puVar1[7]) / 100 + puVar1[9];
            local_18.bottom = ((local_38.bottom - local_38.top) * puVar1[8]) / 100 + puVar1[10];
          }
          else {
            local_48.left = 0;
            local_48.top = 0;
            local_48.right = 0;
            local_48.bottom = 0;
            GetWindowRect((HWND)puVar1[0xc],&local_48);
            local_80 = local_48.left;
            local_7c = local_48.top;
            local_88 = local_48.right;
            local_84 = local_48.bottom;
            (*pcVar6)(local_6c,&local_80);
            (*pcVar6)(local_6c,&local_88);
            local_48.left = local_80;
            local_48.top = local_7c;
            local_48.right = local_88;
            local_48.bottom = local_84;
            local_18.right = local_88;
            local_18.bottom = local_7c;
          }
          BVar4 = EqualRect(&local_18,&local_28);
          param_1 = local_74;
          if (BVar4 == 0) {
            iVar3 = puVar1[1];
            if (iVar3 != 0) {
              MoveWindow((HWND)*puVar1,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar1,&local_18,1);
              UpdateWindow(local_6c);
            }
            iVar2 = puVar1[2];
            if (iVar2 != 0) {
              MoveWindow((HWND)*puVar1,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar1,&local_18,1);
              UpdateWindow(local_6c);
            }
            param_1 = local_74;
            if (iVar2 == 0 && iVar3 == 0) {
              DeferWindowPos(local_78,(HWND)*puVar1,(HWND)0x0,local_18.left,local_18.top,
                             local_18.right - local_18.left,local_18.bottom - local_18.top,0x14);
              param_1 = local_74;
            }
          }
        }
      }
      piVar5 = (int *)*local_70;
      local_70 = piVar5;
    } while (piVar5 != (int *)*(int *)(param_1 + 0x5c));
  }
  EndDeferWindowPos(local_78);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008f55 at 10008f55

void __thiscall FUN_10008f55(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  undefined4 *puVar1;
  void *local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_8 = this;
  if ((param_2 == (int *)**this) && (param_3 == *this)) {
    FUN_100083ff((int *)this);
                    /* WARNING: Load size is inaccurate */
    param_3 = *this;
  }
  else {
    while (param_2 != param_3) {
      puVar1 = (undefined4 *)FUN_100083c7(this,(int *)&local_8,param_2);
      param_2 = (int *)*puVar1;
    }
  }
  *param_1 = param_3;
  return;
}



// Function: FUN_10008f98 at 10008f98

void __cdecl FUN_10008f98(DLGTEMPLATE *param_1,int *param_2,char param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined4 local_4c;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  local_4c = 0;
  FUN_100031c7((int)param_1,param_2);
  iVar1 = FUN_10006976(param_1,local_48,(undefined2 *)&local_4c);
  if (iVar1 == 0) {
    uVar3 = 0;
    pwVar2 = (wchar_t *)0x0;
  }
  else {
    pwVar2 = local_48;
    uVar3 = local_4c;
  }
  FUN_10008428(pwVar2,(ushort)uVar3,param_2,param_3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008ffa at 10008ffa

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10008ffa(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_1000250b();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_1000250b();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_100090d4();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10002da0(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_1000128f(&local_42c);
  FUN_10017306();
  return;
}



// Function: Catch@100090bf at 100090bf

undefined * Catch_100090bf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100090cc;
}



// Function: FUN_100090d4 at 100090d4

void FUN_100090d4(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000250b();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10008517((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10002da0((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000128f((int *)(unaff_EBP + -0x428));
  FUN_10017306();
  return;
}



// Function: FUN_1000915e at 1000915e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000915e(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10008ffa(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_1000128f(local_14);
  return uVar1;
}



// Function: FUN_1000919f at 1000919f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000919f(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_1000128f(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10008ffa(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_1000128f(local_14);
  }
  return uVar1;
}



// Function: FUN_100091fb at 100091fb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100091fb(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10008ffa(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_1000128f(local_14);
  return uVar1;
}



// Function: FUN_1000923b at 1000923b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000923b(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_1000128f(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10008ffa(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_1000128f(local_14);
  }
  return uVar1;
}



// Function: FUN_10009296 at 10009296

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009296(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_10006ba5(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_10031340;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10031340,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000250b();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000128f((int *)&local_a48);
        goto LAB_10009318;
      }
      FUN_10002646(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_1000242e(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000128f((int *)&local_a48);
          goto LAB_10009318;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10006ba5(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10006ba5(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_1000923b(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_1000919f(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000128f((int *)&local_a48);
  }
LAB_10009318:
  local_8 = 0xffffffff;
  FUN_10005583(&local_a60);
  FUN_100172f7();
  return;
}



// Function: FUN_10009499 at 10009499

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009499(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_10006ba5(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_10031340;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10031340,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000250b();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000128f((int *)&local_a48);
        goto LAB_10009512;
      }
      FUN_10002646(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_1000242e(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000128f((int *)&local_a48);
          goto LAB_10009512;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10006ba5(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10006ba5(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_100091fb(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_1000915e(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000128f((int *)&local_a48);
  }
LAB_10009512:
  local_8 = 0xffffffff;
  FUN_10005583(&local_a5c);
  FUN_100172f7();
  return;
}



// Function: FUN_10009690 at 10009690

undefined4 FUN_10009690(int *param_1,HWND param_2,int *param_3)

{
  undefined4 uVar1;
  HWND pHVar2;
  int *piVar3;
  
  if (param_1 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = param_1 + -10;
  }
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    pHVar2 = FUN_10008b50(piVar3 + 1,param_2,0);
    piVar3[2] = (int)pHVar2;
    (**(code **)(*param_1 + 0x24))(param_1,param_3);
    param_1[4] = param_3[2] - *param_3;
    param_1[5] = param_3[3] - param_3[1];
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100096e3 at 100096e3

undefined4 FUN_100096e3(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  DLGTEMPLATE *pDVar2;
  ATLSTRINGRESOURCEIMAGE *pAVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_1 + -0x28;
  }
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    hResInfo = FindResourceW(DAT_10031344,(LPCWSTR)0x65,(LPCWSTR)0x5);
    if (((hResInfo != (HRSRC)0x0) &&
        (hResData = LoadResource(DAT_10031344,hResInfo), hResData != (HGLOBAL)0x0)) &&
       (pDVar2 = (DLGTEMPLATE *)LockResource(hResData), pDVar2 != (DLGTEMPLATE *)0x0)) {
      FUN_10008f98(pDVar2,(int *)(param_1 + 0x10),'\x01');
      *param_2 = 0x1c;
      pAVar3 = FUN_10007d93(*(ATLSTRINGRESOURCEIMAGE **)(iVar4 + 0x40));
      param_2[1] = pAVar3;
      param_2[2] = *(int *)(param_1 + 0x10);
      param_2[3] = *(undefined4 *)(param_1 + 0x14);
      pAVar3 = FUN_10007d93(*(ATLSTRINGRESOURCEIMAGE **)(iVar4 + 0x44));
      param_2[5] = pAVar3;
      pAVar3 = FUN_10007d93(*(ATLSTRINGRESOURCEIMAGE **)(iVar4 + 0x48));
      param_2[4] = pAVar3;
      param_2[6] = *(undefined4 *)(iVar4 + 0x4c);
      return 0;
    }
    uVar1 = 0x8000ffff;
  }
  return uVar1;
}



// Function: FUN_10009798 at 10009798

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10009798(int *param_1)

{
  int iVar1;
  size_t sVar2;
  LPCWSTR ***ppppWVar3;
  wchar_t ****_Str;
  undefined4 uStack_114;
  LPCWSTR **pppWStack_110;
  undefined1 auStack_f4 [28];
  LPCWSTR **pppWStack_d8;
  HMODULE local_c4;
  undefined1 *local_c0;
  undefined2 local_bc [8];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined2 local_a0 [8];
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_84 [28];
  undefined1 local_68 [28];
  wchar_t ***local_4c [4];
  int local_3c;
  uint local_38;
  LPCWSTR **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb4;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_a8 = 7;
  local_ac = 0;
  local_bc[0] = 0;
  local_8._1_3_ = 0;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (wchar_t ***)((uint)local_4c[0] & 0xffff0000);
  local_8._0_1_ = 3;
  pppWStack_d8 = (LPCWSTR **)local_30;
  local_c0 = auStack_f4;
  basic_string<>(auStack_f4,(undefined4 *)&stack0x00000004);
  local_8 = CONCAT31(local_8._1_3_,3);
  local_c0 = (undefined1 *)(**(code **)(*param_1 + 0x40))();
  ppppWVar3 = (LPCWSTR ***)local_30[0];
  if (local_1c < 8) {
    ppppWVar3 = local_30;
  }
  local_c4 = LoadLibraryW((LPCWSTR)ppppWVar3);
  if ((local_c0 != (undefined1 *)0x0) || (local_c4 == (HMODULE)0x0)) {
    local_c0 = (undefined1 *)(**(code **)(*param_1 + 0x28))();
    ppppWVar3 = (LPCWSTR ***)local_30[0];
    if (local_1c < 8) {
      ppppWVar3 = local_30;
    }
    local_c4 = LoadLibraryW((LPCWSTR)ppppWVar3);
    if ((local_c0 != (undefined1 *)0x0) || (local_c4 == (HMODULE)0x0)) {
      iVar1 = (**(code **)(*param_1 + 0x14))();
      if (((iVar1 != 0) || (local_3c == 0)) &&
         ((iVar1 = (**(code **)(*param_1 + 0x10))(), iVar1 != 0 || (local_3c == 0)))) {
        sVar2 = wcslen(L"EN");
        FID_conflict_assign(local_4c,(undefined4 *)&DAT_10020ab4,sVar2);
      }
      FUN_10001d86(local_68,L"_");
      local_8._0_1_ = 5;
      _Str = (wchar_t ****)local_4c[0];
      if (local_38 < 8) {
        _Str = local_4c;
      }
      sVar2 = wcslen((wchar_t *)_Str);
      FUN_10008081(local_68,_Str,sVar2);
      sVar2 = wcslen(L".");
      FUN_10008081(local_68,(undefined4 *)&DAT_10022264,sVar2);
      FUN_10001d86(local_84,L"_EN.");
      local_8._0_1_ = 6;
      (**(code **)(*param_1 + 0x38))();
      local_8._0_1_ = 5;
      pppWStack_110 = (LPCWSTR **)0x1000992a;
      FID_conflict__Tidy(local_84,'\x01',0);
      FUN_10001d86(local_84,L"_en.");
      local_8._0_1_ = 7;
      pppWStack_110 = (LPCWSTR **)local_30;
      uStack_114 = 0x1000994e;
      (**(code **)(*param_1 + 0x38))();
      local_8._0_1_ = 5;
      FID_conflict__Tidy(local_84,'\x01',0);
      ppppWVar3 = (LPCWSTR ***)local_30[0];
      if (local_1c < 8) {
        ppppWVar3 = local_30;
      }
      local_c4 = LoadLibraryW((LPCWSTR)ppppWVar3);
      local_8 = CONCAT31(local_8._1_3_,3);
      FID_conflict__Tidy(local_68,'\x01',0);
      if (local_c4 == (HMODULE)0x0) {
        GetLastError();
        goto LAB_100099b3;
      }
    }
  }
  (**(code **)(*param_1 + 0x20))();
  param_1[1] = 1;
LAB_100099b3:
  local_8c = 7;
  local_90 = 0;
  local_a0[0] = 0;
  local_8._0_1_ = 8;
  local_c0 = (undefined1 *)&uStack_114;
  basic_string<>(&uStack_114,(undefined4 *)&stack0x00000004);
  local_8._0_1_ = 8;
  (**(code **)(*param_1 + 0x44))();
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_a0,'\x01',0);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_bc,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(&stack0x00000004,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_10009a5f at 10009a5f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009a5f(LPCWSTR param_1)

{
  LPCWSTR *ppWVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  uint in_stack_00000018;
  void *in_stack_00000020;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  ulong local_220;
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x21c;
  local_22c = 0;
  local_228 = 0;
  local_224 = 0;
  local_8 = 1;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_220 = 0x208;
  ppWVar1 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar1 = &param_1;
  }
  iVar2 = FUN_10002744(&local_22c,(HKEY)0x80000002,(LPCWSTR)ppWVar1,0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_22c,L"ResourceDLL",&local_21c,&local_220);
    if ((lVar3 == 0) && (local_220 != 0)) {
      sVar4 = wcslen(&local_21c);
      FID_conflict_assign(in_stack_00000020,(undefined4 *)&local_21c,sVar4);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FUN_100026cd(&local_22c);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(&param_1,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_10009b4c at 10009b4c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009b4c(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  ulong local_23c;
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_23c = 0x208;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}");
  FUN_10008081(local_238,(undefined4 *)L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_248,L"ResourceDLL",&local_21c,&local_23c);
    if ((lVar3 == 0) && (local_23c != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_248);
  FUN_100172f7();
  return;
}



// Function: FUN_10009c77 at 10009c77

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10009c77(void *this,wchar_t *param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10009c83;
  puVar1 = FUN_10001d86(local_30,param_1);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 8))(puVar1,param_2);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_10009cbd at 10009cbd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009cbd(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  ulong local_23c;
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_23c = 0x208;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\cs\\");
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"Locale");
  FUN_10008081(local_238,(undefined4 *)L"Locale",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_248,L"LanguageExt",&local_21c,&local_23c);
    if ((lVar3 == 0) && (local_23c != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_248);
  FUN_100172f7();
  return;
}



// Function: FUN_10009de8 at 10009de8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009de8(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  ulong local_258;
  undefined4 local_254 [7];
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 600;
  local_264 = 0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_258 = 0x208;
  FUN_10001d86(local_254,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10007fdc(local_238,local_254,0,0xffffffff);
  sVar1 = wcslen(L"\\AddIns\\");
  FUN_10008081(local_238,(undefined4 *)L"\\AddIns\\",sVar1);
  sVar1 = wcslen(L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}");
  FUN_10008081(local_238,(undefined4 *)L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_264,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_264,L"LanguageExt",&local_21c,&local_258);
    if ((lVar3 == 0) && (local_258 != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_254,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_264);
  FUN_100172f7();
  return;
}



// Function: FUN_10009f65 at 10009f65

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009f65(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  ulong local_258;
  undefined4 local_254 [7];
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 600;
  local_264 = 0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_258 = 0x208;
  FUN_10001d86(local_254,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10007fdc(local_238,local_254,0,0xffffffff);
  sVar1 = wcslen(L"\\AddIns\\");
  FUN_10008081(local_238,(undefined4 *)L"\\AddIns\\",sVar1);
  sVar1 = wcslen(L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}");
  FUN_10008081(local_238,(undefined4 *)L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_264,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_264,L"ResourceDLL",&local_21c,&local_258);
    if ((lVar3 == 0) && (local_258 != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_254,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_264);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a0e1 at 1000a0e1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000a0e1(void *this,undefined4 param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  ulong local_444;
  LPCWSTR *local_440 [5];
  uint local_42c;
  wchar_t local_424;
  undefined1 local_422 [518];
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x448;
  local_450 = 0;
  local_44c = 0;
  local_448 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_424 = L'\0';
  memset(local_422,0,0x206);
  local_444 = 0x208;
  FUN_10001d86(local_440,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}");
  FUN_10008081(local_440,(undefined4 *)L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}",sVar1);
  if (local_42c < 8) {
    local_440[0] = (LPCWSTR *)local_440;
  }
  iVar2 = FUN_10002744(&local_450,(HKEY)0x80000002,(LPCWSTR)local_440[0],0x2001f);
  if (iVar2 == 0) {
    iVar2 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_450,L"XMLResource",&local_21c,&local_444);
    local_444 = 0x208;
  }
  ATL::CRegKey::QueryStringValue((CRegKey *)&local_450,L"FriendlyName",&local_424,&local_444);
  if ((iVar2 == 0) && (local_444 != 0)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0xc))(&local_21c,param_1);
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_440,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_450);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a24d at 1000a24d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000a24d(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  ulong local_23c;
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_23c = 0x208;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}");
  FUN_10008081(local_238,(undefined4 *)L"{B7B056DE-F426-4199-9A8D-53173A6AEC83}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue((CRegKey *)&local_248,L"BaseName",&local_21c,&local_23c);
    if ((lVar3 == 0) && (local_23c != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_248);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a378 at 1000a378

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000a378(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  ulong local_23c;
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_23c = 0x208;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)");
  FUN_10008081(local_238,(undefined4 *)L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_248,L"ResourceDLL",&local_21c,&local_23c);
    if ((lVar3 == 0) && (local_23c != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_248);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a4a3 at 1000a4a3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000a4a3(void *this,wchar_t ****param_1,void *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  wchar_t ******local_50;
  undefined4 local_4c [4];
  undefined4 local_3c;
  undefined4 local_38;
  wchar_t ******local_30 [4];
  undefined4 *local_20;
  uint local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_50 = (wchar_t ******)param_1;
  local_1c = 7;
  local_20 = (undefined4 *)0x0;
  local_30[0] = (wchar_t ******)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar2 = (**(code **)(*this + 0x14))(local_30);
                    /* WARNING: Load size is inaccurate */
  if (((((iVar2 == 0) && (local_20 != (undefined4 *)0x0)) ||
       ((iVar2 = (**(code **)(*this + 0x10))(local_30), iVar2 == 0 &&
        (local_20 != (undefined4 *)0x0)))) ||
      (FUN_10001bf4(param_2,local_50,0,0xffffffff), iVar2 == 0)) && (local_20 != (undefined4 *)0x0))
  {
    local_38 = 7;
    local_3c = 0;
    local_4c[0]._0_2_ = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10001bf4(local_4c,local_50,0,0xffffffff);
    puVar1 = local_20;
    local_50 = (wchar_t ******)0x5f;
    uVar3 = FUN_1000365f(local_4c,(ushort *)&local_50,0xffffffff,1);
    local_50 = (wchar_t ******)0x2e;
    uVar4 = FUN_1000365f(local_4c,(ushort *)&local_50,0xffffffff,1);
    if ((uVar3 != 0xffffffff) && ((undefined4 *)((uVar4 - uVar3) + -1) == local_20)) {
      local_50 = local_30[0];
      if (local_1c < 8) {
        local_50 = (wchar_t ******)local_30;
      }
      puVar5 = (undefined4 *)wcslen((wchar_t *)local_50);
      FUN_1000821b(local_4c,uVar3 + 1,puVar1,local_50,puVar5);
    }
    FUN_10001bf4(param_2,local_4c,0,0xffffffff);
    local_8 = local_8 & 0xffffff00;
    FID_conflict__Tidy(local_4c,'\x01',0);
  }
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a5e0 at 1000a5e0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000a5e0(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  ulong local_258;
  undefined4 local_254 [7];
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 600;
  local_264 = 0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_258 = 0x208;
  FUN_10001d86(local_254,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10007fdc(local_238,local_254,0,0xffffffff);
  sVar1 = wcslen(L"\\AddIns\\");
  FUN_10008081(local_238,(undefined4 *)L"\\AddIns\\",sVar1);
  sVar1 = wcslen(L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)");
  FUN_10008081(local_238,(undefined4 *)L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_264,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_264,L"LanguageExt",&local_21c,&local_258);
    if ((lVar3 == 0) && (local_258 != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_254,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_264);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a75c at 1000a75c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000a75c(int *param_1)

{
  int iVar1;
  size_t sVar2;
  undefined **ppuVar3;
  uint uVar4;
  undefined2 local_30 [8];
  int local_20;
  undefined4 local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = 0;
  local_8 = 0;
  iVar1 = (**(code **)(*param_1 + 0x10))(local_30);
  if ((iVar1 != 0) || (local_20 == 0)) {
    sVar2 = wcslen(L"EN");
    FID_conflict_assign(local_30,(undefined4 *)&DAT_10020ab4,sVar2);
  }
  uVar4 = 0;
  if (PTR_DAT_1002d150 != (undefined *)0x0) {
    ppuVar3 = &PTR_DAT_1002d150;
    do {
      iVar1 = FUN_100053fb(local_30,(wchar_t *)*ppuVar3);
      if (iVar1 == 0) break;
      uVar4 = uVar4 + 1;
      ppuVar3 = &PTR_DAT_1002d150 + (uVar4 & 0xffff);
    } while (*ppuVar3 != (undefined *)0x0);
  }
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a7f1 at 1000a7f1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000a7f1(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  ulong local_258;
  undefined4 local_254 [7];
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 600;
  local_264 = 0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_258 = 0x208;
  FUN_10001d86(local_254,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10007fdc(local_238,local_254,0,0xffffffff);
  sVar1 = wcslen(L"\\AddIns\\");
  FUN_10008081(local_238,(undefined4 *)L"\\AddIns\\",sVar1);
  sVar1 = wcslen(L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)");
  FUN_10008081(local_238,(undefined4 *)L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_264,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_264,L"ResourceDLL",&local_21c,&local_258);
    if ((lVar3 == 0) && (local_258 != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_254,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_264);
  FUN_100172f7();
  return;
}



// Function: FUN_1000a96d at 1000a96d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000a96d(void *this,undefined4 param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  ulong local_444;
  LPCWSTR *local_440 [5];
  uint local_42c;
  wchar_t local_424;
  undefined1 local_422 [518];
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x448;
  local_450 = 0;
  local_44c = 0;
  local_448 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_424 = L'\0';
  memset(local_422,0,0x206);
  local_444 = 0x208;
  FUN_10001d86(local_440,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)");
  FUN_10008081(local_440,(undefined4 *)L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)",sVar1);
  if (local_42c < 8) {
    local_440[0] = (LPCWSTR *)local_440;
  }
  iVar2 = FUN_10002744(&local_450,(HKEY)0x80000002,(LPCWSTR)local_440[0],0x2001f);
  if (iVar2 == 0) {
    iVar2 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_450,L"XMLResource",&local_21c,&local_444);
    local_444 = 0x208;
  }
  ATL::CRegKey::QueryStringValue((CRegKey *)&local_450,L"FriendlyName",&local_424,&local_444);
  if ((iVar2 == 0) && (local_444 != 0)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0xc))(&local_21c,param_1);
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_440,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_450);
  FUN_100172f7();
  return;
}



// Function: FUN_1000aad9 at 1000aad9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000aad9(void *param_1)

{
  size_t sVar1;
  int iVar2;
  long lVar3;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  ulong local_23c;
  LPCWSTR *local_238 [5];
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [530];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_248 = 0;
  local_244 = 0;
  local_240 = 0;
  local_8 = 0;
  local_21c = L'\0';
  memset(local_21a,0,0x206);
  local_23c = 0x208;
  FUN_10001d86(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)");
  FUN_10008081(local_238,(undefined4 *)L"(E880F1B4-95B6-4f3f-ADA5-91D5DABDE888)",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = FUN_10002744(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue((CRegKey *)&local_248,L"BaseName",&local_21c,&local_23c);
    if ((lVar3 == 0) && (local_23c != 0)) {
      sVar1 = wcslen(&local_21c);
      FID_conflict_assign(param_1,(undefined4 *)&local_21c,sVar1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_238,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_248);
  FUN_100172f7();
  return;
}



// Function: FUN_1000ac04 at 1000ac04

void FUN_1000ac04(void *param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  uint uVar4;
  wchar_t *pwVar5;
  
  pwVar2 = param_2;
  if (7 < *(uint *)(param_2 + 10)) {
    param_2 = *(wchar_t **)param_2;
  }
  sVar3 = wcslen(param_2);
  for (uVar4 = FUN_100048a3(param_1,(ushort *)param_2,0,sVar3); uVar4 != 0xffffffff;
      uVar4 = FUN_100048a3(param_1,(ushort *)param_2,iVar1 + uVar4,sVar3)) {
    pwVar5 = param_3;
    if (7 < *(uint *)(param_3 + 10)) {
      pwVar5 = *(wchar_t **)param_3;
    }
    FUN_10008af1(param_1,uVar4,*(undefined4 **)(pwVar2 + 8),pwVar5);
    iVar1 = *(int *)(param_3 + 8);
    param_2 = pwVar2;
    if (7 < *(uint *)(pwVar2 + 10)) {
      param_2 = *(wchar_t **)pwVar2;
    }
    sVar3 = wcslen(param_2);
  }
  return;
}



// Function: FUN_1000ac8a at 1000ac8a

void __thiscall
FUN_1000ac8a(void *this,undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  HWND hWnd;
  int iVar1;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  iVar1 = __RTDynamicCast(this,0,&CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::
                                  RTTI_Type_Descriptor,
                          &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar1 + 8);
  if ((param_2 != 4) && (param_2 != 3)) {
    if (*(int *)((int)this + 0x18) != 0) {
      FUN_10003ba7((int)this);
      InvalidateRect(hWnd,(RECT *)((int)this + 0x44),1);
      *(undefined4 *)((int)this + 0x20) = 1;
    }
    FUN_10008bc7((int)this);
    FUN_10008bc7((int)this);
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0x74;
  }
  GetWindowRect(*(HWND *)(iVar1 + 8),&local_18);
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0x74;
  }
  InvalidateRect(*(HWND *)(iVar1 + 8),&local_18,1);
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0x74;
  }
  UpdateWindow(*(HWND *)(iVar1 + 8));
  *param_4 = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ad64 at 1000ad64

void __cdecl FUN_1000ad64(undefined4 param_1,void *param_2)

{
  FID_conflict__Tidy(param_2,'\x01',0);
  return;
}



// Function: FUN_1000ad75 at 1000ad75

void __fastcall FUN_1000ad75(int param_1)

{
  int *this;
  int *piVar1;
  int local_8;
  
  this = (int *)(param_1 + 0x5c);
  piVar1 = *(int **)*this;
  local_8 = param_1;
  if (piVar1 != (int *)*this) {
    do {
      operator_delete((void *)piVar1[2]);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*this);
  }
  FUN_10008f55(this,&local_8,*(int **)*this,(int *)*this);
  return;
}



// Function: FUN_1000adaa at 1000adaa

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000adaa(void *this,void *param_1)

{
  int *piVar1;
  int local_74;
  wchar_t *local_70;
  undefined4 local_6c [7];
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0;
  __RTDynamicCast(this,0,&CContextSensitiveHelpProvider<class_CFuelSystemTableResetGTIS45PageImpl>::
                          RTTI_Type_Descriptor,
                  &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  FUN_10003e90(&local_70,(GUID *)&DAT_10023490);
  local_8._0_1_ = 1;
  FUN_10016152((undefined2 *)local_6c,local_70);
  local_8._0_1_ = 2;
  FUN_10001d86(local_34,L"");
  local_8._0_1_ = 3;
  FUN_10001d86(local_50,L"{");
  local_8._0_1_ = 4;
  FUN_100160ce(local_6c,local_50,local_34);
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_50,'\x01',0);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_34,'\x01',0);
  FUN_10001d86(local_50,L"");
  local_8._0_1_ = 5;
  FUN_10001d86(local_34,L"}");
  local_8._0_1_ = 6;
  FUN_100160ce(local_6c,local_34,local_50);
  local_8._0_1_ = 5;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_50,'\x01',0);
  piVar1 = FUN_10015f82(&local_74,local_6c);
  local_8._0_1_ = 7;
  FUN_10002f81(param_1,piVar1);
  local_8._0_1_ = 2;
  Ordinal_6(local_74);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_70);
  local_8 = 0xffffffff;
  FUN_10017306();
  return;
}



// Function: Catch@1000aeee at 1000aeee

undefined4 Catch_1000aeee(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000aee4;
}



// Function: FUN_1000aef8 at 1000aef8

void __cdecl FUN_1000aef8(void *param_1,void *param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = (void *)((int)param_1 + 0x1c)) {
    FUN_1000ad64(param_3,param_1);
  }
  return;
}



// Function: FUN_1000af17 at 1000af17

void FUN_1000af17(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_10009296(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000af20 at 1000af20

void FUN_1000af20(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10009499(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000af29 at 1000af29

void FUN_1000af29(int param_1)

{
  FUN_10009499((int *)&DAT_1002ff54,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000af41 at 1000af41

void FUN_1000af41(int param_1)

{
  FUN_10009499((int *)&DAT_1002ff54,0x67,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_1000af59 at 1000af59

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000af59(int *param_1)

{
  int iVar1;
  size_t sVar2;
  LPCWSTR *****ppppppWVar3;
  HMODULE pHVar4;
  wchar_t ******_Str;
  HMODULE local_a8;
  int local_a4;
  undefined1 local_a0 [28];
  undefined4 local_84 [4];
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_68 [28];
  wchar_t *****local_4c [4];
  int local_3c;
  uint local_38;
  LPCWSTR ****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR ****)((uint)local_30[0] & 0xffff0000);
  local_70 = 7;
  local_74 = 0;
  local_84[0]._0_2_ = 0;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (wchar_t *****)((uint)local_4c[0] & 0xffff0000);
  local_8 = 2;
  iVar1 = (**(code **)(*param_1 + 0x24))(local_30);
  ppppppWVar3 = (LPCWSTR *****)local_30[0];
  if (local_1c < 8) {
    ppppppWVar3 = local_30;
  }
  local_a8 = LoadLibraryW((LPCWSTR)ppppppWVar3);
  if ((iVar1 == 0) && (local_a8 != (HMODULE)0x0)) {
LAB_1000b1e7:
    (**(code **)(*param_1 + 0x20))(local_a8);
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x28))(local_30);
    ppppppWVar3 = (LPCWSTR *****)local_30[0];
    if (local_1c < 8) {
      ppppppWVar3 = local_30;
    }
    local_a8 = LoadLibraryW((LPCWSTR)ppppppWVar3);
    if ((iVar1 == 0) && (local_a8 != (HMODULE)0x0)) goto LAB_1000b1e7;
    iVar1 = (**(code **)(*param_1 + 0x14))(local_4c);
    if (((iVar1 != 0) || (local_a4 = 0, local_3c == 0)) &&
       ((local_a4 = (**(code **)(*param_1 + 0x10))(local_4c), local_a4 != 0 || (local_3c == 0)))) {
      sVar2 = wcslen(L"EN");
      FID_conflict_assign(local_4c,(undefined4 *)&DAT_10020ab4,sVar2);
    }
    FUN_10001d86(local_68,L"_");
    local_8._0_1_ = 3;
    _Str = (wchar_t ******)local_4c[0];
    if (local_38 < 8) {
      _Str = local_4c;
    }
    sVar2 = wcslen((wchar_t *)_Str);
    FUN_10008081(local_68,_Str,sVar2);
    sVar2 = wcslen(L".");
    FUN_10008081(local_68,(undefined4 *)&DAT_10022264,sVar2);
    FUN_10001d86(local_a0,L"_EN.");
    local_8._0_1_ = 4;
    (**(code **)(*param_1 + 0x38))(local_30,local_a0,local_68);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_a0,'\x01',0);
    FUN_10001d86(local_a0,L"_en.");
    local_8._0_1_ = 5;
    (**(code **)(*param_1 + 0x38))(local_30,local_a0,local_68);
    local_8 = CONCAT31(local_8._1_3_,3);
    FID_conflict__Tidy(local_a0,'\x01',0);
    ppppppWVar3 = (LPCWSTR *****)local_30[0];
    if (local_1c < 8) {
      ppppppWVar3 = local_30;
    }
    local_a8 = LoadLibraryW((LPCWSTR)ppppppWVar3);
    if (((local_a4 != 0) || (local_a8 == (HMODULE)0x0)) &&
       (iVar1 = (**(code **)(*param_1 + 0x30))(local_84), iVar1 == 0)) {
      FUN_10001bf4(local_30,local_84,0,0xffffffff);
      sVar2 = wcslen(L"Res_");
      FUN_10008081(local_30,(undefined4 *)L"Res_",sVar2);
      FUN_10007fdc(local_30,local_4c,0,0xffffffff);
      sVar2 = wcslen(L".dll");
      FUN_10008081(local_30,(undefined4 *)L".dll",sVar2);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FID_conflict__Tidy(local_68,'\x01',0);
    if (local_a8 != (HMODULE)0x0) goto LAB_1000b1e7;
    ppppppWVar3 = (LPCWSTR *****)local_30[0];
    if (local_1c < 8) {
      ppppppWVar3 = local_30;
    }
    pHVar4 = LoadLibraryW((LPCWSTR)ppppppWVar3);
    if (pHVar4 == (HMODULE)0x0) {
      GetLastError();
      goto LAB_1000b1f7;
    }
    (**(code **)(*param_1 + 0x20))(pHVar4);
  }
  param_1[1] = 1;
LAB_1000b1f7:
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_84,'\x01',0);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_1000b241 at 1000b241

undefined4 __thiscall FUN_1000b241(void *this)

{
  undefined4 *in_stack_00000010;
  
  FUN_1000ad75((int)this);
  *in_stack_00000010 = 0;
  return 0;
}



// Function: FUN_1000b255 at 1000b255

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000b255(void *this,void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_18 [4];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_18[0] = 0;
  local_8 = 2;
  puVar1 = (undefined4 *)((int)this + 0x10);
  iVar2 = Ordinal_7(*puVar1);
  if (iVar2 == 0) {
    FUN_1000adaa(this,puVar1);
  }
  FUN_10002fc6(param_1,*puVar1);
                    /* WARNING: Load size is inaccurate */
  uVar3 = (**(code **)(*this + 0x10))(local_18);
  iVar2 = Ordinal_7(local_18[0]);
  if (iVar2 != 0) {
    uVar4 = lstrlenW(L"-");
    FUN_10003ee7(param_1,&DAT_10022440,uVar4);
    FUN_10002fc6(param_1,local_18[0]);
  }
  local_8._0_1_ = 1;
  Ordinal_6(local_18[0]);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  return uVar3;
}



// Function: Catch@1000b2fd at 1000b2fd

undefined4 Catch_1000b2fd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000b2f2;
}



// Function: FUN_1000b307 at 1000b307

undefined4 __thiscall
FUN_1000b307(void *this,undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  undefined4 uVar1;
  
  if (param_6 == 0) {
    if (param_2 == 0xf) {
      param_6 = 1;
      uVar1 = FUN_1000505d(this);
    }
    else if (param_2 == 5) {
      param_6 = 1;
      uVar1 = FUN_1000ac8a(this,5,param_3,param_4,&param_6);
    }
    else {
      if (param_2 == 0x24) {
        uVar1 = FUN_10003a90(this,0x24,param_3,param_4);
        *param_5 = uVar1;
        return 1;
      }
      if (param_2 != 2) {
        return 0;
      }
      param_6 = 1;
      uVar1 = FUN_1000b241(this);
    }
    *param_5 = uVar1;
    if (param_6 != 0) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_1000b3a6 at 1000b3a6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000b3a6(void *this,void *param_1)

{
  uint uVar1;
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x1000b3b2;
  if (((*(uint *)((int)this + 0x40) & 2) == 0) && (**(uint **)((int)this + 0x24) != 0)) {
    uVar1 = **(uint **)((int)this + 0x24);
    if (uVar1 <= *(uint *)((int)this + 0x3c)) {
      uVar1 = *(uint *)((int)this + 0x3c);
    }
    basic_string<>(local_30,(undefined4 *)**(undefined4 **)((int)this + 0x14),
                   (int)(uVar1 - (int)**(undefined4 **)((int)this + 0x14)) >> 1);
    local_8 = 1;
    basic_string<>(param_1,(undefined4 *)local_30);
  }
  else {
    if (((*(uint *)((int)this + 0x40) & 4) == 0) && (**(int **)((int)this + 0x20) != 0)) {
      basic_string<>(local_30,(undefined4 *)**(undefined4 **)((int)this + 0x10),
                     (**(int **)((int)this + 0x20) + **(int **)((int)this + 0x30) * 2) -
                     (int)**(undefined4 **)((int)this + 0x10) >> 1);
      local_8 = 2;
    }
    else {
      local_1c = 7;
      local_20 = 0;
      local_30[0] = 0;
      local_8 = 3;
    }
    basic_string<>(param_1,(undefined4 *)local_30);
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_1000b470 at 1000b470

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_1000b470(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_10018e95;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000b49e at 1000b49e

void * __cdecl FUN_1000b49e(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_10001db8(param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: FUN_1000b4c2 at 1000b4c2

undefined4 __thiscall
FUN_1000b4c2(void *this,undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  local_8 = 1;
  if (param_6 != 0) {
    return 0;
  }
  iVar1 = FUN_1000b307((void *)((int)this + 0x70),param_1,param_2,param_3,param_4,param_5,0);
  if (iVar1 != 0) {
    return 1;
  }
  if (param_2 == 0x110) {
    local_8 = 1;
    uVar2 = FUN_10014999((undefined4 *)((int)this + -4));
  }
  else if (param_2 == 5) {
    local_8 = 1;
    uVar2 = FUN_1000ddf9((int)this + -4);
  }
  else if (param_2 == 0x111) {
    if ((short)param_3 == 0x66) {
      if ((short)((uint)param_3 >> 0x10) != 0) {
        return 0;
      }
      local_8 = 1;
      uVar2 = FUN_1000dddc((int)this + -4);
    }
    else {
      if (param_3 != 0x67) {
        return 0;
      }
      local_8 = 1;
      uVar2 = FUN_100156c5((undefined1 *)((int)this + -4));
    }
  }
  else {
    if (param_2 != 0x53) {
      return 0;
    }
    local_8 = 1;
    uVar2 = (**(code **)(*(int *)((int)this + 0xd8) + 4))(0x53,param_3,param_4,&local_8);
  }
  *param_5 = uVar2;
  if (local_8 == 0) {
    return 0;
  }
  return 1;
}



// Function: FUN_1000b5d1 at 1000b5d1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000b5d1(void *this,void *param_1)

{
  FUN_1000b3a6((void *)((int)this + 4),param_1);
  return param_1;
}



// Function: FUN_1000b602 at 1000b602

void __cdecl FUN_1000b602(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000b470(param_2,param_3);
  return;
}



// Function: FUN_1000b615 at 1000b615

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl
FUN_1000b615(undefined4 *param_1,undefined4 *param_2,void *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_1000b602(param_4,param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: Catch@1000b659 at 1000b659

void Catch_1000b659(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  for (pvVar1 = *(void **)(unaff_EBP + -0x14); pvVar1 != *(void **)(unaff_EBP + 0x10);
      pvVar1 = (void *)((int)pvVar1 + 0x1c)) {
    FUN_1000ad64(*(undefined4 *)(unaff_EBP + 0x14),pvVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b67b at 1000b67b

void __thiscall
FUN_1000b67b(void *this,undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  FUN_1000b4c2((void *)((int)this + -0x70),param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000b683 at 1000b683

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Removing unreachable block (ram,0x1000b81e) */
/* WARNING: Removing unreachable block (ram,0x1000b864) */

void FUN_1000b683(int param_1,wchar_t *param_2,undefined4 *param_3)

{
  code *pcVar1;
  size_t sVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  code *pcVar6;
  wchar_t *in_stack_fffffeb4;
  wchar_t *in_stack_fffffec0;
  int local_94;
  uint local_90;
  wchar_t *local_8c;
  code *local_88;
  undefined1 local_84 [28];
  undefined1 local_68 [28];
  undefined1 local_4c [28];
  undefined4 **local_30 [5];
  uint local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 300;
  local_8 = 0x1000b692;
  FUN_10001d86(local_30,L"");
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  FUN_10001d86(local_4c,param_2);
  pcVar6 = wcslen_exref;
  local_90 = 0;
  do {
    local_8c = (wchar_t *)0x0;
    local_8._0_1_ = 3;
    sVar2 = wcslen(L"</LicenseName>");
    uVar3 = FUN_100048a3(local_4c,(ushort *)L"</LicenseName>",local_90,sVar2);
    FUN_10008b17(local_4c,local_68,local_90,uVar3 - local_90);
    local_8._0_1_ = 4;
    FUN_10007e12(&stack0xfffffec4,2,1);
    local_8._0_1_ = 5;
    piVar4 = (int *)FUN_10005101((int *)&stack0xfffffec4,L".//*[@Name=\"");
    piVar4 = (int *)FUN_1000528c(piVar4,in_stack_fffffeb4);
    FUN_10005101(piVar4,in_stack_fffffec0);
    in_stack_fffffec0 = *(wchar_t **)(param_1 + 8);
    puVar5 = (undefined4 *)FUN_1000b5d1(&stack0xfffffec4,local_84);
    local_8._0_1_ = 6;
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) {
      local_94 = 0;
    }
    else {
      local_94 = Ordinal_2();
      if (local_94 == 0) goto LAB_1000b8ae;
    }
    local_8._0_1_ = 7;
    (**(code **)(*(int *)in_stack_fffffec0 + 0x94))();
    local_8._0_1_ = 6;
    Ordinal_6(local_94);
    local_8._0_1_ = 5;
    FID_conflict__Tidy(local_84,'\x01',0);
    local_88 = (code *)0x0;
    local_8._0_1_ = 8;
    (**(code **)(iRam00000000 + 0x88))(0,&local_88);
    pcVar1 = local_88;
    sVar2 = wcslen((wchar_t *)local_88);
    FUN_10008081(local_30,(undefined4 *)pcVar1,sVar2);
    local_8._0_1_ = 5;
    Ordinal_6(local_88);
    local_8._0_1_ = 4;
    FUN_10007a31((int)&stack0xfffffec4);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_68,'\x01',0);
    local_8._0_1_ = 1;
    sVar2 = wcslen(L"<LicenseName>");
    local_90 = FUN_100048a3(local_4c,(ushort *)L"<LicenseName>",uVar3,sVar2);
    in_stack_fffffeb4 = local_8c;
  } while (local_90 != 0xffffffff);
  if (local_1c < 8) {
    local_30[0] = local_30;
  }
  pcVar6 = (code *)0x0;
  if ((undefined4 ***)local_30[0] == (undefined4 ***)0x0) {
    local_88 = (code *)0x0;
  }
  else {
    while (local_88 = (code *)Ordinal_2(), local_88 == pcVar6) {
LAB_1000b8ae:
      FUN_10001000(0x8007000e);
    }
  }
  *param_3 = local_88;
  local_8._0_1_ = 1;
  local_88 = pcVar6;
  Ordinal_6();
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_4c,'\x01',(int)pcVar6);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',(int)pcVar6);
  FUN_100172f7();
  return;
}



// Function: FUN_1000b90e at 1000b90e

void __thiscall FUN_1000b90e(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  
  if (param_2 != param_3) {
    pvVar1 = FUN_1000b49e(param_3,*(undefined4 **)((int)this + 4),param_2);
    FUN_1000aef8(pvVar1,*(void **)((int)this + 4),(int)this + 0xc);
    *(void **)((int)this + 4) = pvVar1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000b952 at 1000b952

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_1000b952(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_3c [4];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x1000b95e;
  local_24 = 0xffffffff;
  FUN_1000173f(local_3c);
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  local_18[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 7;
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021f34,&local_20);
    FUN_100020b2(local_3c,iVar3);
    piVar2 = local_20;
    piVar4 = FUN_10015f82(&local_2c,(undefined4 *)&DAT_1002fe90);
    local_8._0_1_ = 8;
    iVar3 = (**(code **)(*piVar2 + 0x24))(piVar2,*piVar4,&local_1c);
    FUN_100020b2(local_3c,iVar3);
    local_8._0_1_ = 7;
    Ordinal_6(local_2c);
    iVar3 = (**(code **)*local_1c)(local_1c,&DAT_10021f44,local_18);
    FUN_100020b2(local_3c,iVar3);
    local_28 = 0xffffffff;
    (**(code **)(*local_18[0] + 0x88))(local_18[0],&local_28);
    if (local_18[0] != (int *)0x0) {
      if ((short)local_28 == -1) {
        local_24 = 0xffffffff;
      }
      else {
        iVar3 = (**(code **)(*local_18[0] + 0x5c))(local_18[0],&local_24);
        FUN_100020b2(local_3c,iVar3);
      }
    }
  }
  local_8._0_1_ = 5;
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8._0_1_ = 3;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return local_24;
}



// Function: Catch@1000ba95 at 1000ba95

undefined4 Catch_1000ba95(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000ba88;
}



// Function: _Uninitialized_move<> at 1000ba9f

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
_Uninitialized_move<>(undefined4 *param_1,undefined4 *param_2,void *param_3,undefined4 param_4)

{
  FUN_1000b615(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000babe at 1000babe

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000babe(void *this,undefined4 param_1,CComBSTR *param_2)

{
  HRESULT HVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_2c [3];
  undefined4 local_20;
  wchar_t *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0;
  FUN_1000173f(local_2c);
  local_20 = 0;
  local_18[0] = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  HVar1 = CoCreateInstance((IID *)&DAT_10021720,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021f24,local_18);
  FUN_100020b2(local_2c,HVar1);
  uVar2 = FUN_1000b952((int)this);
  iVar3 = (**(code **)(*local_18[0] + 0xc))(local_18[0],uVar2);
  FUN_100020b2(local_2c,iVar3);
  Ordinal_6(*(undefined4 *)param_2);
  *(undefined4 *)param_2 = 0;
  iVar3 = (**(code **)(*local_18[0] + 0x18))(local_18[0],param_1,0,&local_1c);
  FUN_100020b2(local_2c,iVar3);
  ATL::CComBSTR::Attach(param_2,local_1c);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = 0xffffffff;
  Ordinal_6(param_1);
  return local_20;
}



// Function: Catch@1000bb8e at 1000bb8e

undefined4 Catch_1000bb8e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000bb76;
}



// Function: FUN_1000bb9b at 1000bb9b

void __thiscall FUN_1000bb9b(void *this,undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_1000bbb7 at 1000bbb7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000bbb7(void *this,char *param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    pvVar3 = FUN_10003ae4(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_1000bb9b(this,*this,*(undefined4 **)((int)this + 4),pvVar3);
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    pvVar2 = *this;
    if (pvVar2 != (void *)0x0) {
      FUN_1000aef8(pvVar2,*(void **)((int)this + 4),(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    *(void **)((int)this + 8) = (void *)((int)param_1 * 0x1c + (int)pvVar3);
    *(void **)((int)this + 4) = (void *)(((iVar1 - (int)pvVar2) / 0x1c) * 0x1c + (int)pvVar3);
    *(void **)this = pvVar3;
  }
  return;
}



// Function: Catch@1000bc56 at 1000bc56

void Catch_1000bc56(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000bc69 at 1000bc69

void __thiscall FUN_1000bc69(void *this,int param_1)

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
    pcVar2 = (char *)FUN_10003990(this,uVar1);
    FUN_1000bbb7(this,pcVar2);
  }
  return;
}



// Function: FUN_1000bcbe at 1000bcbe

void __thiscall FUN_1000bcbe(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000bc69(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)((((int)param_1 - (int)puVar2) / 0x1c) * 0x1c + *this);
  }
  else if (puVar1 == *(undefined4 **)((int)this + 8)) {
    FUN_1000bc69(this,1);
  }
  FUN_1000b602((int)this + 0xc,*(void **)((int)this + 4),param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  return;
}



// Function: FUN_1000bd1e at 1000bd1e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_1000bd1e(void *param_1,ushort param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint local_38;
  uint local_34;
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x1000bd2a;
  FUN_1000b90e(param_3,&local_38,(undefined4 *)*param_3,(undefined4 *)param_3[1]);
  local_38 = (uint)param_2;
  local_34 = 0;
  uVar1 = FUN_100048a3(param_1,(ushort *)&local_38,0,1);
  if (uVar1 != 0xffffffff) {
    local_38 = (uint)param_2;
    do {
      puVar2 = (undefined4 *)FUN_10008b17(param_1,local_30,local_34,uVar1 - local_34);
      local_8 = 0;
      FUN_1000bcbe(param_3,puVar2);
      local_8 = 0xffffffff;
      FID_conflict__Tidy(local_30,'\x01',0);
      local_34 = uVar1 + 1;
      uVar1 = FUN_100048a3(param_1,(ushort *)&local_38,local_34,1);
    } while (uVar1 != 0xffffffff);
  }
  puVar2 = (undefined4 *)
           FUN_10008b17(param_1,local_30,local_34,*(int *)((int)param_1 + 0x10) - local_34);
  local_8 = 1;
  FUN_1000bcbe(param_3,puVar2);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_1000bdf6 at 1000bdf6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000bdf6(void *this,LPCWSTR param_1)

{
  size_t sVar1;
  LPCWSTR *ppWVar2;
  int iVar3;
  wchar_t *pwVar4;
  void *this_00;
  uint in_stack_00000018;
  int *in_stack_00000020;
  undefined4 local_a48;
  undefined4 local_a44;
  undefined4 local_a40;
  wchar_t *local_a3c;
  wchar_t *local_a38;
  ulong local_a34;
  undefined1 local_a30 [28];
  wchar_t local_a14 [1024];
  wchar_t local_214 [262];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa3c;
  local_a48 = 0;
  local_a44 = 0;
  local_a40 = 0;
  local_8 = 1;
  __RTDynamicCast(this,0,&CComNonAddInSecurity<class_CFuelSystemTableResetGTIS45LogicImpl>::
                          RTTI_Type_Descriptor,
                  &CFuelSystemTableResetGTIS45LogicImpl::RTTI_Type_Descriptor,0);
  StringFromCLSID((IID *)&DAT_100234a0,&local_a3c);
  local_a38 = local_a3c;
  sVar1 = wcslen(local_a3c);
  FUN_10008081(&param_1,(undefined4 *)local_a38,sVar1);
  CoTaskMemFree(local_a3c);
  ppWVar2 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar2 = &param_1;
  }
  iVar3 = FUN_10002744(&local_a48,(HKEY)0x80000002,(LPCWSTR)ppWVar2,0x2001f);
  if (iVar3 == 0) {
    local_a34 = 0x800;
    iVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_a48,L"SecurityFilePath",local_a14,&local_a34);
    local_a34 = 0x200;
    if (iVar3 == 0) {
      iVar3 = ATL::CRegKey::QueryStringValue
                        ((CRegKey *)&local_a48,L"SecurityFiles",local_214,&local_a34);
    }
    pwVar4 = (wchar_t *)0x0;
    if (iVar3 == 0) {
      FUN_10001d86(local_a30,local_214);
      local_8._0_1_ = 2;
      local_a38 = (wchar_t *)FUN_1000bd1e(local_a30,0x21,in_stack_00000020);
      local_8 = CONCAT31(local_8._1_3_,1);
      FID_conflict__Tidy(local_a30,'\x01',0);
      pwVar4 = local_a38;
    }
    if (0 < (int)pwVar4) {
      local_a34 = 0;
      local_a38 = pwVar4;
      do {
        this_00 = (void *)(*in_stack_00000020 + local_a34);
        sVar1 = wcslen(local_a14);
        FUN_10008123(this_00,0,(undefined4 *)local_a14,sVar1);
        local_a34 = local_a34 + 0x1c;
        local_a38 = (wchar_t *)((int)local_a38 + -1);
      } while (local_a38 != (wchar_t *)0x0);
    }
    FUN_100026cd(&local_a48);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_100026cd(&local_a48);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(&param_1,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_1000bfc4 at 1000bfc4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000bfc4(void *this,int *param_1)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  void *this_00;
  undefined4 local_a64;
  undefined4 local_a60;
  undefined4 local_a5c;
  wchar_t *local_a58;
  wchar_t *local_a54;
  ulong local_a50;
  undefined1 local_a4c [28];
  LPCWSTR **local_a30 [5];
  uint local_a1c;
  wchar_t local_a14 [1024];
  wchar_t local_214 [262];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa58;
  local_a64 = 0;
  local_a60 = 0;
  local_a5c = 0;
  local_8 = 0;
  FUN_10001d86(local_a30,L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  __RTDynamicCast(this,0,&CComSecurity<class_CFuelSystemTableResetGTIS45LogicImpl>::
                          RTTI_Type_Descriptor,
                  &CFuelSystemTableResetGTIS45LogicImpl::RTTI_Type_Descriptor,0);
  StringFromCLSID((IID *)&DAT_100234a0,&local_a58);
  local_a54 = local_a58;
  sVar1 = wcslen(local_a58);
  FUN_10008081(local_a30,(undefined4 *)local_a54,sVar1);
  CoTaskMemFree(local_a58);
  if (local_a1c < 8) {
    local_a30[0] = (LPCWSTR **)local_a30;
  }
  iVar2 = FUN_10002744(&local_a64,(HKEY)0x80000002,(LPCWSTR)local_a30[0],0x2001f);
  if (iVar2 == 0) {
    local_a50 = 0x800;
    iVar2 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_a64,L"SecurityFilePath",local_a14,&local_a50);
    local_a50 = 0x200;
    if (iVar2 == 0) {
      iVar2 = ATL::CRegKey::QueryStringValue
                        ((CRegKey *)&local_a64,L"SecurityFiles",local_214,&local_a50);
    }
    pwVar3 = (wchar_t *)0x0;
    if (iVar2 == 0) {
      FUN_10001d86(local_a4c,local_214);
      local_8._0_1_ = 2;
      local_a54 = (wchar_t *)FUN_1000bd1e(local_a4c,0x21,param_1);
      local_8 = CONCAT31(local_8._1_3_,1);
      FID_conflict__Tidy(local_a4c,'\x01',0);
      pwVar3 = local_a54;
    }
    if (0 < (int)pwVar3) {
      local_a50 = 0;
      local_a54 = pwVar3;
      do {
        this_00 = (void *)(*param_1 + local_a50);
        sVar1 = wcslen(local_a14);
        FUN_10008123(this_00,0,(undefined4 *)local_a14,sVar1);
        local_a50 = local_a50 + 0x1c;
        local_a54 = (wchar_t *)((int)local_a54 + -1);
      } while (local_a54 != (wchar_t *)0x0);
    }
    FUN_100026cd(&local_a64);
  }
  local_8 = local_8 & 0xffffff00;
  FID_conflict__Tidy(local_a30,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100026cd(&local_a64);
  FUN_100172f7();
  return;
}



// Function: operator== at 1000c1b3

/* Library Function - Single Match
    public: bool __thiscall ATL::CComBSTR::operator==(class ATL::CComBSTR const &)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

bool __thiscall ATL::CComBSTR::operator==(CComBSTR *this,CComBSTR *param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_314(*(undefined4 *)this,*(undefined4 *)param_1,0x400,0);
  return (bool)('\x01' - (iVar1 != 1));
}



// Function: FUN_1000c1d3 at 1000c1d3

undefined4 FUN_1000c1d3(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_1002e10c + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000c1ff at 1000c1ff

void __fastcall FUN_1000c1ff(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000c20c at 1000c20c

void __thiscall FUN_1000c20c(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_100226e8,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c259 at 1000c259

void __fastcall FUN_1000c259(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HarshHRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_1000c260 at 1000c260

undefined4 * __thiscall FUN_1000c260(void *this,byte param_1)

{
  FUN_1000c259((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c27f at 1000c27f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

bool __thiscall FUN_1000c27f(void *this,int param_1)

{
  code *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 uStack_28;
  int iStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x1000c28b;
  puVar5 = (undefined4 *)auStack_20;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iStack_24 = param_1;
    puVar5 = &uStack_28;
    uStack_28 = 0x1000c2c8;
    param_1 = Ordinal_2();
    if (param_1 == 0) {
      puVar5[-1] = 0x8007000e;
      puVar5[-2] = 0x1000c2d9;
      FUN_10001000(puVar5[-1]);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return (bool)uVar3;
    }
  }
  local_8 = 0;
  *(int **)((int)puVar5 + -4) = &param_1;
  *(undefined4 *)((int)puVar5 + -8) = 0x1000c2a6;
  bVar2 = ATL::CComBSTR::operator==((CComBSTR *)this,*(CComBSTR **)((int)puVar5 + -4));
  local_8 = 0xffffffff;
  *(int *)((int)puVar5 + -4) = param_1;
  puVar4 = (undefined1 *)((int)puVar5 + -8);
  *(undefined4 *)((int)puVar5 + -8) = 0x1000c2b5;
  Ordinal_6();
  *(undefined4 *)(puVar4 + -4) = 0x1000c2bc;
  return bVar2;
}



// Function: FUN_1000c2da at 1000c2da

void __fastcall FUN_1000c2da(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_1000c2e2 at 1000c2e2

undefined2 * __thiscall FUN_1000c2e2(void *this,CComBSTR *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_1000c2fa;
  while( true ) {
    FUN_10001000(iVar1);
LAB_1000c2fa:
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



// Function: FUN_1000c32d at 1000c32d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c32d(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000c352 at 1000c352

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c352(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
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



// Function: FUN_1000c39a at 1000c39a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c39a(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
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



// Function: FUN_1000c3e2 at 1000c3e2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c3e2(undefined4 *param_1)

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



// Function: FUN_1000c42a at 1000c42a

undefined4 * __thiscall FUN_1000c42a(void *this,byte param_1)

{
  FUN_1000c352((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c449 at 1000c449

undefined4 * __thiscall FUN_1000c449(void *this,byte param_1)

{
  FUN_1000c39a((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c468 at 1000c468

undefined4 * __thiscall FUN_1000c468(void *this,byte param_1)

{
  FUN_1000c3e2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c487 at 1000c487

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000c487(void *this,int *param_1)

{
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c4b5 at 1000c4b5

void __fastcall FUN_1000c4b5(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HarshHRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_1000c4cd at 1000c4cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c4cd(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000c518 at 1000c518

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c518(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[1] = 0;
  *param_1 = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  return;
}



// Function: FUN_1000c54c at 1000c54c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c54c(undefined4 *param_1)

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



// Function: FUN_1000c594 at 1000c594

undefined4 * __thiscall FUN_1000c594(void *this,byte param_1)

{
  FUN_1000c54c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c5b3 at 1000c5b3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c5b3(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_1000c5e7 at 1000c5e7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000c6d1) */

undefined4 FUN_1000c5e7(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  LPCOLESTR pOVar3;
  undefined4 uVar4;
  LPUNKNOWN pIVar5;
  int *piVar6;
  int *piVar7;
  undefined4 local_30;
  undefined4 uStack_2c;
  int *local_28;
  undefined4 uStack_24;
  LPCOLESTR local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  pIVar5 = (LPUNKNOWN)0x0;
  local_18 = (int *)0x0;
  piVar6 = (int *)0x1;
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  pOVar3 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
  piVar7 = piVar6;
  local_20 = pOVar3;
  if (pOVar3 != (LPCOLESTR)0x0) goto LAB_1000c623;
  do {
    FUN_10001000(0x8007000e);
    piVar7 = piVar6;
LAB_1000c623:
    local_8._0_1_ = 4;
    FUN_1000c20c(local_14,pOVar3,pIVar5,0x17);
    pIVar5 = (LPUNKNOWN)Ordinal_6_exref;
    local_8._0_1_ = 3;
    Ordinal_6(pOVar3);
    piVar6 = local_14[0];
    uVar2 = uStack_24;
    uVar1 = uStack_2c;
    local_30 = CONCAT22(local_30._2_2_,3);
    uVar4 = local_30;
    local_8._0_1_ = 5;
    pOVar3 = (LPCOLESTR)&local_30;
    local_1c = local_14[0];
    local_28 = piVar7;
    local_20 = (LPCOLESTR)Ordinal_2(L"LicenseFile");
  } while (local_20 == (LPCOLESTR)0x0);
  local_8._0_1_ = 6;
  (**(code **)(*piVar6 + 0xe0))(local_1c,uVar4,uVar1,piVar7,uVar2,local_20,0,&local_18);
  local_8._0_1_ = 5;
  Ordinal_6(local_20);
  local_8._0_1_ = 3;
  Ordinal_9(&local_30);
  uVar4 = (**(code **)(*local_14[0] + 0x54))(local_14[0],local_18,param_2);
  *param_1 = local_14[0];
  local_14[0] = (int *)0x0;
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return uVar4;
}



// Function: FUN_1000c6f2 at 1000c6f2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000c6f2(void *this,int *param_1)

{
  FUN_1000c487((void *)((int)this + 4),param_1);
  *(undefined ***)this =
       TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  return (undefined4 *)this;
}



// Function: FUN_1000c726 at 1000c726

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000c726(void *this,int *param_1)

{
  FUN_1000c487((void *)((int)this + 4),param_1);
  *(undefined ***)this =
       TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  return (undefined4 *)this;
}



// Function: FUN_1000c75a at 1000c75a

int __thiscall FUN_1000c75a(void *this,int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)(param_1 + 4);
  }
  if (*(int **)((int)this + 4) != (int *)*puVar1) {
    FUN_100010fd((int *)((int)this + 4),(int *)*puVar1);
  }
  return (int)this;
}



// Function: FUN_1000c785 at 1000c785

int * __thiscall FUN_1000c785(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != param_1) {
    piVar1 = FUN_100010fd((int *)((int)this + 4),param_1);
  }
  return piVar1;
}



// Function: FUN_1000c7a3 at 1000c7a3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000c7a3(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1 + 1;
  *param_1 = CComECMPropertyPageHelperImpl<class_CFuelSystemTableResetGTIS45LogicImpl>::vftable;
  *piVar1 = 0;
  piVar2 = param_1 + 2;
  *piVar2 = 0;
  if (*piVar1 != 0) {
    FUN_100010fd(piVar1,(int *)0x0);
  }
  if (*piVar2 != 0) {
    FUN_100010fd(piVar2,(int *)0x0);
  }
  return param_1;
}



// Function: FUN_1000c7fb at 1000c7fb

undefined4 FUN_1000c7fb(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_100010fd((int *)(param_1 + 4),(int *)0x0);
  }
  if (*(int *)(param_1 + 8) != 0) {
    FUN_100010fd((int *)(param_1 + 8),(int *)0x0);
  }
  return 1;
}



// Function: FUN_1000c82a at 1000c82a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c82a(int param_1)

{
  FUN_1000c4cd(param_1);
  return;
}



// Function: FUN_1000c848 at 1000c848

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000c848(undefined4 *param_1)

{
  param_1[10] = 0;
  FUN_10002e18(param_1 + 0xb);
  FUN_1000c7a3(param_1);
  param_1[5] = 0;
  FUN_1000c5b3((int)(param_1 + 7));
  return param_1;
}



// Function: FUN_1000c897 at 1000c897

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c897(int param_1)

{
  FUN_1000c4cd(param_1 + 0x1c);
  FUN_1000c4cd(param_1);
  FUN_10002d3f((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000c8e5 at 1000c8e5

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000c8e5(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_74 [48];
  undefined1 local_44 [60];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x1000c8f1;
  FUN_10001e15(local_44,param_1,0,param_2,L"",0);
  local_8 = 0;
  FUN_10001d36(local_74,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_74,(ThrowInfo *)&DAT_10026b18);
}



// Function: FUN_1000c927 at 1000c927

void __thiscall FUN_1000c927(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 != 0)) {
    *(undefined1 *)this = 1;
    FUN_1000c8e5(param_1,*(undefined4 *)((int)this + 4));
  }
  return;
}



// Function: FUN_1000c947 at 1000c947

int __thiscall FUN_1000c947(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_1000c927((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_1000c963 at 1000c963

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c963(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  wchar_t *pwVar2;
  undefined4 local_50 [11];
  undefined4 local_24 [3];
  undefined4 local_18;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x1000c96f;
  FUN_1000173f(local_24);
  local_8 = 0;
  FUN_10016866(local_50,*(undefined4 **)(param_1 + -0x10));
  local_8 = CONCAT31((int3)(local_8 >> 8),2);
  FUN_100020b2(local_24,0);
  puVar1 = DAT_10030030;
  if (DAT_10030044 < 8) {
    puVar1 = &DAT_10030030;
  }
  FUN_1001643a(local_50,puVar1,1,0);
  local_8 = 1;
  pwVar2 = DAT_1003004c;
  if (DAT_10030060 < 8) {
    pwVar2 = (wchar_t *)&DAT_1003004c;
  }
  FUN_100169f3(local_50,pwVar2,param_2);
  local_8 = local_8 & 0xffffff00;
  FUN_100164f7(local_50);
  return local_18;
}



// Function: Catch@1000c9f8 at 1000c9f8

undefined4 Catch_1000c9f8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000c9be;
}



// Function: FUN_1000ca0c at 1000ca0c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000ca0c(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  wchar_t *pwVar2;
  undefined4 local_54 [11];
  undefined4 local_28 [3];
  undefined4 local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x1000ca18;
  FUN_1000173f(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_100020b2(local_28,0);
  local_18[0] = -1;
  FUN_10016866(local_54,*(undefined4 **)(param_1 + -0x10));
  local_8._0_1_ = 2;
  pwVar2 = DAT_10030014;
  if (DAT_10030028 < 8) {
    pwVar2 = (wchar_t *)&DAT_10030014;
  }
  FUN_100169f3(local_54,pwVar2,local_18);
  if (local_18[0] == 1) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = 0;
  }
  *param_2 = uVar1;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100164f7(local_54);
  return local_1c;
}



// Function: Catch@1000ca99 at 1000ca99

undefined4 Catch_1000ca99(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000ca8a;
}



// Function: FUN_1000caaa at 1000caaa

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000caaa(int param_1)

{
  int iVar1;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x1000cab6;
  FUN_1000173f(local_24);
  local_8 = 1;
  iVar1 = FUN_1000c7fb(param_1);
  FUN_100020b2(local_24,iVar1);
  return local_18;
}



// Function: Catch@1000caea at 1000caea

undefined4 Catch_1000caea(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000cadb;
}



// Function: FUN_1000cafb at 1000cafb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000cafb(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_28 [4];
  undefined4 *local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  puVar1 = (undefined4 *)((int)this + 4);
  *puVar1 = 0;
  local_8 = 1;
  *(undefined ***)this =
       TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_18 = puVar1;
  local_14 = this;
  FUN_1000173f(local_28);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = (**(code **)*param_1)(param_1,&DAT_10022700,puVar1);
  FUN_100020b2(local_28,iVar2);
  return (undefined4 *)this;
}



// Function: FUN_1000cb55 at 1000cb55

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_1000cb55(void *this,int *param_1,undefined4 *param_2,undefined4 *param_3)

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
  FUN_1000173f(local_2c);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_14[0] = 0;
  local_8._0_1_ = 3;
  if (param_2[4] == 0) {
    iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,local_14);
    FUN_100020b2(local_2c,iVar2);
  }
  else {
    piVar3 = FUN_10015f82((int *)&param_2,param_2);
    local_8._0_1_ = 4;
    FUN_10002f81(local_14,piVar3);
    local_8._0_1_ = 3;
    Ordinal_6(param_2);
  }
  local_18 = (int *)0x0;
  local_8._0_1_ = 6;
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1,&local_18);
  FUN_100020b2(local_2c,iVar2);
  iVar2 = (**(code **)(*local_18 + 0x24))(local_18,local_14[0],piVar1);
  FUN_100020b2(local_2c,iVar2);
  if (param_3[4] != 0) {
    piVar3 = FUN_10015f82((int *)&param_1,param_3);
    local_8._0_1_ = 7;
    iVar2 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,*piVar3);
    FUN_100020b2(local_2c,iVar2);
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



// Function: FUN_1000cc6a at 1000cc6a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000cc6a(void *this,undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_20 [6];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000cc76;
  FUN_1000173f(local_20);
  local_8 = 0;
  piVar1 = FUN_10015f82((int *)&param_1,param_1);
  local_8._0_1_ = 1;
  iVar2 = (**(code **)(**(int **)((int)this + 4) + 0x24))(*(int **)((int)this + 4),*piVar1);
  FUN_100020b2(local_20,iVar2);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(param_1);
  return;
}



// Function: FUN_1000ccc4 at 1000ccc4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000ccc4(void *this,void *param_1)

{
  int iVar1;
  undefined4 local_28 [4];
  undefined4 local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x1000ccd0;
  local_18 = 0;
  FUN_1000173f(local_28);
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x28))(*(int **)((int)this + 4),local_14);
  FUN_100020b2(local_28,iVar1);
  FUN_1000c6f2(param_1,local_14[0]);
  local_18 = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return param_1;
}



// Function: FUN_1000cd2f at 1000cd2f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000cd2f(void *this,void *param_1,undefined4 *param_2)

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
  local_8 = 0x1000cd3b;
  local_1c = 0;
  FUN_1000173f(local_2c);
  local_18 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  piVar1 = FUN_10015f82((int *)&param_2,param_2);
  local_8._0_1_ = 4;
  iVar2 = (**(code **)(**(int **)((int)this + 4) + 0x30))
                    (*(int **)((int)this + 4),*piVar1,1,&local_18);
  FUN_100020b2(local_2c,iVar2);
  local_8._0_1_ = 3;
  Ordinal_6(param_2);
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 6;
  if (local_18 != (int *)0x0) {
    iVar2 = (**(code **)*local_18)(local_18,&DAT_10022720,local_14);
    FUN_100020b2(local_2c,iVar2);
  }
  FUN_1000c726(param_1,local_14[0]);
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



// Function: FUN_1000cdf4 at 1000cdf4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __thiscall FUN_1000cdf4(void *this,undefined2 *param_1)

{
  int iVar1;
  undefined4 local_28 [4];
  undefined4 local_18;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x1000ce00;
  local_18 = 0;
  FUN_1000173f(local_28);
  local_14[0] = (wchar_t *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x1c))(*(int **)((int)this + 4),local_14);
  FUN_100020b2(local_28,iVar1);
  FUN_10016152(param_1,local_14[0]);
  local_18 = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_14[0]);
  return param_1;
}



// Function: FUN_1000ce5d at 1000ce5d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_1000ce5d(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 param_3,
            undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 local_24 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  *param_1 = 0;
  local_8 = 0;
  local_14 = 1;
  FUN_1000173f(local_24);
  local_8 = 2;
  piVar1 = FUN_10015f82((int *)&param_2,param_2);
  local_8._0_1_ = 3;
  iVar2 = (**(code **)(**(int **)((int)this + 4) + 0x34))
                    (*(int **)((int)this + 4),*piVar1,param_3,*param_4,param_4[1],param_4[2],
                     param_4[3],param_1);
  FUN_100020b2(local_24,iVar2);
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6(param_2);
  return param_1;
}



// Function: FUN_1000cee3 at 1000cee3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000cee3(void *this,int *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  wchar_t *in_stack_ffffff18;
  wchar_t *in_stack_ffffff24;
  int local_d8;
  int *local_3c;
  int *local_38;
  int local_34;
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 200;
  local_38 = (int *)0x0;
  local_34 = param_2;
  local_3c = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  FUN_10007e12(&local_d8,2,1);
  local_8._0_1_ = 4;
  piVar2 = (int *)FUN_10005101(&local_d8,L".//*[@ID=\"");
  piVar2 = (int *)FUN_1000528c(piVar2,in_stack_ffffff18);
  FUN_10005101(piVar2,in_stack_ffffff24);
  piVar2 = *(int **)((int)this + 8);
  local_d8 = 0x1000cf66;
  puVar3 = (undefined4 *)FUN_1000b5d1(&local_d8,local_30);
  local_8._0_1_ = 5;
  if (7 < (uint)puVar3[5]) {
    puVar3 = (undefined4 *)*puVar3;
  }
  if (puVar3 == (undefined4 *)0x0) {
    local_34 = 0;
  }
  else {
    local_d8 = 0x1000d00d;
    local_34 = Ordinal_2();
    if (local_34 == 0) {
      local_d8 = 0x1000d022;
      FUN_10001000(0x8007000e);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  local_8._0_1_ = 6;
  local_d8 = local_34;
  (**(code **)(*piVar2 + 0x94))(piVar2);
  local_8._0_1_ = 5;
  Ordinal_6(local_34);
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_30,'\x01',0);
  (**(code **)(*local_38 + 0x60))(local_38,0xffffffff,&local_3c);
  (**(code **)(*param_1 + 0x54))(param_1,local_3c,param_3);
  local_8._0_1_ = 3;
  FUN_10007a31((int)&local_d8);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
  local_8 = 0xffffffff;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  FUN_100172f7();
  return;
}



// Function: FUN_1000d023 at 1000d023

void __fastcall FUN_1000d023(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FUN_1000aef8((void *)*param_1,(void *)param_1[1],param_1 + 3);
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000d058 at 1000d058

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000d058(void *this,int *param_1,undefined4 *param_2)

{
  *(undefined ***)this = CECMParameterReader::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  FUN_1000c518((undefined4 *)((int)this + 8));
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  FUN_1000c785((void *)((int)this + 8),param_1);
  if (param_2[4] != 0) {
    FUN_1000cc6a((void *)((int)this + 8),param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000d0e6 at 1000d0e6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000d0e6(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *local_34;
  undefined2 local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  *param_1 = CECMParameterReader::vftable;
  local_8 = 5;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)FUN_1000cdf4(param_1 + 2,local_30);
    local_8._0_1_ = 6;
    piVar3 = FUN_10015f82((int *)&local_34,puVar2);
    local_8._0_1_ = 7;
    (**(code **)(*piVar1 + 0x28))(piVar1,*piVar3);
    local_8._0_1_ = 6;
    Ordinal_6(local_34);
    local_8 = CONCAT31(local_8._1_3_,5);
    FID_conflict__Tidy(local_30,'\x01',0);
  }
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_34 = param_1 + 7;
  local_8._0_1_ = 4;
  piVar1 = (int *)*local_34;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
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
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000c54c(param_1 + 2);
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_100172f7();
  return;
}



// Function: FUN_1000d1e5 at 1000d1e5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000d1e5(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 local_1c [2];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000d1f1;
  local_14 = 0;
  pvVar1 = FUN_1000cd2f((void *)((int)this + 8),local_1c,param_2);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)((int)pvVar1 + 4);
  }
  *param_1 = 0;
  *param_1 = *puVar2;
  *puVar2 = 0;
  local_14 = 1;
  local_8 = 0;
  FUN_1000c3e2(local_1c);
  return param_1;
}



// Function: FUN_1000d242 at 1000d242

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000d242(void *this,undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 local_24 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0;
  local_14 = 0;
  FUN_1000d1e5(this,&param_2,param_2);
  local_8 = 1;
  Ordinal_8(param_1);
  local_14 = 1;
  FUN_1000c4b5(local_24);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = (**(code **)(*param_2 + 0x28))(param_2,param_1);
  FUN_1000c947(local_24,iVar1);
  local_8 = 0;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return param_1;
}



// Function: FUN_1000d2b1 at 1000d2b1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_1000d2b1(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 local_34 [8];
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x1000d2bd;
  local_14 = 0;
  FUN_1000d058(local_34,param_2,param_4);
  local_8 = 1;
  FUN_1000d242(local_34,param_1,param_3);
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_1000d0e6(local_34);
  return param_1;
}



// Function: FUN_1000d2fb at 1000d2fb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000d2fb(void *this,void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_14[0] = (int *)0x0;
  local_8 = 2;
  FUN_1000ce5d(this,&local_18,param_2,1,param_3);
  local_8._0_1_ = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)*local_18)(local_18,&DAT_10022720,local_14);
  }
  FUN_1000c726(param_1,local_14[0]);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = 0;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return param_1;
}



// Function: FUN_1000d37f at 1000d37f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_1000d37f(void *this,undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined1 local_3c [8];
  int local_34;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  int *local_20;
  code *local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_2c = 0;
  local_24 = (int *)0x0;
  local_14[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_20 = (int *)0x0;
  local_8._0_1_ = 6;
  FUN_1000c5e7(&local_24,&local_20);
  FUN_1000cee3(this,local_20,param_1,local_14);
  (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_2c);
  piVar1 = local_24;
  local_28 = 0;
  local_8._0_1_ = 7;
  (**(code **)(*local_24 + 0x88))(local_24,&local_28);
  (**(code **)(**(int **)((int)this + 4) + 0xc))(*(int **)((int)this + 4),piVar1);
  local_1c = (code *)0x0;
  local_8._0_1_ = 9;
  (**(code **)*local_14[0])(local_14[0],&DAT_10022750,&local_1c);
  Ordinal_8(local_3c);
  pcVar5 = local_1c;
  local_8 = CONCAT31(local_8._1_3_,10);
  iVar3 = Ordinal_2(L"IsValid");
  iVar4 = iVar3;
  if (iVar3 != 0) goto LAB_1000d43d;
  while( true ) {
    iVar4 = FUN_10001000(0x8007000e);
LAB_1000d43d:
    local_8._0_1_ = 0xb;
    (**(code **)(*(int *)pcVar5 + 0xb0))(pcVar5,iVar4,local_3c);
    pcVar5 = Ordinal_6_exref;
    local_8 = CONCAT31(local_8._1_3_,10);
    Ordinal_6(iVar3);
    if (local_34 == 0) break;
    local_18 = Ordinal_2(local_34);
    if (local_18 != 0) {
LAB_1000d474:
      local_8._0_1_ = 0xc;
      bVar2 = FUN_1000c27f(&local_18,0x10022808);
      local_8._0_1_ = 10;
      Ordinal_6(local_18);
      local_8._0_1_ = 9;
      Ordinal_9(local_3c);
      local_8._0_1_ = 7;
      if (local_1c != (code *)0x0) {
        (**(code **)(*(int *)local_1c + 8))(local_1c);
      }
      local_8._0_1_ = 6;
      Ordinal_6(local_28);
      local_8._0_1_ = 4;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      local_8._0_1_ = 2;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      (**(code **)(*local_24 + 8))(local_24);
      local_8 = 0xffffffff;
      Ordinal_6(local_2c);
      return bVar2;
    }
  }
  local_18 = 0;
  goto LAB_1000d474;
}



// Function: FUN_1000d4fb at 1000d4fb

void __fastcall FUN_1000d4fb(int *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FUN_1000aef8((void *)*param_1,(void *)param_1[1],param_1 + 3);
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000d500 at 1000d500

undefined4 * __thiscall FUN_1000d500(void *this,byte param_1)

{
  FUN_1000d0e6((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000d51f at 1000d51f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000d51f(int param_1,undefined2 *param_2)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_b0 [4];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_94 [4];
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_78 [8];
  int local_70;
  undefined4 local_68 [4];
  undefined4 local_58;
  int *local_54;
  uint local_50;
  undefined4 local_4c;
  int *local_48;
  undefined2 *local_44;
  int *local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined2 local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa0;
  local_8 = 0x1000d52e;
  local_44 = param_2;
  FUN_1000173f(local_68);
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = 0;
    local_34 = 0;
    local_3c = 0;
    local_8._1_3_ = 0;
    local_38 = 0;
    local_8._0_1_ = 3;
    Ordinal_6(0);
    local_3c = 0;
    FUN_1000117f(0x87,&local_3c);
    Ordinal_6(0);
    local_38 = 0;
    FUN_1000117f(0x88,&local_38);
    local_40 = (int *)0x0;
    local_8._0_1_ = 5;
    iVar3 = (**(code **)**(undefined4 **)(param_1 + -0x10))
                      (*(undefined4 **)(param_1 + -0x10),&DAT_10022710,&local_40);
    FUN_100020b2(local_68,iVar3);
    iVar3 = (**(code **)(*local_40 + 0x20))(local_40,&local_34);
    FUN_100020b2(local_68,iVar3);
    FUN_1000cafb(&local_4c,*(undefined4 **)(param_1 + -0x10));
    local_9c = 7;
    local_a0 = 0;
    local_b0[0]._0_2_ = 0;
    local_8._0_1_ = 7;
    puVar4 = (undefined4 *)FUN_1000cdf4(&local_4c,local_30);
    local_8._0_1_ = 8;
    FUN_1000cb55(&local_58,local_48,puVar4,local_b0);
    local_8._0_1_ = 10;
    FID_conflict__Tidy(local_30,'\x01',0);
    local_8._0_1_ = 0xb;
    FID_conflict__Tidy(local_b0,'\x01',0);
    local_80 = 7;
    local_84 = 0;
    local_94[0]._0_2_ = 0;
    local_8._0_1_ = 0xc;
    FUN_1000d2b1(local_78,local_54,(int *)&DAT_10030084,local_94);
    local_8 = CONCAT31(local_8._1_3_,0xe);
    FID_conflict__Tidy(local_94,'\x01',0);
    FUN_10015f61(3,(int)local_78,0,0x409);
    local_50 = (uint)(local_70 != 0);
    iVar3 = Ordinal_314(local_34,local_3c,0x400,0);
    if (((iVar3 == 1) ||
        (((iVar3 = Ordinal_314(local_34,local_38,0x400,0), iVar3 == 1 && (local_50 == 0)) ||
         (bVar1 = FUN_1000d37f((void *)(param_1 + 4),&DAT_100300a0), !bVar1)))) ||
       (bVar1 = FUN_1000d37f((void *)(param_1 + 4),&DAT_100300bc), !bVar1)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffff;
    }
    *local_44 = uVar2;
    local_8._0_1_ = 0xb;
    Ordinal_9(local_78);
    local_8._0_1_ = 6;
    FUN_1000c54c(&local_58);
    local_8._0_1_ = 5;
    FUN_1000c352(&local_4c);
    local_8._0_1_ = 3;
    if (local_40 != (int *)0x0) {
      (**(code **)(*local_40 + 8))(local_40);
    }
    local_8._0_1_ = 2;
    Ordinal_6(local_38);
    local_8._0_1_ = 1;
    Ordinal_6(local_3c);
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(local_34);
  }
  local_8 = 0xffffffff;
  FUN_100172f7();
  return;
}



// Function: FUN_1000d768 at 1000d768

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000d768(void *this,undefined4 *param_1)

{
  undefined4 **ppuVar1;
  int *piVar2;
  int *piVar3;
  LPCOLESTR pOVar4;
  LPCOLESTR pOVar5;
  int iVar6;
  OLECHAR aOStack_108 [4];
  undefined4 uStack_100;
  undefined4 *puStack_fc;
  undefined4 uStack_f8;
  TypeDescriptor *pTStack_f4;
  TypeDescriptor *pTStack_f0;
  undefined4 **ppuStack_ec;
  int *piStack_e8;
  int *piStack_e4;
  int *piStack_e0;
  int *piStack_dc;
  int **ppiStack_d8;
  undefined4 *puStack_d4;
  undefined *puStack_d0;
  int **ppiStack_cc;
  undefined4 **ppuStack_c8;
  int *piStack_c4;
  LPCOLESTR pOStack_c0;
  undefined4 **ppuStack_bc;
  int *piStack_b8;
  undefined4 **ppuStack_b4;
  int *piStack_b0;
  undefined4 local_70;
  LPCOLESTR local_6c;
  undefined4 **local_68;
  int *piStack_64;
  undefined4 local_60;
  int *piStack_5c;
  undefined4 *local_58;
  undefined4 *local_54;
  undefined4 local_50;
  undefined4 local_48;
  int *local_44;
  short local_40;
  int *local_3c;
  LPCOLESTR local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  LPCOLESTR local_24;
  int local_20;
  int *local_1c;
  undefined4 *local_18;
  LPCOLESTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x70;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_18 = (undefined4 *)this;
  (**(code **)*param_1)();
  pOVar5 = (LPCOLESTR)Ordinal_2();
  local_24 = pOVar5;
  if (pOVar5 != (LPCOLESTR)0x0) goto LAB_1000d7ad;
  do {
    do {
      FUN_10001000(0x8007000e);
LAB_1000d7ad:
      local_8._0_1_ = 1;
      piStack_b0 = (int *)0x1000d7bd;
      FUN_1000c20c((undefined4 *)((int)this + 8),pOVar5,(LPUNKNOWN)0x0,0x17);
      local_8._0_1_ = 0;
      Ordinal_6();
      piVar3 = piStack_5c;
      piVar2 = piStack_64;
      local_3c = (int *)0x0;
      local_1c = (int *)0x0;
      local_2c = (int *)0x0;
      local_68 = (undefined4 **)CONCAT22(local_68._2_2_,3);
      ppuVar1 = local_68;
      local_60 = 1;
      local_8._0_1_ = 8;
      this = &local_70;
      pOVar5 = (LPCOLESTR)local_18[2];
      local_24 = pOVar5;
      local_28 = (int *)Ordinal_2();
    } while (local_28 == (int *)0x0);
    local_8._0_1_ = 9;
    pOStack_c0 = local_24;
    ppuStack_bc = ppuVar1;
    piStack_b8 = piVar2;
    ppuStack_b4 = (undefined4 ***)0x1;
    piStack_b0 = piVar3;
    piStack_c4 = (int *)0x1000d834;
    (**(code **)(*(int *)pOVar5 + 0xe0))();
    local_8._0_1_ = 8;
    piStack_c4 = local_28;
    ppuStack_c8 = (undefined4 **)0x1000d841;
    Ordinal_6();
    local_8 = CONCAT31(local_8._1_3_,7);
    ppuStack_c8 = &local_68;
    ppiStack_cc = (int **)0x1000d84f;
    Ordinal_9();
    puStack_d4 = (undefined4 *)local_18[2];
    ppiStack_cc = &local_2c;
    puStack_d0 = &DAT_10022740;
    ppiStack_d8 = (int **)0x1000d863;
    (**(code **)*puStack_d4)();
    ppiStack_d8 = &local_3c;
    piStack_dc = local_1c;
    piStack_e0 = local_2c;
    piStack_e4 = (int *)0x1000d873;
    (**(code **)(*local_2c + 0x54))();
    piStack_e4 = local_1c;
    if (local_1c != (int *)0x0) {
      local_1c = (int *)0x0;
      piStack_e8 = (int *)0x1000d883;
      (**(code **)(*piStack_e4 + 8))();
    }
    local_48 = 0;
    local_8._0_1_ = 10;
    piStack_e4 = &local_48;
    piStack_e8 = local_2c;
    ppuStack_ec = (undefined4 **)0x1000d89a;
    local_20 = (**(code **)(*local_2c + 0x88))();
    local_58 = (undefined4 *)0x0;
    local_54 = (undefined4 *)0x0;
    local_50 = 0;
    local_8._0_1_ = 0xb;
    ppuStack_ec = (undefined4 **)0x0;
    pTStack_f0 = &CFuelSystemTableResetGTIS45LogicImpl::RTTI_Type_Descriptor;
    pTStack_f4 = &CComNonAddInSecurity<class_CFuelSystemTableResetGTIS45LogicImpl>::
                  RTTI_Type_Descriptor;
    uStack_f8 = 0;
    puStack_fc = local_18;
    uStack_100 = 0x1000d8be;
    iVar6 = __RTDynamicCast();
    ppuStack_ec = &local_58;
    local_24 = aOStack_108;
    basic_string<>(aOStack_108,(undefined4 *)&stack0x00000008);
    local_8 = CONCAT31(local_8._1_3_,0xb);
    (**(code **)(*(int *)(iVar6 + 0x1c) + 0x1c))();
    local_18 = local_58;
    if (local_58 == local_54) {
LAB_1000db26:
      local_8._0_1_ = 10;
      FUN_1000d023(&local_58);
      local_8._0_1_ = 7;
      Ordinal_6(local_48);
      local_8._0_1_ = 5;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      local_8._0_1_ = 3;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      local_8 = 0xffffffff;
      FID_conflict__Tidy(&stack0x00000008,'\x01',0);
      return local_20;
    }
    while( true ) {
      this = local_18;
      if (local_20 < 0) goto LAB_1000db26;
      local_30 = (int *)0x0;
      local_8._0_1_ = 0xe;
      pOVar5 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
      local_6c = pOVar5;
      if (pOVar5 == (LPCOLESTR)0x0) break;
      local_8._0_1_ = 0xf;
      piStack_b0 = (int *)0x1000d936;
      FUN_1000c20c(&local_30,pOVar5,(LPUNKNOWN)0x0,0x17);
      local_8._0_1_ = 0xe;
      Ordinal_6();
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        this = *this;
      }
      if ((undefined4 *)this == (undefined4 *)0x0) {
        local_38 = (LPCOLESTR)0x0;
      }
      else {
        local_38 = (LPCOLESTR)Ordinal_2();
        if (local_38 == (LPCOLESTR)0x0) break;
      }
      local_8._0_1_ = 0x10;
      local_68 = (undefined4 **)((uint)local_68 & 0xffff0000);
      FUN_1000c2e2(&local_68,(CComBSTR *)&local_38);
      local_8._0_1_ = 0x11;
      ppuStack_b4 = local_68;
      piStack_b0 = piStack_64;
      piStack_b8 = local_30;
      ppuStack_bc = (undefined4 **)0x1000d99a;
      (**(code **)(*local_30 + 0xe8))();
      local_8._0_1_ = 0x10;
      ppuStack_bc = &local_68;
      pOStack_c0 = L"䗆໼痿诌쀽Ȃ０曗綃ￄ蔏ļ";
      Ordinal_9();
      local_8._0_1_ = 0xe;
      pOStack_c0 = local_38;
      piStack_c4 = (int *)0x1000d9b7;
      Ordinal_6();
      if (local_40 == -1) {
        local_28 = (int *)0x0;
        local_8._0_1_ = 0x13;
        (**(code **)*local_30)(local_30,&DAT_10022740,&local_28);
        local_34 = (int *)0x0;
        local_8._0_1_ = 0x15;
        local_20 = (**(code **)(*local_28 + 0x34))(local_28,&local_34);
        local_14[0] = (LPCOLESTR)0x0;
        pOVar5 = (LPCOLESTR)0x0;
        local_24 = (LPCOLESTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x19);
        iVar6 = (**(code **)(*local_34 + 0x34))(local_34,local_14);
        while (((-1 < local_20 && (-1 < iVar6)) && (local_14[0] != (LPCOLESTR)0x0))) {
          local_70 = 0;
          local_44 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x1c);
          (**(code **)(*(int *)local_14[0] + 0x60))(local_14[0],0xffffffff,&local_44);
          local_20 = (**(code **)(*local_3c + 0x54))(local_3c,local_44,&local_1c);
          piVar2 = local_1c;
          if (local_1c != (int *)0x0) {
            local_1c = (int *)0x0;
            (**(code **)(*piVar2 + 8))(piVar2);
          }
          if (pOVar5 != local_14[0]) {
            FUN_100010fd((int *)&local_24,(int *)local_14[0]);
            pOVar5 = local_24;
          }
          pOVar4 = local_14[0];
          if (local_14[0] != (LPCOLESTR)0x0) {
            local_14[0] = (LPCOLESTR)0x0;
            (**(code **)(*(int *)pOVar4 + 8))(pOVar4);
            if (local_14[0] != (LPCOLESTR)0x0) {
              local_14[0] = (LPCOLESTR)0x0;
            }
          }
          local_8._0_1_ = 0x1a;
          if (local_44 != (int *)0x0) {
            (**(code **)(*local_44 + 8))(local_44);
          }
          local_8 = CONCAT31(local_8._1_3_,0x19);
          Ordinal_6(0);
          iVar6 = (**(code **)(*(int *)pOVar5 + 0x40))(pOVar5,local_14);
        }
        local_8._0_1_ = 0x17;
        if (pOVar5 != (LPCOLESTR)0x0) {
          (**(code **)(*(int *)pOVar5 + 8))(pOVar5);
        }
        local_8._0_1_ = 0x15;
        if (local_14[0] != (LPCOLESTR)0x0) {
          (**(code **)(*(int *)local_14[0] + 8))(local_14[0]);
        }
        local_8._0_1_ = 0x13;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))(local_34);
        }
        local_8._0_1_ = 0xe;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))(local_28);
        }
      }
      else {
        local_20 = -0x7fffbffb;
      }
      local_8 = CONCAT31(local_8._1_3_,0xb);
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
      local_18 = local_18 + 7;
      if (local_18 == local_54) goto LAB_1000db26;
    }
  } while( true );
}



// Function: FUN_1000db8b at 1000db8b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000db8b(int param_1,wchar_t *param_2)

{
  int iVar1;
  undefined1 auStack_54 [20];
  undefined4 uStack_40;
  undefined4 local_28 [3];
  undefined4 local_1c;
  undefined1 *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x1000db97;
  FUN_1000173f(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  uStack_40 = 0x1000dbb1;
  FUN_100020b2(local_28,0);
  uStack_40 = 0x1000dbba;
  FUN_100020b2(local_28,0);
  local_18 = auStack_54;
  FUN_10001d86(auStack_54,param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = FUN_1000d768((void *)(param_1 + 0x1c),*(undefined4 **)(param_1 + 8));
  uStack_40 = 0x1000dbea;
  FUN_100020b2(local_28,iVar1);
  return local_1c;
}



// Function: Catch@1000dbfc at 1000dbfc

undefined4 Catch_1000dbfc(void)

{
  int unaff_EBP;
  
  (**(code **)(**(int **)(unaff_EBP + 8) + 0x18))(*(int **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -0x18) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000dbed;
}



// Function: FUN_1000dc16 at 1000dc16

void __cdecl FUN_1000dc16(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + -8) == 0xdddd)) {
    free((int *)(param_1 + -8));
  }
  return;
}



// Function: FUN_1000dc35 at 1000dc35

int __cdecl FUN_1000dc35(int param_1)

{
  if (*(short *)(param_1 + 2) == -1) {
    return param_1 + 0x10;
  }
  return param_1 + 8;
}



// Function: FUN_1000dc50 at 1000dc50

uint __cdecl FUN_1000dc50(uint *param_1)

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



// Function: FUN_1000dcd6 at 1000dcd6

uint __cdecl FUN_1000dcd6(int param_1,int param_2)

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



// Function: FUN_1000dd39 at 1000dd39

void __fastcall FUN_1000dd39(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FreeStdCallThunk((void *)*param_1);
  }
  return;
}



// Function: FUN_1000dd46 at 1000dd46

void FUN_1000dd46(LONG *param_1)

{
  LONG LVar1;
  
  if (param_1 != (LONG *)PTR_DAT_1002d148) {
    LVar1 = InterlockedDecrement(param_1);
    if (LVar1 < 1) {
      operator_delete__(param_1);
    }
  }
  return;
}



// Function: FUN_1000dd6c at 1000dd6c

uint __fastcall FUN_1000dd6c(undefined4 *param_1)

{
  uint in_EAX;
  HCURSOR pHVar1;
  
  if (*(char *)(param_1 + 2) != '\0') {
    return in_EAX & 0xffffff00;
  }
  pHVar1 = SetCursor((HCURSOR)*param_1);
  param_1[1] = pHVar1;
  *(undefined1 *)(param_1 + 2) = 1;
  return CONCAT31((int3)((uint)pHVar1 >> 8),1);
}



// Function: FUN_1000dd8c at 1000dd8c

undefined1 __fastcall FUN_1000dd8c(int param_1)

{
  if (*(char *)(param_1 + 8) == '\0') {
    return 0;
  }
  SetCursor(*(HCURSOR *)(param_1 + 4));
  *(undefined1 *)(param_1 + 8) = 0;
  return 1;
}



// Function: FUN_1000ddaa at 1000ddaa

undefined * FUN_1000ddaa(void)

{
  return &DAT_10022aa8;
}



// Function: FUN_1000ddb0 at 1000ddb0

undefined4 FUN_1000ddb0(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_1002e5dc + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000dddc at 1000dddc

void __fastcall FUN_1000dddc(int param_1)

{
  int local_8;
  
  local_8 = param_1;
  (**(code **)(*(int *)(param_1 + 0xdc) + 4))(0x53,0,0,&local_8);
  return;
}



// Function: FUN_1000ddf9 at 1000ddf9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_1000ddf9(int param_1)

{
  InvalidateRect(*(HWND *)(param_1 + 8),(RECT *)0x0,1);
  return 0;
}



// Function: Catch@1000de24 at 1000de24

undefined4 Catch_1000de24(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000de1a;
}



// Function: FUN_1000de2e at 1000de2e

undefined4 FUN_1000de2e(void)

{
  return 0x80004001;
}



// Function: FUN_1000de36 at 1000de36

void __fastcall FUN_1000de36(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x28;
  }
  if (*(int *)(iVar2 + 0x2c) != 0) {
    (**(code **)(**(int **)(iVar2 + 0x2c) + 8))(*(int **)(iVar2 + 0x2c));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(iVar2 + 0x30) + uVar3 * 4);
      (**(code **)(*piVar1 + 8))(piVar1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0xc));
  }
  operator_delete__(*(void **)(iVar2 + 0x30));
  return;
}



// Function: FUN_1000de7a at 1000de7a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000de7a(int param_1)

{
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0xc));
  }
  return;
}



// Function: FUN_1000dea0 at 1000dea0

void FUN_1000dea0(void)

{
  return;
}



// Function: FUN_1000dea1 at 1000dea1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000dea1(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000dead;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x15555556) &&
     (pvVar1 = operator_new((int)param_1 * 0xc), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10026910);
}



// Function: FUN_1000df00 at 1000df00

void __thiscall
FUN_1000df00(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_10;
  *(undefined4 *)((int)this + 8) = param_11;
  *(undefined4 *)((int)this + 0xc) = param_2;
  *(undefined4 *)((int)this + 0x10) = param_3;
  *(undefined4 *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 0x18) = param_5;
  *(undefined4 *)((int)this + 0x1c) = param_6;
  *(undefined4 *)((int)this + 0x20) = param_7;
  *(undefined4 *)((int)this + 0x24) = param_8;
  *(undefined4 *)((int)this + 0x28) = param_9;
  *(undefined4 *)((int)this + 0x2c) = param_12;
  *(undefined4 *)((int)this + 0x30) = param_13;
  return;
}



// Function: FUN_1000df56 at 1000df56

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000df56(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
  }
  return;
}



// Function: FUN_1000df83 at 1000df83

uint * FUN_1000df83(uint *param_1)

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
  local_14 = (void *)FUN_1000dc50(param_1);
  rVar12 = (int)local_14 - (int)param_1;
  uVar8 = (uint)(*(short *)((int)param_1 + 2) == -1);
  puVar3 = (ushort *)FUN_1000dc35((int)param_1);
  uVar4 = (uint)*puVar3;
  bVar1 = false;
  uVar10 = rVar12;
  param_1 = (uint *)local_14;
  local_10 = uVar4;
  if (uVar4 != 0) {
    do {
      pvVar5 = (void *)FUN_1000dcd6((int)param_1,uVar8);
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
      FUN_10002493(puVar6,uVar10,puVar2,rVar12);
      param_1 = (uint *)((int)puVar6 + rVar12);
      uVar11 = uVar10 - rVar12;
      if (uVar11 <= uVar10) goto LAB_1000e047;
LAB_1000e03d:
      FUN_10001000(0x80004005);
LAB_1000e047:
      puVar7 = (undefined2 *)FUN_1000dc35((int)puVar6);
      local_c = 0;
      *puVar7 = 0;
      uVar10 = uVar11;
      do {
        pvVar5 = (void *)FUN_1000dcd6((int)local_14,uVar8);
        psVar9 = (short *)((int)local_14 + 0x18);
        if (uVar8 == 0) {
          psVar9 = (short *)((int)local_14 + 0x12);
        }
        uVar11 = uVar10;
        if (*psVar9 != 0x7b) {
          rVar12 = (int)pvVar5 - (int)local_14;
          FUN_10002493(param_1,uVar10,local_14,rVar12);
          param_1 = (uint *)((int)param_1 + rVar12);
          uVar11 = uVar10 - rVar12;
          local_14 = pvVar5;
          if (uVar10 < uVar11) goto LAB_1000e03d;
          psVar9 = (short *)FUN_1000dc35((int)puVar6);
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



// Function: FUN_1000e0ba at 1000e0ba

void __fastcall FUN_1000e0ba(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_1002d148) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
  }
  return;
}



// Function: FUN_1000e0e6 at 1000e0e6

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000e0e6(void *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    *(undefined **)this = PTR_DAT_1002d14c;
    return 1;
  }
  FUN_10017151(param_1 * 2 + 0xe);
  uVar1 = FUN_1000e134();
  return uVar1;
}



// Function: Catch@1000e121 at 1000e121

undefined * Catch_1000e121(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e12b;
}



// Function: FUN_1000e134 at 1000e134

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000e134(void)

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



// Function: FUN_1000e15b at 1000e15b

void __fastcall FUN_1000e15b(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_1002d148) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
    *param_1 = (int)PTR_DAT_1002d14c;
  }
  return;
}



// Function: FUN_1000e18e at 1000e18e

undefined4 * __thiscall FUN_1000e18e(void *this,char param_1,LPCWSTR param_2,char param_3)

{
  HINSTANCE hInstance;
  HCURSOR pHVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 8) = 0;
  hInstance = DAT_10031344;
  if (param_3 != '\0') {
    hInstance = (HINSTANCE)0x0;
  }
  pHVar1 = LoadCursorW(hInstance,param_2);
  *(HCURSOR *)this = pHVar1;
  if (param_1 != '\0') {
    FUN_1000dd6c((undefined4 *)this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e1d0 at 1000e1d0

undefined4 FUN_1000e1d0(void *param_1)

{
  FUN_100014c5(param_1,0x10020a3c);
  return 0;
}



// Function: FUN_1000e1e6 at 1000e1e6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e1e6(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



// Function: FUN_1000e21c at 1000e21c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e21c(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  return;
}



// Function: FUN_1000e24c at 1000e24c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000e24c(int param_1)

{
  FUN_1000e1e6(param_1);
  *(code **)(param_1 + 0x20) = DefWindowProcW_exref;
  return param_1;
}



// Function: FUN_1000e27a at 1000e27a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e27a(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e2a9 at 1000e2a9

void __fastcall FUN_1000e2a9(int *param_1)

{
  FUN_1000dc16(*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000e2b9 at 1000e2b9

void __fastcall FUN_1000e2b9(undefined4 *param_1)

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



// Function: FUN_1000e2d2 at 1000e2d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000e2d2(void *this,int param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined2 *)(*this + param_1 * 2);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = *param_2;
  }
  return;
}



// Function: FUN_1000e309 at 1000e309

void __fastcall FUN_1000e309(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x28;
  }
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}



// Function: FUN_1000e33c at 1000e33c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e33c(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CContextSensitiveHelpProvider<class_CFSTRErrorDlg>::vftable;
  Ordinal_6(param_1[4]);
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e39d at 1000e39d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000e39d(undefined4 *param_1)

{
  *param_1 = CContextSensitiveHelpProvider<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  FUN_100014c5(param_1 + 4,0x10020a3c);
  param_1[1] = 0;
  return param_1;
}



// Function: FUN_1000e3f5 at 1000e3f5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e3f5(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CContextSensitiveHelpProvider<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  Ordinal_6(param_1[4]);
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000e456 at 1000e456

undefined4 * __thiscall FUN_1000e456(void *this,byte param_1)

{
  FUN_1000e33c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e475 at 1000e475

undefined4 * __thiscall FUN_1000e475(void *this,byte param_1)

{
  FUN_1000e3f5((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e494 at 1000e494

void __fastcall FUN_1000e494(undefined4 *param_1)

{
  operator_delete((void *)*param_1);
  return;
}



// Function: FUN_1000e49d at 1000e49d

void __cdecl FUN_1000e49d(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000df56(param_2,param_3);
  return;
}



// Function: FUN_1000e4b0 at 1000e4b0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_1000e4b0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined1 uVar3;
  undefined4 uVar4;
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
  local_8 = 0x1000e4bf;
  local_410 = param_2;
  *param_2 = 0;
  if ((((param_1 == (int *)0x0) ||
       (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_404,2,&local_408), iVar1 < 0)) ||
      (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,local_414,4,&local_408), iVar1 < 0)) ||
     (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&local_40c,4,&local_408), iVar1 < 0))
  goto LAB_1000e66c;
  uVar3 = local_40c == 0;
  if (local_40c == 0) {
LAB_1000e5e2:
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
    if (-1 < local_40c) goto LAB_1000e54b;
    uVar4 = 0x80070057;
    while( true ) {
      iVar1 = FUN_10001000(uVar4);
LAB_1000e54b:
      if ((bool)uVar3) break;
      local_400 = (void *)Ordinal_4(0,iVar1);
      uVar3 = local_400 == (void *)0x0;
      if (!(bool)uVar3) goto LAB_1000e555;
      uVar4 = 0x8007000e;
      local_400 = (void *)0x0;
    }
    local_400 = (void *)0x0;
LAB_1000e555:
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
        goto LAB_1000e5e2;
      }
    }
    local_8 = 0xffffffff;
    Ordinal_6(pvVar2);
  }
LAB_1000e66c:
  FUN_100172f7();
  return;
}



// Function: FUN_1000e672 at 1000e672

int * __thiscall FUN_1000e672(void *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != *(int *)param_1) {
    Ordinal_6(*this);
    pwVar1 = ATL::CComBSTR::Copy(param_1);
    *(wchar_t **)this = pwVar1;
    if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
      FUN_10001000(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_1000e6ad at 1000e6ad

int __thiscall FUN_1000e6ad(void *this,int param_1)

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
    iVar2 = FUN_1000e0e6(this,param_1);
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
    FUN_1000dd46((LONG *)((int)_Src + -0xc));
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000e712 at 1000e712

void __fastcall FUN_1000e712(int *param_1)

{
  uint _Size;
  void *_Src;
  int iVar1;
  
  _Src = (void *)*param_1;
  if (1 < *(int *)((int)_Src + -0xc)) {
    FUN_1000e15b(param_1);
    iVar1 = FUN_1000e0e6(param_1,*(int *)((int)_Src + -8));
    if (iVar1 != 0) {
      _Size = *(int *)((int)_Src + -8) * 2 + 2;
      if (_Size <= *(int *)(*param_1 + -4) * 2 + 2U) {
        memcpy((void *)*param_1,_Src,_Size);
      }
    }
  }
  return;
}



// Function: FUN_1000e753 at 1000e753

void __thiscall FUN_1000e753(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((1 < *(int *)(*this + -0xc)) || (*(int *)(*this + -4) < param_1)) {
    FUN_1000e15b((int *)this);
    FUN_1000e0e6(this,param_1);
  }
  return;
}



// Function: FUN_1000e781 at 1000e781

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e781(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000de36(param_1 + 4);
  return;
}



// Function: FUN_1000e80f at 1000e80f

undefined4 __thiscall FUN_1000e80f(void *this,undefined2 *param_1)

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
      uVar6 = FUN_10001000(0x80004005);
      iVar5 = extraout_ECX;
    }
    if ((int)uVar6 == 0) {
      _Count = 1;
LAB_1000e851:
      pvVar3 = _recalloc((void *)((ulonglong)uVar6 >> 0x20),_Count,2);
      if (pvVar3 != (void *)0x0) {
        *(uint *)((int)this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_1000e867;
      }
    }
    else {
      _Count = iVar5 * 2;
      if ((-1 < (int)_Count) && (_Count < 0x40000000)) goto LAB_1000e851;
    }
    uVar4 = 0;
  }
  else {
LAB_1000e867:
    FUN_1000e2d2(this,*(int *)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
    uVar4 = 1;
  }
  return uVar4;
}



// Function: FUN_1000e884 at 1000e884

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e884(int param_1)

{
  FUN_1000e21c(param_1);
  return;
}



// Function: FUN_1000e8a2 at 1000e8a2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000e8a2(int param_1)

{
  FUN_1000e1e6(param_1);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  return param_1;
}



// Function: FUN_1000e8d3 at 1000e8d3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000e8d3(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10021f44,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e90e at 1000e90e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000e90e(void *this,undefined4 param_1)

{
  *(undefined ***)this = CContextSensitiveHelpProvider<class_CFSTRErrorDlg>::vftable;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  FUN_1000e672((undefined4 *)((int)this + 0x10),(CComBSTR *)&param_1);
  *(undefined4 *)((int)this + 4) = 0;
  Ordinal_6(param_1);
  return (undefined4 *)this;
}



// Function: FUN_1000e96e at 1000e96e

void __thiscall FUN_1000e96e(void *this,uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if ((uVar1 <= param_1) && (*(uint *)((int)this + 0x14) != param_1)) {
    bVar2 = FUN_10001b8a(this,param_1,'\x01');
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



// Function: FUN_1000e9a7 at 1000e9a7

int * __fastcall FUN_1000e9a7(int *param_1)

{
  void *pvVar1;
  
  param_1[1] = 0;
  pvVar1 = FUN_1000dea1((char *)0x1);
  *param_1 = (int)pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*param_1 + 4) = *param_1;
  return param_1;
}



// Function: FUN_1000e9c8 at 1000e9c8

void __thiscall FUN_1000e9c8(void *this,uint param_1)

{
  int extraout_EAX;
  int iVar1;
  void *extraout_ECX;
  uint extraout_EDX;
  
  iVar1 = *(int *)((int)this + 4);
  if (0x3ffffffeU - iVar1 < param_1) {
    std::_Xlength_error("list<T> too long");
    iVar1 = extraout_EAX;
    this = extraout_ECX;
    param_1 = extraout_EDX;
  }
  *(uint *)((int)this + 4) = iVar1 + param_1;
  return;
}



// Function: FUN_1000e9f2 at 1000e9f2

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_1000e9f2(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000dea1((char *)0x1);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  FUN_1000e49d((int)this + 9,puVar1 + 2,param_3);
  return puVar1;
}



// Function: Catch@1000ea40 at 1000ea40

void Catch_1000ea40(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000ea53 at 1000ea53

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ea53(int param_1)

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
  FUN_1000e27a(param_1 + 0x38);
  FUN_1000e21c(param_1);
  return;
}



// Function: FUN_1000ebb8 at 1000ebb8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ebb8(int param_1)

{
  FUN_1000e21c(param_1);
  return;
}



// Function: FUN_1000ebd6 at 1000ebd6

int __thiscall FUN_1000ebd6(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  wchar_t *pwVar1;
  void *_Src;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  wchar_t *pwVar8;
  int local_14;
  int local_10;
  int local_8;
  
  if ((param_1 == (LPCWSTR)0x0) || (iVar3 = lstrlenW(param_1), iVar3 == 0)) {
    local_10 = 0;
  }
  else {
    if (param_2 == (LPCWSTR)0x0) {
      local_8 = 0;
    }
    else {
      local_8 = lstrlenW(param_2);
    }
                    /* WARNING: Load size is inaccurate */
    pwVar8 = *this;
    pwVar1 = pwVar8 + *(int *)(pwVar8 + -4);
    local_10 = 0;
    if (pwVar8 < pwVar1) {
      do {
        while (pwVar4 = wcsstr(pwVar8,param_1), pwVar4 != (wchar_t *)0x0) {
          local_10 = local_10 + 1;
          pwVar8 = pwVar4 + iVar3;
        }
        iVar5 = lstrlenW(pwVar8);
        pwVar8 = pwVar8 + iVar5 + 1;
      } while (pwVar8 < pwVar1);
      if (0 < local_10) {
        FUN_1000e712((int *)this);
                    /* WARNING: Load size is inaccurate */
        _Src = *this;
        local_14 = *(int *)((int)_Src + -8);
        iVar5 = (local_8 - iVar3) * local_10 + local_14;
        if ((*(int *)((int)_Src + -4) < iVar5) || (1 < *(int *)((int)_Src + -0xc))) {
          iVar6 = FUN_1000e0e6(this,iVar5);
          if (iVar6 == 0) {
            return -1;
          }
          uVar2 = *(int *)((int)_Src + -8) * 2;
          if (uVar2 <= iVar5 * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
            memcpy(*this,_Src,uVar2);
          }
          FUN_1000dd46((LONG *)((int)_Src + -0xc));
        }
                    /* WARNING: Load size is inaccurate */
        pwVar8 = *this;
        pwVar1 = pwVar8 + *(int *)(pwVar8 + -4);
        for (; pwVar8 < pwVar1; pwVar8 = pwVar8 + iVar6 + 1) {
          while (pwVar4 = wcsstr(pwVar8,param_1), pwVar4 != (wchar_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
            iVar7 = (int)pwVar4 - *this >> 1;
            iVar6 = (local_14 - iVar7) - iVar3;
            iVar7 = *(int *)(*this + -4) - iVar7;
            uVar2 = iVar6 * 2;
            if (uVar2 <= (iVar7 - local_8) * 2 + 2U) {
              memmove(pwVar4 + local_8,pwVar4 + iVar3,uVar2);
            }
            if ((uint)(local_8 * 2) <= iVar7 * 2 + 2U) {
              memcpy(pwVar4,param_2,local_8 * 2);
            }
            pwVar8 = pwVar4 + local_8;
            local_14 = local_14 + (local_8 - iVar3);
            pwVar8[iVar6] = L'\0';
          }
          iVar6 = lstrlenW(pwVar8);
        }
                    /* WARNING: Load size is inaccurate */
        *(int *)(*this + -8) = iVar5;
      }
    }
  }
  return local_10;
}



// Function: FUN_1000ed87 at 1000ed87

void __thiscall FUN_1000ed87(void *this,int param_1)

{
  FUN_1000e712((int *)this);
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



// Function: FUN_1000edb4 at 1000edb4

void __thiscall FUN_1000edb4(void *this,int param_1,void *param_2)

{
  uint _Size;
  int iVar1;
  
  iVar1 = FUN_1000e753(this,param_1);
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



// Function: FUN_1000edf5 at 1000edf5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000edf5(undefined4 *param_1)

{
  int *piVar1;
  
  FUN_1000e309((int)(param_1 + 1));
  *param_1 = CComECMPropertyPageImpl<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[1] = CComECMPropertyPageImpl<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  piVar1 = param_1 + 0xe;
  *piVar1 = 0;
  param_1[0xf] = 0;
  if (*piVar1 != 0) {
    FUN_100010fd(piVar1,(int *)0x0);
  }
  param_1[0x10] = 0;
  return param_1;
}



// Function: FUN_1000ee6a at 1000ee6a

undefined4 FUN_1000ee6a(undefined4 param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_2 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ee86 at 1000ee86

void FUN_1000ee86(int *param_1,short *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2);
  if ((-1 < iVar1) && (*param_2 == 0)) {
    (**(code **)(*param_1 + 0x28))(param_1,param_2);
  }
  return;
}



// Function: FUN_1000eeaf at 1000eeaf

void __thiscall FUN_1000eeaf(void *this,byte param_1)

{
  FUN_1000eeb7((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_1000eeb7 at 1000eeb7

void * __thiscall FUN_1000eeb7(void *this,byte param_1)

{
  FUN_1000e781((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000eed6 at 1000eed6

undefined4 FUN_1000eed6(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_100010fd((int *)(param_1 + 0x38),(int *)0x0);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_100010fd((int *)(param_1 + 0x30),(int *)0x0);
  }
  return 0;
}



// Function: FUN_1000ef04 at 1000ef04

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ef04(int param_1)

{
  FUN_1000ea53(param_1);
  return;
}



// Function: FUN_1000ef22 at 1000ef22

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __fastcall FUN_1000ef22(int *param_1)

{
  int *apiStack_2c [5];
  undefined1 *local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x1000ef2e;
  local_18 = (undefined1 *)apiStack_2c;
  apiStack_2c[0] = param_1;
  local_14 = param_1;
  FUN_1000e9a7(param_1);
  return local_14;
}



// Function: FUN_1000ef4a at 1000ef4a

void __thiscall FUN_1000ef4a(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_1000e9f2(this,param_1,*(undefined4 *)(param_1 + 4),param_2);
  FUN_1000e9c8(this,1);
  *(undefined4 *)(param_1 + 4) = puVar1;
  *(undefined4 **)puVar1[1] = puVar1;
  return;
}



// Function: FUN_1000ef7c at 1000ef7c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000ef7c(undefined4 *param_1)

{
  undefined4 extraout_ECX;
  undefined4 uVar1;
  
  FUN_1000e8a2((int)param_1);
  uVar1 = extraout_ECX;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffd4,(CComBSTR *)&DAT_10030330);
  FUN_1000e90e(param_1 + 10,uVar1);
  *param_1 = CFSTRErrorDlg::vftable;
  param_1[10] = CFSTRErrorDlg::vftable;
  param_1[0xf] = 0;
  param_1[0x15] = 7;
  param_1[0x14] = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  return param_1;
}



// Function: FUN_1000effe at 1000effe

int __cdecl FUN_1000effe(uint param_1,ushort *param_2,int *param_3)

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



// Function: FUN_1000f03c at 1000f03c

undefined4 __cdecl FUN_1000f03c(int param_1,int param_2)

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



// Function: FUN_1000f059 at 1000f059

int FUN_1000f059(HWND param_1,LRESULT *param_2)

{
  int iVar1;
  LRESULT LVar2;
  
  if (param_2 == (LRESULT *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    LVar2 = SendMessageW(param_1,DAT_1002f1b8,0,0);
    *param_2 = LVar2;
    iVar1 = (-(uint)(LVar2 != 0) & 0x7fffbffb) + 0x80004005;
  }
  return iVar1;
}



// Function: FUN_1000f093 at 1000f093

void __thiscall FUN_1000f093(void *this,byte param_1)

{
  FUN_1000f21d((void *)((int)this + -0x28),param_1);
  return;
}



// Function: FUN_1000f09b at 1000f09b

void __thiscall
FUN_1000f09b(void *this,LPCWSTR param_1,HWND param_2,int *param_3,LPCWSTR param_4,DWORD param_5,
            DWORD param_6,HMENU param_7,LPVOID param_8)

{
  HWND pHVar1;
  
  if (param_3 == (int *)0x0) {
    param_3 = &DAT_1002d000;
  }
  pHVar1 = CreateWindowExW(param_6,param_1,param_4,param_5,*param_3,param_3[1],param_3[2] - *param_3
                           ,param_3[3] - param_3[1],param_2,param_7,DAT_10031340,param_8);
  *(HWND *)this = pHVar1;
  return;
}



// Function: FUN_1000f0ed at 1000f0ed

int FUN_1000f0ed(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 == 0x110) && (iVar1 = (**(code **)(*param_1 + 0x10))(100), iVar1 < 0)) {
    param_1[9] = iVar1;
    if ((char)param_1[8] != '\0') {
      EndDialog((HWND)param_1[1],-1);
    }
    return 0;
  }
  iVar1 = FUN_100039bf(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_1000f136 at 1000f136

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_1000f136(void *this,undefined4 param_1,int *param_2)

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
    piStackY_2c = (int *)0x1000f169;
    iVar4 = FUN_1000f059(*this,(LRESULT *)&param_2);
    piVar3 = param_2;
    puVar5 = (undefined4 *)auStack_20;
    if (-1 < iVar4) {
      piStackY_2c = param_2;
      puVar5 = &uStackY_30;
      uStackY_30 = 0x1000f17b;
      iVar4 = (**(code **)*param_2)();
    }
    local_8 = 0xffffffff;
    if (piVar3 != (int *)0x0) {
      iVar1 = *piVar3;
      *(int **)((int)puVar5 + -4) = piVar3;
      pcVar2 = *(code **)(iVar1 + 8);
      puVar6 = (undefined4 *)((int)puVar5 + -8);
      puVar5 = (undefined4 *)((int)puVar5 + -8);
      *puVar6 = 0x1000f18b;
      (*pcVar2)();
    }
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x1000f192;
  return iVar4;
}



// Function: FUN_1000f195 at 1000f195

undefined * FUN_1000f195(void)

{
  return FUN_1000f0ed;
}



// Function: FUN_1000f19b at 1000f19b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000f19b(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CFSTRErrorDlg::vftable;
  param_1[10] = CFSTRErrorDlg::vftable;
  piVar1 = (int *)param_1[0x18];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[0x17];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FID_conflict__Tidy(param_1 + 0x10,'\x01',0);
  FUN_1000e33c(param_1 + 10);
  FUN_1000e21c((int)param_1);
  return;
}



// Function: FUN_1000f21d at 1000f21d

undefined4 * __thiscall FUN_1000f21d(void *this,byte param_1)

{
  FUN_1000f19b((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000f23c at 1000f23c

void * __thiscall FUN_1000f23c(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    iVar1 = lstrlenW(param_1);
  }
  FUN_1000edb4(this,iVar1,param_1);
  return this;
}



// Function: FUN_1000f264 at 1000f264

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_1000f264(void *this,LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  undefined1 *puVar4;
  HWND hWnd;
  BOOL BVar5;
  LPCWSTR pWVar6;
  UINT Msg;
  WPARAM wParam;
  LPCWSTR pWVar7;
  undefined4 local_48;
  int local_44;
  int local_40;
  LPCWSTR local_3c;
  undefined4 *local_1c;
  int local_18;
  LPCWSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  puVar4 = &LAB_1001a19b;
  iVar1 = *(int *)param_1;
  local_1c = (undefined4 *)this;
  pWVar6 = param_1;
  do {
    if (iVar1 == 0) {
      return puVar4;
    }
    local_14[0] = (LPCWSTR)0x0;
    local_8 = 1;
    iVar1 = *(int *)pWVar6;
    local_18 = -0x7fffbffb;
    param_1 = (LPCWSTR)PTR_DAT_1002d14c;
    if (((iVar1 == 0x1f5) || (iVar1 == 0x192)) || (iVar1 == 0x193)) {
      local_18 = 0;
    }
    else {
      uVar2 = *(uint *)(pWVar6 + 4);
      Ordinal_6(0);
      local_14[0] = (LPCWSTR)0x0;
      bVar3 = FUN_1000117f(uVar2,(int *)local_14);
      if (bVar3) {
        FUN_1000f23c(&param_1,local_14[0]);
        local_18 = 0;
      }
    }
    if (*(int *)pWVar6 == 100) {
      hWnd = (HWND)*local_1c;
LAB_1000f3fa:
      SetWindowTextW(hWnd,param_1);
    }
    else {
      hWnd = GetDlgItem((HWND)*local_1c,*(int *)(pWVar6 + 2));
      if (((-1 < local_18) && (BVar5 = IsWindow((HWND)*local_1c), BVar5 != 0)) &&
         (BVar5 = IsWindow(hWnd), BVar5 != 0)) {
        iVar1 = *(int *)pWVar6;
        if ((iVar1 == 200) || (iVar1 == 300)) {
          FUN_1000ebd6(&param_1,L"\\r\\n",L"\r\n");
          goto LAB_1000f3fa;
        }
        if (iVar1 == 500) {
          local_40 = *(int *)(pWVar6 + 8);
          local_44 = *(int *)(pWVar6 + 10);
          local_3c = param_1;
          wParam = *(WPARAM *)(pWVar6 + 6);
          local_48 = 7;
          Msg = 0x1061;
          pWVar7 = (LPCWSTR)&local_48;
        }
        else if (iVar1 == 0x1f5) {
          wParam = *(WPARAM *)(pWVar6 + 6);
          Msg = 0x101e;
          pWVar7 = (LPCWSTR)(uint)(ushort)pWVar6[8];
        }
        else {
          pWVar7 = param_1;
          if (iVar1 == 400) {
            wParam = 0;
            Msg = 0x143;
          }
          else if (iVar1 == 0x191) {
            wParam = *(WPARAM *)(pWVar6 + 6);
            Msg = 0x14a;
          }
          else if (iVar1 == 0x192) {
            pWVar7 = (LPCWSTR)0x0;
            wParam = *(WPARAM *)(pWVar6 + 6);
            Msg = 0x14e;
          }
          else {
            if (iVar1 != 0x193) goto LAB_1000f400;
            pWVar7 = *(LPCWSTR *)(pWVar6 + 8);
            wParam = *(WPARAM *)(pWVar6 + 6);
            Msg = 0x151;
          }
        }
        SendMessageW(hWnd,Msg,wParam,(LPARAM)pWVar7);
      }
    }
LAB_1000f400:
    pWVar6 = pWVar6 + 0xc;
    local_8 = local_8 & 0xffffff00;
    FUN_1000e0ba((int *)&param_1);
    local_8 = 0xffffffff;
    puVar4 = (undefined1 *)Ordinal_6(local_14[0]);
    iVar1 = *(int *)pWVar6;
  } while( true );
}



// Function: FUN_1000f42d at 1000f42d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000f42d(int param_1)

{
  DWORD DVar1;
  
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_1000e24c(param_1);
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



// Function: FUN_1000f578 at 1000f578

undefined4
FUN_1000f578(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,int param_6)

{
  if (param_6 == 0) {
    if (param_2 == 0x110) {
      FUN_100019de(100);
    }
    else if (param_2 != 2) {
      return 0;
    }
    *param_5 = 1;
  }
  return 0;
}



// Function: FUN_1000f5a8 at 1000f5a8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000f5a8(void *this,undefined4 param_1)

{
  FUN_1000f42d((int)this);
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



// Function: FUN_1000f622 at 1000f622

void __fastcall FUN_1000f622(undefined4 *param_1)

{
  HWND hWnd;
  int iVar1;
  WCHAR local_18 [8];
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  hWnd = GetParent((HWND)*param_1);
  iVar1 = GetClassNameW(hWnd,local_18,8);
  if (iVar1 != 0) {
    lstrcmpW(local_18,L"#32770");
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f66b at 1000f66b

void __fastcall FUN_1000f66b(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar1 + 8))(piVar1);
  return;
}



// Function: FUN_1000f679 at 1000f679

void FUN_1000f679(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



// Function: FUN_1000f69d at 1000f69d

undefined4 FUN_1000f69d(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) ^ (param_2 ^ *(uint *)(param_1 + 0x7c)) & 1;
  return 0;
}



// Function: FUN_1000f6b5 at 1000f6b5

undefined4 FUN_1000f6b5(int param_1,short *param_2)

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



// Function: FUN_1000f6df at 1000f6df

undefined4 FUN_1000f6df(int param_1,undefined4 *param_2)

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



// Function: FUN_1000f701 at 1000f701

undefined4 FUN_1000f701(int param_1,undefined4 *param_2)

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



// Function: FUN_1000f723 at 1000f723

undefined4 FUN_1000f723(int param_1,undefined4 *param_2)

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



// Function: FUN_1000f745 at 1000f745

undefined4 FUN_1000f745(int param_1,short *param_2)

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



// Function: FUN_1000f76f at 1000f76f

undefined4 FUN_1000f76f(int param_1,short *param_2)

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



// Function: FUN_1000f799 at 1000f799

undefined4 FUN_1000f799(int param_1,short *param_2)

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



// Function: FUN_1000f7c3 at 1000f7c3

void FUN_1000f7c3(undefined4 param_1,undefined2 *param_2)

{
  *param_2 = 0;
  return;
}



// Function: FUN_1000f7d2 at 1000f7d2

undefined4 FUN_1000f7d2(undefined4 param_1,undefined2 *param_2)

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



// Function: FUN_1000f7ee at 1000f7ee

undefined4 FUN_1000f7ee(int param_1,undefined4 *param_2)

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



// Function: FUN_1000f810 at 1000f810

undefined4 FUN_1000f810(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x98) = param_2;
  return 0;
}



// Function: FUN_1000f825 at 1000f825

undefined4 FUN_1000f825(int param_1,undefined4 *param_2)

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



// Function: FUN_1000f847 at 1000f847

undefined4 FUN_1000f847(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 5 ^ *(uint *)(param_1 + 0x7c)) & 0x20;
  return 0;
}



// Function: FUN_1000f863 at 1000f863

undefined4 FUN_1000f863(int param_1,short *param_2)

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



// Function: FUN_1000f88d at 1000f88d

undefined4 FUN_1000f88d(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 6 ^ *(uint *)(param_1 + 0x7c)) & 0x40;
  return 0;
}



// Function: FUN_1000f8a9 at 1000f8a9

undefined4 FUN_1000f8a9(int param_1,short *param_2)

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



// Function: FUN_1000f8d3 at 1000f8d3

undefined4 FUN_1000f8d3(int param_1,undefined4 *param_2)

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



// Function: FUN_1000f8fd at 1000f8fd

undefined4 FUN_1000f8fd(void)

{
  return 0x80004001;
}



// Function: FUN_1000f905 at 1000f905

LPWSTR __cdecl FUN_1000f905(LPWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_1000f94a at 1000f94a

undefined4 FUN_1000f94a(int param_1,undefined4 *param_2)

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



// Function: FUN_1000f969 at 1000f969

undefined4 FUN_1000f969(void)

{
  return 0;
}



// Function: FUN_1000f96e at 1000f96e

undefined4 FUN_1000f96e(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 2;
  return 0;
}



// Function: FUN_1000f97e at 1000f97e

undefined4 FUN_1000f97e(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffffd;
  return 0;
}



// Function: FUN_1000f98e at 1000f98e

undefined4 FUN_1000f98e(void)

{
  return 0x80004001;
}



// Function: FUN_1000f996 at 1000f996

void FUN_1000f996(int param_1,int *param_2)

{
  BOOL BVar1;
  HWND hWnd;
  tagPOINT local_18;
  tagPOINT local_10;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
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



// Function: FUN_1000fa36 at 1000fa36

uint FUN_1000fa36(int param_1)

{
  return ~*(uint *)(param_1 + 0x9c) & 1;
}



// Function: FUN_1000fa4b at 1000fa4b

uint FUN_1000fa4b(int param_1)

{
  return ~(*(uint *)(param_1 + 0x6c) >> 4) & 1;
}



// Function: FUN_1000fa60 at 1000fa60

undefined4 FUN_1000fa60(int param_1,int param_2)

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



// Function: FUN_1000fa90 at 1000fa90

uint FUN_1000fa90(int param_1)

{
  return ~(*(uint *)(param_1 + 0x6c) >> 5) & 1;
}



// Function: FUN_1000faa5 at 1000faa5

undefined4 FUN_1000faa5(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x6c) =
       *(uint *)(param_1 + 0x6c) ^ (param_2 << 5 ^ *(uint *)(param_1 + 0x6c)) & 0x20;
  return 0;
}



// Function: FUN_1000fac0 at 1000fac0

void FUN_1000fac0(int param_1,undefined4 param_2,byte param_3,undefined4 *param_4)

{
  HDC pHVar1;
  HBITMAP h;
  HGDIOBJ ho;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  if ((param_4 == (undefined4 *)0x0) || (*(char *)(param_1 + 0x30) == '\0')) goto LAB_1000fb95;
  pHVar1 = GetDC(*(HWND *)(param_1 + -0x28));
  *param_4 = pHVar1;
  if ((pHVar1 == (HDC)0x0) || (*(undefined1 *)(param_1 + 0x30) = 0, (param_3 & 1) != 0))
  goto LAB_1000fb95;
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
        goto LAB_1000fb7f;
      }
      DeleteObject(h);
    }
    DeleteDC(pHVar1);
  }
LAB_1000fb7f:
  if ((param_3 & 2) != 0) {
    FillRect((HDC)*param_4,&local_18,(HBRUSH)0x6);
  }
LAB_1000fb95:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fba5 at 1000fba5

void FUN_1000fba5(int param_1,HDC param_2)

{
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
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



// Function: FUN_1000fc21 at 1000fc21

undefined4 FUN_1000fc21(int param_1,RECT *param_2,BOOL param_3)

{
  InvalidateRect(*(HWND *)(param_1 + -0x28),param_2,param_3);
  return 0;
}



// Function: FUN_1000fc3c at 1000fc3c

undefined4 FUN_1000fc3c(int param_1,HRGN param_2,BOOL param_3)

{
  InvalidateRgn(*(HWND *)(param_1 + -0x28),param_2,param_3);
  return 0;
}



// Function: FUN_1000fc57 at 1000fc57

undefined4 FUN_1000fc57(void)

{
  return 0;
}



// Function: FUN_1000fc5c at 1000fc5c

undefined4 FUN_1000fc5c(void)

{
  return 1;
}



// Function: FUN_1000fc62 at 1000fc62

undefined4 FUN_1000fc62(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x68) =
       *(uint *)(param_1 + 0x68) ^ (param_2 << 5 ^ *(uint *)(param_1 + 0x68)) & 0x20;
  return 0;
}



// Function: FUN_1000fc7d at 1000fc7d

void FUN_1000fc7d(void)

{
  return;
}



// Function: FUN_1000fc80 at 1000fc80

void FUN_1000fc80(void)

{
  return;
}



// Function: FUN_1000fc83 at 1000fc83

undefined4 FUN_1000fc83(void)

{
  return 0x80004001;
}



// Function: FUN_1000fc8b at 1000fc8b

undefined4 FUN_1000fc8b(int param_1,int param_2)

{
  *(uint *)(param_1 + 100) =
       *(uint *)(param_1 + 100) ^ (param_2 << 7 ^ *(uint *)(param_1 + 100)) & 0x80;
  return 0;
}



// Function: FUN_1000fca9 at 1000fca9

void FUN_1000fca9(int *param_1,int *param_2)

{
  HDC hdc;
  int iVar1;
  int nNumber;
  
  if (param_1 != (int *)0x0) goto LAB_1000fcbd;
  do {
    FUN_10001000(0x80004003);
LAB_1000fcbd:
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



// Function: FUN_1000fd1e at 1000fd1e

void FUN_1000fd1e(int *param_1,int *param_2)

{
  HDC hdc;
  int iVar1;
  int nDenominator;
  
  if (param_1 != (int *)0x0) goto LAB_1000fd32;
  do {
    FUN_10001000(0x80004003);
LAB_1000fd32:
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



// Function: FUN_1000fd93 at 1000fd93

undefined4 __thiscall FUN_1000fd93(void *this,int *param_1)

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



// Function: FUN_1000fdba at 1000fdba

undefined4 FUN_1000fdba(int param_1,undefined4 param_2,undefined4 *param_3)

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



// Function: FUN_1000fdf5 at 1000fdf5

void FUN_1000fdf5(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 4))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000fe08 at 1000fe08

void FUN_1000fe08(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 8))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000fe1b at 1000fe1b

void FUN_1000fe1b(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x2c))(*(undefined4 **)(param_1 + 0x2c),param_2,param_3);
  return;
}



// Function: FUN_1000fe33 at 1000fe33

undefined4 __fastcall FUN_1000fe33(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}



// Function: FUN_1000fe37 at 1000fe37

LRESULT FUN_1000fe37(int *param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int *piVar1;
  UINT Msg;
  int iVar2;
  LONG LVar3;
  undefined1 local_2c [36];
  LONG local_8;
  
  Msg = param_2;
  piVar1 = param_1;
  FUN_10002f12(local_2c,param_1[1],param_2,param_3,param_4,1);
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



// Function: FUN_1000ff2d at 1000ff2d

undefined4 __cdecl FUN_1000ff2d(int *param_1,int *param_2)

{
  int *piVar1;
  int *extraout_ECX;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    param_2 = (int *)FUN_10001000(0x80004005);
    param_1 = extraout_ECX;
  }
  piVar1 = (int *)*param_2;
  *param_1 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}



// Function: FUN_1000ff5a at 1000ff5a

void FUN_1000ff5a(int param_1)

{
  FUN_1000fe08(param_1 + -0x24);
  return;
}



// Function: FUN_1000ff64 at 1000ff64

void FUN_1000ff64(int param_1)

{
  FUN_1000fdf5(param_1 + -0x1c);
  return;
}



// Function: FUN_1000ff6e at 1000ff6e

void FUN_1000ff6e(int param_1)

{
  FUN_1000fe08(param_1 + -8);
  return;
}



// Function: FUN_1000ff78 at 1000ff78

void FUN_1000ff78(int param_1)

{
  FUN_1000fe08(param_1 + -0x28);
  return;
}



// Function: FUN_1000ff82 at 1000ff82

void FUN_1000ff82(int param_1)

{
  FUN_1000fdf5(param_1 + -0x20);
  return;
}



// Function: FUN_1000ff8c at 1000ff8c

void FUN_1000ff8c(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -0x1c,param_2,param_3);
  return;
}



// Function: FUN_1000ff96 at 1000ff96

void FUN_1000ff96(int param_1)

{
  FUN_1000fe08(param_1 + -0xc);
  return;
}



// Function: FUN_1000ffa0 at 1000ffa0

void FUN_1000ffa0(int param_1)

{
  FUN_1000fdf5(param_1 + -4);
  return;
}



// Function: FUN_1000ffaa at 1000ffaa

void FUN_1000ffaa(int param_1)

{
  FUN_1000fdf5(param_1 + -0x24);
  return;
}



// Function: FUN_1000ffb4 at 1000ffb4

void FUN_1000ffb4(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -0x20,param_2,param_3);
  return;
}



// Function: FUN_1000ffbe at 1000ffbe

void FUN_1000ffbe(int param_1)

{
  FUN_1000fe08(param_1 + -0x10);
  return;
}



// Function: FUN_1000ffc8 at 1000ffc8

void FUN_1000ffc8(int param_1)

{
  FUN_1000fdf5(param_1 + -8);
  return;
}



// Function: FUN_1000ffd2 at 1000ffd2

void FUN_1000ffd2(int param_1)

{
  FUN_1000fdf5(param_1 + -0x28);
  return;
}



// Function: FUN_1000ffdc at 1000ffdc

void FUN_1000ffdc(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000ffe6 at 1000ffe6

void FUN_1000ffe6(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -0x24,param_2,param_3);
  return;
}



// Function: FUN_1000fff0 at 1000fff0

void FUN_1000fff0(int param_1)

{
  FUN_1000fe08(param_1 + -0x14);
  return;
}



// Function: FUN_1000fffa at 1000fffa

void FUN_1000fffa(int param_1)

{
  FUN_1000fdf5(param_1 + -0xc);
  return;
}



// Function: FUN_10010004 at 10010004

void FUN_10010004(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1001000e at 1001000e

void FUN_1001000e(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -0x28,param_2,param_3);
  return;
}



// Function: FUN_10010018 at 10010018

void FUN_10010018(int param_1)

{
  FUN_1000fdf5(param_1 + -0x10);
  return;
}



// Function: FUN_10010022 at 10010022

void FUN_10010022(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1001002c at 1001002c

void FUN_1001002c(int param_1)

{
  FUN_1000fe08(param_1 + -0x1c);
  return;
}



// Function: FUN_10010036 at 10010036

void __thiscall FUN_10010036(void *this,byte param_1)

{
  FUN_1001202d((void *)((int)this + -0x38),param_1);
  return;
}



// Function: FUN_1001003e at 1001003e

void FUN_1001003e(int param_1)

{
  FUN_1000fdf5(param_1 + -0x14);
  return;
}



// Function: FUN_10010048 at 10010048

void FUN_10010048(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_10010052 at 10010052

void FUN_10010052(int param_1)

{
  FUN_1000fe08(param_1 + -0x20);
  return;
}



// Function: FUN_1001005c at 1001005c

void FUN_1001005c(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fe1b(param_1 + -0x14,param_2,param_3);
  return;
}



// Function: FUN_10010066 at 10010066

void FUN_10010066(int param_1)

{
  FUN_1000fe08(param_1 + -4);
  return;
}



// Function: FUN_10010070 at 10010070

undefined2 * __thiscall FUN_10010070(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_10010087;
  while( true ) {
    FUN_10001000(iVar1);
LAB_10010087:
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



// Function: FUN_100100b9 at 100100b9

undefined4 __thiscall
FUN_100100b9(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
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
  FUN_1000fd1e((int *)((int)this + 0xac),(int *)((int)this + 0xa4));
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



// Function: FUN_10010152 at 10010152

undefined4 __thiscall
FUN_10010152(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
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



// Function: FUN_10010194 at 10010194

undefined4 __thiscall
FUN_10010194(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
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



// Function: FUN_100101d1 at 100101d1

void __thiscall FUN_100101d1(void *this)

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
  
  local_8 = DAT_1002f19c ^ (uint)&stack0xfffffffc;
  if (*(int *)((int)this + 0x70) == 0) {
    pHVar1 = BeginPaint(*(HWND *)((int)this + 4),&local_58);
    if (pHVar1 == (HDC)0x0) goto LAB_10010338;
    GetClientRect(*(HWND *)((int)this + 4),&local_18);
    hbr = CreateSolidBrush(*(COLORREF *)((int)this + 0xcc));
    if (hbr != (HBRUSH)0x0) {
      FillRect(pHVar1,&local_18,hbr);
LAB_10010236:
      DeleteObject(hbr);
    }
  }
  else {
    if ((*(byte *)((int)this + 0x98) & 8) == 0) {
      *in_stack_00000010 = 0;
      goto LAB_10010338;
    }
    pHVar1 = BeginPaint(*(HWND *)((int)this + 4),&local_58);
    if (pHVar1 == (HDC)0x0) goto LAB_10010338;
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
      goto LAB_10010236;
    }
  }
  EndPaint(*(HWND *)((int)this + 4),&local_58);
LAB_10010338:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010349 at 10010349

undefined4 FUN_10010349(int param_1,undefined4 param_2,undefined4 *param_3)

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



// Function: FUN_10010379 at 10010379

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10010379(int param_1,int *param_2)

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
  local_8 = 0x10010388;
  local_80 = param_2;
  if (param_2 == (int *)0x0) goto LAB_100104e7;
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
          goto LAB_1001049b;
        }
      }
      else {
        hdc = GetDC(*(HWND *)(param_1 + -0x48));
        if (hdc != (HDC)0x0) {
          iVar1 = GetDeviceCaps(hdc,0x5a);
          pHVar2 = *(HWND *)(param_1 + -0x48);
LAB_1001049b:
          ReleaseDC(pHVar2,hdc);
          local_98 = (local_7c * 720000) / iVar1;
          local_94 = 0;
          Ordinal_420(&local_a0,&DAT_10022f24,local_74);
          local_8 = 0xffffffff;
          FUN_1000128f(&local_78);
          goto LAB_100104e1;
        }
      }
    }
    FUN_1000250b();
    local_8 = 0xffffffff;
    FUN_1000128f(&local_78);
  }
  else {
LAB_100104e1:
    FUN_1000fd93(local_74,local_80);
  }
LAB_100104e7:
  FUN_100172f7();
  return;
}



// Function: FUN_100104ef at 100104ef

undefined4 FUN_100104ef(int param_1,int param_2)

{
  FUN_100014c5((void *)(param_1 + 0x9c),param_2);
  return 0;
}



// Function: FUN_10010509 at 10010509

int FUN_10010509(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = -0x7fffbffd;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    puVar1 = *(undefined4 **)(param_1 + 0x14);
    if ((puVar1 == (undefined4 *)0x0) ||
       (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_10022f34,param_2), iVar2 < 0)) {
      iVar2 = (*(code *)**(undefined4 **)(param_1 + -4))
                        ((undefined4 *)(param_1 + -4),&DAT_10022f34,param_2);
    }
  }
  return iVar2;
}



// Function: FUN_10010549 at 10010549

undefined4 FUN_10010549(int param_1)

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



// Function: FUN_1001059c at 1001059c

undefined4 FUN_1001059c(int param_1)

{
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
  OleLockRunning(*(LPUNKNOWN *)(param_1 + 0x38),1,0);
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffff7;
  (**(code **)**(undefined4 **)(param_1 + 0x38))
            (*(undefined4 **)(param_1 + 0x38),&DAT_10022f44,param_1 + 0x48);
  return 0;
}



// Function: FUN_100105d0 at 100105d0

undefined4 FUN_100105d0(int param_1)

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



// Function: FUN_100105f1 at 100105f1

undefined4 FUN_100105f1(int param_1,undefined4 param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
  OleLockRunning(*(LPUNKNOWN *)(param_1 + 0x38),1,0);
  if ((param_3 & 1) != 0) {
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 8;
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x38))
                      (*(undefined4 **)(param_1 + 0x38),&DAT_10022f54,param_1 + 0x48);
    if (-1 < iVar2) goto LAB_1001063e;
  }
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffff7;
  (**(code **)**(undefined4 **)(param_1 + 0x38))
            (*(undefined4 **)(param_1 + 0x38),&DAT_10022f44,param_1 + 0x48);
LAB_1001063e:
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,param_1 + 0x88,param_1 + 0x88);
  }
  return 0;
}



// Function: FUN_1001065a at 1001065a

undefined4 FUN_1001065a(int param_1)

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



// Function: FUN_1001067b at 1001067b

undefined4 FUN_1001067b(int param_1,UINT param_2,WPARAM param_3,LPARAM param_4,LRESULT *param_5)

{
  LRESULT LVar1;
  
  LVar1 = CallWindowProcW(*(WNDPROC *)(param_1 + -0xc),*(HWND *)(param_1 + -0x28),param_2,param_3,
                          param_4);
  *param_5 = LVar1;
  return 0;
}



// Function: FUN_100106a1 at 100106a1

undefined4 FUN_100106a1(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = (**(code **)**(undefined4 **)(param_1 + 0x34))
                      (*(undefined4 **)(param_1 + 0x34),&DAT_10021c4c,param_2);
  }
  return uVar1;
}



// Function: FUN_100106c8 at 100106c8

undefined4 FUN_100106c8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

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



// Function: FUN_100106ff at 100106ff

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100106ff(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10010724 at 10010724

undefined * FUN_10010724(void)

{
  return FUN_1000fe37;
}



// Function: FUN_1001072a at 1001072a

LRESULT __fastcall FUN_1001072a(int param_1)

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



// Function: FUN_1001074e at 1001074e

undefined4 FUN_1001074e(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x38;
  }
  if (*(int **)(iVar1 + 0x3c) != param_2) {
    FUN_100010fd((int *)(iVar1 + 0x3c),param_2);
  }
  return 0;
}



// Function: FUN_10010776 at 10010776

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10010776(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022f64,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100107b1 at 100107b1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100107b1(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022f74,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100107ec at 100107ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100107ec(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022f84,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10010827 at 10010827

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10010827(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10022f94,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10010862 at 10010862

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10010862(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



// Function: FUN_1001089a at 1001089a

undefined4 __thiscall FUN_1001089a(void *this,HWND param_1)

{
  int iVar1;
  LONG LVar2;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 8))();
  iVar1 = FUN_10003369((void *)((int)this + 0x14),iVar1,this);
  if ((iVar1 != 0) && (LVar2 = SetWindowLongW(param_1,-4,*(LONG *)((int)this + 0x14)), LVar2 != 0))
  {
    *(LONG *)((int)this + 0x20) = LVar2;
    *(HWND *)((int)this + 4) = param_1;
    return 1;
  }
  return 0;
}



// Function: FUN_100108da at 100108da

LONG __thiscall FUN_100108da(void *this,int param_1)

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



// Function: FUN_10010926 at 10010926

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10010926(int param_1)

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



// Function: FUN_10010983 at 10010983

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10010983(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  
  if (param_4 == 3) {
    lVar1 = (ulonglong)(uint)(param_2 - param_1 >> 2) * 4;
    uVar2 = FUN_10017151(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    *(undefined4 *)((int)this + 8) = uVar2;
    uVar2 = FUN_100109db();
    return uVar2;
  }
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  if (*(int **)((int)this + 4) != param_3) {
    FUN_100010fd((int *)((int)this + 4),param_3);
  }
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 8);
  *(int *)((int)this + 0x14) = param_4;
  return 0;
}



// Function: Catch@100109cb at 100109cb

undefined * Catch_100109cb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100109d5;
}



// Function: FUN_100109db at 100109db

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100109db(void)

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
      iVar3 = FUN_1000ff2d(*(int **)(unaff_ESI + 0x10),piVar4);
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
      FUN_100010fd((int *)(unaff_ESI + 4),*(int **)(unaff_EBP + 0x10));
    }
    *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 8);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_EBP + 0x14);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10010c0c at 10010c0c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_10010c0c(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10010c18;
  FUN_10010776(local_14,*(undefined4 **)((int)this + 0x60));
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



// Function: FUN_10010c6c at 10010c6c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10010c6c(void *this)

{
  undefined4 *puVar1;
  HWND pHVar2;
  BOOL BVar3;
  undefined4 *in_stack_00000010;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10010c78;
  *(uint *)((int)this + 0x98) = *(uint *)((int)this + 0x98) | 0x20;
  if ((*(uint *)((int)this + 0x98) & 0x40) == 0) {
    if ((*(int *)((int)this + 100) != 0) && ((*(uint *)((int)this + 0x98) & 2) == 0)) {
      local_14[0] = (int *)0x0;
      local_8 = 1;
                    /* WARNING: Load size is inaccurate */
      puVar1 = (undefined4 *)(**(code **)(*this + 0x10))();
      (**(code **)*puVar1)(puVar1,&DAT_10022f74,local_14);
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
      if (BVar3 != 0) goto LAB_10010d1b;
      pHVar2 = GetWindow(*(HWND *)((int)this + 4),5);
    }
    else {
      pHVar2 = *(HWND *)((int)this + 4);
    }
    SetFocus(pHVar2);
  }
LAB_10010d1b:
  *in_stack_00000010 = 0;
  return 0;
}



// Function: FUN_10010d2a at 10010d2a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10010d2a(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3,param_4,local_14,&PTR_100234f4,0,0)
  ;
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar1;
}



// Function: FUN_10010d7d at 10010d7d

undefined4 FUN_10010d7d(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0x54) != param_2) {
    FUN_100010fd((int *)(param_1 + 0x54),param_2);
  }
  return 0;
}



// Function: FUN_10010d9a at 10010d9a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_10010d9a(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                    (param_1,param_2,param_3,param_4,local_14,&PTR_100234f4,0,param_5);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar1;
}



// Function: FUN_10010dee at 10010dee

uint FUN_10010dee(uint param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
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



// Function: FUN_10010e2c at 10010e2c

undefined4 FUN_10010e2c(int param_1,int param_2)

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



// Function: FUN_10010e71 at 10010e71

uint FUN_10010e71(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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



// Function: FUN_10010ead at 10010ead

undefined4 FUN_10010ead(int param_1)

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



// Function: FUN_10010ec6 at 10010ec6

undefined4 FUN_10010ec6(int param_1)

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



// Function: FUN_10010edf at 10010edf

undefined4 FUN_10010edf(int param_1,int param_2)

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



// Function: FUN_10010f00 at 10010f00

undefined4 FUN_10010f00(int param_1,int param_2)

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



// Function: FUN_10010f21 at 10010f21

undefined4 FUN_10010f21(int param_1,int param_2)

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



// Function: FUN_10010f42 at 10010f42

undefined4 FUN_10010f42(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)

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



// Function: FUN_10010f74 at 10010f74

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10010f74(int param_1,undefined4 *param_2,GUID *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10010f80;
  piVar1 = *(int **)(param_1 + 0x34);
  local_14[0] = 1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)FUN_10003e90(&param_1,param_3);
    local_8 = 0;
    (**(code **)(*piVar1 + 0x40))
              (piVar1,*param_2,param_2[1],param_2[2],param_2[3],*puVar2,param_4,local_14);
    local_8 = 0xffffffff;
    Ordinal_6(param_1);
  }
  return local_14[0];
}



// Function: FUN_10010fd6 at 10010fd6

int FUN_10010fd6(int param_1,int *param_2,undefined4 param_3)

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
          bVar2 = FUN_1000242e(pvVar4,iVar5 + 1,*(LPCWSTR *)(param_1 + 0xa0));
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



// Function: FUN_10011079 at 10011079

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_10011079(int param_1,undefined4 param_2,int *param_3)

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
    goto LAB_100110f6;
  }
  *param_3 = 0;
  iVar6 = -0x7fffbfff;
  if (*(int *)(param_1 + 0x34) == 0) goto LAB_100110f6;
  param_3 = (int *)0x0;
  local_8 = 1;
  piStack_2c = *(int **)(param_1 + 0x34);
  ppiStack_24 = &param_3;
  uStack_28 = param_2;
  puVar7 = &uStack_30;
  uStack_30 = 0x100110c0;
  iVar6 = (**(code **)(*piStack_2c + 0x48))();
  piVar5 = param_3;
  if ((iVar6 < 0) || (param_3 == (int *)0x0)) {
LAB_100110e1:
    iVar6 = -0x7fffbfff;
  }
  else {
    puVar1 = (undefined4 *)*param_3;
    puVar7[-1] = piVar4;
    puVar7[-2] = &DAT_10022fd8;
    puVar7[-3] = piVar5;
    pcVar2 = (code *)*puVar1;
    puVar8 = puVar7 + -4;
    puVar7 = puVar7 + -4;
    *puVar8 = 0x100110d6;
    iVar6 = (*pcVar2)();
    if ((iVar6 < 0) || (*piVar4 == 0)) goto LAB_100110e1;
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    iVar3 = *param_3;
    *(int **)((int)puVar7 + -4) = param_3;
    pcVar2 = *(code **)(iVar3 + 8);
    puVar9 = (undefined4 *)((int)puVar7 + -8);
    puVar7 = (undefined4 *)((int)puVar7 + -8);
    *puVar9 = 0x100110f4;
    (*pcVar2)();
  }
LAB_100110f6:
  *(undefined4 *)((int)puVar7 + -4) = 0x100110fb;
  return iVar6;
}



// Function: FUN_100110fe at 100110fe

int FUN_100110fe(int param_1,int *param_2)

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
      iVar2 = FUN_1000fd93((void *)(param_1 + 0x30),param_2);
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



// Function: FUN_10011141 at 10011141

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10011141(void *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

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
LAB_1001118d:
    local_14 = (**(code **)(*cb + 0x50))(cb,param_2,param_3,&param_1);
    unaff_EDI = Ordinal_6_exref;
    Ordinal_6(param_3);
    if ((local_14 < 0) || (iVar1 = Ordinal_7(param_1), iVar1 == 0)) {
      local_14 = 1;
      goto LAB_10011220;
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
    if (param_3 != 0) goto LAB_1001118d;
    pvVar2 = (void *)FUN_10001000(0x8007000e);
  }
  FUN_10002493(pvVar2,(rsize_t)cb,param_1,(rsize_t)cb);
LAB_10011220:
  (*unaff_EDI)(param_1);
  return local_14;
}



// Function: FUN_10011234 at 10011234

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int * FUN_10011234(int *param_1,undefined4 param_2,int *param_3)

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
      uStack_30 = 0x10011276;
      param_3 = (int *)(**(code **)(*piStack_2c + 0x54))();
      if (param_1 != (int *)0x0) {
        puVar6[-1] = piVar5;
        piVar1 = piVar1 + -9;
        puVar2 = (undefined4 *)*piVar1;
        puVar6[-2] = &DAT_10022fe8;
        puVar6[-3] = piVar1;
        pcVar3 = (code *)*puVar2;
        puVar7 = puVar6 + -4;
        puVar6 = puVar6 + -4;
        *puVar7 = 0x1001128c;
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
        *puVar8 = 0x100112b0;
        (*pcVar3)();
      }
    }
  }
  *(undefined4 *)((int)puVar6 + -4) = 0x100112b8;
  return param_3;
}



// Function: FUN_100112bb at 100112bb

undefined4 FUN_100112bb(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 8) != param_2) {
    FUN_100010fd((int *)(param_1 + 8),param_2);
  }
  return 0;
}



// Function: FUN_100112d8 at 100112d8

int FUN_100112d8(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = FUN_1001074e(param_1,param_2);
  if ((-1 < iVar3) && (puVar1 = *(undefined4 **)(param_1 + 4), puVar1 != (undefined4 *)0x0)) {
    iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10022ff8,param_1 + 0xa4);
  }
  if ((param_2 == (int *)0x0) && (piVar2 = *(int **)(param_1 + 0xa4), piVar2 != (int *)0x0)) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return iVar3;
}



// Function: FUN_1001132e at 1001132e

void __thiscall FUN_1001132e(void *this,HWND param_1)

{
  int iVar1;
  
  iVar1 = FUN_1001089a(this,param_1);
  *(uint *)((int)this + 200) =
       *(uint *)((int)this + 200) ^ (iVar1 << 4 ^ *(uint *)((int)this + 200)) & 0x10;
  return;
}



// Function: FUN_10011353 at 10011353

void __fastcall FUN_10011353(void *param_1)

{
  uint *puVar1;
  LONG LVar2;
  
  puVar1 = (uint *)((int)param_1 + 200);
  if ((*(byte *)puVar1 & 0x10) == 0) {
    DestroyWindow(*(HWND *)((int)param_1 + 4));
  }
  else {
    LVar2 = FUN_100108da(param_1,1);
    if (LVar2 != 0) {
      *puVar1 = *puVar1 & 0xffffffef;
      return;
    }
  }
  return;
}



// Function: FUN_1001137a at 1001137a

LRESULT __thiscall
FUN_1001137a(void *this,uint param_1,uint param_2,HWND param_3,undefined4 *param_4)

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
      goto LAB_10011443;
      pHVar4 = (HWND)lParam[5].unused;
    }
    else if (param_1 == 0x2c) {
      if (param_3->unused == 1) goto LAB_10011443;
      nIDDlgItem = param_3[1].unused;
LAB_1001142e:
      pHVar4 = GetDlgItem(*(HWND *)((int)this + 4),nIDDlgItem);
    }
    else if (param_1 == 0x2d) {
      pHVar4 = (HWND)param_3[3].unused;
    }
    else {
      if (param_1 < 0x2e) goto LAB_10011443;
      if (0x2f < param_1) {
        if (param_1 != 0x39) goto LAB_10011443;
        pHVar4 = (HWND)param_3[2].unused;
      }
    }
  }
  else if (param_1 == 0x111) {
    if (param_3 == (HWND)0x0) goto LAB_10011443;
  }
  else {
    if (param_1 < 0x114) goto LAB_10011443;
    if (0x115 < param_1) {
      if (param_1 < 0x132) goto LAB_10011443;
      if (0x138 < param_1) {
        if (param_1 != 0x210) goto LAB_10011443;
        FUN_1001072a((int)this);
        if (1 < (param_2 & 0xffff) - 1) {
          nIDDlgItem = param_2 >> 0x10;
          goto LAB_1001142e;
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
LAB_10011443:
  *param_4 = 0;
  return 1;
}



// Function: FUN_10011530 at 10011530

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10011530(int *param_1,undefined4 param_2,undefined4 param_3)

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
    iVar2 = (**(code **)*piVar1)(piVar1,&DAT_10023008,local_14);
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



// Function: FUN_100115c1 at 100115c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100115c1(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10023018,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100115fc at 100115fc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100115fc(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10023028,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10011637 at 10011637

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10011637(int param_1)

{
  FUN_10010862(param_1);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10011661 at 10011661

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10011661(int param_1)

{
  FUN_10010926(param_1);
  return;
}



// Function: FUN_1001167f at 1001167f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1001167f(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000e21c(param_1);
  return;
}



// Function: FUN_100116bb at 100116bb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_100116bb(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_1000e24c(param_1);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return param_1;
}



// Function: FUN_100116f1 at 100116f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100116f1(int param_1)

{
  int *piVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x100116fd;
  if ((*(uint *)(param_1 + 0x98) & 0x40) == 0) {
    *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) | 0x40;
    piVar1 = *(int **)(param_1 + 0x70);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1,1,0,0);
    }
    if (*(int *)(param_1 + 0x94) != -0x32323233) {
      FUN_10011530(*(int **)(param_1 + 0x60),param_1 + 0x80,*(int *)(param_1 + 0x94));
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
                (*(undefined4 **)(param_1 + 0x60),&DAT_10023038,local_14);
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



// Function: FUN_10011843 at 10011843

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_10011843(void *this)

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
  local_8 = 0x1001184f;
  ppuVar7 = (undefined4 **)auStack_20;
  *in_stack_00000010 = 0;
  if ((*(uint *)((int)this + 0xa0) & 0x4000) == 0) {
    puStack_24 = &stack0x00000010;
    FUN_10010c6c(this);
    ppuVar7 = (undefined4 **)auStack_20;
  }
  else if ((*(int *)((int)this + 100) != 0) && ((*(byte *)((int)this + 0x98) & 1) == 0)) {
    in_stack_00000010 = (int *)0x0;
    local_8 = 1;
                    /* WARNING: Load size is inaccurate */
    ppuVar6 = &puStack_24;
    puStack_24 = (undefined4 *)0x1001187f;
    puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
    puVar1 = (undefined4 *)*puVar5;
    ppuVar6[-1] = &stack0x00000010;
    ppuVar6[-2] = (undefined4 *)&DAT_10022f74;
    ppuVar6[-3] = puVar5;
    pcVar2 = (code *)*puVar1;
    ppuVar7 = ppuVar6 + -4;
    ppuVar6[-4] = (undefined4 *)0x1001188d;
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
      *puVar8 = 0x100118ac;
      (*pcVar2)();
    }
    local_8 = 0xffffffff;
    if (in_stack_00000010 != (int *)0x0) {
      iVar4 = *in_stack_00000010;
      *(int **)((int)ppuVar7 + -4) = in_stack_00000010;
      pcVar2 = *(code **)(iVar4 + 8);
      puVar9 = (undefined4 *)((int)ppuVar7 + -8);
      ppuVar7 = (undefined4 **)((int)ppuVar7 + -8);
      *puVar9 = 0x100118bd;
      (*pcVar2)();
    }
  }
  *(undefined4 *)((int)ppuVar7 + -4) = 0x100118d2;
  return 0;
}



// Function: FUN_100118d5 at 100118d5

undefined4 __thiscall
FUN_100118d5(void *this,UINT param_1,WPARAM param_2,LPARAM param_3,undefined4 *param_4)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = (int *)(**(code **)(*this + 0x10))();
  (**(code **)(*piVar1 + 4))(piVar1);
  CallWindowProcW(*(WNDPROC *)((int)this + 0x20),*(HWND *)((int)this + 4),param_1,param_2,param_3);
  FUN_100116f1((int)this);
  *param_4 = 0;
  return 0;
}



// Function: FUN_1001190f at 1001190f

undefined4 FUN_1001190f(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0x58) != param_2) {
    FUN_100010fd((int *)(param_1 + 0x58),param_2);
  }
  return 0;
}



// Function: FUN_1001192c at 1001192c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1001192c(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x10011938;
  uVar1 = 0;
  FUN_100115c1(local_14,*(undefined4 **)((int)this + 0x60));
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



// Function: FUN_10011975 at 10011975

undefined4 FUN_10011975(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x80) = param_2;
  FUN_1001192c((void *)(param_1 + -0x4c),0xfffffd43);
  (**(code **)(*(int *)(param_1 + -0x20) + 100))((int *)(param_1 + -0x20),0,0);
  return 0;
}



// Function: FUN_100119a6 at 100119a6

undefined4 FUN_100119a6(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x84) = param_2;
  FUN_1001192c((void *)(param_1 + -0x4c),0xfffffd40);
  return 0;
}



// Function: FUN_100119c8 at 100119c8

undefined4 FUN_100119c8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x88) = param_2;
  FUN_1001192c((void *)(param_1 + -0x4c),0xfffffd3f);
  return 0;
}



// Function: FUN_100119ea at 100119ea

undefined4 FUN_100119ea(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ (param_2 * 2 ^ *(uint *)(param_1 + 0x7c)) & 2;
  FUN_1001192c((void *)(param_1 + -0x4c),0xfffffd3b);
  return 0;
}



// Function: FUN_10011a12 at 10011a12

undefined4 FUN_10011a12(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 2 ^ *(uint *)(param_1 + 0x7c)) & 4;
  FUN_1001192c((void *)(param_1 + -0x4c),0xfffffd37);
  return 0;
}



// Function: FUN_10011a3b at 10011a3b

undefined4 FUN_10011a3b(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0x8c) != param_2) {
    FUN_100010fd((int *)(param_1 + 0x8c),param_2);
  }
  FUN_1001192c((void *)(param_1 + -0x4c),0xfffffd41);
  return 0;
}



// Function: FUN_10011a6a at 10011a6a

undefined4 FUN_10011a6a(int param_1,short param_2)

{
  *(uint *)(param_1 + 0x7c) =
       *(uint *)(param_1 + 0x7c) ^ ((int)param_2 << 3 ^ *(uint *)(param_1 + 0x7c)) & 8;
  FUN_1001192c((void *)(param_1 + -0x4c),0xfffffd3e);
  return 0;
}



// Function: FUN_10011a93 at 10011a93

undefined4 FUN_10011a93(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x94) = param_2;
  FUN_1001192c((void *)(param_1 + -0x4c),0xffffffff);
  return 0;
}



// Function: FUN_10011ab2 at 10011ab2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10011ab2(void *this,int *param_1,int *param_2,int param_3)

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
  local_8 = 0x10011abe;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)((int)this + 0x60);
  if ((int *)*piVar1 != param_1) {
    FUN_100010fd(piVar1,param_1);
  }
  local_14 = 0;
  piVar7 = (int *)((int)this + 100);
  (**(code **)*param_1)(param_1,&DAT_10023084,piVar7);
  piVar3 = (int *)*piVar7;
  if (piVar3 != (int *)0x0) {
    puVar2 = (uint *)((int)this + 0xa0);
    (**(code **)(*piVar3 + 0x58))(piVar3,1,puVar2);
    if ((*puVar2 & 0x20000) != 0) {
                    /* WARNING: Load size is inaccurate */
      puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
      FUN_100107b1(&local_20,puVar5);
      local_8 = 0;
      (**(code **)(*(int *)*piVar7 + 0xc))((int *)*piVar7,local_20);
      local_8 = 0xffffffff;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
    }
    if ((char)param_2 == '\0') {
      FUN_100107ec(&param_2,(undefined4 *)*piVar7);
      local_8 = 3;
      if (param_2 == (int *)0x0) {
        if (param_3 != 0) {
          FUN_10010827(&local_20,(undefined4 *)*piVar7);
          local_8._0_1_ = 4;
          if (local_20 != (int *)0x0) {
            local_14 = (**(code **)(*local_20 + 0x14))(local_20,param_3);
          }
          local_8 = CONCAT31(local_8._1_3_,3);
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          goto LAB_10011bb6;
        }
      }
      else {
        if (param_3 == 0) {
          local_14 = (**(code **)(*param_2 + 0x20))(param_2);
        }
        else {
          local_14 = (**(code **)(*param_2 + 0x14))(param_2,param_3);
        }
LAB_10011bb6:
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
          goto LAB_10011e3c;
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
      FUN_100107b1(&param_2,puVar5);
      local_8 = 0xb;
      (**(code **)(*(int *)*piVar7 + 0xc))((int *)*piVar7,param_2);
      local_8 = 0xffffffff;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    *(undefined4 *)((int)this + 0x90) = 0;
    piVar1 = (int *)((int)this + 0x70);
    local_14 = (*(code *)**(undefined4 **)*piVar7)((undefined4 *)*piVar7,&DAT_10023074,piVar1);
    if (local_14 < 0) {
      local_14 = (*(code *)**(undefined4 **)*piVar7)((undefined4 *)*piVar7,&DAT_10023064,piVar1);
      if (local_14 < 0) {
        local_14 = (*(code *)**(undefined4 **)*piVar7)((undefined4 *)*piVar7,&DAT_10023054,piVar1);
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
    FUN_100115fc(&local_18,puVar5);
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
      FUN_1000fd1e((int *)((int)this + 0xac),(int *)((int)this + 0xa4));
      (**(code **)(*(int *)*piVar7 + 0x44))((int *)*piVar7,1,(int)this + 0xa4);
      (**(code **)(*(int *)*piVar7 + 0x48))((int *)*piVar7,1,(int)this + 0xa4);
      FUN_1000fca9((int *)((int)this + 0xa4),(int *)((int)this + 0xac));
      *(LONG *)((int)this + 0xbc) = lpRect->left + *(int *)((int)this + 0xac);
      *(int *)((int)this + 0xc0) = *(int *)((int)this + 0xb0) + *(int *)((int)this + 0xb8);
                    /* WARNING: Load size is inaccurate */
      puVar5 = (undefined4 *)(**(code **)(*this + 0x10))();
      FUN_100107b1(&param_2,puVar5);
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
  (**(code **)*param_1)(param_1,&DAT_10023038,&local_1c);
  piVar1 = local_1c;
  piVar7 = local_1c;
  if (local_1c != (int *)0x0) {
    iVar4 = *local_1c;
                    /* WARNING: Load size is inaccurate */
    uVar6 = (**(code **)(*this + 0x10))();
    (**(code **)(iVar4 + 0xc))(piVar1,uVar6);
    piVar7 = local_1c;
  }
LAB_10011e3c:
  local_8 = 0xffffffff;
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 8))(piVar7);
  }
  return local_14;
}



// Function: FUN_10011e4f at 10011e4f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10011e4f(undefined4 *param_1)

{
  FUN_10011637((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumUnknown,&struct___s_GUID_const__GUID_00000100_0000_0000_c000_000000000046,struct_IUnknown*,class_ATL::_CopyInterface<struct_IUnknown>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_1002f1c0 + 4))();
  return param_1;
}



// Function: FUN_10011e88 at 10011e88

undefined4 FUN_10011e88(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: Release at 10011e98

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



// Function: FUN_10011eb9 at 10011eb9

undefined4 FUN_10011eb9(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// Function: FUN_10011ecb at 10011ecb

bool FUN_10011ecb(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 4;
  return param_2 != uVar1;
}



// Function: FUN_10011ef8 at 10011ef8

uint FUN_10011ef8(int param_1,uint param_2,int *param_3,uint *param_4)

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
      uVar2 = FUN_1000ff2d(piVar3,*(int **)(param_1 + 0x10));
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



// Function: QueryInterface at 10011fb6

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100230b8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10011fd0 at 10011fd0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10011fd0(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumUnknown,&struct___s_GUID_const__GUID_00000100_0000_0000_c000_000000000046,struct_IUnknown*,class_ATL::_CopyInterface<struct_IUnknown>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_1002f1c0 + 8))();
  FUN_10010926((int)param_1);
  return;
}



// Function: FUN_1001200e at 1001200e

undefined4 * __thiscall FUN_1001200e(void *this,byte param_1)

{
  FUN_10011fd0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001202d at 1001202d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1001202d(void *this,byte param_1)

{
  FUN_1000ea53((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1001205e at 1001205e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1001205e(undefined4 *param_1)

{
  FUN_100116bb((int)param_1);
  *param_1 = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  (**(code **)(*DAT_1002f1c0 + 4))();
  return param_1;
}



// Function: FUN_1001209e at 1001209e

undefined4 FUN_1001209e(void)

{
  return 0;
}



// Function: FUN_100120a3 at 100120a3

undefined4 FUN_100120a3(void)

{
  return 0x800401a1;
}



// Function: FUN_100120ab at 100120ab

undefined4 FUN_100120ab(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_100120bb at 100120bb

void FUN_100120bb(int param_1,_GUID *param_2,void **param_3)

{
  ATL::AtlInternalQueryInterface
            ((void *)(param_1 + -0x24),(_ATL_INTMAP_ENTRY *)&PTR_DAT_1002311c,param_2,param_3);
  return;
}



// Function: FUN_100120d9 at 100120d9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100120d9(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxUIWindow>::vftable;
  param_1[10] = 0xc0000001;
  FUN_10012f83((int)param_1);
  (**(code **)(*DAT_1002f1c0 + 8))();
  FUN_1001167f((int)param_1);
  return;
}



// Function: FUN_10012123 at 10012123

undefined4 * __thiscall FUN_10012123(void *this,byte param_1)

{
  FUN_100120d9((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10012142 at 10012142

undefined4 FUN_10012142(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 8) != param_2) {
    FUN_100010fd((int *)(param_1 + 8),param_2);
  }
  return 0;
}



// Function: FUN_1001215f at 1001215f

ATOM FUN_1001215f(int param_1,WNDCLASSEXW *param_2)

{
  ATOM AVar1;
  
  if ((param_1 == 0) || (param_2 == (WNDCLASSEXW *)0x0)) {
    AVar1 = 0;
  }
  else {
    AVar1 = RegisterClassExW(param_2);
    param_2 = (WNDCLASSEXW *)(uint)AVar1;
    if (AVar1 != 0) {
      FUN_1000e80f((void *)(param_1 + 0x20),(undefined2 *)&param_2);
    }
  }
  return AVar1;
}



// Function: FUN_1001219e at 1001219e

void FUN_1001219e(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *dwNewLong;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_100060b5(0x1003139c);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)param_1;
    iVar2 = (**(code **)(*piVar1 + 8))();
    FUN_10003369(piVar1 + 5,iVar2,piVar1);
    dwNewLong = (code *)piVar1[5];
    SetWindowLongW(param_1,-4,(LONG)dwNewLong);
    (*dwNewLong)(param_1,param_2,param_3,param_4);
  }
  return;
}



// Function: FUN_100121eb at 100121eb

HWND __thiscall
FUN_100121eb(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,ushort param_7,LPVOID param_8)

{
  int iVar1;
  HWND pHVar2;
  
  iVar1 = FUN_10003369((void *)((int)this + 0x14),0,0);
  if (iVar1 == 0) {
    SetLastError(0xe);
  }
  else if (param_7 != 0) {
    FUN_1000603f(0x1003139c,(DWORD *)((int)this + 8),(DWORD *)this);
    if ((param_6 == (HMENU)0x0) && ((param_4 & 0x40000000) != 0)) {
      param_6 = (HMENU)this;
    }
    if (param_2 == (int *)0x0) {
      param_2 = &DAT_1002d000;
    }
    pHVar2 = CreateWindowExW(param_5,(LPCWSTR)(uint)param_7,param_3,param_4,*param_2,param_2[1],
                             param_2[2] - *param_2,param_2[3] - param_2[1],param_1,param_6,
                             DAT_10031340,param_8);
    return pHVar2;
  }
  return (HWND)0x0;
}



// Function: FUN_1001227f at 1001227f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1001227f(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10011e4f(puVar1);
    }
    uVar2 = FUN_100122da();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100122cb at 100122cb

undefined * Catch_100122cb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100122d5;
}



// Function: FUN_100122da at 100122da

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100122da(void)

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



// Function: FUN_100122f1 at 100122f1

undefined4 __thiscall
FUN_100122f1(void *this,undefined4 param_1,uint param_2,uint param_3,HWND param_4,LRESULT *param_5,
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
joined_r0x1001234e:
      if (iVar1 != 0) {
        return 1;
      }
    }
    else {
      if (param_2 == 0xf) {
        param_6 = 1;
        LVar4 = FUN_100101d1(this);
LAB_10012348:
        *pLVar2 = LVar4;
        iVar1 = param_6;
        goto joined_r0x1001234e;
      }
      if (param_2 == 5) {
        param_6 = 1;
        LVar4 = FUN_100100b9(this,5,param_3,param_4,&param_6);
        goto LAB_10012348;
      }
      if (param_2 == 0x21) {
        param_6 = 1;
        LVar4 = FUN_10011843(this);
        goto LAB_10012348;
      }
      if (param_2 == 7) {
        param_6 = 1;
        LVar4 = FUN_10010c6c(this);
        goto LAB_10012348;
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
        if (piVar5 == (int *)0x0) goto LAB_100123f1;
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
          if (param_2 != 0x209) goto LAB_100123f1;
          uVar3 = 0x209;
        }
        param_6 = 1;
        LVar4 = FUN_10010194(this,uVar3,param_3,param_4,&param_6);
        *pLVar2 = LVar4;
        if (param_6 != 0) {
          return 1;
        }
      }
    }
LAB_100123f1:
    if ((*(uint *)((int)this + 0x98) >> 2 & *(uint *)((int)this + 0x98) & 8) == 0) {
LAB_10012660:
      if (param_2 == 2) {
        param_6 = 1;
        LVar4 = FUN_100118d5(this,2,param_3,(LPARAM)param_4,&param_6);
        goto LAB_10012429;
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
          LVar4 = FUN_10010152(this,0x286,param_3,param_4,&param_6);
          *pLVar2 = LVar4;
          if (param_6 != 0) {
            return 1;
          }
        }
        else {
          if (param_2 == 0x209) goto LAB_1001241f;
          if ((param_2 < 0x281) || (0x291 < param_2)) goto LAB_10012660;
        }
        param_6 = 1;
        LVar4 = FUN_10010152(this,param_2,param_3,param_4,&param_6);
        *pLVar2 = LVar4;
        if (param_6 != 0) {
          return 1;
        }
        goto LAB_10012660;
      }
LAB_1001241f:
      param_6 = 1;
      LVar4 = FUN_10010152(this,uVar7,param_3,param_4,&param_6);
LAB_10012429:
      *pLVar2 = LVar4;
      if (param_6 != 0) {
        return 1;
      }
    }
    if ((*(byte *)((int)this + 200) & 8) != 0) {
      param_6 = 1;
      LVar4 = FUN_1001137a(this,param_2,param_3,param_4,&param_6);
      *pLVar2 = LVar4;
      if (param_6 != 0) {
        return 1;
      }
    }
    if (param_2 == DAT_1002f1b8) {
                    /* WARNING: Load size is inaccurate */
      piVar5 = (int *)(**(code **)(*this + 0x10))();
LAB_1001247c:
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    else {
      if (param_2 != DAT_1002f1bc) {
        if (param_2 == 0x37f) {
          LVar4 = FUN_10010c0c(this,0x37f,param_3,param_4);
          *pLVar2 = LVar4;
          return 1;
        }
        goto LAB_100126bd;
      }
      piVar5 = *(int **)((int)this + 0x60);
      if (piVar5 != (int *)0x0) goto LAB_1001247c;
    }
    *pLVar2 = (LRESULT)piVar5;
  }
  else {
LAB_100126bd:
    uVar6 = 0;
  }
  return uVar6;
}



// Function: FUN_100126c6 at 100126c6

int FUN_100126c6(int param_1,int *param_2,HWND param_3)

{
  void *this;
  HWND hWnd;
  BOOL BVar1;
  bool bVar2;
  undefined4 local_8;
  
  this = (void *)(param_1 + -0x24);
  local_8 = 1;
  FUN_100116f1((int)this);
  hWnd = *(HWND *)(param_1 + -0x20);
  if ((hWnd != (HWND)0x0) && (hWnd != param_3)) {
    RedrawWindow(hWnd,(RECT *)0x0,(HRGN)0x0,0x507);
    FUN_10011353(this);
  }
  BVar1 = IsWindow(param_3);
  if (BVar1 != 0) {
    bVar2 = *(HWND *)(param_1 + -0x20) != param_3;
    if (bVar2) {
      FUN_1001132e(this,param_3);
    }
    local_8 = FUN_10011ab2(this,param_2,(int *)0x1,0);
    if (local_8 < 0) {
      FUN_100116f1((int)this);
      if (*(HWND *)(param_1 + -0x20) != (HWND)0x0) {
        RedrawWindow(*(HWND *)(param_1 + -0x20),(RECT *)0x0,(HRGN)0x0,0x507);
        if (bVar2) {
          FUN_10011353(this);
        }
      }
    }
  }
  return local_8;
}



// Function: FUN_10012b1f at 10012b1f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10012b1f(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10011e4f(puVar1);
    }
    iVar2 = FUN_10012b76();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10012b69 at 10012b69

undefined * Catch_10012b69(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10012b73;
}



// Function: FUN_10012b76 at 10012b76

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10012b76(void)

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
    iVar1 = FUN_10010983(unaff_ESI,unaff_EBP + -0x18,unaff_EBP + -0x14,piVar2,iVar1);
    if ((iVar1 < 0) || (iVar1 = (**(code **)*unaff_ESI)(), iVar1 < 0)) {
      (**(code **)(*unaff_ESI + 0x1c))(1);
    }
  }
  return iVar1;
}



// Function: FUN_10012bd0 at 10012bd0

undefined4 FUN_10012bd0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000872c(&PTR_DAT_1002ee1c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10012bf4 at 10012bf4

void FUN_10012bf4(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000876c(&PTR_DAT_1002ee1c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10012c14 at 10012c14

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10012c14(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x30);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1001205e(puVar1);
    }
    uVar2 = FUN_10012c6f();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10012c60 at 10012c60

undefined * Catch_10012c60(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10012c6a;
}



// Function: FUN_10012c6f at 10012c6f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10012c6f(void)

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



// Function: FUN_10012c86 at 10012c86

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10012c86(int *param_1,void **param_2)

{
  int *piVar1;
  int *local_1c;
  int local_18;
  uint local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xc;
  local_8 = 0x10012c92;
  local_14 = 0;
  local_18 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    local_18 = FUN_1001227f(&local_1c);
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
      local_18 = FUN_10010983(local_1c,piVar1[2],piVar1[3],param_1,0);
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
                             (local_1c,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100230b8,(_GUID *)&DAT_100230d0
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



// Function: FUN_10012d99 at 10012d99

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 __cdecl FUN_10012d99(int param_1,int param_2,WNDCLASSEXW *param_3,UINT *param_4)

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
LAB_10012e48:
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
              goto LAB_10012e48;
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
          AVar2 = FUN_1001215f(param_2,param_3);
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



// Function: FUN_10012f10 at 10012f10

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10012f10(undefined4 *param_1)

{
  FUN_100116bb((int)param_1);
  *param_1 = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  (**(code **)(*DAT_1002f1c0 + 4))();
  return param_1;
}



// Function: FUN_10012f50 at 10012f50

undefined4 FUN_10012f50(void)

{
  return 0;
}



// Function: FUN_10012f55 at 10012f55

undefined4 FUN_10012f55(void)

{
  return 0;
}



// Function: FUN_10012f5a at 10012f5a

undefined4 FUN_10012f5a(void)

{
  return 0;
}



// Function: FUN_10012f5f at 10012f5f

undefined4 FUN_10012f5f(int param_1)

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



// Function: FUN_10012f83 at 10012f83

void __fastcall FUN_10012f83(int param_1)

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



// Function: FUN_10012fa7 at 10012fa7

void FUN_10012fa7(int param_1,_GUID *param_2,void **param_3)

{
  ATL::AtlInternalQueryInterface
            ((void *)(param_1 + -0x24),(_ATL_INTMAP_ENTRY *)&PTR_DAT_100231e4,param_2,param_3);
  return;
}



// Function: FUN_10012fc5 at 10012fc5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10012fc5(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[9] = ATL::CComObject<class_ATL::CAxFrameWindow>::vftable;
  param_1[10] = 0xc0000001;
  FUN_10012f83((int)param_1);
  (**(code **)(*DAT_1002f1c0 + 8))();
  FUN_1001167f((int)param_1);
  return;
}



// Function: FUN_1001300f at 1001300f

undefined4 * __thiscall FUN_1001300f(void *this,byte param_1)

{
  FUN_10012fc5((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001302e at 1001302e

void FUN_1001302e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_1000880d(&PTR_DAT_1002ee1c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                       param_8,param_9);
  if (((iVar2 == -0x7ffdfffd) || (iVar2 == -0x7ffd7fd5)) &&
     (piVar1 = *(int **)(param_1 + 8), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x18))
                      (piVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    if ((-1 < iVar2) && ((param_5 & 4) != 0)) {
      FUN_1001192c((void *)(param_1 + -0x4c),param_2);
    }
  }
  return;
}



// Function: FUN_100130a5 at 100130a5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100130a5(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x30);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10012f10(puVar1);
    }
    uVar2 = FUN_10013100();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100130f1 at 100130f1

undefined * Catch_100130f1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100130fb;
}



// Function: FUN_10013100 at 10013100

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10013100(void)

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



// Function: FUN_10013117 at 10013117

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10013117(int *param_1)

{
  FUN_100083ff(param_1);
  operator_delete((void *)*param_1);
  return;
}



// Function: FUN_10013143 at 10013143

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10013143(void *this,void *param_1)

{
  int iVar1;
  int *piVar2;
  int local_74;
  wchar_t *local_70;
  undefined4 local_6c [7];
  wchar_t local_50 [14];
  wchar_t local_34 [6];
  CLSID local_28 [2];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0;
  iVar1 = __RTDynamicCast(this,0,&CContextSensitiveHelpProvider<class_CFSTRErrorDlg>::
                                  RTTI_Type_Descriptor,&CFSTRErrorDlg::RTTI_Type_Descriptor,0);
  CLSIDFromString(*(LPCOLESTR *)(iVar1 + 0x38),local_28);
  FUN_10003e90(&local_70,local_28);
  local_8._0_1_ = 1;
  FUN_10016152((undefined2 *)local_6c,local_70);
  local_8._0_1_ = 2;
  FUN_10001d86(local_50,L"");
  local_8._0_1_ = 3;
  FUN_10001d86(local_34,L"{");
  local_8._0_1_ = 4;
  FUN_100160ce(local_6c,local_34,local_50);
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_50,'\x01',0);
  FUN_10001d86(local_34,L"");
  local_8._0_1_ = 5;
  FUN_10001d86(local_50,L"}");
  local_8._0_1_ = 6;
  FUN_100160ce(local_6c,local_50,local_34);
  local_8._0_1_ = 5;
  FID_conflict__Tidy(local_50,'\x01',0);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_34,'\x01',0);
  piVar2 = FUN_10015f82(&local_74,local_6c);
  local_8._0_1_ = 7;
  FUN_10002f81(param_1,piVar2);
  local_8._0_1_ = 2;
  Ordinal_6(local_74);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_70);
  local_8 = 0xffffffff;
  FUN_10017306();
  return;
}



// Function: Catch@10013294 at 10013294

undefined4 Catch_10013294(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001328a;
}



// Function: FUN_1001329e at 1001329e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_1001329e(void *this,HWND param_1,int param_2,int param_3,int param_4,int param_5,HWND param_6,
            HWND param_7)

{
  HWND hWnd;
  int iVar1;
  LPWSTR lpClassName;
  int iVar2;
  tagPOINT local_84;
  tagPOINT local_7c;
  tagPOINT local_74;
  HWND local_6c;
  HWND local_68;
  HWND local_64;
  HWND local_60;
  undefined4 local_5c;
  LPWSTR local_58;
  tagRECT local_54;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0x100132aa;
  local_6c = param_1;
  local_68 = param_6;
  local_64 = param_7;
  iVar1 = __RTDynamicCast(this,0,&CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::
                                  RTTI_Type_Descriptor,
                          &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar1 + 8);
  local_5c = 0;
  local_58 = (LPWSTR)PTR_DAT_1002d14c;
  local_8 = 0;
  local_60 = hWnd;
  lpClassName = (LPWSTR)FUN_1000e6ad(&local_58,0x104);
  if (lpClassName != (LPWSTR)0x0) {
    local_58[-0xffffffff00000004] = L'Ą';
    local_58[-0xffffffff00000003] = L'\0';
    local_58[0x104] = L'\0';
    lpClassName = local_58;
  }
  GetClassNameW(local_6c,lpClassName,0x104);
  FUN_1000ed87(&local_58,-1);
  FUN_1000e712((int *)&local_58);
  CharUpperW(local_58);
  iVar1 = wcscmp(local_58,L"LISTBOX");
  if (iVar1 == 0) {
    local_5c = 1;
  }
  local_34.left = 0;
  local_34.top = 0;
  local_34.right = 0;
  local_34.bottom = 0;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  GetClientRect(hWnd,&local_34);
  GetWindowRect(local_6c,&local_24);
  local_7c.x = local_24.right;
  local_7c.y = local_24.top;
  local_84.x = local_24.left;
  local_84.y = local_24.bottom;
  ScreenToClient(hWnd,&local_7c);
  ScreenToClient(local_60,&local_84);
  local_24.right = local_7c.x;
  local_24.top = local_7c.y;
  local_24.left = local_84.x;
  local_24.bottom = local_84.y;
  if ((param_4 == DAT_1002e554) && (param_5 == DAT_1002e558)) {
    param_4 = param_2;
    param_5 = param_3;
  }
  if (local_68 == (HWND)0x0) {
    local_44.right = local_84.x - ((local_34.right - local_34.left) * param_2) / 100;
    local_44.bottom = local_7c.y - ((local_34.bottom - local_34.top) * param_3) / 100;
  }
  else {
    local_44.left = 0;
    local_44.top = 0;
    local_44.right = 0;
    local_44.bottom = 0;
    GetWindowRect(local_68,&local_44);
    local_74.x = local_44.left;
    local_74.y = local_44.top;
    ScreenToClient(local_60,&local_74);
    local_44.bottom = 0;
    local_44.right = local_74.x;
  }
  if (local_64 == (HWND)0x0) {
    iVar1 = local_24.bottom - ((local_34.bottom - local_34.top) * param_5) / 100;
    iVar2 = local_24.right - ((local_34.right - local_34.left) * param_4) / 100;
  }
  else {
    local_54.left = 0;
    local_54.top = 0;
    local_54.right = 0;
    local_54.bottom = 0;
    GetWindowRect(local_64,&local_54);
    local_74.x = local_54.right;
    local_74.y = local_54.bottom;
    ScreenToClient(local_60,&local_74);
    iVar1 = 0;
    iVar2 = 0;
  }
  local_60 = (HWND)operator_new(0x34);
  local_8._0_1_ = 1;
  if (local_60 == (HWND)0x0) {
    local_5c = 0;
  }
  else {
    local_5c = FUN_1000df00(local_60,local_6c,param_2,param_3,local_44.right,local_44.bottom,param_4
                            ,param_5,iVar2,iVar1,local_5c,0,local_68,local_64);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000ef4a((int *)((int)this + 0x5c),*(int *)((int)this + 0x5c),&local_5c);
  local_8 = 0xffffffff;
  FUN_1000e0ba((int *)&local_58);
  FUN_100172f7();
  return;
}



// Function: FUN_10013521 at 10013521

void __thiscall FUN_10013521(void *this,UINT *param_1)

{
  FUN_10012d99(0x1003133c,0x1003139c,(WNDCLASSEXW *)this,param_1);
  return;
}



// Function: FUN_10013541 at 10013541

int FUN_10013541(int param_1,int *param_2,int *param_3,LPRECT param_4,LPRECT param_5,
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
      iVar3 = FUN_100130a5(&param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      (*(code *)**(undefined4 **)(param_1 + 0x24))
                ((undefined4 *)(param_1 + 0x24),&DAT_10023214,piVar4);
    }
    this = (int *)(iVar1 + 0x40);
    if (*this == 0) {
      iVar3 = FUN_10012c14(&param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      (*(code *)**(undefined4 **)(param_1 + 0x24))
                ((undefined4 *)(param_1 + 0x24),&DAT_10023140,this);
    }
    piVar4 = (int *)FUN_1000fd93((void *)(iVar1 + 0x3c),param_2);
    if ((-1 < (int)piVar4) &&
       (param_2 = (int *)FUN_1000fd93(this,param_3), piVar4 = param_2, -1 < (int)param_2)) {
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



// Function: FUN_1001367e at 1001367e

undefined4 __thiscall
FUN_1001367e(void *this,undefined4 param_1,int param_2,int param_3,undefined4 param_4,
            undefined4 *param_5,int param_6)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int local_8;
  
  local_8 = 1;
  if (param_6 != 0) {
    return 0;
  }
  if (param_2 == 0x110) {
    local_8 = 1;
    uVar2 = FUN_10001f5e(this);
  }
  else {
    if (param_2 != 0x111) goto LAB_10013749;
    sVar1 = (short)((uint)param_3 >> 0x10);
    if ((short)param_3 == 9) {
      if (sVar1 != 0) goto LAB_10013749;
      local_8 = 1;
      uVar2 = FUN_100012a9(this);
    }
    else if ((short)param_3 == 1) {
      if (sVar1 != 0) goto LAB_10013749;
      local_8 = 1;
      uVar2 = FUN_1000161c(this,0,1);
    }
    else {
      if (param_3 != 2) goto LAB_10013749;
      local_8 = 1;
      uVar2 = FUN_1000161c(this,0,2);
    }
  }
  *param_5 = uVar2;
  if (local_8 != 0) {
    return 1;
  }
LAB_10013749:
  iVar3 = FUN_1000f578(param_1,param_2,param_3,param_4,param_5,0);
  if (iVar3 != 0) {
    return 1;
  }
  if (param_2 == 0x53) {
    local_8 = 1;
    uVar2 = (**(code **)(*(int *)((int)this + 0x28) + 4))(0x53,param_3,param_4,&local_8);
    *param_5 = uVar2;
    if (local_8 != 0) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_1001379b at 1001379b

void __thiscall
FUN_1001379b(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  ushort uVar1;
  
  if (DAT_1002efd8 == 0) {
    DAT_1002efd8 = 0;
  }
  uVar1 = FUN_10013521(&DAT_1002efa8,(UINT *)((int)this + 0x20));
  if (param_4 == 0) {
    param_4 = 0x56000000;
  }
  if (param_3 == (LPCWSTR)0x0) {
    param_3 = (LPCWSTR)0x0;
  }
  FUN_100121eb(this,param_1,param_2,param_3,param_4,param_5,param_6,uVar1,param_7);
  return;
}



// Function: FUN_100137fa at 100137fa

void __thiscall
FUN_100137fa(void *this,HWND param_1,int *param_2,LPCWSTR param_3,uint param_4,DWORD param_5,
            HMENU param_6,LPVOID param_7)

{
  ushort uVar1;
  
  if (DAT_1002ee68 == 0) {
    DAT_1002ee68 = 0;
  }
  uVar1 = FUN_10013521(&DAT_1002ee38,(UINT *)((int)this + 0x20));
  if (param_4 == 0) {
    param_4 = 0x56000000;
  }
  if (param_3 == (LPCWSTR)0x0) {
    param_3 = (LPCWSTR)0x0;
  }
  FUN_100121eb(this,param_1,param_2,param_3,param_4,param_5,param_6,uVar1,param_7);
  return;
}



// Function: FUN_10013859 at 10013859

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10013859(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComPolyObject<class_ATL::CAxHostWindow>::vftable;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)this;
  }
  FUN_1000f5a8((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_1002f1c0 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_100138a3 at 100138a3

long FUN_100138a3(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10023248,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_100138ef at 100138ef

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100138ef(undefined4 *param_1)

{
  *param_1 = ATL::CComPolyObject<class_ATL::CAxHostWindow>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100116f1((int)(param_1 + 2));
  (**(code **)(*DAT_1002f1c0 + 8))();
  FUN_1000ea53((int)(param_1 + 2));
  return;
}



// Function: FUN_1001393c at 1001393c

undefined4 * __thiscall FUN_1001393c(void *this,byte param_1)

{
  FUN_100138ef((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001395b at 1001395b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1001395b(void *this,void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_18 [4];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_18[0] = 0;
  local_8 = 2;
  puVar1 = (undefined4 *)((int)this + 0x10);
  iVar2 = Ordinal_7(*puVar1);
  if (iVar2 == 0) {
    FUN_10013143(this,puVar1);
  }
  FUN_10002fc6(param_1,*puVar1);
                    /* WARNING: Load size is inaccurate */
  uVar3 = (**(code **)(*this + 0x10))(local_18);
  iVar2 = Ordinal_7(local_18[0]);
  if (iVar2 != 0) {
    uVar4 = lstrlenW(L"-");
    FUN_10003ee7(param_1,&DAT_10022440,uVar4);
    FUN_10002fc6(param_1,local_18[0]);
  }
  local_8._0_1_ = 1;
  Ordinal_6(local_18[0]);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  return uVar3;
}



// Function: Catch@10013a03 at 10013a03

undefined4 Catch_10013a03(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100139f8;
}



// Function: FUN_10013a0d at 10013a0d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10013a0d(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  FUN_1000ef22(param_1 + 0x17);
  param_1[5] = 1;
  param_1[2] = 1;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = 1;
  param_1[8] = 0;
  iVar1 = GetSystemMetrics(0x14);
  iVar2 = GetSystemMetrics(2);
  param_1[0x15] = iVar2;
  param_1[0x16] = iVar1;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_10013a72 at 10013a72

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10013a72(undefined4 *param_1)

{
  *param_1 = CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::vftable;
  FUN_1000ad75((int)param_1);
  FUN_10013117(param_1 + 0x17);
  return;
}



// Function: FUN_10013aa4 at 10013aa4

void __thiscall
FUN_10013aa4(void *this,HWND param_1,HWND param_2,int param_3,int param_4,HWND param_5,int param_6,
            int param_7)

{
  HWND hDlg;
  HWND pHVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  HWND pHVar5;
  HWND local_1c;
  int local_18;
  HWND local_c;
  HWND local_8;
  
  local_1c = (HWND)0x0;
  local_18 = 0;
  local_c = (HWND)0x0;
  local_8 = (HWND)0x0;
  iVar3 = __RTDynamicCast(this,0,&CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::
                                  RTTI_Type_Descriptor,
                          &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  iVar2 = DAT_1002e558;
  pHVar1 = DAT_1002e554;
  hDlg = *(HWND *)(iVar3 + 8);
  if (param_4 == 0) {
    local_c = (HWND)0x0;
    pHVar5 = param_2;
    pHVar4 = local_c;
  }
  else {
    pHVar5 = pHVar1;
    param_3 = iVar2;
    pHVar4 = param_2;
    if ((param_4 != 1) && (pHVar5 = (HWND)0x0, param_3 = 0, pHVar4 = local_c, param_4 == 2)) {
      pHVar4 = GetDlgItem(hDlg,(int)param_2);
      pHVar5 = pHVar1;
      param_3 = iVar2;
    }
  }
  local_c = pHVar4;
  iVar2 = DAT_1002e558;
  pHVar1 = DAT_1002e554;
  if (param_7 == 0) {
    local_8 = (HWND)0x0;
    local_1c = param_5;
    local_18 = param_6;
  }
  else {
    if (param_7 != 1) {
      if (param_7 != 2) goto LAB_10013b70;
      param_5 = GetDlgItem(hDlg,(int)param_5);
    }
    local_18 = iVar2;
    local_1c = pHVar1;
    local_8 = param_5;
  }
LAB_10013b70:
  FUN_1001329e(this,param_1,(int)pHVar5,param_3,(int)local_1c,local_18,local_c,local_8);
  return;
}



// Function: FUN_10013b90 at 10013b90

undefined4 FUN_10013b90(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(int *)(param_1 + -0x20) == 0) {
      FUN_1001379b((void *)(param_1 + -0x24),(HWND)0x0,(int *)0x0,L"AXWIN Frame Window",0xcf0000,0,
                   (HMENU)0x0,(LPVOID)0x0);
    }
    *param_2 = *(undefined4 *)(param_1 + -0x20);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10013bd9 at 10013bd9

undefined4 FUN_10013bd9(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    if (*(int *)(param_1 + -0x20) == 0) {
      FUN_100137fa((void *)(param_1 + -0x24),(HWND)0x0,(int *)0x0,L"AXWIN UI Window",0xcf0000,0,
                   (HMENU)0x0,(LPVOID)0x0);
    }
    *param_2 = *(undefined4 *)(param_1 + -0x20);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10013c29 at 10013c29

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10013c29(int param_1)

{
  *(undefined4 *)(param_1 + 0xf4) = 0;
  FUN_1000e1e6(param_1 + 4);
  FUN_1000edf5((undefined4 *)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x6c) = 0;
  FUN_10013a0d((undefined4 *)(param_1 + 0x74));
  FUN_1000e39d((undefined4 *)(param_1 + 0xdc));
  *(undefined4 *)(param_1 + 0x110) = 7;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined2 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  return param_1;
}



// Function: FUN_10013cee at 10013cee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10013cee(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x120);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000e2b9((undefined4 *)(param_1 + 0x11c));
  FUN_1000e2b9((undefined4 *)(param_1 + 0x118));
  FID_conflict__Tidy((void *)(param_1 + 0xfc),'\x01',0);
  FUN_1000e3f5((undefined4 *)(param_1 + 0xdc));
  FUN_10013a72((undefined4 *)(param_1 + 0x74));
  FUN_1000e781(param_1 + 0x24);
  FUN_1000e21c(param_1 + 4);
  return;
}



// Function: FUN_10013d90 at 10013d90

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10013d90(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0xf4);
    if (this != (void *)0x0) {
      FUN_10013859(this,param_1);
    }
    uVar1 = FUN_10013dfa();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10013ded at 10013ded

undefined * Catch_10013ded(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10013df7;
}



// Function: FUN_10013dfa at 10013dfa

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10013dfa(void)

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



// Function: FUN_10013e2a at 10013e2a

void __thiscall
FUN_10013e2a(void *this,int param_1,HWND param_2,int param_3,int param_4,HWND param_5,int param_6,
            int param_7)

{
  int iVar1;
  HWND pHVar2;
  
  iVar1 = __RTDynamicCast(this,0,&CResizingDialog<class_CFuelSystemTableResetGTIS45PageImpl>::
                                  RTTI_Type_Descriptor,
                          &CFuelSystemTableResetGTIS45PageImpl::RTTI_Type_Descriptor,0);
  pHVar2 = GetDlgItem(*(HWND *)(iVar1 + 8),param_1);
  FUN_10013aa4(this,pHVar2,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



// Function: FUN_10013e7a at 10013e7a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10013e7a(undefined2 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_1000e96e(param_1,param_3[4] + param_2[4]);
  FUN_10007fdc(param_1,param_2,0,0xffffffff);
  FUN_10007fdc(param_1,param_3,0,0xffffffff);
  return param_1;
}



// Function: FUN_10013ede at 10013ede

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10013ede(void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (((uint)(param_2[5] - param_2[4]) < (uint)param_3[4]) &&
     ((uint)param_2[4] <= (uint)(param_3[5] - param_3[4]))) {
    puVar1 = FUN_10006841(param_3,0,param_2,0,0xffffffff);
    basic_string<>(param_1,puVar1);
  }
  else {
    puVar1 = FUN_10007fdc(param_2,param_3,0,0xffffffff);
    basic_string<>(param_1,puVar1);
  }
  return param_1;
}



// Function: FUN_10013f49 at 10013f49

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10013f49(void *param_1,undefined4 *param_2,void *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_10006841(param_3,0,param_2,0,0xffffffff);
  basic_string<>(param_1,puVar1);
  return param_1;
}



// Function: FUN_10013f87 at 10013f87

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10013f87(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10013f93;
  FUN_1001532d();
  local_14[0] = (int *)0x0;
  local_18 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  iVar1 = FUN_10013d90((undefined4 *)0x0,&PTR_10020a0c,local_14);
  if (iVar1 < 0) {
LAB_10014023:
    if (param_4 == (undefined4 *)0x0) goto LAB_10014054;
    if (-1 < iVar1) {
      *param_4 = local_14[0];
      local_14[0] = (int *)0x0;
      goto LAB_10014054;
    }
  }
  else {
    local_1c = (int *)0x0;
    local_8._0_1_ = 5;
    (**(code **)*local_14[0])(local_14[0],&DAT_10023314,&local_1c);
    if (param_1 == 0) {
      param_1 = 0;
LAB_10013fe0:
      local_8._0_1_ = 6;
      iVar1 = (**(code **)(*local_1c + 0x28))
                        (local_1c,param_1,param_2,param_3,&local_18,param_6,param_7,param_8);
      local_8._0_1_ = 5;
      Ordinal_6(param_1);
      local_8._0_1_ = 3;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      goto LAB_10014023;
    }
    param_1 = Ordinal_2(param_1);
    if (param_1 != 0) goto LAB_10013fe0;
    param_4 = (undefined4 *)FUN_10001000(0x8007000e);
  }
  *param_4 = 0;
LAB_10014054:
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



// Function: FUN_10014097 at 10014097

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10014097(void *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  uint uVar2;
  
  basic_string<>(param_1,param_2);
  puVar1 = DAT_10030314;
  if (DAT_10030328 < 8) {
    puVar1 = (ushort *)&DAT_10030314;
  }
  uVar2 = FUN_100048a3(param_1,puVar1,0,(uint)DAT_10030324);
  while (uVar2 != 0xffffffff) {
    FUN_10007a90(param_1,uVar2,DAT_10030324,(undefined4 *)&DAT_100302c0,0,0xffffffff);
    puVar1 = DAT_10030314;
    if (DAT_10030328 < 8) {
      puVar1 = (ushort *)&DAT_10030314;
    }
    uVar2 = FUN_100048a3(param_1,puVar1,0,(uint)DAT_10030324);
  }
  while( true ) {
    puVar1 = DAT_100302f8;
    if (DAT_1003030c < 8) {
      puVar1 = (ushort *)&DAT_100302f8;
    }
    uVar2 = FUN_100048a3(param_1,puVar1,0,(uint)DAT_10030308);
    if (uVar2 == 0xffffffff) break;
    FUN_10007a90(param_1,uVar2,DAT_10030308,(undefined4 *)&DAT_100302dc,0,0xffffffff);
  }
  return param_1;
}



// Function: FUN_10014169 at 10014169

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10014169(int param_1)

{
  void *this;
  
  this = (void *)(param_1 + 0x74);
  FUN_10013e2a(this,0x69,DAT_100308f0,DAT_100308f4,0,DAT_1002e564,DAT_1002e568,0);
  FUN_10013e2a(this,0x68,DAT_100308f0,DAT_100308f4,0,DAT_1002e564,DAT_1002e568,0);
  FUN_10013e2a(this,0x6b,DAT_100308f0,DAT_100308f4,0,DAT_1002e564,DAT_1002e568,0);
  FUN_10013e2a(this,0x6a,DAT_1002e564,DAT_1002e568,0,DAT_1002e554,DAT_1002e558,0);
  FUN_10013e2a(this,0x66,DAT_1002e584,DAT_1002e588,0,DAT_1002e554,DAT_1002e558,0);
  FUN_10013e2a(this,0x67,DAT_1002e5a4,DAT_1002e5a8,0,DAT_1002e554,DAT_1002e558,0);
  return;
}



// Function: Catch@1001432c at 1001432c

undefined4 Catch_1001432c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10014326;
}



// Function: FUN_10014336 at 10014336

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall
FUN_10014336(void *this,int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
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
  iVar2 = FUN_1000f136(this,&DAT_10022c84,(int *)local_14);
  if (iVar2 < 0) {
                    /* WARNING: Load size is inaccurate */
    iVar2 = FUN_10013f87(param_1,*this,param_2,param_3,param_4,param_5,param_6,param_7);
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
        iVar2 = (**(code **)*local_14[0])(local_14[0],&PTR_10020a0c,param_3);
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



// Function: FUN_10014401 at 10014401

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_10014401(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_3c [4];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x1001440d;
  local_24 = 0xffffffff;
  FUN_1000173f(local_3c);
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  local_18[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 7;
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10021f34,&local_20);
    FUN_100020b2(local_3c,iVar3);
    piVar2 = local_20;
    piVar4 = FUN_10015f82(&local_2c,(undefined4 *)&DAT_1003082c);
    local_8._0_1_ = 8;
    iVar3 = (**(code **)(*piVar2 + 0x24))(piVar2,*piVar4,&local_1c);
    FUN_100020b2(local_3c,iVar3);
    local_8._0_1_ = 7;
    Ordinal_6(local_2c);
    iVar3 = (**(code **)*local_1c)(local_1c,&DAT_10021f44,local_18);
    FUN_100020b2(local_3c,iVar3);
    local_28 = 0xffffffff;
    (**(code **)(*local_18[0] + 0x88))(local_18[0],&local_28);
    if (local_18[0] != (int *)0x0) {
      if ((short)local_28 == -1) {
        local_24 = 0xffffffff;
      }
      else {
        iVar3 = (**(code **)(*local_18[0] + 0x5c))(local_18[0],&local_24);
        FUN_100020b2(local_3c,iVar3);
      }
    }
  }
  local_8._0_1_ = 5;
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8._0_1_ = 3;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return local_24;
}



// Function: Catch@10014544 at 10014544

undefined4 Catch_10014544(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014537;
}



// Function: FUN_1001454e at 1001454e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1001454e(void *this,undefined4 *param_1)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  undefined4 local_38 [3];
  undefined4 uStack_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_1c = (int *)0x0;
  local_18[0] = (int *)0x0;
  local_28 = (int *)0x0;
  local_8._1_3_ = 0;
  local_24 = (int *)0x0;
  local_8._0_1_ = 7;
  FUN_1000173f(local_38);
  if (*(int *)((int)this + 0xc) != 0) {
    local_8._0_1_ = 9;
    iVar1 = (**(code **)**(undefined4 **)((int)this + 0xc))
                      (*(undefined4 **)((int)this + 0xc),&DAT_10022848,&local_24);
    FUN_100020b2(local_38,iVar1);
    local_20 = (int *)0x0;
    local_8._0_1_ = 0xb;
    iVar1 = (**(code **)(*local_24 + 0x20))(local_24,&local_20);
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)*local_20)(local_20,&DAT_10020a1c,&local_28);
    FUN_100020b2(local_38,iVar1);
    HVar2 = CoCreateInstance((IID *)&DAT_10022838,(LPUNKNOWN)0x0,0x17,(IID *)&PTR_10020a0c,&local_1c
                            );
    FUN_100020b2(local_38,HVar2);
    iVar1 = (**(code **)*local_1c)(local_1c,&DAT_10020a2c,local_18);
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)(*local_18[0] + 0x10))(local_18[0],*param_1);
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)(*local_18[0] + 0x20))(local_18[0],*(undefined4 *)((int)this + 4));
    FUN_100020b2(local_38,iVar1);
    iVar1 = (**(code **)(*local_28 + 0xc))(local_28,local_1c);
    FUN_100020b2(local_38,iVar1);
    local_8 = CONCAT31(local_8._1_3_,9);
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
    local_8 = 8;
    uVar3 = FUN_10014694();
    return uVar3;
  }
  local_8._0_1_ = 5;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  local_8._0_1_ = 3;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return uStack_2c;
}



// Function: Catch@10014685 at 10014685

undefined * Catch_10014685(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 8;
  return &DAT_10014692;
}



// Function: FUN_10014694 at 10014694

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10014694(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_EDI;
  
  *(undefined1 *)(unaff_EBP + -4) = 5;
  piVar1 = *(int **)(unaff_EBP + -0x20);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  piVar1 = *(int **)(unaff_EBP + -0x24);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + -0x18);
  if (piVar1 != unaff_EDI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return *(undefined4 *)(unaff_EBP + -0x28);
}



// Function: FUN_100146e3 at 100146e3

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100146e3(int param_1)

{
  int iVar1;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x100146ef;
  FUN_1000173f(local_24);
  local_8 = 1;
  iVar1 = FUN_1000eed6(param_1);
  FUN_100020b2(local_24,iVar1);
  return local_18;
}



// Function: Catch@10014723 at 10014723

undefined4 Catch_10014723(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014714;
}



// Function: FUN_10014734 at 10014734

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10014734(void *this,char param_1)

{
  LPCWSTR pWVar1;
  HDC pHVar2;
  HWND pHVar3;
  HICON pHVar4;
  undefined4 *puVar5;
  HFONT wParam;
  bool bVar6;
  int iVar7;
  int iVar8;
  undefined4 local_78 [4];
  undefined4 local_68;
  HFONT local_64;
  tagRECT local_60;
  undefined2 local_50 [14];
  LPCWSTR *local_34 [5];
  uint local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0x10014740;
  FUN_1000173f(local_78);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_100020b2(local_78,0);
  local_64 = *(HFONT *)((int)this + 8);
                    /* WARNING: Load size is inaccurate */
  pWVar1 = (LPCWSTR)(**(code **)(*this + 0x10))();
  FUN_1000f264(&local_64,pWVar1);
  iVar8 = 0x48;
  iVar7 = 0x5a;
  pHVar2 = GetDC((HWND)0x0);
  iVar7 = GetDeviceCaps(pHVar2,iVar7);
  iVar7 = MulDiv(0xc,iVar7,iVar8);
  pWVar1 = DAT_1003096c;
  if (DAT_10030980 < 8) {
    pWVar1 = (LPCWSTR)&DAT_1003096c;
  }
  local_64 = CreateFontW(-iVar7,0,0,0,700,0,0,0,1,0,0,0,0,pWVar1);
  *(HFONT *)((int)this + 0x118) = local_64;
  pHVar3 = GetDlgItem(*(HWND *)((int)this + 8),0x69);
  SendMessageW(pHVar3,0x30,(WPARAM)local_64,1);
  pHVar3 = GetDlgItem(*(HWND *)((int)this + 8),0x6b);
  *(undefined4 *)((int)this + 0x138) = pHVar3;
  FUN_10001130((undefined4 *)((int)this + 0x138),0,7,0);
  pHVar3 = GetDlgItem(*(HWND *)((int)this + 8),0x6a);
  *(undefined4 *)((int)this + 0x134) = pHVar3;
  FUN_10001130((undefined4 *)((int)this + 0x134),0,3,0);
  pHVar4 = LoadIconW(DAT_10031344,(LPCWSTR)0x6c);
  FUN_100012c1((void *)((int)this + 0x134),(WPARAM)pHVar4);
  local_68 = 0;
  iVar7 = (**(code **)(**(int **)((int)this + 0x120) + 0x24))
                    (*(int **)((int)this + 0x120),&local_68);
  FUN_100020b2(local_78,iVar7);
  if ((param_1 == '\0') || ((short)local_68 != -1)) {
    pHVar3 = GetDlgItem(*(HWND *)((int)this + 8),0x67);
    EnableWindow(pHVar3,0);
    if (param_1 == '\0') {
      GetClientRect(*(HWND *)((int)this + 0x138),&local_60);
      basic_string<>(local_34,(undefined4 *)&DAT_100308fc);
      local_8._0_1_ = 2;
      puVar5 = (undefined4 *)FUN_10001eb7(local_50,0x7d);
      local_8._0_1_ = 3;
      FUN_10001db8(local_34,puVar5);
      local_8._0_1_ = 2;
      FID_conflict__Tidy(local_50,'\x01',0);
      if (local_20 < 8) {
        local_34[0] = (LPCWSTR *)local_34;
      }
      pHVar3 = CreateWindowExW(0,L"STATIC",(LPCWSTR)local_34[0],0x50000000,local_60.left + 0xf,
                               local_60.bottom + 0x14,local_60.right - local_60.left,
                               local_60.bottom - local_60.top,*(HWND *)((int)this + 8),(HMENU)0x0,
                               (HINSTANCE)0x0,(LPVOID)0x0);
      iVar8 = 0x48;
      iVar7 = 0x5a;
      pHVar2 = GetDC((HWND)0x0);
      iVar7 = GetDeviceCaps(pHVar2,iVar7);
      iVar7 = MulDiv(8,iVar7,iVar8);
      pWVar1 = DAT_1003096c;
      if (DAT_10030980 < 8) {
        pWVar1 = (LPCWSTR)&DAT_1003096c;
      }
      wParam = CreateFontW(-iVar7,0,0,0,0,0,0,0,1,0,0,0,0,pWVar1);
      *(HFONT *)((int)this + 0x11c) = wParam;
      SendMessageW(pHVar3,0x30,(WPARAM)wParam,1);
      local_8 = CONCAT31(local_8._1_3_,1);
      FID_conflict__Tidy(local_34,'\x01',0);
    }
  }
  else {
    bVar6 = *(int *)((int)this + 0xf8) != 3;
    if (bVar6) {
      pHVar3 = GetDlgItem(*(HWND *)((int)this + 8),0x67);
    }
    else {
      pHVar3 = GetDlgItem(*(HWND *)((int)this + 8),0x67);
    }
    EnableWindow(pHVar3,(uint)bVar6);
  }
  local_8 = 0xffffffff;
  FUN_10017306();
  return;
}



// Function: Catch@1001498f at 1001498f

undefined4 Catch_1001498f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014983;
}



// Function: FUN_10014999 at 10014999

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x100149f0) */

undefined4 __fastcall FUN_10014999(undefined4 *param_1)

{
  undefined4 uVar1;
  HWND hWnd;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  FUN_10016475(&stack0xffffffd4,param_1 + 0x15);
  uVar1 = FUN_10016384(puVar2);
  param_1[0x3e] = uVar1;
  FUN_10014169((int)param_1);
  (**(code **)(*(int *)param_1[0x48] + 0x1c))();
  FUN_10014734(param_1,'\0');
  if (param_1[0x3e] == 3) {
    hWnd = GetDlgItem((HWND)param_1[2],0x67);
    EnableWindow(hWnd,0);
  }
  return 1;
}



// Function: FUN_10014a23 at 10014a23

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __fastcall FUN_10014a23(int param_1)

{
  int iVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30 [4];
  int *local_20;
  int *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x10014a2f;
  FUN_1000173f(local_30);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_100020b2(local_30,0);
  local_1c = (int *)0x0;
  local_8._0_1_ = 3;
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x54))
                    (*(undefined4 **)(param_1 + 0x54),&DAT_10021f34,&local_1c);
  FUN_100020b2(local_30,iVar1);
  local_18[0] = (int *)0x0;
  local_8._0_1_ = 5;
  iVar1 = (**(code **)(*local_1c + 0x24))(local_1c,DAT_100308f8,local_18);
  FUN_100020b2(local_30,iVar1);
  FUN_1000e8d3(&local_20,local_18[0]);
  local_40 = CONCAT22(local_40._2_2_,3);
  local_38 = 0x1e;
  local_8._0_1_ = 7;
  (**(code **)(*local_20 + 0x3c))(local_20,local_40,uStack_3c,0x1e,uStack_34);
  local_8._0_1_ = 6;
  Ordinal_9(&local_40);
  local_8._0_1_ = 5;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_8._0_1_ = 3;
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = 0xffffffff;
  FUN_10001415(local_30);
  FUN_10014b3f();
  return;
}



// Function: Catch@10014b2f at 10014b2f

undefined * Catch_10014b2f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10014b39;
}



// Function: FUN_10014b3f at 10014b3f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10014b3f(void)

{
  return;
}



// Function: FUN_10014b45 at 10014b45

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10014b45(int param_1)

{
  uint uVar1;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10014b51;
  FUN_1000173f(local_24);
  local_8 = 1;
  uVar1 = (**(code **)(*(int *)(param_1 + -0x14) + 4))(0x53,0,0,&param_1);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  FUN_100020b2(local_24,uVar1);
  return local_18;
}



// Function: Catch@10014b9e at 10014b9e

undefined4 Catch_10014b9e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014b8f;
}



// Function: FUN_10014ba8 at 10014ba8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10014ba8(undefined4 param_1,wchar_t *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *pwVar3;
  wchar_t *in_stack_ffffff24;
  int local_d0 [38];
  undefined4 local_38;
  wchar_t *local_34;
  undefined1 local_30 [40];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc0;
  local_8 = 0x10014bb7;
  local_38 = param_1;
  local_34 = param_2;
  FUN_10007e12(local_d0,2,1);
  local_8 = 0;
  __RTDynamicCast(local_38,0);
  piVar1 = (int *)FUN_10005101(local_d0,local_34);
  FUN_10005101(piVar1,in_stack_ffffff24);
  iVar2 = __RTDynamicCast();
  pwVar3 = (wchar_t *)FUN_1000b5d1(local_d0,local_30);
  local_8._0_1_ = 1;
  if (7 < *(uint *)(pwVar3 + 10)) {
    pwVar3 = *(wchar_t **)pwVar3;
  }
  local_34 = (wchar_t *)&stack0xffffff14;
  FUN_10001d86(&stack0xffffff14,pwVar3);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)(iVar2 + 0x68) + 0x3c))();
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  FUN_10007a31((int)local_d0);
  FUN_100172f7();
  return;
}



// Function: FUN_10014c80 at 10014c80

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10014c80(void *this,undefined4 param_1,CComBSTR *param_2)

{
  HRESULT HVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_2c [3];
  undefined4 local_20;
  wchar_t *local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0;
  FUN_1000173f(local_2c);
  local_20 = 0;
  local_18[0] = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  HVar1 = CoCreateInstance((IID *)&DAT_10022828,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10021f24,local_18);
  FUN_100020b2(local_2c,HVar1);
  uVar2 = FUN_10014401((int)this);
  iVar3 = (**(code **)(*local_18[0] + 0xc))(local_18[0],uVar2);
  FUN_100020b2(local_2c,iVar3);
  Ordinal_6(*(undefined4 *)param_2);
  *(undefined4 *)param_2 = 0;
  iVar3 = (**(code **)(*local_18[0] + 0x18))(local_18[0],param_1,0,&local_1c);
  FUN_100020b2(local_2c,iVar3);
  ATL::CComBSTR::Attach(param_2,local_1c);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = 0xffffffff;
  Ordinal_6(param_1);
  return local_20;
}



// Function: Catch@10014d50 at 10014d50

undefined4 Catch_10014d50(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10014d38;
}



// Function: FUN_10014d5d at 10014d5d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10014d5d(void *this)

{
  int iVar1;
  undefined4 *in_stack_00000010;
  undefined4 uStack_4c;
  undefined4 local_30 [3];
  int local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10014d69;
  FUN_1000173f(local_30);
  local_1c = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 8))();
  uStack_4c = 0x10014d97;
  FUN_100020b2(local_30,iVar1);
  local_18[0] = 0;
  local_8._0_1_ = 3;
  local_20 = (undefined1 *)&uStack_4c;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&uStack_4c,(CComBSTR *)&local_1c);
                    /* WARNING: Load size is inaccurate */
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = (**(code **)(*this + 0xc))();
  FUN_100020b2(local_30,iVar1);
  if (local_24 == 0) {
    iVar1 = FUN_1001454e(this,local_18);
    FUN_100020b2(local_30,iVar1);
  }
  local_8._0_1_ = 2;
  Ordinal_6(local_18[0]);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_1c);
  *in_stack_00000010 = 1;
  return local_24;
}



// Function: Catch@10014e15 at 10014e15

undefined4 Catch_10014e15(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014dfd;
}



// Function: FUN_1001532d at 1001532d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_1001532d(void)

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
  local_1c = &DAT_100313a0;
  local_18 = 0;
  local_8 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_100313a0);
  local_18 = 1;
  DAT_1002f1b8 = RegisterWindowMessageW(L"WM_ATLGETHOST");
  DAT_1002f1bc = RegisterWindowMessageW(L"WM_ATLGETCONTROL");
  local_4c.cbSize = 0x30;
  BVar2 = GetClassInfoExW(DAT_10031340,L"AtlAxWin100",&local_4c);
  if (BVar2 == 0) {
    local_4c.cbSize = 0x30;
    local_4c.style = 8;
    local_4c.lpfnWndProc = (WNDPROC)&LAB_10014e1f;
    local_4c.cbClsExtra = 0;
    local_4c.cbWndExtra = 0;
    local_4c.hInstance = DAT_10031340;
    local_4c.hIcon = (HICON)0x0;
    local_4c.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_4c.hbrBackground = (HBRUSH)0x6;
    local_4c.lpszMenuName = (LPCWSTR)0x0;
    local_4c.lpszClassName = L"AtlAxWin100";
    local_4c.hIconSm = (HICON)0x0;
    AVar1 = RegisterClassExW(&local_4c);
    local_14[0] = (uint)AVar1;
    if (AVar1 != 0) {
      FUN_1000e80f(&DAT_100313bc,(undefined2 *)local_14);
      goto LAB_100153fd;
    }
  }
  else {
LAB_100153fd:
    memset(&local_4c,0,0x30);
    local_4c.cbSize = 0x30;
    local_14[0] = GetClassInfoExW(DAT_10031340,L"AtlAxWinLic100",&local_4c);
    if (local_14[0] != 0) goto LAB_1001549e;
    local_4c.cbSize = 0x30;
    local_4c.style = 8;
    local_4c.lpfnWndProc = (WNDPROC)&LAB_1001507d;
    local_4c.cbClsExtra = 0;
    local_4c.cbWndExtra = 0;
    local_4c.hInstance = DAT_10031340;
    local_4c.hIcon = (HICON)0x0;
    local_4c.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_4c.hbrBackground = (HBRUSH)0x6;
    local_4c.lpszMenuName = (LPCWSTR)0x0;
    local_4c.lpszClassName = L"AtlAxWinLic100";
    local_4c.hIconSm = (HICON)0x0;
    AVar1 = RegisterClassExW(&local_4c);
    local_14[0] = (uint)AVar1;
    if (AVar1 != 0) {
      FUN_1000e80f(&DAT_100313bc,(undefined2 *)local_14);
      local_14[0] = 1;
      goto LAB_1001549e;
    }
  }
  local_14[0] = 0;
LAB_1001549e:
  local_8 = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_100313a0);
  return local_14[0];
}



// Function: FUN_100154b5 at 100154b5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100154b5(int param_1,wchar_t *param_2)

{
  int iVar1;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x100154c1;
  FUN_1000173f(local_24);
  local_8 = 1;
  FUN_100020b2(local_24,0);
  iVar1 = FUN_10014ba8(param_1,param_2);
  FUN_100020b2(local_24,iVar1);
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x38))
                    (*(undefined4 **)(param_1 + 0x38),&DAT_10021d6c,param_1 + 0xfc);
  FUN_100020b2(local_24,iVar1);
  return local_18;
}



// Function: Catch@1001551f at 1001551f

undefined4 Catch_1001551f(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  uVar1 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x1c))(*(int **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10015510;
}



// Function: FUN_1001553c at 1001553c

void __fastcall FUN_1001553c(void *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*(int *)((int)param_1 + -0xb8) + 0x4c))(1);
  if (*(int **)((int)param_1 + 8) != piVar1) {
    FUN_100010fd((int *)((int)param_1 + 8),piVar1);
  }
  piVar1 = (int *)(**(code **)(*(int *)((int)param_1 + -0xb8) + 0x4c))(2);
  if (*(int **)((int)param_1 + 0xc) != piVar1) {
    FUN_100010fd((int *)((int)param_1 + 0xc),piVar1);
  }
  FUN_10014d5d(param_1);
  return;
}



// Function: FUN_1001559a at 1001559a

INT_PTR __cdecl
FUN_1001559a(HMODULE param_1,LPCWSTR param_2,HWND param_3,DLGPROC param_4,LPARAM param_5)

{
  HRSRC hResInfo;
  HRSRC hResInfo_00;
  HGLOBAL pvVar1;
  LPCDLGTEMPLATEW pDVar2;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR local_10;
  LPVOID local_c;
  DWORD local_8;
  
  FUN_1001532d();
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
      hDialogTemplate = (LPCDLGTEMPLATEW)FUN_1000df83(pDVar2,local_c);
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



// Function: FUN_1001566f at 1001566f

INT_PTR __thiscall FUN_1001566f(void *this,HWND param_1,LPARAM param_2)

{
  INT_PTR IVar1;
  
  FUN_1000603f(0x1003139c,(DWORD *)((int)this + 8),(DWORD *)this);
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x20) = 1;
  IVar1 = FUN_1001559a(DAT_10031344,(LPCWSTR)0x64,param_1,FUN_1000837a,param_2);
  if (((int)*(DWORD *)((int)this + 0x24) < 0) && (IVar1 == -1)) {
    SetLastError(*(DWORD *)((int)this + 0x24));
  }
  return IVar1;
}



// Function: FUN_100156c5 at 100156c5

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_100156c5(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  LPCWSTR lpText;
  int iVar3;
  LPCWSTR **lpText_00;
  undefined4 *puVar4;
  size_t sVar5;
  void *pvVar6;
  HWND pHVar7;
  LPCWSTR lpCaption;
  LPCWSTR **lpCaption_00;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar8;
  int *piVar9;
  LPARAM LVar10;
  int local_180;
  undefined1 *local_17c;
  undefined4 local_178 [25];
  undefined1 local_114 [28];
  undefined2 local_f8 [8];
  undefined4 local_e8;
  undefined4 local_e4;
  undefined2 local_dc [8];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b0;
  uint local_ac;
  undefined2 local_a4 [8];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_88;
  undefined4 local_78;
  uint local_74;
  LPCWSTR *local_6c [4];
  undefined4 local_5c;
  uint local_58;
  undefined2 local_50 [8];
  undefined4 local_40;
  undefined4 local_3c;
  LPCWSTR *local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 400;
  local_8 = 0x100156d4;
  local_17c = param_1;
  FUN_1000173f((undefined4 *)&stack0xfffffe6c);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_100020b2(&stack0xfffffe6c,0);
  local_74 = 7;
  local_78 = 0;
  local_88 = (LPCWSTR)((uint)local_88._2_2_ << 0x10);
  local_ac = 7;
  local_b0 = 0;
  local_c0 = (LPCWSTR)((uint)local_c0._2_2_ << 0x10);
  local_8._0_1_ = 3;
  puVar2 = (undefined4 *)FUN_10001eb7(local_50,0x84);
  local_8._0_1_ = 4;
  FUN_10001db8(&local_88,puVar2);
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_50,'\x01',0);
  puVar2 = (undefined4 *)FUN_10014097(local_50,&local_88);
  local_8._0_1_ = 5;
  FUN_10001db8(&local_88,puVar2);
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_50,'\x01',0);
  puVar2 = (undefined4 *)FUN_10001eb7(local_50,0x79);
  local_8._0_1_ = 6;
  FUN_10001db8(&local_c0,puVar2);
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_50,'\x01',0);
  lpCaption = local_c0;
  if (local_ac < 8) {
    lpCaption = (LPCWSTR)&local_c0;
  }
  lpText = local_88;
  if (local_74 < 8) {
    lpText = (LPCWSTR)&local_88;
  }
  iVar3 = MessageBoxW(*(HWND *)(param_1 + 8),lpText,lpCaption,0x34);
  local_180 = -1;
  if (iVar3 == 6) {
    FUN_1000e18e(&stack0xfffffe60,'\x01',(LPCWSTR)0x7f02,'\x01');
    local_8._0_1_ = 7;
    iVar3 = (**(code **)(**(int **)(local_17c + 0x120) + 0x20))
                      (*(int **)(local_17c + 0x120),&local_180);
    if ((local_180 == 0) && (-1 < iVar3)) {
      iVar3 = FUN_10014a23((int)local_17c);
      if (iVar3 == 1) {
        local_20 = 7;
        local_24 = 0;
        local_34[0] = (LPCWSTR *)((uint)local_34[0] & 0xffff0000);
        local_58 = 7;
        local_5c = 0;
        local_6c[0] = (LPCWSTR *)((uint)local_6c[0] & 0xffff0000);
        local_8._0_1_ = 9;
        puVar2 = (undefined4 *)FUN_10001eb7(local_50,0x7c);
        local_8._0_1_ = 10;
        FUN_10001db8(local_34,puVar2);
        local_8._0_1_ = 9;
        FID_conflict__Tidy(local_50,'\x01',0);
        puVar2 = (undefined4 *)FUN_10001eb7(local_50,0x79);
        local_8._0_1_ = 0xb;
        FUN_10001db8(local_6c,puVar2);
        local_8._0_1_ = 9;
        FID_conflict__Tidy(local_50,'\x01',0);
        lpCaption_00 = (LPCWSTR **)local_6c[0];
        if (local_58 < 8) {
          lpCaption_00 = local_6c;
        }
        lpText_00 = (LPCWSTR **)local_34[0];
        if (local_20 < 8) {
          lpText_00 = local_34;
        }
        MessageBoxW(*(HWND *)(local_17c + 8),(LPCWSTR)lpText_00,(LPCWSTR)lpCaption_00,0x40);
        local_8._0_1_ = 8;
        FID_conflict__Tidy(local_6c,'\x01',0);
        local_8._0_1_ = 7;
        FID_conflict__Tidy(local_34,'\x01',0);
      }
    }
    else {
      local_3c = 7;
      local_40 = 0;
      local_50[0] = 0;
      local_c8 = 7;
      local_cc = 0;
      local_dc[0] = 0;
      local_e4 = 7;
      local_e8 = 0;
      local_f8[0] = 0;
      local_90 = 7;
      local_94 = 0;
      local_a4[0] = 0;
      local_8._0_1_ = 0xf;
      puVar2 = (undefined4 *)FUN_10001eb7((undefined2 *)local_34,0x7f);
      local_8._0_1_ = 0x10;
      FUN_10001db8(local_50,puVar2);
      local_8._0_1_ = 0xf;
      FID_conflict__Tidy(local_34,'\x01',0);
      puVar2 = (undefined4 *)FUN_10001eb7((undefined2 *)local_34,0x80);
      local_8._0_1_ = 0x11;
      FUN_10001db8(local_f8,puVar2);
      local_8._0_1_ = 0xf;
      FID_conflict__Tidy(local_34,'\x01',0);
      puVar2 = (undefined4 *)FUN_10001eb7((undefined2 *)local_34,0x7e);
      local_8._0_1_ = 0x12;
      FUN_10001db8(local_dc,puVar2);
      local_8._0_1_ = 0xf;
      FID_conflict__Tidy(local_34,'\x01',0);
      puVar2 = (undefined4 *)FUN_100161d5(local_114,0x8aac);
      local_8._0_1_ = 0x13;
      puVar4 = (undefined4 *)
               FUN_10013e7a((undefined2 *)local_6c,(undefined4 *)local_50,
                            (undefined4 *)&DAT_100308fc);
      local_8._0_1_ = 0x14;
      puVar2 = (undefined4 *)FUN_10013ede(local_34,puVar4,puVar2);
      local_8._0_1_ = 0x15;
      FUN_10007fdc(local_a4,puVar2,0,0xffffffff);
      local_8._0_1_ = 0x14;
      FID_conflict__Tidy(local_34,'\x01',0);
      local_8._0_1_ = 0x13;
      FID_conflict__Tidy(local_6c,'\x01',0);
      local_8._0_1_ = 0xf;
      FID_conflict__Tidy(local_114,'\x01',0);
      sVar5 = wcslen(L"\r\n\r\n");
      FUN_10008081(local_a4,(undefined4 *)L"\r\n\r\n",sVar5);
      FUN_10007fdc(local_a4,(undefined4 *)local_f8,0,0xffffffff);
      sVar5 = wcslen(L"\r\n");
      FUN_10008081(local_a4,(undefined4 *)&DAT_10022ca0,sVar5);
      pvVar6 = FUN_100161d5(local_34,local_180);
      local_8._0_1_ = 0x16;
      puVar2 = (undefined4 *)FUN_10013f49(local_114,(undefined4 *)local_dc,pvVar6);
      local_8._0_1_ = 0x17;
      FUN_10007fdc(local_a4,puVar2,0,0xffffffff);
      local_8._0_1_ = 0x16;
      FID_conflict__Tidy(local_114,'\x01',0);
      local_8._0_1_ = 0xf;
      FID_conflict__Tidy(local_34,'\x01',0);
      FUN_1000ef7c(local_178);
      local_8._0_1_ = 0x18;
      FUN_10001e7c(local_178,(undefined4 *)local_a4);
      puVar1 = local_17c;
      piVar8 = (int *)(local_17c + 0x58);
      local_17c = &stack0xfffffe74;
      piVar9 = extraout_ECX;
      FUN_10016475(&stack0xfffffe74,piVar8);
      local_8._0_1_ = 0x19;
      piVar8 = extraout_ECX_00;
      FUN_10016475(&stack0xfffffe70,(int *)(puVar1 + 0x54));
      local_8._0_1_ = 0x18;
      FUN_10001785(local_178,piVar8,piVar9);
      LVar10 = 0;
      pHVar7 = GetActiveWindow();
      FUN_1001566f(local_178,pHVar7,LVar10);
      local_8._0_1_ = 0xf;
      FUN_1000f19b(local_178);
      local_8._0_1_ = 0xe;
      FID_conflict__Tidy(local_a4,'\x01',0);
      local_8._0_1_ = 0xd;
      FID_conflict__Tidy(local_f8,'\x01',0);
      local_8._0_1_ = 0xc;
      FID_conflict__Tidy(local_dc,'\x01',0);
      local_8._0_1_ = 7;
      FID_conflict__Tidy(local_50,'\x01',0);
    }
    local_8._0_1_ = 3;
    FUN_1000dd8c((int)&stack0xfffffe60);
  }
  local_8._0_1_ = 2;
  FID_conflict__Tidy(&local_c0,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FID_conflict__Tidy(&local_88,'\x01',0);
  local_8 = 0xffffffff;
  FUN_10017306();
  return;
}



// Function: Catch@10015c1a at 10015c1a

undefined4 Catch_10015c1a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10015c0c;
}



// Function: FUN_10015c24 at 10015c24

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10015c24(void *this,ushort param_1)

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
  local_8 = 0x10015c30;
  pHVar5 = FindResourceW(DAT_10031344,(LPCWSTR)(uint)param_1,(LPCWSTR)0xf0);
  local_48 = (ushort *)0x0;
  local_28 = (HWND)0x0;
  if ((pHVar5 != (HRSRC)0x0) && (pvVar6 = LoadResource(DAT_10031344,pHVar5), pvVar6 != (HGLOBAL)0x0)
     ) {
    local_48 = (ushort *)LockResource(pvVar6);
  }
  pHVar5 = FindResourceW(DAT_10031344,(LPCWSTR)(uint)param_1,(LPCWSTR)0x5);
  if (pHVar5 != (HRSRC)0x0) {
    pvVar6 = LoadResource(DAT_10031344,pHVar5);
    if ((pvVar6 == (HGLOBAL)0x0) || (puVar7 = (uint *)LockResource(pvVar6), puVar7 == (uint *)0x0))
    {
      local_28 = (HWND)FUN_1000250b();
    }
    else {
      local_30 = (uint)(*(short *)((int)puVar7 + 2) == -1);
      puVar8 = (ushort *)FUN_1000dc35((int)puVar7);
      uVar2 = *puVar8;
      pDVar9 = (DWORD *)FUN_1000dc50(puVar7);
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
          uVar10 = FUN_1000f03c((int)pDVar9,local_30);
          if ((char)uVar10 == '\0') {
            if ((ushort)local_34 != 0) {
              local_38 = GetWindow(local_38,2);
            }
          }
          else {
            local_28 = (HWND)0x0;
            dwBytes = FUN_1000effe(DVar13,local_48,(int *)&local_28);
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
                  FUN_10002493(pvVar11,dwBytes,local_28,dwBytes);
                  GlobalUnlock(pvVar6);
                  CreateStreamOnHGlobal(pvVar6,1,&local_2c);
                  goto LAB_10015d7b;
                }
                local_28 = (HWND)FUN_1000250b();
              }
LAB_10015f44:
              local_8 = 0xffffffff;
              if (local_2c != (IStream *)0x0) {
                (*local_2c->lpVtbl->Release)(local_2c);
              }
              break;
            }
LAB_10015d7b:
            local_3c = 0;
            local_8 = CONCAT31(local_8._1_3_,4);
            local_28 = (HWND)FUN_1000e4b0((int *)local_2c,&local_3c);
            if (-1 < (int)local_28) {
              local_28 = (HWND)0x0;
              FUN_1001532d();
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
              FUN_1000f09b(&local_28,L"AtlAxWinLic100",*(HWND *)((int)this + 4),&local_24.left,
                           (LPCWSTR)0x0,DVar12 | 0x10000,DVar13,pHVar14,(LPVOID)0x0);
              hWnd = local_28;
              if (local_28 == (HWND)0x0) {
                local_28 = (HWND)FUN_1000250b();
              }
              else {
                if ((local_30 != 0) && (*pDVar9 != 0)) {
                  SetWindowContextHelpId(local_28,*pDVar9);
                }
                local_28 = (HWND)FUN_10014336(&local_28,(int)pDVar1,local_2c,(undefined4 *)0x0,
                                              (undefined4 *)0x0,&PTR_100234f4,0,local_3c);
                if ((int)local_28 < 0) {
                  local_8 = CONCAT31(local_8._1_3_,1);
                  Ordinal_6(local_3c);
                  goto LAB_10015f44;
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
          pDVar9 = (DWORD *)FUN_1000dcd6((int)pDVar9,local_30);
          local_34 = local_34 + 1;
        } while ((ushort)local_34 < uVar2);
      }
    }
  }
  FUN_100172f7();
  return;
}



// Function: FUN_10015f61 at 10015f61

void __cdecl FUN_10015f61(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_10015f82 at 10015f82

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __cdecl FUN_10015f82(int *param_1,undefined4 *param_2)

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
      FUN_10001000(0x8007000e);
      pcVar1 = (code *)swi(3);
      piVar3 = (int *)(*pcVar1)();
      return piVar3;
    }
  }
  return param_1;
}



// Function: FUN_10015fd4 at 10015fd4

void __cdecl FUN_10015fd4(wchar_t *param_1)

{
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(wchar_t **)param_1;
  }
  _wtol(param_1);
  return;
}



// Function: FUN_10015fec at 10015fec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10015fec(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x60) + 4) + -0x60 + param_1) =
       std::
       basic_stringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::
       vftable;
  FUN_100049d2((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x48));
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x48));
  return;
}



// Function: FUN_10016029 at 10016029

void __fastcall FUN_10016029(int param_1)

{
  FUN_10015fec(param_1 + 0x60);
                    /* WARNING: Could not recover jumptable at 0x10016037. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 0x60));
  return;
}



// Function: FUN_1001603d at 1001603d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_1001603d(void *this,byte param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined ***)this = &PTR_10023458;
    *(undefined ***)((int)this + 0x10) = &PTR_100221a4;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x60));
  }
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
             (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18));
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_stringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::
       vftable;
  FUN_10006801((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18),
               param_1);
  return (basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_100160ac at 100160ac

void * __thiscall FUN_100160ac(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x60);
  FUN_10016029((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_100160ce at 100160ce

void __cdecl FUN_100160ce(void *param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  uint uVar4;
  wchar_t *pwVar5;
  
  pwVar2 = param_2;
  if (7 < *(uint *)(param_2 + 10)) {
    param_2 = *(wchar_t **)param_2;
  }
  sVar3 = wcslen(param_2);
  for (uVar4 = FUN_100048a3(param_1,(ushort *)param_2,0,sVar3); uVar4 != 0xffffffff;
      uVar4 = FUN_100048a3(param_1,(ushort *)param_2,iVar1 + uVar4,sVar3)) {
    pwVar5 = param_3;
    if (7 < *(uint *)(param_3 + 10)) {
      pwVar5 = *(wchar_t **)param_3;
    }
    FUN_10008af1(param_1,uVar4,*(undefined4 **)(pwVar2 + 8),pwVar5);
    iVar1 = *(int *)(param_3 + 8);
    param_2 = pwVar2;
    if (7 < *(uint *)(pwVar2 + 10)) {
      param_2 = *(wchar_t **)pwVar2;
    }
    sVar3 = wcslen(param_2);
  }
  return;
}



// Function: FUN_10016152 at 10016152

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10016152(undefined2 *param_1,wchar_t *param_2)

{
  if (param_2 == (wchar_t *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    FUN_10001d86(param_1,param_2);
  }
  return param_1;
}



// Function: FUN_100161a4 at 100161a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100161a4(void *this,void *param_1)

{
  FUN_1000b3a6((void *)((int)this + 0x18),param_1);
  return param_1;
}



// Function: FUN_100161d5 at 100161d5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100161d5(void *param_1,long param_2)

{
  undefined1 local_bc [16];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_ac [80];
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_5c [72];
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_8 = 0x100161e4;
  local_14 = 0;
  FUN_1001603d(local_bc,3,1);
  local_8 = 1;
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(local_ac,param_2);
  FUN_100161a4(local_bc,param_1);
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_10015fec((int)local_5c);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_5c);
  return param_1;
}



// Function: FUN_1001623a at 1001623a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1001623a(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c [4];
  void *local_1c;
  int *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  piVar1 = (int *)((int)this + 4);
  *piVar1 = 0;
  local_8 = 1;
  *(undefined ***)this =
       TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_1c = this;
  local_18 = piVar1;
  FUN_1000173f(local_2c);
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_14[0] = 0;
  local_8._0_1_ = 3;
  if (param_2[4] == 0) {
    iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,local_14);
    FUN_100020b2(local_2c,iVar2);
  }
  else {
    piVar3 = FUN_10015f82((int *)&param_2,param_2);
    local_8._0_1_ = 4;
    FUN_10002f81(local_14,piVar3);
    local_8._0_1_ = 3;
    Ordinal_6(param_2);
  }
  local_18 = (int *)0x0;
  local_8._0_1_ = 6;
  iVar2 = (**(code **)(*param_1 + 0x28))(param_1,&local_18);
  FUN_100020b2(local_2c,iVar2);
  local_3c = (uint)local_3c._2_2_ << 0x10;
  FUN_1000c2e2(&local_3c,(CComBSTR *)local_14);
  local_8._0_1_ = 7;
  iVar2 = (**(code **)(*local_18 + 0x1c))(local_18,local_3c,uStack_38,uStack_34,uStack_30,piVar1);
  FUN_100020b2(local_2c,iVar2);
  local_8._0_1_ = 6;
  Ordinal_9(&local_3c);
  local_8._0_1_ = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6(local_14[0]);
  return (undefined4 *)this;
}



// Function: FUN_10016347 at 10016347

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_10016347(int param_1)

{
  int iVar1;
  undefined4 local_24 [4];
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10016353;
  FUN_1000173f(local_24);
  local_8 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x2c))(*(int **)(param_1 + 4),local_14);
  FUN_100020b2(local_24,iVar1);
  return local_14[0];
}



// Function: FUN_10016384 at 10016384

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10016384(undefined4 *param_1)

{
  uint3 uVar1;
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_18 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (param_1 != (undefined4 *)0x0) {
    FUN_1000cafb(&local_28,param_1);
    uVar1 = local_8._1_3_;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_24 != (int *)0x0) {
      local_30 = 7;
      local_34 = 0;
      local_44[0] = 0;
      local_8._0_1_ = 3;
      local_8._1_3_ = uVar1;
      FUN_1001623a(&local_20,local_24,(undefined4 *)local_44);
      local_8 = CONCAT31(local_8._1_3_,5);
      FID_conflict__Tidy(local_44,'\x01',0);
      if (local_1c != 0) {
        local_18 = FUN_10016347((int)&local_20);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_1000c39a(&local_20);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_1000c352(&local_28);
  }
  local_8 = 0;
  FUN_10016420();
  return;
}



// Function: Catch@10016414 at 10016414

undefined * Catch_10016414(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1001641e;
}



// Function: FUN_10016420 at 10016420

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10016420(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 8);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_1001643a at 1001643a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_1001643a(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  uStack_24 = param_3;
  uStack_34 = 3;
  uStack_2c = param_2;
                    /* WARNING: Load size is inaccurate */
  uStack_38 = param_1;
  local_8 = 0xffffffff;
  puVar1 = &uStack_3c;
  uStack_3c = 0x1001646d;
  (**(code **)(*this + 4))();
  puVar1[-1] = 0x10016472;
  return;
}



// Function: FUN_10016475 at 10016475

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10016475(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_100164a5 at 100164a5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_100164a5(void *this,undefined4 param_1,undefined4 param_2,undefined2 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uStackY_3c;
  undefined2 auStack_34 [8];
  undefined2 *puStack_24;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0;
  puStack_24 = param_3;
  param_3 = auStack_34;
  auStack_34[0] = 0;
  uStackY_3c = 0x100164d0;
  FUN_1000c2e2(param_3,(CComBSTR *)&param_2);
                    /* WARNING: Load size is inaccurate */
  local_8 = local_8 & 0xffffff00;
  puVar1 = &uStackY_3c;
  uStackY_3c = 0x100164e2;
  (**(code **)(*this + 4))();
  local_8 = 0xffffffff;
  puVar1[-1] = param_2;
  puVar2 = puVar1 + -2;
  puVar1[-2] = 0x100164ef;
  Ordinal_6();
  *(undefined4 *)((int)puVar2 + -4) = 0x100164f4;
  return;
}



// Function: FUN_100164f7 at 100164f7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100164f7(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = ECMParameter2::vftable;
  piVar1 = (int *)param_1[10];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[9];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[8];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[7];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  Ordinal_6(param_1[6]);
  FUN_1000c54c(param_1 + 4);
  FUN_1000c352(param_1 + 2);
  return;
}



// Function: FUN_100165a4 at 100165a4

undefined4 * __thiscall FUN_100165a4(void *this,byte param_1)

{
  FUN_100164f7((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100165c3 at 100165c3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100165c3(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 local_24 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0;
  local_14 = 0;
  FUN_1000173f(local_24);
  local_8 = 1;
  Ordinal_8(param_1);
  local_14 = 1;
  if (*(int *)((int)this + 4) != 0) {
    iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x28))(*(int **)((int)this + 4),param_1);
    FUN_100020b2(local_24,iVar1);
  }
  return param_1;
}



// Function: FUN_1001661d at 1001661d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1001661d(void *this,int *param_1)

{
  int iVar1;
  void *this_00;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined4 local_4c;
  int local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  undefined2 local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_38 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar1 = (**(code **)(**(int **)((int)this + 0x1c) + 0x28))(*(int **)((int)this + 0x1c),&local_38);
  if (-1 < iVar1) {
    this_00 = FUN_1000ccc4((void *)((int)this + 0x10),&local_4c);
    local_8._0_1_ = 3;
    pwVar2 = FUN_1000cdf4(this_00,local_30);
    local_8._0_1_ = 4;
    uVar3 = FUN_10015fd4(pwVar2);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_30,'\x01',0);
    local_8._0_1_ = 2;
    FUN_1000c39a(&local_4c);
    local_34 = (int *)0x0;
    local_8._0_1_ = 6;
    iVar1 = (**(code **)(*local_38 + 0x24))(local_38,uVar3,&local_34);
    if (-1 < iVar1) {
      local_3c = (int *)0x0;
      local_8._0_1_ = 8;
      iVar1 = (**(code **)(*local_34 + 0x38))(local_34,&local_3c);
      if (-1 < iVar1) {
        local_40 = (int *)0x0;
        local_8._0_1_ = 10;
        iVar1 = (**(code **)(*local_3c + 0x20))(local_3c,0,&local_40);
        if (-1 < iVar1) {
          local_44 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0xc);
          iVar1 = (**(code **)(*local_40 + 0x30))(local_40,0,&local_44);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_44 + 0x40))(local_44,&local_48);
            if (-1 < iVar1) {
              if ((local_48 == 4) || (local_48 == 5)) {
                *(undefined1 *)((int)this + 4) = 0;
              }
              else {
                *(undefined1 *)((int)this + 4) = 1;
              }
            }
          }
          local_8._0_1_ = 10;
          if (local_44 != (int *)0x0) {
            (**(code **)(*local_44 + 8))(local_44);
          }
        }
        local_8._0_1_ = 8;
        if (local_40 != (int *)0x0) {
          (**(code **)(*local_40 + 8))(local_40);
        }
      }
      local_8._0_1_ = 6;
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
    }
    local_8._0_1_ = 2;
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))(local_34);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_100172f7();
  return;
}



// Function: FUN_10016789 at 10016789

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __thiscall FUN_10016789(void *this,undefined2 *param_1)

{
  int iVar1;
  undefined4 local_34 [4];
  undefined1 local_24 [8];
  wchar_t *local_1c;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x10016795;
  local_14 = 0;
  FUN_1000173f(local_34);
  local_8 = 1;
  FUN_100165c3(this,local_24);
  local_8._0_1_ = 2;
  iVar1 = FUN_10015f61(8,(int)local_24,0,0x409);
  FUN_100020b2(local_34,iVar1);
  FUN_10016152(param_1,local_1c);
  local_14 = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_9(local_24);
  return param_1;
}



// Function: FUN_10016802 at 10016802

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_10016802(void *param_1)

{
  int iVar1;
  undefined4 local_30 [4];
  undefined1 local_20 [8];
  undefined4 local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x1001680e;
  FUN_1000173f(local_30);
  local_8 = 0;
  FUN_100165c3(param_1,local_20);
  local_8._0_1_ = 1;
  iVar1 = FUN_10015f61(3,(int)local_20,0,0x409);
  FUN_100020b2(local_30,iVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(local_20);
  return local_18;
}



// Function: FUN_10016866 at 10016866

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10016866(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  void *this_00;
  wchar_t *pwVar3;
  int *extraout_ECX;
  int *piVar4;
  undefined2 local_64 [8];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48 [2];
  void *local_40;
  int *local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x10016872;
  *(undefined ***)this = ECMParameter2::vftable;
  *(undefined1 *)((int)this + 4) = 0;
  local_40 = this;
  FUN_1000cafb((void *)((int)this + 8),param_1);
  local_8 = 0;
  FUN_1000c518((undefined4 *)((int)this + 0x10));
  *(undefined4 *)((int)this + 0x18) = 0;
  piVar1 = (int *)((int)this + 0x1c);
  *piVar1 = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  local_34 = (undefined4 *)((int)this + 0x28);
  *local_34 = 0;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = 0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_50 = 7;
  local_54 = 0;
  local_64[0] = 0;
  local_8._0_1_ = 0xc;
  puVar2 = FUN_1000cb55(&local_38,*(int **)((int)this + 0xc),(undefined4 *)local_64,
                        (undefined4 *)local_30);
  local_8._0_1_ = 0xd;
  FUN_1000c75a((void *)((int)this + 0x10),(int)puVar2);
  local_8._0_1_ = 0xc;
  FUN_1000c54c(&local_38);
  local_8._0_1_ = 0xb;
  FID_conflict__Tidy(local_64,'\x01',0);
  local_8._0_1_ = 10;
  FID_conflict__Tidy(local_30,'\x01',0);
  (**(code **)**(undefined4 **)((int)this + 0xc))();
  (**(code **)(*(int *)*piVar1 + 0x24))();
  local_3c = *(int **)((int)this + 0x20);
  this_00 = FUN_1000ccc4((void *)((int)this + 0x10),local_48);
  local_8._0_1_ = 0xe;
  pwVar3 = FUN_1000cdf4(this_00,local_30);
  local_8._0_1_ = 0xf;
  local_34 = (undefined4 *)*local_3c;
  FUN_10015fd4(pwVar3);
  (**(code **)((int)local_34 + 0x24))();
  local_8._0_1_ = 0xe;
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8._0_1_ = 10;
  FUN_1000c39a(local_48);
  (**(code **)**(undefined4 **)((int)this + 0x28))();
  local_34 = (undefined4 *)&stack0xffffff5c;
  piVar4 = extraout_ECX;
  FUN_10016475(&stack0xffffff5c,piVar1);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_1001661d(this,piVar4);
  local_8 = 0xffffffff;
  FUN_100172f7();
  return;
}



// Function: FUN_100169f3 at 100169f3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100169f3(void *this,wchar_t *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 local_38 [2];
  undefined4 local_30 [10];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x100169ff;
  FUN_10001d86(local_30,param_1);
  local_8 = 0;
  pvVar1 = FUN_1000cd2f((void *)((int)this + 0x10),local_38,local_30);
  local_8._0_1_ = 1;
  uVar2 = FUN_10016802(pvVar1);
  *param_2 = uVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000c3e2(local_38);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_10016a55 at 10016a55

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10016a55(void *this,wchar_t *param_1,void *param_2)

{
  void *this_00;
  undefined4 *puVar1;
  int *piVar2;
  undefined4 local_58 [2];
  int local_50;
  undefined2 local_4c [14];
  undefined4 local_30 [10];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x10016a61;
  FUN_10001d86(local_30,param_1);
  local_8 = 0;
  this_00 = FUN_1000cd2f((void *)((int)this + 0x10),local_58,local_30);
  local_8._0_1_ = 1;
  puVar1 = (undefined4 *)FUN_10016789(this_00,local_4c);
  local_8._0_1_ = 2;
  piVar2 = FUN_10015f82(&local_50,puVar1);
  local_8._0_1_ = 3;
  FUN_10002f81(param_2,piVar2);
  local_8._0_1_ = 2;
  Ordinal_6(local_50);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000c3e2(local_58);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100172f7();
  return;
}



// Function: FUN_10016af2 at 10016af2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10016af2(int *param_1)

{
  bool bVar1;
  undefined4 local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10016afe;
  FUN_10016a55(param_1,(wchar_t *)PTR_DAT_1002f140,(CComBSTR *)(param_1 + 6));
  local_14[0] = 0;
  local_8 = 0;
  FUN_10016a55(param_1,(wchar_t *)PTR_DAT_1002f144,local_14);
  bVar1 = ATL::CComBSTR::operator==((CComBSTR *)local_14,(CComBSTR *)(param_1 + 6));
  if (!bVar1) {
    ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffd0,(CComBSTR *)local_14);
    local_8 = local_8 & 0xffffff00;
    (**(code **)(*param_1 + 0xc))(PTR_DAT_1002f140);
  }
  local_8 = 0xffffffff;
  Ordinal_6();
  return;
}



// Function: FUN_10016b6e at 10016b6e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10016b6e(int *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = 0;
  local_8 = 0;
  FUN_10016a55(param_1,(wchar_t *)PTR_DAT_1002f144,local_14);
  bVar1 = ATL::CComBSTR::operator==((CComBSTR *)local_14,(CComBSTR *)(param_1 + 6));
  if (!bVar1) {
    iVar2 = Ordinal_7();
    if (iVar2 != 0) {
      ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffffd0,(CComBSTR *)(param_1 + 6));
      local_8 = local_8 & 0xffffff00;
      (**(code **)(*param_1 + 0xc))(PTR_DAT_1002f140);
    }
  }
  local_8 = 0xffffffff;
  Ordinal_6();
  return;
}



// Function: FUN_10016be5 at 10016be5

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10016be5(void *this,wchar_t *param_1)

{
  char in_stack_00000018;
  undefined4 local_38 [2];
  undefined4 local_30 [10];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0;
  if (in_stack_00000018 != '\0') {
    FUN_10016af2((int *)this);
  }
  FUN_10001d86(local_30,param_1);
  local_8._0_1_ = 1;
  FUN_1000d2fb((void *)((int)this + 0x10),local_38,local_30,(undefined4 *)&stack0x00000008);
  FUN_1000c3e2(local_38);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_30,'\x01',0);
  if (in_stack_00000018 != '\0') {
    FUN_10016b6e((int *)this);
  }
  local_8 = 0xffffffff;
  Ordinal_9(&stack0x00000008);
  FUN_100172f7();
  return;
}



// Function: RemoveAll at 10016c6a

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



// Function: FUN_10016c89 at 10016c89

int __fastcall FUN_10016c89(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10016cae at 10016cae

void __fastcall FUN_10016cae(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  RemoveAll((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 10016cc6

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
LAB_10016d14:
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
        goto LAB_10016d14;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_10016d23 at 10016d23

undefined4 * __fastcall FUN_10016d23(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10016c89((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10023544;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_1002f804 = 1;
  }
  return param_1;
}



// Function: FUN_10016d63 at 10016d63

void __fastcall FUN_10016d63(int *param_1)

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



// Function: FUN_10016da7 at 10016da7

int __fastcall FUN_10016da7(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10016dc0 at 10016dc0

undefined4 * __fastcall FUN_10016dc0(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10016da7((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1002b188;
  param_1[3] = &DAT_1002b188;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_1002f804 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: AtlWinModuleInit at 10016e01

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



// Function: FUN_10016e29 at 10016e29

int __fastcall FUN_10016e29(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 10016e4e

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_10016e5b:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_10016e5b;
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



// Function: FUN_10016ec4 at 10016ec4

_ATL_WIN_MODULE70 * __fastcall FUN_10016ec4(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_10016e29((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_1002f804 = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: __FreeStdCallThunk_cmn at 10016eec

/* Library Function - Single Match
    void __cdecl __FreeStdCallThunk_cmn(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void __cdecl __FreeStdCallThunk_cmn(void *param_1)

{
  HANDLE hHeap;
  DWORD dwFlags;
  
  if (DAT_100313c8 == (PSLIST_HEADER)0x1) {
    dwFlags = 0;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,param_1);
    return;
  }
  InterlockedPushEntrySList(DAT_100313c8,(PSINGLE_LIST_ENTRY)param_1);
  return;
}



// Function: __InitializeThunkPool at 10016f18

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
    DAT_100313c8 = 1;
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
  DAT_100313c8 = DVar4;
  return 1;
}



// Function: FreeStdCallThunk at 10016f86

/* Library Function - Multiple Matches With Same Base Name
    void __stdcall __FreeStdCallThunk(void *)
    void __stdcall ATL::__FreeStdCallThunk(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void FreeStdCallThunk(void *param_1)

{
  __FreeStdCallThunk_cmn(param_1);
  return;
}



// Function: __AllocStdCallThunk_cmn at 10016f98

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
  
  if ((DAT_100313c8 != (PSLIST_HEADER)0x0) || (iVar1 = __InitializeThunkPool(), iVar1 != 0)) {
    if (DAT_100313c8 == (PSLIST_HEADER)0x1) {
      dwBytes = 0xd;
      dwFlags = 0;
      hHeap = GetProcessHeap();
      pvVar2 = HeapAlloc(hHeap,dwFlags,dwBytes);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
    }
    else {
      p_Var3 = InterlockedPopEntrySList(DAT_100313c8);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        return p_Var3;
      }
      p_Var3 = (PSINGLE_LIST_ENTRY)VirtualAlloc((LPVOID)0x0,0x1000,0x1000,0x40);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        p_Var4 = InterlockedPopEntrySList(DAT_100313c8);
        if (p_Var4 != (PSINGLE_LIST_ENTRY)0x0) {
          VirtualFree(p_Var3,0,0x8000);
          return p_Var4;
        }
        p_Var4 = p_Var3 + 0x3fc;
        do {
          InterlockedPushEntrySList(DAT_100313c8,p_Var3);
          p_Var3 = p_Var3 + 4;
        } while (p_Var3 < p_Var4);
        return p_Var3;
      }
    }
  }
  return (void *)0x0;
}



// Function: FUN_10017040 at 10017040

void FUN_10017040(undefined4 param_1)

{
  (*(code *)PTR_FUN_1002f164)(param_1,0);
  return;
}



// Function: FUN_10017090 at 10017090

void FUN_10017090(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__10023554;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1002b08c);
}



// Function: _com_error at 100170d0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__10023554;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 10017110

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__10023554;
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



// Function: FUN_10017151 at 10017151

void FUN_10017151(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 100171aa

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



// Function: __security_check_cookie at 100171fc

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1002f19c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 1001720b

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002f19c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 1001723e

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002f19c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 10017274

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002f19c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 100172aa

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002f19c ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 100172e3

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



// Function: FUN_100172f7 at 100172f7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100172f7(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_10017306 at 10017306

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10017306(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __ArrayUnwind at 1001732e

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



// Function: `eh_vector_destructor_iterator' at 1001738c

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
  FUN_100173d7();
  return;
}



// Function: FUN_100173d7 at 100173d7

void FUN_100173d7(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 100173ef

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
  
  local_8 = &DAT_1002b100;
  uStack_c = 0x100173fb;
  local_20[0] = DecodePointer(DAT_1003170c);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1003170c);
    local_24 = DecodePointer(DAT_10031708);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1003170c = EncodePointer(local_20[0]);
    DAT_10031708 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10017487();
  }
  return p_Var1;
}



// Function: FUN_10017487 at 10017487

void FUN_10017487(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10017490

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 100174c0

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



// Function: `eh_vector_constructor_iterator' at 100174f2

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
  FUN_1001753f();
  return;
}



// Function: FUN_1001753f at 1001753f

void FUN_1001753f(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __alloca_probe_16 at 10017560

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



// Function: __alloca_probe_8 at 10017576

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



// Function: FUN_100175e7 at 100175e7

void __cdecl
FUN_100175e7(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1002f19c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __CRT_INIT@12 at 1001765e

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
    if (DAT_100313cc < 1) {
      return 0;
    }
    DAT_100313cc = DAT_100313cc + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10031700,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100316fc == 2) {
      param_2 = (int *)DecodePointer(DAT_1003170c);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10031708);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1003170c);
            piVar8 = (int *)DecodePointer(DAT_10031708);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10031708 = (PVOID)encoded_null();
        DAT_1003170c = DAT_10031708;
      }
      DAT_100316fc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10031700,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10031700,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_100316fc == 0) {
      DAT_100316fc = 1;
      iVar5 = initterm_e(&DAT_10020990,&DAT_10020998);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10020418,&DAT_1002098c);
      DAT_100316fc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10031700,0);
    }
    if ((DAT_10031704 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10031704), BVar2 != 0)) {
      (*DAT_10031704)(param_1,2,param_3);
    }
    DAT_100313cc = DAT_100313cc + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10017868

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10017908) */
/* WARNING: Removing unreachable block (ram,0x100178b5) */
/* WARNING: Removing unreachable block (ram,0x10017935) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1002f1b0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_100313cc == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10004712(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10004712(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_10017973();
  return local_20;
}



// Function: FUN_10017973 at 10017973

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10017973(void)

{
  _DAT_1002f1b0 = 0xffffffff;
  return;
}



// Function: entry at 1001797e

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 100179a1

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
  
  _DAT_100314e8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_100314ec = &stack0x00000004;
  _DAT_10031428 = 0x10001;
  _DAT_100313d0 = 0xc0000409;
  _DAT_100313d4 = 1;
  local_32c = DAT_1002f19c;
  local_328 = DAT_1002f1a0;
  _DAT_100313dc = unaff_retaddr;
  _DAT_100314b4 = in_GS;
  _DAT_100314b8 = in_FS;
  _DAT_100314bc = in_ES;
  _DAT_100314c0 = in_DS;
  _DAT_100314c4 = unaff_EDI;
  _DAT_100314c8 = unaff_ESI;
  _DAT_100314cc = unaff_EBX;
  _DAT_100314d0 = in_EDX;
  _DAT_100314d4 = in_ECX;
  _DAT_100314d8 = in_EAX;
  _DAT_100314dc = unaff_EBP;
  DAT_100314e0 = unaff_retaddr;
  _DAT_100314e4 = in_CS;
  _DAT_100314f0 = in_SS;
  DAT_10031420 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10023564);
  if (DAT_10031420 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10017ab0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1002f19c ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10017af5

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



// Function: __ValidateImageBase at 10017b80

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



// Function: __FindPESection at 10017bc0

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



// Function: __IsNonwritableInCurrentImage at 10017c10

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
  
  pcStack_10 = FUN_100175e7;
  local_14 = ExceptionList;
  local_c = DAT_1002f19c ^ 0x1002b168;
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



// Function: ___security_init_cookie at 10017ce4

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
  if ((DAT_1002f19c == 0xbb40e64e) || ((DAT_1002f19c & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1002f19c = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1002f19c == 0xbb40e64e) {
      DAT_1002f19c = 0xbb40e64f;
    }
    else if ((DAT_1002f19c & 0xffff0000) == 0) {
      DAT_1002f19c = DAT_1002f19c | (DAT_1002f19c | 0x4711) << 0x10;
    }
    DAT_1002f1a0 = ~DAT_1002f19c;
  }
  else {
    DAT_1002f1a0 = ~DAT_1002f19c;
  }
  return;
}



// Function: Unwind@10017d92 at 10017d92

void Unwind_10017d92(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10017d95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017db6 at 10017db6

void Unwind_10017db6(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017dd9 at 10017dd9

void Unwind_10017dd9(void)

{
  int unaff_EBP;
  
  FUN_100011b2(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017dfc at 10017dfc

void Unwind_10017dfc(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10017e21 at 10017e21

void Unwind_10017e21(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10017e29 at 10017e29

void Unwind_10017e29(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10017e31 at 10017e31

void Unwind_10017e31(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10017e39 at 10017e39

void Unwind_10017e39(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10017e77 at 10017e77

void Unwind_10017e77(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10017e9d at 10017e9d

void Unwind_10017e9d(void)

{
  int unaff_EBP;
  
  FUN_1000167c((undefined4 *)(unaff_EBP + -0x218));
  return;
}



// Function: Unwind@10017ea8 at 10017ea8

void Unwind_10017ea8(void)

{
  int unaff_EBP;
  
  FUN_1000167c((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10017edb at 10017edb

void Unwind_10017edb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x3c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + -0x40));
    return;
  }
  return;
}



// Function: Unwind@10017ef4 at 10017ef4

void Unwind_10017ef4(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10017efc at 10017efc

void Unwind_10017efc(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10017f29 at 10017f29

void Unwind_10017f29(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10017f31 at 10017f31

void Unwind_10017f31(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10017f39 at 10017f39

void Unwind_10017f39(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10017f66 at 10017f66

void Unwind_10017f66(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017f6e at 10017f6e

void Unwind_10017f6e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10017f76 at 10017f76

void Unwind_10017f76(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017f7e at 10017f7e

void Unwind_10017f7e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017f86 at 10017f86

void Unwind_10017f86(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017f8e at 10017f8e

void Unwind_10017f8e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017f96 at 10017f96

void Unwind_10017f96(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10017f9e at 10017f9e

void Unwind_10017f9e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10017fa6 at 10017fa6

void Unwind_10017fa6(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10017fae at 10017fae

void Unwind_10017fae(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017fb6 at 10017fb6

void Unwind_10017fb6(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017fbe at 10017fbe

void Unwind_10017fbe(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10017fc6 at 10017fc6

void Unwind_10017fc6(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10017fce at 10017fce

void Unwind_10017fce(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10017fd6 at 10017fd6

void Unwind_10017fd6(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10017fde at 10017fde

void Unwind_10017fde(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018001 at 10018001

void Unwind_10018001(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018009 at 10018009

void Unwind_10018009(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018011 at 10018011

void Unwind_10018011(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018019 at 10018019

void Unwind_10018019(void)

{
  int unaff_EBP;
  
  FUN_100011b2(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001803c at 1001803c

void Unwind_1001803c(void)

{
  DAT_1002f838 = DAT_1002f838 & 0xfffffffe;
  return;
}



// Function: Unwind@10018065 at 10018065

void Unwind_10018065(void)

{
  int unaff_EBP;
  
  FUN_100024f9(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100180a3 at 100180a3

void Unwind_100180a3(void)

{
  int unaff_EBP;
  
  FUN_1000c897(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100180c6 at 100180c6

void Unwind_100180c6(void)

{
  int unaff_EBP;
  
  FUN_10013cee(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100180e9 at 100180e9

void Unwind_100180e9(void)

{
  int unaff_EBP;
  
  FUN_1000404d(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001810c at 1001810c

void Unwind_1001810c(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001813f at 1001813f

void Unwind_1001813f(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10018172 at 10018172

void Unwind_10018172(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001817c at 1001817c

void Unwind_1001817c(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001819f at 1001819f

void Unwind_1001819f(void)

{
  int unaff_EBP;
  
  FUN_10002d3f((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100181c5 at 100181c5

void Unwind_100181c5(void)

{
  FUN_1000dea0();
  return;
}



// Function: Unwind@100181dc at 100181dc

void Unwind_100181dc(void)

{
  FUN_1000dea0();
  return;
}



// Function: Unwind@1001820f at 1001820f

void Unwind_1001820f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018217 at 10018217

void Unwind_10018217(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001821f at 1001821f

void Unwind_1001821f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018227 at 10018227

void Unwind_10018227(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001822f at 1001822f

void Unwind_1001822f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018237 at 10018237

void Unwind_10018237(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001825a at 1001825a

void Unwind_1001825a(void)

{
  int unaff_EBP;
  
  FUN_100037f4(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001827d at 1001827d

void Unwind_1001827d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100182d7 at 100182d7

void Unwind_100182d7(void)

{
  int unaff_EBP;
  
  FUN_1000388a(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100182fd at 100182fd

void Unwind_100182fd(void)

{
  int unaff_EBP;
  
  FUN_1000388a(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10018308 at 10018308

void Unwind_10018308(void)

{
  int unaff_EBP;
  
  FUN_10013cee(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001832b at 1001832b

void Unwind_1001832b(void)

{
  int unaff_EBP;
  
  FUN_1000499a((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001834e at 1001834e

void Unwind_1001834e(void)

{
  int unaff_EBP;
  
  FUN_1000499a((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018371 at 10018371

void Unwind_10018371(void)

{
  int unaff_EBP;
  
  FUN_1000404d(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018379 at 10018379

void Unwind_10018379(void)

{
  int unaff_EBP;
  
  FUN_10004052(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001839c at 1001839c

void Unwind_1001839c(void)

{
  int unaff_EBP;
  
  FUN_10004052(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100183a4 at 100183a4

void Unwind_100183a4(void)

{
  int unaff_EBP;
  
  FUN_1000404d(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100183c7 at 100183c7

void Unwind_100183c7(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002d12(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100183ea at 100183ea

void Unwind_100183ea(void)

{
  int unaff_EBP;
  
  FUN_10005559((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018410 at 10018410

void Unwind_10018410(void)

{
  int unaff_EBP;
  
  FUN_10002857(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1001843d at 1001843d

void Unwind_1001843d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018448 at 10018448

void Unwind_10018448(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018453 at 10018453

void Unwind_10018453(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001845e at 1001845e

void Unwind_1001845e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018469 at 10018469

void Unwind_10018469(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10018474 at 10018474

void Unwind_10018474(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x1bc));
  return;
}



// Function: Unwind@1001847f at 1001847f

void Unwind_1001847f(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1001848a at 1001848a

void Unwind_1001848a(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@10018495 at 10018495

void Unwind_10018495(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100184a0 at 100184a0

void Unwind_100184a0(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100184d3 at 100184d3

void Unwind_100184d3(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100184db at 100184db

void Unwind_100184db(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184e3 at 100184e3

void Unwind_100184e3(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184eb at 100184eb

void Unwind_100184eb(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100184f3 at 100184f3

void Unwind_100184f3(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018516 at 10018516

void Unwind_10018516(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10018521 at 10018521

void Unwind_10018521(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001852c at 1001852c

void Unwind_1001852c(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10018537 at 10018537

void Unwind_10018537(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10018542 at 10018542

void Unwind_10018542(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001854d at 1001854d

void Unwind_1001854d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10018580 at 10018580

void Unwind_10018580(void)

{
  int unaff_EBP;
  
  FUN_10004670((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100185a3 at 100185a3

void Unwind_100185a3(void)

{
  int unaff_EBP;
  
  FUN_10004670((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100185c6 at 100185c6

void Unwind_100185c6(void)

{
  int unaff_EBP;
  
  FUN_100045fb(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100185d1 at 100185d1

void Unwind_100185d1(void)

{
  int unaff_EBP;
  
  FUN_10002d3f((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100185f7 at 100185f7

void Unwind_100185f7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100185ff at 100185ff

void Unwind_100185ff(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@10018632 at 10018632

void Unwind_10018632(void)

{
  int unaff_EBP;
  
  FUN_10004d83(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018655 at 10018655

void Unwind_10018655(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001865b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10018661 at 10018661

void Unwind_10018661(void)

{
  int unaff_EBP;
  
  FUN_100049d2((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@10018687 at 10018687

void Unwind_10018687(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100186ac at 100186ac

void Unwind_100186ac(void)

{
  int unaff_EBP;
  
  FUN_10002d3f((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100186b7 at 100186b7

void Unwind_100186b7(void)

{
  int unaff_EBP;
  
  FUN_100045fb(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100186dd at 100186dd

void Unwind_100186dd(void)

{
  int unaff_EBP;
  
  FUN_1000167c((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10018710 at 10018710

void Unwind_10018710(void)

{
  int unaff_EBP;
  
  FUN_100045de((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018718 at 10018718

void Unwind_10018718(void)

{
  int unaff_EBP;
  
  FUN_100045de((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001873b at 1001873b

void Unwind_1001873b(void)

{
  int unaff_EBP;
  
  FUN_100045ee((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10018746 at 10018746

void Unwind_10018746(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10018751 at 10018751

void Unwind_10018751(void)

{
  int unaff_EBP;
  
  FUN_100045ee((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10018784 at 10018784

void Unwind_10018784(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@1001878f at 1001878f

void Unwind_1001878f(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x223c));
  return;
}



// Function: Unwind@1001879a at 1001879a

void Unwind_1001879a(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@100187a5 at 100187a5

void Unwind_100187a5(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@100187b0 at 100187b0

void Unwind_100187b0(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@100187e3 at 100187e3

void Unwind_100187e3(void)

{
  int unaff_EBP;
  
  FUN_10004670((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018806 at 10018806

void Unwind_10018806(void)

{
  int unaff_EBP;
  
  FUN_10004670((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@10018811 at 10018811

void Unwind_10018811(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001881c at 1001881c

void Unwind_1001881c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10018827 at 10018827

void Unwind_10018827(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10018832 at 10018832

void Unwind_10018832(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001883d at 1001883d

void Unwind_1001883d(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10018848 at 10018848

void Unwind_10018848(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10018853 at 10018853

void Unwind_10018853(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001885e at 1001885e

void Unwind_1001885e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10018869 at 10018869

void Unwind_10018869(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10018874 at 10018874

void Unwind_10018874(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100188a7 at 100188a7

void Unwind_100188a7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100188aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100188cb at 100188cb

void Unwind_100188cb(void)

{
  int unaff_EBP;
  
  FUN_100064f6(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100188d3 at 100188d3

void Unwind_100188d3(void)

{
  int unaff_EBP;
  
  FUN_10004d83(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100188f6 at 100188f6

void Unwind_100188f6(void)

{
  int unaff_EBP;
  
  FUN_10004d83((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100188fe at 100188fe

void Unwind_100188fe(void)

{
  int unaff_EBP;
  
  FUN_100064f6((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018906 at 10018906

void Unwind_10018906(void)

{
  int unaff_EBP;
  
  FUN_10007a6a((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001890e at 1001890e

void Unwind_1001890e(void)

{
  int unaff_EBP;
  
  FUN_100064f6((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018916 at 10018916

void Unwind_10018916(void)

{
  int unaff_EBP;
  
  FUN_10004d83((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018939 at 10018939

void Unwind_10018939(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001893c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10018942 at 10018942

void Unwind_10018942(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10018958. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@1001895f at 1001895f

void Unwind_1001895f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018965. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1001896b at 1001896b

void Unwind_1001896b(void)

{
  int unaff_EBP;
  
  FUN_100049d2((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10018991 at 10018991

void Unwind_10018991(void)

{
  int unaff_EBP;
  
  FUN_100061d6(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189b4 at 100189b4

void Unwind_100189b4(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100189bc at 100189bc

void Unwind_100189bc(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100189c4 at 100189c4

void Unwind_100189c4(void)

{
  int unaff_EBP;
  
  FUN_10004d83((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189cc at 100189cc

void Unwind_100189cc(void)

{
  int unaff_EBP;
  
  FUN_100064f6((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189d4 at 100189d4

void Unwind_100189d4(void)

{
  int unaff_EBP;
  
  FUN_10007a6a((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189dc at 100189dc

void Unwind_100189dc(void)

{
  int unaff_EBP;
  
  FUN_100064f6((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189e4 at 100189e4

void Unwind_100189e4(void)

{
  int unaff_EBP;
  
  FUN_10004d83((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189ec at 100189ec

void Unwind_100189ec(void)

{
  int unaff_EBP;
  
  FUN_100064f6((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189f4 at 100189f4

void Unwind_100189f4(void)

{
  int unaff_EBP;
  
  FUN_10004d83((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100189fc at 100189fc

void Unwind_100189fc(void)

{
  int unaff_EBP;
  
  FUN_100064f6((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a04 at 10018a04

void Unwind_10018a04(void)

{
  int unaff_EBP;
  
  FUN_10004d83((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a0c at 10018a0c

void Unwind_10018a0c(void)

{
  int unaff_EBP;
  
  FUN_100064f6((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a14 at 10018a14

void Unwind_10018a14(void)

{
  int unaff_EBP;
  
  FUN_10004d83((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018a37 at 10018a37

void Unwind_10018a37(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018a5c at 10018a5c

void Unwind_10018a5c(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@10018a67 at 10018a67

void Unwind_10018a67(void)

{
  int unaff_EBP;
  
  FUN_100045ee((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10018a9a at 10018a9a

void Unwind_10018a9a(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018abd at 10018abd

void Unwind_10018abd(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002d12(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10018ac8 at 10018ac8

void Unwind_10018ac8(void)

{
  int unaff_EBP;
  
  FUN_10005559((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10018ad3 at 10018ad3

void Unwind_10018ad3(void)

{
  int unaff_EBP;
  
  FUN_10005583((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@10018ade at 10018ade

void Unwind_10018ade(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10018b11 at 10018b11

void Unwind_10018b11(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002d12(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10018b1c at 10018b1c

void Unwind_10018b1c(void)

{
  int unaff_EBP;
  
  FUN_10005559((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@10018b27 at 10018b27

void Unwind_10018b27(void)

{
  int unaff_EBP;
  
  FUN_10005583((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10018b32 at 10018b32

void Unwind_10018b32(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10018b65 at 10018b65

void Unwind_10018b65(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018b6d at 10018b6d

void Unwind_10018b6d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018b75 at 10018b75

void Unwind_10018b75(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10018b80 at 10018b80

void Unwind_10018b80(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10018b88 at 10018b88

void Unwind_10018b88(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@10018b93 at 10018b93

void Unwind_10018b93(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10018b9b at 10018b9b

void Unwind_10018b9b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10018ba3 at 10018ba3

void Unwind_10018ba3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10018bab at 10018bab

void Unwind_10018bab(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10018bb6 at 10018bb6

void Unwind_10018bb6(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@10018be9 at 10018be9

void Unwind_10018be9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018bf1 at 10018bf1

void Unwind_10018bf1(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10018c24 at 10018c24

void Unwind_10018c24(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c51 at 10018c51

void Unwind_10018c51(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10018c5c at 10018c5c

void Unwind_10018c5c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10018c8f at 10018c8f

void Unwind_10018c8f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018c97 at 10018c97

void Unwind_10018c97(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10018cc4 at 10018cc4

void Unwind_10018cc4(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@10018ccf at 10018ccf

void Unwind_10018ccf(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@10018cda at 10018cda

void Unwind_10018cda(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10018d0d at 10018d0d

void Unwind_10018d0d(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0x44c));
  return;
}



// Function: Unwind@10018d18 at 10018d18

void Unwind_10018d18(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@10018d4b at 10018d4b

void Unwind_10018d4b(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10018d53 at 10018d53

void Unwind_10018d53(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10018d5b at 10018d5b

void Unwind_10018d5b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10018d63 at 10018d63

void Unwind_10018d63(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10018d6b at 10018d6b

void Unwind_10018d6b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10018d73 at 10018d73

void Unwind_10018d73(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10018d7b at 10018d7b

void Unwind_10018d7b(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10018da8 at 10018da8

void Unwind_10018da8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018db0 at 10018db0

void Unwind_10018db0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10018db8 at 10018db8

void Unwind_10018db8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10018dc0 at 10018dc0

void Unwind_10018dc0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10018dc8 at 10018dc8

void Unwind_10018dc8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10018dd3 at 10018dd3

void Unwind_10018dd3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10018e06 at 10018e06

void Unwind_10018e06(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018e0e at 10018e0e

void Unwind_10018e0e(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018e31 at 10018e31

void Unwind_10018e31(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018e39 at 10018e39

void Unwind_10018e39(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@10018e52 at 10018e52

void Unwind_10018e52(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018e5a at 10018e5a

void Unwind_10018e5a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018e87 at 10018e87

void Unwind_10018e87(void)

{
  FUN_1000dea0();
  return;
}



// Function: Unwind@10018ecb at 10018ecb

void Unwind_10018ecb(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10018ed3 at 10018ed3

void Unwind_10018ed3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10018edb at 10018edb

void Unwind_10018edb(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10018ee6 at 10018ee6

void Unwind_10018ee6(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10018ef1 at 10018ef1

void Unwind_10018ef1(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10018ef9 at 10018ef9

void Unwind_10018ef9(void)

{
  int unaff_EBP;
  
  FUN_10007a31(unaff_EBP + -0x138);
  return;
}



// Function: Unwind@10018f04 at 10018f04

void Unwind_10018f04(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10018f0c at 10018f0c

void Unwind_10018f0c(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10018f17 at 10018f17

void Unwind_10018f17(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10018f22 at 10018f22

void Unwind_10018f22(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10018f2d at 10018f2d

void Unwind_10018f2d(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10018f60 at 10018f60

void Unwind_10018f60(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10018f68 at 10018f68

void Unwind_10018f68(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018f70 at 10018f70

void Unwind_10018f70(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018f78 at 10018f78

void Unwind_10018f78(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018f80 at 10018f80

void Unwind_10018f80(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018f88 at 10018f88

void Unwind_10018f88(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f90 at 10018f90

void Unwind_10018f90(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f98 at 10018f98

void Unwind_10018f98(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018fa0 at 10018fa0

void Unwind_10018fa0(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018fa8 at 10018fa8

void Unwind_10018fa8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10018fb0 at 10018fb0

void Unwind_10018fb0(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10018fd3 at 10018fd3

void Unwind_10018fd3(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10018fdb at 10018fdb

void Unwind_10018fdb(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018fe3 at 10018fe3

void Unwind_10018fe3(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018feb at 10018feb

void Unwind_10018feb(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018ff3 at 10018ff3

void Unwind_10018ff3(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019031 at 10019031

void Unwind_10019031(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019039 at 10019039

void Unwind_10019039(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019066 at 10019066

void Unwind_10019066(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001906e at 1001906e

void Unwind_1001906e(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10019079 at 10019079

void Unwind_10019079(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa2c));
  return;
}



// Function: Unwind@100190ac at 100190ac

void Unwind_100190ac(void)

{
  int unaff_EBP;
  
  thunk_FUN_100026cd((undefined4 *)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@100190b7 at 100190b7

void Unwind_100190b7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa2c));
  return;
}



// Function: Unwind@100190c2 at 100190c2

void Unwind_100190c2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa48));
  return;
}



// Function: Unwind@100190f5 at 100190f5

void Unwind_100190f5(void)

{
  FUN_10004052(0x1002ff54);
  return;
}



// Function: Unwind@100190ff at 100190ff

void Unwind_100190ff(void)

{
  FUN_1000404d(0x1002ff54);
  return;
}



// Function: Unwind@10019124 at 10019124

void Unwind_10019124(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019147 at 10019147

void Unwind_10019147(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001916a at 1001916a

void Unwind_1001916a(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019175 at 10019175

void Unwind_10019175(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019180 at 10019180

void Unwind_10019180(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019188 at 10019188

void Unwind_10019188(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100191ab at 100191ab

void Unwind_100191ab(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100191b3 at 100191b3

void Unwind_100191b3(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100191bb at 100191bb

void Unwind_100191bb(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100191c3 at 100191c3

void Unwind_100191c3(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100191cb at 100191cb

void Unwind_100191cb(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100191d3 at 100191d3

void Unwind_100191d3(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@100191db at 100191db

void Unwind_100191db(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100191e3 at 100191e3

void Unwind_100191e3(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100191eb at 100191eb

void Unwind_100191eb(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001920e at 1001920e

void Unwind_1001920e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019234 at 10019234

void Unwind_10019234(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001923c at 1001923c

void Unwind_1001923c(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019247 at 10019247

void Unwind_10019247(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001924f at 1001924f

void Unwind_1001924f(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019275 at 10019275

void Unwind_10019275(void)

{
  int unaff_EBP;
  
  FUN_1000c4cd(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019298 at 10019298

void Unwind_10019298(void)

{
  int unaff_EBP;
  
  FUN_10002d3f((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100192a3 at 100192a3

void Unwind_100192a3(void)

{
  int unaff_EBP;
  
  FUN_100045fb(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@100192ae at 100192ae

void Unwind_100192ae(void)

{
  int unaff_EBP;
  
  FUN_1000c4cd(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100192b6 at 100192b6

void Unwind_100192b6(void)

{
  int unaff_EBP;
  
  FUN_1000c4cd(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100192be at 100192be

void Unwind_100192be(void)

{
  int unaff_EBP;
  
  FUN_1000c82a(*(int *)(unaff_EBP + -0x10) + 0x1c);
  return;
}



// Function: Unwind@100192e4 at 100192e4

void Unwind_100192e4(void)

{
  int unaff_EBP;
  
  FUN_100045fb(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@100192ef at 100192ef

void Unwind_100192ef(void)

{
  int unaff_EBP;
  
  FUN_1000c4cd(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100192f7 at 100192f7

void Unwind_100192f7(void)

{
  int unaff_EBP;
  
  FUN_1000c82a(*(int *)(unaff_EBP + -0x10) + 0x1c);
  return;
}



// Function: Unwind@10019302 at 10019302

void Unwind_10019302(void)

{
  int unaff_EBP;
  
  FUN_1000c4cd(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001930a at 1001930a

void Unwind_1001930a(void)

{
  int unaff_EBP;
  
  FUN_10002d3f((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019330 at 10019330

void Unwind_10019330(void)

{
  int unaff_EBP;
  
  FUN_10001994((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001935d at 1001935d

void Unwind_1001935d(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019365 at 10019365

void Unwind_10019365(void)

{
  int unaff_EBP;
  
  FUN_100164f7((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10019388 at 10019388

void Unwind_10019388(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019390 at 10019390

void Unwind_10019390(void)

{
  int unaff_EBP;
  
  FUN_100164f7((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100193b3 at 100193b3

void Unwind_100193b3(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100193d6 at 100193d6

void Unwind_100193d6(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100193de at 100193de

void Unwind_100193de(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100193e9 at 100193e9

void Unwind_100193e9(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001940c at 1001940c

void Unwind_1001940c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019414 at 10019414

void Unwind_10019414(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001941f at 1001941f

void Unwind_1001941f(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019427 at 10019427

void Unwind_10019427(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001942f at 1001942f

void Unwind_1001942f(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019437 at 10019437

void Unwind_10019437(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001943f at 1001943f

void Unwind_1001943f(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019447 at 10019447

void Unwind_10019447(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001944f at 1001944f

void Unwind_1001944f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019472 at 10019472

void Unwind_10019472(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001947a at 1001947a

void Unwind_1001947a(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001949d at 1001949d

void Unwind_1001949d(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100194a5 at 100194a5

void Unwind_100194a5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194ad at 100194ad

void Unwind_100194ad(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194b5 at 100194b5

void Unwind_100194b5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000c39a(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100194ce at 100194ce

void Unwind_100194ce(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194f1 at 100194f1

void Unwind_100194f1(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100194f9 at 100194f9

void Unwind_100194f9(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019501 at 10019501

void Unwind_10019501(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019509 at 10019509

void Unwind_10019509(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019511 at 10019511

void Unwind_10019511(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019519 at 10019519

void Unwind_10019519(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019521 at 10019521

void Unwind_10019521(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_1000c3e2(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001953a at 1001953a

void Unwind_1001953a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019542 at 10019542

void Unwind_10019542(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019565 at 10019565

void Unwind_10019565(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001956d at 1001956d

void Unwind_1001956d(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019575 at 10019575

void Unwind_10019575(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100195a9 at 100195a9

void Unwind_100195a9(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100195b1 at 100195b1

void Unwind_100195b1(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000c32d(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100195ca at 100195ca

void Unwind_100195ca(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100195d2 at 100195d2

void Unwind_100195d2(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100195f5 at 100195f5

void Unwind_100195f5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100195fd at 100195fd

void Unwind_100195fd(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019605 at 10019605

void Unwind_10019605(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001960d at 1001960d

void Unwind_1001960d(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019615 at 10019615

void Unwind_10019615(void)

{
  int unaff_EBP;
  
  FUN_10007a31(unaff_EBP + -0xd4);
  return;
}



// Function: Unwind@10019620 at 10019620

void Unwind_10019620(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019628 at 10019628

void Unwind_10019628(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019630 at 10019630

void Unwind_10019630(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019638 at 10019638

void Unwind_10019638(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019668 at 10019668

void Unwind_10019668(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019670 at 10019670

void Unwind_10019670(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001967b at 1001967b

void Unwind_1001967b(void)

{
  int unaff_EBP;
  
  FUN_1000c54c((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019686 at 10019686

void Unwind_10019686(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001968e at 1001968e

void Unwind_1001968e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019699 at 10019699

void Unwind_10019699(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100196a1 at 100196a1

void Unwind_100196a1(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@100196ac at 100196ac

void Unwind_100196ac(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100196b4 at 100196b4

void Unwind_100196b4(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@100196bf at 100196bf

void Unwind_100196bf(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100196c7 at 100196c7

void Unwind_100196c7(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@100196ed at 100196ed

void Unwind_100196ed(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x34) + 4));
  return;
}



// Function: Unwind@100196f8 at 100196f8

void Unwind_100196f8(void)

{
  int unaff_EBP;
  
  FUN_1000c54c((undefined4 *)(*(int *)(unaff_EBP + -0x34) + 8));
  return;
}



// Function: Unwind@10019703 at 10019703

void Unwind_10019703(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x34) + 0x10));
  return;
}



// Function: Unwind@1001970e at 1001970e

void Unwind_1001970e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x34) + 0x14));
  return;
}



// Function: Unwind@10019719 at 10019719

void Unwind_10019719(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x34) + 0x18));
  return;
}



// Function: Unwind@10019724 at 10019724

void Unwind_10019724(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x34) + 0x1c));
  return;
}



// Function: Unwind@1001972f at 1001972f

void Unwind_1001972f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019737 at 10019737

void Unwind_10019737(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001973f at 1001973f

void Unwind_1001973f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019747 at 10019747

void Unwind_10019747(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001974f at 1001974f

void Unwind_1001974f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019757 at 10019757

void Unwind_10019757(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001975f at 1001975f

void Unwind_1001975f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001978c at 1001978c

void Unwind_1001978c(void)

{
  int unaff_EBP;
  
  FUN_1000c3e2((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019794 at 10019794

void Unwind_10019794(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001979c at 1001979c

void Unwind_1001979c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000c32d(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100197d0 at 100197d0

void Unwind_100197d0(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100197d8 at 100197d8

void Unwind_100197d8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000c2da(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100197f1 at 100197f1

void Unwind_100197f1(void)

{
  int unaff_EBP;
  
  FUN_1000c259((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100197f9 at 100197f9

void Unwind_100197f9(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001981c at 1001981c

void Unwind_1001981c(void)

{
  int unaff_EBP;
  
  FUN_1000d0e6((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019824 at 10019824

void Unwind_10019824(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000c2da(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019858 at 10019858

void Unwind_10019858(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019860 at 10019860

void Unwind_10019860(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019868 at 10019868

void Unwind_10019868(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019870 at 10019870

void Unwind_10019870(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_1000c3e2(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019889 at 10019889

void Unwind_10019889(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019891 at 10019891

void Unwind_10019891(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100198b4 at 100198b4

void Unwind_100198b4(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100198bc at 100198bc

void Unwind_100198bc(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100198c4 at 100198c4

void Unwind_100198c4(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100198cc at 100198cc

void Unwind_100198cc(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100198d4 at 100198d4

void Unwind_100198d4(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100198dc at 100198dc

void Unwind_100198dc(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100198e4 at 100198e4

void Unwind_100198e4(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100198ec at 100198ec

void Unwind_100198ec(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100198f4 at 100198f4

void Unwind_100198f4(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100198fc at 100198fc

void Unwind_100198fc(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019904 at 10019904

void Unwind_10019904(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001990c at 1001990c

void Unwind_1001990c(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019914 at 10019914

void Unwind_10019914(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001991c at 1001991c

void Unwind_1001991c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019924 at 10019924

void Unwind_10019924(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001992c at 1001992c

void Unwind_1001992c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019934 at 10019934

void Unwind_10019934(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019957 at 10019957

void Unwind_10019957(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001995f at 1001995f

void Unwind_1001995f(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019967 at 10019967

void Unwind_10019967(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001996f at 1001996f

void Unwind_1001996f(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019977 at 10019977

void Unwind_10019977(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001997f at 1001997f

void Unwind_1001997f(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019987 at 10019987

void Unwind_10019987(void)

{
  int unaff_EBP;
  
  FUN_1000c352((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001998f at 1001998f

void Unwind_1001998f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001999a at 1001999a

void Unwind_1001999a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100199a2 at 100199a2

void Unwind_100199a2(void)

{
  int unaff_EBP;
  
  FUN_1000c54c((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100199aa at 100199aa

void Unwind_100199aa(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100199b5 at 100199b5

void Unwind_100199b5(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x74);
  return;
}



// Function: Unwind@100199bd at 100199bd

void Unwind_100199bd(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100199ed at 100199ed

void Unwind_100199ed(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100199f5 at 100199f5

void Unwind_100199f5(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100199fd at 100199fd

void Unwind_100199fd(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019a05 at 10019a05

void Unwind_10019a05(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019a0d at 10019a0d

void Unwind_10019a0d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019a15 at 10019a15

void Unwind_10019a15(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019a1d at 10019a1d

void Unwind_10019a1d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019a25 at 10019a25

void Unwind_10019a25(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019a2d at 10019a2d

void Unwind_10019a2d(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -100);
  return;
}



// Function: Unwind@10019a35 at 10019a35

void Unwind_10019a35(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019a3d at 10019a3d

void Unwind_10019a3d(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10019a45 at 10019a45

void Unwind_10019a45(void)

{
  int unaff_EBP;
  
  FUN_1000d4fb((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10019a4d at 10019a4d

void Unwind_10019a4d(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019a55 at 10019a55

void Unwind_10019a55(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019a5d at 10019a5d

void Unwind_10019a5d(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019a65 at 10019a65

void Unwind_10019a65(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10019a6d at 10019a6d

void Unwind_10019a6d(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019a75 at 10019a75

void Unwind_10019a75(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -100);
  return;
}



// Function: Unwind@10019a7d at 10019a7d

void Unwind_10019a7d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019a85 at 10019a85

void Unwind_10019a85(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019a8d at 10019a8d

void Unwind_10019a8d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019a95 at 10019a95

void Unwind_10019a95(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019a9d at 10019a9d

void Unwind_10019a9d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019aa5 at 10019aa5

void Unwind_10019aa5(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019aad at 10019aad

void Unwind_10019aad(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019ab5 at 10019ab5

void Unwind_10019ab5(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019abd at 10019abd

void Unwind_10019abd(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10019ac5 at 10019ac5

void Unwind_10019ac5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019acd at 10019acd

void Unwind_10019acd(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019ad5 at 10019ad5

void Unwind_10019ad5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019add at 10019add

void Unwind_10019add(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019ae5 at 10019ae5

void Unwind_10019ae5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019aed at 10019aed

void Unwind_10019aed(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019af5 at 10019af5

void Unwind_10019af5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019afd at 10019afd

void Unwind_10019afd(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019b05 at 10019b05

void Unwind_10019b05(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019b0d at 10019b0d

void Unwind_10019b0d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019b15 at 10019b15

void Unwind_10019b15(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019b38 at 10019b38

void Unwind_10019b38(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019b40 at 10019b40

void Unwind_10019b40(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019b7e at 10019b7e

void Unwind_10019b7e(void)

{
  int unaff_EBP;
  
  FUN_1000dd39((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10019ba4 at 10019ba4

void Unwind_10019ba4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019ba7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019be3 at 10019be3

void Unwind_10019be3(void)

{
  int unaff_EBP;
  
  FUN_1000dd39((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@10019bee at 10019bee

void Unwind_10019bee(void)

{
  int unaff_EBP;
  
  FUN_1000de7a(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10019c14 at 10019c14

void Unwind_10019c14(void)

{
  int unaff_EBP;
  
  FUN_1000de7a(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10019c1f at 10019c1f

void Unwind_10019c1f(void)

{
  int unaff_EBP;
  
  FUN_1000dd39((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10019c45 at 10019c45

void Unwind_10019c45(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019c68 at 10019c68

void Unwind_10019c68(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019c73 at 10019c73

void Unwind_10019c73(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019c96 at 10019c96

void Unwind_10019c96(void)

{
  FUN_1000dea0();
  return;
}



// Function: Unwind@10019cc8 at 10019cc8

void Unwind_10019cc8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019cd0 at 10019cd0

void Unwind_10019cd0(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019cdb at 10019cdb

void Unwind_10019cdb(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019ce3 at 10019ce3

void Unwind_10019ce3(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10019cee at 10019cee

void Unwind_10019cee(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019d14 at 10019d14

void Unwind_10019d14(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019d1f at 10019d1f

void Unwind_10019d1f(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10019d2a at 10019d2a

void Unwind_10019d2a(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019d35 at 10019d35

void Unwind_10019d35(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019d3d at 10019d3d

void Unwind_10019d3d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019d60 at 10019d60

void Unwind_10019d60(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x3fc));
  return;
}



// Function: Unwind@10019d93 at 10019d93

void Unwind_10019d93(void)

{
  int unaff_EBP;
  
  FUN_1000de36(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019d9e at 10019d9e

void Unwind_10019d9e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10019da9 at 10019da9

void Unwind_10019da9(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@10019db4 at 10019db4

void Unwind_10019db4(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10019dbf at 10019dbf

void Unwind_10019dbf(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10019dca at 10019dca

void Unwind_10019dca(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019dd2 at 10019dd2

void Unwind_10019dd2(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019dda at 10019dda

void Unwind_10019dda(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019de2 at 10019de2

void Unwind_10019de2(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e05 at 10019e05

void Unwind_10019e05(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e0d at 10019e0d

void Unwind_10019e0d(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019e30 at 10019e30

void Unwind_10019e30(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019e38 at 10019e38

void Unwind_10019e38(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e40 at 10019e40

void Unwind_10019e40(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019e4b at 10019e4b

void Unwind_10019e4b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e53 at 10019e53

void Unwind_10019e53(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10019e5e at 10019e5e

void Unwind_10019e5e(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019e9f at 10019e9f

void Unwind_10019e9f(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019ea7 at 10019ea7

void Unwind_10019ea7(void)

{
  int unaff_EBP;
  
  FUN_1000e27a(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@10019eb2 at 10019eb2

void Unwind_10019eb2(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@10019ebd at 10019ebd

void Unwind_10019ebd(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@10019ec8 at 10019ec8

void Unwind_10019ec8(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@10019ed3 at 10019ed3

void Unwind_10019ed3(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@10019ede at 10019ede

void Unwind_10019ede(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@10019ee9 at 10019ee9

void Unwind_10019ee9(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@10019ef4 at 10019ef4

void Unwind_10019ef4(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@10019eff at 10019eff

void Unwind_10019eff(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@10019f0a at 10019f0a

void Unwind_10019f0a(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@10019f15 at 10019f15

void Unwind_10019f15(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@10019f23 at 10019f23

void Unwind_10019f23(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@10019f31 at 10019f31

void Unwind_10019f31(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe8));
  return;
}



// Function: Unwind@10019f3f at 10019f3f

void Unwind_10019f3f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f47 at 10019f47

void Unwind_10019f47(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f4f at 10019f4f

void Unwind_10019f4f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f57 at 10019f57

void Unwind_10019f57(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f5f at 10019f5f

void Unwind_10019f5f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f67 at 10019f67

void Unwind_10019f67(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f6f at 10019f6f

void Unwind_10019f6f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f77 at 10019f77

void Unwind_10019f77(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f7f at 10019f7f

void Unwind_10019f7f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f87 at 10019f87

void Unwind_10019f87(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f8f at 10019f8f

void Unwind_10019f8f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019f97 at 10019f97

void Unwind_10019f97(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019f9f at 10019f9f

void Unwind_10019f9f(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019fc2 at 10019fc2

void Unwind_10019fc2(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019fca at 10019fca

void Unwind_10019fca(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019fed at 10019fed

void Unwind_10019fed(void)

{
  int unaff_EBP;
  
  FUN_1000de36(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019ff8 at 10019ff8

void Unwind_10019ff8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a000 at 1001a000

void Unwind_1001a000(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001a00b at 1001a00b

void Unwind_1001a00b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a013 at 1001a013

void Unwind_1001a013(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@1001a01e at 1001a01e

void Unwind_1001a01e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a026 at 1001a026

void Unwind_1001a026(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001a031 at 1001a031

void Unwind_1001a031(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a039 at 1001a039

void Unwind_1001a039(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001a05f at 1001a05f

void Unwind_1001a05f(void)

{
  int unaff_EBP;
  
  FUN_1000e494(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a082 at 1001a082

void Unwind_1001a082(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a08a at 1001a08a

void Unwind_1001a08a(void)

{
  int unaff_EBP;
  
  FUN_100011b2(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a092 at 1001a092

void Unwind_1001a092(void)

{
  int unaff_EBP;
  
  FUN_1000e33c((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001a09d at 1001a09d

void Unwind_1001a09d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1001a0a8 at 1001a0a8

void Unwind_1001a0a8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a0b0 at 1001a0b0

void Unwind_1001a0b0(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1001a0bb at 1001a0bb

void Unwind_1001a0bb(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a0c3 at 1001a0c3

void Unwind_1001a0c3(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001a0e9 at 1001a0e9

void Unwind_1001a0e9(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a0f1 at 1001a0f1

void Unwind_1001a0f1(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a0f9 at 1001a0f9

void Unwind_1001a0f9(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a11c at 1001a11c

void Unwind_1001a11c(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a124 at 1001a124

void Unwind_1001a124(void)

{
  int unaff_EBP;
  
  FUN_1000e33c((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001a12f at 1001a12f

void Unwind_1001a12f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1001a13a at 1001a13a

void Unwind_1001a13a(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1001a145 at 1001a145

void Unwind_1001a145(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001a150 at 1001a150

void Unwind_1001a150(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a158 at 1001a158

void Unwind_1001a158(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a160 at 1001a160

void Unwind_1001a160(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a168 at 1001a168

void Unwind_1001a168(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a18b at 1001a18b

void Unwind_1001a18b(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a193 at 1001a193

void Unwind_1001a193(void)

{
  int unaff_EBP;
  
  FUN_1000e0ba((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a1b6 at 1001a1b6

void Unwind_1001a1b6(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a1be at 1001a1be

void Unwind_1001a1be(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a1c6 at 1001a1c6

void Unwind_1001a1c6(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a1ce at 1001a1ce

void Unwind_1001a1ce(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001a1d9 at 1001a1d9

void Unwind_1001a1d9(void)

{
  int unaff_EBP;
  
  FUN_1000e27a(*(int *)(unaff_EBP + -0x10) + 0x38);
  return;
}



// Function: Unwind@1001a1e4 at 1001a1e4

void Unwind_1001a1e4(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a1ec at 1001a1ec

void Unwind_1001a1ec(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x54));
  return;
}



// Function: Unwind@1001a1f7 at 1001a1f7

void Unwind_1001a1f7(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a1ff at 1001a1ff

void Unwind_1001a1ff(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x60));
  return;
}



// Function: Unwind@1001a20a at 1001a20a

void Unwind_1001a20a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a212 at 1001a212

void Unwind_1001a212(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 100));
  return;
}



// Function: Unwind@1001a21d at 1001a21d

void Unwind_1001a21d(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a225 at 1001a225

void Unwind_1001a225(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001a230 at 1001a230

void Unwind_1001a230(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a238 at 1001a238

void Unwind_1001a238(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001a243 at 1001a243

void Unwind_1001a243(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a24b at 1001a24b

void Unwind_1001a24b(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@1001a256 at 1001a256

void Unwind_1001a256(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a25e at 1001a25e

void Unwind_1001a25e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001a269 at 1001a269

void Unwind_1001a269(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a271 at 1001a271

void Unwind_1001a271(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@1001a27c at 1001a27c

void Unwind_1001a27c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a284 at 1001a284

void Unwind_1001a284(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@1001a28f at 1001a28f

void Unwind_1001a28f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a297 at 1001a297

void Unwind_1001a297(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@1001a2a5 at 1001a2a5

void Unwind_1001a2a5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a2ad at 1001a2ad

void Unwind_1001a2ad(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@1001a2bb at 1001a2bb

void Unwind_1001a2bb(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xe8));
  return;
}



// Function: Unwind@1001a2e4 at 1001a2e4

void Unwind_1001a2e4(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001a314 at 1001a314

void Unwind_1001a314(void)

{
  int unaff_EBP;
  
  FUN_1000c32d(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a31c at 1001a31c

void Unwind_1001a31c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a33f at 1001a33f

void Unwind_1001a33f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a347 at 1001a347

void Unwind_1001a347(void)

{
  int unaff_EBP;
  
  FUN_1000c32d(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a36a at 1001a36a

void Unwind_1001a36a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a372 at 1001a372

void Unwind_1001a372(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a3b3 at 1001a3b3

void Unwind_1001a3b3(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a3bb at 1001a3bb

void Unwind_1001a3bb(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a3c3 at 1001a3c3

void Unwind_1001a3c3(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a3f0 at 1001a3f0

void Unwind_1001a3f0(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a3f8 at 1001a3f8

void Unwind_1001a3f8(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a400 at 1001a400

void Unwind_1001a400(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a408 at 1001a408

void Unwind_1001a408(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a410 at 1001a410

void Unwind_1001a410(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a433 at 1001a433

void Unwind_1001a433(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a43b at 1001a43b

void Unwind_1001a43b(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a443 at 1001a443

void Unwind_1001a443(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a466 at 1001a466

void Unwind_1001a466(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a489 at 1001a489

void Unwind_1001a489(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a491 at 1001a491

void Unwind_1001a491(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a499 at 1001a499

void Unwind_1001a499(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a4bc at 1001a4bc

void Unwind_1001a4bc(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a4c4 at 1001a4c4

void Unwind_1001a4c4(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a4e7 at 1001a4e7

void Unwind_1001a4e7(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a4ef at 1001a4ef

void Unwind_1001a4ef(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a4f7 at 1001a4f7

void Unwind_1001a4f7(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a51a at 1001a51a

void Unwind_1001a51a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a522 at 1001a522

void Unwind_1001a522(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a52a at 1001a52a

void Unwind_1001a52a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a532 at 1001a532

void Unwind_1001a532(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a53a at 1001a53a

void Unwind_1001a53a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a542 at 1001a542

void Unwind_1001a542(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a565 at 1001a565

void Unwind_1001a565(void)

{
  int unaff_EBP;
  
  FUN_10010926(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a588 at 1001a588

void Unwind_1001a588(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a590 at 1001a590

void Unwind_1001a590(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001a59b at 1001a59b

void Unwind_1001a59b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a5a3 at 1001a5a3

void Unwind_1001a5a3(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a5ab at 1001a5ab

void Unwind_1001a5ab(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a5ce at 1001a5ce

void Unwind_1001a5ce(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a5d6 at 1001a5d6

void Unwind_1001a5d6(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a5de at 1001a5de

void Unwind_1001a5de(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a5e6 at 1001a5e6

void Unwind_1001a5e6(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001a60c at 1001a60c

void Unwind_1001a60c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001a614 at 1001a614

void Unwind_1001a614(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001a61c at 1001a61c

void Unwind_1001a61c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1001a63f at 1001a63f

void Unwind_1001a63f(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a647 at 1001a647

void Unwind_1001a647(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a64f at 1001a64f

void Unwind_1001a64f(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a672 at 1001a672

void Unwind_1001a672(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a67a at 1001a67a

void Unwind_1001a67a(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a682 at 1001a682

void Unwind_1001a682(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a68a at 1001a68a

void Unwind_1001a68a(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a692 at 1001a692

void Unwind_1001a692(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a69a at 1001a69a

void Unwind_1001a69a(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a6a2 at 1001a6a2

void Unwind_1001a6a2(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a6aa at 1001a6aa

void Unwind_1001a6aa(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6b2 at 1001a6b2

void Unwind_1001a6b2(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6ba at 1001a6ba

void Unwind_1001a6ba(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6c2 at 1001a6c2

void Unwind_1001a6c2(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6ca at 1001a6ca

void Unwind_1001a6ca(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6d2 at 1001a6d2

void Unwind_1001a6d2(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6da at 1001a6da

void Unwind_1001a6da(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6e2 at 1001a6e2

void Unwind_1001a6e2(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a6ea at 1001a6ea

void Unwind_1001a6ea(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6f2 at 1001a6f2

void Unwind_1001a6f2(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6fa at 1001a6fa

void Unwind_1001a6fa(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a702 at 1001a702

void Unwind_1001a702(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a70a at 1001a70a

void Unwind_1001a70a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a712 at 1001a712

void Unwind_1001a712(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a71a at 1001a71a

void Unwind_1001a71a(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a722 at 1001a722

void Unwind_1001a722(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a745 at 1001a745

void Unwind_1001a745(void)

{
  int unaff_EBP;
  
  FUN_10011661(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a768 at 1001a768

void Unwind_1001a768(void)

{
  int unaff_EBP;
  
  FUN_10011661(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a770 at 1001a770

void Unwind_1001a770(void)

{
  int unaff_EBP;
  
  FUN_10010926(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a793 at 1001a793

void Unwind_1001a793(void)

{
  int unaff_EBP;
  
  FUN_1000ea53(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a7d1 at 1001a7d1

void Unwind_1001a7d1(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001a7d9 at 1001a7d9

void Unwind_1001a7d9(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001a7e1 at 1001a7e1

void Unwind_1001a7e1(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001a7e9 at 1001a7e9

void Unwind_1001a7e9(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001a7f1 at 1001a7f1

void Unwind_1001a7f1(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a7f9 at 1001a7f9

void Unwind_1001a7f9(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a801 at 1001a801

void Unwind_1001a801(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001a809 at 1001a809

void Unwind_1001a809(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x20));
  return;
}



// Function: Unwind@1001a811 at 1001a811

void Unwind_1001a811(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x24));
  return;
}



// Function: Unwind@1001a819 at 1001a819

void Unwind_1001a819(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@1001a821 at 1001a821

void Unwind_1001a821(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@1001a829 at 1001a829

void Unwind_1001a829(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001a831 at 1001a831

void Unwind_1001a831(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@1001a839 at 1001a839

void Unwind_1001a839(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 0x18));
  return;
}



// Function: Unwind@1001a892 at 1001a892

void Unwind_1001a892(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a89a at 1001a89a

void Unwind_1001a89a(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000c32d((int *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a8b3 at 1001a8b3

void Unwind_1001a8b3(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a8bb at 1001a8bb

void Unwind_1001a8bb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_1000c32d((int *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a8d4 at 1001a8d4

void Unwind_1001a8d4(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a8dc at 1001a8dc

void Unwind_1001a8dc(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a8ff at 1001a8ff

void Unwind_1001a8ff(void)

{
  int unaff_EBP;
  
  FUN_10004670((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a922 at 1001a922

void Unwind_1001a922(void)

{
  int unaff_EBP;
  
  FUN_1001167f(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a960 at 1001a960

void Unwind_1001a960(void)

{
  int unaff_EBP;
  
  FUN_1000e494(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a983 at 1001a983

void Unwind_1001a983(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001a98b at 1001a98b

void Unwind_1001a98b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001a993 at 1001a993

void Unwind_1001a993(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001a99b at 1001a99b

void Unwind_1001a99b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a9a3 at 1001a9a3

void Unwind_1001a9a3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a9ab at 1001a9ab

void Unwind_1001a9ab(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001a9b3 at 1001a9b3

void Unwind_1001a9b3(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001a9e0 at 1001a9e0

void Unwind_1001a9e0(void)

{
  int unaff_EBP;
  
  FUN_1000e0ba((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001a9e8 at 1001a9e8

void Unwind_1001a9e8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001aa1a at 1001aa1a

void Unwind_1001aa1a(void)

{
  int unaff_EBP;
  
  FUN_1000ef04(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001aa40 at 1001aa40

void Unwind_1001aa40(void)

{
  int unaff_EBP;
  
  FUN_1000ef04(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001aa4b at 1001aa4b

void Unwind_1001aa4b(void)

{
  int unaff_EBP;
  
  FUN_1000ea53(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aa6e at 1001aa6e

void Unwind_1001aa6e(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001aa76 at 1001aa76

void Unwind_1001aa76(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aa99 at 1001aa99

void Unwind_1001aa99(void)

{
  int unaff_EBP;
  
  FUN_10013117((int *)(*(int *)(unaff_EBP + -0x14) + 0x5c));
  return;
}



// Function: Unwind@1001aabf at 1001aabf

void Unwind_1001aabf(void)

{
  int unaff_EBP;
  
  FUN_10013117((int *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1001aae5 at 1001aae5

void Unwind_1001aae5(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aaed at 1001aaed

void Unwind_1001aaed(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aaf5 at 1001aaf5

void Unwind_1001aaf5(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001ab00 at 1001ab00

void Unwind_1001ab00(void)

{
  int unaff_EBP;
  
  FUN_1000e781(*(int *)(unaff_EBP + -0x10) + 0x24);
  return;
}



// Function: Unwind@1001ab0b at 1001ab0b

void Unwind_1001ab0b(void)

{
  int unaff_EBP;
  
  FUN_10013a72((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001ab16 at 1001ab16

void Unwind_1001ab16(void)

{
  int unaff_EBP;
  
  FUN_1000e3f5((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@1001ab24 at 1001ab24

void Unwind_1001ab24(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0xfc));
  return;
}



// Function: Unwind@1001ab32 at 1001ab32

void Unwind_1001ab32(void)

{
  int unaff_EBP;
  
  FUN_1000e2b9((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x118));
  return;
}



// Function: Unwind@1001ab40 at 1001ab40

void Unwind_1001ab40(void)

{
  int unaff_EBP;
  
  FUN_1000e2b9((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x11c));
  return;
}



// Function: Unwind@1001ab4e at 1001ab4e

void Unwind_1001ab4e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ab56 at 1001ab56

void Unwind_1001ab56(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x120));
  return;
}



// Function: Unwind@1001ab7f at 1001ab7f

void Unwind_1001ab7f(void)

{
  int unaff_EBP;
  
  FUN_1000ebb8(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001ab8a at 1001ab8a

void Unwind_1001ab8a(void)

{
  int unaff_EBP;
  
  FUN_1000e781(*(int *)(unaff_EBP + -0x10) + 0x24);
  return;
}



// Function: Unwind@1001ab95 at 1001ab95

void Unwind_1001ab95(void)

{
  int unaff_EBP;
  
  FUN_10013a72((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001aba0 at 1001aba0

void Unwind_1001aba0(void)

{
  int unaff_EBP;
  
  FUN_1000e3f5((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@1001abae at 1001abae

void Unwind_1001abae(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0xfc));
  return;
}



// Function: Unwind@1001abbc at 1001abbc

void Unwind_1001abbc(void)

{
  int unaff_EBP;
  
  FUN_1000e2b9((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x118));
  return;
}



// Function: Unwind@1001abca at 1001abca

void Unwind_1001abca(void)

{
  int unaff_EBP;
  
  FUN_1000e2b9((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x11c));
  return;
}



// Function: Unwind@1001abd8 at 1001abd8

void Unwind_1001abd8(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x120));
  return;
}



// Function: Unwind@1001abe6 at 1001abe6

void Unwind_1001abe6(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001abee at 1001abee

void Unwind_1001abee(void)

{
  int unaff_EBP;
  
  FUN_1000e884(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001abf6 at 1001abf6

void Unwind_1001abf6(void)

{
  int unaff_EBP;
  
  FUN_1000e21c(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ac19 at 1001ac19

void Unwind_1001ac19(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ac3e at 1001ac3e

void Unwind_1001ac3e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ac46 at 1001ac46

void Unwind_1001ac46(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ac4e at 1001ac4e

void Unwind_1001ac4e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ac56 at 1001ac56

void Unwind_1001ac56(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ac5e at 1001ac5e

void Unwind_1001ac5e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ac66 at 1001ac66

void Unwind_1001ac66(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ac6e at 1001ac6e

void Unwind_1001ac6e(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001ac76 at 1001ac76

void Unwind_1001ac76(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ac7e at 1001ac7e

void Unwind_1001ac7e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ac86 at 1001ac86

void Unwind_1001ac86(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aca9 at 1001aca9

void Unwind_1001aca9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001acf8 at 1001acf8

void Unwind_1001acf8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ad00 at 1001ad00

void Unwind_1001ad00(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ad08 at 1001ad08

void Unwind_1001ad08(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ad10 at 1001ad10

void Unwind_1001ad10(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad18 at 1001ad18

void Unwind_1001ad18(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad20 at 1001ad20

void Unwind_1001ad20(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad28 at 1001ad28

void Unwind_1001ad28(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ad4b at 1001ad4b

void Unwind_1001ad4b(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001ad53 at 1001ad53

void Unwind_1001ad53(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ad5b at 1001ad5b

void Unwind_1001ad5b(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ad63 at 1001ad63

void Unwind_1001ad63(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ad6b at 1001ad6b

void Unwind_1001ad6b(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ad73 at 1001ad73

void Unwind_1001ad73(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad7b at 1001ad7b

void Unwind_1001ad7b(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad83 at 1001ad83

void Unwind_1001ad83(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001ad8b at 1001ad8b

void Unwind_1001ad8b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad93 at 1001ad93

void Unwind_1001ad93(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ad9b at 1001ad9b

void Unwind_1001ad9b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001adbe at 1001adbe

void Unwind_1001adbe(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001adc6 at 1001adc6

void Unwind_1001adc6(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001adce at 1001adce

void Unwind_1001adce(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001add6 at 1001add6

void Unwind_1001add6(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001adde at 1001adde

void Unwind_1001adde(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ade6 at 1001ade6

void Unwind_1001ade6(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001adee at 1001adee

void Unwind_1001adee(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001adf6 at 1001adf6

void Unwind_1001adf6(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001adfe at 1001adfe

void Unwind_1001adfe(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ae06 at 1001ae06

void Unwind_1001ae06(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ae0e at 1001ae0e

void Unwind_1001ae0e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ae16 at 1001ae16

void Unwind_1001ae16(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001ae1e at 1001ae1e

void Unwind_1001ae1e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ae26 at 1001ae26

void Unwind_1001ae26(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001ae2e at 1001ae2e

void Unwind_1001ae2e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae36 at 1001ae36

void Unwind_1001ae36(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ae59 at 1001ae59

void Unwind_1001ae59(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001ae7c at 1001ae7c

void Unwind_1001ae7c(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1001ae84 at 1001ae84

void Unwind_1001ae84(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001ae8c at 1001ae8c

void Unwind_1001ae8c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001aeb9 at 1001aeb9

void Unwind_1001aeb9(void)

{
  int unaff_EBP;
  
  FUN_1000c32d(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aedc at 1001aedc

void Unwind_1001aedc(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001aee4 at 1001aee4

void Unwind_1001aee4(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aeec at 1001aeec

void Unwind_1001aeec(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aef4 at 1001aef4

void Unwind_1001aef4(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aefc at 1001aefc

void Unwind_1001aefc(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001af04 at 1001af04

void Unwind_1001af04(void)

{
  int unaff_EBP;
  
  FUN_100106ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001af0c at 1001af0c

void Unwind_1001af0c(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@1001af14 at 1001af14

void Unwind_1001af14(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001af1c at 1001af1c

void Unwind_1001af1c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001af24 at 1001af24

void Unwind_1001af24(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001af2c at 1001af2c

void Unwind_1001af2c(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001af4f at 1001af4f

void Unwind_1001af4f(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001af72 at 1001af72

void Unwind_1001af72(void)

{
  int unaff_EBP;
  
  FUN_10007a31(unaff_EBP + -0xcc);
  return;
}



// Function: Unwind@1001af7d at 1001af7d

void Unwind_1001af7d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001af85 at 1001af85

void Unwind_1001af85(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001afb5 at 1001afb5

void Unwind_1001afb5(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001afbd at 1001afbd

void Unwind_1001afbd(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001afc5 at 1001afc5

void Unwind_1001afc5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001afcd at 1001afcd

void Unwind_1001afcd(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001afd5 at 1001afd5

void Unwind_1001afd5(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aff8 at 1001aff8

void Unwind_1001aff8(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b000 at 1001b000

void Unwind_1001b000(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b008 at 1001b008

void Unwind_1001b008(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b010 at 1001b010

void Unwind_1001b010(void)

{
  int unaff_EBP;
  
  FUN_100011b2(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b033 at 1001b033

void Unwind_1001b033(void)

{
  int unaff_EBP;
  
  FUN_1000e2a9((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b03b at 1001b03b

void Unwind_1001b03b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b043 at 1001b043

void Unwind_1001b043(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b04b at 1001b04b

void Unwind_1001b04b(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b053 at 1001b053

void Unwind_1001b053(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b05b at 1001b05b

void Unwind_1001b05b(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b063 at 1001b063

void Unwind_1001b063(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b06b at 1001b06b

void Unwind_1001b06b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b073 at 1001b073

void Unwind_1001b073(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b07b at 1001b07b

void Unwind_1001b07b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b083 at 1001b083

void Unwind_1001b083(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b08b at 1001b08b

void Unwind_1001b08b(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b0b8 at 1001b0b8

void Unwind_1001b0b8(void)

{
  int unaff_EBP;
  
  FUN_1000e2a9((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b0c0 at 1001b0c0

void Unwind_1001b0c0(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b0c8 at 1001b0c8

void Unwind_1001b0c8(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b0d0 at 1001b0d0

void Unwind_1001b0d0(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b0d8 at 1001b0d8

void Unwind_1001b0d8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b0e0 at 1001b0e0

void Unwind_1001b0e0(void)

{
  int unaff_EBP;
  
  FUN_1000128f((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b0e8 at 1001b0e8

void Unwind_1001b0e8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b0f0 at 1001b0f0

void Unwind_1001b0f0(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b0f8 at 1001b0f8

void Unwind_1001b0f8(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b100 at 1001b100

void Unwind_1001b100(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b108 at 1001b108

void Unwind_1001b108(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b110 at 1001b110

void Unwind_1001b110(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b118 at 1001b118

void Unwind_1001b118(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b120 at 1001b120

void Unwind_1001b120(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b14d at 1001b14d

void Unwind_1001b14d(void)

{
  int unaff_EBP;
  
  FUN_10004670((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b170 at 1001b170

void Unwind_1001b170(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b193 at 1001b193

void Unwind_1001b193(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -400));
  return;
}



// Function: Unwind@1001b19e at 1001b19e

void Unwind_1001b19e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001b1a9 at 1001b1a9

void Unwind_1001b1a9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001b1b4 at 1001b1b4

void Unwind_1001b1b4(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b1bc at 1001b1bc

void Unwind_1001b1bc(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b1c4 at 1001b1c4

void Unwind_1001b1c4(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b1cc at 1001b1cc

void Unwind_1001b1cc(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000dd8c(unaff_EBP + -0x19c);
  return;
}



// Function: Unwind@1001b1d7 at 1001b1d7

void Unwind_1001b1d7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b1df at 1001b1df

void Unwind_1001b1df(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b1e7 at 1001b1e7

void Unwind_1001b1e7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b1ef at 1001b1ef

void Unwind_1001b1ef(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b1f7 at 1001b1f7

void Unwind_1001b1f7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b1ff at 1001b1ff

void Unwind_1001b1ff(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001b20a at 1001b20a

void Unwind_1001b20a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@1001b215 at 1001b215

void Unwind_1001b215(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001b220 at 1001b220

void Unwind_1001b220(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b228 at 1001b228

void Unwind_1001b228(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b230 at 1001b230

void Unwind_1001b230(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b238 at 1001b238

void Unwind_1001b238(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@1001b243 at 1001b243

void Unwind_1001b243(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b24b at 1001b24b

void Unwind_1001b24b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b253 at 1001b253

void Unwind_1001b253(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b25b at 1001b25b

void Unwind_1001b25b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x110));
  return;
}



// Function: Unwind@1001b266 at 1001b266

void Unwind_1001b266(void)

{
  int unaff_EBP;
  
  FUN_1000f19b((undefined4 *)(unaff_EBP + -0x174));
  return;
}



// Function: Unwind@1001b271 at 1001b271

void Unwind_1001b271(void)

{
  int unaff_EBP;
  
  FUN_1000c32d(*(int **)(unaff_EBP + -0x178));
  return;
}



// Function: Unwind@1001b27c at 1001b27c

void Unwind_1001b27c(void)

{
  int unaff_EBP;
  
  FUN_1000c32d(*(int **)(unaff_EBP + -0x180));
  return;
}



// Function: Unwind@1001b2af at 1001b2af

void Unwind_1001b2af(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b2b7 at 1001b2b7

void Unwind_1001b2b7(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b2bf at 1001b2bf

void Unwind_1001b2bf(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001b2c7 at 1001b2c7

void Unwind_1001b2c7(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b2cf at 1001b2cf

void Unwind_1001b2cf(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b2d7 at 1001b2d7

void Unwind_1001b2d7(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b2df at 1001b2df

void Unwind_1001b2df(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b30c at 1001b30c

void Unwind_1001b30c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100011b2(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b340 at 1001b340

void Unwind_1001b340(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b346. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001b34c at 1001b34c

void Unwind_1001b34c(void)

{
  int unaff_EBP;
  
  FUN_100049d2((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001b372 at 1001b372

void Unwind_1001b372(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001b388. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x60));
    return;
  }
  return;
}



// Function: Unwind@1001b38f at 1001b38f

void Unwind_1001b38f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b395. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001b39b at 1001b39b

void Unwind_1001b39b(void)

{
  int unaff_EBP;
  
  FUN_100049d2((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001b3c1 at 1001b3c1

void Unwind_1001b3c1(void)

{
  int unaff_EBP;
  
  FUN_10016029(unaff_EBP + -0xb8);
  return;
}



// Function: Unwind@1001b3cc at 1001b3cc

void Unwind_1001b3cc(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b403 at 1001b403

void Unwind_1001b403(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b40b at 1001b40b

void Unwind_1001b40b(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001b416 at 1001b416

void Unwind_1001b416(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b41e at 1001b41e

void Unwind_1001b41e(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b426 at 1001b426

void Unwind_1001b426(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b42e at 1001b42e

void Unwind_1001b42e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b436 at 1001b436

void Unwind_1001b436(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b43e at 1001b43e

void Unwind_1001b43e(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001b446 at 1001b446

void Unwind_1001b446(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b469 at 1001b469

void Unwind_1001b469(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b48c at 1001b48c

void Unwind_1001b48c(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b494 at 1001b494

void Unwind_1001b494(void)

{
  int unaff_EBP;
  
  FUN_1000c352((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b49c at 1001b49c

void Unwind_1001b49c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001b4a4 at 1001b4a4

void Unwind_1001b4a4(void)

{
  int unaff_EBP;
  
  FUN_1000c39a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b4ac at 1001b4ac

void Unwind_1001b4ac(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b4cf at 1001b4cf

void Unwind_1001b4cf(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b4f2 at 1001b4f2

void Unwind_1001b4f2(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b4fa at 1001b4fa

void Unwind_1001b4fa(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b51d at 1001b51d

void Unwind_1001b51d(void)

{
  int unaff_EBP;
  
  FUN_1000c352((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001b528 at 1001b528

void Unwind_1001b528(void)

{
  int unaff_EBP;
  
  FUN_1000c54c((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001b533 at 1001b533

void Unwind_1001b533(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001b53e at 1001b53e

void Unwind_1001b53e(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001b549 at 1001b549

void Unwind_1001b549(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@1001b554 at 1001b554

void Unwind_1001b554(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x24));
  return;
}



// Function: Unwind@1001b55f at 1001b55f

void Unwind_1001b55f(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1001b56a at 1001b56a

void Unwind_1001b56a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b572 at 1001b572

void Unwind_1001b572(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b57a at 1001b57a

void Unwind_1001b57a(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b582 at 1001b582

void Unwind_1001b582(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b5a5 at 1001b5a5

void Unwind_1001b5a5(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001b5ad at 1001b5ad

void Unwind_1001b5ad(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_1000c2da(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b5e1 at 1001b5e1

void Unwind_1001b5e1(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b5e9 at 1001b5e9

void Unwind_1001b5e9(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001b5f1 at 1001b5f1

void Unwind_1001b5f1(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001b5f9 at 1001b5f9

void Unwind_1001b5f9(void)

{
  int unaff_EBP;
  
  FUN_1000c39a((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b601 at 1001b601

void Unwind_1001b601(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b609 at 1001b609

void Unwind_1001b609(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b611 at 1001b611

void Unwind_1001b611(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b619 at 1001b619

void Unwind_1001b619(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001b621 at 1001b621

void Unwind_1001b621(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001b629 at 1001b629

void Unwind_1001b629(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001b631 at 1001b631

void Unwind_1001b631(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001b639 at 1001b639

void Unwind_1001b639(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001b641 at 1001b641

void Unwind_1001b641(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001b649 at 1001b649

void Unwind_1001b649(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001b651 at 1001b651

void Unwind_1001b651(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001b659 at 1001b659

void Unwind_1001b659(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001b661 at 1001b661

void Unwind_1001b661(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b669 at 1001b669

void Unwind_1001b669(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001b671 at 1001b671

void Unwind_1001b671(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b69e at 1001b69e

void Unwind_1001b69e(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b6a6 at 1001b6a6

void Unwind_1001b6a6(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@1001b6ae at 1001b6ae

void Unwind_1001b6ae(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001b6e2 at 1001b6e2

void Unwind_1001b6e2(void)

{
  int unaff_EBP;
  
  FUN_10001415((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b6ea at 1001b6ea

void Unwind_1001b6ea(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@1001b70d at 1001b70d

void Unwind_1001b70d(void)

{
  int unaff_EBP;
  
  FUN_1000c352((undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 8));
  return;
}



// Function: Unwind@1001b718 at 1001b718

void Unwind_1001b718(void)

{
  int unaff_EBP;
  
  FUN_1000c54c((undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 0x10));
  return;
}



// Function: Unwind@1001b723 at 1001b723

void Unwind_1001b723(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 0x18));
  return;
}



// Function: Unwind@1001b72e at 1001b72e

void Unwind_1001b72e(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b736 at 1001b736

void Unwind_1001b736(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x3c) + 0x1c));
  return;
}



// Function: Unwind@1001b741 at 1001b741

void Unwind_1001b741(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b749 at 1001b749

void Unwind_1001b749(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x3c) + 0x20));
  return;
}



// Function: Unwind@1001b754 at 1001b754

void Unwind_1001b754(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b75c at 1001b75c

void Unwind_1001b75c(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x3c) + 0x24));
  return;
}



// Function: Unwind@1001b767 at 1001b767

void Unwind_1001b767(void)

{
  int unaff_EBP;
  
  FUN_1000c1ff(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b76f at 1001b76f

void Unwind_1001b76f(void)

{
  int unaff_EBP;
  
  FUN_1000c32d((int *)(*(int *)(unaff_EBP + -0x3c) + 0x28));
  return;
}



// Function: Unwind@1001b77a at 1001b77a

void Unwind_1001b77a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b782 at 1001b782

void Unwind_1001b782(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001b78a at 1001b78a

void Unwind_1001b78a(void)

{
  int unaff_EBP;
  
  FUN_1000c54c((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001b792 at 1001b792

void Unwind_1001b792(void)

{
  int unaff_EBP;
  
  FUN_1000c39a((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001b79a at 1001b79a

void Unwind_1001b79a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b7a2 at 1001b7a2

void Unwind_1001b7a2(void)

{
  int unaff_EBP;
  
  FUN_1000c32d(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b7cf at 1001b7cf

void Unwind_1001b7cf(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b7d7 at 1001b7d7

void Unwind_1001b7d7(void)

{
  int unaff_EBP;
  
  FUN_1000c3e2((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001b804 at 1001b804

void Unwind_1001b804(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b80c at 1001b80c

void Unwind_1001b80c(void)

{
  int unaff_EBP;
  
  FUN_1000c3e2((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001b814 at 1001b814

void Unwind_1001b814(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b81c at 1001b81c

void Unwind_1001b81c(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b849 at 1001b849

void Unwind_1001b849(void)

{
  int unaff_EBP;
  
  FUN_100011b2((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b851 at 1001b851

void Unwind_1001b851(void)

{
  int unaff_EBP;
  
  FUN_100011b2(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b874 at 1001b874

void Unwind_1001b874(void)

{
  int unaff_EBP;
  
  FUN_1000c2da(unaff_EBP + 0xc);
  return;
}



// Function: Unwind@1001b87c at 1001b87c

void Unwind_1001b87c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: FUN_1001dfc2 at 1001dfc2

void FUN_1001dfc2(void)

{
  Ordinal_6(DAT_1002f244);
  return;
}



// Function: FUN_1001dfcf at 1001dfcf

void FUN_1001dfcf(void)

{
  Ordinal_6(DAT_1002f424);
  return;
}



// Function: FUN_1001dfdc at 1001dfdc

void FUN_1001dfdc(void)

{
  Ordinal_6(DAT_1002f428);
  return;
}



// Function: FUN_1001dfe9 at 1001dfe9

void FUN_1001dfe9(void)

{
  Ordinal_6(DAT_1002f42c);
  return;
}



// Function: FUN_1001dff8 at 1001dff8

void FUN_1001dff8(void)

{
  Ordinal_6(DAT_1002f468);
  return;
}



// Function: FUN_1001e005 at 1001e005

void FUN_1001e005(void)

{
  Ordinal_6(DAT_1002f46c);
  return;
}



// Function: FUN_1001e012 at 1001e012

void FUN_1001e012(void)

{
  Ordinal_6(DAT_1002f470);
  return;
}



// Function: FUN_1001e01f at 1001e01f

void FUN_1001e01f(void)

{
  Ordinal_6(DAT_1002f474);
  return;
}



// Function: FUN_1001e02c at 1001e02c

void FUN_1001e02c(void)

{
  Ordinal_6(DAT_1002f478);
  return;
}



// Function: FUN_1001e039 at 1001e039

void FUN_1001e039(void)

{
  FID_conflict__Tidy(&DAT_1002f1d4,'\x01',0);
  return;
}



// Function: FUN_1001e048 at 1001e048

void FUN_1001e048(void)

{
  FID_conflict__Tidy(&DAT_1002f1f0,'\x01',0);
  return;
}



// Function: FUN_1001e057 at 1001e057

void FUN_1001e057(void)

{
  FID_conflict__Tidy(&DAT_1002f20c,'\x01',0);
  return;
}



// Function: FUN_1001e066 at 1001e066

void FUN_1001e066(void)

{
  FID_conflict__Tidy(&DAT_1002f228,'\x01',0);
  return;
}



// Function: FUN_1001e075 at 1001e075

void FUN_1001e075(void)

{
  FID_conflict__Tidy(&DAT_1002f248,'\x01',0);
  return;
}



// Function: FUN_1001e084 at 1001e084

void FUN_1001e084(void)

{
  FID_conflict__Tidy(&DAT_1002f264,'\x01',0);
  return;
}



// Function: FUN_1001e093 at 1001e093

void FUN_1001e093(void)

{
  FID_conflict__Tidy(&DAT_1002f280,'\x01',0);
  return;
}



// Function: FUN_1001e0a2 at 1001e0a2

void FUN_1001e0a2(void)

{
  FID_conflict__Tidy(&DAT_1002f29c,'\x01',0);
  return;
}



// Function: FUN_1001e0b1 at 1001e0b1

void FUN_1001e0b1(void)

{
  FID_conflict__Tidy(&DAT_1002f2b8,'\x01',0);
  return;
}



// Function: FUN_1001e0c0 at 1001e0c0

void FUN_1001e0c0(void)

{
  FID_conflict__Tidy(&DAT_1002f2d4,'\x01',0);
  return;
}



// Function: FUN_1001e0cf at 1001e0cf

void FUN_1001e0cf(void)

{
  FID_conflict__Tidy(&DAT_1002f2f0,'\x01',0);
  return;
}



// Function: FUN_1001e0de at 1001e0de

void FUN_1001e0de(void)

{
  FID_conflict__Tidy(&DAT_1002f30c,'\x01',0);
  return;
}



// Function: FUN_1001e0ed at 1001e0ed

void FUN_1001e0ed(void)

{
  FID_conflict__Tidy(&DAT_1002f328,'\x01',0);
  return;
}



// Function: FUN_1001e0fc at 1001e0fc

void FUN_1001e0fc(void)

{
  FID_conflict__Tidy(&DAT_1002f344,'\x01',0);
  return;
}



// Function: FUN_1001e10b at 1001e10b

void FUN_1001e10b(void)

{
  FID_conflict__Tidy(&DAT_1002f360,'\x01',0);
  return;
}



// Function: FUN_1001e11a at 1001e11a

void FUN_1001e11a(void)

{
  FID_conflict__Tidy(&DAT_1002f37c,'\x01',0);
  return;
}



// Function: FUN_1001e129 at 1001e129

void FUN_1001e129(void)

{
  FID_conflict__Tidy(&DAT_1002f398,'\x01',0);
  return;
}



// Function: FUN_1001e138 at 1001e138

void FUN_1001e138(void)

{
  FID_conflict__Tidy(&DAT_1002f3b4,'\x01',0);
  return;
}



// Function: FUN_1001e147 at 1001e147

void FUN_1001e147(void)

{
  FID_conflict__Tidy(&DAT_1002f3d0,'\x01',0);
  return;
}



// Function: FUN_1001e156 at 1001e156

void FUN_1001e156(void)

{
  FID_conflict__Tidy(&DAT_1002f3ec,'\x01',0);
  return;
}



// Function: FUN_1001e165 at 1001e165

void FUN_1001e165(void)

{
  FID_conflict__Tidy(&DAT_1002f408,'\x01',0);
  return;
}



// Function: FUN_1001e174 at 1001e174

void FUN_1001e174(void)

{
  FID_conflict__Tidy(&DAT_1002f430,'\x01',0);
  return;
}



// Function: FUN_1001e183 at 1001e183

void FUN_1001e183(void)

{
  FID_conflict__Tidy(&DAT_1002f44c,'\x01',0);
  return;
}



// Function: FUN_1001e192 at 1001e192

void FUN_1001e192(void)

{
  FID_conflict__Tidy(&DAT_1002f47c,'\x01',0);
  return;
}



// Function: FUN_1001e1a1 at 1001e1a1

void FUN_1001e1a1(void)

{
  FID_conflict__Tidy(&DAT_1002f498,'\x01',0);
  return;
}



// Function: FUN_1001e1b0 at 1001e1b0

void FUN_1001e1b0(void)

{
  FID_conflict__Tidy(&DAT_1002f4b4,'\x01',0);
  return;
}



// Function: FUN_1001e1bf at 1001e1bf

void FUN_1001e1bf(void)

{
  FID_conflict__Tidy(&DAT_1002f4d0,'\x01',0);
  return;
}



// Function: FUN_1001e1ce at 1001e1ce

void FUN_1001e1ce(void)

{
  FID_conflict__Tidy(&DAT_1002f4ec,'\x01',0);
  return;
}



// Function: FUN_1001e1dd at 1001e1dd

void FUN_1001e1dd(void)

{
  FID_conflict__Tidy(&DAT_1002f508,'\x01',0);
  return;
}



// Function: FUN_1001e1ec at 1001e1ec

void FUN_1001e1ec(void)

{
  FID_conflict__Tidy(&DAT_1002f524,'\x01',0);
  return;
}



// Function: FUN_1001e1fb at 1001e1fb

void FUN_1001e1fb(void)

{
  FID_conflict__Tidy(&DAT_1002f540,'\x01',0);
  return;
}



// Function: FUN_1001e20a at 1001e20a

void FUN_1001e20a(void)

{
  FID_conflict__Tidy(&DAT_1002f55c,'\x01',0);
  return;
}



// Function: FUN_1001e219 at 1001e219

void FUN_1001e219(void)

{
  FID_conflict__Tidy(&DAT_1002f578,'\x01',0);
  return;
}



// Function: FUN_1001e228 at 1001e228

void FUN_1001e228(void)

{
  FID_conflict__Tidy(&DAT_1002f594,'\x01',0);
  return;
}



// Function: FUN_1001e237 at 1001e237

void FUN_1001e237(void)

{
  FID_conflict__Tidy(&DAT_1002f5b0,'\x01',0);
  return;
}



// Function: FUN_1001e246 at 1001e246

void FUN_1001e246(void)

{
  FID_conflict__Tidy(&DAT_1002f5cc,'\x01',0);
  return;
}



// Function: FUN_1001e255 at 1001e255

void FUN_1001e255(void)

{
  FID_conflict__Tidy(&DAT_1002f5e8,'\x01',0);
  return;
}



// Function: FUN_1001e264 at 1001e264

void FUN_1001e264(void)

{
  FID_conflict__Tidy(&DAT_1002f604,'\x01',0);
  return;
}



// Function: FUN_1001e273 at 1001e273

void FUN_1001e273(void)

{
  FID_conflict__Tidy(&DAT_1002f620,'\x01',0);
  return;
}



// Function: FUN_1001e282 at 1001e282

void FUN_1001e282(void)

{
  FID_conflict__Tidy(&DAT_1002f63c,'\x01',0);
  return;
}



// Function: FUN_1001e291 at 1001e291

void FUN_1001e291(void)

{
  FID_conflict__Tidy(&DAT_1002f658,'\x01',0);
  return;
}



// Function: FUN_1001e2a0 at 1001e2a0

void FUN_1001e2a0(void)

{
  FID_conflict__Tidy(&DAT_1002f674,'\x01',0);
  return;
}



// Function: FUN_1001e2af at 1001e2af

void FUN_1001e2af(void)

{
  FID_conflict__Tidy(&DAT_1002f690,'\x01',0);
  return;
}



// Function: FUN_1001e2be at 1001e2be

void FUN_1001e2be(void)

{
  FID_conflict__Tidy(&DAT_1002f6ac,'\x01',0);
  return;
}



// Function: FUN_1001e2cd at 1001e2cd

void FUN_1001e2cd(void)

{
  FID_conflict__Tidy(&DAT_1002f6c8,'\x01',0);
  return;
}



// Function: FUN_1001e2dc at 1001e2dc

void FUN_1001e2dc(void)

{
  FID_conflict__Tidy(&DAT_1002f6e4,'\x01',0);
  return;
}



// Function: FUN_1001e2eb at 1001e2eb

void FUN_1001e2eb(void)

{
  FID_conflict__Tidy(&DAT_1002f700,'\x01',0);
  return;
}



// Function: FUN_1001e2fa at 1001e2fa

void FUN_1001e2fa(void)

{
  FID_conflict__Tidy(&DAT_1002f71c,'\x01',0);
  return;
}



// Function: FUN_1001e309 at 1001e309

void FUN_1001e309(void)

{
  FID_conflict__Tidy(&DAT_1002f740,'\x01',0);
  return;
}



// Function: FUN_1001e318 at 1001e318

void FUN_1001e318(void)

{
  FID_conflict__Tidy(&DAT_1002f75c,'\x01',0);
  return;
}



// Function: FUN_1001e327 at 1001e327

void FUN_1001e327(void)

{
  FID_conflict__Tidy(&DAT_1002f778,'\x01',0);
  return;
}



// Function: FUN_1001e336 at 1001e336

void FUN_1001e336(void)

{
  FID_conflict__Tidy(&DAT_1002f794,'\x01',0);
  return;
}



// Function: FUN_1001e345 at 1001e345

void FUN_1001e345(void)

{
  FID_conflict__Tidy(&DAT_1002f7b0,'\x01',0);
  return;
}



// Function: FUN_1001e354 at 1001e354

void FUN_1001e354(void)

{
  FID_conflict__Tidy(&DAT_1002f7cc,'\x01',0);
  return;
}



// Function: FUN_1001e363 at 1001e363

void FUN_1001e363(void)

{
  FID_conflict__Tidy(&DAT_1002f7e8,'\x01',0);
  return;
}



// Function: FUN_1001e372 at 1001e372

void FUN_1001e372(void)

{
  if (DAT_1002f738 != (int *)0x0) {
    FUN_10001969(DAT_1002f738);
    DAT_1002f738 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e389 at 1001e389

void FUN_1001e389(void)

{
  if (DAT_1002f73c != (int *)0x0) {
    FUN_10001969(DAT_1002f73c);
    DAT_1002f73c = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e3a0 at 1001e3a0

void FUN_1001e3a0(void)

{
  Ordinal_6(DAT_1002fa90);
  return;
}



// Function: FUN_1001e3ad at 1001e3ad

void FUN_1001e3ad(void)

{
  Ordinal_6(DAT_1002fa94);
  return;
}



// Function: FUN_1001e3ba at 1001e3ba

void FUN_1001e3ba(void)

{
  Ordinal_6(DAT_1002fa98);
  return;
}



// Function: FUN_1001e3c7 at 1001e3c7

void FUN_1001e3c7(void)

{
  Ordinal_6(DAT_1002fa9c);
  return;
}



// Function: FUN_1001e3d4 at 1001e3d4

void FUN_1001e3d4(void)

{
  Ordinal_6(DAT_1002fbb8);
  return;
}



// Function: FUN_1001e3e1 at 1001e3e1

void FUN_1001e3e1(void)

{
  Ordinal_6(DAT_1002fbbc);
  return;
}



// Function: FUN_1001e3ee at 1001e3ee

void FUN_1001e3ee(void)

{
  Ordinal_6(DAT_1002fbc0);
  return;
}



// Function: FUN_1001e3fb at 1001e3fb

void FUN_1001e3fb(void)

{
  Ordinal_6(DAT_1002fbc4);
  return;
}



// Function: FUN_1001e408 at 1001e408

void FUN_1001e408(void)

{
  Ordinal_6(DAT_1002fbc8);
  return;
}



// Function: FUN_1001e415 at 1001e415

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e415(void)

{
  _DAT_1002ff54 = ATL::CComModule::vftable;
  FUN_10004014(0x1002ff54);
  return;
}



// Function: FUN_1001e43f at 1001e43f

void FUN_1001e43f(void)

{
  FID_conflict__Tidy(&DAT_1002f83c,'\x01',0);
  return;
}



// Function: FUN_1001e44e at 1001e44e

void FUN_1001e44e(void)

{
  FID_conflict__Tidy(&DAT_1002f858,'\x01',0);
  return;
}



// Function: FUN_1001e45d at 1001e45d

void FUN_1001e45d(void)

{
  FID_conflict__Tidy(&DAT_1002f874,'\x01',0);
  return;
}



// Function: FUN_1001e46c at 1001e46c

void FUN_1001e46c(void)

{
  FID_conflict__Tidy(&DAT_1002f890,'\x01',0);
  return;
}



// Function: FUN_1001e47b at 1001e47b

void FUN_1001e47b(void)

{
  FID_conflict__Tidy(&DAT_1002f8b4,'\x01',0);
  return;
}



// Function: FUN_1001e48a at 1001e48a

void FUN_1001e48a(void)

{
  FID_conflict__Tidy(&DAT_1002f8d0,'\x01',0);
  return;
}



// Function: FUN_1001e499 at 1001e499

void FUN_1001e499(void)

{
  FID_conflict__Tidy(&DAT_1002f8ec,'\x01',0);
  return;
}



// Function: FUN_1001e4a8 at 1001e4a8

void FUN_1001e4a8(void)

{
  FID_conflict__Tidy(&DAT_1002f908,'\x01',0);
  return;
}



// Function: FUN_1001e4b7 at 1001e4b7

void FUN_1001e4b7(void)

{
  FID_conflict__Tidy(&DAT_1002f924,'\x01',0);
  return;
}



// Function: FUN_1001e4c6 at 1001e4c6

void FUN_1001e4c6(void)

{
  FID_conflict__Tidy(&DAT_1002f940,'\x01',0);
  return;
}



// Function: FUN_1001e4d5 at 1001e4d5

void FUN_1001e4d5(void)

{
  FID_conflict__Tidy(&DAT_1002f95c,'\x01',0);
  return;
}



// Function: FUN_1001e4e4 at 1001e4e4

void FUN_1001e4e4(void)

{
  FID_conflict__Tidy(&DAT_1002f978,'\x01',0);
  return;
}



// Function: FUN_1001e4f3 at 1001e4f3

void FUN_1001e4f3(void)

{
  FID_conflict__Tidy(&DAT_1002f994,'\x01',0);
  return;
}



// Function: FUN_1001e502 at 1001e502

void FUN_1001e502(void)

{
  FID_conflict__Tidy(&DAT_1002f9b0,'\x01',0);
  return;
}



// Function: FUN_1001e511 at 1001e511

void FUN_1001e511(void)

{
  FID_conflict__Tidy(&DAT_1002f9cc,'\x01',0);
  return;
}



// Function: FUN_1001e520 at 1001e520

void FUN_1001e520(void)

{
  FID_conflict__Tidy(&DAT_1002f9e8,'\x01',0);
  return;
}



// Function: FUN_1001e52f at 1001e52f

void FUN_1001e52f(void)

{
  FID_conflict__Tidy(&DAT_1002fa04,'\x01',0);
  return;
}



// Function: FUN_1001e53e at 1001e53e

void FUN_1001e53e(void)

{
  FID_conflict__Tidy(&DAT_1002fa20,'\x01',0);
  return;
}



// Function: FUN_1001e54d at 1001e54d

void FUN_1001e54d(void)

{
  FID_conflict__Tidy(&DAT_1002fa3c,'\x01',0);
  return;
}



// Function: FUN_1001e55c at 1001e55c

void FUN_1001e55c(void)

{
  FID_conflict__Tidy(&DAT_1002fa58,'\x01',0);
  return;
}



// Function: FUN_1001e56b at 1001e56b

void FUN_1001e56b(void)

{
  FID_conflict__Tidy(&DAT_1002fa74,'\x01',0);
  return;
}



// Function: FUN_1001e57a at 1001e57a

void FUN_1001e57a(void)

{
  FID_conflict__Tidy(&DAT_1002faa0,'\x01',0);
  return;
}



// Function: FUN_1001e589 at 1001e589

void FUN_1001e589(void)

{
  FID_conflict__Tidy(&DAT_1002fabc,'\x01',0);
  return;
}



// Function: FUN_1001e598 at 1001e598

void FUN_1001e598(void)

{
  FID_conflict__Tidy(&DAT_1002fad8,'\x01',0);
  return;
}



// Function: FUN_1001e5a7 at 1001e5a7

void FUN_1001e5a7(void)

{
  FID_conflict__Tidy(&DAT_1002faf4,'\x01',0);
  return;
}



// Function: FUN_1001e5b6 at 1001e5b6

void FUN_1001e5b6(void)

{
  FID_conflict__Tidy(&DAT_1002fb10,'\x01',0);
  return;
}



// Function: FUN_1001e5c5 at 1001e5c5

void FUN_1001e5c5(void)

{
  FID_conflict__Tidy(&DAT_1002fb2c,'\x01',0);
  return;
}



// Function: FUN_1001e5d4 at 1001e5d4

void FUN_1001e5d4(void)

{
  FID_conflict__Tidy(&DAT_1002fb48,'\x01',0);
  return;
}



// Function: FUN_1001e5e3 at 1001e5e3

void FUN_1001e5e3(void)

{
  FID_conflict__Tidy(&DAT_1002fb64,'\x01',0);
  return;
}



// Function: FUN_1001e5f2 at 1001e5f2

void FUN_1001e5f2(void)

{
  FID_conflict__Tidy(&DAT_1002fb80,'\x01',0);
  return;
}



// Function: FUN_1001e601 at 1001e601

void FUN_1001e601(void)

{
  FID_conflict__Tidy(&DAT_1002fb9c,'\x01',0);
  return;
}



// Function: FUN_1001e610 at 1001e610

void FUN_1001e610(void)

{
  FID_conflict__Tidy(&DAT_1002fbcc,'\x01',0);
  return;
}



// Function: FUN_1001e61f at 1001e61f

void FUN_1001e61f(void)

{
  FID_conflict__Tidy(&DAT_1002fbe8,'\x01',0);
  return;
}



// Function: FUN_1001e62e at 1001e62e

void FUN_1001e62e(void)

{
  FID_conflict__Tidy(&DAT_1002fc04,'\x01',0);
  return;
}



// Function: FUN_1001e63d at 1001e63d

void FUN_1001e63d(void)

{
  FID_conflict__Tidy(&DAT_1002fc20,'\x01',0);
  return;
}



// Function: FUN_1001e64c at 1001e64c

void FUN_1001e64c(void)

{
  FID_conflict__Tidy(&DAT_1002fc3c,'\x01',0);
  return;
}



// Function: FUN_1001e65b at 1001e65b

void FUN_1001e65b(void)

{
  FID_conflict__Tidy(&DAT_1002fc58,'\x01',0);
  return;
}



// Function: FUN_1001e66a at 1001e66a

void FUN_1001e66a(void)

{
  FID_conflict__Tidy(&DAT_1002fc74,'\x01',0);
  return;
}



// Function: FUN_1001e679 at 1001e679

void FUN_1001e679(void)

{
  FID_conflict__Tidy(&DAT_1002fc90,'\x01',0);
  return;
}



// Function: FUN_1001e688 at 1001e688

void FUN_1001e688(void)

{
  FID_conflict__Tidy(&DAT_1002fcac,'\x01',0);
  return;
}



// Function: FUN_1001e697 at 1001e697

void FUN_1001e697(void)

{
  FID_conflict__Tidy(&DAT_1002fcc8,'\x01',0);
  return;
}



// Function: FUN_1001e6a6 at 1001e6a6

void FUN_1001e6a6(void)

{
  FID_conflict__Tidy(&DAT_1002fce4,'\x01',0);
  return;
}



// Function: FUN_1001e6b5 at 1001e6b5

void FUN_1001e6b5(void)

{
  FID_conflict__Tidy(&DAT_1002fd00,'\x01',0);
  return;
}



// Function: FUN_1001e6c4 at 1001e6c4

void FUN_1001e6c4(void)

{
  FID_conflict__Tidy(&DAT_1002fd1c,'\x01',0);
  return;
}



// Function: FUN_1001e6d3 at 1001e6d3

void FUN_1001e6d3(void)

{
  FID_conflict__Tidy(&DAT_1002fd38,'\x01',0);
  return;
}



// Function: FUN_1001e6e2 at 1001e6e2

void FUN_1001e6e2(void)

{
  FID_conflict__Tidy(&DAT_1002fd54,'\x01',0);
  return;
}



// Function: FUN_1001e6f1 at 1001e6f1

void FUN_1001e6f1(void)

{
  FID_conflict__Tidy(&DAT_1002fd70,'\x01',0);
  return;
}



// Function: FUN_1001e700 at 1001e700

void FUN_1001e700(void)

{
  FID_conflict__Tidy(&DAT_1002fd8c,'\x01',0);
  return;
}



// Function: FUN_1001e70f at 1001e70f

void FUN_1001e70f(void)

{
  FID_conflict__Tidy(&DAT_1002fda8,'\x01',0);
  return;
}



// Function: FUN_1001e71e at 1001e71e

void FUN_1001e71e(void)

{
  FID_conflict__Tidy(&DAT_1002fdc4,'\x01',0);
  return;
}



// Function: FUN_1001e72d at 1001e72d

void FUN_1001e72d(void)

{
  FID_conflict__Tidy(&DAT_1002fde0,'\x01',0);
  return;
}



// Function: FUN_1001e73c at 1001e73c

void FUN_1001e73c(void)

{
  FID_conflict__Tidy(&DAT_1002fdfc,'\x01',0);
  return;
}



// Function: FUN_1001e74b at 1001e74b

void FUN_1001e74b(void)

{
  FID_conflict__Tidy(&DAT_1002fe18,'\x01',0);
  return;
}



// Function: FUN_1001e75a at 1001e75a

void FUN_1001e75a(void)

{
  FID_conflict__Tidy(&DAT_1002fe34,'\x01',0);
  return;
}



// Function: FUN_1001e769 at 1001e769

void FUN_1001e769(void)

{
  FID_conflict__Tidy(&DAT_1002fe50,'\x01',0);
  return;
}



// Function: FUN_1001e778 at 1001e778

void FUN_1001e778(void)

{
  FID_conflict__Tidy(&DAT_1002fe6c,'\x01',0);
  return;
}



// Function: FUN_1001e787 at 1001e787

void FUN_1001e787(void)

{
  FID_conflict__Tidy(&DAT_1002fe90,'\x01',0);
  return;
}



// Function: FUN_1001e796 at 1001e796

void FUN_1001e796(void)

{
  FID_conflict__Tidy(&DAT_1002feac,'\x01',0);
  return;
}



// Function: FUN_1001e7a5 at 1001e7a5

void FUN_1001e7a5(void)

{
  FID_conflict__Tidy(&DAT_1002fec8,'\x01',0);
  return;
}



// Function: FUN_1001e7b4 at 1001e7b4

void FUN_1001e7b4(void)

{
  FID_conflict__Tidy(&DAT_1002fee4,'\x01',0);
  return;
}



// Function: FUN_1001e7c3 at 1001e7c3

void FUN_1001e7c3(void)

{
  FID_conflict__Tidy(&DAT_1002ff00,'\x01',0);
  return;
}



// Function: FUN_1001e7d2 at 1001e7d2

void FUN_1001e7d2(void)

{
  FID_conflict__Tidy(&DAT_1002ff1c,'\x01',0);
  return;
}



// Function: FUN_1001e7e1 at 1001e7e1

void FUN_1001e7e1(void)

{
  FID_conflict__Tidy(&DAT_1002ff38,'\x01',0);
  return;
}



// Function: FUN_1001e7f0 at 1001e7f0

void FUN_1001e7f0(void)

{
  if (DAT_1002fe88 != (int *)0x0) {
    FUN_10001969(DAT_1002fe88);
    DAT_1002fe88 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e807 at 1001e807

void FUN_1001e807(void)

{
  if (DAT_1002fe8c != (int *)0x0) {
    FUN_10001969(DAT_1002fe8c);
    DAT_1002fe8c = (int *)0x0;
  }
  return;
}



// Function: FUN_1001e81e at 1001e81e

void FUN_1001e81e(void)

{
  Ordinal_6(DAT_1002fff4);
  return;
}



// Function: FUN_1001e82b at 1001e82b

void FUN_1001e82b(void)

{
  Ordinal_6(DAT_100302b4);
  return;
}



// Function: FUN_1001e838 at 1001e838

void FUN_1001e838(void)

{
  Ordinal_6(DAT_100302b8);
  return;
}



// Function: FUN_1001e845 at 1001e845

void FUN_1001e845(void)

{
  Ordinal_6(DAT_100302bc);
  return;
}



// Function: FUN_1001e852 at 1001e852

void FUN_1001e852(void)

{
  FID_conflict__Tidy(&DAT_1002ff84,'\x01',0);
  return;
}



// Function: FUN_1001e861 at 1001e861

void FUN_1001e861(void)

{
  FID_conflict__Tidy(&DAT_1002ffa0,'\x01',0);
  return;
}



// Function: FUN_1001e870 at 1001e870

void FUN_1001e870(void)

{
  FID_conflict__Tidy(&DAT_1002ffbc,'\x01',0);
  return;
}



// Function: FUN_1001e87f at 1001e87f

void FUN_1001e87f(void)

{
  FID_conflict__Tidy(&DAT_1002ffd8,'\x01',0);
  return;
}



// Function: FUN_1001e88e at 1001e88e

void FUN_1001e88e(void)

{
  FID_conflict__Tidy(&DAT_1002fff8,'\x01',0);
  return;
}



// Function: FUN_1001e89d at 1001e89d

void FUN_1001e89d(void)

{
  FID_conflict__Tidy(&DAT_10030014,'\x01',0);
  return;
}



// Function: FUN_1001e8ac at 1001e8ac

void FUN_1001e8ac(void)

{
  FID_conflict__Tidy(&DAT_10030030,'\x01',0);
  return;
}



// Function: FUN_1001e8bb at 1001e8bb

void FUN_1001e8bb(void)

{
  FID_conflict__Tidy(&DAT_1003004c,'\x01',0);
  return;
}



// Function: FUN_1001e8ca at 1001e8ca

void FUN_1001e8ca(void)

{
  FID_conflict__Tidy(&DAT_10030068,'\x01',0);
  return;
}



// Function: FUN_1001e8d9 at 1001e8d9

void FUN_1001e8d9(void)

{
  FID_conflict__Tidy(&DAT_10030084,'\x01',0);
  return;
}



// Function: FUN_1001e8e8 at 1001e8e8

void FUN_1001e8e8(void)

{
  FID_conflict__Tidy(&DAT_100300a0,'\x01',0);
  return;
}



// Function: FUN_1001e8f7 at 1001e8f7

void FUN_1001e8f7(void)

{
  FID_conflict__Tidy(&DAT_100300bc,'\x01',0);
  return;
}



// Function: FUN_1001e906 at 1001e906

void FUN_1001e906(void)

{
  FID_conflict__Tidy(&DAT_100300d8,'\x01',0);
  return;
}



// Function: FUN_1001e915 at 1001e915

void FUN_1001e915(void)

{
  FID_conflict__Tidy(&DAT_100300f4,'\x01',0);
  return;
}



// Function: FUN_1001e924 at 1001e924

void FUN_1001e924(void)

{
  FID_conflict__Tidy(&DAT_10030110,'\x01',0);
  return;
}



// Function: FUN_1001e933 at 1001e933

void FUN_1001e933(void)

{
  FID_conflict__Tidy(&DAT_1003012c,'\x01',0);
  return;
}



// Function: FUN_1001e942 at 1001e942

void FUN_1001e942(void)

{
  FID_conflict__Tidy(&DAT_10030148,'\x01',0);
  return;
}



// Function: FUN_1001e951 at 1001e951

void FUN_1001e951(void)

{
  FID_conflict__Tidy(&DAT_10030164,'\x01',0);
  return;
}



// Function: FUN_1001e960 at 1001e960

void FUN_1001e960(void)

{
  FID_conflict__Tidy(&DAT_10030180,'\x01',0);
  return;
}



// Function: FUN_1001e96f at 1001e96f

void FUN_1001e96f(void)

{
  FID_conflict__Tidy(&DAT_1003019c,'\x01',0);
  return;
}



// Function: FUN_1001e97e at 1001e97e

void FUN_1001e97e(void)

{
  FID_conflict__Tidy(&DAT_100301b8,'\x01',0);
  return;
}



// Function: FUN_1001e98d at 1001e98d

void FUN_1001e98d(void)

{
  FID_conflict__Tidy(&DAT_100301d4,'\x01',0);
  return;
}



// Function: FUN_1001e99c at 1001e99c

void FUN_1001e99c(void)

{
  FID_conflict__Tidy(&DAT_100301f0,'\x01',0);
  return;
}



// Function: FUN_1001e9ab at 1001e9ab

void FUN_1001e9ab(void)

{
  FID_conflict__Tidy(&DAT_1003020c,'\x01',0);
  return;
}



// Function: FUN_1001e9ba at 1001e9ba

void FUN_1001e9ba(void)

{
  FID_conflict__Tidy(&DAT_10030228,'\x01',0);
  return;
}



// Function: FUN_1001e9c9 at 1001e9c9

void FUN_1001e9c9(void)

{
  FID_conflict__Tidy(&DAT_10030244,'\x01',0);
  return;
}



// Function: FUN_1001e9d8 at 1001e9d8

void FUN_1001e9d8(void)

{
  FID_conflict__Tidy(&DAT_10030260,'\x01',0);
  return;
}



// Function: FUN_1001e9e7 at 1001e9e7

void FUN_1001e9e7(void)

{
  FID_conflict__Tidy(&DAT_1003027c,'\x01',0);
  return;
}



// Function: FUN_1001e9f6 at 1001e9f6

void FUN_1001e9f6(void)

{
  FID_conflict__Tidy(&DAT_10030298,'\x01',0);
  return;
}



// Function: FUN_1001ea05 at 1001ea05

void FUN_1001ea05(void)

{
  Ordinal_6(DAT_10030330);
  return;
}



// Function: FUN_1001ea12 at 1001ea12

void FUN_1001ea12(void)

{
  Ordinal_6(DAT_10030510);
  return;
}



// Function: FUN_1001ea1f at 1001ea1f

void FUN_1001ea1f(void)

{
  Ordinal_6(DAT_10030514);
  return;
}



// Function: FUN_1001ea2c at 1001ea2c

void FUN_1001ea2c(void)

{
  Ordinal_6(DAT_10030518);
  return;
}



// Function: FUN_1001ea39 at 1001ea39

void FUN_1001ea39(void)

{
  Ordinal_6(DAT_10030554);
  return;
}



// Function: FUN_1001ea46 at 1001ea46

void FUN_1001ea46(void)

{
  Ordinal_6(DAT_10030558);
  return;
}



// Function: FUN_1001ea53 at 1001ea53

void FUN_1001ea53(void)

{
  Ordinal_6(DAT_1003055c);
  return;
}



// Function: FUN_1001ea60 at 1001ea60

void FUN_1001ea60(void)

{
  Ordinal_6(DAT_10030560);
  return;
}



// Function: FUN_1001ea6d at 1001ea6d

void FUN_1001ea6d(void)

{
  Ordinal_6(DAT_10030564);
  return;
}



// Function: FUN_1001ea7a at 1001ea7a

void FUN_1001ea7a(void)

{
  Ordinal_6(DAT_100308f8);
  return;
}



// Function: FUN_1001ea87 at 1001ea87

void FUN_1001ea87(void)

{
  FID_conflict__Tidy(&DAT_100302c0,'\x01',0);
  return;
}



// Function: FUN_1001ea96 at 1001ea96

void FUN_1001ea96(void)

{
  FID_conflict__Tidy(&DAT_100302dc,'\x01',0);
  return;
}



// Function: FUN_1001eaa5 at 1001eaa5

void FUN_1001eaa5(void)

{
  FID_conflict__Tidy(&DAT_100302f8,'\x01',0);
  return;
}



// Function: FUN_1001eab4 at 1001eab4

void FUN_1001eab4(void)

{
  FID_conflict__Tidy(&DAT_10030314,'\x01',0);
  return;
}



// Function: FUN_1001eac3 at 1001eac3

void FUN_1001eac3(void)

{
  FID_conflict__Tidy(&DAT_10030334,'\x01',0);
  return;
}



// Function: FUN_1001ead2 at 1001ead2

void FUN_1001ead2(void)

{
  FID_conflict__Tidy(&DAT_10030350,'\x01',0);
  return;
}



// Function: FUN_1001eae1 at 1001eae1

void FUN_1001eae1(void)

{
  FID_conflict__Tidy(&DAT_1003036c,'\x01',0);
  return;
}



// Function: FUN_1001eaf0 at 1001eaf0

void FUN_1001eaf0(void)

{
  FID_conflict__Tidy(&DAT_10030388,'\x01',0);
  return;
}



// Function: FUN_1001eaff at 1001eaff

void FUN_1001eaff(void)

{
  FID_conflict__Tidy(&DAT_100303a4,'\x01',0);
  return;
}



// Function: FUN_1001eb0e at 1001eb0e

void FUN_1001eb0e(void)

{
  FID_conflict__Tidy(&DAT_100303c0,'\x01',0);
  return;
}



// Function: FUN_1001eb1d at 1001eb1d

void FUN_1001eb1d(void)

{
  FID_conflict__Tidy(&DAT_100303dc,'\x01',0);
  return;
}



// Function: FUN_1001eb2c at 1001eb2c

void FUN_1001eb2c(void)

{
  FID_conflict__Tidy(&DAT_100303f8,'\x01',0);
  return;
}



// Function: FUN_1001eb3b at 1001eb3b

void FUN_1001eb3b(void)

{
  FID_conflict__Tidy(&DAT_10030414,'\x01',0);
  return;
}



// Function: FUN_1001eb4a at 1001eb4a

void FUN_1001eb4a(void)

{
  FID_conflict__Tidy(&DAT_10030430,'\x01',0);
  return;
}



// Function: FUN_1001eb59 at 1001eb59

void FUN_1001eb59(void)

{
  FID_conflict__Tidy(&DAT_1003044c,'\x01',0);
  return;
}



// Function: FUN_1001eb68 at 1001eb68

void FUN_1001eb68(void)

{
  FID_conflict__Tidy(&DAT_10030468,'\x01',0);
  return;
}



// Function: FUN_1001eb77 at 1001eb77

void FUN_1001eb77(void)

{
  FID_conflict__Tidy(&DAT_10030484,'\x01',0);
  return;
}



// Function: FUN_1001eb86 at 1001eb86

void FUN_1001eb86(void)

{
  FID_conflict__Tidy(&DAT_100304a0,'\x01',0);
  return;
}



// Function: FUN_1001eb95 at 1001eb95

void FUN_1001eb95(void)

{
  FID_conflict__Tidy(&DAT_100304bc,'\x01',0);
  return;
}



// Function: FUN_1001eba4 at 1001eba4

void FUN_1001eba4(void)

{
  FID_conflict__Tidy(&DAT_100304d8,'\x01',0);
  return;
}



// Function: FUN_1001ebb3 at 1001ebb3

void FUN_1001ebb3(void)

{
  FID_conflict__Tidy(&DAT_100304f4,'\x01',0);
  return;
}



// Function: FUN_1001ebc2 at 1001ebc2

void FUN_1001ebc2(void)

{
  FID_conflict__Tidy(&DAT_1003051c,'\x01',0);
  return;
}



// Function: FUN_1001ebd1 at 1001ebd1

void FUN_1001ebd1(void)

{
  FID_conflict__Tidy(&DAT_10030538,'\x01',0);
  return;
}



// Function: FUN_1001ebe0 at 1001ebe0

void FUN_1001ebe0(void)

{
  FID_conflict__Tidy(&DAT_10030568,'\x01',0);
  return;
}



// Function: FUN_1001ebef at 1001ebef

void FUN_1001ebef(void)

{
  FID_conflict__Tidy(&DAT_10030584,'\x01',0);
  return;
}



// Function: FUN_1001ebfe at 1001ebfe

void FUN_1001ebfe(void)

{
  FID_conflict__Tidy(&DAT_100305a0,'\x01',0);
  return;
}



// Function: FUN_1001ec0d at 1001ec0d

void FUN_1001ec0d(void)

{
  FID_conflict__Tidy(&DAT_100305bc,'\x01',0);
  return;
}



// Function: FUN_1001ec1c at 1001ec1c

void FUN_1001ec1c(void)

{
  FID_conflict__Tidy(&DAT_100305d8,'\x01',0);
  return;
}



// Function: FUN_1001ec2b at 1001ec2b

void FUN_1001ec2b(void)

{
  FID_conflict__Tidy(&DAT_100305f4,'\x01',0);
  return;
}



// Function: FUN_1001ec3a at 1001ec3a

void FUN_1001ec3a(void)

{
  FID_conflict__Tidy(&DAT_10030610,'\x01',0);
  return;
}



// Function: FUN_1001ec49 at 1001ec49

void FUN_1001ec49(void)

{
  FID_conflict__Tidy(&DAT_1003062c,'\x01',0);
  return;
}



// Function: FUN_1001ec58 at 1001ec58

void FUN_1001ec58(void)

{
  FID_conflict__Tidy(&DAT_10030648,'\x01',0);
  return;
}



// Function: FUN_1001ec67 at 1001ec67

void FUN_1001ec67(void)

{
  FID_conflict__Tidy(&DAT_10030664,'\x01',0);
  return;
}



// Function: FUN_1001ec76 at 1001ec76

void FUN_1001ec76(void)

{
  FID_conflict__Tidy(&DAT_10030680,'\x01',0);
  return;
}



// Function: FUN_1001ec85 at 1001ec85

void FUN_1001ec85(void)

{
  FID_conflict__Tidy(&DAT_1003069c,'\x01',0);
  return;
}



// Function: FUN_1001ec94 at 1001ec94

void FUN_1001ec94(void)

{
  FID_conflict__Tidy(&DAT_100306b8,'\x01',0);
  return;
}



// Function: FUN_1001eca3 at 1001eca3

void FUN_1001eca3(void)

{
  FID_conflict__Tidy(&DAT_100306d4,'\x01',0);
  return;
}



// Function: FUN_1001ecb2 at 1001ecb2

void FUN_1001ecb2(void)

{
  FID_conflict__Tidy(&DAT_100306f0,'\x01',0);
  return;
}



// Function: FUN_1001ecc1 at 1001ecc1

void FUN_1001ecc1(void)

{
  FID_conflict__Tidy(&DAT_1003070c,'\x01',0);
  return;
}



// Function: FUN_1001ecd0 at 1001ecd0

void FUN_1001ecd0(void)

{
  FID_conflict__Tidy(&DAT_10030728,'\x01',0);
  return;
}



// Function: FUN_1001ecdf at 1001ecdf

void FUN_1001ecdf(void)

{
  FID_conflict__Tidy(&DAT_10030744,'\x01',0);
  return;
}



// Function: FUN_1001ecee at 1001ecee

void FUN_1001ecee(void)

{
  FID_conflict__Tidy(&DAT_10030760,'\x01',0);
  return;
}



// Function: FUN_1001ecfd at 1001ecfd

void FUN_1001ecfd(void)

{
  FID_conflict__Tidy(&DAT_1003077c,'\x01',0);
  return;
}



// Function: FUN_1001ed0c at 1001ed0c

void FUN_1001ed0c(void)

{
  FID_conflict__Tidy(&DAT_10030798,'\x01',0);
  return;
}



// Function: FUN_1001ed1b at 1001ed1b

void FUN_1001ed1b(void)

{
  FID_conflict__Tidy(&DAT_100307b4,'\x01',0);
  return;
}



// Function: FUN_1001ed2a at 1001ed2a

void FUN_1001ed2a(void)

{
  FID_conflict__Tidy(&DAT_100307d0,'\x01',0);
  return;
}



// Function: FUN_1001ed39 at 1001ed39

void FUN_1001ed39(void)

{
  FID_conflict__Tidy(&DAT_100307ec,'\x01',0);
  return;
}



// Function: FUN_1001ed48 at 1001ed48

void FUN_1001ed48(void)

{
  FID_conflict__Tidy(&DAT_10030808,'\x01',0);
  return;
}



// Function: FUN_1001ed57 at 1001ed57

void FUN_1001ed57(void)

{
  FID_conflict__Tidy(&DAT_1003082c,'\x01',0);
  return;
}



// Function: FUN_1001ed66 at 1001ed66

void FUN_1001ed66(void)

{
  FID_conflict__Tidy(&DAT_10030848,'\x01',0);
  return;
}



// Function: FUN_1001ed75 at 1001ed75

void FUN_1001ed75(void)

{
  FID_conflict__Tidy(&DAT_10030864,'\x01',0);
  return;
}



// Function: FUN_1001ed84 at 1001ed84

void FUN_1001ed84(void)

{
  FID_conflict__Tidy(&DAT_10030880,'\x01',0);
  return;
}



// Function: FUN_1001ed93 at 1001ed93

void FUN_1001ed93(void)

{
  FID_conflict__Tidy(&DAT_1003089c,'\x01',0);
  return;
}



// Function: FUN_1001eda2 at 1001eda2

void FUN_1001eda2(void)

{
  FID_conflict__Tidy(&DAT_100308b8,'\x01',0);
  return;
}



// Function: FUN_1001edb1 at 1001edb1

void FUN_1001edb1(void)

{
  FID_conflict__Tidy(&DAT_100308d4,'\x01',0);
  return;
}



// Function: FUN_1001edc0 at 1001edc0

void FUN_1001edc0(void)

{
  FID_conflict__Tidy(&DAT_100308fc,'\x01',0);
  return;
}



// Function: FUN_1001edcf at 1001edcf

void FUN_1001edcf(void)

{
  FID_conflict__Tidy(&DAT_10030918,'\x01',0);
  return;
}



// Function: FUN_1001edde at 1001edde

void FUN_1001edde(void)

{
  FID_conflict__Tidy(&DAT_10030934,'\x01',0);
  return;
}



// Function: FUN_1001eded at 1001eded

void FUN_1001eded(void)

{
  FID_conflict__Tidy(&DAT_10030950,'\x01',0);
  return;
}



// Function: FUN_1001edfc at 1001edfc

void FUN_1001edfc(void)

{
  FID_conflict__Tidy(&DAT_1003096c,'\x01',0);
  return;
}



// Function: FUN_1001ee0b at 1001ee0b

void FUN_1001ee0b(void)

{
  FID_conflict__Tidy(&DAT_10030988,'\x01',0);
  return;
}



// Function: FUN_1001ee1a at 1001ee1a

void FUN_1001ee1a(void)

{
  FID_conflict__Tidy(&DAT_100309a4,'\x01',0);
  return;
}



// Function: FUN_1001ee29 at 1001ee29

void FUN_1001ee29(void)

{
  FID_conflict__Tidy(&DAT_100309c0,'\x01',0);
  return;
}



// Function: FUN_1001ee38 at 1001ee38

void FUN_1001ee38(void)

{
  if (DAT_10030824 != (int *)0x0) {
    FUN_10001969(DAT_10030824);
    DAT_10030824 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001ee4f at 1001ee4f

void FUN_1001ee4f(void)

{
  if (DAT_10030828 != (int *)0x0) {
    FUN_10001969(DAT_10030828);
    DAT_10030828 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001ee66 at 1001ee66

void FUN_1001ee66(void)

{
  Ordinal_6(DAT_10030b10);
  return;
}



// Function: FUN_1001ee73 at 1001ee73

void FUN_1001ee73(void)

{
  Ordinal_6(DAT_10030c2c);
  return;
}



// Function: FUN_1001ee80 at 1001ee80

void FUN_1001ee80(void)

{
  Ordinal_6(DAT_10030c30);
  return;
}



// Function: FUN_1001ee8d at 1001ee8d

void FUN_1001ee8d(void)

{
  FID_conflict__Tidy(&DAT_10030a14,'\x01',0);
  return;
}



// Function: FUN_1001ee9c at 1001ee9c

void FUN_1001ee9c(void)

{
  FID_conflict__Tidy(&DAT_100309f8,'\x01',0);
  return;
}



// Function: FUN_1001eeab at 1001eeab

void FUN_1001eeab(void)

{
  FID_conflict__Tidy(&DAT_100309dc,'\x01',0);
  return;
}



// Function: FUN_1001eeba at 1001eeba

void FUN_1001eeba(void)

{
  FID_conflict__Tidy(&DAT_10030ba0,'\x01',0);
  return;
}



// Function: FUN_1001eec9 at 1001eec9

void FUN_1001eec9(void)

{
  FID_conflict__Tidy(&DAT_10030af4,'\x01',0);
  return;
}



// Function: FUN_1001eed8 at 1001eed8

void FUN_1001eed8(void)

{
  FID_conflict__Tidy(&DAT_10030bf4,'\x01',0);
  return;
}



// Function: FUN_1001eee7 at 1001eee7

void FUN_1001eee7(void)

{
  FID_conflict__Tidy(&DAT_10030a30,'\x01',0);
  return;
}



// Function: FUN_1001eef6 at 1001eef6

void FUN_1001eef6(void)

{
  FID_conflict__Tidy(&DAT_10030b4c,'\x01',0);
  return;
}



// Function: FUN_1001ef05 at 1001ef05

void FUN_1001ef05(void)

{
  FID_conflict__Tidy(&DAT_10030bbc,'\x01',0);
  return;
}



// Function: FUN_1001ef14 at 1001ef14

void FUN_1001ef14(void)

{
  FID_conflict__Tidy(&DAT_10030b84,'\x01',0);
  return;
}



// Function: FUN_1001ef23 at 1001ef23

void FUN_1001ef23(void)

{
  FID_conflict__Tidy(&DAT_10030bd8,'\x01',0);
  return;
}



// Function: FUN_1001ef32 at 1001ef32

void FUN_1001ef32(void)

{
  FID_conflict__Tidy(&DAT_10030b14,'\x01',0);
  return;
}



// Function: FUN_1001ef41 at 1001ef41

void FUN_1001ef41(void)

{
  FID_conflict__Tidy(&DAT_10030ad8,'\x01',0);
  return;
}



// Function: FUN_1001ef50 at 1001ef50

void FUN_1001ef50(void)

{
  FID_conflict__Tidy(&DAT_10030a4c,'\x01',0);
  return;
}



// Function: FUN_1001ef5f at 1001ef5f

void FUN_1001ef5f(void)

{
  FID_conflict__Tidy(&DAT_10030b30,'\x01',0);
  return;
}



// Function: FUN_1001ef6e at 1001ef6e

void FUN_1001ef6e(void)

{
  FID_conflict__Tidy(&DAT_10030a68,'\x01',0);
  return;
}



// Function: FUN_1001ef7d at 1001ef7d

void FUN_1001ef7d(void)

{
  FID_conflict__Tidy(&DAT_10030aa0,'\x01',0);
  return;
}



// Function: FUN_1001ef8c at 1001ef8c

void FUN_1001ef8c(void)

{
  FID_conflict__Tidy(&DAT_10030b68,'\x01',0);
  return;
}



// Function: FUN_1001ef9b at 1001ef9b

void FUN_1001ef9b(void)

{
  FID_conflict__Tidy(&DAT_10030c10,'\x01',0);
  return;
}



// Function: FUN_1001efaa at 1001efaa

void FUN_1001efaa(void)

{
  FID_conflict__Tidy(&DAT_10030a84,'\x01',0);
  return;
}



// Function: FUN_1001efb9 at 1001efb9

void FUN_1001efb9(void)

{
  FID_conflict__Tidy(&DAT_10030abc,'\x01',0);
  return;
}



// Function: FUN_1001efc8 at 1001efc8

void FUN_1001efc8(void)

{
  Ordinal_6(DAT_10030e80);
  return;
}



// Function: FUN_1001efd5 at 1001efd5

void FUN_1001efd5(void)

{
  Ordinal_6(DAT_10030e84);
  return;
}



// Function: FUN_1001efe2 at 1001efe2

void FUN_1001efe2(void)

{
  Ordinal_6(DAT_10030e88);
  return;
}



// Function: FUN_1001efef at 1001efef

void FUN_1001efef(void)

{
  FID_conflict__Tidy(&DAT_10030c34,'\x01',0);
  return;
}



// Function: FUN_1001effe at 1001effe

void FUN_1001effe(void)

{
  FID_conflict__Tidy(&DAT_10030c50,'\x01',0);
  return;
}



// Function: FUN_1001f00d at 1001f00d

void FUN_1001f00d(void)

{
  FID_conflict__Tidy(&DAT_10030c6c,'\x01',0);
  return;
}



// Function: FUN_1001f01c at 1001f01c

void FUN_1001f01c(void)

{
  FID_conflict__Tidy(&DAT_10030c88,'\x01',0);
  return;
}



// Function: FUN_1001f02b at 1001f02b

void FUN_1001f02b(void)

{
  FID_conflict__Tidy(&DAT_10030ca4,'\x01',0);
  return;
}



// Function: FUN_1001f03a at 1001f03a

void FUN_1001f03a(void)

{
  FID_conflict__Tidy(&DAT_10030cc0,'\x01',0);
  return;
}



// Function: FUN_1001f049 at 1001f049

void FUN_1001f049(void)

{
  FID_conflict__Tidy(&DAT_10030cdc,'\x01',0);
  return;
}



// Function: FUN_1001f058 at 1001f058

void FUN_1001f058(void)

{
  FID_conflict__Tidy(&DAT_10030cf8,'\x01',0);
  return;
}



// Function: FUN_1001f067 at 1001f067

void FUN_1001f067(void)

{
  FID_conflict__Tidy(&DAT_10030d14,'\x01',0);
  return;
}



// Function: FUN_1001f076 at 1001f076

void FUN_1001f076(void)

{
  FID_conflict__Tidy(&DAT_10030d30,'\x01',0);
  return;
}



// Function: FUN_1001f085 at 1001f085

void FUN_1001f085(void)

{
  FID_conflict__Tidy(&DAT_10030d4c,'\x01',0);
  return;
}



// Function: FUN_1001f094 at 1001f094

void FUN_1001f094(void)

{
  FID_conflict__Tidy(&DAT_10030d68,'\x01',0);
  return;
}



// Function: FUN_1001f0a3 at 1001f0a3

void FUN_1001f0a3(void)

{
  FID_conflict__Tidy(&DAT_10030d84,'\x01',0);
  return;
}



// Function: FUN_1001f0b2 at 1001f0b2

void FUN_1001f0b2(void)

{
  FID_conflict__Tidy(&DAT_10030da0,'\x01',0);
  return;
}



// Function: FUN_1001f0c1 at 1001f0c1

void FUN_1001f0c1(void)

{
  FID_conflict__Tidy(&DAT_10030dbc,'\x01',0);
  return;
}



// Function: FUN_1001f0d0 at 1001f0d0

void FUN_1001f0d0(void)

{
  FID_conflict__Tidy(&DAT_10030dd8,'\x01',0);
  return;
}



// Function: FUN_1001f0df at 1001f0df

void FUN_1001f0df(void)

{
  FID_conflict__Tidy(&DAT_10030df4,'\x01',0);
  return;
}



// Function: FUN_1001f0ee at 1001f0ee

void FUN_1001f0ee(void)

{
  FID_conflict__Tidy(&DAT_10030e10,'\x01',0);
  return;
}



// Function: FUN_1001f0fd at 1001f0fd

void FUN_1001f0fd(void)

{
  FID_conflict__Tidy(&DAT_10030e2c,'\x01',0);
  return;
}



// Function: FUN_1001f10c at 1001f10c

void FUN_1001f10c(void)

{
  FID_conflict__Tidy(&DAT_10030e48,'\x01',0);
  return;
}



// Function: FUN_1001f11b at 1001f11b

void FUN_1001f11b(void)

{
  FID_conflict__Tidy(&DAT_10030e64,'\x01',0);
  return;
}



// Function: FUN_1001f12a at 1001f12a

void FUN_1001f12a(void)

{
  Ordinal_6(DAT_100310d8);
  return;
}



// Function: FUN_1001f137 at 1001f137

void FUN_1001f137(void)

{
  Ordinal_6(DAT_100310dc);
  return;
}



// Function: FUN_1001f144 at 1001f144

void FUN_1001f144(void)

{
  Ordinal_6(DAT_100310e0);
  return;
}



// Function: FUN_1001f151 at 1001f151

void FUN_1001f151(void)

{
  FID_conflict__Tidy(&DAT_10030e8c,'\x01',0);
  return;
}



// Function: FUN_1001f160 at 1001f160

void FUN_1001f160(void)

{
  FID_conflict__Tidy(&DAT_10030ea8,'\x01',0);
  return;
}



// Function: FUN_1001f16f at 1001f16f

void FUN_1001f16f(void)

{
  FID_conflict__Tidy(&DAT_10030ec4,'\x01',0);
  return;
}



// Function: FUN_1001f17e at 1001f17e

void FUN_1001f17e(void)

{
  FID_conflict__Tidy(&DAT_10030ee0,'\x01',0);
  return;
}



// Function: FUN_1001f18d at 1001f18d

void FUN_1001f18d(void)

{
  FID_conflict__Tidy(&DAT_10030efc,'\x01',0);
  return;
}



// Function: FUN_1001f19c at 1001f19c

void FUN_1001f19c(void)

{
  FID_conflict__Tidy(&DAT_10030f18,'\x01',0);
  return;
}



// Function: FUN_1001f1ab at 1001f1ab

void FUN_1001f1ab(void)

{
  FID_conflict__Tidy(&DAT_10030f34,'\x01',0);
  return;
}



// Function: FUN_1001f1ba at 1001f1ba

void FUN_1001f1ba(void)

{
  FID_conflict__Tidy(&DAT_10030f50,'\x01',0);
  return;
}



// Function: FUN_1001f1c9 at 1001f1c9

void FUN_1001f1c9(void)

{
  FID_conflict__Tidy(&DAT_10030f6c,'\x01',0);
  return;
}



// Function: FUN_1001f1d8 at 1001f1d8

void FUN_1001f1d8(void)

{
  FID_conflict__Tidy(&DAT_10030f88,'\x01',0);
  return;
}



// Function: FUN_1001f1e7 at 1001f1e7

void FUN_1001f1e7(void)

{
  FID_conflict__Tidy(&DAT_10030fa4,'\x01',0);
  return;
}



// Function: FUN_1001f1f6 at 1001f1f6

void FUN_1001f1f6(void)

{
  FID_conflict__Tidy(&DAT_10030fc0,'\x01',0);
  return;
}



// Function: FUN_1001f205 at 1001f205

void FUN_1001f205(void)

{
  FID_conflict__Tidy(&DAT_10030fdc,'\x01',0);
  return;
}



// Function: FUN_1001f214 at 1001f214

void FUN_1001f214(void)

{
  FID_conflict__Tidy(&DAT_10030ff8,'\x01',0);
  return;
}



// Function: FUN_1001f223 at 1001f223

void FUN_1001f223(void)

{
  FID_conflict__Tidy(&DAT_10031014,'\x01',0);
  return;
}



// Function: FUN_1001f232 at 1001f232

void FUN_1001f232(void)

{
  FID_conflict__Tidy(&DAT_10031030,'\x01',0);
  return;
}



// Function: FUN_1001f241 at 1001f241

void FUN_1001f241(void)

{
  FID_conflict__Tidy(&DAT_1003104c,'\x01',0);
  return;
}



// Function: FUN_1001f250 at 1001f250

void FUN_1001f250(void)

{
  FID_conflict__Tidy(&DAT_10031068,'\x01',0);
  return;
}



// Function: FUN_1001f25f at 1001f25f

void FUN_1001f25f(void)

{
  FID_conflict__Tidy(&DAT_10031084,'\x01',0);
  return;
}



// Function: FUN_1001f26e at 1001f26e

void FUN_1001f26e(void)

{
  FID_conflict__Tidy(&DAT_100310a0,'\x01',0);
  return;
}



// Function: FUN_1001f27d at 1001f27d

void FUN_1001f27d(void)

{
  FID_conflict__Tidy(&DAT_100310bc,'\x01',0);
  return;
}



// Function: FUN_1001f28c at 1001f28c

void FUN_1001f28c(void)

{
  Ordinal_6(DAT_10031330);
  return;
}



// Function: FUN_1001f299 at 1001f299

void FUN_1001f299(void)

{
  Ordinal_6(DAT_10031334);
  return;
}



// Function: FUN_1001f2a6 at 1001f2a6

void FUN_1001f2a6(void)

{
  Ordinal_6(DAT_10031338);
  return;
}



// Function: FUN_1001f2b3 at 1001f2b3

void FUN_1001f2b3(void)

{
  FID_conflict__Tidy(&DAT_100310e4,'\x01',0);
  return;
}



// Function: FUN_1001f2c2 at 1001f2c2

void FUN_1001f2c2(void)

{
  FID_conflict__Tidy(&DAT_10031100,'\x01',0);
  return;
}



// Function: FUN_1001f2d1 at 1001f2d1

void FUN_1001f2d1(void)

{
  FID_conflict__Tidy(&DAT_1003111c,'\x01',0);
  return;
}



// Function: FUN_1001f2e0 at 1001f2e0

void FUN_1001f2e0(void)

{
  FID_conflict__Tidy(&DAT_10031138,'\x01',0);
  return;
}



// Function: FUN_1001f2ef at 1001f2ef

void FUN_1001f2ef(void)

{
  FID_conflict__Tidy(&DAT_10031154,'\x01',0);
  return;
}



// Function: FUN_1001f2fe at 1001f2fe

void FUN_1001f2fe(void)

{
  FID_conflict__Tidy(&DAT_10031170,'\x01',0);
  return;
}



// Function: FUN_1001f30d at 1001f30d

void FUN_1001f30d(void)

{
  FID_conflict__Tidy(&DAT_1003118c,'\x01',0);
  return;
}



// Function: FUN_1001f31c at 1001f31c

void FUN_1001f31c(void)

{
  FID_conflict__Tidy(&DAT_100311a8,'\x01',0);
  return;
}



// Function: FUN_1001f32b at 1001f32b

void FUN_1001f32b(void)

{
  FID_conflict__Tidy(&DAT_100311c4,'\x01',0);
  return;
}



// Function: FUN_1001f33a at 1001f33a

void FUN_1001f33a(void)

{
  FID_conflict__Tidy(&DAT_100311e0,'\x01',0);
  return;
}



// Function: FUN_1001f349 at 1001f349

void FUN_1001f349(void)

{
  FID_conflict__Tidy(&DAT_100311fc,'\x01',0);
  return;
}



// Function: FUN_1001f358 at 1001f358

void FUN_1001f358(void)

{
  FID_conflict__Tidy(&DAT_10031218,'\x01',0);
  return;
}



// Function: FUN_1001f367 at 1001f367

void FUN_1001f367(void)

{
  FID_conflict__Tidy(&DAT_10031234,'\x01',0);
  return;
}



// Function: FUN_1001f376 at 1001f376

void FUN_1001f376(void)

{
  FID_conflict__Tidy(&DAT_10031250,'\x01',0);
  return;
}



// Function: FUN_1001f385 at 1001f385

void FUN_1001f385(void)

{
  FID_conflict__Tidy(&DAT_1003126c,'\x01',0);
  return;
}



// Function: FUN_1001f394 at 1001f394

void FUN_1001f394(void)

{
  FID_conflict__Tidy(&DAT_10031288,'\x01',0);
  return;
}



// Function: FUN_1001f3a3 at 1001f3a3

void FUN_1001f3a3(void)

{
  FID_conflict__Tidy(&DAT_100312a4,'\x01',0);
  return;
}



// Function: FUN_1001f3b2 at 1001f3b2

void FUN_1001f3b2(void)

{
  FID_conflict__Tidy(&DAT_100312c0,'\x01',0);
  return;
}



// Function: FUN_1001f3c1 at 1001f3c1

void FUN_1001f3c1(void)

{
  FID_conflict__Tidy(&DAT_100312dc,'\x01',0);
  return;
}



// Function: FUN_1001f3d0 at 1001f3d0

void FUN_1001f3d0(void)

{
  FID_conflict__Tidy(&DAT_100312f8,'\x01',0);
  return;
}



// Function: FUN_1001f3df at 1001f3df

void FUN_1001f3df(void)

{
  FID_conflict__Tidy(&DAT_10031314,'\x01',0);
  return;
}



// Function: FUN_1001f3ee at 1001f3ee

void FUN_1001f3ee(void)

{
  FUN_10016cae(0x1003133c);
  return;
}



// Function: FUN_1001f3f8 at 1001f3f8

void FUN_1001f3f8(void)

{
  FUN_10016d63((int *)&DAT_10031374);
  return;
}



// Function: FUN_1001f402 at 1001f402

void FUN_1001f402(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_1003139c,DAT_10031340);
  RemoveAll((undefined4 *)&DAT_100313bc);
  return;
}



