/*
 * Decompiled from: Dictionary.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001020 at 10001020

void __fastcall FUN_10001020(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10010c68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10001000(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001080 at 10001080

undefined4 * __thiscall FUN_10001080(void *this,uint param_1)

{
  if ((param_1 & 2) == 0) {
    FUN_10001020((undefined4 *)this);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    _eh_vector_destructor_iterator_(this,0xc,*(int *)((int)this + -4),FUN_10001020);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)this + -4));
    }
    this = (void *)((int)this + -4);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001100 at 10001100

undefined4 FUN_10001100(undefined4 param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  while( true ) {
    if (bVar1) {
      return 1;
    }
    iVar2 = FUN_10001150((int *)PTR_DAT_10018004,param_2);
    if (iVar2 != 0) break;
    bVar1 = true;
  }
  return 0;
}



// Function: FUN_10001150 at 10001150

undefined4 __cdecl FUN_10001150(int *param_1,int *param_2)

{
  undefined4 local_48;
  
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    local_48 = 1;
  }
  else {
    local_48 = 0;
  }
  return local_48;
}



// Function: FUN_100011f0 at 100011f0

undefined4 FUN_100011f0(void)

{
  return 0;
}



// Function: FUN_10001210 at 10001210

void FUN_10001210(undefined4 param_1)

{
  FUN_100065d0((int *)&DAT_100184f0,0x65,param_1,(int *)0x0);
  return;
}



// Function: FUN_10001240 at 10001240

undefined4 FUN_10001240(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10011732;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)FUN_100102ae(0x28);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10001b30(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_100012e6();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100012e0 at 100012e0

undefined * Catch_100012e0(void)

{
  return &DAT_100012ef;
}



// Function: FUN_100012e6 at 100012e6

undefined4 FUN_100012e6(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_100060f0(*(void **)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 8));
    FUN_10005300();
    uVar1 = FUN_10006850(*(int *)(unaff_EBP + -0x18) + 4);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_100046a0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_100067d0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    FUN_10005340();
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x5c);
      if (*(int *)(unaff_EBP + -0x60) == 0) {
        *(undefined4 *)(unaff_EBP + -0x6c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x60) + 0x14))(1);
        *(undefined4 *)(unaff_EBP + -0x6c) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100013c0 at 100013c0

undefined4 FUN_100013c0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_48;
  
  if (param_1 == 0) {
    local_48 = FUN_10004250(0,param_2,param_3);
  }
  else {
    local_48 = FUN_100040d0(param_1,param_2,param_3);
  }
  return local_48;
}



// Function: FUN_10001410 at 10001410

void FUN_10001410(void)

{
  return;
}



// Function: FUN_10001430 at 10001430

undefined4 FUN_10001430(void)

{
  return 0;
}



// Function: FUN_10001450 at 10001450

void __thiscall FUN_10001450(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  puVar2 = (undefined4 *)FUN_10003670(param_1);
  bVar1 = FUN_100054b0(this,puVar2);
  if (bVar1) {
    FUN_10003690((undefined4 *)this);
  }
  else {
    puVar4 = &DAT_100132e4;
    uVar3 = FUN_10003670(param_1);
    AtlComQIPtrAssign(this,uVar3,puVar4);
  }
  return;
}



// Function: FUN_100014a0 at 100014a0

uint __cdecl FUN_100014a0(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (-param_2 - 1U < param_3) {
    uVar1 = FUN_100089c0(0x216);
  }
  else {
    *param_1 = param_2 + param_3;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_100014e0 at 100014e0

int __cdecl FUN_100014e0(int param_1,uint param_2)

{
  uint uVar1;
  int local_8;
  
  uVar1 = FUN_100014a0(&local_8,param_1,param_2);
  if ((int)uVar1 < 0) {
    FUN_10003fa0(uVar1);
  }
  return local_8;
}



// Function: FUN_10001520 at 10001520

uint __cdecl FUN_10001520(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  lVar2 = __allmul(param_2,(int)param_2 >> 0x1f,param_3,(int)param_3 >> 0x1f);
  local_8 = (uint)((ulonglong)lVar2 >> 0x20);
  if ((((int)local_8 < 1) && ((local_c = (uint)lVar2, lVar2 < 0 || (local_c < 0x80000000)))) &&
     ((local_8 < 0x80000000 || ((-2 < (int)local_8 && (0x7fffffff < local_c)))))) {
    *param_1 = local_c;
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_100089c0(0x216);
  }
  return uVar1;
}



// Function: FUN_10001590 at 10001590

void FUN_10001590(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_100132d4,param_2);
  return;
}



// Function: FUN_100015c0 at 100015c0

void * __cdecl FUN_100015c0(uint param_1)

{
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x5555555 < param_1 || (local_8 = operator_new(param_1 * 0x30), local_8 == (void *)0x0)))) {
    std::_Xbad_alloc();
  }
  return local_8;
}



// Function: FUN_10001610 at 10001610

undefined4 __cdecl FUN_10001610(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10001630 at 10001630

undefined4 __cdecl FUN_10001630(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10001650 at 10001650

undefined4 __cdecl FUN_10001650(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10001670 at 10001670

void __thiscall FUN_10001670(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10001850(param_2);
  FUN_10001740(this,param_1,uVar1);
  return;
}



// Function: FUN_100016b0 at 100016b0

void FUN_100016b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010ca1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_100034d0(4,param_1);
  local_8 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_10001850(param_2);
    *puVar1 = *puVar2;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001740 at 10001740

void __cdecl FUN_10001740(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10001850(param_3);
  FUN_100016b0(param_2,uVar1);
  return;
}



// Function: FUN_10001770 at 10001770

void FUN_10001770(void)

{
  FUN_100017c0();
  return;
}



// Function: FUN_100017a0 at 100017a0

void FUN_100017a0(void)

{
  return;
}



// Function: FUN_100017c0 at 100017c0

void FUN_100017c0(void)

{
  FUN_100017a0();
  return;
}



// Function: FUN_100017e0 at 100017e0

void __thiscall FUN_100017e0(void *this,void *param_1)

{
  FUN_10001830(this,param_1);
  return;
}



// Function: FUN_10001810 at 10001810

void FUN_10001810(void *param_1)

{
  FUN_10003a00(param_1,0);
  return;
}



// Function: FUN_10001830 at 10001830

void __cdecl FUN_10001830(undefined4 param_1,void *param_2)

{
  FUN_10001810(param_2);
  return;
}



// Function: FUN_10001850 at 10001850

undefined4 __cdecl FUN_10001850(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10001870 at 10001870

void __cdecl FUN_10001870(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined1 local_5;
  
  puVar1 = (undefined1 *)FUN_10001610(param_1);
  local_5 = *puVar1;
  puVar1 = (undefined1 *)FUN_10001610(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined1 *)FUN_10001610(&local_5);
  *param_2 = *puVar1;
  return;
}



// Function: FUN_100018c0 at 100018c0

int __fastcall FUN_100018c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010cc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100022b0(param_1);
  local_8 = 0;
  FUN_10005240();
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001920 at 10001920

undefined4 * __fastcall FUN_10001920(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001940 at 10001940

undefined4 * __thiscall FUN_10001940(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010d06;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002700(this);
  FUN_10001c10((undefined4 *)((int)this + 4));
  local_8 = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CDict>::vftable;
  FUN_100019e0((void *)((int)this + 0xc),param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*DAT_100184c8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100019e0 at 100019e0

undefined4 * __thiscall FUN_100019e0(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010d38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002570((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CDict>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CDict>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001a60 at 10001a60

undefined4 * __thiscall FUN_10001a60(void *this,undefined4 param_1,char param_2)

{
  int iVar1;
  
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  if (param_2 != '\0') {
    iVar1 = FUN_10005950((undefined4 *)this);
    if (iVar1 < 0) {
      FUN_10003fa0(iVar1);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10001ab0 at 10001ab0

undefined4 * __fastcall FUN_10001ab0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010d68;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002570((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CDict>::vftable;
  param_1[1] = ATL::CComObject<class_CDict>::vftable;
  (**(code **)(*DAT_100184c8 + 4))(uVar1);
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
  puStack_c = &LAB_10010d98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100023e0(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001ba0 at 10001ba0

undefined4 * __fastcall FUN_10001ba0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010dd3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100024f0(param_1);
  local_8 = 0;
  FUN_10002360(param_1 + 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001c10 at 10001c10

undefined4 * __fastcall FUN_10001c10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010df8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100024f0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001c70 at 10001c70

undefined4 * __fastcall FUN_10001c70(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010e28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001eb0(param_1);
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
  puStack_c = &LAB_10010e58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001ed0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001d30 at 10001d30

void * __thiscall FUN_10001d30(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010e88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001ef0(this,*param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10001d90 at 10001d90

undefined4 * __fastcall FUN_10001d90(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010eb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001f30(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001df0 at 10001df0

undefined4 * __fastcall FUN_10001df0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010ee8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001f50(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001e50 at 10001e50

undefined4 * __fastcall FUN_10001e50(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010f18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001f70(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001eb0 at 10001eb0

undefined4 * __fastcall FUN_10001eb0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001ed0 at 10001ed0

undefined4 * __fastcall FUN_10001ed0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001ef0 at 10001ef0

int * __thiscall FUN_10001ef0(void *this,int param_1)

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



// Function: FUN_10001f30 at 10001f30

undefined4 * __fastcall FUN_10001f30(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001f50 at 10001f50

undefined4 * __fastcall FUN_10001f50(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001f70 at 10001f70

undefined4 * __fastcall FUN_10001f70(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10001f90 at 10001f90

undefined4 __fastcall FUN_10001f90(undefined4 param_1)

{
  FUN_10002680(param_1);
  return param_1;
}



// Function: FUN_10001fb0 at 10001fb0

undefined4 * __fastcall FUN_10001fb0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010f48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100020a0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002010 at 10002010

undefined4 * __fastcall FUN_10002010(undefined4 *param_1)

{
  undefined4 uVar1;
  
  FUN_10002190(param_1);
  uVar1 = FUN_10006980();
  *param_1 = uVar1;
  return param_1;
}



// Function: FUN_10002040 at 10002040

undefined4 * __fastcall FUN_10002040(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010f78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002010(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100020a0 at 100020a0

undefined4 * __fastcall FUN_100020a0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010fa8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002040(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002100 at 10002100

void * __thiscall FUN_10002100(void *this,undefined4 param_1)

{
  FUN_10002160(this,param_1);
  return this;
}



// Function: FUN_10002130 at 10002130

void * __thiscall FUN_10002130(void *this,undefined4 param_1)

{
  FUN_10002100(this,param_1);
  return this;
}



// Function: FUN_10002160 at 10002160

undefined4 * __thiscall FUN_10002160(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_100067b0();
  return (undefined4 *)this;
}



// Function: FUN_10002190 at 10002190

undefined4 * __fastcall FUN_10002190(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}



// Function: FUN_100021c0 at 100021c0

undefined4 __fastcall FUN_100021c0(undefined4 param_1)

{
  FUN_100021e0(param_1);
  return param_1;
}



// Function: FUN_100021e0 at 100021e0

undefined4 __fastcall FUN_100021e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10002200 at 10002200

undefined4 __fastcall FUN_10002200(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10002220 at 10002220

undefined4 * FUN_10002220(void)

{
  undefined1 local_56 [66];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10010fd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002200(local_56);
  FUN_10001fb0(local_14);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10002290 at 10002290

undefined4 * __thiscall FUN_10002290(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_100022b0 at 100022b0

int __fastcall FUN_100022b0(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001100b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002720(param_1 + 4);
  local_8 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_100184c8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  uVar1 = FUN_100050f0((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)uVar1 < 0) {
    DAT_100184de = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002360 at 10002360

void * __fastcall FUN_10002360(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011038;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002510(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100023c0 at 100023c0

undefined4 * __fastcall FUN_100023c0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100023e0 at 100023e0

undefined4 * __fastcall FUN_100023e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001106b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100026a0(param_1);
  FUN_10001ba0(param_1 + 1);
  *param_1 = ATL::CComClassFactory::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002450 at 10002450

void * __fastcall FUN_10002450(void *param_1)

{
  memset(param_1,0,0x18);
  return param_1;
}



// Function: FUN_10002480 at 10002480

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10002480(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011098;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100018c0((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_100184e8 = param_1;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100024f0 at 100024f0

undefined4 * __fastcall FUN_100024f0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10002510 at 10002510

void * __fastcall FUN_10002510(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100110c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002450(param_1);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002570 at 10002570

int __fastcall FUN_10002570(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011106;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001ba0((undefined4 *)(param_1 + 8));
  local_8 = 0;
  FUN_100026e0(param_1);
  FUN_10001f90(param_1 + 4);
  FUN_100025f0((void *)(param_1 + 0x28),(undefined4 *)&DAT_10013420);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100025f0 at 100025f0

undefined4 * __thiscall FUN_100025f0(void *this,undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001113b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CDictionary::vftable;
  FUN_10002220();
  *(undefined4 *)((int)this + 0xc) = *param_1;
  *(undefined4 *)((int)this + 0x10) = param_1[1];
  *(undefined4 *)((int)this + 0x14) = param_1[2];
  *(undefined4 *)((int)this + 0x18) = param_1[3];
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10002680 at 10002680

undefined4 __fastcall FUN_10002680(undefined4 param_1)

{
  FUN_100026c0(param_1);
  return param_1;
}



// Function: FUN_100026a0 at 100026a0

undefined4 __fastcall FUN_100026a0(undefined4 param_1)

{
  FUN_10002700(param_1);
  return param_1;
}



// Function: FUN_100026c0 at 100026c0

undefined4 __fastcall FUN_100026c0(undefined4 param_1)

{
  FUN_10002700(param_1);
  return param_1;
}



// Function: FUN_100026e0 at 100026e0

undefined4 __fastcall FUN_100026e0(undefined4 param_1)

{
  FUN_10002700(param_1);
  return param_1;
}



// Function: FUN_10002700 at 10002700

undefined4 __fastcall FUN_10002700(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10002720 at 10002720

int __fastcall FUN_10002720(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001116b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002450((void *)(param_1 + 0xc));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002780 at 10002780

undefined4 * __thiscall FUN_10002780(void *this,undefined4 param_1,undefined4 param_2,char param_3)

{
  *(undefined ***)this = _com_error::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = 0;
  if ((*(int *)((int)this + 8) != 0) && (param_3 != '\0')) {
    (**(code **)(**(int **)((int)this + 8) + 4))(*(undefined4 *)((int)this + 8));
  }
  return (undefined4 *)this;
}



// Function: FUN_100027f0 at 100027f0

undefined4 * __fastcall FUN_100027f0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011198;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100023c0(param_1);
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002860 at 10002860

void __fastcall FUN_10002860(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100111c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003100(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100028c0 at 100028c0

void __fastcall FUN_100028c0(int *param_1)

{
  void *pvVar1;
  
  while (*param_1 != 0) {
    pvVar1 = (void *)*param_1;
    *param_1 = *(int *)*param_1;
    FUN_10004710(pvVar1);
  }
  return;
}



// Function: FUN_10002900 at 10002900

void __fastcall FUN_10002900(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10011206;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CDict>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  FUN_100046c0();
  (**(code **)(*DAT_100184c8 + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_100029a0((int)(param_1 + 3));
  local_8 = 0xffffffff;
  FUN_10002bb0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_100029a0 at 100029a0

void __fastcall FUN_100029a0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011238;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003350(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002a00 at 10002a00

void __fastcall FUN_10002a00(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_10006290(param_1);
  }
  return;
}



// Function: FUN_10002a30 at 10002a30

void __fastcall FUN_10002a30(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011268;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CDict>::vftable;
  param_1[1] = ATL::CComObject<class_CDict>::vftable;
  local_8 = 0;
  param_1[2] = 0xc0000001;
  FUN_100046f0();
  (**(code **)(*DAT_100184c8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10003350((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002ac0 at 10002ac0

void __fastcall FUN_10002ac0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011298;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  FUN_100046f0();
  local_8 = 0xffffffff;
  FUN_100031c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002b40 at 10002b40

void __fastcall FUN_10002b40(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100112d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003160((LPCRITICAL_SECTION)(param_1 + 4));
  local_8 = 0xffffffff;
  FUN_100032a0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002bb0 at 10002bb0

void FUN_10002bb0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100112f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100032a0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002c10 at 10002c10

void __fastcall FUN_10002c10(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011328;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002df0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002c70 at 10002c70

void __fastcall FUN_10002c70(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011358;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e20(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002cd0 at 10002cd0

void __fastcall FUN_10002cd0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011388;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e50(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002d30 at 10002d30

void __fastcall FUN_10002d30(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100113b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002e80(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002d90 at 10002d90

void __fastcall FUN_10002d90(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100113e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002eb0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002df0 at 10002df0

void __fastcall FUN_10002df0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002e20 at 10002e20

void __fastcall FUN_10002e20(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002e50 at 10002e50

void __fastcall FUN_10002e50(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002e80 at 10002e80

void __fastcall FUN_10002e80(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002eb0 at 10002eb0

void __fastcall FUN_10002eb0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10002ee0 at 10002ee0

void __fastcall FUN_10002ee0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011418;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10007180(param_1);
  local_8 = 0xffffffff;
  FUN_10002fd0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002f40 at 10002f40

void __fastcall FUN_10002f40(undefined4 *param_1)

{
  FUN_10006ba0((void *)*param_1);
  return;
}



// Function: FUN_10002f70 at 10002f70

void __fastcall FUN_10002f70(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011448;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002f40(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002fd0 at 10002fd0

void __fastcall FUN_10002fd0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011478;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002f70(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003030 at 10003030

void __fastcall FUN_10003030(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100114a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002ee0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003090 at 10003090

void __fastcall FUN_10003090(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100114e3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003330(param_1 + 0x10);
  local_8 = 0xffffffff;
  FUN_10003330(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003100 at 10003100

void __fastcall FUN_10003100(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001150b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10006130(param_1);
  local_8 = 0xffffffff;
  FUN_10003420();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003160 at 10003160

void __fastcall FUN_10003160(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011538;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100032c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100031c0 at 100031c0

void __fastcall FUN_100031c0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001156b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  FUN_10002b40((int)(param_1 + 1));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003220 at 10003220

void FUN_10003220(void)

{
  return;
}



// Function: FUN_10003240 at 10003240

void __fastcall FUN_10003240(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011598;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  FUN_10002860((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100032a0 at 100032a0

void FUN_100032a0(void)

{
  return;
}



// Function: FUN_100032c0 at 100032c0

void __fastcall FUN_100032c0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100115c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    FUN_100061c0(param_1);
  }
  local_8 = 0xffffffff;
  FUN_10003220();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003330 at 10003330

void __fastcall FUN_10003330(undefined4 param_1)

{
  FUN_100040b0(param_1);
  return;
}



// Function: FUN_10003350 at 10003350

void __fastcall FUN_10003350(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011606;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100033c0(param_1 + 0x28);
  local_8 = 0xffffffff;
  FUN_10002b40(param_1 + 8);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100033c0 at 100033c0

void __fastcall FUN_100033c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001163b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003030((int *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003420 at 10003420

void FUN_10003420(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001166b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10003220();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003480 at 10003480

void __fastcall FUN_10003480(undefined4 *param_1)

{
  *param_1 = _com_error::vftable;
  if (param_1[2] != 0) {
    (**(code **)(*(int *)param_1[2] + 8))(param_1[2]);
  }
  if (param_1[3] != 0) {
    LocalFree((HLOCAL)param_1[3]);
  }
  return;
}



// Function: FUN_100034d0 at 100034d0

undefined4 __cdecl FUN_100034d0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_100034f0 at 100034f0

void FUN_100034f0(void)

{
  return;
}



// Function: FUN_10003500 at 10003500

bool __fastcall FUN_10003500(int *param_1)

{
  return *param_1 == 0;
}



// Function: FUN_10003530 at 10003530

bool __thiscall FUN_10003530(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_10003570 at 10003570

bool __thiscall FUN_10003570(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == *param_1;
}



// Function: FUN_100035b0 at 100035b0

void __fastcall FUN_100035b0(int *param_1)

{
  FUN_10003500(param_1);
  return;
}



// Function: FUN_100035d0 at 100035d0

bool __thiscall FUN_100035d0(void *this,int *param_1)

{
  bool local_4c;
  
  local_4c = FUN_10003570(this,param_1);
  local_4c = !local_4c;
  return local_4c;
}



// Function: FUN_10003610 at 10003610

bool __fastcall FUN_10003610(int *param_1)

{
  char cVar1;
  
  cVar1 = FUN_100035b0(param_1);
  return cVar1 == '\0';
}



// Function: FUN_10003650 at 10003650

undefined4 __fastcall FUN_10003650(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003670 at 10003670

undefined4 __fastcall FUN_10003670(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003690 at 10003690

undefined4 __fastcall FUN_10003690(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100036b0 at 100036b0

undefined4 __fastcall FUN_100036b0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100036d0 at 100036d0

undefined4 __fastcall FUN_100036d0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100036f0 at 100036f0

undefined4 __fastcall FUN_100036f0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003710 at 10003710

undefined4 __fastcall FUN_10003710(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003730 at 10003730

undefined4 __fastcall FUN_10003730(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003750 at 10003750

undefined4 __fastcall FUN_10003750(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10003770 at 10003770

int * __thiscall FUN_10003770(void *this,int *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  FUN_100037a0((int *)this);
  *param_1 = iVar1;
  return param_1;
}



// Function: FUN_100037a0 at 100037a0

int * __fastcall FUN_100037a0(int *param_1)

{
  FUN_100037c0(param_1);
  return param_1;
}



// Function: FUN_100037c0 at 100037c0

int * __fastcall FUN_100037c0(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_10006d10(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_10006fc0(*param_1);
    pcVar1 = (char *)FUN_10006d10(*piVar2);
    if (*pcVar1 == '\0') {
      puVar3 = (undefined4 *)FUN_10006fc0(*param_1);
      iVar4 = FUN_10006f10(*puVar3);
      *param_1 = iVar4;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_10006fa0(*param_1);
        iVar4 = *piVar2;
        pcVar1 = (char *)FUN_10006d10(iVar4);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_10006fc0(iVar4), *param_1 != *piVar2)) break;
        *param_1 = iVar4;
      }
      *param_1 = iVar4;
    }
  }
  return param_1;
}



// Function: FUN_10003880 at 10003880

undefined4 __fastcall FUN_10003880(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100038a0 at 100038a0

undefined4 __fastcall FUN_100038a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100038c0 at 100038c0

undefined4 __fastcall FUN_100038c0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100038e0 at 100038e0

undefined4 __fastcall FUN_100038e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003900 at 10003900

undefined4 __fastcall FUN_10003900(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003920 at 10003920

undefined4 __fastcall FUN_10003920(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10003940 at 10003940

undefined4 * __thiscall FUN_10003940(void *this,uint param_1)

{
  FUN_10002900((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003980 at 10003980

undefined4 * __thiscall FUN_10003980(void *this,uint param_1)

{
  FUN_10002a30((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100039c0 at 100039c0

undefined4 * __thiscall FUN_100039c0(void *this,uint param_1)

{
  FUN_10002ac0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003a00 at 10003a00

void * __thiscall FUN_10003a00(void *this,uint param_1)

{
  FUN_10003090((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10003a40 at 10003a40

undefined4 * __thiscall FUN_10003a40(void *this,uint param_1)

{
  FUN_100031c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003a80 at 10003a80

undefined4 * __thiscall FUN_10003a80(void *this,uint param_1)

{
  FUN_10003240((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003ac0 at 10003ac0

undefined4 * __thiscall FUN_10003ac0(void *this,uint param_1)

{
  FUN_10003480((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: CDict_Add at 10003b00

void CDict_Add(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011698;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 0xc))(param_1 + 0x24,param_2,param_3);
  FUN_10003c0f();
  return;
}



// Function: Catch@10003b5c at 10003b5c

undefined * Catch_10003b5c(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x71,
                       "CDict::Add",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_10003c26;
}



// Function: Catch@10003ba5 at 10003ba5

undefined * Catch_10003ba5(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x71,
                       "CDict::Add",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10003c03;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_10003c18;
}



// Function: FUN_10003c0f at 10003c0f

undefined4 FUN_10003c0f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10003c50 at 10003c50

void FUN_10003c50(int *param_1)

{
  undefined *puVar1;
  
  puVar1 = FUN_10004730();
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",puVar1);
  return;
}



// Function: FUN_10003c80 at 10003c80

void FUN_10003c80(int param_1)

{
  FUN_100052e0((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10003ca0 at 10003ca0

void FUN_10003ca0(int param_1)

{
  FUN_10005a10((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10003cbd at 10003cbd

void FUN_10003cbd(int param_1)

{
  FUN_10003ca0(param_1 + -4);
  return;
}



// Function: FUN_10003cd0 at 10003cd0

void FUN_10003cd0(int param_1)

{
  FUN_100052c0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10003ced at 10003ced

void FUN_10003ced(int param_1)

{
  FUN_10003cd0(param_1 + -4);
  return;
}



// Function: FUN_10003d00 at 10003d00

int FUN_10003d00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_100052c0((LONG *)(param_1 + 4));
  if (iVar1 == 2) {
    (**(code **)(*DAT_100184c8 + 4))();
  }
  return iVar1;
}



// Function: FUN_10003d40 at 10003d40

void __thiscall FUN_10003d40(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 local_4c;
  
  if (this == (void *)0x0) {
    local_4c = 0;
  }
  else {
    local_4c = (int)this + 4;
  }
  AtlModuleAddTermFunc(local_4c,param_1,param_2);
  return;
}



// Function: FUN_10003d80 at 10003d80

int __thiscall FUN_10003d80(void *this,int param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  int iVar3;
  
  sVar1 = FUN_100014e0(param_1,8);
  puVar2 = (undefined4 *)FUN_10003de0(sVar1);
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    *puVar2 = *this;
    *(undefined4 **)this = puVar2;
    iVar3 = FUN_100048d0((int)puVar2);
  }
  return iVar3;
}



// Function: FUN_10003de0 at 10003de0

void __cdecl FUN_10003de0(size_t param_1)

{
  malloc(param_1);
  return;
}



// Function: FUN_10003e00 at 10003e00

LPWSTR FUN_10003e00(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

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



// Function: FUN_10003e60 at 10003e60

undefined4 __cdecl FUN_10003e60(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_10003fa0(0x80004005);
    break;
  case 0xc:
    FUN_10003fa0(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_10003fa0(0x80070057);
  }
  return param_1;
}



// Function: FUN_10003f20 at 10003f20

int FUN_10003f20(LPWSTR param_1)

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



// Function: FUN_10003fa0 at 10003fa0

void FUN_10003fa0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 local_4c;
  undefined1 local_48 [68];
  
  puVar1 = FUN_10002290(local_48,param_1);
  local_4c = *puVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_4c,(ThrowInfo *)&DAT_1001675c);
}



// Function: FUN_10003ff0 at 10003ff0

void __thiscall FUN_10003ff0(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(int *)this = param_1;
  }
  return;
}



// Function: FUN_10004030 at 10004030

void FUN_10004030(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10001080(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_100040b0 at 100040b0

void __fastcall FUN_100040b0(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_100040d0 at 100040d0

undefined4 FUN_100040d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100116d2;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    this = (void *)FUN_100102ae(0x50);
    local_8._0_1_ = 1;
    if (this != (void *)0x0) {
      FUN_10001940(this,param_1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar1 = FUN_10004176();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@10004170 at 10004170

undefined * Catch_10004170(void)

{
  return &DAT_1000417f;
}



// Function: FUN_10004176 at 10004176

undefined4 FUN_10004176(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_10006110();
    FUN_10005300();
    iVar1 = FUN_10006810(*(int *)(unaff_EBP + -0x18));
    *(int *)(unaff_EBP + -0x14) = iVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_10004670();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_100067d0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    FUN_10005340();
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar2 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x5c);
      if (*(int *)(unaff_EBP + -0x60) == 0) {
        *(undefined4 *)(unaff_EBP + -0x6c) = 0;
      }
      else {
        uVar2 = (**(code **)(**(int **)(unaff_EBP + -0x60) + 0xc))(1);
        *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10004250 at 10004250

undefined4 FUN_10004250(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10011702;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)FUN_100102ae(0x44);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10001ab0(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_100042f6();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100042f0 at 100042f0

undefined * Catch_100042f0(void)

{
  return &DAT_100042ff;
}



// Function: FUN_100042f6 at 100042f6

undefined4 FUN_100042f6(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_10006110();
    FUN_10005320(*(int *)(unaff_EBP + -0x18));
    uVar1 = FUN_10006850(*(int *)(unaff_EBP + -0x18) + 8);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_100046a0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_100067d0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    FUN_10005360(*(int *)(unaff_EBP + -0x18));
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar1 = (**(code **)**(undefined4 **)(unaff_EBP + -0x18))
                        (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 0xc),
                         *(undefined4 *)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x5c);
      if (*(int *)(unaff_EBP + -0x60) == 0) {
        *(undefined4 *)(unaff_EBP + -0x6c) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x60) + 0x10))(1);
        *(undefined4 *)(unaff_EBP + -0x6c) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100043d0 at 100043d0

undefined4 FUN_100043d0(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 == 0) || (iVar1 = FUN_10005250(param_3), iVar1 != 0)) {
      local_8 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
    }
    else {
      local_8 = 0x80040110;
    }
  }
  return local_8;
}



// Function: FUN_10004440 at 10004440

void FUN_10004440(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10004460 at 10004460

void FUN_10004460(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10004480 at 10004480

undefined4 __fastcall FUN_10004480(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_100044b0 at 100044b0

undefined4 __fastcall FUN_100044b0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_100044e0 at 100044e0

undefined4 __thiscall FUN_100044e0(void *this,undefined4 param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_c = FUN_10004b40(this,param_1);
  }
  return local_c;
}



// Function: CDict_Exists at 10004520

void CDict_Exists(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011758;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x14))(param_1 + 0x24,param_2,param_3);
  FUN_10004635();
  return;
}



// Function: Catch@1000457c at 1000457c

undefined * Catch_1000457c(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x88,
                       "CDict::Exists",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_1000464c;
}



// Function: Catch@100045c8 at 100045c8

undefined * Catch_100045c8(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x88,
                       "CDict::Exists",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10004629;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_1000463e;
}



// Function: FUN_10004635 at 10004635

undefined4 FUN_10004635(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10004670 at 10004670

void FUN_10004670(void)

{
  FUN_100046a0();
  FUN_100046a0();
  return;
}



// Function: FUN_100046a0 at 100046a0

undefined4 FUN_100046a0(void)

{
  return 0;
}



// Function: FUN_100046c0 at 100046c0

void FUN_100046c0(void)

{
  FUN_100046f0();
  FUN_100046f0();
  return;
}



// Function: FUN_100046f0 at 100046f0

void FUN_100046f0(void)

{
  return;
}



// Function: FUN_10004710 at 10004710

void __cdecl FUN_10004710(void *param_1)

{
  free(param_1);
  return;
}



// Function: FUN_10004730 at 10004730

undefined * FUN_10004730(void)

{
  return &DAT_1001350c;
}



// Function: FUN_10004750 at 10004750

int __thiscall FUN_10004750(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 local_24 [2];
  int *local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011788;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_3 = 0;
  local_18 = 0;
  local_14 = this;
  if (*(int *)((int)this + 0x2c) != 0) {
    for (local_1c = *(int **)((int)this + 0x2c); *local_1c != 0; local_1c = local_1c + 9) {
      if ((local_1c[2] != 0) && (iVar1 = FUN_10001150(param_1,(int *)*local_1c), iVar1 != 0)) {
        if (local_1c[4] == 0) {
          FUN_10001a60(local_24,&DAT_1001857c,'\0');
          local_8 = 0;
          local_18 = FUN_10005950(local_24);
          if (local_18 < 0) {
            local_8 = 0xffffffff;
            FUN_10002a00(local_24);
            break;
          }
          if (local_1c[4] == 0) {
            local_18 = (*(code *)local_1c[2])(local_1c[3],&DAT_10013270,local_1c + 4);
          }
          local_8 = 0xffffffff;
          FUN_10002a00(local_24);
        }
        if (local_1c[4] != 0) {
          local_18 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_2,param_3);
        }
        break;
      }
    }
  }
  if ((*param_3 == 0) && (local_18 == 0)) {
    local_18 = AtlComModuleGetClassObject(&DAT_1001856c,param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_100048d0 at 100048d0

int __fastcall FUN_100048d0(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_100048f0 at 100048f0

int __thiscall FUN_100048f0(void *this,undefined4 *param_1)

{
  int local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_c = CoCreateInstance((IID *)&DAT_10014728,(LPUNKNOWN)0x0,1,(IID *)&DAT_10013400,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_c) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_c;
}



// Function: FUN_10004970 at 10004970

void FUN_10004970(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_100049a0(&PTR_DAT_100181d4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100049a0 at 100049a0

int __thiscall
FUN_100049a0(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  size_t sVar1;
  size_t _Size;
  void *_Buf1;
  int iVar2;
  void *_Buf2;
  int local_14;
  int local_c;
  
  local_c = FUN_100044e0(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = -0x7fffbffb;
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      sVar1 = FUN_10007e40((wchar_t *)*param_2);
      local_14 = *(int *)((int)this + 0x18);
      do {
        do {
          local_14 = local_14 + -1;
          if (local_14 < 0) goto LAB_10004aa4;
        } while (sVar1 != *(size_t *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc));
        _Size = *(int *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc) << 1;
        _Buf2 = (void *)*param_2;
        _Buf1 = (void *)FUN_100036f0((undefined4 *)(local_14 * 0xc + *(int *)((int)this + 0x14)));
        iVar2 = memcmp(_Buf1,_Buf2,_Size);
      } while (iVar2 != 0);
      *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + local_14 * 0xc);
      local_c = 0;
    }
LAB_10004aa4:
    if (local_c < 0) {
      local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                          (*(undefined4 *)((int)this + 0xc),param_2,param_3,param_5);
    }
  }
  return local_c;
}



// Function: FUN_10004ae0 at 10004ae0

undefined4 __fastcall FUN_10004ae0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10004b00 at 10004b00

undefined4 __fastcall FUN_10004b00(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10004b20 at 10004b20

undefined * FUN_10004b20(void)

{
  return &DAT_10013440;
}



// Function: FUN_10004b40 at 10004b40

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10004b40(void *this,undefined4 param_1)

{
  char cVar1;
  int iVar2;
  HMODULE hModule;
  size_t sVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  CHAR *lpFilename;
  DWORD nSize;
  uint local_1c0;
  LPWSTR local_1b0;
  LPWSTR local_1a8;
  LPWSTR local_1a4;
  int local_154;
  int local_150;
  int local_14c;
  LPWSTR local_148;
  int local_144;
  char *local_140;
  UINT local_138;
  uint local_134;
  DWORD local_130;
  CHAR local_12c [260];
  int *local_28;
  int local_24;
  undefined4 local_20 [2];
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100117e4;
  local_10 = ExceptionList;
  local_1c0 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  local_14 = local_1c0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10001a60(local_20,(int)DAT_100184c8 + 0x10,'\0');
    local_8 = 0;
    local_24 = FUN_10005950(local_20);
    if (local_24 < 0) {
      local_8 = 0xffffffff;
      FUN_10002a00(local_20);
    }
    else {
      local_24 = -0x7fffbffb;
      if (local_18[3] == 0) {
        local_28 = (int *)0x0;
        iVar2 = FUN_10001150((int *)&DAT_100184cc,(int *)local_18[1]);
        if (((iVar2 == 0) || (*(short *)(local_18 + 2) != -1)) ||
           (*(short *)((int)local_18 + 10) != -1)) {
          local_24 = Ordinal_162(local_18[1],*(undefined2 *)(local_18 + 2),
                                 *(undefined2 *)((int)local_18 + 10),param_1,&local_28);
        }
        else {
          nSize = 0x104;
          lpFilename = local_12c;
          hModule = (HMODULE)FUN_10004b00(0x10018534);
          local_130 = GetModuleFileNameA(hModule,lpFilename,nSize);
          if ((local_130 != 0) && (local_130 != 0x104)) {
            local_138 = FUN_100067f0();
            FUN_10001920(&local_144);
            local_8._0_1_ = 1;
            local_140 = local_12c;
            if (local_140 == (char *)0x0) {
              local_1a4 = (LPWSTR)0x0;
            }
            else {
              sVar3 = strlen(local_140);
              local_134 = sVar3 + 1;
              uVar4 = FUN_10001520(&local_134,local_134,2);
              if ((int)uVar4 < 0) {
                local_1a8 = (LPWSTR)0x0;
              }
              else {
                if (((int)local_134 < 0x401) && (cVar1 = FUN_10006890(local_134), cVar1 != '\0')) {
                  local_1b0 = (LPWSTR)&local_1c0;
                }
                else {
                  local_1b0 = (LPWSTR)FUN_10003d80(&local_144,local_134);
                }
                local_1a8 = FUN_10003e00(local_1b0,local_140,local_134 >> 1,local_138);
              }
              local_1a4 = local_1a8;
            }
            local_148 = local_1a4;
            if (local_1a4 == (LPWSTR)0x0) {
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_100028c0(&local_144);
              local_8 = 0xffffffff;
              FUN_10002a00(local_20);
              goto LAB_10004f6a;
            }
            local_24 = Ordinal_161(local_1a4,&local_28);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100028c0(&local_144);
          }
        }
        if (-1 < local_24) {
          FUN_10001d90(&local_14c);
          local_8._0_1_ = 2;
          uVar5 = FUN_100038c0(&local_14c);
          local_24 = (**(code **)(*local_28 + 0x18))(local_28,*local_18,uVar5);
          if (-1 < local_24) {
            FUN_10001d30(&local_150,&local_14c);
            local_8._0_1_ = 3;
            FUN_10001cd0(&local_154);
            local_8 = CONCAT31(local_8._1_3_,4);
            uVar5 = FUN_100038a0(&local_154);
            puVar6 = (undefined4 *)FUN_10003730(&local_14c);
            iVar2 = FUN_10001590(puVar6,uVar5);
            if (-1 < iVar2) {
              FUN_10001450(&local_150,&local_154);
            }
            uVar5 = FUN_10004480(&local_150);
            local_18[3] = uVar5;
            FUN_10003d40(DAT_100184c8,FUN_10004030,local_18);
            local_8._0_1_ = 3;
            FUN_10002c70(&local_154);
            local_8._0_1_ = 2;
            FUN_10002cd0(&local_150);
          }
          (**(code **)(*local_28 + 8))(local_28);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10002cd0(&local_14c);
        }
      }
      else {
        local_24 = 0;
      }
      if ((local_18[3] != 0) && (local_18[5] == 0)) {
        local_24 = FUN_10005710((int *)local_18[3]);
      }
      local_8 = 0xffffffff;
      FUN_10002a00(local_20);
    }
  }
LAB_10004f6a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004f90 at 10004f90

undefined4 __thiscall FUN_10004f90(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      local_c = FUN_10004b40(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(undefined4 *)((int)this + 0xc));
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_10005010 at 10005010

void FUN_10005010(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_10005040(&PTR_DAT_100181d4,param_2,param_3,param_4);
  return;
}



// Function: FUN_10005040 at 10005040

undefined4 __thiscall FUN_10005040(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_10004f90(this,param_2,param_3);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10005080 at 10005080

undefined4 FUN_10005080(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_100050b0 at 100050b0

void FUN_100050b0(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_100050d0 at 100050d0

void FUN_100050d0(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_100050f0 at 100050f0

uint __fastcall FUN_100050f0(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 local_c;
  
  local_c = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    local_c = FUN_100089c0(DVar2);
  }
  return local_c;
}



// Function: FUN_10005130 at 10005130

undefined4 FUN_10005130(void)

{
  return 0;
}



// Function: FUN_10005150 at 10005150

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_10005150(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_10;
  int *local_c;
  
  if (param_3 != (undefined4 *)0x0) {
    _DAT_100184cc = *param_3;
    _DAT_100184d0 = param_3[1];
    _DAT_100184d4 = param_3[2];
    _DAT_100184d8 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_c = *(int **)((int)this + 0x2c); *local_c != 0; local_c = local_c + 9) {
      (*(code *)local_c[8])(1);
    }
  }
  for (local_10 = DAT_10018574; local_10 < DAT_10018578; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x1c))(1);
    }
  }
  return 0;
}



// Function: FUN_10005210 at 10005210

uint __fastcall FUN_10005210(LPCRITICAL_SECTION param_1)

{
  uint uVar1;
  
  uVar1 = FUN_100050f0(param_1);
  if (-1 < (int)uVar1) {
    *(undefined1 *)&param_1[1].DebugInfo = 1;
  }
  return uVar1;
}



// Function: FUN_10005240 at 10005240

void FUN_10005240(void)

{
  return;
}



// Function: FUN_10005250 at 10005250

undefined4 FUN_10005250(int *param_1)

{
  undefined4 local_48;
  
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0xc0)) && (param_1[3] == 0x46000000)
     ) {
    local_48 = 1;
  }
  else {
    local_48 = 0;
  }
  return local_48;
}



// Function: FUN_100052c0 at 100052c0

void __fastcall FUN_100052c0(LONG *param_1)

{
  FUN_100050b0(param_1);
  return;
}



// Function: FUN_100052e0 at 100052e0

void __fastcall FUN_100052e0(LONG *param_1)

{
  FUN_100050d0(param_1);
  return;
}



// Function: FUN_10005300 at 10005300

void FUN_10005300(void)

{
  return;
}



// Function: FUN_10005320 at 10005320

void __fastcall FUN_10005320(int param_1)

{
  FUN_100052c0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10005340 at 10005340

void FUN_10005340(void)

{
  return;
}



// Function: FUN_10005360 at 10005360

void __fastcall FUN_10005360(int param_1)

{
  FUN_100053b0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10005380 at 10005380

undefined4 FUN_10005380(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = AtlInternalQueryInterface(param_1,param_2,param_3,param_4);
  return uVar1;
}



// Function: FUN_100053b0 at 100053b0

void __fastcall FUN_100053b0(LONG *param_1)

{
  FUN_10004440(param_1);
  return;
}



// Function: FUN_100053d0 at 100053d0

void __fastcall FUN_100053d0(LONG *param_1)

{
  FUN_10004460(param_1);
  return;
}



// Function: FUN_100053f0 at 100053f0

void FUN_100053f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10005440(&PTR_DAT_100181d4,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10005440 at 10005440

undefined4 __thiscall
FUN_10005440(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 local_c;
  
  local_c = FUN_100044e0(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
                        (*(undefined4 *)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,
                         param_8,param_9);
  }
  return local_c;
}



// Function: FUN_100054b0 at 100054b0

bool __thiscall FUN_100054b0(void *this,undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011820;
  local_10 = ExceptionList;
  uVar2 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*this == 0) && (param_1 == (undefined4 *)0x0)) {
    bVar1 = true;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*this == 0) || (param_1 == (undefined4 *)0x0)) {
      bVar1 = false;
    }
    else {
      local_14 = (undefined4 *)this;
      FUN_10001e50(&local_18);
      local_8 = 0;
      FUN_10001e50(&local_1c);
      local_8._0_1_ = 1;
      uVar3 = FUN_10003900(&local_18);
      (*(code *)**(undefined4 **)*local_14)(*local_14,&DAT_10013270,uVar3,uVar2);
      uVar3 = FUN_10003900(&local_1c);
      (**(code **)*param_1)(param_1,&DAT_10013270,uVar3);
      iVar4 = FUN_100036d0(&local_1c);
      bVar1 = FUN_10003530(&local_18,iVar4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10002d90(&local_1c);
      local_8 = 0xffffffff;
      FUN_10002d90(&local_18);
    }
  }
  ExceptionList = local_10;
  return bVar1;
}



// Function: CDict_Keys at 100055a0

void CDict_Keys(int param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011848;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x38))(param_1 + 0x24,param_2);
  FUN_100056b1();
  return;
}



// Function: Catch@100055f8 at 100055f8

undefined * Catch_100055f8(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0xb6,
                       "CDict::Keys",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_100056c8;
}



// Function: Catch@10005644 at 10005644

undefined * Catch_10005644(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0xb6,
                       "CDict::Keys",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100056a5;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_100056ba;
}



// Function: FUN_100056b1 at 100056b1

undefined4 FUN_100056b1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100056f0 at 100056f0

void __fastcall FUN_100056f0(undefined4 *param_1)

{
  Ordinal_7(*param_1);
  return;
}



// Function: FUN_10005710 at 10005710

undefined4 FUN_10005710(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint *local_7c;
  undefined4 local_2c;
  uint *local_28;
  int local_24;
  uint *local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001188a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = (**(code **)(*param_1 + 0xc))(param_1,&local_18,DAT_10018498 ^ (uint)&stack0xfffffffc);
  if (-1 < local_1c) {
    local_20 = (uint *)0x0;
    *(uint *)(local_14 + 0x18) = (uint)*(ushort *)(local_18 + 0x2c);
    *(undefined4 *)(local_14 + 0x14) = 0;
    if (*(int *)(local_14 + 0x18) != 0) {
      uVar3 = *(uint *)(local_14 + 0x18);
      uVar4 = -(uint)((int)((ulonglong)uVar3 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar3 * 0xc);
      local_7c = (uint *)FUN_100102dc(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
      local_8 = 0;
      if (local_7c == (uint *)0x0) {
        local_7c = (uint *)0x0;
      }
      else {
        *local_7c = uVar3;
        _eh_vector_constructor_iterator_(local_7c + 1,0xc,uVar3,FUN_100027f0,FUN_10001020);
        local_7c = local_7c + 1;
      }
      local_8 = 0xffffffff;
      local_20 = local_7c;
      if (local_7c == (uint *)0x0) {
        (**(code **)(*param_1 + 0x4c))(param_1,local_18);
        ExceptionList = local_10;
        return 0x8007000e;
      }
    }
    for (local_24 = 0; local_24 < *(int *)(local_14 + 0x18); local_24 = local_24 + 1) {
      iVar1 = (**(code **)(*param_1 + 0x14))(param_1,local_24,&local_28);
      if (-1 < iVar1) {
        FUN_100023c0(&local_2c);
        local_8 = 1;
        uVar7 = 0;
        uVar6 = 0;
        uVar5 = 0;
        uVar2 = FUN_10003920(&local_2c);
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,*local_28,uVar2,uVar5,uVar6,uVar7);
        if (-1 < iVar1) {
          iVar1 = FUN_100044b0(&local_2c);
          FUN_10003ff0(local_20 + local_24 * 3,iVar1);
          uVar2 = FUN_100036f0(local_20 + local_24 * 3);
          uVar3 = Ordinal_7(uVar2);
          local_20[local_24 * 3 + 1] = uVar3;
          local_20[local_24 * 3 + 2] = *local_28;
        }
        (**(code **)(*param_1 + 0x50))(param_1,local_28);
        local_8 = 0xffffffff;
        FUN_10001000(&local_2c);
      }
    }
    *(uint **)(local_14 + 0x14) = local_20;
    (**(code **)(*param_1 + 0x4c))(param_1,local_18);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_10005950 at 10005950

int __fastcall FUN_10005950(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100059b0((LPCRITICAL_SECTION)*param_1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 1) = 1;
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_10005990 at 10005990

void __fastcall FUN_10005990(int param_1)

{
  FUN_100050b0((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100059b0 at 100059b0

undefined4 __fastcall FUN_100059b0(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  return 0;
}



// Function: FUN_100059d0 at 100059d0

undefined4 FUN_100059d0(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_100184c8 + 8))();
  }
  else {
    (**(code **)(*DAT_100184c8 + 4))();
  }
  return 0;
}



// Function: FUN_10005a10 at 10005a10

void __fastcall FUN_10005a10(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 4))(*param_1);
  return;
}



// Function: FUN_10005a40 at 10005a40

void __thiscall FUN_10005a40(void *this,undefined4 param_1,undefined4 param_2)

{
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  (**(code **)**this)(*this,param_1,param_2);
  return;
}



// Function: FUN_10005a70 at 10005a70

void __fastcall FUN_10005a70(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 8))(*param_1);
  return;
}



// Function: FUN_10005aa0 at 10005aa0

undefined4 FUN_10005aa0(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    local_8 = 0x80004003;
  }
  else {
    *param_3 = 0;
    local_8 = 0;
    iVar1 = FUN_10005250(param_2);
    if (iVar1 == 0) {
      local_8 = FUN_10006ce0(param_1 + 3,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return local_8;
}



// Function: FUN_10005b10 at 10005b10

void FUN_10005b10(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10005a40((void *)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_10005b35 at 10005b35

void FUN_10005b35(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10005b10(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10005b40 at 10005b40

void FUN_10005b40(void *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10006ce0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10005b62 at 10005b62

void FUN_10005b62(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10005b40((void *)(param_1 + -4),param_2,param_3);
  return;
}



// Function: FUN_10005b70 at 10005b70

void FUN_10005b70(void *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10006cb0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10005ba0 at 10005ba0

int FUN_10005ba0(int param_1,void *param_2)

{
  int local_c;
  
  local_c = FUN_10005c00(&DAT_1001856c,param_1,param_2);
  if ((-1 < local_c) && (DAT_100184e0 != (code *)0x0)) {
    local_c = (*DAT_100184e0)(DAT_10018538);
  }
  return local_c;
}



// Function: FUN_10005c00 at 10005c00

void __thiscall FUN_10005c00(void *this,int param_1,void *param_2)

{
  FUN_100082a0((int)this,param_1,param_2);
  return;
}



// Function: FUN_10005c30 at 10005c30

int __thiscall FUN_10005c30(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined4 uVar3;
  int *local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_10008a00(param_2,(void *)*local_10), CONCAT31(extraout_var,bVar1) != 0)) {
        local_c = (*(code *)local_10[1])(1);
        if (local_c < 0) break;
        uVar3 = 1;
        uVar2 = (*(code *)local_10[7])(1);
        local_c = AtlRegisterClassCategoriesHelper(*local_10,uVar2,uVar3);
        if (local_c < 0) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_10005ba0(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_10005cf0 at 10005cf0

int FUN_10005cf0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100053d0(param_1 + 1);
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return iVar1;
}



// Function: FUN_10005d50 at 10005d50

void FUN_10005d50(int param_1)

{
  FUN_10005a70((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10005d6d at 10005d6d

void FUN_10005d6d(int param_1)

{
  FUN_10005d50(param_1 + -4);
  return;
}



// Function: FUN_10005d80 at 10005d80

int FUN_10005d80(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100053b0(param_1 + 2);
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return iVar1;
}



// Function: FUN_10005dd6 at 10005dd6

void FUN_10005dd6(int param_1)

{
  FUN_10005d80((int *)(param_1 + -4));
  return;
}



// Function: FUN_10005de0 at 10005de0

int FUN_10005de0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100053b0(param_1 + 1);
  if (iVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (iVar1 == 1) {
    (**(code **)(*DAT_100184c8 + 8))();
  }
  return iVar1;
}



// Function: CDict_Remove at 10005e50

void CDict_Remove(int param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100118b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x1c))(param_1 + 0x24,param_2);
  FUN_10005f61();
  return;
}



// Function: Catch@10005ea8 at 10005ea8

undefined * Catch_10005ea8(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0xa0,
                       "CDict::Remove",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_10005f78;
}



// Function: Catch@10005ef4 at 10005ef4

undefined * Catch_10005ef4(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0xa0,
                       "CDict::Remove",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10005f55;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_10005f6a;
}



// Function: FUN_10005f61 at 10005f61

undefined4 FUN_10005f61(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: CDict_RemoveAll at 10005fa0

void CDict_RemoveAll(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100118e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x20))(param_1 + 0x24);
  FUN_100060ad();
  return;
}



// Function: Catch@10005ff4 at 10005ff4

undefined * Catch_10005ff4(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0xab,
                       "CDict::RemoveAll",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_100060c4;
}



// Function: Catch@10006040 at 10006040

undefined * Catch_10006040(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0xab,
                       "CDict::RemoveAll",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100060a1;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_100060b6;
}



// Function: FUN_100060ad at 100060ad

undefined4 FUN_100060ad(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100060f0 at 100060f0

void __thiscall FUN_100060f0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}



// Function: FUN_10006110 at 10006110

void FUN_10006110(void)

{
  return;
}



// Function: FUN_10006130 at 10006130

void __fastcall FUN_10006130(int param_1)

{
  undefined4 local_4c;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_1 == 0) {
        local_4c = 0;
      }
      else {
        local_4c = param_1 + 4;
      }
      AtlCallTermFunc(local_4c);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(undefined4 *)(param_1 + 0x28));
    }
    FUN_100061c0((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_100061c0 at 100061c0

undefined4 __fastcall FUN_100061c0(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return 0;
}



// Function: FUN_100061e0 at 100061e0

void __fastcall FUN_100061e0(int param_1)

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
  for (local_10 = DAT_10018574; local_10 < DAT_10018578; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x1c))(0);
    }
  }
  FUN_10006130(param_1);
  return;
}



// Function: FUN_10006290 at 10006290

void __fastcall FUN_10006290(undefined4 *param_1)

{
  FUN_100062e0((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_100062c0 at 100062c0

void __fastcall FUN_100062c0(int param_1)

{
  FUN_10004440((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100062e0 at 100062e0

undefined4 __fastcall FUN_100062e0(LPCRITICAL_SECTION param_1)

{
  LeaveCriticalSection(param_1);
  return 0;
}



// Function: FUN_10006300 at 10006300

int FUN_10006300(int param_1,void *param_2)

{
  int local_c;
  
  local_c = 0;
  if (DAT_100184e4 != (code *)0x0) {
    local_c = (*DAT_100184e4)();
  }
  if (-1 < local_c) {
    local_c = FUN_10006350(&DAT_1001856c,param_1,param_2);
  }
  return local_c;
}



// Function: FUN_10006350 at 10006350

void __thiscall FUN_10006350(void *this,int param_1,void *param_2)

{
  FUN_10008380((int)this,param_1,param_2);
  return;
}



// Function: FUN_10006380 at 10006380

int __thiscall FUN_10006380(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined4 uVar3;
  int *local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_10008a00(param_2,(void *)*local_10), CONCAT31(extraout_var,bVar1) != 0)) {
        uVar3 = 0;
        uVar2 = (*(code *)local_10[7])(0);
        local_c = AtlRegisterClassCategoriesHelper(*local_10,uVar2,uVar3);
        if ((local_c < 0) || (local_c = (*(code *)local_10[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_10006300(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_10006440 at 10006440

void FUN_10006440(int *param_1,ushort param_2,undefined4 param_3,int *param_4)

{
  FUN_10006630(param_1,(uint)param_2,param_3,param_4);
  return;
}



// Function: FUN_10006470 at 10006470

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10006470(int *param_1,char *param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  uint local_90;
  LPWSTR local_80;
  LPWSTR local_78;
  LPWSTR local_74;
  int local_28;
  char *local_24;
  UINT local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011918;
  local_10 = ExceptionList;
  local_90 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_90;
  if (param_2 != (char *)0x0) {
    local_1c = FUN_100067f0();
    FUN_10001920(&local_28);
    local_8 = 0;
    local_24 = param_2;
    if (param_2 == (char *)0x0) {
      local_74 = (LPWSTR)0x0;
    }
    else {
      sVar2 = strlen(param_2);
      local_18 = sVar2 + 1;
      uVar3 = FUN_10001520(&local_18,local_18,2);
      if ((int)uVar3 < 0) {
        local_78 = (LPWSTR)0x0;
      }
      else {
        if (((int)local_18 < 0x401) && (cVar1 = FUN_10006890(local_18), cVar1 != '\0')) {
          local_80 = (LPWSTR)&local_90;
        }
        else {
          local_80 = (LPWSTR)FUN_10003d80(&local_28,local_18);
        }
        local_78 = FUN_10003e00(local_80,local_24,local_18 >> 1,local_1c);
      }
      local_74 = local_78;
    }
    FUN_10006630(param_1,local_74,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_100028c0(&local_28);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100065d0 at 100065d0

void FUN_100065d0(int *param_1,ushort param_2,undefined4 param_3,int *param_4)

{
  FUN_10006440(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10006600 at 10006600

void FUN_10006600(int *param_1,char *param_2,undefined4 param_3,int *param_4)

{
  FUN_10006470(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10006630 at 10006630

int FUN_10006630(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011948;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001c70(&local_14);
  local_8 = 0;
  uVar1 = FUN_10003880(&local_14);
  iVar2 = AtlCreateRegistrar(uVar1);
  if (iVar2 < 0) {
    local_8 = 0xffffffff;
    FUN_10002c10(&local_14);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        piVar3 = (int *)FUN_10003710(&local_14);
        (**(code **)(*piVar3 + 0xc))(piVar3,*param_4,param_4[1]);
      }
    }
    uVar1 = FUN_10003650(&local_14);
    iVar2 = (**(code **)(*param_1 + 0x14))(uVar1);
    if (iVar2 < 0) {
      local_8 = 0xffffffff;
      FUN_10002c10(&local_14);
    }
    else {
      uVar1 = FUN_10003650(&local_14);
      uVar5 = 0;
      uVar4 = FUN_10004b00(0x10018534);
      iVar2 = AtlUpdateRegistryFromResourceD(uVar4,param_2,param_3,uVar5,uVar1);
      local_8 = 0xffffffff;
      FUN_10002c10(&local_14);
    }
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10006770 at 10006770

undefined4 FUN_10006770(void)

{
  return 0x80004005;
}



// Function: FUN_10006790 at 10006790

undefined4 FUN_10006790(void)

{
  return 0x80004005;
}



// Function: FUN_100067b0 at 100067b0

void FUN_100067b0(void)

{
  return;
}



// Function: FUN_100067d0 at 100067d0

undefined4 FUN_100067d0(void)

{
  return 0;
}



// Function: FUN_100067f0 at 100067f0

undefined4 FUN_100067f0(void)

{
  return 3;
}



// Function: FUN_10006810 at 10006810

int __fastcall FUN_10006810(int param_1)

{
  undefined4 local_c;
  
  local_c = FUN_10006850(param_1 + 0x14);
  if (-1 < local_c) {
    local_c = FUN_10006870();
  }
  return local_c;
}



// Function: FUN_10006850 at 10006850

void __fastcall FUN_10006850(int param_1)

{
  FUN_10005210((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10006870 at 10006870

void FUN_10006870(void)

{
  FUN_10005130();
  return;
}



// Function: FUN_10006890 at 10006890

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_10006890(int param_1)

{
  uint uVar1;
  uint local_88;
  int local_28;
  undefined1 local_21;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_1001039c;
  local_14 = ExceptionList;
  local_c = DAT_10018498 ^ 0x10015698;
  local_88 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_88;
  ExceptionList = &local_14;
  local_21 = 1;
  local_8 = 0;
  local_28 = 0;
  local_20 = local_88;
  uVar1 = FUN_100014a0(&local_28,param_1,0x2000);
  if ((int)uVar1 < 0) {
    local_21 = 0;
  }
  else {
    local_1c = (undefined1 *)((int)&local_88 - local_28);
  }
  local_8 = 0xfffffffe;
  ExceptionList = local_14;
  __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006980 at 10006980

void FUN_10006980(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uStack_74;
  undefined1 local_61;
  undefined1 local_60;
  undefined1 local_5f;
  undefined1 local_5e [66];
  int local_1c [2];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011970;
  local_10 = ExceptionList;
  uStack_74 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_74;
  ExceptionList = &local_10;
  uVar4 = 1;
  FUN_10006c90(&local_61);
  local_1c[0] = FUN_100071d0(uVar4);
  local_8 = 0;
  piVar5 = local_1c;
  uVar1 = FUN_10006d30(local_1c[0]);
  uVar1 = FUN_10001630(uVar1);
  pvVar2 = (void *)FUN_10006c90(&local_60);
  FUN_10001670(pvVar2,uVar1,piVar5);
  piVar5 = local_1c;
  iVar3 = FUN_10006fa0(local_1c[0]);
  uVar1 = FUN_10001630(iVar3);
  pvVar2 = (void *)FUN_10006c90(&local_5f);
  FUN_10001670(pvVar2,uVar1,piVar5);
  piVar5 = local_1c;
  iVar3 = FUN_10006fc0(local_1c[0]);
  uVar1 = FUN_10001630(iVar3);
  pvVar2 = (void *)FUN_10006c90(local_5e);
  FUN_10001670(pvVar2,uVar1,piVar5);
  FUN_10006a7f();
  return;
}



// Function: Catch@10006a57 at 10006a57

void Catch_10006a57(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  pvVar1 = *(void **)(unaff_EBP + -0x18);
  FUN_10006c90(unaff_EBP + -0x59);
  FUN_100072c0(pvVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10006a7f at 10006a7f

undefined4 FUN_10006a7f(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  puVar1 = (undefined1 *)FUN_10006ad0(*(int *)(unaff_EBP + -0x18));
  *puVar1 = 1;
  puVar1 = (undefined1 *)FUN_10006d10(*(int *)(unaff_EBP + -0x18));
  *puVar1 = 1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10006ad0 at 10006ad0

int __cdecl FUN_10006ad0(int param_1)

{
  return param_1 + 0xc;
}



// Function: FUN_10006af0 at 10006af0

void FUN_10006af0(void *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  void *this;
  void *pvVar5;
  undefined1 local_4e;
  undefined1 local_4d [65];
  void *local_c;
  
  local_c = param_1;
  while( true ) {
    pvVar5 = local_c;
    pcVar1 = (char *)FUN_10006d10((int)local_c);
    if (*pcVar1 != '\0') break;
    puVar2 = (undefined4 *)FUN_10006fc0((int)local_c);
    FUN_10006af0((void *)*puVar2);
    puVar2 = (undefined4 *)FUN_10006d30(local_c);
    local_c = (void *)*puVar2;
    iVar3 = FUN_10006f80((int)pvVar5);
    pvVar4 = (void *)FUN_10001650(iVar3);
    this = (void *)FUN_10006c90(&local_4e);
    FUN_100017e0(this,pvVar4);
    FUN_10006c90(local_4d);
    FUN_100072c0(pvVar5);
  }
  return;
}



// Function: FUN_10006ba0 at 10006ba0

void FUN_10006ba0(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49 [69];
  
  uVar1 = FUN_10006d30(param_1);
  FUN_10001630(uVar1);
  FUN_10006c90(&local_4c);
  FUN_10001770();
  iVar2 = FUN_10006fa0((int)param_1);
  FUN_10001630(iVar2);
  FUN_10006c90(&local_4b);
  FUN_10001770();
  iVar2 = FUN_10006fc0((int)param_1);
  FUN_10001630(iVar2);
  FUN_10006c90(&local_4a);
  FUN_10001770();
  FUN_10006c90(local_49);
  FUN_100072c0(param_1);
  return;
}



// Function: FUN_10006c50 at 10006c50

undefined ** FUN_10006c50(void)

{
  return &PTR_DAT_100134e8;
}



// Function: FUN_10006c70 at 10006c70

undefined ** FUN_10006c70(void)

{
  return &PTR_DAT_10013558;
}



// Function: FUN_10006c90 at 10006c90

undefined4 FUN_10006c90(undefined4 param_1)

{
  FUN_100021c0(param_1);
  return param_1;
}



// Function: FUN_10006cb0 at 10006cb0

void __thiscall FUN_10006cb0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_10006c50();
  FUN_10005380(this,ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_10006ce0 at 10006ce0

void __thiscall FUN_10006ce0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_10006c70();
  FUN_10005380(this,ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_10006d10 at 10006d10

int __cdecl FUN_10006d10(int param_1)

{
  return param_1 + 0xd;
}



// Function: FUN_10006d30 at 10006d30

undefined4 __cdecl FUN_10006d30(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10006d50 at 10006d50

void __fastcall FUN_10006d50(undefined4 *param_1)

{
  FUN_10006d30(*param_1);
  return;
}



// Function: FUN_10006d80 at 10006d80

void __thiscall FUN_10006d80(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_10006fc0(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_10006d30(iVar1);
  puVar4 = (undefined4 *)FUN_10006fc0(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10006d30(iVar1);
  pcVar5 = (char *)FUN_10006d10(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_10006d30(iVar1);
    piVar2 = (int *)FUN_10006fa0(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_10006fa0(param_1);
  puVar4 = (undefined4 *)FUN_10006fa0(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10007010((int *)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_10007010((int *)this);
    *piVar2 = iVar1;
  }
  else {
    puVar3 = (undefined4 *)FUN_10006fa0(param_1);
    piVar2 = (int *)FUN_10006d30(*puVar3);
    if (param_1 == *piVar2) {
      puVar3 = (undefined4 *)FUN_10006fa0(param_1);
      piVar2 = (int *)FUN_10006d30(*puVar3);
      *piVar2 = iVar1;
    }
    else {
      piVar2 = (int *)FUN_10006fa0(param_1);
      piVar2 = (int *)FUN_10006fc0(*piVar2);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_10006d30(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_10006fa0(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_10006ec0 at 10006ec0

int __cdecl FUN_10006ec0(int param_1)

{
  int *piVar1;
  char *pcVar2;
  
  while( true ) {
    piVar1 = (int *)FUN_10006fc0(param_1);
    pcVar2 = (char *)FUN_10006d10(*piVar1);
    if (*pcVar2 != '\0') break;
    piVar1 = (int *)FUN_10006fc0(param_1);
    param_1 = *piVar1;
  }
  return param_1;
}



// Function: FUN_10006f10 at 10006f10

undefined4 __cdecl FUN_10006f10(undefined4 param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  while( true ) {
    piVar1 = (int *)FUN_10006d30(param_1);
    pcVar2 = (char *)FUN_10006d10(*piVar1);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_10006d30(param_1);
    param_1 = *puVar3;
  }
  return param_1;
}



// Function: FUN_10006f60 at 10006f60

undefined4 __fastcall FUN_10006f60(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10006f80 at 10006f80

int __cdecl FUN_10006f80(int param_1)

{
  return param_1 + 0x10;
}



// Function: FUN_10006fa0 at 10006fa0

int __cdecl FUN_10006fa0(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_10006fc0 at 10006fc0

int __cdecl FUN_10006fc0(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_10006fe0 at 10006fe0

void __fastcall FUN_10006fe0(int *param_1)

{
  FUN_10006fc0(*param_1);
  return;
}



// Function: FUN_10007010 at 10007010

void __fastcall FUN_10007010(int *param_1)

{
  FUN_10006fa0(*param_1);
  return;
}



// Function: FUN_10007040 at 10007040

void __thiscall FUN_10007040(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_10006d30(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_10006fc0(iVar1);
  puVar4 = (undefined4 *)FUN_10006d30(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10006fc0(iVar1);
  pcVar5 = (char *)FUN_10006d10(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_10006fc0(iVar1);
    piVar2 = (int *)FUN_10006fa0(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_10006fa0(param_1);
  puVar4 = (undefined4 *)FUN_10006fa0(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10007010((int *)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_10007010((int *)this);
    *piVar2 = iVar1;
  }
  else {
    piVar2 = (int *)FUN_10006fa0(param_1);
    piVar2 = (int *)FUN_10006fc0(*piVar2);
    if (param_1 == *piVar2) {
      piVar2 = (int *)FUN_10006fa0(param_1);
      piVar2 = (int *)FUN_10006fc0(*piVar2);
      *piVar2 = iVar1;
    }
    else {
      puVar3 = (undefined4 *)FUN_10006fa0(param_1);
      piVar2 = (int *)FUN_10006d30(*puVar3);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_10006fc0(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_10006fa0(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_10007180 at 10007180

void __fastcall FUN_10007180(int *param_1)

{
  undefined4 *puVar1;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [68];
  int *local_8;
  
  local_8 = param_1;
  FUN_10007320(param_1,local_58);
  puVar1 = (undefined4 *)FUN_10007230(local_8,local_50);
  local_54 = *puVar1;
  FUN_10007350(local_8,local_4c,local_54);
  return;
}



// Function: FUN_100071d0 at 100071d0

void FUN_100071d0(uint param_1)

{
  FUN_10007200(param_1);
  return;
}



// Function: FUN_10007200 at 10007200

void FUN_10007200(uint param_1)

{
  FUN_100015c0(param_1);
  return;
}



// Function: FUN_10007230 at 10007230

void * __thiscall FUN_10007230(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10006d50((undefined4 *)this);
  FUN_10002130(param_1,*puVar1);
  return param_1;
}



// Function: FUN_10007260 at 10007260

void __fastcall FUN_10007260(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = (undefined4 *)FUN_10007010(param_1);
  FUN_10006af0((void *)*puVar1);
  piVar2 = (int *)FUN_10007010(param_1);
  *piVar2 = *param_1;
  piVar2 = (int *)FUN_10006d50(param_1);
  *piVar2 = *param_1;
  piVar2 = (int *)FUN_10006fe0(param_1);
  *piVar2 = *param_1;
  param_1[1] = 0;
  return;
}



// Function: FUN_100072c0 at 100072c0

void FUN_100072c0(void *param_1)

{
  FUN_100072f0(param_1);
  return;
}



// Function: FUN_100072f0 at 100072f0

void FUN_100072f0(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_10007320 at 10007320

void * __thiscall FUN_10007320(void *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  FUN_10002130(param_1,*this);
  return param_1;
}



// Function: FUN_10007350 at 10007350

/* WARNING: Variable defined which should be unmapped: param_2 */

void * __thiscall FUN_10007350(int *param_1,void *param_2,undefined4 param_3)

{
  bool bVar1;
  int *piVar2;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  int local_50;
  undefined1 local_4c [68];
  int *local_8;
  
  local_8 = param_1;
  piVar2 = (int *)FUN_10007230(param_1,local_58);
  bVar1 = FUN_10003570(&param_3,piVar2);
  if (bVar1) {
    piVar2 = (int *)FUN_10007320(local_8,local_54);
    bVar1 = FUN_10003570(&stack0x0000000c,piVar2);
    if (bVar1) {
      FUN_10007260(local_8);
      FUN_10007230(local_8,param_2);
      return param_2;
    }
  }
  while (bVar1 = FUN_100035d0(&param_3,(int *)&stack0x0000000c), bVar1) {
    piVar2 = FUN_10003770(&param_3,&local_50);
    FUN_10007400(local_4c,*piVar2);
  }
  FUN_10002130(param_2,param_3);
  return param_2;
}



// Function: FUN_10007400 at 10007400

void * FUN_10007400(void *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  void *pvVar8;
  void *this;
  void *local_60;
  undefined1 local_5a;
  undefined1 local_59 [65];
  void *local_18;
  void *local_14;
  void *local_10;
  void *local_c;
  int *local_8;
  
  iVar1 = FUN_10006f60(&param_2);
  pcVar2 = (char *)FUN_10006d10(iVar1);
  if (*pcVar2 != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  local_c = (void *)FUN_10006f60(&param_2);
  FUN_100037a0(&param_2);
  local_18 = local_c;
  piVar3 = (int *)FUN_10006d30(local_c);
  pcVar2 = (char *)FUN_10006d10(*piVar3);
  if (*pcVar2 == '\0') {
    piVar3 = (int *)FUN_10006fc0((int)local_18);
    pcVar2 = (char *)FUN_10006d10(*piVar3);
    if (*pcVar2 == '\0') {
      local_18 = (void *)FUN_10006f60(&param_2);
      puVar4 = (undefined4 *)FUN_10006fc0((int)local_18);
      local_10 = (void *)*puVar4;
    }
    else {
      puVar4 = (undefined4 *)FUN_10006d30(local_18);
      local_10 = (void *)*puVar4;
    }
  }
  else {
    puVar4 = (undefined4 *)FUN_10006fc0((int)local_18);
    local_10 = (void *)*puVar4;
  }
  if (local_18 == local_c) {
    piVar3 = (int *)FUN_10006fa0((int)local_c);
    local_14 = (void *)*piVar3;
    pcVar2 = (char *)FUN_10006d10((int)local_10);
    if (*pcVar2 == '\0') {
      piVar3 = (int *)FUN_10006fa0((int)local_10);
      *piVar3 = (int)local_14;
    }
    piVar3 = (int *)FUN_10007010(local_8);
    if ((void *)*piVar3 == local_c) {
      puVar4 = (undefined4 *)FUN_10007010(local_8);
      *puVar4 = local_10;
    }
    else {
      piVar3 = (int *)FUN_10006d30(local_14);
      if ((void *)*piVar3 == local_c) {
        puVar4 = (undefined4 *)FUN_10006d30(local_14);
        *puVar4 = local_10;
      }
      else {
        puVar4 = (undefined4 *)FUN_10006fc0((int)local_14);
        *puVar4 = local_10;
      }
    }
    piVar3 = (int *)FUN_10006d50(local_8);
    if ((void *)*piVar3 == local_c) {
      pcVar2 = (char *)FUN_10006d10((int)local_10);
      if (*pcVar2 == '\0') {
        local_60 = (void *)FUN_10006f10(local_10);
      }
      else {
        local_60 = local_14;
      }
      piVar3 = (int *)FUN_10006d50(local_8);
      *piVar3 = (int)local_60;
    }
    piVar3 = (int *)FUN_10006fe0(local_8);
    if ((void *)*piVar3 == local_c) {
      pcVar2 = (char *)FUN_10006d10((int)local_10);
      if (*pcVar2 == '\0') {
        local_60 = (void *)FUN_10006ec0((int)local_10);
      }
      else {
        local_60 = local_14;
      }
      piVar3 = (int *)FUN_10006fe0(local_8);
      *piVar3 = (int)local_60;
    }
  }
  else {
    piVar3 = (int *)FUN_10006d30(local_c);
    puVar4 = (undefined4 *)FUN_10006fa0(*piVar3);
    *puVar4 = local_18;
    puVar4 = (undefined4 *)FUN_10006d30(local_c);
    puVar5 = (undefined4 *)FUN_10006d30(local_18);
    *puVar5 = *puVar4;
    piVar3 = (int *)FUN_10006fc0((int)local_c);
    if (local_18 == (void *)*piVar3) {
      local_14 = local_18;
    }
    else {
      piVar3 = (int *)FUN_10006fa0((int)local_18);
      local_14 = (void *)*piVar3;
      pcVar2 = (char *)FUN_10006d10((int)local_10);
      if (*pcVar2 == '\0') {
        piVar3 = (int *)FUN_10006fa0((int)local_10);
        *piVar3 = (int)local_14;
      }
      puVar4 = (undefined4 *)FUN_10006d30(local_14);
      *puVar4 = local_10;
      puVar4 = (undefined4 *)FUN_10006fc0((int)local_c);
      puVar5 = (undefined4 *)FUN_10006fc0((int)local_18);
      *puVar5 = *puVar4;
      piVar3 = (int *)FUN_10006fc0((int)local_c);
      puVar4 = (undefined4 *)FUN_10006fa0(*piVar3);
      *puVar4 = local_18;
    }
    piVar3 = (int *)FUN_10007010(local_8);
    if ((void *)*piVar3 == local_c) {
      puVar4 = (undefined4 *)FUN_10007010(local_8);
      *puVar4 = local_18;
    }
    else {
      puVar4 = (undefined4 *)FUN_10006fa0((int)local_c);
      piVar3 = (int *)FUN_10006d30(*puVar4);
      if ((void *)*piVar3 == local_c) {
        puVar4 = (undefined4 *)FUN_10006fa0((int)local_c);
        puVar4 = (undefined4 *)FUN_10006d30(*puVar4);
        *puVar4 = local_18;
      }
      else {
        piVar3 = (int *)FUN_10006fa0((int)local_c);
        puVar4 = (undefined4 *)FUN_10006fc0(*piVar3);
        *puVar4 = local_18;
      }
    }
    puVar4 = (undefined4 *)FUN_10006fa0((int)local_c);
    puVar5 = (undefined4 *)FUN_10006fa0((int)local_18);
    *puVar5 = *puVar4;
    puVar6 = (undefined1 *)FUN_10006ad0((int)local_c);
    puVar7 = (undefined1 *)FUN_10006ad0((int)local_18);
    FUN_10001870(puVar7,puVar6);
  }
  pcVar2 = (char *)FUN_10006ad0((int)local_c);
  if (*pcVar2 != '\x01') {
LAB_10007b22:
    iVar1 = FUN_10006f80((int)local_c);
    pvVar8 = (void *)FUN_10001650(iVar1);
    this = (void *)FUN_10006c90(&local_5a);
    FUN_100017e0(this,pvVar8);
    pvVar8 = local_c;
    FUN_10006c90(local_59);
    FUN_100072c0(pvVar8);
    if (local_8[1] != 0) {
      local_8[1] = local_8[1] + -1;
    }
    FUN_10002130(param_1,param_2);
    return param_1;
  }
LAB_100077a6:
  piVar3 = (int *)FUN_10007010(local_8);
  if ((local_10 == (void *)*piVar3) ||
     (pcVar2 = (char *)FUN_10006ad0((int)local_10), *pcVar2 != '\x01')) goto LAB_10007b13;
  piVar3 = (int *)FUN_10006d30(local_14);
  if (local_10 == (void *)*piVar3) {
    piVar3 = (int *)FUN_10006fc0((int)local_14);
    local_18 = (void *)*piVar3;
    pcVar2 = (char *)FUN_10006ad0((int)local_18);
    if (*pcVar2 == '\0') {
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_18);
      *puVar6 = 1;
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_14);
      *puVar6 = 0;
      FUN_10006d80(local_8,(int)local_14);
      puVar4 = (undefined4 *)FUN_10006fc0((int)local_14);
      local_18 = (void *)*puVar4;
    }
    pcVar2 = (char *)FUN_10006d10((int)local_18);
    pvVar8 = local_14;
    if (*pcVar2 == '\0') {
      piVar3 = (int *)FUN_10006d30(local_18);
      pcVar2 = (char *)FUN_10006ad0(*piVar3);
      if (*pcVar2 == '\x01') {
        piVar3 = (int *)FUN_10006fc0((int)local_18);
        pcVar2 = (char *)FUN_10006ad0(*piVar3);
        if (*pcVar2 == '\x01') {
          puVar6 = (undefined1 *)FUN_10006ad0((int)local_18);
          *puVar6 = 0;
          pvVar8 = local_14;
          goto LAB_10007795;
        }
      }
      piVar3 = (int *)FUN_10006fc0((int)local_18);
      pcVar2 = (char *)FUN_10006ad0(*piVar3);
      if (*pcVar2 == '\x01') {
        piVar3 = (int *)FUN_10006d30(local_18);
        puVar6 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar6 = 1;
        puVar6 = (undefined1 *)FUN_10006ad0((int)local_18);
        *puVar6 = 0;
        FUN_10007040(local_8,(int)local_18);
        puVar4 = (undefined4 *)FUN_10006fc0((int)local_14);
        local_18 = (void *)*puVar4;
      }
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_14);
      puVar7 = (undefined1 *)FUN_10006ad0((int)local_18);
      *puVar7 = *puVar6;
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_14);
      *puVar6 = 1;
      piVar3 = (int *)FUN_10006fc0((int)local_18);
      puVar6 = (undefined1 *)FUN_10006ad0(*piVar3);
      *puVar6 = 1;
      FUN_10006d80(local_8,(int)local_14);
LAB_10007b13:
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_10);
      *puVar6 = 1;
      goto LAB_10007b22;
    }
  }
  else {
    piVar3 = (int *)FUN_10006d30(local_14);
    local_18 = (void *)*piVar3;
    pcVar2 = (char *)FUN_10006ad0((int)local_18);
    if (*pcVar2 == '\0') {
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_18);
      *puVar6 = 1;
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_14);
      *puVar6 = 0;
      FUN_10007040(local_8,(int)local_14);
      puVar4 = (undefined4 *)FUN_10006d30(local_14);
      local_18 = (void *)*puVar4;
    }
    pcVar2 = (char *)FUN_10006d10((int)local_18);
    if (*pcVar2 == '\0') {
      piVar3 = (int *)FUN_10006fc0((int)local_18);
      pcVar2 = (char *)FUN_10006ad0(*piVar3);
      if (*pcVar2 == '\x01') {
        piVar3 = (int *)FUN_10006d30(local_18);
        pcVar2 = (char *)FUN_10006ad0(*piVar3);
        if (*pcVar2 == '\x01') {
          puVar6 = (undefined1 *)FUN_10006ad0((int)local_18);
          *puVar6 = 0;
          local_10 = local_14;
          pvVar8 = local_10;
          goto LAB_10007795;
        }
      }
      piVar3 = (int *)FUN_10006d30(local_18);
      pcVar2 = (char *)FUN_10006ad0(*piVar3);
      if (*pcVar2 == '\x01') {
        piVar3 = (int *)FUN_10006fc0((int)local_18);
        puVar6 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar6 = 1;
        puVar6 = (undefined1 *)FUN_10006ad0((int)local_18);
        *puVar6 = 0;
        FUN_10006d80(local_8,(int)local_18);
        puVar4 = (undefined4 *)FUN_10006d30(local_14);
        local_18 = (void *)*puVar4;
      }
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_14);
      puVar7 = (undefined1 *)FUN_10006ad0((int)local_18);
      *puVar7 = *puVar6;
      puVar6 = (undefined1 *)FUN_10006ad0((int)local_14);
      *puVar6 = 1;
      piVar3 = (int *)FUN_10006d30(local_18);
      puVar6 = (undefined1 *)FUN_10006ad0(*piVar3);
      *puVar6 = 1;
      FUN_10007040(local_8,(int)local_14);
      goto LAB_10007b13;
    }
    pvVar8 = local_14;
  }
LAB_10007795:
  local_10 = pvVar8;
  local_14 = local_10;
  piVar3 = (int *)FUN_10006fa0((int)local_10);
  local_14 = (void *)*piVar3;
  goto LAB_100077a6;
}



// Function: CDict_get_Count at 10007ba0

void CDict_get_Count(int param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011998;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x10))(param_1 + 0x24,param_2);
  FUN_10007cab();
  return;
}



// Function: Catch@10007bf8 at 10007bf8

undefined * Catch_10007bf8(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x7c,
                       "CDict::get_Count",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_10007cc2;
}



// Function: Catch@10007c41 at 10007c41

undefined * Catch_10007c41(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x7c,
                       "CDict::get_Count",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10007c9f;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_10007cb4;
}



// Function: FUN_10007cab at 10007cab

undefined4 FUN_10007cab(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: CDict_get_Item at 10007cf0

void CDict_get_Item(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100119c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 8))(param_1 + 0x24,param_2,param_3);
  FUN_10007dff();
  return;
}



// Function: Catch@10007d4c at 10007d4c

undefined * Catch_10007d4c(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x66,
                       "CDict::get_Item",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  return &DAT_10007e16;
}



// Function: Catch@10007d95 at 10007d95

undefined * Catch_10007d95(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x66,
                       "CDict::get_Item",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10007df3;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_10007e08;
}



// Function: FUN_10007dff at 10007dff

undefined4 FUN_10007dff(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10007e40 at 10007e40

size_t __cdecl FUN_10007e40(wchar_t *param_1)

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



// Function: CDict_put_Item at 10007e70

void CDict_put_Item(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100119f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 4))(param_1 + 0x24,param_2,param_3);
  FUN_10007f7f();
  return;
}



// Function: Catch@10007ecc at 10007ecc

undefined * Catch_10007ecc(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x5b,
                       "CDict::put_Item",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_10007f96;
}



// Function: Catch@10007f15 at 10007f15

undefined * Catch_10007f15(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x5b,
                       "CDict::put_Item",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10007f73;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_10007f88;
}



// Function: FUN_10007f7f at 10007f7f

undefined4 FUN_10007f7f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: CDict_put_Key at 10007fc0

void CDict_put_Key(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011a28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x18))(param_1 + 0x24,param_2,param_3);
  FUN_100080d5();
  return;
}



// Function: Catch@1000801c at 1000801c

undefined * Catch_1000801c(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x94,
                       "CDict::put_Key",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_100080ec;
}



// Function: Catch@10008068 at 10008068

undefined * Catch_10008068(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x94,
                       "CDict::put_Key",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x100080c9;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_100080de;
}



// Function: FUN_100080d5 at 100080d5

undefined4 FUN_100080d5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: CDict_putref_Item at 10008110

void CDict_putref_Item(int param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011a58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (*(code *)**(undefined4 **)(param_1 + 0x24))(param_1 + 0x24,param_2,param_3);
  FUN_1000821e();
  return;
}



// Function: Catch@1000816b at 1000816b

undefined * Catch_1000816b(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo(*(void **)(unaff_EBP + -0x18),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x50,
                       "CDict::putref_Item",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x70) = uVar2;
  return &DAT_10008235;
}



// Function: Catch@100081b4 at 100081b4

undefined * Catch_100081b4(void)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  undefined4 uStack0000001c;
  
  FUN_10002780((void *)(unaff_EBP + -0x28),0x8000ffff,0,'\0');
  *(undefined1 *)(unaff_EBP + -4) = 2;
  puVar1 = (undefined8 *)FUN_10004b20();
  uVar2 = throwExceptionWithFileInfo((void *)(unaff_EBP + -0x28),
                       "d:\\views\\kt874_view_bm3\\etips_comp\\mdas\\src\\dictionary\\dict.h",0x50,
                       "CDict::putref_Item",*puVar1,puVar1[1]);
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uStack0000001c = 0x10008212;
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return &DAT_10008227;
}



// Function: FUN_1000821e at 1000821e

undefined4 FUN_1000821e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10008260 at 10008260

void __cdecl FUN_10008260(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  FUN_10003e60(eVar1);
  return;
}



// Function: FUN_100082a0 at 100082a0

int FUN_100082a0(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined4 uVar4;
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
          (bVar2 = FUN_10008a00(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        uVar4 = 1;
        uVar3 = (*(code *)puVar1[6])(1);
        local_8 = AtlRegisterClassCategoriesHelper(*puVar1,uVar3,uVar4);
        if (local_8 < 0) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10008450(*(undefined4 *)(param_1 + 4),0);
    }
  }
  return local_8;
}



// Function: FUN_10008380 at 10008380

int FUN_10008380(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined4 uVar4;
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
          (bVar2 = FUN_10008a00(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        uVar4 = 0;
        uVar3 = (*(code *)puVar1[6])(0);
        local_8 = AtlRegisterClassCategoriesHelper(*puVar1,uVar3,uVar4);
        if ((local_8 < 0) || (local_8 = (*(code *)puVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10008710(*(undefined4 *)(param_1 + 4),0);
    }
  }
  return local_8;
}



// Function: FUN_10008450 at 10008450

/* WARNING: Removing unreachable block (ram,0x1000857d) */

void FUN_10008450(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  rsize_t rVar5;
  int iVar6;
  HMODULE hModule;
  wchar_t *pwVar7;
  char local_235;
  FARPROC local_234;
  wchar_t *local_230;
  wchar_t local_22c [259];
  undefined2 uStack_26;
  wchar_t *local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011a9b;
  local_10 = ExceptionList;
  local_14 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100023c0(&local_18);
  local_8 = 0;
  FUN_10001df0(&local_1c);
  local_8._0_1_ = 1;
  uVar2 = FUN_100038e0(&local_1c);
  uVar3 = FUN_10003920(&local_18);
  local_20 = AtlLoadTypeLib(param_1,param_2,uVar3,uVar2);
  if (-1 < local_20) {
    local_24 = (wchar_t *)0x0;
    FUN_100023c0(&local_230);
    local_8 = CONCAT31(local_8._1_3_,2);
    piVar4 = (int *)FUN_10003750(&local_1c);
    uVar2 = FUN_10003920(&local_230);
    local_20 = (**(code **)(*piVar4 + 0x24))(piVar4,0xffffffff,0,0,0,uVar2);
    if ((-1 < local_20) && (bVar1 = FUN_10003610((int *)&local_230), bVar1)) {
      rVar5 = FUN_100056f0(&local_230);
      FUN_10008260(local_22c,0x104,local_230,rVar5);
      uStack_26 = 0;
      iVar6 = FUN_10003f20(local_22c);
      if (0x207 < (uint)(iVar6 * 2)) {
        ___report_rangecheckfailure();
      }
      local_22c[iVar6] = L'\0';
      local_24 = local_22c;
    }
    local_234 = (FARPROC)0x0;
    local_235 = '\0';
    local_20 = AtlGetPerUserRegistration(&local_235);
    if (local_20 < 0) {
      local_8._0_1_ = 1;
      FUN_10001000(&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10002d30(&local_1c);
      local_8 = 0xffffffff;
      FUN_10001000(&local_18);
      goto LAB_100086ea;
    }
    if ((local_235 == '\x01') &&
       (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
      local_234 = GetProcAddress(hModule,"RegisterTypeLibForUser");
    }
    if (local_234 == (FARPROC)0x0) {
      local_234 = Ordinal_163_exref;
    }
    pwVar7 = local_24;
    uVar2 = FUN_100036f0(&local_18);
    uVar3 = FUN_100036b0(&local_1c);
    local_20 = (*local_234)(uVar3,uVar2,pwVar7);
    local_8._0_1_ = 1;
    FUN_10001000(&local_230);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002d30(&local_1c);
  local_8 = 0xffffffff;
  FUN_10001000(&local_18);
LAB_100086ea:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008710 at 10008710

int FUN_10008710(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  HMODULE hModule;
  char local_25;
  FARPROC local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011ae0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100023c0(&local_14);
  local_8 = 0;
  FUN_10001df0(&local_18);
  local_8._0_1_ = 1;
  uVar1 = FUN_100038e0(&local_18);
  uVar2 = FUN_10003920(&local_14);
  local_1c = AtlLoadTypeLib(param_1,param_2,uVar2,uVar1);
  if (-1 < local_1c) {
    piVar3 = (int *)FUN_10003750(&local_18);
    local_1c = (**(code **)(*piVar3 + 0x1c))(piVar3,&local_20);
    if (-1 < local_1c) {
      local_24 = (FARPROC)0x0;
      local_25 = '\0';
      iVar4 = AtlGetPerUserRegistration(&local_25);
      local_1c = iVar4;
      if (iVar4 < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10002d30(&local_18);
        local_8 = 0xffffffff;
        FUN_10001000(&local_14);
        ExceptionList = local_10;
        return iVar4;
      }
      if ((local_25 == '\x01') &&
         (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule != (HMODULE)0x0)) {
        local_24 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
      }
      if (local_24 == (FARPROC)0x0) {
        local_24 = Ordinal_186_exref;
      }
      local_1c = (*local_24)(local_20,(uint)*(ushort *)(local_20 + 0x18),
                             (uint)*(ushort *)(local_20 + 0x1a),*(undefined4 *)(local_20 + 0x10),
                             *(undefined4 *)(local_20 + 0x14));
      piVar3 = (int *)FUN_10003750(&local_18);
      (**(code **)(*piVar3 + 0x30))(piVar3,local_20);
    }
  }
  iVar4 = local_1c;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10002d30(&local_18);
  local_8 = 0xffffffff;
  FUN_10001000(&local_14);
  ExceptionList = local_10;
  return iVar4;
}



// Function: DllCanUnloadNow at 100088b0

HRESULT DllCanUnloadNow(void)

{
  int iVar1;
  uint local_48;
  
                    /* 0x88b0  1  DllCanUnloadNow */
  iVar1 = FUN_10004ae0(0x100184f0);
  local_48 = (uint)(iVar1 != 0);
  return local_48;
}



// Function: DllGetClassObject at 100088f0

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x88f0  2  DllGetClassObject */
  iVar1 = FUN_10004750(&DAT_100184f0,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_10008920 at 10008920

undefined4 FUN_10008920(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10005150(&DAT_100184f0,0x10018010,param_1,(undefined4 *)&DAT_10013430);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_100061e0(0x100184f0);
  }
  return 1;
}



// Function: DllRegisterServer at 10008980

void DllRegisterServer(void)

{
                    /* 0x8980  3  DllRegisterServer */
  FUN_10005c30(&DAT_100184f0,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 100089a0

void DllUnregisterServer(void)

{
                    /* 0x89a0  4  DllUnregisterServer */
  FUN_10006380(&DAT_100184f0,1,(void *)0x0);
  return;
}



// Function: FUN_100089c0 at 100089c0

uint __cdecl FUN_100089c0(uint param_1)

{
  undefined4 local_48;
  
  if ((int)param_1 < 1) {
    local_48 = param_1;
  }
  else {
    local_48 = param_1 & 0xffff | 0x80070000;
  }
  return local_48;
}



// Function: FUN_10008a00 at 10008a00

bool __cdecl FUN_10008a00(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return iVar1 == 0;
}



// Function: FUN_10008a40 at 10008a40

int __thiscall FUN_10008a40(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 4) <= param_1)) {
    FUN_10008bb0(0xc000008c,1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this + param_1 * 2;
}



// Function: FUN_10008a80 at 10008a80

int FUN_10008a80(LPWSTR param_1)

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



// Function: FUN_10008b00 at 10008b00

undefined4 __fastcall FUN_10008b00(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10008b20 at 10008b20

void __fastcall FUN_10008b20(int *param_1)

{
  int local_c;
  
  if (*param_1 != 0) {
    for (local_c = 0; local_c < param_1[1]; local_c = local_c + 1) {
    }
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10008b90 at 10008b90

void __cdecl FUN_10008b90(LPCRITICAL_SECTION param_1,DWORD param_2)

{
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return;
}



// Function: FUN_10008bb0 at 10008bb0

void __cdecl FUN_10008bb0(DWORD param_1,DWORD param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: FUN_10008be0 at 10008be0

undefined4 FUN_10008be0(int *param_1,HINSTANCE param_2)

{
  undefined4 uVar1;
  int iVar2;
  ushort *puVar3;
  HINSTANCE hInstance;
  int local_8;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*param_1 == 0) {
    uVar1 = 0;
  }
  else if (*param_1 == 0x2c) {
    local_8 = 0;
    while( true ) {
      iVar2 = FUN_10008b00((int)(param_1 + 8));
      if (iVar2 <= local_8) break;
      hInstance = param_2;
      puVar3 = (ushort *)FUN_10008a40(param_1 + 8,local_8);
      UnregisterClassA((LPCSTR)(uint)*puVar3,hInstance);
      local_8 = local_8 + 1;
    }
    FUN_10008b20(param_1 + 8);
    FUN_100061c0((LPCRITICAL_SECTION)(param_1 + 1));
    *param_1 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



// Function: FUN_10008c80 at 10008c80

undefined4 FUN_10008c80(int param_1,tagVARIANT *param_2,tagVARIANT *param_3)

{
  CComVariant *this;
  tagVARIANT *ptVar1;
  short local_38 [8];
  tagVARIANT local_28 [16];
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011b10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  COleVariant(local_38,param_2);
  local_8 = 0;
  COleVariant(local_28,param_3);
  local_8._0_1_ = 1;
  ptVar1 = local_28;
  this = (CComVariant *)FUN_1000b750((void *)(param_1 + 4),local_38);
  ATL::CComVariant::operator=(this,ptVar1);
  local_18 = local_14;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10003330(local_28);
  local_8 = 0xffffffff;
  FUN_10003330(local_38);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10008d20 at 10008d20

undefined4 FUN_10008d20(int param_1,tagVARIANT *param_2,undefined4 param_3)

{
  bool bVar1;
  int *piVar2;
  undefined1 local_6c [32];
  short local_4c [8];
  undefined1 local_3c [8];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_20;
  void *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011b3b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = 0;
  FUN_1000b530(&local_14);
  COleVariant(local_4c,param_2);
  local_8 = 0;
  piVar2 = FUN_1000c220((void *)(param_1 + 4),&local_2c,local_4c);
  local_14 = *piVar2;
  piVar2 = (int *)FUN_10007320((void *)(param_1 + 4),local_30);
  bVar1 = FUN_100035d0(&local_14,piVar2);
  if (bVar1) {
    local_18 = local_14;
    FUN_10007400(local_34,local_14);
  }
  local_20 = FUN_100097f0(local_6c,param_2,param_3);
  local_8._0_1_ = 1;
  local_1c = local_20;
  FUN_1000c2c0(local_3c,local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10003090((int)local_6c);
  local_28 = local_24;
  local_8 = 0xffffffff;
  FUN_10003330(local_4c);
  ExceptionList = local_10;
  return local_28;
}



// Function: FUN_10008e20 at 10008e20

undefined4 FUN_10008e20(int param_1,tagVARIANT *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  CComVariant *pCVar3;
  int *piVar4;
  tagVARIANT *ptVar5;
  tagVARIANT local_44 [16];
  short local_34 [8];
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011b66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_3 == 0) {
    FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
  }
  local_18 = 0;
  COleVariant(local_34,param_2);
  local_8 = 0;
  FUN_1000b5d0(local_44);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000b530(&local_14);
  iVar2 = FUN_1000c3e0(param_1 + 4);
  if (iVar2 == 0) {
    ptVar5 = local_44;
    pCVar3 = (CComVariant *)FUN_1000b750((void *)(param_1 + 4),local_34);
    ATL::CComVariant::operator=(pCVar3,ptVar5);
  }
  else {
    piVar4 = FUN_1000c220((void *)(param_1 + 4),&local_20,local_34);
    local_14 = *piVar4;
    piVar4 = (int *)FUN_10007320((void *)(param_1 + 4),local_24);
    bVar1 = FUN_100035d0(&local_14,piVar4);
    if (bVar1) {
      iVar2 = FUN_1000b870(&local_14);
      local_18 = Ordinal_10(param_3,iVar2 + 0x10);
    }
    else {
      ptVar5 = local_44;
      pCVar3 = (CComVariant *)FUN_1000b750((void *)(param_1 + 4),local_34);
      ATL::CComVariant::operator=(pCVar3,ptVar5);
    }
  }
  local_1c = local_18;
  local_8 = local_8 & 0xffffff00;
  FUN_10003330(local_44);
  local_8 = 0xffffffff;
  FUN_10003330(local_34);
  ExceptionList = local_10;
  return local_1c;
}



// Function: FUN_10008f70 at 10008f70

undefined4 FUN_10008f70(int param_1,tagVARIANT *param_2,tagVARIANT *param_3)

{
  bool bVar1;
  int iVar2;
  CComVariant *pCVar3;
  undefined4 *puVar4;
  int *piVar5;
  tagVARIANT *ptVar6;
  tagVARIANT local_54 [16];
  tagVARIANT local_44 [16];
  short local_34 [8];
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011b99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  COleVariant(local_34,param_2);
  local_8 = 0;
  FUN_1000b530(&local_14);
  iVar2 = FUN_1000c3e0(param_1 + 4);
  if (iVar2 == 0) {
    COleVariant(local_44,param_3);
    local_8._0_1_ = 1;
    ptVar6 = local_44;
    pCVar3 = (CComVariant *)FUN_1000b750((void *)(param_1 + 4),local_34);
    ATL::CComVariant::operator=(pCVar3,ptVar6);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10003330(local_44);
  }
  else {
    puVar4 = FUN_1000c220((void *)(param_1 + 4),&local_20,local_34);
    local_14 = *puVar4;
    piVar5 = (int *)FUN_10007320((void *)(param_1 + 4),local_24);
    bVar1 = FUN_100035d0(&local_14,piVar5);
    if (bVar1) {
      FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
    }
    else {
      COleVariant(local_54,param_3);
      local_8._0_1_ = 2;
      ptVar6 = local_54;
      pCVar3 = (CComVariant *)FUN_1000b750((void *)(param_1 + 4),local_34);
      ATL::CComVariant::operator=(pCVar3,ptVar6);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10003330(local_54);
    }
  }
  local_1c = local_18;
  local_8 = 0xffffffff;
  FUN_10003330(local_34);
  ExceptionList = local_10;
  return local_1c;
}



// Function: FUN_100090c0 at 100090c0

undefined4 FUN_100090c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
  }
  uVar1 = FUN_1000c3e0(param_1 + 4);
  *param_2 = uVar1;
  return 0;
}



// Function: FUN_10009110 at 10009110

undefined4 FUN_10009110(int param_1,tagVARIANT *param_2,undefined2 *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  short local_30 [8];
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011bbc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  if (param_3 == (undefined2 *)0x0) {
    FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
  }
  iVar2 = FUN_1000c3e0(param_1 + 4);
  if (iVar2 == 0) {
    *param_3 = 0;
  }
  else {
    COleVariant(local_30,param_2);
    local_8 = 0;
    FUN_1000b530(&local_14);
    puVar3 = FUN_1000c220((void *)(param_1 + 4),&local_1c,local_30);
    local_14 = *puVar3;
    piVar4 = (int *)FUN_10007320((void *)(param_1 + 4),local_20);
    bVar1 = FUN_100035d0(&local_14,piVar4);
    if (bVar1) {
      *param_3 = 0xffff;
    }
    else {
      *param_3 = 0;
    }
    local_8 = 0xffffffff;
    FUN_10003330(local_30);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10009210 at 10009210

undefined4 FUN_10009210(int *param_1,tagVARIANT *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  CComVariant *pCVar3;
  int *piVar4;
  tagVARIANT *ptVar5;
  tagVARIANT local_6c [16];
  undefined1 local_5c [16];
  tagVARIANT local_4c [16];
  short local_3c [8];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011bf7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  COleVariant(local_3c,param_2);
  local_8 = 0;
  FUN_1000b530(&local_14);
  iVar2 = FUN_1000c3e0((int)(param_1 + 1));
  if (iVar2 == 0) {
    FUN_1000b5d0(local_4c);
    local_8._0_1_ = 1;
    ptVar5 = local_4c;
    pCVar3 = (CComVariant *)FUN_1000b750(param_1 + 1,local_3c);
    ATL::CComVariant::operator=(pCVar3,ptVar5);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10003330(local_4c);
  }
  else {
    piVar4 = FUN_1000c220(param_1 + 1,&local_24,local_3c);
    local_14 = *piVar4;
    piVar4 = (int *)FUN_10007320(param_1 + 1,local_28);
    bVar1 = FUN_100035d0(&local_14,piVar4);
    if (bVar1) {
      iVar2 = FUN_1000b8b0(&local_14);
      COleVariant(local_5c,(tagVARIANT *)(iVar2 + 0x10));
      local_8._0_1_ = 2;
      local_1c = local_14;
      FUN_10007400(local_2c,local_14);
      local_18 = (**(code **)(*param_1 + 0xc))(param_1,param_3,local_5c);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10003330(local_5c);
    }
    else {
      FUN_1000b5d0(local_6c);
      local_8._0_1_ = 3;
      ptVar5 = local_6c;
      pCVar3 = (CComVariant *)FUN_1000b750(param_1 + 1,local_3c);
      ATL::CComVariant::operator=(pCVar3,ptVar5);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10003330(local_6c);
    }
  }
  local_20 = local_18;
  local_8 = 0xffffffff;
  FUN_10003330(local_3c);
  ExceptionList = local_10;
  return local_20;
}



// Function: FUN_10009390 at 10009390

undefined4 FUN_10009390(int param_1,tagVARIANT *param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  short local_3c [8];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011c1a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 == (tagVARIANT *)0x0) {
    FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
  }
  local_1c = 0;
  COleVariant(local_3c,param_2);
  local_8 = 0;
  FUN_1000b530(&local_14);
  iVar2 = FUN_1000c3e0(param_1 + 4);
  if (iVar2 == 0) {
    FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
  }
  else {
    piVar3 = FUN_1000c220((void *)(param_1 + 4),&local_24,local_3c);
    local_14 = *piVar3;
    piVar3 = (int *)FUN_10007320((void *)(param_1 + 4),local_28);
    bVar1 = FUN_100035d0(&local_14,piVar3);
    if (bVar1) {
      local_18 = local_14;
      FUN_10007400(local_2c,local_14);
    }
    else {
      FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
    }
  }
  local_20 = local_1c;
  local_8 = 0xffffffff;
  FUN_10003330(local_3c);
  ExceptionList = local_10;
  return local_20;
}



// Function: FUN_100094e0 at 100094e0

undefined4 FUN_100094e0(int param_1)

{
  FUN_10007260((int *)(param_1 + 4));
  return 0;
}



// Function: FUN_10009500 at 10009500

undefined4 FUN_10009500(void)

{
  return 0x80004001;
}



// Function: FUN_10009520 at 10009520

undefined4 FUN_10009520(void)

{
  return 0x80004001;
}



// Function: FUN_10009540 at 10009540

undefined4 FUN_10009540(void)

{
  return 0x80004001;
}



// Function: FUN_10009560 at 10009560

undefined4 FUN_10009560(void)

{
  return 0x80004001;
}



// Function: FUN_10009580 at 10009580

undefined4 FUN_10009580(void)

{
  return 0x80004001;
}



// Function: FUN_100095a0 at 100095a0

undefined4 FUN_100095a0(int param_1,undefined2 *param_2)

{
  bool bVar1;
  int *piVar2;
  tagVARIANT *ptVar3;
  undefined1 local_6c [16];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined1 local_34 [8];
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011c4d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = 0;
  if (param_2 == (undefined2 *)0x0) {
    FUN_1000dd40((uchar *)"DictionaryImpl.cpp");
  }
  local_3c = 0;
  uStack_38 = FUN_1000c3e0(param_1 + 4);
  FUN_1000b600(local_34,1,0xc,(int)&local_3c);
  local_8 = 0;
  local_18 = 0;
  FUN_1000b530(&local_14);
  piVar2 = (int *)FUN_10007230((void *)(param_1 + 4),local_28);
  local_14 = *piVar2;
  while( true ) {
    piVar2 = (int *)FUN_10007320((void *)(param_1 + 4),local_2c);
    bVar1 = FUN_100035d0(&local_14,piVar2);
    if (!bVar1) break;
    FUN_1000b5d0(&local_5c);
    local_8._0_1_ = 1;
    ptVar3 = (tagVARIANT *)FUN_1000b870(&local_14);
    ATL::CComVariant::operator=((CComVariant *)&local_5c,ptVar3);
    local_4c = local_5c;
    local_48 = local_58;
    local_44 = local_54;
    local_40 = local_50;
    FUN_1000bca0(&local_18);
    local_18 = local_18 + 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_10003330(&local_5c);
    FUN_1000b8d0(&local_14);
  }
  FUN_1000b5d0(local_6c);
  local_8._0_1_ = 2;
  FUN_1000bae0(local_6c,param_2);
  local_1c = 0;
  FUN_1000bb40(local_34,&local_1c);
  *param_2 = 0x200c;
  *(undefined4 *)(param_2 + 4) = local_1c;
  local_24 = local_20;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10003330(local_6c);
  local_8 = 0xffffffff;
  FUN_1000b6d0((int)local_34);
  ExceptionList = local_10;
  return local_24;
}



// Function: FUN_10009770 at 10009770

void * __thiscall FUN_10009770(void *this,int param_1)

{
  tagVARIANT *ptVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011c83;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ptVar1 = (tagVARIANT *)FUN_1000b420(param_1);
  COleVariant(this,ptVar1);
  local_8 = 0;
  ptVar1 = (tagVARIANT *)FUN_1000b4a0(param_1 + 0x10);
  COleVariant((void *)((int)this + 0x10),ptVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100097f0 at 100097f0

void * __thiscall FUN_100097f0(void *this,undefined4 param_1,undefined4 param_2)

{
  tagVARIANT *ptVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011cb3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ptVar1 = (tagVARIANT *)FUN_1000b440(param_1);
  COleVariant(this,ptVar1);
  local_8 = 0;
  ptVar1 = (tagVARIANT *)FUN_1000b440(param_2);
  COleVariant((void *)((int)this + 0x10),ptVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10009870 at 10009870

undefined4 * __thiscall FUN_10009870(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_1000b450(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_1000b4b0(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_100098b0 at 100098b0

void * __thiscall FUN_100098b0(void *this,undefined4 param_1,undefined4 param_2)

{
  tagVARIANT *ptVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011ce3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ptVar1 = (tagVARIANT *)FUN_1000b460(param_1);
  COleVariant(this,ptVar1);
  local_8 = 0;
  ptVar1 = (tagVARIANT *)FUN_1000b4a0(param_2);
  COleVariant((void *)((int)this + 0x10),ptVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10009930 at 10009930

undefined4 * __thiscall FUN_10009930(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_1000b490(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_1000b4b0(param_1 + 4);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_10009970 at 10009970

undefined4 * __thiscall FUN_10009970(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_1000b490(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_1000b4b0(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_100099b0 at 100099b0

void * __thiscall FUN_100099b0(void *this,int param_1)

{
  tagVARIANT *ptVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011d13;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ptVar1 = (tagVARIANT *)FUN_1000b4a0(param_1);
  COleVariant(this,ptVar1);
  local_8 = 0;
  ptVar1 = (tagVARIANT *)FUN_1000b4a0(param_1 + 0x10);
  COleVariant((void *)((int)this + 0x10),ptVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10009a30 at 10009a30

void FUN_10009a30(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *this;
  uint uStack_30;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011d30;
  local_10 = ExceptionList;
  uStack_30 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  iVar1 = FUN_1000bed0();
  puVar2 = (undefined1 *)FUN_10006ad0(iVar1);
  *puVar2 = 0;
  puVar2 = (undefined1 *)FUN_10006d10(iVar1);
  *puVar2 = 0;
  local_8 = 0;
  uVar3 = forward<>(param_1);
  iVar1 = FUN_10006f80(iVar1);
  uVar4 = FUN_10001650(iVar1);
  this = (void *)FUN_10006c90(&local_15);
  construct<>(this,uVar4,uVar3);
  FUN_10009ae2();
  return;
}



// Function: Catch@10009ac7 at 10009ac7

void Catch_10009ac7(void)

{
  int unaff_EBP;
  
  FUN_1000c070(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10009ae2 at 10009ae2

undefined4 FUN_10009ae2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10009b10 at 10009b10

void FUN_10009b10(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *this;
  uint uStack_30;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011d50;
  local_10 = ExceptionList;
  uStack_30 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  iVar1 = FUN_1000bed0();
  puVar2 = (undefined1 *)FUN_10006ad0(iVar1);
  *puVar2 = 0;
  puVar2 = (undefined1 *)FUN_10006d10(iVar1);
  *puVar2 = 0;
  local_8 = 0;
  uVar3 = forward<>(param_1);
  iVar1 = FUN_10006f80(iVar1);
  uVar4 = FUN_10001650(iVar1);
  this = (void *)FUN_10006c90(&local_15);
  construct<>(this,uVar4,uVar3);
  FUN_10009bc2();
  return;
}



// Function: Catch@10009ba7 at 10009ba7

void Catch_10009ba7(void)

{
  int unaff_EBP;
  
  FUN_1000c070(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10009bc2 at 10009bc2

undefined4 FUN_10009bc2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10009bf0 at 10009bf0

undefined4 FUN_10009bf0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10009c00 at 10009c00

void FUN_10009c00(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = forward<>(param_2);
  FUN_10009a30(uVar1);
  return;
}



// Function: FUN_10009c30 at 10009c30

void * __thiscall
FUN_10009c30(void *this,void *param_1,char param_2,int param_3,undefined4 param_4,void *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int local_8;
  
  iVar2 = FUN_1000c330();
  if (iVar2 - 1U <= *(uint *)((int)this + 4)) {
    FUN_1000c000(param_5);
    std::_Xlength_error("map/set<T> too long");
  }
  FUN_1000b430(param_4);
  iVar2 = FUN_10009bf0(param_5);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  *(int *)(iVar2 + 4) = param_3;
                    /* WARNING: Load size is inaccurate */
  local_8 = iVar2;
  if (param_3 == *this) {
    piVar3 = (int *)FUN_10007010((int *)this);
    *piVar3 = iVar2;
    piVar3 = (int *)FUN_10006d50((undefined4 *)this);
    *piVar3 = iVar2;
    piVar3 = (int *)FUN_10006fe0((int *)this);
    *piVar3 = iVar2;
  }
  else if (param_2 == '\0') {
    piVar3 = (int *)FUN_10006fc0(param_3);
    *piVar3 = iVar2;
    piVar3 = (int *)FUN_10006fe0((int *)this);
    if (param_3 == *piVar3) {
      piVar3 = (int *)FUN_10006fe0((int *)this);
      *piVar3 = iVar2;
    }
  }
  else {
    piVar3 = (int *)FUN_10006d30(param_3);
    *piVar3 = iVar2;
    piVar3 = (int *)FUN_10006d50((undefined4 *)this);
    if (param_3 == *piVar3) {
      piVar3 = (int *)FUN_10006d50((undefined4 *)this);
      *piVar3 = iVar2;
    }
  }
  while( true ) {
    piVar3 = (int *)FUN_10006fa0(local_8);
    pcVar4 = (char *)FUN_10006ad0(*piVar3);
    if (*pcVar4 != '\0') break;
    piVar3 = (int *)FUN_10006fa0(local_8);
    piVar5 = (int *)FUN_10006fa0(local_8);
    puVar6 = (undefined4 *)FUN_10006fa0(*piVar5);
    piVar5 = (int *)FUN_10006d30(*puVar6);
    if (*piVar3 == *piVar5) {
      piVar3 = (int *)FUN_10006fa0(local_8);
      piVar3 = (int *)FUN_10006fa0(*piVar3);
      piVar3 = (int *)FUN_10006fc0(*piVar3);
      iVar1 = *piVar3;
      pcVar4 = (char *)FUN_10006ad0(iVar1);
      if (*pcVar4 == '\0') {
        piVar3 = (int *)FUN_10006fa0(local_8);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10006ad0(iVar1);
        *puVar7 = 1;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 0;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        local_8 = *piVar3;
      }
      else {
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fc0(*piVar3);
        if (local_8 == *piVar3) {
          piVar3 = (int *)FUN_10006fa0(local_8);
          local_8 = *piVar3;
          FUN_10006d80(this,local_8);
        }
        piVar3 = (int *)FUN_10006fa0(local_8);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 1;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 0;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        FUN_10007040(this,*piVar3);
      }
    }
    else {
      piVar3 = (int *)FUN_10006fa0(local_8);
      puVar6 = (undefined4 *)FUN_10006fa0(*piVar3);
      piVar3 = (int *)FUN_10006d30(*puVar6);
      iVar1 = *piVar3;
      pcVar4 = (char *)FUN_10006ad0(iVar1);
      if (*pcVar4 == '\0') {
        piVar3 = (int *)FUN_10006fa0(local_8);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10006ad0(iVar1);
        *puVar7 = 1;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 0;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        local_8 = *piVar3;
      }
      else {
        puVar6 = (undefined4 *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006d30(*puVar6);
        if (local_8 == *piVar3) {
          piVar3 = (int *)FUN_10006fa0(local_8);
          local_8 = *piVar3;
          FUN_10007040(this,local_8);
        }
        piVar3 = (int *)FUN_10006fa0(local_8);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 1;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
        *puVar7 = 0;
        piVar3 = (int *)FUN_10006fa0(local_8);
        piVar3 = (int *)FUN_10006fa0(*piVar3);
        FUN_10006d80(this,*piVar3);
      }
    }
  }
  piVar3 = (int *)FUN_10007010((int *)this);
  puVar7 = (undefined1 *)FUN_10006ad0(*piVar3);
  *puVar7 = 1;
  FUN_10002130(param_1,iVar2);
  return param_1;
}



// Function: FUN_1000a060 at 1000a060

void * __thiscall
FUN_1000a060(void *this,void *param_1,char param_2,int param_3,undefined4 param_4,byte param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  int local_8;
  
  iVar2 = FUN_1000c330();
  if (iVar2 - 1U <= *(uint *)((int)this + 4)) {
    FUN_1000c060();
    std::_Xlength_error("map/set<T> too long");
  }
  uVar3 = forward<>(param_4);
  iVar2 = FUN_10009c00((uint)param_5,uVar3);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  *(int *)(iVar2 + 4) = param_3;
                    /* WARNING: Load size is inaccurate */
  local_8 = iVar2;
  if (param_3 == *this) {
    piVar4 = (int *)FUN_10007010((int *)this);
    *piVar4 = iVar2;
    piVar4 = (int *)FUN_10006d50((undefined4 *)this);
    *piVar4 = iVar2;
    piVar4 = (int *)FUN_10006fe0((int *)this);
    *piVar4 = iVar2;
  }
  else if (param_2 == '\0') {
    piVar4 = (int *)FUN_10006fc0(param_3);
    *piVar4 = iVar2;
    piVar4 = (int *)FUN_10006fe0((int *)this);
    if (param_3 == *piVar4) {
      piVar4 = (int *)FUN_10006fe0((int *)this);
      *piVar4 = iVar2;
    }
  }
  else {
    piVar4 = (int *)FUN_10006d30(param_3);
    *piVar4 = iVar2;
    piVar4 = (int *)FUN_10006d50((undefined4 *)this);
    if (param_3 == *piVar4) {
      piVar4 = (int *)FUN_10006d50((undefined4 *)this);
      *piVar4 = iVar2;
    }
  }
  while( true ) {
    piVar4 = (int *)FUN_10006fa0(local_8);
    pcVar5 = (char *)FUN_10006ad0(*piVar4);
    if (*pcVar5 != '\0') break;
    piVar4 = (int *)FUN_10006fa0(local_8);
    piVar6 = (int *)FUN_10006fa0(local_8);
    puVar7 = (undefined4 *)FUN_10006fa0(*piVar6);
    piVar6 = (int *)FUN_10006d30(*puVar7);
    if (*piVar4 == *piVar6) {
      piVar4 = (int *)FUN_10006fa0(local_8);
      piVar4 = (int *)FUN_10006fa0(*piVar4);
      piVar4 = (int *)FUN_10006fc0(*piVar4);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_10006ad0(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_10006fa0(local_8);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 1;
        puVar8 = (undefined1 *)FUN_10006ad0(iVar1);
        *puVar8 = 1;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 0;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        local_8 = *piVar4;
      }
      else {
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fc0(*piVar4);
        if (local_8 == *piVar4) {
          piVar4 = (int *)FUN_10006fa0(local_8);
          local_8 = *piVar4;
          FUN_10006d80(this,local_8);
        }
        piVar4 = (int *)FUN_10006fa0(local_8);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 1;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 0;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        FUN_10007040(this,*piVar4);
      }
    }
    else {
      piVar4 = (int *)FUN_10006fa0(local_8);
      puVar7 = (undefined4 *)FUN_10006fa0(*piVar4);
      piVar4 = (int *)FUN_10006d30(*puVar7);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_10006ad0(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_10006fa0(local_8);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 1;
        puVar8 = (undefined1 *)FUN_10006ad0(iVar1);
        *puVar8 = 1;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 0;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        local_8 = *piVar4;
      }
      else {
        puVar7 = (undefined4 *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006d30(*puVar7);
        if (local_8 == *piVar4) {
          piVar4 = (int *)FUN_10006fa0(local_8);
          local_8 = *piVar4;
          FUN_10007040(this,local_8);
        }
        piVar4 = (int *)FUN_10006fa0(local_8);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 1;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
        *puVar8 = 0;
        piVar4 = (int *)FUN_10006fa0(local_8);
        piVar4 = (int *)FUN_10006fa0(*piVar4);
        FUN_10006d80(this,*piVar4);
      }
    }
  }
  piVar4 = (int *)FUN_10007010((int *)this);
  puVar8 = (undefined1 *)FUN_10006ad0(*piVar4);
  *puVar8 = 1;
  FUN_10002130(param_1,iVar2);
  return param_1;
}



// Function: FUN_1000a490 at 1000a490

/* WARNING: Removing unreachable block (ram,0x1000a518) */
/* WARNING: Removing unreachable block (ram,0x1000a5a6) */
/* WARNING: Removing unreachable block (ram,0x1000a634) */
/* WARNING: Removing unreachable block (ram,0x1000a671) */
/* WARNING: Removing unreachable block (ram,0x1000a6bb) */
/* WARNING: Removing unreachable block (ram,0x1000a710) */
/* WARNING: Removing unreachable block (ram,0x1000a6de) */
/* WARNING: Removing unreachable block (ram,0x1000a745) */
/* WARNING: Removing unreachable block (ram,0x1000a782) */
/* WARNING: Removing unreachable block (ram,0x1000a7ab) */
/* WARNING: Removing unreachable block (ram,0x1000a7e8) */
/* WARNING: Removing unreachable block (ram,0x1000a83d) */
/* WARNING: Removing unreachable block (ram,0x1000a80b) */
/* WARNING: Removing unreachable block (ram,0x1000a86f) */
/* WARNING: Removing unreachable block (ram,0x1000a5c2) */
/* WARNING: Removing unreachable block (ram,0x1000a5fd) */
/* WARNING: Removing unreachable block (ram,0x1000a62f) */
/* WARNING: Removing unreachable block (ram,0x1000a534) */
/* WARNING: Removing unreachable block (ram,0x1000a56d) */
/* WARNING: Removing unreachable block (ram,0x1000a59d) */
/* WARNING: Removing unreachable block (ram,0x1000a873) */

void * FUN_1000a490(void *param_1,int param_2,undefined4 param_3,void *param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  short *psVar6;
  char *pcVar7;
  int *this;
  void *pvVar8;
  uint uStack_5c;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [16];
  int local_2c;
  int *local_28;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c [7];
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011d70;
  local_10 = ExceptionList;
  uStack_5c = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_5c;
  ExceptionList = &local_10;
  FUN_1000b510(&local_2c);
  local_15 = 0;
  local_8 = 0;
  iVar3 = FUN_1000c3e0((int)local_28);
  if (iVar3 == 0) {
    pvVar8 = param_4;
    uVar4 = FUN_1000b430(param_3);
    FUN_10009c30(local_28,param_1,'\x01',*local_28,uVar4,pvVar8);
    ExceptionList = local_10;
    return param_1;
  }
  piVar5 = (int *)FUN_10007230(local_28,local_3c);
  bVar1 = FUN_10003570(&param_2,piVar5);
  if (bVar1) {
    iVar3 = FUN_10006f60(&param_2);
    psVar6 = (short *)FUN_1000c130(iVar3);
    pvVar8 = (void *)FUN_1000c160(param_3);
    FUN_1000c120(local_1c);
    cVar2 = FUN_1000ba80(pvVar8,psVar6);
    if (cVar2 != '\0') {
      pvVar8 = param_4;
      uVar4 = FUN_1000b430(param_3);
      iVar3 = FUN_10006f60(&param_2);
      FUN_10009c30(local_28,param_1,'\x01',iVar3,uVar4,pvVar8);
      ExceptionList = local_10;
      return param_1;
    }
  }
  else {
    piVar5 = (int *)FUN_10007320(local_28,local_40);
    bVar1 = FUN_10003570(&param_2,piVar5);
    if (bVar1) {
      psVar6 = (short *)FUN_1000c160(param_3);
      piVar5 = (int *)FUN_10006fe0(local_28);
      pvVar8 = (void *)FUN_1000c130(*piVar5);
      FUN_1000c120(&local_1d);
      cVar2 = FUN_1000ba80(pvVar8,psVar6);
      if (cVar2 != '\0') {
        pvVar8 = param_4;
        uVar4 = FUN_1000b430(param_3);
        piVar5 = (int *)FUN_10006fe0(local_28);
        FUN_10009c30(local_28,param_1,'\0',*piVar5,uVar4,pvVar8);
        ExceptionList = local_10;
        return param_1;
      }
    }
    else {
      iVar3 = FUN_10006f60(&param_2);
      psVar6 = (short *)FUN_1000c130(iVar3);
      pvVar8 = (void *)FUN_1000c160(param_3);
      FUN_1000c120(&local_1e);
      cVar2 = FUN_1000ba80(pvVar8,psVar6);
      if (cVar2 != '\0') {
        local_2c = param_2;
        psVar6 = (short *)FUN_1000c160(param_3);
        piVar5 = FUN_1000b8f0(&local_2c);
        iVar3 = FUN_10006f60(piVar5);
        pvVar8 = (void *)FUN_1000c130(iVar3);
        FUN_1000c120(&local_1f);
        cVar2 = FUN_1000ba80(pvVar8,psVar6);
        if (cVar2 != '\0') {
          iVar3 = FUN_10006f60(&local_2c);
          piVar5 = (int *)FUN_10006fc0(iVar3);
          pcVar7 = (char *)FUN_10006d10(*piVar5);
          if (*pcVar7 != '\0') {
            pvVar8 = param_4;
            uVar4 = FUN_1000b430(param_3);
            iVar3 = FUN_10006f60(&local_2c);
            FUN_10009c30(local_28,param_1,'\0',iVar3,uVar4,pvVar8);
            ExceptionList = local_10;
            return param_1;
          }
          pvVar8 = param_4;
          uVar4 = FUN_1000b430(param_3);
          iVar3 = FUN_10006f60(&param_2);
          FUN_10009c30(local_28,param_1,'\x01',iVar3,uVar4,pvVar8);
          ExceptionList = local_10;
          return param_1;
        }
      }
      psVar6 = (short *)FUN_1000c160(param_3);
      iVar3 = FUN_10006f60(&param_2);
      pvVar8 = (void *)FUN_1000c130(iVar3);
      FUN_1000c120(&local_20);
      cVar2 = FUN_1000ba80(pvVar8,psVar6);
      if (cVar2 != '\0') {
        local_2c = param_2;
        piVar5 = (int *)FUN_10007320(local_28,local_44);
        this = FUN_100037a0(&local_2c);
        bVar1 = FUN_10003570(this,piVar5);
        if (!bVar1) {
          iVar3 = FUN_10006f60(&local_2c);
          psVar6 = (short *)FUN_1000c130(iVar3);
          pvVar8 = (void *)FUN_1000c160(param_3);
          FUN_1000c120(&local_21);
          cVar2 = FUN_1000ba80(pvVar8,psVar6);
          if (cVar2 == '\0') goto LAB_1000abc6;
        }
        iVar3 = FUN_10006f60(&param_2);
        piVar5 = (int *)FUN_10006fc0(iVar3);
        pcVar7 = (char *)FUN_10006d10(*piVar5);
        if (*pcVar7 != '\0') {
          pvVar8 = param_4;
          uVar4 = FUN_1000b430(param_3);
          iVar3 = FUN_10006f60(&param_2);
          FUN_10009c30(local_28,param_1,'\0',iVar3,uVar4,pvVar8);
          ExceptionList = local_10;
          return param_1;
        }
        pvVar8 = param_4;
        uVar4 = FUN_1000b430(param_3);
        iVar3 = FUN_10006f60(&local_2c);
        FUN_10009c30(local_28,param_1,'\x01',iVar3,uVar4,pvVar8);
        ExceptionList = local_10;
        return param_1;
      }
    }
  }
LAB_1000abc6:
  pvVar8 = (void *)FUN_1000abe3();
  return pvVar8;
}



// Function: Catch@1000abc8 at 1000abc8

void Catch_1000abc8(void)

{
  int unaff_EBP;
  
  FUN_1000c000(*(void **)(unaff_EBP + 0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000abe3 at 1000abe3

undefined4 FUN_1000abe3(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  void *pvVar3;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pvVar3 = *(void **)(unaff_EBP + 0x14);
  uVar1 = FUN_1000b430(*(undefined4 *)(unaff_EBP + 0x10));
  puVar2 = (undefined4 *)
           FUN_1000ac40(*(void **)(unaff_EBP + -0x24),(void *)(unaff_EBP + -0x48),
                        *(char *)(unaff_EBP + -0x11),uVar1,pvVar3);
  **(undefined4 **)(unaff_EBP + 8) = *puVar2;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}



// Function: FUN_1000ac40 at 1000ac40

/* WARNING: Removing unreachable block (ram,0x1000ad6b) */

void __thiscall FUN_1000ac40(void *this,void *param_1,char param_2,undefined4 param_3,void *param_4)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  char *pcVar4;
  short *psVar5;
  void *pvVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  uint uStack_74;
  undefined1 local_64 [8];
  undefined1 local_5c [8];
  undefined1 local_54 [16];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [8];
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17 [2];
  char local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011d90;
  local_10 = ExceptionList;
  uStack_74 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_74;
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = (int *)this;
  piVar3 = (int *)FUN_10007010((int *)this);
  local_24 = *piVar3;
  local_28 = *local_20;
  local_15 = '\x01';
  while (pcVar4 = (char *)FUN_10006d10(local_24), *pcVar4 == '\0') {
    local_28 = local_24;
    if (param_2 == '\0') {
      psVar5 = (short *)FUN_1000c130(local_24);
      pvVar6 = (void *)FUN_1000c160(param_3);
      FUN_1000c120(&local_1b);
      local_15 = FUN_1000ba80(pvVar6,psVar5);
    }
    else {
      psVar5 = (short *)FUN_1000c160(param_3);
      pvVar6 = (void *)FUN_1000c130(local_24);
      FUN_1000c120(&local_1a);
      cVar1 = FUN_1000ba80(pvVar6,psVar5);
      local_15 = cVar1 == '\0';
      local_30 = (uint)(byte)local_15;
    }
    if (local_15 == '\0') {
      piVar3 = (int *)FUN_10006fc0(local_24);
      local_34 = *piVar3;
    }
    else {
      piVar3 = (int *)FUN_10006d30(local_24);
      local_34 = *piVar3;
    }
    local_24 = local_34;
  }
  FUN_10002130(&local_2c,local_28);
  if (local_15 != '\0') {
    piVar3 = (int *)FUN_10007230(local_20,local_3c);
    bVar2 = FUN_10003570(&local_2c,piVar3);
    if (bVar2) {
      local_17[0] = 1;
      puVar10 = local_17;
      uVar8 = FUN_1000b430(param_3);
      pvVar6 = FUN_10009c30(local_20,local_40,'\x01',local_28,uVar8,param_4);
      puVar9 = FUN_10009970(local_54,pvVar6,puVar10);
      FUN_10009930(param_1,(int)puVar9);
      FUN_1000af28();
      return;
    }
    FUN_1000b910(&local_2c);
  }
  psVar5 = (short *)FUN_1000c160(param_3);
  iVar7 = FUN_10006f60(&local_2c);
  pvVar6 = (void *)FUN_1000c130(iVar7);
  FUN_1000c120(&local_1c);
  cVar1 = FUN_1000ba80(pvVar6,psVar5);
  if (cVar1 == '\0') {
    FUN_1000c000(param_4);
    local_19 = 0;
    puVar9 = FUN_10009870(local_64,&local_2c,&local_19);
    FUN_10009930(param_1,(int)puVar9);
    FUN_1000af28();
    return;
  }
  local_18 = 1;
  puVar10 = &local_18;
  uVar8 = FUN_1000b430(param_3);
  pvVar6 = FUN_10009c30(local_20,local_44,local_15,local_28,uVar8,param_4);
  puVar9 = FUN_10009970(local_5c,pvVar6,puVar10);
  FUN_10009930(param_1,(int)puVar9);
  FUN_1000af28();
  return;
}



// Function: Catch@1000aefd at 1000aefd

void Catch_1000aefd(void)

{
  int unaff_EBP;
  
  FUN_1000c000(*(void **)(unaff_EBP + 0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000af28 at 1000af28

void FUN_1000af28(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000af40 at 1000af40

/* WARNING: Removing unreachable block (ram,0x1000b06b) */

void __thiscall FUN_1000af40(void *this,void *param_1,char param_2,undefined4 param_3,byte param_4)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  char *pcVar4;
  short *psVar5;
  void *pvVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  uint uStack_74;
  undefined1 local_64 [8];
  undefined1 local_5c [8];
  undefined1 local_54 [16];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [8];
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17 [2];
  char local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10011db0;
  local_10 = ExceptionList;
  uStack_74 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_74;
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = (int *)this;
  piVar3 = (int *)FUN_10007010((int *)this);
  local_24 = *piVar3;
  local_28 = *local_20;
  local_15 = '\x01';
  while (pcVar4 = (char *)FUN_10006d10(local_24), *pcVar4 == '\0') {
    local_28 = local_24;
    if (param_2 == '\0') {
      psVar5 = (short *)FUN_1000c130(local_24);
      pvVar6 = (void *)FUN_1000c160(param_3);
      FUN_1000c120(&local_1b);
      local_15 = FUN_1000ba80(pvVar6,psVar5);
    }
    else {
      psVar5 = (short *)FUN_1000c160(param_3);
      pvVar6 = (void *)FUN_1000c130(local_24);
      FUN_1000c120(&local_1a);
      cVar1 = FUN_1000ba80(pvVar6,psVar5);
      local_15 = cVar1 == '\0';
      local_30 = (uint)(byte)local_15;
    }
    if (local_15 == '\0') {
      piVar3 = (int *)FUN_10006fc0(local_24);
      local_34 = *piVar3;
    }
    else {
      piVar3 = (int *)FUN_10006d30(local_24);
      local_34 = *piVar3;
    }
    local_24 = local_34;
  }
  FUN_10002130(&local_2c,local_28);
  if (local_15 != '\0') {
    piVar3 = (int *)FUN_10007230(local_20,local_3c);
    bVar2 = FUN_10003570(&local_2c,piVar3);
    if (bVar2) {
      local_17[0] = 1;
      puVar10 = local_17;
      uVar8 = forward<>(param_3);
      pvVar6 = FUN_1000a060(local_20,local_40,'\x01',local_28,uVar8,param_4);
      puVar9 = FUN_10009970(local_54,pvVar6,puVar10);
      FUN_10009930(param_1,(int)puVar9);
      FUN_1000b22d();
      return;
    }
    FUN_1000b910(&local_2c);
  }
  psVar5 = (short *)FUN_1000c160(param_3);
  iVar7 = FUN_10006f60(&local_2c);
  pvVar6 = (void *)FUN_1000c130(iVar7);
  FUN_1000c120(&local_1c);
  cVar1 = FUN_1000ba80(pvVar6,psVar5);
  if (cVar1 == '\0') {
    FUN_1000c060();
    local_19 = 0;
    puVar9 = FUN_10009870(local_64,&local_2c,&local_19);
    FUN_10009930(param_1,(int)puVar9);
    FUN_1000b22d();
    return;
  }
  local_18 = 1;
  puVar10 = &local_18;
  uVar8 = forward<>(param_3);
  pvVar6 = FUN_1000a060(local_20,local_44,local_15,local_28,uVar8,param_4);
  puVar9 = FUN_10009970(local_5c,pvVar6,puVar10);
  FUN_10009930(param_1,(int)puVar9);
  FUN_1000b22d();
  return;
}



// Function: Catch@1000b201 at 1000b201

void Catch_1000b201(void)

{
  FUN_1000c060();
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000b22d at 1000b22d

void FUN_1000b22d(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000b250 at 1000b250

undefined4 __cdecl FUN_1000b250(undefined4 param_1)

{
  return param_1;
}



// Function: construct<> at 1000b260

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



// Function: FUN_1000b290 at 1000b290

void FUN_1000b290(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011de1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_100034d0(0x20,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = forward<>(param_2);
    FUN_10009770(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: construct<> at 1000b320

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
  undefined4 uVar1;
  
  uVar1 = forward<>(param_3);
  FUN_1000b290(param_2,uVar1);
  return;
}



// Function: construct<> at 1000b340

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



// Function: FUN_1000b370 at 1000b370

void FUN_1000b370(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011e11;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_100034d0(0x20,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = forward<>(param_2);
    FUN_100099b0(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: construct<> at 1000b400

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
  undefined4 uVar1;
  
  uVar1 = forward<>(param_3);
  FUN_1000b370(param_2,uVar1);
  return;
}



// Function: FUN_1000b420 at 1000b420

undefined4 __cdecl FUN_1000b420(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b430 at 1000b430

undefined4 __cdecl FUN_1000b430(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b440 at 1000b440

undefined4 __cdecl FUN_1000b440(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b450 at 1000b450

undefined4 __cdecl FUN_1000b450(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b460 at 1000b460

undefined4 __cdecl FUN_1000b460(undefined4 param_1)

{
  return param_1;
}



// Function: forward<> at 1000b470

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



// Function: forward<> at 1000b480

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



// Function: FUN_1000b490 at 1000b490

undefined4 __cdecl FUN_1000b490(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b4a0 at 1000b4a0

undefined4 __cdecl FUN_1000b4a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b4b0 at 1000b4b0

undefined4 __cdecl FUN_1000b4b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b4c0 at 1000b4c0

void * FUN_1000b4c0(void *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = forward<>(param_3);
  pvVar2 = (void *)FUN_10009b10(uVar1);
  iVar3 = FUN_10006f80((int)pvVar2);
  FUN_1000a490(param_1,param_2,iVar3,pvVar2);
  return param_1;
}



// Function: FUN_1000b510 at 1000b510

undefined4 * __fastcall FUN_1000b510(undefined4 *param_1)

{
  FUN_1000b550(param_1);
  return param_1;
}



// Function: FUN_1000b530 at 1000b530

undefined4 * __fastcall FUN_1000b530(undefined4 *param_1)

{
  FUN_1000b510(param_1);
  return param_1;
}



// Function: FUN_1000b550 at 1000b550

undefined4 * __fastcall FUN_1000b550(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: COleVariant at 1000b570

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall COleVariant::COleVariant(class ATL::CStringT<char,class
   StrTraitMFC<char,class ATL::ChTraitsCRT<char> > > &)
    public: __thiscall COleVariant::COleVariant(class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > &)
    public: __thiscall COleVariant::COleVariant(class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsOS<wchar_t> > > &)
    public: __thiscall COleVariant::COleVariant(class CArray<unsigned char,unsigned char> const &)
     8 names - too many to list
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

CComVariant * __thiscall COleVariant(void *this,tagVARIANT *param_1)

{
  *(undefined2 *)this = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)this,param_1);
  return (CComVariant *)this;
}



// Function: COleVariant at 1000b5a0

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall COleVariant::COleVariant(class ATL::CStringT<char,class
   StrTraitMFC<char,class ATL::ChTraitsCRT<char> > > &)
    public: __thiscall COleVariant::COleVariant(class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > &)
    public: __thiscall COleVariant::COleVariant(class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsOS<wchar_t> > > &)
    public: __thiscall COleVariant::COleVariant(class CArray<unsigned char,unsigned char> const &)
     8 names - too many to list
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

CComVariant * __thiscall COleVariant(void *this,tagVARIANT *param_1)

{
  *(undefined2 *)this = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)this,param_1);
  return (CComVariant *)this;
}



// Function: FUN_1000b5d0 at 1000b5d0

void * __fastcall FUN_1000b5d0(void *param_1)

{
  memset(param_1,0,0x10);
  Ordinal_8(param_1);
  return param_1;
}



// Function: FUN_1000b600 at 1000b600

uint * __thiscall FUN_1000b600(void *this,uint param_1,undefined2 param_2,int param_3)

{
  *(uint *)this = param_1;
  FUN_1000bb80(this,param_1,param_2,param_3);
  return (uint *)this;
}



// Function: FUN_1000b630 at 1000b630

void * __thiscall FUN_1000b630(void *this,undefined4 param_1)

{
  int iVar1;
  
  Ordinal_8(this);
  iVar1 = Ordinal_10(this,param_1);
  FUN_1000baa0(iVar1);
  return this;
}



// Function: ~_ExceptionPtr_static<> at 1000b670

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
  
  puStack_c = &LAB_10011e43;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10003330(param_1 + 0x10);
  local_8 = 0xffffffff;
  FUN_10003330(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b6d0 at 1000b6d0

void __fastcall FUN_1000b6d0(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    Ordinal_16(*(undefined4 *)(param_1 + 4));
  }
  return;
}



// Function: FUN_1000b700 at 1000b700

void __fastcall FUN_1000b700(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: operator= at 1000b720

/* Library Function - Single Match
    public: class ATL::CComVariant & __thiscall ATL::CComVariant::operator=(struct tagVARIANT const
   &)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

CComVariant * __thiscall ATL::CComVariant::operator=(CComVariant *this,tagVARIANT *param_1)

{
  if (this != (CComVariant *)param_1) {
    InternalCopy(this,param_1);
  }
  return this;
}



// Function: FUN_1000b750 at 1000b750

int __thiscall FUN_1000b750(void *this,short *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  undefined1 local_68 [32];
  undefined1 local_48 [16];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  int local_30;
  void *local_2c;
  void *local_28;
  void *local_24;
  void *local_20;
  int local_1c;
  void *local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011e70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = this;
  FUN_1000c300(this,&local_1c,param_1);
  piVar3 = (int *)FUN_10007320(local_18,local_34);
  bVar1 = FUN_10003570(&local_1c,piVar3);
  if (!bVar1) {
    iVar4 = FUN_10006f60(&local_1c);
    psVar5 = (short *)FUN_1000c130(iVar4);
    psVar6 = param_1;
    FUN_1000c120(&local_11);
    cVar2 = FUN_1000ba80(psVar6,psVar5);
    if (cVar2 == '\0') goto LAB_1000b845;
  }
  local_30 = local_1c;
  local_24 = FUN_1000b5d0(local_48);
  local_8 = 0;
  local_20 = local_24;
  local_2c = FUN_100098b0(local_68,param_1,local_24);
  local_8._0_1_ = 1;
  local_28 = local_2c;
  piVar3 = (int *)FUN_1000b4c0(local_38,local_30,local_2c);
  local_1c = *piVar3;
  local_8 = (uint)local_8._1_3_ << 8;
  ~_ExceptionPtr_static<>((int)local_68);
  local_8 = 0xffffffff;
  FUN_10003330(local_48);
LAB_1000b845:
  iVar4 = FUN_1000b870(&local_1c);
  ExceptionList = local_10;
  return iVar4 + 0x10;
}



// Function: FUN_1000b870 at 1000b870

void __fastcall FUN_1000b870(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1000b8b0(param_1);
  FUN_1000c3c0(uVar1);
  return;
}



// Function: FUN_1000b890 at 1000b890

void __fastcall FUN_1000b890(int *param_1)

{
  FUN_10006f80(*param_1);
  return;
}



// Function: FUN_1000b8b0 at 1000b8b0

void __fastcall FUN_1000b8b0(int *param_1)

{
  FUN_1000b890(param_1);
  return;
}



// Function: FUN_1000b8d0 at 1000b8d0

int * __fastcall FUN_1000b8d0(int *param_1)

{
  FUN_100037a0(param_1);
  return param_1;
}



// Function: FUN_1000b8f0 at 1000b8f0

int * __fastcall FUN_1000b8f0(int *param_1)

{
  FUN_1000b930(param_1);
  return param_1;
}



// Function: FUN_1000b910 at 1000b910

int * __fastcall FUN_1000b910(int *param_1)

{
  FUN_1000b8f0(param_1);
  return param_1;
}



// Function: FUN_1000b930 at 1000b930

int * __fastcall FUN_1000b930(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  
  pcVar1 = (char *)FUN_10006d10(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_10006d30(*param_1);
    pcVar1 = (char *)FUN_10006d10(*piVar2);
    if (*pcVar1 == '\0') {
      piVar2 = (int *)FUN_10006d30(*param_1);
      iVar3 = FUN_10006ec0(*piVar2);
      *param_1 = iVar3;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_10006fa0(*param_1);
        iVar3 = *piVar2;
        pcVar1 = (char *)FUN_10006d10(iVar3);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_10006d30(iVar3), *param_1 != *piVar2)) break;
        *param_1 = iVar3;
      }
      pcVar1 = (char *)FUN_10006d10(*param_1);
      if (*pcVar1 == '\0') {
        *param_1 = iVar3;
      }
    }
  }
  else {
    piVar2 = (int *)FUN_10006fc0(*param_1);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_1000ba20 at 1000ba20

bool __thiscall FUN_1000ba20(void *this,short *param_1)

{
  int iVar1;
  bool bVar2;
  
                    /* WARNING: Load size is inaccurate */
  if ((*this == 1) && (*param_1 == 1)) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_1000bd30(this,(int)this,(int)param_1,0x400,0);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



// Function: FUN_1000ba80 at 1000ba80

void FUN_1000ba80(void *param_1,short *param_2)

{
  FUN_1000ba20(param_1,param_2);
  return;
}



// Function: FUN_1000baa0 at 1000baa0

void __cdecl FUN_1000baa0(int param_1)

{
  if (param_1 < 0) {
    _com_issue_error(param_1);
  }
  return;
}



// Function: Copy at 1000bac0

/* Library Function - Single Match
    public: long __thiscall ATL::CComVariant::Copy(struct tagVARIANT const *)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

long __thiscall ATL::CComVariant::Copy(CComVariant *this,tagVARIANT *param_1)

{
  long lVar1;
  
  lVar1 = Ordinal_10(this,param_1);
  return lVar1;
}



// Function: FUN_1000bae0 at 1000bae0

int __thiscall FUN_1000bae0(void *this,void *param_1)

{
  undefined4 local_8;
  
  if (param_1 == (void *)0x0) {
    local_8 = -0x7fffbffd;
  }
  else {
    local_8 = Ordinal_9(param_1);
    if (-1 < local_8) {
      FUN_1000c390(param_1,0x10,this,0x10);
      *(undefined2 *)this = 0;
      local_8 = 0;
    }
  }
  return local_8;
}



// Function: FUN_1000bb40 at 1000bb40

undefined4 __thiscall FUN_1000bb40(void *this,undefined4 *param_1)

{
  undefined4 local_8;
  
  local_8 = 0x80004005;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    local_8 = Ordinal_27(*(undefined4 *)((int)this + 4),param_1);
  }
  return local_8;
}



// Function: FUN_1000bb80 at 1000bb80

undefined4 __thiscall FUN_1000bb80(void *this,uint param_1,undefined2 param_2,int param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 local_14;
  int local_8;
  
  local_14 = 0x80004005;
  *(uint *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  pvVar1 = (void *)FUN_1000fcfc(-(uint)((int)((ulonglong)*this * 8 >> 0x20) != 0) |
                                (uint)((ulonglong)*this * 8));
                    /* WARNING: Load size is inaccurate */
  for (local_8 = 0; local_8 < *this; local_8 = local_8 + 1) {
    *(undefined4 *)((int)pvVar1 + local_8 * 8 + 4) = *(undefined4 *)(param_3 + local_8 * 8);
    *(undefined4 *)((int)pvVar1 + local_8 * 8) = *(undefined4 *)(param_3 + 4 + local_8 * 8);
  }
                    /* WARNING: Load size is inaccurate */
  uVar2 = Ordinal_15(param_2,*this,pvVar1);
  *(undefined4 *)((int)this + 4) = uVar2;
  operator_delete__(pvVar1);
  if (*(int *)((int)this + 4) != 0) {
    local_14 = 0;
  }
  return local_14;
}



// Function: InternalCopy at 1000bc50

/* Library Function - Single Match
    public: void __thiscall ATL::CComVariant::InternalCopy(struct tagVARIANT const *)
   
   Libraries: Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall ATL::CComVariant::InternalCopy(CComVariant *this,tagVARIANT *param_1)

{
  long lVar1;
  
  lVar1 = Copy(this,param_1);
  if (lVar1 < 0) {
    *(undefined2 *)this = 10;
    *(long *)(this + 8) = lVar1;
    FUN_10003fa0(lVar1);
  }
  return;
}



// Function: FUN_1000bca0 at 1000bca0

undefined4 FUN_1000bca0(undefined4 param_1)

{
  uint uVar1;
  undefined1 local_2c [16];
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011e98;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0x80004005;
  FUN_1000b630(local_2c,&stack0x00000008);
  local_8 = 0;
  local_1c = Ordinal_26(*(undefined4 *)(local_18 + 4),param_1,local_2c,uVar1);
  local_8 = 0xffffffff;
  local_14 = local_1c;
  FUN_1000b700(local_2c);
  ExceptionList = local_10;
  return local_1c;
}



// Function: FUN_1000bd30 at 1000bd30

undefined4 __thiscall
FUN_1000bd30(void *this,int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_28;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* WARNING: Load size is inaccurate */
  switch(*this) {
  case 0x10:
    if (*(char *)(param_1 + 8) == *(char *)(param_2 + 8)) {
      local_28 = 1;
    }
    else if (*(char *)(param_2 + 8) < *(char *)(param_1 + 8)) {
      local_c = 2;
      local_28 = local_c;
    }
    else {
      local_c = 0;
      local_28 = local_c;
    }
    break;
  default:
    local_28 = Ordinal_176(param_1,param_2,param_3,param_4);
    break;
  case 0x12:
    if (*(short *)(param_1 + 8) == *(short *)(param_2 + 8)) {
      local_28 = 1;
    }
    else if (*(ushort *)(param_2 + 8) < *(ushort *)(param_1 + 8)) {
      local_10 = 2;
      local_28 = local_10;
    }
    else {
      local_10 = 0;
      local_28 = local_10;
    }
    break;
  case 0x13:
    if (*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) {
      local_28 = 1;
    }
    else if (*(uint *)(param_2 + 8) < *(uint *)(param_1 + 8)) {
      local_14 = 2;
      local_28 = local_14;
    }
    else {
      local_14 = 0;
      local_28 = local_14;
    }
    break;
  case 0x15:
    if ((*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) &&
       (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) {
      local_28 = 1;
    }
    else if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_2 + 0xc)) ||
            ((*(uint *)(param_1 + 0xc) <= *(uint *)(param_2 + 0xc) &&
             (*(uint *)(param_1 + 8) <= *(uint *)(param_2 + 8))))) {
      local_28 = 0;
    }
    else {
      local_28 = 2;
    }
  }
  return local_28;
}



// Function: FUN_1000bed0 at 1000bed0

void FUN_1000bed0(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_var;
  undefined4 uVar6;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  uint uStack_34;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011ec0;
  local_10 = ExceptionList;
  uStack_34 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  uVar5 = 1;
  FUN_10006c90(&local_15);
  iVar1 = FUN_100071d0(uVar5);
  local_8 = 0;
  uVar2 = FUN_10006d30(iVar1);
  uVar6 = extraout_var;
  uVar2 = FUN_10001630(uVar2);
  pvVar3 = (void *)FUN_10006c90(&local_16);
  FUN_10001670(pvVar3,uVar2,uVar6);
  iVar4 = FUN_10006fa0(iVar1);
  uVar6 = extraout_var_00;
  uVar2 = FUN_10001630(iVar4);
  pvVar3 = (void *)FUN_10006c90(&local_17);
  FUN_10001670(pvVar3,uVar2,uVar6);
  iVar1 = FUN_10006fc0(iVar1);
  uVar6 = extraout_var_01;
  uVar2 = FUN_10001630(iVar1);
  pvVar3 = (void *)FUN_10006c90(&local_18);
  FUN_10001670(pvVar3,uVar2,uVar6);
  FUN_1000bfcf();
  return;
}



// Function: Catch@1000bfa7 at 1000bfa7

void Catch_1000bfa7(void)

{
  int unaff_EBP;
  void *pvVar1;
  
  pvVar1 = *(void **)(unaff_EBP + -0x20);
  FUN_10006c90(unaff_EBP + -0x15);
  FUN_100072c0(pvVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000bfcf at 1000bfcf

undefined4 FUN_1000bfcf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x20);
}



// Function: FUN_1000c000 at 1000c000

void FUN_1000c000(void *param_1)

{
  int iVar1;
  void *pvVar2;
  void *this;
  undefined1 local_6;
  undefined1 local_5;
  
  iVar1 = FUN_10006f80((int)param_1);
  pvVar2 = (void *)FUN_10001650(iVar1);
  this = (void *)FUN_10006c90(&local_5);
  FUN_100017e0(this,pvVar2);
  FUN_10006c90(&local_6);
  FUN_100072c0(param_1);
  return;
}



// Function: FUN_1000c060 at 1000c060

void FUN_1000c060(void)

{
  return;
}



// Function: FUN_1000c070 at 1000c070

void FUN_1000c070(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  uVar1 = FUN_10006d30(param_1);
  FUN_10001630(uVar1);
  FUN_10006c90(&local_5);
  FUN_10001770();
  iVar2 = FUN_10006fa0((int)param_1);
  FUN_10001630(iVar2);
  FUN_10006c90(&local_6);
  FUN_10001770();
  iVar2 = FUN_10006fc0((int)param_1);
  FUN_10001630(iVar2);
  FUN_10006c90(&local_7);
  FUN_10001770();
  FUN_10006c90(&local_8);
  FUN_100072c0(param_1);
  return;
}



// Function: FUN_1000c120 at 1000c120

undefined4 FUN_1000c120(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000c130 at 1000c130

void FUN_1000c130(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10006f80(param_1);
  FUN_1000c160(iVar1);
  return;
}



// Function: FUN_1000c160 at 1000c160

void FUN_1000c160(undefined4 param_1)

{
  FUN_1000b250(param_1);
  return;
}



// Function: FUN_1000c180 at 1000c180

int __thiscall FUN_1000c180(void *this,short *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  void *pvVar4;
  short *psVar5;
  int local_14;
  int local_c;
  undefined1 local_5;
  
  piVar2 = (int *)FUN_10007010((int *)this);
  local_c = *piVar2;
                    /* WARNING: Load size is inaccurate */
  local_14 = *this;
  while (pcVar3 = (char *)FUN_10006d10(local_c), *pcVar3 == '\0') {
    psVar5 = param_1;
    pvVar4 = (void *)FUN_1000c130(local_c);
    FUN_1000c120(&local_5);
    cVar1 = FUN_1000ba80(pvVar4,psVar5);
    if (cVar1 == '\0') {
      local_14 = local_c;
      piVar2 = (int *)FUN_10006d30(local_c);
      local_c = *piVar2;
    }
    else {
      piVar2 = (int *)FUN_10006fc0(local_c);
      local_c = *piVar2;
    }
  }
  return local_14;
}



// Function: FUN_1000c220 at 1000c220

undefined4 * __thiscall FUN_1000c220(void *this,undefined4 *param_1,short *param_2)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  short *psVar5;
  undefined1 local_24 [4];
  undefined1 local_20 [8];
  undefined4 local_18;
  undefined4 *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 local_5;
  
  local_c = this;
  FUN_1000c300(this,&local_10,param_2);
  piVar3 = (int *)FUN_10007320(local_c,local_20);
  bVar1 = FUN_10003570(&local_10,piVar3);
  if (!bVar1) {
    iVar4 = FUN_10006f60(&local_10);
    psVar5 = (short *)FUN_1000c130(iVar4);
    FUN_1000c120(&local_5);
    cVar2 = FUN_1000ba80(param_2,psVar5);
    if (cVar2 == '\0') {
      local_14 = &local_18;
      goto LAB_1000c2a2;
    }
  }
  local_14 = (undefined4 *)FUN_10007320(local_c,local_24);
LAB_1000c2a2:
  *param_1 = *local_14;
  return param_1;
}



// Function: FUN_1000c2c0 at 1000c2c0

void * FUN_1000c2c0(void *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  undefined1 local_10 [8];
  void *local_8;
  
  bVar3 = DAT_10018532;
  uVar1 = forward<>(param_2);
  iVar2 = FUN_1000af40(local_8,local_10,'\0',uVar1,bVar3);
  FUN_10009930(param_1,iVar2);
  return param_1;
}



// Function: FUN_1000c300 at 1000c300

void * __thiscall FUN_1000c300(void *this,void *param_1,short *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000c180(this,param_2);
  FUN_10002130(param_1,iVar1);
  return param_1;
}



// Function: FUN_1000c330 at 1000c330

void FUN_1000c330(void)

{
  undefined1 local_5;
  
  FUN_10006c90(&local_5);
  max_size();
  return;
}



// Function: max_size at 1000c350

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



// Function: FUN_1000c370 at 1000c370

undefined4 FUN_1000c370(void)

{
  return 0x5555555;
}



// Function: max_size at 1000c380

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
  FUN_1000c370();
  return;
}



// Function: FUN_1000c390 at 1000c390

void __cdecl FUN_1000c390(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  FUN_10003e60(eVar1);
  return;
}



// Function: FUN_1000c3c0 at 1000c3c0

void __cdecl FUN_1000c3c0(undefined4 param_1)

{
  FUN_10001650(param_1);
  return;
}



// Function: FUN_1000c3e0 at 1000c3e0

undefined4 __fastcall FUN_1000c3e0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_1000c400 at 1000c400

undefined4 * __thiscall FUN_1000c400(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011ee8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1000c5e0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000c480 at 1000c480

int * __thiscall FUN_1000c480(void *this,int *param_1)

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



// Function: FUN_1000c4b0 at 1000c4b0

int * __thiscall FUN_1000c4b0(void *this,int *param_1)

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



// Function: FUN_1000c4e0 at 1000c4e0

void * __thiscall FUN_1000c4e0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011f18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1000c5e0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000c560 at 1000c560

void * __thiscall FUN_1000c560(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10011f48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_1000c6a0(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000c5e0 at 1000c5e0

int __thiscall FUN_1000c5e0(void *this,int *param_1)

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
  
  puStack_c = &LAB_10011f78;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
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
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10013988,&local_14);
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



// Function: FUN_1000c6a0 at 1000c6a0

int __thiscall FUN_1000c6a0(void *this,int *param_1)

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
  
  puStack_c = &LAB_10011fa8;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
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
    iVar3 = (**(code **)*piVar2)(piVar2,&DAT_10013dfc,&local_14);
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



// Function: FUN_1000c760 at 1000c760

undefined4 * __fastcall FUN_1000c760(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000c7b0 at 1000c7b0

undefined4 * __fastcall FUN_1000c7b0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000c820 at 1000c820

undefined4 * __thiscall FUN_1000c820(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  code *pcVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)this = 0;
  HVar2 = FUN_1000e390(this,param_1,param_2,param_3);
  if ((HVar2 < 0) && (HVar2 != -0x7fffbffe)) {
    _com_issue_error(HVar2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c860 at 1000c860

int * __thiscall FUN_1000c860(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1000c890 at 1000c890

int * __thiscall FUN_1000c890(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_1000c8b0 at 1000c8b0

undefined4 * __thiscall FUN_1000c8b0(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000c8f0 at 1000c8f0

int * __thiscall FUN_1000c8f0(void *this,int param_1)

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
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10017198);
  }
  return (int *)this;
}



// Function: FUN_1000c950 at 1000c950

int * __thiscall FUN_1000c950(void *this,int param_1)

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
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10017198);
}



// Function: FUN_1000c990 at 1000c990

int * __thiscall FUN_1000c990(void *this,int param_1,char param_2)

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



// Function: FUN_1000c9e0 at 1000c9e0

undefined4 * __thiscall FUN_1000c9e0(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return (undefined4 *)this;
}



// Function: FUN_1000ca10 at 1000ca10

int * __thiscall FUN_1000ca10(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  if (iVar1 != 0) {
    InterlockedIncrement((LONG *)(iVar1 + 8));
  }
  return (int *)this;
}



// Function: FUN_1000ca40 at 1000ca40

undefined4 * __thiscall FUN_1000ca40(void *this,int param_1,char param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001203b;
  local_10 = ExceptionList;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
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
      if (iVar4 != 0) goto LAB_1000cac2;
      _com_issue_error(-0x7ff8fff2);
    }
    *piVar2 = param_1;
  }
LAB_1000cac2:
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000caf0 at 1000caf0

undefined4 * __thiscall FUN_1000caf0(void *this,LPCSTR param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001206b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(0xc);
  local_8 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 0;
    puVar1[2] = 1;
    uVar2 = ConvertStringToBSTR(param_1);
    *puVar1 = uVar2;
  }
  local_8 = 0xffffffff;
  *(undefined4 **)this = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: _com_error at 1000cb90

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



// Function: FUN_1000cbd0 at 1000cbd0

void __fastcall FUN_1000cbd0(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012098;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10018498 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cc20 at 1000cc20

void __fastcall FUN_1000cc20(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100120c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10018498 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cc70 at 1000cc70

void __fastcall FUN_1000cc70(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000cc80 at 1000cc80

void __fastcall FUN_1000cc80(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000cc90 at 1000cc90

void __fastcall FUN_1000cc90(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000cca0 at 1000cca0

void __fastcall FUN_1000cca0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000ccb0 at 1000ccb0

void __fastcall FUN_1000ccb0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000ccc0 at 1000ccc0

void __fastcall FUN_1000ccc0(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}



// Function: FUN_1000ccf0 at 1000ccf0

void __fastcall FUN_1000ccf0(undefined4 *param_1)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    LVar2 = InterlockedDecrement(piVar1 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
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
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1000cd50 at 1000cd50

void __cdecl FUN_1000cd50(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_1000cd60 at 1000cd60

int * __thiscall FUN_1000cd60(void *this,int param_1)

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
    _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10017198);
  }
  return (int *)this;
}



// Function: FUN_1000cdc0 at 1000cdc0

int * __thiscall FUN_1000cdc0(void *this,int param_1)

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
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10017198);
}



// Function: FUN_1000ce00 at 1000ce00

int * __thiscall FUN_1000ce00(void *this,int *param_1)

{
  int iVar1;
  
  if ((int *)this != param_1) {
    FUN_1000ea10((undefined4 *)this);
    iVar1 = *param_1;
    *(int *)this = iVar1;
    if (iVar1 != 0) {
      InterlockedIncrement((LONG *)(iVar1 + 8));
    }
  }
  return (int *)this;
}



// Function: FUN_1000ce30 at 1000ce30

uint __thiscall FUN_1000ce30(void *this,int param_1)

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



// Function: FUN_1000ce50 at 1000ce50

uint __thiscall FUN_1000ce50(void *this,int param_1)

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



// Function: FUN_1000ce70 at 1000ce70

uint __thiscall FUN_1000ce70(void *this,int param_1)

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



// Function: FUN_1000ce90 at 1000ce90

uint __thiscall FUN_1000ce90(void *this,int param_1)

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



// Function: FUN_1000cf50 at 1000cf50

void __fastcall FUN_1000cf50(int *param_1)

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



// Function: FUN_1000cfd0 at 1000cfd0

int * __fastcall FUN_1000cfd0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000cff0 at 1000cff0

int * __fastcall FUN_1000cff0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000d010 at 1000d010

int * __thiscall FUN_1000d010(void *this,byte param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != 0) {
    Ordinal_6(*this);
    *(undefined4 *)this = 0;
  }
  if (*(void **)((int)this + 4) != (void *)0x0) {
    operator_delete(*(void **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_1000d060 at 1000d060

ULONG __fastcall FUN_1000d060(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[8].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10013d98);
  }
  return UVar1;
}



// Function: FUN_1000d0a0 at 1000d0a0

void FUN_1000d0a0(IID *param_1,LPCSTR param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_1000d0c0(param_1,param_2,0,(LPCSTR)0x0,param_3,param_4);
  return;
}



// Function: FUN_1000d0c0 at 1000d0c0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000d0c0(IID *param_1,LPCSTR param_2,int param_3,LPCSTR param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  LPWSTR pWVar4;
  LPWSTR pWVar5;
  uint uVar6;
  LPCSTR pCVar7;
  int *_Memory;
  uint local_30;
  char *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100120f8;
  local_10 = ExceptionList;
  local_30 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_30;
  if (param_2 == (LPCSTR)0x0) goto LAB_1000d236;
  _Memory = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 0;
  pCVar7 = param_2;
  do {
    cVar3 = *pCVar7;
    pCVar7 = pCVar7 + 1;
  } while (cVar3 != '\0');
  pcVar1 = pCVar7 + (1 - (int)(param_2 + 1));
  uVar6 = (int)pcVar1 * 2;
  if ((((int)pcVar1 >> 0x1f) << 1 | (uint)pcVar1 >> 0x1f) + (uint)(0x7fffffff < uVar6) == 0) {
    if (((int)uVar6 < 0x401) && (cVar3 = FUN_10006890(uVar6), cVar3 != '\0')) {
      pWVar4 = (LPWSTR)&local_30;
    }
    else {
      pWVar4 = (LPWSTR)FUN_10003d80(&local_18,uVar6);
      _Memory = local_18;
    }
    pWVar4 = FUN_10003e00(pWVar4,param_2,(uint)pcVar1 & 0x7fffffff,3);
    if (pWVar4 != (LPWSTR)0x0) {
      pWVar5 = (LPWSTR)0x0;
      if (param_4 == (LPCSTR)0x0) {
LAB_1000d1f4:
        FUN_1000d260(param_1,pWVar4,param_3,(int)pWVar5,param_5,param_6,(HINSTANCE)0x0);
      }
      else {
        pCVar7 = param_4;
        do {
          cVar3 = *pCVar7;
          pCVar7 = pCVar7 + 1;
        } while (cVar3 != '\0');
        local_1c = pCVar7 + (1 - (int)(param_4 + 1));
        uVar6 = FUN_10001520((uint *)&local_1c,(uint)local_1c,2);
        pcVar1 = local_1c;
        if (-1 < (int)uVar6) {
          if (((int)local_1c < 0x401) && (cVar3 = FUN_10006890((int)local_1c), cVar3 != '\0')) {
            pWVar5 = (LPWSTR)&local_30;
          }
          else {
            pWVar5 = (LPWSTR)FUN_10003d80(&local_18,(int)pcVar1);
            _Memory = local_18;
          }
          pWVar5 = FUN_10003e00(pWVar5,param_4,(uint)pcVar1 >> 1,3);
          if (pWVar5 != (LPWSTR)0x0) goto LAB_1000d1f4;
        }
      }
    }
  }
  local_8 = 0xffffffff;
  while (_Memory != (int *)0x0) {
    piVar2 = (int *)*_Memory;
    local_18 = piVar2;
    free(_Memory);
    _Memory = piVar2;
  }
LAB_1000d236:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d260 at 1000d260

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000d260(IID *param_1,LPWSTR param_2,int param_3,int param_4,undefined4 param_5,int param_6
                 ,HINSTANCE param_7)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  errno_t eVar5;
  LPWSTR pWVar6;
  char *pcVar7;
  int *_Memory;
  uint local_440;
  LPOLESTR local_424;
  int *local_420;
  int *local_41c;
  int *local_418;
  CHAR local_414 [1024];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001216d;
  local_10 = ExceptionList;
  local_440 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Memory = (int *)0x0;
  local_420 = (int *)0x0;
  local_8 = 0;
  local_414[0] = '\0';
  local_14 = local_440;
  if (((uint)param_2 & 0xffff0000) == 0) {
    local_41c = (int *)((uint)param_2 & 0xffff);
    iVar4 = LoadStringA(param_7,(UINT)local_41c,local_414,0x400);
    if (iVar4 == 0) {
      eVar5 = strcpy_s(local_414,0x400,"Unknown Error");
      FUN_10003e60(eVar5);
    }
    pcVar7 = local_414;
    do {
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    pcVar7 = pcVar7 + (1 - (int)(local_414 + 1));
    uVar2 = (int)pcVar7 * 2;
    if ((((int)pcVar7 >> 0x1f) << 1 | (uint)pcVar7 >> 0x1f) + (uint)(0x7fffffff < uVar2) == 0) {
      if (((int)uVar2 < 0x401) && (cVar3 = FUN_10006890(uVar2), cVar3 != '\0')) {
        pWVar6 = (LPWSTR)&local_440;
      }
      else {
        pWVar6 = (LPWSTR)FUN_10003d80(&local_420,uVar2);
        _Memory = local_420;
      }
      param_2 = FUN_10003e00(pWVar6,local_414,(uint)pcVar7 & 0x7fffffff,3);
      if (param_2 != (LPWSTR)0x0) goto LAB_1000d3bf;
    }
    local_8 = 0xffffffff;
    FUN_100028c0((int *)&local_420);
  }
  else {
LAB_1000d3bf:
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
      iVar4 = (**(code **)*local_418)(local_418,&DAT_10013988,&local_41c);
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
    while (_Memory != (int *)0x0) {
      piVar1 = (int *)*_Memory;
      local_420 = piVar1;
      free(_Memory);
      _Memory = piVar1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d530 at 1000d530

void __thiscall FUN_1000d530(void *this,int param_1)

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



// Function: FUN_1000d550 at 1000d550

void __thiscall FUN_1000d550(void *this,int param_1)

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



// Function: throwExceptionWithFileInfo at 1000d570

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
  puStack_c = &LAB_1001222f;
  local_10 = ExceptionList;
  uStack_207c = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_207c;
  ExceptionList = &local_10;
  local_2044 = param_2;
  local_2048 = param_4;
  local_2038 = param_5;
  local_2030 = param_6;
  local_2040 = *(undefined4 *)((int)param_1 + 4);
  local_18 = uStack_207c;
  FUN_1000e420(param_1,&local_204c);
  piVar1 = local_204c;
  local_8 = 0;
  if ((local_204c != (int *)0x0) && (local_204c[1] == 0)) {
    pCVar3 = ConvertBSTRToString((LPCWSTR)*local_204c);
    piVar1[1] = (int)pCVar3;
  }
  local_203c = (void *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_10013dec,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10013270,&local_2054
                          );
  if (-1 < HVar4) {
    HVar4 = OleRun(local_2054);
    if (-1 < HVar4) {
      HVar4 = (*local_2054->lpVtbl->QueryInterface)(local_2054,(IID *)&DAT_10013da8,&local_203c);
    }
    (*local_2054->lpVtbl->Release)(local_2054);
    if (-1 < HVar4) goto LAB_1000d6a2;
  }
  local_203c = (void *)0x0;
  if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
    _com_issue_error(HVar4);
  }
LAB_1000d6a2:
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
  this = (void *)FUN_1000cf50((int *)&local_203c);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000eaa0(this,local_204c);
  local_8 = 1;
  FUN_1000d835();
  return;
}



// Function: Catch@1000d6f5 at 1000d6f5

undefined * Catch_1000d6f5(void)

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
  FUN_1000d060(pIVar2);
  if (*(LPCSTR *)(unaff_EBP + -0x2058) == (LPCSTR)0x0) {
    *(undefined1 *)(unaff_EBP + -0x2014) = 0;
    piVar3 = (int *)0x1fff;
    memset((void *)(unaff_EBP + -0x2013),0,0x1fff);
    FUN_1000e6b0((ushort)*(undefined4 *)(unaff_EBP + -0x203c),(LPSTR)(unaff_EBP + -0x2014));
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    FUN_1000caf0(&stack0xfffffffc,(LPCSTR)(unaff_EBP + -0x2014));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_01;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_1000e740(pvVar1,piVar3);
  }
  else {
    *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
    piVar3 = extraout_ECX_00;
    FUN_1000caf0(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP + -0x2058));
    *(undefined1 *)(unaff_EBP + -4) = 6;
    pvVar1 = *(void **)(unaff_EBP + -0x2038);
    if (pvVar1 == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      pvVar1 = extraout_ECX_02;
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_1000e740(pvVar1,piVar3);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_03;
  }
  FUN_1000e800(pIVar2);
  *(undefined1 **)(unaff_EBP + -0x204c) = &stack0xfffffffc;
  piVar3 = extraout_ECX_04;
  FUN_1000caf0(&stack0xfffffffc,"");
  *(undefined1 *)(unaff_EBP + -4) = 7;
  pvVar1 = *(void **)(unaff_EBP + -0x2038);
  if (pvVar1 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar1 = extraout_ECX_05;
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_1000e830(pvVar1,piVar3);
  pIVar2 = *(IUnknown **)(unaff_EBP + -0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar2 = extraout_ECX_06;
  }
  FUN_1000e8f0(pIVar2);
  return &DAT_1000d822;
}



// Function: FUN_1000d835 at 1000d835

/* WARNING: Removing unreachable block (ram,0x1000dae2) */

void FUN_1000d835(void)

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
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10013d98);
    piVar7 = extraout_ECX_00;
  }
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  FUN_1000caf0(&stack0xfffffffc,*(LPCSTR *)(unaff_EBP - 0x2044));
  *(undefined1 *)(unaff_EBP - 4) = 9;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_01;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_1000e740(pvVar12,piVar7);
  *(undefined1 **)(unaff_EBP - 0x2040) = &stack0xfffffffc;
  piVar7 = extraout_ECX_02;
  FUN_1000caf0(&stack0xfffffffc,(LPCSTR)unaff_EBX);
  *(undefined1 *)(unaff_EBP - 4) = 10;
  pvVar12 = *(void **)(unaff_EBP - 0x2038);
  if (pvVar12 == (void *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pvVar12 = extraout_ECX_03;
  }
  *(undefined1 *)(unaff_EBP - 4) = 8;
  FUN_1000e830(pvVar12,piVar7);
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar5 = (*pIVar2->lpVtbl[4].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10013d98);
  }
  pIVar2 = *(IUnknown **)(unaff_EBP - 0x2038);
  if (pIVar2 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  uVar10 = *(undefined4 *)(unaff_EBP - 0x203c);
  uVar13 = uVar10;
  UVar5 = (*pIVar2->lpVtbl[5].Release)(pIVar2);
  if ((int)UVar5 < 0) {
    _com_issue_errorex(UVar5,pIVar2,(_GUID *)&DAT_10013d98);
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
    piVar6 = FUN_1000e590(pvVar12,(undefined4 *)(unaff_EBP - 0x2040));
    *(undefined1 *)(unaff_EBP - 4) = 0xc;
    if ((undefined4 *)*piVar6 == (undefined4 *)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined4 *)*piVar6;
    }
    (**(code **)(*piVar7 + 0x14))(piVar7,uVar13);
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    FUN_1000ccf0((undefined4 *)(unaff_EBP - 0x2040));
    FUN_1000c400((void *)(unaff_EBP - 0x2040),(int *)(unaff_EBP - 0x203c));
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
      _CxxThrowException((void *)(unaff_EBP - 0x2068),(ThrowInfo *)&DAT_10017198);
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
  piVar7 = FUN_1000e590(pvVar12,(undefined4 *)(unaff_EBP - 0x2044));
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
  uVar10 = FUN_1000d0c0((IID *)(unaff_EBP - 0x2034),pCVar9,0,(LPCSTR)0x0,unaff_EBP - 0x2024,uVar10);
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
  uStack00000004 = 0x1000dc57;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000dc60 at 1000dc60

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000dc60(undefined4 param_1,uchar *param_2)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_1000dea0(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000dcd0 at 1000dcd0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000dcd0(uchar *param_1)

{
  char *in_stack_00000018;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000018,&stack0x0000001c);
  FUN_1000dea0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000dd40 at 1000dd40

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000dd40(uchar *param_1)

{
  char *in_stack_00000014;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_00000014,&stack0x00000018);
  FUN_1000dea0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ddb0 at 1000ddb0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000ddb0(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_1000dea0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000de20 at 1000de20

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_1000de20(uchar *param_1)

{
  char *in_stack_0000001c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_10018498 ^ (uint)&stack0xfffffffc;
  _vsnprintf(local_1008,0xfff,in_stack_0000001c,&stack0x00000020);
  FUN_1000dea0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000dea0 at 1000dea0

/* WARNING: Removing unreachable block (ram,0x1000e06e) */

void __cdecl FUN_1000dea0(uchar *param_1)

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
  
  puStack_c = &LAB_100122b3;
  local_10 = ExceptionList;
  ppvObject = (void **)(DAT_10018498 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  local_8 = 1;
  local_14 = (IUnknown *)0x0;
  HVar4 = CoCreateInstance((IID *)&DAT_10013dec,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10013270,&local_20);
  if (HVar4 < 0) {
LAB_1000df34:
    local_14 = (IUnknown *)0x0;
    if ((HVar4 < 0) && (HVar4 != -0x7fffbffe)) {
      _com_issue_error(HVar4);
    }
  }
  else {
    HVar4 = OleRun(local_20);
    if (-1 < HVar4) {
      HVar4 = (*local_20->lpVtbl->QueryInterface)(local_20,(IID *)&DAT_10013da8,&local_14);
    }
    (*local_20->lpVtbl->Release)(local_20);
    if (HVar4 < 0) goto LAB_1000df34;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  pbVar12 = PTR_s_APPEND_10018480;
  do {
    bVar1 = *in_stack_00000018;
    bVar15 = bVar1 < *pbVar12;
    if (bVar1 != *pbVar12) {
LAB_1000df80:
      uVar5 = -(uint)bVar15 | 1;
      goto LAB_1000df85;
    }
    if (bVar1 == 0) break;
    bVar1 = in_stack_00000018[1];
    bVar15 = bVar1 < pbVar12[1];
    if (bVar1 != pbVar12[1]) goto LAB_1000df80;
    in_stack_00000018 = in_stack_00000018 + 2;
    pbVar12 = pbVar12 + 2;
  } while (bVar1 != 0);
  uVar5 = 0;
LAB_1000df85:
  if (uVar5 == 0) {
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    local_18 = (int *)0x0;
    Ordinal_200(0);
    if (local_18 != (int *)0x0) {
      FUN_1000c560(&local_1c,(int *)&local_18);
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
        FUN_1000ccf0(&local_2c);
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
    iVar6 = FUN_1000c5e0(&local_18,piVar11);
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
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10013d98);
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
      if (in_stack_00000014 != 3) goto LAB_1000e17f;
      if (local_14 == (IUnknown *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      UVar7 = (*pIVar10->lpVtbl[9].Release)(pIVar10);
      if ((int)UVar7 < 0) {
        _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10013da8);
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
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10013da8);
    piVar11 = extraout_ECX_03;
  }
LAB_1000e17f:
  local_2c = (int *)&stack0xffffffb4;
  FUN_1000caf0(&stack0xffffffb4,in_stack_00000024);
  local_8._0_1_ = 7;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_04;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_1000e740(pIVar10,piVar11);
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
  FUN_1000caf0(&stack0xffffffb4,(LPCSTR)param_1);
  local_8._0_1_ = 8;
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_07;
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_1000e830(pIVar10,piVar11);
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[4].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10013d98);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
  }
  UVar7 = (*pIVar10->lpVtbl[5].Release)(pIVar10);
  if ((int)UVar7 < 0) {
    _com_issue_errorex(UVar7,pIVar10,(_GUID *)&DAT_10013d98);
  }
  pIVar10 = local_14;
  if (local_14 == (IUnknown *)0x0) {
    _com_issue_error(-0x7fffbffd);
    pIVar10 = extraout_ECX_08;
  }
  ppuVar9 = (undefined4 **)FUN_1000e590(pIVar10,&local_2c);
  local_8._0_1_ = 9;
  if (&local_28 != ppuVar9) {
    FUN_1000ea10(&local_28);
    puVar14 = *ppuVar9;
    local_28 = puVar14;
    if (puVar14 != (undefined4 *)0x0) {
      InterlockedIncrement(puVar14 + 2);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_1000ccf0(&local_2c);
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
  _CxxThrowException(local_3c,(ThrowInfo *)&DAT_10017198);
}



// Function: FUN_1000e390 at 1000e390

HRESULT __thiscall FUN_1000e390(void *this,IID *param_1,LPUNKNOWN param_2,LPUNKNOWN param_3)

{
  int *piVar1;
  HRESULT HVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((uint)param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10013da8,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,(DWORD)param_3,(IID *)&DAT_10013270,&param_3);
    if (HVar2 < 0) goto LAB_1000e409;
    HVar2 = OleRun(param_3);
    if (-1 < HVar2) {
      HVar2 = (*param_3->lpVtbl->QueryInterface)(param_3,(IID *)&DAT_10013da8,(void **)this);
    }
    (*param_3->lpVtbl->Release)(param_3);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_1000e409:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_1000e420 at 1000e420

undefined4 * __thiscall FUN_1000e420(void *this,undefined4 *param_1)

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
  puStack_c = &LAB_100122f4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 8);
  local_14 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1,&local_14,DAT_10018498 ^ (uint)&stack0xfffffffc);
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



// Function: FUN_1000e4e0 at 1000e4e0

undefined4 __fastcall FUN_1000e4e0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    return *(undefined4 *)(param_1 + 8);
  }
  return 0;
}



// Function: FUN_1000e560 at 1000e560

undefined4 __fastcall FUN_1000e560(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (param_1[1] == 0) {
    pCVar1 = ConvertBSTRToString((LPCWSTR)*param_1);
    param_1[1] = pCVar1;
  }
  return param_1[1];
}



// Function: FUN_1000e590 at 1000e590

undefined4 * __thiscall FUN_1000e590(void *this,undefined4 *param_1)

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
  puStack_c = &LAB_10012334;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  iVar2 = (**(code **)(*this + 0x3c))(this,&local_14,DAT_10018498 ^ (uint)&stack0xfffffffc);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_10013d98);
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



// Function: FUN_1000e650 at 1000e650

uint __cdecl FUN_1000e650(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_1000e670 at 1000e670

uchar * __cdecl FUN_1000e670(uchar *param_1)

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



// Function: FUN_1000e6b0 at 1000e6b0

undefined4 __cdecl FUN_1000e6b0(ushort param_1,LPSTR param_2)

{
  FormatMessageA(0x1200,(LPCVOID)0x0,(uint)param_1,0x400,param_2,0x2000,(va_list *)0x0);
  return 0;
}



// Function: FUN_1000e6e0 at 1000e6e0

void __fastcall FUN_1000e6e0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[10].AddRef)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10013da8);
  }
  return;
}



// Function: FUN_1000e710 at 1000e710

void __fastcall FUN_1000e710(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[9].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10013da8);
  }
  return;
}



// Function: FUN_1000e740 at 1000e740

void __thiscall FUN_1000e740(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012358;
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
  iVar1 = (**(code **)(*this + 0x28))(this,iVar1,DAT_10018498 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10013d98);
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



// Function: FUN_1000e800 at 1000e800

void __fastcall FUN_1000e800(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[5].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10013d98);
  }
  return;
}



// Function: FUN_1000e830 at 1000e830

void __thiscall FUN_1000e830(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10012388;
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
  iVar1 = (**(code **)(*this + 0x30))(this,iVar1,DAT_10018498 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10013d98);
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



// Function: FUN_1000e8f0 at 1000e8f0

void __fastcall FUN_1000e8f0(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[4].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_10013d98);
  }
  return;
}



// Function: FUN_1000e920 at 1000e920

void __fastcall FUN_1000e920(int *param_1)

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



// Function: FUN_1000e950 at 1000e950

LONG __fastcall FUN_1000e950(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
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
  return LVar1;
}



// Function: FUN_1000e9e0 at 1000e9e0

void __fastcall FUN_1000e9e0(int *param_1)

{
  if (*param_1 != 0) {
    Ordinal_6(*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}



// Function: FUN_1000ea10 at 1000ea10

void __fastcall FUN_1000ea10(undefined4 *param_1)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    LVar2 = InterlockedDecrement(piVar1 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
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
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1000eaa0 at 1000eaa0

HRESULT __thiscall FUN_1000eaa0(void *this,int *param_1)

{
  int iVar1;
  LONG LVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100123b8;
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
  iVar1 = (**(code **)(*this + 0x6c))(this,iVar1,DAT_10018498 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_10013d98);
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



// Function: FUN_1000eb70 at 1000eb70

void __cdecl FUN_1000eb70(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  FUN_10003e60(eVar1);
  return;
}



// Function: FUN_1000eb90 at 1000eb90

void FUN_1000eb90(uchar *param_1,uint param_2)

{
                    /* WARNING: Could not recover jumptable at 0x1000eb94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _mbsrchr(param_1,param_2);
  return;
}



// Function: CAtlBaseModule at 1000ece7

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::CAtlBaseModule(void)
   
   Library: Visual Studio 2012 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  uint uVar1;
  
  _ATL_BASE_MODULE70::_ATL_BASE_MODULE70((_ATL_BASE_MODULE70 *)this);
  *(undefined4 *)this = 0x38;
  *(undefined4 *)(this + 8) = 0x10000000;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined4 *)(this + 0xc) = 0xb00;
  *(undefined **)(this + 0x10) = &DAT_10014af8;
  uVar1 = FUN_100050f0((LPCRITICAL_SECTION)(this + 0x14));
  if ((int)uVar1 < 0) {
    DAT_100184de = 1;
  }
  return this;
}



// Function: FUN_1000ed25 at 1000ed25

undefined4 * __thiscall FUN_1000ed25(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: _ATL_BASE_MODULE70 at 1000ed35

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



// Function: ~CAtlBaseModule at 1000ed5d

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



// Function: operator[] at 1000ed7b

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



// Function: Add at 1000eda5

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
      FUN_10003fa0(0x80004005);
      pcVar2 = (code *)swi(3);
      iVar4 = (*pcVar2)();
      return iVar4;
    }
    if (iVar4 == 0) {
      _Count = 1;
LAB_1000eddc:
      pvVar3 = _recalloc(_Memory,_Count,4);
      if (pvVar3 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_1000edf1;
      }
    }
    else {
      _Count = *(int *)(this + 4) * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_1000eddc;
    }
    iVar4 = 0;
  }
  else {
LAB_1000edf1:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar4 = 1;
  }
  return iVar4;
}



// Function: AddResourceInstance at 1000ee1d

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



// Function: GetHInstanceAt at 1000ee50

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



// Function: InternalSetAtIndex at 1000ee99

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



// Function: RemoveAll at 1000eeb3

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



// Function: RemoveAt at 1000eed0

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



// Function: RemoveResourceInstance at 1000ef18

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



// Function: memmove_s at 1000ef75

/* Library Function - Single Match
    void __cdecl ATL::Checked::memmove_s(void *,unsigned int,void const *,unsigned int)
   
   Library: Visual Studio 2012 Release */

void __cdecl ATL::Checked::memmove_s(void *param_1,uint param_2,void *param_3,uint param_4)

{
  errno_t eVar1;
  
  eVar1 = ::memmove_s(param_1,param_2,param_3,param_4);
  FUN_10003e60(eVar1);
  return;
}



// Function: CAtlComModule at 1000ef94

/* Library Function - Single Match
    public: __thiscall ATL::CAtlComModule::CAtlComModule(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

CAtlComModule * __thiscall ATL::CAtlComModule::CAtlComModule(CAtlComModule *this)

{
  uint uVar1;
  
  _ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)this);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined **)(this + 8) = &DAT_10017388;
  *(undefined **)(this + 0xc) = &DAT_10017388;
  uVar1 = FUN_100050f0((LPCRITICAL_SECTION)(this + 0x10));
  if ((int)uVar1 < 0) {
    DAT_100184de = 1;
  }
  else {
    *(undefined4 *)this = 0x28;
  }
  return this;
}



// Function: _ATL_COM_MODULE70 at 1000efd3

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

_ATL_COM_MODULE70 * __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  memset(this + 0x10,0,0x18);
  return this;
}



// Function: Term at 1000eff0

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



// Function: `vector_constructor_iterator' at 1000f03a

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



// Function: `vector_destructor_iterator' at 1000f059

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



// Function: _com_dispatch_method at 1000f080

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
    (*(code *)PTR_FUN_10018484)(lVar1,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_propget at 1000f0c0

/* Library Function - Single Match
    long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2012 Release */

long _com_dispatch_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_propput at 1000f0e0

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
    (*(code *)PTR_FUN_10018484)(lVar2,local_c);
  }
  return lVar2;
}



// Function: _com_issue_error at 1000f140

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Library: Visual Studio 2012 Release */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_10018484)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 1000f160

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
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_10013244,&param_2),
     ppuVar3 = local_8, -1 < HVar1)) {
    HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
    (*param_2->lpVtbl->Release)(param_2);
    ppuVar3 = local_8;
    if (HVar1 == 0) {
      local_8 = &local_8;
      iVar2 = Ordinal_200(0);
      local_8 = (undefined4 **)(~-(uint)(iVar2 != 0) & (uint)local_8);
      (*(code *)PTR_FUN_10018484)(param_1,local_8);
      return;
    }
  }
  local_8 = ppuVar3;
  (*(code *)PTR_FUN_10018484)(param_1);
  return;
}



// Function: FUN_1000f1e0 at 1000f1e0

void FUN_1000f1e0(undefined *param_1)

{
  PTR_FUN_10018484 = param_1;
  return;
}



// Function: _variant_t at 1000f1f0

/* Library Function - Single Match
    public: __thiscall _variant_t::_variant_t(long,unsigned short)
   
   Library: Visual Studio 2012 Release */

_variant_t * __thiscall _variant_t::_variant_t(_variant_t *this,long param_1,ushort param_2)

{
  code *pcVar1;
  _variant_t *p_Var2;
  
  if (param_2 != 3) {
    if (param_2 == 10) goto LAB_1000f20f;
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
LAB_1000f20f:
  *(undefined2 *)this = 10;
  *(long *)(this + 8) = param_1;
  return this;
}



// Function: ConvertBSTRToString at 1000f270

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
  puStack_c = &LAB_100123e0;
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



// Function: Catch_All@1000f373 at 1000f373

undefined * Catch_All_1000f373(void)

{
  return &DAT_1000f379;
}



// Function: ConvertStringToBSTR at 1000f390

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
  pcStack_10 = FUN_1001039c;
  local_14 = ExceptionList;
  local_c = DAT_10018498 ^ 0x100171d0;
  uVar1 = DAT_10018498 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_1000f510 at 1000f510

uint FUN_1000f510(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FUN_1000f530 at 1000f530

void FUN_1000f530(undefined4 param_1,undefined4 param_2)

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
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10017198);
}



// Function: _com_dispatch_raw_method at 1000f560

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



// Function: _com_dispatch_raw_propget at 1000f5a0

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



// Function: _com_dispatch_raw_propput at 1000f5c0

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



// Function: _com_invoke_helper at 1000f620

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
  pcStack_10 = FUN_1001039c;
  local_14 = ExceptionList;
  local_c = DAT_10018498 ^ 0x10017248;
  local_8c = DAT_10018498 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_8c;
  ExceptionList = &local_14;
  local_20 = local_8c;
  puVar15 = &local_8c;
  if (param_1 == (IDispatch *)0x0) goto LAB_1000f995;
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
    if (local_3c == 0) goto LAB_1000f995;
    local_38 = 1;
    local_40 = &local_54;
  }
  if (local_3c != 0) {
    local_1c = (undefined1 *)&local_8c;
    local_34 = &local_8c;
    local_8 = 0xfffffffe;
    uStack_9c = 0x1000f6ec;
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
switchD_1000f765_caseD_f:
            puVar15 = (uint *)local_1c;
            if ((uVar1 & 0x2000) == 0) goto LAB_1000f995;
          }
switchD_1000f765_caseD_3:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *piVar14 = *piVar7;
          goto LAB_1000f850;
        }
        if (uVar4 == 0x4002) goto switchD_1000f765_caseD_3;
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
          goto switchD_1000f765_caseD_3;
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
          goto switchD_1000f765_caseD_f;
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
LAB_1000f850:
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
  iVar13 = (**(code **)(*(int *)param_1 + 0x18))(param_1,param_2,&DAT_100133a4,0,_param_3,&local_44)
  ;
  if (iVar13 < 0) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    if (iVar13 == -0x7ffdfff7) {
      _com_handle_excepinfo((tagEXCEPINFO *)&local_78,param_8);
      puVar15 = (uint *)local_1c;
    }
    goto LAB_1000f995;
  }
  puVar15 = (uint *)local_1c;
  if ((param_4 == 0) || (param_5 == (void *)0x0)) goto LAB_1000f995;
  if ((param_4 != 0xc) &&
     ((param_4 != (ushort)local_30 &&
      (iVar13 = Ordinal_12(&local_30,&local_30,0,_param_4), iVar13 < 0)))) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    goto LAB_1000f995;
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
        goto switchD_1000fa3f_caseD_3;
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
        goto switchD_1000fa3f_caseD_f;
      case 0x10:
      case 0x11:
        *(undefined1 *)param_5 = local_28;
      }
      goto LAB_1000f995;
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
switchD_1000fa3f_caseD_f:
      if ((param_4 & 0x2000) == 0) {
        Ordinal_9(&local_30);
        puVar15 = (uint *)local_1c;
        goto LAB_1000f995;
      }
    }
  }
switchD_1000fa3f_caseD_3:
  *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
LAB_1000f995:
  local_1c = (undefined1 *)puVar15;
  ExceptionList = local_14;
  lVar3 = __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return lVar3;
}



// Function: FUN_1000fbd0 at 1000fbd0

int FUN_1000fbd0(ushort param_1)

{
  if (0xfdff < param_1) {
    return -0x7ffb0001;
  }
  return param_1 + 0x80040200;
}



// Function: _com_handle_excepinfo at 1000fc00

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
      (**(code **)(*(int *)param_1 + 0xc))(param_1,&DAT_10013288);
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
      iVar4 = (*(code *)**(undefined4 **)param_1)(param_1,&DAT_10013988,ppIVar3);
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



// Function: FUN_1000fcfc at 1000fcfc

void __cdecl FUN_1000fcfc(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: `eh_vector_destructor_iterator' at 1000fd12

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
  FUN_1000fd71();
  return;
}



// Function: FUN_1000fd71 at 1000fd71

void FUN_1000fd71(void)

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



// Function: FUN_1000fd81 at 1000fd81

undefined4 __cdecl FUN_1000fd81(undefined4 *param_1)

{
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 != -0x1f928c9d) {
    return 0;
  }
  terminate();
  return extraout_EAX;
}



// Function: __ArrayUnwind at 1000fd9a

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



// Function: __security_check_cookie at 1000fdfe

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Library: Visual Studio 2012 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10018498) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: `eh_vector_constructor_iterator' at 1000fe14

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
  FUN_1000fe6c();
  return;
}



// Function: FUN_1000fe6c at 1000fe6c

void FUN_1000fe6c(void)

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



// Function: __onexit at 1000fec4

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
  
  local_8 = &DAT_100172c8;
  uStack_c = 0x1000fed0;
  local_20[0] = DecodePointer(DAT_10018914);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10018914);
    local_24 = DecodePointer(DAT_10018910);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10018914 = EncodePointer(local_20[0]);
    DAT_10018910 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000ff60();
  }
  return p_Var1;
}



// Function: FUN_1000ff60 at 1000ff60

void FUN_1000ff60(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000ff69

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2012 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: ___raise_securityfailure at 1000ff7e

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_100188f4 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_100188f4 == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}



// Function: ___report_gsfailure at 1000ffbb

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
  _DAT_100186d0 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_100186d8 = (undefined4)uVar9;
  _DAT_100186e8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_100186ec = &stack0x00000004;
  _DAT_10018628 = 0x10001;
  _DAT_100185d8 = 0xc0000409;
  _DAT_100185dc = 1;
  _DAT_100185e8 = 1;
  DAT_100185ec = 2;
  _DAT_100185e4 = unaff_retaddr;
  _DAT_100186b4 = in_GS;
  _DAT_100186b8 = in_FS;
  _DAT_100186bc = in_ES;
  _DAT_100186c0 = in_DS;
  _DAT_100186c4 = unaff_EDI;
  _DAT_100186c8 = unaff_ESI;
  _DAT_100186cc = unaff_EBX;
  _DAT_100186d4 = uVar3;
  _DAT_100186dc = unaff_EBP;
  DAT_100186e0 = unaff_retaddr;
  _DAT_100186e4 = in_CS;
  _DAT_100186f0 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10014bc4);
  return;
}



// Function: ___report_rangecheckfailure at 100100b4

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}



// Function: ___report_securityfailure at 100100c0

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
  _DAT_100186d0 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_100186d8 = (undefined4)uVar9;
  _DAT_100186e8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_100186ec = &param_1;
  _DAT_100185d8 = 0xc0000409;
  _DAT_100185dc = 1;
  _DAT_100185e8 = 1;
  DAT_100185ec = param_1;
  _DAT_100185e4 = unaff_retaddr;
  _DAT_100186b4 = in_GS;
  _DAT_100186b8 = in_FS;
  _DAT_100186bc = in_ES;
  _DAT_100186c0 = in_DS;
  _DAT_100186c4 = unaff_EDI;
  _DAT_100186c8 = unaff_ESI;
  _DAT_100186cc = unaff_EBX;
  _DAT_100186d4 = uVar3;
  _DAT_100186dc = unaff_EBP;
  DAT_100186e0 = unaff_retaddr;
  _DAT_100186e4 = in_CS;
  _DAT_100186f0 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10014bc4);
  return;
}



// Function: ___report_securityfailureEx at 1001018e

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
  _DAT_100186e8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_100186ec = &param_1;
  _DAT_100185d8 = 0xc0000409;
  _DAT_100185dc = 1;
  if ((param_2 != 0) && (param_3 == 0)) {
    param_2 = 0;
  }
  if (0xe < param_2) {
    param_2 = param_2 - 1;
  }
  _DAT_100185e8 = param_2 + 1;
  DAT_100185ec = param_1;
  _DAT_100185e4 = unaff_retaddr;
  _DAT_100186b4 = in_GS;
  _DAT_100186b8 = in_FS;
  _DAT_100186bc = in_ES;
  _DAT_100186c0 = in_DS;
  _DAT_100186c4 = unaff_EDI;
  _DAT_100186c8 = unaff_ESI;
  _DAT_100186cc = unaff_EBX;
  _DAT_100186d4 = uVar3;
  _DAT_100186dc = unaff_EBP;
  DAT_100186e0 = unaff_retaddr;
  _DAT_100186e4 = in_CS;
  _DAT_100186f0 = in_SS;
  for (local_8 = 0; _DAT_100186d0 = (undefined4)((ulonglong)uVar9 >> 0x20),
      _DAT_100186d8 = (undefined4)uVar9, local_8 < param_2; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_100185f0 + local_8 * 4) = *(undefined4 *)(param_3 + local_8 * 4);
    uVar9 = CONCAT44(_DAT_100186d0,_DAT_100186d8);
  }
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10014bc4);
  return;
}



// Function: FUN_100102ae at 100102ae

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_100102ae(uint param_1)

{
  operator_new(param_1);
  FUN_100102d6();
  return;
}



// Function: Catch_All@100102c9 at 100102c9

undefined * Catch_All_100102c9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  return &DAT_100102d3;
}



// Function: FUN_100102d6 at 100102d6

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100102d6(void)

{
  return;
}



// Function: FUN_100102dc at 100102dc

void FUN_100102dc(uint param_1)

{
  FUN_100102ae(param_1);
  return;
}



// Function: FUN_100102e5 at 100102e5

void __cdecl FUN_100102e5(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_100102f3 at 100102f3

void __cdecl FUN_100102f3(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// Function: __allmul at 10010330

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



// Function: __alloca_probe_16 at 10010370

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



// Function: __alloca_probe_8 at 10010386

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



// Function: FUN_1001039c at 1001039c

void __cdecl
FUN_1001039c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10018498,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 100103cf

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



// Function: __CRT_INIT@12 at 1001046c

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
    if (DAT_100188f8 < 1) {
      return 0;
    }
    DAT_100188f8 = DAT_100188f8 + -1;
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_10018904 != (void *)0x0) {
        pvVar3 = DAT_10018904;
        pvVar2 = DAT_10018904;
      }
      DAT_10018904 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_100104bf;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_100104bf:
    if (DAT_10018908 == 2) {
      _Memory = (int *)DecodePointer(DAT_10018914);
      if (_Memory != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10018910);
        param_1 = piVar4;
        param_2 = _Memory;
        param_3 = _Memory;
        while (piVar4 = piVar4 + -1, _Memory <= piVar4) {
          if ((*piVar4 != 0) && (pvVar5 = EncodePointer((PVOID)0x0), (PVOID)*piVar4 != pvVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            pvVar5 = EncodePointer((PVOID)0x0);
            *piVar4 = (int)pvVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10018914);
            piVar8 = (int *)DecodePointer(DAT_10018910);
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
        DAT_10018910 = EncodePointer((PVOID)0x0);
        DAT_10018914 = DAT_10018910;
      }
      DAT_10018908 = 0;
      if (!bVar1) {
        LOCK();
        DAT_10018904 = (void *)0x0;
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
      if (DAT_10018904 != (void *)0x0) {
        pvVar3 = DAT_10018904;
        pvVar2 = DAT_10018904;
      }
      DAT_10018904 = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_100105da;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_100105da:
    if (DAT_10018908 == 0) {
      DAT_10018908 = 1;
      iVar9 = initterm_e(&DAT_100131f0,&DAT_100131fc);
      if (iVar9 != 0) {
        return 0;
      }
      initterm(&DAT_100131c0,&DAT_100131ec);
      DAT_10018908 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      LOCK();
      DAT_10018904 = (void *)0x0;
      UNLOCK();
    }
    if ((DAT_1001890c != (code *)0x0) &&
       (BVar10 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1001890c), BVar10 != 0)) {
      (*DAT_1001890c)(param_1,2,param_3);
    }
    DAT_100188f8 = DAT_100188f8 + 1;
  }
  return 1;
}



// Function: entry at 10010661

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_1,param_2,param_3);
  return;
}



// Function: ___DllMainCRTStartup at 10010684

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10010735) */
/* WARNING: Removing unreachable block (ram,0x100106cb) */
/* WARNING: Removing unreachable block (ram,0x10010767) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2012 Release */

uint __cdecl ___DllMainCRTStartup(HMODULE param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  _DAT_100184c0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_100188f8 == 0)) {
    uVar1 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (uVar1 = __CRT_INIT_12(&param_1->unused,param_2,param_3), uVar1 != 0)) {
    uVar1 = FUN_10008920(param_1,(int)param_2);
    if ((param_2 == (int *)0x1) && (uVar1 == 0)) {
      FUN_10008920(param_1,0);
      __CRT_INIT_12(&param_1->unused,(int *)0x0,param_3);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar2 = __CRT_INIT_12(&param_1->unused,param_2,param_3);
      uVar1 = uVar1 & -(uint)(iVar2 != 0);
    }
  }
  FUN_100107ac();
  return uVar1;
}



// Function: FUN_100107ac at 100107ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100107ac(void)

{
  _DAT_100184c0 = 0xffffffff;
  return;
}



// Function: __alloca_probe at 100107d0

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



// Function: __SEH_prolog4 at 10010820

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10018498 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10010865

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



// Function: __EH_epilog3 at 100108a4

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



// Function: __EH_prolog3_catch at 1001093f

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10018498 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __FindPESection at 100109d0

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



// Function: __IsNonwritableInCurrentImage at 10010a20

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
  
  pcStack_10 = FUN_1001039c;
  local_14 = ExceptionList;
  local_c = DAT_10018498 ^ 0x10017368;
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



// Function: __ValidateImageBase at 10010ae0

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



// Function: ___security_init_cookie at 10010b11

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
  if ((DAT_10018498 == 0xbb40e64e) || ((DAT_10018498 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_10018498 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_10018498 == 0xbb40e64e) {
      DAT_10018498 = 0xbb40e64f;
    }
    else if ((DAT_10018498 & 0xffff0000) == 0) {
      DAT_10018498 = DAT_10018498 | (DAT_10018498 | 0x4711) << 0x10;
    }
    DAT_1001849c = ~DAT_10018498;
  }
  else {
    DAT_1001849c = ~DAT_10018498;
  }
  return;
}



// Function: FUN_10010bb2 at 10010bb2

void FUN_10010bb2(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = &DAT_10015658; puVar1 < &DAT_10015658; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// Function: FUN_10010bd2 at 10010bd2

void FUN_10010bd2(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = &DAT_10015660; puVar1 < &DAT_10015660; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// Function: FUN_10010bfe at 10010bfe

void FUN_10010bfe(void)

{
  __clean_type_info_names_internal(&DAT_100188fc);
  return;
}



// Function: Unwind@10010c60 at 10010c60

void Unwind_10010c60(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010c90 at 10010c90

void Unwind_10010c90(void)

{
  FUN_100034f0();
  return;
}



// Function: Unwind@10010cc0 at 10010cc0

void Unwind_10010cc0(void)

{
  int unaff_EBP;
  
  FUN_10003100(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010cf0 at 10010cf0

void Unwind_10010cf0(void)

{
  FUN_10002bb0();
  return;
}



// Function: Unwind@10010cfb at 10010cfb

void Unwind_10010cfb(void)

{
  int unaff_EBP;
  
  FUN_100029a0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10010d30 at 10010d30

void Unwind_10010d30(void)

{
  int unaff_EBP;
  
  FUN_10003350(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010d60 at 10010d60

void Unwind_10010d60(void)

{
  int unaff_EBP;
  
  FUN_10003350(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010d90 at 10010d90

void Unwind_10010d90(void)

{
  int unaff_EBP;
  
  FUN_100031c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010dc0 at 10010dc0

void Unwind_10010dc0(void)

{
  FUN_100032a0();
  return;
}



// Function: Unwind@10010dc8 at 10010dc8

void Unwind_10010dc8(void)

{
  int unaff_EBP;
  
  FUN_10003160((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10010df0 at 10010df0

void Unwind_10010df0(void)

{
  FUN_100032a0();
  return;
}



// Function: Unwind@10010e20 at 10010e20

void Unwind_10010e20(void)

{
  int unaff_EBP;
  
  FUN_10002df0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010e50 at 10010e50

void Unwind_10010e50(void)

{
  int unaff_EBP;
  
  FUN_10002e20(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010e80 at 10010e80

void Unwind_10010e80(void)

{
  int unaff_EBP;
  
  FUN_10002e50(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010eb0 at 10010eb0

void Unwind_10010eb0(void)

{
  int unaff_EBP;
  
  FUN_10002e50(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010ee0 at 10010ee0

void Unwind_10010ee0(void)

{
  int unaff_EBP;
  
  FUN_10002e80(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010f10 at 10010f10

void Unwind_10010f10(void)

{
  int unaff_EBP;
  
  FUN_10002eb0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010f40 at 10010f40

void Unwind_10010f40(void)

{
  int unaff_EBP;
  
  FUN_10002fd0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010f70 at 10010f70

void Unwind_10010f70(void)

{
  int unaff_EBP;
  
  FUN_10002f40(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010fa0 at 10010fa0

void Unwind_10010fa0(void)

{
  int unaff_EBP;
  
  FUN_10002f70(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10010fd0 at 10010fd0

void Unwind_10010fd0(void)

{
  int unaff_EBP;
  
  FUN_10002ee0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011000 at 10011000

void Unwind_10011000(void)

{
  FUN_10003420();
  return;
}



// Function: Unwind@10011030 at 10011030

void Unwind_10011030(void)

{
  int unaff_EBP;
  
  FUN_100032c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011060 at 10011060

void Unwind_10011060(void)

{
  int unaff_EBP;
  
  FUN_10002b40(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10011090 at 10011090

void Unwind_10011090(void)

{
  int unaff_EBP;
  
  FUN_10002860(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100110c0 at 100110c0

void Unwind_100110c0(void)

{
  FUN_10003220();
  return;
}



// Function: Unwind@100110f0 at 100110f0

void Unwind_100110f0(void)

{
  int unaff_EBP;
  
  FUN_10002b40(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100110fb at 100110fb

void Unwind_100110fb(void)

{
  int unaff_EBP;
  
  FUN_100033c0(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@10011130 at 10011130

void Unwind_10011130(void)

{
  int unaff_EBP;
  
  FUN_10003030((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10011160 at 10011160

void Unwind_10011160(void)

{
  FUN_10003220();
  return;
}



// Function: Unwind@10011190 at 10011190

void Unwind_10011190(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100111c0 at 100111c0

void Unwind_100111c0(void)

{
  int unaff_EBP;
  
  FUN_10003100(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100111f0 at 100111f0

void Unwind_100111f0(void)

{
  FUN_10002bb0();
  return;
}



// Function: Unwind@100111fb at 100111fb

void Unwind_100111fb(void)

{
  int unaff_EBP;
  
  FUN_100029a0(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10011230 at 10011230

void Unwind_10011230(void)

{
  int unaff_EBP;
  
  FUN_10003350(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011260 at 10011260

void Unwind_10011260(void)

{
  int unaff_EBP;
  
  FUN_10003350(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011290 at 10011290

void Unwind_10011290(void)

{
  int unaff_EBP;
  
  FUN_100031c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100112c0 at 100112c0

void Unwind_100112c0(void)

{
  FUN_100032a0();
  return;
}



// Function: Unwind@100112c8 at 100112c8

void Unwind_100112c8(void)

{
  int unaff_EBP;
  
  FUN_10003160((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100112f0 at 100112f0

void Unwind_100112f0(void)

{
  FUN_100032a0();
  return;
}



// Function: Unwind@10011320 at 10011320

void Unwind_10011320(void)

{
  int unaff_EBP;
  
  FUN_10002df0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011350 at 10011350

void Unwind_10011350(void)

{
  int unaff_EBP;
  
  FUN_10002e20(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011380 at 10011380

void Unwind_10011380(void)

{
  int unaff_EBP;
  
  FUN_10002e50(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100113b0 at 100113b0

void Unwind_100113b0(void)

{
  int unaff_EBP;
  
  FUN_10002e80(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100113e0 at 100113e0

void Unwind_100113e0(void)

{
  int unaff_EBP;
  
  FUN_10002eb0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011410 at 10011410

void Unwind_10011410(void)

{
  int unaff_EBP;
  
  FUN_10002fd0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011440 at 10011440

void Unwind_10011440(void)

{
  int unaff_EBP;
  
  FUN_10002f40(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011470 at 10011470

void Unwind_10011470(void)

{
  int unaff_EBP;
  
  FUN_10002f70(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100114a0 at 100114a0

void Unwind_100114a0(void)

{
  int unaff_EBP;
  
  FUN_10002ee0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100114d0 at 100114d0

void Unwind_100114d0(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100114d8 at 100114d8

void Unwind_100114d8(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10011500 at 10011500

void Unwind_10011500(void)

{
  FUN_10003420();
  return;
}



// Function: Unwind@10011530 at 10011530

void Unwind_10011530(void)

{
  int unaff_EBP;
  
  FUN_100032c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011560 at 10011560

void Unwind_10011560(void)

{
  int unaff_EBP;
  
  FUN_10002b40(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10011590 at 10011590

void Unwind_10011590(void)

{
  int unaff_EBP;
  
  FUN_10002860(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100115c0 at 100115c0

void Unwind_100115c0(void)

{
  FUN_10003220();
  return;
}



// Function: Unwind@100115f0 at 100115f0

void Unwind_100115f0(void)

{
  int unaff_EBP;
  
  FUN_10002b40(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@100115fb at 100115fb

void Unwind_100115fb(void)

{
  int unaff_EBP;
  
  FUN_100033c0(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@10011630 at 10011630

void Unwind_10011630(void)

{
  int unaff_EBP;
  
  FUN_10003030((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10011660 at 10011660

void Unwind_10011660(void)

{
  FUN_10003220();
  return;
}



// Function: Unwind@10011690 at 10011690

void Unwind_10011690(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100116c0 at 100116c0

void Unwind_100116c0(void)

{
  int unaff_EBP;
  
  FUN_100102e5(*(void **)(unaff_EBP + -100));
  return;
}



// Function: Unwind@100116f0 at 100116f0

void Unwind_100116f0(void)

{
  int unaff_EBP;
  
  FUN_100102e5(*(void **)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10011720 at 10011720

void Unwind_10011720(void)

{
  int unaff_EBP;
  
  FUN_100102e5(*(void **)(unaff_EBP + -100));
  return;
}



// Function: Unwind@10011750 at 10011750

void Unwind_10011750(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10011780 at 10011780

void Unwind_10011780(void)

{
  int unaff_EBP;
  
  FUN_10002a00((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100117b0 at 100117b0

void Unwind_100117b0(void)

{
  int unaff_EBP;
  
  FUN_10002a00((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100117b8 at 100117b8

void Unwind_100117b8(void)

{
  int unaff_EBP;
  
  FUN_100028c0((int *)(unaff_EBP + -0x140));
  return;
}



// Function: Unwind@100117c3 at 100117c3

void Unwind_100117c3(void)

{
  int unaff_EBP;
  
  FUN_10002cd0((int *)(unaff_EBP + -0x148));
  return;
}



// Function: Unwind@100117ce at 100117ce

void Unwind_100117ce(void)

{
  int unaff_EBP;
  
  FUN_10002cd0((int *)(unaff_EBP + -0x14c));
  return;
}



// Function: Unwind@100117d9 at 100117d9

void Unwind_100117d9(void)

{
  int unaff_EBP;
  
  FUN_10002c70((int *)(unaff_EBP + -0x150));
  return;
}



// Function: Unwind@10011810 at 10011810

void Unwind_10011810(void)

{
  int unaff_EBP;
  
  FUN_10002d90((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011818 at 10011818

void Unwind_10011818(void)

{
  int unaff_EBP;
  
  FUN_10002d90((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10011840 at 10011840

void Unwind_10011840(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10011870 at 10011870

void Unwind_10011870(void)

{
  int unaff_EBP;
  
  FUN_100102f3(*(void **)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10011882 at 10011882

void Unwind_10011882(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100118b0 at 100118b0

void Unwind_100118b0(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100118e0 at 100118e0

void Unwind_100118e0(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10011910 at 10011910

void Unwind_10011910(void)

{
  int unaff_EBP;
  
  FUN_100028c0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10011940 at 10011940

void Unwind_10011940(void)

{
  int unaff_EBP;
  
  FUN_10002c10((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011990 at 10011990

void Unwind_10011990(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100119c0 at 100119c0

void Unwind_100119c0(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100119f0 at 100119f0

void Unwind_100119f0(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10011a20 at 10011a20

void Unwind_10011a20(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10011a50 at 10011a50

void Unwind_10011a50(void)

{
  int unaff_EBP;
  
  FUN_10003480((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10011a80 at 10011a80

void Unwind_10011a80(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011a88 at 10011a88

void Unwind_10011a88(void)

{
  int unaff_EBP;
  
  FUN_10002d30((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10011a90 at 10011a90

void Unwind_10011a90(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@10011ad0 at 10011ad0

void Unwind_10011ad0(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011ad8 at 10011ad8

void Unwind_10011ad8(void)

{
  int unaff_EBP;
  
  FUN_10002d30((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10011b00 at 10011b00

void Unwind_10011b00(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@10011b08 at 10011b08

void Unwind_10011b08(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@10011b2b at 10011b2b

void Unwind_10011b2b(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x48);
  return;
}



// Function: Unwind@10011b33 at 10011b33

void Unwind_10011b33(void)

{
  int unaff_EBP;
  
  FUN_10003090(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@10011b56 at 10011b56

void Unwind_10011b56(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@10011b5e at 10011b5e

void Unwind_10011b5e(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10011b81 at 10011b81

void Unwind_10011b81(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@10011b89 at 10011b89

void Unwind_10011b89(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10011b91 at 10011b91

void Unwind_10011b91(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x50);
  return;
}



// Function: Unwind@10011bb4 at 10011bb4

void Unwind_10011bb4(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@10011bd7 at 10011bd7

void Unwind_10011bd7(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@10011bdf at 10011bdf

void Unwind_10011bdf(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x48);
  return;
}



// Function: Unwind@10011be7 at 10011be7

void Unwind_10011be7(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x58);
  return;
}



// Function: Unwind@10011bef at 10011bef

void Unwind_10011bef(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@10011c12 at 10011c12

void Unwind_10011c12(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@10011c35 at 10011c35

void Unwind_10011c35(void)

{
  int unaff_EBP;
  
  FUN_1000b6d0(unaff_EBP + -0x30);
  return;
}



// Function: Unwind@10011c3d at 10011c3d

void Unwind_10011c3d(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x58);
  return;
}



// Function: Unwind@10011c45 at 10011c45

void Unwind_10011c45(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@10011c70 at 10011c70

void Unwind_10011c70(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011c78 at 10011c78

void Unwind_10011c78(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10011ca0 at 10011ca0

void Unwind_10011ca0(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011ca8 at 10011ca8

void Unwind_10011ca8(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10011cd0 at 10011cd0

void Unwind_10011cd0(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011cd8 at 10011cd8

void Unwind_10011cd8(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10011d00 at 10011d00

void Unwind_10011d00(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011d08 at 10011d08

void Unwind_10011d08(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10011dd0 at 10011dd0

void Unwind_10011dd0(void)

{
  FUN_100034f0();
  return;
}



// Function: Unwind@10011e00 at 10011e00

void Unwind_10011e00(void)

{
  FUN_100034f0();
  return;
}



// Function: Unwind@10011e30 at 10011e30

void Unwind_10011e30(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011e38 at 10011e38

void Unwind_10011e38(void)

{
  int unaff_EBP;
  
  FUN_10003330(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@10011e60 at 10011e60

void Unwind_10011e60(void)

{
  int unaff_EBP;
  
  FUN_10003330(unaff_EBP + -0x44);
  return;
}



// Function: Unwind@10011e68 at 10011e68

void Unwind_10011e68(void)

{
  int unaff_EBP;
  
  ~_ExceptionPtr_static<>(unaff_EBP + -100);
  return;
}



// Function: Unwind@10011e90 at 10011e90

void Unwind_10011e90(void)

{
  int unaff_EBP;
  
  FUN_1000b700(unaff_EBP + -0x28);
  return;
}



// Function: Unwind@10011ee0 at 10011ee0

void Unwind_10011ee0(void)

{
  int unaff_EBP;
  
  FUN_1000cca0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011f10 at 10011f10

void Unwind_10011f10(void)

{
  int unaff_EBP;
  
  FUN_1000cca0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011f40 at 10011f40

void Unwind_10011f40(void)

{
  int unaff_EBP;
  
  FUN_1000ccb0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10011f70 at 10011f70

void Unwind_10011f70(void)

{
  int unaff_EBP;
  
  FUN_1000cca0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011fa0 at 10011fa0

void Unwind_10011fa0(void)

{
  int unaff_EBP;
  
  FUN_1000ccb0((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10011fd0 at 10011fd0

void Unwind_10011fd0(void)

{
  int unaff_EBP;
  
  FUN_1000cc70(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012000 at 10012000

void Unwind_10012000(void)

{
  int unaff_EBP;
  
  FUN_1000cc80(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012030 at 10012030

void Unwind_10012030(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012060 at 10012060

void Unwind_10012060(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012090 at 10012090

void Unwind_10012090(void)

{
  int unaff_EBP;
  
  FUN_1000cc70(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100120c0 at 100120c0

void Unwind_100120c0(void)

{
  int unaff_EBP;
  
  FUN_1000cc80(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100120f0 at 100120f0

void Unwind_100120f0(void)

{
  int unaff_EBP;
  
  FUN_100028c0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012120 at 10012120

void Unwind_10012120(void)

{
  int unaff_EBP;
  
  FUN_100028c0((int *)(unaff_EBP + -0x41c));
  return;
}



// Function: Unwind@1001212b at 1001212b

void Unwind_1001212b(void)

{
  int unaff_EBP;
  
  FUN_1000cc70((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10012136 at 10012136

void Unwind_10012136(void)

{
  int unaff_EBP;
  
  FUN_1000cbd0((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@10012141 at 10012141

void Unwind_10012141(void)

{
  int unaff_EBP;
  
  FUN_1000cc80((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1001214c at 1001214c

void Unwind_1001214c(void)

{
  int unaff_EBP;
  
  FUN_1000cc20((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10012157 at 10012157

void Unwind_10012157(void)

{
  int unaff_EBP;
  
  FUN_1000cc80((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@10012162 at 10012162

void Unwind_10012162(void)

{
  int unaff_EBP;
  
  FUN_1000cc70((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@100121a0 at 100121a0

void Unwind_100121a0(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + -0x2048));
  return;
}



// Function: Unwind@100121ab at 100121ab

void Unwind_100121ab(void)

{
  int unaff_EBP;
  
  FUN_1000cc90((int *)(unaff_EBP + -0x2038));
  return;
}



// Function: Unwind@100121b6 at 100121b6

void Unwind_100121b6(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@100121c1 at 100121c1

void Unwind_100121c1(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@100121cc at 100121cc

void Unwind_100121cc(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@100121d7 at 100121d7

void Unwind_100121d7(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@100121e2 at 100121e2

void Unwind_100121e2(void)

{
  int unaff_EBP;
  
  FUN_1000ccb0((int *)(unaff_EBP + -0x204c));
  return;
}



// Function: Unwind@100121ed at 100121ed

void Unwind_100121ed(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@100121f8 at 100121f8

void Unwind_100121f8(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10012203 at 10012203

void Unwind_10012203(void)

{
  int unaff_EBP;
  
  FUN_1000cca0((int *)(unaff_EBP + -0x203c));
  return;
}



// Function: Unwind@1001220e at 1001220e

void Unwind_1001220e(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10012219 at 10012219

void Unwind_10012219(void)

{
  int unaff_EBP;
  
  FUN_1000ccb0((int *)(unaff_EBP + -0x2040));
  return;
}



// Function: Unwind@10012224 at 10012224

void Unwind_10012224(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + -0x2044));
  return;
}



// Function: Unwind@10012260 at 10012260

void Unwind_10012260(void)

{
  int unaff_EBP;
  
  FUN_1000cca0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10012268 at 10012268

void Unwind_10012268(void)

{
  int unaff_EBP;
  
  FUN_1000ccb0((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10012270 at 10012270

void Unwind_10012270(void)

{
  int unaff_EBP;
  
  FUN_1000cc90((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10012278 at 10012278

void Unwind_10012278(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10012283 at 10012283

void Unwind_10012283(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001228b at 1001228b

void Unwind_1001228b(void)

{
  int unaff_EBP;
  
  FUN_1000cca0(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10012293 at 10012293

void Unwind_10012293(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001229b at 1001229b

void Unwind_1001229b(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100122a3 at 100122a3

void Unwind_100122a3(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100122ab at 100122ab

void Unwind_100122ab(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@100122d0 at 100122d0

void Unwind_100122d0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100122db at 100122db

void Unwind_100122db(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000ccf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10012310 at 10012310

void Unwind_10012310(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001231b at 1001231b

void Unwind_1001231b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_1000ccf0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10012350 at 10012350

void Unwind_10012350(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10012380 at 10012380

void Unwind_10012380(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100123b0 at 100123b0

void Unwind_100123b0(void)

{
  int unaff_EBP;
  
  FUN_1000ccf0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: FUN_10012420 at 10012420

void FUN_10012420(void)

{
  return;
}



// Function: FUN_10012440 at 10012440

void FUN_10012440(void)

{
  return;
}



// Function: FUN_10012460 at 10012460

void FUN_10012460(void)

{
  FUN_10002480((undefined4 *)&DAT_100184f0);
  _atexit(FUN_10012530);
  return;
}



// Function: FUN_10012490 at 10012490

void FUN_10012490(void)

{
  return;
}



// Function: FUN_100124b0 at 100124b0

void FUN_100124b0(void)

{
  return;
}



// Function: FUN_100124d0 at 100124d0

void FUN_100124d0(void)

{
  return;
}



// Function: FUN_100124e0 at 100124e0

void FUN_100124e0(void)

{
  return;
}



// Function: FUN_10012530 at 10012530

void FUN_10012530(void)

{
  FUN_10003240((undefined4 *)&DAT_100184f0);
  return;
}



// Function: FUN_1001254a at 1001254a

void FUN_1001254a(void)

{
  ATL::CAtlBaseModule::~CAtlBaseModule((CAtlBaseModule *)&DAT_10018534);
  return;
}



// Function: FUN_10012554 at 10012554

void FUN_10012554(void)

{
  ATL::CAtlComModule::Term((CAtlComModule *)&DAT_1001856c);
  return;
}



// Function: FUN_10012560 at 10012560

void FUN_10012560(void)

{
  Ordinal_9(&DAT_10018488);
  return;
}



