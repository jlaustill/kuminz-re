/*
 * Decompiled from: SecurityLicenses.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001020 at 10001020

void __fastcall FUN_10001020(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10001030 at 10001030

void FUN_10001030(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&PTR_100154b4,param_2);
  return;
}



// Function: FUN_10001050 at 10001050

undefined4 * __thiscall FUN_10001050(void *this,byte param_1)

{
  *(undefined ***)this = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001080 at 10001080

void __fastcall FUN_10001080(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100010a0 at 100010a0

void __fastcall FUN_100010a0(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_100010b0 at 100010b0

void __fastcall FUN_100010b0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012408;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_1001d274 ^ (uint)&stack0xfffffffc,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001100 at 10001100

void __fastcall FUN_10001100(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011929;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001150 at 10001150

exception * __thiscall FUN_10001150(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011959;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_100011b0 at 100011b0

void FUN_100011b0(void)

{
  return;
}



// Function: FUN_100011c0 at 100011c0

void __fastcall FUN_100011c0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011988;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001210 at 10001210

void * __cdecl FUN_10001210(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100119e9;
  local_10 = ExceptionList;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  ExceptionList = &local_10;
  if ((param_1 < (char *)0x80000000) &&
     (pvVar1 = operator_new((int)param_1 * 2), pvVar1 != (void *)0x0)) {
    ExceptionList = local_10;
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10017f24);
}



// Function: FUN_100012a0 at 100012a0

exception * __thiscall FUN_100012a0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011959;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10001300 at 10001300

void __fastcall FUN_10001300(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100119b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_1001d274 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001350 at 10001350

void * __cdecl FUN_10001350(IMAGE_DOS_HEADER *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100119e9;
  local_10 = ExceptionList;
  if (param_1 == (IMAGE_DOS_HEADER *)0x0) {
    return (void *)0x0;
  }
  ExceptionList = &local_10;
  if ((param_1 < &IMAGE_DOS_HEADER_10000000) &&
     (pvVar1 = operator_new((int)param_1 << 4), pvVar1 != (void *)0x0)) {
    ExceptionList = local_10;
    return pvVar1;
  }
  param_1 = (IMAGE_DOS_HEADER *)0x0;
  std::exception::exception((exception *)local_1c,(char **)&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10017f24);
}



// Function: FUN_100013e0 at 100013e0

void __fastcall FUN_100013e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011a23;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001440 at 10001440

undefined4 FUN_10001440(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011a58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  uVar1 = (**(code **)*param_1)(param_1,param_2,&local_14,DAT_1001d274 ^ (uint)&stack0xfffffffc);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_100014b0 at 100014b0

void __cdecl FUN_100014b0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
  }
  return;
}



// Function: FUN_10001520 at 10001520

void __fastcall FUN_10001520(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_10001550 at 10001550

int * __thiscall FUN_10001550(void *this,uint param_1,uint param_2)

{
  void *pvVar1;
  uint extraout_EAX;
  uint uVar2;
  int iVar3;
  uint extraout_ECX;
  void *pvVar4;
  
  uVar2 = *(uint *)((int)this + 0x10);
  if (uVar2 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
    param_1 = extraout_ECX;
  }
  uVar2 = uVar2 - param_1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  if (param_2 != 0) {
    pvVar4 = this;
    pvVar1 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar1 = *this;
    }
    memmove((void *)((int)pvVar4 + param_1 * 2),(void *)((int)pvVar1 + (param_1 + param_2) * 2),
            (uVar2 - param_2) * 2);
    iVar3 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar3;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + iVar3 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + iVar3 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_100015e0 at 100015e0

void __thiscall FUN_100015e0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011ab0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = param_1 | 7;
  if (uVar3 < 0x7fffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = uVar2 + uVar1, 0x7ffffffe - uVar2 < uVar1)) {
      param_1 = 0x7ffffffe;
    }
  }
  local_8 = 0;
  FUN_10001210((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_100016a0();
  return;
}



// Function: Catch@1000166e at 1000166e

undefined * Catch_1000166e(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001210((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10001697;
}



// Function: FUN_100016a0 at 100016a0

void FUN_100016a0(void)

{
  undefined4 *_Src;
  int iVar1;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  undefined4 *unaff_EDI;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if (iVar1 != 0) {
    _Src = unaff_EDI;
    if (7 < (uint)unaff_EDI[5]) {
      _Src = (undefined4 *)*unaff_EDI;
    }
    memcpy(unaff_EBX,_Src,iVar1 * 2);
    iVar1 = *(int *)(unaff_EBP + 0xc);
  }
  if (7 < (uint)unaff_EDI[5]) {
    operator_delete((void *)*unaff_EDI);
    iVar1 = *(int *)(unaff_EBP + 0xc);
  }
  *unaff_EDI = unaff_EBX;
  unaff_EDI[5] = unaff_ESI;
  unaff_EDI[4] = iVar1;
  if (7 < unaff_ESI) {
    unaff_EDI = unaff_EBX;
  }
  *(undefined2 *)((int)unaff_EDI + iVar1 * 2) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch@10001701 at 10001701

void Catch_10001701(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  if (7 < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 7;
  puVar1[4] = 0;
  *(undefined2 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001730 at 10001730

void __fastcall FUN_10001730(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011adb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandlerException::vftable;
  local_8 = 0xffffffff;
  if (7 < (uint)param_1[9]) {
    operator_delete((void *)param_1[4]);
  }
  param_1[9] = 7;
  param_1[8] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_100017a0 at 100017a0

undefined4 * __thiscall FUN_100017a0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011adb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  local_8 = 0xffffffff;
  if (7 < *(uint *)((int)this + 0x24)) {
    operator_delete(*(void **)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001820 at 10001820

undefined4 * __cdecl
FUN_10001820(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011b00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_100014b0(param_4,param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}



// Function: Catch@10001899 at 10001899

void Catch_10001899(void)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100018b0 at 100018b0

int * __thiscall FUN_100018b0(void *this,int *param_1,uint param_2,uint param_3)

{
  size_t _Size;
  void *_Dst;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar1;
  uint uVar2;
  
  uVar2 = param_1[4];
  piVar1 = param_1;
  if (uVar2 < param_2) {
    std::_Xout_of_range("invalid string position");
    piVar1 = extraout_ECX;
  }
  uVar2 = uVar2 - param_2;
  if (param_3 < uVar2) {
    uVar2 = param_3;
  }
  if ((int *)this == piVar1) {
    FUN_10001550(this,uVar2 + param_2,0xffffffff);
    FUN_10001550(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_100015e0(this,uVar2);
    piVar1 = param_1;
    if (uVar2 == 0) {
      return (int *)this;
    }
  }
  else if (uVar2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    *(undefined2 *)this = 0;
    return (int *)this;
  }
  if (7 < (uint)piVar1[5]) {
    piVar1 = (int *)*piVar1;
  }
  _Dst = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    _Dst = *this;
  }
  _Size = uVar2 * 2;
  memcpy(_Dst,(void *)((int)piVar1 + param_2 * 2),_Size);
  *(uint *)((int)this + 0x10) = uVar2;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)(_Size + (int)this) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(_Size + *this) = 0;
  return (int *)this;
}



// Function: FUN_100019b0 at 100019b0

int * __thiscall FUN_100019b0(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  size_t _Size;
  int *piVar2;
  void *pvVar3;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    piVar2 = (int *)this;
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
    }
    if (piVar2 <= param_1) {
      pvVar3 = this;
      if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
      }
      if (param_1 < (int *)((int)pvVar3 + *(int *)((int)this + 0x10) * 2)) {
        pvVar3 = this;
        if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
          pvVar3 = *this;
        }
        piVar2 = FUN_100018b0(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_100015e0(this,param_2);
    if (param_2 == 0) {
      return (int *)this;
    }
  }
  else if (param_2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    *(undefined2 *)this = 0;
    return (int *)this;
  }
  pvVar3 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar3 = *this;
  }
  _Size = param_2 * 2;
  memcpy(pvVar3,param_1,_Size);
  *(uint *)((int)this + 0x10) = param_2;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)(_Size + (int)this) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(_Size + *this) = 0;
  return (int *)this;
}



// Function: FUN_10001ab0 at 10001ab0

void __thiscall FUN_10001ab0(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_10001820(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_10001ae0 at 10001ae0

void __thiscall FUN_10001ae0(void *this,IMAGE_DOS_HEADER *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011b20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((IMAGE_DOS_HEADER *)0xfffffff < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((IMAGE_DOS_HEADER *)(*(int *)((int)this + 8) - *this >> 4) < param_1) {
    puVar3 = (undefined4 *)FUN_10001350(param_1);
    local_8 = 0;
                    /* WARNING: Load size is inaccurate */
    FUN_10001ab0(this,*this,*(undefined4 **)((int)this + 4),puVar3);
    local_8 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    iVar2 = *(int *)((int)this + 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(undefined4 **)((int)this + 8) = puVar3 + (int)param_1 * 4;
    *(uint *)((int)this + 4) = (iVar2 - (int)pvVar1 & 0xfffffff0U) + (int)puVar3;
    *(undefined4 **)this = puVar3;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@10001b9d at 10001b9d

void Catch_10001b9d(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10001bc0 at 10001bc0

undefined4 * __thiscall FUN_10001bc0(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011b4b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  FUN_100018b0((undefined2 *)((int)this + 0x10),(int *)(param_1 + 0x10),0,0xffffffff);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001c50 at 10001c50

void __fastcall FUN_10001c50(_Container_base0 *param_1)

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



// Function: FUN_10001c80 at 10001c80

void __thiscall FUN_10001c80(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_EAX;
  IMAGE_DOS_HEADER *pIVar3;
  void *extraout_ECX;
  int extraout_EDX;
  IMAGE_DOS_HEADER *pIVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  uVar2 = *(int *)((int)this + 4) - iVar1 >> 4;
  if (0xfffffffU - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    uVar2 = extraout_EAX;
    this = extraout_ECX;
    param_1 = extraout_EDX;
  }
  pIVar3 = (IMAGE_DOS_HEADER *)(uVar2 + param_1);
  pIVar4 = (IMAGE_DOS_HEADER *)(*(int *)((int)this + 8) - iVar1 >> 4);
  if (pIVar4 < pIVar3) {
    if ((IMAGE_DOS_HEADER *)(0xfffffff - ((uint)pIVar4 >> 1)) < pIVar4) {
      pIVar4 = (IMAGE_DOS_HEADER *)0x0;
    }
    else {
      pIVar4 = (IMAGE_DOS_HEADER *)(pIVar4->e_magic + ((uint)pIVar4 >> 1));
    }
    if (pIVar4 < pIVar3) {
      pIVar4 = pIVar3;
    }
    FUN_10001ae0(this,pIVar4);
  }
  return;
}



// Function: FUN_10001ce0 at 10001ce0

void FUN_10001ce0(undefined4 param_1,undefined4 param_2)

{
  undefined **local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined2 local_64 [8];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined **local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34 [8];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011b88;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = CComErrorHandlerException::vftable;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  local_8 = 0;
  local_40 = param_1;
  local_3c = 0;
  local_38 = param_2;
  FUN_100019b0(local_34,(int *)&PTR_10015500,0);
  local_18 = 0;
  local_8 = 1;
  local_6c = local_3c;
  local_70 = local_40;
  local_74 = CComErrorHandlerException::vftable;
  local_68 = local_38;
  local_50 = 7;
  local_54 = 0;
  local_64[0] = 0;
  FUN_100018b0(local_64,(int *)local_34,0,0xffffffff);
  local_48 = local_18;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_74,(ThrowInfo *)&DAT_10018200);
}



// Function: FUN_10001db0 at 10001db0

void __thiscall FUN_10001db0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100134b2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar2) && (puVar1 = *this, puVar1 <= param_1)) {
    if (puVar2 == *(undefined4 **)((int)this + 8)) {
      FUN_10001c80(this,1);
    }
    puVar2 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)(((int)param_1 - (int)puVar1 & 0xfffffff0U) + *this);
  }
  else {
    if (puVar2 == *(undefined4 **)((int)this + 8)) {
      FUN_10001c80(this,1);
    }
    puVar2 = *(undefined4 **)((int)this + 4);
  }
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    puVar2[2] = param_1[2];
    puVar2[3] = param_1[3];
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x10;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001e70 at 10001e70

int __fastcall FUN_10001e70(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011bd9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  local_8 = 3;
  FUN_10001db0((void *)(param_1 + 0x30),(undefined4 *)&DAT_10015574);
  FUN_10001db0((void *)(param_1 + 0x30),(undefined4 *)&DAT_10015584);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001f10 at 10001f10

void __thiscall FUN_10001f10(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  if ((*(char *)((int)this + 4) == '\0') && (param_1 < 0)) {
    *(undefined1 *)((int)this + 4) = 1;
    FUN_10001ce0(param_1,*(undefined4 *)((int)this + 8));
  }
  return;
}



// Function: FUN_10001f40 at 10001f40

undefined4 FUN_10001f40(int param_1,undefined4 param_2,undefined4 param_3)

{
  HRESULT HVar1;
  int iVar2;
  IID *rclsid;
  uint local_40;
  undefined **local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  IID *local_20;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011c18;
  local_10 = ExceptionList;
  local_40 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&local_40;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = 0;
  local_30 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_24 = 0x80004005;
  local_18 = (int *)0x0;
  local_8 = 3;
  local_1c = 0;
  rclsid = *(IID **)(param_1 + 0x28);
  do {
    local_20 = rclsid;
    if ((short)local_1c != 0) {
LAB_1000200f:
      iVar2 = FUN_10001030(local_18,param_3);
      FUN_10001f10(&local_30,iVar2);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_10001300((int *)&local_18);
      ExceptionList = local_10;
      return local_24;
    }
    if (rclsid == *(IID **)(param_1 + 0x2c)) {
      FUN_10001f10(&local_30,-0x7ff8ffa9);
      goto LAB_1000200f;
    }
    FUN_10001000((int *)&local_18);
    HVar1 = CoCreateInstance(rclsid,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10015488,&local_18);
    FUN_10001f10(&local_30,HVar1);
    iVar2 = (**(code **)(*local_18 + 0x10))(local_18,param_2,&local_1c);
    FUN_10001f10(&local_30,iVar2);
    rclsid = rclsid + 1;
  } while( true );
}



// Function: Catch@1000205d at 1000205d

undefined4 Catch_1000205d(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10002038;
}



// Function: FUN_10002070 at 10002070

bool __cdecl FUN_10002070(byte *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0x10;
  do {
    if (*(int *)param_1 != *(int *)param_2) {
      iVar2 = (uint)*param_1 - (uint)*param_2;
      if (((iVar2 == 0) && (iVar2 = (uint)param_1[1] - (uint)param_2[1], iVar2 == 0)) &&
         (iVar2 = (uint)param_1[2] - (uint)param_2[2], iVar2 == 0)) {
        iVar2 = (uint)param_1[3] - (uint)param_2[3];
      }
      return (iVar2 >> 0x1f | 1U) == 0;
    }
    uVar1 = uVar1 - 4;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
  } while (3 < uVar1);
  return true;
}



// Function: AtlMultiply<unsigned_long> at 10002100

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



// Function: FUN_10002130 at 10002130

bool __cdecl FUN_10002130(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_10002160 at 10002160

void FUN_10002160(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10018324);
}



// Function: FUN_10002180 at 10002180

void __cdecl FUN_10002180(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  case 0xc:
    FUN_10002160(0x8007000e);
  case 0x16:
  case 0x22:
    FUN_10002160(0x80070057);
  default:
    FUN_10002160(0x80004005);
    return;
  }
}



// Function: FUN_10002240 at 10002240

void __cdecl FUN_10002240(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  case 0xc:
    FUN_10002160(0x8007000e);
  case 0x16:
  case 0x22:
    FUN_10002160(0x80070057);
  default:
    FUN_10002160(0x80004005);
    return;
  }
}



// Function: FUN_100022f0 at 100022f0

void __cdecl FUN_100022f0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  case 0xc:
    FUN_10002160(0x8007000e);
  case 0x16:
  case 0x22:
    FUN_10002160(0x80070057);
  default:
    FUN_10002160(0x80004005);
    return;
  }
}



// Function: FUN_100023b0 at 100023b0

void __cdecl FUN_100023b0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscat_s(param_1,param_2,param_3);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  case 0xc:
    FUN_10002160(0x8007000e);
  case 0x16:
  case 0x22:
    FUN_10002160(0x80070057);
  default:
    FUN_10002160(0x80004005);
    return;
  }
}



// Function: FUN_10002460 at 10002460

uint __fastcall FUN_10002460(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  uint uVar2;
  
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
    if (0 < (int)uVar2) {
      return uVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10002490 at 10002490

DWORD FUN_10002490(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_100024b0 at 100024b0

uint __cdecl FUN_100024b0(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_100024d0 at 100024d0

int __thiscall
FUN_100024d0(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,LPWSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x10002532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegCreateKeyExW(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                              param_9);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedW");
      if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
        iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                          *this,0);
        return iVar2;
      }
    }
  }
  return 1;
}



// Function: FUN_10002550 at 10002550

int __thiscall FUN_10002550(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x1000259a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegDeleteKeyW(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW");
      if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
        iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0);
        return iVar2;
      }
    }
  }
  return 1;
}



// Function: FUN_100025b0 at 100025b0

undefined4 __fastcall FUN_100025b0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100025c0 at 100025c0

void __cdecl FUN_100025c0(short *param_1,int param_2,short *param_3)

{
  uint uVar1;
  short *psVar2;
  
  if (param_2 != 0) {
    uVar1 = 0;
    psVar2 = param_1;
    if (param_2 != 1) {
      do {
        psVar2 = param_1;
        if (*param_3 == 0) break;
        *param_1 = *param_3;
        psVar2 = param_1 + 1;
        if ((*param_3 == 0x27) && (uVar1 = uVar1 + 1, uVar1 < param_2 - 1U)) {
          *psVar2 = 0x27;
          psVar2 = param_1 + 2;
        }
        uVar1 = uVar1 + 1;
        param_3 = param_3 + 1;
        param_1 = psVar2;
      } while (uVar1 < param_2 - 1U);
    }
    *psVar2 = 0;
  }
  return;
}



// Function: FUN_10002620 at 10002620

void __thiscall FUN_10002620(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(void **)((int)this + 8) != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    FUN_10002550(*(void **)((int)this + 8),*this,param_1);
    return;
  }
  if (DAT_1001d2b4 == '\0') {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_1001d2b0 = GetProcAddress(hModule,"RegDeleteKeyExW");
    }
    DAT_1001d2b4 = '\x01';
  }
  if (DAT_1001d2b0 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
    (*DAT_1001d2b0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    return;
  }
                    /* WARNING: Load size is inaccurate */
  RegDeleteKeyW(*this,param_1);
  return;
}



// Function: FUN_100026a0 at 100026a0

void __fastcall FUN_100026a0(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    return;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_100026d0 at 100026d0

void __thiscall
FUN_100026d0(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
            LPSECURITY_ATTRIBUTES param_6,undefined4 *param_7)

{
  int iVar1;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  if (*(void **)((int)this + 8) == (void *)0x0) {
    iVar1 = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,
                            (LPDWORD)&param_6);
  }
  else {
    iVar1 = FUN_100024d0(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,param_6
                         ,&local_8,(LPDWORD)&param_6);
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_6;
  }
  if (iVar1 == 0) {
                    /* WARNING: Load size is inaccurate */
    if (*this != (HKEY)0x0) {
      RegCloseKey(*this);
      *(undefined4 *)this = 0;
    }
    *(HKEY *)this = local_8;
    *(uint *)((int)this + 4) = param_5 & 0x300;
  }
  return;
}



// Function: FUN_10002770 at 10002770

void __thiscall FUN_10002770(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int *piVar1;
  HMODULE hModule;
  int iVar2;
  FARPROC pFVar3;
  HKEY local_8;
  
  piVar1 = *(int **)((int)this + 8);
  local_8 = (HKEY)0x0;
  if (piVar1 == (int *)0x0) {
LAB_100027da:
    iVar2 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    if (*piVar1 == 0) {
      if (piVar1[1] != 0) goto LAB_100027da;
    }
    else {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        iVar2 = 1;
        goto LAB_100027ef;
      }
      pFVar3 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
      if (pFVar3 != (FARPROC)0x0) {
        iVar2 = (*pFVar3)(param_1,param_2,0,param_3,&local_8,*piVar1,0);
        goto LAB_100027ef;
      }
    }
    iVar2 = 1;
  }
LAB_100027ef:
  if (iVar2 == 0) {
                    /* WARNING: Load size is inaccurate */
    if (*this != (HKEY)0x0) {
      RegCloseKey(*this);
      *(undefined4 *)this = 0;
    }
    *(HKEY *)this = local_8;
    *(uint *)((int)this + 4) = param_3 & 0x300;
  }
  return;
}



// Function: FUN_10002820 at 10002820

void __thiscall FUN_10002820(void *this,LPCWSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExW(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_10002840 at 10002840

LSTATUS __thiscall FUN_10002840(void *this,LPCWSTR param_1,LPCWSTR param_2,DWORD param_3)

{
  int iVar1;
  LSTATUS LVar2;
  
  if (param_2 == (LPCWSTR)0x0) {
    return 0xd;
  }
  iVar1 = lstrlenW(param_2);
                    /* WARNING: Load size is inaccurate */
  LVar2 = RegSetValueExW(*this,param_1,0,param_3,(BYTE *)param_2,iVar1 * 2 + 2);
  return LVar2;
}



// Function: FUN_10002880 at 10002880

LSTATUS __thiscall FUN_10002880(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  int iVar1;
  LSTATUS LVar2;
  LPCWSTR lpString;
  DWORD cbData;
  
  if (param_2 == (LPCWSTR)0x0) {
    return 0xd;
  }
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
  return LVar2;
}



// Function: FUN_100028e0 at 100028e0

undefined4 __fastcall FUN_100028e0(undefined4 *param_1)

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



// Function: FUN_10002910 at 10002910

void __fastcall FUN_10002910(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10002920 at 10002920

undefined4 __thiscall FUN_10002920(void *this,void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  LPVOID pvVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this + 1 + param_2;
  if ((*this < iVar1) && (param_2 < iVar1)) {
    if (*(int *)((int)this + 4) <= iVar1) {
      do {
        iVar2 = *(int *)((int)this + 4);
        if (0x3fffffff < iVar2) {
          return 0;
        }
        iVar3 = iVar2 * 2;
        *(int *)((int)this + 4) = iVar3;
      } while (iVar3 <= iVar1);
      if (iVar3 < 0) {
        return 0;
      }
      pvVar4 = CoTaskMemRealloc(*(LPVOID *)((int)this + 8),iVar2 * 4);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10002180((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_100029d0 at 100029d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100029d0(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011c4e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  if ((DAT_1001d2d8 & 1) == 0) {
    DAT_1001d2d8 = DAT_1001d2d8 | 1;
    DAT_1001d2bc = 8;
    DAT_1001d2b8 = &DAT_10015434;
    DAT_1001d2c0 = &DAT_10015430;
    _DAT_1001d2c4 = 0x4008;
    _DAT_1001d2c8 = &DAT_1001542c;
    _DAT_1001d2cc = 0x13;
    _DAT_1001d2d0 = &DAT_10015428;
    _DAT_1001d2d4 = 0x11;
  }
  local_8 = 0xffffffff;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&DAT_1001d2b8)[uVar2 * 2]);
    if (iVar1 == 0) {
      *param_2 = (&DAT_1001d2bc)[uVar2 * 4];
      ExceptionList = local_10;
      return 1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 4);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10002ac0 at 10002ac0

uint __cdecl FUN_10002ac0(ushort param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  uVar1 = uVar2 - 0x30;
  switch(uVar2) {
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    goto switchD_10002ad6_caseD_30;
  default:
    uVar1 = uVar1 & 0xffffff00;
switchD_10002ad6_caseD_30:
    return uVar1;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
    return uVar2 - 0x37;
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
    return uVar2 - 0x57;
  }
}



// Function: FUN_10002b40 at 10002b40

LPCWSTR __cdecl FUN_10002b40(LPCWSTR param_1,WCHAR param_2)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  
  if (param_1 == (LPCWSTR)0x0) {
    return param_1;
  }
  WVar1 = *param_1;
  pWVar2 = (LPCWSTR)0x0;
  if (WVar1 != L'\0') {
    while (pWVar2 = param_1, WVar1 != param_2) {
      param_1 = CharNextW(param_1);
      WVar1 = *param_1;
      if (WVar1 == L'\0') {
        return (LPCWSTR)0x0;
      }
    }
  }
  return pWVar2;
}



// Function: FUN_10002b90 at 10002b90

void __fastcall FUN_10002b90(undefined4 *param_1)

{
  LPWSTR pWVar1;
  
  do {
    switch(*(LPCWSTR)*param_1) {
    case L'\t':
    case L'\n':
    case L'\r':
    case L' ':
      pWVar1 = CharNextW((LPCWSTR)*param_1);
      *param_1 = pWVar1;
      break;
    default:
      return;
    }
  } while( true );
}



// Function: FUN_10002bf0 at 10002bf0

undefined4 __thiscall FUN_10002bf0(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  LPWSTR pWVar3;
  short *psVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 *puVar7;
  code *pcVar8;
  int iVar9;
  
  FUN_10002b90((undefined4 *)this);
  pcVar8 = CharNextW_exref;
                    /* WARNING: Load size is inaccurate */
  WVar1 = **this;
  if (WVar1 == L'\0') {
    return 0x80020009;
  }
  puVar7 = param_1;
  if (WVar1 == L'\'') {
    pWVar3 = CharNextW(*this);
    *(LPWSTR *)this = pWVar3;
    WVar1 = *pWVar3;
    while( true ) {
                    /* WARNING: Load size is inaccurate */
      if ((WVar1 == L'\0') ||
         ((**this == 0x27 && (psVar4 = (short *)(*pcVar8)(*this), *psVar4 != 0x27)))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == 0) {
          return 0x80020009;
        }
        *puVar7 = 0;
                    /* WARNING: Load size is inaccurate */
        uVar5 = (*pcVar8)(*this);
        *(undefined4 *)this = uVar5;
        return 0;
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == 0x27) {
        uVar5 = (*pcVar8)(*this);
        *(undefined4 *)this = uVar5;
      }
                    /* WARNING: Load size is inaccurate */
      pWVar2 = *this;
      pWVar3 = CharNextW(pWVar2);
      *(LPWSTR *)this = pWVar3;
      iVar6 = (int)pWVar3 - (int)pWVar2 >> 1;
      if (param_1 + 0x1000 <= puVar7 + iVar6 + 1) break;
      if (0 < iVar6) {
        iVar9 = (int)pWVar2 - (int)puVar7;
        do {
          *puVar7 = *(undefined2 *)(iVar9 + (int)puVar7);
          puVar7 = puVar7 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
                    /* WARNING: Load size is inaccurate */
      WVar1 = **this;
      pcVar8 = CharNextW_exref;
    }
    return 0x80020009;
  }
  do {
                    /* WARNING: Load size is inaccurate */
    pWVar2 = *this;
    switch(*pWVar2) {
    case L'\t':
    case L'\n':
    case L'\r':
    case L' ':
      goto switchD_10002ce4_caseD_9;
    }
    pWVar3 = CharNextW(pWVar2);
    *(LPWSTR *)this = pWVar3;
    iVar6 = (int)pWVar3 - (int)pWVar2 >> 1;
    if (param_1 + 0x1000 <= puVar7 + iVar6 + 1) {
      return 0x80020009;
    }
    if (0 < iVar6) {
      iVar9 = (int)pWVar2 - (int)puVar7;
      do {
        *puVar7 = *(undefined2 *)(iVar9 + (int)puVar7);
        puVar7 = puVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
                    /* WARNING: Load size is inaccurate */
  } while (**this != 0);
switchD_10002ce4_caseD_9:
  *puVar7 = 0;
  return 0;
}



// Function: FUN_10002d60 at 10002d60

undefined4 FUN_10002d60(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_10015458;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x10015488);
  return 1;
}



// Function: FUN_10002da0 at 10002da0

bool FUN_10002da0(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  if (LVar1 != 0) {
    return false;
  }
  return local_8 != 0;
}



// Function: FUN_10002df0 at 10002df0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10002df0(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10002bf0(this,param_1), -1 < iVar1)) {
    FUN_10002b90((undefined4 *)this);
    iVar1 = FUN_10002bf0(this,local_2008);
    if (-1 < iVar1) {
      FUN_10002bf0(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002e60 at 10002e60

void FUN_10002e60(void)

{
  WCHAR WVar1;
  LPCWSTR in_EAX;
  
  if (in_EAX != (LPCWSTR)0x0) {
    WVar1 = *in_EAX;
    while (WVar1 != L'\0') {
      in_EAX = CharNextW(in_EAX);
      WVar1 = *in_EAX;
    }
    return;
  }
  return;
}



// Function: FUN_10002ea0 at 10002ea0

int FUN_10002ea0(void)

{
  WCHAR WVar1;
  LPCWSTR lpsz;
  LPWSTR pWVar2;
  LPCWSTR unaff_EBX;
  LPCWSTR pWVar3;
  
  if (unaff_EBX == (LPCWSTR)0x0) {
    return 0;
  }
  WVar1 = *unaff_EBX;
  lpsz = unaff_EBX;
  pWVar3 = unaff_EBX;
  while (WVar1 != L'\0') {
    pWVar2 = CharNextW(lpsz);
    WVar1 = *lpsz;
    if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
      pWVar3 = pWVar2;
    }
    lpsz = pWVar2;
    WVar1 = *pWVar2;
  }
  return (int)pWVar3 - (int)unaff_EBX >> 1;
}



// Function: FUN_10002ef0 at 10002ef0

undefined4 __thiscall FUN_10002ef0(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_1001d290 = *param_3;
    DAT_1001d294 = param_3[1];
    DAT_1001d298 = param_3[2];
    DAT_1001d29c = param_3[3];
  }
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      iVar1 = *param_1;
    }
  }
  piVar2 = DAT_1001d334;
  if (DAT_1001d334 < DAT_1001d338) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_1001d338);
  }
  return 0;
}



// Function: FUN_10002f70 at 10002f70

void FUN_10002f70(int param_1)

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



// Function: FUN_10002fd0 at 10002fd0

void __fastcall FUN_10002fd0(int *param_1)

{
  int iVar1;
  int *_Memory;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
    iVar1 = *param_1;
  }
  return;
}



// Function: FUN_10003000 at 10003000

void __fastcall FUN_10003000(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10003010 at 10003010

void __fastcall FUN_10003010(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10003020 at 10003020

void __thiscall FUN_10003020(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_10002160(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: DllCanUnloadNow at 10003050

HRESULT DllCanUnloadNow(void)

{
                    /* 0x3050  1  DllCanUnloadNow */
  return (uint)(DAT_1001d2e4 != 0);
}



// Function: FUN_10003060 at 10003060

int __fastcall FUN_10003060(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  ((LPCRITICAL_SECTION)(param_1 + 0x10))->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_1001d28c = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_1001d2a0 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_100030d0 at 100030d0

void __fastcall FUN_100030d0(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002f70(param_1 + 4);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_10003120 at 10003120

void __fastcall FUN_10003120(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011c78;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002f70(param_1 + 4);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,uVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100031a0 at 100031a0

void __fastcall FUN_100031a0(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_100031c0 at 100031c0

void __thiscall FUN_100031c0(void *this,LPCWSTR param_1)

{
  int iVar1;
  _FILETIME local_230;
  LPCWSTR local_228;
  DWORD local_224;
  HKEY local_220;
  undefined4 local_21c;
  undefined4 local_218;
  WCHAR local_214 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011cab;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = param_1;
  local_220 = (HKEY)0x0;
  local_21c = 0;
  local_218 = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = FUN_10002770(&local_220,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  if (iVar1 == 0) {
    local_224 = 0x100;
    iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          &local_230);
    while (iVar1 == 0) {
      iVar1 = FUN_100031c0(&local_220,local_214);
      if (iVar1 != 0) goto LAB_1000322f;
      local_224 = 0x100;
      iVar1 = RegEnumKeyExW(local_220,0,local_214,&local_224,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_230);
    }
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
    local_21c = 0;
    FUN_10002620(this,local_228);
    local_8 = 0xffffffff;
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
  }
  else {
LAB_1000322f:
    local_8 = 0xffffffff;
    if (local_220 != (HKEY)0x0) {
      RegCloseKey(local_220);
      local_220 = (HKEY)0x0;
    }
  }
  local_21c = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003350 at 10003350

undefined4 __fastcall FUN_10003350(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1[2]) {
    do {
      if (((iVar3 < 0) || (param_1[2] <= iVar3)) ||
         (operator_delete__(*(void **)(*param_1 + iVar3 * 4)), param_1[2] <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return uVar2;
      }
      operator_delete__(*(void **)(param_1[1] + iVar3 * 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[2]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  return 0;
}



// Function: FUN_100033e0 at 100033e0

void __thiscall FUN_100033e0(void *this,LPCWSTR param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011ce8;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  iVar1 = lstrlenW(param_1);
  FUN_10002920(this,param_1,iVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003460 at 10003460

void FUN_10003460(int param_1)

{
  FUN_10003350((int *)(param_1 + 4));
  return;
}



// Function: FUN_10003480 at 10003480

void FUN_10003480(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int local_240;
  WCHAR local_23c [270];
  wchar_t local_20 [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011d1b;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_1000364d;
  *param_3 = 0;
  *param_4 = 0;
  local_240 = 0;
  local_8 = 0;
  DVar3 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar3 == 0) {
    FUN_10002490();
  }
  else {
    if (DVar3 == 0x104) {
      local_8 = 0xffffffff;
      FUN_10002fd0(&local_240);
      goto LAB_1000364d;
    }
    pwVar4 = (wchar_t *)FUN_10002e60();
    if (param_2 != (LPCWSTR)0x0) {
      uVar5 = lstrlenW(param_2);
      uVar1 = uVar5 + DVar3;
      if (((DVar3 <= uVar1) && (uVar5 <= uVar1)) && (uVar1 < 0x10e)) {
        FUN_10002240(local_23c + DVar3,0x10e - DVar3,param_2);
        goto LAB_10003590;
      }
LAB_1000362f:
      local_8 = 0xffffffff;
      FUN_10002fd0(&local_240);
      goto LAB_1000364d;
    }
LAB_10003590:
    iVar6 = Ordinal_161(local_23c,param_4,uVar2);
    if (iVar6 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar6 = (int)pwVar4 - (int)local_23c >> 1;
      if (0x104 < iVar6 + 5U) goto LAB_1000362f;
      FUN_10002240(pwVar4,0x10e - iVar6,local_20);
      iVar6 = Ordinal_161(local_23c,param_4);
      if (iVar6 < 0) goto LAB_100034ff;
    }
    uVar7 = Ordinal_2(local_23c);
    *param_3 = uVar7;
  }
LAB_100034ff:
  local_8 = 0xffffffff;
  FUN_10002fd0(&local_240);
LAB_1000364d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003670 at 10003670

void __fastcall FUN_10003670(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x2c);
  if (piVar5 != (int *)0x0) {
    iVar1 = *piVar5;
    while (iVar1 != 0) {
      piVar2 = (int *)piVar5[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar5[4] = 0;
      (*(code *)piVar5[8])(0);
      piVar5 = piVar5 + 9;
      iVar1 = *piVar5;
    }
  }
  piVar5 = DAT_1001d334;
  if (DAT_1001d334 < DAT_1001d338) {
    do {
      if (*piVar5 != 0) {
        (**(code **)(*piVar5 + 0x20))(0);
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 < DAT_1001d338);
  }
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if ((undefined4 *)(param_1 + 4) == (undefined4 *)0x0) {
        RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = *(undefined4 **)(param_1 + 0xc);
      while (puVar4 != (undefined4 *)0x0) {
        (*(code *)*puVar4)(puVar4[1]);
        puVar3 = (undefined4 *)puVar4[2];
        operator_delete(puVar4);
        puVar4 = puVar3;
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar5 = *(int **)(param_1 + 0x28);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))(piVar5);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_10003760 at 10003760

void __fastcall FUN_10003760(undefined4 *param_1)

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



// Function: FUN_100037a0 at 100037a0

undefined4 __thiscall FUN_100037a0(void *this,undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)((int)this + 8)) {
                    /* WARNING: Load size is inaccurate */
    while (iVar2 = lstrcmpiW(*(LPCWSTR *)(*this + iVar4 * 4),(LPCWSTR)*param_1), iVar2 != 0) {
      iVar4 = iVar4 + 1;
      if (*(int *)((int)this + 8) <= iVar4) {
        return 0;
      }
    }
    if (iVar4 != -1) {
      if ((-1 < iVar4) && (iVar4 < *(int *)((int)this + 8))) {
        return *(undefined4 *)(*(int *)((int)this + 4) + iVar4 * 4);
      }
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  return 0;
}



// Function: FUN_10003810 at 10003810

void __fastcall FUN_10003810(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10003830 at 10003830

void __fastcall FUN_10003830(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10003010(param_1);
    return;
  }
  return;
}



// Function: FUN_10003840 at 10003840

void __fastcall FUN_10003840(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10003860 at 10003860

undefined4 FUN_10003860(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10002ef0(&DAT_1001d2dc,(int *)&PTR_DAT_1001c100,param_1,(undefined4 *)&DAT_10015504);
    DisableThreadLibraryCalls(param_1);
    return 1;
  }
  if (param_2 == 0) {
    FUN_10003670(0x1001d2dc);
  }
  return 1;
}



// Function: FUN_100038b0 at 100038b0

DWORD __fastcall FUN_100038b0(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x24),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  *(undefined1 *)(param_1 + 0x3c) = 1;
  if ((int)DVar2 < 0) {
    return DVar2;
  }
  return 0;
}



// Function: FUN_100038f0 at 100038f0

DWORD __fastcall FUN_100038f0(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x20),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  *(undefined1 *)(param_1 + 0x38) = 1;
  if ((int)DVar2 < 0) {
    return DVar2;
  }
  return 0;
}



// Function: FUN_10003930 at 10003930

void __fastcall FUN_10003930(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003940 at 10003940

void __fastcall FUN_10003940(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003950 at 10003950

HRESULT __thiscall FUN_10003950(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_100166e0,(LPUNKNOWN)0x0,1,(IID *)&DAT_10015838,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_100039b0 at 100039b0

undefined4 FUN_100039b0(void)

{
  return 0x80004005;
}



// Function: FUN_100039c0 at 100039c0

void FUN_100039c0(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&PTR_10015500);
  return;
}



// Function: FUN_100039e0 at 100039e0

undefined4 * __thiscall FUN_100039e0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011d60;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (*(int *)((int)this + 4) != 0) {
    if (*(int *)((int)this + 0xc) != 0) {
      FUN_10002f70((int)this + 4);
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    piVar1 = *(int **)((int)this + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,uVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003a80 at 10003a80

void __fastcall FUN_10003a80(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011d88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003350(param_1);
  local_8 = 0xffffffff;
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    free((void *)param_1[1]);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003b00 at 10003b00

void __fastcall FUN_10003b00(undefined4 *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011dc3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  piVar1 = param_1 + 1;
  FUN_10003350(piVar1);
  local_8 = 1;
  FUN_10003350(piVar1);
  local_8 = 0xffffffff;
  if ((void *)*piVar1 != (void *)0x0) {
    free((void *)*piVar1);
    *piVar1 = 0;
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
    param_1[2] = 0;
  }
  param_1[3] = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003ba0 at 10003ba0

undefined4 FUN_10003ba0(void)

{
  return 0x80004001;
}



// Function: FUN_10003bb0 at 10003bb0

undefined4 FUN_10003bb0(void)

{
  return 1;
}



// Function: FUN_10003bc0 at 10003bc0

undefined4 FUN_10003bc0(void)

{
  return 0;
}



// Function: FUN_10003bd0 at 10003bd0

undefined4 * __thiscall FUN_10003bd0(void *this,byte param_1)

{
  FUN_10003b00((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003c00 at 10003c00

void __thiscall FUN_10003c00(void *this,LPCWSTR param_1,undefined4 *param_2)

{
  WCHAR WVar1;
  undefined2 *puVar2;
  wchar_t *pwVar3;
  LPWSTR pWVar4;
  int iVar5;
  LPCWSTR pWVar6;
  rsize_t rVar7;
  LPCWSTR pWVar8;
  wchar_t *local_78;
  undefined4 *local_74;
  undefined4 local_70;
  int local_6c;
  undefined2 *local_68;
  int local_64;
  char local_5d;
  undefined4 local_5c;
  char local_56;
  char local_55;
  wchar_t local_54 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011de8;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_74 = param_2;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    local_6c = lstrlenW(param_1);
    local_6c = local_6c * 2;
    if (local_6c < 100) {
      local_6c = 1000;
    }
    local_70 = 0;
    if (local_6c < 0) {
      local_68 = (undefined2 *)0x0;
    }
    else {
      local_68 = (undefined2 *)CoTaskMemAlloc(local_6c * 2);
    }
    if (local_68 != (undefined2 *)0x0) {
      *local_68 = 0;
    }
    local_8 = 0;
    if (local_68 == (undefined2 *)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5c = 0;
      local_64 = 0;
      local_56 = '\0';
      local_55 = '\0';
      WVar1 = *param_1;
      puVar2 = local_68;
      local_5d = DAT_1001d288;
      while (WVar1 != L'\0') {
        local_68 = puVar2;
        if (local_5d == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if (((local_64 != 0) || (pwVar3 = wcsstr(*this,L"HKCR"), pwVar3 == (wchar_t *)0x0)) ||
             (pwVar3 != *this)) {
LAB_10003d2a:
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x27) {
              if (local_55 == '\0') {
                local_55 = '\x01';
                goto LAB_10003da9;
              }
              iVar5 = FUN_100028e0((undefined4 *)this);
              if (iVar5 == 0) {
                    /* WARNING: Load size is inaccurate */
                pWVar4 = CharNextW(*this);
                *(LPWSTR *)this = pWVar4;
                iVar5 = FUN_10002920(&local_70,pWVar4,1);
                if (iVar5 == 0) goto LAB_10003e76;
                goto LAB_10003d6d;
              }
              local_55 = '\0';
            }
            else {
LAB_10003d6d:
              if (local_55 != '\0') goto LAB_10003da9;
            }
                    /* WARNING: Load size is inaccurate */
            if (**this == 0x7b) {
              local_64 = local_64 + 1;
            }
            if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
               (local_56 == '\x01')) {
              iVar5 = FUN_100033e0(&local_70,L"\r\n\t}\r\n}\r\n");
              if (iVar5 == 0) goto LAB_10003e76;
              local_56 = '\0';
            }
            goto LAB_10003da9;
          }
          pWVar4 = CharNextW(*this);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          pWVar4 = CharNextW(pWVar4);
          *(LPWSTR *)this = pWVar4;
          iVar5 = FUN_100033e0(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
          if (iVar5 != 0) {
            local_56 = '\x01';
            goto LAB_10003d2a;
          }
LAB_10003e76:
          local_5c = 0x8007000e;
          goto LAB_10003e60;
        }
LAB_10003da9:
                    /* WARNING: Load size is inaccurate */
        pWVar6 = *this;
        if (*pWVar6 == L'%') {
          pWVar6 = CharNextW(pWVar6);
          *(LPCWSTR *)this = pWVar6;
          if (*pWVar6 == L'%') goto LAB_10003e2d;
          pWVar6 = FUN_10002b40(pWVar6,L'%');
          if (pWVar6 == (LPCWSTR)0x0) {
LAB_10003e7f:
            local_5c = 0x80020009;
            goto LAB_10003e60;
          }
                    /* WARNING: Load size is inaccurate */
          rVar7 = (int)pWVar6 - (int)*this >> 1;
          if (0x1f < (int)rVar7) {
            local_5c = 0x80004005;
            goto LAB_10003e60;
          }
          FUN_100022f0(local_54,0x20,*this,rVar7);
          local_78 = local_54;
          pWVar8 = (LPCWSTR)FUN_100037a0((void *)(*(int *)((int)this + 4) + 4),&local_78);
          if (pWVar8 == (LPCWSTR)0x0) goto LAB_10003e7f;
          iVar5 = FUN_100033e0(&local_70,pWVar8);
          if (iVar5 == 0) goto LAB_10003e76;
                    /* WARNING: Load size is inaccurate */
          pWVar8 = *this;
          while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
            pWVar8 = CharNextW(*this);
            *(LPCWSTR *)this = pWVar8;
          }
        }
        else {
LAB_10003e2d:
          iVar5 = FUN_10002920(&local_70,pWVar6,1);
          if (iVar5 == 0) goto LAB_10003e76;
        }
                    /* WARNING: Load size is inaccurate */
        pWVar4 = CharNextW(*this);
        *(LPWSTR *)this = pWVar4;
        puVar2 = local_68;
        WVar1 = *pWVar4;
      }
      local_68 = (undefined2 *)0x0;
      local_70 = 0;
      local_6c = 0;
      *local_74 = puVar2;
LAB_10003e60:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003ec0 at 10003ec0

/* WARNING: Removing unreachable block (ram,0x10003f1c) */
/* WARNING: Removing unreachable block (ram,0x10003f69) */

void FUN_10003ec0(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int iVar3;
  code *pcVar4;
  LSTATUS LVar5;
  int local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  HKEY local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  DWORD local_1ac;
  int *local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  OLECHAR local_194 [64];
  wchar_t local_114 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011e7e;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1a8 = (int *)0x0;
  local_8 = 1;
  if (param_2 == (int *)0x0) {
    local_8 = 0xffffffff;
  }
  else if ((((param_1->Data1 == 0) &&
            (iVar3._0_2_ = param_1->Data2, iVar3._2_2_ = param_1->Data3, iVar3 == 0)) &&
           (*(int *)param_1->Data4 == 0)) && (*(int *)(param_1->Data4 + 4) == 0)) {
    local_8 = 0xffffffff;
  }
  else {
    HVar2 = CoCreateInstance((IID *)&DAT_100166b0,(LPUNKNOWN)0x0,1,(IID *)&DAT_10015934,&local_1a8);
    if (HVar2 < 0) {
      local_8 = 0xffffffff;
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))(local_1a8);
      }
    }
    else {
      iVar3 = *param_2;
      while (iVar3 != 0) {
        puVar1 = (undefined4 *)param_2[1];
        local_1a4 = *puVar1;
        local_1a0 = puVar1[1];
        local_19c = puVar1[2];
        local_198 = puVar1[3];
        iVar3 = *local_1a8;
        if (param_3 == 0) {
          if (*param_2 == 1) {
            pcVar4 = *(code **)(iVar3 + 0x18);
          }
          else {
            pcVar4 = *(code **)(iVar3 + 0x20);
          }
          (*pcVar4)(local_1a8,param_1,1,&local_1a4);
        }
        else {
          if (*param_2 == 1) {
            pcVar4 = *(code **)(iVar3 + 0x14);
          }
          else {
            pcVar4 = *(code **)(iVar3 + 0x1c);
          }
          iVar3 = (*pcVar4)();
          if (iVar3 < 0) {
            local_8 = 0xffffffff;
            if (local_1a8 != (int *)0x0) {
              (**(code **)(*local_1a8 + 8))(local_1a8);
            }
            goto LAB_10004230;
          }
        }
        param_2 = param_2 + 2;
        iVar3 = *param_2;
      }
      if (param_3 == 0) {
        StringFromGUID2(param_1,local_194,0x40);
        local_1c8 = 0;
        local_8._0_1_ = 6;
        FUN_10002240(local_114,0x80,L"CLSID\\");
        FUN_100023b0(local_114,0x80,local_194);
        FUN_100023b0(local_114,0x80,L"\\Required Categories");
        local_1c4 = 0x80000000;
        local_1c0 = 0;
        local_1bc = 0;
        local_1b8 = (HKEY)0x0;
        local_1b4 = 0;
        local_1b0 = 0;
        local_8 = CONCAT31(local_8._1_3_,8);
        local_1ac = 0;
        iVar3 = FUN_10002770(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_100026a0(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_10002620(&local_1c4,local_114);
          }
        }
        FUN_10002240(local_114,0x80,L"CLSID\\");
        FUN_100023b0(local_114,0x80,local_194);
        FUN_100023b0(local_114,0x80,L"\\Implemented Categories");
        iVar3 = FUN_10002770(&local_1b8,(HKEY)0x80000000,local_114,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1b8,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_1ac,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(PFILETIME)0x0);
          FUN_100026a0(&local_1b8);
          if ((LVar5 == 0) && (local_1ac == 0)) {
            FUN_10002620(&local_1c4,local_114);
          }
        }
        local_8._0_1_ = 7;
        FUN_100031a0(&local_1b8);
        local_8._0_1_ = 6;
        FUN_100031a0(&local_1c4);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_10002fd0(&local_1c8);
      }
      local_8 = 0xffffffff;
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))(local_1a8);
      }
    }
  }
LAB_10004230:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004270 at 10004270

int FUN_10004270(HMODULE param_1,LPCWSTR param_2)

{
  uint uVar1;
  int iVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10011ed0;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar2 = FUN_10003480(param_1,param_2,&local_18,&local_14);
  if (iVar2 < 0) goto LAB_1000432c;
  iVar2 = (**(code **)(*local_14 + 0x1c))(local_14,&param_2,uVar1);
  if (iVar2 < 0) goto LAB_1000432c;
  if (DAT_1001d288 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_100042fe;
    pFVar3 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar3 == (FARPROC)0x0) goto LAB_100042fe;
  }
  else {
LAB_100042fe:
    pFVar3 = Ordinal_186_exref;
  }
  iVar2 = (*pFVar3)(param_2,(uint)(ushort)param_2[0xc],(uint)(ushort)param_2[0xd],
                    *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 10));
  (**(code **)(*local_14 + 0x30))(local_14,param_2);
LAB_1000432c:
  local_8 = local_8 & 0xffffff00;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10004370 at 10004370

void FUN_10004370(HMODULE param_1,LPCWSTR param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  rsize_t rVar4;
  HMODULE hModule;
  FARPROC pFVar5;
  wchar_t *pwVar6;
  undefined4 local_228;
  wchar_t *local_224;
  int *local_220;
  wchar_t local_21c [259];
  undefined2 local_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10011f27;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_228 = 0;
  local_220 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_14 = uVar2;
  iVar3 = FUN_10003480(param_1,param_2,&local_228,&local_220);
  uVar1 = local_228;
  if (iVar3 < 0) goto LAB_1000449f;
  pwVar6 = (wchar_t *)0x0;
  local_224 = (wchar_t *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = (**(code **)(*local_220 + 0x24))(local_220,0xffffffff,0,0,0,&local_224,uVar2);
  if ((-1 < iVar3) && (local_224 != (wchar_t *)0x0)) {
    rVar4 = Ordinal_7(local_224);
    FUN_100022f0(local_21c,0x104,local_224,rVar4);
    pwVar6 = local_21c;
    local_16 = 0;
    iVar3 = FUN_10002ea0();
    local_21c[iVar3] = L'\0';
  }
  if (DAT_1001d288 == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_1000447c;
    pFVar5 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    if (pFVar5 == (FARPROC)0x0) goto LAB_1000447c;
  }
  else {
LAB_1000447c:
    pFVar5 = Ordinal_163_exref;
  }
  (*pFVar5)(local_220,uVar1,pwVar6);
  local_8._0_1_ = 2;
  Ordinal_6(local_224);
LAB_1000449f:
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_220 != (int *)0x0) {
    (**(code **)(*local_220 + 8))(local_220);
  }
  local_8 = 0xffffffff;
  Ordinal_6(uVar1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100044f0 at 100044f0

int FUN_100044f0(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return -0x7ff8ffa9;
  }
  piVar4 = *(int **)(param_1 + 8);
  iVar5 = 0;
  if (piVar4 < *(int **)(param_1 + 0xc)) {
    do {
      puVar1 = (undefined4 *)*piVar4;
      if ((puVar1 != (undefined4 *)0x0) &&
         ((param_3 == (byte *)0x0 ||
          (bVar2 = FUN_10002070(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar6 = 1;
        iVar5 = (*(code *)puVar1[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)puVar1[7])(1);
        iVar5 = FUN_10003ec0((GUID *)*puVar1,piVar3,iVar6);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 < *(int **)(param_1 + 0xc));
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  if (param_2 != 0) {
    iVar5 = FUN_10004370(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10004580 at 10004580

int FUN_10004580(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return -0x7ff8ffa9;
  }
  piVar4 = *(int **)(param_1 + 8);
  iVar5 = 0;
  if (piVar4 < *(int **)(param_1 + 0xc)) {
    do {
      puVar1 = (undefined4 *)*piVar4;
      if ((puVar1 != (undefined4 *)0x0) &&
         ((param_3 == (byte *)0x0 ||
          (bVar2 = FUN_10002070(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)puVar1[7])();
        iVar5 = FUN_10003ec0((GUID *)*puVar1,piVar3,iVar5);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = (*(code *)puVar1[1])(0);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 < *(int **)(param_1 + 0xc));
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  if (param_2 != 0) {
    iVar5 = FUN_10004270(*(HMODULE *)(param_1 + 4),(LPCWSTR)0x0);
  }
  return iVar5;
}



// Function: FUN_10004610 at 10004610

int FUN_10004610(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  LPCRITICAL_SECTION local_18;
  undefined1 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar3 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011f58;
  local_10 = ExceptionList;
  uVar4 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  if (param_4 == (int *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_4 = 0;
  if (param_1 == (int *)0x0) {
    ExceptionList = pvVar3;
    return -0x7ff8ffa9;
  }
  if (*param_1 == 0) {
    ExceptionList = pvVar3;
    return -0x7fff0001;
  }
  puVar5 = (undefined4 *)param_1[2];
  while( true ) {
    if ((undefined4 *)param_1[3] <= puVar5) {
      ExceptionList = pvVar3;
      return -0x7ffbfeef;
    }
    puVar1 = (undefined4 *)*puVar5;
    if ((((puVar1 != (undefined4 *)0x0) && (puVar1[2] != 0)) &&
        (piVar2 = (int *)*puVar1, *param_2 == *piVar2)) &&
       (((param_2[1] == piVar2[1] && (param_2[2] == piVar2[2])) && (param_2[3] == piVar2[3]))))
    break;
    puVar5 = puVar5 + 1;
  }
  piVar2 = puVar1 + 4;
  iVar6 = 0;
  if (*piVar2 == 0) {
    local_18 = (LPCRITICAL_SECTION)(param_1 + 4);
    local_14 = 0;
    local_8 = 0;
    EnterCriticalSection(local_18);
    local_14 = 1;
    if (*piVar2 == 0) {
      iVar6 = (*(code *)puVar1[2])(puVar1[3],&PTR_100154b4,piVar2);
    }
    local_8 = 0xffffffff;
    FUN_10003840(&local_18);
  }
  if (*piVar2 != 0) {
    iVar6 = (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,param_3,param_4,uVar4);
  }
  if (*param_4 == 0) {
    if (iVar6 == 0) {
      ExceptionList = local_10;
      return -0x7ffbfeef;
    }
    ExceptionList = local_10;
    return iVar6;
  }
  ExceptionList = local_10;
  return iVar6;
}



// Function: FUN_10004770 at 10004770

void __fastcall FUN_10004770(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011f9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 8) != '\0') {
    *(undefined1 *)(param_1 + 8) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100047e0 at 100047e0

undefined4 FUN_100047e0(int *param_1)

{
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    return 1;
  }
  return 0;
}



// Function: FUN_10004820 at 10004820

undefined4 FUN_10004820(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 != 0) &&
       ((((*param_3 != 0 || (param_3[1] != 0)) || (param_3[2] != 0xc0)) ||
        (param_3[3] != 0x46000000)))) {
      return 0x80040110;
    }
    uVar1 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
  }
  return uVar1;
}



// Function: FUN_10004880 at 10004880

undefined4 FUN_10004880(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_1001d28c + 4))();
    return 0;
  }
  (**(code **)(*DAT_1001d28c + 8))();
  return 0;
}



// Function: FUN_100048b0 at 100048b0

undefined4 * __thiscall FUN_100048b0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011fde;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x20) != '\0') {
    *(undefined1 *)((int)this + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 8));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10004930 at 10004930

undefined4 __thiscall FUN_10004930(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012033;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  pvVar2 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar2 != (void *)0x0) {
    *(void **)this = pvVar2;
    pvVar2 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar2 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar2;
      iVar1 = *(int *)((int)this + 8) * 4;
                    /* WARNING: Load size is inaccurate */
      puVar3 = (undefined4 *)(*this + iVar1);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *param_1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)this + 4) + iVar1);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *param_2;
      }
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      ExceptionList = local_10;
      return 1;
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10004a10 at 10004a10

int __thiscall FUN_10004a10(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 * 2;
  if (param_1 < 0) {
    uVar1 = FUN_10002160(0x80070216);
  }
  if (0x400 < uVar1) {
    FUN_10003020(this,uVar1);
                    /* WARNING: Load size is inaccurate */
    return *this;
  }
  *(int *)this = (int)this + 4;
  return (int)this + 4;
}



// Function: FUN_10004a60 at 10004a60

int __thiscall FUN_10004a60(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 * 2;
  if (param_1 < 0) {
    uVar1 = FUN_10002160(0x80070216);
  }
  if (0x100 < uVar1) {
    FUN_10003020(this,uVar1);
                    /* WARNING: Load size is inaccurate */
    return *this;
  }
  *(int *)this = (int)this + 4;
  return (int)this + 4;
}



// Function: FUN_10004ab0 at 10004ab0

/* WARNING: Removing unreachable block (ram,0x10004ac2) */

int __thiscall FUN_10004ab0(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
    return (int)this + 4;
  }
  FUN_10003020(this,param_1);
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10004af0 at 10004af0

undefined4 FUN_10004af0(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012060;
  local_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &local_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_10010d76(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    local_8 = 0xffffffff;
    uVar3 = FUN_10004b86();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10004b74 at 10004b74

undefined * Catch_10004b74(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004b81;
}



// Function: FUN_10004b86 at 10004b86

void FUN_10004b86(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -0x18) = unaff_EBX;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x18) = unaff_EDI;
  iVar3 = lstrlenW(*(LPCWSTR *)(unaff_EBP + 0xc));
  uVar1 = iVar3 * 2 + 2;
  *(uint *)(unaff_EBP + -0x24) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = unaff_EBX;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  lVar2 = (ulonglong)uVar1 * 2;
  uVar4 = FUN_10010d76(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10004bea();
  return;
}



// Function: Catch@10004bd4 at 10004bd4

undefined * Catch_10004bd4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10004be1;
}



// Function: FUN_10004bea at 10004bea

bool FUN_10004bea(void)

{
  int iVar1;
  void *unaff_EBX;
  int unaff_EBP;
  rsize_t unaff_ESI;
  void *unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(void **)(unaff_EBP + -0x24) = unaff_EBX;
  if ((unaff_EDI != (void *)0x0) && (unaff_EBX != (void *)0x0)) {
    FUN_10002180(unaff_EDI,*(rsize_t *)(unaff_EBP + -0x28),*(void **)(unaff_EBP + 8),
                 *(rsize_t *)(unaff_EBP + -0x28));
    FUN_10002180(unaff_EBX,unaff_ESI,*(void **)(unaff_EBP + 0xc),unaff_ESI);
    iVar1 = FUN_10004930(*(void **)(unaff_EBP + -0x2c),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x1c));
    if (iVar1 != 0) {
      unaff_EBX = (void *)0x0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      goto LAB_10004c43;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x20) = 0x8007000e;
LAB_10004c43:
  iVar1 = *(int *)(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(unaff_EBX);
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -1 < iVar1;
}



// Function: FUN_10004ca0 at 10004ca0

int FUN_10004ca0(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012088;
  local_10 = ExceptionList;
  if ((param_2 != (LPCWSTR)0x0) && (param_3 != 0)) {
    local_8 = 0;
    ExceptionList = &local_10;
    iVar1 = FUN_10004af0(param_2,param_3);
    ExceptionList = local_10;
    return (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
  }
  return -0x7ff8ffa9;
}



// Function: FUN_10004d30 at 10004d30

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_10004d30(void *this,void *param_1,LPCWSTR param_2,undefined2 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uStack_2144;
  uint local_2128;
  void *local_2124;
  uint local_2120 [66];
  WCHAR local_2018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100120d1;
  local_10 = ExceptionList;
  uStack_2144 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2120[0] = 0;
  local_18 = uStack_2144;
  iVar1 = FUN_10002bf0(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_100029d0(local_2018,(undefined2 *)local_2120), iVar1 == 0))
  goto LAB_100050b7;
  FUN_10002b90((undefined4 *)this);
  iVar1 = FUN_10002bf0(this,local_2018);
  if (iVar1 < 0) goto LAB_100050b7;
  uVar2 = local_2120[0] & 0xffff;
  if (uVar2 < 0x14) {
    if (uVar2 == 0x13) {
      local_2124 = (void *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      uVar2 = FUN_10002820(param_1,param_2);
      local_8 = 0xffffffff;
      FUN_10002fd0((int *)&local_2124);
    }
    else {
      if (uVar2 != 8) {
        if (uVar2 == 0x11) {
          local_2128 = lstrlenW(local_2018);
          if ((local_2128 & 1) == 0) {
            local_2120[0] = (int)local_2128 / 2;
            local_2120[1] = 0;
            local_8 = 5;
            FUN_10004ab0(local_2120 + 1,local_2120[0]);
            local_8 = 4;
            FUN_10004e7c();
            return;
          }
          goto LAB_100050b7;
        }
        goto LAB_1000509b;
      }
      uVar2 = FUN_10002840(param_1,param_2,local_2018,1);
    }
    if (uVar2 != 0) {
      FUN_100024b0(uVar2);
      goto LAB_100050b7;
    }
  }
  else if (uVar2 == 0x4008) {
    iVar1 = lstrlenW(local_2018);
    local_2120[1] = 0;
    local_8 = 1;
    FUN_10004a60(local_2120 + 1,iVar1 + 2);
    local_8 = 0;
    FUN_10004ff3();
    return;
  }
LAB_1000509b:
  FUN_10002bf0(this,param_3);
LAB_100050b7:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10004e61 at 10004e61

undefined * Catch_10004e61(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10004e6e;
}



// Function: FUN_10004e7c at 10004e7c

void FUN_10004e7c(void)

{
  uint uVar1;
  void *pvVar2;
  int unaff_EBX;
  uint unaff_EBP;
  void *unaff_ESI;
  DWORD unaff_EDI;
  byte *pbVar3;
  undefined4 uStack0000000c;
  
  if (*(void **)(unaff_EBP - 0x2118) == unaff_ESI) {
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_10003010((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),(int)unaff_ESI,unaff_EDI);
    if ((int)unaff_ESI < unaff_EBX) {
      do {
        pbVar3 = (byte *)(((uint)unaff_ESI >> 1) + *(int *)(unaff_EBP - 0x2118));
        uVar1 = FUN_10002ac0(*(ushort *)((unaff_EBP - 0x2014) + (int)unaff_ESI * 2));
        *pbVar3 = *pbVar3 | (char)uVar1 << (((byte)unaff_ESI & 1) * -4 + 4 & 0x1f);
        unaff_ESI = (void *)((int)unaff_ESI + 1);
      } while ((int)unaff_ESI < unaff_EBX);
      unaff_ESI = (void *)0x0;
      unaff_EDI = *(DWORD *)(unaff_EBP - 0x211c);
    }
    pvVar2 = (void *)RegSetValueExW((HKEY)**(undefined4 **)(unaff_EBP - 0x2120),
                                    *(LPCWSTR *)(unaff_EBP - 0x212c),(DWORD)unaff_ESI,3,
                                    *(BYTE **)(unaff_EBP - 0x2118),unaff_EDI);
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_10003010((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (pvVar2 == unaff_ESI) {
      FUN_10002bf0(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
    }
    else {
      FUN_100024b0((uint)pvVar2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100050cf;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10004fe4 at 10004fe4

undefined * Catch_10004fe4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10004ff1;
}



// Function: FUN_10004ff3 at 10004ff3

void FUN_10004ff3(void)

{
  WCHAR WVar1;
  LPWSTR lpsz;
  LPCWSTR lpsz_00;
  WCHAR *pWVar2;
  uint unaff_EBP;
  WCHAR *unaff_ESI;
  undefined4 uStack0000000c;
  
  pWVar2 = *(WCHAR **)(unaff_EBP - 0x2118);
  if (pWVar2 == unaff_ESI) {
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
    pWVar2[0] = L'\0';
    pWVar2[1] = L'\0';
    pWVar2 = (WCHAR *)FUN_10002880(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x212c),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_ESI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_10003010((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_ESI) {
    FUN_10002bf0(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x2130));
  }
  else {
    FUN_100024b0((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100050cf;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100050e0 at 100050e0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100050e0(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  WCHAR WVar1;
  code *pcVar2;
  HKEY pHVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  LPCWSTR pWVar8;
  uint uVar9;
  errno_t eVar10;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar11;
  char *pcVar12;
  HKEY *ppHVar13;
  char extraout_DL;
  undefined **ppuVar14;
  HKEY local_226c;
  undefined4 local_2268;
  undefined4 local_2264;
  HKEY local_2260;
  undefined4 local_225c;
  undefined4 local_2258;
  int local_2254;
  HKEY local_2250;
  undefined4 local_224c;
  undefined4 local_2248;
  int local_2244;
  HKEY local_2240;
  undefined4 local_223c;
  undefined4 local_2238;
  HKEY local_2234;
  uint local_2230;
  HKEY local_222c;
  undefined4 local_2228;
  undefined4 local_2224;
  void *local_2220;
  WCHAR local_221c [4096];
  wchar_t local_21c [260];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10012137;
  local_10 = ExceptionList;
  pcVar5 = (char *)(DAT_1001d274 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_2234 = param_2;
  local_222c = (HKEY)0x0;
  local_2228 = 0;
  local_2224 = 0;
  local_8 = 0;
  local_2254 = param_4;
  local_2220 = this;
  local_14 = pcVar5;
  iVar6 = FUN_10002bf0(this,param_1);
  if (iVar6 < 0) {
    local_8 = 0xffffffff;
  }
  else {
    if (*param_1 != L'}') {
LAB_10005170:
      local_2244 = 1;
      iVar6 = lstrcmpiW(param_1,L"Delete");
      local_2230 = (uint)(iVar6 == 0);
      iVar7 = lstrcmpiW(param_1,L"ForceRemove");
      if ((iVar7 == 0) || ((iVar6 == 0) != 0)) {
        iVar6 = FUN_10002bf0(local_2220,param_1);
        if (-1 < iVar6) {
          if (param_3 == 0) goto LAB_10005302;
          local_2240 = (HKEY)0x0;
          local_223c = 0;
          local_2238 = 0;
          local_8._0_1_ = 1;
          WVar1 = *param_1;
          pWVar8 = param_1;
          while (WVar1 != L'\0') {
            if (WVar1 == L'\\') {
              if (pWVar8 != (LPCWSTR)0x0) {
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_100031a0(&local_2240);
                goto LAB_10005798;
              }
              break;
            }
            pWVar8 = CharNextW(pWVar8);
            WVar1 = *pWVar8;
          }
          ppuVar14 = &PTR_u_AppID_10015458;
          do {
            iVar6 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar14);
            if (iVar6 == 0) goto LAB_1000525f;
            ppuVar14 = ppuVar14 + 1;
          } while ((int)ppuVar14 < 0x10015488);
          local_2240 = local_2234;
          local_223c = 0;
          local_2238 = 0;
          FUN_100031c0(&local_2240,param_1);
          local_2240 = (HKEY)0x0;
          local_223c = 0;
          local_2238 = 0;
LAB_1000525f:
          if (local_2230 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            local_223c = 0;
            goto LAB_10005302;
          }
          iVar6 = FUN_10002bf0(local_2220,param_1);
          if ((-1 < iVar6) && (iVar6 = FUN_10002df0(local_2220,param_1), -1 < iVar6)) {
            local_8 = (uint)local_8._1_3_ << 8;
            local_223c = 0;
            goto LAB_100052a0;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ppHVar13 = &local_2240;
LAB_100057ba:
          FUN_100031a0(ppHVar13);
        }
        goto LAB_100057bf;
      }
LAB_10005302:
      iVar6 = lstrcmpiW(param_1,L"NoRemove");
      if (iVar6 == 0) {
        local_2244 = 0;
        iVar6 = FUN_10002bf0(local_2220,param_1);
        if (iVar6 < 0) goto LAB_100057bf;
      }
      iVar6 = lstrcmpiW(param_1,L"Val");
      if (iVar6 == 0) {
        iVar6 = FUN_10002bf0(local_2220,local_221c);
        if ((-1 < iVar6) && (iVar6 = FUN_10002bf0(local_2220,param_1), -1 < iVar6)) {
          if (*param_1 != L'=') {
LAB_10005798:
            local_8 = 0xffffffff;
            FUN_100031a0(&local_222c);
            goto LAB_100057e5;
          }
          if (param_3 != 0) {
            local_8._0_1_ = 2;
            local_2250 = local_2234;
            local_224c = 0;
            local_2248 = 0;
            iVar6 = FUN_10004d30(local_2220,&local_2250,local_221c,param_1);
            local_2250 = (HKEY)0x0;
            local_224c = 0;
            local_2248 = 0;
            if (-1 < iVar6) {
              local_8 = (uint)local_8._1_3_ << 8;
              local_224c = 0;
              goto LAB_100052a0;
            }
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100031a0(&local_2250);
LAB_10005811:
            local_8 = 0xffffffff;
            FUN_100031a0(&local_222c);
            goto LAB_100057e5;
          }
          if ((param_4 == 0) && (local_2244 != 0)) {
            local_226c = (HKEY)0x0;
            local_2268 = 0;
            local_2264 = 0;
            local_8._0_1_ = 3;
            uVar9 = FUN_10002770(&local_226c,local_2234,(LPCWSTR)0x0,0x20006);
            pHVar3 = local_226c;
            if ((uVar9 != 0) ||
               ((uVar9 = RegDeleteValueW(local_226c,local_221c), uVar9 != 0 && (uVar9 != 2)))) {
              FUN_100024b0(uVar9);
              local_8 = (uint)local_8._1_3_ << 8;
              ppHVar13 = &local_226c;
              goto LAB_100057ba;
            }
            local_8 = (uint)local_8._1_3_ << 8;
            if (pHVar3 != (HKEY)0x0) {
              RegCloseKey(pHVar3);
              local_226c = (HKEY)0x0;
            }
            local_2268 = 0;
          }
          iVar6 = FUN_10002df0(local_2220,param_1);
LAB_100052e0:
          if (-1 < iVar6) goto LAB_100052ea;
        }
        goto LAB_100057bf;
      }
      WVar1 = *param_1;
      pWVar8 = param_1;
      pHVar3 = local_2234;
      while (local_2234 = pHVar3, WVar1 != L'\0') {
        if (WVar1 == L'\\') {
          if (pWVar8 != (LPCWSTR)0x0) goto LAB_10005798;
          break;
        }
        pWVar8 = CharNextW(pWVar8);
        pHVar3 = local_2234;
        WVar1 = *pWVar8;
      }
      if (param_3 == 0) {
        if (param_4 == 0) {
          local_2230 = FUN_10002770(&local_222c,pHVar3,param_1,0x20019);
          if (local_2230 != 0) goto LAB_10005572;
        }
        else {
          local_2230 = 2;
LAB_10005572:
          param_4 = 1;
        }
        eVar10 = wcsncpy_s(local_21c,0x104,param_1,0xffffffff);
        switch(eVar10) {
        case 0:
        case 0x50:
          goto switchD_100055a1_caseD_0;
        default:
          uVar11 = FUN_10002160(0x80004005);
          pcVar12 = (char *)CONCAT22((short)((uint)uVar11 >> 0x10),CONCAT11(0x55,(char)uVar11));
          *pcVar12 = *pcVar12 + extraout_DL;
          *pcVar5 = *pcVar5 + extraout_DL;
          *(char *)param_1 = (char)*param_1 + extraout_DL;
          if ((POPCOUNT((char)*param_1) & 1U) != 0) {
            *(char *)param_1 = (char)*param_1 + extraout_DL;
            pWRam00000000 =
                 (LPCWSTR)CONCAT31(pWRam00000000._1_3_,(char)pWRam00000000 + (char)param_1);
            pWRam00000000 = param_1 + (int)pWRam00000000 * 3;
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        case 0xc:
          FUN_10002160(0x8007000e);
        case 0x16:
        case 0x22:
          uVar9 = FUN_10002160(0x80070057);
LAB_10005861:
          FUN_100024b0(uVar9);
          local_8 = local_8 & 0xffffff00;
          ppHVar13 = &local_2260;
          goto LAB_100057ba;
        }
      }
      iVar6 = FUN_10002770(&local_222c,pHVar3,param_1,0x2001f);
      if (((iVar6 != 0) && (iVar6 = FUN_10002770(&local_222c,pHVar3,param_1,0x20019), iVar6 != 0))
         && (uVar9 = FUN_100026d0(&local_222c,pHVar3,param_1,(LPWSTR)0x0,0,0x2001f,
                                  (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar9 != 0)) {
LAB_10005840:
        FUN_100024b0(uVar9);
        goto LAB_10005811;
      }
      iVar6 = FUN_10002bf0(local_2220,param_1);
      if ((iVar6 < 0) ||
         ((*param_1 == L'=' &&
          (iVar6 = FUN_10004d30(local_2220,&local_222c,(LPCWSTR)0x0,param_1), iVar6 < 0))))
      goto LAB_100057bf;
LAB_100052a0:
      if ((*param_1 == L'{') && (iVar6 = lstrlenW(param_1), iVar6 == 1)) {
        iVar6 = FUN_100050e0(local_2220,param_1,local_222c,param_3,0);
        if (-1 < iVar6) {
          iVar6 = FUN_10002bf0(local_2220,param_1);
          goto LAB_100052e0;
        }
        goto LAB_100057bf;
      }
      goto LAB_100052ea;
    }
LAB_100057bf:
    local_8 = 0xffffffff;
    if (local_222c != (HKEY)0x0) {
      RegCloseKey(local_222c);
      local_222c = (HKEY)0x0;
    }
  }
  local_2228 = 0;
LAB_100057e5:
  ExceptionList = local_10;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
switchD_100055a1_caseD_0:
  iVar6 = FUN_10002bf0(local_2220,param_1);
  if (((iVar6 < 0) || (iVar6 = FUN_10002df0(local_2220,param_1), iVar6 < 0)) ||
     (((*param_1 == L'{' && (iVar6 = lstrlenW(param_1), iVar6 == 1)) &&
      (((iVar6 = FUN_100050e0(local_2220,param_1,local_222c,0,param_4), iVar6 < 0 && (param_4 == 0))
       || (iVar6 = FUN_10002bf0(local_2220,param_1), iVar6 < 0)))))) goto LAB_100057bf;
  param_4 = local_2254;
  if (local_2230 != 2) {
    if (local_2230 == 0) {
      if ((local_2254 == 0) || (bVar4 = FUN_10002da0(local_222c), CONCAT31(extraout_var,bVar4) == 0)
         ) {
        bVar4 = FUN_10002da0(local_222c);
        local_2230 = CONCAT31(extraout_var_00,bVar4);
        uVar9 = 0;
        if (local_222c != (HKEY)0x0) {
          uVar9 = RegCloseKey(local_222c);
          local_222c = (HKEY)0x0;
        }
        local_2228 = 0;
        if (uVar9 != 0) goto LAB_10005840;
        if ((local_2244 != 0) && (local_2230 == 0)) {
          local_8 = CONCAT31(local_8._1_3_,4);
          local_2260 = local_2234;
          local_225c = 0;
          local_2258 = 0;
          uVar9 = FUN_10002620(&local_2260,local_21c);
          local_2260 = (HKEY)0x0;
          local_225c = 0;
          local_2258 = 0;
          if (uVar9 != 0) goto LAB_10005861;
          local_8 = local_8 & 0xffffff00;
          FUN_100031a0(&local_2260);
        }
      }
      else {
        iVar6 = FUN_10002d60(local_21c);
        if ((iVar6 != 0) && (local_2244 != 0)) {
          FUN_100031c0(&local_222c,local_21c);
        }
      }
    }
    else if (local_2254 == 0) {
      FUN_100024b0(local_2230);
      goto LAB_100057bf;
    }
  }
LAB_100052ea:
  if (*param_1 == L'}') goto LAB_100057bf;
  goto LAB_10005170;
}



// Function: FUN_100058f0 at 100058f0

int __thiscall FUN_100058f0(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011f58;
  local_10 = ExceptionList;
  uVar3 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = 0;
  *param_3 = 0;
  puVar5 = *(undefined4 **)((int)this + 0x2c);
  if (puVar5 != (undefined4 *)0x0) {
    piVar2 = (int *)*puVar5;
    while (piVar2 != (int *)0x0) {
      if ((((puVar5[2] != 0) && (*param_1 == *piVar2)) && (param_1[1] == piVar2[1])) &&
         ((param_1[2] == piVar2[2] && (param_1[3] == piVar2[3])))) {
        piVar2 = puVar5 + 4;
        if (puVar5[4] == 0) {
          local_8 = 0;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1001d33c);
          iVar4 = 0;
          if (*piVar2 == 0) {
            iVar4 = (*(code *)puVar5[2])(puVar5[3],&PTR_100154b4,piVar2);
          }
          local_8 = 0xffffffff;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1001d33c);
        }
        if (*piVar2 != 0) {
          iVar4 = (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,param_2,param_3,uVar3);
        }
        if ((*param_3 != 0) || (iVar4 != 0)) {
          ExceptionList = local_10;
          return iVar4;
        }
        break;
      }
      puVar1 = puVar5 + 9;
      puVar5 = puVar5 + 9;
      piVar2 = (int *)*puVar1;
    }
  }
  iVar4 = FUN_10004610((int *)&DAT_1001d32c,param_1,param_2,param_3);
  ExceptionList = local_10;
  return iVar4;
}



// Function: DllGetClassObject at 10005a20

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x5a20  2  DllGetClassObject */
  iVar1 = FUN_100058f0(&DAT_1001d2dc,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_10005a30 at 10005a30

void __fastcall FUN_10005a30(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *param_1 = ATL::CComClassFactory::vftable;
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return;
}



// Function: FUN_10005ac0 at 10005ac0

int FUN_10005ac0(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return -0x7ff8ffa9;
  }
  if (param_4 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_4 = 0;
  iVar2 = FUN_100047e0(param_3);
  if (iVar2 != 0) {
    piVar3 = (int *)(param_2[1] + param_1);
    (**(code **)(*piVar3 + 4))(piVar3);
    *param_4 = piVar3;
    return 0;
  }
  pcVar1 = (code *)param_2[2];
  do {
    if (pcVar1 == (code *)0x0) {
      return -0x7fffbffe;
    }
    piVar3 = (int *)*param_2;
    if ((piVar3 == (int *)0x0) ||
       ((((*piVar3 == *param_3 && (piVar3[1] == param_3[1])) && (piVar3[2] == param_3[2])) &&
        (piVar3[3] == param_3[3])))) {
      if (pcVar1 == (code *)0x1) {
        piVar3 = (int *)(param_2[1] + param_1);
        (**(code **)(*piVar3 + 4))(piVar3);
        *param_4 = piVar3;
        return 0;
      }
      iVar2 = (*pcVar1)(param_1,param_3,param_4,param_2[1]);
      if (iVar2 == 0) {
        return 0;
      }
      if ((piVar3 != (int *)0x0) && (iVar2 < 0)) {
        return iVar2;
      }
    }
    pcVar1 = (code *)param_2[5];
    param_2 = param_2 + 3;
  } while( true );
}



// Function: FUN_10005bb0 at 10005bb0

LONG FUN_10005bb0(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_1001d28c + 4))();
  }
  return LVar1;
}



// Function: FUN_10005be0 at 10005be0

LONG FUN_10005be0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
      return 0;
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_1001d28c + 8))();
  }
  return LVar1;
}



// Function: FUN_10005c30 at 10005c30

void FUN_10005c30(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005ac0(param_1,(int *)&PTR_DAT_100159cc,param_2,param_3);
  return;
}



// Function: FUN_10005c50 at 10005c50

undefined4 * __thiscall FUN_10005c50(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100121d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  if (*(char *)((int)this + 0x20) != '\0') {
    *(undefined1 *)((int)this + 0x20) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)((int)this + 8));
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005ce0 at 10005ce0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10005ce0(void *this,LPCWSTR param_1,int param_2)

{
  WCHAR WVar1;
  HKEY pHVar2;
  undefined4 uVar3;
  LPCWSTR lpsz;
  int iVar4;
  LPWSTR pWVar5;
  uint uVar6;
  WCHAR *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_200c = (WCHAR *)0x0;
  iVar4 = FUN_10003c00(this,param_1,&local_200c);
  if (iVar4 < 0) {
LAB_10005df5:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(WCHAR **)this = local_200c;
  WVar1 = *local_200c;
joined_r0x10005d2e:
  if ((WVar1 == L'\0') || (iVar4 = FUN_10002bf0(this,local_2008), iVar4 < 0)) goto LAB_10005de6;
  uVar6 = 0;
  while (iVar4 = lstrcmpiW(local_2008,(LPCWSTR)(&PTR_u_HKCR_10015648)[uVar6 * 2]), iVar4 != 0) {
    uVar6 = uVar6 + 1;
    if (0xd < uVar6) goto LAB_10005de6;
  }
  pHVar2 = (HKEY)(&DAT_1001564c)[uVar6 * 2];
  if (((pHVar2 == (HKEY)0x0) || (iVar4 = FUN_10002bf0(this,local_2008), iVar4 < 0)) ||
     (local_2008[0] != L'{')) goto LAB_10005de6;
  if (param_2 == 0) {
    iVar4 = FUN_100050e0(this,local_2008,pHVar2,0,0);
    if (iVar4 < 0) goto LAB_10005de6;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar3 = *this;
    iVar4 = FUN_100050e0(this,local_2008,pHVar2,param_2,0);
    if (iVar4 < 0) {
      *(undefined4 *)this = uVar3;
      FUN_100050e0(this,local_2008,pHVar2,0,0);
LAB_10005de6:
      CoTaskMemFree(local_200c);
      goto LAB_10005df5;
    }
  }
  do {
                    /* WARNING: Load size is inaccurate */
    lpsz = *this;
    switch(*lpsz) {
    case L'\t':
    case L'\n':
    case L'\r':
    case L' ':
      pWVar5 = CharNextW(lpsz);
      *(LPWSTR *)this = pWVar5;
      break;
    default:
      goto switchD_10005e34_caseD_b;
    }
  } while( true );
switchD_10005e34_caseD_b:
  WVar1 = *lpsz;
  goto joined_r0x10005d2e;
}



// Function: FUN_10005e80 at 10005e80

int __thiscall FUN_10005e80(void *this,int param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pbVar2 = (byte *)*piVar4, pbVar2 != (byte *)0x0)) {
    do {
      if ((param_2 == (byte *)0x0) ||
         (bVar1 = FUN_10002070(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10003ec0((GUID *)*piVar4,piVar3,iVar6);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      pbVar2 = (byte *)piVar4[9];
      piVar4 = piVar4 + 9;
    } while (pbVar2 != (byte *)0x0);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  iVar5 = FUN_100044f0(0x1001d32c,param_1,param_2);
  if ((-1 < iVar5) && (DAT_1001d2a4 != (code *)0x0)) {
    iVar5 = (*DAT_1001d2a4)(DAT_1001d358);
    return iVar5;
  }
  return iVar5;
}



// Function: FUN_10005f20 at 10005f20

int __thiscall FUN_10005f20(void *this,int param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)((int)this + 0x2c);
  iVar5 = 0;
  if ((piVar4 != (int *)0x0) && (pbVar2 = (byte *)*piVar4, pbVar2 != (byte *)0x0)) {
    do {
      if ((param_2 == (byte *)0x0) ||
         (bVar1 = FUN_10002070(param_2,pbVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10003ec0((GUID *)*piVar4,piVar3,iVar5);
        if (iVar5 < 0) {
          return iVar5;
        }
        iVar5 = (*(code *)piVar4[1])(0);
        if (iVar5 < 0) {
          return iVar5;
        }
      }
      pbVar2 = (byte *)piVar4[9];
      piVar4 = piVar4 + 9;
    } while (pbVar2 != (byte *)0x0);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  if ((DAT_1001d2a8 != (code *)0x0) && (iVar5 = (*DAT_1001d2a8)(), iVar5 < 0)) {
    return iVar5;
  }
  iVar5 = FUN_10004580(0x1001d32c,param_1,param_2);
  return iVar5;
}



// Function: DllRegisterServer at 10005fb0

void DllRegisterServer(void)

{
                    /* 0x5fb0  3  DllRegisterServer */
  FUN_10005e80(&DAT_1001d2dc,1,(byte *)0x0);
  return;
}



// Function: DllUnregisterServer at 10005fc0

void DllUnregisterServer(void)

{
                    /* 0x5fc0  4  DllUnregisterServer */
  FUN_10005f20(&DAT_1001d2dc,1,(byte *)0x0);
  return;
}



// Function: FUN_10005fd0 at 10005fd0

DWORD FUN_10005fd0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001220b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10005a30(puVar1);
    }
    local_8 = 0xffffffff;
    DVar2 = FUN_10006076();
    return DVar2;
  }
  return 0x80004003;
}



// Function: Catch@10006063 at 10006063

undefined * Catch_10006063(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006070;
}



// Function: FUN_10006076 at 10006076

DWORD FUN_10006076(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_100060d3;
  unaff_ESI[9] = *(int *)(unaff_EBP + 8);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 2),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_100060ab;
  }
  else {
LAB_100060ab:
    *(undefined1 *)(unaff_ESI + 8) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_100060d3;
    }
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_100060d3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_100060f0 at 100060f0

void FUN_100060f0(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  DWORD DVar2;
  uint uStack_444;
  undefined1 *local_41c;
  undefined1 auStack_418 [1024];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10012246;
  local_10 = ExceptionList;
  uStack_444 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_444;
  ExceptionList = &local_10;
  local_41c = (undefined1 *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_18 = uStack_444;
  hModule = LoadLibraryExW(param_1,(HANDLE)0x0,2);
  if (hModule == (HMODULE)0x0) {
    FUN_10002490();
  }
  else {
    hResInfo = FindResourceW(hModule,param_2,param_3);
    if (hResInfo == (HRSRC)0x0) {
      FUN_10002490();
    }
    else {
      pvVar1 = LoadResource(hModule,hResInfo);
      if (pvVar1 == (HGLOBAL)0x0) {
        FUN_10002490();
      }
      else {
        DVar2 = SizeofResource(hModule,hResInfo);
        if (DVar2 <= DVar2 + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10004a10(&local_41c,DVar2 + 1);
          local_8 = 1;
          FUN_100061fd();
          return;
        }
      }
    }
    FreeLibrary(hModule);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10003010(&local_41c);
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@100061de at 100061de

undefined * Catch_100061de(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100061eb;
}



// Function: FUN_100061fd at 100061fd

void FUN_100061fd(void)

{
  int iVar1;
  LPCSTR unaff_EBX;
  uint unaff_EBP;
  HMODULE unaff_ESI;
  int unaff_EDI;
  undefined4 uStack0000000c;
  
  if (*(LPWSTR *)(unaff_EBP - 0x418) != (LPWSTR)0x0) {
    iVar1 = MultiByteToWideChar(3,0,unaff_EBX,unaff_EDI,*(LPWSTR *)(unaff_EBP - 0x418),unaff_EDI);
    if (iVar1 == 0) {
      FUN_10002490();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP - 0x418) + iVar1 * 2) = 0;
      FUN_10005ce0((void *)(unaff_EBP - 0x42c),*(LPCWSTR *)(unaff_EBP - 0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(unaff_ESI);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  if (*(int *)(unaff_EBP - 0x418) != unaff_EBP - 0x414) {
    FUN_10003010((undefined4 *)(unaff_EBP - 0x418));
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10006290;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100062a0 at 100062a0

void FUN_100062a0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012278;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100060f0(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006300 at 10006300

undefined4 FUN_10006300(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012278;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_100060f0(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_10006380 at 10006380

void FUN_10006380(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012278;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100060f0(param_2,(LPCWSTR)(uint)param_3,param_4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100063e0 at 100063e0

undefined4 FUN_100063e0(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012278;
  local_10 = ExceptionList;
  local_8 = 0;
  if ((param_3 != (LPCWSTR)0x0) && (param_4 != (LPCWSTR)0x0)) {
    ExceptionList = &local_10;
    uVar1 = FUN_100060f0(param_2,param_3,param_4);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80070057;
}



// Function: FUN_10006460 at 10006460

void FUN_10006460(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  LPCWSTR pWVar2;
  HMODULE pHVar3;
  void **ppvVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  DWORD DVar8;
  HMODULE pHVar9;
  WCHAR *pWVar10;
  undefined **local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  undefined4 local_a50;
  int *local_a48;
  WCHAR local_a44 [520];
  WCHAR local_634;
  undefined2 local_632 [523];
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100122d7;
  local_10 = ExceptionList;
  uVar6 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_a48 = param_1;
  local_a5c = ATL::CRegObject::vftable;
  local_a58 = 0;
  local_a54 = 0;
  local_a50 = 0;
  local_8 = 2;
  ppvVar4 = &local_10;
  local_14 = uVar6;
  if (param_4 != (undefined4 *)0x0) {
    pWVar2 = (LPCWSTR)*param_4;
    while (ExceptionList = ppvVar4, ppvVar4 = (void **)ExceptionList, pWVar2 != (LPCWSTR)0x0) {
      if ((pWVar2 != (LPCWSTR)0x0) && (param_4[1] != 0)) {
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 3;
        FUN_10004af0(pWVar2,param_4[1]);
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      puVar1 = param_4 + 2;
      param_4 = param_4 + 2;
      ppvVar4 = (void **)ExceptionList;
      pWVar2 = (LPCWSTR)*puVar1;
    }
  }
  ExceptionList = ppvVar4;
  iVar7 = (**(code **)(*local_a48 + 0x14))(&local_a5c,uVar6);
  pHVar3 = DAT_1001d358;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_1001d358,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_10002490();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10002fd0((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10003b00(&local_a5c);
        goto LAB_100066d9;
      }
      FUN_100025c0(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10002130(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10002fd0((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10003b00(&local_a5c);
          goto LAB_100066d9;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_10004ca0(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_10004ca0(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_100063e0(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_10006300(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10002fd0((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10003b00(&local_a5c);
LAB_100066d9:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006700 at 10006700

void FUN_10006700(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  LPCWSTR pWVar2;
  HMODULE pHVar3;
  void **ppvVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  DWORD DVar8;
  HMODULE pHVar9;
  WCHAR *pWVar10;
  undefined **local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  undefined4 local_a50;
  int *local_a48;
  WCHAR local_a44 [520];
  WCHAR local_634;
  undefined2 local_632 [523];
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012337;
  local_10 = ExceptionList;
  uVar6 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_a48 = param_1;
  local_a5c = ATL::CRegObject::vftable;
  local_a58 = 0;
  local_a54 = 0;
  local_a50 = 0;
  local_8 = 2;
  ppvVar4 = &local_10;
  local_14 = uVar6;
  if (param_4 != (undefined4 *)0x0) {
    pWVar2 = (LPCWSTR)*param_4;
    while (ExceptionList = ppvVar4, ppvVar4 = (void **)ExceptionList, pWVar2 != (LPCWSTR)0x0) {
      if ((pWVar2 != (LPCWSTR)0x0) && (param_4[1] != 0)) {
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8._0_1_ = 3;
        FUN_10004af0(pWVar2,param_4[1]);
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      puVar1 = param_4 + 2;
      param_4 = param_4 + 2;
      ppvVar4 = (void **)ExceptionList;
      pWVar2 = (LPCWSTR)*puVar1;
    }
  }
  ExceptionList = ppvVar4;
  iVar7 = (**(code **)(*local_a48 + 0x14))(&local_a5c,uVar6);
  pHVar3 = DAT_1001d358;
  if (-1 < iVar7) {
    local_a48 = (int *)0x0;
    local_8._0_1_ = 4;
    DVar8 = GetModuleFileNameW(DAT_1001d358,local_21c,0x104);
    if (DVar8 == 0) {
      FUN_10002490();
    }
    else {
      if (DVar8 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10002fd0((int *)&local_a48);
        local_8 = 0xffffffff;
        FUN_10003b00(&local_a5c);
        goto LAB_10006963;
      }
      FUN_100025c0(local_a44,0x208,local_21c);
      if ((pHVar3 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleW((LPCWSTR)0x0), pHVar3 == pHVar9)) {
        local_634 = L'\"';
        bVar5 = FUN_10002130(local_632,0x20b,local_a44);
        if (!bVar5) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10002fd0((int *)&local_a48);
          local_8 = 0xffffffff;
          FUN_10003b00(&local_a5c);
          goto LAB_10006963;
        }
        iVar7 = lstrlenW(&local_634);
        local_632[iVar7 + -1] = 0x22;
        local_632[iVar7] = 0;
        pWVar10 = &local_634;
      }
      else {
        pWVar10 = local_a44;
      }
      iVar7 = FUN_10004ca0(&local_a5c,L"Module",(int)pWVar10);
      if ((-1 < iVar7) &&
         (iVar7 = FUN_10004ca0(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar7)) {
        if (param_3 == 0) {
          FUN_10006380(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_100062a0(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10002fd0((int *)&local_a48);
  }
  local_8 = 0xffffffff;
  FUN_10003b00(&local_a5c);
LAB_10006963:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006980 at 10006980

void __cdecl FUN_10006980(undefined4 param_1,undefined4 *param_2)

{
  if (7 < (uint)param_2[5]) {
    operator_delete((void *)*param_2);
  }
  param_2[5] = 7;
  param_2[4] = 0;
  *(undefined2 *)param_2 = 0;
  return;
}



// Function: FUN_100069b0 at 100069b0

void FUN_100069b0(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_10006460(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100069c0 at 100069c0

void FUN_100069c0(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10006700(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100069d0 at 100069d0

void FUN_100069d0(int param_1)

{
  FUN_10006700((int *)&DAT_1001d2dc,0xc9,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_100069f0 at 100069f0

void FUN_100069f0(int param_1)

{
  FUN_10006700((int *)&DAT_1001d2dc,0xca,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10006a10 at 10006a10

void FUN_10006a10(int param_1)

{
  FUN_10006700((int *)&DAT_1001d2dc,0xcb,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10006a30 at 10006a30

void __cdecl FUN_10006a30(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != param_2) {
    do {
      if (7 < (uint)param_1[5]) {
        operator_delete((void *)*param_1);
      }
      param_1[5] = 7;
      param_1[4] = 0;
      *(undefined2 *)param_1 = 0;
      param_1 = param_1 + 7;
    } while (param_1 != param_2);
  }
  return;
}



// Function: FUN_10006a70 at 10006a70

void __fastcall FUN_10006a70(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012389;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(param_1 + 0x30) != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 0x30));
    operator_delete(*(void **)(param_1 + 0x30));
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006b00 at 10006b00

void __fastcall FUN_10006b00(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100123e1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  if (*(int *)(param_1 + 0x30) != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 0x30));
    operator_delete(*(void **)(param_1 + 0x30));
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006ba0 at 10006ba0

void FUN_10006ba0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  if (param_3 == (undefined4 *)0x0) {
    __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
    return;
  }
  *param_3 = 0;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006bf0 at 10006bf0

undefined4 FUN_10006bf0(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}



// Function: FUN_10006c10 at 10006c10

void __fastcall FUN_10006c10(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return;
}



// Function: AtlAdd<unsigned_long> at 10006c60

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



// Function: FUN_10006c90 at 10006c90

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_10006c90(ulong param_1)

{
  long lVar1;
  uint local_38;
  ulong local_28;
  undefined1 local_21;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  undefined4 local_8;
  
  puStack_10 = &LAB_10010f48;
  local_14 = ExceptionList;
  local_c = DAT_1001d274 ^ 0x10018b68;
  local_38 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_38;
  ExceptionList = &local_14;
  local_8 = 0;
  local_28 = 0;
  local_20 = local_38;
  lVar1 = ATL::AtlAdd<unsigned_long>(&local_28,param_1,0x2000);
  if (lVar1 < 0) {
    local_21 = 0;
  }
  else {
    local_1c = (undefined1 *)((int)&local_38 - local_28);
  }
  local_8 = 0xfffffffe;
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006d50 at 10006d50

void FUN_10006d50(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10006d70 at 10006d70

void FUN_10006d70(int param_1)

{
  FUN_10008de0(param_1 + -0xc);
  return;
}



// Function: FUN_10006d80 at 10006d80

void FUN_10006d80(int param_1)

{
  FUN_10006d50(param_1 + -4);
  return;
}



// Function: FUN_10006d90 at 10006d90

void FUN_10006d90(int param_1)

{
  FUN_10006d50(param_1 + -0xc);
  return;
}



// Function: FUN_10006da0 at 10006da0

void FUN_10006da0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10008e00(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10006db0 at 10006db0

void FUN_10006db0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10008e00(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10006dc0 at 10006dc0

void FUN_10006dc0(int param_1)

{
  FUN_10008de0(param_1 + -4);
  return;
}



// Function: FUN_10006dd0 at 10006dd0

void FUN_10006dd0(int param_1)

{
  FUN_10008de0(param_1 + -8);
  return;
}



// Function: FUN_10006de0 at 10006de0

undefined4 __thiscall FUN_10006de0(void *this,int *param_1)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  uint uStack_38;
  int local_24;
  uint *local_20;
  int *piStack_1c;
  uint *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar4 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012443;
  local_10 = ExceptionList;
  uStack_38 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  iVar6 = (**(code **)(*param_1 + 0xc))(param_1,&local_24);
  if (-1 < iVar6) {
    local_18 = (uint *)0x0;
    uVar2 = *(ushort *)(local_24 + 0x2c);
    *(uint *)((int)this + 0x18) = (uint)uVar2;
    *(undefined4 *)((int)this + 0x14) = 0;
    if (uVar2 != 0) {
      local_8 = 0;
      uVar3 = *(uint *)((int)this + 0x18);
      uVar8 = -(uint)((int)((ulonglong)uVar3 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar3 * 0xc);
      local_20 = (uint *)FUN_10010d76(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 != (uint *)0x0) {
        *local_20 = uVar3;
        puVar1 = local_20 + 1;
        _eh_vector_constructor_iterator_(puVar1,0xc,uVar3,FUN_10006c10,FUN_100010b0);
        local_8 = 0xffffffff;
        local_18 = puVar1;
        uVar7 = FUN_10006ec1();
        return uVar7;
      }
      local_18 = (uint *)0x0;
      local_8 = 0xffffffff;
      uVar7 = FUN_10006ec1();
      return uVar7;
    }
    local_20 = (uint *)0x0;
    if (0 < *(int *)((int)this + 0x18)) {
      piVar9 = (int *)0x0;
      do {
        iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4,local_20,&piStack_1c);
        if (-1 < iVar6) {
          param_1 = (int *)0x0;
          local_8 = 3;
          iVar6 = (**(code **)(*piVar4 + 0x30))(piVar4,*piStack_1c,&param_1,0,0,0);
          piVar5 = param_1;
          if (-1 < iVar6) {
            param_1 = (int *)0x0;
            if ((int *)*piVar9 != piVar5) {
              Ordinal_6((int *)*piVar9);
              *piVar9 = (int)piVar5;
            }
            iVar6 = Ordinal_7(*piVar9);
            piVar9[1] = iVar6;
            piVar9[2] = *piStack_1c;
          }
          (**(code **)(*piVar4 + 0x50))(piVar4,piStack_1c);
          local_8 = 0xffffffff;
          Ordinal_6(param_1);
        }
        local_20 = (uint *)((int)local_20 + 1);
        piVar9 = piVar9 + 3;
      } while ((int)local_20 < *(int *)((int)this + 0x18));
    }
    *(uint **)((int)this + 0x14) = local_18;
    (**(code **)(*piVar4 + 0x4c))(piVar4,local_24);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10006eb1 at 10006eb1

undefined * Catch_10006eb1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10006ebe;
}



// Function: FUN_10006ec1 at 10006ec1

undefined4 FUN_10006ec1(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar3;
  
  if (*(int *)(unaff_EBP + -0x14) == 0) {
    (**(code **)(*unaff_EBX + 0x4c))();
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  if (0 < *(int *)(iVar2 + 0x18)) {
    piVar3 = *(int **)(unaff_EBP + -0x14);
    do {
      iVar1 = (**(code **)(*unaff_EBX + 0x14))();
      if (-1 < iVar1) {
        *(undefined4 *)(unaff_EBP + 8) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        iVar1 = (**(code **)(*unaff_EBX + 0x30))();
        if (-1 < iVar1) {
          iVar2 = *(int *)(unaff_EBP + 8);
          *(undefined4 *)(unaff_EBP + 8) = 0;
          if (*piVar3 != iVar2) {
            Ordinal_6(*piVar3);
            *piVar3 = iVar2;
          }
          iVar2 = Ordinal_7(*piVar3);
          piVar3[1] = iVar2;
          piVar3[2] = **(int **)(unaff_EBP + -0x18);
          iVar2 = *(int *)(unaff_EBP + -0x24);
        }
        (**(code **)(*unaff_EBX + 0x50))();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
      }
      iVar1 = *(int *)(unaff_EBP + -0x1c) + 1;
      *(int *)(unaff_EBP + -0x1c) = iVar1;
      piVar3 = piVar3 + 3;
    } while (iVar1 < *(int *)(iVar2 + 0x18));
  }
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(unaff_EBP + -0x14);
  (**(code **)(*unaff_EBX + 0x4c))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10006fd0 at 10006fd0

void FUN_10006fd0(int param_1)

{
  int *piVar1;
  void *pvVar2;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    pvVar2 = *(void **)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (pvVar2 != (void *)0x0) {
      _eh_vector_destructor_iterator_(pvVar2,0xc,*(int *)((int)pvVar2 + -4),FUN_100010b0);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10007030 at 10007030

undefined4 * __thiscall FUN_10007030(void *this,int param_1)

{
  undefined4 *puVar1;
  
  if (-param_1 - 1U < 8) {
    puVar1 = (undefined4 *)FUN_10002160(0x80070216);
  }
  else {
    puVar1 = (undefined4 *)malloc(param_1 + 8);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
                    /* WARNING: Load size is inaccurate */
  *puVar1 = *this;
  *(undefined4 **)this = puVar1;
  return puVar1 + 2;
}



// Function: FUN_10007080 at 10007080

bool __thiscall FUN_10007080(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012490;
  local_10 = ExceptionList;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (param_1 == (undefined4 *)0x0) {
      return true;
    }
  }
  else if (param_1 != (undefined4 *)0x0) {
    local_18 = (int *)0x0;
    local_14 = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
                    /* WARNING: Load size is inaccurate */
    ExceptionList = &local_10;
    (**(code **)**this)(*this,&PTR_100154b4,&local_18,DAT_1001d274 ^ (uint)&stack0xfffffffc);
    (**(code **)*param_1)(param_1,&PTR_100154b4,&local_14);
    bVar1 = local_18 == local_14;
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    ExceptionList = local_10;
    return bVar1;
  }
  return false;
}



// Function: FUN_10007170 at 10007170

void __fastcall FUN_10007170(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100124c3;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((*(byte *)(param_1 + 0x14) & 2) != 0) {
    piVar3 = *(int **)(param_1 + 8);
    if (piVar3 != *(int **)(param_1 + 0xc)) {
      do {
        piVar1 = (int *)*piVar3;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1,uVar2);
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 != *(int **)(param_1 + 0xc));
    }
    operator_delete__(*(void **)(param_1 + 8));
  }
  local_8 = 0xffffffff;
  piVar3 = *(int **)(param_1 + 4);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007200 at 10007200

undefined4 FUN_10007200(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100124e8;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    return 0x80070057;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new(0xc);
  local_8 = 0xffffffff;
  uVar1 = FUN_1000727e();
  return uVar1;
}



// Function: Catch@1000726b at 1000726b

undefined * Catch_1000726b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007278;
}



// Function: FUN_1000727e at 1000727e

undefined4 FUN_1000727e(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI == (undefined4 *)0x0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  *unaff_ESI = *(undefined4 *)(unaff_EBP + 0xc);
  unaff_ESI[1] = *(undefined4 *)(unaff_EBP + 0x10);
  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_EBX + 0xc);
  *(LPCRITICAL_SECTION *)(unaff_EBP + -0x1c) = lpCriticalSection;
  *(undefined1 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(unaff_EBP + -0x18) = 1;
  *(undefined4 *)(unaff_EBP + 8) = 0;
  unaff_ESI[2] = *(undefined4 *)(unaff_EBX + 8);
  *(undefined4 **)(unaff_EBX + 8) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
  *(undefined1 *)(unaff_EBP + -0x18) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_10007300 at 10007300

int __thiscall FUN_10007300(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  
  bVar3 = FUN_10007080(this,(undefined4 *)*param_1);
  if (!bVar3) {
    puVar1 = (undefined4 *)*param_1;
    if (this == (void *)0x0) {
      return 0;
    }
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    *(undefined4 *)this = 0;
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,&DAT_10015aa0,this);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10007360 at 10007360

void __fastcall FUN_10007360(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012518;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10007170(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100073b0 at 100073b0

undefined4 __thiscall FUN_100073b0(void *this,int param_1,int param_2,int *param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012540;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_4 == 3) {
    local_8 = 0;
    lVar2 = (ulonglong)(uint)(param_2 - param_1 >> 2) * 4;
    uVar3 = FUN_10010d76(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(undefined4 *)((int)this + 8) = uVar3;
    local_8 = 0xffffffff;
    uVar3 = FUN_10007434();
    return uVar3;
  }
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  if (*(int **)((int)this + 4) != param_3) {
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 4))(param_3);
    }
    piVar1 = *(int **)((int)this + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)((int)this + 4) = param_3;
  }
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 8);
  *(int *)((int)this + 0x14) = param_4;
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10007421 at 10007421

undefined * Catch_10007421(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000742e;
}



// Function: FUN_10007434 at 10007434

undefined4 FUN_10007434(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piVar2;
  
  *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 8);
  if (*(int *)(unaff_ESI + 8) == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  piVar2 = *(int **)(unaff_EBP + 8);
  if (piVar2 != unaff_EBX) {
    do {
      if ((*(int **)(unaff_ESI + 0x10) == (int *)0x0) || (piVar2 == (int *)0x0)) {
        FUN_10002160(0x80004005);
        *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_EBP + 8);
        *(undefined4 *)(unaff_ESI + 0xc) = *(undefined4 *)(unaff_EBP + 0xc);
        goto LAB_100074af;
      }
      piVar1 = (int *)*piVar2;
      **(int **)(unaff_ESI + 0x10) = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_ESI + 0x10) + 4;
      piVar2 = piVar2 + 1;
    } while (piVar2 != unaff_EBX);
    piVar2 = *(int **)(unaff_EBP + 8);
  }
  *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 8) + ((int)unaff_EBX - (int)piVar2 >> 2) * 4;
LAB_100074af:
  piVar2 = *(int **)(unaff_EBP + 0x10);
  if (*(int **)(unaff_ESI + 4) != piVar2) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    piVar1 = *(int **)(unaff_ESI + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(int **)(unaff_ESI + 4) = piVar2;
  }
  *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 8);
  *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_EBP + 0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_10007500 at 10007500

void __fastcall FUN_10007500(int param_1)

{
  if (param_1 != 0) {
    FUN_10007200(param_1 + 4);
    return;
  }
  FUN_10007200(0);
  return;
}



// Function: FUN_10007530 at 10007530

void __thiscall FUN_10007530(void *this,undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD DVar3;
  int iVar4;
  int *local_22c;
  int *local_228;
  int *local_224;
  int *local_220;
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100125d9;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_100077a3;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_1001d28c + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_228 = (int *)0x0;
    if (((((DAT_1001d290 == *piVar1) && (DAT_1001d294 == piVar1[1])) && (DAT_1001d298 == piVar1[2]))
        && ((DAT_1001d29c == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_1001d358,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10007771;
      local_220 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = Ordinal_161(local_21c,&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10002fd0((int *)&local_220);
    }
    else {
      iVar4 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                          param_1,&local_228,uVar2);
    }
    if (-1 < iVar4) {
      local_22c = (int *)0x0;
      local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
      iVar4 = (**(code **)(*local_228 + 0x18))(local_228,*this,&local_22c);
      if (-1 < iVar4) {
        local_224 = local_22c;
        if (local_22c != (int *)0x0) {
          (**(code **)(*local_22c + 4))(local_22c);
        }
        local_220 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,7);
        iVar4 = (**(code **)*local_22c)(local_22c,&DAT_10015a90,&local_220);
        if (-1 < iVar4) {
          FUN_10007300(&local_224,(int *)&local_220);
        }
        *(int **)((int)this + 0xc) = local_224;
        local_224 = (int *)0x0;
        FUN_10007500(DAT_1001d28c);
        local_8._0_1_ = 5;
        if (local_220 != (int *)0x0) {
          (**(code **)(*local_220 + 8))(local_220);
        }
        local_8._0_1_ = 3;
        if (local_224 != (int *)0x0) {
          (**(code **)(*local_224 + 8))(local_224);
        }
      }
      (**(code **)(*local_228 + 8))(local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_22c != (int *)0x0) {
        (**(code **)(*local_22c + 8))(local_22c);
      }
    }
  }
LAB_10007771:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_10006de0(this,*(int **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_100077a3:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100077d0 at 100077d0

undefined4 * __fastcall FUN_100077d0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012633;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_8 = 3;
  *param_1 = ATL::
             CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
             ::vftable;
  (**(code **)(*DAT_1001d28c + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10007860 at 10007860

undefined4 FUN_10007860(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// Function: FUN_10007880 at 10007880

bool FUN_10007880(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  if (param_2 <= uVar1) {
    uVar1 = param_2;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1 * 4;
  return param_2 != uVar1;
}



// Function: FUN_100078b0 at 100078b0

undefined4 FUN_100078b0(int param_1)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  return *(undefined4 *)(param_1 + 0x18);
}



// Function: FUN_100078c0 at 100078c0

int FUN_100078c0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 6;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[6];
  if ((*piVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(1);
  }
  return iVar2;
}



// Function: FUN_100078f0 at 100078f0

uint FUN_100078f0(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = param_4;
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  if ((param_3 != (int *)0x0) && ((param_2 < 2 || (param_4 != (uint *)0x0)))) {
    if ((*(int *)(param_1 + 8) != 0) &&
       ((*(int *)(param_1 + 0xc) != 0 && (*(int *)(param_1 + 0x10) != 0)))) {
      uVar3 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
      param_4 = (uint *)(uint)(uVar3 < param_2);
      if (uVar3 <= param_2) {
        param_2 = uVar3;
      }
      if (puVar2 != (uint *)0x0) {
        *puVar2 = param_2;
      }
      while( true ) {
        if (param_2 == 0) {
          return (uint)param_4;
        }
        param_2 = param_2 - 1;
        if ((param_3 == (int *)0x0) || (*(int **)(param_1 + 0x10) == (int *)0x0)) break;
        piVar1 = (int *)**(int **)(param_1 + 0x10);
        *param_3 = (int)piVar1;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 4;
        param_3 = param_3 + 1;
      }
      FUN_10002160(0x80004005);
    }
    return 0x80004005;
  }
  return 0x80004003;
}



// Function: FUN_100079c0 at 100079c0

void FUN_100079c0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005ac0(param_1,(int *)&PTR_DAT_10015ad4,param_2,param_3);
  return;
}



// Function: FUN_100079e0 at 100079e0

undefined4 * __thiscall FUN_100079e0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012660;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       ATL::
       CComObject<class_ATL::CComEnum<struct_IEnumConnectionPoints,&struct___s_GUID_const__GUID_b196b285_bab4_101a_b69c_00aa00341d07,struct_IConnectionPoint*,class_ATL::_CopyInterface<struct_IConnectionPoint>,class_ATL::CComSingleThreadModel>_>
       ::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0xc0000001;
  (**(code **)(*DAT_1001d28c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10007170((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007a60 at 10007a60

undefined4 FUN_10007a60(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012680;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_100077d0(puVar1);
    local_8 = 0xffffffff;
    uVar2 = FUN_10007b03();
    return uVar2;
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_10007b03();
  return uVar2;
}



// Function: Catch@10007aed at 10007aed

undefined * Catch_10007aed(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007afa;
}



// Function: FUN_10007b03 at 10007b03

undefined4 FUN_10007b03(void)

{
  int in_EAX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  int *unaff_EDI;
  
  if (in_EAX != 0) {
    unaff_ESI = 0;
  }
  *unaff_EDI = in_EAX;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_10007b30 at 10007b30

undefined4 __thiscall
FUN_10007b30(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  
  uVar2 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar2 = FUN_10007530(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      iVar3 = lstrlenW((LPCWSTR)*param_2);
      iVar9 = *(int *)((int)this + 0x18) + -1;
      if (-1 < iVar9) {
        iVar4 = iVar9 * 0xc;
        piVar5 = (int *)(iVar4 + 4 + *(int *)((int)this + 0x14));
        do {
          if (iVar3 == *piVar5) {
            piVar8 = (int *)*param_2;
            puVar1 = (undefined4 *)(iVar4 + *(int *)((int)this + 0x14));
            piVar7 = (int *)*puVar1;
            for (uVar6 = puVar1[1] * 2; 3 < uVar6; uVar6 = uVar6 - 4) {
              if (*piVar7 != *piVar8) goto LAB_10007bfe;
              piVar8 = piVar8 + 1;
              piVar7 = piVar7 + 1;
            }
            if ((uVar6 == 0) ||
               (((char)*piVar8 == (char)*piVar7 &&
                ((uVar6 < 2 ||
                 ((*(char *)((int)piVar8 + 1) == *(char *)((int)piVar7 + 1) &&
                  ((uVar6 < 3 || (*(char *)((int)piVar8 + 2) == *(char *)((int)piVar7 + 2)))))))))))
            {
              *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + iVar9 * 0xc);
              return 0;
            }
          }
LAB_10007bfe:
          piVar5 = piVar5 + -3;
          iVar4 = iVar4 + -0xc;
          iVar9 = iVar9 + -1;
        } while (-1 < iVar9);
      }
    }
    uVar2 = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                      (*(int **)((int)this + 0xc),param_2,param_3,param_5);
  }
  return uVar2;
}



// Function: FUN_10007c50 at 10007c50

int FUN_10007c50(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100126a8;
  local_10 = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_2 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_100077d0(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_10007ceb();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_10007ceb();
  return iVar2;
}



// Function: Catch@10007cd9 at 10007cd9

undefined * Catch_10007cd9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007ce6;
}



// Function: FUN_10007ceb at 10007ceb

int FUN_10007ceb(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  if (unaff_ESI != unaff_EBX) {
    *(int **)(unaff_EBP + -0x14) = unaff_EBX;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    cVar1 = FUN_10006c90((ulong)unaff_EBX);
    if (cVar1 == '\0') {
      piVar2 = FUN_10007030((void *)(unaff_EBP + -0x14),(int)unaff_EBX);
      if (piVar2 != unaff_EBX) {
        iVar3 = FUN_100073b0(unaff_ESI,(int)piVar2,(int)piVar2,*(int **)(unaff_EBP + 8),3);
        if ((int)unaff_EBX <= iVar3) {
          iVar3 = (**(code **)*unaff_ESI)();
          if ((int)unaff_EBX <= iVar3) goto LAB_10007d7c;
        }
        (**(code **)(*unaff_ESI + 0x1c))(1);
LAB_10007d7c:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_10002fd0((int *)(unaff_EBP + -0x14));
        ExceptionList = *(void **)(unaff_EBP + -0xc);
        return iVar3;
      }
    }
    (**(code **)(*unaff_ESI + 0x1c))(1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10002fd0((int *)(unaff_EBP + -0x14));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -0x7ff8fff2;
}



// Function: FUN_10007db0 at 10007db0

undefined4 FUN_10007db0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1001c8f0 == (int *)0x0) {
    uVar1 = FUN_10007530(&PTR_DAT_1001c8e4,param_3);
  }
  *param_4 = DAT_1001c8f0;
  if (DAT_1001c8f0 != (int *)0x0) {
    (**(code **)(*DAT_1001c8f0 + 4))(DAT_1001c8f0);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10007e10 at 10007e10

void FUN_10007e10(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10007b30(&PTR_DAT_1001c8e4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007e40 at 10007e40

void FUN_10007e40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1001c8f0 == (int *)0x0) || (DAT_1001c8f8 == 0)) {
    FUN_10007530(&PTR_DAT_1001c8e4,param_4);
  }
  if (DAT_1001c8f0 != (int *)0x0) {
    (**(code **)(*DAT_1001c8f0 + 0x2c))
              (DAT_1001c8f0,param_1 + -4,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10007ea0 at 10007ea0

int FUN_10007ea0(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012722;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  piVar2 = (int *)0x80004003;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    piVar2 = (int *)FUN_10007a60(&local_1c);
    if (-1 < (int)piVar2) {
      if ((*(byte *)(param_1 + 5) & 2) == 0) {
        local_18 = (int *)param_1[1];
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 4))(local_18,uVar1);
        }
        local_8 = 3;
        uVar1 = 2;
      }
      else {
        local_18 = param_1;
        (**(code **)(*param_1 + 4))(param_1);
        uVar1 = 1;
        local_8 = 1;
      }
      local_14 = uVar1;
      piVar2 = (int *)FUN_100073b0(local_1c,param_1[2],param_1[3],local_18,0);
      if ((uVar1 & 2) != 0) {
        uVar1 = uVar1 & 0xfffffffd;
        local_8 = 1;
        local_14 = uVar1;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      local_8 = 0xffffffff;
      if ((uVar1 & 1) != 0) {
        local_14 = uVar1 & 0xfffffffe;
        local_8 = 0xffffffff;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      if (-1 < (int)piVar2) {
        local_1c[4] = param_1[4];
        piVar2 = (int *)FUN_10005ac0((int)local_1c,(int *)&PTR_DAT_10015ad4,(int *)&DAT_10015aec,
                                     param_2);
        if (-1 < (int)piVar2) {
          ExceptionList = local_10;
          return (int)piVar2;
        }
      }
      param_1 = piVar2;
      piVar2 = param_1;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 0x1c))(1);
      }
    }
  }
  ExceptionList = local_10;
  return (int)piVar2;
}



// Function: FUN_10008000 at 10008000

undefined4 * __fastcall FUN_10008000(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012748;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10001e70((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  param_1[1] = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  param_1[2] = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  param_1[3] = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  (**(code **)(*DAT_1001d28c + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10008080 at 10008080

void FUN_10008080(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005ac0(param_1,(int *)&PTR_DAT_10015b70,param_2,param_3);
  return;
}



// Function: FUN_100080a0 at 100080a0

void FUN_100080a0(int param_1)

{
  FUN_10009d30((int *)(param_1 + -4));
  return;
}



// Function: FUN_100080b0 at 100080b0

void FUN_100080b0(int param_1)

{
  FUN_10009d30((int *)(param_1 + -8));
  return;
}



// Function: FUN_100080c0 at 100080c0

void FUN_100080c0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10008080(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_100080d0 at 100080d0

void FUN_100080d0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10008080(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_100080e0 at 100080e0

void FUN_100080e0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10008080(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_100080f0 at 100080f0

void __fastcall FUN_100080f0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100127a1;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  param_1[1] = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  param_1[2] = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  param_1[3] = ATL::CComObject<class_CSecurityLicenseFactory>::vftable;
  local_8 = 0;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_1001d28c + 8))(uVar1);
  local_8 = 1;
  if (param_1[0xc] != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 0xc));
    operator_delete((void *)param_1[0xc]);
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0xb) != '\0') {
    *(undefined1 *)(param_1 + 0xb) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100081c0 at 100081c0

undefined4 * __thiscall FUN_100081c0(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100127d3;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CSecurityLicenseFactory>::vftable;
  FUN_10001e70((int)this + 0xc);
  *(undefined ***)((int)this + 0xc) =
       ATL::CComContainedObject<class_CSecurityLicenseFactory>::vftable;
  *(undefined ***)((int)this + 0x10) =
       ATL::CComContainedObject<class_CSecurityLicenseFactory>::vftable;
  *(undefined ***)((int)this + 0x14) =
       ATL::CComContainedObject<class_CSecurityLicenseFactory>::vftable;
  *(undefined ***)((int)this + 0x18) =
       ATL::CComContainedObject<class_CSecurityLicenseFactory>::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1001d28c + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008260 at 10008260

int FUN_10008260(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  iVar1 = FUN_10005ac0((int)(param_1 + 3),(int *)&PTR_DAT_10015b70,param_2,param_3);
  return iVar1;
}



// Function: FUN_100082d0 at 100082d0

void FUN_100082d0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_100082f0 at 100082f0

LONG FUN_100082f0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_10008320 at 10008320

undefined4 * __thiscall FUN_10008320(void *this,byte param_1)

{
  FUN_100080f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10008350 at 10008350

undefined4 * __thiscall FUN_10008350(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100127fb;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CSecurityLicenseFactory>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1001d28c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10006b00((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100083d0 at 100083d0

DWORD FUN_100083d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012820;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10008000(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_10008477();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_10008477();
  return DVar2;
}



// Function: Catch@10008464 at 10008464

undefined * Catch_10008464(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008471;
}



// Function: FUN_10008477 at 10008477

DWORD FUN_10008477(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_100084e8;
  InterlockedIncrement(unaff_ESI + 4);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 5),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_100084b0;
  }
  else {
LAB_100084b0:
    *(undefined1 *)(unaff_ESI + 0xb) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = 0;
    }
  }
  InterlockedDecrement(unaff_ESI + 4);
  if (unaff_EDI == 0) {
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI == 0) goto LAB_100084e8;
  }
  (**(code **)(*unaff_ESI + 0x10))(1);
LAB_100084e8:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10008500 at 10008500

int * FUN_10008500(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001284b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x4c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_100081c0(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_100085b6();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_100085b6();
  return piVar1;
}



// Function: Catch@100085a1 at 100085a1

undefined * Catch_100085a1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100085ae;
}



// Function: FUN_100085b6 at 100085b6

int * FUN_100085b6(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_100038f0((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_100085e7;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_100085e7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10008600 at 10008600

void FUN_10008600(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_100083d0(0,param_2,param_3);
    return;
  }
  FUN_10008500(param_1,param_2,param_3);
  return;
}



// Function: FUN_10008630 at 10008630

void __fastcall FUN_10008630(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_10006a30(*(undefined4 **)param_1,*(undefined4 **)(param_1 + 4));
    operator_delete(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10008680 at 10008680

void __fastcall FUN_10008680(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10012903;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 8;
  if (*(int *)(param_1 + 0x130) != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 0x130));
    FUN_10006a30(*(undefined4 **)(param_1 + 0x130),*(undefined4 **)(param_1 + 0x134));
    operator_delete(*(void **)(param_1 + 0x130));
  }
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  local_8._0_1_ = 7;
  if (7 < *(uint *)(param_1 + 0x10c)) {
    operator_delete(*(void **)(param_1 + 0xf8));
  }
  *(undefined4 *)(param_1 + 0x10c) = 7;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined2 *)(param_1 + 0xf8) = 0;
  local_8._0_1_ = 6;
  if (7 < *(uint *)(param_1 + 0xf0)) {
    operator_delete(*(void **)(param_1 + 0xdc));
  }
  *(undefined4 *)(param_1 + 0xf0) = 7;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined2 *)(param_1 + 0xdc) = 0;
  local_8._0_1_ = 5;
  if (7 < *(uint *)(param_1 + 0xd4)) {
    operator_delete(*(void **)(param_1 + 0xc0));
  }
  *(undefined4 *)(param_1 + 0xd4) = 7;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined2 *)(param_1 + 0xc0) = 0;
  local_8._0_1_ = 4;
  if (7 < *(uint *)(param_1 + 0xb8)) {
    operator_delete(*(void **)(param_1 + 0xa4));
  }
  *(undefined4 *)(param_1 + 0xb8) = 7;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined2 *)(param_1 + 0xa4) = 0;
  local_8._0_1_ = 3;
  if (7 < *(uint *)(param_1 + 0x9c)) {
    operator_delete(*(void **)(param_1 + 0x88));
  }
  *(undefined4 *)(param_1 + 0x9c) = 7;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined2 *)(param_1 + 0x88) = 0;
  local_8._0_1_ = 2;
  if (7 < *(uint *)(param_1 + 0x80)) {
    operator_delete(*(void **)(param_1 + 0x6c));
  }
  *(undefined4 *)(param_1 + 0x80) = 7;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined2 *)(param_1 + 0x6c) = 0;
  local_8._0_1_ = 1;
  if (7 < *(uint *)(param_1 + 100)) {
    operator_delete(*(void **)(param_1 + 0x50));
  }
  *(undefined4 *)(param_1 + 100) = 7;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined2 *)(param_1 + 0x50) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < *(uint *)(param_1 + 0x48)) {
    operator_delete(*(void **)(param_1 + 0x34));
  }
  *(undefined4 *)(param_1 + 0x48) = 7;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x30) != '\0') {
    *(undefined1 *)(param_1 + 0x30) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100088b0 at 100088b0

void __fastcall FUN_100088b0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100129b3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 8;
  if (*(int *)(param_1 + 0x128) != 0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)(param_1 + 0x128));
    FUN_10006a30(*(undefined4 **)(param_1 + 0x128),*(undefined4 **)(param_1 + 300));
    operator_delete(*(void **)(param_1 + 0x128));
  }
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  local_8._0_1_ = 7;
  if (7 < *(uint *)(param_1 + 0x108)) {
    operator_delete(*(void **)(param_1 + 0xf4));
  }
  *(undefined4 *)(param_1 + 0x108) = 7;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined2 *)(param_1 + 0xf4) = 0;
  local_8._0_1_ = 6;
  if (7 < *(uint *)(param_1 + 0xec)) {
    operator_delete(*(void **)(param_1 + 0xd8));
  }
  *(undefined4 *)(param_1 + 0xec) = 7;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined2 *)(param_1 + 0xd8) = 0;
  local_8._0_1_ = 5;
  if (7 < *(uint *)(param_1 + 0xd0)) {
    operator_delete(*(void **)(param_1 + 0xbc));
  }
  *(undefined4 *)(param_1 + 0xd0) = 7;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined2 *)(param_1 + 0xbc) = 0;
  local_8._0_1_ = 4;
  if (7 < *(uint *)(param_1 + 0xb4)) {
    operator_delete(*(void **)(param_1 + 0xa0));
  }
  *(undefined4 *)(param_1 + 0xb4) = 7;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined2 *)(param_1 + 0xa0) = 0;
  local_8._0_1_ = 3;
  if (7 < *(uint *)(param_1 + 0x98)) {
    operator_delete(*(void **)(param_1 + 0x84));
  }
  *(undefined4 *)(param_1 + 0x98) = 7;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined2 *)(param_1 + 0x84) = 0;
  local_8._0_1_ = 2;
  if (7 < *(uint *)(param_1 + 0x7c)) {
    operator_delete(*(void **)(param_1 + 0x68));
  }
  *(undefined4 *)(param_1 + 0x7c) = 7;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x68) = 0;
  local_8._0_1_ = 1;
  if (7 < *(uint *)(param_1 + 0x60)) {
    operator_delete(*(void **)(param_1 + 0x4c));
  }
  *(undefined4 *)(param_1 + 0x60) = 7;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < *(uint *)(param_1 + 0x44)) {
    operator_delete(*(void **)(param_1 + 0x30));
  }
  *(undefined4 *)(param_1 + 0x44) = 7;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008ad0 at 10008ad0

void __fastcall FUN_10008ad0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100129d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100088b0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008b20 at 10008b20

undefined4 FUN_10008b20(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x28),param_2);
  return 0;
}



// Function: FUN_10008b40 at 10008b40

undefined4 FUN_10008b40(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x28));
  return 0;
}



// Function: FUN_10008b60 at 10008b60

undefined4 FUN_10008b60(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x44),param_2);
  return 0;
}



// Function: FUN_10008b80 at 10008b80

undefined4 FUN_10008b80(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x44));
  return 0;
}



// Function: FUN_10008ba0 at 10008ba0

undefined4 FUN_10008ba0(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x60),param_2);
  return 0;
}



// Function: FUN_10008bc0 at 10008bc0

undefined4 FUN_10008bc0(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x60));
  return 0;
}



// Function: FUN_10008be0 at 10008be0

undefined4 FUN_10008be0(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x7c));
  return 0;
}



// Function: FUN_10008c00 at 10008c00

undefined4 FUN_10008c00(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x78),param_2);
  return 0;
}



// Function: FUN_10008c20 at 10008c20

undefined4 FUN_10008c20(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x78));
  return 0;
}



// Function: FUN_10008c40 at 10008c40

undefined4 FUN_10008c40(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0xb8),param_2);
  return 0;
}



// Function: FUN_10008c60 at 10008c60

undefined4 FUN_10008c60(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0xb8));
  return 0;
}



// Function: FUN_10008c80 at 10008c80

undefined4 FUN_10008c80(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x9c),param_2);
  return 0;
}



// Function: FUN_10008ca0 at 10008ca0

undefined4 FUN_10008ca0(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x9c));
  return 0;
}



// Function: FUN_10008cc0 at 10008cc0

undefined4 FUN_10008cc0(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0xf0),param_2);
  return 0;
}



// Function: FUN_10008ce0 at 10008ce0

undefined4 FUN_10008ce0(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0xf0));
  return 0;
}



// Function: FUN_10008d00 at 10008d00

undefined4 FUN_10008d00(int param_1,int *param_2)

{
  FUN_1000aa20((double *)(param_1 + 0x118),param_2);
  return 0;
}



// Function: FUN_10008d20 at 10008d20

undefined4 FUN_10008d20(int param_1,undefined4 param_2)

{
  FUN_1000a6c0(param_2,(undefined8 *)(param_1 + 0x118));
  return 0;
}



// Function: FUN_10008d40 at 10008d40

undefined4 FUN_10008d40(int param_1,undefined4 *param_2)

{
  FUN_1000a4f0(*(undefined4 *)(param_1 + 0x110),param_2);
  return 0;
}



// Function: FUN_10008d60 at 10008d60

undefined4 FUN_10008d60(int param_1,undefined4 param_2)

{
  FUN_1000a4f0(param_2,(undefined4 *)(param_1 + 0x110));
  return 0;
}



// Function: FUN_10008d80 at 10008d80

undefined4 FUN_10008d80(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0xcc),param_2);
  return 0;
}



// Function: FUN_10008da0 at 10008da0

void FUN_10008da0(int param_1,int *param_2)

{
  FUN_10008c60(param_1 + -8,param_2);
  return;
}



// Function: FUN_10008db0 at 10008db0

void FUN_10008db0(int param_1,int *param_2)

{
  FUN_10008c40(param_1 + -8,param_2);
  return;
}



// Function: FUN_10008dc0 at 10008dc0

void FUN_10008dc0(int param_1,undefined4 param_2)

{
  FUN_10008d20(param_1 + -4,param_2);
  return;
}



// Function: FUN_10008dd0 at 10008dd0

void FUN_10008dd0(int param_1,int *param_2)

{
  FUN_10008d00(param_1 + -4,param_2);
  return;
}



// Function: FUN_10008de0 at 10008de0

void FUN_10008de0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))(*(int **)(param_1 + 0x10));
  return;
}



// Function: FUN_10008e00 at 10008e00

void FUN_10008e00(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))(*(undefined4 **)(param_1 + 0x10),param_2,param_3);
  return;
}



// Function: FUN_10008e20 at 10008e20

void FUN_10008e20(int param_1)

{
  FUN_10006d50(param_1 + -8);
  return;
}



// Function: FUN_10008e30 at 10008e30

void FUN_10008e30(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10008e00(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10008e40 at 10008e40

void FUN_10008e40(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000fa70((void *)(param_1 + -8),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008ee0 at 10008ee0

void FUN_10008ee0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000f080((void *)(param_1 + -8),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008f80 at 10008f80

void FUN_10008f80(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000fd60((void *)(param_1 + -8),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009020 at 10009020

void FUN_10009020(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000f1f0((void *)(param_1 + -0xc),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100090c0 at 100090c0

void FUN_100090c0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_100102e0((void *)(param_1 + -4),(ushort *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009160 at 10009160

void FUN_10009160(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000f8d0((void *)(param_1 + -4),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009200 at 10009200

void FUN_10009200(int param_1)

{
  int *piVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)FUN_1000ed10((undefined2 *)local_30);
  local_8 = 0;
  FUN_1000ab20(piVar1,(void *)(param_1 + 0xb4));
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100092a0 at 100092a0

undefined4 FUN_100092a0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1001cba4 == (int *)0x0) {
    uVar1 = FUN_10007530(&PTR_DAT_1001cb98,param_3);
  }
  *param_4 = DAT_1001cba4;
  if (DAT_1001cba4 != (int *)0x0) {
    (**(code **)(*DAT_1001cba4 + 4))(DAT_1001cba4);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10009300 at 10009300

void FUN_10009300(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10007b30(&PTR_DAT_1001cb98,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10009330 at 10009330

void FUN_10009330(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1001cba4 == (int *)0x0) || (DAT_1001cbac == 0)) {
    FUN_10007530(&PTR_DAT_1001cb98,param_4);
  }
  if (DAT_1001cba4 != (int *)0x0) {
    (**(code **)(*DAT_1001cba4 + 0x2c))
              (DAT_1001cba4,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10009390 at 10009390

undefined4 * __fastcall FUN_10009390(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a98;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000dc10((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  (**(code **)(*DAT_1001d28c + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009410 at 10009410

undefined4 FUN_10009410(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x2c),param_2);
  return 0;
}



// Function: FUN_10009430 at 10009430

undefined4 FUN_10009430(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x2c));
  return 0;
}



// Function: FUN_10009450 at 10009450

undefined4 FUN_10009450(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x48),param_2);
  return 0;
}



// Function: FUN_10009470 at 10009470

undefined4 FUN_10009470(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x48));
  return 0;
}



// Function: FUN_10009490 at 10009490

undefined4 FUN_10009490(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 100),param_2);
  return 0;
}



// Function: FUN_100094b0 at 100094b0

undefined4 FUN_100094b0(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 100));
  return 0;
}



// Function: FUN_100094d0 at 100094d0

undefined4 FUN_100094d0(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x80),param_2);
  return 0;
}



// Function: FUN_100094f0 at 100094f0

undefined4 FUN_100094f0(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0x80));
  return 0;
}



// Function: FUN_10009510 at 10009510

undefined4 FUN_10009510(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0x7c),param_2);
  return 0;
}



// Function: FUN_10009530 at 10009530

undefined4 FUN_10009530(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0xbc),param_2);
  return 0;
}



// Function: FUN_10009550 at 10009550

undefined4 FUN_10009550(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0xbc));
  return 0;
}



// Function: FUN_10009570 at 10009570

undefined4 FUN_10009570(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0xa0),param_2);
  return 0;
}



// Function: FUN_10009590 at 10009590

undefined4 FUN_10009590(int param_1,int *param_2)

{
  FUN_1000ab40(param_2,(void *)(param_1 + 0xa0));
  return 0;
}



// Function: FUN_100095b0 at 100095b0

undefined4 FUN_100095b0(int param_1,int *param_2)

{
  FUN_1000aa20((double *)(param_1 + 0x120),param_2);
  return 0;
}



// Function: FUN_100095d0 at 100095d0

undefined4 FUN_100095d0(int param_1,undefined4 param_2)

{
  FUN_1000a6c0(param_2,(undefined8 *)(param_1 + 0x120));
  return 0;
}



// Function: FUN_100095f0 at 100095f0

undefined4 FUN_100095f0(int param_1,undefined4 *param_2)

{
  FUN_1000a4f0(*(undefined4 *)(param_1 + 0x118),param_2);
  return 0;
}



// Function: FUN_10009610 at 10009610

undefined4 FUN_10009610(int param_1,undefined4 param_2)

{
  FUN_1000a4f0(param_2,(undefined4 *)(param_1 + 0x118));
  return 0;
}



// Function: FUN_10009630 at 10009630

undefined4 FUN_10009630(int param_1,int *param_2)

{
  FUN_1000a9a0((undefined4 *)(param_1 + 0xd0),param_2);
  return 0;
}



// Function: FUN_10009650 at 10009650

undefined4 FUN_10009650(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_10009670 at 10009670

void FUN_10009670(int param_1,int *param_2)

{
  FUN_10009550(param_1 + -8,param_2);
  return;
}



// Function: FUN_10009680 at 10009680

void FUN_10009680(int param_1,int *param_2)

{
  FUN_10009530(param_1 + -8,param_2);
  return;
}



// Function: FUN_10009690 at 10009690

void FUN_10009690(int param_1,undefined4 param_2)

{
  FUN_100095d0(param_1 + -4,param_2);
  return;
}



// Function: FUN_100096a0 at 100096a0

void FUN_100096a0(int param_1,int *param_2)

{
  FUN_100095b0(param_1 + -4,param_2);
  return;
}



// Function: FUN_100096b0 at 100096b0

void FUN_100096b0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



// Function: FUN_100096d0 at 100096d0

LONG FUN_100096d0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_10009700 at 10009700

void FUN_10009700(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005ac0(param_1,(int *)&PTR_DAT_10015dd8,param_2,param_3);
  return;
}



// Function: FUN_10009720 at 10009720

void FUN_10009720(int param_1)

{
  FUN_100096d0((int *)(param_1 + -8));
  return;
}



// Function: FUN_10009730 at 10009730

void FUN_10009730(int param_1)

{
  FUN_100096d0((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_10009740 at 10009740

void FUN_10009740(int param_1)

{
  FUN_100096b0(param_1 + -4);
  return;
}



// Function: FUN_10009750 at 10009750

void FUN_10009750(int param_1)

{
  FUN_100096d0((int *)(param_1 + -0x10));
  return;
}



// Function: FUN_10009760 at 10009760

void FUN_10009760(int param_1)

{
  FUN_100096b0(param_1 + -8);
  return;
}



// Function: FUN_10009770 at 10009770

void FUN_10009770(int param_1)

{
  FUN_100096b0(param_1 + -0xc);
  return;
}



// Function: FUN_10009780 at 10009780

void FUN_10009780(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009700(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10009790 at 10009790

void FUN_10009790(int param_1)

{
  FUN_100096b0(param_1 + -0x10);
  return;
}



// Function: FUN_100097a0 at 100097a0

void FUN_100097a0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009700(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_100097b0 at 100097b0

void FUN_100097b0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009700(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_100097c0 at 100097c0

void FUN_100097c0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009700(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_100097d0 at 100097d0

void FUN_100097d0(int param_1)

{
  FUN_100096d0((int *)(param_1 + -4));
  return;
}



// Function: FUN_100097e0 at 100097e0

void FUN_100097e0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000ccf0((void *)(param_1 + -8),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009880 at 10009880

void FUN_10009880(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000c450((void *)(param_1 + -8),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009920 at 10009920

void FUN_10009920(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000d590((void *)(param_1 + -8),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100099c0 at 100099c0

void FUN_100099c0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000c8c0((void *)(param_1 + -0xc),(undefined2 *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009a60 at 10009a60

void FUN_10009a60(int param_1,int *param_2)

{
  undefined4 *puVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1000cf60((void *)(param_1 + -4),(ushort *)local_30);
  local_8 = 0;
  FUN_1000a9a0(puVar1,param_2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009b00 at 10009b00

void FUN_10009b00(int param_1,int *param_2)

{
  int *piVar1;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a08;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)FUN_1000c350((undefined2 *)local_30,param_2);
  local_8 = 0;
  FUN_1000ab20(piVar1,(void *)(param_1 + 0xb8));
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009ba0 at 10009ba0

undefined4 FUN_10009ba0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1001cd60 == (int *)0x0) {
    uVar1 = FUN_10007530(&PTR_DAT_1001cd54,param_3);
  }
  *param_4 = DAT_1001cd60;
  if (DAT_1001cd60 != (int *)0x0) {
    (**(code **)(*DAT_1001cd60 + 4))(DAT_1001cd60);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10009c00 at 10009c00

void FUN_10009c00(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10007b30(&PTR_DAT_1001cd54,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10009c30 at 10009c30

void FUN_10009c30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1001cd60 == (int *)0x0) || (DAT_1001cd68 == 0)) {
    FUN_10007530(&PTR_DAT_1001cd54,param_4);
  }
  if (DAT_1001cd60 != (int *)0x0) {
    (**(code **)(*DAT_1001cd60 + 0x2c))
              (DAT_1001cd60,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10009c90 at 10009c90

undefined4 * __fastcall FUN_10009c90(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a38;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100108c0((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  (**(code **)(*DAT_1001d28c + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009d10 at 10009d10

void FUN_10009d10(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



// Function: FUN_10009d30 at 10009d30

LONG FUN_10009d30(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_10009d60 at 10009d60

void FUN_10009d60(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10005ac0(param_1,(int *)&PTR_DAT_10015f48,param_2,param_3);
  return;
}



// Function: FUN_10009d80 at 10009d80

void FUN_10009d80(int param_1)

{
  FUN_10009d30((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_10009d90 at 10009d90

void FUN_10009d90(int param_1)

{
  FUN_10009d10(param_1 + -4);
  return;
}



// Function: FUN_10009da0 at 10009da0

void FUN_10009da0(int param_1)

{
  FUN_10009d10(param_1 + -8);
  return;
}



// Function: FUN_10009db0 at 10009db0

void FUN_10009db0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009d60(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10009dc0 at 10009dc0

void FUN_10009dc0(int param_1)

{
  FUN_10009d10(param_1 + -0xc);
  return;
}



// Function: FUN_10009dd0 at 10009dd0

void FUN_10009dd0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009d60(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10009de0 at 10009de0

void FUN_10009de0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10009d60(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10009df0 at 10009df0

undefined4 * __thiscall FUN_10009df0(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012a73;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CUsageCountLicenseImpl>::vftable;
  FUN_100108c0((int)this + 0x10);
  *(undefined ***)((int)this + 0x10) =
       ATL::CComContainedObject<class_CUsageCountLicenseImpl>::vftable;
  *(undefined ***)((int)this + 0x14) =
       ATL::CComContainedObject<class_CUsageCountLicenseImpl>::vftable;
  *(undefined ***)((int)this + 0x18) =
       ATL::CComContainedObject<class_CUsageCountLicenseImpl>::vftable;
  *(undefined ***)((int)this + 0x1c) =
       ATL::CComContainedObject<class_CUsageCountLicenseImpl>::vftable;
  *(undefined4 *)((int)this + 0x20) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_1001d28c + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009e90 at 10009e90

int FUN_10009e90(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  iVar1 = FUN_10005ac0((int)(param_1 + 4),(int *)&PTR_DAT_10015f48,param_2,param_3);
  return iVar1;
}



// Function: FUN_10009f00 at 10009f00

undefined4 * __thiscall FUN_10009f00(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012a98;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComObject<class_CToolLevelLicenseImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x14) = 0xc0000001;
  (**(code **)(*DAT_1001d28c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10008680((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009fa0 at 10009fa0

undefined4 * __thiscall FUN_10009fa0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012a38;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<class_CUsageCountLicenseImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_1001d28c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100088b0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000a030 at 1000a030

undefined4 * __thiscall FUN_1000a030(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012ad3;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CUsageCountLicenseImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_1001d28c + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_100088b0((int)this + 0x10);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000a0c0 at 1000a0c0

DWORD FUN_1000a0c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012af0;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x140);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10009390(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000a16a();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000a16a();
  return DVar2;
}



// Function: Catch@1000a157 at 1000a157

undefined * Catch_1000a157(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a164;
}



// Function: FUN_1000a16a at 1000a16a

DWORD FUN_1000a16a(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_1000a1db;
  InterlockedIncrement(unaff_ESI + 5);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 6),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000a1a3;
  }
  else {
LAB_1000a1a3:
    *(undefined1 *)(unaff_ESI + 0xc) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = 0;
    }
  }
  InterlockedDecrement(unaff_ESI + 5);
  if (unaff_EDI == 0) {
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI == 0) goto LAB_1000a1db;
  }
  (**(code **)(*unaff_ESI + 0x10))(1);
LAB_1000a1db:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000a200 at 1000a200

DWORD FUN_1000a200(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012b10;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x138);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10009c90(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_1000a2aa();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_1000a2aa();
  return DVar2;
}



// Function: Catch@1000a297 at 1000a297

undefined * Catch_1000a297(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a2a4;
}



// Function: FUN_1000a2aa at 1000a2aa

DWORD FUN_1000a2aa(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_1000a31b;
  InterlockedIncrement(unaff_ESI + 4);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 5),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000a2e3;
  }
  else {
LAB_1000a2e3:
    *(undefined1 *)(unaff_ESI + 0xb) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = 0;
    }
  }
  InterlockedDecrement(unaff_ESI + 4);
  if (unaff_EDI == 0) {
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI == 0) goto LAB_1000a31b;
  }
  (**(code **)(*unaff_ESI + 0x10))(1);
LAB_1000a31b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000a340 at 1000a340

int * FUN_1000a340(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012b3b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x148);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_10009df0(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_1000a3f9();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_1000a3f9();
  return piVar1;
}



// Function: Catch@1000a3e4 at 1000a3e4

undefined * Catch_1000a3e4(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000a3f1;
}



// Function: FUN_1000a3f9 at 1000a3f9

int * FUN_1000a3f9(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_100038b0((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_1000a42a;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_1000a42a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_1000a440 at 1000a440

DWORD FUN_1000a440(int param_1,undefined4 param_2,undefined4 *param_3)

{
  DWORD DVar1;
  
  if (param_1 == 0) {
    DVar1 = FUN_1000a0c0(0,param_2,param_3);
    return DVar1;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  return 0x80040110;
}



// Function: FUN_1000a480 at 1000a480

void FUN_1000a480(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_1000a200(0,param_2,param_3);
    return;
  }
  FUN_1000a340(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000a4b0 at 1000a4b0

void __thiscall FUN_1000a4b0(void *this,undefined8 param_1)

{
  *(undefined8 *)this = param_1;
  return;
}



// Function: FUN_1000a4c0 at 1000a4c0

void __thiscall FUN_1000a4c0(void *this,int param_1,int param_2,int param_3,int param_4)

{
  *(double *)this =
       (double)param_4 / 86400.0 +
       (double)param_3 / 1440.0 + (double)param_2 / 24.0 + (double)param_1;
  return;
}



// Function: FUN_1000a4f0 at 1000a4f0

void __cdecl FUN_1000a4f0(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = param_1;
  return;
}



// Function: FUN_1000a500 at 1000a500

undefined4 __thiscall FUN_1000a500(void *this,double *param_1)

{
  double _X;
  double dVar1;
  double dVar2;
  
                    /* WARNING: Load size is inaccurate */
  _X = *this;
  if (NAN(_X) || 0.0 < _X == (_X == 0.0)) {
    dVar1 = ceil(_X);
    _X = dVar1 - (_X - dVar1);
  }
  dVar1 = *param_1;
  if (NAN(dVar1) || 0.0 < dVar1 == (dVar1 == 0.0)) {
    dVar2 = ceil(dVar1);
    dVar1 = dVar2 - (dVar1 - dVar2);
  }
  if (dVar1 < _X) {
    return 1;
  }
  return 0;
}



// Function: FUN_1000a580 at 1000a580

void __thiscall
FUN_1000a580(void *this,undefined2 param_1,ushort param_2,undefined2 param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6)

{
  double dVar1;
  int iVar2;
  undefined2 local_18;
  uint local_16;
  undefined2 local_12;
  undefined2 uStack_10;
  undefined2 local_e;
  undefined2 uStack_c;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  local_a = 0;
  local_18 = param_1;
  local_16 = (uint)param_2;
  _local_12 = CONCAT22(param_4,param_3);
  _local_e = CONCAT22(param_6,param_5);
  iVar2 = Ordinal_184(&local_18,this);
  if (iVar2 == 0) {
    *(undefined8 *)this = 0xc124103600000000;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    dVar1 = *this;
                    /* WARNING: Load size is inaccurate */
    if ((!NAN(dVar1) && -657434.0 < dVar1 != (dVar1 == -657434.0)) && (*this <= 2958465.0)) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a630 at 1000a630

void __cdecl FUN_1000a630(undefined8 param_1)

{
  int iVar1;
  tm *unaff_ESI;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  ushort local_12;
  ushort local_10;
  ushort local_e;
  ushort local_c;
  uint local_8;
  
  local_8 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  iVar1 = Ordinal_185(param_1,&local_18);
  if (iVar1 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  unaff_ESI->tm_sec = (uint)local_c;
  unaff_ESI->tm_min = (uint)local_e;
  unaff_ESI->tm_hour = (uint)local_10;
  unaff_ESI->tm_mday = (uint)local_12;
  unaff_ESI->tm_mon = local_16 - 1;
  unaff_ESI->tm_year = local_18 - 0x76c;
  unaff_ESI->tm_wday = (uint)local_14;
  unaff_ESI->tm_isdst = -1;
  _mktime64(unaff_ESI);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a6c0 at 1000a6c0

void __cdecl FUN_1000a6c0(undefined4 param_1,undefined8 *param_2)

{
  int iVar1;
  
  iVar1 = Ordinal_94(param_1,0x409,0,param_2);
  if (iVar1 < 0) {
    *param_2 = 0xc124103600000000;
  }
  return;
}



// Function: FUN_1000a6f0 at 1000a6f0

uint __thiscall FUN_1000a6f0(void *this,ushort *param_1,uint param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar3 = *(uint *)((int)this + 0x10) - param_2, param_3 <= uVar3)) {
      iVar7 = uVar3 + (1 - param_3);
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      puVar1 = (ushort *)((int)pvVar4 + param_2 * 2);
      for (; iVar7 != 0; iVar7 = iVar7 + (-1 - (iVar5 >> 1))) {
        puVar2 = puVar1;
        iVar5 = iVar7;
        while (*puVar2 != *param_1) {
          puVar2 = puVar2 + 1;
          iVar5 = iVar5 + -1;
          if (iVar5 == 0) goto LAB_1000a74c;
        }
        if (puVar2 == (ushort *)0x0) break;
        puVar6 = puVar2;
        puVar8 = param_1;
        uVar3 = param_3;
        if (param_3 == 0) {
LAB_1000a775:
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
            this = *this;
          }
          return (int)puVar2 - (int)this >> 1;
        }
        while (*puVar6 == *puVar8) {
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
          uVar3 = uVar3 - 1;
          if (uVar3 == 0) goto LAB_1000a775;
        }
        if ((-(uint)(*puVar6 < *puVar8) & 0xfffffffe) == 0xffffffff) goto LAB_1000a775;
        iVar5 = (int)puVar2 - (int)puVar1;
        puVar1 = puVar2 + 1;
      }
    }
LAB_1000a74c:
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_1000a7b0 at 1000a7b0

void __thiscall FUN_1000a7b0(void *this,wchar_t *param_1,wchar_t *param_2)

{
  double dVar1;
  char cVar2;
  tm local_2c;
  uint local_8;
  
  local_8 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  *param_1 = L'\0';
                    /* WARNING: Load size is inaccurate */
  dVar1 = *this;
                    /* WARNING: Load size is inaccurate */
  if ((!NAN(dVar1) && -657434.0 < dVar1 != (dVar1 == -657434.0)) && (*this <= 2958465.0)) {
                    /* WARNING: Load size is inaccurate */
    cVar2 = FUN_1000a630(*this);
    if (cVar2 != '\0') {
      wcsftime(param_1,0x1000,param_2,&local_2c);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000a830 at 1000a830

double * __cdecl FUN_1000a830(double *param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  
  *param_1 = -657435.0;
  dVar1 = *param_2;
  if ((((!NAN(dVar1) && -657434.0 < dVar1 != (dVar1 == -657434.0)) && (*param_2 <= 2958465.0)) &&
      (dVar1 = *param_3, !NAN(dVar1) && -3615897.0 < dVar1 != (dVar1 == -3615897.0))) &&
     (*param_3 <= 3615897.0)) {
    dVar1 = *param_2;
    if (NAN(dVar1) || 0.0 < dVar1 == (dVar1 == 0.0)) {
      dVar2 = ceil(dVar1);
      dVar1 = dVar2 - (dVar1 - dVar2);
    }
    dVar1 = dVar1 + *param_3;
    if (NAN(dVar1) || 0.0 < dVar1 == (dVar1 == 0.0)) {
      dVar2 = floor(dVar1);
      dVar1 = (dVar2 - dVar1) + dVar2;
    }
    *param_1 = dVar1;
  }
  return param_1;
}



// Function: FUN_1000a8e0 at 1000a8e0

double * __cdecl FUN_1000a8e0(double *param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  *param_1 = -3615898.0;
  dVar1 = *param_2;
  if ((!NAN(dVar1) && -657434.0 < dVar1 != (dVar1 == -657434.0)) && (*param_2 <= 2958465.0)) {
    dVar1 = *param_3;
    if (NAN(dVar1) || -657434.0 < dVar1 == (dVar1 == -657434.0)) {
      return param_1;
    }
    if (*param_3 <= 2958465.0) {
      dVar1 = *param_2;
      if (NAN(dVar1) || 0.0 < dVar1 == (dVar1 == 0.0)) {
        dVar2 = ceil(dVar1);
        dVar1 = dVar2 - (dVar1 - dVar2);
      }
      dVar2 = *param_3;
      if (NAN(dVar2) || 0.0 < dVar2 == (dVar2 == 0.0)) {
        dVar3 = ceil(dVar2);
        dVar2 = dVar3 - (dVar2 - dVar3);
      }
      *param_1 = dVar1 - dVar2;
    }
    return param_1;
  }
  return param_1;
}



// Function: FUN_1000a9a0 at 1000a9a0

void __cdecl FUN_1000a9a0(undefined4 *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012bc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Ordinal_2(param_1,DAT_1001d274 ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0) {
      FUN_10002160(0x8007000e);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  *param_2 = iVar2;
  local_8 = 0xffffffff;
  Ordinal_6(0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000aa20 at 1000aa20

void __cdecl FUN_1000aa20(double *param_1,int *param_2)

{
  double dVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  tm local_9c;
  wchar_t local_78 [50];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012bfb;
  local_10 = ExceptionList;
  uVar3 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  dVar1 = *param_1;
  local_78[0] = L'\0';
  local_14 = uVar3;
  if ((!NAN(dVar1) && -657434.0 < dVar1 != (dVar1 == -657434.0)) && (*param_1 <= 2958465.0)) {
    cVar2 = FUN_1000a630(*param_1);
    if (cVar2 != '\0') {
      wcsftime(local_78,0x1000,L"%d-%b-%Y",&local_9c);
    }
  }
  uVar5 = 0;
  Ordinal_6();
  iVar4 = Ordinal_2(local_78,uVar5,uVar3);
  if (iVar4 == 0) {
    iVar4 = FUN_10002160(0x8007000e);
  }
  *param_2 = iVar4;
  local_8 = 0xffffffff;
  Ordinal_6(0);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ab20 at 1000ab20

void __cdecl FUN_1000ab20(int *param_1,void *param_2)

{
  FUN_100018b0(param_2,param_1,0,0xffffffff);
  return;
}



// Function: FUN_1000ab40 at 1000ab40

void __cdecl FUN_1000ab40(int *param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(param_2,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return;
}



// Function: FUN_1000ab70 at 1000ab70

int __cdecl FUN_1000ab70(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  ushort *extraout_ECX;
  ushort *puVar5;
  ushort ******ppppppuVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  ulonglong uVar10;
  int local_20;
  ushort *****local_1c;
  ushort *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012c3e;
  local_10 = ExceptionList;
  uVar3 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  if ((DAT_1001d328 & 1) == 0) {
    DAT_1001d328 = DAT_1001d328 | 1;
    local_8 = 0;
    DAT_1001d320 = 7;
    DAT_1001d31c = (ushort *)0x0;
    DAT_1001d30c = (ushort *)((uint)DAT_1001d30c & 0xffff0000);
    FUN_100019b0(&DAT_1001d30c,(int *)L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",0x24);
    _atexit((_func_4879 *)&LAB_10014010);
  }
  local_8 = 0xffffffff;
  iVar1 = param_1[4];
  local_20 = 0;
  if (iVar1 < 1) {
    ExceptionList = local_10;
    return 0;
  }
  uVar2 = param_1[5];
  do {
    puVar8 = DAT_1001d31c;
    local_1c = (ushort *****)((iVar1 - local_20) + -1);
    _CIpow(uVar3);
    puVar4 = param_1;
    if (7 < uVar2) {
      puVar4 = (undefined4 *)*param_1;
    }
    ppppppuVar6 = (ushort ******)(uint)*(ushort *)((int)puVar4 + local_20 * 2);
    local_1c = (ushort *****)ppppppuVar6;
    puVar5 = extraout_ECX;
    if ((puVar8 != (ushort *)0x0) && (local_18 = puVar8, puVar5 = puVar8, puVar8 != (ushort *)0x0))
    {
      puVar8 = DAT_1001d30c;
      puVar5 = local_18;
      puVar9 = DAT_1001d30c;
      if (DAT_1001d320 < 8) {
        puVar8 = (ushort *)&DAT_1001d30c;
        puVar9 = puVar8;
      }
      while (puVar5 != (ushort *)0x0) {
        if (*puVar8 == (ushort)ppppppuVar6) {
          if (puVar8 == (ushort *)0x0) break;
          iVar7 = 1;
          ppppppuVar6 = &local_1c;
          puVar5 = puVar8;
          while (*puVar5 == *(ushort *)ppppppuVar6) {
            puVar5 = puVar5 + 1;
            ppppppuVar6 = (ushort ******)((int)ppppppuVar6 + 2);
            iVar7 = iVar7 + -1;
            if (iVar7 == 0) goto LAB_1000aca4;
          }
          ppppppuVar6 = (ushort ******)
                        ((-(uint)(*puVar5 < *(ushort *)ppppppuVar6) & 0xfffffffe) + 1);
          if (ppppppuVar6 == (ushort ******)0x0) {
LAB_1000aca4:
            puVar5 = DAT_1001d30c;
            if (DAT_1001d320 < 8) {
              puVar5 = (ushort *)&DAT_1001d30c;
            }
            break;
          }
          local_18 = (ushort *)((int)local_18 + (-1 - ((int)puVar8 - (int)puVar9 >> 1)));
          puVar8 = puVar8 + 1;
          puVar5 = local_18;
          puVar9 = puVar8;
          ppppppuVar6 = (ushort ******)local_1c;
        }
        else {
          puVar8 = puVar8 + 1;
          puVar5 = (ushort *)((int)puVar5 + -1);
        }
      }
    }
    uVar10 = FUN_100110d0(puVar5,ppppppuVar6);
    local_14 = local_14 + (int)uVar10;
    local_20 = local_20 + 1;
    if (iVar1 <= local_20) {
      ExceptionList = local_10;
      return local_14;
    }
  } while( true );
}



// Function: FUN_1000ad40 at 1000ad40

void FUN_1000ad40(int param_1,undefined4 param_2)

{
  (*(code *)**(undefined4 **)(param_1 + -4))(param_1 + -4,&DAT_10015e4c,param_2);
  return;
}



// Function: FUN_1000ad60 at 1000ad60

void __fastcall FUN_1000ad60(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar1;
  
  pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*(int *)*param_1 + 4) + *param_1));
  if (pbVar1 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*(int *)*param_1 + 4) + *param_1));
                    /* WARNING: Could not recover jumptable at 0x1000ad8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)pbVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_1000ada0 at 1000ada0

undefined4 FUN_1000ada0(int param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  *param_2 = (*(int *)(param_1 + 0x124) - *(int *)(param_1 + 0x120)) / 0x1c;
  return 0;
}



// Function: FUN_1000ade0 at 1000ade0

ulonglong __fastcall FUN_1000ade0(int param_1,uint param_2)

{
  double dVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  double local_14;
  double local_c;
  
  dVar1 = *(double *)(param_1 + 0x128);
  if ((!NAN(dVar1) && -657434.0 < dVar1 != (dVar1 == -657434.0)) &&
     (*(double *)(param_1 + 0x128) <= 2958465.0)) {
    FUN_1000a580(&local_c,2000,1,1,0,0,0);
    FUN_1000a8e0(&local_14,(double *)(param_1 + 0x128),&local_c);
    uVar2 = FUN_100110d0(extraout_ECX,extraout_EDX);
    return uVar2;
  }
  return (ulonglong)param_2 << 0x20;
}



// Function: FUN_1000ae50 at 1000ae50

float10 FUN_1000ae50(int *param_1)

{
  double local_1c;
  double local_14;
  double local_c;
  
  FUN_1000a580(&local_1c,2000,1,1,0,0,0);
  FUN_1000a4c0(&local_14,*param_1,0,0,0);
  FUN_1000a830(&local_c,&local_1c,&local_14);
  if (*param_1 == 0) {
    FUN_1000a4b0(&local_c,0x4146924080000000);
  }
  return (float10)local_c;
}



// Function: FUN_1000aec0 at 1000aec0

void __fastcall
FUN_1000aec0(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  if (((byte)param_1[0x40] & 1) != 0) {
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr(param_1);
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



// Function: FUN_1000af20 at 1000af20

void * __cdecl FUN_1000af20(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100119e9;
  local_10 = ExceptionList;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  ExceptionList = &local_10;
  if ((param_1 < (char *)0x924924a) &&
     (pvVar1 = operator_new((int)param_1 * 0x1c), pvVar1 != (void *)0x0)) {
    ExceptionList = local_10;
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10017f24);
}



// Function: FUN_1000afc0 at 1000afc0

uint __thiscall FUN_1000afc0(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

{
  uint extraout_EAX;
  ushort *puVar1;
  undefined4 *extraout_ECX;
  uint uVar2;
  
  uVar2 = *(uint *)((int)this + 0x10);
  if (uVar2 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
    this = extraout_ECX;
  }
  if (uVar2 - param_1 < param_2) {
    param_2 = uVar2 - param_1;
  }
  uVar2 = param_2;
  if (param_4 <= param_2) {
    uVar2 = param_4;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  puVar1 = (ushort *)((int)this + param_1 * 2);
  do {
    if (uVar2 == 0) {
LAB_1000b028:
      if (param_4 <= param_2) {
        return (uint)(param_2 != param_4);
      }
      return 0xffffffff;
    }
    if (*puVar1 != *param_3) {
      uVar2 = (-(uint)(*puVar1 < *param_3) & 0xfffffffe) + 1;
      if (uVar2 != 0) {
        return uVar2;
      }
      goto LAB_1000b028;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_1000b050 at 1000b050

int * __thiscall FUN_1000b050(void *this,int *param_1)

{
  bool bVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012c68;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(int **)this = param_1;
  pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*param_1 + 4) + (int)param_1));
  if (pbVar3 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
                    /* WARNING: Load size is inaccurate */
    pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**this + 4) + (int)*this));
    (**(code **)(*(int *)pbVar3 + 4))(uVar2);
  }
  local_8 = 0;
  bVar1 = std::ios_base::good((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if (bVar1) {
    pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::tie
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*param_1 + 4) + (int)param_1));
    if (pbVar4 != (basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::tie
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::flush(pbVar4);
    }
  }
  bVar1 = std::ios_base::good((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  *(bool *)((int)this + 4) = bVar1;
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_1000b120 at 1000b120

void __fastcall FUN_1000b120(int *param_1)

{
  bool bVar1;
  uint uVar2;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012c98;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)*param_1);
  }
  local_8 = 0xffffffff;
  pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*(int *)*param_1 + 4) + *param_1));
  if (pbVar3 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar3 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*(int *)*param_1 + 4) + *param_1));
    (**(code **)(*(int *)pbVar3 + 8))(uVar2);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b1b0 at 1000b1b0

int FUN_1000b1b0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012ce0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  iVar1 = (**(code **)*param_1)(param_1,param_2,&local_14,DAT_1001d274 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar1) {
    local_8 = 0xffffffff;
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
    ExceptionList = local_10;
    return iVar1;
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_1000b260 at 1000b260

undefined4
FUN_1000b260(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int *param_6)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012d08;
  local_10 = ExceptionList;
  if (param_6 == (int *)0x0) {
    return 0x80004003;
  }
  if ((*(int *)(param_1 + 0x124) - *(int *)(param_1 + 0x120)) / 0x1c < param_4) {
    return 0x80070057;
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x120) + -0x1c + param_4 * 0x1c);
  if (7 < *(uint *)(*(int *)(param_1 + 0x120) + -8 + param_4 * 0x1c)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  ExceptionList = &local_10;
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = Ordinal_2(puVar2,DAT_1001d274 ^ (uint)&stack0xfffffffc);
    if (iVar3 == 0) {
      FUN_10002160(0x8007000e);
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
  *param_6 = iVar3;
  local_8 = 0xffffffff;
  Ordinal_6(0);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000b360 at 1000b360

void __fastcall
FUN_1000b360(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012d39;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8 = 0;
  FUN_1000aec0(param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b3c0 at 1000b3c0

ushort __fastcall
FUN_1000b3c0(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if (puVar4 == (ushort *)0x0) {
    return 0xffff;
  }
  iVar1 = **(int **)(param_1 + 0x30);
  iVar2 = **(int **)(param_1 + 0x20);
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if (puVar4 < (ushort *)(iVar2 + iVar1 * 2)) {
    puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                       (param_1);
    return *puVar4;
  }
  if ((((byte)param_1[0x40] & 4) != 0) ||
     (puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         (param_1), puVar4 == (ushort *)0x0)) {
    return 0xffff;
  }
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     (param_1);
  puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  if ((puVar4 <= puVar5) &&
     (puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         (param_1), *(ushort **)(param_1 + 0x3c) <= puVar4)) {
    return 0xffff;
  }
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     (param_1);
  if (*(ushort **)(param_1 + 0x3c) < puVar4) {
    puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       (param_1);
    *(ushort **)(param_1 + 0x3c) = puVar4;
  }
  iVar1 = *(int *)(param_1 + 0x3c);
  uVar3 = **(undefined4 **)(param_1 + 0x10);
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  **(undefined4 **)(param_1 + 0x10) = uVar3;
  **(undefined4 **)(param_1 + 0x20) = puVar4;
  **(int **)(param_1 + 0x30) = iVar1 - (int)puVar4 >> 1;
  puVar4 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     (param_1);
  return *puVar4;
}



// Function: FUN_1000b490 at 1000b490

void __thiscall
FUN_1000b490(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((puVar2 != (ushort *)0x0) &&
     (puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), *(ushort **)((int)this + 0x3c) < puVar2)) {
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    *(ushort **)((int)this + 0x3c) = puVar2;
  }
  if (((param_5 & 1) == 0) ||
     (puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar2 == (ushort *)0x0)) {
    if (((param_5 & 2) == 0) ||
       (puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this), puVar2 == (ushort *)0x0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_1000b6a4;
    }
    else {
      if (param_4 == 2) {
        iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        uVar4 = iVar3 >> 1;
        bVar7 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 == 1) {
        iVar3 = **(int **)((int)this + 0x10);
        puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        iVar3 = (int)puVar2 - iVar3;
        uVar4 = iVar3 >> 1;
        bVar7 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        iVar3 = **(int **)((int)this + 0x10);
        iVar5 = *(int *)((int)this + 0x3c) - iVar3;
        iVar6 = iVar5 >> 0x1f;
        if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= (uint)(iVar5 >> 1)))))
        {
          puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                    ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                     this,(iVar3 - (int)puVar2 >> 1) + param_2);
          goto LAB_1000b6a4;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar3 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      uVar4 = iVar3 >> 1;
      bVar7 = CARRY4(param_2,uVar4);
      param_2 = param_2 + uVar4;
      param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar7;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        iVar3 = **(int **)((int)this + 0x10);
        puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        iVar3 = (int)puVar2 - iVar3;
        uVar4 = iVar3 >> 1;
        bVar7 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + (iVar3 >> 0x1f) + (uint)bVar7;
      }
      else {
LAB_1000b521:
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else if (param_4 != 0) goto LAB_1000b521;
    if (-1 < (int)param_3) {
      iVar3 = **(int **)((int)this + 0x10);
      iVar5 = *(int *)((int)this + 0x3c) - iVar3;
      iVar6 = iVar5 >> 0x1f;
      if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= (uint)(iVar5 >> 1))))) {
        puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   (iVar3 - (int)puVar2 >> 1) + param_2);
        if (((param_5 & 2) != 0) &&
           (puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                     pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar2 != (ushort *)0x0)) {
          iVar3 = **(int **)((int)this + 0x34);
          iVar5 = **(int **)((int)this + 0x24);
          uVar1 = **(undefined4 **)((int)this + 0x14);
          puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          **(undefined4 **)((int)this + 0x14) = uVar1;
          **(undefined4 **)((int)this + 0x24) = puVar2;
          **(int **)((int)this + 0x34) = (iVar5 + iVar3 * 2) - (int)puVar2 >> 1;
        }
        goto LAB_1000b6a4;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_1000b6a4:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_1000b6c0 at 1000b6c0

void __thiscall FUN_1000b6c0(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint in_stack_00000020;
  uint local_8;
  
  uVar6 = param_4 + param_2;
  local_8 = ((int)param_4 >> 0x1f) + param_3 + (uint)CARRY4(param_4,param_2);
  puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((puVar3 != (ushort *)0x0) &&
     (puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), *(ushort **)((int)this + 0x3c) < puVar3)) {
    puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    *(ushort **)((int)this + 0x3c) = puVar3;
  }
  if ((uVar6 != *(uint *)_BADOFF_exref) || (local_8 != *(uint *)(_BADOFF_exref + 4))) {
    if (((in_stack_00000020 & 1) == 0) ||
       (puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this), puVar3 == (ushort *)0x0)) {
      if (((in_stack_00000020 & 2) != 0) &&
         (puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this), puVar3 != (ushort *)0x0)) {
        if (-1 < (int)local_8) {
          iVar1 = **(int **)((int)this + 0x10);
          iVar4 = *(int *)((int)this + 0x3c) - iVar1;
          iVar5 = iVar4 >> 0x1f;
          if (((int)local_8 <= iVar5) && (((int)local_8 < iVar5 || (uVar6 <= (uint)(iVar4 >> 1)))))
          {
            puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                     pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
            std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pbump
                      ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       this,(iVar1 - (int)puVar3 >> 1) + uVar6);
            goto LAB_1000b830;
          }
        }
        local_8 = *(uint *)(_BADOFF_exref + 4);
        uVar6 = *(uint *)_BADOFF_exref;
        goto LAB_1000b830;
      }
    }
    else if (-1 < (int)local_8) {
      iVar1 = **(int **)((int)this + 0x10);
      iVar4 = *(int *)((int)this + 0x3c) - iVar1;
      iVar5 = iVar4 >> 0x1f;
      if (((int)local_8 <= iVar5) && (((int)local_8 < iVar5 || (uVar6 <= (uint)(iVar4 >> 1))))) {
        puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
                  ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,
                   (iVar1 - (int)puVar3 >> 1) + uVar6);
        if (((in_stack_00000020 & 2) != 0) &&
           (puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                     pptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar3 != (ushort *)0x0)) {
          iVar1 = **(int **)((int)this + 0x34);
          iVar4 = **(int **)((int)this + 0x24);
          uVar2 = **(undefined4 **)((int)this + 0x14);
          puVar3 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
                   gptr((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
          **(undefined4 **)((int)this + 0x14) = uVar2;
          **(undefined4 **)((int)this + 0x24) = puVar3;
          **(int **)((int)this + 0x34) = (iVar4 + iVar1 * 2) - (int)puVar3 >> 1;
        }
        goto LAB_1000b830;
      }
    }
    uVar6 = *(uint *)_BADOFF_exref;
    local_8 = *(uint *)(_BADOFF_exref + 4);
  }
LAB_1000b830:
  param_1[1] = local_8;
  *param_1 = uVar6;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_1000b850 at 1000b850

ushort __thiscall FUN_1000b850(void *this,ushort param_1)

{
  void *pvVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  void *_Src;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  char *pcVar8;
  void *pvVar9;
  uint uVar10;
  
  if (((*(byte *)((int)this + 0x40) & 8) != 0) &&
     (puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this), puVar5 != (ushort *)0x0)) {
    puVar5 = *(ushort **)((int)this + 0x3c);
    puVar6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar6 < puVar5) {
      iVar3 = **(int **)((int)this + 0x34);
      uVar10 = **(uint **)((int)this + 0x24);
      **(uint **)((int)this + 0x24) = (uint)puVar5;
      **(int **)((int)this + 0x34) = (int)((uVar10 + iVar3 * 2) - (int)puVar5) >> 1;
    }
  }
  if (param_1 == 0xffff) {
    return 0;
  }
  puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((puVar5 != (ushort *)0x0) &&
     (iVar3 = **(int **)((int)this + 0x34), iVar4 = **(int **)((int)this + 0x24),
     puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                        ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), puVar5 < (ushort *)(iVar4 + iVar3 * 2))) {
    puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Pninc
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    *puVar5 = param_1;
    return param_1;
  }
  if ((*(byte *)((int)this + 0x40) & 2) != 0) {
    return 0xffff;
  }
  puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if (puVar5 == (ushort *)0x0) {
    uVar10 = 0;
  }
  else {
    uVar10 = (**(int **)((int)this + 0x34) * 2 - **(int **)((int)this + 0x10)) +
             **(int **)((int)this + 0x24) >> 1;
  }
  uVar7 = uVar10 >> 1;
  if (uVar7 < 0x20) {
    uVar7 = 0x20;
  }
  else if (uVar7 == 0) {
    return 0xffff;
  }
  do {
    if (uVar10 <= 0x7fffffff - uVar7) break;
    uVar7 = uVar7 >> 1;
  } while (uVar7 != 0);
  if (uVar7 != 0) {
    pcVar8 = (char *)(uVar7 + uVar10);
    pvVar9 = FUN_10001210(pcVar8);
    _Src = (void *)**(undefined4 **)((int)this + 0x10);
    if ((uVar10 == 0) || (memcpy(pvVar9,_Src,uVar10 * 2), uVar10 == 0)) {
      *(void **)((int)this + 0x3c) = pvVar9;
      **(undefined4 **)((int)this + 0x14) = pvVar9;
      **(undefined4 **)((int)this + 0x24) = pvVar9;
      **(int **)((int)this + 0x34) = (int)pcVar8 * 2 >> 1;
      bVar2 = *(byte *)((int)this + 0x40);
      **(undefined4 **)((int)this + 0x10) = pvVar9;
      if ((bVar2 & 4) == 0) {
        **(undefined4 **)((int)this + 0x20) = pvVar9;
        **(undefined4 **)((int)this + 0x30) = 1;
      }
      else {
        **(undefined4 **)((int)this + 0x20) = 0;
        **(int **)((int)this + 0x30) = (int)pvVar9 >> 1;
      }
    }
    else {
      *(void **)((int)this + 0x3c) =
           (void *)((int)pvVar9 + (*(int *)((int)this + 0x3c) - (int)_Src >> 1) * 2);
      iVar3 = **(int **)((int)this + 0x14);
      puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      **(int **)((int)this + 0x14) = (int)((int)pvVar9 + (iVar3 - (int)_Src >> 1) * 2);
      pvVar1 = (void *)((int)pvVar9 + ((int)puVar5 - (int)_Src >> 1) * 2);
      **(int **)((int)this + 0x24) = (int)pvVar1;
      **(int **)((int)this + 0x34) = ((int)pcVar8 * 2 - (int)pvVar1) + (int)pvVar9 >> 1;
      if ((*(byte *)((int)this + 0x40) & 4) == 0) {
        puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        puVar6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                           ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                             *)this);
        **(undefined4 **)((int)this + 0x10) = pvVar9;
        pvVar9 = (void *)((int)pvVar9 + ((int)puVar6 - (int)_Src >> 1) * 2);
        **(int **)((int)this + 0x20) = (int)pvVar9;
        **(int **)((int)this + 0x30) = (int)puVar5 + (2 - (int)pvVar9) >> 1;
      }
      else {
        **(undefined4 **)((int)this + 0x10) = pvVar9;
        **(undefined4 **)((int)this + 0x20) = 0;
        **(int **)((int)this + 0x30) = (int)pvVar9 >> 1;
      }
    }
    if ((*(byte *)((int)this + 0x40) & 1) != 0) {
      operator_delete(_Src);
    }
    *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
    puVar5 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Pninc
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    *puVar5 = param_1;
    return param_1;
  }
  return 0xffff;
}



// Function: FUN_1000ba90 at 1000ba90

ushort __thiscall FUN_1000ba90(void *this,ushort param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  if ((puVar1 == (ushort *)0x0) ||
     (puVar1 = (ushort *)**(uint **)((int)this + 0x10),
     puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                        ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *
                         )this), puVar2 <= puVar1)) {
    return 0xffff;
  }
  if ((param_1 != 0xffff) &&
     ((puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                          ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                            *)this), param_1 != puVar1[-1] &&
      ((*(byte *)((int)this + 0x40) & 2) != 0)))) {
    return 0xffff;
  }
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gbump
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this,-1);
  if (param_1 == 0xffff) {
    return 0;
  }
  puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                     ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      this);
  *puVar1 = param_1;
  return param_1;
}



// Function: FUN_1000bb10 at 1000bb10

basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> * __thiscall
FUN_1000bb10(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012d39;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8 = 0;
  FUN_1000aec0((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  local_8 = 0xffffffff;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
}



// Function: FUN_1000bb80 at 1000bb80

void FUN_1000bb80(int *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  __int64 _Var8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined1 local_24 [4];
  char local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012d70;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffc4;
  uVar11 = (undefined2)(DAT_1001d274 ^ (uint)&stack0xfffffffc);
  uVar12 = (undefined2)((DAT_1001d274 ^ (uint)&stack0xfffffffc) >> 0x10);
  ExceptionList = &local_10;
  local_18 = 0;
  puVar2 = param_2;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
  } while (uVar1 != 0);
  uVar3 = (int)puVar2 - (int)(param_2 + 1) >> 1;
  local_1c = uVar3;
  _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((_Var8 < 0) || (((int)((ulonglong)_Var8 >> 0x20) == 0 || _Var8 < 0 && ((int)_Var8 == 0)))) {
LAB_1000bc18:
    iVar6 = 0;
    iVar5 = 0;
  }
  else {
    _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    if ((_Var8 < 0) || ((_Var8 < 0x100000000 && ((uint)_Var8 <= uVar3)))) goto LAB_1000bc18;
    _Var8 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    iVar6 = (uint)_Var8 - local_1c;
    iVar5 = (int)((ulonglong)_Var8 >> 0x20) - (uint)((uint)_Var8 < local_1c);
  }
  FUN_1000b050(local_24,param_1);
  local_8 = 0;
  if (local_20 == '\0') {
    local_18 = 4;
    FUN_1000bd7c();
    return;
  }
  local_8 = 1;
  uVar3 = std::ios_base::flags((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((uVar3 & 0x1c0) != 0x40) {
    while( true ) {
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_1000bca1;
      uVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*param_1 + 4) + (int)param_1));
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      uVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar4,uVar1);
      if (uVar1 == 0xffff) break;
      bVar7 = iVar6 != 0;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -1 + (uint)bVar7;
    }
    local_18 = local_18 | 4;
LAB_1000bca1:
    if (local_18 != 0) goto LAB_1000bcd9;
  }
  uVar9 = 0;
  uVar10 = 0;
  pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(*param_1 + 4) + (int)param_1));
  _Var8 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputn
                    (pbVar4,param_2,CONCAT26(uVar12,CONCAT24(uVar11,CONCAT22(uVar10,uVar9))));
  if (((uint)_Var8 == local_1c) && ((int)((ulonglong)_Var8 >> 0x20) == 0)) {
    while( true ) {
      if ((iVar5 < 0) || ((iVar5 < 1 && (iVar6 == 0)))) goto LAB_1000bcd9;
      uVar1 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*param_1 + 4) + (int)param_1));
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      uVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar4,uVar1);
      if (uVar1 == 0xffff) break;
      bVar7 = iVar6 != 0;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + -1 + (uint)bVar7;
    }
    local_18 = local_18 | 4;
  }
  else {
    local_18 = 4;
  }
LAB_1000bcd9:
  std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1),0);
  local_8 = 0;
  FUN_1000bd7c();
  return;
}



// Function: Catch@1000bd58 at 1000bd58

undefined * Catch_1000bd58(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000bd79;
}



// Function: FUN_1000bd7c at 1000bd7c

void FUN_1000bd7c(void)

{
  bool bVar1;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar2;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              (*(basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
                (unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                      (int)*(int **)(unaff_EBP + -0x20)));
  if (pbVar2 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                        (int)*(int **)(unaff_EBP + -0x20)));
    (**(code **)(*(int *)pbVar2 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000be00 at 1000be00

/* WARNING: Removing unreachable block (ram,0x1000be4c) */

void FUN_1000be00(int *param_1,ushort *param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar4;
  int iVar5;
  __int64 _Var6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined1 local_24 [4];
  char local_20;
  int local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012da0;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffcc;
  uVar9 = (undefined2)(DAT_1001d274 ^ (uint)&stack0xfffffffc);
  uVar10 = (undefined2)((DAT_1001d274 ^ (uint)&stack0xfffffffc) >> 0x10);
  ExceptionList = &local_10;
  local_18 = 0;
  uVar1 = *(uint *)(param_2 + 8);
  _Var6 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((_Var6 < 1) ||
     (_Var6 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1)),
     (uint)_Var6 <= uVar1)) {
    local_1c = 0;
  }
  else {
    _Var6 = std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
    local_1c = (int)_Var6 - uVar1;
  }
  iVar5 = local_1c;
  FUN_1000b050(local_24,param_1);
  local_8 = 0;
  if (local_20 == '\0') {
    local_18 = 4;
    FUN_1000bfb9();
    return;
  }
  local_8 = 1;
  uVar3 = std::ios_base::flags((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1));
  if ((uVar3 & 0x1c0) == 0x40) {
LAB_1000bef8:
    if (7 < *(uint *)(param_2 + 10)) {
      param_2 = *(ushort **)param_2;
    }
    uVar7 = 0;
    uVar8 = 0;
    pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*param_1 + 4) + (int)param_1));
    _Var6 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputn
                      (pbVar4,param_2,CONCAT26(uVar10,CONCAT24(uVar9,CONCAT22(uVar8,uVar7))));
    if (((uint)_Var6 != uVar1) || (iVar5 = local_1c, (int)((ulonglong)_Var6 >> 0x20) != 0)) {
      local_18 = 4;
      goto LAB_1000bf2c;
    }
  }
  else {
    while (iVar5 != 0) {
      uVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                        ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                         (*(int *)(*param_1 + 4) + (int)param_1));
      pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                         ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                          (*(int *)(*param_1 + 4) + (int)param_1));
      uVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                        (pbVar4,uVar2);
      if (uVar2 == 0xffff) {
        local_18 = local_18 | 4;
        break;
      }
      iVar5 = iVar5 + -1;
      local_1c = iVar5;
    }
    if (local_18 == 0) goto LAB_1000bef8;
  }
  while (iVar5 != 0) {
    uVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::fill
                      ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                       (*(int *)(*param_1 + 4) + (int)param_1));
    pbVar4 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(*param_1 + 4) + (int)param_1));
    uVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::sputc
                      (pbVar4,uVar2);
    if (uVar2 == 0xffff) {
      local_18 = local_18 | 4;
      break;
    }
    local_1c = iVar5 + -1;
    iVar5 = local_1c;
  }
LAB_1000bf2c:
  std::ios_base::width((ios_base *)(*(int *)(*param_1 + 4) + (int)param_1),0);
  local_8 = 0;
  FUN_1000bfb9();
  return;
}



// Function: Catch@1000bf95 at 1000bf95

undefined * Catch_1000bf95(void)

{
  int unaff_EBP;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000bfb6;
}



// Function: FUN_1000bfb9 at 1000bfb9

void FUN_1000bfb9(void)

{
  bool bVar1;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar2;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::setstate
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::_Osfx
              (*(basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
                (unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                     ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                      (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                      (int)*(int **)(unaff_EBP + -0x20)));
  if (pbVar2 != (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0) {
    pbVar2 = std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::rdbuf
                       ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        (*(int *)(**(int **)(unaff_EBP + -0x20) + 4) +
                        (int)*(int **)(unaff_EBP + -0x20)));
    (**(code **)(*(int *)pbVar2 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000c030 at 1000c030

void __cdecl
FUN_1000c030(int *param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined *param_5)

{
  undefined2 uVar1;
  
  if (param_2 == param_3) {
    *param_1 = (int)param_4;
    return;
  }
  do {
    uVar1 = (*(code *)param_5)(*param_2);
    *param_4 = uVar1;
    param_4 = param_4 + 1;
    param_2 = param_2 + 1;
  } while (param_2 != param_3);
  *param_1 = (int)param_4;
  return;
}



// Function: FUN_1000c080 at 1000c080

int * __thiscall FUN_1000c080(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  uint extraout_EAX;
  uint uVar1;
  int extraout_EAX_00;
  int iVar2;
  void *pvVar3;
  uint extraout_ECX;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *extraout_EDX;
  undefined4 *extraout_EDX_00;
  undefined4 *extraout_EDX_01;
  
  uVar1 = param_1[4];
  uVar4 = param_2;
  puVar5 = param_1;
  if (uVar1 < param_2) {
    std::_Xout_of_range("invalid string position");
    uVar1 = extraout_EAX;
    uVar4 = extraout_ECX;
    puVar5 = extraout_EDX;
  }
  if (uVar1 - uVar4 < param_3) {
    param_3 = uVar1 - uVar4;
  }
  iVar2 = *(int *)((int)this + 0x10);
  if (-iVar2 - 1U <= param_3) {
    std::_Xlength_error("string too long");
    iVar2 = extraout_EAX_00;
    puVar5 = extraout_EDX_00;
  }
  if (param_3 != 0) {
    uVar1 = iVar2 + param_3;
    if (0x7ffffffe < uVar1) {
      std::_Xlength_error("string too long");
      puVar5 = extraout_EDX_01;
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_100015e0(this,uVar1);
      puVar5 = param_1;
      if (uVar1 == 0) {
        return (int *)this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      *(undefined2 *)this = 0;
      return (int *)this;
    }
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    pvVar3 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
    }
    memcpy((void *)((int)pvVar3 + *(int *)((int)this + 0x10) * 2),
           (void *)((int)puVar5 + param_2 * 2),param_3 * 2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + uVar1 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + uVar1 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_1000c190 at 1000c190

void __fastcall FUN_1000c190(int *param_1)

{
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10012de0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)
   ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x14) +
   *(int *)(*param_1 + 4) + -0x50) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  this = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 1);
  *(undefined ***)this =
       std::
       basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_1000aec0(this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>(this);
  local_8 = 0xffffffff;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 2)
            );
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)(param_1 + 0x14))
  ;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c220 at 1000c220

int * __thiscall FUN_1000c220(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x50);
  FUN_1000c190(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: FUN_1000c250 at 1000c250

undefined2 * __thiscall FUN_1000c250(void *this,undefined2 *param_1,uint param_2,uint param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012ec9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_100018b0(param_1,(int *)this,param_2,param_3);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c2d0 at 1000c2d0

undefined4 * __thiscall FUN_1000c2d0(void *this,undefined4 *param_1)

{
  if ((undefined4 *)this != param_1) {
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    *(undefined4 *)((int)this + 0x14) = 7;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined2 *)this = 0;
    if ((uint)param_1[5] < 8) {
      memmove(this,param_1,param_1[4] * 2 + 2);
    }
    else {
      *(undefined4 *)this = *param_1;
      *param_1 = 0;
    }
    *(undefined4 *)((int)this + 0x10) = param_1[4];
    *(undefined4 *)((int)this + 0x14) = param_1[5];
    param_1[5] = 7;
    param_1[4] = 0;
    *(undefined2 *)param_1 = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c350 at 1000c350

void FUN_1000c350(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  ushort local_34 [2];
  void *local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10012e21;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(local_30,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  local_8 = 1;
  local_34[0] = 0x3d;
  local_34[1] = 0;
  uVar3 = FUN_1000a6f0(local_30,local_34,0,1);
  uVar3 = local_20 - uVar3;
  local_34[0] = 0x3d;
  local_34[1] = 0;
  uVar4 = FUN_1000a6f0(local_30,local_34,0,1);
  FUN_1000c250(local_30,param_1,uVar4,uVar3);
  local_8 = local_8 & 0xffffff00;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c450 at 1000c450

undefined2 * __thiscall FUN_1000c450(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013699;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_100019b0(param_1,(int *)L"CUMMINSPCID=",0xc);
  local_8 = 0;
  FUN_1000c080(param_1,(undefined4 *)((int)this + 0xc0),0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c4e0 at 1000c4e0

void __thiscall FUN_1000c4e0(void *this,undefined2 *param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012e81;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(byte *)((int)this + 0x40) & 2) == 0) {
    puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar1 == (ushort *)0x0) goto LAB_1000c5b9;
    puVar1 = *(ushort **)((int)this + 0x3c);
    puVar2 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                       ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
                        this);
    if (puVar1 < puVar2) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    FUN_100019b0(&local_30,(int *)**(undefined4 **)((int)this + 0x14),
                 (int)puVar1 - (int)**(undefined4 **)((int)this + 0x14) >> 1);
    local_8 = 1;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000c2d0(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
LAB_1000c5ae:
    local_30 = (void *)((uint)local_30 & 0xffff0000);
  }
  else {
LAB_1000c5b9:
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      puVar1 = std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::gptr
                         ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
                           *)this);
      if (puVar1 != (ushort *)0x0) {
        local_1c = 7;
        local_20 = 0;
        local_30 = (void *)((uint)local_30 & 0xffff0000);
        FUN_100019b0(&local_30,(int *)**(undefined4 **)((int)this + 0x10),
                     (**(int **)((int)this + 0x20) + **(int **)((int)this + 0x30) * 2) -
                     (int)**(undefined4 **)((int)this + 0x10) >> 1);
        local_8 = 2;
        *(undefined4 *)(param_1 + 10) = 7;
        *(undefined4 *)(param_1 + 8) = 0;
        *param_1 = 0;
        FUN_1000c2d0(param_1,&local_30);
        local_8 = local_8 & 0xffffff00;
        if (7 < local_1c) {
          operator_delete(local_30);
          local_30 = (void *)((uint)local_30 & 0xffff0000);
          goto LAB_1000c68d;
        }
        goto LAB_1000c5ae;
      }
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    local_8 = 3;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_1000c2d0(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
    local_30 = (void *)((uint)local_30 & 0xffff0000);
  }
LAB_1000c68d:
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c6c0 at 1000c6c0

undefined4 * __cdecl FUN_1000c6c0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    if (param_3 != param_1) {
      if (7 < (uint)param_3[5]) {
        operator_delete((void *)*param_3);
      }
      param_3[5] = 7;
      param_3[4] = 0;
      *(undefined2 *)param_3 = 0;
      if ((uint)param_1[5] < 8) {
        memmove(param_3,param_1,param_1[4] * 2 + 2);
      }
      else {
        *param_3 = *param_1;
        *param_1 = 0;
      }
      param_3[4] = param_1[4];
      param_3[5] = param_1[5];
      param_1[5] = 7;
      param_1[4] = 0;
      *(undefined2 *)param_1 = 0;
    }
    param_1 = param_1 + 7;
    param_3 = param_3 + 7;
  } while (param_1 != param_2);
  return param_3;
}



// Function: FUN_1000c750 at 1000c750

undefined2 * __thiscall FUN_1000c750(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012ec9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000c4e0((void *)((int)this + 4),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000c7b0 at 1000c7b0

void __cdecl FUN_1000c7b0(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011a91;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_2 != (undefined2 *)0x0) {
    *(undefined4 *)(param_2 + 10) = 7;
    *(undefined4 *)(param_2 + 8) = 0;
    *param_2 = 0;
    FUN_1000c2d0(param_2,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c810 at 1000c810

undefined2 * __cdecl
FUN_1000c810(undefined4 *param_1,undefined4 *param_2,undefined2 *param_3,undefined4 param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012ef0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_1000c7b0(param_4,param_3,param_1);
    param_3 = param_3 + 0xe;
  }
  ExceptionList = local_10;
  return param_3;
}



// Function: Catch@1000c889 at 1000c889

void Catch_1000c889(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(unaff_EBP + -0x14);
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  if (puVar3 != puVar1) {
    uVar2 = *(undefined4 *)(unaff_EBP + 0x14);
    do {
      FUN_10006980(uVar2,puVar3);
      puVar3 = puVar3 + 7;
    } while (puVar3 != puVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000c8c0 at 1000c8c0

void __thiscall FUN_1000c8c0(void *this,undefined2 *param_1)

{
  undefined4 *puVar1;
  wchar_t wVar2;
  uint uVar3;
  ushort **ppuVar4;
  undefined4 *puVar5;
  wchar_t *pwVar6;
  undefined4 *puVar7;
  wchar_t *pwVar8;
  long lVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined1 local_4e8 [8];
  undefined4 uStack_4e0;
  undefined **local_4d8;
  undefined **local_4d4;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_4d0 [56];
  undefined4 local_498;
  undefined4 local_494;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_488 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_440;
  undefined2 *local_43c;
  undefined4 local_438;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_434;
  undefined4 local_430;
  int local_420;
  uint local_41c;
  wchar_t local_414 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012fb7;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lVar9 = 0;
  local_438 = 0;
  local_43c = param_1;
  local_4d8 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_488);
  local_8 = 1;
  local_438 = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_4d8,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_4d4,
             false);
  local_8 = 2;
  *(undefined ***)((int)&local_4d8 + (int)local_4d8[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_434 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_4d4
  ;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_4d4)
  ;
  local_4d4 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_498 = 0;
  local_494 = 4;
  local_8 = 6;
  ppuVar4 = (ushort **)DAT_1001d078;
  if (DAT_1001d08c < 8) {
    ppuVar4 = &DAT_1001d078;
  }
  uVar3 = FUN_1000afc0((void *)((int)this + 0xa4),0,*(uint *)((int)this + 0xb4),(ushort *)ppuVar4,
                       DAT_1001d088);
  if (uVar3 == 0) {
    iVar14 = (*(int *)((int)this + 0x134) - *(int *)((int)this + 0x130)) / 0x1c;
    if (iVar14 == 0) {
      lVar9 = 3;
    }
    else if (iVar14 == 2) {
      lVar9 = 5;
    }
    else if (iVar14 == 3) {
      lVar9 = 6;
    }
    else if (iVar14 == 4) {
      lVar9 = 7;
    }
    else if (iVar14 == 1) {
      lVar9 = 1;
    }
  }
  else {
    ppuVar4 = (ushort **)DAT_1001d0b0;
    if (DAT_1001d0c4 < 8) {
      ppuVar4 = &DAT_1001d0b0;
    }
    uVar3 = FUN_1000afc0((void *)((int)this + 0xa4),0,*(uint *)((int)this + 0xb4),(ushort *)ppuVar4,
                         DAT_1001d0c0);
    if (uVar3 == 0) {
      iVar14 = (*(int *)((int)this + 0x134) - *(int *)((int)this + 0x130)) / 0x1c;
      if (iVar14 == 1) {
        lVar9 = 2;
      }
      else if (iVar14 == 2) {
        lVar9 = 4;
      }
      else if (iVar14 == 3) {
        lVar9 = 8;
      }
    }
  }
  uVar13 = 0;
  puVar11 = local_4e8;
  uVar12 = 3;
  puVar5 = (undefined4 *)std::setw(CONCAT44(3,puVar11));
  (*(code *)*puVar5)((undefined *)((int)&local_4d8 + (int)local_4d8[1]),puVar5[2],puVar5[3],puVar11,
                     uVar12,uVar13);
  *(undefined2 *)((int)&local_498 + (int)local_4d8[1]) = 0x30;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_4d8,
             lVar9);
  FUN_1000be00((int *)&local_4d8,(ushort *)((int)this + 0x88));
  uVar13 = 0;
  puVar11 = local_4e8;
  uVar12 = 3;
  puVar5 = (undefined4 *)std::setw(CONCAT44(3,puVar11));
  (*(code *)*puVar5)((undefined *)((int)&local_4d8 + (int)local_4d8[1]),puVar5[2],puVar5[3],puVar11,
                     uVar12,uVar13);
  *(undefined2 *)((int)&local_498 + (int)local_4d8[1]) = 0x30;
  iVar14 = 0x24;
  pwVar8 = local_414;
  uVar10 = FUN_1000ade0((int)this,0x30);
  pwVar6 = _itow((int)uVar10,pwVar8,iVar14);
  local_430 = (undefined4 *)((uint)local_430._2_2_ << 0x10);
  local_41c = 7;
  local_420 = 0;
  pwVar8 = pwVar6;
  do {
    wVar2 = *pwVar8;
    pwVar8 = pwVar8 + 1;
  } while (wVar2 != L'\0');
  FUN_100019b0(&local_430,(int *)pwVar6,(int)pwVar8 - (int)(pwVar6 + 1) >> 1);
  local_8._0_1_ = 7;
  puVar5 = local_430;
  if (local_41c < 8) {
    puVar5 = &local_430;
  }
  puVar1 = (undefined4 *)((int)puVar5 + local_420 * 2);
  puVar7 = local_430;
  if (local_41c < 8) {
    puVar7 = &local_430;
  }
  if (puVar7 != puVar1) {
    FUN_1000c030((int *)&local_434,(undefined2 *)puVar7,(undefined2 *)puVar1,(undefined2 *)puVar5,
                 toupper_exref);
  }
  FUN_1000be00((int *)&local_4d8,(ushort *)&local_430);
  FUN_1000c750(&local_4d8,local_43c);
  local_438 = 3;
  local_8 = CONCAT31(local_8._1_3_,6);
  if (7 < local_41c) {
    operator_delete(local_430);
  }
  local_41c = 7;
  local_420 = 0;
  local_430 = (undefined4 *)((uint)local_430 & 0xffff0000);
  local_434 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_488;
  *(undefined ***)((int)&local_4d8 + (int)local_4d8[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_440 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_4d4
  ;
  local_4d4 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 10;
  local_8._1_3_ = 0;
  FUN_1000aec0(local_440);
  local_8._0_1_ = 8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_4d4)
  ;
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_4d0);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_488);
  ExceptionList = local_10;
  uStack_4e0 = 0x1000ccdd;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ccf0 at 1000ccf0

/* WARNING: Removing unreachable block (ram,0x1000cede) */

undefined2 * __thiscall FUN_1000ccf0(void *this,undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  ushort *unaff_ESI;
  ushort *puVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  ushort *in_stack_ffffff5c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_64 [72];
  undefined1 *local_1c;
  undefined4 local_18;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001305e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  ppuVar6 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  local_8 = 1;
  puVar5 = (ushort *)0x0;
  local_18 = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff4c,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff50,false);
  local_8 = 2;
  *(undefined ***)(&stack0xffffff4c + (int)ppuVar6[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff50;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff50);
  local_8 = 6;
  piVar2 = (int *)FUN_1000bb80((int *)&stack0xffffff4c,(ushort *)&DAT_100161a4);
  piVar2 = (int *)FUN_1000be00(piVar2,puVar5);
  FUN_1000bb80(piVar2,unaff_ESI);
  ppuVar7 = *(undefined ***)((int)this + 0x130);
  iVar3 = *(int *)((int)this + 0x134) - (int)ppuVar7;
  iVar1 = iVar3 >> 0x1f;
  if (iVar3 / 0x1c + iVar1 != iVar1) {
    FUN_1000be00((int *)&stack0xffffff4c,(ushort *)ppuVar7);
    uVar4 = 1;
    ppuVar6 = ppuVar7;
    if (1 < (uint)((*(int *)((int)this + 0x134) - *(int *)((int)this + 0x130)) / 0x1c)) {
      local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x1c;
      do {
        ppuVar6 = (undefined **)&stack0xffffff4c;
        piVar2 = (int *)FUN_1000bb80((int *)ppuVar6,(ushort *)&DAT_100161a0);
        FUN_1000be00(piVar2,in_stack_ffffff5c);
        local_14 = local_14 + 0x1c;
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)((*(int *)((int)this + 0x134) - *(int *)((int)this + 0x130)) / 0x1c));
    }
  }
  FUN_1000c750(&stack0xffffff4c,param_1);
  local_18 = 3;
  local_14 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_64;
  *(undefined ***)(&stack0xffffff4c + (int)ppuVar6[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_1c = &stack0xffffff50;
  local_8._1_3_ = 0;
  local_8._0_1_ = 9;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff50,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff50,(ushort *)0x0,(ushort *)0x0);
  local_8._0_1_ = 7;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff50);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff54);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_64);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000cf60 at 1000cf60

/* WARNING: Removing unreachable block (ram,0x1000d496) */

void __thiscall FUN_1000cf60(void *this,ushort *param_1)

{
  wchar_t wVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  ushort *unaff_ESI;
  ushort *puVar7;
  undefined **ppuVar8;
  undefined4 local_1a8;
  ushort *in_stack_fffffe60;
  ushort *in_stack_fffffe6c;
  ushort *in_stack_fffffe78;
  ushort *in_stack_fffffe84;
  ushort *puVar9;
  ushort *in_stack_fffffeac;
  ushort *in_stack_fffffeb8;
  ushort *in_stack_fffffec4;
  ushort *in_stack_fffffed0;
  ushort *in_stack_fffffedc;
  ushort *in_stack_fffffee8;
  undefined2 *local_114;
  undefined4 in_stack_ffffff00;
  ushort uVar12;
  ushort *puVar10;
  wchar_t *pwVar11;
  ushort *in_stack_ffffff0c;
  ushort *in_stack_ffffff18;
  undefined4 local_e4;
  void *local_c8 [4];
  undefined4 local_b8;
  uint local_b4;
  undefined **local_ac;
  undefined **local_a8 [12];
  wchar_t local_78;
  undefined1 local_76 [10];
  undefined4 local_6c;
  undefined4 local_68;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_5c [72];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  uVar12 = (ushort)((uint)in_stack_ffffff00 >> 0x10);
  local_8 = 0xffffffff;
  puStack_c = &LAB_100131a1;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppuVar8 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffea0)
  ;
  local_8 = 1;
  puVar7 = (ushort *)0x0;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe50,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe54,false);
  local_8 = 2;
  *(undefined ***)(&stack0xfffffe50 + (int)ppuVar8[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe54);
  ppuVar8 = std::
            basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
            ::vftable;
  puVar9 = (ushort *)0x0;
  puVar10 = (ushort *)((uint)uVar12 << 0x10);
  local_8 = 7;
  FUN_1000a580(&local_114,2000,1,1,0,0,0);
  uVar2 = FUN_1000a500((void *)((int)this + 0x128),(double *)&local_114);
  if (((char)uVar2 == '\0') || (*(double *)((int)this + 0x128) == 2958465.0)) {
    uVar3 = 9;
    pwVar11 = L"permanent";
  }
  else {
    FUN_1000a7b0((void *)((int)this + 0x128),&local_78,L"%d-%b-%Y");
    pwVar11 = &local_78;
    do {
      wVar1 = *pwVar11;
      pwVar11 = pwVar11 + 1;
    } while (wVar1 != L'\0');
    uVar3 = (int)pwVar11 - (int)local_76 >> 1;
    pwVar11 = &local_78;
  }
  FUN_100019b0(&stack0xffffff00,(int *)pwVar11,uVar3);
  local_e4 = (uint)local_e4._2_2_ << 0x10;
  local_8._0_1_ = 8;
  if (*(int *)((int)this + 0x120) < 1) {
    FUN_100019b0(&local_e4,(int *)L"uncounted",9);
  }
  else {
    local_ac = &PTR_10016198;
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_5c);
    local_8 = CONCAT31(local_8._1_3_,9);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac,
               (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_a8,
               false);
    local_8 = 10;
    *(undefined ***)((int)local_a8 + (int)(local_ac[1] + -4)) =
         std::
         basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
         ::vftable;
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_a8)
    ;
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_a8[0] = std::
                  basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  ::vftable;
    local_6c = 0;
    local_68 = 4;
    local_8._0_1_ = 0xe;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac,
               *(long *)((int)this + 0x120));
    puVar4 = (undefined4 *)FUN_1000c750(&local_ac,(undefined2 *)local_c8);
    local_8._0_1_ = 0xf;
    FUN_1000c2d0(&local_e4,puVar4);
    local_8._0_1_ = 0xe;
    if (7 < local_b4) {
      operator_delete(local_c8[0]);
    }
    local_b4 = 7;
    local_b8 = 0;
    local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
    local_8._0_1_ = 8;
    FUN_1000c190((int *)&local_ac);
  }
  piVar5 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"<GenericLicense Expiration=\"");
  piVar5 = (int *)FUN_1000be00(piVar5,puVar7);
  FUN_1000bb80(piVar5,unaff_ESI);
  piVar5 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Name=\"");
  piVar6 = (int *)FUN_1000be00(piVar5,(ushort *)ppuVar8);
  local_1a8 = 0x1000d274;
  FUN_1000bb80(piVar6,in_stack_fffffe60);
  local_1a8 = 0x1000d291;
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"VendorDaemon=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffe6c);
  FUN_1000bb80(piVar6,in_stack_fffffe78);
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Key=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffe84);
  FUN_1000bb80(piVar6,puVar9);
  FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"IsValid=\"\" ");
  FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"ID=\"\" ");
  FUN_1000ccf0(this,(undefined2 *)local_c8);
  local_8._0_1_ = 0x10;
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Data=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffeac);
  FUN_1000bb80(piVar6,in_stack_fffffeb8);
  local_8._0_1_ = 8;
  if (7 < local_b4) {
    operator_delete(local_c8[0]);
  }
  local_b4 = 7;
  local_b8 = 0;
  local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Version=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffec4);
  FUN_1000bb80(piVar6,in_stack_fffffed0);
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Count=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffedc);
  FUN_1000bb80(piVar6,in_stack_fffffee8);
  local_114 = (undefined2 *)0x1000d3db;
  local_114 = FUN_1000c450(this,(undefined2 *)local_c8);
  local_8._0_1_ = 0x11;
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"HostID=\"");
  local_114 = (undefined2 *)0x1000d3ff;
  piVar6 = (int *)FUN_1000be00(piVar6,param_1);
  FUN_1000bb80(piVar6,puVar10);
  local_8._0_1_ = 8;
  if (7 < local_b4) {
    operator_delete(local_c8[0]);
  }
  pwVar11 = L"IsExpDlgDisp=\"";
  local_b4 = 7;
  local_b8 = 0;
  local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"IsExpDlgDisp=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_ffffff0c);
  FUN_1000bb80(piVar6,in_stack_ffffff18);
  local_e4 = 0x1000d483;
  FUN_1000c750(&stack0xfffffe50,param_1);
  local_e4 = local_e4 & 0xffff0000;
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((int *)0x7 < piVar6) {
    local_e4 = 0x1000d4d6;
    operator_delete(pwVar11);
  }
  *(undefined ***)(&stack0xfffffe50 + piVar5[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._0_1_ = 0x14;
  local_8._1_3_ = 0;
  FUN_1000aec0((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               &stack0xfffffe54);
  local_8._0_1_ = 0x12;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe54);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1a8);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffea0)
  ;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d590 at 1000d590

void __thiscall FUN_1000d590(void *this,undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  void **ppvVar3;
  uint extraout_EDX;
  ushort *unaff_EDI;
  ulonglong uVar4;
  ushort *puVar5;
  int **ppiVar6;
  undefined4 uVar7;
  undefined **ppuVar8;
  undefined **local_1c8;
  ushort *in_stack_fffffe40;
  ushort *puVar9;
  ushort *in_stack_fffffe4c;
  ushort *in_stack_fffffe58;
  ushort *in_stack_fffffe64;
  ushort *in_stack_fffffe70;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *pbVar10;
  ushort *in_stack_fffffe84;
  ushort *in_stack_fffffe90;
  undefined **local_134;
  undefined **local_130;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_12c [56];
  undefined4 local_f4;
  undefined4 local_f0;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_e4 [72];
  undefined2 *local_9c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_98;
  int *local_94;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_90;
  char local_89;
  uint local_88;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001338d;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_88 = 0;
  local_9c = param_1;
  local_134 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_e4);
  local_8 = 1;
  uVar7 = 0;
  local_88 = 0x20;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_134,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_130,
             false);
  local_8 = 2;
  *(undefined ***)((int)&local_134 + (int)local_134[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_90 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_130;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_130)
  ;
  local_130 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_f4 = 0;
  local_f0 = 4;
  local_8 = 6;
  uVar4 = FUN_1000ade0((int)this,extraout_EDX);
  local_89 = (int)uVar4 == 0;
  local_94 = (int *)0x0;
  local_8._0_1_ = 7;
  ppiVar6 = &local_94;
  (**(code **)(*(int *)((int)this + 8) + 0x2c))((int)this + 8,ppiVar6,uVar7);
  local_68 = (void *)((uint)local_68._2_2_ << 0x10);
  local_54 = 7;
  local_58 = 0;
  piVar2 = local_94;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(&local_68,local_94,(int)piVar2 - ((int)local_94 + 2) >> 1);
  local_8._0_1_ = 8;
  ppuVar8 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffe84)
  ;
  local_8 = CONCAT31(local_8._1_3_,9);
  local_88 = 0x60;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe34,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c8,
             false);
  local_8 = 10;
  *(undefined ***)(&stack0xfffffe34 + (int)ppuVar8[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_90 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c8;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c8)
  ;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_1c8 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 0xe;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe34,*(long *)((int)this + 0x120));
  if (*(int *)((int)this + 0x120) == 0) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    FUN_100019b0(local_30,(int *)L"uncounted",9);
    ppvVar3 = local_30;
    local_8 = CONCAT31(local_8._1_3_,0xf);
    local_88 = 0x61;
  }
  else {
    ppvVar3 = (void **)FUN_1000c750(&stack0xfffffe34,(undefined2 *)local_4c);
    local_8 = 0x10;
    local_88 = 0x62;
  }
  local_70 = 7;
  local_74 = 0;
  local_84 = (void *)((uint)local_84._2_2_ << 0x10);
  FUN_1000c2d0(&local_84,ppvVar3);
  local_8 = 0x12;
  if ((local_88 & 2) != 0) {
    local_88 = local_88 & 0xfffffffd;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  }
  local_8._0_1_ = 0x13;
  if ((local_88 & 1) != 0) {
    local_88 = local_88 & 0xfffffffe;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  }
  puVar5 = (ushort *)&DAT_10016334;
  puVar9 = (ushort *)((int)this + 0x50);
  piVar2 = (int *)FUN_1000bb80((int *)&local_134,(ushort *)L"FEATURE ");
  piVar2 = (int *)FUN_1000be00(piVar2,puVar9);
  piVar2 = (int *)FUN_1000bb80(piVar2,puVar5);
  piVar2 = (int *)FUN_1000be00(piVar2,(ushort *)ppiVar6);
  piVar2 = (int *)FUN_1000bb80(piVar2,unaff_EDI);
  piVar2 = (int *)FUN_1000be00(piVar2,(ushort *)ppuVar8);
  local_1c8 = (undefined **)0x1000d89d;
  FUN_1000bb80(piVar2,in_stack_fffffe40);
  if (local_89 == '\0') {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    FUN_100018b0(local_30,&local_68,0,0xffffffff);
    ppvVar3 = local_30;
    local_8 = 0x15;
    local_88 = local_88 | 8;
  }
  else {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
    FUN_100019b0(local_4c,(int *)L"permanent",9);
    ppvVar3 = local_4c;
    local_8 = CONCAT31(local_8._1_3_,0x14);
    local_88 = local_88 | 4;
  }
  puVar9 = (ushort *)&DAT_10016334;
  local_1c8 = (undefined **)&DAT_10016334;
  piVar2 = (int *)FUN_1000be00((int *)&local_134,(ushort *)ppvVar3);
  local_1c8 = (undefined **)0x1000d92f;
  piVar2 = (int *)FUN_1000bb80(piVar2,puVar9);
  piVar2 = (int *)FUN_1000be00(piVar2,in_stack_fffffe4c);
  piVar2 = (int *)FUN_1000bb80(piVar2,in_stack_fffffe58);
  piVar2 = (int *)FUN_1000be00(piVar2,in_stack_fffffe64);
  FUN_1000bb80(piVar2,in_stack_fffffe70);
  local_8 = 0x14;
  if ((local_88 & 8) != 0) {
    local_88 = local_88 & 0xfffffff7;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  }
  local_8 = 0x13;
  if ((local_88 & 4) != 0) {
    local_88 = local_88 & 0xfffffffb;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  }
  local_90 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             FUN_1000ccf0(this,(undefined2 *)local_30);
  local_8._0_1_ = 0x16;
  FUN_1000c450(this,(undefined2 *)local_4c);
  local_8._0_1_ = 0x17;
  pbVar10 = local_90;
  piVar2 = (int *)FUN_1000bb80((int *)&local_134,(ushort *)L" HOSTID=");
  piVar2 = (int *)FUN_1000be00(piVar2,(ushort *)pbVar10);
  piVar2 = (int *)FUN_1000bb80(piVar2,in_stack_fffffe84);
  FUN_1000be00(piVar2,in_stack_fffffe90);
  local_8._0_1_ = 0x16;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_8._0_1_ = 0x13;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  FUN_1000c750(&local_134,local_9c);
  local_88 = local_88 | 0x10;
  local_8._0_1_ = 0xe;
  if (7 < local_70) {
    operator_delete(local_84);
  }
  local_70 = 7;
  local_74 = 0;
  local_84 = (void *)((uint)local_84 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  local_90 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe84;
  *(undefined ***)(&stack0xfffffe34 + (int)ppvVar3[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_98 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c8;
  local_1c8 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 0x1a;
  FUN_1000aec0(local_98);
  local_8._0_1_ = 0x18;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c8)
  ;
  local_8._0_1_ = 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe3c);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffe84)
  ;
  local_8._0_1_ = 7;
  if (7 < local_54) {
    operator_delete(local_68);
  }
  local_54 = 7;
  local_58 = 0;
  local_68 = (void *)((uint)local_68 & 0xffff0000);
  local_8 = CONCAT31(local_8._1_3_,6);
  Ordinal_6();
  local_98 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_e4;
  *(undefined ***)((int)&local_134 + (int)local_134[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_90 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_130;
  local_130 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 0x1d;
  local_8._1_3_ = 0;
  FUN_1000aec0(local_90);
  local_8._0_1_ = 0x1b;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_130)
  ;
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_12c);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_e4);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000dbe0 at 1000dbe0

void __thiscall FUN_1000dbe0(void *this,undefined4 *param_1,undefined4 *param_2,undefined2 *param_3)

{
  FUN_1000c810(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_1000dc10 at 1000dc10

int __fastcall FUN_1000dc10(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013453;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)(param_1 + 0x30) = 0;
  local_8 = 2;
  *(undefined4 *)(param_1 + 0x48) = 7;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x34),(int *)L"INSITE_ToolLevel_License",0x18);
  local_8._0_1_ = 3;
  *(undefined4 *)(param_1 + 100) = 7;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined2 *)(param_1 + 0x50) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x50),(int *)L"cummins",7);
  local_8._0_1_ = 4;
  *(undefined4 *)(param_1 + 0x80) = 7;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined2 *)(param_1 + 0x6c) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x6c),(int *)L"1.000",5);
  local_8._0_1_ = 5;
  *(undefined4 *)(param_1 + 0x9c) = 7;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined2 *)(param_1 + 0x88) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x88),(int *)&DAT_1001634c,1);
  local_8._0_1_ = 6;
  *(undefined4 *)(param_1 + 0xb8) = 7;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined2 *)(param_1 + 0xa4) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0xa4),(int *)&PTR_10015500,0);
  local_8._0_1_ = 7;
  *(undefined4 *)(param_1 + 0xd4) = 7;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined2 *)(param_1 + 0xc0) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0xc0),(int *)L"00000000",8);
  local_8._0_1_ = 8;
  *(undefined4 *)(param_1 + 0xf0) = 7;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined2 *)(param_1 + 0xdc) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0xdc),(int *)L"ToolLevel",9);
  local_8 = CONCAT31(local_8._1_3_,9);
  *(undefined4 *)(param_1 + 0x10c) = 7;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined2 *)(param_1 + 0xf8) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0xf8),(int *)&DAT_1001612c,1);
  *(undefined1 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ddc0 at 1000ddc0

void __thiscall FUN_1000ddc0(void *this,char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013470;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    puVar3 = (undefined2 *)FUN_1000af20(param_1);
    local_8 = 0;
                    /* WARNING: Load size is inaccurate */
    FUN_1000dbe0(this,*this,*(undefined4 **)((int)this + 4),puVar3);
    local_8 = 0xffffffff;
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    puVar2 = *this;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_10006a30(puVar2,*(undefined4 **)((int)this + 4));
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    std::_Container_base0::_Orphan_all((_Container_base0 *)this);
    *(undefined2 **)((int)this + 8) = puVar3 + (int)param_1 * 0xe;
    *(undefined2 **)((int)this + 4) = puVar3 + ((iVar1 - (int)puVar2) / 0x1c) * 0xe;
    *(undefined2 **)this = puVar3;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000decb at 1000decb

void Catch_1000decb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000def0 at 1000def0

void __thiscall FUN_1000def0(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_EAX;
  char *pcVar3;
  void *extraout_ECX;
  char *pcVar4;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  uVar2 = (*(int *)((int)this + 4) - iVar1) / 0x1c;
  if (0x9249249U - param_1 < uVar2) {
    std::_Xlength_error("vector<T> too long");
    param_1 = extraout_EAX;
    this = extraout_ECX;
  }
  pcVar4 = (char *)(uVar2 + param_1);
  pcVar3 = (char *)((*(int *)((int)this + 8) - iVar1) / 0x1c);
  if (pcVar3 < pcVar4) {
    if ((char *)(0x9249249 - ((uint)pcVar3 >> 1)) < pcVar3) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = pcVar3 + ((uint)pcVar3 >> 1);
    }
    if (pcVar3 < pcVar4) {
      pcVar3 = pcVar4;
    }
    FUN_1000ddc0(this,pcVar3);
  }
  return;
}



// Function: FUN_1000df70 at 1000df70

void __thiscall FUN_1000df70(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100134b2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000def0(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)(*this + (((int)param_1 - (int)puVar2) / 0x1c) * 0x1c);
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 0;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000e033;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000def0(this,1);
    }
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 1;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000e033;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  FUN_1000c2d0(this_00,param_1);
LAB_1000e033:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e060 at 1000e060

void __thiscall FUN_1000e060(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined2 *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100134b2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < piVar1) && (piVar2 = *this, piVar2 <= param_1)) {
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_1000def0(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (int *)(*this + (((int)param_1 - (int)piVar2) / 0x1c) * 0x1c);
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 0;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000e12b;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  else {
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_1000def0(this,1);
    }
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 1;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000e12b;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  FUN_100018b0(this_00,param_1,0,0xffffffff);
LAB_1000e12b:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e150 at 1000e150

uint __thiscall FUN_1000e150(void *this,wchar_t *param_1)

{
  wchar_t *_Str;
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  _Str = param_1;
  if (7 < *(uint *)(param_1 + 10)) {
    _Str = *(wchar_t **)param_1;
  }
  uVar1 = _wtoi(_Str);
  puVar3 = *(undefined4 **)((int)this + 0x134);
  if (*(undefined4 **)((int)this + 0x130) != puVar3) {
    puVar2 = FUN_1000c6c0(puVar3,puVar3,*(undefined4 **)((int)this + 0x130));
    puVar3 = (undefined4 *)FUN_10006a30(puVar2,*(undefined4 **)((int)this + 0x134));
    *(undefined4 **)((int)this + 0x134) = puVar2;
  }
  if (uVar1 == 0) {
    puVar3 = (undefined4 *)FUN_1000afc0(param_1,0,*(uint *)(param_1 + 8),(ushort *)&DAT_10016350,3);
    if (puVar3 == (undefined4 *)0x0) {
LAB_1000e1f0:
                    /* WARNING: Could not recover jumptable at 0x1000e1f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)(&PTR_LAB_1000e390)[uVar1])();
      return uVar1;
    }
  }
  else if ((int)uVar1 < 0xb) {
    if (8 < uVar1) {
      return (uint)puVar3 & 0xffffff00;
    }
    goto LAB_1000e1f0;
  }
  return (uint)puVar3 & 0xffffff00;
}



// Function: FUN_1000e3c0 at 1000e3c0

void __thiscall FUN_1000e3c0(void *this,void *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100134e0;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = FUN_1000a6f0(param_1,(ushort *)&DAT_100161a4,0,1);
  uVar2 = FUN_1000a6f0(param_1,(ushort *)&DAT_100161a8,0,1);
  puVar3 = (undefined4 *)FUN_1000c250(param_1,(undefined2 *)local_30,uVar1 + 1,(uVar2 - uVar1) - 1);
  local_8 = 0;
  FUN_1000c2d0((void *)((int)this + 0xa4),puVar3);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  if (uVar2 + 2 <= *(uint *)((int)param_1 + 0x10)) {
    do {
      local_1c = 7;
      local_20 = 0;
      uVar1 = uVar2 + 1;
      if (uVar2 == 0xffffffff) break;
      uVar2 = FUN_1000a6f0(param_1,(ushort *)&DAT_100161a0,uVar1,1);
      FUN_1000c250(param_1,(undefined2 *)local_30,uVar1,uVar2 - uVar1);
      local_8 = 1;
      FUN_1000e060((void *)((int)this + 0x130),(int *)local_30);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    } while (uVar2 + 2 <= *(uint *)((int)param_1 + 0x10));
  }
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e510 at 1000e510

void FUN_1000e510(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013518;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(local_30,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  local_8 = 0;
  FUN_1000df70((void *)(param_1 + 0x120),local_30);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e5e0 at 1000e5e0

void FUN_1000e5e0(int param_1,int *param_2,short *param_3)

{
  int iVar1;
  int *piVar2;
  wchar_t *pwVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
  float10 fVar7;
  int local_58;
  uint local_54;
  char local_4d;
  void *local_4c [4];
  int local_3c;
  uint local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013571;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = 0;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(local_4c,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  local_8 = 0;
  if (local_3c == 0x12) {
    pwVar3 = FUN_1000c250(local_4c,(undefined2 *)local_30,0,3);
    local_8._0_1_ = 1;
    uVar4 = FUN_1000e150((void *)(param_1 + -0xc),pwVar3);
    local_4d = (char)uVar4;
    local_8._0_1_ = 0;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    bVar6 = local_4d != '\0';
    if (bVar6) {
      puVar5 = (undefined4 *)FUN_1000c250(local_4c,(undefined2 *)local_30,0xf,3);
      local_8 = CONCAT31(local_8._1_3_,2);
      local_54 = 1;
      local_58 = FUN_1000ab70(puVar5);
      fVar7 = FUN_1000ae50(&local_58);
      *(double *)(param_1 + 0x11c) = (double)fVar7;
    }
    local_8 = 0;
    local_4d = bVar6;
    if ((local_54 & 1) != 0) {
      local_54 = local_54 & 0xfffffffe;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    }
    if (local_4d != '\0') {
      puVar5 = (undefined4 *)FUN_1000c250(local_4c,(undefined2 *)local_30,3,0xc);
      local_8._0_1_ = 3;
      FUN_1000c2d0((void *)(param_1 + 0x7c),puVar5);
      local_8 = (uint)local_8._1_3_ << 8;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    }
    *param_3 = -(ushort)(local_4d != '\0');
    local_8 = 0xffffffff;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
  }
  else {
    local_8 = 0xffffffff;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_3c = 0;
  local_38 = 7;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e7e0 at 1000e7e0

void FUN_1000e7e0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013518;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(local_30,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  local_8 = 0;
  FUN_1000e3c0((void *)(param_1 + -8),local_30);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e8c0 at 1000e8c0

undefined4 FUN_1000e8c0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((((piVar1 = *(int **)((int)&PTR_DAT_1001d230 + uVar2), *piVar1 != *param_2 ||
           (piVar1[1] != param_2[1])) || (piVar1[2] != param_2[2])) || (piVar1[3] != param_2[3]))) {
    uVar2 = uVar2 + 4;
    if (3 < uVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_1000e910 at 1000e910

void __thiscall FUN_1000e910(void *this,int param_1,uint param_2,undefined2 param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_2 == 1) {
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      this = *this;
    }
    *(undefined2 *)((int)this + param_1 * 2) = param_3;
    return;
  }
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  if (param_2 != 0) {
    puVar2 = (undefined4 *)((int)this + param_1 * 2);
    for (uVar1 = param_2 >> 1; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = CONCAT22(param_3,param_3);
      puVar2 = puVar2 + 1;
    }
    for (uVar1 = (uint)((param_2 & 1) != 0); uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined2 *)puVar2 = param_3;
      puVar2 = (undefined4 *)((int)puVar2 + 2);
    }
  }
  return;
}



// Function: FUN_1000e970 at 1000e970

undefined4 __thiscall FUN_1000e970(void *this,undefined4 *param_1)

{
  int iVar1;
  double *pdVar2;
  double local_1c;
  double local_14;
  double local_c;
  
  iVar1 = FUN_1000ab70(param_1);
  FUN_1000a580(&local_14,2000,1,1,0,0,0);
  FUN_1000a4c0(&local_c,iVar1,0,0,0);
  pdVar2 = FUN_1000a830(&local_1c,&local_14,&local_c);
  *(double *)((int)this + 0x120) = *pdVar2;
  return CONCAT31((int3)((uint)pdVar2 >> 8),1);
}



// Function: FUN_1000e9e0 at 1000e9e0

int * __thiscall FUN_1000e9e0(void *this,uint param_1,undefined2 param_2)

{
  uint uVar1;
  int extraout_EAX;
  int iVar2;
  
  iVar2 = *(int *)((int)this + 0x10);
  if (-iVar2 - 1U <= param_1) {
    std::_Xlength_error("string too long");
    iVar2 = extraout_EAX;
  }
  if (param_1 != 0) {
    uVar1 = iVar2 + param_1;
    if (0x7ffffffe < uVar1) {
      std::_Xlength_error("string too long");
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_100015e0(this,uVar1);
      if (uVar1 == 0) {
        return (int *)this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      *(undefined2 *)this = 0;
      return (int *)this;
    }
    FUN_1000e910(this,*(int *)((int)this + 0x10),param_1,param_2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + uVar1 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + uVar1 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_1000eaa0 at 1000eaa0

int * __thiscall FUN_1000eaa0(void *this,undefined2 param_1)

{
  undefined2 *puVar1;
  
  if (*(int *)((int)this + 0x14) == 0) {
    FUN_100015e0(this,1);
  }
  puVar1 = (undefined2 *)this;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    puVar1 = *this;
  }
  *puVar1 = param_1;
  *(undefined4 *)((int)this + 0x10) = 1;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)((int)this + 2) = 0;
    return (int *)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(*this + 2) = 0;
  return (int *)this;
}



// Function: FUN_1000eb00 at 1000eb00

void __thiscall FUN_1000eb00(void *this,ushort *param_1)

{
  wchar_t wVar1;
  uint uVar2;
  ushort *puVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  int iVar6;
  undefined4 local_94;
  undefined4 local_84;
  uint local_80;
  wchar_t local_78 [50];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100135ab;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar3 = param_1;
  if (7 < *(uint *)(param_1 + 10)) {
    puVar3 = *(ushort **)param_1;
  }
  switch(*puVar3) {
  case 0x44:
  case 0x45:
  case 0x46:
    FUN_100019b0((void *)((int)this + 0xa0),(int *)L"FleetCal",8);
    uVar2 = *(uint *)(param_1 + 10);
    if (uVar2 < 8) {
      iVar6 = *param_1 - 0x44;
    }
    else {
      iVar6 = **(ushort **)param_1 - 0x44;
    }
    break;
  default:
    goto LAB_1000ecbc;
  case 0x55:
  case 0x56:
  case 0x57:
    FUN_100019b0((void *)((int)this + 0xa0),(int *)L"ZapItNonOEM",0xb);
    uVar2 = *(uint *)(param_1 + 10);
    if (uVar2 < 8) {
      iVar6 = *param_1 - 0x55;
    }
    else {
      iVar6 = **(ushort **)param_1 - 0x55;
    }
    break;
  case 0x58:
  case 0x59:
  case 0x5a:
    FUN_100019b0((void *)((int)this + 0xa0),(int *)L"ZapItAll",8);
    uVar2 = *(uint *)(param_1 + 10);
    puVar3 = param_1;
    if (7 < uVar2) {
      puVar3 = *(ushort **)param_1;
    }
    iVar6 = *puVar3 - 0x58;
  }
  puVar3 = param_1;
  if (7 < uVar2) {
    puVar3 = *(ushort **)param_1;
  }
  FUN_1000eaa0((void *)((int)this + 0xf4),puVar3[1]);
  pwVar4 = _itow(iVar6,local_78,0x24);
  local_94 = (void *)((uint)local_94._2_2_ << 0x10);
  local_80 = 7;
  local_84 = 0;
  pwVar5 = pwVar4;
  do {
    wVar1 = *pwVar5;
    pwVar5 = pwVar5 + 1;
  } while (wVar1 != L'\0');
  FUN_100019b0(&local_94,(int *)pwVar4,(int)pwVar5 - (int)(pwVar4 + 1) >> 1);
  local_8 = 0;
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(ushort **)param_1;
  }
  FUN_1000e9e0(&local_94,1,param_1[2]);
  iVar6 = FUN_1000ab70(&local_94);
  *(int *)((int)this + 0x114) = iVar6;
  local_8 = 0xffffffff;
  if (7 < local_80) {
    operator_delete(local_94);
  }
  local_94 = (void *)((uint)local_94 & 0xffff0000);
  local_80 = 7;
  local_84 = 0;
LAB_1000ecbc:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ed10 at 1000ed10

undefined2 * FUN_1000ed10(undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012ec9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_100019b0(param_1,(int *)&PTR_10015500,0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ed80 at 1000ed80

void FUN_1000ed80(int param_1,int *param_2,short *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  void *local_4c [4];
  int local_3c;
  uint local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013611;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar2 = false;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  piVar5 = param_2;
  do {
    iVar3 = *piVar5;
    piVar5 = (int *)((int)piVar5 + 2);
  } while ((short)iVar3 != 0);
  FUN_100019b0(local_4c,param_2,(int)piVar5 - ((int)param_2 + 2) >> 1);
  local_8 = 0;
  if (local_3c != 0x12) {
    local_8 = 0xffffffff;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    goto LAB_1000ef39;
  }
  puVar6 = FUN_1000c250(local_4c,(undefined2 *)local_30,0,3);
  local_8._0_1_ = 1;
  cVar4 = FUN_1000eb00((void *)(param_1 + -0xc),puVar6);
  local_8._0_1_ = 0;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  if (cVar4 == '\0') {
LAB_1000ee91:
    bVar1 = false;
  }
  else {
    puVar7 = (undefined4 *)FUN_1000c250(local_4c,(undefined2 *)local_30,0xf,3);
    local_8 = CONCAT31(local_8._1_3_,2);
    bVar2 = true;
    uVar8 = FUN_1000e970((void *)(param_1 + -0xc),puVar7);
    bVar1 = true;
    if ((char)uVar8 == '\0') goto LAB_1000ee91;
  }
  local_8 = 0;
  if (bVar2) {
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  }
  if (bVar1) {
    puVar7 = (undefined4 *)FUN_1000c250(local_4c,(undefined2 *)local_30,3,0xc);
    local_8._0_1_ = 3;
    FUN_1000c2d0((void *)(param_1 + 0x78),puVar7);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  }
  *param_3 = -(ushort)bVar1;
  local_8 = 0xffffffff;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
LAB_1000ef39:
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_3c = 0;
  local_38 = 7;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ef70 at 1000ef70

void __thiscall FUN_1000ef70(void *this,void *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013650;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = FUN_1000a6f0(param_1,(ushort *)&DAT_100161a4,0,1);
  uVar2 = FUN_1000a6f0(param_1,(ushort *)&DAT_100161a8,0,1);
  puVar3 = (undefined4 *)FUN_1000c250(param_1,(undefined2 *)local_4c,uVar1 + 1,(uVar2 - uVar1) - 1);
  local_8 = 0;
  FUN_1000c2d0((void *)((int)this + 0xa0),puVar3);
  local_8 = 0xffffffff;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  FUN_1000c250(param_1,(undefined2 *)local_30,uVar2 - uVar1,*(int *)((int)param_1 + 0x10) - uVar2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f080 at 1000f080

undefined2 * __thiscall FUN_1000f080(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013699;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_100019b0(param_1,(int *)L"CUMMINSPCID=",0xc);
  local_8 = 0;
  FUN_1000c080(param_1,(undefined4 *)((int)this + 0xbc),0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000f110 at 1000f110

void FUN_1000f110(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013518;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(local_30,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  local_8 = 0;
  FUN_1000ef70((void *)(param_1 + -8),local_30);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f1f0 at 1000f1f0

void __thiscall FUN_1000f1f0(void *this,undefined2 *param_1)

{
  ushort *puVar1;
  double dVar2;
  ushort uVar3;
  wchar_t wVar4;
  void *pvVar5;
  ushort *puVar6;
  uint uVar7;
  wchar_t *pwVar8;
  undefined4 *puVar9;
  int *_Src;
  char *pcVar10;
  int iVar11;
  undefined4 extraout_ECX;
  wchar_t *pwVar12;
  undefined4 extraout_EDX;
  int iVar13;
  ushort *puVar14;
  bool bVar15;
  ulonglong uVar16;
  undefined1 *puVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined2 uVar21;
  undefined **ppuVar22;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_1b8 [12];
  undefined4 *local_1ac;
  undefined4 local_180;
  uint local_17c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_170 [72];
  undefined **local_128;
  undefined **local_124;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_120 [12];
  undefined4 *local_114;
  undefined4 local_e8;
  uint local_e4;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_d8 [72];
  undefined2 *local_90;
  undefined8 local_8c;
  undefined4 local_84;
  undefined4 local_80;
  int local_70;
  uint local_6c;
  void *local_64 [3];
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined8 local_50;
  undefined4 local_48;
  int local_38;
  uint local_34;
  wchar_t local_2c [4];
  wchar_t local_24 [4];
  ushort local_1c;
  undefined2 uStack_1a;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100137ca;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_90 = param_1;
  local_84 = 0;
  bVar15 = false;
  local_50._4_4_ = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)0x0;
  iVar13 = 0;
  local_8c._4_4_ = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)this;
  do {
    if (bVar15) break;
    puVar14 = (ushort *)(&PTR_u_FleetCal_1001d234)[iVar13];
    puVar6 = puVar14;
    do {
      uVar3 = *puVar6;
      puVar6 = puVar6 + 1;
    } while (uVar3 != 0);
    local_50._4_4_ = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)iVar13;
    uVar7 = FUN_1000afc0((void *)((int)local_8c._4_4_ + 0xa0),0,
                         *(uint *)((int)local_8c._4_4_ + 0xb0),puVar14,
                         (int)puVar6 - (int)(puVar14 + 1) >> 1);
    bVar15 = uVar7 == 0;
    iVar13 = iVar13 + 1;
  } while (iVar13 < 3);
  pvVar5 = local_8c._4_4_;
  local_18 = 0x30;
  _local_1c = CONCAT22(0x30,*(undefined2 *)(&DAT_10016630 + (int)local_50._4_4_ * 2));
  pwVar8 = _itow(*(int *)((int)local_8c._4_4_ + 0x114),local_24,0x24);
  local_48 = (char *)((uint)local_48._2_2_ << 0x10);
  local_34 = 7;
  local_38 = 0;
  pwVar12 = pwVar8;
  do {
    wVar4 = *pwVar12;
    pwVar12 = pwVar12 + 1;
  } while (wVar4 != L'\0');
  FUN_100019b0(&local_48,(int *)pwVar8,(int)pwVar12 - (int)(pwVar8 + 1) >> 1);
  local_8 = 1;
  ppuVar22 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_170);
  local_8 = CONCAT31(local_8._1_3_,2);
  uVar20 = 0;
  local_84 = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe40,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe44,false);
  local_8 = 3;
  *(undefined ***)(&stack0xfffffe40 + (int)ppuVar22[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_50._4_4_ =
       (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffe44;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe44);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_180 = 0;
  local_17c = 4;
  local_8._0_1_ = 7;
  uVar19 = 0;
  puVar17 = local_58;
  uVar18 = 2;
  puVar9 = (undefined4 *)std::setw(CONCAT44(2,puVar17));
  (*(code *)*puVar9)(&stack0xfffffe40 + (int)ppuVar22[1],puVar9[2],puVar9[3],puVar17,uVar18,uVar19,
                     uVar20);
  *(undefined2 *)((int)&local_180 + (int)ppuVar22[1]) = 0x30;
  FUN_1000be00((int *)&stack0xfffffe40,(ushort *)&local_48);
  _Src = (int *)FUN_1000c750(&stack0xfffffe40,(undefined2 *)local_64);
  local_8._0_1_ = 8;
  if (&local_48 != _Src) {
    if (7 < local_34) {
      operator_delete(local_48);
    }
    local_34 = 7;
    local_38 = 0;
    local_48 = (char *)((uint)local_48 & 0xffff0000);
    if ((uint)_Src[5] < 8) {
      memmove(&local_48,_Src,(_Src[4] + 1) * 2);
    }
    else {
      local_48 = (char *)*_Src;
      *_Src = 0;
    }
    local_38 = _Src[4];
    local_34 = _Src[5];
    _Src[5] = 7;
    _Src[4] = 0;
    *(undefined2 *)_Src = 0;
  }
  local_8._0_1_ = 7;
  if (7 < (uint)local_50) {
    operator_delete(local_64[0]);
  }
  local_50._0_4_ = 7;
  local_54 = 0;
  local_64[0] = (void *)((uint)local_64[0] & 0xffff0000);
  pcVar10 = local_48;
  if (local_34 < 8) {
    pcVar10 = (char *)&local_48;
  }
  if (*(uint *)((int)pvVar5 + 0x108) < 8) {
    iVar13 = (int)pvVar5 + 0xf4;
  }
  else {
    iVar13 = *(int *)((int)pvVar5 + 0xf4);
  }
  _local_1c = CONCAT22(*(undefined2 *)(iVar13 + *(int *)((int)pvVar5 + 0x104) * 2 + -2),
                       local_1c + (short)(char)(*pcVar10 + -0x30));
  pcVar10 = local_48;
  if (local_34 < 8) {
    pcVar10 = (char *)&local_48;
  }
  iVar13 = toupper((uint)*(ushort *)(pcVar10 + 2));
  local_18 = CONCAT22(local_18._2_2_,(short)iVar13);
  local_128 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_d8);
  local_8 = CONCAT31(local_8._1_3_,9);
  local_84 = 6;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_128,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_124,
             false);
  local_8 = 10;
  *(undefined ***)((int)&local_128 + (int)local_128[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_50._4_4_ = (basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_124;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_124)
  ;
  local_124 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_e8 = 0;
  local_e4 = 4;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),0xe);
  FUN_1000bb80((int *)&local_128,&local_1c);
  FUN_1000be00((int *)&local_128,(ushort *)((int)pvVar5 + 0x84));
  dVar2 = *(double *)((int)pvVar5 + 0x120);
  if ((NAN(dVar2) || -657434.0 < dVar2 == (dVar2 == -657434.0)) ||
     (2958465.0 < *(double *)((int)pvVar5 + 0x120))) {
    iVar13 = 0;
  }
  else {
    FUN_1000a580(&local_50,2000,1,1,0,0,0);
    FUN_1000a8e0((double *)&local_8c,(double *)((int)pvVar5 + 0x120),(double *)&local_50);
    uVar16 = FUN_100110d0(extraout_ECX,extraout_EDX);
    iVar13 = (int)uVar16;
  }
  pwVar8 = _itow(iVar13,local_2c,0x24);
  local_6c = 7;
  local_70 = 0;
  local_80 = (ushort *)((uint)local_80._2_2_ << 0x10);
  pwVar12 = pwVar8;
  do {
    wVar4 = *pwVar12;
    pwVar12 = pwVar12 + 1;
  } while (wVar4 != L'\0');
  FUN_100019b0(&local_80,(int *)pwVar8,(int)pwVar12 - (int)(pwVar8 + 1) >> 1);
  local_8._0_1_ = 0xf;
  puVar14 = local_80;
  if (local_6c < 8) {
    puVar14 = (ushort *)&local_80;
  }
  puVar1 = puVar14 + local_70;
  puVar6 = local_80;
  if (local_6c < 8) {
    puVar6 = (ushort *)&local_80;
  }
  if (puVar6 != puVar1) {
    iVar13 = (int)puVar14 - (int)puVar6;
    do {
      iVar11 = toupper((uint)*puVar6);
      *(short *)((int)puVar6 + iVar13) = (short)iVar11;
      puVar6 = puVar6 + 1;
    } while (puVar6 != puVar1);
  }
  uVar18 = 0;
  puVar17 = local_58;
  uVar21 = 3;
  puVar9 = (undefined4 *)std::setw((ulonglong)CONCAT24(3,puVar17));
  (*(code *)*puVar9)((undefined *)((int)&local_128 + (int)local_128[1]),puVar9[2],puVar9[3],
                     (short)puVar17,uVar21,uVar18);
  *(undefined2 *)((int)&local_e8 + (int)local_128[1]) = 0x30;
  FUN_1000be00((int *)&local_128,(ushort *)&local_80);
  FUN_1000c750(&local_128,local_90);
  local_84 = 7;
  local_8._0_1_ = 0xe;
  if (7 < local_6c) {
    operator_delete(local_80);
  }
  local_6c = 7;
  local_70 = 0;
  local_80 = (ushort *)((uint)local_80 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  local_50._4_4_ = local_d8;
  *(undefined ***)((int)&local_128 + (int)local_128[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8c._4_4_ =
       (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_124;
  local_124 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 0x12;
  if ((local_e4 & 1) != 0) {
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
              (local_8c._4_4_);
    operator_delete((void *)*local_114);
  }
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_124,
             (ushort *)0x0,(ushort *)0x0,(ushort *)0x0);
  iVar13 = 0;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_124,
             (ushort *)0x0,(ushort *)0x0);
  local_e4 = local_e4 & 0xfffffffe;
  local_e8 = 0;
  local_8._0_1_ = 0x10;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_124)
  ;
  local_8._0_1_ = 7;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_120);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_d8);
  local_8 = (uint)local_8._1_3_ << 8;
  local_50._4_4_ = local_170;
  *(undefined ***)(&stack0xfffffe40 + *(int *)(iVar13 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8c._4_4_ =
       (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffe44;
  local_8._0_1_ = 0x15;
  if ((local_17c & 1) != 0) {
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::pptr
              (local_8c._4_4_);
    operator_delete((void *)*local_1ac);
  }
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setg
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe44,(ushort *)0x0,(ushort *)0x0,(ushort *)0x0);
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::setp
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe44,(ushort *)0x0,(ushort *)0x0);
  local_17c = local_17c & 0xfffffffe;
  local_180 = 0;
  local_8._0_1_ = 0x13;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe44);
  local_8._0_1_ = 1;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_1b8);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_170);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_34) {
    operator_delete(local_48);
  }
  local_34 = 7;
  local_38 = 0;
  local_48 = (char *)((uint)local_48 & 0xffff0000);
  ExceptionList = local_10;
  local_1ac = (undefined4 *)0x1000f8b9;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f8d0 at 1000f8d0

void __thiscall FUN_1000f8d0(void *this,undefined2 *param_1)

{
  ushort *puVar1;
  int *piVar2;
  undefined **local_d0;
  undefined **local_cc;
  undefined4 local_c8 [14];
  undefined4 local_90;
  undefined4 local_8c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_80 [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_38;
  undefined2 *local_34;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_30;
  undefined4 local_2c;
  wchar_t local_28 [10];
  ushort *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001387e;
  local_10 = ExceptionList;
  puVar1 = (ushort *)(DAT_1001d274 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_34 = param_1;
  local_2c = 0;
  local_14 = puVar1;
  FUN_1000a7b0((void *)((int)this + 0x120),local_28,L"%m%d%Y");
  local_d0 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_80);
  local_8 = 1;
  local_2c = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_d0,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_cc,
             false);
  local_8 = 2;
  *(undefined ***)((int)&local_d0 + (int)local_d0[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_30 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_cc;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_cc);
  local_cc = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_90 = 0;
  local_8c = 4;
  local_8 = 6;
  piVar2 = (int *)FUN_1000bb80((int *)&local_d0,(ushort *)local_28);
  FUN_1000be00(piVar2,puVar1);
  FUN_1000c750(&local_d0,param_1);
  local_2c = 3;
  local_30 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_80;
  *(undefined ***)((int)&local_d0 + (int)local_d0[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_38 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_cc;
  local_cc = std::
             basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
             ::vftable;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  FUN_1000aec0(local_38);
  local_8._0_1_ = 7;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_cc);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_c8);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_80);
  ExceptionList = local_10;
  local_c8[0] = 0x1000fa61;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fa70 at 1000fa70

void __thiscall FUN_1000fa70(void *this,undefined2 *param_1)

{
  undefined4 *puVar1;
  wchar_t wVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  wchar_t *pwVar6;
  undefined4 *puVar7;
  wchar_t *pwVar8;
  ushort *unaff_ESI;
  ushort *puVar9;
  undefined **ppuVar10;
  int iVar11;
  ushort *in_stack_ffffff0c;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_ac [72];
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_64;
  undefined2 *local_60;
  undefined4 local_5c;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_58;
  void *local_54 [3];
  undefined1 local_48 [4];
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  int local_28;
  uint local_24;
  wchar_t local_1c [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013941;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = 0;
  local_60 = param_1;
  ppuVar10 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_ac);
  local_8 = 1;
  puVar9 = (ushort *)0x0;
  local_5c = 2;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff04,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff08,false);
  local_8 = 2;
  *(undefined ***)(&stack0xffffff04 + (int)ppuVar10[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_58 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff08;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff08);
  local_8 = 6;
  puVar3 = (undefined4 *)std::setw(CONCAT44(2,local_48));
  piVar4 = (int *)FUN_1000bb80((int *)&stack0xffffff04,(ushort *)&DAT_100161a4);
  piVar4 = (int *)FUN_1000be00(piVar4,puVar9);
  piVar5 = (int *)FUN_1000bb80(piVar4,unaff_ESI);
  piVar4 = piVar5;
  if (piVar5 != (int *)0x0) {
    piVar4 = (int *)(*(int *)(*piVar5 + 4) + (int)piVar5);
  }
  (*(code *)*puVar3)(piVar4,puVar3[2]);
  *(undefined2 *)(*(int *)(*piVar5 + 4) + 0x40 + (int)piVar5) = 0x30;
  pwVar6 = _itow(*(int *)((int)this + 0x114),local_1c,0x24);
  local_24 = 7;
  local_28 = 0;
  local_38 = (undefined4 *)((uint)local_38._2_2_ << 0x10);
  pwVar8 = pwVar6;
  do {
    wVar2 = *pwVar8;
    pwVar8 = pwVar8 + 1;
  } while (wVar2 != L'\0');
  FUN_100019b0(&local_38,(int *)pwVar6,(int)pwVar8 - (int)(pwVar6 + 1) >> 1);
  local_8._0_1_ = 7;
  puVar3 = local_38;
  if (local_24 < 8) {
    puVar3 = &local_38;
  }
  puVar1 = (undefined4 *)((int)puVar3 + local_28 * 2);
  puVar7 = local_38;
  if (local_24 < 8) {
    puVar7 = &local_38;
  }
  if (puVar7 != puVar1) {
    FUN_1000c030((int *)&local_58,(undefined2 *)puVar7,(undefined2 *)puVar1,(undefined2 *)puVar3,
                 toupper_exref);
  }
  puVar9 = (ushort *)FUN_1000f8d0(this,(undefined2 *)local_54);
  local_8._0_1_ = 8;
  piVar4 = (int *)FUN_1000be00((int *)&stack0xffffff04,puVar9);
  iVar11 = 0x1000fc56;
  FUN_1000be00(piVar4,in_stack_ffffff0c);
  local_8._0_1_ = 7;
  if (7 < local_40) {
    operator_delete(local_54[0]);
  }
  local_40 = 7;
  local_44 = 0;
  local_54[0] = (void *)((uint)local_54[0] & 0xffff0000);
  FUN_1000c750(&stack0xffffff04,local_60);
  local_5c = 3;
  local_8 = CONCAT31(local_8._1_3_,6);
  if (7 < local_24) {
    operator_delete(local_38);
  }
  local_24 = 7;
  local_28 = 0;
  local_38 = (undefined4 *)((uint)local_38 & 0xffff0000);
  local_58 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_ac;
  *(undefined ***)(&stack0xffffff04 + *(int *)(iVar11 + 4)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_64 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff08;
  local_8._0_1_ = 0xb;
  local_8._1_3_ = 0;
  FUN_1000aec0(local_64);
  local_8._0_1_ = 9;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff08);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xffffff0c);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_ac);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fd60 at 1000fd60

void __thiscall FUN_1000fd60(void *this,undefined2 *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  void **ppvVar4;
  ushort *unaff_EDI;
  ushort *puVar5;
  ushort *puVar6;
  int **ppiVar7;
  undefined4 uVar8;
  undefined **ppuVar9;
  undefined **local_1c4;
  ushort *in_stack_fffffe44;
  ushort *in_stack_fffffe50;
  ushort *in_stack_fffffe5c;
  ushort *in_stack_fffffe68;
  ushort *in_stack_fffffe74;
  ushort *in_stack_fffffe88;
  ushort *in_stack_fffffe94;
  undefined **local_130;
  undefined **local_12c;
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> local_128 [56];
  undefined4 local_f0;
  undefined4 local_ec;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_e0 [72];
  undefined2 *local_98;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_94;
  int *local_90;
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *local_8c;
  uint local_88;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10013aef;
  local_10 = ExceptionList;
  uVar2 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_88 = 0;
  local_98 = param_1;
  local_130 = &PTR_10016198;
  local_14 = uVar2;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_e0);
  local_8 = 1;
  uVar8 = 0;
  local_88 = 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_130,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_12c,
             false);
  local_8 = 2;
  *(undefined ***)((int)&local_130 + (int)local_130[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_12c;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_12c)
  ;
  local_12c = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_f0 = 0;
  local_ec = 4;
  local_90 = (int *)0x0;
  local_8._0_1_ = 7;
  local_8._1_3_ = 0;
  ppiVar7 = &local_90;
  (**(code **)(*(int *)((int)this + 8) + 0x2c))((int)this + 8,ppiVar7,uVar8,uVar2);
  local_84 = (void *)((uint)local_84._2_2_ << 0x10);
  local_70 = 7;
  local_74 = 0;
  piVar3 = local_90;
  do {
    iVar1 = *piVar3;
    piVar3 = (int *)((int)piVar3 + 2);
  } while ((short)iVar1 != 0);
  FUN_100019b0(&local_84,local_90,(int)piVar3 - ((int)local_90 + 2) >> 1);
  local_8._0_1_ = 8;
  ppuVar9 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffe88)
  ;
  local_8 = CONCAT31(local_8._1_3_,9);
  local_88 = 0x18;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe38,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c4,
             false);
  local_8 = 10;
  *(undefined ***)(&stack0xfffffe38 + (int)ppuVar9[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c4;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c4)
  ;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_1c4 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 0xe;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe38,*(long *)((int)this + 0x118));
  if (*(int *)((int)this + 0x118) == 0) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    FUN_100019b0(local_30,(int *)L"uncounted",9);
    ppvVar4 = local_30;
    local_8 = CONCAT31(local_8._1_3_,0xf);
    local_88 = 0x19;
  }
  else {
    ppvVar4 = (void **)FUN_1000c750(&stack0xfffffe38,(undefined2 *)local_4c);
    local_8 = 0x10;
    local_88 = 0x1a;
  }
  local_54 = 7;
  local_58 = 0;
  local_68 = (void *)((uint)local_68._2_2_ << 0x10);
  FUN_1000c2d0(&local_68,ppvVar4);
  local_8 = 0x12;
  if ((local_88 & 2) != 0) {
    local_88 = local_88 & 0xfffffffd;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  }
  local_8._0_1_ = 0x13;
  if ((local_88 & 1) != 0) {
    local_88 = local_88 & 0xfffffffe;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  }
  puVar6 = (ushort *)&DAT_10016334;
  puVar5 = (ushort *)((int)this + 0x4c);
  piVar3 = (int *)FUN_1000bb80((int *)&local_130,(ushort *)L"FEATURE ");
  piVar3 = (int *)FUN_1000be00(piVar3,puVar5);
  piVar3 = (int *)FUN_1000bb80(piVar3,puVar6);
  piVar3 = (int *)FUN_1000be00(piVar3,(ushort *)ppiVar7);
  piVar3 = (int *)FUN_1000bb80(piVar3,unaff_EDI);
  piVar3 = (int *)FUN_1000be00(piVar3,(ushort *)ppuVar9);
  local_1c4 = (undefined **)0x1001005d;
  FUN_1000bb80(piVar3,in_stack_fffffe44);
  puVar6 = (ushort *)&DAT_10016334;
  local_1c4 = (undefined **)&DAT_10016334;
  puVar5 = (ushort *)&local_84;
  piVar3 = (int *)FUN_1000be00((int *)&local_130,puVar5);
  local_1c4 = (undefined **)0x10010093;
  piVar3 = (int *)FUN_1000bb80(piVar3,puVar6);
  piVar3 = (int *)FUN_1000be00(piVar3,in_stack_fffffe50);
  piVar3 = (int *)FUN_1000bb80(piVar3,in_stack_fffffe5c);
  piVar3 = (int *)FUN_1000be00(piVar3,in_stack_fffffe68);
  FUN_1000bb80(piVar3,in_stack_fffffe74);
  puVar6 = (ushort *)FUN_1000fa70(this,(undefined2 *)local_30);
  local_8._0_1_ = 0x14;
  FUN_1000f080(this,(undefined2 *)local_4c);
  local_8._0_1_ = 0x15;
  piVar3 = (int *)FUN_1000bb80((int *)&local_130,(ushort *)L" HOSTID=");
  piVar3 = (int *)FUN_1000be00(piVar3,puVar6);
  piVar3 = (int *)FUN_1000bb80(piVar3,in_stack_fffffe88);
  FUN_1000be00(piVar3,in_stack_fffffe94);
  local_8._0_1_ = 0x14;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  local_8._0_1_ = 0x13;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  FUN_1000c750(&local_130,local_98);
  local_88 = local_88 | 4;
  local_8._0_1_ = 0xe;
  if (7 < local_54) {
    operator_delete(local_68);
  }
  local_54 = 7;
  local_58 = 0;
  local_68 = (void *)((uint)local_68 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  local_8c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe88;
  *(undefined ***)(&stack0xfffffe38 + *(int *)(puVar5 + 2)) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_94 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c4;
  local_1c4 = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 0x18;
  FUN_1000aec0(local_94);
  local_8._0_1_ = 0x16;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1c4)
  ;
  local_8._0_1_ = 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe40);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffe88)
  ;
  local_8._0_1_ = 7;
  if (7 < local_70) {
    operator_delete(local_84);
  }
  local_70 = 7;
  local_74 = 0;
  local_84 = (void *)((uint)local_84 & 0xffff0000);
  local_8 = CONCAT31(local_8._1_3_,6);
  Ordinal_6();
  local_94 = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_e0;
  *(undefined ***)((int)&local_130 + (int)local_130[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8c = (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_12c;
  local_12c = std::
              basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
              ::vftable;
  local_8._0_1_ = 0x1b;
  local_8._1_3_ = 0;
  FUN_1000aec0(local_8c);
  local_8._0_1_ = 0x19;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_12c)
  ;
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_128);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_e0);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100102e0 at 100102e0

/* WARNING: Removing unreachable block (ram,0x100107fd) */

void __thiscall FUN_100102e0(void *this,ushort *param_1)

{
  wchar_t wVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  ushort *unaff_ESI;
  wchar_t *pwVar7;
  ushort *puVar8;
  undefined **ppuVar9;
  undefined4 local_1a8;
  ushort *in_stack_fffffe60;
  ushort *in_stack_fffffe6c;
  ushort *in_stack_fffffe78;
  ushort *in_stack_fffffe84;
  ushort *puVar10;
  ushort *in_stack_fffffeac;
  ushort *in_stack_fffffeb8;
  ushort *in_stack_fffffec4;
  ushort *in_stack_fffffed0;
  ushort *in_stack_fffffedc;
  ushort *in_stack_fffffee8;
  undefined2 *local_114;
  undefined4 in_stack_ffffff00;
  ushort uVar12;
  ushort *puVar11;
  undefined4 local_e4;
  undefined4 local_d4;
  uint local_d0;
  void *local_c8 [4];
  undefined4 local_b8;
  uint local_b4;
  undefined **local_ac;
  undefined **local_a8 [12];
  wchar_t local_78;
  undefined1 local_76 [10];
  undefined4 local_6c;
  undefined4 local_68;
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> local_5c [72];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  uVar12 = (ushort)((uint)in_stack_ffffff00 >> 0x10);
  local_8 = 0xffffffff;
  puStack_c = &LAB_100131a1;
  local_10 = ExceptionList;
  local_14 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppuVar9 = &PTR_10016198;
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffea0)
  ;
  local_8 = 1;
  puVar8 = (ushort *)0x0;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe50,
             (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe54,false);
  local_8 = 2;
  *(undefined ***)(&stack0xfffffe50 + (int)ppuVar9[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe54);
  ppuVar9 = std::
            basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
            ::vftable;
  puVar10 = (ushort *)0x0;
  puVar11 = (ushort *)((uint)uVar12 << 0x10);
  local_8 = 7;
  FUN_1000a580(&local_114,2000,1,1,0,0,0);
  uVar2 = FUN_1000a500((void *)((int)this + 0x120),(double *)&local_114);
  if ((char)uVar2 == '\0') {
    uVar3 = 9;
    pwVar7 = L"permanent";
  }
  else {
    FUN_1000a7b0((void *)((int)this + 0x120),&local_78,L"%d-%b-%Y");
    pwVar7 = &local_78;
    do {
      wVar1 = *pwVar7;
      pwVar7 = pwVar7 + 1;
    } while (wVar1 != L'\0');
    uVar3 = (int)pwVar7 - (int)local_76 >> 1;
    pwVar7 = &local_78;
  }
  FUN_100019b0(&stack0xffffff00,(int *)pwVar7,uVar3);
  local_d0 = 7;
  local_d4 = 0;
  local_e4 = (void *)((uint)local_e4._2_2_ << 0x10);
  local_8._0_1_ = 8;
  if (*(int *)((int)this + 0x118) < 1) {
    FUN_100019b0(&local_e4,(int *)L"uncounted",9);
  }
  else {
    local_ac = &PTR_10016198;
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>(local_5c);
    local_8 = CONCAT31(local_8._1_3_,9);
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac,
               (basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_a8,
               false);
    local_8 = 10;
    *(undefined ***)((int)local_a8 + (int)(local_ac[1] + -4)) =
         std::
         basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
         ::vftable;
    std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)local_a8)
    ;
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_a8[0] = std::
                  basic_stringbuf<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
                  ::vftable;
    local_6c = 0;
    local_68 = 4;
    local_8._0_1_ = 0xe;
    std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::operator<<
              ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_ac,
               *(long *)((int)this + 0x118));
    puVar4 = (undefined4 *)FUN_1000c750(&local_ac,(undefined2 *)local_c8);
    local_8._0_1_ = 0xf;
    FUN_1000c2d0(&local_e4,puVar4);
    local_8._0_1_ = 0xe;
    if (7 < local_b4) {
      operator_delete(local_c8[0]);
    }
    local_b4 = 7;
    local_b8 = 0;
    local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
    local_8._0_1_ = 8;
    FUN_1000c190((int *)&local_ac);
  }
  piVar5 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"<GenericLicense Expiration=\"");
  piVar5 = (int *)FUN_1000be00(piVar5,puVar8);
  FUN_1000bb80(piVar5,unaff_ESI);
  piVar5 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Name=\"");
  piVar6 = (int *)FUN_1000be00(piVar5,(ushort *)ppuVar9);
  local_1a8 = 0x100105d9;
  FUN_1000bb80(piVar6,in_stack_fffffe60);
  local_1a8 = 0x100105f6;
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"VendorDaemon=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffe6c);
  FUN_1000bb80(piVar6,in_stack_fffffe78);
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Key=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffe84);
  FUN_1000bb80(piVar6,puVar10);
  FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"IsValid=\"\" ");
  FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"ID=\"\" ");
  FUN_1000fa70(this,(undefined2 *)local_c8);
  local_8._0_1_ = 0x10;
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Data=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffeac);
  FUN_1000bb80(piVar6,in_stack_fffffeb8);
  local_8._0_1_ = 8;
  if (7 < local_b4) {
    operator_delete(local_c8[0]);
  }
  local_b4 = 7;
  local_b8 = 0;
  local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Version=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffec4);
  FUN_1000bb80(piVar6,in_stack_fffffed0);
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"Count=\"");
  piVar6 = (int *)FUN_1000be00(piVar6,in_stack_fffffedc);
  FUN_1000bb80(piVar6,in_stack_fffffee8);
  local_114 = (undefined2 *)0x10010740;
  local_114 = FUN_1000f080(this,(undefined2 *)local_c8);
  local_8._0_1_ = 0x11;
  piVar6 = (int *)FUN_1000bb80((int *)&stack0xfffffe50,(ushort *)L"HostID=\"");
  local_114 = (undefined2 *)0x10010764;
  piVar6 = (int *)FUN_1000be00(piVar6,param_1);
  FUN_1000bb80(piVar6,puVar11);
  local_8._0_1_ = 8;
  if (7 < local_b4) {
    operator_delete(local_c8[0]);
  }
  local_b4 = 7;
  local_b8 = 0;
  local_c8[0] = (void *)((uint)local_c8[0] & 0xffff0000);
  FUN_1000c750(&stack0xfffffe50,param_1);
  local_8._0_1_ = 7;
  if (7 < local_d0) {
    operator_delete(local_e4);
  }
  local_e4 = (void *)((uint)local_e4 & 0xffff0000);
  local_d0 = 7;
  local_d4 = 0;
  *(undefined ***)(&stack0xfffffe50 + piVar5[1]) =
       std::
       basic_ostringstream<unsigned_short,struct_std::char_traits<unsigned_short>,class_std::allocator<unsigned_short>_>
       ::vftable;
  local_8._0_1_ = 0x14;
  local_8._1_3_ = 0;
  FUN_1000aec0((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               &stack0xfffffe54);
  local_8._0_1_ = 0x12;
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             &stack0xfffffe54);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&local_1a8);
  std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)&stack0xfffffea0)
  ;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100108c0 at 100108c0

int __fastcall FUN_100108c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10013bb3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  local_8 = 2;
  *(undefined4 *)(param_1 + 0x44) = 7;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x30),(int *)L"INSITE_UsageCount_License",0x19);
  local_8._0_1_ = 3;
  *(undefined4 *)(param_1 + 0x60) = 7;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x4c),(int *)L"cummins",7);
  local_8._0_1_ = 4;
  *(undefined4 *)(param_1 + 0x7c) = 7;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x68) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x68),(int *)L"1.000",5);
  local_8._0_1_ = 5;
  *(undefined4 *)(param_1 + 0x98) = 7;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined2 *)(param_1 + 0x84) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0x84),(int *)&DAT_1001634c,1);
  local_8._0_1_ = 6;
  *(undefined4 *)(param_1 + 0xb4) = 7;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined2 *)(param_1 + 0xa0) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0xa0),(int *)&PTR_10015500,0);
  *(undefined4 *)(param_1 + 0xd0) = 7;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined2 *)(param_1 + 0xbc) = 0;
  local_8._0_1_ = 8;
  *(undefined4 *)(param_1 + 0xec) = 7;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined2 *)(param_1 + 0xd8) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0xd8),(int *)L"UsageCount",10);
  local_8 = CONCAT31(local_8._1_3_,9);
  *(undefined4 *)(param_1 + 0x108) = 7;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined2 *)(param_1 + 0xf4) = 0;
  FUN_100019b0((undefined2 *)(param_1 + 0xf4),(int *)&PTR_10015500,0);
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10010a55 at 10010a55

void __fastcall FUN_10010a55(int *param_1)

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



// Function: FUN_10010a99 at 10010a99

int __fastcall FUN_10010a99(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_10010ab2 at 10010ab2

undefined4 * __fastcall FUN_10010ab2(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10010a99((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_1001a170;
  param_1[3] = &DAT_1001a170;
  uVar1 = FUN_10002460((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_1001d2a0 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_10010af3 at 10010af3

void __fastcall FUN_10010af3(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10010b12 at 10010b12

int __fastcall FUN_10010b12(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10010b37 at 10010b37

void __fastcall FUN_10010b37(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_10010af3((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10010b4f at 10010b4f

undefined4 * __fastcall FUN_10010b4f(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10010b12((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10016710;
  uVar1 = FUN_10002460((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_1001d2a0 = 1;
  }
  return param_1;
}



// Function: ~CWin32Heap at 10010b8f

/* Library Function - Single Match
    public: virtual __thiscall ATL::CWin32Heap::~CWin32Heap(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __thiscall ATL::CWin32Heap::~CWin32Heap(CWin32Heap *this)

{
  *(undefined ***)this = &PTR_FUN_10016720;
  if ((this[8] != (CWin32Heap)0x0) && (*(HANDLE *)(this + 4) != (HANDLE)0x0)) {
    HeapDestroy(*(HANDLE *)(this + 4));
  }
  return;
}



// Function: FUN_10010baa at 10010baa

void __thiscall FUN_10010baa(void *this,SIZE_T param_1)

{
  HeapAlloc(*(HANDLE *)((int)this + 4),0,param_1);
  return;
}



// Function: FUN_10010bc1 at 10010bc1

void __thiscall FUN_10010bc1(void *this,LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    HeapFree(*(HANDLE *)((int)this + 4),0,param_1);
  }
  return;
}



// Function: Reallocate at 10010bde

/* Library Function - Single Match
    public: virtual void * __thiscall ATL::CWin32Heap::Reallocate(void *,unsigned int)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void * __thiscall ATL::CWin32Heap::Reallocate(CWin32Heap *this,void *param_1,uint param_2)

{
  void *pvVar1;
  
  if (param_1 == (void *)0x0) {
    pvVar1 = (void *)(*(code *)**(undefined4 **)this)(param_2);
  }
  else if (param_2 == 0) {
    (**(code **)(*(int *)this + 4))(param_1);
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = HeapReAlloc(*(HANDLE *)(this + 4),0,param_1,param_2);
  }
  return pvVar1;
}



// Function: FUN_10010c18 at 10010c18

void __thiscall FUN_10010c18(void *this,LPCVOID param_1)

{
  HeapSize(*(HANDLE *)((int)this + 4),0,param_1);
  return;
}



// Function: `scalar_deleting_destructor' at 10010c2f

/* Library Function - Single Match
    public: virtual void * __thiscall ATL::CWin32Heap::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void * __thiscall ATL::CWin32Heap::_scalar_deleting_destructor_(CWin32Heap *this,uint param_1)

{
  ~CWin32Heap(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10010c50 at 10010c50

void __fastcall FUN_10010c50(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10010c5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 4) + 4))();
  return;
}



// Function: FUN_10010c6f at 10010c6f

undefined4 * __thiscall FUN_10010c6f(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_Allocate_10016734;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: AtlAdd<unsigned_int> at 10010c91

/* Library Function - Single Match
    long __cdecl ATL::AtlAdd<unsigned int>(unsigned int *,unsigned int,unsigned int)
   
   Library: Visual Studio 2010 Release */

long __cdecl ATL::AtlAdd<unsigned_int>(uint *param_1,uint param_2,uint param_3)

{
  if (-param_2 - 1 < param_3) {
    return -0x7ff8fdea;
  }
  *param_1 = param_2 + param_3;
  return 0;
}



// Function: Allocate at 10010cb7

/* Library Function - Single Match
    public: virtual struct ATL::CStringData * __thiscall ATL::CAtlStringMgr::Allocate(int,int)
   
   Library: Visual Studio 2010 Release */

CStringData * __thiscall ATL::CAtlStringMgr::Allocate(CAtlStringMgr *this,int param_1,int param_2)

{
  long lVar1;
  CStringData *pCVar2;
  uint uVar3;
  
  uVar3 = param_1 + 8U & 0xfffffff8;
  lVar1 = AtlMultiply<unsigned_long>((ulong *)&param_1,uVar3,param_2);
  if (((-1 < lVar1) && (lVar1 = AtlAdd<unsigned_int>((uint *)&param_1,0x10,param_1), -1 < lVar1)) &&
     (pCVar2 = (CStringData *)(**(code **)**(undefined4 **)(this + 4))(param_1),
     pCVar2 != (CStringData *)0x0)) {
    *(undefined4 *)(pCVar2 + 4) = 0;
    *(CAtlStringMgr **)pCVar2 = this;
    *(undefined4 *)(pCVar2 + 0xc) = 1;
    *(uint *)(pCVar2 + 8) = uVar3 - 1;
    return pCVar2;
  }
  return (CStringData *)0x0;
}



// Function: Reallocate at 10010d1b

/* Library Function - Single Match
    public: virtual struct ATL::CStringData * __thiscall ATL::CAtlStringMgr::Reallocate(struct
   ATL::CStringData *,int,int)
   
   Library: Visual Studio 2010 Release */

CStringData * __thiscall
ATL::CAtlStringMgr::Reallocate(CAtlStringMgr *this,CStringData *param_1,int param_2,int param_3)

{
  long lVar1;
  CStringData *pCVar2;
  uint uVar3;
  
  uVar3 = param_2 + 8U & 0xfffffff8;
  lVar1 = AtlMultiply<unsigned_long>((ulong *)&param_2,uVar3,param_3);
  if (((-1 < lVar1) && (lVar1 = AtlAdd<unsigned_long>((ulong *)&param_2,0x10,param_2), -1 < lVar1))
     && (pCVar2 = (CStringData *)(**(code **)(**(int **)(this + 4) + 8))(param_1,param_2),
        pCVar2 != (CStringData *)0x0)) {
    *(uint *)(pCVar2 + 8) = uVar3 - 1;
    return pCVar2;
  }
  return (CStringData *)0x0;
}



// Function: FUN_10010d76 at 10010d76

void FUN_10010d76(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10010dc4

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



// Function: __security_check_cookie at 10010e16

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1001d274) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __ArrayUnwind at 10010e44

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



// Function: `eh_vector_destructor_iterator' at 10010ea2

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
  FUN_10010eed();
  return;
}



// Function: FUN_10010eed at 10010eed

void FUN_10010eed(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __alloca_probe at 10010f10

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



// Function: __alloca_probe_16 at 10010f70

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



// Function: __alloca_probe_8 at 10010f86

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



// Function: `eh_vector_constructor_iterator' at 10010f9c

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
  FUN_10010fe9();
  return;
}



// Function: FUN_10010fe9 at 10010fe9

void FUN_10010fe9(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 10011001

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
  
  local_8 = &DAT_1001a108;
  uStack_c = 0x1001100d;
  local_20[0] = DecodePointer(DAT_1001d6e0);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1001d6e0);
    local_24 = DecodePointer(DAT_1001d6dc);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1001d6e0 = EncodePointer(local_20[0]);
    DAT_1001d6dc = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10011099();
  }
  return p_Var1;
}



// Function: FUN_10011099 at 10011099

void FUN_10011099(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 100110a2

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: FUN_100110d0 at 100110d0

ulonglong __fastcall FUN_100110d0(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint local_20;
  float fStack_1c;
  
  if (DAT_1001d6d4 == 0) {
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



// Function: __CRT_INIT@12 at 100111d0

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
    if (DAT_1001d398 < 1) {
      return 0;
    }
    DAT_1001d398 = DAT_1001d398 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1001d6d0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1001d6cc == 2) {
      param_2 = (int *)DecodePointer(DAT_1001d6e0);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_1001d6dc);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1001d6e0);
            piVar8 = (int *)DecodePointer(DAT_1001d6dc);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_1001d6dc = (PVOID)encoded_null();
        DAT_1001d6e0 = DAT_1001d6dc;
      }
      DAT_1001d6cc = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_1001d6d0,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_1001d6d0,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1001d6cc == 0) {
      DAT_1001d6cc = 1;
      iVar5 = initterm_e(&DAT_100152f8,&DAT_10015304);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10015280,&DAT_100152f4);
      DAT_1001d6cc = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_1001d6d0,0);
    }
    if ((DAT_1001d6d8 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1001d6d8), BVar2 != 0)) {
      (*DAT_1001d6d8)(param_1,2,param_3);
    }
    DAT_1001d398 = DAT_1001d398 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 100113da

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001147a) */
/* WARNING: Removing unreachable block (ram,0x10011427) */
/* WARNING: Removing unreachable block (ram,0x100114a7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_1001d280 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_1001d398 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10003860(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10003860(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_100114e5();
  return local_20;
}



// Function: FUN_100114e5 at 100114e5

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100114e5(void)

{
  _DAT_1001d280 = 0xffffffff;
  return;
}



// Function: entry at 100114f0

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 10011513

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
  
  _DAT_1001d4b8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1001d4bc = &stack0x00000004;
  _DAT_1001d3f8 = 0x10001;
  _DAT_1001d3a0 = 0xc0000409;
  _DAT_1001d3a4 = 1;
  local_32c = DAT_1001d274;
  local_328 = DAT_1001d278;
  _DAT_1001d3ac = unaff_retaddr;
  _DAT_1001d484 = in_GS;
  _DAT_1001d488 = in_FS;
  _DAT_1001d48c = in_ES;
  _DAT_1001d490 = in_DS;
  _DAT_1001d494 = unaff_EDI;
  _DAT_1001d498 = unaff_ESI;
  _DAT_1001d49c = unaff_EBX;
  _DAT_1001d4a0 = in_EDX;
  _DAT_1001d4a4 = in_ECX;
  _DAT_1001d4a8 = in_EAX;
  _DAT_1001d4ac = unaff_EBP;
  DAT_1001d4b0 = unaff_retaddr;
  _DAT_1001d4b4 = in_CS;
  _DAT_1001d4c0 = in_SS;
  DAT_1001d3f0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10016758);
  if (DAT_1001d3f0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10011620

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001d274 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10011665

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



// Function: __ValidateImageBase at 10011700

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



// Function: __FindPESection at 10011740

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



// Function: __IsNonwritableInCurrentImage at 10011790

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2010 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  undefined4 local_8;
  
  puStack_10 = &LAB_10010f48;
  local_14 = ExceptionList;
  local_c = DAT_1001d274 ^ 0x1001a150;
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



// Function: ___security_init_cookie at 10011864

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
  if ((DAT_1001d274 == 0xbb40e64e) || ((DAT_1001d274 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1001d274 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1001d274 == 0xbb40e64e) {
      DAT_1001d274 = 0xbb40e64f;
    }
    else if ((DAT_1001d274 & 0xffff0000) == 0) {
      DAT_1001d274 = DAT_1001d274 | (DAT_1001d274 | 0x4711) << 0x10;
    }
    DAT_1001d278 = ~DAT_1001d274;
  }
  else {
    DAT_1001d278 = ~DAT_1001d274;
  }
  return;
}



// Function: Unwind@10011920 at 10011920

void Unwind_10011920(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10011923. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011950 at 10011950

void Unwind_10011950(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10011953. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011980 at 10011980

void Unwind_10011980(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100119b0 at 100119b0

void Unwind_100119b0(void)

{
  int unaff_EBP;
  
  FUN_10003000(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100119e0 at 100119e0

void Unwind_100119e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100119e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10011a10 at 10011a10

void Unwind_10011a10(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10011a1b at 10011a1b

void Unwind_10011a1b(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011a40 at 10011a40

void Unwind_10011a40(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011a48 at 10011a48

void Unwind_10011a48(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011a50 at 10011a50

void Unwind_10011a50(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011a80 at 10011a80

void Unwind_10011a80(void)

{
  FUN_100011b0();
  return;
}



// Function: Unwind@10011ad0 at 10011ad0

void Unwind_10011ad0(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10011b40 at 10011b40

void Unwind_10011b40(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10011b70 at 10011b70

void Unwind_10011b70(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10011b78 at 10011b78

void Unwind_10011b78(void)

{
  int unaff_EBP;
  
  FUN_10001730((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10011b80 at 10011b80

void Unwind_10011b80(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10011bb0 at 10011bb0

void Unwind_10011bb0(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10011bb8 at 10011bb8

void Unwind_10011bb8(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10011bc3 at 10011bc3

void Unwind_10011bc3(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10011bce at 10011bce

void Unwind_10011bce(void)

{
  int unaff_EBP;
  
  FUN_10001c50((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10011c00 at 10011c00

void Unwind_10011c00(void)

{
  int unaff_EBP;
  
  FUN_10001020((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10011c08 at 10011c08

void Unwind_10011c08(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011c10 at 10011c10

void Unwind_10011c10(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011c40 at 10011c40

void Unwind_10011c40(void)

{
  DAT_1001d2d8 = DAT_1001d2d8 & 0xfffffffe;
  return;
}



// Function: Unwind@10011c70 at 10011c70

void Unwind_10011c70(void)

{
  int unaff_EBP;
  
  FUN_100030d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011ca0 at 10011ca0

void Unwind_10011ca0(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10011ce0 at 10011ce0

void Unwind_10011ce0(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011d10 at 10011d10

void Unwind_10011d10(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0x23c));
  return;
}



// Function: Unwind@10011d50 at 10011d50

void Unwind_10011d50(void)

{
  int unaff_EBP;
  
  FUN_10003120(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011d58 at 10011d58

void Unwind_10011d58(void)

{
  int unaff_EBP;
  
  FUN_100030d0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011d80 at 10011d80

void Unwind_10011d80(void)

{
  int unaff_EBP;
  
  FUN_10003760(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011db0 at 10011db0

void Unwind_10011db0(void)

{
  int unaff_EBP;
  
  FUN_10003a80((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10011dbb at 10011dbb

void Unwind_10011dbb(void)

{
  int unaff_EBP;
  
  FUN_10003760(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011de0 at 10011de0

void Unwind_10011de0(void)

{
  int unaff_EBP;
  
  FUN_10002910(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@10011e10 at 10011e10

void Unwind_10011e10(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10011e1b at 10011e1b

void Unwind_10011e1b(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10011e26 at 10011e26

void Unwind_10011e26(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10011e31 at 10011e31

void Unwind_10011e31(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10011e3c at 10011e3c

void Unwind_10011e3c(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10011e47 at 10011e47

void Unwind_10011e47(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@10011e52 at 10011e52

void Unwind_10011e52(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x1c0));
  return;
}



// Function: Unwind@10011e5d at 10011e5d

void Unwind_10011e5d(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@10011e68 at 10011e68

void Unwind_10011e68(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10011e73 at 10011e73

void Unwind_10011e73(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@10011eb0 at 10011eb0

void Unwind_10011eb0(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011eb8 at 10011eb8

void Unwind_10011eb8(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011ec0 at 10011ec0

void Unwind_10011ec0(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011ec8 at 10011ec8

void Unwind_10011ec8(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011ef0 at 10011ef0

void Unwind_10011ef0(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@10011efb at 10011efb

void Unwind_10011efb(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10011f06 at 10011f06

void Unwind_10011f06(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10011f11 at 10011f11

void Unwind_10011f11(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10011f1c at 10011f1c

void Unwind_10011f1c(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10011f50 at 10011f50

void Unwind_10011f50(void)

{
  int unaff_EBP;
  
  FUN_10003840((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011f80 at 10011f80

void Unwind_10011f80(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10011f8b at 10011f8b

void Unwind_10011f8b(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10011f96 at 10011f96

void Unwind_10011f96(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011fc0 at 10011fc0

void Unwind_10011fc0(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10011fcb at 10011fcb

void Unwind_10011fcb(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10011fd6 at 10011fd6

void Unwind_10011fd6(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012000 at 10012000

void Unwind_10012000(void)

{
  FUN_100011b0();
  return;
}



// Function: Unwind@10012019 at 10012019

void Unwind_10012019(void)

{
  FUN_100011b0();
  return;
}



// Function: Unwind@10012050 at 10012050

void Unwind_10012050(void)

{
  int unaff_EBP;
  
  FUN_10003810((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10012058 at 10012058

void Unwind_10012058(void)

{
  int unaff_EBP;
  
  FUN_10003810((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10012080 at 10012080

void Unwind_10012080(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100120b0 at 100120b0

void Unwind_100120b0(void)

{
  int unaff_EBP;
  
  FUN_10003830((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@100120bb at 100120bb

void Unwind_100120bb(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@100120c6 at 100120c6

void Unwind_100120c6(void)

{
  int unaff_EBP;
  
  FUN_10003830((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@10012100 at 10012100

void Unwind_10012100(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x2228));
  return;
}



// Function: Unwind@1001210b at 1001210b

void Unwind_1001210b(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x223c));
  return;
}



// Function: Unwind@10012116 at 10012116

void Unwind_10012116(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@10012121 at 10012121

void Unwind_10012121(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x2268));
  return;
}



// Function: Unwind@1001212c at 1001212c

void Unwind_1001212c(void)

{
  int unaff_EBP;
  
  FUN_100031a0((undefined4 *)(unaff_EBP + -0x225c));
  return;
}



// Function: Unwind@10012160 at 10012160

void Unwind_10012160(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10012168 at 10012168

void Unwind_10012168(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10012173 at 10012173

void Unwind_10012173(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001217e at 1001217e

void Unwind_1001217e(void)

{
  int unaff_EBP;
  
  FUN_10004770(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100121b0 at 100121b0

void Unwind_100121b0(void)

{
  int unaff_EBP;
  
  FUN_10004770(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100121b8 at 100121b8

void Unwind_100121b8(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@100121c3 at 100121c3

void Unwind_100121c3(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100121ce at 100121ce

void Unwind_100121ce(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012200 at 10012200

void Unwind_10012200(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10012230 at 10012230

void Unwind_10012230(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@1001223b at 1001223b

void Unwind_1001223b(void)

{
  int unaff_EBP;
  
  FUN_10003830((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10012270 at 10012270

void Unwind_10012270(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100122a0 at 100122a0

void Unwind_100122a0(void)

{
  int unaff_EBP;
  
  FUN_10003760(*(undefined4 **)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@100122ab at 100122ab

void Unwind_100122ab(void)

{
  int unaff_EBP;
  
  FUN_10003a80((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@100122b6 at 100122b6

void Unwind_100122b6(void)

{
  int unaff_EBP;
  
  FUN_10003b00((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@100122c1 at 100122c1

void Unwind_100122c1(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0xa60));
  return;
}



// Function: Unwind@100122cc at 100122cc

void Unwind_100122cc(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10012300 at 10012300

void Unwind_10012300(void)

{
  int unaff_EBP;
  
  FUN_10003760(*(undefined4 **)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1001230b at 1001230b

void Unwind_1001230b(void)

{
  int unaff_EBP;
  
  FUN_10003a80((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@10012316 at 10012316

void Unwind_10012316(void)

{
  int unaff_EBP;
  
  FUN_10003b00((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@10012321 at 10012321

void Unwind_10012321(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1001232c at 1001232c

void Unwind_1001232c(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@10012360 at 10012360

void Unwind_10012360(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001236b at 1001236b

void Unwind_1001236b(void)

{
  int unaff_EBP;
  
  FUN_10001c50((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10012376 at 10012376

void Unwind_10012376(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012381 at 10012381

void Unwind_10012381(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100123b0 at 100123b0

void Unwind_100123b0(void)

{
  int unaff_EBP;
  
  FUN_10006a70(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100123b8 at 100123b8

void Unwind_100123b8(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@100123c3 at 100123c3

void Unwind_100123c3(void)

{
  int unaff_EBP;
  
  FUN_10001c50((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@100123ce at 100123ce

void Unwind_100123ce(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100123d9 at 100123d9

void Unwind_100123d9(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012400 at 10012400

void Unwind_10012400(void)

{
  int unaff_EBP;
  
  FUN_100010a0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012430 at 10012430

void Unwind_10012430(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001243b at 1001243b

void Unwind_1001243b(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10012460 at 10012460

void Unwind_10012460(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012468 at 10012468

void Unwind_10012468(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012470 at 10012470

void Unwind_10012470(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012478 at 10012478

void Unwind_10012478(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012480 at 10012480

void Unwind_10012480(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012488 at 10012488

void Unwind_10012488(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100124b0 at 100124b0

void Unwind_100124b0(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100124bb at 100124bb

void Unwind_100124bb(void)

{
  int unaff_EBP;
  
  FUN_10003000(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100124e0 at 100124e0

void Unwind_100124e0(void)

{
  int unaff_EBP;
  
  FUN_10003840((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10012510 at 10012510

void Unwind_10012510(void)

{
  int unaff_EBP;
  
  FUN_10007170(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012560 at 10012560

void Unwind_10012560(void)

{
  int unaff_EBP;
  
  FUN_10003840((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1001256b at 1001256b

void Unwind_1001256b(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10012576 at 10012576

void Unwind_10012576(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10012581 at 10012581

void Unwind_10012581(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001258c at 1001258c

void Unwind_1001258c(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10012597 at 10012597

void Unwind_10012597(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100125a2 at 100125a2

void Unwind_100125a2(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@100125ad at 100125ad

void Unwind_100125ad(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@100125b8 at 100125b8

void Unwind_100125b8(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@100125c3 at 100125c3

void Unwind_100125c3(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@100125ce at 100125ce

void Unwind_100125ce(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10012610 at 10012610

void Unwind_10012610(void)

{
  int unaff_EBP;
  
  FUN_10003000(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012618 at 10012618

void Unwind_10012618(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012623 at 10012623

void Unwind_10012623(void)

{
  int unaff_EBP;
  
  FUN_10007170(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001262b at 1001262b

void Unwind_1001262b(void)

{
  int unaff_EBP;
  
  FUN_10007360(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012650 at 10012650

void Unwind_10012650(void)

{
  int unaff_EBP;
  
  FUN_10007360(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012658 at 10012658

void Unwind_10012658(void)

{
  int unaff_EBP;
  
  FUN_10007170(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100126a0 at 100126a0

void Unwind_100126a0(void)

{
  int unaff_EBP;
  
  FUN_10002fd0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100126d0 at 100126d0

void Unwind_100126d0(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100126d8 at 100126d8

void Unwind_100126d8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001300((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@100126f1 at 100126f1

void Unwind_100126f1(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100126f9 at 100126f9

void Unwind_100126f9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_10001300((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}



// Function: Unwind@10012712 at 10012712

void Unwind_10012712(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001271a at 1001271a

void Unwind_1001271a(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012740 at 10012740

void Unwind_10012740(void)

{
  int unaff_EBP;
  
  FUN_10006a70(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012770 at 10012770

void Unwind_10012770(void)

{
  int unaff_EBP;
  
  FUN_10006a70(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012778 at 10012778

void Unwind_10012778(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10012783 at 10012783

void Unwind_10012783(void)

{
  int unaff_EBP;
  
  FUN_10001c50((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001278e at 1001278e

void Unwind_1001278e(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10012799 at 10012799

void Unwind_10012799(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100127c0 at 100127c0

void Unwind_100127c0(void)

{
  int unaff_EBP;
  
  FUN_10006a70(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100127c8 at 100127c8

void Unwind_100127c8(void)

{
  int unaff_EBP;
  
  FUN_10006b00(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@100127f0 at 100127f0

void Unwind_100127f0(void)

{
  int unaff_EBP;
  
  FUN_10006b00(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10012840 at 10012840

void Unwind_10012840(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10012870 at 10012870

void Unwind_10012870(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x14);
  return;
}



// Function: Unwind@1001287b at 1001287b

void Unwind_1001287b(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@10012886 at 10012886

void Unwind_10012886(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x50));
  return;
}



// Function: Unwind@10012891 at 10012891

void Unwind_10012891(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001289c at 1001289c

void Unwind_1001289c(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}



// Function: Unwind@100128aa at 100128aa

void Unwind_100128aa(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa4));
  return;
}



// Function: Unwind@100128b8 at 100128b8

void Unwind_100128b8(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc0));
  return;
}



// Function: Unwind@100128c6 at 100128c6

void Unwind_100128c6(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@100128d4 at 100128d4

void Unwind_100128d4(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf8));
  return;
}



// Function: Unwind@100128e2 at 100128e2

void Unwind_100128e2(void)

{
  int unaff_EBP;
  
  FUN_10008630((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x130));
  return;
}



// Function: Unwind@100128f0 at 100128f0

void Unwind_100128f0(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100128fb at 100128fb

void Unwind_100128fb(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012920 at 10012920

void Unwind_10012920(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001292b at 1001292b

void Unwind_1001292b(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10012936 at 10012936

void Unwind_10012936(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@10012941 at 10012941

void Unwind_10012941(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@1001294c at 1001294c

void Unwind_1001294c(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@1001295a at 1001295a

void Unwind_1001295a(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa0));
  return;
}



// Function: Unwind@10012968 at 10012968

void Unwind_10012968(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xbc));
  return;
}



// Function: Unwind@10012976 at 10012976

void Unwind_10012976(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@10012984 at 10012984

void Unwind_10012984(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf4));
  return;
}



// Function: Unwind@10012992 at 10012992

void Unwind_10012992(void)

{
  int unaff_EBP;
  
  FUN_10008630((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x128));
  return;
}



// Function: Unwind@100129a0 at 100129a0

void Unwind_100129a0(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100129ab at 100129ab

void Unwind_100129ab(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100129d0 at 100129d0

void Unwind_100129d0(void)

{
  int unaff_EBP;
  
  FUN_100088b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012a00 at 10012a00

void Unwind_10012a00(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10012a30 at 10012a30

void Unwind_10012a30(void)

{
  int unaff_EBP;
  
  FUN_100088b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012a60 at 10012a60

void Unwind_10012a60(void)

{
  int unaff_EBP;
  
  FUN_100088b0(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012a68 at 10012a68

void Unwind_10012a68(void)

{
  int unaff_EBP;
  
  FUN_10008ad0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10012a90 at 10012a90

void Unwind_10012a90(void)

{
  int unaff_EBP;
  
  FUN_10008680(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012ac0 at 10012ac0

void Unwind_10012ac0(void)

{
  int unaff_EBP;
  
  FUN_10008ad0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10012acb at 10012acb

void Unwind_10012acb(void)

{
  int unaff_EBP;
  
  FUN_100088b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012b30 at 10012b30

void Unwind_10012b30(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10012b60 at 10012b60

void Unwind_10012b60(void)

{
  FUN_100030d0(0x1001d2dc);
  return;
}



// Function: Unwind@10012b6a at 10012b6a

void Unwind_10012b6a(void)

{
  FUN_10003120(0x1001d2dc);
  return;
}



// Function: Unwind@10012b90 at 10012b90

void Unwind_10012b90(void)

{
  FUN_10003120(0x1001d2dc);
  return;
}



// Function: Unwind@10012b9a at 10012b9a

void Unwind_10012b9a(void)

{
  FUN_100030d0(0x1001d2dc);
  return;
}



// Function: Unwind@10012bc0 at 10012bc0

void Unwind_10012bc0(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10012bf0 at 10012bf0

void Unwind_10012bf0(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10012c30 at 10012c30

void Unwind_10012c30(void)

{
  DAT_1001d328 = DAT_1001d328 & 0xfffffffe;
  return;
}



// Function: Unwind@10012c60 at 10012c60

void Unwind_10012c60(void)

{
  int unaff_EBP;
  
  FUN_1000ad60(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012c90 at 10012c90

void Unwind_10012c90(void)

{
  int unaff_EBP;
  
  FUN_1000ad60(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012cc0 at 10012cc0

void Unwind_10012cc0(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012cc8 at 10012cc8

void Unwind_10012cc8(void)

{
  int unaff_EBP;
  
  FUN_10001300((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012cd0 at 10012cd0

void Unwind_10012cd0(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012cd8 at 10012cd8

void Unwind_10012cd8(void)

{
  int unaff_EBP;
  
  FUN_10003000((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012d00 at 10012d00

void Unwind_10012d00(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + 0x1c));
  return;
}



// Function: Unwind@10012d30 at 10012d30

void Unwind_10012d30(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10012d33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012d60 at 10012d60

void Unwind_10012d60(void)

{
  int unaff_EBP;
  
  FUN_1000b120((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10012d68 at 10012d68

void Unwind_10012d68(void)

{
  int unaff_EBP;
  
  FUN_1000ad60((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10012d90 at 10012d90

void Unwind_10012d90(void)

{
  int unaff_EBP;
  
  FUN_1000b120((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10012d98 at 10012d98

void Unwind_10012d98(void)

{
  int unaff_EBP;
  
  FUN_1000ad60((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10012dc0 at 10012dc0

void Unwind_10012dc0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10012dc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10012dcc at 10012dcc

void Unwind_10012dcc(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@10012dd7 at 10012dd7

void Unwind_10012dd7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10012dda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012e00 at 10012e00

void Unwind_10012e00(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10012e08 at 10012e08

void Unwind_10012e08(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x34) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x34) = *(uint *)(unaff_EBP + -0x34) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x38));
    return;
  }
  return;
}



// Function: Unwind@10012e50 at 10012e50

void Unwind_10012e50(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10012e58 at 10012e58

void Unwind_10012e58(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x38));
    return;
  }
  return;
}



// Function: Unwind@10012e71 at 10012e71

void Unwind_10012e71(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10012e79 at 10012e79

void Unwind_10012e79(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10012eb0 at 10012eb0

void Unwind_10012eb0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10012f10 at 10012f10

void Unwind_10012f10(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x434) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x434) = *(uint *)(unaff_EBP + -0x434) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x10012f2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x484));
    return;
  }
  return;
}



// Function: Unwind@10012f33 at 10012f33

void Unwind_10012f33(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10012f39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x4cc));
  return;
}



// Function: Unwind@10012f3f at 10012f3f

void Unwind_10012f3f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10012f45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x430));
  return;
}



// Function: Unwind@10012f4b at 10012f4b

void Unwind_10012f4b(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x4d0));
  return;
}



// Function: Unwind@10012f56 at 10012f56

void Unwind_10012f56(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0x4d4));
  return;
}



// Function: Unwind@10012f61 at 10012f61

void Unwind_10012f61(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x42c));
  return;
}



// Function: Unwind@10012f6c at 10012f6c

void Unwind_10012f6c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x434) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x434) = *(uint *)(unaff_EBP + -0x434) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x438));
    return;
  }
  return;
}



// Function: Unwind@10012f8e at 10012f8e

void Unwind_10012f8e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10012f97. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x430) + -0x48));
  return;
}



// Function: Unwind@10012f9d at 10012f9d

void Unwind_10012f9d(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x430) + -0x4c));
  return;
}



// Function: Unwind@10012fab at 10012fab

void Unwind_10012fab(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10012fb1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@10012fe0 at 10012fe0

void Unwind_10012fe0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x10012ff3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x60));
    return;
  }
  return;
}



// Function: Unwind@10012ffa at 10012ffa

void Unwind_10012ffa(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10013006 at 10013006

void Unwind_10013006(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013009. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001300f at 1001300f

void Unwind_1001300f(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001301a at 1001301a

void Unwind_1001301a(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0xb0));
  return;
}



// Function: Unwind@10013025 at 10013025

void Unwind_10013025(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001303e at 1001303e

void Unwind_1001303e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013044. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@1001304a at 1001304a

void Unwind_1001304a(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@10013055 at 10013055

void Unwind_10013055(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013058. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013080 at 10013080

void Unwind_10013080(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x100) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x100) = *(uint *)(unaff_EBP + -0x100) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x1001309c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x15c));
    return;
  }
  return;
}



// Function: Unwind@100130a3 at 100130a3

void Unwind_100130a3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100130a9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@100130af at 100130af

void Unwind_100130af(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100130b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x104));
  return;
}



// Function: Unwind@100130bb at 100130bb

void Unwind_100130bb(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x1a8));
  return;
}



// Function: Unwind@100130c6 at 100130c6

void Unwind_100130c6(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0x1ac));
  return;
}



// Function: Unwind@100130d1 at 100130d1

void Unwind_100130d1(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@100130dc at 100130dc

void Unwind_100130dc(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@100130e7 at 100130e7

void Unwind_100130e7(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x100) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x100) = *(uint *)(unaff_EBP + -0x100) & 0xfffffffb;
                    /* WARNING: Could not recover jumptable at 0x10013100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x58));
    return;
  }
  return;
}



// Function: Unwind@10013107 at 10013107

void Unwind_10013107(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001310d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xa0));
  return;
}



// Function: Unwind@10013113 at 10013113

void Unwind_10013113(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013119. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x104));
  return;
}



// Function: Unwind@1001311f at 1001311f

void Unwind_1001311f(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1001312a at 1001312a

void Unwind_1001312a(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@10013135 at 10013135

void Unwind_10013135(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10013140 at 10013140

void Unwind_10013140(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1001314b at 1001314b

void Unwind_1001314b(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10013156 at 10013156

void Unwind_10013156(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x100) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x100) = *(uint *)(unaff_EBP + -0x100) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x108));
    return;
  }
  return;
}



// Function: Unwind@10013178 at 10013178

void Unwind_10013178(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013181. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x104) + -0x48));
  return;
}



// Function: Unwind@10013187 at 10013187

void Unwind_10013187(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x104) + -0x4c));
  return;
}



// Function: Unwind@10013195 at 10013195

void Unwind_10013195(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001319b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x114));
  return;
}



// Function: Unwind@100131d0 at 100131d0

void Unwind_100131d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 0x20) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xffffffdf;
                    /* WARNING: Could not recover jumptable at 0x100131ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xe0));
    return;
  }
  return;
}



// Function: Unwind@100131f3 at 100131f3

void Unwind_100131f3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100131f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x128));
  return;
}



// Function: Unwind@100131ff at 100131ff

void Unwind_100131ff(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013205. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1001320b at 1001320b

void Unwind_1001320b(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -300));
  return;
}



// Function: Unwind@10013216 at 10013216

void Unwind_10013216(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@10013221 at 10013221

void Unwind_10013221(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001322c at 1001322c

void Unwind_1001322c(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10013234 at 10013234

void Unwind_10013234(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 0x40) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xffffffbf;
                    /* WARNING: Could not recover jumptable at 0x10013250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x178));
    return;
  }
  return;
}



// Function: Unwind@10013257 at 10013257

void Unwind_10013257(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001325d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x1c0));
  return;
}



// Function: Unwind@10013263 at 10013263

void Unwind_10013263(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013269. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1001326f at 1001326f

void Unwind_1001326f(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1001327a at 1001327a

void Unwind_1001327a(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@10013285 at 10013285

void Unwind_10013285(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffffe;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}



// Function: Unwind@100132a4 at 100132a4

void Unwind_100132a4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffffd;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
    return;
  }
  return;
}



// Function: Unwind@100132c3 at 100132c3

void Unwind_100132c3(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100132cb at 100132cb

void Unwind_100132cb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffffb;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
    return;
  }
  return;
}



// Function: Unwind@100132ea at 100132ea

void Unwind_100132ea(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 8) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffff7;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}



// Function: Unwind@10013309 at 10013309

void Unwind_10013309(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013311 at 10013311

void Unwind_10013311(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10013319 at 10013319

void Unwind_10013319(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 0x10) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xffffffef;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x98));
    return;
  }
  return;
}



// Function: Unwind@1001333b at 1001333b

void Unwind_1001333b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013344. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x8c) + -0x48));
  return;
}



// Function: Unwind@1001334a at 1001334a

void Unwind_1001334a(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x8c) + -0x4c));
  return;
}



// Function: Unwind@10013358 at 10013358

void Unwind_10013358(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001335e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x94));
  return;
}



// Function: Unwind@10013364 at 10013364

void Unwind_10013364(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001336d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x94) + -0x48));
  return;
}



// Function: Unwind@10013373 at 10013373

void Unwind_10013373(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x94) + -0x4c));
  return;
}



// Function: Unwind@10013381 at 10013381

void Unwind_10013381(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013387. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100133c0 at 100133c0

void Unwind_100133c0(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100133c8 at 100133c8

void Unwind_100133c8(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@100133d3 at 100133d3

void Unwind_100133d3(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x14);
  return;
}



// Function: Unwind@100133de at 100133de

void Unwind_100133de(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@100133e9 at 100133e9

void Unwind_100133e9(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x50));
  return;
}



// Function: Unwind@100133f4 at 100133f4

void Unwind_100133f4(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@100133ff at 100133ff

void Unwind_100133ff(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x88));
  return;
}



// Function: Unwind@1001340d at 1001340d

void Unwind_1001340d(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa4));
  return;
}



// Function: Unwind@1001341b at 1001341b

void Unwind_1001341b(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc0));
  return;
}



// Function: Unwind@10013429 at 10013429

void Unwind_10013429(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xdc));
  return;
}



// Function: Unwind@10013437 at 10013437

void Unwind_10013437(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf8));
  return;
}



// Function: Unwind@10013445 at 10013445

void Unwind_10013445(void)

{
  int unaff_EBP;
  
  FUN_10008630((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x130));
  return;
}



// Function: Unwind@10013490 at 10013490

void Unwind_10013490(void)

{
  FUN_100011b0();
  return;
}



// Function: Unwind@100134a1 at 100134a1

void Unwind_100134a1(void)

{
  FUN_100011b0();
  return;
}



// Function: Unwind@100134d0 at 100134d0

void Unwind_100134d0(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100134d8 at 100134d8

void Unwind_100134d8(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013510 at 10013510

void Unwind_10013510(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013540 at 10013540

void Unwind_10013540(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10013548 at 10013548

void Unwind_10013548(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013550 at 10013550

void Unwind_10013550(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}



// Function: Unwind@10013569 at 10013569

void Unwind_10013569(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100135a0 at 100135a0

void Unwind_100135a0(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100135e0 at 100135e0

void Unwind_100135e0(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100135e8 at 100135e8

void Unwind_100135e8(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100135f0 at 100135f0

void Unwind_100135f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}



// Function: Unwind@10013609 at 10013609

void Unwind_10013609(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013640 at 10013640

void Unwind_10013640(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10013648 at 10013648

void Unwind_10013648(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013680 at 10013680

void Unwind_10013680(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100136c0 at 100136c0

void Unwind_100136c0(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@100136c8 at 100136c8

void Unwind_100136c8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x80) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x80) = *(uint *)(unaff_EBP + -0x80) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x100136de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x16c));
    return;
  }
  return;
}



// Function: Unwind@100136e5 at 100136e5

void Unwind_100136e5(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100136eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x1b4));
  return;
}



// Function: Unwind@100136f1 at 100136f1

void Unwind_100136f1(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100136f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100136fa at 100136fa

void Unwind_100136fa(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@10013705 at 10013705

void Unwind_10013705(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0x1bc));
  return;
}



// Function: Unwind@10013710 at 10013710

void Unwind_10013710(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10013718 at 10013718

void Unwind_10013718(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x80) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x80) = *(uint *)(unaff_EBP + -0x80) & 0xfffffffb;
                    /* WARNING: Could not recover jumptable at 0x1001372e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xd4));
    return;
  }
  return;
}



// Function: Unwind@10013735 at 10013735

void Unwind_10013735(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001373b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@10013741 at 10013741

void Unwind_10013741(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013744. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001374a at 1001374a

void Unwind_1001374a(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x120));
  return;
}



// Function: Unwind@10013755 at 10013755

void Unwind_10013755(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@10013760 at 10013760

void Unwind_10013760(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10013768 at 10013768

void Unwind_10013768(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x80) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x80) = *(uint *)(unaff_EBP + -0x80) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x8c));
    return;
  }
  return;
}



// Function: Unwind@10013784 at 10013784

void Unwind_10013784(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001378a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x48) + -0x48));
  return;
}



// Function: Unwind@10013790 at 10013790

void Unwind_10013790(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x48) + -0x4c));
  return;
}



// Function: Unwind@1001379b at 1001379b

void Unwind_1001379b(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100137a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@100137a7 at 100137a7

void Unwind_100137a7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100137ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x48) + -0x48));
  return;
}



// Function: Unwind@100137b3 at 100137b3

void Unwind_100137b3(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x48) + -0x4c));
  return;
}



// Function: Unwind@100137be at 100137be

void Unwind_100137be(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100137c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x84));
  return;
}



// Function: Unwind@10013800 at 10013800

void Unwind_10013800(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x28) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x28) = *(uint *)(unaff_EBP + -0x28) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x10013813. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x7c));
    return;
  }
  return;
}



// Function: Unwind@1001381a at 1001381a

void Unwind_1001381a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@10013826 at 10013826

void Unwind_10013826(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013829. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001382f at 1001382f

void Unwind_1001382f(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -200));
  return;
}



// Function: Unwind@1001383a at 1001383a

void Unwind_1001383a(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0xcc));
  return;
}



// Function: Unwind@10013845 at 10013845

void Unwind_10013845(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x28) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x28) = *(uint *)(unaff_EBP + -0x28) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x30));
    return;
  }
  return;
}



// Function: Unwind@1001385e at 1001385e

void Unwind_1001385e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013864. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x2c) + -0x48));
  return;
}



// Function: Unwind@1001386a at 1001386a

void Unwind_1001386a(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x2c) + -0x4c));
  return;
}



// Function: Unwind@10013875 at 10013875

void Unwind_10013875(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013878. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100138b0 at 100138b0

void Unwind_100138b0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x58) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x58) = *(uint *)(unaff_EBP + -0x58) & 0xfffffffd;
                    /* WARNING: Could not recover jumptable at 0x100138c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xa8));
    return;
  }
  return;
}



// Function: Unwind@100138cd at 100138cd

void Unwind_100138cd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100138d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@100138d9 at 100138d9

void Unwind_100138d9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100138dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100138e2 at 100138e2

void Unwind_100138e2(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xf4));
  return;
}



// Function: Unwind@100138ed at 100138ed

void Unwind_100138ed(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0xf8));
  return;
}



// Function: Unwind@100138f8 at 100138f8

void Unwind_100138f8(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10013900 at 10013900

void Unwind_10013900(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@10013908 at 10013908

void Unwind_10013908(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x58) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x58) = *(uint *)(unaff_EBP + -0x58) & 0xfffffffe;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x5c));
    return;
  }
  return;
}



// Function: Unwind@10013921 at 10013921

void Unwind_10013921(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013927. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x54) + -0x48));
  return;
}



// Function: Unwind@1001392d at 1001392d

void Unwind_1001392d(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x54) + -0x4c));
  return;
}



// Function: Unwind@10013938 at 10013938

void Unwind_10013938(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001393b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10013970 at 10013970

void Unwind_10013970(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 8) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffff7;
                    /* WARNING: Could not recover jumptable at 0x1001398c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0xdc));
    return;
  }
  return;
}



// Function: Unwind@10013993 at 10013993

void Unwind_10013993(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013999. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x124));
  return;
}



// Function: Unwind@1001399f at 1001399f

void Unwind_1001399f(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100139a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x88));
  return;
}



// Function: Unwind@100139ab at 100139ab

void Unwind_100139ab(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x128));
  return;
}



// Function: Unwind@100139b6 at 100139b6

void Unwind_100139b6(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@100139c1 at 100139c1

void Unwind_100139c1(void)

{
  int unaff_EBP;
  
  FUN_100010a0((undefined4 *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@100139cc at 100139cc

void Unwind_100139cc(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100139d4 at 100139d4

void Unwind_100139d4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 0x10) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xffffffef;
                    /* WARNING: Could not recover jumptable at 0x100139f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>::
    ~basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_>
              ((basic_ios<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x174));
    return;
  }
  return;
}



// Function: Unwind@100139f7 at 100139f7

void Unwind_100139f7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100139fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (unaff_EBP + -0x1bc));
  return;
}



// Function: Unwind@10013a03 at 10013a03

void Unwind_10013a03(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013a09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10013a0f at 10013a0f

void Unwind_10013a0f(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (unaff_EBP + -0x1c0));
  return;
}



// Function: Unwind@10013a1a at 10013a1a

void Unwind_10013a1a(void)

{
  int unaff_EBP;
  
  FUN_1000c190((int *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@10013a25 at 10013a25

void Unwind_10013a25(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffffe;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}



// Function: Unwind@10013a44 at 10013a44

void Unwind_10013a44(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffffd;
    FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
    return;
  }
  return;
}



// Function: Unwind@10013a63 at 10013a63

void Unwind_10013a63(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10013a6b at 10013a6b

void Unwind_10013a6b(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10013a73 at 10013a73

void Unwind_10013a73(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10013a7b at 10013a7b

void Unwind_10013a7b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x84) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x84) = *(uint *)(unaff_EBP + -0x84) & 0xfffffffb;
    FUN_10001520(*(undefined4 **)(unaff_EBP + -0x94));
    return;
  }
  return;
}



// Function: Unwind@10013a9d at 10013a9d

void Unwind_10013a9d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013aa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x88) + -0x48));
  return;
}



// Function: Unwind@10013aac at 10013aac

void Unwind_10013aac(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x88) + -0x4c));
  return;
}



// Function: Unwind@10013aba at 10013aba

void Unwind_10013aba(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x90));
  return;
}



// Function: Unwind@10013ac6 at 10013ac6

void Unwind_10013ac6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013acf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_>
            ((basic_ostream<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
             (*(int *)(unaff_EBP + -0x90) + -0x48));
  return;
}



// Function: Unwind@10013ad5 at 10013ad5

void Unwind_10013ad5(void)

{
  int unaff_EBP;
  
  FUN_1000b360((basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> *)
               (*(int *)(unaff_EBP + -0x90) + -0x4c));
  return;
}



// Function: Unwind@10013ae3 at 10013ae3

void Unwind_10013ae3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10013ae9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>::
  ~basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_>
            (*(basic_streambuf<unsigned_short,struct_std::char_traits<unsigned_short>_> **)
              (unaff_EBP + -0x88));
  return;
}



// Function: Unwind@10013b20 at 10013b20

void Unwind_10013b20(void)

{
  int unaff_EBP;
  
  FUN_10001080(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10013b28 at 10013b28

void Unwind_10013b28(void)

{
  int unaff_EBP;
  
  FUN_100011c0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10013b33 at 10013b33

void Unwind_10013b33(void)

{
  int unaff_EBP;
  
  FUN_100013e0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10013b3e at 10013b3e

void Unwind_10013b3e(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@10013b49 at 10013b49

void Unwind_10013b49(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@10013b54 at 10013b54

void Unwind_10013b54(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x68));
  return;
}



// Function: Unwind@10013b5f at 10013b5f

void Unwind_10013b5f(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x84));
  return;
}



// Function: Unwind@10013b6d at 10013b6d

void Unwind_10013b6d(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa0));
  return;
}



// Function: Unwind@10013b7b at 10013b7b

void Unwind_10013b7b(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xbc));
  return;
}



// Function: Unwind@10013b89 at 10013b89

void Unwind_10013b89(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@10013b97 at 10013b97

void Unwind_10013b97(void)

{
  int unaff_EBP;
  
  FUN_10001520((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf4));
  return;
}



// Function: Unwind@10013ba5 at 10013ba5

void Unwind_10013ba5(void)

{
  int unaff_EBP;
  
  FUN_10008630((_Container_base0 *)(*(int *)(unaff_EBP + -0x10) + 0x128));
  return;
}



// Function: FUN_10013bd0 at 10013bd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013bd0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10012b74;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10003060(0x1001d2dc);
  _DAT_1001d2dc = ATL::CComModule::vftable;
  _DAT_1001d2ac = &DAT_1001d2dc;
  local_8 = 0xffffffff;
  _atexit(FUN_10013f80);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013f80 at 10013f80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013f80(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012ba4;
  local_10 = ExceptionList;
  uVar1 = DAT_1001d274 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_1001d2dc = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  if (DAT_1001d2e0 != 0) {
    if (DAT_1001d2e8 != 0) {
      FUN_10002f70(0x1001d2e0);
      DAT_1001d2e8 = 0;
    }
    if (DAT_1001d304 != (int *)0x0) {
      (**(code **)(*DAT_1001d304 + 8))(DAT_1001d304,uVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1001d2ec);
    DAT_1001d2e0 = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014050 at 10014050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014050(void)

{
  if (7 < DAT_1001ce18) {
    operator_delete(DAT_1001ce04);
  }
  DAT_1001ce18 = 7;
  _DAT_1001ce14 = 0;
  DAT_1001ce04 = (void *)((uint)DAT_1001ce04 & 0xffff0000);
  return;
}



// Function: FUN_10014090 at 10014090

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014090(void)

{
  if (7 < DAT_1001ce34) {
    operator_delete(DAT_1001ce20);
  }
  DAT_1001ce34 = 7;
  _DAT_1001ce30 = 0;
  DAT_1001ce20 = (void *)((uint)DAT_1001ce20 & 0xffff0000);
  return;
}



// Function: FUN_100140d0 at 100140d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100140d0(void)

{
  if (7 < DAT_1001ce50) {
    operator_delete(DAT_1001ce3c);
  }
  DAT_1001ce50 = 7;
  _DAT_1001ce4c = 0;
  DAT_1001ce3c = (void *)((uint)DAT_1001ce3c & 0xffff0000);
  return;
}



// Function: FUN_10014110 at 10014110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014110(void)

{
  if (7 < DAT_1001ce6c) {
    operator_delete(DAT_1001ce58);
  }
  DAT_1001ce6c = 7;
  _DAT_1001ce68 = 0;
  DAT_1001ce58 = (void *)((uint)DAT_1001ce58 & 0xffff0000);
  return;
}



// Function: FUN_10014150 at 10014150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014150(void)

{
  if (7 < DAT_1001d01c) {
    operator_delete(DAT_1001d008);
  }
  DAT_1001d01c = 7;
  _DAT_1001d018 = 0;
  DAT_1001d008 = (void *)((uint)DAT_1001d008 & 0xffff0000);
  return;
}



// Function: FUN_10014190 at 10014190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014190(void)

{
  if (7 < DAT_1001d038) {
    operator_delete(DAT_1001d024);
  }
  DAT_1001d038 = 7;
  _DAT_1001d034 = 0;
  DAT_1001d024 = (void *)((uint)DAT_1001d024 & 0xffff0000);
  return;
}



// Function: FUN_100141d0 at 100141d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100141d0(void)

{
  if (7 < DAT_1001d054) {
    operator_delete(DAT_1001d040);
  }
  DAT_1001d054 = 7;
  _DAT_1001d050 = 0;
  DAT_1001d040 = (void *)((uint)DAT_1001d040 & 0xffff0000);
  return;
}



// Function: FUN_10014210 at 10014210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014210(void)

{
  if (7 < DAT_1001d070) {
    operator_delete(DAT_1001d05c);
  }
  DAT_1001d070 = 7;
  _DAT_1001d06c = 0;
  DAT_1001d05c = (void *)((uint)DAT_1001d05c & 0xffff0000);
  return;
}



// Function: FUN_10014250 at 10014250

void FUN_10014250(void)

{
  if (7 < DAT_1001d08c) {
    operator_delete(DAT_1001d078);
  }
  DAT_1001d08c = 7;
  DAT_1001d088 = 0;
  DAT_1001d078 = (void *)((uint)DAT_1001d078 & 0xffff0000);
  return;
}



// Function: FUN_10014290 at 10014290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014290(void)

{
  if (7 < DAT_1001d0a8) {
    operator_delete(DAT_1001d094);
  }
  DAT_1001d0a8 = 7;
  _DAT_1001d0a4 = 0;
  DAT_1001d094 = (void *)((uint)DAT_1001d094 & 0xffff0000);
  return;
}



// Function: FUN_100142d0 at 100142d0

void FUN_100142d0(void)

{
  if (7 < DAT_1001d0c4) {
    operator_delete(DAT_1001d0b0);
  }
  DAT_1001d0c4 = 7;
  DAT_1001d0c0 = 0;
  DAT_1001d0b0 = (void *)((uint)DAT_1001d0b0 & 0xffff0000);
  return;
}



// Function: FUN_10014310 at 10014310

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014310(void)

{
  if (7 < DAT_1001d0e0) {
    operator_delete(DAT_1001d0cc);
  }
  DAT_1001d0e0 = 7;
  _DAT_1001d0dc = 0;
  DAT_1001d0cc = (void *)((uint)DAT_1001d0cc & 0xffff0000);
  return;
}



// Function: FUN_10014350 at 10014350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014350(void)

{
  if (7 < DAT_1001d0fc) {
    operator_delete(DAT_1001d0e8);
  }
  DAT_1001d0fc = 7;
  _DAT_1001d0f8 = 0;
  DAT_1001d0e8 = (void *)((uint)DAT_1001d0e8 & 0xffff0000);
  return;
}



// Function: FUN_10014390 at 10014390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014390(void)

{
  if (7 < DAT_1001d118) {
    operator_delete(DAT_1001d104);
  }
  DAT_1001d118 = 7;
  _DAT_1001d114 = 0;
  DAT_1001d104 = (void *)((uint)DAT_1001d104 & 0xffff0000);
  return;
}



// Function: FUN_100143d0 at 100143d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100143d0(void)

{
  if (7 < DAT_1001d134) {
    operator_delete(DAT_1001d120);
  }
  DAT_1001d134 = 7;
  _DAT_1001d130 = 0;
  DAT_1001d120 = (void *)((uint)DAT_1001d120 & 0xffff0000);
  return;
}



// Function: FUN_10014410 at 10014410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014410(void)

{
  if (7 < DAT_1001d150) {
    operator_delete(DAT_1001d13c);
  }
  DAT_1001d150 = 7;
  _DAT_1001d14c = 0;
  DAT_1001d13c = (void *)((uint)DAT_1001d13c & 0xffff0000);
  return;
}



// Function: FUN_10014450 at 10014450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014450(void)

{
  if (7 < DAT_1001d16c) {
    operator_delete(DAT_1001d158);
  }
  DAT_1001d16c = 7;
  _DAT_1001d168 = 0;
  DAT_1001d158 = (void *)((uint)DAT_1001d158 & 0xffff0000);
  return;
}



// Function: FUN_10014490 at 10014490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014490(void)

{
  if (7 < DAT_1001d188) {
    operator_delete(DAT_1001d174);
  }
  DAT_1001d188 = 7;
  _DAT_1001d184 = 0;
  DAT_1001d174 = (void *)((uint)DAT_1001d174 & 0xffff0000);
  return;
}



// Function: FUN_100144d0 at 100144d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100144d0(void)

{
  if (7 < DAT_1001d1a4) {
    operator_delete(DAT_1001d190);
  }
  DAT_1001d1a4 = 7;
  _DAT_1001d1a0 = 0;
  DAT_1001d190 = (void *)((uint)DAT_1001d190 & 0xffff0000);
  return;
}



// Function: FUN_10014510 at 10014510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014510(void)

{
  if (7 < DAT_1001d1c0) {
    operator_delete(DAT_1001d1ac);
  }
  DAT_1001d1c0 = 7;
  _DAT_1001d1bc = 0;
  DAT_1001d1ac = (void *)((uint)DAT_1001d1ac & 0xffff0000);
  return;
}



// Function: FUN_10014550 at 10014550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014550(void)

{
  if (7 < DAT_1001d1dc) {
    operator_delete(DAT_1001d1c8);
  }
  DAT_1001d1dc = 7;
  _DAT_1001d1d8 = 0;
  DAT_1001d1c8 = (void *)((uint)DAT_1001d1c8 & 0xffff0000);
  return;
}



// Function: FUN_10014590 at 10014590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10014590(void)

{
  if (7 < DAT_1001d1f8) {
    operator_delete(DAT_1001d1e4);
  }
  DAT_1001d1f8 = 7;
  _DAT_1001d1f4 = 0;
  DAT_1001d1e4 = (void *)((uint)DAT_1001d1e4 & 0xffff0000);
  return;
}



// Function: FUN_100145d0 at 100145d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100145d0(void)

{
  if (7 < DAT_1001d214) {
    operator_delete(DAT_1001d200);
  }
  DAT_1001d214 = 7;
  _DAT_1001d210 = 0;
  DAT_1001d200 = (void *)((uint)DAT_1001d200 & 0xffff0000);
  return;
}



// Function: FUN_10014605 at 10014605

void FUN_10014605(void)

{
  FUN_10010a55((int *)&DAT_1001d32c);
  return;
}



// Function: FUN_1001460f at 1001460f

void FUN_1001460f(void)

{
  FUN_10010b37(0x1001d354);
  return;
}



// Function: FUN_10014619 at 10014619

void FUN_10014619(void)

{
  ATL::CWin32Heap::~CWin32Heap((CWin32Heap *)&DAT_1001d38c);
  return;
}



// Function: FUN_10014623 at 10014623

void FUN_10014623(void)

{
  PTR_PTR_1001d240 = (undefined *)&PTR_Allocate_10016734;
  return;
}



