/*
 * Decompiled from: OpenLoopModeLockIn.dll
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



// Function: FUN_10001055 at 10001055

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_10001055(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_1000108d at 1000108d

void FUN_1000108d(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_1001dc24);
}



// Function: AtlCrtErrorCheck at 100010a5

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
  else if ((param_1 == 0x16) || (param_1 == 0x22)) {
    uVar1 = 0x80070057;
  }
  else {
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000108d(uVar1);
}



// Function: FUN_100010dd at 100010dd

void __cdecl FUN_100010dd(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_100010fd at 100010fd

void __fastcall FUN_100010fd(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_1000110f at 1000110f

int * FUN_1000110f(int *param_1,int *param_2)

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



// Function: AtlComQIPtrAssign at 10001142

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



// Function: Attach at 10001179

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



// Function: FUN_10001198 at 10001198

void __fastcall FUN_10001198(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: InternalCopy at 100011a1

/* Library Function - Single Match
    public: void __thiscall ATL::CComVariant::InternalCopy(struct tagVARIANT const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall ATL::CComVariant::InternalCopy(CComVariant *this,tagVARIANT *param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_10(this,param_1);
  if (iVar1 < 0) {
    *(undefined2 *)this = 10;
    *(int *)(this + 8) = iVar1;
                    /* WARNING: Subroutine does not return */
    FUN_1000108d(iVar1);
  }
  return;
}



// Function: FUN_100011c9 at 100011c9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_100011c9(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_100011f7 at 100011f7

undefined * FUN_100011f7(void)

{
  return &DAT_10018a18;
}



// Function: FUN_100011fd at 100011fd

bool FUN_100011fd(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = _InlineIsEqualGUID((int *)PTR_DAT_100240e4,param_2);
  return iVar1 == 0;
}



// Function: FUN_10001221 at 10001221

undefined4 FUN_10001221(void)

{
  return 0;
}



// Function: FUN_10001226 at 10001226

undefined4 FUN_10001226(void)

{
  return 0;
}



// Function: FID_conflict:_Inside at 1000124c

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



// Function: FUN_10001288 at 10001288

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001288(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001294;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1001dc84);
}



// Function: FUN_10001319 at 10001319

void __fastcall FUN_10001319(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10001333 at 10001333

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001333(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_10013351;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: AtlAdd<> at 1000135d

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



// Function: FUN_10001381 at 10001381

int * __thiscall FUN_10001381(void *this,int param_1)

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
        FUN_1000108d(0x8007000e);
      }
    }
  }
  return (int *)this;
}



// Function: Copy at 100013be

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



// Function: FUN_100013db at 100013db

long __thiscall FUN_100013db(void *this,void *param_1,uint param_2)

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
      FUN_100010dd(pvVar4,local_10,*this,local_c);
    }
    FUN_100010dd((void *)((int)pvVar4 + uVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar4 + local_8 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar4;
  }
  return 0;
}



// Function: FUN_100014c7 at 100014c7

void __fastcall FUN_100014c7(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_100014cf at 100014cf

undefined2 * __thiscall FUN_100014cf(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) {
    *(undefined2 *)this = 8;
    iVar1 = Ordinal_2(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (param_1 == 0)) {
      return (undefined2 *)this;
    }
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000108d(iVar1);
}



// Function: FUN_10001518 at 10001518

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10001518(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_1000122b);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10001575 at 10001575

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001575(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000159a at 1000159a

undefined4 FUN_1000159a(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10018af0,param_1 + 4);
  }
  return uVar1;
}



// Function: FID_conflict:_Tidy at 100015c0

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



// Function: FUN_10001609 at 10001609

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001609(int param_1)

{
  FUN_10001333((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: CComBSTR at 1000162a

/* Library Function - Single Match
    public: __thiscall ATL::CComBSTR::CComBSTR(class ATL::CComBSTR const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

CComBSTR * __thiscall ATL::CComBSTR::CComBSTR(CComBSTR *this,CComBSTR *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = Copy(param_1);
  *(wchar_t **)this = pwVar1;
  if ((*(int *)param_1 != 0) && (pwVar1 == (wchar_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_1000108d(0x8007000e);
  }
  return this;
}



// Function: FUN_10001658 at 10001658

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001658(int param_1)

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



// Function: FUN_100016a3 at 100016a3

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100016a3(int param_1)

{
  int iVar1;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_18 = 0;
  local_1c = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_2c = local_2c & 0xffff0000;
  FUN_100014cf(&local_2c,(int)PTR_DAT_10024084);
  local_8._0_1_ = 3;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x34))
                    (*(int **)(param_1 + 0x2c),DAT_10025780,1,local_2c,uStack_28,uStack_24,uStack_20
                     ,&local_1c);
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_9(&local_2c);
  if (iVar1 < 0) {
    local_18 = 0x80004005;
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return local_18;
}



// Function: Catch@1000173c at 1000173c

undefined4 Catch_1000173c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10001720;
}



// Function: FUN_10001750 at 10001750

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10001750(int param_1)

{
  int iVar1;
  uint local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_18 = 0;
  local_1c = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_2c = local_2c & 0xffff0000;
  FUN_100014cf(&local_2c,(int)PTR_DAT_10024088);
  local_8._0_1_ = 3;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x34))
                    (*(int **)(param_1 + 0x2c),DAT_10025780,1,local_2c,uStack_28,uStack_24,uStack_20
                     ,&local_1c);
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_9(&local_2c);
  if (iVar1 < 0) {
    local_18 = 0x80004005;
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return local_18;
}



// Function: Catch@100017e9 at 100017e9

undefined4 Catch_100017e9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x100017cd;
}



// Function: FUN_100017fd at 100017fd

void FUN_100017fd(int param_1,undefined4 *param_2)

{
  FUN_1000159a(param_1,param_2);
  return;
}



// Function: ~basic_string<> at 10001806

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



// Function: FUN_10001810 at 10001810

undefined4 * __thiscall FUN_10001810(void *this,uint param_1,uint param_2)

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



// Function: FUN_10001891 at 10001891

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10001891(void *this,uint param_1)

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
  FUN_10001288((char *)(param_1 + 1));
  FUN_10001926();
  return;
}



// Function: Catch@100018f8 at 100018f8

undefined * Catch_100018f8(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001288((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001920;
}



// Function: FUN_10001926 at 10001926

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001926(void)

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



// Function: Catch@10001974 at 10001974

void Catch_10001974(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001989 at 10001989

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001989(undefined4 *param_1)

{
  *param_1 = CComErrorHandler::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xb] = 7;
  param_1[10] = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  return;
}



// Function: FUN_100019f2 at 100019f2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100019f2(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CComErrorHandler::vftable;
  FID_conflict__Tidy(param_1 + 6,'\x01',0);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001a8a at 10001a8a

undefined4 * __thiscall FUN_10001a8a(void *this,byte param_1)

{
  FUN_100019f2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001aa9 at 10001aa9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001aa9(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10001658(param_1);
  return;
}



// Function: FUN_10001ae5 at 10001ae5

undefined4 FUN_10001ae5(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 8);
    if (*piVar2 != 0) {
      FUN_1000110f(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10018ae0,piVar2);
  }
  return uVar1;
}



// Function: FUN_10001b1c at 10001b1c

undefined4 FUN_10001b1c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 4);
    if (*piVar2 != 0) {
      FUN_1000110f(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10018b00,piVar2);
  }
  return uVar1;
}



// Function: FUN_10001b53 at 10001b53

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10001b53(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1 + 1;
  *param_1 = CComECMPropertyPageHelperImpl<class_COpenLoopLockHelper>::vftable;
  *piVar1 = 0;
  piVar2 = param_1 + 2;
  *piVar2 = 0;
  if (*piVar1 != 0) {
    FUN_1000110f(piVar1,(int *)0x0);
  }
  if (*piVar2 != 0) {
    FUN_1000110f(piVar2,(int *)0x0);
  }
  return param_1;
}



// Function: FUN_10001bab at 10001bab

undefined4 FUN_10001bab(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_1000110f((int *)(param_1 + 4),(int *)0x0);
  }
  if (*(int *)(param_1 + 8) != 0) {
    FUN_1000110f((int *)(param_1 + 8),(int *)0x0);
  }
  return 1;
}



// Function: FUN_10001bda at 10001bda

bool __thiscall FUN_10001bda(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001891(this,param_1);
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



// Function: FUN_10001c44 at 10001c44

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001c44(int param_1)

{
  FUN_10001aa9(param_1 + 0x14);
  FUN_10001aa9(param_1);
  return;
}



// Function: FUN_10001c72 at 10001c72

void FUN_10001c72(int param_1,undefined4 *param_2)

{
  FUN_10001ae5(param_1,param_2);
  return;
}



// Function: FUN_10001c7b at 10001c7b

void FUN_10001c7b(int param_1,undefined4 *param_2)

{
  FUN_10001b1c(param_1,param_2);
  return;
}



// Function: FUN_10001c84 at 10001c84

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10001c84(undefined4 *param_1)

{
  FUN_10001b53(param_1);
  *param_1 = CComECMTestPageHelperImpl<class_COpenLoopLockHelper>::vftable;
  param_1[3] = CComECMTestPageHelperImpl<class_COpenLoopLockHelper>::vftable;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_10001cc0 at 10001cc0

undefined4 FUN_10001cc0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  uVar2 = 0x80004003;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10001cdc at 10001cdc

undefined4 FUN_10001cdc(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  uVar2 = 0x80004003;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10001cf8 at 10001cf8

undefined4 FUN_10001cf8(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  uVar2 = 0x80004003;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10001d14 at 10001d14

undefined4 FUN_10001d14(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  uVar2 = 0x80004003;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,param_2);
  }
  return uVar2;
}



// Function: FUN_10001d33 at 10001d33

void FUN_10001d33(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 4);
  if ((*piVar2 != 0) && (piVar1 = (int *)*piVar2, piVar1 != (int *)0x0)) {
    *piVar2 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)*param_2)(param_2,&DAT_10018b94,piVar2);
  return;
}



// Function: FUN_10001d64 at 10001d64

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10001d64(undefined4 *param_1)

{
  FUN_10001b53(param_1);
  *param_1 = CComECMPropertyPageHelperImpl2<class_COpenLoopLockHelper>::vftable;
  param_1[3] = CComECMPropertyPageHelperImpl2<class_COpenLoopLockHelper>::vftable;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_10001da0 at 10001da0

undefined4 * __thiscall FUN_10001da0(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10001810(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10001810(this,0,param_2);
  }
  else {
    bVar1 = FUN_10001bda(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 10001e3c

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
    bVar1 = FUN_10001bda(this,param_2,'\0');
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
    this = FUN_10001da0(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001eba at 10001eba

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10001eba(undefined4 *param_1)

{
  FUN_10001c84(param_1);
  FUN_10001d64(param_1 + 5);
  *param_1 = CComECMTestPageHelperImpl2<class_COpenLoopLockHelper>::vftable;
  param_1[3] = CComECMTestPageHelperImpl2<class_COpenLoopLockHelper>::vftable;
  param_1[5] = CComECMTestPageHelperImpl2<class_COpenLoopLockHelper>::vftable;
  param_1[8] = CComECMTestPageHelperImpl2<class_COpenLoopLockHelper>::vftable;
  return param_1;
}



// Function: FUN_10001f07 at 10001f07

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10001f07(int param_1)

{
  *(undefined4 *)(param_1 + 0x70) = 0;
  FUN_100011c9((void *)(param_1 + 0x74));
  FUN_10001eba((undefined4 *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x38) = 0;
  FUN_10001989((undefined4 *)(param_1 + 0x3c));
  return param_1;
}



// Function: FUN_10001f54 at 10001f54

undefined2 * __thiscall FUN_10001f54(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10001f86 at 10001f86

uint __fastcall FUN_10001f86(undefined4 *param_1)

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



// Function: FUN_10001fa6 at 10001fa6

undefined1 __fastcall FUN_10001fa6(int param_1)

{
  if (*(char *)(param_1 + 8) == '\0') {
    return 0;
  }
  SetCursor(*(HCURSOR *)(param_1 + 4));
  *(undefined1 *)(param_1 + 8) = 0;
  return 1;
}



// Function: FUN_10001fc4 at 10001fc4

int __cdecl FUN_10001fc4(ushort *param_1,ushort *param_2,int param_3)

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



// Function: _AtlGetStringResourceImage at 10001ff8

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



// Function: AtlGetStringResourceImage at 10002053

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



// Function: FUN_10002083 at 10002083

ATLSTRINGRESOURCEIMAGE * __cdecl FUN_10002083(uint param_1)

{
  HINSTANCE__ *pHVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  int iVar3;
  
  pAVar2 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_100268d4,0);
  iVar3 = 1;
  while ((pHVar1 != (HINSTANCE__ *)0x0 && (pAVar2 == (ATLSTRINGRESOURCEIMAGE *)0x0))) {
    pAVar2 = ATL::AtlGetStringResourceImage(pHVar1,param_1);
    pHVar1 = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_100268d4,iVar3);
    iVar3 = iVar3 + 1;
  }
  return pAVar2;
}



// Function: FUN_100020c2 at 100020c2

void __thiscall
FUN_100020c2(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_8 = 0;
  local_14 = param_2;
  local_c = param_3;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**this + 0x18))(*this,param_1,&PTR_1001b2c8,0x400,1,&local_14,param_4,0,0);
  return;
}



// Function: FUN_10002100 at 10002100

void __fastcall FUN_10002100(undefined4 *param_1)

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



// Function: FUN_10002119 at 10002119

int __thiscall FUN_10002119(void *this,uint param_1)

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



// Function: FUN_10002154 at 10002154

int __thiscall FUN_10002154(void *this,undefined4 param_1)

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



// Function: FUN_10002196 at 10002196

bool __cdecl FUN_10002196(HINSTANCE__ *param_1,uint param_2,int *param_3)

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



// Function: FUN_100021cd at 100021cd

bool __cdecl FUN_100021cd(uint param_1,int *param_2)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  int iVar2;
  
  pAVar1 = FUN_10002083(param_1);
  if (pAVar1 == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    *param_2 = 0;
  }
  else {
    iVar2 = Ordinal_4(pAVar1 + 2,*(undefined2 *)pAVar1);
    *param_2 = iVar2;
  }
  return *param_2 != 0;
}



// Function: FID_conflict:RegOpenKeyExA at 10002200

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
                    /* WARNING: Could not recover jumptable at 0x10002249. Too many branches */
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



// Function: Close at 10002257

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



// Function: Open at 10002272

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



// Function: QueryStringValue at 100022c1

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
              (*(short *)((int)param_2 + ((local_8 & 0xfffffffe) - 2)) != 0)) goto LAB_100022fd;
    }
    *puVar2 = local_8 >> 1;
    lVar4 = 0;
  }
  else {
LAB_100022fd:
    lVar4 = 0xd;
  }
  return lVar4;
}



// Function: FUN_10002330 at 10002330

void __thiscall FUN_10002330(void *this,uint *param_1,uint param_2)

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
      puVar2 = puVar1 + iVar5 * 8;
      uVar4 = *puVar2;
    } while (((((((puVar2[7] != 0 || puVar2[6] != 0) || puVar2[5] != 0) || puVar2[4] != 0) ||
               puVar2[3] != 0) || puVar2[2] != 0) || puVar2[1] != 0) || uVar4 != 0);
  }
  puVar1 = puVar1 + iVar5 * 8;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



// Function: FUN_100023a4 at 100023a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_100023a4(void)

{
  if ((DAT_10025974 & 1) == 0) {
    DAT_10025974 = DAT_10025974 | 1;
    _DAT_10025970 = 0;
    _DAT_1002596c = PTR_u__5CD1DEEB_ABBE_439f_BB98_1D2B501_10025678;
  }
  return &DAT_1002596c;
}



// Function: FUN_100023e4 at 100023e4

void __fastcall FUN_100023e4(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x100023ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + -8) + 0x14))();
  return;
}



// Function: FUN_100023f0 at 100023f0

undefined4 FUN_100023f0(void)

{
  return 0x4010;
}



// Function: FUN_100023f6 at 100023f6

undefined * FUN_100023f6(void)

{
  return &DAT_10018db8;
}



// Function: FUN_100023fc at 100023fc

bool FUN_100023fc(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = _InlineIsEqualGUID((int *)PTR_DAT_100243c4,param_2);
  return iVar1 == 0;
}



// Function: FUN_10002420 at 10002420

void __fastcall FUN_10002420(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FreeStdCallThunk((void *)*param_1);
  }
  return;
}



// Function: FUN_1000242d at 1000242d

void __thiscall FUN_1000242d(void *this,int param_1)

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



// Function: FUN_1000245d at 1000245d

void __fastcall FUN_1000245d(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x24;
  }
  if (*(int *)(iVar2 + 0x28) != 0) {
    (**(code **)(**(int **)(iVar2 + 0x28) + 8))(*(int **)(iVar2 + 0x28));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(iVar2 + 0x2c) + uVar3 * 4);
      (**(code **)(*piVar1 + 8))(piVar1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0xc));
  }
  operator_delete__(*(void **)(iVar2 + 0x2c));
  return;
}



// Function: FUN_100024a1 at 100024a1

void __fastcall FUN_100024a1(undefined4 *param_1)

{
  *param_1 = CComErrorDisplay<class_COpenLoopLockPage>::vftable;
  return;
}



// Function: FUN_100024a8 at 100024a8

void __fastcall FUN_100024a8(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100024b8 at 100024b8

undefined4 * __thiscall FUN_100024b8(void *this,byte param_1)

{
  *(undefined ***)this = CComErrorDisplay<class_COpenLoopLockPage>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100024d8 at 100024d8

void __thiscall FUN_100024d8(void *this,codecvt_base *param_1)

{
  bool bVar1;
  
  bVar1 = std::codecvt_base::always_noconv(param_1);
  if (bVar1) {
    *(undefined4 *)((int)this + 0x44) = 0;
  }
  else {
    *(codecvt_base **)((int)this + 0x44) = param_1;
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  }
  return;
}



// Function: Reset_back at 10002505

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



// Function: FUN_10002528 at 10002528

void FUN_10002528(LONG *param_1)

{
  LONG LVar1;
  
  if (param_1 != (LONG *)PTR_DAT_100243bc) {
    LVar1 = InterlockedDecrement(param_1);
    if (LVar1 < 1) {
      operator_delete__(param_1);
    }
  }
  return;
}



// Function: FUN_1000254e at 1000254e

void FUN_1000254e(UINT param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_100268dc,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = L'\0';
  }
  return;
}



// Function: FUN_10002576 at 10002576

int * __thiscall FUN_10002576(void *this,int param_1)

{
  int iVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  iVar1 = Ordinal_2(param_1);
  *(int *)this = iVar1;
  if ((iVar1 == 0) && (param_1 != 0)) {
    FUN_10012510(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_100025ac at 100025ac

void __fastcall FUN_100025ac(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  return;
}



// Function: FUN_100025cc at 100025cc

undefined4 * __thiscall FUN_100025cc(void *this,int *param_1)

{
  int *piVar1;
  
  *(int **)this = param_1;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return (undefined4 *)this;
}



// Function: FUN_100025f2 at 100025f2

void __fastcall FUN_100025f2(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x10002605. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_10002609 at 10002609

void __fastcall FUN_10002609(int param_1)

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



// Function: FUN_10002646 at 10002646

undefined4 __thiscall FUN_10002646(void *this,int *param_1)

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



// Function: FUN_1000266d at 1000266d

uint FUN_1000266d(byte param_1)

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



// Function: FUN_10002699 at 10002699

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

facet * __cdecl FUN_10002699(locale *param_1)

{
  uint uVar1;
  facet *pfVar2;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  facet *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x100026a5;
  std::_Lockit::_Lockit(local_18,0);
  local_8 = 0;
  local_14[0] = DAT_1002597c;
  uVar1 = std::locale::id::operator_unsigned_int((id *)id_exref);
  pfVar2 = (facet *)FUN_10002119(param_1,uVar1);
  if ((pfVar2 == (facet *)0x0) && (pfVar2 = local_14[0], local_14[0] == (facet *)0x0)) {
    uVar1 = std::ctype<wchar_t>::_Getcat(local_14,param_1);
    pfVar2 = local_14[0];
    if (uVar1 == 0xffffffff) {
      std::bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_1001e154);
    }
    DAT_1002597c = local_14[0];
    std::locale::facet::_Incref(local_14[0]);
    Facet_Register(pfVar2);
  }
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_18);
  return pfVar2;
}



// Function: FUN_1000273d at 1000273d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000273d(int param_1)

{
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0xc));
  }
  return;
}



// Function: FUN_10002763 at 10002763

void __thiscall FUN_10002763(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_1000276f at 1000276f

void __fastcall FUN_1000276f(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10002776 at 10002776

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

facet * __cdecl FUN_10002776(locale *param_1)

{
  uint uVar1;
  facet *pfVar2;
  bad_cast local_24 [12];
  _Lockit local_18 [4];
  facet *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10002782;
  std::_Lockit::_Lockit(local_18,0);
  local_8 = 0;
  local_14[0] = DAT_10025980;
  uVar1 = std::locale::id::operator_unsigned_int((id *)id_exref);
  pfVar2 = (facet *)FUN_10002119(param_1,uVar1);
  if ((pfVar2 == (facet *)0x0) && (pfVar2 = local_14[0], local_14[0] == (facet *)0x0)) {
    uVar1 = std::codecvt<wchar_t,char,int>::_Getcat(local_14,param_1);
    pfVar2 = local_14[0];
    if (uVar1 == 0xffffffff) {
      std::bad_cast::bad_cast(local_24,"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_1001e154);
    }
    DAT_10025980 = local_14[0];
    std::locale::facet::_Incref(local_14[0]);
    Facet_Register(pfVar2);
  }
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_18);
  return pfVar2;
}



// Function: FUN_1000281a at 1000281a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1000281a(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10002826;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1001dc84);
  }
  return;
}



// Function: FUN_10002874 at 10002874

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10002874(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10002880;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x5555556) &&
     (pvVar1 = operator_new((int)param_1 * 0x30), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1001dc84);
}



// Function: FUN_100028d3 at 100028d3

uint __thiscall FUN_100028d3(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
  uVar1 = FUN_10001fc4((ushort *)((int)this + param_1 * 2),param_3,uVar1);
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



// Function: FUN_10002937 at 10002937

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10002937(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10002943;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1001dc84);
}



// Function: FUN_10002996 at 10002996

undefined4 * __thiscall FUN_10002996(void *this,char param_1,LPCWSTR param_2,char param_3)

{
  HINSTANCE hInstance;
  HCURSOR pHVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 8) = 0;
  hInstance = DAT_100268dc;
  if (param_3 != '\0') {
    hInstance = (HINSTANCE)0x0;
  }
  pHVar1 = LoadCursorW(hInstance,param_2);
  *(HCURSOR *)this = pHVar1;
  if (param_1 != '\0') {
    FUN_10001f86((undefined4 *)this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100029d3 at 100029d3

undefined1 __fastcall FUN_100029d3(int param_1)

{
  if (*(char *)(param_1 + 8) == '\0') {
    return 0;
  }
  SetCursor(*(HCURSOR *)(param_1 + 4));
  *(undefined1 *)(param_1 + 8) = 0;
  return 1;
}



// Function: FUN_100029d8 at 100029d8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100029d8(void *this,int *param_1)

{
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002a06 at 10002a06

void __thiscall FUN_10002a06(void *this,HINSTANCE__ *param_1,uint param_2)

{
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  FUN_10002196(param_1,param_2,(int *)this);
  return;
}



// Function: FUN_10002a2b at 10002a2b

void __thiscall FUN_10002a2b(void *this,uint param_1)

{
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  FUN_100021cd(param_1,(int *)this);
  return;
}



// Function: FUN_10002a4c at 10002a4c

undefined2 * __thiscall FUN_10002a4c(void *this,CComBSTR *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) {
    *(undefined2 *)this = 8;
    pwVar2 = ATL::CComBSTR::Copy(param_1);
    *(wchar_t **)((int)this + 8) = pwVar2;
    if ((pwVar2 != (wchar_t *)0x0) || (*(int *)param_1 == 0)) {
      return (undefined2 *)this;
    }
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1000108d(iVar1);
}



// Function: FUN_10002a97 at 10002a97

LSTATUS __fastcall FUN_10002a97(undefined4 *param_1)

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



// Function: FUN_10002a9c at 10002a9c

undefined4 FUN_10002a9c(void *param_1)

{
  FUN_10001381(param_1,0x10018b10);
  return 0;
}



// Function: FUN_10002ab2 at 10002ab2

undefined4 * __thiscall FUN_10002ab2(void *this,byte param_1)

{
  FUN_1000276f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002ad1 at 10002ad1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10002ad1(void *this,void *param_1)

{
  *(undefined ***)this = MessageFiringService<enum_tagTestContainerEvents>::vftable;
  *(int *)((int)this + 4) = 0;
  FUN_10002646(param_1,(int *)((int)this + 4));
  return (undefined4 *)this;
}



// Function: FUN_10002b0f at 10002b0f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002b0f(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = MessageFiringService<enum_tagTestContainerEvents>::vftable;
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



// Function: FUN_10002b57 at 10002b57

undefined4 * __thiscall FUN_10002b57(void *this,byte param_1)

{
  FUN_10002b0f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002b76 at 10002b76

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002b76(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10002b9b at 10002b9b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10002b9b(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *(undefined ***)this = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  *(undefined1 *)((int)this + 0x50) = 0;
  *(undefined1 *)((int)this + 0x4a) = 0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *(undefined4 *)((int)this + 0x54) = param_1;
  uVar1 = DAT_10025978;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x4c) = uVar1;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10002bec at 10002bec

int __cdecl FUN_10002bec(wint_t *param_1,FILE *param_2)

{
  wint_t wVar1;
  uint3 uVar2;
  
  wVar1 = fgetwc(param_2);
  uVar2 = (uint3)(byte)(wVar1 >> 8);
  if (wVar1 == 0xffff) {
    return (uint)uVar2 << 8;
  }
  *param_1 = wVar1;
  return CONCAT31(uVar2,1);
}



// Function: FUN_10002c14 at 10002c14

bool __cdecl FUN_10002c14(wchar_t param_1,FILE *param_2)

{
  wint_t wVar1;
  
  wVar1 = fputwc(param_1,param_2);
  return wVar1 != 0xffff;
}



// Function: FUN_10002c34 at 10002c34

undefined4 __cdecl FUN_10002c34(wint_t *param_1,FILE *param_2)

{
  wint_t wVar1;
  undefined2 extraout_var;
  
  wVar1 = ungetwc(*param_1,param_2);
  return CONCAT31((int3)(CONCAT22(extraout_var,wVar1) >> 8),wVar1 != 0xffff);
}



// Function: FUN_10002c58 at 10002c58

void __fastcall FUN_10002c58(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _lock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_10002c68 at 10002c68

void __fastcall FUN_10002c68(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _unlock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: underflow at 10002c78

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::basic_filebuf<unsigned short,struct
   std::char_traits<unsigned short> >::underflow(void)
    protected: virtual unsigned short __thiscall std::basic_filebuf<wchar_t,struct
   std::char_traits<wchar_t> >::underflow(void)
   
   Library: Visual Studio 2010 Release */

short __fastcall underflow(int *param_1)

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



// Function: FUN_10002cba at 10002cba

undefined4 __fastcall FUN_10002cba(int *param_1)

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



// Function: Set_back at 10002cec

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



// Function: FUN_10002d25 at 10002d25

uint __thiscall FUN_10002d25(void *this,uint param_1)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = param_1;
  uVar4 = **(uint **)((int)this + 0x20);
  sVar1 = (short)param_1;
  if (((uVar4 != 0) && (**(uint **)((int)this + 0x10) < uVar4)) &&
     (((short)param_1 == -1 || (*(short *)(uVar4 - 2) == (short)param_1)))) {
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Gndec
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    if (sVar1 != -1) {
      return uVar2 & 0xffff;
    }
    return 0;
  }
  if ((*(FILE **)((int)this + 0x54) == (FILE *)0x0) || ((short)param_1 == -1)) {
LAB_10002daa:
    uVar4 = 0xffff;
  }
  else {
    if (*(int *)((int)this + 0x44) == 0) {
      param_1 = param_1 & 0xffff;
      uVar3 = FUN_10002c34((wint_t *)&param_1,*(FILE **)((int)this + 0x54));
      if ((char)uVar3 == '\0') goto LAB_10002d94;
    }
    else {
LAB_10002d94:
      if ((short *)**(int **)((int)this + 0x20) == (short *)((int)this + 0x48)) goto LAB_10002daa;
      *(short *)((int)this + 0x48) = sVar1;
      uVar3 = Set_back((int)this);
    }
    uVar4 = CONCAT22((short)((uint)uVar3 >> 0x10),sVar1);
  }
  return uVar4;
}



// Function: FUN_10002db3 at 10002db3

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10002db3(void *this,char *param_1,int param_2,int param_3)

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
      uVar1 = DAT_10025978;
      *(undefined4 *)((int)this + 0x44) = 0;
      *(undefined4 *)((int)this + 0x4c) = uVar1;
      return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
    }
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
}



// Function: FUN_10002e1a at 10002e1a

void __thiscall FUN_10002e1a(void *this,locale *param_1)

{
  facet *pfVar1;
  
  pfVar1 = FUN_10002776(param_1);
  FUN_100024d8(this,(codecvt_base *)pfVar1);
  return;
}



// Function: FUN_10002e36 at 10002e36

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10002e36(void *this,wchar_t *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  _iobuf *p_Var2;
  locale *plVar3;
  facet *pfVar4;
  
  if ((*(int *)((int)this + 0x54) == 0) &&
     (p_Var2 = std::_Fiopen(param_1,param_2,param_3), p_Var2 != (_iobuf *)0x0)) {
    *(undefined1 *)((int)this + 0x50) = 1;
    *(undefined1 *)((int)this + 0x4a) = 0;
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *(_iobuf **)((int)this + 0x54) = p_Var2;
    uVar1 = DAT_10025978;
    *(undefined4 *)((int)this + 0x44) = 0;
    *(undefined4 *)((int)this + 0x4c) = uVar1;
    plVar3 = (locale *)
             std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::getloc
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    pfVar4 = FUN_10002776(plVar3);
    FUN_100024d8(this,(codecvt_base *)pfVar4);
    FUN_10002100(&param_3);
    return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
}



// Function: FUN_10002eba at 10002eba

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10002eba(void *this,int *param_1)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  
  FUN_100025cc(this,param_1);
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (this_00 = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
                 (*(int *)(*param_1 + 4) + 0x3c + (int)param_1),
     this_00 != (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush(this_00);
  }
  *(bool *)((int)this + 4) = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0;
  return this;
}



// Function: FUN_10002f12 at 10002f12

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002f12(int *param_1)

{
  bool bVar1;
  
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx
              ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)*param_1);
  }
  FUN_100025f2(param_1);
  return;
}



// Function: FUN_10002f4a at 10002f4a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002f4a(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  *(undefined ***)param_1 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_10002609((int)param_1);
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  return;
}



// Function: FUN_10002f7c at 10002f7c

undefined4 __fastcall FUN_10002f7c(int param_1)

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



// Function: FUN_10002fe0 at 10002fe0

void __thiscall
FUN_10002fe0(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

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
      if (param_2 == 0 && param_3 == 0) goto LAB_1000316c;
    }
    else {
      if (param_4 == 2) {
        iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
LAB_100030fc:
        bVar5 = CARRY4(param_2,iVar3 >> 1);
        param_2 = param_2 + (iVar3 >> 1);
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar5;
      }
      else {
        if (param_4 == 1) {
          iVar3 = uVar2 - **(int **)((int)this + 0x10);
          goto LAB_100030fc;
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
          goto LAB_1000316c;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar1 = *(int *)((int)this + 0x3c);
LAB_1000302b:
      iVar1 = iVar1 - **(int **)((int)this + 0x10);
      uVar2 = iVar1 >> 1;
      bVar5 = CARRY4(param_2,uVar2);
      param_2 = param_2 + uVar2;
      param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar5;
    }
    else if (param_4 == 1) {
      iVar1 = iVar3;
      if ((param_5 & 2) == 0) goto LAB_1000302b;
LAB_10003045:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    else if (param_4 != 0) goto LAB_10003045;
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
        goto LAB_1000316c;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_1000316c:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10003186 at 10003186

void __thiscall FUN_10003186(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

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



// Function: FUN_1000329e at 1000329e

short __thiscall FUN_1000329e(void *this,short param_1)

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



// Function: FUN_100032fb at 100032fb

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_100032fb(void *this,byte param_1)

{
  FUN_10002f4a((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_1000331a at 1000331a

void __fastcall FUN_1000331a(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_100243bc) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
  }
  return;
}



// Function: FUN_10003346 at 10003346

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10003346(void *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    *(undefined **)this = PTR_DAT_100243c0;
    return 1;
  }
  FUN_100126e8(param_1 * 2 + 0xe);
  uVar1 = FUN_10003394();
  return uVar1;
}



// Function: Catch@10003381 at 10003381

undefined * Catch_10003381(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000338b;
}



// Function: FUN_10003394 at 10003394

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10003394(void)

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



// Function: FUN_100033bb at 100033bb

void __fastcall FUN_100033bb(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_100243bc) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
    *param_1 = (int)PTR_DAT_100243c0;
  }
  return;
}



// Function: _Chassign at 100033ee

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



// Function: FUN_1000342a at 1000342a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000342a(void *this,int param_1)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_10002576(this_00,param_1);
  }
  *(int **)this = piVar1;
  if (piVar1 == (int *)0x0) {
    FUN_10012510(0x8007000e);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003477 at 10003477

void __fastcall FUN_10003477(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10003481 at 10003481

void __fastcall FUN_10003481(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x24;
  }
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 4) = 0;
  return;
}



// Function: FUN_100034b4 at 100034b4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100034b4(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  return;
}



// Function: FUN_100034e4 at 100034e4

void __fastcall FUN_100034e4(int *param_1)

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



// Function: FUN_1000351f at 1000351f

void __thiscall FUN_1000351f(void *this,int param_1)

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



// Function: FUN_10003564 at 10003564

void __thiscall FUN_10003564(void *this,int *param_1)

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



// Function: FUN_100035ab at 100035ab

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_100035ab(int *param_1,char *param_2)

{
  uint uVar1;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  ushort uVar2;
  wchar_t wVar3;
  locale *plVar4;
  int iVar5;
  bool bVar6;
  undefined1 local_38 [4];
  char local_34;
  size_t local_30;
  int local_2c;
  int local_28;
  int local_24;
  facet *local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x100035b7;
  local_18 = 0;
  local_30 = strlen(param_2);
  iVar5 = 0;
  uVar1 = *(uint *)(*(int *)(*param_1 + 4) + 0x20 + (int)param_1);
  local_24 = *(int *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1);
  if ((local_24 < 0) ||
     ((((local_24 < 1 && (uVar1 == 0)) || (local_24 < 0)) || ((local_24 < 1 && (uVar1 <= local_30)))
      ))) {
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = uVar1 - local_30;
    local_24 = local_24 - (uint)(uVar1 < local_30);
  }
  FUN_10002eba(local_38,param_1);
  local_8 = 0;
  if (local_34 == '\0') {
    local_18 = 4;
    FUN_10003770();
    return;
  }
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  plVar4 = (locale *)std::ios_base::getloc((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  local_8._0_1_ = 2;
  local_20 = FUN_10002699(plVar4);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10002100(&local_1c);
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_24 < 0) || ((local_24 < 1 && (local_28 == 0)))) goto LAB_10003694;
      uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar2 == 0xffff) break;
      bVar6 = local_28 != 0;
      local_28 = local_28 + -1;
      local_24 = local_24 + -1 + (uint)bVar6;
    }
    local_18 = local_18 | 4;
  }
LAB_10003694:
  do {
    if (local_18 != 0) goto LAB_10003731;
    if ((iVar5 < 0) || ((iVar5 < 1 && (local_30 == 0)))) break;
    this = *(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
            (*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
    wVar3 = std::ctype<wchar_t>::widen((ctype<wchar_t> *)local_20,*param_2);
    uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc(this,wVar3);
    if (uVar2 == 0xffff) {
      local_18 = 4;
    }
    bVar6 = local_30 != 0;
    local_30 = local_30 - 1;
    iVar5 = iVar5 + -1 + (uint)bVar6;
    param_2 = param_2 + 1;
    local_2c = iVar5;
  } while( true );
LAB_100036ff:
  if ((local_24 < 0) || ((local_24 < 1 && (local_28 == 0)))) goto LAB_10003731;
  uVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                    (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                      (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                     *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
  if (uVar2 == 0xffff) {
    local_18 = local_18 | 4;
LAB_10003731:
    iVar5 = *(int *)(*param_1 + 4);
    *(undefined4 *)(iVar5 + 0x20 + (int)param_1) = 0;
    *(undefined4 *)(iVar5 + 0x24 + (int)param_1) = 0;
    local_8 = 0;
    FUN_10003770();
    return;
  }
  bVar6 = local_28 != 0;
  local_28 = local_28 + -1;
  local_24 = local_24 + -1 + (uint)bVar6;
  goto LAB_100036ff;
}



// Function: Catch@1000374d at 1000374d

undefined * Catch_1000374d(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000376b;
}



// Function: FUN_10003770 at 10003770

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10003770(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  bool unaff_DI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),unaff_DI);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10002f12((int *)(unaff_EBP + -0x34));
  return;
}



// Function: FUN_10003795 at 10003795

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10003795(int *param_1,wchar_t *param_2)

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
  local_8 = 0x100037a1;
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
  FUN_10002eba(local_28,param_1);
  local_8 = 0;
  if (local_24 == '\0') {
    local_18 = 4;
    FUN_100038fa();
    return;
  }
  local_8 = 1;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_10003852;
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
LAB_10003852:
    if (local_18 != 0) goto LAB_1000387b;
  }
  _Var6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                    (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                      (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                     (ulonglong)CONCAT22(in_stack_ffffffca,in_stack_ffffffc8) << 0x20);
  if (((size_t)_Var6 == sVar4) && ((int)((ulonglong)_Var6 >> 0x20) == 0)) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_1000387b;
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
LAB_1000387b:
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  local_8 = 0;
  FUN_100038fa();
  return;
}



// Function: Catch@100038d9 at 100038d9

undefined * Catch_100038d9(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_100038f7;
}



// Function: FUN_100038fa at 100038fa

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100038fa(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10002f12((int *)(unaff_EBP + -0x24));
  return;
}



// Function: FUN_10003920 at 10003920

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003920(undefined4 *param_1)

{
  *param_1 = CContextSensitiveHelpProvider<class_COpenLoopLockPage>::vftable;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  FUN_10001381(param_1 + 4,0x10018b10);
  param_1[1] = 0;
  return param_1;
}



// Function: FUN_10003978 at 10003978

int * __thiscall FUN_10003978(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_1000399e at 1000399e

void __fastcall FUN_1000399e(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100039ab at 100039ab

void __thiscall FUN_100039ab(void *this,GUID *param_1)

{
  int iVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  iVar1 = Ordinal_2(local_88);
  *(int *)this = iVar1;
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1000108d(0x8007000e);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003a02 at 10003a02

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003a02(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



// Function: FUN_10003a38 at 10003a38

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003a38(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CContextSensitiveHelpProvider<class_COpenLoopLockPage>::vftable;
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



// Function: FUN_10003a99 at 10003a99

void __fastcall FUN_10003a99(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10003ab3 at 10003ab3

void __fastcall FUN_10003ab3(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10003acb at 10003acb

undefined4 * __thiscall FUN_10003acb(void *this,byte param_1)

{
  FUN_10003a38((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003aea at 10003aea

void __thiscall FUN_10003aea(void *this,ushort *param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(ushort **)param_1;
  }
  FUN_100028d3(this,0,*(uint *)((int)this + 0x10),param_1,*puVar1);
  return;
}



// Function: FUN_10003b0b at 10003b0b

void __fastcall FUN_10003b0b(undefined4 *param_1)

{
  operator_delete((void *)*param_1);
  return;
}



// Function: FUN_10003b14 at 10003b14

void * __thiscall FUN_10003b14(void *this,LPCWSTR param_1)

{
  uint uVar1;
  long lVar2;
  
  uVar1 = lstrlenW(param_1);
  lVar2 = FUN_100013db(this,param_1,uVar1);
  if (lVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1000108d(lVar2);
  }
  return this;
}



// Function: FUN_10003b3f at 10003b3f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT __fastcall FUN_10003b3f(void *param_1)

{
  undefined4 *puVar1;
  uint local_3c [2];
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  HRESULT local_1c;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x10003b4b;
  FUN_10002330(param_1,local_3c,*(uint *)((int)param_1 + 0x14));
  if (local_34 == 0) {
    local_1c = CoCreateInstance((IID *)&DAT_1001b0e8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10018ea0,
                                (LPVOID *)((int)param_1 + 8));
    if (-1 < local_1c) {
      puVar1 = *(undefined4 **)((int)param_1 + 8);
      local_1c = (**(code **)*puVar1)(puVar1,&DAT_10018ee4,(int)param_1 + 0x10);
    }
  }
  else {
    local_14[0] = (int *)0x0;
    local_8 = 1;
    local_1c = CoCreateInstance((IID *)&DAT_1001b108,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10018ec0,
                                local_14);
    if (-1 < local_1c) {
      (**(code **)*local_14[0])(local_14[0],&DAT_10018ee4,(int)param_1 + 0x10);
      (**(code **)*local_14[0])(local_14[0],&DAT_10018ea0,(int)param_1 + 8);
      puVar1 = (undefined4 *)((int)param_1 + 4);
      local_1c = (**(code **)*local_14[0])(local_14[0],&DAT_10018ef4,puVar1);
      if (-1 < local_1c) {
        local_18 = 0;
        local_8._0_1_ = 2;
        Ordinal_6(0);
        local_18 = 0;
        FUN_100021cd(local_34,&local_18);
        (**(code **)(*(int *)*puVar1 + 0x10))((int *)*puVar1,local_18);
        (**(code **)(*(int *)*puVar1 + 0x18))((int *)*puVar1,local_2c);
        (**(code **)(*(int *)*puVar1 + 0x20))((int *)*puVar1,local_30);
        local_8 = CONCAT31(local_8._1_3_,1);
        Ordinal_6(local_18);
      }
    }
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  return local_1c;
}



// Function: FUN_10003c62 at 10003c62

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10003c62(int param_1)

{
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_38 = 0xce38368b;
  uStack_34 = 0x46c12bd3;
  uStack_30 = 0x7c4a4ab3;
  uStack_2c = 0x9a7e3936;
  local_18 = 0;
  local_3c = 0;
  local_40 = 0;
  local_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0xc0;
  local_50 = 0;
  local_4c = 0;
  local_54 = 0;
  local_58 = 0;
  uStack_1c = 0x46000000;
  local_44 = (int *)0x0;
  local_8 = 1;
  local_48 = param_1;
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),&DAT_10018ae0,&local_44)
  ;
  (**(code **)(**(int **)(local_48 + 0xc) + 0xc))
            (*(int **)(local_48 + 0xc),&local_40,0,&local_58,local_44,0);
  local_8 = 0xffffffff;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))(local_44);
  }
  FUN_100127fb();
  return;
}



// Function: FUN_10003cf1 at 10003cf1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003cf1(int param_1)

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
  FUN_1000245d(param_1 + 4);
  return;
}



// Function: FUN_10003d7f at 10003d7f

void __thiscall FUN_10003d7f(void *this,wchar_t *param_1,int param_2,int param_3)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar1;
  
  pbVar1 = FUN_10002e36((void *)((int)this + 0x18),param_1,param_2,param_3);
                    /* WARNING: Load size is inaccurate */
  if (pbVar1 == (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0) {
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(*this + 4) + (int)this),2,false);
  }
  else {
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::clear
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(*this + 4) + (int)this),0,false);
  }
  return;
}



// Function: FUN_10003dbc at 10003dbc

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10003dbc(void *this,undefined4 param_1)

{
  int *piVar1;
  int *local_58;
  undefined2 local_54 [8];
  undefined2 local_44 [8];
  undefined2 local_34 [8];
  undefined2 local_24 [14];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 3;
  piVar1 = *(int **)((int)this + 4);
  local_58 = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  local_8._0_1_ = 6;
  local_54[0] = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)local_54,(tagVARIANT *)&stack0x00000038);
  local_8._0_1_ = 7;
  local_44[0] = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)local_44,(tagVARIANT *)&stack0x00000028);
  local_8._0_1_ = 8;
  local_34[0] = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)local_34,(tagVARIANT *)&stack0x00000018);
  local_8._0_1_ = 9;
  local_24[0] = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)local_24,(tagVARIANT *)&stack0x00000008);
  local_8._0_1_ = 10;
  FUN_100020c2(&local_58,param_1,local_54,4,0);
  local_8._0_1_ = 6;
  _eh_vector_destructor_iterator_(local_54,0x10,4,FUN_100014c7);
  local_8._0_1_ = 3;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 2;
  Ordinal_9(&stack0x00000008);
  local_8._0_1_ = 1;
  Ordinal_9(&stack0x00000018);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(&stack0x00000028);
  local_8 = 0xffffffff;
  Ordinal_9(&stack0x00000038);
  FUN_100127fb();
  return;
}



// Function: FUN_10003eb1 at 10003eb1

undefined4 * __thiscall FUN_10003eb1(void *this,uint param_1,uint param_2)

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



// Function: _Tidy at 10003f2b

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



// Function: FUN_10003f6f at 10003f6f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003f6f(undefined4 *param_1)

{
  int *piVar1;
  
  FUN_10003481((int)(param_1 + 1));
  *param_1 = CComECMPropertyPageImpl<class_COpenLoopLockPage>::vftable;
  param_1[1] = CComECMPropertyPageImpl<class_COpenLoopLockPage>::vftable;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  piVar1 = param_1 + 0xe;
  *piVar1 = 0;
  param_1[0xf] = 0;
  if (*piVar1 != 0) {
    FUN_1000110f(piVar1,(int *)0x0);
  }
  param_1[0x10] = 0;
  return param_1;
}



// Function: FUN_10003fe4 at 10003fe4

undefined4 __thiscall FUN_10003fe4(void *this,int param_1,undefined4 param_2)

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



// Function: FUN_10004019 at 10004019

void __thiscall FUN_10004019(void *this,int param_1,undefined4 param_2)

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
  FUN_10003fe4(*this,param_1,param_2);
  return;
}



// Function: FUN_10004041 at 10004041

void __cdecl FUN_10004041(wchar_t *param_1,ushort param_2,uint *param_3,uint *param_4)

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
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
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
        goto LAB_10004182;
      }
      ReleaseDC((HWND)0x0,hdc);
    }
  }
  uVar2 = GetDialogBaseUnits();
  *param_3 = uVar2 & 0xffff;
  param_3[1] = uVar2 >> 0x10;
  *local_a4 = uVar2 >> 0x10;
LAB_10004182:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: HasFont at 10004191

/* Library Function - Single Match
    int __cdecl HasFont(struct DLGTEMPLATE const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release */

int __cdecl HasFont(DLGTEMPLATE *param_1)

{
  uint uVar1;
  
  if (*(short *)(param_1 + 2) == -1) {
    uVar1 = *(uint *)(param_1 + 0xc);
  }
  else {
    uVar1 = *(uint *)param_1;
  }
  return uVar1 & 0x40;
}



// Function: GetFontSizeField at 100041ae

/* Library Function - Single Match
    protected: static unsigned char * __cdecl CDialogTemplate::GetFontSizeField(struct DLGTEMPLATE
   const *)
   
   Library: Visual Studio 2010 Release */

uchar * __cdecl CDialogTemplate::GetFontSizeField(DLGTEMPLATE *param_1)

{
  short sVar1;
  DLGTEMPLATE *pDVar2;
  
  if (*(short *)(param_1 + 2) == -1) {
    pDVar2 = param_1 + 0x1a;
  }
  else {
    pDVar2 = param_1 + 0x12;
  }
  if (*(short *)pDVar2 == -1) {
    pDVar2 = pDVar2 + 4;
  }
  else {
    do {
      sVar1 = *(short *)pDVar2;
      pDVar2 = pDVar2 + 2;
    } while (sVar1 != 0);
  }
  if (*(short *)pDVar2 == -1) {
    pDVar2 = pDVar2 + 4;
  }
  else {
    do {
      sVar1 = *(short *)pDVar2;
      pDVar2 = pDVar2 + 2;
    } while (sVar1 != 0);
  }
  do {
    sVar1 = *(short *)pDVar2;
    pDVar2 = pDVar2 + 2;
  } while (sVar1 != 0);
  return (uchar *)pDVar2;
}



// Function: FUN_10004200 at 10004200

void __cdecl FUN_10004200(int param_1,int *param_2)

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



// Function: FUN_1000422f at 1000422f

undefined4 FUN_1000422f(undefined4 param_1,undefined2 *param_2)

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



// Function: FUN_1000424b at 1000424b

void FUN_1000424b(int *param_1,short *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2);
  if ((-1 < iVar1) && (*param_2 == 0)) {
    (**(code **)(*param_1 + 0x28))(param_1,param_2);
  }
  return;
}



// Function: FUN_10004274 at 10004274

undefined4 FUN_10004274(void)

{
  return 0x80004001;
}



// Function: FUN_1000427c at 1000427c

int FUN_1000427c(undefined4 param_1,int param_2)

{
  return (uint)(param_2 == 0) * 2 + -0x7fffbfff;
}



// Function: FUN_10004292 at 10004292

undefined4 FUN_10004292(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x24;
  }
  if (param_2 == (int *)0x0) {
    piVar1 = *(int **)(iVar2 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(iVar2 + 0x28) = 0;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x28) != 0) {
      return 0x8000ffff;
    }
    *(int **)(iVar2 + 0x28) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
  }
  return 0;
}



// Function: FUN_100042db at 100042db

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100042db(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x24;
  }
  if (param_3 == 0) {
    return 0x80004003;
  }
  if ((*(int *)(iVar3 + 0x2c) != 0) && (*(int *)(iVar3 + 0x30) != 0)) {
    uVar4 = 0;
    if (*(int *)(iVar3 + 0x30) != 0) {
      do {
        piVar1 = *(int **)(*(int *)(iVar3 + 0x2c) + uVar4 * 4);
        (**(code **)(*piVar1 + 8))(piVar1);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar3 + 0x30));
    }
    operator_delete__(*(void **)(iVar3 + 0x2c));
  }
  *(undefined4 *)(iVar3 + 0x2c) = 0;
  uVar2 = FUN_100126e8(-(uint)((int)((ulonglong)param_2 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)param_2 * 4));
  *(undefined4 *)(iVar3 + 0x2c) = uVar2;
  uVar2 = FUN_1000436c();
  return uVar2;
}



// Function: Catch@1000435d at 1000435d

undefined * Catch_1000435d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004367;
}



// Function: FUN_1000436c at 1000436c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000436c(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  uint uVar5;
  
  if (*(int *)(unaff_ESI + 0x2c) == unaff_EBX) {
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
        *(undefined4 *)(*(int *)(unaff_ESI + 0x2c) + uVar5 * 4) = **(undefined4 **)(unaff_EBP + 0xc)
        ;
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    *(uint *)(unaff_ESI + 0x30) = uVar2;
    uVar4 = 0;
  }
  return uVar4;
}



// Function: FUN_100043af at 100043af

undefined4 FUN_100043af(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x24;
  }
  if (*(HWND *)(iVar1 + 4) == (HWND)0x0) {
    uVar2 = 0x8000ffff;
  }
  else {
    ShowWindow(*(HWND *)(iVar1 + 4),param_2);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_100043de at 100043de

undefined4 FUN_100043de(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x24;
  }
  if (*(HWND *)(iVar1 + 4) == (HWND)0x0) {
    uVar2 = 0x8000ffff;
  }
  else if (param_2 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    MoveWindow(*(HWND *)(iVar1 + 4),*param_2,param_2[1],param_2[2] - *param_2,
               param_2[3] - param_2[1],1);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10004431 at 10004431

bool FUN_10004431(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x24;
  }
  return *(int *)(iVar1 + 0x4c) == 0;
}



// Function: FUN_10004450 at 10004450

bool FUN_10004450(int param_1,LPMSG param_2)

{
  uint uVar1;
  char cVar2;
  BOOL BVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_1 + -0x24;
  }
  uVar1 = param_2->message;
  if (((uVar1 < 0x100) || (0x109 < uVar1)) && ((uVar1 < 0x200 || (0x20e < uVar1)))) {
    cVar2 = '\x01';
  }
  else {
    BVar3 = IsDialogMessageW(*(HWND *)(iVar4 + 4),param_2);
    cVar2 = '\x01' - (BVar3 != 0);
  }
  return (bool)cVar2;
}



// Function: FUN_1000449b at 1000449b

void __cdecl FUN_1000449b(int *param_1,size_t param_2,void *param_3,int param_4)

{
  void *pvVar1;
  undefined4 unaff_ESI;
  
  if (((param_1 == (int *)0x0) || ((int)param_2 < 0)) || (param_3 == (void *)0x0))
  goto LAB_100044ac;
  pvVar1 = (void *)*param_1;
  if (pvVar1 == param_3) {
    if ((int)param_2 <= param_4) goto LAB_100044ea;
    pvVar1 = calloc(param_2,2);
LAB_10004505:
    *param_1 = (int)pvVar1;
LAB_100044ec:
    if (*param_1 != 0) {
      return;
    }
  }
  else {
    if ((int)param_2 <= param_4) {
      free(pvVar1);
LAB_100044ea:
      *param_1 = (int)param_3;
      goto LAB_100044ec;
    }
    pvVar1 = _recalloc(pvVar1,param_2,2);
    if (pvVar1 != (void *)0x0) goto LAB_10004505;
  }
  unaff_ESI = 0x8007000e;
LAB_100044ac:
                    /* WARNING: Subroutine does not return */
  FUN_1000108d(unaff_ESI);
}



// Function: FUN_10004509 at 10004509

void __thiscall FUN_10004509(void *this,byte param_1)

{
  FUN_10004950((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10004511 at 10004511

undefined4 __thiscall FUN_10004511(void *this,int param_1)

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



// Function: FUN_1000452d at 1000452d

undefined4 FUN_1000452d(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x24;
  }
  if (*(HWND *)(iVar2 + 4) != (HWND)0x0) {
    BVar1 = IsWindow(*(HWND *)(iVar2 + 4));
    if (BVar1 != 0) {
      DestroyWindow(*(HWND *)(iVar2 + 4));
    }
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  return 0;
}



// Function: FUN_10004565 at 10004565

void __fastcall FUN_10004565(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: Allocate at 10004575

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



// Function: FUN_100045ae at 100045ae

void __fastcall FUN_100045ae(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: Init at 100045c0

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
    FUN_1000449b((int *)this,iVar2 + 1U,this + 4,0x80);
    rVar1 = (iVar2 + 1U) * 2;
    FUN_100010dd(*(void **)this,rVar1,param_1,rVar1);
  }
  return;
}



// Function: FUN_10004606 at 10004606

void __fastcall FUN_10004606(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000461d at 1000461d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000461d(int param_1,DWORD *param_2,DWORD *param_3)

{
  DWORD DVar1;
  DWORD *lpArguments;
  DWORD *extraout_ECX;
  
  lpArguments = (DWORD *)0x0;
  if (param_1 != 0) goto LAB_10004641;
  do {
    RaiseException(0xc0000005,1,(DWORD)lpArguments,lpArguments);
    lpArguments = extraout_ECX;
LAB_10004641:
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



// Function: FUN_10004693 at 10004693

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004693(int param_1)

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



// Function: FUN_10004714 at 10004714

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004714(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000473a at 1000473a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000473a(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_10002f4a((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x4c));
  *(code **)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) = _vftable__exref;
  return;
}



// Function: FUN_1000477f at 1000477f

wchar_t __thiscall FUN_1000477f(void *this,wchar_t param_1)

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
  _Dst = FUN_10001288(pcVar1);
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
      goto LAB_10004926;
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
      goto LAB_10004926;
    }
    **(undefined4 **)((int)this + 0x10) = _Dst;
    puVar6 = *(undefined4 **)((int)this + 0x20);
  }
  *puVar6 = 0;
  **(int **)((int)this + 0x30) = (int)_Dst >> 1;
LAB_10004926:
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *pwVar5 = param_1;
  return param_1;
}



// Function: FUN_10004950 at 10004950

void * __thiscall FUN_10004950(void *this,byte param_1)

{
  FUN_10003cf1((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000496f at 1000496f

int __thiscall FUN_1000496f(void *this,int param_1)

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
    iVar2 = FUN_10003346(this,param_1);
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
    FUN_10002528((LONG *)((int)_Src + -0xc));
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100049d4 at 100049d4

void __fastcall FUN_100049d4(int *param_1)

{
  uint _Size;
  void *_Src;
  int iVar1;
  
  _Src = (void *)*param_1;
  if (1 < *(int *)((int)_Src + -0xc)) {
    FUN_100033bb(param_1);
    iVar1 = FUN_10003346(param_1,*(int *)((int)_Src + -8));
    if (iVar1 != 0) {
      _Size = *(int *)((int)_Src + -8) * 2 + 2;
      if (_Size <= *(int *)(*param_1 + -4) * 2 + 2U) {
        memcpy((void *)*param_1,_Src,_Size);
      }
    }
  }
  return;
}



// Function: FUN_10004a15 at 10004a15

void __thiscall FUN_10004a15(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((1 < *(int *)(*this + -0xc)) || (*(int *)(*this + -4) < param_1)) {
    FUN_100033bb((int *)this);
    FUN_10003346(this,param_1);
  }
  return;
}



// Function: FUN_10004a43 at 10004a43

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10004a43(void *this,byte param_1)

{
  uint uVar1;
  
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  uVar1 = FUN_1000266d(param_1);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0x40) = uVar1;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10004a83 at 10004a83

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10004a83(void *this,uint param_1)

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
  FUN_1000281a((char *)(param_1 + 1));
  FUN_10004b13();
  return;
}



// Function: Catch@10004ae5 at 10004ae5

undefined * Catch_10004ae5(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_1000281a((char *)(iVar1 + 1));
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10004b0d;
}



// Function: FUN_10004b13 at 10004b13

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10004b13(void)

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



// Function: Catch@10004b5c at 10004b5c

void Catch_10004b5c(void)

{
  int unaff_EBP;
  
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (*(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
              (unaff_EBP + -0x1c),true,0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10004b71 at 10004b71

int __fastcall FUN_10004b71(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10002874((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2d) = 1;
  return param_1;
}



// Function: FUN_10004ba8 at 10004ba8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004ba8(int param_1)

{
  FUN_100034b4(param_1);
  return;
}



// Function: FUN_10004bc6 at 10004bc6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004bc6(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10004be8 at 10004be8

int * __fastcall FUN_10004be8(int *param_1)

{
  void *pvVar1;
  
  param_1[1] = 0;
  pvVar1 = FUN_10002937((char *)0x1);
  *param_1 = (int)pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*param_1 + 4) = *param_1;
  return param_1;
}



// Function: FUN_10004c09 at 10004c09

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004c09(undefined4 *param_1)

{
  *param_1 = CComErrorHandlerException::vftable;
  FID_conflict__Tidy(param_1 + 4,'\x01',0);
  return;
}



// Function: FUN_10004c34 at 10004c34

undefined4 * __thiscall FUN_10004c34(void *this,byte param_1)

{
  FUN_10004c09((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004c53 at 10004c53

void __fastcall FUN_10004c53(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 8);
  if (*piVar1 != 0) {
    FUN_1000110f(piVar1,(int *)0x0);
  }
  piVar2 = (int *)(param_1 + 0xc);
  (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,&DAT_10018ea0,piVar1);
  Ordinal_201(0,*piVar1);
  if (*piVar1 != 0) {
    FUN_1000110f(piVar1,(int *)0x0);
  }
  if (*piVar2 != 0) {
    FUN_1000110f(piVar2,(int *)0x0);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_1000110f((int *)(param_1 + 0x10),(int *)0x0);
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_1000110f((int *)(param_1 + 4),(int *)0x0);
  }
  return;
}



// Function: FUN_10004cc0 at 10004cc0

HRESULT __fastcall FUN_10004cc0(int param_1)

{
  int *piVar1;
  int iVar2;
  LPVOID *ppv;
  HRESULT local_8;
  
  piVar1 = (int *)(param_1 + 8);
  if (*piVar1 != 0) {
    FUN_1000110f(piVar1,(int *)0x0);
  }
  iVar2 = Ordinal_200(0,piVar1);
  ppv = (LPVOID *)(param_1 + 0xc);
  if (iVar2 == 1) {
    local_8 = CoCreateInstance((IID *)&DAT_1001b118,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10018eb0,ppv);
  }
  else {
    if (*ppv != (LPVOID)0x0) {
      FUN_1000110f((int *)ppv,(int *)0x0);
    }
    local_8 = (*(code *)**(undefined4 **)*piVar1)((undefined4 *)*piVar1,&DAT_10018eb0,ppv);
    if (local_8 < 0) {
      if (*piVar1 != 0) {
        FUN_1000110f(piVar1,(int *)0x0);
      }
      local_8 = CoCreateInstance((IID *)&DAT_1001b118,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10018eb0,ppv);
    }
    if (*piVar1 != 0) {
      FUN_1000110f(piVar1,(int *)0x0);
    }
  }
  return local_8;
}



// Function: FUN_10004d59 at 10004d59

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004d59(int param_1)

{
  FUN_100034b4(param_1);
  return;
}



// Function: FUN_10004d77 at 10004d77

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004d77(int param_1)

{
  FUN_10003cf1(param_1);
  return;
}



// Function: FUN_10004d95 at 10004d95

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10004d95(void *this,undefined4 param_1)

{
  uint extraout_ECX;
  undefined2 auStack_70 [4];
  undefined4 uStack_68;
  undefined2 auStack_60 [4];
  undefined4 uStack_58;
  uint uStack_50;
  undefined4 uStack_4c;
  int local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_18 = 0;
  local_14[0] = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  Ordinal_6();
  local_18 = 0;
  FUN_100021cd(0x71,&local_18);
  Ordinal_6();
  local_14[0] = 0;
  uStack_4c = 0x10004de0;
  FUN_100021cd(0x72,local_14);
  uStack_50 = extraout_ECX & 0xffff0000;
  uStack_58 = 0x10004df5;
  FUN_10002a4c(&uStack_50,(CComBSTR *)local_14);
  local_8._0_1_ = 3;
  auStack_60[0] = 0;
  uStack_68 = 0x10004e0f;
  FUN_10002a4c(auStack_60,(CComBSTR *)&param_1);
  local_8._0_1_ = 4;
  auStack_70[0] = 0;
  FUN_10002a4c(auStack_70,(CComBSTR *)&local_18);
  local_8._0_1_ = 2;
  FUN_10003dbc(*(void **)((int)this + 0x154),1);
  local_8._0_1_ = 1;
  Ordinal_6();
  local_8 = (uint)local_8._1_3_ << 8;
  uStack_4c = 0x10004e66;
  Ordinal_6();
  local_8 = 0xffffffff;
  uStack_4c = param_1;
  uStack_50 = 0x10004e6f;
  Ordinal_6();
  return;
}



// Function: FUN_10004e77 at 10004e77

void __fastcall
FUN_10004e77(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1)

{
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            (param_1,true,0);
  return;
}



// Function: FUN_10004e81 at 10004e81

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_10004e81(DLGTEMPLATE *param_1,wchar_t *param_2,undefined2 *param_3)

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
  local_8 = 0x10004e90;
  if (param_1 != (DLGTEMPLATE *)0x0) {
    iVar1 = HasFont(param_1);
    if (iVar1 != 0) {
      if ((param_2 == (wchar_t *)0x0) || (param_3 == (undefined2 *)0x0)) goto LAB_10004ea4;
      puVar2 = CDialogTemplate::GetFontSizeField(param_1);
      *param_3 = *(undefined2 *)puVar2;
      local_118 = local_114;
      ATL::CW2WEX<128>::Init
                ((CW2WEX<128> *)&local_118,
                 (wchar_t *)(puVar2 + ((uint)(*(short *)(param_1 + 2) == -1) * 2 + 1) * 2));
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
    }
    FUN_100127fb();
    return;
  }
LAB_10004ea4:
                    /* WARNING: Subroutine does not return */
  FUN_1000108d(0x80004005);
}



// Function: FUN_10004f65 at 10004f65

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10004f65(undefined4 *param_1)

{
  FUN_10003f6f(param_1);
  *param_1 = CComECMTestPageImpl<class_COpenLoopLockPage,0,0>::vftable;
  param_1[1] = CComECMTestPageImpl<class_COpenLoopLockPage,0,0>::vftable;
  param_1[0x11] = CComECMTestPageImpl<class_COpenLoopLockPage,0,0>::vftable;
  return param_1;
}



// Function: FUN_10004f9f at 10004f9f

void __thiscall FUN_10004f9f(void *this,byte param_1)

{
  FUN_100050b9((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_10004fa7 at 10004fa7

undefined4 FUN_10004fa7(void)

{
  return 0x80004001;
}



// Function: FUN_10004faf at 10004faf

undefined4 FUN_10004faf(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x30);
    if (*piVar2 != 0) {
      FUN_1000110f(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10018ae0,piVar2);
  }
  return uVar1;
}



// Function: FUN_10004fe6 at 10004fe6

undefined4 FUN_10004fe6(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x34);
    if (*piVar2 != 0) {
      FUN_1000110f(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10018ae0,piVar2);
  }
  return uVar1;
}



// Function: FUN_1000501d at 1000501d

undefined4 FUN_1000501d(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x38);
    if (*piVar2 != 0) {
      FUN_1000110f(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10018f14,piVar2);
  }
  return uVar1;
}



// Function: FUN_10005054 at 10005054

undefined4 FUN_10005054(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_1000110f((int *)(param_1 + 0x38),(int *)0x0);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_1000110f((int *)(param_1 + 0x30),(int *)0x0);
  }
  return 0;
}



// Function: FUN_10005082 at 10005082

undefined4 FUN_10005082(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(param_1 + 0x3c);
    if (*piVar2 != 0) {
      FUN_1000110f(piVar2,(int *)0x0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_1001911c,piVar2);
  }
  return uVar1;
}



// Function: FUN_100050b9 at 100050b9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100050b9(void *this,byte param_1)

{
  FUN_10003cf1((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100050ea at 100050ea

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100050ea(int param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)(param_1 + 0x50);
  FUN_1000473a((int)piVar1);
  *(code **)piVar1 = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}



// Function: FUN_10005123 at 10005123

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005123(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10005149 at 10005149

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ATLSTRINGRESOURCEIMAGE * FUN_10005149(ATLSTRINGRESOURCEIMAGE *param_1)

{
  ATLSTRINGRESOURCEIMAGE *pAVar1;
  ATLSTRINGRESOURCEIMAGE *pAVar2;
  
  pAVar1 = ATL::AtlGetStringResourceImage(DAT_100268dc,(uint)param_1);
  pAVar2 = pAVar1;
  if (pAVar1 != (ATLSTRINGRESOURCEIMAGE *)0x0) {
    param_1 = (ATLSTRINGRESOURCEIMAGE *)0x0;
    ATL::CHeapPtr<wchar_t,class_ATL::CComAllocator>::Allocate
              ((CHeapPtr<wchar_t,class_ATL::CComAllocator> *)&param_1,*(ushort *)pAVar1 + 1);
    pAVar2 = param_1;
    if (param_1 != (ATLSTRINGRESOURCEIMAGE *)0x0) {
      FUN_100010dd(param_1,(uint)*(ushort *)pAVar1 * 2 + 2,pAVar1 + 2,(uint)*(ushort *)pAVar1 * 2);
      *(undefined2 *)(pAVar2 + (uint)*(ushort *)pAVar1 * 2) = 0;
    }
    param_1 = (ATLSTRINGRESOURCEIMAGE *)0x0;
    CoTaskMemFree((LPVOID)0x0);
  }
  return pAVar2;
}



// Function: FUN_100051c8 at 100051c8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_100051c8(void *this,byte param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined ***)this = &PTR_100191ec;
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
  FUN_10004a43((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 4),
               param_1 | 2);
  return (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10005246 at 10005246

void * __thiscall FUN_10005246(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x50);
  FUN_100050ea((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_10005268 at 10005268

void __thiscall FUN_10005268(void *this,int param_1)

{
  FUN_100049d4((int *)this);
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



// Function: FUN_10005295 at 10005295

void __thiscall FUN_10005295(void *this,int param_1,void *param_2)

{
  uint _Size;
  int iVar1;
  
  iVar1 = FUN_10004a15(this,param_1);
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



// Function: FUN_100052d6 at 100052d6

bool __thiscall FUN_100052d6(void *this,uint param_1,char param_2)

{
  uint uVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *extraout_ECX;
  
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10004a83(this,param_1);
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



// Function: FUN_1000533b at 1000533b

LONG __fastcall FUN_1000533b(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    FUN_100025ac(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



// Function: FUN_10005366 at 10005366

undefined4 * __thiscall FUN_10005366(void *this,ushort *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x2d) == '\0') {
    iVar2 = FUN_10003aea(puVar3 + 3,param_1);
    if (iVar2 < 0) {
      puVar1 = (undefined4 *)puVar3[2];
    }
    else {
      puVar1 = (undefined4 *)*puVar3;
      puVar4 = puVar3;
    }
  }
  return puVar4;
}



// Function: FUN_1000539b at 1000539b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_1000539b(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *local_20;
  undefined4 local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x100053a7;
  local_1c = 0;
  iVar2 = __RTDynamicCast(param_1,0,&CComErrorDisplay<class_COpenLoopLockPage>::RTTI_Type_Descriptor
                          ,&COpenLoopLockPage::RTTI_Type_Descriptor,0);
  piVar3 = (int *)(**(code **)(*(int *)(iVar2 + 0x20) + 0x4c))(2);
  local_20 = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
    local_14[0] = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    (**(code **)*piVar3)(piVar3,&DAT_10018f24,local_14);
    FUN_1000110f((int *)&local_20,(int *)0x0);
    if (local_14[0] != (int *)0x0) {
      local_18 = (int *)0x0;
      local_8._0_1_ = 5;
      (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_18);
      (**(code **)*local_18)(local_18,&DAT_10018f34,&local_1c);
      local_8._0_1_ = 3;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  uVar1 = local_1c;
  local_8 = 0xffffffff;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return uVar1;
}



// Function: FUN_1000546c at 1000546c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000546c(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_1000548e at 1000548e

void FUN_1000548e(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *dwNewLong;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_10004693(0x10026910);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)param_1;
    iVar2 = (**(code **)(*piVar1 + 8))();
    FUN_10004019(piVar1 + 5,iVar2,piVar1);
    dwNewLong = (code *)piVar1[5];
    SetWindowLongW(param_1,4,(LONG)dwNewLong);
    (*dwNewLong)(param_1,param_2,param_3,param_4);
  }
  return;
}



// Function: FUN_100054db at 100054db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __fastcall FUN_100054db(int *param_1)

{
  int *apiStack_2c [5];
  undefined1 *local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x100054e7;
  local_18 = (undefined1 *)apiStack_2c;
  apiStack_2c[0] = param_1;
  local_14 = param_1;
  FUN_10004be8(param_1);
  return local_14;
}



// Function: FUN_10005503 at 10005503

void __fastcall FUN_10005503(int *param_1)

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



// Function: FUN_1000552c at 1000552c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000552c(void *this,byte param_1)

{
  FID_conflict__Tidy(this,'\x01',0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10005561 at 10005561

void __thiscall FUN_10005561(void *this,int *param_1,int *param_2)

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



// Function: FUN_10005599 at 10005599

void __thiscall FUN_10005599(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x14) = param_1;
  FUN_10004cc0((int)this);
  FUN_10003b3f(this);
  FUN_10003c62((int)this);
  return;
}



// Function: basic_string<> at 100055bd

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
  FUN_10001da0(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: FUN_100055e5 at 100055e5

void __cdecl FUN_100055e5(wchar_t *param_1,ushort param_2,int *param_3,char param_4)

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
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  FUN_10004041(param_1,param_2,&local_54,&local_58);
  if (param_4 != '\0') {
    hModule = LoadLibraryW(L"COMCTL32.DLL");
    if (hModule != (HMODULE)0x0) {
      hResInfo = FindResourceW(hModule,(LPCWSTR)0x3ee,(LPCWSTR)0x5);
      if (hResInfo != (HRSRC)0x0) {
        pDVar1 = (DLGTEMPLATE *)LoadResource(hModule,hResInfo);
        if (pDVar1 != (DLGTEMPLATE *)0x0) {
          iVar2 = FUN_10004e81(pDVar1,local_48,(undefined2 *)&local_4c);
          FreeLibrary(hModule);
          if (iVar2 != 0) {
            FUN_10004041(local_48,(ushort)local_4c,&local_60,&local_4c);
            pcVar3 = MulDiv_exref;
            iVar2 = MulDiv(*param_3,local_54,4);
            *param_3 = iVar2;
            iVar2 = MulDiv(param_3[1],local_5c,8);
            param_3[1] = iVar2;
            goto LAB_100056c1;
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
LAB_100056c1:
  iVar2 = (*pcVar3)(iVar2,local_58,local_4c);
  param_3[1] = iVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100056d4 at 100056d4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

long FUN_100056d4(int param_1,LPCWSTR param_2)

{
  ATLSTRINGRESOURCEIMAGE *lpString;
  uint uVar1;
  long lVar2;
  int local_18;
  ATLSTRINGRESOURCEIMAGE *local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + -0x24;
  }
  local_18 = 0;
  local_8 = 0;
  if (param_2 == (LPCWSTR)0x0) {
    param_2 = (LPCWSTR)0x0;
  }
  else {
    param_2 = (LPCWSTR)Ordinal_2(param_2);
    if (param_2 == (LPCWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_1000108d(0x8007000e);
    }
  }
  local_8._0_1_ = 1;
  lpString = FUN_10005149(*(ATLSTRINGRESOURCEIMAGE **)(param_1 + 0x40));
  local_8._0_1_ = 4;
  local_14 = lpString;
  if (lpString == (ATLSTRINGRESOURCEIMAGE *)0x0) {
    local_8 = CONCAT31(local_8._1_3_,1);
    CoTaskMemFree((LPVOID)0x0);
    lVar2 = -0x7ff8fff2;
  }
  else {
    uVar1 = lstrlenW(L"\\");
    lVar2 = FUN_100013db(&param_2,&DAT_10019210,uVar1);
    if (lVar2 < 0) {
      local_8 = CONCAT31(local_8._1_3_,1);
      CoTaskMemFree(lpString);
    }
    else {
      uVar1 = lstrlenW((LPCWSTR)lpString);
      lVar2 = FUN_100013db(&param_2,lpString,uVar1);
      if (-1 < lVar2) {
        WinHelpW(*(HWND *)(param_1 + 4),param_2,8,0);
        local_8._0_1_ = 1;
        CoTaskMemFree(lpString);
        local_14 = (ATLSTRINGRESOURCEIMAGE *)0x0;
        local_8 = (uint)local_8._1_3_ << 8;
        Ordinal_6(param_2);
        local_8 = 0xffffffff;
        FUN_10001319(&local_18);
        return 0;
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      CoTaskMemFree(lpString);
    }
  }
  local_14 = (ATLSTRINGRESOURCEIMAGE *)0x0;
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(param_2);
  local_8 = 0xffffffff;
  FUN_10001319(&local_18);
  return lVar2;
}



// Function: FUN_10005803 at 10005803

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10005803(void *this,uint param_1,char param_2)

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
    bVar2 = FUN_100052d6(this,uVar1,'\0');
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



// Function: basic_string<> at 10005864

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



// Function: FUN_1000588c at 1000588c

HWND __thiscall FUN_1000588c(void *this,HWND param_1,LPARAM param_2)

{
  int iVar1;
  HWND pHVar2;
  
  iVar1 = FUN_10004019((void *)((int)this + 0x14),0,0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    pHVar2 = (HWND)0x0;
  }
  else {
    FUN_1000461d(0x10026910,(DWORD *)((int)this + 8),(DWORD *)this);
    pHVar2 = CreateDialogParamW(DAT_100268dc,(LPCWSTR)0x66,param_1,FUN_1000548e,param_2);
  }
  return pHVar2;
}



// Function: FUN_100058db at 100058db

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10005972) */

undefined4 __thiscall FUN_100058db(void *this,int param_1)

{
  undefined4 uVar1;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  if (param_1 == 0) {
    return 1;
  }
  local_18[0] = (int *)0x0;
  local_8 = 3;
  local_18[0] = (int *)FUN_1000539b(this);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 0xc))(local_18[0],param_1);
    FUN_1000110f((int *)local_18,(int *)0x0);
  }
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = 0;
  uVar1 = FUN_10005958();
  return uVar1;
}



// Function: Catch@10005943 at 10005943

undefined * Catch_10005943(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005956;
}



// Function: FUN_10005958 at 10005958

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005958(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (*(int **)(unaff_EBP + 8) != unaff_ESI) {
    FUN_1000110f((int *)(unaff_EBP + 8),unaff_ESI);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 8);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: Catch@10005983 at 10005983

undefined * Catch_10005983(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005956;
}



// Function: FUN_1000598d at 1000598d

void * __thiscall FUN_1000598d(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    iVar1 = lstrlenW(param_1);
  }
  FUN_10005295(this,iVar1,param_1);
  return this;
}



// Function: FUN_100059b5 at 100059b5

void __thiscall FUN_100059b5(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  int iVar3;
  int iVar4;
  WCHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  iVar1 = FUN_1000254e(param_1,local_208,0x100);
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      iVar4 = iVar1 + 0x100;
      pWVar2 = (LPWSTR)FUN_1000496f(this,iVar1 + 0xff);
      if (pWVar2 == (LPWSTR)0x0) break;
      iVar3 = FUN_1000254e(param_1,pWVar2,iVar4);
      iVar1 = iVar4;
    } while (iVar4 - iVar3 < 2);
    FUN_10005268(this,-1);
  }
  else {
    FUN_1000598d(this,local_208);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005a5e at 10005a5e

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> * __thiscall
FUN_10005a5e(void *this,uint param_1,char param_2)

{
  bool bVar1;
  void *pvVar2;
  void *extraout_ECX;
  
  pvVar2 = this;
  if (param_1 == 0xffffffff) {
    std::_Xlength_error("string too long");
    pvVar2 = extraout_ECX;
  }
  bVar1 = FUN_100052d6(pvVar2,param_1,'\0');
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



// Function: FUN_10005aac at 10005aac

void __thiscall FUN_10005aac(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  undefined4 *puVar1;
  void *local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_8 = this;
  if ((param_2 == (int *)**this) && (param_3 == *this)) {
    FUN_10005503((int *)this);
                    /* WARNING: Load size is inaccurate */
    param_3 = *this;
  }
  else {
    while (param_2 != param_3) {
      puVar1 = (undefined4 *)FUN_10005561(this,(int *)&local_8,param_2);
      param_2 = (int *)*puVar1;
    }
  }
  *param_1 = param_3;
  return;
}



// Function: FUN_10005aef at 10005aef

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10005aef(void *this,int param_1)

{
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  basic_string<>((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  return (undefined4 *)this;
}



// Function: FUN_10005b3f at 10005b3f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10005b3f(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  char ****ppppcVar1;
  int iVar2;
  char *pcVar3;
  wchar_t *local_3c;
  char *local_38;
  wchar_t local_34;
  wchar_t local_32;
  char ***local_30 [4];
  uint local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x10005b4b;
  if ((**(int **)(param_1 + 0x20) == 0) ||
     (**(uint **)(param_1 + 0x20) + **(int **)(param_1 + 0x30) * 2 <= **(uint **)(param_1 + 0x20)))
  {
    if (*(int *)(param_1 + 0x54) != 0) {
      Reset_back((int)param_1);
      if (*(int *)(param_1 + 0x44) == 0) {
        local_38 = (char *)0x0;
        FUN_10002bec((wint_t *)&local_38,*(FILE **)(param_1 + 0x54));
      }
      else {
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
        local_8 = 0;
LAB_10005c5f:
        do {
          iVar2 = fgetc(*(FILE **)(param_1 + 0x54));
          if (iVar2 == -1) {
LAB_10005c6e:
            local_8 = 0xffffffff;
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_30,true,0);
            goto LAB_10005c82;
          }
          FUN_10005803(local_30,1,(char)iVar2);
          ppppcVar1 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar1 = local_30;
          }
          iVar2 = std::codecvt<wchar_t,char,int>::in
                            (*(codecvt<wchar_t,char,int> **)(param_1 + 0x44),(int *)(param_1 + 0x4c)
                             ,(char *)ppppcVar1,(char *)((int)ppppcVar1 + local_20),&local_38,
                             &local_34,&local_32,&local_3c);
          if (iVar2 < 0) goto LAB_10005c6e;
          if (iVar2 < 2) {
            if (local_3c != &local_34) {
              ppppcVar1 = (char ****)local_30[0];
              if (local_1c < 0x10) {
                ppppcVar1 = local_30;
              }
              pcVar3 = (char *)((int)ppppcVar1 + (local_20 - (int)local_38));
              while (0 < (int)pcVar3) {
                pcVar3 = pcVar3 + -1;
                ungetc((int)local_38[(int)pcVar3],*(FILE **)(param_1 + 0x54));
              }
              goto LAB_10005cb3;
            }
            ppppcVar1 = (char ****)local_30[0];
            if (local_1c < 0x10) {
              ppppcVar1 = local_30;
            }
            FUN_10003eb1(local_30,0,(int)local_38 - (int)ppppcVar1);
            goto LAB_10005c5f;
          }
          if (iVar2 != 3) goto LAB_10005c6e;
        } while (local_20 < 2);
        ppppcVar1 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar1 = local_30;
        }
        memcpy_s(&local_34,2,ppppcVar1,2);
LAB_10005cb3:
        local_8 = 0xffffffff;
        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                  ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_30,true,0);
      }
    }
  }
  else {
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Gninc(param_1);
  }
LAB_10005c82:
  FUN_100127fb();
  return;
}



// Function: FUN_10005ccb at 10005ccb

void __cdecl FUN_10005ccb(DLGTEMPLATE *param_1,int *param_2,char param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined4 local_4c;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  local_4c = 0;
  FUN_10004200((int)param_1,param_2);
  iVar1 = FUN_10004e81(param_1,local_48,(undefined2 *)&local_4c);
  if (iVar1 == 0) {
    uVar3 = 0;
    pwVar2 = (wchar_t *)0x0;
  }
  else {
    pwVar2 = local_48;
    uVar3 = local_4c;
  }
  FUN_100055e5(pwVar2,(ushort)uVar3,param_2,param_3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005d2a at 10005d2a

void __thiscall FUN_10005d2a(void *this,undefined4 *param_1,ushort *param_2)

{
  int iVar1;
  ushort **ppuVar2;
  ushort *local_8;
  
  local_8 = (ushort *)this;
  local_8 = (ushort *)FUN_10005366(this,param_2);
  if (local_8 != *(ushort **)((int)this + 4)) {
    iVar1 = FUN_10003aea(param_2,local_8 + 6);
    if (-1 < iVar1) {
      ppuVar2 = &local_8;
      goto LAB_10005d5f;
    }
  }
  ppuVar2 = &param_2;
LAB_10005d5f:
  *param_1 = *ppuVar2;
  return;
}



// Function: FUN_10005d6b at 10005d6b

undefined4 FUN_10005d6b(int *param_1,HWND param_2,int *param_3)

{
  undefined4 uVar1;
  HWND pHVar2;
  int *this;
  
  if (param_1 == (int *)0x0) {
    this = (int *)0x0;
  }
  else {
    this = param_1 + -9;
  }
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    pHVar2 = FUN_1000588c(this,param_2,0);
    this[1] = (int)pHVar2;
    (**(code **)(*param_1 + 0x24))(param_1,param_3);
    param_1[4] = param_3[2] - *param_3;
    param_1[5] = param_3[3] - param_3[1];
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10005dbd at 10005dbd

undefined4 FUN_10005dbd(int param_1,undefined4 *param_2)

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
    iVar4 = param_1 + -0x24;
  }
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    hResInfo = FindResourceW(DAT_100268dc,(LPCWSTR)0x66,(LPCWSTR)0x5);
    if (((hResInfo != (HRSRC)0x0) &&
        (hResData = LoadResource(DAT_100268dc,hResInfo), hResData != (HGLOBAL)0x0)) &&
       (pDVar2 = (DLGTEMPLATE *)LockResource(hResData), pDVar2 != (DLGTEMPLATE *)0x0)) {
      FUN_10005ccb(pDVar2,(int *)(param_1 + 0x10),'\x01');
      *param_2 = 0x1c;
      pAVar3 = FUN_10005149(*(ATLSTRINGRESOURCEIMAGE **)(iVar4 + 0x3c));
      param_2[1] = pAVar3;
      param_2[2] = *(int *)(param_1 + 0x10);
      param_2[3] = *(undefined4 *)(param_1 + 0x14);
      pAVar3 = FUN_10005149(*(ATLSTRINGRESOURCEIMAGE **)(iVar4 + 0x40));
      param_2[5] = pAVar3;
      pAVar3 = FUN_10005149(*(ATLSTRINGRESOURCEIMAGE **)(iVar4 + 0x44));
      param_2[4] = pAVar3;
      param_2[6] = *(undefined4 *)(iVar4 + 0x48);
      return 0;
    }
    uVar1 = 0x8000ffff;
  }
  return uVar1;
}



// Function: FUN_10005e72 at 10005e72

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10005ebe) */
/* WARNING: Removing unreachable block (ram,0x10005ed7) */

undefined4 __thiscall FUN_10005e72(void *this,int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  if (param_1 == (int *)0x0) {
    local_8 = 3;
    Ordinal_200(0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else if (param_1 != (int *)0x0) {
    FUN_1000110f((int *)local_14,param_1);
  }
  piVar2 = local_14[0];
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 4))(local_14[0]);
  }
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
  uVar1 = FUN_100058db(this,(int)piVar2);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))();
  }
  return uVar1;
}



// Function: FUN_10005f24 at 10005f24

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10005f24(int *param_1)

{
  short sVar1;
  int iVar2;
  char ******ppppppcVar3;
  size_t sVar4;
  size_t _Count;
  char *local_34;
  char *****local_30 [4];
  int local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x10005f30;
  if (((param_1[0x11] != 0) && (*(char *)((int)param_1 + 0x4a) != '\0')) &&
     (sVar1 = (**(code **)(*param_1 + 0xc))(0xffff), sVar1 != -1)) {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char *****)((uint)local_30[0] & 0xffffff00);
    FUN_10005a5e(local_30,8,'\0');
    local_8 = 0;
LAB_10005f7b:
    ppppppcVar3 = (char ******)local_30[0];
    if (local_1c < 0x10) {
      ppppppcVar3 = local_30;
    }
    iVar2 = std::codecvt<wchar_t,char,int>::unshift
                      ((codecvt<wchar_t,char,int> *)param_1[0x11],param_1 + 0x13,(char *)ppppppcVar3
                       ,(char *)((int)ppppppcVar3 + local_20),&local_34);
    if (iVar2 == 0) {
      *(undefined1 *)((int)param_1 + 0x4a) = 0;
    }
    else if (iVar2 != 1) goto LAB_10005fac;
    ppppppcVar3 = (char ******)local_30[0];
    if (local_1c < 0x10) {
      ppppppcVar3 = local_30;
    }
    _Count = (int)local_34 - (int)ppppppcVar3;
    if (_Count != 0) {
      ppppppcVar3 = (char ******)local_30[0];
      if (local_1c < 0x10) {
        ppppppcVar3 = local_30;
      }
      sVar4 = fwrite(ppppppcVar3,1,_Count,(FILE *)param_1[0x15]);
      if (_Count != sVar4) goto LAB_10005fac;
    }
    if (*(char *)((int)param_1 + 0x4a) == '\0') goto LAB_10005fac;
    if (_Count == 0) {
      FUN_10005803(local_30,8,'\0');
    }
    goto LAB_10005f7b;
  }
LAB_10006020:
  FUN_100127fb();
  return;
LAB_10005fac:
  local_8 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_30,true,0);
  goto LAB_10006020;
}



// Function: FUN_10006026 at 10006026

int * __thiscall FUN_10006026(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    *(undefined **)this = PTR_DAT_100243c0;
    FUN_1000598d(this,(LPCWSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    InterlockedIncrement((LONG *)(iVar1 + -0xc));
  }
  return (int *)this;
}



// Function: FUN_1000605c at 1000605c

void __fastcall FUN_1000605c(undefined4 *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    FUN_1000533b((int *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1000606f at 1000606f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000606f(int *param_1)

{
  FUN_10005503(param_1);
  operator_delete((void *)*param_1);
  return;
}



// Function: FUN_1000609b at 1000609b

void __fastcall FUN_1000609b(int param_1)

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
  FUN_10005aac(this,&local_8,*(int **)*this,(int *)*this);
  return;
}



// Function: FUN_100060d0 at 100060d0

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100060d0(void *this,void *param_1)

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
  __RTDynamicCast(this,0,&CContextSensitiveHelpProvider<class_COpenLoopLockPage>::
                          RTTI_Type_Descriptor,&COpenLoopLockPage::RTTI_Type_Descriptor,0);
  FUN_100039ab(&local_70,(GUID *)&DAT_10019ef8);
  local_8._0_1_ = 1;
  FUN_10011e36((undefined2 *)local_6c,local_70);
  local_8._0_1_ = 2;
  FUN_10001f54(local_34,L"");
  local_8._0_1_ = 3;
  FUN_10001f54(local_50,L"{");
  local_8._0_1_ = 4;
  FUN_10011db2(local_6c,local_50,local_34);
  local_8._0_1_ = 3;
  FID_conflict__Tidy(local_50,'\x01',0);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_34,'\x01',0);
  FUN_10001f54(local_50,L"");
  local_8._0_1_ = 5;
  FUN_10001f54(local_34,L"}");
  local_8._0_1_ = 6;
  FUN_10011db2(local_6c,local_34,local_50);
  local_8._0_1_ = 5;
  FID_conflict__Tidy(local_34,'\x01',0);
  local_8._0_1_ = 2;
  FID_conflict__Tidy(local_50,'\x01',0);
  piVar1 = FUN_10011d60(&local_74,local_6c);
  local_8._0_1_ = 7;
  FUN_10003978(param_1,piVar1);
  local_8._0_1_ = 2;
  Ordinal_6(local_74);
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_6c,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_70);
  local_8 = 0xffffffff;
  FUN_1001280a();
  return;
}



// Function: Catch@10006214 at 10006214

undefined4 Catch_10006214(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000620a;
}



// Function: FUN_1000621e at 1000621e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_1000621e(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
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



// Function: FUN_10006285 at 10006285

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10006285(int *param_1)

{
  uint uVar1;
  size_t sVar2;
  int *piVar3;
  LPCWSTR pWVar4;
  HMODULE hLibModule;
  wchar_t *_DstBuf;
  errno_t eVar5;
  int iVar6;
  uint local_60;
  uint local_5c;
  int local_4c;
  uint local_44;
  int *local_40;
  int *local_3c;
  char local_35;
  int local_34;
  undefined4 local_30;
  int local_20;
  uint local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_35 = '\0';
  local_34 = 0;
  local_8 = 0;
  local_3c = param_1;
  FUN_10002330(param_1,&local_60,param_1[5]);
  if (local_5c == 0) {
    if (local_44 != 0) {
      Ordinal_6(0);
      local_34 = 0;
      FUN_100021cd(local_44,&local_34);
      local_1c = 7;
      local_20 = 0;
      local_30 = (LPCWSTR)((uint)local_30._2_2_ << 0x10);
      local_8 = CONCAT31(local_8._1_3_,1);
      (**(code **)(*param_1 + 8))(&local_30);
      uVar1 = lstrlenW(L"_");
      FUN_100013db(&local_34,&DAT_10019330,uVar1);
      if (local_20 == 0) {
        sVar2 = wcslen(L"en");
        FID_conflict_assign(&local_30,(undefined4 *)&DAT_10019328,sVar2);
      }
      pWVar4 = local_30;
      if (local_1c < 8) {
        pWVar4 = (LPCWSTR)&local_30;
      }
      uVar1 = lstrlenW(pWVar4);
      FUN_100013db(&local_34,pWVar4,uVar1);
      uVar1 = lstrlenW(L".dll");
      FUN_100013db(&local_34,L".dll",uVar1);
      piVar3 = FUN_1000342a(&local_40,local_34);
      local_8._0_1_ = 2;
      if ((undefined4 *)*piVar3 == (undefined4 *)0x0) {
        pWVar4 = (LPCWSTR)0x0;
      }
      else {
        pWVar4 = *(LPCWSTR *)*piVar3;
      }
      hLibModule = LoadLibraryW(pWVar4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_40 != (int *)0x0) {
        FUN_1000533b(local_40);
        local_40 = (int *)0x0;
      }
      if (hLibModule != (HMODULE)0x0) {
        local_35 = FUN_10002a06(&local_34,hLibModule,local_3c[5] - local_4c);
        FreeLibrary(hLibModule);
      }
      local_8 = local_8 & 0xffffff00;
      FID_conflict__Tidy(&local_30,'\x01',0);
      param_1 = local_3c;
      if (local_35 != '\0') goto LAB_10006479;
    }
    _DstBuf = (wchar_t *)FUN_100126e8(0x40);
    FUN_10001381(&local_34,0x10019258);
    if (_DstBuf != (wchar_t *)0x0) {
      eVar5 = _ltow_s(param_1[5],_DstBuf,0x20,10);
      if (eVar5 < 0) {
        iVar6 = -0x7ff8ffa9;
LAB_100063fd:
                    /* WARNING: Subroutine does not return */
        FUN_1000108d(iVar6);
      }
      if (eVar5 == 0) {
        local_3c = (int *)0x0;
      }
      else {
        local_3c = (int *)Ordinal_4(0,eVar5);
        if (local_3c == (int *)0x0) {
          iVar6 = -0x7ff8fff2;
          goto LAB_100063fd;
        }
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      iVar6 = FUN_10002154(&local_34,local_3c);
      if (iVar6 < 0) goto LAB_100063fd;
      local_8 = local_8 & 0xffffff00;
      Ordinal_6(local_3c);
    }
    FUN_10003b14(&local_34,L".");
    FUN_10003b14(&local_34,L"</Description></ErrorInfo>");
    operator_delete__(_DstBuf);
  }
  else {
    Ordinal_6(0);
    local_34 = 0;
    FUN_100021cd(local_5c,&local_34);
  }
LAB_10006479:
  (**(code **)(*(int *)param_1[4] + 0x14))((int *)param_1[4],local_34);
  local_8 = 0xffffffff;
  Ordinal_6(local_34);
  FUN_100127fb();
  return;
}



// Function: FUN_10006498 at 10006498

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ** FUN_10006498(void)

{
  LPOLESTR pOVar1;
  size_t sVar2;
  undefined4 ***pppuVar3;
  LPOLESTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x100064a4;
  if ((DAT_100259a0 & 1) == 0) {
    DAT_100259a0 = DAT_100259a0 | 1;
    local_8 = 0;
    DAT_10025998 = 7;
    _DAT_10025994 = 0;
    DAT_10025984 = (undefined4 **)((uint)DAT_10025984 & 0xffff0000);
    _atexit((_func_4879 *)&LAB_1001760d);
    local_8 = 0xffffffff;
  }
  local_14[0] = (wchar_t *)0x0;
  StringFromCLSID((IID *)&DAT_10019ef8,local_14);
  pOVar1 = local_14[0];
  sVar2 = wcslen(local_14[0]);
  FID_conflict_assign(&DAT_10025984,(undefined4 *)pOVar1,sVar2);
  CoTaskMemFree(local_14[0]);
  pppuVar3 = (undefined4 ***)DAT_10025984;
  if (DAT_10025998 < 8) {
    pppuVar3 = &DAT_10025984;
  }
  return pppuVar3;
}



// Function: FUN_1000652a at 1000652a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000652a(int param_1)

{
  FUN_10006026(&stack0xffffffd8,(int *)&stack0x00000004);
  FUN_100120d3(param_1 + 0x158);
  SetFocus(*(HWND *)(param_1 + 0x15c));
  FUN_1000331a((int *)&stack0x00000004);
  return;
}



// Function: FUN_1000657e at 1000657e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000657e(void *this,wchar_t param_1)

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
  char ***local_30 [4];
  uint local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x1000658a;
  if (param_1 != L'\xffff') {
    uVar1 = **(uint **)((int)this + 0x24);
    if ((uVar1 == 0) || (uVar1 + **(int **)((int)this + 0x34) * 2 <= uVar1)) {
      if (*(int *)((int)this + 0x54) != 0) {
        Reset_back((int)this);
        if (*(int *)((int)this + 0x44) != 0) {
          local_34 = (uint)(ushort)param_1;
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
          FUN_10005a5e(local_30,8,'\0');
          local_8 = 0;
LAB_10006622:
          ppppcVar4 = (char ****)local_30[0];
          if (local_1c < 0x10) {
            ppppcVar4 = local_30;
          }
          iVar3 = std::codecvt<wchar_t,char,int>::out
                            (*(codecvt<wchar_t,char,int> **)((int)this + 0x44),
                             (int *)((int)this + 0x4c),(wchar_t *)&local_34,
                             (wchar_t *)((int)&local_34 + 2),&local_3c,(char *)ppppcVar4,
                             (char *)((int)ppppcVar4 + local_20),&local_38);
          if (iVar3 < 0) goto LAB_10006710;
          if (iVar3 < 2) {
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
              if (_Count != sVar5) goto LAB_10006710;
            }
            *(undefined1 *)((int)this + 0x4a) = 1;
            if (local_3c == (wchar_t *)&local_34) goto code_r0x100066a2;
            local_8 = 0xffffffff;
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_30,true,0);
          }
          else {
            if (iVar3 != 3) goto LAB_10006710;
            FUN_10002c14((wchar_t)local_34,*(FILE **)((int)this + 0x54));
            local_8 = 0xffffffff;
            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                      ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_30,true,0);
          }
          goto LAB_10006724;
        }
        FUN_10002c14(param_1,*(FILE **)((int)this + 0x54));
      }
    }
    else {
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      *pwVar2 = param_1;
    }
  }
LAB_10006724:
  FUN_100127fb();
  return;
code_r0x100066a2:
  if (_Count == 0) {
    if (0x1f < local_20) {
LAB_10006710:
      local_8 = 0xffffffff;
      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::_Tidy
                ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_30,true,0);
      goto LAB_10006724;
    }
    FUN_10005803(local_30,8,'\0');
  }
  goto LAB_10006622;
}



// Function: FUN_1000672c at 1000672c

void __thiscall FUN_1000672c(void *this,undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int unaff_EDI;
  bool bVar4;
  void *local_c;
  void *local_8;
  
  if (((**(int **)((int)this + 0x20) == (int)this + 0x48) && (param_4 == 1)) &&
     (*(int *)((int)this + 0x44) == 0)) {
    bVar4 = 1 < param_2;
    param_2 = param_2 - 2;
    param_3 = param_3 + -1 + (uint)bVar4;
  }
  if ((((*(int *)((int)this + 0x54) != 0) &&
       (local_c = this, local_8 = this, cVar2 = FUN_10005f24((int *)this), cVar2 != '\0')) &&
      (((param_2 == 0 && param_3 == 0 && (param_4 == 1)) ||
       (iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(param_4,param_3),unaff_EDI),
       iVar3 == 0)))) &&
     (iVar3 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c), iVar3 == 0)) {
    Reset_back((int)this);
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



// Function: FUN_100067e3 at 100067e3

void __thiscall
FUN_100067e3(void *this,undefined4 *param_1,int param_2,int param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

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
    cVar2 = FUN_10005f24((int *)this);
    if (cVar2 != '\0') {
      iVar3 = fsetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c);
      if (iVar3 == 0) {
        if (param_2 != 0 || param_3 != 0) {
          iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(1,param_3),unaff_EDI);
          if (iVar3 != 0) goto LAB_10006876;
        }
        iVar3 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c);
        if (iVar3 == 0) {
          *(int *)((int)this + 0x4c) = param_6;
          Reset_back((int)this);
          *param_1 = 0;
          param_1[1] = 0;
          param_1[2] = local_c;
          param_1[3] = local_8;
          uVar4 = *(undefined4 *)((int)this + 0x4c);
          goto LAB_10006891;
        }
      }
    }
  }
LAB_10006876:
  uVar1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = *(undefined4 *)(_BADOFF_exref + 4);
  uVar4 = 0;
  *param_1 = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
LAB_10006891:
  param_1[4] = uVar4;
  return;
}



// Function: FUN_1000689b at 1000689b

undefined4 * __thiscall FUN_1000689b(void *this,undefined4 *param_1)

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



// Function: FUN_100068f8 at 100068f8

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __fastcall
FUN_100068f8(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  char cVar1;
  int iVar2;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar3;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    cVar1 = FUN_10005f24((int *)param_1);
    pbVar3 = param_1;
    if (cVar1 == '\0') {
      pbVar3 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
    }
    iVar2 = fclose(*(FILE **)(param_1 + 0x54));
    if (iVar2 == 0) goto LAB_10006921;
  }
  pbVar3 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
LAB_10006921:
  param_1[0x50] = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0;
  param_1[0x4a] = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init(param_1);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x4c) = DAT_10025978;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return pbVar3;
}



// Function: FUN_10006943 at 10006943

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10006943(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_100054db((int *)(param_1 + 0x5c));
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar1 = GetSystemMetrics(0x14);
  iVar2 = GetSystemMetrics(2);
  *(int *)(param_1 + 0x54) = iVar2;
  *(int *)(param_1 + 0x58) = iVar1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return param_1;
}



// Function: FUN_100069a2 at 100069a2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100069a2(int param_1)

{
  FUN_1000609b(param_1);
  FUN_1000606f((int *)(param_1 + 0x5c));
  return;
}



// Function: FUN_100069ce at 100069ce

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100069ce(void *this,void *param_1)

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
    FUN_100060d0(this,puVar1);
  }
  FUN_10002154(param_1,*puVar1);
                    /* WARNING: Load size is inaccurate */
  uVar3 = (**(code **)(*this + 0x10))(local_18);
  iVar2 = Ordinal_7(local_18[0]);
  if (iVar2 != 0) {
    uVar4 = lstrlenW(L"-");
    FUN_100013db(param_1,&DAT_10019334,uVar4);
    FUN_10002154(param_1,local_18[0]);
  }
  local_8._0_1_ = 1;
  Ordinal_6(local_18[0]);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  return uVar3;
}



// Function: Catch@10006a76 at 10006a76

undefined4 Catch_10006a76(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10006a6b;
}



// Function: FUN_10006a80 at 10006a80

void __cdecl FUN_10006a80(undefined4 param_1,void *param_2)

{
  FUN_1000552c(param_2,0);
  return;
}



// Function: FUN_10006a8f at 10006a8f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10006a8f(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_74 [48];
  undefined1 local_44 [60];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x10006a9b;
  FUN_1000621e(local_44,param_1,0,param_2,L"",0);
  local_8 = 0;
  FUN_10005aef(local_74,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_74,(ThrowInfo *)&DAT_1001ef98);
}



// Function: basic_string<> at 10006ad1

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
  FUN_1000689b(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_10006af6 at 10006af6

void __fastcall FUN_10006af6(int *param_1)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar1;
  
  pbVar1 = FUN_100068f8((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 6))
  ;
  if (pbVar1 == (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0) {
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(*param_1 + 4) + (int)param_1),2,false);
  }
  return;
}



// Function: FUN_10006b17 at 10006b17

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006b17(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  *(undefined ***)param_1 = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  if (*(int *)(param_1 + 0x54) != 0) {
    Reset_back((int)param_1);
  }
  if (param_1[0x50] != (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0) {
    FUN_100068f8(param_1);
  }
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  return;
}



// Function: FUN_10006b5c at 10006b5c

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10006b5c(void *this,byte param_1)

{
  FUN_10006b17((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10006b7b at 10006b7b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10006b7b(void *this,void *param_1)

{
  uint uVar1;
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10006b87;
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
  FUN_100127fb();
  return;
}



// Function: FUN_10006c45 at 10006c45

void __thiscall FUN_10006c45(void *this,undefined4 *param_1,int *param_2)

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
  FUN_100034e4((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_10006c8f;
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
LAB_10006c8f:
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
LAB_10006e6c:
    FUN_10006a80((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_10006e20:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xb] != '\x01'))
  goto LAB_10006e68;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_1000351f(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x2c) = 1;
          *(undefined1 *)(piVar5 + 0xb) = 0;
          FUN_10003564(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        FUN_1000351f(this,(int)piVar6);
        goto LAB_10006e68;
      }
LAB_10006e17:
      *(undefined1 *)(piVar5 + 0xb) = 0;
    }
  }
  else {
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10003564(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
      goto LAB_10006e17;
      if (*(char *)(*piVar5 + 0x2c) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        *(undefined1 *)(piVar5 + 0xb) = 0;
        FUN_1000351f(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(*piVar5 + 0x2c) = 1;
      FUN_10003564(this,piVar6);
LAB_10006e68:
      *(undefined1 *)(piVar7 + 0xb) = 1;
      goto LAB_10006e6c;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_10006e20;
}



// Function: FUN_10006ea2 at 10006ea2

void __thiscall FUN_10006ea2(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_10006ea2(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10006a80((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_10006ee6 at 10006ee6

void __thiscall FUN_10006ee6(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 < 0)) {
    *(undefined1 *)this = 1;
    FUN_10006a8f(param_1,*(undefined4 *)((int)this + 4));
  }
  return;
}



// Function: FUN_10006f06 at 10006f06

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10006f06(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined **)this = &DAT_10019364;
    *(undefined ***)((int)this + 0x10) = &PTR_1001935c;
    *(undefined4 *)((int)this + 0x70) = _vftable__exref;
    *(undefined4 *)((int)this + 0x70) = _vftable__exref;
  }
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
             (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18));
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_fstream<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  FUN_10002b9b((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18),0);
  return (basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10006f86 at 10006f86

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006f86(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x70) + 4) + -0x70 + param_1) =
       std::basic_fstream<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  FUN_10006b17((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x58));
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x58));
  return;
}



// Function: FUN_10006fc3 at 10006fc3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10006fc3(void *this,void *param_1)

{
  FUN_10006b7b((void *)((int)this + 4),param_1);
  return param_1;
}



// Function: FUN_10006ff4 at 10006ff4

void __fastcall FUN_10006ff4(void *param_1)

{
  FUN_10006ea2(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000701b at 1000701b

int __thiscall FUN_1000701b(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_10006ee6((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_10007037 at 10007037

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10007037(void *this,undefined4 *param_1)

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
  FUN_10003ab3(local_38);
  if (*(int *)((int)this + 0xc) != 0) {
    local_8._0_1_ = 9;
    iVar1 = (**(code **)**(undefined4 **)((int)this + 0xc))
                      (*(undefined4 **)((int)this + 0xc),&DAT_10018d00,&local_24);
    FUN_1000701b(local_38,iVar1);
    local_20 = (int *)0x0;
    local_8._0_1_ = 0xb;
    iVar1 = (**(code **)(*local_24 + 0x20))(local_24,&local_20);
    FUN_1000701b(local_38,iVar1);
    iVar1 = (**(code **)*local_20)(local_20,&DAT_10018f34,&local_28);
    FUN_1000701b(local_38,iVar1);
    HVar2 = CoCreateInstance((IID *)&DAT_10018cf0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10018ae0,&local_1c
                            );
    FUN_1000701b(local_38,HVar2);
    iVar1 = (**(code **)*local_1c)(local_1c,&DAT_10018ef4,local_18);
    FUN_1000701b(local_38,iVar1);
    iVar1 = (**(code **)(*local_18[0] + 0x10))(local_18[0],*param_1);
    FUN_1000701b(local_38,iVar1);
    iVar1 = (**(code **)(*local_18[0] + 0x20))(local_18[0],*(undefined4 *)((int)this + 4));
    FUN_1000701b(local_38,iVar1);
    iVar1 = (**(code **)(*local_28 + 0xc))(local_28,local_1c);
    FUN_1000701b(local_38,iVar1);
    local_8 = CONCAT31(local_8._1_3_,9);
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
    local_8 = 8;
    uVar3 = FUN_1000717d();
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



// Function: Catch@1000716e at 1000716e

undefined * Catch_1000716e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 8;
  return &DAT_1000717b;
}



// Function: FUN_1000717d at 1000717d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000717d(void)

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



// Function: FUN_100071cc at 100071cc

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_100071cc(int param_1)

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
  local_8 = 0x100071d8;
  local_24 = 0xffffffff;
  FUN_10003ab3(local_3c);
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  local_18[0] = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 7;
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = (**(code **)*puVar1)(puVar1,&DAT_10018ff8,&local_20);
    FUN_1000701b(local_3c,iVar3);
    piVar2 = local_20;
    piVar4 = FUN_10011d60(&local_2c,(undefined4 *)&DAT_10025f14);
    local_8._0_1_ = 8;
    iVar3 = (**(code **)(*piVar2 + 0x24))(piVar2,*piVar4,&local_1c);
    FUN_1000701b(local_3c,iVar3);
    local_8._0_1_ = 7;
    Ordinal_6(local_2c);
    iVar3 = (**(code **)*local_1c)(local_1c,&DAT_10019008,local_18);
    FUN_1000701b(local_3c,iVar3);
    local_28 = 0xffffffff;
    (**(code **)(*local_18[0] + 0x88))(local_18[0],&local_28);
    if (local_18[0] != (int *)0x0) {
      if ((short)local_28 == -1) {
        local_24 = 0xffffffff;
      }
      else {
        iVar3 = (**(code **)(*local_18[0] + 0x5c))(local_18[0],&local_24);
        FUN_1000701b(local_3c,iVar3);
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



// Function: Catch@1000730f at 1000730f

undefined4 Catch_1000730f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10007302;
}



// Function: FUN_10007319 at 10007319

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007319(int param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)(param_1 + 0x70);
  FUN_10006f86((int)piVar1);
  *(code **)piVar1 = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}



// Function: FUN_10007352 at 10007352

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10007352(undefined4 param_1,wchar_t *param_2)

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
  local_8 = 0x10007361;
  local_38 = param_1;
  local_34 = param_2;
  FUN_100051c8(local_d0,2,1);
  local_8 = 0;
  __RTDynamicCast(local_38,0);
  piVar1 = (int *)FUN_10003795(local_d0,local_34);
  FUN_10003795(piVar1,in_stack_ffffff24);
  iVar2 = __RTDynamicCast();
  pwVar3 = (wchar_t *)FUN_10006fc3(local_d0,local_30);
  local_8._0_1_ = 1;
  if (7 < *(uint *)(pwVar3 + 10)) {
    pwVar3 = *(wchar_t **)pwVar3;
  }
  local_34 = (wchar_t *)&stack0xffffff14;
  FUN_10001f54(&stack0xffffff14,pwVar3);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)(iVar2 + 0x70) + 0x3c))();
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  FUN_100050ea((int)local_d0);
  FUN_100127fb();
  return;
}



// Function: FUN_1000742a at 1000742a

void * __thiscall FUN_1000742a(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x70);
  FUN_10007319((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_1000744c at 1000744c

void __thiscall FUN_1000744c(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10006ff4(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_100034e4((int *)&param_2);
      FUN_10006c45(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000749f at 1000749f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000749f(void *this)

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
  local_8 = 0x100074ab;
  FUN_10003ab3(local_30);
  local_1c = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 8))();
  uStack_4c = 0x100074d9;
  FUN_1000701b(local_30,iVar1);
  local_18[0] = 0;
  local_8._0_1_ = 3;
  local_20 = (undefined1 *)&uStack_4c;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&uStack_4c,(CComBSTR *)&local_1c);
                    /* WARNING: Load size is inaccurate */
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = (**(code **)(*this + 0xc))();
  FUN_1000701b(local_30,iVar1);
  if (local_24 == 0) {
    iVar1 = FUN_10007037(this,local_18);
    FUN_1000701b(local_30,iVar1);
  }
  local_8._0_1_ = 2;
  Ordinal_6(local_18[0]);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_1c);
  *in_stack_00000010 = 1;
  return local_24;
}



// Function: Catch@10007557 at 10007557

undefined4 Catch_10007557(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000753f;
}



// Function: FUN_10007561 at 10007561

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10007561(void *this,undefined4 param_1,CComBSTR *param_2)

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
  FUN_10003ab3(local_2c);
  local_20 = 0;
  local_18[0] = (int *)0x0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 4;
  HVar1 = CoCreateInstance((IID *)&DAT_10018ce0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10018fe8,local_18);
  FUN_1000701b(local_2c,HVar1);
  uVar2 = FUN_100071cc((int)this);
  iVar3 = (**(code **)(*local_18[0] + 0xc))(local_18[0],uVar2);
  FUN_1000701b(local_2c,iVar3);
  Ordinal_6(*(undefined4 *)param_2);
  *(undefined4 *)param_2 = 0;
  iVar3 = (**(code **)(*local_18[0] + 0x18))(local_18[0],param_1,0,&local_1c);
  FUN_1000701b(local_2c,iVar3);
  ATL::CComBSTR::Attach(param_2,local_1c);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))(local_18[0]);
  }
  local_8 = 0xffffffff;
  Ordinal_6(param_1);
  return local_20;
}



// Function: Catch@10007631 at 10007631

undefined4 Catch_10007631(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10007619;
}



// Function: FUN_1000763e at 1000763e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_1000763e(void *this,long param_1,long param_2,undefined4 param_3,wchar_t *param_4)

{
  longlong lVar1;
  size_t sVar2;
  int *piVar3;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  wchar_t *pwVar5;
  char *in_stack_fffffd00;
  wchar_t *in_stack_fffffd0c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd18;
  wchar_t *in_stack_fffffd20;
  wchar_t *in_stack_fffffd2c;
  wchar_t *in_stack_fffffd3c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd48;
  wchar_t *in_stack_fffffd4c;
  int in_stack_fffffd58;
  wchar_t *in_stack_fffffd5c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd68;
  wchar_t *in_stack_fffffd70;
  int in_stack_fffffd78;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd7c;
  wchar_t *in_stack_fffffd80;
  code *pcVar6;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd8c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd90;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd94;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  LPWSTR local_224;
  ulong local_220;
  wchar_t local_21c [266];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2e4;
  local_8 = 0x1000764d;
  local_228 = param_3;
  FUN_10006f06(&stack0xfffffd0c,1);
  local_8 = 0;
  if (*(int *)((int)this + 0x28) == 0) {
    local_234 = 0;
    local_230 = 0;
    local_22c = 0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    Open(&local_234,(HKEY)0x80000002,
         L"Software\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths\\",0x2001f);
    local_220 = 0x208;
    ATL::CRegKey::QueryStringValue((CRegKey *)&local_234,L"ErrorLog",local_21c,&local_220);
    sVar2 = wcslen(local_21c);
    FID_conflict_assign((void *)((int)this + 0x18),(undefined4 *)local_21c,sVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    ATL::CRegKey::Close((CRegKey *)&local_234);
    if (*(int *)((int)this + 0x28) == 0) {
      local_8 = 0xffffffff;
      FUN_10007319((int)&stack0xfffffd0c);
      goto LAB_1000771d;
    }
  }
  pwVar5 = (wchar_t *)((int)this + 0x18);
  if (7 < *(uint *)((int)this + 0x2c)) {
    pwVar5 = *(wchar_t **)pwVar5;
  }
  FUN_10003d7f(&stack0xfffffd0c,pwVar5,10,0x40);
  if (in_stack_fffffd78 != 0) {
    pwVar5 = L" Error Log Entry:";
    piVar3 = (int *)FUN_100035ab((int *)&stack0xfffffd1c,&DAT_10019454);
    piVar3 = (int *)FUN_10003795(piVar3,pwVar5);
    piVar3 = (int *)FUN_100035ab(piVar3,in_stack_fffffd00);
    pbVar4 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             FUN_10003795(piVar3,in_stack_fffffd0c);
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
              (pbVar4,in_stack_fffffd18);
    local_220 = GetDateFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,(LPWSTR)0x0,0);
    lVar1 = (ulonglong)(local_220 + 1) * 2;
    local_224 = (LPWSTR)FUN_100126e8(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    GetDateFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,local_224,local_220);
    piVar3 = (int *)FUN_10003795((int *)&stack0xfffffd1c,L"On ");
    piVar3 = (int *)FUN_10003795(piVar3,in_stack_fffffd20);
    FUN_10003795(piVar3,in_stack_fffffd2c);
    operator_delete__(local_224);
    local_220 = GetTimeFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,(LPWSTR)0x0,0);
    lVar1 = (ulonglong)(local_220 + 1) * 2;
    local_224 = (LPWSTR)FUN_100126e8(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    GetTimeFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,local_224,local_220);
    piVar3 = (int *)FUN_10003795((int *)&stack0xfffffd1c,local_224);
    pbVar4 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             FUN_10003795(piVar3,in_stack_fffffd3c);
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
              (pbVar4,in_stack_fffffd48);
    operator_delete__(local_224);
    piVar3 = (int *)FUN_10003795((int *)&stack0xfffffd1c,L"In file ");
    piVar3 = (int *)FUN_10003795(piVar3,param_4);
    pbVar4 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             FUN_10003795(piVar3,in_stack_fffffd4c);
    pbVar4 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                       (pbVar4,in_stack_fffffd58);
    pbVar4 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             FUN_10003795((int *)pbVar4,in_stack_fffffd5c);
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
              (pbVar4,in_stack_fffffd68);
    pwVar5 = (wchar_t *)FUN_100126e8(0x20);
    _ltow_s(param_1,pwVar5,0x10,0x10);
    piVar3 = (int *)FUN_10003795((int *)&stack0xfffffd1c,L"The HRESULT was: 0x");
    pbVar4 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             FUN_10003795(piVar3,in_stack_fffffd70);
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
              (pbVar4,in_stack_fffffd7c);
    _ltow_s(param_2,pwVar5,0x10,0x10);
    piVar3 = (int *)FUN_10003795((int *)&stack0xfffffd1c,L"The result of the expression was: 0x");
    pbVar4 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             FUN_10003795(piVar3,in_stack_fffffd80);
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
              (pbVar4,in_stack_fffffd8c);
    operator_delete__(pwVar5);
    if (*(int *)((int)this + 8) != 0) {
      local_220 = 0;
      local_8._0_1_ = 2;
      (**(code **)(**(int **)((int)this + 8) + 0x14))();
      pcVar6 = endl_exref;
      piVar3 = (int *)FUN_10003795((int *)&stack0xfffffd1c,L"Description of error: ");
      pbVar4 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_10003795(piVar3,(wchar_t *)pcVar6);
      pbVar4 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                         (pbVar4,in_stack_fffffd90);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar4,in_stack_fffffd94);
      local_8 = (uint)local_8._1_3_ << 8;
      Ordinal_6();
    }
    FUN_10006af6((int *)&stack0xfffffd0c);
  }
  local_8 = 0xffffffff;
  FUN_10007319((int)&stack0xfffffd0c);
LAB_1000771d:
  FUN_100127fb();
  return;
}



// Function: FUN_100079fc at 100079fc

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100079fc(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 local_78 [48];
  undefined1 local_48 [64];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_80 = param_1;
  local_7c = 0;
  local_84 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  cVar2 = FUN_10002a2b(&local_84,0x68);
  uVar1 = local_84;
  if (cVar2 == '\0') {
    local_7c = 0x8000ffff;
    FUN_1000621e(local_48,0x8000ffff,0,0x4015,(wchar_t *)"OpenLoopLockPage.cpp",0x65);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10005aef(local_78,(int)local_48);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_78,(ThrowInfo *)&DAT_1001ef98);
  }
  local_84 = 0;
  *param_2 = uVar1;
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  local_8 = 0xffffffff;
  FUN_1001280a();
  return;
}



// Function: Catch@10007a91 at 10007a91

undefined * Catch_10007a91(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x88);
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007b17;
}



// Function: Catch@10007b1c at 10007b1c

undefined * Catch_10007b1c(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x84) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(*(int *)(unaff_EBP + -0x84) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  uVar5 = 0x68;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x78),
               *(undefined4 *)(unaff_EBP + -0x78),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007bd2;
}



// Function: Catch@10007bd7 at 10007bd7

undefined * Catch_10007bd7(void)

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
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  uVar5 = 0x68;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::exception::~exception((exception *)(unaff_EBP + -0xa4));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007c95;
}



// Function: Catch@10007c9a at 10007c9a

undefined4 Catch_10007c9a(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  uVar5 = 0x68;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10007a86;
}



// Function: FUN_10007d44 at 10007d44

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10007d44(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 local_78 [48];
  undefined1 local_48 [64];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_80 = param_1;
  local_7c = 0;
  local_84 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  cVar2 = FUN_10002a2b(&local_84,0x69);
  uVar1 = local_84;
  if (cVar2 == '\0') {
    local_7c = 0x8000ffff;
    FUN_1000621e(local_48,0x8000ffff,0,0x4015,(wchar_t *)"OpenLoopLockPage.cpp",0x79);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10005aef(local_78,(int)local_48);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_78,(ThrowInfo *)&DAT_1001ef98);
  }
  local_84 = 0;
  *param_2 = uVar1;
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  local_8 = 0xffffffff;
  FUN_1001280a();
  return;
}



// Function: Catch@10007dd9 at 10007dd9

undefined * Catch_10007dd9(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x88);
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007e5f;
}



// Function: Catch@10007e64 at 10007e64

undefined * Catch_10007e64(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x84) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(*(int *)(unaff_EBP + -0x84) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  uVar5 = 0x7c;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x78),
               *(undefined4 *)(unaff_EBP + -0x78),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007f1a;
}



// Function: Catch@10007f1f at 10007f1f

undefined * Catch_10007f1f(void)

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
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  uVar5 = 0x7c;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::exception::~exception((exception *)(unaff_EBP + -0xa4));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007fdd;
}



// Function: Catch@10007fe2 at 10007fe2

undefined4 Catch_10007fe2(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x98));
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x78) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x7c) + 0x14);
  uVar5 = 0x7c;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10007dce;
}



// Function: FUN_1000808c at 1000808c

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000808c(int param_1)

{
  undefined1 *pExceptionObject;
  int iVar1;
  undefined1 local_c8 [12];
  undefined *local_bc [2];
  undefined *local_b4;
  int local_b0;
  int local_ac;
  undefined1 local_a8 [48];
  undefined1 local_78 [48];
  undefined1 local_48 [64];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xd0;
  local_b0 = param_1;
  local_ac = 0x80004005;
  local_8 = 0;
  FUN_10002996(local_c8,'\x01',(LPCWSTR)0x7f02,'\x01');
  local_8._0_1_ = 1;
  local_ac = (**(code **)(**(int **)(param_1 + 0xe8) + 0xc))();
  if (local_ac < 0) {
    FUN_1000621e(local_48,local_ac,local_ac,0x4011,(wchar_t *)"OpenLoopLockPage.cpp",0x91);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10005aef(local_78,(int)local_48);
    pExceptionObject = local_78;
  }
  else {
    local_b4 = PTR_DAT_100243c0;
    local_bc[0] = PTR_DAT_100243c0;
    local_8._0_1_ = 4;
    iVar1 = FUN_100059b5(&local_b4,0x65);
    if (iVar1 != 0) {
      FUN_10006026(&stack0xffffff08,(int *)&local_b4);
      local_8._0_1_ = 4;
      FUN_1000652a(param_1 + -0x68);
      local_8._0_1_ = 3;
      FUN_1000331a((int *)local_bc);
      local_8._0_1_ = 1;
      FUN_1000331a((int *)&local_b4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001fa6((int)local_c8);
      local_8 = 0xffffffff;
      FUN_1001280a();
      return;
    }
    local_ac = -0x7fff0001;
    FUN_1000621e(local_48,0x8000ffff,0,0x4015,(wchar_t *)"OpenLoopLockPage.cpp",0x98);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_10005aef(local_a8,(int)local_48);
    pExceptionObject = local_a8;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_1001ef98);
}



// Function: Catch@100081ee at 100081ee

undefined * Catch_100081ee(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0xd0);
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x10);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -200));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 7;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000827d;
}



// Function: Catch@10008282 at 10008282

undefined * Catch_10008282(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -200));
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 7;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x10);
  uVar5 = 0x9d;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0xa8),
               *(undefined4 *)(unaff_EBP + -0xa8),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000834a;
}



// Function: Catch@1000834f at 1000834f

undefined * Catch_1000834f(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -200));
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x10);
  uVar5 = 0x9d;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  std::exception::~exception((exception *)(unaff_EBP + -0xdc));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008419;
}



// Function: Catch@1000841e at 1000841e

undefined4 Catch_1000841e(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -200));
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x10);
  uVar5 = 0x9d;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100081e0;
}



// Function: FUN_100084d4 at 100084d4

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100084d4(int param_1)

{
  int iVar1;
  undefined1 *pExceptionObject;
  undefined1 local_11c [40];
  undefined1 *local_f4;
  undefined *local_f0 [2];
  undefined *local_e8;
  undefined *local_e4;
  int local_e0;
  int local_dc;
  undefined1 local_d8 [48];
  undefined1 local_a8 [48];
  undefined1 local_78 [48];
  undefined1 local_48 [64];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x124;
  local_e0 = param_1;
  local_dc = 0x80004005;
  local_8 = 0;
  FUN_10002996(local_11c,'\x01',(LPCWSTR)0x7f02,'\x01');
  local_8._0_1_ = 1;
  local_dc = (**(code **)(**(int **)(param_1 + 0xe8) + 0x10))();
  if (local_dc < 0) {
    FUN_1000621e(local_48,local_dc,local_dc,0x4012,(wchar_t *)"OpenLoopLockPage.cpp",0xd7);
    local_8 = CONCAT31(local_8._1_3_,0x13);
    FUN_10005aef(local_a8,(int)local_48);
    pExceptionObject = local_a8;
  }
  else {
    local_e4 = PTR_DAT_100243c0;
    local_f0[0] = PTR_DAT_100243c0;
    local_e8 = PTR_DAT_100243c0;
    local_8._0_1_ = 5;
    iVar1 = FUN_100059b5(&local_e8,0x6a);
    if (iVar1 == 0) {
      local_dc = -0x7fff0001;
      FUN_1000621e(local_48,0x8000ffff,0,0x4015,(wchar_t *)"OpenLoopLockPage.cpp",0xc0);
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_10005aef(local_d8,(int)local_48);
      pExceptionObject = local_d8;
    }
    else {
      local_f4 = &stack0xfffffeb4;
      FUN_10006026(&stack0xfffffeb4,(int *)&local_e8);
      local_8._0_1_ = 5;
      FUN_1000652a(param_1 + -0x68);
      iVar1 = FUN_100059b5(&local_e4,0x75);
      if (iVar1 != 0) {
        local_f4 = &stack0xfffffeb4;
        FUN_10006026(&stack0xfffffeb4,(int *)&local_e4);
        local_8._0_1_ = 5;
        FUN_1000652a(param_1 + -0x68);
        local_8._0_1_ = 4;
        FUN_1000331a((int *)&local_e8);
        local_8._0_1_ = 3;
        FUN_1000331a((int *)local_f0);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000331a((int *)&local_e4);
        local_8 = 1;
        if (local_dc < 0) {
          FUN_10005e72((void *)(local_e0 + 0x44),(int *)0x0);
          local_dc = 0;
        }
        local_8 = local_8 & 0xffffff00;
        FUN_10001fa6((int)local_11c);
        local_8 = 0xffffffff;
        FUN_1001280a();
        return;
      }
      local_dc = -0x7fff0001;
      FUN_1000621e(local_48,0x8000ffff,0,0x4015,(wchar_t *)"OpenLoopLockPage.cpp",0xc5);
      local_8 = CONCAT31(local_8._1_3_,8);
      FUN_10005aef(local_78,(int)local_48);
      pExceptionObject = local_78;
    }
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_1001ef98);
}



// Function: Catch@100086c0 at 100086c0

undefined * Catch_100086c0(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x108);
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 10;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10008752;
}



// Function: Catch@10008757 at 10008757

undefined * Catch_10008757(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x104) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 10;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = *(undefined4 *)(*(int *)(unaff_EBP + -0x104) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  uVar5 = 0xca;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0xd8),
               *(undefined4 *)(unaff_EBP + -0xd8),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10008822;
}



// Function: Catch@10008827 at 10008827

undefined * Catch_10008827(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  uVar5 = 0xca;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  std::exception::~exception((exception *)(unaff_EBP + -0x124));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100088f4;
}



// Function: Catch@100088f9 at 100088f9

undefined4 Catch_100088f9(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0x11;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 10;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  uVar5 = 0xca;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10008680;
}



// Function: Catch@100089ee at 100089ee

undefined * Catch_100089ee(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x10c);
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0x15;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 0x14;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008a7d;
}



// Function: Catch@10008a82 at 10008a82

undefined * Catch_10008a82(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0x16;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0xe8) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 0x14;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = *(undefined4 *)(*(int *)(unaff_EBP + -0xe8) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  uVar5 = 0xda;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0xd8),
               *(undefined4 *)(unaff_EBP + -0xd8),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008b4a;
}



// Function: Catch@10008b4f at 10008b4f

undefined * Catch_10008b4f(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0x19;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 0x18;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  uVar5 = 0xda;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0x1a;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  std::exception::~exception((exception *)(unaff_EBP + -0x130));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008c19;
}



// Function: Catch@10008c1e at 10008c1e

undefined4 Catch_10008c1e(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x100));
    *(undefined1 *)(unaff_EBP + -4) = 0x1b;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 0x14;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xd8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xdc) + 0x10);
  uVar5 = 0xda;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0x1c;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100086b2;
}



// Function: FUN_10008cd4 at 10008cd4

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10008cd4(void *param_1)

{
  HWND pHVar1;
  undefined4 *puVar2;
  undefined *local_b0;
  CComBSTR local_ac [4];
  wchar_t *local_a8;
  LPCWSTR local_a4;
  LPCWSTR local_a0;
  void *local_9c;
  int local_98;
  undefined1 local_94 [48];
  undefined4 local_64 [7];
  undefined1 local_48 [64];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xb8;
  local_8 = 0x10008ce3;
  local_9c = param_1;
  pHVar1 = GetDlgItem(*(HWND *)((int)param_1 + 4),0xcb);
  *(HWND *)((int)param_1 + 0x15c) = pHVar1;
  local_a4 = (LPCWSTR)PTR_DAT_100243c0;
  local_8 = 0;
  FUN_100059b5(&local_a4,0x70);
  pHVar1 = GetDlgItem(*(HWND *)((int)param_1 + 4),0xca);
  SetWindowTextW(pHVar1,local_a4);
  local_a0 = (LPCWSTR)Ordinal_2();
  if (local_a0 == (LPCWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1000108d(0x8007000e);
  }
  local_8._0_1_ = 1;
  Ordinal_6();
  local_a0 = (LPCWSTR)0x0;
  FUN_100021cd(0x73,(int *)&local_a0);
  pHVar1 = GetDlgItem(*(HWND *)((int)param_1 + 4),0x74);
  SetWindowTextW(pHVar1,local_a0);
  FUN_10002763((void *)((int)param_1 + 0xe8),*(undefined4 *)((int)param_1 + 4));
  local_98 = 0;
  local_b0 = PTR_DAT_100243c0;
  local_a8 = (wchar_t *)PTR_DAT_100243c0;
  local_8._0_1_ = 4;
  local_98 = FUN_100059b5(&local_a8,0x66);
  if (local_98 < 0) {
    FUN_1000621e(local_48,local_98,local_98,0x4015,(wchar_t *)"OpenLoopLockPage.cpp",0x103);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_10005aef(local_94,(int)local_48);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_94,(ThrowInfo *)&DAT_1001ef98);
  }
  FUN_10001f54(local_64,local_a8);
  local_8._0_1_ = 6;
  puVar2 = local_64;
  FUN_10011d60((int *)local_ac,puVar2);
  local_8._0_1_ = 7;
  ATL::CComBSTR::CComBSTR((CComBSTR *)&stack0xffffff1c,local_ac);
  local_8._0_1_ = 7;
  FUN_10004d95(param_1,puVar2);
  local_8._0_1_ = 6;
  Ordinal_6();
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_64,'\x01',0);
  local_8._0_1_ = 3;
  FUN_1000331a((int *)&local_a8);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000331a((int *)&local_b0);
  local_8 = 1;
  FUN_10008f3b();
  return;
}



// Function: Catch@10008ea6 at 10008ea6

undefined * Catch_10008ea6(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0xb8);
  this = (int *)(*(int *)(unaff_EBP + -0x98) + 0x78);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 9;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x94) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10008f35;
}



// Function: FUN_10008f3b at 10008f3b

void FUN_10008f3b(void)

{
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(int *)(unaff_EBP + -0x94) < 0) {
    FUN_10005e72((void *)(unaff_ESI + 0xac),(int *)0x0);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  Ordinal_6(*(undefined4 *)(unaff_EBP + -0x9c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000331a((int *)(unaff_EBP + -0xa0));
  FUN_1001280a();
  return;
}



// Function: Catch@10008f7a at 10008f7a

undefined * Catch_10008f7a(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 9;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x94) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0x98) + 0x78);
  uVar5 = 0x10e;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x94),
               *(undefined4 *)(unaff_EBP + -0x94),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10009042;
}



// Function: Catch@10009047 at 10009047

undefined * Catch_10009047(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x94) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x98) + 0x78);
  uVar5 = 0x10e;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  std::exception::~exception((exception *)(unaff_EBP + -0xc4));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10009111;
}



// Function: Catch@10009116 at 10009116

undefined * Catch_10009116(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 9;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x94) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x98) + 0x78);
  uVar5 = 0x10e;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10008f35;
}



// Function: FUN_100091cc at 100091cc

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100091cc(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 *pExceptionObject;
  undefined1 local_a8 [48];
  undefined1 local_78 [48];
  undefined1 local_48 [64];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc4;
  local_8 = 0;
  piVar1 = (int *)(param_1 + 0x130);
  if (*piVar1 != 0) {
    FUN_100024a8(piVar1);
  }
  iVar2 = FUN_1000501d(param_1,param_2);
  if (iVar2 < 0) {
    FUN_1000621e(local_48,iVar2,iVar2,0x4014,(wchar_t *)"OpenLoopLockPage.cpp",0x149);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10005aef(local_78,(int)local_48);
    pExceptionObject = local_78;
  }
  else {
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x38))
                      (*(undefined4 **)(param_1 + 0x38),&DAT_10018f04,piVar1);
    if (-1 < iVar2) {
      local_8 = 0xffffffff;
      FUN_1001280a();
      return;
    }
    FUN_1000621e(local_48,iVar2,iVar2,0x4014,(wchar_t *)"OpenLoopLockPage.cpp",0x14e);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10005aef(local_a8,(int)local_48);
    pExceptionObject = local_a8;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_1001ef98);
}



// Function: Catch@100092b2 at 100092b2

undefined * Catch_100092b2(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0xb4);
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x58);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -0xc4));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009341;
}



// Function: Catch@10009346 at 10009346

undefined * Catch_10009346(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0xc4));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x58);
  uVar5 = 0x150;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0xa8),
               *(undefined4 *)(unaff_EBP + -0xa8),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000940e;
}



// Function: Catch@10009413 at 10009413

undefined * Catch_10009413(void)

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
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0xc4));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 7;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x58);
  uVar5 = 0x150;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  std::exception::~exception((exception *)(unaff_EBP + -0xd0));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100094dd;
}



// Function: Catch@100094e2 at 100094e2

undefined4 Catch_100094e2(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0xc4));
    *(undefined1 *)(unaff_EBP + -4) = 10;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 3;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0xa8) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0xac) + 0x58);
  uVar5 = 0x150;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100092a4;
}



// Function: FUN_10009598 at 10009598

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009598(int param_1)

{
  (**(code **)(*(int *)(param_1 + 0xa4) + 0x24))(*(undefined4 *)(param_1 + 0x30));
  FUN_100024a8((int *)(param_1 + 0x130));
  if (*(undefined4 **)(param_1 + 0x134) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x134))(1);
    *(undefined4 *)(param_1 + 0x134) = 0;
  }
  FUN_10005054(param_1);
  FUN_1001280a();
  return;
}



// Function: Catch@100095fc at 100095fc

undefined * Catch_100095fc(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x54);
  this = (int *)(*(int *)(unaff_EBP + -0x4c) + 0x58);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -100));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000967c;
}



// Function: Catch@10009681 at 10009681

undefined * Catch_10009681(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -100));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x50) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(*(int *)(unaff_EBP + -0x50) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0x4c) + 0x58);
  uVar5 = 0x16b;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x48),
               *(undefined4 *)(unaff_EBP + -0x48),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009731;
}



// Function: Catch@10009736 at 10009736

undefined * Catch_10009736(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  *(undefined1 *)(unaff_EBP + -4) = 5;
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -100));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 5;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x4c) + 0x58);
  uVar5 = 0x16b;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  std::exception::~exception((exception *)(unaff_EBP + -0x70));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100097f1;
}



// Function: Catch@100097f6 at 100097f6

undefined4 Catch_100097f6(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -100));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 1;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x4c) + 0x58);
  uVar5 = 0x16b;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100095f2;
}



// Function: FUN_100098a0 at 100098a0

void __fastcall FUN_100098a0(void *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*(int *)((int)param_1 + -0x90) + 0x4c))(1);
  if (*(int **)((int)param_1 + 8) != piVar1) {
    FUN_1000110f((int *)((int)param_1 + 8),piVar1);
  }
  piVar1 = (int *)(**(code **)(*(int *)((int)param_1 + -0x90) + 0x4c))(2);
  if (*(int **)((int)param_1 + 0xc) != piVar1) {
    FUN_1000110f((int *)((int)param_1 + 0xc),piVar1);
  }
  FUN_1000749f(param_1);
  return;
}



// Function: FUN_100098fe at 100098fe

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_100098fe(int param_1,wchar_t *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *local_78;
  void *local_74;
  uint local_70;
  int local_6c;
  undefined4 local_68;
  ushort local_64 [46];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_6c = param_1;
  local_70 = 0;
  local_68 = 0;
  local_8 = 0;
  local_68 = FUN_10007352(param_1,param_2);
  local_68 = (**(code **)(*(int *)(param_1 + 0xa4) + 0x1c))(*(undefined4 *)(param_1 + 0x30));
  FUN_10001f54(local_64,(wchar_t *)PTR_u__5CD1DEEB_ABBE_439f_BB98_1D2B501_10025678);
  local_8._0_1_ = 1;
  FUN_10005d2a((void *)(param_1 + 0xa8),&local_74,local_64);
  local_8._0_1_ = 0;
  FID_conflict__Tidy(local_64,'\x01',0);
  if (local_74 == *(void **)(param_1 + 0xac)) {
    local_68 = 0x80004005;
  }
  else if (*(int *)(param_1 + 0x134) == 0) {
    pvVar1 = operator_new(8);
    local_8._0_1_ = 2;
    if (pvVar1 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
      local_74 = pvVar1;
    }
    else {
      puVar2 = (undefined4 *)((int)local_74 + 0x28);
      local_74 = pvVar1;
      puVar2 = FUN_100029d8(&local_78,(int *)*puVar2);
      local_8 = CONCAT31(local_8._1_3_,3);
      local_70 = 1;
      puVar2 = FUN_10002ad1(local_74,puVar2);
    }
    *(undefined4 **)(param_1 + 0x134) = puVar2;
    if ((local_70 & 1) != 0) {
      local_70 = local_70 & 0xfffffffe;
      local_8 = 0;
      if (local_78 != (int *)0x0) {
        (**(code **)(*local_78 + 8))(local_78);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_10009a79();
  return;
}



// Function: Catch@100099f6 at 100099f6

undefined * Catch_100099f6(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x7c);
  this = (int *)(*(int *)(unaff_EBP + -0x68) + 0x58);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 6;
  }
  else {
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(iVar1 + 4);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009a76;
}



// Function: FUN_10009a79 at 10009a79

void FUN_10009a79(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  if (*(int *)(unaff_EBP + -100) != 0) {
    (**(code **)(*unaff_ESI + 0x1c))();
  }
  FUN_1001280a();
  return;
}



// Function: Catch@10009a90 at 10009a90

undefined * Catch_10009a90(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x78) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 6;
  }
  else {
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(*(int *)(unaff_EBP + -0x78) + 4);
  }
  this = (int *)(*(int *)(unaff_EBP + -0x68) + 0x58);
  uVar5 = 0x1b1;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -100),
               *(undefined4 *)(unaff_EBP + -100),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009b40;
}



// Function: Catch@10009b45 at 10009b45

undefined * Catch_10009b45(void)

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
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 10;
  }
  else {
    *(undefined4 *)(unaff_EBP + -100) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x68) + 0x58);
  uVar5 = 0x1b1;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  std::exception::~exception((exception *)(unaff_EBP + -0x88));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009c03;
}



// Function: Catch@10009c08 at 10009c08

undefined * Catch_10009c08(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int *this;
  char *pcVar4;
  undefined4 uVar5;
  
  bVar1 = type_info::operator==
                    ((type_info *)&TypeDescriptor_10024944,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar1) {
    iVar2 = FUN_10003a99((undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
  }
  else {
    *(undefined4 *)(unaff_EBP + -100) = 0x8000ffff;
  }
  this = (int *)(*(int *)(unaff_EBP + -0x68) + 0x58);
  uVar5 = 0x1b1;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009a76;
}



// Function: FUN_10009cb2 at 10009cb2

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10009cb2(int param_1)

{
  uint uVar1;
  undefined1 local_78 [28];
  undefined4 local_5c [4];
  int local_4c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x10009cbe;
  local_4c = param_1;
  FUN_10003ab3(local_5c);
  local_8 = 1;
  uVar1 = (**(code **)(*(int *)(param_1 + -0x30) + 4))(0x53,0,0,local_78);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  FUN_1000701b(local_5c,uVar1);
  local_8 = 0xffffffff;
  FUN_1001280a();
  return;
}



// Function: Catch@10009d0e at 10009d0e

undefined * Catch_10009d0e(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x60);
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x68);
  FUN_10005599(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_10006285(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_1000763e(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_10004c53((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000242d((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
  }
  else {
    FUN_1000701b((void *)(unaff_EBP + -0x58),*(int *)(iVar1 + 4));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10009d90;
}



// Function: Catch@10009d95 at 10009d95

undefined * Catch_10009d95(void)

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
    iVar2 = FUN_1000242d((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x5c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
  }
  else {
    FUN_1000701b((void *)(unaff_EBP + -0x58),*(int *)(*(int *)(unaff_EBP + -0x5c) + 4));
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x68);
  uVar5 = 0x203;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x4c),
               *(undefined4 *)(unaff_EBP + -0x4c),uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10009e47;
}



// Function: Catch@10009e4c at 10009e4c

undefined * Catch_10009e4c(void)

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
    iVar2 = FUN_1000242d((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
  }
  else {
    FUN_1000701b((void *)(unaff_EBP + -0x58),-0x7fff0001);
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x68);
  uVar5 = 0x203;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::exception::~exception((exception *)(unaff_EBP + -0x80));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10009f0a;
}



// Function: Catch@10009f0f at 10009f0f

undefined4 Catch_10009f0f(void)

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
    iVar2 = FUN_1000242d((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
  }
  else {
    FUN_1000701b((void *)(unaff_EBP + -0x58),-0x7fff0001);
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x68);
  uVar5 = 0x203;
  pcVar4 = "OpenLoopLockPage.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_1000621e((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(wchar_t *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_10005599(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_10006285(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_1000763e(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_10004c53((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10009cff;
}



// Function: FUN_10009fbc at 10009fbc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009fbc(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000744c(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_10009ff6 at 10009ff6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009ff6(void *param_1)

{
  FUN_10009fbc(param_1);
  return;
}



// Function: FUN_1000a014 at 1000a014

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000a014(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000a020;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_10004b71(param_1);
  return local_18;
}



// Function: FUN_1000a040 at 1000a040

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000a040(int param_1)

{
  FUN_1000a014(param_1 + 4);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_1000a079 at 1000a079

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a079(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10009fbc((void *)(param_1 + 4));
  return;
}



// Function: FUN_1000a0bd at 1000a0bd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000a0bd(int param_1)

{
  *(undefined4 *)(param_1 + 0xe4) = 0;
  FUN_10003a02(param_1);
  FUN_10004f65((undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x74) = 0;
  FUN_10006943(param_1 + 0xe8);
  FUN_10001989((undefined4 *)(param_1 + 0x78));
  *(undefined ***)(param_1 + 0xac) = CComErrorDisplay<class_COpenLoopLockPage>::vftable;
  FUN_10003920((undefined4 *)(param_1 + 0xb0));
  FUN_1000a040(param_1 + 0xc4);
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  FUN_1001209f((undefined4 *)(param_1 + 0x158));
  return param_1;
}



// Function: FUN_1000a166 at 1000a166

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a166(int param_1)

{
  int *piVar1;
  
  FUN_10011fce((undefined4 *)(param_1 + 0x158));
  piVar1 = *(int **)(param_1 + 0x150);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000a079(param_1 + 0xc4);
  FUN_10003a38((undefined4 *)(param_1 + 0xb0));
  *(undefined ***)(param_1 + 0xac) = CComErrorDisplay<class_COpenLoopLockPage>::vftable;
  FUN_100019f2((undefined4 *)(param_1 + 0x78));
  FUN_100069a2(param_1 + 0xe8);
  FUN_10003cf1(param_1 + 0x20);
  FUN_100034b4(param_1);
  return;
}



// Function: FUN_1000a211 at 1000a211

bool __cdecl FUN_1000a211(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 1000a22b

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



// Function: AtlCoTaskMemCAlloc at 1000a24d

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



// Function: FUN_1000a27a at 1000a27a

LPVOID __cdecl FUN_1000a27a(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_1000a2aa at 1000a2aa

bool __cdecl FUN_1000a2aa(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_1000a2d7 at 1000a2d7

void __cdecl FUN_1000a2d7(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 1000a2f4

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



// Function: FUN_1000a31d at 1000a31d

DWORD FUN_1000a31d(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_1000a332 at 1000a332

uint __cdecl FUN_1000a332(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FID_conflict:RegCreateKeyExW at 1000a348

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
                    /* WARNING: Could not recover jumptable at 0x1000a39d. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 1000a3ab

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
                    /* WARNING: Could not recover jumptable at 0x1000a3ee. Too many branches */
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



// Function: FUN_1000a3fd at 1000a3fd

undefined4 __fastcall FUN_1000a3fd(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1000a401 at 1000a401

void __cdecl FUN_1000a401(short *param_1,int param_2,short *param_3)

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



// Function: FUN_1000a44f at 1000a44f

int __fastcall FUN_1000a44f(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 1000a466

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10025fec == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10025fe8 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10025fec = '\x01';
    }
    if (DAT_10025fe8 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10025fe8)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Create at 1000a4d6

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



// Function: SetStringValue at 1000a53e

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



// Function: FUN_1000a575 at 1000a575

LSTATUS __thiscall FUN_1000a575(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_1000a5b8 at 1000a5b8

undefined4 __fastcall FUN_1000a5b8(undefined4 *param_1)

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



// Function: FUN_1000a5d8 at 1000a5d8

undefined4 * __thiscall FUN_1000a5d8(void *this,ulong param_1)

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



// Function: FUN_1000a60e at 1000a60e

void __fastcall FUN_1000a60e(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_1000a618 at 1000a618

undefined4 __thiscall FUN_1000a618(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_1000a27a(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_100010dd((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_1000a6a6 at 1000a6a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000a6a6(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x1000a6b2;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10026010 & 1) == 0) {
    DAT_10026010 = DAT_10026010 | 1;
    DAT_10025ff4 = 8;
    _DAT_10025ffc = 0x4008;
    _DAT_10026004 = 0x13;
    DAT_10025ff0 = &DAT_100187f4;
    DAT_10025ff8 = &DAT_100187f0;
    _DAT_10026000 = &DAT_100187ec;
    _DAT_10026008 = &DAT_100187e8;
    _DAT_1002600c = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10025ff0)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x1000a729;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_10025ff4)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_1000a735;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_1000a735:
  *(undefined4 *)(puVar4 + -4) = 0x1000a73a;
  return uVar2;
}



// Function: FUN_1000a74e at 1000a74e

int __cdecl FUN_1000a74e(ushort param_1)

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



// Function: FUN_1000a784 at 1000a784

undefined4 __cdecl FUN_1000a784(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1001a038)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1001a03c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_1000a7b2 at 1000a7b2

LPCWSTR __cdecl FUN_1000a7b2(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_1000a7df at 1000a7df

undefined4 FUN_1000a7df(ushort param_1)

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



// Function: FUN_1000a805 at 1000a805

void __fastcall FUN_1000a805(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_1000a7df(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_1000a827 at 1000a827

undefined4 __thiscall FUN_1000a827(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_1000a805((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_1000a5b8((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_1000a7df(*pWVar2);
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



// Function: FUN_1000a93d at 1000a93d

undefined4 FUN_1000a93d(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_100189d8;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10018a08);
  return 1;
}



// Function: FUN_1000a96c at 1000a96c

bool FUN_1000a96c(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_1000a9a1 at 1000a9a1

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000a9a1(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_1000a827(this,param_1), -1 < iVar1)) {
    FUN_1000a805((undefined4 *)this);
    iVar1 = FUN_1000a827(this,local_2008);
    if (-1 < iVar1) {
      FUN_1000a827(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: DllCanUnloadNow at 1000aa06

HRESULT DllCanUnloadNow(void)

{
                    /* 0xaa06  1  DllCanUnloadNow */
  return (uint)(DAT_10026654 != 0);
}



// Function: FUN_1000aa12 at 1000aa12

undefined4 FUN_1000aa12(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_100256f8;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000aa31 at 1000aa31

undefined4 __thiscall FUN_1000aa31(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10025700 = *param_3;
    DAT_10025704 = param_3[1];
    DAT_10025708 = param_3[2];
    DAT_1002570c = param_3[3];
  }
  piVar2 = DAT_10026944;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10026944, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10026944 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10026944;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10026948; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_1000aa8f at 1000aa8f

void FUN_1000aa8f(int param_1)

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



// Function: FUN_1000aad5 at 1000aad5

void __fastcall FUN_1000aad5(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_1000aaea at 1000aaea

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000aaea(undefined4 *param_1)

{
  FUN_1000a0bd((int)param_1);
  *param_1 = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[8] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[9] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x19] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1a] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1b] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1c] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1e] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x2b] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x2c] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x31] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x38] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  (**(code **)(*DAT_100256fc + 4))();
  return param_1;
}



// Function: FUN_1000ab7c at 1000ab7c

short * __cdecl FUN_1000ab7c(short *param_1,short param_2,int param_3)

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



// Function: InlineIsEqualUnknown at 1000ab9d

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



// Function: AtlInternalQueryInterface at 1000abcb

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
          if (pcVar1 == (code *)0x1) goto LAB_1000abff;
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
LAB_1000abff:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_1000ac6c at 1000ac6c

void __thiscall
FUN_1000ac6c(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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



// Function: FUN_1000aca4 at 1000aca4

undefined4 __fastcall FUN_1000aca4(int param_1)

{
  BOOL BVar1;
  
  if (((DAT_100268dc != (HMODULE)0x0) && (*(int *)(param_1 + 4) == 1)) &&
     (BVar1 = FreeLibrary(DAT_100268dc), BVar1 != 1)) {
    return 0x80004005;
  }
  return 0;
}



// Function: FUN_1000accd at 1000accd

void FUN_1000accd(int param_1)

{
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10026914);
    InterlockedExchange(&DAT_100268dc,param_1);
    DAT_100268d8 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10026914);
  }
  return;
}



// Function: FUN_1000ad04 at 1000ad04

uint __thiscall FUN_1000ad04(void *this,ushort *param_1,uint param_2,uint param_3)

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
        if ((*puVar6 == uVar1) && (iVar4 = FUN_10001fc4(puVar6,param_1,param_3), iVar4 == 0)) {
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



// Function: FUN_1000ad90 at 1000ad90

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ad90(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[8] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[9] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x19] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1a] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1b] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1c] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x1e] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x2b] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x2c] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x31] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x38] = ATL::CComObject<class_COpenLoopLockPage>::vftable;
  param_1[0x39] = 0xc0000001;
  (**(code **)(*DAT_100256fc + 8))();
  FUN_1000a166((int)param_1);
  return;
}



// Function: FUN_1000ae2a at 1000ae2a

undefined4 FUN_1000ae2a(int param_1)

{
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1;
  return *(undefined4 *)(param_1 + 0xc4);
}



// Function: FUN_1000ae40 at 1000ae40

undefined4 FUN_1000ae40(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0xc4);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0xc4);
  if ((*piVar1 == 0) && ((int *)(param_1 + -0x20) != (int *)0x0)) {
    (**(code **)(*(int *)(param_1 + -0x20) + 4))(1);
  }
  return uVar2;
}



// Function: FUN_1000ae68 at 1000ae68

undefined4 * __thiscall FUN_1000ae68(void *this,byte param_1)

{
  FUN_1000ad90((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000ae87 at 1000ae87

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ae87(int param_1)

{
  FUN_1000a166(param_1);
  return;
}



// Function: FUN_1000aea5 at 1000aea5

void __fastcall FUN_1000aea5(undefined4 *param_1)

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



// Function: FUN_1000aed2 at 1000aed2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000aed2(void *this,undefined4 param_1)

{
  FUN_1000a0bd((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0x20) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0x24) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 100) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0x68) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0x6c) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0x70) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0x78) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0xac) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0xb0) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0xc4) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined ***)((int)this + 0xe0) = ATL::CComContainedObject<class_COpenLoopLockPage>::vftable;
  *(undefined4 *)((int)this + 0xe4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000af62 at 1000af62

void FUN_1000af62(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc4) + 4))(*(int **)(param_1 + 0xc4));
  return;
}



// Function: FUN_1000af78 at 1000af78

void FUN_1000af78(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc4) + 8))(*(int **)(param_1 + 0xc4));
  return;
}



// Function: FUN_1000af8e at 1000af8e

void FUN_1000af8e(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc4))(*(undefined4 **)(param_1 + 0xc4),param_2,param_3);
  return;
}



// Function: FUN_1000afa9 at 1000afa9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000afa9(void *this,byte param_1)

{
  FUN_1000a166((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000afda at 1000afda

void FUN_1000afda(void)

{
  return;
}



// Function: FUN_1000afdd at 1000afdd

undefined4 __thiscall FUN_1000afdd(void *this,undefined4 param_1,undefined4 param_2,int param_3)

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



// Function: FUN_1000b031 at 1000b031

int __thiscall FUN_1000b031(void *this,undefined4 *param_1)

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



// Function: FUN_1000b068 at 1000b068

void __fastcall FUN_1000b068(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_1000b072 at 1000b072

void __thiscall FUN_1000b072(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1000108d(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: FUN_1000b097 at 1000b097

int FUN_1000b097(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined1 local_28 [36];
  
  uVar3 = param_2;
  piVar2 = param_1;
  FUN_1000ac6c(local_28,param_1[1],param_2,param_3,param_4,1);
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



// Function: FUN_1000b168 at 1000b168

void __fastcall FUN_1000b168(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x2d) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x2d) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x2d) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x2d) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x2d) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: FUN_1000b1ae at 1000b1ae

void __fastcall FUN_1000b1ae(undefined4 *param_1)

{
  LPRECT lpRect;
  HWND hWnd;
  
  lpRect = (LPRECT)(param_1 + 0x11);
  GetClientRect((HWND)*param_1,lpRect);
  InvalidateRect((HWND)*param_1,lpRect,1);
  hWnd = (HWND)*param_1;
  lpRect->left = param_1[0x13] - param_1[0x15];
  param_1[0x12] = param_1[0x14] - param_1[0x16];
  UpdateWindow(hWnd);
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 1000b1e5

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1000108d(lVar1);
  }
  return local_8;
}



// Function: FUN_1000b20a at 1000b20a

void FUN_1000b20a(void)

{
  return;
}



// Function: FUN_1000b20b at 1000b20b

void FUN_1000b20b(int param_1)

{
  FUN_1000af62(param_1 + -0xa4);
  return;
}



// Function: FUN_1000b218 at 1000b218

void FUN_1000b218(int param_1)

{
  FUN_1000af62(param_1 + -0x48);
  return;
}



// Function: FUN_1000b222 at 1000b222

void FUN_1000b222(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000af8e(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000b22c at 1000b22c

void __thiscall FUN_1000b22c(void *this,byte param_1)

{
  FUN_1000ae68((void *)((int)this + -0x78),param_1);
  return;
}



// Function: FUN_1000b234 at 1000b234

void __thiscall FUN_1000b234(void *this,byte param_1)

{
  FUN_1000afa9((void *)((int)this + -0xac),param_1);
  return;
}



// Function: FUN_1000b23f at 1000b23f

void FUN_1000b23f(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000af8e(param_1 + -0xc0,param_2,param_3);
  return;
}



// Function: FUN_1000b24c at 1000b24c

void FUN_1000b24c(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000af8e(param_1 + -0x44,param_2,param_3);
  return;
}



// Function: FUN_1000b256 at 1000b256

void FUN_1000b256(int param_1)

{
  FUN_1000af62(param_1 + -0x4c);
  return;
}



// Function: FUN_1000b260 at 1000b260

void FUN_1000b260(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000af8e(param_1 + -0xa4,param_2,param_3);
  return;
}



// Function: FUN_1000b26d at 1000b26d

void __thiscall FUN_1000b26d(void *this,byte param_1)

{
  FUN_1000afa9((void *)((int)this + -0xb0),param_1);
  return;
}



// Function: FUN_1000b278 at 1000b278

void FUN_1000b278(int param_1)

{
  FUN_1000ae40(param_1 + -4);
  return;
}



// Function: FUN_1000b282 at 1000b282

void FUN_1000b282(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000af8e(param_1 + -0x48,param_2,param_3);
  return;
}



// Function: FUN_1000b28c at 1000b28c

void FUN_1000b28c(int param_1)

{
  FUN_1000ae40(param_1 + -0xc0);
  return;
}



// Function: FUN_1000b299 at 1000b299

void FUN_1000b299(int param_1)

{
  FUN_1000ae40(param_1 + -0x44);
  return;
}



// Function: FUN_1000b2a3 at 1000b2a3

void __thiscall FUN_1000b2a3(void *this,byte param_1)

{
  FUN_1000ae68((void *)((int)this + -0x24),param_1);
  return;
}



// Function: FUN_1000b2ab at 1000b2ab

void FUN_1000b2ab(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000af8e(param_1 + -0x4c,param_2,param_3);
  return;
}



// Function: FUN_1000b2b5 at 1000b2b5

void FUN_1000b2b5(int param_1)

{
  FUN_1000ae40(param_1 + -0xa4);
  return;
}



// Function: FUN_1000b2c2 at 1000b2c2

void __thiscall FUN_1000b2c2(void *this,byte param_1)

{
  FUN_1000afa9((void *)((int)this + -0x78),param_1);
  return;
}



// Function: FUN_1000b2ca at 1000b2ca

void FUN_1000b2ca(int param_1)

{
  FUN_1000ae40(param_1 + -0x48);
  return;
}



// Function: FUN_1000b2d4 at 1000b2d4

void FUN_1000b2d4(int param_1)

{
  FUN_1000ae2a(param_1 + -4);
  return;
}



// Function: FUN_1000b2de at 1000b2de

void __thiscall FUN_1000b2de(void *this,byte param_1)

{
  FUN_1000ae68((void *)((int)this + -0xc4),param_1);
  return;
}



// Function: FUN_1000b2e9 at 1000b2e9

void FUN_1000b2e9(int param_1)

{
  FUN_1000ae2a(param_1 + -0xc0);
  return;
}



// Function: FUN_1000b2f6 at 1000b2f6

void FUN_1000b2f6(int param_1)

{
  FUN_1000ae40(param_1 + -0x4c);
  return;
}



// Function: FUN_1000b300 at 1000b300

void FUN_1000b300(int param_1)

{
  FUN_1000ae2a(param_1 + -0x44);
  return;
}



// Function: FUN_1000b30a at 1000b30a

void FUN_1000b30a(int param_1)

{
  FUN_1000af78(param_1 + -4);
  return;
}



// Function: FUN_1000b314 at 1000b314

void FUN_1000b314(int param_1)

{
  FUN_1000af78(param_1 + -0xc0);
  return;
}



// Function: FUN_1000b321 at 1000b321

void FUN_1000b321(int param_1)

{
  FUN_1000af78(param_1 + -0x44);
  return;
}



// Function: FUN_1000b32b at 1000b32b

void FUN_1000b32b(int param_1)

{
  FUN_1000ae2a(param_1 + -0xa4);
  return;
}



// Function: FUN_1000b338 at 1000b338

void FUN_1000b338(int param_1)

{
  FUN_1000ae2a(param_1 + -0x48);
  return;
}



// Function: FUN_1000b342 at 1000b342

void __thiscall FUN_1000b342(void *this,byte param_1)

{
  FUN_1000afa9((void *)((int)this + -0x24),param_1);
  return;
}



// Function: FUN_1000b34a at 1000b34a

void FUN_1000b34a(int param_1)

{
  FUN_1000af78(param_1 + -0xa4);
  return;
}



// Function: FUN_1000b357 at 1000b357

void __thiscall FUN_1000b357(void *this,byte param_1)

{
  FUN_1000ae68((void *)((int)this + -0xac),param_1);
  return;
}



// Function: FUN_1000b362 at 1000b362

void FUN_1000b362(int param_1)

{
  FUN_1000af78(param_1 + -0x48);
  return;
}



// Function: FUN_1000b36c at 1000b36c

void FUN_1000b36c(int param_1)

{
  FUN_1000ae2a(param_1 + -0x4c);
  return;
}



// Function: FUN_1000b376 at 1000b376

void FUN_1000b376(int param_1)

{
  FUN_1000af62(param_1 + -4);
  return;
}



// Function: FUN_1000b380 at 1000b380

void __thiscall FUN_1000b380(void *this,byte param_1)

{
  FUN_1000afa9((void *)((int)this + -0xc4),param_1);
  return;
}



// Function: FUN_1000b38b at 1000b38b

void __thiscall FUN_1000b38b(void *this,byte param_1)

{
  FUN_1000ae68((void *)((int)this + -0xb0),param_1);
  return;
}



// Function: FUN_1000b396 at 1000b396

void FUN_1000b396(int param_1)

{
  FUN_1000af62(param_1 + -0xc0);
  return;
}



// Function: FUN_1000b3a3 at 1000b3a3

void FUN_1000b3a3(int param_1)

{
  FUN_1000af78(param_1 + -0x4c);
  return;
}



// Function: FUN_1000b3ad at 1000b3ad

void FUN_1000b3ad(int param_1)

{
  FUN_1000af62(param_1 + -0x44);
  return;
}



// Function: FUN_1000b3b7 at 1000b3b7

int __fastcall FUN_1000b3b7(int param_1)

{
  long lVar1;
  
  FUN_1000a44f(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_100256fc = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10025fd8 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_1000b3f8 at 1000b3f8

void __fastcall FUN_1000b3f8(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_1000aa8f((int)piVar1);
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



// Function: FUN_1000b431 at 1000b431

void __fastcall FUN_1000b431(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_1000aa8f((int)piVar1);
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



// Function: FUN_1000b436 at 1000b436

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000b436(int param_1)

{
  FUN_1000b3f8(param_1);
  return;
}



// Function: FUN_1000b454 at 1000b454

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000b454(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_1000b454(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_100127fb();
  return;
}



// Function: FUN_1000b539 at 1000b539

undefined4 __fastcall FUN_1000b539(int *param_1)

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
LAB_1000b57e:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_1000b57e;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_1000aea5(param_1);
  return 0;
}



// Function: FUN_1000b590 at 1000b590

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000b590(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_1000a618(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10001319(local_14);
  }
  return uVar1;
}



// Function: FUN_1000b5d7 at 1000b5d7

void FUN_1000b5d7(int param_1)

{
  FUN_1000b539((int *)(param_1 + 4));
  return;
}



// Function: FUN_1000b5e9 at 1000b5e9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000b5e9(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x1000b5f8;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_1000b7c3;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000a31d();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_1000b656;
      FUN_1000a2d7(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_1000b793;
      }
    }
    else {
LAB_1000b793:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_1000b656:
  local_8 = 0xffffffff;
  FUN_10001319(&local_248);
LAB_1000b7c3:
  FUN_100127fb();
  return;
}



// Function: FUN_1000b7cb at 1000b7cb

void __fastcall FUN_1000b7cb(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10026944;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10026944, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10026948; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_1000b3f8(param_1);
  return;
}



// Function: FUN_1000b81d at 1000b81d

undefined4
FUN_1000b81d(undefined4 param_1,int param_2,int param_3,int param_4,uint *param_5,int param_6)

{
  undefined4 uVar1;
  
  if ((param_6 == 0) && (param_2 == 0x7c)) {
    if (param_3 == -0x14) {
      *(uint *)(param_4 + 4) = *(uint *)(param_4 + 4) | 0x10000;
    }
    *param_5 = (uint)(param_3 != -0x14);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000b853 at 1000b853

void __thiscall FUN_1000b853(void *this,undefined4 param_1,undefined4 param_2)

{
  if (*(char *)((int)this + 0x14) == '\0') {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0x2c))(param_1);
  }
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x28))(param_2);
  return;
}



// Function: FUN_1000b876 at 1000b876

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b876(undefined4 param_1,int *param_2)

{
  undefined4 **ppuVar1;
  int iVar2;
  
  ppuVar1 = FUN_10006498();
  if (ppuVar1 == (undefined4 **)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Ordinal_2(ppuVar1);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1000108d(0x8007000e);
    }
  }
  *param_2 = iVar2;
  Ordinal_6(0);
  return 0;
}



// Function: FUN_1000b8ca at 1000b8ca

uint __thiscall FUN_1000b8ca(void *this,ushort *param_1,uint param_2,uint param_3)

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
      while (puVar3 = (ushort *)FUN_1000ab7c((short *)puVar6,uVar1,param_2), puVar3 != (ushort *)0x0
            ) {
        iVar2 = FUN_10001fc4(puVar3,param_1,param_3);
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



// Function: FUN_1000b969 at 1000b969

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b969(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x164);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000aaea(puVar1);
    }
    uVar2 = FUN_1000b9c9();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000b9bc at 1000b9bc

undefined * Catch_1000b9bc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b9c6;
}



// Function: FUN_1000b9c9 at 1000b9c9

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b9c9(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[0x39] = unaff_ESI[0x39] + 1;
    unaff_ESI[0x39] = unaff_ESI[0x39] + -1;
    iVar1 = (**(code **)unaff_ESI[8])
                      (unaff_ESI + 8,*(undefined4 *)(unaff_EBP + 0xc),
                       *(undefined4 *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 4))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000ba02 at 1000ba02

void FUN_1000ba02(int param_1,_GUID *param_2,void **param_3)

{
  ATL::AtlInternalQueryInterface
            ((void *)(param_1 + -0x20),(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001a3a8,param_2,param_3);
  return;
}



// Function: FUN_1000ba20 at 1000ba20

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000ba20(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_COpenLoopLockPage>::vftable;
  FUN_1000aed2((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_100256fc + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000ba63 at 1000ba63

undefined4 FUN_1000ba63(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: Release at 1000ba73

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



// Function: FUN_1000ba94 at 1000ba94

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ba94(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_COpenLoopLockPage>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_100256fc + 8))();
  FUN_1000a166((int)(param_1 + 2));
  return;
}



// Function: FUN_1000bada at 1000bada

long FUN_1000bada(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001a3a8,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1000bb26 at 1000bb26

undefined4 * __thiscall FUN_1000bb26(void *this,byte param_1)

{
  FUN_1000ba94((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000bb4a at 1000bb4a

void __fastcall FUN_1000bb4a(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000bb5a at 1000bb5a

void __fastcall FUN_1000bb5a(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_1000b068(param_1);
    return;
  }
  return;
}



// Function: FUN_1000bb67 at 1000bb67

undefined * FUN_1000bb67(void)

{
  return FUN_1000b097;
}



// Function: FUN_1000bb6d at 1000bb6d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000bb6d(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_1000bbc1 at 1000bbc1

void __thiscall FUN_1000bbc1(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_1);
  FUN_100028d3(this,0,*(uint *)((int)this + 0x10),(ushort *)param_1,sVar1);
  return;
}



// Function: FUN_1000bbe6 at 1000bbe6

void FUN_1000bbe6(int param_1,_GUID *param_2,void **param_3)

{
  FUN_1000ba02(param_1 + -0x4c,param_2,param_3);
  return;
}



// Function: FUN_1000bbf0 at 1000bbf0

void FUN_1000bbf0(int param_1,_GUID *param_2,void **param_3)

{
  FUN_1000ba02(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000bbfa at 1000bbfa

void FUN_1000bbfa(int param_1,_GUID *param_2,void **param_3)

{
  FUN_1000ba02(param_1 + -0xc0,param_2,param_3);
  return;
}



// Function: FUN_1000bc07 at 1000bc07

void FUN_1000bc07(int param_1,_GUID *param_2,void **param_3)

{
  FUN_1000ba02(param_1 + -0x44,param_2,param_3);
  return;
}



// Function: FUN_1000bc11 at 1000bc11

void FUN_1000bc11(int param_1,_GUID *param_2,void **param_3)

{
  FUN_1000ba02(param_1 + -0xa4,param_2,param_3);
  return;
}



// Function: FUN_1000bc1e at 1000bc1e

void FUN_1000bc1e(int param_1,_GUID *param_2,void **param_3)

{
  FUN_1000ba02(param_1 + -0x48,param_2,param_3);
  return;
}



// Function: FUN_1000bc28 at 1000bc28

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_1000bc28(undefined4 *param_1)

{
  FUN_1000b3b7((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10025fe4 = param_1;
  return param_1;
}



// Function: FUN_1000bc5d at 1000bc5d

void __fastcall FUN_1000bc5d(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000bc68 at 1000bc68

void __fastcall FUN_1000bc68(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000bc73 at 1000bc73

HRESULT __thiscall FUN_1000bc73(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1001b2d8,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001a67c,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_1000bcbf at 1000bcbf

undefined4 FUN_1000bcbf(void)

{
  return 0x80004005;
}



// Function: FUN_1000bcc7 at 1000bcc7

void FUN_1000bcc7(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10018b10);
  return;
}



// Function: FUN_1000bce1 at 1000bce1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000bce1(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_1000b3f8((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000bd18 at 1000bd18

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000bd18(int *param_1)

{
  FUN_1000b539(param_1);
  FUN_1000aea5(param_1);
  return;
}



// Function: FUN_1000bd42 at 1000bd42

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000bd42(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_1000b539(param_1 + 1);
  FUN_1000bd18(param_1 + 1);
  return;
}



// Function: FUN_1000bd76 at 1000bd76

undefined4 FUN_1000bd76(void)

{
  return 0x80004001;
}



// Function: FUN_1000bd7e at 1000bd7e

undefined4 FUN_1000bd7e(void)

{
  return 1;
}



// Function: FUN_1000bd84 at 1000bd84

undefined4 * __thiscall FUN_1000bd84(void *this,byte param_1)

{
  FUN_1000bd42((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000bda3 at 1000bda3

undefined4 __fastcall FUN_1000bda3(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_1000b031((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_1000bde4 at 1000bde4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000bde4(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x1000bdf0;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_1000a5d8(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_1000aa12(&local_5d);
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
LAB_1000bed9:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_1000bf4d;
                }
                iVar3 = FUN_1000a5b8((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_1000a618(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_1000bf73;
                  goto LAB_1000bf15;
                }
                local_55 = '\0';
              }
              else {
LAB_1000bf15:
                if (local_55 != '\0') goto LAB_1000bf4d;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_1000b590(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_1000bf73;
                local_56 = '\0';
              }
              goto LAB_1000bf4d;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_1000b590(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_1000bed9;
            }
LAB_1000bf73:
            local_5c = -0x7ff8fff2;
            goto LAB_1000be54;
          }
LAB_1000bf4d:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_1000a7b2(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_1000be54;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_1000bda3(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_1000b590(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_1000bf73;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_1000bfe6;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_1000be54;
            }
            iVar3 = FUN_1000a618(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_1000bf73;
          }
          else {
            iVar3 = FUN_1000a618(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_1000bfe6:
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
LAB_1000be54:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_100127fb();
  return;
}



// Function: FUN_1000c051 at 1000c051

undefined4 FUN_1000c051(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_1000aa31(&DAT_1002664c,(int *)&PTR_DAT_100249e0,param_1,(undefined4 *)&DAT_10019ed8);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_1000b7cb(0x1002664c);
  }
  return 1;
}



// Function: FUN_1000c093 at 1000c093

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000c093(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&PTR_1001b2c8), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_1001b2e8,(LPUNKNOWN)0x0,1,(IID *)&DAT_1001a774,&local_1a8
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
          goto LAB_1000c31e;
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
      FUN_10001319(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_1000c31e:
  FUN_100127fb();
  return;
}



// Function: FUN_1000c3b1 at 1000c3b1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000c3b1(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_1000b5e9(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_1000aa12((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_1000c481 at 1000c481

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000c481(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_1000b5e9(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_1000aa12(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_1000c643;
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
LAB_1000c643:
  FUN_100127fb();
  return;
}



// Function: FUN_1000c64b at 1000c64b

int FUN_1000c64b(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000a211(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_1000c093((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_1000c481(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000c6d1 at 1000c6d1

int FUN_1000c6d1(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_1000a211(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_1000c093((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_1000c3b1(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000c758 at 1000c758

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_1000c758(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_10018ae0,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_1000c813;
          }
          else {
LAB_1000c813:
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



// Function: FUN_1000c843 at 1000c843

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000c843(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10001333((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_1000c874 at 1000c874

undefined4 FUN_1000c874(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_1000c8b2 at 1000c8b2

undefined4 FUN_1000c8b2(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_100256fc + 8))();
  }
  else {
    (**(code **)(*DAT_100256fc + 4))();
  }
  return 0;
}



// Function: FUN_1000c8d1 at 1000c8d1

undefined4 * __thiscall FUN_1000c8d1(void *this,byte param_1)

{
  FUN_1000c843((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c8f0 at 1000c8f0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000c8f0(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 **ppuVar2;
  undefined4 uVar3;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 1;
  (**(code **)*param_1)(param_1,&DAT_1001a610,local_14);
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x20))(param_1);
  piVar1 = local_14[0];
  ppuVar2 = FUN_10006498();
  if (ppuVar2 == (undefined4 **)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = (undefined4 *)Ordinal_2(ppuVar2);
    if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_1000108d(0x8007000e);
    }
  }
  local_8._0_1_ = 2;
  uVar3 = (**(code **)(*piVar1 + 0x20))(piVar1,param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(param_1);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar3;
}



// Function: FUN_1000c981 at 1000c981

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c981(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x16c);
    if (this != (void *)0x0) {
      FUN_1000ba20(this,param_1);
    }
    uVar1 = FUN_1000c9eb();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000c9de at 1000c9de

undefined * Catch_1000c9de(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c9e8;
}



// Function: FUN_1000c9eb at 1000c9eb

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c9eb(void)

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



// Function: FUN_1000ca15 at 1000ca15

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000ca15(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_100011c9(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_1000ca50 at 1000ca50

undefined4 __thiscall FUN_1000ca50(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_1000bb6d(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 1000caa7

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
    FUN_1000b072(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000cad6

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
    FUN_1000b072(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000cb05

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
    FUN_1000b072(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000cb34 at 1000cb34

void __fastcall FUN_1000cb34(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10002874((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0xb) = 0;
  return;
}



// Function: FUN_1000cb5b at 1000cb5b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000cb5b(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_100126e8(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_1000cbc1();
    return uVar3;
  }
  return 0;
}



// Function: Catch@1000cbb5 at 1000cbb5

undefined * Catch_1000cbb5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000cbbf;
}



// Function: FUN_1000cbc1 at 1000cbc1

void FUN_1000cbc1(void)

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
  uVar4 = FUN_100126e8(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_1000cc12();
  return;
}



// Function: Catch@1000cc03 at 1000cc03

undefined * Catch_1000cc03(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_1000cc10;
}



// Function: FUN_1000cc12 at 1000cc12

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_1000cc12(void)

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
    FUN_100010dd(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_100010dd(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_1000ca50(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_1000cc6e;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_1000cc6e:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_1000cca6 at 1000cca6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000cca6(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_1000cb5b(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10001319(local_14);
  }
  return iVar1;
}



// Function: FUN_1000cd01 at 1000cd01

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000cd01(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1001522b;
  local_10 = ExceptionList;
  uStack_2144 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_1000a827(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_1000a6a6(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_1000d07a;
  FUN_1000a805((undefined4 *)this);
  iVar1 = FUN_1000a827(this,local_2018);
  if (iVar1 < 0) goto LAB_1000d07a;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_1000d056:
    if (uVar2 != 0) {
      FUN_1000a332(uVar2);
      goto LAB_1000d07a;
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
        FUN_1000cf89();
        return;
      }
      goto LAB_1000d07a;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10001319((int *)&local_2124);
      goto LAB_1000d056;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_1000ce22();
      return;
    }
  }
  FUN_1000a827(this,param_3);
LAB_1000d07a:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000ce16 at 1000ce16

undefined * Catch_1000ce16(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000ce20;
}



// Function: FUN_1000ce22 at 1000ce22

void FUN_1000ce22(void)

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
    pWVar2 = (WCHAR *)FUN_1000a575(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_1000b068((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_1000a827(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_1000a332((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000d092;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@1000cf6e at 1000cf6e

undefined * Catch_1000cf6e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_1000cf7b;
}



// Function: FUN_1000cf89 at 1000cf89

void FUN_1000cf89(void)

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
      FUN_1000b068((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_1000a74e(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_1000b068((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_1000a827(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_1000a332(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000d092;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000d096 at 1000d096

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000d096(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_1001528a;
  local_10 = ExceptionList;
  local_14 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_1000d0fa:
  iVar3 = FUN_1000a827(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_1000d10a:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_1000d567:
    if (*param_1 == L'}') goto LAB_1000d10a;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_1000a827(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000d10a;
      if (param_3 == 0) goto LAB_1000d249;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_1000a7b2(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_1000a93d(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_1000b454(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_1000d249;
        }
        iVar3 = FUN_1000a827(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_1000a9a1(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_1000d666;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_1000d6e5;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_1000d10a;
    }
LAB_1000d249:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_1000a827(local_2220,param_1);
      if (iVar3 < 0) goto LAB_1000d10a;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_1000a7b2(param_1,L'\\');
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
          iVar3 = FUN_1000a827(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_1000a9a1(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_1000d096(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_1000a827(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_1000d704;
          iVar3 = FUN_1000a827(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_1000cd01(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_1000d66b;
        }
      }
      goto LAB_1000d10a;
    }
    iVar3 = FUN_1000a827(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_1000a827(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_1000d10a;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_1000cd01(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_1000d666;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_1000d6e5;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_1000a332(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_1000d6e5:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_1000d10a;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_1000a9a1(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_1000a96c(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_1000a93d(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_1000b454(&local_2234,local_21c);
        }
        goto LAB_1000d567;
      }
      bVar2 = FUN_1000a96c(local_2234);
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
            FUN_1000a332(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_1000d6e5;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_1000d666:
          ATL::CRegKey::Close(pCVar8);
LAB_1000d66b:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_1000d096(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_1000d0fa;
            goto LAB_1000d10a;
          }
        }
        goto LAB_1000d567;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_1000d567;
    }
LAB_1000d704:
    FUN_1000a332(uVar6);
    goto LAB_1000d10a;
  }
  goto LAB_1000d567;
}



// Function: FUN_1000d72d at 1000d72d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000d72d(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1002694c);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_10018ae0,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1002694c);
          if (*piVar2 != 0) goto LAB_1000d7c1;
        }
        else {
LAB_1000d7c1:
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
  piVar2 = FUN_1000c758((int *)&DAT_1002693c,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_1000d7f9 at 1000d7f9

void FUN_1000d7f9(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000b969(0,param_2,param_3);
    return;
  }
  FUN_1000c981(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000d819 at 1000d819

undefined4 * __thiscall
FUN_1000d819(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,
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
    FUN_10001bda(this,uVar8,'\0');
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
    goto LAB_1000daec;
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
      goto LAB_1000d960;
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
      goto LAB_1000daec;
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
LAB_1000d960:
    pvVar5 = (void *)((int)pvVar5 + param_4 * 2);
    pvVar4 = (void *)((int)pvVar4 + param_1 * 2);
  }
  memmove(pvVar4,pvVar5,param_5 * 2);
LAB_1000daec:
  *(uint *)((int)this + 0x10) = uVar8;
  pvVar5 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar5 = *this;
  }
  *(undefined2 *)((int)pvVar5 + uVar8 * 2) = 0;
  return (undefined4 *)this;
}



// Function: FUN_1000db1c at 1000db1c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000db1c(undefined4 *param_1)

{
  FUN_1000ca15(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_1000db4a at 1000db4a

LONG FUN_1000db4a(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_100256fc + 4))();
  }
  return LVar1;
}



// Function: FUN_1000db74 at 1000db74

LONG FUN_1000db74(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_100256fc + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 1000dbb3

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001a840,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000dbcd at 1000dbcd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000dbcd(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_1000c843(param_1);
  return;
}



// Function: FUN_1000dbfc at 1000dbfc

undefined4 * __thiscall FUN_1000dbfc(void *this,byte param_1)

{
  FUN_1000dbcd((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000dc1b at 1000dc1b

undefined4 * __thiscall FUN_1000dc1b(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_10001bda(this,uVar2,'\0');
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



// Function: FUN_1000dcc0 at 1000dcc0

undefined4 * __thiscall FUN_1000dcc0(void *this,undefined4 *param_1,uint param_2)

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
      bVar1 = FUN_10001bda(this,uVar2,'\0');
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
    this = FUN_1000dc1b(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000dd62 at 1000dd62

undefined4 * __thiscall
FUN_1000dd62(void *this,uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

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
      bVar1 = FUN_10001bda(this,uVar2,'\0');
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
    this = FUN_1000d819(this,param_1,param_2,(undefined4 *)this,(int)param_3 - (int)pvVar5 >> 1,
                        (uint)param_4);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000dec1 at 1000dec1

void FUN_1000dec1(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000c64b(0x1002693c,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10025fdc != (code *)0x0)) {
    (*DAT_10025fdc)(DAT_100268d8);
  }
  return;
}



// Function: FUN_1000deef at 1000deef

void FUN_1000deef(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_10025fe0 != (code *)0x0) && (iVar1 = (*DAT_10025fe0)(), iVar1 < 0)) {
    return;
  }
  FUN_1000c6d1(0x1002693c,param_1,param_2);
  return;
}



// Function: FUN_1000df15 at 1000df15

undefined4 * __fastcall FUN_1000df15(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = ATL::
             CComObject<class_CComEventPublisher<class_COpenLoopLockPage>::CPublisherEventsImpl>::
             vftable;
  (**(code **)(*DAT_100256fc + 4))();
  return param_1;
}



// Function: FUN_1000df5c at 1000df5c

undefined4 FUN_1000df5c(undefined4 param_1,undefined4 *param_2)

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



// Function: Release at 1000df79

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
    (**(code **)(*in_stack_00000004 + 0x24))(1);
  }
  return uVar2;
}



// Function: FUN_1000df9a at 1000df9a

undefined4 FUN_1000df9a(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    iVar5 = 0;
    piVar3 = (int *)FUN_100023a4();
    iVar1 = *piVar3;
    while (iVar1 != 0) {
      iVar5 = iVar5 + 1;
      puVar4 = FUN_100023a4();
      iVar1 = *(int *)(puVar4 + iVar5 * 4);
    }
    *param_2 = iVar5;
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000dfce at 1000dfce

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000dfce(void *this,wchar_t *param_1)

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
  local_8 = 0x1000dfda;
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
      local_18 = (uint *)FUN_100126e8(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_1000df33,
                   (_func_void_void_ptr *)&LAB_1000122b);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_1000e07e();
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



// Function: Catch@1000e06e at 1000e06e

undefined * Catch_1000e06e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e078;
}



// Function: FUN_1000e07e at 1000e07e

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e07e(void)

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



// Function: FUN_1000e136 at 1000e136

void FUN_1000e136(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10001518(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_1000e169 at 1000e169

void __fastcall FUN_1000e169(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_CComEventPublisher<class_COpenLoopLockPage>::CPublisherEventsImpl>::
             vftable;
  param_1[1] = 0xc0000001;
                    /* WARNING: Could not recover jumptable at 0x1000e17e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_100256fc + 8))();
  return;
}



// Function: FUN_1000e181 at 1000e181

undefined4 * __thiscall FUN_1000e181(void *this,byte param_1)

{
  FUN_1000e169((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e1a0 at 1000e1a0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_1000e1a0(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_10018ae0,&local_18);
    (**(code **)*param_1)(param_1,&DAT_10018ae0,local_14);
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



// Function: FUN_1000e22b at 1000e22b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e22b(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_1000e270();
  return uVar1;
}



// Function: Catch@1000e260 at 1000e260

undefined * Catch_1000e260(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e26a;
}



// Function: FUN_1000e270 at 1000e270

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000e270(void)

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



// Function: QueryInterface at 1000e2cb

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001a894,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000e2e5 at 1000e2e5

IUnknown * __thiscall FUN_1000e2e5(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_1000e1a0(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1001a8cc);
  }
  return pIVar2;
}



// Function: FUN_1000e312 at 1000e312

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000e312(void *this,undefined4 param_1)

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
  local_8 = 0x1000e321;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_1000e557;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_100256fc + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_10025700,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_100268d8,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_1000e521;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001319((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_1001a8bc,&local_224);
        if (-1 < iVar2) {
          FUN_1000e2e5(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_100256fc == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_100256fc + 4;
        }
        pcVar4 = FUN_1000e136;
        pvVar5 = this;
        FUN_1000e22b(iVar2);
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
LAB_1000e521:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_1000dfce(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_1000e557:
  FUN_100127fb();
  return;
}



// Function: FUN_1000e55f at 1000e55f

undefined4 * __fastcall FUN_1000e55f(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = ATL::CComObject<class_CComEventPublisher<class_COpenLoopLockPage>::CPublisherEventImpl>
             ::vftable;
  (**(code **)(*DAT_100256fc + 4))();
  return param_1;
}



// Function: Release at 1000e581

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
    (**(code **)(*in_stack_00000004 + 0x28))(1);
  }
  return uVar2;
}



// Function: FUN_1000e5a2 at 1000e5a2

void __fastcall FUN_1000e5a2(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CComEventPublisher<class_COpenLoopLockPage>::CPublisherEventImpl>
             ::vftable;
  param_1[1] = 0xc0000001;
                    /* WARNING: Could not recover jumptable at 0x1000e5b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_100256fc + 8))();
  return;
}



// Function: FUN_1000e5ba at 1000e5ba

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_1000e5ba(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uStack_28;
  int iStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x1000e5c6;
  puVar5 = (undefined4 *)auStack_20;
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iStack_24 = 0x1000e5d9;
    puVar2 = FUN_100023a4();
    if (*(int *)(puVar2 + *(int *)(param_1 + 8) * 4) == 0) {
      iVar3 = 0;
    }
    else {
      puVar5 = &uStack_28;
      uStack_28 = 0x1000e610;
      iStack_24 = *(int *)(puVar2 + *(int *)(param_1 + 8) * 4);
      iVar3 = Ordinal_2();
      if (iVar3 == 0) {
        puVar5[-1] = 0x8007000e;
                    /* WARNING: Subroutine does not return */
        puVar5[-2] = &UNK_1000e621;
        FUN_1000108d(puVar5[-1]);
      }
    }
    *param_2 = iVar3;
    local_8 = 0xffffffff;
    *(undefined4 *)((int)puVar5 + -4) = 0;
    puVar4 = (undefined4 *)((int)puVar5 + -8);
    puVar5 = (undefined4 *)((int)puVar5 + -8);
    *puVar4 = 0x1000e5ff;
    Ordinal_6();
    uVar1 = 0;
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x1000e606;
  return uVar1;
}



// Function: FUN_1000e622 at 1000e622

undefined4 * __thiscall FUN_1000e622(void *this,byte param_1)

{
  FUN_1000e5a2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: QueryInterface at 1000e641

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001a90c,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000e65b at 1000e65b

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000e65b(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_1000bde4(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_1000e751:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x1000e6a6:
  if ((((sVar1 == 0) || (iVar3 = FUN_1000a827(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_1000a784(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_1000a827(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_1000e743;
  if (param_2 == 0) {
    iVar3 = FUN_1000d096(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_1000e743;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_1000d096(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_1000d096(this,local_2008,pHVar4,0,0);
LAB_1000e743:
      CoTaskMemFree(local_200c);
      goto LAB_1000e751;
    }
  }
  FUN_1000a805((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x1000e6a6;
}



// Function: DllGetClassObject at 1000e792

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0xe792  2  DllGetClassObject */
  piVar1 = FUN_1000d72d(&DAT_1002664c,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_1000e7a0 at 1000e7a0

int __thiscall FUN_1000e7a0(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000a211(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_1000c093((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_1000dec1(param_1,param_2);
  return iVar5;
}



// Function: FUN_1000e80f at 1000e80f

int __thiscall FUN_1000e80f(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000a211(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_1000c093((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_1000deef(param_1,param_2);
  return iVar5;
}



// Function: FUN_1000e87e at 1000e87e

undefined4 __thiscall FUN_1000e87e(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_1000e312(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_1000e8be at 1000e8be

undefined4 __thiscall
FUN_1000e8be(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_1000e312(this,param_4);
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



// Function: FUN_1000e95f at 1000e95f

void __thiscall
FUN_1000e95f(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_1000e312(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000e9a2 at 1000e9a2

undefined4 FUN_1000e9a2(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000e87e(&PTR_DAT_10025348,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000e9c6 at 1000e9c6

void FUN_1000e9c6(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000e8be(&PTR_DAT_10025348,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000e9e6 at 1000e9e6

void FUN_1000e9e6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_1000e95f(&PTR_DAT_10025348,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000e9f4 at 1000e9f4

undefined4 FUN_1000e9f4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000e87e(&PTR_DAT_10025364,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000ea18 at 1000ea18

void FUN_1000ea18(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000e8be(&PTR_DAT_10025364,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000ea38 at 1000ea38

void FUN_1000ea38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_1000e95f(&PTR_DAT_10025364,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: Catch@1000eaa4 at 1000eaa4

undefined1 * Catch_1000eaa4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000eaae;
}



// Function: FUN_1000eaf6 at 1000eaf6

void __thiscall FUN_1000eaf6(void *this,uint param_1,undefined4 *param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)wcslen(param_3);
  FUN_1000dd62(this,param_1,param_2,(undefined4 *)param_3,puVar1);
  return;
}



// Function: FUN_1000eb1c at 1000eb1c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000eb1c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000df15(puVar1);
    }
    uVar2 = FUN_1000eb77();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000eb68 at 1000eb68

undefined * Catch_1000eb68(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000eb72;
}



// Function: FUN_1000eb77 at 1000eb77

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000eb77(void)

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



// Function: FUN_1000eb8e at 1000eb8e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000eb8e(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000e55f(puVar1);
    }
    uVar2 = FUN_1000ebe9();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000ebda at 1000ebda

undefined * Catch_1000ebda(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ebe4;
}



// Function: FUN_1000ebe9 at 1000ebe9

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000ebe9(void)

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



// Function: FUN_1000ec00 at 1000ec00

void __fastcall FUN_1000ec00(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  int *piVar5;
  code *pcVar6;
  tagPOINT local_a4;
  LONG local_9c;
  int local_98;
  tagPOINT local_94;
  tagPOINT local_8c;
  tagPOINT local_84;
  LONG local_7c;
  LONG local_78;
  HDWP local_74;
  undefined4 *local_70;
  int *local_6c;
  tagRECT local_68;
  tagRECT local_58;
  tagRECT local_48;
  tagRECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_100256e0 ^ (uint)&stack0xfffffffc;
  local_38.left = 0;
  local_38.top = 0;
  local_38.right = 0;
  local_38.bottom = 0;
  local_70 = param_1;
  GetClientRect((HWND)*param_1,&local_38);
  piVar5 = *(int **)param_1[0x17];
  local_6c = piVar5;
  local_74 = BeginDeferWindowPos(param_1[0x18]);
  if (piVar5 != (int *)param_1[0x17]) {
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
          local_84.x = local_28.right;
          local_84.y = local_28.top;
          local_94.x = local_28.left;
          local_94.y = local_28.bottom;
          ScreenToClient((HWND)*puVar1,&local_84);
          ScreenToClient((HWND)*puVar1,&local_94);
          local_28.right = local_84.x;
          local_28.top = local_84.y;
          local_28.left = local_94.x;
          local_28.bottom = local_94.y;
          local_68.left = 0;
          local_68.top = 0;
          local_68.right = 0;
          local_68.bottom = 0;
          GetWindowRect((HWND)*param_1,&local_68);
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
            local_8c.x = local_58.left;
            local_8c.y = local_58.top;
            local_a4.x = local_58.right;
            local_a4.y = local_58.bottom;
            ScreenToClient((HWND)*param_1,&local_8c);
            ScreenToClient((HWND)*param_1,&local_a4);
            local_18.left = puVar1[5];
            local_58.left = local_8c.x;
            local_58.top = local_8c.y;
            local_58.right = local_a4.x;
            local_58.bottom = local_a4.y;
            local_18.top = local_a4.y + 2;
            param_1 = local_70;
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
            local_9c = local_48.left;
            local_98 = local_48.top;
            local_7c = local_48.right;
            local_78 = local_48.bottom;
            (*pcVar6)(*param_1,&local_9c);
            (*pcVar6)(*param_1,&local_7c);
            local_18.right = puVar1[9];
            local_48.left = local_9c;
            local_48.top = local_98;
            local_48.right = local_7c;
            local_48.bottom = local_78;
            local_18.bottom = local_98 + -2;
            param_1 = local_70;
          }
          BVar4 = EqualRect(&local_18,&local_28);
          if (BVar4 == 0) {
            iVar2 = puVar1[1];
            if (iVar2 != 0) {
              MoveWindow((HWND)*puVar1,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar1,&local_18,1);
              UpdateWindow((HWND)*param_1);
            }
            iVar3 = puVar1[2];
            if (iVar3 != 0) {
              MoveWindow((HWND)*puVar1,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar1,&local_18,1);
              UpdateWindow((HWND)*param_1);
            }
            if (iVar3 == 0 && iVar2 == 0) {
              DeferWindowPos(local_74,(HWND)*puVar1,(HWND)0x0,local_18.left,local_18.top,
                             local_18.right - local_18.left,local_18.bottom - local_18.top,0x14);
            }
          }
        }
      }
      piVar5 = (int *)*local_6c;
      local_6c = piVar5;
    } while (piVar5 != (int *)param_1[0x17]);
  }
  EndDeferWindowPos(local_74);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ef77 at 1000ef77

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000ef77(void *this,undefined4 *param_1,undefined4 *param_2)

{
  basic_string<>(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  return this;
}



// Function: FUN_1000efaa at 1000efaa

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000efaa(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_1000a31d();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_1000a31d();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_1000f084();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_1000b068(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10001319(&local_42c);
  FUN_1001280a();
  return;
}



// Function: Catch@1000f06f at 1000f06f

undefined * Catch_1000f06f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000f07c;
}



// Function: FUN_1000f084 at 1000f084

void FUN_1000f084(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000a31d();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_1000e65b((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_1000b068((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001319((int *)(unaff_EBP + -0x428));
  FUN_1001280a();
  return;
}



// Function: FUN_1000f10e at 1000f10e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000f10e(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000efaa(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001319(local_14);
  return uVar1;
}



// Function: FUN_1000f14f at 1000f14f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000f14f(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001319(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000efaa(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001319(local_14);
  }
  return uVar1;
}



// Function: FUN_1000f1ab at 1000f1ab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000f1ab(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000efaa(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001319(local_14);
  return uVar1;
}



// Function: FUN_1000f1eb at 1000f1eb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000f1eb(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001319(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000efaa(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001319(local_14);
  }
  return uVar1;
}



// Function: DllRegisterServer at 1000f246

void DllRegisterServer(void)

{
                    /* 0xf246  3  DllRegisterServer */
  FUN_1000e7a0(&DAT_1002664c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 1000f255

void DllUnregisterServer(void)

{
                    /* 0xf255  4  DllUnregisterServer */
  FUN_1000e80f(&DAT_1002664c,1,(void *)0x0);
  return;
}



// Function: FUN_1000f264 at 1000f264

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000f264(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_1000cca6(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_100268d8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_100268d8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000a31d();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001319((int *)&local_a48);
        goto LAB_1000f2e6;
      }
      FUN_1000a401(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_1000a2aa(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001319((int *)&local_a48);
          goto LAB_1000f2e6;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000cca6(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000cca6(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_1000f1eb(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_1000f14f(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001319((int *)&local_a48);
  }
LAB_1000f2e6:
  local_8 = 0xffffffff;
  FUN_1000bd42(&local_a60);
  FUN_100127fb();
  return;
}



// Function: FUN_1000f467 at 1000f467

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000f467(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_1000cca6(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_100268d8;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_100268d8,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000a31d();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001319((int *)&local_a48);
        goto LAB_1000f4e0;
      }
      FUN_1000a401(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_1000a2aa(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001319((int *)&local_a48);
          goto LAB_1000f4e0;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000cca6(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000cca6(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_1000f1ab(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_1000f10e(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001319((int *)&local_a48);
  }
LAB_1000f4e0:
  local_8 = 0xffffffff;
  FUN_1000bd42(&local_a5c);
  FUN_100127fb();
  return;
}



// Function: FUN_1000f65e at 1000f65e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000f65e(void *this,wchar_t ****param_1,void *param_2)

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
      (FUN_10001da0(param_2,local_50,0,0xffffffff), iVar2 == 0)) && (local_20 != (undefined4 *)0x0))
  {
    local_38 = 7;
    local_3c = 0;
    local_4c[0]._0_2_ = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10001da0(local_4c,local_50,0,0xffffffff);
    puVar1 = local_20;
    local_50 = (wchar_t ******)0x5f;
    uVar3 = FUN_1000ad04(local_4c,(ushort *)&local_50,0xffffffff,1);
    local_50 = (wchar_t ******)0x2e;
    uVar4 = FUN_1000ad04(local_4c,(ushort *)&local_50,0xffffffff,1);
    if ((uVar3 != 0xffffffff) && ((undefined4 *)((uVar4 - uVar3) + -1) == local_20)) {
      local_50 = local_30[0];
      if (local_1c < 8) {
        local_50 = (wchar_t ******)local_30;
      }
      puVar5 = (undefined4 *)wcslen((wchar_t *)local_50);
      FUN_1000dd62(local_4c,uVar3 + 1,puVar1,local_50,puVar5);
    }
    FUN_10001da0(param_2,local_4c,0,0xffffffff);
    local_8 = local_8 & 0xffffff00;
    FID_conflict__Tidy(local_4c,'\x01',0);
  }
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_1000f79b at 1000f79b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000f79b(void *param_1)

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
  FUN_10001f54(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\cs\\");
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"Locale");
  FUN_1000dcc0(local_238,(undefined4 *)L"Locale",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = Open(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
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
  ATL::CRegKey::Close((CRegKey *)&local_248);
  FUN_100127fb();
  return;
}



// Function: FUN_1000f8c6 at 1000f8c6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000f8c6(void *param_1)

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
  FUN_10001f54(local_254,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10001f54(local_238,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000dc1b(local_238,local_254,0,0xffffffff);
  sVar1 = wcslen(L"\\AddIns\\");
  FUN_1000dcc0(local_238,(undefined4 *)L"\\AddIns\\",sVar1);
  sVar1 = wcslen(L"{E9573A65-8CF6-429B-B83F-A33278495583}");
  FUN_1000dcc0(local_238,(undefined4 *)L"{E9573A65-8CF6-429B-B83F-A33278495583}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = Open(&local_264,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
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
  ATL::CRegKey::Close((CRegKey *)&local_264);
  FUN_100127fb();
  return;
}



// Function: FUN_1000fa42 at 1000fa42

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000fa42(int *param_1)

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
    FID_conflict_assign(local_30,(undefined4 *)&DAT_10018880,sVar2);
  }
  uVar4 = 0;
  if (PTR_DAT_10024950 != (undefined *)0x0) {
    ppuVar3 = &PTR_DAT_10024950;
    do {
      iVar1 = FUN_1000bbc1(local_30,(wchar_t *)*ppuVar3);
      if (iVar1 == 0) break;
      uVar4 = uVar4 + 1;
      ppuVar3 = &PTR_DAT_10024950 + (uVar4 & 0xffff);
    } while (*ppuVar3 != (undefined *)0x0);
  }
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_1000fad7 at 1000fad7

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000fad7(void *param_1)

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
  FUN_10001f54(local_254,L"Administrator");
  local_8._0_1_ = 1;
  FUN_10001f54(local_238,L"software\\cummins\\intelect\\insite\\6.0\\users\\");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000dc1b(local_238,local_254,0,0xffffffff);
  sVar1 = wcslen(L"\\AddIns\\");
  FUN_1000dcc0(local_238,(undefined4 *)L"\\AddIns\\",sVar1);
  sVar1 = wcslen(L"{E9573A65-8CF6-429B-B83F-A33278495583}");
  FUN_1000dcc0(local_238,(undefined4 *)L"{E9573A65-8CF6-429B-B83F-A33278495583}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = Open(&local_264,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
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
  ATL::CRegKey::Close((CRegKey *)&local_264);
  FUN_100127fb();
  return;
}



// Function: FUN_1000fc53 at 1000fc53

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000fc53(void *this,int *param_1)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 **ppuVar3;
  int iVar4;
  int iVar5;
  undefined4 local_1c;
  int *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  iVar4 = 0;
  local_18 = (int *)0x0;
  local_8 = 1;
  local_1c = (**(code **)*param_1)(param_1,&DAT_1001a610,&local_18);
  piVar1 = (int *)FUN_100023a4();
  if (*piVar1 != 0) {
    iVar5 = 0;
    do {
      puVar2 = FUN_100023a4();
      piVar1 = local_18;
      if (*(int *)(puVar2 + iVar5) == 0) {
        local_14 = 0;
      }
      else {
        local_14 = Ordinal_2(*(int *)(puVar2 + iVar5));
        if (local_14 == 0) goto LAB_1000fd59;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      ppuVar3 = FUN_10006498();
      if (ppuVar3 == (undefined4 **)0x0) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = (int *)Ordinal_2(ppuVar3);
        if (param_1 == (int *)0x0) {
LAB_1000fd59:
                    /* WARNING: Subroutine does not return */
          FUN_1000108d(0x8007000e);
        }
      }
      local_8._0_1_ = 3;
      local_1c = (**(code **)(*piVar1 + 0x28))(piVar1,param_1,local_14);
      local_8._0_1_ = 2;
      Ordinal_6(param_1);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(local_14);
      iVar4 = iVar4 + 1;
      iVar5 = iVar4 * 4;
      puVar2 = FUN_100023a4();
    } while (*(int *)(puVar2 + iVar5) != 0);
  }
  param_1 = (int *)**(int **)((int)this + 8);
  if (param_1 != *(int **)((int)this + 8)) {
    do {
      (**(code **)(*(int *)param_1[10] + 8))((int *)param_1[10]);
      FUN_100034e4((int *)&param_1);
    } while (param_1 != *(int **)((int)this + 8));
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return local_1c;
}



// Function: FUN_1000fd64 at 1000fd64

undefined4
FUN_1000fd64(int *param_1,ushort param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_8;
  
  piVar2 = param_1;
  if ((param_2 < 2) ||
     (((3 < param_2 && (param_2 != 0x10)) &&
      ((param_2 < 0x12 || ((0x15 < param_2 && (param_2 != 0x17)))))))) {
    uVar3 = 0x80070057;
  }
  else {
    local_8 = 0;
    (**(code **)(*param_1 + 0x20))(param_1,&local_8);
    iVar4 = param_4 + -1;
    FUN_1000eb8e(&param_1);
    iVar1 = piVar2[2];
    param_1[2] = iVar4;
    param_1[3] = iVar1;
    uVar3 = (**(code **)*param_1)(param_1,&DAT_1001a8ac,param_6);
  }
  return uVar3;
}



// Function: FUN_1000fdd0 at 1000fdd0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000fdd0(int param_1)

{
  FUN_100019f2((undefined4 *)(param_1 + 0x3c));
  FUN_10001c44(param_1 + 0xc);
  FUN_10001333((LPCRITICAL_SECTION)(param_1 + 0x74));
  return;
}



// Function: FUN_1000fe18 at 1000fe18

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000fe18(int param_1)

{
  FUN_1000fdd0(param_1);
  return;
}



// Function: FUN_1000fe36 at 1000fe36

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000fe36(void *this,undefined4 param_1)

{
  FUN_10001f07((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 0x18) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 0x20) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 0x2c) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 0x34) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined ***)((int)this + 0x3c) = ATL::CComContainedObject<class_COpenLoopLockHelper>::vftable;
  *(undefined4 *)((int)this + 0x70) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000fea2 at 1000fea2

undefined4 FUN_1000fea2(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}



// Function: FUN_1000feb4 at 1000feb4

undefined2 __fastcall FUN_1000feb4(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x18))();
  return *(undefined2 *)(&DAT_10019f18 + (uVar1 & 0xffff) * 2);
}



// Function: FUN_1000fec5 at 1000fec5

undefined4 FUN_1000fec5(void)

{
  return DAT_100268dc;
}



// Function: FUN_1000fecb at 1000fecb

void FUN_1000fecb(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 4))(*(int **)(param_1 + 0x70));
  return;
}



// Function: FUN_1000fede at 1000fede

void FUN_1000fede(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 8))(*(int **)(param_1 + 0x70));
  return;
}



// Function: FUN_1000fef1 at 1000fef1

void FUN_1000fef1(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x70))(*(undefined4 **)(param_1 + 0x70),param_2,param_3);
  return;
}



// Function: FUN_1000ff09 at 1000ff09

undefined4 __fastcall FUN_1000ff09(int param_1)

{
  return *(undefined4 *)(param_1 + 0x70);
}



// Function: FUN_1000ff0d at 1000ff0d

void FUN_1000ff0d(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fef1(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000ff17 at 1000ff17

void FUN_1000ff17(void)

{
  FUN_10001221();
  return;
}



// Function: FUN_1000ff21 at 1000ff21

void FUN_1000ff21(int param_1,undefined4 *param_2)

{
  FUN_10001c72(param_1 + -0x14,param_2);
  return;
}



// Function: FUN_1000ff2b at 1000ff2b

void FUN_1000ff2b(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fef1(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000ff35 at 1000ff35

void __thiscall FUN_1000ff35(void *this,byte param_1)

{
  FUN_10010a00((void *)((int)this + -0x3c),param_1);
  return;
}



// Function: FUN_1000ff3d at 1000ff3d

void FUN_1000ff3d(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fef1(param_1 + -0x2c,param_2,param_3);
  return;
}



// Function: FUN_1000ff47 at 1000ff47

void FUN_1000ff47(int param_1)

{
  FUN_1000fede(param_1 + -0x20);
  return;
}



// Function: FUN_1000ff51 at 1000ff51

void FUN_1000ff51(int param_1)

{
  FUN_1000fecb(param_1 + -0x18);
  return;
}



// Function: FUN_1000ff5b at 1000ff5b

void FUN_1000ff5b(int param_1)

{
  FUN_1000fede(param_1 + -4);
  return;
}



// Function: FUN_1000ff65 at 1000ff65

void FUN_1000ff65(void)

{
  FUN_10001226();
  return;
}



// Function: FUN_1000ff6f at 1000ff6f

void FUN_1000ff6f(int param_1)

{
  FUN_1000fede(param_1 + -8);
  return;
}



// Function: FUN_1000ff79 at 1000ff79

void FUN_1000ff79(void)

{
  FUN_10001221();
  return;
}



// Function: FUN_1000ff83 at 1000ff83

void FUN_1000ff83(int param_1)

{
  FUN_1000fecb(param_1 + -0x20);
  return;
}



// Function: FUN_1000ff8d at 1000ff8d

void FUN_1000ff8d(int param_1,undefined4 *param_2)

{
  FUN_10001c72(param_1 + -0x20,param_2);
  return;
}



// Function: FUN_1000ff97 at 1000ff97

void FUN_1000ff97(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fef1(param_1 + -0x18,param_2,param_3);
  return;
}



// Function: FUN_1000ffa1 at 1000ffa1

void FUN_1000ffa1(int param_1)

{
  FUN_1000fede(param_1 + -0xc);
  return;
}



// Function: FUN_1000ffab at 1000ffab

void FUN_1000ffab(int param_1)

{
  FUN_1000fecb(param_1 + -4);
  return;
}



// Function: FUN_1000ffb5 at 1000ffb5

void FUN_1000ffb5(int param_1)

{
  FUN_1000fede(param_1 + -0x2c);
  return;
}



// Function: FUN_1000ffbf at 1000ffbf

void FUN_1000ffbf(int param_1,undefined4 *param_2)

{
  FUN_100017fd(param_1 + -0x14,param_2);
  return;
}



// Function: FUN_1000ffc9 at 1000ffc9

void FUN_1000ffc9(int param_1)

{
  FUN_1000fecb(param_1 + -8);
  return;
}



// Function: FUN_1000ffd3 at 1000ffd3

void FUN_1000ffd3(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fef1(param_1 + -0x20,param_2,param_3);
  return;
}



// Function: FUN_1000ffdd at 1000ffdd

void FUN_1000ffdd(int param_1)

{
  FUN_1000fecb(param_1 + -0xc);
  return;
}



// Function: FUN_1000ffe7 at 1000ffe7

void FUN_1000ffe7(int param_1)

{
  FUN_1000fecb(param_1 + -0x2c);
  return;
}



// Function: FUN_1000fff1 at 1000fff1

void FUN_1000fff1(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1000fef1(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000fffb at 1000fffb

void FUN_1000fffb(void)

{
  FUN_10001226();
  return;
}



// Function: FUN_10010005 at 10010005

void FUN_10010005(int param_1)

{
  FUN_1000fede(param_1 + -0x18);
  return;
}



// Function: FUN_1001000f at 1001000f

void FUN_1001000f(int param_1,undefined4 *param_2)

{
  FUN_100017fd(param_1 + -0x20,param_2);
  return;
}



// Function: FUN_10010019 at 10010019

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10010019(void *this,LPCWSTR param_1)

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
  iVar2 = Open(&local_434,(HKEY)0x80000002,(LPCWSTR)ppWVar1,0x2001f);
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
  ATL::CRegKey::Close((CRegKey *)&local_434);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(&param_1,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_1001014a at 1001014a

undefined4 FUN_1001014a(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_1000e87e(&PTR_DAT_1002559c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1001016e at 1001016e

void FUN_1001016e(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_1000e8be(&PTR_DAT_1002559c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1001018e at 1001018e

void FUN_1001018e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_1000e95f(&PTR_DAT_1002559c,param_1 + -4,param_2,param_3,param_4,param_5,param_6,param_7,
               param_8,param_9);
  return;
}



// Function: FUN_100101be at 100101be

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100101be(LPCWSTR param_1)

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
  iVar2 = Open(&local_22c,(HKEY)0x80000002,(LPCWSTR)ppWVar1,0x2001f);
  if (iVar2 == 0) {
    lVar3 = ATL::CRegKey::QueryStringValue
                      ((CRegKey *)&local_22c,L"ResourceDLL",&local_21c,&local_220);
    if ((lVar3 == 0) && (local_220 != 0)) {
      sVar4 = wcslen(&local_21c);
      FID_conflict_assign(in_stack_00000020,(undefined4 *)&local_21c,sVar4);
    }
  }
  local_8 = local_8 & 0xffffff00;
  ATL::CRegKey::Close((CRegKey *)&local_22c);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(&param_1,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_100102ab at 100102ab

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_100102ab(int *param_1)

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
        FID_conflict_assign(local_4c,(undefined4 *)&DAT_10018880,sVar2);
      }
      FUN_10001f54(local_68,L"_");
      local_8._0_1_ = 5;
      _Str = (wchar_t ****)local_4c[0];
      if (local_38 < 8) {
        _Str = local_4c;
      }
      sVar2 = wcslen((wchar_t *)_Str);
      FUN_1000dcc0(local_68,_Str,sVar2);
      sVar2 = wcslen(L".");
      FUN_1000dcc0(local_68,(undefined4 *)&DAT_10019254,sVar2);
      FUN_10001f54(local_84,L"_EN.");
      local_8._0_1_ = 6;
      (**(code **)(*param_1 + 0x38))();
      local_8._0_1_ = 5;
      pppWStack_110 = (LPCWSTR **)0x1001043d;
      FID_conflict__Tidy(local_84,'\x01',0);
      FUN_10001f54(local_84,L"_en.");
      local_8._0_1_ = 7;
      pppWStack_110 = (LPCWSTR **)local_30;
      uStack_114 = 0x10010461;
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
        goto LAB_100104c6;
      }
    }
  }
  (**(code **)(*param_1 + 0x20))();
  param_1[1] = 1;
LAB_100104c6:
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
  FUN_100127fb();
  return;
}



// Function: FUN_10010572 at 10010572

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10010572(void *param_1)

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
  FUN_10001f54(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"{E9573A65-8CF6-429B-B83F-A33278495583}");
  FUN_1000dcc0(local_238,(undefined4 *)L"{E9573A65-8CF6-429B-B83F-A33278495583}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = Open(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
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
  ATL::CRegKey::Close((CRegKey *)&local_248);
  FUN_100127fb();
  return;
}



// Function: FUN_1001069d at 1001069d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1001069d(void *this,wchar_t *param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x100106a9;
  puVar1 = FUN_10001f54(local_30,param_1);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 8))(puVar1,param_2);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_100106e3 at 100106e3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100106e3(void *this,undefined4 param_1)

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
  FUN_10001f54(local_440,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"{E9573A65-8CF6-429B-B83F-A33278495583}");
  FUN_1000dcc0(local_440,(undefined4 *)L"{E9573A65-8CF6-429B-B83F-A33278495583}",sVar1);
  if (local_42c < 8) {
    local_440[0] = (LPCWSTR *)local_440;
  }
  iVar2 = Open(&local_450,(HKEY)0x80000002,(LPCWSTR)local_440[0],0x2001f);
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
  ATL::CRegKey::Close((CRegKey *)&local_450);
  FUN_100127fb();
  return;
}



// Function: FUN_1001084f at 1001084f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1001084f(void *param_1)

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
  FUN_10001f54(local_238,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\")
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  sVar1 = wcslen(L"{E9573A65-8CF6-429B-B83F-A33278495583}");
  FUN_1000dcc0(local_238,(undefined4 *)L"{E9573A65-8CF6-429B-B83F-A33278495583}",sVar1);
  if (local_224 < 8) {
    local_238[0] = (LPCWSTR *)local_238;
  }
  iVar2 = Open(&local_248,(HKEY)0x80000002,(LPCWSTR)local_238[0],0x2001f);
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
  ATL::CRegKey::Close((CRegKey *)&local_248);
  FUN_100127fb();
  return;
}



// Function: FUN_1001097a at 1001097a

void FUN_1001097a(void *param_1,wchar_t *param_2,wchar_t *param_3)

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
  for (uVar4 = FUN_1000b8ca(param_1,(ushort *)param_2,0,sVar3); uVar4 != 0xffffffff;
      uVar4 = FUN_1000b8ca(param_1,(ushort *)param_2,iVar1 + uVar4,sVar3)) {
    pwVar5 = param_3;
    if (7 < *(uint *)(param_3 + 10)) {
      pwVar5 = *(wchar_t **)param_3;
    }
    FUN_1000eaf6(param_1,uVar4,*(undefined4 **)(pwVar2 + 8),pwVar5);
    iVar1 = *(int *)(param_3 + 8);
    param_2 = pwVar2;
    if (7 < *(uint *)(pwVar2 + 10)) {
      param_2 = *(wchar_t **)pwVar2;
    }
    sVar3 = wcslen(param_2);
  }
  return;
}



// Function: FUN_10010a00 at 10010a00

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10010a00(void *this,byte param_1)

{
  FUN_1000fdd0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10010a31 at 10010a31

undefined4 __thiscall FUN_10010a31(void *this,undefined4 param_1,int param_2)

{
  if ((param_2 != 4) && (param_2 != 3)) {
    if (*(int *)((int)this + 0x18) != 0) {
      FUN_1000b1ae((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
      InvalidateRect(*this,(RECT *)((int)this + 0x44),1);
      *(undefined4 *)((int)this + 0x20) = 1;
    }
    FUN_1000ec00((undefined4 *)this);
    FUN_1000ec00((undefined4 *)this);
  }
  return 0;
}



// Function: FUN_10010a78 at 10010a78

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10010a78(void *this,undefined4 *param_1)

{
  FUN_1000ef77(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_10010aa6 at 10010aa6

void FUN_10010aa6(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_1000f264(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10010aaf at 10010aaf

void FUN_10010aaf(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_1000f467(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10010ab8 at 10010ab8

undefined4 __thiscall
FUN_10010ab8(void *this,undefined4 param_1,int param_2,int param_3,int param_4,uint *param_5,
            int param_6)

{
  int iVar1;
  uint uVar2;
  int local_8;
  
  local_8 = 1;
  if (param_6 == 0) {
    iVar1 = FUN_1000b81d(param_1,param_2,param_3,param_4,param_5,0);
    if (iVar1 != 0) {
      return 1;
    }
    if (param_2 == 5) {
      local_8 = 1;
      uVar2 = FUN_10010a31((void *)((int)this + 0xe8),5,param_3);
    }
    else if (param_2 == 0x24) {
      local_8 = 1;
      uVar2 = FUN_1000afdd((void *)((int)this + 0xe8),0x24,param_3,param_4);
    }
    else if (param_2 == 0x110) {
      local_8 = 1;
      uVar2 = FUN_10008cd4(this);
    }
    else {
      if (param_2 != 0x53) {
        return 0;
      }
      local_8 = 1;
      uVar2 = (**(code **)(*(int *)((int)this + 0xb0) + 4))(0x53,param_3,param_4,&local_8);
    }
    *param_5 = uVar2;
    if (local_8 != 0) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10010b82 at 10010b82

void FUN_10010b82(int param_1)

{
  FUN_1000f467((int *)&DAT_1002664c,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10010b9a at 10010b9a

void FUN_10010b9a(int param_1)

{
  FUN_1000f467((int *)&DAT_1002664c,0x6a,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10010bb2 at 10010bb2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_10010bb2(int *param_1)

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
LAB_10010e40:
    (**(code **)(*param_1 + 0x20))(local_a8);
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x28))(local_30);
    ppppppWVar3 = (LPCWSTR *****)local_30[0];
    if (local_1c < 8) {
      ppppppWVar3 = local_30;
    }
    local_a8 = LoadLibraryW((LPCWSTR)ppppppWVar3);
    if ((iVar1 == 0) && (local_a8 != (HMODULE)0x0)) goto LAB_10010e40;
    iVar1 = (**(code **)(*param_1 + 0x14))(local_4c);
    if (((iVar1 != 0) || (local_a4 = 0, local_3c == 0)) &&
       ((local_a4 = (**(code **)(*param_1 + 0x10))(local_4c), local_a4 != 0 || (local_3c == 0)))) {
      sVar2 = wcslen(L"EN");
      FID_conflict_assign(local_4c,(undefined4 *)&DAT_10018880,sVar2);
    }
    FUN_10001f54(local_68,L"_");
    local_8._0_1_ = 3;
    _Str = (wchar_t ******)local_4c[0];
    if (local_38 < 8) {
      _Str = local_4c;
    }
    sVar2 = wcslen((wchar_t *)_Str);
    FUN_1000dcc0(local_68,_Str,sVar2);
    sVar2 = wcslen(L".");
    FUN_1000dcc0(local_68,(undefined4 *)&DAT_10019254,sVar2);
    FUN_10001f54(local_a0,L"_EN.");
    local_8._0_1_ = 4;
    (**(code **)(*param_1 + 0x38))(local_30,local_a0,local_68);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_a0,'\x01',0);
    FUN_10001f54(local_a0,L"_en.");
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
      FUN_10001da0(local_30,local_84,0,0xffffffff);
      sVar2 = wcslen(L"Res_");
      FUN_1000dcc0(local_30,(undefined4 *)L"Res_",sVar2);
      FUN_1000dc1b(local_30,local_4c,0,0xffffffff);
      sVar2 = wcslen(L".dll");
      FUN_1000dcc0(local_30,(undefined4 *)L".dll",sVar2);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FID_conflict__Tidy(local_68,'\x01',0);
    if (local_a8 != (HMODULE)0x0) goto LAB_10010e40;
    ppppppWVar3 = (LPCWSTR *****)local_30[0];
    if (local_1c < 8) {
      ppppppWVar3 = local_30;
    }
    pHVar4 = LoadLibraryW((LPCWSTR)ppppppWVar3);
    if (pHVar4 == (HMODULE)0x0) {
      GetLastError();
      goto LAB_10010e50;
    }
    (**(code **)(*param_1 + 0x20))(pHVar4);
  }
  param_1[1] = 1;
LAB_10010e50:
  local_8._0_1_ = 1;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8 = (uint)local_8._1_3_ << 8;
  FID_conflict__Tidy(local_84,'\x01',0);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_10010e9a at 10010e9a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10010e9a(undefined4 *param_1)

{
  FUN_10001f07((int)param_1);
  *param_1 = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[1] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[2] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[3] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[6] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[8] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[0xb] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[0xd] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[0xf] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  (**(code **)(*DAT_100256fc + 4))();
  return param_1;
}



// Function: FUN_10010f0b at 10010f0b

void FUN_10010f0b(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x70));
  return;
}



// Function: FUN_10010f1f at 10010f1f

LONG FUN_10010f1f(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x70));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (*(code *)**(undefined4 **)(param_1 + 0x3c))(1);
  }
  return LVar1;
}



// Function: FUN_10010f4c at 10010f4c

void __thiscall FUN_10010f4c(void *this,byte param_1)

{
  FUN_100111b2((void *)((int)this + -0x3c),param_1);
  return;
}



// Function: FUN_10010f54 at 10010f54

void FUN_10010f54(int param_1)

{
  FUN_10010f1f(param_1 + -0x20);
  return;
}



// Function: FUN_10010f5e at 10010f5e

void FUN_10010f5e(int param_1)

{
  FUN_10010f0b(param_1 + -0x18);
  return;
}



// Function: FUN_10010f68 at 10010f68

void FUN_10010f68(int param_1)

{
  FUN_10010f1f(param_1 + -4);
  return;
}



// Function: FUN_10010f72 at 10010f72

void FUN_10010f72(int param_1)

{
  FUN_10010f1f(param_1 + -8);
  return;
}



// Function: FUN_10010f7c at 10010f7c

void FUN_10010f7c(int param_1)

{
  FUN_10010f0b(param_1 + -0x20);
  return;
}



// Function: FUN_10010f86 at 10010f86

void FUN_10010f86(int param_1)

{
  FUN_10010f1f(param_1 + -0xc);
  return;
}



// Function: FUN_10010f90 at 10010f90

void FUN_10010f90(int param_1)

{
  FUN_10010f0b(param_1 + -4);
  return;
}



// Function: FUN_10010f9a at 10010f9a

void FUN_10010f9a(int param_1)

{
  FUN_10010f1f(param_1 + -0x2c);
  return;
}



// Function: FUN_10010fa4 at 10010fa4

void FUN_10010fa4(int param_1)

{
  FUN_10010f0b(param_1 + -8);
  return;
}



// Function: FUN_10010fae at 10010fae

void FUN_10010fae(int param_1)

{
  FUN_10010f0b(param_1 + -0xc);
  return;
}



// Function: FUN_10010fb8 at 10010fb8

void FUN_10010fb8(int param_1)

{
  FUN_10010f0b(param_1 + -0x2c);
  return;
}



// Function: FUN_10010fc2 at 10010fc2

void FUN_10010fc2(int param_1)

{
  FUN_10010f1f(param_1 + -0x18);
  return;
}



// Function: FUN_10010fcc at 10010fcc

int __fastcall FUN_10010fcc(int param_1)

{
  return param_1 + 4;
}



// Function: QueryInterface at 10010fd0

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001adb8,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10010fea at 10010fea

void FUN_10010fea(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x18),param_2);
  return;
}



// Function: FUN_10010ff4 at 10010ff4

void FUN_10010ff4(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x20),param_2);
  return;
}



// Function: FUN_10010ffe at 10010ffe

void FUN_10010ffe(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10011008 at 10011008

void FUN_10011008(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_10011012 at 10011012

void FUN_10011012(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_1001101c at 1001101c

void FUN_1001101c(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x2c),param_2);
  return;
}



// Function: FUN_10011026 at 10011026

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10011026(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[1] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[2] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[3] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[6] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[8] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[0xb] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[0xd] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[0xf] = ATL::CComObject<class_COpenLoopLockHelper>::vftable;
  param_1[0x1c] = 0xc0000001;
  (**(code **)(*DAT_100256fc + 8))();
  FUN_1000fdd0((int)param_1);
  return;
}



// Function: FUN_1001109c at 1001109c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1001109c(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_COpenLoopLockHelper>::vftable;
  FUN_1000fe36((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_100256fc + 4))();
  return (undefined4 *)this;
}



// Function: FUN_100110df at 100110df

void FUN_100110df(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: Release at 100110f3

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



// Function: FUN_10011120 at 10011120

long FUN_10011120(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001adb8,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_1001116c at 1001116c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1001116c(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_COpenLoopLockHelper>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_100256fc + 8))();
  FUN_1000fdd0((int)(param_1 + 3));
  return;
}



// Function: FUN_100111b2 at 100111b2

undefined4 * __thiscall FUN_100111b2(void *this,byte param_1)

{
  FUN_10011026((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100111d1 at 100111d1

undefined4 * __thiscall FUN_100111d1(void *this,byte param_1)

{
  FUN_1001116c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100111f0 at 100111f0

void __thiscall
FUN_100111f0(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x7fffffd < uVar3) {
    this = (void *)((int)this + 0xd);
    FUN_10006a80(this,param_4 + 3);
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
    if (*(char *)(iVar4 + 0x2c) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x2c) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x2c) == '\0') {
LAB_100112bf:
        *(undefined1 *)(piVar1 + 0xb) = 1;
        *(undefined1 *)(iVar4 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_1000351f(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        FUN_10003564(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x2c) == '\0') goto LAB_100112bf;
      if (piVar5 == (int *)*piVar1) {
        FUN_10003564(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      FUN_1000351f(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_10011328 at 10011328

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10011328(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_100158f9;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10010a78(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10011356 at 10011356

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10011356(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x90);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10010e9a(puVar1);
    }
    iVar2 = FUN_100113bd();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@100113ad at 100113ad

undefined * Catch_100113ad(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100113b7;
}



// Function: FUN_100113bd at 100113bd

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100113bd(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    lpAddend = unaff_ESI + 0x1c;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_1000aad5((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)unaff_ESI[0xf])(1);
  }
  return unaff_EBX;
}



// Function: FUN_10011409 at 10011409

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10011409(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x9c);
    if (this != (void *)0x0) {
      FUN_1001109c(this,param_1);
    }
    iVar1 = FUN_1001147a();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@1001146a at 1001146a

undefined * Catch_1001146a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10011474;
}



// Function: FUN_1001147a at 1001147a

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1001147a(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_1000aad5((int)(unaff_ESI + 0x1f));
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



// Function: FUN_100114bc at 100114bc

void __thiscall FUN_100114bc(void *this,int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  ushort *this_00;
  undefined4 *puVar3;
  undefined4 *local_c;
  bool local_8;
  
  this_00 = (ushort *)(param_2 + 3);
  local_8 = true;
  puVar3 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  local_c = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)puVar3 + 0x2d) == '\0') {
    if ((char)param_3 == '\0') {
      iVar2 = FUN_10003aea(this_00,(ushort *)(puVar3 + 3));
      local_8 = iVar2 < 0;
    }
    else {
      iVar2 = FUN_10003aea(puVar3 + 3,this_00);
      local_8 = -1 < iVar2;
    }
    local_c = puVar3;
    if (local_8 == false) {
      puVar3 = (undefined4 *)puVar3[2];
    }
    else {
      puVar3 = (undefined4 *)*puVar3;
    }
  }
  param_3 = local_c;
  if (local_8 != false) {
    if (local_c == (undefined4 *)**(int **)((int)this + 4)) {
      local_8 = true;
      goto LAB_10011532;
    }
    FUN_1000b168((int *)&param_3);
  }
  puVar3 = param_3;
  iVar2 = FUN_10003aea(param_3 + 3,this_00);
  if (-1 < iVar2) {
    FUN_10006a80((int)this + 0xd,this_00);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10011532:
  piVar1 = (int *)FUN_100111f0(this,&param_3,local_8,local_c,param_2);
  *param_1 = *piVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_10011592 at 10011592

void __cdecl FUN_10011592(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10011328(param_2,param_3);
  return;
}



// Function: FUN_100115a5 at 100115a5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100115a5(void *this,undefined4 *param_1,undefined4 *param_2)

{
  basic_string<>(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  return this;
}



// Function: FUN_100115d8 at 100115d8

void FUN_100115d8(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10011356(0,param_2,param_3);
    return;
  }
  FUN_10011409(param_1,param_2,param_3);
  return;
}



// Function: FUN_100115f8 at 100115f8

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_100115f8(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  ushort *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  char cVar5;
  int *piVar6;
  void *local_c;
  void *pvStack_8;
  
  piVar2 = param_4;
  this = (ushort *)(param_4 + 3);
  local_c = param_1;
  pvStack_8 = param_1;
  if (*(int *)((int)param_1 + 8) == 0) {
    piVar6 = *(int **)((int)param_1 + 4);
  }
  else {
    piVar1 = *(int **)((int)param_1 + 4);
    if (param_3 == (int *)*piVar1) {
      iVar3 = FUN_10003aea(this,(ushort *)(param_3 + 3));
      if (-1 < iVar3) goto LAB_10011708;
      cVar5 = '\x01';
      goto LAB_10011614;
    }
    if (param_3 == piVar1) {
      iVar3 = FUN_10003aea((void *)(piVar1[2] + 0xc),this);
      if (-1 < iVar3) goto LAB_10011708;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_10011614;
    }
    iVar3 = FUN_10003aea(this,(ushort *)(param_3 + 3));
    if (iVar3 < 0) {
      param_4 = param_3;
      FUN_1000b168((int *)&param_4);
      piVar1 = param_4;
      iVar3 = FUN_10003aea(param_4 + 3,this);
      if (-1 < iVar3) goto LAB_100116b7;
      cVar5 = *(char *)(piVar1[2] + 0x2d);
      piVar6 = param_3;
    }
    else {
LAB_100116b7:
      iVar3 = FUN_10003aea(param_3 + 3,(ushort *)(piVar2 + 3));
      if (-1 < iVar3) {
LAB_10011708:
        puVar4 = (undefined4 *)FUN_100114bc(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_100034e4((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (iVar3 = FUN_10003aea(piVar2 + 3,(ushort *)(param_4 + 3)), -1 < iVar3)) goto LAB_10011708;
      cVar5 = *(char *)(param_3[2] + 0x2d);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_10011614;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_10011614:
  FUN_100111f0(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_10011724 at 10011724

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10011724(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000cb34((int)this);
  FUN_10011592((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10011761 at 10011761

void Catch_10011761(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10011774 at 10011774

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10011774(void *this,undefined4 *param_1)

{
  FUN_100115a5(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_100117a2 at 100117a2

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100117a2(void *this,undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 local_28 [3];
  undefined4 local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x100117ae;
  FUN_10003ab3(local_28);
  local_8 = 1;
  if (*(char *)((int)this + 0x14) == '\0') {
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x2c))(param_1);
    FUN_1000701b(local_28,iVar1);
  }
  local_18 = 0;
  while( true ) {
    iVar1 = local_18;
    puVar2 = FUN_100023a4();
    if (*(int *)(puVar2 + iVar1 * 4) == 0) break;
    puVar2 = FUN_100023a4();
    param_1 = *(undefined4 *)(puVar2 + iVar1 * 4);
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x28))(&param_1);
    FUN_1000701b(local_28,iVar1);
    local_18 = local_18 + 1;
  }
  return local_1c;
}



// Function: Catch@1001181f at 1001181f

undefined4 Catch_1001181f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10011810;
}



// Function: FUN_10011829 at 10011829

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10011829(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 **ppuVar2;
  int iVar3;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10011835;
  FUN_10003ab3(local_24);
  local_8 = 1;
  if (*(char *)((int)this + 0x14) == '\0') {
    if (param_1 != (undefined4 *)0x0) {
      iVar3 = (**(code **)*param_1)(param_1,&DAT_1001a610,(undefined4 *)((int)this + 0x18));
      FUN_1000701b(local_24,iVar3);
      piVar1 = *(int **)((int)this + 0x18);
      ppuVar2 = FUN_10006498();
      if (ppuVar2 == (undefined4 **)0x0) {
        param_1 = (undefined4 *)0x0;
      }
      else {
        param_1 = (undefined4 *)Ordinal_2(ppuVar2);
        if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_1000108d(0x8007000e);
        }
      }
      local_8._0_1_ = 2;
      iVar3 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_1);
      FUN_1000701b(local_24,iVar3);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(param_1);
      goto LAB_100118ae;
    }
    iVar3 = -0x7fffbffd;
  }
  else {
    iVar3 = 0;
  }
  FUN_1000701b(local_24,iVar3);
LAB_100118ae:
  *(undefined1 *)((int)this + 0x14) = 1;
  return local_18;
}



// Function: Catch@100118dc at 100118dc

undefined4 Catch_100118dc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100118b5;
}



// Function: FUN_100118e6 at 100118e6

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100118e6(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_28 [3];
  undefined4 local_1c;
  undefined4 *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x100118f2;
  FUN_10003ab3(local_28);
  local_8 = 1;
  iVar1 = FUN_1000eb1c(local_18);
  FUN_1000701b(local_28,iVar1);
  local_18[0][2] = param_1;
  iVar1 = (**(code **)*local_18[0])(local_18[0],&DAT_1001a620,param_2);
  FUN_1000701b(local_28,iVar1);
  return local_1c;
}



// Function: Catch@10011946 at 10011946

undefined4 Catch_10011946(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10011937;
}



// Function: FUN_10011950 at 10011950

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10011950(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_100158f9;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10011774(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1001197e at 1001197e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1001197e(void *this,ushort *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_38;
  undefined4 local_34 [7];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x1001198a;
  piVar1 = FUN_10005366(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_10003aea(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_100119ed;
  }
  basic_string<>(local_34,(undefined4 *)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_10011724(this,local_34);
  FUN_100115f8(this,&local_38,piVar1,piVar3);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_34,'\x01',0);
LAB_100119ed:
  FUN_100127fb();
  return;
}



// Function: FUN_100119f8 at 100119f8

void __cdecl FUN_100119f8(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10011950(param_2,param_3);
  return;
}



// Function: FUN_10011a0b at 10011a0b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10011a0b(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10011a17;
  puVar1 = FUN_100023a4();
  FUN_10001f54(local_30,*(wchar_t **)(puVar1 + *(int *)(param_1 + 8) * 4));
  local_8 = 0;
  puVar2 = (undefined4 *)FUN_1001197e((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  (*(code *)**(undefined4 **)*puVar2)((undefined4 *)*puVar2,&DAT_1001ae48,param_2);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_10011a6c at 10011a6c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10011a6c(int param_1,int *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10011a78;
  puVar2 = FUN_100023a4();
  FUN_10001f54(local_30,*(wchar_t **)(puVar2 + *(int *)(param_1 + 8) * 4));
  local_8 = 0;
  piVar3 = (int *)FUN_1001197e((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  iVar1 = *piVar3;
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  if (iVar1 != 0) {
    puVar2 = FUN_100023a4();
    FUN_10001f54(local_30,*(wchar_t **)(puVar2 + *(int *)(param_1 + 8) * 4));
    local_8 = 1;
    puVar4 = (undefined4 *)FUN_1001197e((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
    (**(code **)(*(int *)*puVar4 + 8))((int *)*puVar4);
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
    puVar2 = FUN_100023a4();
    FUN_10001f54(local_30,*(wchar_t **)(puVar2 + *(int *)(param_1 + 8) * 4));
    local_8 = 2;
    puVar4 = (undefined4 *)FUN_1001197e((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
    *puVar4 = 0;
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  local_8 = 4;
  puVar2 = FUN_100023a4();
  FUN_10001f54(local_30,*(wchar_t **)(puVar2 + *(int *)(param_1 + 8) * 4));
  local_8._0_1_ = 5;
  puVar4 = (undefined4 *)FUN_1001197e((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  *puVar4 = param_2;
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_30,'\x01',0);
  puVar2 = FUN_100023a4();
  FUN_10001f54(local_30,*(wchar_t **)(puVar2 + *(int *)(param_1 + 8) * 4));
  local_8._0_1_ = 6;
  puVar4 = (undefined4 *)FUN_1001197e((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  (**(code **)(*(int *)*puVar4 + 4))((int *)*puVar4);
  local_8 = CONCAT31(local_8._1_3_,4);
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  FUN_100127fb();
  return;
}



// Function: FUN_10011bd8 at 10011bd8

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10011bd8(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000cb34((int)this);
  FUN_100119f8((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10011c15 at 10011c15

void Catch_10011c15(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10011c28 at 10011c28

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10011c28(void *this,ushort *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_38;
  undefined4 local_34 [7];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10011c34;
  piVar1 = FUN_10005366(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_10003aea(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_10011c97;
  }
  basic_string<>(local_34,(undefined4 *)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_10011bd8(this,local_34);
  FUN_100115f8(this,&local_38,piVar1,piVar3);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_34,'\x01',0);
LAB_10011c97:
  FUN_100127fb();
  return;
}



// Function: FUN_10011ca2 at 10011ca2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10011ca2(void *this,int *param_1)

{
  int *piVar1;
  undefined4 **ppuVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  undefined4 local_3c;
  int local_38;
  int local_34;
  undefined1 local_30 [40];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x10011cae;
  piVar1 = *(int **)((int)this + 0x18);
  if (*param_1 == 0) {
    local_34 = 0;
  }
  else {
    local_34 = Ordinal_2(*param_1);
    if (local_34 == 0) goto LAB_10011cdf;
  }
  local_8 = 0;
  ppuVar2 = FUN_10006498();
  if (ppuVar2 == (undefined4 **)0x0) {
    local_38 = 0;
  }
  else {
    local_38 = Ordinal_2(ppuVar2);
    if (local_38 == 0) {
LAB_10011cdf:
                    /* WARNING: Subroutine does not return */
      FUN_1000108d(0x8007000e);
    }
  }
  local_8._0_1_ = 1;
  (**(code **)(*piVar1 + 0x24))(piVar1,local_38,local_34,&local_3c);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_38);
  local_8 = 0xffffffff;
  Ordinal_6(local_34);
  puVar3 = FUN_10001f54(local_30,(wchar_t *)*param_1);
  local_8 = 2;
  puVar4 = (undefined4 *)FUN_10011c28((void *)((int)this + 4),puVar3);
  *puVar4 = local_3c;
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_100127fb();
  return;
}



// Function: FUN_10011d60 at 10011d60

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __cdecl FUN_10011d60(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1000108d(0x8007000e);
    }
  }
  return param_1;
}



// Function: FUN_10011db2 at 10011db2

void __cdecl FUN_10011db2(void *param_1,wchar_t *param_2,wchar_t *param_3)

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
  for (uVar4 = FUN_1000b8ca(param_1,(ushort *)param_2,0,sVar3); uVar4 != 0xffffffff;
      uVar4 = FUN_1000b8ca(param_1,(ushort *)param_2,iVar1 + uVar4,sVar3)) {
    pwVar5 = param_3;
    if (7 < *(uint *)(param_3 + 10)) {
      pwVar5 = *(wchar_t **)param_3;
    }
    FUN_1000eaf6(param_1,uVar4,*(undefined4 **)(pwVar2 + 8),pwVar5);
    iVar1 = *(int *)(param_3 + 8);
    param_2 = pwVar2;
    if (7 < *(uint *)(pwVar2 + 10)) {
      param_2 = *(wchar_t **)pwVar2;
    }
    sVar3 = wcslen(param_2);
  }
  return;
}



// Function: FUN_10011e36 at 10011e36

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_10011e36(undefined2 *param_1,wchar_t *param_2)

{
  if (param_2 == (wchar_t *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
  else {
    FUN_10001f54(param_1,param_2);
  }
  return param_1;
}



// Function: FUN_10011e88 at 10011e88

void __fastcall FUN_10011e88(int param_1)

{
  LRESULT LVar1;
  LRESULT LVar2;
  
  SetWindowTextW(*(HWND *)(param_1 + 4),*(LPCWSTR *)(param_1 + 8));
  LVar1 = SendMessageW(*(HWND *)(param_1 + 4),0xba,0,0);
  LVar2 = SendMessageW(*(HWND *)(param_1 + 4),0xce,0,0);
  SendMessageW(*(HWND *)(param_1 + 4),0xb6,0,LVar1 - LVar2);
  return;
}



// Function: FUN_10011ed0 at 10011ed0

int __thiscall FUN_10011ed0(void *this,int param_1,void *param_2,int param_3,void *param_4)

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
    local_8 = FUN_10003346(this,iVar1);
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



// Function: FUN_10011f55 at 10011f55

void __thiscall FUN_10011f55(void *this,int param_1,void *param_2)

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
    iVar2 = FUN_10011ed0(this,*(int *)((int)pvVar1 + -8),pvVar1,param_1,param_2);
    if (iVar2 != 0) {
      FUN_10002528((LONG *)((int)pvVar1 + -0xc));
    }
  }
  return;
}



// Function: FUN_10011fce at 10011fce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10011fce(undefined4 *param_1)

{
  *param_1 = CStatusBox::vftable;
  FUN_1000331a(param_1 + 2);
  return;
}



// Function: FUN_10011ff5 at 10011ff5

void * __thiscall FUN_10011ff5(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    iVar1 = lstrlenW(param_1);
  }
  FUN_10011f55(this,iVar1,param_1);
  return this;
}



// Function: FUN_1001201d at 1001201d

undefined4 * __thiscall FUN_1001201d(void *this,byte param_1)

{
  FUN_10011fce((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001203c at 1001203c

undefined4 * __thiscall FUN_1001203c(void *this,LPCWSTR param_1)

{
  uint _Size;
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_100243c0;
  if (param_1 != (LPCWSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_100059b5(this,(uint)param_1 & 0xffff);
    }
    else {
      iVar1 = lstrlenW(param_1);
      if (((iVar1 != 0) && (iVar2 = FUN_10003346(this,iVar1), iVar2 != 0)) &&
         (_Size = iVar1 * 2, _Size <= _Size + 2)) {
                    /* WARNING: Load size is inaccurate */
        memcpy(*this,param_1,_Size);
      }
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1001209f at 1001209f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1001209f(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = CStatusBox::vftable;
  FUN_1001203c(param_1 + 2,L"");
  return param_1;
}



// Function: FUN_100120d3 at 100120d3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100120d3(int param_1)

{
  void *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0;
  FUN_10006026(local_14,(int *)&stack0x00000004);
  local_8._0_1_ = 1;
  FUN_10011ff5(local_14,L"\r\n");
  FUN_10011f55((void *)(param_1 + 8),*(int *)((int)local_14[0] + -8),local_14[0]);
  FUN_10011e88(param_1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000331a((int *)local_14);
  local_8 = 0xffffffff;
  FUN_1000331a((int *)&stack0x00000004);
  return;
}



// Function: FUN_1001213e at 1001213e

int __fastcall FUN_1001213e(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10012163 at 10012163

void __fastcall FUN_10012163(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  RemoveAll((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 1001217b

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
LAB_100121c9:
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
        goto LAB_100121c9;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_100121d8 at 100121d8

undefined4 * __fastcall FUN_100121d8(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1001213e((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1001b318;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10025fd8 = 1;
  }
  return param_1;
}



// Function: __FreeStdCallThunk_cmn at 10012218

/* Library Function - Single Match
    void __cdecl __FreeStdCallThunk_cmn(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void __cdecl __FreeStdCallThunk_cmn(void *param_1)

{
  HANDLE hHeap;
  DWORD dwFlags;
  
  if (DAT_1002690c == (PSLIST_HEADER)0x1) {
    dwFlags = 0;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,param_1);
    return;
  }
  InterlockedPushEntrySList(DAT_1002690c,(PSINGLE_LIST_ENTRY)param_1);
  return;
}



// Function: __InitializeThunkPool at 10012244

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
    DAT_1002690c = 1;
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
  DAT_1002690c = DVar4;
  return 1;
}



// Function: FreeStdCallThunk at 100122b2

/* Library Function - Multiple Matches With Same Base Name
    void __stdcall __FreeStdCallThunk(void *)
    void __stdcall ATL::__FreeStdCallThunk(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void FreeStdCallThunk(void *param_1)

{
  __FreeStdCallThunk_cmn(param_1);
  return;
}



// Function: __AllocStdCallThunk_cmn at 100122c4

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
  
  if ((DAT_1002690c != (PSLIST_HEADER)0x0) || (iVar1 = __InitializeThunkPool(), iVar1 != 0)) {
    if (DAT_1002690c == (PSLIST_HEADER)0x1) {
      dwBytes = 0xd;
      dwFlags = 0;
      hHeap = GetProcessHeap();
      pvVar2 = HeapAlloc(hHeap,dwFlags,dwBytes);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
    }
    else {
      p_Var3 = InterlockedPopEntrySList(DAT_1002690c);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        return p_Var3;
      }
      p_Var3 = (PSINGLE_LIST_ENTRY)VirtualAlloc((LPVOID)0x0,0x1000,0x1000,0x40);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        p_Var4 = InterlockedPopEntrySList(DAT_1002690c);
        if (p_Var4 != (PSINGLE_LIST_ENTRY)0x0) {
          VirtualFree(p_Var3,0,0x8000);
          return p_Var4;
        }
        p_Var4 = p_Var3 + 0x3fc;
        do {
          InterlockedPushEntrySList(DAT_1002690c,p_Var3);
          p_Var3 = p_Var3 + 4;
        } while (p_Var3 < p_Var4);
        return p_Var3;
      }
    }
  }
  return (void *)0x0;
}



// Function: AtlWinModuleInit at 10012367

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



// Function: RemoveAll at 1001238f

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



// Function: FUN_100123ae at 100123ae

int __fastcall FUN_100123ae(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 100123d3

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_100123e0:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_100123e0;
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



// Function: FUN_10012449 at 10012449

_ATL_WIN_MODULE70 * __fastcall FUN_10012449(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_100123ae((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_10025fd8 = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: FUN_10012471 at 10012471

void __fastcall FUN_10012471(int *param_1)

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



// Function: FUN_100124b5 at 100124b5

int __fastcall FUN_100124b5(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_100124ce at 100124ce

undefined4 * __fastcall FUN_100124ce(undefined4 *param_1)

{
  long lVar1;
  
  FUN_100124b5((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_100212f0;
  param_1[3] = &DAT_100212f0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10025fd8 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10012510 at 10012510

void FUN_10012510(undefined4 param_1)

{
  (*(code *)PTR_FUN_100256c4)(param_1,0);
  return;
}



// Function: FUN_10012560 at 10012560

void FUN_10012560(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__1001b328;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_100211c8);
}



// Function: _com_error at 100125a0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001b328;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 100125e0

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001b328;
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



// Function: FUN_10012621 at 10012621

void __fastcall FUN_10012621(int param_1)

{
  facet *pfVar1;
  
  pfVar1 = std::locale::facet::_Decref(*(facet **)(param_1 + 4));
  if (pfVar1 != (facet *)0x0) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: Facet_Register at 10012637

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
    *puVar1 = DAT_10026964;
    puVar1[1] = param_1;
  }
  DAT_10026964 = puVar1;
  return;
}



// Function: FUN_10012661 at 10012661

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10012661(void)

{
  undefined4 *puVar1;
  _Lockit local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x1001266d;
  std::_Lockit::_Lockit(local_14,0);
  local_8 = 0;
  while (puVar1 = DAT_10026964, DAT_10026964 != (undefined4 *)0x0) {
    DAT_10026964 = (undefined4 *)*DAT_10026964;
    FUN_10012621((int)puVar1);
    operator_delete(puVar1);
  }
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_14);
  return;
}



// Function: FUN_100126e8 at 100126e8

void FUN_100126e8(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __security_check_cookie at 10012700

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_100256e0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 1001270f

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100256e0 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 10012742

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100256e0 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 10012778

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100256e0 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 100127ae

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100256e0 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 100127e7

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



// Function: FUN_100127fb at 100127fb

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100127fb(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_1001280a at 1001280a

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1001280a(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10012819

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



// Function: __ArrayUnwind at 10012896

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



// Function: `eh_vector_destructor_iterator' at 100128f4

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
  FUN_1001293f();
  return;
}



// Function: FUN_1001293f at 1001293f

void FUN_1001293f(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 1001295e

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
  
  local_8 = &DAT_10021268;
  uStack_c = 0x1001296a;
  local_20[0] = DecodePointer(DAT_10026cac);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10026cac);
    local_24 = DecodePointer(DAT_10026ca8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10026cac = EncodePointer(local_20[0]);
    DAT_10026ca8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_100129f6();
  }
  return p_Var1;
}



// Function: FUN_100129f6 at 100129f6

void FUN_100129f6(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 100129ff

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 10012a40

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



// Function: `eh_vector_constructor_iterator' at 10012a6b

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
  FUN_10012ab8();
  return;
}



// Function: FUN_10012ab8 at 10012ab8

void FUN_10012ab8(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: FUN_10012b27 at 10012b27

void __cdecl
FUN_10012b27(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_100256e0,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 10012b50

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



// Function: __alloca_probe_8 at 10012b66

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



// Function: __CRT_INIT@12 at 10012bce

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
    if (DAT_1002696c < 1) {
      return 0;
    }
    DAT_1002696c = DAT_1002696c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10026ca0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10026c9c == 2) {
      param_2 = (int *)DecodePointer(DAT_10026cac);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10026ca8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10026cac);
            piVar8 = (int *)DecodePointer(DAT_10026ca8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10026ca8 = (PVOID)encoded_null();
        DAT_10026cac = DAT_10026ca8;
      }
      DAT_10026c9c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10026ca0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10026ca0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10026c9c == 0) {
      DAT_10026c9c = 1;
      iVar5 = initterm_e(&DAT_100186bc,&DAT_100186c4);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_100183d0,&DAT_100186b8);
      DAT_10026c9c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10026ca0,0);
    }
    if ((DAT_10026ca4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10026ca4), BVar2 != 0)) {
      (*DAT_10026ca4)(param_1,2,param_3);
    }
    DAT_1002696c = DAT_1002696c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 10012dd8

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10012e78) */
/* WARNING: Removing unreachable block (ram,0x10012e25) */
/* WARNING: Removing unreachable block (ram,0x10012ea5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_100256f0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1002696c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_1000c051(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_1000c051(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_10012ee3();
  return local_20;
}



// Function: FUN_10012ee3 at 10012ee3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10012ee3(void)

{
  _DAT_100256f0 = 0xffffffff;
  return;
}



// Function: entry at 10012eee

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 10012f11

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
  
  _DAT_10026a88 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10026a8c = &stack0x00000004;
  _DAT_100269c8 = 0x10001;
  _DAT_10026970 = 0xc0000409;
  _DAT_10026974 = 1;
  local_32c = DAT_100256e0;
  local_328 = DAT_100256e4;
  _DAT_1002697c = unaff_retaddr;
  _DAT_10026a54 = in_GS;
  _DAT_10026a58 = in_FS;
  _DAT_10026a5c = in_ES;
  _DAT_10026a60 = in_DS;
  _DAT_10026a64 = unaff_EDI;
  _DAT_10026a68 = unaff_ESI;
  _DAT_10026a6c = unaff_EBX;
  _DAT_10026a70 = in_EDX;
  _DAT_10026a74 = in_ECX;
  _DAT_10026a78 = in_EAX;
  _DAT_10026a7c = unaff_EBP;
  DAT_10026a80 = unaff_retaddr;
  _DAT_10026a84 = in_CS;
  _DAT_10026a90 = in_SS;
  DAT_100269c0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1001b338);
  if (DAT_100269c0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10013020

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100256e0 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10013065

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



// Function: __ValidateImageBase at 100130f0

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



// Function: __FindPESection at 10013130

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



// Function: __IsNonwritableInCurrentImage at 10013180

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
  
  pcStack_10 = FUN_10012b27;
  local_14 = ExceptionList;
  local_c = DAT_100256e0 ^ 0x100212d0;
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



// Function: ___security_init_cookie at 10013254

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
  if ((DAT_100256e0 == 0xbb40e64e) || ((DAT_100256e0 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_100256e0 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_100256e0 == 0xbb40e64e) {
      DAT_100256e0 = 0xbb40e64f;
    }
    else if ((DAT_100256e0 & 0xffff0000) == 0) {
      DAT_100256e0 = DAT_100256e0 | (DAT_100256e0 | 0x4711) << 0x10;
    }
    DAT_100256e4 = ~DAT_100256e0;
  }
  else {
    DAT_100256e4 = ~DAT_100256e0;
  }
  return;
}



// Function: Unwind@10013302 at 10013302

void Unwind_10013302(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013305. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013326 at 10013326

void Unwind_10013326(void)

{
  int unaff_EBP;
  
  FUN_10001198(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013349 at 10013349

void Unwind_10013349(void)

{
  int unaff_EBP;
  
  FUN_100010fd(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001336c at 1001336c

void Unwind_1001336c(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001338f at 1001338f

void Unwind_1001338f(void)

{
  int unaff_EBP;
  
  FUN_10001333((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100133b5 at 100133b5

void Unwind_100133b5(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100133c0 at 100133c0

void Unwind_100133c0(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@100133cb at 100133cb

void Unwind_100133cb(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100133d3 at 100133d3

void Unwind_100133d3(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100133f6 at 100133f6

void Unwind_100133f6(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100133fe at 100133fe

void Unwind_100133fe(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013406 at 10013406

void Unwind_10013406(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + -0x28);
  return;
}



// Function: Unwind@1001340e at 1001340e

void Unwind_1001340e(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013431 at 10013431

void Unwind_10013431(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013439 at 10013439

void Unwind_10013439(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013441 at 10013441

void Unwind_10013441(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + -0x28);
  return;
}



// Function: Unwind@10013449 at 10013449

void Unwind_10013449(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013487 at 10013487

void Unwind_10013487(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001348f at 1001348f

void Unwind_1001348f(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001349a at 1001349a

void Unwind_1001349a(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100134a2 at 100134a2

void Unwind_100134a2(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@100134ad at 100134ad

void Unwind_100134ad(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100134b5 at 100134b5

void Unwind_100134b5(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100134c0 at 100134c0

void Unwind_100134c0(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100134c8 at 100134c8

void Unwind_100134c8(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@100134d3 at 100134d3

void Unwind_100134d3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@100134f9 at 100134f9

void Unwind_100134f9(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10013504 at 10013504

void Unwind_10013504(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001350f at 1001350f

void Unwind_1001350f(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001351a at 1001351a

void Unwind_1001351a(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10013525 at 10013525

void Unwind_10013525(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10013530 at 10013530

void Unwind_10013530(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013538 at 10013538

void Unwind_10013538(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013540 at 10013540

void Unwind_10013540(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013548 at 10013548

void Unwind_10013548(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001356b at 1001356b

void Unwind_1001356b(void)

{
  int unaff_EBP;
  
  FUN_10001658(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013573 at 10013573

void Unwind_10013573(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001357e at 1001357e

void Unwind_1001357e(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100135a1 at 100135a1

void Unwind_100135a1(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100135a9 at 100135a9

void Unwind_100135a9(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100135b4 at 100135b4

void Unwind_100135b4(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100135bc at 100135bc

void Unwind_100135bc(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@100135e2 at 100135e2

void Unwind_100135e2(void)

{
  int unaff_EBP;
  
  FUN_10001658(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100135ea at 100135ea

void Unwind_100135ea(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100135f2 at 100135f2

void Unwind_100135f2(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10013618 at 10013618

void Unwind_10013618(void)

{
  int unaff_EBP;
  
  FUN_10001aa9(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013620 at 10013620

void Unwind_10013620(void)

{
  int unaff_EBP;
  
  FUN_10001aa9(*(int *)(unaff_EBP + -0x10) + 0x14);
  return;
}



// Function: Unwind@10013646 at 10013646

void Unwind_10013646(void)

{
  int unaff_EBP;
  
  FUN_10001333((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10013651 at 10013651

void Unwind_10013651(void)

{
  int unaff_EBP;
  
  FUN_10001609(*(int *)(unaff_EBP + -0x10) + 0x70);
  return;
}



// Function: Unwind@1001365c at 1001365c

void Unwind_1001365c(void)

{
  int unaff_EBP;
  
  FUN_10001c44(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10013667 at 10013667

void Unwind_10013667(void)

{
  int unaff_EBP;
  
  FUN_100019f2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001368d at 1001368d

void Unwind_1001368d(void)

{
  DAT_10025974 = DAT_10025974 & 0xfffffffe;
  return;
}



// Function: Unwind@100136b6 at 100136b6

void Unwind_100136b6(void)

{
  int unaff_EBP;
  
  FUN_10002420((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100136dc at 100136dc

void Unwind_100136dc(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100136df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013700 at 10013700

void Unwind_10013700(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013703. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013724 at 10013724

void Unwind_10013724(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001372c at 1001372c

void Unwind_1001372c(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10013752 at 10013752

void Unwind_10013752(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001375d at 1001375d

void Unwind_1001375d(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013780 at 10013780

void Unwind_10013780(void)

{
  int unaff_EBP;
  
  FUN_10001575(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013788 at 10013788

void Unwind_10013788(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100137ab at 100137ab

void Unwind_100137ab(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100137ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100137cf at 100137cf

void Unwind_100137cf(void)

{
  int unaff_EBP;
  
  FUN_10002100((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@100137f2 at 100137f2

void Unwind_100137f2(void)

{
  int unaff_EBP;
  
  FUN_100025f2(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013830 at 10013830

void Unwind_10013830(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013855 at 10013855

void Unwind_10013855(void)

{
  int unaff_EBP;
  
  FUN_1000273d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10013860 at 10013860

void Unwind_10013860(void)

{
  int unaff_EBP;
  
  FUN_10002420((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10013886 at 10013886

void Unwind_10013886(void)

{
  int unaff_EBP;
  
  FUN_10002f12((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001388e at 1001388e

void Unwind_1001388e(void)

{
  int unaff_EBP;
  
  FUN_10002100((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100138b1 at 100138b1

void Unwind_100138b1(void)

{
  int unaff_EBP;
  
  FUN_10002f12((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100138d4 at 100138d4

void Unwind_100138d4(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100138dc at 100138dc

void Unwind_100138dc(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@100138e7 at 100138e7

void Unwind_100138e7(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100138ef at 100138ef

void Unwind_100138ef(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@100138fa at 100138fa

void Unwind_100138fa(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10013920 at 10013920

void Unwind_10013920(void)

{
  int unaff_EBP;
  
  FUN_10002420((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001392b at 1001392b

void Unwind_1001392b(void)

{
  int unaff_EBP;
  
  FUN_1000273d(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10013951 at 10013951

void Unwind_10013951(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001395c at 1001395c

void Unwind_1001395c(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@10013967 at 10013967

void Unwind_10013967(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10013972 at 10013972

void Unwind_10013972(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001397a at 1001397a

void Unwind_1001397a(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001399d at 1001399d

void Unwind_1001399d(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100139a5 at 100139a5

void Unwind_100139a5(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100139ad at 100139ad

void Unwind_100139ad(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100139b5 at 100139b5

void Unwind_100139b5(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100139d8 at 100139d8

void Unwind_100139d8(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100139e0 at 100139e0

void Unwind_100139e0(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100139e8 at 100139e8

void Unwind_100139e8(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10013a15 at 10013a15

void Unwind_10013a15(void)

{
  int unaff_EBP;
  
  FUN_1000245d(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10013a20 at 10013a20

void Unwind_10013a20(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10013a2b at 10013a2b

void Unwind_10013a2b(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@10013a36 at 10013a36

void Unwind_10013a36(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10013a41 at 10013a41

void Unwind_10013a41(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10013a4c at 10013a4c

void Unwind_10013a4c(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013a54 at 10013a54

void Unwind_10013a54(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013a5c at 10013a5c

void Unwind_10013a5c(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013a64 at 10013a64

void Unwind_10013a64(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013a87 at 10013a87

void Unwind_10013a87(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + 0x3c);
  return;
}



// Function: Unwind@10013a8f at 10013a8f

void Unwind_10013a8f(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + 0x2c);
  return;
}



// Function: Unwind@10013a97 at 10013a97

void Unwind_10013a97(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + 0x1c);
  return;
}



// Function: Unwind@10013a9f at 10013a9f

void Unwind_10013a9f(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + 0xc);
  return;
}



// Function: Unwind@10013aa7 at 10013aa7

void Unwind_10013aa7(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10013aaf at 10013aaf

void Unwind_10013aaf(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10013ab7 at 10013ab7

void Unwind_10013ab7(void)

{
  int unaff_EBP;
  
  FUN_10002b76((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10013abf at 10013abf

void Unwind_10013abf(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + -0x50);
  return;
}



// Function: Unwind@10013ac7 at 10013ac7

void Unwind_10013ac7(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10013acf at 10013acf

void Unwind_10013acf(void)

{
  int unaff_EBP;
  
  FUN_100014c7(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@10013ad7 at 10013ad7

void Unwind_10013ad7(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(unaff_EBP + -0x50),0x10,4,FUN_100014c7);
  return;
}



// Function: Unwind@10013aea at 10013aea

void Unwind_10013aea(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10013af2 at 10013af2

void Unwind_10013af2(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10013b1f at 10013b1f

void Unwind_10013b1f(void)

{
  int unaff_EBP;
  
  FUN_1000245d(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10013b2a at 10013b2a

void Unwind_10013b2a(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013b32 at 10013b32

void Unwind_10013b32(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10013b3d at 10013b3d

void Unwind_10013b3d(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013b45 at 10013b45

void Unwind_10013b45(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@10013b50 at 10013b50

void Unwind_10013b50(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013b58 at 10013b58

void Unwind_10013b58(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10013b63 at 10013b63

void Unwind_10013b63(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013b6b at 10013b6b

void Unwind_10013b6b(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10013bac at 10013bac

void Unwind_10013bac(void)

{
  int unaff_EBP;
  
  FUN_10004606((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013bcf at 10013bcf

void Unwind_10013bcf(void)

{
  int unaff_EBP;
  
  FUN_10004565(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013bf2 at 10013bf2

void Unwind_10013bf2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10013bfe at 10013bfe

void Unwind_10013bfe(void)

{
  int unaff_EBP;
  
  FUN_10002f4a((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@10013c3f at 10013c3f

void Unwind_10013c3f(void)

{
  int unaff_EBP;
  
  FUN_100034b4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013c62 at 10013c62

void Unwind_10013c62(void)

{
  int unaff_EBP;
  
  FUN_10004ba8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013c6a at 10013c6a

void Unwind_10013c6a(void)

{
  int unaff_EBP;
  
  FUN_100034b4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013c8d at 10013c8d

void Unwind_10013c8d(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013c95 at 10013c95

void Unwind_10013c95(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013c9d at 10013c9d

void Unwind_10013c9d(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013ca5 at 10013ca5

void Unwind_10013ca5(void)

{
  int unaff_EBP;
  
  FUN_100014c7(*(undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013cad at 10013cad

void Unwind_10013cad(void)

{
  int unaff_EBP;
  
  FUN_100014c7(*(undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013cb5 at 10013cb5

void Unwind_10013cb5(void)

{
  int unaff_EBP;
  
  FUN_100014c7(*(undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10013cbd at 10013cbd

void Unwind_10013cbd(void)

{
  int unaff_EBP;
  
  FUN_100014c7(*(undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10013ce0 at 10013ce0

void Unwind_10013ce0(void)

{
  int unaff_EBP;
  
  FUN_100045ae((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10013d13 at 10013d13

void Unwind_10013d13(void)

{
  int unaff_EBP;
  
  FUN_10003cf1(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013d36 at 10013d36

void Unwind_10013d36(void)

{
  int unaff_EBP;
  
  FUN_10004714(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013d3e at 10013d3e

void Unwind_10013d3e(void)

{
  int unaff_EBP;
  
  FUN_10004565(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013d61 at 10013d61

void Unwind_10013d61(void)

{
  int unaff_EBP;
  
  FUN_10004565((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013d69 at 10013d69

void Unwind_10013d69(void)

{
  int unaff_EBP;
  
  FUN_10004714((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013d71 at 10013d71

void Unwind_10013d71(void)

{
  int unaff_EBP;
  
  FUN_10005123((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013d79 at 10013d79

void Unwind_10013d79(void)

{
  int unaff_EBP;
  
  FUN_10004714((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013d81 at 10013d81

void Unwind_10013d81(void)

{
  int unaff_EBP;
  
  FUN_10004565((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013da4 at 10013da4

void Unwind_10013da4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013da7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10013dad at 10013dad

void Unwind_10013dad(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10013dc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@10013dca at 10013dca

void Unwind_10013dca(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@10013dd6 at 10013dd6

void Unwind_10013dd6(void)

{
  int unaff_EBP;
  
  FUN_10002f4a((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10013dfc at 10013dfc

void Unwind_10013dfc(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013e04 at 10013e04

void Unwind_10013e04(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013e0c at 10013e0c

void Unwind_10013e0c(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013e14 at 10013e14

void Unwind_10013e14(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013e1c at 10013e1c

void Unwind_10013e1c(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013e24 at 10013e24

void Unwind_10013e24(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013e2c at 10013e2c

void Unwind_10013e2c(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013e34 at 10013e34

void Unwind_10013e34(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013e3c at 10013e3c

void Unwind_10013e3c(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10013e5f at 10013e5f

void Unwind_10013e5f(void)

{
  int unaff_EBP;
  
  FUN_10003b0b(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013e82 at 10013e82

void Unwind_10013e82(void)

{
  int unaff_EBP;
  
  FUN_10004bc6(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013e8a at 10013e8a

void Unwind_10013e8a(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013ead at 10013ead

void Unwind_10013ead(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013eb5 at 10013eb5

void Unwind_10013eb5(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10013ebd at 10013ebd

void Unwind_10013ebd(void)

{
  int unaff_EBP;
  
  FUN_10004565((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013ec5 at 10013ec5

void Unwind_10013ec5(void)

{
  int unaff_EBP;
  
  FUN_10004714((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013ecd at 10013ecd

void Unwind_10013ecd(void)

{
  int unaff_EBP;
  
  FUN_10005123((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013ed5 at 10013ed5

void Unwind_10013ed5(void)

{
  int unaff_EBP;
  
  FUN_10004714((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013edd at 10013edd

void Unwind_10013edd(void)

{
  int unaff_EBP;
  
  FUN_10004565((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013ee5 at 10013ee5

void Unwind_10013ee5(void)

{
  int unaff_EBP;
  
  FUN_10004714((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013eed at 10013eed

void Unwind_10013eed(void)

{
  int unaff_EBP;
  
  FUN_10004565((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013ef5 at 10013ef5

void Unwind_10013ef5(void)

{
  int unaff_EBP;
  
  FUN_10004714((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013efd at 10013efd

void Unwind_10013efd(void)

{
  int unaff_EBP;
  
  FUN_10004565((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013f05 at 10013f05

void Unwind_10013f05(void)

{
  int unaff_EBP;
  
  FUN_10004714((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013f0d at 10013f0d

void Unwind_10013f0d(void)

{
  int unaff_EBP;
  
  FUN_10004565((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013f30 at 10013f30

void Unwind_10013f30(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013f38 at 10013f38

void Unwind_10013f38(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013f40 at 10013f40

void Unwind_10013f40(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013f48 at 10013f48

void Unwind_10013f48(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013f50 at 10013f50

void Unwind_10013f50(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013f73 at 10013f73

void Unwind_10013f73(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10013f99 at 10013f99

void Unwind_10013f99(void)

{
  int unaff_EBP;
  
  FUN_10004e77((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013fc6 at 10013fc6

void Unwind_10013fc6(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013fce at 10013fce

void Unwind_10013fce(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10013fd6 at 10013fd6

void Unwind_10013fd6(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013fde at 10013fde

void Unwind_10013fde(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013fe6 at 10013fe6

void Unwind_10013fe6(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013fee at 10013fee

void Unwind_10013fee(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10013ff6 at 10013ff6

void Unwind_10013ff6(void)

{
  int unaff_EBP;
  
  FUN_10001575(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10013ffe at 10013ffe

void Unwind_10013ffe(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014021 at 10014021

void Unwind_10014021(void)

{
  int unaff_EBP;
  
  FUN_10004e77((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001404e at 1001404e

void Unwind_1001404e(void)

{
  int unaff_EBP;
  
  FUN_10003b0b(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014071 at 10014071

void Unwind_10014071(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10014079 at 10014079

void Unwind_10014079(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10014081 at 10014081

void Unwind_10014081(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10014089 at 10014089

void Unwind_10014089(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10014091 at 10014091

void Unwind_10014091(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10014099 at 10014099

void Unwind_10014099(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100140a1 at 100140a1

void Unwind_100140a1(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100140ce at 100140ce

void Unwind_100140ce(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100140d6 at 100140d6

void Unwind_100140d6(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100140de at 100140de

void Unwind_100140de(void)

{
  int unaff_EBP;
  
  FUN_1000605c((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100140e6 at 100140e6

void Unwind_100140e6(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10014113 at 10014113

void Unwind_10014113(void)

{
  DAT_100259a0 = DAT_100259a0 & 0xfffffffe;
  return;
}



// Function: Unwind@1001413c at 1001413c

void Unwind_1001413c(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10014144 at 10014144

void Unwind_10014144(void)

{
  int unaff_EBP;
  
  FUN_1000331a(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014167 at 10014167

void Unwind_10014167(void)

{
  int unaff_EBP;
  
  FUN_1000606f((int *)(*(int *)(unaff_EBP + -0x14) + 0x5c));
  return;
}



// Function: Unwind@1001418d at 1001418d

void Unwind_1001418d(void)

{
  int unaff_EBP;
  
  FUN_1000606f((int *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@100141b3 at 100141b3

void Unwind_100141b3(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100141bb at 100141bb

void Unwind_100141bb(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100141de at 100141de

void Unwind_100141de(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001420b at 1001420b

void Unwind_1001420b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10014213 at 10014213

void Unwind_10014213(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@1001422c at 1001422c

void Unwind_1001422c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10014234 at 10014234

void Unwind_10014234(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10014261 at 10014261

void Unwind_10014261(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10014264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001426a at 1001426a

void Unwind_1001426a(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10014280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x70));
    return;
  }
  return;
}



// Function: Unwind@10014287 at 10014287

void Unwind_10014287(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001428d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@10014293 at 10014293

void Unwind_10014293(void)

{
  int unaff_EBP;
  
  FUN_10006b17((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@100142b9 at 100142b9

void Unwind_100142b9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100142bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@100142c5 at 100142c5

void Unwind_100142c5(void)

{
  int unaff_EBP;
  
  FUN_10006b17((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@100142eb at 100142eb

void Unwind_100142eb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001431f at 1001431f

void Unwind_1001431f(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10014327 at 10014327

void Unwind_10014327(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001432f at 1001432f

void Unwind_1001432f(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014337 at 10014337

void Unwind_10014337(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001433f at 1001433f

void Unwind_1001433f(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10014347 at 10014347

void Unwind_10014347(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001434f at 1001434f

void Unwind_1001434f(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10014357 at 10014357

void Unwind_10014357(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001435f at 1001435f

void Unwind_1001435f(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10014367 at 10014367

void Unwind_10014367(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001436f at 1001436f

void Unwind_1001436f(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10014377 at 10014377

void Unwind_10014377(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001437f at 1001437f

void Unwind_1001437f(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10014387 at 10014387

void Unwind_10014387(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001438f at 1001438f

void Unwind_1001438f(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014397 at 10014397

void Unwind_10014397(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100143ba at 100143ba

void Unwind_100143ba(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100143c2 at 100143c2

void Unwind_100143c2(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100143ca at 100143ca

void Unwind_100143ca(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100143d2 at 100143d2

void Unwind_100143d2(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100143da at 100143da

void Unwind_100143da(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100143e2 at 100143e2

void Unwind_100143e2(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100143ea at 100143ea

void Unwind_100143ea(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100143f2 at 100143f2

void Unwind_100143f2(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100143fa at 100143fa

void Unwind_100143fa(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014402 at 10014402

void Unwind_10014402(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001440a at 1001440a

void Unwind_1001440a(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001442d at 1001442d

void Unwind_1001442d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10014430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014451 at 10014451

void Unwind_10014451(void)

{
  int unaff_EBP;
  
  FUN_100050ea(unaff_EBP + -0xcc);
  return;
}



// Function: Unwind@1001445c at 1001445c

void Unwind_1001445c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10014464 at 10014464

void Unwind_10014464(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10014494 at 10014494

void Unwind_10014494(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001449c at 1001449c

void Unwind_1001449c(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100144a4 at 100144a4

void Unwind_100144a4(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100144ac at 100144ac

void Unwind_100144ac(void)

{
  int unaff_EBP;
  
  FUN_10001198(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100144cf at 100144cf

void Unwind_100144cf(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100144d7 at 100144d7

void Unwind_100144d7(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100144df at 100144df

void Unwind_100144df(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100144e7 at 100144e7

void Unwind_100144e7(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100144ef at 100144ef

void Unwind_100144ef(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014512 at 10014512

void Unwind_10014512(void)

{
  int unaff_EBP;
  
  FUN_10007319(unaff_EBP + -0x2f0);
  return;
}



// Function: Unwind@1001451d at 1001451d

void Unwind_1001451d(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x230));
  return;
}



// Function: Unwind@10014528 at 10014528

void Unwind_10014528(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001455b at 1001455b

void Unwind_1001455b(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10014563 at 10014563

void Unwind_10014563(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001456b at 1001456b

void Unwind_1001456b(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10014576 at 10014576

void Unwind_10014576(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10014581 at 10014581

void Unwind_10014581(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014589 at 10014589

void Unwind_10014589(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001458f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@10014595 at 10014595

void Unwind_10014595(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@100145a0 at 100145a0

void Unwind_100145a0(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100145a8 at 100145a8

void Unwind_100145a8(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@100145b3 at 100145b3

void Unwind_100145b3(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100145e3 at 100145e3

void Unwind_100145e3(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100145eb at 100145eb

void Unwind_100145eb(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100145f3 at 100145f3

void Unwind_100145f3(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@100145fe at 100145fe

void Unwind_100145fe(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10014609 at 10014609

void Unwind_10014609(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014611 at 10014611

void Unwind_10014611(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10014617. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001461d at 1001461d

void Unwind_1001461d(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@10014628 at 10014628

void Unwind_10014628(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014630 at 10014630

void Unwind_10014630(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// Function: Unwind@1001463b at 1001463b

void Unwind_1001463b(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001466b at 1001466b

void Unwind_1001466b(void)

{
  int unaff_EBP;
  
  FUN_100029d3(unaff_EBP + -0xc4);
  return;
}



// Function: Unwind@10014676 at 10014676

void Unwind_10014676(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001467e at 1001467e

void Unwind_1001467e(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10014689 at 10014689

void Unwind_10014689(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10014694 at 10014694

void Unwind_10014694(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001469c at 1001469c

void Unwind_1001469c(void)

{
  int unaff_EBP;
  
  FUN_1000331a(*(int **)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@100146a7 at 100146a7

void Unwind_100146a7(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@100146b2 at 100146b2

void Unwind_100146b2(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@100146bd at 100146bd

void Unwind_100146bd(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100146c5 at 100146c5

void Unwind_100146c5(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100146cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xdc));
  return;
}



// Function: Unwind@100146d1 at 100146d1

void Unwind_100146d1(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@100146dc at 100146dc

void Unwind_100146dc(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100146e4 at 100146e4

void Unwind_100146e4(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@100146ef at 100146ef

void Unwind_100146ef(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001471f at 1001471f

void Unwind_1001471f(void)

{
  int unaff_EBP;
  
  FUN_100029d3(unaff_EBP + -0x118);
  return;
}



// Function: Unwind@1001472a at 1001472a

void Unwind_1001472a(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@10014735 at 10014735

void Unwind_10014735(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xec));
  return;
}



// Function: Unwind@10014740 at 10014740

void Unwind_10014740(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xe4));
  return;
}



// Function: Unwind@1001474b at 1001474b

void Unwind_1001474b(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014753 at 10014753

void Unwind_10014753(void)

{
  int unaff_EBP;
  
  FUN_1000331a(*(int **)(unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@1001475e at 1001475e

void Unwind_1001475e(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014766 at 10014766

void Unwind_10014766(void)

{
  int unaff_EBP;
  
  FUN_1000331a(*(int **)(unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@10014771 at 10014771

void Unwind_10014771(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@1001477c at 1001477c

void Unwind_1001477c(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@10014787 at 10014787

void Unwind_10014787(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001478f at 1001478f

void Unwind_1001478f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10014795. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@1001479b at 1001479b

void Unwind_1001479b(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100147a6 at 100147a6

void Unwind_100147a6(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100147ae at 100147ae

void Unwind_100147ae(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100147b9 at 100147b9

void Unwind_100147b9(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100147c1 at 100147c1

void Unwind_100147c1(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100147c9 at 100147c9

void Unwind_100147c9(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100147d4 at 100147d4

void Unwind_100147d4(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100147df at 100147df

void Unwind_100147df(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100147e7 at 100147e7

void Unwind_100147e7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100147ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@100147f3 at 100147f3

void Unwind_100147f3(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@100147fe at 100147fe

void Unwind_100147fe(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014806 at 10014806

void Unwind_10014806(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x100));
  return;
}



// Function: Unwind@10014811 at 10014811

void Unwind_10014811(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014841 at 10014841

void Unwind_10014841(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@1001484c at 1001484c

void Unwind_1001484c(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10014857 at 10014857

void Unwind_10014857(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@10014862 at 10014862

void Unwind_10014862(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001486d at 1001486d

void Unwind_1001486d(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014875 at 10014875

void Unwind_10014875(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001487d at 1001487d

void Unwind_1001487d(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10014888 at 10014888

void Unwind_10014888(void)

{
  int unaff_EBP;
  
  FUN_10001198(*(undefined4 **)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@10014893 at 10014893

void Unwind_10014893(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001489b at 1001489b

void Unwind_1001489b(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100148a3 at 100148a3

void Unwind_100148a3(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100148ab at 100148ab

void Unwind_100148ab(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100148b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@100148b7 at 100148b7

void Unwind_100148b7(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100148bf at 100148bf

void Unwind_100148bf(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100148c7 at 100148c7

void Unwind_100148c7(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100148cf at 100148cf

void Unwind_100148cf(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100148ff at 100148ff

void Unwind_100148ff(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014907 at 10014907

void Unwind_10014907(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001490f at 1001490f

void Unwind_1001490f(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1001491a at 1001491a

void Unwind_1001491a(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10014925 at 10014925

void Unwind_10014925(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001492d at 1001492d

void Unwind_1001492d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10014933. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0xd0));
  return;
}



// Function: Unwind@10014939 at 10014939

void Unwind_10014939(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10014944 at 10014944

void Unwind_10014944(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001494c at 1001494c

void Unwind_1001494c(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10014957 at 10014957

void Unwind_10014957(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014987 at 10014987

void Unwind_10014987(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001498f at 1001498f

void Unwind_1001498f(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10014997 at 10014997

void Unwind_10014997(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001499f at 1001499f

void Unwind_1001499f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100149a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100149a8 at 100149a8

void Unwind_100149a8(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@100149b0 at 100149b0

void Unwind_100149b0(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100149b8 at 100149b8

void Unwind_100149b8(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@100149c0 at 100149c0

void Unwind_100149c0(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100149ed at 100149ed

void Unwind_100149ed(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100149f5 at 100149f5

void Unwind_100149f5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100149ff at 100149ff

void Unwind_100149ff(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x6c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x6c) = *(uint *)(unaff_EBP + -0x6c) & 0xfffffffe;
    FUN_10001575((int *)(unaff_EBP + -0x74));
    return;
  }
  return;
}



// Function: Unwind@10014a18 at 10014a18

void Unwind_10014a18(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10014a20 at 10014a20

void Unwind_10014a20(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10014a28 at 10014a28

void Unwind_10014a28(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10014a30 at 10014a30

void Unwind_10014a30(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014a38 at 10014a38

void Unwind_10014a38(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10014a3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10014a44 at 10014a44

void Unwind_10014a44(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10014a4c at 10014a4c

void Unwind_10014a4c(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014a54 at 10014a54

void Unwind_10014a54(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10014a5c at 10014a5c

void Unwind_10014a5c(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014a8c at 10014a8c

void Unwind_10014a8c(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10014a94 at 10014a94

void Unwind_10014a94(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10014a9c at 10014a9c

void Unwind_10014a9c(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10014aa4 at 10014aa4

void Unwind_10014aa4(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014aac at 10014aac

void Unwind_10014aac(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10014aaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10014ab5 at 10014ab5

void Unwind_10014ab5(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10014abd at 10014abd

void Unwind_10014abd(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014ac5 at 10014ac5

void Unwind_10014ac5(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10014acd at 10014acd

void Unwind_10014acd(void)

{
  int unaff_EBP;
  
  FUN_10004c09((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10014afd at 10014afd

void Unwind_10014afd(void)

{
  int unaff_EBP;
  
  FUN_10003477(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014b20 at 10014b20

void Unwind_10014b20(void)

{
  int unaff_EBP;
  
  FUN_10009fbc(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014b43 at 10014b43

void Unwind_10014b43(void)

{
  int unaff_EBP;
  
  FUN_10003477(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014b4b at 10014b4b

void Unwind_10014b4b(void)

{
  int unaff_EBP;
  
  FUN_10009fbc(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014b6e at 10014b6e

void Unwind_10014b6e(void)

{
  int unaff_EBP;
  
  FUN_10009ff6((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10014b79 at 10014b79

void Unwind_10014b79(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014b81 at 10014b81

void Unwind_10014b81(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10014ba7 at 10014ba7

void Unwind_10014ba7(void)

{
  int unaff_EBP;
  
  FUN_10009ff6((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10014bb2 at 10014bb2

void Unwind_10014bb2(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10014bbd at 10014bbd

void Unwind_10014bbd(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014bc5 at 10014bc5

void Unwind_10014bc5(void)

{
  int unaff_EBP;
  
  FUN_10009fbc(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014be8 at 10014be8

void Unwind_10014be8(void)

{
  int unaff_EBP;
  
  FUN_100034b4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014bf0 at 10014bf0

void Unwind_10014bf0(void)

{
  int unaff_EBP;
  
  FUN_10004ba8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014bf8 at 10014bf8

void Unwind_10014bf8(void)

{
  int unaff_EBP;
  
  FUN_10004d59(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014c00 at 10014c00

void Unwind_10014c00(void)

{
  int unaff_EBP;
  
  FUN_10004d77(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@10014c0b at 10014c0b

void Unwind_10014c0b(void)

{
  int unaff_EBP;
  
  FUN_100069a2(*(int *)(unaff_EBP + -0x10) + 0xe8);
  return;
}



// Function: Unwind@10014c19 at 10014c19

void Unwind_10014c19(void)

{
  int unaff_EBP;
  
  FUN_100019f2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@10014c24 at 10014c24

void Unwind_10014c24(void)

{
  int unaff_EBP;
  
  FUN_100024a1((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xac));
  return;
}



// Function: Unwind@10014c32 at 10014c32

void Unwind_10014c32(void)

{
  int unaff_EBP;
  
  FUN_10003a38((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xb0));
  return;
}



// Function: Unwind@10014c40 at 10014c40

void Unwind_10014c40(void)

{
  int unaff_EBP;
  
  FUN_1000a079(*(int *)(unaff_EBP + -0x10) + 0xc4);
  return;
}



// Function: Unwind@10014c4e at 10014c4e

void Unwind_10014c4e(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014c56 at 10014c56

void Unwind_10014c56(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x150));
  return;
}



// Function: Unwind@10014c64 at 10014c64

void Unwind_10014c64(void)

{
  int unaff_EBP;
  
  FUN_10011fce((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x158));
  return;
}



// Function: Unwind@10014c8d at 10014c8d

void Unwind_10014c8d(void)

{
  int unaff_EBP;
  
  FUN_10004d59(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014c95 at 10014c95

void Unwind_10014c95(void)

{
  int unaff_EBP;
  
  FUN_10004d77(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@10014ca0 at 10014ca0

void Unwind_10014ca0(void)

{
  int unaff_EBP;
  
  FUN_100069a2(*(int *)(unaff_EBP + -0x10) + 0xe8);
  return;
}



// Function: Unwind@10014cae at 10014cae

void Unwind_10014cae(void)

{
  int unaff_EBP;
  
  FUN_100019f2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x78));
  return;
}



// Function: Unwind@10014cb9 at 10014cb9

void Unwind_10014cb9(void)

{
  int unaff_EBP;
  
  FUN_100024a1((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xac));
  return;
}



// Function: Unwind@10014cc7 at 10014cc7

void Unwind_10014cc7(void)

{
  int unaff_EBP;
  
  FUN_10003a38((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xb0));
  return;
}



// Function: Unwind@10014cd5 at 10014cd5

void Unwind_10014cd5(void)

{
  int unaff_EBP;
  
  FUN_1000a079(*(int *)(unaff_EBP + -0x10) + 0xc4);
  return;
}



// Function: Unwind@10014ce3 at 10014ce3

void Unwind_10014ce3(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(*(int *)(unaff_EBP + -0x10) + 0x150));
  return;
}



// Function: Unwind@10014cf1 at 10014cf1

void Unwind_10014cf1(void)

{
  int unaff_EBP;
  
  FUN_10011fce((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x158));
  return;
}



// Function: Unwind@10014cff at 10014cff

void Unwind_10014cff(void)

{
  int unaff_EBP;
  
  FUN_1000399e(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014d07 at 10014d07

void Unwind_10014d07(void)

{
  int unaff_EBP;
  
  FUN_10003cf1(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10014d0f at 10014d0f

void Unwind_10014d0f(void)

{
  int unaff_EBP;
  
  FUN_10004ba8(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014d17 at 10014d17

void Unwind_10014d17(void)

{
  int unaff_EBP;
  
  FUN_100034b4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014d3a at 10014d3a

void Unwind_10014d3a(void)

{
  DAT_10026010 = DAT_10026010 & 0xfffffffe;
  return;
}



// Function: Unwind@10014d63 at 10014d63

void Unwind_10014d63(void)

{
  int unaff_EBP;
  
  FUN_1000a166(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014d86 at 10014d86

void Unwind_10014d86(void)

{
  int unaff_EBP;
  
  FUN_1000b431(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014da9 at 10014da9

void Unwind_10014da9(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10014ddc at 10014ddc

void Unwind_10014ddc(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014dff at 10014dff

void Unwind_10014dff(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10014e32 at 10014e32

void Unwind_10014e32(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014e70 at 10014e70

void Unwind_10014e70(void)

{
  int unaff_EBP;
  
  FUN_1000ae87(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10014e96 at 10014e96

void Unwind_10014e96(void)

{
  int unaff_EBP;
  
  FUN_1000ae87(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10014ea1 at 10014ea1

void Unwind_10014ea1(void)

{
  int unaff_EBP;
  
  FUN_1000a166(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014ec4 at 10014ec4

void Unwind_10014ec4(void)

{
  FUN_1000b20a();
  return;
}



// Function: Unwind@10014edb at 10014edb

void Unwind_10014edb(void)

{
  FUN_1000b20a();
  return;
}



// Function: Unwind@10014f0e at 10014f0e

void Unwind_10014f0e(void)

{
  int unaff_EBP;
  
  FUN_1000b431(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014f16 at 10014f16

void Unwind_10014f16(void)

{
  int unaff_EBP;
  
  FUN_1000b436(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014f39 at 10014f39

void Unwind_10014f39(void)

{
  int unaff_EBP;
  
  FUN_1000b436(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014f41 at 10014f41

void Unwind_10014f41(void)

{
  int unaff_EBP;
  
  FUN_1000b431(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014f64 at 10014f64

void Unwind_10014f64(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000aea5(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10014f87 at 10014f87

void Unwind_10014f87(void)

{
  int unaff_EBP;
  
  FUN_1000bd18((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10014fad at 10014fad

void Unwind_10014fad(void)

{
  int unaff_EBP;
  
  FUN_1000a60e(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@10014fda at 10014fda

void Unwind_10014fda(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10014fe5 at 10014fe5

void Unwind_10014fe5(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10014ff0 at 10014ff0

void Unwind_10014ff0(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10014ffb at 10014ffb

void Unwind_10014ffb(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10015006 at 10015006

void Unwind_10015006(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10015011 at 10015011

void Unwind_10015011(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1001501c at 1001501c

void Unwind_1001501c(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@10015027 at 10015027

void Unwind_10015027(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@10015032 at 10015032

void Unwind_10015032(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001503d at 1001503d

void Unwind_1001503d(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10015070 at 10015070

void Unwind_10015070(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10015078 at 10015078

void Unwind_10015078(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015080 at 10015080

void Unwind_10015080(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015088 at 10015088

void Unwind_10015088(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015090 at 10015090

void Unwind_10015090(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100150b3 at 100150b3

void Unwind_100150b3(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@100150be at 100150be

void Unwind_100150be(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100150c9 at 100150c9

void Unwind_100150c9(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100150d4 at 100150d4

void Unwind_100150d4(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100150df at 100150df

void Unwind_100150df(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100150ea at 100150ea

void Unwind_100150ea(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001511d at 1001511d

void Unwind_1001511d(void)

{
  int unaff_EBP;
  
  FUN_10001609(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10015128 at 10015128

void Unwind_10015128(void)

{
  int unaff_EBP;
  
  FUN_10001333((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001514e at 1001514e

void Unwind_1001514e(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015156 at 10015156

void Unwind_10015156(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001515e at 1001515e

void Unwind_1001515e(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10015166 at 10015166

void Unwind_10015166(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015189 at 10015189

void Unwind_10015189(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100151ae at 100151ae

void Unwind_100151ae(void)

{
  int unaff_EBP;
  
  FUN_10001333((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100151b9 at 100151b9

void Unwind_100151b9(void)

{
  int unaff_EBP;
  
  FUN_10001609(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100151df at 100151df

void Unwind_100151df(void)

{
  int unaff_EBP;
  
  FUN_1000bb4a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100151e7 at 100151e7

void Unwind_100151e7(void)

{
  int unaff_EBP;
  
  FUN_1000bb4a((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001520a at 1001520a

void Unwind_1001520a(void)

{
  int unaff_EBP;
  
  FUN_1000bb5a((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10015215 at 10015215

void Unwind_10015215(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10015220 at 10015220

void Unwind_10015220(void)

{
  int unaff_EBP;
  
  FUN_1000bb5a((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10015253 at 10015253

void Unwind_10015253(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@1001525e at 1001525e

void Unwind_1001525e(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@10015269 at 10015269

void Unwind_10015269(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@10015274 at 10015274

void Unwind_10015274(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@1001527f at 1001527f

void Unwind_1001527f(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@100152b2 at 100152b2

void Unwind_100152b2(void)

{
  int unaff_EBP;
  
  FUN_10004606((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100152d5 at 100152d5

void Unwind_100152d5(void)

{
  int unaff_EBP;
  
  FUN_1000c843(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100152f8 at 100152f8

void Unwind_100152f8(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10015302 at 10015302

void Unwind_10015302(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10015325 at 10015325

void Unwind_10015325(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001532d at 1001532d

void Unwind_1001532d(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10015335 at 10015335

void Unwind_10015335(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001533d at 1001533d

void Unwind_1001533d(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015345 at 10015345

void Unwind_10015345(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001534d at 1001534d

void Unwind_1001534d(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10015370 at 10015370

void Unwind_10015370(void)

{
  int unaff_EBP;
  
  FUN_10004606((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10015393 at 10015393

void Unwind_10015393(void)

{
  int unaff_EBP;
  
  FUN_10004606((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1001539e at 1001539e

void Unwind_1001539e(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100153a9 at 100153a9

void Unwind_100153a9(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100153b4 at 100153b4

void Unwind_100153b4(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@100153bf at 100153bf

void Unwind_100153bf(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@100153ca at 100153ca

void Unwind_100153ca(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@100153d5 at 100153d5

void Unwind_100153d5(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100153e0 at 100153e0

void Unwind_100153e0(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100153eb at 100153eb

void Unwind_100153eb(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100153f6 at 100153f6

void Unwind_100153f6(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10015401 at 10015401

void Unwind_10015401(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10015434 at 10015434

void Unwind_10015434(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10015457 at 10015457

void Unwind_10015457(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100154b2 at 100154b2

void Unwind_100154b2(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@100154bd at 100154bd

void Unwind_100154bd(void)

{
  int unaff_EBP;
  
  FUN_1000bb5a((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@100154f0 at 100154f0

void Unwind_100154f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000aea5(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100154fb at 100154fb

void Unwind_100154fb(void)

{
  int unaff_EBP;
  
  FUN_1000bd18((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10015506 at 10015506

void Unwind_10015506(void)

{
  int unaff_EBP;
  
  FUN_1000bd42((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@10015511 at 10015511

void Unwind_10015511(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10015544 at 10015544

void Unwind_10015544(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000aea5(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001554f at 1001554f

void Unwind_1001554f(void)

{
  int unaff_EBP;
  
  FUN_1000bd18((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1001555a at 1001555a

void Unwind_1001555a(void)

{
  int unaff_EBP;
  
  FUN_1000bd42((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10015565 at 10015565

void Unwind_10015565(void)

{
  int unaff_EBP;
  
  FUN_10001319((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10015598 at 10015598

void Unwind_10015598(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100155a0 at 100155a0

void Unwind_100155a0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100155cd at 100155cd

void Unwind_100155cd(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@100155d8 at 100155d8

void Unwind_100155d8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@100155e3 at 100155e3

void Unwind_100155e3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10015616 at 10015616

void Unwind_10015616(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001561e at 1001561e

void Unwind_1001561e(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10015626 at 10015626

void Unwind_10015626(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001562e at 1001562e

void Unwind_1001562e(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10015636 at 10015636

void Unwind_10015636(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10015659 at 10015659

void Unwind_10015659(void)

{
  int unaff_EBP;
  
  FUN_10001609(*(int *)(unaff_EBP + -0x10) + 0x70);
  return;
}



// Function: Unwind@10015664 at 10015664

void Unwind_10015664(void)

{
  int unaff_EBP;
  
  FUN_10001c44(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1001566f at 1001566f

void Unwind_1001566f(void)

{
  int unaff_EBP;
  
  FUN_100019f2((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001567a at 1001567a

void Unwind_1001567a(void)

{
  int unaff_EBP;
  
  FUN_10001333((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100156a0 at 100156a0

void Unwind_100156a0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100156a8 at 100156a8

void Unwind_100156a8(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@100156db at 100156db

void Unwind_100156db(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100156e3 at 100156e3

void Unwind_100156e3(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10015716 at 10015716

void Unwind_10015716(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001571e at 1001571e

void Unwind_1001571e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015726 at 10015726

void Unwind_10015726(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10015731 at 10015731

void Unwind_10015731(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10015739 at 10015739

void Unwind_10015739(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@10015744 at 10015744

void Unwind_10015744(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001574c at 1001574c

void Unwind_1001574c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10015754 at 10015754

void Unwind_10015754(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001575c at 1001575c

void Unwind_1001575c(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10015767 at 10015767

void Unwind_10015767(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0xbc));
  return;
}



// Function: Unwind@1001579a at 1001579a

void Unwind_1001579a(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100157a5 at 100157a5

void Unwind_100157a5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@100157d8 at 100157d8

void Unwind_100157d8(void)

{
  int unaff_EBP;
  
  FUN_10002a97((undefined4 *)(unaff_EBP + -0x44c));
  return;
}



// Function: Unwind@100157e3 at 100157e3

void Unwind_100157e3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@10015816 at 10015816

void Unwind_10015816(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001581e at 1001581e

void Unwind_1001581e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10015826 at 10015826

void Unwind_10015826(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001582e at 1001582e

void Unwind_1001582e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10015836 at 10015836

void Unwind_10015836(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10015841 at 10015841

void Unwind_10015841(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10015874 at 10015874

void Unwind_10015874(void)

{
  int unaff_EBP;
  
  FUN_1000fdd0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015897 at 10015897

void Unwind_10015897(void)

{
  int unaff_EBP;
  
  FUN_1000fe18(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100158bd at 100158bd

void Unwind_100158bd(void)

{
  int unaff_EBP;
  
  FUN_1000fe18(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100158c8 at 100158c8

void Unwind_100158c8(void)

{
  int unaff_EBP;
  
  FUN_1000fdd0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100158eb at 100158eb

void Unwind_100158eb(void)

{
  FUN_1000b20a();
  return;
}



// Function: Unwind@1001592f at 1001592f

void Unwind_1001592f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10015954 at 10015954

void Unwind_10015954(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015992 at 10015992

void Unwind_10015992(void)

{
  int unaff_EBP;
  
  FUN_10004bc6(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100159b5 at 100159b5

void Unwind_100159b5(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100159d8 at 100159d8

void Unwind_100159d8(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100159e0 at 100159e0

void Unwind_100159e0(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10015a03 at 10015a03

void Unwind_10015a03(void)

{
  int unaff_EBP;
  
  FUN_1000276f((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10015a26 at 10015a26

void Unwind_10015a26(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015a53 at 10015a53

void Unwind_10015a53(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015a5b at 10015a5b

void Unwind_10015a5b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015a63 at 10015a63

void Unwind_10015a63(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015a6b at 10015a6b

void Unwind_10015a6b(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10015a73 at 10015a73

void Unwind_10015a73(void)

{
  int unaff_EBP;
  
  FUN_10001575((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10015a7b at 10015a7b

void Unwind_10015a7b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015a83 at 10015a83

void Unwind_10015a83(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015a8b at 10015a8b

void Unwind_10015a8b(void)

{
  int unaff_EBP;
  
  FUN_1000399e((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10015ad3 at 10015ad3

void Unwind_10015ad3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10015adb at 10015adb

void Unwind_10015adb(void)

{
  int unaff_EBP;
  
  FUN_10004bc6((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10015ae3 at 10015ae3

void Unwind_10015ae3(void)

{
  int unaff_EBP;
  
  FUN_1000546c((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10015aeb at 10015aeb

void Unwind_10015aeb(void)

{
  int unaff_EBP;
  
  FUN_10004bc6((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10015af3 at 10015af3

void Unwind_10015af3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10015b20 at 10015b20

void Unwind_10015b20(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10015b28 at 10015b28

void Unwind_10015b28(void)

{
  int unaff_EBP;
  
  FUN_10001198((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10015b30 at 10015b30

void Unwind_10015b30(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10015b5d at 10015b5d

void Unwind_10015b5d(void)

{
  FUN_1000b436(0x1002664c);
  return;
}



// Function: Unwind@10015b67 at 10015b67

void Unwind_10015b67(void)

{
  FUN_1000b431(0x1002664c);
  return;
}



// Function: Unwind@10015b8c at 10015b8c

void Unwind_10015b8c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001198(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10015bc0 at 10015bc0

void Unwind_10015bc0(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10015be6 at 10015be6

void Unwind_10015be6(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10015bee at 10015bee

void Unwind_10015bee(void)

{
  int unaff_EBP;
  
  FUN_1000331a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10015c11 at 10015c11

void Unwind_10015c11(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10015c14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_100170fd at 100170fd

void FUN_100170fd(void)

{
  Ordinal_6(DAT_10025780);
  return;
}



// Function: FUN_1001710a at 1001710a

void FUN_1001710a(void)

{
  Ordinal_6(DAT_10025960);
  return;
}



// Function: FUN_10017117 at 10017117

void FUN_10017117(void)

{
  Ordinal_6(DAT_10025964);
  return;
}



// Function: FUN_10017124 at 10017124

void FUN_10017124(void)

{
  Ordinal_6(DAT_10025968);
  return;
}



// Function: FUN_10017131 at 10017131

void FUN_10017131(void)

{
  FID_conflict__Tidy(&DAT_10025710,'\x01',0);
  return;
}



// Function: FUN_10017140 at 10017140

void FUN_10017140(void)

{
  FID_conflict__Tidy(&DAT_1002572c,'\x01',0);
  return;
}



// Function: FUN_1001714f at 1001714f

void FUN_1001714f(void)

{
  FID_conflict__Tidy(&DAT_10025748,'\x01',0);
  return;
}



// Function: FUN_1001715e at 1001715e

void FUN_1001715e(void)

{
  FID_conflict__Tidy(&DAT_10025764,'\x01',0);
  return;
}



// Function: FUN_1001716d at 1001716d

void FUN_1001716d(void)

{
  FID_conflict__Tidy(&DAT_10025784,'\x01',0);
  return;
}



// Function: FUN_1001717c at 1001717c

void FUN_1001717c(void)

{
  FID_conflict__Tidy(&DAT_100257a0,'\x01',0);
  return;
}



// Function: FUN_1001718b at 1001718b

void FUN_1001718b(void)

{
  FID_conflict__Tidy(&DAT_100257bc,'\x01',0);
  return;
}



// Function: FUN_1001719a at 1001719a

void FUN_1001719a(void)

{
  FID_conflict__Tidy(&DAT_100257d8,'\x01',0);
  return;
}



// Function: FUN_100171a9 at 100171a9

void FUN_100171a9(void)

{
  FID_conflict__Tidy(&DAT_100257f4,'\x01',0);
  return;
}



// Function: FUN_100171b8 at 100171b8

void FUN_100171b8(void)

{
  FID_conflict__Tidy(&DAT_10025810,'\x01',0);
  return;
}



// Function: FUN_100171c7 at 100171c7

void FUN_100171c7(void)

{
  FID_conflict__Tidy(&DAT_1002582c,'\x01',0);
  return;
}



// Function: FUN_100171d6 at 100171d6

void FUN_100171d6(void)

{
  FID_conflict__Tidy(&DAT_10025848,'\x01',0);
  return;
}



// Function: FUN_100171e5 at 100171e5

void FUN_100171e5(void)

{
  FID_conflict__Tidy(&DAT_10025864,'\x01',0);
  return;
}



// Function: FUN_100171f4 at 100171f4

void FUN_100171f4(void)

{
  FID_conflict__Tidy(&DAT_10025880,'\x01',0);
  return;
}



// Function: FUN_10017203 at 10017203

void FUN_10017203(void)

{
  FID_conflict__Tidy(&DAT_1002589c,'\x01',0);
  return;
}



// Function: FUN_10017212 at 10017212

void FUN_10017212(void)

{
  FID_conflict__Tidy(&DAT_100258b8,'\x01',0);
  return;
}



// Function: FUN_10017221 at 10017221

void FUN_10017221(void)

{
  FID_conflict__Tidy(&DAT_100258d4,'\x01',0);
  return;
}



// Function: FUN_10017230 at 10017230

void FUN_10017230(void)

{
  FID_conflict__Tidy(&DAT_100258f0,'\x01',0);
  return;
}



// Function: FUN_1001723f at 1001723f

void FUN_1001723f(void)

{
  FID_conflict__Tidy(&DAT_1002590c,'\x01',0);
  return;
}



// Function: FUN_1001724e at 1001724e

void FUN_1001724e(void)

{
  FID_conflict__Tidy(&DAT_10025928,'\x01',0);
  return;
}



// Function: FUN_1001725d at 1001725d

void FUN_1001725d(void)

{
  FID_conflict__Tidy(&DAT_10025944,'\x01',0);
  return;
}



// Function: FUN_1001726c at 1001726c

void FUN_1001726c(void)

{
  Ordinal_6(DAT_10025bf8);
  return;
}



// Function: FUN_10017279 at 10017279

void FUN_10017279(void)

{
  Ordinal_6(DAT_10025bfc);
  return;
}



// Function: FUN_10017286 at 10017286

void FUN_10017286(void)

{
  Ordinal_6(DAT_10025c00);
  return;
}



// Function: FUN_10017293 at 10017293

void FUN_10017293(void)

{
  Ordinal_6(DAT_10025c3c);
  return;
}



// Function: FUN_100172a0 at 100172a0

void FUN_100172a0(void)

{
  Ordinal_6(DAT_10025c40);
  return;
}



// Function: FUN_100172ad at 100172ad

void FUN_100172ad(void)

{
  Ordinal_6(DAT_10025c44);
  return;
}



// Function: FUN_100172ba at 100172ba

void FUN_100172ba(void)

{
  Ordinal_6(DAT_10025c48);
  return;
}



// Function: FUN_100172c7 at 100172c7

void FUN_100172c7(void)

{
  Ordinal_6(DAT_10025c4c);
  return;
}



// Function: FUN_100172d4 at 100172d4

void FUN_100172d4(void)

{
  FID_conflict__Tidy(&DAT_100259a4,'\x01',0);
  return;
}



// Function: FUN_100172e3 at 100172e3

void FUN_100172e3(void)

{
  FID_conflict__Tidy(&DAT_100259c0,'\x01',0);
  return;
}



// Function: FUN_100172f2 at 100172f2

void FUN_100172f2(void)

{
  FID_conflict__Tidy(&DAT_100259dc,'\x01',0);
  return;
}



// Function: FUN_10017301 at 10017301

void FUN_10017301(void)

{
  FID_conflict__Tidy(&DAT_100259f8,'\x01',0);
  return;
}



// Function: FUN_10017310 at 10017310

void FUN_10017310(void)

{
  FID_conflict__Tidy(&DAT_10025a1c,'\x01',0);
  return;
}



// Function: FUN_1001731f at 1001731f

void FUN_1001731f(void)

{
  FID_conflict__Tidy(&DAT_10025a38,'\x01',0);
  return;
}



// Function: FUN_1001732e at 1001732e

void FUN_1001732e(void)

{
  FID_conflict__Tidy(&DAT_10025a54,'\x01',0);
  return;
}



// Function: FUN_1001733d at 1001733d

void FUN_1001733d(void)

{
  FID_conflict__Tidy(&DAT_10025a70,'\x01',0);
  return;
}



// Function: FUN_1001734c at 1001734c

void FUN_1001734c(void)

{
  FID_conflict__Tidy(&DAT_10025a8c,'\x01',0);
  return;
}



// Function: FUN_1001735b at 1001735b

void FUN_1001735b(void)

{
  FID_conflict__Tidy(&DAT_10025aa8,'\x01',0);
  return;
}



// Function: FUN_1001736a at 1001736a

void FUN_1001736a(void)

{
  FID_conflict__Tidy(&DAT_10025ac4,'\x01',0);
  return;
}



// Function: FUN_10017379 at 10017379

void FUN_10017379(void)

{
  FID_conflict__Tidy(&DAT_10025ae0,'\x01',0);
  return;
}



// Function: FUN_10017388 at 10017388

void FUN_10017388(void)

{
  FID_conflict__Tidy(&DAT_10025afc,'\x01',0);
  return;
}



// Function: FUN_10017397 at 10017397

void FUN_10017397(void)

{
  FID_conflict__Tidy(&DAT_10025b18,'\x01',0);
  return;
}



// Function: FUN_100173a6 at 100173a6

void FUN_100173a6(void)

{
  FID_conflict__Tidy(&DAT_10025b34,'\x01',0);
  return;
}



// Function: FUN_100173b5 at 100173b5

void FUN_100173b5(void)

{
  FID_conflict__Tidy(&DAT_10025b50,'\x01',0);
  return;
}



// Function: FUN_100173c4 at 100173c4

void FUN_100173c4(void)

{
  FID_conflict__Tidy(&DAT_10025b6c,'\x01',0);
  return;
}



// Function: FUN_100173d3 at 100173d3

void FUN_100173d3(void)

{
  FID_conflict__Tidy(&DAT_10025b88,'\x01',0);
  return;
}



// Function: FUN_100173e2 at 100173e2

void FUN_100173e2(void)

{
  FID_conflict__Tidy(&DAT_10025ba4,'\x01',0);
  return;
}



// Function: FUN_100173f1 at 100173f1

void FUN_100173f1(void)

{
  FID_conflict__Tidy(&DAT_10025bc0,'\x01',0);
  return;
}



// Function: FUN_10017400 at 10017400

void FUN_10017400(void)

{
  FID_conflict__Tidy(&DAT_10025bdc,'\x01',0);
  return;
}



// Function: FUN_1001740f at 1001740f

void FUN_1001740f(void)

{
  FID_conflict__Tidy(&DAT_10025c04,'\x01',0);
  return;
}



// Function: FUN_1001741e at 1001741e

void FUN_1001741e(void)

{
  FID_conflict__Tidy(&DAT_10025c20,'\x01',0);
  return;
}



// Function: FUN_1001742d at 1001742d

void FUN_1001742d(void)

{
  FID_conflict__Tidy(&DAT_10025c50,'\x01',0);
  return;
}



// Function: FUN_1001743c at 1001743c

void FUN_1001743c(void)

{
  FID_conflict__Tidy(&DAT_10025c6c,'\x01',0);
  return;
}



// Function: FUN_1001744b at 1001744b

void FUN_1001744b(void)

{
  FID_conflict__Tidy(&DAT_10025c88,'\x01',0);
  return;
}



// Function: FUN_1001745a at 1001745a

void FUN_1001745a(void)

{
  FID_conflict__Tidy(&DAT_10025ca4,'\x01',0);
  return;
}



// Function: FUN_10017469 at 10017469

void FUN_10017469(void)

{
  FID_conflict__Tidy(&DAT_10025cc0,'\x01',0);
  return;
}



// Function: FUN_10017478 at 10017478

void FUN_10017478(void)

{
  FID_conflict__Tidy(&DAT_10025cdc,'\x01',0);
  return;
}



// Function: FUN_10017487 at 10017487

void FUN_10017487(void)

{
  FID_conflict__Tidy(&DAT_10025cf8,'\x01',0);
  return;
}



// Function: FUN_10017496 at 10017496

void FUN_10017496(void)

{
  FID_conflict__Tidy(&DAT_10025d14,'\x01',0);
  return;
}



// Function: FUN_100174a5 at 100174a5

void FUN_100174a5(void)

{
  FID_conflict__Tidy(&DAT_10025d30,'\x01',0);
  return;
}



// Function: FUN_100174b4 at 100174b4

void FUN_100174b4(void)

{
  FID_conflict__Tidy(&DAT_10025d4c,'\x01',0);
  return;
}



// Function: FUN_100174c3 at 100174c3

void FUN_100174c3(void)

{
  FID_conflict__Tidy(&DAT_10025d68,'\x01',0);
  return;
}



// Function: FUN_100174d2 at 100174d2

void FUN_100174d2(void)

{
  FID_conflict__Tidy(&DAT_10025d84,'\x01',0);
  return;
}



// Function: FUN_100174e1 at 100174e1

void FUN_100174e1(void)

{
  FID_conflict__Tidy(&DAT_10025da0,'\x01',0);
  return;
}



// Function: FUN_100174f0 at 100174f0

void FUN_100174f0(void)

{
  FID_conflict__Tidy(&DAT_10025dbc,'\x01',0);
  return;
}



// Function: FUN_100174ff at 100174ff

void FUN_100174ff(void)

{
  FID_conflict__Tidy(&DAT_10025dd8,'\x01',0);
  return;
}



// Function: FUN_1001750e at 1001750e

void FUN_1001750e(void)

{
  FID_conflict__Tidy(&DAT_10025df4,'\x01',0);
  return;
}



// Function: FUN_1001751d at 1001751d

void FUN_1001751d(void)

{
  FID_conflict__Tidy(&DAT_10025e10,'\x01',0);
  return;
}



// Function: FUN_1001752c at 1001752c

void FUN_1001752c(void)

{
  FID_conflict__Tidy(&DAT_10025e2c,'\x01',0);
  return;
}



// Function: FUN_1001753b at 1001753b

void FUN_1001753b(void)

{
  FID_conflict__Tidy(&DAT_10025e48,'\x01',0);
  return;
}



// Function: FUN_1001754a at 1001754a

void FUN_1001754a(void)

{
  FID_conflict__Tidy(&DAT_10025e64,'\x01',0);
  return;
}



// Function: FUN_10017559 at 10017559

void FUN_10017559(void)

{
  FID_conflict__Tidy(&DAT_10025e80,'\x01',0);
  return;
}



// Function: FUN_10017568 at 10017568

void FUN_10017568(void)

{
  FID_conflict__Tidy(&DAT_10025e9c,'\x01',0);
  return;
}



// Function: FUN_10017577 at 10017577

void FUN_10017577(void)

{
  FID_conflict__Tidy(&DAT_10025eb8,'\x01',0);
  return;
}



// Function: FUN_10017586 at 10017586

void FUN_10017586(void)

{
  FID_conflict__Tidy(&DAT_10025ed4,'\x01',0);
  return;
}



// Function: FUN_10017595 at 10017595

void FUN_10017595(void)

{
  FID_conflict__Tidy(&DAT_10025ef0,'\x01',0);
  return;
}



// Function: FUN_100175a4 at 100175a4

void FUN_100175a4(void)

{
  FID_conflict__Tidy(&DAT_10025f14,'\x01',0);
  return;
}



// Function: FUN_100175b3 at 100175b3

void FUN_100175b3(void)

{
  FID_conflict__Tidy(&DAT_10025f30,'\x01',0);
  return;
}



// Function: FUN_100175c2 at 100175c2

void FUN_100175c2(void)

{
  FID_conflict__Tidy(&DAT_10025f4c,'\x01',0);
  return;
}



// Function: FUN_100175d1 at 100175d1

void FUN_100175d1(void)

{
  FID_conflict__Tidy(&DAT_10025f68,'\x01',0);
  return;
}



// Function: FUN_100175e0 at 100175e0

void FUN_100175e0(void)

{
  FID_conflict__Tidy(&DAT_10025f84,'\x01',0);
  return;
}



// Function: FUN_100175ef at 100175ef

void FUN_100175ef(void)

{
  FID_conflict__Tidy(&DAT_10025fa0,'\x01',0);
  return;
}



// Function: FUN_100175fe at 100175fe

void FUN_100175fe(void)

{
  FID_conflict__Tidy(&DAT_10025fbc,'\x01',0);
  return;
}



// Function: FUN_1001761c at 1001761c

void FUN_1001761c(void)

{
  if (DAT_10025f0c != (int *)0x0) {
    FUN_1000533b(DAT_10025f0c);
    DAT_10025f0c = (int *)0x0;
  }
  return;
}



// Function: FUN_10017633 at 10017633

void FUN_10017633(void)

{
  if (DAT_10025f10 != (int *)0x0) {
    FUN_1000533b(DAT_10025f10);
    DAT_10025f10 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001764a at 1001764a

void FUN_1001764a(void)

{
  Ordinal_6(DAT_10026268);
  return;
}



// Function: FUN_10017657 at 10017657

void FUN_10017657(void)

{
  Ordinal_6(DAT_1002626c);
  return;
}



// Function: FUN_10017664 at 10017664

void FUN_10017664(void)

{
  Ordinal_6(DAT_10026270);
  return;
}



// Function: FUN_10017671 at 10017671

void FUN_10017671(void)

{
  Ordinal_6(DAT_100262ac);
  return;
}



// Function: FUN_1001767e at 1001767e

void FUN_1001767e(void)

{
  Ordinal_6(DAT_100262b0);
  return;
}



// Function: FUN_1001768b at 1001768b

void FUN_1001768b(void)

{
  Ordinal_6(DAT_100262b4);
  return;
}



// Function: FUN_10017698 at 10017698

void FUN_10017698(void)

{
  Ordinal_6(DAT_100262b8);
  return;
}



// Function: FUN_100176a5 at 100176a5

void FUN_100176a5(void)

{
  Ordinal_6(DAT_100262bc);
  return;
}



// Function: FUN_100176b2 at 100176b2

void FUN_100176b2(void)

{
  Ordinal_6(DAT_10026648);
  return;
}



// Function: FUN_100176bf at 100176bf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100176bf(void)

{
  _DAT_1002664c = ATL::CComModule::vftable;
  FUN_1000b3f8(0x1002664c);
  return;
}



// Function: FUN_100176e9 at 100176e9

void FUN_100176e9(void)

{
  FID_conflict__Tidy(&DAT_10026014,'\x01',0);
  return;
}



// Function: FUN_100176f8 at 100176f8

void FUN_100176f8(void)

{
  FID_conflict__Tidy(&DAT_10026030,'\x01',0);
  return;
}



// Function: FUN_10017707 at 10017707

void FUN_10017707(void)

{
  FID_conflict__Tidy(&DAT_1002604c,'\x01',0);
  return;
}



// Function: FUN_10017716 at 10017716

void FUN_10017716(void)

{
  FID_conflict__Tidy(&DAT_10026068,'\x01',0);
  return;
}



// Function: FUN_10017725 at 10017725

void FUN_10017725(void)

{
  FID_conflict__Tidy(&DAT_1002608c,'\x01',0);
  return;
}



// Function: FUN_10017734 at 10017734

void FUN_10017734(void)

{
  FID_conflict__Tidy(&DAT_100260a8,'\x01',0);
  return;
}



// Function: FUN_10017743 at 10017743

void FUN_10017743(void)

{
  FID_conflict__Tidy(&DAT_100260c4,'\x01',0);
  return;
}



// Function: FUN_10017752 at 10017752

void FUN_10017752(void)

{
  FID_conflict__Tidy(&DAT_100260e0,'\x01',0);
  return;
}



// Function: FUN_10017761 at 10017761

void FUN_10017761(void)

{
  FID_conflict__Tidy(&DAT_100260fc,'\x01',0);
  return;
}



// Function: FUN_10017770 at 10017770

void FUN_10017770(void)

{
  FID_conflict__Tidy(&DAT_10026118,'\x01',0);
  return;
}



// Function: FUN_1001777f at 1001777f

void FUN_1001777f(void)

{
  FID_conflict__Tidy(&DAT_10026134,'\x01',0);
  return;
}



// Function: FUN_1001778e at 1001778e

void FUN_1001778e(void)

{
  FID_conflict__Tidy(&DAT_10026150,'\x01',0);
  return;
}



// Function: FUN_1001779d at 1001779d

void FUN_1001779d(void)

{
  FID_conflict__Tidy(&DAT_1002616c,'\x01',0);
  return;
}



// Function: FUN_100177ac at 100177ac

void FUN_100177ac(void)

{
  FID_conflict__Tidy(&DAT_10026188,'\x01',0);
  return;
}



// Function: FUN_100177bb at 100177bb

void FUN_100177bb(void)

{
  FID_conflict__Tidy(&DAT_100261a4,'\x01',0);
  return;
}



// Function: FUN_100177ca at 100177ca

void FUN_100177ca(void)

{
  FID_conflict__Tidy(&DAT_100261c0,'\x01',0);
  return;
}



// Function: FUN_100177d9 at 100177d9

void FUN_100177d9(void)

{
  FID_conflict__Tidy(&DAT_100261dc,'\x01',0);
  return;
}



// Function: FUN_100177e8 at 100177e8

void FUN_100177e8(void)

{
  FID_conflict__Tidy(&DAT_100261f8,'\x01',0);
  return;
}



// Function: FUN_100177f7 at 100177f7

void FUN_100177f7(void)

{
  FID_conflict__Tidy(&DAT_10026214,'\x01',0);
  return;
}



// Function: FUN_10017806 at 10017806

void FUN_10017806(void)

{
  FID_conflict__Tidy(&DAT_10026230,'\x01',0);
  return;
}



// Function: FUN_10017815 at 10017815

void FUN_10017815(void)

{
  FID_conflict__Tidy(&DAT_1002624c,'\x01',0);
  return;
}



// Function: FUN_10017824 at 10017824

void FUN_10017824(void)

{
  FID_conflict__Tidy(&DAT_10026274,'\x01',0);
  return;
}



// Function: FUN_10017833 at 10017833

void FUN_10017833(void)

{
  FID_conflict__Tidy(&DAT_10026290,'\x01',0);
  return;
}



// Function: FUN_10017842 at 10017842

void FUN_10017842(void)

{
  FID_conflict__Tidy(&DAT_100262c0,'\x01',0);
  return;
}



// Function: FUN_10017851 at 10017851

void FUN_10017851(void)

{
  FID_conflict__Tidy(&DAT_100262dc,'\x01',0);
  return;
}



// Function: FUN_10017860 at 10017860

void FUN_10017860(void)

{
  FID_conflict__Tidy(&DAT_100262f8,'\x01',0);
  return;
}



// Function: FUN_1001786f at 1001786f

void FUN_1001786f(void)

{
  FID_conflict__Tidy(&DAT_10026314,'\x01',0);
  return;
}



// Function: FUN_1001787e at 1001787e

void FUN_1001787e(void)

{
  FID_conflict__Tidy(&DAT_10026330,'\x01',0);
  return;
}



// Function: FUN_1001788d at 1001788d

void FUN_1001788d(void)

{
  FID_conflict__Tidy(&DAT_1002634c,'\x01',0);
  return;
}



// Function: FUN_1001789c at 1001789c

void FUN_1001789c(void)

{
  FID_conflict__Tidy(&DAT_10026368,'\x01',0);
  return;
}



// Function: FUN_100178ab at 100178ab

void FUN_100178ab(void)

{
  FID_conflict__Tidy(&DAT_10026384,'\x01',0);
  return;
}



// Function: FUN_100178ba at 100178ba

void FUN_100178ba(void)

{
  FID_conflict__Tidy(&DAT_100263a0,'\x01',0);
  return;
}



// Function: FUN_100178c9 at 100178c9

void FUN_100178c9(void)

{
  FID_conflict__Tidy(&DAT_100263bc,'\x01',0);
  return;
}



// Function: FUN_100178d8 at 100178d8

void FUN_100178d8(void)

{
  FID_conflict__Tidy(&DAT_100263d8,'\x01',0);
  return;
}



// Function: FUN_100178e7 at 100178e7

void FUN_100178e7(void)

{
  FID_conflict__Tidy(&DAT_100263f4,'\x01',0);
  return;
}



// Function: FUN_100178f6 at 100178f6

void FUN_100178f6(void)

{
  FID_conflict__Tidy(&DAT_10026410,'\x01',0);
  return;
}



// Function: FUN_10017905 at 10017905

void FUN_10017905(void)

{
  FID_conflict__Tidy(&DAT_1002642c,'\x01',0);
  return;
}



// Function: FUN_10017914 at 10017914

void FUN_10017914(void)

{
  FID_conflict__Tidy(&DAT_10026448,'\x01',0);
  return;
}



// Function: FUN_10017923 at 10017923

void FUN_10017923(void)

{
  FID_conflict__Tidy(&DAT_10026464,'\x01',0);
  return;
}



// Function: FUN_10017932 at 10017932

void FUN_10017932(void)

{
  FID_conflict__Tidy(&DAT_10026480,'\x01',0);
  return;
}



// Function: FUN_10017941 at 10017941

void FUN_10017941(void)

{
  FID_conflict__Tidy(&DAT_1002649c,'\x01',0);
  return;
}



// Function: FUN_10017950 at 10017950

void FUN_10017950(void)

{
  FID_conflict__Tidy(&DAT_100264b8,'\x01',0);
  return;
}



// Function: FUN_1001795f at 1001795f

void FUN_1001795f(void)

{
  FID_conflict__Tidy(&DAT_100264d4,'\x01',0);
  return;
}



// Function: FUN_1001796e at 1001796e

void FUN_1001796e(void)

{
  FID_conflict__Tidy(&DAT_100264f0,'\x01',0);
  return;
}



// Function: FUN_1001797d at 1001797d

void FUN_1001797d(void)

{
  FID_conflict__Tidy(&DAT_1002650c,'\x01',0);
  return;
}



// Function: FUN_1001798c at 1001798c

void FUN_1001798c(void)

{
  FID_conflict__Tidy(&DAT_10026528,'\x01',0);
  return;
}



// Function: FUN_1001799b at 1001799b

void FUN_1001799b(void)

{
  FID_conflict__Tidy(&DAT_10026544,'\x01',0);
  return;
}



// Function: FUN_100179aa at 100179aa

void FUN_100179aa(void)

{
  FID_conflict__Tidy(&DAT_10026560,'\x01',0);
  return;
}



// Function: FUN_100179b9 at 100179b9

void FUN_100179b9(void)

{
  FID_conflict__Tidy(&DAT_10026584,'\x01',0);
  return;
}



// Function: FUN_100179c8 at 100179c8

void FUN_100179c8(void)

{
  FID_conflict__Tidy(&DAT_100265a0,'\x01',0);
  return;
}



// Function: FUN_100179d7 at 100179d7

void FUN_100179d7(void)

{
  FID_conflict__Tidy(&DAT_100265bc,'\x01',0);
  return;
}



// Function: FUN_100179e6 at 100179e6

void FUN_100179e6(void)

{
  FID_conflict__Tidy(&DAT_100265d8,'\x01',0);
  return;
}



// Function: FUN_100179f5 at 100179f5

void FUN_100179f5(void)

{
  FID_conflict__Tidy(&DAT_100265f4,'\x01',0);
  return;
}



// Function: FUN_10017a04 at 10017a04

void FUN_10017a04(void)

{
  FID_conflict__Tidy(&DAT_10026610,'\x01',0);
  return;
}



// Function: FUN_10017a13 at 10017a13

void FUN_10017a13(void)

{
  FID_conflict__Tidy(&DAT_1002662c,'\x01',0);
  return;
}



// Function: FUN_10017a22 at 10017a22

void FUN_10017a22(void)

{
  if (DAT_1002657c != (int *)0x0) {
    FUN_1000533b(DAT_1002657c);
    DAT_1002657c = (int *)0x0;
  }
  return;
}



// Function: FUN_10017a39 at 10017a39

void FUN_10017a39(void)

{
  if (DAT_10026580 != (int *)0x0) {
    FUN_1000533b(DAT_10026580);
    DAT_10026580 = (int *)0x0;
  }
  return;
}



// Function: FUN_10017a50 at 10017a50

void FUN_10017a50(void)

{
  Ordinal_6(DAT_100267b0);
  return;
}



// Function: FUN_10017a5d at 10017a5d

void FUN_10017a5d(void)

{
  Ordinal_6(DAT_100268cc);
  return;
}



// Function: FUN_10017a6a at 10017a6a

void FUN_10017a6a(void)

{
  Ordinal_6(DAT_100268d0);
  return;
}



// Function: FUN_10017a77 at 10017a77

void FUN_10017a77(void)

{
  FID_conflict__Tidy(&DAT_100266b4,'\x01',0);
  return;
}



// Function: FUN_10017a86 at 10017a86

void FUN_10017a86(void)

{
  FID_conflict__Tidy(&DAT_10026698,'\x01',0);
  return;
}



// Function: FUN_10017a95 at 10017a95

void FUN_10017a95(void)

{
  FID_conflict__Tidy(&DAT_1002667c,'\x01',0);
  return;
}



// Function: FUN_10017aa4 at 10017aa4

void FUN_10017aa4(void)

{
  FID_conflict__Tidy(&DAT_10026840,'\x01',0);
  return;
}



// Function: FUN_10017ab3 at 10017ab3

void FUN_10017ab3(void)

{
  FID_conflict__Tidy(&DAT_10026794,'\x01',0);
  return;
}



// Function: FUN_10017ac2 at 10017ac2

void FUN_10017ac2(void)

{
  FID_conflict__Tidy(&DAT_10026894,'\x01',0);
  return;
}



// Function: FUN_10017ad1 at 10017ad1

void FUN_10017ad1(void)

{
  FID_conflict__Tidy(&DAT_100266d0,'\x01',0);
  return;
}



// Function: FUN_10017ae0 at 10017ae0

void FUN_10017ae0(void)

{
  FID_conflict__Tidy(&DAT_100267ec,'\x01',0);
  return;
}



// Function: FUN_10017aef at 10017aef

void FUN_10017aef(void)

{
  FID_conflict__Tidy(&DAT_1002685c,'\x01',0);
  return;
}



// Function: FUN_10017afe at 10017afe

void FUN_10017afe(void)

{
  FID_conflict__Tidy(&DAT_10026824,'\x01',0);
  return;
}



// Function: FUN_10017b0d at 10017b0d

void FUN_10017b0d(void)

{
  FID_conflict__Tidy(&DAT_10026878,'\x01',0);
  return;
}



// Function: FUN_10017b1c at 10017b1c

void FUN_10017b1c(void)

{
  FID_conflict__Tidy(&DAT_100267b4,'\x01',0);
  return;
}



// Function: FUN_10017b2b at 10017b2b

void FUN_10017b2b(void)

{
  FID_conflict__Tidy(&DAT_10026778,'\x01',0);
  return;
}



// Function: FUN_10017b3a at 10017b3a

void FUN_10017b3a(void)

{
  FID_conflict__Tidy(&DAT_100266ec,'\x01',0);
  return;
}



// Function: FUN_10017b49 at 10017b49

void FUN_10017b49(void)

{
  FID_conflict__Tidy(&DAT_100267d0,'\x01',0);
  return;
}



// Function: FUN_10017b58 at 10017b58

void FUN_10017b58(void)

{
  FID_conflict__Tidy(&DAT_10026708,'\x01',0);
  return;
}



// Function: FUN_10017b67 at 10017b67

void FUN_10017b67(void)

{
  FID_conflict__Tidy(&DAT_10026740,'\x01',0);
  return;
}



// Function: FUN_10017b76 at 10017b76

void FUN_10017b76(void)

{
  FID_conflict__Tidy(&DAT_10026808,'\x01',0);
  return;
}



// Function: FUN_10017b85 at 10017b85

void FUN_10017b85(void)

{
  FID_conflict__Tidy(&DAT_100268b0,'\x01',0);
  return;
}



// Function: FUN_10017b94 at 10017b94

void FUN_10017b94(void)

{
  FID_conflict__Tidy(&DAT_10026724,'\x01',0);
  return;
}



// Function: FUN_10017ba3 at 10017ba3

void FUN_10017ba3(void)

{
  FID_conflict__Tidy(&DAT_1002675c,'\x01',0);
  return;
}



// Function: FUN_10017bb2 at 10017bb2

void FUN_10017bb2(void)

{
  FUN_10012163(0x100268d4);
  return;
}



// Function: FUN_10017bbc at 10017bbc

void FUN_10017bbc(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_10026910,DAT_100268d8);
  RemoveAll((undefined4 *)&DAT_10026930);
  return;
}



// Function: FUN_10017bd6 at 10017bd6

void FUN_10017bd6(void)

{
  FUN_10012471((int *)&DAT_1002693c);
  return;
}



// Function: FUN_10017be0 at 10017be0

void FUN_10017be0(void)

{
  FUN_10012661();
  return;
}



