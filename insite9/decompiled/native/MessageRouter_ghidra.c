/*
 * Decompiled from: MessageRouter.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

undefined4 FUN_10001000(void)

{
  undefined4 *in_stack_00000018;
  
  *in_stack_00000018 = 0x60030000;
  return 0;
}



// Function: FUN_10001012 at 10001012

void __fastcall FUN_10001012(int *param_1)

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



// Function: FUN_1000104d at 1000104d

void FUN_1000104d(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10018ba0);
}



// Function: AtlCrtErrorCheck at 10001065

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
    if (param_1 == 0x16) goto LAB_1000108d;
    if (param_1 == 0x22) goto LAB_1000108d;
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar1 = 0x80004005;
  }
  do {
    FUN_1000104d(uVar1);
LAB_1000108d:
    uVar1 = 0x80070057;
  } while( true );
}



// Function: FUN_1000109d at 1000109d

void __fastcall FUN_1000109d(int *param_1)

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



// Function: FUN_100010e3 at 100010e3

void __fastcall FUN_100010e3(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100010f5 at 100010f5

void __fastcall FUN_100010f5(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_1000111f at 1000111f

int * __thiscall FUN_1000111f(void *this,int param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  if ((param_2 != '\0') && (param_1 != 0)) {
    uVar1 = Ordinal_149(param_1);
    iVar2 = Ordinal_150(param_1,uVar1);
    *(int *)this = iVar2;
    if (iVar2 != 0) {
      return (int *)this;
    }
    FUN_1000f200(0x8007000e);
  }
  *(int *)this = param_1;
  return (int *)this;
}



// Function: FUN_10001167 at 10001167

void __fastcall FUN_10001167(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  return;
}



// Function: FUN_10001187 at 10001187

uint __cdecl FUN_10001187(int param_1)

{
  if (param_1 + 0x7ffbfe00U < 0xfe00) {
    return param_1 - 0x200U & 0xffff;
  }
  return 0;
}



// Function: FUN_100011a9 at 100011a9

void FUN_100011a9(void)

{
  return;
}



// Function: FUN_100011cf at 100011cf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_100011cf(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10001207 at 10001207

void __fastcall FUN_10001207(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10001221 at 10001221

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001221(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_1000fef4;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FID_conflict:_Inside at 1000124b

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



// Function: FUN_10001287 at 10001287

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10001287(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10001293;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10018c00);
}



// Function: FUN_10001318 at 10001318

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10001318(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10001346 at 10001346

uint __thiscall FUN_10001346(void *this,uint param_1,uint param_2,wchar_t *param_3,uint param_4)

{
  undefined4 *extraout_EAX;
  uint uVar1;
  uint extraout_ECX;
  uint extraout_EDX;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
    std::_Xout_of_range("invalid string position");
    this = extraout_EAX;
    uVar1 = extraout_ECX;
    param_1 = extraout_EDX;
  }
  if (uVar1 - param_1 < param_2) {
    param_2 = uVar1 - param_1;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  uVar1 = _wcsicmp((wchar_t *)((int)this + param_1 * 2),param_3);
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



// Function: FUN_1000139e at 1000139e

int * __thiscall FUN_1000139e(void *this,int param_1)

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
      FUN_1000104d(0x8007000e);
    }
    *(undefined4 *)this = 0;
  }
  return (int *)this;
}



// Function: FUN_100013db at 100013db

void __fastcall FUN_100013db(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_100013f8 at 100013f8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_100013f8(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_100010fe);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10001455 at 10001455

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10001455(void *this,int param_1,char param_2)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_1000111f(this_00,param_1,param_2);
  }
  *(int **)this = piVar1;
  if (piVar1 == (int *)0x0) {
    FUN_1000f200(0x8007000e);
  }
  return (undefined4 *)this;
}



// Function: FUN_100014a5 at 100014a5

undefined4 __fastcall FUN_100014a5(int param_1)

{
  LPWSTR lpBuffer;
  short *psVar1;
  int iVar2;
  wchar_t *_Dst;
  uint uVar3;
  wchar_t *_Format;
  uint uVar4;
  
  lpBuffer = (LPWSTR)(param_1 + 0xc);
  if (*(int *)lpBuffer == 0) {
    FormatMessageW(0x1300,(LPCVOID)0x0,*(DWORD *)(param_1 + 4),0x400,lpBuffer,0,(va_list *)0x0);
    if (*(LPCWSTR *)lpBuffer == (LPCWSTR)0x0) {
      _Dst = (wchar_t *)LocalAlloc(0,0x40);
      *(wchar_t **)lpBuffer = _Dst;
      if (_Dst != (wchar_t *)0x0) {
        uVar4 = *(uint *)(param_1 + 4);
        uVar3 = FUN_10001187(uVar4);
        if ((short)uVar3 == 0) {
          _Format = L"Unknown error 0x%0lX";
        }
        else {
          _Format = L"IDispatch error #%d";
          uVar4 = uVar3 & 0xffff;
        }
        swprintf_s(_Dst,0x20,_Format,uVar4);
      }
    }
    else {
      iVar2 = lstrlenW(*(LPCWSTR *)lpBuffer);
      if ((1 < iVar2) && (psVar1 = (short *)(*(int *)lpBuffer + -2 + iVar2 * 2), *psVar1 == 10)) {
        *psVar1 = 0;
        psVar1 = (short *)(*(int *)lpBuffer + -4 + iVar2 * 2);
        if (*psVar1 == 0xd) {
          *psVar1 = 0;
        }
      }
    }
  }
  return *(undefined4 *)lpBuffer;
}



// Function: FUN_1000154f at 1000154f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000154f(int param_1)

{
  FUN_10001221((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FID_conflict:_Tidy at 10001570

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



// Function: FUN_100015b9 at 100015b9

undefined4 * __thiscall FUN_100015b9(void *this,uint param_1,uint param_2)

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



// Function: FUN_1000163a at 1000163a

undefined4 FUN_1000163a(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((param_2 != 0) && (iVar1 = Ordinal_7(param_2), iVar1 != 0)) && (param_3 != 0)) &&
     (iVar1 = Ordinal_7(param_3), iVar1 != 0)) {
    FUN_1000139e((void *)(param_1 + 0x28),param_2);
    FUN_1000139e((void *)(param_1 + 0x2c),param_3);
    return 0;
  }
  return 0x80070057;
}



// Function: FUN_10001689 at 10001689

void __thiscall FUN_10001689(void *this,int param_1)

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



// Function: FUN_100016ce at 100016ce

void __thiscall FUN_100016ce(void *this,wchar_t *param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = param_1 + 8;
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(wchar_t **)param_1;
  }
  FUN_10001346(this,0,*(uint *)((int)this + 0x10),param_1,*(uint *)pwVar1);
  return;
}



// Function: FUN_100016ef at 100016ef

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100016ef(IID *param_1,WCHAR *param_2,int param_3,int param_4,undefined4 param_5,int param_6
                 ,HINSTANCE param_7)

{
  int iVar1;
  errno_t eVar2;
  int local_828;
  int local_824;
  int *local_820;
  LPOLESTR local_81c;
  int *local_818;
  WCHAR local_814 [1030];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x81c;
  local_824 = param_4;
  local_828 = 0;
  local_8 = 0;
  local_814[0] = L'\0';
  if (((uint)param_2 & 0xffff0000) == 0) {
    iVar1 = LoadStringW(param_7,(uint)param_2 & 0xffff,local_814,0x400);
    if (iVar1 == 0) {
      eVar2 = wcscpy_s(local_814,0x400,L"Unknown Error");
      ATL::AtlCrtErrorCheck(eVar2);
    }
    param_2 = local_814;
  }
  local_818 = (int *)0x0;
  local_8._0_1_ = 2;
  iVar1 = Ordinal_202(&local_818);
  if (-1 < iVar1) {
    local_820 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
    (**(code **)(*local_818 + 0xc))(local_818,param_5);
    ProgIDFromCLSID(param_1,&local_81c);
    if (local_81c != (LPOLESTR)0x0) {
      (**(code **)(*local_818 + 0x10))(local_818,local_81c);
    }
    if ((param_3 != 0) && (local_824 != 0)) {
      (**(code **)(*local_818 + 0x1c))(local_818,param_3);
      (**(code **)(*local_818 + 0x18))(local_818,local_824);
    }
    CoTaskMemFree(local_81c);
    (**(code **)(*local_818 + 0x14))(local_818,param_2);
    iVar1 = (**(code **)*local_818)(local_818,&DAT_10013460,&local_820);
    if (-1 < iVar1) {
      Ordinal_201(0,local_820);
    }
    local_8._0_1_ = 2;
    if (local_820 != (int *)0x0) {
      (**(code **)(*local_820 + 8))(local_820);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_818 != (int *)0x0) {
    (**(code **)(*local_818 + 8))(local_818);
  }
  local_8 = 0xffffffff;
  FUN_10001207(&local_828);
  FUN_1000f487();
  return;
}



// Function: FUN_100018a3 at 100018a3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_100018a3(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x100018af;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  if (param_1 == (undefined4 *)0x0) {
    local_14[0] = 0;
  }
  else {
    local_14[0] = Ordinal_2(param_1);
    if (local_14[0] == 0) {
      FUN_1000104d(0x8007000e);
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
  }
  local_8 = 0;
  uVar2 = FUN_100013db(local_14);
  local_8 = 0xffffffff;
  Ordinal_6(local_14[0]);
  return uVar2;
}



// Function: ~basic_string<> at 100018fc

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



// Function: FUN_10001906 at 10001906

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_10001906(void *this,uint param_1)

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
  FUN_10001287((char *)(param_1 + 1));
  FUN_1000199b();
  return;
}



// Function: Catch@1000196d at 1000196d

undefined * Catch_1000196d(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001287((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001995;
}



// Function: FUN_1000199b at 1000199b

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000199b(void)

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



// Function: Catch@100019e9 at 100019e9

void Catch_100019e9(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100019fe at 100019fe

int __fastcall FUN_100019fe(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10009bbb((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2d) = 1;
  return param_1;
}



// Function: FUN_10001a35 at 10001a35

LONG __fastcall FUN_10001a35(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    FUN_10001167(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



// Function: FUN_10001a60 at 10001a60

bool __thiscall FUN_10001a60(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_10001906(this,param_1);
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



// Function: FUN_10001aca at 10001aca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001aca(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10001aec at 10001aec

undefined4 * __thiscall FUN_10001aec(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_100015b9(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_100015b9(this,0,param_2);
  }
  else {
    bVar1 = FUN_10001a60(pvVar3,uVar4,'\0');
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



// Function: FUN_10001b88 at 10001b88

void __fastcall FUN_10001b88(undefined4 *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    FUN_10001a35((int *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10001b9b at 10001b9b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10001b9b(void *this,void *param_1)

{
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10001ba7;
  local_14[0] = 0;
  if (*(int *)((int)this + 8) != 0) {
    (**(code **)(**(int **)((int)this + 8) + 0x14))(*(int **)((int)this + 8),local_14);
  }
  FUN_10001455(param_1,local_14[0],'\0');
  return param_1;
}



// Function: FID_conflict:assign at 10001be2

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
    bVar1 = FUN_10001a60(this,param_2,'\0');
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
    this = FUN_10001aec(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001c60 at 10001c60

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10001c60(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,int param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40 [4];
  undefined4 local_30;
  undefined2 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_48 = param_7;
  local_50 = param_9;
  local_8 = 0;
  puVar3 = local_40;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_44 = param_2;
  local_40[0] = *param_3;
  local_40[1] = param_3[1];
  local_40[2] = param_3[2];
  local_40[3] = param_3[3];
  local_30 = param_4;
  local_2c = param_5;
  local_28 = param_6;
  local_24 = param_7;
  local_20 = param_8;
  local_1c = param_9;
  FUN_1000e79b(&local_54,(int *)(param_1 + 0x30));
  local_8._0_1_ = 1;
  local_48 = **(int **)(param_1 + 0x6c);
  while (local_48 != *(int *)(param_1 + 0x6c)) {
    piVar1 = *(int **)(local_48 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
      local_4c = (**(code **)(*piVar1 + 0x28))
                           (piVar1,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
                            &local_44);
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    FUN_10001012(&local_48);
  }
  local_4c = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000e7b6(&local_54);
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@10001d41 at 10001d41

undefined * Catch_10001d41(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x5c);
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar1 = *(undefined4 *)((int)this + 4);
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x58) + 0x78);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,L"CEventImpl::Invoke\nCode = %08lx\nError Message = %s\nDescription = %s\n",uVar1
            ,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (*(int **)(unaff_EBP + -0x44) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013710,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -0x48) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10001db0;
}



// Function: Catch@10001db2 at 10001db2

undefined4 Catch_10001db2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10001d36;
}



// Function: FUN_10001dc3 at 10001dc3

void __thiscall FUN_10001dc3(void *this,undefined4 *param_1,wchar_t *param_2)

{
  int iVar1;
  wchar_t **ppwVar2;
  wchar_t *local_8;
  
  local_8 = (wchar_t *)this;
  local_8 = (wchar_t *)FUN_1000a289(this,param_2);
  if (local_8 != *(wchar_t **)((int)this + 4)) {
    iVar1 = FUN_100016ce(param_2,local_8 + 6);
    if (-1 < iVar1) {
      ppwVar2 = &local_8;
      goto LAB_10001df8;
    }
  }
  ppwVar2 = &param_2;
LAB_10001df8:
  *param_1 = *ppwVar2;
  return;
}



// Function: FUN_10001e04 at 10001e04

void __thiscall FUN_10001e04(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_10001e04(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_1000608c((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_10001e48 at 10001e48

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __thiscall FUN_10001e48(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10001e8f at 10001e8f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __thiscall FUN_10001e8f(void *this,undefined4 *param_1)

{
  wchar_t *_Str;
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  _Str = (wchar_t *)FUN_100018a3(param_1);
  sVar1 = wcslen(_Str);
  FID_conflict_assign(this,(undefined4 *)_Str,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10001edc at 10001edc

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10001edc(int param_1,wchar_t *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_48 [2];
  int local_40;
  int *local_3c;
  int local_38;
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_40 = param_1;
  local_38 = -0x7fffbffb;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar2 = Ordinal_7(param_2);
    if (iVar2 != 0) {
      FUN_1000e79b(local_48,(int *)(param_1 + 0x2c));
      local_8._0_1_ = 1;
      FUN_10001e48(local_34,param_2);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_10001dc3((void *)(param_1 + 100),&local_3c,local_34);
      if (local_3c == *(int **)(param_1 + 0x68)) {
        local_38 = -0x7ff8ffa9;
      }
      else {
        piVar1 = (int *)local_3c[10];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
          local_38 = (**(code **)(*piVar1 + 0x20))
                               (piVar1,*(undefined4 *)(param_1 + 0x24),
                                *(undefined4 *)(param_1 + 0x28));
          if (-1 < local_38) {
            (**(code **)(*piVar1 + 8))(piVar1);
            FUN_100060e1((void *)(param_1 + 100),&local_3c,local_3c);
            local_38 = 0;
          }
          (**(code **)(*piVar1 + 8))(piVar1);
        }
      }
      local_8._1_3_ = (uint3)((uint)local_8 >> 8);
      local_8._0_1_ = 1;
      FID_conflict__Tidy(local_34,'\x01',0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000e7b6(local_48);
      goto LAB_10001fbc;
    }
  }
  local_38 = -0x7ff8ffa9;
LAB_10001fbc:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@10001fcb at 10001fcb

undefined * Catch_10001fcb(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x48);
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x38));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar1 = *(undefined4 *)((int)this + 4);
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x3c) + 0x74);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CEventImpl::RemoveSubscriber\nCode = %08lx\nError Message = %s\nDescription = %s\n",
            uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (*(int **)(unaff_EBP + -0x38) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x38));
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013710,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -0x34) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000203a;
}



// Function: Catch@1000203c at 1000203c

undefined4 Catch_1000203c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10001fc0;
}



// Function: FUN_1000204d at 1000204d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000204d(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_40 [2];
  undefined4 local_38;
  undefined4 local_34 [11];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0;
  FUN_1000e79b(local_40,param_1 + 0xb);
  local_8._0_1_ = 1;
  while (piVar1 = *(int **)param_1[0x1a], piVar1 != (int *)param_1[0x1a]) {
    FUN_10001e8f(local_34,piVar1 + 3);
    local_8._0_1_ = 2;
    iVar2 = *param_1;
    uVar3 = FUN_100018a3(local_34);
    local_38 = (**(code **)(iVar2 + 0x20))(param_1,uVar3);
    local_8._0_1_ = 1;
    FID_conflict__Tidy(local_34,'\x01',0);
  }
  local_38 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000e7b6(local_40);
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@100020d2 at 100020d2

undefined * Catch_100020d2(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x44);
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x38));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar1 = *(undefined4 *)((int)this + 4);
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x40) + 0x74);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CEventImpl::RemoveSubscriber\nCode = %08lx\nError Message = %s\nDescription = %s\n",
            uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (*(int **)(unaff_EBP + -0x38) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x38));
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013710,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -0x34) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10002141;
}



// Function: Catch@10002143 at 10002143

undefined4 Catch_10002143(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100020c7;
}



// Function: FUN_10002154 at 10002154

void __fastcall FUN_10002154(void *param_1)

{
  FUN_10001e04(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000217b at 1000217b

void __thiscall FUN_1000217b(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10002154(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_10001012((int *)&param_2);
      FUN_100060e1(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_100021ce at 100021ce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_100021ce(int param_1)

{
  undefined1 auStack_44 [12];
  undefined4 uStack_38;
  
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_10001318((void *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_1000e565(auStack_44,L"EventMap");
  FUN_1000e862((undefined4 *)(param_1 + 0x30));
  FUN_1000b84d(param_1 + 0x68);
  uStack_38 = 0x10002249;
  memset((void *)(param_1 + 0x78),0,0x1fe);
  return param_1;
}



// Function: FUN_10002258 at 10002258

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10002258(int param_1,wchar_t *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [2];
  int local_40;
  int local_3c;
  int *local_38;
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_40 = param_1;
  local_3c = 0x80004005;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar1 = Ordinal_7(param_2);
    if (iVar1 != 0) {
      if (param_3 == (undefined4 *)0x0) {
        local_3c = -0x7fffbffd;
      }
      else {
        local_38 = (int *)0x0;
        local_3c = (**(code **)*param_3)(param_3,&DAT_100136d0,&local_38);
        if ((-1 < local_3c) && (local_38 != (int *)0x0)) {
          FUN_1000e79b(local_48,(int *)(param_1 + 0x2c));
          local_8._0_1_ = 1;
          FUN_10001e48(local_34,param_2);
          local_8._0_1_ = 2;
          puVar2 = (undefined4 *)FUN_1000bd3f((void *)(param_1 + 100),local_34);
          *puVar2 = local_38;
          puVar2 = (undefined4 *)FUN_1000bd3f((void *)(param_1 + 100),local_34);
          (**(code **)(*(int *)*puVar2 + 4))((int *)*puVar2);
          (**(code **)(*local_38 + 8))(local_38);
          local_8._0_1_ = 1;
          FID_conflict__Tidy(local_34,'\x01',0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_1000e7b6(local_48);
        }
      }
      goto LAB_10002335;
    }
  }
  local_3c = -0x7ff8ffa9;
LAB_10002335:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@10002344 at 10002344

undefined * Catch_10002344(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x48);
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x34));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar1 = *(undefined4 *)((int)this + 4);
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x3c) + 0x74);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CEventImpl::AddSubscriber\nCode = %08lx\nError Message = %s\nDescription = %s\n",uVar1
            ,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (*(int **)(unaff_EBP + -0x34) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x34));
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013710,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100023ac;
}



// Function: Catch@100023ae at 100023ae

undefined4 Catch_100023ae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x38) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10002339;
}



// Function: _InlineIsEqualGUID at 100023bf

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



// Function: FUN_100023ef at 100023ef

bool __cdecl FUN_100023ef(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 1000240c

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



// Function: AtlCoTaskMemCAlloc at 1000242e

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



// Function: FUN_1000245b at 1000245b

LPVOID __cdecl FUN_1000245b(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_1000248b at 1000248b

bool __cdecl FUN_1000248b(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100024b8 at 100024b8

void __cdecl FUN_100024b8(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_100024d8 at 100024d8

void __cdecl FUN_100024d8(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 100024f5

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



// Function: FUN_1000251e at 1000251e

DWORD FUN_1000251e(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10002533 at 10002533

uint __cdecl FUN_10002533(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FID_conflict:RegOpenKeyExA at 10002549

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
                    /* WARNING: Could not recover jumptable at 0x10002592. Too many branches */
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



// Function: FID_conflict:RegCreateKeyExW at 100025a0

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
                    /* WARNING: Could not recover jumptable at 0x100025f5. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 10002603

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
                    /* WARNING: Could not recover jumptable at 0x10002646. Too many branches */
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



// Function: FUN_10002655 at 10002655

undefined4 __fastcall FUN_10002655(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10002659 at 10002659

void __cdecl FUN_10002659(short *param_1,int param_2,short *param_3)

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



// Function: FUN_100026a7 at 100026a7

int __fastcall FUN_100026a7(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 100026be

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10020a94 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10020a90 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10020a94 = '\x01';
    }
    if (DAT_10020a90 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10020a90)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Close at 1000272e

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



// Function: Create at 10002749

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



// Function: Open at 100027b1

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



// Function: SetStringValue at 10002800

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



// Function: FUN_10002837 at 10002837

LSTATUS __thiscall FUN_10002837(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_1000287a at 1000287a

undefined4 __fastcall FUN_1000287a(undefined4 *param_1)

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



// Function: FUN_1000289a at 1000289a

undefined4 * __thiscall FUN_1000289a(void *this,ulong param_1)

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



// Function: FUN_100028d0 at 100028d0

void __fastcall FUN_100028d0(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100028da at 100028da

undefined4 __thiscall FUN_100028da(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_1000245b(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_100024b8((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10002968 at 10002968

void __thiscall FUN_10002968(void *this,int *param_1)

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



// Function: FUN_100029af at 100029af

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100029af(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x100029bb;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10020ab8 & 1) == 0) {
    DAT_10020ab8 = DAT_10020ab8 | 1;
    DAT_10020a9c = 8;
    _DAT_10020aa4 = 0x4008;
    _DAT_10020aac = 0x13;
    DAT_10020a98 = &DAT_10013384;
    DAT_10020aa0 = &DAT_10013380;
    _DAT_10020aa8 = &DAT_1001337c;
    _DAT_10020ab0 = &DAT_10013378;
    _DAT_10020ab4 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10020a98)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x10002a32;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_10020a9c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_10002a3e;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_10002a3e:
  *(undefined4 *)(puVar4 + -4) = 0x10002a43;
  return uVar2;
}



// Function: FUN_10002a57 at 10002a57

int __cdecl FUN_10002a57(ushort param_1)

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



// Function: FUN_10002a8d at 10002a8d

void __thiscall FUN_10002a8d(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x69) == '\0') {
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



// Function: FUN_10002ad4 at 10002ad4

undefined4 __cdecl FUN_10002ad4(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10013808)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1001380c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10002b02 at 10002b02

LPCWSTR __cdecl FUN_10002b02(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10002b2f at 10002b2f

undefined4 FUN_10002b2f(ushort param_1)

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



// Function: FUN_10002b55 at 10002b55

void __fastcall FUN_10002b55(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10002b2f(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_10002b77 at 10002b77

undefined4 __thiscall FUN_10002b77(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10002b55((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_1000287a((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10002b2f(*pWVar2);
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



// Function: FUN_10002c8d at 10002c8d

undefined4 FUN_10002c8d(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_100133a8;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x100133d8);
  return 1;
}



// Function: FUN_10002cbc at 10002cbc

bool FUN_10002cbc(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10002cf1 at 10002cf1

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10002cf1(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10020a54 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10002b77(this,param_1), -1 < iVar1)) {
    FUN_10002b55((undefined4 *)this);
    iVar1 = FUN_10002b77(this,local_2008);
    if (-1 < iVar1) {
      FUN_10002b77(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002d56 at 10002d56

undefined4 FUN_10002d56(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10020a68;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10002d75 at 10002d75

undefined4 __thiscall FUN_10002d75(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10020a70 = *param_3;
    DAT_10020a74 = param_3[1];
    DAT_10020a78 = param_3[2];
    DAT_10020a7c = param_3[3];
  }
  piVar2 = DAT_10020b90;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10020b90, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10020b90 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10020b90;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10020b94; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10002dd3 at 10002dd3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002dd3(undefined4 *param_1)

{
  FUN_1000e50c(param_1);
  return;
}



// Function: FUN_10002df1 at 10002df1

void FUN_10002df1(int param_1)

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



// Function: FUN_10002e37 at 10002e37

void __fastcall FUN_10002e37(undefined4 *param_1)

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



// Function: FUN_10002e64 at 10002e64

void __fastcall FUN_10002e64(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10002e71 at 10002e71

int __thiscall FUN_10002e71(void *this,undefined4 *param_1)

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



// Function: FUN_10002ea8 at 10002ea8

void __fastcall FUN_10002ea8(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10002eb2 at 10002eb2

void __thiscall FUN_10002eb2(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_1000104d(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10002ed7

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  long lVar1;
  uint local_8;
  
  lVar1 = AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (lVar1 < 0) {
    FUN_1000104d(lVar1);
  }
  return local_8;
}



// Function: DllCanUnloadNow at 10002efc

HRESULT DllCanUnloadNow(void)

{
                    /* 0x2efc  1  DllCanUnloadNow */
  return (uint)(DAT_10020ac4 != 0);
}



// Function: FUN_10002f08 at 10002f08

void __fastcall FUN_10002f08(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10002f1d at 10002f1d

void __fastcall FUN_10002f1d(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x69) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x69) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x69) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x69) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_10002f58 at 10002f58

void __fastcall FUN_10002f58(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10002f62 at 10002f62

int __fastcall FUN_10002f62(int param_1)

{
  long lVar1;
  
  FUN_100026a7(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10020a6c = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10020a80 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10002fa3 at 10002fa3

void __fastcall FUN_10002fa3(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002df1((int)piVar1);
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



// Function: FUN_10002fdc at 10002fdc

void __fastcall FUN_10002fdc(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002df1((int)piVar1);
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



// Function: FUN_10002fe1 at 10002fe1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10002fe1(int param_1)

{
  FUN_10002fa3(param_1);
  return;
}



// Function: FUN_10003004 at 10003004

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10003004(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_10003004(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_1000f487();
  return;
}



// Function: FUN_100030e9 at 100030e9

undefined4 __fastcall FUN_100030e9(int *param_1)

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
LAB_1000312e:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_1000312e;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10002e37(param_1);
  return 0;
}



// Function: FUN_10003140 at 10003140

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10003140(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_100028da(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10001207(local_14);
  }
  return uVar1;
}



// Function: FUN_10003187 at 10003187

void FUN_10003187(int param_1)

{
  FUN_100030e9((int *)(param_1 + 4));
  return;
}



// Function: FUN_10003199 at 10003199

void __thiscall FUN_10003199(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x69) == '\0') {
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



// Function: FUN_100031de at 100031de

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100031de(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x100031ed;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_100033b8;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000251e();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_1000324b;
      FUN_100024d8(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_10003388;
      }
    }
    else {
LAB_10003388:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_1000324b:
  local_8 = 0xffffffff;
  FUN_10001207(&local_248);
LAB_100033b8:
  FUN_1000f487();
  return;
}



// Function: FUN_100033c0 at 100033c0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100033c0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100033e5 at 100033e5

void __fastcall FUN_100033e5(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10020b90;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10020b90, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10020b94; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10002fa3(param_1);
  return;
}



// Function: FUN_10003437 at 10003437

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003437(undefined4 *param_1)

{
  FUN_1000e50c(param_1);
  return;
}



// Function: FUN_1000345a at 1000345a

void __fastcall FUN_1000345a(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000346a at 1000346a

void __fastcall FUN_1000346a(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10002ea8(param_1);
    return;
  }
  return;
}



// Function: FUN_10003477 at 10003477

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10003477(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_100034cb at 100034cb

void __fastcall FUN_100034cb(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_100034e2 at 100034e2

undefined4 FUN_100034e2(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10002d75(&DAT_10020abc,(int *)&PTR_DAT_1001d078,param_1,(undefined4 *)&DAT_100136a0);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_100033e5(0x10020abc);
  }
  return 1;
}



// Function: FUN_10003524 at 10003524

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003524(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10001318(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: InlineIsEqualUnknown at 1000355f

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



// Function: FUN_1000358d at 1000358d

undefined4 FUN_1000358d(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_100035cb at 100035cb

undefined4 FUN_100035cb(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10020a6c + 8))();
  }
  else {
    (**(code **)(*DAT_10020a6c + 4))();
  }
  return 0;
}



// Function: FUN_100035ea at 100035ea

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_100035ea(undefined4 *param_1)

{
  FUN_10002f62((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10020a8c = param_1;
  return param_1;
}



// Function: FUN_1000361f at 1000361f

void __fastcall FUN_1000361f(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000362a at 1000362a

void __fastcall FUN_1000362a(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003635 at 10003635

HRESULT __thiscall FUN_10003635(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_10016048,(LPUNKNOWN)0x0,1,(IID *)&DAT_10013a14,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10003681 at 10003681

undefined4 FUN_10003681(void)

{
  return 0x80004005;
}



// Function: FUN_10003689 at 10003689

void FUN_10003689(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_10013a24);
  return;
}



// Function: FUN_100036a3 at 100036a3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100036a3(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10002fa3((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100036da at 100036da

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100036da(int *param_1)

{
  FUN_100030e9(param_1);
  FUN_10002e37(param_1);
  return;
}



// Function: FUN_10003704 at 10003704

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003704(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_100030e9(param_1 + 1);
  FUN_100036da(param_1 + 1);
  return;
}



// Function: FUN_10003738 at 10003738

undefined4 FUN_10003738(void)

{
  return 0x80004001;
}



// Function: FUN_10003740 at 10003740

undefined4 FUN_10003740(void)

{
  return 1;
}



// Function: FUN_10003746 at 10003746

undefined4 FUN_10003746(void)

{
  return 0;
}



// Function: FUN_1000374b at 1000374b

undefined4 * __thiscall FUN_1000374b(void *this,byte param_1)

{
  FUN_10003704((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000376a at 1000376a

undefined4 __fastcall FUN_1000376a(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10002e71((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_100037ab at 100037ab

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100037ab(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x100037b7;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_1000289a(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10002d56(&local_5d);
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
LAB_100038a0:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_10003914;
                }
                iVar3 = FUN_1000287a((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_100028da(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_1000393a;
                  goto LAB_100038dc;
                }
                local_55 = '\0';
              }
              else {
LAB_100038dc:
                if (local_55 != '\0') goto LAB_10003914;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_10003140(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_1000393a;
                local_56 = '\0';
              }
              goto LAB_10003914;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_10003140(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_100038a0;
            }
LAB_1000393a:
            local_5c = -0x7ff8fff2;
            goto LAB_1000381b;
          }
LAB_10003914:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_10002b02(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_1000381b;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_1000376a(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_10003140(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_1000393a;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_100039ad;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_1000381b;
            }
            iVar3 = FUN_100028da(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_1000393a;
          }
          else {
            iVar3 = FUN_100028da(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_100039ad:
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
LAB_1000381b:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_1000f487();
  return;
}



// Function: FUN_10003a18 at 10003a18

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003a18(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&PTR_10016038), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_10016058,(LPUNKNOWN)0x0,1,(IID *)&DAT_10013b14,&local_1a8
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
          goto LAB_10003ca3;
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
      FUN_10001207(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_10003ca3:
  FUN_1000f487();
  return;
}



// Function: FUN_10003d36 at 10003d36

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003d36(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_100031de(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10002d56((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_10003e06 at 10003e06

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003e06(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_100031de(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_10002d56(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10003fc8;
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
LAB_10003fc8:
  FUN_1000f487();
  return;
}



// Function: FUN_10003fd0 at 10003fd0

int FUN_10003fd0(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_100023ef(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_10003a18((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_10003e06(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10004056 at 10004056

int FUN_10004056(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_100023ef(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_10003a18((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_10003d36(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_100040dd at 100040dd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_100040dd(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_10013b74,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_10004198;
          }
          else {
LAB_10004198:
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



// Function: FUN_100041c8 at 100041c8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100041c8(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10001221((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_100041f9 at 100041f9

undefined4 * __thiscall FUN_100041f9(void *this,byte param_1)

{
  FUN_100041c8((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004218 at 10004218

undefined4 __thiscall FUN_10004218(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10003477(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 1000426f

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
    FUN_10002eb2(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000429e

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
    FUN_10002eb2(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100042cd

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
    FUN_10002eb2(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100042fc at 100042fc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100042fc(undefined4 *param_1)

{
  FUN_10003524(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: AtlInternalQueryInterface at 1000432a

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
          if (pcVar1 == (code *)0x1) goto LAB_1000435e;
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
LAB_1000435e:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_100043cb at 100043cb

LONG FUN_100043cb(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10020a6c + 4))();
  }
  return LVar1;
}



// Function: FUN_100043f5 at 100043f5

LONG FUN_100043f5(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10020a6c + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 10004434

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013ba0,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000444e at 1000444e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000444e(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_100041c8(param_1);
  return;
}



// Function: FUN_1000447d at 1000447d

undefined4 * __thiscall FUN_1000447d(void *this,byte param_1)

{
  FUN_1000444e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000449c at 1000449c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000449c(_Container_base12 *param_1)

{
  std::_Container_base12::_Orphan_all(param_1);
  operator_delete(*(void **)param_1);
  *(undefined4 *)param_1 = 0;
  std::_Container_base12::~_Container_base12(param_1);
  return;
}



// Function: FUN_100044d4 at 100044d4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100044d4(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1000f311(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_1000453a();
    return uVar3;
  }
  return 0;
}



// Function: Catch@1000452e at 1000452e

undefined * Catch_1000452e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004538;
}



// Function: FUN_1000453a at 1000453a

void FUN_1000453a(void)

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
  uVar4 = FUN_1000f311(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_1000458b();
  return;
}



// Function: Catch@1000457c at 1000457c

undefined * Catch_1000457c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10004589;
}



// Function: FUN_1000458b at 1000458b

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_1000458b(void)

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
    FUN_100024b8(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_100024b8(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_10004218(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_100045e7;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_100045e7:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_1000461f at 1000461f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000461f(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_100044d4(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10001207(local_14);
  }
  return iVar1;
}



// Function: FUN_1000467a at 1000467a

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_1000467a(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_10010684;
  local_10 = ExceptionList;
  uStack_2144 = DAT_10020a54 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_10002b77(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_100029af(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_100049f3;
  FUN_10002b55((undefined4 *)this);
  iVar1 = FUN_10002b77(this,local_2018);
  if (iVar1 < 0) goto LAB_100049f3;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_100049cf:
    if (uVar2 != 0) {
      FUN_10002533(uVar2);
      goto LAB_100049f3;
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
        FUN_10004902();
        return;
      }
      goto LAB_100049f3;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10001207((int *)&local_2124);
      goto LAB_100049cf;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_1000479b();
      return;
    }
  }
  FUN_10002b77(this,param_3);
LAB_100049f3:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000478f at 1000478f

undefined * Catch_1000478f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10004799;
}



// Function: FUN_1000479b at 1000479b

void FUN_1000479b(void)

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
    pWVar2 = (WCHAR *)FUN_10002837(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10002ea8((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_10002b77(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_10002533((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10004a0b;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100048e7 at 100048e7

undefined * Catch_100048e7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_100048f4;
}



// Function: FUN_10004902 at 10004902

void FUN_10004902(void)

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
      FUN_10002ea8((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_10002a57(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_10002ea8((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_10002b77(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_10002533(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10004a0b;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10004a0f at 10004a0f

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10004a0f(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_100106e3;
  local_10 = ExceptionList;
  local_14 = DAT_10020a54 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_10004a73:
  iVar3 = FUN_10002b77(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_10004a83:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_10004ee0:
    if (*param_1 == L'}') goto LAB_10004a83;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_10002b77(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10004a83;
      if (param_3 == 0) goto LAB_10004bc2;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_10002b02(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_10002c8d(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_10003004(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_10004bc2;
        }
        iVar3 = FUN_10002b77(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10002cf1(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_10004fdf;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_1000505e;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_10004a83;
    }
LAB_10004bc2:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_10002b77(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10004a83;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10002b02(param_1,L'\\');
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
          iVar3 = FUN_10002b77(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10002cf1(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_10004a0f(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_10002b77(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_1000507d;
          iVar3 = FUN_10002b77(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_1000467a(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_10004fe4;
        }
      }
      goto LAB_10004a83;
    }
    iVar3 = FUN_10002b77(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_10002b77(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_10004a83;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_1000467a(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_10004fdf;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_1000505e;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10002533(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_1000505e:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_10004a83;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10002cf1(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_10002cbc(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_10002c8d(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_10003004(&local_2234,local_21c);
        }
        goto LAB_10004ee0;
      }
      bVar2 = FUN_10002cbc(local_2234);
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
            FUN_10002533(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_1000505e;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_10004fdf:
          ATL::CRegKey::Close(pCVar8);
LAB_10004fe4:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_10004a0f(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_10004a73;
            goto LAB_10004a83;
          }
        }
        goto LAB_10004ee0;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_10004ee0;
    }
LAB_1000507d:
    FUN_10002533(uVar6);
    goto LAB_10004a83;
  }
  goto LAB_10004ee0;
}



// Function: FUN_100050a6 at 100050a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_100050a6(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10020b98);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_10013b74,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10020b98);
          if (*piVar2 != 0) goto LAB_1000513a;
        }
        else {
LAB_1000513a:
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
  piVar2 = FUN_100040dd((int *)&DAT_10020b88,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_10005172 at 10005172

void FUN_10005172(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10003fd0(0x10020b88,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10020a84 != (code *)0x0)) {
    (*DAT_10020a84)(DAT_10020bb4);
  }
  return;
}



// Function: FUN_100051a0 at 100051a0

void FUN_100051a0(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_10020a88 != (code *)0x0) && (iVar1 = (*DAT_10020a88)(), iVar1 < 0)) {
    return;
  }
  FUN_10004056(0x10020b88,param_1,param_2);
  return;
}



// Function: DllGetClassObject at 100051c6

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x51c6  2  DllGetClassObject */
  piVar1 = FUN_100050a6(&DAT_10020abc,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: Catch@10005232 at 10005232

undefined1 * Catch_10005232(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000523c;
}



// Function: FUN_10005284 at 10005284

void __fastcall FUN_10005284(int param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar2 = iVar4;
  while (iVar2 != 0) {
    if (iVar4 != 0) {
      iVar4 = iVar4 + -1;
      *(int *)(param_1 + 0x10) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
    }
    iVar2 = *(int *)(param_1 + 0x10);
  }
  iVar4 = *(int *)(param_1 + 8);
  while (pvVar3 = *(void **)(param_1 + 4), iVar4 != 0) {
    iVar4 = iVar4 + -1;
    piVar1 = (int *)((int)pvVar3 + iVar4 * 4);
    if (*piVar1 != 0) {
      operator_delete((void *)*piVar1);
    }
  }
  if (pvVar3 != (void *)0x0) {
    operator_delete(pvVar3);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



// Function: FUN_100052d5 at 100052d5

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100052d5(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10020a54 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_100037ab(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_100053cb:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10005320:
  if ((((sVar1 == 0) || (iVar3 = FUN_10002b77(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10002ad4(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_10002b77(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_100053bd;
  if (param_2 == 0) {
    iVar3 = FUN_10004a0f(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_100053bd;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_10004a0f(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_10004a0f(this,local_2008,pHVar4,0,0);
LAB_100053bd:
      CoTaskMemFree(local_200c);
      goto LAB_100053cb;
    }
  }
  FUN_10002b55((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10005320;
}



// Function: FUN_1000540c at 1000540c

int __thiscall FUN_1000540c(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_100023ef(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10003a18((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_10005172(param_1,param_2);
  return iVar5;
}



// Function: FUN_1000547b at 1000547b

int __thiscall FUN_1000547b(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_100023ef(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10003a18((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_100051a0(param_1,param_2);
  return iVar5;
}



// Function: DllRegisterServer at 100054ea

void DllRegisterServer(void)

{
                    /* 0x54ea  3  DllRegisterServer */
  FUN_1000540c(&DAT_10020abc,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 100054f9

void DllUnregisterServer(void)

{
                    /* 0x54f9  4  DllUnregisterServer */
  FUN_1000547b(&DAT_10020abc,1,(void *)0x0);
  return;
}



// Function: FUN_10005508 at 10005508

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005508(_Container_base12 *param_1)

{
  FUN_10005284((int)param_1);
  FUN_1000449c(param_1);
  return;
}



// Function: FUN_10005532 at 10005532

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_10005532(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_1000251e();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_1000251e();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_1000560c();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10002ea8(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10001207(&local_42c);
  FUN_1000f496();
  return;
}



// Function: Catch@100055f7 at 100055f7

undefined * Catch_100055f7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10005604;
}



// Function: FUN_1000560c at 1000560c

void FUN_1000560c(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000251e();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_100052d5((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10002ea8((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10001207((int *)(unaff_EBP + -0x428));
  FUN_1000f496();
  return;
}



// Function: FUN_10005696 at 10005696

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005696(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10005532(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001207(local_14);
  return uVar1;
}



// Function: FUN_100056d7 at 100056d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100056d7(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001207(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10005532(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001207(local_14);
  }
  return uVar1;
}



// Function: FUN_10005733 at 10005733

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005733(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_10005532(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10001207(local_14);
  return uVar1;
}



// Function: FUN_10005773 at 10005773

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005773(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10001207(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_10005532(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10001207(local_14);
  }
  return uVar1;
}



// Function: FUN_100057ce at 100057ce

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100057ce(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_1000461f(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_10020bb4;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10020bb4,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000251e();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001207((int *)&local_a48);
        goto LAB_10005850;
      }
      FUN_10002659(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_1000248b(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001207((int *)&local_a48);
          goto LAB_10005850;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000461f(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000461f(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10005773(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_100056d7(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001207((int *)&local_a48);
  }
LAB_10005850:
  local_8 = 0xffffffff;
  FUN_10003704(&local_a60);
  FUN_1000f487();
  return;
}



// Function: FUN_100059d1 at 100059d1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100059d1(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_1000461f(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_10020bb4;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10020bb4,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000251e();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10001207((int *)&local_a48);
        goto LAB_10005a4a;
      }
      FUN_10002659(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_1000248b(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10001207((int *)&local_a48);
          goto LAB_10005a4a;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000461f(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000461f(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_10005733(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10005696(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10001207((int *)&local_a48);
  }
LAB_10005a4a:
  local_8 = 0xffffffff;
  FUN_10003704(&local_a5c);
  FUN_1000f487();
  return;
}



// Function: FUN_10005bc8 at 10005bc8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_10005bc8(undefined4 param_1,undefined4 *param_2)

{
  FUN_1000e50c(param_2);
  return;
}



// Function: FUN_10005be6 at 10005be6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005be6(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10005c08 at 10005c08

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005c08(_Container_base12 *param_1)

{
  FUN_10005508(param_1);
  return;
}



// Function: FUN_10005c26 at 10005c26

void FUN_10005c26(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_100057ce(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10005c2f at 10005c2f

void FUN_10005c2f(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_100059d1(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10005c38 at 10005c38

void __thiscall FUN_10005c38(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x69) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_10002f1d((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x69) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x69) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_10005c82;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x69) == '\0') {
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
    iVar1 = param_2[0x1a];
    *(char *)(param_2 + 0x1a) = (char)piVar2[0x1a];
    *(char *)(piVar2 + 0x1a) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_10005c82:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x69) == '\0') {
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
      if (*(char *)((int)piVar7 + 0x69) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x69) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x69) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x69) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[0x1a] != '\x01') {
LAB_10005e5f:
    FUN_10005bc8((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_10005e13:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0x1a] != '\x01'))
  goto LAB_10005e5b;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0x1a] == '\0') {
      *(undefined1 *)(piVar5 + 0x1a) = 1;
      *(undefined1 *)(piVar6 + 0x1a) = 0;
      FUN_10003199(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x69) == '\0') {
      if ((*(char *)(*piVar5 + 0x68) != '\x01') || (*(char *)(piVar5[2] + 0x68) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x68) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x68) = 1;
          *(undefined1 *)(piVar5 + 0x1a) = 0;
          FUN_10002a8d(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0x1a) = (char)piVar6[0x1a];
        *(undefined1 *)(piVar6 + 0x1a) = 1;
        *(undefined1 *)(piVar5[2] + 0x68) = 1;
        FUN_10003199(this,(int)piVar6);
        goto LAB_10005e5b;
      }
LAB_10005e0a:
      *(undefined1 *)(piVar5 + 0x1a) = 0;
    }
  }
  else {
    if ((char)piVar5[0x1a] == '\0') {
      *(undefined1 *)(piVar5 + 0x1a) = 1;
      *(undefined1 *)(piVar6 + 0x1a) = 0;
      FUN_10002a8d(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x69) == '\0') {
      if ((*(char *)(piVar5[2] + 0x68) == '\x01') && (*(char *)(*piVar5 + 0x68) == '\x01'))
      goto LAB_10005e0a;
      if (*(char *)(*piVar5 + 0x68) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x68) = 1;
        *(undefined1 *)(piVar5 + 0x1a) = 0;
        FUN_10003199(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0x1a) = (char)piVar6[0x1a];
      *(undefined1 *)(piVar6 + 0x1a) = 1;
      *(undefined1 *)(*piVar5 + 0x68) = 1;
      FUN_10002a8d(this,piVar6);
LAB_10005e5b:
      *(undefined1 *)(piVar7 + 0x1a) = 1;
      goto LAB_10005e5f;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_10005e13;
}



// Function: FUN_10005e95 at 10005e95

void __thiscall FUN_10005e95(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x69);
  while (cVar1 == '\0') {
    FUN_10005e95(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10005bc8((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x69);
  }
  return;
}



// Function: FUN_10005ed9 at 10005ed9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005ed9(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10005efb at 10005efb

void FUN_10005efb(int param_1)

{
  FUN_100059d1((int *)&DAT_10020abc,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005f13 at 10005f13

void FUN_10005f13(int param_1)

{
  FUN_100059d1((int *)&DAT_10020abc,0x66,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005f2b at 10005f2b

void FUN_10005f2b(int param_1)

{
  FUN_100059d1((int *)&DAT_10020abc,0x67,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005f43 at 10005f43

void FUN_10005f43(int param_1)

{
  FUN_100059d1((int *)&DAT_10020abc,0x69,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005f5b at 10005f5b

void FUN_10005f5b(int param_1)

{
  FUN_100059d1((int *)&DAT_10020abc,0x6d,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005f73 at 10005f73

void FUN_10005f73(int param_1)

{
  FUN_100059d1((int *)&DAT_10020abc,0x6e,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005f8b at 10005f8b

void FUN_10005f8b(int param_1)

{
  FUN_100059d1((int *)&DAT_10020abc,0x70,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10005fa3 at 10005fa3

void __fastcall FUN_10005fa3(void *param_1)

{
  FUN_10005e95(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10005fca at 10005fca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10005fca(void *this,byte param_1)

{
  FID_conflict__Tidy(this,'\x01',0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10005fff at 10005fff

void __thiscall FUN_10005fff(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10005fa3(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_10002f1d((int *)&param_2);
      FUN_10005c38(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_10006052 at 10006052

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006052(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10005fff(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000608c at 1000608c

void __cdecl FUN_1000608c(undefined4 param_1,void *param_2)

{
  FUN_10005fca(param_2,0);
  return;
}



// Function: FUN_1000609b at 1000609b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000609b(void *param_1)

{
  FUN_10006052(param_1);
  return;
}



// Function: FUN_100060b9 at 100060b9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100060b9(int param_1)

{
  FUN_10006052((void *)(param_1 + 4));
  return;
}



// Function: FUN_100060e1 at 100060e1

void __thiscall FUN_100060e1(void *this,undefined4 *param_1,int *param_2)

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
  FUN_10001012((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000612b;
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
LAB_1000612b:
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
LAB_10006308:
    FUN_1000608c((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_100062bc:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xb] != '\x01'))
  goto LAB_10006304;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10001689(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x2c) = 1;
          *(undefined1 *)(piVar5 + 0xb) = 0;
          FUN_10002968(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        FUN_10001689(this,(int)piVar6);
        goto LAB_10006304;
      }
LAB_100062b3:
      *(undefined1 *)(piVar5 + 0xb) = 0;
    }
  }
  else {
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10002968(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
      goto LAB_100062b3;
      if (*(char *)(*piVar5 + 0x2c) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        *(undefined1 *)(piVar5 + 0xb) = 0;
        FUN_10001689(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(*piVar5 + 0x2c) = 1;
      FUN_10002968(this,piVar6);
LAB_10006304:
      *(undefined1 *)(piVar7 + 0xb) = 1;
      goto LAB_10006308;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_100062bc;
}



// Function: FUN_1000633e at 1000633e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000633e(int param_1)

{
  FUN_10006052((void *)(param_1 + 0x7c));
  FUN_1000e7fb((undefined4 *)(param_1 + 0x44));
  FUN_10005508((_Container_base12 *)(param_1 + 0x2c));
  FUN_10001221((LPCRITICAL_SECTION)(param_1 + 0x10));
  return;
}



// Function: FUN_100063a0 at 100063a0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100063a0(int param_1)

{
  FUN_1000633e(param_1);
  return;
}



// Function: FUN_100063be at 100063be

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100063be(int param_1)

{
  FUN_100060b9(param_1);
  return;
}



// Function: FUN_100063dc at 100063dc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100063dc(void *this,undefined4 param_1)

{
  FUN_1000df72((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CSubscriberImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CSubscriberImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CSubscriberImpl>::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  return (undefined4 *)this;
}



// Function: AtlComQIPtrAssign at 1000641e

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



// Function: Attach at 10006455

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



// Function: FUN_1000649d at 1000649d

void FUN_1000649d(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_100064b0 at 100064b0

void FUN_100064b0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_100064c3 at 100064c3

void FUN_100064c3(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))(*(undefined4 **)(param_1 + 0xc),param_2,param_3);
  return;
}



// Function: FUN_100064db at 100064db

void FUN_100064db(int param_1)

{
  FUN_100064b0(param_1 + -4);
  return;
}



// Function: FUN_100064e5 at 100064e5

void FUN_100064e5(int param_1)

{
  FUN_100064b0(param_1 + -8);
  return;
}



// Function: FUN_100064ef at 100064ef

void FUN_100064ef(int param_1)

{
  FUN_1000649d(param_1 + -4);
  return;
}



// Function: FUN_100064f9 at 100064f9

void FUN_100064f9(int param_1)

{
  FUN_1000649d(param_1 + -8);
  return;
}



// Function: FUN_10006503 at 10006503

void FUN_10006503(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100064c3(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_1000650d at 1000650d

void FUN_1000650d(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_100064c3(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10006517 at 10006517

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10006517(void *this,wchar_t *param_1)

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
  local_8 = 0x10006523;
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
      local_18 = (uint *)FUN_1000f311(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10006474,
                   (_func_void_void_ptr *)&LAB_100010fe);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_100065c7();
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



// Function: Catch@100065b7 at 100065b7

undefined * Catch_100065b7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100065c1;
}



// Function: FUN_100065c7 at 100065c7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100065c7(void)

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



// Function: FUN_1000667f at 1000667f

void FUN_1000667f(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_100013f8(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_100066b2 at 100066b2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

code * FUN_100066b2(undefined4 *param_1)

{
  int *in_ECX;
  bool bVar1;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  if (*in_ECX == 0) {
    if (param_1 == (undefined4 *)0x0) {
      return Unwind_10010a01;
    }
  }
  else if (param_1 != (undefined4 *)0x0) {
    local_18 = (int *)0x0;
    local_14[0] = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    (*(code *)**(undefined4 **)*in_ECX)((undefined4 *)*in_ECX,&DAT_10013b74,&local_18);
    (**(code **)*param_1)(param_1,&DAT_10013b74,local_14);
    bVar1 = local_18 == local_14[0];
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    return (code *)(uint)bVar1;
  }
  return (code *)0x0;
}



// Function: FUN_1000673d at 1000673d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000673d(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_10006782();
  return uVar1;
}



// Function: Catch@10006772 at 10006772

undefined * Catch_10006772(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000677c;
}



// Function: FUN_10006782 at 10006782

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10006782(void)

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



// Function: FUN_100067dd at 100067dd

IUnknown * __thiscall FUN_100067dd(void *this,undefined4 *param_1)

{
  char cVar1;
  IUnknown *pIVar2;
  
  cVar1 = FUN_100066b2(*param_1);
  if (cVar1 == '\0') {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_10013c9c);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  return pIVar2;
}



// Function: FUN_1000680a at 1000680a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000680a(void *this,undefined4 param_1)

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
  local_8 = 0x10006819;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10006a4f;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10020a6c + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_10020a70,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_10020bb4,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10006a19;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10001207((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_10013c8c,&local_224);
        if (-1 < iVar2) {
          FUN_100067dd(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_10020a6c == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_10020a6c + 4;
        }
        pcVar4 = FUN_1000667f;
        pvVar5 = this;
        FUN_1000673d(iVar2);
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
LAB_10006a19:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10006517(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10006a4f:
  FUN_1000f487();
  return;
}



// Function: FUN_10006a57 at 10006a57

undefined4 __thiscall FUN_10006a57(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_1000680a(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10006a97 at 10006a97

undefined4 __thiscall
FUN_10006a97(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_1000680a(this,param_4);
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



// Function: FUN_10006b38 at 10006b38

void __thiscall
FUN_10006b38(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_1000680a(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10006b7b at 10006b7b

undefined4 FUN_10006b7b(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001d66c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10006b9f at 10006b9f

void FUN_10006b9f(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001d66c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10006bbf at 10006bbf

void FUN_10006bbf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001d66c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10006bcd at 10006bcd

undefined4 FUN_10006bcd(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001d688,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10006bf1 at 10006bf1

void FUN_10006bf1(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001d688,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10006c11 at 10006c11

void FUN_10006c11(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001d688,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10006c1f at 10006c1f

undefined4 FUN_10006c1f(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001d6a4,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10006c43 at 10006c43

void FUN_10006c43(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001d6a4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10006c63 at 10006c63

void FUN_10006c63(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001d6a4,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10006c71 at 10006c71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10006c71(undefined4 *param_1)

{
  FUN_1000df72((int)param_1);
  *param_1 = ATL::CComObject<class_CSubscriberImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CSubscriberImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CSubscriberImpl>::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: FUN_10006cb8 at 10006cb8

void FUN_10006cb8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



// Function: Release at 10006ccc

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x24))(1);
  }
  return LVar1;
}



// Function: QueryInterface at 10006cf9

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013d38,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10006d13 at 10006d13

void FUN_10006d13(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10006d1d at 10006d1d

void FUN_10006d1d(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_10006d27 at 10006d27

void FUN_10006d27(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_10006d31 at 10006d31

void FUN_10006d31(int param_1)

{
  Release((int *)(param_1 + -8));
  return;
}



// Function: FUN_10006d3b at 10006d3b

void FUN_10006d3b(int param_1)

{
  FUN_10006cb8(param_1 + -4);
  return;
}



// Function: FUN_10006d45 at 10006d45

void FUN_10006d45(int param_1)

{
  FUN_10006cb8(param_1 + -8);
  return;
}



// Function: FUN_10006d4f at 10006d4f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006d4f(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CSubscriberImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CSubscriberImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CSubscriberImpl>::vftable;
  param_1[3] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_1000633e((int)param_1);
  return;
}



// Function: FUN_10006d9b at 10006d9b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006d9b(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CSubscriberImpl>::vftable;
  FUN_100063dc((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10020a6c + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10006dde at 10006dde

long FUN_10006dde(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013d38,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: Release at 10006e2a

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



// Function: FUN_10006e57 at 10006e57

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006e57(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CSubscriberImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_1000633e((int)(param_1 + 3));
  return;
}



// Function: FUN_10006e9d at 10006e9d

undefined4 * __thiscall FUN_10006e9d(void *this,byte param_1)

{
  FUN_10006d4f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006ebc at 10006ebc

undefined4 * __thiscall FUN_10006ebc(void *this,byte param_1)

{
  FUN_10006e57((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006edb at 10006edb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006edb(int param_1)

{
  FUN_100060b9(param_1 + 4);
  return;
}



// Function: FUN_10006f03 at 10006f03

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006f03(int param_1)

{
  FUN_10006edb(param_1);
  return;
}



// Function: FUN_10006f21 at 10006f21

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006f21(void *this,undefined4 param_1)

{
  FUN_1000ed38((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CEnumSubscriberEvents>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CEnumSubscriberEvents>::vftable;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10006f5c at 10006f5c

int * FUN_10006f5c(int *param_1,int *param_2)

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



// Function: FUN_10006f8f at 10006f8f

void FUN_10006f8f(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x18) + 8))(*(int **)(param_1 + 0x18));
  return;
}



// Function: FUN_10006fa2 at 10006fa2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006fa2(int param_1)

{
  FUN_100082d7(param_1);
  return;
}



// Function: FUN_10006fc0 at 10006fc0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006fc0(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// Function: FUN_10006ff9 at 10006ff9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10006ff9(undefined4 *param_1)

{
  FUN_10006fc0((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemSubscriberEvents,class_std::map<class_CFCBstrDualId,class_CEventCallback*,struct_std::less<class_CFCBstrDualId>,class_std::allocator<struct_std::pair<class_CFCBstrDualId_const_,class_CEventCallback*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: QueryInterface at 10007032

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013e30,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000704c at 1000704c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000704c(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemSubscriberEvents,class_std::map<class_CFCBstrDualId,class_CEventCallback*,struct_std::less<class_CFCBstrDualId>,class_std::allocator<struct_std::pair<class_CFCBstrDualId_const_,class_CEventCallback*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_100082d7((int)param_1);
  return;
}



// Function: FUN_1000708a at 1000708a

undefined4 * __thiscall FUN_1000708a(void *this,byte param_1)

{
  FUN_1000704c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100070a9 at 100070a9

int FUN_100070a9(uint param_1,uint param_2,undefined2 *param_3,uint *param_4)

{
  uint uVar1;
  undefined2 *puVar2;
  int local_8;
  
  uVar1 = param_1;
  if ((param_3 == (undefined2 *)0x0) || ((1 < param_2 && (param_4 == (uint *)0x0)))) {
    local_8 = -0x7fffbffd;
  }
  else {
    if (param_4 != (uint *)0x0) {
      *param_4 = 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      local_8 = -0x7fffbffb;
    }
    else {
      param_1 = 0;
      local_8 = 0;
      puVar2 = param_3;
      do {
        if ((*(int *)(uVar1 + 0xc) == *(int *)(*(int *)(uVar1 + 8) + 4)) || (param_2 <= param_1))
        break;
        local_8 = FUN_1000ebee(puVar2,*(int *)(uVar1 + 0xc) + 0xc);
        if (local_8 < 0) {
          for (; param_3 < puVar2; param_3 = param_3 + 8) {
            FUN_1000e900(param_3);
          }
          param_1 = 0;
        }
        else {
          puVar2 = puVar2 + 8;
          FUN_10002f1d((int *)(uVar1 + 0xc));
          param_1 = param_1 + 1;
        }
      } while (-1 < local_8);
      if (-1 < local_8) {
        if (param_4 != (uint *)0x0) {
          *param_4 = param_1;
        }
        if (param_1 < param_2) {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}



// Function: FUN_1000716e at 1000716e

undefined4 FUN_1000716e(int param_1,int param_2)

{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      if (*(int *)(param_1 + 0xc) == *(int *)(*(int *)(param_1 + 8) + 4)) {
        return 1;
      }
      FUN_10002f1d((int *)(param_1 + 0xc));
    } while (param_2 != 0);
  }
  return 0;
}



// Function: FUN_100071a7 at 100071a7

undefined4 FUN_100071a7(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e138,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100071cb at 100071cb

void FUN_100071cb(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001e138,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100071eb at 100071eb

void FUN_100071eb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001e138,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100071f9 at 100071f9

undefined4 FUN_100071f9(int param_1,undefined4 *param_2,undefined2 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_3 == (undefined2 *)0x0) {
    uVar2 = 0x80004003;
  }
  else if ((int)param_2 < 1) {
    uVar2 = 0x80070057;
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 8);
    uVar2 = 0x80004005;
    puVar3 = param_2;
    param_2 = (undefined4 *)*puVar1;
    while ((puVar3 = (undefined4 *)((int)puVar3 + -1), param_2 != puVar1 && (0 < (int)puVar3))) {
      FUN_10002f1d((int *)&param_2);
    }
    if (param_2 != puVar1) {
      uVar2 = FUN_1000ebee(param_3,(int)(param_2 + 3));
    }
  }
  return uVar2;
}



// Function: FUN_1000725e at 1000725e

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000725e(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006ff9(puVar1);
    }
    uVar2 = FUN_100072b9();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100072aa at 100072aa

undefined * Catch_100072aa(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100072b4;
}



// Function: FUN_100072b9 at 100072b9

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100072b9(void)

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



// Function: FUN_100072d0 at 100072d0

int FUN_100072d0(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    return unaff_EDI;
  }
  *param_2 = 0;
  iVar3 = FUN_1000725e(&param_2);
  piVar2 = param_2;
  if (-1 < iVar3) {
    iVar3 = FUN_10009030(param_2,param_1,(int)(param_1 + 1));
    if (iVar3 != 0) goto LAB_1000731f;
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10013b74,piVar1);
  }
  if (iVar3 == 0) {
    return unaff_EDI;
  }
LAB_1000731f:
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x1c))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10007335 at 10007335

int FUN_10007335(int param_1,void **param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    iVar1 = FUN_1000725e(&local_8);
    if (-1 < iVar1) {
      iVar1 = FUN_10009030(local_8,*(int **)(param_1 + 4),*(int *)(param_1 + 8));
      if (-1 < iVar1) {
        local_8[3] = *(int *)(param_1 + 0xc);
        iVar1 = ATL::AtlInternalQueryInterface
                          (local_8,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013e30,(_GUID *)&DAT_10016068,
                           param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
      }
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 0x1c))(1);
      }
    }
  }
  return iVar1;
}



// Function: FUN_100073a9 at 100073a9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100073a9(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x29c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006c71(puVar1);
    }
    iVar2 = FUN_10007410();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10007400 at 10007400

undefined * Catch_10007400(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000740a;
}



// Function: FUN_10007410 at 10007410

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10007410(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 3;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10002f08((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x24))(1);
  }
  return unaff_EBX;
}



// Function: FUN_1000745c at 1000745c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000745c(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x2a8);
    if (this != (void *)0x0) {
      FUN_10006d9b(this,param_1);
    }
    iVar1 = FUN_100074cd();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@100074bd at 100074bd

undefined * Catch_100074bd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100074c7;
}



// Function: FUN_100074cd at 100074cd

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100074cd(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10002f08((int)(unaff_ESI + 6));
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



// Function: FUN_1000750f at 1000750f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000750f(undefined4 *param_1)

{
  FUN_1000ed38((int)param_1);
  *param_1 = ATL::CComObject<class_CEnumSubscriberEvents>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumSubscriberEvents>::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: Release at 1000754f

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
    (**(code **)(*in_stack_00000004 + 0x10))(1);
  }
  return uVar2;
}



// Function: QueryInterface at 10007570

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013e90,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000758a at 1000758a

void FUN_1000758a(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10007594 at 10007594

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007594(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CEnumSubscriberEvents>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumSubscriberEvents>::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10006edb((int)param_1);
  return;
}



// Function: FUN_100075d9 at 100075d9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100075d9(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CEnumSubscriberEvents>::vftable;
  FUN_10006f21((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_10020a6c + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000761c at 1000761c

long FUN_1000761c(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013e90,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10007668 at 10007668

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007668(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CEnumSubscriberEvents>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10006edb((int)(param_1 + 2));
  return;
}



// Function: FUN_100076ae at 100076ae

undefined4 * __thiscall FUN_100076ae(void *this,byte param_1)

{
  FUN_10007594((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100076cd at 100076cd

undefined4 * __thiscall FUN_100076cd(void *this,byte param_1)

{
  FUN_10007668((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100076ec at 100076ec

void FUN_100076ec(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_100073a9(0,param_2,param_3);
    return;
  }
  FUN_1000745c(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000770c at 1000770c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000770c(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000750f(puVar1);
    }
    uVar2 = FUN_10007769();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000775c at 1000775c

undefined * Catch_1000775c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007766;
}



// Function: FUN_10007769 at 10007769

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007769(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[6] = unaff_ESI[6] + 1;
    unaff_ESI[6] = unaff_ESI[6] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x10))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10007799 at 10007799

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007799(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x24);
    if (this != (void *)0x0) {
      FUN_100075d9(this,param_1);
    }
    uVar1 = FUN_10007800();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@100077f3 at 100077f3

undefined * Catch_100077f3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100077fd;
}



// Function: FUN_10007800 at 10007800

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007800(void)

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



// Function: FUN_1000782a at 1000782a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000782a(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000217b(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_10007864 at 10007864

void FUN_10007864(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000770c(0,param_2,param_3);
    return;
  }
  FUN_10007799(param_1,param_2,param_3);
  return;
}



// Function: FUN_10007884 at 10007884

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007884(void *param_1)

{
  FUN_1000782a(param_1);
  return;
}



// Function: FUN_100078a2 at 100078a2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100078a2(int param_1)

{
  int *piVar1;
  
  FUN_1000782a((void *)(param_1 + 0x84));
  FUN_1000782a((void *)(param_1 + 0x74));
  piVar1 = *(int **)(param_1 + 0x70);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000e7fb((undefined4 *)(param_1 + 0x38));
  FUN_10001221((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return;
}



// Function: FUN_10007921 at 10007921

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007921(int param_1)

{
  FUN_100078a2(param_1);
  return;
}



// Function: FUN_1000793f at 1000793f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000793f(int param_1)

{
  FUN_1000782a((void *)(param_1 + 0x68));
  FUN_1000e7fb((undefined4 *)(param_1 + 0x30));
  Ordinal_6(*(undefined4 *)(param_1 + 0x2c));
  Ordinal_6(*(undefined4 *)(param_1 + 0x28));
  FUN_10001221((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



// Function: FUN_100079a6 at 100079a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100079a6(int param_1)

{
  FUN_1000793f(param_1);
  return;
}



// Function: FUN_100079c4 at 100079c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100079c4(int param_1)

{
  FUN_1000782a((void *)(param_1 + 4));
  return;
}



// Function: FUN_100079ec at 100079ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100079ec(void *this,undefined4 param_1)

{
  FUN_1000b8f1((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CMessageRouterImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CMessageRouterImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CMessageRouterImpl>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CMessageRouterImpl>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<class_CMessageRouterImpl>::vftable;
  *(undefined ***)((int)this + 0x14) = ATL::CComContainedObject<class_CMessageRouterImpl>::vftable;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10007a43 at 10007a43

undefined4 FUN_10007a43(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_10007a60 at 10007a60

undefined4 __fastcall FUN_10007a60(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: FUN_10007a64 at 10007a64

void FUN_10007a64(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x18) + 4))(*(int **)(param_1 + 0x18));
  return;
}



// Function: FUN_10007a77 at 10007a77

void FUN_10007a77(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x18))(*(undefined4 **)(param_1 + 0x18),param_2,param_3);
  return;
}



// Function: FUN_10007a8f at 10007a8f

void FUN_10007a8f(int param_1)

{
  FUN_10006f8f(param_1 + -0xc);
  return;
}



// Function: FUN_10007a99 at 10007a99

void FUN_10007a99(int param_1)

{
  FUN_10006f8f(param_1 + -0x10);
  return;
}



// Function: FUN_10007aa3 at 10007aa3

void FUN_10007aa3(int param_1)

{
  FUN_10007a64(param_1 + -8);
  return;
}



// Function: FUN_10007aad at 10007aad

void FUN_10007aad(int param_1)

{
  FUN_10006f8f(param_1 + -0x14);
  return;
}



// Function: FUN_10007ab7 at 10007ab7

void FUN_10007ab7(int param_1)

{
  FUN_10007a64(param_1 + -0xc);
  return;
}



// Function: FUN_10007ac1 at 10007ac1

void FUN_10007ac1(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007a77(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10007acb at 10007acb

void FUN_10007acb(int param_1)

{
  FUN_10007a64(param_1 + -0x10);
  return;
}



// Function: FUN_10007ad5 at 10007ad5

void FUN_10007ad5(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007a77(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10007adf at 10007adf

void FUN_10007adf(int param_1)

{
  FUN_10007a64(param_1 + -0x14);
  return;
}



// Function: FUN_10007ae9 at 10007ae9

void FUN_10007ae9(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007a77(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_10007af3 at 10007af3

void FUN_10007af3(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007a77(param_1 + -0x14,param_2,param_3);
  return;
}



// Function: FUN_10007afd at 10007afd

void FUN_10007afd(int param_1)

{
  FUN_10006f8f(param_1 + -8);
  return;
}



// Function: FUN_10007b07 at 10007b07

undefined4 FUN_10007b07(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e614,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007b2b at 10007b2b

void FUN_10007b2b(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001e614,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007b4b at 10007b4b

void FUN_10007b4b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001e614,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007b59 at 10007b59

undefined4 FUN_10007b59(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e630,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007b7d at 10007b7d

void FUN_10007b7d(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001e630,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007b9d at 10007b9d

void FUN_10007b9d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001e630,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007bab at 10007bab

undefined4 FUN_10007bab(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e64c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007bcf at 10007bcf

void FUN_10007bcf(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001e64c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007bef at 10007bef

void FUN_10007bef(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001e64c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007bfd at 10007bfd

undefined4 FUN_10007bfd(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e668,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007c21 at 10007c21

void FUN_10007c21(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001e668,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007c41 at 10007c41

void FUN_10007c41(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001e668,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007c4f at 10007c4f

undefined4 FUN_10007c4f(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e684,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007c73 at 10007c73

void FUN_10007c73(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001e684,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007c93 at 10007c93

void FUN_10007c93(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001e684,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007ca1 at 10007ca1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10007ca1(void *this,undefined4 param_1)

{
  FUN_100021ce((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CEventImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CEventImpl>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10007cdc at 10007cdc

void FUN_10007cdc(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,int param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10001c60(param_1 + -4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



// Function: FUN_10007ce6 at 10007ce6

void FUN_10007ce6(void)

{
  FUN_10001000();
  return;
}



// Function: FUN_10007cf0 at 10007cf0

void FUN_10007cf0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 4))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10007d03 at 10007d03

void FUN_10007d03(int param_1)

{
  (**(code **)(**(int **)(param_1 + 8) + 8))(*(int **)(param_1 + 8));
  return;
}



// Function: FUN_10007d16 at 10007d16

void FUN_10007d16(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 8))(*(undefined4 **)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_10007d2e at 10007d2e

void FUN_10007d2e(int param_1)

{
  FUN_10007d03(param_1 + -4);
  return;
}



// Function: FUN_10007d38 at 10007d38

void FUN_10007d38(int param_1)

{
  FUN_10007cf0(param_1 + -4);
  return;
}



// Function: FUN_10007d42 at 10007d42

void FUN_10007d42(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007d16(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10007d4c at 10007d4c

undefined4 FUN_10007d4c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e8a8,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007d70 at 10007d70

undefined4 FUN_10007d70(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001e8c4,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007d94 at 10007d94

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10007d94(undefined4 *param_1)

{
  FUN_1000b8f1((int)param_1);
  *param_1 = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[5] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: FUN_10007df0 at 10007df0

void FUN_10007df0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x18));
  return;
}



// Function: Release at 10007e04

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 6);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return LVar1;
}



// Function: QueryInterface at 10007e31

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10014168,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10007e4b at 10007e4b

void FUN_10007e4b(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_10007e55 at 10007e55

void FUN_10007e55(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x10),param_2);
  return;
}



// Function: FUN_10007e5f at 10007e5f

void FUN_10007e5f(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_10007e69 at 10007e69

void FUN_10007e69(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x14),param_2);
  return;
}



// Function: FUN_10007e73 at 10007e73

void FUN_10007e73(int param_1)

{
  Release((int *)(param_1 + -8));
  return;
}



// Function: FUN_10007e7d at 10007e7d

void FUN_10007e7d(int param_1)

{
  Release((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_10007e87 at 10007e87

void FUN_10007e87(int param_1)

{
  FUN_10007df0(param_1 + -4);
  return;
}



// Function: FUN_10007e91 at 10007e91

void FUN_10007e91(int param_1)

{
  Release((int *)(param_1 + -0x10));
  return;
}



// Function: FUN_10007e9b at 10007e9b

void FUN_10007e9b(int param_1)

{
  FUN_10007df0(param_1 + -8);
  return;
}



// Function: FUN_10007ea5 at 10007ea5

void FUN_10007ea5(int param_1)

{
  Release((int *)(param_1 + -0x14));
  return;
}



// Function: FUN_10007eaf at 10007eaf

void FUN_10007eaf(int param_1)

{
  FUN_10007df0(param_1 + -0xc);
  return;
}



// Function: FUN_10007eb9 at 10007eb9

void FUN_10007eb9(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10007ec3 at 10007ec3

void FUN_10007ec3(int param_1)

{
  FUN_10007df0(param_1 + -0x10);
  return;
}



// Function: FUN_10007ecd at 10007ecd

void FUN_10007ecd(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_10007ed7 at 10007ed7

void FUN_10007ed7(int param_1)

{
  FUN_10007df0(param_1 + -0x14);
  return;
}



// Function: FUN_10007ee1 at 10007ee1

int __fastcall FUN_10007ee1(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_10007ee5 at 10007ee5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007ee5(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[5] = ATL::CComObject<class_CMessageRouterImpl>::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_100078a2((int)param_1);
  return;
}



// Function: FUN_10007f46 at 10007f46

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10007f46(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CMessageRouterImpl>::vftable;
  FUN_100079ec((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10020a6c + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10007f89 at 10007f89

long FUN_10007f89(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10014168,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10007fd5 at 10007fd5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10007fd5(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CMessageRouterImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_100078a2((int)(param_1 + 3));
  return;
}



// Function: FUN_1000801b at 1000801b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000801b(undefined4 *param_1)

{
  FUN_100021ce((int)param_1);
  *param_1 = ATL::CComObject<class_CEventImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CEventImpl>::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: FUN_1000805b at 1000805b

void FUN_1000805b(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: Release at 1000806f

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2019 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x20))(1);
  }
  return LVar1;
}



// Function: QueryInterface at 1000809c

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10014280,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100080b6 at 100080b6

void FUN_100080b6(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_100080c0 at 100080c0

void FUN_100080c0(int param_1)

{
  FUN_1000805b(param_1 + -4);
  return;
}



// Function: FUN_100080ca at 100080ca

void FUN_100080ca(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100080d4 at 100080d4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100080d4(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CEventImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CEventImpl>::vftable;
  param_1[2] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_1000793f((int)param_1);
  return;
}



// Function: FUN_10008119 at 10008119

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008119(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CEventImpl>::vftable;
  FUN_10007ca1((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10020a6c + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000815c at 1000815c

long FUN_1000815c(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10014280,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_100081a8 at 100081a8

void FUN_100081a8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_100081bc at 100081bc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100081bc(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CEventImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_1000793f((int)(param_1 + 3));
  return;
}



// Function: FUN_10008202 at 10008202

undefined4 * __thiscall FUN_10008202(void *this,byte param_1)

{
  FUN_10007ee5((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008221 at 10008221

undefined4 * __thiscall FUN_10008221(void *this,byte param_1)

{
  FUN_10007fd5((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008240 at 10008240

undefined4 * __thiscall FUN_10008240(void *this,byte param_1)

{
  FUN_100080d4((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000825f at 1000825f

undefined4 * __thiscall FUN_1000825f(void *this,byte param_1)

{
  FUN_100081bc((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000827e at 1000827e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000827e(int param_1)

{
  FUN_100079c4(param_1);
  return;
}



// Function: FUN_1000829c at 1000829c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000829c(void *this,undefined4 param_1)

{
  FUN_1000eb90((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CEnumPublishers>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CEnumPublishers>::vftable;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100082d7 at 100082d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100082d7(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10008306 at 10008306

void FUN_10008306(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007a77(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10008310 at 10008310

void FUN_10008310(int param_1)

{
  FUN_10006f8f(param_1 + -4);
  return;
}



// Function: FUN_1000831a at 1000831a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000831a(undefined4 *param_1)

{
  FUN_10006fc0((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemPubId,class_std::map<class_CFCBstrId,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: FUN_10008353 at 10008353

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008353(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemPubId,class_std::map<class_CFCBstrId,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_100082d7((int)param_1);
  return;
}



// Function: FUN_10008391 at 10008391

undefined4 * __thiscall FUN_10008391(void *this,byte param_1)

{
  FUN_10008353((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100083b0 at 100083b0

undefined4 FUN_100083b0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(*(int *)(param_1 + 8) + 4);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100083d2 at 100083d2

undefined4 FUN_100083d2(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_1001f79c,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100083f6 at 100083f6

void FUN_100083f6(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_1001f79c,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008416 at 10008416

void FUN_10008416(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_1001f79c,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10008424 at 10008424

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008424(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000831a(puVar1);
    }
    uVar2 = FUN_1000847f();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10008470 at 10008470

undefined * Catch_10008470(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000847a;
}



// Function: FUN_1000847f at 1000847f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000847f(void)

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



// Function: FUN_10008496 at 10008496

int FUN_10008496(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    return unaff_EDI;
  }
  *param_2 = 0;
  iVar3 = FUN_10008424(&param_2);
  piVar2 = param_2;
  if (-1 < iVar3) {
    iVar3 = FUN_10009030(param_2,param_1,(int)(param_1 + 1));
    if (iVar3 != 0) goto LAB_100084e5;
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10013b74,piVar1);
  }
  if (iVar3 == 0) {
    return unaff_EDI;
  }
LAB_100084e5:
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x1c))(1);
  }
  return unaff_EDI;
}



// Function: FUN_100084fb at 100084fb

int FUN_100084fb(int param_1,void **param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    iVar1 = FUN_10008424(&local_8);
    if (-1 < iVar1) {
      iVar1 = FUN_10009030(local_8,*(int **)(param_1 + 4),*(int *)(param_1 + 8));
      if (-1 < iVar1) {
        local_8[3] = *(int *)(param_1 + 0xc);
        iVar1 = ATL::AtlInternalQueryInterface
                          (local_8,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013e30,(_GUID *)&DAT_10016068,
                           param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
      }
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 0x1c))(1);
      }
    }
  }
  return iVar1;
}



// Function: FUN_1000856f at 1000856f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000856f(void *this,undefined4 param_1)

{
  FUN_1000f046((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CEnumSubscribers>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CEnumSubscribers>::vftable;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100085aa at 100085aa

undefined4 FUN_100085aa(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100085c9 at 100085c9

void FUN_100085c9(int param_1)

{
  FUN_10007a64(param_1 + -4);
  return;
}



// Function: FUN_100085d3 at 100085d3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100085d3(undefined4 *param_1)

{
  FUN_10006fc0((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemSubId,class_std::map<class_CFCBstrId,struct_ISubscriber*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_ISubscriber*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: Release at 1000860c

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
    (**(code **)(*in_stack_00000004 + 0x1c))(1);
  }
  return uVar2;
}



// Function: FUN_1000862d at 1000862d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000862d(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemSubId,class_std::map<class_CFCBstrId,struct_ISubscriber*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_ISubscriber*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_100082d7((int)param_1);
  return;
}



// Function: FUN_1000866b at 1000866b

undefined4 * __thiscall FUN_1000866b(void *this,byte param_1)

{
  FUN_1000862d((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000868a at 1000868a

int FUN_1000868a(uint param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  int local_8;
  
  uVar1 = param_1;
  if ((param_3 == 0) || ((1 < param_2 && (param_4 == (uint *)0x0)))) {
    local_8 = -0x7fffbffd;
  }
  else {
    if (param_4 != (uint *)0x0) {
      *param_4 = 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      local_8 = -0x7fffbffb;
    }
    else {
      param_1 = 0;
      local_8 = 0;
      uVar2 = param_3;
      do {
        if ((*(int *)(uVar1 + 0xc) == *(int *)(*(int *)(uVar1 + 8) + 4)) || (param_2 <= param_1))
        break;
        local_8 = FUN_1000eef8(uVar2,(undefined4 *)(*(int *)(uVar1 + 0xc) + 0xc));
        if (local_8 < 0) {
          for (; param_3 < uVar2; param_3 = param_3 + 0x10) {
            FUN_1000e900(param_3);
          }
          param_1 = 0;
        }
        else {
          uVar2 = uVar2 + 0x10;
          FUN_10001012((int *)(uVar1 + 0xc));
          param_1 = param_1 + 1;
        }
      } while (-1 < local_8);
      if (-1 < local_8) {
        if (param_4 != (uint *)0x0) {
          *param_4 = param_1;
        }
        if (param_1 < param_2) {
          local_8 = 1;
        }
      }
    }
  }
  return local_8;
}



// Function: FUN_1000874f at 1000874f

undefined4 FUN_1000874f(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_10020004,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10008773 at 10008773

void FUN_10008773(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_10020004,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10008793 at 10008793

void FUN_10008793(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_10020004,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100087a1 at 100087a1

undefined4 FUN_100087a1(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_3 == 0) {
    uVar2 = 0x80004003;
  }
  else if ((int)param_2 < 1) {
    uVar2 = 0x80070057;
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 8);
    uVar2 = 0x80004005;
    puVar3 = param_2;
    param_2 = (undefined4 *)*puVar1;
    while ((puVar3 = (undefined4 *)((int)puVar3 + -1), param_2 != puVar1 && (0 < (int)puVar3))) {
      FUN_10001012((int *)&param_2);
    }
    if (param_2 != puVar1) {
      uVar2 = FUN_1000eef8(param_3,param_2 + 3);
    }
  }
  return uVar2;
}



// Function: FUN_10008806 at 10008806

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008806(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100085d3(puVar1);
    }
    uVar2 = FUN_10008861();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10008852 at 10008852

undefined * Catch_10008852(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000885c;
}



// Function: FUN_10008861 at 10008861

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008861(void)

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



// Function: FUN_10008878 at 10008878

int FUN_10008878(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    return unaff_EDI;
  }
  *param_2 = 0;
  iVar3 = FUN_10008806(&param_2);
  piVar2 = param_2;
  if (-1 < iVar3) {
    iVar3 = FUN_10009030(param_2,param_1,(int)(param_1 + 1));
    if (iVar3 != 0) goto LAB_100088c7;
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10013b74,piVar1);
  }
  if (iVar3 == 0) {
    return unaff_EDI;
  }
LAB_100088c7:
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x1c))(1);
  }
  return unaff_EDI;
}



// Function: FUN_100088dd at 100088dd

int FUN_100088dd(int param_1,void **param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    iVar1 = FUN_10008806(&local_8);
    if (-1 < iVar1) {
      iVar1 = FUN_10009030(local_8,*(int **)(param_1 + 4),*(int *)(param_1 + 8));
      if (-1 < iVar1) {
        local_8[3] = *(int *)(param_1 + 0xc);
        iVar1 = ATL::AtlInternalQueryInterface
                          (local_8,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013e30,(_GUID *)&DAT_10016068,
                           param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
      }
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 0x1c))(1);
      }
    }
  }
  return iVar1;
}



// Function: FUN_10008951 at 10008951

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008951(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x294);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10007d94(puVar1);
    }
    iVar2 = FUN_100089b8();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@100089a8 at 100089a8

undefined * Catch_100089a8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100089b2;
}



// Function: FUN_100089b8 at 100089b8

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100089b8(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 6;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10002f08((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x14))(1);
  }
  return unaff_EBX;
}



// Function: FUN_10008a04 at 10008a04

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008a04(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x2a0);
    if (this != (void *)0x0) {
      FUN_10007f46(this,param_1);
    }
    iVar1 = FUN_10008a75();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@10008a65 at 10008a65

undefined * Catch_10008a65(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008a6f;
}



// Function: FUN_10008a75 at 10008a75

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008a75(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10002f08((int)(unaff_ESI + 9));
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



// Function: FUN_10008ab7 at 10008ab7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008ab7(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x278);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000801b(puVar1);
    }
    iVar2 = FUN_10008b1e();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10008b0e at 10008b0e

undefined * Catch_10008b0e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008b18;
}



// Function: FUN_10008b1e at 10008b1e

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008b1e(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 2;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10002f08((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(*unaff_ESI + 0x20))(1);
  }
  return unaff_EBX;
}



// Function: FUN_10008b6a at 10008b6a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008b6a(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x284);
    if (this != (void *)0x0) {
      FUN_10008119(this,param_1);
    }
    iVar1 = FUN_10008bdb();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@10008bcb at 10008bcb

undefined * Catch_10008bcb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008bd5;
}



// Function: FUN_10008bdb at 10008bdb

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008bdb(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10002f08((int)(unaff_ESI + 5));
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



// Function: FUN_10008c1d at 10008c1d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10008c1d(undefined4 *param_1)

{
  FUN_1000eb90((int)param_1);
  *param_1 = ATL::CComObject<class_CEnumPublishers>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumPublishers>::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: QueryInterface at 10008c5d

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100143fc,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10008c77 at 10008c77

void FUN_10008c77(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10008c81 at 10008c81

void FUN_10008c81(void)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::Release();
  return;
}



// Function: FUN_10008c8b at 10008c8b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008c8b(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CEnumPublishers>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumPublishers>::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10008f71((int)param_1);
  return;
}



// Function: FUN_10008cd0 at 10008cd0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008cd0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CEnumPublishers>::vftable;
  FUN_1000829c((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_10020a6c + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10008d13 at 10008d13

long FUN_10008d13(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_100143fc,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10008d5f at 10008d5f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008d5f(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CEnumPublishers>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10008f71((int)(param_1 + 2));
  return;
}



// Function: FUN_10008da5 at 10008da5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10008da5(undefined4 *param_1)

{
  FUN_1000f046((int)param_1);
  *param_1 = ATL::CComObject<class_CEnumSubscribers>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumSubscribers>::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: FUN_10008de5 at 10008de5

undefined4 FUN_10008de5(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: QueryInterface at 10008df5

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10014498,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10008e0f at 10008e0f

void FUN_10008e0f(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10008e19 at 10008e19

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008e19(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CEnumSubscribers>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumSubscribers>::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10008f71((int)param_1);
  return;
}



// Function: FUN_10008e5e at 10008e5e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008e5e(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CEnumSubscribers>::vftable;
  FUN_1000856f((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_10020a6c + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10008ea1 at 10008ea1

long FUN_10008ea1(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10014498,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10008eed at 10008eed

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008eed(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CEnumSubscribers>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10008f71((int)(param_1 + 2));
  return;
}



// Function: FUN_10008f33 at 10008f33

undefined4 * __thiscall FUN_10008f33(void *this,byte param_1)

{
  FUN_10008c8b((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008f52 at 10008f52

undefined4 * __thiscall FUN_10008f52(void *this,byte param_1)

{
  FUN_10008d5f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008f71 at 10008f71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008f71(int param_1)

{
  FUN_100079c4(param_1 + 4);
  return;
}



// Function: FUN_10008f99 at 10008f99

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008f99(int param_1)

{
  FUN_10008f71(param_1);
  return;
}



// Function: FUN_10008fb7 at 10008fb7

undefined4 * __thiscall FUN_10008fb7(void *this,byte param_1)

{
  FUN_10008e19((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008fd6 at 10008fd6

undefined4 * __thiscall FUN_10008fd6(void *this,byte param_1)

{
  FUN_10008eed((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008ff5 at 10008ff5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008ff5(void *this,undefined4 param_1)

{
  FUN_1000e939((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CEnumPublisherEvents>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CEnumPublisherEvents>::vftable;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10009030 at 10009030

undefined4 __thiscall FUN_10009030(void *this,int *param_1,int param_2)

{
  if (*(int **)((int)this + 4) != param_1) {
    FUN_10006f5c((int *)((int)this + 4),param_1);
  }
  *(int *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = **(undefined4 **)(param_2 + 4);
  return 0;
}



// Function: FUN_1000905c at 1000905c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000905c(undefined4 *param_1)

{
  FUN_10006fc0((int)param_1);
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemPubEvents,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: FUN_10009095 at 10009095

undefined4 FUN_10009095(int param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_100090a5 at 100090a5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100090a5(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemPubEvents,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_100082d7((int)param_1);
  return;
}



// Function: FUN_100090e3 at 100090e3

undefined4 * __thiscall FUN_100090e3(void *this,byte param_1)

{
  FUN_100090a5((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009102 at 10009102

undefined4 FUN_10009102(int param_1,int param_2)

{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      if (*(int *)(param_1 + 0xc) == *(int *)(*(int *)(param_1 + 8) + 4)) {
        return 1;
      }
      FUN_10001012((int *)(param_1 + 0xc));
    } while (param_2 != 0);
  }
  return 0;
}



// Function: FUN_1000913b at 1000913b

undefined4 FUN_1000913b(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006a57(&PTR_DAT_10020938,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000915f at 1000915f

void FUN_1000915f(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006a97(&PTR_DAT_10020938,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_1000917f at 1000917f

void FUN_1000917f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006b38(&PTR_DAT_10020938,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000918d at 1000918d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000918d(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000905c(puVar1);
    }
    uVar2 = FUN_100091e8();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100091d9 at 100091d9

undefined * Catch_100091d9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100091e3;
}



// Function: FUN_100091e8 at 100091e8

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100091e8(void)

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



// Function: FUN_100091ff at 100091ff

int FUN_100091ff(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int unaff_EDI;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    return unaff_EDI;
  }
  *param_2 = 0;
  iVar3 = FUN_1000918d(&param_2);
  piVar2 = param_2;
  if (-1 < iVar3) {
    iVar3 = FUN_10009030(param_2,param_1,(int)(param_1 + 1));
    if (iVar3 != 0) goto LAB_1000924e;
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10013b74,piVar1);
  }
  if (iVar3 == 0) {
    return unaff_EDI;
  }
LAB_1000924e:
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x1c))(1);
  }
  return unaff_EDI;
}



// Function: FUN_10009264 at 10009264

int FUN_10009264(int param_1,void **param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = -0x7fffbffd;
  if (param_2 != (void **)0x0) {
    *param_2 = (void *)0x0;
    iVar1 = FUN_1000918d(&local_8);
    if (-1 < iVar1) {
      iVar1 = FUN_10009030(local_8,*(int **)(param_1 + 4),*(int *)(param_1 + 8));
      if (-1 < iVar1) {
        local_8[3] = *(int *)(param_1 + 0xc);
        iVar1 = ATL::AtlInternalQueryInterface
                          (local_8,(_ATL_INTMAP_ENTRY *)&PTR_DAT_10013e30,(_GUID *)&DAT_10016068,
                           param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
      }
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 0x1c))(1);
      }
    }
  }
  return iVar1;
}



// Function: FUN_100092d8 at 100092d8

void FUN_100092d8(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10008951(0,param_2,param_3);
    return;
  }
  FUN_10008a04(param_1,param_2,param_3);
  return;
}



// Function: FUN_100092f8 at 100092f8

void FUN_100092f8(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10008ab7(0,param_2,param_3);
    return;
  }
  FUN_10008b6a(param_1,param_2,param_3);
  return;
}



// Function: FUN_10009318 at 10009318

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009318(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10008c1d(puVar1);
    }
    uVar2 = FUN_10009375();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10009368 at 10009368

undefined * Catch_10009368(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009372;
}



// Function: FUN_10009375 at 10009375

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009375(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[6] = unaff_ESI[6] + 1;
    unaff_ESI[6] = unaff_ESI[6] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x10))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100093a5 at 100093a5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100093a5(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x24);
    if (this != (void *)0x0) {
      FUN_10008cd0(this,param_1);
    }
    uVar1 = FUN_1000940c();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@100093ff at 100093ff

undefined * Catch_100093ff(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009409;
}



// Function: FUN_1000940c at 1000940c

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000940c(void)

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



// Function: FUN_10009436 at 10009436

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009436(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10008da5(puVar1);
    }
    uVar2 = FUN_10009493();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10009486 at 10009486

undefined * Catch_10009486(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009490;
}



// Function: FUN_10009493 at 10009493

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009493(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[6] = unaff_ESI[6] + 1;
    unaff_ESI[6] = unaff_ESI[6] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x10))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_100094c3 at 100094c3

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100094c3(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x24);
    if (this != (void *)0x0) {
      FUN_10008e5e(this,param_1);
    }
    uVar1 = FUN_1000952a();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@1000951d at 1000951d

undefined * Catch_1000951d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10009527;
}



// Function: FUN_1000952a at 1000952a

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000952a(void)

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



// Function: FUN_10009554 at 10009554

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10009554(undefined4 *param_1)

{
  FUN_1000e939((int)param_1);
  *param_1 = ATL::CComObject<class_CEnumPublisherEvents>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumPublisherEvents>::vftable;
  (**(code **)(*DAT_10020a6c + 4))();
  return param_1;
}



// Function: QueryInterface at 10009594

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001459c,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100095ae at 100095ae

void FUN_100095ae(int param_1)

{
  FUN_10008de5(param_1 + -4);
  return;
}



// Function: FUN_100095b8 at 100095b8

void FUN_100095b8(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100095c2 at 100095c2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100095c2(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CEnumPublisherEvents>::vftable;
  param_1[1] = ATL::CComObject<class_CEnumPublisherEvents>::vftable;
  param_1[6] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10008f71((int)param_1);
  return;
}



// Function: FUN_10009607 at 10009607

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10009607(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CEnumPublisherEvents>::vftable;
  FUN_10008ff5((void *)((int)this + 8),param_1);
  (**(code **)(*DAT_10020a6c + 4))();
  return (undefined4 *)this;
}



// Function: FUN_1000964a at 1000964a

undefined4 FUN_1000964a(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: Release at 1000965a

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



// Function: FUN_1000967b at 1000967b

long FUN_1000967b(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 2,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1001459c,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_100096c7 at 100096c7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100096c7(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CEnumPublisherEvents>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10020a6c + 8))();
  FUN_10008f71((int)(param_1 + 2));
  return;
}



// Function: FUN_1000970d at 1000970d

undefined4 * __thiscall FUN_1000970d(void *this,byte param_1)

{
  FUN_100095c2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000972c at 1000972c

undefined4 * __thiscall FUN_1000972c(void *this,byte param_1)

{
  FUN_100096c7((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000974b at 1000974b

void FUN_1000974b(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10009318(0,param_2,param_3);
    return;
  }
  FUN_100093a5(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000976b at 1000976b

void FUN_1000976b(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10009436(0,param_2,param_3);
    return;
  }
  FUN_100094c3(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000978b at 1000978b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000978b(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10009554(puVar1);
    }
    uVar2 = FUN_100097e8();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100097db at 100097db

undefined * Catch_100097db(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100097e5;
}



// Function: FUN_100097e8 at 100097e8

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100097e8(void)

{
  int iVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[6] = unaff_ESI[6] + 1;
    unaff_ESI[6] = unaff_ESI[6] + -1;
    iVar1 = (**(code **)*unaff_ESI)();
    *(int *)(unaff_EBP + -0x18) = iVar1;
    if (iVar1 != 0) {
      (**(code **)(*unaff_ESI + 0x10))(1);
    }
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10009818 at 10009818

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009818(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x24);
    if (this != (void *)0x0) {
      FUN_10009607(this,param_1);
    }
    uVar1 = FUN_1000987f();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10009872 at 10009872

undefined * Catch_10009872(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000987c;
}



// Function: FUN_1000987f at 1000987f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000987f(void)

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



// Function: FUN_100098a9 at 100098a9

void FUN_100098a9(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000978b(0,param_2,param_3);
    return;
  }
  FUN_10009818(param_1,param_2,param_3);
  return;
}



// Function: FUN_100098c9 at 100098c9

undefined4 FUN_100098c9(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_100209c8 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_100098fb at 100098fb

void __thiscall FUN_100098fb(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_8 = 0;
  local_14 = param_2;
                    /* WARNING: Load size is inaccurate */
  local_c = 1;
  (**(code **)(**this + 0x18))(*this,param_1,&PTR_10016038,0x400,1,&local_14,param_3,0,0);
  return;
}



// Function: FUN_1000993a at 1000993a

int __thiscall FUN_1000993a(void *this,undefined4 param_1)

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



// Function: InternalCopy at 1000997c

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
    FUN_1000104d(iVar1);
  }
  return;
}



// Function: FUN_100099a4 at 100099a4

void __fastcall FUN_100099a4(int *param_1)

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



// Function: FUN_100099df at 100099df

void __fastcall FUN_100099df(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_100099e7 at 100099e7

undefined2 * __thiscall FUN_100099e7(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) goto LAB_100099fe;
  while( true ) {
    FUN_1000104d(iVar1);
LAB_100099fe:
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



// Function: FUN_10009a30 at 10009a30

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_10009a30(void *this,undefined4 param_1,tagVARIANT *param_2,tagVARIANT *param_3,
            undefined4 param_4)

{
  undefined4 uVar1;
  undefined2 local_40 [8];
  undefined2 local_30 [8];
  undefined2 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x10009a3c;
  if ((param_2 == (tagVARIANT *)0x0) || (param_3 == (tagVARIANT *)0x0)) {
    uVar1 = 0x80070057;
  }
  else {
    local_40[0] = 0;
    ATL::CComVariant::InternalCopy((CComVariant *)local_40,param_3);
    local_8 = 0;
    local_30[0] = 0;
    ATL::CComVariant::InternalCopy((CComVariant *)local_30,param_2);
    local_8 = 1;
    local_1c = 0;
    local_14 = 0;
    local_20 = local_40;
                    /* WARNING: Load size is inaccurate */
    local_18 = 2;
    uVar1 = (**(code **)(**this + 0x18))(*this,param_1,&PTR_10016038,0x400,1,&local_20,param_4,0,0);
    local_8 = 0xffffffff;
    _eh_vector_destructor_iterator_(local_40,0x10,2,FUN_100099df);
  }
  return uVar1;
}



// Function: FUN_10009ad0 at 10009ad0

void __thiscall FUN_10009ad0(void *this,int param_1)

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



// Function: FUN_10009b15 at 10009b15

void __thiscall FUN_10009b15(void *this,int *param_1)

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



// Function: FUN_10009b5c at 10009b5c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10009b5c(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10009b68;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10018c00);
}



// Function: FUN_10009bbb at 10009bbb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_10009bbb(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10009bc7;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10018c00);
}



// Function: FUN_10009c1a at 10009c1a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009c1a(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = Ordinal_2(L"{3E31EB53-8CEF-4FC9-94AC-8619887851D3}");
  if (iVar2 != 0) goto LAB_10009c51;
  do {
    FUN_1000104d(0x8007000e);
LAB_10009c51:
    iVar3 = Ordinal_2(L"{3F20B3AC-EF09-4A15-B18A-FE9D3AD66E85}");
  } while (iVar3 == 0);
  piVar1 = (int *)(param_1 + 4);
  (**(code **)(*piVar1 + 0x1c))(piVar1,iVar2);
  uVar4 = (**(code **)(*piVar1 + 0x24))(piVar1,iVar2,iVar3,param_1 + 0x6c);
  Ordinal_6(iVar3);
  Ordinal_6(iVar2);
  return uVar4;
}



// Function: FUN_10009ca8 at 10009ca8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10009ca8(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10009ccd at 10009ccd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10009ccd(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_10013da4,this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009d08 at 10009d08

void __fastcall FUN_10009d08(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10009bbb((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0xb) = 0;
  return;
}



// Function: FUN_10009d2f at 10009d2f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009d2f(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 local_20 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x10009d3b;
  piVar1 = (int *)param_1[0x17];
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    param_1 = piVar1;
    (**(code **)(*piVar1 + 4))(piVar1);
    local_8 = 2;
    local_20[0] = 0;
    FUN_100099e7(local_20,param_2);
    local_8._0_1_ = 3;
    uVar2 = FUN_100098fb(&param_1,1,local_20,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_9(local_20);
    local_8 = 0xffffffff;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10009d9f at 10009d9f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009d9f(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 local_20 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x10009dab;
  piVar1 = (int *)param_1[0x17];
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    param_1 = piVar1;
    (**(code **)(*piVar1 + 4))(piVar1);
    local_8 = 2;
    local_20[0] = 0;
    FUN_100099e7(local_20,param_2);
    local_8._0_1_ = 3;
    uVar2 = FUN_100098fb(&param_1,2,local_20,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_9(local_20);
    local_8 = 0xffffffff;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10009e0f at 10009e0f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009e0f(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 local_30 [8];
  undefined2 local_20 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10009e1b;
  piVar1 = (int *)param_1[0x17];
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    param_1 = piVar1;
    (**(code **)(*piVar1 + 4))(piVar1);
    local_8 = 2;
    local_30[0] = 0;
    FUN_100099e7(local_30,param_2);
    local_8._0_1_ = 3;
    local_20[0] = 0;
    FUN_100099e7(local_20,param_3);
    local_8._0_1_ = 4;
    uVar2 = FUN_10009a30(&param_1,3,(tagVARIANT *)local_30,(tagVARIANT *)local_20,0);
    local_8._0_1_ = 3;
    Ordinal_9(local_20);
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_9(local_30);
    local_8 = 0xffffffff;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10009ea4 at 10009ea4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009ea4(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 local_30 [8];
  undefined2 local_20 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x10009eb0;
  piVar1 = (int *)param_1[0x17];
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    param_1 = piVar1;
    (**(code **)(*piVar1 + 4))(piVar1);
    local_8 = 2;
    local_30[0] = 0;
    FUN_100099e7(local_30,param_2);
    local_8._0_1_ = 3;
    local_20[0] = 0;
    FUN_100099e7(local_20,param_3);
    local_8._0_1_ = 4;
    uVar2 = FUN_10009a30(&param_1,5,(tagVARIANT *)local_30,(tagVARIANT *)local_20,0);
    local_8._0_1_ = 3;
    Ordinal_9(local_20);
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_9(local_30);
    local_8 = 0xffffffff;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



// Function: FUN_10009f39 at 10009f39

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009f39(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined2 local_40 [8];
  undefined2 local_30 [8];
  undefined2 local_20 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x10009f45;
  piVar1 = *(int **)(param_1 + 0x5c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    local_8 = 2;
    local_40[0] = 0;
    FUN_100099e7(local_40,param_2);
    local_8._0_1_ = 3;
    local_30[0] = 0;
    FUN_100099e7(local_30,param_3);
    local_8._0_1_ = 4;
    local_20[0] = 0;
    FUN_100099e7(local_20,param_4);
    local_8._0_1_ = 4;
    Ordinal_9(local_20);
    local_8._0_1_ = 3;
    Ordinal_9(local_30);
    local_8 = CONCAT31(local_8._1_3_,2);
    Ordinal_9(local_40);
    local_8 = 0xffffffff;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



// Function: FUN_10009fd2 at 10009fd2

int __fastcall FUN_10009fd2(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_10009b5c((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x15) = 1;
  return param_1;
}



// Function: FUN_1000a009 at 1000a009

void __thiscall FUN_1000a009(void *this,undefined4 *param_1,int *param_2)

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
  FUN_100099a4((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x15) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x15) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000a053;
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
LAB_1000a053:
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
LAB_1000a230:
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000a1e4:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[5] != '\x01'))
  goto LAB_1000a22c;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_10009ad0(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(*piVar5 + 0x14) != '\x01') || (*(char *)(piVar5[2] + 0x14) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x14) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x14) = 1;
          *(undefined1 *)(piVar5 + 5) = 0;
          FUN_10009b15(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 5) = (char)piVar6[5];
        *(undefined1 *)(piVar6 + 5) = 1;
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        FUN_10009ad0(this,(int)piVar6);
        goto LAB_1000a22c;
      }
LAB_1000a1db:
      *(undefined1 *)(piVar5 + 5) = 0;
    }
  }
  else {
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_10009b15(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(piVar5[2] + 0x14) == '\x01') && (*(char *)(*piVar5 + 0x14) == '\x01'))
      goto LAB_1000a1db;
      if (*(char *)(*piVar5 + 0x14) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        *(undefined1 *)(piVar5 + 5) = 0;
        FUN_10009ad0(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 5) = (char)piVar6[5];
      *(undefined1 *)(piVar6 + 5) = 1;
      *(undefined1 *)(*piVar5 + 0x14) = 1;
      FUN_10009b15(this,piVar6);
LAB_1000a22c:
      *(undefined1 *)(piVar7 + 5) = 1;
      goto LAB_1000a230;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000a1e4;
}



// Function: FUN_1000a254 at 1000a254

void FUN_1000a254(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x15);
  while (cVar1 == '\0') {
    FUN_1000a254((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  return;
}



// Function: FUN_1000a289 at 1000a289

undefined4 * __thiscall FUN_1000a289(void *this,wchar_t *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x2d) == '\0') {
    iVar2 = FUN_100016ce(puVar3 + 3,param_1);
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



// Function: FUN_1000a2be at 1000a2be

void __fastcall FUN_1000a2be(int param_1)

{
  FUN_1000a254(*(int **)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: basic_string<> at 1000a2e5

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
  FUN_10001aec(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: FUN_1000a30d at 1000a30d

void __thiscall FUN_1000a30d(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_1000a2be((int)this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_100099a4((int *)&param_2);
      FUN_1000a009(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000a360 at 1000a360

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000a360(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 local_18;
  
  if (param_4 == 0) {
    local_18 = 0x80004003;
  }
  else {
    if ((((param_2 != 0) && (iVar1 = Ordinal_7(param_2), iVar1 != 0)) && (param_3 != 0)) &&
       (iVar1 = Ordinal_7(param_3), iVar1 != 0)) {
      return 0x80004001;
    }
    local_18 = 0x80070057;
  }
  return local_18;
}



// Function: Catch@1000a3be at 1000a3be

undefined * Catch_1000a3be(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x18);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + 8) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::GetActiveEventSubscribersCountGetActiveEventSubscribersCount\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (*(int **)(unaff_EBP + 0xc) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a42c;
}



// Function: Catch@1000a42e at 1000a42e

undefined4 Catch_1000a42e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000a3b3;
}



// Function: FUN_1000a43f at 1000a43f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a43f(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000a30d(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000a479 at 1000a479

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000a479(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000a485;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_10009fd2(param_1);
  return local_18;
}



// Function: FUN_1000a4a5 at 1000a4a5

void __thiscall
FUN_1000a4a5(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
    FUN_1000608c(this,param_4 + 3);
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
LAB_1000a574:
        *(undefined1 *)(piVar1 + 0xb) = 1;
        *(undefined1 *)(iVar4 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10001689(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        FUN_10002968(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x2c) == '\0') goto LAB_1000a574;
      if (piVar5 == (int *)*piVar1) {
        FUN_10002968(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      FUN_10001689(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_1000a5dd at 1000a5dd

void __thiscall FUN_1000a5dd(void *this,int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  wchar_t *this_00;
  undefined4 *puVar3;
  undefined4 *local_c;
  bool local_8;
  
  this_00 = (wchar_t *)(param_2 + 3);
  local_8 = true;
  puVar3 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  local_c = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)puVar3 + 0x2d) == '\0') {
    if ((char)param_3 == '\0') {
      iVar2 = FUN_100016ce(this_00,(wchar_t *)(puVar3 + 3));
      local_8 = iVar2 < 0;
    }
    else {
      iVar2 = FUN_100016ce(puVar3 + 3,this_00);
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
      goto LAB_1000a653;
    }
    FUN_1000109d((int *)&param_3);
  }
  puVar3 = param_3;
  iVar2 = FUN_100016ce(param_3 + 3,this_00);
  if (-1 < iVar2) {
    FUN_1000608c((int)this + 0xd,this_00);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_1000a653:
  piVar1 = (int *)FUN_1000a4a5(this,&param_3,local_8,local_c,param_2);
  *param_1 = *piVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_1000a6b3 at 1000a6b3

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a6b3(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  void *this;
  int *piVar1;
  int iVar2;
  undefined4 local_6c [3];
  int local_60;
  int *local_5c;
  int local_58;
  wchar_t *local_54;
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_60 = param_1;
  local_54 = param_3;
  local_58 = -0x7fffbffb;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar2 = Ordinal_7(param_2);
    if ((iVar2 != 0) && (local_54 != (wchar_t *)0x0)) {
      iVar2 = Ordinal_7(local_54);
      if (iVar2 != 0) {
        FUN_1000e79b(local_6c,(int *)(param_1 + 0x30));
        local_8._0_1_ = 1;
        FUN_10001e48(local_34,param_2);
        local_8._0_1_ = 2;
        FUN_10001dc3((void *)(param_1 + 0x6c),&local_5c,local_34);
        if ((local_5c != *(int **)(param_1 + 0x70)) &&
           (this = (void *)local_5c[10], this != (void *)0x0)) {
          FUN_10001e48(local_50,local_54);
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_10001dc3(this,&local_5c,local_50);
          if (local_5c == *(int **)((int)this + 4)) {
            local_58 = 1;
          }
          else {
            piVar1 = (int *)local_5c[10];
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 4))(piVar1);
              local_54 = (wchar_t *)0x0;
              local_58 = (**(code **)*piVar1)(piVar1,&DAT_100136f0,&local_54);
              if ((-1 < local_58) && (local_54 != (wchar_t *)0x0)) {
                local_58 = (**(code **)(*(int *)local_54 + 0x24))(local_54);
                if (-1 < local_58) {
                  (**(code **)(*(int *)local_5c[10] + 8))((int *)local_5c[10]);
                  FUN_100060e1(this,&local_5c,local_5c);
                }
                (**(code **)(*(int *)local_54 + 8))(local_54);
              }
              (**(code **)(*piVar1 + 8))(piVar1);
            }
          }
          local_8._1_3_ = (uint3)((uint)local_8 >> 8);
          local_8._0_1_ = 2;
          FID_conflict__Tidy(local_50,'\x01',0);
        }
        local_8._0_1_ = 1;
        FID_conflict__Tidy(local_34,'\x01',0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1000e7b6(local_6c);
        goto LAB_1000a819;
      }
    }
  }
  local_58 = -0x7ff8ffa9;
LAB_1000a819:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000a828 at 1000a828

undefined * Catch_1000a828(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x60);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x54) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x50));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x5c) + 0x8c);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::UnPublishEvent\nUnpublishing the Event object\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  if (*(int **)(unaff_EBP + -0x50) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x50));
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a896;
}



// Function: Catch@1000a898 at 1000a898

undefined4 Catch_1000a898(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x54) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000a81d;
}



// Function: FUN_1000a8a9 at 1000a8a9

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000a8a9(int param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4,int param_5)

{
  void *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_88 [2];
  int local_80;
  wchar_t *local_7c;
  wchar_t *local_78;
  int *local_74;
  int local_70;
  wchar_t local_6c [14];
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x88;
  local_78 = param_3;
  local_7c = param_4;
  local_70 = -0x7fffbffb;
  local_8 = 0;
  if (param_5 == 0) {
    local_70 = -0x7fffbffd;
  }
  else {
    if (param_2 != (wchar_t *)0x0) {
      iVar3 = Ordinal_7(param_2);
      if ((iVar3 != 0) && (local_78 != (wchar_t *)0x0)) {
        iVar3 = Ordinal_7(local_78);
        if ((iVar3 != 0) && (local_7c != (wchar_t *)0x0)) {
          iVar3 = Ordinal_7(local_7c);
          if (iVar3 != 0) {
            FUN_1000e79b(local_88,(int *)(param_1 + 0x2c));
            local_8._0_1_ = 1;
            FUN_10001e48(local_50,local_78);
            local_8._0_1_ = 2;
            FUN_10001dc3((void *)(param_1 + 0x68),&local_80,local_50);
            FUN_10001e48(local_34,param_2);
            local_8._0_1_ = 3;
            FUN_10001dc3((void *)(param_1 + 0x78),&local_74,local_34);
            FUN_1000e7cc(local_88);
            piVar2 = local_74;
            iVar3 = local_80;
            if ((local_74 == *(int **)(param_1 + 0x7c)) || (local_80 == *(int *)(param_1 + 0x6c))) {
              local_70 = -0x7ff8ffa9;
            }
            else {
              FUN_1000e7de(local_88);
              this = *(void **)(iVar3 + 0x28);
              if (this != (void *)0x0) {
                FUN_10001e48(local_6c,local_7c);
                local_8 = CONCAT31(local_8._1_3_,4);
                FUN_10001dc3(this,&local_80,local_6c);
                if (local_80 == *(int *)((int)this + 4)) {
                  local_70 = -0x7ff8ffa9;
                }
                else {
                  piVar1 = *(int **)(local_80 + 0x28);
                  if (piVar1 != (int *)0x0) {
                    (**(code **)(*piVar1 + 4))(piVar1);
                    piVar2 = (int *)piVar2[10];
                    if (piVar2 != (int *)0x0) {
                      (**(code **)(*piVar2 + 4))(piVar2);
                      FUN_1000e7cc(local_88);
                      local_74 = (int *)0x0;
                      local_70 = (**(code **)*piVar2)(piVar2,&DAT_100136d0,&local_74);
                      if ((-1 < local_70) && (local_74 != (int *)0x0)) {
                        local_70 = (**(code **)(*local_74 + 0x1c))
                                             (local_74,local_78,local_7c,param_5);
                        if (-1 < local_70) {
                          local_78 = (wchar_t *)0x0;
                          local_70 = (**(code **)*piVar1)(piVar1,&DAT_100136f0,&local_78);
                          if ((-1 < local_70) && (local_78 != (wchar_t *)0x0)) {
                            local_70 = (**(code **)(*(int *)local_78 + 0x1c))
                                                 (local_78,param_2,local_74);
                            (**(code **)(*(int *)local_78 + 8))(local_78);
                          }
                        }
                        (**(code **)(*local_74 + 8))(local_74);
                      }
                      (**(code **)(*piVar2 + 8))(piVar2);
                    }
                    (**(code **)(*piVar1 + 8))(piVar1);
                  }
                }
                local_8._1_3_ = (uint3)((uint)local_8 >> 8);
                local_8._0_1_ = 3;
                FID_conflict__Tidy(local_6c,'\x01',0);
              }
            }
            local_8._0_1_ = 2;
            FID_conflict__Tidy(local_34,'\x01',0);
            local_8._0_1_ = 1;
            FID_conflict__Tidy(local_50,'\x01',0);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_1000e7b6(local_88);
            goto LAB_1000ab0d;
          }
        }
      }
    }
    local_70 = -0x7ff8ffa9;
  }
LAB_1000ab0d:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000ab1c at 1000ab1c

undefined * Catch_1000ab1c(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x94);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x70));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x90) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::SubscribeToEvent\nSubscribing to an event\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (*(int **)(unaff_EBP + -0x70) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x70));
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ab90;
}



// Function: Catch@1000ab95 at 1000ab95

undefined4 Catch_1000ab95(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ab11;
}



// Function: FUN_1000aba6 at 1000aba6

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000aba6(int param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  void *this;
  int *piVar1;
  int iVar2;
  undefined4 local_90 [3];
  int local_84;
  int local_80;
  int local_7c;
  wchar_t *local_78;
  wchar_t *local_74;
  int local_70;
  wchar_t local_6c [14];
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_80 = param_1;
  local_78 = param_2;
  local_74 = param_4;
  local_70 = -0x7fffbffb;
  local_8 = 0;
  if ((param_2 == (wchar_t *)0x0) || (iVar2 = Ordinal_7(param_2), iVar2 == 0)) {
    local_70 = -0x7ff8ffa9;
  }
  if ((param_3 == (wchar_t *)0x0) || (iVar2 = Ordinal_7(param_3), iVar2 == 0)) {
    local_70 = -0x7ff8ffa9;
  }
  if ((local_74 == (wchar_t *)0x0) || (iVar2 = Ordinal_7(local_74), iVar2 == 0)) {
    local_70 = -0x7ff8ffa9;
  }
  else {
    FUN_1000e79b(local_90,(int *)(param_1 + 0x2c));
    local_8._0_1_ = 1;
    FUN_10001e48(local_6c,param_3);
    local_8._0_1_ = 2;
    FUN_10001dc3((void *)(param_1 + 0x68),&local_7c,local_6c);
    FUN_10001e48(local_34,local_78);
    local_8._0_1_ = 3;
    FUN_10001dc3((void *)(param_1 + 0x78),&local_84,local_34);
    if ((local_84 == *(int *)(param_1 + 0x7c)) || (local_7c == *(int *)(param_1 + 0x6c))) {
      local_70 = -0x7ff8ffa9;
    }
    else {
      this = *(void **)(local_7c + 0x28);
      if (this != (void *)0x0) {
        FUN_10001e48(local_50,local_74);
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_10001dc3(this,&local_7c,local_50);
        if (local_7c == *(int *)((int)this + 4)) {
          local_70 = -0x7ff8ffa9;
        }
        else {
          piVar1 = *(int **)(local_7c + 0x28);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 4))(piVar1);
            local_74 = (wchar_t *)0x0;
            local_70 = (**(code **)*piVar1)(piVar1,&DAT_100136f0,&local_74);
            if ((-1 < local_70) && (local_74 != (wchar_t *)0x0)) {
              local_70 = (**(code **)(*(int *)local_74 + 0x20))(local_74,local_78);
              (**(code **)(*(int *)local_74 + 8))(local_74);
            }
            (**(code **)(*piVar1 + 8))(piVar1);
          }
        }
        local_8._1_3_ = (uint3)((uint)local_8 >> 8);
        local_8._0_1_ = 3;
        FID_conflict__Tidy(local_50,'\x01',0);
      }
    }
    local_8._0_1_ = 2;
    FID_conflict__Tidy(local_34,'\x01',0);
    local_8._0_1_ = 1;
    FID_conflict__Tidy(local_6c,'\x01',0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1000e7b6(local_90);
  }
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000ad68 at 1000ad68

undefined * Catch_1000ad68(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x84);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x74));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x7c) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::UnSubscribeToEventUnsubscribing to an event\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (*(int **)(unaff_EBP + -0x74) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x74));
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000add9;
}



// Function: Catch@1000addb at 1000addb

undefined4 Catch_1000addb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ad5d;
}



// Function: FUN_1000adec at 1000adec

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000adec(int param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  void *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_8c [2];
  int local_84;
  int local_80;
  wchar_t *local_7c;
  wchar_t *local_78;
  int *local_74;
  int local_70;
  wchar_t local_6c [14];
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_84 = param_1;
  local_7c = param_3;
  local_78 = param_4;
  local_70 = -0x7fffbffb;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar3 = Ordinal_7(param_2);
    if ((iVar3 != 0) && (local_7c != (wchar_t *)0x0)) {
      iVar3 = Ordinal_7(local_7c);
      if ((iVar3 != 0) && (local_78 != (wchar_t *)0x0)) {
        iVar3 = Ordinal_7(local_78);
        if (iVar3 != 0) {
          FUN_1000e79b(local_8c,(int *)(param_1 + 0x2c));
          local_8._0_1_ = 1;
          FUN_10001e48(local_34,local_7c);
          local_8._0_1_ = 2;
          FUN_10001dc3((void *)(param_1 + 0x68),&local_80,local_34);
          FUN_10001e48(local_6c,param_2);
          local_8._0_1_ = 3;
          FUN_10001dc3((void *)(param_1 + 0x78),&local_74,local_6c);
          piVar2 = local_74;
          if ((local_74 == *(int **)(param_1 + 0x7c)) || (local_80 == *(int *)(param_1 + 0x6c))) {
            local_70 = -0x7ff8ffa9;
          }
          else {
            this = *(void **)(local_80 + 0x28);
            if (this != (void *)0x0) {
              FUN_10001e48(local_50,local_78);
              local_8 = CONCAT31(local_8._1_3_,4);
              FUN_10001dc3(this,&local_80,local_50);
              if (local_80 == *(int *)((int)this + 4)) {
                local_70 = -0x7ff8ffa9;
              }
              else {
                piVar1 = *(int **)(local_80 + 0x28);
                if (piVar1 != (int *)0x0) {
                  (**(code **)(*piVar1 + 4))(piVar1);
                  piVar2 = (int *)piVar2[10];
                  if (piVar2 != (int *)0x0) {
                    (**(code **)(*piVar2 + 4))(piVar2);
                    local_74 = (int *)0x0;
                    local_70 = (**(code **)*piVar2)(piVar2,&DAT_100136d0,&local_74);
                    if ((-1 < local_70) && (local_74 != (int *)0x0)) {
                      local_70 = (**(code **)(*local_74 + 0x30))(local_74,local_7c,local_78);
                      (**(code **)(*local_74 + 8))(local_74);
                    }
                    (**(code **)(*piVar2 + 8))(piVar2);
                  }
                  (**(code **)(*piVar1 + 8))(piVar1);
                }
              }
              local_8._1_3_ = (uint3)((uint)local_8 >> 8);
              local_8._0_1_ = 3;
              FID_conflict__Tidy(local_50,'\x01',0);
            }
          }
          local_8._0_1_ = 2;
          FID_conflict__Tidy(local_6c,'\x01',0);
          local_8._0_1_ = 1;
          FID_conflict__Tidy(local_34,'\x01',0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_1000e7b6(local_8c);
          goto LAB_1000afbd;
        }
      }
    }
  }
  local_70 = -0x7ff8ffa9;
LAB_1000afbd:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000afcc at 1000afcc

undefined * Catch_1000afcc(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x8c);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x70));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x80) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::SuspendEventSubcriptionSuspendiing a subscriber\'s event subscription\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (*(int **)(unaff_EBP + -0x70) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x70));
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b03d;
}



// Function: Catch@1000b03f at 1000b03f

undefined4 Catch_1000b03f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000afc1;
}



// Function: FUN_1000b050 at 1000b050

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000b050(int param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  void *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_8c [2];
  int local_84;
  int local_80;
  wchar_t *local_7c;
  wchar_t *local_78;
  int *local_74;
  int local_70;
  wchar_t local_6c [14];
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_84 = param_1;
  local_7c = param_3;
  local_78 = param_4;
  local_70 = -0x7fffbffb;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar3 = Ordinal_7(param_2);
    if ((iVar3 != 0) && (local_7c != (wchar_t *)0x0)) {
      iVar3 = Ordinal_7(local_7c);
      if ((iVar3 != 0) && (local_78 != (wchar_t *)0x0)) {
        iVar3 = Ordinal_7(local_78);
        if (iVar3 != 0) {
          FUN_1000e79b(local_8c,(int *)(param_1 + 0x2c));
          local_8._0_1_ = 1;
          FUN_10001e48(local_34,local_7c);
          local_8._0_1_ = 2;
          FUN_10001dc3((void *)(param_1 + 0x68),&local_80,local_34);
          FUN_10001e48(local_6c,param_2);
          local_8._0_1_ = 3;
          FUN_10001dc3((void *)(param_1 + 0x78),&local_74,local_6c);
          piVar2 = local_74;
          if ((local_74 == *(int **)(param_1 + 0x7c)) || (local_80 == *(int *)(param_1 + 0x6c))) {
            local_70 = -0x7ff8ffa9;
          }
          else {
            this = *(void **)(local_80 + 0x28);
            if (this != (void *)0x0) {
              FUN_10001e48(local_50,local_78);
              local_8 = CONCAT31(local_8._1_3_,4);
              FUN_10001dc3(this,&local_80,local_50);
              if (local_80 == *(int *)((int)this + 4)) {
                local_70 = -0x7ff8ffa9;
              }
              else {
                piVar1 = *(int **)(local_80 + 0x28);
                if (piVar1 != (int *)0x0) {
                  (**(code **)(*piVar1 + 4))(piVar1);
                  piVar2 = (int *)piVar2[10];
                  if (piVar2 != (int *)0x0) {
                    (**(code **)(*piVar2 + 4))(piVar2);
                    local_74 = (int *)0x0;
                    local_70 = (**(code **)*piVar2)(piVar2,&DAT_100136d0,&local_74);
                    if ((-1 < local_70) && (local_74 != (int *)0x0)) {
                      local_70 = (**(code **)(*local_74 + 0x34))(local_74,local_7c,local_78);
                      (**(code **)(*local_74 + 8))(local_74);
                    }
                    (**(code **)(*piVar2 + 8))(piVar2);
                  }
                  (**(code **)(*piVar1 + 8))(piVar1);
                }
              }
              local_8._1_3_ = (uint3)((uint)local_8 >> 8);
              local_8._0_1_ = 3;
              FID_conflict__Tidy(local_50,'\x01',0);
            }
          }
          local_8._0_1_ = 2;
          FID_conflict__Tidy(local_6c,'\x01',0);
          local_8._0_1_ = 1;
          FID_conflict__Tidy(local_34,'\x01',0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_1000e7b6(local_8c);
          goto LAB_1000b221;
        }
      }
    }
  }
  local_70 = -0x7ff8ffa9;
LAB_1000b221:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000b230 at 1000b230

undefined * Catch_1000b230(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x8c);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x70));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x80) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::ResumeEventSubcriptionResuming a subscriber\'s event subscription\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (*(int **)(unaff_EBP + -0x70) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x70));
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b2a1;
}



// Function: Catch@1000b2a3 at 1000b2a3

undefined4 Catch_1000b2a3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000b225;
}



// Function: FUN_1000b2b4 at 1000b2b4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000b2b4(void *this,int param_1)

{
  *(undefined ***)this = CFCBstrDualId::vftable;
  basic_string<>((void *)((int)this + 4),(undefined4 *)(param_1 + 4));
  FUN_10001e8f((void *)((int)this + 0x20),(undefined4 *)(param_1 + 0x20));
  FUN_10001e8f((void *)((int)this + 0x3c),(undefined4 *)(param_1 + 0x3c));
  return (undefined4 *)this;
}



// Function: FUN_1000b308 at 1000b308

undefined4 * __thiscall FUN_1000b308(void *this,byte param_1)

{
  FUN_1000e50c((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b327 at 1000b327

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_1000b327(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  wchar_t *this;
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  char cVar5;
  int *piVar6;
  void *local_c;
  void *pvStack_8;
  
  piVar2 = param_4;
  this = (wchar_t *)(param_4 + 3);
  local_c = param_1;
  pvStack_8 = param_1;
  if (*(int *)((int)param_1 + 8) == 0) {
    piVar6 = *(int **)((int)param_1 + 4);
  }
  else {
    piVar1 = *(int **)((int)param_1 + 4);
    if (param_3 == (int *)*piVar1) {
      iVar3 = FUN_100016ce(this,(wchar_t *)(param_3 + 3));
      if (-1 < iVar3) goto LAB_1000b437;
      cVar5 = '\x01';
      goto LAB_1000b343;
    }
    if (param_3 == piVar1) {
      iVar3 = FUN_100016ce((void *)(piVar1[2] + 0xc),this);
      if (-1 < iVar3) goto LAB_1000b437;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_1000b343;
    }
    iVar3 = FUN_100016ce(this,(wchar_t *)(param_3 + 3));
    if (iVar3 < 0) {
      param_4 = param_3;
      FUN_1000109d((int *)&param_4);
      piVar1 = param_4;
      iVar3 = FUN_100016ce(param_4 + 3,this);
      if (-1 < iVar3) goto LAB_1000b3e6;
      cVar5 = *(char *)(piVar1[2] + 0x2d);
      piVar6 = param_3;
    }
    else {
LAB_1000b3e6:
      iVar3 = FUN_100016ce(param_3 + 3,(wchar_t *)(piVar2 + 3));
      if (-1 < iVar3) {
LAB_1000b437:
        puVar4 = (undefined4 *)FUN_1000a5dd(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_10001012((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (iVar3 = FUN_100016ce(piVar2 + 3,(wchar_t *)(param_4 + 3)), -1 < iVar3)) goto LAB_1000b437;
      cVar5 = *(char *)(param_3[2] + 0x2d);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_1000b343;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_1000b343:
  FUN_1000a4a5(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_1000b453 at 1000b453

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000b453(int *param_1,wchar_t *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_b8 [2];
  int *local_b0;
  int local_ac;
  int local_a8;
  int *local_a4;
  int local_a0;
  wchar_t *local_9c;
  int *local_98;
  int *local_94;
  int local_90;
  undefined4 local_8c [22];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_b0 = param_1;
  local_9c = param_2;
  local_90 = -0x7fffbffb;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar3 = Ordinal_7(param_2);
    if (iVar3 != 0) {
      FUN_1000e79b(local_b8,param_1 + 0xb);
      local_8._0_1_ = 1;
      FUN_10001e48(local_34,param_2);
      local_8._0_1_ = 2;
      FUN_10001dc3(param_1 + 0x1e,&local_a4,local_34);
      if (local_a4 == (int *)param_1[0x1f]) {
        local_90 = -0x7ff8ffa9;
      }
      else {
        piVar1 = (int *)local_a4[10];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
          FUN_10009ccd(&local_98,piVar1);
          local_8._0_1_ = 3;
          if (local_98 != (int *)0x0) {
            local_a8 = 0;
            local_90 = (**(code **)(*local_98 + 0x2c))(local_98,&local_a8);
            if (-1 < local_90) {
              local_ac = local_a8;
              while (piVar2 = (int *)**(int **)(local_ac + 4), piVar2 != *(int **)(local_ac + 4)) {
                FUN_1000b2b4(local_8c,(int)(piVar2 + 3));
                local_8 = CONCAT31(local_8._1_3_,4);
                iVar3 = FUN_1000e305((int)local_8c);
                if (iVar3 == 0) {
                  local_94 = (int *)0x0;
                }
                else {
                  local_94 = (int *)Ordinal_2(iVar3);
                  if (local_94 == (int *)0x0) goto LAB_1000b5b0;
                }
                local_8 = CONCAT31(local_8._1_3_,5);
                iVar3 = FUN_1000e30d((int)local_8c);
                if (iVar3 == 0) {
                  local_a0 = 0;
                }
                else {
                  while( true ) {
                    local_a0 = Ordinal_2(iVar3);
                    if (local_a0 != 0) break;
LAB_1000b5b0:
                    iVar3 = FUN_1000104d(0x8007000e);
                  }
                }
                local_8._0_1_ = 6;
                (**(code **)(*param_1 + 0x28))(param_1,local_9c,local_94,local_a0);
                local_8._0_1_ = 5;
                Ordinal_6(local_a0);
                local_8._0_1_ = 4;
                Ordinal_6(local_94);
                local_8._0_1_ = 3;
                FUN_1000e50c(local_8c);
              }
              if (-1 < local_90) {
                local_90 = (**(code **)(*piVar1 + 0x20))(piVar1,&local_9c);
                local_94 = (int *)0x0;
                local_8._0_1_ = 8;
                puVar4 = (undefined4 *)(**(code **)(param_1[-3] + 0x10))();
                local_90 = (**(code **)*puVar4)(puVar4,&DAT_10014610,&local_94);
                local_90 = (**(code **)(*local_94 + 0x20))(local_94,local_9c);
                local_8._0_1_ = 3;
                if (local_94 != (int *)0x0) {
                  (**(code **)(*local_94 + 8))(local_94);
                }
              }
            }
          }
          (**(code **)(*piVar1 + 8))(piVar1);
          FUN_100060e1(param_1 + 0x1e,&local_9c,local_a4);
          (**(code **)(*piVar1 + 8))(piVar1);
          local_8._0_1_ = 2;
          if (local_98 != (int *)0x0) {
            (**(code **)(*local_98 + 8))(local_98);
          }
        }
      }
      local_8._0_1_ = 1;
      FID_conflict__Tidy(local_34,'\x01',0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000e7b6(local_b8);
      goto LAB_1000b6f9;
    }
  }
  local_90 = -0x7ff8ffa9;
LAB_1000b6f9:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000b70b at 1000b70b

undefined * Catch_1000b70b(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0xb8);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x8c) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x94));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0xac) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::UnRegisterSubscriberUnregistering a Subscriber\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  if (*(int **)(unaff_EBP + -0x94) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x94));
    *(undefined4 *)(unaff_EBP + -0x94) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b78b;
}



// Function: Catch@1000b790 at 1000b790

undefined4 Catch_1000b790(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x8c) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000b6fd;
}



// Function: FUN_1000b7a4 at 1000b7a4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b7a4(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x29c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006c71(puVar1);
    }
    uVar2 = FUN_1000b808();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000b7f8 at 1000b7f8

undefined * Catch_1000b7f8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b802;
}



// Function: FUN_1000b808 at 1000b808

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b808(void)

{
  LONG *lpAddend;
  int iVar1;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != (int *)0x0) {
    lpAddend = unaff_ESI + 3;
    InterlockedIncrement(lpAddend);
    iVar1 = FUN_10002f08((int)lpAddend);
    *(int *)(unaff_EBP + -0x14) = iVar1;
    if (-1 < iVar1) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    InterlockedDecrement(lpAddend);
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      (**(code **)(*unaff_ESI + 0x24))(1);
      unaff_ESI = (int *)0x0;
    }
  }
  *unaff_EBX = unaff_ESI;
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_1000b84d at 1000b84d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000b84d(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000b859;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_100019fe(param_1);
  return local_18;
}



// Function: FUN_1000b879 at 1000b879

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b879(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_1000750f(puVar1);
    }
    uVar2 = FUN_1000b8d7();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000b8c5 at 1000b8c5

undefined * Catch_1000b8c5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000b8cf;
}



// Function: FUN_1000b8d7 at 1000b8d7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000b8d7(void)

{
  int in_EAX;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + -1;
  }
  *unaff_ESI = in_EAX;
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000b8f1 at 1000b8f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000b8f1(int param_1)

{
  undefined1 auStack_44 [12];
  undefined4 uStack_38;
  
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_10001318((void *)(param_1 + 0x1c));
  FUN_1000e565(auStack_44,L"MessageRouterMaps");
  FUN_1000e862((undefined4 *)(param_1 + 0x38));
  *(undefined4 *)(param_1 + 0x70) = 0;
  FUN_1000b84d(param_1 + 0x74);
  FUN_1000b84d(param_1 + 0x84);
  uStack_38 = 0x1000b97b;
  memset((void *)(param_1 + 0x94),0,0x1fe);
  return param_1;
}



// Function: FUN_1000b98a at 1000b98a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000b98a(void *this,byte param_1)

{
  FUN_1000782a(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000b9bb at 1000b9bb

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000b9bb(int param_1,wchar_t *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *this;
  int iVar2;
  void *local_40;
  int local_3c;
  int *local_38;
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0;
  if (param_3 == (undefined4 *)0x0) {
    local_3c = -0x7fffbffd;
    goto LAB_1000bae3;
  }
  if (param_2 != (wchar_t *)0x0) {
    iVar2 = Ordinal_7(param_2);
    if (iVar2 != 0) {
      *param_3 = 0;
      FUN_10001e48(local_34,param_2);
      local_8._0_1_ = 1;
      FUN_10001dc3((void *)(param_1 + 0x74),&local_38,local_34);
      piVar1 = local_38;
      if (local_38 == *(int **)(param_1 + 0x78)) {
        local_3c = -0x7ff8ffa9;
      }
      else {
        local_38 = (int *)0x0;
        local_3c = FUN_1000b879(&local_38);
        this = local_38;
        if ((-1 < local_3c) && (local_38 != (int *)0x0)) {
          (**(code **)(*local_38 + 4))(local_38);
          FUN_10009ccd(&local_38,(undefined4 *)piVar1[10]);
          local_8 = CONCAT31(local_8._1_3_,2);
          if (local_38 == (int *)0x0) {
LAB_1000ba7f:
            local_3c = -0x7fffbffd;
          }
          else {
            local_40 = (void *)0x0;
            (**(code **)(*local_38 + 0x2c))(local_38,&local_40);
            if (local_40 == (void *)0x0) goto LAB_1000ba7f;
            local_3c = FUN_1000ee79(this,local_40);
            if (-1 < local_3c) {
              local_3c = (**(code **)*this)(this,&DAT_10013d84,param_3);
            }
          }
          (**(code **)(*this + 8))(this);
          local_8._1_3_ = (uint3)((uint)local_8 >> 8);
          local_8._0_1_ = 1;
          if (local_38 != (int *)0x0) {
            (**(code **)(*local_38 + 8))(local_38);
          }
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FID_conflict__Tidy(local_34,'\x01',0);
      goto LAB_1000bae3;
    }
  }
  local_3c = -0x7ff8ffa9;
LAB_1000bae3:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000baf2 at 1000baf2

undefined * Catch_1000baf2(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x44);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x38) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x34));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x40) + 0x84);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::GetSubscriberEventsEnumEnumerating through a subscribed event list\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  if (*(int **)(unaff_EBP + -0x34) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x34));
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015920,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000bb60;
}



// Function: Catch@1000bb62 at 1000bb62

undefined4 Catch_1000bb62(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x38) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000bae7;
}



// Function: FUN_1000bb73 at 1000bb73

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000bb73(int *param_1,wchar_t *param_2)

{
  void *this;
  int *piVar1;
  int iVar2;
  undefined4 local_6c [3];
  int *local_60;
  int local_5c;
  int *local_58;
  undefined4 local_54;
  undefined4 local_50 [7];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_60 = param_1;
  local_54 = 0x80004005;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar2 = Ordinal_7(param_2);
    if (iVar2 != 0) {
      FUN_1000e79b(local_6c,param_1 + 0xc);
      local_8._0_1_ = 1;
      FUN_10001e48(local_34,param_2);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_10001dc3(param_1 + 0x1b,&local_58,local_34);
      if (local_58 == (int *)param_1[0x1c]) {
        local_54 = 1;
      }
      else {
        this = (void *)local_58[10];
        if (this != (void *)0x0) {
          while (piVar1 = (int *)**(int **)((int)this + 4), piVar1 != *(int **)((int)this + 4)) {
            FUN_10001e8f(local_50,piVar1 + 3);
            local_8 = CONCAT31(local_8._1_3_,3);
            iVar2 = FUN_100018a3(local_50);
            if (iVar2 == 0) {
              local_5c = 0;
            }
            else {
              local_5c = Ordinal_2(iVar2);
              if (local_5c == 0) {
                FUN_1000104d(0x8007000e);
                break;
              }
            }
            local_8._0_1_ = 4;
            local_54 = (**(code **)(*param_1 + 0x28))(param_1,param_2,local_5c);
            local_8._0_1_ = 3;
            Ordinal_6(local_5c);
            local_8 = CONCAT31(local_8._1_3_,2);
            FID_conflict__Tidy(local_50,'\x01',0);
          }
          FUN_1000b98a(this,1);
          FUN_100060e1(param_1 + 0x1b,&local_58,local_58);
          local_54 = 0;
        }
      }
      local_8._1_3_ = (uint3)((uint)local_8 >> 8);
      local_8._0_1_ = 1;
      FID_conflict__Tidy(local_34,'\x01',0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000e7b6(local_6c);
      goto LAB_1000bcaf;
    }
  }
  local_54 = 0x80070057;
LAB_1000bcaf:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000bcbe at 1000bcbe

undefined * Catch_1000bcbe(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x60);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x50) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x54));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x5c) + 0x8c);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::UnRegisterPublisher\nUnregistering the Publisher\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  if (*(int **)(unaff_EBP + -0x54) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x54));
    *(undefined4 *)(unaff_EBP + -0x54) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000bd2c;
}



// Function: Catch@1000bd2e at 1000bd2e

undefined4 Catch_1000bd2e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x50) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000bcb3;
}



// Function: FUN_1000bd3f at 1000bd3f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000bd3f(void *this,wchar_t *param_1)

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
  local_8 = 0x1000bd4b;
  piVar1 = FUN_1000a289(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_100016ce(param_1,(wchar_t *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_1000bdae;
  }
  FUN_10001e8f(local_34,(undefined4 *)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_1000ea00(this,local_34);
  FUN_1000b327(this,&local_38,piVar1,piVar3);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_34,'\x01',0);
LAB_1000bdae:
  FUN_1000f487();
  return;
}



// Function: FUN_1000bdb9 at 1000bdb9

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000bdb9(int param_1,wchar_t *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 local_6c [3];
  wchar_t *local_60;
  int local_5c;
  undefined4 local_58;
  void *local_54;
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_5c = param_1;
  local_60 = param_2;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar1 = Ordinal_7(param_2);
    if (iVar1 != 0) {
      FUN_1000e79b(local_6c,(int *)(param_1 + 0x30));
      local_8._0_1_ = 1;
      FUN_10001e48(local_50,param_2);
      local_8._0_1_ = 2;
      FUN_10001dc3((void *)(param_1 + 0x6c),&local_54,local_50);
      if (local_54 == *(void **)(param_1 + 0x70)) {
        FUN_10001e48(local_34,param_2);
        local_8._0_1_ = 3;
        local_54 = operator_new(0x10);
        local_8._0_1_ = 4;
        if (local_54 == (void *)0x0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_1000b84d((int)local_54);
        }
        local_8._0_1_ = 3;
        piVar2 = (int *)FUN_1000bd3f((void *)(param_1 + 0x6c),local_34);
        *piVar2 = iVar1;
        local_58 = 0;
        local_8._0_1_ = 2;
        FID_conflict__Tidy(local_34,'\x01',0);
      }
      else {
        local_58 = 0x80070057;
      }
      local_8._0_1_ = 1;
      FID_conflict__Tidy(local_50,'\x01',0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000e7b6(local_6c);
      goto LAB_1000beaa;
    }
  }
  local_58 = 0x80070057;
LAB_1000beaa:
  local_8 = 0xffffffff;
  FUN_1000bf21();
  return;
}



// Function: Catch@1000beb0 at 1000beb0

undefined * Catch_1000beb0(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x60);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x54) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x50));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x58) + 0x8c);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::RegisterPublisher\nRegistering the Publisher\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  if (*(int **)(unaff_EBP + -0x50) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x50));
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000bf1e;
}



// Function: FUN_1000bf21 at 1000bf21

void FUN_1000bf21(void)

{
  int unaff_EBP;
  int unaff_ESI;
  
  if (-1 < *(int *)(unaff_EBP + -0x54)) {
    (**(code **)(*(int *)(unaff_ESI + 0xc) + 0x1c))
              ((int *)(unaff_ESI + 0xc),*(undefined4 *)(unaff_EBP + -0x5c));
  }
  FUN_1000f496();
  return;
}



// Function: Catch@1000bf3c at 1000bf3c

undefined * Catch_1000bf3c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x54) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000bf1e;
}



// Function: FUN_1000bf4d at 1000bf4d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000bf4d(int param_1,wchar_t *param_2,wchar_t *param_3,undefined4 *param_4)

{
  void *this;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8c [3];
  int local_80;
  wchar_t *local_7c;
  wchar_t *local_78;
  HRESULT local_74;
  int *local_70;
  wchar_t local_6c [14];
  wchar_t local_50 [14];
  wchar_t local_34 [22];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_80 = param_1;
  local_7c = param_2;
  local_78 = param_3;
  local_74 = -0x7fffbffb;
  local_8 = 0;
  if (param_4 == (undefined4 *)0x0) {
    local_74 = -0x7fffbffd;
  }
  else {
    if (param_2 != (wchar_t *)0x0) {
      iVar1 = Ordinal_7(param_2);
      if ((iVar1 != 0) && (local_78 != (wchar_t *)0x0)) {
        iVar1 = Ordinal_7(local_78);
        if (iVar1 != 0) {
          FUN_1000e79b(local_8c,(int *)(param_1 + 0x30));
          local_8._0_1_ = 1;
          *param_4 = 0;
          FUN_10001e48(local_50,local_7c);
          local_8._0_1_ = 2;
          FUN_10001dc3((void *)(param_1 + 0x6c),&local_70,local_50);
          if (local_70 == *(int **)(param_1 + 0x70)) {
            local_74 = -0x7ff8ffa9;
          }
          else {
            this = (void *)local_70[10];
            if (this != (void *)0x0) {
              FUN_10001e48(local_6c,local_78);
              local_8._0_1_ = 3;
              FUN_10001dc3(this,&local_70,local_6c);
              if (local_70 == *(int **)((int)this + 4)) {
                local_70 = (int *)0x0;
                local_74 = CoCreateInstance((IID *)&DAT_10013710,(LPUNKNOWN)0x0,0x17,
                                            (IID *)&DAT_100136e0,&local_70);
                if (-1 < local_74) {
                  local_74 = (**(code **)(*local_70 + 0x1c))(local_70,local_7c,local_78);
                  if (-1 < local_74) {
                    FUN_10001e48(local_34,local_78);
                    local_8._0_1_ = 4;
                    puVar2 = (undefined4 *)FUN_1000bd3f(this,local_34);
                    *puVar2 = local_70;
                    puVar2 = (undefined4 *)FUN_1000bd3f(this,local_34);
                    (**(code **)(*(int *)*puVar2 + 4))((int *)*puVar2);
                    *param_4 = local_70;
                    (**(code **)(*local_70 + 4))(local_70);
                    local_8._0_1_ = 3;
                    FID_conflict__Tidy(local_34,'\x01',0);
                  }
                }
                (**(code **)(*local_70 + 8))(local_70);
              }
              local_8._0_1_ = 2;
              FID_conflict__Tidy(local_6c,'\x01',0);
            }
          }
          local_8._0_1_ = 1;
          FID_conflict__Tidy(local_50,'\x01',0);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_1000e7b6(local_8c);
          goto LAB_1000c10a;
        }
      }
    }
    local_74 = -0x7ff8ffa9;
  }
LAB_1000c10a:
  local_8 = 0xffffffff;
  FUN_1000c181();
  return;
}



// Function: Catch@1000c110 at 1000c110

undefined * Catch_1000c110(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x80);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x6c));
  *(undefined1 *)(unaff_EBP + -4) = 9;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x7c) + 0x8c);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::PublishEvent\nCreating and Initializing the Event object\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (*(int **)(unaff_EBP + -0x6c) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x6c));
    *(undefined4 *)(unaff_EBP + -0x6c) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c17e;
}



// Function: FUN_1000c181 at 1000c181

void FUN_1000c181(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  int unaff_ESI;
  
  if (-1 < *(int *)(unaff_EBP + -0x70)) {
    uVar1 = (**(code **)(*(int *)(unaff_ESI + 0xc) + 0x24))
                      ((int *)(unaff_ESI + 0xc),*(undefined4 *)(unaff_EBP + -0x78),
                       *(undefined4 *)(unaff_EBP + -0x74));
    *(undefined4 *)(unaff_EBP + -0x70) = uVar1;
  }
  FUN_1000f496();
  return;
}



// Function: Catch@1000c1a4 at 1000c1a4

undefined * Catch_1000c1a4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x70) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c17e;
}



// Function: FUN_1000c1b5 at 1000c1b5

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000c1b5(int param_1,undefined *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  code *pcVar3;
  code *pcVar4;
  undefined4 local_84 [2];
  code *local_7c;
  undefined4 *local_78;
  undefined4 local_74;
  undefined4 *local_70;
  code *local_6c;
  int local_68;
  undefined *local_64;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int *local_50;
  int *local_4c;
  undefined4 *local_48;
  int local_44;
  wchar_t local_40 [14];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_58 = param_1;
  local_64 = param_2;
  local_8 = 0;
  if ((param_2 == (undefined *)0x0) || (iVar1 = Ordinal_7(param_2), iVar1 == 0)) {
    local_44 = -0x7ff8ffa9;
  }
  else {
    FUN_1000e79b(local_84,(int *)(param_1 + 0x2c));
    local_8._0_1_ = 1;
    FUN_10001e48(local_40,(wchar_t *)param_2);
    local_8._0_1_ = 2;
    FUN_10001dc3((void *)(param_1 + 0x78),&local_48,local_40);
    if (local_48 == *(undefined4 **)(param_1 + 0x7c)) {
      local_4c = (int *)0x0;
      local_44 = FUN_1000b7a4(&local_48);
      local_44 = (**(code **)*local_48)(local_48,&DAT_10013d74,&local_4c);
      if (-1 < local_44) {
        puVar2 = (undefined4 *)FUN_1000bd3f((void *)(param_1 + 0x78),local_40);
        *puVar2 = local_4c;
        (**(code **)(*local_4c + 4))(local_4c);
        local_44 = (**(code **)*local_4c)(local_4c,&DAT_10015640,&local_48);
        if ((-1 < local_44) && (local_48 != (undefined4 *)0x0)) {
          local_54 = 0;
          local_50 = (int *)0x0;
          local_8._0_1_ = 4;
          puVar2 = (undefined4 *)(**(code **)(*(int *)(param_1 + -0xc) + 0x10))();
          local_44 = (**(code **)*puVar2)(puVar2,&DAT_10014610,&local_50);
          pcVar3 = Ordinal_2_exref;
          local_24 = 0;
          local_20 = 0;
          local_1c = 1;
          local_5c = Ordinal_2(L"Subscriber Thread: ");
          pcVar4 = (code *)param_2;
          if (local_5c != 0) goto LAB_1000c2e9;
LAB_1000c2df:
          do {
            iVar1 = -0x7ff8fff2;
            param_2 = pcVar4;
            do {
              FUN_1000104d(iVar1);
LAB_1000c2e9:
              local_8._0_1_ = 5;
              local_60 = (*pcVar3)(param_2);
              pcVar4 = (code *)param_2;
              if (local_60 == 0) goto LAB_1000c2df;
              local_8._0_1_ = 6;
              iVar1 = FUN_1000993a(&local_5c,local_60);
              pcVar4 = Ordinal_6_exref;
            } while (iVar1 < 0);
            local_8._0_1_ = 5;
            Ordinal_6(local_60);
            pcVar3 = (code *)(*pcVar3)(L"MessageRouter");
            local_7c = pcVar3;
          } while (pcVar3 == (code *)0x0);
          local_8 = CONCAT31(local_8._1_3_,7);
          local_78 = local_48;
          local_74 = 1;
          local_70 = &local_24;
          local_68 = local_5c;
          local_6c = pcVar3;
          local_44 = (**(code **)(*local_50 + 0x1c))(local_50,&local_78,&local_54);
          local_44 = (**(code **)(*local_4c + 0x1c))(local_4c,local_54,0);
          (**(code **)(*local_4c + 8))(local_4c);
          if (-1 < local_44) {
            (**(code **)(*local_50 + 0x30))(local_50,local_54);
          }
          local_8._0_1_ = 5;
          Ordinal_6(pcVar3);
          local_8._0_1_ = 4;
          Ordinal_6(local_5c);
          local_8._0_1_ = 2;
          if (local_50 != (int *)0x0) {
            (**(code **)(*local_50 + 8))(local_50);
          }
        }
      }
    }
    else {
      local_44 = -0x7ff8ffa9;
    }
    local_8._0_1_ = 1;
    FID_conflict__Tidy(local_40,'\x01',0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1000e7b6(local_84);
  }
  local_8 = 0xffffffff;
  FUN_1000c454();
  return;
}



// Function: Catch@1000c3e0 at 1000c3e0

undefined * Catch_1000c3e0(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x84);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x40) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x54) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::RegisterSubscriber\nRegistering and Initializing the subscriber object\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  if (*(int **)(unaff_EBP + -0x44) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x44));
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015850,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c451;
}



// Function: FUN_1000c454 at 1000c454

void FUN_1000c454(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int unaff_EBP;
  
  if (-1 < *(int *)(unaff_EBP + -0x40)) {
    uVar1 = (**(code **)(*(int *)(unaff_EBX + 8) + 0x20))
                      ((int *)(unaff_EBX + 8),*(undefined4 *)(unaff_EBP + -0x60));
    *(undefined4 *)(unaff_EBP + -0x40) = uVar1;
  }
  FUN_1000f496();
  return;
}



// Function: Catch@1000c474 at 1000c474

undefined * Catch_1000c474(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x40) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c451;
}



// Function: FUN_1000c485 at 1000c485

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c485(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10008c1d(puVar1);
    }
    uVar2 = FUN_1000c4e3();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000c4d1 at 1000c4d1

undefined * Catch_1000c4d1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c4db;
}



// Function: FUN_1000c4e3 at 1000c4e3

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c4e3(void)

{
  int in_EAX;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + -1;
  }
  *unaff_ESI = in_EAX;
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000c4fd at 1000c4fd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c4fd(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10008da5(puVar1);
    }
    uVar2 = FUN_1000c55b();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000c549 at 1000c549

undefined * Catch_1000c549(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c553;
}



// Function: FUN_1000c55b at 1000c55b

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c55b(void)

{
  int in_EAX;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + -1;
  }
  *unaff_ESI = in_EAX;
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000c575 at 1000c575

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c575(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10009554(puVar1);
    }
    uVar2 = FUN_1000c5d3();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@1000c5c1 at 1000c5c1

undefined * Catch_1000c5c1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c5cb;
}



// Function: FUN_1000c5d3 at 1000c5d3

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c5d3(void)

{
  int in_EAX;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;
    *(int *)(unaff_EBP + -0x18) = unaff_EDI;
    *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + -1;
  }
  *unaff_ESI = in_EAX;
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1000c5ed at 1000c5ed

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000c5ed(int param_1,int *param_2)

{
  int *piVar1;
  int *this;
  int local_18;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    local_18 = -0x7fffbffd;
  }
  else {
    *param_2 = 0;
    param_2 = (int *)0x0;
    local_18 = FUN_1000c485(&param_2);
    this = param_2;
    if ((-1 < local_18) && (param_2 != (int *)0x0)) {
      (**(code **)(*param_2 + 4))(param_2);
      local_18 = FUN_1000f072(this,(void *)(param_1 + 100));
      if (-1 < local_18) {
        local_18 = (**(code **)*this)(this,&DAT_10013d84,piVar1);
      }
      (**(code **)(*this + 8))(this);
    }
  }
  return local_18;
}



// Function: Catch@1000c668 at 1000c668

undefined * Catch_1000c668(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x18);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + 8) + 0x84);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::GetPublishersEnumEnumerating through a publisher list\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (*(int **)(unaff_EBP + 0xc) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015920,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c6d6;
}



// Function: Catch@1000c6d8 at 1000c6d8

undefined4 Catch_1000c6d8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000c65d;
}



// Function: FUN_1000c6e9 at 1000c6e9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000c6e9(int param_1,int *param_2)

{
  int *piVar1;
  int *this;
  int local_18;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    local_18 = -0x7fffbffd;
  }
  else {
    *param_2 = 0;
    param_2 = (int *)0x0;
    local_18 = FUN_1000c4fd(&param_2);
    this = param_2;
    if ((-1 < local_18) && (param_2 != (int *)0x0)) {
      (**(code **)(*param_2 + 4))(param_2);
      local_18 = FUN_1000f072(this,(void *)(param_1 + 0x74));
      if (-1 < local_18) {
        local_18 = (**(code **)*this)(this,&DAT_10013d84,piVar1);
      }
      (**(code **)(*this + 8))(this);
    }
  }
  return local_18;
}



// Function: Catch@1000c764 at 1000c764

undefined * Catch_1000c764(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x18);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + 8) + 0x84);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::GetSubscribersEnumEnumerating through a subscribers list\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (*(int **)(unaff_EBP + 0xc) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015920,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c7d2;
}



// Function: Catch@1000c7d4 at 1000c7d4

undefined4 Catch_1000c7d4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000c759;
}



// Function: FUN_1000c7e5 at 1000c7e5

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000c7e5(int param_1,wchar_t *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *this;
  int iVar2;
  int *local_3c;
  int local_38;
  wchar_t local_34 [22];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0;
  if (param_3 == (undefined4 *)0x0) {
    local_38 = -0x7fffbffd;
  }
  else {
    iVar2 = Ordinal_7(param_2);
    if (iVar2 == 0) {
      local_38 = -0x7ff8ffa9;
    }
    else {
      *param_3 = 0;
      FUN_10001e48(local_34,param_2);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_10001dc3((void *)(param_1 + 100),&local_3c,local_34);
      piVar1 = local_3c;
      if (local_3c == *(int **)(param_1 + 0x68)) {
        local_38 = -0x7ff8ffa9;
      }
      else {
        local_3c = (int *)0x0;
        local_38 = FUN_1000c575(&local_3c);
        this = local_3c;
        if ((-1 < local_38) && (local_3c != (int *)0x0)) {
          (**(code **)(*local_3c + 4))(local_3c);
          if ((void *)piVar1[10] == (void *)0x0) {
            local_38 = -0x7fffbffd;
          }
          else {
            local_38 = FUN_1000f072(this,(void *)piVar1[10]);
            if (-1 < local_38) {
              local_38 = (**(code **)*this)(this,&DAT_10013d84,param_3);
            }
          }
          (**(code **)(*this + 8))(this);
        }
      }
      local_8 = local_8 & 0xffffff00;
      FID_conflict__Tidy(local_34,'\x01',0);
    }
  }
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000c8d2 at 1000c8d2

undefined * Catch_1000c8d2(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x40);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x38));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x3c) + 0x84);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CMessageRouterImpl::GetPublisherEventsEnumEnumerating through a published event list\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (*(int **)(unaff_EBP + -0x38) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x38));
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013700,pWVar4,0,0,&DAT_10015920,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c940;
}



// Function: Catch@1000c942 at 1000c942

undefined4 Catch_1000c942(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000c8c7;
}



// Function: FUN_1000c953 at 1000c953

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000c953(int param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  undefined4 local_20 [2];
  undefined4 local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_18 = 0x80004005;
  local_8 = 0;
  FUN_1000e79b(local_20,(int *)(param_1 + 0x44));
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  *(undefined4 *)(param_1 + 0x298) = param_3;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 0x294) = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 0x290) = pvVar1;
  if ((*(int *)(param_1 + 0x294) != 0) && (pvVar1 != (HANDLE)0x0)) {
    local_18 = 0;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000e7b6(local_20);
  return local_18;
}



// Function: Catch@1000c9d9 at 1000c9d9

undefined4 Catch_1000c9d9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000c9ce;
}



// Function: FUN_1000c9ea at 1000c9ea

undefined4 FUN_1000c9ea(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x8c);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ca0c at 1000ca0c

undefined4 FUN_1000ca0c(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = param_1 + 0x74;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_1000ca2b at 1000ca2b

undefined1 * __thiscall FUN_1000ca2b(void *this,int *param_1)

{
  *(int **)((int)this + 4) = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  *(undefined1 *)this = 0;
  return (undefined1 *)this;
}



// Function: FUN_1000ca47 at 1000ca47

void __fastcall FUN_1000ca47(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 8))(*(int **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



// Function: FUN_1000ca59 at 1000ca59

void __fastcall FUN_1000ca59(undefined1 *param_1)

{
  *param_1 = 0;
  return;
}



// Function: FUN_1000ca5d at 1000ca5d

void __fastcall FUN_1000ca5d(undefined1 *param_1)

{
  *param_1 = 1;
  return;
}



// Function: FUN_1000ca61 at 1000ca61

undefined1 __fastcall FUN_1000ca61(undefined1 *param_1)

{
  return *param_1;
}



// Function: FUN_1000ca64 at 1000ca64

undefined4 __fastcall FUN_1000ca64(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000ca68 at 1000ca68

undefined4 * __thiscall FUN_1000ca68(void *this,int *param_1,undefined4 *param_2)

{
  longlong lVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)((int)this + 0x60) = 0;
  memset(this,0,0x30);
  memset((void *)((int)this + 0x40),0,0x20);
  Ordinal_8((int)this + 0x30);
  if ((param_1 != (int *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *(int **)this = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    *(undefined4 *)((int)this + 4) = *param_2;
    *(undefined **)((int)this + 8) = (undefined *)0x0;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x14) = 0;
    *(undefined4 *)((int)this + 0x18) = param_2[5];
    *(undefined2 *)((int)this + 0x1c) = *(undefined2 *)(param_2 + 6);
    *(int *)((int)this + 0x24) = (int)this + 0x30;
    *(int *)((int)this + 0x28) = (int)this + 0x40;
    *(int *)((int)this + 0x2c) = (int)this + 0x60;
    pvVar2 = operator_new(0x10);
    *(void **)((int)this + 0x20) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 8) = *(undefined4 *)(param_2[7] + 8);
      lVar1 = (ulonglong)*(uint *)(param_2[7] + 8) * 0x10;
      uVar3 = FUN_1000f311(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
      **(undefined4 **)((int)this + 0x20) = uVar3;
      iVar5 = 0;
      if (**(int **)((int)this + 0x20) != 0) {
        param_1 = (int *)0x0;
        if (*(int *)(param_2[7] + 8) != 0) {
          do {
            Ordinal_8(**(int **)((int)this + 0x20) + iVar5);
            Ordinal_10(**(int **)((int)this + 0x20) + iVar5,*(int *)param_2[7] + iVar5);
            param_1 = (int *)((int)param_1 + 1);
            iVar5 = iVar5 + 0x10;
          } while (param_1 != *(int **)(param_2[7] + 8));
        }
        *(undefined4 *)(*(int *)((int)this + 0x20) + 0xc) = *(undefined4 *)(param_2[7] + 0xc);
        lVar1 = (ulonglong)*(uint *)(param_2[7] + 0xc) * 4;
        uVar3 = FUN_1000f311(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
        *(undefined4 *)(*(int *)((int)this + 0x20) + 4) = uVar3;
        iVar5 = 0;
        if ((*(int *)(*(int *)((int)this + 0x20) + 4) != 0) &&
           (iVar4 = param_2[7], *(int *)(iVar4 + 0xc) != 0)) {
          do {
            *(undefined4 *)(*(int *)(*(int *)((int)this + 0x20) + 4) + iVar5 * 4) =
                 *(undefined4 *)(*(int *)(iVar4 + 4) + iVar5 * 4);
            iVar4 = param_2[7];
            iVar5 = iVar5 + 1;
          } while (iVar5 != *(int *)(iVar4 + 0xc));
        }
      }
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1000cbd4 at 1000cbd4

void __fastcall FUN_1000cbd4(int *param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if ((param_1[8] != 0) && (pvVar1 = *(void **)(param_1[8] + 4), pvVar1 != (void *)0x0)) {
    operator_delete__(pvVar1);
    *(undefined4 *)(param_1[8] + 4) = 0;
  }
  piVar2 = (int *)param_1[8];
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    if (piVar2[2] != 0) {
      iVar3 = 0;
      do {
        Ordinal_9(*(int *)param_1[8] + iVar3);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0x10;
      } while (uVar4 < *(uint *)(param_1[8] + 8));
    }
    operator_delete__(*(void **)param_1[8]);
    *(undefined4 *)param_1[8] = 0;
  }
  if ((void *)param_1[8] != (void *)0x0) {
    operator_delete((void *)param_1[8]);
    param_1[8] = 0;
  }
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  Ordinal_9(param_1 + 0xc);
  return;
}



// Function: FUN_1000cc5f at 1000cc5f

undefined4 __fastcall FUN_1000cc5f(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000cc62 at 1000cc62

void __fastcall FUN_1000cc62(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x69) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x69) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x69) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x69) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x69) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: FUN_1000cca8 at 1000cca8

void * __cdecl FUN_1000cca8(void *param_1,int param_2,void *param_3)

{
  void *pvVar1;
  size_t _Size;
  
  _Size = (param_2 - (int)param_1 >> 2) * 4;
  pvVar1 = memmove(param_3,param_1,_Size);
  return (void *)((int)pvVar1 + _Size);
}



// Function: FUN_1000cccd at 1000cccd

void __cdecl FUN_1000cccd(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      *param_1 = *param_3;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}



// Function: FUN_1000ccee at 1000ccee

undefined4 * __thiscall FUN_1000ccee(void *this,int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x69) == '\0') {
    bVar2 = FUN_1000e315(puVar3 + 3,param_1);
    if (bVar2) {
      puVar1 = (undefined4 *)puVar3[2];
    }
    else {
      puVar1 = (undefined4 *)*puVar3;
      puVar4 = puVar3;
    }
  }
  return puVar4;
}



// Function: FUN_1000cd23 at 1000cd23

int __fastcall FUN_1000cd23(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((int *)*param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)*param_1;
  }
  uVar1 = (uint)param_1[2] >> 2;
  if (*(uint *)(iVar2 + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)(iVar2 + 8);
  }
  return *(int *)(*(int *)(iVar2 + 4) + uVar1 * 4) + (param_1[2] & 3U) * 4;
}



// Function: FUN_1000cd4f at 1000cd4f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000cd4f(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000cd5b;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10018c00);
}



// Function: FUN_1000cdb0 at 1000cdb0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000cdb0(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000cdbc;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x25ed098) &&
     (pvVar1 = operator_new((int)param_1 * 0x6c), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10018c00);
}



// Function: FUN_1000ce0f at 1000ce0f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000ce0f(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000ce1b;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x20000000) &&
     (pvVar1 = operator_new((int)param_1 << 3), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10018c00);
}



// Function: FUN_1000ce70 at 1000ce70

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000ce70(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
  }
  return;
}



// Function: FUN_1000cea3 at 1000cea3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_1000cea3(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
  }
  return;
}



// Function: _String_const_iterator<> at 1000ced1

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_String_const_iterator<char,struct std::char_traits<char>,class
   std::allocator<char> >::_String_const_iterator<char,struct std::char_traits<char>,class
   std::allocator<char> >(char const *,struct std::_Container_base12 const *)
    public: __thiscall std::_String_const_iterator<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_String_const_iterator<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(unsigned short const
   *,struct std::_Container_base12 const *)
    public: __thiscall std::_String_const_iterator<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::_String_const_iterator<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(wchar_t const *,struct std::_Container_base12 const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall _String_const_iterator<>(void *this,undefined4 param_1,undefined4 *param_2)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)this = *param_2;
  }
  *(undefined4 *)((int)this + 8) = param_1;
  return;
}



// Function: FUN_1000cef2 at 1000cef2

void __cdecl FUN_1000cef2(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000ce70(param_2,param_3);
  return;
}



// Function: FUN_1000cf05 at 1000cf05

void __fastcall FUN_1000cf05(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000cdb0((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0x1a) = 0;
  return;
}



// Function: FUN_1000cf2c at 1000cf2c

void __fastcall FUN_1000cf2c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    if ((uint)(*(int *)(param_1 + 8) << 2) <= *(uint *)(param_1 + 0xc)) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x10) + -1;
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return;
}



// Function: FUN_1000cf52 at 1000cf52

void __thiscall FUN_1000cf52(void *this,uint param_1)

{
  void *pvVar1;
  uint extraout_EAX;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int extraout_EDX;
  int iVar6;
  void **ppvVar7;
  void *local_10;
  void *local_c;
  undefined4 *local_8;
  
  uVar2 = *(uint *)((int)this + 8);
  iVar5 = 0xfffffff;
  if (0xfffffff - uVar2 < param_1) {
    std::_Xlength_error("deque<T> too long");
    uVar2 = extraout_EAX;
    iVar5 = extraout_EDX;
  }
  uVar4 = uVar2 >> 1;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  if ((param_1 < uVar4) && (uVar2 <= iVar5 - uVar4)) {
    param_1 = uVar4;
  }
  uVar4 = *(uint *)((int)this + 0xc) >> 2;
  local_8 = (undefined4 *)FUN_1000cd4f((char *)(uVar2 + param_1));
  iVar5 = uVar4 * 4;
  local_c = (void *)(*(int *)((int)this + 4) + iVar5);
  local_10 = FUN_1000cca8(local_c,*(int *)((int)this + 4) + *(int *)((int)this + 8) * 4,
                          local_8 + uVar4);
  pvVar1 = *(void **)((int)this + 4);
  if (param_1 < uVar4) {
    FUN_1000cca8(pvVar1,(int)(param_1 * 4 + (int)pvVar1),local_10);
    local_10 = (void *)0x0;
    ppvVar7 = &local_10;
    uVar2 = param_1;
    puVar3 = (undefined4 *)
             FUN_1000cca8((void *)(param_1 * 4 + *(int *)((int)this + 4)),
                          iVar5 + *(int *)((int)this + 4),local_8);
    FUN_1000cccd(puVar3,uVar2,ppvVar7);
  }
  else {
    local_c = (void *)0x0;
    ppvVar7 = &local_c;
    iVar6 = param_1 - uVar4;
    puVar3 = (undefined4 *)FUN_1000cca8(pvVar1,(int)(iVar5 + (int)pvVar1),local_10);
    FUN_1000cccd(puVar3,iVar6,ppvVar7);
    local_10 = (void *)0x0;
    FUN_1000cccd(local_8,uVar4,&local_10);
  }
  if (*(void **)((int)this + 4) != (void *)0x0) {
    operator_delete(*(void **)((int)this + 4));
  }
  *(undefined4 **)((int)this + 4) = local_8;
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + param_1;
  return;
}



// Function: FUN_1000d084 at 1000d084

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

_Container_base12 * __fastcall FUN_1000d084(_Container_base12 *param_1)

{
  undefined4 *puVar1;
  undefined4 local_20;
  undefined4 local_1c;
  _Container_base12 *local_18;
  undefined1 local_11 [9];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x1000d090;
  local_18 = param_1;
  std::_Container_base12::_Container_base12(param_1);
  local_8 = 0;
  puVar1 = (undefined4 *)FUN_1000ce0f((char *)0x1);
  *(undefined4 **)param_1 = puVar1;
  local_20 = 0;
  local_1c = 0;
  FUN_1000cef2(local_11,puVar1,&local_20);
  **(undefined4 **)param_1 = param_1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return param_1;
}



// Function: FUN_1000d0df at 1000d0df

int __fastcall FUN_1000d0df(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_1000cdb0((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x68) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x69) = 1;
  return param_1;
}



// Function: FUN_1000d116 at 1000d116

void __cdecl FUN_1000d116(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_1000cea3(param_2,param_3);
  return;
}



// Function: FUN_1000d128 at 1000d128

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

_Container_base12 * __fastcall FUN_1000d128(_Container_base12 *param_1)

{
  _Container_base12 *ap_Stack_2c [5];
  undefined1 *local_18;
  _Container_base12 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x1000d134;
  local_18 = (undefined1 *)ap_Stack_2c;
  ap_Stack_2c[0] = param_1;
  local_14 = param_1;
  FUN_1000d084(param_1);
  return local_14;
}



// Function: FUN_1000d150 at 1000d150

void __thiscall FUN_1000d150(void *this,undefined4 *param_1)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  
  std::_Container_base12::_Orphan_all((_Container_base12 *)this);
  if (((*(int *)((int)this + 0xc) + *(int *)((int)this + 0x10) & 3U) == 0) &&
     (*(uint *)((int)this + 8) <= *(int *)((int)this + 0x10) + 4U >> 2)) {
    FUN_1000cf52(this,1);
  }
  uVar3 = *(int *)((int)this + 0xc) + *(int *)((int)this + 0x10);
  uVar1 = uVar3 >> 2;
  if (*(uint *)((int)this + 8) <= uVar1) {
    uVar1 = uVar1 - *(uint *)((int)this + 8);
  }
  if (*(int *)(*(int *)((int)this + 4) + uVar1 * 4) == 0) {
    pvVar2 = FUN_1000cd4f((char *)0x4);
    *(void **)(*(int *)((int)this + 4) + uVar1 * 4) = pvVar2;
  }
  FUN_1000d116((int)this + 0x14,
               (undefined4 *)(*(int *)(*(int *)((int)this + 4) + uVar1 * 4) + (uVar3 & 3) * 4),
               param_1);
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  return;
}



// Function: FUN_1000d1d5 at 1000d1d5

void * __thiscall FUN_1000d1d5(void *this,void *param_1)

{
  _String_const_iterator<>(param_1,*(undefined4 *)((int)this + 0xc),(undefined4 *)this);
  return param_1;
}



// Function: FUN_1000d1eb at 1000d1eb

void __thiscall FUN_1000d1eb(void *this,uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if ((uVar1 <= param_1) && (*(uint *)((int)this + 0x14) != param_1)) {
    bVar2 = FUN_10001a60(this,param_1,'\x01');
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



// Function: FUN_1000d224 at 1000d224

void __thiscall
FUN_1000d224(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x2c85909 < uVar3) {
    this = (void *)((int)this + 0xd);
    FUN_10005bc8(this,param_4 + 3);
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
    if (*(char *)(iVar4 + 0x68) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x68) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x68) == '\0') {
LAB_1000d2f3:
        *(undefined1 *)(piVar1 + 0x1a) = 1;
        *(undefined1 *)(iVar4 + 0x68) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x68) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10003199(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x68) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x68) = 0;
        FUN_10002a8d(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x68) == '\0') goto LAB_1000d2f3;
      if (piVar5 == (int *)*piVar1) {
        FUN_10002a8d(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x68) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x68) = 0;
      FUN_10003199(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_1000d35c at 1000d35c

undefined4 * __thiscall FUN_1000d35c(void *this,undefined4 *param_1,uint param_2)

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
      bVar1 = FUN_10001a60(this,uVar2,'\0');
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
    this = FUN_1000e332(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000d3fe at 1000d3fe

void __thiscall FUN_1000d3fe(void *this,undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 **ppuVar2;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)this;
  local_8 = FUN_1000ccee(this,(int)param_2);
  if (local_8 != *(undefined4 **)((int)this + 4)) {
    bVar1 = FUN_1000e315(param_2,(int)(local_8 + 3));
    if (!bVar1) {
      ppuVar2 = &local_8;
      goto LAB_1000d433;
    }
  }
  ppuVar2 = &param_2;
LAB_1000d433:
  *param_1 = *ppuVar2;
  return;
}



// Function: FUN_1000d43f at 1000d43f

void __thiscall FUN_1000d43f(void *this,int *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  char local_c;
  undefined4 *local_8;
  
  piVar2 = param_2 + 3;
  local_c = '\x01';
  puVar3 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  local_8 = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)puVar3 + 0x69) == '\0') {
    if ((char)param_3 == '\0') {
      local_c = FUN_1000e315(piVar2,(int)(puVar3 + 3));
    }
    else {
      bVar1 = FUN_1000e315(puVar3 + 3,(int)piVar2);
      local_c = '\x01' - bVar1;
    }
    local_8 = puVar3;
    if (local_c == '\0') {
      puVar3 = (undefined4 *)puVar3[2];
    }
    else {
      puVar3 = (undefined4 *)*puVar3;
    }
  }
  param_3 = local_8;
  if (local_c != '\0') {
    if (local_8 == (undefined4 *)**(int **)((int)this + 4)) {
      local_c = '\x01';
      goto LAB_1000d4af;
    }
    FUN_1000cc62((int *)&param_3);
  }
  puVar3 = param_3;
  bVar1 = FUN_1000e315(param_3 + 3,(int)piVar2);
  if (!bVar1) {
    FUN_10005bc8((int)this + 0xd,piVar2);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_1000d4af:
  piVar2 = (int *)FUN_1000d224(this,&param_3,local_c,local_8,param_2);
  *param_1 = *piVar2;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_1000d50f at 1000d50f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000d50f(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  void *pvVar1;
  int iVar2;
  undefined4 local_84 [2];
  int local_7c;
  int *local_78;
  undefined4 local_74;
  undefined4 local_70 [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_7c = param_1;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar2 = Ordinal_7(param_2);
    if ((iVar2 != 0) && (param_3 != (wchar_t *)0x0)) {
      iVar2 = Ordinal_7(param_3);
      if (iVar2 != 0) {
        FUN_1000e684(local_70,param_2,param_3);
        local_8._0_1_ = 1;
        FUN_1000e79b(local_84,(int *)(param_1 + 0x3c));
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000d3fe((void *)(param_1 + 0x74),&local_78,local_70);
        if (local_78 == *(int **)(param_1 + 0x78)) {
          local_74 = 0x80070057;
        }
        else {
          pvVar1 = (void *)local_78[0x19];
          if (pvVar1 != (void *)0x0) {
            FUN_1000ca47((int)pvVar1);
            operator_delete(pvVar1);
          }
          FUN_10005c38((void *)(param_1 + 0x74),&local_78,local_78);
          local_74 = 0;
        }
        local_8._0_1_ = 1;
        FUN_1000e7b6(local_84);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1000e50c(local_70);
        goto LAB_1000d5e2;
      }
    }
  }
  local_74 = 0x80070057;
LAB_1000d5e2:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000d5f1 at 1000d5f1

undefined * Catch_1000d5f1(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x84);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x74));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x78) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CSubscriberImpl::RemoveEvent\nRemoving an event from the subscriber\'s event map\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (*(int **)(unaff_EBP + -0x74) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x74));
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013720,pWVar4,0,0,&DAT_100136c0,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d662;
}



// Function: Catch@1000d664 at 1000d664

undefined4 Catch_1000d664(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x70) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000d5e6;
}



// Function: FUN_1000d675 at 1000d675

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000d675(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_28 [3];
  undefined4 local_1c;
  int local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0;
  FUN_1000e79b(local_28,param_1 + 0xf);
  local_8._0_1_ = 1;
  while (piVar1 = *(int **)param_1[0x1e], piVar1 != (int *)param_1[0x1e]) {
    FUN_1000e7cc(local_28);
    iVar2 = *param_1;
    uVar3 = FUN_1000e30d((int)(piVar1 + 3));
    uVar4 = FUN_1000e305((int)(piVar1 + 3));
    local_18 = (**(code **)(iVar2 + 0x20))(param_1,uVar4,uVar3);
    if (-1 < local_18) {
      FUN_1000e7de(local_28);
      FUN_10005c38(param_1 + 0x1d,&local_1c,piVar1);
      FUN_1000e7cc(local_28);
    }
    FUN_1000e7de(local_28);
  }
  local_18 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000e7b6(local_28);
  return local_18;
}



// Function: Catch@1000d70e at 1000d70e

undefined * Catch_1000d70e(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x1c);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + 8) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CSubscriberImpl::RemoveAllEvents\nRemoving all events from the subscriber\'s event map\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (*(int **)(unaff_EBP + -0x18) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x18));
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013720,pWVar4,0,0,&DAT_100136c0,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d77c;
}



// Function: Catch@1000d77e at 1000d77e

undefined4 Catch_1000d77e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000d703;
}



// Function: FUN_1000d78f at 1000d78f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000d78f(int param_1,wchar_t *param_2,wchar_t *param_3,undefined4 *param_4)

{
  char cVar1;
  LPUNKNOWN pUnk;
  void *this;
  int extraout_ECX;
  LPSTREAM *ppStm;
  undefined4 local_8c [3];
  LPSTREAM local_80;
  int local_7c;
  undefined4 *local_78;
  HRESULT local_74;
  undefined4 local_70 [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_7c = param_1;
  local_74 = 0x80004005;
  local_8 = 0;
  if ((param_2 == (wchar_t *)0x0) || (param_3 == (wchar_t *)0x0)) {
    local_74 = 0x80070057;
  }
  else {
    FUN_1000e684(local_70,param_2,param_3);
    local_8._0_1_ = 1;
    FUN_1000e79b(local_8c,(int *)(param_1 + 0x3c));
    local_8._0_1_ = 2;
    FUN_1000d3fe((void *)(param_1 + 0x74),&local_78,local_70);
    if (local_78 == *(undefined4 **)(param_1 + 0x78)) {
      local_74 = 0x80070057;
    }
    else {
      cVar1 = FUN_1000ca61((undefined1 *)local_78[0x19]);
      if (cVar1 == '\0') {
        ppStm = &local_80;
        pUnk = (LPUNKNOWN)FUN_1000ca64(extraout_ECX);
        local_74 = CoMarshalInterThreadInterfaceInStream((IID *)&DAT_10013d84,pUnk,ppStm);
        local_78 = (undefined4 *)0x0;
        this = operator_new(0x68);
        local_8._0_1_ = 3;
        if (this == (void *)0x0) {
          local_78 = (undefined4 *)0x0;
        }
        else {
          local_78 = FUN_1000ca68(this,(int *)local_80,param_4);
        }
        local_8._0_1_ = 2;
        if (local_78 == (undefined4 *)0x0) {
          local_74 = 0x8007000e;
        }
        else {
          FUN_1000d150((void *)(param_1 + 0x24),&local_78);
          SetEvent(*(HANDLE *)(param_1 + 0x28c));
          local_74 = 0;
        }
      }
    }
    local_8._0_1_ = 1;
    FUN_1000e7b6(local_8c);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1000e50c(local_70);
  }
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000d8b4 at 1000d8b4

undefined * Catch_1000d8b4(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x80);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x74));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x78) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CSubscriberImpl::PushEvent\nPushing a Message structure onto the message queue\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (*(int **)(unaff_EBP + -0x74) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x74));
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013720,pWVar4,0,0,&DAT_100136c0,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000d922;
}



// Function: Catch@1000d924 at 1000d924

undefined4 Catch_1000d924(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x70) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000d8a9;
}



// Function: FUN_1000d935 at 1000d935

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000d935(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  undefined4 local_84 [2];
  int local_7c;
  int local_78 [28];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_7c = param_1;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar1 = Ordinal_7(param_2);
    if ((iVar1 != 0) && (param_3 != (wchar_t *)0x0)) {
      iVar1 = Ordinal_7(param_3);
      if (iVar1 != 0) {
        FUN_1000e684(local_78 + 2,param_2,param_3);
        local_8._0_1_ = 1;
        FUN_1000e79b(local_84,(int *)(param_1 + 0x3c));
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000d3fe((void *)(param_1 + 0x74),local_78,local_78 + 2);
        if (local_78[0] == *(int *)(param_1 + 0x78)) {
          local_78[1] = 0x80070057;
        }
        else {
          FUN_1000ca5d(*(undefined1 **)(local_78[0] + 100));
          local_78[1] = 0;
        }
        local_8._0_1_ = 1;
        FUN_1000e7b6(local_84);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1000e50c(local_78 + 2);
        goto LAB_1000d9e1;
      }
    }
  }
  local_78[1] = 0x80070057;
LAB_1000d9e1:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000d9f0 at 1000d9f0

undefined * Catch_1000d9f0(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x84);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x74));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x78) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CSubscriberImpl::RemoveEvent\nRemoving an event from the subscriber\'s event map\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (*(int **)(unaff_EBP + -0x74) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x74));
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013720,pWVar4,0,0,&DAT_100136c0,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000da61;
}



// Function: Catch@1000da63 at 1000da63

undefined4 Catch_1000da63(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x70) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000d9e5;
}



// Function: FUN_1000da74 at 1000da74

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000da74(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  undefined4 local_84 [2];
  int local_7c;
  int local_78 [28];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_7c = param_1;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar1 = Ordinal_7(param_2);
    if ((iVar1 != 0) && (param_3 != (wchar_t *)0x0)) {
      iVar1 = Ordinal_7(param_3);
      if (iVar1 != 0) {
        FUN_1000e684(local_78 + 2,param_2,param_3);
        local_8._0_1_ = 1;
        FUN_1000e79b(local_84,(int *)(param_1 + 0x3c));
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_1000d3fe((void *)(param_1 + 0x74),local_78,local_78 + 2);
        if (local_78[0] == *(int *)(param_1 + 0x78)) {
          local_78[1] = 0x80070057;
        }
        else {
          FUN_1000ca59(*(undefined1 **)(local_78[0] + 100));
          local_78[1] = 0;
        }
        local_8._0_1_ = 1;
        FUN_1000e7b6(local_84);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1000e50c(local_78 + 2);
        goto LAB_1000db20;
      }
    }
  }
  local_78[1] = 0x80070057;
LAB_1000db20:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000db2f at 1000db2f

undefined * Catch_1000db2f(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x84);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x74));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x78) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CSubscriberImpl::RemoveEvent\nRemoving an event from the subscriber\'s event map\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (*(int **)(unaff_EBP + -0x74) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x74));
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013720,pWVar4,0,0,&DAT_100136c0,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000dba0;
}



// Function: Catch@1000dba2 at 1000dba2

undefined4 Catch_1000dba2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x70) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000db24;
}



// Function: FUN_1000dbb3 at 1000dbb3

void __fastcall FUN_1000dbb3(void *param_1)

{
  int *piVar1;
  undefined1 local_10 [12];
  
  piVar1 = (int *)FUN_1000d1d5(param_1,local_10);
  FUN_1000cd23(piVar1);
  return;
}



// Function: FUN_1000dbcb at 1000dbcb

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_1000dbcb(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  undefined4 *puVar4;
  char cVar5;
  int *piVar6;
  void *local_c;
  void *pvStack_8;
  
  piVar2 = param_4;
  piVar6 = param_4 + 3;
  local_c = param_1;
  pvStack_8 = param_1;
  if (*(int *)((int)param_1 + 8) == 0) {
    piVar6 = *(int **)((int)param_1 + 4);
  }
  else {
    piVar1 = *(int **)((int)param_1 + 4);
    if (param_3 == (int *)*piVar1) {
      bVar3 = FUN_1000e315(piVar6,(int)(param_3 + 3));
      if (!bVar3) goto LAB_1000dcdb;
      cVar5 = '\x01';
      goto LAB_1000dbe7;
    }
    if (param_3 == piVar1) {
      bVar3 = FUN_1000e315((void *)(piVar1[2] + 0xc),(int)piVar6);
      if (!bVar3) goto LAB_1000dcdb;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_1000dbe7;
    }
    bVar3 = FUN_1000e315(piVar6,(int)(param_3 + 3));
    if (bVar3) {
      param_4 = param_3;
      FUN_1000cc62((int *)&param_4);
      piVar1 = param_4;
      bVar3 = FUN_1000e315(param_4 + 3,(int)piVar6);
      if (!bVar3) goto LAB_1000dc8a;
      cVar5 = *(char *)(piVar1[2] + 0x69);
      piVar6 = param_3;
    }
    else {
LAB_1000dc8a:
      bVar3 = FUN_1000e315(param_3 + 3,(int)(piVar2 + 3));
      if (!bVar3) {
LAB_1000dcdb:
        puVar4 = (undefined4 *)FUN_1000d43f(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_10002f1d((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (bVar3 = FUN_1000e315(piVar2 + 3,(int)(param_4 + 3)), !bVar3)) goto LAB_1000dcdb;
      cVar5 = *(char *)(param_3[2] + 0x69);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_1000dbe7;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_1000dbe7:
  FUN_1000d224(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_1000dcf7 at 1000dcf7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_1000dcf7(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 local_2c [4];
  int local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0;
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x290),0xffffffff);
  local_1c = 0;
  local_18[0] = (int *)0x0;
  local_8._0_1_ = 1;
  FUN_1000e79b(local_2c,(int *)(param_1 + 0x40));
  local_8._0_1_ = 2;
  if (*(int *)(param_1 + 0x38) != 0) {
    piVar2 = (int *)FUN_1000dbb3((void *)(param_1 + 0x28));
    iVar1 = *piVar2;
    local_1c = iVar1;
    FUN_1000cf2c(param_1 + 0x28);
    FUN_1000e7cc(local_2c);
    if (iVar1 != 0) {
      puVar3 = (undefined4 *)FUN_1000cc5f(iVar1);
      if (puVar3 != (undefined4 *)0x0) {
        CoGetInterfaceAndReleaseStream((LPSTREAM)*puVar3,(IID *)&DAT_10013d84,local_18);
        if (local_18[0] != (int *)0x0) {
          (**(code **)(*local_18[0] + 0x18))
                    (local_18[0],puVar3[1],puVar3 + 2,puVar3[6],*(undefined2 *)(puVar3 + 7),
                     puVar3[8],puVar3[9],puVar3[10],puVar3[0xb]);
          (**(code **)(*local_18[0] + 8))(local_18[0]);
          local_18[0] = (int *)0x0;
        }
      }
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000e7b6(local_2c);
  local_8 = 0;
  FUN_1000de3d();
  return;
}



// Function: Catch@1000ddbf at 1000ddbf

undefined * Catch_1000ddbf(void)

{
  int *piVar1;
  void *this;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  LPWSTR pWVar5;
  int unaff_EBP;
  undefined4 uVar6;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  this = *(void **)(unaff_EBP + -0x20);
  uVar2 = *(undefined4 *)((int)this + 4);
  puVar3 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x1c));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  pWVar5 = (LPWSTR)(*(int *)(unaff_EBP + 8) + 0x8c);
  uVar6 = *puVar3;
  uVar4 = FUN_100014a5((int)this);
  wsprintfW(pWVar5,
            L"CSubscriberImpl::ExecFunc\nExecuting a function\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar2,uVar4,uVar6);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (*(int **)(unaff_EBP + -0x1c) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013720,pWVar5,0,0,&DAT_100136c0,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000de3a;
}



// Function: FUN_1000de3d at 1000de3d

void FUN_1000de3d(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  int unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_1000cbd4(*(int **)(unaff_EBP + -0x18));
    operator_delete(*(void **)(unaff_EBP + -0x18));
  }
  if (*(int *)(unaff_EDI + 0x38) == 0) {
    ResetEvent(*(HANDLE *)(unaff_EDI + 0x290));
  }
  WaitForSingleObject(*(HANDLE *)(unaff_EDI + 0x290),0xffffffff);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_1000e79b((void *)(unaff_EBP + -0x28),(int *)(unaff_EDI + 0x40));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (*(int *)(unaff_EDI + 0x38) != 0) {
    piVar2 = (int *)FUN_1000dbb3((void *)(unaff_EDI + 0x28));
    iVar1 = *piVar2;
    *(int *)(unaff_EBP + -0x18) = iVar1;
    FUN_1000cf2c(unaff_EDI + 0x28);
    FUN_1000e7cc((undefined4 *)(unaff_EBP + -0x28));
    if (iVar1 != 0) {
      puVar3 = (undefined4 *)FUN_1000cc5f(iVar1);
      if (puVar3 != (undefined4 *)0x0) {
        CoGetInterfaceAndReleaseStream
                  ((LPSTREAM)*puVar3,(IID *)&DAT_10013d84,(LPVOID *)(unaff_EBP + -0x14));
        piVar2 = *(int **)(unaff_EBP + -0x14);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x18))
                    (piVar2,puVar3[1],puVar3 + 2,puVar3[6],*(undefined2 *)(puVar3 + 7),puVar3[8],
                     puVar3[9],puVar3[10],puVar3[0xb]);
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
        }
      }
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x28));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_1000de3d();
  return;
}



// Function: Catch@1000de6f at 1000de6f

undefined * Catch_1000de6f(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000de3a;
}



// Function: Catch@1000de8a at 1000de8a

undefined1 * Catch_1000de8a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000de94;
}



// Function: FUN_1000dea1 at 1000dea1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __cdecl FUN_1000dea1(undefined2 *param_1,wchar_t *param_2,undefined4 *param_3)

{
  size_t sVar1;
  
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  sVar1 = wcslen(param_2);
  FUN_1000d1eb(param_1,param_3[4] + sVar1);
  sVar1 = wcslen(param_2);
  FUN_1000d35c(param_1,(undefined4 *)param_2,sVar1);
  FUN_1000e332(param_1,param_3,0,0xffffffff);
  return param_1;
}



// Function: FUN_1000df13 at 1000df13

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000df13(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000df1f;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_1000d0df(param_1);
  return local_18;
}



// Function: FUN_1000df3f at 1000df3f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000df3f(void *this,int param_1,undefined4 *param_2)

{
  FUN_1000b2b4(this,param_1);
  *(undefined4 *)((int)this + 0x58) = *param_2;
  return this;
}



// Function: FUN_1000df72 at 1000df72

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000df72(int param_1)

{
  wchar_t *pwVar1;
  long lVar2;
  size_t sVar3;
  undefined2 auStack_148 [2];
  undefined4 uStack_144;
  wchar_t local_114 [134];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10c;
  local_8 = 0x1000df81;
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_10001318((void *)(param_1 + 0x10));
  local_8 = 1;
  FUN_1000d128((_Container_base12 *)(param_1 + 0x2c));
  local_8._0_1_ = 3;
  FUN_1000dea1(auStack_148,L"SubscriberMap#",&DAT_10020b6c);
  local_8._0_1_ = 3;
  FUN_1000e862((undefined4 *)(param_1 + 0x44));
  local_8._0_1_ = 5;
  FUN_1000df13(param_1 + 0x7c);
  local_8 = CONCAT31(local_8._1_3_,6);
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x290) = 0;
  *(undefined4 *)(param_1 + 0x294) = 0;
  *(undefined4 *)(param_1 + 0x298) = 0;
  memset((void *)(param_1 + 0x90),0,0x1fe);
  pwVar1 = DAT_10020b6c;
  if (DAT_10020b80 < 8) {
    pwVar1 = (wchar_t *)&DAT_10020b6c;
  }
  lVar2 = _wtol(pwVar1);
  pwVar1 = _ltow(lVar2 + 1,local_114,10);
  uStack_144 = 0x1000e054;
  sVar3 = wcslen(pwVar1);
  FID_conflict_assign(&DAT_10020b6c,(undefined4 *)pwVar1,sVar3);
  local_8 = 0xffffffff;
  FUN_1000f487();
  return;
}



// Function: FUN_1000e06c at 1000e06c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000e06c(void *this,int param_1)

{
  FUN_1000df3f(this,param_1,(undefined4 *)(param_1 + 0x58));
  return this;
}



// Function: FUN_1000e09a at 1000e09a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_1000e09a(void *param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_10012246;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_1000e06c(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000e0c8 at 1000e0c8

void __cdecl FUN_1000e0c8(undefined4 param_1,void *param_2,int param_3)

{
  FUN_1000e09a(param_2,param_3);
  return;
}



// Function: FUN_1000e0db at 1000e0db

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000e0db(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000cf05((int)this);
  FUN_1000e0c8((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@1000e118 at 1000e118

void Catch_1000e118(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000e12b at 1000e12b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000e12b(void *this,void *param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 local_74;
  undefined4 local_70 [22];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x1000e137;
  piVar2 = FUN_1000ccee(this,(int)param_1);
  if (piVar2 != *(int **)((int)this + 4)) {
    bVar1 = FUN_1000e315(param_1,(int)(piVar2 + 3));
    if (!bVar1) goto LAB_1000e197;
  }
  FUN_1000b2b4(local_70,(int)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_1000e0db(this,(int)local_70);
  FUN_1000dbcb(this,&local_74,piVar2,piVar3);
  local_8 = 0xffffffff;
  FUN_1000e50c(local_70);
LAB_1000e197:
  FUN_1000f487();
  return;
}



// Function: FUN_1000e1a2 at 1000e1a2

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000e1a2(int param_1,wchar_t *param_2,wchar_t *param_3,int *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 local_88 [2];
  void *local_80;
  int local_7c;
  int *local_78;
  undefined4 local_74;
  undefined4 local_70 [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_7c = param_1;
  local_78 = param_4;
  local_8 = 0;
  if (param_2 != (wchar_t *)0x0) {
    iVar1 = Ordinal_7(param_2);
    if ((iVar1 != 0) && (param_3 != (wchar_t *)0x0)) {
      iVar1 = Ordinal_7(param_3);
      if ((iVar1 != 0) && (local_78 != (int *)0x0)) {
        FUN_1000e684(local_70,param_2,param_3);
        local_8._0_1_ = 1;
        local_80 = operator_new(8);
        local_8._0_1_ = 2;
        if (local_80 == (void *)0x0) {
          puVar2 = (undefined1 *)0x0;
        }
        else {
          puVar2 = FUN_1000ca2b(local_80,local_78);
        }
        local_8._0_1_ = 1;
        FUN_1000e79b(local_88,(int *)(param_1 + 0x3c));
        local_8._0_1_ = 3;
        puVar3 = (undefined4 *)FUN_1000e12b((void *)(param_1 + 0x74),local_70);
        *puVar3 = puVar2;
        local_74 = 0;
        local_8._0_1_ = 1;
        FUN_1000e7b6(local_88);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_1000e50c(local_70);
        goto LAB_1000e272;
      }
    }
  }
  local_74 = 0x80070057;
LAB_1000e272:
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000e281 at 1000e281

undefined * Catch_1000e281(void)

{
  void *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int unaff_EBP;
  undefined4 uVar5;
  
  this = *(void **)(unaff_EBP + -0x88);
  uVar1 = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar1;
  puVar2 = (undefined4 *)FUN_10001b9b(this,(void *)(unaff_EBP + -0x74));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  pWVar4 = (LPWSTR)(*(int *)(unaff_EBP + -0x78) + 0x88);
  uVar5 = *puVar2;
  uVar3 = FUN_100014a5((int)this);
  wsprintfW(pWVar4,
            L"CSubscriberImpl::AddEvent\nAdding an event to the subscriber\'s event map\nCode = %08lx\nError Message = %s\nDescription = %s\n"
            ,uVar1,uVar3,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (*(int **)(unaff_EBP + -0x74) != (int *)0x0) {
    FUN_10001a35(*(int **)(unaff_EBP + -0x74));
    *(undefined4 *)(unaff_EBP + -0x74) = 0;
  }
  FUN_100016ef((IID *)&DAT_10013720,pWVar4,0,0,&DAT_100136c0,0,(HINSTANCE)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e2f2;
}



// Function: Catch@1000e2f4 at 1000e2f4

undefined4 Catch_1000e2f4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x70) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000e276;
}



// Function: FUN_1000e305 at 1000e305

void __fastcall FUN_1000e305(int param_1)

{
  FUN_100018a3((undefined4 *)(param_1 + 0x20));
  return;
}



// Function: FUN_1000e30d at 1000e30d

void __fastcall FUN_1000e30d(int param_1)

{
  FUN_100018a3((undefined4 *)(param_1 + 0x3c));
  return;
}



// Function: FUN_1000e315 at 1000e315

bool __thiscall FUN_1000e315(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_100016ce((void *)((int)this + 4),(wchar_t *)(param_1 + 4));
  return iVar1 < 0;
}



// Function: FUN_1000e332 at 1000e332

undefined4 * __thiscall FUN_1000e332(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    bVar1 = FUN_10001a60(this,uVar2,'\0');
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



// Function: FUN_1000e3d7 at 1000e3d7

undefined4 * __thiscall
FUN_1000e3d7(void *this,uint param_1,undefined4 *param_2,uint param_3,uint param_4)

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
      bVar3 = FUN_10001a60(this,uVar8,'\0');
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



// Function: FUN_1000e50c at 1000e50c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e50c(undefined4 *param_1)

{
  *param_1 = CFCBstrDualId::vftable;
  FID_conflict__Tidy(param_1 + 0xf,'\x01',0);
  FID_conflict__Tidy(param_1 + 8,'\x01',0);
  FID_conflict__Tidy(param_1 + 1,'\x01',0);
  return;
}



// Function: FUN_1000e565 at 1000e565

undefined2 * __thiscall FUN_1000e565(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_1000e597 at 1000e597

undefined4 * __thiscall FUN_1000e597(void *this,undefined4 *param_1)

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



// Function: basic_string<> at 1000e5f4

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
  FUN_1000e597(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_1000e619 at 1000e619

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000e619(void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (((uint)(param_2[5] - param_2[4]) < (uint)param_3[4]) &&
     ((uint)param_2[4] <= (uint)(param_3[5] - param_3[4]))) {
    puVar1 = FUN_1000e3d7(param_3,0,param_2,0,0xffffffff);
    basic_string<>(param_1,puVar1);
  }
  else {
    puVar1 = FUN_1000e332(param_2,param_3,0,0xffffffff);
    basic_string<>(param_1,puVar1);
  }
  return param_1;
}



// Function: FUN_1000e684 at 1000e684

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000e684(void *this,wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_68 [28];
  undefined1 local_4c [28];
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  *(undefined ***)this = CFCBstrDualId::vftable;
  *(undefined4 *)((int)this + 0x18) = 7;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x34) = 7;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined2 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 7;
  *(undefined2 *)((int)this + 0x3c) = 0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 4;
  sVar1 = wcslen(param_1);
  FID_conflict_assign((void *)((int)this + 0x20),(undefined4 *)param_1,sVar1);
  sVar1 = wcslen(param_2);
  FID_conflict_assign((void *)((int)this + 0x3c),(undefined4 *)param_2,sVar1);
  puVar2 = (undefined4 *)FUN_1000e565(local_30,param_2);
  local_8._0_1_ = 5;
  puVar3 = (undefined4 *)FUN_1000e565(local_4c,param_1);
  local_8._0_1_ = 6;
  puVar2 = (undefined4 *)FUN_1000e619(local_68,puVar3,puVar2);
  local_8._0_1_ = 7;
  FUN_1000e597((void *)((int)this + 4),puVar2);
  local_8._0_1_ = 6;
  FID_conflict__Tidy(local_68,'\x01',0);
  local_8._0_1_ = 5;
  FID_conflict__Tidy(local_4c,'\x01',0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1000f487();
  return;
}



// Function: FUN_1000e785 at 1000e785

void __fastcall FUN_1000e785(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000e790 at 1000e790

void __fastcall FUN_1000e790(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1000e79b at 1000e79b

undefined4 * __thiscall FUN_1000e79b(void *this,int *param_1)

{
  *(int **)this = param_1;
  (**(code **)(*param_1 + 4))();
  *(undefined1 *)((int)this + 4) = 1;
  return (undefined4 *)this;
}



// Function: FUN_1000e7b6 at 1000e7b6

void __fastcall FUN_1000e7b6(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    (**(code **)(*(int *)*param_1 + 8))();
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000e7cc at 1000e7cc

void __fastcall FUN_1000e7cc(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
                    /* WARNING: Could not recover jumptable at 0x1000e7da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)*param_1 + 8))();
    return;
  }
  return;
}



// Function: FUN_1000e7de at 1000e7de

void __fastcall FUN_1000e7de(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) == '\0') {
    (**(code **)(*(int *)*param_1 + 4))();
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}



// Function: FUN_1000e7f4 at 1000e7f4

void __fastcall FUN_1000e7f4(undefined4 *param_1)

{
  *param_1 = CSyncObjectBase::vftable;
  return;
}



// Function: FUN_1000e7fb at 1000e7fb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000e7fb(undefined4 *param_1)

{
  *param_1 = CCriticalSection::vftable;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  FID_conflict__Tidy(param_1 + 7,'\x01',0);
  *param_1 = CSyncObjectBase::vftable;
  return;
}



// Function: FUN_1000e843 at 1000e843

undefined4 * __thiscall FUN_1000e843(void *this,byte param_1)

{
  FUN_1000e7fb((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000e862 at 1000e862

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000e862(undefined4 *param_1)

{
  *param_1 = CSyncObjectBase::vftable;
  *param_1 = CCriticalSection::vftable;
  param_1[0xb] = 0;
  param_1[0xc] = 7;
  *(undefined2 *)(param_1 + 7) = 0;
  FUN_10001aec(param_1 + 7,(undefined4 *)&stack0x00000004,0,0xffffffff);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  FID_conflict__Tidy(&stack0x00000004,'\x01',0);
  return param_1;
}



// Function: FUN_1000e8ce at 1000e8ce

undefined4 FUN_1000e8ce(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10020a28 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000e900 at 1000e900

void __cdecl FUN_1000e900(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_1000e90e at 1000e90e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000e90e(undefined4 *param_1)

{
  *param_1 = ATL::
             ICollectionOnSTLImpl<struct_IEnumPublisherEvents,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>,struct_tagVARIANT,class__CopyMapItemPubEvents,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemPubEvents,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  FUN_1000b84d((int)(param_1 + 1));
  return param_1;
}



// Function: FUN_1000e939 at 1000e939

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000e939(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_1000e90e((undefined4 *)(param_1 + 4));
  return param_1;
}



// Function: FUN_1000e965 at 1000e965

undefined4 FUN_1000e965(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10020a2c + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000e997 at 1000e997

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_1000e997(int param_1,short param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5,
            int param_6)

{
  undefined4 local_18;
  
  if (param_6 == 0) {
    local_18 = 0x80004003;
  }
  else {
    Ordinal_8(param_6);
    if (param_2 == 3) {
      local_18 = FUN_100087a1(param_1,param_4,param_6);
    }
    else {
      local_18 = 0x80070057;
    }
  }
  return local_18;
}



// Function: Catch@1000e9ef at 1000e9ef

undefined4 Catch_1000e9ef(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000e9e4;
}



// Function: FUN_1000ea00 at 1000ea00

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_1000ea00(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009d08((int)this);
  FUN_1000f008((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@1000ea3d at 1000ea3d

void Catch_1000ea3d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000ea50 at 1000ea50

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000ea50(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *local_18;
  
  local_18 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    puVar1 = (undefined4 *)FUN_1000ea00(this,param_1 + 3);
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 0xb) = *(undefined1 *)(param_1 + 0xb);
    if (*(char *)((int)local_18 + 0x2d) != '\0') {
      local_18 = puVar1;
    }
    puVar2 = FUN_1000ea50(this,(undefined4 *)*param_1,puVar1);
    *puVar1 = puVar2;
    puVar2 = FUN_1000ea50(this,(undefined4 *)param_1[2],puVar1);
    puVar1[2] = puVar2;
  }
  return local_18;
}



// Function: Catch@1000eac0 at 1000eac0

void Catch_1000eac0(void)

{
  int unaff_EBP;
  
  FUN_10001e04(*(void **)(unaff_EBP + -0x18),*(int **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000ead5 at 1000ead5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000ead5(undefined4 *param_1)

{
  *param_1 = ATL::
             ICollectionOnSTLImpl<struct_IEnumPublishers,class_std::map<class_CFCBstrId,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*>_>_>,struct_tagVARIANT,class__CopyMapItemPubId,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemPubId,class_std::map<class_CFCBstrId,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,class_std::map<class_CFCBstrId,struct_IEvent*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_IEvent*>_>_>*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  FUN_1000b84d((int)(param_1 + 1));
  return param_1;
}



// Function: FUN_1000eb00 at 1000eb00

void __thiscall FUN_1000eb00(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = *(int *)((int)this + 4);
  puVar4 = FUN_1000ea50(this,*(undefined4 **)(*(int *)(param_1 + 4) + 4),iVar1);
  *(undefined4 **)(iVar1 + 4) = puVar4;
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  piVar2 = *(int **)((int)this + 4);
  piVar3 = (int *)piVar2[1];
  if (*(char *)(piVar2[1] + 0x2d) == '\0') {
    do {
      piVar5 = piVar3;
      piVar3 = (int *)*piVar5;
    } while (*(char *)((int)piVar3 + 0x2d) == '\0');
    *piVar2 = (int)piVar5;
    iVar1 = *(int *)(*(int *)((int)this + 4) + 4);
    do {
      iVar6 = iVar1;
      iVar1 = *(int *)(iVar6 + 8);
    } while (*(char *)(iVar1 + 0x2d) == '\0');
    *(int *)(*(int *)((int)this + 4) + 8) = iVar6;
  }
  else {
    *piVar2 = (int)piVar2;
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
  }
  return;
}



// Function: FUN_1000eb61 at 1000eb61

void * __thiscall FUN_1000eb61(void *this,void *param_1)

{
  void *local_8;
  
  if (this != param_1) {
    local_8 = this;
    FUN_1000217b(this,&local_8,(int *)**(int **)((int)this + 4),*(int **)((int)this + 4));
    FUN_1000eb00(this,(int)param_1);
  }
  return this;
}



// Function: FUN_1000eb90 at 1000eb90

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000eb90(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_1000ead5((undefined4 *)(param_1 + 4));
  return param_1;
}



// Function: FUN_1000ebbc at 1000ebbc

undefined4 FUN_1000ebbc(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10020a30 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000ebee at 1000ebee

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_1000ebee(undefined2 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined4 local_74;
  undefined4 local_70 [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x70;
  local_8 = 0;
  if (param_2 == 0) {
    local_74 = 0x80004003;
  }
  else {
    FUN_1000b2b4(local_70,param_2);
    local_8._0_1_ = 1;
    Ordinal_8(param_1);
    *param_1 = 0x2008;
    local_80 = 2;
    local_7c = 0;
    uVar1 = Ordinal_15(8,1,&local_80);
    Ordinal_23(uVar1,&local_78);
    uVar2 = FUN_1000e305((int)local_70);
    *local_78 = uVar2;
    uVar2 = FUN_1000e30d((int)local_70);
    local_78[1] = uVar2;
    Ordinal_24(uVar1);
    *(undefined4 *)(param_1 + 4) = uVar1;
    local_74 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1000e50c(local_70);
  }
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000ec93 at 1000ec93

undefined4 Catch_1000ec93(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x70) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ec8a;
}



// Function: FUN_1000eca4 at 1000eca4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000eca4(undefined4 *param_1)

{
  *param_1 = ATL::
             ICollectionOnSTLImpl<struct_IEnumSubscriberEvents,class_std::map<class_CFCBstrDualId,class_CEventCallback*,struct_std::less<class_CFCBstrDualId>,class_std::allocator<struct_std::pair<class_CFCBstrDualId_const_,class_CEventCallback*>_>_>,struct_tagVARIANT,class__CopyMapItemSubscriberEvents,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemSubscriberEvents,class_std::map<class_CFCBstrDualId,class_CEventCallback*,struct_std::less<class_CFCBstrDualId>,class_std::allocator<struct_std::pair<class_CFCBstrDualId_const_,class_CEventCallback*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  FUN_1000df13((int)(param_1 + 1));
  return param_1;
}



// Function: FUN_1000eccf at 1000eccf

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_1000eccf(int param_1,short param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5,
            undefined2 *param_6)

{
  undefined4 local_18;
  
  if (param_6 == (undefined2 *)0x0) {
    local_18 = 0x80004003;
  }
  else {
    Ordinal_8(param_6);
    if (param_2 == 3) {
      local_18 = FUN_100071f9(param_1,param_4,param_6);
    }
    else {
      local_18 = 0x80070057;
    }
  }
  return local_18;
}



// Function: Catch@1000ed27 at 1000ed27

undefined4 Catch_1000ed27(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ed1c;
}



// Function: FUN_1000ed38 at 1000ed38

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000ed38(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_1000eca4((undefined4 *)(param_1 + 4));
  return param_1;
}



// Function: FUN_1000ed64 at 1000ed64

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000ed64(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *local_18;
  
  local_18 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)param_1 + 0x69) == '\0') {
    puVar1 = (undefined4 *)FUN_1000e0db(this,(int)(param_1 + 3));
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 0x1a) = *(undefined1 *)(param_1 + 0x1a);
    if (*(char *)((int)local_18 + 0x69) != '\0') {
      local_18 = puVar1;
    }
    puVar2 = FUN_1000ed64(this,(undefined4 *)*param_1,puVar1);
    *puVar1 = puVar2;
    puVar2 = FUN_1000ed64(this,(undefined4 *)param_1[2],puVar1);
    puVar1[2] = puVar2;
  }
  return local_18;
}



// Function: Catch@1000edd4 at 1000edd4

void Catch_1000edd4(void)

{
  int unaff_EBP;
  
  FUN_10005e95(*(void **)(unaff_EBP + -0x18),*(int **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000ede9 at 1000ede9

void __thiscall FUN_1000ede9(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = *(int *)((int)this + 4);
  puVar4 = FUN_1000ed64(this,*(undefined4 **)(*(int *)(param_1 + 4) + 4),iVar1);
  *(undefined4 **)(iVar1 + 4) = puVar4;
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  piVar2 = *(int **)((int)this + 4);
  piVar3 = (int *)piVar2[1];
  if (*(char *)(piVar2[1] + 0x69) == '\0') {
    do {
      piVar5 = piVar3;
      piVar3 = (int *)*piVar5;
    } while (*(char *)((int)piVar3 + 0x69) == '\0');
    *piVar2 = (int)piVar5;
    iVar1 = *(int *)(*(int *)((int)this + 4) + 4);
    do {
      iVar6 = iVar1;
      iVar1 = *(int *)(iVar6 + 8);
    } while (*(char *)(iVar1 + 0x69) == '\0');
    *(int *)(*(int *)((int)this + 4) + 8) = iVar6;
  }
  else {
    *piVar2 = (int)piVar2;
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
  }
  return;
}



// Function: FUN_1000ee4a at 1000ee4a

void * __thiscall FUN_1000ee4a(void *this,void *param_1)

{
  void *local_8;
  
  if (this != param_1) {
    local_8 = this;
    FUN_10005fff(this,&local_8,(int *)**(int **)((int)this + 4),*(int **)((int)this + 4));
    FUN_1000ede9(this,(int)param_1);
  }
  return this;
}



// Function: FUN_1000ee79 at 1000ee79

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000ee79(void *this,void *param_1)

{
  undefined4 local_18;
  
  if (param_1 == (void *)0x0) {
    local_18 = 0x80004003;
  }
  else {
    FUN_1000ee4a((void *)((int)this + 8),param_1);
    local_18 = 0;
  }
  return local_18;
}



// Function: Catch@1000eeb5 at 1000eeb5

undefined4 Catch_1000eeb5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000eeaa;
}



// Function: FUN_1000eec6 at 1000eec6

undefined4 FUN_1000eec6(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_10020a34 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 4);
  return 1;
}



// Function: FUN_1000eef8 at 1000eef8

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_1000eef8(undefined4 param_1,undefined4 *param_2)

{
  undefined2 local_48 [4];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34 [11];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0;
  if (param_2 == (undefined4 *)0x0) {
    local_38 = 0x80004003;
  }
  else {
    FUN_10001e8f(local_34,param_2);
    local_8._0_1_ = 1;
    local_48[0] = 8;
    local_40 = FUN_100018a3(local_34);
    Ordinal_10(param_1,local_48);
    local_38 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FID_conflict__Tidy(local_34,'\x01',0);
  }
  local_8 = 0xffffffff;
  FUN_1000f496();
  return;
}



// Function: Catch@1000ef68 at 1000ef68

undefined4 Catch_1000ef68(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x34) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000ef5f;
}



// Function: FUN_1000ef79 at 1000ef79

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000ef79(void *this,undefined4 *param_1,undefined4 *param_2)

{
  FUN_10001e8f(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  return this;
}



// Function: FUN_1000efac at 1000efac

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000efac(void *this,undefined4 *param_1)

{
  FUN_1000ef79(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_1000efda at 1000efda

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_1000efda(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_10012246;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_1000efac(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_1000f008 at 1000f008

void __cdecl FUN_1000f008(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_1000efda(param_2,param_3);
  return;
}



// Function: FUN_1000f01b at 1000f01b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000f01b(undefined4 *param_1)

{
  *param_1 = ATL::
             ICollectionOnSTLImpl<struct_IEnumSubscribers,class_std::map<class_CFCBstrId,struct_ISubscriber*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_ISubscriber*>_>_>,struct_tagVARIANT,class__CopyMapItemSubId,class_ATL::CComEnumOnSTL<struct_IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,struct_tagVARIANT,class__CopyMapItemSubId,class_std::map<class_CFCBstrId,struct_ISubscriber*,struct_std::less<class_CFCBstrId>,class_std::allocator<struct_std::pair<class_CFCBstrId_const_,struct_ISubscriber*>_>_>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  FUN_1000b84d((int)(param_1 + 1));
  return param_1;
}



// Function: FUN_1000f046 at 1000f046

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000f046(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_1000f01b((undefined4 *)(param_1 + 4));
  return param_1;
}



// Function: FUN_1000f072 at 1000f072

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_1000f072(void *this,void *param_1)

{
  undefined4 local_18;
  
  if (param_1 == (void *)0x0) {
    local_18 = 0x80004003;
  }
  else {
    FUN_1000eb61((void *)((int)this + 8),param_1);
    local_18 = 0;
  }
  return local_18;
}



// Function: Catch@1000f0ae at 1000f0ae

undefined4 Catch_1000f0ae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x8000ffff;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000f0a3;
}



// Function: FUN_1000f0c6 at 1000f0c6

void __fastcall FUN_1000f0c6(int *param_1)

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



// Function: FUN_1000f10a at 1000f10a

int __fastcall FUN_1000f10a(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1000f123 at 1000f123

undefined4 * __fastcall FUN_1000f123(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000f10a((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1001c328;
  param_1[3] = &DAT_1001c328;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10020a80 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1000f164 at 1000f164

void __fastcall FUN_1000f164(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000f183 at 1000f183

int __fastcall FUN_1000f183(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1000f1a8 at 1000f1a8

void __fastcall FUN_1000f1a8(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1000f164((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000f1c0 at 1000f1c0

undefined4 * __fastcall FUN_1000f1c0(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000f183((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10016098;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10020a80 = 1;
  }
  return param_1;
}



// Function: FUN_1000f200 at 1000f200

void FUN_1000f200(undefined4 param_1)

{
  (*(code *)PTR_FUN_10020a38)(param_1,0);
  return;
}



// Function: FUN_1000f250 at 1000f250

void FUN_1000f250(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__100160a8;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1001c228);
}



// Function: _com_error at 1000f290

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__100160a8;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 1000f2d0

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__100160a8;
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



// Function: FUN_1000f311 at 1000f311

void FUN_1000f311(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000f334

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



// Function: __security_check_cookie at 1000f38c

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10020a54) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 1000f39b

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10020a54 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 1000f3ce

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10020a54 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1000f404

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10020a54 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 1000f43a

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10020a54 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 1000f473

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



// Function: FUN_1000f487 at 1000f487

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000f487(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_1000f496 at 1000f496

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000f496(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __ArrayUnwind at 1000f4be

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



// Function: `eh_vector_destructor_iterator' at 1000f51c

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
  FUN_1000f567();
  return;
}



// Function: FUN_1000f567 at 1000f567

void FUN_1000f567(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __alloca_probe at 1000f590

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



// Function: `eh_vector_constructor_iterator' at 1000f5c2

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
  FUN_1000f60f();
  return;
}



// Function: FUN_1000f60f at 1000f60f

void FUN_1000f60f(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 1000f627

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
  
  local_8 = &DAT_1001c2c0;
  uStack_c = 0x1000f633;
  local_20[0] = DecodePointer(DAT_10020f2c);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10020f2c);
    local_24 = DecodePointer(DAT_10020f28);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10020f2c = EncodePointer(local_20[0]);
    DAT_10020f28 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000f6bf();
  }
  return p_Var1;
}



// Function: FUN_1000f6bf at 1000f6bf

void FUN_1000f6bf(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000f6c8

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __CRT_INIT@12 at 1000f72d

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
    if (DAT_10020be8 < 1) {
      return 0;
    }
    DAT_10020be8 = DAT_10020be8 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10020f20,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10020f1c == 2) {
      param_2 = (int *)DecodePointer(DAT_10020f2c);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10020f28);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10020f2c);
            piVar8 = (int *)DecodePointer(DAT_10020f28);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10020f28 = (PVOID)encoded_null();
        DAT_10020f2c = DAT_10020f28;
      }
      DAT_10020f1c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10020f20,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10020f20,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10020f1c == 0) {
      DAT_10020f1c = 1;
      iVar5 = initterm_e(&DAT_10013248,&DAT_10013250);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1001321c,&DAT_10013244);
      DAT_10020f1c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10020f20,0);
    }
    if ((DAT_10020f24 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10020f24), BVar2 != 0)) {
      (*DAT_10020f24)(param_1,2,param_3);
    }
    DAT_10020be8 = DAT_10020be8 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1000f937

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000f9d7) */
/* WARNING: Removing unreachable block (ram,0x1000f984) */
/* WARNING: Removing unreachable block (ram,0x1000fa04) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10020a60 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10020be8 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_100034e2(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_100034e2(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000fa42();
  return local_20;
}



// Function: FUN_1000fa42 at 1000fa42

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000fa42(void)

{
  _DAT_10020a60 = 0xffffffff;
  return;
}



// Function: entry at 1000fa4d

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: FUN_1000fa70 at 1000fa70

void __cdecl
FUN_1000fa70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10020a54,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __alloca_probe_16 at 1000faa0

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



// Function: __alloca_probe_8 at 1000fab6

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



// Function: ___report_gsfailure at 1000facc

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
  
  _DAT_10020d08 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10020d0c = &stack0x00000004;
  _DAT_10020c48 = 0x10001;
  _DAT_10020bf0 = 0xc0000409;
  _DAT_10020bf4 = 1;
  local_32c = DAT_10020a54;
  local_328 = DAT_10020a58;
  _DAT_10020bfc = unaff_retaddr;
  _DAT_10020cd4 = in_GS;
  _DAT_10020cd8 = in_FS;
  _DAT_10020cdc = in_ES;
  _DAT_10020ce0 = in_DS;
  _DAT_10020ce4 = unaff_EDI;
  _DAT_10020ce8 = unaff_ESI;
  _DAT_10020cec = unaff_EBX;
  _DAT_10020cf0 = in_EDX;
  _DAT_10020cf4 = in_ECX;
  _DAT_10020cf8 = in_EAX;
  _DAT_10020cfc = unaff_EBP;
  DAT_10020d00 = unaff_retaddr;
  _DAT_10020d04 = in_CS;
  _DAT_10020d10 = in_SS;
  DAT_10020c40 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_100160b8);
  if (DAT_10020c40 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1000fbe0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10020a54 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000fc25

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



// Function: __ValidateImageBase at 1000fcb0

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



// Function: __FindPESection at 1000fcf0

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



// Function: __IsNonwritableInCurrentImage at 1000fd40

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
  
  pcStack_10 = FUN_1000fa70;
  local_14 = ExceptionList;
  local_c = DAT_10020a54 ^ 0x1001c308;
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



// Function: ___security_init_cookie at 1000fe14

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
  if ((DAT_10020a54 == 0xbb40e64e) || ((DAT_10020a54 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10020a54 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10020a54 == 0xbb40e64e) {
      DAT_10020a54 = 0xbb40e64f;
    }
    else if ((DAT_10020a54 & 0xffff0000) == 0) {
      DAT_10020a54 = DAT_10020a54 | (DAT_10020a54 | 0x4711) << 0x10;
    }
    DAT_10020a58 = ~DAT_10020a54;
  }
  else {
    DAT_10020a58 = ~DAT_10020a54;
  }
  return;
}



// Function: Unwind@1000fec8 at 1000fec8

void Unwind_1000fec8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000fecb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000feec at 1000feec

void Unwind_1000feec(void)

{
  int unaff_EBP;
  
  FUN_100010e3(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ff0f at 1000ff0f

void Unwind_1000ff0f(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ff34 at 1000ff34

void Unwind_1000ff34(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000ff5a at 1000ff5a

void Unwind_1000ff5a(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0x824));
  return;
}



// Function: Unwind@1000ff65 at 1000ff65

void Unwind_1000ff65(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x814));
  return;
}



// Function: Unwind@1000ff70 at 1000ff70

void Unwind_1000ff70(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x814));
  return;
}



// Function: Unwind@1000ff7b at 1000ff7b

void Unwind_1000ff7b(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x81c));
  return;
}



// Function: Unwind@1000ff86 at 1000ff86

void Unwind_1000ff86(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x81c));
  return;
}



// Function: Unwind@1000ff91 at 1000ff91

void Unwind_1000ff91(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x81c));
  return;
}



// Function: Unwind@1000ff9c at 1000ff9c

void Unwind_1000ff9c(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x814));
  return;
}



// Function: Unwind@1000ffcf at 1000ffcf

void Unwind_1000ffcf(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001000d at 1001000d

void Unwind_1001000d(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010030 at 10010030

void Unwind_10010030(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001b88(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10010064 at 10010064

void Unwind_10010064(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001006c at 1001006c

void Unwind_1001006c(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10010099 at 10010099

void Unwind_10010099(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100100a1 at 100100a1

void Unwind_100100a1(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100100a9 at 100100a9

void Unwind_100100a9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100100b1 at 100100b1

void Unwind_100100b1(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@100100de at 100100de

void Unwind_100100de(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100100e6 at 100100e6

void Unwind_100100e6(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100100ee at 100100ee

void Unwind_100100ee(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100100f6 at 100100f6

void Unwind_100100f6(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10010123 at 10010123

void Unwind_10010123(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001012e at 1001012e

void Unwind_1001012e(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10010139 at 10010139

void Unwind_10010139(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10010144 at 10010144

void Unwind_10010144(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1001014f at 1001014f

void Unwind_1001014f(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010157 at 10010157

void Unwind_10010157(void)

{
  int unaff_EBP;
  
  FUN_1000e7fb((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10010162 at 10010162

void Unwind_10010162(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@10010188 at 10010188

void Unwind_10010188(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10010190 at 10010190

void Unwind_10010190(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10010198 at 10010198

void Unwind_10010198(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100101a0 at 100101a0

void Unwind_100101a0(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100101cd at 100101cd

void Unwind_100101cd(void)

{
  DAT_10020ab8 = DAT_10020ab8 & 0xfffffffe;
  return;
}



// Function: Unwind@100101f6 at 100101f6

void Unwind_100101f6(void)

{
  int unaff_EBP;
  
  FUN_1000e50c(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010219 at 10010219

void Unwind_10010219(void)

{
  int unaff_EBP;
  
  FUN_10002fdc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001023c at 1001023c

void Unwind_1001023c(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001026f at 1001026f

void Unwind_1001026f(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@100102a2 at 100102a2

void Unwind_100102a2(void)

{
  int unaff_EBP;
  
  FUN_10002e64(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100102c5 at 100102c5

void Unwind_100102c5(void)

{
  int unaff_EBP;
  
  FUN_10002dd3(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100102cd at 100102cd

void Unwind_100102cd(void)

{
  int unaff_EBP;
  
  FUN_1000e50c(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100102f0 at 100102f0

void Unwind_100102f0(void)

{
  FUN_100011a9();
  return;
}



// Function: Unwind@10010307 at 10010307

void Unwind_10010307(void)

{
  FUN_100011a9();
  return;
}



// Function: Unwind@1001033a at 1001033a

void Unwind_1001033a(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10010345 at 10010345

void Unwind_10010345(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001036b at 1001036b

void Unwind_1001036b(void)

{
  int unaff_EBP;
  
  FUN_10002fdc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010373 at 10010373

void Unwind_10010373(void)

{
  int unaff_EBP;
  
  FUN_10002fe1(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010396 at 10010396

void Unwind_10010396(void)

{
  int unaff_EBP;
  
  FUN_10002fe1(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001039e at 1001039e

void Unwind_1001039e(void)

{
  int unaff_EBP;
  
  FUN_10002fdc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100103c1 at 100103c1

void Unwind_100103c1(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002e37(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100103e4 at 100103e4

void Unwind_100103e4(void)

{
  int unaff_EBP;
  
  FUN_100036da((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001040a at 1001040a

void Unwind_1001040a(void)

{
  int unaff_EBP;
  
  FUN_100028d0(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@10010437 at 10010437

void Unwind_10010437(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10010442 at 10010442

void Unwind_10010442(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001044d at 1001044d

void Unwind_1001044d(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10010458 at 10010458

void Unwind_10010458(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10010463 at 10010463

void Unwind_10010463(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001046e at 1001046e

void Unwind_1001046e(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@10010479 at 10010479

void Unwind_10010479(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@10010484 at 10010484

void Unwind_10010484(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@1001048f at 1001048f

void Unwind_1001048f(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1001049a at 1001049a

void Unwind_1001049a(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100104cd at 100104cd

void Unwind_100104cd(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100104d5 at 100104d5

void Unwind_100104d5(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100104dd at 100104dd

void Unwind_100104dd(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100104e5 at 100104e5

void Unwind_100104e5(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100104ed at 100104ed

void Unwind_100104ed(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010510 at 10010510

void Unwind_10010510(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001051b at 1001051b

void Unwind_1001051b(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10010526 at 10010526

void Unwind_10010526(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10010531 at 10010531

void Unwind_10010531(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001053c at 1001053c

void Unwind_1001053c(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10010547 at 10010547

void Unwind_10010547(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001057a at 1001057a

void Unwind_1001057a(void)

{
  int unaff_EBP;
  
  FUN_100034cb((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001059d at 1001059d

void Unwind_1001059d(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100105a8 at 100105a8

void Unwind_100105a8(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100105ce at 100105ce

void Unwind_100105ce(void)

{
  int unaff_EBP;
  
  FUN_100041c8(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100105f1 at 100105f1

void Unwind_100105f1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100105f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Container_base12::~_Container_base12(*(_Container_base12 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010615 at 10010615

void Unwind_10010615(void)

{
  int unaff_EBP;
  
  FUN_1000345a((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001061d at 1001061d

void Unwind_1001061d(void)

{
  int unaff_EBP;
  
  FUN_1000345a((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10010640 at 10010640

void Unwind_10010640(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010663 at 10010663

void Unwind_10010663(void)

{
  int unaff_EBP;
  
  FUN_1000346a((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1001066e at 1001066e

void Unwind_1001066e(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@10010679 at 10010679

void Unwind_10010679(void)

{
  int unaff_EBP;
  
  FUN_1000346a((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@100106ac at 100106ac

void Unwind_100106ac(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@100106b7 at 100106b7

void Unwind_100106b7(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@100106c2 at 100106c2

void Unwind_100106c2(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@100106cd at 100106cd

void Unwind_100106cd(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@100106d8 at 100106d8

void Unwind_100106d8(void)

{
  int unaff_EBP;
  
  ATL::CRegKey::Close((CRegKey *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1001070b at 1001070b

void Unwind_1001070b(void)

{
  int unaff_EBP;
  
  FUN_100034cb((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001072e at 1001072e

void Unwind_1001072e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10010753 at 10010753

void Unwind_10010753(void)

{
  int unaff_EBP;
  
  FUN_1000449c(*(_Container_base12 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010776 at 10010776

void Unwind_10010776(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@10010781 at 10010781

void Unwind_10010781(void)

{
  int unaff_EBP;
  
  FUN_1000346a((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@100107b4 at 100107b4

void Unwind_100107b4(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002e37(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@100107bf at 100107bf

void Unwind_100107bf(void)

{
  int unaff_EBP;
  
  FUN_100036da((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@100107ca at 100107ca

void Unwind_100107ca(void)

{
  int unaff_EBP;
  
  FUN_10003704((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@100107d5 at 100107d5

void Unwind_100107d5(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10010808 at 10010808

void Unwind_10010808(void)

{
  int unaff_EBP;
  
  thunk_FUN_10002e37(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10010813 at 10010813

void Unwind_10010813(void)

{
  int unaff_EBP;
  
  FUN_100036da((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1001081e at 1001081e

void Unwind_1001081e(void)

{
  int unaff_EBP;
  
  FUN_10003704((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10010829 at 10010829

void Unwind_10010829(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1001085c at 1001085c

void Unwind_1001085c(void)

{
  int unaff_EBP;
  
  FUN_10002dd3(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10010864 at 10010864

void Unwind_10010864(void)

{
  int unaff_EBP;
  
  FUN_1000e50c(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10010887 at 10010887

void Unwind_10010887(void)

{
  int unaff_EBP;
  
  FUN_10001aca(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001088f at 1001088f

void Unwind_1001088f(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100108b2 at 100108b2

void Unwind_100108b2(void)

{
  int unaff_EBP;
  
  FUN_10005508(*(_Container_base12 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100108d5 at 100108d5

void Unwind_100108d5(void)

{
  int unaff_EBP;
  
  FUN_10005be6(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100108dd at 100108dd

void Unwind_100108dd(void)

{
  int unaff_EBP;
  
  FUN_10001aca(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100108e5 at 100108e5

void Unwind_100108e5(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010908 at 10010908

void Unwind_10010908(void)

{
  int unaff_EBP;
  
  FUN_10002f58(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001092b at 1001092b

void Unwind_1001092b(void)

{
  int unaff_EBP;
  
  FUN_10006052(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001094e at 1001094e

void Unwind_1001094e(void)

{
  int unaff_EBP;
  
  FUN_1000609b((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10010959 at 10010959

void Unwind_10010959(void)

{
  int unaff_EBP;
  
  FUN_10006052(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001097c at 1001097c

void Unwind_1001097c(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010987 at 10010987

void Unwind_10010987(void)

{
  int unaff_EBP;
  
  FUN_10005c08((_Container_base12 *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10010992 at 10010992

void Unwind_10010992(void)

{
  int unaff_EBP;
  
  FUN_1000e7fb((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x44));
  return;
}



// Function: Unwind@1001099d at 1001099d

void Unwind_1001099d(void)

{
  int unaff_EBP;
  
  FUN_1000609b((void *)(*(int *)(unaff_EBP + -0x10) + 0x7c));
  return;
}



// Function: Unwind@100109a8 at 100109a8

void Unwind_100109a8(void)

{
  int unaff_EBP;
  
  FUN_10006052(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100109b0 at 100109b0

void Unwind_100109b0(void)

{
  int unaff_EBP;
  
  FUN_10005508(*(_Container_base12 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100109b8 at 100109b8

void Unwind_100109b8(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100109de at 100109de

void Unwind_100109de(void)

{
  int unaff_EBP;
  
  FUN_100060b9(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010a01 at 10010a01

void Unwind_10010a01(void)

{
  int unaff_EBP;
  
  FUN_100010f5(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010a24 at 10010a24

void Unwind_10010a24(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010a2e at 10010a2e

void Unwind_10010a2e(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10010a51 at 10010a51

void Unwind_10010a51(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010a59 at 10010a59

void Unwind_10010a59(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010a61 at 10010a61

void Unwind_10010a61(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010a69 at 10010a69

void Unwind_10010a69(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010a71 at 10010a71

void Unwind_10010a71(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010a79 at 10010a79

void Unwind_10010a79(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010a9c at 10010a9c

void Unwind_10010a9c(void)

{
  int unaff_EBP;
  
  FUN_100034cb((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10010abf at 10010abf

void Unwind_10010abf(void)

{
  int unaff_EBP;
  
  FUN_100034cb((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@10010aca at 10010aca

void Unwind_10010aca(void)

{
  int unaff_EBP;
  
  FUN_10001207((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10010ad5 at 10010ad5

void Unwind_10010ad5(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10010ae0 at 10010ae0

void Unwind_10010ae0(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10010aeb at 10010aeb

void Unwind_10010aeb(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10010af6 at 10010af6

void Unwind_10010af6(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10010b01 at 10010b01

void Unwind_10010b01(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10010b0c at 10010b0c

void Unwind_10010b0c(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10010b17 at 10010b17

void Unwind_10010b17(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10010b22 at 10010b22

void Unwind_10010b22(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10010b2d at 10010b2d

void Unwind_10010b2d(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10010b60 at 10010b60

void Unwind_10010b60(void)

{
  int unaff_EBP;
  
  FUN_1000633e(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010b83 at 10010b83

void Unwind_10010b83(void)

{
  int unaff_EBP;
  
  FUN_100063a0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010ba9 at 10010ba9

void Unwind_10010ba9(void)

{
  int unaff_EBP;
  
  FUN_100063a0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010bb4 at 10010bb4

void Unwind_10010bb4(void)

{
  int unaff_EBP;
  
  FUN_1000633e(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010bd7 at 10010bd7

void Unwind_10010bd7(void)

{
  int unaff_EBP;
  
  FUN_100063be(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10010be2 at 10010be2

void Unwind_10010be2(void)

{
  int unaff_EBP;
  
  FUN_100060b9(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010c05 at 10010c05

void Unwind_10010c05(void)

{
  int unaff_EBP;
  
  FUN_10006edb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010c28 at 10010c28

void Unwind_10010c28(void)

{
  int unaff_EBP;
  
  FUN_100082d7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010c4b at 10010c4b

void Unwind_10010c4b(void)

{
  int unaff_EBP;
  
  FUN_10002e64(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010c53 at 10010c53

void Unwind_10010c53(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10010c5e at 10010c5e

void Unwind_10010c5e(void)

{
  int unaff_EBP;
  
  FUN_100082d7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010c81 at 10010c81

void Unwind_10010c81(void)

{
  int unaff_EBP;
  
  FUN_10006fa2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010c89 at 10010c89

void Unwind_10010c89(void)

{
  int unaff_EBP;
  
  FUN_100082d7(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010ce2 at 10010ce2

void Unwind_10010ce2(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10010d07 at 10010d07

void Unwind_10010d07(void)

{
  int unaff_EBP;
  
  FUN_10006f03(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10010d2d at 10010d2d

void Unwind_10010d2d(void)

{
  int unaff_EBP;
  
  FUN_10006f03(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10010d38 at 10010d38

void Unwind_10010d38(void)

{
  int unaff_EBP;
  
  FUN_10006edb(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010d76 at 10010d76

void Unwind_10010d76(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10010d9b at 10010d9b

void Unwind_10010d9b(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x10) + 0x18);
  return;
}



// Function: Unwind@10010da6 at 10010da6

void Unwind_10010da6(void)

{
  int unaff_EBP;
  
  FUN_1000e7fb((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@10010db1 at 10010db1

void Unwind_10010db1(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@10010dbc at 10010dbc

void Unwind_10010dbc(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@10010dc7 at 10010dc7

void Unwind_10010dc7(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@10010dd5 at 10010dd5

void Unwind_10010dd5(void)

{
  int unaff_EBP;
  
  FUN_1000782a(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010ddd at 10010ddd

void Unwind_10010ddd(void)

{
  int unaff_EBP;
  
  FUN_1000782a(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010de5 at 10010de5

void Unwind_10010de5(void)

{
  int unaff_EBP;
  
  FUN_10002e64(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010ded at 10010ded

void Unwind_10010ded(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10010e13 at 10010e13

void Unwind_10010e13(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@10010e1e at 10010e1e

void Unwind_10010e1e(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@10010e29 at 10010e29

void Unwind_10010e29(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@10010e34 at 10010e34

void Unwind_10010e34(void)

{
  int unaff_EBP;
  
  FUN_1000e7fb((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10010e3f at 10010e3f

void Unwind_10010e3f(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@10010e4a at 10010e4a

void Unwind_10010e4a(void)

{
  int unaff_EBP;
  
  FUN_1000782a(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10010e52 at 10010e52

void Unwind_10010e52(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10010e78 at 10010e78

void Unwind_10010e78(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10010e83 at 10010e83

void Unwind_10010e83(void)

{
  int unaff_EBP;
  
  FUN_1000782a(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010ea6 at 10010ea6

void Unwind_10010ea6(void)

{
  int unaff_EBP;
  
  FUN_100078a2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010ec9 at 10010ec9

void Unwind_10010ec9(void)

{
  int unaff_EBP;
  
  FUN_10007921(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010eef at 10010eef

void Unwind_10010eef(void)

{
  int unaff_EBP;
  
  FUN_10007921(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010efa at 10010efa

void Unwind_10010efa(void)

{
  int unaff_EBP;
  
  FUN_100078a2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010f1d at 10010f1d

void Unwind_10010f1d(void)

{
  int unaff_EBP;
  
  FUN_1000793f(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010f40 at 10010f40

void Unwind_10010f40(void)

{
  int unaff_EBP;
  
  FUN_100079a6(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010f66 at 10010f66

void Unwind_10010f66(void)

{
  int unaff_EBP;
  
  FUN_100079a6(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010f71 at 10010f71

void Unwind_10010f71(void)

{
  int unaff_EBP;
  
  FUN_1000793f(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010f94 at 10010f94

void Unwind_10010f94(void)

{
  int unaff_EBP;
  
  FUN_100079c4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010fb7 at 10010fb7

void Unwind_10010fb7(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10010fc2 at 10010fc2

void Unwind_10010fc2(void)

{
  int unaff_EBP;
  
  FUN_10002e64(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011000 at 10011000

void Unwind_10011000(void)

{
  int unaff_EBP;
  
  FUN_10006fa2(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011059 at 10011059

void Unwind_10011059(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10011099 at 10011099

void Unwind_10011099(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100110be at 100110be

void Unwind_100110be(void)

{
  int unaff_EBP;
  
  FUN_10008f99(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100110e4 at 100110e4

void Unwind_100110e4(void)

{
  int unaff_EBP;
  
  FUN_10008f99(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100110ef at 100110ef

void Unwind_100110ef(void)

{
  int unaff_EBP;
  
  FUN_10008f71(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011112 at 10011112

void Unwind_10011112(void)

{
  int unaff_EBP;
  
  FUN_1000827e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001111d at 1001111d

void Unwind_1001111d(void)

{
  int unaff_EBP;
  
  FUN_100079c4(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011176 at 10011176

void Unwind_10011176(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100111b6 at 100111b6

void Unwind_100111b6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100111db at 100111db

void Unwind_100111db(void)

{
  int unaff_EBP;
  
  FUN_10008f71(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011219 at 10011219

void Unwind_10011219(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001123e at 1001123e

void Unwind_1001123e(void)

{
  FUN_10002fe1(0x10020abc);
  return;
}



// Function: Unwind@10011248 at 10011248

void Unwind_10011248(void)

{
  FUN_10002fdc(0x10020abc);
  return;
}



// Function: Unwind@1001126d at 1001126d

void Unwind_1001126d(void)

{
  int unaff_EBP;
  
  FUN_100099df(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@10011275 at 10011275

void Unwind_10011275(void)

{
  int unaff_EBP;
  
  _eh_vector_destructor_iterator_((void *)(unaff_EBP + -0x3c),0x10,2,FUN_100099df);
  return;
}



// Function: Unwind@100112a3 at 100112a3

void Unwind_100112a3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100112a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100112c7 at 100112c7

void Unwind_100112c7(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100112cf at 100112cf

void Unwind_100112cf(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100112d7 at 100112d7

void Unwind_100112d7(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100112df at 100112df

void Unwind_100112df(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100112e7 at 100112e7

void Unwind_100112e7(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001130a at 1001130a

void Unwind_1001130a(void)

{
  int unaff_EBP;
  
  FUN_100033c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011312 at 10011312

void Unwind_10011312(void)

{
  int unaff_EBP;
  
  FUN_10002e64(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011335 at 10011335

void Unwind_10011335(void)

{
  int unaff_EBP;
  
  FUN_10002e64(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001133d at 1001133d

void Unwind_1001133d(void)

{
  int unaff_EBP;
  
  FUN_100033c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011360 at 10011360

void Unwind_10011360(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011368 at 10011368

void Unwind_10011368(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011370 at 10011370

void Unwind_10011370(void)

{
  int unaff_EBP;
  
  FUN_10009ca8((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011378 at 10011378

void Unwind_10011378(void)

{
  int unaff_EBP;
  
  FUN_100099df(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10011380 at 10011380

void Unwind_10011380(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011388 at 10011388

void Unwind_10011388(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100113ab at 100113ab

void Unwind_100113ab(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100113b3 at 100113b3

void Unwind_100113b3(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100113bb at 100113bb

void Unwind_100113bb(void)

{
  int unaff_EBP;
  
  FUN_10009ca8((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100113c3 at 100113c3

void Unwind_100113c3(void)

{
  int unaff_EBP;
  
  FUN_100099df(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@100113cb at 100113cb

void Unwind_100113cb(void)

{
  int unaff_EBP;
  
  FUN_100099df(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@100113d3 at 100113d3

void Unwind_100113d3(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100113db at 100113db

void Unwind_100113db(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100113fe at 100113fe

void Unwind_100113fe(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011406 at 10011406

void Unwind_10011406(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001140e at 1001140e

void Unwind_1001140e(void)

{
  int unaff_EBP;
  
  FUN_10009ca8((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011416 at 10011416

void Unwind_10011416(void)

{
  int unaff_EBP;
  
  FUN_100099df(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@1001141e at 1001141e

void Unwind_1001141e(void)

{
  int unaff_EBP;
  
  FUN_100099df(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@10011426 at 10011426

void Unwind_10011426(void)

{
  int unaff_EBP;
  
  FUN_100099df(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@1001142e at 1001142e

void Unwind_1001142e(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011436 at 10011436

void Unwind_10011436(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011459 at 10011459

void Unwind_10011459(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001147c at 1001147c

void Unwind_1001147c(void)

{
  int unaff_EBP;
  
  FUN_10002f58(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011484 at 10011484

void Unwind_10011484(void)

{
  int unaff_EBP;
  
  FUN_1000a43f(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100114a7 at 100114a7

void Unwind_100114a7(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100114af at 100114af

void Unwind_100114af(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100114b7 at 100114b7

void Unwind_100114b7(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100114bf at 100114bf

void Unwind_100114bf(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100114c7 at 100114c7

void Unwind_100114c7(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100114cf at 100114cf

void Unwind_100114cf(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100114fc at 100114fc

void Unwind_100114fc(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10011507 at 10011507

void Unwind_10011507(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001150f at 1001150f

void Unwind_1001150f(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011517 at 10011517

void Unwind_10011517(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001151f at 1001151f

void Unwind_1001151f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10011527 at 10011527

void Unwind_10011527(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001152f at 1001152f

void Unwind_1001152f(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011537 at 10011537

void Unwind_10011537(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10011567 at 10011567

void Unwind_10011567(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10011572 at 10011572

void Unwind_10011572(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001157a at 1001157a

void Unwind_1001157a(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011582 at 10011582

void Unwind_10011582(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001158a at 1001158a

void Unwind_1001158a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011592 at 10011592

void Unwind_10011592(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001159a at 1001159a

void Unwind_1001159a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100115a2 at 100115a2

void Unwind_100115a2(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@100115d2 at 100115d2

void Unwind_100115d2(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@100115dd at 100115dd

void Unwind_100115dd(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100115e5 at 100115e5

void Unwind_100115e5(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100115ed at 100115ed

void Unwind_100115ed(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100115f5 at 100115f5

void Unwind_100115f5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100115fd at 100115fd

void Unwind_100115fd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10011605 at 10011605

void Unwind_10011605(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001160d at 1001160d

void Unwind_1001160d(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001163d at 1001163d

void Unwind_1001163d(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10011648 at 10011648

void Unwind_10011648(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011650 at 10011650

void Unwind_10011650(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10011658 at 10011658

void Unwind_10011658(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011660 at 10011660

void Unwind_10011660(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011668 at 10011668

void Unwind_10011668(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10011670 at 10011670

void Unwind_10011670(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011678 at 10011678

void Unwind_10011678(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@100116a8 at 100116a8

void Unwind_100116a8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100116b3 at 100116b3

void Unwind_100116b3(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@100116be at 100116be

void Unwind_100116be(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@100116e4 at 100116e4

void Unwind_100116e4(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@100116ef at 100116ef

void Unwind_100116ef(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100116f7 at 100116f7

void Unwind_100116f7(void)

{
  int unaff_EBP;
  
  FUN_10009ca8((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10011702 at 10011702

void Unwind_10011702(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001170d at 1001170d

void Unwind_1001170d(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10011718 at 10011718

void Unwind_10011718(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10011723 at 10011723

void Unwind_10011723(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001172e at 1001172e

void Unwind_1001172e(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10011739 at 10011739

void Unwind_10011739(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10011744 at 10011744

void Unwind_10011744(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001174f at 1001174f

void Unwind_1001174f(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001175a at 1001175a

void Unwind_1001175a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011762 at 10011762

void Unwind_10011762(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@100117b0 at 100117b0

void Unwind_100117b0(void)

{
  int unaff_EBP;
  
  FUN_10002f58(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100117b8 at 100117b8

void Unwind_100117b8(void)

{
  int unaff_EBP;
  
  FUN_1000782a(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100117f6 at 100117f6

void Unwind_100117f6(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10011801 at 10011801

void Unwind_10011801(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x10) + 0x18);
  return;
}



// Function: Unwind@1001180c at 1001180c

void Unwind_1001180c(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011814 at 10011814

void Unwind_10011814(void)

{
  int unaff_EBP;
  
  FUN_1000e7fb((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001181f at 1001181f

void Unwind_1001181f(void)

{
  int unaff_EBP;
  
  FUN_10002e64(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011827 at 10011827

void Unwind_10011827(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(*(int *)(unaff_EBP + -0x10) + 0x70));
  return;
}



// Function: Unwind@10011832 at 10011832

void Unwind_10011832(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 0x74));
  return;
}



// Function: Unwind@1001183d at 1001183d

void Unwind_1001183d(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@10011866 at 10011866

void Unwind_10011866(void)

{
  int unaff_EBP;
  
  FUN_1000782a(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011889 at 10011889

void Unwind_10011889(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011891 at 10011891

void Unwind_10011891(void)

{
  int unaff_EBP;
  
  FUN_10009ca8((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10011899 at 10011899

void Unwind_10011899(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100118a1 at 100118a1

void Unwind_100118a1(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100118a9 at 100118a9

void Unwind_100118a9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100118b1 at 100118b1

void Unwind_100118b1(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100118de at 100118de

void Unwind_100118de(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@100118e6 at 100118e6

void Unwind_100118e6(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100118ee at 100118ee

void Unwind_100118ee(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100118f6 at 100118f6

void Unwind_100118f6(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100118fe at 100118fe

void Unwind_100118fe(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011906 at 10011906

void Unwind_10011906(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001190e at 1001190e

void Unwind_1001190e(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001193b at 1001193b

void Unwind_1001193b(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011943 at 10011943

void Unwind_10011943(void)

{
  int unaff_EBP;
  
  FUN_10005be6((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001194b at 1001194b

void Unwind_1001194b(void)

{
  int unaff_EBP;
  
  FUN_10005ed9((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011953 at 10011953

void Unwind_10011953(void)

{
  int unaff_EBP;
  
  FUN_10005be6((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001195b at 1001195b

void Unwind_1001195b(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011963 at 10011963

void Unwind_10011963(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011990 at 10011990

void Unwind_10011990(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10011998 at 10011998

void Unwind_10011998(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100119a0 at 100119a0

void Unwind_100119a0(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100119a8 at 100119a8

void Unwind_100119a8(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100119b2 at 100119b2

void Unwind_100119b2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100119ba at 100119ba

void Unwind_100119ba(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@100119c2 at 100119c2

void Unwind_100119c2(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@100119ef at 100119ef

void Unwind_100119ef(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@100119fa at 100119fa

void Unwind_100119fa(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011a02 at 10011a02

void Unwind_10011a02(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10011a0a at 10011a0a

void Unwind_10011a0a(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011a12 at 10011a12

void Unwind_10011a12(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011a1a at 10011a1a

void Unwind_10011a1a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10011a22 at 10011a22

void Unwind_10011a22(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011a2a at 10011a2a

void Unwind_10011a2a(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011a5a at 10011a5a

void Unwind_10011a5a(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10011a62 at 10011a62

void Unwind_10011a62(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10011a6a at 10011a6a

void Unwind_10011a6a(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011a72 at 10011a72

void Unwind_10011a72(void)

{
  int unaff_EBP;
  
  FUN_100033c0((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011a7a at 10011a7a

void Unwind_10011a7a(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10011a82 at 10011a82

void Unwind_10011a82(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10011a8a at 10011a8a

void Unwind_10011a8a(void)

{
  int unaff_EBP;
  
  FUN_100010f5((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10011a92 at 10011a92

void Unwind_10011a92(void)

{
  int unaff_EBP;
  
  FUN_10002e64((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10011a9a at 10011a9a

void Unwind_10011a9a(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10011aa2 at 10011aa2

void Unwind_10011aa2(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@10011b23 at 10011b23

void Unwind_10011b23(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10011b46 at 10011b46

void Unwind_10011b46(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10011b69 at 10011b69

void Unwind_10011b69(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011b71 at 10011b71

void Unwind_10011b71(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011b79 at 10011b79

void Unwind_10011b79(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10011ba6 at 10011ba6

void Unwind_10011ba6(void)

{
  FUN_1000a43f(&DAT_10020aec);
  return;
}



// Function: Unwind@10011bcb at 10011bcb

void Unwind_10011bcb(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10011bee at 10011bee

void Unwind_10011bee(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10011bf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Container_base12::~_Container_base12(*(_Container_base12 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011c12 at 10011c12

void Unwind_10011c12(void)

{
  int unaff_EBP;
  
  FUN_1000449c(*(_Container_base12 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011c35 at 10011c35

void Unwind_10011c35(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011c3d at 10011c3d

void Unwind_10011c3d(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10011c45 at 10011c45

void Unwind_10011c45(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10011c75 at 10011c75

void Unwind_10011c75(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10011c7d at 10011c7d

void Unwind_10011c7d(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10011ca0 at 10011ca0

void Unwind_10011ca0(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011ca8 at 10011ca8

void Unwind_10011ca8(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10011cb3 at 10011cb3

void Unwind_10011cb3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@10011cc0 at 10011cc0

void Unwind_10011cc0(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10011cf0 at 10011cf0

void Unwind_10011cf0(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011cf8 at 10011cf8

void Unwind_10011cf8(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10011d00 at 10011d00

void Unwind_10011d00(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10011d30 at 10011d30

void Unwind_10011d30(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011d38 at 10011d38

void Unwind_10011d38(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@10011d40 at 10011d40

void Unwind_10011d40(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10011d70 at 10011d70

void Unwind_10011d70(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10011d78 at 10011d78

void Unwind_10011d78(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10011d9b at 10011d9b

void Unwind_10011d9b(void)

{
  int unaff_EBP;
  
  FUN_10002f58(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011da3 at 10011da3

void Unwind_10011da3(void)

{
  int unaff_EBP;
  
  FUN_10006052(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011dc6 at 10011dc6

void Unwind_10011dc6(void)

{
  int unaff_EBP;
  
  FUN_10001221((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x114) + 4));
  return;
}



// Function: Unwind@10011dd4 at 10011dd4

void Unwind_10011dd4(void)

{
  int unaff_EBP;
  
  FUN_1000154f(*(int *)(unaff_EBP + -0x118) + 0xc);
  return;
}



// Function: Unwind@10011de2 at 10011de2

void Unwind_10011de2(void)

{
  int unaff_EBP;
  
  FUN_10005508(*(_Container_base12 **)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10011ded at 10011ded

void Unwind_10011ded(void)

{
  int unaff_EBP;
  
  FUN_10005c08((_Container_base12 *)(*(int *)(unaff_EBP + -0x118) + 0x2c));
  return;
}



// Function: Unwind@10011dfb at 10011dfb

void Unwind_10011dfb(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@10011e06 at 10011e06

void Unwind_10011e06(void)

{
  int unaff_EBP;
  
  FUN_1000e7fb((undefined4 *)(*(int *)(unaff_EBP + -0x118) + 0x44));
  return;
}



// Function: Unwind@10011e14 at 10011e14

void Unwind_10011e14(void)

{
  int unaff_EBP;
  
  FUN_1000609b((void *)(*(int *)(unaff_EBP + -0x118) + 0x7c));
  return;
}



// Function: Unwind@10011e4a at 10011e4a

void Unwind_10011e4a(void)

{
  int unaff_EBP;
  
  FUN_10002dd3(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011e88 at 10011e88

void Unwind_10011e88(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011e90 at 10011e90

void Unwind_10011e90(void)

{
  int unaff_EBP;
  
  FUN_10002dd3((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011e98 at 10011e98

void Unwind_10011e98(void)

{
  int unaff_EBP;
  
  FUN_10003437((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011ea0 at 10011ea0

void Unwind_10011ea0(void)

{
  int unaff_EBP;
  
  FUN_10002dd3((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011ea8 at 10011ea8

void Unwind_10011ea8(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011ed5 at 10011ed5

void Unwind_10011ed5(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011edd at 10011edd

void Unwind_10011edd(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10011ee7 at 10011ee7

void Unwind_10011ee7(void)

{
  int unaff_EBP;
  
  FUN_1000e7b6((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10011ef2 at 10011ef2

void Unwind_10011ef2(void)

{
  int unaff_EBP;
  
  FUN_10001b88((undefined4 *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@10011f22 at 10011f22

void Unwind_10011f22(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10011f2d at 10011f2d

void Unwind_10011f2d(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@10011f38 at 10011f38

void Unwind_10011f38(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@10011f43 at 10011f43

void Unwind_10011f43(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011f4b at 10011f4b

void Unwind_10011f4b(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011f6e at 10011f6e

void Unwind_10011f6e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    ~basic_string<>(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10011fa2 at 10011fa2

void Unwind_10011fa2(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x74) + 4));
  return;
}



// Function: Unwind@10011fad at 10011fad

void Unwind_10011fad(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10011fb5 at 10011fb5

void Unwind_10011fb5(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(*(int *)(unaff_EBP + -0x74) + 0x20));
  return;
}



// Function: Unwind@10011fc0 at 10011fc0

void Unwind_10011fc0(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10011fc8 at 10011fc8

void Unwind_10011fc8(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(*(int *)(unaff_EBP + -0x74) + 0x3c));
  return;
}



// Function: Unwind@10011fd3 at 10011fd3

void Unwind_10011fd3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10011fdb at 10011fdb

void Unwind_10011fdb(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10011fe3 at 10011fe3

void Unwind_10011fe3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10012010 at 10012010

void Unwind_10012010(void)

{
  int unaff_EBP;
  
  FUN_1000e7f4(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012018 at 10012018

void Unwind_10012018(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001203e at 1001203e

void Unwind_1001203e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10012046 at 10012046

void Unwind_10012046(void)

{
  int unaff_EBP;
  
  FUN_1000e7f4(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001204e at 1001204e

void Unwind_1001204e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@10012074 at 10012074

void Unwind_10012074(void)

{
  int unaff_EBP;
  
  FUN_10007884((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100120eb at 100120eb

void Unwind_100120eb(void)

{
  int unaff_EBP;
  
  FUN_1000e50c((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10012118 at 10012118

void Unwind_10012118(void)

{
  int unaff_EBP;
  
  FUN_1000609b((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012159 at 10012159

void Unwind_10012159(void)

{
  int unaff_EBP;
  
  FUN_100060b9(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012161 at 10012161

void Unwind_10012161(void)

{
  int unaff_EBP;
  
  FUN_100063be(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100121bd at 100121bd

void Unwind_100121bd(void)

{
  int unaff_EBP;
  
  FUN_10001aca((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100121c5 at 100121c5

void Unwind_100121c5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100121f2 at 100121f2

void Unwind_100121f2(void)

{
  int unaff_EBP;
  
  FUN_10001aca(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012215 at 10012215

void Unwind_10012215(void)

{
  int unaff_EBP;
  
  FUN_10005be6(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012238 at 10012238

void Unwind_10012238(void)

{
  FUN_100011a9();
  return;
}



// Function: Unwind@10012261 at 10012261

void Unwind_10012261(void)

{
  int unaff_EBP;
  
  FUN_100079c4(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012269 at 10012269

void Unwind_10012269(void)

{
  int unaff_EBP;
  
  FUN_1000827e(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: FUN_10012389 at 10012389

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10012389(void)

{
  _DAT_10020abc = ATL::CComModule::vftable;
  FUN_10002fa3(0x10020abc);
  return;
}



// Function: FUN_100123b3 at 100123b3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100123b3(void)

{
  FUN_1000a43f(&DAT_10020aec);
  return;
}



// Function: FUN_100123d3 at 100123d3

void FUN_100123d3(void)

{
  FID_conflict__Tidy(&DAT_10020b34,'\x01',0);
  return;
}



// Function: FUN_100123e2 at 100123e2

void FUN_100123e2(void)

{
  FID_conflict__Tidy(&DAT_10020b18,'\x01',0);
  return;
}



// Function: FUN_100123f1 at 100123f1

void FUN_100123f1(void)

{
  FID_conflict__Tidy(&DAT_10020afc,'\x01',0);
  return;
}



// Function: FUN_10012400 at 10012400

void FUN_10012400(void)

{
  FID_conflict__Tidy(&DAT_10020b50,'\x01',0);
  return;
}



// Function: FUN_1001240f at 1001240f

void FUN_1001240f(void)

{
  FID_conflict__Tidy(&DAT_10020b6c,'\x01',0);
  return;
}



// Function: FUN_1001241e at 1001241e

void FUN_1001241e(void)

{
  FUN_1000f0c6((int *)&DAT_10020b88);
  return;
}



// Function: FUN_10012428 at 10012428

void FUN_10012428(void)

{
  FUN_1000f1a8(0x10020bb0);
  return;
}



