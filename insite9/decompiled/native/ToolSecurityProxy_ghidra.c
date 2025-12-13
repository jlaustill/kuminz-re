/*
 * Decompiled from: ToolSecurityProxy.dll
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
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_1000d53c);
}



// Function: FUN_100010a5 at 100010a5

int * FUN_100010a5(int *param_1,int *param_2)

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



// Function: FUN_100010d8 at 100010d8

void __fastcall FUN_100010d8(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_100010e1 at 100010e1

undefined4 FUN_100010e1(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10010058 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000110d at 1000110d

void __thiscall FUN_1000110d(void *this,LPCOLESTR param_1,LPUNKNOWN param_2,DWORD param_3)

{
  HRESULT HVar1;
  CLSID local_18;
  uint local_8;
  
  local_8 = DAT_10010d90 ^ (uint)&stack0xfffffffc;
  HVar1 = CLSIDFromProgID(param_1,&local_18);
  if (-1 < HVar1) {
    CoCreateInstance(&local_18,param_2,param_3,(IID *)&DAT_1000b414,(LPVOID *)this);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000115a at 1000115a

void __fastcall FUN_1000115a(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FID_conflict:_Inside at 10001167

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



// Function: FUN_100011a3 at 100011a3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100011a3(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100011af;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1000d570);
}



// Function: FUN_10001234 at 10001234

void __fastcall FUN_10001234(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_10001251 at 10001251

void __fastcall FUN_10001251(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10001259 at 10001259

undefined2 * __thiscall FUN_10001259(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_10001271;
  while( true ) {
    FUN_1000108d(iVar1);
LAB_10001271:
    *(undefined2 *)this = 8;
    iVar1 = FUN_10001234(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (*param_1 == 0)) break;
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
  return (undefined2 *)this;
}



// Function: FUN_100012a4 at 100012a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100012a4(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FID_conflict:_Tidy at 100012c9

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



// Function: FUN_10001312 at 10001312

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10001312(void *this,uint param_1)

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
  FUN_100011a3((char *)(param_1 + 1));
  FUN_100013a7();
  return;
}



// Function: Catch@10001379 at 10001379

undefined * Catch_10001379(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100011a3((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100013a1;
}



// Function: FUN_100013a7 at 100013a7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100013a7(void)

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



// Function: Catch@100013f5 at 100013f5

void Catch_100013f5(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: ~basic_string<> at 1000140a

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



// Function: FUN_10001414 at 10001414

undefined4 * __thiscall FUN_10001414(void *this,uint param_1,uint param_2)

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



// Function: FUN_10001495 at 10001495

bool __thiscall FUN_10001495(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001312(this,param_1);
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



// Function: FUN_100014ff at 100014ff

undefined4 * __thiscall FUN_100014ff(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10001414(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10001414(this,0,param_2);
  }
  else {
    bVar1 = FUN_10001495(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 1000159b

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
    bVar1 = FUN_10001495(this,param_2,'\0');
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
    this = FUN_100014ff(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001619 at 10001619

undefined2 * __thiscall FUN_10001619(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_1000164b at 1000164b

void __cdecl FUN_1000164b(undefined4 param_1,void *param_2)

{
  FID_conflict__Tidy(param_2,'\x01',0);
  return;
}



// Function: FUN_1000165c at 1000165c

undefined4 FUN_1000165c(int param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FID_conflict_assign((void *)(param_1 + 0x30),(undefined4 *)param_2,sVar1);
  return 0;
}



// Function: FUN_1000167e at 1000167e

void __cdecl FUN_1000167e(void *param_1,void *param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = (void *)((int)param_1 + 0x1c)) {
    FUN_1000164b(param_3,param_1);
  }
  return;
}



// Function: FUN_1000169d at 1000169d

void __fastcall FUN_1000169d(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FUN_1000167e((void *)*param_1,(void *)param_1[1],param_1 + 3);
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_100016d2 at 100016d2

void __fastcall FUN_100016d2(int *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FUN_1000167e((void *)*param_1,(void *)param_1[1],param_1 + 3);
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_100016d7 at 100016d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100016d7(void *this,LPCOLESTR param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LPCOLESTR pOVar5;
  int iVar6;
  int *piVar7;
  uint local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 uStack_60;
  uint *local_5c;
  uint *local_58;
  undefined4 local_54;
  undefined4 local_4c;
  LPCOLESTR local_48;
  undefined4 local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  uint *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8._0_1_ = 0xe3;
  local_8._1_3_ = 0x100016;
  local_24 = (uint *)this;
  (*(code *)**(undefined4 **)param_1)(param_1,&DAT_1000b434,(int)this + 4);
  pOVar5 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
  param_1 = pOVar5;
  if (pOVar5 != (LPCOLESTR)0x0) goto LAB_10001719;
  do {
    do {
      FUN_1000108d(0x8007000e);
LAB_10001719:
      local_8 = 0;
      FUN_1000110d((uint *)((int)this + 8),pOVar5,(LPUNKNOWN)0x0,0x17);
      local_8 = 0xffffffff;
      Ordinal_6(pOVar5);
      uVar3 = uStack_60;
      uVar2 = uStack_68;
      local_3c = (int *)0x0;
      local_18 = (int *)0x0;
      local_28 = (int *)0x0;
      local_8._1_3_ = 0;
      local_6c = CONCAT22(local_6c._2_2_,3);
      uVar1 = local_6c;
      local_64 = 1;
      local_8._0_1_ = 7;
      this = &local_6c;
      pOVar5 = (LPCOLESTR)local_24[2];
      param_1 = pOVar5;
      local_40 = (int *)Ordinal_2(L"LicenseFile");
    } while (local_40 == (int *)0x0);
    local_8._0_1_ = 8;
    (**(code **)(*(int *)pOVar5 + 0xe0))(param_1,uVar1,uVar2,1,uVar3,local_40,0,&local_18);
    local_8._0_1_ = 7;
    Ordinal_6(local_40);
    local_8 = CONCAT31(local_8._1_3_,6);
    Ordinal_9(&local_6c);
    (*(code *)**(undefined4 **)local_24[2])((undefined4 *)local_24[2],&DAT_1000b444,&local_28);
    (**(code **)(*local_28 + 0x54))(local_28,local_18,&local_3c);
    piVar7 = local_18;
    if (local_18 != (int *)0x0) {
      local_18 = (int *)0x0;
      (**(code **)(*piVar7 + 8))(piVar7);
    }
    local_44 = 0;
    local_8._0_1_ = 9;
    local_1c = (**(code **)(*local_28 + 0x88))(local_28,&local_44);
    local_5c = (uint *)0x0;
    local_58 = (uint *)0x0;
    local_54 = 0;
    local_8 = CONCAT31(local_8._1_3_,10);
    iVar6 = __RTDynamicCast(local_24,0,
                            &CComSecurity<class_CLicenseManagerImpl>::RTTI_Type_Descriptor,
                            &CLicenseManagerImpl::RTTI_Type_Descriptor,0);
    (**(code **)(*(int *)(iVar6 + 0xc) + 0x18))(&local_5c);
    local_24 = local_5c;
    if (local_5c == local_58) {
LAB_10001a7a:
      local_8._0_1_ = 9;
      FUN_1000169d(&local_5c);
      local_8._0_1_ = 6;
      Ordinal_6(local_44);
      local_8._0_1_ = 4;
      if (local_28 != (int *)0x0) {
        (**(code **)(*local_28 + 8))(local_28);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_8 = 0xffffffff;
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      return local_1c;
    }
    while( true ) {
      this = local_24;
      if (local_1c < 0) goto LAB_10001a7a;
      local_20 = (int *)0x0;
      local_8._0_1_ = 0xc;
      pOVar5 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
      local_48 = pOVar5;
      if (pOVar5 == (LPCOLESTR)0x0) break;
      local_8._0_1_ = 0xd;
      FUN_1000110d(&local_20,pOVar5,(LPUNKNOWN)0x0,0x17);
      local_8._0_1_ = 0xc;
      Ordinal_6(pOVar5);
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        this = *this;
      }
      if ((uint *)this == (uint *)0x0) {
        local_2c = 0;
      }
      else {
        local_2c = Ordinal_2(this);
        if (local_2c == 0) break;
      }
      local_8._0_1_ = 0xe;
      local_6c = local_6c & 0xffff0000;
      FUN_10001259(&local_6c,&local_2c);
      local_8._0_1_ = 0xf;
      (**(code **)(*local_20 + 0xe8))(local_20,local_6c,uStack_68,local_64,uStack_60,&param_1);
      local_8._0_1_ = 0xe;
      Ordinal_9(&local_6c);
      local_8._0_1_ = 0xc;
      Ordinal_6(local_2c);
      if ((short)param_1 == -1) {
        local_38 = (int *)0x0;
        local_8._0_1_ = 0x11;
        (**(code **)*local_20)(local_20,&DAT_1000b444,&local_38);
        local_34 = (int *)0x0;
        local_8._0_1_ = 0x13;
        local_1c = (**(code **)(*local_38 + 0x34))(local_38,&local_34);
        local_14[0] = (int *)0x0;
        piVar7 = (int *)0x0;
        local_40 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x17);
        iVar6 = (**(code **)(*local_34 + 0x34))(local_34,local_14);
        while (((-1 < local_1c && (-1 < iVar6)) && (local_14[0] != (int *)0x0))) {
          local_4c = 0;
          local_30 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x1a);
          (**(code **)(*local_14[0] + 0x60))(local_14[0],0xffffffff,&local_30);
          local_1c = (**(code **)(*local_3c + 0x54))(local_3c,local_30,&local_18);
          piVar4 = local_18;
          if (local_18 != (int *)0x0) {
            local_18 = (int *)0x0;
            (**(code **)(*piVar4 + 8))(piVar4);
          }
          if (piVar7 != local_14[0]) {
            FUN_100010a5((int *)&local_40,local_14[0]);
            piVar7 = local_40;
          }
          piVar4 = local_14[0];
          if (local_14[0] != (int *)0x0) {
            local_14[0] = (int *)0x0;
            (**(code **)(*piVar4 + 8))(piVar4);
            if (local_14[0] != (int *)0x0) {
              local_14[0] = (int *)0x0;
            }
          }
          local_8._0_1_ = 0x18;
          if (local_30 != (int *)0x0) {
            (**(code **)(*local_30 + 8))(local_30);
          }
          local_8 = CONCAT31(local_8._1_3_,0x17);
          Ordinal_6(0);
          iVar6 = (**(code **)(*piVar7 + 0x40))(piVar7,local_14);
        }
        local_8._0_1_ = 0x15;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 8))(piVar7);
        }
        local_8._0_1_ = 0x13;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_8._0_1_ = 0x11;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))(local_34);
        }
        local_8._0_1_ = 0xc;
        if (local_38 != (int *)0x0) {
          (**(code **)(*local_38 + 8))(local_38);
        }
      }
      else {
        local_1c = -0x7fffbffb;
      }
      local_8 = CONCAT31(local_8._1_3_,10);
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      local_24 = local_24 + 7;
      if (local_24 == local_58) goto LAB_10001a7a;
    }
  } while( true );
}



// Function: FUN_10001ad1 at 10001ad1

void FUN_10001ad1(int param_1,LPCOLESTR param_2)

{
  FUN_100016d7((void *)(param_1 + 4),param_2);
  return;
}



// Function: FUN_10001b07 at 10001b07

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10001b07(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10001ae6);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10001b64 at 10001b64

bool __cdecl FUN_10001b64(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 10001b7e

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



// Function: AtlCoTaskMemCAlloc at 10001ba0

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



// Function: FUN_10001bcd at 10001bcd

LPVOID __cdecl FUN_10001bcd(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10001bfd at 10001bfd

bool __cdecl FUN_10001bfd(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: AtlCrtErrorCheck at 10001c2a

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
    if (param_1 == 0x16) goto LAB_10001c52;
    if (param_1 == 0x22) goto LAB_10001c52;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_1000108d(uVar1);
LAB_10001c52:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_10001c62 at 10001c62

void __cdecl FUN_10001c62(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10001c82 at 10001c82

void __cdecl FUN_10001c82(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 10001c9f

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



// Function: FUN_10001cc8 at 10001cc8

void __fastcall FUN_10001cc8(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10001cda at 10001cda

DWORD FUN_10001cda(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10001cef at 10001cef

uint __cdecl FUN_10001cef(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FID_conflict:RegOpenKeyExA at 10001d05

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
                    /* WARNING: Could not recover jumptable at 0x10001d4e. Too many branches */
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



// Function: FID_conflict:RegCreateKeyExW at 10001d5c

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
                    /* WARNING: Could not recover jumptable at 0x10001db1. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 10001dbf

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
                    /* WARNING: Could not recover jumptable at 0x10001e02. Too many branches */
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



// Function: FUN_10001e11 at 10001e11

undefined4 __fastcall FUN_10001e11(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10001e15 at 10001e15

void __cdecl FUN_10001e15(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10001e63 at 10001e63

int __fastcall FUN_10001e63(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 10001e7a

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10010e44 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10010e40 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10010e44 = '\x01';
    }
    if (DAT_10010e40 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10010e40)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Close at 10001eea

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



// Function: Create at 10001f05

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



// Function: Open at 10001f6d

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



// Function: SetStringValue at 10001fbc

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



// Function: FUN_10001ff3 at 10001ff3

LSTATUS __thiscall FUN_10001ff3(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: DllCanUnloadNow at 10002036

HRESULT DllCanUnloadNow(void)

{
                    /* 0x2036  1  DllCanUnloadNow */
  return (uint)(DAT_10010ee4 != 0);
}



// Function: FUN_10002045 at 10002045

undefined4 __fastcall FUN_10002045(undefined4 *param_1)

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



// Function: FUN_10002065 at 10002065

undefined4 * __thiscall FUN_10002065(void *this,ulong param_1)

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



// Function: FUN_1000209b at 1000209b

void __fastcall FUN_1000209b(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100020a5 at 100020a5

undefined4 __thiscall FUN_100020a5(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10001bcd(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10001c62((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10002133 at 10002133

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10002133(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x1000213f;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10010e68 & 1) == 0) {
    DAT_10010e68 = DAT_10010e68 | 1;
    DAT_10010e4c = 8;
    _DAT_10010e54 = 0x4008;
    _DAT_10010e5c = 0x13;
    DAT_10010e48 = &DAT_1000b39c;
    DAT_10010e50 = &DAT_1000b398;
    _DAT_10010e58 = &DAT_1000b394;
    _DAT_10010e60 = &DAT_1000b390;
    _DAT_10010e64 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10010e48)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x100021b6;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_10010e4c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_100021c2;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_100021c2:
  *(undefined4 *)(puVar4 + -4) = 0x100021c7;
  return uVar2;
}



// Function: FUN_100021db at 100021db

int __cdecl FUN_100021db(ushort param_1)

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



// Function: FUN_10002211 at 10002211

undefined4 __cdecl FUN_10002211(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1000b748)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1000b74c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_1000223f at 1000223f

LPCWSTR __cdecl FUN_1000223f(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_1000226c at 1000226c

undefined4 FUN_1000226c(ushort param_1)

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



// Function: FUN_10002292 at 10002292

void __fastcall FUN_10002292(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_1000226c(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_100022b4 at 100022b4

undefined4 __thiscall FUN_100022b4(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10002292((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10002045((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_1000226c(*pWVar2);
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



// Function: FUN_100023ca at 100023ca

undefined4 FUN_100023ca(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1000b3c0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1000b3f0);
  return 1;
}



// Function: FUN_100023f9 at 100023f9

bool FUN_100023f9(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_1000242e at 1000242e

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000242e(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10010d90 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_100022b4(this,param_1), -1 < iVar1)) {
    FUN_10002292((undefined4 *)this);
    iVar1 = FUN_100022b4(this,local_2008);
    if (-1 < iVar1) {
      FUN_100022b4(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002493 at 10002493

undefined4 FUN_10002493(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10010da8;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100024b2 at 100024b2

undefined4 __thiscall FUN_100024b2(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10010e2c = *param_3;
    DAT_10010e30 = param_3[1];
    DAT_10010e34 = param_3[2];
    DAT_10010e38 = param_3[3];
  }
  piVar2 = DAT_10010f14;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10010f14, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10010f14 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10010f14;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10010f18; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10002510 at 10002510

void FUN_10002510(int param_1)

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



// Function: FUN_10002553 at 10002553

void __fastcall FUN_10002553(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_1000256b at 1000256b

void __fastcall FUN_1000256b(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10002585 at 10002585

void __fastcall FUN_10002585(undefined4 *param_1)

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



// Function: FUN_100025b2 at 100025b2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_100025b2(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_100099f3;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_100025dc at 100025dc

int __thiscall FUN_100025dc(void *this,undefined4 *param_1)

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



// Function: FUN_10002613 at 10002613

void __fastcall FUN_10002613(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_1000261d at 1000261d

void __thiscall FUN_1000261d(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_1000108d(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10002642

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_1000108d(lVar1);
  }
  return local_8;
}



// Function: FUN_10002667 at 10002667

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10002667(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10002695 at 10002695

int __fastcall FUN_10002695(int param_1)

{
  long lVar1;
  
  FUN_10001e63(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10010dac = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10010e20 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_100026d6 at 100026d6

void __fastcall FUN_100026d6(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002510((int)piVar1);
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



// Function: FUN_1000270f at 1000270f

void __fastcall FUN_1000270f(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002510((int)piVar1);
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



// Function: FUN_10002714 at 10002714

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002714(int param_1)

{
  FUN_100026d6(param_1);
  return;
}



// Function: FUN_10002732 at 10002732

LSTATUS __fastcall FUN_10002732(undefined4 *param_1)

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



// Function: FUN_10002737 at 10002737

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10002737(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10002737(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_10008d05();
  return;
}



// Function: FUN_1000281c at 1000281c

undefined4 __fastcall FUN_1000281c(int *param_1)

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
LAB_10002861:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_10002861;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10002585(param_1);
  return 0;
}



// Function: FUN_10002873 at 10002873

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10002873(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_100020a5(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_1000256b(local_14);
  }
  return uVar1;
}



// Function: FUN_100028ba at 100028ba

void FUN_100028ba(int param_1)

{
  FUN_1000281c((int *)(param_1 + 4));
  return;
}



// Function: FUN_100028cc at 100028cc

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100028cc(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x100028db;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_10002aa6;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_10001cda();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_10002939;
      FUN_10001c82(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_10002a76;
      }
    }
    else {
LAB_10002a76:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_10002939:
  local_8 = 0xffffffff;
  FUN_1000256b(&local_248);
LAB_10002aa6:
  FUN_10008d05();
  return;
}



// Function: FUN_10002aae at 10002aae

void __fastcall FUN_10002aae(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10010f14;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10010f14, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10010f18; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_100026d6(param_1);
  return;
}



// Function: FUN_10002b00 at 10002b00

void __fastcall FUN_10002b00(undefined4 *param_1)

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



// Function: FUN_10002b05 at 10002b05

void __fastcall FUN_10002b05(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10002b15 at 10002b15

void __fastcall FUN_10002b15(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10002613(param_1);
    return;
  }
  return;
}



// Function: FUN_10002b22 at 10002b22

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002b22(int param_1)

{
  FUN_100025b2((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10002b43 at 10002b43

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10002b43(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_10002b97 at 10002b97

void __fastcall FUN_10002b97(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10002bae at 10002bae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002bae(int param_1)

{
  FUN_100025b2((LPCRITICAL_SECTION)(param_1 + 0x14));
  return;
}



// Function: FUN_10002bd9 at 10002bd9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002bd9(int param_1)

{
  FUN_10002bae(param_1);
  return;
}



// Function: FUN_10002bf7 at 10002bf7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10002bf7(undefined4 *param_1)

{
  FUN_10002695((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10010e3c = param_1;
  return param_1;
}



// Function: FUN_10002c2c at 10002c2c

void __fastcall FUN_10002c2c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10002c37 at 10002c37

void __fastcall FUN_10002c37(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10002c42 at 10002c42

HRESULT __thiscall FUN_10002c42(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1000c028,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000b938,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10002c8e at 10002c8e

undefined4 FUN_10002c8e(void)

{
  return 0x80004005;
}



// Function: FUN_10002c96 at 10002c96

void FUN_10002c96(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_1000b948);
  return;
}



// Function: FUN_10002cb0 at 10002cb0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10002cb0(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_100026d6((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002ce7 at 10002ce7

undefined4 FUN_10002ce7(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_100024b2(&DAT_10010edc,(int *)&PTR_DAT_100100b8,param_1,(undefined4 *)&DAT_1000b634);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10002aae(0x10010edc);
  }
  return 1;
}



// Function: FUN_10002d29 at 10002d29

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002d29(int *param_1)

{
  FUN_1000281c(param_1);
  FUN_10002585(param_1);
  return;
}



// Function: FUN_10002d53 at 10002d53

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002d53(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_1000281c(param_1 + 1);
  FUN_10002d29(param_1 + 1);
  return;
}



// Function: FUN_10002d87 at 10002d87

undefined4 FUN_10002d87(void)

{
  return 0x80004001;
}



// Function: FUN_10002d8f at 10002d8f

undefined4 FUN_10002d8f(void)

{
  return 1;
}



// Function: FUN_10002d95 at 10002d95

undefined4 FUN_10002d95(void)

{
  return 0;
}



// Function: FUN_10002d9a at 10002d9a

undefined4 * __thiscall FUN_10002d9a(void *this,byte param_1)

{
  FUN_10002d53((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002db9 at 10002db9

undefined4 __fastcall FUN_10002db9(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_100025dc((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10002dfa at 10002dfa

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10002dfa(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10002e06;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10002065(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10002493(&local_5d);
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
LAB_10002eef:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_10002f63;
                }
                iVar3 = FUN_10002045((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_100020a5(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_10002f89;
                  goto LAB_10002f2b;
                }
                local_55 = '\0';
              }
              else {
LAB_10002f2b:
                if (local_55 != '\0') goto LAB_10002f63;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_10002873(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_10002f89;
                local_56 = '\0';
              }
              goto LAB_10002f63;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_10002873(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_10002eef;
            }
LAB_10002f89:
            local_5c = -0x7ff8fff2;
            goto LAB_10002e6a;
          }
LAB_10002f63:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_1000223f(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_10002e6a;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_10002db9(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_10002873(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_10002f89;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_10002ffc;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_10002e6a;
            }
            iVar3 = FUN_100020a5(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_10002f89;
          }
          else {
            iVar3 = FUN_100020a5(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_10002ffc:
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
LAB_10002e6a:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_10008d05();
  return;
}



// Function: FUN_10003067 at 10003067

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003067(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_1000c018), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_1000c038,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000ba34,&local_1a8
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
          goto LAB_100032f2;
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
      FUN_1000256b(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_100032f2:
  FUN_10008d05();
  return;
}



// Function: FUN_10003385 at 10003385

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003385(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_100028cc(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10002493((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_10003455 at 10003455

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003455(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_100028cc(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_10002493(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10003617;
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
LAB_10003617:
  FUN_10008d05();
  return;
}



// Function: FUN_1000361f at 1000361f

int FUN_1000361f(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10001b64(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_10003067((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_10003455(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_100036a5 at 100036a5

int FUN_100036a5(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_10001b64(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_10003067((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_10003385(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_1000372c at 1000372c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000372c(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10003760 at 10003760

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003760(int param_1)

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



// Function: FUN_100037ab at 100037ab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_100037ab(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_1000ba94,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_10003866;
          }
          else {
LAB_10003866:
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



// Function: FUN_10003896 at 10003896

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003896(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_100025b2((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: InlineIsEqualUnknown at 100038c7

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



// Function: FUN_100038f5 at 100038f5

undefined4 FUN_100038f5(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10003933 at 10003933

undefined4 FUN_10003933(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10010dac + 8))();
  }
  else {
    (**(code **)(*DAT_10010dac + 4))();
  }
  return 0;
}



// Function: FUN_10003952 at 10003952

undefined4 * __thiscall FUN_10003952(void *this,byte param_1)

{
  FUN_10003896((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003971 at 10003971

undefined4 __thiscall FUN_10003971(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10002b43(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 100039c8

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
    FUN_1000261d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100039f7

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
    FUN_1000261d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 10003a26

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
    FUN_1000261d(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10003a55 at 10003a55

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003a55(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10002667(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_10003a90 at 10003a90

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10003a90(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_10002667((void *)(param_1 + 0x1c));
  FUN_1000372c(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 7;
  *(undefined2 *)(param_1 + 0x38) = 0;
  return param_1;
}



// Function: FUN_10003ae2 at 10003ae2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003ae2(int param_1)

{
  FID_conflict__Tidy((void *)(param_1 + 0x38),'\x01',0);
  FUN_10003760(param_1 + 0xc);
  FUN_100025b2((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return;
}



// Function: FUN_10003b2c at 10003b2c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003b2c(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_10008bbc(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10003b92();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10003b86 at 10003b86

undefined * Catch_10003b86(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003b90;
}



// Function: FUN_10003b92 at 10003b92

void FUN_10003b92(void)

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
  uVar4 = FUN_10008bbc(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10003be3();
  return;
}



// Function: Catch@10003bd4 at 10003bd4

undefined * Catch_10003bd4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10003be1;
}



// Function: FUN_10003be3 at 10003be3

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10003be3(void)

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
    FUN_10001c62(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10001c62(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_10003971(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_10003c3f;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_10003c3f:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_10003c77 at 10003c77

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003c77(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_10003b2c(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_1000256b(local_14);
  }
  return iVar1;
}



// Function: FUN_10003cd2 at 10003cd2

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003cd2(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_10009f28;
  local_10 = ExceptionList;
  uStack_2144 = DAT_10010d90 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_100022b4(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10002133(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_1000404b;
  FUN_10002292((undefined4 *)this);
  iVar1 = FUN_100022b4(this,local_2018);
  if (iVar1 < 0) goto LAB_1000404b;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_10004027:
    if (uVar2 != 0) {
      FUN_10001cef(uVar2);
      goto LAB_1000404b;
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
        FUN_10003f5a();
        return;
      }
      goto LAB_1000404b;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_1000256b((int *)&local_2124);
      goto LAB_10004027;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10003df3();
      return;
    }
  }
  FUN_100022b4(this,param_3);
LAB_1000404b:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10003de7 at 10003de7

undefined * Catch_10003de7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10003df1;
}



// Function: FUN_10003df3 at 10003df3

void FUN_10003df3(void)

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
    pWVar2 = (WCHAR *)FUN_10001ff3(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10002613((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_100022b4(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_10001cef((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10004063;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10003f3f at 10003f3f

undefined * Catch_10003f3f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10003f4c;
}



// Function: FUN_10003f5a at 10003f5a

void FUN_10003f5a(void)

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
      FUN_10002613((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_100021db(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10002613((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_100022b4(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_10001cef(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10004063;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10004067 at 10004067

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10004067(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_10009f87;
  local_10 = ExceptionList;
  local_14 = DAT_10010d90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_100040cb:
  iVar3 = FUN_100022b4(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_100040db:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_10004538:
    if (*param_1 == L'}') goto LAB_100040db;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_100022b4(local_2220,param_1);
      if (iVar3 < 0) goto LAB_100040db;
      if (param_3 == 0) goto LAB_1000421a;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_1000223f(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_100023ca(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10002737(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_1000421a;
        }
        iVar3 = FUN_100022b4(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_1000242e(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_10004637;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_100046b6;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_100040db;
    }
LAB_1000421a:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_100022b4(local_2220,param_1);
      if (iVar3 < 0) goto LAB_100040db;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_1000223f(param_1,L'\\');
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
          iVar3 = FUN_100022b4(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_1000242e(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_10004067(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_100022b4(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_100046d5;
          iVar3 = FUN_100022b4(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_10003cd2(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_1000463c;
        }
      }
      goto LAB_100040db;
    }
    iVar3 = FUN_100022b4(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_100022b4(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_100040db;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_10003cd2(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_10004637;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_100046b6;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10001cef(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_100046b6:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_100040db;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_1000242e(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_100023f9(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_100023ca(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10002737(&local_2234,local_21c);
        }
        goto LAB_10004538;
      }
      bVar2 = FUN_100023f9(local_2234);
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
            FUN_10001cef(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_100046b6;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_10004637:
          ATL::CRegKey::Close(pCVar8);
LAB_1000463c:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_10004067(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_100040cb;
            goto LAB_100040db;
          }
        }
        goto LAB_10004538;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_10004538;
    }
LAB_100046d5:
    FUN_10001cef(uVar6);
    goto LAB_100040db;
  }
  goto LAB_10004538;
}



// Function: FUN_100046fe at 100046fe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_100046fe(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10010f1c);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_1000ba94,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10010f1c);
          if (*piVar2 != 0) goto LAB_10004792;
        }
        else {
LAB_10004792:
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
  piVar2 = FUN_100037ab((int *)&DAT_10010f0c,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_100047ca at 100047ca

void FUN_100047ca(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000361f(0x10010f0c,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10010e24 != (code *)0x0)) {
    (*DAT_10010e24)(DAT_10010f38);
  }
  return;
}



// Function: FUN_100047f8 at 100047f8

void FUN_100047f8(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_10010e28 != (code *)0x0) && (iVar1 = (*DAT_10010e28)(), iVar1 < 0)) {
    return;
  }
  FUN_100036a5(0x10010f0c,param_1,param_2);
  return;
}



// Function: FUN_1000481e at 1000481e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000481e(undefined4 *param_1)

{
  FUN_10003a55(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: AtlInternalQueryInterface at 1000484c

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
          if (pcVar1 == (code *)0x1) goto LAB_10004880;
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
LAB_10004880:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_100048ed at 100048ed

LONG FUN_100048ed(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10010dac + 4))();
  }
  return LVar1;
}



// Function: FUN_10004917 at 10004917

LONG FUN_10004917(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10010dac + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 10004956

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000badc,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10004970 at 10004970

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004970(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10003896(param_1);
  return;
}



// Function: FUN_1000499f at 1000499f

undefined4 * __thiscall FUN_1000499f(void *this,byte param_1)

{
  FUN_10004970((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100049be at 100049be

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100049be(undefined4 *param_1)

{
  FUN_10003a90((int)param_1);
  *param_1 = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  (**(code **)(*DAT_10010dac + 4))();
  return param_1;
}



// Function: FUN_10004a0c at 10004a0c

short * __cdecl FUN_10004a0c(short *param_1,short param_2,int param_3)

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



// Function: FUN_10004a2d at 10004a2d

int __cdecl FUN_10004a2d(ushort *param_1,ushort *param_2,int param_3)

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



// Function: FUN_10004a61 at 10004a61

void FUN_10004a61(void)

{
  return;
}



// Function: FUN_10004a62 at 10004a62

LSTATUS __thiscall FUN_10004a62(void *this,LPBYTE param_1,LPCWSTR param_2,LPDWORD param_3)

{
  short sVar1;
  LPDWORD lpcbData;
  LSTATUS LVar2;
  undefined4 *extraout_ECX;
  uint uVar3;
  
  lpcbData = param_3;
  if (param_3 == (LPDWORD)0x0) {
    FUN_1000108d(0x80004005);
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
      if ((uVar3 & 1) != 0) goto LAB_10004adb;
      sVar1 = *(short *)(param_1 + ((uVar3 & 0xfffffffe) - 2));
    }
    else {
      if ((((param_3 != (LPDWORD)0x7) || ((uVar3 & 1) != 0)) || (uVar3 = uVar3 >> 1, uVar3 == 0)) ||
         (*(short *)(param_1 + uVar3 * 2 + -2) != 0)) goto LAB_10004adb;
      if (uVar3 < 2) {
        return LVar2;
      }
      sVar1 = *(short *)(param_1 + uVar3 * 2 + -4);
    }
    if (sVar1 == 0) {
      return LVar2;
    }
  }
LAB_10004adb:
  param_1[0] = '\0';
  param_1[1] = '\0';
  return 0xd;
}



// Function: FUN_10004af1 at 10004af1

void FUN_10004af1(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = DAT_10010d90 ^ (uint)&stack0xfffffffc;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004b23 at 10004b23

undefined4 FUN_10004b23(void)

{
  return 0;
}



// Function: AtlAdd<unsigned_long> at 10004b28

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



// Function: AtlAddThrow<> at 10004b4c

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
    FUN_1000108d(lVar1);
  }
  return local_8;
}



// Function: FUN_10004b71 at 10004b71

undefined4 * __thiscall FUN_10004b71(void *this,int *param_1)

{
  int *piVar1;
  
  *(int **)this = param_1;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  return (undefined4 *)this;
}



// Function: FUN_10004b97 at 10004b97

void __fastcall FUN_10004b97(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x10004baa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_10004bae at 10004bae

void __fastcall FUN_10004bae(int param_1)

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



// Function: FUN_10004beb at 10004beb

void FUN_10004beb(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x18));
  return;
}



// Function: FUN_10004bff at 10004bff

LONG FUN_10004bff(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x18));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (**(code **)(*(int *)(param_1 + 0xc) + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_10004c2d at 10004c2d

uint FUN_10004c2d(byte param_1)

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



// Function: FUN_10004c59 at 10004c59

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10004c59(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10004c65;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_1000d570);
}



// Function: FUN_10004cb8 at 10004cb8

undefined4 __cdecl FUN_10004cb8(int *param_1,int *param_2)

{
  int *piVar1;
  int *extraout_ECX;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    param_2 = (int *)FUN_1000108d(0x80004005);
    param_1 = extraout_ECX;
  }
  piVar1 = (int *)*param_2;
  *param_1 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}



// Function: FUN_10004ce5 at 10004ce5

void FUN_10004ce5(int param_1)

{
  FUN_10004bff(param_1 + -4);
  return;
}



// Function: FUN_10004cef at 10004cef

void FUN_10004cef(int param_1)

{
  FUN_10004bff(param_1 + -8);
  return;
}



// Function: FUN_10004cf9 at 10004cf9

void FUN_10004cf9(int param_1)

{
  FUN_10004bff(param_1 + -0xc);
  return;
}



// Function: FUN_10004d03 at 10004d03

void FUN_10004d03(int param_1)

{
  FUN_10004beb(param_1 + -4);
  return;
}



// Function: FUN_10004d0d at 10004d0d

void __thiscall FUN_10004d0d(void *this,byte param_1)

{
  FUN_10006014((void *)((int)this + -0xc),param_1);
  return;
}



// Function: FUN_10004d15 at 10004d15

void FUN_10004d15(int param_1)

{
  FUN_10004beb(param_1 + -8);
  return;
}



// Function: FUN_10004d1f at 10004d1f

void FUN_10004d1f(int param_1)

{
  FUN_10004beb(param_1 + -0xc);
  return;
}



// Function: _AtlVerifyStackAvailable at 10004d29

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
  
  uStack_c = 0x10004d35;
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
  uVar1 = FUN_10008fb8();
  return (bool)uVar1;
}



// Function: FUN_10004d9f at 10004d9f

uint __thiscall FUN_10004d9f(void *this,ushort *param_1,uint param_2,uint param_3)

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
      while (puVar3 = (ushort *)FUN_10004a0c((short *)puVar6,uVar1,param_2), puVar3 != (ushort *)0x0
            ) {
        iVar2 = FUN_10004a2d(puVar3,param_1,param_3);
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



// Function: FUN_10004e3e at 10004e3e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10004e3e(void *this,int *param_1)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  
  FUN_10004b71(this,param_1);
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (this_00 = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
                 (*(int *)(*param_1 + 4) + 0x3c + (int)param_1),
     this_00 != (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush(this_00);
  }
  *(bool *)((int)this + 4) = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0;
  return this;
}



// Function: FUN_10004e96 at 10004e96

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004e96(int *param_1)

{
  bool bVar1;
  
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx
              ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)*param_1);
  }
  FUN_10004b97(param_1);
  return;
}



// Function: FUN_10004ece at 10004ece

undefined4 * __thiscall FUN_10004ece(void *this,ulong param_1)

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



// Function: FUN_10004efa at 10004efa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004efa(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  *(undefined ***)param_1 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_10004bae((int)param_1);
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  return;
}



// Function: FUN_10004f2c at 10004f2c

undefined4 __fastcall FUN_10004f2c(int param_1)

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



// Function: FUN_10004f90 at 10004f90

void __thiscall
FUN_10004f90(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

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
      if (param_2 == 0 && param_3 == 0) goto LAB_1000511c;
    }
    else {
      if (param_4 == 2) {
        iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
LAB_100050ac:
        bVar5 = CARRY4(param_2,iVar3 >> 1);
        param_2 = param_2 + (iVar3 >> 1);
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar5;
      }
      else {
        if (param_4 == 1) {
          iVar3 = uVar2 - **(int **)((int)this + 0x10);
          goto LAB_100050ac;
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
          goto LAB_1000511c;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar1 = *(int *)((int)this + 0x3c);
LAB_10004fdb:
      iVar1 = iVar1 - **(int **)((int)this + 0x10);
      uVar2 = iVar1 >> 1;
      bVar5 = CARRY4(param_2,uVar2);
      param_2 = param_2 + uVar2;
      param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar5;
    }
    else if (param_4 == 1) {
      iVar1 = iVar3;
      if ((param_5 & 2) == 0) goto LAB_10004fdb;
LAB_10004ff5:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    else if (param_4 != 0) goto LAB_10004ff5;
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
        goto LAB_1000511c;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_1000511c:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10005136 at 10005136

short __thiscall FUN_10005136(void *this,short param_1)

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



// Function: FUN_10005193 at 10005193

void __thiscall FUN_10005193(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

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



// Function: FUN_100052ab at 100052ab

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_100052ab(void *this,byte param_1)

{
  FUN_10004efa((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_100052ca at 100052ca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100052ca(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



// Function: QueryInterface at 10005302

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000bb6c,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000531c at 1000531c

uint __thiscall FUN_1000531c(void *this,uint param_1)

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



// Function: FUN_1000534b at 1000534b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000534b(int param_1)

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



// Function: FUN_100053a8 at 100053a8

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_100053a8(int *param_1,wchar_t *param_2)

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
  local_8 = 0x100053b4;
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
  FUN_10004e3e(local_28,param_1);
  local_8 = 0;
  if (local_24 == '\0') {
    local_18 = 4;
    FUN_1000550d();
    return;
  }
  local_8 = 1;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_10005465;
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
LAB_10005465:
    if (local_18 != 0) goto LAB_1000548e;
  }
  _Var6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                    (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                      (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                     (ulonglong)CONCAT22(in_stack_ffffffca,in_stack_ffffffc8) << 0x20);
  if (((size_t)_Var6 == sVar4) && ((int)((ulonglong)_Var6 >> 0x20) == 0)) {
    while( true ) {
      if ((local_1c < 0) || ((local_1c < 1 && (local_20 == 0)))) goto LAB_1000548e;
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
LAB_1000548e:
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  local_8 = 0;
  FUN_1000550d();
  return;
}



// Function: Catch@100054ec at 100054ec

undefined * Catch_100054ec(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000550a;
}



// Function: FUN_1000550d at 1000550d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000550d(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10004e96((int *)(unaff_EBP + -0x24));
  return;
}



// Function: FUN_10005533 at 10005533

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10005533(int *param_1,wchar_t *param_2)

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
  local_8 = 0x1000553f;
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
  FUN_10004e3e(local_24,param_1);
  local_8 = 0;
  if ((char)local_20 == '\0') {
    local_18 = 4;
    FUN_1000567c();
    return;
  }
  local_8 = 1;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) == 0x40) {
LAB_100055e0:
    if (7 < *(uint *)(param_2 + 10)) {
      param_2 = *(wchar_t **)param_2;
    }
    _Var5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                      (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                        (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                       (ulonglong)CONCAT22(in_stack_ffffffce,in_stack_ffffffcc) << 0x20);
    if (((uint)_Var5 != uVar1) || ((int)((ulonglong)_Var5 >> 0x20) != 0)) {
      local_18 = 4;
      goto LAB_10005614;
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
    if (local_18 == 0) goto LAB_100055e0;
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
LAB_10005614:
  iVar3 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar3 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar3 + 0x24 + (int)param_1) = 0;
  local_8 = 0;
  FUN_1000567c();
  return;
}



// Function: Catch@1000565b at 1000565b

undefined * Catch_1000565b(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005679;
}



// Function: FUN_1000567c at 1000567c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000567c(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10004e96((int *)(unaff_EBP + -0x20));
  return;
}



// Function: FUN_100056a2 at 100056a2

void FUN_100056a2(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_100056ac at 100056ac

void FUN_100056ac(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_100056b6 at 100056b6

void FUN_100056b6(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100056c0 at 100056c0

int __fastcall FUN_100056c0(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_100056c4 at 100056c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100056c4(int param_1)

{
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_10004efa((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x4c));
  *(code **)(*(int *)(*(int *)(param_1 + -0x50) + 4) + -0x50 + param_1) = _vftable__exref;
  return;
}



// Function: FUN_10005709 at 10005709

wchar_t __thiscall FUN_10005709(void *this,wchar_t param_1)

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
  _Dst = FUN_100011a3(pcVar1);
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
      goto LAB_100058b0;
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
      goto LAB_100058b0;
    }
    **(undefined4 **)((int)this + 0x10) = _Dst;
    puVar6 = *(undefined4 **)((int)this + 0x20);
  }
  *puVar6 = 0;
  **(int **)((int)this + 0x30) = (int)_Dst >> 1;
LAB_100058b0:
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *pwVar5 = param_1;
  return param_1;
}



// Function: FUN_100058da at 100058da

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_100058da(int param_1)

{
  FUN_100052ca(param_1);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10005904 at 10005904

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005904(int param_1)

{
  FUN_1000534b(param_1);
  return;
}



// Function: FUN_10005922 at 10005922

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10005922(void *this,byte param_1)

{
  uint uVar1;
  
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  uVar1 = FUN_10004c2d(param_1);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(uint *)((int)this + 0x40) = uVar1;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10005962 at 10005962

undefined4 * __thiscall FUN_10005962(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_10001495(this,uVar2,'\0');
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



// Function: FUN_10005a07 at 10005a07

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10005a07(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  
  if (param_4 == 3) {
    lVar1 = (ulonglong)(uint)(param_2 - param_1 >> 2) * 4;
    uVar2 = FUN_10008bbc(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    *(undefined4 *)((int)this + 8) = uVar2;
    uVar2 = FUN_10005a5f();
    return uVar2;
  }
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  if (*(int **)((int)this + 4) != param_3) {
    FUN_100010a5((int *)((int)this + 4),param_3);
  }
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 8);
  *(int *)((int)this + 0x14) = param_4;
  return 0;
}



// Function: Catch@10005a4f at 10005a4f

undefined * Catch_10005a4f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005a59;
}



// Function: FUN_10005a5f at 10005a5f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005a5f(void)

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
      iVar3 = FUN_10004cb8(*(int **)(unaff_ESI + 0x10),piVar4);
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
      FUN_100010a5((int *)(unaff_ESI + 4),*(int **)(unaff_EBP + 0x10));
    }
    *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 8);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_EBP + 0x14);
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10005b08 at 10005b08

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005b08(int param_1)

{
  ios_base *piVar1;
  
  piVar1 = (ios_base *)(param_1 + 0x50);
  FUN_100056c4((int)piVar1);
  *(code **)piVar1 = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  return;
}



// Function: FUN_10005b41 at 10005b41

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10005b41(undefined4 *param_1)

{
  FUN_100058da((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10010dac + 4))();
  return param_1;
}



// Function: FUN_10005b7a at 10005b7a

undefined4 FUN_10005b7a(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: Release at 10005b8a

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



// Function: FUN_10005bab at 10005bab

undefined4 FUN_10005bab(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// Function: FUN_10005bbd at 10005bbd

bool FUN_10005bbd(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 4;
  return param_2 != uVar1;
}



// Function: FUN_10005bea at 10005bea

uint FUN_10005bea(int param_1,uint param_2,int *param_3,uint *param_4)

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
      uVar2 = FUN_10004cb8(piVar3,*(int **)(param_1 + 0x10));
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



// Function: QueryInterface at 10005ca8

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000bc6c,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10005cc2 at 10005cc2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005cc2(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10010dac + 8))();
  FUN_1000534b((int)param_1);
  return;
}



// Function: FUN_10005d00 at 10005d00

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10005d00(void *this,byte param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined **)this = &DAT_1000bc94;
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
  FUN_10005922((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 4),
               param_1 | 2);
  return (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10005d7e at 10005d7e

undefined4 * __thiscall FUN_10005d7e(void *this,byte param_1)

{
  FUN_10005cc2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005d9d at 10005d9d

void * __thiscall FUN_10005d9d(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x50);
  FUN_10005b08((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_10005dbf at 10005dbf

undefined2 * __thiscall FUN_10005dbf(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FUN_100014ff(this,param_1,param_2,param_3);
  return (undefined2 *)this;
}



// Function: FUN_10005dea at 10005dea

undefined4 * __thiscall FUN_10005dea(void *this,undefined4 *param_1,uint param_2)

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
      bVar1 = FUN_10001495(this,uVar2,'\0');
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
    this = FUN_10005962(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005e8c at 10005e8c

undefined4 * __thiscall
FUN_10005e8c(void *this,uint param_1,undefined4 *param_2,uint param_3,uint param_4)

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
      bVar3 = FUN_10001495(this,uVar8,'\0');
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



// Function: FUN_10005fc1 at 10005fc1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005fc1(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CLicenseManagerImpl>::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10010dac + 8))();
  FUN_10003ae2((int)param_1);
  return;
}



// Function: FUN_10006014 at 10006014

undefined4 * __thiscall FUN_10006014(void *this,byte param_1)

{
  FUN_10005fc1((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006033 at 10006033

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006033(int param_1)

{
  FUN_10003ae2(param_1);
  return;
}



// Function: basic_string<> at 10006051

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



// Function: FUN_10006079 at 10006079

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006079(void *this,undefined4 param_1)

{
  FUN_10003a90((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CLicenseManagerImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CLicenseManagerImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CLicenseManagerImpl>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CLicenseManagerImpl>::vftable;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100060c2 at 100060c2

void FUN_100060c2(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x18) + 4))(*(int **)(param_1 + 0x18));
  return;
}



// Function: FUN_100060d5 at 100060d5

void FUN_100060d5(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x18) + 8))(*(int **)(param_1 + 0x18));
  return;
}



// Function: FUN_100060e8 at 100060e8

void FUN_100060e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x18))(*(undefined4 **)(param_1 + 0x18),param_2,param_3);
  return;
}



// Function: FUN_10006100 at 10006100

undefined4 __fastcall FUN_10006100(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: FUN_10006104 at 10006104

void FUN_10006104(int param_1)

{
  FUN_100060d5(param_1 + -4);
  return;
}



// Function: FUN_1000610e at 1000610e

void FUN_1000610e(int param_1)

{
  FUN_100060d5(param_1 + -8);
  return;
}



// Function: FUN_10006118 at 10006118

void __thiscall FUN_10006118(void *this,byte param_1)

{
  FUN_10006166((void *)((int)this + -0xc),param_1);
  return;
}



// Function: FUN_10006120 at 10006120

void FUN_10006120(int param_1)

{
  FUN_100060d5(param_1 + -0xc);
  return;
}



// Function: FUN_1000612a at 1000612a

void FUN_1000612a(int param_1)

{
  FUN_100060c2(param_1 + -4);
  return;
}



// Function: FUN_10006134 at 10006134

void FUN_10006134(int param_1)

{
  FUN_100060c2(param_1 + -8);
  return;
}



// Function: FUN_1000613e at 1000613e

void FUN_1000613e(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100060e8(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10006148 at 10006148

void FUN_10006148(int param_1)

{
  FUN_100060c2(param_1 + -0xc);
  return;
}



// Function: FUN_10006152 at 10006152

void FUN_10006152(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100060e8(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_1000615c at 1000615c

void FUN_1000615c(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100060e8(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10006166 at 10006166

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10006166(void *this,byte param_1)

{
  FUN_10003ae2((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10006197 at 10006197

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006197(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10005b41(puVar1);
    }
    uVar2 = FUN_100061f2();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100061e3 at 100061e3

undefined * Catch_100061e3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100061ed;
}



// Function: FUN_100061f2 at 100061f2

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100061f2(void)

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



// Function: FUN_10006209 at 10006209

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10006209(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_10002667((void *)(param_1 + 0x14));
  return param_1;
}



// Function: DllGetClassObject at 10006237

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x6237  2  DllGetClassObject */
  piVar1 = FUN_100046fe(&DAT_10010edc,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_10006245 at 10006245

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10006245(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10010d90 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10002dfa(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_1000633b:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10006290:
  if ((((sVar1 == 0) || (iVar3 = FUN_100022b4(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10002211(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_100022b4(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_1000632d;
  if (param_2 == 0) {
    iVar3 = FUN_10004067(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_1000632d;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_10004067(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_10004067(this,local_2008,pHVar4,0,0);
LAB_1000632d:
      CoTaskMemFree(local_200c);
      goto LAB_1000633b;
    }
  }
  FUN_10002292((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10006290;
}



// Function: FUN_1000637c at 1000637c

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000637c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10005b41(puVar1);
    }
    FUN_100063db();
    return;
  }
  FUN_10008d14();
  return;
}



// Function: Catch@100063cc at 100063cc

undefined * Catch_100063cc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100063d6;
}



// Function: FUN_100063db at 100063db

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_100063db(void)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != unaff_EBX) {
    *(int **)(unaff_EBP + -0x20) = unaff_EBX;
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
        register0x00000010 = (BADSPACEBASE *)FUN_10004ece((void *)(unaff_EBP + -0x20),uVar1);
      }
      if ((int *)register0x00000010 == unaff_EBX) {
        (**(code **)(*unaff_ESI + 0x1c))(1);
      }
      else {
        iVar4 = FUN_10005a07(unaff_ESI,(int)register0x00000010,(int)register0x00000010,
                             *(int **)(unaff_EBP + 8),3);
        if ((iVar4 < (int)unaff_EBX) || (iVar4 = (**(code **)*unaff_ESI)(), iVar4 < (int)unaff_EBX))
        {
          (**(code **)(*unaff_ESI + 0x1c))(1);
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_1000256b((int *)(unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -0x34) = 0x1000639e;
  FUN_10008d14();
  return;
}



// Function: FUN_10006490 at 10006490

int __thiscall FUN_10006490(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10001b64(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10003067((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_100047ca(param_1,param_2);
  return iVar5;
}



// Function: FUN_100064ff at 100064ff

int __thiscall FUN_100064ff(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_10001b64(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10003067((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_100047f8(param_1,param_2);
  return iVar5;
}



// Function: Catch@100065cc at 100065cc

undefined1 * Catch_100065cc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100065d6;
}



// Function: FUN_1000661e at 1000661e

undefined4 * __thiscall FUN_1000661e(void *this,uint param_1,undefined4 *param_2,uint param_3)

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
      bVar1 = FUN_10001495(this,uVar2,'\0');
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
    this = FUN_10005e8c(this,param_1,(undefined4 *)this,(int)param_2 - (int)pvVar4 >> 1,param_3);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006716 at 10006716

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10006716(void *this,void *param_1,uint param_2,uint param_3)

{
  FUN_10005dbf(param_1,(undefined4 *)this,param_2,param_3);
  return param_1;
}



// Function: FUN_1000674f at 1000674f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000674f(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x54);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100049be(puVar1);
    }
    iVar2 = FUN_100067b3();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@100067a3 at 100067a3

undefined * Catch_100067a3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100067ad;
}



// Function: FUN_100067b3 at 100067b3

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100067b3(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    lpAddend = unaff_ESI + 6;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10002553((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(unaff_ESI[3] + 0x10))(1);
  }
  return unaff_EBX;
}



// Function: FUN_10006800 at 10006800

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10006800(undefined4 *param_1)

{
  FUN_10006209((int)param_1);
  *param_1 = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  (**(code **)(*DAT_10010dac + 4))();
  return param_1;
}



// Function: AtlComQIPtrAssign at 1000684e

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



// Function: Attach at 10006885

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



// Function: FUN_100068a4 at 100068a4

undefined4 FUN_100068a4(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_100068ea at 100068ea

void FUN_100068ea(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



// Function: Release at 100068fe

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_1000692b at 1000692b

void FUN_1000692b(int param_1)

{
  Release((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_10006935 at 10006935

void FUN_10006935(int param_1)

{
  FUN_100068ea(param_1 + -4);
  return;
}



// Function: FUN_1000693f at 1000693f

void FUN_1000693f(int param_1)

{
  FUN_100068ea(param_1 + -8);
  return;
}



// Function: FUN_10006949 at 10006949

void FUN_10006949(int param_1)

{
  FUN_100068ea(param_1 + -0xc);
  return;
}



// Function: FUN_10006953 at 10006953

void FUN_10006953(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_1000695d at 1000695d

void FUN_1000695d(int param_1)

{
  Release((int *)(param_1 + -8));
  return;
}



// Function: FUN_10006967 at 10006967

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10006967(void *this,wchar_t *param_1)

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
  local_8 = 0x10006973;
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
      local_18 = (uint *)FUN_10008bbc(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_100068c1,
                   (_func_void_void_ptr *)&LAB_10001ae6);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_10006a17();
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



// Function: Catch@10006a07 at 10006a07

undefined * Catch_10006a07(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006a11;
}



// Function: FUN_10006a17 at 10006a17

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006a17(void)

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



// Function: FUN_10006acf at 10006acf

void FUN_10006acf(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10001b07(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10006b02 at 10006b02

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_10006b02(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_1000ba94,&local_18);
    (**(code **)*param_1)(param_1,&DAT_1000ba94,local_14);
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



// Function: QueryInterface at 10006b8d

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000bd90,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10006ba7 at 10006ba7

void FUN_10006ba7(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10006bb1 at 10006bb1

void FUN_10006bb1(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_10006bbb at 10006bbb

void FUN_10006bbb(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_10006bc5 at 10006bc5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006bc5(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_10006c0a();
  return uVar1;
}



// Function: Catch@10006bfa at 10006bfa

undefined * Catch_10006bfa(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006c04;
}



// Function: FUN_10006c0a at 10006c0a

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006c0a(void)

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



// Function: FUN_10006c65 at 10006c65

IUnknown * __thiscall FUN_10006c65(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_10006b02(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1000be28);
  }
  return pIVar2;
}



// Function: FUN_10006c92 at 10006c92

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006c92(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CTSSProxyImpl>::vftable;
  param_1[4] = 0xc0000001;
  FUN_100087f3((int)param_1);
  (**(code **)(*DAT_10010dac + 8))();
  FUN_10002bae((int)param_1);
  return;
}



// Function: FUN_10006cea at 10006cea

undefined4 * __thiscall FUN_10006cea(void *this,byte param_1)

{
  FUN_10006c92((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006d09 at 10006d09

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10006d09(void *this,undefined4 param_1)

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
  local_8 = 0x10006d18;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10006f4e;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10010dac + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_10010e2c,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_10010f38,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10006f18;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000256b((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_1000be18,&local_224);
        if (-1 < iVar2) {
          FUN_10006c65(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_10010dac == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_10010dac + 4;
        }
        pcVar4 = FUN_10006acf;
        pvVar5 = this;
        FUN_10006bc5(iVar2);
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
LAB_10006f18:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10006967(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10006f4e:
  FUN_10008d05();
  return;
}



// Function: FUN_10006f56 at 10006f56

undefined4 __thiscall FUN_10006f56(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10006d09(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10006f96 at 10006f96

undefined4 __thiscall
FUN_10006f96(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10006d09(this,param_4);
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



// Function: FUN_10007037 at 10007037

void __thiscall
FUN_10007037(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10006d09(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_1000707a at 1000707a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000707a(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CLicenseManagerImpl>::vftable;
  FUN_10006079((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10010dac + 4))();
  return (undefined4 *)this;
}



// Function: FUN_100070bd at 100070bd

long FUN_100070bd(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000bb6c,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10007109 at 10007109

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007109(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CLicenseManagerImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10010dac + 8))();
  FUN_10003ae2((int)(param_1 + 3));
  return;
}



// Function: FUN_1000714f at 1000714f

undefined4 * __thiscall FUN_1000714f(void *this,byte param_1)

{
  FUN_10007109((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000716e at 1000716e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000716e(void *this,undefined4 param_1)

{
  FUN_10006209((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CTSSProxyImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CTSSProxyImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CTSSProxyImpl>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CTSSProxyImpl>::vftable;
  *(undefined4 *)((int)this + 0x10) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100071b7 at 100071b7

void FUN_100071b7(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_100071ca at 100071ca

void FUN_100071ca(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_100071dd at 100071dd

void FUN_100071dd(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))(*(undefined4 **)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_100071f5 at 100071f5

void FUN_100071f5(int param_1)

{
  FUN_100071ca(param_1 + -0xc);
  return;
}



// Function: FUN_100071ff at 100071ff

void FUN_100071ff(int param_1)

{
  FUN_100071b7(param_1 + -8);
  return;
}



// Function: FUN_10007209 at 10007209

void FUN_10007209(int param_1)

{
  FUN_100071b7(param_1 + -0xc);
  return;
}



// Function: FUN_10007213 at 10007213

void FUN_10007213(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100071dd(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000721d at 1000721d

void FUN_1000721d(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100071dd(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10007227 at 10007227

void FUN_10007227(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100071dd(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10007231 at 10007231

void FUN_10007231(int param_1)

{
  FUN_100071ca(param_1 + -4);
  return;
}



// Function: FUN_1000723b at 1000723b

void FUN_1000723b(int param_1)

{
  FUN_100071ca(param_1 + -8);
  return;
}



// Function: FUN_10007245 at 10007245

void FUN_10007245(int param_1)

{
  FUN_100071b7(param_1 + -4);
  return;
}



// Function: FUN_1000724f at 1000724f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000724f(int *param_1,void **param_2)

{
  int *piVar1;
  int *local_1c;
  int local_18;
  uint local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0xc;
  local_8 = 0x1000725b;
  local_14 = 0;
  local_18 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    local_18 = FUN_10006197(&local_1c);
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
      local_18 = FUN_10005a07(local_1c,piVar1[2],piVar1[3],param_1,0);
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
                             (local_1c,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000bc6c,(_GUID *)&DAT_1000bc84
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



// Function: DllRegisterServer at 10007362

void DllRegisterServer(void)

{
                    /* 0x7362  3  DllRegisterServer */
  FUN_10006490(&DAT_10010edc,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10007371

void DllUnregisterServer(void)

{
                    /* 0x7371  4  DllUnregisterServer */
  FUN_100064ff(&DAT_10010edc,1,(void *)0x0);
  return;
}



// Function: FUN_10007380 at 10007380

undefined4 FUN_10007380(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006f56(&PTR_DAT_10010cec,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100073a4 at 100073a4

void FUN_100073a4(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006f96(&PTR_DAT_10010cec,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100073c4 at 100073c4

void FUN_100073c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10007037(&PTR_DAT_10010cec,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100073d2 at 100073d2

undefined4 FUN_100073d2(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006f56(&PTR_DAT_10010d08,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100073f6 at 100073f6

void FUN_100073f6(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006f96(&PTR_DAT_10010d08,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007416 at 10007416

void FUN_10007416(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10007037(&PTR_DAT_10010d08,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007424 at 10007424

undefined4 FUN_10007424(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006f56(&PTR_DAT_10010d24,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007448 at 10007448

void FUN_10007448(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006f96(&PTR_DAT_10010d24,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007468 at 10007468

void FUN_10007468(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10007037(&PTR_DAT_10010d24,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007476 at 10007476

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10007476(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_10001cda();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_10001cda();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_10007550();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10002613(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_1000256b(&local_42c);
  FUN_10008d14();
  return;
}



// Function: Catch@1000753b at 1000753b

undefined * Catch_1000753b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10007548;
}



// Function: FUN_10007550 at 10007550

void FUN_10007550(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_10001cda();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_10006245((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10002613((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1000256b((int *)(unaff_EBP + -0x428));
  FUN_10008d14();
  return;
}



// Function: FUN_100075da at 100075da

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100075da(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10007476(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_1000256b(local_14);
  return uVar1;
}



// Function: FUN_1000761b at 1000761b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000761b(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_1000256b(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10007476(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_1000256b(local_14);
  }
  return uVar1;
}



// Function: FUN_10007677 at 10007677

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007677(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10007476(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_1000256b(local_14);
  return uVar1;
}



// Function: FUN_100076b7 at 100076b7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100076b7(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_1000256b(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10007476(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_1000256b(local_14);
  }
  return uVar1;
}



// Function: FUN_10007712 at 10007712

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10007712(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_10003c77(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_10010f38;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10010f38,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_10001cda();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000256b((int *)&local_a48);
        goto LAB_10007794;
      }
      FUN_10001e15(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10001bfd(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000256b((int *)&local_a48);
          goto LAB_10007794;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10003c77(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10003c77(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_100076b7(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_1000761b(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000256b((int *)&local_a48);
  }
LAB_10007794:
  local_8 = 0xffffffff;
  FUN_10002d53(&local_a60);
  FUN_10008d05();
  return;
}



// Function: FUN_10007915 at 10007915

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10007915(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_10003c77(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_10010f38;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10010f38,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_10001cda();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000256b((int *)&local_a48);
        goto LAB_1000798e;
      }
      FUN_10001e15(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10001bfd(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_1000256b((int *)&local_a48);
          goto LAB_1000798e;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_10003c77(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_10003c77(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10007677(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_100075da(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_1000256b((int *)&local_a48);
  }
LAB_1000798e:
  local_8 = 0xffffffff;
  FUN_10002d53(&local_a5c);
  FUN_10008d05();
  return;
}



// Function: FUN_10007b0c at 10007b0c

undefined4 * __thiscall FUN_10007b0c(void *this,undefined4 *param_1)

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



// Function: FUN_10007b69 at 10007b69

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007b69(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x34);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006800(puVar1);
    }
    iVar2 = FUN_10007bcd();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10007bbd at 10007bbd

undefined * Catch_10007bbd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007bc7;
}



// Function: FUN_10007bcd at 10007bcd

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007bcd(void)

{
  LONG *lpAddend;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 4;
    InterlockedIncrement(lpAddend);
    unaff_EDI = FUN_10002553((int)lpAddend);
    if ((-1 < unaff_EDI) && (unaff_EDI = FUN_100087ec((int)unaff_ESI), -1 < unaff_EDI)) {
      unaff_EDI = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EDI == 0) && (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x10))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10007c26 at 10007c26

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007c26(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x60);
    if (this != (void *)0x0) {
      FUN_1000707a(this,param_1);
    }
    iVar1 = FUN_10007c94();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@10007c84 at 10007c84

undefined * Catch_10007c84(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007c8e;
}



// Function: FUN_10007c94 at 10007c94

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007c94(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10002553((int)(unaff_ESI + 9));
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



// Function: FUN_10007cd6 at 10007cd6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10007cd6(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CTSSProxyImpl>::vftable;
  FUN_1000716e((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10010dac + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10007d19 at 10007d19

void FUN_10007d19(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: Release at 10007d2d

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



// Function: FUN_10007d5a at 10007d5a

long FUN_10007d5a(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000bd90,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10007da6 at 10007da6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007da6(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CTSSProxyImpl>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100087f3((int)(param_1 + 3));
  (**(code **)(*DAT_10010dac + 8))();
  FUN_10002bae((int)(param_1 + 3));
  return;
}



// Function: FUN_10007df3 at 10007df3

undefined4 * __thiscall FUN_10007df3(void *this,byte param_1)

{
  FUN_10007da6((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007e12 at 10007e12

void FUN_10007e12(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_10007712(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007e1b at 10007e1b

void FUN_10007e1b(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10007915(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007e24 at 10007e24

void FUN_10007e24(int param_1)

{
  FUN_10007915((int *)&DAT_10010edc,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: basic_string<> at 10007e3c

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
  FUN_10007b0c(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_10007e61 at 10007e61

void FUN_10007e61(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000674f(0,param_2,param_3);
    return;
  }
  FUN_10007c26(param_1,param_2,param_3);
  return;
}



// Function: FUN_10007e81 at 10007e81

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007e81(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x40);
    if (this != (void *)0x0) {
      FUN_10007cd6(this,param_1);
    }
    iVar1 = FUN_10007eef();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@10007edf at 10007edf

undefined * Catch_10007edf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007ee9;
}



// Function: FUN_10007eef at 10007eef

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007eef(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10002553((int)(unaff_ESI + 7));
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    if ((-1 < unaff_EDI) && (unaff_EDI = FUN_100087ec((int)(unaff_ESI + 3)), -1 < unaff_EDI)) {
      unaff_EDI = 0;
    }
    if ((unaff_EDI != 0) || (unaff_EDI = (**(code **)*unaff_ESI)(), unaff_EDI != 0)) {
      (**(code **)(*unaff_ESI + 0xc))(1);
    }
  }
  return unaff_EDI;
}



// Function: FUN_10007f3f at 10007f3f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10007f3f(void *this,void *param_1)

{
  uint uVar1;
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x10007f4b;
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
  FUN_10008d05();
  return;
}



// Function: FUN_10008009 at 10008009

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_10008009(void *param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&LAB_1000a75e;
  if (param_1 != (void *)0x0) {
    puVar1 = basic_string<>(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10008037 at 10008037

void * __cdecl FUN_10008037(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_10007b0c(param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: FUN_1000805b at 1000805b

void FUN_1000805b(int param_1)

{
  FUN_10007915((int *)&DAT_10010edc,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10008073 at 10008073

void FUN_10008073(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10007b69(0,param_2,param_3);
    return;
  }
  FUN_10007e81(param_1,param_2,param_3);
  return;
}



// Function: FUN_10008093 at 10008093

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008093(void *this,void *param_1)

{
  FUN_10007f3f((void *)((int)this + 4),param_1);
  return param_1;
}



// Function: FUN_100080c4 at 100080c4

void __cdecl FUN_100080c4(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10008009(param_2,param_3);
  return;
}



// Function: FUN_100080d7 at 100080d7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl
FUN_100080d7(undefined4 *param_1,undefined4 *param_2,void *param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_100080c4(param_4,param_3,param_1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: Catch@1000811b at 1000811b

void Catch_1000811b(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  for (pvVar1 = *(void **)(unaff_EBP + -0x14); pvVar1 != *(void **)(unaff_EBP + 0x10);
      pvVar1 = (void *)((int)pvVar1 + 0x1c)) {
    FUN_1000164b(*(undefined4 *)(unaff_EBP + 0x14),pvVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000813d at 1000813d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Removing unreachable block (ram,0x100082d8) */
/* WARNING: Removing unreachable block (ram,0x1000831e) */

void FUN_1000813d(int param_1,wchar_t *param_2,undefined4 *param_3)

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
  local_8 = 0x1000814c;
  FUN_10001619(local_30,L"");
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  FUN_10001619(local_4c,param_2);
  pcVar6 = wcslen_exref;
  local_90 = 0;
  do {
    local_8c = (wchar_t *)0x0;
    local_8._0_1_ = 3;
    sVar2 = wcslen(L"</LicenseName>");
    uVar3 = FUN_10004d9f(local_4c,(ushort *)L"</LicenseName>",local_90,sVar2);
    FUN_10006716(local_4c,local_68,local_90,uVar3 - local_90);
    local_8._0_1_ = 4;
    FUN_10005d00(&stack0xfffffec4,2,1);
    local_8._0_1_ = 5;
    piVar4 = (int *)FUN_100053a8((int *)&stack0xfffffec4,L".//*[@Name=\"");
    piVar4 = (int *)FUN_10005533(piVar4,in_stack_fffffeb4);
    FUN_100053a8(piVar4,in_stack_fffffec0);
    in_stack_fffffec0 = *(wchar_t **)(param_1 + 8);
    puVar5 = (undefined4 *)FUN_10008093(&stack0xfffffec4,local_84);
    local_8._0_1_ = 6;
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) {
      local_94 = 0;
    }
    else {
      local_94 = Ordinal_2();
      if (local_94 == 0) goto LAB_10008368;
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
    FUN_10005dea(local_30,(undefined4 *)pcVar1,sVar2);
    local_8._0_1_ = 5;
    Ordinal_6(local_88);
    local_8._0_1_ = 4;
    FUN_10005b08((int)&stack0xfffffec4);
    local_8._0_1_ = 3;
    FID_conflict__Tidy(local_68,'\x01',0);
    local_8._0_1_ = 1;
    sVar2 = wcslen(L"<LicenseName>");
    local_90 = FUN_10004d9f(local_4c,(ushort *)L"<LicenseName>",uVar3,sVar2);
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
LAB_10008368:
      FUN_1000108d(0x8007000e);
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
  FUN_10008d05();
  return;
}



// Function: _Uninitialized_move<> at 100083c8

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
  FUN_100080d7(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100083e7 at 100083e7

void __thiscall FUN_100083e7(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  
  if (param_2 != param_3) {
    pvVar1 = FUN_10008037(param_3,*(undefined4 **)((int)this + 4),param_2);
    FUN_1000167e(pvVar1,*(void **)((int)this + 4),(int)this + 0xc);
    *(void **)((int)this + 4) = pvVar1;
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000842b at 1000842b

void __thiscall FUN_1000842b(void *this,undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  _Uninitialized_move<>(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_10008447 at 10008447

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10008447(void *this,char *param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    pvVar3 = FUN_10004c59(param_1);
                    /* WARNING: Load size is inaccurate */
    FUN_1000842b(this,*this,*(undefined4 **)((int)this + 4),pvVar3);
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    pvVar2 = *this;
    if (pvVar2 != (void *)0x0) {
      FUN_1000167e(pvVar2,*(void **)((int)this + 4),(int)this + 0xc);
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    *(void **)((int)this + 8) = (void *)((int)param_1 * 0x1c + (int)pvVar3);
    *(void **)((int)this + 4) = (void *)(((iVar1 - (int)pvVar2) / 0x1c) * 0x1c + (int)pvVar3);
    *(void **)this = pvVar3;
  }
  return;
}



// Function: Catch@100084e6 at 100084e6

void Catch_100084e6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100084f9 at 100084f9

void __thiscall FUN_100084f9(void *this,int param_1)

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
    pcVar2 = (char *)FUN_1000531c(this,uVar1);
    FUN_10008447(this,pcVar2);
  }
  return;
}



// Function: FUN_1000854e at 1000854e

void __thiscall FUN_1000854e(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_100084f9(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)((((int)param_1 - (int)puVar2) / 0x1c) * 0x1c + *this);
  }
  else if (puVar1 == *(undefined4 **)((int)this + 8)) {
    FUN_100084f9(this,1);
  }
  FUN_100080c4((int)this + 0xc,*(void **)((int)this + 4),param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  return;
}



// Function: FUN_100085ae at 100085ae

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_100085ae(void *param_1,ushort param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint local_38;
  uint local_34;
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x100085ba;
  FUN_100083e7(param_3,&local_38,(undefined4 *)*param_3,(undefined4 *)param_3[1]);
  local_38 = (uint)param_2;
  local_34 = 0;
  uVar1 = FUN_10004d9f(param_1,(ushort *)&local_38,0,1);
  if (uVar1 != 0xffffffff) {
    local_38 = (uint)param_2;
    do {
      puVar2 = (undefined4 *)FUN_10006716(param_1,local_30,local_34,uVar1 - local_34);
      local_8 = 0;
      FUN_1000854e(param_3,puVar2);
      local_8 = 0xffffffff;
      FID_conflict__Tidy(local_30,'\x01',0);
      local_34 = uVar1 + 1;
      uVar1 = FUN_10004d9f(param_1,(ushort *)&local_38,local_34,1);
    } while (uVar1 != 0xffffffff);
  }
  puVar2 = (undefined4 *)
           FUN_10006716(param_1,local_30,local_34,*(int *)((int)param_1 + 0x10) - local_34);
  local_8 = 1;
  FUN_1000854e(param_3,puVar2);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_10008d05();
  return;
}



// Function: FUN_10008686 at 10008686

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10008686(void *this,int *param_1)

{
  LPCWSTR pWVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  void *this_00;
  undefined4 local_a48;
  undefined4 local_a44;
  undefined4 local_a40;
  int local_a3c;
  int local_a38;
  DWORD local_a34;
  undefined1 local_a30 [28];
  wchar_t local_a14 [1024];
  wchar_t local_214 [262];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa38;
  local_a48 = 0;
  local_a44 = 0;
  local_a40 = 0;
  local_8 = 0;
  pWVar1 = (LPCWSTR)((int)this + 0x2c);
  if (7 < *(uint *)((int)this + 0x40)) {
    pWVar1 = *(LPCWSTR *)pWVar1;
  }
  iVar2 = Open(&local_a48,(HKEY)0x80000002,pWVar1,0x2001f);
  if (iVar2 == 0) {
    local_a34 = 0x800;
    iVar2 = FUN_10004a62(&local_a48,(LPBYTE)local_a14,L"SecurityFilePath",&local_a34);
    local_a34 = 0x200;
    if (iVar2 == 0) {
      iVar2 = FUN_10004a62(&local_a48,(LPBYTE)local_214,L"SecurityFiles",&local_a34);
    }
    iVar4 = 0;
    if (iVar2 == 0) {
      FUN_10001619(local_a30,local_214);
      local_8._0_1_ = 1;
      iVar4 = FUN_100085ae(local_a30,0x21,param_1);
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__Tidy(local_a30,'\x01',0);
    }
    if (0 < iVar4) {
      local_a38 = 0;
      local_a3c = iVar4;
      do {
        this_00 = (void *)(*param_1 + local_a38);
        sVar3 = wcslen(local_a14);
        FUN_1000661e(this_00,0,(undefined4 *)local_a14,sVar3);
        local_a38 = local_a38 + 0x1c;
        local_a3c = local_a3c + -1;
      } while (local_a3c != 0);
    }
    ATL::CRegKey::Close((CRegKey *)&local_a48);
  }
  local_8 = 0xffffffff;
  ATL::CRegKey::Close((CRegKey *)&local_a48);
  FUN_10008d05();
  return;
}



// Function: FUN_100087d4 at 100087d4

undefined4 FUN_100087d4(int param_1,int *param_2)

{
  *(int **)(param_1 + 0x2c) = param_2;
  (**(code **)(*param_2 + 4))(param_2);
  return 0;
}



// Function: FUN_100087ec at 100087ec

undefined4 __fastcall FUN_100087ec(int param_1)

{
  *(undefined4 *)(param_1 + 0x30) = 0;
  return 0;
}



// Function: FUN_100087f3 at 100087f3

void __fastcall FUN_100087f3(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}



// Function: FUN_10008809 at 10008809

undefined4 FUN_10008809(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10010d74 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_10008835 at 10008835

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008835(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPCOLESTR pOVar2;
  undefined4 uVar3;
  int *local_20;
  undefined4 local_1c;
  int *local_18;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_20 = (int *)0x0;
  local_8 = 1;
  (**(code **)**(undefined4 **)(param_1 + 0x28))
            (*(undefined4 **)(param_1 + 0x28),&DAT_1000b434,&local_20);
  local_18 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  pOVar2 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
  if (pOVar2 == (LPCOLESTR)0x0) {
    FUN_1000108d(0x8007000e);
  }
  local_8._0_1_ = 4;
  FUN_1000110d(&local_18,pOVar2,(LPUNKNOWN)0x0,0x17);
  local_8._0_1_ = 3;
  Ordinal_6(pOVar2);
  (**(code **)(*local_18 + 0x104))(local_18,*param_2,local_14);
  (**(code **)(*local_20 + 0xc))(local_20,local_18);
  local_1c = 0;
  local_8._0_1_ = 5;
  uVar3 = (**(code **)(*local_18 + 0x88))(local_18,&local_1c);
  Ordinal_6(*param_2);
  uVar1 = local_1c;
  local_1c = 0;
  *param_2 = uVar1;
  local_8._0_1_ = 3;
  Ordinal_6(0);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = 0xffffffff;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return uVar3;
}



// Function: FUN_10008920 at 10008920

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008920(int param_1)

{
  code *pcVar1;
  IID *riid;
  undefined4 uVar2;
  code *pcVar3;
  LPUNKNOWN This;
  LPUNKNOWN pIVar4;
  int *local_20;
  LPUNKNOWN local_1c;
  LPUNKNOWN local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  This = (LPUNKNOWN)0x0;
  local_20 = (int *)0x0;
  local_8 = 1;
  (**(code **)**(undefined4 **)(param_1 + 0x24))
            (*(undefined4 **)(param_1 + 0x24),&DAT_1000bfe4,&local_20);
  riid = (IID *)Ordinal_2_exref;
  local_18[0] = (IUnknown *)0x0;
  local_8._0_1_ = 3;
  pcVar1 = (code *)Ordinal_2(L"Msxml2.DOMDocument.3.0");
  pcVar3 = pcVar1;
  pIVar4 = This;
  if (pcVar1 != (code *)0x0) goto LAB_10008973;
  do {
    FUN_1000108d(0x8007000e);
    pcVar3 = pcVar1;
    pIVar4 = This;
LAB_10008973:
    local_8._0_1_ = 4;
    FUN_1000110d(local_18,(LPCOLESTR)pcVar3,pIVar4,0x17);
    pcVar1 = Ordinal_6_exref;
    local_8._0_1_ = 3;
    Ordinal_6(pcVar3);
    (*local_18[0]->lpVtbl[0x15].Release)(local_18[0]);
    This = local_18[0];
    local_8._0_1_ = 6;
    local_1c = pIVar4;
    riid = (IID *)(*(code *)riid)(L".//GenericLicense");
  } while (riid == (IID *)0x0);
  local_8._0_1_ = 7;
  (*This->lpVtbl[0xc].QueryInterface)(This,riid,&local_1c);
  local_8._0_1_ = 6;
  Ordinal_6(riid);
  uVar2 = (**(code **)(*local_20 + 0x24))(local_20,local_1c);
  local_8._0_1_ = 3;
  if (local_1c != (IUnknown *)0x0) {
    (*local_1c->lpVtbl->Release)(local_1c);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18[0] != (IUnknown *)0x0) {
    (*local_18[0]->lpVtbl->Release)(local_18[0]);
  }
  local_8 = 0xffffffff;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  return uVar2;
}



// Function: FUN_10008a21 at 10008a21

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008a21(int param_1,int param_2)

{
  undefined4 uVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  if (param_2 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    local_14[0] = (int *)0x0;
    local_8 = 1;
    (**(code **)**(undefined4 **)(param_1 + 0x24))
              (*(undefined4 **)(param_1 + 0x24),&DAT_1000bfe4,local_14);
    uVar1 = (**(code **)(*local_14[0] + 0x20))(local_14[0],param_2);
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  return uVar1;
}



// Function: FUN_10008a82 at 10008a82

void __fastcall FUN_10008a82(int *param_1)

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



// Function: FUN_10008ac6 at 10008ac6

int __fastcall FUN_10008ac6(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10008adf at 10008adf

undefined4 * __fastcall FUN_10008adf(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10008ac6((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1000ed60;
  param_1[3] = &DAT_1000ed60;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10010e20 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10008b20 at 10008b20

void __fastcall FUN_10008b20(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10008b3f at 10008b3f

int __fastcall FUN_10008b3f(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10008b64 at 10008b64

void __fastcall FUN_10008b64(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_10008b20((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10008b7c at 10008b7c

undefined4 * __fastcall FUN_10008b7c(undefined4 *param_1)

{
  long lVar1;
  
  FUN_10008b3f((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1000c068;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10010e20 = 1;
  }
  return param_1;
}



// Function: FUN_10008bbc at 10008bbc

void FUN_10008bbc(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: __security_check_cookie at 10008c0a

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10010d90) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 10008c19

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10010d90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 10008c4c

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10010d90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 10008c82

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10010d90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 10008cb8

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10010d90 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 10008cf1

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



// Function: FUN_10008d05 at 10008d05

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10008d05(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_10008d14 at 10008d14

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10008d14(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10008d23

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



// Function: __onexit at 10008d94

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
  
  local_8 = &DAT_1000ec98;
  uStack_c = 0x10008da0;
  local_20[0] = DecodePointer(DAT_100112ac);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_100112ac);
    local_24 = DecodePointer(DAT_100112a8);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_100112ac = EncodePointer(local_20[0]);
    DAT_100112a8 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10008e2c();
  }
  return p_Var1;
}



// Function: FUN_10008e2c at 10008e2c

void FUN_10008e2c(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10008e35

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __ArrayUnwind at 10008e52

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



// Function: `eh_vector_destructor_iterator' at 10008eb0

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
  FUN_10008efb();
  return;
}



// Function: FUN_10008efb at 10008efb

void FUN_10008efb(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __alloca_probe at 10008f30

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



// Function: __SEH_prolog4_GS at 10008f70

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10010d90 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: FUN_10008fb8 at 10008fb8

/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_10008fb8(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x1c) ^ unaff_EBP);
  return;
}



// Function: FUN_10008fc7 at 10008fc7

void __cdecl
FUN_10008fc7(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10010d90,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 10008ff0

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



// Function: __alloca_probe_8 at 10009006

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



// Function: `eh_vector_constructor_iterator' at 1000901c

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
  FUN_10009069();
  return;
}



// Function: FUN_10009069 at 10009069

void FUN_10009069(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __CRT_INIT@12 at 100090cf

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
    if (DAT_10010f6c < 1) {
      return 0;
    }
    DAT_10010f6c = DAT_10010f6c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100112a0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1001129c == 2) {
      param_2 = (int *)DecodePointer(DAT_100112ac);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_100112a8);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_100112ac);
            piVar8 = (int *)DecodePointer(DAT_100112a8);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_100112a8 = (PVOID)encoded_null();
        DAT_100112ac = DAT_100112a8;
      }
      DAT_1001129c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_100112a0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_100112a0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1001129c == 0) {
      DAT_1001129c = 1;
      iVar5 = initterm_e(&DAT_1000b264,&DAT_1000b26c);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1000b230,&DAT_1000b260);
      DAT_1001129c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_100112a0,0);
    }
    if ((DAT_100112a4 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_100112a4), BVar2 != 0)) {
      (*DAT_100112a4)(param_1,2,param_3);
    }
    DAT_10010f6c = DAT_10010f6c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 100092d9

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10009379) */
/* WARNING: Removing unreachable block (ram,0x10009326) */
/* WARNING: Removing unreachable block (ram,0x100093a6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10010da0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10010f6c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10002ce7(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10002ce7(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_100093e4();
  return local_20;
}



// Function: FUN_100093e4 at 100093e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100093e4(void)

{
  _DAT_10010da0 = 0xffffffff;
  return;
}



// Function: entry at 100093ef

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 10009412

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
  
  _DAT_10011088 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1001108c = &stack0x00000004;
  _DAT_10010fc8 = 0x10001;
  _DAT_10010f70 = 0xc0000409;
  _DAT_10010f74 = 1;
  local_32c = DAT_10010d90;
  local_328 = DAT_10010d94;
  _DAT_10010f7c = unaff_retaddr;
  _DAT_10011054 = in_GS;
  _DAT_10011058 = in_FS;
  _DAT_1001105c = in_ES;
  _DAT_10011060 = in_DS;
  _DAT_10011064 = unaff_EDI;
  _DAT_10011068 = unaff_ESI;
  _DAT_1001106c = unaff_EBX;
  _DAT_10011070 = in_EDX;
  _DAT_10011074 = in_ECX;
  _DAT_10011078 = in_EAX;
  _DAT_1001107c = unaff_EBP;
  DAT_10011080 = unaff_retaddr;
  _DAT_10011084 = in_CS;
  _DAT_10011090 = in_SS;
  DAT_10010fc0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1000c084);
  if (DAT_10010fc0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10009530

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10010d90 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10009575

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



// Function: __ValidateImageBase at 100095f0

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



// Function: __FindPESection at 10009630

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



// Function: __IsNonwritableInCurrentImage at 10009680

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
  
  pcStack_10 = FUN_10008fc7;
  local_14 = ExceptionList;
  local_c = DAT_10010d90 ^ 0x1000ed40;
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



// Function: ___security_init_cookie at 10009754

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
  if ((DAT_10010d90 == 0xbb40e64e) || ((DAT_10010d90 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10010d90 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10010d90 == 0xbb40e64e) {
      DAT_10010d90 = 0xbb40e64f;
    }
    else if ((DAT_10010d90 & 0xffff0000) == 0) {
      DAT_10010d90 = DAT_10010d90 | (DAT_10010d90 | 0x4711) << 0x10;
    }
    DAT_10010d94 = ~DAT_10010d90;
  }
  else {
    DAT_10010d94 = ~DAT_10010d90;
  }
  return;
}



// Function: Unwind@10009802 at 10009802

void Unwind_10009802(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10009805. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009826 at 10009826

void Unwind_10009826(void)

{
  int unaff_EBP;
  
  FUN_1000115a(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009864 at 10009864

void Unwind_10009864(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000986c at 1000986c

void Unwind_1000986c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10009874 at 10009874

void Unwind_10009874(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000987c at 1000987c

void Unwind_1000987c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009884 at 10009884

void Unwind_10009884(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000988c at 1000988c

void Unwind_1000988c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10009894 at 10009894

void Unwind_10009894(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000989c at 1000989c

void Unwind_1000989c(void)

{
  int unaff_EBP;
  
  FUN_10001251(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@100098a4 at 100098a4

void Unwind_100098a4(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100098ac at 100098ac

void Unwind_100098ac(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@100098b4 at 100098b4

void Unwind_100098b4(void)

{
  int unaff_EBP;
  
  FUN_100016d2((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100098bc at 100098bc

void Unwind_100098bc(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100098c4 at 100098c4

void Unwind_100098c4(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100098cc at 100098cc

void Unwind_100098cc(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100098d4 at 100098d4

void Unwind_100098d4(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100098dc at 100098dc

void Unwind_100098dc(void)

{
  int unaff_EBP;
  
  FUN_10001251(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@100098e4 at 100098e4

void Unwind_100098e4(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100098ec at 100098ec

void Unwind_100098ec(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100098f4 at 100098f4

void Unwind_100098f4(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100098fc at 100098fc

void Unwind_100098fc(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10009904 at 10009904

void Unwind_10009904(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000990c at 1000990c

void Unwind_1000990c(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009914 at 10009914

void Unwind_10009914(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000991c at 1000991c

void Unwind_1000991c(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10009924 at 10009924

void Unwind_10009924(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000992c at 1000992c

void Unwind_1000992c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009934 at 10009934

void Unwind_10009934(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000993c at 1000993c

void Unwind_1000993c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10009944 at 10009944

void Unwind_10009944(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000994c at 1000994c

void Unwind_1000994c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009954 at 10009954

void Unwind_10009954(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000995c at 1000995c

void Unwind_1000995c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10009964 at 10009964

void Unwind_10009964(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000996c at 1000996c

void Unwind_1000996c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10009974 at 10009974

void Unwind_10009974(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000997c at 1000997c

void Unwind_1000997c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000999f at 1000999f

void Unwind_1000999f(void)

{
  int unaff_EBP;
  
  FUN_100010d8(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100099c2 at 100099c2

void Unwind_100099c2(void)

{
  DAT_10010e68 = DAT_10010e68 & 0xfffffffe;
  return;
}



// Function: Unwind@100099eb at 100099eb

void Unwind_100099eb(void)

{
  int unaff_EBP;
  
  FUN_10001cc8(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009a0e at 10009a0e

void Unwind_10009a0e(void)

{
  int unaff_EBP;
  
  FUN_1000270f(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009a31 at 10009a31

void Unwind_10009a31(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10009a64 at 10009a64

void Unwind_10009a64(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10009a97 at 10009a97

void Unwind_10009a97(void)

{
  int unaff_EBP;
  
  FUN_100025b2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10009abd at 10009abd

void Unwind_10009abd(void)

{
  FUN_10004a61();
  return;
}



// Function: Unwind@10009ad4 at 10009ad4

void Unwind_10009ad4(void)

{
  FUN_10004a61();
  return;
}



// Function: Unwind@10009b07 at 10009b07

void Unwind_10009b07(void)

{
  int unaff_EBP;
  
  FUN_10002b22(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10009b12 at 10009b12

void Unwind_10009b12(void)

{
  int unaff_EBP;
  
  FUN_100025b2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10009b38 at 10009b38

void Unwind_10009b38(void)

{
  int unaff_EBP;
  
  FUN_1000270f(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009b40 at 10009b40

void Unwind_10009b40(void)

{
  int unaff_EBP;
  
  FUN_10002714(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009b63 at 10009b63

void Unwind_10009b63(void)

{
  int unaff_EBP;
  
  FUN_10002714(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009b6b at 10009b6b

void Unwind_10009b6b(void)

{
  int unaff_EBP;
  
  FUN_1000270f(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009b8e at 10009b8e

void Unwind_10009b8e(void)

{
  int unaff_EBP;
  
  FUN_10002b00(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009bb1 at 10009bb1

void Unwind_10009bb1(void)

{
  int unaff_EBP;
  
  FUN_10002d29((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10009bd7 at 10009bd7

void Unwind_10009bd7(void)

{
  int unaff_EBP;
  
  FUN_1000209b(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@10009c04 at 10009c04

void Unwind_10009c04(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10009c0f at 10009c0f

void Unwind_10009c0f(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10009c1a at 10009c1a

void Unwind_10009c1a(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10009c25 at 10009c25

void Unwind_10009c25(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10009c30 at 10009c30

void Unwind_10009c30(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10009c3b at 10009c3b

void Unwind_10009c3b(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@10009c46 at 10009c46

void Unwind_10009c46(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@10009c51 at 10009c51

void Unwind_10009c51(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@10009c5c at 10009c5c

void Unwind_10009c5c(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10009c67 at 10009c67

void Unwind_10009c67(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10009c9a at 10009c9a

void Unwind_10009c9a(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009ca2 at 10009ca2

void Unwind_10009ca2(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009caa at 10009caa

void Unwind_10009caa(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009cb2 at 10009cb2

void Unwind_10009cb2(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009cba at 10009cba

void Unwind_10009cba(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009cdd at 10009cdd

void Unwind_10009cdd(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10009ce8 at 10009ce8

void Unwind_10009ce8(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10009cf3 at 10009cf3

void Unwind_10009cf3(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10009cfe at 10009cfe

void Unwind_10009cfe(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10009d09 at 10009d09

void Unwind_10009d09(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10009d14 at 10009d14

void Unwind_10009d14(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10009d47 at 10009d47

void Unwind_10009d47(void)

{
  int unaff_EBP;
  
  FUN_1000115a(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009d4f at 10009d4f

void Unwind_10009d4f(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10009d5a at 10009d5a

void Unwind_10009d5a(void)

{
  int unaff_EBP;
  
  FUN_1000115a(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009d62 at 10009d62

void Unwind_10009d62(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10009d88 at 10009d88

void Unwind_10009d88(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10009d93 at 10009d93

void Unwind_10009d93(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10009d9e at 10009d9e

void Unwind_10009d9e(void)

{
  int unaff_EBP;
  
  FUN_1000115a(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009da6 at 10009da6

void Unwind_10009da6(void)

{
  int unaff_EBP;
  
  FUN_1000115a(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009dc9 at 10009dc9

void Unwind_10009dc9(void)

{
  int unaff_EBP;
  
  FUN_10002b97((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10009dec at 10009dec

void Unwind_10009dec(void)

{
  int unaff_EBP;
  
  FUN_10002b22(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10009df7 at 10009df7

void Unwind_10009df7(void)

{
  int unaff_EBP;
  
  FUN_100025b2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10009e1d at 10009e1d

void Unwind_10009e1d(void)

{
  int unaff_EBP;
  
  FUN_100025b2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10009e28 at 10009e28

void Unwind_10009e28(void)

{
  int unaff_EBP;
  
  FUN_10002b22(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10009e4e at 10009e4e

void Unwind_10009e4e(void)

{
  int unaff_EBP;
  
  FUN_100025b2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10009e59 at 10009e59

void Unwind_10009e59(void)

{
  int unaff_EBP;
  
  FUN_10002b22(*(int *)(unaff_EBP + -0x10) + 0x18);
  return;
}



// Function: Unwind@10009e64 at 10009e64

void Unwind_10009e64(void)

{
  int unaff_EBP;
  
  FUN_10003760(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10009e6f at 10009e6f

void Unwind_10009e6f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10009e95 at 10009e95

void Unwind_10009e95(void)

{
  int unaff_EBP;
  
  FUN_10002b22(*(int *)(unaff_EBP + -0x10) + 0x18);
  return;
}



// Function: Unwind@10009ea0 at 10009ea0

void Unwind_10009ea0(void)

{
  int unaff_EBP;
  
  FUN_10003760(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10009eab at 10009eab

void Unwind_10009eab(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10009eb6 at 10009eb6

void Unwind_10009eb6(void)

{
  int unaff_EBP;
  
  FUN_100025b2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10009edc at 10009edc

void Unwind_10009edc(void)

{
  int unaff_EBP;
  
  FUN_10002b05((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10009ee4 at 10009ee4

void Unwind_10009ee4(void)

{
  int unaff_EBP;
  
  FUN_10002b05((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10009f07 at 10009f07

void Unwind_10009f07(void)

{
  int unaff_EBP;
  
  FUN_10002b15((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10009f12 at 10009f12

void Unwind_10009f12(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10009f1d at 10009f1d

void Unwind_10009f1d(void)

{
  int unaff_EBP;
  
  FUN_10002b15((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10009f50 at 10009f50

void Unwind_10009f50(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@10009f5b at 10009f5b

void Unwind_10009f5b(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@10009f66 at 10009f66

void Unwind_10009f66(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@10009f71 at 10009f71

void Unwind_10009f71(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@10009f7c at 10009f7c

void Unwind_10009f7c(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@10009faf at 10009faf

void Unwind_10009faf(void)

{
  int unaff_EBP;
  
  FUN_10002b97((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10009fd2 at 10009fd2

void Unwind_10009fd2(void)

{
  int unaff_EBP;
  
  FUN_10003896(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10009ff5 at 10009ff5

void Unwind_10009ff5(void)

{
  int unaff_EBP;
  
  FUN_10003ae2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a018 at 1000a018

void Unwind_1000a018(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a01b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a03c at 1000a03c

void Unwind_1000a03c(void)

{
  int unaff_EBP;
  
  FUN_10004b97(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a05f at 1000a05f

void Unwind_1000a05f(void)

{
  int unaff_EBP;
  
  FUN_1000115a(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a067 at 1000a067

void Unwind_1000a067(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000a08d at 1000a08d

void Unwind_1000a08d(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000a098 at 1000a098

void Unwind_1000a098(void)

{
  int unaff_EBP;
  
  FUN_1000115a(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a0bb at 1000a0bb

void Unwind_1000a0bb(void)

{
  int unaff_EBP;
  
  FUN_10004e96((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000a0de at 1000a0de

void Unwind_1000a0de(void)

{
  int unaff_EBP;
  
  FUN_10004e96((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000a101 at 1000a101

void Unwind_1000a101(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a107. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1000a10d at 1000a10d

void Unwind_1000a10d(void)

{
  int unaff_EBP;
  
  FUN_10004efa((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@1000a133 at 1000a133

void Unwind_1000a133(void)

{
  int unaff_EBP;
  
  FUN_1000534b(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a156 at 1000a156

void Unwind_1000a156(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a159. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a195 at 1000a195

void Unwind_1000a195(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a198. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a1b9 at 1000a1b9

void Unwind_1000a1b9(void)

{
  int unaff_EBP;
  
  FUN_10005904(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a1dc at 1000a1dc

void Unwind_1000a1dc(void)

{
  int unaff_EBP;
  
  FUN_10005904(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a1e4 at 1000a1e4

void Unwind_1000a1e4(void)

{
  int unaff_EBP;
  
  FUN_1000534b(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a207 at 1000a207

void Unwind_1000a207(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a20a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000a210 at 1000a210

void Unwind_1000a210(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1000a226. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@1000a22d at 1000a22d

void Unwind_1000a22d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000a233. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1000a239 at 1000a239

void Unwind_1000a239(void)

{
  int unaff_EBP;
  
  FUN_10004efa((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000a27a at 1000a27a

void Unwind_1000a27a(void)

{
  int unaff_EBP;
  
  FUN_100025b2((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000a285 at 1000a285

void Unwind_1000a285(void)

{
  int unaff_EBP;
  
  FUN_10002b22(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000a2ab at 1000a2ab

void Unwind_1000a2ab(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000a2d8 at 1000a2d8

void Unwind_1000a2d8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a318 at 1000a318

void Unwind_1000a318(void)

{
  int unaff_EBP;
  
  FUN_10002bae(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a33b at 1000a33b

void Unwind_1000a33b(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a345 at 1000a345

void Unwind_1000a345(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a368 at 1000a368

void Unwind_1000a368(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a370 at 1000a370

void Unwind_1000a370(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a378 at 1000a378

void Unwind_1000a378(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a380 at 1000a380

void Unwind_1000a380(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a388 at 1000a388

void Unwind_1000a388(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a390 at 1000a390

void Unwind_1000a390(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a3b3 at 1000a3b3

void Unwind_1000a3b3(void)

{
  int unaff_EBP;
  
  FUN_10002b97((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a3d6 at 1000a3d6

void Unwind_1000a3d6(void)

{
  int unaff_EBP;
  
  FUN_10002b97((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1000a3e1 at 1000a3e1

void Unwind_1000a3e1(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000a3ec at 1000a3ec

void Unwind_1000a3ec(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000a3f7 at 1000a3f7

void Unwind_1000a3f7(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000a402 at 1000a402

void Unwind_1000a402(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000a40d at 1000a40d

void Unwind_1000a40d(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000a418 at 1000a418

void Unwind_1000a418(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000a423 at 1000a423

void Unwind_1000a423(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000a42e at 1000a42e

void Unwind_1000a42e(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000a439 at 1000a439

void Unwind_1000a439(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000a444 at 1000a444

void Unwind_1000a444(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000a477 at 1000a477

void Unwind_1000a477(void)

{
  int unaff_EBP;
  
  FUN_10006033(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000a49d at 1000a49d

void Unwind_1000a49d(void)

{
  int unaff_EBP;
  
  FUN_10006033(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000a4a8 at 1000a4a8

void Unwind_1000a4a8(void)

{
  int unaff_EBP;
  
  FUN_10003ae2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a4cb at 1000a4cb

void Unwind_1000a4cb(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a4d3 at 1000a4d3

void Unwind_1000a4d3(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_100012a4((int *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000a4ec at 1000a4ec

void Unwind_1000a4ec(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a4f4 at 1000a4f4

void Unwind_1000a4f4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_100012a4((int *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000a50d at 1000a50d

void Unwind_1000a50d(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a515 at 1000a515

void Unwind_1000a515(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a538 at 1000a538

void Unwind_1000a538(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000a543 at 1000a543

void Unwind_1000a543(void)

{
  int unaff_EBP;
  
  FUN_10002b15((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000a576 at 1000a576

void Unwind_1000a576(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a599 at 1000a599

void Unwind_1000a599(void)

{
  int unaff_EBP;
  
  FUN_10002b00(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000a5a4 at 1000a5a4

void Unwind_1000a5a4(void)

{
  int unaff_EBP;
  
  FUN_10002d29((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000a5af at 1000a5af

void Unwind_1000a5af(void)

{
  int unaff_EBP;
  
  FUN_10002d53((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000a5ba at 1000a5ba

void Unwind_1000a5ba(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000a5ed at 1000a5ed

void Unwind_1000a5ed(void)

{
  int unaff_EBP;
  
  FUN_10002b00(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000a5f8 at 1000a5f8

void Unwind_1000a5f8(void)

{
  int unaff_EBP;
  
  FUN_10002d29((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000a603 at 1000a603

void Unwind_1000a603(void)

{
  int unaff_EBP;
  
  FUN_10002d53((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000a60e at 1000a60e

void Unwind_1000a60e(void)

{
  int unaff_EBP;
  
  FUN_1000256b((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000a65c at 1000a65c

void Unwind_1000a65c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a681 at 1000a681

void Unwind_1000a681(void)

{
  int unaff_EBP;
  
  FUN_10002bd9(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000a6a7 at 1000a6a7

void Unwind_1000a6a7(void)

{
  int unaff_EBP;
  
  FUN_10002bd9(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000a6b2 at 1000a6b2

void Unwind_1000a6b2(void)

{
  int unaff_EBP;
  
  FUN_10002bae(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a6d5 at 1000a6d5

void Unwind_1000a6d5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a6fa at 1000a6fa

void Unwind_1000a6fa(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000a702 at 1000a702

void Unwind_1000a702(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@1000a71b at 1000a71b

void Unwind_1000a71b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000a723 at 1000a723

void Unwind_1000a723(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000a750 at 1000a750

void Unwind_1000a750(void)

{
  FUN_10004a61();
  return;
}



// Function: Unwind@1000a779 at 1000a779

void Unwind_1000a779(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000a7c8 at 1000a7c8

void Unwind_1000a7c8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000a7d0 at 1000a7d0

void Unwind_1000a7d0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000a7d8 at 1000a7d8

void Unwind_1000a7d8(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000a7e3 at 1000a7e3

void Unwind_1000a7e3(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000a7ee at 1000a7ee

void Unwind_1000a7ee(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1000a7f6 at 1000a7f6

void Unwind_1000a7f6(void)

{
  int unaff_EBP;
  
  FUN_10005b08(unaff_EBP + -0x138);
  return;
}



// Function: Unwind@1000a801 at 1000a801

void Unwind_1000a801(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1000a809 at 1000a809

void Unwind_1000a809(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1000a814 at 1000a814

void Unwind_1000a814(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1000a81f at 1000a81f

void Unwind_1000a81f(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1000a82a at 1000a82a

void Unwind_1000a82a(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1000a878 at 1000a878

void Unwind_1000a878(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000a880 at 1000a880

void Unwind_1000a880(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000a8ad at 1000a8ad

void Unwind_1000a8ad(void)

{
  int unaff_EBP;
  
  FUN_10002732((undefined4 *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000a8b8 at 1000a8b8

void Unwind_1000a8b8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0xa2c));
  return;
}



// Function: Unwind@1000a8eb at 1000a8eb

void Unwind_1000a8eb(void)

{
  FUN_10002714(0x10010edc);
  return;
}



// Function: Unwind@1000a8f5 at 1000a8f5

void Unwind_1000a8f5(void)

{
  FUN_1000270f(0x10010edc);
  return;
}



// Function: Unwind@1000a91a at 1000a91a

void Unwind_1000a91a(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a922 at 1000a922

void Unwind_1000a922(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a92a at 1000a92a

void Unwind_1000a92a(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a932 at 1000a932

void Unwind_1000a932(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a93a at 1000a93a

void Unwind_1000a93a(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a942 at 1000a942

void Unwind_1000a942(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a94a at 1000a94a

void Unwind_1000a94a(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a952 at 1000a952

void Unwind_1000a952(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a975 at 1000a975

void Unwind_1000a975(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a97d at 1000a97d

void Unwind_1000a97d(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a985 at 1000a985

void Unwind_1000a985(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a98d at 1000a98d

void Unwind_1000a98d(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a995 at 1000a995

void Unwind_1000a995(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a99d at 1000a99d

void Unwind_1000a99d(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a9a5 at 1000a9a5

void Unwind_1000a9a5(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a9ad at 1000a9ad

void Unwind_1000a9ad(void)

{
  int unaff_EBP;
  
  FUN_100010d8((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000a9b5 at 1000a9b5

void Unwind_1000a9b5(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000a9bd at 1000a9bd

void Unwind_1000a9bd(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000a9c5 at 1000a9c5

void Unwind_1000a9c5(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000a9e8 at 1000a9e8

void Unwind_1000a9e8(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a9f0 at 1000a9f0

void Unwind_1000a9f0(void)

{
  int unaff_EBP;
  
  FUN_100012a4((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000a9f8 at 1000a9f8

void Unwind_1000a9f8(void)

{
  int unaff_EBP;
  
  FUN_1000115a((int *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_1000ab35 at 1000ab35

void FUN_1000ab35(void)

{
  FID_conflict__Tidy(&DAT_10010db0,'\x01',0);
  return;
}



// Function: FUN_1000ab44 at 1000ab44

void FUN_1000ab44(void)

{
  FID_conflict__Tidy(&DAT_10010dcc,'\x01',0);
  return;
}



// Function: FUN_1000ab53 at 1000ab53

void FUN_1000ab53(void)

{
  FID_conflict__Tidy(&DAT_10010de8,'\x01',0);
  return;
}



// Function: FUN_1000ab62 at 1000ab62

void FUN_1000ab62(void)

{
  FID_conflict__Tidy(&DAT_10010e04,'\x01',0);
  return;
}



// Function: FUN_1000ab71 at 1000ab71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ab71(void)

{
  _DAT_10010edc = ATL::CComModule::vftable;
  FUN_100026d6(0x10010edc);
  return;
}



// Function: FUN_1000ab9b at 1000ab9b

void FUN_1000ab9b(void)

{
  FID_conflict__Tidy(&DAT_10010e6c,'\x01',0);
  return;
}



// Function: FUN_1000abaa at 1000abaa

void FUN_1000abaa(void)

{
  FID_conflict__Tidy(&DAT_10010e88,'\x01',0);
  return;
}



// Function: FUN_1000abb9 at 1000abb9

void FUN_1000abb9(void)

{
  FID_conflict__Tidy(&DAT_10010ea4,'\x01',0);
  return;
}



// Function: FUN_1000abc8 at 1000abc8

void FUN_1000abc8(void)

{
  FID_conflict__Tidy(&DAT_10010ec0,'\x01',0);
  return;
}



// Function: FUN_1000abd7 at 1000abd7

void FUN_1000abd7(void)

{
  FUN_10008a82((int *)&DAT_10010f0c);
  return;
}



// Function: FUN_1000abe1 at 1000abe1

void FUN_1000abe1(void)

{
  FUN_10008b64(0x10010f34);
  return;
}



