/*
 * Decompiled from: ActivityLog.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void FUN_10001000(int param_1)

{
  FUN_100025b0((int *)&DAT_10043ea8,0x65,param_1,(int *)0x0);
  return;
}



// Function: FUN_10001030 at 10001030

undefined4 FUN_10001030(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_10005fb0(&DAT_10043ea8,0x10043028,param_1,(undefined4 *)&DAT_1003696c);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_10006070(0x10043ea8);
  }
  return 1;
}



// Function: DllCanUnloadNow at 10001090

HRESULT DllCanUnloadNow(void)

{
  int iVar1;
  
                    /* 0x1090  1  DllCanUnloadNow */
  iVar1 = FUN_10002590(0x10043ea8);
  return (uint)(iVar1 != 0);
}



// Function: DllGetClassObject at 100010b0

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0x10b0  2  DllGetClassObject */
  iVar1 = FUN_100061b0(&DAT_10043ea8,(int *)rclsid,riid,(int *)ppv);
  return iVar1;
}



// Function: DllRegisterServer at 100010e0

void DllRegisterServer(void)

{
                    /* 0x10e0  3  DllRegisterServer */
  FUN_10006380(&DAT_10043ea8,1,(void *)0x0);
  return;
}



// Function: DllUnregisterServer at 10001100

void DllUnregisterServer(void)

{
                    /* 0x1100  4  DllUnregisterServer */
  FUN_10006a70(&DAT_10043ea8,1,(void *)0x0);
  return;
}



// Function: FUN_10001120 at 10001120

undefined4 FUN_10001120(void)

{
  return 0;
}



// Function: FUN_10001140 at 10001140

undefined4 FUN_10001140(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002cd7b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8._0_1_ = 1;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10001330(puVar1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar2 = FUN_100011e8();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@100011db at 100011db

undefined4 Catch_100011db(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100011ef;
}



// Function: FUN_100011e8 at 100011e8

undefined4 FUN_100011e8(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_10007330(*(void **)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + 8));
    FUN_10007040();
    uVar1 = FUN_10001310(*(int *)(unaff_EBP + -0x18) + 4);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_10006db0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_10006dd0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    FUN_10007060();
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



// Function: FUN_100012c0 at 100012c0

undefined4 FUN_100012c0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_48;
  
  if (param_1 == 0) {
    local_48 = FUN_10001480(0,param_2,param_3);
  }
  else {
    local_48 = FUN_10001630(param_1,param_2,param_3);
  }
  return local_48;
}



// Function: FUN_10001310 at 10001310

void __fastcall FUN_10001310(int param_1)

{
  FUN_10002450((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_10001330 at 10001330

undefined4 * __fastcall FUN_10001330(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002cda8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10001870(param_1);
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100013a0 at 100013a0

int FUN_100013a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_100019d0((LONG *)(param_1 + 4));
  if (iVar1 == 2) {
    (**(code **)(*DAT_10043bb8 + 4))();
  }
  return iVar1;
}



// Function: FUN_100013e0 at 100013e0

int FUN_100013e0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10001a00(param_1 + 1);
  if (iVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (iVar1 == 1) {
    (**(code **)(*DAT_10043bb8 + 8))();
  }
  return iVar1;
}



// Function: FUN_10001450 at 10001450

void FUN_10001450(void *param_1,int *param_2,undefined4 *param_3)

{
  FUN_100071d0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10001480 at 10001480

undefined4 FUN_10001480(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002cdd0;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x150);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_10001a20(puVar1);
    }
    uVar2 = FUN_1000151d();
    return uVar2;
  }
  return 0x80004003;
}



// Function: Catch@10001510 at 10001510

undefined4 Catch_10001510(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10001524;
}



// Function: FUN_1000151d at 1000151d

undefined4 FUN_1000151d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_10007020();
    FUN_100015f0(*(int *)(unaff_EBP + -0x18));
    uVar1 = FUN_100071b0();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_10006db0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar1 = FUN_10006dd0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
    }
    FUN_10001610(*(int *)(unaff_EBP + -0x18));
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
        *(undefined4 *)(unaff_EBP + -0x68) = 0;
      }
      else {
        uVar1 = (**(code **)(**(int **)(unaff_EBP + -0x60) + 0x28))(1);
        *(undefined4 *)(unaff_EBP + -0x68) = uVar1;
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_100015f0 at 100015f0

void __fastcall FUN_100015f0(int param_1)

{
  FUN_10007100((int *)(param_1 + 8));
  return;
}



// Function: FUN_10001610 at 10001610

void __fastcall FUN_10001610(int param_1)

{
  FUN_10007160((int *)(param_1 + 8));
  return;
}



// Function: FUN_10001630 at 10001630

undefined4 FUN_10001630(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002cdfb;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    this = operator_new(0x158);
    local_8._0_1_ = 1;
    if (this != (void *)0x0) {
      FUN_10001ce0(this,param_1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    uVar1 = FUN_100016db();
    return uVar1;
  }
  return 0x80004003;
}



// Function: Catch@100016ce at 100016ce

undefined4 Catch_100016ce(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100016e2;
}



// Function: FUN_100016db at 100016db

undefined4 FUN_100016db(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_10007020();
    FUN_10007040();
    iVar1 = FUN_10001d80();
    *(int *)(unaff_EBP + -0x14) = iVar1;
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_10001dc0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    if (-1 < *(int *)(unaff_EBP + -0x14)) {
      uVar2 = FUN_10006dd0();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    }
    FUN_10007060();
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



// Function: FUN_100017b0 at 100017b0

undefined4 * __thiscall FUN_100017b0(void *this,uint param_1)

{
  FUN_100017f0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100017f0 at 100017f0

void __fastcall FUN_100017f0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002ce28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObjectCached<class_ATL::CComClassFactory>::vftable;
  local_8 = 0;
  param_1[1] = 0xc0000001;
  FUN_10006df0();
  local_8 = 0xffffffff;
  FUN_10007220(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001870 at 10001870

undefined4 * __fastcall FUN_10001870(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ce5b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100018e0(param_1);
  FUN_10001900(param_1 + 1);
  *param_1 = ATL::CComClassFactory::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100018e0 at 100018e0

undefined4 __fastcall FUN_100018e0(undefined4 param_1)

{
  FUN_100025e0(param_1);
  return param_1;
}



// Function: FUN_10001900 at 10001900

undefined4 * __fastcall FUN_10001900(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ce93;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10006d70(param_1);
  local_8 = 0;
  FUN_10001970(param_1 + 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001970 at 10001970

void * __fastcall FUN_10001970(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ceb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002310(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100019d0 at 100019d0

void __fastcall FUN_100019d0(LONG *param_1)

{
  FUN_10002500(param_1);
  return;
}



// Function: FUN_10001a00 at 10001a00

void __fastcall FUN_10001a00(LONG *param_1)

{
  FUN_10002520(param_1);
  return;
}



// Function: FUN_10001a20 at 10001a20

undefined4 * __fastcall FUN_10001a20(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002cee8;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000bb80((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CActivityLogImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CActivityLogImpl>::vftable;
  (**(code **)(*DAT_10043bb8 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10001aa0 at 10001aa0

void __fastcall FUN_10001aa0(int param_1)

{
  FUN_10001ac0(param_1);
  return;
}



// Function: FUN_10001ac0 at 10001ac0

void __fastcall FUN_10001ac0(int param_1)

{
  FUN_10001ae0(param_1);
  return;
}



// Function: FUN_10001ae0 at 10001ae0

undefined * __fastcall FUN_10001ae0(int param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_10001b00();
  return ppuVar1[1] + param_1;
}



// Function: FUN_10001b00 at 10001b00

undefined ** FUN_10001b00(void)

{
  return &PTR_DAT_10036bc8;
}



// Function: FUN_10001b20 at 10001b20

undefined4 FUN_10001b20(undefined4 param_1,undefined4 *param_2)

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



// Function: FUN_10001b50 at 10001b50

void FUN_10001b50(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  FUN_10007390(&PTR_DAT_10043358,param_2,param_3,param_4);
  return;
}



// Function: FUN_10001b80 at 10001b80

void FUN_10001b80(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10007450(&PTR_DAT_10043358,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10001bb0 at 10001bb0

void FUN_10001bb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  FUN_100075d0(&PTR_DAT_10043358,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
               param_9);
  return;
}



// Function: FUN_10001c00 at 10001c00

void FUN_10001c00(int param_1)

{
  FUN_10007100((int *)(param_1 + 8));
  return;
}



// Function: FUN_10001c20 at 10001c20

int FUN_10001c20(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10007160(param_1 + 2);
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x28))(1);
  }
  return iVar1;
}



// Function: FUN_10001c80 at 10001c80

void FUN_10001c80(void *param_1,int *param_2,undefined4 *param_3)

{
  FUN_10001cb0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10001cb0 at 10001cb0

void __thiscall FUN_10001cb0(void *this,int *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_10001b00();
  FUN_10006e30((int)this,(int *)ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_10001ce0 at 10001ce0

undefined4 * __thiscall FUN_10001ce0(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002cf26;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100025e0(this);
  FUN_100020b0((undefined4 *)((int)this + 4));
  local_8 = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CActivityLogImpl>::vftable;
  FUN_100021a0((void *)((int)this + 8),param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*DAT_10043bb8 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10001d80 at 10001d80

int FUN_10001d80(void)

{
  undefined4 local_c;
  
  local_c = FUN_100071b0();
  if (-1 < local_c) {
    local_c = FUN_100071b0();
  }
  return local_c;
}



// Function: FUN_10001dc0 at 10001dc0

void FUN_10001dc0(void)

{
  FUN_10006db0();
  FUN_10006db0();
  return;
}



// Function: FUN_10001df0 at 10001df0

void FUN_10001df0(int param_1)

{
  FUN_10007100((int *)(param_1 + 4));
  return;
}



// Function: FUN_10001e10 at 10001e10

int FUN_10001e10(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10007160(param_1 + 1);
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return iVar1;
}



// Function: FUN_10001e70 at 10001e70

undefined4 FUN_10001e70(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_8;
  
  if (param_3 == (undefined4 *)0x0) {
    local_8 = 0x80004003;
  }
  else {
    *param_3 = 0;
    local_8 = 0;
    iVar1 = FUN_10002540(param_2);
    if (iVar1 == 0) {
      local_8 = FUN_10001cb0(param_1 + 2,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return local_8;
}



// Function: FUN_10001ee0 at 10001ee0

undefined4 * __thiscall FUN_10001ee0(void *this,uint param_1)

{
  FUN_10001f20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10001f20 at 10001f20

void __fastcall FUN_10001f20(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002cf58;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CActivityLogImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CActivityLogImpl>::vftable;
  local_8 = 0;
  param_1[2] = 0xc0000001;
  FUN_10001fb0();
  (**(code **)(*DAT_10043bb8 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_1000bca0((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001fb0 at 10001fb0

void FUN_10001fb0(void)

{
  return;
}



// Function: FUN_10001fd0 at 10001fd0

undefined4 * __thiscall FUN_10001fd0(void *this,uint param_1)

{
  FUN_10002010((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002010 at 10002010

void __fastcall FUN_10002010(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1002cf96;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComAggObject<class_CActivityLogImpl>::vftable;
  local_8 = 1;
  param_1[1] = 0xc0000001;
  FUN_10002170();
  (**(code **)(*DAT_10043bb8 + 8))(uVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_10002110((int)(param_1 + 2));
  local_8 = 0xffffffff;
  FUN_100070a0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_100020b0 at 100020b0

undefined4 * __fastcall FUN_100020b0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002cfc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10006d70(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002110 at 10002110

void __fastcall FUN_10002110(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002cff8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000bca0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002170 at 10002170

void FUN_10002170(void)

{
  FUN_10006df0();
  FUN_10001fb0();
  return;
}



// Function: FUN_100021a0 at 100021a0

undefined4 * __thiscall FUN_100021a0(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d028;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000bb80((int)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CActivityLogImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComContainedObject<class_CActivityLogImpl>::vftable;
  *(undefined4 *)((int)this + 8) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10002220 at 10002220

void FUN_10002220(int param_1)

{
  FUN_10006f90((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10002240 at 10002240

void FUN_10002240(int param_1)

{
  FUN_10006fc0((undefined4 *)(param_1 + 8));
  return;
}



// Function: FUN_10002260 at 10002260

void FUN_10002260(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10006ff0((void *)(param_1 + 8),param_2,param_3);
  return;
}



// Function: FUN_10002290 at 10002290

undefined4 __fastcall FUN_10002290(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100022b0 at 100022b0

void FUN_100022b0(int param_1)

{
  FUN_10001c20((int *)(param_1 + -4));
  return;
}



// Function: FUN_100022c0 at 100022c0

void FUN_100022c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10002260(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_100022d0 at 100022d0

void FUN_100022d0(int param_1)

{
  FUN_10001c00(param_1 + -4);
  return;
}



// Function: FUN_100022e0 at 100022e0

void FUN_100022e0(int param_1)

{
  FUN_10002240(param_1 + -4);
  return;
}



// Function: FUN_100022f0 at 100022f0

void FUN_100022f0(int param_1,int *param_2,undefined4 *param_3)

{
  FUN_10001c80((void *)(param_1 + -4),param_2,param_3);
  return;
}



// Function: FUN_10002300 at 10002300

void FUN_10002300(int param_1)

{
  FUN_10002220(param_1 + -4);
  return;
}



// Function: FUN_10002310 at 10002310

void * __fastcall FUN_10002310(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d058;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002370(param_1);
  *(undefined1 *)((int)param_1 + 0x18) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10002370 at 10002370

void * __fastcall FUN_10002370(void *param_1)

{
  memset(param_1,0,0x18);
  return param_1;
}



// Function: FUN_100023a0 at 100023a0

void FUN_100023a0(void)

{
  return;
}



// Function: FUN_100023c0 at 100023c0

void __fastcall FUN_100023c0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d088;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    FUN_10002430(param_1);
  }
  local_8 = 0xffffffff;
  FUN_100023a0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002430 at 10002430

undefined4 __fastcall FUN_10002430(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return 0;
}



// Function: FUN_10002450 at 10002450

uint __fastcall FUN_10002450(LPCRITICAL_SECTION param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10002480(param_1);
  if (-1 < (int)uVar1) {
    *(undefined1 *)&param_1[1].DebugInfo = 1;
  }
  return uVar1;
}



// Function: FUN_10002480 at 10002480

uint __fastcall FUN_10002480(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 local_c;
  
  local_c = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    local_c = FUN_100024c0(DVar2);
  }
  return local_c;
}



// Function: FUN_100024c0 at 100024c0

uint __cdecl FUN_100024c0(uint param_1)

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



// Function: FUN_10002500 at 10002500

void FUN_10002500(LONG *param_1)

{
  InterlockedIncrement(param_1);
  return;
}



// Function: FUN_10002520 at 10002520

void FUN_10002520(LONG *param_1)

{
  InterlockedDecrement(param_1);
  return;
}



// Function: FUN_10002540 at 10002540

undefined4 FUN_10002540(int *param_1)

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



// Function: FUN_10002590 at 10002590

undefined4 __fastcall FUN_10002590(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_100025b0 at 100025b0

void FUN_100025b0(int *param_1,ushort param_2,int param_3,int *param_4)

{
  FUN_10002600(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_100025e0 at 100025e0

undefined4 __fastcall FUN_100025e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10002600 at 10002600

void FUN_10002600(int *param_1,ushort param_2,int param_3,int *param_4)

{
  bool bVar1;
  uint uVar2;
  HMODULE pHVar3;
  int iVar4;
  int local_aec;
  WCHAR local_a80;
  undefined2 local_a7e [523];
  int local_668;
  WCHAR local_664 [520];
  short *local_254;
  DWORD local_250;
  HMODULE local_24c;
  WCHAR local_248 [260];
  int local_40 [3];
  undefined4 local_34;
  int local_2c;
  undefined4 local_28 [5];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d0c0;
  local_10 = ExceptionList;
  uVar2 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_10005e90(local_28);
  local_8 = 0;
  local_2c = FUN_10002d60();
  if (local_2c < 0) {
    local_8 = 0xffffffff;
    FUN_10002bb0(local_28);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10002de0(local_28,*param_4,param_4[1]);
      }
    }
    local_2c = (**(code **)(*param_1 + 0x14))(local_28,uVar2);
    if (local_2c < 0) {
      local_8 = 0xffffffff;
      FUN_10002bb0(local_28);
    }
    else {
      local_34 = FUN_10002a10();
      FUN_10008090(local_40);
      local_8._0_1_ = 1;
      local_24c = (HMODULE)FUN_10002ab0(0x100458a4);
      local_250 = GetModuleFileNameW(local_24c,local_248,0x104);
      if (local_250 == 0) {
        FUN_10002ad0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100080b0(local_40);
        local_8 = 0xffffffff;
        FUN_10002bb0(local_28);
      }
      else if (local_250 == 0x104) {
        FUN_100024c0(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100080b0(local_40);
        local_8 = 0xffffffff;
        FUN_10002bb0(local_28);
      }
      else {
        local_254 = (short *)0x0;
        local_254 = (short *)FUN_10002a90(local_248);
        FUN_10002b00(local_664,0x208,local_254);
        if ((local_24c == (HMODULE)0x0) ||
           (pHVar3 = GetModuleHandleW((LPCWSTR)0x0), local_24c == pHVar3)) {
          local_a80 = L'\"';
          bVar1 = FUN_10002a50(local_a7e,0x20b,local_664);
          if (!bVar1) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100080b0(local_40);
            local_8 = 0xffffffff;
            FUN_10002bb0(local_28);
            goto LAB_100029e8;
          }
          iVar4 = FUN_10002a30(&local_a80);
          local_a7e[iVar4 + -1] = 0x22;
          local_a7e[iVar4] = 0;
          local_668 = FUN_10002de0(local_28,0x10036c8c,(int)&local_a80);
        }
        else {
          local_668 = FUN_10002de0(local_28,0x10036c8c,(int)local_664);
        }
        if (local_668 < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100080b0(local_40);
          local_8 = 0xffffffff;
          FUN_10002bb0(local_28);
        }
        else {
          local_668 = FUN_10002de0(local_28,0x10036c74,(int)local_664);
          if (local_668 < 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100080b0(local_40);
            local_8 = 0xffffffff;
            FUN_10002bb0(local_28);
          }
          else {
            if (param_3 == 0) {
              local_aec = FUN_10003540(local_28,local_254,param_2,L"REGISTRY");
            }
            else {
              local_aec = FUN_10003270(local_28,local_254,param_2,L"REGISTRY");
            }
            local_2c = local_aec;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100080b0(local_40);
            local_8 = 0xffffffff;
            FUN_10002bb0(local_28);
          }
        }
      }
    }
  }
LAB_100029e8:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10002a10 at 10002a10

undefined4 FUN_10002a10(void)

{
  return 3;
}



// Function: FUN_10002a30 at 10002a30

void __cdecl FUN_10002a30(LPCWSTR param_1)

{
  lstrlenW(param_1);
  return;
}



// Function: FUN_10002a50 at 10002a50

bool __cdecl FUN_10002a50(void *param_1,int param_2,LPCWSTR param_3)

{
  int iVar1;
  errno_t eVar2;
  
  iVar1 = FUN_10002a30(param_3);
  eVar2 = memcpy_s(param_1,param_2 << 1,param_3,iVar1 * 2 + 2);
  return (bool)('\x01' - (eVar2 != 0));
}



// Function: FUN_10002a90 at 10002a90

undefined4 __cdecl FUN_10002a90(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10002ab0 at 10002ab0

undefined4 __fastcall FUN_10002ab0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10002ad0 at 10002ad0

void FUN_10002ad0(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  FUN_100024c0(DVar1);
  return;
}



// Function: FUN_10002b00 at 10002b00

void __cdecl FUN_10002b00(short *param_1,int param_2,short *param_3)

{
  short *psVar1;
  uint local_8;
  
  if (param_2 != 0) {
    local_8 = 0;
    for (; (local_8 < param_2 - 1U && (*param_3 != 0)); param_3 = param_3 + 1) {
      *param_1 = *param_3;
      psVar1 = param_1 + 1;
      if ((*param_3 == 0x27) && (local_8 = local_8 + 1, local_8 < param_2 - 1U)) {
        *psVar1 = *param_3;
        psVar1 = param_1 + 2;
      }
      param_1 = psVar1;
      local_8 = local_8 + 1;
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_10002bb0 at 10002bb0

void __fastcall FUN_10002bb0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d0fb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CRegObject::vftable;
  local_8 = 0;
  FUN_100035e0((int)param_1);
  local_8 = 0xffffffff;
  FUN_10002c20(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002c20 at 10002c20

void __fastcall FUN_10002c20(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d128;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10002c80(param_1);
  local_8 = 0xffffffff;
  FUN_10008db0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002c80 at 10002c80

undefined4 __fastcall FUN_10002c80(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_c;
  
  local_c = 0;
  while( true ) {
    iVar1 = FUN_10008dd0((int)param_1);
    if (iVar1 <= local_c) break;
    puVar2 = (undefined4 *)FUN_10008f60(param_1,local_c);
    operator_delete__((void *)*puVar2);
    puVar2 = (undefined4 *)FUN_10008fa0(param_1,local_c);
    operator_delete__((void *)*puVar2);
    local_c = local_c + 1;
  }
  FUN_10008ea0(param_1);
  return 0;
}



// Function: FUN_10002d00 at 10002d00

undefined4 FUN_10002d00(void)

{
  return 0x80004001;
}



// Function: FUN_10002d20 at 10002d20

undefined4 FUN_10002d20(void)

{
  return 1;
}



// Function: FUN_10002d40 at 10002d40

undefined4 FUN_10002d40(void)

{
  return 0;
}



// Function: FUN_10002d60 at 10002d60

void FUN_10002d60(void)

{
  FUN_10002d80();
  return;
}



// Function: FUN_10002d80 at 10002d80

undefined4 FUN_10002d80(void)

{
  return 0;
}



// Function: FUN_10002da0 at 10002da0

undefined4 * __thiscall FUN_10002da0(void *this,uint param_1)

{
  FUN_10002bb0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10002de0 at 10002de0

int FUN_10002de0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  LPCWSTR pWVar2;
  int local_24 [3];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d158;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_2 == 0) || (param_3 == 0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    FUN_10002ed0();
    local_18 = FUN_10002a10();
    FUN_10008090(local_24);
    local_8 = 0;
    pWVar2 = (LPCWSTR)FUN_10002eb0(param_2);
    iVar1 = FUN_10002f10(pWVar2,param_3);
    FUN_10002ef0();
    iVar1 = (-(uint)(iVar1 != 0) & 0x7ff8fff2) + 0x8007000e;
    local_8 = 0xffffffff;
    FUN_100080b0(local_24);
  }
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_10002eb0 at 10002eb0

undefined4 __cdecl FUN_10002eb0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10002ed0 at 10002ed0

undefined4 FUN_10002ed0(void)

{
  return 0;
}



// Function: FUN_10002ef0 at 10002ef0

undefined4 FUN_10002ef0(void)

{
  return 0;
}



// Function: FUN_10002f10 at 10002f10

undefined4 FUN_10002f10(LPCWSTR param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d190;
  local_10 = ExceptionList;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != 0)) {
    ExceptionList = &local_10;
    iVar2 = lstrlenW(param_1);
    local_8 = 0;
    lVar1 = (ulonglong)(iVar2 * 2 + 2) * 2;
    FUN_1002bb86(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar3 = FUN_10002fac();
    return uVar3;
  }
  return 0;
}



// Function: Catch@10002f9f at 10002f9f

undefined4 Catch_10002f9f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10002fb3;
}



// Function: FUN_10002fac at 10002fac

void FUN_10002fac(void)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10008fe0((undefined4 *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10009020((void *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
  iVar2 = FUN_10002a30(*(LPCWSTR *)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x28) = iVar2 * 2 + 2;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  lVar1 = (ulonglong)*(uint *)(unaff_EBP + -0x28) * 2;
  uVar3 = FUN_1002bb86(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  *(undefined4 *)(unaff_EBP + -0x78) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x78);
  FUN_10003028();
  return;
}



// Function: Catch@1000301b at 1000301b

undefined4 Catch_1000301b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  return 0x1000302f;
}



// Function: FUN_10003028 at 10003028

undefined4 FUN_10003028(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_10008fe0((undefined4 *)(unaff_EBP + -0x30));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_10009020((void *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x2c));
  if ((*(int *)(unaff_EBP + -0x20) == 0) || (*(int *)(unaff_EBP + -0x2c) == 0)) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0x8007000e;
  }
  else {
    FUN_10003110(*(void **)(unaff_EBP + -0x20),*(rsize_t *)(unaff_EBP + -0x1c),
                 *(void **)(unaff_EBP + 8),*(rsize_t *)(unaff_EBP + -0x1c));
    FUN_10003110(*(void **)(unaff_EBP + -0x2c),*(rsize_t *)(unaff_EBP + -0x28),
                 *(void **)(unaff_EBP + 0xc),*(rsize_t *)(unaff_EBP + -0x28));
    iVar1 = FUN_10008df0(*(void **)(unaff_EBP + -0x14),(undefined4 *)(unaff_EBP + -0x20),
                         (undefined4 *)(unaff_EBP + -0x2c));
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0x8007000e;
    }
  }
  if (-1 < *(int *)(unaff_EBP + -0x18)) {
    FUN_10009050((undefined4 *)(unaff_EBP + -0x24));
    FUN_10009050((undefined4 *)(unaff_EBP + -0x30));
  }
  *(uint *)(unaff_EBP + -0x74) = (uint)(-1 < *(int *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10009000((undefined4 *)(unaff_EBP + -0x30));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_10009000((undefined4 *)(unaff_EBP + -0x24));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x74);
}



// Function: FUN_10003110 at 10003110

void __cdecl FUN_10003110(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  FUN_10003150(eVar1);
  return;
}



// Function: FUN_10003150 at 10003150

undefined4 __cdecl FUN_10003150(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 0x50:
    break;
  default:
    FUN_10003210(0x80004005);
    break;
  case 0xc:
    FUN_10003210(0x8007000e);
    break;
  case 0x16:
  case 0x22:
    FUN_10003210(0x80070057);
  }
  return param_1;
}



// Function: FUN_10003210 at 10003210

void FUN_10003210(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 local_4c;
  undefined1 local_48 [68];
  
  puVar1 = FUN_10003250(local_48,param_1);
  local_4c = *puVar1;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_4c,(ThrowInfo *)&DAT_1003c8c4);
}



// Function: FUN_10003250 at 10003250

undefined4 * __thiscall FUN_10003250(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10003270 at 10003270

undefined4 FUN_10003270(undefined4 param_1,undefined4 param_2,ushort param_3,undefined4 param_4)

{
  LPCWSTR pWVar1;
  undefined4 uVar2;
  int local_24 [3];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d1b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = FUN_10002a10();
  FUN_10008090(local_24);
  local_8 = 0;
  pWVar1 = (LPCWSTR)FUN_10002eb0(param_4);
  uVar2 = FUN_10003310(param_2,(LPCWSTR)(uint)param_3,pWVar1);
  local_8 = 0xffffffff;
  FUN_100080b0(local_24);
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_10003310 at 10003310

void FUN_10003310(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  LPCWSTR lpLibFileName;
  uint uStack_4b0;
  int local_454 [257];
  HGLOBAL local_50;
  DWORD local_4c;
  HGLOBAL local_48;
  HRSRC local_44;
  HMODULE local_40;
  undefined1 local_3c [8];
  undefined4 local_34;
  int local_30 [3];
  undefined4 local_24;
  undefined4 local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d1f3;
  local_10 = ExceptionList;
  uStack_4b0 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4b0;
  ExceptionList = &local_10;
  local_18 = uStack_4b0;
  local_24 = FUN_10002a10();
  FUN_10008090(local_30);
  local_8 = 0;
  FUN_10003620(local_3c,local_1c);
  FUN_10009080(local_454);
  local_8._0_1_ = 1;
  lpLibFileName = (LPCWSTR)FUN_10002eb0(param_1);
  local_40 = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,2);
  if (local_40 == (HMODULE)0x0) {
    local_34 = FUN_10002ad0();
  }
  else {
    local_44 = FindResourceW(local_40,param_2,param_3);
    if (local_44 == (HRSRC)0x0) {
      local_34 = FUN_10002ad0();
    }
    else {
      local_48 = LoadResource(local_40,local_44);
      if (local_48 == (HGLOBAL)0x0) {
        local_34 = FUN_10002ad0();
      }
      else {
        local_4c = SizeofResource(local_40,local_44);
        local_50 = local_48;
        if (local_4c <= local_4c + 1) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_100090f0(local_454,local_4c + 1);
          FUN_10003454();
          return;
        }
        local_34 = 0x8007000e;
      }
    }
  }
  if (local_40 != (HMODULE)0x0) {
    FreeLibrary(local_40);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100090a0(local_454);
  local_8 = 0xffffffff;
  FUN_100080b0(local_30);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10003447 at 10003447

undefined4 Catch_10003447(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000345b;
}



// Function: FUN_10003454 at 10003454

void FUN_10003454(void)

{
  int iVar1;
  LPWSTR lpWideCharStr;
  UINT CodePage;
  undefined4 uVar2;
  LPCWSTR pWVar3;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  DWORD dwFlags;
  LPCSTR lpMultiByteStr;
  int cbMultiByte;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  iVar1 = FUN_100090d0((undefined4 *)(unaff_EBP - 0x450));
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP - 0x30) = 0x8007000e;
  }
  else {
    iVar1 = *(int *)(unaff_EBP - 0x48);
    lpWideCharStr = (LPWSTR)FUN_100090d0((undefined4 *)(unaff_EBP - 0x450));
    cbMultiByte = *(int *)(unaff_EBP - 0x48);
    lpMultiByteStr = *(LPCSTR *)(unaff_EBP - 0x4c);
    dwFlags = 0;
    CodePage = FUN_10002a10();
    iVar1 = MultiByteToWideChar(CodePage,dwFlags,lpMultiByteStr,cbMultiByte,lpWideCharStr,iVar1);
    *(int *)(unaff_EBP - 0x458) = iVar1;
    if (*(int *)(unaff_EBP - 0x458) == 0) {
      uVar2 = FUN_10002ad0();
      *(undefined4 *)(unaff_EBP - 0x30) = uVar2;
    }
    else {
      iVar1 = FUN_100090d0((undefined4 *)(unaff_EBP - 0x450));
      *(undefined2 *)(iVar1 + *(int *)(unaff_EBP - 0x458) * 2) = 0;
      iVar1 = *(int *)(unaff_EBP + 0x14);
      pWVar3 = (LPCWSTR)FUN_100090d0((undefined4 *)(unaff_EBP - 0x450));
      uVar2 = FUN_10003650((void *)(unaff_EBP - 0x38),pWVar3,iVar1);
      *(undefined4 *)(unaff_EBP - 0x30) = uVar2;
    }
  }
  if (*(int *)(unaff_EBP - 0x3c) != 0) {
    FreeLibrary(*(HMODULE *)(unaff_EBP - 0x3c));
  }
  *(undefined4 *)(unaff_EBP - 0x49c) = *(undefined4 *)(unaff_EBP - 0x30);
  *(undefined1 *)(unaff_EBP - 4) = 0;
  FUN_100090a0((int *)(unaff_EBP - 0x450));
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_100080b0((int *)(unaff_EBP - 0x2c));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10003539;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10003540 at 10003540

undefined4 FUN_10003540(undefined4 param_1,undefined4 param_2,ushort param_3,undefined4 param_4)

{
  LPCWSTR pWVar1;
  undefined4 uVar2;
  int local_24 [3];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d228;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = FUN_10002a10();
  FUN_10008090(local_24);
  local_8 = 0;
  pWVar1 = (LPCWSTR)FUN_10002eb0(param_4);
  uVar2 = FUN_10003310(param_2,(LPCWSTR)(uint)param_3,pWVar1);
  local_8 = 0xffffffff;
  FUN_100080b0(local_24);
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_100035e0 at 100035e0

undefined4 FUN_100035e0(int param_1)

{
  undefined4 uVar1;
  
  FUN_10002ed0();
  uVar1 = FUN_10002c80((int *)(param_1 + 4));
  FUN_10002ef0();
  return uVar1;
}



// Function: FUN_10003620 at 10003620

undefined4 * __thiscall FUN_10003620(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)this = 0;
  return (undefined4 *)this;
}



// Function: FUN_10003650 at 10003650

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10003650(void *this,LPCWSTR param_1,int param_2)

{
  undefined4 uVar1;
  HKEY pHVar2;
  LPVOID local_2014;
  int local_2010;
  WCHAR local_200c [4096];
  undefined4 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_2010 = 0;
  local_2014 = (LPVOID)0x0;
  local_c = (undefined4 *)this;
  local_2010 = FUN_10003be0(this,param_1,&local_2014);
  if (-1 < local_2010) {
    *local_c = local_2014;
    while( true ) {
      if ((*(short *)*local_c == 0) ||
         (local_2010 = FUN_10003960(local_c,local_200c), local_2010 < 0)) goto LAB_10003808;
      pHVar2 = (HKEY)FUN_10003850(local_200c);
      if (pHVar2 == (HKEY)0x0) break;
      local_2010 = FUN_10003960(local_c,local_200c);
      if (local_2010 < 0) goto LAB_10003808;
      if (local_200c[0] != L'{') {
        local_2010 = FUN_10003830();
        goto LAB_10003808;
      }
      if (param_2 == 0) {
        local_2010 = FUN_10004510(local_200c,pHVar2,0,0);
        if (local_2010 < 0) goto LAB_10003808;
      }
      else {
        uVar1 = *local_c;
        local_2010 = FUN_10004510(local_200c,pHVar2,param_2,0);
        if (local_2010 < 0) {
          *local_c = uVar1;
          FUN_10004510(local_200c,pHVar2,0,0);
          goto LAB_10003808;
        }
      }
      FUN_100038b0(local_c);
    }
    local_2010 = FUN_10003830();
LAB_10003808:
    CoTaskMemFree(local_2014);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003830 at 10003830

undefined4 FUN_10003830(void)

{
  return 0x80020009;
}



// Function: FUN_10003850 at 10003850

undefined4 __cdecl FUN_10003850(LPCWSTR param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xd < local_8) {
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10036cb8)[local_8 * 2]);
    if (iVar1 == 0) break;
    local_8 = local_8 + 1;
  }
  return *(undefined4 *)(&DAT_10036cbc + local_8 * 8);
}



// Function: FUN_100038b0 at 100038b0

void __fastcall FUN_100038b0(undefined4 *param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  
  while( true ) {
    iVar1 = FUN_100038f0(*(undefined2 *)*param_1);
    if (iVar1 == 0) break;
    pWVar2 = CharNextW((LPCWSTR)*param_1);
    *param_1 = pWVar2;
  }
  return;
}



// Function: FUN_100038f0 at 100038f0

undefined4 FUN_100038f0(undefined2 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 9:
  case 10:
  case 0xd:
  case 0x20:
    uVar1 = 1;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10003960 at 10003960

undefined4 __thiscall FUN_10003960(void *this,undefined2 *param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  LPWSTR pWVar3;
  int iVar4;
  int local_24;
  undefined2 *local_1c;
  int local_18;
  undefined2 *local_10;
  
  puVar1 = param_1;
  FUN_100038b0((undefined4 *)this);
                    /* WARNING: Load size is inaccurate */
  if (**this == 0) {
    uVar2 = FUN_10003830();
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (**this == 0x27) {
                    /* WARNING: Load size is inaccurate */
      pWVar3 = CharNextW(*this);
      *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
      while ((**this != 0 && (iVar4 = FUN_10003b90((undefined4 *)this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        if (**this == 0x27) {
                    /* WARNING: Load size is inaccurate */
          pWVar3 = CharNextW(*this);
          *(LPWSTR *)this = pWVar3;
        }
                    /* WARNING: Load size is inaccurate */
        local_10 = *this;
                    /* WARNING: Load size is inaccurate */
        pWVar3 = CharNextW(*this);
        *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_10 >> 1;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_10003830();
          return uVar2;
        }
        for (local_18 = 0; local_18 < iVar4; local_18 = local_18 + 1) {
          *param_1 = *local_10;
          param_1 = param_1 + 1;
          local_10 = local_10 + 1;
        }
      }
                    /* WARNING: Load size is inaccurate */
      if (**this == 0) {
        uVar2 = FUN_10003830();
        return uVar2;
      }
      *param_1 = 0;
                    /* WARNING: Load size is inaccurate */
      pWVar3 = CharNextW(*this);
      *(LPWSTR *)this = pWVar3;
    }
    else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      while ((**this != 0 && (iVar4 = FUN_100038f0(**this), iVar4 == 0))) {
                    /* WARNING: Load size is inaccurate */
        local_1c = *this;
                    /* WARNING: Load size is inaccurate */
        pWVar3 = CharNextW(*this);
        *(LPWSTR *)this = pWVar3;
                    /* WARNING: Load size is inaccurate */
        iVar4 = *this - (int)local_1c >> 1;
        if (puVar1 + 0x1000 <= param_1 + iVar4 + 1) {
          uVar2 = FUN_10003830();
          return uVar2;
        }
        for (local_24 = 0; local_24 < iVar4; local_24 = local_24 + 1) {
          *param_1 = *local_1c;
          param_1 = param_1 + 1;
          local_1c = local_1c + 1;
        }
      }
      *param_1 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10003b90 at 10003b90

undefined4 __fastcall FUN_10003b90(undefined4 *param_1)

{
  LPWSTR pWVar1;
  
  if ((*(short *)*param_1 == 0x27) && (pWVar1 = CharNextW((LPCWSTR)*param_1), *pWVar1 != L'\'')) {
    return 1;
  }
  return 0;
}



// Function: FUN_10003be0 at 10003be0

void __thiscall FUN_10003be0(void *this,LPCWSTR param_1,undefined4 *param_2)

{
  LPWSTR pWVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t local_8c [32];
  rsize_t local_4c;
  LPCWSTR local_48;
  int local_44;
  wchar_t *local_40;
  wchar_t *local_3c;
  char local_36;
  char local_35;
  int local_34;
  char local_2d;
  int local_2c;
  undefined4 local_28 [2];
  int local_20;
  int local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d258;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (int *)this;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = 0;
    local_1c = lstrlenW(param_1);
    local_1c = local_1c << 1;
    FUN_10004080(local_28,local_1c);
    local_8 = 0;
    if (local_20 == 0) {
      local_8 = 0xffffffff;
      FUN_10004190((int)local_28);
    }
    else {
      *local_18 = (int)param_1;
      local_2c = 0;
      local_2d = '\0';
      local_2c = FUN_10005f80(&local_2d);
      if (local_2c < 0) {
        local_8 = 0xffffffff;
        FUN_10004190((int)local_28);
      }
      else {
        local_34 = 0;
        local_35 = '\0';
        local_36 = '\0';
        while (*(short *)*local_18 != 0) {
          if (local_2d == '\x01') {
            local_3c = L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses";
            local_40 = L"\r\n\t}\r\n}\r\n";
            if (local_34 == 0) {
              local_44 = 0;
              local_44 = FUN_10004010((wchar_t *)*local_18,L"HKCR");
              if ((local_44 != 0) && (local_44 == *local_18)) {
                pWVar1 = CharNextW((LPCWSTR)*local_18);
                *local_18 = (int)pWVar1;
                pWVar1 = CharNextW((LPCWSTR)*local_18);
                *local_18 = (int)pWVar1;
                pWVar1 = CharNextW((LPCWSTR)*local_18);
                *local_18 = (int)pWVar1;
                pWVar1 = CharNextW((LPCWSTR)*local_18);
                *local_18 = (int)pWVar1;
                iVar2 = FUN_10004360((int)local_3c);
                if (iVar2 == 0) {
                  local_2c = -0x7ff8fff2;
                  break;
                }
                local_35 = '\x01';
              }
            }
            if (*(short *)*local_18 == 0x27) {
              if (local_36 == '\0') {
                local_36 = '\x01';
              }
              else {
                iVar2 = FUN_10003b90(local_18);
                if (iVar2 == 0) {
                  pWVar1 = CharNextW((LPCWSTR)*local_18);
                  *local_18 = (int)pWVar1;
                  iVar2 = FUN_100041b0(local_28,(void *)*local_18);
                  if (iVar2 == 0) {
                    local_2c = -0x7ff8fff2;
                    break;
                  }
                }
                else {
                  local_36 = '\0';
                }
              }
            }
            if ((local_36 == '\0') && (*(short *)*local_18 == 0x7b)) {
              local_34 = local_34 + 1;
            }
            if ((((local_36 == '\0') && (*(short *)*local_18 == 0x7d)) &&
                (local_34 = local_34 + -1, local_34 == 0)) && (local_35 == '\x01')) {
              iVar2 = FUN_10004360((int)local_40);
              if (iVar2 == 0) {
                local_2c = -0x7ff8fff2;
                break;
              }
              local_35 = '\0';
            }
          }
          if (*(short *)*local_18 == 0x25) {
            pWVar1 = CharNextW((LPCWSTR)*local_18);
            *local_18 = (int)pWVar1;
            if (*(short *)*local_18 == 0x25) {
              iVar2 = FUN_100041b0(local_28,(void *)*local_18);
              if (iVar2 == 0) {
                local_2c = -0x7ff8fff2;
                break;
              }
            }
            else {
              local_48 = FUN_100044b0((LPWSTR)*local_18,L'%');
              if (local_48 == (LPCWSTR)0x0) {
                local_2c = FUN_10003830();
                break;
              }
              if (0x1f < (int)local_48 - *local_18 >> 1) {
                local_2c = -0x7fffbffb;
                break;
              }
              local_4c = (int)local_48 - *local_18 >> 1;
              FUN_10004040(local_8c,0x20,(wchar_t *)*local_18,local_4c);
              iVar2 = FUN_10004470(local_18[1]);
              if (iVar2 == 0) {
                local_2c = FUN_10003830();
                break;
              }
              iVar2 = FUN_10004360(iVar2);
              if (iVar2 == 0) {
                local_2c = -0x7ff8fff2;
                break;
              }
              while ((LPCWSTR)*local_18 != local_48) {
                pWVar1 = CharNextW((LPCWSTR)*local_18);
                *local_18 = (int)pWVar1;
              }
            }
          }
          else {
            iVar2 = FUN_100041b0(local_28,(void *)*local_18);
            if (iVar2 == 0) {
              local_2c = -0x7ff8fff2;
              break;
            }
          }
          pWVar1 = CharNextW((LPCWSTR)*local_18);
          *local_18 = (int)pWVar1;
        }
        if (-1 < local_2c) {
          uVar3 = FUN_10004430(local_28);
          *param_2 = uVar3;
        }
        local_8 = 0xffffffff;
        FUN_10004190((int)local_28);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004010 at 10004010

void __cdecl FUN_10004010(wchar_t *param_1,wchar_t *param_2)

{
  wcsstr(param_1,param_2);
  return;
}



// Function: FUN_10004040 at 10004040

void __cdecl FUN_10004040(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  FUN_10003150(eVar1);
  return;
}



// Function: FUN_10004080 at 10004080

undefined4 * __thiscall FUN_10004080(void *this,int param_1)

{
  LPVOID pvVar1;
  
  if (param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(int *)((int)this + 4) = param_1;
  pvVar1 = FUN_100040f0(*(uint *)((int)this + 4),2);
  *(LPVOID *)((int)this + 8) = pvVar1;
  if (*(int *)((int)this + 8) != 0) {
    **(undefined2 **)((int)this + 8) = 0;
  }
  return (undefined4 *)this;
}



// Function: FUN_100040f0 at 100040f0

LPVOID __cdecl FUN_100040f0(uint param_1,uint param_2)

{
  LPVOID pvVar1;
  SIZE_T local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = FUN_10004140(&local_c,param_1,param_2);
  if ((int)local_8 < 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = CoTaskMemAlloc(local_c);
  }
  return pvVar1;
}



// Function: FUN_10004140 at 10004140

uint __cdecl FUN_10004140(undefined4 *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_8 == 0) {
    local_c = (undefined4)((ulonglong)param_2 * (ulonglong)param_3);
    *param_1 = local_c;
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_100024c0(0x216);
  }
  return uVar1;
}



// Function: FUN_10004190 at 10004190

void __fastcall FUN_10004190(int param_1)

{
  CoTaskMemFree(*(LPVOID *)(param_1 + 8));
  return;
}



// Function: FUN_100041b0 at 100041b0

void __thiscall FUN_100041b0(void *this,void *param_1)

{
  FUN_100041e0(this,param_1,1);
  return;
}



// Function: FUN_100041e0 at 100041e0

undefined4 __thiscall FUN_100041e0(void *this,void *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this + 1 + param_2;
                    /* WARNING: Load size is inaccurate */
  if ((*this < iVar1) && (param_2 < iVar1)) {
    if (*(int *)((int)this + 4) <= iVar1) {
      while (*(int *)((int)this + 4) <= iVar1) {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          return 0;
        }
        *(int *)((int)this + 4) = *(int *)((int)this + 4) << 1;
      }
      pvVar3 = FUN_10004310(*(LPVOID *)((int)this + 8),*(uint *)((int)this + 4),2);
      if (pvVar3 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar3;
    }
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((*this < 0) || (*(int *)((int)this + 4) <= *this)) ||
       (*(int *)((int)this + 4) < *(int *)((int)this + 4) - *this)) {
      uVar2 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      FUN_10003110((void *)(*(int *)((int)this + 8) + *this * 2),
                   (*(int *)((int)this + 4) - *this) * 2,param_1,param_2 << 1);
                    /* WARNING: Load size is inaccurate */
      *(int *)this = *this + param_2;
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*(int *)((int)this + 8) + *this * 2) = 0;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function: FUN_10004310 at 10004310

LPVOID __cdecl FUN_10004310(LPVOID param_1,uint param_2,uint param_3)

{
  LPVOID pvVar1;
  SIZE_T local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = FUN_10004140(&local_c,param_2,param_3);
  if ((int)local_8 < 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = CoTaskMemRealloc(param_1,local_c);
  }
  return pvVar1;
}



// Function: FUN_10004360 at 10004360

undefined4 FUN_10004360(int param_1)

{
  undefined4 uVar1;
  LPCWSTR lpString;
  int iVar2;
  int local_28 [3];
  undefined4 local_1c;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d288;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    local_1c = FUN_10002a10();
    FUN_10008090(local_28);
    local_8 = 0;
    lpString = (LPCWSTR)FUN_10002eb0(param_1);
    if (lpString == (LPCWSTR)0x0) {
      local_8 = 0xffffffff;
      FUN_100080b0(local_28);
      uVar1 = 0;
    }
    else {
      iVar2 = lstrlenW(lpString);
      uVar1 = FUN_100041e0(local_14,lpString,iVar2);
      local_8 = 0xffffffff;
      FUN_100080b0(local_28);
    }
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_10004430 at 10004430

undefined4 __fastcall FUN_10004430(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = param_1[2];
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return uVar1;
}



// Function: FUN_10004470 at 10004470

undefined4 __fastcall FUN_10004470(int param_1)

{
  undefined4 uVar1;
  
  FUN_10002ed0();
  uVar1 = FUN_10008f20((void *)(param_1 + 4),(undefined4 *)&stack0x00000004);
  FUN_10002ef0();
  return uVar1;
}



// Function: FUN_100044b0 at 100044b0

LPCWSTR __cdecl FUN_100044b0(LPWSTR param_1,WCHAR param_2)

{
  LPWSTR pWVar1;
  LPCWSTR local_8;
  
  local_8 = (LPCWSTR)0x0;
  if (param_1 == (LPWSTR)0x0) {
    pWVar1 = (LPCWSTR)0x0;
  }
  else {
    for (; (pWVar1 = local_8, *param_1 != L'\0' && (pWVar1 = param_1, *param_1 != param_2));
        param_1 = CharNextW(param_1)) {
    }
  }
  return pWVar1;
}



// Function: FUN_10004510 at 10004510

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10004510(LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  LPCWSTR pWVar3;
  HKEY pHVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_2274 [3];
  int local_2268;
  int local_2264 [3];
  int local_2258 [3];
  WCHAR local_224c [4096];
  int local_24c [3];
  uint local_240;
  int local_23c;
  int local_238;
  int local_234;
  wchar_t local_230 [260];
  uint local_28;
  HKEY local_24 [3];
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d2e4;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10004e20(local_24,0);
  local_8 = 0;
  local_234 = 1;
  local_238 = param_4;
  local_23c = 0;
  local_23c = FUN_10003960(local_18,param_1);
  if (-1 < local_23c) {
LAB_100045b4:
    if (*param_1 == L'}') goto LAB_10004db9;
    local_234 = 1;
    iVar2 = lstrcmpiW(param_1,L"Delete");
    local_240 = (uint)(iVar2 == 0);
    iVar2 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar2 == 0) || (local_240 != 0)) {
      local_23c = FUN_10003960(local_18,param_1);
      if (local_23c < 0) goto LAB_10004db9;
      if (param_3 == 0) goto LAB_10004757;
      FUN_10004e20(local_24c,0);
      local_8._0_1_ = 1;
      pWVar3 = FUN_100044b0(param_1,L'\\');
      if (pWVar3 == (LPCWSTR)0x0) {
        iVar2 = FUN_10005d40(param_1);
        if (iVar2 != 0) {
          FUN_10004ee0(local_24c,param_2);
          FUN_100053a0(param_1);
          FUN_10004ea0(local_24c);
        }
        if (local_240 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004e60(local_24c);
          goto LAB_10004757;
        }
        local_23c = FUN_10003960(local_18,param_1);
        if (local_23c < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004e60(local_24c);
        }
        else {
          local_23c = FUN_10005df0(local_18,param_1);
          if (-1 < local_23c) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_10004e60(local_24c);
            goto LAB_10004d50;
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004e60(local_24c);
        }
        goto LAB_10004db9;
      }
      FUN_10003830();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10004e60(local_24c);
      local_8 = 0xffffffff;
      FUN_10004e60((int *)local_24);
      goto LAB_10004dda;
    }
LAB_10004757:
    iVar2 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar2 == 0) {
      local_234 = 0;
      local_23c = FUN_10003960(local_18,param_1);
      if (local_23c < 0) goto LAB_10004db9;
    }
    iVar2 = lstrcmpiW(param_1,L"Val");
    if (iVar2 == 0) {
      local_23c = FUN_10003960(local_18,local_224c);
      if ((local_23c < 0) || (local_23c = FUN_10003960(local_18,param_1), local_23c < 0))
      goto LAB_10004db9;
      if (*param_1 != L'=') {
        FUN_10003830();
        local_8 = 0xffffffff;
        FUN_10004e60((int *)local_24);
        goto LAB_10004dda;
      }
      if (param_3 != 0) {
        FUN_10004e20(local_2258,0);
        local_8._0_1_ = 2;
        FUN_10004ee0(local_2258,param_2);
        local_23c = FUN_100054f0(local_18,local_2258,local_224c,param_1);
        FUN_10004ea0(local_2258);
        if (-1 < local_23c) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004e60(local_2258);
          goto LAB_10004d50;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10004e60(local_2258);
        local_8 = 0xffffffff;
        FUN_10004e60((int *)local_24);
        goto LAB_10004dda;
      }
      if ((param_4 == 0) && (local_234 != 0)) {
        FUN_10004e20(local_2264,0);
        local_8._0_1_ = 3;
        local_28 = FUN_10005260(local_2264,param_2,(LPCWSTR)0x0,0x20006);
        if (local_28 != 0) {
          local_23c = FUN_10004e00(local_28);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004e60(local_2264);
          goto LAB_10004db9;
        }
        local_28 = FUN_10005060(local_2264,local_224c);
        if ((local_28 != 0) && (local_28 != 2)) {
          local_23c = FUN_10004e00(local_28);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004e60(local_2264);
          goto LAB_10004db9;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10004e60(local_2264);
      }
      local_23c = FUN_10005df0(local_18,param_1);
joined_r0x100049b2:
      if (local_23c < 0) goto LAB_10004db9;
      goto LAB_100045b4;
    }
    pWVar3 = FUN_100044b0(param_1,L'\\');
    if (pWVar3 != (LPCWSTR)0x0) {
      FUN_10003830();
      local_8 = 0xffffffff;
      FUN_10004e60((int *)local_24);
      goto LAB_10004dda;
    }
    if (param_3 == 0) {
      if (param_4 == 0) {
        local_28 = FUN_10005260(local_24,param_2,param_1,0x20019);
      }
      else {
        local_28 = 2;
      }
      if (local_28 != 0) {
        param_4 = 1;
      }
      FUN_10004040(local_230,0x104,param_1,0xffffffff);
      local_23c = FUN_10003960(local_18,param_1);
      if (((local_23c < 0) || (local_23c = FUN_10005df0(local_18,param_1), local_23c < 0)) ||
         (((*param_1 == L'{' && (iVar2 = lstrlenW(param_1), iVar2 == 1)) &&
          (((local_23c = FUN_10004510(param_1,local_24[0],0,param_4), local_23c < 0 &&
            (param_4 == 0)) || (local_23c = FUN_10003960(local_18,param_1), local_23c < 0))))))
      goto LAB_10004db9;
      param_4 = local_238;
      if (local_28 == 2) goto LAB_100045b4;
      if (local_28 != 0) {
        if (local_238 == 0) goto LAB_10004c0c;
        goto LAB_100045b4;
      }
      if (local_238 != 0) {
        pHVar4 = (HKEY)FUN_10004e80(local_24);
        bVar1 = FUN_10005da0(pHVar4);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          iVar2 = FUN_10005d40(local_230);
          if ((iVar2 != 0) && (local_234 != 0)) {
            FUN_100053a0(local_230);
          }
          goto LAB_100045b4;
        }
      }
      pHVar4 = (HKEY)FUN_10004e80(local_24);
      bVar1 = FUN_10005da0(pHVar4);
      local_2268 = CONCAT31(extraout_var_00,bVar1);
      local_28 = FUN_10005090((int *)local_24);
      if (local_28 != 0) {
        FUN_10004e00(local_28);
        local_8 = 0xffffffff;
        FUN_10004e60((int *)local_24);
        goto LAB_10004dda;
      }
      if ((local_234 != 0) && (local_2268 == 0)) {
        FUN_10004e20(local_2274,0);
        local_8._0_1_ = 4;
        FUN_10004ee0(local_2274,param_2);
        local_28 = FUN_10004f20(local_2274,local_230);
        FUN_10004ea0(local_2274);
        if (local_28 == 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10004e60(local_2274);
          goto LAB_10004d50;
        }
        local_23c = FUN_10004e00(local_28);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10004e60(local_2274);
        goto LAB_10004db9;
      }
    }
    else {
      local_28 = FUN_10005260(local_24,param_2,param_1,0x2001f);
      if (((local_28 != 0) &&
          (local_28 = FUN_10005260(local_24,param_2,param_1,0x20019), local_28 != 0)) &&
         (local_28 = FUN_100050e0(local_24,param_2,param_1,(LPWSTR)0x0,0,0x2001f,
                                  (LPSECURITY_ATTRIBUTES)0x0,(DWORD *)0x0), local_28 != 0)) {
        FUN_10004e00(local_28);
        local_8 = 0xffffffff;
        FUN_10004e60((int *)local_24);
        goto LAB_10004dda;
      }
      local_23c = FUN_10003960(local_18,param_1);
      if ((local_23c < 0) ||
         ((*param_1 == L'=' &&
          (local_23c = FUN_100054f0(local_18,local_24,(LPCWSTR)0x0,param_1), local_23c < 0))))
      goto LAB_10004db9;
    }
LAB_10004d50:
    if (((param_3 != 0) && (*param_1 == L'{')) && (iVar2 = lstrlenW(param_1), iVar2 == 1)) {
      local_23c = FUN_10004510(param_1,local_24[0],param_3,0);
      if (-1 < local_23c) {
        local_23c = FUN_10003960(local_18,param_1);
        goto joined_r0x100049b2;
      }
      goto LAB_10004db9;
    }
    goto LAB_100045b4;
  }
  local_8 = 0xffffffff;
  FUN_10004e60((int *)local_24);
LAB_10004dda:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_10004c0c:
  local_23c = FUN_10004e00(local_28);
LAB_10004db9:
  local_8 = 0xffffffff;
  FUN_10004e60((int *)local_24);
  goto LAB_10004dda;
}



// Function: FUN_10004e00 at 10004e00

void __cdecl FUN_10004e00(uint param_1)

{
  FUN_100024c0(param_1);
  return;
}



// Function: FUN_10004e20 at 10004e20

undefined4 * __thiscall FUN_10004e20(void *this,undefined4 param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_10004e60 at 10004e60

void __fastcall FUN_10004e60(int *param_1)

{
  FUN_10005090(param_1);
  return;
}



// Function: FUN_10004e80 at 10004e80

undefined4 __fastcall FUN_10004e80(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10004ea0 at 10004ea0

undefined4 __fastcall FUN_10004ea0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return uVar1;
}



// Function: FUN_10004ee0 at 10004ee0

void __thiscall FUN_10004ee0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}



// Function: FUN_10004f20 at 10004f20

void __thiscall FUN_10004f20(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(int *)((int)this + 8) == 0) {
    if (DAT_10043bd4 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_10043bd0 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_10043bd4 = '\x01';
    }
    if (DAT_10043bd0 == (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      RegDeleteKeyW(*this,param_1);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      (*DAT_10043bd0)(*this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    FUN_10004fd0(*(void **)((int)this + 8),*this,param_1);
  }
  return;
}



// Function: FUN_10004fd0 at 10004fd0

LSTATUS __thiscall FUN_10004fd0(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegDeleteKeyW(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_10005060 at 10005060

void __thiscall FUN_10005060(void *this,LPCWSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegDeleteValueW(*this,param_1);
  return;
}



// Function: FUN_10005090 at 10005090

LSTATUS __fastcall FUN_10005090(int *param_1)

{
  LSTATUS local_c;
  
  local_c = 0;
  if (*param_1 != 0) {
    local_c = RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return local_c;
}



// Function: FUN_100050e0 at 100050e0

LSTATUS __thiscall
FUN_100050e0(void *this,HKEY param_1,LPCWSTR param_2,LPWSTR param_3,DWORD param_4,uint param_5,
            LPSECURITY_ATTRIBUTES param_6,DWORD *param_7)

{
  int local_58;
  LSTATUS local_14;
  HKEY local_10;
  DWORD local_c;
  int *local_8;
  
  local_10 = (HKEY)0x0;
  local_8 = (int *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_58 = RegCreateKeyExW(param_1,param_2,0,param_3,param_4,param_5,param_6,&local_10,&local_c)
    ;
  }
  else {
    local_58 = FUN_100051a0(*(void **)((int)this + 8),param_1,param_2,0,param_3,param_4,param_5,
                            param_6,&local_10,&local_c);
  }
  local_14 = local_58;
  if (param_7 != (DWORD *)0x0) {
    *param_7 = local_c;
  }
  if (local_58 == 0) {
    local_14 = FUN_10005090(local_8);
    *local_8 = (int)local_10;
    local_8[1] = param_5 & 0x300;
  }
  return local_14;
}



// Function: FUN_100051a0 at 100051a0

LSTATUS __thiscall
FUN_100051a0(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,LPWSTR param_4,DWORD param_5,
            REGSAM param_6,LPSECURITY_ATTRIBUTES param_7,PHKEY param_8,LPDWORD param_9)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegCreateKeyExW(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                              param_9);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegCreateKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                        *this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_10005260 at 10005260

LSTATUS __thiscall FUN_10005260(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int local_54;
  LSTATUS local_10;
  HKEY local_c;
  int *local_8;
  
  local_c = (HKEY)0x0;
  local_8 = (int *)this;
  if (*(int *)((int)this + 8) == 0) {
    local_54 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_c);
  }
  else {
    local_54 = FUN_10005300(*(void **)((int)this + 8),param_1,param_2,0,param_3,&local_c);
  }
  local_10 = local_54;
  if (local_54 == 0) {
    local_10 = FUN_10005090(local_8);
    *local_8 = (int)local_c;
    local_8[1] = param_3 & 0x300;
  }
  return local_10;
}



// Function: FUN_10005300 at 10005300

LSTATUS __thiscall
FUN_10005300(void *this,HKEY param_1,LPCWSTR param_2,DWORD param_3,REGSAM param_4,PHKEY param_5)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == 0) {
    if (*(int *)((int)this + 4) != 0) {
      LVar3 = RegOpenKeyExW(param_1,param_2,param_3,param_4,param_5);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    if (hModule == (HMODULE)0x0) {
      return 1;
    }
    pFVar1 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (*pFVar1)(param_1,param_2,param_3,param_4,param_5,*this,0);
      return iVar2;
    }
  }
  return 1;
}



// Function: FUN_100053a0 at 100053a0

void FUN_100053a0(LPCWSTR param_1)

{
  LSTATUS LVar1;
  WCHAR local_234 [256];
  DWORD local_34;
  _FILETIME local_30;
  LSTATUS local_28;
  HKEY local_24 [3];
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d318;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10004e20(local_24,0);
  local_8 = 0;
  local_28 = FUN_10005260(local_24,(HKEY)*local_18,param_1,local_18[1] | 0x2001f);
  if (local_28 == 0) {
    do {
      local_34 = 0x100;
      LVar1 = RegEnumKeyExW(local_24[0],0,local_234,&local_34,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                            &local_30);
      if (LVar1 != 0) {
        FUN_10005090((int *)local_24);
        FUN_10004f20(local_18,param_1);
        local_8 = 0xffffffff;
        FUN_10004e60((int *)local_24);
        goto LAB_100054c9;
      }
      local_28 = FUN_100053a0(local_234);
    } while (local_28 == 0);
    local_8 = 0xffffffff;
    FUN_10004e60((int *)local_24);
  }
  else {
    local_8 = 0xffffffff;
    FUN_10004e60((int *)local_24);
  }
LAB_100054c9:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100054f0 at 100054f0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_100054f0(void *this,void *param_1,LPCWSTR param_2,undefined2 *param_3)

{
  int iVar1;
  uint uStack_22c4;
  undefined4 auStack_2268 [65];
  uint uStack_2164;
  uint uStack_2160;
  undefined4 uStack_215c;
  int aiStack_2158 [3];
  undefined4 uStack_214c;
  undefined1 auStack_2144 [16];
  undefined4 local_2134 [65];
  uint local_2030;
  undefined4 local_202c;
  uint local_2028;
  ushort local_2024 [2];
  WCHAR local_2020 [4096];
  int local_20;
  undefined4 *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d361;
  local_10 = ExceptionList;
  uStack_22c4 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_22c4;
  ExceptionList = &local_10;
  local_2024[0] = 0;
  local_2028 = 0;
  local_202c = 0;
  local_1c = (undefined4 *)this;
  local_18 = uStack_22c4;
  local_20 = FUN_10003960(this,local_2020);
  if (-1 < local_20) {
    iVar1 = FUN_10005ba0(local_2020,local_2024);
    if (iVar1 == 0) {
      FUN_10003830();
    }
    else {
      FUN_100038b0(local_1c);
      local_20 = FUN_10003960(local_1c,local_2020);
      if (-1 < local_20) {
        if (local_2024[0] < 0x14) {
          if (local_2024[0] == 0x13) {
            uStack_214c = FUN_10002a10();
            FUN_10008090(aiStack_2158);
            local_8 = 3;
            uStack_215c = FUN_10002a90(local_2020);
            Ordinal_277(uStack_215c,0,0,auStack_2144);
            local_2028 = FUN_10005a50(param_1,param_2);
            local_8 = 0xffffffff;
            FUN_100080b0(aiStack_2158);
          }
          else if (local_2024[0] == 8) {
            local_2028 = FUN_10005a90(param_1,param_2,local_2020,1);
          }
          else if (local_2024[0] == 0x11) {
            uStack_2160 = lstrlenW(local_2020);
            if ((uStack_2160 & 1) == 0) {
              uStack_2164 = (int)uStack_2160 / 2;
              FUN_100091c0(auStack_2268);
              local_8 = 5;
              FUN_10009230(auStack_2268,uStack_2164);
              FUN_100058bf();
              return;
            }
            goto LAB_10005a2b;
          }
        }
        else if (local_2024[0] == 0x4008) {
          iVar1 = lstrlenW(local_2020);
          local_2030 = iVar1 + 2;
          FUN_10009120(local_2134);
          local_8 = 1;
          FUN_10009190(local_2134,local_2030);
          FUN_10005676();
          return;
        }
        if (local_2028 == 0) {
          local_20 = FUN_10003960(local_1c,param_3);
        }
        else {
          local_202c = 0x204;
          FUN_10004e00(local_2028);
        }
      }
    }
  }
LAB_10005a2b:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10005669 at 10005669

undefined4 Catch_10005669(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000567d;
}



// Function: FUN_10005676 at 10005676

void FUN_10005676(void)

{
  int iVar1;
  undefined4 uVar2;
  LPWSTR pWVar3;
  LPCWSTR pWVar4;
  LSTATUS LVar5;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  iVar1 = FUN_10009170((undefined4 *)(unaff_EBP - 0x2130));
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP - 0x2024) = 0xe;
  }
  else {
    uVar2 = FUN_10009170((undefined4 *)(unaff_EBP - 0x2130));
    *(undefined4 *)(unaff_EBP - 0x2134) = uVar2;
    *(uint *)(unaff_EBP - 0x2138) = unaff_EBP - 0x201c;
    *(undefined4 *)(unaff_EBP - 0x202c) = 0;
    while (**(short **)(unaff_EBP - 0x2138) != 0) {
      pWVar3 = CharNextW(*(LPCWSTR *)(unaff_EBP - 0x2138));
      *(LPWSTR *)(unaff_EBP - 0x213c) = pWVar3;
      if ((**(short **)(unaff_EBP - 0x2138) == 0x5c) && (**(short **)(unaff_EBP - 0x213c) == 0x30))
      {
        **(undefined2 **)(unaff_EBP - 0x2134) = 0;
        *(int *)(unaff_EBP - 0x2134) = *(int *)(unaff_EBP - 0x2134) + 2;
        pWVar3 = CharNextW(*(LPCWSTR *)(unaff_EBP - 0x213c));
        *(LPWSTR *)(unaff_EBP - 0x2138) = pWVar3;
      }
      else {
        **(undefined2 **)(unaff_EBP - 0x2134) = **(undefined2 **)(unaff_EBP - 0x2138);
        *(int *)(unaff_EBP - 0x2134) = *(int *)(unaff_EBP - 0x2134) + 2;
        *(int *)(unaff_EBP - 0x2138) = *(int *)(unaff_EBP - 0x2138) + 2;
      }
      *(int *)(unaff_EBP - 0x202c) = *(int *)(unaff_EBP - 0x202c) + 1;
    }
    **(undefined2 **)(unaff_EBP - 0x2134) = 0;
    *(int *)(unaff_EBP - 0x2134) = *(int *)(unaff_EBP - 0x2134) + 2;
    **(undefined2 **)(unaff_EBP - 0x2134) = 0;
    pWVar4 = (LPCWSTR)FUN_10009170((undefined4 *)(unaff_EBP - 0x2130));
    LVar5 = FUN_10005b00(*(void **)(unaff_EBP + 8),*(LPCWSTR *)(unaff_EBP + 0xc),pWVar4);
    *(LSTATUS *)(unaff_EBP - 0x2024) = LVar5;
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10009140((int *)(unaff_EBP - 0x2130));
  if (*(int *)(unaff_EBP - 0x2024) == 0) {
    uVar2 = FUN_10003960(*(void **)(unaff_EBP - 0x18),*(undefined2 **)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP - 0x1c) = uVar2;
  }
  else {
    *(undefined4 *)(unaff_EBP - 0x2028) = 0x204;
    FUN_10004e00(*(uint *)(unaff_EBP - 0x2024));
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10005a43;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100058b2 at 100058b2

undefined4 Catch_100058b2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return 0x100058c6;
}



// Function: FUN_100058bf at 100058bf

void FUN_100058bf(void)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  BYTE *lpData;
  HKEY hKey;
  LSTATUS LVar3;
  undefined4 uVar4;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  LPCWSTR lpValueName;
  DWORD Reserved;
  DWORD dwType;
  size_t _Size;
  DWORD cbData;
  
  *(undefined4 *)(unaff_EBP - 4) = 4;
  iVar1 = FUN_10009210((undefined4 *)(unaff_EBP - 0x2264));
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_EBP - 0x22ac) = 0x80004005;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    FUN_100091e0((int *)(unaff_EBP - 0x2264));
  }
  else {
    _Size = *(size_t *)(unaff_EBP - 0x2160);
    iVar1 = 0;
    _Dst = (void *)FUN_10009210((undefined4 *)(unaff_EBP - 0x2264));
    memset(_Dst,iVar1,_Size);
    *(undefined4 *)(unaff_EBP - 0x2268) = 0;
    while (*(int *)(unaff_EBP - 0x2268) < *(int *)(unaff_EBP - 0x215c)) {
      iVar1 = FUN_10009210((undefined4 *)(unaff_EBP - 0x2264));
      *(int *)(unaff_EBP - 0x22b0) = iVar1 + *(int *)(unaff_EBP - 0x2268) / 2;
      uVar2 = FUN_10005ca0(*(ushort *)((unaff_EBP - 0x201c) + *(int *)(unaff_EBP - 0x2268) * 2));
      **(byte **)(unaff_EBP - 0x22b0) =
           **(byte **)(unaff_EBP - 0x22b0) |
           (byte)((uVar2 & 0xff) <<
                 (('\x01' - ((byte)*(undefined4 *)(unaff_EBP - 0x2268) & 1)) * '\x04' & 0x1f));
      *(int *)(unaff_EBP - 0x2268) = *(int *)(unaff_EBP - 0x2268) + 1;
    }
    cbData = *(DWORD *)(unaff_EBP - 0x2160);
    lpData = (BYTE *)FUN_10009210((undefined4 *)(unaff_EBP - 0x2264));
    dwType = 3;
    Reserved = 0;
    lpValueName = *(LPCWSTR *)(unaff_EBP + 0xc);
    hKey = (HKEY)FUN_10004e80(*(undefined4 **)(unaff_EBP + 8));
    LVar3 = RegSetValueExW(hKey,lpValueName,Reserved,dwType,lpData,cbData);
    *(LSTATUS *)(unaff_EBP - 0x2024) = LVar3;
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    FUN_100091e0((int *)(unaff_EBP - 0x2264));
    if (*(int *)(unaff_EBP - 0x2024) == 0) {
      uVar4 = FUN_10003960(*(void **)(unaff_EBP - 0x18),*(undefined2 **)(unaff_EBP + 0x10));
      *(undefined4 *)(unaff_EBP - 0x1c) = uVar4;
    }
    else {
      *(undefined4 *)(unaff_EBP - 0x2028) = 0x204;
      FUN_10004e00(*(uint *)(unaff_EBP - 0x2024));
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10005a43;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10005a50 at 10005a50

void __thiscall FUN_10005a50(void *this,LPCWSTR param_1)

{
                    /* WARNING: Load size is inaccurate */
  RegSetValueExW(*this,param_1,0,4,&stack0x00000008,4);
  return;
}



// Function: FUN_10005a90 at 10005a90

LSTATUS __thiscall FUN_10005a90(void *this,LPCWSTR param_1,LPCWSTR param_2,DWORD param_3)

{
  LSTATUS LVar1;
  int iVar2;
  
  if (param_2 == (LPCWSTR)0x0) {
    LVar1 = 0xd;
  }
  else {
    iVar2 = lstrlenW(param_2);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExW(*this,param_1,0,param_3,(BYTE *)param_2,iVar2 * 2 + 2);
  }
  return LVar1;
}



// Function: FUN_10005b00 at 10005b00

LSTATUS __thiscall FUN_10005b00(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD local_10;
  LPCWSTR local_c;
  
  if (param_2 == (LPCWSTR)0x0) {
    LVar1 = 0xd;
  }
  else {
    local_10 = 0;
    local_c = param_2;
    do {
      iVar2 = lstrlenW(local_c);
      iVar2 = iVar2 + 1;
      local_c = local_c + iVar2;
      local_10 = local_10 + iVar2 * 2;
    } while (iVar2 != 1);
                    /* WARNING: Load size is inaccurate */
    LVar1 = RegSetValueExW(*this,param_1,0,7,(BYTE *)param_2,local_10);
  }
  return LVar1;
}



// Function: FUN_10005ba0 at 10005ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10005ba0(LPCWSTR param_1,undefined2 *param_2)

{
  int iVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d39e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_10043bf8 & 1) == 0) {
    DAT_10043bf8 = DAT_10043bf8 | 1;
    _DAT_10043bd8 = &DAT_10036958;
    _DAT_10043bdc = 8;
    _DAT_10043be0 = &DAT_10036954;
    _DAT_10043be4 = 0x4008;
    _DAT_10043be8 = &DAT_10036950;
    _DAT_10043bec = 0x13;
    _DAT_10043bf0 = &DAT_1003694c;
    _DAT_10043bf4 = 0x11;
  }
  local_8 = 0xffffffff;
  local_14 = 0;
  while( true ) {
    if (3 < local_14) {
      ExceptionList = local_10;
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,*(LPCWSTR *)(&DAT_10043bd8 + local_14 * 8));
    if (iVar1 == 0) break;
    local_14 = local_14 + 1;
  }
  *param_2 = *(undefined2 *)(&DAT_10043bdc + local_14 * 8);
  ExceptionList = local_10;
  return 1;
}



// Function: FUN_10005ca0 at 10005ca0

uint __cdecl FUN_10005ca0(ushort param_1)

{
  uint uVar1;
  
  switch(param_1) {
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
    uVar1 = param_1 - 0x30;
    break;
  default:
    uVar1 = 0;
    break;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
    uVar1 = param_1 - 0x37;
    break;
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
    uVar1 = param_1 - 0x57;
  }
  return uVar1;
}



// Function: FUN_10005d40 at 10005d40

undefined4 FUN_10005d40(LPCWSTR param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0xb < local_c) {
      return 1;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_AppID_10036b1c)[local_c]);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return 0;
}



// Function: FUN_10005da0 at 10005da0

bool FUN_10005da0(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_c [2];
  
  local_c[0] = 0;
  LVar1 = RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,local_c,(LPDWORD)0x0,
                           (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                           (PFILETIME)0x0);
  return LVar1 == 0 && local_c[0] != 0;
}



// Function: FUN_10005df0 at 10005df0

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_10005df0(void *this,short *param_1)

{
  undefined2 local_2010 [4096];
  int local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = (undefined4 *)this;
  if ((*param_1 == 0x3d) && (local_10 = FUN_10003960(this,param_1), -1 < local_10)) {
    FUN_100038b0(local_c);
    local_10 = FUN_10003960(local_c,local_2010);
    if (-1 < local_10) {
      local_10 = FUN_10003960(local_c,param_1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10005e90 at 10005e90

undefined4 * __fastcall FUN_10005e90(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d3cb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10005f00(param_1);
  *param_1 = ATL::CRegObject::vftable;
  FUN_10005f20(param_1 + 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10005f00 at 10005f00

undefined4 __fastcall FUN_10005f00(undefined4 param_1)

{
  FUN_100025e0(param_1);
  return param_1;
}



// Function: FUN_10005f20 at 10005f20

undefined4 * __fastcall FUN_10005f20(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d3f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10008d70(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10005f80 at 10005f80

undefined4 FUN_10005f80(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_10043bb4;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10005fb0 at 10005fb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_10005fb0(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_10;
  int *local_c;
  
  if (param_3 != (undefined4 *)0x0) {
    _DAT_10043bbc = *param_3;
    _DAT_10043bc0 = param_3[1];
    _DAT_10043bc4 = param_3[2];
    _DAT_10043bc8 = param_3[3];
  }
  if ((param_1 != -1) && (*(int *)((int)this + 0x2c) = param_1, *(int *)((int)this + 0x2c) != 0)) {
    for (local_c = *(int **)((int)this + 0x2c); *local_c != 0; local_c = local_c + 9) {
      (*(code *)local_c[8])(1);
    }
  }
  for (local_10 = DAT_100458e4; local_10 < DAT_100458e8; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x20))(1);
    }
  }
  return 0;
}



// Function: FUN_10006070 at 10006070

void __fastcall FUN_10006070(int param_1)

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
  for (local_10 = DAT_100458e4; local_10 < DAT_100458e8; local_10 = local_10 + 1) {
    if (*local_10 != 0) {
      (**(code **)(*local_10 + 0x20))(0);
    }
  }
  FUN_10006120(param_1);
  return;
}



// Function: FUN_10006120 at 10006120

void __fastcall FUN_10006120(int param_1)

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
      FUN_10006cc0(local_4c);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      (**(code **)(**(int **)(param_1 + 0x28) + 8))(*(undefined4 *)(param_1 + 0x28));
    }
    FUN_10002430((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function: FUN_100061b0 at 100061b0

int __thiscall FUN_100061b0(void *this,int *param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 local_24 [2];
  int *local_1c;
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d428;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_3 = 0;
  local_18 = 0;
  local_14 = this;
  if (*(int *)((int)this + 0x2c) != 0) {
    for (local_1c = *(int **)((int)this + 0x2c); *local_1c != 0; local_1c = local_1c + 9) {
      if ((local_1c[2] != 0) && (iVar2 = FUN_10006320(param_1,(int *)*local_1c), iVar2 != 0)) {
        if (local_1c[4] == 0) {
          FUN_10009bc0(local_24,&DAT_100458ec,'\0');
          local_8 = 0;
          local_18 = FUN_10009c40(local_24);
          if (local_18 < 0) {
            local_8 = 0xffffffff;
            FUN_10009c10(local_24);
            break;
          }
          if (local_1c[4] == 0) {
            local_18 = (*(code *)local_1c[2])(local_1c[3],&DAT_10036f3c,local_1c + 4,uVar1);
          }
          local_8 = 0xffffffff;
          FUN_10009c10(local_24);
        }
        if (local_1c[4] != 0) {
          local_18 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_2,param_3);
        }
        break;
      }
    }
  }
  if ((*param_3 == 0) && (local_18 == 0)) {
    local_18 = FUN_10006b20((int *)&DAT_100458dc,param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10006320 at 10006320

undefined4 __cdecl FUN_10006320(int *param_1,int *param_2)

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



// Function: FUN_10006380 at 10006380

int __thiscall FUN_10006380(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int *local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_10006430(param_2,(void *)*local_10), CONCAT31(extraout_var,bVar1) != 0)) {
        local_c = (*(code *)local_10[1])(1);
        if (local_c < 0) break;
        iVar3 = 1;
        piVar2 = (int *)(*(code *)local_10[7])();
        local_c = FUN_10006460((GUID *)*local_10,piVar2,iVar3);
        if (local_c < 0) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_10008110(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_10006430 at 10006430

bool __cdecl FUN_10006430(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: FUN_10006460 at 10006460

void FUN_10006460(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  LPVOID *ppv;
  int *piVar3;
  HKEY pHVar4;
  LSTATUS LVar5;
  LPWSTR pWVar6;
  LPDWORD pDVar7;
  LPDWORD pDVar8;
  DWORD *pDVar9;
  LPDWORD pDVar10;
  LPDWORD pDVar11;
  LPDWORD pDVar12;
  LPDWORD pDVar13;
  LPDWORD pDVar14;
  wchar_t *pwVar15;
  LPDWORD pDVar16;
  uint uVar17;
  PFILETIME p_Var18;
  DWORD local_1e4;
  int local_1e0 [3];
  int local_1d4 [3];
  wchar_t local_1c8 [128];
  wchar_t *local_c8;
  int local_c4 [3];
  undefined4 local_b8;
  OLECHAR local_b0 [64];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  HRESULT local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d479;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10009260(&local_18);
  local_8 = 0;
  if (param_2 == (int *)0x0) {
    local_8 = 0xffffffff;
    FUN_10006a10(&local_18);
  }
  else {
    iVar2 = FUN_10006320((int *)param_1,&DAT_1003a118);
    if (iVar2 == 0) {
      ppv = (LPVOID *)FUN_100092f0(&local_18);
      local_1c = CoCreateInstance((IID *)&DAT_10039d48,(LPUNKNOWN)0x0,1,(IID *)&DAT_10036fb8,ppv);
      if (local_1c < 0) {
        local_8 = 0xffffffff;
        FUN_10006a10(&local_18);
      }
      else {
        local_1c = 0;
        for (local_20 = param_2; *local_20 != 0; local_20 = local_20 + 2) {
          puVar1 = (undefined4 *)local_20[1];
          local_30 = *puVar1;
          local_2c = puVar1[1];
          local_28 = puVar1[2];
          local_24 = puVar1[3];
          if (param_3 == 0) {
            if (*local_20 == 1) {
              piVar3 = (int *)FUN_10009310(&local_18);
              (**(code **)(*piVar3 + 0x18))(piVar3,param_1,1,&local_30);
            }
            else {
              piVar3 = (int *)FUN_10009310(&local_18);
              (**(code **)(*piVar3 + 0x20))(piVar3,param_1,1,&local_30);
            }
          }
          else {
            if (*local_20 == 1) {
              piVar3 = (int *)FUN_10009310(&local_18);
              local_1c = (**(code **)(*piVar3 + 0x14))(piVar3,param_1,1,&local_30);
            }
            else {
              piVar3 = (int *)FUN_10009310(&local_18);
              local_1c = (**(code **)(*piVar3 + 0x1c))(piVar3,param_1,1,&local_30);
            }
            if (local_1c < 0) {
              local_8 = 0xffffffff;
              FUN_10006a10(&local_18);
              goto LAB_10006928;
            }
          }
        }
        if (param_3 == 0) {
          StringFromGUID2(param_1,local_b0,0x40);
          local_b8 = FUN_10002a10();
          FUN_10008090(local_c4);
          local_8._0_1_ = 1;
          local_c8 = (wchar_t *)FUN_10006950(local_b0);
          if (local_c8 != (wchar_t *)0x0) {
            FUN_10006970(local_1c8,0x80,L"CLSID\\");
            FUN_100069a0(local_1c8,0x80,local_c8);
            FUN_100069a0(local_1c8,0x80,L"\\Required Categories");
            FUN_100069d0(local_1d4,0x80000000);
            local_8._0_1_ = 2;
            FUN_10004e20(local_1e0,0);
            local_8 = CONCAT31(local_8._1_3_,3);
            local_1e4 = 0;
            uVar17 = 0x20019;
            pwVar15 = local_1c8;
            pHVar4 = (HKEY)FUN_10004e80(local_1d4);
            LVar5 = FUN_10005260(local_1e0,pHVar4,pwVar15,uVar17);
            if (LVar5 == 0) {
              p_Var18 = (PFILETIME)0x0;
              pDVar16 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = (LPDWORD)0x0;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = (LPDWORD)0x0;
              pDVar9 = &local_1e4;
              pDVar8 = (LPDWORD)0x0;
              pDVar7 = (LPDWORD)0x0;
              pWVar6 = (LPWSTR)0x0;
              pHVar4 = (HKEY)FUN_10004e80(local_1e0);
              LVar5 = RegQueryInfoKeyW(pHVar4,pWVar6,pDVar7,pDVar8,pDVar9,pDVar10,pDVar11,pDVar12,
                                       pDVar13,pDVar14,pDVar16,p_Var18);
              FUN_10005090(local_1e0);
              if ((LVar5 == 0) && (local_1e4 == 0)) {
                FUN_10004f20(local_1d4,local_1c8);
              }
            }
            FUN_10006970(local_1c8,0x80,L"CLSID\\");
            FUN_100069a0(local_1c8,0x80,local_c8);
            FUN_100069a0(local_1c8,0x80,L"\\Implemented Categories");
            uVar17 = 0x20019;
            pwVar15 = local_1c8;
            pHVar4 = (HKEY)FUN_10004e80(local_1d4);
            LVar5 = FUN_10005260(local_1e0,pHVar4,pwVar15,uVar17);
            if (LVar5 == 0) {
              p_Var18 = (PFILETIME)0x0;
              pDVar16 = (LPDWORD)0x0;
              pDVar14 = (LPDWORD)0x0;
              pDVar13 = (LPDWORD)0x0;
              pDVar12 = (LPDWORD)0x0;
              pDVar11 = (LPDWORD)0x0;
              pDVar10 = (LPDWORD)0x0;
              pDVar9 = &local_1e4;
              pDVar8 = (LPDWORD)0x0;
              pDVar7 = (LPDWORD)0x0;
              pWVar6 = (LPWSTR)0x0;
              pHVar4 = (HKEY)FUN_10004e80(local_1e0);
              LVar5 = RegQueryInfoKeyW(pHVar4,pWVar6,pDVar7,pDVar8,pDVar9,pDVar10,pDVar11,pDVar12,
                                       pDVar13,pDVar14,pDVar16,p_Var18);
              FUN_10005090(local_1e0);
              if ((LVar5 == 0) && (local_1e4 == 0)) {
                FUN_10004f20(local_1d4,local_1c8);
              }
            }
            local_8._0_1_ = 2;
            FUN_10004e60(local_1e0);
            local_8._0_1_ = 1;
            FUN_10004e60(local_1d4);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100080b0(local_c4);
        }
        local_8 = 0xffffffff;
        FUN_10006a10(&local_18);
      }
    }
    else {
      local_8 = 0xffffffff;
      FUN_10006a10(&local_18);
    }
  }
LAB_10006928:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006950 at 10006950

undefined4 __cdecl FUN_10006950(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10006970 at 10006970

void __cdecl FUN_10006970(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscpy_s(param_1,param_2,param_3);
  FUN_10003150(eVar1);
  return;
}



// Function: FUN_100069a0 at 100069a0

void __cdecl FUN_100069a0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = wcscat_s(param_1,param_2,param_3);
  FUN_10003150(eVar1);
  return;
}



// Function: FUN_100069d0 at 100069d0

undefined4 * __thiscall FUN_100069d0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return (undefined4 *)this;
}



// Function: FUN_10006a10 at 10006a10

void __fastcall FUN_10006a10(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d4b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100092c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006a70 at 10006a70

int __thiscall FUN_10006a70(void *this,int param_1,void *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int *local_10;
  int local_c;
  
  local_c = 0;
  local_10 = *(int **)((int)this + 0x2c);
  if (local_10 != (int *)0x0) {
    for (; *local_10 != 0; local_10 = local_10 + 9) {
      if ((param_2 == (void *)0x0) ||
         (bVar1 = FUN_10006430(param_2,(void *)*local_10), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar3 = 0;
        piVar2 = (int *)(*(code *)local_10[7])();
        local_c = FUN_10006460((GUID *)*local_10,piVar2,iVar3);
        if ((local_c < 0) || (local_c = (*(code *)local_10[1])(0), local_c < 0)) break;
      }
    }
  }
  if (-1 < local_c) {
    local_c = FUN_10008a80(param_1,param_2);
  }
  return local_c;
}



// Function: FUN_10006b20 at 10006b20

int FUN_10006b20(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 local_24 [2];
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d4e8;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_4 == (int *)0x0) {
    local_14 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    if (param_1 == (int *)0x0) {
      local_14 = -0x7ff8ffa9;
    }
    else if (*param_1 == 0) {
      local_14 = -0x7fff0001;
    }
    else {
      local_14 = 0;
      for (local_18 = (int *)param_1[2]; local_18 < (int *)param_1[3]; local_18 = local_18 + 1) {
        if (((*local_18 != 0) && (local_1c = (undefined4 *)*local_18, local_1c[2] != 0)) &&
           (iVar2 = FUN_10006320(param_2,(int *)*local_1c), iVar2 != 0)) {
          if (local_1c[4] == 0) {
            FUN_10009bc0(local_24,param_1 + 4,'\0');
            local_8 = 0;
            local_14 = FUN_10009c40(local_24);
            if (local_14 < 0) {
              local_8 = 0xffffffff;
              FUN_10009c10(local_24);
              break;
            }
            if (local_1c[4] == 0) {
              local_14 = (*(code *)local_1c[2])(local_1c[3],&DAT_10036f3c,local_1c + 4,uVar1);
            }
            local_8 = 0xffffffff;
            FUN_10009c10(local_24);
          }
          if (local_1c[4] != 0) {
            local_14 = (*(code *)**(undefined4 **)local_1c[4])(local_1c[4],param_3,param_4);
          }
          break;
        }
      }
      if ((*param_4 == 0) && (local_14 == 0)) {
        local_14 = -0x7ffbfeef;
      }
    }
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10006cc0 at 10006cc0

void FUN_10006cc0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *local_8;
  
  if (param_1 == 0) {
    FUN_10006d40(0xc0000005,1);
  }
  local_8 = *(undefined4 **)(param_1 + 8);
  while (local_8 != (undefined4 *)0x0) {
    (*(code *)*local_8)(local_8[1]);
    puVar1 = (undefined4 *)local_8[2];
    operator_delete(local_8);
    local_8 = puVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10006d40 at 10006d40

void __cdecl FUN_10006d40(DWORD param_1,DWORD param_2)

{
  RaiseException(param_1,param_2,0,(ULONG_PTR *)0x0);
  return;
}



// Function: FUN_10006d70 at 10006d70

undefined4 * __fastcall FUN_10006d70(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10006d90 at 10006d90

void FUN_10006d90(void)

{
  return;
}



// Function: FUN_10006db0 at 10006db0

undefined4 FUN_10006db0(void)

{
  return 0;
}



// Function: FUN_10006dd0 at 10006dd0

undefined4 FUN_10006dd0(void)

{
  return 0;
}



// Function: FUN_10006df0 at 10006df0

void FUN_10006df0(void)

{
  return;
}



// Function: FUN_10006e10 at 10006e10

undefined4 FUN_10006e10(void)

{
  return 0;
}



// Function: FUN_10006e30 at 10006e30

int FUN_10006e30(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_10006e60(param_1,param_2,param_3,param_4);
  return iVar1;
}



// Function: FUN_10006e60 at 10006e60

int FUN_10006e60(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else if (param_4 == (undefined4 *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    iVar1 = FUN_10002540(param_3);
    if (iVar1 == 0) {
      for (; param_2[2] != 0; param_2 = param_2 + 3) {
        iVar1 = *param_2;
        if ((iVar1 == 0) || (iVar2 = FUN_10006320((int *)*param_2,param_3), iVar2 != 0)) {
          if (param_2[2] == 1) {
            piVar3 = (int *)(param_1 + param_2[1]);
            (**(code **)(*piVar3 + 4))(piVar3);
            *param_4 = piVar3;
            return 0;
          }
          iVar2 = (*(code *)param_2[2])(param_1,param_3,param_4,param_2[1]);
          if (iVar2 == 0) {
            return 0;
          }
          if ((iVar1 != 0) && (iVar2 < 0)) {
            return iVar2;
          }
        }
      }
      iVar1 = -0x7fffbffe;
    }
    else {
      piVar3 = (int *)(param_1 + param_2[1]);
      (**(code **)(*piVar3 + 4))(piVar3);
      *param_4 = piVar3;
      iVar1 = 0;
    }
  }
  return iVar1;
}



// Function: FUN_10006f90 at 10006f90

void __fastcall FUN_10006f90(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 4))(*param_1);
  return;
}



// Function: FUN_10006fc0 at 10006fc0

void __fastcall FUN_10006fc0(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 8))(*param_1);
  return;
}



// Function: FUN_10006ff0 at 10006ff0

void __thiscall FUN_10006ff0(void *this,undefined4 param_1,undefined4 param_2)

{
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  (**(code **)**this)(*this,param_1,param_2);
  return;
}



// Function: FUN_10007020 at 10007020

void FUN_10007020(void)

{
  return;
}



// Function: FUN_10007040 at 10007040

void FUN_10007040(void)

{
  return;
}



// Function: FUN_10007060 at 10007060

void FUN_10007060(void)

{
  return;
}



// Function: FUN_10007080 at 10007080

void FUN_10007080(void)

{
  return;
}



// Function: FUN_100070a0 at 100070a0

void FUN_100070a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d518;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10006d90();
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007100 at 10007100

void __fastcall FUN_10007100(int *param_1)

{
  FUN_10007130(param_1);
  return;
}



// Function: FUN_10007130 at 10007130

int FUN_10007130(int *param_1)

{
  *param_1 = *param_1 + 1;
  return *param_1;
}



// Function: FUN_10007160 at 10007160

void __fastcall FUN_10007160(int *param_1)

{
  FUN_10007180(param_1);
  return;
}



// Function: FUN_10007180 at 10007180

int FUN_10007180(int *param_1)

{
  *param_1 = *param_1 + -1;
  return *param_1;
}



// Function: FUN_100071b0 at 100071b0

undefined4 FUN_100071b0(void)

{
  return 0;
}



// Function: FUN_100071d0 at 100071d0

void __thiscall FUN_100071d0(void *this,int *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = FUN_10007200();
  FUN_10006e30((int)this,(int *)ppuVar1,param_1,param_2);
  return;
}



// Function: FUN_10007200 at 10007200

undefined ** FUN_10007200(void)

{
  return &PTR_DAT_10036fc8;
}



// Function: FUN_10007220 at 10007220

void __fastcall FUN_10007220(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d54b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComClassFactory::vftable;
  local_8 = 0xffffffff;
  FUN_10009580((int)(param_1 + 1));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007280 at 10007280

undefined4 FUN_10007280(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0x80004003;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
    if ((param_2 == 0) || (iVar1 = FUN_10002540(param_3), iVar1 != 0)) {
      local_8 = (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
    }
    else {
      local_8 = 0x80040110;
    }
  }
  return local_8;
}



// Function: FUN_100072f0 at 100072f0

undefined4 FUN_100072f0(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(*DAT_10043bb8 + 8))();
  }
  else {
    (**(code **)(*DAT_10043bb8 + 4))();
  }
  return 0;
}



// Function: FUN_10007330 at 10007330

void __thiscall FUN_10007330(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x24) = param_1;
  return;
}



// Function: FUN_10007350 at 10007350

undefined4 * __thiscall FUN_10007350(void *this,uint param_1)

{
  FUN_10007220((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10007390 at 10007390

undefined4 __thiscall FUN_10007390(void *this,int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_100073d0(this,param_2,param_3);
  }
  else {
    uVar1 = 0x8002000b;
  }
  return uVar1;
}



// Function: FUN_100073d0 at 100073d0

undefined4 __thiscall FUN_100073d0(void *this,undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_c;
  
  if (param_2 == (undefined4 *)0x0) {
    local_c = 0x80004003;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      local_c = FUN_10007740(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 0xc) + 4))(*(undefined4 *)((int)this + 0xc));
      local_c = 0;
    }
  }
  return local_c;
}



// Function: FUN_10007450 at 10007450

int __thiscall
FUN_10007450(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  size_t _Size;
  void *_Buf1;
  int iVar2;
  void *_Buf2;
  int local_14;
  int local_c;
  
  local_c = FUN_10007590(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = -0x7fffbffb;
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      iVar1 = FUN_10002a30((LPCWSTR)*param_2);
      local_14 = *(int *)((int)this + 0x18);
      do {
        do {
          local_14 = local_14 + -1;
          if (local_14 < 0) goto LAB_10007530;
        } while (iVar1 != *(int *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc));
        _Size = *(int *)(*(int *)((int)this + 0x14) + 4 + local_14 * 0xc) << 1;
        _Buf2 = (void *)*param_2;
        _Buf1 = (void *)FUN_10007570((undefined4 *)(local_14 * 0xc + *(int *)((int)this + 0x14)));
        iVar2 = memcmp(_Buf1,_Buf2,_Size);
      } while (iVar2 != 0);
      *param_5 = *(undefined4 *)(*(int *)((int)this + 0x14) + 8 + local_14 * 0xc);
      local_c = 0;
    }
LAB_10007530:
    if (local_c < 0) {
      local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                          (*(undefined4 *)((int)this + 0xc),param_2,param_3,param_5);
    }
  }
  return local_c;
}



// Function: FUN_10007570 at 10007570

undefined4 __fastcall FUN_10007570(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10007590 at 10007590

undefined4 __thiscall FUN_10007590(void *this,undefined4 param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    local_c = FUN_10007740(this,param_1);
  }
  return local_c;
}



// Function: FUN_100075d0 at 100075d0

undefined4 __thiscall
FUN_100075d0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 local_c;
  
  local_c = FUN_10007590(this,param_4);
  if (*(int *)((int)this + 0xc) != 0) {
    local_c = (**(code **)(**(int **)((int)this + 0xc) + 0x2c))
                        (*(undefined4 *)((int)this + 0xc),param_1,param_2,param_5,param_6,param_7,
                         param_8,param_9);
  }
  return local_c;
}



// Function: FUN_10007640 at 10007640

undefined4 * __thiscall FUN_10007640(void *this,uint param_1)

{
  if ((param_1 & 2) == 0) {
    FUN_100076c0((undefined4 *)this);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    _eh_vector_destructor_iterator_(this,0xc,*(int *)((int)this + -4),FUN_100076c0);
    if ((param_1 & 1) != 0) {
      operator_delete__((void *)((int)this + -4));
    }
    this = (void *)((int)this + -4);
  }
  return (undefined4 *)this;
}



// Function: FUN_100076c0 at 100076c0

void __fastcall FUN_100076c0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d578;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10007720(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007720 at 10007720

void __fastcall FUN_10007720(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10007740 at 10007740

void __thiscall FUN_10007740(void *this,undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  HMODULE hModule;
  undefined4 uVar3;
  undefined4 *puVar4;
  WCHAR *lpFilename;
  DWORD nSize;
  int local_258;
  int local_254;
  int local_250;
  undefined4 local_24c;
  int local_248 [3];
  undefined4 local_23c;
  DWORD local_234;
  WCHAR local_230 [260];
  int *local_28;
  int local_24;
  undefined4 local_20 [2];
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d5d4;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  local_14 = uVar1;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_10009bc0(local_20,DAT_10043bb8 + 0x10,'\0');
    local_8 = 0;
    local_24 = FUN_10009c40(local_20);
    if (local_24 < 0) {
      local_8 = 0xffffffff;
      FUN_10009c10(local_20);
    }
    else {
      local_24 = -0x7fffbffb;
      if (local_18[3] == 0) {
        local_28 = (int *)0x0;
        iVar2 = FUN_10006320((int *)&DAT_10043bbc,(int *)local_18[1]);
        if (((iVar2 == 0) || (*(short *)(local_18 + 2) != -1)) ||
           (*(short *)((int)local_18 + 10) != -1)) {
          local_24 = Ordinal_162(local_18[1],*(undefined2 *)(local_18 + 2),
                                 *(undefined2 *)((int)local_18 + 10),param_1,&local_28,uVar1);
        }
        else {
          nSize = 0x104;
          lpFilename = local_230;
          hModule = (HMODULE)FUN_10002ab0(0x100458a4);
          local_234 = GetModuleFileNameW(hModule,lpFilename,nSize);
          if ((local_234 != 0) && (local_234 != 0x104)) {
            local_23c = FUN_10002a10();
            FUN_10008090(local_248);
            local_8._0_1_ = 1;
            local_24c = FUN_10002a90(local_230);
            local_24 = Ordinal_161(local_24c,&local_28);
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100080b0(local_248);
          }
        }
        if (-1 < local_24) {
          FUN_10009420(&local_250);
          local_8._0_1_ = 2;
          uVar3 = FUN_10009510(&local_250);
          local_24 = (**(code **)(*local_28 + 0x18))(local_28,*local_18,uVar3);
          if (-1 < local_24) {
            FUN_10009480(&local_254,&local_250);
            local_8._0_1_ = 3;
            FUN_100095f0(&local_258);
            local_8 = CONCAT31(local_8._1_3_,4);
            uVar3 = FUN_10009680(&local_258);
            puVar4 = (undefined4 *)FUN_10009530(&local_250);
            iVar2 = FUN_10009ca0(puVar4,uVar3);
            if (-1 < iVar2) {
              FUN_10009cd0(&local_254,&local_258);
            }
            uVar3 = FUN_10009550(&local_254);
            local_18[3] = uVar3;
            FUN_10007a70(DAT_10043bb8);
            local_8._0_1_ = 3;
            FUN_10008030(&local_258);
            local_8._0_1_ = 2;
            FUN_10007bd0(&local_254);
          }
          (**(code **)(*local_28 + 8))(local_28);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_10007bd0(&local_250);
        }
      }
      else {
        local_24 = 0;
      }
      if ((local_18[3] != 0) && (local_18[5] == 0)) {
        local_24 = FUN_10007c30((int *)local_18[3]);
      }
      local_8 = 0xffffffff;
      FUN_10009c10(local_20);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10007a70 at 10007a70

void __fastcall FUN_10007a70(int param_1)

{
  undefined4 local_4c;
  
  if (param_1 == 0) {
    local_4c = 0;
  }
  else {
    local_4c = param_1 + 4;
  }
  FUN_10007ab0(local_4c);
  return;
}



// Function: FUN_10007ab0 at 10007ab0

undefined4 FUN_10007ab0(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d608;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    return 0x80070057;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new(0xc);
  uVar1 = FUN_10007b23();
  return uVar1;
}



// Function: Catch@10007b16 at 10007b16

undefined4 Catch_10007b16(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10007b2a;
}



// Function: FUN_10007b23 at 10007b23

undefined4 FUN_10007b23(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0x8007000e;
  }
  else {
    **(undefined4 **)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 4) = *(undefined4 *)(unaff_EBP + 0x10);
    FUN_10009bc0((void *)(unaff_EBP + -0x20),*(int *)(unaff_EBP + 8) + 0xc,'\0');
    *(undefined4 *)(unaff_EBP + -4) = 2;
    iVar1 = FUN_10009c40((undefined4 *)(unaff_EBP + -0x20));
    *(int *)(unaff_EBP + -0x14) = iVar1;
    if (*(int *)(unaff_EBP + -0x14) < 0) {
      *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x18);
      operator_delete(*(void **)(unaff_EBP + -100));
    }
    else {
      *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 8) =
           *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8);
      *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8) = *(undefined4 *)(unaff_EBP + -0x18);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_10009c10((undefined4 *)(unaff_EBP + -0x20));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// Function: FUN_10007bd0 at 10007bd0

void __fastcall FUN_10007bd0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d638;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100094e0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10007c30 at 10007c30

undefined4 FUN_10007c30(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uStack_90;
  uint *local_80;
  undefined4 uStack_30;
  undefined4 *puStack_2c;
  int iStack_28;
  uint *local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d673;
  local_10 = ExceptionList;
  uStack_90 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_20 = (**(code **)(*param_1 + 0xc))(param_1,&local_1c);
  if (-1 < local_20) {
    local_24 = (uint *)0x0;
    *(uint *)(local_18 + 0x18) = (uint)*(ushort *)(local_1c + 0x2c);
    *(undefined4 *)(local_18 + 0x14) = 0;
    if (*(int *)(local_18 + 0x18) != 0) {
      local_8 = 0;
      uVar1 = *(uint *)(local_18 + 0x18);
      uVar4 = -(uint)((int)((ulonglong)uVar1 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar1 * 0xc);
      local_80 = (uint *)FUN_1002bb86(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
      local_8._0_1_ = 1;
      if (local_80 == (uint *)0x0) {
        local_80 = (uint *)0x0;
      }
      else {
        *local_80 = uVar1;
        _eh_vector_constructor_iterator_(local_80 + 1,0xc,uVar1,FUN_10007f40,FUN_100076c0);
        local_80 = local_80 + 1;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      local_24 = local_80;
      uVar2 = FUN_10007d43();
      return uVar2;
    }
    for (iStack_28 = 0; iStack_28 < *(int *)(local_18 + 0x18); iStack_28 = iStack_28 + 1) {
      iVar3 = (**(code **)(*param_1 + 0x14))(param_1,iStack_28,&puStack_2c);
      if (-1 < iVar3) {
        FUN_10007e90(&uStack_30);
        local_8 = 3;
        uVar7 = 0;
        uVar6 = 0;
        uVar5 = 0;
        uVar2 = FUN_10007eb0(&uStack_30);
        iVar3 = (**(code **)(*param_1 + 0x30))(param_1,*puStack_2c,uVar2,uVar5,uVar6,uVar7);
        if (-1 < iVar3) {
          iVar3 = FUN_10007f10(&uStack_30);
          FUN_10007ed0((void *)(iStack_28 * 0xc + (int)local_24),iVar3);
          uVar2 = FUN_10007570((undefined4 *)(iStack_28 * 0xc + (int)local_24));
          uVar2 = Ordinal_7(uVar2);
          *(undefined4 *)((int)local_24 + 4 + iStack_28 * 0xc) = uVar2;
          *(undefined4 *)((int)local_24 + 8 + iStack_28 * 0xc) = *puStack_2c;
        }
        (**(code **)(*param_1 + 0x50))(param_1,puStack_2c);
        local_8 = 0xffffffff;
        FUN_10007720(&uStack_30);
      }
    }
    *(uint **)(local_18 + 0x14) = local_24;
    (**(code **)(*param_1 + 0x4c))(param_1,local_1c);
  }
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10007d36 at 10007d36

undefined4 Catch_10007d36(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10007d4a;
}



// Function: FUN_10007d43 at 10007d43

undefined4 FUN_10007d43(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x4c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    uVar1 = 0x8007000e;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    while (*(int *)(unaff_EBP + -0x24) < *(int *)(*(int *)(unaff_EBP + -0x14) + 0x18)) {
      iVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x14))
                        (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x24),
                         unaff_EBP + -0x28);
      if (-1 < iVar2) {
        FUN_10007e90((undefined4 *)(unaff_EBP + -0x2c));
        *(undefined4 *)(unaff_EBP + -4) = 3;
        uVar5 = 0;
        uVar4 = 0;
        uVar3 = 0;
        uVar1 = FUN_10007eb0(unaff_EBP + -0x2c);
        iVar2 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x30))
                          (*(undefined4 *)(unaff_EBP + 8),**(undefined4 **)(unaff_EBP + -0x28),uVar1
                           ,uVar3,uVar4,uVar5);
        if (-1 < iVar2) {
          iVar2 = FUN_10007f10((undefined4 *)(unaff_EBP + -0x2c));
          FUN_10007ed0((void *)(*(int *)(unaff_EBP + -0x24) * 0xc + *(int *)(unaff_EBP + -0x20)),
                       iVar2);
          uVar1 = FUN_10007570((undefined4 *)
                               (*(int *)(unaff_EBP + -0x24) * 0xc + *(int *)(unaff_EBP + -0x20)));
          uVar1 = Ordinal_7(uVar1);
          *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 4 + *(int *)(unaff_EBP + -0x24) * 0xc) =
               uVar1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 8 + *(int *)(unaff_EBP + -0x24) * 0xc) =
               **(undefined4 **)(unaff_EBP + -0x28);
        }
        (**(code **)(**(int **)(unaff_EBP + 8) + 0x50))
                  (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x28));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_10007720((undefined4 *)(unaff_EBP + -0x2c));
      }
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
    }
    *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14) = *(undefined4 *)(unaff_EBP + -0x20);
    (**(code **)(**(int **)(unaff_EBP + 8) + 0x4c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18));
    uVar1 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}



// Function: FUN_10007e90 at 10007e90

undefined4 * __fastcall FUN_10007e90(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10007eb0 at 10007eb0

undefined4 __fastcall FUN_10007eb0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10007ed0 at 10007ed0

void __thiscall FUN_10007ed0(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(int *)this = param_1;
  }
  return;
}



// Function: FUN_10007f10 at 10007f10

undefined4 __fastcall FUN_10007f10(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10007f40 at 10007f40

undefined4 * __fastcall FUN_10007f40(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d698;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10007e90(param_1);
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10007fb0 at 10007fb0

void FUN_10007fb0(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(undefined4 *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    if (*(void **)(param_1 + 0x14) != (void *)0x0) {
      FUN_10007640(*(void **)(param_1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10008030 at 10008030

void __fastcall FUN_10008030(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d6c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10009650(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008090 at 10008090

undefined4 * __fastcall FUN_10008090(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100080b0 at 100080b0

void __fastcall FUN_100080b0(int *param_1)

{
  void *pvVar1;
  
  while (*param_1 != 0) {
    pvVar1 = (void *)*param_1;
    *param_1 = *(int *)*param_1;
    FUN_100080f0(pvVar1);
  }
  return;
}



// Function: FUN_100080f0 at 100080f0

void __cdecl FUN_100080f0(void *param_1)

{
  free(param_1);
  return;
}



// Function: FUN_10008110 at 10008110

int FUN_10008110(int param_1,void *param_2)

{
  int local_c;
  
  local_c = FUN_10008170(&DAT_100458dc,param_1,param_2);
  if ((-1 < local_c) && (DAT_10043bac != (code *)0x0)) {
    local_c = (*DAT_10043bac)(DAT_100458a8);
  }
  return local_c;
}



// Function: FUN_10008170 at 10008170

void __thiscall FUN_10008170(void *this,int param_1,void *param_2)

{
  FUN_100081a0((int)this,param_1,param_2);
  return;
}



// Function: FUN_100081a0 at 100081a0

int FUN_100081a0(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
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
          (bVar2 = FUN_10006430(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        local_8 = (*(code *)puVar1[1])(1);
        if (local_8 < 0) break;
        iVar4 = 1;
        piVar3 = (int *)(*(code *)puVar1[7])();
        local_8 = FUN_10006460((GUID *)*puVar1,piVar3,iVar4);
        if (local_8 < 0) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10008280(*(HMODULE *)(param_1 + 4),0);
    }
  }
  return local_8;
}



// Function: FUN_10008280 at 10008280

void FUN_10008280(HMODULE param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  rsize_t rVar5;
  int iVar6;
  HMODULE hModule;
  undefined4 uVar7;
  wchar_t *pwVar8;
  char local_235;
  FARPROC local_234;
  wchar_t *local_230;
  wchar_t local_22c [259];
  undefined2 local_26;
  wchar_t *local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d70b;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10007e90(&local_18);
  local_8 = 0;
  FUN_10009330(&local_1c);
  local_8._0_1_ = 1;
  puVar2 = (undefined4 *)FUN_100093e0(&local_1c);
  piVar3 = (int *)FUN_10007eb0(&local_18);
  local_20 = FUN_100085b0(param_1,param_2,piVar3,puVar2);
  if (-1 < local_20) {
    local_24 = (wchar_t *)0x0;
    FUN_10007e90(&local_230);
    local_8 = CONCAT31(local_8._1_3_,2);
    piVar3 = (int *)FUN_10009400(&local_1c);
    uVar4 = FUN_10007eb0(&local_230);
    local_20 = (**(code **)(*piVar3 + 0x24))(piVar3,0xffffffff,0,0,0,uVar4);
    if (-1 < local_20) {
      bVar1 = FUN_10008540((int *)&local_230);
      if (bVar1) {
        rVar5 = FUN_10008520(&local_230);
        FUN_100084e0(local_22c,0x104,local_230,rVar5);
        local_26 = 0;
        iVar6 = FUN_100089a0(local_22c);
        local_22c[iVar6] = L'\0';
        local_24 = local_22c;
      }
    }
    local_234 = (FARPROC)0x0;
    local_235 = '\0';
    local_20 = FUN_10005f80(&local_235);
    if (local_20 < 0) {
      local_8._0_1_ = 1;
      FUN_10007720(&local_230);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10008a20(&local_1c);
      local_8 = 0xffffffff;
      FUN_10007720(&local_18);
      goto LAB_100084b8;
    }
    if (local_235 == '\x01') {
      hModule = GetModuleHandleW(L"OLEAUT32.DLL");
      if (hModule != (HMODULE)0x0) {
        local_234 = GetProcAddress(hModule,"RegisterTypeLibForUser");
      }
    }
    if (local_234 == (FARPROC)0x0) {
      local_234 = Ordinal_163_exref;
    }
    pwVar8 = local_24;
    uVar4 = FUN_10007570(&local_18);
    uVar7 = FUN_100093c0(&local_1c);
    local_20 = (*local_234)(uVar7,uVar4,pwVar8);
    local_8._0_1_ = 1;
    FUN_10007720(&local_230);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10008a20(&local_1c);
  local_8 = 0xffffffff;
  FUN_10007720(&local_18);
LAB_100084b8:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100084e0 at 100084e0

void __cdecl FUN_100084e0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  FUN_10003150(eVar1);
  return;
}



// Function: FUN_10008520 at 10008520

void __fastcall FUN_10008520(undefined4 *param_1)

{
  Ordinal_7(*param_1);
  return;
}



// Function: FUN_10008540 at 10008540

bool __fastcall FUN_10008540(int *param_1)

{
  char cVar1;
  
  cVar1 = FUN_10008570(param_1);
  return (bool)('\x01' - (cVar1 != '\0'));
}



// Function: FUN_10008570 at 10008570

void __fastcall FUN_10008570(int *param_1)

{
  FUN_10008590(param_1);
  return;
}



// Function: FUN_10008590 at 10008590

bool __fastcall FUN_10008590(int *param_1)

{
  return *param_1 == 0;
}



// Function: FUN_100085b0 at 100085b0

void FUN_100085b0(HMODULE param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  wchar_t local_26c [6];
  int local_260;
  undefined4 local_25c;
  uint local_258;
  uint local_254;
  LPCWSTR local_250;
  LPCWSTR local_24c;
  DWORD local_248;
  WCHAR local_244 [270];
  int local_28 [3];
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d748;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_3 != (int *)0x0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = 0;
    *param_4 = 0;
    local_1c = FUN_10002a10();
    FUN_10008090(local_28);
    local_8 = 0;
    local_248 = GetModuleFileNameW(param_1,local_244,0x104);
    if (local_248 == 0) {
      FUN_10002ad0();
      local_8 = 0xffffffff;
      FUN_100080b0(local_28);
    }
    else if (local_248 == 0x104) {
      FUN_100024c0(0x7a);
      local_8 = 0xffffffff;
      FUN_100080b0(local_28);
    }
    else {
      local_24c = (LPCWSTR)0x0;
      local_24c = FUN_10008920(local_244);
      if (param_2 != 0) {
        local_250 = (LPCWSTR)FUN_10002eb0(param_2);
        if (local_250 == (LPCWSTR)0x0) {
          local_8 = 0xffffffff;
          FUN_100080b0(local_28);
          goto LAB_100088f4;
        }
        local_254 = lstrlenW(local_250);
        local_258 = local_248 + local_254;
        if (((local_258 < local_248) || (local_258 < local_254)) || (0x10d < local_258)) {
          local_8 = 0xffffffff;
          FUN_100080b0(local_28);
          goto LAB_100088f4;
        }
        FUN_10006970(local_244 + local_248,0x10e - local_248,local_250);
      }
      local_25c = FUN_10002a90(local_244);
      local_260 = Ordinal_161(local_25c,param_4);
      if (local_260 < 0) {
        builtin_wcsncpy(local_26c,L".tlb",5);
        if (0x104 < ((int)local_24c - (int)local_244 >> 1) + 5U) {
          local_8 = 0xffffffff;
          FUN_100080b0(local_28);
          goto LAB_100088f4;
        }
        FUN_10006970(local_24c,0x10e - ((int)local_24c - (int)local_244 >> 1),local_26c);
        local_25c = FUN_10002a90(local_244);
        local_260 = Ordinal_161(local_25c,param_4);
      }
      if (-1 < local_260) {
        iVar1 = Ordinal_2(local_25c);
        *param_3 = iVar1;
        if (*param_3 == 0) {
          local_260 = -0x7ff8fff2;
        }
      }
      local_8 = 0xffffffff;
      FUN_100080b0(local_28);
    }
  }
LAB_100088f4:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008920 at 10008920

LPCWSTR __cdecl FUN_10008920(LPWSTR param_1)

{
  LPCWSTR local_8;
  
  if (param_1 == (LPWSTR)0x0) {
    local_8 = (LPCWSTR)0x0;
  }
  else {
    local_8 = (LPCWSTR)0x0;
    for (; *param_1 != L'\0'; param_1 = CharNextW(param_1)) {
      if (*param_1 == L'.') {
        local_8 = param_1;
      }
      else if (*param_1 == L'\\') {
        local_8 = (LPCWSTR)0x0;
      }
    }
    if (local_8 == (LPCWSTR)0x0) {
      local_8 = param_1;
    }
  }
  return local_8;
}



// Function: FUN_100089a0 at 100089a0

int FUN_100089a0(LPWSTR param_1)

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



// Function: FUN_10008a20 at 10008a20

void __fastcall FUN_10008a20(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d778;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10009390(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10008a80 at 10008a80

int FUN_10008a80(int param_1,void *param_2)

{
  int local_c;
  
  local_c = 0;
  if (DAT_10043bb0 != (code *)0x0) {
    local_c = (*DAT_10043bb0)();
  }
  if (-1 < local_c) {
    local_c = FUN_10008ad0(&DAT_100458dc,param_1,param_2);
  }
  return local_c;
}



// Function: FUN_10008ad0 at 10008ad0

void __thiscall FUN_10008ad0(void *this,int param_1,void *param_2)

{
  FUN_10008b00((int)this,param_1,param_2);
  return;
}



// Function: FUN_10008b00 at 10008b00

int FUN_10008b00(int param_1,int param_2,void *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
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
          (bVar2 = FUN_10006430(param_3,(void *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar4 = 0;
        piVar3 = (int *)(*(code *)puVar1[7])();
        local_8 = FUN_10006460((GUID *)*puVar1,piVar3,iVar4);
        if ((local_8 < 0) || (local_8 = (*(code *)puVar1[1])(0), local_8 < 0)) break;
      }
    }
    if ((-1 < local_8) && (param_2 != 0)) {
      local_8 = FUN_10008bd0(*(HMODULE *)(param_1 + 4),0);
    }
  }
  return local_8;
}



// Function: FUN_10008bd0 at 10008bd0

int FUN_10008bd0(HMODULE param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
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
  puStack_c = &LAB_1002d7b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10007e90(&local_14);
  local_8 = 0;
  FUN_10009330(&local_18);
  local_8._0_1_ = 1;
  puVar1 = (undefined4 *)FUN_100093e0(&local_18);
  piVar2 = (int *)FUN_10007eb0(&local_14);
  local_1c = FUN_100085b0(param_1,param_2,piVar2,puVar1);
  if (-1 < local_1c) {
    piVar2 = (int *)FUN_10009400(&local_18);
    local_1c = (**(code **)(*piVar2 + 0x1c))(piVar2,&local_20);
    if (-1 < local_1c) {
      local_24 = (FARPROC)0x0;
      local_25 = '\0';
      iVar3 = FUN_10005f80(&local_25);
      local_1c = iVar3;
      if (iVar3 < 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_10008a20(&local_18);
        local_8 = 0xffffffff;
        FUN_10007720(&local_14);
        ExceptionList = local_10;
        return iVar3;
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
      piVar2 = (int *)FUN_10009400(&local_18);
      (**(code **)(*piVar2 + 0x30))(piVar2,local_20);
    }
  }
  iVar3 = local_1c;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10008a20(&local_18);
  local_8 = 0xffffffff;
  FUN_10007720(&local_14);
  ExceptionList = local_10;
  return iVar3;
}



// Function: FUN_10008d70 at 10008d70

undefined4 * __fastcall FUN_10008d70(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_10008db0 at 10008db0

void __fastcall FUN_10008db0(int *param_1)

{
  FUN_10008ea0(param_1);
  return;
}



// Function: FUN_10008dd0 at 10008dd0

undefined4 __fastcall FUN_10008dd0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10008df0 at 10008df0

undefined4 __thiscall FUN_10008df0(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
                    /* WARNING: Load size is inaccurate */
  pvVar1 = _recalloc(*this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    *(void **)this = pvVar1;
    pvVar1 = _recalloc(*(void **)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      *(void **)((int)this + 4) = pvVar1;
      FUN_10009790(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}



// Function: FUN_10008ea0 at 10008ea0

void __fastcall FUN_10008ea0(int *param_1)

{
  int local_c;
  
  if (*param_1 != 0) {
    for (local_c = 0; local_c < param_1[2]; local_c = local_c + 1) {
    }
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



// Function: FUN_10008f20 at 10008f20

undefined4 __thiscall FUN_10008f20(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_10009700(this,param_1);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_10008fa0(this,iVar1);
    uVar2 = *puVar3;
  }
  return uVar2;
}



// Function: FUN_10008f60 at 10008f60

int __thiscall FUN_10008f60(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    FUN_10006d40(0xc000008c,1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this + param_1 * 4;
}



// Function: FUN_10008fa0 at 10008fa0

int __thiscall FUN_10008fa0(void *this,int param_1)

{
  if ((param_1 < 0) || (*(int *)((int)this + 8) <= param_1)) {
    FUN_10006d40(0xc000008c,1);
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}



// Function: FUN_10008fe0 at 10008fe0

undefined4 * __fastcall FUN_10008fe0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10009000 at 10009000

void __fastcall FUN_10009000(undefined4 *param_1)

{
  FUN_10009870(param_1);
  return;
}



// Function: FUN_10009020 at 10009020

void __thiscall FUN_10009020(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: FUN_10009050 at 10009050

undefined4 __fastcall FUN_10009050(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10009080 at 10009080

undefined4 * __fastcall FUN_10009080(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100090a0 at 100090a0

void __fastcall FUN_100090a0(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_100098e0(param_1);
  }
  return;
}



// Function: FUN_100090d0 at 100090d0

undefined4 __fastcall FUN_100090d0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100090f0 at 100090f0

void __thiscall FUN_100090f0(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10009db0(param_1,2);
  FUN_100098a0(this,uVar1);
  return;
}



// Function: FUN_10009120 at 10009120

undefined4 * __fastcall FUN_10009120(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10009140 at 10009140

void __fastcall FUN_10009140(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_10009950(param_1);
  }
  return;
}



// Function: FUN_10009170 at 10009170

undefined4 __fastcall FUN_10009170(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10009190 at 10009190

void __thiscall FUN_10009190(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10009db0(param_1,2);
  FUN_10009910(this,uVar1);
  return;
}



// Function: FUN_100091c0 at 100091c0

undefined4 * __fastcall FUN_100091c0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100091e0 at 100091e0

void __fastcall FUN_100091e0(int *param_1)

{
  if ((int *)*param_1 != param_1 + 1) {
    FUN_100099c0(param_1);
  }
  return;
}



// Function: FUN_10009210 at 10009210

undefined4 __fastcall FUN_10009210(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10009230 at 10009230

void __thiscall FUN_10009230(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_10009db0(param_1,1);
  FUN_10009980(this,uVar1);
  return;
}



// Function: FUN_10009260 at 10009260

undefined4 * __fastcall FUN_10009260(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d7d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100099f0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100092c0 at 100092c0

void __fastcall FUN_100092c0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100092f0 at 100092f0

undefined4 __fastcall FUN_100092f0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10009310 at 10009310

undefined4 __fastcall FUN_10009310(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10009330 at 10009330

undefined4 * __fastcall FUN_10009330(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10009a10(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009390 at 10009390

void __fastcall FUN_10009390(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_100093c0 at 100093c0

undefined4 __fastcall FUN_100093c0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100093e0 at 100093e0

undefined4 __fastcall FUN_100093e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10009400 at 10009400

undefined4 __fastcall FUN_10009400(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10009420 at 10009420

undefined4 * __fastcall FUN_10009420(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d838;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10009a30(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009480 at 10009480

void * __thiscall FUN_10009480(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d868;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10009a50(this,*param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100094e0 at 100094e0

void __fastcall FUN_100094e0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10009510 at 10009510

undefined4 __fastcall FUN_10009510(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10009530 at 10009530

undefined4 __fastcall FUN_10009530(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10009550 at 10009550

undefined4 __fastcall FUN_10009550(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



// Function: FUN_10009580 at 10009580

void __fastcall FUN_10009580(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d8a3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_100096a0((LPCRITICAL_SECTION)(param_1 + 4));
  local_8 = 0xffffffff;
  FUN_10006d90();
  ExceptionList = local_10;
  return;
}



// Function: FUN_100095f0 at 100095f0

undefined4 * __fastcall FUN_100095f0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d8c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10009a90(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009650 at 10009650

void __fastcall FUN_10009650(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_10009680 at 10009680

undefined4 __fastcall FUN_10009680(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100096a0 at 100096a0

void __fastcall FUN_100096a0(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d8f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100023c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009700 at 10009700

int __thiscall FUN_10009700(void *this,undefined4 *param_1)

{
  bool bVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (*(int *)((int)this + 8) <= local_c) {
      return -1;
    }
                    /* WARNING: Load size is inaccurate */
    bVar1 = FUN_10009760(*(LPCWSTR *)(*this + local_c * 4),(LPCWSTR)*param_1);
    if (bVar1) break;
    local_c = local_c + 1;
  }
  return local_c;
}



// Function: FUN_10009760 at 10009760

bool __cdecl FUN_10009760(LPCWSTR param_1,LPCWSTR param_2)

{
  int iVar1;
  
  iVar1 = lstrcmpiW(param_1,param_2);
  return iVar1 == 0;
}



// Function: FUN_10009790 at 10009790

void __thiscall FUN_10009790(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d953;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  pvVar1 = (void *)FUN_10009e40(4,*this + param_1 * 4);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_10009b90(pvVar1,param_2);
  }
  local_8 = 0xffffffff;
  pvVar1 = (void *)FUN_10009e40(4,*(int *)((int)this + 4) + param_1 * 4);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_10009b90(pvVar1,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009870 at 10009870

void __fastcall FUN_10009870(undefined4 *param_1)

{
  operator_delete__((void *)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_100098a0 at 100098a0

undefined4 __thiscall FUN_100098a0(void *this,uint param_1)

{
  if (param_1 < 0x401) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10009ab0(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100098e0 at 100098e0

void __fastcall FUN_100098e0(undefined4 *param_1)

{
  FUN_100080f0((void *)*param_1);
  return;
}



// Function: FUN_10009910 at 10009910

undefined4 __thiscall FUN_10009910(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10009b10(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10009950 at 10009950

void __fastcall FUN_10009950(undefined4 *param_1)

{
  FUN_100080f0((void *)*param_1);
  return;
}



// Function: FUN_10009980 at 10009980

undefined4 __thiscall FUN_10009980(void *this,uint param_1)

{
  if (param_1 < 0x101) {
    *(int *)this = (int)this + 4;
  }
  else {
    FUN_10009b50(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_100099c0 at 100099c0

void __fastcall FUN_100099c0(undefined4 *param_1)

{
  FUN_100080f0((void *)*param_1);
  return;
}



// Function: FUN_100099f0 at 100099f0

undefined4 * __fastcall FUN_100099f0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10009a10 at 10009a10

undefined4 * __fastcall FUN_10009a10(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10009a30 at 10009a30

undefined4 * __fastcall FUN_10009a30(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10009a50 at 10009a50

int * __thiscall FUN_10009a50(void *this,int param_1)

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



// Function: FUN_10009a90 at 10009a90

undefined4 * __fastcall FUN_10009a90(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10009ab0 at 10009ab0

void __thiscall FUN_10009ab0(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009af0(param_1);
  if (iVar1 == 0) {
    FUN_10003210(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: FUN_10009af0 at 10009af0

void __cdecl FUN_10009af0(size_t param_1)

{
  malloc(param_1);
  return;
}



// Function: FUN_10009b10 at 10009b10

void __thiscall FUN_10009b10(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009af0(param_1);
  if (iVar1 == 0) {
    FUN_10003210(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: FUN_10009b50 at 10009b50

void __thiscall FUN_10009b50(void *this,size_t param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009af0(param_1);
  if (iVar1 == 0) {
    FUN_10003210(0x8007000e);
  }
  *(int *)this = iVar1;
  return;
}



// Function: FUN_10009b90 at 10009b90

undefined4 * __thiscall FUN_10009b90(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10009bc0 at 10009bc0

undefined4 * __thiscall FUN_10009bc0(void *this,undefined4 param_1,char param_2)

{
  int iVar1;
  
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 4) = 0;
  if (param_2 != '\0') {
    iVar1 = FUN_10009c40((undefined4 *)this);
    if (iVar1 < 0) {
      FUN_10003210(iVar1);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10009c10 at 10009c10

void __fastcall FUN_10009c10(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_1000a100(param_1);
  }
  return;
}



// Function: FUN_10009c40 at 10009c40

int __fastcall FUN_10009c40(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10009c80((LPCRITICAL_SECTION)*param_1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 1) = 1;
    iVar1 = 0;
  }
  return iVar1;
}



// Function: FUN_10009c80 at 10009c80

undefined4 __fastcall FUN_10009c80(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  return 0;
}



// Function: FUN_10009ca0 at 10009ca0

void FUN_10009ca0(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_1003704c,param_2);
  return;
}



// Function: FUN_10009cd0 at 10009cd0

void __thiscall FUN_10009cd0(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar2 = (undefined4 *)FUN_1000a0e0(param_1);
  bVar1 = FUN_10009e70(this,puVar2);
  if (bVar1) {
    FUN_10009d90((undefined4 *)this);
  }
  else {
    puVar3 = &DAT_1003705c;
    puVar2 = (undefined4 *)FUN_1000a0e0(param_1);
    FUN_10009d20((int *)this,puVar2,puVar3);
  }
  return;
}



// Function: FUN_10009d20 at 10009d20

int FUN_10009d20(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    piVar1 = (int *)*param_1;
    *param_1 = 0;
    if (param_2 != (undefined4 *)0x0) {
      (**(code **)*param_2)(param_2,param_3,param_1);
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    iVar2 = *param_1;
  }
  return iVar2;
}



// Function: FUN_10009d90 at 10009d90

undefined4 __fastcall FUN_10009d90(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10009db0 at 10009db0

undefined4 __cdecl FUN_10009db0(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 local_8;
  
  uVar1 = FUN_10009df0(&local_8,param_1,param_2);
  if ((int)uVar1 < 0) {
    FUN_10003210(uVar1);
  }
  return local_8;
}



// Function: FUN_10009df0 at 10009df0

uint __cdecl FUN_10009df0(undefined4 *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = (int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (local_8 == 0) {
    local_c = (undefined4)((ulonglong)param_2 * (ulonglong)param_3);
    *param_1 = local_c;
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_100024c0(0x216);
  }
  return uVar1;
}



// Function: FUN_10009e40 at 10009e40

undefined4 __cdecl FUN_10009e40(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10009e60 at 10009e60

void FUN_10009e60(void)

{
  return;
}



// Function: FUN_10009e70 at 10009e70

bool __thiscall FUN_10009e70(void *this,undefined4 *param_1)

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
  puStack_c = &LAB_1002d980;
  local_10 = ExceptionList;
  uVar2 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
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
      FUN_10009fc0(&local_18);
      local_8 = 0;
      FUN_10009fc0(&local_1c);
      local_8._0_1_ = 1;
      uVar3 = FUN_1000a070(&local_18);
      (*(code *)**(undefined4 **)*local_14)(*local_14,&DAT_10036f3c,uVar3,uVar2);
      uVar3 = FUN_1000a070(&local_1c);
      (**(code **)*param_1)(param_1,&DAT_10036f3c,uVar3);
      iVar4 = FUN_1000a050(&local_1c);
      bVar1 = FUN_1000a090(&local_18,iVar4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10009f60(&local_1c);
      local_8 = 0xffffffff;
      FUN_10009f60(&local_18);
    }
  }
  ExceptionList = local_10;
  return bVar1;
}



// Function: FUN_10009f60 at 10009f60

void __fastcall FUN_10009f60(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d9a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000a020(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009fc0 at 10009fc0

undefined4 * __fastcall FUN_10009fc0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d9d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a0c0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000a020 at 1000a020

void __fastcall FUN_1000a020(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000a050 at 1000a050

undefined4 __fastcall FUN_1000a050(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000a070 at 1000a070

undefined4 __fastcall FUN_1000a070(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000a090 at 1000a090

bool __thiscall FUN_1000a090(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == param_1;
}



// Function: FUN_1000a0c0 at 1000a0c0

undefined4 * __fastcall FUN_1000a0c0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000a0e0 at 1000a0e0

undefined4 __fastcall FUN_1000a0e0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000a100 at 1000a100

void __fastcall FUN_1000a100(undefined4 *param_1)

{
  FUN_1000a130((LPCRITICAL_SECTION)*param_1);
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



// Function: FUN_1000a130 at 1000a130

undefined4 __fastcall FUN_1000a130(LPCRITICAL_SECTION param_1)

{
  LeaveCriticalSection(param_1);
  return 0;
}



// Function: FUN_1000a150 at 1000a150

void * __thiscall FUN_1000a150(void *this,wchar_t *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002da08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a6a0(&stack0xffffff94);
  FUN_1000a650((int)this);
  local_8 = 0;
  FUN_1000a550(this,'\0',0);
  FUN_1000a1d0(this,param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000a1d0 at 1000a1d0

void __thiscall FUN_1000a1d0(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1000a200(param_1);
  FUN_1000a220(this,(undefined4 *)param_1,uVar1);
  return;
}



// Function: FUN_1000a200 at 1000a200

void __cdecl FUN_1000a200(wchar_t *param_1)

{
  wcslen(param_1);
  return;
}



// Function: FUN_1000a220 at 1000a220

undefined4 * __thiscall FUN_1000a220(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_1000a780(this,param_1);
  if ((uVar2 & 0xff) == 0) {
    bVar1 = FUN_1000a6e0(this,param_2,'\0');
    if (bVar1) {
      uVar2 = param_2;
      puVar3 = FUN_1000a5d0((undefined4 *)this);
      FUN_1000a2b0(puVar3,param_1,uVar2);
      FUN_1000a4f0(this,param_2);
    }
  }
  else {
    puVar3 = FUN_1000a5d0((undefined4 *)this);
    this = FUN_1000a310(this,(undefined4 *)this,(int)param_1 - (int)puVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a2b0 at 1000a2b0

void __cdecl FUN_1000a2b0(void *param_1,void *param_2,int param_3)

{
  FUN_1000a2e0(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000a2e0 at 1000a2e0

void __cdecl FUN_1000a2e0(void *param_1,void *param_2,int param_3)

{
  memcpy(param_1,param_2,param_3 << 1);
  return;
}



// Function: FUN_1000a310 at 1000a310

undefined4 * __thiscall FUN_1000a310(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 local_c;
  
  uVar2 = FUN_1000a4d0((int)param_1);
  if (uVar2 < param_2) {
    FUN_1000a630();
  }
  iVar3 = FUN_1000a4d0((int)param_1);
  local_c = iVar3 - param_2;
  if (param_3 < local_c) {
    local_c = param_3;
  }
  if ((undefined4 *)this == param_1) {
    FUN_1000a3d0(this,param_2 + local_c,0xffffffff);
    FUN_1000a3d0(this,0,param_2);
  }
  else {
    bVar1 = FUN_1000a6e0(this,local_c,'\0');
    if (bVar1) {
      uVar2 = local_c;
      puVar4 = FUN_1000a600(param_1);
      pvVar5 = (void *)((int)puVar4 + param_2 * 2);
      puVar4 = FUN_1000a5d0((undefined4 *)this);
      FUN_1000a2b0(puVar4,pvVar5,uVar2);
      FUN_1000a4f0(this,local_c);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a3d0 at 1000a3d0

undefined4 * __thiscall FUN_1000a3d0(void *this,uint param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000a630();
  }
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  if (param_2 != 0) {
    iVar2 = (*(int *)((int)this + 0x10) - param_1) - param_2;
    puVar1 = FUN_1000a5d0((undefined4 *)this);
    pvVar3 = (void *)((int)puVar1 + param_2 * 2 + param_1 * 2);
    puVar1 = FUN_1000a5d0((undefined4 *)this);
    FUN_1000a470((void *)((int)puVar1 + param_1 * 2),pvVar3,iVar2);
    FUN_1000a4f0(this,*(int *)((int)this + 0x10) - param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a470 at 1000a470

void __cdecl FUN_1000a470(void *param_1,void *param_2,int param_3)

{
  FUN_1000a4a0(param_1,param_2,param_3);
  return;
}



// Function: FUN_1000a4a0 at 1000a4a0

void __cdecl FUN_1000a4a0(void *param_1,void *param_2,int param_3)

{
  memmove(param_1,param_2,param_3 << 1);
  return;
}



// Function: FUN_1000a4d0 at 1000a4d0

undefined4 __fastcall FUN_1000a4d0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1000a4f0 at 1000a4f0

void __thiscall FUN_1000a4f0(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  undefined2 local_4a [33];
  void *local_8;
  
  local_4a[0] = 0;
  *(int *)((int)this + 0x10) = param_1;
  puVar2 = local_4a;
  local_8 = this;
  puVar1 = FUN_1000a5d0((undefined4 *)this);
  FUN_1000a530((undefined2 *)((int)puVar1 + param_1 * 2),puVar2);
  return;
}



// Function: FUN_1000a530 at 1000a530

void __cdecl FUN_1000a530(undefined2 *param_1,undefined2 *param_2)

{
  *param_1 = *param_2;
  return;
}



// Function: FUN_1000a550 at 1000a550

void __thiscall FUN_1000a550(void *this,char param_1,int param_2)

{
  void *pvVar1;
  
  if ((param_1 != '\0') && (7 < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    if (param_2 != 0) {
      FUN_1000a2b0(this,pvVar1,param_2);
    }
    FUN_1000a7f0(pvVar1);
  }
  *(undefined4 *)((int)this + 0x14) = 7;
  FUN_1000a4f0(this,param_2);
  return;
}



// Function: FUN_1000a5d0 at 1000a5d0

undefined4 * __fastcall FUN_1000a5d0(undefined4 *param_1)

{
  undefined4 *local_4c;
  
  local_4c = param_1;
  if (7 < (uint)param_1[5]) {
    local_4c = (undefined4 *)*param_1;
  }
  return local_4c;
}



// Function: FUN_1000a600 at 1000a600

undefined4 * __fastcall FUN_1000a600(undefined4 *param_1)

{
  undefined4 *local_4c;
  
  local_4c = param_1;
  if (7 < (uint)param_1[5]) {
    local_4c = (undefined4 *)*param_1;
  }
  return local_4c;
}



// Function: FUN_1000a630 at 1000a630

void FUN_1000a630(void)

{
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: FUN_1000a650 at 1000a650

int __fastcall FUN_1000a650(int param_1)

{
  FUN_1000a6c0(param_1 + 0x18);
  return param_1;
}



// Function: FUN_1000a680 at 1000a680

void FUN_1000a680(void)

{
  return;
}



// Function: FUN_1000a6a0 at 1000a6a0

undefined4 __fastcall FUN_1000a6a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000a6c0 at 1000a6c0

undefined4 __fastcall FUN_1000a6c0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000a6e0 at 1000a6e0

bool __thiscall FUN_1000a6e0(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 local_4c;
  
  uVar1 = FUN_1000a820();
  if (uVar1 < param_1) {
    FUN_1000a7d0();
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_1000a860(this,param_1);
  }
  else if ((param_2 == '\0') || (7 < param_1)) {
    if (param_1 == 0) {
      FUN_1000a4f0(this,0);
    }
  }
  else {
    if (param_1 < *(uint *)((int)this + 0x10)) {
      local_4c = param_1;
    }
    else {
      local_4c = *(uint *)((int)this + 0x10);
    }
    FUN_1000a550(this,'\x01',local_4c);
  }
  return param_1 != 0;
}



// Function: FUN_1000a780 at 1000a780

uint __thiscall FUN_1000a780(void *this,undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (in_EAX = FUN_1000a5d0((undefined4 *)this), in_EAX <= param_1)) {
    puVar1 = FUN_1000a5d0((undefined4 *)this);
    in_EAX = (undefined4 *)((int)puVar1 + *(int *)((int)this + 0x10) * 2);
    if (param_1 < in_EAX) {
      return CONCAT31((int3)((uint)in_EAX >> 8),1);
    }
  }
  return (uint)in_EAX & 0xffffff00;
}



// Function: FUN_1000a7d0 at 1000a7d0

void FUN_1000a7d0(void)

{
  std::_Xlength_error("string too long");
  return;
}



// Function: FUN_1000a7f0 at 1000a7f0

void FUN_1000a7f0(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1000a820 at 1000a820

int FUN_1000a820(void)

{
  uint uVar1;
  undefined4 local_50;
  
  uVar1 = FUN_1000aa10();
  if (uVar1 < 2) {
    local_50 = 1;
  }
  else {
    local_50 = uVar1 - 1;
  }
  return local_50;
}



// Function: FUN_1000a860 at 1000a860

void __thiscall FUN_1000a860(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002da30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1 | 7;
  uVar1 = FUN_1000a820();
  if (uVar1 < local_1c) {
    local_1c = param_1;
  }
  else if (local_1c / 3 < *(uint *)((int)this + 0x14) >> 1) {
    iVar2 = FUN_1000a820();
    if (iVar2 - (*(uint *)((int)this + 0x14) >> 1) < *(uint *)((int)this + 0x14)) {
      local_1c = FUN_1000a820();
    }
    else {
      local_1c = (*(uint *)((int)this + 0x14) >> 1) + *(int *)((int)this + 0x14);
    }
  }
  local_8 = 0;
  FUN_1000a9e0(local_1c + 1);
  FUN_1000a977();
  return;
}



// Function: Catch@1000a91d at 1000a91d

void Catch_1000a91d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = FUN_1000a9e0(*(int *)(unaff_EBP + -0x18) + 1);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar1;
  FUN_1000a963();
  return;
}



// Function: Catch@1000a941 at 1000a941

void Catch_1000a941(void)

{
  int unaff_EBP;
  
  FUN_1000a550(*(void **)(unaff_EBP + -0x14),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000a963 at 1000a963

undefined4 FUN_1000a963(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1000a97e;
}



// Function: FUN_1000a977 at 1000a977

void FUN_1000a977(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  int iVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    iVar2 = *(int *)(unaff_EBP + 0xc);
    puVar1 = FUN_1000a5d0(*(undefined4 **)(unaff_EBP + -0x14));
    FUN_1000a2b0(*(void **)(unaff_EBP + -0x1c),puVar1,iVar2);
  }
  FUN_1000a550(*(void **)(unaff_EBP + -0x14),'\x01',0);
  **(undefined4 **)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  FUN_1000a4f0(*(void **)(unaff_EBP + -0x14),*(int *)(unaff_EBP + 0xc));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000a9e0 at 1000a9e0

void FUN_1000a9e0(uint param_1)

{
  FUN_1000aa50(param_1);
  return;
}



// Function: FUN_1000aa10 at 1000aa10

/* WARNING: Removing unreachable block (ram,0x1000aa31) */

undefined4 FUN_1000aa10(void)

{
  return 0x7fffffff;
}



// Function: FUN_1000aa50 at 1000aa50

void * __cdecl FUN_1000aa50(uint param_1)

{
  exception local_54 [76];
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x7fffffff < param_1 || (local_8 = operator_new(param_1 << 1), local_8 == (void *)0x0)))) {
    FUN_1000aac0(local_54);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1003d210);
  }
  return local_8;
}



// Function: FUN_1000aac0 at 1000aac0

exception * __fastcall FUN_1000aac0(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002da59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception(param_1,(char **)&stack0x00000004);
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ab30 at 1000ab30

void __fastcall FUN_1000ab30(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002da89;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ab90 at 1000ab90

exception * __thiscall FUN_1000ab90(void *this,uint param_1)

{
  FUN_1000ab30((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (exception *)this;
}



// Function: FUN_1000abd0 at 1000abd0

exception * __thiscall FUN_1000abd0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002dab9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_1000ac40 at 1000ac40

int * __thiscall FUN_1000ac40(void *this,int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    *(undefined4 *)this = 0;
  }
  else {
    uVar2 = Ordinal_2(param_1);
    *(undefined4 *)this = uVar2;
    bVar1 = FUN_10008590((int *)this);
    if (bVar1) {
      FUN_10003210(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_1000aca0 at 1000aca0

void __fastcall FUN_1000aca0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002dba8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000a550(param_1,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1000a680();
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ad00 at 1000ad00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_1000ad00(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002dbd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000b650((int)param_1);
  *param_1 = ATL::CComModule::vftable;
  _DAT_10043bcc = param_1;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ad70 at 1000ad70

void __fastcall FUN_1000ad70(int param_1)

{
  FUN_10002500((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000ad90 at 1000ad90

void __fastcall FUN_1000ad90(int param_1)

{
  FUN_10002520((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_1000adb0 at 1000adb0

int __thiscall FUN_1000adb0(void *this,undefined4 *param_1)

{
  int local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    local_c = -0x7fffbffd;
  }
  else {
    local_c = 0;
    if (*(int *)((int)this + 0x28) == 0) {
      local_c = CoCreateInstance((IID *)&DAT_1003a358,(LPUNKNOWN)0x0,1,(IID *)&DAT_100373b0,
                                 (LPVOID *)((int)this + 0x28));
    }
    if (-1 < local_c) {
      *param_1 = *(undefined4 *)((int)this + 0x28);
      (**(code **)(**(int **)((int)this + 0x28) + 4))(*(undefined4 *)((int)this + 0x28));
    }
  }
  return local_c;
}



// Function: FUN_1000ae30 at 1000ae30

undefined4 FUN_1000ae30(void)

{
  return 0x80004005;
}



// Function: FUN_1000ae50 at 1000ae50

undefined4 FUN_1000ae50(void)

{
  return 0x80004005;
}



// Function: FUN_1000ae70 at 1000ae70

void FUN_1000ae70(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  FUN_1000b060(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000aea0 at 1000aea0

undefined4 * __thiscall FUN_1000aea0(void *this,uint param_1)

{
  FUN_1000aee0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000aee0 at 1000aee0

void __fastcall FUN_1000aee0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002dc08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = ATL::CComModule::vftable;
  local_8 = 0xffffffff;
  FUN_1000af40((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000af40 at 1000af40

void __fastcall FUN_1000af40(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002dc38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000afa0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000afa0 at 1000afa0

void __fastcall FUN_1000afa0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002dc6b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10006120(param_1);
  local_8 = 0xffffffff;
  FUN_1000b000();
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b000 at 1000b000

void FUN_1000b000(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002dc9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100023a0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000b060 at 1000b060

void FUN_1000b060(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  bool bVar1;
  uint uVar2;
  HMODULE pHVar3;
  int iVar4;
  int local_af0;
  WCHAR local_a80;
  undefined2 local_a7e [523];
  int local_668;
  WCHAR local_664 [520];
  short *local_254;
  DWORD local_250;
  HMODULE local_24c;
  WCHAR local_248 [260];
  int local_40 [3];
  undefined4 local_34;
  int local_2c;
  undefined4 local_28 [5];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002dcd0;
  local_10 = ExceptionList;
  uVar2 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_10005e90(local_28);
  local_8 = 0;
  local_2c = FUN_10002d60();
  if (local_2c < 0) {
    local_8 = 0xffffffff;
    FUN_10002bb0(local_28);
  }
  else {
    if (param_4 != (int *)0x0) {
      for (; *param_4 != 0; param_4 = param_4 + 2) {
        FUN_10002de0(local_28,*param_4,param_4[1]);
      }
    }
    local_2c = (**(code **)(*param_1 + 0x14))(local_28,uVar2);
    if (local_2c < 0) {
      local_8 = 0xffffffff;
      FUN_10002bb0(local_28);
    }
    else {
      local_34 = FUN_10002a10();
      FUN_10008090(local_40);
      local_8._0_1_ = 1;
      local_24c = (HMODULE)FUN_10002ab0(0x100458a4);
      local_250 = GetModuleFileNameW(local_24c,local_248,0x104);
      if (local_250 == 0) {
        FUN_10002ad0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100080b0(local_40);
        local_8 = 0xffffffff;
        FUN_10002bb0(local_28);
      }
      else if (local_250 == 0x104) {
        FUN_100024c0(0x7a);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_100080b0(local_40);
        local_8 = 0xffffffff;
        FUN_10002bb0(local_28);
      }
      else {
        local_254 = (short *)0x0;
        local_254 = (short *)FUN_10002a90(local_248);
        FUN_10002b00(local_664,0x208,local_254);
        if ((local_24c == (HMODULE)0x0) ||
           (pHVar3 = GetModuleHandleW((LPCWSTR)0x0), local_24c == pHVar3)) {
          local_a80 = L'\"';
          bVar1 = FUN_10002a50(local_a7e,0x20b,local_664);
          if (!bVar1) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100080b0(local_40);
            local_8 = 0xffffffff;
            FUN_10002bb0(local_28);
            goto LAB_1000b465;
          }
          iVar4 = FUN_10002a30(&local_a80);
          local_a7e[iVar4 + -1] = 0x22;
          local_a7e[iVar4] = 0;
          local_668 = FUN_10002de0(local_28,0x10036c8c,(int)&local_a80);
        }
        else {
          local_668 = FUN_10002de0(local_28,0x10036c8c,(int)local_664);
        }
        if (local_668 < 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_100080b0(local_40);
          local_8 = 0xffffffff;
          FUN_10002bb0(local_28);
        }
        else {
          local_668 = FUN_10002de0(local_28,0x10036c74,(int)local_664);
          if (local_668 < 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100080b0(local_40);
            local_8 = 0xffffffff;
            FUN_10002bb0(local_28);
          }
          else {
            iVar4 = FUN_1000b490(param_2);
            if (param_3 == 0) {
              local_af0 = FUN_1000b580(local_28,local_254,iVar4,0x10036c60);
            }
            else {
              local_af0 = FUN_1000b4b0(local_28,local_254,iVar4,0x10036c60);
            }
            local_2c = local_af0;
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_100080b0(local_40);
            local_8 = 0xffffffff;
            FUN_10002bb0(local_28);
          }
        }
      }
    }
  }
LAB_1000b465:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b490 at 1000b490

undefined4 __cdecl FUN_1000b490(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000b4b0 at 1000b4b0

undefined4 FUN_1000b4b0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  LPCWSTR pWVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  int local_24 [3];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002dd08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = FUN_10002a10();
  FUN_10008090(local_24);
  local_8 = 0;
  if ((param_3 == 0) || (param_4 == 0)) {
    local_8 = 0xffffffff;
    FUN_100080b0(local_24);
    uVar3 = 0x80070057;
  }
  else {
    pWVar1 = (LPCWSTR)FUN_10002eb0(param_3);
    pWVar2 = (LPCWSTR)FUN_10002eb0(param_4);
    uVar3 = FUN_10003310(param_2,pWVar1,pWVar2);
    local_8 = 0xffffffff;
    FUN_100080b0(local_24);
  }
  ExceptionList = local_10;
  return uVar3;
}



// Function: FUN_1000b580 at 1000b580

undefined4 FUN_1000b580(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  LPCWSTR pWVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  int local_24 [3];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002dd38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = FUN_10002a10();
  FUN_10008090(local_24);
  local_8 = 0;
  if ((param_3 == 0) || (param_4 == 0)) {
    local_8 = 0xffffffff;
    FUN_100080b0(local_24);
    uVar3 = 0x80070057;
  }
  else {
    pWVar1 = (LPCWSTR)FUN_10002eb0(param_3);
    pWVar2 = (LPCWSTR)FUN_10002eb0(param_4);
    uVar3 = FUN_10003310(param_2,pWVar1,pWVar2);
    local_8 = 0xffffffff;
    FUN_100080b0(local_24);
  }
  ExceptionList = local_10;
  return uVar3;
}



// Function: FUN_1000b650 at 1000b650

int __fastcall FUN_1000b650(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002dd68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000b6b0(param_1);
  local_8 = 0;
  FUN_1000b7f0();
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000b6b0 at 1000b6b0

int __fastcall FUN_1000b6b0(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002dd9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000b760(param_1 + 4);
  local_8 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_10043bb8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  uVar1 = FUN_10002480((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)uVar1 < 0) {
    DAT_10043ba8 = 1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x24;
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000b760 at 1000b760

int __fastcall FUN_1000b760(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ddcb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002370((void *)(param_1 + 0xc));
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000b7c0 at 1000b7c0

void FUN_1000b7c0(int *param_1)

{
  undefined2 *puVar1;
  
  puVar1 = FUN_1000b800();
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",puVar1);
  return;
}



// Function: FUN_1000b7f0 at 1000b7f0

void FUN_1000b7f0(void)

{
  return;
}



// Function: FUN_1000b800 at 1000b800

undefined2 * FUN_1000b800(void)

{
  return &DAT_100373cc;
}



// Function: FUN_1000b820 at 1000b820

void FUN_1000b820(void)

{
  void *pvVar1;
  undefined1 local_184 [8];
  undefined1 local_17c [8];
  undefined1 local_174 [8];
  undefined1 local_16c [8];
  undefined1 local_164 [8];
  undefined1 local_15c [8];
  undefined1 local_154 [8];
  undefined1 local_14c [8];
  undefined1 local_144 [8];
  undefined1 local_13c [8];
  undefined1 local_134 [8];
  undefined1 local_12c [8];
  undefined1 local_124 [8];
  undefined1 local_11c [8];
  undefined1 local_114 [8];
  undefined1 local_10c [8];
  undefined1 local_104 [8];
  undefined1 local_fc [8];
  undefined1 local_f4 [8];
  undefined1 local_ec [8];
  undefined1 local_e4 [8];
  undefined1 local_dc [8];
  undefined1 local_d4 [8];
  undefined1 local_cc [8];
  undefined1 local_c4 [8];
  undefined1 local_bc [8];
  undefined1 local_b4 [8];
  undefined1 local_ac [8];
  undefined1 local_a4 [8];
  undefined1 local_9c [8];
  undefined1 local_94 [8];
  undefined1 local_8c [8];
  undefined1 local_84 [8];
  undefined1 local_7c [8];
  undefined1 local_74 [8];
  undefined1 local_6c [8];
  undefined1 local_64 [8];
  undefined1 local_5c [8];
  undefined1 local_54 [8];
  undefined1 local_4c [72];
  
  pvVar1 = FUN_10010c80(local_184,&DAT_10037614,L"English");
  FUN_10010cb0(&DAT_10044180,local_17c,pvVar1);
  pvVar1 = FUN_10010c80(local_174,&DAT_100375fc,L"Spanish");
  FUN_10010cb0(&DAT_10044180,local_16c,pvVar1);
  pvVar1 = FUN_10010cf0(local_164,&DAT_100375dc,L"Portuguese");
  FUN_10010cb0(&DAT_10044180,local_15c,pvVar1);
  pvVar1 = FUN_10010c80(local_154,&DAT_100375c4,L"Turkish");
  FUN_10010cb0(&DAT_10044180,local_14c,pvVar1);
  pvVar1 = FUN_10010c80(local_144,&DAT_100375ac,L"Chinese");
  FUN_10010cb0(&DAT_10044180,local_13c,pvVar1);
  pvVar1 = FUN_10010d20(local_134,&DAT_10037590,L"Japanese");
  FUN_10010cb0(&DAT_10044180,local_12c,pvVar1);
  pvVar1 = FUN_10010d50(local_124,&DAT_10037578,L"French");
  FUN_10010cb0(&DAT_10044180,local_11c,pvVar1);
  pvVar1 = FUN_10010d50(local_114,&DAT_10037560,L"German");
  FUN_10010cb0(&DAT_10044180,local_10c,pvVar1);
  pvVar1 = FUN_10010c80(local_104,&DAT_10037548,L"Italian");
  FUN_10010cb0(&DAT_10044180,local_fc,pvVar1);
  pvVar1 = FUN_10010d50(local_f4,&DAT_10037530,L"Korean");
  FUN_10010cb0(&DAT_10044180,local_ec,pvVar1);
  pvVar1 = FUN_10010c80(local_e4,&DAT_10037518,L"Russian");
  FUN_10010cb0(&DAT_10044180,local_dc,pvVar1);
  pvVar1 = FUN_10010d50(local_d4,&DAT_10037500,L"Danish");
  FUN_10010cb0(&DAT_10044180,local_cc,pvVar1);
  pvVar1 = FUN_10010d80(local_c4,&DAT_100374ec,L"Dutch");
  FUN_10010cb0(&DAT_10044180,local_bc,pvVar1);
  pvVar1 = FUN_10010c80(local_b4,&DAT_100374d4,L"Finnish");
  FUN_10010cb0(&DAT_10044180,local_ac,pvVar1);
  pvVar1 = FUN_10010db0(local_a4,&DAT_100374b8,L"Norwegian");
  FUN_10010cb0(&DAT_10044180,local_9c,pvVar1);
  pvVar1 = FUN_10010c80(local_94,&DAT_100374a0,L"Swedish");
  FUN_10010cb0(&DAT_10044180,local_8c,pvVar1);
  pvVar1 = FUN_10010cf0(local_84,&DAT_10037480,L"Indonesian");
  FUN_10010cb0(&DAT_10044180,local_7c,pvVar1);
  pvVar1 = FUN_10010d50(local_74,&DAT_10037468,L"Polish");
  FUN_10010cb0(&DAT_10044180,local_6c,pvVar1);
  pvVar1 = FUN_10010db0(local_64,&DAT_1003744c,L"Hungarian");
  FUN_10010cb0(&DAT_10044180,local_5c,pvVar1);
  pvVar1 = FUN_10010d20(local_54,&DAT_10037430,L"Romanian");
  FUN_10010cb0(&DAT_10044180,local_4c,pvVar1);
  return;
}



// Function: FUN_1000bb80 at 1000bb80

int __fastcall FUN_1000bb80(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002de11;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100020b0((undefined4 *)(param_1 + 8));
  local_8 = 0;
  FUN_1000bc20(param_1);
  FUN_1000bc40(param_1 + 4);
  FUN_10009fc0((undefined4 *)(param_1 + 0xc));
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_10017a50((undefined4 *)(param_1 + 0x18));
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000b820();
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000bc20 at 1000bc20

undefined4 __fastcall FUN_1000bc20(undefined4 param_1)

{
  FUN_1000bc60(param_1);
  return param_1;
}



// Function: FUN_1000bc40 at 1000bc40

undefined4 __fastcall FUN_1000bc40(undefined4 param_1)

{
  FUN_100025e0(param_1);
  return param_1;
}



// Function: FUN_1000bc60 at 1000bc60

undefined4 __fastcall FUN_1000bc60(undefined4 param_1)

{
  FUN_1000bc80(param_1);
  return param_1;
}



// Function: FUN_1000bc80 at 1000bc80

undefined4 __fastcall FUN_1000bc80(undefined4 param_1)

{
  FUN_100025e0(param_1);
  return param_1;
}



// Function: FUN_1000bca0 at 1000bca0

void __fastcall FUN_1000bca0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002de51;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_10017ba0((undefined4 *)(param_1 + 0x18));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10009f60((int *)(param_1 + 0xc));
  local_8 = 0xffffffff;
  FUN_100070a0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000bd20 at 1000bd20

undefined4 FUN_1000bd20(void)

{
  return 0x80004001;
}



// Function: FUN_1000bd40 at 1000bd40

void FUN_1000bd40(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uStack_cc;
  undefined1 local_a8 [28];
  undefined1 local_8c [92];
  int local_30;
  int local_2c;
  undefined4 local_28 [4];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002de9e;
  local_10 = ExceptionList;
  uStack_cc = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_cc;
  ExceptionList = &local_10;
  local_18 = uStack_cc;
  FUN_10010de0(local_28);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_1000db80(&local_2c);
  local_8._0_1_ = 2;
  uVar1 = FUN_1000dc30(&local_2c,(IID *)&DAT_1003a358,(LPUNKNOWN)0x0,0x17);
  FUN_10010e40(local_28,uVar1);
  FUN_1000dc60(&local_30);
  local_8._0_1_ = 3;
  piVar2 = (int *)FUN_1000dc10(&local_2c);
  uVar1 = FUN_1000dcf0(&local_30);
  uVar1 = (**(code **)(*piVar2 + 0x14))(piVar2,param_3,&DAT_10037f2c,uVar1);
  FUN_10010e40(local_28,uVar1);
  piVar2 = (int *)FUN_1000dd10(&local_30);
  uVar1 = FUN_1000a070(param_1 + 8);
  uVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,uVar1);
  FUN_10010e40(local_28,uVar1);
  *(undefined4 *)(param_1 + 0xc) = param_3;
  puVar3 = (undefined4 *)FUN_1000d480();
  local_8._0_1_ = 4;
  puVar4 = (undefined4 *)FUN_10014f70(local_a8,(undefined4 *)&DAT_10044144);
  local_8._0_1_ = 5;
  FUN_10018110((void *)(param_1 + 0x14),puVar4,puVar3);
  local_8._0_1_ = 4;
  FUN_1000aca0(local_a8);
  local_8._0_1_ = 3;
  FUN_1000aca0(local_8c);
  local_8._0_1_ = 2;
  FUN_1000bfa0(&local_30);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_1000bf40(&local_2c);
  FUN_1000bef1();
  return;
}



// Function: Catch@1000bed7 at 1000bed7

undefined4 Catch_1000bed7(void)

{
  int unaff_EBP;
  
  FUN_10010e40((void *)(unaff_EBP + -0x24),0x80004005);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000bef8;
}



// Function: FUN_1000bef1 at 1000bef1

void FUN_1000bef1(void)

{
  undefined4 uVar1;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0;
  uVar1 = FUN_1000db30(unaff_EBP - 0x24);
  *(undefined4 *)(unaff_EBP - 0xa8) = uVar1;
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_10010e20((undefined4 *)(unaff_EBP - 0x24));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000bf33;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000bf40 at 1000bf40

void __fastcall FUN_1000bf40(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002ded8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000dbe0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000bfa0 at 1000bfa0

void __fastcall FUN_1000bfa0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002df08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000dcc0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c000 at 1000c000

void FUN_1000c000(int param_1)

{
  undefined1 auStack_b0 [16];
  undefined4 uStack_a0;
  undefined4 local_34 [7];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002df40;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  uStack_a0 = 0x1000c042;
  FUN_1000c0b0(local_34,(short *)&stack0x00000008);
  local_8 = 0;
  FUN_100156f0(auStack_b0,local_34);
  local_8 = local_8 & 0xffffff00;
  FUN_10017e20((void *)(param_1 + 0x18));
  local_8 = 0xffffffff;
  FUN_1000aca0(local_34);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c0b0 at 1000c0b0

void FUN_1000c0b0(undefined4 param_1,short *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  uint uStack_220;
  int local_208;
  undefined4 local_204 [15];
  undefined1 local_1c8 [28];
  undefined4 local_1ac;
  int local_a4;
  int local_a0;
  int local_9c;
  char local_95;
  int local_94;
  uint local_90;
  _Container_base0 local_8c [16];
  undefined1 local_7c [28];
  undefined4 local_60;
  undefined4 local_5c [4];
  undefined1 local_4c [16];
  undefined4 local_3c;
  undefined1 local_38 [32];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e06a;
  local_10 = ExceptionList;
  uStack_220 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_220;
  ExceptionList = &local_10;
  local_1ac = 0;
  local_18 = uStack_220;
  FUN_10015780(local_38);
  local_8 = 1;
  FUN_1000e0f0(&local_3c);
  FUN_1000dd30();
  local_8._0_1_ = 2;
  FUN_10010de0(local_5c);
  local_60 = 0;
  local_8._0_1_ = 4;
  if (*param_2 == 8) {
    FUN_10023020(local_7c,*(int *)(param_2 + 4));
    local_8._0_1_ = 5;
    FUN_1000e160((undefined4 *)local_8c);
    local_8 = CONCAT31(local_8._1_3_,6);
    local_90 = 0;
    local_94 = 0;
    local_95 = '\x01';
    local_9c = FUN_1000a4d0((int)local_7c);
    cVar4 = local_95;
    while ((local_95 = cVar4, (int)local_90 < local_9c && (local_95 == '\x01'))) {
      local_94 = FUN_10015980(local_7c,(undefined4 *)&DAT_10043f30,local_90);
      cVar4 = local_94 != -1;
      if ((bool)cVar4) {
        pvVar1 = FUN_10015a00(local_1c8,local_90,local_94 - local_90);
        local_8._0_1_ = 7;
        FUN_1000e1d0(local_8c,pvVar1);
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_1000aca0(local_1c8);
        local_90 = local_94 + 1;
      }
    }
    local_a0 = FUN_1000e350((int *)local_8c);
    for (local_a4 = 0; local_a4 < local_a0; local_a4 = local_a4 + 2) {
      puVar2 = (undefined4 *)FUN_1000e380(local_8c,local_a4);
      local_208 = FUN_10023ad0(puVar2);
      puVar2 = (undefined4 *)FUN_1000e380(local_8c,local_a4 + 1);
      piVar3 = (int *)FUN_100232d0(local_204,puVar2);
      local_8._0_1_ = 8;
      pvVar1 = (void *)FUN_1000dda0(local_4c,&local_208);
      FUN_1000f1b0(pvVar1,piVar3);
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_10007720(local_204);
    }
    local_8._0_1_ = 5;
    FUN_1000e2f0(local_8c);
    local_8._0_1_ = 4;
    FUN_1000aca0(local_7c);
  }
  FUN_10010e40(local_5c,0);
  FUN_1000c349();
  return;
}



// Function: Catch@1000c33c at 1000c33c

undefined4 Catch_1000c33c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 3;
  return 0x1000c350;
}



// Function: FUN_1000c349 at 1000c349

void FUN_1000c349(void)

{
  bool bVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 3;
  *(undefined4 *)(unaff_EBP - 0xa4) = 5;
  FUN_10007e90((undefined4 *)(unaff_EBP - 0xa8));
  *(undefined1 *)(unaff_EBP - 4) = 10;
  FUN_1000c9e0((undefined4 *)(unaff_EBP - 0xa8));
  piVar3 = (int *)(unaff_EBP - 0xa8);
  pvVar2 = (void *)FUN_1000dec0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0xa4));
  FUN_1000f0d0(pvVar2,piVar3);
  *(undefined4 *)(unaff_EBP - 0xa4) = 6;
  FUN_10007e90((undefined4 *)(unaff_EBP - 0xac));
  *(undefined1 *)(unaff_EBP - 4) = 0xb;
  FUN_1000caf0((undefined4 *)(unaff_EBP - 0xac));
  piVar3 = (int *)(unaff_EBP - 0xac);
  pvVar2 = (void *)FUN_1000dec0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0xa4));
  FUN_1000f0d0(pvVar2,piVar3);
  GetSystemTime((LPSYSTEMTIME)(unaff_EBP - 0x120));
  FUN_100156a0((void *)(unaff_EBP - 0x128),(undefined2 *)(unaff_EBP - 0x120));
  FUN_10020370((void *)(unaff_EBP - 0x128),(wchar_t *)(unaff_EBP - 0x110),L"%d-%b-%Y");
  *(undefined4 *)(unaff_EBP - 0xa4) = 1;
  piVar3 = FUN_1000ac40((void *)(unaff_EBP - 0x1fc),unaff_EBP - 0x110);
  *(int **)(unaff_EBP - 0x208) = piVar3;
  *(undefined4 *)(unaff_EBP - 0x20c) = *(undefined4 *)(unaff_EBP - 0x208);
  *(undefined1 *)(unaff_EBP - 4) = 0xc;
  piVar3 = *(int **)(unaff_EBP - 0x20c);
  pvVar2 = (void *)FUN_1000dec0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0xa4));
  FUN_1000f1b0(pvVar2,piVar3);
  *(undefined1 *)(unaff_EBP - 4) = 0xb;
  FUN_10007720((undefined4 *)(unaff_EBP - 0x1fc));
  FUN_10020370((void *)(unaff_EBP - 0x128),(wchar_t *)(unaff_EBP - 0x110),L"%H:%M:%S");
  *(undefined4 *)(unaff_EBP - 0xa4) = 2;
  piVar3 = FUN_1000ac40((void *)(unaff_EBP - 0x1f8),unaff_EBP - 0x110);
  *(int **)(unaff_EBP - 0x208) = piVar3;
  *(undefined4 *)(unaff_EBP - 0x20c) = *(undefined4 *)(unaff_EBP - 0x208);
  *(undefined1 *)(unaff_EBP - 4) = 0xd;
  piVar3 = *(int **)(unaff_EBP - 0x20c);
  pvVar2 = (void *)FUN_1000dec0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0xa4));
  FUN_1000f1b0(pvVar2,piVar3);
  *(undefined1 *)(unaff_EBP - 4) = 0xb;
  FUN_10007720((undefined4 *)(unaff_EBP - 0x1f8));
  *(undefined4 *)(unaff_EBP - 500) = 3;
  puVar4 = FUN_1000e060((void *)(unaff_EBP - 0x48),(undefined4 *)(unaff_EBP - 0x1f0),
                        (int *)(unaff_EBP - 500));
  *(undefined4 *)(unaff_EBP - 0x38) = *puVar4;
  piVar3 = (int *)FUN_1000e030((void *)(unaff_EBP - 0x48),(void *)(unaff_EBP - 0x1ec));
  bVar1 = FUN_1000e130((void *)(unaff_EBP - 0x38),piVar3);
  if (bVar1) {
    iVar5 = FUN_1000e110((int *)(unaff_EBP - 0x38));
    FUN_1000f080((void *)(unaff_EBP - 300),(int *)(iVar5 + 4));
    *(undefined1 *)(unaff_EBP - 4) = 0xe;
    FUN_1000f460((undefined4 *)(unaff_EBP - 300));
    bVar1 = FUN_1000f7e0(0x10037630);
    if (bVar1) {
      FUN_10007e90((undefined4 *)(unaff_EBP - 0x130));
      *(undefined1 *)(unaff_EBP - 4) = 0xf;
      FUN_10007e90((undefined4 *)(unaff_EBP - 0x134));
      *(undefined1 *)(unaff_EBP - 4) = 0x10;
      FUN_10007e90((undefined4 *)(unaff_EBP - 0x138));
      *(undefined1 *)(unaff_EBP - 4) = 0x11;
      FUN_10007e90((undefined4 *)(unaff_EBP - 0x13c));
      *(undefined1 *)(unaff_EBP - 4) = 0x12;
      FUN_1000cc10((undefined4 *)(unaff_EBP - 0x130),(void *)(unaff_EBP - 0x134),
                   (undefined4 *)(unaff_EBP - 0x138),(undefined4 *)(unaff_EBP - 0x13c));
      *(undefined4 *)(unaff_EBP - 0xa4) = 10;
      *(undefined4 *)(unaff_EBP - 0x1e8) = 10;
      piVar3 = (int *)(unaff_EBP - 0x130);
      pvVar2 = (void *)FUN_1000dda0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0x1e8));
      FUN_1000f0d0(pvVar2,piVar3);
      *(undefined4 *)(unaff_EBP - 0xa4) = 0xb;
      *(undefined4 *)(unaff_EBP - 0x1e4) = 0xb;
      piVar3 = (int *)(unaff_EBP - 0x134);
      pvVar2 = (void *)FUN_1000dda0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0x1e4));
      FUN_1000f0d0(pvVar2,piVar3);
      *(undefined4 *)(unaff_EBP - 0xa4) = 0xc;
      *(undefined4 *)(unaff_EBP - 0x1e0) = 0xc;
      piVar3 = (int *)(unaff_EBP - 0x138);
      pvVar2 = (void *)FUN_1000dda0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0x1e0));
      FUN_1000f0d0(pvVar2,piVar3);
      *(undefined4 *)(unaff_EBP - 0xa4) = 0xd;
      *(undefined4 *)(unaff_EBP - 0x1dc) = 0xd;
      piVar3 = (int *)(unaff_EBP - 0x13c);
      pvVar2 = (void *)FUN_1000dda0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0x1dc));
      FUN_1000f0d0(pvVar2,piVar3);
      *(undefined4 *)(unaff_EBP - 0xa4) = 0x10;
      uVar6 = FUN_1000d7f0((void *)(unaff_EBP - 0x1d8));
      *(undefined4 *)(unaff_EBP - 0x208) = uVar6;
      *(undefined4 *)(unaff_EBP - 0x20c) = *(undefined4 *)(unaff_EBP - 0x208);
      *(undefined1 *)(unaff_EBP - 4) = 0x13;
      piVar3 = *(int **)(unaff_EBP - 0x20c);
      pvVar2 = (void *)FUN_1000dec0((void *)(unaff_EBP - 0x48),(int *)(unaff_EBP - 0xa4));
      FUN_1000f1b0(pvVar2,piVar3);
      *(undefined1 *)(unaff_EBP - 4) = 0x12;
      FUN_10007720((undefined4 *)(unaff_EBP - 0x1d8));
      *(undefined1 *)(unaff_EBP - 4) = 0x11;
      FUN_10007720((undefined4 *)(unaff_EBP - 0x13c));
      *(undefined1 *)(unaff_EBP - 4) = 0x10;
      FUN_10007720((undefined4 *)(unaff_EBP - 0x138));
      *(undefined1 *)(unaff_EBP - 4) = 0xf;
      FUN_10007720((undefined4 *)(unaff_EBP - 0x134));
      *(undefined1 *)(unaff_EBP - 4) = 0xe;
      FUN_10007720((undefined4 *)(unaff_EBP - 0x130));
    }
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    FUN_10007720((undefined4 *)(unaff_EBP - 300));
  }
  *(undefined4 *)(unaff_EBP - 0x140) = 0x10;
  *(undefined4 *)(unaff_EBP - 0x144) = 0;
  while (*(int *)(unaff_EBP - 0x144) < *(int *)(unaff_EBP - 0x140)) {
    FUN_1000f080((void *)(unaff_EBP - 0x148),(int *)&DAT_10043f2c);
    *(undefined1 *)(unaff_EBP - 4) = 0x14;
    puVar4 = FUN_1000e060((void *)(unaff_EBP - 0x48),(undefined4 *)(unaff_EBP - 0x1d4),
                          (int *)(&DAT_100373d0 + *(int *)(unaff_EBP - 0x144) * 4));
    *(undefined4 *)(unaff_EBP - 0x38) = *puVar4;
    piVar3 = (int *)FUN_1000e030((void *)(unaff_EBP - 0x48),(void *)(unaff_EBP - 0x1d0));
    bVar1 = FUN_1000e130((void *)(unaff_EBP - 0x38),piVar3);
    if (bVar1) {
      iVar5 = FUN_1000e110((int *)(unaff_EBP - 0x38));
      piVar3 = FUN_1000f080((void *)(unaff_EBP - 0x1cc),(int *)(iVar5 + 4));
      *(int **)(unaff_EBP - 0x208) = piVar3;
      *(undefined4 *)(unaff_EBP - 0x20c) = *(undefined4 *)(unaff_EBP - 0x208);
      *(undefined1 *)(unaff_EBP - 4) = 0x15;
      FUN_1000f310(*(undefined4 **)(unaff_EBP - 0x20c));
      *(undefined1 *)(unaff_EBP - 4) = 0x14;
      FUN_10007720((undefined4 *)(unaff_EBP - 0x1cc));
    }
    else {
      piVar3 = FUN_1000ac40((void *)(unaff_EBP - 0x1c8),0x100373cc);
      *(int **)(unaff_EBP - 0x208) = piVar3;
      *(undefined4 *)(unaff_EBP - 0x20c) = *(undefined4 *)(unaff_EBP - 0x208);
      *(undefined1 *)(unaff_EBP - 4) = 0x16;
      FUN_1000f310(*(undefined4 **)(unaff_EBP - 0x20c));
      *(undefined1 *)(unaff_EBP - 4) = 0x14;
      FUN_10007720((undefined4 *)(unaff_EBP - 0x1c8));
    }
    FUN_1000f310((undefined4 *)&DAT_10043f2c);
    iVar5 = FUN_10007570((undefined4 *)(unaff_EBP - 0x148));
    pvVar2 = FUN_10023020((void *)(unaff_EBP - 0x1a4),iVar5);
    *(void **)(unaff_EBP - 0x208) = pvVar2;
    *(undefined4 *)(unaff_EBP - 0x20c) = *(undefined4 *)(unaff_EBP - 0x208);
    *(undefined1 *)(unaff_EBP - 4) = 0x17;
    FUN_10015910((void *)(unaff_EBP - 0x34),*(undefined4 **)(unaff_EBP - 0x20c));
    *(undefined1 *)(unaff_EBP - 4) = 0x14;
    FUN_1000aca0((void *)(unaff_EBP - 0x1a4));
    if (*(int *)(unaff_EBP - 0x144) != *(int *)(unaff_EBP - 0x140) + -1) {
      FUN_10015910((void *)(unaff_EBP - 0x34),(undefined4 *)&DAT_10043f10);
    }
    *(undefined1 *)(unaff_EBP - 4) = 0xb;
    FUN_10007720((undefined4 *)(unaff_EBP - 0x148));
    *(int *)(unaff_EBP - 0x144) = *(int *)(unaff_EBP - 0x144) + 1;
  }
  FUN_100169a0((void *)(unaff_EBP - 0x34),L"\n");
  FUN_100157f0(*(void **)(unaff_EBP + 8),unaff_EBP - 0x34);
  *(uint *)(unaff_EBP - 0x1a8) = *(uint *)(unaff_EBP - 0x1a8) | 1;
  *(undefined1 *)(unaff_EBP - 4) = 10;
  FUN_10007720((undefined4 *)(unaff_EBP - 0xac));
  *(undefined1 *)(unaff_EBP - 4) = 3;
  FUN_10007720((undefined4 *)(unaff_EBP - 0xa8));
  *(undefined1 *)(unaff_EBP - 4) = 2;
  FUN_10010e20((undefined4 *)(unaff_EBP - 0x58));
  *(undefined1 *)(unaff_EBP - 4) = 1;
  FUN_1000c980((void *)(unaff_EBP - 0x48));
  *(undefined1 *)(unaff_EBP - 4) = 0;
  FUN_1000aca0((void *)(unaff_EBP - 0x34));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000c979;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000c980 at 1000c980

void __fastcall FUN_1000c980(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e0a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000dfd0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c9e0 at 1000c9e0

void FUN_1000c9e0(undefined4 *param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e0d8;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  FUN_1000e3a0(&local_1c,0);
  local_8 = 0;
  local_18 = FUN_1000e450(&local_1c,(IID *)&DAT_10036a6c,(LPUNKNOWN)0x0,0x17);
  if (local_18 < 0) {
    FUN_1000f2e0(param_1);
  }
  else {
    piVar2 = (int *)FUN_1000e430(&local_1c);
    uVar3 = FUN_10007eb0(param_1);
    local_18 = (**(code **)(*piVar2 + 0x20))(piVar2,uVar3,uVar1);
  }
  local_8 = 0xffffffff;
  FUN_1000ca90(&local_1c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ca90 at 1000ca90

void __fastcall FUN_1000ca90(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e108;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000e400(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000caf0 at 1000caf0

void FUN_1000caf0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e138;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  FUN_1000e480(&local_1c);
  local_8 = 0;
  uVar1 = FUN_1000e510(&local_1c);
  puVar2 = (undefined4 *)FUN_100156d0((undefined4 *)(local_14 + 0xc));
  local_18 = FUN_10010e80(puVar2,uVar1);
  if (local_18 < 0) {
    FUN_1000f2e0(param_1);
  }
  else {
    piVar3 = (int *)FUN_1000e530(&local_1c);
    uVar1 = FUN_10007eb0(param_1);
    local_18 = (**(code **)(*piVar3 + 0x20))(piVar3,uVar1);
  }
  local_8 = 0xffffffff;
  FUN_1000cbb0(&local_1c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cbb0 at 1000cbb0

void __fastcall FUN_1000cbb0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e168;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000e4e0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cc10 at 1000cc10

void FUN_1000cc10(undefined4 *param_1,void *param_2,undefined4 *param_3,undefined4 *param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 local_a8;
  undefined1 local_a4 [4];
  undefined4 local_a0 [17];
  undefined4 local_5c [7];
  undefined4 local_40 [7];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e1bb;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0;
  FUN_1000e550(&local_20);
  local_8 = 0;
  uVar2 = FUN_1000e5e0(&local_20);
  puVar3 = (undefined4 *)FUN_100156d0((undefined4 *)(local_18 + 0xc));
  local_1c = FUN_10010eb0(puVar3,uVar2);
  if (local_1c < 0) {
    FUN_1000f2e0(param_1);
  }
  else {
    piVar4 = (int *)FUN_1000e600(&local_20);
    uVar2 = FUN_10007eb0(param_1);
    local_1c = (**(code **)(*piVar4 + 0x1c))(piVar4,uVar2);
  }
  FUN_1000e620(&local_24);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_1c = FUN_1000e6d0(&local_24,(IID *)&DAT_10037f5c,(LPUNKNOWN)0x0,0x17);
  if (local_1c < 0) {
    FUN_1000f2e0(param_4);
  }
  else {
    piVar4 = (int *)FUN_1000e6b0(&local_24);
    uVar2 = FUN_10007eb0(param_4);
    local_1c = (**(code **)(*piVar4 + 0x38))(piVar4,uVar2);
  }
  FUN_10015780(local_40);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar5 = FUN_1000d640(&DAT_10044164,local_40,1);
  if (iVar5 == 0) {
    FUN_1000f2e0(param_3);
  }
  else {
    piVar4 = (int *)FUN_1000da40(&DAT_10044180,local_a4);
    puVar3 = FUN_1000da70(&DAT_10044180,&local_a8,local_40);
    bVar1 = FUN_1000db00(puVar3,piVar4);
    if (bVar1) {
      piVar4 = (int *)FUN_1000d900(&DAT_10044180,local_40);
      FUN_1000f0d0(param_3,piVar4);
    }
    else {
      FUN_1000f140(param_3,0x100373cc);
    }
  }
  FUN_1000cf00(local_5c);
  local_8._0_1_ = 3;
  piVar4 = (int *)FUN_100232d0(local_a0,local_5c);
  local_8._0_1_ = 4;
  FUN_1000f1b0(param_2,piVar4);
  local_8._0_1_ = 3;
  FUN_10007720(local_a0);
  local_8._0_1_ = 2;
  FUN_1000aca0(local_5c);
  local_8._0_1_ = 1;
  FUN_1000aca0(local_40);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000cea0(&local_24);
  local_8 = 0xffffffff;
  FUN_1000ce40(&local_20);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ce40 at 1000ce40

void __fastcall FUN_1000ce40(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e1f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000e5b0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cea0 at 1000cea0

void __fastcall FUN_1000cea0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e228;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000e680(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cf00 at 1000cf00

void FUN_1000cf00(void *param_1)

{
  BOOL BVar1;
  int iVar2;
  void *pvVar3;
  wchar_t *pwVar4;
  undefined4 *puVar5;
  wchar_t *pwVar6;
  undefined4 *puVar7;
  undefined1 local_2b8 [28];
  undefined1 local_29c [28];
  undefined1 local_280 [28];
  undefined1 local_264 [28];
  undefined1 local_248 [28];
  undefined1 local_22c [28];
  undefined1 local_210 [28];
  uint local_1f4;
  undefined1 local_1b0 [28];
  LSTATUS local_194;
  HKEY local_190;
  BOOL local_18c;
  _OSVERSIONINFOW local_188;
  undefined4 local_6c [7];
  undefined4 local_50 [7];
  undefined4 local_34 [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e2df;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1f4 = 0;
  FUN_10015780(local_34);
  local_8 = 1;
  FUN_10015780(local_50);
  local_8._0_1_ = 2;
  FUN_10015780(local_6c);
  local_8._0_1_ = 3;
  memset(&local_188,0,0x11c);
  local_188.dwOSVersionInfoSize = 0x11c;
  local_18c = GetVersionExW(&local_188);
  if (local_18c == 0) {
    local_188.dwOSVersionInfoSize = 0x114;
    BVar1 = GetVersionExW(&local_188);
    if (BVar1 == 0) {
      FUN_1000a150(param_1,(wchar_t *)0x0);
      local_1f4 = local_1f4 | 1;
      local_8._0_1_ = 2;
      FUN_1000aca0(local_6c);
      local_8._0_1_ = 1;
      FUN_1000aca0(local_50);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000aca0(local_34);
      goto LAB_1000d457;
    }
  }
  if (local_188.dwPlatformId == 0) {
    FUN_100158e0(local_34,L"Microsoft Win32s\n");
  }
  else if (local_188.dwPlatformId == 1) {
    if (((local_188.dwMajorVersion == 4) && (local_188.dwMinorVersion == 0)) &&
       ((FUN_100158e0(local_34,L"Microsoft Windows 95 "), local_188.szCSDVersion[1] == L'C' ||
        (local_188.szCSDVersion[1] == L'B')))) {
      FUN_100169a0(local_34,L" OSR2");
    }
    if (((local_188.dwMajorVersion == 4) && (local_188.dwMinorVersion == 10)) &&
       (FUN_100158e0(local_34,L"Microsoft Windows 98 "), local_188.szCSDVersion[1] == L'A')) {
      FUN_100169a0(local_34,L"SE");
    }
    if ((local_188.dwMajorVersion == 4) && (local_188.dwMinorVersion == 0x5a)) {
      FUN_100158e0(local_34,L"Microsoft Windows Millennium Edition\n");
    }
  }
  else if (local_188.dwPlatformId == 2) {
    if ((local_188.dwMajorVersion == 5) && (local_188.dwMinorVersion == 2)) {
      FUN_100158e0(local_34,L"Microsoft Windows Server 2003 family");
    }
    if ((local_188.dwMajorVersion == 5) && (local_188.dwMinorVersion == 1)) {
      FUN_100158e0(local_34,L"Microsoft Windows XP ");
    }
    if ((local_188.dwMajorVersion == 5) && (local_188.dwMinorVersion == 0)) {
      FUN_100158e0(local_34,L"Microsoft Windows 2000 ");
    }
    if (local_188.dwMajorVersion < 5) {
      FUN_100158e0(local_34,L"Microsoft Windows NT ");
    }
    if ((local_188.dwMajorVersion == 6) && (local_188.dwMinorVersion == 0)) {
      FUN_100158b0(local_34,(undefined4 *)&DAT_10044128);
    }
    if ((local_188.dwMajorVersion == 4) &&
       (iVar2 = lstrcmpiW(local_188.szCSDVersion,L"Service Pack 6"), iVar2 == 0)) {
      local_194 = RegOpenKeyExW((HKEY)0x80000002,
                                L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009",
                                0,1,&local_190);
      if (local_194 == 0) {
        FUN_100158e0(local_50,L"Service Pack 6a");
        pvVar3 = FUN_10022bb0(local_2b8,local_188.dwBuildNumber & 0xffff);
        local_8._0_1_ = 4;
        FUN_10015880(local_6c,pvVar3);
        local_8._0_1_ = 3;
        FUN_1000aca0(local_2b8);
      }
      else {
        pvVar3 = FUN_10022bb0(local_29c,local_188.dwBuildNumber & 0xffff);
        local_8._0_1_ = 5;
        FUN_10015880(local_6c,pvVar3);
        local_8._0_1_ = 3;
        FUN_1000aca0(local_29c);
        FUN_100158e0(local_50,local_188.szCSDVersion);
      }
      RegCloseKey(local_190);
    }
    else {
      pvVar3 = FUN_10022bb0(local_280,local_188.dwBuildNumber & 0xffff);
      local_8._0_1_ = 6;
      FUN_10015880(local_6c,pvVar3);
      local_8._0_1_ = 3;
      FUN_1000aca0(local_280);
      FUN_100158e0(local_50,local_188.szCSDVersion);
    }
  }
  puVar7 = local_50;
  pwVar6 = L":";
  puVar5 = local_34;
  pwVar4 = L":";
  pvVar3 = (void *)FUN_10010ee0(local_264,L"Build ",local_6c);
  local_8._0_1_ = 7;
  pvVar3 = FUN_10010fa0(local_248,pvVar3,pwVar4);
  local_8._0_1_ = 8;
  pvVar3 = FUN_10016740(local_22c,pvVar3,puVar5);
  local_8._0_1_ = 9;
  pvVar3 = FUN_10010fa0(local_210,pvVar3,pwVar6);
  local_8._0_1_ = 10;
  FUN_10016740(local_1b0,pvVar3,puVar7);
  local_8._0_1_ = 0xc;
  FUN_1000aca0(local_210);
  local_8._0_1_ = 0xd;
  FUN_1000aca0(local_22c);
  local_8._0_1_ = 0xe;
  FUN_1000aca0(local_248);
  local_8._0_1_ = 0xf;
  FUN_1000aca0(local_264);
  FUN_100157f0(param_1,(int)local_1b0);
  local_1f4 = local_1f4 | 1;
  local_8._0_1_ = 3;
  FUN_1000aca0(local_1b0);
  local_8._0_1_ = 2;
  FUN_1000aca0(local_6c);
  local_8._0_1_ = 1;
  FUN_1000aca0(local_50);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(local_34);
LAB_1000d457:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d480 at 1000d480

void FUN_1000d480(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  uint uStack_c8;
  undefined1 local_b0 [28];
  undefined4 local_94;
  undefined4 local_50;
  undefined1 local_4c [28];
  undefined4 local_30;
  undefined4 local_2c [4];
  int local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e35a;
  local_10 = ExceptionList;
  uStack_c8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_c8;
  ExceptionList = &local_10;
  local_94 = 0;
  local_18 = uStack_c8;
  FUN_10010de0(local_2c);
  local_8 = 1;
  FUN_10007e90(&local_30);
  local_8._0_1_ = 2;
  FUN_10015780(local_4c);
  local_8._0_1_ = 3;
  FUN_1000e550(&local_50);
  local_8._0_1_ = 5;
  uVar1 = FUN_1000e5e0(&local_50);
  puVar2 = (undefined4 *)FUN_100156d0((undefined4 *)(local_1c + 0xc));
  uVar1 = FUN_10010eb0(puVar2,uVar1);
  FUN_10010e40(local_2c,uVar1);
  piVar3 = (int *)FUN_1000e600(&local_50);
  uVar1 = FUN_10007eb0(&local_30);
  uVar1 = (**(code **)(*piVar3 + 0x1c))(piVar3,uVar1);
  FUN_10010e40(local_2c,uVar1);
  iVar4 = FUN_10007570(&local_30);
  pvVar5 = FUN_10023020(local_b0,iVar4);
  local_8._0_1_ = 6;
  FUN_10015880(local_4c,pvVar5);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_1000aca0(local_b0);
  FUN_1000d5a8();
  return;
}



// Function: Catch@1000d59b at 1000d59b

undefined4 Catch_1000d59b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return 0x1000d5af;
}



// Function: FUN_1000d5a8 at 1000d5a8

void FUN_1000d5a8(void)

{
  int iVar1;
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 4;
  iVar1 = FUN_1000db30(unaff_EBP - 0x28);
  if (iVar1 < 0) {
    FUN_1000db50((void *)(unaff_EBP - 0x28),0x80004005);
  }
  FUN_100157f0(*(void **)(unaff_EBP + 8),unaff_EBP - 0x48);
  *(uint *)(unaff_EBP - 0x90) = *(uint *)(unaff_EBP - 0x90) | 1;
  *(undefined1 *)(unaff_EBP - 4) = 3;
  FUN_1000ce40((int *)(unaff_EBP - 0x4c));
  *(undefined1 *)(unaff_EBP - 4) = 2;
  FUN_1000aca0((void *)(unaff_EBP - 0x48));
  *(undefined1 *)(unaff_EBP - 4) = 1;
  FUN_10007720((undefined4 *)(unaff_EBP - 0x2c));
  *(undefined1 *)(unaff_EBP - 4) = 0;
  FUN_10010e20((undefined4 *)(unaff_EBP - 0x28));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1000d62e;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1000d640 at 1000d640

void FUN_1000d640(void *param_1,void *param_2,int param_3)

{
  int iVar1;
  LPCWSTR pWVar2;
  uint uVar3;
  DWORD *pDVar4;
  DWORD local_27c;
  wchar_t local_278;
  undefined1 local_276 [522];
  undefined4 local_6c;
  undefined4 local_68 [7];
  undefined4 local_4c [7];
  uint local_30;
  LSTATUS local_2c;
  int local_28 [3];
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e3a8;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 1;
  FUN_10004e20(local_28,0);
  local_8 = 0;
  local_30 = FUN_100159c0(param_1,L"\\",0xffffffff);
  FUN_10015a00(local_4c,0,local_30);
  local_8._0_1_ = 1;
  iVar1 = FUN_10015960((int)param_1);
  FUN_10015a00(local_68,local_30 + 1,iVar1 - local_30);
  local_8 = CONCAT31(local_8._1_3_,2);
  uVar3 = 0x2001f;
  pWVar2 = (LPCWSTR)FUN_10015940(local_4c);
  local_2c = FUN_10005260(local_28,(HKEY)0x80000002,pWVar2,uVar3);
  if (local_2c == 0) {
    if (param_3 == 1) {
      local_6c = 0;
      local_278 = L'\0';
      memset(local_276,0,0x208);
      local_27c = 0x20a;
      pDVar4 = &local_27c;
      pWVar2 = (LPCWSTR)FUN_10015940(local_68);
      local_2c = FUN_10014450(local_28,(LPBYTE)&local_278,pWVar2,pDVar4);
      if (local_2c == 0) {
        FUN_100158e0(param_2,&local_278);
      }
      else {
        local_1c = 0;
      }
    }
    else {
      local_1c = 0;
      OutputDebugStringW(L"Exception while reading Registry due to Data mismatch");
    }
  }
  else {
    local_1c = 0;
  }
  FUN_10005090(local_28);
  local_8._0_1_ = 1;
  FUN_1000aca0(local_68);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(local_4c);
  local_8 = 0xffffffff;
  FUN_10004e60(local_28);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d7f0 at 1000d7f0

void FUN_1000d7f0(void *param_1)

{
  BOOL BVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_a0 [7];
  undefined4 local_84;
  uint local_80;
  DWORD local_3c;
  WCHAR local_38 [18];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e3fc;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_80 = 0;
  BVar1 = GetComputerNameW(local_38,&local_3c);
  if (BVar1 == 0) {
    FUN_1000f080(param_1,(int *)&DAT_10044160);
    local_8 = 0;
    local_80 = local_80 | 1;
  }
  else {
    FUN_1000a150(local_a0,local_38);
    local_8 = 1;
    piVar2 = (int *)FUN_100232d0(&local_84,local_a0);
    local_8._0_1_ = 2;
    iVar3 = FUN_1000f280(piVar2);
    FUN_1000ac40(param_1,iVar3);
    local_80 = local_80 | 1;
    local_8._0_1_ = 1;
    FUN_10007720(&local_84);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_1000aca0(local_a0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000d900 at 1000d900

void __thiscall FUN_1000d900(void *this,undefined4 *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined1 local_8c [32];
  undefined1 local_6c [4];
  undefined4 local_68;
  int local_64;
  undefined4 local_60 [17];
  int local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e443;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = this;
  FUN_1000e950(this,&local_1c,param_1);
  piVar3 = (int *)FUN_1000da40(local_18,local_6c);
  bVar1 = FUN_1000eab0(&local_1c,piVar3);
  if (!bVar1) {
    iVar4 = FUN_1000eae0(&local_1c);
    puVar5 = (undefined4 *)FUN_1000e990(iVar4);
    cVar2 = FUN_1000e9c0(param_1,puVar5);
    if (cVar2 == '\0') goto LAB_1000da13;
  }
  local_64 = local_1c;
  puVar5 = FUN_10007e90(&local_68);
  local_8 = 0;
  pvVar6 = FUN_1000e9f0(local_8c,param_1,puVar5);
  local_8._0_1_ = 1;
  piVar3 = FUN_10011020(local_18,local_60,local_64,pvVar6);
  local_1c = *piVar3;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000e700(local_8c);
  local_8 = 0xffffffff;
  FUN_10007720(&local_68);
LAB_1000da13:
  FUN_1000ea90(&local_1c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000da40 at 1000da40

void * __thiscall FUN_1000da40(void *this,void *param_1)

{
  FUN_1000ea60(param_1,*(undefined4 *)((int)this + 4));
  return param_1;
}



// Function: FUN_1000da70 at 1000da70

undefined4 * __thiscall FUN_1000da70(void *this,undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *local_5c;
  undefined1 local_54 [4];
  undefined1 local_50 [68];
  undefined4 local_c;
  void *local_8;
  
  local_8 = this;
  FUN_1000e950(this,&local_c,param_2);
  piVar3 = (int *)FUN_1000da40(local_8,local_54);
  bVar1 = FUN_1000eab0(&local_c,piVar3);
  if (!bVar1) {
    iVar4 = FUN_1000eae0(&local_c);
    puVar5 = (undefined4 *)FUN_1000e990(iVar4);
    cVar2 = FUN_1000e9c0(param_2,puVar5);
    if (cVar2 == '\0') {
      local_5c = &local_c;
      goto LAB_1000dae4;
    }
  }
  local_5c = (undefined4 *)FUN_1000da40(local_8,local_50);
LAB_1000dae4:
  *param_1 = *local_5c;
  return param_1;
}



// Function: FUN_1000db00 at 1000db00

bool __thiscall FUN_1000db00(void *this,int *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_1000eab0(this,param_1);
  return (bool)('\x01' - bVar1);
}



// Function: FUN_1000db30 at 1000db30

undefined4 __fastcall FUN_1000db30(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



// Function: FUN_1000db50 at 1000db50

int __thiscall FUN_1000db50(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = param_1;
  return (int)this;
}



// Function: FUN_1000db80 at 1000db80

undefined4 * __fastcall FUN_1000db80(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e478;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000eb00(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000dbe0 at 1000dbe0

void __fastcall FUN_1000dbe0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000dc10 at 1000dc10

undefined4 __fastcall FUN_1000dc10(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000dc30 at 1000dc30

void __thiscall FUN_1000dc30(void *this,IID *param_1,LPUNKNOWN param_2,DWORD param_3)

{
  CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_100373b0,(LPVOID *)this);
  return;
}



// Function: FUN_1000dc60 at 1000dc60

undefined4 * __fastcall FUN_1000dc60(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e4a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000eb20(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000dcc0 at 1000dcc0

void __fastcall FUN_1000dcc0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000dcf0 at 1000dcf0

undefined4 __fastcall FUN_1000dcf0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000dd10 at 1000dd10

undefined4 __fastcall FUN_1000dd10(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000dd30 at 1000dd30

int FUN_1000dd30(void)

{
  undefined1 local_56 [66];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e4d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000eca0(local_56);
  FUN_1000eb40(local_14);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000dda0 at 1000dda0

int __thiscall FUN_1000dda0(void *this,int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined1 local_74 [4];
  undefined1 local_70 [8];
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c [17];
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e510;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = this;
  FUN_1000ebb0(this,&local_18,param_1);
  piVar2 = (int *)FUN_1000e030(local_14,local_74);
  bVar1 = FUN_1000ed60(&local_18,piVar2);
  if (!bVar1) {
    iVar3 = FUN_1000ed90(&local_18);
    piVar2 = (int *)FUN_1000ec70(iVar3);
    bVar1 = FUN_1000ecc0(param_1,piVar2);
    if (!bVar1) goto LAB_1000dea0;
  }
  puVar4 = (undefined4 *)FUN_10011060(param_1);
  local_64 = *puVar4;
  local_60 = local_18;
  puVar4 = FUN_10007e90(&local_68);
  local_8 = 0;
  pvVar5 = FUN_1000f200(local_70,&local_64,puVar4);
  local_8._0_1_ = 1;
  piVar2 = FUN_10011080(local_14,local_5c,local_60,pvVar5);
  local_18 = *piVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000e760((int)local_70);
  local_8 = 0xffffffff;
  FUN_10007720(&local_68);
LAB_1000dea0:
  iVar3 = FUN_1000ed20(&local_18);
  ExceptionList = local_10;
  return iVar3 + 4;
}



// Function: FUN_1000dec0 at 1000dec0

int __thiscall FUN_1000dec0(void *this,int *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined1 local_70 [4];
  undefined1 local_6c [8];
  undefined4 local_64;
  int local_60;
  undefined4 local_5c [17];
  int local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e540;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = this;
  FUN_1000ebb0(this,&local_18,param_1);
  piVar2 = (int *)FUN_1000e030(local_14,local_70);
  bVar1 = FUN_1000ed60(&local_18,piVar2);
  if (!bVar1) {
    iVar3 = FUN_1000ed90(&local_18);
    piVar2 = (int *)FUN_1000ec70(iVar3);
    bVar1 = FUN_1000ecc0(param_1,piVar2);
    if (!bVar1) goto LAB_1000dfab;
  }
  local_60 = local_18;
  puVar4 = FUN_10007e90(&local_64);
  local_8 = 0;
  pvVar5 = FUN_1000ef70(local_6c,param_1,puVar4);
  local_8._0_1_ = 1;
  piVar2 = FUN_100110c0(local_14,local_5c,local_60,pvVar5);
  local_18 = *piVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000e7c0((int)local_6c);
  local_8 = 0xffffffff;
  FUN_10007720(&local_64);
LAB_1000dfab:
  iVar3 = FUN_1000ed20(&local_18);
  ExceptionList = local_10;
  return iVar3 + 4;
}



// Function: FUN_1000dfd0 at 1000dfd0

void __fastcall FUN_1000dfd0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e568;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000ebf0(param_1);
  local_8 = 0xffffffff;
  FUN_1000ec40((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e030 at 1000e030

void * __thiscall FUN_1000e030(void *this,void *param_1)

{
  FUN_1000ecf0(param_1,*(undefined4 *)((int)this + 4));
  return param_1;
}



// Function: FUN_1000e060 at 1000e060

undefined4 * __thiscall FUN_1000e060(void *this,undefined4 *param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *local_5c;
  undefined1 local_54 [4];
  undefined1 local_50 [68];
  undefined4 local_c;
  void *local_8;
  
  local_8 = this;
  FUN_1000ebb0(this,&local_c,param_2);
  piVar2 = (int *)FUN_1000e030(local_8,local_54);
  bVar1 = FUN_1000ed60(&local_c,piVar2);
  if (!bVar1) {
    iVar3 = FUN_1000ed90(&local_c);
    piVar2 = (int *)FUN_1000ec70(iVar3);
    bVar1 = FUN_1000ecc0(param_2,piVar2);
    if (!bVar1) {
      local_5c = &local_c;
      goto LAB_1000e0d4;
    }
  }
  local_5c = (undefined4 *)FUN_1000e030(local_8,local_50);
LAB_1000e0d4:
  *param_1 = *local_5c;
  return param_1;
}



// Function: FUN_1000e0f0 at 1000e0f0

undefined4 * __fastcall FUN_1000e0f0(undefined4 *param_1)

{
  FUN_1000ed40(param_1);
  return param_1;
}



// Function: FUN_1000e110 at 1000e110

void __fastcall FUN_1000e110(int *param_1)

{
  FUN_1000ed20(param_1);
  return;
}



// Function: FUN_1000e130 at 1000e130

bool __thiscall FUN_1000e130(void *this,int *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_1000ed60(this,param_1);
  return (bool)('\x01' - bVar1);
}



// Function: FUN_1000e160 at 1000e160

undefined4 * __fastcall FUN_1000e160(undefined4 *param_1)

{
  undefined4 *puStack_6c;
  uint uStack_68;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e598;
  local_10 = ExceptionList;
  uStack_68 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puStack_6c = param_1;
  FUN_10016660(&puStack_6c);
  FUN_1000ef00(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e1d0 at 1000e1d0

void __thiscall FUN_1000e1d0(void *this,undefined4 param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = FUN_10011100(param_1);
  cVar2 = FUN_1000edb0(this,uVar3);
  if (cVar2 == '\0') {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_1000edf0(this,1);
    }
    FUN_1000eee0();
    uVar5 = FUN_100168a0(param_1);
    FUN_10011120((int)this + 0xc,*(undefined4 *)((int)this + 4),uVar5);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  }
  else {
    iVar4 = FUN_10011100(param_1);
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_1000edf0(this,1);
    }
    FUN_1000eee0();
                    /* WARNING: Load size is inaccurate */
    uVar5 = FUN_100168a0(((iVar4 - iVar1) / 0x1c) * 0x1c + *this);
    FUN_10011120((int)this + 0xc,*(undefined4 *)((int)this + 4),uVar5);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  }
  return;
}



// Function: FUN_1000e2f0 at 1000e2f0

void __fastcall FUN_1000e2f0(_Container_base0 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e5c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000ee60(param_1);
  local_8 = 0xffffffff;
  FUN_1000ef50();
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e350 at 1000e350

int __fastcall FUN_1000e350(int *param_1)

{
  return (param_1[1] - *param_1) / 0x1c;
}



// Function: FUN_1000e380 at 1000e380

int __thiscall FUN_1000e380(void *this,int param_1)

{
                    /* WARNING: Load size is inaccurate */
  return param_1 * 0x1c + *this;
}



// Function: FUN_1000e3a0 at 1000e3a0

void * __thiscall FUN_1000e3a0(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e5f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000efe0(this,param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000e400 at 1000e400

void __fastcall FUN_1000e400(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000e430 at 1000e430

undefined4 __fastcall FUN_1000e430(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000e450 at 1000e450

void __thiscall FUN_1000e450(void *this,IID *param_1,LPUNKNOWN param_2,DWORD param_3)

{
  CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10037958,(LPVOID *)this);
  return;
}



// Function: FUN_1000e480 at 1000e480

undefined4 * __fastcall FUN_1000e480(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e628;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000f020(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e4e0 at 1000e4e0

void __fastcall FUN_1000e4e0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000e510 at 1000e510

undefined4 __fastcall FUN_1000e510(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000e530 at 1000e530

undefined4 __fastcall FUN_1000e530(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000e550 at 1000e550

undefined4 * __fastcall FUN_1000e550(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e658;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000f040(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e5b0 at 1000e5b0

void __fastcall FUN_1000e5b0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000e5e0 at 1000e5e0

undefined4 __fastcall FUN_1000e5e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000e600 at 1000e600

undefined4 __fastcall FUN_1000e600(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000e620 at 1000e620

undefined4 * __fastcall FUN_1000e620(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e688;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000f060(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000e680 at 1000e680

void __fastcall FUN_1000e680(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1000e6b0 at 1000e6b0

undefined4 __fastcall FUN_1000e6b0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000e6d0 at 1000e6d0

void __thiscall FUN_1000e6d0(void *this,IID *param_1,LPUNKNOWN param_2,DWORD param_3)

{
  CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_10037968,(LPVOID *)this);
  return;
}



// Function: FUN_1000e700 at 1000e700

void __fastcall FUN_1000e700(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e6b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000e820(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e760 at 1000e760

void __fastcall FUN_1000e760(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e6e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000e890(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e7c0 at 1000e7c0

void __fastcall FUN_1000e7c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e718;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000e8f0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e820 at 1000e820

void __fastcall FUN_1000e820(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e753;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10007720((undefined4 *)((int)param_1 + 0x1c));
  local_8 = 0xffffffff;
  FUN_1000aca0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e890 at 1000e890

void __fastcall FUN_1000e890(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e77b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10007720((undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e8f0 at 1000e8f0

void __fastcall FUN_1000e8f0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002e7ab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10007720((undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e950 at 1000e950

void * __thiscall FUN_1000e950(void *this,void *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000f3b0(this,param_2);
  FUN_1000ea60(param_1,iVar1);
  return param_1;
}



// Function: FUN_1000e990 at 1000e990

void __cdecl FUN_1000e990(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000f440(param_1);
  FUN_10011150(iVar1);
  return;
}



// Function: FUN_1000e9c0 at 1000e9c0

void FUN_1000e9c0(void *param_1,undefined4 *param_2)

{
  FUN_10011170(param_1,param_2);
  return;
}



// Function: FUN_1000e9f0 at 1000e9f0

void * __thiscall FUN_1000e9f0(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e7d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_100111a0(param_2);
  FUN_1000f4a0(this,param_1,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000ea60 at 1000ea60

void * __thiscall FUN_1000ea60(void *this,undefined4 param_1)

{
  FUN_1000f550(this,param_1);
  return this;
}



// Function: FUN_1000ea90 at 1000ea90

void __fastcall FUN_1000ea90(int *param_1)

{
  FUN_1000f580(param_1);
  return;
}



// Function: FUN_1000eab0 at 1000eab0

bool __thiscall FUN_1000eab0(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == *param_1;
}



// Function: FUN_1000eae0 at 1000eae0

undefined4 __fastcall FUN_1000eae0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000eb00 at 1000eb00

undefined4 * __fastcall FUN_1000eb00(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000eb20 at 1000eb20

undefined4 * __fastcall FUN_1000eb20(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000eb40 at 1000eb40

int __fastcall FUN_1000eb40(int param_1)

{
  int iStack_6c;
  uint uStack_68;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e808;
  local_10 = ExceptionList;
  uStack_68 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iStack_6c = param_1;
  FUN_1000f8c0(&iStack_6c);
  FUN_1000f720(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000ebb0 at 1000ebb0

void * __thiscall FUN_1000ebb0(void *this,void *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000f690(this,param_2);
  FUN_1000ecf0(param_1,iVar1);
  return param_1;
}



// Function: FUN_1000ebf0 at 1000ebf0

void __fastcall FUN_1000ebf0(void *param_1)

{
  undefined4 *puVar1;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = param_1;
  FUN_1000e030(param_1,local_58);
  puVar1 = (undefined4 *)FUN_1000f5b0(local_8,local_50);
  local_54 = *puVar1;
  FUN_1000f5e0(local_8,local_4c,local_54);
  return;
}



// Function: FUN_1000ec40 at 1000ec40

void __fastcall FUN_1000ec40(int param_1)

{
  FUN_1000f8e0(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_1000ec70 at 1000ec70

void __cdecl FUN_1000ec70(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000f8a0(param_1);
  FUN_100111c0(iVar1);
  return;
}



// Function: FUN_1000eca0 at 1000eca0

undefined4 __fastcall FUN_1000eca0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000ecc0 at 1000ecc0

bool FUN_1000ecc0(int *param_1,int *param_2)

{
  return *param_1 < *param_2;
}



// Function: FUN_1000ecf0 at 1000ecf0

void * __thiscall FUN_1000ecf0(void *this,undefined4 param_1)

{
  FUN_1000f910(this,param_1);
  return this;
}



// Function: FUN_1000ed20 at 1000ed20

void __fastcall FUN_1000ed20(int *param_1)

{
  FUN_1000f940(param_1);
  return;
}



// Function: FUN_1000ed40 at 1000ed40

undefined4 * __fastcall FUN_1000ed40(undefined4 *param_1)

{
  FUN_1000f970(param_1);
  return param_1;
}



// Function: FUN_1000ed60 at 1000ed60

bool __thiscall FUN_1000ed60(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == *param_1;
}



// Function: FUN_1000ed90 at 1000ed90

undefined4 __fastcall FUN_1000ed90(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1000edb0 at 1000edb0

undefined1 __thiscall FUN_1000edb0(void *this,uint param_1)

{
  undefined1 local_4c;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < *(uint *)((int)this + 4)) && (*this <= param_1)) {
    local_4c = 1;
  }
  else {
    local_4c = 0;
  }
  return local_4c;
}



// Function: FUN_1000edf0 at 1000edf0

void __thiscall FUN_1000edf0(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_1000e350((int *)this);
  iVar2 = FUN_1000fb10();
  if ((uint)(iVar2 - param_1) < uVar1) {
    FUN_1000fbc0();
  }
  else {
    uVar3 = FUN_1000fae0((int *)this);
    if (uVar3 < uVar1 + param_1) {
      uVar1 = FUN_1000fb60(this,uVar1 + param_1);
      FUN_1000f990(this,uVar1);
    }
  }
  return;
}



// Function: FUN_1000ee60 at 1000ee60

void __fastcall FUN_1000ee60(_Container_base0 *param_1)

{
  if (*(int *)param_1 != 0) {
    std::_Container_base0::_Orphan_all(param_1);
    FUN_1000fb30(param_1,*(void **)param_1,*(void **)(param_1 + 4));
    FUN_10016680(*(void **)param_1);
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_1000eee0 at 1000eee0

void FUN_1000eee0(void)

{
  return;
}



// Function: FUN_1000ef00 at 1000ef00

undefined4 * __fastcall FUN_1000ef00(undefined4 *param_1)

{
  FUN_100166e0(param_1 + 3);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



// Function: FUN_1000ef50 at 1000ef50

void FUN_1000ef50(void)

{
  return;
}



// Function: FUN_1000ef70 at 1000ef70

void * __thiscall FUN_1000ef70(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e838;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_100111a0(param_2);
  FUN_1000fbe0(this,param_1,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000efe0 at 1000efe0

int * __thiscall FUN_1000efe0(void *this,int param_1)

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



// Function: FUN_1000f020 at 1000f020

undefined4 * __fastcall FUN_1000f020(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000f040 at 1000f040

undefined4 * __fastcall FUN_1000f040(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000f060 at 1000f060

undefined4 * __fastcall FUN_1000f060(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000f080 at 1000f080

int * __thiscall FUN_1000f080(void *this,int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_1000f280(param_1);
  *(undefined4 *)this = uVar2;
  bVar1 = FUN_10008590(param_1);
  if (!bVar1) {
    bVar1 = FUN_10008590((int *)this);
    if (bVar1) {
      FUN_10003210(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_1000f0d0 at 1000f0d0

int * __thiscall FUN_1000f0d0(void *this,int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    uVar2 = FUN_1000f280(param_1);
    *(undefined4 *)this = uVar2;
    bVar1 = FUN_10008590(param_1);
    if (!bVar1) {
      bVar1 = FUN_10008590((int *)this);
      if (bVar1) {
        FUN_10003210(0x8007000e);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_1000f140 at 1000f140

int * __thiscall FUN_1000f140(void *this,int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 != *this) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    if (param_1 == 0) {
      *(undefined4 *)this = 0;
    }
    else {
      uVar2 = Ordinal_2(param_1);
      *(undefined4 *)this = uVar2;
      bVar1 = FUN_10008590((int *)this);
      if (bVar1) {
        FUN_10003210(0x8007000e);
      }
    }
  }
  return (int *)this;
}



// Function: FUN_1000f1b0 at 1000f1b0

int * __thiscall FUN_1000f1b0(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_1000f200 at 1000f200

void * __thiscall FUN_1000f200(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e868;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_100111a0(param_2);
  uVar2 = FUN_10011060(param_1);
  FUN_1000fc60(this,uVar2,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000f280 at 1000f280

undefined4 __fastcall FUN_1000f280(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_10008590(param_1);
  if (bVar1) {
    uVar2 = 0;
  }
  else if (*param_1 == 0) {
    uVar2 = Ordinal_150(0,0);
  }
  else {
    uVar2 = Ordinal_149(*param_1);
    uVar2 = Ordinal_150(*param_1,uVar2);
  }
  return uVar2;
}



// Function: FUN_1000f2e0 at 1000f2e0

void __fastcall FUN_1000f2e0(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000f310 at 1000f310

void FUN_1000f310(undefined4 *param_1)

{
  FUN_1000f340(*param_1);
  return;
}



// Function: FUN_1000f340 at 1000f340

int FUN_1000f340(undefined4 param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined4 *local_8;
  
  iVar1 = Ordinal_7(param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    local_c = 0;
    iVar1 = Ordinal_313(*local_8,param_1,&local_c);
    if (-1 < iVar1) {
      Ordinal_6(*local_8);
      *local_8 = local_c;
    }
  }
  return iVar1;
}



// Function: FUN_1000f3b0 at 1000f3b0

int __thiscall FUN_1000f3b0(void *this,undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int local_10;
  int local_c;
  
  piVar2 = (int *)FUN_1000fce0((int)this);
  local_c = *piVar2;
  local_10 = *(int *)((int)this + 4);
  while (pcVar3 = (char *)FUN_1000fd10(local_c), *pcVar3 == '\0') {
    puVar5 = param_1;
    pvVar4 = (void *)FUN_1000e990(local_c);
    cVar1 = FUN_1000e9c0(pvVar4,puVar5);
    if (cVar1 == '\0') {
      local_10 = local_c;
      piVar2 = (int *)FUN_1000fd30(local_c);
      local_c = *piVar2;
    }
    else {
      piVar2 = (int *)FUN_1000fd70(local_c);
      local_c = *piVar2;
    }
  }
  return local_10;
}



// Function: FUN_1000f440 at 1000f440

int __cdecl FUN_1000f440(int param_1)

{
  return param_1 + 0xc;
}



// Function: FUN_1000f460 at 1000f460

undefined4 __fastcall FUN_1000f460(undefined4 *param_1)

{
  int iVar1;
  DWORD cchLength;
  
  iVar1 = Ordinal_7(*param_1);
  if (iVar1 != 0) {
    cchLength = FUN_10008520(param_1);
    CharUpperBuffW((LPWSTR)*param_1,cchLength);
  }
  return 0;
}



// Function: FUN_1000f4a0 at 1000f4a0

void * __thiscall FUN_1000f4a0(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e8a3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100156f0(this,param_1);
  local_8 = 0;
  puVar1 = (undefined4 *)FUN_100111a0(param_2);
  FUN_1000f520((void *)((int)this + 0x1c),puVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1000f520 at 1000f520

undefined4 * __thiscall FUN_1000f520(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  *param_1 = 0;
  return (undefined4 *)this;
}



// Function: FUN_1000f550 at 1000f550

void * __thiscall FUN_1000f550(void *this,undefined4 param_1)

{
  FUN_1000fd90(this,param_1);
  return this;
}



// Function: FUN_1000f580 at 1000f580

void __fastcall FUN_1000f580(int *param_1)

{
  FUN_1000f440(*param_1);
  return;
}



// Function: FUN_1000f5b0 at 1000f5b0

void * __thiscall FUN_1000f5b0(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_100105b0((int)this);
  FUN_1000ecf0(param_1,*puVar1);
  return param_1;
}



// Function: FUN_1000f5e0 at 1000f5e0

/* WARNING: Variable defined which should be unmapped: param_2 */

void * __thiscall FUN_1000f5e0(void *param_1,void *param_2,undefined4 param_3)

{
  bool bVar1;
  int *piVar2;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  int local_50;
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = param_1;
  piVar2 = (int *)FUN_1000f5b0(param_1,local_58);
  bVar1 = FUN_1000ed60(&param_3,piVar2);
  if (bVar1) {
    piVar2 = (int *)FUN_1000e030(local_8,local_54);
    bVar1 = FUN_1000ed60(&stack0x0000000c,piVar2);
    if (bVar1) {
      FUN_10010550(local_8);
      FUN_1000f5b0(local_8,param_2);
      return param_2;
    }
  }
  while (bVar1 = FUN_1000e130(&param_3,(int *)&stack0x0000000c), bVar1) {
    piVar2 = FUN_10010730(&param_3,&local_50);
    FUN_1000fdc0(local_8,local_4c,*piVar2);
  }
  FUN_1000ecf0(param_2,param_3);
  return param_2;
}



// Function: FUN_1000f690 at 1000f690

int __thiscall FUN_1000f690(void *this,int *param_1)

{
  bool bVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  int local_10;
  int local_c;
  
  piVar2 = (int *)FUN_100105e0((int)this);
  local_c = *piVar2;
  local_10 = *(int *)((int)this + 4);
  while (pcVar3 = (char *)FUN_10010630(local_c), *pcVar3 == '\0') {
    piVar2 = param_1;
    piVar4 = (int *)FUN_1000ec70(local_c);
    bVar1 = FUN_1000ecc0(piVar4,piVar2);
    if (bVar1) {
      piVar2 = (int *)FUN_10010690(local_c);
      local_c = *piVar2;
    }
    else {
      local_10 = local_c;
      piVar2 = (int *)FUN_10010650(local_c);
      local_c = *piVar2;
    }
  }
  return local_10;
}



// Function: FUN_1000f720 at 1000f720

int __fastcall FUN_1000f720(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  FUN_1000f8c0(&stack0xffffffa4);
  FUN_100106b0(param_1);
  *(undefined4 *)(param_1 + 8) = 0;
  uVar1 = FUN_10010700(1);
  *(undefined4 *)(param_1 + 4) = uVar1;
  puVar2 = (undefined4 *)FUN_10010650(*(undefined4 *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_10010670(*(int *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_10010690(*(int *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined1 *)FUN_10010610(*(int *)(param_1 + 4));
  *puVar3 = 1;
  puVar3 = (undefined1 *)FUN_10010630(*(int *)(param_1 + 4));
  *puVar3 = 1;
  return param_1;
}



// Function: FUN_1000f7e0 at 1000f7e0

bool FUN_1000f7e0(int param_1)

{
  bool bVar1;
  undefined4 local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e8c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000ac40(&local_18,param_1);
  local_8 = 0;
  bVar1 = FUN_1000f860(local_14,&local_18);
  local_8 = 0xffffffff;
  FUN_10007720(&local_18);
  ExceptionList = local_10;
  return bVar1;
}



// Function: FUN_1000f860 at 1000f860

bool __thiscall FUN_1000f860(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_314(*this,*param_1,0x400,0);
  return (bool)('\x01' - (iVar1 != 1));
}



// Function: FUN_1000f8a0 at 1000f8a0

int __cdecl FUN_1000f8a0(int param_1)

{
  return param_1 + 0xc;
}



// Function: FUN_1000f8c0 at 1000f8c0

undefined4 __fastcall FUN_1000f8c0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000f8e0 at 1000f8e0

void FUN_1000f8e0(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1000f910 at 1000f910

void * __thiscall FUN_1000f910(void *this,undefined4 param_1)

{
  FUN_10010760(this,param_1);
  return this;
}



// Function: FUN_1000f940 at 1000f940

void __fastcall FUN_1000f940(int *param_1)

{
  FUN_1000f8a0(*param_1);
  return;
}



// Function: FUN_1000f970 at 1000f970

undefined4 * __fastcall FUN_1000f970(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1000f990 at 1000f990

void __thiscall FUN_1000f990(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e8f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_1000fb10();
  if (uVar1 < param_1) {
    FUN_1000fbc0();
  }
  else {
    uVar1 = FUN_1000fae0((int *)this);
    if (uVar1 < param_1) {
      iVar2 = FUN_100166b0(param_1);
      local_8 = 0;
                    /* WARNING: Load size is inaccurate */
      FUN_100111e0(this,*this,*(int *)((int)this + 4),iVar2);
      FUN_1000fa47();
      return;
    }
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000fa1e at 1000fa1e

void Catch_1000fa1e(void)

{
  int unaff_EBP;
  
  FUN_10016680(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000fa47 at 1000fa47

void FUN_1000fa47(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = FUN_1000e350(*(int **)(unaff_EBP + -0x14));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  if (**(int **)(unaff_EBP + -0x14) != 0) {
    FUN_1000fb30(*(void **)(unaff_EBP + -0x14),(void *)**(undefined4 **)(unaff_EBP + -0x14),
                 *(void **)(*(int *)(unaff_EBP + -0x14) + 4));
    FUN_10016680((void *)**(undefined4 **)(unaff_EBP + -0x14));
  }
  std::_Container_base0::_Orphan_all(*(_Container_base0 **)(unaff_EBP + -0x14));
  *(int *)(*(int *)(unaff_EBP + -0x14) + 8) =
       *(int *)(unaff_EBP + 8) * 0x1c + *(int *)(unaff_EBP + -0x18);
  *(int *)(*(int *)(unaff_EBP + -0x14) + 4) =
       *(int *)(unaff_EBP + -0x1c) * 0x1c + *(int *)(unaff_EBP + -0x18);
  **(undefined4 **)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000fae0 at 1000fae0

int __fastcall FUN_1000fae0(int *param_1)

{
  return (param_1[2] - *param_1) / 0x1c;
}



// Function: FUN_1000fb10 at 1000fb10

void FUN_1000fb10(void)

{
  FUN_10016700();
  return;
}



// Function: FUN_1000fb30 at 1000fb30

void __thiscall FUN_1000fb30(void *this,void *param_1,void *param_2)

{
  FUN_10011210(param_1,param_2,(int)this + 0xc);
  return;
}



// Function: FUN_1000fb60 at 1000fb60

uint __thiscall FUN_1000fb60(void *this,uint param_1)

{
  int iVar1;
  undefined4 local_50;
  undefined4 local_c;
  
  local_50 = FUN_1000fae0((int *)this);
  iVar1 = FUN_1000fb10();
  if (iVar1 - (local_50 >> 1) < local_50) {
    local_50 = 0;
  }
  else {
    local_50 = (local_50 >> 1) + local_50;
  }
  local_c = local_50;
  if (local_50 < param_1) {
    local_c = param_1;
  }
  return local_c;
}



// Function: FUN_1000fbc0 at 1000fbc0

void FUN_1000fbc0(void)

{
  std::_Xlength_error("vector<T> too long");
  return;
}



// Function: FUN_1000fbe0 at 1000fbe0

undefined4 * __thiscall FUN_1000fbe0(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e91b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = *param_1;
  puVar1 = (undefined4 *)FUN_100111a0(param_2);
  FUN_1000f520((void *)((int)this + 4),puVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000fc60 at 1000fc60

undefined4 * __thiscall FUN_1000fc60(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e94b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10011060(param_1);
  *(undefined4 *)this = *puVar1;
  puVar1 = (undefined4 *)FUN_100111a0(param_2);
  FUN_1000f520((void *)((int)this + 4),puVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000fce0 at 1000fce0

void __fastcall FUN_1000fce0(int param_1)

{
  FUN_1000fd50(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_1000fd10 at 1000fd10

int __cdecl FUN_1000fd10(int param_1)

{
  return param_1 + 0x2d;
}



// Function: FUN_1000fd30 at 1000fd30

undefined4 __cdecl FUN_1000fd30(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1000fd50 at 1000fd50

int __cdecl FUN_1000fd50(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_1000fd70 at 1000fd70

int __cdecl FUN_1000fd70(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_1000fd90 at 1000fd90

undefined4 * __thiscall FUN_1000fd90(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_10014df0();
  return (undefined4 *)this;
}



// Function: FUN_1000fdc0 at 1000fdc0

void * __thiscall FUN_1000fdc0(void *this,void *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  void *pvVar9;
  void *local_5c;
  void *local_18;
  void *local_14;
  void *local_10;
  
  iVar1 = FUN_1000ed90(&param_2);
  pcVar2 = (char *)FUN_10010630(iVar1);
  if (*pcVar2 != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  pvVar3 = (void *)FUN_1000ed90(&param_2);
  FUN_10010ba0(&param_2);
  piVar4 = (int *)FUN_10010650(pvVar3);
  pcVar2 = (char *)FUN_10010630(*piVar4);
  local_18 = pvVar3;
  if (*pcVar2 == '\0') {
    piVar4 = (int *)FUN_10010690((int)pvVar3);
    pcVar2 = (char *)FUN_10010630(*piVar4);
    if (*pcVar2 == '\0') {
      local_18 = (void *)FUN_1000ed90(&param_2);
      puVar5 = (undefined4 *)FUN_10010690((int)local_18);
      local_10 = (void *)*puVar5;
    }
    else {
      puVar5 = (undefined4 *)FUN_10010650(pvVar3);
      local_10 = (void *)*puVar5;
    }
  }
  else {
    puVar5 = (undefined4 *)FUN_10010690((int)pvVar3);
    local_10 = (void *)*puVar5;
  }
  if (local_18 == pvVar3) {
    piVar4 = (int *)FUN_10010670((int)pvVar3);
    local_14 = (void *)*piVar4;
    pcVar2 = (char *)FUN_10010630((int)local_10);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_10010670((int)local_10);
      *piVar4 = (int)local_14;
    }
    piVar4 = (int *)FUN_100105e0((int)this);
    if ((void *)*piVar4 == pvVar3) {
      puVar5 = (undefined4 *)FUN_100105e0((int)this);
      *puVar5 = local_10;
    }
    else {
      piVar4 = (int *)FUN_10010650(local_14);
      if ((void *)*piVar4 == pvVar3) {
        puVar5 = (undefined4 *)FUN_10010650(local_14);
        *puVar5 = local_10;
      }
      else {
        puVar5 = (undefined4 *)FUN_10010690((int)local_14);
        *puVar5 = local_10;
      }
    }
    piVar4 = (int *)FUN_100105b0((int)this);
    if ((void *)*piVar4 == pvVar3) {
      pcVar2 = (char *)FUN_10010630((int)local_10);
      local_5c = local_14;
      if (*pcVar2 == '\0') {
        local_5c = (void *)FUN_10010b30(local_10);
      }
      piVar4 = (int *)FUN_100105b0((int)this);
      *piVar4 = (int)local_5c;
    }
    piVar4 = (int *)FUN_10010970((int)this);
    if ((void *)*piVar4 == pvVar3) {
      pcVar2 = (char *)FUN_10010630((int)local_10);
      local_5c = local_14;
      if (*pcVar2 == '\0') {
        local_5c = (void *)FUN_10010ae0((int)local_10);
      }
      piVar4 = (int *)FUN_10010970((int)this);
      *piVar4 = (int)local_5c;
    }
  }
  else {
    piVar4 = (int *)FUN_10010650(pvVar3);
    puVar5 = (undefined4 *)FUN_10010670(*piVar4);
    *puVar5 = local_18;
    puVar5 = (undefined4 *)FUN_10010650(pvVar3);
    puVar6 = (undefined4 *)FUN_10010650(local_18);
    *puVar6 = *puVar5;
    piVar4 = (int *)FUN_10010690((int)pvVar3);
    if (local_18 == (void *)*piVar4) {
      local_14 = local_18;
    }
    else {
      piVar4 = (int *)FUN_10010670((int)local_18);
      local_14 = (void *)*piVar4;
      pcVar2 = (char *)FUN_10010630((int)local_10);
      if (*pcVar2 == '\0') {
        piVar4 = (int *)FUN_10010670((int)local_10);
        *piVar4 = (int)local_14;
      }
      puVar5 = (undefined4 *)FUN_10010650(local_14);
      *puVar5 = local_10;
      puVar5 = (undefined4 *)FUN_10010690((int)pvVar3);
      puVar6 = (undefined4 *)FUN_10010690((int)local_18);
      *puVar6 = *puVar5;
      piVar4 = (int *)FUN_10010690((int)pvVar3);
      puVar5 = (undefined4 *)FUN_10010670(*piVar4);
      *puVar5 = local_18;
    }
    piVar4 = (int *)FUN_100105e0((int)this);
    if ((void *)*piVar4 == pvVar3) {
      puVar5 = (undefined4 *)FUN_100105e0((int)this);
      *puVar5 = local_18;
    }
    else {
      puVar5 = (undefined4 *)FUN_10010670((int)pvVar3);
      piVar4 = (int *)FUN_10010650(*puVar5);
      if ((void *)*piVar4 == pvVar3) {
        puVar5 = (undefined4 *)FUN_10010670((int)pvVar3);
        puVar5 = (undefined4 *)FUN_10010650(*puVar5);
        *puVar5 = local_18;
      }
      else {
        piVar4 = (int *)FUN_10010670((int)pvVar3);
        puVar5 = (undefined4 *)FUN_10010690(*piVar4);
        *puVar5 = local_18;
      }
    }
    puVar5 = (undefined4 *)FUN_10010670((int)pvVar3);
    puVar6 = (undefined4 *)FUN_10010670((int)local_18);
    *puVar6 = *puVar5;
    puVar7 = (undefined1 *)FUN_10010610((int)pvVar3);
    puVar8 = (undefined1 *)FUN_10010610((int)local_18);
    FUN_10011250(puVar8,puVar7);
  }
  pcVar2 = (char *)FUN_10010610((int)pvVar3);
  if (*pcVar2 != '\x01') {
LAB_100104e2:
    iVar1 = FUN_1000f8a0((int)pvVar3);
    pvVar9 = (void *)FUN_100112a0(iVar1);
    FUN_100112c0((int)this + 0xd,pvVar9);
    FUN_1000f8e0(pvVar3);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    FUN_1000ecf0(param_1,param_2);
    return param_1;
  }
LAB_10010166:
  piVar4 = (int *)FUN_100105e0((int)this);
  if ((local_10 == (void *)*piVar4) ||
     (pcVar2 = (char *)FUN_10010610((int)local_10), *pcVar2 != '\x01')) goto LAB_100104d3;
  piVar4 = (int *)FUN_10010650(local_14);
  if (local_10 == (void *)*piVar4) {
    piVar4 = (int *)FUN_10010690((int)local_14);
    local_18 = (void *)*piVar4;
    pcVar2 = (char *)FUN_10010610((int)local_18);
    if (*pcVar2 == '\0') {
      puVar7 = (undefined1 *)FUN_10010610((int)local_18);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_10010610((int)local_14);
      *puVar7 = 0;
      FUN_10010830(this,(int)local_14);
      piVar4 = (int *)FUN_10010690((int)local_14);
      local_18 = (void *)*piVar4;
    }
    pcVar2 = (char *)FUN_10010630((int)local_18);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_10010650(local_18);
      pcVar2 = (char *)FUN_10010610(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_10010690((int)local_18);
        pcVar2 = (char *)FUN_10010610(*piVar4);
        if (*pcVar2 == '\x01') {
          puVar7 = (undefined1 *)FUN_10010610((int)local_18);
          *puVar7 = 0;
          goto LAB_10010155;
        }
      }
      piVar4 = (int *)FUN_10010690((int)local_18);
      pcVar2 = (char *)FUN_10010610(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_10010650(local_18);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10010610((int)local_18);
        *puVar7 = 0;
        FUN_100109a0(this,(int)local_18);
        piVar4 = (int *)FUN_10010690((int)local_14);
        local_18 = (void *)*piVar4;
      }
      puVar7 = (undefined1 *)FUN_10010610((int)local_14);
      puVar8 = (undefined1 *)FUN_10010610((int)local_18);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_10010610((int)local_14);
      *puVar7 = 1;
      piVar4 = (int *)FUN_10010690((int)local_18);
      puVar7 = (undefined1 *)FUN_10010610(*piVar4);
      *puVar7 = 1;
      FUN_10010830(this,(int)local_14);
LAB_100104d3:
      puVar7 = (undefined1 *)FUN_10010610((int)local_10);
      *puVar7 = 1;
      goto LAB_100104e2;
    }
  }
  else {
    piVar4 = (int *)FUN_10010650(local_14);
    local_18 = (void *)*piVar4;
    pcVar2 = (char *)FUN_10010610((int)local_18);
    if (*pcVar2 == '\0') {
      puVar7 = (undefined1 *)FUN_10010610((int)local_18);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_10010610((int)local_14);
      *puVar7 = 0;
      FUN_100109a0(this,(int)local_14);
      piVar4 = (int *)FUN_10010650(local_14);
      local_18 = (void *)*piVar4;
    }
    pcVar2 = (char *)FUN_10010630((int)local_18);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_10010690((int)local_18);
      pcVar2 = (char *)FUN_10010610(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_10010650(local_18);
        pcVar2 = (char *)FUN_10010610(*piVar4);
        if (*pcVar2 == '\x01') {
          puVar7 = (undefined1 *)FUN_10010610((int)local_18);
          *puVar7 = 0;
          goto LAB_10010155;
        }
      }
      piVar4 = (int *)FUN_10010650(local_18);
      pcVar2 = (char *)FUN_10010610(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_10010690((int)local_18);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10010610((int)local_18);
        *puVar7 = 0;
        FUN_10010830(this,(int)local_18);
        piVar4 = (int *)FUN_10010650(local_14);
        local_18 = (void *)*piVar4;
      }
      puVar7 = (undefined1 *)FUN_10010610((int)local_14);
      puVar8 = (undefined1 *)FUN_10010610((int)local_18);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_10010610((int)local_14);
      *puVar7 = 1;
      piVar4 = (int *)FUN_10010650(local_18);
      puVar7 = (undefined1 *)FUN_10010610(*piVar4);
      *puVar7 = 1;
      FUN_100109a0(this,(int)local_14);
      goto LAB_100104d3;
    }
  }
LAB_10010155:
  local_10 = local_14;
  puVar5 = (undefined4 *)FUN_10010670((int)local_14);
  local_14 = (void *)*puVar5;
  goto LAB_10010166;
}



// Function: FUN_10010550 at 10010550

void __fastcall FUN_10010550(void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_100105e0((int)param_1);
  FUN_10010790(param_1,(void *)*puVar1);
  puVar1 = (undefined4 *)FUN_100105e0((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_100105b0((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_10010970((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_100105b0 at 100105b0

void __fastcall FUN_100105b0(int param_1)

{
  FUN_10010650(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_100105e0 at 100105e0

void __fastcall FUN_100105e0(int param_1)

{
  FUN_10010670(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_10010610 at 10010610

int __cdecl FUN_10010610(int param_1)

{
  return param_1 + 0x14;
}



// Function: FUN_10010630 at 10010630

int __cdecl FUN_10010630(int param_1)

{
  return param_1 + 0x15;
}



// Function: FUN_10010650 at 10010650

undefined4 __cdecl FUN_10010650(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10010670 at 10010670

int __cdecl FUN_10010670(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_10010690 at 10010690

int __cdecl FUN_10010690(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_100106b0 at 100106b0

int __fastcall FUN_100106b0(int param_1)

{
  FUN_10010b80(param_1);
  FUN_100112e0(param_1 + 0xc);
  FUN_1000f8c0(param_1 + 0xd);
  return param_1;
}



// Function: FUN_10010700 at 10010700

void FUN_10010700(uint param_1)

{
  FUN_10011300(param_1);
  return;
}



// Function: FUN_10010730 at 10010730

int * __thiscall FUN_10010730(void *this,int *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  FUN_10010ba0((int *)this);
  *param_1 = iVar1;
  return param_1;
}



// Function: FUN_10010760 at 10010760

undefined4 * __thiscall FUN_10010760(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_10014df0();
  return (undefined4 *)this;
}



// Function: FUN_10010790 at 10010790

void __thiscall FUN_10010790(void *this,void *param_1)

{
  void *pvVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_c;
  
  local_c = param_1;
  while( true ) {
    pcVar2 = (char *)FUN_10010630((int)local_c);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_10010690((int)local_c);
    FUN_10010790(this,(void *)*puVar3);
    puVar3 = (undefined4 *)FUN_10010650(local_c);
    pvVar1 = (void *)*puVar3;
    iVar4 = FUN_1000f8a0((int)local_c);
    pvVar5 = (void *)FUN_100112a0(iVar4);
    FUN_100112c0((int)this + 0xd,pvVar5);
    FUN_1000f8e0(local_c);
    local_c = pvVar1;
  }
  return;
}



// Function: FUN_10010830 at 10010830

void __thiscall FUN_10010830(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_10010690(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_10010650(iVar1);
  puVar4 = (undefined4 *)FUN_10010690(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10010650(iVar1);
  pcVar5 = (char *)FUN_10010630(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_10010650(iVar1);
    piVar2 = (int *)FUN_10010670(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_10010670(param_1);
  puVar4 = (undefined4 *)FUN_10010670(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_100105e0((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_100105e0((int)this);
    *piVar2 = iVar1;
  }
  else {
    puVar3 = (undefined4 *)FUN_10010670(param_1);
    piVar2 = (int *)FUN_10010650(*puVar3);
    if (param_1 == *piVar2) {
      puVar3 = (undefined4 *)FUN_10010670(param_1);
      piVar2 = (int *)FUN_10010650(*puVar3);
      *piVar2 = iVar1;
    }
    else {
      piVar2 = (int *)FUN_10010670(param_1);
      piVar2 = (int *)FUN_10010690(*piVar2);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_10010650(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_10010670(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_10010970 at 10010970

void __fastcall FUN_10010970(int param_1)

{
  FUN_10010690(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_100109a0 at 100109a0

void __thiscall FUN_100109a0(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_10010650(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_10010690(iVar1);
  puVar4 = (undefined4 *)FUN_10010650(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10010690(iVar1);
  pcVar5 = (char *)FUN_10010630(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_10010690(iVar1);
    piVar2 = (int *)FUN_10010670(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_10010670(param_1);
  puVar4 = (undefined4 *)FUN_10010670(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_100105e0((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_100105e0((int)this);
    *piVar2 = iVar1;
  }
  else {
    piVar2 = (int *)FUN_10010670(param_1);
    piVar2 = (int *)FUN_10010690(*piVar2);
    if (param_1 == *piVar2) {
      piVar2 = (int *)FUN_10010670(param_1);
      piVar2 = (int *)FUN_10010690(*piVar2);
      *piVar2 = iVar1;
    }
    else {
      puVar3 = (undefined4 *)FUN_10010670(param_1);
      piVar2 = (int *)FUN_10010650(*puVar3);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_10010690(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_10010670(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_10010ae0 at 10010ae0

int __cdecl FUN_10010ae0(int param_1)

{
  int *piVar1;
  char *pcVar2;
  
  while( true ) {
    piVar1 = (int *)FUN_10010690(param_1);
    pcVar2 = (char *)FUN_10010630(*piVar1);
    if (*pcVar2 != '\0') break;
    piVar1 = (int *)FUN_10010690(param_1);
    param_1 = *piVar1;
  }
  return param_1;
}



// Function: FUN_10010b30 at 10010b30

undefined4 __cdecl FUN_10010b30(undefined4 param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  while( true ) {
    piVar1 = (int *)FUN_10010650(param_1);
    pcVar2 = (char *)FUN_10010630(*piVar1);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_10010650(param_1);
    param_1 = *puVar3;
  }
  return param_1;
}



// Function: FUN_10010b80 at 10010b80

undefined4 __fastcall FUN_10010b80(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10010ba0 at 10010ba0

int * __fastcall FUN_10010ba0(int *param_1)

{
  FUN_10010bc0(param_1);
  return param_1;
}



// Function: FUN_10010bc0 at 10010bc0

int * __fastcall FUN_10010bc0(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_10010630(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_10010690(*param_1);
    pcVar1 = (char *)FUN_10010630(*piVar2);
    if (*pcVar1 == '\0') {
      puVar3 = (undefined4 *)FUN_10010690(*param_1);
      iVar4 = FUN_10010b30(*puVar3);
      *param_1 = iVar4;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_10010670(*param_1);
        iVar4 = *piVar2;
        pcVar1 = (char *)FUN_10010630(iVar4);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_10010690(iVar4), *param_1 != *piVar2)) break;
        *param_1 = iVar4;
      }
      *param_1 = iVar4;
    }
  }
  return param_1;
}



// Function: FUN_10010c80 at 10010c80

void * __cdecl FUN_10010c80(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_4c;
  undefined4 local_48 [17];
  
  local_4c = param_3;
  local_48[0] = param_2;
  FUN_10011f40(param_1,local_48,&local_4c);
  return param_1;
}



// Function: FUN_10010cb0 at 10010cb0

void * __thiscall FUN_10010cb0(void *this,void *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  char cVar3;
  
  cVar3 = '\0';
  uVar1 = FUN_10013a50(param_2);
  pvVar2 = (void *)FUN_10013a70(this,uVar1);
  FUN_10011480(param_1,pvVar2,cVar3);
  return param_1;
}



// Function: FUN_10010cf0 at 10010cf0

void * __cdecl FUN_10010cf0(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_4c;
  undefined4 local_48 [17];
  
  local_4c = param_3;
  local_48[0] = param_2;
  FUN_10011f40(param_1,local_48,&local_4c);
  return param_1;
}



// Function: FUN_10010d20 at 10010d20

void * __cdecl FUN_10010d20(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_4c;
  undefined4 local_48 [17];
  
  local_4c = param_3;
  local_48[0] = param_2;
  FUN_10011f40(param_1,local_48,&local_4c);
  return param_1;
}



// Function: FUN_10010d50 at 10010d50

void * __cdecl FUN_10010d50(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_4c;
  undefined4 local_48 [17];
  
  local_4c = param_3;
  local_48[0] = param_2;
  FUN_10011f40(param_1,local_48,&local_4c);
  return param_1;
}



// Function: FUN_10010d80 at 10010d80

void * __cdecl FUN_10010d80(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_4c;
  undefined4 local_48 [17];
  
  local_4c = param_3;
  local_48[0] = param_2;
  FUN_10011f40(param_1,local_48,&local_4c);
  return param_1;
}



// Function: FUN_10010db0 at 10010db0

void * __cdecl FUN_10010db0(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_4c;
  undefined4 local_48 [17];
  
  local_4c = param_3;
  local_48[0] = param_2;
  FUN_10011f40(param_1,local_48,&local_4c);
  return param_1;
}



// Function: FUN_10010de0 at 10010de0

undefined4 * __fastcall FUN_10010de0(undefined4 *param_1)

{
  FUN_10011fd0((undefined1 *)(param_1 + 1));
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return param_1;
}



// Function: FUN_10010e20 at 10010e20

void __fastcall FUN_10010e20(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10010e40 at 10010e40

int __thiscall FUN_10010e40(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = param_1;
  FUN_10011f80((void *)((int)this + 4),*(int *)((int)this + 0xc));
  return (int)this;
}



// Function: FUN_10010e80 at 10010e80

void FUN_10010e80(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_100379b4,param_2);
  return;
}



// Function: FUN_10010eb0 at 10010eb0

void FUN_10010eb0(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_100379c4,param_2);
  return;
}



// Function: FUN_10010ee0 at 10010ee0

void __cdecl FUN_10010ee0(void *param_1,wchar_t *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e991;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10015780(local_30);
  local_8 = 1;
  iVar1 = FUN_1000a200(param_2);
  iVar2 = FUN_1000a4d0((int)param_3);
  FUN_100169d0(local_30,iVar1 + iVar2);
  FUN_100169a0(local_30,param_2);
  FUN_10015910(local_30,param_3);
  FUN_100157f0(param_1,(int)local_30);
  local_8 = local_8 & 0xffffff00;
  FUN_1000aca0(local_30);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010fa0 at 10010fa0

void * __cdecl FUN_10010fa0(void *param_1,void *param_2,wchar_t *param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002e9d9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10016a60(param_2,param_3);
  iVar2 = FUN_10016bf0(uVar1);
  FUN_100157f0(param_1,iVar2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10011020 at 10011020

undefined4 * __thiscall FUN_10011020(void *this,undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = FUN_10013b30(param_3);
  pvVar2 = (void *)FUN_10013b50(this,uVar1);
  FUN_100117a0(param_1,param_2,pvVar2);
  return param_1;
}



// Function: FUN_10011060 at 10011060

undefined4 __cdecl FUN_10011060(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10011080 at 10011080

undefined4 * __thiscall FUN_10011080(void *this,undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = FUN_10013c10(param_3);
  pvVar2 = (void *)FUN_10013c30(this,uVar1);
  FUN_10012000(param_1,param_2,pvVar2);
  return param_1;
}



// Function: FUN_100110c0 at 100110c0

undefined4 * __thiscall FUN_100110c0(void *this,undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = FUN_10013cf0(param_3);
  pvVar2 = (void *)FUN_10013d10(this,uVar1);
  FUN_10012000(param_1,param_2,pvVar2);
  return param_1;
}



// Function: FUN_10011100 at 10011100

undefined4 __cdecl FUN_10011100(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10011120 at 10011120

void __cdecl FUN_10011120(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_100168a0(param_3);
  FUN_100113f0(param_2,uVar1);
  return;
}



// Function: FUN_10011150 at 10011150

undefined4 __cdecl FUN_10011150(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10011170 at 10011170

bool __cdecl FUN_10011170(void *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_100113b0(param_1,param_2);
  return iVar1 < 0;
}



// Function: FUN_100111a0 at 100111a0

undefined4 __cdecl FUN_100111a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100111c0 at 100111c0

undefined4 __cdecl FUN_100111c0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100111e0 at 100111e0

void __thiscall FUN_100111e0(void *this,int param_1,int param_2,int param_3)

{
  FUN_10013dd0(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_10011210 at 10011210

void __cdecl FUN_10011210(void *param_1,void *param_2,undefined4 param_3)

{
  FUN_10013e20();
  FUN_10013e40(param_1,param_2,param_3);
  return;
}



// Function: FUN_10011250 at 10011250

void __cdecl FUN_10011250(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined1 local_5;
  
  puVar1 = (undefined1 *)FUN_10013e80(param_1);
  local_5 = *puVar1;
  puVar1 = (undefined1 *)FUN_10013e80(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined1 *)FUN_10013e80(&local_5);
  *param_2 = *puVar1;
  return;
}



// Function: FUN_100112a0 at 100112a0

undefined4 __cdecl FUN_100112a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100112c0 at 100112c0

void __cdecl FUN_100112c0(undefined4 param_1,void *param_2)

{
  FUN_10012610(param_2);
  return;
}



// Function: FUN_100112e0 at 100112e0

undefined4 __fastcall FUN_100112e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10011300 at 10011300

void * __cdecl FUN_10011300(uint param_1)

{
  exception local_54 [76];
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0xaaaaaaa < param_1 || (local_8 = operator_new(param_1 * 0x18), local_8 == (void *)0x0)))) {
    FUN_1000aac0(local_54);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1003d210);
  }
  return local_8;
}



// Function: FUN_10011370 at 10011370

undefined4 * __thiscall FUN_10011370(void *this,uint param_1)

{
  FUN_10010e20((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100113b0 at 100113b0

void __thiscall FUN_100113b0(void *this,undefined4 *param_1)

{
  uint uVar1;
  ushort *puVar2;
  
  uVar1 = FUN_1000a4d0((int)param_1);
  puVar2 = (ushort *)FUN_1000a600(param_1);
  FUN_10012640(this,0,*(uint *)((int)this + 0x10),puVar2,uVar1);
  return;
}



// Function: FUN_100113f0 at 100113f0

void FUN_100113f0(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ea11;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(0x1c,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = FUN_100168a0(param_2);
    FUN_100157f0(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10011480 at 10011480

/* WARNING: Removing unreachable block (ram,0x1001156b) */

void * FUN_10011480(void *param_1,void *param_2,char param_3)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_80;
  undefined1 local_74 [7];
  undefined1 local_6d;
  undefined1 local_6c [7];
  undefined1 local_65;
  undefined1 local_64 [7];
  undefined1 local_5d [65];
  int local_1c;
  char local_15;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_1000f440((int)param_2);
  piVar3 = (int *)FUN_1000fce0((int)local_8);
  local_10 = *piVar3;
  local_14 = *(int *)((int)local_8 + 4);
  local_15 = '\x01';
  while (pcVar4 = (char *)FUN_1000fd10(local_10), *pcVar4 == '\0') {
    local_14 = local_10;
    if (param_3 == '\0') {
      puVar5 = (undefined4 *)FUN_1000e990(local_10);
      pvVar6 = (void *)FUN_10011150(local_c);
      local_15 = FUN_1000e9c0(pvVar6,puVar5);
    }
    else {
      puVar5 = (undefined4 *)FUN_10011150(local_c);
      pvVar6 = (void *)FUN_1000e990(local_10);
      cVar1 = FUN_1000e9c0(pvVar6,puVar5);
      local_15 = '\x01' - (cVar1 != '\0');
    }
    if (local_15 == '\0') {
      piVar3 = (int *)FUN_1000fd70(local_10);
      local_80 = *piVar3;
    }
    else {
      piVar3 = (int *)FUN_1000fd30(local_10);
      local_80 = *piVar3;
    }
    local_10 = local_80;
  }
  FUN_1000ea60(&local_1c,local_14);
  if (local_15 != '\0') {
    piVar3 = (int *)FUN_100116d0(local_8,local_74);
    bVar2 = FUN_1000eab0(&local_1c,piVar3);
    if (bVar2) {
      local_6d = 1;
      puVar8 = &local_6d;
      pvVar6 = FUN_10012710(local_8,local_6c,'\x01',local_14,param_2);
      FUN_10012e30(param_1,pvVar6,puVar8);
      return param_1;
    }
    FUN_10012e70(&local_1c);
  }
  puVar5 = (undefined4 *)FUN_10011150(local_c);
  iVar7 = FUN_1000eae0(&local_1c);
  pvVar6 = (void *)FUN_1000e990(iVar7);
  cVar1 = FUN_1000e9c0(pvVar6,puVar5);
  if (cVar1 == '\0') {
    iVar7 = FUN_1000f440((int)param_2);
    pvVar6 = (void *)FUN_10011760(iVar7);
    FUN_10011780((int)local_8 + 0xd,pvVar6);
    FUN_10011700(param_2);
    local_5d[0] = 0;
    FUN_10013ea0(param_1,&local_1c,local_5d);
  }
  else {
    local_65 = 1;
    puVar8 = &local_65;
    pvVar6 = FUN_10012710(local_8,local_64,local_15,local_14,param_2);
    FUN_10012e30(param_1,pvVar6,puVar8);
  }
  return param_1;
}



// Function: FUN_100116d0 at 100116d0

void * __thiscall FUN_100116d0(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10011730((int)this);
  FUN_1000ea60(param_1,*puVar1);
  return param_1;
}



// Function: FUN_10011700 at 10011700

void FUN_10011700(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_10011730 at 10011730

void __fastcall FUN_10011730(int param_1)

{
  FUN_1000fd30(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_10011760 at 10011760

undefined4 __cdecl FUN_10011760(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10011780 at 10011780

void __cdecl FUN_10011780(undefined4 param_1,void *param_2)

{
  FUN_10011f10(param_2);
  return;
}



// Function: FUN_100117a0 at 100117a0

/* WARNING: Removing unreachable block (ram,0x10011801) */
/* WARNING: Removing unreachable block (ram,0x10011877) */
/* WARNING: Removing unreachable block (ram,0x100118ed) */
/* WARNING: Removing unreachable block (ram,0x1001191f) */
/* WARNING: Removing unreachable block (ram,0x1001195a) */
/* WARNING: Removing unreachable block (ram,0x100119a2) */
/* WARNING: Removing unreachable block (ram,0x1001197d) */
/* WARNING: Removing unreachable block (ram,0x100119ca) */
/* WARNING: Removing unreachable block (ram,0x100119fc) */
/* WARNING: Removing unreachable block (ram,0x10011a25) */
/* WARNING: Removing unreachable block (ram,0x10011a53) */
/* WARNING: Removing unreachable block (ram,0x10011a9b) */
/* WARNING: Removing unreachable block (ram,0x10011a76) */
/* WARNING: Removing unreachable block (ram,0x10011ac0) */
/* WARNING: Removing unreachable block (ram,0x10011893) */
/* WARNING: Removing unreachable block (ram,0x100118c3) */
/* WARNING: Removing unreachable block (ram,0x100118e8) */
/* WARNING: Removing unreachable block (ram,0x1001181d) */
/* WARNING: Removing unreachable block (ram,0x1001184b) */
/* WARNING: Removing unreachable block (ram,0x1001186e) */
/* WARNING: Removing unreachable block (ram,0x10011ac4) */

undefined4 * FUN_100117a0(undefined4 *param_1,int param_2,void *param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  char *pcVar6;
  int *this;
  undefined4 *puVar7;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [75];
  char local_11;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_1000f440((int)param_3);
  FUN_10012e90(&local_10);
  local_11 = '\0';
  iVar3 = FUN_100126f0((int)local_8);
  if (iVar3 == 0) {
    FUN_10012710(local_8,param_1,'\x01',*(int *)((int)local_8 + 4),param_3);
    return param_1;
  }
  piVar4 = (int *)FUN_100116d0(local_8,local_68);
  bVar1 = FUN_1000eab0(&param_2,piVar4);
  if (bVar1) {
    iVar3 = FUN_1000eae0(&param_2);
    puVar7 = (undefined4 *)FUN_1000e990(iVar3);
    pvVar5 = (void *)FUN_10011150(local_c);
    cVar2 = FUN_1000e9c0(pvVar5,puVar7);
    if (cVar2 != '\0') {
      pvVar5 = param_3;
      iVar3 = FUN_1000eae0(&param_2);
      FUN_10012710(local_8,param_1,'\x01',iVar3,pvVar5);
      return param_1;
    }
  }
  else {
    piVar4 = (int *)FUN_1000da40(local_8,local_64);
    bVar1 = FUN_1000eab0(&param_2,piVar4);
    if (bVar1) {
      puVar7 = (undefined4 *)FUN_10011150(local_c);
      piVar4 = (int *)FUN_10011db0((int)local_8);
      pvVar5 = (void *)FUN_1000e990(*piVar4);
      cVar2 = FUN_1000e9c0(pvVar5,puVar7);
      if (cVar2 != '\0') {
        pvVar5 = param_3;
        piVar4 = (int *)FUN_10011db0((int)local_8);
        FUN_10012710(local_8,param_1,'\0',*piVar4,pvVar5);
        return param_1;
      }
    }
    else {
      iVar3 = FUN_1000eae0(&param_2);
      puVar7 = (undefined4 *)FUN_1000e990(iVar3);
      pvVar5 = (void *)FUN_10011150(local_c);
      cVar2 = FUN_1000e9c0(pvVar5,puVar7);
      if (cVar2 != '\0') {
        local_10 = param_2;
        puVar7 = (undefined4 *)FUN_10011150(local_c);
        piVar4 = FUN_10012eb0(&local_10);
        iVar3 = FUN_1000eae0(piVar4);
        pvVar5 = (void *)FUN_1000e990(iVar3);
        cVar2 = FUN_1000e9c0(pvVar5,puVar7);
        if (cVar2 != '\0') {
          iVar3 = FUN_1000eae0(&local_10);
          piVar4 = (int *)FUN_1000fd70(iVar3);
          pcVar6 = (char *)FUN_1000fd10(*piVar4);
          if (*pcVar6 != '\0') {
            pvVar5 = param_3;
            iVar3 = FUN_1000eae0(&local_10);
            FUN_10012710(local_8,param_1,'\0',iVar3,pvVar5);
            return param_1;
          }
          pvVar5 = param_3;
          iVar3 = FUN_1000eae0(&param_2);
          FUN_10012710(local_8,param_1,'\x01',iVar3,pvVar5);
          return param_1;
        }
      }
      puVar7 = (undefined4 *)FUN_10011150(local_c);
      iVar3 = FUN_1000eae0(&param_2);
      pvVar5 = (void *)FUN_1000e990(iVar3);
      cVar2 = FUN_1000e9c0(pvVar5,puVar7);
      if (cVar2 != '\0') {
        local_10 = param_2;
        piVar4 = (int *)FUN_1000da40(local_8,local_60);
        this = FUN_10011de0(&local_10);
        bVar1 = FUN_1000eab0(this,piVar4);
        if (!bVar1) {
          iVar3 = FUN_1000eae0(&local_10);
          puVar7 = (undefined4 *)FUN_1000e990(iVar3);
          pvVar5 = (void *)FUN_10011150(local_c);
          cVar2 = FUN_1000e9c0(pvVar5,puVar7);
          if (cVar2 == '\0') goto LAB_10011d7c;
        }
        iVar3 = FUN_1000eae0(&param_2);
        piVar4 = (int *)FUN_1000fd70(iVar3);
        pcVar6 = (char *)FUN_1000fd10(*piVar4);
        if (*pcVar6 != '\0') {
          pvVar5 = param_3;
          iVar3 = FUN_1000eae0(&param_2);
          FUN_10012710(local_8,param_1,'\0',iVar3,pvVar5);
          return param_1;
        }
        pvVar5 = param_3;
        iVar3 = FUN_1000eae0(&local_10);
        FUN_10012710(local_8,param_1,'\x01',iVar3,pvVar5);
        return param_1;
      }
    }
  }
LAB_10011d7c:
  puVar7 = (undefined4 *)FUN_10011480(local_5c,param_3,local_11);
  *param_1 = *puVar7;
  return param_1;
}



// Function: FUN_10011db0 at 10011db0

void __fastcall FUN_10011db0(int param_1)

{
  FUN_1000fd70(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_10011de0 at 10011de0

int * __fastcall FUN_10011de0(int *param_1)

{
  FUN_10011e00(param_1);
  return param_1;
}



// Function: FUN_10011e00 at 10011e00

int * __fastcall FUN_10011e00(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_1000fd10(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_1000fd70(*param_1);
    pcVar1 = (char *)FUN_1000fd10(*piVar2);
    if (*pcVar1 == '\0') {
      puVar3 = (undefined4 *)FUN_1000fd70(*param_1);
      iVar4 = FUN_10011ec0(*puVar3);
      *param_1 = iVar4;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_1000fd50(*param_1);
        iVar4 = *piVar2;
        pcVar1 = (char *)FUN_1000fd10(iVar4);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_1000fd70(iVar4), *param_1 != *piVar2)) break;
        *param_1 = iVar4;
      }
      *param_1 = iVar4;
    }
  }
  return param_1;
}



// Function: FUN_10011ec0 at 10011ec0

undefined4 __cdecl FUN_10011ec0(undefined4 param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  while( true ) {
    piVar1 = (int *)FUN_1000fd30(param_1);
    pcVar2 = (char *)FUN_1000fd10(*piVar1);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_1000fd30(param_1);
    param_1 = *puVar3;
  }
  return param_1;
}



// Function: FUN_10011f10 at 10011f10

void FUN_10011f10(void *param_1)

{
  FUN_10013ee0(param_1);
  return;
}



// Function: FUN_10011f40 at 10011f40

void * __thiscall FUN_10011f40(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_10013f00(param_2);
  uVar2 = FUN_10013f00(param_1);
  FUN_10012df0(this,uVar2,uVar1);
  return this;
}



// Function: FUN_10011f80 at 10011f80

void __thiscall FUN_10011f80(void *this,int param_1)

{
  bool bVar1;
  
                    /* WARNING: Load size is inaccurate */
  if (*this == '\0') {
    bVar1 = FUN_10012ed0(param_1);
    if (!bVar1) {
      *(undefined1 *)this = 1;
      FUN_10012ef0(param_1,*(undefined4 *)((int)this + 4));
    }
  }
  return;
}



// Function: FUN_10011fd0 at 10011fd0

undefined1 * __fastcall FUN_10011fd0(undefined1 *param_1)

{
  *param_1 = 0;
  FUN_10014f50((undefined4 *)(param_1 + 4));
  return param_1;
}



// Function: FUN_10012000 at 10012000

/* WARNING: Removing unreachable block (ram,0x10012061) */
/* WARNING: Removing unreachable block (ram,0x100120d7) */
/* WARNING: Removing unreachable block (ram,0x1001214d) */
/* WARNING: Removing unreachable block (ram,0x1001217f) */
/* WARNING: Removing unreachable block (ram,0x100121ba) */
/* WARNING: Removing unreachable block (ram,0x10012202) */
/* WARNING: Removing unreachable block (ram,0x100121dd) */
/* WARNING: Removing unreachable block (ram,0x1001222a) */
/* WARNING: Removing unreachable block (ram,0x1001225c) */
/* WARNING: Removing unreachable block (ram,0x10012285) */
/* WARNING: Removing unreachable block (ram,0x100122b3) */
/* WARNING: Removing unreachable block (ram,0x100122fb) */
/* WARNING: Removing unreachable block (ram,0x100122d6) */
/* WARNING: Removing unreachable block (ram,0x10012320) */
/* WARNING: Removing unreachable block (ram,0x100120f3) */
/* WARNING: Removing unreachable block (ram,0x10012123) */
/* WARNING: Removing unreachable block (ram,0x10012148) */
/* WARNING: Removing unreachable block (ram,0x1001207d) */
/* WARNING: Removing unreachable block (ram,0x100120ab) */
/* WARNING: Removing unreachable block (ram,0x100120ce) */
/* WARNING: Removing unreachable block (ram,0x10012324) */

undefined4 * FUN_10012000(undefined4 *param_1,int param_2,void *param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 *puVar6;
  void *pvVar7;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [75];
  char local_11;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_1000f8a0((int)param_3);
  FUN_1000ed40(&local_10);
  local_11 = '\0';
  iVar2 = FUN_10012f90((int)local_8);
  if (iVar2 == 0) {
    FUN_10013200(local_8,param_1,'\x01',*(int *)((int)local_8 + 4),param_3);
    return param_1;
  }
  piVar3 = (int *)FUN_1000f5b0(local_8,local_68);
  bVar1 = FUN_1000ed60(&param_2,piVar3);
  if (bVar1) {
    iVar2 = FUN_1000ed90(&param_2);
    piVar3 = (int *)FUN_1000ec70(iVar2);
    piVar4 = (int *)FUN_100111c0(local_c);
    bVar1 = FUN_1000ecc0(piVar4,piVar3);
    if (bVar1) {
      pvVar7 = param_3;
      iVar2 = FUN_1000ed90(&param_2);
      FUN_10013200(local_8,param_1,'\x01',iVar2,pvVar7);
      return param_1;
    }
  }
  else {
    piVar3 = (int *)FUN_1000e030(local_8,local_64);
    bVar1 = FUN_1000ed60(&param_2,piVar3);
    if (bVar1) {
      piVar3 = (int *)FUN_100111c0(local_c);
      piVar4 = (int *)FUN_10010970((int)local_8);
      piVar4 = (int *)FUN_1000ec70(*piVar4);
      bVar1 = FUN_1000ecc0(piVar4,piVar3);
      if (bVar1) {
        pvVar7 = param_3;
        piVar3 = (int *)FUN_10010970((int)local_8);
        FUN_10013200(local_8,param_1,'\0',*piVar3,pvVar7);
        return param_1;
      }
    }
    else {
      iVar2 = FUN_1000ed90(&param_2);
      piVar3 = (int *)FUN_1000ec70(iVar2);
      piVar4 = (int *)FUN_100111c0(local_c);
      bVar1 = FUN_1000ecc0(piVar4,piVar3);
      if (bVar1) {
        local_10 = param_2;
        piVar3 = (int *)FUN_100111c0(local_c);
        piVar4 = FUN_10013640(&local_10);
        iVar2 = FUN_1000ed90(piVar4);
        piVar4 = (int *)FUN_1000ec70(iVar2);
        bVar1 = FUN_1000ecc0(piVar4,piVar3);
        if (bVar1) {
          iVar2 = FUN_1000ed90(&local_10);
          piVar3 = (int *)FUN_10010690(iVar2);
          pcVar5 = (char *)FUN_10010630(*piVar3);
          if (*pcVar5 != '\0') {
            pvVar7 = param_3;
            iVar2 = FUN_1000ed90(&local_10);
            FUN_10013200(local_8,param_1,'\0',iVar2,pvVar7);
            return param_1;
          }
          pvVar7 = param_3;
          iVar2 = FUN_1000ed90(&param_2);
          FUN_10013200(local_8,param_1,'\x01',iVar2,pvVar7);
          return param_1;
        }
      }
      piVar3 = (int *)FUN_100111c0(local_c);
      iVar2 = FUN_1000ed90(&param_2);
      piVar4 = (int *)FUN_1000ec70(iVar2);
      bVar1 = FUN_1000ecc0(piVar4,piVar3);
      if (bVar1) {
        local_10 = param_2;
        piVar3 = (int *)FUN_1000e030(local_8,local_60);
        piVar4 = FUN_10010ba0(&local_10);
        bVar1 = FUN_1000ed60(piVar4,piVar3);
        if (!bVar1) {
          iVar2 = FUN_1000ed90(&local_10);
          piVar3 = (int *)FUN_1000ec70(iVar2);
          piVar4 = (int *)FUN_100111c0(local_c);
          bVar1 = FUN_1000ecc0(piVar4,piVar3);
          if (!bVar1) goto LAB_100125dc;
        }
        iVar2 = FUN_1000ed90(&param_2);
        piVar3 = (int *)FUN_10010690(iVar2);
        pcVar5 = (char *)FUN_10010630(*piVar3);
        if (*pcVar5 != '\0') {
          pvVar7 = param_3;
          iVar2 = FUN_1000ed90(&param_2);
          FUN_10013200(local_8,param_1,'\0',iVar2,pvVar7);
          return param_1;
        }
        pvVar7 = param_3;
        iVar2 = FUN_1000ed90(&local_10);
        FUN_10013200(local_8,param_1,'\x01',iVar2,pvVar7);
        return param_1;
      }
    }
  }
LAB_100125dc:
  puVar6 = (undefined4 *)FUN_10012fb0(local_5c,param_3,local_11);
  *param_1 = *puVar6;
  return param_1;
}



// Function: FUN_10012610 at 10012610

void FUN_10012610(void *param_1)

{
  FUN_10013f20(param_1);
  return;
}



// Function: FUN_10012640 at 10012640

uint __thiscall FUN_10012640(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 local_54;
  undefined4 local_50;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1000a630();
  }
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  if (param_2 < param_4) {
    local_50 = param_2;
  }
  else {
    local_50 = param_4;
  }
  puVar1 = FUN_1000a600((undefined4 *)this);
  local_50 = FUN_10014d50((ushort *)((int)puVar1 + param_1 * 2),param_3,local_50);
  if (local_50 == 0) {
    if (param_2 < param_4) {
      local_54 = 0xffffffff;
    }
    else {
      local_54 = (uint)(param_2 != param_4);
    }
    local_50 = local_54;
  }
  return local_50;
}



// Function: FUN_100126f0 at 100126f0

undefined4 __fastcall FUN_100126f0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10012710 at 10012710

void * __thiscall FUN_10012710(void *this,void *param_1,char param_2,int param_3,void *param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *puVar7;
  void *local_c;
  
  iVar1 = FUN_10013660();
  if (iVar1 - 1U <= *(uint *)((int)this + 8)) {
    iVar1 = FUN_1000f440((int)param_4);
    pvVar2 = (void *)FUN_10011760(iVar1);
    FUN_10011780((int)this + 0xd,pvVar2);
    FUN_10011700(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  *(int *)((int)param_4 + 4) = param_3;
  if (param_3 == *(int *)((int)this + 4)) {
    puVar3 = (undefined4 *)FUN_1000fce0((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_10011730((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_10011db0((int)this);
    *puVar3 = param_4;
  }
  else if (param_2 == '\0') {
    puVar3 = (undefined4 *)FUN_1000fd70(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_10011db0((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_10011db0((int)this);
      *puVar3 = param_4;
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_1000fd30(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_10011730((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_10011730((int)this);
      *puVar3 = param_4;
    }
  }
  local_c = param_4;
  while( true ) {
    piVar4 = (int *)FUN_1000fd50((int)local_c);
    pcVar5 = (char *)FUN_10012b50(*piVar4);
    if (*pcVar5 != '\0') break;
    piVar4 = (int *)FUN_1000fd50((int)local_c);
    piVar6 = (int *)FUN_1000fd50((int)local_c);
    puVar3 = (undefined4 *)FUN_1000fd50(*piVar6);
    piVar6 = (int *)FUN_1000fd30(*puVar3);
    if (*piVar4 == *piVar6) {
      piVar4 = (int *)FUN_1000fd50((int)local_c);
      piVar4 = (int *)FUN_1000fd50(*piVar4);
      piVar4 = (int *)FUN_1000fd70(*piVar4);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_10012b50(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10012b50(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd50(*piVar4);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        puVar3 = (undefined4 *)FUN_1000fd50(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd70(*piVar4);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_1000fd50((int)local_c);
          local_c = (void *)*piVar4;
          FUN_10012b70(this,(int)local_c);
        }
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd50(*piVar4);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd50(*piVar4);
        FUN_10012cb0(this,*piVar4);
      }
    }
    else {
      piVar4 = (int *)FUN_1000fd50((int)local_c);
      puVar3 = (undefined4 *)FUN_1000fd50(*piVar4);
      piVar4 = (int *)FUN_1000fd30(*puVar3);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_10012b50(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10012b50(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd50(*piVar4);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        puVar3 = (undefined4 *)FUN_1000fd50(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd30(*puVar3);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_1000fd50((int)local_c);
          local_c = (void *)*piVar4;
          FUN_10012cb0(this,(int)local_c);
        }
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd50(*piVar4);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1000fd50((int)local_c);
        piVar4 = (int *)FUN_1000fd50(*piVar4);
        FUN_10012b70(this,*piVar4);
      }
    }
  }
  piVar4 = (int *)FUN_1000fce0((int)this);
  puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
  *puVar7 = 1;
  FUN_1000ea60(param_1,param_4);
  return param_1;
}



// Function: FUN_10012b50 at 10012b50

int __cdecl FUN_10012b50(int param_1)

{
  return param_1 + 0x2c;
}



// Function: FUN_10012b70 at 10012b70

void __thiscall FUN_10012b70(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_1000fd70(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_1000fd30(iVar1);
  puVar4 = (undefined4 *)FUN_1000fd70(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1000fd30(iVar1);
  pcVar5 = (char *)FUN_1000fd10(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_1000fd30(iVar1);
    piVar2 = (int *)FUN_1000fd50(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_1000fd50(param_1);
  puVar4 = (undefined4 *)FUN_1000fd50(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1000fce0((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_1000fce0((int)this);
    *piVar2 = iVar1;
  }
  else {
    puVar3 = (undefined4 *)FUN_1000fd50(param_1);
    piVar2 = (int *)FUN_1000fd30(*puVar3);
    if (param_1 == *piVar2) {
      puVar3 = (undefined4 *)FUN_1000fd50(param_1);
      piVar2 = (int *)FUN_1000fd30(*puVar3);
      *piVar2 = iVar1;
    }
    else {
      piVar2 = (int *)FUN_1000fd50(param_1);
      piVar2 = (int *)FUN_1000fd70(*piVar2);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_1000fd30(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_1000fd50(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_10012cb0 at 10012cb0

void __thiscall FUN_10012cb0(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_1000fd30(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_1000fd70(iVar1);
  puVar4 = (undefined4 *)FUN_1000fd30(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1000fd70(iVar1);
  pcVar5 = (char *)FUN_1000fd10(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_1000fd70(iVar1);
    piVar2 = (int *)FUN_1000fd50(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_1000fd50(param_1);
  puVar4 = (undefined4 *)FUN_1000fd50(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1000fce0((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_1000fce0((int)this);
    *piVar2 = iVar1;
  }
  else {
    piVar2 = (int *)FUN_1000fd50(param_1);
    piVar2 = (int *)FUN_1000fd70(*piVar2);
    if (param_1 == *piVar2) {
      piVar2 = (int *)FUN_1000fd50(param_1);
      piVar2 = (int *)FUN_1000fd70(*piVar2);
      *piVar2 = iVar1;
    }
    else {
      puVar3 = (undefined4 *)FUN_1000fd50(param_1);
      piVar2 = (int *)FUN_1000fd30(*puVar3);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_1000fd70(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_1000fd50(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_10012df0 at 10012df0

undefined4 * __thiscall FUN_10012df0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10013f00(param_1);
  *(undefined4 *)this = *puVar1;
  puVar1 = (undefined4 *)FUN_10013f00(param_2);
  *(undefined4 *)((int)this + 4) = *puVar1;
  return (undefined4 *)this;
}



// Function: FUN_10012e30 at 10012e30

void * __thiscall FUN_10012e30(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_10013f60(param_2);
  uVar2 = FUN_10013f40(param_1);
  FUN_10013680(this,uVar2,uVar1);
  return this;
}



// Function: FUN_10012e70 at 10012e70

int * __fastcall FUN_10012e70(int *param_1)

{
  FUN_10012eb0(param_1);
  return param_1;
}



// Function: FUN_10012e90 at 10012e90

undefined4 * __fastcall FUN_10012e90(undefined4 *param_1)

{
  FUN_100136c0(param_1);
  return param_1;
}



// Function: FUN_10012eb0 at 10012eb0

int * __fastcall FUN_10012eb0(int *param_1)

{
  FUN_100136e0(param_1);
  return param_1;
}



// Function: FUN_10012ed0 at 10012ed0

bool __cdecl FUN_10012ed0(int param_1)

{
  return -1 < param_1;
}



// Function: FUN_10012ef0 at 10012ef0

void FUN_10012ef0(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_b4 [112];
  undefined1 local_44 [48];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ea38;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10014e10(local_44,param_1,0,param_2,L"",0);
  local_8 = 0;
  FUN_10016a90(local_b4,(int)local_44);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_b4,(ThrowInfo *)&DAT_1003e0fc);
}



// Function: FUN_10012f90 at 10012f90

undefined4 __fastcall FUN_10012f90(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10012fb0 at 10012fb0

/* WARNING: Removing unreachable block (ram,0x1001309b) */

void * FUN_10012fb0(void *param_1,void *param_2,char param_3)

{
  bool bVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  int local_80;
  undefined1 local_74 [7];
  undefined1 local_6d;
  undefined1 local_6c [7];
  undefined1 local_65;
  undefined1 local_64 [7];
  undefined1 local_5d [65];
  int local_1c;
  char local_15;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_1000f8a0((int)param_2);
  piVar2 = (int *)FUN_100105e0((int)local_8);
  local_10 = *piVar2;
  local_14 = *(int *)((int)local_8 + 4);
  local_15 = '\x01';
  while (pcVar3 = (char *)FUN_10010630(local_10), *pcVar3 == '\0') {
    local_14 = local_10;
    if (param_3 == '\0') {
      piVar2 = (int *)FUN_1000ec70(local_10);
      piVar4 = (int *)FUN_100111c0(local_c);
      local_15 = FUN_1000ecc0(piVar4,piVar2);
    }
    else {
      piVar2 = (int *)FUN_100111c0(local_c);
      piVar4 = (int *)FUN_1000ec70(local_10);
      bVar1 = FUN_1000ecc0(piVar4,piVar2);
      local_15 = '\x01' - bVar1;
    }
    if (local_15 == '\0') {
      piVar2 = (int *)FUN_10010690(local_10);
      local_80 = *piVar2;
    }
    else {
      piVar2 = (int *)FUN_10010650(local_10);
      local_80 = *piVar2;
    }
    local_10 = local_80;
  }
  FUN_1000ecf0(&local_1c,local_14);
  if (local_15 != '\0') {
    piVar2 = (int *)FUN_1000f5b0(local_8,local_74);
    bVar1 = FUN_1000ed60(&local_1c,piVar2);
    if (bVar1) {
      local_6d = 1;
      puVar7 = &local_6d;
      pvVar6 = FUN_10013200(local_8,local_6c,'\x01',local_14,param_2);
      FUN_10013950(param_1,pvVar6,puVar7);
      return param_1;
    }
    FUN_10013840(&local_1c);
  }
  piVar2 = (int *)FUN_100111c0(local_c);
  iVar5 = FUN_1000ed90(&local_1c);
  piVar4 = (int *)FUN_1000ec70(iVar5);
  bVar1 = FUN_1000ecc0(piVar4,piVar2);
  if (bVar1) {
    local_65 = 1;
    puVar7 = &local_65;
    pvVar6 = FUN_10013200(local_8,local_64,local_15,local_14,param_2);
    FUN_10013950(param_1,pvVar6,puVar7);
  }
  else {
    iVar5 = FUN_1000f8a0((int)param_2);
    pvVar6 = (void *)FUN_100112a0(iVar5);
    FUN_100112c0((int)local_8 + 0xd,pvVar6);
    FUN_1000f8e0(param_2);
    local_5d[0] = 0;
    FUN_10013f80(param_1,&local_1c,local_5d);
  }
  return param_1;
}



// Function: FUN_10013200 at 10013200

void * __thiscall FUN_10013200(void *this,void *param_1,char param_2,int param_3,void *param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *puVar7;
  void *local_c;
  
  iVar1 = FUN_10013820();
  if (iVar1 - 1U <= *(uint *)((int)this + 8)) {
    iVar1 = FUN_1000f8a0((int)param_4);
    pvVar2 = (void *)FUN_100112a0(iVar1);
    FUN_100112c0((int)this + 0xd,pvVar2);
    FUN_1000f8e0(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  *(int *)((int)param_4 + 4) = param_3;
  if (param_3 == *(int *)((int)this + 4)) {
    puVar3 = (undefined4 *)FUN_100105e0((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_100105b0((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_10010970((int)this);
    *puVar3 = param_4;
  }
  else if (param_2 == '\0') {
    puVar3 = (undefined4 *)FUN_10010690(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_10010970((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_10010970((int)this);
      *puVar3 = param_4;
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_10010650(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_100105b0((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_100105b0((int)this);
      *puVar3 = param_4;
    }
  }
  local_c = param_4;
  while( true ) {
    piVar4 = (int *)FUN_10010670((int)local_c);
    pcVar5 = (char *)FUN_10010610(*piVar4);
    if (*pcVar5 != '\0') break;
    piVar4 = (int *)FUN_10010670((int)local_c);
    piVar6 = (int *)FUN_10010670((int)local_c);
    puVar3 = (undefined4 *)FUN_10010670(*piVar6);
    piVar6 = (int *)FUN_10010650(*puVar3);
    if (*piVar4 == *piVar6) {
      piVar4 = (int *)FUN_10010670((int)local_c);
      piVar4 = (int *)FUN_10010670(*piVar4);
      piVar4 = (int *)FUN_10010690(*piVar4);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_10010610(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_10010670((int)local_c);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10010610(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010670(*piVar4);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10010670((int)local_c);
        puVar3 = (undefined4 *)FUN_10010670(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        piVar4 = (int *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010690(*piVar4);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_10010670((int)local_c);
          local_c = (void *)*piVar4;
          FUN_10010830(this,(int)local_c);
        }
        piVar4 = (int *)FUN_10010670((int)local_c);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010670(*piVar4);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010670(*piVar4);
        FUN_100109a0(this,*piVar4);
      }
    }
    else {
      piVar4 = (int *)FUN_10010670((int)local_c);
      puVar3 = (undefined4 *)FUN_10010670(*piVar4);
      piVar4 = (int *)FUN_10010650(*puVar3);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_10010610(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_10010670((int)local_c);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10010610(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010670(*piVar4);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10010670((int)local_c);
        puVar3 = (undefined4 *)FUN_10010670(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010650(*puVar3);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_10010670((int)local_c);
          local_c = (void *)*piVar4;
          FUN_100109a0(this,(int)local_c);
        }
        piVar4 = (int *)FUN_10010670((int)local_c);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010670(*piVar4);
        puVar7 = (undefined1 *)FUN_10010610(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10010670((int)local_c);
        piVar4 = (int *)FUN_10010670(*piVar4);
        FUN_10010830(this,*piVar4);
      }
    }
  }
  piVar4 = (int *)FUN_100105e0((int)this);
  puVar7 = (undefined1 *)FUN_10010610(*piVar4);
  *puVar7 = 1;
  FUN_1000ecf0(param_1,param_4);
  return param_1;
}



// Function: FUN_10013640 at 10013640

int * __fastcall FUN_10013640(int *param_1)

{
  FUN_10013860(param_1);
  return param_1;
}



// Function: FUN_10013660 at 10013660

void FUN_10013660(void)

{
  FUN_10013990();
  return;
}



// Function: FUN_10013680 at 10013680

undefined4 * __thiscall FUN_10013680(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_10013f40(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_10013f60(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_100136c0 at 100136c0

undefined4 * __fastcall FUN_100136c0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_100136e0 at 100136e0

int * __fastcall FUN_100136e0(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  
  pcVar1 = (char *)FUN_1000fd10(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_1000fd30(*param_1);
    pcVar1 = (char *)FUN_1000fd10(*piVar2);
    if (*pcVar1 == '\0') {
      piVar2 = (int *)FUN_1000fd30(*param_1);
      iVar3 = FUN_100137d0(*piVar2);
      *param_1 = iVar3;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_1000fd50(*param_1);
        iVar3 = *piVar2;
        pcVar1 = (char *)FUN_1000fd10(iVar3);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_1000fd30(iVar3), *param_1 != *piVar2)) break;
        *param_1 = iVar3;
      }
      pcVar1 = (char *)FUN_1000fd10(*param_1);
      if (*pcVar1 == '\0') {
        *param_1 = iVar3;
      }
    }
  }
  else {
    piVar2 = (int *)FUN_1000fd70(*param_1);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_100137d0 at 100137d0

int __cdecl FUN_100137d0(int param_1)

{
  int *piVar1;
  char *pcVar2;
  
  while( true ) {
    piVar1 = (int *)FUN_1000fd70(param_1);
    pcVar2 = (char *)FUN_1000fd10(*piVar1);
    if (*pcVar2 != '\0') break;
    piVar1 = (int *)FUN_1000fd70(param_1);
    param_1 = *piVar1;
  }
  return param_1;
}



// Function: FUN_10013820 at 10013820

void FUN_10013820(void)

{
  FUN_100139d0();
  return;
}



// Function: FUN_10013840 at 10013840

int * __fastcall FUN_10013840(int *param_1)

{
  FUN_10013640(param_1);
  return param_1;
}



// Function: FUN_10013860 at 10013860

int * __fastcall FUN_10013860(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  
  pcVar1 = (char *)FUN_10010630(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_10010650(*param_1);
    pcVar1 = (char *)FUN_10010630(*piVar2);
    if (*pcVar1 == '\0') {
      piVar2 = (int *)FUN_10010650(*param_1);
      iVar3 = FUN_10010ae0(*piVar2);
      *param_1 = iVar3;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_10010670(*param_1);
        iVar3 = *piVar2;
        pcVar1 = (char *)FUN_10010630(iVar3);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_10010650(iVar3), *param_1 != *piVar2)) break;
        *param_1 = iVar3;
      }
      pcVar1 = (char *)FUN_10010630(*param_1);
      if (*pcVar1 == '\0') {
        *param_1 = iVar3;
      }
    }
  }
  else {
    piVar2 = (int *)FUN_10010690(*param_1);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_10013950 at 10013950

void * __thiscall FUN_10013950(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_10013f60(param_2);
  uVar2 = FUN_10013fc0(param_1);
  FUN_10013a10(this,uVar2,uVar1);
  return this;
}



// Function: FUN_10013990 at 10013990

/* WARNING: Removing unreachable block (ram,0x100139b1) */

undefined4 FUN_10013990(void)

{
  return 0x7ffffff;
}



// Function: FUN_100139d0 at 100139d0

/* WARNING: Removing unreachable block (ram,0x100139f1) */

undefined4 FUN_100139d0(void)

{
  return 0x1fffffff;
}



// Function: FUN_10013a10 at 10013a10

undefined4 * __thiscall FUN_10013a10(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_10013fc0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_10013f60(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_10013a50 at 10013a50

undefined4 __cdecl FUN_10013a50(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013a70 at 10013a70

void __thiscall FUN_10013a70(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ea60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10014060((int)this);
  local_8 = 0;
  uVar2 = FUN_10013a50(param_1);
  iVar1 = FUN_1000f440(iVar1);
  uVar3 = FUN_10011760(iVar1);
  FUN_10014200((int)this + 0xd,uVar3,uVar2);
  FUN_10013b0c();
  return;
}



// Function: Catch@10013ae5 at 10013ae5

void Catch_10013ae5(void)

{
  int unaff_EBP;
  
  FUN_10011700(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10013b0c at 10013b0c

undefined4 FUN_10013b0c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10013b30 at 10013b30

undefined4 __cdecl FUN_10013b30(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013b50 at 10013b50

void __thiscall FUN_10013b50(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ea80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10014060((int)this);
  local_8 = 0;
  uVar2 = FUN_10013b30(param_1);
  iVar1 = FUN_1000f440(iVar1);
  uVar3 = FUN_10011760(iVar1);
  FUN_10014230((int)this + 0xd,uVar3,uVar2);
  FUN_10013bec();
  return;
}



// Function: Catch@10013bc5 at 10013bc5

void Catch_10013bc5(void)

{
  int unaff_EBP;
  
  FUN_10011700(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10013bec at 10013bec

undefined4 FUN_10013bec(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10013c10 at 10013c10

undefined4 __cdecl FUN_10013c10(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013c30 at 10013c30

void __thiscall FUN_10013c30(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002eaa0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10014180((int)this);
  local_8 = 0;
  uVar2 = FUN_10013c10(param_1);
  iVar1 = FUN_1000f8a0(iVar1);
  uVar3 = FUN_100112a0(iVar1);
  FUN_10014260((int)this + 0xd,uVar3,uVar2);
  FUN_10013ccc();
  return;
}



// Function: Catch@10013ca5 at 10013ca5

void Catch_10013ca5(void)

{
  int unaff_EBP;
  
  FUN_1000f8e0(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10013ccc at 10013ccc

undefined4 FUN_10013ccc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10013cf0 at 10013cf0

undefined4 __cdecl FUN_10013cf0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013d10 at 10013d10

void __thiscall FUN_10013d10(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002eac0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10014180((int)this);
  local_8 = 0;
  uVar2 = FUN_10013cf0(param_1);
  iVar1 = FUN_1000f8a0(iVar1);
  uVar3 = FUN_100112a0(iVar1);
  FUN_10014290((int)this + 0xd,uVar3,uVar2);
  FUN_10013dac();
  return;
}



// Function: Catch@10013d85 at 10013d85

void Catch_10013d85(void)

{
  int unaff_EBP;
  
  FUN_1000f8e0(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10013dac at 10013dac

undefined4 FUN_10013dac(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10013dd0 at 10013dd0

void __cdecl FUN_10013dd0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_10013e20();
  FUN_100142c0();
  FUN_100142e0(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10013e20 at 10013e20

undefined1 FUN_10013e20(void)

{
  undefined1 local_5;
  
  return local_5;
}



// Function: FUN_10013e40 at 10013e40

void __cdecl FUN_10013e40(void *param_1,void *param_2,undefined4 param_3)

{
  for (; param_1 != param_2; param_1 = (void *)((int)param_1 + 0x1c)) {
    FUN_10016910(param_3,param_1);
  }
  return;
}



// Function: FUN_10013e80 at 10013e80

undefined4 __cdecl FUN_10013e80(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013ea0 at 10013ea0

void * __thiscall FUN_10013ea0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_100143d0(param_2);
  uVar2 = FUN_100143b0(param_1);
  FUN_100143f0(this,uVar2,uVar1);
  return this;
}



// Function: FUN_10013ee0 at 10013ee0

void __cdecl FUN_10013ee0(void *param_1)

{
  FUN_10013fe0(param_1,0);
  return;
}



// Function: FUN_10013f00 at 10013f00

undefined4 __cdecl FUN_10013f00(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013f20 at 10013f20

void __cdecl FUN_10013f20(void *param_1)

{
  FUN_10014020(param_1,0);
  return;
}



// Function: FUN_10013f40 at 10013f40

undefined4 __cdecl FUN_10013f40(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013f60 at 10013f60

undefined4 __cdecl FUN_10013f60(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013f80 at 10013f80

void * __thiscall FUN_10013f80(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_100143d0(param_2);
  uVar2 = FUN_10014430(param_1);
  FUN_100145a0(this,uVar2,uVar1);
  return this;
}



// Function: FUN_10013fc0 at 10013fc0

undefined4 __cdecl FUN_10013fc0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10013fe0 at 10013fe0

void * __thiscall FUN_10013fe0(void *this,uint param_1)

{
  FUN_1000e700(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10014020 at 10014020

void * __thiscall FUN_10014020(void *this,uint param_1)

{
  FUN_1000e7c0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10014060 at 10014060

int __fastcall FUN_10014060(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_100140e0(1);
  puVar2 = (undefined4 *)FUN_1000fd30(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1000fd50(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1000fd70(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined1 *)FUN_10012b50(iVar1);
  *puVar3 = 0;
  puVar3 = (undefined1 *)FUN_1000fd10(iVar1);
  *puVar3 = 0;
  return iVar1;
}



// Function: FUN_100140e0 at 100140e0

void FUN_100140e0(uint param_1)

{
  FUN_10014110(param_1);
  return;
}



// Function: FUN_10014110 at 10014110

void * __cdecl FUN_10014110(uint param_1)

{
  exception local_54 [76];
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x5555555 < param_1 || (local_8 = operator_new(param_1 * 0x30), local_8 == (void *)0x0)))) {
    FUN_1000aac0(local_54);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1003d210);
  }
  return local_8;
}



// Function: FUN_10014180 at 10014180

int __fastcall FUN_10014180(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_10010700(1);
  puVar2 = (undefined4 *)FUN_10010650(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_10010670(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_10010690(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined1 *)FUN_10010610(iVar1);
  *puVar3 = 0;
  puVar3 = (undefined1 *)FUN_10010630(iVar1);
  *puVar3 = 0;
  return iVar1;
}



// Function: FUN_10014200 at 10014200

void __cdecl FUN_10014200(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10013a50(param_3);
  FUN_10014700(param_2,uVar1);
  return;
}



// Function: FUN_10014230 at 10014230

void __cdecl FUN_10014230(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10013b30(param_3);
  FUN_100145e0(param_2,uVar1);
  return;
}



// Function: FUN_10014260 at 10014260

void __cdecl FUN_10014260(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10013c10(param_3);
  FUN_10014790(param_2,uVar1);
  return;
}



// Function: FUN_10014290 at 10014290

void __cdecl FUN_10014290(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10013cf0(param_3);
  FUN_10014670(param_2,uVar1);
  return;
}



// Function: FUN_100142c0 at 100142c0

undefined4 FUN_100142c0(void)

{
  return 0;
}



// Function: FUN_100142e0 at 100142e0

void FUN_100142e0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002eae0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    FUN_10011120(param_4,param_3,param_1);
    param_3 = param_3 + 0x1c;
  }
  FUN_10014388();
  return;
}



// Function: FUN_1001434f at 1001434f

void FUN_1001434f(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x1c;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_10016910(*(undefined4 *)(unaff_EBP + 0x14),*(void **)(unaff_EBP + -0x14));
    FUN_1001434f();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10014358 at 10014358

void FUN_10014358(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    FUN_10016910(*(undefined4 *)(unaff_EBP + 0x14),*(void **)(unaff_EBP + -0x14));
    FUN_1001434f();
    return;
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10014388 at 10014388

undefined4 FUN_10014388(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 0x10);
}



// Function: FUN_100143b0 at 100143b0

undefined4 __cdecl FUN_100143b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100143d0 at 100143d0

undefined4 __cdecl FUN_100143d0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100143f0 at 100143f0

undefined4 * __thiscall FUN_100143f0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_100143b0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_100143d0(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_10014430 at 10014430

undefined4 __cdecl FUN_10014430(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014450 at 10014450

LSTATUS __thiscall FUN_10014450(void *this,LPBYTE param_1,LPCWSTR param_2,LPDWORD param_3)

{
  LSTATUS LVar1;
  DWORD local_10;
  uint local_c;
  undefined4 *local_8;
  
  local_c = (uint)(param_3 != (LPDWORD)0x0);
  local_8 = (undefined4 *)this;
  if (local_c == 0) {
    FUN_10003210(0x80004005);
  }
  local_10 = 0;
  LVar1 = RegQueryValueExW((HKEY)*local_8,param_2,(LPDWORD)0x0,&local_10,param_1,param_3);
  if (param_1 != (LPBYTE)0x0) {
    if (*param_3 == 0) {
      param_1[0] = '\0';
      param_1[1] = '\0';
    }
    else {
      if (local_10 != 0) {
        if (local_10 < 3) {
          if ((*param_3 % 2 == 0) && (*(short *)(param_1 + ((*param_3 & 0xfffffffe) - 2)) == 0)) {
            return LVar1;
          }
          param_1[0] = '\0';
          param_1[1] = '\0';
          return 0xd;
        }
        if (local_10 == 7) {
          if (((*param_3 % 2 == 0) && (*param_3 >> 1 != 0)) &&
             (*(short *)(param_1 + ((*param_3 & 0xfffffffe) - 2)) == 0)) {
            if (*param_3 >> 1 < 2) {
              return LVar1;
            }
            if (*(short *)(param_1 + ((*param_3 & 0xfffffffe) - 4)) == 0) {
              return LVar1;
            }
          }
          param_1[0] = '\0';
          param_1[1] = '\0';
          return 0xd;
        }
      }
      param_1[0] = '\0';
      param_1[1] = '\0';
      LVar1 = 0xd;
    }
  }
  return LVar1;
}



// Function: FUN_100145a0 at 100145a0

undefined4 * __thiscall FUN_100145a0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_10014430(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_100143d0(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_100145e0 at 100145e0

void FUN_100145e0(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002eb11;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(0x20,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = FUN_10013b30(param_2);
    FUN_10014820(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014670 at 10014670

void FUN_10014670(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002eb41;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(8,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = FUN_10013cf0(param_2);
    FUN_100148a0(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014700 at 10014700

void FUN_10014700(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002eb71;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(0x20,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = FUN_10013a50(param_2);
    FUN_10014a30(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014790 at 10014790

void FUN_10014790(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002eba1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(8,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = FUN_10013c10(param_2);
    FUN_10014ab0(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014820 at 10014820

void * __thiscall FUN_10014820(void *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ebc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10014b50(param_1 + 0x1c);
  uVar2 = FUN_10014b30(param_1);
  FUN_10014920(this,uVar2,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100148a0 at 100148a0

void * __thiscall FUN_100148a0(void *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ebf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10014b50(param_1 + 4);
  uVar2 = FUN_10014b70(param_1);
  FUN_100149b0(this,uVar2,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10014920 at 10014920

void * __thiscall FUN_10014920(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ec33;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10014b90(param_1);
  FUN_100156f0(this,puVar1);
  local_8 = 0;
  puVar1 = (undefined4 *)FUN_100111a0(param_2);
  FUN_1000f520((void *)((int)this + 0x1c),puVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100149b0 at 100149b0

undefined4 * __thiscall FUN_100149b0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ec5b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10014bb0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar1 = (undefined4 *)FUN_100111a0(param_2);
  FUN_1000f520((void *)((int)this + 4),puVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014a30 at 10014a30

void * __thiscall FUN_10014a30(void *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ec88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10014bd0(param_1 + 4);
  uVar2 = FUN_10014bd0(param_1);
  FUN_10014bf0(this,uVar2,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10014ab0 at 10014ab0

void * __thiscall FUN_10014ab0(void *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ecb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10014b50(param_1 + 4);
  uVar2 = FUN_10014c80(param_1);
  FUN_10014ca0(this,uVar2,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10014b30 at 10014b30

undefined4 __cdecl FUN_10014b30(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014b50 at 10014b50

undefined4 __cdecl FUN_10014b50(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014b70 at 10014b70

undefined4 __cdecl FUN_10014b70(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014b90 at 10014b90

undefined4 __cdecl FUN_10014b90(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014bb0 at 10014bb0

undefined4 __cdecl FUN_10014bb0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014bd0 at 10014bd0

undefined4 __cdecl FUN_10014bd0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014bf0 at 10014bf0

void * __thiscall FUN_10014bf0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ecf3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10014bd0(param_1);
  FUN_1000a150(this,(wchar_t *)*puVar1);
  local_8 = 0;
  piVar2 = (int *)FUN_10014bd0(param_2);
  FUN_1000ac40((void *)((int)this + 0x1c),*piVar2);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10014c80 at 10014c80

undefined4 __cdecl FUN_10014c80(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10014ca0 at 10014ca0

undefined4 * __thiscall FUN_10014ca0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ed1b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10014c80(param_1);
  *(undefined4 *)this = *puVar1;
  puVar1 = (undefined4 *)FUN_10014b50(param_2);
  FUN_1000f520((void *)((int)this + 4),puVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014d20 at 10014d20

undefined4 __cdecl FUN_10014d20(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_10014d40 at 10014d40

void FUN_10014d40(void)

{
  return;
}



// Function: FUN_10014d50 at 10014d50

void __cdecl FUN_10014d50(ushort *param_1,ushort *param_2,int param_3)

{
  FUN_10014d80(param_1,param_2,param_3);
  return;
}



// Function: FUN_10014d80 at 10014d80

int __cdecl FUN_10014d80(ushort *param_1,ushort *param_2,int param_3)

{
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    if (*param_1 != *param_2) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  }
  return (uint)(*param_2 <= *param_1) * 2 + -1;
}



// Function: FUN_10014df0 at 10014df0

void FUN_10014df0(void)

{
  return;
}



// Function: FUN_10014e10 at 10014e10

undefined4 * __thiscall
FUN_10014e10(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
            undefined4 param_5)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ed4b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  FUN_10015780((void *)((int)this + 0x10));
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  FUN_100158e0((void *)((int)this + 0x10),param_4);
  *(undefined4 *)((int)this + 0x2c) = param_5;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014eb0 at 10014eb0

void __fastcall FUN_10014eb0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002ed7b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandlerException::vftable;
  local_8 = 0xffffffff;
  FUN_1000aca0(param_1 + 4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014f10 at 10014f10

undefined4 * __thiscall FUN_10014f10(void *this,uint param_1)

{
  FUN_10014eb0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10014f50 at 10014f50

undefined4 * __fastcall FUN_10014f50(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10014f70 at 10014f70

void __cdecl FUN_10014f70(void *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined1 local_18c [28];
  undefined1 local_170 [28];
  undefined1 local_154 [28];
  undefined1 local_138 [28];
  undefined1 local_11c [28];
  undefined1 local_100 [28];
  undefined1 local_e4 [28];
  undefined1 local_c8 [28];
  undefined1 local_ac [95];
  char local_4d;
  undefined4 local_4c [7];
  undefined4 local_30 [7];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ee32;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10015630(local_30);
  local_8 = 1;
  uVar7 = 0x80000002;
  puVar6 = (undefined4 *)&DAT_10044200;
  puVar5 = (undefined4 *)&DAT_100441e4;
  puVar4 = (undefined4 *)&DAT_100441c8;
  puVar2 = local_30;
  puVar8 = param_2;
  pvVar1 = (void *)FUN_100167c0(local_18c,(undefined4 *)&DAT_1004421c,(undefined4 *)&DAT_100441e4);
  local_8._0_1_ = 2;
  pvVar1 = FUN_10016740(local_170,pvVar1,puVar2);
  local_8._0_1_ = 3;
  pvVar1 = FUN_10016740(local_154,pvVar1,puVar4);
  local_8._0_1_ = 4;
  pvVar1 = FUN_10016740(local_138,pvVar1,puVar5);
  local_8._0_1_ = 5;
  puVar2 = (undefined4 *)FUN_10016740(local_11c,pvVar1,puVar8);
  local_8._0_1_ = 6;
  FUN_100152a0(local_4c,puVar2,puVar6,uVar7);
  local_8._0_1_ = 8;
  FUN_1000aca0(local_11c);
  local_8._0_1_ = 9;
  FUN_1000aca0(local_138);
  local_8._0_1_ = 10;
  FUN_1000aca0(local_154);
  local_8._0_1_ = 0xb;
  FUN_1000aca0(local_170);
  local_8._0_1_ = 0xc;
  FUN_1000aca0(local_18c);
  local_4d = FUN_1001eae0(local_4c);
  iVar3 = FUN_10015960((int)local_4c);
  if ((iVar3 == 0) || (local_4d == '\0')) {
    uVar7 = 0x80000002;
    puVar8 = (undefined4 *)&DAT_10044200;
    puVar2 = (undefined4 *)&DAT_100441e4;
    pvVar1 = (void *)FUN_100167c0(local_100,(undefined4 *)&DAT_10044190,(undefined4 *)&DAT_100441c8)
    ;
    local_8._0_1_ = 0xd;
    pvVar1 = FUN_10016740(local_e4,pvVar1,puVar2);
    local_8._0_1_ = 0xe;
    puVar2 = (undefined4 *)FUN_10016740(local_c8,pvVar1,param_2);
    local_8._0_1_ = 0xf;
    uVar7 = FUN_100152a0(local_ac,puVar2,puVar8,uVar7);
    local_8._0_1_ = 0x10;
    FUN_10015880(local_4c,uVar7);
    local_8._0_1_ = 0xf;
    FUN_1000aca0(local_ac);
    local_8._0_1_ = 0xe;
    FUN_1000aca0(local_c8);
    local_8._0_1_ = 0xd;
    FUN_1000aca0(local_e4);
    local_8._0_1_ = 0xc;
    FUN_1000aca0(local_100);
  }
  FUN_100157f0(param_1,(int)local_4c);
  local_8._0_1_ = 1;
  FUN_1000aca0(local_4c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(local_30);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100152a0 at 100152a0

void FUN_100152a0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  void *pvVar1;
  int *piVar2;
  REGSAM RVar3;
  undefined1 *puVar4;
  uint uStack_108;
  int local_f0 [9];
  int local_cc [9];
  undefined1 local_a8 [28];
  int local_8c [2];
  char local_81;
  undefined4 local_80;
  int local_3c [2];
  undefined1 local_34 [28];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002eeb5;
  local_10 = ExceptionList;
  uStack_108 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_108;
  ExceptionList = &local_10;
  local_80 = 0;
  local_18 = uStack_108;
  FUN_10015780(local_34);
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  RVar3 = 0xf003f;
  piVar2 = local_3c;
  pvVar1 = FUN_10015a80(local_8c,param_4);
  local_8._0_1_ = 3;
  FUN_10015b30(pvVar1,piVar2,param_2,RVar3);
  local_8._0_1_ = 5;
  FUN_10015460(local_8c);
  pvVar1 = FUN_10015c00(local_3c,local_f0,param_3);
  local_8._0_1_ = 6;
  local_81 = FUN_10015c70(pvVar1);
  local_8._0_1_ = 5;
  FUN_100155c0(local_f0);
  if (local_81 != '\0') {
    puVar4 = local_a8;
    pvVar1 = FUN_10015c00(local_3c,local_cc,param_3);
    local_8._0_1_ = 7;
    FUN_10015ca0(pvVar1,puVar4);
    local_8._0_1_ = 8;
    FUN_10015880(local_34,local_a8);
    local_8._0_1_ = 7;
    FUN_1000aca0(local_a8);
    local_8._0_1_ = 5;
    FUN_100155c0(local_cc);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10015460(local_3c);
  FUN_1001540d();
  return;
}



// Function: Catch@10015400 at 10015400

undefined4 Catch_10015400(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x10015414;
}



// Function: FUN_1001540d at 1001540d

void FUN_1001540d(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 1;
  FUN_100157f0(*(void **)(unaff_EBP + 8),unaff_EBP - 0x30);
  *(uint *)(unaff_EBP - 0x7c) = *(uint *)(unaff_EBP - 0x7c) | 1;
  *(undefined1 *)(unaff_EBP - 4) = 0;
  FUN_1000aca0((void *)(unaff_EBP - 0x30));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10015450;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_10015460 at 10015460

void __fastcall FUN_10015460(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002eee8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100154c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100154c0 at 100154c0

void __fastcall FUN_100154c0(int *param_1)

{
  FUN_100154e0(param_1);
  return;
}



// Function: FUN_100154e0 at 100154e0

void __fastcall FUN_100154e0(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = FUN_100155a0(*param_1);
  if (bVar1) {
    iVar2 = FUN_10015530(param_1 + 1);
    if (iVar2 == 0) {
      RegCloseKey((HKEY)*param_1);
    }
  }
  *param_1 = 0;
  return;
}



// Function: FUN_10015530 at 10015530

undefined4 __fastcall FUN_10015530(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*param_1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)*param_1;
    *(int *)*param_1 = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      operator_delete((void *)*param_1);
      *param_1 = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)*param_1;
    }
  }
  return uVar2;
}



// Function: FUN_100155a0 at 100155a0

bool __cdecl FUN_100155a0(int param_1)

{
  return param_1 != 0;
}



// Function: FUN_100155c0 at 100155c0

void __fastcall FUN_100155c0(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002ef23;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000aca0(param_1 + 2);
  local_8 = 0xffffffff;
  FUN_100154c0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015630 at 10015630

void * __cdecl FUN_10015630(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ef59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a150(param_1,L"Administrator");
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100156a0 at 100156a0

void * __thiscall FUN_100156a0(void *this,undefined2 *param_1)

{
  FUN_1001fd40(this,param_1);
  return this;
}



// Function: FUN_100156d0 at 100156d0

undefined4 __fastcall FUN_100156d0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100156f0 at 100156f0

void * __thiscall FUN_100156f0(void *this,undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ef88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a6c0(&stack0xffffff94);
  FUN_1000a650((int)this);
  local_8 = 0;
  FUN_1000a550(this,'\0',0);
  FUN_1000a310(this,param_1,0,0xffffffff);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10015780 at 10015780

void * __fastcall FUN_10015780(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002efb8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a6a0(&stack0xffffff94);
  FUN_1000a650((int)param_1);
  local_8 = 0;
  FUN_1000a550(param_1,'\0',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100157f0 at 100157f0

void * __thiscall FUN_100157f0(void *this,int param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002efe8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10016880(param_1 + 0x18);
  FUN_1000a6c0(&stack0xffffff94);
  FUN_1000a650((int)this);
  local_8 = 0;
  FUN_1000a550(this,'\0',0);
  puVar1 = (undefined4 *)FUN_100168a0(param_1);
  FUN_10015da0(this,puVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10015880 at 10015880

void __thiscall FUN_10015880(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_100168a0(param_1);
  FUN_10015da0(this,puVar1);
  return;
}



// Function: FUN_100158b0 at 100158b0

void __thiscall FUN_100158b0(void *this,undefined4 *param_1)

{
  FUN_10015ea0(this,param_1);
  return;
}



// Function: FUN_100158e0 at 100158e0

void __thiscall FUN_100158e0(void *this,wchar_t *param_1)

{
  FUN_1000a1d0(this,param_1);
  return;
}



// Function: FUN_10015910 at 10015910

void __thiscall FUN_10015910(void *this,undefined4 *param_1)

{
  FUN_10015e70(this,param_1);
  return;
}



// Function: FUN_10015940 at 10015940

void __fastcall FUN_10015940(undefined4 *param_1)

{
  FUN_1000a600(param_1);
  return;
}



// Function: FUN_10015960 at 10015960

undefined4 __fastcall FUN_10015960(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_10015980 at 10015980

void __thiscall FUN_10015980(void *this,undefined4 *param_1,uint param_2)

{
  uint uVar1;
  ushort *puVar2;
  
  uVar1 = FUN_1000a4d0((int)param_1);
  puVar2 = (ushort *)FUN_1000a600(param_1);
  FUN_10015ed0(this,puVar2,param_2,uVar1);
  return;
}



// Function: FUN_100159c0 at 100159c0

void __thiscall FUN_100159c0(void *this,wchar_t *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000a200(param_1);
  FUN_10016040(this,param_1,param_2,iVar1);
  return;
}



// Function: FUN_10015a00 at 10015a00

void * FUN_10015a00(void *param_1,uint param_2,uint param_3)

{
  undefined1 local_59;
  undefined4 local_58;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f029;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_58 = 0;
  FUN_100160f0(&local_59);
  FUN_10015d10(param_1,local_14,param_2,param_3);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015a80 at 10015a80

void * __thiscall FUN_10015a80(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f058;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10015ae0(this,param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10015ae0 at 10015ae0

undefined4 * __thiscall FUN_10015ae0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_10015b10((undefined4 *)((int)this + 4));
  return (undefined4 *)this;
}



// Function: FUN_10015b10 at 10015b10

undefined4 * __fastcall FUN_10015b10(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10015b30 at 10015b30

void * __thiscall FUN_10015b30(void *this,void *param_1,undefined4 *param_2,REGSAM param_3)

{
  int iVar1;
  HKEY local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f099;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = (HKEY)0x0;
  local_14 = this;
  iVar1 = FUN_10015bc0(this,param_2,param_3,&local_18);
  FUN_10016120(iVar1);
  FUN_10015a80(param_1,local_18);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015bc0 at 10015bc0

void __thiscall FUN_10015bc0(void *this,undefined4 *param_1,REGSAM param_2,PHKEY param_3)

{
  LPCWSTR lpSubKey;
  DWORD ulOptions;
  
  *param_3 = (HKEY)0x0;
  ulOptions = 0;
  lpSubKey = (LPCWSTR)FUN_10015940(param_1);
                    /* WARNING: Load size is inaccurate */
  RegOpenKeyExW(*this,lpSubKey,ulOptions,param_2,param_3);
  return;
}



// Function: FUN_10015c00 at 10015c00

void * __thiscall FUN_10015c00(void *this,void *param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f0d9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10016160(this,param_1,param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015c70 at 10015c70

bool __fastcall FUN_10015c70(void *param_1)

{
  int iVar1;
  
  iVar1 = FUN_100161d0(param_1,(LPDWORD)0x0,(LPBYTE)0x0,(LPDWORD)0x0);
  return (bool)('\x01' - (iVar1 != 0));
}



// Function: FUN_10015ca0 at 10015ca0

void * __thiscall FUN_10015ca0(void *this,void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f119;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10016230(this,param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10015d10 at 10015d10

void * __thiscall FUN_10015d10(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f148;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a6c0(&stack0xffffff94);
  FUN_1000a650((int)this);
  local_8 = 0;
  FUN_1000a550(this,'\0',0);
  FUN_1000a310(this,param_1,param_2,param_3);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10015da0 at 10015da0

undefined4 * __thiscall FUN_10015da0(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined1 local_4a;
  undefined1 local_49 [65];
  undefined4 *local_8;
  
  local_8 = (undefined4 *)this;
  if ((undefined4 *)this != param_1) {
    FUN_100160f0(&local_4a);
    FUN_100160f0(local_49);
    bVar1 = FUN_100168c0();
    if ((bVar1) && (7 < (uint)param_1[5])) {
      FUN_100158b0(local_8,param_1);
    }
    else {
      FUN_1000a550(local_8,'\x01',0);
      if ((uint)param_1[5] < 8) {
        FUN_1000a470(local_8,param_1,param_1[4] + 1);
      }
      else {
        *local_8 = *param_1;
        *param_1 = 0;
      }
      local_8[4] = param_1[4];
      local_8[5] = param_1[5];
      FUN_1000a550(param_1,'\0',0);
    }
  }
  return local_8;
}



// Function: FUN_10015e70 at 10015e70

void __thiscall FUN_10015e70(void *this,undefined4 *param_1)

{
  FUN_100163c0(this,param_1,0,0xffffffff);
  return;
}



// Function: FUN_10015ea0 at 10015ea0

void __thiscall FUN_10015ea0(void *this,undefined4 *param_1)

{
  FUN_1000a310(this,param_1,0,0xffffffff);
  return;
}



// Function: FUN_10015ed0 at 10015ed0

uint __thiscall FUN_10015ed0(void *this,ushort *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  ushort *local_14;
  int local_c;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar4 = *(int *)((int)this + 0x10) - param_2, param_3 <= uVar4)) {
      local_c = uVar4 - (param_3 - 1);
      puVar1 = FUN_1000a600((undefined4 *)this);
      local_14 = (ushort *)((int)puVar1 + param_2 * 2);
      while (puVar2 = (ushort *)FUN_10015fc0((short *)local_14,local_c,(short *)param_1),
            puVar2 != (ushort *)0x0) {
        iVar3 = FUN_10014d50(puVar2,param_1,param_3);
        if (iVar3 == 0) {
          puVar1 = FUN_1000a600((undefined4 *)this);
          return (int)puVar2 - (int)puVar1 >> 1;
        }
        local_c = local_c - (((int)puVar2 - (int)local_14 >> 1) + 1);
        local_14 = puVar2 + 1;
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_10015fc0 at 10015fc0

void __cdecl FUN_10015fc0(short *param_1,int param_2,short *param_3)

{
  FUN_10015ff0(param_1,*param_3,param_2);
  return;
}



// Function: FUN_10015ff0 at 10015ff0

short * __cdecl FUN_10015ff0(short *param_1,short param_2,int param_3)

{
  while( true ) {
    if (param_3 == 0) {
      return (short *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
  }
  return param_1;
}



// Function: FUN_10016040 at 10016040

int __thiscall FUN_10016040(void *this,short *param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  short *psVar3;
  uint local_50;
  short *local_c;
  
  if ((param_3 == 0) || (*(int *)((int)this + 0x10) == 0)) {
LAB_100160d8:
    iVar2 = -1;
  }
  else {
    if (param_2 < *(uint *)((int)this + 0x10)) {
      local_50 = param_2;
    }
    else {
      local_50 = *(int *)((int)this + 0x10) - 1;
    }
    puVar1 = FUN_1000a600((undefined4 *)this);
    local_c = (short *)((int)puVar1 + local_50 * 2);
    while (iVar2 = FUN_10015fc0(param_1,param_3,local_c), iVar2 == 0) {
      psVar3 = (short *)FUN_1000a600((undefined4 *)this);
      if (local_c == psVar3) goto LAB_100160d8;
      local_c = local_c + -1;
    }
    puVar1 = FUN_1000a600((undefined4 *)this);
    iVar2 = (int)local_c - (int)puVar1 >> 1;
  }
  return iVar2;
}



// Function: FUN_100160f0 at 100160f0

undefined4 FUN_100160f0(undefined4 param_1)

{
  FUN_1000a6c0(param_1);
  return param_1;
}



// Function: FUN_10016120 at 10016120

void __cdecl FUN_10016120(int param_1)

{
  if (param_1 != 0) {
    FUN_10016150();
  }
  return;
}



// Function: FUN_10016150 at 10016150

void FUN_10016150(void)

{
  return;
}



// Function: FUN_10016160 at 10016160

void * __thiscall FUN_10016160(void *this,void *param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f189;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100164f0(param_1,(int *)this,param_2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100161d0 at 100161d0

void __thiscall FUN_100161d0(void *this,LPDWORD param_1,LPBYTE param_2,LPDWORD param_3)

{
  LPCWSTR lpValueName;
  HKEY hKey;
  LPDWORD lpReserved;
  
  lpReserved = (LPDWORD)0x0;
  lpValueName = (LPCWSTR)FUN_10015940((undefined4 *)((int)this + 8));
  hKey = (HKEY)FUN_10016210((undefined4 *)this);
  RegQueryValueExW(hKey,lpValueName,lpReserved,param_1,param_2,param_3);
  return;
}



// Function: FUN_10016210 at 10016210

undefined4 __fastcall FUN_10016210(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10016230 at 10016230

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_10016230(void *this,void *param_1)

{
  int iVar1;
  void *this_00;
  undefined4 uStackY_8c;
  uint local_7c;
  DWORD local_20;
  DWORD local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f1c9;
  local_10 = ExceptionList;
  local_7c = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0;
  uStackY_8c = 0x1001627e;
  local_18 = this;
  local_14 = local_7c;
  FUN_10016380(this,&local_20,(LPBYTE)0x0,&local_1c);
  if ((local_20 != 1) && (local_20 != 2)) {
    FUN_100164c0();
  }
  iVar1 = -local_1c;
  *(DWORD **)(&stack0xffffff80 + iVar1) = &local_1c;
  *(int *)(&stack0xffffff7c + iVar1) = (int)&local_7c + iVar1;
  *(undefined4 *)(&stack0xffffff78 + iVar1) = 0;
  this_00 = local_18;
  *(undefined4 *)((int)&uStackY_8c + iVar1) = 0x100162b2;
  FUN_10016380(this_00,*(LPDWORD *)(&stack0xffffff78 + iVar1),*(LPBYTE *)(&stack0xffffff7c + iVar1),
               *(LPDWORD *)(&stack0xffffff80 + iVar1));
  *(DWORD *)(&stack0xffffff80 + iVar1) = (local_1c >> 1) - 1;
  *(int *)(&stack0xffffff7c + iVar1) = (int)&local_7c + iVar1;
  *(undefined4 *)(&stack0xffffff78 + iVar1) = 0x100162c7;
  FUN_10016300(param_1,*(undefined4 **)(&stack0xffffff7c + iVar1),
               *(uint *)(&stack0xffffff80 + iVar1));
  local_8 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016300 at 10016300

void * __thiscall FUN_10016300(void *this,undefined4 *param_1,uint param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f1f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a6a0(&stack0xffffff94);
  FUN_1000a650((int)this);
  local_8 = 0;
  FUN_1000a550(this,'\0',0);
  FUN_1000a220(this,param_1,param_2);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10016380 at 10016380

void __thiscall FUN_10016380(void *this,LPDWORD param_1,LPBYTE param_2,LPDWORD param_3)

{
  int iVar1;
  
  iVar1 = FUN_100161d0(this,param_1,param_2,param_3);
  FUN_10016490(iVar1);
  return;
}



// Function: FUN_100163c0 at 100163c0

undefined4 * __thiscall FUN_100163c0(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  
  uVar2 = FUN_1000a4d0((int)param_1);
  if (uVar2 < param_2) {
    FUN_1000a630();
  }
  iVar3 = FUN_1000a4d0((int)param_1);
  if (iVar3 - param_2 < param_3) {
    param_3 = iVar3 - param_2;
  }
  if (-*(int *)((int)this + 0x10) - 1U <= param_3) {
    FUN_1000a7d0();
  }
  if (param_3 != 0) {
    uVar2 = *(int *)((int)this + 0x10) + param_3;
    bVar1 = FUN_1000a6e0(this,uVar2,'\0');
    if (bVar1) {
      puVar4 = FUN_1000a600(param_1);
      pvVar5 = (void *)((int)puVar4 + param_2 * 2);
      puVar4 = FUN_1000a5d0((undefined4 *)this);
      FUN_1000a2b0((void *)((int)puVar4 + *(int *)((int)this + 0x10) * 2),pvVar5,param_3);
      FUN_1000a4f0(this,uVar2);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10016490 at 10016490

void __cdecl FUN_10016490(int param_1)

{
  if (param_1 != 0) {
    FUN_10016150();
  }
  return;
}



// Function: FUN_100164c0 at 100164c0

void FUN_100164c0(void)

{
  FUN_100164e0();
  return;
}



// Function: FUN_100164e0 at 100164e0

void FUN_100164e0(void)

{
  return;
}



// Function: FUN_100164f0 at 100164f0

void * __thiscall FUN_100164f0(void *this,int *param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f233;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10016560(this,param_1);
  local_8 = 0;
  FUN_100156f0((void *)((int)this + 8),param_2);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10016560 at 10016560

int * __thiscall FUN_10016560(void *this,int *param_1)

{
  bool bVar1;
  
  *(int *)this = *param_1;
  FUN_10015b10((undefined4 *)((int)this + 4));
                    /* WARNING: Load size is inaccurate */
  bVar1 = FUN_100155a0(*this);
  if (bVar1) {
    FUN_100165c0(param_1 + 1);
  }
  FUN_10016630((void *)((int)this + 4),param_1 + 1);
  return (int *)this;
}



// Function: FUN_100165c0 at 100165c0

int __fastcall FUN_100165c0(int *param_1)

{
  int iVar1;
  undefined4 local_50;
  
  if (*param_1 == 0) {
    local_50 = (undefined4 *)operator_new(4);
    if (local_50 == (undefined4 *)0x0) {
      local_50 = (undefined4 *)0x0;
    }
    else {
      *local_50 = 1;
    }
    *param_1 = (int)local_50;
  }
  iVar1 = *(int *)*param_1;
  *(int *)*param_1 = iVar1 + 1;
  return iVar1 + 1;
}



// Function: FUN_10016630 at 10016630

undefined4 * __thiscall FUN_10016630(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return (undefined4 *)this;
}



// Function: FUN_10016660 at 10016660

undefined4 __fastcall FUN_10016660(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10016680 at 10016680

void FUN_10016680(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_100166b0 at 100166b0

void FUN_100166b0(uint param_1)

{
  FUN_10016930(param_1);
  return;
}



// Function: FUN_100166e0 at 100166e0

undefined4 __fastcall FUN_100166e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10016700 at 10016700

/* WARNING: Removing unreachable block (ram,0x10016721) */

undefined4 FUN_10016700(void)

{
  return 0x9249249;
}



// Function: FUN_10016740 at 10016740

void * __cdecl FUN_10016740(void *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f269;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10015e70(param_2,param_3);
  iVar2 = FUN_10016bf0(uVar1);
  FUN_100157f0(param_1,iVar2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100167c0 at 100167c0

void __cdecl FUN_100167c0(void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f2b1;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10015780(local_30);
  local_8 = 1;
  iVar1 = FUN_1000a4d0((int)param_2);
  iVar2 = FUN_1000a4d0((int)param_3);
  FUN_100169d0(local_30,iVar1 + iVar2);
  FUN_10015910(local_30,param_2);
  FUN_10015910(local_30,param_3);
  FUN_100157f0(param_1,(int)local_30);
  local_8 = local_8 & 0xffffff00;
  FUN_1000aca0(local_30);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016880 at 10016880

undefined4 __cdecl FUN_10016880(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100168a0 at 100168a0

undefined4 __cdecl FUN_100168a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100168c0 at 100168c0

bool FUN_100168c0(void)

{
  char cVar1;
  
  cVar1 = FUN_100168f0();
  return (bool)('\x01' - (cVar1 != '\0'));
}



// Function: FUN_100168f0 at 100168f0

undefined1 FUN_100168f0(void)

{
  return 1;
}



// Function: FUN_10016910 at 10016910

void __cdecl FUN_10016910(undefined4 param_1,void *param_2)

{
  FUN_10016a30(param_2);
  return;
}



// Function: FUN_10016930 at 10016930

void * __cdecl FUN_10016930(uint param_1)

{
  exception local_54 [76];
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x9249249 < param_1 || (local_8 = operator_new(param_1 * 0x1c), local_8 == (void *)0x0)))) {
    FUN_1000aac0(local_54);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1003d210);
  }
  return local_8;
}



// Function: FUN_100169a0 at 100169a0

void __thiscall FUN_100169a0(void *this,wchar_t *param_1)

{
  FUN_10016a60(this,param_1);
  return;
}



// Function: FUN_100169d0 at 100169d0

void __thiscall FUN_100169d0(void *this,uint param_1)

{
  int iVar1;
  bool bVar2;
  
  if ((*(uint *)((int)this + 0x10) <= param_1) && (*(uint *)((int)this + 0x14) != param_1)) {
    iVar1 = *(int *)((int)this + 0x10);
    bVar2 = FUN_1000a6e0(this,param_1,'\x01');
    if (bVar2) {
      FUN_1000a4f0(this,iVar1);
    }
  }
  return;
}



// Function: FUN_10016a30 at 10016a30

void FUN_10016a30(void *param_1)

{
  FUN_10016c10(param_1);
  return;
}



// Function: FUN_10016a60 at 10016a60

void __thiscall FUN_10016a60(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1000a200(param_1);
  FUN_10016b30(this,(undefined4 *)param_1,uVar1);
  return;
}



// Function: FUN_10016a90 at 10016a90

undefined4 * __thiscall FUN_10016a90(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f2eb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  FUN_100156f0((void *)((int)this + 0x10),(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016b30 at 10016b30

undefined4 * __thiscall FUN_10016b30(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_1000a780(this,param_1);
  if ((uVar2 & 0xff) == 0) {
    if (-*(int *)((int)this + 0x10) - 1U <= param_2) {
      FUN_1000a7d0();
    }
    if (param_2 != 0) {
      uVar2 = *(int *)((int)this + 0x10) + param_2;
      bVar1 = FUN_1000a6e0(this,uVar2,'\0');
      if (bVar1) {
        puVar3 = FUN_1000a5d0((undefined4 *)this);
        FUN_1000a2b0((void *)((int)puVar3 + *(int *)((int)this + 0x10) * 2),param_1,param_2);
        FUN_1000a4f0(this,uVar2);
      }
    }
  }
  else {
    puVar3 = FUN_1000a5d0((undefined4 *)this);
    this = FUN_100163c0(this,(undefined4 *)this,(int)param_1 - (int)puVar3 >> 1,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10016bf0 at 10016bf0

undefined4 __cdecl FUN_10016bf0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10016c10 at 10016c10

void __cdecl FUN_10016c10(void *param_1)

{
  FUN_10016c30(param_1,0);
  return;
}



// Function: FUN_10016c30 at 10016c30

void * __thiscall FUN_10016c30(void *this,uint param_1)

{
  FUN_1000aca0(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10016c70 at 10016c70

void __cdecl FUN_10016c70(void *param_1,undefined4 *param_2,wchar_t *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f331;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10015780(local_30);
  local_8 = 1;
  iVar1 = FUN_1000a4d0((int)param_2);
  iVar2 = FUN_1000a200(param_3);
  FUN_100169d0(local_30,iVar1 + iVar2);
  FUN_10015910(local_30,param_2);
  FUN_100169a0(local_30,param_3);
  FUN_100157f0(param_1,(int)local_30);
  local_8 = local_8 & 0xffffff00;
  FUN_1000aca0(local_30);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10016d30 at 10016d30

int FUN_10016d30(void)

{
  undefined1 local_56 [66];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f428;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10016ef0(local_56);
  FUN_10016e00(local_14);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10016da0 at 10016da0

void __fastcall FUN_10016da0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002f458;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10016e70(param_1);
  local_8 = 0xffffffff;
  FUN_10016ec0((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016e00 at 10016e00

int __fastcall FUN_10016e00(int param_1)

{
  int iStack_6c;
  uint uStack_68;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f488;
  local_10 = ExceptionList;
  uStack_68 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iStack_6c = param_1;
  FUN_10017080(&iStack_6c);
  FUN_10016fc0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016e70 at 10016e70

void __fastcall FUN_10016e70(void *param_1)

{
  undefined4 *puVar1;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = param_1;
  FUN_1000da40(param_1,local_58);
  puVar1 = (undefined4 *)FUN_100116d0(local_8,local_50);
  local_54 = *puVar1;
  FUN_10016f10(local_8,local_4c,local_54);
  return;
}



// Function: FUN_10016ec0 at 10016ec0

void __fastcall FUN_10016ec0(int param_1)

{
  FUN_10011700(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_10016ef0 at 10016ef0

undefined4 __fastcall FUN_10016ef0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10016f10 at 10016f10

/* WARNING: Variable defined which should be unmapped: param_2 */

void * __thiscall FUN_10016f10(void *param_1,void *param_2,undefined4 param_3)

{
  bool bVar1;
  int *piVar2;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  int local_50;
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = param_1;
  piVar2 = (int *)FUN_100116d0(param_1,local_58);
  bVar1 = FUN_1000eab0(&param_3,piVar2);
  if (bVar1) {
    piVar2 = (int *)FUN_1000da40(local_8,local_54);
    bVar1 = FUN_1000eab0(&stack0x0000000c,piVar2);
    if (bVar1) {
      FUN_10017830(local_8);
      FUN_100116d0(local_8,param_2);
      return param_2;
    }
  }
  while (bVar1 = FUN_1000db00(&param_3,(int *)&stack0x0000000c), bVar1) {
    piVar2 = FUN_100178e0(&param_3,&local_50);
    FUN_100170a0(local_8,local_4c,*piVar2);
  }
  FUN_1000ea60(param_2,param_3);
  return param_2;
}



// Function: FUN_10016fc0 at 10016fc0

int __fastcall FUN_10016fc0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  FUN_10017080(&stack0xffffffa4);
  FUN_10017890(param_1);
  *(undefined4 *)(param_1 + 8) = 0;
  uVar1 = FUN_100140e0(1);
  *(undefined4 *)(param_1 + 4) = uVar1;
  puVar2 = (undefined4 *)FUN_1000fd30(*(undefined4 *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1000fd50(*(int *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1000fd70(*(int *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined1 *)FUN_10012b50(*(int *)(param_1 + 4));
  *puVar3 = 1;
  puVar3 = (undefined1 *)FUN_1000fd10(*(int *)(param_1 + 4));
  *puVar3 = 1;
  return param_1;
}



// Function: FUN_10017080 at 10017080

undefined4 __fastcall FUN_10017080(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100170a0 at 100170a0

void * __thiscall FUN_100170a0(void *this,void *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  void *pvVar9;
  void *local_5c;
  void *local_18;
  void *local_14;
  void *local_10;
  
  iVar1 = FUN_1000eae0(&param_2);
  pcVar2 = (char *)FUN_1000fd10(iVar1);
  if (*pcVar2 != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  pvVar3 = (void *)FUN_1000eae0(&param_2);
  FUN_10011de0(&param_2);
  piVar4 = (int *)FUN_1000fd30(pvVar3);
  pcVar2 = (char *)FUN_1000fd10(*piVar4);
  local_18 = pvVar3;
  if (*pcVar2 == '\0') {
    piVar4 = (int *)FUN_1000fd70((int)pvVar3);
    pcVar2 = (char *)FUN_1000fd10(*piVar4);
    if (*pcVar2 == '\0') {
      local_18 = (void *)FUN_1000eae0(&param_2);
      puVar5 = (undefined4 *)FUN_1000fd70((int)local_18);
      local_10 = (void *)*puVar5;
    }
    else {
      puVar5 = (undefined4 *)FUN_1000fd30(pvVar3);
      local_10 = (void *)*puVar5;
    }
  }
  else {
    puVar5 = (undefined4 *)FUN_1000fd70((int)pvVar3);
    local_10 = (void *)*puVar5;
  }
  if (local_18 == pvVar3) {
    piVar4 = (int *)FUN_1000fd50((int)pvVar3);
    local_14 = (void *)*piVar4;
    pcVar2 = (char *)FUN_1000fd10((int)local_10);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_1000fd50((int)local_10);
      *piVar4 = (int)local_14;
    }
    piVar4 = (int *)FUN_1000fce0((int)this);
    if ((void *)*piVar4 == pvVar3) {
      puVar5 = (undefined4 *)FUN_1000fce0((int)this);
      *puVar5 = local_10;
    }
    else {
      piVar4 = (int *)FUN_1000fd30(local_14);
      if ((void *)*piVar4 == pvVar3) {
        puVar5 = (undefined4 *)FUN_1000fd30(local_14);
        *puVar5 = local_10;
      }
      else {
        puVar5 = (undefined4 *)FUN_1000fd70((int)local_14);
        *puVar5 = local_10;
      }
    }
    piVar4 = (int *)FUN_10011730((int)this);
    if ((void *)*piVar4 == pvVar3) {
      pcVar2 = (char *)FUN_1000fd10((int)local_10);
      local_5c = local_14;
      if (*pcVar2 == '\0') {
        local_5c = (void *)FUN_10011ec0(local_10);
      }
      piVar4 = (int *)FUN_10011730((int)this);
      *piVar4 = (int)local_5c;
    }
    piVar4 = (int *)FUN_10011db0((int)this);
    if ((void *)*piVar4 == pvVar3) {
      pcVar2 = (char *)FUN_1000fd10((int)local_10);
      local_5c = local_14;
      if (*pcVar2 == '\0') {
        local_5c = (void *)FUN_100137d0((int)local_10);
      }
      piVar4 = (int *)FUN_10011db0((int)this);
      *piVar4 = (int)local_5c;
    }
  }
  else {
    piVar4 = (int *)FUN_1000fd30(pvVar3);
    puVar5 = (undefined4 *)FUN_1000fd50(*piVar4);
    *puVar5 = local_18;
    puVar5 = (undefined4 *)FUN_1000fd30(pvVar3);
    puVar6 = (undefined4 *)FUN_1000fd30(local_18);
    *puVar6 = *puVar5;
    piVar4 = (int *)FUN_1000fd70((int)pvVar3);
    if (local_18 == (void *)*piVar4) {
      local_14 = local_18;
    }
    else {
      piVar4 = (int *)FUN_1000fd50((int)local_18);
      local_14 = (void *)*piVar4;
      pcVar2 = (char *)FUN_1000fd10((int)local_10);
      if (*pcVar2 == '\0') {
        piVar4 = (int *)FUN_1000fd50((int)local_10);
        *piVar4 = (int)local_14;
      }
      puVar5 = (undefined4 *)FUN_1000fd30(local_14);
      *puVar5 = local_10;
      puVar5 = (undefined4 *)FUN_1000fd70((int)pvVar3);
      puVar6 = (undefined4 *)FUN_1000fd70((int)local_18);
      *puVar6 = *puVar5;
      piVar4 = (int *)FUN_1000fd70((int)pvVar3);
      puVar5 = (undefined4 *)FUN_1000fd50(*piVar4);
      *puVar5 = local_18;
    }
    piVar4 = (int *)FUN_1000fce0((int)this);
    if ((void *)*piVar4 == pvVar3) {
      puVar5 = (undefined4 *)FUN_1000fce0((int)this);
      *puVar5 = local_18;
    }
    else {
      puVar5 = (undefined4 *)FUN_1000fd50((int)pvVar3);
      piVar4 = (int *)FUN_1000fd30(*puVar5);
      if ((void *)*piVar4 == pvVar3) {
        puVar5 = (undefined4 *)FUN_1000fd50((int)pvVar3);
        puVar5 = (undefined4 *)FUN_1000fd30(*puVar5);
        *puVar5 = local_18;
      }
      else {
        piVar4 = (int *)FUN_1000fd50((int)pvVar3);
        puVar5 = (undefined4 *)FUN_1000fd70(*piVar4);
        *puVar5 = local_18;
      }
    }
    puVar5 = (undefined4 *)FUN_1000fd50((int)pvVar3);
    puVar6 = (undefined4 *)FUN_1000fd50((int)local_18);
    *puVar6 = *puVar5;
    puVar7 = (undefined1 *)FUN_10012b50((int)pvVar3);
    puVar8 = (undefined1 *)FUN_10012b50((int)local_18);
    FUN_10011250(puVar8,puVar7);
  }
  pcVar2 = (char *)FUN_10012b50((int)pvVar3);
  if (*pcVar2 != '\x01') {
LAB_100177c2:
    iVar1 = FUN_1000f440((int)pvVar3);
    pvVar9 = (void *)FUN_10011760(iVar1);
    FUN_10011780((int)this + 0xd,pvVar9);
    FUN_10011700(pvVar3);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    FUN_1000ea60(param_1,param_2);
    return param_1;
  }
LAB_10017446:
  piVar4 = (int *)FUN_1000fce0((int)this);
  if ((local_10 == (void *)*piVar4) ||
     (pcVar2 = (char *)FUN_10012b50((int)local_10), *pcVar2 != '\x01')) goto LAB_100177b3;
  piVar4 = (int *)FUN_1000fd30(local_14);
  if (local_10 == (void *)*piVar4) {
    piVar4 = (int *)FUN_1000fd70((int)local_14);
    local_18 = (void *)*piVar4;
    pcVar2 = (char *)FUN_10012b50((int)local_18);
    if (*pcVar2 == '\0') {
      puVar7 = (undefined1 *)FUN_10012b50((int)local_18);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_10012b50((int)local_14);
      *puVar7 = 0;
      FUN_10012b70(this,(int)local_14);
      piVar4 = (int *)FUN_1000fd70((int)local_14);
      local_18 = (void *)*piVar4;
    }
    pcVar2 = (char *)FUN_1000fd10((int)local_18);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_1000fd30(local_18);
      pcVar2 = (char *)FUN_10012b50(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1000fd70((int)local_18);
        pcVar2 = (char *)FUN_10012b50(*piVar4);
        if (*pcVar2 == '\x01') {
          puVar7 = (undefined1 *)FUN_10012b50((int)local_18);
          *puVar7 = 0;
          goto LAB_10017435;
        }
      }
      piVar4 = (int *)FUN_1000fd70((int)local_18);
      pcVar2 = (char *)FUN_10012b50(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1000fd30(local_18);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10012b50((int)local_18);
        *puVar7 = 0;
        FUN_10012cb0(this,(int)local_18);
        piVar4 = (int *)FUN_1000fd70((int)local_14);
        local_18 = (void *)*piVar4;
      }
      puVar7 = (undefined1 *)FUN_10012b50((int)local_14);
      puVar8 = (undefined1 *)FUN_10012b50((int)local_18);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_10012b50((int)local_14);
      *puVar7 = 1;
      piVar4 = (int *)FUN_1000fd70((int)local_18);
      puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
      *puVar7 = 1;
      FUN_10012b70(this,(int)local_14);
LAB_100177b3:
      puVar7 = (undefined1 *)FUN_10012b50((int)local_10);
      *puVar7 = 1;
      goto LAB_100177c2;
    }
  }
  else {
    piVar4 = (int *)FUN_1000fd30(local_14);
    local_18 = (void *)*piVar4;
    pcVar2 = (char *)FUN_10012b50((int)local_18);
    if (*pcVar2 == '\0') {
      puVar7 = (undefined1 *)FUN_10012b50((int)local_18);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_10012b50((int)local_14);
      *puVar7 = 0;
      FUN_10012cb0(this,(int)local_14);
      piVar4 = (int *)FUN_1000fd30(local_14);
      local_18 = (void *)*piVar4;
    }
    pcVar2 = (char *)FUN_1000fd10((int)local_18);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_1000fd70((int)local_18);
      pcVar2 = (char *)FUN_10012b50(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1000fd30(local_18);
        pcVar2 = (char *)FUN_10012b50(*piVar4);
        if (*pcVar2 == '\x01') {
          puVar7 = (undefined1 *)FUN_10012b50((int)local_18);
          *puVar7 = 0;
          goto LAB_10017435;
        }
      }
      piVar4 = (int *)FUN_1000fd30(local_18);
      pcVar2 = (char *)FUN_10012b50(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1000fd70((int)local_18);
        puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_10012b50((int)local_18);
        *puVar7 = 0;
        FUN_10012b70(this,(int)local_18);
        piVar4 = (int *)FUN_1000fd30(local_14);
        local_18 = (void *)*piVar4;
      }
      puVar7 = (undefined1 *)FUN_10012b50((int)local_14);
      puVar8 = (undefined1 *)FUN_10012b50((int)local_18);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_10012b50((int)local_14);
      *puVar7 = 1;
      piVar4 = (int *)FUN_1000fd30(local_18);
      puVar7 = (undefined1 *)FUN_10012b50(*piVar4);
      *puVar7 = 1;
      FUN_10012cb0(this,(int)local_14);
      goto LAB_100177b3;
    }
  }
LAB_10017435:
  local_10 = local_14;
  puVar5 = (undefined4 *)FUN_1000fd50((int)local_14);
  local_14 = (void *)*puVar5;
  goto LAB_10017446;
}



// Function: FUN_10017830 at 10017830

void __fastcall FUN_10017830(void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1000fce0((int)param_1);
  FUN_10017910(param_1,(void *)*puVar1);
  puVar1 = (undefined4 *)FUN_1000fce0((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_10011730((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_10011db0((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10017890 at 10017890

int __fastcall FUN_10017890(int param_1)

{
  FUN_100179b0(param_1);
  FUN_100179d0(param_1 + 0xc);
  FUN_10017080(param_1 + 0xd);
  return param_1;
}



// Function: FUN_100178e0 at 100178e0

int * __thiscall FUN_100178e0(void *this,int *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  FUN_10011de0((int *)this);
  *param_1 = iVar1;
  return param_1;
}



// Function: FUN_10017910 at 10017910

void __thiscall FUN_10017910(void *this,void *param_1)

{
  void *pvVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_c;
  
  local_c = param_1;
  while( true ) {
    pcVar2 = (char *)FUN_1000fd10((int)local_c);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_1000fd70((int)local_c);
    FUN_10017910(this,(void *)*puVar3);
    puVar3 = (undefined4 *)FUN_1000fd30(local_c);
    pvVar1 = (void *)*puVar3;
    iVar4 = FUN_1000f440((int)local_c);
    pvVar5 = (void *)FUN_10011760(iVar4);
    FUN_10011780((int)this + 0xd,pvVar5);
    FUN_10011700(local_c);
    local_c = pvVar1;
  }
  return;
}



// Function: FUN_100179b0 at 100179b0

undefined4 __fastcall FUN_100179b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100179d0 at 100179d0

undefined4 __fastcall FUN_100179d0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100179f0 at 100179f0

void __fastcall FUN_100179f0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002f4b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10016da0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017a50 at 10017a50

undefined4 * __fastcall FUN_10017a50(undefined4 *param_1)

{
  undefined1 auStack_90 [20];
  undefined4 uStack_7c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f51d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CLogFileManager::vftable;
  uStack_7c = 0x10017a91;
  FUN_100189e0(param_1 + 2,1);
  local_8 = 0;
  FUN_10015780(param_1 + 0x30);
  local_8._0_1_ = 1;
  *(undefined2 *)(param_1 + 0x37) = 1;
  uStack_7c = 0x10017acc;
  FUN_1000a150(param_1 + 0x38,L"");
  local_8._0_1_ = 2;
  FUN_1000a150(auStack_90,L"LogFileManagerLock");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1002b0c0(param_1 + 0x3f);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017b30 at 10017b30

undefined4 * __thiscall FUN_10017b30(void *this,uint param_1)

{
  FUN_10017ba0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10017b70 at 10017b70

void __fastcall FUN_10017b70(int param_1)

{
  FUN_10018ab0(param_1 + 0x70);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(param_1 + 0x70));
  return;
}



// Function: FUN_10017ba0 at 10017ba0

void __fastcall FUN_10017ba0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002f575;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CLogFileManager::vftable;
  local_8 = 3;
  FUN_10018200((int)param_1);
  local_8._0_1_ = 2;
  FUN_1002b1e0(param_1 + 0x3f);
  local_8._0_1_ = 1;
  FUN_1000aca0(param_1 + 0x38);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(param_1 + 0x30);
  local_8 = 0xffffffff;
  FUN_10017b70((int)(param_1 + 2));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10017c40 at 10017c40

void __thiscall FUN_10017c40(void *this,void *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_c8 [28];
  undefined1 local_ac [28];
  undefined1 local_90 [92];
  undefined4 local_34 [7];
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f5d8;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = this;
  FUN_10022bb0(local_34,(int)*(short *)((int)this + 0xdc));
  local_8 = 1;
  puVar4 = (undefined4 *)&DAT_1004425c;
  puVar1 = (undefined4 *)((int)local_18 + 0xe0);
  puVar3 = (undefined4 *)&DAT_100442b4;
  pvVar2 = (void *)FUN_100167c0(local_c8,(undefined4 *)&DAT_10044240,local_34);
  local_8._0_1_ = 2;
  pvVar2 = FUN_10016740(local_ac,pvVar2,puVar3);
  local_8._0_1_ = 3;
  pvVar2 = FUN_10016740(local_90,pvVar2,puVar1);
  local_8._0_1_ = 4;
  FUN_10016740(param_1,pvVar2,puVar4);
  local_8._0_1_ = 3;
  FUN_1000aca0(local_90);
  local_8._0_1_ = 2;
  FUN_1000aca0(local_ac);
  local_8._0_1_ = 1;
  FUN_1000aca0(local_c8);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(local_34);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017db0 at 10017db0

undefined4 __fastcall FUN_10017db0(int param_1)

{
  void *this;
  ulonglong uVar1;
  uint *puVar2;
  uint local_78 [28];
  int local_8;
  
  local_8 = param_1;
  std::basic_istream<char,struct_std::char_traits<char>_>::seekg
            ((basic_istream<char,struct_std::char_traits<char>_> *)(param_1 + 8),0,0);
  std::basic_istream<char,struct_std::char_traits<char>_>::tellg
            ((basic_istream<char,struct_std::char_traits<char>_> *)(local_8 + 8));
  std::basic_istream<char,struct_std::char_traits<char>_>::seekg
            ((basic_istream<char,struct_std::char_traits<char>_> *)(local_8 + 8),0,2);
  puVar2 = local_78;
  this = (void *)std::basic_istream<char,struct_std::char_traits<char>_>::tellg
                           ((basic_istream<char,struct_std::char_traits<char>_> *)(local_8 + 8));
  uVar1 = FUN_100189a0(this,puVar2);
  return (int)((longlong)((ulonglong)(uint)((int)uVar1 >> 0x1f) << 0x20 | uVar1 & 0xffffffff) / 1000
              );
}



// Function: FUN_10017e20 at 10017e20

void __fastcall FUN_10017e20(void *param_1)

{
  char cVar1;
  undefined2 uVar2;
  char *pcVar3;
  int *local_8c;
  undefined4 local_44 [7];
  int local_28;
  undefined4 local_24 [2];
  undefined4 local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1002f618;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = 0;
  local_18 = param_1;
  FUN_1002b2a0(local_24,(int)param_1 + 0xfc);
  local_8 = CONCAT31(local_8._1_3_,1);
  cVar1 = FUN_10018b30((int)local_18 + 8);
  if (cVar1 == '\0') {
    local_1c = 0x80001101;
  }
  else {
    local_28 = FUN_10017db0((int)local_18);
    if (0x1ff < local_28) {
      uVar2 = FUN_10018580(local_18,*(short *)((int)local_18 + 0xdc));
      *(undefined2 *)((int)local_18 + 0xdc) = uVar2;
    }
    cVar1 = FUN_10018b30((int)local_18 + 8);
    if (cVar1 == '\0') {
      local_1c = 0x80001101;
    }
    else {
      FUN_10022d90(local_44,(undefined4 *)&stack0x00000004);
      local_8._0_1_ = 2;
      if (local_18 == (void *)0xfffffff8) {
        local_8c = (int *)0x0;
      }
      else {
        local_8c = (int *)((int)local_18 + 0x18);
      }
      pcVar3 = (char *)FUN_1001d880(local_44);
      FUN_1001ba90(local_8c,pcVar3);
      std::basic_ostream<char,struct_std::char_traits<char>_>::flush
                ((basic_ostream<char,struct_std::char_traits<char>_> *)((int)local_18 + 0x18));
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_1001d820(local_44);
    }
  }
  local_8 = local_8 & 0xffffff00;
  FUN_1002b2e0(local_24);
  local_8 = 0xffffffff;
  FUN_1000aca0(&stack0x00000004);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017f90 at 10017f90

void __fastcall FUN_10017f90(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int *local_98;
  undefined1 local_94 [28];
  undefined1 local_78 [92];
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f653;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  bVar1 = std::ios_base::operator!((ios_base *)(param_1 + 8 + *(int *)(*(int *)(param_1 + 8) + 4)));
  if (!bVar1) {
    for (local_1c = 0; local_1c < 0x10; local_1c = local_1c + 1) {
      if (local_18 == -8) {
        local_98 = (int *)0x0;
      }
      else {
        local_98 = (int *)(local_18 + 0x18);
      }
      puVar2 = (undefined4 *)FUN_10022d90(local_94,(undefined4 *)(&DAT_100442d0 + local_1c * 0x1c));
      local_8 = 0;
      FUN_1001bdd0(local_98,puVar2);
      local_8 = 0xffffffff;
      FUN_1001d820(local_94);
      if (local_18 == -8) {
        local_98 = (int *)0x0;
      }
      else {
        local_98 = (int *)(local_18 + 0x18);
      }
      puVar2 = (undefined4 *)FUN_10022d90(local_78,(undefined4 *)&DAT_10044278);
      local_8 = 1;
      FUN_1001bdd0(local_98,puVar2);
      local_8 = 0xffffffff;
      FUN_1001d820(local_78);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018110 at 10018110

void __thiscall FUN_10018110(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  void *pvVar2;
  undefined1 local_90 [92];
  undefined4 local_34 [7];
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f693;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = this;
  FUN_100158b0((void *)((int)this + 0xc0),param_1);
  FUN_100158b0((void *)((int)local_18 + 0xe0),param_2);
  pvVar2 = (void *)FUN_10018620(local_90);
  local_8 = 0;
  FUN_10018890(local_34,pvVar2);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000aca0(local_90);
  uVar1 = FUN_10023ad0(local_34);
  *(undefined2 *)((int)local_18 + 0xdc) = uVar1;
  FUN_10018240(local_18);
  local_8 = 0xffffffff;
  FUN_1000aca0(local_34);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018200 at 10018200

void __fastcall FUN_10018200(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_10018b30(param_1 + 8);
  if (cVar1 != '\0') {
    std::basic_ostream<char,struct_std::char_traits<char>_>::flush
              ((basic_ostream<char,struct_std::char_traits<char>_> *)(param_1 + 0x18));
    FUN_10018bb0((int *)(param_1 + 8));
  }
  return;
}



// Function: FUN_10018240 at 10018240

void __fastcall FUN_10018240(void *param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uStack_ec;
  undefined1 local_cc [28];
  undefined1 local_b0 [92];
  undefined4 local_54 [7];
  undefined4 local_38 [7];
  void *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f6e6;
  local_10 = ExceptionList;
  uStack_ec = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_ec;
  ExceptionList = &local_10;
  local_1c = param_1;
  local_18 = uStack_ec;
  puVar3 = (undefined4 *)FUN_10017c40(param_1,local_b0);
  local_8 = 0;
  puVar4 = (undefined4 *)FUN_10016c70(local_cc,(undefined4 *)((int)local_1c + 0xc0),L"\\");
  local_8._0_1_ = 1;
  FUN_1001e4c0(local_38,puVar4,puVar3);
  local_8._0_1_ = 3;
  FUN_1000aca0(local_cc);
  local_8._0_1_ = 4;
  FUN_1000aca0(local_b0);
  local_8._0_1_ = 5;
  FUN_10022d90(local_54,local_38);
  local_8 = CONCAT31(local_8._1_3_,6);
  iVar7 = 0x40;
  iVar6 = 0xe;
  pcVar5 = (char *)FUN_1001d880(local_54);
  FUN_10018b50((void *)((int)local_1c + 8),pcVar5,iVar6,iVar7);
  cVar1 = FUN_10018b30((int)local_1c + 8);
  if (cVar1 == '\0') {
    uVar2 = FUN_10018580(local_1c,*(short *)((int)local_1c + 0xdc));
    *(undefined2 *)((int)local_1c + 0xdc) = uVar2;
  }
  else {
    FUN_10017f90((int)local_1c);
    std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<
              ((basic_ostream<char,struct_std::char_traits<char>_> *)((int)local_1c + 0x18),
               endl_exref);
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_1001d820(local_54);
  FUN_1001839e();
  return;
}



// Function: Catch@10018391 at 10018391

undefined4 Catch_10018391(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 4;
  return 0x100183a5;
}



// Function: FUN_1001839e at 1001839e

void FUN_1001839e(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 4;
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  FUN_1000aca0((void *)(unaff_EBP - 0x34));
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100183cc;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_100183d0 at 100183d0

void __fastcall FUN_100183d0(void *param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined1 local_cc [28];
  undefined1 local_b0 [92];
  undefined4 local_54 [7];
  undefined4 local_38 [7];
  undefined1 local_19;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f736;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_19 = 0;
  local_18 = param_1;
  cVar1 = FUN_10018b30((int)param_1 + 8);
  if (cVar1 != '\0') {
    FUN_10018bb0((int *)((int)local_18 + 8));
  }
  std::basic_ios<char,struct_std::char_traits<char>_>::clear
            ((basic_ios<char,struct_std::char_traits<char>_> *)
             ((int)local_18 + *(int *)(*(int *)((int)local_18 + 8) + 4) + 8),0,false);
  FUN_10017c40(local_18,local_38);
  local_8 = 0;
  puVar3 = local_38;
  pvVar2 = (void *)FUN_10016c70(local_cc,(undefined4 *)((int)local_18 + 0xc0),L"\\");
  local_8._0_1_ = 1;
  puVar3 = (undefined4 *)FUN_10016740(local_b0,pvVar2,puVar3);
  local_8._0_1_ = 2;
  FUN_10022d90(local_54,puVar3);
  local_8._0_1_ = 4;
  FUN_1000aca0(local_b0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_1000aca0(local_cc);
  iVar6 = 0x40;
  iVar5 = 0x12;
  pcVar4 = (char *)FUN_1001d880(local_54);
  FUN_10018b50((void *)((int)local_18 + 8),pcVar4,iVar5,iVar6);
  cVar1 = FUN_10018b30((int)local_18 + 8);
  if (cVar1 != '\0') {
    FUN_10017f90((int)local_18);
    std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<
              ((basic_ostream<char,struct_std::char_traits<char>_> *)((int)local_18 + 0x18),
               endl_exref);
    local_19 = 1;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_1001d820(local_54);
  local_8 = 0xffffffff;
  FUN_1000aca0(local_38);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018580 at 10018580

undefined2 __thiscall FUN_10018580(void *this,short param_1)

{
  undefined1 local_9;
  
  local_9 = '\0';
  *(undefined2 *)((int)this + 0xdc) = 1;
  while (local_9 == '\0') {
    if (param_1 == *(short *)((int)this + 0xdc)) {
      *(short *)((int)this + 0xdc) = *(short *)((int)this + 0xdc) + 1;
    }
    local_9 = FUN_100183d0(this);
    if (local_9 == '\0') {
      *(short *)((int)this + 0xdc) = *(short *)((int)this + 0xdc) + 1;
    }
  }
  return *(undefined2 *)((int)this + 0xdc);
}



// Function: FUN_10018620 at 10018620

void FUN_10018620(void *param_1)

{
  LPCWSTR lpFileName;
  undefined4 uVar1;
  void *this;
  BOOL BVar2;
  int *piVar3;
  int iVar4;
  _WIN32_FIND_DATAW *lpFindFileData;
  WCHAR *pWVar5;
  undefined1 local_32c [4];
  uint local_328;
  undefined1 local_324 [92];
  DWORD local_2c8;
  DWORD local_2c4;
  DWORD local_2c0;
  DWORD local_2bc;
  undefined4 local_2b8 [7];
  HANDLE local_29c;
  _WIN32_FIND_DATAW local_298;
  undefined1 local_48 [16];
  int local_38;
  undefined1 local_34 [28];
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f7a5;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_328 = 0;
  FUN_10015780(local_34);
  local_8 = 1;
  FUN_10019b00(&local_38);
  FUN_100198b0();
  local_8._0_1_ = 2;
  local_298.dwFileAttributes = 0x80000000;
  local_29c = (HANDLE)0xffffffff;
  FUN_10016c70(local_2b8,(undefined4 *)((int)local_18 + 0xc0),L"\\ialf*.dat");
  local_8._0_1_ = 3;
  lpFindFileData = &local_298;
  lpFileName = (LPCWSTR)FUN_10015940(local_2b8);
  local_29c = FindFirstFileW(lpFileName,lpFindFileData);
  if (local_29c == (HANDLE)0xffffffff) {
    *(undefined2 *)((int)local_18 + 0xdc) = 1;
    uVar1 = FUN_10017c40(local_18,local_324);
    local_8._0_1_ = 4;
    FUN_10015880(local_34,uVar1);
    local_8._0_1_ = 3;
    FUN_1000aca0(local_324);
  }
  else {
    do {
      local_2c0 = local_298.ftLastWriteTime.dwLowDateTime;
      local_2bc = local_298.ftLastWriteTime.dwHighDateTime;
      local_2c8 = local_298.ftLastWriteTime.dwLowDateTime;
      local_2c4 = local_298.ftLastWriteTime.dwHighDateTime;
      pWVar5 = local_298.cFileName;
      this = (void *)FUN_10019920(local_48,&local_2c8);
      FUN_100158e0(this,pWVar5);
      BVar2 = FindNextFileW(local_29c,&local_298);
    } while (BVar2 != 0);
    FindClose(local_29c);
    piVar3 = (int *)FUN_10019ad0(local_48,local_32c);
    local_38 = *piVar3;
    iVar4 = FUN_10019b20(&local_38);
    FUN_100158b0(local_34,(undefined4 *)(iVar4 + 8));
  }
  FUN_100157f0(param_1,(int)local_34);
  local_328 = local_328 | 1;
  local_8._0_1_ = 2;
  FUN_1000aca0(local_2b8);
  local_8._0_1_ = 1;
  FUN_10018830(local_48);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(local_34);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018830 at 10018830

void __fastcall FUN_10018830(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002f7d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10019a70(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018890 at 10018890

void FUN_10018890(void *param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined1 local_7c [92];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f821;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar1 = FUN_100156f0(local_7c,(undefined4 *)&DAT_10044240);
  local_8 = 1;
  local_1c = FUN_10015960((int)pvVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_1000aca0(local_7c);
  iVar2 = FUN_10018960(param_2,(undefined4 *)&DAT_100442b4,0);
  local_20 = iVar2 - local_1c;
  FUN_10015a00(param_1,local_1c,local_20);
  local_8 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10018960 at 10018960

void __thiscall FUN_10018960(void *this,undefined4 *param_1,uint param_2)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = FUN_1000a4d0((int)param_1);
  psVar2 = (short *)FUN_1000a600(param_1);
  FUN_10019c80(this,psVar2,param_2,iVar1);
  return;
}



// Function: FUN_100189a0 at 100189a0

longlong __thiscall FUN_100189a0(void *this,uint *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = FUN_1001dd40((uint *)this);
  lVar2 = FUN_1001dd40(param_1);
  return lVar1 - lVar2;
}



// Function: FUN_100189e0 at 100189e0

basic_iostream<char,struct_std::char_traits<char>_> * __thiscall
FUN_100189e0(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f884;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    *(undefined **)this = &DAT_10037b24;
    *(undefined ***)((int)this + 0x10) = &PTR_10037b1c;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + 0x70));
    local_8 = 0;
  }
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)this,
             (basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18));
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_fstream<char,struct_std::char_traits<char>_>::vftable;
  FUN_10019d10((void *)((int)this + 0x18),(char **)0x0);
  ExceptionList = local_10;
  return (basic_iostream<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10018ab0 at 10018ab0

void __fastcall FUN_10018ab0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002f8b7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(param_1 + -0x70 + *(int *)(*(int *)(param_1 + -0x70) + 4)) =
       std::basic_fstream<char,struct_std::char_traits<char>_>::vftable;
  local_8 = 0;
  FUN_10018bf0((basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + -0x58));
  local_8 = 0xffffffff;
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)(param_1 + -0x58));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018b30 at 10018b30

void __fastcall FUN_10018b30(int param_1)

{
  FUN_10019d80(param_1 + 0x18);
  return;
}



// Function: FUN_10018b50 at 10018b50

void __thiscall FUN_10018b50(void *this,char *param_1,int param_2,int param_3)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = FUN_10019db0((void *)((int)this + 0x18),param_1,param_2,param_3);
  if (pbVar1 == (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
                    /* WARNING: Load size is inaccurate */
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + *(int *)(*this + 4)),2
               ,false);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    std::basic_ios<char,struct_std::char_traits<char>_>::clear
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + *(int *)(*this + 4)),0
               ,false);
  }
  return;
}



// Function: FUN_10018bb0 at 10018bb0

void __fastcall FUN_10018bb0(int *param_1)

{
  int *piVar1;
  
  piVar1 = FUN_10019e70(param_1 + 6);
  if (piVar1 == (int *)0x0) {
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               ((int)param_1 + *(int *)(*param_1 + 4)),2,false);
  }
  return;
}



// Function: FUN_10018bf0 at 10018bf0

void __fastcall FUN_10018bf0(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002f8e9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  local_8 = 0;
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_1001a220(param_1);
  }
  if (param_1[0x50] != (basic_streambuf<char,struct_std::char_traits<char>_>)0x0) {
    FUN_10019e70((int *)param_1);
  }
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10018c80 at 10018c80

void __fastcall FUN_10018c80(int param_1)

{
  if (*(int *)(param_1 + 0x54) != 0) {
    _lock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_10018cb0 at 10018cb0

void __fastcall FUN_10018cb0(int param_1)

{
  if (*(int *)(param_1 + 0x54) != 0) {
    _unlock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_10018ce0 at 10018ce0

void FUN_10018ce0(uint param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  void *_Str;
  uint uVar8;
  size_t sVar9;
  size_t _Size;
  char **ppcVar10;
  FILE *pFVar11;
  uint local_b4;
  int local_b0;
  undefined1 local_ac [4];
  undefined1 local_a8 [4];
  undefined1 local_a4 [4];
  undefined1 local_a0 [4];
  undefined4 local_9c;
  uint local_98;
  undefined4 local_94;
  uint local_90;
  undefined4 local_8c;
  size_t local_48;
  undefined1 local_44 [28];
  char *local_28;
  char *local_24;
  char local_1e;
  char local_1d [5];
  basic_streambuf<char,struct_std::char_traits<char>_> *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f918;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_b0 = FUN_1001d5f0();
  bVar1 = FUN_1001d590(&local_b0,(int *)&param_1);
  if (bVar1) {
    FUN_1001d5b0(&param_1);
  }
  else {
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_18);
    if (pcVar3 != (char *)0x0) {
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_18);
      pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(local_18);
      if (pcVar3 < pcVar4) {
        cVar2 = FUN_1001d550((undefined1 *)&param_1);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc(local_18);
        *pcVar3 = cVar2;
        goto LAB_10019034;
      }
    }
    if (*(int *)(local_18 + 0x54) == 0) {
      FUN_1001d5f0();
    }
    else {
      FUN_1001a220(local_18);
      if (*(int *)(local_18 + 0x44) == 0) {
        pFVar11 = *(FILE **)(local_18 + 0x54);
        cVar2 = FUN_1001d550((undefined1 *)&param_1);
        bVar1 = FUN_1001d750(cVar2,pFVar11);
        if (!bVar1) {
          FUN_1001d5f0();
        }
      }
      else {
        local_1d[1] = '\b';
        local_1d[2] = '\0';
        local_1d[3] = '\0';
        local_1d[4] = '\0';
        local_1e = FUN_1001d550((undefined1 *)&param_1);
        FUN_1001d8c0(local_44,8,'\0');
        local_8 = 0;
        while( true ) {
          ppcVar10 = &local_28;
          puVar5 = (undefined4 *)FUN_1001da90(local_44,local_ac);
          iVar6 = FUN_1001dc30(puVar5);
          iVar7 = FUN_1001d8a0((int)local_44);
          pcVar4 = (char *)(iVar6 + iVar7);
          puVar5 = (undefined4 *)FUN_1001da90(local_44,local_a8);
          pcVar3 = (char *)FUN_1001dc30(puVar5);
          iVar6 = std::codecvt<char,char,int>::out
                            (*(codecvt<char,char,int> **)(local_18 + 0x44),(int *)(local_18 + 0x4c),
                             &local_1e,local_1d,&local_24,pcVar3,pcVar4,ppcVar10);
          if (iVar6 < 0) break;
          if (1 < iVar6) {
            if (iVar6 == 3) {
              bVar1 = FUN_1001d750(local_1e,*(FILE **)(local_18 + 0x54));
              if (bVar1) {
                local_b4 = param_1;
              }
              else {
                local_b4 = FUN_1001d5f0();
              }
              local_90 = local_b4;
              local_8 = 0xffffffff;
              FUN_1001d820(local_44);
              goto LAB_10019034;
            }
            break;
          }
          puVar5 = (undefined4 *)FUN_1001da90(local_44,local_a4);
          iVar6 = FUN_1001dc30(puVar5);
          sVar9 = (int)local_28 - iVar6;
          local_48 = sVar9;
          if (sVar9 != 0) {
            pFVar11 = *(FILE **)(local_18 + 0x54);
            _Size = 1;
            puVar5 = (undefined4 *)FUN_1001da90(local_44,local_a0);
            _Str = (void *)FUN_1001dc30(puVar5);
            sVar9 = fwrite(_Str,_Size,sVar9,pFVar11);
            if (local_48 != sVar9) {
              local_9c = FUN_1001d5f0();
              local_8 = 0xffffffff;
              FUN_1001d820(local_44);
              goto LAB_10019034;
            }
          }
          local_18[0x49] = (basic_streambuf<char,struct_std::char_traits<char>_>)0x1;
          if (local_24 != &local_1e) {
            local_98 = param_1;
            local_8 = 0xffffffff;
            FUN_1001d820(local_44);
            goto LAB_10019034;
          }
          if (local_48 == 0) {
            uVar8 = FUN_1001d8a0((int)local_44);
            if (0x1f < uVar8) {
              local_94 = FUN_1001d5f0();
              local_8 = 0xffffffff;
              FUN_1001d820(local_44);
              goto LAB_10019034;
            }
            FUN_1001d940(local_44,8,'\0');
          }
        }
        local_8c = FUN_1001d5f0();
        local_8 = 0xffffffff;
        FUN_1001d820(local_44);
      }
    }
  }
LAB_10019034:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10019060 at 10019060

uint __thiscall FUN_10019060(void *this,uint param_1)

{
  bool bVar1;
  undefined1 uVar2;
  basic_streambuf<char,struct_std::char_traits<char>_> bVar3;
  char *pcVar4;
  char *pcVar5;
  undefined3 extraout_var;
  uint uVar6;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar7;
  int local_58;
  int local_54;
  int local_50;
  byte local_49 [65];
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_8 = (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
  pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (pcVar4 != (char *)0x0) {
    pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(local_8);
    pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
    if (pcVar4 < pcVar5) {
      local_58 = FUN_1001d5f0();
      bVar1 = FUN_1001d590(&local_58,(int *)&param_1);
      if (!bVar1) {
        pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
        uVar2 = FUN_1001d570(pcVar4 + -1);
        local_54 = CONCAT31(extraout_var,uVar2);
        bVar1 = FUN_1001d590(&local_54,(int *)&param_1);
        if (!bVar1) goto LAB_10019102;
      }
      std::basic_streambuf<char,struct_std::char_traits<char>_>::_Gndec(local_8);
      uVar6 = FUN_1001d5b0(&param_1);
      return uVar6;
    }
  }
LAB_10019102:
  if (*(int *)(local_8 + 0x54) != 0) {
    local_50 = FUN_1001d5f0();
    bVar1 = FUN_1001d590(&local_50,(int *)&param_1);
    if (!bVar1) {
      if (*(int *)(local_8 + 0x44) == 0) {
        local_49[0] = FUN_1001d550((undefined1 *)&param_1);
        bVar1 = FUN_1001d780(local_49,*(FILE **)(local_8 + 0x54));
        if (bVar1) {
          return param_1;
        }
      }
      pbVar7 = (basic_streambuf<char,struct_std::char_traits<char>_> *)
               std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
      if (pbVar7 != local_8 + 0x48) {
        bVar3 = (basic_streambuf<char,struct_std::char_traits<char>_>)
                FUN_1001d550((undefined1 *)&param_1);
        local_8[0x48] = bVar3;
        FUN_1001a270(local_8);
        return param_1;
      }
      uVar6 = FUN_1001d5f0();
      return uVar6;
    }
  }
  uVar6 = FUN_1001d5f0();
  return uVar6;
}



// Function: FUN_100191b0 at 100191b0

uint __fastcall FUN_100191b0(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  undefined1 uVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  undefined3 extraout_var;
  int local_50 [17];
  uint local_c;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_8 = param_1;
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
    pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(local_8);
    if (pcVar3 < pcVar4) {
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
      uVar1 = FUN_1001d570(pcVar3);
      return CONCAT31(extraout_var,uVar1);
    }
  }
  local_c = (**(code **)(*(int *)local_8 + 0x1c))();
  local_50[0] = FUN_1001d5f0();
  bVar2 = FUN_1001d590(local_50,(int *)&local_c);
  if (!bVar2) {
    (**(code **)(*(int *)local_8 + 0x10))(local_c);
  }
  return local_c;
}



// Function: FUN_10019250 at 10019250

void __fastcall FUN_10019250(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  bool bVar1;
  undefined1 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined3 extraout_var;
  void *_Src;
  undefined3 extraout_var_00;
  char *pcVar9;
  char **ppcVar10;
  char **ppcVar11;
  rsize_t _MaxCount;
  undefined1 local_ac [4];
  undefined1 local_a8 [4];
  undefined1 local_a4 [4];
  undefined4 local_a0;
  undefined1 local_9c [4];
  undefined1 local_98 [4];
  undefined4 local_94;
  undefined4 local_90;
  int local_4c;
  int local_48;
  char *local_44;
  char *local_40;
  char local_3a;
  char local_39;
  undefined1 local_38 [31];
  undefined1 local_19;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f948;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_18);
    pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(local_18);
    if (pcVar3 < pcVar4) {
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Gninc(local_18);
      FUN_1001d570(pcVar3);
      goto LAB_10019567;
    }
  }
  if (*(int *)(local_18 + 0x54) == 0) {
    FUN_1001d5f0();
  }
  else {
    FUN_1001a220(local_18);
    if (*(int *)(local_18 + 0x44) == 0) {
      local_19 = 0;
      bVar1 = FUN_1001d710(&local_19,*(FILE **)(local_18 + 0x54));
      if (bVar1) {
        FUN_1001d570(&local_19);
      }
      else {
        FUN_1001d5f0();
      }
    }
    else {
      FUN_1001d7b0(local_38);
      local_8 = 0;
LAB_1001933f:
      do {
        local_4c = fgetc(*(FILE **)(local_18 + 0x54));
        if (local_4c == -1) {
          FUN_1001d5f0();
          local_8 = 0xffffffff;
          FUN_1001d820(local_38);
          goto LAB_10019567;
        }
        FUN_1001d940(local_38,1,(char)local_4c);
        ppcVar11 = &local_40;
        pcVar3 = &local_39;
        pcVar4 = &local_3a;
        ppcVar10 = &local_44;
        puVar5 = (undefined4 *)FUN_1001da90(local_38,local_ac);
        iVar6 = FUN_1001dc30(puVar5);
        iVar7 = FUN_1001d8a0((int)local_38);
        pcVar9 = (char *)(iVar6 + iVar7);
        puVar5 = (undefined4 *)FUN_1001da90(local_38,local_a8);
        pcVar8 = (char *)FUN_1001dc30(puVar5);
        iVar6 = std::codecvt<char,char,int>::in
                          (*(codecvt<char,char,int> **)(local_18 + 0x44),(int *)(local_18 + 0x4c),
                           pcVar8,pcVar9,ppcVar10,pcVar4,pcVar3,ppcVar11);
        if (iVar6 < 0) {
LAB_10019531:
          local_90 = FUN_1001d5f0();
          local_8 = 0xffffffff;
          FUN_1001d820(local_38);
          goto LAB_10019567;
        }
        if (iVar6 < 2) {
          if (local_40 != &local_3a) {
            puVar5 = (undefined4 *)FUN_1001da90(local_38,local_a4);
            iVar6 = FUN_1001dc30(puVar5);
            iVar7 = FUN_1001d8a0((int)local_38);
            local_48 = (iVar6 + iVar7) - (int)local_44;
            while (0 < local_48) {
              local_48 = local_48 + -1;
              ungetc((int)local_44[local_48],*(FILE **)(local_18 + 0x54));
            }
            uVar2 = FUN_1001d570(&local_3a);
            local_a0 = CONCAT31(extraout_var,uVar2);
            local_8 = 0xffffffff;
            FUN_1001d820(local_38);
            goto LAB_10019567;
          }
          puVar5 = (undefined4 *)FUN_1001da90(local_38,local_9c);
          iVar6 = FUN_1001dc30(puVar5);
          FUN_1001d9c0(local_38,0,(int)local_44 - iVar6);
          goto LAB_1001933f;
        }
        if (iVar6 != 3) goto LAB_10019531;
        iVar6 = FUN_1001d8a0((int)local_38);
      } while (iVar6 == 0);
      _MaxCount = 1;
      puVar5 = (undefined4 *)FUN_1001da90(local_38,local_98);
      _Src = (void *)FUN_1001dc30(puVar5);
      memcpy_s(&local_3a,1,_Src,_MaxCount);
      uVar2 = FUN_1001d570(&local_3a);
      local_94 = CONCAT31(extraout_var_00,uVar2);
      local_8 = 0xffffffff;
      FUN_1001d820(local_38);
    }
  }
LAB_10019567:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10019590 at 10019590

void * __thiscall FUN_10019590(void *this,void *param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar2;
  int iVar3;
  int unaff_EDI;
  bool bVar4;
  undefined4 local_10;
  undefined4 local_c;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_8 = (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
  pbVar2 = (basic_streambuf<char,struct_std::char_traits<char>_> *)
           std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (((pbVar2 == local_8 + 0x48) && (param_4 == 1)) && (*(int *)(local_8 + 0x44) == 0)) {
    bVar4 = param_2 == 0;
    param_2 = param_2 + -1;
    param_3 = param_3 - (uint)bVar4;
  }
  if ((((*(int *)(local_8 + 0x54) != 0) && (cVar1 = FUN_10019f90((int *)local_8), cVar1 != '\0')) &&
      (((param_2 == 0 && param_3 == 0 && (param_4 == 1)) ||
       (iVar3 = _fseeki64(*(FILE **)(local_8 + 0x54),CONCAT44(param_4,param_3),unaff_EDI),
       iVar3 == 0)))) &&
     (iVar3 = fgetpos(*(FILE **)(local_8 + 0x54),(fpos_t *)&local_10), iVar3 == 0)) {
    FUN_1001a220(local_8);
    FUN_1001dcc0(param_1,*(undefined4 *)(local_8 + 0x4c),local_10,local_c);
    return param_1;
  }
  FUN_1001dc70(param_1,*(undefined4 *)_BADOFF_exref,*(undefined4 *)(_BADOFF_exref + 4));
  return param_1;
}



// Function: FUN_10019680 at 10019680

void * FUN_10019680(void *param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EDI;
  longlong lVar5;
  undefined4 local_14;
  undefined8 local_10;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_10 = FUN_1001dd20((int)&stack0x00000008);
  lVar5 = FUN_1001dd40((uint *)&stack0x00000008);
  lVar1 = (longlong)(int)local_10;
  if ((((*(int *)(local_8 + 0x54) != 0) && (cVar2 = FUN_10019f90((int *)local_8), cVar2 != '\0')) &&
      (iVar3 = fsetpos(*(FILE **)(local_8 + 0x54),&local_10), iVar3 == 0)) &&
     (((local_14 = (undefined4)((ulonglong)(lVar5 - lVar1) >> 0x20), lVar5 - lVar1 == 0 ||
       (iVar3 = _fseeki64(*(FILE **)(local_8 + 0x54),CONCAT44(1,local_14),unaff_EDI), iVar3 == 0))
      && (iVar3 = fgetpos(*(FILE **)(local_8 + 0x54),&local_10), iVar3 == 0)))) {
    uVar4 = FUN_1001dd00((int)&stack0x00000008);
    *(undefined4 *)(local_8 + 0x4c) = uVar4;
    FUN_1001a220(local_8);
    FUN_1001dcc0(param_1,*(undefined4 *)(local_8 + 0x4c),(int)local_10,local_10._4_4_);
    return param_1;
  }
  FUN_1001dc70(param_1,*(undefined4 *)_BADOFF_exref,*(undefined4 *)(_BADOFF_exref + 4));
  return param_1;
}



// Function: FUN_10019780 at 10019780

void * __thiscall FUN_10019780(void *this,char *param_1,size_t param_2,int param_3)

{
  int iVar1;
  int local_4c;
  
  if (*(int *)((int)this + 0x54) != 0) {
    if ((param_1 == (char *)0x0) && (param_2 == 0 && param_3 == 0)) {
      local_4c = 4;
    }
    else {
      local_4c = 0;
    }
    iVar1 = setvbuf(*(FILE **)((int)this + 0x54),param_1,local_4c,param_2);
    if (iVar1 == 0) {
      FUN_10019ee0(this,*(char ***)((int)this + 0x54),1);
      return this;
    }
  }
  return (void *)0x0;
}



// Function: FUN_10019800 at 10019800

undefined4 __fastcall FUN_10019800(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_50;
  int local_4c [17];
  int *local_8;
  
  if (param_1[0x15] != 0) {
    local_8 = param_1;
    uVar2 = FUN_1001d5f0();
    local_50 = (**(code **)(*local_8 + 0xc))(uVar2);
    local_4c[0] = FUN_1001d5f0();
    bVar1 = FUN_1001d590(local_4c,&local_50);
    if ((!bVar1) && (iVar3 = fflush((FILE *)local_8[0x15]), iVar3 < 0)) {
      return 0xffffffff;
    }
  }
  return 0;
}



// Function: FUN_10019880 at 10019880

void __thiscall FUN_10019880(void *this,locale *param_1)

{
  facet *pfVar1;
  
  pfVar1 = FUN_1001c0a0(param_1);
  FUN_1001a1d0(this,(codecvt_base *)pfVar1);
  return;
}



// Function: FUN_100198b0 at 100198b0

int FUN_100198b0(void)

{
  undefined1 local_56 [66];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f978;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001a470(local_56);
  FUN_1001a2e0(local_14);
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_10019920 at 10019920

void __thiscall FUN_10019920(void *this,uint *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  void *pvVar6;
  undefined1 local_ac [4];
  int local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [28];
  undefined1 local_84 [104];
  int local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f9b3;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = this;
  FUN_1001a380(this,&local_1c,param_1);
  piVar3 = (int *)FUN_1001a350(local_18,local_ac);
  bVar1 = FUN_1001a530(&local_1c,piVar3);
  if (!bVar1) {
    iVar4 = FUN_1001a560(&local_1c);
    puVar5 = (uint *)FUN_1001a440(iVar4);
    cVar2 = FUN_1001a490(param_1,puVar5);
    if (cVar2 == '\0') goto LAB_10019a3f;
  }
  local_a8 = local_1c;
  pvVar6 = FUN_10015780(local_a0);
  local_8 = 0;
  pvVar6 = FUN_1001a5d0(local_84,param_1,pvVar6);
  local_8._0_1_ = 1;
  piVar3 = FUN_1001c1a0(local_18,&local_a4,local_a8,pvVar6);
  local_1c = *piVar3;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10019bc0((int)local_84);
  local_8 = 0xffffffff;
  FUN_1000aca0(local_a0);
LAB_10019a3f:
  FUN_1001a510(&local_1c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10019a70 at 10019a70

void __fastcall FUN_10019a70(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002f9e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1001a3c0(param_1);
  local_8 = 0xffffffff;
  FUN_1001a410((int)param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10019ad0 at 10019ad0

void * __thiscall FUN_10019ad0(void *this,void *param_1)

{
  undefined4 *puVar1;
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = this;
  puVar1 = (undefined4 *)FUN_1001a350(this,local_4c);
  FUN_1001a4e0(param_1,*puVar1);
  return param_1;
}



// Function: FUN_10019b00 at 10019b00

undefined4 * __fastcall FUN_10019b00(undefined4 *param_1)

{
  FUN_1001a580(param_1);
  return param_1;
}



// Function: FUN_10019b20 at 10019b20

void __fastcall FUN_10019b20(int *param_1)

{
  FUN_1001a5a0(param_1);
  return;
}



// Function: FUN_10019b40 at 10019b40

int __thiscall FUN_10019b40(void *this,uint param_1)

{
  FUN_10017b70((int)this + -0x70);
  if ((param_1 & 1) != 0) {
    operator_delete((void *)((int)this + -0x70));
  }
  return (int)this + -0x70;
}



// Function: FUN_10019b80 at 10019b80

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10019b80(void *this,uint param_1)

{
  FUN_10018bf0((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10019bc0 at 10019bc0

void __fastcall FUN_10019bc0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002fa18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10019c20(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10019c20 at 10019c20

void __fastcall FUN_10019c20(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002fa4b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1000aca0((void *)(param_1 + 8));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10019c80 at 10019c80

int __thiscall FUN_10019c80(void *this,short *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  short *local_10;
  
  if ((param_3 != 0) && (param_2 < *(uint *)((int)this + 0x10))) {
    puVar2 = FUN_1000a600((undefined4 *)this);
    iVar1 = *(int *)((int)this + 0x10);
    puVar3 = FUN_1000a600((undefined4 *)this);
    for (local_10 = (short *)((int)puVar3 + param_2 * 2);
        local_10 < (short *)((int)puVar2 + iVar1 * 2); local_10 = local_10 + 1) {
      iVar4 = FUN_10015fc0(param_1,param_3,local_10);
      if (iVar4 != 0) {
        puVar2 = FUN_1000a600((undefined4 *)this);
        return (int)local_10 - (int)puVar2 >> 1;
      }
    }
  }
  return -1;
}



// Function: FUN_10019d10 at 10019d10

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10019d10(void *this,char **param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fa79;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  local_8 = 0;
  *(undefined ***)this = std::basic_filebuf<char,struct_std::char_traits<char>_>::vftable;
  FUN_10019ee0(this,param_1,0);
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10019d80 at 10019d80

bool __fastcall FUN_10019d80(int param_1)

{
  return *(int *)(param_1 + 0x54) != 0;
}



// Function: FUN_10019db0 at 10019db0

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10019db0(void *this,char *param_1,int param_2,int param_3)

{
  locale *plVar1;
  facet *pfVar2;
  int local_5c [17];
  _iobuf *local_18;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002faa8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)((int)this + 0x54) == 0) &&
     (local_14 = (basic_streambuf<char,struct_std::char_traits<char>_> *)this,
     local_18 = std::_Fiopen(param_1,param_2,param_3), local_18 != (_iobuf *)0x0)) {
    FUN_10019ee0(local_14,&local_18->_ptr,1);
    plVar1 = (locale *)std::basic_streambuf<char,struct_std::char_traits<char>_>::getloc(local_14);
    local_8 = 0;
    pfVar2 = FUN_1001c0a0(plVar1);
    FUN_1001a1d0(local_14,(codecvt_base *)pfVar2);
    local_8 = 0xffffffff;
    FUN_1001d630(local_5c);
    ExceptionList = local_10;
    return local_14;
  }
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0;
}



// Function: FUN_10019e70 at 10019e70

int * __fastcall FUN_10019e70(int *param_1)

{
  char cVar1;
  int iVar2;
  int *local_c;
  
  if (param_1[0x15] == 0) {
    local_c = (int *)0x0;
  }
  else {
    cVar1 = FUN_10019f90(param_1);
    local_c = param_1;
    if (cVar1 == '\0') {
      local_c = (int *)0x0;
    }
    iVar2 = fclose((FILE *)param_1[0x15]);
    if (iVar2 != 0) {
      local_c = (int *)0x0;
    }
  }
  FUN_10019ee0(param_1,(char **)0x0,2);
  return local_c;
}



// Function: FUN_10019ee0 at 10019ee0

void __thiscall FUN_10019ee0(void *this,char **param_1,int param_2)

{
  *(bool *)((int)this + 0x50) = param_2 == 1;
  *(undefined1 *)((int)this + 0x49) = 0;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if (param_1 != (char **)0x0) {
    std::basic_streambuf<char,struct_std::char_traits<char>_>::_Init
              ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,param_1 + 2,param_1,
               (int *)(param_1 + 1),param_1 + 2,param_1,(int *)(param_1 + 1));
  }
  *(char ***)((int)this + 0x54) = param_1;
  *(undefined4 *)((int)this + 0x4c) = DAT_10044238;
  *(undefined4 *)((int)this + 0x44) = 0;
  return;
}



// Function: FUN_10019f90 at 10019f90

void __fastcall FUN_10019f90(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  void *_Str;
  size_t sVar8;
  char *pcVar9;
  size_t _Size;
  char **ppcVar10;
  FILE *_File;
  int local_9c;
  int local_98;
  undefined1 local_94 [4];
  undefined1 local_90 [4];
  undefined1 local_8c [4];
  undefined1 local_88 [4];
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  undefined1 local_81;
  size_t local_40;
  undefined1 local_3c [28];
  char *local_20;
  undefined4 local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fad8;
  local_10 = ExceptionList;
  uVar2 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = param_1;
  local_14 = uVar2;
  if ((param_1[0x11] != 0) && (*(char *)((int)param_1 + 0x49) != '\0')) {
    local_1c = 8;
    uVar3 = FUN_1001d5f0();
    local_9c = (**(code **)(*local_18 + 0xc))(uVar3,uVar2);
    local_98 = FUN_1001d5f0();
    bVar1 = FUN_1001d590(&local_98,&local_9c);
    if (!bVar1) {
      FUN_1001d8c0(local_3c,8,'\0');
      local_8 = 0;
      while( true ) {
        ppcVar10 = &local_20;
        puVar4 = (undefined4 *)FUN_1001da90(local_3c,local_94);
        iVar5 = FUN_1001dc30(puVar4);
        iVar6 = FUN_1001d8a0((int)local_3c);
        pcVar9 = (char *)(iVar5 + iVar6);
        puVar4 = (undefined4 *)FUN_1001da90(local_3c,local_90);
        pcVar7 = (char *)FUN_1001dc30(puVar4);
        iVar5 = std::codecvt<char,char,int>::unshift
                          ((codecvt<char,char,int> *)local_18[0x11],local_18 + 0x13,pcVar7,pcVar9,
                           ppcVar10);
        if (iVar5 == 0) {
          *(undefined1 *)((int)local_18 + 0x49) = 0;
        }
        else if (iVar5 != 1) {
          if (iVar5 == 3) {
            local_82 = 1;
            local_8 = 0xffffffff;
            FUN_1001d820(local_3c);
          }
          else {
            local_81 = 0;
            local_8 = 0xffffffff;
            FUN_1001d820(local_3c);
          }
          goto LAB_1001a1aa;
        }
        puVar4 = (undefined4 *)FUN_1001da90(local_3c,local_8c);
        iVar5 = FUN_1001dc30(puVar4);
        sVar8 = (int)local_20 - iVar5;
        local_40 = sVar8;
        if (sVar8 != 0) {
          _File = (FILE *)local_18[0x15];
          _Size = 1;
          puVar4 = (undefined4 *)FUN_1001da90(local_3c,local_88);
          _Str = (void *)FUN_1001dc30(puVar4);
          sVar8 = fwrite(_Str,_Size,sVar8,_File);
          if (local_40 != sVar8) {
            local_84 = 0;
            local_8 = 0xffffffff;
            FUN_1001d820(local_3c);
            goto LAB_1001a1aa;
          }
        }
        if (*(char *)((int)local_18 + 0x49) == '\0') break;
        if (local_40 == 0) {
          FUN_1001d940(local_3c,8,'\0');
        }
      }
      local_83 = 1;
      local_8 = 0xffffffff;
      FUN_1001d820(local_3c);
    }
  }
LAB_1001a1aa:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001a1d0 at 1001a1d0

void __thiscall FUN_1001a1d0(void *this,codecvt_base *param_1)

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



// Function: FUN_1001a220 at 1001a220

void __fastcall FUN_1001a220(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = (basic_streambuf<char,struct_std::char_traits<char>_> *)
           std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
  if (pbVar1 == param_1 + 0x48) {
    std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
              (param_1,*(char **)(param_1 + 0x3c),*(char **)(param_1 + 0x40),
               *(char **)(param_1 + 0x40));
  }
  return;
}



// Function: FUN_1001a270 at 1001a270

void __fastcall FUN_1001a270(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  char *pcVar2;
  
  pbVar1 = (basic_streambuf<char,struct_std::char_traits<char>_> *)
           std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
  if (pbVar1 != param_1 + 0x48) {
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    *(char **)(param_1 + 0x3c) = pcVar2;
    pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
    *(char **)(param_1 + 0x40) = pcVar2;
  }
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
            (param_1,(char *)(param_1 + 0x48),(char *)(param_1 + 0x48),(char *)(param_1 + 0x49));
  return;
}



// Function: FUN_1001a2e0 at 1001a2e0

int __fastcall FUN_1001a2e0(int param_1)

{
  int iStack_6c;
  uint uStack_68;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fb08;
  local_10 = ExceptionList;
  uStack_68 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iStack_6c = param_1;
  FUN_1001a890(&iStack_6c);
  FUN_1001a7b0(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001a350 at 1001a350

void * __thiscall FUN_1001a350(void *this,void *param_1)

{
  FUN_1001a900(param_1,*(undefined4 *)((int)this + 4));
  return param_1;
}



// Function: FUN_1001a380 at 1001a380

void * __thiscall FUN_1001a380(void *this,void *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1001a720(this,param_2);
  FUN_1001a900(param_1,iVar1);
  return param_1;
}



// Function: FUN_1001a3c0 at 1001a3c0

void __fastcall FUN_1001a3c0(void *param_1)

{
  undefined4 *puVar1;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = param_1;
  FUN_1001a350(param_1,local_58);
  puVar1 = (undefined4 *)FUN_1001a640(local_8,local_50);
  local_54 = *puVar1;
  FUN_1001a670(local_8,local_4c,local_54);
  return;
}



// Function: FUN_1001a410 at 1001a410

void __fastcall FUN_1001a410(int param_1)

{
  FUN_1001a8b0(*(void **)(param_1 + 4));
  return;
}



// Function: FUN_1001a440 at 1001a440

void __cdecl FUN_1001a440(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1001a870(param_1);
  FUN_1001c1e0(iVar1);
  return;
}



// Function: FUN_1001a470 at 1001a470

undefined4 __fastcall FUN_1001a470(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001a490 at 1001a490

undefined1 FUN_1001a490(uint *param_1,uint *param_2)

{
  undefined1 local_54;
  
  if (((int)param_2[1] < (int)param_1[1]) ||
     (((int)param_2[1] <= (int)param_1[1] && (*param_2 <= *param_1)))) {
    local_54 = 0;
  }
  else {
    local_54 = 1;
  }
  return local_54;
}



// Function: FUN_1001a4e0 at 1001a4e0

void * __thiscall FUN_1001a4e0(void *this,undefined4 param_1)

{
  FUN_1001a980(this,param_1);
  return this;
}



// Function: FUN_1001a510 at 1001a510

void __fastcall FUN_1001a510(int *param_1)

{
  FUN_1001a950(param_1);
  return;
}



// Function: FUN_1001a530 at 1001a530

bool __thiscall FUN_1001a530(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == *param_1;
}



// Function: FUN_1001a560 at 1001a560

undefined4 __fastcall FUN_1001a560(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1001a580 at 1001a580

undefined4 * __fastcall FUN_1001a580(undefined4 *param_1)

{
  FUN_1001a8e0(param_1);
  return param_1;
}



// Function: FUN_1001a5a0 at 1001a5a0

void __fastcall FUN_1001a5a0(int *param_1)

{
  int *piVar1;
  int local_c;
  int *local_8;
  
  local_c = *param_1;
  local_8 = param_1;
  piVar1 = FUN_1001a930(&local_c);
  FUN_1001a510(piVar1);
  return;
}



// Function: FUN_1001a5d0 at 1001a5d0

void * __thiscall FUN_1001a5d0(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fb38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10016bf0(param_2);
  FUN_1001a9a0(this,param_1,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001a640 at 1001a640

void * __thiscall FUN_1001a640(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1001b210((int)this);
  FUN_1001a900(param_1,*puVar1);
  return param_1;
}



// Function: FUN_1001a670 at 1001a670

/* WARNING: Variable defined which should be unmapped: param_2 */

void * __thiscall FUN_1001a670(void *param_1,void *param_2,undefined4 param_3)

{
  bool bVar1;
  int *piVar2;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  int local_50;
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = param_1;
  piVar2 = (int *)FUN_1001a640(param_1,local_58);
  bVar1 = FUN_1001a530(&param_3,piVar2);
  if (bVar1) {
    piVar2 = (int *)FUN_1001a350(local_8,local_54);
    bVar1 = FUN_1001a530(&stack0x0000000c,piVar2);
    if (bVar1) {
      FUN_1001b1b0(local_8);
      FUN_1001a640(local_8,param_2);
      return param_2;
    }
  }
  while (bVar1 = FUN_1001b430(&param_3,(int *)&stack0x0000000c), bVar1) {
    piVar2 = FUN_1001b3e0(&param_3,&local_50);
    FUN_1001aa20(local_8,local_4c,*piVar2);
  }
  FUN_1001a900(param_2,param_3);
  return param_2;
}



// Function: FUN_1001a720 at 1001a720

int __thiscall FUN_1001a720(void *this,uint *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  uint *puVar4;
  uint *puVar5;
  int local_10;
  int local_c;
  
  piVar2 = (int *)FUN_1001b240((int)this);
  local_c = *piVar2;
  local_10 = *(int *)((int)this + 4);
  while (pcVar3 = (char *)FUN_1001b290(local_c), *pcVar3 == '\0') {
    puVar5 = param_1;
    puVar4 = (uint *)FUN_1001a440(local_c);
    cVar1 = FUN_1001a490(puVar4,puVar5);
    if (cVar1 == '\0') {
      local_10 = local_c;
      piVar2 = (int *)FUN_1001b2b0(local_c);
      local_c = *piVar2;
    }
    else {
      piVar2 = (int *)FUN_1001b2f0(local_c);
      local_c = *piVar2;
    }
  }
  return local_10;
}



// Function: FUN_1001a7b0 at 1001a7b0

int __fastcall FUN_1001a7b0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  FUN_1001a890(&stack0xffffffa4);
  FUN_1001b310(param_1);
  *(undefined4 *)(param_1 + 8) = 0;
  uVar1 = FUN_1001b360(1);
  *(undefined4 *)(param_1 + 4) = uVar1;
  puVar2 = (undefined4 *)FUN_1001b2b0(*(undefined4 *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1001b2d0(*(int *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1001b2f0(*(int *)(param_1 + 4));
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined1 *)FUN_1001b270(*(int *)(param_1 + 4));
  *puVar3 = 1;
  puVar3 = (undefined1 *)FUN_1001b290(*(int *)(param_1 + 4));
  *puVar3 = 1;
  return param_1;
}



// Function: FUN_1001a870 at 1001a870

int __cdecl FUN_1001a870(int param_1)

{
  return param_1 + 0x10;
}



// Function: FUN_1001a890 at 1001a890

undefined4 __fastcall FUN_1001a890(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001a8b0 at 1001a8b0

void FUN_1001a8b0(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1001a8e0 at 1001a8e0

undefined4 * __fastcall FUN_1001a8e0(undefined4 *param_1)

{
  FUN_1001b390(param_1);
  return param_1;
}



// Function: FUN_1001a900 at 1001a900

void * __thiscall FUN_1001a900(void *this,undefined4 param_1)

{
  FUN_1001b3b0(this,param_1);
  return this;
}



// Function: FUN_1001a930 at 1001a930

int * __fastcall FUN_1001a930(int *param_1)

{
  FUN_1001b410(param_1);
  return param_1;
}



// Function: FUN_1001a950 at 1001a950

void __fastcall FUN_1001a950(int *param_1)

{
  FUN_1001a870(*param_1);
  return;
}



// Function: FUN_1001a980 at 1001a980

undefined4 * __thiscall FUN_1001a980(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1001a9a0 at 1001a9a0

undefined4 * __thiscall FUN_1001a9a0(void *this,undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fb6b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 4) = param_1[1];
  iVar1 = FUN_10016bf0(param_2);
  FUN_100157f0((void *)((int)this + 8),iVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001aa20 at 1001aa20

void * __thiscall FUN_1001aa20(void *this,void *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  void *pvVar9;
  void *local_5c;
  void *local_18;
  void *local_14;
  void *local_10;
  
  iVar1 = FUN_1001a560(&param_2);
  pcVar2 = (char *)FUN_1001b290(iVar1);
  if (*pcVar2 != '\0') {
    std::_Xout_of_range("invalid map/set<T> iterator");
  }
  pvVar3 = (void *)FUN_1001a560(&param_2);
  FUN_1001b870(&param_2);
  piVar4 = (int *)FUN_1001b2b0(pvVar3);
  pcVar2 = (char *)FUN_1001b290(*piVar4);
  local_18 = pvVar3;
  if (*pcVar2 == '\0') {
    piVar4 = (int *)FUN_1001b2f0((int)pvVar3);
    pcVar2 = (char *)FUN_1001b290(*piVar4);
    if (*pcVar2 == '\0') {
      local_18 = (void *)FUN_1001a560(&param_2);
      puVar5 = (undefined4 *)FUN_1001b2f0((int)local_18);
      local_10 = (void *)*puVar5;
    }
    else {
      puVar5 = (undefined4 *)FUN_1001b2b0(pvVar3);
      local_10 = (void *)*puVar5;
    }
  }
  else {
    puVar5 = (undefined4 *)FUN_1001b2f0((int)pvVar3);
    local_10 = (void *)*puVar5;
  }
  if (local_18 == pvVar3) {
    piVar4 = (int *)FUN_1001b2d0((int)pvVar3);
    local_14 = (void *)*piVar4;
    pcVar2 = (char *)FUN_1001b290((int)local_10);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_1001b2d0((int)local_10);
      *piVar4 = (int)local_14;
    }
    piVar4 = (int *)FUN_1001b240((int)this);
    if ((void *)*piVar4 == pvVar3) {
      puVar5 = (undefined4 *)FUN_1001b240((int)this);
      *puVar5 = local_10;
    }
    else {
      piVar4 = (int *)FUN_1001b2b0(local_14);
      if ((void *)*piVar4 == pvVar3) {
        puVar5 = (undefined4 *)FUN_1001b2b0(local_14);
        *puVar5 = local_10;
      }
      else {
        puVar5 = (undefined4 *)FUN_1001b2f0((int)local_14);
        *puVar5 = local_10;
      }
    }
    piVar4 = (int *)FUN_1001b210((int)this);
    if ((void *)*piVar4 == pvVar3) {
      pcVar2 = (char *)FUN_1001b290((int)local_10);
      local_5c = local_14;
      if (*pcVar2 == '\0') {
        local_5c = (void *)FUN_1001b800(local_10);
      }
      piVar4 = (int *)FUN_1001b210((int)this);
      *piVar4 = (int)local_5c;
    }
    piVar4 = (int *)FUN_1001b640((int)this);
    if ((void *)*piVar4 == pvVar3) {
      pcVar2 = (char *)FUN_1001b290((int)local_10);
      local_5c = local_14;
      if (*pcVar2 == '\0') {
        local_5c = (void *)FUN_1001b7b0((int)local_10);
      }
      piVar4 = (int *)FUN_1001b640((int)this);
      *piVar4 = (int)local_5c;
    }
  }
  else {
    piVar4 = (int *)FUN_1001b2b0(pvVar3);
    puVar5 = (undefined4 *)FUN_1001b2d0(*piVar4);
    *puVar5 = local_18;
    puVar5 = (undefined4 *)FUN_1001b2b0(pvVar3);
    puVar6 = (undefined4 *)FUN_1001b2b0(local_18);
    *puVar6 = *puVar5;
    piVar4 = (int *)FUN_1001b2f0((int)pvVar3);
    if (local_18 == (void *)*piVar4) {
      local_14 = local_18;
    }
    else {
      piVar4 = (int *)FUN_1001b2d0((int)local_18);
      local_14 = (void *)*piVar4;
      pcVar2 = (char *)FUN_1001b290((int)local_10);
      if (*pcVar2 == '\0') {
        piVar4 = (int *)FUN_1001b2d0((int)local_10);
        *piVar4 = (int)local_14;
      }
      puVar5 = (undefined4 *)FUN_1001b2b0(local_14);
      *puVar5 = local_10;
      puVar5 = (undefined4 *)FUN_1001b2f0((int)pvVar3);
      puVar6 = (undefined4 *)FUN_1001b2f0((int)local_18);
      *puVar6 = *puVar5;
      piVar4 = (int *)FUN_1001b2f0((int)pvVar3);
      puVar5 = (undefined4 *)FUN_1001b2d0(*piVar4);
      *puVar5 = local_18;
    }
    piVar4 = (int *)FUN_1001b240((int)this);
    if ((void *)*piVar4 == pvVar3) {
      puVar5 = (undefined4 *)FUN_1001b240((int)this);
      *puVar5 = local_18;
    }
    else {
      puVar5 = (undefined4 *)FUN_1001b2d0((int)pvVar3);
      piVar4 = (int *)FUN_1001b2b0(*puVar5);
      if ((void *)*piVar4 == pvVar3) {
        puVar5 = (undefined4 *)FUN_1001b2d0((int)pvVar3);
        puVar5 = (undefined4 *)FUN_1001b2b0(*puVar5);
        *puVar5 = local_18;
      }
      else {
        piVar4 = (int *)FUN_1001b2d0((int)pvVar3);
        puVar5 = (undefined4 *)FUN_1001b2f0(*piVar4);
        *puVar5 = local_18;
      }
    }
    puVar5 = (undefined4 *)FUN_1001b2d0((int)pvVar3);
    puVar6 = (undefined4 *)FUN_1001b2d0((int)local_18);
    *puVar6 = *puVar5;
    puVar7 = (undefined1 *)FUN_1001b270((int)pvVar3);
    puVar8 = (undefined1 *)FUN_1001b270((int)local_18);
    FUN_10011250(puVar8,puVar7);
  }
  pcVar2 = (char *)FUN_1001b270((int)pvVar3);
  if (*pcVar2 != '\x01') {
LAB_1001b142:
    iVar1 = FUN_1001a870((int)pvVar3);
    pvVar9 = (void *)FUN_1001c200(iVar1);
    FUN_1001c220((int)this + 0xd,pvVar9);
    FUN_1001a8b0(pvVar3);
    if (*(int *)((int)this + 8) != 0) {
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
    }
    FUN_1001a900(param_1,param_2);
    return param_1;
  }
LAB_1001adc6:
  piVar4 = (int *)FUN_1001b240((int)this);
  if ((local_10 == (void *)*piVar4) ||
     (pcVar2 = (char *)FUN_1001b270((int)local_10), *pcVar2 != '\x01')) goto LAB_1001b133;
  piVar4 = (int *)FUN_1001b2b0(local_14);
  if (local_10 == (void *)*piVar4) {
    piVar4 = (int *)FUN_1001b2f0((int)local_14);
    local_18 = (void *)*piVar4;
    pcVar2 = (char *)FUN_1001b270((int)local_18);
    if (*pcVar2 == '\0') {
      puVar7 = (undefined1 *)FUN_1001b270((int)local_18);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_1001b270((int)local_14);
      *puVar7 = 0;
      FUN_1001b500(this,(int)local_14);
      piVar4 = (int *)FUN_1001b2f0((int)local_14);
      local_18 = (void *)*piVar4;
    }
    pcVar2 = (char *)FUN_1001b290((int)local_18);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_1001b2b0(local_18);
      pcVar2 = (char *)FUN_1001b270(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1001b2f0((int)local_18);
        pcVar2 = (char *)FUN_1001b270(*piVar4);
        if (*pcVar2 == '\x01') {
          puVar7 = (undefined1 *)FUN_1001b270((int)local_18);
          *puVar7 = 0;
          goto LAB_1001adb5;
        }
      }
      piVar4 = (int *)FUN_1001b2f0((int)local_18);
      pcVar2 = (char *)FUN_1001b270(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1001b2b0(local_18);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_1001b270((int)local_18);
        *puVar7 = 0;
        FUN_1001b670(this,(int)local_18);
        piVar4 = (int *)FUN_1001b2f0((int)local_14);
        local_18 = (void *)*piVar4;
      }
      puVar7 = (undefined1 *)FUN_1001b270((int)local_14);
      puVar8 = (undefined1 *)FUN_1001b270((int)local_18);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_1001b270((int)local_14);
      *puVar7 = 1;
      piVar4 = (int *)FUN_1001b2f0((int)local_18);
      puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
      *puVar7 = 1;
      FUN_1001b500(this,(int)local_14);
LAB_1001b133:
      puVar7 = (undefined1 *)FUN_1001b270((int)local_10);
      *puVar7 = 1;
      goto LAB_1001b142;
    }
  }
  else {
    piVar4 = (int *)FUN_1001b2b0(local_14);
    local_18 = (void *)*piVar4;
    pcVar2 = (char *)FUN_1001b270((int)local_18);
    if (*pcVar2 == '\0') {
      puVar7 = (undefined1 *)FUN_1001b270((int)local_18);
      *puVar7 = 1;
      puVar7 = (undefined1 *)FUN_1001b270((int)local_14);
      *puVar7 = 0;
      FUN_1001b670(this,(int)local_14);
      piVar4 = (int *)FUN_1001b2b0(local_14);
      local_18 = (void *)*piVar4;
    }
    pcVar2 = (char *)FUN_1001b290((int)local_18);
    if (*pcVar2 == '\0') {
      piVar4 = (int *)FUN_1001b2f0((int)local_18);
      pcVar2 = (char *)FUN_1001b270(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1001b2b0(local_18);
        pcVar2 = (char *)FUN_1001b270(*piVar4);
        if (*pcVar2 == '\x01') {
          puVar7 = (undefined1 *)FUN_1001b270((int)local_18);
          *puVar7 = 0;
          goto LAB_1001adb5;
        }
      }
      piVar4 = (int *)FUN_1001b2b0(local_18);
      pcVar2 = (char *)FUN_1001b270(*piVar4);
      if (*pcVar2 == '\x01') {
        piVar4 = (int *)FUN_1001b2f0((int)local_18);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_1001b270((int)local_18);
        *puVar7 = 0;
        FUN_1001b500(this,(int)local_18);
        piVar4 = (int *)FUN_1001b2b0(local_14);
        local_18 = (void *)*piVar4;
      }
      puVar7 = (undefined1 *)FUN_1001b270((int)local_14);
      puVar8 = (undefined1 *)FUN_1001b270((int)local_18);
      *puVar8 = *puVar7;
      puVar7 = (undefined1 *)FUN_1001b270((int)local_14);
      *puVar7 = 1;
      piVar4 = (int *)FUN_1001b2b0(local_18);
      puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
      *puVar7 = 1;
      FUN_1001b670(this,(int)local_14);
      goto LAB_1001b133;
    }
  }
LAB_1001adb5:
  local_10 = local_14;
  puVar5 = (undefined4 *)FUN_1001b2d0((int)local_14);
  local_14 = (void *)*puVar5;
  goto LAB_1001adc6;
}



// Function: FUN_1001b1b0 at 1001b1b0

void __fastcall FUN_1001b1b0(void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1001b240((int)param_1);
  FUN_1001b460(param_1,(void *)*puVar1);
  puVar1 = (undefined4 *)FUN_1001b240((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_1001b210((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_1001b640((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_1001b210 at 1001b210

void __fastcall FUN_1001b210(int param_1)

{
  FUN_1001b2b0(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_1001b240 at 1001b240

void __fastcall FUN_1001b240(int param_1)

{
  FUN_1001b2d0(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_1001b270 at 1001b270

int __cdecl FUN_1001b270(int param_1)

{
  return param_1 + 0x38;
}



// Function: FUN_1001b290 at 1001b290

int __cdecl FUN_1001b290(int param_1)

{
  return param_1 + 0x39;
}



// Function: FUN_1001b2b0 at 1001b2b0

undefined4 __cdecl FUN_1001b2b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001b2d0 at 1001b2d0

int __cdecl FUN_1001b2d0(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_1001b2f0 at 1001b2f0

int __cdecl FUN_1001b2f0(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_1001b310 at 1001b310

int __fastcall FUN_1001b310(int param_1)

{
  FUN_1001b850(param_1);
  FUN_1001c240(param_1 + 0xc);
  FUN_1001a890(param_1 + 0xd);
  return param_1;
}



// Function: FUN_1001b360 at 1001b360

void FUN_1001b360(uint param_1)

{
  FUN_1001c260(param_1);
  return;
}



// Function: FUN_1001b390 at 1001b390

undefined4 * __fastcall FUN_1001b390(undefined4 *param_1)

{
  FUN_1001b890(param_1);
  return param_1;
}



// Function: FUN_1001b3b0 at 1001b3b0

void * __thiscall FUN_1001b3b0(void *this,undefined4 param_1)

{
  FUN_1001b8b0(this,param_1);
  return this;
}



// Function: FUN_1001b3e0 at 1001b3e0

int * __thiscall FUN_1001b3e0(void *this,int *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  FUN_1001b870((int *)this);
  *param_1 = iVar1;
  return param_1;
}



// Function: FUN_1001b410 at 1001b410

int * __fastcall FUN_1001b410(int *param_1)

{
  FUN_1001b8e0(param_1);
  return param_1;
}



// Function: FUN_1001b430 at 1001b430

bool __thiscall FUN_1001b430(void *this,int *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_1001a530(this,param_1);
  return (bool)('\x01' - bVar1);
}



// Function: FUN_1001b460 at 1001b460

void __thiscall FUN_1001b460(void *this,void *param_1)

{
  void *pvVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_c;
  
  local_c = param_1;
  while( true ) {
    pcVar2 = (char *)FUN_1001b290((int)local_c);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_1001b2f0((int)local_c);
    FUN_1001b460(this,(void *)*puVar3);
    puVar3 = (undefined4 *)FUN_1001b2b0(local_c);
    pvVar1 = (void *)*puVar3;
    iVar4 = FUN_1001a870((int)local_c);
    pvVar5 = (void *)FUN_1001c200(iVar4);
    FUN_1001c220((int)this + 0xd,pvVar5);
    FUN_1001a8b0(local_c);
    local_c = pvVar1;
  }
  return;
}



// Function: FUN_1001b500 at 1001b500

void __thiscall FUN_1001b500(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_1001b2f0(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_1001b2b0(iVar1);
  puVar4 = (undefined4 *)FUN_1001b2f0(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1001b2b0(iVar1);
  pcVar5 = (char *)FUN_1001b290(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_1001b2b0(iVar1);
    piVar2 = (int *)FUN_1001b2d0(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_1001b2d0(param_1);
  puVar4 = (undefined4 *)FUN_1001b2d0(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1001b240((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_1001b240((int)this);
    *piVar2 = iVar1;
  }
  else {
    puVar3 = (undefined4 *)FUN_1001b2d0(param_1);
    piVar2 = (int *)FUN_1001b2b0(*puVar3);
    if (param_1 == *piVar2) {
      puVar3 = (undefined4 *)FUN_1001b2d0(param_1);
      piVar2 = (int *)FUN_1001b2b0(*puVar3);
      *piVar2 = iVar1;
    }
    else {
      piVar2 = (int *)FUN_1001b2d0(param_1);
      piVar2 = (int *)FUN_1001b2f0(*piVar2);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_1001b2b0(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_1001b2d0(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_1001b640 at 1001b640

void __fastcall FUN_1001b640(int param_1)

{
  FUN_1001b2f0(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_1001b670 at 1001b670

void __thiscall FUN_1001b670(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_1001b2b0(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_1001b2f0(iVar1);
  puVar4 = (undefined4 *)FUN_1001b2b0(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1001b2f0(iVar1);
  pcVar5 = (char *)FUN_1001b290(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_1001b2f0(iVar1);
    piVar2 = (int *)FUN_1001b2d0(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_1001b2d0(param_1);
  puVar4 = (undefined4 *)FUN_1001b2d0(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_1001b240((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_1001b240((int)this);
    *piVar2 = iVar1;
  }
  else {
    piVar2 = (int *)FUN_1001b2d0(param_1);
    piVar2 = (int *)FUN_1001b2f0(*piVar2);
    if (param_1 == *piVar2) {
      piVar2 = (int *)FUN_1001b2d0(param_1);
      piVar2 = (int *)FUN_1001b2f0(*piVar2);
      *piVar2 = iVar1;
    }
    else {
      puVar3 = (undefined4 *)FUN_1001b2d0(param_1);
      piVar2 = (int *)FUN_1001b2b0(*puVar3);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_1001b2f0(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_1001b2d0(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_1001b7b0 at 1001b7b0

int __cdecl FUN_1001b7b0(int param_1)

{
  int *piVar1;
  char *pcVar2;
  
  while( true ) {
    piVar1 = (int *)FUN_1001b2f0(param_1);
    pcVar2 = (char *)FUN_1001b290(*piVar1);
    if (*pcVar2 != '\0') break;
    piVar1 = (int *)FUN_1001b2f0(param_1);
    param_1 = *piVar1;
  }
  return param_1;
}



// Function: FUN_1001b800 at 1001b800

undefined4 __cdecl FUN_1001b800(undefined4 param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  while( true ) {
    piVar1 = (int *)FUN_1001b2b0(param_1);
    pcVar2 = (char *)FUN_1001b290(*piVar1);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_1001b2b0(param_1);
    param_1 = *puVar3;
  }
  return param_1;
}



// Function: FUN_1001b850 at 1001b850

undefined4 __fastcall FUN_1001b850(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001b870 at 1001b870

int * __fastcall FUN_1001b870(int *param_1)

{
  FUN_1001b9d0(param_1);
  return param_1;
}



// Function: FUN_1001b890 at 1001b890

undefined4 * __fastcall FUN_1001b890(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001b8b0 at 1001b8b0

undefined4 * __thiscall FUN_1001b8b0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_10014df0();
  return (undefined4 *)this;
}



// Function: FUN_1001b8e0 at 1001b8e0

int * __fastcall FUN_1001b8e0(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  
  pcVar1 = (char *)FUN_1001b290(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_1001b2b0(*param_1);
    pcVar1 = (char *)FUN_1001b290(*piVar2);
    if (*pcVar1 == '\0') {
      piVar2 = (int *)FUN_1001b2b0(*param_1);
      iVar3 = FUN_1001b7b0(*piVar2);
      *param_1 = iVar3;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_1001b2d0(*param_1);
        iVar3 = *piVar2;
        pcVar1 = (char *)FUN_1001b290(iVar3);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_1001b2b0(iVar3), *param_1 != *piVar2)) break;
        *param_1 = iVar3;
      }
      pcVar1 = (char *)FUN_1001b290(*param_1);
      if (*pcVar1 == '\0') {
        *param_1 = iVar3;
      }
    }
  }
  else {
    piVar2 = (int *)FUN_1001b2f0(*param_1);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_1001b9d0 at 1001b9d0

int * __fastcall FUN_1001b9d0(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_1001b290(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_1001b2f0(*param_1);
    pcVar1 = (char *)FUN_1001b290(*piVar2);
    if (*pcVar1 == '\0') {
      puVar3 = (undefined4 *)FUN_1001b2f0(*param_1);
      iVar4 = FUN_1001b800(*puVar3);
      *param_1 = iVar4;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_1001b2d0(*param_1);
        iVar4 = *piVar2;
        pcVar1 = (char *)FUN_1001b290(iVar4);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_1001b2f0(iVar4), *param_1 != *piVar2)) break;
        *param_1 = iVar4;
      }
      *param_1 = iVar4;
    }
  }
  return param_1;
}



// Function: FUN_1001ba90 at 1001ba90

/* WARNING: Removing unreachable block (ram,0x1001bbfe) */
/* WARNING: Removing unreachable block (ram,0x1001bce1) */

int * FUN_1001ba90(int *param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar6;
  int *piVar7;
  __int64 _Var8;
  uint local_94;
  int local_90;
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int *piStack_74;
  int local_30 [2];
  undefined8 local_28;
  uint local_20;
  int local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fb98;
  local_10 = ExceptionList;
  uVar3 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = &stack0xffffff54;
  ExceptionList = &local_10;
  local_18 = 0;
  local_20 = FUN_1001d530(param_2);
  local_1c = 0;
  _Var8 = std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
  local_88 = (int)((ulonglong)_Var8 >> 0x20);
  if ((-1 < _Var8) && ((0 < local_88 || (local_8c = (uint)_Var8, local_8c != 0)))) {
    _Var8 = std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
    local_90 = (int)((ulonglong)_Var8 >> 0x20);
    if ((local_1c <= local_90) &&
       ((local_1c < local_90 || (local_94 = (uint)_Var8, local_20 < local_94)))) {
      _Var8 = std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
      local_28 = _Var8 - CONCAT44(local_1c,local_20);
      goto LAB_1001bb7d;
    }
  }
  local_28 = 0;
LAB_1001bb7d:
  FUN_1001dd70(local_30,param_1);
  local_8 = 0;
  iVar4 = FUN_1001deb0((int)local_30);
  if (iVar4 == -1) {
    local_18 = local_18 | 4;
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               ((int)param_1 + *(int *)(*param_1 + 4)),local_18,false);
    piStack_74 = param_1;
    local_8 = 0xffffffff;
    FUN_1001de40(local_30);
    ExceptionList = local_10;
    return piStack_74;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar5 = std::ios_base::flags((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
  if ((uVar5 & 0x1c0) != 0x40) {
    while (0 < local_28) {
      cVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::fill
                        ((basic_ios<char,struct_std::char_traits<char>_> *)
                         ((int)param_1 + *(int *)(*param_1 + 4)));
      pbVar6 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                         ((basic_ios<char,struct_std::char_traits<char>_> *)
                          ((int)param_1 + *(int *)(*param_1 + 4)));
      local_84 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc(pbVar6,cVar1);
      local_80 = FUN_1001d5f0();
      bVar2 = FUN_1001d590(&local_80,&local_84);
      if (bVar2) {
        local_18 = local_18 | 4;
        break;
      }
      local_28 = CONCAT44(local_28._4_4_ - (uint)((int)local_28 == 0),(int)local_28 + -1);
    }
  }
  if (local_18 == 0) {
    iVar4 = local_1c;
    pbVar6 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        ((int)param_1 + *(int *)(*param_1 + 4)));
    _Var8 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputn
                      (pbVar6,param_2,CONCAT44(uVar3,iVar4));
    local_8c = (uint)_Var8;
    if ((local_8c != local_20) || (local_88 = (int)((ulonglong)_Var8 >> 0x20), local_88 != local_1c)
       ) {
      local_18 = local_18 | 4;
    }
  }
  if (local_18 == 0) {
    while (0 < local_28) {
      cVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::fill
                        ((basic_ios<char,struct_std::char_traits<char>_> *)
                         ((int)param_1 + *(int *)(*param_1 + 4)));
      pbVar6 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                         ((basic_ios<char,struct_std::char_traits<char>_> *)
                          ((int)param_1 + *(int *)(*param_1 + 4)));
      local_7c = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc(pbVar6,cVar1);
      local_78 = FUN_1001d5f0();
      bVar2 = FUN_1001d590(&local_78,&local_7c);
      if (bVar2) {
        local_18 = local_18 | 4;
        break;
      }
      local_28 = CONCAT44(local_28._4_4_ - (uint)((int)local_28 == 0),(int)local_28 + -1);
    }
  }
  std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)),0);
  piVar7 = (int *)FUN_1001bd83();
  return piVar7;
}



// Function: Catch@1001bd5f at 1001bd5f

undefined4 Catch_1001bd5f(void)

{
  int unaff_EBP;
  
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001bd8a;
}



// Function: FUN_1001bd83 at 1001bd83

undefined4 FUN_1001bd83(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4)),
             *(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1001de40((int *)(unaff_EBP + -0x2c));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x70);
}



// Function: FUN_1001bdd0 at 1001bdd0

int * FUN_1001bdd0(int *param_1,undefined4 *param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar6;
  char *pcVar7;
  int *piVar8;
  __int64 _Var9;
  undefined4 uVar10;
  int local_88;
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int *piStack_6c;
  int local_28 [2];
  int local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fbc8;
  local_10 = ExceptionList;
  uVar3 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = &stack0xffffff64;
  ExceptionList = &local_10;
  local_18 = 0;
  local_1c = FUN_1001d8a0((int)param_2);
  _Var9 = std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
  local_80 = (int)((ulonglong)_Var9 >> 0x20);
  if ((_Var9 < 0) ||
     (((local_80 < 1 && (local_84 = (uint)_Var9, local_84 == 0)) ||
      (_Var9 = std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4))),
      (uint)_Var9 <= local_1c)))) {
    local_88 = 0;
  }
  else {
    _Var9 = std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
    local_88 = (int)_Var9 - local_1c;
  }
  local_20 = local_88;
  FUN_1001dd70(local_28,param_1);
  local_8 = 0;
  iVar4 = FUN_1001deb0((int)local_28);
  if (iVar4 == -1) {
    local_18 = local_18 | 4;
    std::basic_ios<char,struct_std::char_traits<char>_>::setstate
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               ((int)param_1 + *(int *)(*param_1 + 4)),local_18,false);
    piStack_6c = param_1;
    local_8 = 0xffffffff;
    FUN_1001de40(local_28);
    ExceptionList = local_10;
    return piStack_6c;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar5 = std::ios_base::flags((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
  if ((uVar5 & 0x1c0) != 0x40) {
    for (; local_20 != 0; local_20 = local_20 + -1) {
      cVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::fill
                        ((basic_ios<char,struct_std::char_traits<char>_> *)
                         ((int)param_1 + *(int *)(*param_1 + 4)));
      pbVar6 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                         ((basic_ios<char,struct_std::char_traits<char>_> *)
                          ((int)param_1 + *(int *)(*param_1 + 4)));
      local_7c = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc(pbVar6,cVar1);
      local_78 = FUN_1001d5f0();
      bVar2 = FUN_1001d590(&local_78,&local_7c);
      if (bVar2) {
        local_18 = local_18 | 4;
        break;
      }
    }
  }
  if (local_18 == 0) {
    uVar10 = 0;
    pcVar7 = (char *)FUN_1001d880(param_2);
    pbVar6 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        ((int)param_1 + *(int *)(*param_1 + 4)));
    _Var9 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputn
                      (pbVar6,pcVar7,CONCAT44(uVar3,uVar10));
    local_84 = (uint)_Var9;
    if ((local_84 != local_1c) || (local_80 = (int)((ulonglong)_Var9 >> 0x20), local_80 != 0)) {
      local_18 = local_18 | 4;
      goto LAB_1001c014;
    }
  }
  for (; local_20 != 0; local_20 = local_20 + -1) {
    cVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::fill
                      ((basic_ios<char,struct_std::char_traits<char>_> *)
                       ((int)param_1 + *(int *)(*param_1 + 4)));
    pbVar6 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        ((int)param_1 + *(int *)(*param_1 + 4)));
    local_74 = std::basic_streambuf<char,struct_std::char_traits<char>_>::sputc(pbVar6,cVar1);
    local_70 = FUN_1001d5f0();
    bVar2 = FUN_1001d590(&local_70,&local_74);
    if (bVar2) {
      local_18 = local_18 | 4;
      break;
    }
  }
LAB_1001c014:
  std::ios_base::width((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)),0);
  piVar8 = (int *)FUN_1001c051();
  return piVar8;
}



// Function: Catch@1001c02d at 1001c02d

undefined4 Catch_1001c02d(void)

{
  int unaff_EBP;
  
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001c058;
}



// Function: FUN_1001c051 at 1001c051

undefined4 FUN_1001c051(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  std::basic_ios<char,struct_std::char_traits<char>_>::setstate
            ((basic_ios<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4)),
             *(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1001de40((int *)(unaff_EBP + -0x24));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x68);
}



// Function: FUN_1001c0a0 at 1001c0a0

facet * __cdecl FUN_1001c0a0(locale *param_1)

{
  uint uVar1;
  bad_cast local_74 [12];
  facet *local_68;
  facet *local_24;
  facet *local_20;
  uint local_1c;
  facet *local_18;
  _Lockit local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fbf9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_14,0);
  local_8 = 0;
  local_18 = DAT_1004423c;
  local_1c = std::locale::id::operator_unsigned_int((id *)id_exref);
  local_20 = (facet *)FUN_1001d680(param_1,local_1c);
  if (local_20 == (facet *)0x0) {
    if (local_18 == (facet *)0x0) {
      uVar1 = std::codecvt<char,char,int>::_Getcat(&local_18,param_1);
      if (uVar1 == 0xffffffff) {
        std::bad_cast::bad_cast(local_74,"bad cast");
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_74,(ThrowInfo *)&DAT_1003f25c);
      }
      local_20 = local_18;
      DAT_1004423c = local_18;
      local_24 = local_18;
      std::locale::facet::_Incref(local_18);
      FUN_1001d610(local_24);
    }
    else {
      local_20 = local_18;
    }
  }
  local_68 = local_20;
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_14);
  ExceptionList = local_10;
  return local_68;
}



// Function: FUN_1001c1a0 at 1001c1a0

undefined4 * __thiscall FUN_1001c1a0(void *this,undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = FUN_1001d0a0(param_3);
  pvVar2 = (void *)FUN_1001d0c0(this,uVar1);
  FUN_1001c2d0(param_1,param_2,pvVar2);
  return param_1;
}



// Function: FUN_1001c1e0 at 1001c1e0

undefined4 __cdecl FUN_1001c1e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001c200 at 1001c200

undefined4 __cdecl FUN_1001c200(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001c220 at 1001c220

void __cdecl FUN_1001c220(undefined4 param_1,void *param_2)

{
  FUN_1001c8e0(param_2);
  return;
}



// Function: FUN_1001c240 at 1001c240

undefined4 __fastcall FUN_1001c240(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001c260 at 1001c260

void * __cdecl FUN_1001c260(uint param_1)

{
  exception local_54 [76];
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x3ffffff < param_1 || (local_8 = operator_new(param_1 << 6), local_8 == (void *)0x0)))) {
    FUN_1000aac0(local_54);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1003d210);
  }
  return local_8;
}



// Function: FUN_1001c2d0 at 1001c2d0

/* WARNING: Removing unreachable block (ram,0x1001c331) */
/* WARNING: Removing unreachable block (ram,0x1001c3a7) */
/* WARNING: Removing unreachable block (ram,0x1001c41d) */
/* WARNING: Removing unreachable block (ram,0x1001c44f) */
/* WARNING: Removing unreachable block (ram,0x1001c48a) */
/* WARNING: Removing unreachable block (ram,0x1001c4d2) */
/* WARNING: Removing unreachable block (ram,0x1001c4ad) */
/* WARNING: Removing unreachable block (ram,0x1001c4fa) */
/* WARNING: Removing unreachable block (ram,0x1001c52c) */
/* WARNING: Removing unreachable block (ram,0x1001c555) */
/* WARNING: Removing unreachable block (ram,0x1001c583) */
/* WARNING: Removing unreachable block (ram,0x1001c5cb) */
/* WARNING: Removing unreachable block (ram,0x1001c5a6) */
/* WARNING: Removing unreachable block (ram,0x1001c5f0) */
/* WARNING: Removing unreachable block (ram,0x1001c3c3) */
/* WARNING: Removing unreachable block (ram,0x1001c3f3) */
/* WARNING: Removing unreachable block (ram,0x1001c418) */
/* WARNING: Removing unreachable block (ram,0x1001c34d) */
/* WARNING: Removing unreachable block (ram,0x1001c37b) */
/* WARNING: Removing unreachable block (ram,0x1001c39e) */
/* WARNING: Removing unreachable block (ram,0x1001c5f4) */

undefined4 * FUN_1001c2d0(undefined4 *param_1,int param_2,void *param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  int *this;
  undefined4 *puVar8;
  void *pvVar9;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [75];
  char local_11;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_1001a870((int)param_3);
  FUN_1001b390(&local_10);
  local_11 = '\0';
  iVar3 = FUN_1001c910((int)local_8);
  if (iVar3 == 0) {
    FUN_1001cb80(local_8,param_1,'\x01',*(int *)((int)local_8 + 4),param_3);
    return param_1;
  }
  piVar4 = (int *)FUN_1001a640(local_8,local_68);
  bVar1 = FUN_1001a530(&param_2,piVar4);
  if (bVar1) {
    iVar3 = FUN_1001a560(&param_2);
    puVar5 = (uint *)FUN_1001a440(iVar3);
    puVar6 = (uint *)FUN_1001c1e0(local_c);
    cVar2 = FUN_1001a490(puVar6,puVar5);
    if (cVar2 != '\0') {
      pvVar9 = param_3;
      iVar3 = FUN_1001a560(&param_2);
      FUN_1001cb80(local_8,param_1,'\x01',iVar3,pvVar9);
      return param_1;
    }
  }
  else {
    piVar4 = (int *)FUN_1001a350(local_8,local_64);
    bVar1 = FUN_1001a530(&param_2,piVar4);
    if (bVar1) {
      puVar5 = (uint *)FUN_1001c1e0(local_c);
      piVar4 = (int *)FUN_1001b640((int)local_8);
      puVar6 = (uint *)FUN_1001a440(*piVar4);
      cVar2 = FUN_1001a490(puVar6,puVar5);
      if (cVar2 != '\0') {
        pvVar9 = param_3;
        piVar4 = (int *)FUN_1001b640((int)local_8);
        FUN_1001cb80(local_8,param_1,'\0',*piVar4,pvVar9);
        return param_1;
      }
    }
    else {
      iVar3 = FUN_1001a560(&param_2);
      puVar5 = (uint *)FUN_1001a440(iVar3);
      puVar6 = (uint *)FUN_1001c1e0(local_c);
      cVar2 = FUN_1001a490(puVar6,puVar5);
      if (cVar2 != '\0') {
        local_10 = param_2;
        puVar5 = (uint *)FUN_1001c1e0(local_c);
        piVar4 = FUN_1001b410(&local_10);
        iVar3 = FUN_1001a560(piVar4);
        puVar6 = (uint *)FUN_1001a440(iVar3);
        cVar2 = FUN_1001a490(puVar6,puVar5);
        if (cVar2 != '\0') {
          iVar3 = FUN_1001a560(&local_10);
          piVar4 = (int *)FUN_1001b2f0(iVar3);
          pcVar7 = (char *)FUN_1001b290(*piVar4);
          if (*pcVar7 != '\0') {
            pvVar9 = param_3;
            iVar3 = FUN_1001a560(&local_10);
            FUN_1001cb80(local_8,param_1,'\0',iVar3,pvVar9);
            return param_1;
          }
          pvVar9 = param_3;
          iVar3 = FUN_1001a560(&param_2);
          FUN_1001cb80(local_8,param_1,'\x01',iVar3,pvVar9);
          return param_1;
        }
      }
      puVar5 = (uint *)FUN_1001c1e0(local_c);
      iVar3 = FUN_1001a560(&param_2);
      puVar6 = (uint *)FUN_1001a440(iVar3);
      cVar2 = FUN_1001a490(puVar6,puVar5);
      if (cVar2 != '\0') {
        local_10 = param_2;
        piVar4 = (int *)FUN_1001a350(local_8,local_60);
        this = FUN_1001b870(&local_10);
        bVar1 = FUN_1001a530(this,piVar4);
        if (!bVar1) {
          iVar3 = FUN_1001a560(&local_10);
          puVar5 = (uint *)FUN_1001a440(iVar3);
          puVar6 = (uint *)FUN_1001c1e0(local_c);
          cVar2 = FUN_1001a490(puVar6,puVar5);
          if (cVar2 == '\0') goto LAB_1001c8ac;
        }
        iVar3 = FUN_1001a560(&param_2);
        piVar4 = (int *)FUN_1001b2f0(iVar3);
        pcVar7 = (char *)FUN_1001b290(*piVar4);
        if (*pcVar7 != '\0') {
          pvVar9 = param_3;
          iVar3 = FUN_1001a560(&param_2);
          FUN_1001cb80(local_8,param_1,'\0',iVar3,pvVar9);
          return param_1;
        }
        pvVar9 = param_3;
        iVar3 = FUN_1001a560(&local_10);
        FUN_1001cb80(local_8,param_1,'\x01',iVar3,pvVar9);
        return param_1;
      }
    }
  }
LAB_1001c8ac:
  puVar8 = (undefined4 *)FUN_1001c930(local_5c,param_3,local_11);
  *param_1 = *puVar8;
  return param_1;
}



// Function: FUN_1001c8e0 at 1001c8e0

void FUN_1001c8e0(void *param_1)

{
  FUN_1001d180(param_1);
  return;
}



// Function: FUN_1001c910 at 1001c910

undefined4 __fastcall FUN_1001c910(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_1001c930 at 1001c930

/* WARNING: Removing unreachable block (ram,0x1001ca1b) */

void * FUN_1001c930(void *param_1,void *param_2,char param_3)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  char *pcVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  void *pvVar8;
  undefined1 *puVar9;
  int local_80;
  undefined1 local_74 [7];
  undefined1 local_6d;
  undefined1 local_6c [7];
  undefined1 local_65;
  undefined1 local_64 [7];
  undefined1 local_5d [65];
  int local_1c;
  char local_15;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_1001a870((int)param_2);
  piVar3 = (int *)FUN_1001b240((int)local_8);
  local_10 = *piVar3;
  local_14 = *(int *)((int)local_8 + 4);
  local_15 = '\x01';
  while (pcVar4 = (char *)FUN_1001b290(local_10), *pcVar4 == '\0') {
    local_14 = local_10;
    if (param_3 == '\0') {
      puVar5 = (uint *)FUN_1001a440(local_10);
      puVar6 = (uint *)FUN_1001c1e0(local_c);
      local_15 = FUN_1001a490(puVar6,puVar5);
    }
    else {
      puVar5 = (uint *)FUN_1001c1e0(local_c);
      puVar6 = (uint *)FUN_1001a440(local_10);
      cVar1 = FUN_1001a490(puVar6,puVar5);
      local_15 = '\x01' - (cVar1 != '\0');
    }
    if (local_15 == '\0') {
      piVar3 = (int *)FUN_1001b2f0(local_10);
      local_80 = *piVar3;
    }
    else {
      piVar3 = (int *)FUN_1001b2b0(local_10);
      local_80 = *piVar3;
    }
    local_10 = local_80;
  }
  FUN_1001a900(&local_1c,local_14);
  if (local_15 != '\0') {
    piVar3 = (int *)FUN_1001a640(local_8,local_74);
    bVar2 = FUN_1001a530(&local_1c,piVar3);
    if (bVar2) {
      local_6d = 1;
      puVar9 = &local_6d;
      pvVar8 = FUN_1001cb80(local_8,local_6c,'\x01',local_14,param_2);
      FUN_1001cfe0(param_1,pvVar8,puVar9);
      return param_1;
    }
    FUN_1001a930(&local_1c);
  }
  puVar5 = (uint *)FUN_1001c1e0(local_c);
  iVar7 = FUN_1001a560(&local_1c);
  puVar6 = (uint *)FUN_1001a440(iVar7);
  cVar1 = FUN_1001a490(puVar6,puVar5);
  if (cVar1 == '\0') {
    iVar7 = FUN_1001a870((int)param_2);
    pvVar8 = (void *)FUN_1001c200(iVar7);
    FUN_1001c220((int)local_8 + 0xd,pvVar8);
    FUN_1001a8b0(param_2);
    local_5d[0] = 0;
    FUN_1001d1a0(param_1,&local_1c,local_5d);
  }
  else {
    local_65 = 1;
    puVar9 = &local_65;
    pvVar8 = FUN_1001cb80(local_8,local_64,local_15,local_14,param_2);
    FUN_1001cfe0(param_1,pvVar8,puVar9);
  }
  return param_1;
}



// Function: FUN_1001cb80 at 1001cb80

void * __thiscall FUN_1001cb80(void *this,void *param_1,char param_2,int param_3,void *param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *puVar7;
  void *local_c;
  
  iVar1 = FUN_1001cfc0();
  if (iVar1 - 1U <= *(uint *)((int)this + 8)) {
    iVar1 = FUN_1001a870((int)param_4);
    pvVar2 = (void *)FUN_1001c200(iVar1);
    FUN_1001c220((int)this + 0xd,pvVar2);
    FUN_1001a8b0(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  *(int *)((int)param_4 + 4) = param_3;
  if (param_3 == *(int *)((int)this + 4)) {
    puVar3 = (undefined4 *)FUN_1001b240((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_1001b210((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_1001b640((int)this);
    *puVar3 = param_4;
  }
  else if (param_2 == '\0') {
    puVar3 = (undefined4 *)FUN_1001b2f0(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_1001b640((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_1001b640((int)this);
      *puVar3 = param_4;
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_1001b2b0(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_1001b210((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_1001b210((int)this);
      *puVar3 = param_4;
    }
  }
  local_c = param_4;
  while( true ) {
    piVar4 = (int *)FUN_1001b2d0((int)local_c);
    pcVar5 = (char *)FUN_1001b270(*piVar4);
    if (*pcVar5 != '\0') break;
    piVar4 = (int *)FUN_1001b2d0((int)local_c);
    piVar6 = (int *)FUN_1001b2d0((int)local_c);
    puVar3 = (undefined4 *)FUN_1001b2d0(*piVar6);
    piVar6 = (int *)FUN_1001b2b0(*puVar3);
    if (*piVar4 == *piVar6) {
      piVar4 = (int *)FUN_1001b2d0((int)local_c);
      piVar4 = (int *)FUN_1001b2d0(*piVar4);
      piVar4 = (int *)FUN_1001b2f0(*piVar4);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_1001b270(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_1001b270(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2d0(*piVar4);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        puVar3 = (undefined4 *)FUN_1001b2d0(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2f0(*piVar4);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_1001b2d0((int)local_c);
          local_c = (void *)*piVar4;
          FUN_1001b500(this,(int)local_c);
        }
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2d0(*piVar4);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2d0(*piVar4);
        FUN_1001b670(this,*piVar4);
      }
    }
    else {
      piVar4 = (int *)FUN_1001b2d0((int)local_c);
      puVar3 = (undefined4 *)FUN_1001b2d0(*piVar4);
      piVar4 = (int *)FUN_1001b2b0(*puVar3);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_1001b270(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_1001b270(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2d0(*piVar4);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        puVar3 = (undefined4 *)FUN_1001b2d0(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2b0(*puVar3);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_1001b2d0((int)local_c);
          local_c = (void *)*piVar4;
          FUN_1001b670(this,(int)local_c);
        }
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2d0(*piVar4);
        puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_1001b2d0((int)local_c);
        piVar4 = (int *)FUN_1001b2d0(*piVar4);
        FUN_1001b500(this,*piVar4);
      }
    }
  }
  piVar4 = (int *)FUN_1001b240((int)this);
  puVar7 = (undefined1 *)FUN_1001b270(*piVar4);
  *puVar7 = 1;
  FUN_1001a900(param_1,param_4);
  return param_1;
}



// Function: FUN_1001cfc0 at 1001cfc0

void FUN_1001cfc0(void)

{
  FUN_1001d020();
  return;
}



// Function: FUN_1001cfe0 at 1001cfe0

void * __thiscall FUN_1001cfe0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_10013f60(param_2);
  uVar2 = FUN_1001d1e0(param_1);
  FUN_1001d060(this,uVar2,uVar1);
  return this;
}



// Function: FUN_1001d020 at 1001d020

/* WARNING: Removing unreachable block (ram,0x1001d041) */

undefined4 FUN_1001d020(void)

{
  return 0x6666666;
}



// Function: FUN_1001d060 at 1001d060

undefined4 * __thiscall FUN_1001d060(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_1001d1e0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_10013f60(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_1001d0a0 at 1001d0a0

undefined4 __cdecl FUN_1001d0a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001d0c0 at 1001d0c0

void __thiscall FUN_1001d0c0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fc20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_1001d240((int)this);
  local_8 = 0;
  uVar2 = FUN_1001d0a0(param_1);
  iVar1 = FUN_1001a870(iVar1);
  uVar3 = FUN_1001c200(iVar1);
  FUN_1001d2c0((int)this + 0xd,uVar3,uVar2);
  FUN_1001d15c();
  return;
}



// Function: Catch@1001d135 at 1001d135

void Catch_1001d135(void)

{
  int unaff_EBP;
  
  FUN_1001a8b0(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001d15c at 1001d15c

undefined4 FUN_1001d15c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_1001d180 at 1001d180

void __cdecl FUN_1001d180(void *param_1)

{
  FUN_1001d200(param_1,0);
  return;
}



// Function: FUN_1001d1a0 at 1001d1a0

void * __thiscall FUN_1001d1a0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_100143d0(param_2);
  uVar2 = FUN_1001d2f0(param_1);
  FUN_1001d310(this,uVar2,uVar1);
  return this;
}



// Function: FUN_1001d1e0 at 1001d1e0

undefined4 __cdecl FUN_1001d1e0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001d200 at 1001d200

void * __thiscall FUN_1001d200(void *this,uint param_1)

{
  FUN_10019bc0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1001d240 at 1001d240

int __fastcall FUN_1001d240(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_1001b360(1);
  puVar2 = (undefined4 *)FUN_1001b2b0(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1001b2d0(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_1001b2f0(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined1 *)FUN_1001b270(iVar1);
  *puVar3 = 0;
  puVar3 = (undefined1 *)FUN_1001b290(iVar1);
  *puVar3 = 0;
  return iVar1;
}



// Function: FUN_1001d2c0 at 1001d2c0

void __cdecl FUN_1001d2c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001d0a0(param_3);
  FUN_1001d350(param_2,uVar1);
  return;
}



// Function: FUN_1001d2f0 at 1001d2f0

undefined4 __cdecl FUN_1001d2f0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001d310 at 1001d310

undefined4 * __thiscall FUN_1001d310(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_1001d2f0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_100143d0(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_1001d350 at 1001d350

void FUN_1001d350(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fc51;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(0x28,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = FUN_1001d0a0(param_2);
    FUN_1001d3e0(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001d3e0 at 1001d3e0

void * __thiscall FUN_1001d3e0(void *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fc78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_100168a0(param_1 + 8);
  uVar2 = FUN_1001d4f0(param_1);
  FUN_1001d460(this,uVar2,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001d460 at 1001d460

undefined4 * __thiscall FUN_1001d460(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fcab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_1001d510(param_1);
  *(undefined4 *)this = *puVar1;
  *(undefined4 *)((int)this + 4) = puVar1[1];
  iVar2 = FUN_10016bf0(param_2);
  FUN_100157f0((void *)((int)this + 8),iVar2);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1001d4f0 at 1001d4f0

undefined4 __cdecl FUN_1001d4f0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001d510 at 1001d510

undefined4 __cdecl FUN_1001d510(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001d530 at 1001d530

void __cdecl FUN_1001d530(char *param_1)

{
  strlen(param_1);
  return;
}



// Function: FUN_1001d550 at 1001d550

undefined1 __cdecl FUN_1001d550(undefined1 *param_1)

{
  return *param_1;
}



// Function: FUN_1001d570 at 1001d570

undefined1 __cdecl FUN_1001d570(undefined1 *param_1)

{
  return *param_1;
}



// Function: FUN_1001d590 at 1001d590

bool __cdecl FUN_1001d590(int *param_1,int *param_2)

{
  return *param_1 == *param_2;
}



// Function: FUN_1001d5b0 at 1001d5b0

uint __cdecl FUN_1001d5b0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 local_48;
  
  uVar1 = FUN_1001d5f0();
  if (*param_1 == uVar1) {
    iVar2 = FUN_1001d5f0();
    local_48 = (uint)(iVar2 == 0);
  }
  else {
    local_48 = *param_1;
  }
  return local_48;
}



// Function: FUN_1001d5f0 at 1001d5f0

undefined4 FUN_1001d5f0(void)

{
  return 0xffffffff;
}



// Function: FUN_1001d610 at 1001d610

void __fastcall FUN_1001d610(undefined4 param_1)

{
  Facet_Register(param_1);
  return;
}



// Function: FUN_1001d630 at 1001d630

void __fastcall FUN_1001d630(int *param_1)

{
  facet *pfVar1;
  
  if ((*param_1 != 0) &&
     (pfVar1 = std::locale::facet::_Decref((facet *)*param_1), pfVar1 != (facet *)0x0)) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: FUN_1001d680 at 1001d680

int __thiscall FUN_1001d680(void *this,uint param_1)

{
  _Locimp *p_Var1;
  int local_54;
  
                    /* WARNING: Load size is inaccurate */
  if (param_1 < *(uint *)(*this + 0xc)) {
                    /* WARNING: Load size is inaccurate */
    local_54 = *(int *)(*(int *)(*this + 8) + param_1 * 4);
  }
  else {
    local_54 = 0;
  }
                    /* WARNING: Load size is inaccurate */
  if ((local_54 == 0) && (*(char *)(*this + 0x14) != '\0')) {
    p_Var1 = std::locale::_Getgloballocale();
    if (param_1 < *(uint *)(p_Var1 + 0xc)) {
      local_54 = *(int *)(*(int *)(p_Var1 + 8) + param_1 * 4);
    }
    else {
      local_54 = 0;
    }
  }
  return local_54;
}



// Function: FUN_1001d710 at 1001d710

bool __cdecl FUN_1001d710(undefined1 *param_1,FILE *param_2)

{
  int iVar1;
  undefined1 local_8;
  
  iVar1 = fgetc(param_2);
  if (iVar1 != -1) {
    local_8 = (undefined1)iVar1;
    *param_1 = local_8;
  }
  return iVar1 != -1;
}



// Function: FUN_1001d750 at 1001d750

bool __cdecl FUN_1001d750(char param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = fputc((int)param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_1001d780 at 1001d780

bool __cdecl FUN_1001d780(byte *param_1,FILE *param_2)

{
  int iVar1;
  
  iVar1 = ungetc((uint)*param_1,param_2);
  return iVar1 != -1;
}



// Function: FUN_1001d7b0 at 1001d7b0

void * __fastcall FUN_1001d7b0(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fcd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001dbf0(&stack0xffffff94);
  FUN_1001dba0((int)param_1);
  local_8 = 0;
  FUN_1001dac0(param_1,'\0',0);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001d820 at 1001d820

void __fastcall FUN_1001d820(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002fd08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1001dac0(param_1,'\x01',0);
  local_8 = 0xffffffff;
  FUN_1001dbd0();
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001d880 at 1001d880

void __fastcall FUN_1001d880(undefined4 *param_1)

{
  FUN_1001db70(param_1);
  return;
}



// Function: FUN_1001d8a0 at 1001d8a0

undefined4 __fastcall FUN_1001d8a0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1001d8c0 at 1001d8c0

void * __thiscall FUN_1001d8c0(void *this,uint param_1,char param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fd38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001dbf0(&stack0xffffff94);
  FUN_1001dba0((int)this);
  local_8 = 0;
  FUN_1001dac0(this,'\0',0);
  FUN_1001dee0(this,param_1,param_2);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001d940 at 1001d940

void * __thiscall FUN_1001d940(void *this,uint param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (-*(int *)((int)this + 0x10) - 1U <= param_1) {
    FUN_1001e100();
  }
  if (param_1 != 0) {
    uVar2 = *(int *)((int)this + 0x10) + param_1;
    bVar1 = FUN_1001e030(this,uVar2,'\0');
    if (bVar1) {
      FUN_1001df40(this,*(int *)((int)this + 0x10),param_1,param_2);
      FUN_1001dff0(this,uVar2);
    }
  }
  return this;
}



// Function: FUN_1001d9c0 at 1001d9c0

undefined4 * __thiscall FUN_1001d9c0(void *this,uint param_1,uint param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  size_t sVar3;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_1001e120();
  }
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  if (param_2 != 0) {
    sVar3 = (*(int *)((int)this + 0x10) - param_1) - param_2;
    puVar1 = FUN_1001e0d0((undefined4 *)this);
    pvVar2 = (void *)((int)puVar1 + param_2 + param_1);
    puVar1 = FUN_1001e0d0((undefined4 *)this);
    FUN_1001da60((void *)((int)puVar1 + param_1),pvVar2,sVar3);
    FUN_1001dff0(this,*(int *)((int)this + 0x10) - param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001da60 at 1001da60

void __cdecl FUN_1001da60(void *param_1,void *param_2,size_t param_3)

{
  memmove(param_1,param_2,param_3);
  return;
}



// Function: FUN_1001da90 at 1001da90

void * __thiscall FUN_1001da90(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_1001e0d0((undefined4 *)this);
  FUN_1001e170(param_1,puVar1);
  return param_1;
}



// Function: FUN_1001dac0 at 1001dac0

void __thiscall FUN_1001dac0(void *this,char param_1,size_t param_2)

{
  void *pvVar1;
  
  if ((param_1 != '\0') && (0xf < *(uint *)((int)this + 0x14))) {
                    /* WARNING: Load size is inaccurate */
    pvVar1 = *this;
    if (param_2 != 0) {
      FUN_1001db40(this,pvVar1,param_2);
    }
    FUN_1001e140(pvVar1);
  }
  *(undefined4 *)((int)this + 0x14) = 0xf;
  FUN_1001dff0(this,param_2);
  return;
}



// Function: FUN_1001db40 at 1001db40

void __cdecl FUN_1001db40(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}



// Function: FUN_1001db70 at 1001db70

undefined4 * __fastcall FUN_1001db70(undefined4 *param_1)

{
  undefined4 *local_4c;
  
  local_4c = param_1;
  if (0xf < (uint)param_1[5]) {
    local_4c = (undefined4 *)*param_1;
  }
  return local_4c;
}



// Function: FUN_1001dba0 at 1001dba0

int __fastcall FUN_1001dba0(int param_1)

{
  FUN_1001dc10(param_1 + 0x18);
  return param_1;
}



// Function: FUN_1001dbd0 at 1001dbd0

void FUN_1001dbd0(void)

{
  return;
}



// Function: FUN_1001dbf0 at 1001dbf0

undefined4 __fastcall FUN_1001dbf0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001dc10 at 1001dc10

undefined4 __fastcall FUN_1001dc10(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001dc30 at 1001dc30

void __fastcall FUN_1001dc30(undefined4 *param_1)

{
  FUN_1001dc50(param_1);
  return;
}



// Function: FUN_1001dc50 at 1001dc50

undefined4 __fastcall FUN_1001dc50(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1001dc70 at 1001dc70

undefined4 * __thiscall FUN_1001dc70(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  return (undefined4 *)this;
}



// Function: FUN_1001dcc0 at 1001dcc0

undefined4 * __thiscall
FUN_1001dcc0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 0x10) = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1001dd00 at 1001dd00

undefined4 __fastcall FUN_1001dd00(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_1001dd20 at 1001dd20

undefined8 __fastcall FUN_1001dd20(int param_1)

{
  return *(undefined8 *)(param_1 + 8);
}



// Function: FUN_1001dd40 at 1001dd40

undefined8 __fastcall FUN_1001dd40(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[2];
  return CONCAT44(((int)uVar1 >> 0x1f) + param_1[1] + (uint)CARRY4(uVar1,*param_1),uVar1 + *param_1)
  ;
}



// Function: FUN_1001dd70 at 1001dd70

void * __thiscall FUN_1001dd70(void *this,int *param_1)

{
  bool bVar1;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fd68;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001e1a0(this,(int)param_1);
  local_8 = 0;
  bVar1 = std::ios_base::good((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
  if (bVar1) {
    pbVar2 = std::basic_ios<char,struct_std::char_traits<char>_>::tie
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        ((int)param_1 + *(int *)(*param_1 + 4)));
    if (pbVar2 != (basic_ostream<char,struct_std::char_traits<char>_> *)0x0) {
      pbVar2 = std::basic_ios<char,struct_std::char_traits<char>_>::tie
                         ((basic_ios<char,struct_std::char_traits<char>_> *)
                          ((int)param_1 + *(int *)(*param_1 + 4)));
      std::basic_ostream<char,struct_std::char_traits<char>_>::flush(pbVar2);
    }
  }
  bVar1 = std::ios_base::good((ios_base *)((int)param_1 + *(int *)(*param_1 + 4)));
  *(bool *)((int)this + 4) = bVar1;
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1001de40 at 1001de40

void __fastcall FUN_1001de40(int *param_1)

{
  bool bVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002fd98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<char,struct_std::char_traits<char>_>::_Osfx
              ((basic_ostream<char,struct_std::char_traits<char>_> *)*param_1);
  }
  local_8 = 0xffffffff;
  FUN_1001e200(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001deb0 at 1001deb0

int __fastcall FUN_1001deb0(int param_1)

{
  return (*(char *)(param_1 + 4) != '\0') - 1;
}



// Function: FUN_1001dee0 at 1001dee0

void * __thiscall FUN_1001dee0(void *this,uint param_1,char param_2)

{
  bool bVar1;
  
  if (param_1 == 0xffffffff) {
    FUN_1001e100();
  }
  bVar1 = FUN_1001e030(this,param_1,'\0');
  if (bVar1) {
    FUN_1001df40(this,0,param_1,param_2);
    FUN_1001dff0(this,param_1);
  }
  return this;
}



// Function: FUN_1001df40 at 1001df40

void __thiscall FUN_1001df40(void *this,int param_1,size_t param_2,char param_3)

{
  undefined4 *puVar1;
  char cVar2;
  char *pcVar3;
  
  if (param_2 == 1) {
    pcVar3 = &param_3;
    puVar1 = FUN_1001e0d0((undefined4 *)this);
    FUN_1001dfd0((undefined1 *)((int)puVar1 + param_1),pcVar3);
  }
  else {
    cVar2 = param_3;
    puVar1 = FUN_1001e0d0((undefined4 *)this);
    FUN_1001dfa0((void *)((int)puVar1 + param_1),param_2,cVar2);
  }
  return;
}



// Function: FUN_1001dfa0 at 1001dfa0

void __cdecl FUN_1001dfa0(void *param_1,size_t param_2,char param_3)

{
  memset(param_1,(int)param_3,param_2);
  return;
}



// Function: FUN_1001dfd0 at 1001dfd0

void __cdecl FUN_1001dfd0(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  return;
}



// Function: FUN_1001dff0 at 1001dff0

void __thiscall FUN_1001dff0(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 local_49 [65];
  void *local_8;
  
  local_49[0] = 0;
  *(int *)((int)this + 0x10) = param_1;
  puVar2 = local_49;
  local_8 = this;
  puVar1 = FUN_1001e0d0((undefined4 *)this);
  FUN_1001dfd0((undefined1 *)((int)puVar1 + param_1),puVar2);
  return;
}



// Function: FUN_1001e030 at 1001e030

bool __thiscall FUN_1001e030(void *this,uint param_1,char param_2)

{
  uint uVar1;
  undefined4 local_4c;
  
  uVar1 = FUN_1001e260();
  if (uVar1 < param_1) {
    FUN_1001e100();
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_1001e2a0(this,param_1);
  }
  else if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      FUN_1001dff0(this,0);
    }
  }
  else {
    if (param_1 < *(uint *)((int)this + 0x10)) {
      local_4c = param_1;
    }
    else {
      local_4c = *(size_t *)((int)this + 0x10);
    }
    FUN_1001dac0(this,'\x01',local_4c);
  }
  return param_1 != 0;
}



// Function: FUN_1001e0d0 at 1001e0d0

undefined4 * __fastcall FUN_1001e0d0(undefined4 *param_1)

{
  undefined4 *local_4c;
  
  local_4c = param_1;
  if (0xf < (uint)param_1[5]) {
    local_4c = (undefined4 *)*param_1;
  }
  return local_4c;
}



// Function: FUN_1001e100 at 1001e100

void FUN_1001e100(void)

{
  std::_Xlength_error("string too long");
  return;
}



// Function: FUN_1001e120 at 1001e120

void FUN_1001e120(void)

{
  std::_Xout_of_range("invalid string position");
  return;
}



// Function: FUN_1001e140 at 1001e140

void FUN_1001e140(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_1001e170 at 1001e170

void * __thiscall FUN_1001e170(void *this,undefined4 param_1)

{
  FUN_1001e420(this,param_1);
  return this;
}



// Function: FUN_1001e1a0 at 1001e1a0

int * __thiscall FUN_1001e1a0(void *this,int param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  *(int *)this = param_1;
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,struct_std::char_traits<char>_> *)
                      (*this + *(int *)(**this + 4)));
  if (pbVar1 != (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        (*this + *(int *)(**this + 4)));
    (**(code **)(*(int *)pbVar1 + 4))();
  }
  return (int *)this;
}



// Function: FUN_1001e200 at 1001e200

void __fastcall FUN_1001e200(int *param_1)

{
  basic_streambuf<char,struct_std::char_traits<char>_> *pbVar1;
  
  pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                     ((basic_ios<char,struct_std::char_traits<char>_> *)
                      (*param_1 + *(int *)(*(int *)*param_1 + 4)));
  if (pbVar1 != (basic_streambuf<char,struct_std::char_traits<char>_> *)0x0) {
    pbVar1 = std::basic_ios<char,struct_std::char_traits<char>_>::rdbuf
                       ((basic_ios<char,struct_std::char_traits<char>_> *)
                        (*param_1 + *(int *)(*(int *)*param_1 + 4)));
    (**(code **)(*(int *)pbVar1 + 8))();
  }
  return;
}



// Function: FUN_1001e260 at 1001e260

int FUN_1001e260(void)

{
  uint uVar1;
  undefined4 local_50;
  
  uVar1 = FUN_1001e480();
  if (uVar1 < 2) {
    local_50 = 1;
  }
  else {
    local_50 = uVar1 - 1;
  }
  return local_50;
}



// Function: FUN_1001e2a0 at 1001e2a0

void __thiscall FUN_1001e2a0(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fdc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1 | 0xf;
  uVar1 = FUN_1001e260();
  if (uVar1 < local_1c) {
    local_1c = param_1;
  }
  else if (local_1c / 3 < *(uint *)((int)this + 0x14) >> 1) {
    iVar2 = FUN_1001e260();
    if (iVar2 - (*(uint *)((int)this + 0x14) >> 1) < *(uint *)((int)this + 0x14)) {
      local_1c = FUN_1001e260();
    }
    else {
      local_1c = (*(uint *)((int)this + 0x14) >> 1) + *(int *)((int)this + 0x14);
    }
  }
  local_8 = 0;
  FUN_1001e450(local_1c + 1);
  FUN_1001e3b7();
  return;
}



// Function: Catch@1001e35d at 1001e35d

void Catch_1001e35d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = FUN_1001e450(*(int *)(unaff_EBP + -0x18) + 1);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar1;
  FUN_1001e3a3();
  return;
}



// Function: Catch@1001e381 at 1001e381

void Catch_1001e381(void)

{
  int unaff_EBP;
  
  FUN_1001dac0(*(void **)(unaff_EBP + -0x14),'\x01',0);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1001e3a3 at 1001e3a3

undefined4 FUN_1001e3a3(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return 0x1001e3be;
}



// Function: FUN_1001e3b7 at 1001e3b7

void FUN_1001e3b7(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  size_t sVar2;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    sVar2 = *(size_t *)(unaff_EBP + 0xc);
    puVar1 = FUN_1001e0d0(*(undefined4 **)(unaff_EBP + -0x14));
    FUN_1001db40(*(void **)(unaff_EBP + -0x1c),puVar1,sVar2);
  }
  FUN_1001dac0(*(void **)(unaff_EBP + -0x14),'\x01',0);
  **(undefined4 **)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x14) = *(undefined4 *)(unaff_EBP + -0x18);
  FUN_1001dff0(*(void **)(unaff_EBP + -0x14),*(int *)(unaff_EBP + 0xc));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1001e420 at 1001e420

undefined4 * __thiscall FUN_1001e420(void *this,undefined4 param_1)

{
  FUN_10014df0();
  *(undefined4 *)this = param_1;
  return (undefined4 *)this;
}



// Function: FUN_1001e450 at 1001e450

void FUN_1001e450(uint param_1)

{
  FUN_1001e5b0(param_1);
  return;
}



// Function: FUN_1001e480 at 1001e480

/* WARNING: Removing unreachable block (ram,0x1001e4a1) */

undefined4 FUN_1001e480(void)

{
  return 0xffffffff;
}



// Function: FUN_1001e4c0 at 1001e4c0

void * __cdecl FUN_1001e4c0(void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002fdf9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_1000a4d0((int)param_3);
  iVar2 = FUN_1001e640((int)param_2);
  iVar3 = FUN_1000a4d0((int)param_2);
  if ((uint)(iVar2 - iVar3) < uVar1) {
    iVar2 = FUN_1001e640((int)param_3);
    iVar3 = FUN_1000a4d0((int)param_3);
    uVar1 = FUN_1000a4d0((int)param_2);
    if (uVar1 <= (uint)(iVar2 - iVar3)) {
      uVar4 = FUN_1001e610(param_3,0,param_2);
      iVar2 = FUN_10016bf0(uVar4);
      FUN_100157f0(param_1,iVar2);
      ExceptionList = local_10;
      return param_1;
    }
  }
  uVar4 = FUN_10015e70(param_2,param_3);
  iVar2 = FUN_10016bf0(uVar4);
  FUN_100157f0(param_1,iVar2);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001e5b0 at 1001e5b0

void * __cdecl FUN_1001e5b0(uint param_1)

{
  exception local_54 [76];
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) && (local_8 = operator_new(param_1), local_8 == (void *)0x0)) {
    FUN_1000aac0(local_54);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1003d210);
  }
  return local_8;
}



// Function: FUN_1001e610 at 1001e610

void __thiscall FUN_1001e610(void *this,uint param_1,undefined4 *param_2)

{
  FUN_1001e660(this,param_1,param_2,0,0xffffffff);
  return;
}



// Function: FUN_1001e640 at 1001e640

undefined4 __fastcall FUN_1001e640(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



// Function: FUN_1001e660 at 1001e660

undefined4 * __thiscall
FUN_1001e660(void *this,uint param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint local_50;
  
  if (param_1 <= *(uint *)((int)this + 0x10)) {
    uVar2 = FUN_1000a4d0((int)param_2);
    if (param_3 <= uVar2) goto LAB_1001e68c;
  }
  FUN_1000a630();
LAB_1001e68c:
  iVar3 = FUN_1000a4d0((int)param_2);
  if (iVar3 - param_3 < param_4) {
    param_4 = iVar3 - param_3;
  }
  if (-*(int *)((int)this + 0x10) - 1U <= param_4) {
    FUN_1000a7d0();
  }
  if (param_4 != 0) {
    uVar2 = *(int *)((int)this + 0x10) + param_4;
    bVar1 = FUN_1000a6e0(this,uVar2,'\0');
    if (bVar1) {
      iVar3 = *(int *)((int)this + 0x10) - param_1;
      puVar4 = FUN_1000a5d0((undefined4 *)this);
      pvVar5 = (void *)((int)puVar4 + param_1 * 2);
      puVar4 = FUN_1000a5d0((undefined4 *)this);
      FUN_1000a470((void *)((int)puVar4 + param_4 * 2 + param_1 * 2),pvVar5,iVar3);
      if ((undefined4 *)this == param_2) {
        if (param_1 < param_3) {
          local_50 = param_3 + param_4;
        }
        else {
          local_50 = param_3;
        }
        puVar4 = FUN_1000a5d0((undefined4 *)this);
        pvVar5 = (void *)((int)puVar4 + local_50 * 2);
        puVar4 = FUN_1000a5d0((undefined4 *)this);
        FUN_1000a470((void *)((int)puVar4 + param_1 * 2),pvVar5,param_4);
      }
      else {
        puVar4 = FUN_1000a600(param_2);
        pvVar5 = (void *)((int)puVar4 + param_3 * 2);
        puVar4 = FUN_1000a5d0((undefined4 *)this);
        FUN_1000a2b0((void *)((int)puVar4 + param_1 * 2),pvVar5,param_4);
      }
      FUN_1000a4f0(this,uVar2);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1001e7c0 at 1001e7c0

void FUN_1001e7c0(void *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short *psVar6;
  uint uStack_d0;
  undefined1 local_bc [4];
  int local_b8;
  undefined1 local_b4 [72];
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60 [28];
  uint local_44;
  _Container_base0 local_40 [16];
  short local_30 [2];
  int local_2c;
  undefined4 local_28 [4];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002ff10;
  local_10 = ExceptionList;
  uStack_d0 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_d0;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_d0;
  FUN_10010de0(local_28);
  local_8._0_1_ = 1;
  FUN_1001ec30(&local_2c);
  local_8._0_1_ = 2;
  FUN_1001ed20(&local_2c,(IID *)&DAT_100380d0,(LPUNKNOWN)0x0,0x17);
  FUN_1000e160((undefined4 *)local_40);
  local_8 = CONCAT31(local_8._1_3_,3);
  local_44 = FUN_1001ebf0(param_1,L"\\",3);
  while (local_44 != 0xffffffff) {
    FUN_10015a00(local_60,0,local_44);
    local_8._0_1_ = 4;
    FUN_1001edb0(local_40,local_60);
    local_44 = FUN_1001ebf0(param_1,L"\\",local_44 + 1);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_1000aca0(local_60);
  }
  FUN_1001eec0(&local_64);
  puVar2 = (undefined4 *)FUN_1001ed50(local_40,local_bc);
  local_64 = *puVar2;
  while( true ) {
    piVar3 = (int *)FUN_1001ed80(local_40,local_b4);
    bVar1 = FUN_1001ef30(&local_64,piVar3);
    if (!bVar1) break;
    puVar2 = (undefined4 *)FUN_1001eee0(&local_64);
    FUN_100232d0(&local_68,puVar2);
    local_8._0_1_ = 5;
    piVar3 = (int *)FUN_1001ecc0(&local_2c);
    psVar6 = local_30;
    uVar4 = FUN_10007570(&local_68);
    uVar4 = (**(code **)(*piVar3 + 0x48))(piVar3,uVar4,psVar6);
    FUN_10010e40(local_28,uVar4);
    if (local_30[0] == 0) {
      FUN_1001ef60(&local_6c);
      local_8._0_1_ = 6;
      piVar3 = (int *)FUN_1001ecc0(&local_2c);
      uVar4 = FUN_1001eff0(&local_6c);
      uVar5 = FUN_10007570(&local_68);
      uVar4 = (**(code **)(*piVar3 + 0x74))(piVar3,uVar5,uVar4);
      FUN_10010e40(local_28,uVar4);
      FUN_1001f010(&local_6c);
      local_8._0_1_ = 5;
      FUN_1001ea80(&local_6c);
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_10007720(&local_68);
    FUN_1001ef00(&local_64,&local_b8);
  }
  FUN_1001ece0(&local_2c);
  local_8._0_1_ = 2;
  FUN_1000e2f0(local_40);
  local_8._0_1_ = 1;
  FUN_1001ea20(&local_2c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10010e20(local_28);
  FUN_1001e9ee();
  return;
}



// Function: Catch@1001e9d4 at 1001e9d4

undefined * Catch_1001e9d4(void)

{
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -0xa9) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1001e9f7;
}



// Function: FUN_1001e9ee at 1001e9ee

void FUN_1001e9ee(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x1001ea19;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: FUN_1001ea20 at 1001ea20

void __fastcall FUN_1001ea20(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002ff48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1001ec90(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ea80 at 1001ea80

void __fastcall FUN_1001ea80(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002ff78;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_1001efc0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001eae0 at 1001eae0

void FUN_1001eae0(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  short *psVar3;
  uint uStack_88;
  short local_34 [2];
  undefined4 local_30;
  int local_2c;
  undefined4 local_28 [4];
  undefined1 local_15;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1002ffb8;
  local_10 = ExceptionList;
  uStack_88 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_88;
  ExceptionList = &local_10;
  local_15 = 0;
  local_8 = 0;
  FUN_10010de0(local_28);
  local_8._0_1_ = 1;
  FUN_1001ec30(&local_2c);
  local_8._0_1_ = 2;
  FUN_1001ed20(&local_2c,(IID *)&DAT_100380d0,(LPUNKNOWN)0x0,0x17);
  FUN_100232d0(&local_30,param_1);
  local_8._0_1_ = 3;
  piVar1 = (int *)FUN_1001ecc0(&local_2c);
  psVar3 = local_34;
  uVar2 = FUN_10007570(&local_30);
  uVar2 = (**(code **)(*piVar1 + 0x48))(piVar1,uVar2,psVar3);
  FUN_10010e40(local_28,uVar2);
  local_15 = local_34[0] == -1;
  FUN_1001ece0(&local_2c);
  local_8._0_1_ = 2;
  FUN_10007720(&local_30);
  local_8._0_1_ = 1;
  FUN_1001ea20(&local_2c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10010e20(local_28);
  FUN_1001ebd1();
  return;
}



// Function: Catch@1001ebc0 at 1001ebc0

undefined4 Catch_1001ebc0(void)

{
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001ebd8;
}



// Function: FUN_1001ebd1 at 1001ebd1

undefined1 FUN_1001ebd1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0x11);
}



// Function: FUN_1001ebf0 at 1001ebf0

void __thiscall FUN_1001ebf0(void *this,wchar_t *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_1000a200(param_1);
  FUN_10015ed0(this,(ushort *)param_1,param_2,uVar1);
  return;
}



// Function: FUN_1001ec30 at 1001ec30

undefined4 * __fastcall FUN_1001ec30(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002ffe8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001f050(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001ec90 at 1001ec90

void __fastcall FUN_1001ec90(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001ecc0 at 1001ecc0

undefined4 __fastcall FUN_1001ecc0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1001ece0 at 1001ece0

void __fastcall FUN_1001ece0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1001ed20 at 1001ed20

void __thiscall FUN_1001ed20(void *this,IID *param_1,LPUNKNOWN param_2,DWORD param_3)

{
  CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_100381f0,(LPVOID *)this);
  return;
}



// Function: FUN_1001ed50 at 1001ed50

void * __thiscall FUN_1001ed50(void *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  FUN_1001f070(param_1,*this);
  return param_1;
}



// Function: FUN_1001ed80 at 1001ed80

void * __thiscall FUN_1001ed80(void *this,void *param_1)

{
  FUN_1001f070(param_1,*(undefined4 *)((int)this + 4));
  return param_1;
}



// Function: FUN_1001edb0 at 1001edb0

void __thiscall FUN_1001edb0(void *this,undefined4 param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = FUN_1001f1d0(param_1);
  cVar2 = FUN_1000edb0(this,uVar3);
  if (cVar2 == '\0') {
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_1000edf0(this,1);
    }
    FUN_1000eee0();
    FUN_1001f2d0((int)this + 0xc,*(undefined4 *)((int)this + 4),param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  }
  else {
    iVar4 = FUN_1001f1d0(param_1);
                    /* WARNING: Load size is inaccurate */
    iVar1 = *this;
    if (*(int *)((int)this + 4) == *(int *)((int)this + 8)) {
      FUN_1000edf0(this,1);
    }
    FUN_1000eee0();
                    /* WARNING: Load size is inaccurate */
    FUN_1001f1f0((int)this + 0xc,*(undefined4 *)((int)this + 4),
                 ((iVar4 - iVar1) / 0x1c) * 0x1c + *this);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  }
  return;
}



// Function: FUN_1001eec0 at 1001eec0

undefined4 * __fastcall FUN_1001eec0(undefined4 *param_1)

{
  FUN_1001f0c0(param_1);
  return param_1;
}



// Function: FUN_1001eee0 at 1001eee0

void __fastcall FUN_1001eee0(undefined4 *param_1)

{
  FUN_1001f0e0(param_1);
  return;
}



// Function: FUN_1001ef00 at 1001ef00

int * __thiscall FUN_1001ef00(void *this,int *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = *this;
  FUN_1001f0a0((int *)this);
  *param_1 = iVar1;
  return param_1;
}



// Function: FUN_1001ef30 at 1001ef30

bool __thiscall FUN_1001ef30(void *this,int *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_1001f100(this,param_1);
  return (bool)('\x01' - bVar1);
}



// Function: FUN_1001ef60 at 1001ef60

undefined4 * __fastcall FUN_1001ef60(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030018;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001f130(param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1001efc0 at 1001efc0

void __fastcall FUN_1001efc0(int *param_1)

{
  if (*param_1 != 0) {
    (**(code **)(*(int *)*param_1 + 8))(*param_1);
  }
  return;
}



// Function: FUN_1001eff0 at 1001eff0

undefined4 __fastcall FUN_1001eff0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001f010 at 1001f010

void __fastcall FUN_1001f010(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    *param_1 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_1001f050 at 1001f050

undefined4 * __fastcall FUN_1001f050(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001f070 at 1001f070

void * __thiscall FUN_1001f070(void *this,undefined4 param_1)

{
  FUN_1001f150(this,param_1);
  return this;
}



// Function: FUN_1001f0a0 at 1001f0a0

int * __fastcall FUN_1001f0a0(int *param_1)

{
  FUN_1001f180(param_1);
  return param_1;
}



// Function: FUN_1001f0c0 at 1001f0c0

undefined4 * __fastcall FUN_1001f0c0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001f0e0 at 1001f0e0

undefined4 __fastcall FUN_1001f0e0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_1001f100 at 1001f100

bool __thiscall FUN_1001f100(void *this,int *param_1)

{
  FUN_1001f1b0();
                    /* WARNING: Load size is inaccurate */
  return *this == *param_1;
}



// Function: FUN_1001f130 at 1001f130

undefined4 * __fastcall FUN_1001f130(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_1001f150 at 1001f150

undefined4 * __thiscall FUN_1001f150(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_10014df0();
  return (undefined4 *)this;
}



// Function: FUN_1001f180 at 1001f180

int * __fastcall FUN_1001f180(int *param_1)

{
  *param_1 = *param_1 + 0x1c;
  return param_1;
}



// Function: FUN_1001f1b0 at 1001f1b0

void FUN_1001f1b0(void)

{
  return;
}



// Function: FUN_1001f1d0 at 1001f1d0

undefined4 __cdecl FUN_1001f1d0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001f1f0 at 1001f1f0

void __cdecl FUN_1001f1f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001f220(param_3);
  FUN_1001f240(param_2,uVar1);
  return;
}



// Function: FUN_1001f220 at 1001f220

undefined4 __cdecl FUN_1001f220(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001f240 at 1001f240

void FUN_1001f240(undefined4 param_1,undefined4 param_2)

{
  void *this;
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030051;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(0x1c,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    puVar1 = (undefined4 *)FUN_1001f220(param_2);
    FUN_100156f0(this,puVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f2d0 at 1001f2d0

void __cdecl FUN_1001f2d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001f330(param_3);
  FUN_1001f300(param_2,uVar1);
  return;
}



// Function: FUN_1001f300 at 1001f300

void FUN_1001f300(undefined4 param_1,undefined4 param_2)

{
  FUN_1001f350(param_1,param_2);
  return;
}



// Function: FUN_1001f330 at 1001f330

undefined4 __cdecl FUN_1001f330(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1001f350 at 1001f350

void __cdecl FUN_1001f350(undefined4 param_1,undefined4 param_2)

{
  void *this;
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030081;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(0x1c,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    puVar1 = (undefined4 *)FUN_1001f330(param_2);
    FUN_100156f0(this,puVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001f3e0 at 1001f3e0

undefined4 * __fastcall FUN_1001f3e0(undefined4 *param_1)

{
  *param_1 = Define_the_symbol__ATL_MIXED::Thank_you::vftable;
  return param_1;
}



// Function: FUN_1001f400 at 1001f400

void FUN_1001f400(void)

{
  return;
}



// Function: FUN_1001f420 at 1001f420

undefined4 * __fastcall FUN_1001f420(undefined4 *param_1)

{
  *param_1 = CFCComGUID::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



// Function: FUN_1001f470 at 1001f470

undefined4 * __thiscall FUN_1001f470(void *this,uint param_1)

{
  FUN_1001f560((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1001f4b0 at 1001f4b0

undefined4 * __thiscall
FUN_1001f4b0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined ***)this = CFCComGUID::vftable;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 0x10) = param_4;
  return (undefined4 *)this;
}



// Function: FUN_1001f4f0 at 1001f4f0

undefined4 * __thiscall FUN_1001f4f0(void *this,void *param_1)

{
  *(undefined ***)this = CFCComGUID::vftable;
  FUN_1001f520(param_1,(undefined4 *)((int)this + 4));
  return (undefined4 *)this;
}



// Function: FUN_1001f520 at 1001f520

undefined4 * __thiscall FUN_1001f520(void *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)((int)this + 4);
  param_1[1] = *(undefined4 *)((int)this + 8);
  param_1[2] = *(undefined4 *)((int)this + 0xc);
  param_1[3] = *(undefined4 *)((int)this + 0x10);
  return param_1;
}



// Function: FUN_1001f560 at 1001f560

void __fastcall FUN_1001f560(undefined4 *param_1)

{
  *param_1 = CFCComGUID::vftable;
  return;
}



// Function: FUN_1001f580 at 1001f580

undefined4 * __thiscall FUN_1001f580(void *this,undefined4 *param_1)

{
  *param_1 = *(undefined4 *)((int)this + 4);
  param_1[1] = *(undefined4 *)((int)this + 8);
  param_1[2] = *(undefined4 *)((int)this + 0xc);
  param_1[3] = *(undefined4 *)((int)this + 0x10);
  return param_1;
}



// Function: FUN_1001f5c0 at 1001f5c0

undefined4 __thiscall FUN_1001f5c0(void *this,int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_10006430((void *)((int)this + 4),(void *)(param_1 + 4));
  return CONCAT31(extraout_var,CONCAT31(extraout_var,bVar1) == 1);
}



// Function: FUN_1001f600 at 1001f600

void __thiscall FUN_1001f600(void *this,int param_1)

{
  uint *puVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  int local_6c;
  uint local_64 [11];
  uint local_38 [11];
  void *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_38[0] = *(uint *)((int)this + 4);
  local_38[1] = (uint)*(ushort *)((int)this + 8);
  local_38[2] = (uint)*(ushort *)((int)this + 10);
  local_38[3] = (uint)*(byte *)((int)this + 0xc);
  local_38[4] = (uint)*(byte *)((int)this + 0xd);
  local_38[5] = (uint)*(byte *)((int)this + 0xe);
  local_38[6] = (uint)*(byte *)((int)this + 0xf);
  local_38[7] = (uint)*(byte *)((int)this + 0x10);
  local_38[8] = (uint)*(byte *)((int)this + 0x11);
  local_38[9] = (uint)*(byte *)((int)this + 0x12);
  local_38[10] = (uint)*(byte *)((int)this + 0x13);
  local_64[0] = *(uint *)(param_1 + 4);
  local_64[1] = (uint)*(ushort *)(param_1 + 8);
  local_64[2] = (uint)*(ushort *)(param_1 + 10);
  local_64[3] = (uint)*(byte *)(param_1 + 0xc);
  local_64[4] = (uint)*(byte *)(param_1 + 0xd);
  local_64[5] = (uint)*(byte *)(param_1 + 0xe);
  local_64[6] = (uint)*(byte *)(param_1 + 0xf);
  local_64[7] = (uint)*(byte *)(param_1 + 0x10);
  local_64[8] = (uint)*(byte *)(param_1 + 0x11);
  local_64[9] = (uint)*(byte *)(param_1 + 0x12);
  local_64[10] = (uint)*(byte *)(param_1 + 0x13);
  bVar3 = false;
  local_6c = 0;
  bVar4 = false;
  while (((local_6c < 0xb && (!bVar3)) && (!bVar4))) {
    bVar3 = local_38[local_6c] < local_64[local_6c];
    puVar1 = local_38 + local_6c;
    puVar2 = local_64 + local_6c;
    local_6c = local_6c + 1;
    bVar4 = *puVar2 < *puVar1;
  }
  local_c = this;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f770 at 1001f770

void __fastcall FUN_1001f770(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f7e0 at 1001f7e0

void __fastcall FUN_1001f7e0(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f850 at 1001f850

void __fastcall FUN_1001f850(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f8b0 at 1001f8b0

void __fastcall FUN_1001f8b0(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f910 at 1001f910

void __fastcall FUN_1001f910(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f970 at 1001f970

void __fastcall FUN_1001f970(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001f9d0 at 1001f9d0

void __fastcall FUN_1001f9d0(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001fa40 at 1001fa40

void __fastcall FUN_1001fa40(double *param_1)

{
  char cVar1;
  tm local_30;
  double *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = param_1;
  cVar1 = FUN_10021b50(param_1);
  if (cVar1 != '\0') {
    FUN_10020ba0(&local_30,*local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001fab0 at 1001fab0

undefined1 __fastcall FUN_1001fab0(double *param_1)

{
  uint uVar1;
  undefined1 local_50;
  
  uVar1 = FUN_1001f770(param_1);
  if (((uVar1 == 0x80000000) || ((uVar1 & 3) != 0)) ||
     (((int)uVar1 % 100 == 0 && ((int)uVar1 % 400 != 0)))) {
    local_50 = 0;
  }
  else {
    local_50 = 1;
  }
  return local_50;
}



// Function: FUN_1001fb10 at 1001fb10

undefined1 __fastcall FUN_1001fb10(double *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1001f8b0(param_1);
  if (((iVar1 == 0xc) && (iVar1 = FUN_1001f910(param_1), iVar1 == 0)) &&
     (iVar1 = FUN_1001f970(param_1), iVar1 == 0)) {
    return 1;
  }
  return 0;
}



// Function: FUN_1001fb60 at 1001fb60

undefined1 __fastcall FUN_1001fb60(double *param_1)

{
  int iVar1;
  
  iVar1 = FUN_1001f8b0(param_1);
  if (((iVar1 == 0) && (iVar1 = FUN_1001f910(param_1), iVar1 == 0)) &&
     (iVar1 = FUN_1001f970(param_1), iVar1 == 0)) {
    return 1;
  }
  return 0;
}



// Function: FUN_1001fbb0 at 1001fbb0

undefined8 * __thiscall FUN_1001fbb0(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  undefined2 uStack_10;
  undefined4 uStack_e;
  undefined2 uStack_a;
  undefined8 *local_8;
  
  local_8 = (undefined8 *)this;
  if (*param_1 == 7) {
    *(undefined8 *)this = *(undefined8 *)(param_1 + 4);
  }
  else {
    local_18 = 0;
    local_16 = 0;
    local_12 = 0;
    uStack_10 = 0;
    uStack_e = 0;
    uStack_a = 0;
    iVar1 = Ordinal_12(&local_18,param_1,0,7);
    if (iVar1 < 0) {
      FUN_10021bc0(local_8);
    }
    else {
      *local_8 = CONCAT26(uStack_a,CONCAT42(uStack_e,uStack_10));
      Ordinal_9(&local_18);
    }
  }
  return local_8;
}



// Function: FUN_1001fc30 at 1001fc30

undefined8 * __thiscall FUN_1001fc30(void *this,undefined8 param_1)

{
  *(undefined8 *)this = param_1;
  return (undefined8 *)this;
}



// Function: FUN_1001fc50 at 1001fc50

void FUN_1001fc50(__time64_t *param_1)

{
  char cVar1;
  int iVar2;
  tm local_30;
  undefined8 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_10021a90(&local_30,param_1);
  if (iVar2 == 0) {
    cVar1 = FUN_10020c90(local_c,(short)local_30.tm_year + 0x76c,(short)local_30.tm_mon + 1,
                         (undefined2)local_30.tm_mday,(undefined2)local_30.tm_hour,
                         (undefined2)local_30.tm_min,(undefined2)local_30.tm_sec);
    if (cVar1 != '\0') goto LAB_1001fcbf;
  }
  FUN_10021bc0(local_c);
LAB_1001fcbf:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001fce0 at 1001fce0

void * __thiscall FUN_1001fce0(void *this,undefined4 *param_1)

{
  FUN_10020220(this,(short)param_1[5] + 0x76c,(short)param_1[4] + 1,(short)param_1[3],
               (short)param_1[2],(short)param_1[1],(short)*param_1);
  return this;
}



// Function: FUN_1001fd40 at 1001fd40

undefined8 * __thiscall FUN_1001fd40(void *this,undefined2 *param_1)

{
  char cVar1;
  
  cVar1 = FUN_10020c90(this,*param_1,param_1[1],param_1[3],param_1[4],param_1[5],param_1[6]);
  if (cVar1 == '\0') {
    FUN_10021bc0((undefined8 *)this);
  }
  return (undefined8 *)this;
}



// Function: FUN_1001fdb0 at 1001fdb0

void FUN_1001fdb0(FILETIME *param_1)

{
  char cVar1;
  BOOL BVar2;
  _SYSTEMTIME local_24;
  _FILETIME local_14;
  undefined8 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  BVar2 = FileTimeToLocalFileTime(param_1,&local_14);
  if (BVar2 == 0) {
    FUN_10021bc0(local_c);
  }
  else {
    BVar2 = FileTimeToSystemTime(&local_14,&local_24);
    if (BVar2 != 0) {
      cVar1 = FUN_10020c90(local_c,local_24.wYear,local_24.wMonth,local_24.wDay,local_24.wHour,
                           local_24.wMinute,local_24.wSecond);
      if (cVar1 != '\0') goto LAB_1001fe2d;
    }
    FUN_10021bc0(local_c);
  }
LAB_1001fe2d:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001fe50 at 1001fe50

undefined4 * __thiscall FUN_1001fe50(void *this,undefined4 *param_1)

{
  undefined8 uVar1;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = *this;
  *param_1 = 7;
  param_1[1] = 0;
  param_1[2] = (int)uVar1;
  param_1[3] = (int)((ulonglong)uVar1 >> 0x20);
  return param_1;
}



// Function: FUN_1001feb0 at 1001feb0

undefined8 FUN_1001feb0(void)

{
  return 0;
}



// Function: FUN_1001fee0 at 1001fee0

void __thiscall FUN_1001fee0(void *this,undefined4 *param_1)

{
  int iVar1;
  void **ppvVar2;
  void *local_30 [10];
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_30[9] = this;
  local_30[0] = (void *)0x0;
  local_30[1] = (void *)0x0;
  local_30[2] = (void *)0x0;
  local_30[3] = (void *)0x0;
  local_30[4] = (void *)0x0;
  local_30[5] = (void *)0x0;
  local_30[6] = (void *)0x0;
  local_30[7] = (void *)0x0;
  local_30[8] = (void *)0x0;
  ppvVar2 = local_30;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *ppvVar2;
    ppvVar2 = ppvVar2 + 1;
    param_1 = param_1 + 1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001ff40 at 1001ff40

void FUN_1001ff40(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001ffa0 at 1001ffa0

undefined4 * FUN_1001ffa0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}



// Function: FUN_1001ffe0 at 1001ffe0

void __thiscall FUN_1001ffe0(void *this,undefined4 *param_1)

{
  char cVar1;
  tm local_40;
  short local_1c;
  short sStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 local_12;
  undefined2 uStack_10;
  undefined2 local_e;
  undefined8 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_1c = 0;
  sStack_1a = 0;
  uStack_18 = 0;
  uStack_16 = 0;
  uStack_14 = 0;
  local_12 = 0;
  uStack_10 = 0;
  local_e = 0;
  local_c = (undefined8 *)this;
  cVar1 = FUN_10021b50((double *)this);
  if (cVar1 != '\0') {
    cVar1 = FUN_10020ba0(&local_40,*local_c);
    if (cVar1 != '\0') {
      uStack_18 = (undefined2)local_40.tm_mday;
      sStack_1a = (short)local_40.tm_mon + 1;
      local_1c = (short)local_40.tm_year + 0x76c;
      uStack_16 = (undefined2)local_40.tm_hour;
      uStack_14 = (undefined2)local_40.tm_min;
      local_12 = (undefined2)local_40.tm_sec;
    }
  }
  *param_1 = CONCAT22(sStack_1a,local_1c);
  param_1[1] = CONCAT22(uStack_16,uStack_18);
  param_1[2] = CONCAT22(local_12,uStack_14);
  param_1[3] = CONCAT22(local_e,uStack_10);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100200a0 at 100200a0

undefined4 __thiscall FUN_100200a0(void *this,double *param_1)

{
  undefined2 extraout_var;
  float10 fVar1;
  float10 fVar2;
  bool local_54;
  
                    /* WARNING: Load size is inaccurate */
  fVar1 = FUN_10020c50(*this);
  fVar2 = FUN_10020c50(*param_1);
  fVar1 = (float10)(double)fVar1;
  local_54 = fVar2 < fVar1 == 0 && (fVar2 == fVar1) == 0;
  return CONCAT31((int3)(CONCAT22(extraout_var,
                                  (ushort)(fVar2 < fVar1) << 8 |
                                  (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                                  (ushort)(fVar2 == fVar1) << 0xe) >> 8),local_54);
}



// Function: FUN_10020100 at 10020100

undefined4 __thiscall FUN_10020100(void *this,double *param_1)

{
  undefined2 extraout_var;
  float10 fVar1;
  float10 fVar2;
  
                    /* WARNING: Load size is inaccurate */
  fVar1 = FUN_10020c50(*this);
  fVar2 = FUN_10020c50(*param_1);
  fVar1 = (float10)(double)fVar1;
  return CONCAT31((int3)(CONCAT22(extraout_var,
                                  (ushort)(fVar2 < fVar1) << 8 |
                                  (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                                  (ushort)(fVar2 == fVar1) << 0xe) >> 8),fVar2 < fVar1);
}



// Function: FUN_10020160 at 10020160

undefined4 __thiscall FUN_10020160(void *this,double *param_1)

{
  undefined2 extraout_var;
  float10 fVar1;
  float10 fVar2;
  
                    /* WARNING: Load size is inaccurate */
  fVar1 = FUN_10020c50(*this);
  fVar2 = FUN_10020c50(*param_1);
  fVar1 = (float10)(double)fVar1;
  return CONCAT31((int3)(CONCAT22(extraout_var,
                                  (ushort)(fVar2 < fVar1) << 8 |
                                  (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                                  (ushort)(fVar2 == fVar1) << 0xe) >> 8),fVar2 < fVar1 == 0);
}



// Function: FUN_100201c0 at 100201c0

undefined4 __thiscall FUN_100201c0(void *this,double *param_1)

{
  undefined2 extraout_var;
  float10 fVar1;
  float10 fVar2;
  
                    /* WARNING: Load size is inaccurate */
  fVar1 = FUN_10020c50(*this);
  fVar2 = FUN_10020c50(*param_1);
  fVar1 = (float10)(double)fVar1;
  return CONCAT31((int3)(CONCAT22(extraout_var,
                                  (ushort)(fVar2 < fVar1) << 8 |
                                  (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                                  (ushort)(fVar2 == fVar1) << 0xe) >> 8),
                  fVar2 < fVar1 != (fVar2 == fVar1));
}



// Function: FUN_10020220 at 10020220

void __thiscall
FUN_10020220(void *this,undefined2 param_1,ushort param_2,undefined2 param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6)

{
  char cVar1;
  
  cVar1 = FUN_10020c90(this,param_1,param_2,param_3,param_4,param_5,param_6);
  if (cVar1 == '\0') {
    FUN_10021bc0((undefined8 *)this);
  }
  FUN_10021b50((double *)this);
  return;
}



// Function: FUN_10020280 at 10020280

void __thiscall FUN_10020280(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  
  FUN_10002a10();
  pvVar3 = this;
  uVar1 = FUN_100202d0(param_1);
  iVar2 = Ordinal_94(uVar1,param_3,param_2,pvVar3);
  if (iVar2 < 0) {
    FUN_10021bc0((undefined8 *)this);
  }
  FUN_10021b50((double *)this);
  return;
}



// Function: FUN_100202d0 at 100202d0

undefined4 __cdecl FUN_100202d0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100202f0 at 100202f0

wchar_t * __thiscall
FUN_100202f0(void *this,wchar_t *param_1,undefined4 param_2,undefined4 param_3,rsize_t param_4)

{
  char cVar1;
  int iVar2;
  wchar_t *local_c;
  undefined8 *local_8;
  
  *param_1 = L'\0';
  local_8 = (undefined8 *)this;
  cVar1 = FUN_10021b50((double *)this);
  if (cVar1 != '\0') {
    local_c = (wchar_t *)0x0;
    iVar2 = Ordinal_114(*local_8,param_3,param_2,&local_c);
    if (-1 < iVar2) {
      wcscpy_s(param_1,param_4,local_c);
      Ordinal_6(local_c);
    }
  }
  return param_1;
}



// Function: FUN_10020370 at 10020370

void __thiscall FUN_10020370(void *this,wchar_t *param_1,wchar_t *param_2)

{
  char cVar1;
  tm local_30;
  undefined8 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  *param_1 = L'\0';
  local_c = (undefined8 *)this;
  cVar1 = FUN_10021b50((double *)this);
  if ((cVar1 != '\0') && (cVar1 = FUN_10020ba0(&local_30,*local_c), cVar1 != '\0')) {
    wcsftime(param_1,0x1000,param_2,&local_30);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100203f0 at 100203f0

void __thiscall FUN_100203f0(void *this,wchar_t *param_1,wchar_t *param_2,rsize_t param_3)

{
  char cVar1;
  int *piVar2;
  wchar_t *_Src;
  int local_94 [17];
  undefined1 local_50 [12];
  undefined4 local_44;
  wchar_t *local_40;
  tm local_3c;
  undefined8 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100300ab;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = L'\0';
  local_18 = (undefined8 *)this;
  cVar1 = FUN_10021b50((double *)this);
  if ((cVar1 != '\0') && (cVar1 = FUN_10020ba0(&local_3c,*local_18), cVar1 != '\0')) {
    local_40 = _wsetlocale(0,(wchar_t *)0x0);
    _wsetlocale(0,L".OCP");
    local_44 = 0x76c;
    FUN_10020540(local_50,(short)local_3c.tm_year + 0x76c,(short)local_3c.tm_mon + 1,
                 (undefined2)local_3c.tm_mday,(undefined2)local_3c.tm_hour,
                 (undefined2)local_3c.tm_min,(undefined2)local_3c.tm_sec);
    piVar2 = (int *)FUN_10020760(local_50,local_94,param_2);
    local_8 = 0;
    _Src = (wchar_t *)FUN_10021150(piVar2);
    wcscpy_s(param_1,param_3,_Src);
    local_8 = 0xffffffff;
    FUN_10021370(local_94);
    _wsetlocale(0,local_40);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020540 at 10020540

void * __thiscall
FUN_10020540(void *this,short param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6)

{
  FUN_10020580(param_1,param_2,param_3,param_4,param_5,param_6);
  return this;
}



// Function: FUN_10020580 at 10020580

void FUN_10020580(short param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5,undefined2 param_6)

{
  int iVar1;
  short local_1c;
  undefined2 local_1a;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  void *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  memset(&local_1c,0,0x10);
  local_1c = param_1;
  local_1a = param_2;
  local_16 = param_3;
  local_14 = param_4;
  local_12 = param_5;
  local_10 = param_6;
  iVar1 = FUN_10020610(local_c,&local_1c);
  *(uint *)((int)local_c + 8) = (uint)(iVar1 == 0);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020610 at 10020610

void __thiscall FUN_10020610(void *this,short *param_1)

{
  FUN_10020640(param_1,(undefined8 *)this);
  return;
}



// Function: FUN_10020640 at 10020640

void __cdecl FUN_10020640(short *param_1,undefined8 *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 local_64;
  short local_20;
  short local_1e;
  short local_1a;
  short local_18;
  short local_16;
  short local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_c = (uint)(param_2 != (undefined8 *)0x0);
  if (local_c == 0) {
    FUN_10003210(0x80004005);
  }
  local_10 = Ordinal_184(param_1,param_2);
  memset(&local_20,0,0x10);
  if ((local_10 == 0) || (iVar2 = Ordinal_185(*param_2,&local_20), iVar2 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((((bVar1) && (*param_1 == local_20)) && (param_1[1] == local_1e)) &&
     (((param_1[3] == local_1a && (param_1[4] == local_18)) &&
      ((param_1[5] == local_16 && (param_1[6] == local_14)))))) {
    local_64 = 1;
  }
  else {
    local_64 = 0;
  }
  local_10 = local_64;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020760 at 10020760

void __thiscall FUN_10020760(void *this,void *param_1,wchar_t *param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  wchar_t *_Buf;
  size_t _SizeInWords;
  tm *_Tm;
  int local_60;
  tm local_5c;
  int local_38;
  ushort local_34;
  ushort local_32;
  ushort local_30;
  ushort local_2e;
  ushort local_2c;
  ushort local_2a;
  ushort local_28;
  ushort local_24;
  int local_20;
  uint local_1c;
  undefined8 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030117;
  local_10 = ExceptionList;
  uVar2 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = (uint)(param_2 != (wchar_t *)0x0);
  local_18 = (undefined8 *)this;
  local_14 = uVar2;
  if (local_1c == 0) {
    FUN_10003210(0x80070057);
  }
  iVar3 = FUN_10020a10((int)local_18);
  if (iVar3 == 2) {
    FUN_100212f0(param_1,L"");
    local_8 = 0;
  }
  else {
    iVar3 = FUN_10020a10((int)local_18);
    if (iVar3 == 1) {
      FUN_10021230(&local_20);
      local_8 = 1;
      bVar1 = FUN_100213d0(&local_20,0xd800);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        FUN_100212f0(param_1,L"Invalid DateTime");
        local_8 = local_8 & 0xffffff00;
        FUN_10021370(&local_20);
      }
      else {
        FUN_10021290(param_1,&local_20);
        local_8 = local_8 & 0xffffff00;
        FUN_10021370(&local_20);
      }
    }
    else {
      iVar3 = Ordinal_331(*local_18,0,&local_34,uVar2);
      if (iVar3 == 0) {
        local_5c.tm_sec = (int)local_28;
        local_5c.tm_min = (int)local_2a;
        local_5c.tm_hour = (int)local_2c;
        local_5c.tm_mday = (int)local_2e;
        local_5c.tm_mon = local_32 - 1;
        local_5c.tm_year = local_34 - 0x76c;
        local_5c.tm_wday = (int)local_30;
        local_5c.tm_yday = local_24 - 1;
        local_5c.tm_isdst = 0;
        FUN_10021230(&local_60);
        local_8 = 3;
        _Buf = (wchar_t *)FUN_100211a0(&local_60,0x100);
        _Tm = &local_5c;
        _SizeInWords = FUN_10021ff0(&local_60);
        wcsftime(_Buf,_SizeInWords,param_2,_Tm);
        FUN_100211e0(&local_60,0xffffffff);
        FUN_10021290(param_1,&local_60);
        local_8 = local_8 & 0xffffff00;
        FUN_10021370(&local_60);
      }
      else {
        FUN_10021230(&local_38);
        local_8 = 2;
        bVar1 = FUN_100213d0(&local_38,0xd800);
        if (CONCAT31(extraout_var_00,bVar1) == 0) {
          FUN_100212f0(param_1,L"Invalid DateTime");
          local_8 = local_8 & 0xffffff00;
          FUN_10021370(&local_38);
        }
        else {
          FUN_10021290(param_1,&local_38);
          local_8 = local_8 & 0xffffff00;
          FUN_10021370(&local_38);
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020a10 at 10020a10

undefined4 __fastcall FUN_10020a10(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10020a30 at 10020a30

void FUN_10020a30(wchar_t *param_1,UINT param_2,HINSTANCE param_3)

{
  int iVar1;
  WCHAR local_20c [256];
  void *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  *param_1 = L'\0';
  iVar1 = LoadStringW(param_3,param_2,local_20c,0x100);
  if (iVar1 != 0) {
    FUN_10020370(local_c,param_1,local_20c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020aa0 at 10020aa0

void FUN_10020aa0(LPWSTR param_1,LPCWSTR param_2,DWORD param_3,LCID param_4)

{
  int iVar1;
  SYSTEMTIME local_1c;
  undefined8 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  memset(&local_1c,0,0x10);
  *param_1 = L'\0';
  iVar1 = Ordinal_185(*local_c,&local_1c);
  if (iVar1 != 0) {
    GetDateFormatW(param_4,param_3,&local_1c,param_2,param_1,0xff);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020b20 at 10020b20

void FUN_10020b20(LPWSTR param_1,LPCWSTR param_2,DWORD param_3,LCID param_4)

{
  int iVar1;
  SYSTEMTIME local_1c;
  undefined8 *local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  memset(&local_1c,0,0x10);
  *param_1 = L'\0';
  iVar1 = Ordinal_185(*local_c,&local_1c);
  if (iVar1 != 0) {
    GetTimeFormatW(param_4,param_3,&local_1c,param_2,param_1,0xff);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020ba0 at 10020ba0

void __cdecl FUN_10020ba0(tm *param_1,undefined8 param_2)

{
  int iVar1;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  ushort local_12;
  ushort local_10;
  ushort local_e;
  ushort local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  iVar1 = Ordinal_185(param_2,&local_18);
  if (iVar1 != 0) {
    param_1->tm_sec = (uint)local_c;
    param_1->tm_min = (uint)local_e;
    param_1->tm_hour = (uint)local_10;
    param_1->tm_mday = (uint)local_12;
    param_1->tm_mon = local_16 - 1;
    param_1->tm_year = local_18 - 0x76c;
    param_1->tm_wday = (uint)local_14;
    param_1->tm_isdst = -1;
    FUN_10021ac0(param_1);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020c50 at 10020c50

float10 __cdecl FUN_10020c50(double param_1)

{
  float10 fVar1;
  double dVar2;
  
  if (NAN(param_1) || 0.0 < param_1 == (param_1 == 0.0)) {
    dVar2 = ceil(param_1);
    fVar1 = (float10)dVar2 - ((float10)param_1 - (float10)dVar2);
  }
  else {
    fVar1 = (float10)param_1;
  }
  return fVar1;
}



// Function: FUN_10020c90 at 10020c90

void __cdecl
FUN_10020c90(undefined4 param_1,undefined2 param_2,ushort param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  undefined2 local_18;
  uint local_16;
  undefined2 local_12;
  undefined2 uStack_10;
  undefined2 local_e;
  undefined2 uStack_c;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_a = 0;
  local_18 = param_2;
  local_16 = (uint)param_3;
  _local_12 = CONCAT22(param_5,param_4);
  _local_e = CONCAT22(param_7,param_6);
  Ordinal_184(&local_18,param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10020d10 at 10020d10

ulonglong __fastcall FUN_10020d10(double *param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar1;
  double local_10;
  double *local_8;
  
  local_8 = param_1;
  local_10 = modf(*param_1,&local_10);
  uVar1 = FUN_1002c2d0(extraout_ECX,extraout_EDX);
  return uVar1;
}



// Function: FUN_10020d50 at 10020d50

ulonglong __fastcall FUN_10020d50(double *param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar1;
  double local_10;
  double *local_8;
  
  local_8 = param_1;
  local_10 = modf(*param_1 * 24.0,&local_10);
  uVar1 = FUN_1002c2d0(extraout_ECX,extraout_EDX);
  return uVar1;
}



// Function: FUN_10020da0 at 10020da0

ulonglong __fastcall FUN_10020da0(double *param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  ulonglong uVar1;
  double local_10;
  double *local_8;
  
  local_8 = param_1;
  local_10 = modf(*param_1 * 24.0 * 60.0,&local_10);
  uVar1 = FUN_1002c2d0(extraout_ECX,extraout_EDX);
  return uVar1;
}



// Function: FUN_10020df0 at 10020df0

void __thiscall FUN_10020df0(void *this,int param_1,int param_2,int param_3,int param_4)

{
  *(double *)this =
       (double)param_4 / 86400.0 +
       (double)param_3 / 1440.0 + (double)param_2 / 24.0 + (double)param_1;
  return;
}



// Function: FUN_10020e30 at 10020e30

void __thiscall FUN_10020e30(double *param_1,int param_2,int param_3,int param_4,double param_5)

{
  *param_1 = param_5 / 86400.0 + (double)param_4 / 1440.0 + (double)param_3 / 24.0 + (double)param_2
  ;
  return;
}



// Function: FUN_10020e70 at 10020e70

void * __cdecl FUN_10020e70(void *param_1,double *param_2,double *param_3)

{
  char cVar1;
  uint uVar2;
  float10 fVar3;
  float10 fVar4;
  undefined8 local_c;
  
  FUN_10021ae0(&local_c);
  cVar1 = FUN_10021b50(param_2);
  if (cVar1 != '\0') {
    uVar2 = FUN_10021cc0(param_3);
    if ((uVar2 & 0xff) != 0) {
      fVar3 = FUN_10021b30(param_2);
      fVar3 = FUN_10020c50((double)fVar3);
      fVar4 = FUN_10021ca0(param_3);
      fVar3 = FUN_10020ef0((double)(fVar4 + (float10)(double)fVar3));
      FUN_1001fc30(&local_c,(double)fVar3);
    }
  }
  FUN_10021b00(param_1,&local_c);
  return param_1;
}



// Function: FUN_10020ef0 at 10020ef0

float10 __cdecl FUN_10020ef0(double param_1)

{
  float10 fVar1;
  double dVar2;
  
  if (NAN(param_1) || 0.0 < param_1 == (param_1 == 0.0)) {
    dVar2 = floor(param_1);
    fVar1 = ((float10)dVar2 - (float10)param_1) + (float10)dVar2;
  }
  else {
    fVar1 = (float10)param_1;
  }
  return fVar1;
}



// Function: FUN_10020f30 at 10020f30

void * __cdecl FUN_10020f30(void *param_1,double *param_2,double *param_3)

{
  char cVar1;
  uint uVar2;
  float10 fVar3;
  float10 fVar4;
  undefined8 local_c;
  
  FUN_10021ae0(&local_c);
  cVar1 = FUN_10021b50(param_3);
  if (cVar1 != '\0') {
    uVar2 = FUN_10021cc0(param_2);
    if ((uVar2 & 0xff) != 0) {
      fVar3 = FUN_10021b30(param_3);
      fVar3 = FUN_10020c50((double)fVar3);
      fVar4 = FUN_10021ca0(param_2);
      fVar3 = FUN_10020ef0((double)(fVar4 + (float10)(double)fVar3));
      FUN_1001fc30(&local_c,(double)fVar3);
    }
  }
  FUN_10021b00(param_1,&local_c);
  return param_1;
}



// Function: FUN_10020fb0 at 10020fb0

void * __cdecl FUN_10020fb0(void *param_1,double *param_2,double *param_3)

{
  char cVar1;
  uint uVar2;
  float10 fVar3;
  float10 fVar4;
  undefined8 local_c;
  
  FUN_10021ae0(&local_c);
  cVar1 = FUN_10021b50(param_2);
  if (cVar1 != '\0') {
    uVar2 = FUN_10021cc0(param_3);
    if ((uVar2 & 0xff) != 0) {
      fVar3 = FUN_10021b30(param_2);
      fVar3 = FUN_10020c50((double)fVar3);
      fVar4 = FUN_10021ca0(param_3);
      fVar3 = FUN_10020ef0((double)((float10)(double)fVar3 - fVar4));
      FUN_1001fc30(&local_c,(double)fVar3);
    }
  }
  FUN_10021b00(param_1,&local_c);
  return param_1;
}



// Function: FUN_10021030 at 10021030

void * __cdecl FUN_10021030(void *param_1,double *param_2,double *param_3)

{
  char cVar1;
  float10 fVar2;
  float10 fVar3;
  undefined8 local_c;
  
  FUN_10021be0(&local_c);
  cVar1 = FUN_10021b50(param_2);
  if (cVar1 != '\0') {
    cVar1 = FUN_10021b50(param_3);
    if (cVar1 != '\0') {
      fVar2 = FUN_10021b30(param_2);
      fVar2 = FUN_10020c50((double)fVar2);
      fVar3 = FUN_10021b30(param_3);
      fVar3 = FUN_10020c50((double)fVar3);
      FUN_10021c30(&local_c,(double)((float10)(double)fVar2 - fVar3));
    }
  }
  FUN_10021c00(param_1,&local_c);
  return param_1;
}



// Function: FUN_100210c0 at 100210c0

void * __cdecl FUN_100210c0(void *param_1,double *param_2,double *param_3)

{
  uint uVar1;
  undefined8 local_c;
  
  FUN_10021be0(&local_c);
  uVar1 = FUN_10021cc0(param_2);
  if ((uVar1 & 0xff) != 0) {
    uVar1 = FUN_10021cc0(param_3);
    if ((uVar1 & 0xff) != 0) {
      FUN_10021c30(&local_c,*param_2 + *param_3);
    }
  }
  FUN_10021c00(param_1,&local_c);
  return param_1;
}



// Function: FUN_10021120 at 10021120

void * __cdecl FUN_10021120(void *param_1,double *param_2,void *param_3)

{
  double *pdVar1;
  undefined1 local_4c [72];
  
  pdVar1 = (double *)FUN_10021c50(param_3,local_4c);
  FUN_100210c0(param_1,param_2,pdVar1);
  return param_1;
}



// Function: FUN_10021150 at 10021150

int __fastcall FUN_10021150(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_10021dc0(param_1);
  bVar1 = FUN_10021a20(iVar2);
  if (bVar1) {
    FUN_10022210(param_1,*(int *)(iVar2 + 4));
  }
  return *param_1;
}



// Function: FUN_100211a0 at 100211a0

undefined4 __thiscall FUN_100211a0(void *this,int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10021fc0(this,param_1);
  FUN_10021de0(this,param_1);
  return uVar1;
}



// Function: FUN_100211e0 at 100211e0

void __thiscall FUN_100211e0(void *this,size_t param_1)

{
  int iVar1;
  
  if (param_1 == 0xffffffff) {
    iVar1 = FUN_10021dc0((int *)this);
                    /* WARNING: Load size is inaccurate */
    param_1 = FUN_100220c0(*this,*(size_t *)(iVar1 + 8));
  }
  FUN_10021de0(this,param_1);
  return;
}



// Function: FUN_10021230 at 10021230

void * __fastcall FUN_10021230(void *param_1)

{
  undefined **ppuVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030148;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ppuVar1 = FUN_100218c0();
  FUN_10021410(param_1,(int *)ppuVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10021290 at 10021290

void * __thiscall FUN_10021290(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030178;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10021470(this,param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100212f0 at 100212f0

void * __thiscall FUN_100212f0(void *this,wchar_t *param_1)

{
  char cVar1;
  undefined **ppuVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100301a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ppuVar2 = FUN_100218c0();
  FUN_10021410(this,(int *)ppuVar2);
  local_8 = 0;
  cVar1 = FUN_10021760(this,(uint)param_1);
  if (cVar1 == '\0') {
    FUN_100214e0(this,param_1);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10021370 at 10021370

void __fastcall FUN_10021370(int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100301d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_100214b0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100213d0 at 100213d0

bool __thiscall FUN_100213d0(void *this,uint param_1)

{
  bool bVar1;
  HMODULE pHVar2;
  
  pHVar2 = (HMODULE)FUN_100217b0(param_1);
  if (pHVar2 == (HMODULE)0x0) {
    bVar1 = false;
  }
  else {
    bVar1 = FUN_10021510(this,pHVar2,param_1);
  }
  return bVar1;
}



// Function: FUN_10021410 at 10021410

void * __thiscall FUN_10021410(void *this,int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_10003210(0x80004005);
  }
  iVar1 = (**(code **)(*param_1 + 0xc))();
  FUN_10021d90(this,iVar1);
  return this;
}



// Function: FUN_10021470 at 10021470

void * __thiscall FUN_10021470(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_10021dc0(param_1);
  piVar1 = FUN_100218e0(piVar1);
  FUN_10021d90(this,(int)piVar1);
  return this;
}



// Function: FUN_100214b0 at 100214b0

void __fastcall FUN_100214b0(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10021dc0(param_1);
  FUN_10021a50(puVar1);
  return;
}



// Function: FUN_100214e0 at 100214e0

void * __thiscall FUN_100214e0(void *this,wchar_t *param_1)

{
  FUN_10021d30(this,param_1);
  return this;
}



// Function: FUN_10021510 at 10021510

bool __thiscall FUN_10021510(void *this,HMODULE param_1,uint param_2)

{
  ushort *puVar1;
  rsize_t rVar2;
  wchar_t *pwVar3;
  
  puVar1 = FUN_10021660(param_1,param_2);
  if (puVar1 != (ushort *)0x0) {
    rVar2 = FUN_100215a0(puVar1 + 1,(uint)*puVar1);
    pwVar3 = (wchar_t *)FUN_10021fc0(this,rVar2);
    FUN_100215c0(pwVar3,rVar2,(wchar_t *)(puVar1 + 1),(uint)*puVar1);
    FUN_10022030(this,rVar2);
  }
  return puVar1 != (ushort *)0x0;
}



// Function: FUN_100215a0 at 100215a0

undefined4 __cdecl FUN_100215a0(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_100215c0 at 100215c0

void __cdecl FUN_100215c0(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  int iVar1;
  
  if (param_4 == 0xffffffff) {
    iVar1 = FUN_10021600(param_3);
    param_4 = iVar1 + 1;
  }
  FUN_10021620(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_10021600 at 10021600

void __cdecl FUN_10021600(wchar_t *param_1)

{
  wcslen(param_1);
  return;
}



// Function: FUN_10021620 at 10021620

void __cdecl FUN_10021620(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wmemcpy_s(param_1,param_2,param_3,param_4);
  FUN_10003150(eVar1);
  return;
}



// Function: FUN_10021660 at 10021660

ushort * __cdecl FUN_10021660(HMODULE param_1,uint param_2)

{
  HRSRC pHVar1;
  ushort *puVar2;
  
  pHVar1 = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if (pHVar1 == (HRSRC)0x0) {
    puVar2 = (ushort *)0x0;
  }
  else {
    puVar2 = FUN_100216b0(param_1,pHVar1,param_2);
  }
  return puVar2;
}



// Function: FUN_100216b0 at 100216b0

ushort * __cdecl FUN_100216b0(HMODULE param_1,HRSRC param_2,uint param_3)

{
  HGLOBAL hResData;
  DWORD DVar1;
  ushort *puVar2;
  uint local_18;
  ushort *local_8;
  
  hResData = LoadResource(param_1,param_2);
  if (hResData == (HGLOBAL)0x0) {
    local_8 = (ushort *)0x0;
  }
  else {
    local_8 = (ushort *)LockResource(hResData);
    if (local_8 == (ushort *)0x0) {
      local_8 = (ushort *)0x0;
    }
    else {
      DVar1 = SizeofResource(param_1,param_2);
      puVar2 = (ushort *)((int)local_8 + DVar1);
      local_18 = param_3 & 0xf;
      for (; (local_18 != 0 && (local_8 < puVar2)); local_8 = local_8 + *local_8 + 1) {
        local_18 = local_18 - 1;
      }
      if (local_8 < puVar2) {
        if (*local_8 == 0) {
          local_8 = (ushort *)0x0;
        }
      }
      else {
        local_8 = (ushort *)0x0;
      }
    }
  }
  return local_8;
}



// Function: FUN_10021760 at 10021760

undefined1 __thiscall FUN_10021760(void *this,uint param_1)

{
  undefined1 local_9;
  
  local_9 = 0;
  if ((param_1 != 0) && (param_1 >> 0x10 == 0)) {
    FUN_100213d0(this,param_1 & 0xffff);
    local_9 = 1;
  }
  return local_9;
}



// Function: FUN_100217b0 at 100217b0

void __cdecl FUN_100217b0(uint param_1)

{
  FUN_100217d0(param_1,0);
  return;
}



// Function: FUN_100217d0 at 100217d0

HMODULE __cdecl FUN_100217d0(uint param_1,WORD param_2)

{
  ushort *puVar1;
  int local_10;
  HMODULE local_c;
  
  local_c = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_100458a4,0);
  local_10 = 1;
  while( true ) {
    if (local_c == (HMODULE)0x0) {
      return (HMODULE)0x0;
    }
    puVar1 = FUN_10021860(local_c,param_1,param_2);
    if (puVar1 != (ushort *)0x0) break;
    local_c = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_100458a4,local_10);
    local_10 = local_10 + 1;
  }
  return local_c;
}



// Function: FUN_10021860 at 10021860

ushort * __cdecl FUN_10021860(HMODULE param_1,uint param_2,WORD param_3)

{
  HRSRC pHVar1;
  ushort *puVar2;
  
  pHVar1 = FindResourceExW(param_1,(LPCWSTR)0x6,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),param_3);
  if (pHVar1 == (HRSRC)0x0) {
    puVar2 = (ushort *)0x0;
  }
  else {
    puVar2 = FUN_100216b0(param_1,pHVar1,param_2);
  }
  return puVar2;
}



// Function: FUN_100218c0 at 100218c0

undefined ** FUN_100218c0(void)

{
  return &PTR_PTR_10043b5c;
}



// Function: FUN_100218e0 at 100218e0

int * __cdecl FUN_100218e0(int *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int *local_8;
  
  puVar2 = (undefined4 *)(**(code **)(*(int *)*param_1 + 0x10))();
  bVar1 = FUN_100219f0((int)param_1);
  if ((bVar1) || (puVar2 != (undefined4 *)*param_1)) {
    local_8 = (int *)(**(code **)*puVar2)(param_1[1],2);
    if (local_8 == (int *)0x0) {
      FUN_10022350();
    }
    local_8[1] = param_1[1];
    iVar6 = param_1[1] + 1;
    pvVar3 = (void *)FUN_100219a0((int)param_1);
    iVar4 = param_1[1] + 1;
    pvVar5 = (void *)FUN_100219a0((int)local_8);
    FUN_10022060(pvVar5,iVar4,pvVar3,iVar6);
  }
  else {
    local_8 = param_1;
    FUN_100219c0((int)param_1);
  }
  return local_8;
}



// Function: FUN_100219a0 at 100219a0

int __fastcall FUN_100219a0(int param_1)

{
  return param_1 + 0x10;
}



// Function: FUN_100219c0 at 100219c0

void __fastcall FUN_100219c0(int param_1)

{
  LOCK();
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  UNLOCK();
  return;
}



// Function: FUN_100219f0 at 100219f0

bool __fastcall FUN_100219f0(int param_1)

{
  return *(int *)(param_1 + 0xc) < 0;
}



// Function: FUN_10021a20 at 10021a20

bool __fastcall FUN_10021a20(int param_1)

{
  return 1 < *(int *)(param_1 + 0xc);
}



// Function: FUN_10021a50 at 10021a50

void __fastcall FUN_10021a50(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 3;
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  if (iVar1 == 1 || iVar1 + -1 < 0) {
    (**(code **)(*(int *)*param_1 + 4))(param_1);
  }
  return;
}



// Function: FUN_10021a90 at 10021a90

void __cdecl FUN_10021a90(tm *param_1,__time64_t *param_2)

{
  _localtime64_s(param_1,param_2);
  return;
}



// Function: FUN_10021ac0 at 10021ac0

__time64_t __cdecl FUN_10021ac0(tm *param_1)

{
  __time64_t _Var1;
  
  _Var1 = _mktime64(param_1);
  return _Var1;
}



// Function: FUN_10021ae0 at 10021ae0

undefined8 * __fastcall FUN_10021ae0(undefined8 *param_1)

{
  FUN_10021bc0(param_1);
  return param_1;
}



// Function: FUN_10021b00 at 10021b00

undefined8 * __thiscall FUN_10021b00(void *this,undefined8 *param_1)

{
  *(undefined8 *)this = *param_1;
  return (undefined8 *)this;
}



// Function: FUN_10021b30 at 10021b30

float10 __fastcall FUN_10021b30(double *param_1)

{
  return (float10)*param_1;
}



// Function: FUN_10021b50 at 10021b50

void __fastcall FUN_10021b50(double *param_1)

{
  FUN_10021b70(param_1);
  return;
}



// Function: FUN_10021b70 at 10021b70

undefined4 __cdecl FUN_10021b70(double *param_1)

{
  double dVar1;
  undefined4 uVar2;
  undefined1 local_48;
  undefined2 uVar3;
  
  dVar1 = *param_1;
  uVar3 = (undefined2)((uint)param_1 >> 0x10);
  uVar2 = CONCAT22(uVar3,(ushort)(-657434.0 < dVar1) << 8 | (ushort)NAN(dVar1) << 10 |
                         (ushort)(dVar1 == -657434.0) << 0xe);
  if (!NAN(dVar1) && -657434.0 < dVar1 != (dVar1 == -657434.0)) {
    dVar1 = *param_1;
    uVar2 = CONCAT22(uVar3,(ushort)(2958465.0 < dVar1) << 8 | (ushort)NAN(dVar1) << 10 |
                           (ushort)(dVar1 == 2958465.0) << 0xe);
    if (2958465.0 < dVar1 == 0) {
      local_48 = 1;
      goto LAB_10021bad;
    }
  }
  local_48 = 0;
LAB_10021bad:
  return CONCAT31((int3)((uint)uVar2 >> 8),local_48);
}



// Function: FUN_10021bc0 at 10021bc0

void __fastcall FUN_10021bc0(undefined8 *param_1)

{
  *param_1 = 0xc124103600000000;
  return;
}



// Function: FUN_10021be0 at 10021be0

undefined8 * __fastcall FUN_10021be0(undefined8 *param_1)

{
  FUN_10021d10(param_1);
  return param_1;
}



// Function: FUN_10021c00 at 10021c00

undefined8 * __thiscall FUN_10021c00(void *this,undefined8 *param_1)

{
  *(undefined8 *)this = *param_1;
  return (undefined8 *)this;
}



// Function: FUN_10021c30 at 10021c30

undefined8 * __thiscall FUN_10021c30(void *this,undefined8 param_1)

{
  *(undefined8 *)this = param_1;
  return (undefined8 *)this;
}



// Function: FUN_10021c50 at 10021c50

void * __thiscall FUN_10021c50(void *this,void *param_1)

{
                    /* WARNING: Load size is inaccurate */
  FUN_10021c80(param_1,-*this);
  return param_1;
}



// Function: FUN_10021c80 at 10021c80

undefined8 * __thiscall FUN_10021c80(void *this,undefined8 param_1)

{
  *(undefined8 *)this = param_1;
  return (undefined8 *)this;
}



// Function: FUN_10021ca0 at 10021ca0

float10 __fastcall FUN_10021ca0(double *param_1)

{
  return (float10)*param_1;
}



// Function: FUN_10021cc0 at 10021cc0

undefined4 __fastcall FUN_10021cc0(double *param_1)

{
  double dVar1;
  undefined4 uVar2;
  undefined1 local_4c;
  undefined2 uVar3;
  
  dVar1 = *param_1;
  uVar3 = (undefined2)((uint)param_1 >> 0x10);
  uVar2 = CONCAT22(uVar3,(ushort)(-3615897.0 < dVar1) << 8 | (ushort)NAN(dVar1) << 10 |
                         (ushort)(dVar1 == -3615897.0) << 0xe);
  if (!NAN(dVar1) && -3615897.0 < dVar1 != (dVar1 == -3615897.0)) {
    dVar1 = *param_1;
    uVar2 = CONCAT22(uVar3,(ushort)(3615897.0 < dVar1) << 8 | (ushort)NAN(dVar1) << 10 |
                           (ushort)(dVar1 == 3615897.0) << 0xe);
    if (3615897.0 < dVar1 == 0) {
      local_4c = 1;
      goto LAB_10021d00;
    }
  }
  local_4c = 0;
LAB_10021d00:
  return CONCAT31((int3)((uint)uVar2 >> 8),local_4c);
}



// Function: FUN_10021d10 at 10021d10

void __fastcall FUN_10021d10(undefined8 *param_1)

{
  *param_1 = 0xc14b964d00000000;
  return;
}



// Function: FUN_10021d30 at 10021d30

void * __thiscall FUN_10021d30(void *this,wchar_t *param_1)

{
  FUN_10021d60(this,param_1);
  return this;
}



// Function: FUN_10021d60 at 10021d60

void __thiscall FUN_10021d60(void *this,wchar_t *param_1)

{
  size_t sVar1;
  
  sVar1 = FUN_10021f70(param_1);
  FUN_10021e40(this,param_1,sVar1);
  return;
}



// Function: FUN_10021d90 at 10021d90

void __thiscall FUN_10021d90(void *this,int param_1)

{
  int iVar1;
  
  iVar1 = FUN_100219a0(param_1);
  *(int *)this = iVar1;
  return;
}



// Function: FUN_10021dc0 at 10021dc0

int __fastcall FUN_10021dc0(int *param_1)

{
  return *param_1 + -0x10;
}



// Function: FUN_10021de0 at 10021de0

void __thiscall FUN_10021de0(void *this,int param_1)

{
  int iVar1;
  
  if (-1 < param_1) {
    iVar1 = FUN_10021dc0((int *)this);
    if (param_1 <= *(int *)(iVar1 + 8)) goto LAB_10021e0c;
  }
  FUN_10003210(0x80070057);
LAB_10021e0c:
  iVar1 = FUN_10021dc0((int *)this);
  *(int *)(iVar1 + 4) = param_1;
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(*this + param_1 * 2) = 0;
  return;
}



// Function: FUN_10021e40 at 10021e40

void __thiscall FUN_10021e40(void *this,void *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  
  if (param_2 == 0) {
    FUN_10021f00((int *)this);
  }
  else {
    if (param_1 == (void *)0x0) {
      FUN_10003210(0x80070057);
    }
    uVar1 = FUN_10021ff0((int *)this);
    iVar2 = FUN_10022010((undefined4 *)this);
    uVar5 = (int)param_1 - iVar2 >> 1;
    pvVar3 = (void *)FUN_10021fc0(this,param_2);
    if (uVar1 < uVar5) {
      iVar2 = param_2;
      iVar4 = FUN_10021fa0((int *)this);
      FUN_10022060(pvVar3,iVar4,param_1,iVar2);
    }
    else {
      pvVar6 = (void *)((int)pvVar3 + uVar5 * 2);
      iVar2 = param_2;
      iVar4 = FUN_10021fa0((int *)this);
      FUN_10022090(pvVar3,iVar4,pvVar6,iVar2);
    }
    FUN_10022030(this,param_2);
  }
  return;
}



// Function: FUN_10021f00 at 10021f00

void __fastcall FUN_10021f00(int *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = (undefined4 *)FUN_10021dc0(param_1);
  piVar1 = (int *)*puVar3;
  if (puVar3[1] != 0) {
    bVar2 = FUN_100219f0((int)puVar3);
    if (bVar2) {
      FUN_10021de0(param_1,0);
    }
    else {
      FUN_10021a50(puVar3);
      iVar4 = (**(code **)(*piVar1 + 0xc))();
      FUN_10021d90(param_1,iVar4);
    }
  }
  return;
}



// Function: FUN_10021f70 at 10021f70

size_t __cdecl FUN_10021f70(wchar_t *param_1)

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



// Function: FUN_10021fa0 at 10021fa0

undefined4 __fastcall FUN_10021fa0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10021dc0(param_1);
  return *(undefined4 *)(iVar1 + 8);
}



// Function: FUN_10021fc0 at 10021fc0

void __thiscall FUN_10021fc0(void *this,int param_1)

{
  FUN_100220f0(this,param_1);
  return;
}



// Function: FUN_10021ff0 at 10021ff0

undefined4 __fastcall FUN_10021ff0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_10021dc0(param_1);
  return *(undefined4 *)(iVar1 + 4);
}



// Function: FUN_10022010 at 10022010

undefined4 __fastcall FUN_10022010(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10022030 at 10022030

void __thiscall FUN_10022030(void *this,int param_1)

{
  FUN_10021de0(this,param_1);
  return;
}



// Function: FUN_10022060 at 10022060

void __cdecl FUN_10022060(void *param_1,int param_2,void *param_3,int param_4)

{
  memcpy_s(param_1,param_2 << 1,param_3,param_4 << 1);
  return;
}



// Function: FUN_10022090 at 10022090

void __cdecl FUN_10022090(void *param_1,int param_2,void *param_3,int param_4)

{
  memmove_s(param_1,param_2 << 1,param_3,param_4 << 1);
  return;
}



// Function: FUN_100220c0 at 100220c0

size_t __cdecl FUN_100220c0(wchar_t *param_1,size_t param_2)

{
  size_t sVar1;
  
  if (param_1 == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = wcsnlen(param_1,param_2);
  }
  return sVar1;
}



// Function: FUN_100220f0 at 100220f0

int __thiscall FUN_100220f0(void *this,int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    FUN_10003210(0x80070057);
  }
  iVar1 = FUN_10021dc0((int *)this);
  if ((int)(1U - *(int *)(iVar1 + 0xc) | *(int *)(iVar1 + 8) - param_1) < 0) {
    FUN_10022160(this,param_1);
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10022160 at 10022160

void __thiscall FUN_10022160(void *this,int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 local_10;
  
  iVar2 = FUN_10021dc0((int *)this);
  if (param_1 < *(int *)(iVar2 + 4)) {
    param_1 = *(int *)(iVar2 + 4);
  }
  bVar1 = FUN_10021a20(iVar2);
  if (bVar1) {
    FUN_10022210(this,param_1);
  }
  else if (*(int *)(iVar2 + 8) < param_1) {
    local_10 = *(int *)(iVar2 + 8);
    if (local_10 < 0x40000001) {
      local_10 = local_10 / 2 + local_10;
    }
    else {
      local_10 = local_10 + 0x100000;
    }
    if (local_10 < param_1) {
      local_10 = param_1;
    }
    FUN_100222d0(this,local_10);
  }
  return;
}



// Function: FUN_10022210 at 10022210

void __thiscall FUN_10022210(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  int iVar7;
  int local_5c;
  
  puVar2 = (undefined4 *)FUN_10021dc0((int *)this);
  iVar1 = puVar2[1];
  puVar3 = (undefined4 *)(**(code **)(*(int *)*puVar2 + 0x10))();
  iVar4 = (**(code **)*puVar3)(param_1,2);
  if (iVar4 == 0) {
    FUN_10022350();
  }
  local_5c = iVar1;
  if (param_1 <= iVar1) {
    local_5c = param_1;
  }
  local_5c = local_5c + 1;
  iVar7 = local_5c;
  pvVar5 = (void *)FUN_100219a0((int)puVar2);
  pvVar6 = (void *)FUN_100219a0(iVar4);
  FUN_10022060(pvVar6,local_5c,pvVar5,iVar7);
  *(int *)(iVar4 + 4) = iVar1;
  FUN_10021a50(puVar2);
  FUN_10021d90(this,iVar4);
  return;
}



// Function: FUN_100222d0 at 100222d0

void __thiscall FUN_100222d0(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_10021dc0((int *)this);
  if (((int)puVar1[2] < param_1) && (0 < param_1)) {
    iVar2 = (**(code **)(*(int *)*puVar1 + 8))(puVar1,param_1,2);
    if (iVar2 == 0) {
      FUN_10022350();
    }
    FUN_10021d90(this,iVar2);
  }
  else {
    FUN_10022350();
  }
  return;
}



// Function: FUN_10022350 at 10022350

void FUN_10022350(void)

{
  FUN_10003210(0x8007000e);
  return;
}



// Function: FUN_10022370 at 10022370

void __cdecl FUN_10022370(undefined2 *param_1,undefined4 *param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined4 local_270;
  undefined2 local_26c;
  undefined1 local_268 [28];
  LSTATUS local_24c;
  undefined1 local_248 [28];
  uint local_22c;
  wchar_t local_228;
  undefined1 local_226 [518];
  int local_20 [3];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1003021e;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 == (undefined2 *)0x0) || (param_2 == (undefined4 *)0x0)) goto LAB_10022757;
  FUN_10004e20(local_20,0);
  local_8 = 0;
  local_228 = L'\0';
  memset(local_226,0,0x206);
  local_22c = 0x208;
  FUN_1000a150(local_248,L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\CS\\Locale\\");
  local_8._0_1_ = 1;
  local_24c = FUN_10005260(local_20,(HKEY)0x80000002,
                           L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale",
                           0x2001f);
  if (local_24c == 0) {
    local_24c = FUN_10022780(local_20,L"LanguageExt",(LPBYTE)&local_228,&local_22c);
    if (local_24c == 0) {
      FUN_1000a150(local_268,&local_228);
      local_8 = CONCAT31(local_8._1_3_,2);
      iVar1 = FUN_10015960((int)local_268);
      if (iVar1 == 0) {
        FUN_100158e0(local_268,L"EN");
      }
      iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_10045764);
      if (((((iVar1 == 0) ||
            (iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_10045864), iVar1 == 0)) ||
           (iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100456a0), iVar1 == 0)) ||
          ((((iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_10045748), iVar1 == 0 ||
             (iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_10045848), iVar1 == 0)) ||
            ((iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_10045784), iVar1 == 0 ||
             ((iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100456d8), iVar1 == 0 ||
              (iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_10045710), iVar1 == 0)))))) ||
           (iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100457d8), iVar1 == 0)))) ||
         (((iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_10045880), iVar1 == 0 ||
           (iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100456f4), iVar1 == 0)) ||
          (iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_1004572c), iVar1 == 0)))) {
LAB_10022607:
        local_26c = 0;
        local_270 = 0x4e4;
      }
      else {
        pwVar2 = (wchar_t *)FUN_10007570((undefined4 *)&DAT_10045780);
        iVar1 = FUN_100243b0(local_268,pwVar2);
        if (iVar1 == 0) goto LAB_10022607;
        pwVar2 = (wchar_t *)FUN_10007570((undefined4 *)&DAT_1004589c);
        iVar1 = FUN_100243b0(local_268,pwVar2);
        if (iVar1 == 0) goto LAB_10022607;
        pwVar2 = (wchar_t *)FUN_10007570((undefined4 *)&DAT_100458a0);
        iVar1 = FUN_100243b0(local_268,pwVar2);
        if (iVar1 == 0) goto LAB_10022607;
        iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100457bc);
        if (iVar1 == 0) {
          local_26c = 0xa2;
          local_270 = 0x4e6;
        }
        else {
          iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_1004582c);
          if (iVar1 == 0) {
            local_26c = 0x86;
            local_270 = 0x3a8;
          }
          else {
            iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100457f4);
            if (iVar1 == 0) {
              local_26c = 0x80;
              local_270 = 0x3a4;
            }
            else {
              iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100456bc);
              if (iVar1 == 0) {
                local_26c = 0x81;
                local_270 = 0x3b5;
              }
              else {
                iVar1 = FUN_100113b0(local_268,(undefined4 *)&DAT_100457a0);
                if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
                }
                local_26c = 0xcc;
                local_270 = 0x4e3;
              }
            }
          }
        }
      }
      *param_1 = local_26c;
      *param_2 = local_270;
      local_8._0_1_ = 1;
      FUN_1000aca0(local_268);
    }
    FUN_10005090(local_20);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(local_248);
  local_8 = 0xffffffff;
  FUN_10004e60(local_20);
LAB_10022757:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10022780 at 10022780

LSTATUS __thiscall FUN_10022780(void *this,LPCWSTR param_1,LPBYTE param_2,uint *param_3)

{
  LSTATUS LVar1;
  uint local_14;
  DWORD local_10 [2];
  void *local_8;
  
  local_14 = *param_3 << 1;
  *param_3 = 0;
                    /* WARNING: Load size is inaccurate */
  local_8 = this;
  LVar1 = RegQueryValueExW(*this,param_1,(LPDWORD)0x0,local_10,param_2,&local_14);
  if (LVar1 == 0) {
    if ((local_10[0] == 1) || (local_10[0] == 2)) {
      if (param_2 != (LPBYTE)0x0) {
        if (local_14 == 0) {
          param_2[0] = '\0';
          param_2[1] = '\0';
        }
        else if ((local_14 % 2 != 0) || (*(short *)(param_2 + ((local_14 & 0xfffffffe) - 2)) != 0))
        {
          return 0xd;
        }
      }
      *param_3 = local_14 >> 1;
      LVar1 = 0;
    }
    else {
      LVar1 = 0xd;
    }
  }
  return LVar1;
}



// Function: FUN_10022840 at 10022840

void * __cdecl FUN_10022840(void *param_1,ulong param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<char,struct_std::char_traits<char>_> local_a8 [152];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1003027a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100243f0(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_a8,param_2);
  FUN_10024540(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_100228e0((int)local_b8);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100228e0 at 100228e0

void __fastcall FUN_100228e0(int param_1)

{
  FUN_100244c0(param_1 + 0x60);
  std::basic_ios<char,struct_std::char_traits<char>_>::
  ~basic_ios<char,struct_std::char_traits<char>_>
            ((basic_ios<char,struct_std::char_traits<char>_> *)(param_1 + 0x60));
  return;
}



// Function: FUN_10022910 at 10022910

void * __cdecl FUN_10022910(void *param_1,ulong param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_a8 [152];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100302ca;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10025010(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(local_a8,param_2);
  FUN_10025160(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_100229b0((int)local_b8);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100229b0 at 100229b0

void __fastcall FUN_100229b0(int param_1)

{
  FUN_100250e0(param_1 + 0x60);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 0x60));
  return;
}



// Function: FUN_100229e0 at 100229e0

void * __cdecl FUN_100229e0(void *param_1,long param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<char,struct_std::char_traits<char>_> local_a8 [152];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1003031a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100243f0(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_a8,param_2);
  FUN_10024540(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_100228e0((int)local_b8);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022a80 at 10022a80

void * __cdecl FUN_10022a80(void *param_1,undefined4 param_2)

{
  undefined1 local_20 [8];
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030361;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10022b30(local_20,param_2,3);
  local_8 = 1;
  FUN_10024120(8,(int)local_20,0,0x409);
  FUN_1000ac40(param_1,local_18);
  local_8 = local_8 & 0xffffff00;
  FUN_10022b10(local_20);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022b10 at 10022b10

void __fastcall FUN_10022b10(undefined4 param_1)

{
  FUN_10022b90(param_1);
  return;
}



// Function: FUN_10022b30 at 10022b30

short * __thiscall FUN_10022b30(void *this,undefined4 param_1,short param_2)

{
  if ((param_2 == 3) || (param_2 == 10)) {
    *(short *)this = param_2;
    *(undefined4 *)((int)this + 8) = param_1;
  }
  else {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x80070057;
    FUN_10003210(0x80070057);
  }
  return (short *)this;
}



// Function: FUN_10022b90 at 10022b90

void __fastcall FUN_10022b90(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10022bb0 at 10022bb0

void * __cdecl FUN_10022bb0(void *param_1,long param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_a8 [152];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100303aa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10025010(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(local_a8,param_2);
  FUN_10025160(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_100229b0((int)local_b8);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022c50 at 10022c50

void * __cdecl FUN_10022c50(void *param_1,float param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<char,struct_std::char_traits<char>_> local_a8 [152];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100303fa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100243f0(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(local_a8,param_2);
  FUN_10024540(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_100228e0((int)local_b8);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022cf0 at 10022cf0

void * __cdecl FUN_10022cf0(void *param_1,float param_2)

{
  undefined1 local_b8 [16];
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> local_a8 [152];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1003044a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10025010(local_b8,3,1);
  local_8 = 1;
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<(local_a8,param_2);
  FUN_10025160(local_b8,param_1);
  local_8 = local_8 & 0xffffff00;
  FUN_100229b0((int)local_b8);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022d90 at 10022d90

void * __cdecl FUN_10022d90(void *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  LPCWSTR pWVar2;
  undefined4 local_58;
  uint local_54;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030491;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_54 = 0;
  puVar1 = (undefined4 *)FUN_100232d0(&local_58,param_2);
  local_8 = 1;
  pWVar2 = (LPCWSTR)FUN_10007570(puVar1);
  FUN_10022eb0(param_1,pWVar2);
  local_54 = local_54 | 1;
  local_8 = local_8 & 0xffffff00;
  FUN_10007720(&local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022e20 at 10022e20

void * __cdecl FUN_10022e20(void *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_58;
  uint local_54;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100304d1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_54 = 0;
  puVar1 = (undefined4 *)FUN_100230e0(&local_58,param_2);
  local_8 = 1;
  iVar2 = FUN_10007570(puVar1);
  FUN_10023020(param_1,iVar2);
  local_54 = local_54 | 1;
  local_8 = local_8 & 0xffffff00;
  FUN_10007720(&local_58);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10022eb0 at 10022eb0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl FUN_10022eb0(void *param_1,LPCWSTR param_2)

{
  uint uVar1;
  UINT UVar2;
  int iVar3;
  uint local_84;
  LPSTR local_70;
  char *local_6c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030509;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_84 = uVar1;
  if (param_2 == (LPCWSTR)0x0) {
    FUN_1001d7b0(param_1);
  }
  else {
    UVar2 = FUN_10002a10();
    if (param_2 == (LPCWSTR)0x0) {
      local_6c = (char *)0x0;
    }
    else {
      iVar3 = lstrlenW(param_2);
      if (iVar3 + 1 < 0x40000000) {
        local_70 = FUN_10022fc0((LPSTR)&local_84,param_2,(iVar3 + 1) * 2,UVar2);
      }
      else {
        local_70 = (LPSTR)0x0;
      }
      local_6c = local_70;
    }
    FUN_100242f0(param_1,local_6c);
  }
  local_8 = 0;
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10022fc0 at 10022fc0

LPSTR FUN_10022fc0(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

{
  int iVar1;
  
  if ((param_1 == (LPSTR)0x0) || (param_2 == (LPCWSTR)0x0)) {
    param_1 = (LPSTR)0x0;
  }
  else {
    *param_1 = '\0';
    iVar1 = WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      param_1 = (LPSTR)0x0;
    }
  }
  return param_1;
}



// Function: FUN_10023020 at 10023020

void * __cdecl FUN_10023020(void *param_1,int param_2)

{
  wchar_t *pwVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030549;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 == 0) {
    FUN_10015780(param_1);
  }
  else {
    FUN_10002a10();
    pwVar1 = (wchar_t *)FUN_100230c0(param_2);
    FUN_1000a150(param_1,pwVar1);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100230c0 at 100230c0

undefined4 __cdecl FUN_100230c0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100230e0 at 100230e0

void * __cdecl FUN_100230e0(void *param_1,undefined4 *param_2)

{
  LPCSTR pCVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030589;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pCVar1 = (LPCSTR)FUN_1001d880(param_2);
  FUN_10023150(param_1,pCVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10023150 at 10023150

int * __thiscall FUN_10023150(void *this,LPCSTR param_1)

{
  bool bVar1;
  LPWSTR pWVar2;
  
  if (param_1 == (LPCSTR)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    pWVar2 = FUN_100231b0(param_1,-1);
    *(LPWSTR *)this = pWVar2;
    bVar1 = FUN_10008590((int *)this);
    if (bVar1) {
      FUN_10003210(0x8007000e);
    }
  }
  return (int *)this;
}



// Function: FUN_100231b0 at 100231b0

LPWSTR __cdecl FUN_100231b0(LPCSTR param_1,int param_2)

{
  uint uVar1;
  LPWSTR lpWideCharStr;
  int cchWideChar;
  int iVar2;
  int local_30;
  int local_24 [3];
  UINT local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100305b8;
  local_10 = ExceptionList;
  uVar1 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
    lpWideCharStr = (LPWSTR)0x0;
  }
  else {
    local_18 = FUN_10002a10();
    FUN_10008090(local_24);
    local_8 = 0;
    cchWideChar = MultiByteToWideChar(local_18,0,param_1,param_2,(LPWSTR)0x0,0);
    local_30 = cchWideChar;
    if (param_2 == -1) {
      local_30 = cchWideChar + -1;
    }
    lpWideCharStr = (LPWSTR)Ordinal_4(0,local_30,uVar1);
    if ((lpWideCharStr != (LPWSTR)0x0) &&
       (iVar2 = MultiByteToWideChar(local_18,0,param_1,param_2,lpWideCharStr,cchWideChar),
       iVar2 != cchWideChar)) {
      Ordinal_6(lpWideCharStr);
      local_8 = 0xffffffff;
      FUN_100080b0(local_24);
      ExceptionList = local_10;
      return (LPWSTR)0x0;
    }
    local_8 = 0xffffffff;
    FUN_100080b0(local_24);
  }
  ExceptionList = local_10;
  return lpWideCharStr;
}



// Function: FUN_100232d0 at 100232d0

void * __cdecl FUN_100232d0(void *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100305f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10015940(param_2);
  FUN_1000ac40(param_1,iVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10023340 at 10023340

int __cdecl FUN_10023340(char param_1)

{
  return -(uint)(param_1 != '\0');
}



// Function: FUN_10023360 at 10023360

bool __cdecl FUN_10023360(char param_1)

{
  return param_1 != '\0';
}



// Function: FUN_10023380 at 10023380

undefined4 __cdecl FUN_10023380(short param_1)

{
  return CONCAT31((int3)(char)((ushort)param_1 >> 8),param_1 == -1);
}



// Function: FUN_100233a0 at 100233a0

bool __cdecl FUN_100233a0(int param_1)

{
  return param_1 != 0;
}



// Function: FUN_100233c0 at 100233c0

undefined4 __cdecl FUN_100233c0(int param_1)

{
  undefined1 local_20 [8];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030628;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10023440(local_20,param_1);
  local_8 = 0;
  FUN_10024120(3,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  FUN_10022b10(local_20);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10023440 at 10023440

undefined2 * __thiscall FUN_10023440(void *this,int param_1)

{
  *(undefined2 *)this = 0;
  FUN_10023470(this,param_1);
  return (undefined2 *)this;
}



// Function: FUN_10023470 at 10023470

undefined2 * __thiscall FUN_10023470(void *this,int param_1)

{
  undefined4 uVar1;
  
  FUN_100234e0(this);
  *(undefined2 *)this = 8;
  uVar1 = Ordinal_2(param_1);
  *(undefined4 *)((int)this + 8) = uVar1;
  if ((*(int *)((int)this + 8) == 0) && (param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    FUN_10003210(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_100234e0 at 100234e0

void __fastcall FUN_100234e0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_10022b90(param_1);
  if (iVar1 < 0) {
    FUN_10003210(iVar1);
  }
  return;
}



// Function: FUN_10023510 at 10023510

float10 __cdecl FUN_10023510(int param_1)

{
  undefined1 local_20 [8];
  float local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030658;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10023440(local_20,param_1);
  local_8 = 0;
  FUN_10024120(4,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  FUN_10022b10(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_10023590 at 10023590

float10 __cdecl FUN_10023590(int param_1)

{
  undefined1 local_20 [8];
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030688;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10023440(local_20,param_1);
  local_8 = 0;
  FUN_10024120(5,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  FUN_10022b10(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_10023610 at 10023610

void __cdecl FUN_10023610(undefined4 *param_1)

{
  char *_Str;
  
  _Str = (char *)FUN_1001d880(param_1);
  atol(_Str);
  return;
}



// Function: FUN_10023640 at 10023640

float10 __cdecl FUN_10023640(undefined4 *param_1)

{
  LPCSTR pCVar1;
  undefined1 local_20 [8];
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100306b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pCVar1 = (LPCSTR)FUN_1001d880(param_1);
  FUN_100236c0(local_20,pCVar1);
  local_8 = 0;
  FUN_10024120(5,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  FUN_10022b10(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_100236c0 at 100236c0

undefined2 * __thiscall FUN_100236c0(void *this,LPCSTR param_1)

{
  *(undefined2 *)this = 0;
  FUN_100236f0(param_1);
  return (undefined2 *)this;
}



// Function: FUN_100236f0 at 100236f0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_100236f0(LPCSTR param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint local_90;
  LPWSTR local_80;
  LPWSTR local_78;
  LPWSTR local_74;
  int local_2c;
  LPCSTR local_28;
  UINT local_20;
  uint local_1c;
  undefined2 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100306e8;
  local_10 = ExceptionList;
  local_90 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_90;
  local_20 = FUN_10002a10();
  FUN_10008090(&local_2c);
  local_8 = 0;
  FUN_100234e0(local_18);
  *local_18 = 8;
  local_28 = param_1;
  if (param_1 == (LPCSTR)0x0) {
    local_74 = (LPWSTR)0x0;
    goto LAB_100237ed;
  }
  iVar2 = lstrlenA(param_1);
  local_1c = iVar2 + 1;
  uVar3 = FUN_10023870(&local_1c,local_1c,2);
  if ((int)uVar3 < 0) {
    local_78 = (LPWSTR)0x0;
  }
  else {
    if ((int)local_1c < 0x401) {
      cVar1 = FUN_100238e0(local_1c);
      if (cVar1 == '\0') goto LAB_100237be;
      local_80 = (LPWSTR)&local_90;
    }
    else {
LAB_100237be:
      local_80 = (LPWSTR)FUN_10024290(&local_2c,local_1c);
    }
    local_78 = FUN_100239c0(local_80,local_28,local_1c >> 1,local_20);
  }
  local_74 = local_78;
LAB_100237ed:
  uVar4 = Ordinal_2(local_74);
  *(undefined4 *)(local_18 + 4) = uVar4;
  if ((*(int *)(local_18 + 4) == 0) && (param_1 != (LPCSTR)0x0)) {
    *local_18 = 10;
    *(undefined4 *)(local_18 + 4) = 0x8007000e;
    FUN_10003210(0x8007000e);
  }
  local_8 = 0xffffffff;
  FUN_100080b0(&local_2c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10023870 at 10023870

uint __cdecl FUN_10023870(uint *param_1,uint param_2,uint param_3)

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
    uVar1 = FUN_100024c0(0x216);
  }
  return uVar1;
}



// Function: FUN_100238e0 at 100238e0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_100238e0(int param_1)

{
  uint uVar1;
  uint local_88;
  int local_28;
  undefined1 local_21;
  uint local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  undefined4 local_8;
  
  puStack_10 = &LAB_1002c3ea;
  local_14 = ExceptionList;
  local_c = DAT_10043b78 ^ 0x1003fcb8;
  local_88 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_1c = (undefined1 *)&local_88;
  ExceptionList = &local_14;
  local_21 = 1;
  local_8 = 0;
  local_28 = 0;
  local_20 = local_88;
  uVar1 = FUN_100273c0(&local_28,param_1,0x2000);
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



// Function: FUN_100239c0 at 100239c0

LPWSTR FUN_100239c0(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

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



// Function: FUN_10023a20 at 10023a20

float10 __cdecl FUN_10023a20(undefined4 *param_1)

{
  int iVar1;
  undefined1 local_20 [8];
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030718;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10015940(param_1);
  FUN_10023440(local_20,iVar1);
  local_8 = 0;
  FUN_10024120(5,(int)local_20,0,0x409);
  local_8 = 0xffffffff;
  FUN_10022b10(local_20);
  ExceptionList = local_10;
  return (float10)local_18;
}



// Function: FUN_10023aa0 at 10023aa0

float10 __cdecl FUN_10023aa0(undefined4 *param_1)

{
  char *_String;
  double dVar1;
  
  FUN_10002a10();
  _String = (char *)FUN_1001d880(param_1);
  dVar1 = atof(_String);
  return (float10)(float)dVar1;
}



// Function: FUN_10023ad0 at 10023ad0

void __cdecl FUN_10023ad0(undefined4 *param_1)

{
  wchar_t *_Str;
  
  _Str = (wchar_t *)FUN_10015940(param_1);
  _wtol(_Str);
  return;
}



// Function: FUN_10023b00 at 10023b00

void * __cdecl FUN_10023b00(void *param_1,undefined4 *param_2)

{
  LPCSTR pCVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030759;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pCVar1 = (LPCSTR)FUN_1001d880(param_2);
  FUN_100236c0(param_1,pCVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10023b70 at 10023b70

void * __cdecl FUN_10023b70(void *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030799;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10015940(param_2);
  FUN_10023440(param_1,iVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10023be0 at 10023be0

undefined8 __cdecl FUN_10023be0(SYSTEMTIME *param_1)

{
  BOOL BVar1;
  undefined4 local_58 [19];
  _FILETIME local_c;
  
  BVar1 = SystemTimeToFileTime(param_1,&local_c);
  if (BVar1 == 0) {
    local_58[0] = 0x80004005;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_58,(ThrowInfo *)&DAT_1003fd58);
  }
  return CONCAT44(local_c.dwHighDateTime,local_c.dwLowDateTime);
}



// Function: FUN_10023c30 at 10023c30

void __cdecl FUN_10023c30(undefined4 *param_1,DWORD param_2,DWORD param_3)

{
  BOOL BVar1;
  undefined4 local_64 [17];
  _SYSTEMTIME local_20;
  FILETIME local_10;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  local_10.dwHighDateTime = param_3;
  local_10.dwLowDateTime = param_2;
  BVar1 = FileTimeToSystemTime(&local_10,&local_20);
  if (BVar1 == 0) {
    local_64[0] = 0x80004005;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_64,(ThrowInfo *)&DAT_1003fd58);
  }
  *param_1 = local_20._0_4_;
  param_1[1] = local_20._4_4_;
  param_1[2] = local_20._8_4_;
  param_1[3] = local_20._12_4_;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10023cb0 at 10023cb0

void __cdecl FUN_10023cb0(void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_8;
  
  uVar3 = 0;
  pwVar1 = (wchar_t *)FUN_10015940(param_2);
  for (local_8 = FUN_1001ebf0(param_1,pwVar1,uVar3); local_8 != 0xffffffff;
      local_8 = FUN_1001ebf0(param_1,pwVar1,local_8)) {
    pwVar1 = (wchar_t *)FUN_10015940(param_3);
    uVar3 = FUN_10015960((int)param_2);
    FUN_10024370(param_1,local_8,uVar3,pwVar1);
    iVar2 = FUN_10015960((int)param_3);
    local_8 = iVar2 + local_8;
    pwVar1 = (wchar_t *)FUN_10015940(param_2);
  }
  return;
}



// Function: FUN_10023d30 at 10023d30

void __cdecl FUN_10023d30(void *param_1,undefined4 *param_2,int param_3)

{
  undefined1 local_84 [28];
  undefined4 local_68 [7];
  undefined4 local_4c [7];
  undefined4 local_30 [7];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100307ff;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000a150(local_30,L"\r\n");
  local_8 = 1;
  FUN_1000a150(local_4c,L"\n");
  local_8._0_1_ = 2;
  FUN_1000a150(local_68,L"\r");
  local_8._0_1_ = 3;
  FUN_100156f0(local_84,param_2);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_10023cb0(local_84,local_30,local_4c);
  FUN_10023cb0(local_84,local_68,local_4c);
  FUN_10023cb0(local_84,local_4c,local_30);
  if (param_3 == 1) {
    FUN_10023cb0(local_84,local_30,local_4c);
  }
  else if (param_3 == 2) {
    FUN_10023cb0(local_84,local_30,local_68);
  }
  FUN_100157f0(param_1,(int)local_84);
  local_8._0_1_ = 3;
  FUN_1000aca0(local_84);
  local_8._0_1_ = 2;
  FUN_1000aca0(local_68);
  local_8._0_1_ = 1;
  FUN_1000aca0(local_4c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000aca0(local_30);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10023ea0 at 10023ea0

void __cdecl FUN_10023ea0(void *param_1,undefined4 *param_2)

{
  LPCWSTR pWVar1;
  int *piVar2;
  UINT UVar3;
  undefined4 local_f4 [49];
  char *local_30;
  UINT local_2c;
  undefined2 local_28 [6];
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1003085a;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = FUN_10002a10();
  local_28[0] = 0;
  local_2c = 0x4e4;
  FUN_10022370(local_28,&local_2c);
  UVar3 = local_2c;
  pWVar1 = (LPCWSTR)FUN_10015940(param_2);
  piVar2 = FUN_10025d50(local_f4,pWVar1,UVar3);
  local_8 = 1;
  local_30 = (char *)FUN_10025dc0(piVar2);
  local_8 = local_8 & 0xffffff00;
  FUN_10025d90(local_f4);
  FUN_100242f0(param_1,local_30);
  local_8 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10023f90 at 10023f90

void __cdecl FUN_10023f90(void *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined1 local_70 [92];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100308b1;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10023020(local_70,param_2);
  local_8 = 1;
  FUN_10023ea0(param_1,puVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_1000aca0(local_70);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10024030 at 10024030

void __cdecl FUN_10024030(void *param_1,undefined4 *param_2)

{
  LPCSTR pCVar1;
  int *piVar2;
  UINT UVar3;
  undefined4 local_174 [81];
  wchar_t *local_30;
  UINT local_2c;
  undefined2 local_28 [6];
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1003090a;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = FUN_10002a10();
  local_28[0] = 0;
  local_2c = 0x4e4;
  FUN_10022370(local_28,&local_2c);
  UVar3 = local_2c;
  pCVar1 = (LPCSTR)FUN_1001d880(param_2);
  piVar2 = FUN_10025de0(local_174,pCVar1,UVar3);
  local_8 = 1;
  local_30 = (wchar_t *)FUN_10025e50(piVar2);
  local_8 = local_8 & 0xffffff00;
  FUN_10025e20(local_174);
  FUN_1000a150(param_1,local_30);
  local_8 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10024120 at 10024120

void __cdecl FUN_10024120(undefined2 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 local_8;
  
  local_8 = param_3;
  if (param_3 == 0) {
    local_8 = param_2;
  }
  Ordinal_147(local_8,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_10024160 at 10024160

long FUN_10024160(void)

{
  long lVar1;
  wchar_t *local_24;
  wchar_t *local_20;
  long local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030948;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = 0xfffffc19;
  local_18 = 0x10;
  local_1c = 0xfffffc19;
  local_20 = (wchar_t *)FUN_10007570((undefined4 *)&stack0x00000004);
  lVar1 = wcstol(local_20,&local_24,0x10);
  local_8 = 0xffffffff;
  local_1c = lVar1;
  FUN_10007720((undefined4 *)&stack0x00000004);
  ExceptionList = local_10;
  return lVar1;
}



// Function: FUN_100241f0 at 100241f0

void __cdecl FUN_100241f0(void *param_1,undefined4 param_2)

{
  wchar_t local_1a4 [200];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1003098f;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  swprintf_s(local_1a4,400,L"%X",param_2,local_14);
  FUN_1000a150(param_1,local_1a4);
  local_8 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10024290 at 10024290

int __thiscall FUN_10024290(void *this,int param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  int iVar3;
  
  sVar1 = FUN_10027400(param_1,8);
  puVar2 = (undefined4 *)FUN_10009af0(sVar1);
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    *puVar2 = *this;
    *(undefined4 **)this = puVar2;
    iVar3 = FUN_10026de0((int)puVar2);
  }
  return iVar3;
}



// Function: FUN_100242f0 at 100242f0

void * __thiscall FUN_100242f0(void *this,char *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100309c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001dbf0(&stack0xffffff94);
  FUN_1001dba0((int)this);
  local_8 = 0;
  FUN_1001dac0(this,'\0',0);
  FUN_10025f70(this,param_1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10024370 at 10024370

void __thiscall FUN_10024370(void *this,uint param_1,uint param_2,wchar_t *param_3)

{
  uint uVar1;
  
  uVar1 = FUN_1000a200(param_3);
  FUN_10025fa0(this,param_1,param_2,(undefined4 *)param_3,uVar1);
  return;
}



// Function: FUN_100243b0 at 100243b0

void __thiscall FUN_100243b0(void *this,wchar_t *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1000a200(param_1);
  FUN_10012640(this,0,*(uint *)((int)this + 0x10),(ushort *)param_1,uVar1);
  return;
}



// Function: FUN_100243f0 at 100243f0

basic_iostream<char,struct_std::char_traits<char>_> * __thiscall
FUN_100243f0(void *this,uint param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030a24;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined **)this = &DAT_100390ac;
    *(undefined ***)((int)this + 0x10) = &PTR_100390a4;
    std::basic_ios<char,struct_std::char_traits<char>_>::
    basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)((int)this + 0x60));
    local_8 = 0;
  }
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)this,
             (basic_streambuf<char,struct_std::char_traits<char>_> *)((int)this + 0x18));
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  FUN_10026460((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return (basic_iostream<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_100244c0 at 100244c0

void __fastcall FUN_100244c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030a57;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(param_1 + -0x60 + *(int *)(*(int *)(param_1 + -0x60) + 4)) =
       std::basic_stringstream<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
       vftable;
  local_8 = 0;
  FUN_100245b0((basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + -0x48));
  local_8 = 0xffffffff;
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)(param_1 + -0x48));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024540 at 10024540

void * __thiscall FUN_10024540(void *this,void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030a99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100264f0((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100245b0 at 100245b0

void __fastcall FUN_100245b0(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030ac9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  local_8 = 0;
  FUN_10026810(param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10024620 at 10024620

uint __thiscall FUN_10024620(void *this,uint param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  uint local_64;
  int local_60 [17];
  char *local_1c;
  char *local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_8 = (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
  if ((((*(uint *)((int)this + 0x40) & 8) != 0) &&
      (pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                          ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
      pcVar3 != (char *)0x0)) &&
     (pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_8),
     pcVar3 < *(char **)(local_8 + 0x3c))) {
    pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(local_8);
    pcVar3 = *(char **)(local_8 + 0x3c);
    pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase(local_8);
    std::basic_streambuf<char,struct_std::char_traits<char>_>::setp(local_8,pcVar5,pcVar3,pcVar4);
  }
  local_60[0] = FUN_1001d5f0();
  bVar1 = FUN_1001d590(local_60,(int *)&param_1);
  if (bVar1) {
    param_1 = FUN_1001d5b0(&param_1);
  }
  else {
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_8);
    if (pcVar3 != (char *)0x0) {
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_8);
      pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(local_8);
      if (pcVar3 < pcVar4) {
        cVar2 = FUN_1001d550((undefined1 *)&param_1);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc(local_8);
        *pcVar3 = cVar2;
        return param_1;
      }
    }
    if ((*(uint *)(local_8 + 0x40) & 2) == 0) {
      pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_8);
      if (pcVar3 == (char *)0x0) {
        local_64 = 0;
      }
      else {
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(local_8);
        pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(local_8);
        local_64 = (int)pcVar3 - (int)pcVar4;
      }
      local_10 = local_64;
      local_c = local_64;
      if (local_64 >> 1 < 0x20) {
        local_64 = 0x20;
      }
      else {
        local_64 = local_64 >> 1;
      }
      for (local_14 = local_64; (local_14 != 0 && (0x7fffffff - local_14 < local_10));
          local_14 = local_14 >> 1) {
      }
      if (local_14 == 0) {
        param_1 = FUN_1001d5f0();
      }
      else {
        local_10 = local_10 + local_14;
        local_18 = (char *)FUN_1001e450(local_10);
        local_1c = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(local_8);
        if (local_c != 0) {
          FUN_1001db40(local_18,local_1c,local_c);
        }
        if (local_c == 0) {
          *(char **)(local_8 + 0x3c) = local_18;
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    (local_8,local_18,local_18 + local_10);
          if ((*(uint *)(local_8 + 0x40) & 4) == 0) {
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      (local_8,local_18,local_18,local_18 + 1);
          }
          else {
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      (local_8,local_18,(char *)0x0,local_18);
          }
        }
        else {
          *(char **)(local_8 + 0x3c) = local_18 + (*(int *)(local_8 + 0x3c) - (int)local_1c);
          pcVar3 = local_18 + local_10;
          pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_8);
          pcVar4 = local_18 + ((int)pcVar4 - (int)local_1c);
          pcVar5 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase(local_8);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    (local_8,local_18 + ((int)pcVar5 - (int)local_1c),pcVar4,pcVar3);
          if ((*(uint *)(local_8 + 0x40) & 4) == 0) {
            pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_8);
            pcVar3 = pcVar3 + 1;
            pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      (local_8,local_18,local_18 + ((int)pcVar4 - (int)local_1c),pcVar3);
          }
          else {
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                      (local_8,local_18,(char *)0x0,local_18);
          }
        }
        if ((*(uint *)(local_8 + 0x40) & 1) != 0) {
          FUN_1001e140(local_1c);
        }
        *(uint *)(local_8 + 0x40) = *(uint *)(local_8 + 0x40) | 1;
        cVar2 = FUN_1001d550((undefined1 *)&param_1);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::_Pninc(local_8);
        *pcVar3 = cVar2;
      }
    }
    else {
      param_1 = FUN_1001d5f0();
    }
  }
  return param_1;
}



// Function: FUN_10024920 at 10024920

void __fastcall FUN_10024920(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int local_54;
  char local_4d;
  int local_4c [17];
  basic_streambuf<char,struct_std::char_traits<char>_> *local_8;
  
  local_8 = param_1;
  pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar3 != (char *)0x0) {
    pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
    pcVar4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(local_8);
    if (pcVar4 < pcVar3) {
      local_54 = FUN_1001d5f0();
      bVar1 = FUN_1001d590(&local_54,(int *)&stack0x00000004);
      if (!bVar1) {
        local_4d = FUN_1001d550(&stack0x00000004);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
        uVar5 = FUN_10024a10(&local_4d,pcVar3 + -1);
        if (((uVar5 & 0xff) == 0) && ((*(uint *)(local_8 + 0x40) & 2) != 0)) goto LAB_100249aa;
      }
      std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump(local_8,-1);
      local_4c[0] = FUN_1001d5f0();
      bVar1 = FUN_1001d590(local_4c,(int *)&stack0x00000004);
      if (!bVar1) {
        cVar2 = FUN_1001d550(&stack0x00000004);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_8);
        *pcVar3 = cVar2;
      }
      FUN_1001d5b0((uint *)&stack0x00000004);
      return;
    }
  }
LAB_100249aa:
  FUN_1001d5f0();
  return;
}



// Function: FUN_10024a10 at 10024a10

undefined4 __cdecl FUN_10024a10(char *param_1,char *param_2)

{
  return CONCAT31(*param_2 >> 7,*param_1 == *param_2);
}



// Function: FUN_10024a40 at 10024a40

void __fastcall FUN_10024a40(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  if (pcVar1 == (char *)0x0) {
    FUN_1001d5f0();
    return;
  }
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
  if (pcVar2 <= pcVar1) {
    if (((*(uint *)(param_1 + 0x40) & 4) == 0) &&
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1),
       pcVar1 != (char *)0x0)) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
      if ((pcVar2 < pcVar1) ||
         (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1),
         pcVar1 < *(char **)(param_1 + 0x3c))) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
        if (*(char **)(param_1 + 0x3c) < pcVar1) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
          *(char **)(param_1 + 0x3c) = pcVar1;
        }
        pcVar1 = *(char **)(param_1 + 0x3c);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
        pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
        std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                  (param_1,pcVar3,pcVar2,pcVar1);
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
        FUN_1001d570(pcVar1);
        return;
      }
    }
    FUN_1001d5f0();
    return;
  }
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(param_1);
  FUN_1001d570(pcVar1);
  return;
}



// Function: FUN_10024b50 at 10024b50

void * __thiscall
FUN_10024b50(void *this,void *param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((pcVar1 != (char *)0x0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     *(char **)((int)this + 0x3c) < pcVar1)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    *(char **)((int)this + 0x3c) = pcVar1;
  }
  if (((param_5 & 1) == 0) ||
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     pcVar1 == (char *)0x0)) {
    if (((param_5 & 2) == 0) ||
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       pcVar1 == (char *)0x0)) {
      if (param_2 != 0 || param_3 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(int *)(_BADOFF_exref + 4);
      }
    }
    else {
      if (param_4 == 2) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        bVar6 = CARRY4(uVar4,param_2);
        param_2 = uVar4 + param_2;
        param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
      }
      else if (param_4 == 1) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = (int)pcVar1 - (int)pcVar2;
        bVar6 = CARRY4(uVar4,param_2);
        param_2 = uVar4 + param_2;
        param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(int *)(_BADOFF_exref + 4);
      }
      if (-1 < param_3) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        iVar5 = (int)uVar4 >> 0x1f;
        if ((param_3 <= iVar5) && ((param_3 < iVar5 || (param_2 <= uVar4)))) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::pbump
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                     (int)(pcVar1 + (param_2 - (int)pcVar2)));
          goto LAB_10024dee;
        }
      }
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(int *)(_BADOFF_exref + 4);
    }
  }
  else {
    if (param_4 == 2) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
      bVar6 = CARRY4(uVar4,param_2);
      param_2 = uVar4 + param_2;
      param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
    }
    else if ((param_4 == 1) && ((param_5 & 2) == 0)) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = (int)pcVar1 - (int)pcVar2;
      bVar6 = CARRY4(uVar4,param_2);
      param_2 = uVar4 + param_2;
      param_3 = ((int)uVar4 >> 0x1f) + param_3 + (uint)bVar6;
    }
    else if (param_4 != 0) {
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(int *)(_BADOFF_exref + 4);
    }
    if (-1 < param_3) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
      iVar5 = (int)uVar4 >> 0x1f;
      if ((param_3 <= iVar5) && ((param_3 < iVar5 || (param_2 <= uVar4)))) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                  ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                   (int)(pcVar1 + (param_2 - (int)pcVar2)));
        if (((param_5 & 2) != 0) &&
           (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
           pcVar1 != (char *)0x0)) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar2,
                     pcVar1);
        }
        goto LAB_10024dee;
      }
    }
    param_2 = *(uint *)_BADOFF_exref;
    param_3 = *(int *)(_BADOFF_exref + 4);
  }
LAB_10024dee:
  FUN_1001dc70(param_1,param_2,param_3);
  return param_1;
}



// Function: FUN_10024e10 at 10024e10

void * __thiscall FUN_10024e10(void *this,void *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  uint in_stack_00000020;
  undefined8 local_10;
  
  lVar6 = FUN_1001dd40((uint *)&stack0x00000008);
  pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                     ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((pcVar1 != (char *)0x0) &&
     (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
     *(char **)((int)this + 0x3c) < pcVar1)) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    *(char **)((int)this + 0x3c) = pcVar1;
  }
  local_10._0_4_ = (uint)lVar6;
  local_10._4_4_ = (int)((ulonglong)lVar6 >> 0x20);
  if (((uint)local_10 != *(uint *)_BADOFF_exref) || (local_10._4_4_ != *(int *)(_BADOFF_exref + 4)))
  {
    if (((in_stack_00000020 & 1) == 0) ||
       (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
       pcVar1 == (char *)0x0)) {
      if (((in_stack_00000020 & 2) == 0) ||
         (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
         pcVar1 == (char *)0x0)) {
        lVar6 = *(longlong *)_BADOFF_exref;
      }
      else {
        if (-1 < lVar6) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
          iVar5 = (int)uVar4 >> 0x1f;
          if ((local_10._4_4_ <= iVar5) && ((local_10._4_4_ < iVar5 || ((uint)local_10 <= uVar4))))
          {
            pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            std::basic_streambuf<char,struct_std::char_traits<char>_>::pbump
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                       (int)(pcVar1 + ((uint)local_10 - (int)pcVar2)));
            goto LAB_10024ff4;
          }
        }
        lVar6 = *(longlong *)_BADOFF_exref;
      }
    }
    else {
      if (-1 < lVar6) {
        pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                           ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
        uVar4 = *(int *)((int)this + 0x3c) - (int)pcVar1;
        iVar5 = (int)uVar4 >> 0x1f;
        if ((local_10._4_4_ <= iVar5) && ((local_10._4_4_ < iVar5 || ((uint)local_10 <= uVar4)))) {
          pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
          std::basic_streambuf<char,struct_std::char_traits<char>_>::gbump
                    ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,
                     (int)(pcVar1 + ((uint)local_10 - (int)pcVar2)));
          if (((in_stack_00000020 & 2) != 0) &&
             (pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                                 ((basic_streambuf<char,struct_std::char_traits<char>_> *)this),
             pcVar1 != (char *)0x0)) {
            pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            pcVar3 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase
                               ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
            std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                      ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar3,pcVar2,
                       pcVar1);
          }
          goto LAB_10024ff4;
        }
      }
      lVar6 = *(longlong *)_BADOFF_exref;
    }
  }
LAB_10024ff4:
  local_10 = lVar6;
  FUN_1001dc70(param_1,(uint)local_10,local_10._4_4_);
  return param_1;
}



// Function: FUN_10025010 at 10025010

basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10025010(void *this,uint param_1,int param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030b24;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined **)this = &DAT_10039108;
    *(undefined ***)((int)this + 0x10) = &PTR_10039100;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x60));
    local_8 = 0;
  }
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
             (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18));
  local_8 = 1;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_stringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::
       vftable;
  FUN_100268b0((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return (basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_100250e0 at 100250e0

void __fastcall FUN_100250e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030b57;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(param_1 + -0x60 + *(int *)(*(int *)(param_1 + -0x60) + 4)) =
       std::
       basic_stringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::
       vftable;
  local_8 = 0;
  FUN_100251d0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x48));
  local_8 = 0xffffffff;
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x48));
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025160 at 10025160

void * __thiscall FUN_10025160(void *this,void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030b99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10026940((void *)((int)this + 0x18),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100251d0 at 100251d0

void __fastcall FUN_100251d0(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030bc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8 = 0;
  FUN_10026b00(param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10025240 at 10025240

uint __thiscall FUN_10025240(void *this,ushort param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  uint uVar8;
  uint local_64;
  short local_5e [33];
  wchar_t *local_1c;
  wchar_t *local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *local_8;
  
  local_8 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
  if ((((*(uint *)((int)this + 0x40) & 8) != 0) &&
      (pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                          ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
      pwVar4 != (wchar_t *)0x0)) &&
     (pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_8),
     pwVar4 < *(wchar_t **)(local_8 + 0x3c))) {
    pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr(local_8);
    pwVar4 = *(wchar_t **)(local_8 + 0x3c);
    pwVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase(local_8);
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
              (local_8,pwVar6,pwVar4,pwVar5);
  }
  uVar7 = FUN_10025600();
  local_5e[0] = (short)uVar7;
  uVar1 = FUN_10025580(local_5e,(short *)&param_1);
  if ((char)uVar1 == '\0') {
    pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_8);
    if (pwVar4 != (wchar_t *)0x0) {
      pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_8);
      pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr(local_8);
      if (pwVar4 < pwVar5) {
        wVar3 = FUN_10025560(&param_1);
        pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc(local_8);
        *pwVar4 = wVar3;
        return CONCAT22((short)((uint)pwVar4 >> 0x10),param_1);
      }
    }
    if ((*(uint *)(local_8 + 0x40) & 2) == 0) {
      pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_8);
      if (pwVar4 == (wchar_t *)0x0) {
        local_64 = 0;
      }
      else {
        pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr(local_8);
        pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(local_8);
        local_64 = (int)pwVar4 - (int)pwVar5 >> 1;
      }
      local_10 = local_64;
      local_c = local_64;
      if (local_64 >> 1 < 0x20) {
        local_64 = 0x20;
      }
      else {
        local_64 = local_64 >> 1;
      }
      for (local_14 = local_64; (local_14 != 0 && (0x7fffffff - local_14 < local_10));
          local_14 = local_14 >> 1) {
      }
      if (local_14 == 0) {
        uVar8 = FUN_10025600();
      }
      else {
        local_10 = local_10 + local_14;
        local_18 = (wchar_t *)FUN_1000a9e0(local_10);
        local_1c = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(local_8);
        if (local_c != 0) {
          FUN_1000a2b0(local_18,local_1c,local_c);
        }
        if (local_c == 0) {
          *(wchar_t **)(local_8 + 0x3c) = local_18;
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                    (local_8,local_18,local_18 + local_10);
          if ((*(uint *)(local_8 + 0x40) & 4) == 0) {
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      (local_8,local_18,local_18,local_18 + 1);
          }
          else {
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      (local_8,local_18,(wchar_t *)0x0,local_18);
          }
        }
        else {
          *(wchar_t **)(local_8 + 0x3c) = local_18 + (*(int *)(local_8 + 0x3c) - (int)local_1c >> 1)
          ;
          pwVar4 = local_18 + local_10;
          pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_8);
          pwVar5 = local_18 + ((int)pwVar5 - (int)local_1c >> 1);
          pwVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase(local_8);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                    (local_8,local_18 + ((int)pwVar6 - (int)local_1c >> 1),pwVar5,pwVar4);
          if ((*(uint *)(local_8 + 0x40) & 4) == 0) {
            pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_8);
            pwVar4 = pwVar4 + 1;
            pwVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(local_8);
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      (local_8,local_18,local_18 + ((int)pwVar5 - (int)local_1c >> 1),pwVar4);
          }
          else {
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                      (local_8,local_18,(wchar_t *)0x0,local_18);
          }
        }
        if ((*(uint *)(local_8 + 0x40) & 1) != 0) {
          FUN_1000a7f0(local_1c);
        }
        *(uint *)(local_8 + 0x40) = *(uint *)(local_8 + 0x40) | 1;
        wVar3 = FUN_10025560(&param_1);
        pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc(local_8);
        *pwVar4 = wVar3;
        uVar8 = CONCAT22((short)((uint)pwVar4 >> 0x10),param_1);
      }
    }
    else {
      uVar8 = FUN_10025600();
    }
  }
  else {
    uVar2 = FUN_100255b0(&param_1);
    uVar8 = CONCAT22(extraout_var,uVar2);
  }
  return uVar8;
}



// Function: FUN_10025560 at 10025560

undefined2 __cdecl FUN_10025560(undefined2 *param_1)

{
  return *param_1;
}



// Function: FUN_10025580 at 10025580

undefined2 __cdecl FUN_10025580(short *param_1,short *param_2)

{
  return CONCAT11((char)((ushort)*param_2 >> 8),*param_1 == *param_2);
}



// Function: FUN_100255b0 at 100255b0

ushort __cdecl FUN_100255b0(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = FUN_10025600();
  if ((uint)uVar1 == (uVar2 & 0xffff)) {
    uVar2 = FUN_10025600();
    uVar1 = (ushort)((uVar2 & 0xffff) == 0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



// Function: FUN_10025600 at 10025600

undefined4 FUN_10025600(void)

{
  return 0xffff;
}



// Function: FUN_10025620 at 10025620

void __fastcall FUN_10025620(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  undefined2 uVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  short local_4e;
  short local_4c;
  short local_4a [33];
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *local_8;
  
  local_8 = param_1;
  pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
  if (pwVar3 != (wchar_t *)0x0) {
    pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(local_8);
    pwVar4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(local_8);
    if (pwVar4 < pwVar3) {
      uVar5 = FUN_10025600();
      local_4e = (short)uVar5;
      uVar1 = FUN_10025580(&local_4e,(short *)&stack0x00000004);
      if ((char)uVar1 == '\0') {
        local_4c = FUN_10025560((undefined2 *)&stack0x00000004);
        pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(local_8);
        uVar1 = FUN_10025710(&local_4c,pwVar3 + -1);
        if (((char)uVar1 == '\0') && ((*(uint *)(local_8 + 0x40) & 2) != 0)) goto LAB_100256ac;
      }
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump(local_8,-1);
      uVar5 = FUN_10025600();
      local_4a[0] = (short)uVar5;
      uVar1 = FUN_10025580(local_4a,(short *)&stack0x00000004);
      if ((char)uVar1 == '\0') {
        wVar2 = FUN_10025560((undefined2 *)&stack0x00000004);
        pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(local_8);
        *pwVar3 = wVar2;
      }
      FUN_100255b0((ushort *)&stack0x00000004);
      return;
    }
  }
LAB_100256ac:
  FUN_10025600();
  return;
}



// Function: FUN_10025710 at 10025710

undefined2 __cdecl FUN_10025710(short *param_1,short *param_2)

{
  return CONCAT11((char)((ushort)*param_2 >> 8),*param_1 == *param_2);
}



// Function: FUN_10025740 at 10025740

void __fastcall FUN_10025740(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
  if (pwVar1 == (wchar_t *)0x0) {
    FUN_10025600();
    return;
  }
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
  pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::egptr(param_1);
  if (pwVar2 <= pwVar1) {
    if (((*(uint *)(param_1 + 0x40) & 4) == 0) &&
       (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1),
       pwVar1 != (wchar_t *)0x0)) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
      if ((pwVar2 < pwVar1) ||
         (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1),
         pwVar1 < *(wchar_t **)(param_1 + 0x3c))) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
        if (*(wchar_t **)(param_1 + 0x3c) < pwVar1) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
          *(wchar_t **)(param_1 + 0x3c) = pwVar1;
        }
        pwVar1 = *(wchar_t **)(param_1 + 0x3c);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
        pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(param_1);
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                  (param_1,pwVar3,pwVar2,pwVar1);
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
        FUN_10025850(pwVar1);
        return;
      }
    }
    FUN_10025600();
    return;
  }
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(param_1);
  FUN_10025850(pwVar1);
  return;
}



// Function: FUN_10025850 at 10025850

undefined2 __cdecl FUN_10025850(undefined2 *param_1)

{
  return *param_1;
}



// Function: FUN_10025870 at 10025870

void * __thiscall
FUN_10025870(void *this,void *param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((pwVar1 != (wchar_t *)0x0) &&
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     *(wchar_t **)((int)this + 0x3c) < pwVar1)) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *(wchar_t **)((int)this + 0x3c) = pwVar1;
  }
  if (((param_5 & 1) == 0) ||
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     pwVar1 == (wchar_t *)0x0)) {
    if (((param_5 & 2) == 0) ||
       (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
       pwVar1 == (wchar_t *)0x0)) {
      if (param_2 != 0 || param_3 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(int *)(_BADOFF_exref + 4);
      }
    }
    else {
      if (param_4 == 2) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
        uVar5 = iVar4 >> 1;
        bVar7 = CARRY4(uVar5,param_2);
        param_2 = uVar5 + param_2;
        param_3 = (iVar4 >> 0x1f) + param_3 + (uint)bVar7;
      }
      else if (param_4 == 1) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        uVar5 = (int)pwVar1 - (int)pwVar2 >> 1;
        bVar7 = CARRY4(uVar5,param_2);
        param_2 = uVar5 + param_2;
        param_3 = ((int)pwVar1 - (int)pwVar2 >> 0x1f) + param_3 + (uint)bVar7;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(int *)(_BADOFF_exref + 4);
      }
      if (-1 < param_3) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
        iVar6 = iVar4 >> 0x1f;
        if ((param_3 <= iVar6) && ((param_3 < iVar6 || (param_2 <= (uint)(iVar4 >> 1))))) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbump
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     ((int)pwVar1 - (int)pwVar2 >> 1) + param_2);
          goto LAB_10025b1e;
        }
      }
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(int *)(_BADOFF_exref + 4);
    }
  }
  else {
    if (param_4 == 2) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
      uVar5 = iVar4 >> 1;
      bVar7 = CARRY4(uVar5,param_2);
      param_2 = uVar5 + param_2;
      param_3 = (iVar4 >> 0x1f) + param_3 + (uint)bVar7;
    }
    else if ((param_4 == 1) && ((param_5 & 2) == 0)) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      uVar5 = (int)pwVar1 - (int)pwVar2 >> 1;
      bVar7 = CARRY4(uVar5,param_2);
      param_2 = uVar5 + param_2;
      param_3 = ((int)pwVar1 - (int)pwVar2 >> 0x1f) + param_3 + (uint)bVar7;
    }
    else if (param_4 != 0) {
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(int *)(_BADOFF_exref + 4);
    }
    if (-1 < param_3) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
      iVar6 = iVar4 >> 0x1f;
      if ((param_3 <= iVar6) && ((param_3 < iVar6 || (param_2 <= (uint)(iVar4 >> 1))))) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
                  ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                   ((int)pwVar1 - (int)pwVar2 >> 1) + param_2);
        if (((param_5 & 2) != 0) &&
           (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
           pwVar1 != (wchar_t *)0x0)) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar3,
                     pwVar2,pwVar1);
        }
        goto LAB_10025b1e;
      }
    }
    param_2 = *(uint *)_BADOFF_exref;
    param_3 = *(int *)(_BADOFF_exref + 4);
  }
LAB_10025b1e:
  FUN_1001dc70(param_1,param_2,param_3);
  return param_1;
}



// Function: FUN_10025b40 at 10025b40

void * __thiscall FUN_10025b40(void *this,void *param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  uint in_stack_00000020;
  undefined8 local_10;
  
  lVar6 = FUN_1001dd40((uint *)&stack0x00000008);
  pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((pwVar1 != (wchar_t *)0x0) &&
     (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
     *(wchar_t **)((int)this + 0x3c) < pwVar1)) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *(wchar_t **)((int)this + 0x3c) = pwVar1;
  }
  local_10._0_4_ = (uint)lVar6;
  local_10._4_4_ = (int)((ulonglong)lVar6 >> 0x20);
  if (((uint)local_10 != *(uint *)_BADOFF_exref) || (local_10._4_4_ != *(int *)(_BADOFF_exref + 4)))
  {
    if (((in_stack_00000020 & 1) == 0) ||
       (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
       pwVar1 == (wchar_t *)0x0)) {
      if (((in_stack_00000020 & 2) == 0) ||
         (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this),
         pwVar1 == (wchar_t *)0x0)) {
        lVar6 = *(longlong *)_BADOFF_exref;
      }
      else {
        if (-1 < lVar6) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
          iVar5 = iVar4 >> 0x1f;
          if ((local_10._4_4_ <= iVar5) &&
             ((local_10._4_4_ < iVar5 || ((uint)local_10 <= (uint)(iVar4 >> 1))))) {
            pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbump
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                       ((int)pwVar1 - (int)pwVar2 >> 1) + (uint)local_10);
            goto LAB_10025d2c;
          }
        }
        lVar6 = *(longlong *)_BADOFF_exref;
      }
    }
    else {
      if (-1 < lVar6) {
        pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                           ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
        iVar4 = *(int *)((int)this + 0x3c) - (int)pwVar1;
        iVar5 = iVar4 >> 0x1f;
        if ((local_10._4_4_ <= iVar5) &&
           ((local_10._4_4_ < iVar5 || ((uint)local_10 <= (uint)(iVar4 >> 1))))) {
          pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                             ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gbump
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     ((int)pwVar1 - (int)pwVar2 >> 1) + (uint)local_10);
          if (((in_stack_00000020 & 2) != 0) &&
             (pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                                 ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this
                                 ), pwVar1 != (wchar_t *)0x0)) {
            pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase
                               ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
            std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                      ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar3,
                       pwVar2,pwVar1);
          }
          goto LAB_10025d2c;
        }
      }
      lVar6 = *(longlong *)_BADOFF_exref;
    }
  }
LAB_10025d2c:
  local_10 = lVar6;
  FUN_1001dc70(param_1,(uint)local_10,local_10._4_4_);
  return param_1;
}



// Function: FUN_10025d50 at 10025d50

int * __thiscall FUN_10025d50(void *this,LPCWSTR param_1,UINT param_2)

{
  *(int *)this = (int)this + 4;
  FUN_10026ba0(this,param_1,param_2);
  return (int *)this;
}



// Function: FUN_10025d90 at 10025d90

void __fastcall FUN_10025d90(undefined4 *param_1)

{
  FUN_10027480((void *)*param_1,param_1 + 1);
  return;
}



// Function: FUN_10025dc0 at 10025dc0

undefined4 __fastcall FUN_10025dc0(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10025de0 at 10025de0

int * __thiscall FUN_10025de0(void *this,LPCSTR param_1,UINT param_2)

{
  *(int *)this = (int)this + 4;
  FUN_10026ce0(this,param_1,param_2);
  return (int *)this;
}



// Function: FUN_10025e20 at 10025e20

void __fastcall FUN_10025e20(undefined4 *param_1)

{
  FUN_100274b0((void *)*param_1,param_1 + 1);
  return;
}



// Function: FUN_10025e50 at 10025e50

undefined4 __fastcall FUN_10025e50(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10025e70 at 10025e70

int __thiscall FUN_10025e70(void *this,uint param_1)

{
  FUN_100228e0((int)this + -0x60);
  if ((param_1 & 1) != 0) {
    operator_delete((void *)((int)this + -0x60));
  }
  return (int)this + -0x60;
}



// Function: FUN_10025eb0 at 10025eb0

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10025eb0(void *this,uint param_1)

{
  FUN_100245b0((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_10025ef0 at 10025ef0

int __thiscall FUN_10025ef0(void *this,uint param_1)

{
  FUN_100229b0((int)this + -0x60);
  if ((param_1 & 1) != 0) {
    operator_delete((void *)((int)this + -0x60));
  }
  return (int)this + -0x60;
}



// Function: FUN_10025f30 at 10025f30

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10025f30(void *this,uint param_1)

{
  FUN_100251d0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10025f70 at 10025f70

void __thiscall FUN_10025f70(void *this,char *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_1001d530(param_1);
  FUN_10026eb0(this,(undefined4 *)param_1,uVar1);
  return;
}



// Function: FUN_10025fa0 at 10025fa0

undefined4 * __thiscall
FUN_10025fa0(void *this,uint param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  
  uVar2 = FUN_1000a780(this,param_3);
  if ((uVar2 & 0xff) == 0) {
    if (*(uint *)((int)this + 0x10) < param_1) {
      FUN_1000a630();
    }
    if (*(int *)((int)this + 0x10) - param_1 < param_2) {
      param_2 = *(int *)((int)this + 0x10) - param_1;
    }
    if (-param_4 - 1 <= *(int *)((int)this + 0x10) - param_2) {
      FUN_1000a7d0();
    }
    iVar4 = (*(int *)((int)this + 0x10) - param_2) - param_1;
    if (param_4 < param_2) {
      iVar6 = iVar4;
      puVar3 = FUN_1000a5d0((undefined4 *)this);
      pvVar5 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
      puVar3 = FUN_1000a5d0((undefined4 *)this);
      FUN_1000a470((void *)((int)puVar3 + param_4 * 2 + param_1 * 2),pvVar5,iVar6);
    }
    if ((param_4 != 0) || (param_2 != 0)) {
      uVar2 = (*(int *)((int)this + 0x10) + param_4) - param_2;
      bVar1 = FUN_1000a6e0(this,uVar2,'\0');
      if (bVar1) {
        if (param_2 < param_4) {
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          pvVar5 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          FUN_1000a470((void *)((int)puVar3 + param_4 * 2 + param_1 * 2),pvVar5,iVar4);
        }
        puVar3 = FUN_1000a5d0((undefined4 *)this);
        FUN_1000a2b0((void *)((int)puVar3 + param_1 * 2),param_3,param_4);
        FUN_1000a4f0(this,uVar2);
      }
    }
  }
  else {
    puVar3 = FUN_1000a5d0((undefined4 *)this);
    this = FUN_10026130(this,param_1,param_2,(undefined4 *)this,(int)param_3 - (int)puVar3 >> 1,
                        param_4);
  }
  return (undefined4 *)this;
}



// Function: FUN_10026130 at 10026130

undefined4 * __thiscall
FUN_10026130(void *this,uint param_1,uint param_2,undefined4 *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  uint uVar5;
  
  if (param_1 <= *(uint *)((int)this + 0x10)) {
    uVar1 = FUN_1000a4d0((int)param_3);
    if (param_4 <= uVar1) goto LAB_1002615c;
  }
  FUN_1000a630();
LAB_1002615c:
  if (*(int *)((int)this + 0x10) - param_1 < param_2) {
    param_2 = *(int *)((int)this + 0x10) - param_1;
  }
  iVar2 = FUN_1000a4d0((int)param_3);
  if (iVar2 - param_4 < param_5) {
    param_5 = iVar2 - param_4;
  }
  if (-param_5 - 1 <= *(int *)((int)this + 0x10) - param_2) {
    FUN_1000a7d0();
  }
  iVar2 = (*(int *)((int)this + 0x10) - param_2) - param_1;
  uVar1 = (*(int *)((int)this + 0x10) + param_5) - param_2;
  if (*(uint *)((int)this + 0x10) < uVar1) {
    FUN_1000a6e0(this,uVar1,'\0');
  }
  if ((undefined4 *)this == param_3) {
    if (param_2 < param_5) {
      if (param_1 < param_4) {
        if (param_4 < param_1 + param_2) {
          uVar5 = param_2;
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          pvVar4 = (void *)((int)puVar3 + param_4 * 2);
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          FUN_1000a470((void *)((int)puVar3 + param_1 * 2),pvVar4,uVar5);
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          pvVar4 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          FUN_1000a470((void *)((int)puVar3 + param_5 * 2 + param_1 * 2),pvVar4,iVar2);
          iVar2 = param_5 - param_2;
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          pvVar4 = (void *)((int)puVar3 + param_5 * 2 + param_4 * 2);
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          FUN_1000a470((void *)((int)puVar3 + param_2 * 2 + param_1 * 2),pvVar4,iVar2);
        }
        else {
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          pvVar4 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          FUN_1000a470((void *)((int)puVar3 + param_5 * 2 + param_1 * 2),pvVar4,iVar2);
          uVar5 = param_5;
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          pvVar4 = (void *)((int)puVar3 + ((param_4 + param_5) - param_2) * 2);
          puVar3 = FUN_1000a5d0((undefined4 *)this);
          FUN_1000a470((void *)((int)puVar3 + param_1 * 2),pvVar4,uVar5);
        }
      }
      else {
        puVar3 = FUN_1000a5d0((undefined4 *)this);
        pvVar4 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
        puVar3 = FUN_1000a5d0((undefined4 *)this);
        FUN_1000a470((void *)((int)puVar3 + param_5 * 2 + param_1 * 2),pvVar4,iVar2);
        puVar3 = FUN_1000a5d0((undefined4 *)this);
        pvVar4 = (void *)((int)puVar3 + param_4 * 2);
        puVar3 = FUN_1000a5d0((undefined4 *)this);
        FUN_1000a470((void *)((int)puVar3 + param_1 * 2),pvVar4,param_5);
      }
    }
    else {
      uVar5 = param_5;
      puVar3 = FUN_1000a5d0((undefined4 *)this);
      pvVar4 = (void *)((int)puVar3 + param_4 * 2);
      puVar3 = FUN_1000a5d0((undefined4 *)this);
      FUN_1000a470((void *)((int)puVar3 + param_1 * 2),pvVar4,uVar5);
      puVar3 = FUN_1000a5d0((undefined4 *)this);
      pvVar4 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
      puVar3 = FUN_1000a5d0((undefined4 *)this);
      FUN_1000a470((void *)((int)puVar3 + param_5 * 2 + param_1 * 2),pvVar4,iVar2);
    }
  }
  else {
    puVar3 = FUN_1000a5d0((undefined4 *)this);
    pvVar4 = (void *)((int)puVar3 + param_2 * 2 + param_1 * 2);
    puVar3 = FUN_1000a5d0((undefined4 *)this);
    FUN_1000a470((void *)((int)puVar3 + param_5 * 2 + param_1 * 2),pvVar4,iVar2);
    puVar3 = FUN_1000a600(param_3);
    pvVar4 = (void *)((int)puVar3 + param_4 * 2);
    puVar3 = FUN_1000a5d0((undefined4 *)this);
    FUN_1000a2b0((void *)((int)puVar3 + param_1 * 2),pvVar4,param_5);
  }
  FUN_1000a4f0(this,uVar1);
  return (undefined4 *)this;
}



// Function: FUN_10026460 at 10026460

basic_streambuf<char,struct_std::char_traits<char>_> * __thiscall
FUN_10026460(void *this,uint param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030bf9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  basic_streambuf<char,struct_std::char_traits<char>_>
            ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
  local_8 = 0;
  *(undefined ***)this =
       std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::vftable
  ;
  FUN_1001dbf0((int)this + 0x44);
  uVar1 = FUN_10027080(param_1);
  FUN_10026f70(this,(void *)0x0,0,uVar1);
  ExceptionList = local_10;
  return (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
}



// Function: FUN_100264f0 at 100264f0

void __thiscall FUN_100264f0(void *this,void *param_1)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *local_b4;
  undefined1 local_6c [28];
  undefined1 local_50 [28];
  undefined1 local_34 [28];
  basic_streambuf<char,struct_std::char_traits<char>_> *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030c57;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (basic_streambuf<char,struct_std::char_traits<char>_> *)this;
  if ((*(uint *)((int)this + 0x40) & 2) == 0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr
                       ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
    if (pcVar1 != (char *)0x0) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_18);
      if (*(char **)(local_18 + 0x3c) < pcVar1) {
        local_b4 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(local_18);
      }
      else {
        local_b4 = *(char **)(local_18 + 0x3c);
      }
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase(local_18);
      uVar3 = (int)local_b4 - (int)pcVar1;
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pbase(local_18);
      FUN_10026e00(local_34,(undefined4 *)pcVar1,uVar3);
      local_8 = 1;
      FUN_100266b0(param_1,(int)local_34);
      local_8 = local_8 & 0xffffff00;
      FUN_1001d820(local_34);
      goto LAB_10026687;
    }
  }
  if ((*(uint *)(local_18 + 0x40) & 4) == 0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr(local_18);
    if (pcVar1 != (char *)0x0) {
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(local_18);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(local_18);
      uVar3 = (int)pcVar1 - (int)pcVar2;
      pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(local_18);
      FUN_10026e00(local_50,(undefined4 *)pcVar1,uVar3);
      local_8 = 2;
      FUN_100266b0(param_1,(int)local_50);
      local_8 = local_8 & 0xffffff00;
      FUN_1001d820(local_50);
      goto LAB_10026687;
    }
  }
  FUN_1001d7b0(local_6c);
  local_8 = 3;
  FUN_100266b0(param_1,(int)local_6c);
  local_8 = local_8 & 0xffffff00;
  FUN_1001d820(local_6c);
LAB_10026687:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100266b0 at 100266b0

void * __thiscall FUN_100266b0(void *this,int param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030c88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10027440(param_1 + 0x18);
  FUN_1001dc10(&stack0xffffff94);
  FUN_1001dba0((int)this);
  local_8 = 0;
  FUN_1001dac0(this,'\0',0);
  puVar1 = (undefined4 *)FUN_10027460(param_1);
  FUN_10026740(this,puVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10026740 at 10026740

undefined4 * __thiscall FUN_10026740(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined1 local_4a;
  undefined1 local_49 [65];
  undefined4 *local_8;
  
  local_8 = (undefined4 *)this;
  if ((undefined4 *)this != param_1) {
    FUN_10026f40(&local_4a);
    FUN_10026f40(local_49);
    bVar1 = FUN_100274e0();
    if ((bVar1) && (0xf < (uint)param_1[5])) {
      FUN_10026e80(local_8,param_1);
    }
    else {
      FUN_1001dac0(local_8,'\x01',0);
      if ((uint)param_1[5] < 0x10) {
        FUN_1001da60(local_8,param_1,param_1[4] + 1);
      }
      else {
        *local_8 = *param_1;
        *param_1 = 0;
      }
      local_8[4] = param_1[4];
      local_8[5] = param_1[5];
      FUN_1001dac0(param_1,'\0',0);
    }
  }
  return local_8;
}



// Function: FUN_10026810 at 10026810

void __fastcall FUN_10026810(basic_streambuf<char,struct_std::char_traits<char>_> *param_1)

{
  char *pcVar1;
  
  if ((*(uint *)(param_1 + 0x40) & 1) != 0) {
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::pptr(param_1);
    if (pcVar1 == (char *)0x0) {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::egptr(param_1);
    }
    else {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::epptr(param_1);
    }
    std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    pcVar1 = std::basic_streambuf<char,struct_std::char_traits<char>_>::eback(param_1);
    FUN_1001e140(pcVar1);
  }
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
            (param_1,(char *)0x0,(char *)0x0,(char *)0x0);
  std::basic_streambuf<char,struct_std::char_traits<char>_>::setp(param_1,(char *)0x0,(char *)0x0);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  return;
}



// Function: FUN_100268b0 at 100268b0

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_100268b0(void *this,uint param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030cb9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  local_8 = 0;
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  FUN_1000a6a0((int)this + 0x44);
  uVar1 = FUN_10027210(param_1);
  FUN_100270f0(this,(void *)0x0,0,uVar1);
  ExceptionList = local_10;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10026940 at 10026940

void __thiscall FUN_10026940(void *this,void *param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  uint uVar3;
  wchar_t *local_b4;
  undefined1 local_6c [28];
  undefined1 local_50 [28];
  undefined1 local_34 [28];
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030d17;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
  if ((*(uint *)((int)this + 0x40) & 2) == 0) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    if (pwVar1 != (wchar_t *)0x0) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_18);
      if (*(wchar_t **)(local_18 + 0x3c) < pwVar1) {
        local_b4 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(local_18);
      }
      else {
        local_b4 = *(wchar_t **)(local_18 + 0x3c);
      }
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase(local_18);
      uVar3 = (int)local_b4 - (int)pwVar1 >> 1;
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pbase(local_18);
      FUN_10016300(local_34,(undefined4 *)pwVar1,uVar3);
      local_8 = 1;
      FUN_100157f0(param_1,(int)local_34);
      local_8 = local_8 & 0xffffff00;
      FUN_1000aca0(local_34);
      goto LAB_10026adb;
    }
  }
  if ((*(uint *)(local_18 + 0x40) & 4) == 0) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr(local_18);
    if (pwVar1 != (wchar_t *)0x0) {
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::egptr(local_18);
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(local_18);
      uVar3 = (int)pwVar1 - (int)pwVar2 >> 1;
      pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(local_18);
      FUN_10016300(local_50,(undefined4 *)pwVar1,uVar3);
      local_8 = 2;
      FUN_100157f0(param_1,(int)local_50);
      local_8 = local_8 & 0xffffff00;
      FUN_1000aca0(local_50);
      goto LAB_10026adb;
    }
  }
  FUN_10015780(local_6c);
  local_8 = 3;
  FUN_100157f0(param_1,(int)local_6c);
  local_8 = local_8 & 0xffffff00;
  FUN_1000aca0(local_6c);
LAB_10026adb:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10026b00 at 10026b00

void __fastcall FUN_10026b00(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  wchar_t *pwVar1;
  
  if ((*(uint *)(param_1 + 0x40) & 1) != 0) {
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::pptr(param_1);
    if (pwVar1 == (wchar_t *)0x0) {
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::egptr(param_1);
    }
    else {
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::epptr(param_1);
    }
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(param_1);
    pwVar1 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::eback(param_1);
    FUN_1000a7f0(pwVar1);
  }
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
            (param_1,(wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0);
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
            (param_1,(wchar_t *)0x0,(wchar_t *)0x0);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
  return;
}



// Function: FUN_10026ba0 at 10026ba0

void __thiscall FUN_10026ba0(void *this,LPCWSTR param_1,UINT param_2)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  size_t cbMultiByte;
  bool bVar4;
  
  if (param_1 == (LPCWSTR)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
    iVar1 = iVar1 + 1;
    FUN_10027510((int *)this,iVar1 * 4,(int)this + 4,0x80);
                    /* WARNING: Load size is inaccurate */
    iVar2 = WideCharToMultiByte(param_2,0,param_1,iVar1,*this,iVar1 * 4,(LPCSTR)0x0,(LPBOOL)0x0);
    bVar4 = iVar2 == 0;
    if (bVar4) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        cbMultiByte = WideCharToMultiByte(param_2,0,param_1,iVar1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                          (LPBOOL)0x0);
        FUN_10027510((int *)this,cbMultiByte,(int)this + 4,0x80);
                    /* WARNING: Load size is inaccurate */
        iVar1 = WideCharToMultiByte(param_2,0,param_1,iVar1,*this,cbMultiByte,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        bVar4 = iVar1 == 0;
      }
    }
    if (bVar4) {
      FUN_10026cb0();
    }
  }
  return;
}



// Function: FUN_10026cb0 at 10026cb0

void FUN_10026cb0(void)

{
  DWORD DVar1;
  uint uVar2;
  
  DVar1 = GetLastError();
  uVar2 = FUN_100024c0(DVar1);
  FUN_10003210(uVar2);
  return;
}



// Function: FUN_10026ce0 at 10026ce0

void __thiscall FUN_10026ce0(void *this,LPCSTR param_1,UINT param_2)

{
  int iVar1;
  size_t cbMultiByte;
  DWORD DVar2;
  size_t cchWideChar;
  bool bVar3;
  
  if (param_1 == (LPCSTR)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    iVar1 = lstrlenA(param_1);
    cbMultiByte = iVar1 + 1;
    FUN_10027630((int *)this,cbMultiByte,(int)this + 4,0x80);
                    /* WARNING: Load size is inaccurate */
    iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*this,cbMultiByte);
    bVar3 = iVar1 == 0;
    if (bVar3) {
      DVar2 = GetLastError();
      if (DVar2 == 0x7a) {
        cchWideChar = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,(LPWSTR)0x0,0);
        FUN_10027630((int *)this,cchWideChar,(int)this + 4,0x80);
                    /* WARNING: Load size is inaccurate */
        iVar1 = MultiByteToWideChar(param_2,0,param_1,cbMultiByte,*this,cchWideChar);
        bVar3 = iVar1 == 0;
      }
    }
    if (bVar3) {
      FUN_10026cb0();
    }
  }
  return;
}



// Function: FUN_10026de0 at 10026de0

int __fastcall FUN_10026de0(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_10026e00 at 10026e00

void * __thiscall FUN_10026e00(void *this,undefined4 *param_1,uint param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030d48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001dbf0(&stack0xffffff94);
  FUN_1001dba0((int)this);
  local_8 = 0;
  FUN_1001dac0(this,'\0',0);
  FUN_10026eb0(this,param_1,param_2);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10026e80 at 10026e80

void __thiscall FUN_10026e80(void *this,undefined4 *param_1)

{
  FUN_10027280(this,param_1);
  return;
}



// Function: FUN_10026eb0 at 10026eb0

undefined4 * __thiscall FUN_10026eb0(void *this,undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_10027370(this,param_1);
  if ((uVar2 & 0xff) == 0) {
    bVar1 = FUN_1001e030(this,param_2,'\0');
    if (bVar1) {
      uVar2 = param_2;
      puVar3 = FUN_1001e0d0((undefined4 *)this);
      FUN_1001db40(puVar3,param_1,uVar2);
      FUN_1001dff0(this,param_2);
    }
  }
  else {
    puVar3 = FUN_1001e0d0((undefined4 *)this);
    this = FUN_100272b0(this,(undefined4 *)this,(int)param_1 - (int)puVar3,param_2);
  }
  return (undefined4 *)this;
}



// Function: FUN_10026f40 at 10026f40

undefined4 FUN_10026f40(undefined4 param_1)

{
  FUN_1001dc10(param_1);
  return param_1;
}



// Function: FUN_10026f70 at 10026f70

void __thiscall FUN_10026f70(void *this,void *param_1,uint param_2,undefined4 param_3)

{
  char *pcVar1;
  char *pcVar2;
  char *local_50;
  
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = param_3;
  if ((param_2 != 0) && ((*(uint *)((int)this + 0x40) & 6) != 6)) {
    pcVar1 = (char *)FUN_1001e450(param_2);
    FUN_1001db40(pcVar1,param_1,param_2);
    *(char **)((int)this + 0x3c) = pcVar1 + param_2;
    if ((*(uint *)((int)this + 0x40) & 4) == 0) {
      std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,pcVar1,
                 pcVar1 + param_2);
    }
    if ((*(uint *)((int)this + 0x40) & 2) == 0) {
      local_50 = pcVar1;
      if ((*(uint *)((int)this + 0x40) & 0x10) != 0) {
        local_50 = pcVar1 + param_2;
      }
      std::basic_streambuf<char,struct_std::char_traits<char>_>::setp
                ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,local_50,
                 pcVar1 + param_2);
      pcVar2 = std::basic_streambuf<char,struct_std::char_traits<char>_>::gptr
                         ((basic_streambuf<char,struct_std::char_traits<char>_> *)this);
      if (pcVar2 == (char *)0x0) {
        std::basic_streambuf<char,struct_std::char_traits<char>_>::setg
                  ((basic_streambuf<char,struct_std::char_traits<char>_> *)this,pcVar1,(char *)0x0,
                   pcVar1);
      }
    }
    *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  }
  return;
}



// Function: FUN_10027080 at 10027080

uint FUN_10027080(uint param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((param_1 & 1) == 0) {
    local_c = 4;
  }
  if ((param_1 & 2) == 0) {
    local_c = local_c | 2;
  }
  if ((param_1 & 8) != 0) {
    local_c = local_c | 8;
  }
  if ((param_1 & 4) != 0) {
    local_c = local_c | 0x10;
  }
  return local_c;
}



// Function: FUN_100270f0 at 100270f0

void __thiscall FUN_100270f0(void *this,void *param_1,uint param_2,undefined4 param_3)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t *local_50;
  
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = param_3;
  if ((param_2 != 0) && ((*(uint *)((int)this + 0x40) & 6) != 6)) {
    pwVar1 = (wchar_t *)FUN_1000a9e0(param_2);
    FUN_1000a2b0(pwVar1,param_1,param_2);
    *(wchar_t **)((int)this + 0x3c) = pwVar1 + param_2;
    if ((*(uint *)((int)this + 0x40) & 4) == 0) {
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,pwVar1,
                 pwVar1 + param_2);
    }
    if ((*(uint *)((int)this + 0x40) & 2) == 0) {
      local_50 = pwVar1;
      if ((*(uint *)((int)this + 0x40) & 0x10) != 0) {
        local_50 = pwVar1 + param_2;
      }
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,local_50,
                 pwVar1 + param_2);
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::gptr
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      if (pwVar2 == (wchar_t *)0x0) {
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                  ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,pwVar1,
                   (wchar_t *)0x0,pwVar1);
      }
    }
    *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  }
  return;
}



// Function: FUN_10027210 at 10027210

uint FUN_10027210(uint param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if ((param_1 & 1) == 0) {
    local_c = 4;
  }
  if ((param_1 & 2) == 0) {
    local_c = local_c | 2;
  }
  if ((param_1 & 8) != 0) {
    local_c = local_c | 8;
  }
  if ((param_1 & 4) != 0) {
    local_c = local_c | 0x10;
  }
  return local_c;
}



// Function: FUN_10027280 at 10027280

void __thiscall FUN_10027280(void *this,undefined4 *param_1)

{
  FUN_100272b0(this,param_1,0,0xffffffff);
  return;
}



// Function: FUN_100272b0 at 100272b0

undefined4 * __thiscall FUN_100272b0(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 local_c;
  
  uVar2 = FUN_1001d8a0((int)param_1);
  if (uVar2 < param_2) {
    FUN_1001e120();
  }
  iVar3 = FUN_1001d8a0((int)param_1);
  local_c = iVar3 - param_2;
  if (param_3 < local_c) {
    local_c = param_3;
  }
  if ((undefined4 *)this == param_1) {
    FUN_1001d9c0(this,param_2 + local_c,0xffffffff);
    FUN_1001d9c0(this,0,param_2);
  }
  else {
    bVar1 = FUN_1001e030(this,local_c,'\0');
    if (bVar1) {
      uVar2 = local_c;
      puVar4 = FUN_1001db70(param_1);
      pvVar5 = (void *)((int)puVar4 + param_2);
      puVar4 = FUN_1001e0d0((undefined4 *)this);
      FUN_1001db40(puVar4,pvVar5,uVar2);
      FUN_1001dff0(this,local_c);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_10027370 at 10027370

uint __thiscall FUN_10027370(void *this,undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (in_EAX = FUN_1001e0d0((undefined4 *)this), in_EAX <= param_1)) {
    puVar1 = FUN_1001e0d0((undefined4 *)this);
    in_EAX = (undefined4 *)((int)puVar1 + *(int *)((int)this + 0x10));
    if (param_1 < in_EAX) {
      return CONCAT31((int3)((uint)in_EAX >> 8),1);
    }
  }
  return (uint)in_EAX & 0xffffff00;
}



// Function: FUN_100273c0 at 100273c0

uint __cdecl FUN_100273c0(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (-param_2 - 1U < param_3) {
    uVar1 = FUN_100024c0(0x216);
  }
  else {
    *param_1 = param_2 + param_3;
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10027400 at 10027400

int __cdecl FUN_10027400(int param_1,uint param_2)

{
  uint uVar1;
  int local_8;
  
  uVar1 = FUN_100273c0(&local_8,param_1,param_2);
  if ((int)uVar1 < 0) {
    FUN_10003210(uVar1);
  }
  return local_8;
}



// Function: FUN_10027440 at 10027440

undefined4 __cdecl FUN_10027440(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10027460 at 10027460

undefined4 __cdecl FUN_10027460(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10027480 at 10027480

void __cdecl FUN_10027480(void *param_1,void *param_2)

{
  if (param_1 != param_2) {
    free(param_1);
  }
  return;
}



// Function: FUN_100274b0 at 100274b0

void __cdecl FUN_100274b0(void *param_1,void *param_2)

{
  if (param_1 != param_2) {
    free(param_1);
  }
  return;
}



// Function: FUN_100274e0 at 100274e0

bool FUN_100274e0(void)

{
  char cVar1;
  
  cVar1 = FUN_10027750();
  return (bool)('\x01' - (cVar1 != '\0'));
}



// Function: FUN_10027510 at 10027510

void __cdecl FUN_10027510(int *param_1,size_t param_2,int param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_10003210(0x80070057);
  }
  if ((int)param_2 < 0) {
    FUN_10003210(0x80070057);
  }
  if (param_3 == 0) {
    FUN_10003210(0x80070057);
  }
  if (*param_1 == param_3) {
    if (param_4 < (int)param_2) {
      pvVar1 = calloc(param_2,1);
      *param_1 = (int)pvVar1;
    }
    else {
      *param_1 = param_3;
    }
  }
  else if (param_4 < (int)param_2) {
    pvVar1 = _recalloc((void *)*param_1,param_2,1);
    if (pvVar1 == (void *)0x0) {
      FUN_10003210(0x8007000e);
    }
    *param_1 = (int)pvVar1;
  }
  else {
    free((void *)*param_1);
    *param_1 = param_3;
  }
  if (*param_1 == 0) {
    FUN_10003210(0x8007000e);
  }
  return;
}



// Function: FUN_10027630 at 10027630

void __cdecl FUN_10027630(int *param_1,size_t param_2,int param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
    FUN_10003210(0x80070057);
  }
  if ((int)param_2 < 0) {
    FUN_10003210(0x80070057);
  }
  if (param_3 == 0) {
    FUN_10003210(0x80070057);
  }
  if (*param_1 == param_3) {
    if (param_4 < (int)param_2) {
      pvVar1 = calloc(param_2,2);
      *param_1 = (int)pvVar1;
    }
    else {
      *param_1 = param_3;
    }
  }
  else if (param_4 < (int)param_2) {
    pvVar1 = _recalloc((void *)*param_1,param_2,2);
    if (pvVar1 == (void *)0x0) {
      FUN_10003210(0x8007000e);
    }
    *param_1 = (int)pvVar1;
  }
  else {
    free((void *)*param_1);
    *param_1 = param_3;
  }
  if (*param_1 == 0) {
    FUN_10003210(0x8007000e);
  }
  return;
}



// Function: FUN_10027750 at 10027750

undefined1 FUN_10027750(void)

{
  return 1;
}



// Function: FUN_10027770 at 10027770

undefined4 * __fastcall FUN_10027770(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030d7b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004e20(param_1 + 1,0);
  *param_1 = CRegKeyEx::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100277e0 at 100277e0

undefined4 * __thiscall FUN_100277e0(void *this,uint param_1)

{
  FUN_10027820((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10027820 at 10027820

void __fastcall FUN_10027820(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030dab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CRegKeyEx::vftable;
  local_8 = 0xffffffff;
  FUN_10004e60(param_1 + 1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10027880 at 10027880

undefined4 FUN_10027880(LPCWSTR param_1)

{
  int iVar1;
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (0xd < local_c) {
      return 0;
    }
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)(&PTR_u_HKCR_10039150)[local_c * 2]);
    if (iVar1 == 0) break;
    local_c = local_c + 1;
  }
  return *(undefined4 *)(&DAT_10039154 + local_c * 8);
}



// Function: FUN_100278e0 at 100278e0

void FUN_100278e0(void *param_1,char param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_2b8 [7];
  LPWSTR local_29c;
  LPWSTR local_298;
  undefined1 local_294 [4];
  undefined1 local_290 [68];
  uint local_24c;
  LPWSTR local_248;
  uint local_244;
  _FILETIME local_240;
  DWORD local_238;
  DWORD local_234;
  DWORD local_230;
  DWORD local_22c;
  DWORD local_228;
  DWORD local_224;
  uint local_220;
  DWORD local_21c;
  WCHAR local_218;
  undefined1 local_216 [510];
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030ddb;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10027e00(param_1);
  local_218 = L'\0';
  memset(local_216,0,0x1fc);
  local_21c = 0xff;
  local_244 = RegQueryInfoKeyW(*(HKEY *)(local_18 + 4),&local_218,&local_21c,(LPDWORD)0x0,&local_220
                               ,&local_224,&local_228,&local_22c,&local_230,&local_234,&local_238,
                               &local_240);
  local_224 = local_224 + 1;
  local_29c = (LPWSTR)FUN_1002bb86(-(uint)((int)((ulonglong)local_224 * 2 >> 0x20) != 0) |
                                   (uint)((ulonglong)local_224 * 2));
  local_24c = 0;
  local_248 = local_29c;
  while ((local_24c < local_220 && ((local_244 == 0xea || (local_244 == 0))))) {
    local_244 = RegEnumKeyW(*(HKEY *)(local_18 + 4),local_24c,local_248,local_224);
    if (local_244 == 0) {
      FUN_1000a150(local_2b8,local_248);
      local_8 = 0;
      FUN_1001edb0(param_1,local_2b8);
      local_8 = 0xffffffff;
      FUN_1000aca0(local_2b8);
    }
    local_24c = local_24c + 1;
  }
  if (local_248 != (LPWSTR)0x0) {
    local_298 = local_248;
    operator_delete__(local_248);
  }
  if (param_2 == '\x01') {
    puVar1 = (undefined4 *)FUN_1001ed80(param_1,local_294);
    uVar3 = *puVar1;
    piVar2 = (int *)FUN_1001ed50(param_1,local_290);
    FUN_100286f0(*piVar2,uVar3);
  }
  FUN_100024c0(local_244);
  ExceptionList = local_10;
  local_2b8[0] = 0x10027b13;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10027b20 at 10027b20

void FUN_10027b20(undefined4 *param_1,void *param_2)

{
  longlong lVar1;
  LPCWSTR pWVar2;
  HKEY pHVar3;
  void *this;
  WCHAR *lpClass;
  DWORD *lpcchClass;
  LPDWORD pDVar4;
  DWORD *lpcSubKeys;
  DWORD *lpcbMaxSubKeyLen;
  DWORD *lpcbMaxClassLen;
  uint *lpcValues;
  DWORD *lpcbMaxValueNameLen;
  LPWSTR lpValueName;
  DWORD *pDVar5;
  DWORD *pDVar6;
  uint uVar7;
  _FILETIME *lpftLastWriteTime;
  LPDWORD lpType;
  wchar_t *pwVar8;
  undefined4 local_2dc;
  undefined4 uStack_2d8;
  LPWSTR local_2c0;
  wchar_t *local_2bc;
  LPWSTR local_2b8;
  wchar_t *local_2b4;
  uint local_2b0;
  DWORD local_26c;
  DWORD local_268;
  uint local_264;
  wchar_t *local_260;
  LPWSTR local_25c;
  LSTATUS local_258;
  _FILETIME local_254;
  DWORD local_24c;
  DWORD local_248;
  DWORD local_244;
  uint local_240;
  DWORD local_23c;
  DWORD local_238;
  DWORD local_234 [2];
  WCHAR local_22c;
  undefined1 local_22a [510];
  uint local_2c;
  undefined4 local_28;
  int local_24 [3];
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030e23;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10027fa0(param_2);
  FUN_10027770(&local_28);
  local_8 = 0;
  uVar7 = 0x2001f;
  pWVar2 = (LPCWSTR)FUN_10015940(param_1);
  local_2c = FUN_10005260(local_24,*(HKEY *)(local_18 + 4),pWVar2,uVar7);
  if (local_2c == 0) {
    local_22c = L'\0';
    memset(local_22a,0,0x1fc);
    local_234[1] = 0xff;
    lpftLastWriteTime = &local_254;
    pDVar6 = &local_24c;
    pDVar5 = &local_248;
    lpcbMaxValueNameLen = &local_244;
    lpcValues = &local_240;
    lpcbMaxClassLen = &local_23c;
    lpcbMaxSubKeyLen = &local_238;
    lpcSubKeys = local_234;
    pDVar4 = (LPDWORD)0x0;
    lpcchClass = local_234 + 1;
    lpClass = &local_22c;
    pHVar3 = (HKEY)FUN_10004e80(local_24);
    local_258 = RegQueryInfoKeyW(pHVar3,lpClass,lpcchClass,pDVar4,lpcSubKeys,lpcbMaxSubKeyLen,
                                 lpcbMaxClassLen,lpcValues,lpcbMaxValueNameLen,pDVar5,pDVar6,
                                 lpftLastWriteTime);
    lVar1 = (ulonglong)(local_244 + 1) * 2;
    local_2c0 = (LPWSTR)FUN_1002bb86(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    lVar1 = (ulonglong)(local_248 + 1) * 2;
    local_25c = local_2c0;
    local_2bc = (wchar_t *)FUN_1002bb86(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1)
    ;
    local_264 = 0;
    local_260 = local_2bc;
    while ((local_264 < local_240 && ((local_258 == 0xea || (local_258 == 0))))) {
      local_268 = local_244 + 1;
      local_26c = local_248 + 1;
      pDVar6 = &local_26c;
      lpType = (LPDWORD)0x0;
      pDVar4 = (LPDWORD)0x0;
      pDVar5 = &local_268;
      uVar7 = local_264;
      lpValueName = local_25c;
      pwVar8 = local_260;
      pHVar3 = (HKEY)FUN_10004e80(local_24);
      local_258 = RegEnumValueW(pHVar3,uVar7,lpValueName,pDVar5,pDVar4,lpType,(LPBYTE)pwVar8,pDVar6)
      ;
      FUN_1000a150(&local_2dc,local_25c);
      local_8._0_1_ = 1;
      pwVar8 = local_260;
      this = (void *)FUN_10027e50(param_2,&local_2dc);
      FUN_100158e0(this,pwVar8);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_1000aca0(&local_2dc);
      local_264 = local_264 + 1;
    }
    local_2b8 = local_25c;
    operator_delete__(local_25c);
    local_2b4 = local_260;
    operator_delete__(local_260);
    local_258 = FUN_10005090(local_24);
  }
  local_2b0 = FUN_100024c0(local_2c);
  local_8 = 0xffffffff;
  FUN_10027820(&local_28);
  ExceptionList = local_10;
  uStack_2d8 = 0x10027dee;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10027e00 at 10027e00

void __fastcall FUN_10027e00(void *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [68];
  void *local_8;
  
  local_8 = param_1;
  puVar2 = (undefined4 *)FUN_1001ed80(param_1,local_58);
  uVar1 = *puVar2;
  puVar2 = (undefined4 *)FUN_1001ed50(local_8,local_50);
  local_54 = *puVar2;
  FUN_100280d0(local_4c,local_54,uVar1);
  return;
}



// Function: FUN_10027e50 at 10027e50

void __thiscall FUN_10027e50(void *this,undefined4 *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined1 local_bc [28];
  undefined1 local_a0 [56];
  undefined1 local_68 [4];
  int local_64;
  undefined4 local_60 [17];
  int local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030e66;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = this;
  FUN_100281a0(this,&local_1c,param_1);
  piVar3 = (int *)FUN_10028170(local_18,local_68);
  bVar1 = FUN_10028360(&local_1c,piVar3);
  if (!bVar1) {
    iVar4 = FUN_10028390(&local_1c);
    puVar5 = (undefined4 *)FUN_10028310(iVar4);
    cVar2 = FUN_1000e9c0(param_1,puVar5);
    if (cVar2 == '\0') goto LAB_10027f69;
  }
  local_64 = local_1c;
  pvVar6 = FUN_10015780(local_bc);
  local_8 = 0;
  pvVar6 = FUN_100283b0(local_a0,param_1,pvVar6);
  local_8._0_1_ = 1;
  piVar3 = FUN_10028730(local_18,local_60,local_64,pvVar6);
  local_1c = *piVar3;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10028000(local_a0);
  local_8 = 0xffffffff;
  FUN_1000aca0(local_bc);
LAB_10027f69:
  FUN_10028340(&local_1c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10027fa0 at 10027fa0

void __fastcall FUN_10027fa0(void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_100282e0((int)param_1);
  FUN_100281e0(param_1,(void *)*puVar1);
  puVar1 = (undefined4 *)FUN_100282e0((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_10028280((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  puVar1 = (undefined4 *)FUN_100282b0((int)param_1);
  *puVar1 = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 8) = 0;
  return;
}



// Function: FUN_10028000 at 10028000

void __fastcall FUN_10028000(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030e98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10028060(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10028060 at 10028060

void __fastcall FUN_10028060(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10030ed3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1000aca0((void *)((int)param_1 + 0x1c));
  local_8 = 0xffffffff;
  FUN_1000aca0(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100280d0 at 100280d0

void * FUN_100280d0(void *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  void *pvVar2;
  int local_10;
  void *local_c;
  void *local_8;
  
  FUN_10028420(&local_c,param_2);
  FUN_10028420(&local_10,param_3);
  bVar1 = FUN_1001ef30(&local_c,&local_10);
  if (bVar1) {
    pvVar2 = (void *)FUN_10028770(local_10,*(int *)((int)local_8 + 4),local_c);
    FUN_1000fb30(local_8,pvVar2,*(void **)((int)local_8 + 4));
    *(void **)((int)local_8 + 4) = pvVar2;
  }
  FUN_10028420(param_1,local_c);
  return param_1;
}



// Function: FUN_10028170 at 10028170

void * __thiscall FUN_10028170(void *this,void *param_1)

{
  FUN_100285b0(param_1,*(undefined4 *)((int)this + 4));
  return param_1;
}



// Function: FUN_100281a0 at 100281a0

void * __thiscall FUN_100281a0(void *this,void *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_10028450(this,param_2);
  FUN_100285b0(param_1,iVar1);
  return param_1;
}



// Function: FUN_100281e0 at 100281e0

void __thiscall FUN_100281e0(void *this,void *param_1)

{
  void *pvVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined4 local_c;
  
  local_c = param_1;
  while( true ) {
    pcVar2 = (char *)FUN_100284e0((int)local_c);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_10028540((int)local_c);
    FUN_100281e0(this,(void *)*puVar3);
    puVar3 = (undefined4 *)FUN_10028500(local_c);
    pvVar1 = (void *)*puVar3;
    iVar4 = FUN_10028560((int)local_c);
    pvVar5 = (void *)FUN_100287b0(iVar4);
    FUN_100287d0((int)this + 0xd,pvVar5);
    FUN_10028580(local_c);
    local_c = pvVar1;
  }
  return;
}



// Function: FUN_10028280 at 10028280

void __fastcall FUN_10028280(int param_1)

{
  FUN_10028500(*(undefined4 *)(param_1 + 4));
  return;
}



// Function: FUN_100282b0 at 100282b0

void __fastcall FUN_100282b0(int param_1)

{
  FUN_10028540(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_100282e0 at 100282e0

void __fastcall FUN_100282e0(int param_1)

{
  FUN_10028520(*(int *)(param_1 + 4));
  return;
}



// Function: FUN_10028310 at 10028310

void __cdecl FUN_10028310(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10028560(param_1);
  FUN_100287f0(iVar1);
  return;
}



// Function: FUN_10028340 at 10028340

void __fastcall FUN_10028340(int *param_1)

{
  FUN_100285e0(param_1);
  return;
}



// Function: FUN_10028360 at 10028360

bool __thiscall FUN_10028360(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  return *this == *param_1;
}



// Function: FUN_10028390 at 10028390

undefined4 __fastcall FUN_10028390(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_100283b0 at 100283b0

void * __thiscall FUN_100283b0(void *this,undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030ef8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10016bf0(param_2);
  FUN_10028610(this,param_1,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10028420 at 10028420

void * FUN_10028420(void *param_1,undefined4 param_2)

{
  FUN_1001f070(param_1,param_2);
  return param_1;
}



// Function: FUN_10028450 at 10028450

int __thiscall FUN_10028450(void *this,undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int local_10;
  int local_c;
  
  piVar2 = (int *)FUN_100282e0((int)this);
  local_c = *piVar2;
  local_10 = *(int *)((int)this + 4);
  while (pcVar3 = (char *)FUN_100284e0(local_c), *pcVar3 == '\0') {
    puVar5 = param_1;
    pvVar4 = (void *)FUN_10028310(local_c);
    cVar1 = FUN_1000e9c0(pvVar4,puVar5);
    if (cVar1 == '\0') {
      local_10 = local_c;
      piVar2 = (int *)FUN_10028500(local_c);
      local_c = *piVar2;
    }
    else {
      piVar2 = (int *)FUN_10028540(local_c);
      local_c = *piVar2;
    }
  }
  return local_10;
}



// Function: FUN_100284e0 at 100284e0

int __cdecl FUN_100284e0(int param_1)

{
  return param_1 + 0x45;
}



// Function: FUN_10028500 at 10028500

undefined4 __cdecl FUN_10028500(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10028520 at 10028520

int __cdecl FUN_10028520(int param_1)

{
  return param_1 + 4;
}



// Function: FUN_10028540 at 10028540

int __cdecl FUN_10028540(int param_1)

{
  return param_1 + 8;
}



// Function: FUN_10028560 at 10028560

int __cdecl FUN_10028560(int param_1)

{
  return param_1 + 0xc;
}



// Function: FUN_10028580 at 10028580

void FUN_10028580(void *param_1)

{
  operator_delete(param_1);
  return;
}



// Function: FUN_100285b0 at 100285b0

void * __thiscall FUN_100285b0(void *this,undefined4 param_1)

{
  FUN_10028690(this,param_1);
  return this;
}



// Function: FUN_100285e0 at 100285e0

void __fastcall FUN_100285e0(int *param_1)

{
  FUN_10028560(*param_1);
  return;
}



// Function: FUN_10028610 at 10028610

void * __thiscall FUN_10028610(void *this,undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030f33;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100156f0(this,param_1);
  local_8 = 0;
  iVar1 = FUN_10016bf0(param_2);
  FUN_100157f0((void *)((int)this + 0x1c),iVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_10028690 at 10028690

void * __thiscall FUN_10028690(void *this,undefined4 param_1)

{
  FUN_100286c0(this,param_1);
  return this;
}



// Function: FUN_100286c0 at 100286c0

undefined4 * __thiscall FUN_100286c0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  FUN_10014df0();
  return (undefined4 *)this;
}



// Function: FUN_100286f0 at 100286f0

void __cdecl FUN_100286f0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_10028810(&param_2,&param_1);
  puVar2 = (undefined4 *)FUN_10029c10();
  puVar3 = (undefined4 *)FUN_10029c10();
  FUN_10029c30(puVar3,puVar2,iVar1);
  return;
}



// Function: FUN_10028730 at 10028730

undefined4 * __thiscall FUN_10028730(void *this,undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = FUN_10029d30(param_3);
  pvVar2 = (void *)FUN_10029d50(this,uVar1);
  FUN_10028840(param_1,param_2,pvVar2);
  return param_1;
}



// Function: FUN_10028770 at 10028770

void __cdecl FUN_10028770(int param_1,int param_2,void *param_3)

{
  FUN_10013e20();
  FUN_10029e10(param_1,param_2,param_3);
  return;
}



// Function: FUN_100287b0 at 100287b0

undefined4 __cdecl FUN_100287b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_100287d0 at 100287d0

void __cdecl FUN_100287d0(undefined4 param_1,void *param_2)

{
  FUN_10028e50(param_2);
  return;
}



// Function: FUN_100287f0 at 100287f0

undefined4 __cdecl FUN_100287f0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10028810 at 10028810

void __thiscall FUN_10028810(void *this,int *param_1)

{
  FUN_10028e80(this,param_1);
  return;
}



// Function: FUN_10028840 at 10028840

/* WARNING: Removing unreachable block (ram,0x100288a1) */
/* WARNING: Removing unreachable block (ram,0x10028917) */
/* WARNING: Removing unreachable block (ram,0x1002898d) */
/* WARNING: Removing unreachable block (ram,0x100289bf) */
/* WARNING: Removing unreachable block (ram,0x100289fa) */
/* WARNING: Removing unreachable block (ram,0x10028a42) */
/* WARNING: Removing unreachable block (ram,0x10028a1d) */
/* WARNING: Removing unreachable block (ram,0x10028a6a) */
/* WARNING: Removing unreachable block (ram,0x10028a9c) */
/* WARNING: Removing unreachable block (ram,0x10028ac5) */
/* WARNING: Removing unreachable block (ram,0x10028af3) */
/* WARNING: Removing unreachable block (ram,0x10028b3b) */
/* WARNING: Removing unreachable block (ram,0x10028b16) */
/* WARNING: Removing unreachable block (ram,0x10028b60) */
/* WARNING: Removing unreachable block (ram,0x10028933) */
/* WARNING: Removing unreachable block (ram,0x10028963) */
/* WARNING: Removing unreachable block (ram,0x10028988) */
/* WARNING: Removing unreachable block (ram,0x100288bd) */
/* WARNING: Removing unreachable block (ram,0x100288eb) */
/* WARNING: Removing unreachable block (ram,0x1002890e) */
/* WARNING: Removing unreachable block (ram,0x10028b64) */

undefined4 * FUN_10028840(undefined4 *param_1,int param_2,void *param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  char *pcVar6;
  int *this;
  undefined4 *puVar7;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [75];
  char local_11;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_10028560((int)param_3);
  FUN_100295a0(&local_10);
  local_11 = '\0';
  iVar3 = FUN_10028ef0((int)local_8);
  if (iVar3 == 0) {
    FUN_10029160(local_8,param_1,'\x01',*(int *)((int)local_8 + 4),param_3);
    return param_1;
  }
  piVar4 = (int *)FUN_10028ec0(local_8,local_68);
  bVar1 = FUN_10028360(&param_2,piVar4);
  if (bVar1) {
    iVar3 = FUN_10028390(&param_2);
    puVar7 = (undefined4 *)FUN_10028310(iVar3);
    pvVar5 = (void *)FUN_100287f0(local_c);
    cVar2 = FUN_1000e9c0(pvVar5,puVar7);
    if (cVar2 != '\0') {
      pvVar5 = param_3;
      iVar3 = FUN_10028390(&param_2);
      FUN_10029160(local_8,param_1,'\x01',iVar3,pvVar5);
      return param_1;
    }
  }
  else {
    piVar4 = (int *)FUN_10028170(local_8,local_64);
    bVar1 = FUN_10028360(&param_2,piVar4);
    if (bVar1) {
      puVar7 = (undefined4 *)FUN_100287f0(local_c);
      piVar4 = (int *)FUN_100282b0((int)local_8);
      pvVar5 = (void *)FUN_10028310(*piVar4);
      cVar2 = FUN_1000e9c0(pvVar5,puVar7);
      if (cVar2 != '\0') {
        pvVar5 = param_3;
        piVar4 = (int *)FUN_100282b0((int)local_8);
        FUN_10029160(local_8,param_1,'\0',*piVar4,pvVar5);
        return param_1;
      }
    }
    else {
      iVar3 = FUN_10028390(&param_2);
      puVar7 = (undefined4 *)FUN_10028310(iVar3);
      pvVar5 = (void *)FUN_100287f0(local_c);
      cVar2 = FUN_1000e9c0(pvVar5,puVar7);
      if (cVar2 != '\0') {
        local_10 = param_2;
        puVar7 = (undefined4 *)FUN_100287f0(local_c);
        piVar4 = FUN_100295e0(&local_10);
        iVar3 = FUN_10028390(piVar4);
        pvVar5 = (void *)FUN_10028310(iVar3);
        cVar2 = FUN_1000e9c0(pvVar5,puVar7);
        if (cVar2 != '\0') {
          iVar3 = FUN_10028390(&local_10);
          piVar4 = (int *)FUN_10028540(iVar3);
          pcVar6 = (char *)FUN_100284e0(*piVar4);
          if (*pcVar6 != '\0') {
            pvVar5 = param_3;
            iVar3 = FUN_10028390(&local_10);
            FUN_10029160(local_8,param_1,'\0',iVar3,pvVar5);
            return param_1;
          }
          pvVar5 = param_3;
          iVar3 = FUN_10028390(&param_2);
          FUN_10029160(local_8,param_1,'\x01',iVar3,pvVar5);
          return param_1;
        }
      }
      puVar7 = (undefined4 *)FUN_100287f0(local_c);
      iVar3 = FUN_10028390(&param_2);
      pvVar5 = (void *)FUN_10028310(iVar3);
      cVar2 = FUN_1000e9c0(pvVar5,puVar7);
      if (cVar2 != '\0') {
        local_10 = param_2;
        piVar4 = (int *)FUN_10028170(local_8,local_60);
        this = FUN_100295c0(&local_10);
        bVar1 = FUN_10028360(this,piVar4);
        if (!bVar1) {
          iVar3 = FUN_10028390(&local_10);
          puVar7 = (undefined4 *)FUN_10028310(iVar3);
          pvVar5 = (void *)FUN_100287f0(local_c);
          cVar2 = FUN_1000e9c0(pvVar5,puVar7);
          if (cVar2 == '\0') goto LAB_10028e1c;
        }
        iVar3 = FUN_10028390(&param_2);
        piVar4 = (int *)FUN_10028540(iVar3);
        pcVar6 = (char *)FUN_100284e0(*piVar4);
        if (*pcVar6 != '\0') {
          pvVar5 = param_3;
          iVar3 = FUN_10028390(&param_2);
          FUN_10029160(local_8,param_1,'\0',iVar3,pvVar5);
          return param_1;
        }
        pvVar5 = param_3;
        iVar3 = FUN_10028390(&local_10);
        FUN_10029160(local_8,param_1,'\x01',iVar3,pvVar5);
        return param_1;
      }
    }
  }
LAB_10028e1c:
  puVar7 = (undefined4 *)FUN_10028f10(local_5c,param_3,local_11);
  *param_1 = *puVar7;
  return param_1;
}



// Function: FUN_10028e50 at 10028e50

void FUN_10028e50(void *param_1)

{
  FUN_10029e60(param_1);
  return;
}



// Function: FUN_10028e80 at 10028e80

int __thiscall FUN_10028e80(void *this,int *param_1)

{
  FUN_1001f1b0();
                    /* WARNING: Load size is inaccurate */
  return (*this - *param_1) / 0x1c;
}



// Function: FUN_10028ec0 at 10028ec0

void * __thiscall FUN_10028ec0(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10028280((int)this);
  FUN_100285b0(param_1,*puVar1);
  return param_1;
}



// Function: FUN_10028ef0 at 10028ef0

undefined4 __fastcall FUN_10028ef0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10028f10 at 10028f10

/* WARNING: Removing unreachable block (ram,0x10028ffb) */

void * FUN_10028f10(void *param_1,void *param_2,char param_3)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_80;
  undefined1 local_74 [7];
  undefined1 local_6d;
  undefined1 local_6c [7];
  undefined1 local_65;
  undefined1 local_64 [7];
  undefined1 local_5d [65];
  int local_1c;
  char local_15;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = FUN_10028560((int)param_2);
  piVar3 = (int *)FUN_100282e0((int)local_8);
  local_10 = *piVar3;
  local_14 = *(int *)((int)local_8 + 4);
  local_15 = '\x01';
  while (pcVar4 = (char *)FUN_100284e0(local_10), *pcVar4 == '\0') {
    local_14 = local_10;
    if (param_3 == '\0') {
      puVar5 = (undefined4 *)FUN_10028310(local_10);
      pvVar6 = (void *)FUN_100287f0(local_c);
      local_15 = FUN_1000e9c0(pvVar6,puVar5);
    }
    else {
      puVar5 = (undefined4 *)FUN_100287f0(local_c);
      pvVar6 = (void *)FUN_10028310(local_10);
      cVar1 = FUN_1000e9c0(pvVar6,puVar5);
      local_15 = '\x01' - (cVar1 != '\0');
    }
    if (local_15 == '\0') {
      piVar3 = (int *)FUN_10028540(local_10);
      local_80 = *piVar3;
    }
    else {
      piVar3 = (int *)FUN_10028500(local_10);
      local_80 = *piVar3;
    }
    local_10 = local_80;
  }
  FUN_100285b0(&local_1c,local_14);
  if (local_15 != '\0') {
    piVar3 = (int *)FUN_10028ec0(local_8,local_74);
    bVar2 = FUN_10028360(&local_1c,piVar3);
    if (bVar2) {
      local_6d = 1;
      puVar8 = &local_6d;
      pvVar6 = FUN_10029160(local_8,local_6c,'\x01',local_14,param_2);
      FUN_10029ab0(param_1,pvVar6,puVar8);
      return param_1;
    }
    FUN_100298c0(&local_1c);
  }
  puVar5 = (undefined4 *)FUN_100287f0(local_c);
  iVar7 = FUN_10028390(&local_1c);
  pvVar6 = (void *)FUN_10028310(iVar7);
  cVar1 = FUN_1000e9c0(pvVar6,puVar5);
  if (cVar1 == '\0') {
    iVar7 = FUN_10028560((int)param_2);
    pvVar6 = (void *)FUN_100287b0(iVar7);
    FUN_100287d0((int)local_8 + 0xd,pvVar6);
    FUN_10028580(param_2);
    local_5d[0] = 0;
    FUN_10029e80(param_1,&local_1c,local_5d);
  }
  else {
    local_65 = 1;
    puVar8 = &local_65;
    pvVar6 = FUN_10029160(local_8,local_64,local_15,local_14,param_2);
    FUN_10029ab0(param_1,pvVar6,puVar8);
  }
  return param_1;
}



// Function: FUN_10029160 at 10029160

void * __thiscall FUN_10029160(void *this,void *param_1,char param_2,int param_3,void *param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *puVar7;
  void *local_c;
  
  iVar1 = FUN_10029600();
  if (iVar1 - 1U <= *(uint *)((int)this + 8)) {
    iVar1 = FUN_10028560((int)param_4);
    pvVar2 = (void *)FUN_100287b0(iVar1);
    FUN_100287d0((int)this + 0xd,pvVar2);
    FUN_10028580(param_4);
    std::_Xlength_error("map/set<T> too long");
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  *(int *)((int)param_4 + 4) = param_3;
  if (param_3 == *(int *)((int)this + 4)) {
    puVar3 = (undefined4 *)FUN_100282e0((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_10028280((int)this);
    *puVar3 = param_4;
    puVar3 = (undefined4 *)FUN_100282b0((int)this);
    *puVar3 = param_4;
  }
  else if (param_2 == '\0') {
    puVar3 = (undefined4 *)FUN_10028540(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_100282b0((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_100282b0((int)this);
      *puVar3 = param_4;
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_10028500(param_3);
    *puVar3 = param_4;
    piVar4 = (int *)FUN_10028280((int)this);
    if (param_3 == *piVar4) {
      puVar3 = (undefined4 *)FUN_10028280((int)this);
      *puVar3 = param_4;
    }
  }
  local_c = param_4;
  while( true ) {
    piVar4 = (int *)FUN_10028520((int)local_c);
    pcVar5 = (char *)FUN_100298a0(*piVar4);
    if (*pcVar5 != '\0') break;
    piVar4 = (int *)FUN_10028520((int)local_c);
    piVar6 = (int *)FUN_10028520((int)local_c);
    puVar3 = (undefined4 *)FUN_10028520(*piVar6);
    piVar6 = (int *)FUN_10028500(*puVar3);
    if (*piVar4 == *piVar6) {
      piVar4 = (int *)FUN_10028520((int)local_c);
      piVar4 = (int *)FUN_10028520(*piVar4);
      piVar4 = (int *)FUN_10028540(*piVar4);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_100298a0(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_10028520((int)local_c);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_100298a0(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028520(*piVar4);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10028520((int)local_c);
        puVar3 = (undefined4 *)FUN_10028520(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        piVar4 = (int *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028540(*piVar4);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_10028520((int)local_c);
          local_c = (void *)*piVar4;
          FUN_10029620(this,(int)local_c);
        }
        piVar4 = (int *)FUN_10028520((int)local_c);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028520(*piVar4);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028520(*piVar4);
        FUN_10029760(this,*piVar4);
      }
    }
    else {
      piVar4 = (int *)FUN_10028520((int)local_c);
      puVar3 = (undefined4 *)FUN_10028520(*piVar4);
      piVar4 = (int *)FUN_10028500(*puVar3);
      iVar1 = *piVar4;
      pcVar5 = (char *)FUN_100298a0(iVar1);
      if (*pcVar5 == '\0') {
        piVar4 = (int *)FUN_10028520((int)local_c);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 1;
        puVar7 = (undefined1 *)FUN_100298a0(iVar1);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028520(*piVar4);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10028520((int)local_c);
        puVar3 = (undefined4 *)FUN_10028520(*piVar4);
        local_c = (void *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028500(*puVar3);
        if (local_c == (void *)*piVar4) {
          piVar4 = (int *)FUN_10028520((int)local_c);
          local_c = (void *)*piVar4;
          FUN_10029760(this,(int)local_c);
        }
        piVar4 = (int *)FUN_10028520((int)local_c);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 1;
        piVar4 = (int *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028520(*piVar4);
        puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
        *puVar7 = 0;
        piVar4 = (int *)FUN_10028520((int)local_c);
        piVar4 = (int *)FUN_10028520(*piVar4);
        FUN_10029620(this,*piVar4);
      }
    }
  }
  piVar4 = (int *)FUN_100282e0((int)this);
  puVar7 = (undefined1 *)FUN_100298a0(*piVar4);
  *puVar7 = 1;
  FUN_100285b0(param_1,param_4);
  return param_1;
}



// Function: FUN_100295a0 at 100295a0

undefined4 * __fastcall FUN_100295a0(undefined4 *param_1)

{
  FUN_100298e0(param_1);
  return param_1;
}



// Function: FUN_100295c0 at 100295c0

int * __fastcall FUN_100295c0(int *param_1)

{
  FUN_10029900(param_1);
  return param_1;
}



// Function: FUN_100295e0 at 100295e0

int * __fastcall FUN_100295e0(int *param_1)

{
  FUN_100299c0(param_1);
  return param_1;
}



// Function: FUN_10029600 at 10029600

void FUN_10029600(void)

{
  FUN_10029b90();
  return;
}



// Function: FUN_10029620 at 10029620

void __thiscall FUN_10029620(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_10028540(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_10028500(iVar1);
  puVar4 = (undefined4 *)FUN_10028540(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10028500(iVar1);
  pcVar5 = (char *)FUN_100284e0(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_10028500(iVar1);
    piVar2 = (int *)FUN_10028520(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_10028520(param_1);
  puVar4 = (undefined4 *)FUN_10028520(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_100282e0((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_100282e0((int)this);
    *piVar2 = iVar1;
  }
  else {
    puVar3 = (undefined4 *)FUN_10028520(param_1);
    piVar2 = (int *)FUN_10028500(*puVar3);
    if (param_1 == *piVar2) {
      puVar3 = (undefined4 *)FUN_10028520(param_1);
      piVar2 = (int *)FUN_10028500(*puVar3);
      *piVar2 = iVar1;
    }
    else {
      piVar2 = (int *)FUN_10028520(param_1);
      piVar2 = (int *)FUN_10028540(*piVar2);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_10028500(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_10028520(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_10029760 at 10029760

void __thiscall FUN_10029760(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  piVar2 = (int *)FUN_10028500(param_1);
  iVar1 = *piVar2;
  puVar3 = (undefined4 *)FUN_10028540(iVar1);
  puVar4 = (undefined4 *)FUN_10028500(param_1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_10028540(iVar1);
  pcVar5 = (char *)FUN_100284e0(*piVar2);
  if (*pcVar5 == '\0') {
    piVar2 = (int *)FUN_10028540(iVar1);
    piVar2 = (int *)FUN_10028520(*piVar2);
    *piVar2 = param_1;
  }
  puVar3 = (undefined4 *)FUN_10028520(param_1);
  puVar4 = (undefined4 *)FUN_10028520(iVar1);
  *puVar4 = *puVar3;
  piVar2 = (int *)FUN_100282e0((int)this);
  if (param_1 == *piVar2) {
    piVar2 = (int *)FUN_100282e0((int)this);
    *piVar2 = iVar1;
  }
  else {
    piVar2 = (int *)FUN_10028520(param_1);
    piVar2 = (int *)FUN_10028540(*piVar2);
    if (param_1 == *piVar2) {
      piVar2 = (int *)FUN_10028520(param_1);
      piVar2 = (int *)FUN_10028540(*piVar2);
      *piVar2 = iVar1;
    }
    else {
      puVar3 = (undefined4 *)FUN_10028520(param_1);
      piVar2 = (int *)FUN_10028500(*puVar3);
      *piVar2 = iVar1;
    }
  }
  piVar2 = (int *)FUN_10028540(iVar1);
  *piVar2 = param_1;
  piVar2 = (int *)FUN_10028520(param_1);
  *piVar2 = iVar1;
  return;
}



// Function: FUN_100298a0 at 100298a0

int __cdecl FUN_100298a0(int param_1)

{
  return param_1 + 0x44;
}



// Function: FUN_100298c0 at 100298c0

int * __fastcall FUN_100298c0(int *param_1)

{
  FUN_100295e0(param_1);
  return param_1;
}



// Function: FUN_100298e0 at 100298e0

undefined4 * __fastcall FUN_100298e0(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



// Function: FUN_10029900 at 10029900

int * __fastcall FUN_10029900(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  pcVar1 = (char *)FUN_100284e0(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_10028540(*param_1);
    pcVar1 = (char *)FUN_100284e0(*piVar2);
    if (*pcVar1 == '\0') {
      puVar3 = (undefined4 *)FUN_10028540(*param_1);
      iVar4 = FUN_10029b40(*puVar3);
      *param_1 = iVar4;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_10028520(*param_1);
        iVar4 = *piVar2;
        pcVar1 = (char *)FUN_100284e0(iVar4);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_10028540(iVar4), *param_1 != *piVar2)) break;
        *param_1 = iVar4;
      }
      *param_1 = iVar4;
    }
  }
  return param_1;
}



// Function: FUN_100299c0 at 100299c0

int * __fastcall FUN_100299c0(int *param_1)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  
  pcVar1 = (char *)FUN_100284e0(*param_1);
  if (*pcVar1 == '\0') {
    piVar2 = (int *)FUN_10028500(*param_1);
    pcVar1 = (char *)FUN_100284e0(*piVar2);
    if (*pcVar1 == '\0') {
      piVar2 = (int *)FUN_10028500(*param_1);
      iVar3 = FUN_10029af0(*piVar2);
      *param_1 = iVar3;
    }
    else {
      while( true ) {
        piVar2 = (int *)FUN_10028520(*param_1);
        iVar3 = *piVar2;
        pcVar1 = (char *)FUN_100284e0(iVar3);
        if ((*pcVar1 != '\0') || (piVar2 = (int *)FUN_10028500(iVar3), *param_1 != *piVar2)) break;
        *param_1 = iVar3;
      }
      pcVar1 = (char *)FUN_100284e0(*param_1);
      if (*pcVar1 == '\0') {
        *param_1 = iVar3;
      }
    }
  }
  else {
    piVar2 = (int *)FUN_10028540(*param_1);
    *param_1 = *piVar2;
  }
  return param_1;
}



// Function: FUN_10029ab0 at 10029ab0

void * __thiscall FUN_10029ab0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_10013f60(param_2);
  uVar2 = FUN_10029ec0(param_1);
  FUN_10029bd0(this,uVar2,uVar1);
  return this;
}



// Function: FUN_10029af0 at 10029af0

int __cdecl FUN_10029af0(int param_1)

{
  int *piVar1;
  char *pcVar2;
  
  while( true ) {
    piVar1 = (int *)FUN_10028540(param_1);
    pcVar2 = (char *)FUN_100284e0(*piVar1);
    if (*pcVar2 != '\0') break;
    piVar1 = (int *)FUN_10028540(param_1);
    param_1 = *piVar1;
  }
  return param_1;
}



// Function: FUN_10029b40 at 10029b40

undefined4 __cdecl FUN_10029b40(undefined4 param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  while( true ) {
    piVar1 = (int *)FUN_10028500(param_1);
    pcVar2 = (char *)FUN_100284e0(*piVar1);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_10028500(param_1);
    param_1 = *puVar3;
  }
  return param_1;
}



// Function: FUN_10029b90 at 10029b90

/* WARNING: Removing unreachable block (ram,0x10029bb1) */

undefined4 FUN_10029b90(void)

{
  return 0x4924924;
}



// Function: FUN_10029bd0 at 10029bd0

undefined4 * __thiscall FUN_10029bd0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_10029ec0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_10013f60(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_10029c10 at 10029c10

void FUN_10029c10(void)

{
  FUN_10029f20((undefined4 *)&stack0x00000004);
  return;
}



// Function: FUN_10029c30 at 10029c30

void __cdecl FUN_10029c30(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  while ((local_8 = ((int)param_2 - (int)param_1) / 0x1c, 0x20 < local_8 && (0 < param_3))) {
    FUN_10029ff0(&local_10,param_1,param_2);
    param_3 = (param_3 / 2) / 2 + param_3 / 2;
    if (((int)local_10 - (int)param_1) / 0x1c < ((int)param_2 - (int)local_c) / 0x1c) {
      FUN_10029c30(param_1,local_10,param_3);
      param_1 = local_c;
    }
    else {
      FUN_10029c30(local_c,param_2,param_3);
      param_2 = local_10;
    }
  }
  if (local_8 < 0x21) {
    if (1 < local_8) {
      FUN_1002a350(param_1,param_2);
    }
  }
  else {
    FUN_1002a2b0((int)param_1,(int)param_2);
    FUN_1002a310(param_1,param_2);
  }
  return;
}



// Function: FUN_10029d30 at 10029d30

undefined4 __cdecl FUN_10029d30(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10029d50 at 10029d50

void __thiscall FUN_10029d50(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030f50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_10029f40((int)this);
  local_8 = 0;
  uVar2 = FUN_10029d30(param_1);
  iVar1 = FUN_10028560(iVar1);
  uVar3 = FUN_100287b0(iVar1);
  FUN_1002a380((int)this + 0xd,uVar3,uVar2);
  FUN_10029dec();
  return;
}



// Function: Catch@10029dc5 at 10029dc5

void Catch_10029dc5(void)

{
  int unaff_EBP;
  
  FUN_10028580(*(void **)(unaff_EBP + -0x18));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_10029dec at 10029dec

undefined4 FUN_10029dec(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}



// Function: FUN_10029e10 at 10029e10

void * __cdecl FUN_10029e10(int param_1,int param_2,void *param_3)

{
  undefined4 uVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 0x1c) {
    uVar1 = FUN_10016bf0(param_1);
    FUN_10015880(param_3,uVar1);
    param_3 = (void *)((int)param_3 + 0x1c);
  }
  return param_3;
}



// Function: FUN_10029e60 at 10029e60

void __cdecl FUN_10029e60(void *param_1)

{
  FUN_10029ee0(param_1,0);
  return;
}



// Function: FUN_10029e80 at 10029e80

void * __thiscall FUN_10029e80(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_100143d0(param_2);
  uVar2 = FUN_1002a3b0(param_1);
  FUN_1002a3d0(this,uVar2,uVar1);
  return this;
}



// Function: FUN_10029ec0 at 10029ec0

undefined4 __cdecl FUN_10029ec0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_10029ee0 at 10029ee0

void * __thiscall FUN_10029ee0(void *this,uint param_1)

{
  FUN_10028000(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_10029f20 at 10029f20

undefined4 __fastcall FUN_10029f20(undefined4 *param_1)

{
  return *param_1;
}



// Function: FUN_10029f40 at 10029f40

int __fastcall FUN_10029f40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_10029fc0(1);
  puVar2 = (undefined4 *)FUN_10028500(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_10028520(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)FUN_10028540(iVar1);
  *puVar2 = *(undefined4 *)(param_1 + 4);
  puVar3 = (undefined1 *)FUN_100298a0(iVar1);
  *puVar3 = 0;
  puVar3 = (undefined1 *)FUN_100284e0(iVar1);
  *puVar3 = 0;
  return iVar1;
}



// Function: FUN_10029fc0 at 10029fc0

void FUN_10029fc0(uint param_1)

{
  FUN_1002a410(param_1);
  return;
}



// Function: FUN_10029ff0 at 10029ff0

void * __cdecl FUN_10029ff0(void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = param_2 + (((int)param_3 - (int)param_2) / 0x38) * 7;
  FUN_1002a510(param_2,local_8,param_3 + -7);
  local_c = local_8;
  local_10 = local_8 + 7;
  while (((param_2 < local_c && (bVar2 = FUN_10011170(local_c + -7,local_c), !bVar2)) &&
         (bVar2 = FUN_10011170(local_c,local_c + -7), !bVar2))) {
    local_c = local_c + -7;
  }
  while (((local_10 < param_3 && (bVar2 = FUN_10011170(local_10,local_c), !bVar2)) &&
         (bVar2 = FUN_10011170(local_c,local_10), !bVar2))) {
    local_10 = local_10 + 7;
  }
  local_14 = local_10;
  local_18 = local_c;
  do {
    while (param_3 <= local_14) {
LAB_1002a142:
      for (; param_2 < local_18; local_18 = local_18 + -7) {
        bVar2 = FUN_10011170(local_18 + -7,local_c);
        if (!bVar2) {
          bVar2 = FUN_10011170(local_c,local_18 + -7);
          if (bVar2) break;
          local_c = local_c + -7;
          FUN_1002a600(local_c,local_18 + -7);
        }
      }
      if ((local_18 == param_2) && (local_14 == param_3)) {
        FUN_1002a620(param_1,&local_c,&local_10);
        return param_1;
      }
      if (local_18 == param_2) {
        if (local_10 != local_14) {
          FUN_1002a600(local_c,local_10);
        }
        puVar1 = local_c;
        local_10 = local_10 + 7;
        local_c = local_c + 7;
        FUN_1002a600(puVar1,local_14);
        local_14 = local_14 + 7;
      }
      else if (local_14 == param_3) {
        local_18 = local_18 + -7;
        local_c = local_c + -7;
        if (local_18 != local_c) {
          FUN_1002a600(local_18,local_c);
        }
        local_10 = local_10 + -7;
        FUN_1002a600(local_c,local_10);
      }
      else {
        local_18 = local_18 + -7;
        FUN_1002a600(local_14,local_18);
        local_14 = local_14 + 7;
      }
    }
    bVar2 = FUN_10011170(local_c,local_14);
    if (!bVar2) {
      bVar2 = FUN_10011170(local_14,local_c);
      puVar1 = local_10;
      if (bVar2) goto LAB_1002a142;
      local_10 = local_10 + 7;
      FUN_1002a600(puVar1,local_14);
    }
    local_14 = local_14 + 7;
  } while( true );
}



// Function: FUN_1002a2b0 at 1002a2b0

void __cdecl FUN_1002a2b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (1 < (param_2 - param_1) / 0x1c) {
    FUN_100142c0();
    FUN_1002a680();
    iVar1 = FUN_1002a660(param_2);
    iVar2 = FUN_1002a660(param_1);
    FUN_1002a6a0(iVar2,iVar1);
  }
  return;
}



// Function: FUN_1002a310 at 1002a310

void __cdecl FUN_1002a310(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_1002a660(param_2);
  iVar2 = FUN_1002a660(param_1);
  FUN_1002a770(iVar2,iVar1);
  return;
}



// Function: FUN_1002a350 at 1002a350

void __cdecl FUN_1002a350(undefined4 *param_1,undefined4 *param_2)

{
  FUN_100142c0();
  FUN_1002a7b0(param_1,param_2);
  return;
}



// Function: FUN_1002a380 at 1002a380

void __cdecl FUN_1002a380(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_10029d30(param_3);
  FUN_1002a480(param_2,uVar1);
  return;
}



// Function: FUN_1002a3b0 at 1002a3b0

undefined4 __cdecl FUN_1002a3b0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1002a3d0 at 1002a3d0

undefined4 * __thiscall FUN_1002a3d0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_1002a3b0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar2 = (undefined1 *)FUN_100143d0(param_2);
  *(undefined1 *)((int)this + 4) = *puVar2;
  return (undefined4 *)this;
}



// Function: FUN_1002a410 at 1002a410

void * __cdecl FUN_1002a410(uint param_1)

{
  exception local_54 [76];
  void *local_8;
  
  local_8 = (void *)0x0;
  if ((param_1 != 0) &&
     ((0x38e38e3 < param_1 || (local_8 = operator_new(param_1 * 0x48), local_8 == (void *)0x0)))) {
    FUN_1000aac0(local_54);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_1003d210);
  }
  return local_8;
}



// Function: FUN_1002a480 at 1002a480

void FUN_1002a480(undefined4 param_1,undefined4 param_2)

{
  void *this;
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030f81;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (void *)FUN_10014d20(0x38,param_1);
  local_8 = 0;
  if (this != (void *)0x0) {
    iVar1 = FUN_10029d30(param_2);
    FUN_1002a900(this,iVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1002a510 at 1002a510

void __cdecl FUN_1002a510(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  
  if (((int)param_3 - (int)param_1) / 0x1c < 0x29) {
    FUN_1002aa10(param_1,param_2,param_3);
  }
  else {
    iVar1 = ((int)param_3 - (int)param_1) / 0x1c + 1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    FUN_1002aa10(param_1,param_1 + iVar1 * 7,param_1 + iVar1 * 0xe);
    FUN_1002aa10(param_2 + iVar1 * -7,param_2,param_2 + iVar1 * 7);
    FUN_1002aa10((undefined4 *)((int)param_3 + iVar1 * -0x38),
                 (undefined4 *)((int)param_3 + iVar1 * -0x1c),param_3);
    FUN_1002aa10(param_1 + iVar1 * 7,param_2,(void *)((int)param_3 + iVar1 * -0x1c));
  }
  return;
}



// Function: FUN_1002a600 at 1002a600

void __cdecl FUN_1002a600(void *param_1,undefined4 *param_2)

{
  FUN_1002aaa0(param_1,param_2);
  return;
}



// Function: FUN_1002a620 at 1002a620

void * __thiscall FUN_1002a620(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_1002aac0(param_2);
  uVar2 = FUN_1002aac0(param_1);
  FUN_1002aae0(this,uVar2,uVar1);
  return this;
}



// Function: FUN_1002a660 at 1002a660

undefined4 __cdecl FUN_1002a660(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1002a680 at 1002a680

undefined4 FUN_1002a680(void)

{
  return 0;
}



// Function: FUN_1002a6a0 at 1002a6a0

void __cdecl FUN_1002a6a0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_38 [28];
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030fa8;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (param_2 - param_1) / 0x1c;
  local_1c = local_18 / 2;
  while (0 < local_1c) {
    local_1c = local_1c + -1;
    iVar1 = FUN_1002ab20(local_1c * 0x1c + param_1);
    FUN_100157f0(local_38,iVar1);
    local_8 = 0;
    uVar2 = FUN_1002ab20(local_38);
    FUN_1002ab40(param_1,local_1c,local_18,uVar2);
    local_8 = 0xffffffff;
    FUN_1000aca0(local_38);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1002a770 at 1002a770

void __cdecl FUN_1002a770(int param_1,int param_2)

{
  for (; 1 < (param_2 - param_1) / 0x1c; param_2 = param_2 + -0x1c) {
    FUN_1002ac30(param_1,param_2);
  }
  return;
}



// Function: FUN_1002a7b0 at 1002a7b0

void __cdecl FUN_1002a7b0(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_38 [28];
  undefined4 *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10030fd8;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != param_2) {
    local_18 = param_1;
    while (local_18 = local_18 + 7, local_18 != param_2) {
      local_1c = local_18;
      iVar2 = FUN_1002ab20(local_18);
      FUN_100157f0(local_38,iVar2);
      local_8 = 0;
      bVar1 = FUN_10011170(local_38,param_1);
      if (bVar1) {
        local_1c = local_1c + 7;
        FUN_1002ac70((int)param_1,(int)local_18,local_1c);
        uVar3 = FUN_1002ab20(local_38);
        FUN_10015880(param_1,uVar3);
      }
      else {
        while( true ) {
          puVar4 = local_1c + -7;
          bVar1 = FUN_10011170(local_38,puVar4);
          if (!bVar1) break;
          uVar3 = FUN_1002ab20(puVar4);
          FUN_10015880(local_1c,uVar3);
          local_1c = puVar4;
        }
        uVar3 = FUN_1002ab20(local_38);
        FUN_10015880(local_1c,uVar3);
      }
      local_8 = 0xffffffff;
      FUN_1000aca0(local_38);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1002a900 at 1002a900

void * __thiscall FUN_1002a900(void *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10031008;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_100168a0(param_1 + 0x1c);
  uVar2 = FUN_10014b30(param_1);
  FUN_1002a980(this,uVar2,uVar1);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1002a980 at 1002a980

void * __thiscall FUN_1002a980(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10031043;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_10014b90(param_1);
  FUN_100156f0(this,puVar1);
  local_8 = 0;
  iVar2 = FUN_10016bf0(param_2);
  FUN_100157f0((void *)((int)this + 0x1c),iVar2);
  ExceptionList = local_10;
  return this;
}



// Function: FUN_1002aa10 at 1002aa10

void __cdecl FUN_1002aa10(undefined4 *param_1,undefined4 *param_2,void *param_3)

{
  bool bVar1;
  
  bVar1 = FUN_10011170(param_2,param_1);
  if (bVar1) {
    FUN_1002a600(param_2,param_1);
  }
  bVar1 = FUN_10011170(param_3,param_2);
  if (bVar1) {
    FUN_1002a600(param_3,param_2);
  }
  bVar1 = FUN_10011170(param_2,param_1);
  if (bVar1) {
    FUN_1002a600(param_2,param_1);
  }
  return;
}



// Function: FUN_1002aaa0 at 1002aaa0

void __cdecl FUN_1002aaa0(void *param_1,undefined4 *param_2)

{
  FUN_1002aea0(param_1,param_2);
  return;
}



// Function: FUN_1002aac0 at 1002aac0

undefined4 __cdecl FUN_1002aac0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1002aae0 at 1002aae0

undefined4 * __thiscall FUN_1002aae0(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_1002aac0(param_1);
  *(undefined4 *)this = *puVar1;
  puVar1 = (undefined4 *)FUN_1002aac0(param_2);
  *(undefined4 *)((int)this + 4) = *puVar1;
  return (undefined4 *)this;
}



// Function: FUN_1002ab20 at 1002ab20

undefined4 __cdecl FUN_1002ab20(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1002ab40 at 1002ab40

void __cdecl FUN_1002ab40(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 local_c;
  
  iVar2 = param_2;
  iVar1 = param_2 * 2;
  while (local_c = iVar1 + 2, local_c < param_3) {
    bVar3 = FUN_10011170((void *)(local_c * 0x1c + param_1),
                         (undefined4 *)((iVar1 + 1) * 0x1c + param_1));
    if (bVar3) {
      local_c = iVar1 + 1;
    }
    uVar4 = FUN_1002ab20(local_c * 0x1c + param_1);
    FUN_10015880((void *)(param_2 * 0x1c + param_1),uVar4);
    param_2 = local_c;
    iVar1 = local_c * 2;
  }
  if (local_c == param_3) {
    uVar4 = FUN_1002ab20((param_3 + -1) * 0x1c + param_1);
    FUN_10015880((void *)(param_2 * 0x1c + param_1),uVar4);
    param_2 = param_3 + -1;
  }
  puVar5 = (undefined4 *)FUN_1002ab20(param_4);
  FUN_1002acb0(param_1,param_2,iVar2,puVar5);
  return;
}



// Function: FUN_1002ac30 at 1002ac30

void __cdecl FUN_1002ac30(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_100142c0();
  iVar1 = FUN_1002a660(param_2);
  iVar2 = FUN_1002a660(param_1);
  FUN_1002ad50(iVar2,iVar1);
  return;
}



// Function: FUN_1002ac70 at 1002ac70

void __cdecl FUN_1002ac70(int param_1,int param_2,void *param_3)

{
  FUN_10013e20();
  FUN_1002ae00(param_1,param_2,param_3);
  return;
}



// Function: FUN_1002acb0 at 1002acb0

void __cdecl FUN_1002acb0(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  iVar2 = param_2 + -1;
  while (local_8 = iVar2 / 2, param_3 < param_2) {
    bVar1 = FUN_10011170((void *)(local_8 * 0x1c + param_1),param_4);
    if (!bVar1) break;
    uVar3 = FUN_1002ab20(local_8 * 0x1c + param_1);
    FUN_10015880((void *)(param_2 * 0x1c + param_1),uVar3);
    iVar2 = local_8 + -1;
    param_2 = local_8;
  }
  uVar3 = FUN_1002ab20(param_4);
  FUN_10015880((void *)(param_2 * 0x1c + param_1),uVar3);
  return;
}



// Function: FUN_1002ad50 at 1002ad50

void __cdecl FUN_1002ad50(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10031068;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = FUN_1002ab20(param_2 + -0x1c);
  FUN_100157f0(local_30,iVar1);
  local_8 = 0;
  FUN_1002a680();
  uVar2 = FUN_1002ab20(local_30);
  FUN_1002ae50(param_1,param_2 + -0x1c,(void *)(param_2 + -0x1c),uVar2);
  local_8 = 0xffffffff;
  FUN_1000aca0(local_30);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1002ae00 at 1002ae00

void * __cdecl FUN_1002ae00(int param_1,int param_2,void *param_3)

{
  undefined4 uVar1;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x1c;
    param_3 = (void *)((int)param_3 + -0x1c);
    uVar1 = FUN_10016bf0(param_2);
    FUN_10015880(param_3,uVar1);
  }
  return param_3;
}



// Function: FUN_1002ae50 at 1002ae50

void __cdecl FUN_1002ae50(int param_1,int param_2,void *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1002ab20(param_1);
  FUN_10015880(param_3,uVar1);
  uVar1 = FUN_1002ab20(param_4);
  FUN_1002ab40(param_1,0,(param_2 - param_1) / 0x1c,uVar1);
  return;
}



// Function: FUN_1002aea0 at 1002aea0

void __thiscall FUN_1002aea0(void *this,undefined4 *param_1)

{
  char cVar1;
  undefined4 local_34 [7];
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10031098;
  local_10 = ExceptionList;
  local_14 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (undefined4 *)this;
  if ((undefined4 *)this != param_1) {
    cVar1 = FUN_100168f0();
    if (cVar1 == '\0') {
      FUN_100156f0(local_34,local_18);
      local_8 = 0;
      FUN_100158b0(local_18,param_1);
      FUN_100158b0(param_1,local_34);
      local_8 = 0xffffffff;
      FUN_1000aca0(local_34);
    }
    else {
      FUN_1002af90(local_18,param_1);
      FUN_1002b030(local_18 + 4,param_1 + 4);
      FUN_1002b030(local_18 + 5,param_1 + 5);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1002af90 at 1002af90

void __cdecl FUN_1002af90(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_10043b78 ^ (uint)&stack0xfffffffc;
  puVar1 = (undefined4 *)FUN_1002b080(param_1);
  local_18 = *puVar1;
  local_14 = puVar1[1];
  local_10 = puVar1[2];
  local_c = puVar1[3];
  puVar1 = (undefined4 *)FUN_1002b080(param_2);
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  param_1[3] = puVar1[3];
  puVar1 = (undefined4 *)FUN_1002b080(&local_18);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  param_2[3] = puVar1[3];
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1002b030 at 1002b030

void __cdecl FUN_1002b030(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 local_8;
  
  puVar1 = (undefined4 *)FUN_1002b0a0(param_1);
  local_8 = *puVar1;
  puVar1 = (undefined4 *)FUN_1002b0a0(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined4 *)FUN_1002b0a0(&local_8);
  *param_2 = *puVar1;
  return;
}



// Function: FUN_1002b080 at 1002b080

undefined4 __cdecl FUN_1002b080(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1002b0a0 at 1002b0a0

undefined4 __cdecl FUN_1002b0a0(undefined4 param_1)

{
  return param_1;
}



// Function: FUN_1002b0c0 at 1002b0c0

undefined4 * __fastcall FUN_1002b0c0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100310db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1002b160(param_1);
  local_8._0_1_ = 1;
  *param_1 = CCriticalSection::vftable;
  FUN_10015780(param_1 + 7);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_100158b0(param_1 + 7,(undefined4 *)&stack0x00000004);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_1000aca0(&stack0x00000004);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1002b160 at 1002b160

undefined4 * __fastcall FUN_1002b160(undefined4 *param_1)

{
  *param_1 = CSyncObjectBase::vftable;
  return param_1;
}



// Function: FUN_1002b180 at 1002b180

void __fastcall FUN_1002b180(undefined4 *param_1)

{
  *param_1 = CSyncObjectBase::vftable;
  return;
}



// Function: FUN_1002b1a0 at 1002b1a0

undefined4 * __thiscall FUN_1002b1a0(void *this,uint param_1)

{
  FUN_1002b1e0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1002b1e0 at 1002b1e0

void __fastcall FUN_1002b1e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10031113;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CCriticalSection::vftable;
  local_8 = 1;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  local_8 = local_8 & 0xffffff00;
  FUN_1000aca0(param_1 + 7);
  local_8 = 0xffffffff;
  FUN_1002b180(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1002b260 at 1002b260

void __fastcall FUN_1002b260(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1002b280 at 1002b280

void __fastcall FUN_1002b280(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return;
}



// Function: FUN_1002b2a0 at 1002b2a0

undefined4 * __thiscall FUN_1002b2a0(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**this + 4))();
  *(undefined1 *)((int)this + 4) = 1;
  return (undefined4 *)this;
}



// Function: FUN_1002b2e0 at 1002b2e0

void __fastcall FUN_1002b2e0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    (**(code **)(*(int *)*param_1 + 8))();
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_1002b320 at 1002b320

void __fastcall FUN_1002b320(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
    (**(code **)(*(int *)*param_1 + 8))();
  }
  return;
}



// Function: FUN_1002b360 at 1002b360

void __fastcall FUN_1002b360(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) == '\0') {
    (**(code **)(*(int *)*param_1 + 4))();
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}



// Function: FUN_1002b579 at 1002b579

void __thiscall FUN_1002b579(void *this,undefined4 *param_1)

{
  *(undefined4 *)this = *param_1;
  return;
}



// Function: FUN_1002b58b at 1002b58b

undefined4 __cdecl FUN_1002b58b(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



// Function: FUN_1002b595 at 1002b595

void __fastcall FUN_1002b595(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: memmove_s at 1002b5b4

/* Library Function - Single Match
    void __cdecl ATL::Checked::memmove_s(void *,unsigned int,void const *,unsigned int)
   
   Library: Visual Studio 2010 Release */

void __cdecl ATL::Checked::memmove_s(void *param_1,uint param_2,void *param_3,uint param_4)

{
  errno_t eVar1;
  
  eVar1 = ::memmove_s(param_1,param_2,param_3,param_4);
  FUN_10003150(eVar1);
  return;
}



// Function: RemoveAt at 1002b5d5

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::RemoveAt(int)
   
   Library: Visual Studio 2010 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
RemoveAt(CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
         *this,int param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1 < 0) || (iVar3 = *(int *)(this + 4), iVar3 <= param_1)) {
    iVar3 = 0;
  }
  else {
    if (param_1 != iVar3 + -1) {
      uVar2 = (iVar3 - param_1) * 4;
      pvVar1 = (void *)(*(int *)this + param_1 * 4);
      Checked::memmove_s(pvVar1,uVar2,(void *)((int)pvVar1 + 4),uVar2 - 4);
    }
    *(int *)(this + 4) = *(int *)(this + 4) + -1;
    iVar3 = 1;
  }
  return iVar3;
}



// Function: FUN_1002b61d at 1002b61d

int __thiscall FUN_1002b61d(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 4))) {
                    /* WARNING: Load size is inaccurate */
    return *this + param_1 * 4;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}



// Function: FUN_1002b649 at 1002b649

void __thiscall FUN_1002b649(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
                    /* WARNING: Load size is inaccurate */
  puVar1 = (undefined4 *)(*this + param_1 * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
  }
  return;
}



// Function: FUN_1002b66a at 1002b66a

int __fastcall FUN_1002b66a(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_1002b697 at 1002b697

void __fastcall FUN_1002b697(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_1002b595((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: RemoveResourceInstance at 1002b6af

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::RemoveResourceInstance(struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

bool __thiscall
ATL::CAtlBaseModule::RemoveResourceInstance(CAtlBaseModule *this,HINSTANCE__ *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(this + 0x14);
  EnterCriticalSection(lpCriticalSection);
  iVar3 = 0;
  if (0 < *(int *)(this + 0x30)) {
    do {
      if ((iVar3 < 0) || (*(int *)(this + 0x30) <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return (bool)uVar2;
      }
      if (*(HINSTANCE__ **)(*(int *)(this + 0x2c) + iVar3 * 4) == param_1) {
        CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::
        RemoveAt((CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
                  *)(this + 0x2c),iVar3);
        LeaveCriticalSection(lpCriticalSection);
        return true;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 0x30));
  }
  LeaveCriticalSection(lpCriticalSection);
  return false;
}



// Function: GetHInstanceAt at 1002b718

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
LAB_1002b766:
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
        goto LAB_1002b766;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: Add at 1002b775

/* Library Function - Single Match
    public: int __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class
   ATL::CSimpleArrayEqualHelper<struct HINSTANCE__ *> >::Add(struct HINSTANCE__ * const &)
   
   Library: Visual Studio 2010 Release */

int __thiscall
ATL::CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>::Add
          (CSimpleArray<struct_HINSTANCE__*,class_ATL::CSimpleArrayEqualHelper<struct_HINSTANCE__*>_>
           *this,HINSTANCE__ **param_1)

{
  undefined4 *puVar1;
  int iVar2;
  HINSTANCE__ **ppHVar3;
  void *pvVar4;
  int iVar5;
  int extraout_ECX;
  uint _Count;
  undefined8 uVar6;
  
  iVar5 = *(int *)(this + 4);
  iVar2 = *(int *)(this + 8);
  if (iVar5 == iVar2) {
    ppHVar3 = *(HINSTANCE__ ***)this;
    uVar6 = CONCAT44(ppHVar3,iVar2);
    if ((ppHVar3 <= param_1) && (uVar6 = CONCAT44(ppHVar3,iVar2), param_1 < ppHVar3 + iVar2)) {
      uVar6 = FUN_10003210(0x80004005);
      iVar5 = extraout_ECX;
    }
    if ((int)uVar6 == 0) {
      _Count = 1;
LAB_1002b7bb:
      pvVar4 = _recalloc((void *)((ulonglong)uVar6 >> 0x20),_Count,4);
      if (pvVar4 != (void *)0x0) {
        *(uint *)(this + 8) = _Count;
        *(void **)this = pvVar4;
        goto LAB_1002b7d0;
      }
    }
    else {
      _Count = iVar5 * 2;
      if ((-1 < (int)_Count) && (_Count < 0x20000000)) goto LAB_1002b7bb;
    }
    iVar5 = 0;
  }
  else {
LAB_1002b7d0:
    puVar1 = (undefined4 *)(*(int *)this + *(int *)(this + 4) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *param_1;
    }
    *(int *)(this + 4) = *(int *)(this + 4) + 1;
    iVar5 = 1;
  }
  return iVar5;
}



// Function: FUN_1002b7f1 at 1002b7f1

undefined4 * __fastcall FUN_1002b7f1(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1002b66a((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_1003ad38;
  uVar1 = FUN_10002480((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_10043ba8 = 1;
  }
  return param_1;
}



// Function: AddResourceInstance at 1002b831

/* Library Function - Single Match
    public: bool __thiscall ATL::CAtlBaseModule::AddResourceInstance(struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

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



// Function: FUN_1002b866 at 1002b866

void __fastcall FUN_1002b866(int *param_1)

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



// Function: FUN_1002b8aa at 1002b8aa

int __fastcall FUN_1002b8aa(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_1002b8c4 at 1002b8c4

undefined4 * __fastcall FUN_1002b8c4(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1002b8aa((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &PTR_PTR_10040690;
  param_1[3] = &DAT_10040694;
  uVar1 = FUN_10002480((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_10043ba8 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_1002b90a at 1002b90a

void __thiscall FUN_1002b90a(void *this,undefined4 param_1)

{
  *(undefined ***)this = &PTR_FUN_1003ad48;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined1 *)((int)this + 8) = 0;
  return;
}



// Function: ~CWin32Heap at 1002b925

/* Library Function - Single Match
    public: virtual __thiscall ATL::CWin32Heap::~CWin32Heap(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __thiscall ATL::CWin32Heap::~CWin32Heap(CWin32Heap *this)

{
  *(undefined ***)this = &PTR_FUN_1003ad48;
  if ((this[8] != (CWin32Heap)0x0) && (*(HANDLE *)(this + 4) != (HANDLE)0x0)) {
    HeapDestroy(*(HANDLE *)(this + 4));
  }
  return;
}



// Function: FUN_1002b940 at 1002b940

void __thiscall FUN_1002b940(void *this,SIZE_T param_1)

{
  HeapAlloc(*(HANDLE *)((int)this + 4),0,param_1);
  return;
}



// Function: FUN_1002b957 at 1002b957

void __thiscall FUN_1002b957(void *this,LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    HeapFree(*(HANDLE *)((int)this + 4),0,param_1);
  }
  return;
}



// Function: Reallocate at 1002b974

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



// Function: FUN_1002b9ae at 1002b9ae

void __thiscall FUN_1002b9ae(void *this,LPCVOID param_1)

{
  HeapSize(*(HANDLE *)((int)this + 4),0,param_1);
  return;
}



// Function: `scalar_deleting_destructor' at 1002b9c5

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



// Function: FUN_1002ba02 at 1002ba02

void __thiscall FUN_1002ba02(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  return;
}



// Function: CAtlStringMgr at 1002ba10

/* Library Function - Single Match
    public: __thiscall ATL::CAtlStringMgr::CAtlStringMgr(struct ATL::IAtlMemMgr *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __thiscall ATL::CAtlStringMgr::CAtlStringMgr(CAtlStringMgr *this,IAtlMemMgr *param_1)

{
  *(IAtlMemMgr **)(this + 4) = param_1;
  *(undefined ***)this = &PTR_Allocate_1003ad5c;
  *(undefined4 *)(this + 0x14) = 2;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x1a) = 0;
  *(CAtlStringMgr **)(this + 8) = this;
  return;
}



// Function: FUN_1002ba48 at 1002ba48

void __fastcall FUN_1002ba48(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1002ba53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 4) + 4))();
  return;
}



// Function: FUN_1002ba67 at 1002ba67

undefined4 * __thiscall FUN_1002ba67(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_Allocate_1003ad5c;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: AtlAdd<unsigned_int> at 1002ba89

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



// Function: FUN_1002baaf at 1002baaf

uint FUN_1002baaf(int param_1,int param_2)

{
  return param_1 + -1 + param_2 & ~(param_2 - 1U);
}



// Function: Allocate at 1002bac7

/* Library Function - Single Match
    public: virtual struct ATL::CStringData * __thiscall ATL::CAtlStringMgr::Allocate(int,int)
   
   Library: Visual Studio 2010 Release */

CStringData * __thiscall ATL::CAtlStringMgr::Allocate(CAtlStringMgr *this,int param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  CStringData *pCVar3;
  uint uVar4;
  
  uVar4 = param_1 + 8U & 0xfffffff8;
  uVar1 = FUN_10009df0(&param_1,uVar4,param_2);
  if (((-1 < (int)uVar1) &&
      (lVar2 = AtlAdd<unsigned_int>((uint *)&param_1,0x10,param_1), -1 < lVar2)) &&
     (pCVar3 = (CStringData *)(**(code **)**(undefined4 **)(this + 4))(param_1),
     pCVar3 != (CStringData *)0x0)) {
    *(undefined4 *)(pCVar3 + 4) = 0;
    *(CAtlStringMgr **)pCVar3 = this;
    *(undefined4 *)(pCVar3 + 0xc) = 1;
    *(uint *)(pCVar3 + 8) = uVar4 - 1;
    return pCVar3;
  }
  return (CStringData *)0x0;
}



// Function: Reallocate at 1002bb2b

/* Library Function - Single Match
    public: virtual struct ATL::CStringData * __thiscall ATL::CAtlStringMgr::Reallocate(struct
   ATL::CStringData *,int,int)
   
   Library: Visual Studio 2010 Release */

CStringData * __thiscall
ATL::CAtlStringMgr::Reallocate(CAtlStringMgr *this,CStringData *param_1,int param_2,int param_3)

{
  uint uVar1;
  CStringData *pCVar2;
  uint uVar3;
  
  uVar3 = param_2 + 8U & 0xfffffff8;
  uVar1 = FUN_10004140(&param_2,uVar3,param_3);
  if (((-1 < (int)uVar1) && (uVar1 = FUN_100273c0(&param_2,0x10,param_2), -1 < (int)uVar1)) &&
     (pCVar2 = (CStringData *)(**(code **)(**(int **)(this + 4) + 8))(param_1,param_2),
     pCVar2 != (CStringData *)0x0)) {
    *(uint *)(pCVar2 + 8) = uVar3 - 1;
    return pCVar2;
  }
  return (CStringData *)0x0;
}



// Function: FUN_1002bb86 at 1002bb86

void FUN_1002bb86(uint param_1)

{
  operator_new(param_1);
  return;
}



// Function: ~_Fac_node at 1002bcce

/* Library Function - Single Match
    public: __thiscall std::_Fac_node::~_Fac_node(void)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __thiscall std::_Fac_node::~_Fac_node(_Fac_node *this)

{
  facet *pfVar1;
  
  pfVar1 = std::locale::facet::_Decref(*(facet **)(this + 4));
  if (pfVar1 != (facet *)0x0) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: `scalar_deleting_destructor' at 1002bce4

/* Library Function - Single Match
    public: void * __thiscall std::_Fac_node::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void * __thiscall std::_Fac_node::_scalar_deleting_destructor_(_Fac_node *this,uint param_1)

{
  ~_Fac_node(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: Facet_Register at 1002bd05

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
    *puVar1 = DAT_10045910;
    puVar1[1] = param_1;
  }
  DAT_10045910 = puVar1;
  return;
}



// Function: FUN_1002bd7f at 1002bd7f

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_1002bd7f(void)

{
  _Fac_node *this;
  int unaff_EBP;
  
  FUN_1002c7c6(4);
  std::_Lockit::_Lockit((_Lockit *)(unaff_EBP + -0x10),0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (this = DAT_10045910, DAT_10045910 != (_Fac_node *)0x0) {
    DAT_10045910 = *(_Fac_node **)DAT_10045910;
    std::_Fac_node::~_Fac_node(this);
    operator_delete(this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: __security_check_cookie at 1002bf0e

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10043b78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: FID_conflict:`vector_deleting_destructor' at 1002bf28

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



// Function: __alloca_probe at 1002bfa0

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



// Function: __ArrayUnwind at 1002bffd

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



// Function: `eh_vector_destructor_iterator' at 1002c05b

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
  FUN_1002c0a6();
  return;
}



// Function: FUN_1002c0a6 at 1002c0a6

void FUN_1002c0a6(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: `eh_vector_constructor_iterator' at 1002c0be

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
  FUN_1002c10b();
  return;
}



// Function: FUN_1002c10b at 1002c10b

void FUN_1002c10b(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __onexit at 1002c136

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
  
  local_8 = &DAT_10040628;
  uStack_c = 0x1002c142;
  local_20[0] = DecodePointer(DAT_10045c60);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10045c60);
    local_24 = DecodePointer(DAT_10045c5c);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10045c60 = EncodePointer(local_20[0]);
    DAT_10045c5c = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_1002c1ce();
  }
  return p_Var1;
}



// Function: FUN_1002c1ce at 1002c1ce

void FUN_1002c1ce(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 1002c1d7

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __alloca_probe_16 at 1002c220

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



// Function: __alloca_probe_8 at 1002c236

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



// Function: FUN_1002c2d0 at 1002c2d0

ulonglong __fastcall FUN_1002c2d0(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float fVar3;
  float10 in_ST0;
  uint local_20;
  float fStack_1c;
  
  if (DAT_10045c54 == 0) {
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



// Function: __allmul at 1002c3b0

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



// Function: __CRT_INIT@12 at 1002c483

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
    if (DAT_10045918 < 1) {
      return 0;
    }
    DAT_10045918 = DAT_10045918 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10045c50,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10045c4c == 2) {
      param_2 = (int *)DecodePointer(DAT_10045c60);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10045c5c);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10045c60);
            piVar8 = (int *)DecodePointer(DAT_10045c5c);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10045c5c = (PVOID)encoded_null();
        DAT_10045c60 = DAT_10045c5c;
      }
      DAT_10045c4c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10045c50,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10045c50,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10045c4c == 0) {
      DAT_10045c4c = 1;
      iVar5 = initterm_e(&DAT_10036800,&DAT_1003680c);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10036458,&DAT_100367fc);
      DAT_10045c4c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10045c50,0);
    }
    if ((DAT_10045c58 != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_10045c58), BVar2 != 0)) {
      (*DAT_10045c58)(param_1,2,param_3);
    }
    DAT_10045918 = DAT_10045918 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 1002c68d

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1002c72d) */
/* WARNING: Removing unreachable block (ram,0x1002c6da) */
/* WARNING: Removing unreachable block (ram,0x1002c75a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,HMODULE param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10043ba0 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10045918 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(&param_3->unused,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_10001030(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_10001030(param_3,0);
      __CRT_INIT_12(&param_3->unused,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(&param_3->unused,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_1002c798();
  return local_20;
}



// Function: FUN_1002c798 at 1002c798

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002c798(void)

{
  _DAT_10043ba0 = 0xffffffff;
  return;
}



// Function: entry at 1002c7a3

void entry(HMODULE param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: FUN_1002c7c6 at 1002c7c6

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */

void __cdecl FUN_1002c7c6(int param_1)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10043b78 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 1002c89e

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



// Function: ___report_gsfailure at 1002c8d0

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
  
  _DAT_10045a38 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_10045a3c = &stack0x00000004;
  _DAT_10045978 = 0x10001;
  _DAT_10045920 = 0xc0000409;
  _DAT_10045924 = 1;
  local_32c = DAT_10043b78;
  local_328 = DAT_10043b7c;
  _DAT_1004592c = unaff_retaddr;
  _DAT_10045a04 = in_GS;
  _DAT_10045a08 = in_FS;
  _DAT_10045a0c = in_ES;
  _DAT_10045a10 = in_DS;
  _DAT_10045a14 = unaff_EDI;
  _DAT_10045a18 = unaff_ESI;
  _DAT_10045a1c = unaff_EBX;
  _DAT_10045a20 = in_EDX;
  _DAT_10045a24 = in_ECX;
  _DAT_10045a28 = in_EAX;
  _DAT_10045a2c = unaff_EBP;
  DAT_10045a30 = unaff_retaddr;
  _DAT_10045a34 = in_CS;
  _DAT_10045a40 = in_SS;
  DAT_10045970 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_1003ad80);
  if (DAT_10045970 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 1002c9e0

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10043b78 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 1002ca25

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



// Function: __ValidateImageBase at 1002cad0

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



// Function: __FindPESection at 1002cb10

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



// Function: __IsNonwritableInCurrentImage at 1002cb60

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
  
  puStack_10 = &LAB_1002c3ea;
  local_14 = ExceptionList;
  local_c = DAT_10043b78 ^ 0x10040670;
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



// Function: ___security_init_cookie at 1002cc34

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
  if ((DAT_10043b78 == 0xbb40e64e) || ((DAT_10043b78 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10043b78 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10043b78 == 0xbb40e64e) {
      DAT_10043b78 = 0xbb40e64f;
    }
    else if ((DAT_10043b78 & 0xffff0000) == 0) {
      DAT_10043b78 = DAT_10043b78 | (DAT_10043b78 | 0x4711) << 0x10;
    }
    DAT_10043b7c = ~DAT_10043b78;
  }
  else {
    DAT_10043b7c = ~DAT_10043b78;
  }
  return;
}



// Function: Unwind@1002cd70 at 1002cd70

void Unwind_1002cd70(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1002cda0 at 1002cda0

void Unwind_1002cda0(void)

{
  int unaff_EBP;
  
  FUN_10007220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002cdf0 at 1002cdf0

void Unwind_1002cdf0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1002ce20 at 1002ce20

void Unwind_1002ce20(void)

{
  int unaff_EBP;
  
  FUN_10007220(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ce50 at 1002ce50

void Unwind_1002ce50(void)

{
  int unaff_EBP;
  
  FUN_10009580(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1002ce80 at 1002ce80

void Unwind_1002ce80(void)

{
  FUN_10006d90();
  return;
}



// Function: Unwind@1002ce88 at 1002ce88

void Unwind_1002ce88(void)

{
  int unaff_EBP;
  
  FUN_100096a0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002ceb0 at 1002ceb0

void Unwind_1002ceb0(void)

{
  int unaff_EBP;
  
  FUN_100023c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002cee0 at 1002cee0

void Unwind_1002cee0(void)

{
  int unaff_EBP;
  
  FUN_1000bca0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002cf10 at 1002cf10

void Unwind_1002cf10(void)

{
  FUN_100070a0();
  return;
}



// Function: Unwind@1002cf1b at 1002cf1b

void Unwind_1002cf1b(void)

{
  int unaff_EBP;
  
  FUN_10002110(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1002cf50 at 1002cf50

void Unwind_1002cf50(void)

{
  int unaff_EBP;
  
  FUN_1000bca0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002cf80 at 1002cf80

void Unwind_1002cf80(void)

{
  FUN_100070a0();
  return;
}



// Function: Unwind@1002cf8b at 1002cf8b

void Unwind_1002cf8b(void)

{
  int unaff_EBP;
  
  FUN_10002110(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1002cfc0 at 1002cfc0

void Unwind_1002cfc0(void)

{
  FUN_10006d90();
  return;
}



// Function: Unwind@1002cff0 at 1002cff0

void Unwind_1002cff0(void)

{
  int unaff_EBP;
  
  FUN_1000bca0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d020 at 1002d020

void Unwind_1002d020(void)

{
  int unaff_EBP;
  
  FUN_1000bca0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d050 at 1002d050

void Unwind_1002d050(void)

{
  FUN_100023a0();
  return;
}



// Function: Unwind@1002d080 at 1002d080

void Unwind_1002d080(void)

{
  FUN_100023a0();
  return;
}



// Function: Unwind@1002d0b0 at 1002d0b0

void Unwind_1002d0b0(void)

{
  int unaff_EBP;
  
  FUN_10002bb0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002d0b8 at 1002d0b8

void Unwind_1002d0b8(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1002d0f0 at 1002d0f0

void Unwind_1002d0f0(void)

{
  int unaff_EBP;
  
  FUN_10002c20((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002d120 at 1002d120

void Unwind_1002d120(void)

{
  int unaff_EBP;
  
  FUN_10008db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d150 at 1002d150

void Unwind_1002d150(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d180 at 1002d180

void Unwind_1002d180(void)

{
  int unaff_EBP;
  
  FUN_10009000((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002d188 at 1002d188

void Unwind_1002d188(void)

{
  int unaff_EBP;
  
  FUN_10009000((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002d1b0 at 1002d1b0

void Unwind_1002d1b0(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d1e0 at 1002d1e0

void Unwind_1002d1e0(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002d1e8 at 1002d1e8

void Unwind_1002d1e8(void)

{
  int unaff_EBP;
  
  FUN_100090a0((int *)(unaff_EBP + -0x450));
  return;
}



// Function: Unwind@1002d220 at 1002d220

void Unwind_1002d220(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d250 at 1002d250

void Unwind_1002d250(void)

{
  int unaff_EBP;
  
  FUN_10004190(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1002d280 at 1002d280

void Unwind_1002d280(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002d2b0 at 1002d2b0

void Unwind_1002d2b0(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d2b8 at 1002d2b8

void Unwind_1002d2b8(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x248));
  return;
}



// Function: Unwind@1002d2c3 at 1002d2c3

void Unwind_1002d2c3(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x2254));
  return;
}



// Function: Unwind@1002d2ce at 1002d2ce

void Unwind_1002d2ce(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x2260));
  return;
}



// Function: Unwind@1002d2d9 at 1002d2d9

void Unwind_1002d2d9(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x2270));
  return;
}



// Function: Unwind@1002d310 at 1002d310

void Unwind_1002d310(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d340 at 1002d340

void Unwind_1002d340(void)

{
  int unaff_EBP;
  
  FUN_10009140((int *)(unaff_EBP + -0x2130));
  return;
}



// Function: Unwind@1002d34b at 1002d34b

void Unwind_1002d34b(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x2154));
  return;
}



// Function: Unwind@1002d356 at 1002d356

void Unwind_1002d356(void)

{
  int unaff_EBP;
  
  FUN_100091e0((int *)(unaff_EBP + -0x2264));
  return;
}



// Function: Unwind@1002d390 at 1002d390

void Unwind_1002d390(void)

{
  DAT_10043bf8 = DAT_10043bf8 & 0xfffffffe;
  return;
}



// Function: Unwind@1002d3c0 at 1002d3c0

void Unwind_1002d3c0(void)

{
  int unaff_EBP;
  
  FUN_10002c20((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002d3f0 at 1002d3f0

void Unwind_1002d3f0(void)

{
  int unaff_EBP;
  
  FUN_10008db0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d420 at 1002d420

void Unwind_1002d420(void)

{
  int unaff_EBP;
  
  FUN_10009c10((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d450 at 1002d450

void Unwind_1002d450(void)

{
  int unaff_EBP;
  
  FUN_10006a10((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002d458 at 1002d458

void Unwind_1002d458(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0xc0));
  return;
}



// Function: Unwind@1002d463 at 1002d463

void Unwind_1002d463(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x1d0));
  return;
}



// Function: Unwind@1002d46e at 1002d46e

void Unwind_1002d46e(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x1dc));
  return;
}



// Function: Unwind@1002d4b0 at 1002d4b0

void Unwind_1002d4b0(void)

{
  int unaff_EBP;
  
  FUN_100092c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d4e0 at 1002d4e0

void Unwind_1002d4e0(void)

{
  int unaff_EBP;
  
  FUN_10009c10((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d510 at 1002d510

void Unwind_1002d510(void)

{
  FUN_10006d90();
  return;
}



// Function: Unwind@1002d540 at 1002d540

void Unwind_1002d540(void)

{
  int unaff_EBP;
  
  FUN_10009580(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1002d570 at 1002d570

void Unwind_1002d570(void)

{
  int unaff_EBP;
  
  FUN_10007720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d5a0 at 1002d5a0

void Unwind_1002d5a0(void)

{
  int unaff_EBP;
  
  FUN_10009c10((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002d5a8 at 1002d5a8

void Unwind_1002d5a8(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1002d5b3 at 1002d5b3

void Unwind_1002d5b3(void)

{
  int unaff_EBP;
  
  FUN_10007bd0((int *)(unaff_EBP + -0x24c));
  return;
}



// Function: Unwind@1002d5be at 1002d5be

void Unwind_1002d5be(void)

{
  int unaff_EBP;
  
  FUN_10007bd0((int *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@1002d5c9 at 1002d5c9

void Unwind_1002d5c9(void)

{
  int unaff_EBP;
  
  FUN_10008030((int *)(unaff_EBP + -0x254));
  return;
}



// Function: Unwind@1002d600 at 1002d600

void Unwind_1002d600(void)

{
  int unaff_EBP;
  
  FUN_10009c10((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002d630 at 1002d630

void Unwind_1002d630(void)

{
  int unaff_EBP;
  
  FUN_100094e0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d660 at 1002d660

void Unwind_1002d660(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1002d66b at 1002d66b

void Unwind_1002d66b(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002d690 at 1002d690

void Unwind_1002d690(void)

{
  int unaff_EBP;
  
  FUN_10007720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d6c0 at 1002d6c0

void Unwind_1002d6c0(void)

{
  int unaff_EBP;
  
  FUN_10009650(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d6f0 at 1002d6f0

void Unwind_1002d6f0(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002d6f8 at 1002d6f8

void Unwind_1002d6f8(void)

{
  int unaff_EBP;
  
  FUN_10008a20((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002d700 at 1002d700

void Unwind_1002d700(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@1002d740 at 1002d740

void Unwind_1002d740(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002d770 at 1002d770

void Unwind_1002d770(void)

{
  int unaff_EBP;
  
  FUN_10009390(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d7a0 at 1002d7a0

void Unwind_1002d7a0(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d7a8 at 1002d7a8

void Unwind_1002d7a8(void)

{
  int unaff_EBP;
  
  FUN_10008a20((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002d7d0 at 1002d7d0

void Unwind_1002d7d0(void)

{
  int unaff_EBP;
  
  FUN_100092c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d800 at 1002d800

void Unwind_1002d800(void)

{
  int unaff_EBP;
  
  FUN_10009390(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d830 at 1002d830

void Unwind_1002d830(void)

{
  int unaff_EBP;
  
  FUN_100094e0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d860 at 1002d860

void Unwind_1002d860(void)

{
  int unaff_EBP;
  
  FUN_100094e0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d890 at 1002d890

void Unwind_1002d890(void)

{
  FUN_10006d90();
  return;
}



// Function: Unwind@1002d898 at 1002d898

void Unwind_1002d898(void)

{
  int unaff_EBP;
  
  FUN_100096a0((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002d8c0 at 1002d8c0

void Unwind_1002d8c0(void)

{
  int unaff_EBP;
  
  FUN_10009650(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d8f0 at 1002d8f0

void Unwind_1002d8f0(void)

{
  int unaff_EBP;
  
  FUN_100023c0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d920 at 1002d920

void Unwind_1002d920(void)

{
  FUN_10009e60();
  return;
}



// Function: Unwind@1002d939 at 1002d939

void Unwind_1002d939(void)

{
  FUN_10009e60();
  return;
}



// Function: Unwind@1002d970 at 1002d970

void Unwind_1002d970(void)

{
  int unaff_EBP;
  
  FUN_10009f60((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002d978 at 1002d978

void Unwind_1002d978(void)

{
  int unaff_EBP;
  
  FUN_10009f60((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002d9a0 at 1002d9a0

void Unwind_1002d9a0(void)

{
  int unaff_EBP;
  
  FUN_1000a020(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002d9d0 at 1002d9d0

void Unwind_1002d9d0(void)

{
  int unaff_EBP;
  
  FUN_1000a020(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002da00 at 1002da00

void Unwind_1002da00(void)

{
  FUN_1000a680();
  return;
}



// Function: Unwind@1002da50 at 1002da50

void Unwind_1002da50(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002da53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002da80 at 1002da80

void Unwind_1002da80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002da83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002dab0 at 1002dab0

void Unwind_1002dab0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002dab3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002dae0 at 1002dae0

void Unwind_1002dae0(void)

{
  FUN_1000aca0(&DAT_10043c90);
  return;
}



// Function: Unwind@1002daea at 1002daea

void Unwind_1002daea(void)

{
  FUN_1000aca0(&DAT_10043cac);
  return;
}



// Function: Unwind@1002daf4 at 1002daf4

void Unwind_1002daf4(void)

{
  FUN_1000aca0(&DAT_10043cc8);
  return;
}



// Function: Unwind@1002dafe at 1002dafe

void Unwind_1002dafe(void)

{
  FUN_1000aca0(&DAT_10043ce4);
  return;
}



// Function: Unwind@1002db08 at 1002db08

void Unwind_1002db08(void)

{
  FUN_1000aca0(&DAT_10043d00);
  return;
}



// Function: Unwind@1002db12 at 1002db12

void Unwind_1002db12(void)

{
  FUN_1000aca0(&DAT_10043d1c);
  return;
}



// Function: Unwind@1002db1c at 1002db1c

void Unwind_1002db1c(void)

{
  FUN_1000aca0(&DAT_10043d38);
  return;
}



// Function: Unwind@1002db26 at 1002db26

void Unwind_1002db26(void)

{
  FUN_1000aca0(&DAT_10043d54);
  return;
}



// Function: Unwind@1002db30 at 1002db30

void Unwind_1002db30(void)

{
  FUN_1000aca0(&DAT_10043d70);
  return;
}



// Function: Unwind@1002db3a at 1002db3a

void Unwind_1002db3a(void)

{
  FUN_1000aca0(&DAT_10043d8c);
  return;
}



// Function: Unwind@1002db44 at 1002db44

void Unwind_1002db44(void)

{
  FUN_1000aca0(&DAT_10043da8);
  return;
}



// Function: Unwind@1002db4e at 1002db4e

void Unwind_1002db4e(void)

{
  FUN_1000aca0(&DAT_10043dc4);
  return;
}



// Function: Unwind@1002db58 at 1002db58

void Unwind_1002db58(void)

{
  FUN_1000aca0(&DAT_10043de0);
  return;
}



// Function: Unwind@1002db62 at 1002db62

void Unwind_1002db62(void)

{
  FUN_1000aca0(&DAT_10043dfc);
  return;
}



// Function: Unwind@1002db6c at 1002db6c

void Unwind_1002db6c(void)

{
  FUN_1000aca0(&DAT_10043e18);
  return;
}



// Function: Unwind@1002dba0 at 1002dba0

void Unwind_1002dba0(void)

{
  FUN_1000a680();
  return;
}



// Function: Unwind@1002dbd0 at 1002dbd0

void Unwind_1002dbd0(void)

{
  int unaff_EBP;
  
  FUN_1000af40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002dc00 at 1002dc00

void Unwind_1002dc00(void)

{
  int unaff_EBP;
  
  FUN_1000af40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002dc30 at 1002dc30

void Unwind_1002dc30(void)

{
  int unaff_EBP;
  
  FUN_1000afa0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002dc60 at 1002dc60

void Unwind_1002dc60(void)

{
  FUN_1000b000();
  return;
}



// Function: Unwind@1002dc90 at 1002dc90

void Unwind_1002dc90(void)

{
  FUN_100023a0();
  return;
}



// Function: Unwind@1002dcc0 at 1002dcc0

void Unwind_1002dcc0(void)

{
  int unaff_EBP;
  
  FUN_10002bb0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002dcc8 at 1002dcc8

void Unwind_1002dcc8(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1002dd00 at 1002dd00

void Unwind_1002dd00(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002dd30 at 1002dd30

void Unwind_1002dd30(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002dd60 at 1002dd60

void Unwind_1002dd60(void)

{
  int unaff_EBP;
  
  FUN_1000afa0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002dd90 at 1002dd90

void Unwind_1002dd90(void)

{
  FUN_1000b000();
  return;
}



// Function: Unwind@1002ddc0 at 1002ddc0

void Unwind_1002ddc0(void)

{
  FUN_100023a0();
  return;
}



// Function: Unwind@1002ddf0 at 1002ddf0

void Unwind_1002ddf0(void)

{
  FUN_100070a0();
  return;
}



// Function: Unwind@1002ddfb at 1002ddfb

void Unwind_1002ddfb(void)

{
  int unaff_EBP;
  
  FUN_10009f60((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1002de06 at 1002de06

void Unwind_1002de06(void)

{
  int unaff_EBP;
  
  FUN_10017ba0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1002de30 at 1002de30

void Unwind_1002de30(void)

{
  FUN_100070a0();
  return;
}



// Function: Unwind@1002de3b at 1002de3b

void Unwind_1002de3b(void)

{
  int unaff_EBP;
  
  FUN_10009f60((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1002de46 at 1002de46

void Unwind_1002de46(void)

{
  int unaff_EBP;
  
  FUN_10017ba0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1002de70 at 1002de70

void Unwind_1002de70(void)

{
  int unaff_EBP;
  
  FUN_10010e20((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002de78 at 1002de78

void Unwind_1002de78(void)

{
  int unaff_EBP;
  
  FUN_1000bf40((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1002de80 at 1002de80

void Unwind_1002de80(void)

{
  int unaff_EBP;
  
  FUN_1000bfa0((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002de88 at 1002de88

void Unwind_1002de88(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1002de93 at 1002de93

void Unwind_1002de93(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1002ded0 at 1002ded0

void Unwind_1002ded0(void)

{
  int unaff_EBP;
  
  FUN_1000dbe0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002df00 at 1002df00

void Unwind_1002df00(void)

{
  int unaff_EBP;
  
  FUN_1000dcc0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002df30 at 1002df30

void Unwind_1002df30(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002df38 at 1002df38

void Unwind_1002df38(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1002df70 at 1002df70

void Unwind_1002df70(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002df78 at 1002df78

void Unwind_1002df78(void)

{
  int unaff_EBP;
  
  FUN_1000c980((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1002df80 at 1002df80

void Unwind_1002df80(void)

{
  int unaff_EBP;
  
  FUN_10010e20((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1002df88 at 1002df88

void Unwind_1002df88(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1002df90 at 1002df90

void Unwind_1002df90(void)

{
  int unaff_EBP;
  
  FUN_1000e2f0((_Container_base0 *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1002df9b at 1002df9b

void Unwind_1002df9b(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x1c4));
  return;
}



// Function: Unwind@1002dfa6 at 1002dfa6

void Unwind_1002dfa6(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// Function: Unwind@1002dfb1 at 1002dfb1

void Unwind_1002dfb1(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1002dfbc at 1002dfbc

void Unwind_1002dfbc(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1002dfc7 at 1002dfc7

void Unwind_1002dfc7(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x1fc));
  return;
}



// Function: Unwind@1002dfd2 at 1002dfd2

void Unwind_1002dfd2(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x1f8));
  return;
}



// Function: Unwind@1002dfdd at 1002dfdd

void Unwind_1002dfdd(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -300));
  return;
}



// Function: Unwind@1002dfe8 at 1002dfe8

void Unwind_1002dfe8(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x130));
  return;
}



// Function: Unwind@1002dff3 at 1002dff3

void Unwind_1002dff3(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x134));
  return;
}



// Function: Unwind@1002dffe at 1002dffe

void Unwind_1002dffe(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x138));
  return;
}



// Function: Unwind@1002e009 at 1002e009

void Unwind_1002e009(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x13c));
  return;
}



// Function: Unwind@1002e014 at 1002e014

void Unwind_1002e014(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x1d8));
  return;
}



// Function: Unwind@1002e01f at 1002e01f

void Unwind_1002e01f(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x148));
  return;
}



// Function: Unwind@1002e02a at 1002e02a

void Unwind_1002e02a(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x1cc));
  return;
}



// Function: Unwind@1002e035 at 1002e035

void Unwind_1002e035(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x1c8));
  return;
}



// Function: Unwind@1002e040 at 1002e040

void Unwind_1002e040(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x1a4));
  return;
}



// Function: Unwind@1002e04b at 1002e04b

void Unwind_1002e04b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1a8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1a8) = *(uint *)(unaff_EBP + -0x1a8) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002e0a0 at 1002e0a0

void Unwind_1002e0a0(void)

{
  int unaff_EBP;
  
  FUN_1000dfd0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e0d0 at 1002e0d0

void Unwind_1002e0d0(void)

{
  int unaff_EBP;
  
  FUN_1000ca90((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002e100 at 1002e100

void Unwind_1002e100(void)

{
  int unaff_EBP;
  
  FUN_1000e400(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e130 at 1002e130

void Unwind_1002e130(void)

{
  int unaff_EBP;
  
  FUN_1000cbb0((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1002e160 at 1002e160

void Unwind_1002e160(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e190 at 1002e190

void Unwind_1002e190(void)

{
  int unaff_EBP;
  
  FUN_1000ce40((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1002e198 at 1002e198

void Unwind_1002e198(void)

{
  int unaff_EBP;
  
  FUN_1000cea0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002e1a0 at 1002e1a0

void Unwind_1002e1a0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1002e1a8 at 1002e1a8

void Unwind_1002e1a8(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1002e1b0 at 1002e1b0

void Unwind_1002e1b0(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1002e1f0 at 1002e1f0

void Unwind_1002e1f0(void)

{
  int unaff_EBP;
  
  FUN_1000e5b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e220 at 1002e220

void Unwind_1002e220(void)

{
  int unaff_EBP;
  
  FUN_1000e680(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e250 at 1002e250

void Unwind_1002e250(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002e258 at 1002e258

void Unwind_1002e258(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1002e260 at 1002e260

void Unwind_1002e260(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1002e268 at 1002e268

void Unwind_1002e268(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1f0) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1f0) = *(uint *)(unaff_EBP + -0x1f0) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002e287 at 1002e287

void Unwind_1002e287(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2b4));
  return;
}



// Function: Unwind@1002e292 at 1002e292

void Unwind_1002e292(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x298));
  return;
}



// Function: Unwind@1002e29d at 1002e29d

void Unwind_1002e29d(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x27c));
  return;
}



// Function: Unwind@1002e2a8 at 1002e2a8

void Unwind_1002e2a8(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@1002e2b3 at 1002e2b3

void Unwind_1002e2b3(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@1002e2be at 1002e2be

void Unwind_1002e2be(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1002e2c9 at 1002e2c9

void Unwind_1002e2c9(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x20c));
  return;
}



// Function: Unwind@1002e2d4 at 1002e2d4

void Unwind_1002e2d4(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x1ac));
  return;
}



// Function: Unwind@1002e310 at 1002e310

void Unwind_1002e310(void)

{
  int unaff_EBP;
  
  FUN_10010e20((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1002e318 at 1002e318

void Unwind_1002e318(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002e320 at 1002e320

void Unwind_1002e320(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1002e328 at 1002e328

void Unwind_1002e328(void)

{
  int unaff_EBP;
  
  FUN_1000ce40((int *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1002e330 at 1002e330

void Unwind_1002e330(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1002e33b at 1002e33b

void Unwind_1002e33b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x90) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x90) = *(uint *)(unaff_EBP + -0x90) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002e390 at 1002e390

void Unwind_1002e390(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002e398 at 1002e398

void Unwind_1002e398(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1002e3a0 at 1002e3a0

void Unwind_1002e3a0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1002e3d0 at 1002e3d0

void Unwind_1002e3d0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1002e3db at 1002e3db

void Unwind_1002e3db(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1002e3e3 at 1002e3e3

void Unwind_1002e3e3(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x7c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x7c) = *(uint *)(unaff_EBP + -0x7c) & 0xfffffffe;
    FUN_10007720(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002e430 at 1002e430

void Unwind_1002e430(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1002e438 at 1002e438

void Unwind_1002e438(void)

{
  int unaff_EBP;
  
  FUN_1000e700((void *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1002e470 at 1002e470

void Unwind_1002e470(void)

{
  int unaff_EBP;
  
  FUN_1000dbe0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e4a0 at 1002e4a0

void Unwind_1002e4a0(void)

{
  int unaff_EBP;
  
  FUN_1000dcc0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e4d0 at 1002e4d0

void Unwind_1002e4d0(void)

{
  int unaff_EBP;
  
  FUN_1000dfd0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e500 at 1002e500

void Unwind_1002e500(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1002e508 at 1002e508

void Unwind_1002e508(void)

{
  int unaff_EBP;
  
  FUN_1000e760(unaff_EBP + -0x6c);
  return;
}



// Function: Unwind@1002e530 at 1002e530

void Unwind_1002e530(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1002e538 at 1002e538

void Unwind_1002e538(void)

{
  int unaff_EBP;
  
  FUN_1000e7c0(unaff_EBP + -0x68);
  return;
}



// Function: Unwind@1002e560 at 1002e560

void Unwind_1002e560(void)

{
  int unaff_EBP;
  
  FUN_1000ec40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e590 at 1002e590

void Unwind_1002e590(void)

{
  FUN_1000ef50();
  return;
}



// Function: Unwind@1002e5c0 at 1002e5c0

void Unwind_1002e5c0(void)

{
  FUN_1000ef50();
  return;
}



// Function: Unwind@1002e5f0 at 1002e5f0

void Unwind_1002e5f0(void)

{
  int unaff_EBP;
  
  FUN_1000e400(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e620 at 1002e620

void Unwind_1002e620(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e650 at 1002e650

void Unwind_1002e650(void)

{
  int unaff_EBP;
  
  FUN_1000e5b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e680 at 1002e680

void Unwind_1002e680(void)

{
  int unaff_EBP;
  
  FUN_1000e680(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e6b0 at 1002e6b0

void Unwind_1002e6b0(void)

{
  int unaff_EBP;
  
  FUN_1000e820(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e6e0 at 1002e6e0

void Unwind_1002e6e0(void)

{
  int unaff_EBP;
  
  FUN_1000e890(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e710 at 1002e710

void Unwind_1002e710(void)

{
  int unaff_EBP;
  
  FUN_1000e8f0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e740 at 1002e740

void Unwind_1002e740(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e748 at 1002e748

void Unwind_1002e748(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1002e770 at 1002e770

void Unwind_1002e770(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002e7a0 at 1002e7a0

void Unwind_1002e7a0(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002e7d0 at 1002e7d0

void Unwind_1002e7d0(void)

{
  int unaff_EBP;
  
  FUN_1000e820(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e800 at 1002e800

void Unwind_1002e800(void)

{
  int unaff_EBP;
  
  FUN_1000ec40(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e830 at 1002e830

void Unwind_1002e830(void)

{
  int unaff_EBP;
  
  FUN_1000e8f0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e860 at 1002e860

void Unwind_1002e860(void)

{
  int unaff_EBP;
  
  FUN_1000e890(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e890 at 1002e890

void Unwind_1002e890(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002e898 at 1002e898

void Unwind_1002e898(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1002e8c0 at 1002e8c0

void Unwind_1002e8c0(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1002e910 at 1002e910

void Unwind_1002e910(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002e940 at 1002e940

void Unwind_1002e940(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002e970 at 1002e970

void Unwind_1002e970(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002e978 at 1002e978

void Unwind_1002e978(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x70) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x70) = *(uint *)(unaff_EBP + -0x70) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002e9c0 at 1002e9c0

void Unwind_1002e9c0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002ea00 at 1002ea00

void Unwind_1002ea00(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@1002ea30 at 1002ea30

void Unwind_1002ea30(void)

{
  int unaff_EBP;
  
  FUN_10014eb0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002eb00 at 1002eb00

void Unwind_1002eb00(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@1002eb30 at 1002eb30

void Unwind_1002eb30(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@1002eb60 at 1002eb60

void Unwind_1002eb60(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@1002eb90 at 1002eb90

void Unwind_1002eb90(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@1002ebc0 at 1002ebc0

void Unwind_1002ebc0(void)

{
  int unaff_EBP;
  
  FUN_1000e820(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ebf0 at 1002ebf0

void Unwind_1002ebf0(void)

{
  int unaff_EBP;
  
  FUN_1000e8f0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ec20 at 1002ec20

void Unwind_1002ec20(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ec28 at 1002ec28

void Unwind_1002ec28(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1002ec50 at 1002ec50

void Unwind_1002ec50(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002ec80 at 1002ec80

void Unwind_1002ec80(void)

{
  int unaff_EBP;
  
  FUN_1000e820(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ecb0 at 1002ecb0

void Unwind_1002ecb0(void)

{
  int unaff_EBP;
  
  FUN_1000e8f0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ece0 at 1002ece0

void Unwind_1002ece0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ece8 at 1002ece8

void Unwind_1002ece8(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1002ed10 at 1002ed10

void Unwind_1002ed10(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1002ed40 at 1002ed40

void Unwind_1002ed40(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1002ed70 at 1002ed70

void Unwind_1002ed70(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1002eda0 at 1002eda0

void Unwind_1002eda0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002eda8 at 1002eda8

void Unwind_1002eda8(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x188));
  return;
}



// Function: Unwind@1002edb3 at 1002edb3

void Unwind_1002edb3(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x16c));
  return;
}



// Function: Unwind@1002edbe at 1002edbe

void Unwind_1002edbe(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x150));
  return;
}



// Function: Unwind@1002edc9 at 1002edc9

void Unwind_1002edc9(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x134));
  return;
}



// Function: Unwind@1002edd4 at 1002edd4

void Unwind_1002edd4(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x118));
  return;
}



// Function: Unwind@1002eddf at 1002eddf

void Unwind_1002eddf(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1002ede7 at 1002ede7

void Unwind_1002ede7(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xfc));
  return;
}



// Function: Unwind@1002edf2 at 1002edf2

void Unwind_1002edf2(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xe0));
  return;
}



// Function: Unwind@1002edfd at 1002edfd

void Unwind_1002edfd(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1002ee08 at 1002ee08

void Unwind_1002ee08(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1002ee13 at 1002ee13

void Unwind_1002ee13(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18c) = *(uint *)(unaff_EBP + -0x18c) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002ee60 at 1002ee60

void Unwind_1002ee60(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002ee68 at 1002ee68

void Unwind_1002ee68(void)

{
  int unaff_EBP;
  
  FUN_10015460((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1002ee73 at 1002ee73

void Unwind_1002ee73(void)

{
  int unaff_EBP;
  
  FUN_10015460((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002ee7b at 1002ee7b

void Unwind_1002ee7b(void)

{
  int unaff_EBP;
  
  FUN_100155c0((int *)(unaff_EBP + -0xec));
  return;
}



// Function: Unwind@1002ee86 at 1002ee86

void Unwind_1002ee86(void)

{
  int unaff_EBP;
  
  FUN_100155c0((int *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1002ee91 at 1002ee91

void Unwind_1002ee91(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xa4));
  return;
}



// Function: Unwind@1002ee9c at 1002ee9c

void Unwind_1002ee9c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x7c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x7c) = *(uint *)(unaff_EBP + -0x7c) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002eee0 at 1002eee0

void Unwind_1002eee0(void)

{
  int unaff_EBP;
  
  FUN_100154c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ef10 at 1002ef10

void Unwind_1002ef10(void)

{
  int unaff_EBP;
  
  FUN_100154c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ef18 at 1002ef18

void Unwind_1002ef18(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1002ef40 at 1002ef40

void Unwind_1002ef40(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002ef80 at 1002ef80

void Unwind_1002ef80(void)

{
  FUN_1000a680();
  return;
}



// Function: Unwind@1002efb0 at 1002efb0

void Unwind_1002efb0(void)

{
  FUN_1000a680();
  return;
}



// Function: Unwind@1002efe0 at 1002efe0

void Unwind_1002efe0(void)

{
  FUN_1000a680();
  return;
}



// Function: Unwind@1002f010 at 1002f010

void Unwind_1002f010(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f050 at 1002f050

void Unwind_1002f050(void)

{
  int unaff_EBP;
  
  FUN_100154c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f080 at 1002f080

void Unwind_1002f080(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x58) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x58) = *(uint *)(unaff_EBP + -0x58) & 0xfffffffe;
    FUN_10015460(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f0c0 at 1002f0c0

void Unwind_1002f0c0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
    FUN_100155c0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f100 at 1002f100

void Unwind_1002f100(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f140 at 1002f140

void Unwind_1002f140(void)

{
  FUN_1000a680();
  return;
}



// Function: Unwind@1002f170 at 1002f170

void Unwind_1002f170(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
    FUN_100155c0(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f1b0 at 1002f1b0

void Unwind_1002f1b0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -100) & 1) != 0) {
    *(uint *)(unaff_EBP + -100) = *(uint *)(unaff_EBP + -100) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f1f0 at 1002f1f0

void Unwind_1002f1f0(void)

{
  FUN_1000a680();
  return;
}



// Function: Unwind@1002f220 at 1002f220

void Unwind_1002f220(void)

{
  int unaff_EBP;
  
  FUN_100154c0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f228 at 1002f228

void Unwind_1002f228(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1002f250 at 1002f250

void Unwind_1002f250(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f290 at 1002f290

void Unwind_1002f290(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002f298 at 1002f298

void Unwind_1002f298(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x70) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x70) = *(uint *)(unaff_EBP + -0x70) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f2e0 at 1002f2e0

void Unwind_1002f2e0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1002f310 at 1002f310

void Unwind_1002f310(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002f318 at 1002f318

void Unwind_1002f318(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x70) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x70) = *(uint *)(unaff_EBP + -0x70) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f360 at 1002f360

void Unwind_1002f360(void)

{
  FUN_1000aca0(&DAT_10043f68);
  return;
}



// Function: Unwind@1002f36a at 1002f36a

void Unwind_1002f36a(void)

{
  FUN_1000aca0(&DAT_10043f84);
  return;
}



// Function: Unwind@1002f374 at 1002f374

void Unwind_1002f374(void)

{
  FUN_1000aca0(&DAT_10043fa0);
  return;
}



// Function: Unwind@1002f37e at 1002f37e

void Unwind_1002f37e(void)

{
  FUN_1000aca0(&DAT_10043fbc);
  return;
}



// Function: Unwind@1002f388 at 1002f388

void Unwind_1002f388(void)

{
  FUN_1000aca0(&DAT_10043fd8);
  return;
}



// Function: Unwind@1002f392 at 1002f392

void Unwind_1002f392(void)

{
  FUN_1000aca0(&DAT_10043ff4);
  return;
}



// Function: Unwind@1002f39c at 1002f39c

void Unwind_1002f39c(void)

{
  FUN_1000aca0(&DAT_10044010);
  return;
}



// Function: Unwind@1002f3a6 at 1002f3a6

void Unwind_1002f3a6(void)

{
  FUN_1000aca0(&DAT_1004402c);
  return;
}



// Function: Unwind@1002f3b0 at 1002f3b0

void Unwind_1002f3b0(void)

{
  FUN_1000aca0(&DAT_10044048);
  return;
}



// Function: Unwind@1002f3ba at 1002f3ba

void Unwind_1002f3ba(void)

{
  FUN_1000aca0(&DAT_10044064);
  return;
}



// Function: Unwind@1002f3c4 at 1002f3c4

void Unwind_1002f3c4(void)

{
  FUN_1000aca0(&DAT_10044080);
  return;
}



// Function: Unwind@1002f3ce at 1002f3ce

void Unwind_1002f3ce(void)

{
  FUN_1000aca0(&DAT_1004409c);
  return;
}



// Function: Unwind@1002f3d8 at 1002f3d8

void Unwind_1002f3d8(void)

{
  FUN_1000aca0(&DAT_100440b8);
  return;
}



// Function: Unwind@1002f3e2 at 1002f3e2

void Unwind_1002f3e2(void)

{
  FUN_1000aca0(&DAT_100440d4);
  return;
}



// Function: Unwind@1002f3ec at 1002f3ec

void Unwind_1002f3ec(void)

{
  FUN_1000aca0(&DAT_100440f0);
  return;
}



// Function: Unwind@1002f420 at 1002f420

void Unwind_1002f420(void)

{
  int unaff_EBP;
  
  FUN_10016da0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f450 at 1002f450

void Unwind_1002f450(void)

{
  int unaff_EBP;
  
  FUN_10016ec0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f480 at 1002f480

void Unwind_1002f480(void)

{
  int unaff_EBP;
  
  FUN_10016ec0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f4b0 at 1002f4b0

void Unwind_1002f4b0(void)

{
  int unaff_EBP;
  
  FUN_10016da0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f4e0 at 1002f4e0

void Unwind_1002f4e0(void)

{
  int unaff_EBP;
  
  FUN_10017b70(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1002f4eb at 1002f4eb

void Unwind_1002f4eb(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0xc0));
  return;
}



// Function: Unwind@1002f4f9 at 1002f4f9

void Unwind_1002f4f9(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0xe0));
  return;
}



// Function: Unwind@1002f507 at 1002f507

void Unwind_1002f507(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1002f50f at 1002f50f

void Unwind_1002f50f(void)

{
  int unaff_EBP;
  
  FUN_1002b1e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xfc));
  return;
}



// Function: Unwind@1002f540 at 1002f540

void Unwind_1002f540(void)

{
  int unaff_EBP;
  
  FUN_10017b70(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1002f54b at 1002f54b

void Unwind_1002f54b(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0xc0));
  return;
}



// Function: Unwind@1002f559 at 1002f559

void Unwind_1002f559(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0xe0));
  return;
}



// Function: Unwind@1002f567 at 1002f567

void Unwind_1002f567(void)

{
  int unaff_EBP;
  
  FUN_1002b1e0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xfc));
  return;
}



// Function: Unwind@1002f590 at 1002f590

void Unwind_1002f590(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002f598 at 1002f598

void Unwind_1002f598(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xc4));
  return;
}



// Function: Unwind@1002f5a3 at 1002f5a3

void Unwind_1002f5a3(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1002f5ae at 1002f5ae

void Unwind_1002f5ae(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1002f5b9 at 1002f5b9

void Unwind_1002f5b9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -200) & 1) != 0) {
    *(uint *)(unaff_EBP + -200) = *(uint *)(unaff_EBP + -200) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f600 at 1002f600

void Unwind_1002f600(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1002f608 at 1002f608

void Unwind_1002f608(void)

{
  int unaff_EBP;
  
  FUN_1002b2e0((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1002f610 at 1002f610

void Unwind_1002f610(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002f640 at 1002f640

void Unwind_1002f640(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1002f64b at 1002f64b

void Unwind_1002f64b(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x74));
  return;
}



// Function: Unwind@1002f680 at 1002f680

void Unwind_1002f680(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x8c));
  return;
}



// Function: Unwind@1002f68b at 1002f68b

void Unwind_1002f68b(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002f6c0 at 1002f6c0

void Unwind_1002f6c0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1002f6cb at 1002f6cb

void Unwind_1002f6cb(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1002f6d6 at 1002f6d6

void Unwind_1002f6d6(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002f6de at 1002f6de

void Unwind_1002f6de(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1002f710 at 1002f710

void Unwind_1002f710(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002f718 at 1002f718

void Unwind_1002f718(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1002f723 at 1002f723

void Unwind_1002f723(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1002f72e at 1002f72e

void Unwind_1002f72e(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1002f760 at 1002f760

void Unwind_1002f760(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1002f768 at 1002f768

void Unwind_1002f768(void)

{
  int unaff_EBP;
  
  FUN_10018830((void *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1002f770 at 1002f770

void Unwind_1002f770(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2b4));
  return;
}



// Function: Unwind@1002f77b at 1002f77b

void Unwind_1002f77b(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -800));
  return;
}



// Function: Unwind@1002f786 at 1002f786

void Unwind_1002f786(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x324) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x324) = *(uint *)(unaff_EBP + -0x324) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f7d0 at 1002f7d0

void Unwind_1002f7d0(void)

{
  int unaff_EBP;
  
  FUN_10019a70(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f800 at 1002f800

void Unwind_1002f800(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1002f808 at 1002f808

void Unwind_1002f808(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x7c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x7c) = *(uint *)(unaff_EBP + -0x7c) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002f850 at 1002f850

void Unwind_1002f850(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1002f866. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<char,struct_std::char_traits<char>_>::
    ~basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x70));
    return;
  }
  return;
}



// Function: Unwind@1002f86d at 1002f86d

void Unwind_1002f86d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002f873. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1002f879 at 1002f879

void Unwind_1002f879(void)

{
  int unaff_EBP;
  
  FUN_10018bf0((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1002f8a0 at 1002f8a0

void Unwind_1002f8a0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002f8a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1002f8ac at 1002f8ac

void Unwind_1002f8ac(void)

{
  int unaff_EBP;
  
  FUN_10018bf0((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1002f8e0 at 1002f8e0

void Unwind_1002f8e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002f8e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f910 at 1002f910

void Unwind_1002f910(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1002f940 at 1002f940

void Unwind_1002f940(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1002f970 at 1002f970

void Unwind_1002f970(void)

{
  int unaff_EBP;
  
  FUN_10019a70(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002f9a0 at 1002f9a0

void Unwind_1002f9a0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1002f9ab at 1002f9ab

void Unwind_1002f9ab(void)

{
  int unaff_EBP;
  
  FUN_10019bc0(unaff_EBP + -0x80);
  return;
}



// Function: Unwind@1002f9e0 at 1002f9e0

void Unwind_1002f9e0(void)

{
  int unaff_EBP;
  
  FUN_1001a410(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fa10 at 1002fa10

void Unwind_1002fa10(void)

{
  int unaff_EBP;
  
  FUN_10019c20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fa40 at 1002fa40

void Unwind_1002fa40(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1002fa70 at 1002fa70

void Unwind_1002fa70(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002fa73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002faa0 at 1002faa0

void Unwind_1002faa0(void)

{
  int unaff_EBP;
  
  FUN_1001d630((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1002fad0 at 1002fad0

void Unwind_1002fad0(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1002fb00 at 1002fb00

void Unwind_1002fb00(void)

{
  int unaff_EBP;
  
  FUN_1001a410(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fb30 at 1002fb30

void Unwind_1002fb30(void)

{
  int unaff_EBP;
  
  FUN_10019c20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fb60 at 1002fb60

void Unwind_1002fb60(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1002fb90 at 1002fb90

void Unwind_1002fb90(void)

{
  int unaff_EBP;
  
  FUN_1001de40((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002fbc0 at 1002fbc0

void Unwind_1002fbc0(void)

{
  int unaff_EBP;
  
  FUN_1001de40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002fbf0 at 1002fbf0

void Unwind_1002fbf0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1002fbf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fc40 at 1002fc40

void Unwind_1002fc40(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@1002fc70 at 1002fc70

void Unwind_1002fc70(void)

{
  int unaff_EBP;
  
  FUN_10019c20(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fca0 at 1002fca0

void Unwind_1002fca0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1002fcd0 at 1002fcd0

void Unwind_1002fcd0(void)

{
  FUN_1001dbd0();
  return;
}



// Function: Unwind@1002fd00 at 1002fd00

void Unwind_1002fd00(void)

{
  FUN_1001dbd0();
  return;
}



// Function: Unwind@1002fd30 at 1002fd30

void Unwind_1002fd30(void)

{
  FUN_1001dbd0();
  return;
}



// Function: Unwind@1002fd60 at 1002fd60

void Unwind_1002fd60(void)

{
  int unaff_EBP;
  
  FUN_1001e200(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fd90 at 1002fd90

void Unwind_1002fd90(void)

{
  int unaff_EBP;
  
  FUN_1001e200(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002fde0 at 1002fde0

void Unwind_1002fde0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1002fe20 at 1002fe20

void Unwind_1002fe20(void)

{
  FUN_1000aca0(&DAT_100442d0);
  return;
}



// Function: Unwind@1002fe2a at 1002fe2a

void Unwind_1002fe2a(void)

{
  FUN_1000aca0(&DAT_100442ec);
  return;
}



// Function: Unwind@1002fe34 at 1002fe34

void Unwind_1002fe34(void)

{
  FUN_1000aca0(&DAT_10044308);
  return;
}



// Function: Unwind@1002fe3e at 1002fe3e

void Unwind_1002fe3e(void)

{
  FUN_1000aca0(&DAT_10044324);
  return;
}



// Function: Unwind@1002fe48 at 1002fe48

void Unwind_1002fe48(void)

{
  FUN_1000aca0(&DAT_10044340);
  return;
}



// Function: Unwind@1002fe52 at 1002fe52

void Unwind_1002fe52(void)

{
  FUN_1000aca0(&DAT_1004435c);
  return;
}



// Function: Unwind@1002fe5c at 1002fe5c

void Unwind_1002fe5c(void)

{
  FUN_1000aca0(&DAT_10044378);
  return;
}



// Function: Unwind@1002fe66 at 1002fe66

void Unwind_1002fe66(void)

{
  FUN_1000aca0(&DAT_10044394);
  return;
}



// Function: Unwind@1002fe70 at 1002fe70

void Unwind_1002fe70(void)

{
  FUN_1000aca0(&DAT_100443b0);
  return;
}



// Function: Unwind@1002fe7a at 1002fe7a

void Unwind_1002fe7a(void)

{
  FUN_1000aca0(&DAT_100443cc);
  return;
}



// Function: Unwind@1002fe84 at 1002fe84

void Unwind_1002fe84(void)

{
  FUN_1000aca0(&DAT_100443e8);
  return;
}



// Function: Unwind@1002fe8e at 1002fe8e

void Unwind_1002fe8e(void)

{
  FUN_1000aca0(&DAT_10044404);
  return;
}



// Function: Unwind@1002fe98 at 1002fe98

void Unwind_1002fe98(void)

{
  FUN_1000aca0(&DAT_10044420);
  return;
}



// Function: Unwind@1002fea2 at 1002fea2

void Unwind_1002fea2(void)

{
  FUN_1000aca0(&DAT_1004443c);
  return;
}



// Function: Unwind@1002feac at 1002feac

void Unwind_1002feac(void)

{
  FUN_1000aca0(&DAT_10044458);
  return;
}



// Function: Unwind@1002fee0 at 1002fee0

void Unwind_1002fee0(void)

{
  int unaff_EBP;
  
  FUN_10010e20((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002fee8 at 1002fee8

void Unwind_1002fee8(void)

{
  int unaff_EBP;
  
  FUN_1001ea20((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1002fef0 at 1002fef0

void Unwind_1002fef0(void)

{
  int unaff_EBP;
  
  FUN_1000e2f0((_Container_base0 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1002fef8 at 1002fef8

void Unwind_1002fef8(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1002ff00 at 1002ff00

void Unwind_1002ff00(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1002ff08 at 1002ff08

void Unwind_1002ff08(void)

{
  int unaff_EBP;
  
  FUN_1001ea80((int *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1002ff40 at 1002ff40

void Unwind_1002ff40(void)

{
  int unaff_EBP;
  
  FUN_1001ec90(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ff70 at 1002ff70

void Unwind_1002ff70(void)

{
  int unaff_EBP;
  
  FUN_1001efc0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1002ffa0 at 1002ffa0

void Unwind_1002ffa0(void)

{
  int unaff_EBP;
  
  FUN_10010e20((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1002ffa8 at 1002ffa8

void Unwind_1002ffa8(void)

{
  int unaff_EBP;
  
  FUN_1001ea20((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1002ffb0 at 1002ffb0

void Unwind_1002ffb0(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1002ffe0 at 1002ffe0

void Unwind_1002ffe0(void)

{
  int unaff_EBP;
  
  FUN_1001ec90(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030010 at 10030010

void Unwind_10030010(void)

{
  int unaff_EBP;
  
  FUN_1001efc0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030040 at 10030040

void Unwind_10030040(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@10030070 at 10030070

void Unwind_10030070(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@100300a0 at 100300a0

void Unwind_100300a0(void)

{
  int unaff_EBP;
  
  FUN_10021370((int *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@100300e0 at 100300e0

void Unwind_100300e0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xa4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xa4) = *(uint *)(unaff_EBP + -0xa4) & 0xfffffffe;
    FUN_10021370(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100300ff at 100300ff

void Unwind_100300ff(void)

{
  int unaff_EBP;
  
  FUN_10021370((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10030107 at 10030107

void Unwind_10030107(void)

{
  int unaff_EBP;
  
  FUN_10021370((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1003010f at 1003010f

void Unwind_1003010f(void)

{
  int unaff_EBP;
  
  FUN_10021370((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10030140 at 10030140

void Unwind_10030140(void)

{
  int unaff_EBP;
  
  FUN_100214b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030170 at 10030170

void Unwind_10030170(void)

{
  int unaff_EBP;
  
  FUN_100214b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100301a0 at 100301a0

void Unwind_100301a0(void)

{
  int unaff_EBP;
  
  FUN_100214b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100301d0 at 100301d0

void Unwind_100301d0(void)

{
  int unaff_EBP;
  
  FUN_100214b0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030200 at 10030200

void Unwind_10030200(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10030208 at 10030208

void Unwind_10030208(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x244));
  return;
}



// Function: Unwind@10030213 at 10030213

void Unwind_10030213(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x264));
  return;
}



// Function: Unwind@10030250 at 10030250

void Unwind_10030250(void)

{
  int unaff_EBP;
  
  FUN_100228e0(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@1003025b at 1003025b

void Unwind_1003025b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf8) = *(uint *)(unaff_EBP + -0xf8) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100302a0 at 100302a0

void Unwind_100302a0(void)

{
  int unaff_EBP;
  
  FUN_100229b0(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@100302ab at 100302ab

void Unwind_100302ab(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf8) = *(uint *)(unaff_EBP + -0xf8) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100302f0 at 100302f0

void Unwind_100302f0(void)

{
  int unaff_EBP;
  
  FUN_100228e0(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@100302fb at 100302fb

void Unwind_100302fb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf8) = *(uint *)(unaff_EBP + -0xf8) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030340 at 10030340

void Unwind_10030340(void)

{
  int unaff_EBP;
  
  FUN_10022b10(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10030348 at 10030348

void Unwind_10030348(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x60) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x60) = *(uint *)(unaff_EBP + -0x60) & 0xfffffffe;
    FUN_10007720(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030380 at 10030380

void Unwind_10030380(void)

{
  int unaff_EBP;
  
  FUN_100229b0(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@1003038b at 1003038b

void Unwind_1003038b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf8) = *(uint *)(unaff_EBP + -0xf8) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100303d0 at 100303d0

void Unwind_100303d0(void)

{
  int unaff_EBP;
  
  FUN_100228e0(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@100303db at 100303db

void Unwind_100303db(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf8) = *(uint *)(unaff_EBP + -0xf8) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030420 at 10030420

void Unwind_10030420(void)

{
  int unaff_EBP;
  
  FUN_100229b0(unaff_EBP + -0xb4);
  return;
}



// Function: Unwind@1003042b at 1003042b

void Unwind_1003042b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf8) = *(uint *)(unaff_EBP + -0xf8) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030470 at 10030470

void Unwind_10030470(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@10030478 at 10030478

void Unwind_10030478(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100304b0 at 100304b0

void Unwind_100304b0(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@100304b8 at 100304b8

void Unwind_100304b8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100304f0 at 100304f0

void Unwind_100304f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -100) & 1) != 0) {
    *(uint *)(unaff_EBP + -100) = *(uint *)(unaff_EBP + -100) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030530 at 10030530

void Unwind_10030530(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x60) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x60) = *(uint *)(unaff_EBP + -0x60) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030570 at 10030570

void Unwind_10030570(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10007720(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100305b0 at 100305b0

void Unwind_100305b0(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@100305e0 at 100305e0

void Unwind_100305e0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10007720(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030620 at 10030620

void Unwind_10030620(void)

{
  int unaff_EBP;
  
  FUN_10022b10(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10030650 at 10030650

void Unwind_10030650(void)

{
  int unaff_EBP;
  
  FUN_10022b10(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10030680 at 10030680

void Unwind_10030680(void)

{
  int unaff_EBP;
  
  FUN_10022b10(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@100306b0 at 100306b0

void Unwind_100306b0(void)

{
  int unaff_EBP;
  
  FUN_10022b10(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@100306e0 at 100306e0

void Unwind_100306e0(void)

{
  int unaff_EBP;
  
  FUN_100080b0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10030710 at 10030710

void Unwind_10030710(void)

{
  int unaff_EBP;
  
  FUN_10022b10(unaff_EBP + -0x1c);
  return;
}



// Function: Unwind@10030740 at 10030740

void Unwind_10030740(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10022b10(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030780 at 10030780

void Unwind_10030780(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x50) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x50) = *(uint *)(unaff_EBP + -0x50) & 0xfffffffe;
    FUN_10022b10(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100307c0 at 100307c0

void Unwind_100307c0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100307c8 at 100307c8

void Unwind_100307c8(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100307d0 at 100307d0

void Unwind_100307d0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@100307d8 at 100307d8

void Unwind_100307d8(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100307e0 at 100307e0

void Unwind_100307e0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xc4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xc4) = *(uint *)(unaff_EBP + -0xc4) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030830 at 10030830

void Unwind_10030830(void)

{
  int unaff_EBP;
  
  FUN_10025d90((undefined4 *)(unaff_EBP + -0xf0));
  return;
}



// Function: Unwind@1003083b at 1003083b

void Unwind_1003083b(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xf4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xf4) = *(uint *)(unaff_EBP + -0xf4) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030890 at 10030890

void Unwind_10030890(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@10030898 at 10030898

void Unwind_10030898(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x70) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x70) = *(uint *)(unaff_EBP + -0x70) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100308e0 at 100308e0

void Unwind_100308e0(void)

{
  int unaff_EBP;
  
  FUN_10025e20((undefined4 *)(unaff_EBP + -0x170));
  return;
}



// Function: Unwind@100308eb at 100308eb

void Unwind_100308eb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x174) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x174) = *(uint *)(unaff_EBP + -0x174) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030940 at 10030940

void Unwind_10030940(void)

{
  int unaff_EBP;
  
  FUN_10007720((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10030970 at 10030970

void Unwind_10030970(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1e4) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1e4) = *(uint *)(unaff_EBP + -0x1e4) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100309c0 at 100309c0

void Unwind_100309c0(void)

{
  FUN_1001dbd0();
  return;
}



// Function: Unwind@100309f0 at 100309f0

void Unwind_100309f0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10030a06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<char,struct_std::char_traits<char>_>::
    ~basic_ios<char,struct_std::char_traits<char>_>
              ((basic_ios<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x60));
    return;
  }
  return;
}



// Function: Unwind@10030a0d at 10030a0d

void Unwind_10030a0d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030a13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10030a19 at 10030a19

void Unwind_10030a19(void)

{
  int unaff_EBP;
  
  FUN_100245b0((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10030a40 at 10030a40

void Unwind_10030a40(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030a46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<char,struct_std::char_traits<char>_>::
  ~basic_iostream<char,struct_std::char_traits<char>_>
            ((basic_iostream<char,struct_std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10030a4c at 10030a4c

void Unwind_10030a4c(void)

{
  int unaff_EBP;
  
  FUN_100245b0((basic_streambuf<char,struct_std::char_traits<char>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10030a80 at 10030a80

void Unwind_10030a80(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030ac0 at 10030ac0

void Unwind_10030ac0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030ac3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030af0 at 10030af0

void Unwind_10030af0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x10030b06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x60));
    return;
  }
  return;
}



// Function: Unwind@10030b0d at 10030b0d

void Unwind_10030b0d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030b13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10030b19 at 10030b19

void Unwind_10030b19(void)

{
  int unaff_EBP;
  
  FUN_100251d0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@10030b40 at 10030b40

void Unwind_10030b40(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030b46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10030b4c at 10030b4c

void Unwind_10030b4c(void)

{
  int unaff_EBP;
  
  FUN_100251d0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10030b80 at 10030b80

void Unwind_10030b80(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x54) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x54) = *(uint *)(unaff_EBP + -0x54) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030bc0 at 10030bc0

void Unwind_10030bc0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030bc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030bf0 at 10030bf0

void Unwind_10030bf0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030bf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,struct_std::char_traits<char>_>::
  ~basic_streambuf<char,struct_std::char_traits<char>_>
            (*(basic_streambuf<char,struct_std::char_traits<char>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030c20 at 10030c20

void Unwind_10030c20(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10030c28 at 10030c28

void Unwind_10030c28(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xac) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xac) = *(uint *)(unaff_EBP + -0xac) & 0xfffffffe;
    FUN_1001d820(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030c47 at 10030c47

void Unwind_10030c47(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10030c4f at 10030c4f

void Unwind_10030c4f(void)

{
  int unaff_EBP;
  
  FUN_1001d820((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10030c80 at 10030c80

void Unwind_10030c80(void)

{
  FUN_1001dbd0();
  return;
}



// Function: Unwind@10030cb0 at 10030cb0

void Unwind_10030cb0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10030cb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030ce0 at 10030ce0

void Unwind_10030ce0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10030ce8 at 10030ce8

void Unwind_10030ce8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0xac) & 1) != 0) {
    *(uint *)(unaff_EBP + -0xac) = *(uint *)(unaff_EBP + -0xac) & 0xfffffffe;
    FUN_1000aca0(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10030d07 at 10030d07

void Unwind_10030d07(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@10030d0f at 10030d0f

void Unwind_10030d0f(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@10030d40 at 10030d40

void Unwind_10030d40(void)

{
  FUN_1001dbd0();
  return;
}



// Function: Unwind@10030d70 at 10030d70

void Unwind_10030d70(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10030da0 at 10030da0

void Unwind_10030da0(void)

{
  int unaff_EBP;
  
  FUN_10004e60((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10030dd0 at 10030dd0

void Unwind_10030dd0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2b4));
  return;
}



// Function: Unwind@10030e10 at 10030e10

void Unwind_10030e10(void)

{
  int unaff_EBP;
  
  FUN_10027820((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10030e18 at 10030e18

void Unwind_10030e18(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2d8));
  return;
}



// Function: Unwind@10030e50 at 10030e50

void Unwind_10030e50(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@10030e5b at 10030e5b

void Unwind_10030e5b(void)

{
  int unaff_EBP;
  
  FUN_10028000((void *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@10030e90 at 10030e90

void Unwind_10030e90(void)

{
  int unaff_EBP;
  
  FUN_10028060(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030ec0 at 10030ec0

void Unwind_10030ec0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030ec8 at 10030ec8

void Unwind_10030ec8(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@10030ef0 at 10030ef0

void Unwind_10030ef0(void)

{
  int unaff_EBP;
  
  FUN_10028060(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030f20 at 10030f20

void Unwind_10030f20(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10030f28 at 10030f28

void Unwind_10030f28(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@10030f70 at 10030f70

void Unwind_10030f70(void)

{
  FUN_10014d40();
  return;
}



// Function: Unwind@10030fa0 at 10030fa0

void Unwind_10030fa0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10030fd0 at 10030fd0

void Unwind_10030fd0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10031000 at 10031000

void Unwind_10031000(void)

{
  int unaff_EBP;
  
  FUN_10028060(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10031030 at 10031030

void Unwind_10031030(void)

{
  int unaff_EBP;
  
  FUN_1000aca0(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10031038 at 10031038

void Unwind_10031038(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@10031060 at 10031060

void Unwind_10031060(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10031090 at 10031090

void Unwind_10031090(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100310c0 at 100310c0

void Unwind_100310c0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@100310c8 at 100310c8

void Unwind_100310c8(void)

{
  int unaff_EBP;
  
  FUN_1002b180(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100310d0 at 100310d0

void Unwind_100310d0(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@10031100 at 10031100

void Unwind_10031100(void)

{
  int unaff_EBP;
  
  FUN_1002b180(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10031108 at 10031108

void Unwind_10031108(void)

{
  int unaff_EBP;
  
  FUN_1000aca0((void *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1003112e at 1003112e

void Unwind_1003112e(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10031131. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10031152 at 10031152

void Unwind_10031152(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10031155. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_10031180 at 10031180

void FUN_10031180(void)

{
  FUN_1000a150(&DAT_10043c00,L"ialf");
  _atexit(FUN_10034100);
  return;
}



// Function: FUN_100311b0 at 100311b0

void FUN_100311b0(void)

{
  FUN_1000a150(&DAT_10043c1c,L".dat");
  _atexit(FUN_10034120);
  return;
}



// Function: FUN_100311e0 at 100311e0

void FUN_100311e0(void)

{
  FUN_1000a150(&DAT_10043c38,L",");
  _atexit(FUN_10034140);
  return;
}



// Function: FUN_10031210 at 10031210

void FUN_10031210(void)

{
  FUN_1000ac40(&DAT_10043c54,0x100370c0);
  _atexit(FUN_10034160);
  return;
}



// Function: FUN_10031240 at 10031240

void FUN_10031240(void)

{
  FUN_1000a150(&DAT_10043c58,L"|");
  _atexit(FUN_10034180);
  return;
}



// Function: FUN_10031270 at 10031270

void FUN_10031270(void)

{
  FUN_1000a150(&DAT_10043c74,L"_");
  _atexit(FUN_100341a0);
  return;
}



// Function: FUN_100312a0 at 100312a0

void FUN_100312a0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002db76;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a150(&DAT_10043c90,L"PC Date");
  local_8 = 0;
  FUN_1000a150(&DAT_10043cac,L"PC Time (GMT)");
  local_8._0_1_ = 1;
  FUN_1000a150(&DAT_10043cc8,L"Feature Used");
  local_8._0_1_ = 2;
  FUN_1000a150(&DAT_10043ce4,L"Action");
  local_8._0_1_ = 3;
  FUN_1000a150(&DAT_10043d00,L"Units of Measure");
  local_8._0_1_ = 4;
  FUN_1000a150(&DAT_10043d1c,L"Tool Level");
  local_8._0_1_ = 5;
  FUN_1000a150(&DAT_10043d38,L"Connection Type");
  local_8._0_1_ = 6;
  FUN_1000a150(&DAT_10043d54,L"Module Type-Engine Marketing Name");
  local_8._0_1_ = 7;
  FUN_1000a150(&DAT_10043d70,L"Module Marketing Name");
  local_8._0_1_ = 8;
  FUN_1000a150(&DAT_10043d8c,L"PCID");
  local_8._0_1_ = 9;
  FUN_1000a150(&DAT_10043da8,L"OS Version");
  local_8._0_1_ = 10;
  FUN_1000a150(&DAT_10043dc4,L"Install Language");
  local_8._0_1_ = 0xb;
  FUN_1000a150(&DAT_10043de0,L"INSITE Version");
  local_8._0_1_ = 0xc;
  FUN_1000a150(&DAT_10043dfc,L"Source");
  local_8._0_1_ = 0xd;
  FUN_1000a150(&DAT_10043e18,L"Error ID");
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_1000a150(&DAT_10043e34,L"Machine Name");
  local_8 = 0xffffffff;
  _atexit(FUN_100341c0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10031420 at 10031420

void FUN_10031420(void)

{
  FUN_1000a150(&DAT_10043e50,L"Windows Vista ");
  _atexit(FUN_100341f0);
  return;
}



// Function: FUN_10031450 at 10031450

void FUN_10031450(void)

{
  FUN_1000a150(&DAT_10043e6c,L"ActivityLog");
  _atexit(FUN_10034210);
  return;
}



// Function: FUN_10031480 at 10031480

void FUN_10031480(void)

{
  FUN_1000ac40(&DAT_10043e88,0x100372d0);
  _atexit(FUN_10034230);
  return;
}



// Function: FUN_100314b0 at 100314b0

void FUN_100314b0(void)

{
  FUN_1000a150(&DAT_10043e8c,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale\\LanguageExt")
  ;
  _atexit(FUN_10034250);
  return;
}



// Function: FUN_100314e0 at 100314e0

void FUN_100314e0(void)

{
  FUN_1000ad00((undefined4 *)&DAT_10043ea8);
  _atexit(FUN_10034270);
  return;
}



// Function: FUN_10031510 at 10031510

void FUN_10031510(void)

{
  FUN_1000a150(&DAT_100441ac,L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0");
  _atexit(FUN_10034420);
  return;
}



// Function: FUN_10031540 at 10031540

void FUN_10031540(void)

{
  FUN_10016c70(&DAT_1004421c,(undefined4 *)&DAT_100441ac,L"\\Users");
  _atexit(FUN_10034460);
  return;
}



// Function: FUN_10031580 at 10031580

void FUN_10031580(void)

{
  FUN_10016c70(&DAT_10044190,(undefined4 *)&DAT_100441ac,L"\\Users\\Templates\\CumminsDefault");
  _atexit(FUN_10034440);
  return;
}



// Function: FUN_100315c0 at 100315c0

void FUN_100315c0(void)

{
  FUN_1000a150(&DAT_100441e4,L"\\");
  _atexit(FUN_10034480);
  return;
}



// Function: FUN_100315f0 at 100315f0

void FUN_100315f0(void)

{
  FUN_1000a150(&DAT_100441c8,L"\\Files");
  _atexit(FUN_100344a0);
  return;
}



// Function: FUN_10031620 at 10031620

void FUN_10031620(void)

{
  FUN_1000a150(&DAT_10044200,L"Path");
  _atexit(FUN_100344c0);
  return;
}



// Function: FUN_10031650 at 10031650

void FUN_10031650(void)

{
  FUN_1000a150(&DAT_10043ed8,L"ialf");
  _atexit(FUN_10034290);
  return;
}



// Function: FUN_10031680 at 10031680

void FUN_10031680(void)

{
  FUN_1000a150(&DAT_10043ef4,L".dat");
  _atexit(FUN_100342b0);
  return;
}



// Function: FUN_100316b0 at 100316b0

void FUN_100316b0(void)

{
  FUN_1000a150(&DAT_10043f10,L",");
  _atexit(FUN_100342d0);
  return;
}



// Function: FUN_100316e0 at 100316e0

void FUN_100316e0(void)

{
  FUN_1000ac40(&DAT_10043f2c,0x100370c0);
  _atexit(FUN_100342f0);
  return;
}



// Function: FUN_10031710 at 10031710

void FUN_10031710(void)

{
  FUN_1000a150(&DAT_10043f30,L"|");
  _atexit(FUN_10034310);
  return;
}



// Function: FUN_10031740 at 10031740

void FUN_10031740(void)

{
  FUN_1000a150(&DAT_10043f4c,L"_");
  _atexit(FUN_10034330);
  return;
}



// Function: FUN_10031770 at 10031770

void FUN_10031770(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002f3f6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a150(&DAT_10043f68,L"PC Date");
  local_8 = 0;
  FUN_1000a150(&DAT_10043f84,L"PC Time (GMT)");
  local_8._0_1_ = 1;
  FUN_1000a150(&DAT_10043fa0,L"Feature Used");
  local_8._0_1_ = 2;
  FUN_1000a150(&DAT_10043fbc,L"Action");
  local_8._0_1_ = 3;
  FUN_1000a150(&DAT_10043fd8,L"Units of Measure");
  local_8._0_1_ = 4;
  FUN_1000a150(&DAT_10043ff4,L"Tool Level");
  local_8._0_1_ = 5;
  FUN_1000a150(&DAT_10044010,L"Connection Type");
  local_8._0_1_ = 6;
  FUN_1000a150(&DAT_1004402c,L"Module Type-Engine Marketing Name");
  local_8._0_1_ = 7;
  FUN_1000a150(&DAT_10044048,L"Module Marketing Name");
  local_8._0_1_ = 8;
  FUN_1000a150(&DAT_10044064,L"PCID");
  local_8._0_1_ = 9;
  FUN_1000a150(&DAT_10044080,L"OS Version");
  local_8._0_1_ = 10;
  FUN_1000a150(&DAT_1004409c,L"Install Language");
  local_8._0_1_ = 0xb;
  FUN_1000a150(&DAT_100440b8,L"INSITE Version");
  local_8._0_1_ = 0xc;
  FUN_1000a150(&DAT_100440d4,L"Source");
  local_8._0_1_ = 0xd;
  FUN_1000a150(&DAT_100440f0,L"Error ID");
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_1000a150(&DAT_1004410c,L"Machine Name");
  local_8 = 0xffffffff;
  _atexit(FUN_10034350);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100318f0 at 100318f0

void FUN_100318f0(void)

{
  FUN_1000a150(&DAT_10044128,L"Windows Vista ");
  _atexit(FUN_10034380);
  return;
}



// Function: FUN_10031920 at 10031920

void FUN_10031920(void)

{
  FUN_1000a150(&DAT_10044144,L"ActivityLog");
  _atexit(FUN_100343a0);
  return;
}



// Function: FUN_10031950 at 10031950

void FUN_10031950(void)

{
  FUN_1000ac40(&DAT_10044160,0x100372d0);
  _atexit(FUN_100343c0);
  return;
}



// Function: FUN_10031980 at 10031980

void FUN_10031980(void)

{
  FUN_1000a150(&DAT_10044164,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Locale\\LanguageExt")
  ;
  _atexit(FUN_100343e0);
  return;
}



// Function: FUN_100319b0 at 100319b0

void FUN_100319b0(void)

{
  FUN_10016d30();
  _atexit(FUN_10034400);
  return;
}



// Function: FUN_100319e0 at 100319e0

void FUN_100319e0(void)

{
  FUN_1000a150(&DAT_10044240,L"ialf");
  _atexit(FUN_100344e0);
  return;
}



// Function: FUN_10031a10 at 10031a10

void FUN_10031a10(void)

{
  FUN_1000a150(&DAT_1004425c,L".dat");
  _atexit(FUN_10034500);
  return;
}



// Function: FUN_10031a40 at 10031a40

void FUN_10031a40(void)

{
  FUN_1000a150(&DAT_10044278,L",");
  _atexit(FUN_10034520);
  return;
}



// Function: FUN_10031a70 at 10031a70

void FUN_10031a70(void)

{
  FUN_1000ac40(&DAT_10044294,0x100370c0);
  _atexit(FUN_10034540);
  return;
}



// Function: FUN_10031aa0 at 10031aa0

void FUN_10031aa0(void)

{
  FUN_1000a150(&DAT_10044298,L"|");
  _atexit(FUN_10034560);
  return;
}



// Function: FUN_10031ad0 at 10031ad0

void FUN_10031ad0(void)

{
  FUN_1000a150(&DAT_100442b4,L"_");
  _atexit(FUN_10034580);
  return;
}



// Function: FUN_10031b00 at 10031b00

void FUN_10031b00(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002feb6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000a150(&DAT_100442d0,L"PC Date");
  local_8 = 0;
  FUN_1000a150(&DAT_100442ec,L"PC Time (GMT)");
  local_8._0_1_ = 1;
  FUN_1000a150(&DAT_10044308,L"Feature Used");
  local_8._0_1_ = 2;
  FUN_1000a150(&DAT_10044324,L"Action");
  local_8._0_1_ = 3;
  FUN_1000a150(&DAT_10044340,L"Units of Measure");
  local_8._0_1_ = 4;
  FUN_1000a150(&DAT_1004435c,L"Tool Level");
  local_8._0_1_ = 5;
  FUN_1000a150(&DAT_10044378,L"Connection Type");
  local_8._0_1_ = 6;
  FUN_1000a150(&DAT_10044394,L"Module Type-Engine Marketing Name");
  local_8._0_1_ = 7;
  FUN_1000a150(&DAT_100443b0,L"Module Marketing Name");
  local_8._0_1_ = 8;
  FUN_1000a150(&DAT_100443cc,L"PCID");
  local_8._0_1_ = 9;
  FUN_1000a150(&DAT_100443e8,L"OS Version");
  local_8._0_1_ = 10;
  FUN_1000a150(&DAT_10044404,L"Install Language");
  local_8._0_1_ = 0xb;
  FUN_1000a150(&DAT_10044420,L"INSITE Version");
  local_8._0_1_ = 0xc;
  FUN_1000a150(&DAT_1004443c,L"Source");
  local_8._0_1_ = 0xd;
  FUN_1000a150(&DAT_10044458,L"Error ID");
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_1000a150(&DAT_10044474,L"Machine Name");
  local_8 = 0xffffffff;
  _atexit(FUN_100345a0);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10031c80 at 10031c80

void FUN_10031c80(void)

{
  return;
}



// Function: FUN_10031ca0 at 10031ca0

void FUN_10031ca0(void)

{
  FUN_1001f3e0((undefined4 *)&DAT_10045640);
  return;
}



// Function: FUN_10031cc0 at 10031cc0

void FUN_10031cc0(void)

{
  FUN_1000a150(&DAT_10044984,L"\r");
  _atexit(FUN_100345d0);
  return;
}



// Function: FUN_10031cf0 at 10031cf0

void FUN_10031cf0(void)

{
  FUN_1000a150(&DAT_10044968,L"\n");
  _atexit(FUN_100345f0);
  return;
}



// Function: FUN_10031d20 at 10031d20

void FUN_10031d20(void)

{
  FUN_1000a150(&DAT_10044498,L"\\n");
  _atexit(FUN_10034610);
  return;
}



// Function: FUN_10031d50 at 10031d50

void FUN_10031d50(void)

{
  FUN_1000a150(&DAT_10045114,L"\\r");
  _atexit(FUN_10034630);
  return;
}



// Function: FUN_10031d80 at 10031d80

void FUN_10031d80(void)

{
  FUN_1000a150(&DAT_10044fc0,L"EN");
  _atexit(FUN_10034650);
  return;
}



// Function: FUN_10031db0 at 10031db0

void FUN_10031db0(void)

{
  FUN_1000a150(&DAT_100454b0,L"ES");
  _atexit(FUN_10034670);
  return;
}



// Function: FUN_10031de0 at 10031de0

void FUN_10031de0(void)

{
  FUN_1000a150(&DAT_10044efc,L"PT");
  _atexit(FUN_10034690);
  return;
}



// Function: FUN_10031e10 at 10031e10

void FUN_10031e10(void)

{
  FUN_1000a150(&DAT_10045018,L"TR");
  _atexit(FUN_100346b0);
  return;
}



// Function: FUN_10031e40 at 10031e40

void FUN_10031e40(void)

{
  FUN_1000a150(&DAT_10045344,L"ZH");
  _atexit(FUN_100346d0);
  return;
}



// Function: FUN_10031e70 at 10031e70

void FUN_10031e70(void)

{
  FUN_1000a150(&DAT_10045050,L"JA");
  _atexit(FUN_100346f0);
  return;
}



// Function: FUN_10031ea0 at 10031ea0

void FUN_10031ea0(void)

{
  FUN_1000a150(&DAT_100453d0,L"FR");
  _atexit(FUN_10034710);
  return;
}



// Function: FUN_10031ed0 at 10031ed0

void FUN_10031ed0(void)

{
  FUN_1000a150(&DAT_10044fe0,L"DE");
  _atexit(FUN_10034730);
  return;
}



// Function: FUN_10031f00 at 10031f00

void FUN_10031f00(void)

{
  FUN_1000a150(&DAT_10044fa4,L"IT");
  _atexit(FUN_10034750);
  return;
}



// Function: FUN_10031f30 at 10031f30

void FUN_10031f30(void)

{
  FUN_1000a150(&DAT_10044f18,L"KO");
  _atexit(FUN_10034770);
  return;
}



// Function: FUN_10031f60 at 10031f60

void FUN_10031f60(void)

{
  FUN_1000a150(&DAT_10044ffc,L"RU");
  _atexit(FUN_10034790);
  return;
}



// Function: FUN_10031f90 at 10031f90

void FUN_10031f90(void)

{
  FUN_1000a150(&DAT_10044f34,L"DA");
  _atexit(FUN_100347b0);
  return;
}



// Function: FUN_10031fc0 at 10031fc0

void FUN_10031fc0(void)

{
  FUN_1000a150(&DAT_10044f6c,L"NL");
  _atexit(FUN_100347d0);
  return;
}



// Function: FUN_10032000 at 10032000

void FUN_10032000(void)

{
  FUN_1000a150(&DAT_10045034,L"FI");
  _atexit(FUN_100347f0);
  return;
}



// Function: FUN_10032030 at 10032030

void FUN_10032030(void)

{
  FUN_1000a150(&DAT_10045558,L"NO");
  _atexit(FUN_10034810);
  return;
}



// Function: FUN_10032060 at 10032060

void FUN_10032060(void)

{
  FUN_1000a150(&DAT_10044f50,L"SV");
  _atexit(FUN_10034830);
  return;
}



// Function: FUN_10032090 at 10032090

void FUN_10032090(void)

{
  FUN_1000a150(&DAT_10044f88,L"ID");
  _atexit(FUN_10034850);
  return;
}



// Function: FUN_100320c0 at 100320c0

void FUN_100320c0(void)

{
  FUN_1000ac40(&DAT_10044fdc,0x10037468);
  _atexit(FUN_10034870);
  return;
}



// Function: FUN_100320f0 at 100320f0

void FUN_100320f0(void)

{
  FUN_1000ac40(&DAT_100455c8,0x10037430);
  _atexit(FUN_10034890);
  return;
}



// Function: FUN_10032120 at 10032120

void FUN_10032120(void)

{
  FUN_1000ac40(&DAT_100455e8,0x1003744c);
  _atexit(FUN_100348b0);
  return;
}



// Function: FUN_10032150 at 10032150

void FUN_10032150(void)

{
  FUN_1000a150(&DAT_10044914,L"TRUE");
  _atexit(FUN_100348d0);
  return;
}



// Function: FUN_10032180 at 10032180

void FUN_10032180(void)

{
  FUN_1000a150(&DAT_10044930,L"FALSE");
  _atexit(FUN_100348f0);
  return;
}



// Function: FUN_100321b0 at 100321b0

void FUN_100321b0(void)

{
  FUN_1000a150(&DAT_100450f8,L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0");
  _atexit(FUN_10034910);
  return;
}



// Function: FUN_100321e0 at 100321e0

void FUN_100321e0(void)

{
  FUN_1000a150(&DAT_1004537c,L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS");
  _atexit(FUN_10034930);
  return;
}



// Function: FUN_10032210 at 10032210

void FUN_10032210(void)

{
  FUN_1000a150(&DAT_10044ad4,L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Shell");
  _atexit(FUN_10034950);
  return;
}



// Function: FUN_10032240 at 10032240

void FUN_10032240(void)

{
  FUN_1000a150(&DAT_1004545c,
               L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\{DABFE35C-C0FC-45F5-B2C7-312516BC7B23}"
              );
  _atexit(FUN_10034970);
  return;
}



// Function: FUN_10032270 at 10032270

void FUN_10032270(void)

{
  FUN_1000a150(&DAT_10044738,L"{F7CC7588-73DE-413C-9CF2-0DB81831383A}");
  _atexit(FUN_10034990);
  return;
}



// Function: FUN_100322a0 at 100322a0

void FUN_100322a0(void)

{
  FUN_1000a150(&DAT_10044754,L"{052113AD-8285-4E41-83FA-66B61C7458DF}");
  _atexit(FUN_100349b0);
  return;
}



// Function: FUN_100322d0 at 100322d0

void FUN_100322d0(void)

{
  FUN_1000a150(&DAT_10045574,L"CWLastAdapter");
  _atexit(FUN_100349d0);
  return;
}



// Function: FUN_10032300 at 10032300

void FUN_10032300(void)

{
  FUN_1000a150(&DAT_10044658,L"CWLastComPort");
  _atexit(FUN_100349f0);
  return;
}



// Function: FUN_10032330 at 10032330

void FUN_10032330(void)

{
  FUN_1000a150(&DAT_100449a0,L"CWLastConnType");
  _atexit(FUN_10034a10);
  return;
}



// Function: FUN_10032360 at 10032360

void FUN_10032360(void)

{
  FUN_1000a150(&DAT_10044674,L"CWLastProtocol");
  _atexit(FUN_10034a30);
  return;
}



// Function: FUN_10032390 at 10032390

void FUN_10032390(void)

{
  FUN_1000a150(&DAT_10044a48,L"CWLastRP1210A");
  _atexit(FUN_10034a50);
  return;
}



// Function: FUN_100323c0 at 100323c0

void FUN_100323c0(void)

{
  FUN_1000a150(&DAT_10045424,L"CWLastSimulator");
  _atexit(FUN_10034a70);
  return;
}



// Function: FUN_100323f0 at 100323f0

void FUN_100323f0(void)

{
  FUN_1000a150(&DAT_100454cc,L"Name");
  _atexit(FUN_10034a90);
  return;
}



// Function: FUN_10032420 at 10032420

void FUN_10032420(void)

{
  FUN_1000a150(&DAT_10044af0,L"ICL_DF_LOC");
  _atexit(FUN_10034ab0);
  return;
}



// Function: FUN_10032450 at 10032450

void FUN_10032450(void)

{
  FUN_1000a150(&DAT_10044dc8,L"IsActive");
  _atexit(FUN_10034ad0);
  return;
}



// Function: FUN_10032480 at 10032480

void FUN_10032480(void)

{
  FUN_1000a150(&DAT_10044d90,L"CONNECTION_TYPE");
  _atexit(FUN_10034af0);
  return;
}



// Function: FUN_100324b0 at 100324b0

void FUN_100324b0(void)

{
  FUN_1000a150(&DAT_10044834,L"Type");
  _atexit(FUN_10034b10);
  return;
}



// Function: FUN_100324e0 at 100324e0

void FUN_100324e0(void)

{
  FUN_1000a150(&DAT_10044de4,L"AutoActivate");
  _atexit(FUN_10034b30);
  return;
}



// Function: FUN_10032510 at 10032510

void FUN_10032510(void)

{
  FUN_1000a150(&DAT_10044d74,L"Category");
  _atexit(FUN_10034b50);
  return;
}



// Function: FUN_10032540 at 10032540

void FUN_10032540(void)

{
  FUN_1000a150(&DAT_100448c0,L"IsSystem");
  _atexit(FUN_10034b70);
  return;
}



// Function: FUN_10032570 at 10032570

void FUN_10032570(void)

{
  FUN_1000a150(&DAT_10044e38,L"IsAutoDetect");
  _atexit(FUN_10034b90);
  return;
}



// Function: FUN_100325a0 at 100325a0

void FUN_100325a0(void)

{
  FUN_1000a150(&DAT_100448dc,L"IclEnum");
  _atexit(FUN_10034bb0);
  return;
}



// Function: FUN_100325d0 at 100325d0

void FUN_100325d0(void)

{
  FUN_1000a150(&DAT_10045478,L"ModType");
  _atexit(FUN_10034bd0);
  return;
}



// Function: FUN_10032600 at 10032600

void FUN_10032600(void)

{
  FUN_1000a150(&DAT_100450c0,L"SystemType");
  _atexit(FUN_10034bf0);
  return;
}



// Function: FUN_10032630 at 10032630

void FUN_10032630(void)

{
  FUN_1000a150(&DAT_10044850,L"EngineType");
  _atexit(FUN_10034c10);
  return;
}



// Function: FUN_10032660 at 10032660

void FUN_10032660(void)

{
  FUN_1000a150(&DAT_1004506c,L"CMNS32");
  _atexit(FUN_10034c30);
  return;
}



// Function: FUN_10032690 at 10032690

void FUN_10032690(void)

{
  FUN_1000a150(&DAT_10045590,L"CMNSI632");
  _atexit(FUN_10034c50);
  return;
}



// Function: FUN_100326c0 at 100326c0

void FUN_100326c0(void)

{
  FUN_1000a150(&DAT_100448a4,L"AdapterName");
  _atexit(FUN_10034c70);
  return;
}



// Function: FUN_100326f0 at 100326f0

void FUN_100326f0(void)

{
  FUN_1000a150(&DAT_10045130,L"AdapterDescription");
  _atexit(FUN_10034c90);
  return;
}



// Function: FUN_10032720 at 10032720

void FUN_10032720(void)

{
  FUN_1000a150(&DAT_1004486c,L"Cummins Inc.");
  _atexit(FUN_10034cb0);
  return;
}



// Function: FUN_10032750 at 10032750

void FUN_10032750(void)

{
  FUN_1000a150(&DAT_10044888,L"PROTOCOL");
  _atexit(FUN_10034cd0);
  return;
}



// Function: FUN_10032780 at 10032780

void FUN_10032780(void)

{
  FUN_1000a150(&DAT_10045520,L"PORT");
  _atexit(FUN_10034cf0);
  return;
}



// Function: FUN_100327b0 at 100327b0

void FUN_100327b0(void)

{
  FUN_1000a150(&DAT_1004553c,L"PORT");
  _atexit(FUN_10034d10);
  return;
}



// Function: FUN_100327e0 at 100327e0

void FUN_100327e0(void)

{
  FUN_1000a150(&DAT_10045624,L"IRQ");
  _atexit(FUN_10034d30);
  return;
}



// Function: FUN_10032810 at 10032810

void FUN_10032810(void)

{
  FUN_1000a150(&DAT_10044818,L"DLA_TYPE");
  _atexit(FUN_10034d50);
  return;
}



// Function: FUN_10032840 at 10032840

void FUN_10032840(void)

{
  FUN_1000a150(&DAT_100447fc,L"PROTOCOL");
  _atexit(FUN_10034d70);
  return;
}



// Function: FUN_10032870 at 10032870

void FUN_10032870(void)

{
  FUN_1000a150(&DAT_10045088,L"INI");
  _atexit(FUN_10034d90);
  return;
}



// Function: FUN_100328a0 at 100328a0

void FUN_100328a0(void)

{
  FUN_1000a150(&DAT_100447e0,L"DEVICEID");
  _atexit(FUN_10034db0);
  return;
}



// Function: FUN_100328d0 at 100328d0

void FUN_100328d0(void)

{
  FUN_1000a150(&DAT_100455ac,L"ECM_TYPE");
  _atexit(FUN_10034dd0);
  return;
}



// Function: FUN_10032900 at 10032900

void FUN_10032900(void)

{
  FUN_1000a150(&DAT_1004494c,L"SimType");
  _atexit(FUN_10034df0);
  return;
}



// Function: FUN_10032930 at 10032930

void FUN_10032930(void)

{
  FUN_1000a150(&DAT_10045494,L"ModType");
  _atexit(FUN_10034e10);
  return;
}



// Function: FUN_10032960 at 10032960

void FUN_10032960(void)

{
  FUN_1000a150(&DAT_100450dc,L"SystemType");
  _atexit(FUN_10034e30);
  return;
}



// Function: FUN_10032990 at 10032990

void FUN_10032990(void)

{
  FUN_1000a150(&DAT_100447c4,L"EngineType");
  _atexit(FUN_10034e50);
  return;
}



// Function: FUN_100329c0 at 100329c0

void FUN_100329c0(void)

{
  FUN_1000a150(&DAT_100450a4,L"INI");
  _atexit(FUN_10034e70);
  return;
}



// Function: FUN_100329f0 at 100329f0

void FUN_100329f0(void)

{
  FUN_1000a150(&DAT_10044770,L"DEVICEID");
  _atexit(FUN_10034e90);
  return;
}



// Function: FUN_10032a20 at 10032a20

void FUN_10032a20(void)

{
  FUN_1000a150(&DAT_100447a8,L"DLA_TYPE");
  _atexit(FUN_10034eb0);
  return;
}



// Function: FUN_10032a50 at 10032a50

void FUN_10032a50(void)

{
  FUN_1000a150(&DAT_1004478c,L"PROTOCOL");
  _atexit(FUN_10034ed0);
  return;
}



// Function: FUN_10032a80 at 10032a80

void FUN_10032a80(void)

{
  FUN_1000a150(&DAT_100448f8,L"DLA_TYPE");
  _atexit(FUN_10034ef0);
  return;
}



// Function: FUN_10032ab0 at 10032ab0

void FUN_10032ab0(void)

{
  FUN_1000a150(&DAT_10044e54,L"ID");
  _atexit(FUN_10034f10);
  return;
}



// Function: FUN_10032ae0 at 10032ae0

void FUN_10032ae0(void)

{
  FUN_1000a150(&DAT_10044a64,L"Auto Detect");
  _atexit(FUN_10034f30);
  return;
}



// Function: FUN_10032b10 at 10032b10

void FUN_10032b10(void)

{
  FUN_1000a150(&DAT_10044e00,L"J1939");
  _atexit(FUN_10034f50);
  return;
}



// Function: FUN_10032b40 at 10032b40

void FUN_10032b40(void)

{
  FUN_1000a150(&DAT_100445e8,L"J1708");
  _atexit(FUN_10034f70);
  return;
}



// Function: FUN_10032b70 at 10032b70

void FUN_10032b70(void)

{
  FUN_1000a150(&DAT_10044604,L"J1587/J1708");
  _atexit(FUN_10034f90);
  return;
}



// Function: FUN_10032ba0 at 10032ba0

void FUN_10032ba0(void)

{
  FUN_1000a150(&DAT_10044ce8,L"INLINE");
  _atexit(FUN_10034fb0);
  return;
}



// Function: FUN_10032bd0 at 10032bd0

void FUN_10032bd0(void)

{
  FUN_1000a150(&DAT_100445b0,L"INLINE I");
  _atexit(FUN_10034fd0);
  return;
}



// Function: FUN_10032c00 at 10032c00

void FUN_10032c00(void)

{
  FUN_1000a150(&DAT_10044594,L"INLINE/INLINE I");
  _atexit(FUN_10034ff0);
  return;
}



// Function: FUN_10032c30 at 10032c30

void FUN_10032c30(void)

{
  FUN_1000a150(&DAT_100449f4,L"INLINE II");
  _atexit(FUN_10035010);
  return;
}



// Function: FUN_10032c60 at 10032c60

void FUN_10032c60(void)

{
  FUN_1000a150(&DAT_1004455c,L"INLINE4");
  _atexit(FUN_10035030);
  return;
}



// Function: FUN_10032c90 at 10032c90

void FUN_10032c90(void)

{
  FUN_1000a150(&DAT_10045408,L"INLINE5");
  _atexit(FUN_10035050);
  return;
}



// Function: FUN_10032cc0 at 10032cc0

void FUN_10032cc0(void)

{
  FUN_1000a150(&DAT_10044540,L"INLINE4/5");
  _atexit(FUN_10035070);
  return;
}



// Function: FUN_10032cf0 at 10032cf0

void FUN_10032cf0(void)

{
  FUN_1000a150(&DAT_10044578,L"INLINE6");
  _atexit(FUN_10035090);
  return;
}



// Function: FUN_10032d20 at 10032d20

void FUN_10032d20(void)

{
  FUN_1000a150(&DAT_100449bc,L"{CADD2EE2-8AA3-4402-8EC4-949B13AA962A}");
  _atexit(FUN_100350b0);
  return;
}



// Function: FUN_10032d50 at 10032d50

void FUN_10032d50(void)

{
  FUN_1000a150(&DAT_10044d04,L"{2A132C51-A671-4b9e-8A55-0ADB45DBE1CD}");
  _atexit(FUN_100350d0);
  return;
}



// Function: FUN_10032d80 at 10032d80

void FUN_10032d80(void)

{
  FUN_1000a150(&DAT_1004463c,L"{47A83CB5-7840-4030-82F0-F1889C443529}");
  _atexit(FUN_100350f0);
  return;
}



// Function: FUN_10032db0 at 10032db0

void FUN_10032db0(void)

{
  FUN_1000a150(&DAT_10044620,L"{BE80DBEA-4A7A-4069-B89C-0F7C62592BF5}");
  _atexit(FUN_10035110);
  return;
}



// Function: FUN_10032de0 at 10032de0

void FUN_10032de0(void)

{
  FUN_1000a150(&DAT_100445cc,L"COM");
  _atexit(FUN_10035130);
  return;
}



// Function: FUN_10032e10 at 10032e10

void FUN_10032e10(void)

{
  FUN_1000a150(&DAT_100455ec,L"USB");
  _atexit(FUN_10035150);
  return;
}



// Function: FUN_10032e40 at 10032e40

void FUN_10032e40(void)

{
  FUN_1000a150(&DAT_10044ec4,L"COM Port Auto Detect");
  _atexit(FUN_10035170);
  return;
}



// Function: FUN_10032e70 at 10032e70

void FUN_10032e70(void)

{
  FUN_1000a150(&DAT_10045440,L"Local");
  _atexit(FUN_10035190);
  return;
}



// Function: FUN_10032ea0 at 10032ea0

void FUN_10032ea0(void)

{
  FUN_1000a150(&DAT_10044d3c,L"C:\\Intelect\\INSITE\\icldf");
  _atexit(FUN_100351b0);
  return;
}



// Function: FUN_10032ed0 at 10032ed0

void FUN_10032ed0(void)

{
  FUN_1000a150(&DAT_10044ab8,L"Serial");
  _atexit(FUN_100351d0);
  return;
}



// Function: FUN_10032f00 at 10032f00

void FUN_10032f00(void)

{
  FUN_1000a150(&DAT_10044a9c,L"Parallel");
  _atexit(FUN_100351f0);
  return;
}



// Function: FUN_10032f30 at 10032f30

void FUN_10032f30(void)

{
  FUN_1000a150(&DAT_100446c8,L"Simulator");
  _atexit(FUN_10035210);
  return;
}



// Function: FUN_10032f60 at 10032f60

void FUN_10032f60(void)

{
  FUN_1000a150(&DAT_100454e8,L"NGT");
  _atexit(FUN_10035230);
  return;
}



// Function: FUN_10032f90 at 10032f90

void FUN_10032f90(void)

{
  FUN_1000a150(&DAT_10044690,L"RP1210A");
  _atexit(FUN_10035250);
  return;
}



// Function: FUN_10032fc0 at 10032fc0

void FUN_10032fc0(void)

{
  FUN_1000a150(&DAT_10045608,L"USB");
  _atexit(FUN_10035270);
  return;
}



// Function: FUN_10033000 at 10033000

void FUN_10033000(void)

{
  FUN_1000a150(&DAT_100446ac,L"Image");
  _atexit(FUN_10035290);
  return;
}



// Function: FUN_10033030 at 10033030

void FUN_10033030(void)

{
  FUN_1000a150(&DAT_10044a2c,L"AutoConfigure");
  _atexit(FUN_100352b0);
  return;
}



// Function: FUN_10033060 at 10033060

void FUN_10033060(void)

{
  FUN_1000a150(&DAT_10044a80,L"0");
  _atexit(FUN_100352d0);
  return;
}



// Function: FUN_10033090 at 10033090

void FUN_10033090(void)

{
  FUN_1000a150(&DAT_10044e1c,L"0");
  _atexit(FUN_100352f0);
  return;
}



// Function: FUN_100330c0 at 100330c0

void FUN_100330c0(void)

{
  FUN_1000a150(&DAT_10044e70,L"2");
  _atexit(FUN_10035310);
  return;
}



// Function: FUN_100330f0 at 100330f0

void FUN_100330f0(void)

{
  FUN_1000a150(&DAT_10044d20,L"4");
  _atexit(FUN_10035330);
  return;
}



// Function: FUN_10033120 at 10033120

void FUN_10033120(void)

{
  FUN_1000a150(&DAT_1004471c,L"4");
  _atexit(FUN_10035350);
  return;
}



// Function: FUN_10033150 at 10033150

void FUN_10033150(void)

{
  FUN_1000a150(&DAT_10044700,L"4");
  _atexit(FUN_10035370);
  return;
}



// Function: FUN_10033180 at 10033180

void FUN_10033180(void)

{
  FUN_1000a150(&DAT_10044e8c,L"1");
  _atexit(FUN_10035390);
  return;
}



// Function: FUN_100331b0 at 100331b0

void FUN_100331b0(void)

{
  FUN_1000a150(&DAT_100446e4,L"RP1210A");
  _atexit(FUN_100353b0);
  return;
}



// Function: FUN_100331e0 at 100331e0

void FUN_100331e0(void)

{
  FUN_1000a150(&DAT_1004530c,L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\Users\\Global");
  _atexit(FUN_100353d0);
  return;
}



// Function: FUN_10033210 at 10033210

void FUN_10033210(void)

{
  FUN_1000a150(&DAT_10045398,L"SecServicePath");
  _atexit(FUN_100353f0);
  return;
}



// Function: FUN_10033240 at 10033240

void FUN_10033240(void)

{
  FUN_1000a150(&DAT_10044524,L"kAIsHANGlE");
  _atexit(FUN_10035410);
  return;
}



// Function: FUN_10033270 at 10033270

void FUN_10033270(void)

{
  FUN_1000a150(&DAT_10044a10,L"kUANdIAOlE");
  _atexit(FUN_10035430);
  return;
}



// Function: FUN_100332a0 at 100332a0

void FUN_100332a0(void)

{
  FUN_1000a150(&DAT_100444d0,L"UMUsersConfig");
  _atexit(FUN_10035450);
  return;
}



// Function: FUN_100332d0 at 100332d0

void FUN_100332d0(void)

{
  FUN_1000a150(&DAT_10044508,L"UMPredefinedConfig");
  _atexit(FUN_10035470);
  return;
}



// Function: FUN_10033300 at 10033300

void FUN_10033300(void)

{
  FUN_1000a150(&DAT_100444ec,L"UMCurrentUser");
  _atexit(FUN_10035490);
  return;
}



// Function: FUN_10033330 at 10033330

void FUN_10033330(void)

{
  FUN_1000a150(&DAT_100455cc,L"UMGroupRights");
  _atexit(FUN_100354b0);
  return;
}



// Function: FUN_10033360 at 10033360

void FUN_10033360(void)

{
  FUN_1000a150(&DAT_100449d8,L"ResourceDLL");
  _atexit(FUN_100354d0);
  return;
}



// Function: FUN_10033390 at 10033390

void FUN_10033390(void)

{
  FUN_1000a150(&DAT_100444b4,L"388");
  _atexit(FUN_100354f0);
  return;
}



// Function: FUN_100333c0 at 100333c0

void FUN_100333c0(void)

{
  FUN_10016c70(&DAT_10044c78,(undefined4 *)&DAT_100450f8,L"\\Users");
  _atexit(FUN_10035530);
  return;
}



// Function: FUN_10033400 at 10033400

void FUN_10033400(void)

{
  FUN_10016c70(&DAT_10044ee0,(undefined4 *)&DAT_100450f8,L"\\Users\\Templates\\CumminsDefault");
  _atexit(FUN_10035510);
  return;
}



// Function: FUN_10033440 at 10033440

void FUN_10033440(void)

{
  FUN_1000a150(&DAT_10044bb4,L"\\");
  _atexit(FUN_10035550);
  return;
}



// Function: FUN_10033470 at 10033470

void FUN_10033470(void)

{
  FUN_1000a150(&DAT_10044ccc,L"\\Files");
  _atexit(FUN_10035570);
  return;
}



// Function: FUN_100334a0 at 100334a0

void FUN_100334a0(void)

{
  FUN_1000a150(&DAT_10045328,L"Path");
  _atexit(FUN_10035590);
  return;
}



// Function: FUN_100334d0 at 100334d0

void FUN_100334d0(void)

{
  FUN_1000a150(&DAT_10044b0c,L"\\Appearance");
  _atexit(FUN_100355b0);
  return;
}



// Function: FUN_10033500 at 10033500

void FUN_10033500(void)

{
  FUN_1000a150(&DAT_10044b7c,L"\\Backgrounds");
  _atexit(FUN_100355d0);
  return;
}



// Function: FUN_10033530 at 10033530

void FUN_10033530(void)

{
  FUN_1000a150(&DAT_10044ea8,L"\\Grid Lines");
  _atexit(FUN_100355f0);
  return;
}



// Function: FUN_10033560 at 10033560

void FUN_10033560(void)

{
  FUN_1000a150(&DAT_10045504,L"\\Positioning");
  _atexit(FUN_10035610);
  return;
}



// Function: FUN_10033590 at 10033590

void FUN_10033590(void)

{
  FUN_1000a150(&DAT_10044c08,L"\\Text");
  _atexit(FUN_10035630);
  return;
}



// Function: FUN_100335c0 at 100335c0

void FUN_100335c0(void)

{
  FUN_1000a150(&DAT_10044bec,L"GroupWinCols");
  _atexit(FUN_10035650);
  return;
}



// Function: FUN_100335f0 at 100335f0

void FUN_100335f0(void)

{
  FUN_1000a150(&DAT_10044cb0,L"ParamWinCols");
  _atexit(FUN_10035670);
  return;
}



// Function: FUN_10033620 at 10033620

void FUN_10033620(void)

{
  FUN_1000a150(&DAT_10044c40,L"TextWinCols");
  _atexit(FUN_10035690);
  return;
}



// Function: FUN_10033650 at 10033650

void FUN_10033650(void)

{
  FUN_1000a150(&DAT_10044d58,L"Bold");
  _atexit(FUN_100356b0);
  return;
}



// Function: FUN_10033680 at 10033680

void FUN_10033680(void)

{
  FUN_1000a150(&DAT_10044b44,L"Color");
  _atexit(FUN_100356d0);
  return;
}



// Function: FUN_100336b0 at 100336b0

void FUN_100336b0(void)

{
  FUN_1000a150(&DAT_10044b28,L"Italic");
  _atexit(FUN_100356f0);
  return;
}



// Function: FUN_100336e0 at 100336e0

void FUN_100336e0(void)

{
  FUN_1000a150(&DAT_10044c24,L"Name");
  _atexit(FUN_10035710);
  return;
}



// Function: FUN_10033710 at 10033710

void FUN_10033710(void)

{
  FUN_1000a150(&DAT_10044dac,L"Size");
  _atexit(FUN_10035730);
  return;
}



// Function: FUN_10033740 at 10033740

void FUN_10033740(void)

{
  FUN_1000a150(&DAT_10044bd0,L"Strikethrough");
  _atexit(FUN_10035750);
  return;
}



// Function: FUN_10033770 at 10033770

void FUN_10033770(void)

{
  FUN_1000a150(&DAT_10044c5c,L"Style");
  _atexit(FUN_10035770);
  return;
}



// Function: FUN_100337a0 at 100337a0

void FUN_100337a0(void)

{
  FUN_1000a150(&DAT_10044b60,L"Underline");
  _atexit(FUN_10035790);
  return;
}



// Function: FUN_100337d0 at 100337d0

void FUN_100337d0(void)

{
  FUN_1000a150(&DAT_10044b98,L"TRUE");
  _atexit(FUN_100357b0);
  return;
}



// Function: FUN_10033800 at 10033800

void FUN_10033800(void)

{
  FUN_1000a150(&DAT_10044c94,L"FALSE");
  _atexit(FUN_100357d0);
  return;
}



// Function: FUN_10033830 at 10033830

void FUN_10033830(void)

{
  FUN_1000a150(&DAT_1004514c,L"");
  _atexit(FUN_100357f0);
  return;
}



// Function: FUN_10033860 at 10033860

void FUN_10033860(void)

{
  FUN_1000a150(&DAT_10045168,L"NONE");
  _atexit(FUN_10035810);
  return;
}



// Function: FUN_10033890 at 10033890

void FUN_10033890(void)

{
  FUN_1000a150(&DAT_10045360,L"Basic");
  _atexit(FUN_10035830);
  return;
}



// Function: FUN_100338c0 at 100338c0

void FUN_100338c0(void)

{
  FUN_1000a150(&DAT_100451bc,L"RSGR");
  _atexit(FUN_10035850);
  return;
}



// Function: FUN_100338f0 at 100338f0

void FUN_100338f0(void)

{
  FUN_1000a150(&DAT_10045264,L"Lite");
  _atexit(FUN_10035870);
  return;
}



// Function: FUN_10033920 at 10033920

void FUN_10033920(void)

{
  FUN_1000a150(&DAT_100452b8,L"Industrial / Power Generation Applications");
  _atexit(FUN_10035890);
  return;
}



// Function: FUN_10033950 at 10033950

void FUN_10033950(void)

{
  FUN_1000a150(&DAT_1004522c,L"Pro");
  _atexit(FUN_100358b0);
  return;
}



// Function: FUN_10033980 at 10033980

void FUN_10033980(void)

{
  FUN_1000a150(&DAT_100453ec,L"OBD-RSGR");
  _atexit(FUN_100358d0);
  return;
}



// Function: FUN_100339b0 at 100339b0

void FUN_100339b0(void)

{
  FUN_1000a150(&DAT_100451a0,L"OBD");
  _atexit(FUN_100358f0);
  return;
}



// Function: FUN_100339e0 at 100339e0

void FUN_100339e0(void)

{
  FUN_1000a150(&DAT_100452f0,L"Pro Plus");
  _atexit(FUN_10035910);
  return;
}



// Function: FUN_10033a10 at 10033a10

void FUN_10033a10(void)

{
  FUN_1000a150(&DAT_100451f4,L"RSGR Plus");
  _atexit(FUN_10035930);
  return;
}



// Function: FUN_10033a40 at 10033a40

void FUN_10033a40(void)

{
  FUN_1000a150(&DAT_100451d8,L"RSGNR");
  _atexit(FUN_10035950);
  return;
}



// Function: FUN_10033a70 at 10033a70

void FUN_10033a70(void)

{
  FUN_1000a150(&DAT_100453b4,L"NoAutomotive");
  _atexit(FUN_10035970);
  return;
}



// Function: FUN_10033aa0 at 10033aa0

void FUN_10033aa0(void)

{
  FUN_1000a150(&DAT_1004529c,L"OBDRSGNR");
  _atexit(FUN_10035990);
  return;
}



// Function: FUN_10033ad0 at 10033ad0

void FUN_10033ad0(void)

{
  FUN_1000a150(&DAT_100452d4,L"OBD");
  _atexit(FUN_100359b0);
  return;
}



// Function: FUN_10033b00 at 10033b00

void FUN_10033b00(void)

{
  FUN_1000a150(&DAT_10045280,L"PreProdSupp");
  _atexit(FUN_100359d0);
  return;
}



// Function: FUN_10033b30 at 10033b30

void FUN_10033b30(void)

{
  FUN_1000a150(&DAT_10045210,L"NProdSupp");
  _atexit(FUN_100359f0);
  return;
}



// Function: FUN_10033b60 at 10033b60

void FUN_10033b60(void)

{
  FUN_1000a150(&DAT_10045248,L"NOBDRSGR");
  _atexit(FUN_10035a10);
  return;
}



// Function: FUN_10033b90 at 10033b90

void FUN_10033b90(void)

{
  FUN_1000a150(&DAT_10045184,L"NOBD");
  _atexit(FUN_10035a30);
  return;
}



// Function: FUN_10033bc0 at 10033bc0

void FUN_10033bc0(void)

{
  return;
}



// Function: FUN_10033be0 at 10033be0

void FUN_10033be0(void)

{
  FUN_1001f3e0((undefined4 *)&DAT_10045640);
  return;
}



// Function: FUN_10033c00 at 10033c00

void FUN_10033c00(void)

{
  FUN_1000a150(&DAT_10045684,L"\r");
  _atexit(FUN_10035a50);
  return;
}



// Function: FUN_10033c30 at 10033c30

void FUN_10033c30(void)

{
  FUN_1000a150(&DAT_10045668,L"\n");
  _atexit(FUN_10035a70);
  return;
}



// Function: FUN_10033c60 at 10033c60

void FUN_10033c60(void)

{
  FUN_1000a150(&DAT_1004564c,L"\\n");
  _atexit(FUN_10035a90);
  return;
}



// Function: FUN_10033c90 at 10033c90

void FUN_10033c90(void)

{
  FUN_1000a150(&DAT_10045810,L"\\r");
  _atexit(FUN_10035ab0);
  return;
}



// Function: FUN_10033cc0 at 10033cc0

void FUN_10033cc0(void)

{
  FUN_1000a150(&DAT_10045764,L"EN");
  _atexit(FUN_10035ad0);
  return;
}



// Function: FUN_10033cf0 at 10033cf0

void FUN_10033cf0(void)

{
  FUN_1000a150(&DAT_10045864,L"ES");
  _atexit(FUN_10035af0);
  return;
}



// Function: FUN_10033d20 at 10033d20

void FUN_10033d20(void)

{
  FUN_1000a150(&DAT_100456a0,L"PT");
  _atexit(FUN_10035b10);
  return;
}



// Function: FUN_10033d50 at 10033d50

void FUN_10033d50(void)

{
  FUN_1000a150(&DAT_100457bc,L"TR");
  _atexit(FUN_10035b30);
  return;
}



// Function: FUN_10033d80 at 10033d80

void FUN_10033d80(void)

{
  FUN_1000a150(&DAT_1004582c,L"ZH");
  _atexit(FUN_10035b50);
  return;
}



// Function: FUN_10033db0 at 10033db0

void FUN_10033db0(void)

{
  FUN_1000a150(&DAT_100457f4,L"JA");
  _atexit(FUN_10035b70);
  return;
}



// Function: FUN_10033de0 at 10033de0

void FUN_10033de0(void)

{
  FUN_1000a150(&DAT_10045848,L"FR");
  _atexit(FUN_10035b90);
  return;
}



// Function: FUN_10033e10 at 10033e10

void FUN_10033e10(void)

{
  FUN_1000a150(&DAT_10045784,L"DE");
  _atexit(FUN_10035bb0);
  return;
}



// Function: FUN_10033e40 at 10033e40

void FUN_10033e40(void)

{
  FUN_1000a150(&DAT_10045748,L"IT");
  _atexit(FUN_10035bd0);
  return;
}



// Function: FUN_10033e70 at 10033e70

void FUN_10033e70(void)

{
  FUN_1000a150(&DAT_100456bc,L"KO");
  _atexit(FUN_10035bf0);
  return;
}



// Function: FUN_10033ea0 at 10033ea0

void FUN_10033ea0(void)

{
  FUN_1000a150(&DAT_100457a0,L"RU");
  _atexit(FUN_10035c10);
  return;
}



// Function: FUN_10033ed0 at 10033ed0

void FUN_10033ed0(void)

{
  FUN_1000a150(&DAT_100456d8,L"DA");
  _atexit(FUN_10035c30);
  return;
}



// Function: FUN_10033f00 at 10033f00

void FUN_10033f00(void)

{
  FUN_1000a150(&DAT_10045710,L"NL");
  _atexit(FUN_10035c50);
  return;
}



// Function: FUN_10033f30 at 10033f30

void FUN_10033f30(void)

{
  FUN_1000a150(&DAT_100457d8,L"FI");
  _atexit(FUN_10035c70);
  return;
}



// Function: FUN_10033f60 at 10033f60

void FUN_10033f60(void)

{
  FUN_1000a150(&DAT_10045880,L"NO");
  _atexit(FUN_10035c90);
  return;
}



// Function: FUN_10033f90 at 10033f90

void FUN_10033f90(void)

{
  FUN_1000a150(&DAT_100456f4,L"SV");
  _atexit(FUN_10035cb0);
  return;
}



// Function: FUN_10033fc0 at 10033fc0

void FUN_10033fc0(void)

{
  FUN_1000a150(&DAT_1004572c,L"ID");
  _atexit(FUN_10035cd0);
  return;
}



// Function: FUN_10034000 at 10034000

void FUN_10034000(void)

{
  FUN_1000ac40(&DAT_10045780,0x10037468);
  _atexit(FUN_10035cf0);
  return;
}



// Function: FUN_10034030 at 10034030

void FUN_10034030(void)

{
  FUN_1000ac40(&DAT_1004589c,0x10037430);
  _atexit(FUN_10035d10);
  return;
}



// Function: FUN_10034060 at 10034060

void FUN_10034060(void)

{
  FUN_1000ac40(&DAT_100458a0,0x1003744c);
  _atexit(FUN_10035d30);
  return;
}



// Function: FUN_10034100 at 10034100

void FUN_10034100(void)

{
  FUN_1000aca0(&DAT_10043c00);
  return;
}



// Function: FUN_10034120 at 10034120

void FUN_10034120(void)

{
  FUN_1000aca0(&DAT_10043c1c);
  return;
}



// Function: FUN_10034140 at 10034140

void FUN_10034140(void)

{
  FUN_1000aca0(&DAT_10043c38);
  return;
}



// Function: FUN_10034160 at 10034160

void FUN_10034160(void)

{
  FUN_10007720((undefined4 *)&DAT_10043c54);
  return;
}



// Function: FUN_10034180 at 10034180

void FUN_10034180(void)

{
  FUN_1000aca0(&DAT_10043c58);
  return;
}



// Function: FUN_100341a0 at 100341a0

void FUN_100341a0(void)

{
  FUN_1000aca0(&DAT_10043c74);
  return;
}



// Function: FUN_100341c0 at 100341c0

void FUN_100341c0(void)

{
  _eh_vector_destructor_iterator_(&DAT_10043c90,0x1c,0x10,FUN_1000aca0);
  return;
}



// Function: FUN_100341f0 at 100341f0

void FUN_100341f0(void)

{
  FUN_1000aca0(&DAT_10043e50);
  return;
}



// Function: FUN_10034210 at 10034210

void FUN_10034210(void)

{
  FUN_1000aca0(&DAT_10043e6c);
  return;
}



// Function: FUN_10034230 at 10034230

void FUN_10034230(void)

{
  FUN_10007720((undefined4 *)&DAT_10043e88);
  return;
}



// Function: FUN_10034250 at 10034250

void FUN_10034250(void)

{
  FUN_1000aca0(&DAT_10043e8c);
  return;
}



// Function: FUN_10034270 at 10034270

void FUN_10034270(void)

{
  FUN_1000aee0((undefined4 *)&DAT_10043ea8);
  return;
}



// Function: FUN_10034290 at 10034290

void FUN_10034290(void)

{
  FUN_1000aca0(&DAT_10043ed8);
  return;
}



// Function: FUN_100342b0 at 100342b0

void FUN_100342b0(void)

{
  FUN_1000aca0(&DAT_10043ef4);
  return;
}



// Function: FUN_100342d0 at 100342d0

void FUN_100342d0(void)

{
  FUN_1000aca0(&DAT_10043f10);
  return;
}



// Function: FUN_100342f0 at 100342f0

void FUN_100342f0(void)

{
  FUN_10007720((undefined4 *)&DAT_10043f2c);
  return;
}



// Function: FUN_10034310 at 10034310

void FUN_10034310(void)

{
  FUN_1000aca0(&DAT_10043f30);
  return;
}



// Function: FUN_10034330 at 10034330

void FUN_10034330(void)

{
  FUN_1000aca0(&DAT_10043f4c);
  return;
}



// Function: FUN_10034350 at 10034350

void FUN_10034350(void)

{
  _eh_vector_destructor_iterator_(&DAT_10043f68,0x1c,0x10,FUN_1000aca0);
  return;
}



// Function: FUN_10034380 at 10034380

void FUN_10034380(void)

{
  FUN_1000aca0(&DAT_10044128);
  return;
}



// Function: FUN_100343a0 at 100343a0

void FUN_100343a0(void)

{
  FUN_1000aca0(&DAT_10044144);
  return;
}



// Function: FUN_100343c0 at 100343c0

void FUN_100343c0(void)

{
  FUN_10007720((undefined4 *)&DAT_10044160);
  return;
}



// Function: FUN_100343e0 at 100343e0

void FUN_100343e0(void)

{
  FUN_1000aca0(&DAT_10044164);
  return;
}



// Function: FUN_10034400 at 10034400

void FUN_10034400(void)

{
  FUN_100179f0(&DAT_10044180);
  return;
}



// Function: FUN_10034420 at 10034420

void FUN_10034420(void)

{
  FUN_1000aca0(&DAT_100441ac);
  return;
}



// Function: FUN_10034440 at 10034440

void FUN_10034440(void)

{
  FUN_1000aca0(&DAT_10044190);
  return;
}



// Function: FUN_10034460 at 10034460

void FUN_10034460(void)

{
  FUN_1000aca0(&DAT_1004421c);
  return;
}



// Function: FUN_10034480 at 10034480

void FUN_10034480(void)

{
  FUN_1000aca0(&DAT_100441e4);
  return;
}



// Function: FUN_100344a0 at 100344a0

void FUN_100344a0(void)

{
  FUN_1000aca0(&DAT_100441c8);
  return;
}



// Function: FUN_100344c0 at 100344c0

void FUN_100344c0(void)

{
  FUN_1000aca0(&DAT_10044200);
  return;
}



// Function: FUN_100344e0 at 100344e0

void FUN_100344e0(void)

{
  FUN_1000aca0(&DAT_10044240);
  return;
}



// Function: FUN_10034500 at 10034500

void FUN_10034500(void)

{
  FUN_1000aca0(&DAT_1004425c);
  return;
}



// Function: FUN_10034520 at 10034520

void FUN_10034520(void)

{
  FUN_1000aca0(&DAT_10044278);
  return;
}



// Function: FUN_10034540 at 10034540

void FUN_10034540(void)

{
  FUN_10007720((undefined4 *)&DAT_10044294);
  return;
}



// Function: FUN_10034560 at 10034560

void FUN_10034560(void)

{
  FUN_1000aca0(&DAT_10044298);
  return;
}



// Function: FUN_10034580 at 10034580

void FUN_10034580(void)

{
  FUN_1000aca0(&DAT_100442b4);
  return;
}



// Function: FUN_100345a0 at 100345a0

void FUN_100345a0(void)

{
  _eh_vector_destructor_iterator_(&DAT_100442d0,0x1c,0x10,FUN_1000aca0);
  return;
}



// Function: FUN_100345d0 at 100345d0

void FUN_100345d0(void)

{
  FUN_1000aca0(&DAT_10044984);
  return;
}



// Function: FUN_100345f0 at 100345f0

void FUN_100345f0(void)

{
  FUN_1000aca0(&DAT_10044968);
  return;
}



// Function: FUN_10034610 at 10034610

void FUN_10034610(void)

{
  FUN_1000aca0(&DAT_10044498);
  return;
}



// Function: FUN_10034630 at 10034630

void FUN_10034630(void)

{
  FUN_1000aca0(&DAT_10045114);
  return;
}



// Function: FUN_10034650 at 10034650

void FUN_10034650(void)

{
  FUN_1000aca0(&DAT_10044fc0);
  return;
}



// Function: FUN_10034670 at 10034670

void FUN_10034670(void)

{
  FUN_1000aca0(&DAT_100454b0);
  return;
}



// Function: FUN_10034690 at 10034690

void FUN_10034690(void)

{
  FUN_1000aca0(&DAT_10044efc);
  return;
}



// Function: FUN_100346b0 at 100346b0

void FUN_100346b0(void)

{
  FUN_1000aca0(&DAT_10045018);
  return;
}



// Function: FUN_100346d0 at 100346d0

void FUN_100346d0(void)

{
  FUN_1000aca0(&DAT_10045344);
  return;
}



// Function: FUN_100346f0 at 100346f0

void FUN_100346f0(void)

{
  FUN_1000aca0(&DAT_10045050);
  return;
}



// Function: FUN_10034710 at 10034710

void FUN_10034710(void)

{
  FUN_1000aca0(&DAT_100453d0);
  return;
}



// Function: FUN_10034730 at 10034730

void FUN_10034730(void)

{
  FUN_1000aca0(&DAT_10044fe0);
  return;
}



// Function: FUN_10034750 at 10034750

void FUN_10034750(void)

{
  FUN_1000aca0(&DAT_10044fa4);
  return;
}



// Function: FUN_10034770 at 10034770

void FUN_10034770(void)

{
  FUN_1000aca0(&DAT_10044f18);
  return;
}



// Function: FUN_10034790 at 10034790

void FUN_10034790(void)

{
  FUN_1000aca0(&DAT_10044ffc);
  return;
}



// Function: FUN_100347b0 at 100347b0

void FUN_100347b0(void)

{
  FUN_1000aca0(&DAT_10044f34);
  return;
}



// Function: FUN_100347d0 at 100347d0

void FUN_100347d0(void)

{
  FUN_1000aca0(&DAT_10044f6c);
  return;
}



// Function: FUN_100347f0 at 100347f0

void FUN_100347f0(void)

{
  FUN_1000aca0(&DAT_10045034);
  return;
}



// Function: FUN_10034810 at 10034810

void FUN_10034810(void)

{
  FUN_1000aca0(&DAT_10045558);
  return;
}



// Function: FUN_10034830 at 10034830

void FUN_10034830(void)

{
  FUN_1000aca0(&DAT_10044f50);
  return;
}



// Function: FUN_10034850 at 10034850

void FUN_10034850(void)

{
  FUN_1000aca0(&DAT_10044f88);
  return;
}



// Function: FUN_10034870 at 10034870

void FUN_10034870(void)

{
  FUN_10007720((undefined4 *)&DAT_10044fdc);
  return;
}



// Function: FUN_10034890 at 10034890

void FUN_10034890(void)

{
  FUN_10007720((undefined4 *)&DAT_100455c8);
  return;
}



// Function: FUN_100348b0 at 100348b0

void FUN_100348b0(void)

{
  FUN_10007720((undefined4 *)&DAT_100455e8);
  return;
}



// Function: FUN_100348d0 at 100348d0

void FUN_100348d0(void)

{
  FUN_1000aca0(&DAT_10044914);
  return;
}



// Function: FUN_100348f0 at 100348f0

void FUN_100348f0(void)

{
  FUN_1000aca0(&DAT_10044930);
  return;
}



// Function: FUN_10034910 at 10034910

void FUN_10034910(void)

{
  FUN_1000aca0(&DAT_100450f8);
  return;
}



// Function: FUN_10034930 at 10034930

void FUN_10034930(void)

{
  FUN_1000aca0(&DAT_1004537c);
  return;
}



// Function: FUN_10034950 at 10034950

void FUN_10034950(void)

{
  FUN_1000aca0(&DAT_10044ad4);
  return;
}



// Function: FUN_10034970 at 10034970

void FUN_10034970(void)

{
  FUN_1000aca0(&DAT_1004545c);
  return;
}



// Function: FUN_10034990 at 10034990

void FUN_10034990(void)

{
  FUN_1000aca0(&DAT_10044738);
  return;
}



// Function: FUN_100349b0 at 100349b0

void FUN_100349b0(void)

{
  FUN_1000aca0(&DAT_10044754);
  return;
}



// Function: FUN_100349d0 at 100349d0

void FUN_100349d0(void)

{
  FUN_1000aca0(&DAT_10045574);
  return;
}



// Function: FUN_100349f0 at 100349f0

void FUN_100349f0(void)

{
  FUN_1000aca0(&DAT_10044658);
  return;
}



// Function: FUN_10034a10 at 10034a10

void FUN_10034a10(void)

{
  FUN_1000aca0(&DAT_100449a0);
  return;
}



// Function: FUN_10034a30 at 10034a30

void FUN_10034a30(void)

{
  FUN_1000aca0(&DAT_10044674);
  return;
}



// Function: FUN_10034a50 at 10034a50

void FUN_10034a50(void)

{
  FUN_1000aca0(&DAT_10044a48);
  return;
}



// Function: FUN_10034a70 at 10034a70

void FUN_10034a70(void)

{
  FUN_1000aca0(&DAT_10045424);
  return;
}



// Function: FUN_10034a90 at 10034a90

void FUN_10034a90(void)

{
  FUN_1000aca0(&DAT_100454cc);
  return;
}



// Function: FUN_10034ab0 at 10034ab0

void FUN_10034ab0(void)

{
  FUN_1000aca0(&DAT_10044af0);
  return;
}



// Function: FUN_10034ad0 at 10034ad0

void FUN_10034ad0(void)

{
  FUN_1000aca0(&DAT_10044dc8);
  return;
}



// Function: FUN_10034af0 at 10034af0

void FUN_10034af0(void)

{
  FUN_1000aca0(&DAT_10044d90);
  return;
}



// Function: FUN_10034b10 at 10034b10

void FUN_10034b10(void)

{
  FUN_1000aca0(&DAT_10044834);
  return;
}



// Function: FUN_10034b30 at 10034b30

void FUN_10034b30(void)

{
  FUN_1000aca0(&DAT_10044de4);
  return;
}



// Function: FUN_10034b50 at 10034b50

void FUN_10034b50(void)

{
  FUN_1000aca0(&DAT_10044d74);
  return;
}



// Function: FUN_10034b70 at 10034b70

void FUN_10034b70(void)

{
  FUN_1000aca0(&DAT_100448c0);
  return;
}



// Function: FUN_10034b90 at 10034b90

void FUN_10034b90(void)

{
  FUN_1000aca0(&DAT_10044e38);
  return;
}



// Function: FUN_10034bb0 at 10034bb0

void FUN_10034bb0(void)

{
  FUN_1000aca0(&DAT_100448dc);
  return;
}



// Function: FUN_10034bd0 at 10034bd0

void FUN_10034bd0(void)

{
  FUN_1000aca0(&DAT_10045478);
  return;
}



// Function: FUN_10034bf0 at 10034bf0

void FUN_10034bf0(void)

{
  FUN_1000aca0(&DAT_100450c0);
  return;
}



// Function: FUN_10034c10 at 10034c10

void FUN_10034c10(void)

{
  FUN_1000aca0(&DAT_10044850);
  return;
}



// Function: FUN_10034c30 at 10034c30

void FUN_10034c30(void)

{
  FUN_1000aca0(&DAT_1004506c);
  return;
}



// Function: FUN_10034c50 at 10034c50

void FUN_10034c50(void)

{
  FUN_1000aca0(&DAT_10045590);
  return;
}



// Function: FUN_10034c70 at 10034c70

void FUN_10034c70(void)

{
  FUN_1000aca0(&DAT_100448a4);
  return;
}



// Function: FUN_10034c90 at 10034c90

void FUN_10034c90(void)

{
  FUN_1000aca0(&DAT_10045130);
  return;
}



// Function: FUN_10034cb0 at 10034cb0

void FUN_10034cb0(void)

{
  FUN_1000aca0(&DAT_1004486c);
  return;
}



// Function: FUN_10034cd0 at 10034cd0

void FUN_10034cd0(void)

{
  FUN_1000aca0(&DAT_10044888);
  return;
}



// Function: FUN_10034cf0 at 10034cf0

void FUN_10034cf0(void)

{
  FUN_1000aca0(&DAT_10045520);
  return;
}



// Function: FUN_10034d10 at 10034d10

void FUN_10034d10(void)

{
  FUN_1000aca0(&DAT_1004553c);
  return;
}



// Function: FUN_10034d30 at 10034d30

void FUN_10034d30(void)

{
  FUN_1000aca0(&DAT_10045624);
  return;
}



// Function: FUN_10034d50 at 10034d50

void FUN_10034d50(void)

{
  FUN_1000aca0(&DAT_10044818);
  return;
}



// Function: FUN_10034d70 at 10034d70

void FUN_10034d70(void)

{
  FUN_1000aca0(&DAT_100447fc);
  return;
}



// Function: FUN_10034d90 at 10034d90

void FUN_10034d90(void)

{
  FUN_1000aca0(&DAT_10045088);
  return;
}



// Function: FUN_10034db0 at 10034db0

void FUN_10034db0(void)

{
  FUN_1000aca0(&DAT_100447e0);
  return;
}



// Function: FUN_10034dd0 at 10034dd0

void FUN_10034dd0(void)

{
  FUN_1000aca0(&DAT_100455ac);
  return;
}



// Function: FUN_10034df0 at 10034df0

void FUN_10034df0(void)

{
  FUN_1000aca0(&DAT_1004494c);
  return;
}



// Function: FUN_10034e10 at 10034e10

void FUN_10034e10(void)

{
  FUN_1000aca0(&DAT_10045494);
  return;
}



// Function: FUN_10034e30 at 10034e30

void FUN_10034e30(void)

{
  FUN_1000aca0(&DAT_100450dc);
  return;
}



// Function: FUN_10034e50 at 10034e50

void FUN_10034e50(void)

{
  FUN_1000aca0(&DAT_100447c4);
  return;
}



// Function: FUN_10034e70 at 10034e70

void FUN_10034e70(void)

{
  FUN_1000aca0(&DAT_100450a4);
  return;
}



// Function: FUN_10034e90 at 10034e90

void FUN_10034e90(void)

{
  FUN_1000aca0(&DAT_10044770);
  return;
}



// Function: FUN_10034eb0 at 10034eb0

void FUN_10034eb0(void)

{
  FUN_1000aca0(&DAT_100447a8);
  return;
}



// Function: FUN_10034ed0 at 10034ed0

void FUN_10034ed0(void)

{
  FUN_1000aca0(&DAT_1004478c);
  return;
}



// Function: FUN_10034ef0 at 10034ef0

void FUN_10034ef0(void)

{
  FUN_1000aca0(&DAT_100448f8);
  return;
}



// Function: FUN_10034f10 at 10034f10

void FUN_10034f10(void)

{
  FUN_1000aca0(&DAT_10044e54);
  return;
}



// Function: FUN_10034f30 at 10034f30

void FUN_10034f30(void)

{
  FUN_1000aca0(&DAT_10044a64);
  return;
}



// Function: FUN_10034f50 at 10034f50

void FUN_10034f50(void)

{
  FUN_1000aca0(&DAT_10044e00);
  return;
}



// Function: FUN_10034f70 at 10034f70

void FUN_10034f70(void)

{
  FUN_1000aca0(&DAT_100445e8);
  return;
}



// Function: FUN_10034f90 at 10034f90

void FUN_10034f90(void)

{
  FUN_1000aca0(&DAT_10044604);
  return;
}



// Function: FUN_10034fb0 at 10034fb0

void FUN_10034fb0(void)

{
  FUN_1000aca0(&DAT_10044ce8);
  return;
}



// Function: FUN_10034fd0 at 10034fd0

void FUN_10034fd0(void)

{
  FUN_1000aca0(&DAT_100445b0);
  return;
}



// Function: FUN_10034ff0 at 10034ff0

void FUN_10034ff0(void)

{
  FUN_1000aca0(&DAT_10044594);
  return;
}



// Function: FUN_10035010 at 10035010

void FUN_10035010(void)

{
  FUN_1000aca0(&DAT_100449f4);
  return;
}



// Function: FUN_10035030 at 10035030

void FUN_10035030(void)

{
  FUN_1000aca0(&DAT_1004455c);
  return;
}



// Function: FUN_10035050 at 10035050

void FUN_10035050(void)

{
  FUN_1000aca0(&DAT_10045408);
  return;
}



// Function: FUN_10035070 at 10035070

void FUN_10035070(void)

{
  FUN_1000aca0(&DAT_10044540);
  return;
}



// Function: FUN_10035090 at 10035090

void FUN_10035090(void)

{
  FUN_1000aca0(&DAT_10044578);
  return;
}



// Function: FUN_100350b0 at 100350b0

void FUN_100350b0(void)

{
  FUN_1000aca0(&DAT_100449bc);
  return;
}



// Function: FUN_100350d0 at 100350d0

void FUN_100350d0(void)

{
  FUN_1000aca0(&DAT_10044d04);
  return;
}



// Function: FUN_100350f0 at 100350f0

void FUN_100350f0(void)

{
  FUN_1000aca0(&DAT_1004463c);
  return;
}



// Function: FUN_10035110 at 10035110

void FUN_10035110(void)

{
  FUN_1000aca0(&DAT_10044620);
  return;
}



// Function: FUN_10035130 at 10035130

void FUN_10035130(void)

{
  FUN_1000aca0(&DAT_100445cc);
  return;
}



// Function: FUN_10035150 at 10035150

void FUN_10035150(void)

{
  FUN_1000aca0(&DAT_100455ec);
  return;
}



// Function: FUN_10035170 at 10035170

void FUN_10035170(void)

{
  FUN_1000aca0(&DAT_10044ec4);
  return;
}



// Function: FUN_10035190 at 10035190

void FUN_10035190(void)

{
  FUN_1000aca0(&DAT_10045440);
  return;
}



// Function: FUN_100351b0 at 100351b0

void FUN_100351b0(void)

{
  FUN_1000aca0(&DAT_10044d3c);
  return;
}



// Function: FUN_100351d0 at 100351d0

void FUN_100351d0(void)

{
  FUN_1000aca0(&DAT_10044ab8);
  return;
}



// Function: FUN_100351f0 at 100351f0

void FUN_100351f0(void)

{
  FUN_1000aca0(&DAT_10044a9c);
  return;
}



// Function: FUN_10035210 at 10035210

void FUN_10035210(void)

{
  FUN_1000aca0(&DAT_100446c8);
  return;
}



// Function: FUN_10035230 at 10035230

void FUN_10035230(void)

{
  FUN_1000aca0(&DAT_100454e8);
  return;
}



// Function: FUN_10035250 at 10035250

void FUN_10035250(void)

{
  FUN_1000aca0(&DAT_10044690);
  return;
}



// Function: FUN_10035270 at 10035270

void FUN_10035270(void)

{
  FUN_1000aca0(&DAT_10045608);
  return;
}



// Function: FUN_10035290 at 10035290

void FUN_10035290(void)

{
  FUN_1000aca0(&DAT_100446ac);
  return;
}



// Function: FUN_100352b0 at 100352b0

void FUN_100352b0(void)

{
  FUN_1000aca0(&DAT_10044a2c);
  return;
}



// Function: FUN_100352d0 at 100352d0

void FUN_100352d0(void)

{
  FUN_1000aca0(&DAT_10044a80);
  return;
}



// Function: FUN_100352f0 at 100352f0

void FUN_100352f0(void)

{
  FUN_1000aca0(&DAT_10044e1c);
  return;
}



// Function: FUN_10035310 at 10035310

void FUN_10035310(void)

{
  FUN_1000aca0(&DAT_10044e70);
  return;
}



// Function: FUN_10035330 at 10035330

void FUN_10035330(void)

{
  FUN_1000aca0(&DAT_10044d20);
  return;
}



// Function: FUN_10035350 at 10035350

void FUN_10035350(void)

{
  FUN_1000aca0(&DAT_1004471c);
  return;
}



// Function: FUN_10035370 at 10035370

void FUN_10035370(void)

{
  FUN_1000aca0(&DAT_10044700);
  return;
}



// Function: FUN_10035390 at 10035390

void FUN_10035390(void)

{
  FUN_1000aca0(&DAT_10044e8c);
  return;
}



// Function: FUN_100353b0 at 100353b0

void FUN_100353b0(void)

{
  FUN_1000aca0(&DAT_100446e4);
  return;
}



// Function: FUN_100353d0 at 100353d0

void FUN_100353d0(void)

{
  FUN_1000aca0(&DAT_1004530c);
  return;
}



// Function: FUN_100353f0 at 100353f0

void FUN_100353f0(void)

{
  FUN_1000aca0(&DAT_10045398);
  return;
}



// Function: FUN_10035410 at 10035410

void FUN_10035410(void)

{
  FUN_1000aca0(&DAT_10044524);
  return;
}



// Function: FUN_10035430 at 10035430

void FUN_10035430(void)

{
  FUN_1000aca0(&DAT_10044a10);
  return;
}



// Function: FUN_10035450 at 10035450

void FUN_10035450(void)

{
  FUN_1000aca0(&DAT_100444d0);
  return;
}



// Function: FUN_10035470 at 10035470

void FUN_10035470(void)

{
  FUN_1000aca0(&DAT_10044508);
  return;
}



// Function: FUN_10035490 at 10035490

void FUN_10035490(void)

{
  FUN_1000aca0(&DAT_100444ec);
  return;
}



// Function: FUN_100354b0 at 100354b0

void FUN_100354b0(void)

{
  FUN_1000aca0(&DAT_100455cc);
  return;
}



// Function: FUN_100354d0 at 100354d0

void FUN_100354d0(void)

{
  FUN_1000aca0(&DAT_100449d8);
  return;
}



// Function: FUN_100354f0 at 100354f0

void FUN_100354f0(void)

{
  FUN_1000aca0(&DAT_100444b4);
  return;
}



// Function: FUN_10035510 at 10035510

void FUN_10035510(void)

{
  FUN_1000aca0(&DAT_10044ee0);
  return;
}



// Function: FUN_10035530 at 10035530

void FUN_10035530(void)

{
  FUN_1000aca0(&DAT_10044c78);
  return;
}



// Function: FUN_10035550 at 10035550

void FUN_10035550(void)

{
  FUN_1000aca0(&DAT_10044bb4);
  return;
}



// Function: FUN_10035570 at 10035570

void FUN_10035570(void)

{
  FUN_1000aca0(&DAT_10044ccc);
  return;
}



// Function: FUN_10035590 at 10035590

void FUN_10035590(void)

{
  FUN_1000aca0(&DAT_10045328);
  return;
}



// Function: FUN_100355b0 at 100355b0

void FUN_100355b0(void)

{
  FUN_1000aca0(&DAT_10044b0c);
  return;
}



// Function: FUN_100355d0 at 100355d0

void FUN_100355d0(void)

{
  FUN_1000aca0(&DAT_10044b7c);
  return;
}



// Function: FUN_100355f0 at 100355f0

void FUN_100355f0(void)

{
  FUN_1000aca0(&DAT_10044ea8);
  return;
}



// Function: FUN_10035610 at 10035610

void FUN_10035610(void)

{
  FUN_1000aca0(&DAT_10045504);
  return;
}



// Function: FUN_10035630 at 10035630

void FUN_10035630(void)

{
  FUN_1000aca0(&DAT_10044c08);
  return;
}



// Function: FUN_10035650 at 10035650

void FUN_10035650(void)

{
  FUN_1000aca0(&DAT_10044bec);
  return;
}



// Function: FUN_10035670 at 10035670

void FUN_10035670(void)

{
  FUN_1000aca0(&DAT_10044cb0);
  return;
}



// Function: FUN_10035690 at 10035690

void FUN_10035690(void)

{
  FUN_1000aca0(&DAT_10044c40);
  return;
}



// Function: FUN_100356b0 at 100356b0

void FUN_100356b0(void)

{
  FUN_1000aca0(&DAT_10044d58);
  return;
}



// Function: FUN_100356d0 at 100356d0

void FUN_100356d0(void)

{
  FUN_1000aca0(&DAT_10044b44);
  return;
}



// Function: FUN_100356f0 at 100356f0

void FUN_100356f0(void)

{
  FUN_1000aca0(&DAT_10044b28);
  return;
}



// Function: FUN_10035710 at 10035710

void FUN_10035710(void)

{
  FUN_1000aca0(&DAT_10044c24);
  return;
}



// Function: FUN_10035730 at 10035730

void FUN_10035730(void)

{
  FUN_1000aca0(&DAT_10044dac);
  return;
}



// Function: FUN_10035750 at 10035750

void FUN_10035750(void)

{
  FUN_1000aca0(&DAT_10044bd0);
  return;
}



// Function: FUN_10035770 at 10035770

void FUN_10035770(void)

{
  FUN_1000aca0(&DAT_10044c5c);
  return;
}



// Function: FUN_10035790 at 10035790

void FUN_10035790(void)

{
  FUN_1000aca0(&DAT_10044b60);
  return;
}



// Function: FUN_100357b0 at 100357b0

void FUN_100357b0(void)

{
  FUN_1000aca0(&DAT_10044b98);
  return;
}



// Function: FUN_100357d0 at 100357d0

void FUN_100357d0(void)

{
  FUN_1000aca0(&DAT_10044c94);
  return;
}



// Function: FUN_100357f0 at 100357f0

void FUN_100357f0(void)

{
  FUN_1000aca0(&DAT_1004514c);
  return;
}



// Function: FUN_10035810 at 10035810

void FUN_10035810(void)

{
  FUN_1000aca0(&DAT_10045168);
  return;
}



// Function: FUN_10035830 at 10035830

void FUN_10035830(void)

{
  FUN_1000aca0(&DAT_10045360);
  return;
}



// Function: FUN_10035850 at 10035850

void FUN_10035850(void)

{
  FUN_1000aca0(&DAT_100451bc);
  return;
}



// Function: FUN_10035870 at 10035870

void FUN_10035870(void)

{
  FUN_1000aca0(&DAT_10045264);
  return;
}



// Function: FUN_10035890 at 10035890

void FUN_10035890(void)

{
  FUN_1000aca0(&DAT_100452b8);
  return;
}



// Function: FUN_100358b0 at 100358b0

void FUN_100358b0(void)

{
  FUN_1000aca0(&DAT_1004522c);
  return;
}



// Function: FUN_100358d0 at 100358d0

void FUN_100358d0(void)

{
  FUN_1000aca0(&DAT_100453ec);
  return;
}



// Function: FUN_100358f0 at 100358f0

void FUN_100358f0(void)

{
  FUN_1000aca0(&DAT_100451a0);
  return;
}



// Function: FUN_10035910 at 10035910

void FUN_10035910(void)

{
  FUN_1000aca0(&DAT_100452f0);
  return;
}



// Function: FUN_10035930 at 10035930

void FUN_10035930(void)

{
  FUN_1000aca0(&DAT_100451f4);
  return;
}



// Function: FUN_10035950 at 10035950

void FUN_10035950(void)

{
  FUN_1000aca0(&DAT_100451d8);
  return;
}



// Function: FUN_10035970 at 10035970

void FUN_10035970(void)

{
  FUN_1000aca0(&DAT_100453b4);
  return;
}



// Function: FUN_10035990 at 10035990

void FUN_10035990(void)

{
  FUN_1000aca0(&DAT_1004529c);
  return;
}



// Function: FUN_100359b0 at 100359b0

void FUN_100359b0(void)

{
  FUN_1000aca0(&DAT_100452d4);
  return;
}



// Function: FUN_100359d0 at 100359d0

void FUN_100359d0(void)

{
  FUN_1000aca0(&DAT_10045280);
  return;
}



// Function: FUN_100359f0 at 100359f0

void FUN_100359f0(void)

{
  FUN_1000aca0(&DAT_10045210);
  return;
}



// Function: FUN_10035a10 at 10035a10

void FUN_10035a10(void)

{
  FUN_1000aca0(&DAT_10045248);
  return;
}



// Function: FUN_10035a30 at 10035a30

void FUN_10035a30(void)

{
  FUN_1000aca0(&DAT_10045184);
  return;
}



// Function: FUN_10035a50 at 10035a50

void FUN_10035a50(void)

{
  FUN_1000aca0(&DAT_10045684);
  return;
}



// Function: FUN_10035a70 at 10035a70

void FUN_10035a70(void)

{
  FUN_1000aca0(&DAT_10045668);
  return;
}



// Function: FUN_10035a90 at 10035a90

void FUN_10035a90(void)

{
  FUN_1000aca0(&DAT_1004564c);
  return;
}



// Function: FUN_10035ab0 at 10035ab0

void FUN_10035ab0(void)

{
  FUN_1000aca0(&DAT_10045810);
  return;
}



// Function: FUN_10035ad0 at 10035ad0

void FUN_10035ad0(void)

{
  FUN_1000aca0(&DAT_10045764);
  return;
}



// Function: FUN_10035af0 at 10035af0

void FUN_10035af0(void)

{
  FUN_1000aca0(&DAT_10045864);
  return;
}



// Function: FUN_10035b10 at 10035b10

void FUN_10035b10(void)

{
  FUN_1000aca0(&DAT_100456a0);
  return;
}



// Function: FUN_10035b30 at 10035b30

void FUN_10035b30(void)

{
  FUN_1000aca0(&DAT_100457bc);
  return;
}



// Function: FUN_10035b50 at 10035b50

void FUN_10035b50(void)

{
  FUN_1000aca0(&DAT_1004582c);
  return;
}



// Function: FUN_10035b70 at 10035b70

void FUN_10035b70(void)

{
  FUN_1000aca0(&DAT_100457f4);
  return;
}



// Function: FUN_10035b90 at 10035b90

void FUN_10035b90(void)

{
  FUN_1000aca0(&DAT_10045848);
  return;
}



// Function: FUN_10035bb0 at 10035bb0

void FUN_10035bb0(void)

{
  FUN_1000aca0(&DAT_10045784);
  return;
}



// Function: FUN_10035bd0 at 10035bd0

void FUN_10035bd0(void)

{
  FUN_1000aca0(&DAT_10045748);
  return;
}



// Function: FUN_10035bf0 at 10035bf0

void FUN_10035bf0(void)

{
  FUN_1000aca0(&DAT_100456bc);
  return;
}



// Function: FUN_10035c10 at 10035c10

void FUN_10035c10(void)

{
  FUN_1000aca0(&DAT_100457a0);
  return;
}



// Function: FUN_10035c30 at 10035c30

void FUN_10035c30(void)

{
  FUN_1000aca0(&DAT_100456d8);
  return;
}



// Function: FUN_10035c50 at 10035c50

void FUN_10035c50(void)

{
  FUN_1000aca0(&DAT_10045710);
  return;
}



// Function: FUN_10035c70 at 10035c70

void FUN_10035c70(void)

{
  FUN_1000aca0(&DAT_100457d8);
  return;
}



// Function: FUN_10035c90 at 10035c90

void FUN_10035c90(void)

{
  FUN_1000aca0(&DAT_10045880);
  return;
}



// Function: FUN_10035cb0 at 10035cb0

void FUN_10035cb0(void)

{
  FUN_1000aca0(&DAT_100456f4);
  return;
}



// Function: FUN_10035cd0 at 10035cd0

void FUN_10035cd0(void)

{
  FUN_1000aca0(&DAT_1004572c);
  return;
}



// Function: FUN_10035cf0 at 10035cf0

void FUN_10035cf0(void)

{
  FUN_10007720((undefined4 *)&DAT_10045780);
  return;
}



// Function: FUN_10035d10 at 10035d10

void FUN_10035d10(void)

{
  FUN_10007720((undefined4 *)&DAT_1004589c);
  return;
}



// Function: FUN_10035d30 at 10035d30

void FUN_10035d30(void)

{
  FUN_10007720((undefined4 *)&DAT_100458a0);
  return;
}



// Function: FUN_10035d4a at 10035d4a

void FUN_10035d4a(void)

{
  FUN_1002b697(0x100458a4);
  return;
}



// Function: FUN_10035d54 at 10035d54

void FUN_10035d54(void)

{
  FUN_1002b866((int *)&DAT_100458dc);
  return;
}



// Function: FUN_10035d5e at 10035d5e

void FUN_10035d5e(void)

{
  ATL::CWin32Heap::~CWin32Heap((CWin32Heap *)&DAT_10045904);
  return;
}



// Function: FUN_10035d68 at 10035d68

void FUN_10035d68(void)

{
  PTR_PTR_10043b5c = (undefined *)&PTR_Allocate_1003ad5c;
  return;
}



// Function: FUN_10035d73 at 10035d73

void FUN_10035d73(void)

{
  FUN_1002bd7f();
  return;
}



