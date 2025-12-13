/*
 * Decompiled from: iflb210.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(short *param_1)

{
  if (*param_1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x1000100e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 1) + 0xc))();
    return;
  }
  return;
}



// Function: FUN_10001020 at 10001020

undefined4 * __thiscall FUN_10001020(void *this,byte param_1)

{
  FUN_10008ee0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001050 at 10001050

void __fastcall FUN_10001050(int param_1)

{
  *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
  return;
}



// Function: FUN_10001060 at 10001060

void __fastcall FUN_10001060(undefined4 *param_1)

{
  int *piVar1;
  short sVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000c7cb;
  local_10 = ExceptionList;
  uVar3 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = param_1 + 2;
  *param_1 = iclAllocRef::vftable;
  *piVar1 = (int)iclAllocRef::vftable;
  local_8 = 1;
  sVar2 = (**(code **)(*piVar1 + 8))(uVar3);
  local_8._0_1_ = 2;
  operator_delete((void *)param_1[4]);
  local_8._0_1_ = 1;
  if (sVar2 != 0) {
    (**(code **)(*piVar1 + 0xc))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10004c90(piVar1);
  local_8 = 0xffffffff;
  FUN_10008ee0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001110 at 10001110

void __thiscall FUN_10001110(void *this,ushort param_1)

{
  short sVar1;
  void *_Dst;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c7f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (this == (void *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = (int *)((int)this + 8);
  }
  sVar1 = (**(code **)(*local_14 + 8))(DAT_1001498c ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (*(ushort *)((int)this + 0x14) < param_1) {
    _Dst = operator_new((uint)param_1);
    if (_Dst != (void *)0x0) {
      if (*(ushort *)((int)this + 0x14) != 0) {
        memcpy(_Dst,*(void **)((int)this + 0x10),(uint)*(ushort *)((int)this + 0x14));
      }
      memset((void *)((uint)*(ushort *)((int)this + 0x14) + (int)_Dst),0,
             (uint)param_1 - (uint)*(ushort *)((int)this + 0x14));
      operator_delete(*(void **)((int)this + 0x10));
      *(void **)((int)this + 0x10) = _Dst;
      *(ushort *)((int)this + 0x14) = param_1;
    }
  }
  local_8 = 0xffffffff;
  if (sVar1 != 0) {
    (**(code **)(*local_14 + 0xc))();
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100011f0 at 100011f0

void __thiscall FUN_100011f0(void *this,byte param_1)

{
  FUN_10001200((void *)((int)this + -8),param_1);
  return;
}



// Function: FUN_10001200 at 10001200

undefined4 * __thiscall FUN_10001200(void *this,byte param_1)

{
  FUN_10001060((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: ValueBase at 10001230

/* protected: __thiscall ValueBase::ValueBase(void) */

void __thiscall ValueBase::ValueBase(ValueBase *this)

{
                    /* 0x1230  32  ??0ValueBase@@IAE@XZ */
  *(undefined ***)this = vftable;
  return;
}



// Function: ~ValueBase at 10001240

/* public: virtual __thiscall ValueBase::~ValueBase(void) */

void __thiscall ValueBase::~ValueBase(ValueBase *this)

{
                    /* 0x1240  44  ??1ValueBase@@UAE@XZ */
  *(undefined ***)this = vftable;
  return;
}



// Function: operator++ at 10001250

/* public: virtual void __thiscall ValueBase::operator++(void) */

void __thiscall ValueBase::operator++(ValueBase *this)

{
                    /* 0x1250  82  ??EValueBase@@UAEXXZ
                       0x1250  89  ??FValueBase@@UAEXXZ */
  return;
}



// Function: operator!= at 10001260

/* public: int __thiscall ValueBase::operator!=(class ValueBase const &)const  */

int __thiscall ValueBase::operator!=(ValueBase *this,ValueBase *param_1)

{
  int iVar1;
  
                    /* 0x1260  74  ??9ValueBase@@QBEHABV0@@Z */
  iVar1 = (**(code **)(*(int *)this + 0x18))(param_1);
  return (uint)(iVar1 == 0);
}



// Function: operator> at 10001280

/* public: int __thiscall ValueBase::operator>(class ValueBase const &)const  */

int __thiscall ValueBase::operator>(ValueBase *this,ValueBase *param_1)

{
  int iVar1;
  
                    /* 0x1280  104  ??OValueBase@@QBEHABV0@@Z */
  iVar1 = (**(code **)(*(int *)this + 0x20))(param_1);
  return (uint)(iVar1 == 0);
}



// Function: operator>= at 100012a0

/* public: int __thiscall ValueBase::operator>=(class ValueBase const &)const  */

int __thiscall ValueBase::operator>=(ValueBase *this,ValueBase *param_1)

{
  int iVar1;
  
                    /* 0x12a0  105  ??PValueBase@@QBEHABV0@@Z */
  iVar1 = (**(code **)(*(int *)this + 0x1c))(param_1);
  return (uint)(iVar1 == 0);
}



// Function: FUN_100012c0 at 100012c0

undefined4 * __thiscall FUN_100012c0(void *this,byte param_1)

{
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(this,4,*(int *)((int)this + -4),ValueBase::~ValueBase);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001320 at 10001320

void __thiscall FUN_10001320(void *this,int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  ppuVar3 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar3 + 1);
  do {
    cVar2 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar2 != '\0');
  ppuVar4 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar4 == (undefined **)0x0) {
    ppuVar4 = &PTR_1000e1a4;
  }
  FUN_10008580(*(void **)((int)this + 0xe),(char *)ppuVar4,(int)ppuVar3 - (int)pcVar1 & 0xffff);
  return;
}



// Function: FUN_10001370 at 10001370

int __thiscall FUN_10001370(void *this,int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  
  ppuVar3 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar3 + 1);
  do {
    cVar2 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar2 != '\0');
  ppuVar6 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar6 == (undefined **)0x0) {
    ppuVar6 = &PTR_1000e1a4;
  }
  iVar4 = FUN_10008580((void *)(*(int *)((int)this + 0xe) + 0x20),(char *)ppuVar6,
                       (int)ppuVar3 - (int)pcVar1 & 0xffff);
  if (iVar4 == 0) {
    ppuVar3 = *(undefined ***)(*param_1 + 0x10);
    if (ppuVar3 == (undefined **)0x0) {
      ppuVar3 = &PTR_1000e1a4;
    }
    pcVar1 = (char *)((int)ppuVar3 + 1);
    do {
      cVar2 = *(char *)ppuVar3;
      ppuVar3 = (undefined **)((int)ppuVar3 + 1);
    } while (cVar2 != '\0');
    ppuVar6 = *(undefined ***)(*param_1 + 0x10);
    if (ppuVar6 == (undefined **)0x0) {
      ppuVar6 = &PTR_1000e1a4;
    }
    iVar5 = FUN_10008580((void *)(*(int *)((int)this + 0xe) + 0x40),(char *)ppuVar6,
                         (int)ppuVar3 - (int)pcVar1 & 0xffff);
    if (iVar5 != 0) {
      return *(int *)(iVar5 + 8);
    }
  }
  return iVar4;
}



// Function: FUN_10001410 at 10001410

int __thiscall FUN_10001410(void *this,short param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = FUN_10002940(*(int *)((int)this + 0xe) + 0x20);
  if (iVar1 != 0) {
    do {
      if (iVar2 != 0) {
        return iVar2;
      }
      if (*(short *)(iVar1 + 8) == param_1) {
        iVar2 = iVar1;
      }
      iVar1 = FUN_10002950(*(int *)((int)this + 0xe) + 0x20);
    } while (iVar1 != 0);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  iVar1 = FUN_10002940(*(int *)((int)this + 0xe) + 0x40);
  while ((iVar1 != 0 && (iVar2 == 0))) {
    if (*(short *)(*(int *)(iVar1 + 8) + 8) == param_1) {
      iVar2 = *(int *)(iVar1 + 8);
    }
    iVar1 = FUN_10002950(*(int *)((int)this + 0xe) + 0x40);
  }
  return iVar2;
}



// Function: FUN_10001490 at 10001490

undefined4 __fastcall FUN_10001490(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xe) != 0) {
    uVar1 = FUN_10002940(*(int *)(param_1 + 0xe));
    return uVar1;
  }
  return 0;
}



// Function: FUN_100014a0 at 100014a0

undefined4 __fastcall FUN_100014a0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xe) != 0) {
    uVar1 = FUN_10002950(*(int *)(param_1 + 0xe));
    return uVar1;
  }
  return 0;
}



// Function: FUN_100014b0 at 100014b0

undefined4 * __thiscall FUN_100014b0(void *this,ushort param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c833;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = iclRefCount::vftable;
  *(undefined4 *)((int)this + 4) = 0x10000;
  local_8 = 0;
  FUN_10004c30((undefined4 *)((int)this + 8));
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined ***)this = iclAllocRef::vftable;
  *(undefined ***)((int)this + 8) = iclAllocRef::vftable;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined2 *)((int)this + 0x14) = 0;
  FUN_10001110(this,param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001540 at 10001540

undefined4 * __thiscall FUN_10001540(void *this,char *param_1)

{
  uint uVar1;
  void *this_00;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c85b;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this_00 = operator_new(0x16);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(this_00,0);
  }
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(uVar1);
  }
  FUN_10004ac0(this,param_1,0xffff);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100015d0 at 100015d0

void __fastcall FUN_100015d0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c88b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001620 at 10001620

void __fastcall FUN_10001620(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c8c3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001670 at 10001670

void __fastcall FUN_10001670(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100016c0 at 100016c0

void __thiscall FUN_100016c0(void *this,int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  ppuVar3 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar3 + 1);
  do {
    cVar2 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar2 != '\0');
  ppuVar4 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar4 == (undefined **)0x0) {
    ppuVar4 = &PTR_1000e1a4;
  }
  FUN_10008580(this,(char *)ppuVar4,(int)ppuVar3 - (int)pcVar1 & 0xffff);
  return;
}



// Function: FUN_10001710 at 10001710

undefined4 * __thiscall FUN_10001710(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c8eb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001780 at 10001780

void __thiscall FUN_10001780(void *this,byte param_1)

{
  FUN_10002340((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_10001790 at 10001790

void __fastcall FUN_10001790(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ca66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = NamedObject::vftable;
  local_8 = 0;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001800 at 10001800

undefined4 * __thiscall FUN_10001800(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d888;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001860 at 10001860

undefined4 * __thiscall FUN_10001860(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c92b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100018d0 at 100018d0

undefined4 * __thiscall FUN_100018d0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c963;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001940 at 10001940

undefined4 * __thiscall FUN_10001940(void *this,undefined4 *param_1,undefined2 param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c9a6;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)operator_new(10);
  local_8 = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = NamedObject::vftable;
    piVar1 = (int *)*param_1;
    puVar3[1] = piVar1;
    (**(code **)(*piVar1 + 4))(uVar2);
    *puVar3 = FileItemDef::vftable;
    *(undefined2 *)(puVar3 + 2) = param_2;
    *puVar3 = ParameterDef::vftable;
  }
  local_8 = 0xffffffff;
  if (puVar3 != (undefined4 *)0x0) {
    iVar4 = FUN_10002800(*(void **)((int)this + 0xe),puVar3);
    if (iVar4 != 0) {
      (**(code **)*puVar3)(1);
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
  }
  ExceptionList = local_10;
  return puVar3;
}



// Function: FUN_10001a10 at 10001a10

undefined4 * __thiscall
FUN_10001a10(void *this,undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4
            ,undefined4 param_5)

{
  uint uVar1;
  void *this_00;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c9db;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this_00 = operator_new(0x22);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_1000b800(this_00,this,param_1,param_2,param_3,param_4,param_5);
  }
  local_8 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = FUN_10002800((void *)(*(int *)((int)this + 0xe) + 0x20),puVar2);
    if (iVar3 != 0) {
      (**(code **)*puVar2)(1,uVar1);
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
  }
  ExceptionList = local_10;
  return puVar2;
}



// Function: FUN_10001ac0 at 10001ac0

undefined4 * __thiscall
FUN_10001ac0(void *this,undefined4 param_1,undefined4 *param_2,undefined2 param_3,undefined4 param_4
            )

{
  uint uVar1;
  void *this_00;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c9db;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this_00 = operator_new(0x22);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_1000b880(this_00,this,param_1,param_2,param_3,param_4);
  }
  local_8 = 0xffffffff;
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = FUN_10002800((void *)(*(int *)((int)this + 0xe) + 0x20),puVar2);
    if (iVar3 != 0) {
      (**(code **)*puVar2)(1,uVar1);
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
  }
  ExceptionList = local_10;
  return puVar2;
}



// Function: FUN_10001b70 at 10001b70

undefined4 * __thiscall FUN_10001b70(void *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ca1e;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)operator_new(0xc);
  local_8 = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = NamedObject::vftable;
    piVar1 = *(int **)(param_1 + 4);
    puVar3[1] = piVar1;
    (**(code **)(*piVar1 + 4))(uVar2);
    *puVar3 = ValueBlockDefLink::vftable;
    puVar3[2] = param_1;
  }
  local_8 = 0xffffffff;
  if (puVar3 != (undefined4 *)0x0) {
    iVar4 = FUN_10002800((void *)(*(int *)((int)this + 0xe) + 0x40),puVar3);
    if (iVar4 != 0) {
      (**(code **)*puVar3)(1);
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
  }
  ExceptionList = local_10;
  return puVar3;
}



// Function: FUN_10001c40 at 10001c40

int __thiscall FUN_10001c40(void *this,undefined4 param_1)

{
  void *pvVar1;
  void *this_00;
  void *pvVar2;
  
  this_00 = (void *)FUN_10002940(*(int *)((int)this + 0xe) + 0x20);
  pvVar1 = (void *)0x0;
  while ((this_00 != (void *)0x0 && (pvVar1 == (void *)0x0))) {
    if (*(short *)((int)this_00 + 8) != (short)param_1) {
      this_00 = (void *)FUN_10001c40(this_00,param_1);
    }
    pvVar2 = (void *)FUN_10002950(*(int *)((int)this + 0xe) + 0x20);
    pvVar1 = this_00;
    this_00 = pvVar2;
  }
  return (int)pvVar1;
}



// Function: FUN_10001c90 at 10001c90

int __thiscall FUN_10001c90(void *this,void *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int iVar6;
  
  iVar6 = 1;
  iVar3 = FUN_10002940(*(int *)((int)this + 0xe) + 0x20);
  while ((iVar3 != 0 && (iVar6 != 0))) {
    ppuVar4 = *(undefined ***)(*(int *)(iVar3 + 4) + 0x10);
    if (ppuVar4 == (undefined **)0x0) {
      ppuVar4 = &PTR_1000e1a4;
    }
    pcVar1 = (char *)((int)ppuVar4 + 1);
    do {
      cVar2 = *(char *)ppuVar4;
      ppuVar4 = (undefined **)((int)ppuVar4 + 1);
    } while (cVar2 != '\0');
    ppuVar5 = *(undefined ***)(*(int *)(iVar3 + 4) + 0x10);
    if (ppuVar5 == (undefined **)0x0) {
      ppuVar5 = &PTR_1000e1a4;
    }
    iVar3 = FUN_10008580(param_1,(char *)ppuVar5,(int)ppuVar4 - (int)pcVar1 & 0xffff);
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    iVar3 = FUN_10002950(*(int *)((int)this + 0xe) + 0x20);
  }
  iVar3 = FUN_10002940(*(int *)((int)this + 0xe) + 0x40);
  while ((iVar3 != 0 && (iVar6 != 0))) {
    ppuVar4 = *(undefined ***)(*(int *)(iVar3 + 4) + 0x10);
    if (ppuVar4 == (undefined **)0x0) {
      ppuVar4 = &PTR_1000e1a4;
    }
    pcVar1 = (char *)((int)ppuVar4 + 1);
    do {
      cVar2 = *(char *)ppuVar4;
      ppuVar4 = (undefined **)((int)ppuVar4 + 1);
    } while (cVar2 != '\0');
    ppuVar5 = *(undefined ***)(*(int *)(iVar3 + 4) + 0x10);
    if (ppuVar5 == (undefined **)0x0) {
      ppuVar5 = &PTR_1000e1a4;
    }
    iVar3 = FUN_10008580(param_1,(char *)ppuVar5,(int)ppuVar4 - (int)pcVar1 & 0xffff);
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    iVar3 = FUN_10002950(*(int *)((int)this + 0xe) + 0x40);
  }
  return iVar6;
}



// Function: FUN_10001d70 at 10001d70

undefined4 * __thiscall FUN_10001d70(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_ParameterDef>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_ParameterDef>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001e20 at 10001e20

void __thiscall FUN_10001e20(void *this,byte param_1)

{
  FUN_10002160((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_10001e30 at 10001e30

void __fastcall FUN_10001e30(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_ParameterDef>::vftable;
  param_1[5] = NamedObjectList<class_ParameterDef>::vftable;
  local_8 = 0;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001ec0 at 10001ec0

undefined4 * __thiscall FUN_10001ec0(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_ValueBlockDef>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_ValueBlockDef>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001f70 at 10001f70

void __thiscall FUN_10001f70(void *this,byte param_1)

{
  FUN_10002200((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_10001f80 at 10001f80

void __fastcall FUN_10001f80(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_ValueBlockDef>::vftable;
  param_1[5] = NamedObjectList<class_ValueBlockDef>::vftable;
  local_8 = 0;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002010 at 10002010

undefined4 * __thiscall FUN_10002010(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_ValueBlockDefLink>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_ValueBlockDefLink>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100020c0 at 100020c0

void __thiscall FUN_100020c0(void *this,byte param_1)

{
  FUN_100022a0((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_100020d0 at 100020d0

void __fastcall FUN_100020d0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_ValueBlockDefLink>::vftable;
  param_1[5] = NamedObjectList<class_ValueBlockDefLink>::vftable;
  local_8 = 0;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002160 at 10002160

undefined4 * __thiscall FUN_10002160(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_ParameterDef>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_ParameterDef>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10002200 at 10002200

undefined4 * __thiscall FUN_10002200(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_ValueBlockDef>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_ValueBlockDef>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100022a0 at 100022a0

undefined4 * __thiscall FUN_100022a0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_ValueBlockDefLink>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_ValueBlockDefLink>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10002340 at 10002340

undefined4 * __thiscall FUN_10002340(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ca66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 0;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100023c0 at 100023c0

void * __fastcall FUN_100023c0(void *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cae7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = 1;
  pvVar1 = operator_new(0x16);
  local_8 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(pvVar1,0);
  }
  local_8 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  FUN_10004ac0(&stack0xffffffcc,(char *)&PTR_1000e1a4,0xffff);
  local_8 = 0xffffffff;
  FUN_10001d70(param_1,piVar2,uVar3);
  local_8 = 2;
  uVar3 = 1;
  pvVar1 = operator_new(0x16);
  local_8._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(pvVar1,0);
  }
  local_8._0_1_ = 2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  FUN_10004ac0(&stack0xffffffcc,(char *)&PTR_1000e1a4,0xffff);
  local_8._0_1_ = 2;
  FUN_10001ec0((void *)((int)param_1 + 0x20),piVar2,uVar3);
  local_8._0_1_ = 5;
  uVar3 = 1;
  pvVar1 = operator_new(0x16);
  local_8._0_1_ = 6;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(pvVar1,0);
  }
  local_8._0_1_ = 5;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  FUN_10004ac0(&stack0xffffffcc,(char *)&PTR_1000e1a4,0xffff);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_10002010((void *)((int)param_1 + 0x40),piVar2,uVar3);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002540 at 10002540

void __fastcall FUN_10002540(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000cbb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = param_1 + 0x10;
  *puVar1 = NamedObjectList<class_ValueBlockDefLink>::vftable;
  param_1[0x15] = NamedObjectList<class_ValueBlockDefLink>::vftable;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  FUN_10008550((int)puVar1);
  param_1[0x15] = NamedObject::vftable;
  local_8._0_1_ = 4;
  FUN_10004ab0(param_1 + 0x16);
  *puVar1 = celList<class_NamedObject>::vftable;
  local_8._0_1_ = 1;
  FUN_100029c0(puVar1);
  puVar1 = param_1 + 8;
  *puVar1 = NamedObjectList<class_ValueBlockDef>::vftable;
  param_1[0xd] = NamedObjectList<class_ValueBlockDef>::vftable;
  local_8._0_1_ = 8;
  FUN_10008550((int)puVar1);
  param_1[0xd] = NamedObject::vftable;
  local_8._0_1_ = 9;
  FUN_10004ab0(param_1 + 0xe);
  *puVar1 = celList<class_NamedObject>::vftable;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100029c0(puVar1);
  *param_1 = NamedObjectList<class_ParameterDef>::vftable;
  param_1[5] = NamedObjectList<class_ParameterDef>::vftable;
  local_8 = 0xd;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 0xe;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002680 at 10002680

undefined4 * __thiscall
FUN_10002680(void *this,undefined4 param_1,undefined4 *param_2,undefined2 param_3)

{
  int *piVar1;
  uint uVar2;
  void *pvVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cc06;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObject::vftable;
  piVar1 = (int *)*param_2;
  *(int **)((int)this + 4) = piVar1;
  (**(code **)(*piVar1 + 4))(uVar2);
  *(undefined ***)this = FileItemDef::vftable;
  *(undefined2 *)((int)this + 8) = param_3;
  local_8 = 2;
  *(undefined ***)this = FileBlockDef::vftable;
  *(undefined4 *)((int)this + 10) = param_1;
  pvVar3 = operator_new(0x60);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = FUN_100023c0(pvVar3);
  }
  *(void **)((int)this + 0xe) = pvVar3;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10002730 at 10002730

void __fastcall FUN_10002730(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000cc4b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = FileBlockDef::vftable;
  local_8 = 0;
  puVar1 = *(undefined4 **)((int)param_1 + 0xe);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10002540(puVar1);
    operator_delete(puVar1);
  }
  *param_1 = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100027b0 at 100027b0

undefined4 * __thiscall FUN_100027b0(void *this,byte param_1)

{
  FUN_10002730((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100027e0 at 100027e0

void __fastcall FUN_100027e0(undefined4 *param_1)

{
  *param_1 = celListBase::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10002800 at 10002800

undefined4 __thiscall FUN_10002800(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c9db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
    puVar1[1] = 0;
  }
  if (puVar1 != (undefined4 *)0x0) {
    if (*(int *)((int)this + 8) != 0) {
      *(undefined4 **)(*(int *)((int)this + 0x10) + 4) = puVar1;
      *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
      *(undefined4 **)((int)this + 0x10) = puVar1;
      ExceptionList = local_10;
      return 0;
    }
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
    *(undefined4 **)((int)this + 8) = puVar1;
    *(undefined4 **)((int)this + 0x10) = puVar1;
    ExceptionList = local_10;
    return 0;
  }
  ExceptionList = local_10;
  return 2;
}



// Function: FUN_100028b0 at 100028b0

undefined4 __thiscall FUN_100028b0(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar2 = *(int **)((int)this + 8);
  piVar4 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    if (*piVar2 == param_1) {
      *(int *)((int)this + 8) = piVar2[1];
      piVar4 = piVar2;
    }
    else {
      if (piVar2[1] == 0) {
        return 0x10;
      }
      do {
        if (piVar4 != (int *)0x0) goto LAB_10002908;
        piVar1 = (int *)piVar2[1];
        piVar3 = piVar1;
        if ((*piVar1 == param_1) &&
           (piVar2[1] = piVar1[1], piVar3 = piVar2, piVar4 = piVar1,
           *(int **)((int)this + 0x10) == piVar1)) {
          *(int **)((int)this + 0x10) = piVar2;
        }
        piVar2 = piVar3;
      } while (piVar3[1] != 0);
    }
    if (piVar4 != (int *)0x0) {
LAB_10002908:
      if (*(int **)((int)this + 4) == piVar4) {
        *(undefined4 *)((int)this + 4) = 0;
      }
      operator_delete(piVar4);
      *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
      return 0;
    }
  }
  return 0x10;
}



// Function: FUN_10002940 at 10002940

undefined4 __fastcall FUN_10002940(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  uVar2 = 0;
  *(undefined4 **)(param_1 + 4) = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = *puVar1;
  }
  return uVar2;
}



// Function: FUN_10002950 at 10002950

undefined4 __fastcall FUN_10002950(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar3 = 0;
  if (iVar1 == 0) {
    puVar2 = *(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 4) = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = *puVar2;
    }
  }
  else if (iVar1 != *(int *)(param_1 + 0x10)) {
    puVar2 = *(undefined4 **)(iVar1 + 4);
    *(undefined4 **)(param_1 + 4) = puVar2;
    return *puVar2;
  }
  return uVar3;
}



// Function: FUN_10002980 at 10002980

void __fastcall FUN_10002980(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  while (iVar1 != 0) {
    pvVar2 = *(void **)(param_1 + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)((int)pvVar2 + 4);
    operator_delete(pvVar2);
    iVar1 = *(int *)(param_1 + 8);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



// Function: FUN_100029c0 at 100029c0

void __fastcall FUN_100029c0(undefined4 *param_1)

{
  *param_1 = celListBase::vftable;
  FUN_10002980((int)param_1);
  return;
}



// Function: FUN_100029d0 at 100029d0

undefined4 * __thiscall FUN_100029d0(void *this,byte param_1)

{
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002a00 at 10002a00

uint __cdecl FUN_10002a00(uint param_1,byte *param_2,ushort param_3)

{
  undefined4 in_EAX;
  byte bVar1;
  ushort uVar2;
  
  bVar1 = *param_2;
  uVar2 = 0;
  if (bVar1 == 0) {
    return CONCAT22((short)((uint)in_EAX >> 0x10),(undefined2)param_1);
  }
  do {
    if ((param_3 != 0) && (param_3 <= uVar2)) {
      return param_1;
    }
    if (0x1f < bVar1) {
      param_1 = (uint)((ushort)(param_1 >> 7) & 0x1fe ^
                      *(ushort *)(&DAT_10014218 + ((bVar1 ^ param_1) & 0xff) * 2));
    }
    bVar1 = param_2[1];
    param_2 = param_2 + 1;
    uVar2 = uVar2 + 1;
  } while (bVar1 != 0);
  return param_1;
}



// Function: FUN_10002a60 at 10002a60

void __thiscall FUN_10002a60(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009600(this,param_1);
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x50) = 0;
  }
  return;
}



// Function: FUN_10002a80 at 10002a80

int __fastcall FUN_10002a80(int *param_1)

{
  int iVar1;
  char *_Src;
  undefined **ppuVar2;
  int *local_8;
  
  local_8 = param_1;
  iVar1 = FUN_10009490(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_10009030(param_1);
    if (iVar1 == 0) {
      if (param_1[0x13] == 0) {
        _Src = PTR_PTR_10014418;
        if (*(int *)((int)param_1 + 0x32) != 0) {
          _Src = *(char **)((int)param_1 + 0x3a);
        }
        sscanf_s(_Src,"%lx",&local_8);
        *(undefined2 *)(param_1 + 0x15) = 0;
        *(undefined2 *)((int)param_1 + 0x4a) = local_8._0_2_;
        param_1[0x14] = 1;
        return 0;
      }
    }
    else if ((iVar1 == 0x1a) || (iVar1 == 0x22)) {
      ppuVar2 = *(undefined ***)(param_1[1] + 0x10);
      if (ppuVar2 == (undefined **)0x0) {
        ppuVar2 = &PTR_1000e1a4;
      }
      iclError("File CRC missing: %s",ppuVar2);
      iVar1 = 0x19;
    }
  }
  return iVar1;
}



// Function: FUN_10002b20 at 10002b20

int __thiscall FUN_10002b20(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_100097b0(this,param_1);
  if ((*(int *)((int)this + 0x4c) == 0) && (*(int *)((int)this + 0x50) != 0)) {
    if (iVar1 == 0) {
      uVar2 = FUN_10002a00((uint)*(ushort *)((int)this + 0x54),*(byte **)((int)this + 0x1c),
                           (short)*(undefined4 *)((int)this + 0x24) -
                           (short)*(byte **)((int)this + 0x1c));
      *(short *)((int)this + 0x54) = (short)uVar2;
      return 0;
    }
    if (iVar1 == 0x22) {
      *(uint *)((int)this + 0x4c) =
           (*(short *)((int)this + 0x54) != *(short *)((int)this + 0x4a)) + 1;
    }
  }
  return iVar1;
}



// Function: FUN_10002b90 at 10002b90

int __fastcall FUN_10002b90(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1[0x13] == 0) {
    if (param_1[0x14] == 0) {
      iVar2 = (**(code **)(*param_1 + 8))();
    }
    iVar1 = param_1[0x14];
    while ((iVar1 != 0 && (iVar2 == 0))) {
      iVar2 = (**(code **)(*param_1 + 0x14))(1);
      iVar1 = param_1[0x14];
    }
    if (iVar2 == 0x22) {
      iVar2 = 0;
    }
  }
  return iVar2;
}



// Function: FUN_10002bd0 at 10002bd0

void __thiscall FUN_10002bd0(void *this,char *param_1,rsize_t param_2)

{
  char cVar1;
  char *pcVar2;
  char *_Src;
  rsize_t rVar3;
  rsize_t rVar4;
  
  if (param_1 != (char *)0x0) {
    if (param_2 == 0) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      param_2 = (int)pcVar2 - (int)(param_1 + 1);
    }
    rVar3 = 0;
    if (*(uint *)((int)this + 8) < *(int *)((int)this + 4) + param_2) {
                    /* WARNING: Load size is inaccurate */
      rVar4 = rVar3;
      do {
        rVar3 = param_2;
        if (*this != 0) {
          rVar3 = rVar4 + *this;
        }
        rVar4 = rVar3;
      } while (*(int *)((int)this + 8) + rVar3 < *(int *)((int)this + 4) + param_2);
      if ((rVar3 != 0) &&
         (pcVar2 = (char *)operator_new(*(int *)((int)this + 8) + 1 + rVar3), pcVar2 != (char *)0x0)
         ) {
        _Src = PTR_PTR_10014418;
        if (*(int *)((int)this + 4) != 0) {
          _Src = *(char **)((int)this + 0xc);
        }
        strcpy_s(pcVar2,*(int *)((int)this + 8) + 1 + rVar3,_Src);
        *(int *)((int)this + 8) = *(int *)((int)this + 8) + rVar3;
        operator_delete(*(void **)((int)this + 0xc));
        *(char **)((int)this + 0xc) = pcVar2;
      }
    }
    if ((*(int *)((int)this + 4) + param_2 <= *(uint *)((int)this + 8)) &&
       (*(int *)((int)this + 0xc) != 0)) {
      strncpy_s((char *)(*(int *)((int)this + 0xc) + *(int *)((int)this + 4)),
                *(uint *)((int)this + 8) + 1 + rVar3,param_1,param_2);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_2;
      *(undefined1 *)(*(int *)((int)this + 4) + *(int *)((int)this + 0xc)) = 0;
    }
  }
  return;
}



// Function: FUN_10002cc0 at 10002cc0

void __thiscall FUN_10002cc0(void *this,char *param_1,rsize_t param_2)

{
  *(undefined4 *)((int)this + 4) = 0;
  if (param_1 != (char *)0x0) {
    FUN_10002bd0(this,param_1,param_2);
  }
  return;
}



// Function: FUN_10002ce0 at 10002ce0

undefined4 * __thiscall FUN_10002ce0(void *this,char *param_1,undefined4 param_2)

{
  *(undefined4 *)this = param_2;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  FUN_10002bd0(this,param_1,0);
  return (undefined4 *)this;
}



// Function: getType at 10002d10

/* public: virtual enum VBType __thiscall IncValueT<unsigned char,0>::getType(void)const  */

VBType __thiscall IncValueT<unsigned_char,0>::getType(IncValueT<unsigned_char,0> *this)

{
                    /* 0x2d10  165  ?getType@?$IncValueT@E$0A@@@UBE?AW4VBType@@XZ */
  return 0;
}



// Function: FUN_10002d20 at 10002d20

void __fastcall FUN_10002d20(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c963;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = NamedValue::vftable;
  local_8 = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1,uVar1);
  }
  *param_1 = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: InputFile at 10002d90

/* public: __thiscall InputFile::InputFile(class InputFile const &) */

void __thiscall InputFile::InputFile(InputFile *this,InputFile *param_1)

{
                    /* 0x2d90  24  ??0InputFile@@QAE@ABV0@@Z */
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return;
}



// Function: FUN_10002de0 at 10002de0

InputFile * __thiscall FUN_10002de0(void *this,byte param_1)

{
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_(this,0x24,*(int *)((int)this + -4),InputFile::~InputFile);
    if ((param_1 & 1) != 0) {
      operator_delete__((InputFile *)((int)this + -4));
    }
    return (InputFile *)((int)this + -4);
  }
  InputFile::~InputFile((InputFile *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (InputFile *)this;
}



// Function: enableCRC at 10002e40

/* protected: void __thiscall InputFile::enableCRC(void) */

void __thiscall InputFile::enableCRC(InputFile *this)

{
                    /* 0x2e40  152  ?enableCRC@InputFile@@IAEXXZ */
  *(undefined4 *)(this + 0x18) = 1;
  return;
}



// Function: disableCRC at 10002e50

/* protected: void __thiscall InputFile::disableCRC(void) */

void __thiscall InputFile::disableCRC(InputFile *this)

{
                    /* 0x2e50  150  ?disableCRC@InputFile@@IAEXXZ */
  *(undefined4 *)(this + 0x18) = 0;
  return;
}



// Function: FUN_10002e60 at 10002e60

undefined4 __fastcall FUN_10002e60(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    return CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 8));
  }
  return 0xffff;
}



// Function: FUN_10002e80 at 10002e80

ICLStatus __thiscall FUN_10002e80(void *this,int *param_1,char *param_2,long param_3)

{
  int iVar1;
  ICLStatus IVar2;
  
  iVar1 = FUN_10001320(*(void **)((int)this + 0xc),param_1);
  if (iVar1 != 0) {
    IVar2 = InputFile::setParamValue
                      (*(InputFile **)((int)this + 4),*(ushort *)(iVar1 + 8),param_2,param_3);
    return IVar2;
  }
  return 0;
}



// Function: FUN_10002ec0 at 10002ec0

void __fastcall FUN_10002ec0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dd2b;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = NamedValue::vftable;
  local_8 = 1;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1,uVar1);
  }
  *param_1 = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002f40 at 10002f40

ICLStatus __thiscall FUN_10002f40(void *this,void *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  short extraout_DX;
  ICLStatus IVar3;
  undefined4 local_28 [6];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cc78;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  IVar3 = 0x13;
  if ((*(int *)((int)this + 0x14) != 0) &&
     (uVar2 = FUN_10002e60(*(int *)((int)this + 0x14)), (short)uVar2 == extraout_DX)) {
    if ((*(int *)((int)this + 0x20) <= *(int *)((int)this + 0x1c)) ||
       (*(int *)((int)this + 0x18) == -1)) {
      ExceptionList = local_10;
      return 0x10;
    }
    IVar3 = (**(code **)(**(int **)((int)this + 8) + 0xc))(*(int *)((int)this + 0x18),uVar1);
    if (IVar3 == 0) {
      FUN_1000b9b0(local_28,(undefined4 *)((int)param_1 + 4),
                   *(int *)((int)this + 0x20) - *(int *)((int)this + 0x1c),
                   *(VBType *)((int)param_1 + 0x12),0);
      local_8 = 0;
      IVar3 = FUN_1000bb70(local_28,*(void **)((int)this + 0x14));
      if ((IVar3 == 0) &&
         (IVar3 = FUN_10006d80(*(void **)((int)this + 8),param_1,*(int **)((int)this + 0x14),
                               local_28,(int *)0x0), IVar3 == 0)) {
        uVar2 = *(undefined4 *)(*(int *)((int)this + 8) + 0x42);
        *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
        *(undefined4 *)((int)this + 0x18) = uVar2;
        *(undefined4 *)((int)this + 0x24) = 0;
      }
      local_8 = 0xffffffff;
      FUN_10002ec0(local_28);
    }
  }
  ExceptionList = local_10;
  return IVar3;
}



// Function: FUN_10003050 at 10003050

void __fastcall FUN_10003050(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar1 = FUN_10001490(*(int *)(param_1 + 0xc));
    while (iVar1 != 0) {
      InputFile::clearParamValue(*(InputFile **)(param_1 + 4),*(ushort *)(iVar1 + 8));
      iVar1 = FUN_100014a0(*(int *)(param_1 + 0xc));
    }
  }
  return;
}



// Function: FUN_10003080 at 10003080

void __fastcall FUN_10003080(undefined4 *param_1)

{
  *param_1 = FileBlock::vftable;
  FUN_10003110(param_1,0);
  return;
}



// Function: FUN_10003090 at 10003090

undefined4 * __thiscall FUN_10003090(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000c963;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedValue::vftable;
  local_8 = 0;
  if (*(undefined4 **)((int)this + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 8))(1,uVar1);
  }
  *(undefined ***)this = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003110 at 10003110

void __thiscall FUN_10003110(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (*(undefined4 **)((int)this + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 0x14))(1);
  }
                    /* WARNING: Load size is inaccurate */
  pcVar1 = *(code **)(*this + 4);
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_10003050((int)this);
  }
  *(int *)((int)this + 0xc) = param_1;
  FUN_10003050((int)this);
  return;
}



// Function: FUN_10003170 at 10003170

ICLStatus __thiscall FUN_10003170(void *this,short param_1)

{
  void *pvVar1;
  ICLStatus IVar2;
  
  if (*(void **)((int)this + 0xc) != (void *)0x0) {
    pvVar1 = (void *)FUN_10001410(*(void **)((int)this + 0xc),param_1);
    if (pvVar1 != (void *)0x0) {
      IVar2 = FUN_10002f40(this,pvVar1);
      return IVar2;
    }
  }
  return 0x13;
}



// Function: FUN_100031b0 at 100031b0

ICLStatus __thiscall FUN_100031b0(void *this,void *param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  short sVar3;
  ICLStatus IVar4;
  undefined4 uVar5;
  undefined **ppuVar6;
  void *this_00;
  int iVar7;
  void *this_01;
  int extraout_EDX;
  undefined **ppuVar8;
  undefined4 local_2c [4];
  int local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cca8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  IVar4 = 0x10;
  if (*(int *)((int)this + 0x14) != 0) {
    sVar3 = *(short *)((int)param_1 + 8);
    uVar5 = FUN_10002e60(*(int *)((int)this + 0x14));
    iVar7 = extraout_EDX;
    if ((short)uVar5 == sVar3) {
      if (param_2 == (int *)0x0) {
        iVar7 = CONCAT31((int3)((uint)extraout_EDX >> 8),*(int *)((int)this + 0x1c) == 1);
      }
      else {
        iVar7 = FUN_1000b710(this_01,param_2);
      }
    }
    if ((*(int *)((int)this + 0x24) == 0) && (iVar7 != 0)) {
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)((int)this + 0x10) == 0) {
      ExceptionList = local_10;
      return 0x13;
    }
    ppuVar6 = *(undefined ***)(*(int *)((int)param_1 + 4) + 0x10);
    if (ppuVar6 == (undefined **)0x0) {
      ppuVar6 = &PTR_1000e1a4;
    }
    pcVar1 = (char *)((int)ppuVar6 + 1);
    do {
      cVar2 = *(char *)ppuVar6;
      ppuVar6 = (undefined **)((int)ppuVar6 + 1);
    } while (cVar2 != '\0');
    ppuVar8 = *(undefined ***)(*(int *)((int)param_1 + 4) + 0x10);
    if (ppuVar8 == (undefined **)0x0) {
      ppuVar8 = &PTR_1000e1a4;
    }
    this_00 = (void *)FUN_10008580(*(void **)((int)this + 0x10),(char *)ppuVar8,
                                   (int)ppuVar6 - (int)pcVar1 & 0xffff);
    if (this_00 == (void *)0x0) {
      IVar4 = 0x10;
    }
    else {
      if (param_2 == (int *)0x0) {
        IVar4 = FUN_10003a40((int)this_00);
      }
      else {
        IVar4 = FUN_10003920(this_00,param_2);
      }
      if (IVar4 == 0) {
        uVar5 = FUN_10003a60((int)this_00);
        local_14 = (int *)FUN_10003a80((int)this_00);
        iVar7 = FUN_10003aa0((int)this_00);
        *(int *)((int)this + 0x1c) = iVar7;
        *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this_00 + 0x14);
        IVar4 = (**(code **)(**(int **)((int)this + 8) + 0xc))(uVar5);
        if (IVar4 == 0) {
          FUN_1000b9b0(local_2c,(undefined4 *)((int)param_1 + 4),
                       *(int *)((int)this + 0x20) - *(int *)((int)this + 0x1c),
                       *(VBType *)((int)param_1 + 0x12),0);
          local_8 = 0;
          IVar4 = FUN_1000bb10(local_2c,local_14);
          if (IVar4 == 0) {
            IVar4 = FUN_1000bac0(local_2c,(char *)0x0,-1);
            if (IVar4 == 0) {
              IVar4 = FUN_10006d80(*(void **)((int)this + 8),param_1,*(int **)((int)this + 0x14),
                                   local_2c,param_2);
              if (IVar4 == 0) {
                *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(*(int *)((int)this + 8) + 0x42);
                *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x20) - local_1c;
                *(undefined4 *)((int)this + 0x24) = 0;
              }
              else {
                *(undefined4 *)((int)this + 0x18) = 0xffffffff;
                *(undefined4 *)((int)this + 0x1c) = 0;
              }
            }
          }
          local_8 = 0xffffffff;
          FUN_10002ec0(local_2c);
          ExceptionList = local_10;
          return IVar4;
        }
      }
    }
  }
  ExceptionList = local_10;
  return IVar4;
}



// Function: FUN_100033b0 at 100033b0

undefined4 __thiscall FUN_100033b0(void *this,short param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (*(void **)((int)this + 0xc) != (void *)0x0) {
    iVar1 = FUN_10001410(*(void **)((int)this + 0xc),param_1);
    if ((iVar1 != 0) && (*(void **)((int)this + 0x10) != (void *)0x0)) {
      iVar1 = FUN_100016c0(*(void **)((int)this + 0x10),(int *)(iVar1 + 4));
      if (iVar1 != 0) {
        *param_2 = *(undefined4 *)(iVar1 + 0x14);
        return 0;
      }
      *param_2 = 0;
      return 0;
    }
  }
  return 0x13;
}



// Function: FUN_10003410 at 10003410

undefined4 * __thiscall FUN_10003410(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_FileIndex>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_FileIndex>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100034c0 at 100034c0

void __thiscall FUN_100034c0(void *this,byte param_1)

{
  FUN_10003560((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_100034d0 at 100034d0

void __fastcall FUN_100034d0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_FileIndex>::vftable;
  param_1[5] = NamedObjectList<class_FileIndex>::vftable;
  local_8 = 0;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003560 at 10003560

undefined4 * __thiscall FUN_10003560(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_FileIndex>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_FileIndex>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003600 at 10003600

undefined4 * __thiscall FUN_10003600(void *this,byte param_1)

{
  *(undefined ***)this = FileBlock::vftable;
  FUN_10003110(this,0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003630 at 10003630

undefined4 * __thiscall
FUN_10003630(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *this_00;
  int *piVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000cd46;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = FileBlock::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  local_8 = 0;
  uVar2 = 1;
  *(undefined ***)this = ValueBlock::vftable;
  *(undefined4 *)((int)this + 0x28) = param_3;
  *(undefined4 *)((int)this + 0x2c) = 0;
  this_00 = operator_new(0x16);
  local_8._0_1_ = 1;
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_100014b0(this_00,0);
  }
  local_8._0_1_ = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  FUN_10004ac0(&stack0xffffffd4,(char *)&PTR_1000e1a4,0xffff);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10003410((void *)((int)this + 0x30),piVar1,uVar2);
  *(void **)((int)this + 0x10) = (void *)((int)this + 0x30);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003720 at 10003720

undefined4 __fastcall FUN_10003720(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



// Function: FUN_10003730 at 10003730

void __fastcall FUN_10003730(int *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000cdb1;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = (int)ValueBlock::vftable;
  local_8 = 1;
  (**(code **)(*param_1 + 8))(0,uVar2);
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  piVar1 = param_1 + 0xc;
  *piVar1 = (int)NamedObjectList<class_FileIndex>::vftable;
  param_1[0x11] = (int)NamedObjectList<class_FileIndex>::vftable;
  local_8._0_1_ = 2;
  FUN_10008550((int)piVar1);
  param_1[0x11] = (int)NamedObject::vftable;
  local_8._0_1_ = 3;
  FUN_10004ab0(param_1 + 0x12);
  *piVar1 = (int)celList<class_NamedObject>::vftable;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100029c0(piVar1);
  local_8 = 0xffffffff;
  *param_1 = (int)FileBlock::vftable;
  FUN_10003110(param_1,0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100037f0 at 100037f0

undefined4 __thiscall FUN_100037f0(void *this,int *param_1)

{
  int iVar1;
  void *this_00;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cddb;
  local_10 = ExceptionList;
  if (*(void **)((int)this + 0xc) == (void *)0x0) {
    return 0x13;
  }
  ExceptionList = &local_10;
  iVar1 = FUN_10001370(*(void **)((int)this + 0xc),param_1);
  if ((iVar1 != 0) && (*(int *)((int)this + 0x14) == 0)) {
    this_00 = operator_new(0x50);
    local_8 = 0;
    if (this_00 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_10003630(this_00,*(undefined4 *)((int)this + 4),*(undefined4 *)((int)this + 8),
                            this);
    }
    *(undefined4 **)((int)this + 0x14) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      ExceptionList = local_10;
      return 2;
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_100038b0 at 100038b0

ICLStatus __thiscall FUN_100038b0(void *this,short param_1,int *param_2)

{
  void *pvVar1;
  ICLStatus IVar2;
  
  if (*(void **)((int)this + 0xc) != (void *)0x0) {
    pvVar1 = (void *)FUN_10001410(*(void **)((int)this + 0xc),param_1);
    if (pvVar1 != (void *)0x0) {
      IVar2 = FUN_100031b0(this,pvVar1,param_2);
      return IVar2;
    }
  }
  return 0x13;
}



// Function: FUN_100038f0 at 100038f0

int * __thiscall FUN_100038f0(void *this,byte param_1)

{
  FUN_10003730((int *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_10003920 at 10003920

undefined4 __thiscall FUN_10003920(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *local_8;
  
  piVar2 = param_1;
  iVar4 = *(int *)((int)this + 0x2c);
  *(undefined4 *)((int)this + 0xc) = 0xffff;
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 != iVar4) {
    return 5;
  }
  if (*(int *)((int)this + 0x10) != 0) {
    iVar4 = *param_1;
    iVar3 = FUN_100099d0((void *)((int)this + 0x28),0);
    iVar4 = (**(code **)(iVar4 + 0x20))(iVar3);
    if (iVar4 == 0) {
      iVar4 = FUN_100099d0((void *)((int)this + 0x28),*(int *)((int)this + 0x10) + -1);
      iVar4 = (**(code **)(*param_1 + 0x1c))(iVar4);
      if (iVar4 == 0) {
        *(int *)((int)this + 0xc) = *(int *)((int)this + 0x10) + -1;
      }
      else {
        param_1 = (int *)0x0;
        local_8 = (int *)(*(int *)((int)this + 0x10) - 1);
        piVar1 = param_1;
        piVar5 = local_8;
        while ((int *)0x1 < piVar5) {
          iVar4 = *piVar2;
          piVar5 = (int *)((uint)((int)local_8 + (int)piVar1) >> 1);
          iVar3 = FUN_100099d0((void *)((int)this + 0x28),(int)piVar5);
          iVar4 = (**(code **)(iVar4 + 0x1c))(iVar3);
          param_1 = piVar5;
          if (iVar4 != 0) {
            param_1 = piVar1;
            local_8 = piVar5;
          }
          piVar1 = param_1;
          piVar5 = (int *)((int)local_8 - (int)param_1);
        }
        *(int **)((int)this + 0xc) = piVar1;
      }
    }
    else {
      iVar4 = *param_1;
      iVar3 = FUN_100099d0((void *)((int)this + 0x28),0);
      iVar4 = (**(code **)(iVar4 + 0x18))(iVar3);
      if (iVar4 != 0) {
        *(undefined4 *)((int)this + 0xc) = 0;
      }
    }
  }
  if (*(int *)((int)this + 0xc) == 0xffff) {
    return 0x10;
  }
  return 0;
}



// Function: FUN_10003a40 at 10003a40

undefined4 __fastcall FUN_10003a40(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0xffff;
  if (*(int *)(param_1 + 0x10) != 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    return 0;
  }
  return 0x10;
}



// Function: FUN_10003a60 at 10003a60

undefined4 __fastcall FUN_10003a60(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + *(uint *)(param_1 + 0xc) * 4);
  }
  return uVar1;
}



// Function: FUN_10003a80 at 10003a80

int __fastcall FUN_10003a80(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) {
    iVar1 = FUN_100099d0((void *)(param_1 + 0x28),*(uint *)(param_1 + 0xc));
  }
  return iVar1;
}



// Function: FUN_10003aa0 at 10003aa0

int __fastcall FUN_10003aa0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) {
    iVar1 = (int)(*(int *)(param_1 + 0x14) * *(uint *)(param_1 + 0xc) + -1 + *(int *)(param_1 + 8))
            / *(int *)(param_1 + 8) + 1;
  }
  return iVar1;
}



// Function: FUN_10003ac0 at 10003ac0

undefined4 * __thiscall
FUN_10003ac0(void *this,undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
            int param_5)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ce1e;
  local_10 = ExceptionList;
  uVar3 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObject::vftable;
  piVar1 = (int *)*param_1;
  *(int **)((int)this + 4) = piVar1;
  (**(code **)(*piVar1 + 4))(uVar3);
  local_8 = 1;
  *(undefined4 *)((int)this + 0x14) = param_3;
  *(undefined ***)this = FileIndex::vftable;
  *(undefined4 *)((int)this + 0xc) = 0xffff;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  FUN_1000b070((void *)((int)this + 0x28),param_2,0);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_4 < 1) {
    *(undefined4 *)((int)this + 8) = 1;
  }
  else {
    iVar4 = *(int *)((int)this + 0x14);
    if (param_5 < param_4) {
      iVar4 = (iVar4 * param_5 + -1) / param_4 + 1;
    }
    *(int *)((int)this + 8) = iVar4;
  }
  if (*(uint *)((int)this + 8) != 0) {
    FUN_1000aca0((void *)((int)this + 0x28),*(uint *)((int)this + 8));
    lVar2 = (ulonglong)*(uint *)((int)this + 8) * 4;
    pvVar5 = operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(void **)((int)this + 0x1c) = pvVar5;
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003bb0 at 10003bb0

undefined4 * __thiscall
FUN_10003bb0(void *this,uint param_1,undefined4 *param_2,VBType param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  void *pvVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000ce1e;
  local_10 = ExceptionList;
  uVar3 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObject::vftable;
  piVar1 = (int *)*param_2;
  *(int **)((int)this + 4) = piVar1;
  (**(code **)(*piVar1 + 4))(uVar3);
  local_8 = 1;
  *(undefined ***)this = FileIndex::vftable;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0xffff;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(int *)((int)this + 0x14) = param_4;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  FUN_1000b070((void *)((int)this + 0x28),param_3,0);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (0x34 < param_1) {
    uVar3 = ValueBase::dataSize(param_3);
    uVar3 = (param_1 - 0x34) / (uVar3 + 4);
    *(uint *)((int)this + 8) = uVar3;
    if (param_4 < (int)uVar3) {
      *(int *)((int)this + 8) = param_4;
    }
    if (*(uint *)((int)this + 8) != 0) {
      FUN_1000aca0((void *)((int)this + 0x28),*(uint *)((int)this + 8));
      lVar2 = (ulonglong)*(uint *)((int)this + 8) * 4;
      pvVar4 = operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
      *(void **)((int)this + 0x1c) = pvVar4;
    }
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10003cb0 at 10003cb0

void __fastcall FUN_10003cb0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000ce5e;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FileIndex::vftable;
  local_8 = 1;
  operator_delete__((void *)param_1[7]);
  param_1[7] = 0;
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1,uVar1);
  }
  param_1[6] = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_1000b0a0(param_1 + 10);
  *param_1 = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10003d50 at 10003d50

int __thiscall FUN_10003d50(void *this,int *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_8;
  
  bVar1 = false;
  iVar3 = *(int *)((int)this + 0x2c);
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == iVar3) {
    local_8 = 0;
    if (*(int *)((int)this + 0x20) <= *(int *)((int)this + 0x24)) {
      *(int *)((int)this + 0x20) = *(int *)((int)this + 0x14) + *(int *)((int)this + 0x20);
      bVar1 = true;
    }
  }
  else {
    local_8 = 5;
  }
  if (((*(int **)((int)this + 0x18) != (int *)0x0) && (local_8 == 0)) &&
     (iVar3 = (**(code **)(**(int **)((int)this + 0x18) + 0x1c))(param_1), iVar3 == 0)) {
    local_8 = 0x24;
  }
  if ((bVar1) && (local_8 == 0)) {
    if (*(uint *)((int)this + 0x10) < *(uint *)((int)this + 8)) {
      if (*(int *)((int)this + 0x18) == 0) {
        iVar3 = (**(code **)(*param_1 + 8))();
        *(int *)((int)this + 0x18) = iVar3;
        if (iVar3 == 0) {
          local_8 = 2;
          goto LAB_10003e19;
        }
      }
      piVar4 = (int *)FUN_100099d0((void *)((int)this + 0x28),*(int *)((int)this + 0x10));
      (**(code **)(*piVar4 + 0x14))(param_1);
      *(undefined4 *)(*(int *)((int)this + 0x1c) + *(int *)((int)this + 0x10) * 4) = param_2;
      *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
    }
    else {
      local_8 = 0x25;
    }
  }
LAB_10003e19:
  if (*(int **)((int)this + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0x18) + 0x14))(param_1);
  }
  if (local_8 == 0) {
    *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + *(int *)((int)this + 8);
  }
  return local_8;
}



// Function: FUN_10003e40 at 10003e40

undefined4 * __thiscall FUN_10003e40(void *this,byte param_1)

{
  FUN_10003cb0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003e70 at 10003e70

void __thiscall FUN_10003e70(void *this,basic_istream<char,struct_std::char_traits<char>_> *param_1)

{
  ushort uVar1;
  int iVar2;
  char unaff_BL;
  char unaff_SI;
  char unaff_DI;
  char local_48 [8];
  undefined4 uStack_40;
  uint local_8;
  
  local_8 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  if (((byte)param_1[*(int *)(*(int *)param_1 + 4) + 0xc] & 1) == 0) {
    std::basic_istream<char,struct_std::char_traits<char>_>::get
              (param_1,local_48,0x2f00000000,unaff_BL);
    std::basic_istream<char,struct_std::char_traits<char>_>::get(param_1);
    iVar2 = atoi(local_48);
    *(short *)this = (short)iVar2;
    if (((byte)param_1[*(int *)(*(int *)param_1 + 4) + 0xc] & 1) == 0) {
      std::basic_istream<char,struct_std::char_traits<char>_>::get
                (param_1,local_48,0x2f00000000,unaff_DI);
      std::basic_istream<char,struct_std::char_traits<char>_>::get(param_1);
      iVar2 = atoi(local_48);
      *(short *)((int)this + 2) = (short)iVar2;
      if (((byte)param_1[*(int *)(*(int *)param_1 + 4) + 0xc] & 1) == 0) {
        std::basic_istream<char,struct_std::char_traits<char>_>::get
                  (param_1,local_48,0x2f00000000,unaff_SI);
        iVar2 = atoi(local_48);
        uVar1 = (ushort)iVar2;
        *(ushort *)((int)this + 6) = uVar1;
        if ((uVar1 < 100) &&
           (*(ushort *)((int)this + 6) = uVar1 + 0x76c, (ushort)(uVar1 + 0x76c) < 0x7b2)) {
          *(ushort *)((int)this + 6) = uVar1 + 2000;
        }
        *(undefined2 *)((int)this + 4) = 1;
      }
    }
  }
  uStack_40 = 0x10003f58;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003f60 at 10003f60

uint __thiscall FUN_10003f60(void *this,uint param_1)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  void *_Dst;
  int iVar4;
  size_t _Size;
  
  if (param_1 == 0xffffffff) {
    return 0;
  }
  uVar3 = **(uint **)((int)this + 0x24);
  if ((uVar3 != 0) && (uVar3 < **(int **)((int)this + 0x34) + uVar3)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    *pcVar1 = (char)param_1;
    return param_1 & 0xff;
  }
  if (((*(uint *)((int)this + 0x48) & 4) == 0) || ((*(uint *)((int)this + 0x48) & 10) != 0)) {
    return 0xffffffff;
  }
  if (**(int **)((int)this + 0x20) == 0) {
    _Size = 0;
  }
  else {
    _Size = (**(int **)((int)this + 0x34) - **(int **)((int)this + 0x10)) + uVar3;
  }
  iVar2 = (int)_Size / 2;
  if ((int)_Size / 2 < *(int *)((int)this + 0x3c)) {
    iVar2 = *(int *)((int)this + 0x3c);
  }
  *(undefined4 *)((int)this + 0x3c) = 0x20;
  if (0 < iVar2) {
    while (0x7fffffff - iVar2 < (int)_Size) {
      iVar2 = iVar2 / 2;
      if (iVar2 < 1) {
        return 0xffffffff;
      }
    }
    if (0 < iVar2) {
      uVar3 = iVar2 + _Size;
      if (*(code **)((int)this + 0x4c) == (code *)0x0) {
        _Dst = operator_new__(uVar3);
      }
      else {
        _Dst = (void *)(**(code **)((int)this + 0x4c))();
      }
      if (_Dst != (void *)0x0) {
        if (0 < (int)_Size) {
          memcpy(_Dst,(void *)**(undefined4 **)((int)this + 0x10),_Size);
        }
        if ((*(byte *)((int)this + 0x48) & 1) != 0) {
          if (*(code **)((int)this + 0x50) == (code *)0x0) {
            operator_delete__((void *)**(undefined4 **)((int)this + 0x10));
          }
          else {
            (**(code **)((int)this + 0x50))(**(undefined4 **)((int)this + 0x10));
          }
        }
        *(uint *)((int)this + 0x48) = *(uint *)((int)this + 0x48) | 1;
        if (_Size == 0) {
          *(void **)((int)this + 0x44) = _Dst;
          **(undefined4 **)((int)this + 0x14) = _Dst;
          **(undefined4 **)((int)this + 0x24) = _Dst;
          **(uint **)((int)this + 0x34) = uVar3;
          **(undefined4 **)((int)this + 0x10) = _Dst;
          **(undefined4 **)((int)this + 0x20) = _Dst;
          **(undefined4 **)((int)this + 0x30) = 0;
        }
        else {
          *(int *)((int)this + 0x44) =
               (int)_Dst + (*(int *)((int)this + 0x44) - **(int **)((int)this + 0x10));
          iVar2 = **(int **)((int)this + 0x10);
          iVar4 = (**(int **)((int)this + 0x24) - iVar2) + (int)_Dst;
          **(int **)((int)this + 0x14) = (int)_Dst + (**(int **)((int)this + 0x14) - iVar2);
          **(int **)((int)this + 0x24) = iVar4;
          **(int **)((int)this + 0x34) = (int)_Dst + (uVar3 - iVar4);
          iVar2 = **(int **)((int)this + 0x24);
          iVar4 = (**(int **)((int)this + 0x20) - **(int **)((int)this + 0x10)) + (int)_Dst;
          **(int **)((int)this + 0x10) = (int)_Dst;
          **(int **)((int)this + 0x20) = iVar4;
          **(int **)((int)this + 0x30) = (iVar2 - iVar4) + 1;
        }
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        *pcVar1 = (char)param_1;
        return param_1 & 0xff;
      }
    }
  }
  return 0xffffffff;
}



// Function: FUN_10004120 at 10004120

uint __thiscall FUN_10004120(void *this,uint param_1)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = **(uint **)((int)this + 0x20);
  if ((uVar1 != 0) && (**(uint **)((int)this + 0x10) < uVar1)) {
    cVar2 = (char)param_1;
    if ((param_1 == 0xffffffff) ||
       ((cVar2 == *(char *)(uVar1 - 1) || ((*(byte *)((int)this + 0x48) & 2) == 0)))) {
      **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) + 1;
      **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + -1;
      if (param_1 != 0xffffffff) {
        if (*(char *)**(undefined4 **)((int)this + 0x20) != cVar2) {
          *(char *)**(undefined4 **)((int)this + 0x20) = cVar2;
        }
        return param_1 & 0xff;
      }
      return 0;
    }
  }
  return 0xffffffff;
}



// Function: FUN_10004180 at 10004180

uint __fastcall FUN_10004180(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = (byte *)**(int **)(param_1 + 0x20);
  if (pbVar1 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (pbVar1 < pbVar1 + **(int **)(param_1 + 0x30)) {
    return (uint)*pbVar1;
  }
  pbVar2 = (byte *)**(undefined4 **)(param_1 + 0x24);
  if ((pbVar2 != (byte *)0x0) && ((pbVar1 < pbVar2 || (pbVar1 < *(byte **)(param_1 + 0x44))))) {
    if (*(byte **)(param_1 + 0x44) < pbVar2) {
      *(byte **)(param_1 + 0x44) = pbVar2;
    }
    **(int **)(param_1 + 0x30) = *(int *)(param_1 + 0x44) - **(int **)(param_1 + 0x20);
    return (uint)*(byte *)**(undefined4 **)(param_1 + 0x20);
  }
  return 0xffffffff;
}



// Function: FUN_100041e0 at 100041e0

void __fastcall FUN_100041e0(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ce89;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::strstreambuf::vftable;
  local_8 = 0;
  if (((byte)*(undefined4 *)(param_1 + 0x48) & 9) == 1) {
    if (*(code **)(param_1 + 0x50) == (code *)0x0) {
      operator_delete__((void *)**(undefined4 **)(param_1 + 0x10));
    }
    else {
      (**(code **)(param_1 + 0x50))(**(undefined4 **)(param_1 + 0x10),uVar1);
    }
  }
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffff6;
  *(undefined4 *)(param_1 + 0x44) = 0;
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004270 at 10004270

int * __thiscall
FUN_10004270(void *this,int *param_1,int param_2,undefined4 param_3,int param_4,byte param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)((int)this + 0x24);
  if ((iVar3 != 0) && (*(int *)((int)this + 0x44) - iVar3 < 0)) {
    *(int *)((int)this + 0x44) = iVar3;
  }
  if (((param_5 & 1) == 0) || (iVar3 = **(int **)((int)this + 0x20), iVar3 == 0)) {
    if (((param_5 & 2) == 0) || (iVar3 = **(int **)((int)this + 0x24), iVar3 == 0)) {
      param_2 = *(int *)_BADOFF_exref;
    }
    else {
      if (param_4 == 2) {
        param_2 = (*(int *)((int)this + 0x44) - **(int **)((int)this + 0x10)) + param_2;
      }
      else if (param_4 == 1) {
        param_2 = (iVar3 - **(int **)((int)this + 0x10)) + param_2;
      }
      else if ((param_4 != 0) || (param_2 == *(int *)_BADOFF_exref)) {
        param_2 = *(int *)_BADOFF_exref;
      }
      if ((param_2 < 0) || (*(int *)((int)this + 0x44) - **(int **)((int)this + 0x10) < param_2)) {
        param_2 = *(int *)_BADOFF_exref;
      }
      else {
        iVar3 = (**(int **)((int)this + 0x10) - iVar3) + param_2;
        **(int **)((int)this + 0x34) = **(int **)((int)this + 0x34) - iVar3;
        **(int **)((int)this + 0x24) = **(int **)((int)this + 0x24) + iVar3;
      }
    }
    goto LAB_1000439f;
  }
  if (param_4 == 2) {
    param_2 = (*(int *)((int)this + 0x44) - **(int **)((int)this + 0x10)) + param_2;
  }
  else if (param_4 == 1) {
    if ((param_5 & 2) == 0) {
      param_2 = (iVar3 - **(int **)((int)this + 0x10)) + param_2;
    }
    else {
LAB_100042df:
      param_2 = *(int *)_BADOFF_exref;
    }
  }
  else if ((param_4 != 0) || (param_2 == *(int *)_BADOFF_exref)) goto LAB_100042df;
  if ((param_2 < 0) || (*(int *)((int)this + 0x44) - **(int **)((int)this + 0x10) < param_2)) {
    param_2 = *(int *)_BADOFF_exref;
  }
  else {
    iVar3 = (**(int **)((int)this + 0x10) - iVar3) + param_2;
    **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar3;
    **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar3;
    if ((param_5 & 2) != 0) {
      iVar3 = **(int **)((int)this + 0x24);
      if (iVar3 != 0) {
        iVar1 = **(int **)((int)this + 0x34);
        iVar2 = **(int **)((int)this + 0x20);
        **(int **)((int)this + 0x24) = iVar2;
        **(int **)((int)this + 0x34) = (iVar1 + iVar3) - iVar2;
      }
    }
  }
LAB_1000439f:
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = param_2 >> 0x1f;
  return param_1;
}



// Function: FUN_100043c0 at 100043c0

int * __thiscall FUN_100043c0(void *this,int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte in_stack_00000020;
  
  iVar2 = param_4 + param_2;
  iVar4 = **(int **)((int)this + 0x24);
  if ((iVar4 != 0) && (*(int *)((int)this + 0x44) - iVar4 < 0)) {
    *(int *)((int)this + 0x44) = iVar4;
  }
  iVar4 = *(int *)_BADOFF_exref;
  iVar3 = iVar2;
  if (iVar2 != iVar4) {
    iVar3 = iVar4;
    if (((in_stack_00000020 & 1) == 0) || (**(int **)((int)this + 0x20) == 0)) {
      if (((in_stack_00000020 & 2) != 0) &&
         (((iVar4 = **(int **)((int)this + 0x24), iVar4 != 0 && (-1 < iVar2)) &&
          (iVar2 <= *(int *)((int)this + 0x44) - **(int **)((int)this + 0x10))))) {
        iVar4 = (**(int **)((int)this + 0x10) - iVar4) + iVar2;
        **(int **)((int)this + 0x34) = **(int **)((int)this + 0x34) - iVar4;
        **(int **)((int)this + 0x24) = **(int **)((int)this + 0x24) + iVar4;
        iVar3 = iVar2;
      }
    }
    else if ((-1 < iVar2) && (iVar2 <= *(int *)((int)this + 0x44) - **(int **)((int)this + 0x10))) {
      iVar4 = (**(int **)((int)this + 0x10) - **(int **)((int)this + 0x20)) + iVar2;
      **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar4;
      **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar4;
      iVar3 = iVar2;
      if ((in_stack_00000020 & 2) != 0) {
        iVar4 = **(int **)((int)this + 0x24);
        if (iVar4 != 0) {
          iVar3 = **(int **)((int)this + 0x34);
          iVar1 = **(int **)((int)this + 0x20);
          **(int **)((int)this + 0x24) = iVar1;
          **(int **)((int)this + 0x34) = (iVar3 + iVar4) - iVar1;
          iVar3 = iVar2;
        }
      }
    }
  }
  *param_1 = iVar3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = iVar3 >> 0x1f;
  return param_1;
}



// Function: FUN_100044a0 at 100044a0

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_100044a0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ce89;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = std::strstreambuf::vftable;
  local_8 = 0;
  if (((byte)*(undefined4 *)((int)this + 0x48) & 9) == 1) {
    if (*(code **)((int)this + 0x50) == (code *)0x0) {
      operator_delete__((void *)**(undefined4 **)((int)this + 0x10));
    }
    else {
      (**(code **)((int)this + 0x50))(**(undefined4 **)((int)this + 0x10),uVar1);
    }
  }
  *(uint *)((int)this + 0x48) = *(uint *)((int)this + 0x48) & 0xfffffff6;
  *(undefined4 *)((int)this + 0x44) = 0;
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10004540 at 10004540

void __thiscall FUN_10004540(void *this,char *param_1)

{
  char cVar1;
  char *pcVar2;
  size_t _Size;
  int iVar3;
  undefined4 uVar4;
  basic_istream<char,struct_std::char_traits<char>_> local_110 [88];
  undefined **local_b8 [4];
  undefined4 *local_a8;
  undefined4 local_7c;
  undefined4 local_78;
  char *local_74;
  uint local_70;
  undefined4 local_6c;
  code *local_68;
  char local_64 [80];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cedf;
  local_10 = ExceptionList;
  local_14 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  _Size = (int)pcVar2 - (int)(param_1 + 1);
  if ((int)_Size < 0x50) {
    if ((int)_Size < 1) goto LAB_100045aa;
  }
  else {
    _Size = 0x4f;
  }
  memcpy(local_64,param_1,_Size);
LAB_100045aa:
  local_64[_Size] = '\0';
  pcVar2 = local_64;
  do {
    while ((*pcVar2 == '0' || (iVar3 = isspace((int)*pcVar2), iVar3 != 0))) {
      *pcVar2 = ' ';
      pcVar2 = pcVar2 + 1;
    }
    pcVar2 = strchr(pcVar2,0x2f);
  } while ((pcVar2 != (char *)0x0) && (pcVar2 = pcVar2 + 1, pcVar2 != (char *)0x0));
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)local_b8);
  local_8 = 0;
  local_b8[0] = std::strstreambuf::vftable;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)local_b8);
  local_7c = 0x20;
  local_78 = 0;
  local_6c = 0;
  local_68 = (code *)0x0;
  local_70 = 0;
  pcVar2 = local_64;
  do {
    local_74 = pcVar2;
    pcVar2 = local_74 + 1;
  } while (*local_74 != '\0');
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)local_b8,local_64,local_64,
             local_74);
  local_8 = 1;
  uVar4 = 1;
  std::basic_istream<char,struct_std::char_traits<char>_>::
  basic_istream<char,struct_std::char_traits<char>_>
            (local_110,(basic_streambuf<char,struct_std::char_traits<char>_> *)local_b8,false);
  local_8._0_1_ = 2;
  FUN_10003e70(this,local_110);
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_istream<char,struct_std::char_traits<char>_>::_vbase_destructor_(local_110);
  local_b8[0] = std::strstreambuf::vftable;
  local_8 = 3;
  if (((byte)local_70 & 9) == 1) {
    if (local_68 == (code *)0x0) {
      operator_delete__((void *)*local_a8);
    }
    else {
      (*local_68)(*local_a8,uVar4);
    }
  }
  local_70 = local_70 & 0xfffffff6;
  local_74 = (char *)0x0;
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)local_b8);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004710 at 10004710

void __fastcall FUN_10004710(short *param_1)

{
  char cVar1;
  short sVar2;
  undefined **ppuVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  
  ppuVar3 = *(undefined ***)(*(int *)(param_1 + 6) + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar5 = (char *)((int)ppuVar3 + 1);
  do {
    cVar1 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar1 != '\0');
  uVar4 = (int)ppuVar3 - (int)pcVar5;
  uVar8 = uVar4 & 0xffff;
  uVar7 = (ushort)uVar4;
  if ((uVar7 != 0) && (param_1[1] = 0, 1 < uVar8)) {
    pcVar5 = FUN_10004bf0(param_1 + 6,1);
    if (*pcVar5 == ':') {
      param_1[3] = 0;
      param_1[1] = -1;
      if (2 < uVar8) {
        param_1[1] = 2;
      }
      pcVar5 = FUN_10004bf0(param_1 + 6,0);
      iVar6 = tolower((int)*pcVar5);
      if (iVar6 - 0x61U < 0x1a) {
        *param_1 = (short)iVar6 + -0x60;
      }
    }
    pcVar5 = FUN_10004bf0(param_1 + 6,0);
    if ((*pcVar5 == '/') && (pcVar5 = FUN_10004bf0(param_1 + 6,1), *pcVar5 == '/')) {
      param_1[3] = 0;
      param_1[1] = 2;
      if (2 < uVar7) {
        do {
          pcVar5 = FUN_10004bf0(param_1 + 6,param_1[1]);
          if (*pcVar5 == '/') break;
          param_1[1] = param_1[1] + 1;
        } while ((ushort)param_1[1] < uVar7);
      }
      if (param_1[1] == uVar7) {
        param_1[1] = -1;
      }
    }
  }
  ppuVar3 = *(undefined ***)(*(int *)(param_1 + 4) + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  sVar2 = (short)ppuVar3;
  do {
    cVar1 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar1 != '\0');
  sVar2 = (short)ppuVar3 - (sVar2 + 1);
  if (sVar2 != 0) {
    sVar2 = sVar2 + -1;
    param_1[2] = sVar2;
    while ((sVar2 != 0 && (pcVar5 = FUN_10004bf0(param_1 + 4,param_1[2]), *pcVar5 != '.'))) {
      param_1[2] = param_1[2] + -1;
      sVar2 = param_1[2];
    }
    pcVar5 = FUN_10004bf0(param_1 + 4,param_1[2]);
    if (*pcVar5 == '.') {
      param_1[2] = param_1[2] + 1;
      return;
    }
    param_1[2] = -1;
  }
  return;
}



// Function: FUN_10004880 at 10004880

void __fastcall FUN_10004880(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000cf26;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10004ab0((undefined4 *)(param_1 + 0xc));
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)(param_1 + 8));
  ExceptionList = local_10;
  return;
}



// Function: FUN_100048e0 at 100048e0

short * __thiscall FUN_100048e0(void *this,int *param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  int *piVar6;
  undefined **ppuVar7;
  uint uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cf7c;
  local_10 = ExceptionList;
  uVar4 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0xffff0000;
  *(undefined4 *)((int)this + 4) = 0xffffffff;
  pvVar5 = operator_new(0x16);
  local_8 = 0;
  if (pvVar5 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = FUN_100014b0(pvVar5,0);
  }
  local_8 = 0xffffffff;
  *(int **)((int)this + 8) = piVar6;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))(uVar4);
  }
  local_8 = 1;
  pvVar5 = operator_new(0x16);
  local_8._0_1_ = 2;
  if (pvVar5 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = FUN_100014b0(pvVar5,0);
  }
  local_8._0_1_ = 1;
  *(int **)((int)this + 0xc) = piVar6;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))();
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = *param_1;
  ppuVar7 = *(undefined ***)(iVar3 + 0x10);
  if (ppuVar7 == (undefined **)0x0) {
    ppuVar7 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar7 + 1);
  do {
    cVar2 = *(char *)ppuVar7;
    ppuVar7 = (undefined **)((int)ppuVar7 + 1);
  } while (cVar2 != '\0');
  uVar4 = (int)ppuVar7 - (int)pcVar1;
  uVar8 = uVar4 & 0xffff;
  if ((short)uVar4 == 0) goto LAB_10004a6b;
  uVar8 = uVar8 + 0xffff;
  if ((short)uVar8 != 0) {
    do {
      if ((ushort)uVar8 < *(ushort *)(iVar3 + 0x14)) {
        ppuVar7 = *(undefined ***)(iVar3 + 0x10);
        if (ppuVar7 == (undefined **)0x0) {
          ppuVar7 = &PTR_1000e1a4;
        }
        if (*(char *)((uVar8 & 0xffff) + (int)ppuVar7) == '\\') break;
        if ((ushort)uVar8 < *(ushort *)(iVar3 + 0x14)) {
          ppuVar7 = *(undefined ***)(iVar3 + 0x10);
          if (ppuVar7 == (undefined **)0x0) {
            ppuVar7 = &PTR_1000e1a4;
          }
          if (*(char *)((uVar8 & 0xffff) + (int)ppuVar7) == '/') break;
        }
      }
      uVar8 = uVar8 + 0xffff;
    } while ((short)uVar8 != 0);
  }
  if ((ushort)uVar8 < *(ushort *)(iVar3 + 0x14)) {
    ppuVar7 = *(undefined ***)(iVar3 + 0x10);
    if (ppuVar7 == (undefined **)0x0) {
      ppuVar7 = &PTR_1000e1a4;
    }
    if (*(char *)((uVar8 & 0xffff) + (int)ppuVar7) == '\\') {
LAB_10004a4b:
      uVar8 = uVar8 + 1;
    }
    else if ((ushort)uVar8 < *(ushort *)(iVar3 + 0x14)) {
      ppuVar7 = *(undefined ***)(iVar3 + 0x10);
      if (ppuVar7 == (undefined **)0x0) {
        ppuVar7 = &PTR_1000e1a4;
      }
      if (*(char *)((uVar8 & 0xffff) + (int)ppuVar7) == '/') goto LAB_10004a4b;
    }
  }
  ppuVar7 = *(undefined ***)(iVar3 + 0x10);
  if (ppuVar7 == (undefined **)0x0) {
    ppuVar7 = &PTR_1000e1a4;
  }
  FUN_10004ac0((void *)((int)this + 8),(char *)((uVar8 & 0xffff) + (int)ppuVar7),0xffff);
LAB_10004a6b:
  ppuVar7 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar7 == (undefined **)0x0) {
    ppuVar7 = &PTR_1000e1a4;
  }
  FUN_10004ac0((void *)((int)this + 0xc),(char *)ppuVar7,uVar8);
  FUN_10004710((short *)this);
  ExceptionList = local_10;
  return (short *)this;
}



// Function: FUN_10004ab0 at 10004ab0

void __fastcall FUN_10004ab0(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 8))(0);
  return;
}



// Function: FUN_10004ac0 at 10004ac0

void __thiscall FUN_10004ac0(void *this,char *param_1,uint param_2)

{
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  void *this_00;
  int *piVar4;
  undefined **ppuVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000cfab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (((short)param_2 == -1) && (param_2 = 0, param_1 != (char *)0x0)) {
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    param_2 = (int)pcVar3 - (int)(param_1 + 1) & 0xffff;
  }
                    /* WARNING: Load size is inaccurate */
  if (1 < *(ushort *)(*this + 1)) {
    (**(code **)(**this + 8))(0,DAT_1001498c ^ (uint)&stack0xfffffffc);
    this_00 = operator_new(0x16);
    local_8 = 0;
    if (this_00 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = FUN_100014b0(this_00,0);
    }
    local_8 = 0xffffffff;
    *(int **)this = piVar4;
    if (piVar4 == (int *)0x0) {
      ExceptionList = local_10;
      return;
    }
    (**(code **)(*piVar4 + 4))();
  }
                    /* WARNING: Load size is inaccurate */
  if (*this != (void *)0x0) {
    uVar2 = (ushort)param_2;
    FUN_10001110(*this,uVar2 + 1);
                    /* WARNING: Load size is inaccurate */
    if (uVar2 < *(ushort *)(*this + 0x14)) {
      if (uVar2 != 0) {
        ppuVar5 = *(undefined ***)(*this + 0x10);
        if (ppuVar5 == (undefined **)0x0) {
          ppuVar5 = &PTR_1000e1a4;
        }
        memcpy(ppuVar5,param_1,param_2 & 0xffff);
      }
                    /* WARNING: Load size is inaccurate */
      ppuVar5 = *(undefined ***)(*this + 0x10);
      if (ppuVar5 == (undefined **)0x0) {
        ppuVar5 = &PTR_1000e1a4;
      }
      *(undefined1 *)((param_2 & 0xffff) + (int)ppuVar5) = 0;
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004bc0 at 10004bc0

undefined4 * __thiscall FUN_10004bc0(void *this,undefined4 *param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**this + 8))(0);
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  (**(code **)(*piVar1 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10004bf0 at 10004bf0

undefined * __thiscall FUN_10004bf0(void *this,ushort param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 < *(ushort *)(*this + 0x14)) {
    ppuVar1 = *(undefined ***)(*this + 0x10);
    ppuVar2 = &PTR_1000e1a4;
    if (ppuVar1 != (undefined **)0x0) {
      ppuVar2 = ppuVar1;
    }
    return (undefined *)((uint)param_1 + (int)ppuVar2);
  }
  return &DAT_100149a8;
}



// Function: FUN_10004c20 at 10004c20

void __fastcall FUN_10004c20(undefined4 *param_1)

{
  *param_1 = iclSynchBase::vftable;
  return;
}



// Function: FUN_10004c30 at 10004c30

undefined4 * __fastcall FUN_10004c30(undefined4 *param_1)

{
  LPCRITICAL_SECTION p_Var1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000cfd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = iclSynchBase::vftable;
  local_8 = 0;
  *param_1 = iclSynchronous::vftable;
  p_Var1 = FUN_10008650();
  param_1[1] = p_Var1;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004c90 at 10004c90

void __fastcall FUN_10004c90(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000cfd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = iclSynchronous::vftable;
  local_8 = 0;
  FUN_10008670((LPCRITICAL_SECTION)param_1[1]);
  *param_1 = iclSynchBase::vftable;
  ExceptionList = local_10;
  return;
}



// Function: operator_long at 10004cf0

/* public: __thiscall IncValueT<long,5>::operator long(void)const  */

long __thiscall IncValueT<long,5>::operator_long(IncValueT<long,5> *this)

{
                    /* 0x4cf0  75  ??B?$IncValueT@J$04@@QBEJXZ */
  return *(long *)(this + 4);
}



// Function: FUN_10004d00 at 10004d00

void __fastcall FUN_10004d00(int param_1)

{
  FUN_10008690(*(LPCRITICAL_SECTION *)(param_1 + 4));
  return;
}



// Function: FUN_10004d10 at 10004d10

void __fastcall FUN_10004d10(int param_1)

{
  FUN_100086b0(*(LPCRITICAL_SECTION *)(param_1 + 4));
  return;
}



// Function: FUN_10004d20 at 10004d20

undefined4 * __thiscall FUN_10004d20(void *this,byte param_1)

{
  *(undefined ***)this = iclSynchBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004d50 at 10004d50

undefined4 * __thiscall FUN_10004d50(void *this,byte param_1)

{
  FUN_10004c90((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: operator= at 10004d80

/* public: class InputFileDef & __thiscall InputFileDef::operator=(class InputFileDef const &) */

InputFileDef * __thiscall InputFileDef::operator=(InputFileDef *this,InputFileDef *param_1)

{
                    /* 0x4d80  63  ??4InputFileDef@@QAEAAV0@ABV0@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return this;
}



// Function: verify at 10004db0

/* public: enum ICLStatus __thiscall InputFileDef::verify(void)const  */

ICLStatus __thiscall InputFileDef::verify(InputFileDef *this)

{
                    /* 0x4db0  193  ?verify@InputFileDef@@QBE?AW4ICLStatus@@XZ */
  return *(ICLStatus *)this;
}



// Function: isDefined at 10004dc0

/* public: int __thiscall InputFileDef::isDefined(void)const  */

int __thiscall InputFileDef::isDefined(InputFileDef *this)

{
                    /* 0x4dc0  174  ?isDefined@InputFileDef@@QBEHXZ */
  return *(int *)(this + 8);
}



// Function: getNumParams at 10004dd0

/* public: unsigned short __thiscall InputFileDef::getNumParams(void)const  */

ushort __thiscall InputFileDef::getNumParams(InputFileDef *this)

{
                    /* 0x4dd0  163  ?getNumParams@InputFileDef@@QBEGXZ */
  return *(ushort *)(this + 0x10);
}



// Function: getNamedBlockDef at 10004de0

/* public: class NamedBlockDef * __thiscall InputFileDef::getNamedBlockDef(unsigned short) */

NamedBlockDef * __thiscall InputFileDef::getNamedBlockDef(InputFileDef *this,ushort param_1)

{
  NamedBlockDef *pNVar1;
  NamedBlockDef *pNVar2;
  
                    /* 0x4de0  162  ?getNamedBlockDef@InputFileDef@@QAEPAVNamedBlockDef@@G@Z */
  pNVar2 = (NamedBlockDef *)0x0;
  if (*(int *)(this + 4) == 0) {
    init(this);
  }
  if ((*(int *)(this + 4) != 0) &&
     (pNVar1 = (NamedBlockDef *)FUN_10002940(*(int *)(this + 4)), pNVar1 != (NamedBlockDef *)0x0)) {
    do {
      if (pNVar2 != (NamedBlockDef *)0x0) {
        return pNVar2;
      }
      if (*(ushort *)(pNVar1 + 8) == param_1) {
        pNVar2 = pNVar1;
      }
      pNVar1 = (NamedBlockDef *)FUN_10002950(*(int *)(this + 4));
    } while (pNVar1 != (NamedBlockDef *)0x0);
    return pNVar2;
  }
  return (NamedBlockDef *)0x0;
}



// Function: InputFileDef at 10004e40

/* public: __thiscall InputFileDef::InputFileDef(void) */

void __thiscall InputFileDef::InputFileDef(InputFileDef *this)

{
                    /* 0x4e40  25  ??0InputFileDef@@QAE@XZ */
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}



// Function: ~InputFileDef at 10004e60

/* public: __thiscall InputFileDef::~InputFileDef(void) */

void __thiscall InputFileDef::~InputFileDef(InputFileDef *this)

{
                    /* 0x4e60  42  ??1InputFileDef@@QAE@XZ */
  if (*(undefined4 **)(this + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 4))(1);
  }
  return;
}



// Function: clear at 10004e70

/* public: void __thiscall InputFileDef::clear(void) */

void __thiscall InputFileDef::clear(InputFileDef *this)

{
                    /* 0x4e70  130  ?clear@InputFileDef@@QAEXXZ */
  if (*(int *)(this + 4) != 0) {
    FUN_10008550(*(int *)(this + 4));
  }
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}



// Function: setStatus at 10004ea0

/* public: void __thiscall InputFileDef::setStatus(enum ICLStatus) */

void __thiscall InputFileDef::setStatus(InputFileDef *this,ICLStatus param_1)

{
                    /* 0x4ea0  185  ?setStatus@InputFileDef@@QAEXW4ICLStatus@@@Z */
  if (*(int *)this == 0) {
    *(ICLStatus *)this = param_1;
  }
  return;
}



// Function: defineParameter at 10004ec0

/* public: unsigned short __thiscall InputFileDef::defineParameter(class iclString const &) */

ushort __thiscall InputFileDef::defineParameter(InputFileDef *this,iclString *param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  
                    /* 0x4ec0  145  ?defineParameter@InputFileDef@@QAEGABViclString@@@Z */
  if (*(void **)(this + 0xc) != (void *)0x0) {
    puVar2 = FUN_10001940(*(void **)(this + 0xc),(undefined4 *)param_1,*(undefined2 *)(this + 0x10))
    ;
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = *(ushort *)(puVar2 + 2);
      *(short *)(this + 0x10) = *(short *)(this + 0x10) + 1;
      *(undefined4 *)(this + 8) = 1;
      return uVar1;
    }
    setStatus(this,2);
  }
  return 0;
}



// Function: defineValueBlock at 10004f10

/* public: unsigned short __thiscall InputFileDef::defineValueBlock(class iclString const &,enum
   VBType,long,long) */

ushort __thiscall
InputFileDef::defineValueBlock
          (InputFileDef *this,iclString *param_1,VBType param_2,long param_3,long param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  
                    /* 0x4f10  148  ?defineValueBlock@InputFileDef@@QAEGABViclString@@W4VBType@@JJ@Z
                        */
  if (*(void **)(this + 0xc) != (void *)0x0) {
    puVar2 = FUN_10001a10(*(void **)(this + 0xc),(undefined4 *)param_1,*(undefined2 *)(this + 0x12),
                          param_2,param_3,param_4);
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = *(ushort *)(puVar2 + 2);
      *(short *)(this + 0x12) = *(short *)(this + 0x12) + 1;
      *(undefined4 **)(this + 0xc) = puVar2;
      *(undefined4 *)(this + 8) = 1;
      return uVar1;
    }
    setStatus(this,2);
  }
  return 0;
}



// Function: defineValueBlock at 10004f70

/* public: unsigned short __thiscall InputFileDef::defineValueBlock(unsigned int,class iclString
   const &,enum VBType) */

ushort __thiscall
InputFileDef::defineValueBlock(InputFileDef *this,uint param_1,iclString *param_2,VBType param_3)

{
  ushort uVar1;
  undefined4 *puVar2;
  
                    /* 0x4f70  149  ?defineValueBlock@InputFileDef@@QAEGIABViclString@@W4VBType@@@Z
                        */
  if (*(void **)(this + 0xc) != (void *)0x0) {
    puVar2 = FUN_10001ac0(*(void **)(this + 0xc),param_1,(undefined4 *)param_2,
                          *(undefined2 *)(this + 0x12),param_3);
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = *(ushort *)(puVar2 + 2);
      *(short *)(this + 0x12) = *(short *)(this + 0x12) + 1;
      *(undefined4 **)(this + 0xc) = puVar2;
      *(undefined4 *)(this + 8) = 1;
      return uVar1;
    }
    setStatus(this,2);
  }
  return 0;
}



// Function: endValueBlock at 10004fd0

/* public: void __thiscall InputFileDef::endValueBlock(void) */

void __thiscall InputFileDef::endValueBlock(InputFileDef *this)

{
                    /* 0x4fd0  155  ?endValueBlock@InputFileDef@@QAEXXZ */
  if (*(int *)(this + 0xc) != 0) {
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(*(int *)(this + 0xc) + 10);
  }
  return;
}



// Function: FUN_10004fe0 at 10004fe0

undefined4 * __thiscall FUN_10004fe0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d008;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10002730((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: getNamedBlockDef at 10005040

/* public: class NamedBlockDef * __thiscall InputFileDef::getNamedBlockDef(class iclString const &)
    */

NamedBlockDef * __thiscall InputFileDef::getNamedBlockDef(InputFileDef *this,iclString *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  NamedBlockDef *pNVar4;
  undefined **ppuVar5;
  
                    /* 0x5040  161
                       ?getNamedBlockDef@InputFileDef@@QAEPAVNamedBlockDef@@ABViclString@@@Z */
  if (*(void **)(this + 4) == (void *)0x0) {
    return (NamedBlockDef *)0x0;
  }
  ppuVar3 = *(undefined ***)(*(int *)param_1 + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar3 + 1);
  do {
    cVar2 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar2 != '\0');
  ppuVar5 = *(undefined ***)(*(int *)param_1 + 0x10);
  if (ppuVar5 == (undefined **)0x0) {
    ppuVar5 = &PTR_1000e1a4;
  }
  pNVar4 = (NamedBlockDef *)
           FUN_10008580(*(void **)(this + 4),(char *)ppuVar5,(int)ppuVar3 - (int)pcVar1 & 0xffff);
  return pNVar4;
}



// Function: FUN_10005090 at 10005090

undefined4 * __thiscall FUN_10005090(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_NamedBlockDef>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_NamedBlockDef>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005140 at 10005140

void __thiscall FUN_10005140(void *this,byte param_1)

{
  FUN_10005150((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_10005150 at 10005150

undefined4 * __thiscall FUN_10005150(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_NamedBlockDef>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_NamedBlockDef>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: init at 100051f0

/* private: void __thiscall InputFileDef::init(void) */

void __thiscall InputFileDef::init(InputFileDef *this)

{
  void *this_00;
  void *this_01;
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
                    /* 0x51f0  173  ?init@InputFileDef@@AAEXXZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d04e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = operator_new(0x20);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar3 = 1;
    this_01 = operator_new(0x16);
    local_8._0_1_ = 1;
    if (this_01 == (void *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = FUN_100014b0(this_01,0);
    }
    local_8._0_1_ = 0;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
    FUN_10004ac0(&stack0xffffffcc,(char *)&PTR_1000e1a4,0xffff);
    local_8 = (uint)local_8._1_3_ << 8;
    puVar2 = FUN_10005090(this_00,piVar1,uVar3);
  }
  local_8 = 0xffffffff;
  *(undefined4 **)(this + 4) = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    setStatus(this,2);
  }
  ExceptionList = local_10;
  return;
}



// Function: defineNamedBlock at 100052d0

/* public: unsigned short __thiscall InputFileDef::defineNamedBlock(class iclString const &) */

ushort __thiscall InputFileDef::defineNamedBlock(InputFileDef *this,iclString *param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *this_00;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x52d0  143  ?defineNamedBlock@InputFileDef@@QAEGABViclString@@@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d083;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this_00 = (undefined4 *)operator_new(0x12);
  local_8 = 0;
  if (this_00 == (undefined4 *)0x0) {
    this_00 = (undefined4 *)0x0;
  }
  else {
    FUN_10002680(this_00,0,(undefined4 *)param_1,*(undefined2 *)(this + 0x12));
    *this_00 = NamedBlockDef::vftable;
  }
  local_8 = 0xffffffff;
  if (*(int *)(this + 4) == 0) {
    init(this);
  }
  if ((this_00 == (undefined4 *)0x0) || (*(void **)(this + 4) == (void *)0x0)) {
    setStatus(this,2);
  }
  else {
    iVar3 = FUN_10002800(*(void **)(this + 4),this_00);
    if (iVar3 == 0) {
      uVar1 = *(ushort *)(this_00 + 2);
      *(short *)(this + 0x12) = *(short *)(this + 0x12) + 1;
      *(undefined4 *)(this + 8) = 1;
      *(undefined4 **)(this + 0xc) = this_00;
      ExceptionList = local_10;
      return uVar1;
    }
    (**(code **)*this_00)(1,uVar2);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: linkValueBlock at 100053b0

/* public: void __thiscall InputFileDef::linkValueBlock(unsigned short) */

void __thiscall InputFileDef::linkValueBlock(InputFileDef *this,ushort param_1)

{
  void *this_00;
  undefined4 *puVar1;
  int iVar2;
  undefined2 in_stack_00000006;
  
                    /* 0x53b0  177  ?linkValueBlock@InputFileDef@@QAEXG@Z */
  iVar2 = 0;
  if (*(int *)(this + 4) == 0) {
    init(this);
  }
  if ((*(int *)(this + 4) != 0) &&
     (this_00 = (void *)FUN_10002940(*(int *)(this + 4)), this_00 != (void *)0x0)) {
    do {
      if (iVar2 != 0) goto LAB_100053f5;
      iVar2 = FUN_10001c40(this_00,_param_1);
      this_00 = (void *)FUN_10002950(*(int *)(this + 4));
    } while (this_00 != (void *)0x0);
    if (iVar2 != 0) {
LAB_100053f5:
      puVar1 = FUN_10001b70(*(void **)(this + 0xc),iVar2);
      if (puVar1 == (undefined4 *)0x0) {
        setStatus(this,2);
        return;
      }
      *(undefined4 *)(this + 8) = 1;
      return;
    }
  }
  setStatus(this,1);
  return;
}



// Function: indexIsComplete at 10005430

/* public: int __thiscall InputFileDef::indexIsComplete(class NamedObjectList<class
   NamedObjectList<class FileIndex> > &) */

int __thiscall
InputFileDef::indexIsComplete
          (InputFileDef *this,NamedObjectList<class_NamedObjectList<class_FileIndex>_> *param_1)

{
  char *pcVar1;
  char cVar2;
  void *this_00;
  undefined **ppuVar3;
  undefined **ppuVar4;
  int iVar5;
  
                    /* 0x5430  172
                       ?indexIsComplete@InputFileDef@@QAEHAAV?$NamedObjectList@V?$NamedObjectList@VFileIndex@@@@@@@Z
                        */
  iVar5 = 1;
  if (*(int *)(this + 4) == 0) {
    init(this);
  }
  if (*(int *)(this + 4) != 0) {
    this_00 = (void *)FUN_10002940(*(int *)(this + 4));
    while ((this_00 != (void *)0x0 && (iVar5 != 0))) {
      ppuVar3 = *(undefined ***)(*(int *)((int)this_00 + 4) + 0x10);
      if (ppuVar3 == (undefined **)0x0) {
        ppuVar3 = &PTR_1000e1a4;
      }
      pcVar1 = (char *)((int)ppuVar3 + 1);
      do {
        cVar2 = *(char *)ppuVar3;
        ppuVar3 = (undefined **)((int)ppuVar3 + 1);
      } while (cVar2 != '\0');
      ppuVar4 = *(undefined ***)(*(int *)((int)this_00 + 4) + 0x10);
      if (ppuVar4 == (undefined **)0x0) {
        ppuVar4 = &PTR_1000e1a4;
      }
      iVar5 = FUN_10008580(param_1,(char *)ppuVar4,(int)ppuVar3 - (int)pcVar1 & 0xffff);
      if ((iVar5 == 0) || ((void *)(iVar5 + -0x14) == (void *)0x0)) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_10001c90(this_00,(void *)(iVar5 + -0x14));
      }
      this_00 = (void *)FUN_10002950(*(int *)(this + 4));
    }
    return iVar5;
  }
  return 1;
}



// Function: FUN_100054d0 at 100054d0

void __fastcall FUN_100054d0(int param_1)

{
  operator_delete__(*(void **)(param_1 + 0xc));
  return;
}



// Function: FUN_100054e0 at 100054e0

int __fastcall FUN_100054e0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d0d7;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar2 = operator_new(0x16);
  local_8 = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_100014b0(pvVar2,0);
  }
  local_8 = 0xffffffff;
  *(int **)(param_1 + 4) = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(uVar1);
  }
  local_8 = 1;
  pvVar2 = operator_new(0x16);
  local_8._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_100014b0(pvVar2,0);
  }
  local_8._0_1_ = 1;
  *(int **)(param_1 + 8) = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))();
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_10002ce0((void *)(param_1 + 0x10),(char *)0x0,0x100);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100055b0 at 100055b0

void __thiscall FUN_100055b0(void *this,void *param_1,undefined4 param_2)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  
  ppuVar4 = *(undefined ***)(*(int *)((int)this + 8) + 0x10);
  if (ppuVar4 == (undefined **)0x0) {
    ppuVar4 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar4 + 1);
  do {
    cVar3 = *(char *)ppuVar4;
    ppuVar4 = (undefined **)((int)ppuVar4 + 1);
  } while (cVar3 != '\0');
  ppuVar5 = *(undefined ***)(*(int *)((int)this + 8) + 0x10);
  ppuVar7 = &PTR_1000e1a4;
  if (ppuVar5 != (undefined **)0x0) {
    ppuVar7 = ppuVar5;
  }
  ppuVar5 = *(undefined ***)(*(int *)((int)this + 4) + 0x10);
  if (ppuVar5 == (undefined **)0x0) {
    ppuVar5 = &PTR_1000e1a4;
  }
  pcVar2 = (char *)((int)ppuVar5 + 1);
  do {
    cVar3 = *(char *)ppuVar5;
    ppuVar5 = (undefined **)((int)ppuVar5 + 1);
  } while (cVar3 != '\0');
  ppuVar6 = *(undefined ***)(*(int *)((int)this + 4) + 0x10);
  if (ppuVar6 == (undefined **)0x0) {
    ppuVar6 = &PTR_1000e1a4;
  }
  FUN_1000bcf0(param_1,(char *)ppuVar6,(int)ppuVar5 - (int)pcVar2 & 0xffff,(char *)ppuVar7,
               (int)ppuVar4 - (int)pcVar1 & 0xffff,param_2);
  return;
}



// Function: FUN_10005630 at 10005630

char * FUN_10005630(char *param_1,char *param_2)

{
  int iVar1;
  
  if (param_1 != param_2) {
    do {
      if (*param_1 == '\0') {
        return param_1;
      }
      iVar1 = isspace((int)*param_1);
      if (iVar1 == 0) {
        return param_1;
      }
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return param_1;
}



// Function: FUN_10005670 at 10005670

int FUN_10005670(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != param_2) {
    do {
      iVar1 = isspace((int)*(char *)(param_1 + -1));
      if (iVar1 == 0) {
        return param_1;
      }
      param_1 = param_1 + -1;
    } while (param_1 != param_2);
  }
  return param_1;
}



// Function: FUN_100056b0 at 100056b0

void __thiscall FUN_100056b0(void *this,char *param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int local_90;
  char local_8c [132];
  uint local_8;
  
  local_8 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  pcVar6 = (char *)0x0;
  local_90 = 0;
  pcVar7 = local_8c;
  bVar2 = false;
  bVar3 = false;
  pcVar4 = FUN_10005630(param_1,param_2);
  if (pcVar4 != param_2) {
    do {
      cVar1 = *pcVar4;
      if (cVar1 == '\0') break;
      if (bVar2) {
        bVar2 = false;
        switch(cVar1) {
        case 'b':
          *pcVar7 = '\b';
          pcVar7 = pcVar7 + 1;
          break;
        default:
          *pcVar7 = cVar1;
          pcVar7 = pcVar7 + 1;
          break;
        case 'f':
          *pcVar7 = '\f';
          pcVar7 = pcVar7 + 1;
          break;
        case 'n':
          *pcVar7 = '\n';
          pcVar7 = pcVar7 + 1;
          break;
        case 'r':
          *pcVar7 = '\r';
          pcVar7 = pcVar7 + 1;
          break;
        case 't':
          *pcVar7 = '\t';
          pcVar7 = pcVar7 + 1;
        }
      }
      else if (cVar1 == '\"') {
        bVar3 = !bVar3;
LAB_10005805:
        pcVar6 = (char *)0x0;
      }
      else if (cVar1 == ';') {
        if (bVar3) {
          pcVar6 = (char *)0x0;
          *pcVar7 = ';';
          pcVar7 = pcVar7 + 1;
        }
        else {
          pcVar4 = param_2 + -1;
        }
      }
      else {
        if (cVar1 == '\\') {
          if (bVar3) {
            bVar2 = true;
          }
          else {
            local_90 = 0x28;
            pcVar4 = param_2 + -1;
          }
          goto LAB_10005805;
        }
        iVar5 = isspace((int)cVar1);
        if (iVar5 == 0) {
          pcVar6 = (char *)0x0;
        }
        else if (pcVar6 == (char *)0x0) {
          *pcVar7 = *pcVar4;
          pcVar6 = pcVar7;
          pcVar7 = pcVar7 + 1;
          goto LAB_10005807;
        }
        *pcVar7 = *pcVar4;
        pcVar7 = pcVar7 + 1;
      }
LAB_10005807:
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 != param_2);
    if (bVar3) {
      *(char **)((int)this + 0x20) = "Syntax error (Name=Value)";
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (pcVar6 != (char *)0x0) {
      *pcVar6 = '\0';
    }
    if ((local_90 != 0) && (local_90 != 0x28)) {
      if (local_90 == 0x23) {
        *(char **)((int)this + 0x20) = "Syntax error (Name=Value)";
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      goto LAB_10005899;
    }
  }
  *pcVar7 = '\0';
  FUN_10002bd0((void *)((int)this + 0x10),local_8c,0);
LAB_10005899:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100058e0 at 100058e0

void __cdecl FUN_100058e0(void *param_1,char *param_2)

{
  char *_DstBuf;
  char *_DstBuf_00;
  int iVar1;
  undefined **ppuVar2;
  
  if (*(ushort *)((int)param_1 + 0x96) < 0x1a) {
    _DstBuf = (char *)operator_new__(0x200);
    _DstBuf_00 = (char *)operator_new__(0x200);
    if ((_DstBuf != (char *)0x0) && (_DstBuf_00 != (char *)0x0)) {
      iVar1 = *(int *)((int)param_1 + 0x3e);
      if (iVar1 == -1) {
        iVar1 = FUN_10008f30(param_1,*(int *)((int)param_1 + 0x42));
      }
      ppuVar2 = *(undefined ***)(*(int *)((int)param_1 + 4) + 0x10);
      if (ppuVar2 == (undefined **)0x0) {
        ppuVar2 = &PTR_1000e1a4;
      }
      sprintf_s(_DstBuf_00,0x200,"%s:%-5ld  %s",ppuVar2,iVar1,param_2);
      vsprintf_s(_DstBuf,0x200,_DstBuf_00,&stack0x0000000c);
      param_2 = _DstBuf;
    }
    iclError(param_2);
    operator_delete__(_DstBuf);
    operator_delete__(_DstBuf_00);
    *(short *)((int)param_1 + 0x96) = *(short *)((int)param_1 + 0x96) + 1;
    return;
  }
  if (*(ushort *)((int)param_1 + 0x96) == 0x1a) {
    ppuVar2 = *(undefined ***)(*(int *)((int)param_1 + 4) + 0x10);
    if (ppuVar2 == (undefined **)0x0) {
      ppuVar2 = &PTR_1000e1a4;
    }
    iclError("Reached error limit in \'%s\'",ppuVar2);
  }
  *(short *)((int)param_1 + 0x96) = *(short *)((int)param_1 + 0x96) + 1;
  return;
}



// Function: IncValueT<long,5> at 100059c0

/* public: __thiscall IncValueT<long,5>::IncValueT<long,5>(long) */

void __thiscall IncValueT<long,5>::IncValueT<long,5>(IncValueT<long,5> *this,long param_1)

{
                    /* 0x59c0  10  ??0?$IncValueT@J$04@@QAE@J@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(long *)(this + 4) = param_1;
  return;
}



// Function: ~IncValueT<long,5> at 10005a20

/* public: virtual __thiscall IncValueT<long,5>::~IncValueT<long,5>(void) */

void __thiscall IncValueT<long,5>::~IncValueT<long,5>(IncValueT<long,5> *this)

{
                    /* 0x5a20  37  ??1?$IncValueT@J$04@@UAE@XZ */
  *(undefined ***)this = vftable;
  *(undefined ***)this = ValueBase::vftable;
  return;
}



// Function: operator= at 10005a70

/* public: class IncValueT<long,5> const & __thiscall IncValueT<long,5>::operator=(class
   IncValueT<long,5> const &) */

IncValueT<long,5> * __thiscall
IncValueT<long,5>::operator=(IncValueT<long,5> *this,IncValueT<long,5> *param_1)

{
                    /* 0x5a70  53  ??4?$IncValueT@J$04@@QAEABV0@ABV0@@Z
                       0x5a70  54  ??4?$IncValueT@J$04@@UAEABVValueBase@@ABV1@@Z
                       0x5a70  55  ??4?$IncValueT@K$03@@QAEABV0@ABV0@@Z
                       0x5a70  56  ??4?$IncValueT@K$03@@UAEABVValueBase@@ABV1@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return this;
}



// Function: getType at 10005a90

/* public: virtual enum VBType __thiscall IncValueT<long,5>::getType(void)const  */

VBType __thiscall IncValueT<long,5>::getType(IncValueT<long,5> *this)

{
                    /* 0x5a90  168  ?getType@?$IncValueT@J$04@@UBE?AW4VBType@@XZ */
  return 5;
}



// Function: operator-- at 10005aa0

/* public: virtual void __thiscall IncValueT<long,5>::operator--(void) */

void __thiscall IncValueT<long,5>::operator--(IncValueT<long,5> *this)

{
                    /* 0x5aa0  87  ??F?$IncValueT@J$04@@UAEXXZ
                       0x5aa0  88  ??F?$IncValueT@K$03@@UAEXXZ */
  *(int *)(this + 4) = *(int *)(this + 4) + -1;
  return;
}



// Function: operator== at 10005ab0

/* public: virtual int __thiscall IncValueT<long,5>::operator==(class ValueBase const &)const  */

int __thiscall IncValueT<long,5>::operator==(IncValueT<long,5> *this,ValueBase *param_1)

{
                    /* 0x5ab0  71  ??8?$IncValueT@J$04@@UBEHABVValueBase@@@Z
                       0x5ab0  72  ??8?$IncValueT@K$03@@UBEHABVValueBase@@@Z */
  return (uint)(*(int *)(this + 4) == *(int *)(param_1 + 4));
}



// Function: operator< at 10005ad0

/* public: virtual int __thiscall IncValueT<long,5>::operator<(class ValueBase const &)const  */

int __thiscall IncValueT<long,5>::operator<(IncValueT<long,5> *this,ValueBase *param_1)

{
                    /* 0x5ad0  94  ??M?$IncValueT@J$04@@UBEHABVValueBase@@@Z */
  return (uint)(*(int *)(this + 4) < *(int *)(param_1 + 4));
}



// Function: operator<= at 10005af0

/* public: virtual int __thiscall IncValueT<long,5>::operator<=(class ValueBase const &)const  */

int __thiscall IncValueT<long,5>::operator<=(IncValueT<long,5> *this,ValueBase *param_1)

{
                    /* 0x5af0  101  ??N?$IncValueT@J$04@@UBEHABVValueBase@@@Z */
  return (uint)(*(int *)(this + 4) <= *(int *)(param_1 + 4));
}



// Function: IncValueT<long,5> at 10005b10

/* public: __thiscall IncValueT<long,5>::IncValueT<long,5>(class IncValueT<long,5> const &) */

void __thiscall
IncValueT<long,5>::IncValueT<long,5>(IncValueT<long,5> *this,IncValueT<long,5> *param_1)

{
                    /* 0x5b10  9  ??0?$IncValueT@J$04@@QAE@ABV0@@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return;
}



// Function: FUN_10005b70 at 10005b70

void __thiscall FUN_10005b70(void *this,char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *local_94;
  char local_8c [132];
  uint local_8;
  
  local_8 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  strncpy_s(local_8c,0x84,param_1,param_2 - (int)param_1);
  local_8c[param_2 - (int)param_1] = '\0';
  pcVar2 = FUN_10005630(local_8c,(char *)0x0);
  *(undefined4 *)this = 0;
  cVar1 = *pcVar2;
  if (cVar1 == '\0') {
switchD_10005bf1_caseD_3b:
  }
  else {
    switch(cVar1) {
    case '#':
    case '<':
      *(uint *)this = (cVar1 != '<') + 2;
      pcVar2 = FUN_10005630(pcVar2 + 1,(char *)0x0);
      if (*pcVar2 != '\0') {
        local_94 = strchr(pcVar2,0x3d);
        if (local_94 == (char *)0x0) {
                    /* WARNING: Load size is inaccurate */
          if (*this != 2) break;
          FUN_10004ac0((void *)((int)this + 8),(char *)&PTR_1000e1a4,0xffff);
          local_94 = strchr(pcVar2,0x3e);
        }
        else {
          pcVar4 = FUN_10005630(local_94 + 1,(char *)0x0);
          if (*pcVar4 != '\0') {
                    /* WARNING: Load size is inaccurate */
            if (*this == 2) {
              pcVar5 = strchr(pcVar4,0x3e);
              if (pcVar5 != (char *)0x0) {
                pcVar5 = (char *)FUN_10005670((int)pcVar5,(int)pcVar4);
              }
              if (pcVar5 <= pcVar4) break;
              *pcVar5 = '\0';
              FUN_10004ac0((void *)((int)this + 8),pcVar4,0xffff);
            }
            else {
              lVar3 = atol(pcVar4);
              *(long *)((int)this + 0xc) = lVar3;
            }
          }
        }
        if ((local_94 != (char *)0x0) &&
           (pcVar4 = (char *)FUN_10005670((int)local_94,(int)pcVar2), pcVar2 < pcVar4)) {
          *pcVar4 = '\0';
          FUN_10004ac0((void *)((int)this + 4),pcVar2,0xffff);
          goto LAB_10005df2;
        }
      }
      break;
    default:
      *(undefined4 *)this = 4;
      FUN_10002cc0((void *)((int)this + 0x10),(char *)&PTR_1000e1a4,0);
      if ((*pcVar2 != '\0') && (pcVar4 = strchr(pcVar2,0x3d), pcVar4 != (char *)0x0)) {
        pcVar5 = (char *)FUN_10005670((int)pcVar4,(int)pcVar2);
        if (pcVar2 < pcVar5) {
          *pcVar5 = '\0';
          FUN_10004ac0((void *)((int)this + 4),pcVar2,0xffff);
          iVar6 = FUN_100056b0(this,pcVar4 + 1,local_8c + (param_2 - (int)param_1));
          if (iVar6 != 0x23) goto LAB_10005df2;
        }
      }
      break;
    case ';':
      goto switchD_10005bf1_caseD_3b;
    case '[':
      *(undefined4 *)this = 1;
      pcVar2 = FUN_10005630(pcVar2 + 1,(char *)0x0);
      if (((*pcVar2 != '\0') && (pcVar4 = strchr(pcVar2,0x5d), pcVar4 != (char *)0x0)) &&
         (pcVar4 = (char *)FUN_10005670((int)pcVar4,(int)pcVar2), pcVar2 < pcVar4)) {
        *pcVar4 = '\0';
        FUN_10004ac0((void *)((int)this + 4),pcVar2,0xffff);
        goto LAB_10005df2;
      }
    }
                    /* WARNING: Load size is inaccurate */
    iVar6 = *this;
    if (iVar6 == 1) {
      *(char **)((int)this + 0x20) = "Syntax error ([Name])";
    }
    else if (iVar6 == 2) {
      *(char **)((int)this + 0x20) = "Syntax error (<Name=Value> or <Name>)";
    }
    else if (iVar6 == 3) {
      *(char **)((int)this + 0x20) = "Syntax error (#Name=Count)";
    }
    else {
      *(char **)((int)this + 0x20) = "Syntax error (Name=Value)";
    }
  }
LAB_10005df2:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: `default_constructor_closure' at 10005e60

/* public: void __thiscall IncValueT<long,5>::`default constructor closure'(void) */

void __thiscall IncValueT<long,5>::_default_constructor_closure_(IncValueT<long,5> *this)

{
                    /* 0x5e60  126  ??_F?$IncValueT@J$04@@QAEXXZ */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  return;
}



// Function: FUN_10005eb0 at 10005eb0

undefined4 * __thiscall FUN_10005eb0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (this,8,*(int *)((int)this + -4),IncValueT<long,5>::~IncValueT<long,5>);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    ExceptionList = local_10;
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = IncValueT<long,5>::vftable;
  local_8 = 0xffffffff;
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005f60 at 10005f60

int __fastcall FUN_10005f60(int *param_1)

{
  int iVar1;
  
  while (iVar1 = (**(code **)(*param_1 + 0x14))(1), iVar1 == 0) {
    iVar1 = FUN_10005b70(&DAT_100149b0,(char *)param_1[7],param_1[9]);
    while (iVar1 == 0x28) {
      iVar1 = (**(code **)(*param_1 + 0x14))(1);
      if (iVar1 == 0) {
        iVar1 = FUN_100056b0(&DAT_100149b0,(char *)param_1[7],(char *)param_1[9]);
      }
    }
    if (iVar1 != 0) break;
    if (DAT_100149b0 != 0) {
      return 0;
    }
  }
  if (iVar1 == 0x23) {
    FUN_100058e0(param_1,DAT_100149d0);
  }
  return iVar1;
}



// Function: FUN_10005ff0 at 10005ff0

undefined4 __thiscall FUN_10005ff0(void *this,int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined **ppuVar5;
  
  ppuVar3 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar3 + 1);
  do {
    cVar2 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar2 != '\0');
  ppuVar5 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar5 == (undefined **)0x0) {
    ppuVar5 = &PTR_1000e1a4;
  }
  iVar4 = FUN_10008580((void *)((int)this + 0x56),(char *)ppuVar5,
                       (int)ppuVar3 - (int)pcVar1 & 0xffff);
  if (iVar4 != 0) {
    return *(undefined4 *)(*(int *)(iVar4 + 8) + 4);
  }
  return 0xffffffff;
}



// Function: FUN_10006050 at 10006050

int __thiscall FUN_10006050(void *this,int *param_1)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined **ppuVar5;
  
  ppuVar3 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar3 + 1);
  do {
    cVar2 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar2 != '\0');
  ppuVar5 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar5 == (undefined **)0x0) {
    ppuVar5 = &PTR_1000e1a4;
  }
  iVar4 = FUN_10008580((void *)((int)this + 0x76),(char *)ppuVar5,
                       (int)ppuVar3 - (int)pcVar1 & 0xffff);
  if (iVar4 != 0) {
    return iVar4 + -0x14;
  }
  return 0;
}



// Function: FUN_100060b0 at 100060b0

undefined4 * __thiscall FUN_100060b0(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_ValueBlockHeader>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_ValueBlockHeader>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10006160 at 10006160

void __thiscall FUN_10006160(void *this,byte param_1)

{
  FUN_10006270((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_10006170 at 10006170

void __fastcall FUN_10006170(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_ValueBlockHeader>::vftable;
  param_1[5] = NamedObjectList<class_ValueBlockHeader>::vftable;
  local_8 = 0;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: copy at 10006200

/* public: virtual class ValueBase * __thiscall IncValueT<long,5>::copy(void)const  */

ValueBase * __thiscall IncValueT<long,5>::copy(IncValueT<long,5> *this)

{
  ValueBase *pVVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x6200  137  ?copy@?$IncValueT@J$04@@UBEPAVValueBase@@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d173;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pVVar1 = (ValueBase *)operator_new(8);
  if (pVVar1 == (ValueBase *)0x0) {
    pVVar1 = (ValueBase *)0x0;
  }
  else {
    *(undefined ***)pVVar1 = ValueBase::vftable;
    *(undefined ***)pVVar1 = vftable;
    *(undefined4 *)(pVVar1 + 4) = *(undefined4 *)(this + 4);
  }
  ExceptionList = local_10;
  return pVVar1;
}



// Function: FUN_10006270 at 10006270

undefined4 * __thiscall FUN_10006270(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_ValueBlockHeader>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_ValueBlockHeader>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10006310 at 10006310

undefined4 * __fastcall FUN_10006310(undefined4 *param_1)

{
  void *this;
  int *piVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d1ab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 1;
  this = operator_new(0x16);
  local_8 = 0;
  if (this == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_100014b0(this,0);
  }
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  FUN_10004ac0(&stack0xffffffd0,(char *)&PTR_1000e1a4,0xffff);
  local_8 = 0xffffffff;
  FUN_100060b0(param_1,piVar1,uVar2);
  *param_1 = ValueBlockHeaderList::vftable;
  param_1[5] = ValueBlockHeaderList::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100063e0 at 100063e0

void __thiscall FUN_100063e0(void *this,byte param_1)

{
  FUN_10006980((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_100063f0 at 100063f0

void __fastcall FUN_100063f0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d206;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_ValueBlockHeader>::vftable;
  param_1[5] = NamedObjectList<class_ValueBlockHeader>::vftable;
  local_8 = 1;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 2;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006490 at 10006490

ICLStatus __thiscall FUN_10006490(void *this,void *param_1,void *param_2,void *param_3,int param_4)

{
  char cVar1;
  undefined **ppuVar2;
  uint uVar3;
  ICLStatus IVar4;
  ICLStatus IVar5;
  int *this_00;
  void *this_01;
  undefined **ppuVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined **ppuVar9;
  char *pcVar10;
  undefined4 local_44 [3];
  int local_38;
  void *local_24;
  ICLStatus local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d274;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_20 = 0;
  local_18 = (int *)this;
  IVar5 = (**(code **)(*this + 4))(DAT_1001498c ^ (uint)&stack0xfffffffc);
  FUN_10006310(local_44);
  local_8 = 0;
  IVar4 = local_20;
  while (local_20 = IVar5, IVar5 = local_20, local_20 == 0x23) {
                    /* WARNING: Load size is inaccurate */
    IVar5 = (**(code **)(*this + 4))();
    IVar4 = local_20;
  }
  while (((local_20 = IVar4, DAT_100149b0 != 1 && (DAT_100149b0 != 2)) && (IVar5 == 0))) {
    if (DAT_100149b0 == 3) {
      this_00 = (int *)operator_new(0x16);
      uVar3 = local_8 >> 8;
      local_1c = this_00;
      if (this_00 == (int *)0x0) {
        local_14 = (int *)0x0;
      }
      else {
        *this_00 = (int)iclRefCount::vftable;
        this_00[1] = 0x10000;
        local_8._0_1_ = 2;
        FUN_10004c30(this_00 + 2);
        local_8._0_1_ = 3;
        *this_00 = (int)iclAllocRef::vftable;
        this_00[2] = (int)iclAllocRef::vftable;
        this_00[4] = 0;
        *(undefined2 *)(this_00 + 5) = 0;
        FUN_10001110(this_00,0);
        uVar3 = (uint)local_8._1_3_;
        local_14 = this_00;
      }
      local_8 = uVar3 << 8;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 4))();
      }
      local_8._0_1_ = 4;
      FUN_10004bc0(&local_14,&DAT_100149b4);
      IVar5 = 0;
      local_1c = (int *)DAT_100149bc;
      if (param_2 != (void *)0x0) {
        FUN_100037f0(param_2,(int *)&local_14);
      }
      if (param_4 == 0) goto LAB_10006674;
      if ((param_3 == (void *)0x0) ||
         (this_01 = (void *)FUN_10001370(param_1,(int *)&local_14), this = local_18,
         this_01 == (void *)0x0)) {
LAB_10006693:
        local_24 = operator_new(0x18);
        local_8._0_1_ = 6;
        if (local_24 == (void *)0x0) {
          puVar8 = (undefined4 *)0x0;
        }
        else {
          puVar8 = FUN_1000b9b0(local_24,&local_14,local_1c,7,0);
        }
LAB_100066c3:
        local_8._0_1_ = 4;
        if (puVar8 == (undefined4 *)0x0) {
          IVar5 = 2;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004ab0(&local_14);
        }
        else {
          IVar5 = FUN_10002800(local_44,puVar8);
          if (IVar5 == 0) goto LAB_10006674;
          (**(code **)*puVar8)(1);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004ab0(&local_14);
        }
      }
      else {
        ppuVar2 = (undefined **)local_14[4];
        ppuVar6 = &PTR_1000e1a4;
        if (ppuVar2 != (undefined **)0x0) {
          ppuVar6 = ppuVar2;
        }
        pcVar10 = (char *)((int)ppuVar6 + 1);
        do {
          cVar1 = *(char *)ppuVar6;
          ppuVar6 = (undefined **)((int)ppuVar6 + 1);
        } while (cVar1 != '\0');
        ppuVar9 = &PTR_1000e1a4;
        if (ppuVar2 != (undefined **)0x0) {
          ppuVar9 = ppuVar2;
        }
        iVar7 = FUN_10008580(param_3,(char *)ppuVar9,(int)ppuVar6 - (int)pcVar10 & 0xffff);
        this = local_18;
        if (iVar7 != 0) goto LAB_10006693;
        puVar8 = FUN_1000b900(this_01,(int)local_1c);
        if (puVar8 != (undefined4 *)0x0) {
          IVar5 = FUN_10002800(param_3,puVar8);
          this = local_18;
          if (IVar5 != 0) goto LAB_10006674;
          local_24 = operator_new(0x18);
          local_8._0_1_ = 5;
          if (local_24 == (void *)0x0) {
            puVar8 = (undefined4 *)0x0;
            this = local_18;
          }
          else {
            puVar8 = FUN_1000b9b0(local_24,&local_14,local_1c,*(VBType *)((int)this_01 + 0x12),
                                  puVar8);
            this = local_18;
          }
          goto LAB_100066c3;
        }
        IVar5 = 2;
        this = local_18;
LAB_10006674:
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10004ab0(&local_14);
      }
LAB_10006737:
      IVar4 = local_20;
      if (IVar5 == 0) goto LAB_1000673b;
    }
    else {
      if ((DAT_100149b0 == 4) && (param_2 != (void *)0x0)) {
        pcVar10 = DAT_100149cc;
        if (DAT_100149c4 == 0) {
          pcVar10 = PTR_PTR_10014418;
        }
        IVar5 = FUN_10002e80(param_2,&DAT_100149b4,pcVar10,*(long *)((int)this + 0x42));
        goto LAB_10006737;
      }
LAB_1000673b:
                    /* WARNING: Load size is inaccurate */
      IVar5 = (**(code **)(*this + 4))();
      IVar4 = local_20;
    }
    while (local_20 = IVar5, IVar5 = local_20, local_20 == 0x23) {
                    /* WARNING: Load size is inaccurate */
      IVar5 = (**(code **)(*this + 4))();
      IVar4 = local_20;
    }
  }
  if ((local_38 != 0) && (IVar5 == 0)) {
    if (param_4 == 0) goto LAB_10006794;
    IVar5 = FUN_100067d0(this,local_44);
  }
  if (IVar5 == 0x22) {
    IVar5 = 0;
  }
LAB_10006794:
  if (local_20 != 0) {
    IVar5 = local_20;
  }
  local_8 = 0xffffffff;
  FUN_100063f0(local_44);
  ExceptionList = local_10;
  return IVar5;
}



// Function: FUN_100067d0 at 100067d0

ICLStatus __thiscall FUN_100067d0(void *this,void *param_1)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined3 extraout_var_00;
  int iVar6;
  undefined **ppuVar7;
  ICLStatus IVar8;
  undefined **ppuVar9;
  char *pcVar10;
  ICLStatus local_10;
  int local_c;
  
  IVar8 = 0;
  local_10 = 0;
  bVar3 = FUN_1000bcc0((int)param_1);
  local_c = CONCAT31(extraout_var,bVar3);
  if (DAT_100149b0 == 2) {
    do {
      if ((local_c != 0) || (IVar8 != 0)) break;
      ppuVar7 = *(undefined ***)(DAT_100149b8 + 0x10);
      ppuVar4 = &PTR_1000e1a4;
      if (ppuVar7 != (undefined **)0x0) {
        ppuVar4 = ppuVar7;
      }
      pcVar10 = (char *)((int)ppuVar4 + 1);
      do {
        cVar2 = *(char *)ppuVar4;
        ppuVar4 = (undefined **)((int)ppuVar4 + 1);
      } while (cVar2 != '\0');
      ppuVar9 = &PTR_1000e1a4;
      if (ppuVar7 != (undefined **)0x0) {
        ppuVar9 = ppuVar7;
      }
      ppuVar7 = *(undefined ***)(DAT_100149b4 + 0x10);
      ppuVar5 = &PTR_1000e1a4;
      if (ppuVar7 != (undefined **)0x0) {
        ppuVar5 = ppuVar7;
      }
      pcVar1 = (char *)((int)ppuVar5 + 1);
      do {
        cVar2 = *(char *)ppuVar5;
        ppuVar5 = (undefined **)((int)ppuVar5 + 1);
      } while (cVar2 != '\0');
      if (ppuVar7 == (undefined **)0x0) {
        ppuVar7 = &PTR_1000e1a4;
      }
      IVar8 = FUN_1000bcf0(param_1,(char *)ppuVar7,(int)ppuVar5 - (int)pcVar1 & 0xffff,
                           (char *)ppuVar9,(int)ppuVar4 - (int)pcVar10 & 0xffff,
                           *(undefined4 *)((int)this + 0x42));
      if ((((IVar8 == 0x24) || (IVar8 == 0x25)) || (IVar8 == 0x26)) || (IVar8 == 0x23)) {
        if (IVar8 == 0x24) {
          pcVar10 = "Value blocks are out of order";
LAB_100068c4:
          FUN_100058e0(this,pcVar10);
        }
        else {
          if (IVar8 == 0x25) {
            pcVar10 = "Too many value blocks of this type";
            goto LAB_100068c4;
          }
          if (IVar8 == 0x26) {
            pcVar10 = "Unrecognized value block";
            goto LAB_100068c4;
          }
        }
        if (local_10 == 0) {
          local_10 = IVar8;
        }
LAB_100068db:
        IVar8 = FUN_10006490(this,(void *)0x0,(void *)0x0,(void *)0x0,1);
        bVar3 = FUN_1000bcc0((int)param_1);
        local_c = CONCAT31(extraout_var_00,bVar3);
      }
      else if (IVar8 == 0) goto LAB_100068db;
    } while (DAT_100149b0 == 2);
    if (IVar8 == 0x22) {
      IVar8 = 0;
    }
  }
  if ((local_c == 0) && (IVar8 == 0)) {
    iVar6 = FUN_10002940((int)param_1);
    while (iVar6 != 0) {
      if (0 < *(int *)(iVar6 + 0x10)) {
        FUN_100058e0(this,"Found only %ld of %ld %s value blocks");
      }
      iVar6 = FUN_10002950((int)param_1);
    }
    IVar8 = 0x27;
  }
  if (local_10 == 0) {
    local_10 = IVar8;
  }
  return local_10;
}



// Function: FUN_10006980 at 10006980

undefined4 * __thiscall FUN_10006980(void *this,byte param_1)

{
  FUN_100063f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100069b0 at 100069b0

void __thiscall FUN_100069b0(void *this,InputFileDef *param_1)

{
  int iVar1;
  ICLStatus IVar2;
  int *piVar3;
  undefined4 *puVar4;
  ValueBase *pVVar5;
  NamedBlockDef *pNVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined **local_2c;
  undefined4 local_28;
  undefined1 *local_24;
  undefined4 *local_20;
  NamedBlockDef *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d2ec;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)this;
  iVar1 = InputFileDef::indexIsComplete
                    (param_1,(NamedObjectList<class_NamedObjectList<class_FileIndex>_> *)
                             ((int)this + 0x76));
  if (iVar1 == 0) {
                    /* WARNING: Load size is inaccurate */
    IVar2 = (**(code **)(*this + 8))();
    local_1c = (NamedBlockDef *)operator_new(0x16);
    local_8 = 0;
    if (local_1c == (NamedBlockDef *)0x0) {
      local_18 = (int *)0x0;
    }
    else {
      local_18 = FUN_100014b0(local_1c,0);
    }
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 4))();
    }
    FUN_10004ac0(&local_18,(char *)&PTR_1000e1a4,0xffff);
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    if (IVar2 == 0) {
      do {
        piVar3 = (int *)FUN_10009240((int)this);
        if ((piVar3 == (int *)0x0) || (*piVar3 != 0)) break;
        local_1c = InputFileDef::getNamedBlockDef(param_1,(iclString *)&local_18);
        if (local_1c != (NamedBlockDef *)0x0) {
          pNVar6 = local_1c + 4;
          iVar1 = FUN_10005ff0(this,(int *)pNVar6);
          if (iVar1 == -1) {
            local_28 = *(undefined4 *)((int)this + 0x42);
            local_2c = IncValueT<long,5>::vftable;
            local_8._0_1_ = 3;
            puVar4 = (undefined4 *)operator_new(0xc);
            local_8._0_1_ = 4;
            local_20 = puVar4;
            if (puVar4 == (undefined4 *)0x0) {
              puVar4 = (undefined4 *)0x0;
            }
            else {
              *puVar4 = NamedObject::vftable;
              piVar3 = *(int **)pNVar6;
              puVar4[1] = piVar3;
              (**(code **)(*piVar3 + 4))();
              local_8._0_1_ = 6;
              *puVar4 = NamedValue::vftable;
              pVVar5 = IncValueT<long,5>::copy((IncValueT<long,5> *)&local_2c);
              puVar4[2] = pVVar5;
            }
            local_8._0_1_ = 3;
            if (puVar4 == (undefined4 *)0x0) {
              IVar2 = 2;
            }
            else {
              IVar2 = FUN_10002800((void *)((int)local_14 + 0x56),puVar4);
              if (IVar2 != 0) {
                (**(code **)*puVar4)();
              }
            }
            local_8._0_1_ = 1;
            local_2c = ValueBase::vftable;
            this = local_14;
          }
        }
        piVar3 = local_14;
        if (IVar2 != 0) break;
        puVar4 = (undefined4 *)0x0;
        if (local_1c != (NamedBlockDef *)0x0) {
          pNVar6 = local_1c + 4;
          puVar4 = (undefined4 *)FUN_10006050(local_14,(int *)pNVar6);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)operator_new(0x20);
            local_8._0_1_ = 8;
            local_20 = puVar4;
            if (puVar4 == (undefined4 *)0x0) {
              puVar4 = (undefined4 *)0x0;
            }
            else {
              uVar8 = 1;
              local_24 = &stack0xffffffbc;
              piVar7 = *(int **)pNVar6;
              (**(code **)(*piVar7 + 4))();
              local_8._0_1_ = 8;
              puVar4 = FUN_10003410(puVar4,piVar7,uVar8);
            }
            local_8._0_1_ = 1;
            if (puVar4 == (undefined4 *)0x0) {
              IVar2 = 2;
              this = local_14;
              goto LAB_10006c8a;
            }
            IVar2 = FUN_10002800((void *)((int)piVar3 + 0x76),puVar4 + 5);
            if (IVar2 != 0) {
              (**(code **)*puVar4)();
              this = local_14;
              break;
            }
          }
        }
        IVar2 = FUN_10006490(piVar3,local_1c,(void *)0x0,puVar4,1);
        if ((((IVar2 == 0x23) || (IVar2 == 0x26)) || (IVar2 == 0x25)) || (IVar2 == 0x24)) {
          FUN_10009010(piVar3,IVar2);
          IVar2 = 0;
        }
        else {
          piVar3 = local_14;
          this = local_14;
          if (IVar2 != 0) break;
        }
        piVar3 = (int *)FUN_10009240((int)piVar3);
        this = local_14;
        if ((piVar3 != (int *)0x0) && (*piVar3 == 0)) {
          if (DAT_100149b0 != 1) {
            FUN_100058e0(local_14,"Expected named block header");
            IVar2 = 0x23;
            this = local_14;
            goto LAB_10006c8a;
          }
          FUN_10004bc0(&local_18,&DAT_100149b4);
          IVar2 = 0;
          this = local_14;
        }
      } while( true );
    }
    if (((IVar2 == 0x22) || (IVar2 == 0)) &&
       (IVar2 = FUN_10002b90((int *)this), *(int *)((int)this + 0x4c) == 2)) {
      IVar2 = 0x18;
      iclError();
    }
LAB_10006c8a:
    FUN_10009010(this,IVar2);
    local_8 = 0xffffffff;
    FUN_10004ab0(&local_18);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006ce0 at 10006ce0

ICLStatus __thiscall FUN_10006ce0(void *this,void *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  ICLStatus IVar3;
  
  iVar1 = FUN_10005ff0(this,(int *)((int)param_1 + 4));
  iVar2 = FUN_10006050(this,(int *)((int)param_1 + 4));
  if ((iVar1 < 0) || (iVar2 == 0)) {
    IVar3 = 0x10;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    IVar3 = (**(code **)(*this + 0xc))(iVar1);
    if (IVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
      IVar3 = (**(code **)(*this + 0x14))(1);
      if (IVar3 == 0) {
        (**(code **)(*param_2 + 8))(param_1);
        IVar3 = FUN_10006490(this,param_1,param_2,(void *)0x0,0);
        if (IVar3 == 0) {
          param_2[4] = iVar2;
          return 0;
        }
        (**(code **)(*param_2 + 8))(0);
        return IVar3;
      }
    }
  }
  return IVar3;
}



// Function: FUN_10006d80 at 10006d80

ICLStatus __thiscall FUN_10006d80(void *this,void *param_1,int *param_2,void *param_3,int *param_4)

{
  ICLStatus IVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined **local_38 [5];
  undefined **local_24;
  undefined1 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d33b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = (undefined1 *)operator_new(0x16);
  local_8 = 0;
  if (local_18 == (undefined1 *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = FUN_100014b0(local_18,0);
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))();
  }
  FUN_10004ac0(&local_14,(char *)&PTR_1000e1a4,0xffff);
  local_8 = 1;
  uVar4 = 0;
  local_18 = &stack0xffffffb0;
  piVar3 = local_14;
  (**(code **)(*local_14 + 4))();
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 1;
  FUN_100060b0(local_38,piVar3,uVar4);
  local_38[0] = ValueBlockHeaderList::vftable;
  local_24 = ValueBlockHeaderList::vftable;
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_10004ab0(&local_14);
  IVar1 = FUN_10002800(local_38,param_3);
  if (IVar1 == 0) {
                    /* WARNING: Load size is inaccurate */
    local_14 = (int *)0x0;
    local_18 = (undefined1 *)0x0;
    IVar1 = (**(code **)(*this + 4))();
joined_r0x10006e69:
    if (IVar1 == 0) {
      do {
        if (((*(int *)((int)param_3 + 0x10) < 1) || (local_14 != (int *)0x0)) || (DAT_100149b0 != 2)
           ) goto LAB_10006f7f;
        if (param_4 == (int *)0x0) {
          iVar2 = FUN_100055b0(&DAT_100149b0,local_38,*(undefined4 *)((int)this + 0x42));
          if (iVar2 != 0) goto LAB_10006ee2;
          local_18 = (undefined1 *)0x1;
        }
        else {
          FUN_100055b0(&DAT_100149b0,local_38,*(undefined4 *)((int)this + 0x42));
          iVar2 = FUN_1000bb90(param_3,param_4);
          if (iVar2 == 0) {
            iVar2 = FUN_1000bbe0(param_3,param_4);
            if (iVar2 == 0) {
              local_14 = (int *)0x1;
            }
LAB_10006ee2:
            if (local_18 == (undefined1 *)0x0) {
              if (local_14 == (int *)0x0) {
                IVar1 = FUN_10006490(this,(void *)0x0,(void *)0x0,(void *)0x0,1);
              }
              goto joined_r0x10006e69;
            }
          }
          else {
            local_18 = (undefined1 *)0x1;
          }
        }
        local_14 = (int *)0x1;
        (**(code **)(*param_2 + 8))();
        IVar1 = FUN_10006490(this,param_1,param_2,(void *)param_2[4],1);
        if (IVar1 != 0) break;
        if (*(int **)((int)param_3 + 8) == (int *)0x0) {
          IVar1 = 2;
          (**(code **)(*param_2 + 8))();
          goto joined_r0x10006e69;
        }
        IVar1 = FUN_1000b760(param_2,*(int **)((int)param_3 + 8));
      } while (IVar1 == 0);
      (**(code **)(*param_2 + 8))();
      goto joined_r0x10006e69;
    }
LAB_10006f7f:
    if (IVar1 == 0x22) {
      IVar1 = 0;
    }
    if ((local_18 == (undefined1 *)0x0) && (IVar1 == 0)) {
      IVar1 = 0x10;
    }
  }
  local_8 = 0xffffffff;
  FUN_100063f0(local_38);
  ExceptionList = local_10;
  return IVar1;
}



// Function: iflLibraryVersion at 10006fc0

undefined4 iflLibraryVersion(void)

{
                    /* 0x6fc0  196  iflLibraryVersion */
  return DAT_100145f0;
}



// Function: FUN_10006fd0 at 10006fd0

void FUN_10006fd0(void)

{
  if (DAT_100149ac != (undefined4 *)0x0) {
    (**(code **)*DAT_100149ac)(1);
  }
  DAT_100149ac = (undefined4 *)0x0;
  return;
}



// Function: iflLibraryCleanup at 10006ff0

void iflLibraryCleanup(void)

{
                    /* 0x6ff0  194  iflLibraryCleanup */
  if ((DAT_100149d4 != 0) && (DAT_100149d4 = DAT_100149d4 + -1, DAT_100149d4 == 0)) {
    FUN_10006fd0();
    return;
  }
  return;
}



// Function: FUN_10007010 at 10007010

undefined4 * __thiscall FUN_10007010(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_NamedObject>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100070c0 at 100070c0

void __thiscall FUN_100070c0(void *this,byte param_1)

{
  FUN_100070d0((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_100070d0 at 100070d0

undefined4 * __thiscall FUN_100070d0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_NamedObject>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_NamedObject>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007170 at 10007170

undefined4 FUN_10007170(void)

{
  void *this;
  int *extraout_ECX;
  int *piVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d3b3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_100149ac == (undefined4 *)0x0) {
    this = operator_new(0x20);
    local_8 = 0;
    if (this == (void *)0x0) {
      DAT_100149ac = (undefined4 *)0x0;
    }
    else {
      uVar2 = 1;
      piVar1 = extraout_ECX;
      FUN_10001540(&stack0xffffffd4,(char *)&PTR_1000e1a4);
      local_8 = local_8 & 0xffffff00;
      DAT_100149ac = FUN_10007010(this,piVar1,uVar2);
    }
    if (DAT_100149ac == (undefined4 *)0x0) {
      ExceptionList = local_10;
      return 2;
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: iflLibraryInit at 10007210

void iflLibraryInit(void)

{
  int iVar1;
  
                    /* 0x7210  195  iflLibraryInit */
  if ((DAT_100149d4 == 0) && (iVar1 = FUN_10007170(), iVar1 != 0)) {
    return;
  }
  DAT_100149d4 = DAT_100149d4 + 1;
  return;
}



// Function: Parameter at 10007230

/* public: __thiscall Parameter::Parameter(class Parameter const &) */

void __thiscall Parameter::Parameter(Parameter *this,Parameter *param_1)

{
                    /* 0x7230  27  ??0Parameter@@QAE@ABV0@@Z */
  *(undefined ***)this = vftable;
  this[4] = (Parameter)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (Parameter)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  return;
}



// Function: operator= at 10007270

/* public: class Parameter & __thiscall Parameter::operator=(class Parameter const &) */

Parameter * __thiscall Parameter::operator=(Parameter *this,Parameter *param_1)

{
                    /* 0x7270  64  ??4Parameter@@QAEAAV0@ABV0@@Z */
  this[4] = (Parameter)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (Parameter)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  return this;
}



// Function: isSet at 100072b0

/* public: short __thiscall Parameter::isSet(void)const  */

short __thiscall Parameter::isSet(Parameter *this)

{
                    /* 0x72b0  175  ?isSet@Parameter@@QBEFXZ */
  return (short)((byte)this[4] >> 1 & 1);
}



// Function: clearValue at 100072c0

/* public: void __thiscall Parameter::clearValue(void) */

void __thiscall Parameter::clearValue(Parameter *this)

{
                    /* 0x72c0  132  ?clearValue@Parameter@@QAEXXZ */
  this[4] = (Parameter)((byte)this[4] & 0xfd);
  *(undefined4 *)(this + 5) = 0;
  return;
}



// Function: translateErr at 100072d0

/* private: static enum ICLStatus __cdecl InputFile::translateErr(enum ICLStatus) */

ICLStatus __cdecl InputFile::translateErr(ICLStatus param_1)

{
                    /* 0x72d0  190  ?translateErr@InputFile@@CA?AW4ICLStatus@@W42@@Z */
  if ((0x22 < (int)param_1) && ((int)param_1 < 0x28)) {
    param_1 = 0x19;
  }
  return param_1;
}



// Function: verify at 100072f0

/* public: enum ICLStatus __thiscall InputFile::verify(void)const  */

ICLStatus __thiscall InputFile::verify(InputFile *this)

{
  ICLStatus IVar1;
  
                    /* 0x72f0  192  ?verify@InputFile@@QBE?AW4ICLStatus@@XZ */
  IVar1 = *(ICLStatus *)(this + 4);
  if ((IVar1 == 0x18) && (*(int *)(this + 0x18) == 0)) {
    IVar1 = 0;
  }
  return IVar1;
}



// Function: setNamedBlock at 10007310

/* protected: enum ICLStatus __thiscall InputFile::setNamedBlock(unsigned short) */

ICLStatus __thiscall InputFile::setNamedBlock(InputFile *this,ushort param_1)

{
  ICLStatus IVar1;
  undefined4 uVar2;
  NamedBlockDef *pNVar3;
  
                    /* 0x7310  182  ?setNamedBlock@InputFile@@IAE?AW4ICLStatus@@G@Z */
  IVar1 = verify(this);
  if (IVar1 != 0) {
    return 1;
  }
  if (*(int *)(this + 0x20) == 0) {
    uVar2 = FUN_10002e60(*(int *)(this + 0x10));
    if ((ushort)uVar2 == param_1) {
      *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 0x10);
      *(undefined4 *)(this + 0x20) = 0;
      return 0;
    }
  }
  pNVar3 = InputFileDef::getNamedBlockDef(*(InputFileDef **)(this + 0xc),param_1);
  if (pNVar3 == (NamedBlockDef *)0x0) {
    IVar1 = 0x13;
  }
  else {
    IVar1 = FUN_10006ce0(*(void **)(this + 8),pNVar3,*(int **)(this + 0x10));
    IVar1 = translateErr(IVar1);
    if (IVar1 == 0) {
      *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 0x10);
      *(undefined4 *)(this + 0x20) = 0;
      return 0;
    }
  }
  return IVar1;
}



// Function: setValueBlock at 100073a0

/* protected: enum ICLStatus __thiscall InputFile::setValueBlock(unsigned short,class ValueBase
   const &) */

ICLStatus __thiscall InputFile::setValueBlock(InputFile *this,ushort param_1,ValueBase *param_2)

{
  ICLStatus IVar1;
  ICLStatus extraout_EDX;
  
                    /* 0x73a0  189  ?setValueBlock@InputFile@@IAE?AW4ICLStatus@@GABVValueBase@@@Z */
  IVar1 = verify(this);
  if (IVar1 != 0) {
    return 1;
  }
  IVar1 = extraout_EDX;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    IVar1 = FUN_100038b0(*(void **)(this + 0x14),param_1,(int *)param_2);
    IVar1 = translateErr(IVar1);
    if (IVar1 == 0) {
      *(undefined4 *)(this + 0x14) = *(undefined4 *)(*(int *)(this + 0x14) + 0x14);
      return 0;
    }
  }
  return IVar1;
}



// Function: firstValueBlock at 10007400

/* protected: enum ICLStatus __thiscall InputFile::firstValueBlock(unsigned short) */

ICLStatus __thiscall InputFile::firstValueBlock(InputFile *this,ushort param_1)

{
  ICLStatus IVar1;
  ICLStatus extraout_EDX;
  
                    /* 0x7400  156  ?firstValueBlock@InputFile@@IAE?AW4ICLStatus@@G@Z */
  IVar1 = verify(this);
  if (IVar1 != 0) {
    return 1;
  }
  IVar1 = extraout_EDX;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    IVar1 = FUN_100038b0(*(void **)(this + 0x14),param_1,(int *)0x0);
    IVar1 = translateErr(IVar1);
    if (IVar1 == 0) {
      *(undefined4 *)(this + 0x14) = *(undefined4 *)(*(int *)(this + 0x14) + 0x14);
      return 0;
    }
  }
  return IVar1;
}



// Function: nextValueBlock at 10007460

/* protected: enum ICLStatus __thiscall InputFile::nextValueBlock(unsigned short) */

ICLStatus __thiscall InputFile::nextValueBlock(InputFile *this,ushort param_1)

{
  ICLStatus IVar1;
  ICLStatus extraout_EDX;
  
                    /* 0x7460  178  ?nextValueBlock@InputFile@@IAE?AW4ICLStatus@@G@Z */
  IVar1 = verify(this);
  if (IVar1 != 0) {
    return 1;
  }
  IVar1 = extraout_EDX;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    IVar1 = FUN_10003170(*(void **)(this + 0x14),param_1);
    IVar1 = translateErr(IVar1);
    if (IVar1 == 0) {
      *(undefined4 *)(this + 0x14) = *(undefined4 *)(*(int *)(this + 0x14) + 0x14);
      return 0;
    }
  }
  return IVar1;
}



// Function: getCurValueBlock at 100074b0

/* protected: enum ICLStatus __thiscall InputFile::getCurValueBlock(class ValueBase &)const  */

ICLStatus __thiscall InputFile::getCurValueBlock(InputFile *this,ValueBase *param_1)

{
  ICLStatus IVar1;
  int iVar2;
  int extraout_ECX;
  
                    /* 0x74b0  157  ?getCurValueBlock@InputFile@@IBE?AW4ICLStatus@@AAVValueBase@@@Z
                        */
  IVar1 = verify(this);
  if (IVar1 != 0) {
    return 1;
  }
  if (*(int *)(extraout_ECX + 0x14) != 0) {
    iVar2 = (**(code **)(**(int **)(extraout_ECX + 0x14) + 4))();
    if ((iVar2 != 0) && (*(void **)(iVar2 + 0x14) != (void *)0x0)) {
      IVar1 = FUN_1000b7a0(*(void **)(iVar2 + 0x14),(int *)param_1);
      return IVar1;
    }
  }
  return 0x13;
}



// Function: getValueBlockCount at 10007500

/* protected: enum ICLStatus __thiscall InputFile::getValueBlockCount(unsigned short,long &) */

ICLStatus __thiscall InputFile::getValueBlockCount(InputFile *this,ushort param_1,long *param_2)

{
  ICLStatus IVar1;
  int extraout_ECX;
  ICLStatus extraout_EDX;
  
                    /* 0x7500  171  ?getValueBlockCount@InputFile@@IAE?AW4ICLStatus@@GAAJ@Z */
  IVar1 = verify(this);
  if (IVar1 != 0) {
    return 1;
  }
  if (*(void **)(extraout_ECX + 0x14) != (void *)0x0) {
    IVar1 = FUN_100033b0(*(void **)(extraout_ECX + 0x14),param_1,param_2);
    return IVar1;
  }
  return extraout_EDX;
}



// Function: clearParamValue at 10007530

/* private: void __thiscall InputFile::clearParamValue(unsigned short) */

void __thiscall InputFile::clearParamValue(InputFile *this,ushort param_1)

{
  int iVar1;
  
                    /* 0x7530  131  ?clearParamValue@InputFile@@AAEXG@Z */
  if (((*(int *)(this + 0x1c) != 0) && (param_1 < *(ushort *)(*(int *)(this + 0xc) + 0x10))) &&
     (iVar1 = *(int *)(*(int *)(this + 0x1c) + (uint)param_1 * 4), iVar1 != 0)) {
    *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0xfd;
    *(undefined4 *)(iVar1 + 5) = 0;
  }
  return;
}



// Function: setParamValue at 10007560

/* private: enum ICLStatus __thiscall InputFile::setParamValue(unsigned short,char const *,long) */

ICLStatus __thiscall
InputFile::setParamValue(InputFile *this,ushort param_1,char *param_2,long param_3)

{
  Parameter *this_00;
  ICLStatus IVar1;
  
                    /* 0x7560  183  ?setParamValue@InputFile@@AAE?AW4ICLStatus@@GPBDJ@Z */
  IVar1 = 0;
  if ((((*(int *)(this + 0x1c) != 0) && (param_1 < *(ushort *)(*(int *)(this + 0xc) + 0x10))) &&
      (this_00 = *(Parameter **)(*(int *)(this + 0x1c) + (uint)param_1 * 4),
      this_00 != (Parameter *)0x0)) &&
     (IVar1 = (*(code *)**(undefined4 **)this_00)(param_2), IVar1 == 0)) {
    Parameter::setFilePos(this_00,param_3);
  }
  return IVar1;
}



// Function: FUN_100075b0 at 100075b0

undefined4 * __thiscall FUN_100075b0(void *this,undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d3e9;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 8);
  *param_1 = piVar1;
  (**(code **)(*piVar1 + 4))(uVar2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10007610 at 10007610

undefined4 __fastcall FUN_10007610(int param_1)

{
  return *(undefined4 *)(param_1 + 0x46);
}



// Function: FUN_10007620 at 10007620

void __fastcall FUN_10007620(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d418;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = TextCRCFileAccBase::vftable;
  local_8 = 0xffffffff;
  FUN_100096d0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: setStatus at 10007670

/* protected: void __thiscall InputFile::setStatus(enum ICLStatus) */

void __thiscall InputFile::setStatus(InputFile *this,ICLStatus param_1)

{
  ICLStatus IVar1;
  
                    /* 0x7670  184  ?setStatus@InputFile@@IAEXW4ICLStatus@@@Z */
  if (*(int *)(this + 4) == 0) {
    IVar1 = translateErr(param_1);
    *(ICLStatus *)(this + 4) = IVar1;
  }
  return;
}



// Function: paramError at 10007690

/* protected: void __thiscall InputFile::paramError(unsigned short,char const *)const  */

void __thiscall InputFile::paramError(InputFile *this,ushort param_1,char *param_2)

{
  InputFileAcc *pIVar1;
  Parameter *this_00;
  ushort uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
                    /* 0x7690  179  ?paramError@InputFile@@IBEXGPBD@Z */
  if ((((*(int *)(this + 0x1c) != 0) && (param_1 < *(ushort *)(*(int *)(this + 0xc) + 0x10))) &&
      (pIVar1 = *(InputFileAcc **)(this + 8), pIVar1 != (InputFileAcc *)0x0)) &&
     (this_00 = *(Parameter **)(*(int *)(this + 0x1c) + (uint)param_1 * 4),
     this_00 != (Parameter *)0x0)) {
    ppuVar4 = &PTR_1000e1a4;
    if (param_2 != (char *)0x0) {
      ppuVar4 = (undefined **)param_2;
    }
    ppuVar3 = &PTR_1000e1a4;
    if (*(undefined ***)(*(int *)(pIVar1 + 4) + 0x10) != (undefined **)0x0) {
      ppuVar3 = *(undefined ***)(*(int *)(pIVar1 + 4) + 0x10);
    }
    uVar2 = Parameter::getLineNo(this_00,pIVar1);
    iclError("%s:%-5lu  %s",ppuVar3,uVar2,ppuVar4);
  }
  return;
}



// Function: getFilePath at 10007700

/* public: class iclString __thiscall InputFile::getFilePath(void)const  */

undefined4 * __thiscall InputFile::getFilePath(InputFile *this)

{
  uint uVar1;
  void *this_00;
  int *piVar2;
  undefined4 *in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
                    /* 0x7700  159  ?getFilePath@InputFile@@QBE?AViclString@@XZ */
  puStack_c = &LAB_1000d464;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  this_00 = operator_new(0x16);
  local_8 = 1;
  if (this_00 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(this_00,0);
  }
  local_8 = local_8 & 0xffffff00;
  *in_stack_00000004 = piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(uVar1);
  }
  local_8 = 0;
  if (*(int *)(this + 8) != 0) {
    FUN_10004bc0(in_stack_00000004,(undefined4 *)(*(int *)(this + 8) + 4));
  }
  ExceptionList = local_10;
  return in_stack_00000004;
}



// Function: defineNamedBlock at 100077a0

/* protected: static unsigned short __cdecl InputFile::defineNamedBlock(class iclString const &) */

ushort __cdecl InputFile::defineNamedBlock(iclString *param_1)

{
  ushort uVar1;
  
                    /* 0x77a0  142  ?defineNamedBlock@InputFile@@KAGABViclString@@@Z */
  uVar1 = 0;
  if (activeDef != (InputFileDef *)0x0) {
    uVar1 = InputFileDef::defineNamedBlock(activeDef,param_1);
  }
  return uVar1;
}



// Function: defineParameter at 100077c0

/* protected: static unsigned short __cdecl InputFile::defineParameter(class iclString const &) */

ushort __cdecl InputFile::defineParameter(iclString *param_1)

{
  ushort uVar1;
  
                    /* 0x77c0  144  ?defineParameter@InputFile@@KAGABViclString@@@Z */
  uVar1 = 0;
  if (activeDef != (InputFileDef *)0x0) {
    uVar1 = InputFileDef::defineParameter(activeDef,param_1);
  }
  return uVar1;
}



// Function: defineValueBlock at 100077e0

/* protected: static unsigned short __cdecl InputFile::defineValueBlock(class iclString const &,enum
   VBType,long,long) */

ushort __cdecl
InputFile::defineValueBlock(iclString *param_1,VBType param_2,long param_3,long param_4)

{
  ushort uVar1;
  
                    /* 0x77e0  146  ?defineValueBlock@InputFile@@KAGABViclString@@W4VBType@@JJ@Z */
  uVar1 = 0;
  if (activeDef != (InputFileDef *)0x0) {
    uVar1 = InputFileDef::defineValueBlock(activeDef,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



// Function: defineValueBlock at 10007810

/* protected: static unsigned short __cdecl InputFile::defineValueBlock(unsigned int,class iclString
   const &,enum VBType) */

ushort __cdecl InputFile::defineValueBlock(uint param_1,iclString *param_2,VBType param_3)

{
  ushort uVar1;
  
                    /* 0x7810  147  ?defineValueBlock@InputFile@@KAGIABViclString@@W4VBType@@@Z */
  uVar1 = 0;
  if (activeDef != (InputFileDef *)0x0) {
    uVar1 = InputFileDef::defineValueBlock(activeDef,param_1,param_2,param_3);
  }
  return uVar1;
}



// Function: endValueBlock at 10007840

/* protected: static void __cdecl InputFile::endValueBlock(void) */

void __cdecl InputFile::endValueBlock(void)

{
                    /* 0x7840  154  ?endValueBlock@InputFile@@KAXXZ */
  if (activeDef != (InputFileDef *)0x0) {
    InputFileDef::endValueBlock(activeDef);
    return;
  }
  return;
}



// Function: linkValueBlock at 10007850

/* protected: static void __cdecl InputFile::linkValueBlock(unsigned short) */

void __cdecl InputFile::linkValueBlock(ushort param_1)

{
                    /* 0x7850  176  ?linkValueBlock@InputFile@@KAXG@Z */
  if (activeDef != (InputFileDef *)0x0) {
    InputFileDef::linkValueBlock(activeDef,param_1);
  }
  return;
}



// Function: enableParameter at 10007870

/* protected: void __thiscall InputFile::enableParameter(class Parameter &,unsigned short) */

void __thiscall InputFile::enableParameter(InputFile *this,Parameter *param_1,ushort param_2)

{
                    /* 0x7870  153  ?enableParameter@InputFile@@IAEXAAVParameter@@G@Z */
  if ((*(int *)(this + 0x1c) != 0) && (param_2 < *(ushort *)(*(int *)(this + 0xc) + 0x10))) {
    *(Parameter **)(*(int *)(this + 0x1c) + (uint)param_2 * 4) = param_1;
    *(undefined4 *)(this + 0x20) = 1;
    if (*(int *)(this + 0x14) != 0) {
      *(undefined4 *)(*(int *)(this + 0x14) + 0x24) = 1;
    }
  }
  return;
}



// Function: disableParameter at 100078b0

/* protected: void __thiscall InputFile::disableParameter(unsigned short) */

void __thiscall InputFile::disableParameter(InputFile *this,ushort param_1)

{
                    /* 0x78b0  151  ?disableParameter@InputFile@@IAEXG@Z */
  if ((*(int *)(this + 0x1c) != 0) && (param_1 < *(ushort *)(*(int *)(this + 0xc) + 0x10))) {
    *(undefined4 *)(*(int *)(this + 0x1c) + (uint)param_1 * 4) = 0;
  }
  return;
}



// Function: FUN_100078e0 at 100078e0

undefined4 __cdecl FUN_100078e0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_10009790(*param_1);
    *param_1 = 0;
  }
  return 0;
}



// Function: FUN_10007900 at 10007900

undefined4 * __thiscall FUN_10007900(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d488;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = TextCRCFileAccBase::vftable;
  local_8 = 0xffffffff;
  FUN_100096d0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: ~InputFile at 10007960

/* public: virtual __thiscall InputFile::~InputFile(void) */

void __thiscall InputFile::~InputFile(InputFile *this)

{
                    /* 0x7960  41  ??1InputFile@@UAE@XZ */
  *(undefined ***)this = vftable;
  if (*(undefined4 **)(this + 0x10) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0x10))(1);
  }
  *(undefined4 *)(this + 0x10) = 0;
  operator_delete__(*(void **)(this + 0x1c));
  *(undefined4 *)(this + 0x1c) = 0;
  FUN_100078e0((int *)(this + 8));
  return;
}



// Function: getFileName at 100079a0

/* public: class iclString __thiscall InputFile::getFileName(void)const  */

undefined4 * __thiscall InputFile::getFileName(InputFile *this)

{
  uint uVar1;
  int *piVar2;
  short *this_00;
  undefined4 *puVar3;
  undefined4 *in_stack_00000004;
  undefined1 local_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
                    /* 0x79a0  158  ?getFileName@InputFile@@QBE?AViclString@@XZ */
  puStack_c = &LAB_1000d4f4;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = 0;
  local_18 = operator_new(0x16);
  local_8 = 1;
  if (local_18 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(local_18,0);
  }
  local_8 = local_8 & 0xffffff00;
  *in_stack_00000004 = piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(uVar1);
  }
  local_8 = 0;
  local_14 = 1;
  if (*(int *)(this + 8) != 0) {
    this_00 = FUN_100048e0(local_28,(int *)(*(int *)(this + 8) + 4));
    local_8 = 2;
    puVar3 = FUN_100075b0(this_00,&local_18);
    local_8._0_1_ = 3;
    FUN_10004bc0(in_stack_00000004,puVar3);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10004ab0(&local_18);
    local_8 = 4;
    FUN_10004ab0(&local_1c);
    local_8 = local_8 & 0xffffff00;
    FUN_10004ab0(&local_20);
  }
  ExceptionList = local_10;
  return in_stack_00000004;
}



// Function: FUN_10007a90 at 10007a90

int __cdecl FUN_10007a90(int *param_1)

{
  char *pcVar1;
  char cVar2;
  short sVar3;
  undefined **ppuVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined **ppuVar7;
  
  ppuVar4 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar4 == (undefined **)0x0) {
    ppuVar4 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar4 + 1);
  do {
    cVar2 = *(char *)ppuVar4;
    ppuVar4 = (undefined **)((int)ppuVar4 + 1);
  } while (cVar2 != '\0');
  ppuVar7 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar7 == (undefined **)0x0) {
    ppuVar7 = &PTR_1000e1a4;
  }
  puVar5 = (undefined4 *)
           FUN_10008580(DAT_100149ac,(char *)ppuVar7,(int)ppuVar4 - (int)pcVar1 & 0xffff);
  if (puVar5 != (undefined4 *)0x0) {
    sVar3 = FUN_100091f0((int)puVar5);
    if (sVar3 == 0) {
      iVar6 = FUN_10008510(DAT_100149ac,puVar5);
      return iVar6;
    }
    return 0x13;
  }
  return 0x10;
}



// Function: FUN_10007b00 at 10007b00

undefined4 * __thiscall FUN_10007b00(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_NamedValue>::vftable;
  *(undefined ***)((int)this + 0x14) = NamedObjectList<class_NamedValue>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007bb0 at 10007bb0

void __thiscall FUN_10007bb0(void *this,byte param_1)

{
  FUN_10007da0((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_10007bc0 at 10007bc0

void __fastcall FUN_10007bc0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_NamedValue>::vftable;
  param_1[5] = NamedObjectList<class_NamedValue>::vftable;
  local_8 = 0;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007c50 at 10007c50

undefined4 * __thiscall FUN_10007c50(void *this,int *param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d136;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100027e0((undefined4 *)this);
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  *(undefined ***)((int)this + 0x14) = NamedObject::vftable;
  *(int **)((int)this + 0x18) = param_1;
  (**(code **)(*param_1 + 4))(uVar1);
  *(undefined ***)this = NaObjLstBase::vftable;
  *(undefined ***)((int)this + 0x14) = NaObjLstBase::vftable;
  *(undefined4 *)((int)this + 0x1c) = param_2;
  *(undefined ***)this = NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  *(undefined ***)((int)this + 0x14) =
       NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007d00 at 10007d00

void __thiscall FUN_10007d00(void *this,byte param_1)

{
  FUN_10007e40((void *)((int)this + -0x14),param_1);
  return;
}



// Function: FUN_10007d10 at 10007d10

void __fastcall FUN_10007d10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  param_1[5] = NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  local_8 = 0;
  FUN_10008550((int)param_1);
  param_1[5] = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0(param_1 + 6);
  *param_1 = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007da0 at 10007da0

undefined4 * __thiscall FUN_10007da0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_NamedValue>::vftable;
  *(undefined4 *)((int)this + 0x14) = NamedObjectList<class_NamedValue>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007e40 at 10007e40

undefined4 * __thiscall FUN_10007e40(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000ccfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  *(undefined4 *)((int)this + 0x14) =
       NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  local_8 = 0;
  FUN_10008550((int)this);
  *(undefined4 *)((int)this + 0x14) = NamedObject::vftable;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)((int)this + 0x18));
  *(undefined ***)this = celList<class_NamedObject>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007ee0 at 10007ee0

undefined4 * __thiscall FUN_10007ee0(void *this,undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d55c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100090b0(this,param_1);
  *(undefined ***)this = TextCRCFileAccBase::vftable;
  *(undefined2 *)((int)this + 0x4a) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined2 *)((int)this + 0x54) = 0;
  local_8 = 1;
  uVar3 = 1;
  *(undefined ***)this = InputFileAcc::vftable;
  pvVar1 = operator_new(0x16);
  local_8._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(pvVar1,0);
  }
  local_8._0_1_ = 1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  FUN_10004ac0(&stack0xffffffd4,(char *)&PTR_1000e1a4,0xffff);
  local_8._0_1_ = 1;
  FUN_10007b00((void *)((int)this + 0x56),piVar2,uVar3);
  local_8._0_1_ = 4;
  uVar3 = 1;
  pvVar1 = operator_new(0x16);
  local_8._0_1_ = 5;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(pvVar1,0);
  }
  local_8._0_1_ = 4;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))();
  }
  FUN_10004ac0(&stack0xffffffd4,(char *)&PTR_1000e1a4,0xffff);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_10007c50((void *)((int)this + 0x76),piVar2,uVar3);
  *(undefined2 *)((int)this + 0x96) = 0;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008030 at 10008030

void __fastcall FUN_10008030(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000d602;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)((int)param_1 + 0x76);
  *puVar1 = NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  *(undefined4 *)((int)param_1 + 0x8a) =
       NamedObjectList<class_NamedObjectList<class_FileIndex>_>::vftable;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  FUN_10008550((int)puVar1);
  *(undefined4 *)((int)param_1 + 0x8a) = NamedObject::vftable;
  local_8._0_1_ = 4;
  FUN_10004ab0((undefined4 *)((int)param_1 + 0x8e));
  *puVar1 = celList<class_NamedObject>::vftable;
  local_8._0_1_ = 1;
  FUN_100029c0(puVar1);
  puVar1 = (undefined4 *)((int)param_1 + 0x56);
  *puVar1 = NamedObjectList<class_NamedValue>::vftable;
  *(undefined4 *)((int)param_1 + 0x6a) = NamedObjectList<class_NamedValue>::vftable;
  local_8._0_1_ = 8;
  FUN_10008550((int)puVar1);
  *(undefined4 *)((int)param_1 + 0x6a) = NamedObject::vftable;
  local_8._0_1_ = 9;
  FUN_10004ab0((undefined4 *)((int)param_1 + 0x6e));
  *puVar1 = celList<class_NamedObject>::vftable;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100029c0(puVar1);
  *param_1 = TextCRCFileAccBase::vftable;
  local_8 = 0xffffffff;
  FUN_100096d0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008130 at 10008130

undefined4 * __thiscall FUN_10008130(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d628;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  *(undefined ***)this = FileBlock::vftable;
  FUN_10003110(this,0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: unloadFile at 100081a0

/* public: static enum ICLStatus __cdecl InputFile::unloadFile(class iclString const &) */

ICLStatus __cdecl InputFile::unloadFile(iclString *param_1)

{
  ICLStatus IVar1;
  
                    /* 0x81a0  191  ?unloadFile@InputFile@@SA?AW4ICLStatus@@ABViclString@@@Z */
  IVar1 = FUN_10007a90((int *)param_1);
  return IVar1;
}



// Function: FUN_100081b0 at 100081b0

int __cdecl FUN_100081b0(int *param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined **ppuVar3;
  int *piVar4;
  void *this;
  undefined **ppuVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d65b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ppuVar3 = *(undefined ***)(*param_1 + 0x10);
  iVar6 = 0;
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  pcVar1 = (char *)((int)ppuVar3 + 1);
  do {
    cVar2 = *(char *)ppuVar3;
    ppuVar3 = (undefined **)((int)ppuVar3 + 1);
  } while (cVar2 != '\0');
  ppuVar5 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar5 == (undefined **)0x0) {
    ppuVar5 = &PTR_1000e1a4;
  }
  piVar4 = (int *)FUN_10008580(DAT_100149ac,(char *)ppuVar5,(int)ppuVar3 - (int)pcVar1 & 0xffff);
  if (piVar4 != (int *)0x0) {
    FUN_100092d0(piVar4);
LAB_10008222:
    *param_2 = piVar4;
    ExceptionList = local_10;
    return iVar6;
  }
  this = operator_new(0x98);
  local_8 = 0;
  if (this == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_10007ee0(this,param_1);
  }
  local_8 = 0xffffffff;
  if (piVar4 == (int *)0x0) {
    ExceptionList = local_10;
    return 2;
  }
  FUN_100092d0(piVar4);
  iVar6 = FUN_10009240((int)piVar4);
  if (iVar6 == 0) {
    iVar6 = 0x1b;
  }
  else {
    iVar6 = FUN_10002800(DAT_100149ac,piVar4);
    if (iVar6 == 0) goto LAB_10008222;
  }
  (**(code **)*piVar4)(1);
  ExceptionList = local_10;
  return iVar6;
}



// Function: FUN_100082d0 at 100082d0

undefined4 * __thiscall FUN_100082d0(void *this,byte param_1)

{
  FUN_10008030((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: InputFile at 10008300

/* protected: __thiscall InputFile::InputFile(class iclString const &,class InputFileDef &,void
   (__cdecl*)(void),short) */

InputFile * __thiscall
InputFile::InputFile
          (InputFile *this,iclString *param_1,InputFileDef *param_2,_func_void *param_3,
          short param_4)

{
  InputFile *pIVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  ICLStatus IVar5;
  undefined4 *puVar6;
  void *_Dst;
  undefined **ppuVar7;
  undefined2 in_stack_00000012;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x8300  23  ??0InputFile@@IAE@ABViclString@@AAVInputFileDef@@P6AXXZF@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d69b;
  local_10 = ExceptionList;
  uVar4 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(InputFileDef **)(this + 0xc) = param_2;
  pIVar1 = this + 8;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)pIVar1 = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  DAT_10014814 = param_4;
  if (param_4 < 1) {
    DAT_10014814 = 0x200;
  }
  IVar5 = FUN_100081b0((int *)param_1,(undefined4 *)pIVar1);
  setStatus(this,IVar5);
  IVar5 = verify(this);
  if (IVar5 == 0) {
    _param_4 = (undefined4 *)operator_new(0x28);
    if (_param_4 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      uVar3 = *(undefined4 *)pIVar1;
      *_param_4 = FileBlock::vftable;
      _param_4[1] = this;
      _param_4[2] = uVar3;
      _param_4[3] = 0;
      _param_4[4] = 0;
      _param_4[5] = 0;
      _param_4[6] = 0xffffffff;
      _param_4[7] = 0;
      _param_4[8] = 0;
      _param_4[9] = 0;
      *_param_4 = NamedBlock::vftable;
      puVar6 = _param_4;
    }
    local_8 = 0xffffffff;
    *(undefined4 **)(this + 0x10) = puVar6;
    if (puVar6 == (undefined4 *)0x0) {
      setStatus(this,2);
    }
    else {
      if (*(int *)(*(int *)(this + 0xc) + 8) == 0) {
        while (activeDef != (InputFileDef *)0x0) {
          FUN_10008630(0);
        }
        activeDef = *(InputFileDef **)(this + 0xc);
        FUN_10001540(&param_4,(char *)&PTR_1000e1a4);
        local_8 = 2;
        defineNamedBlock((iclString *)&param_4);
        local_8 = 0xffffffff;
        FUN_10004ab0((undefined4 *)&param_4);
        if (param_3 != (_func_void *)0x0) {
          (*param_3)();
        }
        activeDef = (InputFileDef *)0x0;
      }
      setStatus(this,**(ICLStatus **)(this + 0xc));
      if (*(int *)(this + 4) == 0) {
        uVar2 = *(ushort *)(*(int *)(this + 0xc) + 0x10);
        if (uVar2 != 0) {
          _Dst = operator_new__((uint)uVar2 * 4);
          *(void **)(this + 0x1c) = _Dst;
          if (_Dst == (void *)0x0) {
            setStatus(this,2);
          }
          else {
            memset(_Dst,0,(uint)uVar2 * 4);
          }
        }
        if (*(int *)(this + 4) == 0) {
          FUN_100069b0(*(void **)(this + 8),*(InputFileDef **)(this + 0xc));
          IVar5 = (**(code **)(**(int **)(this + 8) + 0x10))();
          setStatus(this,IVar5);
        }
      }
    }
  }
  else {
    ppuVar7 = *(undefined ***)(*(int *)param_1 + 0x10);
    if (ppuVar7 == (undefined **)0x0) {
      ppuVar7 = &PTR_1000e1a4;
    }
    iclError("Problem opening InputFile \'%s\'",ppuVar7,uVar4);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10008510 at 10008510

int __thiscall FUN_10008510(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100028b0(this,(int)param_1);
  if (((iVar1 == 0) && (*(int *)((int)this + 0x1c) != 0)) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(1);
  }
  return iVar1;
}



// Function: FUN_10008550 at 10008550

void __fastcall FUN_10008550(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    puVar1 = (undefined4 *)FUN_10002940(param_1);
    while (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
      puVar1 = (undefined4 *)FUN_10002950(param_1);
    }
  }
  FUN_10002980(param_1);
  return;
}



// Function: FUN_10008580 at 10008580

int __thiscall FUN_10008580(void *this,char *param_1,size_t param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined **ppuVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  local_8 = 0;
  iVar2 = FUN_10002940((int)this);
  if (param_2 == 0xffffffff) {
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    param_2 = (int)pcVar3 - (int)(param_1 + 1);
  }
  iVar6 = 0;
  if (iVar2 != 0) {
    while (iVar6 = local_8, local_8 == 0) {
      ppuVar4 = *(undefined ***)(*(int *)(iVar2 + 4) + 0x10);
      if (ppuVar4 == (undefined **)0x0) {
        ppuVar4 = &PTR_1000e1a4;
      }
      pcVar3 = (char *)((int)ppuVar4 + 1);
      do {
        cVar1 = *(char *)ppuVar4;
        ppuVar4 = (undefined **)((int)ppuVar4 + 1);
      } while (cVar1 != '\0');
      if (((int)ppuVar4 - (int)pcVar3 & 0xffffU) == param_2) {
        ppuVar4 = *(undefined ***)(*(int *)(iVar2 + 4) + 0x10);
        if (ppuVar4 == (undefined **)0x0) {
          ppuVar4 = &PTR_1000e1a4;
        }
        iVar5 = strncmp((char *)ppuVar4,param_1,param_2);
        iVar6 = iVar2;
        if (iVar5 != 0) goto LAB_10008614;
      }
      else {
LAB_10008614:
        iVar2 = FUN_10002950((int)this);
        iVar6 = local_8;
      }
      local_8 = iVar6;
      if (iVar2 == 0) {
        return local_8;
      }
    }
  }
  return iVar6;
}



// Function: FUN_10008630 at 10008630

void __cdecl FUN_10008630(DWORD param_1)

{
  Sleep(param_1);
  return;
}



// Function: FUN_10008650 at 10008650

LPCRITICAL_SECTION FUN_10008650(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)operator_new(0x18);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    InitializeCriticalSection(lpCriticalSection);
  }
  return lpCriticalSection;
}



// Function: FUN_10008670 at 10008670

void __cdecl FUN_10008670(LPCRITICAL_SECTION param_1)

{
  if (param_1 != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(param_1);
    operator_delete(param_1);
  }
  return;
}



// Function: FUN_10008690 at 10008690

bool __cdecl FUN_10008690(LPCRITICAL_SECTION param_1)

{
  if (param_1 != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(param_1);
  }
  return param_1 != (LPCRITICAL_SECTION)0x0;
}



// Function: FUN_100086b0 at 100086b0

void __cdecl FUN_100086b0(LPCRITICAL_SECTION param_1)

{
  if (param_1 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100086d0 at 100086d0

void __cdecl FUN_100086d0(short param_1)

{
  _close((int)param_1);
  return;
}



// Function: FUN_100086f0 at 100086f0

void __cdecl FUN_100086f0(short param_1)

{
  _eof((int)param_1);
  return;
}



// Function: FUN_10008710 at 10008710

void __cdecl FUN_10008710(short param_1,void *param_2,short param_3)

{
  _read((int)param_1,param_2,(int)param_3);
  return;
}



// Function: FUN_10008730 at 10008730

void __cdecl FUN_10008730(short param_1,long param_2,short param_3)

{
  _lseek((int)param_1,param_2,(int)param_3);
  return;
}



// Function: FUN_10008750 at 10008750

uint __cdecl FUN_10008750(char *param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  
  uVar1 = (-(ushort)((param_2 & 0x4000) != 0) & 0xc000) + 0x8000;
  if ((param_2 & 0x200) != 0) {
    param_2 = param_2 | 0x100;
    uVar1 = uVar1 | 0x200;
  }
  uVar4 = param_2 & 0x800;
  if (uVar4 != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_2 & 0x100) != 0) {
    if ((param_2 & 1) == 0) {
      iVar5 = (int)(short)(((short)(char)~(byte)param_2 & 2U | 1) << 7);
      iVar2 = (int)(short)(uVar1 | 0x102);
    }
    else {
      iVar5 = 0x100;
      iVar2 = (int)(short)(uVar1 | 0x102);
    }
    goto LAB_100087fc;
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      if ((param_2 & 4) == 0) {
        if (uVar4 != 0) goto LAB_100087ed;
      }
      else {
        uVar1 = uVar1 | 2;
      }
    }
    else {
LAB_100087ed:
      uVar1 = uVar1 | 1;
    }
  }
  iVar5 = 0;
  iVar2 = (int)(short)uVar1;
LAB_100087fc:
  iVar5 = _sopen(param_1,iVar2,0x20,iVar5);
  sVar3 = (short)iVar5;
  if (uVar4 != 0) {
    iVar5 = FUN_10008730(sVar3,0,2);
  }
  return CONCAT22((short)((uint)iVar5 >> 0x10),sVar3);
}



// Function: StdParam<char> at 10008830

/* public: __thiscall StdParam<char>::StdParam<char>(class StdParam<char> const &) */

void __thiscall StdParam<char>::StdParam<char>(StdParam<char> *this,StdParam<char> *param_1)

{
                    /* 0x8830  15  ??0?$StdParam@D@@QAE@ABV0@@Z */
  *(undefined ***)this = Parameter::vftable;
  this[4] = (StdParam<char>)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (StdParam<char>)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  *(undefined ***)this = vftable;
  this[9] = param_1[9];
  this[10] = param_1[10];
  return;
}



// Function: TextCharParam at 10008880

/* public: __thiscall TextCharParam::TextCharParam(class TextCharParam const &) */

void __thiscall TextCharParam::TextCharParam(TextCharParam *this,TextCharParam *param_1)

{
  undefined4 uVar1;
  
                    /* 0x8880  30  ??0TextCharParam@@QAE@ABV0@@Z */
  *(undefined ***)this = Parameter::vftable;
  this[4] = (TextCharParam)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (TextCharParam)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  uVar1 = *(undefined4 *)(param_1 + 5);
  *(undefined ***)this = StdParam<char>::vftable;
  *(undefined4 *)(this + 5) = uVar1;
  this[9] = param_1[9];
  this[10] = param_1[10];
  *(undefined ***)this = vftable;
  return;
}



// Function: operator= at 100088e0

/* public: class StdParam<char> & __thiscall StdParam<char>::operator=(class StdParam<char> const &)
    */

StdParam<char> * __thiscall StdParam<char>::operator=(StdParam<char> *this,StdParam<char> *param_1)

{
                    /* 0x88e0  59  ??4?$StdParam@D@@QAEAAV0@ABV0@@Z
                       0x88e0  66  ??4TextCharParam@@QAEAAV0@ABV0@@Z */
  this[4] = (StdParam<char>)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (StdParam<char>)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  this[9] = param_1[9];
  this[10] = param_1[10];
  return this;
}



// Function: ~StdParam<class_iclString> at 10008920

/* public: __thiscall StdParam<class iclString>::~StdParam<class iclString>(void) */

void __thiscall
StdParam<class_iclString>::~StdParam<class_iclString>(StdParam<class_iclString> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x8920  40  ??1?$StdParam@ViclString@@@@QAE@XZ */
  puStack_c = &LAB_1000d6d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10004ab0((undefined4 *)(this + 0xd));
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)(this + 9));
  ExceptionList = local_10;
  return;
}



// Function: StdParam<class_iclString> at 10008980

/* public: __thiscall StdParam<class iclString>::StdParam<class iclString>(class StdParam<class
   iclString> const &) */

StdParam<class_iclString> * __thiscall
StdParam<class_iclString>::StdParam<class_iclString>
          (StdParam<class_iclString> *this,StdParam<class_iclString> *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x8980  19  ??0?$StdParam@ViclString@@@@QAE@ABV0@@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d716;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = Parameter::vftable;
  this[4] = (StdParam<class_iclString>)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (StdParam<class_iclString>)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  *(undefined ***)this = vftable;
  piVar1 = *(int **)(param_1 + 9);
  *(int **)(this + 9) = piVar1;
  (**(code **)(*piVar1 + 4))(uVar2);
  local_8 = 0;
  piVar1 = *(int **)(param_1 + 0xd);
  *(int **)(this + 0xd) = piVar1;
  (**(code **)(*piVar1 + 4))();
  ExceptionList = local_10;
  return this;
}



// Function: operator= at 10008a20

/* public: class StdParam<class iclString> & __thiscall StdParam<class iclString>::operator=(class
   StdParam<class iclString> const &) */

StdParam<class_iclString> * __thiscall
StdParam<class_iclString>::operator=
          (StdParam<class_iclString> *this,StdParam<class_iclString> *param_1)

{
                    /* 0x8a20  61  ??4?$StdParam@ViclString@@@@QAEAAV0@ABV0@@Z
                       0x8a20  65  ??4STRINGParam@@QAEAAV0@ABV0@@Z */
  this[4] = (StdParam<class_iclString>)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (StdParam<class_iclString>)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  FUN_10004bc0(this + 9,(undefined4 *)(param_1 + 9));
  FUN_10004bc0(this + 0xd,(undefined4 *)(param_1 + 0xd));
  return this;
}



// Function: ~STRINGParam at 10008a70

/* public: __thiscall STRINGParam::~STRINGParam(void) */

void __thiscall STRINGParam::~STRINGParam(STRINGParam *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x8a70  43  ??1STRINGParam@@QAE@XZ */
  puStack_c = &LAB_1000d75e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_10004ab0((undefined4 *)(this + 0xd));
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)(this + 9));
  ExceptionList = local_10;
  return;
}



// Function: STRINGParam at 10008ad0

/* public: __thiscall STRINGParam::STRINGParam(class STRINGParam const &) */

STRINGParam * __thiscall STRINGParam::STRINGParam(STRINGParam *this,STRINGParam *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x8ad0  28  ??0STRINGParam@@QAE@ABV0@@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d7d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  StdParam<class_iclString>::StdParam<class_iclString>
            ((StdParam<class_iclString> *)this,(StdParam<class_iclString> *)param_1);
  *(undefined ***)this = vftable;
  ExceptionList = local_10;
  return this;
}



// Function: StdParam<class_iclDate> at 10008b30

/* public: __thiscall StdParam<class iclDate>::StdParam<class iclDate>(class StdParam<class iclDate>
   const &) */

void __thiscall
StdParam<class_iclDate>::StdParam<class_iclDate>
          (StdParam<class_iclDate> *this,StdParam<class_iclDate> *param_1)

{
                    /* 0x8b30  17  ??0?$StdParam@ViclDate@@@@QAE@ABV0@@Z */
  *(undefined ***)this = Parameter::vftable;
  this[4] = (StdParam<class_iclDate>)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (StdParam<class_iclDate>)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 9) = *(undefined4 *)(param_1 + 9);
  *(undefined4 *)(this + 0xd) = *(undefined4 *)(param_1 + 0xd);
  *(undefined4 *)(this + 0x11) = *(undefined4 *)(param_1 + 0x11);
  *(undefined4 *)(this + 0x15) = *(undefined4 *)(param_1 + 0x15);
  return;
}



// Function: operator= at 10008b90

/* public: class StdParam<class iclDate> & __thiscall StdParam<class iclDate>::operator=(class
   StdParam<class iclDate> const &) */

StdParam<class_iclDate> * __thiscall
StdParam<class_iclDate>::operator=(StdParam<class_iclDate> *this,StdParam<class_iclDate> *param_1)

{
                    /* 0x8b90  60  ??4?$StdParam@ViclDate@@@@QAEAAV0@ABV0@@Z
                       0x8b90  62  ??4DATEParam@@QAEAAV0@ABV0@@Z */
  this[4] = (StdParam<class_iclDate>)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (StdParam<class_iclDate>)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  *(undefined4 *)(this + 5) = *(undefined4 *)(param_1 + 5);
  *(undefined4 *)(this + 9) = *(undefined4 *)(param_1 + 9);
  *(undefined4 *)(this + 0xd) = *(undefined4 *)(param_1 + 0xd);
  *(undefined4 *)(this + 0x11) = *(undefined4 *)(param_1 + 0x11);
  *(undefined4 *)(this + 0x15) = *(undefined4 *)(param_1 + 0x15);
  return this;
}



// Function: DATEParam at 10008be0

/* public: __thiscall DATEParam::DATEParam(class DATEParam const &) */

void __thiscall DATEParam::DATEParam(DATEParam *this,DATEParam *param_1)

{
  undefined4 uVar1;
  
                    /* 0x8be0  21  ??0DATEParam@@QAE@ABV0@@Z */
  *(undefined ***)this = Parameter::vftable;
  this[4] = (DATEParam)((byte)this[4] ^ ((byte)this[4] ^ (byte)param_1[4]) & 1);
  this[4] = (DATEParam)(((byte)param_1[4] ^ (byte)this[4]) & 2 ^ (byte)this[4]);
  uVar1 = *(undefined4 *)(param_1 + 5);
  *(undefined ***)this = StdParam<class_iclDate>::vftable;
  *(undefined4 *)(this + 5) = uVar1;
  *(undefined4 *)(this + 9) = *(undefined4 *)(param_1 + 9);
  *(undefined4 *)(this + 0xd) = *(undefined4 *)(param_1 + 0xd);
  *(undefined4 *)(this + 0x11) = *(undefined4 *)(param_1 + 0x11);
  *(undefined4 *)(this + 0x15) = *(undefined4 *)(param_1 + 0x15);
  *(undefined ***)this = vftable;
  return;
}



// Function: Parameter at 10008c40

/* protected: __thiscall Parameter::Parameter(void) */

void __thiscall Parameter::Parameter(Parameter *this)

{
                    /* 0x8c40  26  ??0Parameter@@IAE@XZ */
  this[4] = (Parameter)((byte)this[4] & 0xfc);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 5) = 0;
  return;
}



// Function: setFilePos at 10008c60

/* public: void __thiscall Parameter::setFilePos(long) */

void __thiscall Parameter::setFilePos(Parameter *this,long param_1)

{
                    /* 0x8c60  181  ?setFilePos@Parameter@@QAEXJ@Z */
  if (((byte)this[4] & 2) != 0) {
    *(long *)(this + 5) = param_1;
  }
  return;
}



// Function: getLineNo at 10008c80

/* public: unsigned short __thiscall Parameter::getLineNo(class InputFileAcc &) */

ushort __thiscall Parameter::getLineNo(Parameter *this,InputFileAcc *param_1)

{
  int iVar1;
  
                    /* 0x8c80  160  ?getLineNo@Parameter@@QAEGAAVInputFileAcc@@@Z */
  if (0 < *(int *)(this + 5)) {
    iVar1 = FUN_10008f30(param_1,*(int *)(this + 5));
    *(int *)(this + 5) = -iVar1;
  }
  return -(short)*(undefined4 *)(this + 5);
}



// Function: setValue at 10008cb0

/* public: virtual enum ICLStatus __thiscall TextCharParam::setValue(char const *) */

ICLStatus __thiscall TextCharParam::setValue(TextCharParam *this,char *param_1)

{
  TextCharParam TVar1;
  
                    /* 0x8cb0  188  ?setValue@TextCharParam@@UAE?AW4ICLStatus@@PBD@Z */
  TVar1 = (TextCharParam)*param_1;
  this[4] = (TextCharParam)((byte)this[4] | 2);
  this[9] = TVar1;
  return 0;
}



// Function: setValue at 10008cd0

/* public: virtual enum ICLStatus __thiscall STRINGParam::setValue(char const *) */

ICLStatus __thiscall STRINGParam::setValue(STRINGParam *this,char *param_1)

{
                    /* 0x8cd0  187  ?setValue@STRINGParam@@UAE?AW4ICLStatus@@PBD@Z */
  FUN_10004ac0(this + 9,param_1,0xffff);
  this[4] = (STRINGParam)((byte)this[4] | 2);
  return 0;
}



// Function: setValue at 10008d00

/* public: virtual enum ICLStatus __thiscall DATEParam::setValue(char const *) */

ICLStatus __thiscall DATEParam::setValue(DATEParam *this,char *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 local_c [8];
  
                    /* 0x8d00  186  ?setValue@DATEParam@@UAE?AW4ICLStatus@@PBD@Z */
  puVar2 = (undefined4 *)FUN_10004540(local_c,param_1);
  *(undefined4 *)(this + 9) = *puVar2;
  uVar1 = puVar2[1];
  *(undefined4 *)(this + 0xd) = uVar1;
  if ((short)uVar1 != 0) {
    this[4] = (DATEParam)((byte)this[4] | 2);
    return 0;
  }
  return 0x19;
}



// Function: StdParam<char> at 10008d50

/* public: __thiscall StdParam<char>::StdParam<char>(void) */

undefined4 * __thiscall StdParam<char>::StdParam<char>(StdParam<char> *this)

{
  undefined4 *extraout_ECX;
  
                    /* 0x8d50  16  ??0?$StdParam@D@@QAE@XZ */
  Parameter::Parameter((Parameter *)this);
  *extraout_ECX = vftable;
  return extraout_ECX;
}



// Function: TextCharParam at 10008d60

/* public: __thiscall TextCharParam::TextCharParam(void) */

undefined4 * __thiscall TextCharParam::TextCharParam(TextCharParam *this)

{
  undefined4 *extraout_ECX;
  
                    /* 0x8d60  31  ??0TextCharParam@@QAE@XZ */
  Parameter::Parameter((Parameter *)this);
  *extraout_ECX = vftable;
  return extraout_ECX;
}



// Function: StdParam<class_iclString> at 10008d70

/* public: __thiscall StdParam<class iclString>::StdParam<class iclString>(void) */

StdParam<class_iclString> * __thiscall
StdParam<class_iclString>::StdParam<class_iclString>(StdParam<class_iclString> *this)

{
  uint uVar1;
  void *pvVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x8d70  20  ??0?$StdParam@ViclString@@@@QAE@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d7ac;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  Parameter::Parameter((Parameter *)this);
  *(undefined ***)this = vftable;
  pvVar2 = operator_new(0x16);
  local_8 = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_100014b0(pvVar2,0);
  }
  local_8 = 0xffffffff;
  *(int **)(this + 9) = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(uVar1);
  }
  local_8 = 1;
  pvVar2 = operator_new(0x16);
  local_8._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_100014b0(pvVar2,0);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  *(int **)(this + 0xd) = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))();
  }
  ExceptionList = local_10;
  return this;
}



// Function: STRINGParam at 10008e40

/* public: __thiscall STRINGParam::STRINGParam(void) */

STRINGParam * __thiscall STRINGParam::STRINGParam(STRINGParam *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x8e40  29  ??0STRINGParam@@QAE@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d7d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  StdParam<class_iclString>::StdParam<class_iclString>((StdParam<class_iclString> *)this);
  *(undefined ***)this = vftable;
  ExceptionList = local_10;
  return this;
}



// Function: StdParam<class_iclDate> at 10008ea0

/* public: __thiscall StdParam<class iclDate>::StdParam<class iclDate>(void) */

undefined4 * __thiscall
StdParam<class_iclDate>::StdParam<class_iclDate>(StdParam<class_iclDate> *this)

{
  undefined4 *extraout_ECX;
  
                    /* 0x8ea0  18  ??0?$StdParam@ViclDate@@@@QAE@XZ */
  Parameter::Parameter((Parameter *)this);
  *extraout_ECX = vftable;
  *(undefined4 *)((int)extraout_ECX + 9) = 0;
  *(undefined4 *)((int)extraout_ECX + 0xd) = 0;
  *(undefined4 *)((int)extraout_ECX + 0x11) = 0;
  *(undefined4 *)((int)extraout_ECX + 0x15) = 0;
  return extraout_ECX;
}



// Function: DATEParam at 10008ec0

/* public: __thiscall DATEParam::DATEParam(void) */

undefined4 * __thiscall DATEParam::DATEParam(DATEParam *this)

{
  undefined4 *extraout_ECX;
  
                    /* 0x8ec0  22  ??0DATEParam@@QAE@XZ */
  Parameter::Parameter((Parameter *)this);
  *(undefined4 *)((int)extraout_ECX + 9) = 0;
  *(undefined4 *)((int)extraout_ECX + 0xd) = 0;
  *(undefined4 *)((int)extraout_ECX + 0x11) = 0;
  *(undefined4 *)((int)extraout_ECX + 0x15) = 0;
  *extraout_ECX = vftable;
  return extraout_ECX;
}



// Function: FUN_10008ee0 at 10008ee0

void __fastcall FUN_10008ee0(undefined4 *param_1)

{
  *param_1 = iclRefCount::vftable;
  return;
}



// Function: FUN_10008ef0 at 10008ef0

short __thiscall FUN_10008ef0(void *this,short param_1)

{
  short sVar1;
  
  sVar1 = *(short *)((int)this + 4);
  if (sVar1 != 0) {
    sVar1 = sVar1 + -1;
    *(short *)((int)this + 4) = sVar1;
    if (((sVar1 == 0) && (*(short *)((int)this + 6) != 0)) && (param_1 == 0)) {
                    /* WARNING: Load size is inaccurate */
      (*(code *)**this)(1);
    }
  }
  return sVar1;
}



// Function: FUN_10008f30 at 10008f30

int __thiscall FUN_10008f30(void *this,int param_1)

{
  short sVar1;
  short sVar2;
  undefined **ppuVar3;
  uint uVar4;
  char *_Str;
  char *pcVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar6 = param_1;
  iVar7 = 0;
  bVar8 = -1 < param_1;
  param_1 = iVar7;
  if (bVar8) {
    ppuVar3 = *(undefined ***)(*(int *)((int)this + 4) + 0x10);
    if (ppuVar3 == (undefined **)0x0) {
      ppuVar3 = &PTR_1000e1a4;
    }
    uVar4 = FUN_10008750((char *)ppuVar3,0x8001);
    sVar1 = (short)uVar4;
    if (sVar1 != -1) {
      _Str = (char *)operator_new__((int)*(short *)((int)this + 0x28) + 1);
      if (_Str != (char *)0x0) {
        param_1 = 1;
        if (0 < iVar6) {
          do {
            iVar7 = (int)*(short *)((int)this + 0x28);
            if (iVar6 <= *(short *)((int)this + 0x28)) {
              iVar7 = iVar6;
            }
            sVar2 = FUN_10008710(sVar1,_Str,(short)iVar7);
            if (sVar2 < 1) break;
            iVar6 = iVar6 - sVar2;
            _Str[sVar2] = '\0';
            for (pcVar5 = strchr(_Str,10); pcVar5 != (char *)0x0; pcVar5 = strchr(pcVar5 + 1,10)) {
              param_1 = param_1 + 1;
            }
          } while (0 < iVar6);
        }
        operator_delete__(_Str);
      }
      FUN_100086d0(sVar1);
    }
  }
  return param_1;
}



// Function: FUN_10009010 at 10009010

void __thiscall FUN_10009010(void *this,undefined4 param_1)

{
  if (*(int *)((int)this + 0x46) == 0) {
    *(undefined4 *)((int)this + 0x46) = param_1;
  }
  return;
}



// Function: FUN_10009030 at 10009030

int __fastcall FUN_10009030(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x14))(1);
  if (iVar1 == 0) {
    FUN_10002cc0((void *)((int)param_1 + 0x2e),(char *)param_1[7],param_1[9] - param_1[7]);
  }
  return iVar1;
}



// Function: FUN_10009060 at 10009060

void __fastcall FUN_10009060(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = celList<class_TextFileAccBase::AppFile>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100090b0 at 100090b0

undefined4 * __thiscall FUN_100090b0(void *this,undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *pvVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d861;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedObject::vftable;
  piVar1 = (int *)*param_1;
  *(int **)((int)this + 4) = piVar1;
  (**(code **)(*piVar1 + 4))(uVar2);
  local_8 = 1;
  *(undefined ***)this = TextFileAccBase::vftable;
  FUN_100027e0((undefined4 *)((int)this + 8));
  *(undefined4 *)((int)this + 8) = celList<class_TextFileAccBase::AppFile>::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),3);
  *(undefined4 *)((int)this + 0x1c) = 0;
  pvVar3 = operator_new__((int)DAT_10014814 + 1);
  *(void **)((int)this + 0x20) = pvVar3;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(short *)((int)this + 0x28) = DAT_10014814;
  *(undefined4 *)((int)this + 0x2a) = 0;
  FUN_10002ce0((void *)((int)this + 0x2e),(char *)0x0,0x82);
  *(undefined4 *)((int)this + 0x3e) = 0xffffffff;
  *(undefined4 *)((int)this + 0x42) = 0xffffffff;
  *(undefined4 *)((int)this + 0x46) = 0;
  if (*(int *)((int)this + 0x20) == 0) {
    *(undefined4 *)((int)this + 0x46) = 2;
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009190 at 10009190

undefined4 * __thiscall FUN_10009190(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000d888;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = celList<class_TextFileAccBase::AppFile>::vftable;
  local_8 = 0xffffffff;
  FUN_100029c0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100091f0 at 100091f0

short __fastcall FUN_100091f0(int param_1)

{
  int iVar1;
  short local_8;
  
  iVar1 = FUN_10002940(param_1 + 8);
  local_8 = 0;
  if (iVar1 == 0) {
    return 0;
  }
  do {
    local_8 = local_8 + *(short *)(iVar1 + 0x10);
    iVar1 = FUN_10002950(param_1 + 8);
  } while (iVar1 != 0);
  return local_8;
}



// Function: FUN_10009240 at 10009240

int __fastcall FUN_10009240(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_10002940(param_1 + 8);
  iVar2 = _getpid();
  if (iVar1 != 0) {
    while (*(int *)(iVar1 + 0xc) != iVar2) {
      iVar1 = FUN_10002950(param_1 + 8);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (iVar2 != *(int *)(param_1 + 0x2a)) {
      FUN_10002cc0((void *)(param_1 + 0x2e),(char *)&PTR_1000e1a4,0);
      *(undefined4 *)(param_1 + 0x3e) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x42) = 0xffffffff;
      *(int *)(param_1 + 0x2a) = iVar2;
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      iVar2 = FUN_10008730(*(short *)(iVar1 + 4),*(long *)(iVar1 + 8),0);
      if (iVar2 == -1) {
        return 0;
      }
    }
  }
  return iVar1;
}



// Function: FUN_100092d0 at 100092d0

void __fastcall FUN_100092d0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  
  iVar1 = FUN_10009240((int)param_1);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*param_1 + 8))();
    FUN_10009010(param_1,uVar2);
    iVar1 = FUN_10009240(extraout_ECX);
    if (iVar1 == 0) {
      return;
    }
  }
  *(short *)(iVar1 + 0x10) = *(short *)(iVar1 + 0x10) + 1;
  return;
}



// Function: FUN_10009300 at 10009300

int __fastcall FUN_10009300(int param_1)

{
  short sVar1;
  int iVar2;
  undefined **ppuVar3;
  uint uVar4;
  undefined4 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d8bb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_10009240(param_1);
  if (iVar2 != 0) {
    ExceptionList = local_10;
    return 0;
  }
  ppuVar3 = *(undefined ***)(*(int *)(param_1 + 4) + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  uVar4 = FUN_10008750((char *)ppuVar3,0x8001);
  sVar1 = (short)uVar4;
  if (sVar1 != -1) {
    puVar5 = (undefined4 *)operator_new(0x12);
    local_8 = 0;
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      iVar2 = _getpid();
      puVar5[3] = iVar2;
      *puVar5 = 0;
      puVar5[1] = (int)sVar1;
      puVar5[2] = 0;
      *(undefined2 *)(puVar5 + 4) = 0;
    }
    local_8 = 0xffffffff;
    if (puVar5 == (undefined4 *)0x0) {
      iVar2 = 2;
    }
    else {
      iVar2 = FUN_10002800((void *)(param_1 + 8),puVar5);
      puVar5[2] = 0;
      if (iVar2 == 0) {
        ExceptionList = local_10;
        return 0;
      }
    }
    operator_delete(puVar5);
    FUN_100086d0(sVar1);
    ExceptionList = local_10;
    return iVar2;
  }
  ExceptionList = local_10;
  return 0x1b;
}



// Function: FUN_10009420 at 10009420

undefined4 __fastcall FUN_10009420(int param_1)

{
  short sVar1;
  void *pvVar2;
  
  pvVar2 = (void *)FUN_10009240(param_1);
  if (pvVar2 != (void *)0x0) {
    sVar1 = FUN_100086d0(*(short *)((int)pvVar2 + 4));
    if (sVar1 != 0) {
      return 0x1a;
    }
    FUN_100028b0((void *)(param_1 + 8),(int)pvVar2);
    operator_delete(pvVar2);
    FUN_10002cc0((void *)(param_1 + 0x2e),(char *)&PTR_1000e1a4,0);
    *(undefined4 *)(param_1 + 0x3e) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x42) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return 0;
}



// Function: FUN_10009490 at 10009490

void __fastcall FUN_10009490(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009240((int)param_1);
  if ((iVar1 == 0) && (iVar1 = FUN_10009300((int)param_1), iVar1 != 0)) {
    return;
  }
  iVar1 = (**(code **)(*param_1 + 0xc))(0);
  if (iVar1 == 0) {
    *(undefined4 *)((int)param_1 + 0x3e) = 0;
  }
  return;
}



// Function: FUN_100094c0 at 100094c0

undefined4 __fastcall FUN_100094c0(int param_1)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  undefined **ppuVar6;
  short sVar7;
  int iVar8;
  
  puVar3 = (undefined4 *)FUN_10009240(param_1);
  if (puVar3 == (undefined4 *)0x0) {
    return 0x1b;
  }
  pcVar5 = *(char **)(param_1 + 0x1c);
  sVar7 = 0;
  if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {
    pcVar4 = pcVar5;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    sVar7 = (short)pcVar4 - ((short)pcVar5 + 1);
    if (pcVar5[sVar7 + -1] == '\x1a') {
      sVar7 = sVar7 + -1;
    }
    strncpy(*(char **)(param_1 + 0x20),pcVar5,(int)sVar7);
  }
  sVar2 = FUN_10008710(*(short *)(puVar3 + 1),(void *)(*(int *)(param_1 + 0x20) + (int)sVar7),
                       *(short *)(param_1 + 0x28) - sVar7);
  iVar8 = (int)sVar2 + (int)sVar7;
  if (0 < iVar8) {
    *(undefined1 *)(iVar8 + *(int *)(param_1 + 0x20)) = 0;
    *(char **)(param_1 + 0x1c) = *(char **)(param_1 + 0x20);
    pcVar5 = strchr(*(char **)(param_1 + 0x20),10);
    *(char **)(param_1 + 0x24) = pcVar5;
    if (pcVar5 == (char *)0x0) {
      if (*(short *)(param_1 + 0x28) <= iVar8) {
        ppuVar6 = *(undefined ***)(*(int *)(param_1 + 4) + 0x10);
        if (ppuVar6 == (undefined **)0x0) {
          ppuVar6 = &PTR_1000e1a4;
        }
        iclError("%s: Line %lu larger than buffer size (%ld)\n",ppuVar6,*(int *)(param_1 + 0x3e) + 1
                 ,(int)*(short *)(param_1 + 0x28));
        *(undefined4 *)(param_1 + 0x1c) = 0;
        return 0x19;
      }
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x20) + -1 + iVar8;
    }
    return 0;
  }
  sVar7 = FUN_100086f0(*(short *)(puVar3 + 1));
  if (sVar7 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return 0x1a;
  }
  *puVar3 = 1;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return 0x22;
}



// Function: FUN_10009600 at 10009600

undefined4 __thiscall FUN_10009600(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_10009240((int)this);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x1b;
  }
  if (param_1 == puVar1[2]) {
    return 0;
  }
  if (*(int *)((int)this + 0x24) != 0) {
    iVar2 = param_1 - puVar1[2];
    if (iVar2 + 0x7fffU < 0xffff) {
      *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + (int)(short)iVar2;
      if ((*(uint *)((int)this + 0x24) < *(uint *)((int)this + 0x20)) ||
         ((int)*(short *)((int)this + 0x28) + *(uint *)((int)this + 0x20) <=
          *(uint *)((int)this + 0x24))) goto LAB_10009657;
    }
    else {
LAB_10009657:
      *(undefined4 *)((int)this + 0x24) = 0;
    }
    if (*(int *)((int)this + 0x24) != 0) goto LAB_10009685;
  }
  iVar2 = FUN_10008730(*(short *)(puVar1 + 1),param_1,0);
  if (iVar2 == -1) {
    return 0x1a;
  }
LAB_10009685:
  *puVar1 = 0;
  puVar1[2] = param_1;
  *(undefined4 *)((int)this + 0x1c) = 0;
  FUN_10002cc0((void *)((int)this + 0x2e),(char *)&PTR_1000e1a4,0);
  *(undefined4 *)((int)this + 0x3e) = 0xffffffff;
  *(undefined4 *)((int)this + 0x42) = 0xffffffff;
  return 0;
}



// Function: FUN_100096d0 at 100096d0

void __fastcall FUN_100096d0(undefined4 *param_1)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000d911;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = TextFileAccBase::vftable;
  local_8 = 2;
  FUN_10009420((int)param_1);
  pvVar1 = (void *)FUN_10002940((int)(param_1 + 2));
  while (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
    pvVar1 = (void *)FUN_10002950((int)(param_1 + 2));
  }
  operator_delete__((void *)param_1[8]);
  local_8._0_1_ = 1;
  operator_delete__(*(void **)((int)param_1 + 0x3a));
  param_1[2] = celList<class_TextFileAccBase::AppFile>::vftable;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100029c0(param_1 + 2);
  *param_1 = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009790 at 10009790

void __fastcall FUN_10009790(int param_1)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = FUN_10009240(param_1);
  if (iVar2 != 0) {
    psVar1 = (short *)(iVar2 + 0x10);
    *psVar1 = *psVar1 + -1;
    if (*psVar1 == 0) {
      FUN_10009420(param_1);
      return;
    }
  }
  return;
}



// Function: FUN_100097b0 at 100097b0

int __thiscall FUN_100097b0(void *this,int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = FUN_10009240((int)this);
  if (iVar1 == 0) {
    return 0x1b;
  }
  pcVar2 = *(char **)((int)this + 0x24);
  *(char **)((int)this + 0x1c) = pcVar2;
  if (pcVar2 != (char *)0x0) {
    pcVar2 = strchr(pcVar2,10);
    *(char **)((int)this + 0x24) = pcVar2;
  }
  if (*(int *)((int)this + 0x24) == 0) {
    iVar3 = FUN_100094c0((int)this);
    if (iVar3 != 0) {
      FUN_10002cc0((void *)((int)this + 0x2e),(char *)&PTR_1000e1a4,0);
      *(undefined4 *)((int)this + 0x3e) = 0xffffffff;
      *(undefined4 *)((int)this + 0x42) = 0xffffffff;
      return iVar3;
    }
  }
  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 1;
  if (param_1 != 0) {
    *(undefined4 *)((int)this + 0x42) = *(undefined4 *)(iVar1 + 8);
  }
  if (*(int *)((int)this + 0x3e) != -1) {
    *(int *)((int)this + 0x3e) = *(int *)((int)this + 0x3e) + 1;
  }
  *(int *)(iVar1 + 8) =
       *(int *)(iVar1 + 8) + (*(int *)((int)this + 0x24) - *(int *)((int)this + 0x1c));
  return iVar3;
}



// Function: FUN_10009850 at 10009850

undefined4 * __thiscall FUN_10009850(void *this,byte param_1)

{
  FUN_100096d0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10009880 at 10009880

bool __thiscall FUN_10009880(void *this,int *param_1)

{
  byte bVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  bool bVar4;
  
  ppuVar2 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar2 == (undefined **)0x0) {
    ppuVar2 = &PTR_1000e1a4;
  }
                    /* WARNING: Load size is inaccurate */
  ppuVar3 = *(undefined ***)(*this + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  while( true ) {
    bVar1 = *(byte *)ppuVar3;
    bVar4 = bVar1 < *(byte *)ppuVar2;
    if (bVar1 != *(byte *)ppuVar2) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = *(byte *)((int)ppuVar3 + 1);
    bVar4 = bVar1 < *(byte *)((int)ppuVar2 + 1);
    if (bVar1 != *(byte *)((int)ppuVar2 + 1)) break;
    ppuVar3 = (undefined **)((int)ppuVar3 + 2);
    ppuVar2 = (undefined **)((int)ppuVar2 + 2);
    if (bVar1 == 0) {
      return true;
    }
  }
  return 1 - bVar4 == (uint)(bVar4 != 0);
}



// Function: FUN_100098f0 at 100098f0

bool __thiscall FUN_100098f0(void *this,int *param_1)

{
  byte bVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  bool bVar4;
  
  ppuVar2 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar2 == (undefined **)0x0) {
    ppuVar2 = &PTR_1000e1a4;
  }
                    /* WARNING: Load size is inaccurate */
  ppuVar3 = *(undefined ***)(*this + 0x10);
  if (ppuVar3 == (undefined **)0x0) {
    ppuVar3 = &PTR_1000e1a4;
  }
  while( true ) {
    bVar1 = *(byte *)ppuVar3;
    bVar4 = bVar1 < *(byte *)ppuVar2;
    if (bVar1 != *(byte *)ppuVar2) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = *(byte *)((int)ppuVar3 + 1);
    bVar4 = bVar1 < *(byte *)((int)ppuVar2 + 1);
    if (bVar1 != *(byte *)((int)ppuVar2 + 1)) break;
    ppuVar3 = (undefined **)((int)ppuVar3 + 2);
    ppuVar2 = (undefined **)((int)ppuVar2 + 2);
    if (bVar1 == 0) {
      return false;
    }
  }
  return (int)((1 - (uint)bVar4) - (uint)(bVar4 != 0)) < 0;
}



// Function: FUN_10009960 at 10009960

bool __thiscall FUN_10009960(void *this,int *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  bool bVar6;
  
  ppuVar4 = *(undefined ***)(*param_1 + 0x10);
  if (ppuVar4 == (undefined **)0x0) {
    ppuVar4 = &PTR_1000e1a4;
  }
                    /* WARNING: Load size is inaccurate */
  ppuVar5 = *(undefined ***)(*this + 0x10);
  if (ppuVar5 == (undefined **)0x0) {
    ppuVar5 = &PTR_1000e1a4;
  }
  while( true ) {
    bVar1 = *(byte *)ppuVar5;
    bVar6 = bVar1 < *(byte *)ppuVar4;
    if (bVar1 != *(byte *)ppuVar4) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = *(byte *)((int)ppuVar5 + 1);
    bVar6 = bVar1 < *(byte *)((int)ppuVar4 + 1);
    if (bVar1 != *(byte *)((int)ppuVar4 + 1)) break;
    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
    ppuVar4 = (undefined **)((int)ppuVar4 + 2);
    if (bVar1 == 0) {
      return true;
    }
  }
  uVar2 = (uint)(bVar6 != 0);
  uVar3 = 1 - bVar6;
  return uVar3 == uVar2 || (int)(uVar3 - uVar2) < 0;
}



// Function: FUN_100099d0 at 100099d0

int __thiscall FUN_100099d0(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = ValueBase::dataSize(*(VBType *)((int)this + 4));
  return uVar1 * param_1 + *(int *)((int)this + 8);
}



// Function: IncValueT<unsigned_char,0> at 100099f0

/* public: __thiscall IncValueT<unsigned char,0>::IncValueT<unsigned char,0>(unsigned char) */

void __thiscall
IncValueT<unsigned_char,0>::IncValueT<unsigned_char,0>
          (IncValueT<unsigned_char,0> *this,uchar param_1)

{
                    /* 0x99f0  4  ??0?$IncValueT@E$0A@@@QAE@E@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  this[4] = (IncValueT<unsigned_char,0>)param_1;
  return;
}



// Function: ~IncValueT<unsigned_char,0> at 10009a50

/* public: virtual __thiscall IncValueT<unsigned char,0>::~IncValueT<unsigned char,0>(void) */

void __thiscall
IncValueT<unsigned_char,0>::~IncValueT<unsigned_char,0>(IncValueT<unsigned_char,0> *this)

{
                    /* 0x9a50  34  ??1?$IncValueT@E$0A@@@UAE@XZ */
  *(undefined ***)this = vftable;
  *(undefined ***)this = ValueBase::vftable;
  return;
}



// Function: operator++ at 10009aa0

/* public: virtual void __thiscall IncValueT<signed char,1>::operator++(void) */

void __thiscall IncValueT<signed_char,1>::operator++(IncValueT<signed_char,1> *this)

{
                    /* 0x9aa0  76  ??E?$IncValueT@C$00@@UAEXXZ
                       0x9aa0  77  ??E?$IncValueT@E$0A@@@UAEXXZ */
  this[4] = (IncValueT<signed_char,1>)((char)this[4] + '\x01');
  return;
}



// Function: operator-- at 10009ab0

/* public: virtual void __thiscall IncValueT<signed char,1>::operator--(void) */

void __thiscall IncValueT<signed_char,1>::operator--(IncValueT<signed_char,1> *this)

{
                    /* 0x9ab0  83  ??F?$IncValueT@C$00@@UAEXXZ
                       0x9ab0  84  ??F?$IncValueT@E$0A@@@UAEXXZ */
  this[4] = (IncValueT<signed_char,1>)((char)this[4] + -1);
  return;
}



// Function: operator< at 10009ac0

/* public: virtual int __thiscall IncValueT<unsigned char,0>::operator<(class ValueBase const
   &)const  */

int __thiscall
IncValueT<unsigned_char,0>::operator<(IncValueT<unsigned_char,0> *this,ValueBase *param_1)

{
                    /* 0x9ac0  91  ??M?$IncValueT@E$0A@@@UBEHABVValueBase@@@Z */
  return (uint)((byte)this[4] < (byte)*(IncValueT<unsigned_char,0> *)(param_1 + 4));
}



// Function: operator<= at 10009ae0

/* public: virtual int __thiscall IncValueT<unsigned char,0>::operator<=(class ValueBase const
   &)const  */

int __thiscall
IncValueT<unsigned_char,0>::operator<=(IncValueT<unsigned_char,0> *this,ValueBase *param_1)

{
                    /* 0x9ae0  98  ??N?$IncValueT@E$0A@@@UBEHABVValueBase@@@Z */
  return (uint)((byte)this[4] <= (byte)*(IncValueT<unsigned_char,0> *)(param_1 + 4));
}



// Function: IncValueT<signed_char,1> at 10009b00

/* public: __thiscall IncValueT<signed char,1>::IncValueT<signed char,1>(signed char) */

void __thiscall
IncValueT<signed_char,1>::IncValueT<signed_char,1>(IncValueT<signed_char,1> *this,char param_1)

{
                    /* 0x9b00  2  ??0?$IncValueT@C$00@@QAE@C@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  this[4] = (IncValueT<signed_char,1>)param_1;
  return;
}



// Function: ~IncValueT<signed_char,1> at 10009b60

/* public: virtual __thiscall IncValueT<signed char,1>::~IncValueT<signed char,1>(void) */

void __thiscall IncValueT<signed_char,1>::~IncValueT<signed_char,1>(IncValueT<signed_char,1> *this)

{
                    /* 0x9b60  33  ??1?$IncValueT@C$00@@UAE@XZ */
  *(undefined ***)this = vftable;
  *(undefined ***)this = ValueBase::vftable;
  return;
}



// Function: getType at 10009bb0

/* public: virtual enum VBType __thiscall IncValueT<signed char,1>::getType(void)const  */

VBType __thiscall IncValueT<signed_char,1>::getType(IncValueT<signed_char,1> *this)

{
                    /* 0x9bb0  164  ?getType@?$IncValueT@C$00@@UBE?AW4VBType@@XZ */
  return 1;
}



// Function: operator== at 10009bc0

/* public: virtual int __thiscall IncValueT<signed char,1>::operator==(class ValueBase const &)const
    */

int __thiscall
IncValueT<signed_char,1>::operator==(IncValueT<signed_char,1> *this,ValueBase *param_1)

{
                    /* 0x9bc0  67  ??8?$IncValueT@C$00@@UBEHABVValueBase@@@Z
                       0x9bc0  68  ??8?$IncValueT@E$0A@@@UBEHABVValueBase@@@Z */
  return (uint)(this[4] == *(IncValueT<signed_char,1> *)(param_1 + 4));
}



// Function: operator< at 10009be0

/* public: virtual int __thiscall IncValueT<signed char,1>::operator<(class ValueBase const &)const
    */

int __thiscall
IncValueT<signed_char,1>::operator<(IncValueT<signed_char,1> *this,ValueBase *param_1)

{
                    /* 0x9be0  90  ??M?$IncValueT@C$00@@UBEHABVValueBase@@@Z */
  return (uint)((char)this[4] < (char)param_1[4]);
}



// Function: operator<= at 10009c00

/* public: virtual int __thiscall IncValueT<signed char,1>::operator<=(class ValueBase const &)const
    */

int __thiscall
IncValueT<signed_char,1>::operator<=(IncValueT<signed_char,1> *this,ValueBase *param_1)

{
                    /* 0x9c00  97  ??N?$IncValueT@C$00@@UBEHABVValueBase@@@Z */
  return (uint)((char)this[4] <= (char)param_1[4]);
}



// Function: IncValueT<unsigned_short,2> at 10009c20

/* public: __thiscall IncValueT<unsigned short,2>::IncValueT<unsigned short,2>(unsigned short) */

void __thiscall
IncValueT<unsigned_short,2>::IncValueT<unsigned_short,2>
          (IncValueT<unsigned_short,2> *this,ushort param_1)

{
                    /* 0x9c20  8  ??0?$IncValueT@G$01@@QAE@G@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(ushort *)(this + 4) = param_1;
  return;
}



// Function: ~IncValueT<unsigned_short,2> at 10009c80

/* public: virtual __thiscall IncValueT<unsigned short,2>::~IncValueT<unsigned short,2>(void) */

void __thiscall
IncValueT<unsigned_short,2>::~IncValueT<unsigned_short,2>(IncValueT<unsigned_short,2> *this)

{
                    /* 0x9c80  36  ??1?$IncValueT@G$01@@UAE@XZ */
  *(undefined ***)this = vftable;
  *(undefined ***)this = ValueBase::vftable;
  return;
}



// Function: getType at 10009cd0

/* public: virtual enum VBType __thiscall IncValueT<unsigned short,2>::getType(void)const  */

VBType __thiscall IncValueT<unsigned_short,2>::getType(IncValueT<unsigned_short,2> *this)

{
                    /* 0x9cd0  167  ?getType@?$IncValueT@G$01@@UBE?AW4VBType@@XZ */
  return 2;
}



// Function: operator-- at 10009ce0

/* public: virtual void __thiscall IncValueT<unsigned short,2>::operator--(void) */

void __thiscall IncValueT<unsigned_short,2>::operator--(IncValueT<unsigned_short,2> *this)

{
                    /* 0x9ce0  86  ??F?$IncValueT@G$01@@UAEXXZ */
  *(short *)(this + 4) = *(short *)(this + 4) + -1;
  return;
}



// Function: operator< at 10009cf0

/* public: virtual int __thiscall IncValueT<unsigned short,2>::operator<(class ValueBase const
   &)const  */

int __thiscall
IncValueT<unsigned_short,2>::operator<(IncValueT<unsigned_short,2> *this,ValueBase *param_1)

{
                    /* 0x9cf0  93  ??M?$IncValueT@G$01@@UBEHABVValueBase@@@Z */
  return (uint)(*(ushort *)(this + 4) < *(ushort *)(param_1 + 4));
}



// Function: operator<= at 10009d10

/* public: virtual int __thiscall IncValueT<unsigned short,2>::operator<=(class ValueBase const
   &)const  */

int __thiscall
IncValueT<unsigned_short,2>::operator<=(IncValueT<unsigned_short,2> *this,ValueBase *param_1)

{
                    /* 0x9d10  100  ??N?$IncValueT@G$01@@UBEHABVValueBase@@@Z */
  return (uint)(*(ushort *)(this + 4) <= *(ushort *)(param_1 + 4));
}



// Function: IncValueT<short,3> at 10009d30

/* public: __thiscall IncValueT<short,3>::IncValueT<short,3>(short) */

void __thiscall IncValueT<short,3>::IncValueT<short,3>(IncValueT<short,3> *this,short param_1)

{
                    /* 0x9d30  6  ??0?$IncValueT@F$02@@QAE@F@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(short *)(this + 4) = param_1;
  return;
}



// Function: ~IncValueT<short,3> at 10009d90

/* public: virtual __thiscall IncValueT<short,3>::~IncValueT<short,3>(void) */

void __thiscall IncValueT<short,3>::~IncValueT<short,3>(IncValueT<short,3> *this)

{
                    /* 0x9d90  35  ??1?$IncValueT@F$02@@UAE@XZ */
  *(undefined ***)this = vftable;
  *(undefined ***)this = ValueBase::vftable;
  return;
}



// Function: getType at 10009de0

/* public: virtual enum VBType __thiscall IncValueT<short,3>::getType(void)const  */

VBType __thiscall IncValueT<short,3>::getType(IncValueT<short,3> *this)

{
                    /* 0x9de0  166  ?getType@?$IncValueT@F$02@@UBE?AW4VBType@@XZ */
  return 3;
}



// Function: operator++ at 10009df0

/* public: virtual void __thiscall IncValueT<short,3>::operator++(void) */

void __thiscall IncValueT<short,3>::operator++(IncValueT<short,3> *this)

{
                    /* 0x9df0  78  ??E?$IncValueT@F$02@@UAEXXZ
                       0x9df0  79  ??E?$IncValueT@G$01@@UAEXXZ */
  *(short *)(this + 4) = *(short *)(this + 4) + 1;
  return;
}



// Function: operator-- at 10009e00

/* public: virtual void __thiscall IncValueT<short,3>::operator--(void) */

void __thiscall IncValueT<short,3>::operator--(IncValueT<short,3> *this)

{
                    /* 0x9e00  85  ??F?$IncValueT@F$02@@UAEXXZ */
  *(short *)(this + 4) = *(short *)(this + 4) + -1;
  return;
}



// Function: operator== at 10009e10

/* public: virtual int __thiscall IncValueT<short,3>::operator==(class ValueBase const &)const  */

int __thiscall IncValueT<short,3>::operator==(IncValueT<short,3> *this,ValueBase *param_1)

{
                    /* 0x9e10  69  ??8?$IncValueT@F$02@@UBEHABVValueBase@@@Z
                       0x9e10  70  ??8?$IncValueT@G$01@@UBEHABVValueBase@@@Z */
  return (uint)(*(short *)(this + 4) == *(short *)(param_1 + 4));
}



// Function: operator< at 10009e30

/* public: virtual int __thiscall IncValueT<short,3>::operator<(class ValueBase const &)const  */

int __thiscall IncValueT<short,3>::operator<(IncValueT<short,3> *this,ValueBase *param_1)

{
                    /* 0x9e30  92  ??M?$IncValueT@F$02@@UBEHABVValueBase@@@Z */
  return (uint)(*(short *)(this + 4) < *(short *)(param_1 + 4));
}



// Function: operator<= at 10009e50

/* public: virtual int __thiscall IncValueT<short,3>::operator<=(class ValueBase const &)const  */

int __thiscall IncValueT<short,3>::operator<=(IncValueT<short,3> *this,ValueBase *param_1)

{
                    /* 0x9e50  99  ??N?$IncValueT@F$02@@UBEHABVValueBase@@@Z */
  return (uint)(*(short *)(this + 4) <= *(short *)(param_1 + 4));
}



// Function: IncValueT<unsigned_long,4> at 10009e70

/* public: __thiscall IncValueT<unsigned long,4>::IncValueT<unsigned long,4>(unsigned long) */

void __thiscall
IncValueT<unsigned_long,4>::IncValueT<unsigned_long,4>
          (IncValueT<unsigned_long,4> *this,ulong param_1)

{
                    /* 0x9e70  12  ??0?$IncValueT@K$03@@QAE@K@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(ulong *)(this + 4) = param_1;
  return;
}



// Function: ~IncValueT<unsigned_long,4> at 10009ed0

/* public: virtual __thiscall IncValueT<unsigned long,4>::~IncValueT<unsigned long,4>(void) */

void __thiscall
IncValueT<unsigned_long,4>::~IncValueT<unsigned_long,4>(IncValueT<unsigned_long,4> *this)

{
                    /* 0x9ed0  38  ??1?$IncValueT@K$03@@UAE@XZ */
  *(undefined ***)this = vftable;
  *(undefined ***)this = ValueBase::vftable;
  return;
}



// Function: getType at 10009f20

/* public: virtual enum VBType __thiscall IncValueT<unsigned long,4>::getType(void)const  */

VBType __thiscall IncValueT<unsigned_long,4>::getType(IncValueT<unsigned_long,4> *this)

{
                    /* 0x9f20  169  ?getType@?$IncValueT@K$03@@UBE?AW4VBType@@XZ */
  return 4;
}



// Function: operator++ at 10009f30

/* public: virtual void __thiscall IncValueT<long,5>::operator++(void) */

void __thiscall IncValueT<long,5>::operator++(IncValueT<long,5> *this)

{
                    /* 0x9f30  80  ??E?$IncValueT@J$04@@UAEXXZ
                       0x9f30  81  ??E?$IncValueT@K$03@@UAEXXZ */
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return;
}



// Function: operator< at 10009f40

/* public: virtual int __thiscall IncValueT<unsigned long,4>::operator<(class ValueBase const
   &)const  */

int __thiscall
IncValueT<unsigned_long,4>::operator<(IncValueT<unsigned_long,4> *this,ValueBase *param_1)

{
                    /* 0x9f40  95  ??M?$IncValueT@K$03@@UBEHABVValueBase@@@Z */
  return (uint)(*(uint *)(this + 4) < *(uint *)(param_1 + 4));
}



// Function: operator<= at 10009f60

/* public: virtual int __thiscall IncValueT<unsigned long,4>::operator<=(class ValueBase const
   &)const  */

int __thiscall
IncValueT<unsigned_long,4>::operator<=(IncValueT<unsigned_long,4> *this,ValueBase *param_1)

{
                    /* 0x9f60  102  ??N?$IncValueT@K$03@@UBEHABVValueBase@@@Z */
  return (uint)(*(uint *)(this + 4) <= *(uint *)(param_1 + 4));
}



// Function: NonIncValueT<class_iclString,6> at 10009f80

/* public: __thiscall NonIncValueT<class iclString,6>::NonIncValueT<class iclString,6>(class
   iclString) */

NonIncValueT<class_iclString,6> * __thiscall
NonIncValueT<class_iclString,6>::NonIncValueT<class_iclString,6>
          (NonIncValueT<class_iclString,6> *this,int *param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x9f80  14  ??0?$NonIncValueT@ViclString@@$05@@QAE@ViclString@@@Z */
  puStack_c = &LAB_1000d94b;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ValueBase::vftable;
  local_8 = 1;
  *(undefined ***)this = vftable;
  *(int **)(this + 4) = param_2;
  (**(code **)(*param_2 + 4))(uVar1);
  local_8 = 0xffffffff;
  FUN_10004ab0(&param_2);
  ExceptionList = local_10;
  return this;
}



// Function: ~NonIncValueT<class_iclString,6> at 10009ff0

/* public: virtual __thiscall NonIncValueT<class iclString,6>::~NonIncValueT<class
   iclString,6>(void) */

void __thiscall
NonIncValueT<class_iclString,6>::~NonIncValueT<class_iclString,6>
          (NonIncValueT<class_iclString,6> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x9ff0  39  ??1?$NonIncValueT@ViclString@@$05@@UAE@XZ */
  puStack_c = &LAB_1000d9b3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = vftable;
  local_8 = 0;
  FUN_10004ab0((undefined4 *)(this + 4));
  *(undefined ***)this = ValueBase::vftable;
  ExceptionList = local_10;
  return;
}



// Function: getType at 1000a050

/* public: virtual enum VBType __thiscall NonIncValueT<class iclString,6>::getType(void)const  */

VBType __thiscall NonIncValueT<class_iclString,6>::getType(NonIncValueT<class_iclString,6> *this)

{
                    /* 0xa050  170  ?getType@?$NonIncValueT@ViclString@@$05@@UBE?AW4VBType@@XZ */
  return 6;
}



// Function: operator== at 1000a060

/* public: virtual int __thiscall NonIncValueT<class iclString,6>::operator==(class ValueBase const
   &)const  */

int __thiscall
NonIncValueT<class_iclString,6>::operator==
          (NonIncValueT<class_iclString,6> *this,ValueBase *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0xa060  73  ??8?$NonIncValueT@ViclString@@$05@@UBEHABVValueBase@@@Z */
  bVar1 = FUN_10009880(this + 4,(int *)(param_1 + 4));
  return CONCAT31(extraout_var,bVar1);
}



// Function: operator< at 1000a080

/* public: virtual int __thiscall NonIncValueT<class iclString,6>::operator<(class ValueBase const
   &)const  */

int __thiscall
NonIncValueT<class_iclString,6>::operator<(NonIncValueT<class_iclString,6> *this,ValueBase *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0xa080  96  ??M?$NonIncValueT@ViclString@@$05@@UBEHABVValueBase@@@Z */
  bVar1 = FUN_100098f0(this + 4,(int *)(param_1 + 4));
  return CONCAT31(extraout_var,bVar1);
}



// Function: operator<= at 1000a0a0

/* public: virtual int __thiscall NonIncValueT<class iclString,6>::operator<=(class ValueBase const
   &)const  */

int __thiscall
NonIncValueT<class_iclString,6>::operator<=
          (NonIncValueT<class_iclString,6> *this,ValueBase *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
                    /* 0xa0a0  103  ??N?$NonIncValueT@ViclString@@$05@@UBEHABVValueBase@@@Z */
  bVar1 = FUN_10009960(this + 4,(int *)(param_1 + 4));
  return CONCAT31(extraout_var,bVar1);
}



// Function: IncValueT<unsigned_char,0> at 1000a0c0

/* public: __thiscall IncValueT<unsigned char,0>::IncValueT<unsigned char,0>(class
   IncValueT<unsigned char,0> const &) */

void __thiscall
IncValueT<unsigned_char,0>::IncValueT<unsigned_char,0>
          (IncValueT<unsigned_char,0> *this,IncValueT<unsigned_char,0> *param_1)

{
                    /* 0xa0c0  3  ??0?$IncValueT@E$0A@@@QAE@ABV0@@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  this[4] = param_1[4];
  return;
}



// Function: IncValueT<signed_char,1> at 1000a120

/* public: __thiscall IncValueT<signed char,1>::IncValueT<signed char,1>(class IncValueT<signed
   char,1> const &) */

void __thiscall
IncValueT<signed_char,1>::IncValueT<signed_char,1>
          (IncValueT<signed_char,1> *this,IncValueT<signed_char,1> *param_1)

{
                    /* 0xa120  1  ??0?$IncValueT@C$00@@QAE@ABV0@@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  this[4] = param_1[4];
  return;
}



// Function: IncValueT<unsigned_short,2> at 1000a180

/* public: __thiscall IncValueT<unsigned short,2>::IncValueT<unsigned short,2>(class
   IncValueT<unsigned short,2> const &) */

void __thiscall
IncValueT<unsigned_short,2>::IncValueT<unsigned_short,2>
          (IncValueT<unsigned_short,2> *this,IncValueT<unsigned_short,2> *param_1)

{
                    /* 0xa180  7  ??0?$IncValueT@G$01@@QAE@ABV0@@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined2 *)(this + 4) = *(undefined2 *)(param_1 + 4);
  return;
}



// Function: IncValueT<short,3> at 1000a1e0

/* public: __thiscall IncValueT<short,3>::IncValueT<short,3>(class IncValueT<short,3> const &) */

void __thiscall
IncValueT<short,3>::IncValueT<short,3>(IncValueT<short,3> *this,IncValueT<short,3> *param_1)

{
                    /* 0xa1e0  5  ??0?$IncValueT@F$02@@QAE@ABV0@@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined2 *)(this + 4) = *(undefined2 *)(param_1 + 4);
  return;
}



// Function: IncValueT<unsigned_long,4> at 1000a240

/* public: __thiscall IncValueT<unsigned long,4>::IncValueT<unsigned long,4>(class
   IncValueT<unsigned long,4> const &) */

void __thiscall
IncValueT<unsigned_long,4>::IncValueT<unsigned_long,4>
          (IncValueT<unsigned_long,4> *this,IncValueT<unsigned_long,4> *param_1)

{
                    /* 0xa240  11  ??0?$IncValueT@K$03@@QAE@ABV0@@Z */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return;
}



// Function: NonIncValueT<class_iclString,6> at 1000a2a0

/* public: __thiscall NonIncValueT<class iclString,6>::NonIncValueT<class iclString,6>(class
   NonIncValueT<class iclString,6> const &) */

NonIncValueT<class_iclString,6> * __thiscall
NonIncValueT<class_iclString,6>::NonIncValueT<class_iclString,6>
          (NonIncValueT<class_iclString,6> *this,NonIncValueT<class_iclString,6> *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xa2a0  13  ??0?$NonIncValueT@ViclString@@$05@@QAE@ABV0@@Z */
  puStack_c = &LAB_1000d9b3;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ValueBase::vftable;
  local_8 = 0;
  *(undefined ***)this = vftable;
  piVar1 = *(int **)(param_1 + 4);
  *(int **)(this + 4) = piVar1;
  (**(code **)(*piVar1 + 4))(uVar2);
  ExceptionList = local_10;
  return this;
}



// Function: `default_constructor_closure' at 1000a310

/* public: void __thiscall IncValueT<unsigned char,0>::`default constructor closure'(void) */

void __thiscall
IncValueT<unsigned_char,0>::_default_constructor_closure_(IncValueT<unsigned_char,0> *this)

{
                    /* 0xa310  123  ??_F?$IncValueT@E$0A@@@QAEXXZ */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  this[4] = (IncValueT<unsigned_char,0>)0x0;
  return;
}



// Function: FUN_1000a360 at 1000a360

undefined4 * __thiscall FUN_1000a360(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (this,5,*(int *)((int)this + -4),
               IncValueT<unsigned_char,0>::~IncValueT<unsigned_char,0>);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    ExceptionList = local_10;
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = IncValueT<unsigned_char,0>::vftable;
  local_8 = 0xffffffff;
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: `default_constructor_closure' at 1000a410

/* public: void __thiscall IncValueT<signed char,1>::`default constructor closure'(void) */

void __thiscall
IncValueT<signed_char,1>::_default_constructor_closure_(IncValueT<signed_char,1> *this)

{
                    /* 0xa410  122  ??_F?$IncValueT@C$00@@QAEXXZ */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  this[4] = (IncValueT<signed_char,1>)0x0;
  return;
}



// Function: FUN_1000a460 at 1000a460

undefined4 * __thiscall FUN_1000a460(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (this,5,*(int *)((int)this + -4),IncValueT<signed_char,1>::~IncValueT<signed_char,1>);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    ExceptionList = local_10;
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = IncValueT<signed_char,1>::vftable;
  local_8 = 0xffffffff;
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: `default_constructor_closure' at 1000a510

/* public: void __thiscall IncValueT<unsigned short,2>::`default constructor closure'(void) */

void __thiscall
IncValueT<unsigned_short,2>::_default_constructor_closure_(IncValueT<unsigned_short,2> *this)

{
                    /* 0xa510  125  ??_F?$IncValueT@G$01@@QAEXXZ */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined2 *)(this + 4) = 0;
  return;
}



// Function: FUN_1000a570 at 1000a570

undefined4 * __thiscall FUN_1000a570(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (this,6,*(int *)((int)this + -4),
               IncValueT<unsigned_short,2>::~IncValueT<unsigned_short,2>);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    ExceptionList = local_10;
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = IncValueT<unsigned_short,2>::vftable;
  local_8 = 0xffffffff;
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: `default_constructor_closure' at 1000a620

/* public: void __thiscall IncValueT<short,3>::`default constructor closure'(void) */

void __thiscall IncValueT<short,3>::_default_constructor_closure_(IncValueT<short,3> *this)

{
                    /* 0xa620  124  ??_F?$IncValueT@F$02@@QAEXXZ */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined2 *)(this + 4) = 0;
  return;
}



// Function: FUN_1000a680 at 1000a680

undefined4 * __thiscall FUN_1000a680(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (this,6,*(int *)((int)this + -4),IncValueT<short,3>::~IncValueT<short,3>);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    ExceptionList = local_10;
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = IncValueT<short,3>::vftable;
  local_8 = 0xffffffff;
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: `default_constructor_closure' at 1000a730

/* public: void __thiscall IncValueT<unsigned long,4>::`default constructor closure'(void) */

void __thiscall
IncValueT<unsigned_long,4>::_default_constructor_closure_(IncValueT<unsigned_long,4> *this)

{
                    /* 0xa730  127  ??_F?$IncValueT@K$03@@QAEXXZ */
  *(undefined ***)this = ValueBase::vftable;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  return;
}



// Function: FUN_1000a780 at 1000a780

undefined4 * __thiscall FUN_1000a780(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (this,8,*(int *)((int)this + -4),
               IncValueT<unsigned_long,4>::~IncValueT<unsigned_long,4>);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    ExceptionList = local_10;
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = IncValueT<unsigned_long,4>::vftable;
  local_8 = 0xffffffff;
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: `default_constructor_closure' at 1000a830

/* public: void __thiscall NonIncValueT<class iclString,6>::`default constructor closure'(void) */

void __thiscall
NonIncValueT<class_iclString,6>::_default_constructor_closure_
          (NonIncValueT<class_iclString,6> *this)

{
  uint uVar1;
  void *this_00;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xa830  128  ??_F?$NonIncValueT@ViclString@@$05@@QAEXXZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000da26;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this_00 = operator_new(0x16);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    local_14 = FUN_100014b0(this_00,0);
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(uVar1);
  }
  FUN_10004ac0(&local_14,(char *)0x0,0xffff);
  *(undefined ***)this = ValueBase::vftable;
  local_8 = 2;
  *(undefined ***)this = vftable;
  *(int **)(this + 4) = local_14;
  (**(code **)(*local_14 + 4))();
  local_8 = 0xffffffff;
  FUN_10004ab0(&local_14);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000a8f0 at 1000a8f0

undefined4 * __thiscall FUN_1000a8f0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000da63;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    _eh_vector_destructor_iterator_
              (this,8,*(int *)((int)this + -4),
               NonIncValueT<class_iclString,6>::~NonIncValueT<class_iclString,6>);
    if ((param_1 & 1) != 0) {
      operator_delete__((undefined4 *)((int)this + -4));
    }
    ExceptionList = local_10;
    return (undefined4 *)((int)this + -4);
  }
  *(undefined ***)this = NonIncValueT<class_iclString,6>::vftable;
  local_8 = 0;
  FUN_10004ab0((undefined4 *)((int)this + 4));
  local_8 = 0xffffffff;
  *(undefined ***)this = ValueBase::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: copy at 1000a9b0

/* public: virtual class ValueBase * __thiscall IncValueT<unsigned char,0>::copy(void)const  */

ValueBase * __thiscall IncValueT<unsigned_char,0>::copy(IncValueT<unsigned_char,0> *this)

{
  ValueBase *pVVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xa9b0  134  ?copy@?$IncValueT@E$0A@@@UBEPAVValueBase@@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d173;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pVVar1 = (ValueBase *)operator_new(5);
  if (pVVar1 == (ValueBase *)0x0) {
    pVVar1 = (ValueBase *)0x0;
  }
  else {
    *(undefined ***)pVVar1 = ValueBase::vftable;
    *(undefined ***)pVVar1 = vftable;
    pVVar1[4] = *(ValueBase *)(this + 4);
  }
  ExceptionList = local_10;
  return pVVar1;
}



// Function: copy at 1000aa20

/* public: virtual class ValueBase * __thiscall IncValueT<signed char,1>::copy(void)const  */

ValueBase * __thiscall IncValueT<signed_char,1>::copy(IncValueT<signed_char,1> *this)

{
  ValueBase *pVVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xaa20  133  ?copy@?$IncValueT@C$00@@UBEPAVValueBase@@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d173;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pVVar1 = (ValueBase *)operator_new(5);
  if (pVVar1 == (ValueBase *)0x0) {
    pVVar1 = (ValueBase *)0x0;
  }
  else {
    *(undefined ***)pVVar1 = ValueBase::vftable;
    *(undefined ***)pVVar1 = vftable;
    pVVar1[4] = *(ValueBase *)(this + 4);
  }
  ExceptionList = local_10;
  return pVVar1;
}



// Function: copy at 1000aa90

/* public: virtual class ValueBase * __thiscall IncValueT<unsigned short,2>::copy(void)const  */

ValueBase * __thiscall IncValueT<unsigned_short,2>::copy(IncValueT<unsigned_short,2> *this)

{
  ValueBase *pVVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xaa90  136  ?copy@?$IncValueT@G$01@@UBEPAVValueBase@@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d173;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pVVar1 = (ValueBase *)operator_new(6);
  if (pVVar1 == (ValueBase *)0x0) {
    pVVar1 = (ValueBase *)0x0;
  }
  else {
    *(undefined ***)pVVar1 = ValueBase::vftable;
    *(undefined ***)pVVar1 = vftable;
    *(undefined2 *)(pVVar1 + 4) = *(undefined2 *)(this + 4);
  }
  ExceptionList = local_10;
  return pVVar1;
}



// Function: copy at 1000ab10

/* public: virtual class ValueBase * __thiscall IncValueT<short,3>::copy(void)const  */

ValueBase * __thiscall IncValueT<short,3>::copy(IncValueT<short,3> *this)

{
  ValueBase *pVVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xab10  135  ?copy@?$IncValueT@F$02@@UBEPAVValueBase@@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d173;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pVVar1 = (ValueBase *)operator_new(6);
  if (pVVar1 == (ValueBase *)0x0) {
    pVVar1 = (ValueBase *)0x0;
  }
  else {
    *(undefined ***)pVVar1 = ValueBase::vftable;
    *(undefined ***)pVVar1 = vftable;
    *(undefined2 *)(pVVar1 + 4) = *(undefined2 *)(this + 4);
  }
  ExceptionList = local_10;
  return pVVar1;
}



// Function: copy at 1000ab90

/* public: virtual class ValueBase * __thiscall IncValueT<unsigned long,4>::copy(void)const  */

ValueBase * __thiscall IncValueT<unsigned_long,4>::copy(IncValueT<unsigned_long,4> *this)

{
  ValueBase *pVVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xab90  138  ?copy@?$IncValueT@K$03@@UBEPAVValueBase@@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d173;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pVVar1 = (ValueBase *)operator_new(8);
  if (pVVar1 == (ValueBase *)0x0) {
    pVVar1 = (ValueBase *)0x0;
  }
  else {
    *(undefined ***)pVVar1 = ValueBase::vftable;
    *(undefined ***)pVVar1 = vftable;
    *(undefined4 *)(pVVar1 + 4) = *(undefined4 *)(this + 4);
  }
  ExceptionList = local_10;
  return pVVar1;
}



// Function: copy at 1000ac00

/* public: virtual class ValueBase * __thiscall NonIncValueT<class iclString,6>::copy(void)const  */

ValueBase * __thiscall NonIncValueT<class_iclString,6>::copy(NonIncValueT<class_iclString,6> *this)

{
  int *piVar1;
  uint uVar2;
  ValueBase *pVVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xac00  139  ?copy@?$NonIncValueT@ViclString@@$05@@UBEPAVValueBase@@XZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000da9e;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pVVar3 = (ValueBase *)operator_new(8);
  if (pVVar3 != (ValueBase *)0x0) {
    *(undefined ***)pVVar3 = ValueBase::vftable;
    local_8 = 1;
    *(undefined ***)pVVar3 = vftable;
    piVar1 = *(int **)(this + 4);
    *(int **)(pVVar3 + 4) = piVar1;
    (**(code **)(*piVar1 + 4))(uVar2);
    ExceptionList = local_10;
    return pVVar3;
  }
  ExceptionList = local_10;
  return (ValueBase *)0x0;
}



// Function: FUN_1000aca0 at 1000aca0

void __thiscall FUN_1000aca0(void *this,uint param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  code *pcVar5;
  code *pcVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000db0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined4 *)((int)this + 4)) {
  case 0:
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar4 = (uint *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[-1] == 0) {
        operator_delete__(puVar1 + -1);
      }
      else {
        (**(code **)*puVar1)(3);
      }
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (param_1 == 0) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = -(uint)((int)((ulonglong)param_1 * 5 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 5);
    puVar2 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_8 = 0;
    if (puVar2 != (uint *)0x0) {
      pcVar6 = IncValueT<unsigned_char,0>::~IncValueT<unsigned_char,0>;
      pcVar5 = IncValueT<unsigned_char,0>::_default_constructor_closure_;
      uVar3 = 5;
LAB_1000b02b:
      puVar4 = puVar2 + 1;
      *puVar2 = param_1;
      _eh_vector_constructor_iterator_(puVar4,uVar3,param_1,pcVar5,pcVar6);
    }
    break;
  case 1:
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar4 = (uint *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[-1] == 0) {
        operator_delete__(puVar1 + -1);
      }
      else {
        (**(code **)*puVar1)(3);
      }
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (param_1 == 0) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = -(uint)((int)((ulonglong)param_1 * 5 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 5);
    puVar2 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_8 = 1;
    if (puVar2 != (uint *)0x0) {
      pcVar6 = IncValueT<signed_char,1>::~IncValueT<signed_char,1>;
      pcVar5 = IncValueT<signed_char,1>::_default_constructor_closure_;
      uVar3 = 5;
      goto LAB_1000b02b;
    }
    break;
  case 2:
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar4 = (uint *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[-1] == 0) {
        operator_delete__(puVar1 + -1);
      }
      else {
        (**(code **)*puVar1)(3);
      }
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (param_1 == 0) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = -(uint)((int)((ulonglong)param_1 * 6 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 6);
    puVar2 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_8 = 2;
    if (puVar2 != (uint *)0x0) {
      pcVar6 = IncValueT<unsigned_short,2>::~IncValueT<unsigned_short,2>;
      pcVar5 = IncValueT<unsigned_short,2>::_default_constructor_closure_;
      uVar3 = 6;
      goto LAB_1000b02b;
    }
    break;
  case 3:
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar4 = (uint *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[-1] == 0) {
        operator_delete__(puVar1 + -1);
      }
      else {
        (**(code **)*puVar1)(3);
      }
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (param_1 == 0) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = -(uint)((int)((ulonglong)param_1 * 6 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 6);
    puVar2 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_8 = 3;
    if (puVar2 != (uint *)0x0) {
      pcVar6 = IncValueT<short,3>::~IncValueT<short,3>;
      pcVar5 = IncValueT<short,3>::_default_constructor_closure_;
      uVar3 = 6;
      goto LAB_1000b02b;
    }
    break;
  case 4:
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar4 = (uint *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[-1] == 0) {
        operator_delete__(puVar1 + -1);
      }
      else {
        (**(code **)*puVar1)(3);
      }
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (param_1 == 0) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = -(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 8);
    puVar2 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_8 = 4;
    if (puVar2 != (uint *)0x0) {
      pcVar6 = IncValueT<unsigned_long,4>::~IncValueT<unsigned_long,4>;
      pcVar5 = IncValueT<unsigned_long,4>::_default_constructor_closure_;
LAB_1000b028:
      uVar3 = 8;
      goto LAB_1000b02b;
    }
    break;
  case 5:
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar4 = (uint *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[-1] == 0) {
        operator_delete__(puVar1 + -1);
      }
      else {
        (**(code **)*puVar1)(3);
      }
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (param_1 == 0) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = -(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 8);
    puVar2 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_8 = 5;
    if (puVar2 != (uint *)0x0) {
      pcVar6 = IncValueT<long,5>::~IncValueT<long,5>;
      pcVar5 = IncValueT<long,5>::_default_constructor_closure_;
      goto LAB_1000b028;
    }
    break;
  case 6:
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar4 = (uint *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      if (puVar1[-1] == 0) {
        operator_delete__(puVar1 + -1);
      }
      else {
        (**(code **)*puVar1)(3,DAT_1001498c ^ (uint)&stack0xfffffffc);
      }
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (param_1 == 0) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = -(uint)((int)((ulonglong)param_1 * 8 >> 0x20) != 0) | (uint)((ulonglong)param_1 * 8);
    puVar2 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    local_8 = 6;
    if (puVar2 != (uint *)0x0) {
      pcVar6 = NonIncValueT<class_iclString,6>::~NonIncValueT<class_iclString,6>;
      pcVar5 = NonIncValueT<class_iclString,6>::_default_constructor_closure_;
      goto LAB_1000b028;
    }
    break;
  default:
    goto switchD_1000acd3_default;
  }
  *(uint **)((int)this + 8) = puVar4;
switchD_1000acd3_default:
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b070 at 1000b070

undefined4 * __thiscall FUN_1000b070(void *this,undefined4 param_1,uint param_2)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined ***)this = ValueArray::vftable;
  *(undefined4 *)((int)this + 8) = 0;
  if (param_2 != 0) {
    FUN_1000aca0(this,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b0a0 at 1000b0a0

void __fastcall FUN_1000b0a0(undefined4 *param_1)

{
  *param_1 = ValueArray::vftable;
  FUN_1000aca0(param_1,0);
  return;
}



// Function: FUN_1000b0b0 at 1000b0b0

undefined4 * __thiscall FUN_1000b0b0(void *this,byte param_1)

{
  FUN_1000b0a0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b0e0 at 1000b0e0

undefined4 * __thiscall FUN_1000b0e0(void *this,int param_1,ushort param_2,uint param_3)

{
  uint uVar1;
  void *this_00;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c85b;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this_00 = operator_new(0x16);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_100014b0(this_00,0);
  }
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(uVar1);
  }
  if (param_1 != 0) {
    FUN_10004ac0(this,(char *)((uint)param_2 + param_1),param_3);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: dataSize at 1000b170

/* public: static unsigned int __cdecl ValueBase::dataSize(enum VBType) */

uint __cdecl ValueBase::dataSize(VBType param_1)

{
  uint uVar1;
  
                    /* 0xb170  141  ?dataSize@ValueBase@@SAIW4VBType@@@Z */
  uVar1 = 0;
  switch(param_1) {
  case 0:
  case 1:
    return 5;
  case 2:
  case 3:
    return 6;
  case 4:
  case 5:
  case 6:
    uVar1 = 8;
  }
  return uVar1;
}



// Function: operator= at 1000b1c0

/* public: class IncValueT<signed char,1> const & __thiscall IncValueT<signed
   char,1>::operator=(class IncValueT<signed char,1> const &) */

IncValueT<signed_char,1> * __thiscall
IncValueT<signed_char,1>::operator=
          (IncValueT<signed_char,1> *this,IncValueT<signed_char,1> *param_1)

{
                    /* 0xb1c0  45  ??4?$IncValueT@C$00@@QAEABV0@ABV0@@Z
                       0xb1c0  46  ??4?$IncValueT@C$00@@UAEABVValueBase@@ABV1@@Z
                       0xb1c0  47  ??4?$IncValueT@E$0A@@@QAEABV0@ABV0@@Z
                       0xb1c0  48  ??4?$IncValueT@E$0A@@@UAEABVValueBase@@ABV1@@Z */
  this[4] = param_1[4];
  return this;
}



// Function: operator= at 1000b1e0

/* public: class IncValueT<short,3> const & __thiscall IncValueT<short,3>::operator=(class
   IncValueT<short,3> const &) */

IncValueT<short,3> * __thiscall
IncValueT<short,3>::operator=(IncValueT<short,3> *this,IncValueT<short,3> *param_1)

{
                    /* 0xb1e0  49  ??4?$IncValueT@F$02@@QAEABV0@ABV0@@Z
                       0xb1e0  50  ??4?$IncValueT@F$02@@UAEABVValueBase@@ABV1@@Z
                       0xb1e0  51  ??4?$IncValueT@G$01@@QAEABV0@ABV0@@Z
                       0xb1e0  52  ??4?$IncValueT@G$01@@UAEABVValueBase@@ABV1@@Z */
  *(undefined2 *)(this + 4) = *(undefined2 *)(param_1 + 4);
  return this;
}



// Function: operator= at 1000b200

/* public: class NonIncValueT<class iclString,6> const & __thiscall NonIncValueT<class
   iclString,6>::operator=(class NonIncValueT<class iclString,6> const &) */

NonIncValueT<class_iclString,6> * __thiscall
NonIncValueT<class_iclString,6>::operator=
          (NonIncValueT<class_iclString,6> *this,NonIncValueT<class_iclString,6> *param_1)

{
                    /* 0xb200  57  ??4?$NonIncValueT@ViclString@@$05@@QAEABV0@ABV0@@Z
                       0xb200  58  ??4?$NonIncValueT@ViclString@@$05@@UAEABVValueBase@@ABV1@@Z */
  FUN_10004bc0(this + 4,(undefined4 *)(param_1 + 4));
  return this;
}



// Function: create at 1000b220

/* public: static class ValueBase * __cdecl ValueBase::create(enum VBType,char const *,int) */

ValueBase * __cdecl ValueBase::create(VBType param_1,char *param_2,int param_3)

{
  IncValueT<unsigned_char,0> *this;
  IncValueT<signed_char,1> *this_00;
  IncValueT<unsigned_short,2> *this_01;
  IncValueT<short,3> *this_02;
  int iVar1;
  IncValueT<unsigned_long,4> *this_03;
  ulong uVar2;
  IncValueT<long,5> *this_04;
  long lVar3;
  NonIncValueT<class_iclString,6> *pNVar4;
  ValueBase *pVVar5;
  undefined **_Str;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xb220  140  ?create@ValueBase@@SAPAV1@W4VBType@@PBDH@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000db98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _Str = (undefined **)param_2;
  if (param_2 == (char *)0x0) {
    _Str = &PTR_1000e1a4;
    param_3 = 0;
  }
  switch(param_1) {
  case 0:
    this = (IncValueT<unsigned_char,0> *)operator_new(5);
    local_8 = 0;
    if (this != (IncValueT<unsigned_char,0> *)0x0) {
      pVVar5 = (ValueBase *)
               IncValueT<unsigned_char,0>::IncValueT<unsigned_char,0>(this,*(uchar *)_Str);
      ExceptionList = local_10;
      return pVVar5;
    }
    break;
  case 1:
    this_00 = (IncValueT<signed_char,1> *)operator_new(5);
    local_8 = 1;
    if (this_00 != (IncValueT<signed_char,1> *)0x0) {
      pVVar5 = (ValueBase *)
               IncValueT<signed_char,1>::IncValueT<signed_char,1>(this_00,*(uchar *)_Str);
      ExceptionList = local_10;
      return pVVar5;
    }
    break;
  case 2:
    this_01 = (IncValueT<unsigned_short,2> *)operator_new(6);
    local_8 = 2;
    if (this_01 != (IncValueT<unsigned_short,2> *)0x0) {
      iVar1 = atoi((char *)_Str);
      pVVar5 = (ValueBase *)
               IncValueT<unsigned_short,2>::IncValueT<unsigned_short,2>(this_01,(ushort)iVar1);
      ExceptionList = local_10;
      return pVVar5;
    }
    break;
  case 3:
    this_02 = (IncValueT<short,3> *)operator_new(6);
    local_8 = 3;
    if (this_02 != (IncValueT<short,3> *)0x0) {
      iVar1 = atoi((char *)_Str);
      pVVar5 = (ValueBase *)IncValueT<short,3>::IncValueT<short,3>(this_02,(short)iVar1);
      ExceptionList = local_10;
      return pVVar5;
    }
    break;
  case 4:
    this_03 = (IncValueT<unsigned_long,4> *)operator_new(8);
    local_8 = 4;
    if (this_03 != (IncValueT<unsigned_long,4> *)0x0) {
      uVar2 = atol((char *)_Str);
      pVVar5 = (ValueBase *)IncValueT<unsigned_long,4>::IncValueT<unsigned_long,4>(this_03,uVar2);
      ExceptionList = local_10;
      return pVVar5;
    }
    break;
  case 5:
    this_04 = (IncValueT<long,5> *)operator_new(8);
    local_8 = 5;
    if (this_04 != (IncValueT<long,5> *)0x0) {
      lVar3 = atol((char *)_Str);
      pVVar5 = (ValueBase *)IncValueT<long,5>::IncValueT<long,5>(this_04,lVar3);
      ExceptionList = local_10;
      return pVVar5;
    }
    break;
  case 6:
    pNVar4 = (NonIncValueT<class_iclString,6> *)operator_new(8);
    if (param_3 == 0xffffffff) {
      local_8 = 6;
      if (pNVar4 != (NonIncValueT<class_iclString,6> *)0x0) {
        FUN_10001540(&stack0xffffffdc,(char *)_Str);
        local_8 = CONCAT31((int3)((uint)local_8 >> 8),6);
        pVVar5 = (ValueBase *)
                 NonIncValueT<class_iclString,6>::NonIncValueT<class_iclString,6>(pNVar4);
        ExceptionList = local_10;
        return pVVar5;
      }
    }
    else {
      local_8 = 8;
      if (pNVar4 != (NonIncValueT<class_iclString,6> *)0x0) {
        FUN_1000b0e0(&stack0xffffffdc,(int)_Str,0,param_3);
        local_8 = CONCAT31((int3)((uint)local_8 >> 8),8);
        pVVar5 = (ValueBase *)
                 NonIncValueT<class_iclString,6>::NonIncValueT<class_iclString,6>(pNVar4);
        ExceptionList = local_10;
        return pVVar5;
      }
    }
  }
  ExceptionList = local_10;
  return (ValueBase *)0x0;
}



// Function: set at 1000b430

/* public: static enum ICLStatus __cdecl ValueBase::set(class ValueBase &,char const *,int) */

ICLStatus __cdecl ValueBase::set(ValueBase *param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  NonIncValueT<class_iclString,6> local_2c [4];
  undefined4 local_28;
  NonIncValueT<class_iclString,6> local_24 [4];
  undefined4 local_20 [3];
  ICLStatus local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0xb430  180  ?set@ValueBase@@SA?AW4ICLStatus@@AAV1@PBDH@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dc70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  if (param_2 == (char *)0x0) {
    param_3 = 0;
    param_2 = (char *)&PTR_1000e1a4;
  }
  uVar1 = (**(code **)(*(int *)param_1 + 4))();
  switch(uVar1) {
  case 0:
    param_1[4] = (ValueBase)*param_2;
    break;
  case 1:
    param_1[4] = (ValueBase)*param_2;
    break;
  case 2:
    iVar2 = atoi(param_2);
    *(short *)(param_1 + 4) = (short)iVar2;
    break;
  case 3:
    iVar2 = atoi(param_2);
    *(short *)(param_1 + 4) = (short)iVar2;
    break;
  case 4:
    lVar3 = atol(param_2);
    *(long *)(param_1 + 4) = lVar3;
    break;
  case 5:
    lVar3 = atol(param_2);
    *(long *)(param_1 + 4) = lVar3;
    break;
  case 6:
    if (param_3 == -1) {
      FUN_10001540(&stack0xffffffc0,param_2);
      local_8 = 0xffffffff;
      NonIncValueT<class_iclString,6>::NonIncValueT<class_iclString,6>(local_24);
      local_8 = 0x13;
      FUN_10004bc0(param_1 + 4,local_20);
      local_8 = 0xffffffff;
      NonIncValueT<class_iclString,6>::~NonIncValueT<class_iclString,6>(local_24);
    }
    else {
      FUN_1000b0e0(&stack0xffffffc0,(int)param_2,0,param_3);
      local_8 = 0xffffffff;
      NonIncValueT<class_iclString,6>::NonIncValueT<class_iclString,6>(local_2c);
      local_8 = 0x15;
      FUN_10004bc0(param_1 + 4,&local_28);
      local_8 = 0xffffffff;
      NonIncValueT<class_iclString,6>::~NonIncValueT<class_iclString,6>(local_2c);
    }
    break;
  default:
    local_14 = 5;
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000b6d0 at 1000b6d0

void __thiscall FUN_1000b6d0(void *this,int param_1)

{
  FUN_10003110(this,param_1);
  if (*(undefined4 **)((int)this + 0x2c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 0x2c))(1);
  }
  *(undefined4 *)((int)this + 0x2c) = 0;
  FUN_10008550((int)this + 0x30);
  return;
}



// Function: FUN_1000b710 at 1000b710

undefined4 __thiscall FUN_1000b710(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)((int)this + 0x2c) != 0) {
    iVar1 = (**(code **)(**(int **)((int)this + 0x2c) + 4))();
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar1 == iVar2) {
      uVar3 = (**(code **)(**(int **)((int)this + 0x2c) + 0x18))(param_1);
      return uVar3;
    }
  }
  return 0;
}



// Function: FUN_1000b760 at 1000b760

undefined4 __thiscall FUN_1000b760(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(undefined4 **)((int)this + 0x2c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 0x2c))(1);
  }
  iVar1 = (**(code **)(*param_1 + 8))();
  *(int *)((int)this + 0x2c) = iVar1;
  uVar2 = 2;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000b7a0 at 1000b7a0

undefined4 __thiscall FUN_1000b7a0(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)((int)this + 0x2c) == 0) {
    return 0x13;
  }
  iVar1 = (**(code **)(**(int **)((int)this + 0x2c) + 4))();
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == iVar1) {
    (**(code **)(*param_1 + 0x14))(*(undefined4 *)((int)this + 0x2c));
    return 0;
  }
  return 5;
}



// Function: FUN_1000b800 at 1000b800

undefined4 * __thiscall
FUN_1000b800(void *this,undefined4 param_1,undefined4 *param_2,undefined2 param_3,undefined4 param_4
            ,undefined4 param_5,undefined4 param_6)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d008;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002680(this,param_1,param_2,param_3);
  *(undefined4 *)((int)this + 0x12) = param_4;
  *(undefined ***)this = ValueBlockDef::vftable;
  *(undefined4 *)((int)this + 0x16) = param_6;
  *(undefined4 *)((int)this + 0x1a) = param_5;
  *(undefined4 *)((int)this + 0x1e) = 0;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000b880 at 1000b880

undefined4 * __thiscall
FUN_1000b880(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined2 param_4
            ,undefined4 param_5)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000d008;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002680(this,param_1,param_3,param_4);
  *(undefined ***)this = ValueBlockDef::vftable;
  *(undefined4 *)((int)this + 0x12) = param_5;
  *(undefined4 *)((int)this + 0x16) = 0;
  *(undefined4 *)((int)this + 0x1a) = 0;
  *(undefined4 *)((int)this + 0x1e) = param_2;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000b900 at 1000b900

undefined4 * __thiscall FUN_1000b900(void *this,int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dca6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)((int)this + 0x1e) == 0) {
    pvVar1 = operator_new(0x34);
    local_8 = 0;
    if (pvVar1 != (void *)0x0) {
      puVar2 = FUN_10003ac0(pvVar1,(undefined4 *)((int)this + 4),*(undefined4 *)((int)this + 0x12),
                            param_1,*(int *)((int)this + 0x1a),*(int *)((int)this + 0x16));
      ExceptionList = local_10;
      return puVar2;
    }
  }
  else {
    pvVar1 = operator_new(0x34);
    local_8 = 1;
    if (pvVar1 != (void *)0x0) {
      puVar2 = FUN_10003bb0(pvVar1,*(uint *)((int)this + 0x1e),(undefined4 *)((int)this + 4),
                            *(VBType *)((int)this + 0x12),param_1);
      ExceptionList = local_10;
      return puVar2;
    }
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}



// Function: FUN_1000b9b0 at 1000b9b0

undefined4 * __thiscall
FUN_1000b9b0(void *this,undefined4 *param_1,undefined4 param_2,VBType param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  ValueBase *pVVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000dceb;
  local_10 = ExceptionList;
  uVar2 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pVVar3 = ValueBase::create(param_3,(char *)0x0,-1);
  *(undefined ***)this = NamedObject::vftable;
  piVar1 = (int *)*param_1;
  *(int **)((int)this + 4) = piVar1;
  (**(code **)(*piVar1 + 4))(uVar2);
  *(undefined ***)this = NamedValue::vftable;
  *(ValueBase **)((int)this + 8) = pVVar3;
  *(undefined ***)this = ValueBlockHeader::vftable;
  *(undefined4 *)((int)this + 0xc) = param_2;
  *(undefined4 *)((int)this + 0x10) = param_2;
  *(undefined4 *)((int)this + 0x14) = param_4;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000ba50 at 1000ba50

ICLStatus __thiscall FUN_1000ba50(void *this,char *param_1,int param_2,undefined4 param_3)

{
  ValueBase *pVVar1;
  ICLStatus IVar2;
  
  IVar2 = 0;
  if (*(int *)((int)this + 0x10) != 0) {
    pVVar1 = *(ValueBase **)((int)this + 8);
    if (pVVar1 != (ValueBase *)0x0) {
      if (param_2 < 1) {
        (**(code **)(*(int *)pVVar1 + 0xc))();
      }
      else {
        IVar2 = ValueBase::set(pVVar1,param_1,param_2);
      }
      if ((*(void **)((int)this + 0x14) != (void *)0x0) && (IVar2 == 0)) {
        IVar2 = FUN_10003d50(*(void **)((int)this + 0x14),(int *)pVVar1,param_3);
      }
    }
    if (0 < *(int *)((int)this + 0x10)) {
      *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + -1;
    }
    return IVar2;
  }
  return 0x25;
}



// Function: FUN_1000bac0 at 1000bac0

ICLStatus __thiscall FUN_1000bac0(void *this,char *param_1,int param_2)

{
  ValueBase *pVVar1;
  ICLStatus IVar2;
  
  pVVar1 = *(ValueBase **)((int)this + 8);
  IVar2 = 0;
  if (pVVar1 != (ValueBase *)0x0) {
    if (param_1 == (char *)0x0) {
      (**(code **)(*(int *)pVVar1 + 0x10))();
    }
    else {
      IVar2 = ValueBase::set(pVVar1,param_1,param_2);
    }
  }
  if (-1 < *(int *)((int)this + 0x10)) {
    *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  }
  return IVar2;
}



// Function: FUN_1000bb10 at 1000bb10

undefined4 __thiscall FUN_1000bb10(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)((int)this + 8);
  if (piVar1 == (int *)0x0) {
    return 0x13;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == iVar2) {
    (**(code **)(*piVar1 + 0x14))(param_1);
    return 0;
  }
  return 5;
}



// Function: FUN_1000bb70 at 1000bb70

undefined4 __thiscall FUN_1000bb70(void *this,void *param_1)

{
  undefined4 uVar1;
  
  if (*(int **)((int)this + 8) != (int *)0x0) {
    uVar1 = FUN_1000b7a0(param_1,*(int **)((int)this + 8));
    return uVar1;
  }
  return 0x13;
}



// Function: FUN_1000bb90 at 1000bb90

undefined4 __thiscall FUN_1000bb90(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)((int)this + 8);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 == iVar2) {
      uVar4 = (**(code **)(*piVar1 + 0x18))(param_1);
      return uVar4;
    }
  }
  return 0;
}



// Function: FUN_1000bbe0 at 1000bbe0

undefined4 __thiscall FUN_1000bbe0(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)((int)this + 8);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    iVar3 = (**(code **)(*param_1 + 4))();
    if (iVar3 == iVar2) {
      uVar4 = (**(code **)(*piVar1 + 0x1c))(param_1);
      return uVar4;
    }
  }
  return 0;
}



// Function: FUN_1000bc30 at 1000bc30

undefined4 * __thiscall FUN_1000bc30(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1000dd2b;
  local_10 = ExceptionList;
  uVar1 = DAT_1001498c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = NamedValue::vftable;
  local_8 = 1;
  if (*(undefined4 **)((int)this + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 8))(1,uVar1);
  }
  *(undefined ***)this = NamedObject::vftable;
  local_8 = 0xffffffff;
  FUN_10004ab0((undefined4 *)((int)this + 4));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000bcc0 at 1000bcc0

bool __fastcall FUN_1000bcc0(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  iVar1 = FUN_10002940(param_1);
  while ((iVar1 != 0 && (bVar2))) {
    bVar2 = *(int *)(iVar1 + 0x10) == 0;
    iVar1 = FUN_10002950(param_1);
  }
  return bVar2;
}



// Function: FUN_1000bcf0 at 1000bcf0

ICLStatus __thiscall
FUN_1000bcf0(void *this,char *param_1,size_t param_2,char *param_3,int param_4,undefined4 param_5)

{
  void *this_00;
  ICLStatus IVar1;
  
  this_00 = (void *)FUN_10008580(this,param_1,param_2);
  if (this_00 != (void *)0x0) {
    IVar1 = FUN_1000ba50(this_00,param_3,param_4,param_5);
    return IVar1;
  }
  return 0x26;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000bd2a

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



// Function: __security_check_cookie at 1000bd82

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_1001498c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __ArrayUnwind at 1000bdb0

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



// Function: `eh_vector_destructor_iterator' at 1000be0e

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
  FUN_1000be59();
  return;
}



// Function: FUN_1000be59 at 1000be59

void FUN_1000be59(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 1000be78

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
  
  local_8 = &DAT_10010ec0;
  uStack_c = 0x1000be84;
  local_20[0] = DecodePointer(DAT_10014d1c);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10014d1c);
    local_24 = DecodePointer(DAT_10014d18);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10014d1c = EncodePointer(local_20[0]);
    DAT_10014d18 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000bf10();
  }
  return p_Var1;
}



// Function: FUN_1000bf10 at 1000bf10

void FUN_1000bf10(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000bf19

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: `eh_vector_constructor_iterator' at 1000bf30

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
  FUN_1000bf7d();
  return;
}



// Function: FUN_1000bf7d at 1000bf7d

void FUN_1000bf7d(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __CRT_INIT@12 at 1000bfe3

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
    if (DAT_100149dc < 1) {
      return 0;
    }
    DAT_100149dc = DAT_100149dc + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10014d10,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10014d0c == 2) {
      param_2 = (int *)DecodePointer(DAT_10014d1c);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10014d18);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10014d1c);
            piVar8 = (int *)DecodePointer(DAT_10014d18);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10014d18 = (PVOID)encoded_null();
        DAT_10014d1c = DAT_10014d18;
      }
      DAT_10014d0c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10014d10,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10014d10,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10014d0c == 0) {
      DAT_10014d0c = 1;
      iVar5 = initterm_e(&DAT_1000e164,&DAT_1000e16c);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1000e158,&DAT_1000e160);
      DAT_10014d0c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10014d10,0);
    }
    if ((DAT_10014d14 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10014d14), BVar2 != 0)) {
      (*DAT_10014d14)(param_1,2,param_3);
    }
    DAT_100149dc = DAT_100149dc + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1000c1ed

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000c28d) */
/* WARNING: Removing unreachable block (ram,0x1000c23a) */
/* WARNING: Removing unreachable block (ram,0x1000c2ba) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_100149a0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_100149dc == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = _DllMain_12(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      _DllMain_12(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000c2f8();
  return local_20;
}



// Function: FUN_1000c2f8 at 1000c2f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000c2f8(void)

{
  _DAT_100149a0 = 0xffffffff;
  return;
}



// Function: entry at 1000c303

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1000c326

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
  
  _DAT_10014af8 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10014afc = &stack0x00000004;
  _DAT_10014a38 = 0x10001;
  _DAT_100149e0 = 0xc0000409;
  _DAT_100149e4 = 1;
  local_32c = DAT_1001498c;
  local_328 = DAT_10014990;
  _DAT_100149ec = unaff_retaddr;
  _DAT_10014ac4 = in_GS;
  _DAT_10014ac8 = in_FS;
  _DAT_10014acc = in_ES;
  _DAT_10014ad0 = in_DS;
  _DAT_10014ad4 = unaff_EDI;
  _DAT_10014ad8 = unaff_ESI;
  _DAT_10014adc = unaff_EBX;
  _DAT_10014ae0 = in_EDX;
  _DAT_10014ae4 = in_ECX;
  _DAT_10014ae8 = in_EAX;
  _DAT_10014aec = unaff_EBP;
  DAT_10014af0 = unaff_retaddr;
  _DAT_10014af4 = in_CS;
  _DAT_10014b00 = in_SS;
  DAT_10014a30 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1000e71c);
  if (DAT_10014a30 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1000c440

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_1001498c ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000c485

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



// Function: FUN_1000c499 at 1000c499

void __cdecl
FUN_1000c499(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_1001498c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 1000c530

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



// Function: __FindPESection at 1000c570

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



// Function: __IsNonwritableInCurrentImage at 1000c5c0

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
  
  pcStack_10 = FUN_1000c499;
  local_14 = ExceptionList;
  local_c = DAT_1001498c ^ 0x10010f28;
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



// Function: _DllMain@12 at 1000c694

/* Library Function - Single Match
    _DllMain@12
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 _DllMain_12(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



// Function: ___security_init_cookie at 1000c6b8

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
  if ((DAT_1001498c == 0xbb40e64e) || ((DAT_1001498c & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_1001498c = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_1001498c == 0xbb40e64e) {
      DAT_1001498c = 0xbb40e64f;
    }
    else if ((DAT_1001498c & 0xffff0000) == 0) {
      DAT_1001498c = DAT_1001498c | (DAT_1001498c | 0x4711) << 0x10;
    }
    DAT_10014990 = ~DAT_1001498c;
  }
  else {
    DAT_10014990 = ~DAT_1001498c;
  }
  return;
}



// Function: Unwind@1000c7b0 at 1000c7b0

void Unwind_1000c7b0(void)

{
  int unaff_EBP;
  
  FUN_10008ee0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c7b8 at 1000c7b8

void Unwind_1000c7b8(void)

{
  int unaff_EBP;
  
  FUN_10004c90((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000c7c3 at 1000c7c3

void Unwind_1000c7c3(void)

{
  int unaff_EBP;
  
  FUN_10001000((short *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c7f0 at 1000c7f0

void Unwind_1000c7f0(void)

{
  int unaff_EBP;
  
  FUN_10001000((short *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c820 at 1000c820

void Unwind_1000c820(void)

{
  int unaff_EBP;
  
  FUN_10008ee0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c828 at 1000c828

void Unwind_1000c828(void)

{
  int unaff_EBP;
  
  FUN_10004c90((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000c850 at 1000c850

void Unwind_1000c850(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c880 at 1000c880

void Unwind_1000c880(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c8b0 at 1000c8b0

void Unwind_1000c8b0(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c8b8 at 1000c8b8

void Unwind_1000c8b8(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c8e0 at 1000c8e0

void Unwind_1000c8e0(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c910 at 1000c910

void Unwind_1000c910(void)

{
  int unaff_EBP;
  
  FUN_10001620(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c918 at 1000c918

void Unwind_1000c918(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c920 at 1000c920

void Unwind_1000c920(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c950 at 1000c950

void Unwind_1000c950(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c958 at 1000c958

void Unwind_1000c958(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c980 at 1000c980

void Unwind_1000c980(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c98b at 1000c98b

void Unwind_1000c98b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c996 at 1000c996

void Unwind_1000c996(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c99e at 1000c99e

void Unwind_1000c99e(void)

{
  int unaff_EBP;
  
  FUN_10001620(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c9d0 at 1000c9d0

void Unwind_1000c9d0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ca00 at 1000ca00

void Unwind_1000ca00(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000ca0b at 1000ca0b

void Unwind_1000ca0b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000ca16 at 1000ca16

void Unwind_1000ca16(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000ca40 at 1000ca40

void Unwind_1000ca40(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ca48 at 1000ca48

void Unwind_1000ca48(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000ca53 at 1000ca53

void Unwind_1000ca53(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000ca5e at 1000ca5e

void Unwind_1000ca5e(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ca90 at 1000ca90

void Unwind_1000ca90(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ca9b at 1000ca9b

void Unwind_1000ca9b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000caa3 at 1000caa3

void Unwind_1000caa3(void)

{
  int unaff_EBP;
  
  FUN_10001e30(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000caab at 1000caab

void Unwind_1000caab(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cab6 at 1000cab6

void Unwind_1000cab6(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cabe at 1000cabe

void Unwind_1000cabe(void)

{
  int unaff_EBP;
  
  FUN_10001f80((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@1000cac9 at 1000cac9

void Unwind_1000cac9(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cad4 at 1000cad4

void Unwind_1000cad4(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cadc at 1000cadc

void Unwind_1000cadc(void)

{
  int unaff_EBP;
  
  FUN_100020d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1000cb10 at 1000cb10

void Unwind_1000cb10(void)

{
  int unaff_EBP;
  
  FUN_10001e30(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cb18 at 1000cb18

void Unwind_1000cb18(void)

{
  int unaff_EBP;
  
  FUN_10001f80((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x20));
  return;
}



// Function: Unwind@1000cb23 at 1000cb23

void Unwind_1000cb23(void)

{
  int unaff_EBP;
  
  FUN_100020d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}



// Function: Unwind@1000cb2e at 1000cb2e

void Unwind_1000cb2e(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cb36 at 1000cb36

void Unwind_1000cb36(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cb3e at 1000cb3e

void Unwind_1000cb3e(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14));
  return;
}



// Function: Unwind@1000cb49 at 1000cb49

void Unwind_1000cb49(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1000cb54 at 1000cb54

void Unwind_1000cb54(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cb5c at 1000cb5c

void Unwind_1000cb5c(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cb64 at 1000cb64

void Unwind_1000cb64(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cb6c at 1000cb6c

void Unwind_1000cb6c(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x14));
  return;
}



// Function: Unwind@1000cb77 at 1000cb77

void Unwind_1000cb77(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000cb82 at 1000cb82

void Unwind_1000cb82(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cb8a at 1000cb8a

void Unwind_1000cb8a(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cb92 at 1000cb92

void Unwind_1000cb92(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cb9a at 1000cb9a

void Unwind_1000cb9a(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000cba5 at 1000cba5

void Unwind_1000cba5(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1000cbb0 at 1000cbb0

void Unwind_1000cbb0(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cbe0 at 1000cbe0

void Unwind_1000cbe0(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000cbeb at 1000cbeb

void Unwind_1000cbeb(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cbf3 at 1000cbf3

void Unwind_1000cbf3(void)

{
  int unaff_EBP;
  
  FUN_10001620(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cbfb at 1000cbfb

void Unwind_1000cbfb(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1000cc30 at 1000cc30

void Unwind_1000cc30(void)

{
  int unaff_EBP;
  
  FUN_10001620(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cc38 at 1000cc38

void Unwind_1000cc38(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cc40 at 1000cc40

void Unwind_1000cc40(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000cc70 at 1000cc70

void Unwind_1000cc70(void)

{
  int unaff_EBP;
  
  FUN_10002ec0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000cca0 at 1000cca0

void Unwind_1000cca0(void)

{
  int unaff_EBP;
  
  FUN_10002ec0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000ccd0 at 1000ccd0

void Unwind_1000ccd0(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ccd8 at 1000ccd8

void Unwind_1000ccd8(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cce0 at 1000cce0

void Unwind_1000cce0(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000cceb at 1000cceb

void Unwind_1000cceb(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000ccf6 at 1000ccf6

void Unwind_1000ccf6(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cd20 at 1000cd20

void Unwind_1000cd20(void)

{
  int unaff_EBP;
  
  FUN_10003080(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cd28 at 1000cd28

void Unwind_1000cd28(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000cd33 at 1000cd33

void Unwind_1000cd33(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000cd3b at 1000cd3b

void Unwind_1000cd3b(void)

{
  int unaff_EBP;
  
  FUN_100034d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000cd70 at 1000cd70

void Unwind_1000cd70(void)

{
  int unaff_EBP;
  
  FUN_10003080(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cd78 at 1000cd78

void Unwind_1000cd78(void)

{
  int unaff_EBP;
  
  FUN_100034d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000cd83 at 1000cd83

void Unwind_1000cd83(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cd8b at 1000cd8b

void Unwind_1000cd8b(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cd93 at 1000cd93

void Unwind_1000cd93(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14));
  return;
}



// Function: Unwind@1000cd9e at 1000cd9e

void Unwind_1000cd9e(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1000cda9 at 1000cda9

void Unwind_1000cda9(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cdd0 at 1000cdd0

void Unwind_1000cdd0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000ce00 at 1000ce00

void Unwind_1000ce00(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000ce0b at 1000ce0b

void Unwind_1000ce0b(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ce13 at 1000ce13

void Unwind_1000ce13(void)

{
  int unaff_EBP;
  
  FUN_1000b0a0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1000ce40 at 1000ce40

void Unwind_1000ce40(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ce48 at 1000ce48

void Unwind_1000ce48(void)

{
  int unaff_EBP;
  
  FUN_1000b0a0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x28));
  return;
}



// Function: Unwind@1000ce53 at 1000ce53

void Unwind_1000ce53(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000ce80 at 1000ce80

void Unwind_1000ce80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ce83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ceb0 at 1000ceb0

void Unwind_1000ceb0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ceb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1000cebc at 1000cebc

void Unwind_1000cebc(void)

{
  int unaff_EBP;
  
  FUN_100041e0((basic_streambuf<char,struct_std::char_traits<char>_> *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1000cec7 at 1000cec7

void Unwind_1000cec7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000cecd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_istream<char,struct_std::char_traits<char>_>::_vbase_destructor_
            ((basic_istream<char,struct_std::char_traits<char>_> *)(unaff_EBP + -0x10c));
  return;
}



// Function: Unwind@1000ced3 at 1000ced3

void Unwind_1000ced3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000ced9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)(unaff_EBP + -0xb4));
  return;
}



// Function: Unwind@1000cf10 at 1000cf10

void Unwind_1000cf10(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000cf1b at 1000cf1b

void Unwind_1000cf1b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1000cf50 at 1000cf50

void Unwind_1000cf50(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf5b at 1000cf5b

void Unwind_1000cf5b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000cf66 at 1000cf66

void Unwind_1000cf66(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf71 at 1000cf71

void Unwind_1000cf71(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1000cfa0 at 1000cfa0

void Unwind_1000cfa0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000cfd0 at 1000cfd0

void Unwind_1000cfd0(void)

{
  int unaff_EBP;
  
  FUN_10004c20(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d000 at 1000d000

void Unwind_1000d000(void)

{
  int unaff_EBP;
  
  FUN_10002730(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d030 at 1000d030

void Unwind_1000d030(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d03b at 1000d03b

void Unwind_1000d03b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d046 at 1000d046

void Unwind_1000d046(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d070 at 1000d070

void Unwind_1000d070(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d07b at 1000d07b

void Unwind_1000d07b(void)

{
  int unaff_EBP;
  
  FUN_10002730(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d0a0 at 1000d0a0

void Unwind_1000d0a0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d0ab at 1000d0ab

void Unwind_1000d0ab(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d0b6 at 1000d0b6

void Unwind_1000d0b6(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d0c1 at 1000d0c1

void Unwind_1000d0c1(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000d0cc at 1000d0cc

void Unwind_1000d0cc(void)

{
  int unaff_EBP;
  
  FUN_100054d0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000d100 at 1000d100

void Unwind_1000d100(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d108 at 1000d108

void Unwind_1000d108(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d110 at 1000d110

void Unwind_1000d110(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d118 at 1000d118

void Unwind_1000d118(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000d123 at 1000d123

void Unwind_1000d123(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000d12e at 1000d12e

void Unwind_1000d12e(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d160 at 1000d160

void Unwind_1000d160(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d16b at 1000d16b

void Unwind_1000d16b(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d190 at 1000d190

void Unwind_1000d190(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d19b at 1000d19b

void Unwind_1000d19b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d1a3 at 1000d1a3

void Unwind_1000d1a3(void)

{
  int unaff_EBP;
  
  FUN_10006170(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d1d0 at 1000d1d0

void Unwind_1000d1d0(void)

{
  int unaff_EBP;
  
  FUN_10006170(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d1d8 at 1000d1d8

void Unwind_1000d1d8(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d1e0 at 1000d1e0

void Unwind_1000d1e0(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d1e8 at 1000d1e8

void Unwind_1000d1e8(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1000d1f3 at 1000d1f3

void Unwind_1000d1f3(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000d1fe at 1000d1fe

void Unwind_1000d1fe(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d230 at 1000d230

void Unwind_1000d230(void)

{
  int unaff_EBP;
  
  FUN_100063f0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000d238 at 1000d238

void Unwind_1000d238(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d243 at 1000d243

void Unwind_1000d243(void)

{
  int unaff_EBP;
  
  FUN_10008ee0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d24b at 1000d24b

void Unwind_1000d24b(void)

{
  int unaff_EBP;
  
  FUN_10004c90((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8));
  return;
}



// Function: Unwind@1000d256 at 1000d256

void Unwind_1000d256(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d25e at 1000d25e

void Unwind_1000d25e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000d269 at 1000d269

void Unwind_1000d269(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000d290 at 1000d290

void Unwind_1000d290(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d29b at 1000d29b

void Unwind_1000d29b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d2a3 at 1000d2a3

void Unwind_1000d2a3(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000d2ab at 1000d2ab

void Unwind_1000d2ab(void)

{
  int unaff_EBP;
  
  IncValueT<long,5>::~IncValueT<long,5>((IncValueT<long,5> *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000d2b3 at 1000d2b3

void Unwind_1000d2b3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d2be at 1000d2be

void Unwind_1000d2be(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4));
  return;
}



// Function: Unwind@1000d2c9 at 1000d2c9

void Unwind_1000d2c9(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d2d1 at 1000d2d1

void Unwind_1000d2d1(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000d2d9 at 1000d2d9

void Unwind_1000d2d9(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d2e4 at 1000d2e4

void Unwind_1000d2e4(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000d310 at 1000d310

void Unwind_1000d310(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d31b at 1000d31b

void Unwind_1000d31b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d323 at 1000d323

void Unwind_1000d323(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d32b at 1000d32b

void Unwind_1000d32b(void)

{
  int unaff_EBP;
  
  FUN_10006170((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000d333 at 1000d333

void Unwind_1000d333(void)

{
  int unaff_EBP;
  
  FUN_100063f0((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000d360 at 1000d360

void Unwind_1000d360(void)

{
  FUN_10004ab0(&DAT_100149b4);
  return;
}



// Function: Unwind@1000d36a at 1000d36a

void Unwind_1000d36a(void)

{
  FUN_10004ab0(&DAT_100149b8);
  return;
}



// Function: Unwind@1000d374 at 1000d374

void Unwind_1000d374(void)

{
  FUN_100054d0(0x100149c0);
  return;
}



// Function: Unwind@1000d3a0 at 1000d3a0

void Unwind_1000d3a0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d3ab at 1000d3ab

void Unwind_1000d3ab(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d3d0 at 1000d3d0

void Unwind_1000d3d0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d410 at 1000d410

void Unwind_1000d410(void)

{
  int unaff_EBP;
  
  FUN_100096d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d440 at 1000d440

void Unwind_1000d440(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d44b at 1000d44b

void Unwind_1000d44b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d480 at 1000d480

void Unwind_1000d480(void)

{
  int unaff_EBP;
  
  FUN_100096d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d4b0 at 1000d4b0

void Unwind_1000d4b0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d4bb at 1000d4bb

void Unwind_1000d4bb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d4d4 at 1000d4d4

void Unwind_1000d4d4(void)

{
  int unaff_EBP;
  
  FUN_10004880(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1000d4dc at 1000d4dc

void Unwind_1000d4dc(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d4e4 at 1000d4e4

void Unwind_1000d4e4(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d4ec at 1000d4ec

void Unwind_1000d4ec(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d510 at 1000d510

void Unwind_1000d510(void)

{
  int unaff_EBP;
  
  FUN_100096d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d518 at 1000d518

void Unwind_1000d518(void)

{
  int unaff_EBP;
  
  FUN_10007620(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d520 at 1000d520

void Unwind_1000d520(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d52b at 1000d52b

void Unwind_1000d52b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d533 at 1000d533

void Unwind_1000d533(void)

{
  int unaff_EBP;
  
  FUN_10007bc0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x56));
  return;
}



// Function: Unwind@1000d53e at 1000d53e

void Unwind_1000d53e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d549 at 1000d549

void Unwind_1000d549(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d551 at 1000d551

void Unwind_1000d551(void)

{
  int unaff_EBP;
  
  FUN_10007d10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x76));
  return;
}



// Function: Unwind@1000d580 at 1000d580

void Unwind_1000d580(void)

{
  int unaff_EBP;
  
  FUN_10007620(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d588 at 1000d588

void Unwind_1000d588(void)

{
  int unaff_EBP;
  
  FUN_10007bc0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x56));
  return;
}



// Function: Unwind@1000d593 at 1000d593

void Unwind_1000d593(void)

{
  int unaff_EBP;
  
  FUN_10007d10((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x76));
  return;
}



// Function: Unwind@1000d59e at 1000d59e

void Unwind_1000d59e(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d5a6 at 1000d5a6

void Unwind_1000d5a6(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d5ae at 1000d5ae

void Unwind_1000d5ae(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14));
  return;
}



// Function: Unwind@1000d5b9 at 1000d5b9

void Unwind_1000d5b9(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1000d5c4 at 1000d5c4

void Unwind_1000d5c4(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d5cc at 1000d5cc

void Unwind_1000d5cc(void)

{
  int unaff_EBP;
  
  FUN_10001790(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d5d4 at 1000d5d4

void Unwind_1000d5d4(void)

{
  int unaff_EBP;
  
  FUN_10001670(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d5dc at 1000d5dc

void Unwind_1000d5dc(void)

{
  int unaff_EBP;
  
  FUN_100015d0((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x14));
  return;
}



// Function: Unwind@1000d5e7 at 1000d5e7

void Unwind_1000d5e7(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000d5f2 at 1000d5f2

void Unwind_1000d5f2(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d5fa at 1000d5fa

void Unwind_1000d5fa(void)

{
  int unaff_EBP;
  
  FUN_100096d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d620 at 1000d620

void Unwind_1000d620(void)

{
  int unaff_EBP;
  
  FUN_10003080(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d650 at 1000d650

void Unwind_1000d650(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d680 at 1000d680

void Unwind_1000d680(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1000d68b at 1000d68b

void Unwind_1000d68b(void)

{
  int unaff_EBP;
  
  FUN_10003080(*(undefined4 **)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1000d693 at 1000d693

void Unwind_1000d693(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + 0x14));
  return;
}



// Function: Unwind@1000d6c0 at 1000d6c0

void Unwind_1000d6c0(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 9));
  return;
}



// Function: Unwind@1000d6cb at 1000d6cb

void Unwind_1000d6cb(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd));
  return;
}



// Function: Unwind@1000d700 at 1000d700

void Unwind_1000d700(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 9));
  return;
}



// Function: Unwind@1000d70b at 1000d70b

void Unwind_1000d70b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd));
  return;
}



// Function: Unwind@1000d740 at 1000d740

void Unwind_1000d740(void)

{
  int unaff_EBP;
  
  StdParam<class_iclString>::~StdParam<class_iclString>
            (*(StdParam<class_iclString> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d748 at 1000d748

void Unwind_1000d748(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 9));
  return;
}



// Function: Unwind@1000d753 at 1000d753

void Unwind_1000d753(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd));
  return;
}



// Function: Unwind@1000d780 at 1000d780

void Unwind_1000d780(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d78b at 1000d78b

void Unwind_1000d78b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 9));
  return;
}



// Function: Unwind@1000d796 at 1000d796

void Unwind_1000d796(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d7a1 at 1000d7a1

void Unwind_1000d7a1(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd));
  return;
}



// Function: Unwind@1000d7d0 at 1000d7d0

void Unwind_1000d7d0(void)

{
  int unaff_EBP;
  
  StdParam<class_iclString>::~StdParam<class_iclString>
            (*(StdParam<class_iclString> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d800 at 1000d800

void Unwind_1000d800(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d830 at 1000d830

void Unwind_1000d830(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d83b at 1000d83b

void Unwind_1000d83b(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d843 at 1000d843

void Unwind_1000d843(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d84b at 1000d84b

void Unwind_1000d84b(void)

{
  int unaff_EBP;
  
  FUN_10009060((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000d856 at 1000d856

void Unwind_1000d856(void)

{
  int unaff_EBP;
  
  FUN_100054d0(*(int *)(unaff_EBP + -0x10) + 0x2e);
  return;
}



// Function: Unwind@1000d880 at 1000d880

void Unwind_1000d880(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d8b0 at 1000d8b0

void Unwind_1000d8b0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d8e0 at 1000d8e0

void Unwind_1000d8e0(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d8e8 at 1000d8e8

void Unwind_1000d8e8(void)

{
  int unaff_EBP;
  
  FUN_10009060((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1000d8f3 at 1000d8f3

void Unwind_1000d8f3(void)

{
  int unaff_EBP;
  
  FUN_100054d0(*(int *)(unaff_EBP + -0x10) + 0x2e);
  return;
}



// Function: Unwind@1000d8fe at 1000d8fe

void Unwind_1000d8fe(void)

{
  int unaff_EBP;
  
  FUN_100029c0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d906 at 1000d906

void Unwind_1000d906(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d930 at 1000d930

void Unwind_1000d930(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d938 at 1000d938

void Unwind_1000d938(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d940 at 1000d940

void Unwind_1000d940(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d970 at 1000d970

void Unwind_1000d970(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d9a0 at 1000d9a0

void Unwind_1000d9a0(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d9a8 at 1000d9a8

void Unwind_1000d9a8(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000d9d0 at 1000d9d0

void Unwind_1000d9d0(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da00 at 1000da00

void Unwind_1000da00(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000da0b at 1000da0b

void Unwind_1000da0b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da13 at 1000da13

void Unwind_1000da13(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000da1b at 1000da1b

void Unwind_1000da1b(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000da50 at 1000da50

void Unwind_1000da50(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da58 at 1000da58

void Unwind_1000da58(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000da80 at 1000da80

void Unwind_1000da80(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da8b at 1000da8b

void Unwind_1000da8b(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase(*(ValueBase **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000da93 at 1000da93

void Unwind_1000da93(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000dac0 at 1000dac0

void Unwind_1000dac0(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000dacb at 1000dacb

void Unwind_1000dacb(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000dad6 at 1000dad6

void Unwind_1000dad6(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000dae1 at 1000dae1

void Unwind_1000dae1(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000daec at 1000daec

void Unwind_1000daec(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000daf7 at 1000daf7

void Unwind_1000daf7(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000db02 at 1000db02

void Unwind_1000db02(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000db30 at 1000db30

void Unwind_1000db30(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db3b at 1000db3b

void Unwind_1000db3b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db46 at 1000db46

void Unwind_1000db46(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db51 at 1000db51

void Unwind_1000db51(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db5c at 1000db5c

void Unwind_1000db5c(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db67 at 1000db67

void Unwind_1000db67(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db72 at 1000db72

void Unwind_1000db72(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db7d at 1000db7d

void Unwind_1000db7d(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000db85 at 1000db85

void Unwind_1000db85(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000db90 at 1000db90

void Unwind_1000db90(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000dbc0 at 1000dbc0

void Unwind_1000dbc0(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x15));
  return;
}



// Function: Unwind@1000dbc8 at 1000dbc8

void Unwind_1000dbc8(void)

{
  int unaff_EBP;
  
  IncValueT<unsigned_char,0>::~IncValueT<unsigned_char,0>
            ((IncValueT<unsigned_char,0> *)(unaff_EBP + -0x15));
  return;
}



// Function: Unwind@1000dbd0 at 1000dbd0

void Unwind_1000dbd0(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x15));
  return;
}



// Function: Unwind@1000dbd8 at 1000dbd8

void Unwind_1000dbd8(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x15));
  return;
}



// Function: Unwind@1000dbe0 at 1000dbe0

void Unwind_1000dbe0(void)

{
  int unaff_EBP;
  
  IncValueT<signed_char,1>::~IncValueT<signed_char,1>
            ((IncValueT<signed_char,1> *)(unaff_EBP + -0x15));
  return;
}



// Function: Unwind@1000dbe8 at 1000dbe8

void Unwind_1000dbe8(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x15));
  return;
}



// Function: Unwind@1000dbf0 at 1000dbf0

void Unwind_1000dbf0(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x16));
  return;
}



// Function: Unwind@1000dbf8 at 1000dbf8

void Unwind_1000dbf8(void)

{
  int unaff_EBP;
  
  IncValueT<unsigned_short,2>::~IncValueT<unsigned_short,2>
            ((IncValueT<unsigned_short,2> *)(unaff_EBP + -0x16));
  return;
}



// Function: Unwind@1000dc00 at 1000dc00

void Unwind_1000dc00(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x16));
  return;
}



// Function: Unwind@1000dc08 at 1000dc08

void Unwind_1000dc08(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x16));
  return;
}



// Function: Unwind@1000dc10 at 1000dc10

void Unwind_1000dc10(void)

{
  int unaff_EBP;
  
  IncValueT<short,3>::~IncValueT<short,3>((IncValueT<short,3> *)(unaff_EBP + -0x16));
  return;
}



// Function: Unwind@1000dc18 at 1000dc18

void Unwind_1000dc18(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x16));
  return;
}



// Function: Unwind@1000dc20 at 1000dc20

void Unwind_1000dc20(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dc28 at 1000dc28

void Unwind_1000dc28(void)

{
  int unaff_EBP;
  
  IncValueT<unsigned_long,4>::~IncValueT<unsigned_long,4>
            ((IncValueT<unsigned_long,4> *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dc30 at 1000dc30

void Unwind_1000dc30(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dc38 at 1000dc38

void Unwind_1000dc38(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dc40 at 1000dc40

void Unwind_1000dc40(void)

{
  int unaff_EBP;
  
  IncValueT<long,5>::~IncValueT<long,5>((IncValueT<long,5> *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dc48 at 1000dc48

void Unwind_1000dc48(void)

{
  int unaff_EBP;
  
  ValueBase::~ValueBase((ValueBase *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000dc50 at 1000dc50

void Unwind_1000dc50(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000dc58 at 1000dc58

void Unwind_1000dc58(void)

{
  int unaff_EBP;
  
  NonIncValueT<class_iclString,6>::~NonIncValueT<class_iclString,6>
            ((NonIncValueT<class_iclString,6> *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000dc60 at 1000dc60

void Unwind_1000dc60(void)

{
  int unaff_EBP;
  
  FUN_10004ab0(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000dc68 at 1000dc68

void Unwind_1000dc68(void)

{
  int unaff_EBP;
  
  NonIncValueT<class_iclString,6>::~NonIncValueT<class_iclString,6>
            ((NonIncValueT<class_iclString,6> *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000dc90 at 1000dc90

void Unwind_1000dc90(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dc9b at 1000dc9b

void Unwind_1000dc9b(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dcd0 at 1000dcd0

void Unwind_1000dcd0(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000dcdb at 1000dcdb

void Unwind_1000dcdb(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dce3 at 1000dce3

void Unwind_1000dce3(void)

{
  int unaff_EBP;
  
  FUN_10002d20(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd10 at 1000dd10

void Unwind_1000dd10(void)

{
  int unaff_EBP;
  
  FUN_10002d20(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd18 at 1000dd18

void Unwind_1000dd18(void)

{
  int unaff_EBP;
  
  FUN_100015d0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000dd20 at 1000dd20

void Unwind_1000dd20(void)

{
  int unaff_EBP;
  
  FUN_10004ab0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: FUN_1000dd70 at 1000dd70

void FUN_1000dd70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1000d37e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  operator_delete__(DAT_100149cc);
  local_8 = local_8 & 0xffffff00;
  FUN_10004ab0(&DAT_100149b8);
  local_8 = 0xffffffff;
  FUN_10004ab0(&DAT_100149b4);
  ExceptionList = local_10;
  return;
}



