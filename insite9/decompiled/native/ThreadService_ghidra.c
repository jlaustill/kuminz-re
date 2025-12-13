/*
 * Decompiled from: ThreadService.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_1000102a at 1000102a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_1000102a(void *this,byte param_1)

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
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,(_func_void_void_ptr *)&LAB_10001009);
    if ((param_1 & 1) != 0) {
      operator_delete__(piVar1);
    }
  }
  return piVar1;
}



// Function: FUN_10001087 at 10001087

void __thiscall FUN_10001087(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined2 *)((int)this + 0x18) = 0x100;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x28) = param_1;
  *(undefined4 *)((int)this + 0x24) = 0;
  return;
}



// Function: FUN_100010b9 at 100010b9

void __fastcall FUN_100010b9(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x28),0xffffffff);
  return;
}



// Function: FUN_100010c5 at 100010c5

void __fastcall FUN_100010c5(int param_1)

{
  ReleaseMutex(*(HANDLE *)(param_1 + 0x28));
  return;
}



// Function: FUN_100010cf at 100010cf

void __thiscall FUN_100010cf(void *this,undefined4 *param_1)

{
  FUN_100010b9((int)this);
  *(undefined4 *)((int)this + 0x24) = 0;
  if (param_1 != (undefined4 *)0x0) {
    if ((HANDLE)param_1[3] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[3]);
      param_1[3] = 0;
    }
    if ((HANDLE)*param_1 != (HANDLE)0x0) {
      TerminateThread((HANDLE)*param_1,0);
      CloseHandle((HANDLE)*param_1);
      *param_1 = 0;
    }
  }
  FUN_100010c5((int)this);
  return;
}



// Function: FUN_10001122 at 10001122

void __thiscall FUN_10001122(void *this,undefined4 *param_1)

{
  FUN_100010b9((int)this);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)((int)this + 0x18);
  *(undefined1 *)((int)param_1 + 5) = *(undefined1 *)((int)this + 0x19);
  param_1[2] = *(undefined4 *)((int)this + 0x1c);
  *param_1 = *(undefined4 *)((int)this + 0x14);
  param_1[3] = *(undefined4 *)((int)this + 0x20);
  FUN_100010c5((int)this);
  return;
}



// Function: FUN_10001159 at 10001159

bool __fastcall FUN_10001159(int *param_1)

{
  return *param_1 != 0;
}



// Function: FUN_10001161 at 10001161

undefined1 __thiscall FUN_10001161(void *this,int *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  FUN_100010b9((int)this);
  bVar2 = FUN_10001159((int *)this);
  if (bVar2) {
    piVar1 = *(int **)((int)this + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)((int)this + 8) = 0;
    }
    *(int **)((int)this + 8) = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    uVar3 = 1;
  }
  FUN_100010c5((int)this);
  return uVar3;
}



// Function: FUN_100011ab at 100011ab

undefined4 __fastcall FUN_100011ab(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_100011af at 100011af

undefined1 __fastcall FUN_100011af(int param_1)

{
  BOOL BVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  FUN_100010b9(param_1);
  if (*(HANDLE *)(param_1 + 0xc) != (HANDLE)0x0) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 2;
    BVar1 = ResetEvent(*(HANDLE *)(param_1 + 0xc));
    if (BVar1 != 0) {
      uVar2 = 1;
    }
  }
  FUN_100010c5(param_1);
  return uVar2;
}



// Function: FUN_100011de at 100011de

undefined1 __fastcall FUN_100011de(int param_1)

{
  BOOL BVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  FUN_100010b9(param_1);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffd;
  if (*(HANDLE *)(param_1 + 0xc) != (HANDLE)0x0) {
    BVar1 = SetEvent(*(HANDLE *)(param_1 + 0xc));
    if (BVar1 != 0) {
      uVar2 = 1;
    }
  }
  FUN_100010c5(param_1);
  return uVar2;
}



// Function: FUN_1000120d at 1000120d

bool __thiscall FUN_1000120d(void *this,int param_1)

{
  FUN_100010b9((int)this);
  if (param_1 != 0) {
    *(int *)((int)this + 0x24) = param_1;
  }
  FUN_100010c5((int)this);
  return param_1 != 0;
}



// Function: FUN_10001236 at 10001236

undefined1 __fastcall FUN_10001236(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  BOOL BVar5;
  undefined1 uVar6;
  int *local_8;
  
  uVar6 = 0;
  local_8 = param_1;
  FUN_100010b9((int)param_1);
  bVar3 = FUN_10001159(param_1);
  if (((bVar3) && (param_1[9] != 0)) && (*(char *)((int)param_1 + 0x19) != '\0')) {
    *(undefined1 *)(param_1 + 6) = 0;
    param_1[7] = 0;
    puVar1 = (undefined4 *)param_1[2];
    if (puVar1 != (undefined4 *)0x0) {
      local_8 = (int *)0x0;
      iVar4 = (**(code **)*puVar1)(puVar1,&DAT_1000e3c8,&local_8);
      if (iVar4 == 0) {
        (**(code **)(*local_8 + 0x24))(local_8);
        (**(code **)(*local_8 + 8))(local_8);
      }
    }
    piVar2 = (int *)param_1[2];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      param_1[2] = 0;
    }
    BVar5 = SetEvent((HANDLE)param_1[3]);
    if (BVar5 != 0) {
      uVar6 = 1;
    }
  }
  FUN_100010c5((int)param_1);
  return uVar6;
}



// Function: FUN_100012ba at 100012ba

undefined4 __fastcall FUN_100012ba(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: Catch@10001344 at 10001344

undefined1 * Catch_10001344(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_1000134e;
}



// Function: FUN_100013fa at 100013fa

void __fastcall FUN_100013fa(int *param_1)

{
  if (*param_1 != 0) {
    FUN_100010cf(param_1,param_1);
  }
  return;
}



// Function: FUN_10001406 at 10001406

bool __thiscall FUN_10001406(void *this,int *param_1)

{
  bool bVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  undefined4 local_14;
  bool local_5;
  
  local_5 = false;
  FUN_100010b9((int)this);
  bVar1 = FUN_10001159((int *)this);
  if (!bVar1) {
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)this + 0xc) = pvVar2;
    DVar3 = GetLastError();
    if ((*(int *)((int)this + 0xc) != 0) && (DVar3 != 0xb7)) {
      *(int *)((int)this + 0x14) = *param_1;
      *(int *)((int)this + 0x18) = param_1[1];
      *(int *)((int)this + 0x1c) = param_1[2];
      *(int *)((int)this + 0x20) = param_1[3];
      *(uint *)((int)this + 0x10) = *(uint *)((int)this + 0x10) & 0xfffffffe | 2;
      *(undefined4 *)((int)this + 8) = 0;
      pvVar2 = (HANDLE)_beginthreadex((void *)0x0,*(uint *)((int)this + 0x20),
                                      (_StartAddress *)&LAB_100012be,this,0,(uint *)((int)this + 4))
      ;
      *(HANDLE *)this = pvVar2;
      if (pvVar2 == (HANDLE)0x0) {
        CloseHandle(*(HANDLE *)((int)this + 0xc));
        *(uint *)((int)this + 4) = 0;
        *(undefined4 *)((int)this + 0xc) = 0;
        *(undefined4 *)((int)this + 0x10) = 0;
        local_14 = CONCAT22(local_14._2_2_,0x100);
        *(undefined4 *)((int)this + 0x14) = 0;
        *(undefined4 *)((int)this + 0x18) = local_14;
        *(undefined4 *)((int)this + 0x1c) = 0xffffffff;
        *(undefined4 *)((int)this + 0x20) = 0;
      }
      else {
        SetThreadPriority(pvVar2,*(int *)((int)this + 0x14));
        *(uint *)((int)this + 0x10) = *(uint *)((int)this + 0x10) | 1;
      }
      local_5 = pvVar2 != (HANDLE)0x0;
    }
  }
  FUN_100010c5((int)this);
  return local_5;
}



// Function: FUN_100014d8 at 100014d8

undefined1 __thiscall FUN_100014d8(void *this,uint param_1)

{
  bool bVar1;
  int extraout_ECX;
  undefined1 uVar2;
  
  uVar2 = 0;
  FUN_100010b9((int)this);
  bVar1 = FUN_10001159((int *)this);
  if ((bVar1) && ((param_1 & 0xfffffffc) == 0)) {
    *(uint *)((int)this + 0x10) = param_1;
    uVar2 = 1;
  }
  FUN_100010c5(extraout_ECX);
  return uVar2;
}



// Function: FUN_1000150d at 1000150d

int __fastcall FUN_1000150d(int *param_1)

{
  bool bVar1;
  int extraout_ECX;
  int iVar2;
  
  iVar2 = 0;
  FUN_100010b9((int)param_1);
  bVar1 = FUN_10001159(param_1);
  if (bVar1) {
    iVar2 = param_1[4];
  }
  FUN_100010c5(extraout_ECX);
  return iVar2;
}



// Function: FUN_10001530 at 10001530

undefined1 __thiscall FUN_10001530(void *this,uint param_1,int *param_2)

{
  bool bVar1;
  undefined1 local_5;
  
  local_5 = 1;
  FUN_100010b9((int)this);
  bVar1 = FUN_10001159((int *)this);
  if ((bVar1) && ((param_1 & 0xfffffff0) == 0)) {
    if ((param_1 & 1) != 0) {
      *(int *)((int)this + 0x14) = *param_2;
                    /* WARNING: Load size is inaccurate */
      SetThreadPriority(*this,*param_2);
    }
    if ((param_1 & 2) != 0) {
      *(char *)((int)this + 0x18) = (char)param_2[1];
    }
    if ((param_1 & 4) != 0) {
      *(undefined1 *)((int)this + 0x19) = *(undefined1 *)((int)param_2 + 5);
    }
    if ((param_1 & 8) != 0) {
      *(int *)((int)this + 0x1c) = param_2[2];
    }
  }
  else {
    local_5 = 0;
  }
  FUN_100010c5((int)this);
  return local_5;
}



// Function: FUN_100015cc at 100015cc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

exception * __thiscall FUN_100015cc(void *this,byte param_1)

{
  *(undefined ***)this = std::bad_alloc::vftable;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_10001604 at 10001604

void FUN_10001604(void)

{
  return;
}



// Function: FUN_10001605 at 10001605

void __thiscall FUN_10001605(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = param_1;
  return;
}



// Function: FUN_1000161e at 1000161e

void __fastcall FUN_1000161e(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),0xffffffff);
  return;
}



// Function: FUN_1000162a at 1000162a

void __fastcall FUN_1000162a(int param_1)

{
  ReleaseMutex(*(HANDLE *)(param_1 + 0xc));
  return;
}



// Function: FUN_10001634 at 10001634

uint __thiscall FUN_10001634(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  uint in_EAX;
  uint uVar2;
  
  uVar2 = in_EAX & 0xffffff00;
  if (param_1 != (undefined4 *)0x0) {
    *(undefined4 *)this = *param_1;
    *(undefined4 *)((int)this + 4) = param_1[2];
    uVar1 = param_1[1];
    *(undefined4 *)((int)this + 8) = uVar1;
    uVar2 = CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return uVar2;
}



// Function: FUN_10001656 at 10001656

uint __thiscall FUN_10001656(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  uint in_EAX;
  uint uVar2;
  
  uVar2 = in_EAX & 0xffffff00;
  if (param_1 != (undefined4 *)0x0) {
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
    param_1[1] = *(undefined4 *)((int)this + 8);
    uVar1 = *(undefined4 *)((int)this + 4);
    param_1[2] = uVar1;
    uVar2 = CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return uVar2;
}



// Function: FUN_10001678 at 10001678

void __fastcall FUN_10001678(int *param_1)

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



// Function: FUN_100016b3 at 100016b3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100016b3(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100016bf;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10010150);
}



// Function: FUN_10001744 at 10001744

void __fastcall FUN_10001744(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x15) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x15) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x15) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x15) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x15) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: FUN_1000178a at 1000178a

void __thiscall FUN_1000178a(void *this,int *param_1)

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



// Function: FUN_100017d1 at 100017d1

undefined4 * __thiscall FUN_100017d1(void *this,uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if ((uint)puVar2[3] < *param_1) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  return puVar2;
}



// Function: FUN_100017fd at 100017fd

void __fastcall FUN_100017fd(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_100016b3((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 5) = 0;
  return;
}



// Function: FUN_10001824 at 10001824

void __thiscall FUN_10001824(void *this,int param_1)

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



// Function: FUN_10001869 at 10001869

int __fastcall FUN_10001869(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_100016b3((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x15) = 1;
  return param_1;
}



// Function: FUN_100018a0 at 100018a0

void __thiscall
FUN_100018a0(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x1ffffffd < uVar3) {
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
    if (*(char *)(iVar4 + 0x14) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x14) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x14) == '\0') {
LAB_10001960:
        *(undefined1 *)(piVar1 + 5) = 1;
        *(undefined1 *)(iVar4 + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10001824(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
        FUN_1000178a(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x14) == '\0') goto LAB_10001960;
      if (piVar5 == (int *)*piVar1) {
        FUN_1000178a(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x14) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x14) = 0;
      FUN_10001824(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_100019c9 at 100019c9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_100019c9(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
  }
  return;
}



// Function: FUN_100019fc at 100019fc

void __thiscall FUN_100019fc(void *this,undefined4 *param_1,int *param_2)

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
  FUN_10001678((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x15) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x15) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_10001a46;
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
LAB_10001a46:
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
LAB_10001c23:
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_10001bd7:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[5] != '\x01'))
  goto LAB_10001c1f;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_10001824(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(*piVar5 + 0x14) != '\x01') || (*(char *)(piVar5[2] + 0x14) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x14) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x14) = 1;
          *(undefined1 *)(piVar5 + 5) = 0;
          FUN_1000178a(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 5) = (char)piVar6[5];
        *(undefined1 *)(piVar6 + 5) = 1;
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        FUN_10001824(this,(int)piVar6);
        goto LAB_10001c1f;
      }
LAB_10001bce:
      *(undefined1 *)(piVar5 + 5) = 0;
    }
  }
  else {
    if ((char)piVar5[5] == '\0') {
      *(undefined1 *)(piVar5 + 5) = 1;
      *(undefined1 *)(piVar6 + 5) = 0;
      FUN_1000178a(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x15) == '\0') {
      if ((*(char *)(piVar5[2] + 0x14) == '\x01') && (*(char *)(*piVar5 + 0x14) == '\x01'))
      goto LAB_10001bce;
      if (*(char *)(*piVar5 + 0x14) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x14) = 1;
        *(undefined1 *)(piVar5 + 5) = 0;
        FUN_10001824(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 5) = (char)piVar6[5];
      *(undefined1 *)(piVar6 + 5) = 1;
      *(undefined1 *)(*piVar5 + 0x14) = 1;
      FUN_1000178a(this,piVar6);
LAB_10001c1f:
      *(undefined1 *)(piVar7 + 5) = 1;
      goto LAB_10001c23;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_10001bd7;
}



// Function: FUN_10001c47 at 10001c47

void FUN_10001c47(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x15);
  while (cVar1 == '\0') {
    FUN_10001c47((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  return;
}



// Function: FUN_10001c7c at 10001c7c

void __thiscall FUN_10001c7c(void *this,undefined4 *param_1,int *param_2,char param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char local_8;
  
  puVar2 = *(undefined4 **)((int)this + 4);
  local_8 = '\x01';
  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar1;
      if (param_3 == '\0') {
        local_8 = (uint)param_2[3] < (uint)puVar2[3];
      }
      else {
        local_8 = '\x01' - ((uint)puVar2[3] < (uint)param_2[3]);
      }
      if (local_8 == '\0') {
        puVar1 = (undefined4 *)puVar2[2];
      }
      else {
        puVar1 = (undefined4 *)*puVar2;
      }
    } while (*(char *)((int)puVar1 + 0x15) == '\0');
  }
  _param_3 = puVar2;
  if (local_8 != '\0') {
    if (puVar2 == (undefined4 *)**(int **)((int)this + 4)) {
      local_8 = '\x01';
      goto LAB_10001cdf;
    }
    FUN_10001744((int *)&param_3);
  }
  puVar1 = _param_3;
  if ((uint)param_2[3] <= (uint)_param_3[3]) {
    operator_delete(param_2);
    *param_1 = puVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10001cdf:
  puVar2 = (undefined4 *)FUN_100018a0(this,(undefined4 *)&param_3,local_8,puVar2,param_2);
  *param_1 = *puVar2;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_10001d2a at 10001d2a

void __cdecl FUN_10001d2a(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_100019c9(param_2,param_3);
  return;
}



// Function: FUN_10001d3d at 10001d3d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10001d3d(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0;
  local_18[0] = (int *)*DAT_10013c94;
  while (piVar2 = local_18[0], local_18[0] != DAT_10013c94) {
    piVar1 = (int *)local_18[0][4];
    if (piVar1 != (int *)0x0) {
      FUN_100013fa(piVar1);
      operator_delete(piVar1);
    }
    FUN_10001678((int *)local_18);
    FUN_100019fc(&DAT_10013c90,&local_1c,piVar2);
    FUN_10001678((int *)local_18);
  }
  return;
}



// Function: Catch@10001da8 at 10001da8

undefined4 Catch_10001da8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10001da2;
}



// Function: FUN_10001db2 at 10001db2

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10001db2(int *param_1)

{
  int *this;
  char cVar1;
  uint uVar2;
  undefined4 local_2c;
  undefined2 local_28;
  undefined4 local_24;
  int local_20;
  int *local_1c;
  undefined4 *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_1c = (int *)0x0;
  local_8 = 0;
  local_18[0] = (undefined4 *)*DAT_10013c94;
  do {
    if (local_18[0] == DAT_10013c94) {
      return local_1c;
    }
    this = (int *)local_18[0][4];
    uVar2 = FUN_1000150d(this);
    if ((uVar2 & 1) != 0) {
      local_2c = 0;
      local_28 = 0x100;
      local_24 = 0xffffffff;
      local_20 = 0;
      FUN_10001122(this,&local_2c);
      if ((param_1[3] == local_20) && (cVar1 = FUN_10001530(this,3,param_1), cVar1 == '\x01')) {
        return this;
      }
    }
    FUN_10001678((int *)local_18);
  } while( true );
}



// Function: Catch@10001e3c at 10001e3c

undefined4 Catch_10001e3c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10001e27;
}



// Function: FUN_10001e46 at 10001e46

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_10001e46(void)

{
  int *this;
  char cVar1;
  int local_34;
  undefined2 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 *local_1c;
  undefined1 local_15;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_15 = 0;
  local_8 = 0;
  local_1c = (undefined4 *)*DAT_10013c94;
  while( true ) {
    if (local_1c == DAT_10013c94) {
      local_8 = 0xffffffff;
      FUN_10001ee7();
      return;
    }
    this = (int *)local_1c[4];
    local_24 = this;
    FUN_100010b9((int)this);
    local_34 = 0;
    local_2c = 0xffffffff;
    local_28 = 0;
    local_30 = 0x100;
    cVar1 = FUN_10001530(this,4,&local_34);
    if (cVar1 == '\x01') break;
    FUN_100010c5((int)this);
    FUN_10001678((int *)&local_1c);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  local_15 = FUN_10001236(this);
  local_8 = 0;
  FUN_10001ec4();
  return;
}



// Function: Catch@10001eb5 at 10001eb5

undefined * Catch_10001eb5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10001ebf;
}



// Function: FUN_10001ec4 at 10001ec4

void FUN_10001ec4(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  
  do {
    FUN_100010c5((int)unaff_ESI);
    FUN_10001678((int *)(unaff_EBP + -0x18));
    if (*(int *)(unaff_EBP + -0x18) == DAT_10013c94) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_10001ee7();
      return;
    }
    unaff_ESI = *(int **)(*(int *)(unaff_EBP + -0x18) + 0x10);
    *(int **)(unaff_EBP + -0x20) = unaff_ESI;
    FUN_100010b9((int)unaff_ESI);
    *(undefined4 *)(unaff_EBP + -0x30) = unaff_EBX;
    *(undefined4 *)(unaff_EBP + -0x28) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x24) = unaff_EBX;
    *(undefined2 *)(unaff_EBP + -0x2c) = 0x100;
    cVar1 = FUN_10001530(unaff_ESI,4,(int *)(unaff_EBP + -0x30));
  } while (cVar1 != '\x01');
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_10001236(unaff_ESI);
  *(undefined1 *)(unaff_EBP + -0x11) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = unaff_EBX;
  FUN_10001ec4();
  return;
}



// Function: Catch@10001edb at 10001edb

undefined * Catch_10001edb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10001ee5;
}



// Function: FUN_10001ee7 at 10001ee7

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_10001ee7(void)

{
  int *piVar1;
  LPSECURITY_ATTRIBUTES p_Var2;
  LPSECURITY_ATTRIBUTES unaff_EBX;
  int unaff_EBP;
  
  FUN_1000162a(*(int *)(unaff_EBP + -0x1c));
  p_Var2 = (LPSECURITY_ATTRIBUTES)CreateEventW(unaff_EBX,1,(BOOL)unaff_EBX,(LPCWSTR)unaff_EBX);
  if (p_Var2 != unaff_EBX) {
    WaitForSingleObject(p_Var2,DAT_10013c98 * 200);
    CloseHandle(p_Var2);
  }
  FUN_1000161e(*(int *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 4;
  *(LPSECURITY_ATTRIBUTES *)(unaff_EBP + -0x18) = unaff_EBX;
  *(int *)(unaff_EBP + -0x18) = *DAT_10013c94;
  while (piVar1 = *(int **)(unaff_EBP + -0x18), piVar1 != DAT_10013c94) {
    p_Var2 = (LPSECURITY_ATTRIBUTES)piVar1[4];
    FUN_10001678((int *)(unaff_EBP + -0x18));
    if (p_Var2 != unaff_EBX) {
      FUN_100013fa((int *)p_Var2);
      operator_delete(p_Var2);
    }
    FUN_100019fc(&DAT_10013c90,(undefined4 *)(unaff_EBP + -0x1c),piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return *(undefined1 *)(unaff_EBP + -0x11);
}



// Function: Catch@10001f7c at 10001f7c

undefined4 Catch_10001f7c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10001f73;
}



// Function: FUN_10001f86 at 10001f86

void __thiscall FUN_10001f86(void *this,undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint **ppuVar3;
  uint *local_8;
  
  puVar1 = param_2;
  local_8 = (uint *)this;
  puVar2 = FUN_100017d1(this,param_2);
  if ((puVar2 == *(uint **)((int)this + 4)) || (*puVar1 < puVar2[3])) {
    local_8 = *(uint **)((int)this + 4);
    ppuVar3 = &local_8;
  }
  else {
    ppuVar3 = &param_2;
  }
  *param_1 = *ppuVar3;
  return;
}



// Function: FUN_10001fc0 at 10001fc0

void __fastcall FUN_10001fc0(int param_1)

{
  FUN_10001c47(*(int **)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10001fe7 at 10001fe7

undefined4 * __thiscall FUN_10001fe7(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  char cVar4;
  int *piVar5;
  void *local_c;
  void *pvStack_8;
  
  piVar2 = param_3;
  local_c = this;
  pvStack_8 = this;
  if (*(int *)((int)this + 8) == 0) {
    FUN_100018a0(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)((int)this + 4);
  piVar5 = param_2;
  if (param_2 == (int *)*piVar1) {
    if ((uint)param_2[3] <= (uint)param_3[3]) goto LAB_100020b1;
    cVar4 = '\x01';
    goto LAB_100020a4;
  }
  if (param_2 == piVar1) {
    param_2 = (int *)piVar1[2];
    if ((uint)param_3[3] <= (uint)param_2[3]) goto LAB_100020b1;
  }
  else {
    if ((uint)param_3[3] < (uint)param_2[3]) {
      param_3 = param_2;
      FUN_10001744((int *)&param_3);
      if ((uint)piVar2[3] <= (uint)param_3[3]) goto LAB_1000206d;
      cVar4 = *(char *)(param_3[2] + 0x15);
      param_2 = param_3;
    }
    else {
LAB_1000206d:
      if ((uint)piVar2[3] <= (uint)param_2[3]) {
LAB_100020b1:
        puVar3 = (undefined4 *)FUN_10001c7c(this,&local_c,piVar2,'\0');
        *param_1 = *puVar3;
        return param_1;
      }
      param_3 = param_2;
      FUN_10001678((int *)&param_3);
      if ((param_3 != *(int **)((int)this + 4)) && ((uint)param_3[3] <= (uint)piVar2[3]))
      goto LAB_100020b1;
      cVar4 = *(char *)(param_2[2] + 0x15);
      piVar5 = param_3;
    }
    if (cVar4 == '\0') {
      cVar4 = '\x01';
      goto LAB_100020a4;
    }
  }
  cVar4 = '\0';
  piVar5 = param_2;
LAB_100020a4:
  FUN_100018a0(this,param_1,cVar4,piVar5,piVar2);
  return param_1;
}



// Function: FUN_100020cd at 100020cd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100020cd(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100017fd((int)this);
  FUN_10001d2a((int)this + 0xd,(undefined4 *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@1000210a at 1000210a

void Catch_1000210a(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000211d at 1000211d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000211d(void)

{
  int local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_18 = 0;
  local_8 = 0;
  FUN_10001f86(&DAT_10013c90,&local_1c,(uint *)&stack0x00000004);
  if (local_1c != DAT_10013c94) {
    local_18 = *(undefined4 *)(local_1c + 0x10);
  }
  return local_18;
}



// Function: Catch@10002163 at 10002163

undefined4 Catch_10002163(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10002158;
}



// Function: Catch@100021e2 at 100021e2

undefined1 * Catch_100021e2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_100021d7;
}



// Function: FUN_100021ec at 100021ec

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_100021ec(void)

{
  int local_2c;
  undefined2 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined1 local_15;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_15 = 0;
  local_8 = 0;
  FUN_10001f86(&DAT_10013c90,&local_1c,(uint *)&stack0x00000004);
  if (local_1c != DAT_10013c94) {
    local_2c = 0;
    local_24 = 0xffffffff;
    local_20 = 0;
    local_28 = 0x100;
    FUN_100010b9(*(int *)(local_1c + 0x10));
    FUN_10001161(*(void **)(local_1c + 0x10),(int *)0x0);
    local_15 = FUN_10001530(*(void **)(local_1c + 0x10),2,&local_2c);
    FUN_100010c5(*(int *)(local_1c + 0x10));
  }
  return local_15;
}



// Function: Catch@10002266 at 10002266

undefined4 Catch_10002266(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000225b;
}



// Function: FUN_10002270 at 10002270

void __thiscall FUN_10002270(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_10001fc0((int)this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_10001678((int *)&param_2);
      FUN_100019fc(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_100022c3 at 100022c3

uint * __thiscall FUN_100022c3(void *this,uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  void *local_c;
  void *local_8;
  
  puVar1 = param_1;
  local_c = this;
  local_8 = this;
  puVar2 = FUN_100017d1(this,param_1);
  if ((puVar2 == *(uint **)((int)this + 4)) || (*puVar1 < puVar2[3])) {
    local_c = (void *)*puVar1;
    local_8 = (void *)0x0;
    piVar3 = (int *)FUN_100020cd(this,&local_c);
    FUN_10001fe7(this,&param_1,(int *)puVar2,piVar3);
    puVar2 = param_1;
  }
  return puVar2 + 4;
}



// Function: FUN_10002312 at 10002312

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10002312(void *this,int *param_1)

{
  bool bVar1;
  char cVar2;
  void *this_00;
  int *this_01;
  uint *puVar3;
  
  if (DAT_10013c98 < *(int *)((int)this + 4)) {
    this_00 = operator_new(0x2c);
    if (this_00 == (void *)0x0) {
      this_01 = (int *)0x0;
    }
    else {
      this_01 = (int *)FUN_10001087(this_00,*(undefined4 *)((int)this + 0xc));
    }
    bVar1 = FUN_10001406(this_01,param_1);
    if ((bVar1) && (cVar2 = FUN_10001530(this_01,4,param_1), cVar2 == '\x01')) {
      FUN_1000120d(this_01,0x1000216d);
      param_1 = (int *)FUN_100011ab((int)this_01);
      puVar3 = FUN_100022c3(&DAT_10013c90,(uint *)&param_1);
      *puVar3 = (uint)this_01;
      return this_01;
    }
    if (this_01 != (int *)0x0) {
      FUN_100013fa(this_01);
      operator_delete(this_01);
    }
  }
  return (int *)0x0;
}



// Function: Catch@100023c6 at 100023c6

undefined4 Catch_100023c6(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100023bb;
}



// Function: FUN_100023d0 at 100023d0

undefined1 __thiscall FUN_100023d0(void *this,int *param_1,undefined4 *param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_1c;
  bool local_18;
  undefined1 uStack_17;
  undefined4 local_14;
  int local_10;
  void *local_c;
  undefined1 local_5;
  
  local_5 = 0;
  if ((*param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    piVar2 = (int *)param_1[2];
    local_14 = 0xffffffff;
    local_1c = *piVar2;
    local_10 = piVar2[1];
    _local_18 = CONCAT11(1,piVar2[2] != 0);
    local_c = this;
    if ((local_10 != 0) || (piVar2 = FUN_10001db2(&local_1c), piVar2 == (int *)0x0)) {
      local_14 = *(undefined4 *)((int)local_c + 8);
      _local_18 = CONCAT11(1,local_18);
      piVar2 = FUN_10002312(local_c,&local_1c);
      if (piVar2 == (int *)0x0) {
        return local_5;
      }
    }
    uVar3 = FUN_1000150d(piVar2);
    cVar1 = FUN_100014d8(piVar2,uVar3 & 0xfffffffe);
    if (((cVar1 == '\x01') && (cVar1 = FUN_10001161(piVar2,(int *)*param_1), cVar1 == '\x01')) &&
       ((param_1[1] != 0 || (cVar1 = FUN_100011de((int)piVar2), cVar1 == '\x01')))) {
      uVar4 = FUN_100011ab((int)piVar2);
      *param_2 = uVar4;
      local_5 = 1;
    }
  }
  return local_5;
}



// Function: FUN_1000249b at 1000249b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000249b(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10002270(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_100024d5 at 100024d5

undefined1 __thiscall FUN_100024d5(void *this,int *param_1)

{
  int iVar1;
  char cVar2;
  int *this_00;
  uint *puVar3;
  int iVar4;
  int local_18;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_5;
  
  iVar4 = 0;
  local_5 = 0;
  if ((((-1 < *param_1) && (iVar1 = param_1[2], 0 < iVar1)) && (*param_1 <= iVar1)) &&
     (DAT_10013c98 == 0)) {
    *(int *)((int)this + 4) = iVar1;
    *(int *)((int)this + 8) = param_1[1];
    iVar1 = *param_1;
    *(int *)this = iVar1;
    local_5 = 1;
    if (0 < iVar1) {
      do {
        local_18 = 0;
        local_10 = 0xffffffff;
        local_c = 0;
        local_14 = 0;
        this_00 = FUN_10002312(this,&local_18);
        if (this_00 == (int *)0x0) {
          return 0;
        }
        cVar2 = FUN_10001530(this_00,4,&local_18);
        if (cVar2 != '\x01') {
          FUN_100013fa(this_00);
          operator_delete(this_00);
          return 0;
        }
        param_1 = (int *)FUN_100011ab((int)this_00);
        puVar3 = FUN_100022c3(&DAT_10013c90,(uint *)&param_1);
        iVar4 = iVar4 + 1;
        *puVar3 = (uint)this_00;
                    /* WARNING: Load size is inaccurate */
      } while (iVar4 < *this);
    }
  }
  return local_5;
}



// Function: FUN_10002592 at 10002592

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10002592(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000259e;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_10001869(param_1);
  return local_18;
}



// Function: _InlineIsEqualGUID at 100025be

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



// Function: FUN_100025ee at 100025ee

bool __cdecl FUN_100025ee(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: AtlMultiply<unsigned_long> at 10002608

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



// Function: AtlCoTaskMemCAlloc at 1000262a

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



// Function: FUN_10002657 at 10002657

LPVOID __cdecl FUN_10002657(LPVOID param_1,ulong param_2,ulong param_3)

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



// Function: FUN_10002687 at 10002687

bool __cdecl FUN_10002687(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = lstrlenW(param_3);
  eVar2 = memcpy_s(param_1,param_2 * 2,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_100026b4 at 100026b4

void FUN_100026b4(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_10010560);
}



// Function: AtlCrtErrorCheck at 100026cc

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
  FUN_100026b4(uVar1);
}



// Function: FUN_10002704 at 10002704

void __cdecl FUN_10002704(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: FUN_10002724 at 10002724

void __cdecl FUN_10002724(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  ATL::AtlCrtErrorCheck(eVar1);
  return;
}



// Function: Init at 10002741

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



// Function: FUN_1000276a at 1000276a

void __fastcall FUN_1000276a(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_1000277c at 1000277c

DWORD FUN_1000277c(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
  return DVar1;
}



// Function: FUN_10002791 at 10002791

uint __cdecl FUN_10002791(uint param_1)

{
  if (0 < (int)param_1) {
    param_1 = param_1 & 0xffff | 0x80070000;
  }
  return param_1;
}



// Function: FID_conflict:RegOpenKeyExA at 100027a7

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
                    /* WARNING: Could not recover jumptable at 0x100027f0. Too many branches */
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



// Function: FID_conflict:RegCreateKeyExW at 100027fe

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
                    /* WARNING: Could not recover jumptable at 0x10002853. Too many branches */
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



// Function: FID_conflict:RegDeleteKeyA at 10002861

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
                    /* WARNING: Could not recover jumptable at 0x100028a4. Too many branches */
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



// Function: FUN_100028b3 at 100028b3

void __cdecl FUN_100028b3(short *param_1,int param_2,short *param_3)

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



// Function: FUN_10002901 at 10002901

int __fastcall FUN_10002901(int param_1)

{
  memset((void *)(param_1 + 0xc),0,0x18);
  return param_1;
}



// Function: DeleteSubKey at 10002918

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10013ca4 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10013ca0 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10013ca4 = '\x01';
    }
    if (DAT_10013ca0 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10013ca0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FID_conflict_RegDeleteKeyA(*this,(LPCSTR)param_1);
  }
  return;
}



// Function: Close at 10002988

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



// Function: Create at 100029a3

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



// Function: Open at 10002a0b

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



// Function: SetStringValue at 10002a5a

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



// Function: FUN_10002a91 at 10002a91

LSTATUS __thiscall FUN_10002a91(void *this,LPCWSTR param_1,LPCWSTR param_2)

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



// Function: FUN_10002ad4 at 10002ad4

undefined4 __fastcall FUN_10002ad4(undefined4 *param_1)

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



// Function: FUN_10002af4 at 10002af4

undefined4 * __thiscall FUN_10002af4(void *this,ulong param_1)

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



// Function: FUN_10002b2a at 10002b2a

void __fastcall FUN_10002b2a(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_10002b34 at 10002b34

undefined4 __thiscall FUN_10002b34(void *this,void *param_1,int param_2)

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
      pvVar4 = FUN_10002657(*(LPVOID *)((int)this + 8),uVar3,2);
      if (pvVar4 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (((-1 < iVar1) && (iVar2 = *(int *)((int)this + 4), iVar1 < iVar2)) &&
       (iVar2 - iVar1 <= iVar2)) {
      FUN_10002704((void *)(*(int *)((int)this + 8) + iVar1 * 2),(iVar2 - iVar1) * 2,param_1,
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



// Function: FUN_10002bc2 at 10002bc2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10002bc2(undefined4 param_1,undefined2 *param_2)

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
  local_8 = 0x10002bce;
  uVar5 = 0;
  puVar3 = auStack_20;
  if ((DAT_10013cc8 & 1) == 0) {
    DAT_10013cc8 = DAT_10013cc8 | 1;
    DAT_10013cac = 8;
    _DAT_10013cb4 = 0x4008;
    _DAT_10013cbc = 0x13;
    DAT_10013ca8 = &DAT_1000e364;
    DAT_10013cb0 = &DAT_1000e360;
    _DAT_10013cb8 = &DAT_1000e35c;
    _DAT_10013cc0 = &DAT_1000e358;
    _DAT_10013cc4 = 0x11;
    local_8 = 0xffffffff;
  }
  do {
    *(undefined **)(puVar3 + -4) = (&DAT_10013ca8)[uVar5 * 2];
    *(undefined4 *)(puVar3 + -8) = param_1;
    puVar4 = puVar3 + -0xc;
    *(undefined4 *)(puVar3 + -0xc) = 0x10002c45;
    iVar1 = lstrcmpiW(*(LPCWSTR *)(puVar3 + -8),*(LPCWSTR *)(puVar3 + -4));
    if (iVar1 == 0) {
      *param_2 = (&DAT_10013cac)[uVar5 * 4];
      uVar2 = 1;
      goto LAB_10002c51;
    }
    uVar5 = uVar5 + 1;
    puVar3 = puVar4;
  } while (uVar5 < 4);
  uVar2 = 0;
LAB_10002c51:
  *(undefined4 *)(puVar4 + -4) = 0x10002c56;
  return uVar2;
}



// Function: FUN_10002c6a at 10002c6a

int __cdecl FUN_10002c6a(ushort param_1)

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



// Function: FUN_10002ca0 at 10002ca0

undefined4 __cdecl FUN_10002ca0(LPCWSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_1000e518)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_1000e51c)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}



// Function: FUN_10002cce at 10002cce

LPCWSTR __cdecl FUN_10002cce(LPCWSTR param_1,WCHAR param_2)

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



// Function: FUN_10002cfb at 10002cfb

undefined4 FUN_10002cfb(ushort param_1)

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



// Function: FUN_10002d21 at 10002d21

void __fastcall FUN_10002d21(undefined4 *param_1)

{
  LPWSTR pWVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = FUN_10002cfb(*(ushort *)*param_1);
    if (iVar2 == 0) break;
    pWVar1 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar1;
  }
  return;
}



// Function: FUN_10002d43 at 10002d43

undefined4 __thiscall FUN_10002d43(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_10002d21((undefined4 *)this);
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
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_10002ad4((undefined4 *)this), iVar5 == 0))) {
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
        iVar5 = FUN_10002cfb(*pWVar2);
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



// Function: FUN_10002e59 at 10002e59

undefined4 FUN_10002e59(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_1000e3d8;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x1000e408);
  return 1;
}



// Function: FUN_10002e88 at 10002e88

bool FUN_10002e88(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;
  
  local_8 = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_8 != 0;
}



// Function: FUN_10002ebd at 10002ebd

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10002ebd(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10013c58 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_10002d43(this,param_1), -1 < iVar1)) {
    FUN_10002d21((undefined4 *)this);
    iVar1 = FUN_10002d43(this,local_2008);
    if (-1 < iVar1) {
      FUN_10002d43(this,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: DllCanUnloadNow at 10002f22

HRESULT DllCanUnloadNow(void)

{
                    /* 0x2f22  1  DllCanUnloadNow */
  return (uint)(DAT_10013d44 != 0);
}



// Function: FUN_10002f2e at 10002f2e

undefined4 FUN_10002f2e(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10013c74;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10002f4d at 10002f4d

undefined4 __thiscall FUN_10002f4d(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_10013c7c = *param_3;
    DAT_10013c80 = param_3[1];
    DAT_10013c84 = param_3[2];
    DAT_10013c88 = param_3[3];
  }
  piVar2 = DAT_10013e04;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar2 = DAT_10013e04, param_1 != (int *)0x0)) {
    iVar1 = *param_1;
    while (DAT_10013e04 = piVar2, iVar1 != 0) {
      (*(code *)param_1[8])(1);
      param_1 = param_1 + 9;
      piVar2 = DAT_10013e04;
      iVar1 = *param_1;
    }
  }
  for (; piVar2 < DAT_10013e08; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10002fab at 10002fab

void FUN_10002fab(int param_1)

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



// Function: FUN_10002ff4 at 10002ff4

void __fastcall FUN_10002ff4(int param_1)

{
  long lVar1;
  
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (-1 < lVar1) {
    *(undefined1 *)(param_1 + 0x1c) = 1;
  }
  return;
}



// Function: FUN_10003009 at 10003009

void __fastcall FUN_10003009(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
  }
  return;
}



// Function: FUN_10003023 at 10003023

void __fastcall FUN_10003023(undefined4 *param_1)

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



// Function: FUN_10003050 at 10003050

void __fastcall FUN_10003050(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000305d at 1000305d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_1000305d(LPCRITICAL_SECTION param_1)

{
  undefined1 *puVar1;
  undefined1 *extraout_EAX;
  
  puVar1 = &LAB_1000bde0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
    puVar1 = extraout_EAX;
  }
  return puVar1;
}



// Function: FUN_10003087 at 10003087

int __thiscall FUN_10003087(void *this,undefined4 *param_1)

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



// Function: FUN_100030be at 100030be

void __fastcall FUN_100030be(undefined4 *param_1)

{
  free((void *)*param_1);
  return;
}



// Function: FUN_100030c8 at 100030c8

void __thiscall FUN_100030c8(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_100026b4(0x8007000e);
  }
  *(void **)this = pvVar1;
  return;
}



// Function: AtlMultiplyThrow<unsigned_int> at 100030ed

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
    FUN_100026b4(lVar1);
  }
  return local_8;
}



// Function: FUN_10003112 at 10003112

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __fastcall FUN_10003112(void *param_1)

{
  memset(param_1,0,0x18);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  return param_1;
}



// Function: FUN_10003140 at 10003140

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_10003140(undefined4 *param_1)

{
  FUN_1000ab98((int)param_1);
  *param_1 = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  (**(code **)(*DAT_10013c78 + 4))();
  return param_1;
}



// Function: FUN_10003195 at 10003195

int __cdecl FUN_10003195(ushort *param_1,ushort *param_2,int param_3)

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



// Function: AtlComQIPtrAssign at 100031c9

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



// Function: Attach at 10003200

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



// Function: FUN_1000321f at 1000321f

int __thiscall FUN_1000321f(void *this,void *param_1)

{
  int iVar1;
  errno_t eVar2;
  
  if (param_1 == (void *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    iVar1 = Ordinal_9(param_1);
    if (-1 < iVar1) {
      eVar2 = memcpy_s(param_1,0x10,this,0x10);
      ATL::AtlCrtErrorCheck(eVar2);
      iVar1 = 0;
      *(undefined2 *)this = 0;
    }
  }
  return iVar1;
}



// Function: InternalCopy at 10003260

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
    FUN_100026b4(iVar1);
  }
  return;
}



// Function: InlineIsEqualUnknown at 10003288

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



// Function: AtlInternalQueryInterface at 100032b6

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
          if (pcVar1 == (code *)0x1) goto LAB_100032ea;
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
LAB_100032ea:
      piVar4 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      lVar2 = 0;
    }
  }
  return lVar2;
}



// Function: FUN_10003380 at 10003380

void FUN_10003380(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x2c));
  return;
}



// Function: FUN_10003394 at 10003394

LONG FUN_10003394(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)(param_1 + 0x2c));
  if ((LVar1 == 0) && (param_1 != 0)) {
    (**(code **)(*(int *)(param_1 + 0x10) + 0x14))(1);
  }
  return LVar1;
}



// Function: FUN_100033c2 at 100033c2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100033c2(int param_1)

{
  FUN_1000ac33(param_1);
  return;
}



// Function: FID_conflict:_Inside at 100033e0

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



// Function: FUN_1000341c at 1000341c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000341c(void *this,undefined4 param_1)

{
  FUN_1000ab98((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CThreadServiceImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CThreadServiceImpl>::vftable;
  *(undefined ***)((int)this + 8) = ATL::CComContainedObject<class_CThreadServiceImpl>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComContainedObject<class_CThreadServiceImpl>::vftable;
  *(undefined ***)((int)this + 0x10) = ATL::CComContainedObject<class_CThreadServiceImpl>::vftable;
  *(undefined4 *)((int)this + 0x2c) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1000346c at 1000346c

void FUN_1000346c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 4))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000347f at 1000347f

void FUN_1000347f(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 8))(*(int **)(param_1 + 0x2c));
  return;
}



// Function: FUN_10003492 at 10003492

void FUN_10003492(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x2c))(*(undefined4 **)(param_1 + 0x2c),param_2,param_3);
  return;
}



// Function: FUN_100034aa at 100034aa

undefined4 __fastcall FUN_100034aa(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}



// Function: FUN_100034ae at 100034ae

void __fastcall FUN_100034ae(int *param_1)

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



// Function: FUN_100034e9 at 100034e9

void __fastcall FUN_100034e9(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0x41) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0x41) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0x41) == '\0');
      *param_1 = (int)piVar2;
      return;
    }
    for (iVar3 = *(int *)(iVar3 + 4);
        (*(char *)(iVar3 + 0x41) == '\0' && (*param_1 == *(int *)(iVar3 + 8)));
        iVar3 = *(int *)(iVar3 + 4)) {
      *param_1 = iVar3;
    }
    *param_1 = iVar3;
  }
  return;
}



// Function: FUN_10003524 at 10003524

void __fastcall FUN_10003524(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_1000352b at 1000352b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000352b(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10003537;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10010150);
}



// Function: FUN_1000358a at 1000358a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_1000358a(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10003596;
  if (param_1 == (char *)0x0) {
    return (void *)0x0;
  }
  if ((param_1 < (char *)0x38e38e4) &&
     (pvVar1 = operator_new((int)param_1 * 0x48), pvVar1 != (void *)0x0)) {
    return pvVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10010150);
}



// Function: FUN_100035e9 at 100035e9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_100035e9(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x100035f5;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10010150);
}



// Function: FUN_10003648 at 10003648

undefined4 * __thiscall FUN_10003648(void *this,byte param_1)

{
  FUN_10003524((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003667 at 10003667

void __fastcall FUN_10003667(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar1 + 0x41) != '\0') {
    *param_1 = puVar1[2];
    return;
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)((int)*puVar1 + 0x41) == '\0') {
    do {
      piVar3 = piVar2;
      piVar2 = (int *)piVar3[2];
    } while (*(char *)(piVar3[2] + 0x41) == '\0');
  }
  else {
    for (piVar3 = (int *)puVar1[1]; (*(char *)((int)piVar3 + 0x41) == '\0' && (*param_1 == *piVar3))
        ; piVar3 = (int *)piVar3[1]) {
      *param_1 = (int)piVar3;
    }
    if (*(char *)(*param_1 + 0x41) != '\0') {
      return;
    }
  }
  *param_1 = (int)piVar3;
  return;
}



// Function: FUN_100036ad at 100036ad

void FUN_100036ad(int param_1)

{
  FUN_10003394(param_1 + -0xc);
  return;
}



// Function: FUN_100036b7 at 100036b7

void FUN_100036b7(int param_1)

{
  FUN_10003380(param_1 + -8);
  return;
}



// Function: FUN_100036c1 at 100036c1

void FUN_100036c1(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003492(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_100036cb at 100036cb

void FUN_100036cb(int param_1)

{
  FUN_1000347f(param_1 + -4);
  return;
}



// Function: FUN_100036d5 at 100036d5

void __thiscall FUN_100036d5(void *this,byte param_1)

{
  FUN_10003737((void *)((int)this + -0x10),param_1);
  return;
}



// Function: FUN_100036dd at 100036dd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100036dd(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[2] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[3] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CThreadServiceImpl>::vftable;
  param_1[0xb] = 0xc0000001;
  (**(code **)(*DAT_10013c78 + 8))();
  FUN_1000ac33((int)param_1);
  return;
}



// Function: FUN_10003737 at 10003737

undefined4 * __thiscall FUN_10003737(void *this,byte param_1)

{
  FUN_100036dd((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10003756 at 10003756

void FUN_10003756(int param_1)

{
  FUN_10003394(param_1 + -0x10);
  return;
}



// Function: FUN_10003760 at 10003760

void FUN_10003760(int param_1)

{
  FUN_10003380(param_1 + -0xc);
  return;
}



// Function: FUN_1000376a at 1000376a

void FUN_1000376a(int param_1)

{
  FUN_1000347f(param_1 + -8);
  return;
}



// Function: FUN_10003774 at 10003774

void FUN_10003774(int param_1)

{
  FUN_10003380(param_1 + -0x10);
  return;
}



// Function: FUN_1000377e at 1000377e

void FUN_1000377e(int param_1)

{
  FUN_1000347f(param_1 + -0xc);
  return;
}



// Function: FUN_10003788 at 10003788

void FUN_10003788(int param_1)

{
  FUN_1000346c(param_1 + -4);
  return;
}



// Function: FUN_10003792 at 10003792

void FUN_10003792(int param_1)

{
  FUN_1000347f(param_1 + -0x10);
  return;
}



// Function: FUN_1000379c at 1000379c

void FUN_1000379c(int param_1)

{
  FUN_1000346c(param_1 + -8);
  return;
}



// Function: FUN_100037a6 at 100037a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100037a6(void *this,byte param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)((int)this + -0x10);
  FUN_1000ac33((int)pvVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(pvVar1);
  }
  return pvVar1;
}



// Function: FUN_100037df at 100037df

void FUN_100037df(int param_1)

{
  FUN_1000346c(param_1 + -0xc);
  return;
}



// Function: FUN_100037e9 at 100037e9

void FUN_100037e9(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003492(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_100037f3 at 100037f3

void FUN_100037f3(int param_1)

{
  FUN_1000346c(param_1 + -0x10);
  return;
}



// Function: FUN_100037fd at 100037fd

void FUN_100037fd(int param_1)

{
  FUN_10003394(param_1 + -4);
  return;
}



// Function: FUN_10003807 at 10003807

void FUN_10003807(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003492(param_1 + -8,param_2,param_3);
  return;
}



// Function: FUN_10003811 at 10003811

void FUN_10003811(int param_1)

{
  FUN_10003394(param_1 + -8);
  return;
}



// Function: FUN_1000381b at 1000381b

void FUN_1000381b(int param_1)

{
  FUN_10003380(param_1 + -4);
  return;
}



// Function: FUN_10003825 at 10003825

void FUN_10003825(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10003492(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_1000382f at 1000382f

void __fastcall FUN_1000382f(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return;
  }
  uVar1 = Ordinal_149(*param_1);
  Ordinal_150(*param_1,uVar1);
  return;
}



// Function: FUN_1000384c at 1000384c

void __fastcall FUN_1000384c(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10003854 at 10003854

undefined2 * __thiscall FUN_10003854(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_9(this);
  if (-1 < iVar1) {
    *(undefined2 *)this = 8;
    iVar1 = FUN_1000382f(param_1);
    *(int *)((int)this + 8) = iVar1;
    if ((iVar1 != 0) || (*param_1 == 0)) {
      return (undefined2 *)this;
    }
    *(undefined2 *)this = 10;
    iVar1 = -0x7ff8fff2;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
  }
                    /* WARNING: Subroutine does not return */
  FUN_100026b4(iVar1);
}



// Function: FUN_1000389f at 1000389f

short * __thiscall FUN_1000389f(void *this,char param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != 0xb) {
    iVar1 = Ordinal_9(this);
    if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100026b4(iVar1);
    }
    *(undefined2 *)this = 0xb;
  }
  *(ushort *)((int)this + 8) = (param_1 == '\0') - 1;
  return (short *)this;
}



// Function: FUN_100038d6 at 100038d6

short * __thiscall FUN_100038d6(void *this,undefined4 param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != 3) {
    iVar1 = Ordinal_9(this);
    if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100026b4(iVar1);
    }
    *(undefined2 *)this = 3;
  }
  *(undefined4 *)((int)this + 8) = param_1;
  return (short *)this;
}



// Function: FUN_10003906 at 10003906

int __fastcall FUN_10003906(int param_1)

{
  long lVar1;
  
  FUN_10002901(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10013c78 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 0x10));
  if (lVar1 < 0) {
    DAT_10013c68 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  return param_1;
}



// Function: FUN_10003947 at 10003947

void __fastcall FUN_10003947(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002fab((int)piVar1);
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



// Function: FUN_10003980 at 10003980

void __fastcall FUN_10003980(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(param_1 + 4);
  if (*piVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_10002fab((int)piVar1);
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



// Function: FUN_10003985 at 10003985

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003985(int param_1)

{
  FUN_10003947(param_1);
  return;
}



// Function: FUN_100039a3 at 100039a3

LSTATUS __fastcall FUN_100039a3(undefined4 *param_1)

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



// Function: FUN_100039a8 at 100039a8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100039a8(void *this,LPCWSTR param_1)

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
      iVar1 = FUN_100039a8(&local_224,local_214);
    } while (iVar1 == 0);
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  else {
    local_8 = 0xffffffff;
    ATL::CRegKey::Close((CRegKey *)&local_224);
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_10003a8d at 10003a8d

undefined4 __fastcall FUN_10003a8d(int *param_1)

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
LAB_10003ad2:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      operator_delete__(*(void **)(*param_1 + iVar4 * 4));
      if (param_1[2] <= iVar4) goto LAB_10003ad2;
      operator_delete__(*(void **)(param_1[1] + iVar4 * 4));
      iVar2 = param_1[2];
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_10003023(param_1);
  return 0;
}



// Function: FUN_10003ae4 at 10003ae4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10003ae4(void *this,LPCWSTR param_1)

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
    uVar1 = FUN_10002b34(this,param_1,iVar2);
    local_8 = 0xffffffff;
    FUN_10003009(local_14);
  }
  return uVar1;
}



// Function: FUN_10003b2b at 10003b2b

void FUN_10003b2b(int param_1)

{
  FUN_10003a8d((int *)(param_1 + 4));
  return;
}



// Function: FUN_10003b3d at 10003b3d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10003b3d(HMODULE param_1,LPCWSTR param_2,undefined4 *param_3,undefined4 *param_4)

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
  local_8 = 0x10003b4c;
  local_244 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) goto LAB_10003d17;
  *param_3 = 0;
  *param_4 = 0;
  local_248 = 0;
  local_8 = 0;
  DVar2 = GetModuleFileNameW(param_1,local_23c,0x104);
  if (DVar2 == 0) {
    FUN_1000277c();
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
      if (((uVar1 < DVar2) || (uVar1 < uVar3)) || (0x10d < uVar1)) goto LAB_10003baa;
      FUN_10002724(local_23c + DVar2,0x10e - DVar2,local_244);
    }
    iVar4 = Ordinal_161(local_23c,param_4);
    if (iVar4 < 0) {
      builtin_wcsncpy(local_20,L".tlb",5);
      iVar4 = (int)local_240 - (int)local_23c >> 1;
      if (iVar4 + 5U < 0x105) {
        eVar5 = wcscpy_s(local_240,0x10e - iVar4,local_20);
        ATL::AtlCrtErrorCheck(eVar5);
        iVar4 = Ordinal_161(local_23c,param_4);
        if (-1 < iVar4) goto LAB_10003ce7;
      }
    }
    else {
LAB_10003ce7:
      uVar6 = Ordinal_2(local_23c);
      *param_3 = uVar6;
    }
  }
LAB_10003baa:
  local_8 = 0xffffffff;
  FUN_10003009(&local_248);
LAB_10003d17:
  FUN_1000b1dd();
  return;
}



// Function: FUN_10003d1f at 10003d1f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10003d1f(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10003d44 at 10003d44

void __fastcall FUN_10003d44(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  piVar2 = DAT_10013e04;
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = DAT_10013e04, *piVar1 != 0; piVar1 = piVar1 + 9) {
      piVar2 = (int *)piVar1[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar1[4] = 0;
      (*(code *)piVar1[8])(0);
    }
  }
  for (; piVar2 < DAT_10013e08; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x20))(0);
    }
  }
  FUN_10003947(param_1);
  return;
}



// Function: FUN_10003d96 at 10003d96

void __thiscall FUN_10003d96(void *this,undefined4 param_1,undefined4 param_2)

{
  if (*(char *)((int)this + 0x14) == '\0') {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0x2c))(param_1);
  }
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x28))(param_2);
  return;
}



// Function: FUN_10003db9 at 10003db9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003db9(undefined4 param_1,int *param_2)

{
  undefined4 **ppuVar1;
  int iVar2;
  
  ppuVar1 = FUN_1000a1aa();
  if (ppuVar1 == (undefined4 **)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Ordinal_2(ppuVar1);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_100026b4(0x8007000e);
    }
  }
  *param_2 = iVar2;
  Ordinal_6(0);
  return 0;
}



// Function: FUN_10003e0d at 10003e0d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10003e0d(void *this,wchar_t *param_1)

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
  local_8 = 0x10003e19;
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
      local_18 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_18 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_18 = uVar2;
        puVar6 = local_18 + 1;
        _eh_vector_constructor_iterator_
                  (puVar6,0xc,uVar2,(_func_void_void_ptr *)&LAB_10003357,
                   (_func_void_void_ptr *)&LAB_10001009);
      }
      local_8 = 0xffffffff;
      local_1c = puVar6;
      uVar7 = FUN_10003ebd();
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



// Function: Catch@10003ead at 10003ead

undefined * Catch_10003ead(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10003eb7;
}



// Function: FUN_10003ebd at 10003ebd

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10003ebd(void)

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



// Function: FUN_10003f75 at 10003f75

void FUN_10003f75(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_1000102a(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FID_conflict:_Tidy at 10003fa8

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



// Function: FUN_10003ff6 at 10003ff6

void __fastcall FUN_10003ff6(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_10004006 at 10004006

void __fastcall FUN_10004006(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_100030be(param_1);
    return;
  }
  return;
}



// Function: FUN_10004013 at 10004013

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004013(int param_1)

{
  FUN_1000305d((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10004034 at 10004034

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_10004034(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_10004088 at 10004088

void __fastcall FUN_10004088(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1000409f at 1000409f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_1000409f(void *this,undefined4 *param_1)

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
    (**(code **)**this)(*this,&DAT_1000e9c0,&local_18);
    (**(code **)*param_1)(param_1,&DAT_1000e9c0,local_14);
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



// Function: FUN_1000412a at 1000412a

void __fastcall FUN_1000412a(int param_1)

{
  operator_delete(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10004134 at 10004134

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004134(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    puVar1 = (undefined4 *)operator_new(0x74);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10003140(puVar1);
    }
    iVar2 = FUN_10004198();
    return iVar2;
  }
  return -0x7fffbffd;
}



// Function: Catch@10004188 at 10004188

undefined * Catch_10004188(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10004192;
}



// Function: FUN_10004198 at 10004198

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004198(void)

{
  LONG *lpAddend;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    lpAddend = unaff_ESI + 0xb;
    InterlockedIncrement(lpAddend);
    unaff_EBX = FUN_10002ff4((int)lpAddend);
    if (-1 < unaff_EBX) {
      unaff_EBX = 0;
    }
    InterlockedDecrement(lpAddend);
    if ((unaff_EBX == 0) && (unaff_EBX = (**(code **)*unaff_ESI)(), unaff_EBX == 0)) {
      return 0;
    }
    (**(code **)(unaff_ESI[4] + 0x14))(1);
  }
  return unaff_EBX;
}



// Function: QueryInterface at 100041e5

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000e7f0,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100041ff at 100041ff

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_100041ff(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CThreadServiceImpl>::vftable;
  FUN_1000341c((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_10013c78 + 4))();
  return (undefined4 *)this;
}



// Function: FUN_10004242 at 10004242

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004242(undefined4 *param_1)

{
  *param_1 = ATL::CComAggObject<class_CThreadServiceImpl>::vftable;
  param_1[1] = 0xc0000001;
  (**(code **)(*DAT_10013c78 + 8))();
  FUN_1000ac33((int)(param_1 + 3));
  return;
}



// Function: FUN_10004288 at 10004288

void FUN_10004288(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: Release at 1000429c

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



// Function: FUN_100042c9 at 100042c9

long FUN_100042c9(int *param_1,_GUID *param_2,void **param_3)

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
                        (param_1 + 3,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000e7f0,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar2;
}



// Function: FUN_10004315 at 10004315

undefined4 * __thiscall FUN_10004315(void *this,byte param_1)

{
  FUN_10004242((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004334 at 10004334

void __thiscall FUN_10004334(void *this,int param_1)

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



// Function: FUN_10004379 at 10004379

void __thiscall FUN_10004379(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x41) == '\0') {
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



// Function: FUN_100043be at 100043be

void __thiscall FUN_100043be(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x41) == '\0') {
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



// Function: FUN_10004405 at 10004405

void __fastcall FUN_10004405(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_1000441d at 1000441d

uint __thiscall FUN_1000441d(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
  uVar1 = FUN_10003195((ushort *)((int)this + param_1 * 2),param_3,uVar1);
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



// Function: FUN_10004481 at 10004481

void __thiscall FUN_10004481(void *this,int *param_1)

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



// Function: FUN_100044c8 at 100044c8

void __fastcall FUN_100044c8(int *param_1)

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



// Function: FUN_1000450e at 1000450e

void __fastcall FUN_1000450e(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000352b((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0xb) = 0;
  return;
}



// Function: FUN_10004535 at 10004535

void __fastcall FUN_10004535(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000358a((char *)0x1);
  *puVar1 = *(undefined4 *)(param_1 + 4);
  puVar1[1] = *(undefined4 *)(param_1 + 4);
  puVar1[2] = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(puVar1 + 0x10) = 0;
  return;
}



// Function: FUN_1000455c at 1000455c

void FUN_1000455c(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -4),param_2);
  return;
}



// Function: FUN_10004566 at 10004566

void FUN_10004566(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -8),param_2);
  return;
}



// Function: FUN_10004570 at 10004570

void FUN_10004570(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0xc),param_2);
  return;
}



// Function: FUN_1000457a at 1000457a

void FUN_1000457a(int param_1,void **param_2)

{
  CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface((_GUID *)(param_1 + -0x10),param_2);
  return;
}



// Function: FUN_10004584 at 10004584

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_10004584(undefined4 *param_1)

{
  FUN_10003906((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10013c8c = param_1;
  return param_1;
}



// Function: FUN_100045b9 at 100045b9

void __fastcall FUN_100045b9(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100045c4 at 100045c4

void __fastcall FUN_100045c4(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100045cf at 100045cf

HRESULT __thiscall FUN_100045cf(void *this,undefined4 *param_1)

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
       (HVar1 = CoCreateInstance((IID *)&DAT_1000ee50,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000ea10,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(**ppv + 4))(*ppv);
    }
  }
  return HVar1;
}



// Function: FUN_1000461b at 1000461b

undefined4 FUN_1000461b(void)

{
  return 0x80004005;
}



// Function: FUN_10004623 at 10004623

void FUN_10004623(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",&DAT_1000ea20);
  return;
}



// Function: FUN_1000463d at 1000463d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_1000463d(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_10003947((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004674 at 10004674

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10004674(int *param_1)

{
  FUN_10003a8d(param_1);
  FUN_10003023(param_1);
  return;
}



// Function: FUN_1000469e at 1000469e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000469e(undefined4 *param_1)

{
  *param_1 = ATL::CRegObject::vftable;
  FUN_10003a8d(param_1 + 1);
  FUN_10004674(param_1 + 1);
  return;
}



// Function: FUN_100046d2 at 100046d2

undefined4 FUN_100046d2(void)

{
  return 0x80004001;
}



// Function: FUN_100046da at 100046da

undefined4 FUN_100046da(void)

{
  return 1;
}



// Function: FUN_100046e0 at 100046e0

undefined4 FUN_100046e0(void)

{
  return 0;
}



// Function: FUN_100046e5 at 100046e5

undefined4 * __thiscall FUN_100046e5(void *this,byte param_1)

{
  FUN_1000469e((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004704 at 10004704

undefined4 __fastcall FUN_10004704(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_10003087((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
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



// Function: FUN_10004745 at 10004745

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10004745(void *this,LPCWSTR param_1,int *param_2)

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
  local_8 = 0x10004751;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    iVar3 = lstrlenW(param_1);
    FUN_10002af4(&local_70,iVar3 * 2);
    local_8 = 0;
    if (local_68 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      CoTaskMemFree((LPVOID)0x0);
    }
    else {
      *(LPCWSTR *)this = param_1;
      local_5d = '\0';
      local_5c = FUN_10002f2e(&local_5d);
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
LAB_1000483a:
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x27) {
                if (local_55 == '\0') {
                  local_55 = '\x01';
                  goto LAB_100048ae;
                }
                iVar3 = FUN_10002ad4((undefined4 *)this);
                if (iVar3 == 0) {
                    /* WARNING: Load size is inaccurate */
                  pWVar5 = CharNextW(*this);
                  *(LPWSTR *)this = pWVar5;
                  iVar3 = FUN_10002b34(&local_70,pWVar5,1);
                  if (iVar3 == 0) goto LAB_100048d4;
                  goto LAB_10004876;
                }
                local_55 = '\0';
              }
              else {
LAB_10004876:
                if (local_55 != '\0') goto LAB_100048ae;
              }
                    /* WARNING: Load size is inaccurate */
              if (**this == 0x7b) {
                local_64 = local_64 + 1;
              }
              if (((**this == 0x7d) && (local_64 = local_64 + -1, local_64 == 0)) &&
                 (local_56 == '\x01')) {
                iVar3 = FUN_10003ae4(&local_70,L"\r\n\t}\r\n}\r\n");
                if (iVar3 == 0) goto LAB_100048d4;
                local_56 = '\0';
              }
              goto LAB_100048ae;
            }
            pWVar5 = CharNextW(*this);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            pWVar5 = CharNextW(pWVar5);
            *(LPWSTR *)this = pWVar5;
            iVar3 = FUN_10003ae4(&local_70,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar3 != 0) {
              local_56 = '\x01';
              goto LAB_1000483a;
            }
LAB_100048d4:
            local_5c = -0x7ff8fff2;
            goto LAB_100047b5;
          }
LAB_100048ae:
                    /* WARNING: Load size is inaccurate */
          pWVar6 = *this;
          if (*pWVar6 == L'%') {
            pWVar5 = CharNextW(pWVar6);
            *(LPWSTR *)this = pWVar5;
            if (*pWVar5 != L'%') {
              pWVar6 = FUN_10002cce(pWVar5,L'%');
              if (pWVar6 != (LPCWSTR)0x0) {
                    /* WARNING: Load size is inaccurate */
                _MaxCount = (int)pWVar6 - (int)*this >> 1;
                if (0x1f < (int)_MaxCount) {
                  local_5c = -0x7fffbffb;
                  goto LAB_100047b5;
                }
                eVar7 = wcsncpy_s(local_54,0x20,*this,_MaxCount);
                ATL::AtlCrtErrorCheck(eVar7);
                pWVar8 = (LPCWSTR)FUN_10004704(*(int *)((int)this + 4));
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar3 = FUN_10003ae4(&local_70,pWVar8);
                  if (iVar3 == 0) goto LAB_100048d4;
                    /* WARNING: Load size is inaccurate */
                  pWVar8 = *this;
                  while (pWVar8 != pWVar6) {
                    /* WARNING: Load size is inaccurate */
                    pWVar8 = CharNextW(*this);
                    *(LPCWSTR *)this = pWVar8;
                  }
                  goto LAB_10004947;
                }
              }
              local_5c = -0x7ffdfff7;
              goto LAB_100047b5;
            }
            iVar3 = FUN_10002b34(&local_70,pWVar5,1);
            if (iVar3 == 0) goto LAB_100048d4;
          }
          else {
            iVar3 = FUN_10002b34(&local_70,pWVar6,1);
            if (iVar3 == 0) {
              local_5c = -0x7ff8fff2;
              break;
            }
          }
LAB_10004947:
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
LAB_100047b5:
      local_8 = 0xffffffff;
      CoTaskMemFree(local_68);
    }
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_100049b2 at 100049b2

undefined4 __fastcall FUN_100049b2(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100049b5 at 100049b5

undefined4 FUN_100049b5(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10002f4d(&DAT_10013d3c,(int *)&PTR_DAT_10013038,param_1,(undefined4 *)&DAT_1000e444);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10003d44(0x10013d3c);
  }
  return 1;
}



// Function: ~basic_string<> at 100049f7

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



// Function: FUN_10004a01 at 10004a01

undefined4 * __thiscall FUN_10004a01(void *this,uint param_1,uint param_2)

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



// Function: FUN_10004a82 at 10004a82

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10004a82(GUID *param_1,int *param_2,int param_3)

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
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_1000ee40), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_1000ee60,(LPUNKNOWN)0x0,1,(IID *)&DAT_1000eb0c,&local_1a8
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
          goto LAB_10004d0d;
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
      FUN_10003009(&local_1cc);
    }
  }
  local_8 = 0xffffffff;
  if (local_1a8 != (int *)0x0) {
    (**(code **)(*local_1a8 + 8))(local_1a8);
  }
LAB_10004d0d:
  FUN_1000b1dd();
  return;
}



// Function: FUN_10004da0 at 10004da0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_10004da0(HMODULE param_1,LPCWSTR param_2)

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
  iVar1 = FUN_10003b3d(param_1,param_2,&local_18,local_14);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1), -1 < iVar1)
     ) {
    param_2 = (LPCWSTR)((uint)param_2 & 0xffffff);
    iVar1 = FUN_10002f2e((undefined1 *)((int)&param_2 + 3));
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



// Function: FUN_10004e70 at 10004e70

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10004e70(HMODULE param_1,LPCWSTR param_2)

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
  iVar2 = FUN_10003b3d(param_1,param_2,&local_22c,&local_228);
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
    iVar2 = FUN_10002f2e(&local_21d);
    if (iVar2 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_228 != (int *)0x0) {
        (**(code **)(*local_228 + 8))(local_228);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10005032;
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
LAB_10005032:
  FUN_1000b1dd();
  return;
}



// Function: FUN_1000503a at 1000503a

int FUN_1000503a(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_100025ee(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar7 = 1;
          iVar4 = (*(code *)puVar1[1])();
          if (iVar4 < 0) {
            return iVar4;
          }
          piVar5 = (int *)(*(code *)puVar1[7])(1);
          param_1 = FUN_10004a82((GUID *)*puVar1,piVar5,iVar7);
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
      param_1 = FUN_10004e70(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_100050c0 at 100050c0

int FUN_100050c0(int param_1,int param_2,void *param_3)

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
            (bVar3 = FUN_100025ee(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar3) != 0)))) {
          iVar6 = 0;
          piVar4 = (int *)(*(code *)puVar1[7])();
          iVar6 = FUN_10004a82((GUID *)*puVar1,piVar4,iVar6);
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
      param_1 = FUN_10004da0(*(HMODULE *)(iVar2 + 4),(LPCWSTR)0x0);
    }
  }
  return param_1;
}



// Function: FUN_10005147 at 10005147

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_10005147(int *param_1,int *param_2,undefined4 param_3,int *param_4)

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
              param_1 = (int *)(*(code *)puVar1[2])(puVar1[3],&DAT_1000e9c0,piVar3);
            }
            LeaveCriticalSection(lpCriticalSection);
            if (*piVar3 != 0) goto LAB_10005202;
          }
          else {
LAB_10005202:
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



// Function: FUN_10005232 at 10005232

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005232(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  operator_new(0xc);
  uVar1 = FUN_10005277();
  return uVar1;
}



// Function: Catch@10005267 at 10005267

undefined * Catch_10005267(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10005271;
}



// Function: FUN_10005277 at 10005277

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005277(void)

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



// Function: FUN_100052d2 at 100052d2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_100052d2(void *this,undefined4 *param_1)

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
  (**(code **)*param_1)(param_1,&DAT_1000e994,local_14);
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x20))(param_1);
  piVar1 = local_14[0];
  ppuVar2 = FUN_1000a1aa();
  if (ppuVar2 == (undefined4 **)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = (undefined4 *)Ordinal_2(ppuVar2);
    if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_100026b4(0x8007000e);
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



// Function: FUN_10005363 at 10005363

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005363(undefined4 *param_1)

{
  *param_1 = ATL::CComClassFactory::vftable;
  FUN_1000305d((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



// Function: FUN_10005394 at 10005394

undefined4 FUN_10005394(int param_1,int param_2,_GUID *param_3,undefined4 *param_4)

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



// Function: FUN_100053d2 at 100053d2

undefined4 FUN_100053d2(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10013c78 + 8))();
  }
  else {
    (**(code **)(*DAT_10013c78 + 4))();
  }
  return 0;
}



// Function: FUN_100053f1 at 100053f1

undefined4 * __thiscall FUN_100053f1(void *this,byte param_1)

{
  FUN_10005363((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005410 at 10005410

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005410(int param_1)

{
  FID_conflict__Tidy((void *)(param_1 + 4),'\x01',0);
  return;
}



// Function: FUN_10005435 at 10005435

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005435(void *param_1)

{
  Ordinal_9((int)param_1 + 0x20);
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10005469 at 10005469

undefined4 __thiscall FUN_10005469(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10004034(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



// Function: Allocate at 100054c0

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
    FUN_100030c8(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 100054ef

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
    FUN_100030c8(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: Allocate at 1000551e

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
    FUN_100030c8(this,uVar1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000554d at 1000554d

IUnknown * __thiscall FUN_1000554d(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_1000409f(this,(undefined4 *)*param_1);
  if (bVar1) {
                    /* WARNING: Load size is inaccurate */
    pIVar2 = *this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign((IUnknown **)this,(IUnknown *)*param_1,(_GUID *)&DAT_1000eb88);
  }
  return pIVar2;
}



// Function: FUN_1000557a at 1000557a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000557a(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int iVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    this = operator_new(0x80);
    if (this != (void *)0x0) {
      FUN_100041ff(this,param_1);
    }
    iVar1 = FUN_100055eb();
    return iVar1;
  }
  return -0x7fffbffd;
}



// Function: Catch@100055db at 100055db

undefined * Catch_100055db(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100055e5;
}



// Function: FUN_100055eb at 100055eb

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_100055eb(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_EDI = FUN_10002ff4((int)(unaff_ESI + 0xe));
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



// Function: FUN_1000562d at 1000562d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_1000562d(undefined4 *param_1)

{
  param_1[1] = 0;
  FUN_10003112(param_1 + 2);
  *param_1 = ATL::CComClassFactory::vftable;
  return param_1;
}



// Function: FUN_10005668 at 10005668

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005668(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_1000568a at 1000568a

undefined4 * __thiscall FUN_1000568a(void *this,uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)puVar2[1] + 0x2d) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if ((uint)puVar2[3] < *param_1) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  return puVar2;
}



// Function: FUN_100056b6 at 100056b6

int __fastcall FUN_100056b6(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_1000358a((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x40) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x41) = 1;
  return param_1;
}



// Function: FUN_100056ed at 100056ed

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall FUN_100056ed(void *this,uint param_1)

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
  FUN_100035e9((char *)(param_1 + 1));
  FUN_10005782();
  return;
}



// Function: Catch@10005754 at 10005754

undefined * Catch_10005754(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_100035e9((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000577c;
}



// Function: FUN_10005782 at 10005782

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10005782(void)

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



// Function: Catch@100057d0 at 100057d0

void Catch_100057d0(void)

{
  int unaff_EBP;
  
  FID_conflict__Tidy(*(void **)(unaff_EBP + -0x1c),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100057e5 at 100057e5

void __thiscall FUN_100057e5(void *this,ushort *param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 10)) {
    param_1 = *(ushort **)param_1;
  }
  FUN_1000441d(this,0,*(uint *)((int)this + 0x10),param_1,*puVar1);
  return;
}



// Function: FUN_10005806 at 10005806

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10005806(undefined4 *param_1)

{
  *param_1 = CComErrorHandlerException::vftable;
  FID_conflict__Tidy(param_1 + 4,'\x01',0);
  return;
}



// Function: FUN_10005831 at 10005831

undefined4 * __thiscall FUN_10005831(void *this,byte param_1)

{
  FUN_10005806((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10005850 at 10005850

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10005850(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    iVar2 = lstrlenW(param_1);
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    operator_new__(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_100058b6();
    return uVar3;
  }
  return 0;
}



// Function: Catch@100058aa at 100058aa

undefined * Catch_100058aa(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100058b4;
}



// Function: FUN_100058b6 at 100058b6

void FUN_100058b6(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  void *pvVar4;
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
  pvVar4 = operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
  *(void **)(unaff_EBP + -0x20) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10005907();
  return;
}



// Function: Catch@100058f8 at 100058f8

undefined * Catch_100058f8(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return &DAT_10005905;
}



// Function: FUN_10005907 at 10005907

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_10005907(void)

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
    FUN_10002704(*(void **)(unaff_EBP + -0x14),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x28));
    FUN_10002704(pvVar1,*(rsize_t *)(unaff_EBP + -0x2c),*(void **)(unaff_EBP + 0xc),
                 *(rsize_t *)(unaff_EBP + -0x2c));
    iVar2 = FUN_10005469(*(void **)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x14),
                         (undefined4 *)(unaff_EBP + -0x20));
    if (iVar2 != 0) {
      *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
      *(void **)(unaff_EBP + -0x18) = unaff_ESI;
      goto LAB_10005963;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0x8007000e;
LAB_10005963:
  iVar2 = *(int *)(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  *(void **)(unaff_EBP + -0x18) = unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  *(void **)(unaff_EBP + -0x1c) = unaff_ESI;
  return (int)unaff_ESI <= iVar2;
}



// Function: FUN_1000599b at 1000599b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_1000599b(undefined4 param_1,LPCWSTR param_2,int param_3)

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
    iVar1 = FUN_10005850(param_2,param_3);
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_10003009(local_14);
  }
  return iVar1;
}



// Function: FUN_100059f6 at 100059f6

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100059f6(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

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
  puStack_c = &LAB_1000c409;
  local_10 = ExceptionList;
  uStack_2144 = DAT_10013c58 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2144;
  ExceptionList = &local_10;
  local_2124 = param_1;
  local_2128 = param_2;
  local_2120 = (wchar_t *)0x0;
  local_18 = uStack_2144;
  iVar1 = FUN_10002d43(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_10002bc2(local_2018,(undefined2 *)&local_2120), iVar1 == 0))
  goto LAB_10005d6f;
  FUN_10002d21((undefined4 *)this);
  iVar1 = FUN_10002d43(this,local_2018);
  if (iVar1 < 0) goto LAB_10005d6f;
  uVar2 = (uint)local_2120 & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_10005d4b:
    if (uVar2 != 0) {
      FUN_10002791(uVar2);
      goto LAB_10005d6f;
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
        FUN_10005c7e();
        return;
      }
      goto LAB_10005d6f;
    }
    if (uVar2 == 0x13) {
      local_2124 = (CRegKey *)0x0;
      local_8 = 3;
      Ordinal_277(local_2018,0,0,&local_2128);
      local_2120 = local_2128;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&local_2120,4);
      local_8 = 0xffffffff;
      FUN_10003009((int *)&local_2124);
      goto LAB_10005d4b;
    }
    if (uVar2 == 0x4008) {
      iVar1 = lstrlenW(local_2018);
      local_211c[0] = 0;
      local_8 = 1;
      Allocate(local_211c,iVar1 + 2);
      local_8 = 0;
      FUN_10005b17();
      return;
    }
  }
  FUN_10002d43(this,param_3);
LAB_10005d6f:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10005b0b at 10005b0b

undefined * Catch_10005b0b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10005b15;
}



// Function: FUN_10005b17 at 10005b17

void FUN_10005b17(void)

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
    pWVar2 = (WCHAR *)FUN_10002a91(*(void **)(unaff_EBP - 0x2120),*(LPCWSTR *)(unaff_EBP - 0x2124),
                                   *(LPCWSTR *)(unaff_EBP - 0x2118));
    unaff_EDI = (WCHAR *)0x0;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
    FUN_100030be((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (pWVar2 == unaff_EDI) {
    FUN_10002d43(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
  }
  else {
    FUN_10002791((uint)pWVar2);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10005d87;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10005c63 at 10005c63

undefined * Catch_10005c63(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return &DAT_10005c70;
}



// Function: FUN_10005c7e at 10005c7e

void FUN_10005c7e(void)

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
      FUN_100030be((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    memset(*(void **)(unaff_EBP - 0x2118),unaff_EDI,unaff_EBX);
    if ((int)unaff_EDI < *(int *)(unaff_EBP - 0x211c)) {
      do {
        pbVar1 = (byte *)((int)unaff_EDI / 2 + *(int *)(unaff_EBP - 0x2118));
        iVar2 = FUN_10002c6a(*(ushort *)((unaff_EBP - 0x2014) + unaff_EDI * 2));
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
      FUN_100030be((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar3 == unaff_EDI) {
      FUN_10002d43(*(void **)(unaff_EBP - 0x2128),*(undefined2 **)(unaff_EBP - 0x212c));
    }
    else {
      FUN_10002791(uVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10005d87;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10005d8b at 10005d8b

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10005d8b(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

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
  puStack_c = &LAB_1000c468;
  local_10 = ExceptionList;
  local_14 = DAT_10013c58 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2228 = param_2;
  local_2234 = (HKEY)0x0;
  local_2230 = 0;
  local_222c = 0;
  local_8 = 0;
  local_2220 = this;
LAB_10005def:
  iVar3 = FUN_10002d43(local_2220,param_1);
  do {
    if (iVar3 < 0) {
LAB_10005dff:
      local_8 = 0xffffffff;
      ATL::CRegKey::Close((CRegKey *)&local_2234);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_1000625c:
    if (*param_1 == L'}') goto LAB_10005dff;
    local_2238 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2224 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_10002d43(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10005dff;
      if (param_3 == 0) goto LAB_10005f3e;
      local_2244 = (HKEY)0x0;
      local_2240 = 0;
      local_223c = 0;
      local_8._0_1_ = 1;
      pWVar5 = FUN_10002cce(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_10002e59(param_1);
        if (iVar3 != 0) {
          local_2244 = local_2228;
          local_2240 = 0;
          local_223c = 0;
          FUN_100039a8(&local_2244,param_1);
          local_2244 = (HKEY)0x0;
          local_2240 = 0;
          local_223c = 0;
        }
        if (local_2224 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          ATL::CRegKey::Close((CRegKey *)&local_2244);
          goto LAB_10005f3e;
        }
        iVar3 = FUN_10002d43(local_2220,param_1);
        if ((-1 < iVar3) && (iVar3 = FUN_10002ebd(local_2220,param_1), -1 < iVar3)) {
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2244;
          goto LAB_1000635b;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2244;
        goto LAB_100063da;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2244);
      goto LAB_10005dff;
    }
LAB_10005f3e:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2238 = 0;
      iVar3 = FUN_10002d43(local_2220,param_1);
      if (iVar3 < 0) goto LAB_10005dff;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_10002cce(param_1,L'\\');
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
          iVar3 = FUN_10002d43(local_2220,param_1);
          if (((-1 < iVar3) && (iVar3 = FUN_10002ebd(local_2220,param_1), -1 < iVar3)) &&
             (((*param_1 != L'{' || (iVar3 = lstrlenW(param_1), iVar3 != 1)) ||
              (((iVar3 = FUN_10005d8b(local_2220,param_1,local_2234,0,param_4), -1 < iVar3 ||
                (param_4 != 0)) && (iVar3 = FUN_10002d43(local_2220,param_1), -1 < iVar3))))))
          break;
        }
        else {
          iVar3 = Open(&local_2234,local_2228,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2234,local_2228,param_1,0x20019), iVar3 != 0))
             && (uVar6 = Create(&local_2234,local_2228,param_1,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_100063f9;
          iVar3 = FUN_10002d43(local_2220,param_1);
          if ((-1 < iVar3) &&
             ((*param_1 != L'=' ||
              (iVar3 = FUN_100059f6(local_2220,(CRegKey *)&local_2234,(wchar_t *)0x0,param_1),
              -1 < iVar3)))) goto LAB_10006360;
        }
      }
      goto LAB_10005dff;
    }
    iVar3 = FUN_10002d43(local_2220,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_10002d43(local_2220,param_1), iVar3 < 0)) || (*param_1 != L'=')
       ) goto LAB_10005dff;
    if (param_3 != 0) {
      local_8._0_1_ = 2;
      local_225c = local_2228;
      local_2258 = 0;
      local_2254 = 0;
      iVar3 = FUN_100059f6(local_2220,(CRegKey *)&local_225c,local_221c,param_1);
      local_225c = (HKEY)0x0;
      local_2258 = 0;
      local_2254 = 0;
      if (-1 < iVar3) {
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_225c;
        goto LAB_1000635b;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      pCVar8 = (CRegKey *)&local_225c;
      goto LAB_100063da;
    }
    if ((iVar1 == 0) && (local_2238 != 0)) {
      local_2268 = (HKEY)0x0;
      local_2264 = 0;
      local_2260 = 0;
      local_8._0_1_ = 3;
      uVar6 = Open(&local_2268,local_2228,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2268,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_10002791(uVar6);
        local_8 = (uint)local_8._1_3_ << 8;
        pCVar8 = (CRegKey *)&local_2268;
LAB_100063da:
        ATL::CRegKey::Close(pCVar8);
        goto LAB_10005dff;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      ATL::CRegKey::Close((CRegKey *)&local_2268);
    }
    iVar3 = FUN_10002ebd(local_2220,param_1);
  } while( true );
  if (local_2224 != 2) {
    if (local_2224 == 0) {
      if ((iVar1 != 0) && (bVar2 = FUN_10002e88(local_2234), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_10002e59(local_21c);
        if ((iVar3 != 0) && (local_2238 != 0)) {
          FUN_100039a8(&local_2234,local_21c);
        }
        goto LAB_1000625c;
      }
      bVar2 = FUN_10002e88(local_2234);
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
            FUN_10002791(uVar6);
            local_8 = (uint)local_8._1_3_ << 8;
            pCVar8 = (CRegKey *)&local_2250;
            goto LAB_100063da;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          pCVar8 = (CRegKey *)&local_2250;
LAB_1000635b:
          ATL::CRegKey::Close(pCVar8);
LAB_10006360:
          if (((param_3 != 0) && (*param_1 == L'{')) && (iVar3 = lstrlenW(param_1), iVar3 == 1)) {
            iVar3 = FUN_10005d8b(local_2220,param_1,local_2234,param_3,0);
            if (-1 < iVar3) goto LAB_10005def;
            goto LAB_10005dff;
          }
        }
        goto LAB_1000625c;
      }
    }
    else {
      uVar6 = local_2224;
      if (iVar1 != 0) goto LAB_1000625c;
    }
LAB_100063f9:
    FUN_10002791(uVar6);
    goto LAB_10005dff;
  }
  goto LAB_1000625c;
}



// Function: FUN_10006422 at 10006422

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_10006422(void *this,int *param_1,undefined4 param_2,int *param_3)

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
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10013e0c);
          local_14 = (int *)0x0;
          if (*piVar2 == 0) {
            local_14 = (int *)(*(code *)puVar3[2])(puVar3[3],&DAT_1000e9c0,piVar2);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10013e0c);
          if (*piVar2 != 0) goto LAB_100064b6;
        }
        else {
LAB_100064b6:
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
  piVar2 = FUN_10005147((int *)&DAT_10013dfc,param_1,param_2,param_3);
  return piVar2;
}



// Function: FUN_100064ee at 100064ee

void FUN_100064ee(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10004134(0,param_2,param_3);
    return;
  }
  FUN_1000557a(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000650e at 1000650e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000650e(int param_1)

{
  FID_conflict__Tidy((void *)(param_1 + 4),'\x01',0);
  return;
}



// Function: FUN_10006533 at 10006533

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_10006533(void *param_1)

{
  FUN_10005435(param_1);
  return;
}



// Function: FUN_10006551 at 10006551

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10006551(void *this,undefined4 param_1)

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
  local_8 = 0x10006560;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10006796;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_10013c78 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_220 = -0x7fffbffb;
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_230 = (int *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_10013c7c,piVar1);
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      local_220 = Ordinal_162(piVar1,*(undefined2 *)((int)this + 8),*(undefined2 *)((int)this + 10),
                              param_1,&local_230);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_10013e28,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10006760;
      local_224 = (int *)0x0;
      local_8._0_1_ = 1;
      local_220 = Ordinal_161(local_21c,&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10003009((int *)&local_224);
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
        iVar2 = (**(code **)*local_228)(local_228,&DAT_1000e888,&local_224);
        if (-1 < iVar2) {
          FUN_1000554d(&local_22c,&local_224);
        }
        *(int **)((int)this + 0xc) = local_22c;
        local_22c = (int *)0x0;
        if (DAT_10013c78 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_10013c78 + 4;
        }
        pcVar4 = FUN_10003f75;
        pvVar5 = this;
        FUN_10005232(iVar2);
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
LAB_10006760:
  if ((*(wchar_t **)((int)this + 0xc) != (wchar_t *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    local_220 = FUN_10003e0d(this,*(wchar_t **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10006796:
  FUN_1000b1dd();
  return;
}



// Function: FUN_1000679e at 1000679e

void FUN_1000679e(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000503a(0x10013dfc,param_1,param_2);
  if ((-1 < iVar1) && (DAT_10013c6c != (code *)0x0)) {
    (*DAT_10013c6c)(DAT_10013e28);
  }
  return;
}



// Function: FUN_100067cc at 100067cc

void FUN_100067cc(int param_1,void *param_2)

{
  int iVar1;
  
  if ((DAT_10013c70 != (code *)0x0) && (iVar1 = (*DAT_10013c70)(), iVar1 < 0)) {
    return;
  }
  FUN_100050c0(0x10013dfc,param_1,param_2);
  return;
}



// Function: FUN_100067f2 at 100067f2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_100067f2(undefined4 *param_1)

{
  FUN_1000562d(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  return param_1;
}



// Function: FUN_10006820 at 10006820

LONG FUN_10006820(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10013c78 + 4))();
  }
  return LVar1;
}



// Function: FUN_1000684a at 1000684a

LONG FUN_1000684a(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (LVar1 == 1) {
    (**(code **)(*DAT_10013c78 + 8))();
  }
  return LVar1;
}



// Function: QueryInterface at 10006889

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000ebbc,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_100068a3 at 100068a3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100068a3(undefined4 *param_1)

{
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  param_1[1] = 0xc0000001;
  FUN_10005363(param_1);
  return;
}



// Function: FUN_100068d2 at 100068d2

undefined4 * __thiscall FUN_100068d2(void *this,byte param_1)

{
  FUN_100068a3((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100068f1 at 100068f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100068f1(void *param_1)

{
  FID_conflict__Tidy(param_1,'\x01',0);
  return;
}



// Function: FUN_10006913 at 10006913

bool __thiscall FUN_10006913(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 *extraout_ECX;
  
  if (0x7ffffffe < param_1) {
    std::_Xlength_error("string too long");
    this = extraout_ECX;
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_100056ed(this,param_1);
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



// Function: FUN_1000697d at 1000697d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_1000697d(void *this,byte param_1)

{
  FID_conflict__Tidy(this,'\x01',0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100069b2 at 100069b2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100069b2(void *this,byte param_1)

{
  FID_conflict__Tidy((void *)((int)this + 4),'\x01',0);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_100069ea at 100069ea

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100069ea(void *this,LPCWSTR param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  HKEY pHVar4;
  short *local_200c;
  WCHAR local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_10013c58 ^ (uint)&stack0xfffffffc;
  local_200c = (short *)0x0;
  iVar3 = FUN_10004745(this,param_1,(int *)&local_200c);
  if (iVar3 < 0) {
LAB_10006ae0:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(short **)this = local_200c;
  sVar1 = *local_200c;
joined_r0x10006a35:
  if ((((sVar1 == 0) || (iVar3 = FUN_10002d43(this,local_2008), iVar3 < 0)) ||
      (pHVar4 = (HKEY)FUN_10002ca0(local_2008), pHVar4 == (HKEY)0x0)) ||
     ((iVar3 = FUN_10002d43(this,local_2008), iVar3 < 0 || (local_2008[0] != L'{'))))
  goto LAB_10006ad2;
  if (param_2 == 0) {
    iVar3 = FUN_10005d8b(this,local_2008,pHVar4,0,0);
    if (iVar3 < 0) goto LAB_10006ad2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar2 = *this;
    iVar3 = FUN_10005d8b(this,local_2008,pHVar4,param_2,0);
    if (iVar3 < 0) {
      *(undefined4 *)this = uVar2;
      FUN_10005d8b(this,local_2008,pHVar4,0,0);
LAB_10006ad2:
      CoTaskMemFree(local_200c);
      goto LAB_10006ae0;
    }
  }
  FUN_10002d21((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  sVar1 = **this;
  goto joined_r0x10006a35;
}



// Function: DllGetClassObject at 10006b21

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int *piVar1;
  
                    /* 0x6b21  2  DllGetClassObject */
  piVar1 = FUN_10006422(&DAT_10013d3c,(int *)rclsid,riid,(int *)ppv);
  return (HRESULT)piVar1;
}



// Function: FUN_10006b2f at 10006b2f

int __thiscall FUN_10006b2f(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_100025ee(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar6 = 1;
        iVar5 = (*(code *)piVar4[1])();
        if (iVar5 < 0) {
          return iVar5;
        }
        piVar3 = (int *)(*(code *)piVar4[7])(1);
        iVar5 = FUN_10004a82((GUID *)*piVar4,piVar3,iVar6);
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
  iVar5 = FUN_1000679e(param_1,param_2);
  return iVar5;
}



// Function: FUN_10006b9e at 10006b9e

int __thiscall FUN_10006b9e(void *this,int param_1,void *param_2)

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
         (bVar1 = FUN_100025ee(param_2,pvVar2), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar5 = 0;
        piVar3 = (int *)(*(code *)piVar4[7])();
        iVar5 = FUN_10004a82((GUID *)*piVar4,piVar3,iVar5);
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
  iVar5 = FUN_100067cc(param_1,param_2);
  return iVar5;
}



// Function: FUN_10006c0d at 10006c0d

void __thiscall FUN_10006c0d(void *this,undefined4 *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint **ppuVar3;
  uint *local_8;
  
  puVar1 = param_2;
  local_8 = (uint *)this;
  puVar2 = FUN_1000568a(this,param_2);
  if ((puVar2 == *(uint **)((int)this + 4)) || (*puVar1 < puVar2[3])) {
    local_8 = *(uint **)((int)this + 4);
    ppuVar3 = &local_8;
  }
  else {
    ppuVar3 = &param_2;
  }
  *param_1 = *ppuVar3;
  return;
}



// Function: Catch@10006ca5 at 10006ca5

undefined1 * Catch_10006ca5(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &LAB_10006caf;
}



// Function: FUN_10006cf7 at 10006cf7

undefined4 __thiscall FUN_10006cf7(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar1 = FUN_10006551(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(int **)((int)this + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function: FUN_10006d37 at 10006d37

undefined4 __thiscall
FUN_10006d37(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_10006551(this,param_4);
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



// Function: FUN_10006dd8 at 10006dd8

void __thiscall
FUN_10006dd8(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10006551(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
              (*(int **)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10006e1b at 10006e1b

undefined4 * __thiscall FUN_10006e1b(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
    FUN_10004a01(pvVar3,uVar4 + uVar2,0xffffffff);
    FUN_10004a01(this,0,param_2);
  }
  else {
    bVar1 = FUN_10006913(pvVar3,uVar4,'\0');
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



// Function: FID_conflict:assign at 10006eb7

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
    bVar1 = FUN_10006913(this,param_2,'\0');
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
    this = FUN_10006e1b(this,(undefined4 *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10006f35 at 10006f35

undefined4 * __thiscall FUN_10006f35(void *this,ushort *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x41) == '\0') {
    iVar2 = FUN_100057e5(puVar3 + 4,param_1);
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



// Function: FUN_10006f6a at 10006f6a

undefined4 * __thiscall FUN_10006f6a(void *this,ushort *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  puVar4 = *(undefined4 **)((int)this + 4);
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0x2d) == '\0') {
    iVar2 = FUN_100057e5(puVar3 + 3,param_1);
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



// Function: FUN_10006f9f at 10006f9f

undefined4 * __fastcall FUN_10006f9f(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = ATL::
             CComObject<class_CComEventPublisher<class_CThreadServiceImpl>::CPublisherEventsImpl>::
             vftable;
  (**(code **)(*DAT_10013c78 + 4))();
  return param_1;
}



// Function: FUN_10006fbd at 10006fbd

undefined4 FUN_10006fbd(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_10006fda at 10006fda

undefined4 FUN_10006fda(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: Release at 10006fea

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



// Function: FUN_1000700b at 1000700b

undefined4 FUN_1000700b(undefined4 param_1,int *param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  int iVar4;
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    iVar4 = 0;
    ppuVar3 = FUN_10009f20();
    puVar1 = *ppuVar3;
    while (puVar1 != (undefined *)0x0) {
      iVar4 = iVar4 + 1;
      ppuVar3 = FUN_10009f20();
      puVar1 = ppuVar3[iVar4];
    }
    *param_2 = iVar4;
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_1000703f at 1000703f

void __fastcall FUN_1000703f(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_CComEventPublisher<class_CThreadServiceImpl>::CPublisherEventsImpl>::
             vftable;
  param_1[1] = 0xc0000001;
                    /* WARNING: Could not recover jumptable at 0x10007054. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_10013c78 + 8))();
  return;
}



// Function: FUN_10007057 at 10007057

undefined4 * __thiscall FUN_10007057(void *this,byte param_1)

{
  FUN_1000703f((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: QueryInterface at 10007076

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000ec10,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_10007090 at 10007090

undefined4 * __fastcall FUN_10007090(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = ATL::
             CComObject<class_CComEventPublisher<class_CThreadServiceImpl>::CPublisherEventImpl>::
             vftable;
  (**(code **)(*DAT_10013c78 + 4))();
  return param_1;
}



// Function: Release at 100070b2

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



// Function: FUN_100070d3 at 100070d3

void __fastcall FUN_100070d3(undefined4 *param_1)

{
  *param_1 = ATL::
             CComObject<class_CComEventPublisher<class_CThreadServiceImpl>::CPublisherEventImpl>::
             vftable;
  param_1[1] = 0xc0000001;
                    /* WARNING: Could not recover jumptable at 0x100070e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_10013c78 + 8))();
  return;
}



// Function: FUN_100070eb at 100070eb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_100070eb(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uStack_28;
  undefined *puStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x100070f7;
  puVar5 = (undefined4 *)auStack_20;
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puStack_24 = (undefined *)0x1000710a;
    ppuVar2 = FUN_10009f20();
    if (ppuVar2[*(int *)(param_1 + 8)] == (undefined *)0x0) {
      iVar3 = 0;
    }
    else {
      puVar5 = &uStack_28;
      uStack_28 = 0x10007141;
      puStack_24 = ppuVar2[*(int *)(param_1 + 8)];
      iVar3 = Ordinal_2();
      if (iVar3 == 0) {
        puVar5[-1] = 0x8007000e;
                    /* WARNING: Subroutine does not return */
        puVar5[-2] = &UNK_10007152;
        FUN_100026b4(puVar5[-1]);
      }
    }
    *param_2 = iVar3;
    local_8 = 0xffffffff;
    *(undefined4 *)((int)puVar5 + -4) = 0;
    puVar4 = (undefined4 *)((int)puVar5 + -8);
    puVar5 = (undefined4 *)((int)puVar5 + -8);
    *puVar4 = 0x10007130;
    Ordinal_6();
    uVar1 = 0;
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x10007137;
  return uVar1;
}



// Function: FUN_10007153 at 10007153

undefined4 * __thiscall FUN_10007153(void *this,byte param_1)

{
  FUN_100070d3((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: QueryInterface at 10007172

/* Library Function - Single Match
    public: virtual long __stdcall CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct
   _GUID const &,void * *)
   
   Library: Visual Studio 2010 Release */

long CMFCComObject<class_ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = ATL::AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_1000ec68,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}



// Function: FUN_1000718c at 1000718c

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_1000718c(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

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
    FUN_1000277c();
  }
  else {
    hResInfo = FindResourceW(local_420,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (local_424 = LoadResource(local_420,hResInfo), local_424 == (HGLOBAL)0x0)) {
      FUN_1000277c();
    }
    else {
      local_428 = SizeofResource(local_420,hResInfo);
      if (local_428 <= local_428 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,local_428 + 1);
        local_8 = 1;
        FUN_10007266();
        return;
      }
    }
    FreeLibrary(local_420);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_41c != auStack_418) {
    FUN_100030be(&local_41c);
  }
  local_8 = 0xffffffff;
  FUN_10003009(&local_42c);
  FUN_1000b1ec();
  return;
}



// Function: Catch@10007251 at 10007251

undefined * Catch_10007251(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000725e;
}



// Function: FUN_10007266 at 10007266

void FUN_10007266(void)

{
  DWORD DVar1;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(DWORD *)(unaff_EBP + -0x418) != unaff_EBX) {
    DVar1 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (DVar1 == unaff_EBX) {
      FUN_1000277c();
    }
    else {
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + DVar1 * 2) = 0;
      FUN_100069ea((void *)(unaff_EBP + -0x430),*(LPCWSTR *)(unaff_EBP + -0x418),
                   *(int *)(unaff_EBP + 0x14));
    }
  }
  FreeLibrary(*(HMODULE *)(unaff_EBP + -0x41c));
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_100030be((undefined4 *)(unaff_EBP + -0x418));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10003009((int *)(unaff_EBP + -0x428));
  FUN_1000b1ec();
  return;
}



// Function: FUN_100072f0 at 100072f0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100072f0(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000718c(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10003009(local_14);
  return uVar1;
}



// Function: FUN_10007331 at 10007331

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007331(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10003009(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000718c(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10003009(local_14);
  }
  return uVar1;
}



// Function: FUN_1000738d at 1000738d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_1000738d(undefined4 param_1,LPCWSTR param_2,ushort param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  uVar1 = FUN_1000718c(param_2,(LPCWSTR)(uint)param_3,param_4);
  local_8 = 0xffffffff;
  FUN_10003009(local_14);
  return uVar1;
}



// Function: FUN_100073cd at 100073cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_100073cd(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

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
    FUN_10003009(local_14);
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_1000718c(param_2,param_3,param_4);
    local_8 = 0xffffffff;
    FUN_10003009(local_14);
  }
  return uVar1;
}



// Function: FUN_10007428 at 10007428

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10007428(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

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
      FUN_1000599b(&local_a60,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a60);
  pHVar1 = DAT_10013e28;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10013e28,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000277c();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10003009((int *)&local_a48);
        goto LAB_100074aa;
      }
      FUN_100028b3(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10002687(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10003009((int *)&local_a48);
          goto LAB_100074aa;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000599b(&local_a60,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000599b(&local_a60,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_100073cd(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
        else {
          FUN_10007331(&local_a60,local_21c,local_a4c,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10003009((int *)&local_a48);
  }
LAB_100074aa:
  local_8 = 0xffffffff;
  FUN_1000469e(&local_a60);
  FUN_1000b1dd();
  return;
}



// Function: DllRegisterServer at 1000762b

void DllRegisterServer(void)

{
                    /* 0x762b  3  DllRegisterServer */
  FUN_10006b2f(&DAT_10013d3c,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 1000763a

void DllUnregisterServer(void)

{
                    /* 0x763a  4  DllUnregisterServer */
  FUN_10006b9e(&DAT_10013d3c,1,(void *)0x0);
  return;
}



// Function: FUN_10007649 at 10007649

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_10007649(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

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
      FUN_1000599b(&local_a5c,(LPCWSTR)*param_4,param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a5c);
  pHVar1 = DAT_10013e28;
  if (-1 < iVar3) {
    local_a48 = (undefined4 *)0x0;
    local_8._0_1_ = 3;
    DVar4 = GetModuleFileNameW(DAT_10013e28,local_21c,0x104);
    if (DVar4 == 0) {
      FUN_1000277c();
    }
    else {
      if (DVar4 == 0x104) {
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_10003009((int *)&local_a48);
        goto LAB_100076c2;
      }
      FUN_100028b3(local_a44,0x208,local_21c);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_634 = L'\"';
        bVar2 = FUN_10002687(local_632,0x20b,local_a44);
        if (!bVar2) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_10003009((int *)&local_a48);
          goto LAB_100076c2;
        }
        iVar3 = lstrlenW(&local_634);
        local_632[iVar3 + -1] = 0x22;
        local_632[iVar3] = 0;
        pWVar6 = &local_634;
      }
      else {
        pWVar6 = local_a44;
      }
      iVar3 = FUN_1000599b(&local_a5c,L"Module",(int)pWVar6);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_1000599b(&local_a5c,L"Module_Raw",(int)local_a44), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_1000738d(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
        else {
          FUN_100072f0(&local_a5c,local_21c,param_2,L"REGISTRY");
        }
      }
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_10003009((int *)&local_a48);
  }
LAB_100076c2:
  local_8 = 0xffffffff;
  FUN_1000469e(&local_a5c);
  FUN_1000b1dd();
  return;
}



// Function: basic_string<> at 10007840

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
  FUN_10006e1b(this,param_1,0,0xffffffff);
  return (undefined2 *)this;
}



// Function: FUN_10007868 at 10007868

undefined4 FUN_10007868(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006cf7(&PTR_DAT_10013b98,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_1000788c at 1000788c

void FUN_1000788c(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006d37(&PTR_DAT_10013b98,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100078ac at 100078ac

void FUN_100078ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006dd8(&PTR_DAT_10013b98,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100078ba at 100078ba

undefined4 FUN_100078ba(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006cf7(&PTR_DAT_10013bb4,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100078de at 100078de

void FUN_100078de(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006d37(&PTR_DAT_10013bb4,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100078fe at 100078fe

void FUN_100078fe(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006dd8(&PTR_DAT_10013bb4,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000790c at 1000790c

undefined4 FUN_1000790c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006cf7(&PTR_DAT_10013bd0,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007930 at 10007930

void FUN_10007930(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006d37(&PTR_DAT_10013bd0,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007950 at 10007950

void FUN_10007950(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006dd8(&PTR_DAT_10013bd0,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_1000795e at 1000795e

undefined4 FUN_1000795e(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006cf7(&PTR_DAT_10013bec,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007982 at 10007982

void FUN_10007982(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006d37(&PTR_DAT_10013bec,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100079a2 at 100079a2

void FUN_100079a2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006dd8(&PTR_DAT_10013bec,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_100079b0 at 100079b0

undefined4 FUN_100079b0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006cf7(&PTR_DAT_10013c08,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100079d4 at 100079d4

void FUN_100079d4(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006d37(&PTR_DAT_10013c08,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100079f4 at 100079f4

void FUN_100079f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006dd8(&PTR_DAT_10013c08,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007a02 at 10007a02

undefined4 FUN_10007a02(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = FUN_10006cf7(&PTR_DAT_10013c24,param_3,param_4);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_10007a26 at 10007a26

void FUN_10007a26(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10006d37(&PTR_DAT_10013c24,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007a46 at 10007a46

void FUN_10007a46(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_10006dd8(&PTR_DAT_10013c24,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10007a54 at 10007a54

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10007a54(void *this,int *param_1)

{
  int *piVar1;
  undefined **ppuVar2;
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
  local_1c = (**(code **)*param_1)(param_1,&DAT_1000e994,&local_18);
  ppuVar2 = FUN_10009f20();
  if (*ppuVar2 != (undefined *)0x0) {
    iVar5 = 0;
    do {
      ppuVar2 = FUN_10009f20();
      piVar1 = local_18;
      if (*(int *)((int)ppuVar2 + iVar5) == 0) {
        local_14 = 0;
      }
      else {
        local_14 = Ordinal_2(*(int *)((int)ppuVar2 + iVar5));
        if (local_14 == 0) goto LAB_10007b5a;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      ppuVar3 = FUN_1000a1aa();
      if (ppuVar3 == (undefined4 **)0x0) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = (int *)Ordinal_2(ppuVar3);
        if (param_1 == (int *)0x0) {
LAB_10007b5a:
                    /* WARNING: Subroutine does not return */
          FUN_100026b4(0x8007000e);
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
      ppuVar2 = FUN_10009f20();
    } while (ppuVar2[iVar4] != (undefined *)0x0);
  }
  param_1 = (int *)**(int **)((int)this + 8);
  if (param_1 != *(int **)((int)this + 8)) {
    do {
      (**(code **)(*(int *)param_1[10] + 8))((int *)param_1[10]);
      FUN_100034ae((int *)&param_1);
    } while (param_1 != *(int **)((int)this + 8));
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return local_1c;
}



// Function: FUN_10007b65 at 10007b65

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007b65(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10006f9f(puVar1);
    }
    uVar2 = FUN_10007bc0();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10007bb1 at 10007bb1

undefined * Catch_10007bb1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007bbb;
}



// Function: FUN_10007bc0 at 10007bc0

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007bc0(void)

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



// Function: FUN_10007bd7 at 10007bd7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007bd7(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    puVar1 = (undefined4 *)operator_new(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10007090(puVar1);
    }
    uVar2 = FUN_10007c32();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10007c23 at 10007c23

undefined * Catch_10007c23(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007c2d;
}



// Function: FUN_10007c32 at 10007c32

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10007c32(void)

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



// Function: FUN_10007c49 at 10007c49

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10007c49(void *this,int param_1)

{
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  basic_string<>((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  return (undefined4 *)this;
}



// Function: FUN_10007c99 at 10007c99

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10007c99(void *this,undefined4 *param_1,undefined4 *param_2)

{
  basic_string<>(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  return this;
}



// Function: FUN_10007ccc at 10007ccc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10007ccc(void *this,undefined4 *param_1,tagVARIANT *param_2)

{
  basic_string<>(this,param_1);
  *(undefined2 *)((int)this + 0x20) = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)((int)this + 0x20),param_2);
  return this;
}



// Function: FUN_10007d07 at 10007d07

void FUN_10007d07(int *param_1,LPCWSTR param_2,int param_3,undefined4 *param_4)

{
  FUN_10007428(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007d10 at 10007d10

void FUN_10007d10(int *param_1,ushort param_2,int param_3,undefined4 *param_4)

{
  FUN_10007649(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10007d19 at 10007d19

void FUN_10007d19(int param_1)

{
  FUN_10007649((int *)&DAT_10013d3c,0x65,param_1,(undefined4 *)0x0);
  return;
}



// Function: FUN_10007d31 at 10007d31

undefined2 * __thiscall FUN_10007d31(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  sVar1 = wcslen(param_1);
  FID_conflict_assign(this,(undefined4 *)param_1,sVar1);
  return (undefined2 *)this;
}



// Function: FUN_10007d63 at 10007d63

undefined4 * __thiscall FUN_10007d63(void *this,undefined4 *param_1)

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



// Function: FUN_10007dc0 at 10007dc0

undefined4
FUN_10007dc0(int *param_1,ushort param_2,undefined4 param_3,int param_4,undefined4 param_5,
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
    FUN_10007bd7(&param_1);
    iVar1 = piVar2[2];
    param_1[2] = iVar4;
    param_1[3] = iVar1;
    uVar3 = (**(code **)*param_1)(param_1,&DAT_1000ec28,param_6);
  }
  return uVar3;
}



// Function: FUN_10007e2c at 10007e2c

void __cdecl FUN_10007e2c(undefined4 param_1,void *param_2)

{
  FUN_1000697d(param_2,0);
  return;
}



// Function: FUN_10007e3b at 10007e3b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __cdecl FUN_10007e3b(undefined4 param_1,void *param_2)

{
  FUN_10005435(param_2);
  return;
}



// Function: FUN_10007e59 at 10007e59

void __thiscall
FUN_10007e59(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
    FUN_10007e2c(this,param_4 + 3);
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
LAB_10007f28:
        *(undefined1 *)(piVar1 + 0xb) = 1;
        *(undefined1 *)(iVar4 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10004334(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        FUN_10004481(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x2c) == '\0') goto LAB_10007f28;
      if (piVar5 == (int *)*piVar1) {
        FUN_10004481(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      FUN_10004334(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_10007f91 at 10007f91

void __thiscall
FUN_10007f91(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint extraout_EAX;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0x5555553 < uVar3) {
    this = (void *)((int)this + 0xd);
    FUN_10007e3b(this,param_4 + 4);
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
    if (*(char *)(iVar4 + 0x40) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x40) = 1;
      *param_1 = param_4;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar2 = (int *)piVar1[1];
    if (piVar1 == (int *)*piVar2) {
      iVar4 = piVar2[2];
      if (*(char *)(iVar4 + 0x40) == '\0') {
LAB_10008060:
        *(undefined1 *)(piVar1 + 0x10) = 1;
        *(undefined1 *)(iVar4 + 0x40) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x40) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10004379(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x40) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x40) = 0;
        FUN_100043be(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x40) == '\0') goto LAB_10008060;
      if (piVar5 == (int *)*piVar1) {
        FUN_100043be(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x40) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x40) = 0;
      FUN_10004379(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_100080c9 at 100080c9

void __cdecl FUN_100080c9(undefined4 param_1,void *param_2)

{
  FUN_100069b2(param_2,0);
  return;
}



// Function: FUN_100080d8 at 100080d8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100080d8(void *this,undefined4 *param_1)

{
  FUN_10007c99(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_10008106 at 10008106

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008106(void *this,undefined4 *param_1)

{
  FUN_10007ccc(this,param_1,(tagVARIANT *)(param_1 + 8));
  return this;
}



// Function: FUN_10008134 at 10008134

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_10008134(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
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



// Function: basic_string<> at 1000819b

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
  FUN_10007d63(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_100081c0 at 100081c0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_100081c0(void *this,undefined4 *param_1,tagVARIANT *param_2)

{
  basic_string<>(this,param_1);
  *(undefined2 *)((int)this + 0x20) = 0;
  ATL::CComVariant::InternalCopy((CComVariant *)((int)this + 0x20),param_2);
  return this;
}



// Function: FUN_100081fb at 100081fb

void __thiscall FUN_100081fb(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar2 = param_2;
  if (*(char *)((int)param_2 + 0x41) != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  FUN_100034e9((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x41) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x41) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_10008245;
    piVar5[1] = (int)param_2;
    *param_2 = *piVar2;
    piVar5 = param_2;
    if (param_2 != (int *)piVar2[2]) {
      piVar5 = (int *)param_2[1];
      if (*(char *)((int)piVar7 + 0x41) == '\0') {
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
    iVar1 = param_2[0x10];
    *(char *)(param_2 + 0x10) = (char)piVar2[0x10];
    *(char *)(piVar2 + 0x10) = (char)iVar1;
  }
  else {
    piVar7 = (int *)piVar2[2];
LAB_10008245:
    piVar5 = (int *)piVar2[1];
    if (*(char *)((int)piVar7 + 0x41) == '\0') {
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
      if (*(char *)((int)piVar7 + 0x41) == '\0') {
        piVar3 = (int *)*piVar7;
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x41) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)*piVar4;
        }
      }
      **(int **)((int)this + 4) = (int)piVar6;
    }
    if (*(int **)(*(int *)((int)this + 4) + 8) == piVar2) {
      piVar6 = piVar5;
      if (*(char *)((int)piVar7 + 0x41) == '\0') {
        piVar3 = (int *)piVar7[2];
        piVar6 = piVar7;
        while (piVar4 = piVar3, *(char *)((int)piVar4 + 0x41) == '\0') {
          piVar6 = piVar4;
          piVar3 = (int *)piVar4[2];
        }
      }
      *(int **)(*(int *)((int)this + 4) + 8) = piVar6;
    }
  }
  if ((char)piVar2[0x10] != '\x01') {
LAB_10008422:
    FUN_10007e3b((int)this + 0xd,piVar2 + 4);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_100083d6:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0x10] != '\x01'))
  goto LAB_1000841e;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0x10] == '\0') {
      *(undefined1 *)(piVar5 + 0x10) = 1;
      *(undefined1 *)(piVar6 + 0x10) = 0;
      FUN_10004379(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x41) == '\0') {
      if ((*(char *)(*piVar5 + 0x40) != '\x01') || (*(char *)(piVar5[2] + 0x40) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x40) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x40) = 1;
          *(undefined1 *)(piVar5 + 0x10) = 0;
          FUN_100043be(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0x10) = (char)piVar6[0x10];
        *(undefined1 *)(piVar6 + 0x10) = 1;
        *(undefined1 *)(piVar5[2] + 0x40) = 1;
        FUN_10004379(this,(int)piVar6);
        goto LAB_1000841e;
      }
LAB_100083cd:
      *(undefined1 *)(piVar5 + 0x10) = 0;
    }
  }
  else {
    if ((char)piVar5[0x10] == '\0') {
      *(undefined1 *)(piVar5 + 0x10) = 1;
      *(undefined1 *)(piVar6 + 0x10) = 0;
      FUN_100043be(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x41) == '\0') {
      if ((*(char *)(piVar5[2] + 0x40) == '\x01') && (*(char *)(*piVar5 + 0x40) == '\x01'))
      goto LAB_100083cd;
      if (*(char *)(*piVar5 + 0x40) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x40) = 1;
        *(undefined1 *)(piVar5 + 0x10) = 0;
        FUN_10004379(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0x10) = (char)piVar6[0x10];
      *(undefined1 *)(piVar6 + 0x10) = 1;
      *(undefined1 *)(*piVar5 + 0x40) = 1;
      FUN_100043be(this,piVar6);
LAB_1000841e:
      *(undefined1 *)(piVar7 + 0x10) = 1;
      goto LAB_10008422;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_100083d6;
}



// Function: FUN_10008458 at 10008458

void __thiscall FUN_10008458(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_10008458(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10007e2c((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_1000849c at 1000849c

void __thiscall FUN_1000849c(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x41);
  while (cVar1 == '\0') {
    FUN_1000849c(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_10007e3b((int)this + 0xd,param_1 + 4);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x41);
  }
  return;
}



// Function: FUN_100084e0 at 100084e0

void __thiscall FUN_100084e0(void *this,int *param_1,int *param_2,undefined4 *param_3)

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
      iVar2 = FUN_100057e5(this_00,(ushort *)(puVar3 + 3));
      local_8 = iVar2 < 0;
    }
    else {
      iVar2 = FUN_100057e5(puVar3 + 3,this_00);
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
      goto LAB_10008556;
    }
    FUN_100044c8((int *)&param_3);
  }
  puVar3 = param_3;
  iVar2 = FUN_100057e5(param_3 + 3,this_00);
  if (-1 < iVar2) {
    FUN_10007e2c((int)this + 0xd,this_00);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10008556:
  piVar1 = (int *)FUN_10007e59(this,&param_3,local_8,local_c,param_2);
  *param_1 = *piVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_100085b6 at 100085b6

void __thiscall
FUN_100085b6(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,int *param_4)

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
    FUN_100080c9(this,param_4 + 3);
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
LAB_10008685:
        *(undefined1 *)(piVar1 + 0xb) = 1;
        *(undefined1 *)(iVar4 + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_10004334(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
        FUN_10004481(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      iVar4 = *piVar2;
      if (*(char *)(iVar4 + 0x2c) == '\0') goto LAB_10008685;
      if (piVar5 == (int *)*piVar1) {
        FUN_10004481(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0x2c) = 0;
      FUN_10004334(this,*(int *)(piVar5[1] + 4));
    }
    iVar4 = piVar5[1];
  } while( true );
}



// Function: FUN_100086ee at 100086ee

void __thiscall FUN_100086ee(void *this,int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  ushort *this_00;
  undefined4 *puVar3;
  undefined4 *local_c;
  bool local_8;
  
  this_00 = (ushort *)(param_2 + 4);
  local_8 = true;
  puVar3 = (undefined4 *)(*(undefined4 **)((int)this + 4))[1];
  local_c = *(undefined4 **)((int)this + 4);
  while (*(char *)((int)puVar3 + 0x41) == '\0') {
    if ((char)param_3 == '\0') {
      iVar2 = FUN_100057e5(this_00,(ushort *)(puVar3 + 4));
      local_8 = iVar2 < 0;
    }
    else {
      iVar2 = FUN_100057e5(puVar3 + 4,this_00);
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
      goto LAB_10008764;
    }
    FUN_10003667((int *)&param_3);
  }
  puVar3 = param_3;
  iVar2 = FUN_100057e5(param_3 + 4,this_00);
  if (-1 < iVar2) {
    FUN_10007e3b((int)this + 0xd,this_00);
    operator_delete(param_2);
    *param_1 = (int)puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10008764:
  piVar1 = (int *)FUN_10007f91(this,&param_3,local_8,local_c,param_2);
  *param_1 = *piVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_100087c4 at 100087c4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100087c4(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_74 [48];
  undefined1 local_44 [60];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0x100087d0;
  FUN_10008134(local_44,param_1,0,param_2,L"",0);
  local_8 = 0;
  FUN_10007c49(local_74,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_74,(ThrowInfo *)&DAT_10011394);
}



// Function: FUN_10008806 at 10008806

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10008806(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000c911;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_100080d8(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10008834 at 10008834

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10008834(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000c911;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10008106(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10008862 at 10008862

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_10008862(void *this,undefined4 *param_1,undefined4 *param_2)

{
  *(undefined4 *)this = *param_1;
  basic_string<>((void *)((int)this + 4),param_2);
  return (undefined4 *)this;
}



// Function: FUN_10008893 at 10008893

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008893(void *this,undefined4 *param_1,undefined4 *param_2)

{
  basic_string<>(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = *param_2;
  return this;
}



// Function: FUN_100088c6 at 100088c6

void __fastcall FUN_100088c6(void *param_1)

{
  FUN_10008458(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_100088ed at 100088ed

void __fastcall FUN_100088ed(void *param_1)

{
  FUN_1000849c(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10008914 at 10008914

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_10008914(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

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
      iVar3 = FUN_100057e5(this,(ushort *)(param_3 + 3));
      if (-1 < iVar3) goto LAB_10008a24;
      cVar5 = '\x01';
      goto LAB_10008930;
    }
    if (param_3 == piVar1) {
      iVar3 = FUN_100057e5((void *)(piVar1[2] + 0xc),this);
      if (-1 < iVar3) goto LAB_10008a24;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_10008930;
    }
    iVar3 = FUN_100057e5(this,(ushort *)(param_3 + 3));
    if (iVar3 < 0) {
      param_4 = param_3;
      FUN_100044c8((int *)&param_4);
      piVar1 = param_4;
      iVar3 = FUN_100057e5(param_4 + 3,this);
      if (-1 < iVar3) goto LAB_100089d3;
      cVar5 = *(char *)(piVar1[2] + 0x2d);
      piVar6 = param_3;
    }
    else {
LAB_100089d3:
      iVar3 = FUN_100057e5(param_3 + 3,(ushort *)(piVar2 + 3));
      if (-1 < iVar3) {
LAB_10008a24:
        puVar4 = (undefined4 *)FUN_100084e0(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_100034ae((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (iVar3 = FUN_100057e5(piVar2 + 3,(ushort *)(param_4 + 3)), -1 < iVar3)) goto LAB_10008a24;
      cVar5 = *(char *)(param_3[2] + 0x2d);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_10008930;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_10008930:
  FUN_10007e59(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_10008a40 at 10008a40

/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_10008a40(void *param_1,undefined4 *param_2,int *param_3,int *param_4)

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
  this = (ushort *)(param_4 + 4);
  local_c = param_1;
  pvStack_8 = param_1;
  if (*(int *)((int)param_1 + 8) == 0) {
    piVar6 = *(int **)((int)param_1 + 4);
  }
  else {
    piVar1 = *(int **)((int)param_1 + 4);
    if (param_3 == (int *)*piVar1) {
      iVar3 = FUN_100057e5(this,(ushort *)(param_3 + 4));
      if (-1 < iVar3) goto LAB_10008b50;
      cVar5 = '\x01';
      goto LAB_10008a5c;
    }
    if (param_3 == piVar1) {
      iVar3 = FUN_100057e5((void *)(piVar1[2] + 0x10),this);
      if (-1 < iVar3) goto LAB_10008b50;
      param_3 = *(int **)(*(int *)((int)param_1 + 4) + 8);
      cVar5 = '\0';
      goto LAB_10008a5c;
    }
    iVar3 = FUN_100057e5(this,(ushort *)(param_3 + 4));
    if (iVar3 < 0) {
      param_4 = param_3;
      FUN_10003667((int *)&param_4);
      piVar1 = param_4;
      iVar3 = FUN_100057e5(param_4 + 4,this);
      if (-1 < iVar3) goto LAB_10008aff;
      cVar5 = *(char *)(piVar1[2] + 0x41);
      piVar6 = param_3;
    }
    else {
LAB_10008aff:
      iVar3 = FUN_100057e5(param_3 + 4,(ushort *)(piVar2 + 4));
      if (-1 < iVar3) {
LAB_10008b50:
        puVar4 = (undefined4 *)FUN_100086ee(param_1,(int *)&local_c,piVar2,(undefined4 *)0x0);
        *param_2 = *puVar4;
        return param_2;
      }
      param_4 = param_3;
      FUN_100034e9((int *)&param_4);
      if ((param_4 != *(int **)((int)param_1 + 4)) &&
         (iVar3 = FUN_100057e5(piVar2 + 4,(ushort *)(param_4 + 4)), -1 < iVar3)) goto LAB_10008b50;
      cVar5 = *(char *)(param_3[2] + 0x41);
      piVar1 = param_3;
      piVar6 = param_4;
    }
    param_3 = piVar1;
    if (cVar5 != '\0') {
      cVar5 = '\0';
      goto LAB_10008a5c;
    }
  }
  cVar5 = '\x01';
  param_3 = piVar6;
LAB_10008a5c:
  FUN_10007f91(param_1,param_2,cVar5,param_3,piVar2);
  return param_2;
}



// Function: FUN_10008b6c at 10008b6c

void __thiscall FUN_10008b6c(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if ((*this == '\0') && (param_1 < 0)) {
    *(undefined1 *)this = 1;
    FUN_100087c4(param_1,*(undefined4 *)((int)this + 4));
  }
  return;
}



// Function: FUN_10008b8c at 10008b8c

void __thiscall FUN_10008b8c(void *this,int *param_1,int *param_2,char param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  uint *puVar3;
  char local_c;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)((int)this + 4);
  puVar3 = (uint *)(param_2 + 3);
  local_c = '\x01';
  if (*(char *)((int)local_8[1] + 0x2d) == '\0') {
    puVar1 = (undefined4 *)local_8[1];
    do {
      local_8 = puVar1;
      if (param_3 == '\0') {
        local_c = *puVar3 < (uint)local_8[3];
      }
      else {
        local_c = '\x01' - ((uint)local_8[3] < *puVar3);
      }
      if (local_c == '\0') {
        puVar1 = (undefined4 *)local_8[2];
      }
      else {
        puVar1 = (undefined4 *)*local_8;
      }
    } while (*(char *)((int)puVar1 + 0x2d) == '\0');
  }
  _param_3 = local_8;
  if (local_c != '\0') {
    if (local_8 == (undefined4 *)**(int **)((int)this + 4)) {
      local_c = '\x01';
      goto LAB_10008bf5;
    }
    FUN_100044c8((int *)&param_3);
  }
  puVar1 = _param_3;
  if (*puVar3 <= (uint)_param_3[3]) {
    FUN_100080c9((int)this + 0xd,puVar3);
    operator_delete(param_2);
    *param_1 = (int)puVar1;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_10008bf5:
  piVar2 = (int *)FUN_100085b6(this,(undefined4 *)&param_3,local_c,local_8,param_2);
  *param_1 = *piVar2;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// Function: FUN_10008c4f at 10008c4f

void __cdecl FUN_10008c4f(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10008806(param_2,param_3);
  return;
}



// Function: FUN_10008c62 at 10008c62

void __cdecl FUN_10008c62(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10008834(param_2,param_3);
  return;
}



// Function: FUN_10008c75 at 10008c75

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008c75(void *this,undefined4 *param_1)

{
  FUN_10008862(this,param_1,param_1 + 1);
  return this;
}



// Function: FUN_10008ca3 at 10008ca3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008ca3(void *this,undefined4 *param_1)

{
  FUN_10008893(this,param_1,param_1 + 7);
  return this;
}



// Function: FUN_10008cd1 at 10008cd1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_10008cd1(void *this,undefined4 *param_1)

{
  FUN_100081c0(this,param_1,(tagVARIANT *)(param_1 + 8));
  return this;
}



// Function: FUN_10008cff at 10008cff

void __thiscall FUN_10008cff(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_100088c6(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_100034ae((int *)&param_2);
      FUN_1000a499(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_10008d52 at 10008d52

void __thiscall FUN_10008d52(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_100088ed(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_100034e9((int *)&param_2);
      FUN_100081fb(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_10008da5 at 10008da5

int __thiscall FUN_10008da5(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  FUN_10008b6c((void *)((int)this + 4),param_1);
  return (int)this;
}



// Function: FUN_10008dc1 at 10008dc1

undefined4 * __thiscall FUN_10008dc1(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  char cVar4;
  int *piVar5;
  void *local_c;
  void *pvStack_8;
  
  piVar2 = param_3;
  local_c = this;
  pvStack_8 = this;
  if (*(int *)((int)this + 8) == 0) {
    FUN_100085b6(this,param_1,'\x01',*(undefined4 **)((int)this + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)((int)this + 4);
  piVar5 = param_2;
  if (param_2 == (int *)*piVar1) {
    if ((uint)param_2[3] <= (uint)param_3[3]) goto LAB_10008e8b;
    cVar4 = '\x01';
    goto LAB_10008e7e;
  }
  if (param_2 == piVar1) {
    param_2 = (int *)piVar1[2];
    if ((uint)param_3[3] <= (uint)param_2[3]) goto LAB_10008e8b;
  }
  else {
    if ((uint)param_3[3] < (uint)param_2[3]) {
      param_3 = param_2;
      FUN_100044c8((int *)&param_3);
      if ((uint)piVar2[3] <= (uint)param_3[3]) goto LAB_10008e47;
      cVar4 = *(char *)(param_3[2] + 0x2d);
      param_2 = param_3;
    }
    else {
LAB_10008e47:
      if ((uint)piVar2[3] <= (uint)param_2[3]) {
LAB_10008e8b:
        puVar3 = (undefined4 *)FUN_10008b8c(this,(int *)&local_c,piVar2,'\0');
        *param_1 = *puVar3;
        return param_1;
      }
      param_3 = param_2;
      FUN_100034ae((int *)&param_3);
      if ((param_3 != *(int **)((int)this + 4)) && ((uint)param_3[3] <= (uint)piVar2[3]))
      goto LAB_10008e8b;
      cVar4 = *(char *)(param_2[2] + 0x2d);
      piVar5 = param_3;
    }
    if (cVar4 == '\0') {
      cVar4 = '\x01';
      goto LAB_10008e7e;
    }
  }
  cVar4 = '\0';
  piVar5 = param_2;
LAB_10008e7e:
  FUN_100085b6(this,param_1,cVar4,piVar5,piVar2);
  return param_1;
}



// Function: FUN_10008ea7 at 10008ea7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10008ea7(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10004535((int)this);
  FUN_10008c62((int)this + 0xd,(void *)(iVar1 + 0x10),param_1);
  return iVar1;
}



// Function: Catch@10008ee4 at 10008ee4

void Catch_10008ee4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10008ef7 at 10008ef7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10008ef7(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000450e((int)this);
  FUN_10008c4f((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10008f34 at 10008f34

void Catch_10008f34(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10008f47 at 10008f47

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10008f47(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000c911;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10008c75(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10008f75 at 10008f75

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10008f75(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000c911;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10008ca3(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10008fa3 at 10008fa3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_10008fa3(void *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_1000c911;
  if (param_1 != (void *)0x0) {
    puVar1 = (undefined1 *)FUN_10008cd1(param_1,param_2);
  }
  return puVar1;
}



// Function: FUN_10008fd1 at 10008fd1

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10008fd1(void *this,undefined *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 local_28 [3];
  undefined4 local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x10008fdd;
  FUN_10004405(local_28);
  local_8 = 1;
  if (*(char *)((int)this + 0x14) == '\0') {
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x2c))(param_1);
    FUN_10008da5(local_28,iVar1);
  }
  local_18 = 0;
  while( true ) {
    iVar1 = local_18;
    ppuVar2 = FUN_10009f20();
    if (ppuVar2[iVar1] == (undefined *)0x0) break;
    ppuVar2 = FUN_10009f20();
    param_1 = ppuVar2[iVar1];
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x28))(&param_1);
    FUN_10008da5(local_28,iVar1);
    local_18 = local_18 + 1;
  }
  return local_1c;
}



// Function: Catch@1000904e at 1000904e

undefined4 Catch_1000904e(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000903f;
}



// Function: FUN_10009058 at 10009058

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_10009058(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 **ppuVar2;
  int iVar3;
  undefined4 local_24 [3];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x10009064;
  FUN_10004405(local_24);
  local_8 = 1;
  if (*(char *)((int)this + 0x14) == '\0') {
    if (param_1 != (undefined4 *)0x0) {
      iVar3 = (**(code **)*param_1)(param_1,&DAT_1000e994,(undefined4 *)((int)this + 0x18));
      FUN_10008da5(local_24,iVar3);
      piVar1 = *(int **)((int)this + 0x18);
      ppuVar2 = FUN_1000a1aa();
      if (ppuVar2 == (undefined4 **)0x0) {
        param_1 = (undefined4 *)0x0;
      }
      else {
        param_1 = (undefined4 *)Ordinal_2(ppuVar2);
        if (param_1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_100026b4(0x8007000e);
        }
      }
      local_8._0_1_ = 2;
      iVar3 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_1);
      FUN_10008da5(local_24,iVar3);
      local_8 = CONCAT31(local_8._1_3_,1);
      Ordinal_6(param_1);
      goto LAB_100090dd;
    }
    iVar3 = -0x7fffbffd;
  }
  else {
    iVar3 = 0;
  }
  FUN_10008da5(local_24,iVar3);
LAB_100090dd:
  *(undefined1 *)((int)this + 0x14) = 1;
  return local_18;
}



// Function: Catch@1000910b at 1000910b

undefined4 Catch_1000910b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100090e4;
}



// Function: FUN_10009115 at 10009115

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_10009115(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_28 [3];
  undefined4 local_1c;
  undefined4 *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x10009121;
  FUN_10004405(local_28);
  local_8 = 1;
  iVar1 = FUN_10007b65(local_18);
  FUN_10008da5(local_28,iVar1);
  local_18[0][2] = param_1;
  iVar1 = (**(code **)*local_18[0])(local_18[0],&DAT_1000e9a4,param_2);
  FUN_10008da5(local_28,iVar1);
  return local_1c;
}



// Function: Catch@10009175 at 10009175

undefined4 Catch_10009175(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10009166;
}



// Function: FUN_1000917f at 1000917f

void __cdecl FUN_1000917f(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10008f47(param_2,param_3);
  return;
}



// Function: FUN_10009192 at 10009192

void __cdecl FUN_10009192(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10008f75(param_2,param_3);
  return;
}



// Function: FUN_100091a5 at 100091a5

void __cdecl FUN_100091a5(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  FUN_10008fa3(param_2,param_3);
  return;
}



// Function: FUN_100091b8 at 100091b8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100091b8(void *this,ushort *param_1)

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
  local_8 = 0x100091c4;
  piVar1 = FUN_10006f6a(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_100057e5(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_10009227;
  }
  basic_string<>(local_34,(undefined4 *)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_10008ef7(this,local_34);
  FUN_10008914(this,&local_38,piVar1,piVar3);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_34,'\x01',0);
LAB_10009227:
  FUN_1000b1dd();
  return;
}



// Function: FUN_10009232 at 10009232

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10009232(void *this,ushort *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  tagVARIANT local_58 [16];
  undefined4 local_48;
  undefined4 local_44 [15];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x1000923e;
  piVar1 = FUN_10006f35(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_100057e5(param_1,(ushort *)(piVar1 + 4));
    if (-1 < iVar2) goto LAB_100092b3;
  }
  Ordinal_8(local_58);
  local_8 = 0;
  FUN_10007ccc(local_44,(undefined4 *)param_1,local_58);
  local_8._0_1_ = 2;
  piVar3 = (int *)FUN_10008ea7(this,local_44);
  FUN_10008a40(this,&local_48,piVar1,piVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005435(local_44);
  local_8 = 0xffffffff;
  Ordinal_9(local_58);
LAB_100092b3:
  FUN_1000b1dd();
  return;
}



// Function: FUN_100092be at 100092be

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100092be(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10008d52(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_100092f8 at 100092f8

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_100092f8(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000450e((int)this);
  FUN_1000917f((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10009335 at 10009335

void Catch_10009335(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10009348 at 10009348

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10009348(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000450e((int)this);
  FUN_10009192((int)this + 0xd,(void *)(iVar1 + 0xc),param_1);
  return iVar1;
}



// Function: Catch@10009385 at 10009385

void Catch_10009385(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10009398 at 10009398

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_10009398(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10004535((int)this);
  FUN_100091a5((int)this + 0xd,(void *)(iVar1 + 0x10),param_1);
  return iVar1;
}



// Function: Catch@100093d5 at 100093d5

void Catch_100093d5(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100093e8 at 100093e8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_100093e8(void *param_1)

{
  FUN_100092be(param_1);
  return;
}



// Function: FUN_10009406 at 10009406

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10009406(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x10009412;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_1000a173(param_1);
  return local_18;
}



// Function: FUN_10009432 at 10009432

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_10009432(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000943e;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_100056b6(param_1);
  return local_18;
}



// Function: FUN_1000945e at 1000945e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000945e(int param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  undefined4 *puVar2;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x1000946a;
  ppuVar1 = FUN_10009f20();
  FUN_10007d31(local_30,(wchar_t *)ppuVar1[*(int *)(param_1 + 8)]);
  local_8 = 0;
  puVar2 = (undefined4 *)FUN_100091b8((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  (*(code *)**(undefined4 **)*puVar2)((undefined4 *)*puVar2,&DAT_1000e848,param_2);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000b1dd();
  return;
}



// Function: FUN_100094bf at 100094bf

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100094bf(int param_1,int *param_2)

{
  int iVar1;
  undefined **ppuVar2;
  int *piVar3;
  undefined4 *puVar4;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x100094cb;
  ppuVar2 = FUN_10009f20();
  FUN_10007d31(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
  local_8 = 0;
  piVar3 = (int *)FUN_100091b8((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  iVar1 = *piVar3;
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  if (iVar1 != 0) {
    ppuVar2 = FUN_10009f20();
    FUN_10007d31(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
    local_8 = 1;
    puVar4 = (undefined4 *)FUN_100091b8((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
    (**(code **)(*(int *)*puVar4 + 8))((int *)*puVar4);
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
    ppuVar2 = FUN_10009f20();
    FUN_10007d31(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
    local_8 = 2;
    puVar4 = (undefined4 *)FUN_100091b8((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
    *puVar4 = 0;
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  local_8 = 4;
  ppuVar2 = FUN_10009f20();
  FUN_10007d31(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
  local_8._0_1_ = 5;
  puVar4 = (undefined4 *)FUN_100091b8((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  *puVar4 = param_2;
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_30,'\x01',0);
  ppuVar2 = FUN_10009f20();
  FUN_10007d31(local_30,(wchar_t *)ppuVar2[*(int *)(param_1 + 8)]);
  local_8._0_1_ = 6;
  puVar4 = (undefined4 *)FUN_100091b8((void *)(*(int *)(param_1 + 0xc) + 4),local_30);
  (**(code **)(*(int *)*puVar4 + 4))((int *)*puVar4);
  local_8 = CONCAT31(local_8._1_3_,4);
  FID_conflict__Tidy(local_30,'\x01',0);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_1000962b at 1000962b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000962b(void *this,uint *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_54;
  uint local_50;
  undefined1 local_4c [28];
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x10009637;
  piVar1 = FUN_1000568a(this,param_1);
  if ((piVar1 == *(int **)((int)this + 4)) || (*param_1 < (uint)piVar1[3])) {
    local_20 = 0;
    local_1c = 7;
    local_30[0] = 0;
    local_8 = 0;
    local_50 = *param_1;
    basic_string<>(local_4c,(undefined4 *)local_30);
    local_8._0_1_ = 3;
    piVar2 = (int *)FUN_100092f8(this,&local_50);
    FUN_10008dc1(this,&local_54,piVar1,piVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FID_conflict__Tidy(local_4c,'\x01',0);
    local_8 = 0xffffffff;
    FID_conflict__Tidy(local_30,'\x01',0);
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_100096bf at 100096bf

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_100096bf(void *this,ushort *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  tagVARIANT local_58 [16];
  undefined4 local_48;
  undefined4 local_44 [15];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x100096cb;
  piVar1 = FUN_10006f35(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_100057e5(param_1,(ushort *)(piVar1 + 4));
    if (-1 < iVar2) goto LAB_10009740;
  }
  Ordinal_8(local_58);
  local_8 = 0;
  FUN_100081c0(local_44,(undefined4 *)param_1,local_58);
  local_8._0_1_ = 2;
  piVar3 = (int *)FUN_10009398(this,local_44);
  FUN_10008a40(this,&local_48,piVar1,piVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005435(local_44);
  local_8 = 0xffffffff;
  Ordinal_9(local_58);
LAB_10009740:
  FUN_1000b1dd();
  return;
}



// Function: FUN_1000974b at 1000974b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000974b(void *this,ushort *param_1)

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
  local_8 = 0x10009757;
  piVar1 = FUN_10006f6a(this,param_1);
  if (piVar1 != *(int **)((int)this + 4)) {
    iVar2 = FUN_100057e5(param_1,(ushort *)(piVar1 + 3));
    if (-1 < iVar2) goto LAB_100097ba;
  }
  basic_string<>(local_34,(undefined4 *)param_1);
  local_18 = 0;
  local_8 = 2;
  piVar3 = (int *)FUN_10009348(this,local_34);
  FUN_10008914(this,&local_38,piVar1,piVar3);
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_34,'\x01',0);
LAB_100097ba:
  FUN_1000b1dd();
  return;
}



// Function: FUN_100097c5 at 100097c5

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_100097c5(int param_1,wchar_t *param_2,void *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined2 local_64 [4];
  undefined4 local_5c;
  undefined1 local_54 [16];
  wchar_t *local_44;
  void *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  ushort local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x100097d1;
  local_44 = param_2;
  local_40 = param_3;
  if (param_3 != (void *)0x0) {
    FUN_10009f26(param_1 + -8);
    FUN_10009406((int)local_54);
    local_8 = 0;
    FUN_10001656(*(void **)(param_1 + 100),&local_3c);
    FUN_10007d31(local_30,L"MAXTHREADS");
    local_8._0_1_ = 1;
    puVar2 = (undefined4 *)FUN_100091b8(local_54,local_30);
    *puVar2 = local_34;
    local_8._0_1_ = 0;
    FID_conflict__Tidy(local_30,'\x01',0);
    FUN_10007d31(local_30,L"OVERFLOWTIMEOUT");
    local_8._0_1_ = 2;
    puVar2 = (undefined4 *)FUN_100091b8(local_54,local_30);
    *puVar2 = local_38;
    local_8._0_1_ = 0;
    FID_conflict__Tidy(local_30,'\x01',0);
    FUN_10007d31(local_30,L"POOLSIZE");
    local_8._0_1_ = 3;
    puVar2 = (undefined4 *)FUN_100091b8(local_54,local_30);
    *puVar2 = local_3c;
    local_8._0_1_ = 0;
    FID_conflict__Tidy(local_30,'\x01',0);
    FUN_10007d31(local_30,L"THREADCOUNT");
    uVar1 = DAT_10013c98;
    local_8._0_1_ = 4;
    puVar2 = (undefined4 *)FUN_100091b8(local_54,local_30);
    *puVar2 = uVar1;
    local_8._0_1_ = 0;
    FID_conflict__Tidy(local_30,'\x01',0);
    FUN_10007d31(local_30,local_44);
    local_8._0_1_ = 5;
    puVar2 = (undefined4 *)FUN_1000974b(local_54,local_30);
    local_5c = *puVar2;
    local_64[0] = 3;
    local_8._0_1_ = 7;
    FID_conflict__Tidy(local_30,'\x01',0);
    FUN_1000321f(local_64,local_40);
    FUN_10009f32(param_1 + -8);
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_9(local_64);
    local_8 = 0xffffffff;
    FUN_1000a7ee(local_54);
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_1000993f at 1000993f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_1000993f(int param_1,uint param_2,wchar_t *param_3,void *param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  CComVariant *pCVar3;
  void *pvVar4;
  int iVar5;
  tagVARIANT *ptVar6;
  code *pcVar7;
  char cVar8;
  undefined4 uVar9;
  undefined4 local_90;
  undefined2 local_8c [8];
  void *local_7c;
  wchar_t *local_78;
  void *local_74;
  int local_70;
  undefined4 local_6c;
  char local_68;
  char cStack_67;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined1 local_54 [16];
  undefined2 local_44 [8];
  uint local_34;
  ushort local_30 [20];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0x1000994e;
  local_78 = param_3;
  local_7c = param_4;
  local_5c = 0;
  if (param_4 != (void *)0x0) {
    local_58 = (int *)FUN_1000211d();
    if (local_58 == (int *)0x0) {
      local_5c = 0x80070057;
    }
    else {
      local_70 = param_1 + -8;
      FUN_10009f26(local_70);
      local_64 = 0xffffffff;
      local_6c = 0;
      local_68 = '\0';
      cStack_67 = '\x01';
      local_60 = 0;
      FUN_10001122(local_58,&local_6c);
      FUN_10009432((int)local_54);
      local_8 = 0;
      local_74 = (void *)(param_1 + 0x44);
      local_34 = param_2;
      piVar1 = (int *)FUN_10006c0d(local_74,&local_90,&local_34);
      if (*piVar1 == *(int *)(param_1 + 0x48)) {
        FUN_10007d31(local_30,L"USER");
        local_8._0_1_ = 7;
        local_34 = Ordinal_2(&DAT_1000ea20);
        if (local_34 == 0) {
LAB_10009ab3:
                    /* WARNING: Subroutine does not return */
          FUN_100026b4(0x8007000e);
        }
        local_8._0_1_ = 8;
        local_44[0] = 0;
        FUN_10003854(local_44,(int *)&local_34);
        local_8 = CONCAT31(local_8._1_3_,9);
        pCVar3 = (CComVariant *)FUN_10009232(local_54,local_30);
        if (pCVar3 != (CComVariant *)local_44) {
          ATL::CComVariant::InternalCopy(pCVar3,(tagVARIANT *)local_44);
        }
        pcVar7 = Ordinal_9_exref;
        local_8._0_1_ = 8;
        Ordinal_9(local_44);
        local_8._0_1_ = 7;
        Ordinal_6(local_34);
        local_8._0_1_ = 0;
        FID_conflict__Tidy(local_30,'\x01',0);
        FUN_10007d31(local_30,L"NAME");
        local_8._0_1_ = 10;
        local_34 = Ordinal_2(&DAT_1000ea20);
        if (local_34 == 0) goto LAB_10009ab3;
        local_8._0_1_ = 0xb;
        local_44[0] = 0;
        FUN_10003854(local_44,(int *)&local_34);
        local_8 = CONCAT31(local_8._1_3_,0xc);
        pCVar3 = (CComVariant *)FUN_10009232(local_54,local_30);
        if (pCVar3 != (CComVariant *)local_44) {
          ATL::CComVariant::InternalCopy(pCVar3,(tagVARIANT *)local_44);
        }
        local_8._0_1_ = 0xb;
        Ordinal_9(local_44);
        local_8._0_1_ = 10;
        Ordinal_6(local_34);
        local_8 = (uint)local_8._1_3_ << 8;
        FID_conflict__Tidy(local_30,'\x01',0);
      }
      else {
        local_34 = param_2;
        FUN_10007d31(local_30,L"USER");
        local_8._0_1_ = 1;
        puVar2 = (undefined4 *)FUN_1000962b((void *)(param_1 + 0x54),&local_34);
        if (7 < (uint)puVar2[5]) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) {
          local_34 = 0;
        }
        else {
          local_34 = Ordinal_2(puVar2);
          if (local_34 == 0) goto LAB_10009ab3;
        }
        local_8._0_1_ = 2;
        local_44[0] = 0;
        FUN_10003854(local_44,(int *)&local_34);
        local_8 = CONCAT31(local_8._1_3_,3);
        pCVar3 = (CComVariant *)FUN_10009232(local_54,local_30);
        if (pCVar3 != (CComVariant *)local_44) {
          ATL::CComVariant::InternalCopy(pCVar3,(tagVARIANT *)local_44);
        }
        pcVar7 = Ordinal_9_exref;
        local_8._0_1_ = 2;
        Ordinal_9(local_44);
        local_8._0_1_ = 1;
        Ordinal_6(local_34);
        local_8._0_1_ = 0;
        FID_conflict__Tidy(local_30,'\x01',0);
        local_34 = param_2;
        FUN_10007d31(local_30,L"NAME");
        local_8._0_1_ = 4;
        puVar2 = (undefined4 *)FUN_1000962b(local_74,&local_34);
        if (7 < (uint)puVar2[5]) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) {
          local_34 = 0;
        }
        else {
          local_34 = Ordinal_2(puVar2);
          if (local_34 == 0) goto LAB_10009ab3;
        }
        local_8._0_1_ = 5;
        local_44[0] = 0;
        FUN_10003854(local_44,(int *)&local_34);
        local_8 = CONCAT31(local_8._1_3_,6);
        pCVar3 = (CComVariant *)FUN_10009232(local_54,local_30);
        if (pCVar3 != (CComVariant *)local_44) {
          ATL::CComVariant::InternalCopy(pCVar3,(tagVARIANT *)local_44);
        }
        local_8._0_1_ = 5;
        Ordinal_9(local_44);
        local_8._0_1_ = 4;
        Ordinal_6(local_34);
        local_8 = (uint)local_8._1_3_ << 8;
        FID_conflict__Tidy(local_30,'\x01',0);
      }
      FUN_10007d31(local_30,L"PRIORITY");
      local_8._0_1_ = 0xd;
      uVar9 = local_6c;
      pvVar4 = (void *)FUN_10009232(local_54,local_30);
      FUN_100038d6(pvVar4,uVar9);
      local_8._0_1_ = 0;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_10007d31(local_30,L"STACKSIZE");
      local_8._0_1_ = 0xe;
      uVar9 = local_60;
      pvVar4 = (void *)FUN_10009232(local_54,local_30);
      FUN_100038d6(pvVar4,uVar9);
      local_8._0_1_ = 0;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_10007d31(local_30,L"LOOPING");
      local_8._0_1_ = 0xf;
      cVar8 = local_68;
      pvVar4 = (void *)FUN_10009232(local_54,local_30);
      FUN_1000389f(pvVar4,cVar8);
      local_8._0_1_ = 0;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_10007d31(local_30,L"STATE");
      local_8._0_1_ = 0x10;
      iVar5 = FUN_1000150d(local_58);
      pvVar4 = (void *)FUN_10009232(local_54,local_30);
      FUN_100038d6(pvVar4,iVar5);
      local_8._0_1_ = 0;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_10007d31(local_30,L"OVERFLOW");
      local_8._0_1_ = 0x11;
      cVar8 = cStack_67;
      pvVar4 = (void *)FUN_10009232(local_54,local_30);
      FUN_1000389f(pvVar4,cVar8);
      local_8._0_1_ = 0;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_10007d31(local_30,L"OVERFLOWTIMEOUT");
      local_8._0_1_ = 0x12;
      uVar9 = local_64;
      pvVar4 = (void *)FUN_10009232(local_54,local_30);
      FUN_100038d6(pvVar4,uVar9);
      local_8._0_1_ = 0;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_10007d31(local_30,local_78);
      local_8._0_1_ = 0x13;
      ptVar6 = (tagVARIANT *)FUN_100096bf(local_54,local_30);
      local_8c[0] = 0;
      ATL::CComVariant::InternalCopy((CComVariant *)local_8c,ptVar6);
      local_8._0_1_ = 0x15;
      FID_conflict__Tidy(local_30,'\x01',0);
      FUN_1000321f(local_8c,local_7c);
      FUN_10009f32(local_70);
      local_8 = (uint)local_8._1_3_ << 8;
      (*pcVar7)(local_8c);
      local_8 = 0xffffffff;
      FUN_100092be(local_54);
    }
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_10009deb at 10009deb

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_10009deb(void *this,int *param_1)

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
  local_8 = 0x10009df7;
  piVar1 = *(int **)((int)this + 0x18);
  if (*param_1 == 0) {
    local_34 = 0;
  }
  else {
    local_34 = Ordinal_2(*param_1);
    if (local_34 == 0) goto LAB_10009e28;
  }
  local_8 = 0;
  ppuVar2 = FUN_1000a1aa();
  if (ppuVar2 == (undefined4 **)0x0) {
    local_38 = 0;
  }
  else {
    local_38 = Ordinal_2(ppuVar2);
    if (local_38 == 0) {
LAB_10009e28:
                    /* WARNING: Subroutine does not return */
      FUN_100026b4(0x8007000e);
    }
  }
  local_8._0_1_ = 1;
  (**(code **)(*piVar1 + 0x24))(piVar1,local_38,local_34,&local_3c);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_38);
  local_8 = 0xffffffff;
  Ordinal_6(local_34);
  puVar3 = FUN_10007d31(local_30,(wchar_t *)*param_1);
  local_8 = 2;
  puVar4 = (undefined4 *)FUN_1000974b((void *)((int)this + 4),puVar3);
  *puVar4 = local_3c;
  local_8 = 0xffffffff;
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_1000b1dd();
  return;
}



// Function: FUN_10009ea9 at 10009ea9

void __thiscall FUN_10009ea9(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
                    /* WARNING: Load size is inaccurate */
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  (**(code **)(**this + 0x18))(*this,param_1,&DAT_1000ee40,0x400,1,&local_14,param_2,0,0);
  return;
}



// Function: FUN_10009ee1 at 10009ee1

void __thiscall FUN_10009ee1(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  (**(code **)(**this + 0x18))(*this,param_1,&DAT_1000ee40,0x400,1,&local_14,param_3,0,0);
  return;
}



// Function: FUN_10009f20 at 10009f20

undefined ** FUN_10009f20(void)

{
  return &PTR_u__89F5ADE7_D20B_42E7_B980_5150ECB_1000ede8;
}



// Function: FUN_10009f26 at 10009f26

void __fastcall FUN_10009f26(int param_1)

{
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x70),0xffffffff);
  return;
}



// Function: FUN_10009f32 at 10009f32

void __fastcall FUN_10009f32(int param_1)

{
  ReleaseMutex(*(HANDLE *)(param_1 + 0x70));
  return;
}



// Function: FUN_10009f3c at 10009f3c

undefined4 FUN_10009f3c(int param_1,undefined4 param_2,byte param_3,int *param_4)

{
  char cVar1;
  void *this;
  uint uVar2;
  int local_18;
  undefined2 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0x80004005;
  FUN_10009f26(param_1 + -4);
  this = (void *)FUN_1000211d();
  if (this != (void *)0x0) {
    local_10 = 0xffffffff;
    uVar2 = 0;
    local_18 = 0;
    local_14 = 0x100;
    local_c = 0;
    if ((param_3 & 4) != 0) {
      local_14 = CONCAT11(1,param_4[2] != 0);
      uVar2 = 2;
    }
    if ((param_3 & 2) != 0) {
      local_c = param_4[1];
    }
    if ((param_3 & 1) != 0) {
      local_18 = *param_4;
      uVar2 = uVar2 | 1;
    }
    cVar1 = FUN_10001530(this,uVar2,&local_18);
    if (cVar1 != '\0') {
      local_8 = 0;
    }
  }
  FUN_10009f32(param_1 + -4);
  return local_8;
}



// Function: FUN_10009fcf at 10009fcf

undefined4 FUN_10009fcf(int param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 local_18;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0x80004005;
  FUN_10009f26(param_1 + -4);
  this = (void *)FUN_1000211d();
  if (this != (void *)0x0) {
    local_18 = 0;
    local_10 = 0xffffffff;
    local_c = 0;
    local_14 = 0x100;
    FUN_10001122(this,&local_18);
    local_8 = 0;
    param_3[2] = (uint)(byte)local_14;
    param_3[1] = local_c;
    *param_3 = local_18;
  }
  FUN_10009f32(param_1 + -4);
  return local_8;
}



// Function: FUN_1000a03f at 1000a03f

void FUN_1000a03f(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != (int *)0x0) {
    FUN_10009f26(param_1 + -0xc);
    FUN_100024d5(*(void **)(param_1 + 0x60),param_2);
    FUN_10009f32(param_1 + -0xc);
  }
  iVar1 = *(int *)(param_1 + 4);
  uVar2 = (**(code **)(*(int *)(param_1 + -0xc) + 0x1c))();
  (**(code **)(iVar1 + 0x1c))(uVar2);
  return;
}



// Function: FUN_1000a080 at 1000a080

undefined4 FUN_1000a080(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    FUN_10009f26(param_1 + -0xc);
    uVar1 = FUN_10001634(*(void **)(param_1 + 0x60),param_2);
    if ((char)uVar1 != '\0') {
      uVar2 = 0;
    }
    FUN_10009f32(param_1 + -0xc);
  }
  return uVar2;
}



// Function: FUN_1000a0c3 at 1000a0c3

undefined4 FUN_1000a0c3(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    FUN_10009f26(param_1 + -0xc);
    uVar1 = FUN_10001656(*(void **)(param_1 + 0x60),param_2);
    if ((char)uVar1 != '\0') {
      uVar2 = 0;
    }
    FUN_10009f32(param_1 + -0xc);
  }
  return uVar2;
}



// Function: FUN_1000a106 at 1000a106

undefined4 FUN_1000a106(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004005;
  FUN_10009f26(param_1 + -0xc);
  cVar1 = FUN_10001e46();
  if (cVar1 != '\0') {
    uVar2 = 0;
  }
  FUN_10009f32(param_1 + -0xc);
  return uVar2;
}



// Function: FUN_1000a13b at 1000a13b

void FUN_1000a13b(int param_1)

{
  (**(code **)(*(int *)(param_1 + 8) + 0x28))((int *)(param_1 + 8));
  return;
}



// Function: FUN_1000a14e at 1000a14e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a14e(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1000a173 at 1000a173

int __fastcall FUN_1000a173(int param_1)

{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 8) = 0;
  pvVar1 = FUN_1000352b((char *)0x1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)pvVar1 = pvVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x2d) = 1;
  return param_1;
}



// Function: FUN_1000a1aa at 1000a1aa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ** FUN_1000a1aa(void)

{
  LPOLESTR pOVar1;
  size_t sVar2;
  undefined4 ***pppuVar3;
  LPOLESTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x1000a1b6;
  if ((DAT_10013d88 & 1) == 0) {
    DAT_10013d88 = DAT_10013d88 | 1;
    local_8 = 0;
    DAT_10013d80 = 7;
    _DAT_10013d7c = 0;
    DAT_10013d6c = (undefined4 **)((uint)DAT_10013d6c & 0xffff0000);
    _atexit((_func_4879 *)&LAB_1000d22d);
    local_8 = 0xffffffff;
  }
  local_14[0] = (wchar_t *)0x0;
  StringFromCLSID((IID *)&DAT_1000e474,local_14);
  pOVar1 = local_14[0];
  sVar2 = wcslen(local_14[0]);
  FID_conflict_assign(&DAT_10013d6c,(undefined4 *)pOVar1,sVar2);
  CoTaskMemFree(local_14[0]);
  pppuVar3 = (undefined4 ***)DAT_10013d6c;
  if (DAT_10013d80 < 8) {
    pppuVar3 = &DAT_10013d6c;
  }
  return pppuVar3;
}



// Function: FUN_1000a23c at 1000a23c

void __thiscall FUN_1000a23c(void *this,undefined4 *param_1,int *param_2)

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
  FUN_100034ae((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000a286;
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
LAB_1000a286:
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
LAB_1000a463:
    FUN_100080c9((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000a417:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xb] != '\x01'))
  goto LAB_1000a45f;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10004334(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x2c) = 1;
          *(undefined1 *)(piVar5 + 0xb) = 0;
          FUN_10004481(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        FUN_10004334(this,(int)piVar6);
        goto LAB_1000a45f;
      }
LAB_1000a40e:
      *(undefined1 *)(piVar5 + 0xb) = 0;
    }
  }
  else {
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10004481(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
      goto LAB_1000a40e;
      if (*(char *)(*piVar5 + 0x2c) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        *(undefined1 *)(piVar5 + 0xb) = 0;
        FUN_10004334(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(*piVar5 + 0x2c) = 1;
      FUN_10004481(this,piVar6);
LAB_1000a45f:
      *(undefined1 *)(piVar7 + 0xb) = 1;
      goto LAB_1000a463;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000a417;
}



// Function: FUN_1000a499 at 1000a499

void __thiscall FUN_1000a499(void *this,undefined4 *param_1,int *param_2)

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
  FUN_100034ae((int *)&param_2);
  piVar5 = (int *)*piVar2;
  if (*(char *)((int)piVar5 + 0x2d) == '\0') {
    piVar7 = piVar5;
    if ((*(char *)(piVar2[2] + 0x2d) != '\0') || (piVar7 = (int *)param_2[2], param_2 == piVar2))
    goto LAB_1000a4e3;
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
LAB_1000a4e3:
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
LAB_1000a6c0:
    FUN_10007e2c((int)this + 0xd,piVar2 + 3);
    operator_delete(piVar2);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_1000a674:
  piVar6 = piVar5;
  if ((piVar7 == *(int **)(*(int *)((int)this + 4) + 4)) || ((char)piVar7[0xb] != '\x01'))
  goto LAB_1000a6bc;
  piVar5 = (int *)*piVar6;
  if (piVar7 == piVar5) {
    piVar5 = (int *)piVar6[2];
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10004334(this,(int)piVar6);
      piVar5 = (int *)piVar6[2];
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
        if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
          *(undefined1 *)(*piVar5 + 0x2c) = 1;
          *(undefined1 *)(piVar5 + 0xb) = 0;
          FUN_10004481(this,piVar5);
          piVar5 = (int *)piVar6[2];
        }
        *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        FUN_10004334(this,(int)piVar6);
        goto LAB_1000a6bc;
      }
LAB_1000a66b:
      *(undefined1 *)(piVar5 + 0xb) = 0;
    }
  }
  else {
    if ((char)piVar5[0xb] == '\0') {
      *(undefined1 *)(piVar5 + 0xb) = 1;
      *(undefined1 *)(piVar6 + 0xb) = 0;
      FUN_10004481(this,piVar6);
      piVar5 = (int *)*piVar6;
    }
    if (*(char *)((int)piVar5 + 0x2d) == '\0') {
      if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
      goto LAB_1000a66b;
      if (*(char *)(*piVar5 + 0x2c) == '\x01') {
        *(undefined1 *)(piVar5[2] + 0x2c) = 1;
        *(undefined1 *)(piVar5 + 0xb) = 0;
        FUN_10004334(this,(int)piVar5);
        piVar5 = (int *)*piVar6;
      }
      *(char *)(piVar5 + 0xb) = (char)piVar6[0xb];
      *(undefined1 *)(piVar6 + 0xb) = 1;
      *(undefined1 *)(*piVar5 + 0x2c) = 1;
      FUN_10004481(this,piVar6);
LAB_1000a6bc:
      *(undefined1 *)(piVar7 + 0xb) = 1;
      goto LAB_1000a6c0;
    }
  }
  piVar5 = (int *)piVar6[1];
  piVar7 = piVar6;
  goto LAB_1000a674;
}



// Function: FUN_1000a6f6 at 1000a6f6

void __thiscall FUN_1000a6f6(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    FUN_1000a6f6(this,(int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_100080c9((int)this + 0xd,param_1 + 3);
    operator_delete(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2d);
  }
  return;
}



// Function: FUN_1000a73a at 1000a73a

void __fastcall FUN_1000a73a(void *param_1)

{
  FUN_1000a6f6(param_1,*(int **)(*(int *)((int)param_1 + 4) + 4));
  *(int *)(*(int *)((int)param_1 + 4) + 4) = *(int *)((int)param_1 + 4);
  *(undefined4 *)*(undefined4 *)((int)param_1 + 4) = *(undefined4 *)((int)param_1 + 4);
  *(int *)(*(int *)((int)param_1 + 4) + 8) = *(int *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1000a761 at 1000a761

void __thiscall FUN_1000a761(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)((int)this + 4)) && (param_3 == *(int **)((int)this + 4))) {
    FUN_1000a73a(this);
    param_2 = (int *)**(undefined4 **)((int)this + 4);
  }
  else if (param_2 != param_3) {
    do {
      piVar1 = param_2;
      FUN_100034ae((int *)&param_2);
      FUN_1000a23c(this,&local_8,piVar1);
    } while (param_2 != param_3);
  }
  *param_1 = param_2;
  return;
}



// Function: FUN_1000a7b4 at 1000a7b4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a7b4(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_1000a761(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000a7ee at 1000a7ee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a7ee(void *param_1)

{
  undefined4 local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  local_14 = param_1;
  FUN_10008cff(param_1,&local_18,(int *)**(int **)((int)param_1 + 4),*(int **)((int)param_1 + 4));
  local_8 = 0xffffffff;
  operator_delete(*(void **)((int)param_1 + 4));
  return;
}



// Function: FUN_1000a828 at 1000a828

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a828(void *param_1)

{
  FUN_1000a7b4(param_1);
  return;
}



// Function: FUN_1000a846 at 1000a846

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_1000a846(int param_1)

{
  int *piVar1;
  int *local_34;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x1000a852;
  FUN_10007d31(local_30,L"{89F5ADE7-D20B-42E7-B980-5150ECB44F11}");
  local_8 = 0;
  piVar1 = (int *)FUN_100091b8((void *)(param_1 + 0x14),local_30);
  piVar1 = (int *)*piVar1;
  local_34 = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  FID_conflict__Tidy(local_30,'\x01',0);
  FUN_10009ea9(&local_34,1,0);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_1000a8b4 at 1000a8b4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_1000a8b4(void *this,undefined4 param_1)

{
  int *piVar1;
  undefined2 local_44 [4];
  undefined4 local_3c;
  int *local_34;
  ushort local_30 [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x1000a8c0;
  FUN_10007d31(local_30,L"{89F5ADE7-D20B-42E7-B980-5150ECB44F11}");
  local_8 = 0;
  piVar1 = (int *)FUN_100091b8((void *)((int)this + 0x14),local_30);
  piVar1 = (int *)*piVar1;
  local_34 = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  local_8._0_1_ = 4;
  FID_conflict__Tidy(local_30,'\x01',0);
  local_44[0] = 3;
  local_3c = param_1;
  local_8._0_1_ = 5;
  FUN_10009ee1(&local_34,2,local_44,0);
  local_8 = CONCAT31(local_8._1_3_,4);
  Ordinal_9(local_44);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000b1dd();
  return;
}



// Function: FUN_1000a947 at 1000a947

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000a947(int param_1)

{
  int aiStack_30 [5];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x1000a953;
  local_1c = (undefined1 *)aiStack_30;
  aiStack_30[0] = param_1;
  local_18 = param_1;
  FUN_1000a173(param_1);
  return local_18;
}



// Function: FUN_1000a973 at 1000a973

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000a973(void *param_1)

{
  FUN_1000a7ee(param_1);
  return;
}



// Function: FUN_1000a991 at 1000a991

int FUN_1000a991(int *param_1,undefined4 param_2)

{
  int *this;
  char cVar1;
  void *this_00;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_18;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  this = param_1 + -1;
  local_8 = -0x7fffbffb;
  FUN_10009f26((int)this);
  this_00 = (void *)FUN_1000211d();
  if (this_00 == (void *)0x0) {
    local_8 = 1;
  }
  else {
    puVar2 = (undefined4 *)FUN_100012ba((int)this_00);
    if (puVar2 != (undefined4 *)0x0) {
      param_1 = (int *)0x0;
      iVar3 = (**(code **)*puVar2)(puVar2,&DAT_1000e3c8,&param_1);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*param_1 + 0x1c))(param_1);
        if (iVar3 == 0) {
          local_8 = 0;
        }
        (**(code **)(*param_1 + 8))(param_1);
      }
      else {
        local_10 = 0xffffffff;
        local_18 = 0;
        local_14 = 0x100;
        local_c = 0;
        FUN_10001122(this_00,&local_18);
        if ((char)local_14 != '\0') {
          cVar1 = FUN_100011af((int)this_00);
          if (cVar1 != '\0') {
            local_8 = 0;
          }
        }
      }
    }
  }
  FUN_10009f32((int)this);
  if (local_8 == 0) {
    FUN_1000a8b4(this,param_2);
  }
  return local_8;
}



// Function: FUN_1000aa53 at 1000aa53

int FUN_1000aa53(int *param_1,int param_2)

{
  int *this;
  char cVar1;
  void *this_00;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_18;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = -0x7fffbffb;
  if (param_2 == 0) {
    local_8 = -0x7fffbffd;
  }
  else {
    this = param_1 + -1;
    FUN_10009f26((int)this);
    this_00 = (void *)FUN_1000211d();
    if ((this_00 != (void *)0x0) &&
       (puVar2 = (undefined4 *)FUN_100012ba((int)this_00), puVar2 != (undefined4 *)0x0)) {
      param_1 = (int *)0x0;
      iVar3 = (**(code **)*puVar2)(puVar2,&DAT_1000e3c8,&param_1);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*param_1 + 0x20))(param_1);
        if (iVar3 == 0) {
          local_8 = 0;
        }
        (**(code **)(*param_1 + 8))(param_1);
      }
      else {
        local_10 = 0xffffffff;
        local_18 = 0;
        local_14 = 0x100;
        local_c = 0;
        FUN_10001122(this_00,&local_18);
        if (((char)local_14 != '\0') && (cVar1 = FUN_100011de((int)this_00), cVar1 != '\0')) {
          local_8 = 0;
        }
      }
    }
    FUN_10009f32((int)this);
    if (-1 < local_8) {
      FUN_1000a8b4(this,param_2);
    }
  }
  return local_8;
}



// Function: FUN_1000ab1b at 1000ab1b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000ab1b(int param_1)

{
  FUN_10009406(param_1 + 4);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  return param_1;
}



// Function: FUN_1000ab54 at 1000ab54

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ab54(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000a7ee((void *)(param_1 + 4));
  return;
}



// Function: FUN_1000ab98 at 1000ab98

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_1000ab98(int param_1)

{
  HANDLE pvVar1;
  void *this;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_10003112((void *)(param_1 + 0x30));
  FUN_1000ab1b(param_1 + 0x10);
  FUN_1000a947(param_1 + 0x4c);
  FUN_1000a947(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,1,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 0x70) = pvVar1;
  this = operator_new(0x10);
  if (this == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_10001605(this,*(undefined4 *)(param_1 + 0x70));
  }
  *(undefined4 *)(param_1 + 0x6c) = uVar2;
  FUN_10009f32(param_1);
  return param_1;
}



// Function: FUN_1000ac33 at 1000ac33

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_1000ac33(int param_1)

{
  void *pvVar1;
  
  FUN_10009f26(param_1);
  pvVar1 = *(void **)(param_1 + 0x6c);
  if (pvVar1 != (void *)0x0) {
    FUN_10001d3d();
    operator_delete(pvVar1);
  }
  FUN_10009f32(param_1);
  CloseHandle(*(HANDLE *)(param_1 + 0x70));
  FUN_1000a7b4((void *)(param_1 + 0x5c));
  FUN_1000a7b4((void *)(param_1 + 0x4c));
  FUN_1000ab54(param_1 + 0x10);
  FUN_1000305d((LPCRITICAL_SECTION)(param_1 + 0x30));
  return;
}



// Function: FUN_1000acc3 at 1000acc3

int FUN_1000acc3(int param_1,int *param_2,uint *param_3)

{
  wchar_t *pwVar1;
  char cVar2;
  void *pvVar3;
  size_t sVar4;
  int local_8;
  
  local_8 = -0x7fffbffb;
  if ((param_2 == (int *)0x0) || (param_3 == (uint *)0x0)) {
    local_8 = -0x7fffbffd;
  }
  else {
    FUN_10009f26(param_1 + -4);
    cVar2 = FUN_100023d0(*(void **)(param_1 + 0x68),param_2,param_3);
    if (cVar2 != '\0') {
      local_8 = 0;
    }
    FUN_10009f32(param_1 + -4);
  }
  if (-1 < local_8) {
    FUN_1000a846(param_1 + -4);
    pwVar1 = (wchar_t *)param_2[4];
    if (pwVar1 != (wchar_t *)0x0) {
      pvVar3 = (void *)FUN_1000962b((void *)(param_1 + 0x48),param_3);
      sVar4 = wcslen(pwVar1);
      FID_conflict_assign(pvVar3,(undefined4 *)pwVar1,sVar4);
      pwVar1 = (wchar_t *)param_2[3];
      pvVar3 = (void *)FUN_1000962b((void *)(param_1 + 0x58),param_3);
      sVar4 = wcslen(pwVar1);
      FID_conflict_assign(pvVar3,(undefined4 *)pwVar1,sVar4);
    }
  }
  return local_8;
}



// Function: FUN_1000ad71 at 1000ad71

int FUN_1000ad71(int param_1,int *param_2,int *param_3,uint *param_4)

{
  wchar_t *pwVar1;
  char cVar2;
  void *pvVar3;
  size_t sVar4;
  int local_8;
  
  local_8 = -0x7fffbffb;
  if ((param_3 == (int *)0x0) || (param_4 == (uint *)0x0)) {
    local_8 = -0x7fffbffd;
  }
  else {
    FUN_10009f26(param_1 + -4);
    *param_3 = (int)param_2;
    (**(code **)(*param_2 + 4))(param_2);
    cVar2 = FUN_100023d0(*(void **)(param_1 + 0x68),param_3,param_4);
    if (cVar2 != '\0') {
      local_8 = 0;
    }
    FUN_10009f32(param_1 + -4);
  }
  if (-1 < local_8) {
    FUN_1000a846(param_1 + -4);
    pwVar1 = (wchar_t *)param_3[4];
    if ((pwVar1 != (wchar_t *)0x0) && (pwVar1 != (wchar_t *)0xcccccccc)) {
      pvVar3 = (void *)FUN_1000962b((void *)(param_1 + 0x48),param_4);
      sVar4 = wcslen(pwVar1);
      FID_conflict_assign(pvVar3,(undefined4 *)pwVar1,sVar4);
      pwVar1 = (wchar_t *)param_3[3];
      pvVar3 = (void *)FUN_1000962b((void *)(param_1 + 0x58),param_4);
      sVar4 = wcslen(pwVar1);
      FID_conflict_assign(pvVar3,(undefined4 *)pwVar1,sVar4);
    }
  }
  return local_8;
}



// Function: FUN_1000ae32 at 1000ae32

int FUN_1000ae32(int *param_1,uint param_2)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  size_t sVar6;
  undefined4 local_18;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  piVar1 = param_1;
  local_8 = -0x7fffbffb;
  FUN_10009f26((int)(param_1 + -1));
  pvVar3 = (void *)FUN_1000211d();
  if (pvVar3 == (void *)0x0) {
    local_8 = 1;
  }
  else {
    puVar4 = (undefined4 *)FUN_100012ba((int)pvVar3);
    if (puVar4 != (undefined4 *)0x0) {
      param_1 = (int *)0x0;
      iVar5 = (**(code **)*puVar4)(puVar4,&DAT_1000e3c8,&param_1);
      if (iVar5 == 0) {
        iVar5 = (**(code **)(*param_1 + 0x24))(param_1);
        if (iVar5 == 0) {
          cVar2 = FUN_100021ec();
          if (cVar2 != '\0') {
            local_8 = 0;
          }
        }
        (**(code **)(*param_1 + 8))(param_1);
      }
      else {
        local_18 = 0;
        local_10 = 0xffffffff;
        local_c = 0;
        local_14 = 0x100;
        FUN_10001122(pvVar3,&local_18);
        if ((char)local_14 != '\0') {
          cVar2 = FUN_100021ec();
          if (cVar2 != '\0') {
            local_8 = 0;
          }
        }
      }
    }
  }
  FUN_10009f32((int)(piVar1 + -1));
  if (local_8 == 0) {
    FUN_1000a846((int)(piVar1 + -1));
    param_1 = (int *)FUN_1000962b(piVar1 + 0x12,&param_2);
    sVar6 = wcslen(L"");
    FID_conflict_assign(param_1,(undefined4 *)&DAT_1000ea20,sVar6);
    pvVar3 = (void *)FUN_1000962b(piVar1 + 0x16,&param_2);
    sVar6 = wcslen(L"");
    FID_conflict_assign(pvVar3,(undefined4 *)&DAT_1000ea20,sVar6);
  }
  return local_8;
}



// Function: FUN_1000af4f at 1000af4f

void __fastcall FUN_1000af4f(int *param_1)

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



// Function: FUN_1000af93 at 1000af93

int __fastcall FUN_1000af93(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1000afac at 1000afac

undefined4 * __fastcall FUN_1000afac(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000af93((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &DAT_10011ec0;
  param_1[3] = &DAT_10011ec0;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 4));
  if (lVar1 < 0) {
    DAT_10013c68 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1000afed at 1000afed

void __fastcall FUN_1000afed(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1000b00c at 1000b00c

int __fastcall FUN_1000b00c(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1000b031 at 1000b031

void __fastcall FUN_1000b031(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1000afed((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: FUN_1000b049 at 1000b049

undefined4 * __fastcall FUN_1000b049(undefined4 *param_1)

{
  long lVar1;
  
  FUN_1000b00c((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1000ee90;
  lVar1 = ATL::CComCriticalSection::Init((CComCriticalSection *)(param_1 + 5));
  if (lVar1 < 0) {
    DAT_10013c68 = 1;
  }
  return param_1;
}



// Function: FID_conflict:`vector_deleting_destructor' at 1000b090

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



// Function: __security_check_cookie at 1000b0e2

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10013c58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __EH_prolog3 at 1000b0f1

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10013c58 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch at 1000b124

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10013c58 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_GS at 1000b15a

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10013c58 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_prolog3_catch_GS at 1000b190

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10013c58 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 1000b1c9

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



// Function: FUN_1000b1dd at 1000b1dd

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000b1dd(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x10) ^ unaff_EBP);
  return;
}



// Function: FUN_1000b1ec at 1000b1ec

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000b1ec(void)

{
  uint unaff_EBP;
  
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: __ArrayUnwind at 1000b202

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



// Function: `eh_vector_destructor_iterator' at 1000b260

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
  FUN_1000b2ab();
  return;
}



// Function: FUN_1000b2ab at 1000b2ab

void FUN_1000b2ab(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 1000b2dc

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
  
  local_8 = &DAT_10011e38;
  uStack_c = 0x1000b2e8;
  local_20[0] = DecodePointer(DAT_1001419c);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_1001419c);
    local_24 = DecodePointer(DAT_10014198);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_1001419c = EncodePointer(local_20[0]);
    DAT_10014198 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1000b374();
  }
  return p_Var1;
}



// Function: FUN_1000b374 at 1000b374

void FUN_1000b374(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1000b37d

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe at 1000b3b0

/* WARNING: This is an inlined function */

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



// Function: `eh_vector_constructor_iterator' at 1000b3db

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
  FUN_1000b428();
  return;
}



// Function: FUN_1000b428 at 1000b428

void FUN_1000b428(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __CRT_INIT@12 at 1000b49a

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
    if (DAT_10013e5c < 1) {
      return 0;
    }
    DAT_10013e5c = DAT_10013e5c + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10014190,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1001418c == 2) {
      param_2 = (int *)DecodePointer(DAT_1001419c);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10014198);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_1001419c);
            piVar8 = (int *)DecodePointer(DAT_10014198);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10014198 = (PVOID)encoded_null();
        DAT_1001419c = DAT_10014198;
      }
      DAT_1001418c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10014190,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10014190,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_1001418c == 0) {
      DAT_1001418c = 1;
      iVar5 = initterm_e(&DAT_1000e228,&DAT_1000e230);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_1000e1f0,&DAT_1000e224);
      DAT_1001418c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10014190,0);
    }
    if ((DAT_10014194 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10014194), BVar2 != 0)) {
      (*DAT_10014194)(param_1,2,param_3);
    }
    DAT_10013e5c = DAT_10013e5c + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1000b6a4

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1000b744) */
/* WARNING: Removing unreachable block (ram,0x1000b6f1) */
/* WARNING: Removing unreachable block (ram,0x1000b771) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10013c60 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10013e5c == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_100049b5(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_100049b5(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1000b7af();
  return local_20;
}



// Function: FUN_1000b7af at 1000b7af

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000b7af(void)

{
  _DAT_10013c60 = 0xffffffff;
  return;
}



// Function: entry at 1000b7ba

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 1000b7dd

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
  
  _DAT_10013f78 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10013f7c = &stack0x00000004;
  _DAT_10013eb8 = 0x10001;
  _DAT_10013e60 = 0xc0000409;
  _DAT_10013e64 = 1;
  local_32c = DAT_10013c58;
  local_328 = DAT_10013c5c;
  _DAT_10013e6c = unaff_retaddr;
  _DAT_10013f44 = in_GS;
  _DAT_10013f48 = in_FS;
  _DAT_10013f4c = in_ES;
  _DAT_10013f50 = in_DS;
  _DAT_10013f54 = unaff_EDI;
  _DAT_10013f58 = unaff_ESI;
  _DAT_10013f5c = unaff_EBX;
  _DAT_10013f60 = in_EDX;
  _DAT_10013f64 = in_ECX;
  _DAT_10013f68 = in_EAX;
  _DAT_10013f6c = unaff_EBP;
  DAT_10013f70 = unaff_retaddr;
  _DAT_10013f74 = in_CS;
  _DAT_10013f80 = in_SS;
  DAT_10013eb0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1000eeac);
  if (DAT_10013eb0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1000b8f0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10013c58 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1000b935

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



// Function: FUN_1000b949 at 1000b949

void __cdecl
FUN_1000b949(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_10013c58,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}



// Function: __ValidateImageBase at 1000b9e0

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



// Function: __FindPESection at 1000ba20

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



// Function: __IsNonwritableInCurrentImage at 1000ba70

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
  
  pcStack_10 = FUN_1000b949;
  local_14 = ExceptionList;
  local_c = DAT_10013c58 ^ 0x10011ea0;
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



// Function: ___security_init_cookie at 1000bb44

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
  if ((DAT_10013c58 == 0xbb40e64e) || ((DAT_10013c58 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10013c58 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10013c58 == 0xbb40e64e) {
      DAT_10013c58 = 0xbb40e64f;
    }
    else if ((DAT_10013c58 & 0xffff0000) == 0) {
      DAT_10013c58 = DAT_10013c58 | (DAT_10013c58 | 0x4711) << 0x10;
    }
    DAT_10013c5c = ~DAT_10013c58;
  }
  else {
    DAT_10013c5c = ~DAT_10013c58;
  }
  return;
}



// Function: Unwind@1000bbf8 at 1000bbf8

void Unwind_1000bbf8(void)

{
  int unaff_EBP;
  
  FUN_10001000(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bc36 at 1000bc36

void Unwind_1000bc36(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000bc39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bd17 at 1000bd17

void Unwind_1000bd17(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000bd3c at 1000bd3c

void Unwind_1000bd3c(void)

{
  int unaff_EBP;
  
  FUN_1000412a(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bd5f at 1000bd5f

void Unwind_1000bd5f(void)

{
  int unaff_EBP;
  
  FUN_1000412a(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000bd67 at 1000bd67

void Unwind_1000bd67(void)

{
  int unaff_EBP;
  
  FUN_1000249b(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000bd8a at 1000bd8a

void Unwind_1000bd8a(void)

{
  FUN_1000249b(&DAT_10013c90);
  return;
}



// Function: Unwind@1000bdaf at 1000bdaf

void Unwind_1000bdaf(void)

{
  DAT_10013cc8 = DAT_10013cc8 & 0xfffffffe;
  return;
}



// Function: Unwind@1000bdd8 at 1000bdd8

void Unwind_1000bdd8(void)

{
  int unaff_EBP;
  
  FUN_1000276a(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bdfb at 1000bdfb

void Unwind_1000bdfb(void)

{
  int unaff_EBP;
  
  FUN_1000ac33(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000be1e at 1000be1e

void Unwind_1000be1e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1000be21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000be42 at 1000be42

void Unwind_1000be42(void)

{
  int unaff_EBP;
  
  FUN_10003980(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000be65 at 1000be65

void Unwind_1000be65(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000be98 at 1000be98

void Unwind_1000be98(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1000becb at 1000becb

void Unwind_1000becb(void)

{
  int unaff_EBP;
  
  FUN_10003050(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000beee at 1000beee

void Unwind_1000beee(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bf11 at 1000bf11

void Unwind_1000bf11(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000bf1b at 1000bf1b

void Unwind_1000bf1b(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000bf3e at 1000bf3e

void Unwind_1000bf3e(void)

{
  int unaff_EBP;
  
  FUN_1000305d((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000bf64 at 1000bf64

void Unwind_1000bf64(void)

{
  FUN_10001604();
  return;
}



// Function: Unwind@1000bf7b at 1000bf7b

void Unwind_1000bf7b(void)

{
  FUN_10001604();
  return;
}



// Function: Unwind@1000bfae at 1000bfae

void Unwind_1000bfae(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000bfb6 at 1000bfb6

void Unwind_1000bfb6(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000bfbe at 1000bfbe

void Unwind_1000bfbe(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bfc6 at 1000bfc6

void Unwind_1000bfc6(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bfce at 1000bfce

void Unwind_1000bfce(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000bfd6 at 1000bfd6

void Unwind_1000bfd6(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c014 at 1000c014

void Unwind_1000c014(void)

{
  int unaff_EBP;
  
  FUN_100033c2(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000c03a at 1000c03a

void Unwind_1000c03a(void)

{
  int unaff_EBP;
  
  FUN_100033c2(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@1000c045 at 1000c045

void Unwind_1000c045(void)

{
  int unaff_EBP;
  
  FUN_1000ac33(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c068 at 1000c068

void Unwind_1000c068(void)

{
  int unaff_EBP;
  
  FUN_10003980(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c070 at 1000c070

void Unwind_1000c070(void)

{
  int unaff_EBP;
  
  FUN_10003985(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c093 at 1000c093

void Unwind_1000c093(void)

{
  int unaff_EBP;
  
  FUN_10003985(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c09b at 1000c09b

void Unwind_1000c09b(void)

{
  int unaff_EBP;
  
  FUN_10003980(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c0be at 1000c0be

void Unwind_1000c0be(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003023(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c0e1 at 1000c0e1

void Unwind_1000c0e1(void)

{
  int unaff_EBP;
  
  FUN_10004674((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c107 at 1000c107

void Unwind_1000c107(void)

{
  int unaff_EBP;
  
  FUN_10002b2a(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1000c134 at 1000c134

void Unwind_1000c134(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000c13f at 1000c13f

void Unwind_1000c13f(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000c14a at 1000c14a

void Unwind_1000c14a(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000c155 at 1000c155

void Unwind_1000c155(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000c160 at 1000c160

void Unwind_1000c160(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000c16b at 1000c16b

void Unwind_1000c16b(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1000c176 at 1000c176

void Unwind_1000c176(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1000c181 at 1000c181

void Unwind_1000c181(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x1b8));
  return;
}



// Function: Unwind@1000c18c at 1000c18c

void Unwind_1000c18c(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000c197 at 1000c197

void Unwind_1000c197(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1000c1ca at 1000c1ca

void Unwind_1000c1ca(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c1d2 at 1000c1d2

void Unwind_1000c1d2(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c1da at 1000c1da

void Unwind_1000c1da(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c1e2 at 1000c1e2

void Unwind_1000c1e2(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c1ea at 1000c1ea

void Unwind_1000c1ea(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c20d at 1000c20d

void Unwind_1000c20d(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000c218 at 1000c218

void Unwind_1000c218(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c223 at 1000c223

void Unwind_1000c223(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c22e at 1000c22e

void Unwind_1000c22e(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c239 at 1000c239

void Unwind_1000c239(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c244 at 1000c244

void Unwind_1000c244(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c277 at 1000c277

void Unwind_1000c277(void)

{
  int unaff_EBP;
  
  FUN_10004088((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c29a at 1000c29a

void Unwind_1000c29a(void)

{
  int unaff_EBP;
  
  FUN_10004088((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c2bd at 1000c2bd

void Unwind_1000c2bd(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c2c5 at 1000c2c5

void Unwind_1000c2c5(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c2cd at 1000c2cd

void Unwind_1000c2cd(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000c2d5 at 1000c2d5

void Unwind_1000c2d5(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c2f8 at 1000c2f8

void Unwind_1000c2f8(void)

{
  int unaff_EBP;
  
  FUN_10004013(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000c303 at 1000c303

void Unwind_1000c303(void)

{
  int unaff_EBP;
  
  FUN_1000305d((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c329 at 1000c329

void Unwind_1000c329(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c34e at 1000c34e

void Unwind_1000c34e(void)

{
  int unaff_EBP;
  
  FUN_1000305d((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000c359 at 1000c359

void Unwind_1000c359(void)

{
  int unaff_EBP;
  
  FUN_10004013(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1000c37f at 1000c37f

void Unwind_1000c37f(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c3bd at 1000c3bd

void Unwind_1000c3bd(void)

{
  int unaff_EBP;
  
  FUN_10003ff6((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c3c5 at 1000c3c5

void Unwind_1000c3c5(void)

{
  int unaff_EBP;
  
  FUN_10003ff6((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c3e8 at 1000c3e8

void Unwind_1000c3e8(void)

{
  int unaff_EBP;
  
  FUN_10004006((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000c3f3 at 1000c3f3

void Unwind_1000c3f3(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0x2120));
  return;
}



// Function: Unwind@1000c3fe at 1000c3fe

void Unwind_1000c3fe(void)

{
  int unaff_EBP;
  
  FUN_10004006((int *)(unaff_EBP + -0x2118));
  return;
}



// Function: Unwind@1000c431 at 1000c431

void Unwind_1000c431(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x2230));
  return;
}



// Function: Unwind@1000c43c at 1000c43c

void Unwind_1000c43c(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x2240));
  return;
}



// Function: Unwind@1000c447 at 1000c447

void Unwind_1000c447(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x2258));
  return;
}



// Function: Unwind@1000c452 at 1000c452

void Unwind_1000c452(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@1000c45d at 1000c45d

void Unwind_1000c45d(void)

{
  int unaff_EBP;
  
  FUN_100039a3((undefined4 *)(unaff_EBP + -0x224c));
  return;
}



// Function: Unwind@1000c490 at 1000c490

void Unwind_1000c490(void)

{
  int unaff_EBP;
  
  FUN_10004088((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1000c4b3 at 1000c4b3

void Unwind_1000c4b3(void)

{
  int unaff_EBP;
  
  FUN_10005435(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c4d6 at 1000c4d6

void Unwind_1000c4d6(void)

{
  int unaff_EBP;
  
  FUN_10004088((undefined4 *)(unaff_EBP + -0x238));
  return;
}



// Function: Unwind@1000c4e1 at 1000c4e1

void Unwind_1000c4e1(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c4ec at 1000c4ec

void Unwind_1000c4ec(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c4f7 at 1000c4f7

void Unwind_1000c4f7(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c502 at 1000c502

void Unwind_1000c502(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000c50d at 1000c50d

void Unwind_1000c50d(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000c518 at 1000c518

void Unwind_1000c518(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c523 at 1000c523

void Unwind_1000c523(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c52e at 1000c52e

void Unwind_1000c52e(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1000c539 at 1000c539

void Unwind_1000c539(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1000c544 at 1000c544

void Unwind_1000c544(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1000c577 at 1000c577

void Unwind_1000c577(void)

{
  int unaff_EBP;
  
  FUN_10005363(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c59a at 1000c59a

void Unwind_1000c59a(void)

{
  int unaff_EBP;
  
  FUN_10005668(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c5a2 at 1000c5a2

void Unwind_1000c5a2(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c5c5 at 1000c5c5

void Unwind_1000c5c5(void)

{
  int unaff_EBP;
  
  FUN_10005410(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c5cd at 1000c5cd

void Unwind_1000c5cd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c5f3 at 1000c5f3

void Unwind_1000c5f3(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1000c618 at 1000c618

void Unwind_1000c618(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000c63b at 1000c63b

void Unwind_1000c63b(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0x428));
  return;
}



// Function: Unwind@1000c646 at 1000c646

void Unwind_1000c646(void)

{
  int unaff_EBP;
  
  FUN_10004006((int *)(unaff_EBP + -0x418));
  return;
}



// Function: Unwind@1000c679 at 1000c679

void Unwind_1000c679(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c69c at 1000c69c

void Unwind_1000c69c(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003023(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000c6a7 at 1000c6a7

void Unwind_1000c6a7(void)

{
  int unaff_EBP;
  
  FUN_10004674((int *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000c6b2 at 1000c6b2

void Unwind_1000c6b2(void)

{
  int unaff_EBP;
  
  FUN_1000469e((undefined4 *)(unaff_EBP + -0xa5c));
  return;
}



// Function: Unwind@1000c6bd at 1000c6bd

void Unwind_1000c6bd(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000c6f0 at 1000c6f0

void Unwind_1000c6f0(void)

{
  int unaff_EBP;
  
  thunk_FUN_10003023(*(undefined4 **)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000c6fb at 1000c6fb

void Unwind_1000c6fb(void)

{
  int unaff_EBP;
  
  FUN_10004674((int *)(unaff_EBP + -0xa54));
  return;
}



// Function: Unwind@1000c706 at 1000c706

void Unwind_1000c706(void)

{
  int unaff_EBP;
  
  FUN_1000469e((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1000c711 at 1000c711

void Unwind_1000c711(void)

{
  int unaff_EBP;
  
  FUN_10003009((int *)(unaff_EBP + -0xa44));
  return;
}



// Function: Unwind@1000c744 at 1000c744

void Unwind_1000c744(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c74c at 1000c74c

void Unwind_1000c74c(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c754 at 1000c754

void Unwind_1000c754(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c75c at 1000c75c

void Unwind_1000c75c(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000c764 at 1000c764

void Unwind_1000c764(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000c7bd at 1000c7bd

void Unwind_1000c7bd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1000c7e3 at 1000c7e3

void Unwind_1000c7e3(void)

{
  int unaff_EBP;
  
  FUN_10005435(*(void **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1000c806 at 1000c806

void Unwind_1000c806(void)

{
  int unaff_EBP;
  
  FUN_10005668(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c829 at 1000c829

void Unwind_1000c829(void)

{
  int unaff_EBP;
  
  ~basic_string<>(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c831 at 1000c831

void Unwind_1000c831(void)

{
  int unaff_EBP;
  
  FUN_1000384c(*(int *)(unaff_EBP + -0x10) + 0x20);
  return;
}



// Function: Unwind@1000c857 at 1000c857

void Unwind_1000c857(void)

{
  int unaff_EBP;
  
  FUN_10005806((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000c884 at 1000c884

void Unwind_1000c884(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000c8aa at 1000c8aa

void Unwind_1000c8aa(void)

{
  int unaff_EBP;
  
  FUN_10005410(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000c903 at 1000c903

void Unwind_1000c903(void)

{
  FUN_10001604();
  return;
}



// Function: Unwind@1000c92c at 1000c92c

void Unwind_1000c92c(void)

{
  int unaff_EBP;
  
  FUN_10003524((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000c94f at 1000c94f

void Unwind_1000c94f(void)

{
  int unaff_EBP;
  
  FUN_10003524((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1000c957 at 1000c957

void Unwind_1000c957(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1000c97a at 1000c97a

void Unwind_1000c97a(void)

{
  int unaff_EBP;
  
  FUN_10003524((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1000c99d at 1000c99d

void Unwind_1000c99d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000c9a5 at 1000c9a5

void Unwind_1000c9a5(void)

{
  int unaff_EBP;
  
  FUN_10005668((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000c9ad at 1000c9ad

void Unwind_1000c9ad(void)

{
  int unaff_EBP;
  
  FUN_100068f1((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000c9b5 at 1000c9b5

void Unwind_1000c9b5(void)

{
  int unaff_EBP;
  
  FUN_10005668((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000c9bd at 1000c9bd

void Unwind_1000c9bd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000c9ea at 1000c9ea

void Unwind_1000c9ea(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x54);
  return;
}



// Function: Unwind@1000c9f2 at 1000c9f2

void Unwind_1000c9f2(void)

{
  int unaff_EBP;
  
  FUN_10005435((void *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000c9fa at 1000c9fa

void Unwind_1000c9fa(void)

{
  int unaff_EBP;
  
  FUN_10006533((void *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000ca02 at 1000ca02

void Unwind_1000ca02(void)

{
  int unaff_EBP;
  
  FUN_10005435((void *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1000ca80 at 1000ca80

void Unwind_1000ca80(void)

{
  int unaff_EBP;
  
  FUN_100092be(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000caa3 at 1000caa3

void Unwind_1000caa3(void)

{
  int unaff_EBP;
  
  FUN_1000412a(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000caab at 1000caab

void Unwind_1000caab(void)

{
  int unaff_EBP;
  
  FUN_1000a7ee(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cace at 1000cace

void Unwind_1000cace(void)

{
  int unaff_EBP;
  
  FUN_1000412a(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cad6 at 1000cad6

void Unwind_1000cad6(void)

{
  int unaff_EBP;
  
  FUN_100092be(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000caf9 at 1000caf9

void Unwind_1000caf9(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cb26 at 1000cb26

void Unwind_1000cb26(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cb2e at 1000cb2e

void Unwind_1000cb2e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cb36 at 1000cb36

void Unwind_1000cb36(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cb3e at 1000cb3e

void Unwind_1000cb3e(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000cb46 at 1000cb46

void Unwind_1000cb46(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000cb4e at 1000cb4e

void Unwind_1000cb4e(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cb56 at 1000cb56

void Unwind_1000cb56(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cb5e at 1000cb5e

void Unwind_1000cb5e(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000cb8b at 1000cb8b

void Unwind_1000cb8b(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cb93 at 1000cb93

void Unwind_1000cb93(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000cb9b at 1000cb9b

void Unwind_1000cb9b(void)

{
  int unaff_EBP;
  
  FUN_10005410(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1000cba3 at 1000cba3

void Unwind_1000cba3(void)

{
  int unaff_EBP;
  
  FUN_1000650e(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1000cbab at 1000cbab

void Unwind_1000cbab(void)

{
  int unaff_EBP;
  
  FUN_10005410(unaff_EBP + -0x4c);
  return;
}



// Function: Unwind@1000cbb3 at 1000cbb3

void Unwind_1000cbb3(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1000cbe0 at 1000cbe0

void Unwind_1000cbe0(void)

{
  int unaff_EBP;
  
  FUN_1000a973((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cbe8 at 1000cbe8

void Unwind_1000cbe8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cbf0 at 1000cbf0

void Unwind_1000cbf0(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cbf8 at 1000cbf8

void Unwind_1000cbf8(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cc00 at 1000cc00

void Unwind_1000cc00(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cc08 at 1000cc08

void Unwind_1000cc08(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cc10 at 1000cc10

void Unwind_1000cc10(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x60);
  return;
}



// Function: Unwind@1000cc18 at 1000cc18

void Unwind_1000cc18(void)

{
  int unaff_EBP;
  
  FUN_1000a7ee((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cc45 at 1000cc45

void Unwind_1000cc45(void)

{
  int unaff_EBP;
  
  FUN_100093e8((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cc4d at 1000cc4d

void Unwind_1000cc4d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cc55 at 1000cc55

void Unwind_1000cc55(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000cc5d at 1000cc5d

void Unwind_1000cc5d(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1000cc65 at 1000cc65

void Unwind_1000cc65(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cc6d at 1000cc6d

void Unwind_1000cc6d(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000cc75 at 1000cc75

void Unwind_1000cc75(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1000cc7d at 1000cc7d

void Unwind_1000cc7d(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cc85 at 1000cc85

void Unwind_1000cc85(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000cc8d at 1000cc8d

void Unwind_1000cc8d(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1000cc95 at 1000cc95

void Unwind_1000cc95(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cc9d at 1000cc9d

void Unwind_1000cc9d(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000cca5 at 1000cca5

void Unwind_1000cca5(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1000ccad at 1000ccad

void Unwind_1000ccad(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ccb5 at 1000ccb5

void Unwind_1000ccb5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ccbd at 1000ccbd

void Unwind_1000ccbd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ccc5 at 1000ccc5

void Unwind_1000ccc5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cccd at 1000cccd

void Unwind_1000cccd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ccd5 at 1000ccd5

void Unwind_1000ccd5(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ccdd at 1000ccdd

void Unwind_1000ccdd(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cce5 at 1000cce5

void Unwind_1000cce5(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x88);
  return;
}



// Function: Unwind@1000ccf0 at 1000ccf0

void Unwind_1000ccf0(void)

{
  int unaff_EBP;
  
  FUN_100092be((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1000cd20 at 1000cd20

void Unwind_1000cd20(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000cd28 at 1000cd28

void Unwind_1000cd28(void)

{
  int unaff_EBP;
  
  FUN_10001000((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1000cd30 at 1000cd30

void Unwind_1000cd30(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000cd5d at 1000cd5d

void Unwind_1000cd5d(void)

{
  FUN_10003985(0x10013d3c);
  return;
}



// Function: Unwind@1000cd67 at 1000cd67

void Unwind_1000cd67(void)

{
  FUN_10003980(0x10013d3c);
  return;
}



// Function: Unwind@1000cd8c at 1000cd8c

void Unwind_1000cd8c(void)

{
  int unaff_EBP;
  
  FUN_10003d1f(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cd94 at 1000cd94

void Unwind_1000cd94(void)

{
  int unaff_EBP;
  
  FUN_10003050(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cdb7 at 1000cdb7

void Unwind_1000cdb7(void)

{
  DAT_10013d88 = DAT_10013d88 & 0xfffffffe;
  return;
}



// Function: Unwind@1000cde0 at 1000cde0

void Unwind_1000cde0(void)

{
  int unaff_EBP;
  
  FUN_1000a7b4(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000ce03 at 1000ce03

void Unwind_1000ce03(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ce0b at 1000ce0b

void Unwind_1000ce0b(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce13 at 1000ce13

void Unwind_1000ce13(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce1b at 1000ce1b

void Unwind_1000ce1b(void)

{
  int unaff_EBP;
  
  FUN_1000a14e((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce23 at 1000ce23

void Unwind_1000ce23(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce2b at 1000ce2b

void Unwind_1000ce2b(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce58 at 1000ce58

void Unwind_1000ce58(void)

{
  int unaff_EBP;
  
  ~basic_string<>((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1000ce60 at 1000ce60

void Unwind_1000ce60(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce68 at 1000ce68

void Unwind_1000ce68(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce70 at 1000ce70

void Unwind_1000ce70(void)

{
  int unaff_EBP;
  
  FUN_1000a14e((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce78 at 1000ce78

void Unwind_1000ce78(void)

{
  int unaff_EBP;
  
  FUN_1000384c(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@1000ce80 at 1000ce80

void Unwind_1000ce80(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ce88 at 1000ce88

void Unwind_1000ce88(void)

{
  int unaff_EBP;
  
  FUN_10003050((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1000ceb5 at 1000ceb5

void Unwind_1000ceb5(void)

{
  int unaff_EBP;
  
  FUN_1000412a(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cebd at 1000cebd

void Unwind_1000cebd(void)

{
  int unaff_EBP;
  
  FUN_1000a7b4(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cee0 at 1000cee0

void Unwind_1000cee0(void)

{
  int unaff_EBP;
  
  FUN_1000a7ee(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1000cf03 at 1000cf03

void Unwind_1000cf03(void)

{
  int unaff_EBP;
  
  FUN_1000a973((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000cf0e at 1000cf0e

void Unwind_1000cf0e(void)

{
  int unaff_EBP;
  
  FUN_10003050(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf16 at 1000cf16

void Unwind_1000cf16(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1000cf3c at 1000cf3c

void Unwind_1000cf3c(void)

{
  int unaff_EBP;
  
  FUN_1000a973((void *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1000cf47 at 1000cf47

void Unwind_1000cf47(void)

{
  int unaff_EBP;
  
  FUN_10003d1f((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1000cf52 at 1000cf52

void Unwind_1000cf52(void)

{
  int unaff_EBP;
  
  FUN_10003050(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf5a at 1000cf5a

void Unwind_1000cf5a(void)

{
  int unaff_EBP;
  
  FUN_1000a7ee(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cf7d at 1000cf7d

void Unwind_1000cf7d(void)

{
  int unaff_EBP;
  
  FUN_1000305d((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1000cf88 at 1000cf88

void Unwind_1000cf88(void)

{
  int unaff_EBP;
  
  FUN_10004013(*(int *)(unaff_EBP + -0x10) + 0x2c);
  return;
}



// Function: Unwind@1000cf93 at 1000cf93

void Unwind_1000cf93(void)

{
  int unaff_EBP;
  
  FUN_1000ab54(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000cf9e at 1000cf9e

void Unwind_1000cf9e(void)

{
  int unaff_EBP;
  
  FUN_1000a828((void *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000cfa9 at 1000cfa9

void Unwind_1000cfa9(void)

{
  int unaff_EBP;
  
  FUN_1000a828((void *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1000cfb4 at 1000cfb4

void Unwind_1000cfb4(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000cfd9 at 1000cfd9

void Unwind_1000cfd9(void)

{
  int unaff_EBP;
  
  FUN_10004013(*(int *)(unaff_EBP + -0x10) + 0x2c);
  return;
}



// Function: Unwind@1000cfe4 at 1000cfe4

void Unwind_1000cfe4(void)

{
  int unaff_EBP;
  
  FUN_1000ab54(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1000cfef at 1000cfef

void Unwind_1000cfef(void)

{
  int unaff_EBP;
  
  FUN_1000a828((void *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@1000cffa at 1000cffa

void Unwind_1000cffa(void)

{
  int unaff_EBP;
  
  FUN_1000a828((void *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1000d005 at 1000d005

void Unwind_1000d005(void)

{
  int unaff_EBP;
  
  FUN_1000a7b4(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d00d at 1000d00d

void Unwind_1000d00d(void)

{
  int unaff_EBP;
  
  FUN_1000a7b4(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1000d015 at 1000d015

void Unwind_1000d015(void)

{
  int unaff_EBP;
  
  FUN_1000305d((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: FUN_1000d16b at 1000d16b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1000d16b(void)

{
  FUN_1000249b(&DAT_10013c90);
  return;
}



// Function: FUN_1000d18b at 1000d18b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d18b(void)

{
  _DAT_10013d3c = ATL::CComModule::vftable;
  FUN_10003947(0x10013d3c);
  return;
}



// Function: FUN_1000d1b5 at 1000d1b5

void FUN_1000d1b5(void)

{
  FID_conflict__Tidy(&DAT_10013ccc,'\x01',0);
  return;
}



// Function: FUN_1000d1c4 at 1000d1c4

void FUN_1000d1c4(void)

{
  FID_conflict__Tidy(&DAT_10013ce8,'\x01',0);
  return;
}



// Function: FUN_1000d1d3 at 1000d1d3

void FUN_1000d1d3(void)

{
  FID_conflict__Tidy(&DAT_10013d04,'\x01',0);
  return;
}



// Function: FUN_1000d1e2 at 1000d1e2

void FUN_1000d1e2(void)

{
  FID_conflict__Tidy(&DAT_10013d20,'\x01',0);
  return;
}



// Function: FUN_1000d1f1 at 1000d1f1

void FUN_1000d1f1(void)

{
  FID_conflict__Tidy(&DAT_10013d8c,'\x01',0);
  return;
}



// Function: FUN_1000d200 at 1000d200

void FUN_1000d200(void)

{
  FID_conflict__Tidy(&DAT_10013da8,'\x01',0);
  return;
}



// Function: FUN_1000d20f at 1000d20f

void FUN_1000d20f(void)

{
  FID_conflict__Tidy(&DAT_10013dc4,'\x01',0);
  return;
}



// Function: FUN_1000d21e at 1000d21e

void FUN_1000d21e(void)

{
  FID_conflict__Tidy(&DAT_10013de0,'\x01',0);
  return;
}



// Function: FUN_1000d23c at 1000d23c

void FUN_1000d23c(void)

{
  FUN_1000af4f((int *)&DAT_10013dfc);
  return;
}



// Function: FUN_1000d246 at 1000d246

void FUN_1000d246(void)

{
  FUN_1000b031(0x10013e24);
  return;
}



