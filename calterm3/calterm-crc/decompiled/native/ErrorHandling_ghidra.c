/*
 * Decompiled from: ErrorHandling.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001009 at 10001009

void FUN_10001009(int param_1)

{
  FUN_10005fb2((int *)&DAT_1001564c,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: Catch@10001086 at 10001086

undefined1 * Catch_10001086(void)

{
  return &LAB_1000108c;
}



// Function: FUN_100010da at 100010da

void FUN_100010da(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_100039a5(0,param_2,param_3);
    return;
  }
  FUN_100038dd(param_1,param_2,param_3);
  return;
}



// Function: FUN_100010fa at 100010fa

undefined4 __cdecl FUN_100010fa(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10001102 at 10001102

undefined4 __cdecl FUN_10001102(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_1000110a at 1000110a

void FUN_1000110a(void)

{
  return;
}



// Function: FUN_1000110b at 1000110b

void FUN_1000110b(void)

{
  return;
}



// Function: FUN_1000110c at 1000110c

IUnknown * __thiscall FUN_1000110c(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_10004461(this,(int *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1000e624);
  }
  return pIVar2;
}



// Function: operator= at 10001138

/* Library Function - Single Match
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
   
   Library: Visual Studio 2012 Release */

_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> * __thiscall
_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
          (_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *this,IBinding *param_1)

{
  IBinding *pIVar1;
  
  pIVar1 = *(IBinding **)this;
  if (pIVar1 != param_1) {
    *(IBinding **)this = param_1;
    if (param_1 != (IBinding *)0x0) {
      (**(code **)(*(int *)param_1 + 4))(param_1);
    }
    if (pIVar1 != (IBinding *)0x0) {
      (**(code **)(*(int *)pIVar1 + 8))(pIVar1);
    }
  }
  return this;
}



// Function: AtlAdd<unsigned_long> at 10001166

/* Library Function - Single Match
    long __cdecl ATL::AtlAdd<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Release */

long __cdecl ATL::AtlAdd<unsigned_long>(ulong *param_1,ulong param_2,ulong param_3)

{
  if (-param_2 - 1 < param_3) {
    return -0x7ff8fdea;
  }
  *param_1 = param_2 + param_3;
  return 0;
}



// Function: AtlAddThrow<> at 1000118a

/* Library Function - Multiple Matches With Same Base Name
    unsigned int __cdecl ATL::AtlAddThrow<unsigned int>(unsigned int,unsigned int)
    unsigned long __cdecl ATL::AtlAddThrow<unsigned long>(unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Release */

ulong __cdecl AtlAddThrow<>(ulong param_1,ulong param_2)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  ulong local_8;
  
  lVar2 = ATL::AtlAdd<unsigned_long>(&local_8,param_1,param_2);
  if (-1 < lVar2) {
    return local_8;
  }
  FUN_10003606(lVar2);
  pcVar1 = (code *)swi(3);
  uVar3 = (*pcVar1)();
  return uVar3;
}



// Function: AtlMultiply<int> at 100011b0

/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<int>(int *,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __cdecl ATL::AtlMultiply<int>(int *param_1,int param_2,int param_3)

{
  long lVar1;
  
  if ((int)((ulonglong)((longlong)param_2 * (longlong)param_3 + 0x80000000) >> 0x20) == 0) {
    *param_1 = (int)((longlong)param_2 * (longlong)param_3);
    lVar1 = 0;
  }
  else {
    lVar1 = -0x7ff8fdea;
  }
  return lVar1;
}



// Function: AtlMultiply<> at 100011e3

/* Library Function - Multiple Matches With Same Base Name
    long __cdecl ATL::AtlMultiply<unsigned int>(unsigned int *,unsigned int,unsigned int)
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 __cdecl AtlMultiply<>(undefined4 *param_1,uint param_2,uint param_3)

{
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) != 0) {
    return 0x80070216;
  }
  *param_1 = (int)((ulonglong)param_2 * (ulonglong)param_3);
  return 0;
}



// Function: AtlMultiply<unsigned_long> at 10001205

/* Library Function - Single Match
    long __cdecl ATL::AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Release */

long __cdecl ATL::AtlMultiply<unsigned_long>(ulong *param_1,ulong param_2,ulong param_3)

{
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) != 0) {
    return -0x7ff8fdea;
  }
  *param_1 = (ulong)((ulonglong)param_2 * (ulonglong)param_3);
  return 0;
}



// Function: AtlMultiplyThrow<unsigned_int> at 10001227

/* Library Function - Single Match
    unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
   
   Library: Visual Studio 2012 Release */

uint __cdecl ATL::AtlMultiplyThrow<unsigned_int>(uint param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint local_8;
  
  iVar2 = AtlMultiply<>(&local_8,param_1,param_2);
  if (-1 < iVar2) {
    return local_8;
  }
  FUN_10003606(iVar2);
  pcVar1 = (code *)swi(3);
  uVar3 = (*pcVar1)();
  return uVar3;
}



// Function: FUN_1000124d at 1000124d

void FUN_1000124d(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_1000e634,param_2);
  return;
}



// Function: FUN_10001298 at 10001298

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10001298(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CErrorMessageSet>::vftable;
  FUN_100012db((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10015600 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_100012db at 100012db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100012db(void *this,undefined4 param_1)

{
  FUN_1000165d((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CErrorMessageSet>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CErrorMessageSet>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CErrorMessageSet>::vftable;
  *(undefined4 *)((int)this + 0xc) = param_1;
  return (undefined4 *)this;
}



// Function: CComCritSecLock<class_ATL::CComCriticalSection> at 1000131d

/* Library Function - Single Match
    public: __thiscall ATL::CComCritSecLock<class ATL::CComCriticalSection>::CComCritSecLock<class
   ATL::CComCriticalSection>(class ATL::CComCriticalSection &,bool)
   
   Library: Visual Studio */

CComCritSecLock<class_ATL::CComCriticalSection> * __thiscall
ATL::CComCritSecLock<class_ATL::CComCriticalSection>::
CComCritSecLock<class_ATL::CComCriticalSection>
          (CComCritSecLock<class_ATL::CComCriticalSection> *this,CComCriticalSection *param_1,
          bool param_2)

{
  *(CComCriticalSection **)this = param_1;
  this[4] = (CComCritSecLock<class_ATL::CComCriticalSection>)0x0;
  if (param_2) {
    EnterCriticalSection((LPCRITICAL_SECTION)param_1);
    this[4] = (CComCritSecLock<class_ATL::CComCriticalSection>)0x1;
  }
  return this;
}



// Function: FUN_10001344 at 10001344

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10001344(undefined4 *param_1)

{
  FUN_1000165d((int)param_1);
  *param_1 = ATL::CComObject<class_CErrorMessageSet>::vftable;
  param_1[1] = ATL::CComObject<class_CErrorMessageSet>::vftable;
  param_1[2] = ATL::CComObject<class_CErrorMessageSet>::vftable;
  (**(code **)(*DAT_10015600 + 4))();
  return param_1;
}



// Function: FUN_1000138b at 1000138b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000138b(undefined4 *param_1)

{
  FUN_100015bb(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_100014b9 at 100014b9

undefined4 * __thiscall FUN_100014b9(void *this,int *param_1)

{
  *(int **)this = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000150c at 1000150c

undefined4 * __thiscall FUN_1000150c(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000151c at 1000151c

undefined4 * __thiscall FUN_1000151c(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10001538 at 10001538

undefined4 * __thiscall FUN_10001538(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10001546 at 10001546

int __fastcall FUN_10001546(int param_1)

{
  undefined4 *puVar1;
  DWORD DVar2;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  FUN_1000177c((int)puVar1);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10015600 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  DVar2 = FUN_100042e7((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)DVar2 < 0) {
    DAT_100155fc = 1;
  }
  else {
    *puVar1 = 0x24;
  }
  return param_1;
}



// Function: FUN_10001587 at 10001587

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10001587(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_100015bb at 100015bb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100015bb(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10001587(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_1000160a at 1000160a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_1000160a(undefined4 *param_1)

{
  FUN_10001546((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10015614 = param_1;
  return param_1;
}



// Function: FUN_1000165d at 1000165d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000165d(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_10001587((void *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return param_1;
}



// Function: FUN_100016c3 at 100016c3

undefined4 * __thiscall FUN_100016c3(void *this,ulong param_1)

{
  undefined1 *puVar1;
  
  if ((int)param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(ulong *)((int)this + 4) = param_1;
  puVar1 = (undefined1 *)ATL::AtlCoTaskMemCAlloc(param_1,1);
  *(undefined1 **)((int)this + 8) = puVar1;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_100016f8 at 100016f8

undefined4 * __thiscall FUN_100016f8(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000170e at 1000170e

undefined4 * __thiscall FUN_1000170e(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10001755 at 10001755

undefined4 * __thiscall FUN_10001755(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000177c at 1000177c

int __fastcall FUN_1000177c(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: FUN_100017bc at 100017bc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100017bc(int param_1)

{
  FUN_10005e35(param_1);
  return;
}



// Function: FUN_100017da at 100017da

void __fastcall FUN_100017da(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_100017f4 at 100017f4

void __fastcall FUN_100017f4(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10001804 at 10001804

void __fastcall FUN_10001804(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10001814 at 10001814

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001814(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CErrorMessageSet>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10003c8e((int)(param_1 + 3));
  (**(code **)(*DAT_10015600 + 8))();
  FUN_10001b16((int)(param_1 + 3));
  return;
}



// Function: FUN_10001861 at 10001861

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001861(int param_1)

{
  FUN_10001b16(param_1);
  return;
}



// Function: FUN_1000187f at 1000187f

void __fastcall FUN_1000187f(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10001896 at 10001896

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001896(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CErrorMessageSet>::vftable;
  param_1[1] = ATL::CComObject<class_CErrorMessageSet>::vftable;
  param_1[2] = ATL::CComObject<class_CErrorMessageSet>::vftable;
  param_1[3] = 0xc0000001;
  FUN_10003c8e((int)param_1);
  (**(code **)(*DAT_10015600 + 8))();
  FUN_10001b16((int)param_1);
  return;
}



// Function: FUN_100018e7 at 100018e7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100018e7(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10001aad(param_1);
  return;
}



// Function: FUN_10001916 at 10001916

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001916(int param_1)

{
  FUN_10001a7a((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10001938 at 10001938

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001938(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000c47c;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_1000195d at 1000195d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_1000195d(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000c49f;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_10001982 at 10001982

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001982(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000c4c2;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_100019a7 at 100019a7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_100019a7(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000c4e5;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_100019cc at 100019cc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_100019cc(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000c508;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_100019f1 at 100019f1

void __fastcall FUN_100019f1(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_100019fe at 100019fe

void __fastcall FUN_100019fe(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001a0b at 10001a0b

void __fastcall FUN_10001a0b(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001a18 at 10001a18

void __fastcall FUN_10001a18(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001a25 at 10001a25

void __fastcall FUN_10001a25(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001a37 at 10001a37

void __fastcall FUN_10001a37(int *param_1)

{
  if ((int *)*param_1 == param_1 + 1) {
    return;
  }
  free((void *)*param_1);
  return;
}



// Function: FUN_10001a43 at 10001a43

void __fastcall FUN_10001a43(int *param_1)

{
  if ((int *)*param_1 == param_1 + 1) {
    return;
  }
  free((void *)*param_1);
  return;
}



// Function: FUN_10001a4f at 10001a4f

void __fastcall FUN_10001a4f(int *param_1)

{
  if ((int *)*param_1 == param_1 + 1) {
    return;
  }
  free((void *)*param_1);
  return;
}



// Function: FUN_10001a5b at 10001a5b

void __fastcall FUN_10001a5b(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001a68 at 10001a68

void __fastcall FUN_10001a68(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10001a7a at 10001a7a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10001a7a(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_1000c52b;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10001aa4 at 10001aa4

void __fastcall FUN_10001aa4(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001aad at 10001aad

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001aad(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_10001a7a((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_10001b04 at 10001b04

void __fastcall FUN_10001b04(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_10001b16 at 10001b16

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001b16(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10001a7a((LPCRITICAL_SECTION)(param_1 + 0x10));
  return;
}



// Function: FUN_10001b68 at 10001b68

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001b68(int *param_1)

{
  FUN_10003811(param_1);
  FUN_1000590f(param_1);
  return;
}



// Function: FUN_10001b93 at 10001b93

void __fastcall FUN_10001b93(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10001ba2 at 10001ba2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10001ba2(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_10003811(param_1 + 1);
  FUN_10001b68(param_1 + 1);
  return;
}



// Function: FUN_10001bf8 at 10001bf8

int * __thiscall FUN_10001bf8(void *this,int param_1)

{
  code *pcVar1;
  int *piVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Load size is inaccurate */
    piVar2 = *this;
    if ((piVar2 != (int *)0x0) && (*(undefined4 *)this = 0, piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    return (int *)this;
  }
  _com_issue_error(-0x7fffbffd);
  pcVar1 = (code *)swi(3);
  piVar2 = (int *)(*pcVar1)();
  return piVar2;
}



// Function: FUN_10001c31 at 10001c31

bool __thiscall FUN_10001c31(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_10001c42 at 10001c42

uint __thiscall FUN_10001c42(void *this,int param_1)

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



// Function: FUN_10001c61 at 10001c61

uint __thiscall FUN_10001c61(void *this,int param_1)

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



// Function: FUN_10001c8a at 10001c8a

bool __thiscall FUN_10001c8a(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10001c42(this,param_1);
  return (char)uVar1 == '\0';
}



// Function: FUN_10001ca2 at 10001ca2

bool __thiscall FUN_10001ca2(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10001c61(this,param_1);
  return (char)uVar1 == '\0';
}



// Function: FUN_10001cfa at 10001cfa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10001cfa(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10001bd7);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10001d57 at 10001d57

undefined4 * __thiscall FUN_10001d57(void *this,byte param_1)

{
  FUN_10001814((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001d76 at 10001d76

undefined4 * __thiscall FUN_10001d76(void *this,byte param_1)

{
  FUN_10001896((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001d95 at 10001d95

undefined4 * __thiscall FUN_10001d95(void *this,byte param_1)

{
  FUN_100018e7((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001db4 at 10001db4

undefined4 * __thiscall FUN_10001db4(void *this,byte param_1)

{
  FUN_10001aad((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001dd3 at 10001dd3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10001dd3(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10005e35((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001e0a at 10001e0a

undefined4 * __thiscall FUN_10001e0a(void *this,byte param_1)

{
  FUN_10001ba2((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001e29 at 10001e29

undefined4 __thiscall FUN_10001e29(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_100043ec(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10001e80 at 10001e80

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_10001e80(void *this,char *param_1,wchar_t *param_2)

{
  size_t sVar1;
  void *pvVar2;
  void *pvVar3;
  int iVar4;
  void *local_24;
  void *local_20;
  uint local_1c;
  uint local_18;
  void *local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x10001e8c;
  if ((param_1 == (char *)0x0) || (param_2 == (wchar_t *)0x0)) {
    return false;
  }
  sVar1 = strlen(param_1);
  local_18 = sVar1 + 1;
  pvVar2 = (void *)FUN_1000a5d0(local_18);
  local_8 = 0;
  local_24 = pvVar2;
  local_14 = pvVar2;
  sVar1 = wcslen(param_2);
  local_1c = sVar1 * 2 + 2;
  pvVar3 = (void *)FUN_1000a5d0(-(uint)((int)((ulonglong)local_1c * 2 >> 0x20) != 0) |
                                (uint)((ulonglong)local_1c * 2));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_20 = pvVar3;
  if ((pvVar2 != (void *)0x0) && (pvVar3 != (void *)0x0)) {
    FUN_100067c4(pvVar2,local_18,param_1,local_18);
    FUN_100067c4(pvVar3,local_1c,param_2,local_1c);
    iVar4 = FUN_10001e29(this,&local_24,&local_20);
    if (iVar4 != 0) {
      iVar4 = 0;
      pvVar2 = (void *)0x0;
      pvVar3 = (void *)0x0;
      local_14 = (void *)0x0;
      goto LAB_10001f56;
    }
  }
  iVar4 = -0x7ff8fff2;
LAB_10001f56:
  local_8 = local_8 & 0xffffff00;
  operator_delete__(pvVar3);
  local_8 = 0xffffffff;
  operator_delete__(pvVar2);
  return -1 < iVar4;
}



// Function: FUN_10001f89 at 10001f89

void __thiscall FUN_10001f89(void *this,LPCSTR param_1)

{
  LPSTR pCVar1;
  
  pCVar1 = CharNextA(param_1);
  FUN_100027fe(this,param_1,(int)pCVar1 - (int)param_1);
  return;
}



// Function: FUN_10001fab at 10001fab

void FUN_10001fab(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&PTR_1000ef10);
  return;
}



// Function: FUN_10001fc5 at 10001fc5

void FUN_10001fc5(int param_1)

{
  FUN_10007335(param_1 + -4);
  return;
}



// Function: FUN_10001fcf at 10001fcf

void FUN_10001fcf(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10001fe3 at 10001fe3

void FUN_10001fe3(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_10001ff6 at 10001ff6

void FUN_10001ff6(int param_1)

{
  FUN_10001fe3(param_1 + -4);
  return;
}



// Function: FUN_10002000 at 10002000

void FUN_10002000(int param_1)

{
  FUN_10001fe3(param_1 + -8);
  return;
}



// Function: FUN_1000200a at 1000200a

void FUN_1000200a(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



// Function: FUN_1000201e at 1000201e

void FUN_1000201e(int param_1)

{
  FUN_1000200a(param_1 + -4);
  return;
}



// Function: FUN_10002028 at 10002028

void FUN_10002028(int param_1)

{
  FUN_1000200a(param_1 + -8);
  return;
}



// Function: FUN_10002032 at 10002032

LONG FUN_10002032(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10015600 + 4))();
  }
  return LVar1;
}



// Function: FUN_1000205c at 1000205c

undefined4 FUN_1000205c(void)

{
  return 1;
}



// Function: FUN_10002062 at 10002062

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10002062(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  ulong uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  char local_2c [16];
  int local_1c;
  ulong local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000206e;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    local_1c = 0;
    local_8 = 0;
    sVar3 = wcslen(param_2);
    local_18[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar1 = local_18[0];
    if (-1 < lVar4) {
      if (((int)local_18[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
        pcVar5 = local_2c;
      }
      else {
        pcVar5 = (char *)FUN_10002658(&local_1c,uVar1);
      }
      pcVar5 = AtlW2AHelper(pcVar5,param_2,uVar1,3);
      if (pcVar5 != (char *)0x0) {
        FUN_10001e80((void *)(param_1 + 4),pcVar5,param_3);
      }
    }
    local_8 = 0xffffffff;
    FUN_100017da(&local_1c);
  }
  FUN_1000a668();
  return;
}



// Function: FUN_10002126 at 10002126

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_10002126(void *this,wchar_t *param_1)

{
  ulong uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  char local_30 [16];
  void *local_20;
  ulong local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x10002132;
  local_20 = this;
  if (param_1 != (wchar_t *)0x0) {
    local_1c[1] = 0;
    local_8 = 0;
    sVar3 = wcslen(param_1);
    local_1c[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_1c,local_1c[0],2);
    uVar1 = local_1c[0];
    if (-1 < lVar4) {
      if (((int)local_1c[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_1c[0]), bVar2)) {
        pcVar5 = local_30;
      }
      else {
        pcVar5 = (char *)FUN_10002658(local_1c + 1,uVar1);
      }
      pcVar5 = AtlW2AHelper(pcVar5,param_1,uVar1,3);
      if (pcVar5 != (char *)0x0) {
        sVar3 = strlen(pcVar5);
        FUN_100027fe(local_20,pcVar5,sVar3);
      }
    }
    local_8 = 0xffffffff;
    FUN_100017da((int *)(local_1c + 1));
  }
  FUN_1000a668();
  return;
}



// Function: FUN_100021d2 at 100021d2

void __thiscall FUN_100021d2(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + 4;
  }
  FUN_10003064(iVar1,param_1,param_2);
  return;
}



// Function: FUN_100021f0 at 100021f0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_100021f0(void *this,CRegKey *param_1,char *param_2,undefined1 *param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  long lVar5;
  wchar_t *pwVar6;
  uint uStack_114c;
  size_t sStack_1134;
  size_t sStack_1130;
  undefined4 *local_112c;
  char *local_1128;
  CRegKey *local_1124;
  uint local_1120 [66];
  char local_1018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1000c778;
  local_10 = ExceptionList;
  uStack_114c = DAT_100155d8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_114c;
  ExceptionList = &local_10;
  local_1124 = param_1;
  local_1128 = param_2;
  local_1120[0] = 0;
  local_112c = (undefined4 *)this;
  local_18 = uStack_114c;
  iVar2 = FUN_1000470c(this,local_1018);
  if ((iVar2 < 0) || (iVar2 = FUN_10006572(local_1018,(undefined2 *)local_1120), iVar2 == 0))
  goto LAB_10002636;
  FUN_10005dce(local_112c);
  iVar2 = FUN_1000470c(local_112c,local_1018);
  if (iVar2 < 0) goto LAB_10002636;
  uVar3 = local_1120[0] & 0xffff;
  if (uVar3 == 8) {
    uVar3 = ATL::CRegKey::SetStringValue(param_1,param_2,local_1018,1);
LAB_1000260f:
    if (uVar3 != 0) {
      FUN_10002ca4(uVar3);
      goto LAB_10002636;
    }
  }
  else {
    if (uVar3 == 0x11) {
      sStack_1130 = strlen(local_1018);
      if ((sStack_1130 & 1) == 0) {
        sStack_1134 = (int)sStack_1130 / 2;
        local_1120[1] = 0;
        local_8 = 5;
        Allocate(local_1120 + 1,sStack_1134);
        local_8 = 4;
        FUN_1000251e();
        return;
      }
      goto LAB_10002636;
    }
    if (uVar3 == 0x13) {
      local_1124 = (CRegKey *)0x0;
      local_8 = 3;
      sVar4 = strlen(local_1018);
      local_1120[0] = sVar4 + 1;
      lVar5 = ATL::AtlMultiply<int>((int *)local_1120,local_1120[0],2);
      uVar3 = local_1120[0];
      if (-1 < lVar5) {
        if (((int)local_1120[0] < 0x401) &&
           (bVar1 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_1120[0]), bVar1)) {
          local_14 = (undefined1 *)&uStack_114c;
          pwVar6 = (wchar_t *)&uStack_114c;
        }
        else {
          pwVar6 = (wchar_t *)FUN_10002658(&local_1124,uVar3);
        }
        pwVar6 = AtlA2WHelper(pwVar6,local_1018,uVar3 >> 1,3);
        if (pwVar6 != (wchar_t *)0x0) {
          Ordinal_277(pwVar6,0,0,&sStack_1134);
          sStack_1130 = sStack_1134;
          uVar3 = RegSetValueExA(*(HKEY *)param_1,local_1128,0,4,(BYTE *)&sStack_1130,4);
          local_8 = 0xffffffff;
          FUN_100017da((int *)&local_1124);
          goto LAB_1000260f;
        }
      }
      local_8 = 0xffffffff;
      FUN_100017da((int *)&local_1124);
      goto LAB_10002636;
    }
    if (uVar3 == 0x4008) {
      sVar4 = strlen(local_1018);
      local_1120[1] = 0;
      local_8 = 1;
      Allocate(local_1120 + 1,sVar4 + 2);
      local_8 = 0;
      FUN_10002322();
      return;
    }
  }
  FUN_1000470c(local_112c,param_3);
LAB_10002636:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000230b at 1000230b

undefined * Catch_1000230b(void)

{
  return &DAT_10002311;
}



// Function: FUN_10002322 at 10002322

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10002322(void)

{
  BYTE BVar1;
  LPSTR lpsz;
  BYTE *lpsz_00;
  BOOL BVar2;
  uint uVar3;
  BYTE unaff_BL;
  uint unaff_EBP;
  BYTE *pBVar4;
  
  pBVar4 = *(BYTE **)(unaff_EBP - 0x1118);
  if (pBVar4 == (BYTE *)0x0) {
    uVar3 = 0xe;
  }
  else {
    lpsz_00 = (BYTE *)(unaff_EBP - 0x1014);
    BVar1 = *(BYTE *)(unaff_EBP - 0x1014);
    while (BVar1 != '\0') {
      lpsz = CharNextA((LPCSTR)lpsz_00);
      if ((*lpsz_00 == '\\') && (*lpsz == '0')) {
        *pBVar4 = unaff_BL;
        lpsz_00 = (BYTE *)CharNextA(lpsz);
      }
      else {
        *pBVar4 = *lpsz_00;
        BVar2 = IsDBCSLeadByte(*lpsz_00);
        if (BVar2 != 0) {
          pBVar4 = pBVar4 + 1;
          lpsz_00 = lpsz_00 + 1;
          if (*lpsz_00 == '\0') break;
          *pBVar4 = *lpsz_00;
        }
        lpsz_00 = lpsz_00 + 1;
      }
      pBVar4 = pBVar4 + 1;
      BVar1 = *lpsz_00;
    }
    pBVar4[0] = '\0';
    pBVar4[1] = '\0';
    uVar3 = FUN_10005ce0(*(void **)(unaff_EBP - 0x1120),*(LPCSTR *)(unaff_EBP - 0x1124),
                         *(BYTE **)(unaff_EBP - 0x1118));
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x1118) != unaff_EBP - 0x1114) {
    FUN_10003d09((undefined4 *)(unaff_EBP - 0x1118));
  }
  if (uVar3 == 0) {
    FUN_1000470c(*(void **)(unaff_EBP - 0x1128),*(undefined1 **)(unaff_EBP - 0x1138));
  }
  else {
    FUN_10002ca4(uVar3);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar3 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x113c) = 0x10002654;
  __security_check_cookie(uVar3 ^ unaff_EBP);
  return;
}



// Function: Catch@100024fd at 100024fd

undefined * Catch_100024fd(void)

{
  return &DAT_10002503;
}



// Function: FUN_1000251e at 1000251e

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000251e(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  DWORD unaff_EBX;
  uint unaff_EBP;
  DWORD unaff_EDI;
  
  if (*(int *)(unaff_EBP - 0x1118) == 0) {
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x1118) != unaff_EBP - 0x1114) {
      FUN_10003d1d((undefined4 *)(unaff_EBP - 0x1118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x1118),unaff_EBX,unaff_EDI);
    *(DWORD *)(unaff_EBP - 0x111c) = unaff_EBX;
    if (0 < *(int *)(unaff_EBP - 0x112c)) {
      iVar3 = *(int *)(unaff_EBP - 0x112c);
      do {
        iVar4 = *(int *)(unaff_EBP - 0x1118);
        bVar2 = *(byte *)((unaff_EBP - 0x1014) + unaff_EBX);
        uVar5 = FUN_100037a1((void *)(uint)bVar2,bVar2);
        pbVar1 = (byte *)((int)unaff_EBX / 2 + iVar4);
        *pbVar1 = *pbVar1 | (char)uVar5 <<
                            (4U - (char)((*(uint *)(unaff_EBP - 0x111c) & 1) << 2) & 0x1f);
        unaff_EBX = *(int *)(unaff_EBP - 0x111c) + 1;
        *(DWORD *)(unaff_EBP - 0x111c) = unaff_EBX;
      } while ((int)unaff_EBX < iVar3);
      unaff_EBX = 0;
      unaff_EDI = *(DWORD *)(unaff_EBP - 0x1130);
    }
    uVar5 = RegSetValueExA((HKEY)**(undefined4 **)(unaff_EBP - 0x1120),
                           *(LPCSTR *)(unaff_EBP - 0x1124),unaff_EBX,3,
                           *(BYTE **)(unaff_EBP - 0x1118),unaff_EDI);
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    if (*(int *)(unaff_EBP - 0x1118) != unaff_EBP - 0x1114) {
      FUN_10003d1d((undefined4 *)(unaff_EBP - 0x1118));
    }
    if (uVar5 == 0) {
      FUN_1000470c(*(void **)(unaff_EBP - 0x1128),*(undefined1 **)(unaff_EBP - 0x1138));
    }
    else {
      FUN_10002ca4(uVar5);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar5 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x113c) = 0x10002654;
  __security_check_cookie(uVar5 ^ unaff_EBP);
  return;
}



// Function: FUN_10002658 at 10002658

undefined4 * __thiscall FUN_10002658(void *this,ulong param_1)

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



// Function: Allocate at 10002686

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
    public: wchar_t * __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Library: Visual Studio 2012 Release */

int __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  if (uVar1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_1000278c(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100026b5

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
    public: wchar_t * __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Library: Visual Studio 2012 Release */

int __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  if (uVar1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_100027b2(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100026e4

/* Library Function - Multiple Matches With Same Base Name
    public: char * __thiscall ATL::CTempBuffer<char,128,class ATL::CCRTAllocator>::Allocate(unsigned
   int)
    public: unsigned char * __thiscall ATL::CTempBuffer<unsigned char,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
    public: wchar_t * __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Library: Visual Studio 2012 Release */

int __thiscall Allocate(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = ATL::AtlMultiplyThrow<unsigned_int>(param_1,1);
  if (uVar1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_100027d8(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10002713 at 10002713

void FUN_10002713(size_t param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10002717. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  malloc(param_1);
  return;
}



// Function: FUN_10002742 at 10002742

int __thiscall FUN_10002742(void *this,uint param_1)

{
  if (param_1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_100027b2(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10002767 at 10002767

int __thiscall FUN_10002767(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_100027d8(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000278c at 1000278c

void __thiscall FUN_1000278c(void *this,size_t param_1)

{
  code *pcVar1;
  void *pvVar2;
  
  pvVar2 = malloc(param_1);
  if (pvVar2 != (void *)0x0) {
    *(void **)this = pvVar2;
    return;
  }
  FUN_10003606(0x8007000e);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_100027b2 at 100027b2

void __thiscall FUN_100027b2(void *this,size_t param_1)

{
  code *pcVar1;
  void *pvVar2;
  
  pvVar2 = malloc(param_1);
  if (pvVar2 != (void *)0x0) {
    *(void **)this = pvVar2;
    return;
  }
  FUN_10003606(0x8007000e);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_100027d8 at 100027d8

void __thiscall FUN_100027d8(void *this,size_t param_1)

{
  code *pcVar1;
  void *pvVar2;
  
  pvVar2 = malloc(param_1);
  if (pvVar2 != (void *)0x0) {
    *(void **)this = pvVar2;
    return;
  }
  FUN_10003606(0x8007000e);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// Function: FUN_100027fe at 100027fe

undefined4 __thiscall FUN_100027fe(void *this,void *param_1,rsize_t param_2)

{
  ulong uVar1;
  LPVOID pvVar2;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar3 = param_2 + 1 + *this;
                    /* WARNING: Load size is inaccurate */
  if ((*this < iVar3) && ((int)param_2 < iVar3)) {
    if (*(int *)((int)this + 4) <= iVar3) {
      do {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          return 0;
        }
        uVar1 = *(int *)((int)this + 4) * 2;
        *(ulong *)((int)this + 4) = uVar1;
      } while ((int)uVar1 <= iVar3);
      pvVar2 = FUN_10002929(*(LPVOID *)((int)this + 8),uVar1,1);
      if (pvVar2 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar2;
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((-1 < *this) && (iVar3 = *(int *)((int)this + 4), *this < iVar3)) &&
       (iVar3 - *this <= iVar3)) {
                    /* WARNING: Load size is inaccurate */
      FUN_100067c4((void *)(*(int *)((int)this + 8) + *this),iVar3 - *this,param_1,param_2);
                    /* WARNING: Load size is inaccurate */
      *(rsize_t *)this = *this + param_2;
                    /* WARNING: Load size is inaccurate */
      *(undefined1 *)(*this + *(int *)((int)this + 8)) = 0;
      return 1;
    }
  }
  return 0;
}



// Function: AtlA2WHelper at 10002881

/* Library Function - Single Match
    wchar_t * __stdcall AtlA2WHelper(wchar_t *,char const *,int,unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

wchar_t * AtlA2WHelper(wchar_t *param_1,char *param_2,int param_3,uint param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  
  if ((param_1 == (wchar_t *)0x0) || (param_2 == (char *)0x0)) {
    pwVar2 = (wchar_t *)0x0;
  }
  else {
    *param_1 = L'\0';
    iVar1 = MultiByteToWideChar(param_4,0,param_2,-1,param_1,param_3);
    pwVar2 = (wchar_t *)(-(uint)(iVar1 != 0) & (uint)param_1);
  }
  return pwVar2;
}



// Function: FUN_100028b9 at 100028b9

void FUN_100028b9(int param_1)

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



// Function: AtlCoTaskMemCAlloc at 100028fc

/* Library Function - Single Match
    void * __cdecl ATL::AtlCoTaskMemCAlloc(unsigned long,unsigned long)
   
   Library: Visual Studio 2012 Release */

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



// Function: FUN_10002929 at 10002929

LPVOID __cdecl FUN_10002929(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10002959 at 10002959

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10002959(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  PVOID pvVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  piVar2 = param_4;
  piVar1 = param_1;
  if (param_4 == (int *)0x0) {
    iVar4 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    if (param_1 == (int *)0x0) {
      iVar4 = -0x7ff8ffa9;
    }
    else if (*param_1 == 0) {
      iVar4 = -0x7fff0001;
    }
    else {
      for (piVar7 = (int *)param_1[2]; piVar7 < (int *)piVar1[3]; piVar7 = piVar7 + 1) {
        param_4 = (int *)*piVar7;
        if (((param_4 != (int *)0x0) && (param_4[2] != 0)) &&
           (iVar4 = _InlineIsEqualGUID(param_2,(int *)*param_4), piVar3 = param_4, iVar4 != 0)) {
          param_4 = (int *)param_4[4];
          pvVar5 = (PVOID)*param_4;
          if (pvVar5 == (PVOID)0x0) {
            lpCriticalSection = (LPCRITICAL_SECTION)(piVar1 + 4);
            EnterCriticalSection(lpCriticalSection);
            iVar4 = 0;
            if ((*param_4 == 0) &&
               (iVar4 = (*(code *)piVar3[2])(piVar3[3],&DAT_1000eb20,&param_1), -1 < iVar4)) {
              pvVar5 = EncodePointer(param_1);
              *param_4 = (int)pvVar5;
            }
            LeaveCriticalSection(lpCriticalSection);
            pvVar5 = (PVOID)*param_4;
            if (pvVar5 != (PVOID)0x0) goto LAB_10002a38;
          }
          else {
LAB_10002a38:
            puVar6 = (undefined4 *)DecodePointer(pvVar5);
            iVar4 = (**(code **)*puVar6)(puVar6,param_3,piVar2);
          }
          if (*piVar2 != 0) {
            return iVar4;
          }
          if (iVar4 != 0) {
            return iVar4;
          }
          break;
        }
      }
      iVar4 = -0x7ffbfeef;
    }
  }
  return iVar4;
}



// Function: FUN_10002a62 at 10002a62

int FUN_10002a62(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  if (param_1 == 0) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    piVar5 = *(int **)(param_1 + 8);
    iVar3 = 0;
    if (piVar5 < *(int **)(param_1 + 0xc)) {
      do {
        puVar1 = (undefined4 *)*piVar5;
        if ((puVar1 != (undefined4 *)0x0) &&
           ((param_3 == (void *)0x0 ||
            (bVar2 = FUN_1000699e(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
          iVar6 = 1;
          iVar3 = (*(code *)puVar1[1])();
          if (iVar3 < 0) {
            return iVar3;
          }
          piVar4 = (int *)(*(code *)puVar1[6])(1);
          iVar3 = FUN_100030e1((GUID *)*puVar1,piVar4,iVar6);
          if (iVar3 < 0) {
            return iVar3;
          }
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 < *(int **)(param_1 + 0xc));
      if (iVar3 < 0) {
        return iVar3;
      }
    }
    if (param_2 != 0) {
      iVar3 = FUN_10003462(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return iVar3;
}



// Function: FUN_10002aea at 10002aea

int FUN_10002aea(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    piVar5 = *(int **)(param_1 + 8);
    iVar3 = 0;
    if (piVar5 < *(int **)(param_1 + 0xc)) {
      do {
        puVar1 = (undefined4 *)*piVar5;
        if ((puVar1 != (undefined4 *)0x0) &&
           ((param_3 == (void *)0x0 ||
            (bVar2 = FUN_1000699e(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
          iVar3 = 0;
          piVar4 = (int *)(*(code *)puVar1[6])();
          iVar3 = FUN_100030e1((GUID *)*puVar1,piVar4,iVar3);
          if (iVar3 < 0) {
            return iVar3;
          }
          iVar3 = (*(code *)puVar1[1])(0);
          if (iVar3 < 0) {
            return iVar3;
          }
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 < *(int **)(param_1 + 0xc));
      if (iVar3 < 0) {
        return iVar3;
      }
    }
    if (param_2 != 0) {
      iVar3 = FUN_1000361e(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return iVar3;
}



// Function: AtlComQIPtrAssign at 10002b75

/* Library Function - Single Match
    struct IUnknown * __stdcall ATL::AtlComQIPtrAssign(struct IUnknown * *,struct IUnknown *,struct
   _GUID const &)
   
   Library: Visual Studio 2012 Release */

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



// Function: AtlCrtErrorCheck at 10002bb0

/* Library Function - Single Match
    int __cdecl ATL::AtlCrtErrorCheck(int)
   
   Library: Visual Studio 2012 Release */

int __cdecl ATL::AtlCrtErrorCheck(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    return param_1;
  }
  if (param_1 == 0xc) {
    uVar3 = 0x8007000e;
  }
  else if ((param_1 == 0x16) || (param_1 == 0x22)) {
    uVar3 = 0x80070057;
  }
  else {
    if (param_1 == 0x50) {
      return param_1;
    }
    uVar3 = 0x80004005;
  }
  FUN_10003606(uVar3);
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}



// Function: FUN_10002beb at 10002beb

LPCSTR __cdecl FUN_10002beb(LPCSTR param_1)

{
  char cVar1;
  LPCSTR pCVar2;
  LPCSTR pCVar3;
  
  if (param_1 != (LPCSTR)0x0) {
    pCVar3 = (LPCSTR)0x0;
    while (cVar1 = *param_1, cVar1 != '\0') {
      pCVar2 = param_1;
      if ((cVar1 != '.') && (pCVar2 = pCVar3, cVar1 == '\\')) {
        pCVar2 = (LPCSTR)0x0;
      }
      param_1 = CharNextA(param_1);
      pCVar3 = pCVar2;
    }
    if (pCVar3 == (LPCSTR)0x0) {
      pCVar3 = param_1;
    }
    return pCVar3;
  }
  return param_1;
}



// Function: FUN_10002c23 at 10002c23

int FUN_10002c23(LPCWSTR param_1)

{
  WCHAR WVar1;
  LPCWSTR lpsz;
  int iVar2;
  LPWSTR pWVar3;
  LPWSTR pWVar4;
  
  iVar2 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    WVar1 = *param_1;
    lpsz = param_1;
    pWVar4 = param_1;
    while (WVar1 != L'\0') {
      pWVar3 = CharNextW(lpsz);
      WVar1 = *lpsz;
      if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
        pWVar4 = pWVar3;
      }
      lpsz = pWVar3;
      WVar1 = *pWVar3;
    }
    iVar2 = (int)pWVar4 - (int)param_1 >> 1;
  }
  return iVar2;
}



// Function: FUN_10002c6f at 10002c6f

undefined4 FUN_10002c6f(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10015620;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10002c8d at 10002c8d

DWORD FUN_10002c8d(void)

{
  DWORD DVar1;
  uint uVar2;
  
  DVar1 = GetLastError();
  uVar2 = DVar1 & 0xffff | 0x80070000;
  if ((int)DVar1 < 1) {
    uVar2 = DVar1;
  }
  return uVar2;
}



// Function: FUN_10002ca4 at 10002ca4

uint __cdecl FUN_10002ca4(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff | 0x80070000;
  if ((int)param_1 < 1) {
    uVar1 = param_1;
  }
  return uVar1;
}



// Function: AtlInternalQueryInterface at 10002cb9

/* Library Function - Single Match
    long __stdcall ATL::AtlInternalQueryInterface(void *,struct ATL::_ATL_INTMAP_ENTRY const
   *,struct _GUID const &,void * *)
   
   Library: Visual Studio 2012 Release */

long ATL::AtlInternalQueryInterface
               (void *param_1,_ATL_INTMAP_ENTRY *param_2,_GUID *param_3,void **param_4)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_ATL_INTMAP_ENTRY *)0x0)) {
    lVar2 = -0x7ff8ffa9;
  }
  else if (param_4 == (void **)0x0) {
    lVar2 = -0x7fffbffd;
  }
  else {
    iVar3 = InlineIsEqualUnknown(param_3);
    if (iVar3 == 0) {
      for (; pcVar1 = *(code **)(param_2 + 8), pcVar1 != (code *)0x0; param_2 = param_2 + 0xc) {
        iVar3 = *(int *)param_2;
        if (iVar3 == 0) {
LAB_10002d1a:
          if (pcVar1 == (code *)0x1) goto LAB_10002cea;
          lVar2 = (*pcVar1)(param_1,param_3,param_4,*(int *)(param_2 + 4));
          if (lVar2 == 0) goto LAB_10002cf8;
          if ((iVar3 != 0) && (lVar2 < 0)) goto LAB_10002d48;
        }
        else {
          iVar4 = _InlineIsEqualGUID(*(int **)param_2,(int *)param_3);
          if (iVar4 != 0) goto LAB_10002d1a;
        }
      }
      lVar2 = -0x7fffbffe;
LAB_10002d48:
      *param_4 = (void *)0x0;
    }
    else {
LAB_10002cea:
      piVar5 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar5 + 4))(piVar5);
      *param_4 = piVar5;
LAB_10002cf8:
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10002d59 at 10002d59

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10002d59(HMODULE param_1,wchar_t *param_2,int *param_3,undefined4 *param_4)

{
  uint uVar1;
  ulong uVar2;
  bool bVar3;
  DWORD DVar4;
  LPCSTR lpsz;
  size_t sVar5;
  long lVar6;
  char *_Str;
  wchar_t *pwVar7;
  int iVar8;
  errno_t eVar9;
  LPCSTR pCVar10;
  wchar_t local_14c [8];
  int *local_13c;
  LPCSTR local_138;
  int local_134;
  ulong local_130;
  char local_12c [270];
  char local_1e [2];
  wchar_t *local_1c;
  undefined1 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 300;
  local_8 = 0x10002d68;
  local_1c = param_2;
  local_13c = param_3;
  if ((param_3 == (int *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_10003056;
  *param_3 = 0;
  *param_4 = 0;
  local_134 = 0;
  local_8 = 0;
  DVar4 = GetModuleFileNameA(param_1,local_12c,0x104);
  if (DVar4 == 0) {
    FUN_10002c8d();
  }
  else if (DVar4 != 0x104) {
    lpsz = local_12c;
    local_138 = (LPCSTR)0x0;
    while (local_12c[0] != '\0') {
      pCVar10 = lpsz;
      if ((local_12c[0] != '.') && (pCVar10 = local_138, local_12c[0] == '\\')) {
        pCVar10 = (LPCSTR)0x0;
      }
      lpsz = CharNextA(lpsz);
      local_138 = pCVar10;
      local_12c[0] = *lpsz;
    }
    if (local_138 == (LPCSTR)0x0) {
      local_138 = lpsz;
    }
    if (local_1c == (wchar_t *)0x0) {
LAB_10002ebf:
      sVar5 = strlen(local_12c);
      local_130 = sVar5 + 1;
      lVar6 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
      uVar2 = local_130;
      if (-1 < lVar6) {
        if (((int)local_130 < 0x401) &&
           (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_130), bVar3)) {
          pwVar7 = local_14c;
        }
        else {
          pwVar7 = (wchar_t *)FUN_10002658(&local_134,uVar2);
        }
        pwVar7 = AtlA2WHelper(pwVar7,local_12c,uVar2 >> 1,3);
        if (pwVar7 != (wchar_t *)0x0) {
          iVar8 = Ordinal_161(pwVar7,param_4);
          if (iVar8 < 0) {
            local_1c = (wchar_t *)0x626c742e;
            local_18 = 0;
            if (local_138 + (5 - (int)local_12c) < (char *)0x105) {
              eVar9 = strcpy_s(local_138,(rsize_t)(local_1e + -(int)local_138),(char *)&local_1c);
              ATL::AtlCrtErrorCheck(eVar9);
              sVar5 = strlen(local_12c);
              local_130 = sVar5 + 1;
              lVar6 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
              uVar2 = local_130;
              if (-1 < lVar6) {
                if (((int)local_130 < 0x401) &&
                   (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_130), bVar3))
                {
                  pwVar7 = local_14c;
                }
                else {
                  pwVar7 = (wchar_t *)FUN_10002658(&local_134,uVar2);
                }
                pwVar7 = AtlA2WHelper(pwVar7,local_12c,uVar2 >> 1,3);
                if ((pwVar7 != (wchar_t *)0x0) && (iVar8 = Ordinal_161(pwVar7,param_4), -1 < iVar8))
                goto LAB_10003014;
              }
            }
          }
          else {
LAB_10003014:
            iVar8 = Ordinal_2(pwVar7);
            *local_13c = iVar8;
            if (iVar8 == 0) {
              (**(code **)(*(int *)*param_4 + 8))((int *)*param_4);
              *param_4 = 0;
            }
          }
        }
      }
    }
    else {
      sVar5 = wcslen(local_1c);
      local_130 = sVar5 + 1;
      lVar6 = ATL::AtlMultiply<int>((int *)&local_130,local_130,2);
      uVar2 = local_130;
      if (-1 < lVar6) {
        if (((int)local_130 < 0x401) &&
           (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_130), bVar3)) {
          pwVar7 = local_14c;
        }
        else {
          pwVar7 = (wchar_t *)FUN_10002658(&local_134,uVar2);
        }
        _Str = AtlW2AHelper((char *)pwVar7,local_1c,uVar2,3);
        if (_Str != (char *)0x0) {
          sVar5 = strlen(_Str);
          uVar1 = sVar5 + DVar4;
          if (((DVar4 <= uVar1) && (sVar5 <= uVar1)) && (uVar1 < 0x10e)) {
            FUN_10006882(local_12c + DVar4,0x10e - DVar4,_Str);
            goto LAB_10002ebf;
          }
        }
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_100017da(&local_134);
LAB_10003056:
  FUN_1000a668();
  return;
}



// Function: FUN_10003064 at 10003064

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003064(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    puVar2 = (undefined4 *)FUN_1000a5a2(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      *puVar2 = param_2;
      uVar1 = 0;
      puVar2[1] = param_3;
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
      puVar2[2] = *(undefined4 *)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = puVar2;
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    }
  }
  return uVar1;
}



// Function: FUN_100030e1 at 100030e1

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_100030e1(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  HRESULT HVar5;
  size_t sVar6;
  long lVar7;
  char *pcVar8;
  errno_t eVar9;
  LSTATUS LVar10;
  char local_15c [16];
  int local_14c [4];
  HKEY local_13c;
  undefined4 local_138;
  undefined4 local_134;
  int *local_130;
  int *local_12c;
  GUID *local_128;
  undefined4 local_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  OLECHAR local_114 [64];
  char local_94 [140];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x13c;
  local_128 = param_1;
  local_12c = param_2;
  local_130 = (int *)0x0;
  local_8 = 1;
  if (((param_2 != (int *)0x0) &&
      (iVar4 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_1000f9f0), iVar4 == 0)) &&
     (HVar5 = CoCreateInstance((IID *)&DAT_10010740,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000e908,&local_130
                              ), -1 < HVar5)) {
    for (; *local_12c != 0; local_12c = local_12c + 2) {
      puVar1 = (undefined4 *)local_12c[1];
      local_124 = *puVar1;
      uStack_120 = puVar1[1];
      uStack_11c = puVar1[2];
      uStack_118 = puVar1[3];
      if (param_3 == 0) {
        param_1 = local_128;
        if (*local_12c == 1) {
          (**(code **)(*local_130 + 0x18))();
        }
        else {
          (**(code **)(*local_130 + 0x20))(local_130,local_128,1,&local_124);
        }
      }
      else {
        if (*local_12c == 1) {
          iVar4 = (**(code **)(*local_130 + 0x14))();
        }
        else {
          iVar4 = (**(code **)(*local_130 + 0x1c))(local_130,local_128);
        }
        param_1 = local_128;
        if (iVar4 < 0) goto LAB_1000343e;
      }
    }
    if (param_3 == 0) {
      StringFromGUID2(param_1,local_114,0x40);
      local_14c[3] = 0;
      local_8 = CONCAT31(local_8._1_3_,6);
      sVar6 = wcslen(local_114);
      local_12c = (int *)(sVar6 + 1);
      lVar7 = ATL::AtlMultiply<int>((int *)&local_12c,(int)local_12c,2);
      piVar2 = local_12c;
      if (-1 < lVar7) {
        if (((int)local_12c < 0x401) &&
           (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_12c), bVar3))
        {
          pcVar8 = local_15c;
        }
        else {
          pcVar8 = (char *)FUN_10002658(local_14c + 3,(ulong)piVar2);
        }
        pcVar8 = AtlW2AHelper(pcVar8,local_114,(int)piVar2,3);
        if (pcVar8 != (char *)0x0) {
          eVar9 = strcpy_s(local_94,0x80,"CLSID\\");
          ATL::AtlCrtErrorCheck(eVar9);
          eVar9 = strcat_s(local_94,0x80,pcVar8);
          ATL::AtlCrtErrorCheck(eVar9);
          eVar9 = strcat_s(local_94,0x80,"\\Required Categories");
          ATL::AtlCrtErrorCheck(eVar9);
          local_14c[0] = -0x80000000;
          local_14c[1] = 0;
          local_14c[2] = 0;
          local_13c = (HKEY)0x0;
          local_138 = 0;
          local_134 = 0;
          local_8 = CONCAT31((int3)((uint)local_8 >> 8),8);
          local_128 = (GUID *)0x0;
          iVar4 = FUN_1000481b(&local_13c,(HKEY)0x80000000,local_94,0x20019);
          if (iVar4 == 0) {
            LVar10 = RegQueryInfoKeyA(local_13c,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)&local_128,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
            FUN_10003860((int *)&local_13c);
            if ((LVar10 == 0) && (local_128 == (GUID *)0x0)) {
              FUN_10003b52(local_14c,local_94);
            }
          }
          eVar9 = strcpy_s(local_94,0x80,"CLSID\\");
          ATL::AtlCrtErrorCheck(eVar9);
          eVar9 = strcat_s(local_94,0x80,pcVar8);
          ATL::AtlCrtErrorCheck(eVar9);
          eVar9 = strcat_s(local_94,0x80,"\\Implemented Categories");
          ATL::AtlCrtErrorCheck(eVar9);
          iVar4 = FUN_1000481b(&local_13c,(HKEY)0x80000000,local_94,0x20019);
          if (iVar4 == 0) {
            LVar10 = RegQueryInfoKeyA(local_13c,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)&local_128,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
            FUN_10003860((int *)&local_13c);
            if ((LVar10 == 0) && (local_128 == (GUID *)0x0)) {
              FUN_10003b52(local_14c,local_94);
            }
          }
          local_8._0_1_ = 7;
          FUN_10003860((int *)&local_13c);
          local_8 = CONCAT31(local_8._1_3_,6);
          FUN_10003860(local_14c);
        }
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_100017da(local_14c + 3);
    }
  }
LAB_1000343e:
  local_8 = 0xffffffff;
  if (local_130 != (int *)0x0) {
    (**(code **)(*local_130 + 8))(local_130);
  }
  FUN_1000a668();
  return;
}



// Function: FUN_10003462 at 10003462

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003462(HMODULE param_1,wchar_t *param_2)

{
  int iVar1;
  rsize_t _MaxCount;
  errno_t eVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  wchar_t *pwVar4;
  int local_22c;
  int *local_228;
  wchar_t *local_224;
  char local_21d;
  wchar_t local_21c [259];
  undefined2 local_16;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x21c;
  local_22c = 0;
  local_228 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar1 = FUN_10002d59(param_1,param_2,&local_22c,&local_228);
  if (-1 < iVar1) {
    pwVar4 = (wchar_t *)0x0;
    local_224 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar1 = (**(code **)(*local_228 + 0x24))(local_228,0xffffffff,0,0,0,&local_224);
    if ((iVar1 < 0) || (local_224 == (wchar_t *)0x0)) {
LAB_10003536:
      local_21d = '\0';
      iVar1 = FUN_10002c6f(&local_21d);
      if (iVar1 < 0) {
        local_8._0_1_ = 2;
        Ordinal_6(local_224);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_228 != (int *)0x0) {
          (**(code **)(*local_228 + 8))(local_228);
        }
        local_8 = 0xffffffff;
        Ordinal_6(local_22c);
        goto LAB_100035fe;
      }
    }
    else {
      _MaxCount = Ordinal_7(local_224);
      eVar2 = wcsncpy_s(local_21c,0x104,local_224,_MaxCount);
      ATL::AtlCrtErrorCheck(eVar2);
      local_16 = 0;
      iVar1 = FUN_10002c23(local_21c);
      if ((uint)(iVar1 * 2) < 0x208) {
        local_21c[iVar1] = L'\0';
        pwVar4 = local_21c;
        goto LAB_10003536;
      }
      ___report_rangecheckfailure();
    }
    if (local_21d == '\x01') {
      hModule = GetModuleHandleW(L"OLEAUT32.DLL");
      if (hModule == (HMODULE)0x0) goto LAB_100035b2;
      pFVar3 = GetProcAddress(hModule,"RegisterTypeLibForUser");
      if (pFVar3 == (FARPROC)0x0) goto LAB_100035b2;
    }
    else {
LAB_100035b2:
      pFVar3 = Ordinal_163_exref;
    }
    (*pFVar3)(local_228,local_22c,pwVar4);
    local_8._0_1_ = 2;
    Ordinal_6(local_224);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_228 != (int *)0x0) {
    (**(code **)(*local_228 + 8))(local_228);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_22c);
LAB_100035fe:
  FUN_1000a668();
  return;
}



// Function: FUN_10003606 at 10003606

void FUN_10003606(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10012c28);
}



// Function: FUN_1000361e at 1000361e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000361e(HMODULE param_1,wchar_t *param_2)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_18 = 0;
  local_14[0] = (int *)0x0;
  local_8 = 2;
  iVar1 = FUN_10002d59(param_1,param_2,&local_18,local_14);
  if (iVar1 < 0) goto LAB_100036c8;
  iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1);
  if (iVar1 < 0) goto LAB_100036c8;
  param_2 = (wchar_t *)((uint)param_2 & 0xffffff);
  iVar1 = FUN_10002c6f((undefined1 *)((int)&param_2 + 3));
  if (iVar1 < 0) goto LAB_100036c8;
  if (param_2._3_1_ == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_1000369e;
    pFVar2 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar2 == (FARPROC)0x0) goto LAB_1000369e;
  }
  else {
LAB_1000369e:
    pFVar2 = Ordinal_186_exref;
  }
  iVar1 = (*pFVar2)(param_1,(uint)(ushort)param_1[6].unused,
                    (uint)*(ushort *)((int)&param_1[6].unused + 2),param_1[4].unused,
                    param_1[5].unused);
  (**(code **)(*local_14[0] + 0x30))(local_14[0],param_1);
LAB_100036c8:
  local_8 = local_8 & 0xffffff00;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  return iVar1;
}



// Function: AtlW2AHelper at 100036ef

/* Library Function - Single Match
    char * __stdcall AtlW2AHelper(char *,wchar_t const *,int,unsigned int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

char * AtlW2AHelper(char *param_1,wchar_t *param_2,int param_3,uint param_4)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_1 == (char *)0x0) || (param_2 == (wchar_t *)0x0)) {
    pcVar2 = (char *)0x0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    pcVar2 = (char *)(-(uint)(iVar1 != 0) & (uint)param_1);
  }
  return pcVar2;
}



// Function: FUN_10003728 at 10003728

void __thiscall FUN_10003728(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10003734 at 10003734

void __thiscall FUN_10003734(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: Attach at 10003740

/* Library Function - Single Match
    public: void __thiscall ATL::CComBSTR::Attach(wchar_t *)
   
   Library: Visual Studio 2012 Release */

void __thiscall ATL::CComBSTR::Attach(CComBSTR *this,wchar_t *param_1)

{
  if (*(wchar_t **)this != param_1) {
    Ordinal_6(*(undefined4 *)this);
    *(wchar_t **)this = param_1;
  }
  return;
}



// Function: FUN_1000375e at 1000375e

void __thiscall FUN_1000375e(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10003772 at 10003772

undefined4 FUN_10003772(LPCSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_s_AppID_1000e3e8;
  do {
    iVar1 = lstrcmpiA(param_1,*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1000e418);
  return 1;
}



// Function: FUN_100037a1 at 100037a1

uint __thiscall FUN_100037a1(void *this,char param_1)

{
  uint in_EAX;
  
  if ('/' < param_1) {
    if (param_1 < ':') {
      return (int)param_1 - 0x30;
    }
    if ('@' < param_1) {
      if (param_1 < 'G') {
        return (int)param_1 - 0x37;
      }
      in_EAX = CONCAT31((int3)((uint)this >> 8),param_1) - 0x61;
      if ((byte)in_EAX < 6) {
        return (int)param_1 - 0x57;
      }
    }
  }
  return in_EAX & 0xffffff00;
}



// Function: FUN_100037de at 100037de

void FUN_100037de(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10001cfa(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10003811 at 10003811

undefined4 __fastcall FUN_10003811(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      puVar1 = (undefined4 *)FUN_10003e68(param_1,iVar2);
      operator_delete__((void *)*puVar1);
      puVar1 = (undefined4 *)FUN_10004245(param_1,iVar2);
      operator_delete__((void *)*puVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  FUN_1000590f(param_1);
  return 0;
}



// Function: FUN_1000384e at 1000384e

void FUN_1000384e(int param_1)

{
  FUN_10003811((int *)(param_1 + 4));
  return;
}



// Function: FUN_10003860 at 10003860

void __fastcall FUN_10003860(int *param_1)

{
  if (*param_1 != 0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_1000387a at 1000387a

int __thiscall
FUN_1000387a(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,REGSAM param_5,
            LPSECURITY_ATTRIBUTES param_6,undefined4 *param_7)

{
  int iVar1;
  void *local_c;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  local_c = this;
  if (*(int *)((int)this + 8) == 0) {
    iVar1 = RegCreateKeyExA(param_1,(LPCSTR)param_2,0,(LPSTR)param_3,param_4,param_5,param_6,
                            &local_8,(LPDWORD)&local_c);
  }
  else {
    iVar1 = FID_conflict_RegCreateKeyExW
                      (param_1,param_2,0,param_3,param_4,param_5,param_6,&local_8,(LPDWORD)&local_c)
    ;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_c;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_10003860((int *)this);
    *(HKEY *)this = local_8;
  }
  return iVar1;
}



// Function: FUN_100038dd at 100038dd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100038dd(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = (void *)FUN_1000a5a2(0x44);
    if (this != (void *)0x0) {
      FUN_10001298(this,param_1);
    }
    iVar1 = FUN_10003955();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@10003942 at 10003942

undefined * Catch_10003942(void)

{
  return &DAT_10003948;
}



// Function: FUN_10003955 at 10003955

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003955(void)

{
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI != (int *)0x0) {
    unaff_ESI = FUN_1000663f((int)(unaff_EDI + 6));
    if (-1 < unaff_ESI) {
      unaff_ESI = 0;
    }
    if ((-1 < unaff_ESI) && (unaff_ESI = FUN_10003c2d((int)(unaff_EDI + 3)), -1 < unaff_ESI)) {
      unaff_ESI = 0;
    }
    if ((unaff_ESI != 0) || (unaff_ESI = (**(code **)*unaff_EDI)(), unaff_ESI != 0)) {
      (**(code **)(*unaff_EDI + 0xc))(1);
    }
  }
  return unaff_ESI;
}



// Function: FUN_100039a5 at 100039a5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100039a5(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)FUN_1000a5a2(0x38);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10001344(puVar1);
    }
    iVar2 = FUN_10003a1d();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10003a0a at 10003a0a

undefined * Catch_10003a0a(void)

{
  return &DAT_10003a10;
}



// Function: FUN_10003a1d at 10003a1d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10003a1d(void)

{
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI != (int *)0x0) {
    InterlockedIncrement(unaff_EDI + 3);
    unaff_ESI = FUN_1000663f((int)(unaff_EDI + 3));
    if ((-1 < unaff_ESI) && (unaff_ESI = FUN_10003c2d((int)unaff_EDI), -1 < unaff_ESI)) {
      unaff_ESI = 0;
    }
    InterlockedDecrement(unaff_EDI + 3);
    if ((unaff_ESI == 0) && (unaff_ESI = (**(code **)*unaff_EDI)(), unaff_ESI == 0)) {
      return 0;
    }
    (**(code **)(*unaff_EDI + 0x14))(1);
  }
  return unaff_ESI;
}



// Function: FUN_10003a78 at 10003a78

HRESULT __thiscall FUN_10003a78(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  int *piVar1;
  HRESULT HVar2;
  LPUNKNOWN local_8;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  local_8 = (LPUNKNOWN)this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_1000e6d8,(LPVOID *)this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_1000eb20,&local_8);
    if (HVar2 < 0) goto LAB_10003af5;
    HVar2 = OleRun(local_8);
    if (-1 < HVar2) {
      HVar2 = (*local_8->lpVtbl->QueryInterface)(local_8,(IID *)&DAT_1000e6d8,(void **)this);
    }
    (*local_8->lpVtbl->Release)(local_8);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_10003af5:
  *(undefined4 *)this = 0;
  return HVar2;
}



// Function: FUN_10003b00 at 10003b00

undefined4 FUN_10003b00(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_10003b3e at 10003b3e

void FUN_10003b3e(LONG *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x10003b42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10003b52 at 10003b52

void __thiscall FUN_10003b52(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*(int *)((int)this + 8) == 0) {
    RegDeleteKeyA(*this,param_1);
  }
  else {
    FID_conflict_RegDeleteKeyA(*this,param_1);
  }
  return;
}



// Function: FUN_10003b74 at 10003b74

void __thiscall FUN_10003b74(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegDeleteValueA(*this,param_1);
  return;
}



// Function: FUN_10003bb9 at 10003bb9

undefined4 __fastcall FUN_10003bb9(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (*(LPCSTR)*param_1 == '\'') {
    pCVar1 = CharNextA((LPCSTR)*param_1);
    if (*pCVar1 != '\'') {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10003bd3 at 10003bd3

void __cdecl FUN_10003bd3(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10003c2d at 10003c2d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __fastcall FUN_10003c2d(int param_1)

{
  FUN_10003a78((void *)(param_1 + 0x2c),(IID *)&DAT_1000e678,(LPUNKNOWN)0x0,0x17);
  FUN_10003c73();
  return;
}



// Function: Catch@10003c59 at 10003c59

undefined * Catch_10003c59(void)

{
  int unaff_EBP;
  
  FUN_10001bf8((void *)(*(int *)(unaff_EBP + -0x14) + 0x2c),0);
  return &DAT_10003c6c;
}



// Function: FUN_10003c73 at 10003c73

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003c73(void)

{
  int unaff_ESI;
  
  FUN_10008b57(unaff_ESI);
  return 0;
}



// Function: FUN_10003c8e at 10003c8e

void __fastcall FUN_10003c8e(int param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 unaff_ESI;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_100058eb((int *)(param_1 + 0x30));
  }
  piVar1 = (int *)(param_1 + 0x2c);
  if (*piVar1 == 0) {
    return;
  }
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,unaff_ESI);
    *piVar1 = 0;
    return;
  }
  _com_issue_error(-0x7fffbffd);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



// Function: FUN_10003cac at 10003cac

int __thiscall FUN_10003cac(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 8)) {
    do {
                    /* WARNING: Load size is inaccurate */
      iVar1 = lstrcmpiA(*(LPCSTR *)(*this + iVar2 * 4),(LPCSTR)*param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  return -1;
}



// Function: FUN_10003ce3 at 10003ce3

void __fastcall FUN_10003ce3(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10003cf3 at 10003cf3

void __fastcall FUN_10003cf3(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10003d09 at 10003d09

void __fastcall FUN_10003d09(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10003d13 at 10003d13

void __fastcall FUN_10003d13(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10003d1d at 10003d1d

void __fastcall FUN_10003d1d(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_10003d35 at 10003d35

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10003d35(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  *param_3 = 0;
  puVar3 = *(undefined4 **)((int)this + 0x2c);
  if (puVar3 != (undefined4 *)0x0) {
    for (; (int *)*puVar3 != (int *)0x0; puVar3 = puVar3 + 9) {
      if ((puVar3[2] != 0) && (iVar2 = _InlineIsEqualGUID(param_1,(int *)*puVar3), iVar2 != 0)) {
        piVar1 = puVar3 + 4;
        if (*piVar1 == 0) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10015a28);
          iVar4 = 0;
          if (*piVar1 == 0) {
            iVar4 = (*(code *)puVar3[2])(puVar3[3],&DAT_1000eb20,piVar1);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10015a28);
        }
        puVar3 = (undefined4 *)*piVar1;
        if (puVar3 != (undefined4 *)0x0) {
          iVar4 = (**(code **)*puVar3)(puVar3,param_2,param_3);
        }
        if (*param_3 != 0) {
          return iVar4;
        }
        if (iVar4 != 0) {
          return iVar4;
        }
        break;
      }
    }
  }
  iVar4 = FUN_10002959((int *)&DAT_10015a18,param_1,param_2,param_3);
  return iVar4;
}



// Function: FUN_10003dfa at 10003dfa

undefined4 __fastcall FUN_10003dfa(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



// Function: FUN_10003dfe at 10003dfe

int __fastcall FUN_10003dfe(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_10003e06 at 10003e06

HRESULT __thiscall FUN_10003e06(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    ppv = (LPVOID *)((int)this + 0x28);
    HVar1 = 0;
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_1000fc30,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000e5e0,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_10003e52 at 10003e52

void FUN_10003e52(int param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  FUN_10007fe8(param_1 + -4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10003e68 at 10003e68

int __thiscall FUN_10003e68(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 8))) {
                    /* WARNING: Load size is inaccurate */
    return *this + param_1 * 4;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}



// Function: FUN_10003e92 at 10003e92

undefined4 __fastcall FUN_10003e92(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10003e9e at 10003e9e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10003e9e(void *this,undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  size_t sVar5;
  long lVar6;
  wchar_t *pwVar7;
  LPCRITICAL_SECTION lpCriticalSection;
  wchar_t local_140 [8];
  LPCRITICAL_SECTION local_130;
  undefined1 local_12c;
  int *local_128;
  int *local_124;
  int *local_120;
  int *local_11c;
  CHAR local_118 [272];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x120;
  local_8 = 0x10003ead;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10004154;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10015600 + 0x10);
  local_12c = 0;
  local_8 = 0;
  local_130 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  local_12c = 1;
  if (*(int *)((int)this + 0xc) == 0) {
    local_124 = (int *)0x0;
    iVar3 = _InlineIsEqualGUID(&DAT_10015604,*(int **)((int)this + 4));
    if (((iVar3 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      iVar3 = Ordinal_162(*(undefined4 *)((int)this + 4),*(undefined2 *)((int)this + 8),
                          *(undefined2 *)((int)this + 10),param_1,&local_124);
LAB_1000402c:
      if (-1 < iVar3) {
        local_11c = (int *)0x0;
        local_8._0_1_ = 3;
                    /* WARNING: Load size is inaccurate */
        iVar3 = (**(code **)(*local_124 + 0x18))(local_124,*this,&local_11c);
        if (-1 < iVar3) {
          local_128 = local_11c;
          if (local_11c != (int *)0x0) {
            (**(code **)(*local_11c + 4))(local_11c);
          }
          local_120 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,7);
          iVar3 = (**(code **)*local_11c)(local_11c,&DAT_1000e634,&local_120);
          if (-1 < iVar3) {
            FUN_1000110c(&local_128,&local_120);
          }
          piVar1 = local_128;
          local_128 = (int *)0x0;
          *(int **)((int)this + 0xc) = piVar1;
          if (DAT_10015600 == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = DAT_10015600 + 4;
          }
          FUN_10003064(iVar3,FUN_100037de,this);
          local_8._0_1_ = 5;
          if (local_120 != (int *)0x0) {
            (**(code **)(*local_120 + 8))(local_120);
          }
          local_8._0_1_ = 3;
          if (local_128 != (int *)0x0) {
            (**(code **)(*local_128 + 8))(local_128);
          }
        }
        (**(code **)(*local_124 + 8))(local_124);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_11c != (int *)0x0) {
          (**(code **)(*local_11c + 8))(local_11c);
        }
      }
      goto LAB_10004128;
    }
    DVar4 = GetModuleFileNameA(DAT_100159e4,local_118,0x104);
    if ((DVar4 == 0) || (DVar4 == 0x104)) goto LAB_10004128;
    local_11c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    sVar5 = strlen(local_118);
    local_120 = (int *)(sVar5 + 1);
    lVar6 = ATL::AtlMultiply<int>((int *)&local_120,(int)local_120,2);
    piVar1 = local_120;
    if (-1 < lVar6) {
      if (((int)local_120 < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_120), bVar2)) {
        pwVar7 = local_140;
      }
      else {
        pwVar7 = (wchar_t *)FUN_10002658(&local_11c,(ulong)piVar1);
      }
      pwVar7 = AtlA2WHelper(pwVar7,local_118,(uint)piVar1 >> 1,3);
      if (pwVar7 != (wchar_t *)0x0) {
        iVar3 = Ordinal_161(pwVar7,&local_124);
        local_8 = local_8 & 0xffffff00;
        FUN_100017da((int *)&local_11c);
        goto LAB_1000402c;
      }
    }
    local_8 = local_8 & 0xffffff00;
    FUN_100017da((int *)&local_11c);
  }
  else {
LAB_10004128:
    if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) == 0)) {
      FUN_10004512(this,*(int **)((int)this + 0xc));
    }
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
  local_12c = 0;
LAB_10004154:
  FUN_1000a668();
  return;
}



// Function: FUN_10004162 at 10004162

undefined4 __thiscall FUN_10004162(void *this,undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    uVar2 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar2 = FUN_10003e9e(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    piVar1 = *(int **)((int)this + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
      uVar2 = 0;
    }
  }
  return uVar2;
}



// Function: FUN_100041a0 at 100041a0

undefined4 FUN_100041a0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10004162(&PTR_DAT_10015084,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100041c4 at 100041c4

undefined4 FUN_100041c4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10004162(&PTR_DAT_10015068,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100041e8 at 100041e8

undefined4 __thiscall FUN_100041e8(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_10004162(this,param_2,param_3);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10004207 at 10004207

undefined4 FUN_10004207(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_10004224 at 10004224

undefined4 FUN_10004224(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_10004245 at 10004245

int __thiscall FUN_10004245(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 8))) {
    return *(int *)((int)this + 4) + param_1 * 4;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}



// Function: FUN_10004270 at 10004270

undefined4 __cdecl FUN_10004270(LPCSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiA(param_1,(&PTR_DAT_1000ec30)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1000ec34)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_1000429e at 1000429e

bool FUN_1000429e(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_100042d3 at 100042d3

void FUN_100042d3(LONG *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x100042d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_100042e7 at 100042e7

DWORD __fastcall FUN_100042e7(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD DVar3;
  
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  DVar3 = 0;
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    DVar3 = DVar2 & 0xffff | 0x80070000;
    if ((int)DVar2 < 1) {
      DVar3 = DVar2;
    }
  }
  return DVar3;
}



// Function: FUN_10004311 at 10004311

undefined4 __thiscall FUN_10004311(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10015604 = *param_3;
    DAT_10015608 = param_3[1];
    DAT_1001560c = param_3[2];
    DAT_10015610 = param_3[3];
  }
  piVar1 = DAT_10015a24;
  piVar2 = DAT_10015a20;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar1 = DAT_10015a24, piVar2 = DAT_10015a20,
     param_1 != (int *)0x0)) {
    for (; piVar1 = DAT_10015a24, piVar2 = DAT_10015a20, *param_1 != 0; param_1 = param_1 + 9) {
      (*(code *)param_1[8])(1);
    }
  }
  for (; piVar2 < piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x1c))(1);
      piVar1 = DAT_10015a24;
    }
  }
  return 0;
}



// Function: FUN_10004370 at 10004370

void __fastcall FUN_10004370(LPCRITICAL_SECTION param_1)

{
  DWORD DVar1;
  
  DVar1 = FUN_100042e7(param_1);
  if (-1 < (int)DVar1) {
    *(undefined1 *)&param_1[1].DebugInfo = 1;
  }
  return;
}



// Function: InlineIsEqualUnknown at 10004383

/* Library Function - Single Match
    int __stdcall ATL::InlineIsEqualUnknown(struct _GUID const &)
   
   Library: Visual Studio 2012 Release */

int ATL::InlineIsEqualUnknown(_GUID *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((((param_1->Data1 == 0) &&
       (iVar1._0_2_ = param_1->Data2, iVar1._2_2_ = param_1->Data3, iVar1 == 0)) &&
      (*(int *)param_1->Data4 == 0xc0)) && (*(int *)(param_1->Data4 + 4) == 0x46000000)) {
    iVar2 = 1;
  }
  return iVar2;
}



// Function: FUN_100043d3 at 100043d3

void FUN_100043d3(void *param_1,_ATL_INTMAP_ENTRY *param_2,_GUID *param_3,void **param_4)

{
  ATL::AtlInternalQueryInterface(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100043ec at 100043ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_100043ec(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &LAB_1000cab7;
                    /* WARNING: Load size is inaccurate */
  puVar2 = (undefined4 *)(*this + param_1 * 4);
  if (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined1 *)*param_2;
    *puVar2 = puVar1;
  }
  puVar2 = (undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
  if (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined1 *)*param_3;
    *puVar2 = puVar1;
  }
  return puVar1;
}



// Function: FUN_10004440 at 10004440

void FUN_10004440(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  FUN_100083e1(param_1 + -4,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



// Function: FUN_1000444a at 1000444a

undefined4 __cdecl FUN_1000444a(LPCSTR param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = lstrcmpiA(param_1,param_2);
  return CONCAT31((int3)((uint)-iVar1 >> 8),'\x01' - (iVar1 != 0));
}



// Function: FUN_10004461 at 10004461

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_10004461(void *this,int *param_1)

{
  int *piVar1;
  bool bVar2;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 4;
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (param_1 == (int *)0x0) {
      return true;
    }
  }
  else if (param_1 != (int *)0x0) {
    local_14[0] = (int *)0x0;
    param_1 = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
                    /* WARNING: Load size is inaccurate */
    (**(code **)**this)(*this,&DAT_1000eb20,local_14);
    (**(code **)*piVar1)(piVar1,&DAT_1000eb20,&param_1);
    bVar2 = local_14[0] == param_1;
    local_8 = CONCAT31(local_8._1_3_,1);
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    local_8 = 0xffffffff;
    if (local_14[0] == (int *)0x0) {
      return bVar2;
    }
    (**(code **)(*local_14[0] + 8))(local_14[0]);
    return bVar2;
  }
  return false;
}



// Function: FUN_100044e8 at 100044e8

undefined4 FUN_100044e8(char param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < '\t') || ((('\n' < param_1 && (param_1 != '\r')) && (param_1 != ' ')))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// Function: FUN_10004512 at 10004512

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10004512(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x1000451e;
  iVar3 = (**(code **)(*param_1 + 0xc))(param_1,&local_1c);
  if (-1 < iVar3) {
    piVar5 = (int *)0x0;
    param_1 = (int *)(uint)*(ushort *)(local_1c + 0x2c);
    *(undefined4 *)((int)this + 0x14) = 0;
    local_18 = (int *)0x0;
    *(int **)((int)this + 0x18) = param_1;
    if (param_1 != (int *)0x0) {
      puVar4 = (undefined4 *)
               FUN_1000a5d0(-(uint)(0xfffffffb < (uint)((int)param_1 * 0xc)) |
                            (int)param_1 * 0xc + 4U);
      local_8 = 0;
      if (puVar4 == (undefined4 *)0x0) {
        piVar5 = (int *)0x0;
        local_18 = (int *)0x0;
      }
      else {
        piVar5 = puVar4 + 1;
        *puVar4 = param_1;
        local_18 = piVar5;
        _eh_vector_constructor_iterator_
                  (piVar5,0xc,(int)param_1,(_func_void_void_ptr *)&LAB_10001793,
                   (_func_void_void_ptr *)&LAB_10001bd7);
      }
      local_8 = 0xffffffff;
      if (piVar5 == (int *)0x0) {
        (**(code **)(*piVar1 + 0x4c))(piVar1,local_1c);
        return 0x8007000e;
      }
    }
    local_20 = 0;
    piVar6 = piVar5;
    piVar2 = piVar5;
    if (0 < *(int *)((int)this + 0x18)) {
      do {
        param_1 = piVar2;
        iVar3 = (**(code **)(*piVar1 + 0x14))(piVar1,local_20,local_14);
        if (-1 < iVar3) {
          param_1 = (int *)0x0;
          local_8 = 1;
          iVar3 = (**(code **)(*piVar1 + 0x30))(piVar1,*local_14[0],&param_1,0,0,0);
          piVar6 = param_1;
          if (-1 < iVar3) {
            param_1 = (int *)0x0;
            if ((int *)*piVar5 != piVar6) {
              Ordinal_6(*piVar5);
              *piVar5 = (int)piVar6;
            }
            iVar3 = Ordinal_7(*piVar5);
            piVar5[1] = iVar3;
            piVar5[2] = *local_14[0];
          }
          (**(code **)(*piVar1 + 0x50))(piVar1,local_14[0]);
          local_8 = 0xffffffff;
          Ordinal_6(param_1);
        }
        local_20 = local_20 + 1;
        piVar5 = piVar5 + 3;
        piVar6 = local_18;
        piVar2 = param_1;
      } while (local_20 < *(int *)((int)this + 0x18));
    }
    *(int **)((int)this + 0x14) = piVar6;
    (**(code **)(*piVar1 + 0x4c))(piVar1,local_1c);
  }
  return 0;
}



// Function: FUN_10004674 at 10004674

undefined4 __fastcall FUN_10004674(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 1;
  return 0;
}



// Function: FUN_10004687 at 10004687

void __fastcall FUN_10004687(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000469f at 1000469f

undefined4 FUN_1000469f(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10015600 + 8))();
  }
  else {
    (**(code **)(*DAT_10015600 + 4))();
  }
  return 0;
}



// Function: FUN_100046be at 100046be

undefined4 __thiscall FUN_100046be(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_10003cac(this,param_1);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_10004245(this,iVar1);
    uVar2 = *puVar3;
  }
  return uVar2;
}



// Function: FUN_100046e4 at 100046e4

void FUN_100046e4(int param_1)

{
  FUN_10008467((int *)(param_1 + -4));
  return;
}



// Function: FUN_100046ee at 100046ee

void FUN_100046ee(int param_1)

{
  FUN_1000853c((int *)(param_1 + -4));
  return;
}



// Function: FUN_100046f8 at 100046f8

void FUN_100046f8(int param_1)

{
  FUN_10008611((int *)(param_1 + -4));
  return;
}



// Function: FUN_10004702 at 10004702

void FUN_10004702(int param_1)

{
  FUN_100086dd((int *)(param_1 + -4));
  return;
}



// Function: FUN_1000470c at 1000470c

undefined4 __thiscall FUN_1000470c(void *this,undefined1 *param_1)

{
  char cVar1;
  LPCSTR pCVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  LPSTR pCVar6;
  int iVar7;
  undefined1 *puVar8;
  
  FUN_10005dce((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  cVar1 = **this;
  if (cVar1 == '\0') {
    uVar3 = 0x80020009;
  }
  else {
    puVar8 = param_1;
    if (cVar1 == '\'') {
      pcVar4 = CharNextA(*this);
      *(char **)this = pcVar4;
      while ((*pcVar4 != '\0' && (iVar5 = FUN_10003bb9((undefined4 *)this), iVar5 == 0))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == '\'') {
          pCVar6 = CharNextA(*this);
          *(LPSTR *)this = pCVar6;
        }
                    /* WARNING: Load size is inaccurate */
        pCVar2 = *this;
        pCVar6 = CharNextA(pCVar2);
        *(LPSTR *)this = pCVar6;
        iVar5 = (int)pCVar6 - (int)pCVar2;
        if (param_1 + 0x1000 <= puVar8 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar7 = (int)pCVar2 - (int)puVar8;
          do {
            *puVar8 = puVar8[iVar7];
            puVar8 = puVar8 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
                    /* WARNING: Load size is inaccurate */
        pcVar4 = *this;
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == '\0') {
        return 0x80020009;
      }
      *puVar8 = 0;
                    /* WARNING: Load size is inaccurate */
      pCVar6 = CharNextA(*this);
      *(LPSTR *)this = pCVar6;
    }
    else {
      do {
                    /* WARNING: Load size is inaccurate */
        pCVar2 = *this;
        iVar5 = FUN_100044e8(*pCVar2);
        if (iVar5 != 0) break;
        pCVar6 = CharNextA(pCVar2);
        *(LPSTR *)this = pCVar6;
        iVar5 = (int)pCVar6 - (int)pCVar2;
        if (param_1 + 0x1000 <= puVar8 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar7 = (int)pCVar2 - (int)puVar8;
          do {
            *puVar8 = puVar8[iVar7];
            puVar8 = puVar8 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
                    /* WARNING: Load size is inaccurate */
      } while (**this != '\0');
      *puVar8 = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



// Function: FUN_1000481b at 1000481b

int __thiscall FUN_1000481b(void *this,HKEY param_1,LPCSTR param_2,REGSAM param_3)

{
  int iVar1;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  if (*(int *)((int)this + 8) == 0) {
    iVar1 = RegOpenKeyExA(param_1,param_2,0,param_3,&local_8);
  }
  else {
    iVar1 = FID_conflict_RegOpenKeyExA(param_1,param_2,0,param_3,&local_8);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_10003860((int *)this);
    *(HKEY *)this = local_8;
  }
  return iVar1;
}



// Function: FUN_1000486d at 1000486d

void __thiscall FUN_1000486d(void *this,undefined4 param_1,undefined4 param_2)

{
                    /* WARNING: Load size is inaccurate */
  (**(code **)**this)(*this,param_1,param_2);
  return;
}



// Function: FUN_1000488a at 1000488a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000488a(void *this,char *param_1,int *param_2)

{
  char cVar1;
  LPVOID pvVar2;
  size_t sVar3;
  int iVar4;
  uchar *puVar5;
  undefined4 uVar6;
  int iVar7;
  LPCSTR pCVar8;
  LPSTR pCVar9;
  errno_t eVar10;
  wchar_t *pwVar11;
  LPCSTR pCVar12;
  char *pcVar13;
  code *pcVar14;
  uchar *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  LPVOID local_44;
  LPCSTR local_40;
  int local_3c;
  char local_37;
  char local_36;
  char local_35;
  uchar local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x10004896;
  if ((param_1 != (char *)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    sVar3 = strlen(param_1);
    FUN_100016c3(&local_4c,sVar3 * 2);
    local_8 = 0;
    if (local_44 != (LPVOID)0x0) {
      *(char **)this = param_1;
      local_37 = '\0';
      iVar4 = FUN_10002c6f(&local_37);
      if (-1 < iVar4) {
        local_3c = 0;
        local_36 = '\0';
        local_35 = '\0';
        cVar1 = *param_1;
        pcVar14 = CharNextA_exref;
        while (cVar1 != '\0') {
          if (local_37 == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            if (((local_3c == 0) && (puVar5 = _mbsstr(*this,"HKCR"), puVar5 != (uchar *)0x0)) &&
               (puVar5 == *this)) {
                    /* WARNING: Load size is inaccurate */
              uVar6 = (*pcVar14)(*this);
              *(undefined4 *)this = uVar6;
              uVar6 = (*pcVar14)(uVar6);
              *(undefined4 *)this = uVar6;
              uVar6 = (*pcVar14)(uVar6);
              *(undefined4 *)this = uVar6;
              uVar6 = (*pcVar14)(uVar6);
              *(undefined4 *)this = uVar6;
              iVar7 = FUN_10002126(&local_4c,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
              if (iVar7 == 0) goto LAB_10004af0;
              local_36 = '\x01';
            }
                    /* WARNING: Load size is inaccurate */
            if (**this == '\'') {
              if (local_35 != '\0') {
                iVar7 = FUN_10003bb9((undefined4 *)this);
                if (iVar7 != 0) {
                  local_35 = '\0';
                  goto LAB_100049b0;
                }
                    /* WARNING: Load size is inaccurate */
                pCVar8 = (LPCSTR)(*pcVar14)(*this);
                *(LPCSTR *)this = pCVar8;
                pCVar9 = CharNextA(pCVar8);
                iVar7 = FUN_100027fe(&local_4c,pCVar8,(int)pCVar9 - (int)pCVar8);
                pcVar14 = CharNextA_exref;
                if (iVar7 != 0) goto LAB_100049ac;
                goto LAB_10004af0;
              }
              local_35 = '\x01';
            }
            else {
LAB_100049ac:
              if (local_35 == '\0') {
LAB_100049b0:
                    /* WARNING: Load size is inaccurate */
                if (**this == '{') {
                  local_3c = local_3c + 1;
                }
                if (((**this == '}') && (local_3c = local_3c + -1, local_3c == 0)) &&
                   (local_36 == '\x01')) {
                  iVar7 = FUN_10002126(&local_4c,L"\r\n\t}\r\n}\r\n");
                  if (iVar7 == 0) goto LAB_10004af0;
                  local_36 = '\0';
                }
              }
            }
          }
                    /* WARNING: Load size is inaccurate */
          local_50 = *this;
          if (*local_50 == '%') {
            local_40 = (LPCSTR)(*pcVar14)(local_50);
            *(LPCSTR *)this = local_40;
            if (*local_40 == '%') {
              iVar7 = (*pcVar14)(local_40);
              iVar7 = FUN_100027fe(&local_4c,local_40,iVar7 - (int)local_40);
              if (iVar7 == 0) goto LAB_10004af0;
            }
            else {
              local_40 = FUN_10005df0(local_40,'%');
                    /* WARNING: Load size is inaccurate */
              if ((local_40 == (char *)0x0) || (0x1f < (int)local_40 - *this)) goto LAB_10004af0;
                    /* WARNING: Load size is inaccurate */
              eVar10 = _mbsnbcpy_s(local_34,0x20,*this,(int)local_40 - *this);
              ATL::AtlCrtErrorCheck(eVar10);
              local_50 = local_34;
              pwVar11 = (wchar_t *)FUN_100046be((void *)(*(int *)((int)this + 4) + 4),&local_50);
              if ((pwVar11 == (wchar_t *)0x0) ||
                 (iVar7 = FUN_10002126(&local_4c,pwVar11), pCVar8 = local_40, iVar7 == 0))
              goto LAB_10004af0;
                    /* WARNING: Load size is inaccurate */
              pCVar12 = *this;
              while (pCVar12 != pCVar8) {
                    /* WARNING: Load size is inaccurate */
                pCVar12 = (LPCSTR)(*pcVar14)(*this);
                *(LPCSTR *)this = pCVar12;
              }
            }
          }
          else {
            iVar7 = (*pcVar14)(local_50);
            iVar7 = FUN_100027fe(&local_4c,local_50,iVar7 - (int)local_50);
            if (iVar7 == 0) {
              iVar4 = -0x7ff8fff2;
              break;
            }
          }
                    /* WARNING: Load size is inaccurate */
          pcVar13 = (char *)(*pcVar14)(*this);
          *(char **)this = pcVar13;
          cVar1 = *pcVar13;
        }
        pvVar2 = local_44;
        if (-1 < iVar4) {
          local_44 = (LPVOID)0x0;
          local_4c = 0;
          local_48 = 0;
          *param_2 = (int)pvVar2;
        }
      }
    }
LAB_10004af0:
    local_8 = 0xffffffff;
    CoTaskMemFree(local_44);
  }
  FUN_1000a668();
  return;
}



// Function: FUN_10004b0e at 10004b0e

long FUN_10004b0e(int *param_1,_GUID *param_2,void **param_3)

{
  long lVar1;
  int iVar2;
  
  if (param_3 == (void **)0x0) {
    lVar1 = -0x7fffbffd;
  }
  else {
    lVar1 = 0;
    *param_3 = (void *)0x0;
    iVar2 = ATL::InlineIsEqualUnknown(param_2);
    if (iVar2 == 0) {
      lVar1 = ATL::AtlInternalQueryInterface
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000eeac,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar1;
}



// Function: FUN_10004b5d at 10004b5d

void FUN_10004b5d(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))(*(undefined4 **)(param_1 + 0xc),param_2,param_3);
  return;
}



// Function: FUN_10004b75 at 10004b75

void FUN_10004b75(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10004b5d(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10004b7f at 10004b7f

void FUN_10004b7f(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10004b5d(param_1 + -8,param_2,param_3);
  return;
}



// Function: QueryInterface at 10004b89

/* Library Function - Single Match
    public: virtual long __stdcall ATL::CComObjectNoLock<class
   ATL::CAccessibleProxy>::QueryInterface(struct _GUID const &,void * *)
   
   Library: Visual Studio 2012 Release */

long ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::QueryInterface
               (_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000eeac,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10004ba3 at 10004ba3

void FUN_10004ba3(int param_1,void **param_2)

{
  ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::QueryInterface
            ((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10004bad at 10004bad

void FUN_10004bad(int param_1,void **param_2)

{
  ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::QueryInterface
            ((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: QueryInterface at 10004bb7

/* Library Function - Single Match
    public: virtual long __stdcall ATL::CComObjectNoLock<class
   ATL::CAccessibleProxy>::QueryInterface(struct _GUID const &,void * *)
   
   Library: Visual Studio 2012 Release */

long ATL::CComObjectNoLock<class_ATL::CAccessibleProxy>::QueryInterface
               (_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000ee94,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10004bd1 at 10004bd1

undefined4 FUN_10004bd1(void)

{
  return 0x80004001;
}



// Function: FUN_10004bd9 at 10004bd9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10004bd9(void *this,LPCSTR param_1)

{
  int iVar1;
  LSTATUS LVar2;
  _FILETIME local_12c;
  HKEY local_124;
  undefined4 local_120;
  undefined4 local_11c;
  DWORD local_118;
  CHAR local_114 [268];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x11c;
  local_124 = (HKEY)0x0;
  local_120 = 0;
  local_11c = 0;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = FUN_1000481b(&local_124,*this,param_1,*(uint *)((int)this + 4) | 0x2001f);
  do {
    if (iVar1 != 0) {
LAB_10004c79:
      local_8 = 0xffffffff;
      FUN_10003860((int *)&local_124);
      FUN_1000a668();
      return;
    }
    local_118 = 0x100;
    LVar2 = RegEnumKeyExA(local_124,0,local_114,&local_118,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                          &local_12c);
    if (LVar2 != 0) {
      FUN_10003860((int *)&local_124);
      FUN_10003b52(this,param_1);
      goto LAB_10004c79;
    }
    iVar1 = FUN_10004bd9(&local_124,local_114);
  } while( true );
}



// Function: FID_conflict:RegCreateKeyExW at 10004c92

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
                    /* WARNING: Could not recover jumptable at 0x10004ce7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegCreateKeyExA(hKey,(LPCSTR)lpSubKey,Reserved,(LPSTR)lpClass,dwOptions,samDesired,
                              lpSecurityAttributes,phkResult,lpdwDisposition);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if ((hModule != (HMODULE)0x0) &&
       (pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedA"), pFVar1 != (FARPROC)0x0)) {
      iVar2 = (*pFVar1)(hKey,lpSubKey,Reserved,lpClass,dwOptions,samDesired,lpSecurityAttributes,
                        phkResult,lpdwDisposition,*in_ECX,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FID_conflict:RegDeleteKeyA at 10004cf5

/* Library Function - Multiple Matches With Different Base Names
    public: long __thiscall ATL::CAtlTransactionManager::RegDeleteKeyA(struct HKEY__ *,char const *)
    public: long __thiscall ATL::CAtlTransactionManager::RegDeleteKeyW(struct HKEY__ *,wchar_t const
   *)
   
   Library: Visual Studio 2012 Release */

LSTATUS FID_conflict_RegDeleteKeyA(HKEY hKey,LPCSTR lpSubKey)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    if (in_ECX[1] != 0) {
                    /* WARNING: Could not recover jumptable at 0x10004d38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegDeleteKeyA(hKey,lpSubKey);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if ((hModule != (HMODULE)0x0) &&
       (pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedA"), pFVar1 != (FARPROC)0x0)) {
      iVar2 = (*pFVar1)(hKey,lpSubKey,0,0,*in_ECX,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FID_conflict:RegOpenKeyExA at 10004d47

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
                    /* WARNING: Could not recover jumptable at 0x10004d90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegOpenKeyExA(hKey,lpSubKey,ulOptions,samDesired,phkResult);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if ((hModule != (HMODULE)0x0) &&
       (pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedA"), pFVar1 != (FARPROC)0x0)) {
      iVar2 = (*pFVar1)(hKey,lpSubKey,ulOptions,samDesired,phkResult,*in_ECX,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_10004d9e at 10004d9e

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10004d9e(void *this,char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  HKEY pv;
  int iVar3;
  HKEY local_100c;
  char local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100155d8 ^ (uint)&stack0xfffffffc;
  local_100c = (HKEY)0x0;
  iVar3 = FUN_1000488a(this,param_1,(int *)&local_100c);
  pv = local_100c;
  if (iVar3 < 0) {
LAB_10004ece:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(HKEY *)this = local_100c;
  cVar1 = (char)local_100c->unused;
joined_r0x10004de8:
  if ((((cVar1 == '\0') || (iVar3 = FUN_1000470c(this,local_1008), iVar3 < 0)) ||
      (local_100c = (HKEY)FUN_10004270(local_1008), local_100c == (HKEY)0x0)) ||
     ((iVar3 = FUN_1000470c(this,local_1008), iVar3 < 0 || (local_1008[0] != '{'))))
  goto LAB_10004ec4;
  if (param_2 == 0) {
    iVar3 = FUN_100051b1(this,(LPCWSTR)local_1008,local_100c,0,0);
    if (iVar3 < 0) goto LAB_10004ec4;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_100051b1(this,(LPCWSTR)local_1008,local_100c,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_100051b1(this,(LPCWSTR)local_1008,local_100c,0,0);
LAB_10004ec4:
      CoTaskMemFree(pv);
      goto LAB_10004ece;
    }
  }
  FUN_10005dce((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  cVar1 = **this;
  goto joined_r0x10004de8;
}



// Function: FUN_10004ede at 10004ede

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_10004ede(void *this,wchar_t *param_1,LPCSTR param_2,LPCSTR param_3)

{
  uint3 uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  HMODULE pHVar6;
  HRSRC hResInfo;
  char acStack_444 [16];
  undefined4 local_434;
  void *local_430;
  int local_42c;
  LPCSTR local_428;
  LPCSTR local_424;
  HMODULE local_420;
  undefined1 *local_41c;
  undefined1 auStack_418 [1028];
  undefined1 *local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x424;
  local_428 = param_2;
  local_424 = param_3;
  local_42c = 0;
  local_434 = 0;
  local_41c = (undefined1 *)0x0;
  local_8._1_3_ = 0;
  uVar1 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_430 = this;
  if (param_1 != (wchar_t *)0x0) {
    sVar3 = wcslen(param_1);
    local_420 = (HMODULE)(sVar3 + 1);
    lVar4 = ATL::AtlMultiply<int>((int *)&local_420,(int)local_420,2);
    pHVar6 = local_420;
    uVar1 = local_8._1_3_;
    if (-1 < lVar4) {
      if (((int)local_420 < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_420), bVar2)) {
        local_14 = acStack_444;
        pcVar5 = acStack_444;
      }
      else {
        pcVar5 = (char *)FUN_10002658(&local_42c,(ulong)pHVar6);
      }
      pcVar5 = AtlW2AHelper(pcVar5,param_1,(int)pHVar6,3);
      uVar1 = local_8._1_3_;
      if (pcVar5 != (char *)0x0) {
        pHVar6 = LoadLibraryExA(pcVar5,(HANDLE)0x0,0x60);
        if ((pHVar6 == (HMODULE)0x0) &&
           (local_420 = pHVar6, pHVar6 = LoadLibraryExA(pcVar5,(HANDLE)0x0,2),
           pHVar6 == (HMODULE)0x0)) {
          local_420 = pHVar6;
          FUN_10002c8d();
        }
        else {
          local_420 = pHVar6;
          hResInfo = FindResourceA(pHVar6,local_428,local_424);
          if ((hResInfo == (HRSRC)0x0) ||
             (local_424 = (LPCSTR)LoadResource(pHVar6,hResInfo), local_424 == (LPCSTR)0x0)) {
            FUN_10002c8d();
          }
          else {
            local_428 = (LPCSTR)SizeofResource(pHVar6,hResInfo);
            if (local_428 <= local_428 + 1) {
              local_8 = CONCAT31(local_8._1_3_,2);
              Allocate(&local_41c,(uint)(local_428 + 1));
              local_8 = 1;
              FUN_10005059();
              return;
            }
          }
          if (pHVar6 != (HMODULE)0x0) {
            FreeLibrary(pHVar6);
          }
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_41c != auStack_418) {
          FUN_10003d13(&local_41c);
        }
        goto LAB_100050e1;
      }
    }
  }
  local_8._1_3_ = uVar1;
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_10003d13(&local_41c);
  }
LAB_100050e1:
  local_8 = 0xffffffff;
  FUN_100017da(&local_42c);
  FUN_1000a677();
  return;
}



// Function: Catch@1000503e at 1000503e

undefined * Catch_1000503e(void)

{
  return &DAT_10005044;
}



// Function: FUN_10005059 at 10005059

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10005059(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  rsize_t unaff_ESI;
  HMODULE unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x418) != 0) {
    FUN_100067c4(*(void **)(unaff_EBP + -0x418),unaff_ESI,*(void **)(unaff_EBP + -0x420),unaff_ESI);
    *(undefined1 *)(*(int *)(unaff_EBP + -0x418) + unaff_ESI) = unaff_BL;
    FUN_10004d9e((void *)(unaff_EBP + -0x430),*(char **)(unaff_EBP + -0x418),
                 *(int *)(unaff_EBP + 0x14));
  }
  if (unaff_EDI != (HMODULE)0x0) {
    FreeLibrary(unaff_EDI);
  }
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_10003d13((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_100017da((int *)(unaff_EBP + -0x428));
  *(undefined4 *)(unaff_EBP + -0x444) = 0x100050fd;
  FUN_1000a677();
  return;
}



// Function: FUN_10005100 at 10005100

void FUN_10005100(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10002a62(0x10015a18,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10015618 != (code *)0x0)) {
    (*DAT_10015618)(DAT_100159e4);
  }
  return;
}



// Function: FUN_1000512e at 1000512e

void __thiscall FUN_1000512e(void *this,int param_1,void *param_2)

{
  FUN_10002a62((int)this,param_1,param_2);
  return;
}



// Function: FUN_10005141 at 10005141

int __thiscall FUN_10005141(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_1000699e(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_100030e1((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_10005100(param_1,param_2);
  return iVar5;
}



// Function: FUN_100051b1 at 100051b1

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100051b1(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  HKEY pHVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  errno_t eVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t sVar8;
  HKEY *ppHVar9;
  HKEY local_1160;
  undefined4 local_115c;
  undefined4 local_1158;
  HKEY local_1154;
  undefined4 local_1150;
  undefined4 local_114c;
  HKEY local_1148;
  undefined4 local_1144;
  undefined4 local_1140;
  int local_113c;
  HKEY local_1138;
  undefined4 local_1134;
  undefined4 local_1130;
  HKEY local_112c;
  undefined4 local_1128;
  undefined4 local_1124;
  HKEY local_1120;
  uint local_111c;
  char local_1118 [4096];
  uchar local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1000cc25;
  local_10 = ExceptionList;
  local_14 = DAT_100155d8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1120 = param_2;
  local_112c = (HKEY)0x0;
  local_1128 = 0;
  local_1124 = 0;
  local_8 = 0;
LAB_10005211:
  iVar3 = FUN_1000470c(this,(undefined1 *)param_1);
  do {
    if (iVar3 < 0) {
LAB_10005791:
      local_8 = 0xffffffff;
      FUN_10003860((int *)&local_112c);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_10005223:
    if ((char)*param_1 == '}') goto LAB_10005791;
    local_113c = 1;
    iVar3 = lstrcmpiA((LPCSTR)param_1,"Delete");
    local_111c = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiA((LPCSTR)param_1,"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_1000470c(this,(undefined1 *)param_1);
      if (iVar3 < 0) goto LAB_10005791;
      if (param_3 == 0) goto LAB_1000533c;
      local_1138 = (HKEY)0x0;
      local_1134 = 0;
      local_1130 = 0;
      local_8._0_1_ = 1;
      pcVar5 = FUN_10005df0((LPCSTR)param_1,'\\');
      if (pcVar5 == (char *)0x0) {
        iVar3 = FUN_10003772((LPCSTR)param_1);
        if (iVar3 != 0) {
          local_1134 = 0;
          local_1130 = 0;
          local_1138 = local_1120;
          FUN_10004bd9(&local_1138,(LPCSTR)param_1);
          local_1138 = (HKEY)0x0;
          local_1134 = 0;
          local_1130 = 0;
        }
        if (local_111c == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10003860((int *)&local_1138);
          goto LAB_1000533c;
        }
        iVar3 = FUN_1000470c(this,(undefined1 *)param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10005d6a(this,(char *)param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          ppHVar9 = &local_1138;
          goto LAB_1000572b;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar9 = &local_1138;
        goto LAB_100057dc;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10003860((int *)&local_1138);
      goto LAB_10005791;
    }
LAB_1000533c:
    iVar3 = lstrcmpiA((LPCSTR)param_1,"NoRemove");
    if (iVar3 == 0) {
      local_113c = 0;
      iVar3 = FUN_1000470c(this,(undefined1 *)param_1);
      if (iVar3 < 0) goto LAB_10005791;
    }
    iVar3 = lstrcmpiA((LPCSTR)param_1,"Val");
    if (iVar3 != 0) {
      pcVar5 = FUN_10005df0((LPCSTR)param_1,'\\');
      pHVar1 = local_1120;
      if (pcVar5 == (char *)0x0) {
        if (param_3 == 0) {
          if (param_4 == 0) {
            local_111c = FUN_1000481b(&local_112c,local_1120,(LPCSTR)param_1,0x20019);
          }
          else {
            local_111c = 2;
          }
          iVar3 = param_4;
          if (local_111c != 0) {
            iVar3 = 1;
          }
          eVar7 = _mbsnbcpy_s(local_118,0x104,(uchar *)param_1,0xffffffff);
          ATL::AtlCrtErrorCheck(eVar7);
          iVar4 = FUN_1000470c(this,(undefined1 *)param_1);
          if (((-1 < iVar4) && (iVar4 = FUN_10005d6a(this,(char *)param_1), -1 < iVar4)) &&
             ((((char)*param_1 != '{' || (sVar8 = strlen((char *)param_1), sVar8 != 1)) ||
              (((iVar4 = FUN_100051b1(this,param_1,local_112c,0,iVar3), -1 < iVar4 || (iVar3 != 0))
               && (iVar3 = FUN_1000470c(this,(undefined1 *)param_1), -1 < iVar3)))))) break;
        }
        else {
          iVar3 = FUN_1000481b(&local_112c,local_1120,(LPCSTR)param_1,0x2001f);
          if (((iVar3 != 0) &&
              (iVar3 = FUN_1000481b(&local_112c,pHVar1,(LPCSTR)param_1,0x20019), iVar3 != 0)) &&
             (uVar6 = FUN_1000387a(&local_112c,pHVar1,param_1,(LPWSTR)0x0,0,0x2001f,
                                   (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_1000562d;
          iVar3 = FUN_1000470c(this,(undefined1 *)param_1);
          if ((-1 < iVar3) &&
             (((char)*param_1 != '=' ||
              (iVar3 = FUN_100021f0(this,(CRegKey *)&local_112c,(char *)0x0,(undefined1 *)param_1),
              -1 < iVar3)))) goto LAB_10005730;
        }
      }
      goto LAB_10005791;
    }
    iVar3 = FUN_1000470c(this,local_1118);
    if (((iVar3 < 0) || (iVar3 = FUN_1000470c(this,(undefined1 *)param_1), iVar3 < 0)) ||
       ((char)*param_1 != '=')) goto LAB_10005791;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_1154 = local_1120;
      local_1150 = 0;
      local_114c = 0;
      iVar3 = FUN_100021f0(this,(CRegKey *)&local_1154,local_1118,(undefined1 *)param_1);
      local_1154 = (HKEY)0x0;
      local_1150 = 0;
      local_114c = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar9 = &local_1154;
        goto LAB_1000572b;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ppHVar9 = &local_1154;
      goto LAB_100057dc;
    }
    if ((param_4 == 0) && (local_113c != 0)) {
      local_1160 = (HKEY)0x0;
      local_115c = 0;
      local_1158 = 0;
      local_8._0_1_ = 3;
      uVar6 = FUN_1000481b(&local_1160,local_1120,(LPCSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueA(local_1160,local_1118), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10002ca4(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        ppHVar9 = &local_1160;
LAB_100057dc:
        FUN_10003860((int *)ppHVar9);
        goto LAB_10005791;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10003860((int *)&local_1160);
    }
    iVar3 = FUN_10005d6a(this,(char *)param_1);
  } while( true );
  if (local_111c != 2) {
    if (local_111c == 0) {
      if ((param_4 != 0) && (bVar2 = FUN_1000429e(local_112c), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_10003772((LPCSTR)local_118);
        if ((iVar3 != 0) && (local_113c != 0)) {
          FUN_10004bd9(&local_112c,(LPCSTR)local_118);
        }
        goto LAB_10005223;
      }
      bVar2 = FUN_1000429e(local_112c);
      local_111c = CONCAT31(extraout_var_00,bVar2);
      uVar6 = FUN_10003860((int *)&local_112c);
      if (uVar6 == 0) {
        if ((local_113c != 0) && (local_111c == 0)) {
          local_8._0_1_ = 4;
          local_1148 = local_1120;
          local_1144 = 0;
          local_1140 = 0;
          uVar6 = FUN_10003b52(&local_1148,(LPCSTR)local_118);
          local_1148 = (HKEY)0x0;
          local_1144 = 0;
          local_1140 = 0;
          if (uVar6 != 0) {
            FUN_10002ca4(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            ppHVar9 = &local_1148;
            goto LAB_100057dc;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          ppHVar9 = &local_1148;
LAB_1000572b:
          FUN_10003860((int *)ppHVar9);
LAB_10005730:
          if (((param_3 != 0) && ((char)*param_1 == '{')) &&
             (sVar8 = strlen((char *)param_1), sVar8 == 1)) {
            iVar3 = FUN_100051b1(this,param_1,local_112c,param_3,0);
            if (-1 < iVar3) goto LAB_10005211;
            goto LAB_10005791;
          }
        }
        goto LAB_10005223;
      }
    }
    else {
      uVar6 = local_111c;
      if (param_4 != 0) goto LAB_10005223;
    }
LAB_1000562d:
    FUN_10002ca4(uVar6);
    goto LAB_10005791;
  }
  goto LAB_10005223;
}



// Function: Release at 100057f8

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CAudioMediaType::Release(void)
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2012 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_10005825 at 10005825

void FUN_10005825(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(int **)(param_1 + 0xc));
  return;
}



// Function: FUN_10005838 at 10005838

void FUN_10005838(int param_1)

{
  FUN_10005825(param_1 + -4);
  return;
}



// Function: FUN_10005842 at 10005842

void FUN_10005842(int param_1)

{
  FUN_10005825(param_1 + -8);
  return;
}



// Function: Release at 1000584c

/* Library Function - Multiple Matches With Same Base Name
    public: virtual unsigned long __stdcall CAudioMediaType::Release(void)
    public: virtual unsigned long __stdcall CEnumMediaTypes::Release(void)
    public: virtual unsigned long __stdcall CEnumPins::Release(void)
   
   Library: Visual Studio 2012 Release */

LONG Release(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return LVar1;
}



// Function: FUN_10005879 at 10005879

void FUN_10005879(int param_1)

{
  Release((int *)(param_1 + -4));
  return;
}



// Function: FUN_10005883 at 10005883

void FUN_10005883(int param_1)

{
  Release((int *)(param_1 + -8));
  return;
}



// Function: FUN_1000588d at 1000588d

LONG FUN_1000588d(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10015600 + 8))();
  }
  return LVar1;
}



// Function: FUN_100058cc at 100058cc

void __fastcall FUN_100058cc(int *param_1)

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



// Function: FUN_100058eb at 100058eb

void __fastcall FUN_100058eb(int *param_1)

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



// Function: FUN_1000590a at 1000590a

undefined4 FUN_1000590a(void)

{
  return 0;
}



// Function: FUN_1000590f at 1000590f

void __fastcall FUN_1000590f(int *param_1)

{
  if (*param_1 != 0) {
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



// Function: FUN_1000593d at 1000593d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000593d(void *param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  ulong uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  char local_2c [16];
  int local_1c;
  ulong local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_1c = 0;
  local_8 = 0;
  if (param_4 != (wchar_t *)0x0) {
    sVar3 = wcslen(param_4);
    local_18[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar1 = local_18[0];
    if (-1 < lVar4) {
      if (((int)local_18[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
        pcVar5 = local_2c;
      }
      else {
        pcVar5 = (char *)FUN_10002658(&local_1c,uVar1);
      }
      pcVar5 = AtlW2AHelper(pcVar5,param_4,uVar1,3);
      if (pcVar5 != (char *)0x0) {
        FUN_10004ede(param_1,param_2,(LPCSTR)(uint)param_3,pcVar5);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_100017da(&local_1c);
  FUN_1000a668();
  return;
}



// Function: FUN_100059e6 at 100059e6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_100059e6(void *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  ulong uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  char local_2c [16];
  int local_1c;
  ulong local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  pcVar5 = (LPCSTR)0x0;
  local_1c = 0;
  local_8 = 0;
  if ((param_3 != (wchar_t *)0x0) && (param_4 != (wchar_t *)0x0)) {
    sVar3 = wcslen(param_3);
    local_18[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar1 = local_18[0];
    if (lVar4 < 0) {
      pcVar6 = (LPCSTR)0x0;
    }
    else {
      if (((int)local_18[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
        pcVar6 = local_2c;
      }
      else {
        pcVar6 = (char *)FUN_10002658(&local_1c,uVar1);
      }
      pcVar6 = AtlW2AHelper(pcVar6,param_3,uVar1,3);
    }
    sVar3 = wcslen(param_4);
    local_18[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar1 = local_18[0];
    if (-1 < lVar4) {
      if (((int)local_18[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
        pcVar5 = local_2c;
      }
      else {
        pcVar5 = (char *)FUN_10002658(&local_1c,uVar1);
      }
      pcVar5 = AtlW2AHelper(pcVar5,param_4,uVar1,3);
    }
    if ((pcVar6 != (LPCSTR)0x0) && (pcVar5 != (LPCSTR)0x0)) {
      FUN_10004ede(param_1,param_2,pcVar6,pcVar5);
    }
  }
  local_8 = 0xffffffff;
  FUN_100017da(&local_1c);
  FUN_1000a668();
  return;
}



// Function: FUN_10005b00 at 10005b00

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10005b00(void *param_1,wchar_t *param_2,ushort param_3,wchar_t *param_4)

{
  ulong uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  char local_2c [16];
  int local_1c;
  ulong local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_1c = 0;
  local_8 = 0;
  if (param_4 != (wchar_t *)0x0) {
    sVar3 = wcslen(param_4);
    local_18[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar1 = local_18[0];
    if (-1 < lVar4) {
      if (((int)local_18[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
        pcVar5 = local_2c;
      }
      else {
        pcVar5 = (char *)FUN_10002658(&local_1c,uVar1);
      }
      pcVar5 = AtlW2AHelper(pcVar5,param_4,uVar1,3);
      if (pcVar5 != (char *)0x0) {
        FUN_10004ede(param_1,param_2,(LPCSTR)(uint)param_3,pcVar5);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_100017da(&local_1c);
  FUN_1000a668();
  return;
}



// Function: FUN_10005ba9 at 10005ba9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10005ba9(void *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  ulong uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  LPCSTR pCVar5;
  char *pcVar6;
  char *pcVar7;
  char local_2c [16];
  int local_1c;
  ulong local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_1c = 0;
  local_8 = 0;
  if ((param_3 != (wchar_t *)0x0) && (param_4 != (wchar_t *)0x0)) {
    sVar3 = wcslen(param_3);
    local_18[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar1 = local_18[0];
    if (lVar4 < 0) {
      pcVar7 = (LPCSTR)0x0;
    }
    else {
      if (((int)local_18[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
        pcVar7 = local_2c;
      }
      else {
        pcVar7 = (char *)FUN_10002658(&local_1c,uVar1);
      }
      pcVar7 = AtlW2AHelper(pcVar7,param_3,uVar1,3);
    }
    sVar3 = wcslen(param_4);
    local_18[0] = sVar3 + 1;
    lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar1 = local_18[0];
    if (lVar4 < 0) {
      pCVar5 = (LPCSTR)0x0;
    }
    else {
      if (((int)local_18[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
        pcVar6 = local_2c;
      }
      else {
        pcVar6 = (char *)FUN_10002658(&local_1c,uVar1);
      }
      pCVar5 = AtlW2AHelper(pcVar6,param_4,uVar1,3);
    }
    if ((pcVar7 != (LPCSTR)0x0) && (pCVar5 != (LPCSTR)0x0)) {
      FUN_10004ede(param_1,param_2,pcVar7,pCVar5);
    }
  }
  local_8 = 0xffffffff;
  FUN_100017da(&local_1c);
  FUN_1000a668();
  return;
}



// Function: SetDWORDValue at 10005cc4

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::SetDWORDValue(char const *,unsigned long)
    public: long __thiscall ATL::CRegKey::SetDWORDValue(wchar_t const *,unsigned long)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall SetDWORDValue(void *this,LPCSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExA(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_10005ce0 at 10005ce0

LSTATUS __thiscall FUN_10005ce0(void *this,LPCSTR param_1,BYTE *param_2)

{
  size_t sVar1;
  int iVar2;
  LSTATUS LVar3;
  BYTE *_Str;
  DWORD cbData;
  
  if (param_2 == (BYTE *)0x0) {
    LVar3 = 0xd;
  }
  else {
    cbData = 0;
    _Str = param_2;
    do {
      sVar1 = strlen((char *)_Str);
      iVar2 = sVar1 + 1;
      _Str = _Str + iVar2;
      cbData = cbData + iVar2;
    } while (iVar2 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar3 = RegSetValueExA(*this,param_1,0,7,param_2,cbData);
  }
  return LVar3;
}



// Function: SetStringValue at 10005d26

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::SetStringValue(char const *,char const *,unsigned long)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall
ATL::CRegKey::SetStringValue(CRegKey *this,char *param_1,char *param_2,ulong param_3)

{
  size_t sVar1;
  long lVar2;
  
  if (param_2 == (char *)0x0) {
    lVar2 = 0xd;
  }
  else {
    sVar1 = strlen(param_2);
    lVar2 = RegSetValueExA(*(HKEY *)this,param_1,0,param_3,(BYTE *)param_2,sVar1 + 1);
  }
  return lVar2;
}



// Function: FUN_10005d5a at 10005d5a

void __thiscall FUN_10005d5a(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}



// Function: FUN_10005d6a at 10005d6a

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10005d6a(void *this,char *param_1)

{
  int iVar1;
  undefined1 local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_100155d8 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == '=') && (iVar1 = FUN_1000470c(this,param_1), -1 < iVar1)) {
    FUN_10005dce((undefined4 *)this);
    iVar1 = FUN_1000470c(this,local_1008);
    if (-1 < iVar1) {
      FUN_1000470c(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005dce at 10005dce

void __fastcall FUN_10005dce(undefined4 *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)*param_1;
  while( true ) {
    iVar2 = FUN_100044e8(*pcVar1);
    if (iVar2 == 0) break;
    pcVar1 = CharNextA((LPCSTR)*param_1);
    *param_1 = pcVar1;
  }
  return;
}



// Function: FUN_10005df0 at 10005df0

char * __cdecl FUN_10005df0(LPCSTR param_1,char param_2)

{
  char cVar1;
  LPCSTR pCVar2;
  
  pCVar2 = param_1;
  if (param_1 != (LPCSTR)0x0) {
    cVar1 = *param_1;
    while ((pCVar2 = (char *)0x0, cVar1 != '\0' && (pCVar2 = param_1, cVar1 != param_2))) {
      param_1 = CharNextA(param_1);
      cVar1 = *param_1;
    }
  }
  return pCVar2;
}



// Function: FUN_10005e22 at 10005e22

void __fastcall FUN_10005e22(int param_1)

{
  FUN_100046be((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
  return;
}



// Function: FUN_10005e35 at 10005e35

void __fastcall FUN_10005e35(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_100028b9((int)piVar1);
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



// Function: FUN_10005e78 at 10005e78

void __fastcall FUN_10005e78(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = *(int **)(param_1 + 0x2c);
  piVar1 = DAT_10015a24;
  piVar3 = DAT_10015a20;
  if (piVar2 != (int *)0x0) {
    for (; piVar1 = DAT_10015a24, piVar3 = DAT_10015a20, *piVar2 != 0; piVar2 = piVar2 + 9) {
      piVar1 = (int *)piVar2[4];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar2[4] = 0;
      (*(code *)piVar2[8])(0);
    }
  }
  for (; piVar3 < piVar1; piVar3 = piVar3 + 1) {
    if (*piVar3 != 0) {
      (**(code **)(*piVar3 + 0x1c))(0);
      piVar1 = DAT_10015a24;
    }
  }
  FUN_10005e35(param_1);
  return;
}



// Function: FUN_10005ed0 at 10005ed0

void __fastcall FUN_10005ed0(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_10005ee1 at 10005ee1

void __fastcall FUN_10005ee1(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_10005ef9 at 10005ef9

void FUN_10005ef9(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_1001561c != (code *)0x0) && (iVar1 = (*DAT_1001561c)(), iVar1 < 0)) {
    return;
  }
  FUN_10002aea(0x10015a18,param_1,param_2);
  return;
}



// Function: FUN_10005f1f at 10005f1f

void __thiscall FUN_10005f1f(void *this,int param_1,void *param_2)

{
  FUN_10002aea((int)this,param_1,param_2);
  return;
}



// Function: FUN_10005f32 at 10005f32

int __thiscall FUN_10005f32(void *this,int param_1,void *param_2)

{
  bool bVar1;
  void *pvVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)((int)this + 0x2c);
  iVar4 = 0;
  if ((piVar5 != (int *)0x0) && (pvVar2 = (void *)*piVar5, pvVar2 != (void *)0x0)) {
    do {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_1000699e(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar4 = 0;
        piVar3 = (int *)(*(code *)piVar5[7])();
        iVar4 = FUN_100030e1((GUID *)*piVar5,piVar3,iVar4);
        if (iVar4 < 0) {
          return iVar4;
        }
        iVar4 = (*(code *)piVar5[1])(0);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      piVar5 = piVar5 + 9;
      pvVar2 = (void *)*piVar5;
    } while (pvVar2 != (void *)0x0);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  iVar4 = FUN_10005ef9(param_1,param_2);
  return iVar4;
}



// Function: FUN_10005fa2 at 10005fa2

undefined4 FUN_10005fa2(void)

{
  return 0x80004005;
}



// Function: FUN_10005faa at 10005faa

undefined4 FUN_10005faa(void)

{
  return 0x80004005;
}



// Function: FUN_10005fb2 at 10005fb2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10005fb2(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  HMODULE pHVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  DWORD DVar5;
  size_t sVar6;
  long lVar7;
  wchar_t *pwVar8;
  HMODULE pHVar9;
  wchar_t *pwVar10;
  undefined **local_95c;
  undefined4 local_958;
  undefined4 local_954;
  undefined4 local_950;
  undefined4 *local_948;
  int local_944;
  wchar_t local_940 [520];
  wchar_t local_530;
  undefined2 local_52e [523];
  CHAR local_118 [272];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94c;
  local_948 = &local_958;
  local_95c = ATL::CRegObject::vftable;
  local_958 = 0;
  local_954 = 0;
  local_950 = 0;
  local_8 = 2;
  if (param_4 != (undefined4 *)0x0) {
    for (; (wchar_t *)*param_4 != (wchar_t *)0x0; param_4 = param_4 + 2) {
      FUN_10002062((int)&local_95c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
    }
  }
  iVar4 = (**(code **)(*param_1 + 0x14))();
  pHVar1 = DAT_100159e4;
  if (iVar4 < 0) goto LAB_1000622c;
  local_944 = 0;
  local_8._0_1_ = 3;
  DVar5 = GetModuleFileNameA(DAT_100159e4,local_118,0x104);
  if (DVar5 == 0) {
    FUN_10002c8d();
LAB_1000605e:
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_100017da(&local_944);
  }
  else {
    if (DVar5 == 0x104) {
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_100017da(&local_944);
      goto LAB_1000622c;
    }
    sVar6 = strlen(local_118);
    local_948 = (undefined4 *)(sVar6 + 1);
    lVar7 = ATL::AtlMultiply<int>((int *)&local_948,(int)local_948,2);
    puVar2 = local_948;
    if (-1 < lVar7) {
      if (((int)local_948 < 0x401) &&
         (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_948), bVar3)) {
        pwVar8 = (wchar_t *)&stack0xfffff690;
      }
      else {
        pwVar8 = (wchar_t *)FUN_10002658(&local_944,(ulong)puVar2);
      }
      pwVar8 = AtlA2WHelper(pwVar8,local_118,(uint)puVar2 >> 1,3);
      if (pwVar8 != (wchar_t *)0x0) {
        FUN_10003bd3(local_940,0x208,pwVar8);
        if ((pHVar1 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleA((LPCSTR)0x0), pHVar1 == pHVar9))
        {
          local_530 = L'\"';
          bVar3 = FUN_100067e4(local_52e,0x20b,local_940);
          if (!bVar3) {
            local_8 = CONCAT31(local_8._1_3_,2);
            FUN_100017da(&local_944);
            goto LAB_1000622c;
          }
          sVar6 = wcslen(&local_530);
          local_52e[sVar6 - 1] = 0x22;
          if (0x417 < sVar6 * 2 + 2) {
            ___report_rangecheckfailure();
            goto LAB_10006218;
          }
          local_52e[sVar6] = 0;
          pwVar10 = &local_530;
        }
        else {
          pwVar10 = local_940;
        }
        iVar4 = FUN_10002062((int)&local_95c,L"Module",pwVar10);
        if ((-1 < iVar4) &&
           (iVar4 = FUN_10002062((int)&local_95c,L"Module_Raw",local_940), -1 < iVar4)) {
          if (param_3 == 0) {
            FUN_10005b00(&local_95c,pwVar8,param_2,L"REGISTRY");
          }
          else {
            FUN_1000593d(&local_95c,pwVar8,param_2,L"REGISTRY");
          }
        }
        goto LAB_1000605e;
      }
    }
LAB_10006218:
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_100017da(&local_944);
  }
LAB_1000622c:
  local_8 = 0xffffffff;
  FUN_10001ba2(&local_95c);
  FUN_1000a668();
  return;
}



// Function: FUN_1000624b at 1000624b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000624b(int *param_1,char *param_2,int param_3,undefined4 *param_4)

{
  HMODULE pHVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  DWORD DVar5;
  size_t sVar6;
  long lVar7;
  wchar_t *pwVar8;
  HMODULE pHVar9;
  wchar_t *pwVar10;
  undefined **local_95c;
  undefined4 local_958;
  undefined4 local_954;
  undefined4 local_950;
  undefined4 *local_948;
  int local_944;
  wchar_t local_940 [520];
  wchar_t local_530;
  undefined2 local_52e [523];
  CHAR local_118 [272];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x950;
  local_948 = &local_958;
  local_95c = ATL::CRegObject::vftable;
  local_958 = 0;
  local_954 = 0;
  local_950 = 0;
  local_8 = 2;
  if (param_4 != (undefined4 *)0x0) {
    for (; (wchar_t *)*param_4 != (wchar_t *)0x0; param_4 = param_4 + 2) {
      FUN_10002062((int)&local_95c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
    }
  }
  iVar4 = (**(code **)(*param_1 + 0x14))();
  pHVar1 = DAT_100159e4;
  if (iVar4 < 0) goto LAB_10006541;
  local_944 = 0;
  local_8._0_1_ = 3;
  DVar5 = GetModuleFileNameA(DAT_100159e4,local_118,0x104);
  if (DVar5 == 0) {
    FUN_10002c8d();
    goto LAB_10006300;
  }
  if (DVar5 == 0x104) {
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_100017da(&local_944);
    goto LAB_10006541;
  }
  sVar6 = strlen(local_118);
  local_948 = (undefined4 *)(sVar6 + 1);
  lVar7 = ATL::AtlMultiply<int>((int *)&local_948,(int)local_948,2);
  puVar2 = local_948;
  if (-1 < lVar7) {
    if (((int)local_948 < 0x401) &&
       (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_948), bVar3)) {
      pwVar8 = (wchar_t *)&stack0xfffff68c;
    }
    else {
      pwVar8 = (wchar_t *)FUN_10002658(&local_944,(ulong)puVar2);
    }
    pwVar8 = AtlA2WHelper(pwVar8,local_118,(uint)puVar2 >> 1,3);
    if (pwVar8 != (wchar_t *)0x0) {
      FUN_10003bd3(local_940,0x208,pwVar8);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleA((LPCSTR)0x0), pHVar1 == pHVar9)) {
        local_530 = L'\"';
        bVar3 = FUN_100067e4(local_52e,0x20b,local_940);
        if (!bVar3) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_100017da(&local_944);
          goto LAB_10006541;
        }
        sVar6 = wcslen(&local_530);
        local_52e[sVar6 - 1] = 0x22;
        if (0x417 < sVar6 * 2 + 2) {
          ___report_rangecheckfailure();
          goto LAB_1000652d;
        }
        local_52e[sVar6] = 0;
        pwVar10 = &local_530;
      }
      else {
        pwVar10 = local_940;
      }
      iVar4 = FUN_10002062((int)&local_95c,L"Module",pwVar10);
      if ((iVar4 < 0) || (iVar4 = FUN_10002062((int)&local_95c,L"Module_Raw",local_940), iVar4 < 0))
      {
LAB_10006300:
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_100017da(&local_944);
        goto LAB_10006541;
      }
      if (param_2 != (char *)0x0) {
        sVar6 = strlen(param_2);
        local_948 = (undefined4 *)(sVar6 + 1);
        lVar7 = ATL::AtlMultiply<int>((int *)&local_948,(int)local_948,2);
        puVar2 = local_948;
        if (-1 < lVar7) {
          if (((int)local_948 < 0x401) &&
             (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_948), bVar3)
             ) {
            pwVar10 = (wchar_t *)&stack0xfffff68c;
          }
          else {
            pwVar10 = (wchar_t *)FUN_10002658(&local_944,(ulong)puVar2);
          }
          pwVar10 = AtlA2WHelper(pwVar10,param_2,(uint)puVar2 >> 1,3);
          if (pwVar10 != (wchar_t *)0x0) {
            if (param_3 == 0) {
              FUN_10005ba9(&local_95c,pwVar8,pwVar10,L"REGISTRY");
            }
            else {
              FUN_100059e6(&local_95c,pwVar8,pwVar10,L"REGISTRY");
            }
            goto LAB_10006300;
          }
        }
      }
    }
  }
LAB_1000652d:
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_100017da(&local_944);
LAB_10006541:
  local_8 = 0xffffffff;
  FUN_10001ba2(&local_95c);
  FUN_1000a668();
  return;
}



// Function: FUN_10006560 at 10006560

void FUN_10006560(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10005fb2(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10006569 at 10006569

void FUN_10006569(int *param_1,char *param_2,int param_3,undefined4 *param_4)

{
  FUN_1000624b(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10006572 at 10006572

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10006572(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x1000657e;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10015648 & 1) == 0) {
    DAT_10015648 = DAT_10015648 | 1;
    DAT_1001562c = 8;
    _DAT_10015634 = 0x4008;
    _DAT_1001563c = 0x13;
    DAT_10015628 = &DAT_1000e9f8;
    DAT_10015630 = &DAT_1000ea00;
    _DAT_10015638 = &DAT_1000ea18;
    _DAT_10015640 = &DAT_1000ea20;
    _DAT_10015644 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10015628)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x100065f6;
    iVar1 = lstrcmpiA(*(LPCSTR *)(puVar3 + -8),*(LPCSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_1001562c)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_10006615;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_10006615:
  *(undefined4 *)(puVar4 + -4) = 0x1000661a;
  return uVar2;
}



// Function: FUN_1000663f at 1000663f

void __fastcall FUN_1000663f(int param_1)

{
  DWORD DVar1;
  
  DVar1 = FUN_100042e7((LPCRITICAL_SECTION)(param_1 + 4));
  if (-1 < (int)DVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10006657 at 10006657

void __cdecl FUN_10006657(LPCRITICAL_SECTION param_1,DWORD param_2)

{
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return;
}



// Function: FUN_10006668 at 10006668

void __cdecl FUN_10006668(DWORD param_1,DWORD param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: _AtlVerifyStackAvailable at 1000667d

/* WARNING: Function: __SEH_prolog4_GS replaced with injection: SEH_prolog4 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    bool __cdecl ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(unsigned long)
   
   Library: Visual Studio 2012 Release */

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
  
  uStack_c = 0x10006689;
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
  uVar1 = FUN_1000a7a8();
  return (bool)uVar1;
}



// Function: _InternalQueryInterface at 10006702

/* Library Function - Single Match
    public: long __thiscall ATL::CAccessibleProxy::_InternalQueryInterface(struct _GUID const &,void
   * *)
   
   Library: Visual Studio 2012 Release */

long __thiscall
ATL::CAccessibleProxy::_InternalQueryInterface(CAccessibleProxy *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = AtlInternalQueryInterface(this,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000ee94,param_1,param_2);
  return lVar1;
}



// Function: _InternalQueryInterface at 1000671a

/* Library Function - Single Match
    public: long __thiscall ATL::CAccessibleProxy::_InternalQueryInterface(struct _GUID const &,void
   * *)
   
   Library: Visual Studio 2012 Release */

long __thiscall
ATL::CAccessibleProxy::_InternalQueryInterface(CAccessibleProxy *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = AtlInternalQueryInterface(this,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000eeac,param_1,param_2);
  return lVar1;
}



// Function: FUN_1000674c at 1000674c

void FUN_1000674c(uchar *param_1,uchar *param_2)

{
                    /* WARNING: Could not recover jumptable at 0x10006750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _mbsstr(param_1,param_2);
  return;
}



// Function: FUN_10006756 at 10006756

void FUN_10006756(int param_1,int *param_2)

{
  FUN_10008fab(param_1 + -4,param_2);
  return;
}



// Function: FUN_10006760 at 10006760

void FUN_10006760(int param_1,int *param_2)

{
  FUN_10008ff0(param_1 + -4,param_2);
  return;
}



// Function: FUN_1000676a at 1000676a

void FUN_1000676a(int param_1,int *param_2)

{
  FUN_10009035(param_1 + -4,param_2);
  return;
}



// Function: FUN_10006774 at 10006774

void FUN_10006774(int param_1,long *param_2)

{
  FUN_100090e7(param_1 + -4,param_2);
  return;
}



// Function: FUN_1000677e at 1000677e

void FUN_1000677e(int param_1,int *param_2)

{
  FUN_100091a9(param_1 + -4,param_2);
  return;
}



// Function: FUN_10006788 at 10006788

void FUN_10006788(int param_1,long *param_2)

{
  FUN_1000925b(param_1 + -4,param_2);
  return;
}



// Function: FUN_10006792 at 10006792

void FUN_10006792(int param_1,long *param_2)

{
  FUN_100093b7(param_1 + -4,param_2);
  return;
}



// Function: FUN_1000679c at 1000679c

void FUN_1000679c(int param_1,int *param_2)

{
  FUN_10009479(param_1 + -4,param_2);
  return;
}



// Function: FUN_100067a6 at 100067a6

void FUN_100067a6(int param_1,undefined8 *param_2)

{
  FUN_1000952b(param_1 + -4,param_2);
  return;
}



// Function: FUN_100067b0 at 100067b0

void FUN_100067b0(int param_1,int *param_2)

{
  FUN_10009642((int *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100067ba at 100067ba

void FUN_100067ba(int param_1,int param_2)

{
  FUN_10009759((int *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_100067c4 at 100067c4

void __cdecl FUN_100067c4(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_100067e4 at 100067e4

bool __cdecl FUN_100067e4(void *param_1,int param_2,wchar_t *param_3)

{
  size_t sVar1;
  errno_t eVar2;
  
  if (param_3 == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = wcslen(param_3);
  }
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,sVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_1000681f at 1000681f

size_t __cdecl FUN_1000681f(wchar_t *param_1)

{
  size_t sVar1;
  
  if (param_1 == (wchar_t *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x1000682d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = wcslen(param_1);
  return sVar1;
}



// Function: FUN_10006833 at 10006833

void FUN_10006833(int param_1,int param_2)

{
  FUN_1000997c(param_1 + -4,param_2);
  return;
}



// Function: FUN_1000683d at 1000683d

void FUN_1000683d(int param_1)

{
  FUN_100099d5(param_1 + -4);
  return;
}



// Function: FUN_10006847 at 10006847

void FUN_10006847(int param_1,int param_2)

{
  FUN_10009a74(param_1 + -4,param_2);
  return;
}



// Function: FUN_10006851 at 10006851

void FUN_10006851(int param_1)

{
  FUN_10009acd(param_1 + -4);
  return;
}



// Function: FUN_1000685b at 1000685b

void FUN_1000685b(int param_1)

{
  FUN_10009d0d(param_1 + -4);
  return;
}



// Function: FUN_10006865 at 10006865

void __cdecl FUN_10006865(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcat_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10006882 at 10006882

void __cdecl FUN_10006882(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_1000689f at 1000689f

void __cdecl FUN_1000689f(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
  errno_t eVar1;
  
  eVar1 = _mbsnbcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_100068bf at 100068bf

void __cdecl FUN_100068bf(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: DllCanUnloadNow at 100068df

HRESULT DllCanUnloadNow(void)

{
                    /* 0x68df  1  DllCanUnloadNow */
  return (uint)(DAT_10015654 != 0);
}



// Function: DllGetClassObject at 100068eb

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x68eb  2  DllGetClassObject */
  iVar1 = FUN_10003d35(&DAT_1001564c,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: FUN_100068f9 at 100068f9

undefined4 FUN_100068f9(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10004311(&DAT_1001564c,(int *)&PTR_DAT_10015000,param_1,(undefined4 *)&DAT_1000e334);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10005e78(0x1001564c);
  }
  return 1;
}



// Function: DllRegisterServer at 1000693b

void DllRegisterServer(void)

{
                    /* 0x693b  3  DllRegisterServer */
  FUN_10005141(&DAT_1001564c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 1000694a

void DllUnregisterServer(void)

{
                    /* 0x694a  4  DllUnregisterServer */
  FUN_10005f32(&DAT_1001564c,1,(void *)0x0);
  return;
}



// Function: FUN_10006959 at 10006959

uint __cdecl FUN_10006959(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff | 0x80070000;
  if ((int)param_1 < 1) {
    uVar1 = param_1;
  }
  return uVar1;
}



// Function: _InlineIsEqualGUID at 1000696e

/* Library Function - Single Match
    _InlineIsEqualGUID
   
   Library: Visual Studio 2012 Release */

undefined4 __cdecl _InlineIsEqualGUID(int *param_1,int *param_2)

{
  if ((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
     (param_1[3] == param_2[3])) {
    return 1;
  }
  return 0;
}



// Function: FUN_1000699e at 1000699e

bool __cdecl FUN_1000699e(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: FUN_100069b8 at 100069b8

void FUN_100069b8(uchar *param_1,size_t param_2,uchar *param_3,size_t param_4)

{
                    /* WARNING: Could not recover jumptable at 0x100069bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _mbsnbcpy_s(param_1,param_2,param_3,param_4);
  return;
}



// Function: operator= at 100069cc

/* Library Function - Single Match
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
   
   Library: Visual Studio 2012 Release */

_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> * __thiscall
_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
          (_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *this,IBinding *param_1)

{
  IBinding *pIVar1;
  
  pIVar1 = *(IBinding **)this;
  if (pIVar1 != param_1) {
    *(IBinding **)this = param_1;
    if (param_1 != (IBinding *)0x0) {
      (**(code **)(*(int *)param_1 + 4))(param_1);
    }
    if (pIVar1 != (IBinding *)0x0) {
      (**(code **)(*(int *)pIVar1 + 8))(pIVar1);
    }
  }
  return this;
}



// Function: operator= at 100069fa

/* Library Function - Single Match
    public: class _CIP<struct IBinding,&struct _GUID const IID_IBinding> & __thiscall _CIP<struct
   IBinding,&struct _GUID const IID_IBinding>::operator=(struct IBinding *)
   
   Library: Visual Studio 2012 Release */

_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> * __thiscall
_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
          (_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *this,IBinding *param_1)

{
  IBinding *pIVar1;
  
  pIVar1 = *(IBinding **)this;
  if (pIVar1 != param_1) {
    *(IBinding **)this = param_1;
    if (param_1 != (IBinding *)0x0) {
      (**(code **)(*(int *)param_1 + 4))(param_1);
    }
    if (pIVar1 != (IBinding *)0x0) {
      (**(code **)(*(int *)pIVar1 + 8))(pIVar1);
    }
  }
  return this;
}



// Function: FUN_10006a28 at 10006a28

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10006a28(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  iVar1 = FUN_10006ac6(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  return this;
}



// Function: FUN_10006a77 at 10006a77

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10006a77(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  iVar1 = FUN_10006b52(this,piVar2);
  if ((iVar1 < 0) && (iVar1 != -0x7fffbffe)) {
    _com_issue_error(iVar1);
  }
  return this;
}



// Function: FUN_10006ac6 at 10006ac6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10006ac6(void *this,int *param_1)

{
  int *extraout_EAX;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    if ((piVar1 != (int *)0x0) && (*(undefined4 *)this = 0, piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    iVar2 = -0x7fffbffe;
  }
  else {
    piVar1 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar1 = extraout_EAX;
    }
    iVar2 = (**(code **)*piVar1)(piVar1,&DAT_1000e738,local_14);
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    uVar3 = 0;
    if (-1 < iVar2) {
      uVar3 = local_14[0];
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)this = uVar3;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return iVar2;
}



// Function: FUN_10006b52 at 10006b52

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10006b52(void *this,int *param_1)

{
  int *extraout_EAX;
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    if ((piVar1 != (int *)0x0) && (*(undefined4 *)this = 0, piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    iVar2 = -0x7fffbffe;
  }
  else {
    piVar1 = param_1;
    if (param_1 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
      piVar1 = extraout_EAX;
    }
    iVar2 = (**(code **)*piVar1)(piVar1,&DAT_1000e6f8,local_14);
                    /* WARNING: Load size is inaccurate */
    piVar1 = *this;
    uVar3 = 0;
    if (-1 < iVar2) {
      uVar3 = local_14[0];
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)this = uVar3;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return iVar2;
}



// Function: FUN_10006c26 at 10006c26

int * __thiscall FUN_10006c26(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_10006c44 at 10006c44

undefined4 * __thiscall FUN_10006c44(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006c6c at 10006c6c

int * __thiscall FUN_10006c6c(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return (int *)this;
}



// Function: FUN_10006c8a at 10006c8a

undefined4 * __thiscall FUN_10006c8a(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006cac at 10006cac

undefined4 * __thiscall FUN_10006cac(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006cce at 10006cce

undefined4 * __thiscall FUN_10006cce(void *this,int *param_1,char param_2)

{
  *(int **)this = param_1;
  if ((param_2 != '\0') && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006cf0 at 10006cf0

int * __thiscall FUN_10006cf0(void *this,int *param_1,int *param_2)

{
  rsize_t _DstSize;
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *_Dst;
  int *piVar5;
  undefined4 *extraout_ECX;
  void *_Src;
  void *_Src_00;
  uint local_8;
  
  _Src_00 = (void *)0x0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  iVar2 = FUN_10009742(param_1);
  uVar3 = FUN_10009742(param_2);
  iVar4 = FUN_10008bcc(iVar2,uVar3,&local_8);
  if ((-1 < iVar4) && (iVar4 = FUN_10008bea(local_8,2,extraout_ECX), -1 < iVar4)) {
    local_8 = (iVar2 + uVar3) * 2;
    _Dst = (void *)Ordinal_150(0,local_8);
    *(void **)this = _Dst;
    if (_Dst == (void *)0x0) {
      if (iVar2 + uVar3 != 0) goto LAB_10006dd0;
    }
    else {
      if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
        _Src = (void *)0x0;
      }
      else {
        _Src = *(void **)*param_1;
      }
      if (_Src != (void *)0x0) {
        memcpy_s(_Dst,local_8 + 2,_Src,iVar2 * 2 + 2);
      }
      if ((undefined4 *)*param_2 != (undefined4 *)0x0) {
        _Src_00 = *(void **)*param_2;
      }
      if (_Src_00 != (void *)0x0) {
        _DstSize = uVar3 * 2 + 2;
                    /* WARNING: Load size is inaccurate */
        memcpy_s((void *)(*this + iVar2 * 2),_DstSize,_Src_00,_DstSize);
      }
    }
    return (int *)this;
  }
LAB_10006dd0:
  _com_issue_error(-0x7ff8fff2);
  pcVar1 = (code *)swi(3);
  piVar5 = (int *)(*pcVar1)();
  return piVar5;
}



// Function: FUN_10006ddb at 10006ddb

int * __thiscall FUN_10006ddb(void *this,int param_1,char param_2)

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



// Function: FUN_10006e26 at 10006e26

undefined4 * __thiscall FUN_10006e26(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return (undefined4 *)this;
}



// Function: FUN_10006e48 at 10006e48

int * __thiscall FUN_10006e48(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  iVar2 = Ordinal_2(param_1);
  *(int *)this = iVar2;
  if ((iVar2 == 0) && (param_1 != 0)) {
    _com_issue_error(-0x7ff8fff2);
    pcVar1 = (code *)swi(3);
    piVar3 = (int *)(*pcVar1)();
    return piVar3;
  }
  return (int *)this;
}



// Function: FUN_10006e7f at 10006e7f

int * __thiscall FUN_10006e7f(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(int *)this = iVar1;
  if (iVar1 != 0) {
    InterlockedIncrement((LONG *)(iVar1 + 8));
  }
  return (int *)this;
}



// Function: FUN_10006ea1 at 10006ea1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006ea1(void *this,int param_1,char param_2)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  piVar1 = (int *)0x0;
  if (this_00 != (void *)0x0) {
    piVar1 = FUN_10006ddb(this_00,param_1,param_2);
  }
  *(int **)this = piVar1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006eee at 10006eee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006eee(void *this,LPCSTR param_1)

{
  void *this_00;
  undefined4 *puVar1;
  
  this_00 = operator_new(0xc);
  puVar1 = (undefined4 *)0x0;
  if (this_00 != (void *)0x0) {
    puVar1 = FUN_10006e26(this_00,param_1);
  }
  *(undefined4 **)this = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006f38 at 10006f38

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10006f38(void *this,int param_1)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  piVar1 = (int *)0x0;
  if (this_00 != (void *)0x0) {
    piVar1 = FUN_10006e48(this_00,param_1);
  }
  *(int **)this = piVar1;
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006f88 at 10006f88

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10006f88(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000cf1b;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_10006fad at 10006fad

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_10006fad(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  
  puVar2 = &LAB_1000cf3e;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined1 *)(**(code **)(*piVar1 + 8))(piVar1);
  }
  return puVar2;
}



// Function: FUN_10006fd2 at 10006fd2

void __fastcall FUN_10006fd2(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10006fdf at 10006fdf

void __fastcall FUN_10006fdf(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10006fec at 10006fec

void __fastcall FUN_10006fec(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10006ff9 at 10006ff9

void __fastcall FUN_10006ff9(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10007006 at 10007006

void __fastcall FUN_10007006(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10007018 at 10007018

void __fastcall FUN_10007018(undefined4 *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    FUN_10008b2c((int *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_1000702b at 1000702b

void __cdecl FUN_1000702b(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: FUN_10007034 at 10007034

void __thiscall FUN_10007034(void *this,undefined4 *param_1)

{
  _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
            ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)this,(IBinding *)*param_1);
  return;
}



// Function: FUN_10007045 at 10007045

void __thiscall FUN_10007045(void *this,undefined4 *param_1)

{
  _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
            ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)this,(IBinding *)*param_1);
  return;
}



// Function: FUN_10007056 at 10007056

int * __thiscall FUN_10007056(void *this,int *param_1)

{
  int iVar1;
  
  if ((int *)this != param_1) {
                    /* WARNING: Load size is inaccurate */
    if (*this != (int *)0x0) {
      FUN_10008b2c(*this);
      *(undefined4 *)this = 0;
    }
    iVar1 = *param_1;
    *(int *)this = iVar1;
    if (iVar1 != 0) {
      InterlockedIncrement((LONG *)(iVar1 + 8));
    }
  }
  return (int *)this;
}



// Function: FUN_1000708c at 1000708c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000708c(void *this,LPCSTR param_1)

{
  LPCSTR pCVar1;
  void *this_00;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  if (param_1 != (LPCSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
    if (*this == (undefined4 *)0x0) {
      pCVar1 = (LPCSTR)0x0;
    }
    else {
      pCVar1 = (LPCSTR)FUN_1000805a(*this);
    }
    if (pCVar1 == param_1) {
      return (undefined4 *)this;
    }
  }
                    /* WARNING: Load size is inaccurate */
  if (*this != (int *)0x0) {
    FUN_10008b2c(*this);
    *(undefined4 *)this = 0;
  }
  this_00 = operator_new(0xc);
  if (this_00 != (void *)0x0) {
    puVar2 = FUN_10006e26(this_00,param_1);
  }
  *(undefined4 **)this = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  return (undefined4 *)this;
}



// Function: FUN_100070fe at 100070fe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_100070fe(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (param_1 != 0) {
                    /* WARNING: Load size is inaccurate */
    if (*this == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = **this;
    }
    if (iVar1 == param_1) {
      return (int *)this;
    }
  }
                    /* WARNING: Load size is inaccurate */
  if (*this != (int *)0x0) {
    FUN_10008b2c(*this);
    *(undefined4 *)this = 0;
  }
  this_00 = operator_new(0xc);
  if (this_00 != (void *)0x0) {
    piVar2 = FUN_10006e48(this_00,param_1);
  }
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  return (int *)this;
}



// Function: FUN_1000716d at 1000716d

uint __thiscall FUN_1000716d(void *this,int param_1)

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



// Function: FUN_1000718c at 1000718c

uint __thiscall FUN_1000718c(void *this,int param_1)

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



// Function: FUN_100071ab at 100071ab

bool __thiscall FUN_100071ab(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1000716d(this,param_1);
  return (char)uVar1 == '\0';
}



// Function: FUN_100071c3 at 100071c3

bool __thiscall FUN_100071c3(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1000718c(this,param_1);
  return (char)uVar1 == '\0';
}



// Function: FUN_1000720c at 1000720c

void __fastcall FUN_1000720c(int *param_1)

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



// Function: FUN_1000721e at 1000721e

void __fastcall FUN_1000721e(int *param_1)

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



// Function: FUN_10007230 at 10007230

void __fastcall FUN_10007230(int *param_1)

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



// Function: FUN_10007254 at 10007254

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10007254(void *this,int *param_1,int *param_2)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  *param_1 = iVar1;
  if (iVar1 != 0) {
    InterlockedIncrement((LONG *)(iVar1 + 8));
  }
  FUN_100072b8(param_1,param_2);
  return param_1;
}



// Function: FUN_100072a2 at 100072a2

int * __fastcall FUN_100072a2(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100072b8 at 100072b8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_100072b8(void *this,int *param_1)

{
  void *this_00;
  int *piVar1;
  
  this_00 = operator_new(0xc);
  if (this_00 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_10006cf0(this_00,(int *)this,param_1);
  }
  if (piVar1 == (int *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
                    /* WARNING: Load size is inaccurate */
  if (*this != (int *)0x0) {
    FUN_10008b2c(*this);
    *(undefined4 *)this = 0;
  }
  *(int **)this = piVar1;
  return (int *)this;
}



// Function: FUN_10007316 at 10007316

int * __thiscall FUN_10007316(void *this,byte param_1)

{
  FUN_10008c55((int *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (int *)this;
}



// Function: FUN_10007335 at 10007335

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10007335(int param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  void *extraout_ECX;
  void *this;
  int *piVar3;
  int *piVar4;
  IID *pIVar5;
  int *piVar6;
  int *piVar7;
  IBinding *in_stack_ffffff84;
  int *local_68;
  IID *local_64;
  int *local_60;
  int *local_5c;
  undefined1 *local_58;
  IBinding *local_54;
  int local_50;
  _SYSTEMTIME local_4c;
  wchar_t local_3c [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_5c = (int *)0x0;
  local_50 = param_1;
  local_58 = (undefined1 *)0x80004005;
  piVar3 = (int *)0x0;
  local_60 = (int *)0x0;
  pIVar5 = (IID *)0x0;
  local_64 = (IID *)0x0;
  local_8._1_3_ = 0;
  piVar4 = (int *)0x0;
  local_68 = (int *)0x0;
  local_8._0_1_ = 3;
  GetLocalTime(&local_4c);
  if (*(int *)(local_50 + 0x28) != 0) {
    if (DAT_100156a8 != 0) {
      InterlockedIncrement((LONG *)(DAT_100156a8 + 8));
    }
    local_8._0_1_ = 4;
    this = *(void **)(local_50 + 0x28);
    if (this != (void *)0x0) goto LAB_100073c9;
    do {
      do {
        _com_issue_error(-0x7fffbffd);
        this = extraout_ECX;
LAB_100073c9:
        local_8._0_1_ = 3;
        puVar2 = FUN_10008d27(this,&local_54,(int *)in_stack_ffffff84);
        local_8._0_1_ = 5;
        in_stack_ffffff84 = (IBinding *)*puVar2;
        _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
                  ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)&local_64,
                   in_stack_ffffff84);
        local_8._0_1_ = 3;
        if (local_54 != (IBinding *)0x0) {
          in_stack_ffffff84 = local_54;
          (**(code **)(*(int *)local_54 + 8))();
        }
        pIVar5 = local_64;
        if (local_64 == (IID *)0x0) goto LAB_1000747f;
      } while (*(void **)(local_50 + 0x28) == (void *)0x0);
      puVar2 = (undefined4 *)FUN_10008075(*(void **)(local_50 + 0x28),(ulong *)&local_54);
      local_8._0_1_ = 6;
      _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
                ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)&local_68,
                 (IBinding *)*puVar2);
      local_8._0_1_ = 3;
      if (local_54 != (IBinding *)0x0) {
        (**(code **)(*(int *)local_54 + 8))();
      }
      piVar4 = local_68;
      if (local_68 == (int *)0x0) goto LAB_1000747f;
    } while (local_68 == (int *)0x0);
    puVar2 = (undefined4 *)FUN_10008cb7(local_68,&local_54,pIVar5);
    local_8._0_1_ = 7;
    _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
              ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)(local_50 + 0x2c),
               (IBinding *)*puVar2);
    local_8._0_1_ = 3;
    if (local_54 != (IBinding *)0x0) {
      (**(code **)(*(int *)local_54 + 8))();
    }
  }
LAB_1000747f:
  if (*(int *)(local_50 + 0x2c) != 0) {
    *(undefined2 *)(local_50 + 0x30) = 0;
    FUN_10009e88(local_3c,0x1000f158);
    FUN_100070fe(&local_5c,(int)local_3c);
    piVar7 = local_5c;
    if (local_5c != (int *)0x0) {
      InterlockedIncrement(local_5c + 2);
    }
    local_8._0_1_ = 8;
    local_54 = (IBinding *)&stack0xffffff7c;
    piVar6 = DAT_10015698;
    if (DAT_10015698 != (int *)0x0) {
      InterlockedIncrement(DAT_10015698 + 2);
    }
    local_54 = (IBinding *)(local_50 + -4);
    local_8._0_1_ = 3;
    local_58 = (undefined1 *)FUN_100087a9(local_54,piVar6,piVar7);
    if (-1 < (int)local_58) {
      GetCurrentThreadId();
      FUN_10009e88(local_3c,0x1000f31c);
      FUN_100070fe(&local_60,(int)local_3c);
      piVar3 = local_60;
      piVar7 = local_60;
      if (local_60 != (int *)0x0) {
        InterlockedIncrement(local_60 + 2);
      }
      local_8._0_1_ = 10;
      local_58 = &stack0xffffff7c;
      piVar6 = DAT_10015680;
      puVar1 = &stack0xffffff7c;
      if (DAT_10015680 != (int *)0x0) {
        InterlockedIncrement(DAT_10015680 + 2);
        puVar1 = local_58;
      }
      local_58 = puVar1;
      local_8._0_1_ = 3;
      local_58 = (undefined1 *)FUN_100087a9(local_54,piVar6,piVar7);
    }
  }
  if ((*(int *)(local_50 + 0x28) == 0) || (*(int *)(local_50 + 0x2c) == 0)) {
    local_58 = (undefined1 *)
               FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x68,0,0,&DAT_1000e344,0x80004005,
                            DAT_100159e8);
  }
  local_8._0_1_ = 2;
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))();
  }
  local_8._0_1_ = 1;
  if (pIVar5 != (IID *)0x0) {
    (**(code **)(pIVar5->Data1 + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar3 != (int *)0x0) {
    FUN_10008b2c(piVar3);
    local_60 = (int *)0x0;
  }
  local_8 = 0xffffffff;
  if (local_5c != (int *)0x0) {
    FUN_10008b2c(local_5c);
    local_5c = (int *)0x0;
  }
  FUN_1000a668();
  return;
}



// Function: FUN_10007648 at 10007648

void FUN_10007648(IID *param_1,ushort param_2,undefined4 param_3,undefined4 param_4,
                 HINSTANCE param_5)

{
  FUN_1000779e(param_1,(wchar_t *)(uint)param_2,0,0,param_3,param_4,param_5);
  return;
}



// Function: FUN_10007669 at 10007669

void FUN_10007669(IID *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_10007685(param_1,param_2,0,(char *)0x0,param_3,param_4);
  return;
}



// Function: FUN_10007685 at 10007685

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10007685(IID *param_1,char *param_2,int param_3,char *param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  wchar_t local_2c [8];
  int local_1c;
  uint local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10007691;
  if (param_2 == (char *)0x0) goto LAB_10007793;
  local_1c = 0;
  local_8 = 0;
  sVar3 = strlen(param_2);
  local_18[0] = sVar3 + 1;
  lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
  uVar1 = local_18[0];
  if (-1 < lVar4) {
    if (((int)local_18[0] < 0x401) &&
       (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
      pwVar5 = local_2c;
    }
    else {
      pwVar5 = (wchar_t *)FUN_10002658(&local_1c,uVar1);
    }
    pwVar5 = AtlA2WHelper(pwVar5,param_2,uVar1 >> 1,3);
    if (pwVar5 != (wchar_t *)0x0) {
      pwVar6 = (wchar_t *)0x0;
      if (param_4 == (char *)0x0) {
LAB_10007767:
        FUN_1000779e(param_1,pwVar5,param_3,(int)pwVar6,param_5,param_6,(HINSTANCE)0x0);
      }
      else {
        sVar3 = strlen(param_4);
        local_18[0] = sVar3 + 1;
        lVar4 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
        uVar1 = local_18[0];
        if (-1 < lVar4) {
          if (((int)local_18[0] < 0x401) &&
             (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar2)) {
            pwVar6 = local_2c;
          }
          else {
            pwVar6 = (wchar_t *)FUN_10002658(&local_1c,uVar1);
          }
          pwVar6 = AtlA2WHelper(pwVar6,param_4,uVar1 >> 1,3);
          if (pwVar6 != (wchar_t *)0x0) goto LAB_10007767;
        }
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_100017da(&local_1c);
LAB_10007793:
  FUN_1000a668();
  return;
}



// Function: FUN_1000779e at 1000779e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_1000779e(IID *param_1,wchar_t *param_2,int param_3,int param_4,undefined4 param_5,
                 int param_6,HINSTANCE param_7)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  errno_t eVar4;
  size_t sVar5;
  long lVar6;
  wchar_t *pwVar7;
  wchar_t local_43c [8];
  undefined4 local_42c;
  IID *local_428;
  int local_424;
  LPOLESTR local_420;
  int *local_41c;
  int *local_418;
  CHAR local_414 [1036];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x41c;
  local_424 = 0;
  local_428 = param_1;
  local_42c = param_5;
  local_8 = 0;
  local_414[0] = '\0';
  if (((uint)param_2 & 0xffff0000) == 0) {
    local_420 = (LPOLESTR)((uint)param_2 & 0xffff);
    iVar3 = LoadStringA(param_7,(UINT)local_420,local_414,0x400);
    if (iVar3 == 0) {
      eVar4 = strcpy_s(local_414,0x400,"Unknown Error");
      ATL::AtlCrtErrorCheck(eVar4);
    }
    sVar5 = strlen(local_414);
    local_41c = (int *)(sVar5 + 1);
    lVar6 = ATL::AtlMultiply<int>((int *)&local_41c,(int)local_41c,2);
    piVar1 = local_41c;
    if (lVar6 < 0) goto LAB_100079bb;
    if (((int)local_41c < 0x401) &&
       (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_41c), bVar2)) {
      pwVar7 = local_43c;
    }
    else {
      pwVar7 = (wchar_t *)FUN_10002658(&local_424,(ulong)piVar1);
    }
    param_2 = AtlA2WHelper(pwVar7,local_414,(uint)piVar1 >> 1,3);
    if (param_2 == (wchar_t *)0x0) goto LAB_100079bb;
  }
  local_418 = (int *)0x0;
  local_8._0_1_ = 2;
  iVar3 = Ordinal_202(&local_418);
  if (-1 < iVar3) {
    local_41c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
    (**(code **)(*local_418 + 0xc))(local_418,local_42c);
    ProgIDFromCLSID(local_428,&local_420);
    if (local_420 != (LPOLESTR)0x0) {
      (**(code **)(*local_418 + 0x10))(local_418,local_420);
    }
    if ((param_3 != 0) && (param_4 != 0)) {
      (**(code **)(*local_418 + 0x1c))(local_418,param_3);
      (**(code **)(*local_418 + 0x18))(local_418,param_4);
    }
    CoTaskMemFree(local_420);
    (**(code **)(*local_418 + 0x14))(local_418,param_2);
    iVar3 = (**(code **)*local_418)(local_418,&DAT_1000e540,&local_41c);
    if (-1 < iVar3) {
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
LAB_100079bb:
  local_8 = 0xffffffff;
  FUN_100017da(&local_424);
  FUN_1000a668();
  return;
}



// Function: FUN_100079da at 100079da

void __thiscall FUN_100079da(void *this,int param_1)

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



// Function: FUN_100079f6 at 100079f6

void __thiscall FUN_100079f6(void *this,int param_1)

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



// Function: FUN_10007a12 at 10007a12

int __fastcall FUN_10007a12(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*param_1 == 0) {
    iVar3 = 0;
  }
  else {
    uVar2 = Ordinal_149(*param_1);
    iVar3 = Ordinal_150(*param_1,uVar2);
    if (iVar3 == 0) {
      _com_issue_error(-0x7ff8fff2);
      pcVar1 = (code *)swi(3);
      iVar3 = (*pcVar1)();
      return iVar3;
    }
  }
  return iVar3;
}



// Function: FUN_10007a40 at 10007a40

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10007a40(void *this,void *param_1)

{
  int *piVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10007a4c;
  piVar1 = *(int **)((int)this + 8);
  local_14[0] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1,local_14);
  }
  FUN_10006ea1(param_1,local_14[0],'\0');
  return param_1;
}



// Function: FUN_10007a8a at 10007a8a

void __thiscall FUN_10007a8a(void *this,undefined4 param_1)

{
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) {
    return;
  }
  FUN_10003e9e(this,param_1);
  return;
}



// Function: FUN_10007aa3 at 10007aa3

void FUN_10007aa3(ushort param_1,undefined4 param_2,undefined4 param_3,HINSTANCE param_4)

{
  FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)(uint)param_1,0,0,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007ac6 at 10007ac6

void FUN_10007ac6(char *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007685((IID *)&DAT_1000e364,param_1,0,(char *)0x0,param_2,param_3);
  return;
}



// Function: FUN_10007ae8 at 10007ae8

void * __thiscall FUN_10007ae8(void *this,void *param_1)

{
  int *piVar1;
  
  memcpy_s(param_1,0x10,&DAT_1000e378,0x10);
  piVar1 = *(int **)((int)this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,param_1);
  }
  return param_1;
}



// Function: FUN_10007b1b at 10007b1b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10007c28) */

int __thiscall FUN_10007b1b(void *this,int **param_1,void *param_2)

{
  int **ppiVar1;
  int *piVar2;
  void *extraout_ECX;
  void *this_00;
  int *piVar3;
  int iVar4;
  int **local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  piVar3 = (int *)0x0;
  iVar4 = 0;
  local_18 = (int *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (*(char *)((int)this + 0x35) == '\x01') {
    iVar4 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x66,0,0,&DAT_1000e344,0x80004005,
                         DAT_100159e8);
  }
  if (*(char *)((int)this + 0x34) == '\x01') {
    iVar4 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x67,0,0,&DAT_1000e344,0x80004005,
                         DAT_100159e8);
  }
  if (-1 < iVar4) {
    if (*(int *)((int)this + 0x30) == 0) {
      iVar4 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x68,0,0,&DAT_1000e344,0x80004005,
                           DAT_100159e8);
    }
    else {
      local_14[0] = (int *)&stack0xffffffd0;
      ppiVar1 = param_1;
      piVar3 = (int *)&stack0xffffffd0;
      if (param_1 != (int **)0x0) {
        InterlockedIncrement((LONG *)(param_1 + 2));
        piVar3 = local_14[0];
      }
      local_14[0] = piVar3;
      local_8._0_1_ = 2;
      this_00 = *(void **)((int)this + 0x30);
      if (this_00 != (void *)0x0) goto LAB_10007bd5;
      do {
        do {
          _com_issue_error(-0x7fffbffd);
          this_00 = extraout_ECX;
LAB_10007bd5:
          local_8._0_1_ = 1;
          ppiVar1 = (int **)FUN_10009e1a(this_00,&local_1c,(int *)ppiVar1);
          local_8._0_1_ = 3;
          FUN_10006a77(&local_18,(int *)ppiVar1);
          local_8._0_1_ = 1;
          if (local_1c != (int **)0x0) {
            ppiVar1 = local_1c;
            (*(code *)(*local_1c)[2])();
          }
          piVar3 = local_18;
          if (local_18 == (int *)0x0) goto LAB_10007cc1;
          local_14[0] = (int *)0x0;
          local_8._0_1_ = 4;
        } while (local_18 == (int *)0x0);
        local_8._0_1_ = 4;
        local_14[0] = (int *)0x0;
        ppiVar1 = local_14;
        (**(code **)(*local_18 + 0x34))(local_18);
        if (local_14[0] == (int *)0x0) {
          FUN_1000708c(param_2,"");
          goto LAB_10007c8e;
        }
      } while (local_14[0] == (int *)0x0);
      piVar2 = (int *)FUN_100082b3(local_14[0],&local_1c);
      local_8._0_1_ = 5;
      FUN_10007056(param_2,piVar2);
      local_8._0_1_ = 4;
      if (local_1c != (int **)0x0) {
        FUN_10008b2c((int *)local_1c);
        local_1c = (int **)0x0;
      }
LAB_10007c8e:
      local_8._0_1_ = 1;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))();
      }
    }
  }
LAB_10007cc1:
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_1 != (int **)0x0) {
    FUN_10008b2c((int *)param_1);
  }
  return iVar4;
}



// Function: FUN_10007ced at 10007ced

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10007e41) */

undefined4 __thiscall FUN_10007ced(void *this,int *param_1,int *param_2,void *param_3)

{
  int *piVar1;
  uint3 uVar2;
  int iVar3;
  int *piVar4;
  void *extraout_ECX;
  void *this_00;
  int *piVar5;
  int iVar6;
  int **ppiVar7;
  int **local_1c;
  IUnknown *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 0x10;
  piVar5 = (int *)0x0;
  local_14[0] = (int *)0x0;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  *(undefined1 *)param_2 = 0;
  if (*(int *)((int)this + 0x2c) != 0) {
    param_2 = (int *)&stack0xffffffcc;
    ppiVar7 = (int **)this;
    FUN_10006eee(&stack0xffffffcc,"msgs//msg");
    local_8._0_1_ = 2;
    this_00 = *(void **)((int)this + 0x2c);
    if (this_00 != (void *)0x0) goto LAB_10007d46;
    do {
      _com_issue_error(-0x7fffbffd);
      this_00 = extraout_ECX;
LAB_10007d46:
      local_8._0_1_ = 1;
      FUN_10009dac(this_00,&local_18,(int *)ppiVar7);
      local_8._0_1_ = 3;
      if (local_18 == (IUnknown *)0x0) goto LAB_10007eb9;
      iVar6 = 0;
      while (local_18 != (IUnknown *)0x0) {
        ppiVar7 = (int **)0x10007d7a;
        iVar3 = FUN_100081a7(local_18);
        if (iVar3 <= iVar6) goto LAB_10007eb9;
        if (local_18 == (IUnknown *)0x0) break;
        piVar4 = (int *)FUN_1000810e(local_18,&param_2);
        local_8._0_1_ = 4;
        FUN_10006a77(local_14,piVar4);
        local_8 = CONCAT31(local_8._1_3_,3);
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))();
        }
        ppiVar7 = (int **)param_1;
        if (param_1 != (int *)0x0) {
          InterlockedIncrement(param_1 + 2);
        }
        local_8._0_1_ = 5;
        if (local_14[0] == (int *)0x0) break;
        local_8._0_1_ = 3;
        ppiVar7 = (int **)FUN_10009e1a(local_14[0],&local_1c,(int *)ppiVar7);
        local_8._0_1_ = 6;
        FUN_10006a77(local_14,(int *)ppiVar7);
        local_8._0_1_ = 3;
        if (local_1c != (int **)0x0) {
          ppiVar7 = local_1c;
          (*(code *)(*local_1c)[2])();
        }
        piVar5 = local_14[0];
        if (local_14[0] != (int *)0x0) {
          param_2 = (int *)0x0;
          local_8._0_1_ = 7;
          if (local_14[0] == (int *)0x0) break;
          local_8._0_1_ = 7;
          ppiVar7 = &param_2;
          param_2 = (int *)0x0;
          (**(code **)(*local_14[0] + 0x34))(local_14[0]);
          if (param_2 == (int *)0x0) {
            FUN_1000708c(param_3,"");
          }
          else {
            if (param_2 == (int *)0x0) break;
            piVar4 = (int *)FUN_100082b3(param_2,&local_1c);
            local_8._0_1_ = 8;
            FUN_10007056(param_3,piVar4);
            local_8._0_1_ = 7;
            if (local_1c != (int **)0x0) {
              FUN_10008b2c((int *)local_1c);
              local_1c = (int **)0x0;
            }
          }
          *(undefined1 *)piVar1 = 1;
          local_8._0_1_ = 3;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))();
          }
          goto LAB_10007eb9;
        }
        iVar6 = iVar6 + 1;
      }
    } while( true );
  }
LAB_10007eca:
  local_8._1_3_ = uVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    FUN_10008b2c(param_1);
  }
  return 0;
LAB_10007eb9:
  local_8._0_1_ = 1;
  uVar2 = local_8._1_3_;
  if (local_18 != (IUnknown *)0x0) {
    (*local_18->lpVtbl->Release)(local_18);
    uVar2 = local_8._1_3_;
  }
  goto LAB_10007eca;
}



// Function: FUN_10007ef6 at 10007ef6

void FUN_10007ef6(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                 undefined4 *param_6)

{
  FUN_10007f36(&PTR_DAT_10015084,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007f16 at 10007f16

void FUN_10007f16(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                 undefined4 *param_6)

{
  FUN_10007f36(&PTR_DAT_10015068,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007f36 at 10007f36

undefined4 __thiscall
FUN_10007f36(void *this,undefined4 param_1,int *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10003e9e(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      if (*param_2 == 0) {
        sVar2 = 0;
      }
      else {
        sVar2 = wcslen((wchar_t *)*param_2);
      }
      iVar5 = *(int *)((int)this + 0x18) + -1;
      if (-1 < iVar5) {
        iVar4 = iVar5 * 0xc;
        do {
          iVar3 = *(int *)((int)this + 0x14);
          if ((sVar2 == *(size_t *)(iVar4 + 4 + iVar3)) &&
             (iVar3 = memcmp(*(void **)(iVar4 + iVar3),(void *)*param_2,
                             *(int *)(iVar4 + 4 + iVar3) * 2), iVar3 == 0)) {
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



// Function: FUN_10007fe8 at 10007fe8

void FUN_10007fe8(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                 uint *param_6)

{
  int iVar1;
  
  iVar1 = FUN_10007f36(&PTR_DAT_10015084,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 < 0) {
    iVar1 = FUN_10007f36(&PTR_DAT_10015068,param_2,param_3,param_4,param_5,param_6);
    if (-1 < iVar1) {
      *param_6 = *param_6 | 0x10000;
    }
  }
  else {
    *param_6 = *param_6 | 0x20000;
  }
  return;
}



// Function: FUN_1000805a at 1000805a

undefined4 __fastcall FUN_1000805a(undefined4 *param_1)

{
  LPSTR pCVar1;
  
  if (param_1[1] == 0) {
    pCVar1 = ConvertBSTRToString((LPCWSTR)*param_1);
    param_1[1] = pCVar1;
  }
  return param_1[1];
}



// Function: FUN_10008075 at 10008075

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10008075(void *this,ulong *param_1)

{
  int iVar1;
  ulong local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008081;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0xb4))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e6d8);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_100080c3 at 100080c3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_100080c3(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x100080cf;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x34))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_1000810e at 1000810e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000810e(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x1c))(this);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e748);
  }
  *param_1 = 0;
  return;
}



// Function: FUN_1000815c at 1000815c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000815c(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008168;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x38))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_100081a7 at 100081a7

undefined4 __fastcall FUN_100081a7(IUnknown *param_1)

{
  ULONG UVar1;
  
  UVar1 = (*param_1->lpVtbl[2].Release)(param_1);
  if ((int)UVar1 < 0) {
    _com_issue_errorex(UVar1,param_1,(_GUID *)&DAT_1000e748);
  }
  return 0;
}



// Function: FUN_100081d2 at 100081d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_100081d2(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x100081de;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x40))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_1000821d at 1000821d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_1000821d(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008229;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x2c))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_10008268 at 10008268

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10008268(void *this,ulong *param_1)

{
  int iVar1;
  ulong local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008274;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x3c))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_100082b3 at 100082b3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100082b3(void *this,void *param_1)

{
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x100082bf;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x68))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  FUN_10006ea1(param_1,local_14[0],'\0');
  return param_1;
}



// Function: FUN_10008304 at 10008304

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008304(void *this,void *param_1)

{
  int iVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008310;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x88))(this,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  FUN_10006ea1(param_1,local_14[0],'\0');
  return param_1;
}



// Function: FUN_10008358 at 10008358

undefined4 FUN_10008358(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = _InlineIsEqualGUID(*(int **)((int)&PTR_DAT_100155b4 + uVar2),param_2);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 8);
  return 1;
}



// Function: FUN_10008384 at 10008384

void FUN_10008384(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100083a0(&PTR_DAT_10015084,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10008392 at 10008392

void FUN_10008392(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100083a0(&PTR_DAT_10015068,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100083a0 at 100083a0

void __thiscall
FUN_100083a0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  int *piVar1;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10003e9e(this,param_4);
  }
  piVar1 = *(int **)((int)this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))(piVar1,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_100083e1 at 100083e1

undefined4
FUN_100083e1(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  undefined4 uVar1;
  undefined **this;
  
  if ((param_2 & 0xffff0000) == 0x10000) {
    this = &PTR_DAT_10015068;
  }
  else {
    if ((param_2 & 0xffff0000) != 0x20000) {
      return 0x80020003;
    }
    this = &PTR_DAT_10015084;
    param_1 = param_1 + 4;
  }
  uVar1 = FUN_100083a0(this,param_1,param_2 & 0xffff,param_3,param_4,param_5,param_6,param_7,param_8
                       ,param_9);
  return uVar1;
}



// Function: FUN_10008467 at 10008467

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10008467(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  IUnknown *extraout_ECX;
  IUnknown *pIVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 4;
  local_8 = 0x10008473;
  uVar5 = 0;
  pIVar4 = (IUnknown *)param_1[10];
  if (pIVar4 == (IUnknown *)0x0) {
    pwVar6 = (wchar_t *)0x68;
LAB_10008526:
    uVar5 = FUN_1000779e((IID *)&DAT_1000e364,pwVar6,0,0,&DAT_1000e344,0x80004005,DAT_100159e8);
  }
  else {
    if (pIVar4 != (IUnknown *)0x0) goto LAB_1000849b;
    do {
      do {
        _com_issue_error(-0x7fffbffd);
        pIVar4 = extraout_ECX;
LAB_1000849b:
        uVar2 = FUN_10009716(pIVar4);
        if ((short)uVar2 == 0) {
          pwVar6 = (wchar_t *)0x67;
          goto LAB_10008526;
        }
      } while ((void *)piVar1[10] == (void *)0x0);
      puVar3 = (undefined4 *)FUN_10008075((void *)piVar1[10],(ulong *)local_14);
      local_8 = 0;
    } while ((void *)*puVar3 == (void *)0x0);
    puVar3 = (undefined4 *)FUN_100080c3((void *)*puVar3,&param_1);
    local_8._0_1_ = 1;
    _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
              ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)(piVar1 + 0xb),
               (IBinding *)*puVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    *(undefined2 *)(piVar1 + 0xc) = 0;
  }
  return uVar5;
}



// Function: FUN_1000853c at 1000853c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000853c(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  IUnknown *extraout_ECX;
  IUnknown *pIVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 4;
  local_8 = 0x10008548;
  uVar5 = 0;
  pIVar4 = (IUnknown *)param_1[10];
  if (pIVar4 == (IUnknown *)0x0) {
    pwVar6 = (wchar_t *)0x68;
LAB_100085fb:
    uVar5 = FUN_1000779e((IID *)&DAT_1000e364,pwVar6,0,0,&DAT_1000e344,0x80004005,DAT_100159e8);
  }
  else {
    if (pIVar4 != (IUnknown *)0x0) goto LAB_10008570;
    do {
      do {
        _com_issue_error(-0x7fffbffd);
        pIVar4 = extraout_ECX;
LAB_10008570:
        uVar2 = FUN_10009716(pIVar4);
        if ((short)uVar2 == 0) {
          pwVar6 = (wchar_t *)0x67;
          goto LAB_100085fb;
        }
      } while ((void *)piVar1[10] == (void *)0x0);
      puVar3 = (undefined4 *)FUN_10008075((void *)piVar1[10],(ulong *)local_14);
      local_8 = 0;
    } while ((void *)*puVar3 == (void *)0x0);
    puVar3 = (undefined4 *)FUN_1000815c((void *)*puVar3,&param_1);
    local_8._0_1_ = 1;
    _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
              ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)(piVar1 + 0xb),
               (IBinding *)*puVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    *(undefined2 *)(piVar1 + 0xc) = 0;
  }
  return uVar5;
}



// Function: FUN_10008611 at 10008611

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008611(int *param_1)

{
  _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *this;
  int *piVar1;
  undefined4 *puVar2;
  void *extraout_ECX;
  void *this_00;
  int iVar3;
  
  piVar1 = param_1;
  iVar3 = 0;
  if ((*(char *)((int)param_1 + 0x31) != '\x01') ||
     (iVar3 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x66,0,0,&DAT_1000e344,0x80004005,
                           DAT_100159e8), -1 < iVar3)) {
    if ((char)piVar1[0xc] == '\x01') {
      iVar3 = (**(code **)(*piVar1 + 0x58))(piVar1);
    }
    else {
      this = (_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)(piVar1 + 0xb);
      this_00 = *(void **)this;
      if (this_00 == (void *)0x0) {
        iVar3 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x68,0,0,&DAT_1000e344,0x80004005,
                             DAT_100159e8);
      }
      else {
        if (this_00 == (void *)0x0) {
          _com_issue_error(-0x7fffbffd);
          this_00 = extraout_ECX;
        }
        puVar2 = (undefined4 *)FUN_100081d2(this_00,&param_1);
        _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=(this,(IBinding *)*puVar2);
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
        if (*(int *)this == 0) {
          *(undefined1 *)((int)piVar1 + 0x31) = 1;
        }
      }
    }
  }
  return iVar3;
}



// Function: FUN_100086dd at 100086dd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100086dd(int *param_1)

{
  _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *this;
  int *piVar1;
  undefined4 *puVar2;
  void *extraout_ECX;
  void *this_00;
  int iVar3;
  
  piVar1 = param_1;
  iVar3 = 0;
  if (((char)param_1[0xc] != '\x01') ||
     (iVar3 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x67,0,0,&DAT_1000e344,0x80004005,
                           DAT_100159e8), -1 < iVar3)) {
    if (*(char *)((int)piVar1 + 0x31) == '\x01') {
      iVar3 = (**(code **)(*piVar1 + 0x5c))(piVar1);
    }
    else {
      this = (_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)(piVar1 + 0xb);
      this_00 = *(void **)this;
      if (this_00 == (void *)0x0) {
        iVar3 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x68,0,0,&DAT_1000e344,0x80004005,
                             DAT_100159e8);
      }
      else {
        if (this_00 == (void *)0x0) {
          _com_issue_error(-0x7fffbffd);
          this_00 = extraout_ECX;
        }
        puVar2 = (undefined4 *)FUN_10008268(this_00,(ulong *)&param_1);
        _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=(this,(IBinding *)*puVar2);
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
        if (*(int *)this == 0) {
          *(undefined1 *)(piVar1 + 0xc) = 1;
        }
      }
    }
  }
  return iVar3;
}



// Function: FUN_100087a9 at 100087a9

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100087a9(void *this,int *param_1,int *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int **ppiVar7;
  IID *pIVar8;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c [9];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  iVar6 = 0;
  piVar5 = (int *)0x0;
  local_34 = (int *)0x0;
  local_8 = 2;
  local_38 = (int *)this;
  if (*(char *)((int)this + 0x35) == '\x01') {
    iVar6 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x66,0,0,&DAT_1000e344,0x80004005,
                         DAT_100159e8);
  }
  if ((char)local_38[0xd] == '\x01') {
    iVar6 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x67,0,0,&DAT_1000e344,0x80004005,
                         DAT_100159e8);
  }
  if (iVar6 < 0) goto LAB_10008a9d;
  local_30 = local_38 + 0xc;
  if (*local_30 == 0) {
    FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x68,0,0,&DAT_1000e344,0x80004005,DAT_100159e8);
    goto LAB_10008a9d;
  }
  local_8._0_1_ = 3;
  local_2c[0] = (int *)&stack0xffffffa4;
  piVar5 = param_1;
  piVar4 = (int *)&stack0xffffffa4;
  if (param_1 != (int *)0x0) {
    InterlockedIncrement(param_1 + 2);
    piVar4 = local_2c[0];
  }
  local_2c[0] = piVar4;
  local_8._0_1_ = 4;
  ppiVar7 = &local_3c;
  pvVar1 = (void *)FUN_10007230(local_30);
  local_8._0_1_ = 3;
  piVar5 = FUN_10009e1a(pvVar1,ppiVar7,piVar5);
  local_8._0_1_ = 5;
  FUN_10006a77(&local_34,piVar5);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))();
  }
  piVar5 = local_34;
  if (local_34 == (int *)0x0) {
    piVar5 = param_1;
    local_2c[0] = (int *)&stack0xffffffa4;
    if (param_1 != (int *)0x0) {
      local_2c[0] = (int *)&stack0xffffffa4;
      InterlockedIncrement(param_1 + 2);
    }
    local_8._0_1_ = 6;
    local_3c = local_38 + 0xb;
    ppiVar7 = &local_40;
    pvVar1 = (void *)FUN_1000720c(local_3c);
    local_8._0_1_ = 3;
    puVar2 = FUN_10008d27(pvVar1,ppiVar7,piVar5);
    local_8._0_1_ = 7;
    pIVar8 = (IID *)*puVar2;
    ppiVar7 = &local_44;
    pvVar1 = (void *)FUN_10007230(local_30);
    piVar5 = (int *)FUN_10008cb7(pvVar1,ppiVar7,pIVar8);
    local_8._0_1_ = 8;
    FUN_10006a77(&local_34,piVar5);
    local_8._0_1_ = 7;
    if (local_44 != (int *)0x0) {
      (**(code **)(*local_44 + 8))();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_40 != (int *)0x0) {
      (**(code **)(*local_40 + 8))();
    }
    piVar5 = local_34;
    if (local_34 != (int *)0x0) {
      local_2c[0] = (int *)&stack0xffffffa4;
      piVar4 = param_2;
      piVar3 = (int *)&stack0xffffffa4;
      if (param_2 != (int *)0x0) {
        InterlockedIncrement(param_2 + 2);
        piVar3 = local_2c[0];
      }
      local_2c[0] = piVar3;
      local_8._0_1_ = 9;
      ppiVar7 = &local_38;
      pvVar1 = (void *)FUN_1000720c(local_3c);
      local_8._0_1_ = 3;
      puVar2 = FUN_10008d95(pvVar1,ppiVar7,piVar4);
      local_8 = CONCAT31(local_8._1_3_,10);
      pIVar8 = (IID *)*puVar2;
      ppiVar7 = &local_30;
      pvVar1 = (void *)FUN_1000721e((int *)&local_34);
      FUN_10008cb7(pvVar1,ppiVar7,pIVar8);
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))();
      }
      piVar4 = local_38;
      goto LAB_100089f8;
    }
  }
  else {
    piVar4 = param_2;
    local_40 = (int *)&stack0xffffffa4;
    if (param_2 != (int *)0x0) {
      local_40 = (int *)&stack0xffffffa4;
      InterlockedIncrement(param_2 + 2);
    }
    local_8._0_1_ = 0xb;
    ppiVar7 = local_2c;
    pvVar1 = (void *)FUN_1000721e((int *)&local_34);
    piVar3 = (int *)FUN_100080c3(pvVar1,ppiVar7);
    local_8._0_1_ = 0xc;
    pvVar1 = (void *)FUN_10007230(piVar3);
    local_8._0_1_ = 0xd;
    FUN_10008ada(pvVar1,piVar4);
    piVar4 = local_2c[0];
LAB_100089f8:
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))();
    }
  }
  local_8 = 0;
LAB_10008a9d:
  local_8._0_1_ = 1;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    FUN_10008b2c(param_1);
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    FUN_10008b2c(param_2);
  }
  FUN_1000a677();
  return;
}



// Function: Catch@10008a0e at 10008a0e

undefined * Catch_10008a0e(void)

{
  undefined4 *puVar1;
  char *pcVar2;
  void *pvVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  pvVar3 = *(void **)(unaff_EBP + -0x44);
  puVar1 = (undefined4 *)FUN_10007a40(pvVar3,(void *)(unaff_EBP + -0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)((int)pvVar3 + 4);
  if ((undefined4 *)*puVar1 == (undefined4 *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = (char *)FUN_1000805a((undefined4 *)*puVar1);
  }
  uVar4 = *(undefined4 *)(unaff_EBP + -0x28);
  pvVar3 = FUN_10007ae8(pvVar3,(void *)(unaff_EBP + -0x24));
  uVar4 = FUN_10007ac6(pcVar2,pvVar3,uVar4);
  *(undefined4 *)(unaff_EBP + -0x28) = uVar4;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  if (*(int **)(unaff_EBP + -0x2c) != (int *)0x0) {
    FUN_10008b2c(*(int **)(unaff_EBP + -0x2c));
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  }
  return &DAT_10008a6c;
}



// Function: FUN_10008ada at 10008ada

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_10008ada(void *this,int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_2c;
  void *pvStack_28;
  int iStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iStack_24 = 0;
  }
  else {
    iStack_24 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  puVar2 = &uStack_2c;
  uStack_2c = 0x10008b00;
  pvStack_28 = this;
  iVar1 = (**(code **)(*this + 0x6c))();
  if (iVar1 < 0) {
    puVar2[-1] = &DAT_1000e738;
    puVar2[-2] = this;
    puVar2[-3] = iVar1;
    puVar2[-4] = 0x10008b10;
    _com_issue_errorex(puVar2[-3],(IUnknown *)puVar2[-2],(_GUID *)puVar2[-1]);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    puVar2[-1] = 0x10008b20;
    FUN_10008b2c(param_1);
  }
  puVar2[-1] = 0x10008b29;
  return;
}



// Function: FUN_10008b2c at 10008b2c

LONG __fastcall FUN_10008b2c(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    FUN_10008c55(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



// Function: FUN_10008b57 at 10008b57

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10008b57(int param_1)

{
  void *extraout_ECX;
  void *this;
  int *piVar1;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    piVar1 = DAT_1001569c;
    if (DAT_1001569c != (int *)0x0) {
      InterlockedIncrement(DAT_1001569c + 2);
    }
    this = *(void **)(param_1 + 0x2c);
    if (this == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      this = extraout_ECX;
    }
    FUN_100097da(this,piVar1);
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_100058eb((int *)(param_1 + 0x30));
    }
  }
  *(undefined2 *)(param_1 + 0x34) = 0x101;
  return;
}



// Function: FUN_10008bcc at 10008bcc

undefined4 __cdecl FUN_10008bcc(int param_1,uint param_2,uint *param_3)

{
  if (param_1 + param_2 < param_2) {
    return 0x80070216;
  }
  *param_3 = param_1 + param_2;
  return 0;
}



// Function: FUN_10008bea at 10008bea

undefined4 __cdecl FUN_10008bea(uint param_1,uint param_2,undefined4 *param_3)

{
  if ((int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20) != 0) {
    return 0x80070216;
  }
  *param_3 = (int)((ulonglong)param_1 * (ulonglong)param_2);
  return 0;
}



// Function: FUN_10008c55 at 10008c55

void __fastcall FUN_10008c55(int *param_1)

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



// Function: FUN_10008c7d at 10008c7d

void __fastcall FUN_10008c7d(undefined4 *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    FUN_10008b2c((int *)*param_1);
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10008cb7 at 10008cb7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10008cb7(void *this,undefined4 *param_1,IID *param_2)

{
  int iVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008cc3;
                    /* WARNING: Load size is inaccurate */
  local_14[0] = 0;
  iVar1 = (**(code **)(*this + 0x54))(this,param_2,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  return;
}



// Function: FUN_10008d05 at 10008d05

int __thiscall FUN_10008d05(void *this,char param_1)

{
  int *piVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else if (param_1 == '\0') {
    iVar2 = *piVar1;
  }
  else {
    iVar2 = FUN_10007a12(piVar1);
  }
  return iVar2;
}



// Function: FUN_10008d27 at 10008d27

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008d27(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 1;
  local_14[0] = 0;
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_2;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0xbc))(this,iVar1,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e6d8);
  }
  *param_1 = local_14[0];
  local_8 = local_8 & 0xffffff00;
  if (param_2 != (int *)0x0) {
    FUN_10008b2c(param_2);
  }
  return param_1;
}



// Function: FUN_10008d95 at 10008d95

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008d95(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 1;
  local_14[0] = 0;
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_2;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0xc4))(this,iVar1,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e6d8);
  }
  *param_1 = local_14[0];
  local_8 = local_8 & 0xffffff00;
  if (param_2 != (int *)0x0) {
    FUN_10008b2c(param_2);
  }
  return param_1;
}



// Function: FUN_10008e03 at 10008e03

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008e03(int param_1,long *param_2)

{
  int iVar1;
  wchar_t *_Str;
  long lVar2;
  int *piVar3;
  int *piVar4;
  int **ppiVar5;
  int *local_18;
  char local_11 [9];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008e0f;
  FUN_10006f38(&local_18,0x1000ef10);
  local_8 = 0;
  local_11[0] = '\0';
  if (param_2 == (long *)0x0) {
    iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e354,0x80004003,
                         DAT_100159e8);
  }
  else {
    ppiVar5 = &local_18;
    piVar4 = (int *)local_11;
    *param_2 = 0;
    piVar3 = DAT_10015694;
    if (DAT_10015694 != (int *)0x0) {
      InterlockedIncrement(DAT_10015694 + 2);
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007ced((void *)(param_1 + -8),piVar3,piVar4,ppiVar5);
    if (-1 < iVar1) {
      if (local_11[0] == '\0') {
        *param_2 = 0;
      }
      else {
        if (local_18 == (int *)0x0) {
          _Str = (wchar_t *)0x0;
        }
        else {
          _Str = (wchar_t *)*local_18;
        }
        lVar2 = wcstol(_Str,(wchar_t **)0x0,10);
        *param_2 = lVar2;
      }
    }
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    FUN_10008b2c(local_18);
  }
  return iVar1;
}



// Function: FUN_10008ed7 at 10008ed7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10008ed7(int param_1,long *param_2)

{
  int iVar1;
  wchar_t *_Str;
  long lVar2;
  int *piVar3;
  int *piVar4;
  int **ppiVar5;
  int *local_18;
  char local_11 [9];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x10008ee3;
  FUN_10006f38(&local_18,0x1000ef10);
  local_8 = 0;
  local_11[0] = '\0';
  if (param_2 == (long *)0x0) {
    iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e354,0x80004003,
                         DAT_100159e8);
  }
  else {
    ppiVar5 = &local_18;
    piVar4 = (int *)local_11;
    *param_2 = 0;
    piVar3 = DAT_1001567c;
    if (DAT_1001567c != (int *)0x0) {
      InterlockedIncrement(DAT_1001567c + 2);
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007ced((void *)(param_1 + -8),piVar3,piVar4,ppiVar5);
    if (-1 < iVar1) {
      if (local_11[0] == '\0') {
        *param_2 = 0;
      }
      else {
        if (local_18 == (int *)0x0) {
          _Str = (wchar_t *)0x0;
        }
        else {
          _Str = (wchar_t *)*local_18;
        }
        lVar2 = wcstol(_Str,(wchar_t **)0x0,10);
        *param_2 = lVar2;
      }
    }
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    FUN_10008b2c(local_18);
  }
  return iVar1;
}



// Function: FUN_10008fab at 10008fab

undefined4 FUN_10008fab(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (int *)0x0) {
    uVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    *param_2 = (*(char *)(param_1 + 0x30) != '\x01') - 1;
  }
  return uVar1;
}



// Function: FUN_10008ff0 at 10008ff0

undefined4 FUN_10008ff0(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == (int *)0x0) {
    uVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    *param_2 = (*(char *)(param_1 + 0x31) != '\x01') - 1;
  }
  return uVar1;
}



// Function: FUN_10009035 at 10009035

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10009035(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  piVar3 = (int *)0x0;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    ppiVar5 = local_14;
    *param_2 = (int)&PTR_1000ef10;
    ppiVar4 = DAT_1001568c;
    if (DAT_1001568c != (int **)0x0) {
      InterlockedIncrement((LONG *)(DAT_1001568c + 2));
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007b1b((void *)(param_1 + -4),ppiVar4,ppiVar5);
    piVar3 = local_14[0];
    if (-1 < iVar1) {
      if (local_14[0] == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_10007a12(local_14[0]);
      }
      *param_2 = iVar2;
    }
  }
  local_8 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    FUN_10008b2c(piVar3);
  }
  return iVar1;
}



// Function: FUN_100090e7 at 100090e7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100090e7(int param_1,long *param_2)

{
  int iVar1;
  wchar_t *_Str;
  long lVar2;
  int **ppiVar3;
  int **ppiVar4;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x100090f3;
  FUN_10006f38(local_14,0x1000ef10);
  local_8 = 0;
  if (param_2 == (long *)0x0) {
    iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    ppiVar4 = local_14;
    *param_2 = 0;
    ppiVar3 = DAT_10015688;
    if (DAT_10015688 != (int **)0x0) {
      InterlockedIncrement((LONG *)(DAT_10015688 + 2));
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007b1b((void *)(param_1 + -4),ppiVar3,ppiVar4);
    if (-1 < iVar1) {
      if (local_14[0] == (int *)0x0) {
        _Str = (wchar_t *)0x0;
      }
      else {
        _Str = (wchar_t *)*local_14[0];
      }
      lVar2 = wcstol(_Str,(wchar_t **)0x0,10);
      *param_2 = lVar2;
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    FUN_10008b2c(local_14[0]);
  }
  return iVar1;
}



// Function: FUN_100091a9 at 100091a9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100091a9(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  piVar3 = (int *)0x0;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    ppiVar5 = local_14;
    *param_2 = (int)&PTR_1000ef10;
    ppiVar4 = DAT_100156a4;
    if (DAT_100156a4 != (int **)0x0) {
      InterlockedIncrement((LONG *)(DAT_100156a4 + 2));
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007b1b((void *)(param_1 + -4),ppiVar4,ppiVar5);
    piVar3 = local_14[0];
    if (-1 < iVar1) {
      if (local_14[0] == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_10007a12(local_14[0]);
      }
      *param_2 = iVar2;
    }
  }
  local_8 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    FUN_10008b2c(piVar3);
  }
  return iVar1;
}



// Function: FUN_1000925b at 1000925b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000925b(int param_1,long *param_2)

{
  int *piVar1;
  int iVar2;
  wchar_t *_Str;
  long lVar3;
  int **ppiVar4;
  int **ppiVar5;
  int **ppiVar6;
  int *local_24;
  int *local_20;
  int **local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  ppiVar4 = (int **)0x0;
  local_1c = (int **)0x0;
  local_8 = 0;
  FUN_10006f38(local_14,0x1000ef10);
  local_8._0_1_ = 1;
  if (param_2 == (long *)0x0) {
    iVar2 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
    piVar1 = local_14[0];
  }
  else {
    *param_2 = 0;
    FUN_10006f38(&local_18,0x1000f308);
    local_8._0_1_ = 2;
    piVar1 = FUN_10007254(&DAT_100156a4,(int *)&local_24,(int *)&local_18);
    local_8._0_1_ = 3;
    piVar1 = FUN_10007254(piVar1,(int *)&local_20,&DAT_10015690);
    local_8._0_1_ = 4;
    FUN_10007056(&local_1c,piVar1);
    local_8._0_1_ = 3;
    if (local_20 != (int *)0x0) {
      FUN_10008b2c(local_20);
      local_20 = (int *)0x0;
    }
    local_8._0_1_ = 2;
    if (local_24 != (int *)0x0) {
      FUN_10008b2c(local_24);
      local_24 = (int *)0x0;
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18 != (int *)0x0) {
      FUN_10008b2c(local_18);
      local_18 = (int *)0x0;
    }
    ppiVar4 = local_1c;
    ppiVar6 = local_14;
    local_24 = (int *)&stack0xffffffc4;
    ppiVar5 = local_1c;
    piVar1 = (int *)&stack0xffffffc4;
    if (local_1c != (int **)0x0) {
      InterlockedIncrement((LONG *)(local_1c + 2));
      piVar1 = local_24;
    }
    local_24 = piVar1;
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_8._0_1_ = 1;
    iVar2 = FUN_10007b1b((void *)(param_1 + -4),ppiVar5,ppiVar6);
    piVar1 = local_14[0];
    if (-1 < iVar2) {
      if (local_14[0] == (int *)0x0) {
        _Str = (wchar_t *)0x0;
      }
      else {
        _Str = (wchar_t *)*local_14[0];
      }
      lVar3 = wcstol(_Str,(wchar_t **)0x0,10);
      *param_2 = lVar3;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar1 != (int *)0x0) {
    FUN_10008b2c(piVar1);
    local_14[0] = (int *)0x0;
  }
  local_8 = 0xffffffff;
  if (ppiVar4 != (int **)0x0) {
    FUN_10008b2c((int *)ppiVar4);
  }
  return iVar2;
}



// Function: FUN_100093b7 at 100093b7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100093b7(int param_1,long *param_2)

{
  int iVar1;
  wchar_t *_Str;
  long lVar2;
  int **ppiVar3;
  int **ppiVar4;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x100093c3;
  FUN_10006f38(local_14,0x1000ef10);
  local_8 = 0;
  if (param_2 == (long *)0x0) {
    iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    ppiVar4 = local_14;
    *param_2 = 0;
    ppiVar3 = DAT_100156a0;
    if (DAT_100156a0 != (int **)0x0) {
      InterlockedIncrement((LONG *)(DAT_100156a0 + 2));
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007b1b((void *)(param_1 + -4),ppiVar3,ppiVar4);
    if (-1 < iVar1) {
      if (local_14[0] == (int *)0x0) {
        _Str = (wchar_t *)0x0;
      }
      else {
        _Str = (wchar_t *)*local_14[0];
      }
      lVar2 = wcstol(_Str,(wchar_t **)0x0,10);
      *param_2 = lVar2;
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    FUN_10008b2c(local_14[0]);
  }
  return iVar1;
}



// Function: FUN_10009479 at 10009479

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10009479(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  piVar3 = (int *)0x0;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    ppiVar5 = local_14;
    *param_2 = (int)&PTR_1000ef10;
    ppiVar4 = DAT_10015680;
    if (DAT_10015680 != (int **)0x0) {
      InterlockedIncrement((LONG *)(DAT_10015680 + 2));
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007b1b((void *)(param_1 + -4),ppiVar4,ppiVar5);
    piVar3 = local_14[0];
    if (-1 < iVar1) {
      if (local_14[0] == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_10007a12(local_14[0]);
      }
      *param_2 = iVar2;
    }
  }
  local_8 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    FUN_10008b2c(piVar3);
  }
  return iVar1;
}



// Function: FUN_1000952b at 1000952b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000952b(int param_1,undefined8 *param_2)

{
  int iVar1;
  wchar_t *_Src;
  int *piVar2;
  int **ppiVar3;
  int **ppiVar4;
  int *local_28;
  undefined1 local_24 [2];
  undefined1 local_22 [4];
  undefined1 local_1e [2];
  undefined1 local_1c [20];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x10009537;
  FUN_10006f38(&local_28,0x1000ef10);
  local_8 = 0;
  if (param_2 == (undefined8 *)0x0) {
    FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,DAT_100159e8);
    piVar2 = local_28;
  }
  else {
    ppiVar4 = &local_28;
    *param_2 = 0;
    ppiVar3 = DAT_10015698;
    if (DAT_10015698 != (int **)0x0) {
      InterlockedIncrement((LONG *)(DAT_10015698 + 2));
    }
    local_8 = local_8 & 0xffffff00;
    iVar1 = FUN_10007b1b((void *)(param_1 + -4),ppiVar3,ppiVar4);
    piVar2 = local_28;
    if (-1 < iVar1) {
      if (local_28 == (int *)0x0) {
        _Src = (wchar_t *)0x0;
      }
      else {
        _Src = (wchar_t *)*local_28;
      }
      iVar1 = swscanf(_Src,L"%u-%u-%uT%u:%u:%u",local_24,local_22,local_1e,local_1c);
      if (iVar1 != 0xffff) {
        Ordinal_184();
      }
      *param_2 = 0;
    }
  }
  local_8 = 0xffffffff;
  if (piVar2 != (int *)0x0) {
    FUN_10008b2c(piVar2);
    local_28 = (int *)0x0;
  }
  FUN_1000a668();
  return;
}



// Function: FUN_10009642 at 10009642

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009642(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void *extraout_ECX;
  void *this;
  int *piVar4;
  undefined4 uVar5;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 4;
  piVar4 = (int *)0x0;
  uVar5 = 0;
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (param_2 == (int *)0x0) {
    uVar5 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x65,0,0,&DAT_1000e344,0x80004003,
                         DAT_100159e8);
  }
  else {
    this = (void *)param_1[10];
    if (this != (void *)0x0) goto LAB_10009675;
    do {
      _com_issue_error(-0x7fffbffd);
      this = extraout_ECX;
LAB_10009675:
      puVar2 = (undefined4 *)FUN_10008075(this,(ulong *)&param_1);
      local_8._0_1_ = 1;
    } while ((void *)*puVar2 == (void *)0x0);
    piVar4 = (int *)FUN_10008304((void *)*puVar2,&param_2);
    local_8._0_1_ = 2;
    FUN_10007056(local_14,piVar4);
    local_8._0_1_ = 1;
    if (param_2 != (int *)0x0) {
      FUN_10008b2c(param_2);
      param_2 = (int *)0x0;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    piVar4 = local_14[0];
    if (local_14[0] == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_10007a12(local_14[0]);
    }
    *piVar1 = iVar3;
  }
  local_8 = 0xffffffff;
  if (piVar4 != (int *)0x0) {
    FUN_10008b2c(piVar4);
  }
  return uVar5;
}



// Function: FUN_10009716 at 10009716

uint __fastcall FUN_10009716(IUnknown *param_1)

{
  uint uVar1;
  uint extraout_EAX;
  
  uVar1 = (*param_1->lpVtbl[7].AddRef)(param_1);
  if ((int)uVar1 < 0) {
    _com_issue_errorex(uVar1,param_1,(_GUID *)&DAT_1000e738);
    uVar1 = extraout_EAX;
  }
  return uVar1 & 0xffff0000;
}



// Function: FUN_10009742 at 10009742

undefined4 __fastcall FUN_10009742(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)*param_1;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    uVar2 = Ordinal_7(*piVar1);
    return uVar2;
  }
  return 0;
}



// Function: FUN_10009759 at 10009759

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10009759(int *param_1,int param_2)

{
  int iVar1;
  void *extraout_ECX;
  void *this;
  int *extraout_var;
  int *piVar2;
  
  if (param_2 != 0) {
    FUN_10006f38(&stack0xffffffdc,param_2);
    this = (void *)param_1[10];
    piVar2 = extraout_var;
    if (this == (void *)0x0) {
      _com_issue_error(-0x7fffbffd);
      this = extraout_ECX;
    }
    iVar1 = FUN_100097da(this,piVar2);
    if ((short)iVar1 == -1) goto LAB_100097cc;
  }
  FUN_10008b57((int)(param_1 + -1));
  iVar1 = FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x68,0,0,&DAT_1000e344,0x80070057,
                       DAT_100159e8);
  if (iVar1 < 0) {
    return;
  }
LAB_100097cc:
  (**(code **)(*param_1 + 0x58))();
  return;
}



// Function: FUN_100097da at 100097da

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100097da(void *this,int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int extraout_EAX;
  undefined2 uVar4;
  LONG LVar3;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0;
  local_14[0] = 0;
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *param_1;
  }
                    /* WARNING: Load size is inaccurate */
  iVar2 = (**(code **)(*this + 0x104))(this,iVar2,local_14);
  if (iVar2 < 0) {
    _com_issue_errorex(iVar2,(IUnknown *)this,(_GUID *)&DAT_1000e6d8);
    iVar2 = extraout_EAX;
  }
  uVar4 = (undefined2)((uint)iVar2 >> 0x10);
  uVar1 = (undefined2)local_14[0];
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    LVar3 = FUN_10008b2c(param_1);
    uVar4 = (undefined2)((uint)LVar3 >> 0x10);
  }
  return CONCAT22(uVar4,uVar1);
}



// Function: FUN_1000983e at 1000983e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000983e(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *local_40;
  wchar_t local_3c [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_40 = (int *)0x0;
  local_8 = 0;
  FUN_10009e88(local_3c,0x1000f314);
  FUN_100070fe(&local_40,(int)local_3c);
  piVar1 = local_40;
  piVar3 = local_40;
  if (local_40 != (int *)0x0) {
    InterlockedIncrement(local_40 + 2);
  }
  local_8._0_1_ = 1;
  piVar2 = DAT_10015694;
  if (DAT_10015694 != (int *)0x0) {
    InterlockedIncrement(DAT_10015694 + 2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100087a9((void *)(param_1 + -8),piVar2,piVar3);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    FUN_10008b2c(piVar1);
    local_40 = (int *)0x0;
  }
  FUN_1000a668();
  return;
}



// Function: FUN_100098dd at 100098dd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100098dd(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *local_40;
  wchar_t local_3c [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_40 = (int *)0x0;
  local_8 = 0;
  FUN_10009e88(local_3c,0x1000f314);
  FUN_100070fe(&local_40,(int)local_3c);
  piVar1 = local_40;
  piVar3 = local_40;
  if (local_40 != (int *)0x0) {
    InterlockedIncrement(local_40 + 2);
  }
  local_8._0_1_ = 1;
  piVar2 = DAT_1001567c;
  if (DAT_1001567c != (int *)0x0) {
    InterlockedIncrement(DAT_1001567c + 2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100087a9((void *)(param_1 + -8),piVar2,piVar3);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    FUN_10008b2c(piVar1);
    local_40 = (int *)0x0;
  }
  FUN_1000a668();
  return;
}



// Function: FUN_1000997c at 1000997c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000997c(int param_1,int param_2)

{
  int *piVar1;
  int *extraout_var;
  int *piVar2;
  
  FUN_10006f38(&stack0xffffffd8,param_2);
  piVar1 = DAT_1001568c;
  piVar2 = extraout_var;
  if (DAT_1001568c != (int *)0x0) {
    InterlockedIncrement(DAT_1001568c + 2);
  }
  FUN_100087a9((void *)(param_1 + -4),piVar1,piVar2);
  return;
}



// Function: FUN_100099d5 at 100099d5

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100099d5(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *local_40;
  wchar_t local_3c [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_40 = (int *)0x0;
  local_8 = 0;
  FUN_10009e88(local_3c,0x1000f30c);
  FUN_100070fe(&local_40,(int)local_3c);
  piVar1 = local_40;
  piVar3 = local_40;
  if (local_40 != (int *)0x0) {
    InterlockedIncrement(local_40 + 2);
  }
  local_8._0_1_ = 1;
  piVar2 = DAT_10015688;
  if (DAT_10015688 != (int *)0x0) {
    InterlockedIncrement(DAT_10015688 + 2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100087a9((void *)(param_1 + -4),piVar2,piVar3);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    FUN_10008b2c(piVar1);
    local_40 = (int *)0x0;
  }
  FUN_1000a668();
  return;
}



// Function: FUN_10009a74 at 10009a74

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10009a74(int param_1,int param_2)

{
  int *piVar1;
  int *extraout_var;
  int *piVar2;
  
  FUN_10006f38(&stack0xffffffd8,param_2);
  piVar1 = DAT_100156a4;
  piVar2 = extraout_var;
  if (DAT_100156a4 != (int *)0x0) {
    InterlockedIncrement(DAT_100156a4 + 2);
  }
  FUN_100087a9((void *)(param_1 + -4),piVar1,piVar2);
  return;
}



// Function: FUN_10009acd at 10009acd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009acd(int param_1)

{
  IID *this;
  IBinding *pIVar1;
  int *piVar2;
  undefined4 *puVar3;
  code *pcVar4;
  void *extraout_ECX;
  void *this_00;
  IBinding *pIVar5;
  IBinding *pIVar6;
  IBinding *local_4c;
  int local_48;
  IID *local_44;
  IBinding *local_40;
  wchar_t local_3c [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_48 = param_1;
  local_4c = (IBinding *)0x0;
  local_44 = (IID *)0x0;
  local_8 = 1;
  FUN_10009e88(local_3c,0x1000f30c);
  FUN_100070fe(&local_4c,(int)local_3c);
  pcVar4 = InterlockedIncrement_exref;
  pIVar6 = DAT_100156a4;
  if (DAT_100156a4 != (IBinding *)0x0) {
    InterlockedIncrement((LONG *)(DAT_100156a4 + 8));
  }
  local_8._0_1_ = 2;
  pIVar5 = (IBinding *)(param_1 + 0x2c);
  this_00 = *(void **)pIVar5;
  if (this_00 != (void *)0x0) goto LAB_10009b47;
LAB_10009b3d:
  do {
    _com_issue_error(-0x7fffbffd);
    this_00 = extraout_ECX;
LAB_10009b47:
    local_8._0_1_ = 1;
    piVar2 = FUN_10009e1a(this_00,&local_40,(int *)pIVar6);
    local_8._0_1_ = 3;
    FUN_10006a77(&local_44,piVar2);
    local_8._0_1_ = 1;
    if (local_40 != (IBinding *)0x0) {
      (**(code **)(*(int *)local_40 + 8))();
    }
    if (local_44 == (IID *)0x0) {
      pIVar6 = DAT_100156a4;
      if (DAT_100156a4 != (IBinding *)0x0) {
        (*pcVar4)();
      }
      local_8._0_1_ = 4;
      if (*(void **)(local_48 + 0x28) == (void *)0x0) goto LAB_10009b3d;
      local_8._0_1_ = 1;
      puVar3 = FUN_10008d27(*(void **)(local_48 + 0x28),&local_40,(int *)pIVar6);
      local_8._0_1_ = 5;
      pIVar6 = (IBinding *)*puVar3;
      _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
                ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)&local_44,pIVar6);
      local_8._0_1_ = 1;
      if (local_40 != (IBinding *)0x0) {
        pIVar6 = local_40;
        (**(code **)(*(int *)local_40 + 8))();
      }
      if (local_44 != (IID *)0x0) {
        if (*(void **)pIVar5 == (void *)0x0) goto LAB_10009b3d;
        piVar2 = (int *)FUN_10008cb7(*(void **)pIVar5,&local_40,local_44);
        local_8._0_1_ = 6;
        FUN_10006a77(&local_44,piVar2);
        local_8._0_1_ = 1;
        if (local_40 != (IBinding *)0x0) {
          (**(code **)(*(int *)local_40 + 8))();
        }
      }
    }
    this = local_44;
    pIVar5 = local_4c;
    if (local_44 == (IID *)0x0) {
      FUN_1000779e((IID *)&DAT_1000e364,(wchar_t *)0x68,0,0,&DAT_1000e344,0x80004003,DAT_100159e8);
      goto LAB_10009ce2;
    }
    FUN_10006a28((void *)(local_48 + 0x2c),(int *)&local_44);
    pIVar6 = pIVar5;
    if (pIVar5 != (IBinding *)0x0) {
      (*pcVar4)();
    }
    local_8._0_1_ = 7;
    local_40 = (IBinding *)&stack0xffffff98;
    piVar2 = DAT_10015690;
    pIVar1 = (IBinding *)&stack0xffffff98;
    if (DAT_10015690 != (int *)0x0) {
      (*pcVar4)(DAT_10015690 + 2);
      pIVar1 = local_40;
    }
    local_40 = pIVar1;
    local_8._0_1_ = 1;
    pcVar4 = (code *)FUN_100087a9((void *)(local_48 + -4),piVar2,(int *)pIVar6);
    if (this != (IID *)0x0) {
      puVar3 = (undefined4 *)FUN_1000821d(this,&local_40);
      local_8._0_1_ = 9;
      _CIP<struct_IBinding,&struct__GUID_const_IID_IBinding>::operator=
                ((_CIP<struct_IBinding,&struct__GUID_const_IID_IBinding> *)(local_48 + 0x2c),
                 (IBinding *)*puVar3);
      local_8._0_1_ = 1;
      if (local_40 != (IBinding *)0x0) {
        (**(code **)(*(int *)local_40 + 8))();
      }
LAB_10009ce2:
      local_8 = (uint)local_8._1_3_ << 8;
      if (this != (IID *)0x0) {
        (**(code **)(this->Data1 + 8))();
      }
      local_8 = 0xffffffff;
      if (pIVar5 != (IBinding *)0x0) {
        FUN_10008b2c((int *)pIVar5);
        local_4c = (IBinding *)0x0;
      }
      FUN_1000a668();
      return;
    }
  } while( true );
}



// Function: FUN_10009d0d at 10009d0d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10009d0d(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *local_40;
  wchar_t local_3c [26];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_40 = (int *)0x0;
  local_8 = 0;
  FUN_10009e88(local_3c,0x1000f30c);
  FUN_100070fe(&local_40,(int)local_3c);
  piVar1 = local_40;
  piVar3 = local_40;
  if (local_40 != (int *)0x0) {
    InterlockedIncrement(local_40 + 2);
  }
  local_8._0_1_ = 1;
  piVar2 = DAT_100156a0;
  if (DAT_100156a0 != (int *)0x0) {
    InterlockedIncrement(DAT_100156a0 + 2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100087a9((void *)(param_1 + -4),piVar2,piVar3);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    FUN_10008b2c(piVar1);
    local_40 = (int *)0x0;
  }
  FUN_1000a668();
  return;
}



// Function: FUN_10009dac at 10009dac

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10009dac(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 1;
  local_14[0] = 0;
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_2;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x90))(this,iVar1,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  local_8 = local_8 & 0xffffff00;
  if (param_2 != (int *)0x0) {
    FUN_10008b2c(param_2);
  }
  return param_1;
}



// Function: FUN_10009e1a at 10009e1a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10009e1a(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 1;
  local_14[0] = 0;
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_2;
  }
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x94))(this,iVar1,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,(IUnknown *)this,(_GUID *)&DAT_1000e738);
  }
  *param_1 = local_14[0];
  local_8 = local_8 & 0xffffff00;
  if (param_2 != (int *)0x0) {
    FUN_10008b2c(param_2);
  }
  return param_1;
}



// Function: FUN_10009e88 at 10009e88

void __cdecl FUN_10009e88(wchar_t *param_1,size_t param_2)

{
  va_list unaff_EBP;
  
  _vswprintf(param_1,param_2,(wchar_t *)&stack0x0000000c,unaff_EBP);
  return;
}



// Function: FUN_10009ea0 at 10009ea0

void __cdecl FUN_10009ea0(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = strcpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: `eh_vector_constructor_iterator' at 1000a022

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
  FUN_1000a07a();
  return;
}



// Function: FUN_1000a07a at 1000a07a

void FUN_1000a07a(void)

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



// Function: `eh_vector_destructor_iterator' at 1000a08a

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
  FUN_1000a0e9();
  return;
}



// Function: FUN_1000a0e9 at 1000a0e9

void FUN_1000a0e9(void)

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



// Function: FUN_1000a0f9 at 1000a0f9

undefined4 __cdecl FUN_1000a0f9(undefined4 *param_1)

{
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 != -0x1f928c9d) {
    return 0;
  }
  terminate();
  return extraout_EAX;
}



// Function: __ArrayUnwind at 1000a112

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



// Function: __onexit at 1000a1b2

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
  
  local_8 = &DAT_10013a08;
  uStack_c = 0x1000a1be;
  local_20[0] = DecodePointer(DAT_10015a8c);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10015a8c);
    local_24 = DecodePointer(DAT_10015a88);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10015a8c = EncodePointer(local_20[0]);
    DAT_10015a88 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000a24e();
  }
  return p_Var1;
}



// Function: FUN_1000a24e at 1000a24e

void FUN_1000a24e(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000a257

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2012 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: ___raise_securityfailure at 1000a26c

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_100159cc = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_100159cc == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}



// Function: ___report_gsfailure at 1000a2a9

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
  _DAT_100157a8 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_100157b0 = (undefined4)uVar9;
  _DAT_100157c0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_100157c4 = &stack0x00000004;
  _DAT_10015700 = 0x10001;
  _DAT_100156b0 = 0xc0000409;
  _DAT_100156b4 = 1;
  _DAT_100156c0 = 1;
  DAT_100156c4 = 2;
  _DAT_100156bc = unaff_retaddr;
  _DAT_1001578c = in_GS;
  _DAT_10015790 = in_FS;
  _DAT_10015794 = in_ES;
  _DAT_10015798 = in_DS;
  _DAT_1001579c = unaff_EDI;
  _DAT_100157a0 = unaff_ESI;
  _DAT_100157a4 = unaff_EBX;
  _DAT_100157ac = uVar3;
  _DAT_100157b4 = unaff_EBP;
  DAT_100157b8 = unaff_retaddr;
  _DAT_100157bc = in_CS;
  _DAT_100157c8 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10010f50);
  return;
}



// Function: ___report_rangecheckfailure at 1000a3a2

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}



// Function: ___report_securityfailure at 1000a3ae

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
  _DAT_100157a8 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_100157b0 = (undefined4)uVar9;
  _DAT_100157c0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_100157c4 = &param_1;
  _DAT_100156b0 = 0xc0000409;
  _DAT_100156b4 = 1;
  _DAT_100156c0 = 1;
  DAT_100156c4 = param_1;
  _DAT_100156bc = unaff_retaddr;
  _DAT_1001578c = in_GS;
  _DAT_10015790 = in_FS;
  _DAT_10015794 = in_ES;
  _DAT_10015798 = in_DS;
  _DAT_1001579c = unaff_EDI;
  _DAT_100157a0 = unaff_ESI;
  _DAT_100157a4 = unaff_EBX;
  _DAT_100157ac = uVar3;
  _DAT_100157b4 = unaff_EBP;
  DAT_100157b8 = unaff_retaddr;
  _DAT_100157bc = in_CS;
  _DAT_100157c8 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10010f50);
  return;
}



// Function: ___report_securityfailureEx at 1000a47c

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
  _DAT_100157c0 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_100157c4 = &param_1;
  _DAT_100156b0 = 0xc0000409;
  _DAT_100156b4 = 1;
  if ((param_2 != 0) && (param_3 == 0)) {
    param_2 = 0;
  }
  if (0xe < param_2) {
    param_2 = param_2 - 1;
  }
  _DAT_100156c0 = param_2 + 1;
  DAT_100156c4 = param_1;
  _DAT_100156bc = unaff_retaddr;
  _DAT_1001578c = in_GS;
  _DAT_10015790 = in_FS;
  _DAT_10015794 = in_ES;
  _DAT_10015798 = in_DS;
  _DAT_1001579c = unaff_EDI;
  _DAT_100157a0 = unaff_ESI;
  _DAT_100157a4 = unaff_EBX;
  _DAT_100157ac = uVar3;
  _DAT_100157b4 = unaff_EBP;
  DAT_100157b8 = unaff_retaddr;
  _DAT_100157bc = in_CS;
  _DAT_100157c8 = in_SS;
  for (local_8 = 0; _DAT_100157a8 = (undefined4)((ulonglong)uVar9 >> 0x20),
      _DAT_100157b0 = (undefined4)uVar9, local_8 < param_2; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_100156c8 + local_8 * 4) = *(undefined4 *)(param_3 + local_8 * 4);
    uVar9 = CONCAT44(_DAT_100157a8,_DAT_100157b0);
  }
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_10010f50);
  return;
}



// Function: FUN_1000a5a2 at 1000a5a2

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_1000a5a2(uint param_1)

{
  operator_new(param_1);
  FUN_1000a5ca();
  return;
}



// Function: Catch_All@1000a5bd at 1000a5bd

undefined * Catch_All_1000a5bd(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  return &DAT_1000a5c7;
}



// Function: FUN_1000a5ca at 1000a5ca

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000a5ca(void)

{
  return;
}



// Function: FUN_1000a5d0 at 1000a5d0

void FUN_1000a5d0(uint param_1)

{
  FUN_1000a5a2(param_1);
  return;
}



// Function: FUN_1000a5d9 at 1000a5d9

void __cdecl FUN_1000a5d9(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1000a5e7 at 1000a5e7

void __cdecl FUN_1000a5e7(void *param_1)

{
  operator_delete__(param_1);
  return;
}



// Function: __security_check_cookie at 1000a63e

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Library: Visual Studio 2012 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_100155d8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_epilog3 at 1000a654

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



// Function: FUN_1000a668 at 1000a668

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000a668(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_1000a677 at 1000a677

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000a677(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __EH_prolog3 at 1000a686

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100155d8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1000a6b9

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100155d8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 1000a6ef

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100155d8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 1000a725

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100155d8 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_prolog4_GS at 1000a760

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_2 */
/* Library Function - Single Match
    __SEH_prolog4_GS
   
   Library: Visual Studio 2012 Release */

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100155d8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: FUN_1000a7a8 at 1000a7a8

/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_1000a7a8(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x1c) ^ unaff_EBP);
  return;
}



// Function: __alloca_probe_16 at 1000a7c0

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



// Function: __alloca_probe_8 at 1000a7d6

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



// Function: __alloca_probe at 1000a7f0

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



// Function: FUN_1000a81b at 1000a81b

void __cdecl
FUN_1000a81b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_100155d8,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000a84e

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



// Function: __CRT_INIT@12 at 1000a903

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
    if (DAT_100159d4 < 1) {
      return 0;
    }
    DAT_100159d4 = DAT_100159d4 + -1;
    bVar1 = false;
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar2 = StackBase;
      if (DAT_10015a7c != (void *)0x0) {
        pvVar3 = DAT_10015a7c;
        pvVar2 = DAT_10015a7c;
      }
      DAT_10015a7c = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_1000a956;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_1000a956:
    if (DAT_10015a80 == 2) {
      _Memory = (int *)DecodePointer(DAT_10015a8c);
      if (_Memory != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10015a88);
        param_1 = piVar4;
        param_2 = _Memory;
        param_3 = _Memory;
        while (piVar4 = piVar4 + -1, _Memory <= piVar4) {
          if ((*piVar4 != 0) && (pvVar5 = EncodePointer((PVOID)0x0), (PVOID)*piVar4 != pvVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            pvVar5 = EncodePointer((PVOID)0x0);
            *piVar4 = (int)pvVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10015a8c);
            piVar8 = (int *)DecodePointer(DAT_10015a88);
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
        DAT_10015a88 = EncodePointer((PVOID)0x0);
        DAT_10015a8c = DAT_10015a88;
      }
      DAT_10015a80 = 0;
      if (!bVar1) {
        LOCK();
        DAT_10015a7c = (void *)0x0;
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
      if (DAT_10015a7c != (void *)0x0) {
        pvVar3 = DAT_10015a7c;
        pvVar2 = DAT_10015a7c;
      }
      DAT_10015a7c = pvVar2;
      UNLOCK();
      if (pvVar3 == (void *)0x0) goto LAB_1000aa71;
    } while (pvVar3 != StackBase);
    bVar1 = true;
LAB_1000aa71:
    if (DAT_10015a80 == 0) {
      DAT_10015a80 = 1;
      iVar9 = initterm_e(&DAT_1000e21c,&DAT_1000e228);
      if (iVar9 != 0) {
        return 0;
      }
      initterm(&DAT_1000e1d4,&DAT_1000e218);
      DAT_10015a80 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      LOCK();
      DAT_10015a7c = (void *)0x0;
      UNLOCK();
    }
    if ((DAT_10015a84 != (code *)0x0) &&
       (BVar10 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10015a84), BVar10 != 0)) {
      (*DAT_10015a84)(param_1,2,param_3);
    }
    DAT_100159d4 = DAT_100159d4 + 1;
  }
  return 1;
}



// Function: entry at 1000aaf8

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_1,param_2,param_3);
  return;
}



// Function: ___DllMainCRTStartup at 1000ab1b

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000abcc) */
/* WARNING: Removing unreachable block (ram,0x1000ab62) */
/* WARNING: Removing unreachable block (ram,0x1000abfe) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2012 Release */

uint __cdecl ___DllMainCRTStartup(HMODULE param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  _DAT_100155e0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_100159d4 == 0)) {
    uVar1 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (uVar1 = __CRT_INIT_12(&param_1->unused,param_2,param_3), uVar1 != 0)) {
    uVar1 = FUN_100068f9(param_1,(int)param_2);
    if ((param_2 == (int *)0x1) && (uVar1 == 0)) {
      FUN_100068f9(param_1,0);
      __CRT_INIT_12(&param_1->unused,(int *)0x0,param_3);
    }
    if ((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) {
      iVar2 = __CRT_INIT_12(&param_1->unused,param_2,param_3);
      uVar1 = uVar1 & -(uint)(iVar2 != 0);
    }
  }
  FUN_1000ac43();
  return uVar1;
}



// Function: FUN_1000ac43 at 1000ac43

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000ac43(void)

{
  _DAT_100155e0 = 0xffffffff;
  return;
}



// Function: __SEH_prolog4 at 1000ac50

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_100155d8 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000ac95

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



// Function: __FindPESection at 1000ad00

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



// Function: __IsNonwritableInCurrentImage at 1000ad50

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
  
  pcStack_10 = FUN_1000a81b;
  local_14 = ExceptionList;
  local_c = DAT_100155d8 ^ 0x10013aa8;
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



// Function: __ValidateImageBase at 1000ae10

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



// Function: ___security_init_cookie at 1000ae41

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
  if ((DAT_100155d8 == 0xbb40e64e) || ((DAT_100155d8 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_100155d8 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_100155d8 == 0xbb40e64e) {
      DAT_100155d8 = 0xbb40e64f;
    }
    else if ((DAT_100155d8 & 0xffff0000) == 0) {
      DAT_100155d8 = DAT_100155d8 | (DAT_100155d8 | 0x4711) << 0x10;
    }
    DAT_100155dc = ~DAT_100155d8;
  }
  else {
    DAT_100155dc = ~DAT_100155d8;
  }
  return;
}



// Function: FUN_1000aee2 at 1000aee2

void FUN_1000aee2(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = &DAT_10011c9c; puVar1 < &DAT_10011c9c; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// Function: FUN_1000af02 at 1000af02

void FUN_1000af02(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = &DAT_10011ca4; puVar1 < &DAT_10011ca4; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// Function: FUN_1000af2e at 1000af2e

void FUN_1000af2e(void)

{
  __clean_type_info_names_internal(&DAT_100159d8);
  return;
}



// Function: CAtlBaseModule at 1000af55

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::CAtlBaseModule(void)
   
   Library: Visual Studio 2012 Release */

CAtlBaseModule * __thiscall ATL::CAtlBaseModule::CAtlBaseModule(CAtlBaseModule *this)

{
  DWORD DVar1;
  
  _ATL_BASE_MODULE70::_ATL_BASE_MODULE70((_ATL_BASE_MODULE70 *)this);
  *(undefined4 *)this = 0x38;
  *(undefined4 *)(this + 8) = 0x10000000;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined4 *)(this + 0xc) = 0xb00;
  *(undefined **)(this + 0x10) = &DAT_10010fb0;
  DVar1 = FUN_100042e7((LPCRITICAL_SECTION)(this + 0x14));
  if ((int)DVar1 < 0) {
    DAT_100155fc = 1;
  }
  return this;
}



// Function: FUN_1000af93 at 1000af93

undefined4 * __thiscall FUN_1000af93(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: _ATL_BASE_MODULE70 at 1000afa3

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



// Function: ~CAtlBaseModule at 1000afcb

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



// Function: operator[] at 1000afe9

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



// Function: Add at 1000b013

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
      FUN_10003606(0x80004005);
      pcVar2 = (code *)swi(3);
      iVar4 = (*pcVar2)();
      return iVar4;
    }
    if (iVar4 == 0) {
      _Count = 1;
LAB_1000b04a:
      pvVar3 = _recalloc(_Memory,_Count,4);
      if (pvVar3 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar3;
        goto LAB_1000b05f;
      }
    }
    else {
      _Count = *(int *)(this + 4) * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_1000b04a;
    }
    iVar4 = 0;
  }
  else {
LAB_1000b05f:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar4 = 1;
  }
  return iVar4;
}



// Function: AddResourceInstance at 1000b08b

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



// Function: GetHInstanceAt at 1000b0be

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



// Function: InternalSetAtIndex at 1000b107

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



// Function: RemoveAll at 1000b121

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



// Function: RemoveAt at 1000b13e

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



// Function: RemoveResourceInstance at 1000b186

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



// Function: memmove_s at 1000b1e3

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



// Function: CAtlComModule at 1000b202

/* Library Function - Single Match
    public: __thiscall ATL::CAtlComModule::CAtlComModule(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

CAtlComModule * __thiscall ATL::CAtlComModule::CAtlComModule(CAtlComModule *this)

{
  DWORD DVar1;
  
  _ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)this);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0x10000000;
  *(undefined **)(this + 8) = &DAT_10013b90;
  *(undefined **)(this + 0xc) = &DAT_10013b90;
  DVar1 = FUN_100042e7((LPCRITICAL_SECTION)(this + 0x10));
  if ((int)DVar1 < 0) {
    DAT_100155fc = 1;
  }
  else {
    *(undefined4 *)this = 0x28;
  }
  return this;
}



// Function: _ATL_COM_MODULE70 at 1000b241

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

_ATL_COM_MODULE70 * __thiscall ATL::_ATL_COM_MODULE70::_ATL_COM_MODULE70(_ATL_COM_MODULE70 *this)

{
  memset(this + 0x10,0,0x18);
  return this;
}



// Function: Term at 1000b25e

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



// Function: `vector_constructor_iterator' at 1000b2a8

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



// Function: `vector_destructor_iterator' at 1000b2c7

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



// Function: _com_dispatch_method at 1000b2f0

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
    (*(code *)PTR_FUN_100155e4)(lVar1,local_8);
  }
  return lVar1;
}



// Function: _com_dispatch_propget at 1000b330

/* Library Function - Single Match
    long __stdcall _com_dispatch_propget(struct IDispatch *,long,unsigned short,void *)
   
   Library: Visual Studio 2012 Release */

long _com_dispatch_propget(IDispatch *param_1,long param_2,ushort param_3,void *param_4)

{
  long lVar1;
  
  lVar1 = _com_dispatch_method(param_1,param_2,2,param_3,param_4,(ushort *)0x0);
  return lVar1;
}



// Function: _com_dispatch_propput at 1000b350

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
    (*(code *)PTR_FUN_100155e4)(lVar2,local_c);
  }
  return lVar2;
}



// Function: _com_issue_error at 1000b3b0

/* Library Function - Single Match
    void __stdcall _com_issue_error(long)
   
   Library: Visual Studio 2012 Release */

void _com_issue_error(long param_1)

{
  (*(code *)PTR_FUN_100155e4)(param_1,0);
  return;
}



// Function: _com_issue_errorex at 1000b3d0

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
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_1000e5d0,&param_2),
     ppuVar3 = local_8, -1 < HVar1)) {
    HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
    (*param_2->lpVtbl->Release)(param_2);
    ppuVar3 = local_8;
    if (HVar1 == 0) {
      local_8 = &local_8;
      iVar2 = Ordinal_200(0);
      local_8 = (undefined4 **)(~-(uint)(iVar2 != 0) & (uint)local_8);
      (*(code *)PTR_FUN_100155e4)(param_1,local_8);
      return;
    }
  }
  local_8 = ppuVar3;
  (*(code *)PTR_FUN_100155e4)(param_1);
  return;
}



// Function: FUN_1000b450 at 1000b450

void FUN_1000b450(undefined *param_1)

{
  PTR_FUN_100155e4 = param_1;
  return;
}



// Function: _variant_t at 1000b460

/* Library Function - Single Match
    public: __thiscall _variant_t::_variant_t(long,unsigned short)
   
   Library: Visual Studio 2012 Release */

_variant_t * __thiscall _variant_t::_variant_t(_variant_t *this,long param_1,ushort param_2)

{
  code *pcVar1;
  _variant_t *p_Var2;
  
  if (param_2 != 3) {
    if (param_2 == 10) goto LAB_1000b47f;
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
LAB_1000b47f:
  *(undefined2 *)this = 10;
  *(long *)(this + 8) = param_1;
  return this;
}



// Function: ConvertBSTRToString at 1000b4f0

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
  puStack_c = &LAB_1000da70;
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



// Function: Catch_All@1000b5f3 at 1000b5f3

undefined * Catch_All_1000b5f3(void)

{
  return &DAT_1000b5f9;
}



// Function: ConvertStringToBSTR at 1000b610

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
  pcStack_10 = FUN_1000a81b;
  local_14 = ExceptionList;
  local_c = DAT_100155d8 ^ 0x10013ac8;
  uVar1 = DAT_100155d8 ^ (uint)&stack0xfffffffc;
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



// Function: FUN_1000b790 at 1000b790

uint FUN_1000b790(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: _com_error at 1000b7b0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Library: Visual Studio 2012 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001107c;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: _com_error at 1000b7f0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(long,struct IErrorInfo *,bool)
   
   Library: Visual Studio 2012 Release */

_com_error * __thiscall
_com_error::_com_error(_com_error *this,long param_1,IErrorInfo *param_2,bool param_3)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001107c;
  *(long *)(this + 4) = param_1;
  *(IErrorInfo **)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  if ((param_2 != (IErrorInfo *)0x0) && (param_3)) {
    (**(code **)(*(int *)param_2 + 4))(param_2);
  }
  return this;
}



// Function: ~_com_error at 1000b830

/* Library Function - Single Match
    public: virtual __thiscall _com_error::~_com_error(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall _com_error::~_com_error(_com_error *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001107c;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (*(HLOCAL *)(this + 0xc) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(this + 0xc));
  }
  return;
}



// Function: `scalar_deleting_destructor' at 1000b860

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__1001107c;
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



// Function: FUN_1000b8a0 at 1000b8a0

void FUN_1000b8a0(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_1;
  local_c = param_2;
  local_14 = &PTR__scalar_deleting_destructor__1001107c;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_10013b3c);
}



// Function: _com_dispatch_raw_method at 1000b8d0

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



// Function: _com_dispatch_raw_propget at 1000b910

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



// Function: _com_dispatch_raw_propput at 1000b930

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



// Function: _com_invoke_helper at 1000b990

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
  pcStack_10 = FUN_1000a81b;
  local_14 = ExceptionList;
  local_c = DAT_100155d8 ^ 0x10013b70;
  local_8c = DAT_100155d8 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_8c;
  ExceptionList = &local_14;
  local_20 = local_8c;
  puVar15 = &local_8c;
  if (param_1 == (IDispatch *)0x0) goto LAB_1000bd05;
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
    if (local_3c == 0) goto LAB_1000bd05;
    local_38 = 1;
    local_40 = &local_54;
  }
  if (local_3c != 0) {
    local_1c = (undefined1 *)&local_8c;
    local_34 = &local_8c;
    local_8 = 0xfffffffe;
    uStack_9c = 0x1000ba5c;
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
switchD_1000bad5_caseD_f:
            puVar15 = (uint *)local_1c;
            if ((uVar1 & 0x2000) == 0) goto LAB_1000bd05;
          }
switchD_1000bad5_caseD_3:
          piVar12 = piVar11 + 1;
          piVar7 = piVar7 + 1;
          *piVar14 = *piVar7;
          goto LAB_1000bbc0;
        }
        if (uVar4 == 0x4002) goto switchD_1000bad5_caseD_3;
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
          goto switchD_1000bad5_caseD_3;
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
          goto switchD_1000bad5_caseD_f;
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
LAB_1000bbc0:
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
  iVar13 = (**(code **)(*(int *)param_1 + 0x18))(param_1,param_2,&DAT_1000e378,0,_param_3,&local_44)
  ;
  if (iVar13 < 0) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    if (iVar13 == -0x7ffdfff7) {
      _com_handle_excepinfo((tagEXCEPINFO *)&local_78,param_8);
      puVar15 = (uint *)local_1c;
    }
    goto LAB_1000bd05;
  }
  puVar15 = (uint *)local_1c;
  if ((param_4 == 0) || (param_5 == (void *)0x0)) goto LAB_1000bd05;
  if ((param_4 != 0xc) &&
     ((param_4 != (ushort)local_30 &&
      (iVar13 = Ordinal_12(&local_30,&local_30,0,_param_4), iVar13 < 0)))) {
    Ordinal_9(&local_30);
    puVar15 = (uint *)local_1c;
    goto LAB_1000bd05;
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
        goto switchD_1000bdaf_caseD_3;
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
        goto switchD_1000bdaf_caseD_f;
      case 0x10:
      case 0x11:
        *(undefined1 *)param_5 = local_28;
      }
      goto LAB_1000bd05;
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
switchD_1000bdaf_caseD_f:
      if ((param_4 & 0x2000) == 0) {
        Ordinal_9(&local_30);
        puVar15 = (uint *)local_1c;
        goto LAB_1000bd05;
      }
    }
  }
switchD_1000bdaf_caseD_3:
  *(uint *)param_5 = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
LAB_1000bd05:
  local_1c = (undefined1 *)puVar15;
  ExceptionList = local_14;
  lVar3 = __security_check_cookie(local_20 ^ (uint)&stack0xfffffffc);
  return lVar3;
}



// Function: FUN_1000bf40 at 1000bf40

int FUN_1000bf40(ushort param_1)

{
  if (0xfdff < param_1) {
    return -0x7ffb0001;
  }
  return param_1 + 0x80040200;
}



// Function: _com_handle_excepinfo at 1000bf70

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
      (**(code **)(*(int *)param_1 + 0xc))(param_1,&DAT_1000eb7c);
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
      iVar4 = (*(code *)**(undefined4 **)param_1)(param_1,&DAT_1000e540,ppIVar3);
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



// Function: Unwind@1000c0b0 at 1000c0b0

void Unwind_1000c0b0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10005e35(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c0d3 at 1000c0d3

void Unwind_1000c0d3(void)

{
  int unaff_EBP;
  
  FUN_10001861(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000c0f9 at 1000c0f9

void Unwind_1000c0f9(void)

{
  int unaff_EBP;
  
  FUN_10001b16(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c11c at 1000c11c

void Unwind_1000c11c(void)

{
  int unaff_EBP;
  
  FUN_10001b16(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c13f at 1000c13f

void Unwind_1000c13f(void)

{
  int unaff_EBP;
  
  FUN_10001aad(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c162 at 1000c162

void Unwind_1000c162(void)

{
  int unaff_EBP;
  
  FUN_10001a7a((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c188 at 1000c188

void Unwind_1000c188(void)

{
  int unaff_EBP;
  
  FUN_100019f1(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c1ab at 1000c1ab

void Unwind_1000c1ab(void)

{
  int unaff_EBP;
  
  FUN_100019fe(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c1ce at 1000c1ce

void Unwind_1000c1ce(void)

{
  int unaff_EBP;
  
  FUN_10001a0b(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c1f1 at 1000c1f1

void Unwind_1000c1f1(void)

{
  int unaff_EBP;
  
  FUN_10001a0b(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c214 at 1000c214

void Unwind_1000c214(void)

{
  int unaff_EBP;
  
  FUN_10001a18(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c237 at 1000c237

void Unwind_1000c237(void)

{
  int unaff_EBP;
  
  FUN_10001a25(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c25a at 1000c25a

void Unwind_1000c25a(void)

{
  int unaff_EBP;
  
  FUN_10001b04(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c27d at 1000c27d

void Unwind_1000c27d(void)

{
  int unaff_EBP;
  
  FUN_10001a7a((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000c288 at 1000c288

void Unwind_1000c288(void)

{
  int unaff_EBP;
  
  FUN_10001916(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000c2ae at 1000c2ae

void Unwind_1000c2ae(void)

{
  int unaff_EBP;
  
  thunk_FUN_10005e35(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c2b6 at 1000c2b6

void Unwind_1000c2b6(void)

{
  int unaff_EBP;
  
  FUN_100017bc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c2d9 at 1000c2d9

void Unwind_1000c2d9(void)

{
  int unaff_EBP;
  
  FUN_10001a7a((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000c2e4 at 1000c2e4

void Unwind_1000c2e4(void)

{
  int unaff_EBP;
  
  FUN_10001916(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000c2ef at 1000c2ef

void Unwind_1000c2ef(void)

{
  int unaff_EBP;
  
  FUN_10001a5b((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1000c2fa at 1000c2fa

void Unwind_1000c2fa(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000c320 at 1000c320

void Unwind_1000c320(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000590f(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c343 at 1000c343

void Unwind_1000c343(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000590f(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c34b at 1000c34b

void Unwind_1000c34b(void)

{
  int unaff_EBP;
  
  FUN_10001b68((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c371 at 1000c371

void Unwind_1000c371(void)

{
  int unaff_EBP;
  
  FUN_10001aa4(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c394 at 1000c394

void Unwind_1000c394(void)

{
  int unaff_EBP;
  
  thunk_FUN_10005e35(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c3b7 at 1000c3b7

void Unwind_1000c3b7(void)

{
  int unaff_EBP;
  
  FUN_10001861(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000c3c2 at 1000c3c2

void Unwind_1000c3c2(void)

{
  int unaff_EBP;
  
  FUN_10001b16(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c3e5 at 1000c3e5

void Unwind_1000c3e5(void)

{
  int unaff_EBP;
  
  FUN_10001b16(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c408 at 1000c408

void Unwind_1000c408(void)

{
  int unaff_EBP;
  
  FUN_10001b16(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c42b at 1000c42b

void Unwind_1000c42b(void)

{
  int unaff_EBP;
  
  FUN_10001aad(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c44e at 1000c44e

void Unwind_1000c44e(void)

{
  int unaff_EBP;
  
  FUN_10001a7a((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c474 at 1000c474

void Unwind_1000c474(void)

{
  int unaff_EBP;
  
  FUN_100019f1(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c497 at 1000c497

void Unwind_1000c497(void)

{
  int unaff_EBP;
  
  FUN_100019fe(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c4ba at 1000c4ba

void Unwind_1000c4ba(void)

{
  int unaff_EBP;
  
  FUN_10001a0b(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c4dd at 1000c4dd

void Unwind_1000c4dd(void)

{
  int unaff_EBP;
  
  FUN_10001a18(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c500 at 1000c500

void Unwind_1000c500(void)

{
  int unaff_EBP;
  
  FUN_10001a25(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c523 at 1000c523

void Unwind_1000c523(void)

{
  int unaff_EBP;
  
  FUN_10001b04(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c546 at 1000c546

void Unwind_1000c546(void)

{
  int unaff_EBP;
  
  FUN_10001916(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000c551 at 1000c551

void Unwind_1000c551(void)

{
  int unaff_EBP;
  
  FUN_10001a7a((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c577 at 1000c577

void Unwind_1000c577(void)

{
  int unaff_EBP;
  
  FUN_100017bc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c57f at 1000c57f

void Unwind_1000c57f(void)

{
  int unaff_EBP;
  
  thunk_FUN_10005e35(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c5a2 at 1000c5a2

void Unwind_1000c5a2(void)

{
  int unaff_EBP;
  
  FUN_10001916(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000c5ad at 1000c5ad

void Unwind_1000c5ad(void)

{
  int unaff_EBP;
  
  FUN_10001a5b((int *)(*(int *)(unaff_EBP + -0x10) + 0x2c));
  return;
}



// Function: Unwind@1000c5b8 at 1000c5b8

void Unwind_1000c5b8(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1000c5c3 at 1000c5c3

void Unwind_1000c5c3(void)

{
  int unaff_EBP;
  
  FUN_10001a7a((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c5e9 at 1000c5e9

void Unwind_1000c5e9(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000590f(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c60c at 1000c60c

void Unwind_1000c60c(void)

{
  int unaff_EBP;
  
  FUN_10001b68((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c632 at 1000c632

void Unwind_1000c632(void)

{
  int unaff_EBP;
  
  FUN_10001aa4(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c655 at 1000c655

void Unwind_1000c655(void)

{
  int unaff_EBP;
  
  FUN_10001aa4(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c678 at 1000c678

void Unwind_1000c678(void)

{
  int unaff_EBP;
  
  FUN_100017bc(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c680 at 1000c680

void Unwind_1000c680(void)

{
  int unaff_EBP;
  
  thunk_FUN_10005e35(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c6a3 at 1000c6a3

void Unwind_1000c6a3(void)

{
  FUN_100017bc(0x1001564c);
  return;
}



// Function: Unwind@1000c6ad at 1000c6ad

void Unwind_1000c6ad(void)

{
  thunk_FUN_10005e35(0x1001564c);
  return;
}



// Function: Unwind@1000c6d2 at 1000c6d2

void Unwind_1000c6d2(void)

{
  int unaff_EBP;
  
  FUN_100017f4((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c6da at 1000c6da

void Unwind_1000c6da(void)

{
  int unaff_EBP;
  
  FUN_10001804((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000c6fd at 1000c6fd

void Unwind_1000c6fd(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c72a at 1000c72a

void Unwind_1000c72a(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c757 at 1000c757

void Unwind_1000c757(void)

{
  int unaff_EBP;
  
  FUN_10001a37((int *)(unaff_EBP + -0x1118));
  return;
}



// Function: Unwind@1000c762 at 1000c762

void Unwind_1000c762(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x1120));
  return;
}



// Function: Unwind@1000c76d at 1000c76d

void Unwind_1000c76d(void)

{
  int unaff_EBP;
  
  FUN_10001a4f((int *)(unaff_EBP + -0x1118));
  return;
}



// Function: Unwind@1000c7a0 at 1000c7a0

void Unwind_1000c7a0(void)

{
  int unaff_EBP;
  
  FUN_1000187f((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c7c3 at 1000c7c3

void Unwind_1000c7c3(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@1000c7f6 at 1000c7f6

void Unwind_1000c7f6(void)

{
  int unaff_EBP;
  
  FUN_1000187f((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c819 at 1000c819

void Unwind_1000c819(void)

{
  int unaff_EBP;
  
  FUN_100019f1((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@1000c824 at 1000c824

void Unwind_1000c824(void)

{
  int unaff_EBP;
  
  FUN_10001938((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@1000c82f at 1000c82f

void Unwind_1000c82f(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x13c));
  return;
}



// Function: Unwind@1000c83a at 1000c83a

void Unwind_1000c83a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x148));
  return;
}



// Function: Unwind@1000c845 at 1000c845

void Unwind_1000c845(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x138));
  return;
}



// Function: Unwind@1000c850 at 1000c850

void Unwind_1000c850(void)

{
  int unaff_EBP;
  
  FUN_100019f1((int *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@1000c883 at 1000c883

void Unwind_1000c883(void)

{
  int unaff_EBP;
  
  FUN_10001aa4((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000c88e at 1000c88e

void Unwind_1000c88e(void)

{
  int unaff_EBP;
  
  FUN_10001a18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c899 at 1000c899

void Unwind_1000c899(void)

{
  int unaff_EBP;
  
  FUN_100019a7((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c8a4 at 1000c8a4

void Unwind_1000c8a4(void)

{
  int unaff_EBP;
  
  FUN_10001aa4((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c8af at 1000c8af

void Unwind_1000c8af(void)

{
  int unaff_EBP;
  
  FUN_10001a18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c8ba at 1000c8ba

void Unwind_1000c8ba(void)

{
  int unaff_EBP;
  
  FUN_10001a18((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c8ed at 1000c8ed

void Unwind_1000c8ed(void)

{
  int unaff_EBP;
  
  FUN_10001aa4((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c8f5 at 1000c8f5

void Unwind_1000c8f5(void)

{
  int unaff_EBP;
  
  FUN_10001a18((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c8fd at 1000c8fd

void Unwind_1000c8fd(void)

{
  int unaff_EBP;
  
  FUN_100019a7((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c905 at 1000c905

void Unwind_1000c905(void)

{
  int unaff_EBP;
  
  FUN_10001a18((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c928 at 1000c928

void Unwind_1000c928(void)

{
  int unaff_EBP;
  
  FUN_1000a5d9(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c953 at 1000c953

void Unwind_1000c953(void)

{
  int unaff_EBP;
  
  FUN_1000a5d9(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c97e at 1000c97e

void Unwind_1000c97e(void)

{
  int unaff_EBP;
  
  FUN_1000a5d9(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c9c4 at 1000c9c4

void Unwind_1000c9c4(void)

{
  int unaff_EBP;
  
  FUN_1000187f((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c9e7 at 1000c9e7

void Unwind_1000c9e7(void)

{
  int unaff_EBP;
  
  FUN_1000187f((undefined4 *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@1000c9f2 at 1000c9f2

void Unwind_1000c9f2(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x118));
  return;
}



// Function: Unwind@1000c9fd at 1000c9fd

void Unwind_1000c9fd(void)

{
  int unaff_EBP;
  
  FUN_10001a0b((int *)(unaff_EBP + -0x118));
  return;
}



// Function: Unwind@1000ca08 at 1000ca08

void Unwind_1000ca08(void)

{
  int unaff_EBP;
  
  FUN_10001982((int *)(unaff_EBP + -0x118));
  return;
}



// Function: Unwind@1000ca13 at 1000ca13

void Unwind_1000ca13(void)

{
  int unaff_EBP;
  
  FUN_10001a0b((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@1000ca1e at 1000ca1e

void Unwind_1000ca1e(void)

{
  int unaff_EBP;
  
  FUN_10001982((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@1000ca29 at 1000ca29

void Unwind_1000ca29(void)

{
  int unaff_EBP;
  
  FUN_100019fe((int *)(unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@1000ca34 at 1000ca34

void Unwind_1000ca34(void)

{
  int unaff_EBP;
  
  FUN_1000195d((int *)(unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@1000ca3f at 1000ca3f

void Unwind_1000ca3f(void)

{
  int unaff_EBP;
  
  FUN_100019fe((int *)(unaff_EBP + -0x11c));
  return;
}



// Function: Unwind@1000ca4a at 1000ca4a

void Unwind_1000ca4a(void)

{
  int unaff_EBP;
  
  FUN_10001a0b((int *)(unaff_EBP + -0x124));
  return;
}



// Function: Unwind@1000ca55 at 1000ca55

void Unwind_1000ca55(void)

{
  int unaff_EBP;
  
  FUN_10001a0b((int *)(unaff_EBP + -0x118));
  return;
}



// Function: Unwind@1000ca88 at 1000ca88

void Unwind_1000ca88(void)

{
  FUN_1000110a();
  return;
}



// Function: Unwind@1000ca9f at 1000ca9f

void Unwind_1000ca9f(void)

{
  FUN_1000110b();
  return;
}



// Function: Unwind@1000cad2 at 1000cad2

void Unwind_1000cad2(void)

{
  int unaff_EBP;
  
  FUN_10001a25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cada at 1000cada

void Unwind_1000cada(void)

{
  int unaff_EBP;
  
  FUN_100019cc((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cae2 at 1000cae2

void Unwind_1000cae2(void)

{
  int unaff_EBP;
  
  FUN_10001a25((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000caea at 1000caea

void Unwind_1000caea(void)

{
  int unaff_EBP;
  
  FUN_100019cc((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000caf2 at 1000caf2

void Unwind_1000caf2(void)

{
  int unaff_EBP;
  
  FUN_10001a25((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000cafa at 1000cafa

void Unwind_1000cafa(void)

{
  int unaff_EBP;
  
  FUN_10001a25((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cb1d at 1000cb1d

void Unwind_1000cb1d(void)

{
  int unaff_EBP;
  
  FUN_1000a5e7(*(void **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000cb2d at 1000cb2d

void Unwind_1000cb2d(void)

{
  int unaff_EBP;
  
  FUN_10001aa4((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000cb50 at 1000cb50

void Unwind_1000cb50(void)

{
  int unaff_EBP;
  
  FUN_10001b93(unaff_EBP + -0x48);
  return;
}



// Function: Unwind@1000cb7d at 1000cb7d

void Unwind_1000cb7d(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x120));
  return;
}



// Function: Unwind@1000cbb0 at 1000cbb0

void Unwind_1000cbb0(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000cbbb at 1000cbbb

void Unwind_1000cbbb(void)

{
  int unaff_EBP;
  
  FUN_10001a43((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000cbee at 1000cbee

void Unwind_1000cbee(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x1128));
  return;
}



// Function: Unwind@1000cbf9 at 1000cbf9

void Unwind_1000cbf9(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x1134));
  return;
}



// Function: Unwind@1000cc04 at 1000cc04

void Unwind_1000cc04(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x1150));
  return;
}



// Function: Unwind@1000cc0f at 1000cc0f

void Unwind_1000cc0f(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x115c));
  return;
}



// Function: Unwind@1000cc1a at 1000cc1a

void Unwind_1000cc1a(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003860((int *)(unaff_EBP + -0x1144));
  return;
}



// Function: Unwind@1000cc4d at 1000cc4d

void Unwind_1000cc4d(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cc7a at 1000cc7a

void Unwind_1000cc7a(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cca7 at 1000cca7

void Unwind_1000cca7(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000ccd4 at 1000ccd4

void Unwind_1000ccd4(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000cd01 at 1000cd01

void Unwind_1000cd01(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000590f(*(int **)(unaff_EBP + -0x944));
  return;
}



// Function: Unwind@1000cd0c at 1000cd0c

void Unwind_1000cd0c(void)

{
  int unaff_EBP;
  
  FUN_10001b68((int *)(unaff_EBP + -0x954));
  return;
}



// Function: Unwind@1000cd17 at 1000cd17

void Unwind_1000cd17(void)

{
  int unaff_EBP;
  
  FUN_10001ba2((undefined4 *)(unaff_EBP + -0x958));
  return;
}



// Function: Unwind@1000cd22 at 1000cd22

void Unwind_1000cd22(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x940));
  return;
}



// Function: Unwind@1000cd55 at 1000cd55

void Unwind_1000cd55(void)

{
  int unaff_EBP;
  
  thunk_FUN_1000590f(*(int **)(unaff_EBP + -0x944));
  return;
}



// Function: Unwind@1000cd60 at 1000cd60

void Unwind_1000cd60(void)

{
  int unaff_EBP;
  
  FUN_10001b68((int *)(unaff_EBP + -0x954));
  return;
}



// Function: Unwind@1000cd6b at 1000cd6b

void Unwind_1000cd6b(void)

{
  int unaff_EBP;
  
  FUN_10001ba2((undefined4 *)(unaff_EBP + -0x958));
  return;
}



// Function: Unwind@1000cd76 at 1000cd76

void Unwind_1000cd76(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x940));
  return;
}



// Function: Unwind@1000cda9 at 1000cda9

void Unwind_1000cda9(void)

{
  DAT_10015648 = DAT_10015648 & 0xfffffffe;
  return;
}



// Function: Unwind@1000cdd2 at 1000cdd2

void Unwind_1000cdd2(void)

{
  int unaff_EBP;
  
  FUN_10006fec(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cdf5 at 1000cdf5

void Unwind_1000cdf5(void)

{
  int unaff_EBP;
  
  FUN_10001a68(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ce18 at 1000ce18

void Unwind_1000ce18(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000ce3b at 1000ce3b

void Unwind_1000ce3b(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000ce5e at 1000ce5e

void Unwind_1000ce5e(void)

{
  int unaff_EBP;
  
  FUN_10006fd2(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ce81 at 1000ce81

void Unwind_1000ce81(void)

{
  int unaff_EBP;
  
  FUN_10006fdf(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cea4 at 1000cea4

void Unwind_1000cea4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cec9 at 1000cec9

void Unwind_1000cec9(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ceee at 1000ceee

void Unwind_1000ceee(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf13 at 1000cf13

void Unwind_1000cf13(void)

{
  int unaff_EBP;
  
  FUN_10006fd2(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf36 at 1000cf36

void Unwind_1000cf36(void)

{
  int unaff_EBP;
  
  FUN_10006fdf(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf59 at 1000cf59

void Unwind_1000cf59(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf7e at 1000cf7e

void Unwind_1000cf7e(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cfa3 at 1000cfa3

void Unwind_1000cfa3(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10007018(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000cfd7 at 1000cfd7

void Unwind_1000cfd7(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cffc at 1000cffc

void Unwind_1000cffc(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1000d004 at 1000d004

void Unwind_1000d004(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1000d00c at 1000d00c

void Unwind_1000d00c(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1000d014 at 1000d014

void Unwind_1000d014(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1000d01c at 1000d01c

void Unwind_1000d01c(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000d024 at 1000d024

void Unwind_1000d024(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000d02c at 1000d02c

void Unwind_1000d02c(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000d034 at 1000d034

void Unwind_1000d034(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000d03c at 1000d03c

void Unwind_1000d03c(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000d044 at 1000d044

void Unwind_1000d044(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000d04c at 1000d04c

void Unwind_1000d04c(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1000d054 at 1000d054

void Unwind_1000d054(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1000d081 at 1000d081

void Unwind_1000d081(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d0ae at 1000d0ae

void Unwind_1000d0ae(void)

{
  int unaff_EBP;
  
  FUN_100017da((int *)(unaff_EBP + -0x420));
  return;
}



// Function: Unwind@1000d0b9 at 1000d0b9

void Unwind_1000d0b9(void)

{
  int unaff_EBP;
  
  FUN_10006fd2((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@1000d0c4 at 1000d0c4

void Unwind_1000d0c4(void)

{
  int unaff_EBP;
  
  FUN_10006f88((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@1000d0cf at 1000d0cf

void Unwind_1000d0cf(void)

{
  int unaff_EBP;
  
  FUN_10006fdf((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000d0da at 1000d0da

void Unwind_1000d0da(void)

{
  int unaff_EBP;
  
  FUN_10006fad((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000d0e5 at 1000d0e5

void Unwind_1000d0e5(void)

{
  int unaff_EBP;
  
  FUN_10006fdf((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000d0f0 at 1000d0f0

void Unwind_1000d0f0(void)

{
  int unaff_EBP;
  
  FUN_10006fd2((int *)(unaff_EBP + -0x414));
  return;
}



// Function: Unwind@1000d123 at 1000d123

void Unwind_1000d123(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10007018(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d157 at 1000d157

void Unwind_1000d157(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d15f at 1000d15f

void Unwind_1000d15f(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d167 at 1000d167

void Unwind_1000d167(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d16f at 1000d16f

void Unwind_1000d16f(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d177 at 1000d177

void Unwind_1000d177(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d17f at 1000d17f

void Unwind_1000d17f(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d1a2 at 1000d1a2

void Unwind_1000d1a2(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d1aa at 1000d1aa

void Unwind_1000d1aa(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d1b2 at 1000d1b2

void Unwind_1000d1b2(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d1ba at 1000d1ba

void Unwind_1000d1ba(void)

{
  int unaff_EBP;
  
  FUN_10006ff9((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d1c2 at 1000d1c2

void Unwind_1000d1c2(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d1ca at 1000d1ca

void Unwind_1000d1ca(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d1d2 at 1000d1d2

void Unwind_1000d1d2(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d1da at 1000d1da

void Unwind_1000d1da(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d1e2 at 1000d1e2

void Unwind_1000d1e2(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d205 at 1000d205

void Unwind_1000d205(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10006fec(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d239 at 1000d239

void Unwind_1000d239(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d26d at 1000d26d

void Unwind_1000d26d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d2a1 at 1000d2a1

void Unwind_1000d2a1(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d2d5 at 1000d2d5

void Unwind_1000d2d5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d309 at 1000d309

void Unwind_1000d309(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d33d at 1000d33d

void Unwind_1000d33d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d371 at 1000d371

void Unwind_1000d371(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10007018(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d3a5 at 1000d3a5

void Unwind_1000d3a5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10007018(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d3d9 at 1000d3d9

void Unwind_1000d3d9(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d3e1 at 1000d3e1

void Unwind_1000d3e1(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d404 at 1000d404

void Unwind_1000d404(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d40c at 1000d40c

void Unwind_1000d40c(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d42f at 1000d42f

void Unwind_1000d42f(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d452 at 1000d452

void Unwind_1000d452(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d475 at 1000d475

void Unwind_1000d475(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d47d at 1000d47d

void Unwind_1000d47d(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d485 at 1000d485

void Unwind_1000d485(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000d48d at 1000d48d

void Unwind_1000d48d(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000d495 at 1000d495

void Unwind_1000d495(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1000d49d at 1000d49d

void Unwind_1000d49d(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000d4a5 at 1000d4a5

void Unwind_1000d4a5(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d4ad at 1000d4ad

void Unwind_1000d4ad(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000d4b5 at 1000d4b5

void Unwind_1000d4b5(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000d4bd at 1000d4bd

void Unwind_1000d4bd(void)

{
  int unaff_EBP;
  
  FUN_10007006((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000d4c5 at 1000d4c5

void Unwind_1000d4c5(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d4cd at 1000d4cd

void Unwind_1000d4cd(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1000d4d5 at 1000d4d5

void Unwind_1000d4d5(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000d502 at 1000d502

void Unwind_1000d502(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d525 at 1000d525

void Unwind_1000d525(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d548 at 1000d548

void Unwind_1000d548(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d57c at 1000d57c

void Unwind_1000d57c(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d584 at 1000d584

void Unwind_1000d584(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10006fec(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d5b8 at 1000d5b8

void Unwind_1000d5b8(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d5c0 at 1000d5c0

void Unwind_1000d5c0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10007006(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000d5f4 at 1000d5f4

void Unwind_1000d5f4(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d5fc at 1000d5fc

void Unwind_1000d5fc(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d61f at 1000d61f

void Unwind_1000d61f(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d627 at 1000d627

void Unwind_1000d627(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d64a at 1000d64a

void Unwind_1000d64a(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d652 at 1000d652

void Unwind_1000d652(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d675 at 1000d675

void Unwind_1000d675(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d67d at 1000d67d

void Unwind_1000d67d(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d6a0 at 1000d6a0

void Unwind_1000d6a0(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d6a8 at 1000d6a8

void Unwind_1000d6a8(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d6cb at 1000d6cb

void Unwind_1000d6cb(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000d6d3 at 1000d6d3

void Unwind_1000d6d3(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d6db at 1000d6db

void Unwind_1000d6db(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d6e3 at 1000d6e3

void Unwind_1000d6e3(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000d6eb at 1000d6eb

void Unwind_1000d6eb(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000d6f3 at 1000d6f3

void Unwind_1000d6f3(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000d716 at 1000d716

void Unwind_1000d716(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d71e at 1000d71e

void Unwind_1000d71e(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d741 at 1000d741

void Unwind_1000d741(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d749 at 1000d749

void Unwind_1000d749(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d76c at 1000d76c

void Unwind_1000d76c(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000d774 at 1000d774

void Unwind_1000d774(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000d7a1 at 1000d7a1

void Unwind_1000d7a1(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d7a9 at 1000d7a9

void Unwind_1000d7a9(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d7b1 at 1000d7b1

void Unwind_1000d7b1(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d7d4 at 1000d7d4

void Unwind_1000d7d4(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d7f7 at 1000d7f7

void Unwind_1000d7f7(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000d81a at 1000d81a

void Unwind_1000d81a(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d822 at 1000d822

void Unwind_1000d822(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000d82a at 1000d82a

void Unwind_1000d82a(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000d857 at 1000d857

void Unwind_1000d857(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d85f at 1000d85f

void Unwind_1000d85f(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000d867 at 1000d867

void Unwind_1000d867(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000d894 at 1000d894

void Unwind_1000d894(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d89c at 1000d89c

void Unwind_1000d89c(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d8bf at 1000d8bf

void Unwind_1000d8bf(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d8c7 at 1000d8c7

void Unwind_1000d8c7(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000d8cf at 1000d8cf

void Unwind_1000d8cf(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000d8fc at 1000d8fc

void Unwind_1000d8fc(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000d904 at 1000d904

void Unwind_1000d904(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d927 at 1000d927

void Unwind_1000d927(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000d92f at 1000d92f

void Unwind_1000d92f(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000d937 at 1000d937

void Unwind_1000d937(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000d93f at 1000d93f

void Unwind_1000d93f(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d947 at 1000d947

void Unwind_1000d947(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000d94f at 1000d94f

void Unwind_1000d94f(void)

{
  int unaff_EBP;
  
  FUN_10006fec((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d957 at 1000d957

void Unwind_1000d957(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d95f at 1000d95f

void Unwind_1000d95f(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1000d967 at 1000d967

void Unwind_1000d967(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d96f at 1000d96f

void Unwind_1000d96f(void)

{
  int unaff_EBP;
  
  FUN_10001a68((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d99c at 1000d99c

void Unwind_1000d99c(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1000d9a4 at 1000d9a4

void Unwind_1000d9a4(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000d9ac at 1000d9ac

void Unwind_1000d9ac(void)

{
  int unaff_EBP;
  
  FUN_10007018(*(undefined4 **)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1000d9d9 at 1000d9d9

void Unwind_1000d9d9(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000d9e1 at 1000d9e1

void Unwind_1000d9e1(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10006ff9(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1000da15 at 1000da15

void Unwind_1000da15(void)

{
  int unaff_EBP;
  
  FUN_10007018((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000da1d at 1000da1d

void Unwind_1000da1d(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10001a68(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: FUN_1000dc30 at 1000dc30

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000dc30(void)

{
  _DAT_1001564c = ATL::CComModule::vftable;
  FUN_10005e35(0x1001564c);
  return;
}



// Function: FUN_1000dc5a at 1000dc5a

void FUN_1000dc5a(void)

{
  if (DAT_10015694 != (int *)0x0) {
    FUN_10008b2c(DAT_10015694);
    DAT_10015694 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dc71 at 1000dc71

void FUN_1000dc71(void)

{
  if (DAT_1001567c != (int *)0x0) {
    FUN_10008b2c(DAT_1001567c);
    DAT_1001567c = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dc88 at 1000dc88

void FUN_1000dc88(void)

{
  if (DAT_1001568c != (int *)0x0) {
    FUN_10008b2c(DAT_1001568c);
    DAT_1001568c = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dc9f at 1000dc9f

void FUN_1000dc9f(void)

{
  if (DAT_10015688 != (int *)0x0) {
    FUN_10008b2c(DAT_10015688);
    DAT_10015688 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dcb6 at 1000dcb6

void FUN_1000dcb6(void)

{
  if (DAT_100156a4 != (int *)0x0) {
    FUN_10008b2c(DAT_100156a4);
    DAT_100156a4 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dccd at 1000dccd

void FUN_1000dccd(void)

{
  if (DAT_10015690 != (int *)0x0) {
    FUN_10008b2c(DAT_10015690);
    DAT_10015690 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dce4 at 1000dce4

void FUN_1000dce4(void)

{
  if (DAT_100156a8 != (int *)0x0) {
    FUN_10008b2c(DAT_100156a8);
    DAT_100156a8 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dcfb at 1000dcfb

void FUN_1000dcfb(void)

{
  if (DAT_10015684 != (int *)0x0) {
    FUN_10008b2c(DAT_10015684);
    DAT_10015684 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dd12 at 1000dd12

void FUN_1000dd12(void)

{
  if (DAT_100156a0 != (int *)0x0) {
    FUN_10008b2c(DAT_100156a0);
    DAT_100156a0 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dd29 at 1000dd29

void FUN_1000dd29(void)

{
  if (DAT_10015680 != (int *)0x0) {
    FUN_10008b2c(DAT_10015680);
    DAT_10015680 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dd40 at 1000dd40

void FUN_1000dd40(void)

{
  if (DAT_10015698 != (int *)0x0) {
    FUN_10008b2c(DAT_10015698);
    DAT_10015698 = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dd57 at 1000dd57

void FUN_1000dd57(void)

{
  if (DAT_1001569c != (int *)0x0) {
    FUN_10008b2c(DAT_1001569c);
    DAT_1001569c = (int *)0x0;
  }
  return;
}



// Function: FUN_1000dd6e at 1000dd6e

void FUN_1000dd6e(void)

{
  ATL::CAtlBaseModule::~CAtlBaseModule((CAtlBaseModule *)&DAT_100159e0);
  return;
}



// Function: FUN_1000dd78 at 1000dd78

void FUN_1000dd78(void)

{
  ATL::CAtlComModule::Term((CAtlComModule *)&DAT_10015a18);
  return;
}



// Function: FUN_1000dd90 at 1000dd90

void FUN_1000dd90(void)

{
  Ordinal_9(&DAT_100155e8);
  return;
}



