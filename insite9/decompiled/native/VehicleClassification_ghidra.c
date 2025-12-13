/*
 * Decompiled from: VehicleClassification.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_10001000 at 10001000

void __fastcall FUN_10001000(undefined4 *param_1)

{
  *param_1 = CScrollBarImpl::vftable;
  param_1[1] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  return;
}



// Function: FUN_10001030 at 10001030

void __fastcall FUN_10001030(undefined4 *param_1)

{
  *param_1 = CScrollBarImpl::vftable;
  return;
}



// Function: FUN_10001040 at 10001040

void __thiscall FUN_10001040(void *this,int param_1,int param_2,int param_3,int param_4)

{
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  *(int *)((int)this + 0x10) = param_3;
  *(int *)((int)this + 0x14) = param_4;
  *(int *)((int)this + 0x34) = param_4 - param_2;
  *(int *)((int)this + 0x30) = param_3 - param_1;
  return;
}



// Function: FUN_10001070 at 10001070

void __thiscall FUN_10001070(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = param_1;
  return;
}



// Function: FUN_10001080 at 10001080

void FUN_10001080(HWND param_1,int param_2)

{
  tagSCROLLINFO local_24;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_24.nMin = 0;
  local_24.nMax = 0;
  local_24.nPage = 0;
  local_24.nPos = 0;
  local_24.nTrackPos = 0;
  local_24.cbSize = 0x1c;
  local_24.fMask = 0x10;
  GetScrollInfo(param_1,param_2,&local_24);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100010e0 at 100010e0

void __thiscall FUN_100010e0(void *this,int param_1,UINT param_2)

{
  SCROLLINFO local_24;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  if (param_1 == 0) {
    local_24.nMax = *(int *)((int)this + 0x30) + -1;
    local_24.cbSize = 0x1c;
    local_24.fMask = 0x17;
    local_24.nMin = 0;
    local_24.nPos = 0;
    local_24.nPage = param_2;
    local_24.nTrackPos = 0;
    SetScrollInfo(*(HWND *)((int)this + 4),0,&local_24,1);
    if (*(int *)((int)this + 0x1c) < 0) {
      *(undefined4 *)((int)this + 0x1c) = 0;
    }
    else if (*(int *)((int)this + 0x30) < *(int *)((int)this + 0x1c)) {
      *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x30);
    }
    ScrollWindowEx(*(HWND *)((int)this + 4),*(int *)((int)this + 0x1c),0,(RECT *)0x0,(RECT *)0x0,
                   (HRGN)0x0,(LPRECT)0x0,7);
    *(undefined4 *)((int)this + 0x1c) = 0;
  }
  else if (param_1 == 1) {
    local_24.nMax = *(int *)((int)this + 0x34) + -1;
    local_24.cbSize = 0x1c;
    local_24.fMask = 0x17;
    local_24.nMin = 0;
    local_24.nPos = 0;
    local_24.nPage = param_2;
    local_24.nTrackPos = 0;
    SetScrollInfo(*(HWND *)((int)this + 4),1,&local_24,1);
    if (*(int *)((int)this + 0x24) < 0) {
      *(undefined4 *)((int)this + 0x24) = 0;
    }
    else if (*(int *)((int)this + 0x34) < *(int *)((int)this + 0x24)) {
      *(int *)((int)this + 0x24) = *(int *)((int)this + 0x34);
    }
    ScrollWindowEx(*(HWND *)((int)this + 4),0,*(int *)((int)this + 0x24),(RECT *)0x0,(RECT *)0x0,
                   (HRGN)0x0,(LPRECT)0x0,7);
    *(undefined4 *)((int)this + 0x24) = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100011f0 at 100011f0

void __thiscall FUN_100011f0(void *this,int param_1,undefined2 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  SCROLLINFO local_24;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  if (param_1 != 0x114) {
    if (param_1 != 0x115) goto LAB_1000144d;
    uVar3 = *(uint *)((int)this + 0x24);
    switch(param_2) {
    case 0:
      uVar3 = ((int)(uVar3 - 6) < 1) - 1 & uVar3 - 6;
      break;
    case 1:
      uVar2 = uVar3 + 6;
      uVar3 = *(uint *)((int)this + 0x20);
      if ((int)uVar2 < (int)uVar3) goto LAB_100012ab;
      break;
    case 2:
      uVar3 = uVar3 - *(int *)((int)this + 0x34);
      uVar3 = uVar3 & ((int)uVar3 < 1) - 1;
      break;
    case 3:
      uVar2 = *(int *)((int)this + 0x34) + uVar3;
      uVar3 = *(uint *)((int)this + 0x20);
      if ((int)uVar2 < (int)uVar3) goto LAB_100012ab;
      break;
    case 4:
      uVar2 = FUN_10001080(*(HWND *)((int)this + 4),1);
      *(undefined1 *)((int)this + 0x38) = 0;
      goto LAB_100012ab;
    case 5:
      if (*(char *)((int)this + 0x38) == '\0') {
        uVar1 = FUN_10001080(*(HWND *)((int)this + 4),1);
        *(undefined4 *)((int)this + 0x24) = uVar1;
      }
      uVar2 = FUN_10001080(*(HWND *)((int)this + 4),1);
      *(undefined1 *)((int)this + 0x38) = 1;
LAB_100012ab:
      uVar3 = uVar2;
      break;
    case 6:
      uVar3 = 0;
      break;
    case 7:
      uVar3 = *(uint *)((int)this + 0x20);
    }
    if ((uVar3 != *(uint *)((int)this + 0x24)) && (*(char *)((int)this + 0x38) == '\0')) {
      InvalidateRect(*(HWND *)((int)this + 4),(RECT *)((int)this + 8),0);
      if ((int)uVar3 < 0) {
        uVar3 = 0;
      }
      else if ((int)*(uint *)((int)this + 0x20) < (int)uVar3) {
        uVar3 = *(uint *)((int)this + 0x20);
      }
      ScrollWindowEx(*(HWND *)((int)this + 4),0,*(int *)((int)this + 0x24) - uVar3,(RECT *)0x0,
                     (RECT *)0x0,(HRGN)0x0,(LPRECT)0x0,7);
      UpdateWindow(*(HWND *)((int)this + 4));
      local_24.cbSize = 0x1c;
      local_24.fMask = 4;
      local_24.nPos = uVar3;
      SetScrollInfo(*(HWND *)((int)this + 4),1,&local_24,1);
      *(uint *)((int)this + 0x24) = uVar3;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    goto LAB_1000144d;
  }
  uVar3 = *(uint *)((int)this + 0x1c);
  switch(param_2) {
  case 0:
    uVar3 = ((int)(uVar3 - 6) < 1) - 1 & uVar3 - 6;
    break;
  case 1:
    uVar2 = uVar3 + 6;
    uVar3 = *(uint *)((int)this + 0x18);
    if ((int)uVar2 < (int)uVar3) goto LAB_100013d3;
    break;
  case 2:
    uVar3 = uVar3 - *(int *)((int)this + 0x30);
    uVar3 = uVar3 & ((int)uVar3 < 1) - 1;
    break;
  case 3:
    uVar2 = *(int *)((int)this + 0x30) + uVar3;
    uVar3 = *(uint *)((int)this + 0x18);
    if ((int)uVar2 < (int)uVar3) goto LAB_100013d3;
    break;
  case 4:
    uVar2 = FUN_10001080(*(HWND *)((int)this + 4),0);
    *(undefined1 *)((int)this + 0x38) = 0;
    goto LAB_100013d3;
  case 5:
    if (*(char *)((int)this + 0x38) == '\0') {
      uVar1 = FUN_10001080(*(HWND *)((int)this + 4),0);
      *(undefined4 *)((int)this + 0x1c) = uVar1;
    }
    uVar2 = FUN_10001080(*(HWND *)((int)this + 4),0);
    *(undefined1 *)((int)this + 0x38) = 1;
LAB_100013d3:
    uVar3 = uVar2;
    break;
  case 6:
    uVar3 = 0;
    break;
  case 7:
    uVar3 = *(uint *)((int)this + 0x18);
  }
  if ((uVar3 != *(uint *)((int)this + 0x1c)) && (*(char *)((int)this + 0x38) == '\0')) {
    InvalidateRect(*(HWND *)((int)this + 4),(RECT *)((int)this + 8),0);
    if ((int)uVar3 < 0) {
      uVar3 = 0;
    }
    else if ((int)*(uint *)((int)this + 0x18) < (int)uVar3) {
      uVar3 = *(uint *)((int)this + 0x18);
    }
    ScrollWindowEx(*(HWND *)((int)this + 4),*(int *)((int)this + 0x1c) - uVar3,0,(RECT *)0x0,
                   (RECT *)0x0,(HRGN)0x0,(LPRECT)0x0,7);
    UpdateWindow(*(HWND *)((int)this + 4));
    local_24.cbSize = 0x1c;
    local_24.fMask = 4;
    local_24.nPos = uVar3;
    SetScrollInfo(*(HWND *)((int)this + 4),0,&local_24,1);
    *(uint *)((int)this + 0x1c) = uVar3;
  }
LAB_1000144d:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100014b0 at 100014b0

void __thiscall FUN_100014b0(void *this,UINT param_1,UINT param_2)

{
  uint uVar1;
  SCROLLINFO local_24;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  if (*(UINT *)((int)this + 0x2c) != param_2) {
    uVar1 = (*(int *)((int)this + 0x14) - *(int *)((int)this + 0xc)) - param_2;
    local_24.nMax = *(int *)((int)this + 0x34) + -1;
    local_24.cbSize = 0x1c;
    local_24.fMask = 0x17;
    local_24.nMin = 0;
    *(uint *)((int)this + 0x20) = uVar1 & ((int)uVar1 < 0) - 1;
    local_24.nPos = 0;
    local_24.nPage = param_2;
    local_24.nTrackPos = 0;
    SetScrollInfo(*(HWND *)((int)this + 4),1,&local_24,1);
    if (*(int *)((int)this + 0x24) < 0) {
      *(undefined4 *)((int)this + 0x24) = 0;
    }
    else if (*(int *)((int)this + 0x34) < *(int *)((int)this + 0x24)) {
      *(int *)((int)this + 0x24) = *(int *)((int)this + 0x34);
    }
    ScrollWindowEx(*(HWND *)((int)this + 4),0,*(int *)((int)this + 0x24),(RECT *)0x0,(RECT *)0x0,
                   (HRGN)0x0,(LPRECT)0x0,7);
    *(undefined4 *)((int)this + 0x24) = 0;
  }
  *(UINT *)((int)this + 0x2c) = param_2;
  if (*(UINT *)((int)this + 0x28) != param_1) {
    uVar1 = (*(int *)((int)this + 0x10) - *(int *)((int)this + 8)) - param_1;
    *(uint *)((int)this + 0x18) = uVar1 & ((int)uVar1 < 0) - 1;
    FUN_100010e0(this,0,param_1);
  }
  *(UINT *)((int)this + 0x28) = param_1;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10001590 at 10001590

undefined4 * __thiscall FUN_10001590(void *this,byte param_1)

{
  *(undefined ***)this = CScrollBarImpl::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100015c0 at 100015c0

void __fastcall FUN_100015c0(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018d59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001610 at 10001610

exception * __thiscall FUN_10001610(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019769;
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



// Function: FUN_10001670 at 10001670

void __cdecl FUN_10001670(void *param_1,void *param_2,int param_3)

{
  memmove(param_1,param_2,param_3 * 2);
  return;
}



// Function: FUN_10001690 at 10001690

void FUN_10001690(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_100275d4);
}



// Function: FUN_100016b0 at 100016b0

void __fastcall FUN_100016b0(LPCRITICAL_SECTION param_1)

{
  if (*(char *)&param_1[1].DebugInfo != '\0') {
    *(undefined1 *)&param_1[1].DebugInfo = 0;
    DeleteCriticalSection(param_1);
  }
  return;
}



// Function: FUN_100016d0 at 100016d0

bool __thiscall FUN_100016d0(void *this,undefined4 *param_1)

{
  int iVar1;
  
                    /* WARNING: Load size is inaccurate */
  iVar1 = Ordinal_314(*this,*param_1,0x400,0);
  return (bool)('\x01' - (iVar1 != 1));
}



// Function: FUN_10001700 at 10001700

void __fastcall FUN_10001700(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  return;
}



// Function: FUN_10001710 at 10001710

HRESULT FUN_10001710(int param_1,LPCOLESTR param_2)

{
  HRESULT HVar1;
  
  if (param_2 == (LPCOLESTR)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = CLSIDFromString(param_2,(LPCLSID)(param_1 + 0x24));
  return HVar1;
}



// Function: FUN_10001740 at 10001740

void __fastcall FUN_10001740(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100196d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  Ordinal_6(*param_1,DAT_10030e10 ^ (uint)&stack0xfffffffc,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001790 at 10001790

void __fastcall FUN_10001790(LPCRITICAL_SECTION param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018d88;
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



// Function: FUN_100017e0 at 100017e0

undefined4 * __fastcall FUN_100017e0(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  return param_1;
}



// Function: FUN_100017f0 at 100017f0

void __fastcall FUN_100017f0(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x10001806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}



// Function: FUN_10001810 at 10001810

void __fastcall FUN_10001810(int param_1)

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



// Function: FUN_10001870 at 10001870

void * __cdecl FUN_10001870(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019739;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10027634);
}



// Function: FUN_10001900 at 10001900

exception * __thiscall FUN_10001900(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019769;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::bad_alloc::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10001960 at 10001960

undefined2 * __thiscall FUN_10001960(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_9(this);
  if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(iVar1);
  }
  *(undefined2 *)this = 8;
  iVar1 = *param_1;
  if (iVar1 != 0) {
    uVar2 = Ordinal_149(iVar1);
    iVar1 = Ordinal_150(*param_1,uVar2);
  }
  *(int *)((int)this + 8) = iVar1;
  if ((iVar1 == 0) && (*param_1 != 0)) {
    *(undefined2 *)this = 10;
    *(undefined4 *)((int)this + 8) = 0x8007000e;
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  return (undefined2 *)this;
}



// Function: FUN_100019d0 at 100019d0

void __fastcall FUN_100019d0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018dc3;
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



// Function: FUN_10001a30 at 10001a30

void __thiscall FUN_10001a30(void *this,int param_1)

{
  *(int *)((int)this + 0x10) = param_1;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  *(undefined2 *)((int)this + param_1 * 2) = 0;
  return;
}



// Function: FUN_10001a50 at 10001a50

void __fastcall FUN_10001a50(int *param_1)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018de8;
  local_10 = ExceptionList;
  uVar3 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = std::uncaught_exception();
  if (!bVar2) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx
              ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)*param_1);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(uVar3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001ad0 at 10001ad0

void __fastcall FUN_10001ad0(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018e19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8 = 0;
  FUN_10001810((int)param_1);
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10001b30 at 10001b30

undefined4 __fastcall FUN_10001b30(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = (undefined2 *)**(int **)(param_1 + 0x20);
  if (puVar1 == (undefined2 *)0x0) {
    return 0xffff;
  }
  if (puVar1 < puVar1 + **(int **)(param_1 + 0x30)) {
    return CONCAT22((short)((uint)puVar1 >> 0x10),*puVar1);
  }
  if ((((*(byte *)(param_1 + 0x40) & 4) == 0) &&
      (puVar2 = (undefined2 *)**(undefined4 **)(param_1 + 0x24), puVar2 != (undefined2 *)0x0)) &&
     ((puVar1 < puVar2 || (puVar1 < *(undefined2 **)(param_1 + 0x3c))))) {
    if (*(undefined2 **)(param_1 + 0x3c) < puVar2) {
      *(undefined2 **)(param_1 + 0x3c) = puVar2;
    }
    **(int **)(param_1 + 0x30) = *(int *)(param_1 + 0x3c) - **(int **)(param_1 + 0x20) >> 1;
    return CONCAT22((short)((uint)**(undefined4 **)(param_1 + 0x20) >> 0x10),
                    *(undefined2 *)**(undefined4 **)(param_1 + 0x20));
  }
  return 0xffff;
}



// Function: FUN_10001ba0 at 10001ba0

void __thiscall
FUN_10001ba0(void *this,uint *param_1,uint param_2,uint param_3,int param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  uVar2 = **(uint **)((int)this + 0x24);
  if ((uVar2 != 0) && (*(uint *)((int)this + 0x3c) < uVar2)) {
    *(uint *)((int)this + 0x3c) = uVar2;
  }
  if (((param_5 & 1) == 0) || (iVar5 = **(int **)((int)this + 0x20), iVar5 == 0)) {
    if (((param_5 & 2) == 0) || (uVar2 = **(uint **)((int)this + 0x24), uVar2 == 0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_10001d51;
    }
    else {
      if (param_4 == 2) {
        iVar5 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        uVar3 = iVar5 >> 1;
        bVar6 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + (iVar5 >> 0x1f) + (uint)bVar6;
      }
      else if (param_4 == 1) {
        iVar5 = uVar2 - **(int **)((int)this + 0x10);
        uVar3 = iVar5 >> 1;
        bVar6 = CARRY4(param_2,uVar3);
        param_2 = param_2 + uVar3;
        param_3 = param_3 + (iVar5 >> 0x1f) + (uint)bVar6;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        iVar5 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        iVar1 = iVar5 >> 0x1f;
        if (((int)param_3 <= iVar1) && (((int)param_3 < iVar1 || (param_2 <= (uint)(iVar5 >> 1)))))
        {
          iVar5 = ((int)(**(int **)((int)this + 0x10) - uVar2) >> 1) + param_2;
          **(int **)((int)this + 0x34) = **(int **)((int)this + 0x34) - iVar5;
          **(int **)((int)this + 0x24) = **(int **)((int)this + 0x24) + iVar5 * 2;
          goto LAB_10001d51;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      iVar1 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      uVar2 = iVar1 >> 1;
      bVar6 = CARRY4(param_2,uVar2);
      param_2 = param_2 + uVar2;
      param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar6;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) == 0) {
        iVar1 = iVar5 - **(int **)((int)this + 0x10);
        uVar2 = iVar1 >> 1;
        bVar6 = CARRY4(param_2,uVar2);
        param_2 = param_2 + uVar2;
        param_3 = param_3 + (iVar1 >> 0x1f) + (uint)bVar6;
      }
      else {
LAB_10001c15:
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
    }
    else if (param_4 != 0) goto LAB_10001c15;
    if (-1 < (int)param_3) {
      iVar1 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar4 = iVar1 >> 0x1f;
      if (((int)param_3 <= iVar4) && (((int)param_3 < iVar4 || (param_2 <= (uint)(iVar1 >> 1))))) {
        iVar5 = (**(int **)((int)this + 0x10) - iVar5 >> 1) + param_2;
        **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar5;
        **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar5 * 2;
        if ((param_5 & 2) != 0) {
          iVar5 = **(int **)((int)this + 0x24);
          if (iVar5 != 0) {
            iVar1 = **(int **)((int)this + 0x34);
            iVar4 = **(int **)((int)this + 0x20);
            **(int **)((int)this + 0x24) = iVar4;
            **(int **)((int)this + 0x34) = (iVar5 + iVar1 * 2) - iVar4 >> 1;
          }
        }
        goto LAB_10001d51;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_10001d51:
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10001d70 at 10001d70

short __thiscall FUN_10001d70(void *this,short param_1)

{
  uint uVar1;
  
  uVar1 = **(uint **)((int)this + 0x20);
  if ((uVar1 != 0) && (**(uint **)((int)this + 0x10) < uVar1)) {
    if ((param_1 == -1) ||
       ((param_1 == *(short *)(uVar1 - 2) || ((*(byte *)((int)this + 0x40) & 2) == 0)))) {
      **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) + 1;
      **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + -2;
      if (param_1 != -1) {
        *(short *)**(undefined4 **)((int)this + 0x20) = param_1;
        return param_1;
      }
      return 0;
    }
  }
  return -1;
}



// Function: FUN_10001de0 at 10001de0

void __thiscall FUN_10001de0(void *this,uint *param_1,uint param_2,int param_3,uint param_4)

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
      if ((((in_stack_00000020 & 2) != 0) && (**(int **)((int)this + 0x24) != 0)) &&
         (-1 < (int)uVar6)) {
        iVar4 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
        iVar5 = iVar4 >> 0x1f;
        if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) {
          iVar4 = (**(int **)((int)this + 0x10) - **(int **)((int)this + 0x24) >> 1) + uVar8;
          **(int **)((int)this + 0x34) = **(int **)((int)this + 0x34) - iVar4;
          **(int **)((int)this + 0x24) = **(int **)((int)this + 0x24) + iVar4 * 2;
          uVar7 = uVar6;
          uVar9 = uVar8;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      iVar4 = *(int *)((int)this + 0x3c) - **(int **)((int)this + 0x10);
      iVar5 = iVar4 >> 0x1f;
      if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar8 <= (uint)(iVar4 >> 1))))) {
        iVar4 = (**(int **)((int)this + 0x10) - **(int **)((int)this + 0x20) >> 1) + uVar8;
        **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar4;
        **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar4 * 2;
        uVar7 = uVar6;
        uVar9 = uVar8;
        if ((in_stack_00000020 & 2) != 0) {
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
  }
  *param_1 = uVar9;
  param_1[1] = uVar7;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10001f20 at 10001f20

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10001f20(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018e19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8 = 0;
  FUN_10001810((int)this);
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10001f90 at 10001f90

void __thiscall FUN_10001f90(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018e40;
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
  FUN_10001870((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_10002050();
  return;
}



// Function: Catch@1000201e at 1000201e

undefined * Catch_1000201e(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_10001870((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10002047;
}



// Function: FUN_10002050 at 10002050

void FUN_10002050(void)

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



// Function: Catch@100020b1 at 100020b1

void Catch_100020b1(void)

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



// Function: FUN_100020e0 at 100020e0

void FUN_100020e0(int *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  ushort uVar5;
  wchar_t *pwVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  __int64 _Var11;
  undefined2 uVar12;
  undefined2 uVar13;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018e78;
  local_10 = ExceptionList;
  uVar12 = (undefined2)(DAT_10030e10 ^ (uint)&stack0xfffffffc);
  uVar13 = (undefined2)((DAT_10030e10 ^ (uint)&stack0xfffffffc) >> 0x10);
  ExceptionList = &local_10;
  bVar10 = false;
  pwVar6 = param_2;
  do {
    wVar1 = *pwVar6;
    pwVar6 = pwVar6 + 1;
  } while (wVar1 != L'\0');
  uVar7 = (int)pwVar6 - (int)(param_2 + 1) >> 1;
  iVar2 = *(int *)(*param_1 + 4);
  uVar3 = *(uint *)(iVar2 + 0x20 + (int)param_1);
  local_20 = *(int *)(iVar2 + 0x24 + (int)param_1);
  if (((local_20 < 0) || (((local_20 < 1 && (uVar3 == 0)) || (local_20 < 0)))) ||
     ((local_20 < 1 && (uVar3 <= uVar7)))) {
    iVar8 = 0;
    local_20 = 0;
  }
  else {
    iVar8 = uVar3 - uVar7;
    local_20 = local_20 - (uint)(uVar3 < uVar7);
  }
  piVar4 = *(int **)(iVar2 + 0x38 + (int)param_1);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))();
  }
  local_8 = 0;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
              (*(int *)(*param_1 + 4) + 0x3c + (int)param_1),
     this != (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush(this);
  }
  local_8 = 1;
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) {
    FUN_100022d3();
    return;
  }
  local_8 = 2;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_20 < 0) || ((local_20 < 1 && (iVar8 == 0)))) goto LAB_10002210;
      uVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar5 == 0xffff) break;
      bVar9 = iVar8 != 0;
      iVar8 = iVar8 + -1;
      local_20 = local_20 + -1 + (uint)bVar9;
    }
    bVar10 = true;
LAB_10002210:
    if (bVar10) goto LAB_10002240;
  }
  _Var11 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                     (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                       (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                      (ulonglong)CONCAT22(uVar13,uVar12) << 0x20);
  if (((uint)_Var11 == uVar7) && ((int)((ulonglong)_Var11 >> 0x20) == 0)) {
    while ((-1 < local_20 &&
           (((0 < local_20 || (iVar8 != 0)) &&
            (uVar5 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                               (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                                 (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                                *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1)),
            uVar5 != 0xffff))))) {
      bVar10 = iVar8 != 0;
      iVar8 = iVar8 + -1;
      local_20 = local_20 + -1 + (uint)bVar10;
    }
  }
LAB_10002240:
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  local_8 = 1;
  FUN_100022d3();
  return;
}



// Function: Catch@100022af at 100022af

undefined * Catch_100022af(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100022d0;
}



// Function: FUN_100022d3 at 100022d3

void FUN_100022d3(void)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  bool bVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 4;
  bVar1 = std::uncaught_exception();
  this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x28);
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int **)(this + *(int *)(*(int *)this + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(this + *(int *)(*(int *)this + 4) + 0x38) + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002340 at 10002340

void FUN_10002340(int *param_1,wchar_t *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  bool bVar6;
  ushort uVar7;
  uint uVar8;
  __int64 _Var9;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10018eb8;
  local_10 = ExceptionList;
  uVar8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar6 = false;
  uVar1 = *(uint *)(param_2 + 8);
  iVar2 = *(int *)(*param_1 + 4);
  uVar3 = *(uint *)(iVar2 + 0x20 + (int)param_1);
  iVar4 = *(int *)(iVar2 + 0x24 + (int)param_1);
  if ((iVar4 < 0) || (((iVar4 < 1 && (uVar3 == 0)) || (uVar3 <= uVar1)))) {
    local_1c = 0;
  }
  else {
    local_1c = uVar3 - uVar1;
  }
  piVar5 = *(int **)(iVar2 + 0x38 + (int)param_1);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
  }
  local_8 = 0;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
              (*(int *)(*param_1 + 4) + 0x3c + (int)param_1),
     this != (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush(this);
  }
  local_8 = 1;
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) {
    FUN_10002506();
    return;
  }
  local_8 = 2;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) == 0x40) {
LAB_10002460:
    if (7 < *(uint *)(param_2 + 10)) {
      param_2 = *(wchar_t **)param_2;
    }
    _Var9 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputn
                      (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                        (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                       (ulonglong)uVar8 << 0x20);
    if (((uint)_Var9 != uVar1) || ((int)((ulonglong)_Var9 >> 0x20) != 0)) goto LAB_1000248e;
  }
  else {
    for (; local_1c != 0; local_1c = local_1c + -1) {
      uVar7 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (uVar7 == 0xffff) {
        bVar6 = true;
        break;
      }
    }
    if (!bVar6) goto LAB_10002460;
  }
  while ((local_1c != 0 &&
         (uVar7 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                              (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                             *(wchar_t *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1)),
         uVar7 != 0xffff))) {
    local_1c = local_1c + -1;
  }
LAB_1000248e:
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  local_8 = 1;
  FUN_10002506();
  return;
}



// Function: Catch@100024e2 at 100024e2

undefined * Catch_100024e2(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10002503;
}



// Function: FUN_10002506 at 10002506

void FUN_10002506(void)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  bool bVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 4;
  bVar1 = std::uncaught_exception();
  this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x20);
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int **)(this + *(int *)(*(int *)this + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(this + *(int *)(*(int *)this + 4) + 0x38) + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10002570 at 10002570

void __fastcall FUN_10002570(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// Function: FUN_100025a0 at 100025a0

int * __thiscall FUN_100025a0(void *this,uint param_1,uint param_2)

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



// Function: FUN_10002630 at 10002630

/* WARNING: Removing unreachable block (ram,0x1000278f) */

void FUN_10002630(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  ulong uVar2;
  LPCOLESTR lpszProgID;
  HRESULT HVar3;
  int iVar4;
  int *local_2c;
  int *local_28;
  CLSID local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018f28;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2c = (int *)0x0;
  local_28 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  lpszProgID = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0",local_14);
  if (lpszProgID == (LPCOLESTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  HVar3 = CLSIDFromProgID(lpszProgID,&local_24);
  if (-1 < HVar3) {
    CoCreateInstance(&local_24,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10022814,&local_28);
  }
  local_8._0_1_ = 3;
  Ordinal_6(lpszProgID);
  piVar1 = local_28;
  local_24.Data1 = CONCAT22(local_24.Data1._2_2_,3);
  uVar2 = local_24.Data1;
  local_24.Data4[0] = '\x01';
  local_24.Data4[1] = '\0';
  local_24.Data4[2] = '\0';
  local_24.Data4[3] = '\0';
  local_8._0_1_ = 5;
  iVar4 = Ordinal_2(L"LicenseFile");
  if (iVar4 != 0) {
    local_8._0_1_ = 6;
    (**(code **)(*piVar1 + 0xe0))
              (piVar1,uVar2,local_24._4_4_,1,local_24.Data4._4_4_,iVar4,0,&local_2c);
    local_8._0_1_ = 5;
    Ordinal_6(iVar4);
    local_8._0_1_ = 3;
    Ordinal_9(&local_24);
    (**(code **)(*local_28 + 0x54))(local_28,local_2c,param_2);
    *param_1 = local_28;
    local_28 = (int *)0x0;
    local_8 = 0xffffffff;
    if (local_2c != (int *)0x0) {
      (**(code **)(*local_2c + 8))(local_2c);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_10001690(0x8007000e);
}



// Function: FUN_100027d0 at 100027d0

wchar_t __thiscall FUN_100027d0(void *this,wchar_t param_1)

{
  void *pvVar1;
  int iVar2;
  void *_Src;
  wchar_t *pwVar3;
  uint uVar4;
  char *pcVar5;
  void *_Dst;
  uint uVar6;
  
  if ((*(byte *)((int)this + 0x40) & 8) != 0) {
    uVar6 = **(uint **)((int)this + 0x24);
    if ((uVar6 != 0) && (uVar4 = *(uint *)((int)this + 0x3c), uVar6 < uVar4)) {
      iVar2 = **(int **)((int)this + 0x34);
      **(uint **)((int)this + 0x24) = uVar4;
      **(int **)((int)this + 0x34) = (int)((uVar6 + iVar2 * 2) - uVar4) >> 1;
    }
  }
  if (param_1 == L'\xffff') {
    return L'\0';
  }
  uVar6 = **(uint **)((int)this + 0x24);
  if ((uVar6 != 0) && (uVar6 < uVar6 + **(int **)((int)this + 0x34) * 2)) {
    pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                       ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
    *pwVar3 = param_1;
    return param_1;
  }
  if ((*(byte *)((int)this + 0x40) & 2) != 0) {
    return L'\xffff';
  }
  if (uVar6 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (int)((**(int **)((int)this + 0x34) * 2 - **(int **)((int)this + 0x10)) + uVar6) >> 1;
  }
  uVar4 = uVar6 >> 1;
  if (uVar4 < 0x20) {
    uVar4 = 0x20;
  }
  else if (uVar4 == 0) {
    return L'\xffff';
  }
  do {
    if (uVar6 <= 0x7fffffff - uVar4) break;
    uVar4 = uVar4 >> 1;
  } while (uVar4 != 0);
  if (uVar4 == 0) {
    return L'\xffff';
  }
  pcVar5 = (char *)(uVar4 + uVar6);
  _Dst = FUN_10001870(pcVar5);
  _Src = (void *)**(undefined4 **)((int)this + 0x10);
  if ((uVar6 == 0) || (memcpy(_Dst,_Src,uVar6 * 2), uVar6 == 0)) {
    *(void **)((int)this + 0x3c) = _Dst;
    **(undefined4 **)((int)this + 0x14) = _Dst;
    **(undefined4 **)((int)this + 0x24) = _Dst;
    **(int **)((int)this + 0x34) = (int)pcVar5 * 2 >> 1;
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(undefined4 **)((int)this + 0x20) = _Dst;
      **(undefined4 **)((int)this + 0x30) = 1;
    }
    else {
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(undefined4 **)((int)this + 0x20) = 0;
      **(int **)((int)this + 0x30) = (int)_Dst >> 1;
    }
  }
  else {
    *(void **)((int)this + 0x3c) =
         (void *)((int)_Dst + (*(int *)((int)this + 0x3c) - (int)_Src >> 1) * 2);
    pvVar1 = (void *)((int)_Dst + (**(int **)((int)this + 0x24) - (int)_Src >> 1) * 2);
    **(int **)((int)this + 0x14) =
         (int)((int)_Dst + (**(int **)((int)this + 0x14) - (int)_Src >> 1) * 2);
    **(int **)((int)this + 0x24) = (int)pvVar1;
    **(int **)((int)this + 0x34) = ((int)pcVar5 * 2 - (int)pvVar1) + (int)_Dst >> 1;
    if ((*(byte *)((int)this + 0x40) & 4) == 0) {
      iVar2 = **(int **)((int)this + 0x24);
      pvVar1 = (void *)((int)_Dst + (**(int **)((int)this + 0x20) - (int)_Src >> 1) * 2);
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(int **)((int)this + 0x20) = (int)pvVar1;
      **(int **)((int)this + 0x30) = (iVar2 - (int)pvVar1) + 2 >> 1;
    }
    else {
      **(undefined4 **)((int)this + 0x10) = _Dst;
      **(undefined4 **)((int)this + 0x20) = 0;
      **(int **)((int)this + 0x30) = (int)_Dst >> 1;
    }
  }
  if ((*(byte *)((int)this + 0x40) & 1) != 0) {
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x40) = *(uint *)((int)this + 0x40) | 1;
  pwVar3 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  *pwVar3 = param_1;
  return param_1;
}



// Function: FUN_100029f0 at 100029f0

void __fastcall FUN_100029f0(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018f7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002a70 at 10002a70

void __fastcall FUN_10002a70(int *param_1)

{
  ios_base *piVar1;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10018fc9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (ios_base *)(param_1 + 0x14);
  *(undefined ***)(piVar1 + *(int *)(*param_1 + 4) + -0x50) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  this = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 1);
  *(undefined ***)this =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_10001810((int)this);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  *(code **)(piVar1 + *(int *)(*param_1 + 4) + -0x50) = _vftable__exref;
  *(code **)piVar1 = _vftable__exref;
  local_8 = 0xffffffff;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002b20 at 10002b20

int * __thiscall FUN_10002b20(void *this,int *param_1,uint param_2,uint param_3)

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
    FUN_100025a0(this,uVar2 + param_2,0xffffffff);
    FUN_100025a0(this,0,param_2);
    return (int *)this;
  }
  if (0x7ffffffe < uVar2) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_ECX_00;
  }
  if (*(uint *)((int)this + 0x14) < uVar2) {
    FUN_10001f90(this,uVar2);
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



// Function: FUN_10002c20 at 10002c20

/* WARNING: Removing unreachable block (ram,0x10002cce) */

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10002c20(void *this,uint param_1,int param_2)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019036;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 != 0) {
    *(undefined ***)this = &PTR_100228f8;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
    *(undefined4 *)((int)this + 0x50) = _vftable__exref;
    local_8 = 1;
  }
  this_00 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 4);
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,this_00,false);
  local_8 = 2;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::
       basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this_00);
  uVar1 = 0;
  *(undefined ***)this_00 =
       std::basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
       ::vftable;
  if ((param_1 & 1) == 0) {
    uVar1 = 4;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  *(undefined4 *)((int)this + 0x40) = 0;
  *(uint *)((int)this + 0x44) = uVar1;
  ExceptionList = local_10;
  return (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10002d10 at 10002d10

int * __thiscall FUN_10002d10(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((int)this + -0x50);
  FUN_10002a70(piVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(piVar1);
  }
  return piVar1;
}



// Function: FUN_10002d40 at 10002d40

int * __thiscall FUN_10002d40(void *this,int *param_1,uint param_2)

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
        piVar2 = FUN_10002b20(this,(int *)this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar2;
      }
    }
  }
  if (0x7ffffffe < param_2) {
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_10001f90(this,param_2);
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



// Function: FUN_10002e40 at 10002e40

void __fastcall FUN_10002e40(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// Function: FUN_10002ed0 at 10002ed0

void __fastcall FUN_10002ed0(int param_1)

{
  int *piVar1;
  uint3 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019124;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
    uVar2 = local_8._1_3_;
  }
  local_8._1_3_ = uVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10002f70 at 10002f70

undefined2 * __thiscall FUN_10002f70(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined2 *)this = 0;
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10002d40(this,param_1,(int)piVar2 - ((int)param_1 + 2) >> 1);
  return (undefined2 *)this;
}



// Function: FUN_10002fc0 at 10002fc0

undefined4 * __thiscall FUN_10002fc0(void *this,undefined4 *param_1)

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



// Function: FUN_10003040 at 10003040

void __cdecl FUN_10003040(undefined4 param_1,undefined4 *param_2)

{
  if (7 < (uint)param_2[5]) {
    operator_delete((void *)*param_2);
  }
  param_2[5] = 7;
  param_2[4] = 0;
  *(undefined2 *)param_2 = 0;
  return;
}



// Function: FUN_10003070 at 10003070

void __thiscall FUN_10003070(void *this,undefined2 *param_1)

{
  uint uVar1;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019171;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((*(uint *)((int)this + 0x40) & 2) == 0) && (**(uint **)((int)this + 0x24) != 0)) {
    uVar1 = **(uint **)((int)this + 0x24);
    if (uVar1 <= *(uint *)((int)this + 0x3c)) {
      uVar1 = *(uint *)((int)this + 0x3c);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    FUN_10002d40(&local_30,(int *)**(undefined4 **)((int)this + 0x14),
                 (int)(uVar1 - (int)**(undefined4 **)((int)this + 0x14)) >> 1);
    local_8 = 1;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_10002fc0(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
    }
  }
  else {
    if (((*(uint *)((int)this + 0x40) & 4) != 0) || (**(int **)((int)this + 0x20) == 0)) {
      local_1c = 7;
      local_20 = 0;
      local_30 = (void *)((uint)local_30._2_2_ << 0x10);
      local_8 = 3;
      *(undefined4 *)(param_1 + 10) = 7;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 0;
      FUN_10002fc0(param_1,&local_30);
      local_8 = local_8 & 0xffffff00;
      if (7 < local_1c) {
        operator_delete(local_30);
      }
      local_30 = (void *)((uint)local_30 & 0xffff0000);
      goto LAB_100031f5;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (void *)((uint)local_30._2_2_ << 0x10);
    FUN_10002d40(&local_30,(int *)**(undefined4 **)((int)this + 0x10),
                 (**(int **)((int)this + 0x20) + **(int **)((int)this + 0x30) * 2) -
                 (int)**(undefined4 **)((int)this + 0x10) >> 1);
    local_8 = 2;
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_10002fc0(param_1,&local_30);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_1c) {
      operator_delete(local_30);
      local_30 = (void *)((uint)local_30 & 0xffff0000);
      goto LAB_100031f5;
    }
  }
  local_30 = (void *)((uint)local_30 & 0xffff0000);
LAB_100031f5:
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003220 at 10003220

void __cdecl FUN_10003220(undefined4 *param_1,undefined4 *param_2)

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



// Function: FUN_10003260 at 10003260

undefined2 * __thiscall FUN_10003260(void *this,undefined2 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100191b9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10003070((void *)((int)this + 4),param_1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100032c0 at 100032c0

void __thiscall FUN_100032c0(void *this,int *param_1,undefined4 param_2,undefined4 param_3)

{
  wchar_t *pwVar1;
  int *piVar2;
  undefined4 *puVar3;
  wchar_t *unaff_EBX;
  undefined *puVar4;
  undefined *local_d8;
  int *local_38;
  int *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  wchar_t *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001922b;
  local_10 = ExceptionList;
  pwVar1 = (wchar_t *)(DAT_10030e10 ^ (uint)&stack0xfffffffc);
  ExceptionList = &local_10;
  local_34 = (int *)0x0;
  local_38 = (int *)0x0;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  local_14 = pwVar1;
  FUN_10002c20(&local_d8,2,1);
  local_8._0_1_ = 4;
  piVar2 = (int *)FUN_100020e0((int *)&local_d8,L".//*[@ID=\"");
  piVar2 = (int *)FUN_10002340(piVar2,pwVar1);
  FUN_100020e0(piVar2,unaff_EBX);
  piVar2 = *(int **)((int)this + 8);
  local_d8 = (undefined *)0x10003360;
  puVar3 = (undefined4 *)FUN_10003260(&local_d8,(undefined2 *)local_30);
  local_8._0_1_ = 5;
  if (7 < (uint)puVar3[5]) {
    puVar3 = (undefined4 *)*puVar3;
  }
  if (puVar3 == (undefined4 *)0x0) {
    puVar4 = (undefined *)0x0;
  }
  else {
    local_d8 = (undefined *)0x10003444;
    puVar4 = (undefined *)Ordinal_2();
    if (puVar4 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
      local_d8 = &UNK_1000345b;
      FUN_10001690(0x8007000e);
    }
  }
  local_8._0_1_ = 6;
  local_d8 = puVar4;
  (**(code **)(*piVar2 + 0x94))(piVar2);
  local_8._0_1_ = 5;
  Ordinal_6(puVar4);
  local_8._0_1_ = 4;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  (**(code **)(*local_34 + 0x60))(local_34,0xffffffff,&local_38);
  (**(code **)(*param_1 + 0x54))(param_1,local_38,param_3);
  local_8._0_1_ = 3;
  FUN_10002a70((int *)&local_d8);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  local_8 = 0xffffffff;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  ExceptionList = local_10;
  __security_check_cookie((uint)local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003460 at 10003460

bool __thiscall FUN_10003460(void *this,undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 local_40 [8];
  int local_38;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100192f0;
  local_10 = ExceptionList;
  uVar3 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2c = 0;
  local_24 = (int *)0x0;
  local_14 = (int *)0x0;
  local_8._1_3_ = 0;
  local_20 = (int *)0x0;
  local_8._0_1_ = 6;
  FUN_10002630(&local_24,&local_20);
  FUN_100032c0(this,local_20,param_1,&local_14);
  (**(code **)(*local_14 + 0x1c))(local_14,&local_2c,uVar3);
  piVar1 = local_24;
  local_28 = 0;
  local_8._0_1_ = 7;
  (**(code **)(*local_24 + 0x88))(local_24,&local_28);
  (**(code **)(**(int **)((int)this + 4) + 0xc))(*(int **)((int)this + 4),piVar1);
  local_1c = (int *)0x0;
  local_8._0_1_ = 9;
  (**(code **)*local_14)(local_14,&DAT_10022854,&local_1c);
  Ordinal_8(local_40);
  piVar2 = local_1c;
  local_8._0_1_ = 10;
  iVar4 = Ordinal_2(L"IsValid");
  local_18 = iVar4;
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  local_8._0_1_ = 0xb;
  (**(code **)(*piVar2 + 0xb0))(piVar2,iVar4,local_40);
  local_8 = CONCAT31(local_8._1_3_,10);
  Ordinal_6(iVar4);
  if (local_38 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = Ordinal_2(local_38);
    if (local_18 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x8007000e);
    }
  }
  local_8._0_1_ = 0xc;
  iVar4 = Ordinal_2(L"TRUE");
  local_30 = iVar4;
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  local_8._0_1_ = 0xd;
  iVar5 = Ordinal_314(local_18,iVar4,0x400,0);
  local_8._0_1_ = 0xc;
  Ordinal_6(iVar4);
  local_8._0_1_ = 10;
  Ordinal_6(local_18);
  local_8._0_1_ = 9;
  Ordinal_9(local_40);
  local_8._0_1_ = 7;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8._0_1_ = 6;
  Ordinal_6(local_28);
  local_8._0_1_ = 4;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_8._0_1_ = 2;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  (**(code **)(*piVar1 + 8))(piVar1);
  local_8 = 0xffffffff;
  Ordinal_6(local_2c);
  ExceptionList = local_10;
  return iVar5 == 1;
}



// Function: FUN_10003670 at 10003670

void FUN_10003670(int param_1,int *param_2,short *param_3)

{
  bool bVar1;
  undefined2 *puVar2;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b988;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_2 != (int *)0x0) && (param_3 != (short *)0x0)) {
    puVar2 = FUN_10017be0((undefined2 *)local_30,param_2);
    local_8 = 0;
    bVar1 = FUN_10003460((void *)(param_1 + -0xc),puVar2);
    *param_3 = -(ushort)bVar1;
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    local_1c = 7;
    local_20 = 0;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003730 at 10003730

void __fastcall FUN_10003730(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    FUN_10003220((undefined4 *)*param_1,(undefined4 *)param_1[1]);
    operator_delete((void *)*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_10003780 at 10003780

void __thiscall FUN_10003780(void *this,undefined4 *param_1,void *param_2)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int iVar3;
  int *piVar4;
  LPCOLESTR pOVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uStack00000018;
  uint in_stack_0000001c;
  OLECHAR aOStack_114 [4];
  undefined4 uStack_10c;
  void *pvStack_108;
  undefined4 uStack_104;
  TypeDescriptor *pTStack_100;
  TypeDescriptor *pTStack_fc;
  undefined4 **ppuStack_f8;
  int *piStack_f4;
  int *piStack_f0;
  int *piStack_ec;
  int *piStack_e8;
  int **ppiStack_e4;
  undefined4 *puStack_e0;
  undefined *puStack_dc;
  int **ppiStack_d8;
  undefined1 *puStack_d4;
  int iStack_d0;
  int *piStack_cc;
  LPCOLESTR pOStack_c8;
  LPCOLESTR *ppOStack_c4;
  int *piStack_c0;
  LPCOLESTR pOStack_bc;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined4 *local_74;
  undefined4 *local_70;
  undefined4 local_6c;
  int *local_64;
  int *local_60;
  int *local_5c;
  short local_58;
  LPCOLESTR local_54;
  LPCOLESTR *local_50;
  int *local_4c;
  LPCOLESTR local_48;
  LPCOLESTR local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  undefined1 local_24 [8];
  uchar local_1c [4];
  LPCOLESTR local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_10019440;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  (**(code **)*param_1)();
  local_44 = (LPCOLESTR)Ordinal_2();
  if (local_44 == (LPCOLESTR)0x0) {
LAB_100037d9:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  HVar2 = CLSIDFromProgID(local_44,(LPCLSID)local_24);
  if (-1 < HVar2) {
    pOStack_bc = (LPCOLESTR)0x1000380c;
    CoCreateInstance((IID *)local_24,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10022814,
                     (LPVOID *)((int)this + 8));
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_6();
  local_60 = (int *)0x0;
  local_2c = (int *)0x0;
  local_38 = (int *)0x0;
  local_8._1_3_ = (uint3)(local_8 >> 8);
  local_24._0_2_ = 3;
  local_1c[0] = '\x01';
  local_1c[1] = '\0';
  local_1c[2] = '\0';
  local_1c[3] = '\0';
  local_8._0_1_ = 8;
  local_54 = (LPCOLESTR)local_24._0_4_;
  local_50 = (LPCOLESTR *)local_24._4_4_;
  local_30 = *(int **)((int)this + 8);
  local_4c = (int *)0x1;
  local_48 = local_18;
  iVar3 = Ordinal_2();
  local_44 = (LPCOLESTR)iVar3;
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  local_8._0_1_ = 9;
  pOStack_c8 = local_54;
  ppOStack_c4 = local_50;
  piStack_c0 = local_4c;
  pOStack_bc = local_48;
  piStack_cc = local_30;
  iStack_d0 = 0x100038b2;
  (**(code **)(*local_30 + 0xe0))();
  local_8._0_1_ = 8;
  puStack_d4 = (undefined1 *)0x100038bd;
  iStack_d0 = iVar3;
  Ordinal_6();
  local_8 = CONCAT31(local_8._1_3_,7);
  puStack_d4 = local_24;
  ppiStack_d8 = (int **)0x100038cb;
  Ordinal_9();
  puStack_e0 = *(undefined4 **)((int)this + 8);
  ppiStack_d8 = &local_38;
  puStack_dc = &DAT_10022844;
  ppiStack_e4 = (int **)0x100038de;
  (**(code **)*puStack_e0)();
  ppiStack_e4 = &local_60;
  piStack_e8 = local_2c;
  piStack_ec = local_38;
  piStack_f0 = (int *)0x100038f1;
  (**(code **)(*local_38 + 0x54))();
  piStack_f0 = local_2c;
  if (local_2c != (int *)0x0) {
    local_2c = (int *)0x0;
    piStack_f4 = (int *)0x10003903;
    (**(code **)(*piStack_f0 + 8))();
  }
  local_7c = 0;
  local_8._0_1_ = 10;
  piStack_f0 = &local_7c;
  piStack_f4 = local_38;
  ppuStack_f8 = (undefined4 **)0x1000391c;
  local_34 = (**(code **)(*local_38 + 0x88))();
  local_74 = (undefined4 *)0x0;
  local_70 = (undefined4 *)0x0;
  local_6c = 0;
  local_8._0_1_ = 0xb;
  ppuStack_f8 = (undefined4 **)0x0;
  pTStack_fc = &CSimpleSecurity::RTTI_Type_Descriptor;
  pTStack_100 = &CComNonAddInSecurity<class_CSimpleSecurity>::RTTI_Type_Descriptor;
  uStack_104 = 0;
  uStack_10c = 0x1000393e;
  pvStack_108 = this;
  piVar4 = (int *)__RTDynamicCast();
  ppuStack_f8 = &local_74;
  local_44 = aOStack_114;
  pTStack_100 = (TypeDescriptor *)0x7;
  uStack_104 = 0;
  aOStack_114[0] = L'\0';
  FUN_10002b20(aOStack_114,(int *)&param_2,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  (**(code **)(*piVar4 + 0x1c))();
  local_78 = local_74;
  puVar6 = local_74;
  if (local_74 != local_70) {
    do {
      local_78 = puVar6;
      if (local_34 < 0) break;
      local_3c = (int *)0x0;
      local_8._0_1_ = 0xe;
      pOVar5 = (LPCOLESTR)Ordinal_2(L"Msxml2.DOMDocument.3.0");
      if (pOVar5 == (LPCOLESTR)0x0) goto LAB_100037d9;
      local_8 = CONCAT31(local_8._1_3_,0xf);
      HVar2 = CLSIDFromProgID(pOVar5,(LPCLSID)local_24);
      if (-1 < HVar2) {
        pOStack_bc = 
        L"䗆໼ｗ吕ȣ茐ᑾ爈謄\xeb06謂㯆痃㌇觿쁽ᓫｐ䠕ȣ謐觸쁽כּ萏ﷆ\xffff䗆ჼ䶍㎰净襦끅ᗿ⍌ဂ쌻谏˱"
        ;
        CoCreateInstance((IID *)local_24,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10022814,&local_3c);
      }
      local_8._0_1_ = 0xe;
      Ordinal_6();
      if (7 < (uint)puVar6[5]) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) {
        local_44 = (LPCOLESTR)0x0;
      }
      else {
        local_44 = (LPCOLESTR)Ordinal_2();
        if (local_44 == (LPCOLESTR)0x0) goto LAB_100037d9;
      }
      pOVar5 = local_44;
      local_8 = CONCAT31(local_8._1_3_,0x10);
      local_54 = (LPCOLESTR)((uint)local_54 & 0xffff0000);
      iVar3 = Ordinal_9();
      if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_10001690(iVar3);
      }
      local_54 = (LPCOLESTR)CONCAT22(local_54._2_2_,8);
      if (pOVar5 == (LPCOLESTR)0x0) {
        local_4c = (int *)0x0;
      }
      else {
        Ordinal_149();
        local_4c = (int *)Ordinal_150();
      }
      if ((local_4c == (int *)0x0) && (pOVar5 != (LPCOLESTR)0x0)) {
        local_54 = (LPCOLESTR)CONCAT22(local_54._2_2_,10);
        local_4c = (int *)0x8007000e;
                    /* WARNING: Subroutine does not return */
        FUN_10001690(0x8007000e);
      }
      local_8._0_1_ = 0x11;
      pOStack_bc = local_54;
      piStack_c0 = local_3c;
      ppOStack_c4 = (LPCOLESTR *)0x10003a90;
      (**(code **)(*local_3c + 0xe8))();
      local_8._0_1_ = 0x10;
      ppOStack_c4 = &local_54;
      pOStack_c8 = L"䗆໼㖋⍔ဂｗ曖綃ﾬ蔏Š";
      Ordinal_9();
      local_8._0_1_ = 0xe;
      piStack_cc = (int *)0x10003aab;
      pOStack_c8 = pOVar5;
      Ordinal_6();
      if (local_58 == -1) {
        local_30 = (int *)0x0;
        local_8._0_1_ = 0x13;
        (**(code **)*local_3c)(local_3c,&DAT_10022844,&local_30);
        local_64 = (int *)0x0;
        local_8._0_1_ = 0x15;
        iVar7 = (**(code **)(*local_30 + 0x34))(local_30,&local_64);
        local_28 = (int *)0x0;
        local_40 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x19);
        local_34 = iVar7;
        iVar3 = (**(code **)(*local_64 + 0x34))(local_64,&local_28);
        while (((local_8._1_3_ = (uint3)(local_8 >> 8), -1 < iVar7 && (-1 < iVar3)) &&
               (local_28 != (int *)0x0))) {
          local_5c = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x1c);
          (**(code **)(*local_28 + 0x60))(local_28,0xffffffff,&local_5c);
          iVar7 = (**(code **)(*local_60 + 0x54))(local_60,local_5c,&local_2c);
          piVar4 = local_2c;
          local_34 = iVar7;
          if (local_2c != (int *)0x0) {
            local_2c = (int *)0x0;
            (**(code **)(*piVar4 + 8))(piVar4);
          }
          if (local_40 != local_28) {
            Ordinal_30(&local_40,local_28);
          }
          piVar4 = local_28;
          if (local_28 != (int *)0x0) {
            local_28 = (int *)0x0;
            (**(code **)(*piVar4 + 8))(piVar4);
            if (local_28 != (int *)0x0) {
              local_28 = (int *)0x0;
            }
          }
          local_8._0_1_ = 0x1a;
          if (local_5c != (int *)0x0) {
            (**(code **)(*local_5c + 8))(local_5c);
          }
          local_8 = CONCAT31(local_8._1_3_,0x19);
          Ordinal_6(0);
          iVar3 = (**(code **)(*local_40 + 0x40))(local_40,&local_28);
        }
        local_8._0_1_ = 0x17;
        if (local_40 != (int *)0x0) {
          (**(code **)(*local_40 + 8))(local_40);
        }
        local_8._0_1_ = 0x15;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))(local_28);
        }
        local_8._0_1_ = 0x13;
        if (local_64 != (int *)0x0) {
          (**(code **)(*local_64 + 8))(local_64);
        }
        local_8._0_1_ = 0xe;
        if (local_30 != (int *)0x0) {
          (**(code **)(*local_30 + 8))(local_30);
        }
      }
      else {
        local_34 = -0x7fffbffb;
      }
      local_8 = CONCAT31(local_8._1_3_,0xb);
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      puVar6 = local_78 + 7;
      local_78 = puVar6;
    } while (puVar6 != local_70);
  }
  puVar1 = local_70;
  local_8._0_1_ = 10;
  puVar6 = local_74;
  if (local_74 != (undefined4 *)0x0) {
    for (; puVar6 != puVar1; puVar6 = puVar6 + 7) {
      if (7 < (uint)puVar6[5]) {
        operator_delete((void *)*puVar6);
      }
      puVar6[5] = 7;
      puVar6[4] = 0;
      *(undefined2 *)puVar6 = 0;
    }
    operator_delete(local_74);
  }
  local_74 = (undefined4 *)0x0;
  local_70 = (undefined4 *)0x0;
  local_6c = 0;
  local_8._0_1_ = 7;
  Ordinal_6(local_7c);
  local_8._0_1_ = 5;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  local_8._0_1_ = 3;
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_60 != (int *)0x0) {
    (**(code **)(*local_60 + 8))(local_60);
  }
  local_8 = 0xffffffff;
  if (7 < in_stack_0000001c) {
    operator_delete(param_2);
  }
  in_stack_0000001c = 7;
  uStack00000018 = 0;
  param_2 = (void *)((uint)param_2 & 0xffff0000);
  ExceptionList = local_10;
  uStack_10c = 0x10003d1a;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10003d50 at 10003d50

undefined4 FUN_10003d50(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  void *in_stack_ffffffcc;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019478;
  local_10 = ExceptionList;
  if ((param_2 != (undefined4 *)0x0) && (param_3 != (int *)0x0)) {
    ExceptionList = &local_10;
    FUN_10017be0((undefined2 *)&stack0xffffffcc,param_3);
    local_8 = 0xffffffff;
    uVar1 = FUN_10003780((void *)(param_1 + -0xc),param_2,in_stack_ffffffcc);
    ExceptionList = local_10;
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_10003de0 at 10003de0

bool __cdecl FUN_10003de0(byte *param_1,byte *param_2)

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



// Function: FUN_10003e50 at 10003e50

void __cdecl FUN_10003e50(wchar_t *param_1,rsize_t param_2,wchar_t *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = wcsncpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80070057);
  }
}



// Function: FUN_10003f10 at 10003f10

int FUN_10003f10(void)

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



// Function: FUN_10003f60 at 10003f60

void __fastcall FUN_10003f60(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  return;
}



// Function: FUN_10003f90 at 10003f90

int FUN_10003f90(int param_1,uint param_2)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_100194c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar1 = Ordinal_56(param_1,param_2,&local_18,&local_14,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*local_14 + 0x1c))(local_14,&param_1), -1 < iVar1)) {
    param_2 = param_2 & 0xffffff;
    iVar1 = Ordinal_68((int)&param_2 + 3);
    if (iVar1 < 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      goto LAB_100040a1;
    }
    if (((param_2._3_1_ != '\x01') ||
        (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
       (pFVar2 = GetProcAddress(hModule,"UnRegisterTypeLibForUser"), pFVar2 == (FARPROC)0x0)) {
      pFVar2 = Ordinal_186_exref;
    }
    iVar1 = (*pFVar2)(param_1,(uint)*(ushort *)(param_1 + 0x18),(uint)*(ushort *)(param_1 + 0x1a),
                      *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
    (**(code **)(*local_14 + 0x30))(local_14,param_1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
LAB_100040a1:
  local_8 = 0xffffffff;
  Ordinal_6(local_18);
  ExceptionList = local_10;
  return iVar1;
}



// Function: FUN_100040c0 at 100040c0

void FUN_100040c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  rsize_t rVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  wchar_t *pwVar4;
  undefined4 local_22c;
  wchar_t *local_228;
  int *local_224;
  char local_21d;
  wchar_t local_21c [259];
  undefined2 local_16;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019532;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_22c = 0;
  local_224 = (int *)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar1 = Ordinal_56(param_1,param_2,&local_22c,&local_224,local_14);
  if (-1 < iVar1) {
    pwVar4 = (wchar_t *)0x0;
    local_228 = (wchar_t *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar1 = (**(code **)(*local_224 + 0x24))(local_224,0xffffffff,0,0,0,&local_228);
    if ((-1 < iVar1) && (local_228 != (wchar_t *)0x0)) {
      rVar2 = Ordinal_7(local_228);
      FUN_10003e50(local_21c,0x104,local_228,rVar2);
      pwVar4 = local_21c;
      local_16 = 0;
      iVar1 = FUN_10003f10();
      local_21c[iVar1] = L'\0';
    }
    local_21d = '\0';
    iVar1 = Ordinal_68(&local_21d);
    if (iVar1 < 0) {
      local_8._0_1_ = 2;
      Ordinal_6(local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_224 != (int *)0x0) {
        (**(code **)(*local_224 + 8))(local_224);
      }
      local_8 = 0xffffffff;
      Ordinal_6(local_22c);
      goto LAB_10004270;
    }
    if (local_21d == '\x01') {
      hModule = GetModuleHandleW(L"OLEAUT32.DLL");
      if (hModule == (HMODULE)0x0) goto LAB_1000421c;
      pFVar3 = GetProcAddress(hModule,"RegisterTypeLibForUser");
      if (pFVar3 == (FARPROC)0x0) goto LAB_1000421c;
    }
    else {
LAB_1000421c:
      pFVar3 = Ordinal_163_exref;
    }
    (*pFVar3)(local_224,local_22c,pwVar4);
    local_8._0_1_ = 2;
    Ordinal_6(local_228);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_224 != (int *)0x0) {
    (**(code **)(*local_224 + 8))(local_224);
  }
  local_8 = 0xffffffff;
  Ordinal_6(local_22c);
LAB_10004270:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10004290 at 10004290

int FUN_10004290(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
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
          (bVar2 = FUN_10003de0(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar5 = (*(code *)puVar1[1])(1);
        if (iVar5 < 0) {
          return iVar5;
        }
        uVar3 = (*(code *)puVar1[7])(1);
        iVar5 = Ordinal_49(*puVar1,uVar3);
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
    iVar5 = FUN_100040c0(*(undefined4 *)(param_1 + 4),0);
  }
  return iVar5;
}



// Function: FUN_10004320 at 10004320

int FUN_10004320(int param_1,int param_2,byte *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
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
          (bVar2 = FUN_10003de0(param_3,(byte *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        uVar3 = (*(code *)puVar1[7])(0);
        iVar5 = Ordinal_49(*puVar1,uVar3);
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
    iVar5 = FUN_10003f90(*(int *)(param_1 + 4),0);
  }
  return iVar5;
}



// Function: FUN_100043b0 at 100043b0

uint __fastcall FUN_100043b0(LPCRITICAL_SECTION param_1)

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



// Function: DllCanUnloadNow at 100043e0

HRESULT DllCanUnloadNow(void)

{
  int iVar1;
  
                    /* 0x43e0  1  DllCanUnloadNow */
  iVar1 = (**(code **)(DAT_10030e5c + 0xc))();
  return (uint)(iVar1 != 0);
}



// Function: FUN_10004400 at 10004400

int __fastcall FUN_10004400(int param_1)

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
  DAT_10030e30 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0x10),0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
    if ((int)DVar2 < 0) {
      DAT_10030e50 = 1;
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x24;
  return param_1;
}



// Function: FUN_10004470 at 10004470

void __fastcall FUN_10004470(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      Ordinal_64((undefined4 *)(param_1 + 4));
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



// Function: FUN_100044c0 at 100044c0

undefined4 FUN_100044c0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_2 == 1) && (DAT_10030e50 != '\0')) {
    uVar1 = 0;
  }
  return uVar1;
}



// Function: DllGetClassObject at 100044e0

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  HRESULT HVar1;
  
                    /* 0x44e0  2  DllGetClassObject */
  HVar1 = Ordinal_15(&DAT_1003126c,rclsid,riid,ppv);
  return HVar1;
}



// Function: FUN_10004500 at 10004500

void __fastcall FUN_10004500(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019568;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      Ordinal_64((undefined4 *)(param_1 + 4),DAT_10030e10 ^ (uint)&stack0xfffffffc);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar1 = *(int **)(param_1 + 0x28);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004580 at 10004580

int FUN_10004580(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100195b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  iVar2 = Ordinal_61(&local_14,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar2) {
    if (param_4 != (int *)0x0) {
      iVar2 = *param_4;
      while (iVar2 != 0) {
        (**(code **)(*local_14 + 0xc))(local_14,iVar2,param_4[1]);
        piVar1 = param_4 + 2;
        param_4 = param_4 + 2;
        iVar2 = *piVar1;
      }
    }
    iVar2 = (**(code **)(*param_1 + 0x14))(local_14);
    if (-1 < iVar2) {
      iVar2 = Ordinal_23(DAT_10031298,param_2,param_3,0,local_14);
    }
  }
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return iVar2;
}



// Function: FUN_10004650 at 10004650

int __fastcall FUN_10004650(int param_1)

{
  uint uVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100195f0;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10004400(param_1);
  DAT_10030e34 = 0xcd707d97;
  DAT_10030e38 = 0x4a6a84cc;
  DAT_10030e3c = 0x15039e99;
  DAT_10030e40 = 0x53dc80a1;
  local_8 = 1;
  piVar2 = DAT_10031274;
  if (DAT_10031274 < DAT_10031278) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(1,uVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_10031278);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10004700 at 10004700

void __fastcall FUN_10004700(int param_1)

{
  uint uVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019620;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar2 = DAT_10031274;
  if (DAT_10031274 < DAT_10031278) {
    do {
      if (*piVar2 != 0) {
        (**(code **)(*piVar2 + 0x20))(0,uVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 < DAT_10031278);
  }
  local_8 = 0xffffffff;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      Ordinal_64((undefined4 *)(param_1 + 4));
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    piVar2 = *(int **)(param_1 + 0x28);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100047b0 at 100047b0

void FUN_100047b0(int *param_1)

{
  (**(code **)(*param_1 + 0xc))(param_1,L"APPID",L"{A40741AB-1DA0-41A8-B375-4683310D610B}");
  return;
}



// Function: FUN_100047d0 at 100047d0

void __fastcall FUN_100047d0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100047e0 at 100047e0

void __fastcall FUN_100047e0(int param_1)

{
  InterlockedDecrement((LONG *)(param_1 + 8));
  return;
}



// Function: FUN_100047f0 at 100047f0

undefined4 __fastcall FUN_100047f0(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function: FUN_10004800 at 10004800

HRESULT __thiscall FUN_10004800(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*(int *)((int)this + 0x28) == 0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_10024cd8,(LPUNKNOWN)0x0,1,(IID *)&DAT_10022ac0,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(**ppv + 4))(*ppv);
  return HVar1;
}



// Function: FUN_10004860 at 10004860

void * __thiscall FUN_10004860(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019648;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004700((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return this;
}



// Function: FUN_100048c0 at 100048c0

int FUN_100048c0(int param_1)

{
  LCID Locale;
  int iVar1;
  wchar_t *local_14;
  wchar_t *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Locale = GetThreadLocale();
  SetThreadLocale(0x800);
  local_14 = L"APPID";
  local_10 = L"{A40741AB-1DA0-41A8-B375-4683310D610B}";
  local_c = 0;
  local_8 = 0;
  iVar1 = FUN_10004580(DAT_10030e30,0x65,1,(int *)&local_14);
  if (((-1 < iVar1) && (iVar1 = FUN_10004290(0x1003126c,param_1,(byte *)0x0), -1 < iVar1)) &&
     (DAT_10030e54 != (code *)0x0)) {
    iVar1 = (*DAT_10030e54)(DAT_10031298);
  }
  SetThreadLocale(Locale);
  return iVar1;
}



// Function: FUN_10004950 at 10004950

int FUN_10004950(int param_1)

{
  LCID Locale;
  int iVar1;
  wchar_t *local_14;
  wchar_t *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Locale = GetThreadLocale();
  SetThreadLocale(0x800);
  if (DAT_10030e58 != (code *)0x0) {
    iVar1 = (*DAT_10030e58)();
    if (iVar1 < 0) goto LAB_1000498d;
  }
  iVar1 = FUN_10004320(0x1003126c,param_1,(byte *)0x0);
LAB_1000498d:
  if (-1 < iVar1) {
    local_14 = L"APPID";
    local_10 = L"{A40741AB-1DA0-41A8-B375-4683310D610B}";
    local_c = 0;
    local_8 = 0;
    iVar1 = FUN_10004580(DAT_10030e30,0x65,0,(int *)&local_14);
  }
  SetThreadLocale(Locale);
  return iVar1;
}



// Function: DllRegisterServer at 100049d0

void DllRegisterServer(void)

{
                    /* 0x49d0  3  DllRegisterServer */
  FUN_100048c0(1);
  return;
}



// Function: DllUnregisterServer at 100049e0

void DllUnregisterServer(void)

{
                    /* 0x49e0  4  DllUnregisterServer */
  FUN_10004950(1);
  return;
}



// Function: FUN_100049f0 at 100049f0

void __fastcall FUN_100049f0(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018d59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004a40 at 10004a40

exception * __thiscall FUN_10004a40(void *this,char *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019931;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,&param_1);
  *(undefined ***)this = std::logic_error::vftable;
  *(undefined ***)this = std::out_of_range::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10004ab0 at 10004ab0

void __fastcall FUN_10004ab0(exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100196b1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  std::exception::~exception(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004b00 at 10004b00

int * __thiscall FUN_10004b00(void *this,int *param_1)

{
                    /* WARNING: Load size is inaccurate */
  if (*this != *param_1) {
    Ordinal_6(*this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return (int *)this;
}



// Function: FUN_10004b30 at 10004b30

undefined4 FUN_10004b30(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((((piVar1 = *(int **)((int)&PTR_DAT_1002e604 + uVar2), *piVar1 != *param_2 ||
           (piVar1[1] != param_2[1])) || (piVar1[2] != param_2[2])) || (piVar1[3] != param_2[3]))) {
    uVar2 = uVar2 + 4;
    if (3 < uVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_10004b80 at 10004b80

undefined4 FUN_10004b80(void)

{
  return 0x80004001;
}



// Function: FUN_10004b90 at 10004b90

undefined4 FUN_10004b90(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x24);
  return 0;
}



// Function: FUN_10004bb0 at 10004bb0

undefined4 FUN_10004bb0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return 0;
}



// Function: FUN_10004bd0 at 10004bd0

undefined4 FUN_10004bd0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  return 0;
}



// Function: FUN_10004bf0 at 10004bf0

undefined4 FUN_10004bf0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  return 0;
}



// Function: FUN_10004c10 at 10004c10

undefined4 FUN_10004c10(void)

{
  return 0x80004001;
}



// Function: FUN_10004c30 at 10004c30

void FUN_10004c30(void)

{
  return;
}



// Function: FUN_10004c40 at 10004c40

void __fastcall FUN_10004c40(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// Function: FUN_10004c50 at 10004c50

void __fastcall FUN_10004c50(undefined4 param_1)

{
  Ordinal_9(param_1);
  return;
}



// Function: FUN_10004c60 at 10004c60

void __fastcall FUN_10004c60(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab6b;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = safearray<enum_GVWRangeEnum,3>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9(param_1 + 2,uVar1,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004cb0 at 10004cb0

void __fastcall FUN_10004cb0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab6b;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = safearray<enum_VehiclePurposeEnum,3>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9(param_1 + 2,uVar1,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10004d00 at 10004d00

undefined4 * __thiscall FUN_10004d00(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abcb;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = safearray<enum_GVWRangeEnum,3>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9((int)this + 8,uVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10004d70 at 10004d70

undefined4 * __thiscall FUN_10004d70(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abcb;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = safearray<enum_VehiclePurposeEnum,3>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9((int)this + 8,uVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10004de0 at 10004de0

exception * __thiscall FUN_10004de0(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019769;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::logic_error::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10004e40 at 10004e40

void __fastcall FUN_10004e40(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HarshHRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10004e50 at 10004e50

void __fastcall FUN_10004e50(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_10004e60 at 10004e60

void FUN_10004e60(undefined4 *param_1,undefined4 param_2)

{
  (**(code **)*param_1)(param_1,&DAT_10022b78,param_2);
  return;
}



// Function: FUN_10004e80 at 10004e80

undefined4 * __thiscall FUN_10004e80(void *this,byte param_1)

{
  *(undefined ***)this =
       CSmartResult<struct_HarshHRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004eb0 at 10004eb0

undefined4 * __thiscall FUN_10004eb0(void *this,byte param_1)

{
  *(undefined ***)this = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10004ee0 at 10004ee0

undefined4 * __fastcall FUN_10004ee0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019708;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002e40((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CSimpleSecurity>::vftable;
  param_1[3] = ATL::CComObject<class_CSimpleSecurity>::vftable;
  (**(code **)(*DAT_10030e30 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: Attach at 10004f50

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



// Function: FUN_10004f70 at 10004f70

void __thiscall FUN_10004f70(void *this,undefined4 param_1,undefined4 param_2)

{
  if (this != (void *)0x0) {
    Ordinal_58((int)this + 4,param_1,param_2);
    return;
  }
  Ordinal_58(0,param_1,param_2);
  return;
}



// Function: FUN_10004fb0 at 10004fb0

void __thiscall FUN_10004fb0(void *this,HKEY param_1,LPCWSTR param_2,uint param_3)

{
  int *piVar1;
  HMODULE hModule;
  int iVar2;
  FARPROC pFVar3;
  HKEY local_8;
  
  piVar1 = *(int **)((int)this + 8);
  local_8 = (HKEY)0x0;
  if (piVar1 == (int *)0x0) {
LAB_1000501a:
    iVar2 = RegOpenKeyExW(param_1,param_2,0,param_3,&local_8);
  }
  else {
    if (*piVar1 == 0) {
      if (piVar1[1] != 0) goto LAB_1000501a;
    }
    else {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule == (HMODULE)0x0) {
        iVar2 = 1;
        goto LAB_1000502f;
      }
      pFVar3 = GetProcAddress(hModule,"RegOpenKeyTransactedW");
      if (pFVar3 != (FARPROC)0x0) {
        iVar2 = (*pFVar3)(param_1,param_2,0,param_3,&local_8,*piVar1,0);
        goto LAB_1000502f;
      }
    }
    iVar2 = 1;
  }
LAB_1000502f:
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



// Function: FUN_10005060 at 10005060

LSTATUS __thiscall FUN_10005060(void *this,LPCWSTR param_1,LPBYTE param_2,uint *param_3)

{
  uint uVar1;
  LPBYTE pBVar2;
  uint *puVar3;
  LSTATUS LVar4;
  
  puVar3 = param_3;
  pBVar2 = param_2;
  uVar1 = *param_3;
  *param_3 = 0;
                    /* WARNING: Load size is inaccurate */
  param_3 = (uint *)(uVar1 * 2);
  LVar4 = RegQueryValueExW(*this,param_1,(LPDWORD)0x0,(LPDWORD)&param_2,param_2,(LPDWORD)&param_3);
  if (LVar4 == 0) {
    if ((param_2 != (LPBYTE)0x1) && (param_2 != (LPBYTE)0x2)) {
      return 0xd;
    }
    if (pBVar2 != (LPBYTE)0x0) {
      if (param_3 == (uint *)0x0) {
        pBVar2[0] = '\0';
        pBVar2[1] = '\0';
      }
      else {
        if (((uint)param_3 & 1) != 0) {
          return 0xd;
        }
        if (*(short *)(pBVar2 + (((uint)param_3 & 0xfffffffe) - 2)) != 0) {
          return 0xd;
        }
      }
    }
    *puVar3 = (uint)param_3 >> 1;
    LVar4 = 0;
  }
  return LVar4;
}



// Function: FUN_100050e0 at 100050e0

void __fastcall FUN_100050e0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  return;
}



// Function: FUN_10005130 at 10005130

void FUN_10005130(void)

{
  return;
}



// Function: FUN_10005140 at 10005140

void __fastcall FUN_10005140(int *param_1)

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



// Function: FUN_10005170 at 10005170

undefined4 FUN_10005170(void)

{
  return 0;
}



// Function: FUN_10005180 at 10005180

void FUN_10005180(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



// Function: FUN_100051a0 at 100051a0

LONG FUN_100051a0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x10))(1);
  }
  return LVar1;
}



// Function: FUN_100051d0 at 100051d0

undefined4 * __thiscall FUN_100051d0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019708;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CSimpleSecurity>::vftable;
  *(undefined ***)((int)this + 0xc) = ATL::CComObject<class_CSimpleSecurity>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x10) = 0xc0000001;
  (**(code **)(*DAT_10030e30 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10002ed0((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005260 at 10005260

void * __cdecl FUN_10005260(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019739;
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
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10027634);
}



// Function: FUN_10005300 at 10005300

void FUN_10005300(int param_1)

{
  FUN_100051a0((int *)(param_1 + -0xc));
  return;
}



// Function: FUN_10005310 at 10005310

void FUN_10005310(int param_1)

{
  FUN_10005180(param_1 + -0xc);
  return;
}



// Function: FUN_10005320 at 10005320

exception * __thiscall FUN_10005320(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019769;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10005380 at 10005380

exception * __thiscall FUN_10005380(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100197a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  std::exception::~exception((exception *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_100053e0 at 100053e0

void __fastcall FUN_100053e0(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



// Function: FUN_10005400 at 10005400

void __fastcall FUN_10005400(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100197c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10030e10 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005450 at 10005450

void FUN_10005450(int param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100197f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_2 == (undefined4 *)0x0) {
    local_8 = 0xffffffff;
    FUN_100054c5();
    return;
  }
  FUN_10004e60(param_2,param_1 + 0x3c);
  local_8 = 0xffffffff;
  FUN_100054c5();
  return;
}



// Function: Catch@100054ae at 100054ae

undefined * Catch_100054ae(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x14) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100054c2;
}



// Function: FUN_100054c5 at 100054c5

void FUN_100054c5(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_100054e0 at 100054e0

undefined4 __thiscall FUN_100054e0(void *this,int *param_1)

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
  puStack_c = &LAB_10019823;
  local_10 = ExceptionList;
  uStack_38 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
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
      local_20 = (uint *)operator_new__(-(uint)(0xfffffffb < uVar8) | uVar8 + 4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_20 != (uint *)0x0) {
        *local_20 = uVar3;
        puVar1 = local_20 + 1;
        _eh_vector_constructor_iterator_(puVar1,0xc,uVar3,FUN_100050e0,FUN_10001740);
        local_8 = 0xffffffff;
        local_18 = puVar1;
        uVar7 = FUN_100055c1();
        return uVar7;
      }
      local_18 = (uint *)0x0;
      local_8 = 0xffffffff;
      uVar7 = FUN_100055c1();
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



// Function: Catch@100055b1 at 100055b1

undefined * Catch_100055b1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_100055be;
}



// Function: FUN_100055c1 at 100055c1

undefined4 FUN_100055c1(void)

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



// Function: FUN_100056d0 at 100056d0

void FUN_100056d0(int param_1)

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
      _eh_vector_destructor_iterator_(pvVar2,0xc,*(int *)((int)pvVar2 + -4),FUN_10001740);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



// Function: FUN_10005730 at 10005730

undefined4 * __thiscall FUN_10005730(void *this,int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001984b;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = (int *)operator_new(0xc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[1] = 0;
    piVar2[2] = 1;
    iVar3 = Ordinal_2(param_1,uVar1);
    *piVar2 = iVar3;
    if ((iVar3 == 0) && (param_1 != 0)) {
      FUN_10018b30(0x8007000e);
    }
  }
  local_8 = 0xffffffff;
  *(int **)this = piVar2;
  if (piVar2 == (int *)0x0) {
    FUN_10018b30(0x8007000e);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100057e0 at 100057e0

void __fastcall FUN_100057e0(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



// Function: FUN_10005800 at 10005800

bool __thiscall FUN_10005800(void *this,undefined4 *param_1)

{
  bool bVar1;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100198a0;
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
    (**(code **)**this)(*this,&DAT_10022c74,&local_18,DAT_10030e10 ^ (uint)&stack0xfffffffc);
    (**(code **)*param_1)(param_1,&DAT_10022c74,&local_14);
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



// Function: FUN_100058f0 at 100058f0

void __fastcall FUN_100058f0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100198d3;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005970 at 10005970

void __fastcall FUN_10005970(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100198d3;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100059f0 at 100059f0

void __fastcall FUN_100059f0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100198d3;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005a70 at 10005a70

void __fastcall FUN_10005a70(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100198d3;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComUnitDefinitionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10005af0 at 10005af0

void FUN_10005af0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_10022c1c,param_2,param_3);
  return;
}



// Function: FUN_10005b10 at 10005b10

undefined4 * __thiscall FUN_10005b10(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019903;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005ba0 at 10005ba0

undefined4 * __thiscall FUN_10005ba0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019903;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005c30 at 10005c30

undefined4 * __thiscall FUN_10005c30(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019903;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005cc0 at 10005cc0

undefined4 * __thiscall FUN_10005cc0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019903;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComUnitDefinitionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
       ::vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10005d50 at 10005d50

uint __thiscall FUN_10005d50(void *this,ushort *param_1,uint param_2,uint param_3)

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
          if (iVar5 == 0) goto LAB_10005dac;
        }
        if (puVar2 == (ushort *)0x0) break;
        puVar6 = puVar2;
        puVar8 = param_1;
        uVar3 = param_3;
        if (param_3 == 0) {
LAB_10005dd5:
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
          if (uVar3 == 0) goto LAB_10005dd5;
        }
        if ((-(uint)(*puVar6 < *puVar8) & 0xfffffffe) == 0xffffffff) goto LAB_10005dd5;
        iVar5 = (int)puVar2 - (int)puVar1;
        puVar1 = puVar2 + 1;
      }
    }
LAB_10005dac:
    param_2 = 0xffffffff;
  }
  return param_2;
}



// Function: FUN_10005e10 at 10005e10

exception * __thiscall FUN_10005e10(void *this,exception *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019931;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception((exception *)this,param_1);
  *(undefined ***)this = std::logic_error::vftable;
  *(undefined ***)this = std::out_of_range::vftable;
  ExceptionList = local_10;
  return (exception *)this;
}



// Function: FUN_10005e80 at 10005e80

undefined4 FUN_10005e80(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



// Function: FUN_10005ee0 at 10005ee0

undefined4 FUN_10005ee0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    (**(code **)(*DAT_10030e30 + 4))();
    return 0;
  }
  (**(code **)(*DAT_10030e30 + 8))();
  return 0;
}



// Function: FUN_10005f10 at 10005f10

DWORD __fastcall FUN_10005f10(int param_1)

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



// Function: FUN_10005f50 at 10005f50

void __fastcall FUN_10005f50(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  *param_1 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  param_1[3] = 0x80004005;
  return;
}



// Function: FUN_10005f70 at 10005f70

DWORD FUN_10005f70(undefined4 *param_1)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019950;
  local_10 = ExceptionList;
  if (param_1 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_1 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10004ee0(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_10006014();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_10006014();
  return DVar2;
}



// Function: Catch@10006001 at 10006001

undefined * Catch_10006001(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000600e;
}



// Function: FUN_10006014 at 10006014

DWORD FUN_10006014(void)

{
  BOOL BVar1;
  int unaff_EBP;
  DWORD unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) goto LAB_1000605c;
  unaff_ESI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_EDI + 5),0);
  if (BVar1 == 0) {
    unaff_ESI = GetLastError();
    if (0 < (int)unaff_ESI) {
      unaff_ESI = unaff_ESI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_ESI) goto LAB_10006043;
  }
  else {
LAB_10006043:
    *(undefined1 *)(unaff_EDI + 0xb) = 1;
    if (-1 < (int)unaff_ESI) {
      unaff_ESI = 0;
      goto LAB_1000605c;
    }
  }
  (**(code **)(*unaff_EDI + 0x10))(1);
  unaff_EDI = (int *)0x0;
LAB_1000605c:
  **(undefined4 **)(unaff_EBP + 8) = unaff_EDI;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_ESI;
}



// Function: FUN_10006080 at 10006080

uint __thiscall FUN_10006080(void *this,uint param_1,uint param_2,ushort *param_3,uint param_4)

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
LAB_100060e8:
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
      goto LAB_100060e8;
    }
    puVar1 = puVar1 + 1;
    param_3 = param_3 + 1;
    uVar2 = uVar2 - 1;
  } while( true );
}



// Function: FUN_10006110 at 10006110

void FUN_10006110(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10005af0(param_1 + -0xc,param_2,param_3);
  return;
}



// Function: FUN_10006120 at 10006120

void __fastcall FUN_10006120(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019996;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100061a0 at 100061a0

void FUN_100061a0(undefined4 param_1,int *param_2)

{
  char *pcVar1;
  undefined **local_4c [2];
  short local_44 [4];
  int local_3c;
  undefined4 local_34;
  int *local_2c;
  undefined4 local_28;
  char *local_24;
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100199e9;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2c = param_2;
  local_4c[0] = safearray<enum_VehiclePurposeEnum,3>::vftable;
  Ordinal_8(local_44,local_14);
  local_34 = 0;
  local_44[0] = 0x2003;
  local_8 = 1;
  local_24 = (char *)0x0;
  local_28 = 3;
  local_3c = Ordinal_15(3,1,&local_28);
  local_20 = (undefined **)0x0;
  local_1c = 1;
  local_18 = 2;
  pcVar1 = (char *)0x0;
  do {
    if ((local_3c == 0) || (local_44[0] == 0)) {
      local_24 = "array not initialized";
      std::exception::exception((exception *)&local_20,&local_24);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fc4);
    }
    if (*(int *)(local_3c + 0x10) <= (int)pcVar1) {
      local_24 = "index is out of range";
      std::exception::exception((exception *)&local_20,&local_24);
      local_20 = std::out_of_range::vftable;
      local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fd4);
    }
    local_24 = pcVar1;
    FUN_1000ba50(local_4c,&local_24);
    pcVar1 = pcVar1 + 1;
  } while ((int)pcVar1 < 3);
  Ordinal_24(local_3c);
  *local_2c = local_3c;
  local_44[0] = 0;
  local_34 = 0;
  local_4c[0] = safearray<enum_VehiclePurposeEnum,3>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9(local_44);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006320 at 10006320

int __fastcall FUN_10006320(int param_1)

{
  int *piVar1;
  int *local_8;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    local_8 = (int *)0x0;
    FUN_10005f70(&local_8);
    piVar1 = local_8;
    (**(code **)(*local_8 + 4))(local_8);
    (**(code **)*piVar1)(piVar1,&DAT_10022b78,param_1 + 0x4c);
  }
  return param_1 + 0x4c;
}



// Function: FUN_10006360 at 10006360

void __fastcall FUN_10006360(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019a2e;
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



// Function: FUN_100063d0 at 100063d0

undefined4 * __thiscall FUN_100063d0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019a6e;
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



// Function: FUN_10006450 at 10006450

void __fastcall FUN_10006450(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100198d3;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    param_1[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100064d0 at 100064d0

undefined4 __thiscall FUN_100064d0(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_10005800(this,(undefined4 *)*param_1);
  if (!bVar1) {
    uVar2 = Ordinal_31(this,*param_1,&DAT_10022ccc);
    return uVar2;
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_10006510 at 10006510

undefined4 * __thiscall FUN_10006510(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019903;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 0;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100065a0 at 100065a0

void __fastcall FUN_100065a0(undefined4 *param_1)

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



// Function: FUN_10006630 at 10006630

LONG FUN_10006630(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedIncrement((LONG *)(param_1 + 4));
  if (LVar1 == 2) {
    (**(code **)(*DAT_10030e30 + 4))();
  }
  return LVar1;
}



// Function: FUN_10006660 at 10006660

LONG FUN_10006660(int *param_1)

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
    (**(code **)(*DAT_10030e30 + 8))();
  }
  return LVar1;
}



// Function: FUN_100066b0 at 100066b0

void FUN_100066b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_10022cf8,param_2,param_3);
  return;
}



// Function: FUN_100066d0 at 100066d0

undefined4 * __thiscall FUN_100066d0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019b06;
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



// Function: FUN_10006760 at 10006760

void __fastcall FUN_10006760(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_10019ba5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  piVar1 = *(int **)(param_1 + 0x4c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  }
  local_8._0_1_ = 1;
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 6;
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  if (*(char *)(param_1 + 0x30) != '\0') {
    *(undefined1 *)(param_1 + 0x30) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10006850 at 10006850

void __fastcall FUN_10006850(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019bc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10006760(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100068a0 at 100068a0

int * __thiscall FUN_100068a0(void *this,undefined4 *param_1,uint param_2,uint param_3)

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
      FUN_10001f90(this,uVar1);
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



// Function: FUN_100069b0 at 100069b0

int * __thiscall FUN_100069b0(void *this,uint param_1,int *param_2,uint param_3,uint param_4)

{
  code *pcVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  int *piVar5;
  uint extraout_ECX;
  uint uVar6;
  
  uVar6 = *(uint *)((int)this + 0x10);
  if ((param_1 <= uVar6) && (param_3 <= (uint)param_2[4])) {
    uVar2 = param_2[4] - param_3;
    if (uVar2 < param_4) {
      param_4 = uVar2;
    }
    if (-uVar6 - 1 <= param_4) {
      std::_Xlength_error("string too long");
      uVar6 = extraout_ECX;
    }
    if (param_4 != 0) {
      uVar6 = uVar6 + param_4;
      if (0x7ffffffe < uVar6) {
        std::_Xlength_error("string too long");
      }
      if (*(uint *)((int)this + 0x14) < uVar6) {
        FUN_10001f90(this,uVar6);
        if (uVar6 == 0) {
          return (int *)this;
        }
      }
      else if (uVar6 == 0) {
        *(undefined4 *)((int)this + 0x10) = 0;
        if (*(uint *)((int)this + 0x14) < 8) {
          *(undefined2 *)this = 0;
          return (int *)this;
        }
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      pvVar3 = this;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar3 = *this;
        pvVar4 = *this;
      }
      FUN_10001670((void *)((int)pvVar3 + (param_1 + param_4) * 2),
                   (void *)((int)pvVar4 + param_1 * 2),*(int *)((int)this + 0x10) - param_1);
      if ((int *)this == param_2) {
        uVar2 = param_3 + param_4;
        if (param_3 <= param_1) {
          uVar2 = param_3;
        }
        if (*(uint *)((int)this + 0x14) < 8) {
          FUN_10001670((void *)((int)this + param_1 * 2),(void *)((int)this + uVar2 * 2),param_4);
        }
        else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          FUN_10001670((void *)(*this + param_1 * 2),(void *)(*this + uVar2 * 2),param_4);
        }
      }
      else {
        if (7 < (uint)param_2[5]) {
          param_2 = (int *)*param_2;
        }
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        memcpy((void *)((int)pvVar4 + param_1 * 2),(void *)((int)param_2 + param_3 * 2),param_4 * 2)
        ;
      }
      FUN_10001a30(this,uVar6);
    }
    return (int *)this;
  }
  std::_Xout_of_range("invalid string position");
  pcVar1 = (code *)swi(3);
  piVar5 = (int *)(*pcVar1)();
  return piVar5;
}



// Function: FUN_10006b30 at 10006b30

void __fastcall FUN_10006b30(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019bfb;
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



// Function: FUN_10006ba0 at 10006ba0

undefined4 * __thiscall FUN_10006ba0(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019bfb;
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



// Function: FUN_10006c20 at 10006c20

void FUN_10006c20(undefined4 param_1)

{
  FUN_10004580(DAT_10030e30,0x67,param_1,(int *)0x0);
  return;
}



// Function: FUN_10006c40 at 10006c40

undefined4 FUN_10006c40(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uStack_2c;
  LPOLESTR local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019c20;
  local_10 = ExceptionList;
  uStack_2c = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_18 = 0x70001003;
  local_8 = 0;
  StringFromCLSID((IID *)&DAT_10024cb8,&local_1c);
  puVar1 = (undefined4 *)FUN_10006320(param_1 + -4);
  (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,local_1c);
  puVar1 = (undefined4 *)FUN_10006320(param_1 + -4);
  uVar2 = (**(code **)(*(int *)*puVar1 + 0x1c))((int *)*puVar1,*(undefined4 *)(param_1 + 8),param_2)
  ;
  ExceptionList = local_10;
  return uVar2;
}



// Function: Catch@10006cdc at 10006cdc

undefined4 Catch_10006cdc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10006cc5;
}



// Function: FUN_10006cf0 at 10006cf0

void FUN_10006cf0(undefined4 param_1,int param_2,int *param_3)

{
  char **ppcVar1;
  char *pcVar2;
  undefined **local_4c [2];
  short local_44 [4];
  int local_3c;
  undefined4 local_34;
  undefined4 local_2c;
  char *local_28;
  char *local_24;
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019c8b;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_4c[0] = safearray<enum_GVWRangeEnum,3>::vftable;
  Ordinal_8(local_44,local_14);
  local_34 = 0;
  local_44[0] = 0x2003;
  local_8 = 1;
  local_28 = (char *)0x0;
  if (param_2 == 1) {
    local_20 = (undefined **)0x0;
    local_1c = 1;
    local_18 = 2;
    local_2c = 3;
    local_3c = Ordinal_15(3,1,&local_2c);
    pcVar2 = (char *)0x0;
    do {
      if ((local_3c == 0) || (local_44[0] == 0)) {
LAB_10006e4d:
        local_24 = "array not initialized";
        ppcVar1 = &local_24;
LAB_10006e57:
        std::exception::exception((exception *)&local_20,ppcVar1);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fc4);
      }
      if (*(int *)(local_3c + 0x10) <= (int)pcVar2) {
        local_24 = "index is out of range";
        std::exception::exception((exception *)&local_20,&local_24);
        local_20 = std::out_of_range::vftable;
        local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fd4);
      }
      local_24 = pcVar2;
      FUN_1000ba50(local_4c,&local_24);
      pcVar2 = pcVar2 + 1;
    } while ((int)pcVar2 < 3);
  }
  else if (param_2 == 2) {
    local_20 = (undefined **)0x0;
    local_1c = 3;
    local_18 = 4;
    local_2c = 3;
    local_3c = Ordinal_15(3,1,&local_2c);
    pcVar2 = (char *)0x0;
    do {
      if ((local_3c == 0) || (local_44[0] == 0)) goto LAB_10006e4d;
      if (*(int *)(local_3c + 0x10) <= (int)pcVar2) {
        local_24 = "index is out of range";
        std::exception::exception((exception *)&local_20,&local_24);
        local_20 = std::out_of_range::vftable;
        local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fd4);
      }
      local_24 = pcVar2;
      FUN_1000ba50(local_4c,&local_24);
      pcVar2 = pcVar2 + 1;
    } while ((int)pcVar2 < 3);
  }
  else {
    local_24 = (char *)0x0;
    local_2c = 1;
    local_3c = Ordinal_15(3,1,&local_2c);
    pcVar2 = (char *)0x0;
    do {
      if ((local_3c == 0) || (local_44[0] == 0)) {
        local_28 = "array not initialized";
        ppcVar1 = &local_28;
        goto LAB_10006e57;
      }
      if (*(int *)(local_3c + 0x10) <= (int)pcVar2) {
        local_28 = "index is out of range";
        std::exception::exception((exception *)&local_20,&local_28);
        local_20 = std::out_of_range::vftable;
        local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fd4);
      }
      local_28 = pcVar2;
      FUN_1000ba50(local_4c,&local_28);
      pcVar2 = pcVar2 + 1;
    } while ((int)pcVar2 < 1);
  }
  Ordinal_24(local_3c);
  *param_3 = local_3c;
  local_44[0] = 0;
  local_34 = 0;
  local_4c[0] = safearray<enum_GVWRangeEnum,3>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9(local_44);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10006fb0 at 10006fb0

bool __thiscall FUN_10006fb0(void *this,int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 local_c;
  int *local_8;
  
  local_c = 0;
  if (*(int *)((int)this + 0x4c) == 0) {
    local_8 = (int *)0x0;
    FUN_10005f70(&local_8);
    piVar1 = local_8;
    (**(code **)(*local_8 + 4))(local_8);
    (**(code **)*piVar1)(piVar1,&DAT_10022b78,(undefined4 *)((int)this + 0x4c));
  }
  piVar1 = *(int **)((int)this + 0x4c);
  if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)*param_1;
  }
  (**(code **)(*piVar1 + 0x20))(piVar1,uVar2,&local_c);
  return (short)local_c == -1;
}



// Function: FUN_10007020 at 10007020

void __thiscall FUN_10007020(void *this,undefined4 param_1)

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
  puStack_c = &LAB_10019d29;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_10007293;
  lpCriticalSection = (LPCRITICAL_SECTION)((int)DAT_10030e30 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    piVar1 = *(int **)((int)this + 4);
    local_228 = (int *)0x0;
    if (((((DAT_10030e34 == *piVar1) && (DAT_10030e38 == piVar1[1])) && (DAT_10030e3c == piVar1[2]))
        && ((DAT_10030e40 == piVar1[3] && (*(short *)((int)this + 8) == -1)))) &&
       (*(short *)((int)this + 10) == -1)) {
      DVar3 = GetModuleFileNameW(DAT_10031298,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_10007261;
      local_220 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = Ordinal_161(local_21c,&local_228);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_10005140((int *)&local_220);
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
        iVar4 = (**(code **)*local_22c)(local_22c,&DAT_10022c50,&local_220);
        if (-1 < iVar4) {
          FUN_100064d0(&local_224,&local_220);
        }
        *(int **)((int)this + 0xc) = local_224;
        local_224 = (int *)0x0;
        FUN_10004f70(DAT_10030e30,FUN_100056d0,this);
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
LAB_10007261:
  if ((*(int **)((int)this + 0xc) != (int *)0x0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_100054e0(this,*(int **)((int)this + 0xc));
  }
  local_8 = 0xffffffff;
  LeaveCriticalSection(lpCriticalSection);
LAB_10007293:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100072c0 at 100072c0

undefined4 FUN_100072c0(void)

{
  return 0;
}



// Function: FUN_100072d0 at 100072d0

undefined4 FUN_100072d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10022d48,param_1 + 4);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_10007300 at 10007300

undefined4 FUN_10007300(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 8);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10022c74,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_10007340 at 10007340

undefined4 FUN_10007340(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    Ordinal_30(param_1 + 4,0);
  }
  if (*(int *)(param_1 + 8) != 0) {
    Ordinal_30(param_1 + 8,0);
  }
  return 1;
}



// Function: FUN_10007380 at 10007380

DWORD FUN_10007380(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019d6b;
  local_10 = ExceptionList;
  if (param_3 != (undefined4 *)0x0) {
    ExceptionList = &local_10;
    *param_3 = 0;
    local_8 = 0;
    puVar1 = (undefined4 *)operator_new(0x28);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100065a0(puVar1);
    }
    local_8 = 0xffffffff;
    DVar2 = FUN_10007426();
    return DVar2;
  }
  return 0x80004003;
}



// Function: Catch@10007413 at 10007413

undefined * Catch_10007413(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10007420;
}



// Function: FUN_10007426 at 10007426

DWORD FUN_10007426(void)

{
  BOOL BVar1;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  
  if (unaff_ESI == (int *)0x0) goto LAB_10007483;
  unaff_ESI[9] = *(int *)(unaff_EBP + 8);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 2),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_1000745b;
  }
  else {
LAB_1000745b:
    *(undefined1 *)(unaff_ESI + 8) = 1;
    if (-1 < (int)unaff_EDI) {
      unaff_EDI = (**(code **)*unaff_ESI)();
      if (unaff_EDI == 0) goto LAB_10007483;
    }
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_10007483:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_100074a0 at 100074a0

undefined4 * __thiscall
FUN_100074a0(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019df4;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 2;
  piVar3 = FUN_10017aa0((int *)&param_2,param_2);
  local_8._0_1_ = 3;
  uVar4 = (**(code **)(**(int **)((int)this + 4) + 0x30))
                    (*(int **)((int)this + 4),*piVar3,1,&local_18,uVar2);
  puVar1 = param_3;
  *param_3 = uVar4;
  local_8._0_1_ = 2;
  Ordinal_6(param_2);
  local_14 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,5);
  if (local_18 != (int *)0x0) {
    uVar4 = (**(code **)*local_18)(local_18,&DAT_10022b88,&local_14);
    *puVar1 = uVar4;
  }
  param_2 = param_1 + 1;
  *param_2 = local_14;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  *param_1 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),2);
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  local_8 = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100075a0 at 100075a0

int * __thiscall FUN_100075a0(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int extraout_EAX;
  int iVar3;
  void *pvVar4;
  int *extraout_EDX;
  int *extraout_EDX_00;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    piVar2 = (int *)this;
    if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
      piVar2 = *this;
    }
    if (piVar2 <= param_1) {
      pvVar4 = this;
      if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      if (param_1 < (int *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2)) {
        pvVar4 = this;
        if (7 < uVar1) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        piVar2 = FUN_100068a0(this,(undefined4 *)this,(int)param_1 - (int)pvVar4 >> 1,param_2);
        return piVar2;
      }
    }
  }
  iVar3 = *(int *)((int)this + 0x10);
  piVar2 = param_1;
  if (-iVar3 - 1U <= param_2) {
    std::_Xlength_error("string too long");
    iVar3 = extraout_EAX;
    piVar2 = extraout_EDX;
  }
  if (param_2 != 0) {
    uVar1 = iVar3 + param_2;
    if (0x7ffffffe < uVar1) {
      std::_Xlength_error("string too long");
      piVar2 = extraout_EDX_00;
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_10001f90(this,uVar1);
      piVar2 = param_1;
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
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    memcpy((void *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2),piVar2,param_2 * 2);
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



// Function: FUN_100076c0 at 100076c0

int * __thiscall FUN_100076c0(void *this,uint param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  uint extraout_ECX;
  uint uVar5;
  
  if (param_2 != (int *)0x0) {
    uVar2 = *(uint *)((int)this + 0x14);
    piVar1 = (int *)this;
    if (7 < uVar2) {
                    /* WARNING: Load size is inaccurate */
      piVar1 = *this;
    }
    if (piVar1 <= param_2) {
      pvVar4 = this;
      if (7 < uVar2) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      if (param_2 < (int *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2)) {
        pvVar4 = this;
        if (7 < uVar2) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        piVar1 = FUN_100069b0(this,param_1,(int *)this,(int)param_2 - (int)pvVar4 >> 1,param_3);
        return piVar1;
      }
    }
  }
  uVar2 = *(uint *)((int)this + 0x10);
  if (uVar2 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar2 = extraout_EAX;
  }
  uVar5 = param_3;
  if (-uVar2 - 1 <= param_3) {
    std::_Xlength_error("string too long");
    uVar2 = extraout_EAX_00;
    uVar5 = extraout_ECX;
  }
  if (uVar5 != 0) {
    uVar2 = uVar2 + uVar5;
    if (0x7ffffffe < uVar2) {
      std::_Xlength_error("string too long");
    }
    if (*(uint *)((int)this + 0x14) < uVar2) {
      FUN_10001f90(this,uVar2);
      if (uVar2 == 0) {
        return (int *)this;
      }
    }
    else if (uVar2 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (*(uint *)((int)this + 0x14) < 8) {
        *(undefined2 *)this = 0;
        return (int *)this;
      }
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    pvVar3 = this;
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar3 = *this;
      pvVar4 = *this;
    }
    FUN_10001670((void *)((int)pvVar3 + (param_1 + param_3) * 2),(void *)((int)pvVar4 + param_1 * 2)
                 ,*(int *)((int)this + 0x10) - param_1);
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    memcpy((void *)((int)pvVar4 + param_1 * 2),param_2,param_3 * 2);
    FUN_10001a30(this,uVar2);
  }
  return (int *)this;
}



// Function: FUN_10007810 at 10007810

bool __cdecl FUN_10007810(void *param_1,ushort *param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(param_2 + 8);
  if (7 < *(uint *)(param_2 + 10)) {
    param_2 = *(ushort **)param_2;
  }
  uVar2 = FUN_10006080(param_1,0,*(uint *)((int)param_1 + 0x10),param_2,*puVar1);
  return (bool)('\x01' - (uVar2 != 0));
}



// Function: FUN_10007840 at 10007840

int __fastcall FUN_10007840(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019e85;
  local_10 = ExceptionList;
  uVar3 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)(param_1 + 0x30) = 0;
  piVar1 = (int *)(param_1 + 8);
  *(undefined ***)(param_1 + 4) =
       CComECMPropertyPageHelperImpl<class_CVehicleClassificationLogicImpl>::vftable;
  *piVar1 = 0;
  piVar2 = (int *)(param_1 + 0xc);
  *piVar2 = 0;
  local_8 = 6;
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0,uVar3);
  }
  if (*piVar2 != 0) {
    Ordinal_30(piVar2,0,uVar3);
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0x19;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x34) = 1;
  *(undefined4 *)(param_1 + 0x38) = 2;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10007950 at 10007950

undefined4 __thiscall
FUN_10007950(void *this,undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4,
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
    uVar2 = FUN_10007020(this,param_4);
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
              if (*piVar7 != *piVar8) goto LAB_10007a1e;
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
LAB_10007a1e:
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



// Function: FUN_10007a70 at 10007a70

undefined4 FUN_10007a70(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002ee90 == (int *)0x0) {
    uVar1 = FUN_10007020(&PTR_DAT_1002ee84,param_3);
  }
  *param_4 = DAT_1002ee90;
  if (DAT_1002ee90 != (int *)0x0) {
    (**(code **)(*DAT_1002ee90 + 4))(DAT_1002ee90);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10007ad0 at 10007ad0

void FUN_10007ad0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10007950(&PTR_DAT_1002ee84,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007b00 at 10007b00

void FUN_10007b00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002ee90 == (int *)0x0) || (DAT_1002ee98 == 0)) {
    FUN_10007020(&PTR_DAT_1002ee84,param_4);
  }
  if (DAT_1002ee90 != (int *)0x0) {
    (**(code **)(*DAT_1002ee90 + 0x2c))
              (DAT_1002ee90,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10007b60 at 10007b60

undefined2 * __thiscall FUN_10007b60(void *this,undefined2 *param_1,uint param_2,uint param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100191b9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_10002b20(param_1,(int *)this,param_2,param_3);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10007be0 at 10007be0

undefined4 * __fastcall FUN_10007be0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019ea8;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10007840((int)param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CVehicleClassificationLogicImpl>::vftable;
  param_1[1] = ATL::CComObject<class_CVehicleClassificationLogicImpl>::vftable;
  param_1[4] = ATL::CComObject<class_CVehicleClassificationLogicImpl>::vftable;
  (**(code **)(*DAT_10030e30 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10007c60 at 10007c60

undefined4 FUN_10007c60(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined4 **)(param_1 + param_4);
  uVar2 = 0x80004002;
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = (**(code **)*puVar1)(puVar1,param_2,param_3);
  }
  return uVar2;
}



// Function: FUN_10007c90 at 10007c90

void FUN_10007c90(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



// Function: FUN_10007cb0 at 10007cb0

LONG FUN_10007cb0(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x14))(1);
  }
  return LVar1;
}



// Function: FUN_10007ce0 at 10007ce0

void FUN_10007ce0(int param_1)

{
  FUN_10007cb0((int *)(param_1 + -4));
  return;
}



// Function: FUN_10007cf0 at 10007cf0

void FUN_10007cf0(int param_1)

{
  FUN_10007c90(param_1 + -4);
  return;
}



// Function: FUN_10007d00 at 10007d00

void FUN_10007d00(int param_1)

{
  FUN_10007cb0((int *)(param_1 + -0x10));
  return;
}



// Function: FUN_10007d10 at 10007d10

void FUN_10007d10(int param_1)

{
  FUN_10007c90(param_1 + -0x10);
  return;
}



// Function: FUN_10007d20 at 10007d20

void FUN_10007d20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1,&PTR_DAT_10022df0,param_2,param_3);
  return;
}



// Function: FUN_10007d40 at 10007d40

void FUN_10007d40(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007d20(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_10007d50 at 10007d50

void FUN_10007d50(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007d20(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10007d60 at 10007d60

int __fastcall FUN_10007d60(int param_1)

{
  return param_1 + 0x10;
}



// Function: FUN_10007d70 at 10007d70

undefined4 * __thiscall FUN_10007d70(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ea8;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComObject<class_CVehicleClassificationLogicImpl>::vftable;
  *(undefined ***)((int)this + 4) = ATL::CComObject<class_CVehicleClassificationLogicImpl>::vftable;
  *(undefined ***)((int)this + 0x10) =
       ATL::CComObject<class_CVehicleClassificationLogicImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 0x14) = 0xc0000001;
  piVar1 = *(int **)((int)this + 0x48);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)this + 0x48) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  (**(code **)(*DAT_10030e30 + 8))();
  local_8 = 0xffffffff;
  FUN_10006760((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10007e10 at 10007e10

undefined4 FUN_10007e10(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_1002f0a4 == (int *)0x0) {
    uVar1 = FUN_10007020(&PTR_DAT_1002f098,param_3);
  }
  *param_4 = DAT_1002f0a4;
  if (DAT_1002f0a4 != (int *)0x0) {
    (**(code **)(*DAT_1002f0a4 + 4))(DAT_1002f0a4);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10007e70 at 10007e70

void FUN_10007e70(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10007950(&PTR_DAT_1002f098,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10007ea0 at 10007ea0

void FUN_10007ea0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_1002f0a4 == (int *)0x0) || (DAT_1002f0ac == 0)) {
    FUN_10007020(&PTR_DAT_1002f098,param_4);
  }
  if (DAT_1002f0a4 != (int *)0x0) {
    (**(code **)(*DAT_1002f0a4 + 0x2c))
              (DAT_1002f0a4,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10007f00 at 10007f00

void FUN_10007f00(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x14) + 4))(*(int **)(param_1 + 0x14));
  return;
}



// Function: FUN_10007f20 at 10007f20

void FUN_10007f20(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x14) + 8))(*(int **)(param_1 + 0x14));
  return;
}



// Function: FUN_10007f40 at 10007f40

void FUN_10007f40(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x14))(*(undefined4 **)(param_1 + 0x14),param_2,param_3);
  return;
}



// Function: FUN_10007f60 at 10007f60

undefined4 __fastcall FUN_10007f60(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



// Function: FUN_10007f70 at 10007f70

void FUN_10007f70(int param_1)

{
  FUN_10007f00(param_1 + -0x10);
  return;
}



// Function: FUN_10007f80 at 10007f80

void FUN_10007f80(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007f40(param_1 + -0x10,param_2,param_3);
  return;
}



// Function: FUN_10007f90 at 10007f90

void FUN_10007f90(int param_1)

{
  FUN_10007f20(param_1 + -4);
  return;
}



// Function: FUN_10007fa0 at 10007fa0

void FUN_10007fa0(int param_1)

{
  FUN_10007f00(param_1 + -4);
  return;
}



// Function: FUN_10007fb0 at 10007fb0

void FUN_10007fb0(int param_1)

{
  FUN_10007f20(param_1 + -0x10);
  return;
}



// Function: FUN_10007fc0 at 10007fc0

void FUN_10007fc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10007f40(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10007fe0 at 10007fe0

undefined4 * __thiscall FUN_10007fe0(void *this,int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b62b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  FUN_10002b20((undefined2 *)((int)this + 0x10),(int *)(param_1 + 0x10),0,0xffffffff);
  *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008070 at 10008070

void __fastcall FUN_10008070(undefined4 *param_1)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    LVar2 = InterlockedDecrement(piVar1 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    *param_1 = 0;
  }
  return;
}



// Function: FUN_100080c0 at 100080c0

undefined4 __fastcall FUN_100080c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)*param_1;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[2] == 1)) {
    uVar3 = *puVar1;
    *puVar1 = 0;
    FUN_10008070(param_1);
    return uVar3;
  }
  FUN_10018b30(0x80004003);
  pcVar2 = (code *)swi(3);
  uVar3 = (*pcVar2)();
  return uVar3;
}



// Function: FUN_100080f0 at 100080f0

DWORD FUN_100080f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019ed0;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x50);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10007be0(puVar1);
    local_8 = 0xffffffff;
    DVar2 = FUN_10008197();
    return DVar2;
  }
  local_8 = 0xffffffff;
  DVar2 = FUN_10008197();
  return DVar2;
}



// Function: Catch@10008184 at 10008184

undefined * Catch_10008184(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10008191;
}



// Function: FUN_10008197 at 10008197

DWORD FUN_10008197(void)

{
  BOOL BVar1;
  LPUNKNOWN punkOuter;
  int unaff_EBP;
  int *unaff_ESI;
  DWORD unaff_EDI;
  LPUNKNOWN *ppunkMarshal;
  
  if (unaff_ESI == (int *)0x0) goto LAB_10008226;
  InterlockedIncrement(unaff_ESI + 5);
  unaff_EDI = 0;
  BVar1 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 6),0);
  if (BVar1 == 0) {
    unaff_EDI = GetLastError();
    if (0 < (int)unaff_EDI) {
      unaff_EDI = unaff_EDI & 0xffff | 0x80070000;
    }
    if (-1 < (int)unaff_EDI) goto LAB_100081d4;
  }
  else {
LAB_100081d4:
    *(undefined1 *)(unaff_ESI + 0xc) = 1;
    if (-1 < (int)unaff_EDI) {
      ppunkMarshal = (LPUNKNOWN *)(unaff_ESI + 0x12);
      punkOuter = (LPUNKNOWN)(**(code **)(*unaff_ESI + 0x10))();
      unaff_EDI = CoCreateFreeThreadedMarshaler(punkOuter,ppunkMarshal);
      if (-1 < (int)unaff_EDI) {
        unaff_EDI = 0;
      }
    }
  }
  InterlockedDecrement(unaff_ESI + 5);
  if (unaff_EDI == 0) {
    unaff_EDI = (**(code **)*unaff_ESI)();
    if (unaff_EDI == 0) goto LAB_10008226;
  }
  (**(code **)(*unaff_ESI + 0x14))(1);
LAB_10008226:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10008240 at 10008240

undefined4 * __thiscall FUN_10008240(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019f03;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CVehicleClassificationLogicImpl>::vftable;
  FUN_10007840((int)this + 0xc);
  *(undefined ***)((int)this + 0xc) =
       ATL::CComContainedObject<class_CVehicleClassificationLogicImpl>::vftable;
  *(undefined ***)((int)this + 0x10) =
       ATL::CComContainedObject<class_CVehicleClassificationLogicImpl>::vftable;
  *(undefined ***)((int)this + 0x1c) =
       ATL::CComContainedObject<class_CVehicleClassificationLogicImpl>::vftable;
  *(undefined4 *)((int)this + 0x20) = param_1;
  local_8 = 1;
  (**(code **)(*DAT_10030e30 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100082e0 at 100082e0

void FUN_100082e0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



// Function: FUN_10008300 at 10008300

LONG FUN_10008300(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return LVar1;
}



// Function: FUN_10008330 at 10008330

undefined4 FUN_10008330(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  uVar1 = Ordinal_32(param_1 + 3,&PTR_DAT_10022df0,param_2,param_3);
  return uVar1;
}



// Function: FUN_100083a0 at 100083a0

undefined4 * __thiscall FUN_100083a0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f33;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CVehicleClassificationLogicImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  piVar1 = *(int **)((int)this + 0x54);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)((int)this + 0x54) = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  (**(code **)(*DAT_10030e30 + 8))();
  local_8 = 0xffffffff;
  FUN_10006760((int)this + 0xc);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008440 at 10008440

undefined4 * __thiscall
FUN_10008440(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f5b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 8) = param_2;
  piVar2 = param_4;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10002d40((undefined2 *)((int)this + 0x10),param_4,(int)piVar2 - ((int)param_4 + 2) >> 1);
  *(undefined4 *)((int)this + 0x2c) = param_5;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100084e0 at 100084e0

int * FUN_100084e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10019f8b;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x5c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_10008240(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_10008596();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_10008596();
  return piVar1;
}



// Function: Catch@10008581 at 10008581

undefined * Catch_10008581(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000858e;
}



// Function: FUN_10008596 at 10008596

int * FUN_10008596(void)

{
  LPUNKNOWN punkOuter;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  LPUNKNOWN *ppunkMarshal;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_10005f10((int)unaff_ESI);
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      ppunkMarshal = (LPUNKNOWN *)(unaff_ESI + 0x15);
      punkOuter = (LPUNKNOWN)(**(code **)(unaff_ESI[3] + 0x10))();
      unaff_EDI = (int *)CoCreateFreeThreadedMarshaler(punkOuter,ppunkMarshal);
      if (((int)unaff_EBX <= (int)unaff_EDI) || (unaff_EDI == unaff_EBX)) {
        unaff_EDI = (int *)(**(code **)*unaff_ESI)();
        if (unaff_EDI == unaff_EBX) goto LAB_100085e4;
      }
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_100085e4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10008600 at 10008600

void FUN_10008600(undefined4 param_1,undefined4 param_2)

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
  
  puStack_c = &LAB_10019fc8;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_44 = CComErrorHandlerException::vftable;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  local_8 = 0;
  local_40 = param_1;
  local_3c = 0;
  local_38 = param_2;
  FUN_10002d40(local_34,(int *)&PTR_10022cc0,0);
  local_18 = 0;
  local_8 = 1;
  local_6c = local_3c;
  local_70 = local_40;
  local_74 = CComErrorHandlerException::vftable;
  local_68 = local_38;
  local_50 = 7;
  local_54 = 0;
  local_64[0] = 0;
  FUN_10002b20(local_64,(int *)local_34,0,0xffffffff);
  local_48 = local_18;
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_74,(ThrowInfo *)&DAT_100289f4);
}



// Function: FUN_100086d0 at 100086d0

undefined4 * __cdecl FUN_100086d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

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



// Function: FUN_10008760 at 10008760

void FUN_10008760(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_100080f0(0,param_2,param_3);
    return;
  }
  FUN_100084e0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10008790 at 10008790

void __cdecl FUN_10008790(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a001;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_2 != (undefined2 *)0x0) {
    *(undefined4 *)(param_2 + 10) = 7;
    *(undefined4 *)(param_2 + 8) = 0;
    *param_2 = 0;
    FUN_10002fc0(param_2,param_3);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100087f0 at 100087f0

undefined2 * __cdecl
FUN_100087f0(undefined4 *param_1,undefined4 *param_2,undefined2 *param_3,undefined4 param_4)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a020;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 7) {
    FUN_10008790(param_4,param_3,param_1);
    param_3 = param_3 + 0xe;
  }
  ExceptionList = local_10;
  return param_3;
}



// Function: Catch@10008869 at 10008869

void Catch_10008869(void)

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
      FUN_10003040(uVar2,puVar3);
      puVar3 = puVar3 + 7;
    } while (puVar3 != puVar1);
  }
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_100088a0 at 100088a0

void FUN_100088a0(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 ****ppppuVar4;
  wchar_t *unaff_ESI;
  uint uVar5;
  wchar_t *pwVar6;
  undefined **ppuVar7;
  int **ppiVar8;
  undefined **local_144 [2];
  undefined4 uStack_13c;
  undefined4 *local_134;
  undefined4 local_108;
  uint local_104;
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> local_f8 [72];
  undefined ***local_b0;
  undefined ***local_ac;
  basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *local_a8;
  int *local_a4;
  int local_a0;
  uint local_9c;
  int local_98;
  undefined4 local_94;
  uint local_90;
  int *local_8c;
  int *local_88;
  void *local_84 [4];
  undefined4 local_74;
  uint local_70;
  void *local_68 [4];
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a11c;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_90 = 0;
  local_a4 = param_3;
  local_a0 = param_1;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffff0000);
  FUN_10002d40(local_30,(int *)&PTR_10022cc0,0);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_4c = (void *)((uint)local_4c._2_2_ << 0x10);
  local_38 = 7;
  local_3c = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10002d40(&local_4c,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  local_b0 = local_144;
  uVar5 = 0;
  do {
    local_8c = (int *)0x0;
    local_8._0_1_ = 3;
    local_9c = FUN_10005d50(&local_4c,(ushort *)L"</LicenseName>",uVar5,0xe);
    FUN_10007b60(&local_4c,(undefined2 *)local_68,uVar5,local_9c - uVar5);
    local_8._0_1_ = 4;
    ppuVar7 = &PTR_100228f8;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_f8);
    local_8 = CONCAT31(local_8._1_3_,5);
    local_90 = local_90 | 1;
    pwVar6 = (wchar_t *)0x0;
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)&stack0xfffffeb8,
               (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)local_144,false);
    local_8 = 6;
    *(undefined ***)(&stack0xfffffeb8 + (int)ppuVar7[1]) =
         std::
         basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
         ::vftable;
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
    basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)local_144);
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_144[0] = std::
                   basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
                   ::vftable;
    local_108 = 0;
    local_104 = 4;
    local_8._0_1_ = 10;
    piVar2 = (int *)FUN_100020e0((int *)&stack0xfffffeb8,L".//*[@Name=\"");
    piVar2 = (int *)FUN_10002340(piVar2,pwVar6);
    FUN_100020e0(piVar2,unaff_ESI);
    unaff_ESI = *(wchar_t **)(local_a0 + 8);
    puVar3 = (undefined4 *)FUN_10003260(&stack0xfffffeb8,(undefined2 *)local_84);
    local_8._0_1_ = 0xb;
    if (7 < (uint)puVar3[5]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    if (puVar3 == (undefined4 *)0x0) {
      local_98 = 0;
    }
    else {
      local_98 = Ordinal_2();
      if (local_98 == 0) goto LAB_10008d0c;
    }
    iVar1 = local_98;
    local_8._0_1_ = 0xc;
    ppiVar8 = &local_8c;
    (**(code **)(*(int *)unaff_ESI + 0x94))(unaff_ESI,local_98);
    local_8._0_1_ = 0xb;
    Ordinal_6(iVar1);
    local_8._0_1_ = 10;
    if (7 < local_70) {
      operator_delete(local_84[0]);
    }
    local_70 = 7;
    local_74 = 0;
    local_84[0] = (void *)((uint)local_84[0] & 0xffff0000);
    local_88 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,0xd);
    local_94 = (**(code **)(*local_8c + 0x88))(local_8c,&local_88);
    piVar2 = local_88;
    do {
      iVar1 = *piVar2;
      piVar2 = (int *)((int)piVar2 + 2);
    } while ((short)iVar1 != 0);
    FUN_100075a0(local_30,local_88,(int)piVar2 - ((int)local_88 + 2) >> 1);
    piVar2 = local_8c;
    if (local_8c != (int *)0x0) {
      local_8c = (int *)0x0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    local_8._0_1_ = 10;
    Ordinal_6(local_88);
    local_8 = (uint)local_8._1_3_ << 8;
    local_a8 = local_f8;
    *(undefined ***)(&stack0xfffffeb8 + (int)ppiVar8[1]) =
         std::
         basic_ostringstream<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
         ::vftable;
    local_8._1_3_ = (uint3)((uint)local_8 >> 8);
    local_ac = local_144;
    local_144[0] = std::
                   basic_stringbuf<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
                   ::vftable;
    local_8._0_1_ = 0x10;
    if ((local_104 & 1) != 0) {
      operator_delete((void *)*local_134);
    }
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)local_144,
               (wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0);
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setp
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)local_144,
               (wchar_t *)0x0,(wchar_t *)0x0);
    local_104 = local_104 & 0xfffffffe;
    local_108 = 0;
    local_8._0_1_ = 0xe;
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)local_144);
    local_8._0_1_ = 4;
    *(code **)(&stack0xfffffeb8 + (int)ppiVar8[1]) = _vftable__exref;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>(local_f8);
    local_8._0_1_ = 3;
    if (7 < local_54) {
      operator_delete(local_68[0]);
    }
    local_54 = 7;
    local_58 = 0;
    local_68[0] = (void *)((uint)local_68[0] & 0xffff0000);
    local_8._0_1_ = 1;
    if (local_8c != (int *)0x0) {
      (**(code **)(*local_8c + 8))(local_8c);
    }
    uVar5 = FUN_10005d50(&local_4c,(ushort *)L"<LicenseName>",local_9c,0xd);
  } while (uVar5 != 0xffffffff);
  if (local_1c < 8) {
    ppppuVar4 = local_30;
  }
  else {
    ppppuVar4 = (undefined4 ****)local_30[0];
    if ((undefined4 ****)local_30[0] == (undefined4 ****)0x0) {
      piVar2 = (int *)0x0;
      goto LAB_10008c6a;
    }
  }
  piVar2 = (int *)Ordinal_2(ppppuVar4);
  local_88 = piVar2;
  if (piVar2 == (int *)0x0) {
LAB_10008d0c:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
LAB_10008c6a:
  local_88 = (int *)0x0;
  *local_a4 = (int)piVar2;
  local_8._0_1_ = 1;
  Ordinal_6();
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_38) {
    operator_delete(local_4c);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (void *)((uint)local_4c & 0xffff0000);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  uStack_13c = 0x10008cee;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10008d20 at 10008d20

void __thiscall FUN_10008d20(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  if ((*(char *)((int)this + 4) == '\0') && (param_1 < 0)) {
    *(undefined1 *)((int)this + 4) = 1;
    FUN_10008600(param_1,*(undefined4 *)((int)this + 8));
  }
  return;
}



// Function: FUN_10008d50 at 10008d50

undefined4 * __thiscall
FUN_10008d50(void *this,int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  piVar5 = param_1;
  puStack_c = &LAB_1001a19b;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)((int)this + 4);
  *piVar1 = 0;
  *(undefined ***)this =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_14 = 0;
  uStack_7 = 0;
  local_8 = 3;
  puVar4 = param_2;
  local_18 = piVar1;
  if (param_2[4] == 0) {
    iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,&local_14,uVar2);
    if (-1 < iVar3) goto LAB_10008e1e;
    puVar4 = (undefined4 *)FUN_10008600(iVar3,0);
  }
  piVar5 = FUN_10017aa0((int *)&param_2,puVar4);
  local_8 = 4;
  if (local_14 != *piVar5) {
    Ordinal_6(local_14);
    local_14 = *piVar5;
    *piVar5 = 0;
  }
  local_8 = 3;
  Ordinal_6(param_2);
  piVar5 = param_1;
LAB_10008e1e:
  local_18 = (int *)0x0;
  _local_8 = CONCAT31(uStack_7,6);
  iVar3 = (**(code **)(*piVar5 + 0x24))(piVar5,&local_18);
  if (iVar3 < 0) {
    FUN_10008600(iVar3,0);
  }
  iVar3 = (**(code **)(*local_18 + 0x24))(local_18,local_14,piVar1);
  if (iVar3 < 0) {
    FUN_10008600(iVar3,0);
  }
  if (param_3[4] != 0) {
    piVar5 = FUN_10017aa0((int *)&param_1,param_3);
    _local_8 = CONCAT31(uStack_7,7);
    iVar3 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,*piVar5);
    if (iVar3 < 0) {
      FUN_10008600(iVar3,0);
    }
    _local_8 = CONCAT31(uStack_7,6);
    Ordinal_6(param_1);
  }
  local_8 = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  _local_8 = CONCAT31(uStack_7,2);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10008f10 at 10008f10

undefined2 * __thiscall FUN_10008f10(void *this,undefined2 *param_1)

{
  int iVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a399;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x1c))
                    (*(int **)((int)this + 4),&local_14,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_10008600(iVar1,0);
  }
  FUN_10017be0(param_1,local_14);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10008fd0 at 10008fd0

void __thiscall FUN_10008fd0(void *this,undefined4 *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001a1d0;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar2 = FUN_10017aa0((int *)&param_1,param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = (**(code **)(**(int **)((int)this + 4) + 0x24))(*(int **)((int)this + 4),*piVar2,uVar1);
  if (iVar3 < 0) {
    FUN_10008600(iVar3,0);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_6(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10009080 at 10009080

undefined4 * __thiscall FUN_10009080(void *this,undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001a25c;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 3;
  uStack_7 = 0;
  piVar2 = FUN_10017aa0((int *)&param_2,param_2);
  _local_8 = CONCAT31(uStack_7,4);
  iVar3 = (**(code **)(**(int **)((int)this + 4) + 0x30))
                    (*(int **)((int)this + 4),*piVar2,1,&local_18,uVar1);
  if (iVar3 < 0) {
    FUN_10008600(iVar3,0);
  }
  local_8 = 3;
  Ordinal_6(param_2);
  local_14 = (int *)0x0;
  _local_8 = CONCAT31(uStack_7,6);
  if (local_18 != (int *)0x0) {
    iVar3 = (**(code **)*local_18)(local_18,&DAT_10022b88,&local_14);
    if (iVar3 < 0) {
      FUN_10008600(iVar3,0);
    }
  }
  param_2 = param_1 + 1;
  *param_2 = local_14;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  *param_1 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  uStack_7 = (undefined3)((uint)_local_8 >> 8);
  local_8 = 3;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  _local_8 = CONCAT31(uStack_7,1);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100091c0 at 100091c0

undefined4 * __thiscall
FUN_100091c0(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 param_3,
            undefined4 *param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a2b1;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_18[1] = 1;
  local_8 = 2;
  piVar2 = FUN_10017aa0(local_18,param_2);
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar3 = (**(code **)(**(int **)((int)this + 4) + 0x34))
                    (*(int **)((int)this + 4),*piVar2,param_3,*param_4,param_4[1],param_4[2],
                     param_4[3],param_1,uVar1);
  if (iVar3 < 0) {
    FUN_10008600(iVar3,0);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  Ordinal_6(local_18[0]);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100092b0 at 100092b0

undefined4 * __thiscall FUN_100092b0(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined **local_2c;
  undefined1 local_28;
  undefined4 local_24;
  int local_20;
  void *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001a31b;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)((int)this + 4);
  *piVar1 = 0;
  *(undefined ***)this =
       TComConnectionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_28 = 0;
  local_24 = 0;
  local_2c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_20 = -0x7fffbffb;
  local_14 = 0;
  uStack_7 = 0;
  local_8 = 3;
  puVar3 = param_2;
  local_1c = this;
  local_18 = piVar1;
  if (param_2[4] == 0) {
    local_20 = (**(code **)(*param_1 + 0x1c))(param_1,&local_14,uVar2);
    if (-1 < local_20) goto LAB_1000937e;
    local_28 = 1;
    puVar3 = (undefined4 *)FUN_10008600(local_20,local_24);
  }
  piVar4 = FUN_10017aa0((int *)&param_2,puVar3);
  local_8 = 4;
  if (local_14 != *piVar4) {
    Ordinal_6(local_14);
    local_14 = *piVar4;
    *piVar4 = 0;
  }
  local_8 = 3;
  Ordinal_6(param_2);
LAB_1000937e:
  local_18 = (int *)0x0;
  _local_8 = CONCAT31(uStack_7,6);
  local_20 = (**(code **)(*param_1 + 0x28))(param_1,&local_18);
  if (local_20 < 0) {
    local_28 = 1;
    FUN_10008600(local_20,local_24);
  }
  local_3c = (uint)local_3c._2_2_ << 0x10;
  FUN_10001960(&local_3c,&local_14);
  _local_8 = CONCAT31(uStack_7,7);
  local_20 = (**(code **)(*local_18 + 0x1c))(local_18,local_3c,local_38,local_34,local_30,piVar1);
  if (local_20 < 0) {
    local_28 = 1;
    FUN_10008600(local_20,local_24);
  }
  local_8 = 6;
  Ordinal_9(&local_3c);
  local_8 = 3;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  _local_8 = CONCAT31(uStack_7,2);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009460 at 10009460

undefined4 __fastcall FUN_10009460(int param_1)

{
  int iVar1;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a348;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x2c))
                    (*(int **)(param_1 + 4),&local_14,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_10008600(iVar1,0);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_100094f0 at 100094f0

undefined2 * __thiscall FUN_100094f0(void *this,undefined2 *param_1)

{
  int iVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001a399;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 2;
  uStack_7 = 0;
  if (*(int *)((int)this + 4) != 0) {
    iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x24))
                      (*(int **)((int)this + 4),&local_14,DAT_10030e10 ^ (uint)&stack0xfffffffc);
    if (iVar1 < 0) {
      FUN_10008600(iVar1,0);
    }
  }
  FUN_10017be0(param_1,local_14);
  _local_8 = CONCAT31(uStack_7,1);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100095b0 at 100095b0

undefined2 * __thiscall FUN_100095b0(void *this,undefined2 *param_1)

{
  int iVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001a399;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 2;
  uStack_7 = 0;
  if (*(int *)((int)this + 4) != 0) {
    iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x2c))
                      (*(int **)((int)this + 4),&local_14,DAT_10030e10 ^ (uint)&stack0xfffffffc);
    if (iVar1 < 0) {
      FUN_10008600(iVar1,0);
    }
  }
  FUN_10017be0(param_1,local_14);
  _local_8 = CONCAT31(uStack_7,1);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009670 at 10009670

undefined4 * __thiscall FUN_10009670(void *this,undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a3db;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this =
       TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  local_8 = 2;
  iVar2 = (**(code **)*param_1)(param_1,&DAT_10022b50,(undefined4 *)((int)this + 4),uVar1);
  if (iVar2 < 0) {
    FUN_10008600(iVar2,0);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009720 at 10009720

undefined4 * __thiscall FUN_10009720(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a43b;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this =
       TComUnitDefinitionPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
       ::vftable;
  local_14 = (int *)0x0;
  local_8 = 4;
  iVar3 = (**(code **)(*param_1 + 0x30))(param_1,&local_14,uVar2);
  if (iVar3 < 0) {
    FUN_10008600(iVar3,0);
  }
  piVar1 = local_14;
  piVar4 = FUN_10017aa0((int *)&param_1,param_2);
  local_8 = CONCAT31(local_8._1_3_,5);
  iVar3 = (**(code **)(*piVar1 + 0x1c))(piVar1,*piVar4,(undefined4 *)((int)this + 4));
  if (iVar3 < 0) {
    FUN_10008600(iVar3,0);
  }
  local_8._0_1_ = 4;
  Ordinal_6(param_1);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009830 at 10009830

undefined2 * __thiscall FUN_10009830(void *this,undefined2 *param_1)

{
  int iVar1;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a399;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 2;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x20))
                    (*(int **)((int)this + 4),&local_14,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    FUN_10008600(iVar1,0);
  }
  FUN_10017be0(param_1,local_14);
  local_8 = CONCAT31(local_8._1_3_,1);
  Ordinal_6(local_14);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100098f0 at 100098f0

undefined4 __thiscall FUN_100098f0(void *this,undefined4 param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a481;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  Ordinal_8(param_1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  if (*(int *)((int)this + 4) != 0) {
    iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x28))(*(int **)((int)this + 4),param_1);
    if (iVar1 < 0) {
      FUN_10008600(iVar1,0);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_100099a0 at 100099a0

void __thiscall FUN_100099a0(void *this,undefined4 *param_1,undefined4 *param_2,undefined2 *param_3)

{
  FUN_100087f0(param_1,param_2,param_3,(int)this + 0xc);
  return;
}



// Function: FUN_100099d0 at 100099d0

undefined4 * __thiscall FUN_100099d0(void *this,int param_1,undefined4 *param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a51d;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = CECMParameterReader::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined ***)((int)this + 8) =
       TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>::
       vftable;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  local_8 = 0xc;
  if (*(int *)((int)this + 0xc) != param_1) {
    Ordinal_30((int)this + 0xc,param_1,uVar1);
  }
  if (param_2[4] != 0) {
    FUN_10008fd0((void *)((int)this + 8),param_2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10009ac0 at 10009ac0

void __fastcall FUN_10009ac0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int local_3c;
  int *local_38;
  int *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a5cd;
  local_10 = ExceptionList;
  uVar3 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CECMParameterReader::vftable;
  local_8 = 5;
  piVar1 = (int *)param_1[1];
  local_34 = param_1 + 1;
  piVar5 = local_34;
  local_38 = param_1;
  local_14 = uVar3;
  if (piVar1 != (int *)0x0) {
    puVar4 = (undefined4 *)FUN_10008f10(param_1 + 2,(undefined2 *)local_30);
    local_8._0_1_ = 6;
    piVar5 = FUN_10017aa0(&local_3c,puVar4);
    local_8._0_1_ = 7;
    (**(code **)(*piVar1 + 0x28))(piVar1,*piVar5);
    local_8._0_1_ = 6;
    Ordinal_6(local_3c);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (7 < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
    piVar5 = local_34;
  }
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_34 = param_1 + 7;
  local_8._0_1_ = 4;
  piVar1 = (int *)*local_34;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar3);
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
  local_34 = param_1 + 2;
  *local_34 = (int)TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
                   ::vftable;
  local_8._0_1_ = 0xc;
  piVar1 = param_1 + 3;
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar2 = (int *)*piVar1;
  local_34 = piVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)*piVar5;
  local_38 = piVar5;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10009c60 at 10009c60

undefined4 * __thiscall FUN_10009c60(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined **local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a639;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  puVar3 = FUN_10009080((void *)((int)this + 8),&local_1c,param_2);
  piVar1 = local_18;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = puVar3 + 1;
  }
  *param_1 = 0;
  *param_1 = *puVar3;
  *puVar3 = 0;
  local_14 = 1;
  local_1c = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 3;
  if (local_18 != (int *)0x0) {
    local_18 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8 = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009d20 at 10009d20

undefined4 __thiscall FUN_10009d20(void *this,undefined4 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a691;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10009c60(this,&param_2,param_2);
  local_8 = 1;
  Ordinal_8(param_1,uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = (**(code **)(*param_2 + 0x28))(param_2,param_1);
  if (iVar2 != 0) {
    FUN_10008600(iVar2,0);
  }
  local_8 = 0;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009de0 at 10009de0

undefined4 __cdecl FUN_10009de0(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

{
  undefined4 local_34 [8];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a6d1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  FUN_100099d0(local_34,param_2,param_4);
  local_8 = 1;
  FUN_10009d20(local_34,param_1,param_3);
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_10009ac0(local_34);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10009e60 at 10009e60

void FUN_10009e60(int param_1,undefined2 *param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uStack_c0;
  undefined2 local_b0 [8];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined2 local_94 [8];
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_78 [8];
  int local_70;
  undefined4 local_68;
  int local_64;
  undefined4 local_60 [2];
  undefined4 local_58;
  int *local_54;
  undefined2 *local_50;
  int local_4c;
  int *local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  char local_37;
  char local_36;
  char local_35;
  undefined4 local_34 [4];
  undefined4 local_24;
  undefined4 local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a780;
  local_10 = ExceptionList;
  uStack_c0 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_c0;
  ExceptionList = &local_10;
  local_50 = param_2;
  local_3c = 0;
  local_8 = 0;
  local_18 = uStack_c0;
  if (param_2 == (undefined2 *)0x0) {
    local_40 = 0x80004003;
    local_14 = (undefined1 *)&uStack_c0;
    goto LAB_1000a17a;
  }
  *param_2 = 0;
  bVar1 = FUN_10006fb0((void *)(param_1 + -0x10),&DAT_10030e94);
  local_35 = FUN_10006fb0((void *)(param_1 + -0x10),&DAT_10030e98);
  local_37 = FUN_10006fb0((void *)(param_1 + -0x10),&DAT_10030ea0);
  local_36 = FUN_10006fb0((void *)(param_1 + -0x10),&DAT_10030e9c);
  bVar2 = FUN_10006fb0((void *)(param_1 + -0x10),&DAT_10030ea4);
  if ((((bVar1) || ((bool)local_35 != bVar1)) && ((local_37 != '\0' || (local_36 != '\0')))) &&
     (bVar2)) {
    *local_50 = 0xffff;
  }
  local_48 = (int *)0x0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  local_40 = (**(code **)**(undefined4 **)(param_1 + -4))
                       (*(undefined4 **)(param_1 + -4),&DAT_10022b68,&local_48);
  local_44 = 0;
  local_8._0_1_ = 3;
  local_40 = (**(code **)(*local_48 + 0x20))(local_48,&local_44);
  FUN_10009670(&local_58,*(undefined4 **)(param_1 + -4));
  local_20 = 7;
  local_24 = 0;
  local_34[0]._0_2_ = 0;
  local_8._0_1_ = 5;
  FUN_100092b0(local_60,local_54,local_34);
  local_8._0_1_ = 7;
  FUN_10002570(local_34);
  local_80 = 7;
  local_84 = 0;
  local_94[0] = 0;
  local_8._0_1_ = 8;
  puVar3 = (undefined4 *)FUN_10008f10(&local_58,(undefined2 *)local_34);
  local_8._0_1_ = 9;
  FUN_10008d50(&local_68,local_54,puVar3,(undefined4 *)local_94);
  local_8._0_1_ = 0xb;
  FUN_10002570(local_34);
  local_8._0_1_ = 0xc;
  FUN_10002570((undefined4 *)local_94);
  local_9c = 7;
  local_a0 = 0;
  local_b0[0] = 0;
  local_8._0_1_ = 0xd;
  FUN_10009de0(local_78,local_64,&DAT_1002f68c,(undefined4 *)local_b0);
  local_8._0_1_ = 0xf;
  FUN_10002570((undefined4 *)local_b0);
  FUN_10017a70(3,(int)local_78,0,0x409);
  uVar6 = local_3c;
  if (local_70 == 0) {
    piVar4 = FUN_10017aa0(&local_4c,&DAT_1002f504);
    local_8 = CONCAT31(local_8._1_3_,0x10);
    uVar6 = 1;
    local_3c = 1;
    bVar1 = FUN_100016d0(&local_44,piVar4);
    if (!bVar1) goto LAB_1000a08a;
    local_35 = '\x01';
  }
  else {
LAB_1000a08a:
    local_35 = '\0';
  }
  local_8 = 0xf;
  if ((uVar6 & 1) != 0) {
    uVar6 = uVar6 & 0xfffffffe;
    local_3c = uVar6;
    Ordinal_6(local_4c);
  }
  local_36 = local_35 != '\0';
  iVar5 = FUN_10009460((int)local_60);
  if (iVar5 == 2) {
    *local_50 = 0xffff;
  }
  else {
    if (local_36 == '\0') {
      piVar4 = FUN_10017aa0(&local_4c,&DAT_1002f4b0);
      local_8 = CONCAT31(local_8._1_3_,0x11);
      uVar6 = uVar6 | 2;
      local_3c = uVar6;
      bVar1 = FUN_100016d0(&local_44,piVar4);
      local_35 = '\0';
      if (bVar1) goto LAB_1000a10c;
    }
    else {
LAB_1000a10c:
      local_35 = '\x01';
    }
    local_8 = 0xf;
    if ((uVar6 & 2) != 0) {
      local_3c = uVar6 & 0xfffffffd;
      Ordinal_6(local_4c);
    }
    if (local_35 != '\0') {
      *local_50 = 0;
    }
  }
  local_8._0_1_ = 0xc;
  Ordinal_9(local_78);
  local_8._0_1_ = 7;
  FUN_10006450(&local_68);
  local_8._0_1_ = 4;
  FUN_100058f0(local_60);
  local_8._0_1_ = 3;
  FUN_100059f0(&local_58);
  local_8._0_1_ = 2;
  Ordinal_6(local_44);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_10005400((int *)&local_48);
LAB_1000a17a:
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000a1a2 at 1000a1a2

undefined4 Catch_1000a1a2(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x80004005;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000a181;
}



// Function: FUN_1000a1c0 at 1000a1c0

void FUN_1000a1c0(int param_1,undefined4 *param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uStack_98;
  undefined4 local_88 [2];
  undefined4 *local_80;
  undefined4 local_7c [2];
  undefined4 local_74;
  int *local_70;
  undefined4 local_6c [2];
  undefined4 local_64 [2];
  int local_5c [2];
  char local_51;
  undefined2 local_50 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_34 [8];
  undefined4 local_24;
  undefined4 local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001a823;
  local_10 = ExceptionList;
  uStack_98 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  ExceptionList = &local_10;
  local_80 = param_2;
  local_5c[1] = 0x80004005;
  param_2[1] = &PTR_10022cc0;
  *param_2 = 0;
  local_8 = 0;
  local_18 = uStack_98;
  FUN_10009670(&local_74,*(undefined4 **)(param_1 + -4));
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_3c = 7;
  local_40 = 0;
  local_50[0] = 0;
  local_8._0_1_ = 3;
  FUN_10008d50(local_7c,local_70,(undefined4 *)local_50,(undefined4 *)local_34);
  local_8._0_1_ = 5;
  FUN_10002570((undefined4 *)local_50);
  local_8._0_1_ = 6;
  FUN_10002570((undefined4 *)local_34);
  FUN_100074a0(local_7c,local_64,&DAT_1002f424,local_5c + 1);
  local_8._0_1_ = 7;
  FUN_100074a0(local_7c,local_6c,&DAT_1002f440,local_5c + 1);
  local_8._0_1_ = 8;
  pwVar1 = FUN_100094f0(local_64,local_34);
  local_8._0_1_ = 9;
  if (7 < *(uint *)(pwVar1 + 10)) {
    pwVar1 = *(wchar_t **)pwVar1;
  }
  local_5c[0] = _wtoi(pwVar1);
  local_8._0_1_ = 8;
  FUN_10002570((undefined4 *)local_34);
  pwVar1 = FUN_100094f0(local_6c,local_34);
  local_8._0_1_ = 10;
  if (7 < *(uint *)(pwVar1 + 10)) {
    pwVar1 = *(wchar_t **)pwVar1;
  }
  iVar2 = _wtoi(pwVar1);
  local_8._0_1_ = 8;
  FUN_10002570((undefined4 *)local_34);
  if (iVar2 < local_5c[0]) {
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  else {
    *(int *)(param_1 + 0x30) = iVar2 - local_5c[0];
  }
  puVar3 = FUN_100095b0(local_64,local_50);
  local_8._0_1_ = 0xb;
  puVar4 = FUN_100095b0(local_6c,local_34);
  local_8._0_1_ = 0xc;
  local_51 = FUN_10007810(puVar4,puVar3);
  local_8._0_1_ = 0xb;
  FUN_10002570((undefined4 *)local_34);
  local_8._0_1_ = 8;
  FUN_10002570((undefined4 *)local_50);
  if (local_51 == '\0') {
    local_5c[1] = 0x80000720;
  }
  else {
    puVar5 = (undefined4 *)FUN_100095b0(local_64,local_34);
    local_8._0_1_ = 0xd;
    FUN_10009720(local_88,local_70,puVar5);
    local_8._0_1_ = 0xf;
    FUN_10002570((undefined4 *)local_34);
    puVar5 = (undefined4 *)FUN_10009830(local_88,local_34);
    local_8._0_1_ = 0x10;
    if (7 < (uint)puVar5[5]) {
      puVar5 = (undefined4 *)*puVar5;
    }
    puVar5 = FUN_10005730(local_5c,(int)puVar5);
    local_8._0_1_ = 0x11;
    uVar6 = FUN_100080c0(puVar5);
    *(undefined4 *)(param_1 + 0x34) = uVar6;
    local_8._0_1_ = 0x10;
    FUN_10008070(local_5c);
    local_8._0_1_ = 0xf;
    FUN_10002570((undefined4 *)local_34);
    local_5c[1] = 0;
    local_8._0_1_ = 8;
    FUN_10005a70(local_88);
  }
  *local_80 = *(undefined4 *)(param_1 + 0x30);
  local_80[1] = *(undefined4 *)(param_1 + 0x34);
  local_8._0_1_ = 7;
  FUN_10005970(local_6c);
  local_8._0_1_ = 6;
  FUN_10005970(local_64);
  local_8._0_1_ = 1;
  FUN_10006450(local_7c);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_100059f0(&local_74);
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@1000a45c at 1000a45c

undefined4 Catch_1000a45c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000a43b;
}



// Function: FUN_1000a470 at 1000a470

undefined4 __fastcall FUN_1000a470(void *param_1)

{
  uint uVar1;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined **local_20;
  undefined1 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001a860;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  local_1c = 0;
  local_20 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_14 = 0x80004005;
  local_8 = 0;
  FUN_100098f0(param_1,local_30);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_14 = FUN_10017a70(3,(int)local_30,0,0x409);
  if (local_14 < 0) {
    local_1c = 1;
    FUN_10008600(local_14,0);
  }
  local_8 = local_8 & 0xffffff00;
  Ordinal_9(local_30,uVar1);
  ExceptionList = local_10;
  return local_28;
}



// Function: FUN_1000a520 at 1000a520

void __thiscall FUN_1000a520(void *this,char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a880;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((char *)0x9249249 < param_1) {
    std::_Xlength_error("vector<T> too long");
  }
                    /* WARNING: Load size is inaccurate */
  if ((char *)((*(int *)((int)this + 8) - *this) / 0x1c) < param_1) {
    puVar3 = (undefined2 *)FUN_10005260(param_1);
    local_8 = 0;
                    /* WARNING: Load size is inaccurate */
    FUN_100099a0(this,*this,*(undefined4 **)((int)this + 4),puVar3);
    local_8 = 0xffffffff;
    iVar1 = *(int *)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
    puVar2 = *this;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_10003220(puVar2,*(undefined4 **)((int)this + 4));
                    /* WARNING: Load size is inaccurate */
      operator_delete(*this);
    }
    *(undefined2 **)((int)this + 8) = puVar3 + (int)param_1 * 0xe;
    *(undefined2 **)((int)this + 4) = puVar3 + ((iVar1 - (int)puVar2) / 0x1c) * 0xe;
    *(undefined2 **)this = puVar3;
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1000a623 at 1000a623

void Catch_1000a623(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000a640 at 1000a640

undefined4 * __thiscall FUN_1000a640(void *this,byte param_1)

{
  FUN_10009ac0((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000a670 at 1000a670

undefined4 __thiscall FUN_1000a670(void *this,int **param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 local_60;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_44;
  undefined4 local_34;
  uint local_30;
  undefined **local_28;
  int *local_24;
  undefined **local_20;
  int *local_1c;
  undefined **local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a8f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10009670(&local_28,*(undefined4 **)((int)this + 0xc));
  local_4c = 7;
  local_50 = 0;
  local_60 = (void *)((uint)local_60._2_2_ << 0x10);
  local_30 = 7;
  local_34 = 0;
  local_44 = (void *)((uint)local_44._2_2_ << 0x10);
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  FUN_10008d50(&local_20,local_24,&local_44,&local_60);
  local_8._0_1_ = 4;
  if (7 < local_30) {
    operator_delete(local_44);
  }
  local_30 = 7;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffff0000);
  local_8._0_1_ = 5;
  if (7 < local_4c) {
    operator_delete(local_60);
  }
  local_60 = (void *)((uint)local_60 & 0xffff0000);
  local_4c = 7;
  local_50 = 0;
  FUN_100074a0(&local_20,&local_18,param_1,&param_1);
  local_8._0_1_ = 6;
  uVar2 = FUN_1000a470(&local_18);
  piVar1 = local_14;
  local_18 = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 7;
  if (local_14 != (int *)0x0) {
    local_14 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  param_1 = &local_14;
  local_8._0_1_ = 5;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  piVar1 = local_1c;
  local_20 = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 9;
  if (local_1c != (int *)0x0) {
    local_1c = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  param_1 = &local_1c;
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  piVar1 = local_24;
  local_28 = TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0xb;
  if (local_24 != (int *)0x0) {
    local_24 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  param_1 = &local_24;
  local_8 = 0xffffffff;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  ExceptionList = local_10;
  return uVar2;
}



// Function: FUN_1000a820 at 1000a820

int __thiscall FUN_1000a820(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 local_48;
  undefined4 local_38;
  uint local_34;
  undefined **local_2c;
  int *local_28;
  undefined **local_24;
  int *local_20;
  undefined **local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001a978;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10009670(&local_2c,*(undefined4 **)((int)this + 0xc));
  local_50 = 7;
  local_54 = 0;
  local_64 = (void *)((uint)local_64._2_2_ << 0x10);
  local_34 = 7;
  local_38 = 0;
  local_48 = (void *)((uint)local_48._2_2_ << 0x10);
  local_8._1_3_ = 0;
  local_8._0_1_ = 2;
  FUN_10008d50(&local_24,local_28,&local_48,&local_64);
  local_8._0_1_ = 4;
  if (7 < local_34) {
    operator_delete(local_48);
  }
  local_34 = 7;
  local_38 = 0;
  local_48 = (void *)((uint)local_48 & 0xffff0000);
  local_8._0_1_ = 5;
  if (7 < local_50) {
    operator_delete(local_64);
  }
  local_50 = 7;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffff0000);
  FUN_100074a0(&local_24,&local_1c,&DAT_1002f45c,&local_14);
  local_8._0_1_ = 6;
  if (-1 < local_14) {
    uVar2 = FUN_1000a470(&local_1c);
    *param_1 = uVar2;
  }
  piVar1 = local_18;
  local_1c = TComParameterPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 7;
  if (local_18 != (int *)0x0) {
    local_18 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 5;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  piVar1 = local_20;
  local_24 = TComDataServicePtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8._0_1_ = 9;
  if (local_20 != (int *)0x0) {
    local_20 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  piVar1 = local_28;
  local_2c = TComECMServicesPtr<class_CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>_>
             ::vftable;
  local_8 = 0xb;
  if (local_28 != (int *)0x0) {
    local_28 = (int *)0x0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  ExceptionList = local_10;
  return local_14;
}



// Function: FUN_1000a9e0 at 1000a9e0

void __thiscall FUN_1000a9e0(void *this,int param_1)

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
    FUN_1000a520(this,pcVar3);
  }
  return;
}



// Function: FUN_1000aa60 at 1000aa60

undefined4 FUN_1000aa60(int param_1,undefined2 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001a9a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_2 = 0;
  local_8 = 0;
  iVar1 = FUN_1000a670((void *)(param_1 + -0x10),(int **)&DAT_1002f408);
  if (iVar1 == 1) {
    *param_2 = 0xffff;
  }
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1000aadb at 1000aadb

undefined4 Catch_1000aadb(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1000aac4;
}



// Function: FUN_1000aaf0 at 1000aaf0

void FUN_1000aaf0(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000a820((void *)(param_1 + -0x10),&param_1);
  if (-1 < iVar1) {
    *param_2 = param_1;
  }
  return;
}



// Function: FUN_1000ab20 at 1000ab20

void FUN_1000ab20(int param_1)

{
  int iVar1;
  uint uStack_80;
  undefined2 local_70 [8];
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_54 [8];
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_38 [4];
  undefined4 local_30;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20 [2];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar1 = param_1;
  puStack_c = &LAB_1001a9e8;
  local_10 = ExceptionList;
  uStack_80 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_80;
  ExceptionList = &local_10;
  local_18 = 0x80004005;
  local_8 = 0;
  if (((*(int *)(param_1 + 0x24) == 2) && (*(int *)(param_1 + 0x28) == 3)) ||
     ((*(int *)(param_1 + 0x24) == 1 && (*(int *)(param_1 + 0x28) == 1)))) {
    *(undefined4 *)(param_1 + 0x2c) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  Ordinal_8(local_38);
  local_8._0_1_ = 1;
  local_38[0] = 3;
  local_30 = *(undefined4 *)(iVar1 + 0x2c);
  FUN_10009670(&local_28,*(undefined4 **)(iVar1 + -4));
  local_5c = 7;
  local_60 = 0;
  local_70[0] = 0;
  local_40 = 7;
  local_44 = 0;
  local_54[0] = 0;
  local_8._0_1_ = 4;
  FUN_10008d50(local_20,local_24,(undefined4 *)local_54,(undefined4 *)local_70);
  local_8._0_1_ = 6;
  FUN_10002570((undefined4 *)local_54);
  local_8._0_1_ = 7;
  FUN_10002570((undefined4 *)local_70);
  FUN_100091c0(local_20,&param_1,&DAT_1002f45c,1,(undefined4 *)local_38);
  FUN_10005400(&param_1);
  FUN_1000a820((void *)(iVar1 + -0x10),&param_1);
  local_18 = -(uint)(param_1 != *(int *)(iVar1 + 0x2c)) & 0x70001002;
  local_8._0_1_ = 2;
  FUN_10006450(local_20);
  local_8._0_1_ = 1;
  FUN_100059f0(&local_28);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_9(local_38);
  local_8 = 0xffffffff;
  FUN_1000ac7b();
  return;
}



// Function: Catch@1000ac6b at 1000ac6b

undefined * Catch_1000ac6b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000ac78;
}



// Function: FUN_1000ac7b at 1000ac7b

void FUN_1000ac7b(void)

{
  int unaff_EBP;
  
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000aca0 at 1000aca0

void __thiscall FUN_1000aca0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aa32;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)((int)this + 4);
                    /* WARNING: Load size is inaccurate */
  if ((param_1 < puVar1) && (puVar2 = *this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000a9e0(this,1);
    }
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)(*this + (((int)param_1 - (int)puVar2) / 0x1c) * 0x1c);
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 0;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000ad63;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_1000a9e0(this,1);
    }
    this_00 = *(undefined2 **)((int)this + 4);
    local_8 = 1;
    if (this_00 == (undefined2 *)0x0) goto LAB_1000ad63;
    *(undefined4 *)(this_00 + 10) = 7;
    *(undefined4 *)(this_00 + 8) = 0;
    *this_00 = 0;
  }
  FUN_10002fc0(this_00,param_1);
LAB_1000ad63:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x1c;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ad90 at 1000ad90

void __cdecl FUN_1000ad90(undefined4 *param_1,ushort param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  uint *puVar8;
  uint uVar9;
  uint local_3c;
  undefined4 *local_38;
  uint local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aa60;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)param_3[1];
  local_38 = param_1;
  if ((undefined4 *)*param_3 != puVar1) {
    puVar1 = FUN_100086d0(puVar1,puVar1,(undefined4 *)*param_3);
    FUN_10003220(puVar1,(undefined4 *)param_3[1]);
    param_3[1] = puVar1;
  }
  local_34 = (uint)param_2;
  uVar9 = 0;
  uVar2 = FUN_10005d50(param_1,(ushort *)&local_34,0,1);
  if (uVar2 != 0xffffffff) {
    local_3c = (uint)param_2;
    do {
      puVar1 = (undefined4 *)FUN_10007b60(param_1,(undefined2 *)local_30,uVar9,uVar2 - uVar9);
      local_8 = 0;
      FUN_1000aca0(param_3,puVar1);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_20 = 0;
      local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
      uVar9 = uVar2 + 1;
      local_1c = 7;
      local_34 = uVar9;
      if ((uVar9 < (uint)param_1[4]) && (iVar3 = param_1[4] - uVar9, param_1 = local_38, iVar3 != 0)
         ) {
        puVar1 = local_38;
        if (7 < (uint)local_38[5]) {
          puVar1 = (undefined4 *)*local_38;
        }
        puVar4 = (ushort *)((int)puVar1 + uVar9 * 2);
        for (; puVar5 = puVar4, iVar6 = iVar3, iVar3 != 0; iVar3 = iVar3 + (-1 - (iVar6 >> 1))) {
          while (*puVar5 != param_2) {
            iVar6 = iVar6 + -1;
            puVar5 = puVar5 + 1;
            if (iVar6 == 0) goto LAB_1000aeb6;
          }
          if (puVar5 == (ushort *)0x0) break;
          iVar6 = 1;
          puVar8 = &local_3c;
          puVar7 = puVar5;
          while (uVar9 = local_34, *puVar7 == (ushort)*puVar8) {
            puVar7 = puVar7 + 1;
            puVar8 = (uint *)((int)puVar8 + 2);
            iVar6 = iVar6 + -1;
            if (iVar6 == 0) goto LAB_1000af71;
          }
          if ((-(uint)(*puVar7 < (ushort)*puVar8) & 0xfffffffe) == 0xffffffff) {
LAB_1000af71:
            puVar1 = local_38;
            if (7 < (uint)local_38[5]) {
              puVar1 = (undefined4 *)*local_38;
            }
            uVar2 = (int)puVar5 - (int)puVar1 >> 1;
            goto LAB_1000aeb9;
          }
          iVar6 = (int)puVar5 - (int)puVar4;
          puVar4 = puVar5 + 1;
        }
      }
LAB_1000aeb6:
      uVar2 = 0xffffffff;
LAB_1000aeb9:
    } while (uVar2 != 0xffffffff);
  }
  puVar1 = (undefined4 *)FUN_10007b60(param_1,(undefined2 *)local_30,uVar9,param_1[4] - uVar9);
  local_8 = 1;
  FUN_1000aca0(param_3,puVar1);
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



// Function: FUN_1000afb0 at 1000afb0

void __thiscall FUN_1000afb0(void *this,LPCWSTR param_1)

{
  OLECHAR OVar1;
  short sVar2;
  int iVar3;
  LPOLESTR pOVar4;
  LPCWSTR *ppWVar5;
  short *psVar6;
  uint uVar7;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  int *in_stack_00000020;
  LPOLESTR local_a44;
  HKEY local_a40;
  undefined4 local_a3c;
  undefined4 local_a38;
  uint local_a34;
  void *local_a30 [4];
  undefined4 local_a20;
  uint local_a1c;
  undefined4 local_a14;
  undefined4 local_214;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001aaae;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_a40 = (HKEY)0x0;
  local_a3c = 0;
  local_a38 = 0;
  local_8 = 1;
  iVar3 = __RTDynamicCast(this,0,&CComNonAddInSecurity<class_CSimpleSecurity>::RTTI_Type_Descriptor,
                          &CSimpleSecurity::RTTI_Type_Descriptor,0,local_14);
  StringFromCLSID((IID *)(iVar3 + 0x30),&local_a44);
  pOVar4 = local_a44;
  do {
    OVar1 = *pOVar4;
    pOVar4 = pOVar4 + 1;
  } while (OVar1 != L'\0');
  FUN_100075a0(&param_1,(int *)local_a44,(int)pOVar4 - (int)(local_a44 + 1) >> 1);
  CoTaskMemFree(local_a44);
  ppWVar5 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar5 = &param_1;
  }
  iVar3 = FUN_10004fb0(&local_a40,(HKEY)0x80000002,(LPCWSTR)ppWVar5,0x2001f);
  if (iVar3 == 0) {
    local_a34 = 0x800;
    iVar3 = FUN_10005060(&local_a40,L"SecurityFilePath",(LPBYTE)&local_a14,&local_a34);
    local_a34 = 0x200;
    if (iVar3 == 0) {
      iVar3 = FUN_10005060(&local_a40,L"SecurityFiles",(LPBYTE)&local_214,&local_a34);
    }
    uVar7 = 0;
    if (iVar3 == 0) {
      psVar6 = (short *)&local_214;
      local_a1c = 7;
      local_a20 = 0;
      local_a30[0] = (void *)((uint)local_a30[0] & 0xffff0000);
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_10002d40(local_a30,&local_214,(int)psVar6 - ((int)&local_214 + 2) >> 1);
      local_8._0_1_ = 2;
      uVar7 = FUN_1000ad90(local_a30,0x21,in_stack_00000020);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_a1c) {
        operator_delete(local_a30[0]);
      }
      local_a1c = 7;
      local_a20 = 0;
      local_a30[0] = (void *)((uint)local_a30[0] & 0xffff0000);
    }
    if (0 < (int)uVar7) {
      iVar3 = 0;
      local_a34 = uVar7;
      do {
        psVar6 = (short *)&local_a14;
        do {
          sVar2 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar2 != 0);
        FUN_100076c0((void *)(*in_stack_00000020 + iVar3),0,&local_a14,
                     (int)psVar6 - ((int)&local_a14 + 2) >> 1);
        iVar3 = iVar3 + 0x1c;
        local_a34 = local_a34 - 1;
      } while (local_a34 != 0);
    }
    if (local_a40 != (HKEY)0x0) {
      RegCloseKey(local_a40);
      local_a40 = (HKEY)0x0;
    }
    local_a3c = 0;
  }
  local_8 = local_8 & 0xffffff00;
  if (local_a40 != (HKEY)0x0) {
    RegCloseKey(local_a40);
    local_a40 = (HKEY)0x0;
  }
  local_a3c = 0;
  local_8 = 0xffffffff;
  if (7 < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 7;
  uStack00000014 = 0;
  param_1 = (LPCWSTR)((uint)param_1 & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b250 at 1000b250

void __thiscall FUN_1000b250(void *this,int *param_1)

{
  OLECHAR OVar1;
  short sVar2;
  HKEY hKey;
  uint uVar3;
  int iVar4;
  LPOLESTR pOVar5;
  LPCWSTR ***ppppWVar6;
  short *psVar7;
  LPOLESTR local_a64;
  int *local_a60;
  HKEY local_a5c;
  undefined4 local_a58;
  undefined4 local_a54;
  uint local_a50;
  void *local_a4c [4];
  undefined4 local_a3c;
  uint local_a38;
  LPCWSTR **local_a30 [4];
  undefined4 local_a20;
  uint local_a1c;
  undefined4 local_a14;
  undefined4 local_214;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ab01;
  local_10 = ExceptionList;
  uVar3 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_a60 = param_1;
  local_a5c = (HKEY)0x0;
  local_a58 = 0;
  local_a54 = 0;
  local_8 = 0;
  local_a30[0] = (LPCWSTR **)((uint)local_a30[0] & 0xffff0000);
  local_a1c = 7;
  local_a20 = 0;
  local_14 = uVar3;
  FUN_10002d40(local_a30,
               (int *)L"SOFTWARE\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\AIF\\AddIns\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar4 = __RTDynamicCast(this,0,&CComSecurity<class_CSimpleSecurity>::RTTI_Type_Descriptor,
                          &CSimpleSecurity::RTTI_Type_Descriptor,0,uVar3);
  StringFromCLSID((IID *)(iVar4 + 0x30),&local_a64);
  pOVar5 = local_a64;
  do {
    OVar1 = *pOVar5;
    pOVar5 = pOVar5 + 1;
  } while (OVar1 != L'\0');
  FUN_100075a0(local_a30,(int *)local_a64,(int)pOVar5 - (int)(local_a64 + 1) >> 1);
  CoTaskMemFree(local_a64);
  ppppWVar6 = (LPCWSTR ***)local_a30[0];
  if (local_a1c < 8) {
    ppppWVar6 = local_a30;
  }
  iVar4 = FUN_10004fb0(&local_a5c,(HKEY)0x80000002,(LPCWSTR)ppppWVar6,0x2001f);
  if (iVar4 == 0) {
    local_a50 = 0x800;
    iVar4 = FUN_10005060(&local_a5c,L"SecurityFilePath",(LPBYTE)&local_a14,&local_a50);
    local_a50 = 0x200;
    if (iVar4 == 0) {
      iVar4 = FUN_10005060(&local_a5c,L"SecurityFiles",(LPBYTE)&local_214,&local_a50);
    }
    uVar3 = 0;
    if (iVar4 == 0) {
      psVar7 = (short *)&local_214;
      local_a4c[0] = (void *)((uint)local_a4c[0] & 0xffff0000);
      local_a38 = 7;
      local_a3c = 0;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      FUN_10002d40(local_a4c,&local_214,(int)psVar7 - ((int)&local_214 + 2) >> 1);
      local_8._0_1_ = 2;
      uVar3 = FUN_1000ad90(local_a4c,0x21,local_a60);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_a38) {
        operator_delete(local_a4c[0]);
      }
      local_a38 = 7;
      local_a3c = 0;
      local_a4c[0] = (void *)((uint)local_a4c[0] & 0xffff0000);
    }
    if (0 < (int)uVar3) {
      iVar4 = 0;
      local_a50 = uVar3;
      do {
        psVar7 = (short *)&local_a14;
        do {
          sVar2 = *psVar7;
          psVar7 = psVar7 + 1;
        } while (sVar2 != 0);
        FUN_100076c0((void *)(*local_a60 + iVar4),0,&local_a14,
                     (int)psVar7 - ((int)&local_a14 + 2) >> 1);
        iVar4 = iVar4 + 0x1c;
        local_a50 = local_a50 - 1;
      } while (local_a50 != 0);
    }
    if (local_a5c != (HKEY)0x0) {
      RegCloseKey(local_a5c);
      local_a5c = (HKEY)0x0;
    }
    local_a58 = 0;
  }
  hKey = local_a5c;
  local_8 = local_8 & 0xffffff00;
  if (7 < local_a1c) {
    operator_delete(local_a30[0]);
  }
  local_a1c = 7;
  local_a20 = 0;
  local_a30[0] = (LPCWSTR **)((uint)local_a30[0] & 0xffff0000);
  local_8 = 0xffffffff;
  if (hKey != (HKEY)0x0) {
    RegCloseKey(hKey);
    local_a5c = (HKEY)0x0;
  }
  local_a58 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000b530 at 1000b530

void __cdecl FUN_1000b530(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  errno_t eVar1;
  
  eVar1 = memcpy_s(param_1,param_2,param_3,param_4);
  switch(eVar1) {
  case 0:
  case 0x50:
    return;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80004005);
  case 0xc:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  case 0x16:
  case 0x22:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80070057);
  }
}



// Function: FUN_1000b5f0 at 1000b5f0

uint __cdecl FUN_1000b5f0(HMODULE param_1,HRSRC param_2,uint param_3)

{
  HGLOBAL hResData;
  ushort *puVar1;
  DWORD DVar2;
  ushort *puVar3;
  uint uVar4;
  
  hResData = LoadResource(param_1,param_2);
  if (hResData == (HGLOBAL)0x0) {
    return 0;
  }
  puVar1 = (ushort *)LockResource(hResData);
  if (puVar1 != (ushort *)0x0) {
    DVar2 = SizeofResource(param_1,param_2);
    puVar3 = (ushort *)(DVar2 + (int)puVar1);
    for (uVar4 = param_3 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
      if (puVar3 <= puVar1) {
        return 0;
      }
      puVar1 = puVar1 + *puVar1 + 1;
    }
    if (puVar1 < puVar3) {
      return -(uint)(*puVar1 != 0) & (uint)puVar1;
    }
  }
  return 0;
}



// Function: FUN_1000b660 at 1000b660

uint __cdecl FUN_1000b660(uint param_1)

{
  HMODULE hModule;
  HRSRC pHVar1;
  uint uVar2;
  int local_8;
  
  uVar2 = 0;
  hModule = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10031294,0);
  local_8 = 1;
  while ((hModule != (HMODULE)0x0 && (uVar2 == 0))) {
    pHVar1 = FindResourceW(hModule,(LPCWSTR)((param_1 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
    if (pHVar1 != (HRSRC)0x0) {
      uVar2 = FUN_1000b5f0(hModule,pHVar1,param_1);
    }
    hModule = ATL::CAtlBaseModule::GetHInstanceAt((CAtlBaseModule *)&DAT_10031294,local_8);
    local_8 = local_8 + 1;
  }
  return uVar2;
}



// Function: FUN_1000b6d0 at 1000b6d0

undefined4 * __thiscall FUN_1000b6d0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  iVar2 = Ordinal_7(uVar1);
  if (iVar2 != 0) {
                    /* WARNING: Load size is inaccurate */
    param_1 = (undefined4 *)0x0;
    iVar2 = Ordinal_313(*this,uVar1,&param_1);
    if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(iVar2);
    }
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(undefined4 **)this = param_1;
  }
  return (undefined4 *)this;
}



// Function: FUN_1000b720 at 1000b720

void __fastcall FUN_1000b720(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    FreeStdCallThunk((void *)*param_1);
  }
  return;
}



// Function: FUN_1000b730 at 1000b730

void __fastcall FUN_1000b730(undefined4 *param_1)

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



// Function: FUN_1000b750 at 1000b750

void __thiscall FUN_1000b750(void *this,uint *param_1,uint param_2)

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
      uVar4 = puVar1[iVar5 * 8];
      puVar2 = puVar1 + iVar5 * 8;
    } while (((((((puVar1[iVar5 * 8 + 7] != 0 || puVar1[iVar5 * 8 + 6] != 0) ||
                 puVar1[iVar5 * 8 + 5] != 0) || puVar2[4] != 0) || puVar2[3] != 0) || puVar2[2] != 0
              ) || puVar2[1] != 0) || uVar4 != 0);
  }
  puVar1 = puVar1 + iVar5 * 8;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



// Function: FUN_1000b7d0 at 1000b7d0

void __fastcall FUN_1000b7d0(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x1000b7df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + -0xb8) + 0x14))();
  return;
}



// Function: FUN_1000b7f0 at 1000b7f0

undefined4 FUN_1000b7f0(void)

{
  return 0x7f;
}



// Function: FUN_1000b800 at 1000b800

undefined * FUN_1000b800(void)

{
  return &DAT_100234a0;
}



// Function: FUN_1000b810 at 1000b810

undefined * FUN_1000b810(void)

{
  return &DAT_10023380;
}



// Function: FUN_1000b820 at 1000b820

undefined4 FUN_1000b820(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while ((((piVar1 = *(int **)((int)&PTR_DAT_1002fe80 + uVar2), *piVar1 != *param_2 ||
           (piVar1[1] != param_2[1])) || (piVar1[2] != param_2[2])) || (piVar1[3] != param_2[3]))) {
    uVar2 = uVar2 + 4;
    if (3 < uVar2) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_1000b870 at 1000b870

void __thiscall FUN_1000b870(void *this,int param_1)

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



// Function: FUN_1000b8a0 at 1000b8a0

undefined4 FUN_1000b8a0(int param_1,LPCWSTR param_2)

{
  SetWindowTextW(*(HWND *)(param_1 + 0x2c),param_2);
  return 0;
}



// Function: FUN_1000b8c0 at 1000b8c0

undefined4 FUN_1000b8c0(int param_1,BOOL param_2)

{
  EnableWindow(*(HWND *)(param_1 + 0x20),param_2);
  return 0;
}



// Function: FUN_1000b8e0 at 1000b8e0

undefined4 FUN_1000b8e0(int param_1,BOOL param_2)

{
  EnableWindow(*(HWND *)(param_1 + 0x24),param_2);
  return 0;
}



// Function: FUN_1000b900 at 1000b900

undefined4 FUN_1000b900(int param_1,BOOL param_2)

{
  EnableWindow(*(HWND *)(param_1 + 0x28),param_2);
  return 0;
}



// Function: FUN_1000b920 at 1000b920

undefined4 FUN_1000b920(int param_1)

{
  EnableWindow(*(HWND *)(param_1 + 0x20),0);
  EnableWindow(*(HWND *)(param_1 + 0x24),0);
  EnableWindow(*(HWND *)(param_1 + 0x28),0);
  return 0;
}



// Function: FUN_1000b950 at 1000b950

void __fastcall FUN_1000b950(int param_1)

{
  undefined4 local_8;
  
  local_8 = 1;
  (**(code **)(*(int *)(param_1 + 0x114) + 4))(0x53,0,0,&local_8);
  return;
}



// Function: FUN_1000b980 at 1000b980

int * __thiscall FUN_1000b980(void *this,int *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ab38;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)*param_1;
  *(int **)this = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1,uVar2);
  }
  ExceptionList = local_10;
  return (int *)this;
}



// Function: FUN_1000b9e0 at 1000b9e0

void __fastcall FUN_1000b9e0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab6b;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = safearray<wchar_t*,8>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9(param_1 + 2,uVar1,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000ba30 at 1000ba30

undefined4 __thiscall FUN_1000ba30(void *this,undefined4 param_1)

{
  Ordinal_25(*(undefined4 *)((int)this + 0x10),param_1,&param_1);
  return param_1;
}



// Function: FUN_1000ba50 at 1000ba50

void __thiscall FUN_1000ba50(void *this,undefined4 param_1)

{
  Ordinal_26(*(undefined4 *)((int)this + 0x10),param_1,&stack0x00000008);
  return;
}



// Function: FUN_1000ba70 at 1000ba70

void __fastcall FUN_1000ba70(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x2c;
  }
  if (*(int *)(iVar3 + 0x30) != 0) {
    (**(code **)(**(int **)(iVar3 + 0x30) + 8))(*(int **)(iVar3 + 0x30));
  }
  uVar2 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      piVar1 = *(int **)(*(int *)(iVar3 + 0x34) + uVar2 * 4);
      (**(code **)(*piVar1 + 8))(piVar1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0xc));
  }
  operator_delete__(*(void **)(iVar3 + 0x34));
  return;
}



// Function: FUN_1000bac0 at 1000bac0

void __fastcall FUN_1000bac0(undefined4 *param_1)

{
  *param_1 = CComErrorDisplay<class_CVehicleClassificationPageImpl>::vftable;
  return;
}



// Function: FUN_1000bad0 at 1000bad0

void __fastcall FUN_1000bad0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ab9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0xc));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000bb20 at 1000bb20

undefined4 * __thiscall FUN_1000bb20(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001abcb;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = safearray<wchar_t*,8>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9((int)this + 8,uVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000bb90 at 1000bb90

undefined4 * __thiscall FUN_1000bb90(void *this,byte param_1)

{
  *(undefined ***)this = CComErrorDisplay<class_CVehicleClassificationPageImpl>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: Reset_back at 1000bbc0

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



// Function: FUN_1000bbf0 at 1000bbf0

void __thiscall FUN_1000bbf0(void *this,int param_1)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  piVar1 = *this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(int *)this = param_1;
    return;
  }
  *(int *)this = param_1;
  return;
}



// Function: FUN_1000bc20 at 1000bc20

facet * __cdecl FUN_1000bc20(locale *param_1)

{
  int iVar1;
  code *pcVar2;
  _Locimp *p_Var3;
  uint uVar4;
  facet *pfVar5;
  bad_cast local_28 [12];
  _Lockit local_1c [4];
  _Lockit local_18 [4];
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ac02;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_1c,0);
  pcVar2 = id_exref;
  local_8 = 0;
  local_14 = DAT_10030eac;
  if (*(int *)id_exref == 0) {
    std::_Lockit::_Lockit(local_18,0);
    if (*(int *)pcVar2 == 0) {
      *(int *)_Id_cnt_exref = *(int *)_Id_cnt_exref + 1;
      *(undefined4 *)pcVar2 = *(undefined4 *)_Id_cnt_exref;
    }
    local_8 = local_8 & 0xffffff00;
    std::_Lockit::~_Lockit(local_18);
  }
  uVar4 = *(uint *)pcVar2;
  iVar1 = *(int *)param_1;
  if (uVar4 < *(uint *)(iVar1 + 0xc)) {
    pfVar5 = *(facet **)(*(int *)(iVar1 + 8) + uVar4 * 4);
    if (pfVar5 == (facet *)0x0) goto LAB_1000bcb2;
LAB_1000bcd1:
    if (pfVar5 != (facet *)0x0) goto LAB_1000bd27;
  }
  else {
    pfVar5 = (facet *)0x0;
LAB_1000bcb2:
    if (*(char *)(iVar1 + 0x14) == '\0') goto LAB_1000bcd1;
    p_Var3 = std::locale::_Getgloballocale();
    if (uVar4 < *(uint *)(p_Var3 + 0xc)) {
      pfVar5 = *(facet **)(*(int *)(p_Var3 + 8) + uVar4 * 4);
      goto LAB_1000bcd1;
    }
  }
  pfVar5 = local_14;
  if (local_14 == (facet *)0x0) {
    uVar4 = std::ctype<wchar_t>::_Getcat(&local_14,param_1);
    pfVar5 = local_14;
    if (uVar4 == 0xffffffff) {
      std::bad_cast::bad_cast(local_28,"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_1002966c);
    }
    DAT_10030eac = local_14;
    std::locale::facet::_Incref(local_14);
    Facet_Register(pfVar5);
  }
LAB_1000bd27:
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_1c);
  ExceptionList = local_10;
  return pfVar5;
}



// Function: FUN_1000bd50 at 1000bd50

void __fastcall FUN_1000bd50(undefined4 *param_1)

{
  *param_1 = CSmartResult<struct_WINERRORPolicy<struct_ErrorCallbackClass>_>::vftable;
  return;
}



// Function: FUN_1000bd60 at 1000bd60

facet * __cdecl FUN_1000bd60(locale *param_1)

{
  int iVar1;
  code *pcVar2;
  _Locimp *p_Var3;
  uint uVar4;
  facet *pfVar5;
  bad_cast local_28 [12];
  _Lockit local_1c [4];
  _Lockit local_18 [4];
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ac02;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_1c,0);
  pcVar2 = id_exref;
  local_8 = 0;
  local_14 = DAT_10030eb0;
  if (*(int *)id_exref == 0) {
    std::_Lockit::_Lockit(local_18,0);
    if (*(int *)pcVar2 == 0) {
      *(int *)_Id_cnt_exref = *(int *)_Id_cnt_exref + 1;
      *(undefined4 *)pcVar2 = *(undefined4 *)_Id_cnt_exref;
    }
    local_8 = local_8 & 0xffffff00;
    std::_Lockit::~_Lockit(local_18);
  }
  uVar4 = *(uint *)pcVar2;
  iVar1 = *(int *)param_1;
  if (uVar4 < *(uint *)(iVar1 + 0xc)) {
    pfVar5 = *(facet **)(*(int *)(iVar1 + 8) + uVar4 * 4);
    if (pfVar5 == (facet *)0x0) goto LAB_1000bdf2;
LAB_1000be11:
    if (pfVar5 != (facet *)0x0) goto LAB_1000be67;
  }
  else {
    pfVar5 = (facet *)0x0;
LAB_1000bdf2:
    if (*(char *)(iVar1 + 0x14) == '\0') goto LAB_1000be11;
    p_Var3 = std::locale::_Getgloballocale();
    if (uVar4 < *(uint *)(p_Var3 + 0xc)) {
      pfVar5 = *(facet **)(*(int *)(p_Var3 + 8) + uVar4 * 4);
      goto LAB_1000be11;
    }
  }
  pfVar5 = local_14;
  if (local_14 == (facet *)0x0) {
    uVar4 = std::codecvt<wchar_t,char,int>::_Getcat(&local_14,param_1);
    pfVar5 = local_14;
    if (uVar4 == 0xffffffff) {
      std::bad_cast::bad_cast(local_28,"bad cast");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_1002966c);
    }
    DAT_10030eb0 = local_14;
    std::locale::facet::_Incref(local_14);
    Facet_Register(pfVar5);
  }
LAB_1000be67:
  local_8 = 0xffffffff;
  std::_Lockit::~_Lockit(local_1c);
  ExceptionList = local_10;
  return pfVar5;
}



// Function: FUN_1000be90 at 1000be90

undefined4 * __thiscall FUN_1000be90(void *this,byte param_1)

{
  *(undefined ***)this = CSmartResult<struct_WINERRORPolicy<struct_ErrorCallbackClass>_>::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000bec0 at 1000bec0

void __fastcall FUN_1000bec0(int param_1)

{
  LPRECT lpRect;
  HWND hWnd;
  int iVar1;
  int iVar2;
  
  iVar2 = __RTDynamicCast(param_1,0,
                          &CResizingDialog<class_CVehicleClassificationPageImpl>::
                           RTTI_Type_Descriptor,
                          &CVehicleClassificationPageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar2 + 4);
  lpRect = (LPRECT)(param_1 + 0x44);
  GetClientRect(hWnd,lpRect);
  InvalidateRect(hWnd,lpRect,1);
  iVar2 = *(int *)(param_1 + 0x50);
  iVar1 = *(int *)(param_1 + 0x58);
  lpRect->left = *(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x54);
  *(int *)(param_1 + 0x48) = iVar2 - iVar1;
  UpdateWindow(hWnd);
  return;
}



// Function: FUN_1000bf10 at 1000bf10

undefined4 __thiscall FUN_1000bf10(void *this,void *param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_1 == (void *)0x0) || ((*this != 0 && (param_2 == 0)))) {
    return 0;
  }
  if ((int)param_2 < 0) {
    return 0x80070057;
  }
  iVar1 = Ordinal_7(*this);
  if (-iVar1 - 1U < param_2) {
    return 0x80070216;
  }
  iVar4 = param_2 + iVar1;
  if (iVar4 < 0) {
    return 0x80070216;
  }
  if (-1 < iVar1) {
    pvVar2 = (void *)Ordinal_4(0,iVar4);
    if (pvVar2 == (void *)0x0) {
      return 0x8007000e;
    }
                    /* WARNING: Load size is inaccurate */
    iVar3 = Ordinal_7(*this);
    if (iVar3 != 0) {
                    /* WARNING: Load size is inaccurate */
      FUN_1000b530(pvVar2,iVar4 * 2,*this,iVar1 * 2);
    }
    FUN_1000b530((void *)((int)pvVar2 + iVar1 * 2),param_2 * 2,param_1,param_2 * 2);
    *(undefined2 *)((int)pvVar2 + iVar4 * 2) = 0;
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(void **)this = pvVar2;
    return 0;
  }
  return 0x80070216;
}



// Function: FUN_1000c040 at 1000c040

bool __thiscall FUN_1000c040(void *this,HMODULE param_1,uint param_2)

{
  HRSRC pHVar1;
  undefined2 *puVar2;
  int iVar3;
  
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  pHVar1 = FindResourceW(param_1,(LPCWSTR)((param_2 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if (pHVar1 != (HRSRC)0x0) {
    puVar2 = (undefined2 *)FUN_1000b5f0(param_1,pHVar1,param_2);
    if (puVar2 != (undefined2 *)0x0) {
      iVar3 = Ordinal_4(puVar2 + 1,*puVar2);
      *(int *)this = iVar3;
      return iVar3 != 0;
    }
  }
  *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
  return *this != 0;
}



// Function: FUN_1000c0c0 at 1000c0c0

bool __thiscall FUN_1000c0c0(void *this,uint param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  Ordinal_6(*this);
  *(undefined4 *)this = 0;
  puVar1 = (undefined2 *)FUN_1000b660(param_1);
  if (puVar1 != (undefined2 *)0x0) {
    iVar2 = Ordinal_4(puVar1 + 1,*puVar1);
    *(int *)this = iVar2;
    return iVar2 != 0;
  }
  *(undefined4 *)this = 0;
                    /* WARNING: Load size is inaccurate */
  return *this != 0;
}



// Function: FUN_1000c110 at 1000c110

void __fastcall FUN_1000c110(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_1002f6b8) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      operator_delete__((void *)(*param_1 + -0xc));
    }
  }
  return;
}



// Function: FUN_1000c140 at 1000c140

undefined4 __thiscall FUN_1000c140(void *this,int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac20;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    *(undefined **)this = PTR_DAT_1002f6bc;
    return 1;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  operator_new__(param_1 * 2 + 0xe);
  local_8 = 0xffffffff;
  uVar1 = FUN_1000c1b5();
  return uVar1;
}



// Function: Catch@1000c19f at 1000c19f

undefined * Catch_1000c19f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000c1ac;
}



// Function: FUN_1000c1b5 at 1000c1b5

undefined4 FUN_1000c1b5(void)

{
  undefined4 *in_EAX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (in_EAX == (undefined4 *)0x0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0;
  }
  *in_EAX = 1;
  *(undefined2 *)((int)in_EAX + unaff_ESI * 2 + 0xc) = 0;
  in_EAX[1] = unaff_ESI;
  in_EAX[2] = unaff_ESI;
  *unaff_EDI = in_EAX + 3;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}



// Function: FUN_1000c200 at 1000c200

void __fastcall FUN_1000c200(int param_1)

{
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac58;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0xce38368b;
  local_34 = 0x46c12bd3;
  local_30 = 0x7c4a4ab3;
  local_2c = 0x9a7e3936;
  local_28 = 0;
  local_4c = 0;
  local_48 = 0;
  local_50 = 0;
  local_54 = 0;
  local_18 = 0;
  local_3c = 0;
  local_40 = 0;
  local_24 = 0;
  local_20 = 0xc0;
  local_1c = 0x46000000;
  local_44 = (int *)0x0;
  local_8 = 1;
  (**(code **)**(undefined4 **)(param_1 + 8))
            (*(undefined4 **)(param_1 + 8),&DAT_10022c74,&local_44,local_14);
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))
            (*(int **)(param_1 + 0xc),&local_40,0,&local_54,local_44,0);
  local_8 = 0xffffffff;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))(local_44);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000c300 at 1000c300

void __fastcall FUN_1000c300(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ac93;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = safearray<wchar_t*,8>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9(param_1 + 2,uVar1,param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c350 at 1000c350

undefined4 FUN_1000c350(int param_1,LRESULT *param_2)

{
  LRESULT LVar1;
  
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0x20),0x147,0,0);
  *param_2 = LVar1;
  return 0;
}



// Function: FUN_1000c380 at 1000c380

undefined4 FUN_1000c380(int param_1,WPARAM param_2)

{
  SendMessageW(*(HWND *)(param_1 + 0x20),0x14e,param_2,0);
  return 0;
}



// Function: FUN_1000c3b0 at 1000c3b0

undefined4 FUN_1000c3b0(int param_1,LRESULT *param_2)

{
  LRESULT LVar1;
  
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0x24),0x147,0,0);
  *param_2 = LVar1;
  return 0;
}



// Function: FUN_1000c3e0 at 1000c3e0

undefined4 FUN_1000c3e0(int param_1,WPARAM param_2)

{
  SendMessageW(*(HWND *)(param_1 + 0x24),0x14e,param_2,0);
  return 0;
}



// Function: FUN_1000c410 at 1000c410

undefined4 FUN_1000c410(int *param_1)

{
  int iVar1;
  
  if ((undefined **)*param_1 != &PTR_10022cc0) {
    Ordinal_6((undefined **)*param_1);
    iVar1 = Ordinal_2(&PTR_10022cc0);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x8007000e);
    }
  }
  return 0;
}



// Function: FUN_1000c450 at 1000c450

void __fastcall FUN_1000c450(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001acc6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000c4b0 at 1000c4b0

void __fastcall FUN_1000c4b0(undefined4 *param_1)

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



// Function: FUN_1000c4d0 at 1000c4d0

undefined4 __cdecl FUN_1000c4d0(wchar_t param_1,FILE *param_2)

{
  wint_t wVar1;
  undefined2 extraout_var;
  
  wVar1 = fputwc(param_1,param_2);
  return CONCAT31((int3)(CONCAT22(extraout_var,wVar1) >> 8),wVar1 != 0xffff);
}



// Function: FUN_1000c500 at 1000c500

void __fastcall FUN_1000c500(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _lock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_1000c510 at 1000c510

void __fastcall FUN_1000c510(int param_1)

{
  if (*(FILE **)(param_1 + 0x54) != (FILE *)0x0) {
    _unlock_file(*(FILE **)(param_1 + 0x54));
  }
  return;
}



// Function: FUN_1000c520 at 1000c520

short __fastcall FUN_1000c520(int *param_1)

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



// Function: FUN_1000c570 at 1000c570

undefined4 __fastcall FUN_1000c570(int *param_1)

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



// Function: Set_back at 1000c5b0

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



// Function: FUN_1000c5f0 at 1000c5f0

uint __thiscall FUN_1000c5f0(void *this,ushort param_1)

{
  uint uVar1;
  wint_t wVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar3;
  
  uVar1 = **(uint **)((int)this + 0x20);
  if (((uVar1 != 0) && (**(uint **)((int)this + 0x10) < uVar1)) &&
     ((param_1 == 0xffff || (*(ushort *)(uVar1 - 2) == param_1)))) {
    **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) + 1;
    **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + -2;
    if (param_1 != 0xffff) {
      return (uint)param_1;
    }
    return 0;
  }
  if ((*(FILE **)((int)this + 0x54) != (FILE *)0x0) && (param_1 != 0xffff)) {
    if (*(int *)((int)this + 0x44) == 0) {
      wVar2 = ungetwc(param_1,*(FILE **)((int)this + 0x54));
      uVar3 = extraout_var;
      if (wVar2 != 0xffff) goto LAB_1000c67d;
    }
    if ((ushort *)**(int **)((int)this + 0x20) != (ushort *)((int)this + 0x48)) {
      *(ushort *)((int)this + 0x48) = param_1;
      Set_back((int)this);
      uVar3 = extraout_var_00;
LAB_1000c67d:
      return CONCAT22(uVar3,param_1);
    }
  }
  return 0xffff;
}



// Function: FUN_1000c6a0 at 1000c6a0

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_1000c6a0(void *this,char *param_1,int param_2,int param_3)

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
      *(undefined4 *)((int)this + 0x4c) = DAT_10030ea8;
      *(undefined4 *)((int)this + 0x44) = 0;
      return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
    }
  }
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
}



// Function: FUN_1000c710 at 1000c710

void __thiscall FUN_1000c710(void *this,locale *param_1)

{
  bool bVar1;
  facet *this_00;
  
  this_00 = FUN_1000bd60(param_1);
  bVar1 = std::codecvt_base::always_noconv((codecvt_base *)this_00);
  if (bVar1) {
    *(undefined4 *)((int)this + 0x44) = 0;
    return;
  }
  *(facet **)((int)this + 0x44) = this_00;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  return;
}



// Function: FUN_1000c750 at 1000c750

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_1000c750(void *this,wchar_t *param_1,int param_2,facet *param_3)

{
  bool bVar1;
  _iobuf *p_Var2;
  locale *plVar3;
  facet *pfVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001acf8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)((int)this + 0x54) == 0) {
    p_Var2 = std::_Fiopen(param_1,param_2,(int)param_3);
    if (p_Var2 != (_iobuf *)0x0) {
      *(undefined1 *)((int)this + 0x50) = 1;
      *(undefined1 *)((int)this + 0x4a) = 0;
      std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
                ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      *(_iobuf **)((int)this + 0x54) = p_Var2;
      *(undefined4 *)((int)this + 0x4c) = DAT_10030ea8;
      *(undefined4 *)((int)this + 0x44) = 0;
      plVar3 = (locale *)
               std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::getloc
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      local_8 = 0;
      pfVar4 = FUN_1000bd60(plVar3);
      bVar1 = std::codecvt_base::always_noconv((codecvt_base *)pfVar4);
      if (bVar1) {
        *(undefined4 *)((int)this + 0x44) = 0;
      }
      else {
        *(facet **)((int)this + 0x44) = pfVar4;
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
                  ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      }
      local_8 = 0xffffffff;
      if (param_3 != (facet *)0x0) {
        pfVar4 = std::locale::facet::_Decref(param_3);
        if (pfVar4 != (facet *)0x0) {
          (*(code *)**(undefined4 **)pfVar4)(1);
        }
      }
      ExceptionList = local_10;
      return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
    }
  }
  ExceptionList = local_10;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
}



// Function: FUN_1000c850 at 1000c850

void __thiscall FUN_1000c850(void *this,int param_1,size_t param_2,char param_3)

{
  if (param_2 == 1) {
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      this = *this;
    }
    *(char *)((int)this + param_1) = param_3;
    return;
  }
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    this = *this;
  }
  memset((void *)((int)this + param_1),(int)param_3,param_2);
  return;
}



// Function: FUN_1000c890 at 1000c890

void * FUN_1000c890(char *param_1)

{
  void *pvVar1;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10019739;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = (void *)0x0;
  if ((param_1 != (char *)0x0) && (pvVar1 = operator_new((uint)param_1), pvVar1 == (void *)0x0)) {
    param_1 = (char *)0x0;
    std::exception::exception((exception *)local_1c,&param_1);
    local_1c[0] = std::bad_alloc::vftable;
    local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10027634);
  }
  ExceptionList = local_10;
  return pvVar1;
}



// Function: FUN_1000c920 at 1000c920

basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *
FUN_1000c920(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  uint *puVar4;
  bool bVar5;
  ushort uVar6;
  wchar_t wVar7;
  char *pcVar8;
  locale *plVar9;
  facet *this_00;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar10;
  uint uStack_48;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ad40;
  local_10 = ExceptionList;
  uStack_48 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  local_18 = 0;
  pcVar8 = param_2;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  local_30 = (int)pcVar8 - (int)(param_2 + 1);
  local_2c = 0;
  iVar2 = *(int *)(*(int *)param_1 + 4);
  uVar3 = *(uint *)(param_1 + iVar2 + 0x20);
  local_24 = *(int *)(param_1 + iVar2 + 0x24);
  if ((local_24 < 0) ||
     ((local_24 < 1 && (((uVar3 == 0 || (local_24 < 0)) || ((local_24 < 1 && (uVar3 <= local_30)))))
      ))) {
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = uVar3 - local_30;
    local_24 = local_24 - (uint)(uVar3 < local_30);
  }
  puVar4 = &uStack_48;
  if (*(int **)(param_1 + iVar2 + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + iVar2 + 0x38) + 4))();
    puVar4 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar4;
  local_8 = 0;
  if ((*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) == 0) &&
     (*(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
       (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c) !=
      (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0)) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::flush
              (*(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)
                (param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c));
  }
  local_8 = 1;
  if (*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) != 0) {
    local_18 = 4;
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (param_1 + *(int *)(*(int *)param_1 + 4)),4,false);
    local_8 = 5;
    bVar5 = std::uncaught_exception();
    if (!bVar5) {
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(param_1);
    }
    local_8 = 0xffffffff;
    if (*(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) + 8))();
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  plVar9 = (locale *)std::ios_base::getloc((ios_base *)(param_1 + *(int *)(*(int *)param_1 + 4)));
  local_8._0_1_ = 3;
  this_00 = FUN_1000bc20(plVar9);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_1000b730(&local_1c);
  if ((*(uint *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x14) & 0x1c0) != 0x40) {
    while( true ) {
      if ((local_24 < 0) || ((local_24 < 1 && (local_28 == 0)))) goto LAB_1000ca82;
      uVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                        (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                          (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                         *(wchar_t *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x40));
      if (uVar6 == 0xffff) break;
      bVar5 = local_28 != 0;
      local_28 = local_28 + -1;
      local_24 = local_24 + -1 + (uint)bVar5;
    }
    local_18 = local_18 | 4;
  }
LAB_1000ca82:
  do {
    if (local_18 != 0) goto LAB_1000cb26;
    if ((local_2c < 0) || ((local_2c < 1 && (local_30 == 0)))) break;
    this = *(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
            (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38);
    wVar7 = std::ctype<wchar_t>::widen((ctype<wchar_t> *)this_00,*param_2);
    uVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc(this,wVar7);
    if (uVar6 == 0xffff) {
      local_18 = 4;
    }
    bVar5 = local_30 != 0;
    local_30 = local_30 - 1;
    local_2c = local_2c + -1 + (uint)bVar5;
    param_2 = param_2 + 1;
  } while( true );
LAB_1000caf6:
  if ((local_24 < 0) || ((local_24 < 1 && (local_28 == 0)))) goto LAB_1000cb26;
  uVar6 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::sputc
                    (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)
                      (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                     *(wchar_t *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x40));
  if (uVar6 == 0xffff) {
    local_18 = local_18 | 4;
LAB_1000cb26:
    iVar2 = *(int *)(*(int *)param_1 + 4);
    *(undefined4 *)(param_1 + iVar2 + 0x20) = 0;
    *(undefined4 *)(param_1 + iVar2 + 0x24) = 0;
    local_8 = 1;
    pbVar10 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)FUN_1000cb70();
    return pbVar10;
  }
  bVar5 = local_28 != 0;
  local_28 = local_28 + -1;
  local_24 = local_24 + -1 + (uint)bVar5;
  goto LAB_1000caf6;
}



// Function: Catch@1000cb4c at 1000cb4c

undefined * Catch_1000cb4c(void)

{
  int unaff_EBP;
  
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(**(int **)(unaff_EBP + 8) + 4) + (int)*(int **)(unaff_EBP + 8)),4,true);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000cb6d;
}



// Function: FUN_1000cb70 at 1000cb70

void FUN_1000cb70(void)

{
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  bool bVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  this = *(basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x34);
  std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
            ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(*unaff_ESI + 4) + (int)unaff_ESI),*(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  bVar1 = std::uncaught_exception();
  if (!bVar1) {
    std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::_Osfx(this);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int **)(this + *(int *)(*(int *)this + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(this + *(int *)(*(int *)this + 4) + 0x38) + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_1000cbd0 at 1000cbd0

undefined4 * __fastcall FUN_1000cbd0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ad91;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CContextSensitiveHelpProvider<class_CVehicleClassificationPageImpl>::vftable;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  local_8 = 4;
  if ((undefined **)param_1[4] != &PTR_10022cc0) {
    Ordinal_6((undefined **)param_1[4],uVar1);
    iVar2 = Ordinal_2(&PTR_10022cc0);
    param_1[4] = iVar2;
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x8007000e);
    }
  }
  param_1[1] = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000cc80 at 1000cc80

void __fastcall FUN_1000cc80(undefined4 *param_1)

{
  Ordinal_6(*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000cca0 at 1000cca0

void __thiscall FUN_1000cca0(void *this,GUID *param_1)

{
  int iVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  iVar1 = Ordinal_2(local_88);
  *(int *)this = iVar1;
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000cd00 at 1000cd00

int __thiscall FUN_1000cd00(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  iVar2 = Ordinal_7(uVar1);
  if (iVar2 == 0) {
    return 0;
  }
                    /* WARNING: Load size is inaccurate */
  param_1 = (undefined4 *)0x0;
  iVar2 = Ordinal_313(*this,uVar1,&param_1);
  if (-1 < iVar2) {
                    /* WARNING: Load size is inaccurate */
    Ordinal_6(*this);
    *(undefined4 **)this = param_1;
  }
  return iVar2;
}



// Function: FUN_1000cd50 at 1000cd50

void __fastcall FUN_1000cd50(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ade1;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CContextSensitiveHelpProvider<class_CVehicleClassificationPageImpl>::vftable;
  local_8 = 1;
  Ordinal_6(param_1[4],uVar2);
  local_8 = local_8 & 0xffffff00;
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000cde0 at 1000cde0

undefined4 * __thiscall FUN_1000cde0(void *this,byte param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ade1;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this =
       CContextSensitiveHelpProvider<class_CVehicleClassificationPageImpl>::vftable;
  local_8 = 1;
  Ordinal_6(*(undefined4 *)((int)this + 0x10),uVar2);
  local_8 = local_8 & 0xffffff00;
  piVar1 = *(int **)((int)this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)((int)this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000ce80 at 1000ce80

void __fastcall FUN_1000ce80(undefined4 *param_1)

{
  operator_delete((void *)*param_1);
  return;
}



// Function: FUN_1000ce90 at 1000ce90

int * __thiscall FUN_1000ce90(void *this,int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    uVar1 = Ordinal_149(iVar2);
    iVar2 = Ordinal_150(*param_1,uVar1);
  }
  *(int *)this = iVar2;
  if ((*param_1 != 0) && (iVar2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  return (int *)this;
}



// Function: FUN_1000ced0 at 1000ced0

int __thiscall FUN_1000ced0(void *this,int param_1)

{
  LONG *lpAddend;
  uint _Size;
  void *_Src;
  int iVar1;
  int iVar2;
  LONG LVar3;
  
                    /* WARNING: Load size is inaccurate */
  _Src = *this;
  lpAddend = (LONG *)((int)_Src + -0xc);
  if ((1 < *(int *)((int)_Src + -0xc)) || (*(int *)((int)_Src + -4) < param_1)) {
    iVar1 = *(int *)((int)_Src + -8);
    if (param_1 < iVar1) {
      param_1 = iVar1;
    }
    iVar2 = FUN_1000c140(this,param_1);
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
    if (lpAddend != (LONG *)PTR_DAT_1002f6b8) {
      LVar3 = InterlockedDecrement(lpAddend);
      if (LVar3 < 1) {
        operator_delete__(lpAddend);
      }
    }
  }
                    /* WARNING: Load size is inaccurate */
  return *this;
}



// Function: FUN_1000cf60 at 1000cf60

void __fastcall FUN_1000cf60(int *param_1)

{
  uint _Size;
  void *_Src;
  LONG LVar1;
  int iVar2;
  
  _Src = (void *)*param_1;
  if (1 < *(int *)((int)_Src + -0xc)) {
    if ((undefined *)((int)_Src + -0xc) != PTR_DAT_1002f6b8) {
      LVar1 = InterlockedDecrement((LONG *)((int)_Src + -0xc));
      if (LVar1 < 1) {
        operator_delete__((void *)(*param_1 + -0xc));
      }
      *param_1 = (int)PTR_DAT_1002f6bc;
    }
    iVar2 = FUN_1000c140(param_1,*(int *)((int)_Src + -8));
    if (iVar2 != 0) {
      _Size = *(int *)((int)_Src + -8) * 2 + 2;
      if (_Size <= *(int *)(*param_1 + -4) * 2 + 2U) {
        memcpy((void *)*param_1,_Src,_Size);
      }
    }
  }
  return;
}



// Function: FUN_1000cfd0 at 1000cfd0

HRESULT __fastcall FUN_1000cfd0(void *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 *puVar4;
  uint local_38 [2];
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001ae20;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_1000b750(param_1,local_38,*(uint *)((int)param_1 + 0x14));
  if (local_30 == 0) {
    HVar3 = CoCreateInstance((IID *)&DAT_10023470,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100234f0,
                             (LPVOID *)((int)param_1 + 8));
    if (-1 < HVar3) {
      puVar4 = *(undefined4 **)((int)param_1 + 8);
      HVar3 = (**(code **)*puVar4)(puVar4,&DAT_10023534,(int)param_1 + 0x10,uVar2);
      ExceptionList = local_10;
      return HVar3;
    }
  }
  else {
    local_14 = (int *)0x0;
    local_8 = 1;
    HVar3 = CoCreateInstance((IID *)&DAT_10023480,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10023510,&local_14
                            );
    if (-1 < HVar3) {
      (**(code **)*local_14)(local_14,&DAT_10023534,(int)param_1 + 0x10);
      (**(code **)*local_14)(local_14,&DAT_100234f0,(int)param_1 + 8);
      puVar4 = (undefined4 *)((int)param_1 + 4);
      HVar3 = (**(code **)*local_14)(local_14,&DAT_10023544,puVar4);
      if (-1 < HVar3) {
        local_18 = 0;
        local_8._0_1_ = 2;
        FUN_1000c0c0(&local_18,local_30);
        uVar1 = local_18;
        (**(code **)(*(int *)*puVar4 + 0x10))((int *)*puVar4,local_18);
        (**(code **)(*(int *)*puVar4 + 0x18))((int *)*puVar4,local_28);
        (**(code **)(*(int *)*puVar4 + 0x20))((int *)*puVar4,local_2c);
        local_8 = CONCAT31(local_8._1_3_,1);
        Ordinal_6(uVar1);
      }
    }
    local_8 = 0xffffffff;
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 8))(local_14);
    }
  }
  ExceptionList = local_10;
  return HVar3;
}



// Function: FUN_1000d140 at 1000d140

void __fastcall FUN_1000d140(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ae97;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8._0_1_ = 3;
  local_8._1_3_ = 0;
  piVar1 = *(int **)(param_1 + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  }
  local_8._0_1_ = 2;
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8._0_1_ = 1;
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  FUN_1000ba70(param_1 + 4);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d200 at 1000d200

undefined4 __fastcall FUN_1000d200(int param_1)

{
  uint3 uVar1;
  void *this;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001aeeb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = operator_new(0x10);
  if (this == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    if (param_1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(param_1 + 0x110);
    }
    piVar4 = (int *)0x0;
    local_8._1_3_ = 0;
    uVar1 = local_8._1_3_;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
      uVar1 = local_8._1_3_;
    }
    local_8._1_3_ = uVar1;
    local_8 = (uint)local_8._1_3_ << 8;
    puVar3 = FUN_100168c0(this,piVar2,piVar4);
  }
  *(undefined4 **)(param_1 + 300) = puVar3;
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000d2b0 at 1000d2b0

void __fastcall FUN_1000d2b0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000d310 at 1000d310

void __thiscall FUN_1000d310(void *this,undefined4 param_1)

{
  Ordinal_25(*(undefined4 *)((int)this + 0x10),param_1,&param_1);
  Ordinal_2(param_1);
  return;
}



// Function: FUN_1000d340 at 1000d340

void __thiscall FUN_1000d340(void *this,undefined4 param_1,undefined4 param_2)

{
  Ordinal_26(*(undefined4 *)((int)this + 0x10),param_1,param_2);
  return;
}



// Function: FUN_1000d360 at 1000d360

undefined4 * __thiscall FUN_1000d360(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001af63;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = safearray<wchar_t*,8>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9((int)this + 8,uVar1);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_1000d3d0 at 1000d3d0

int * __thiscall FUN_1000d3d0(void *this,uint param_1,uint param_2)

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
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
      pvVar1 = *this;
    }
    memmove((void *)((int)pvVar4 + param_1),(void *)((int)pvVar1 + param_2 + param_1),
            uVar2 - param_2);
    iVar3 = *(int *)((int)this + 0x10) - param_2;
    *(int *)((int)this + 0x10) = iVar3;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined1 *)(*this + iVar3) = 0;
      return (int *)this;
    }
    *(undefined1 *)((int)this + iVar3) = 0;
  }
  return (int *)this;
}



// Function: FUN_1000d460 at 1000d460

undefined4 __fastcall FUN_1000d460(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001afc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = 0;
  iVar2 = __RTDynamicCast(param_1,0,
                          &CComErrorDisplay<class_CVehicleClassificationPageImpl>::
                           RTTI_Type_Descriptor,
                          &CVehicleClassificationPageImpl::RTTI_Type_Descriptor,0,
                          DAT_10030e10 ^ (uint)&stack0xfffffffc);
  local_14 = (int *)(**(code **)(*(int *)(iVar2 + 0x28) + 0x4c))(2);
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  if (local_14 != (int *)0x0) {
    local_18 = (int *)0x0;
    local_8._0_1_ = 3;
    local_8._1_3_ = 0;
    (**(code **)*local_14)(local_14,&DAT_1002355c,&local_18);
    if (local_14 != (int *)0x0) {
      Ordinal_30(&local_14,0);
    }
    if (local_18 != (int *)0x0) {
      local_1c = (int *)0x0;
      local_8._0_1_ = 5;
      (**(code **)(*local_18 + 0x20))(local_18,&local_1c);
      (**(code **)*local_1c)(local_1c,&DAT_1002356c,&local_20);
      local_8._0_1_ = 3;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  uVar1 = local_20;
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_1000d590 at 1000d590

void __thiscall FUN_1000d590(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001aff0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = param_1 | 0xf;
  if (uVar3 != 0xffffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    param_1 = uVar3;
    if ((uVar3 / 3 < uVar2) && (param_1 = uVar2 + uVar1, -uVar2 - 2 < uVar1)) {
      param_1 = 0xfffffffe;
    }
  }
  local_8 = 0;
  FUN_1000c890((char *)(param_1 + 1));
  local_8 = 0xffffffff;
  FUN_1000d64c();
  return;
}



// Function: Catch@1000d619 at 1000d619

undefined * Catch_1000d619(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_1000c890((char *)(iVar1 + 1));
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_1000d643;
}



// Function: FUN_1000d64c at 1000d64c

void FUN_1000d64c(void)

{
  undefined4 *_Src;
  size_t _Size;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  _Size = *(size_t *)(unaff_EBP + 0xc);
  if (_Size != 0) {
    _Src = unaff_ESI;
    if (0xf < (uint)unaff_ESI[5]) {
      _Src = (undefined4 *)*unaff_ESI;
    }
    memcpy(unaff_EBX,_Src,_Size);
    _Size = *(size_t *)(unaff_EBP + 0xc);
  }
  if (0xf < (uint)unaff_ESI[5]) {
    operator_delete((void *)*unaff_ESI);
    _Size = *(size_t *)(unaff_EBP + 0xc);
  }
  *(undefined1 *)unaff_ESI = 0;
  *unaff_ESI = unaff_EBX;
  unaff_ESI[5] = unaff_EDI;
  unaff_ESI[4] = _Size;
  if (0xf < unaff_EDI) {
    unaff_ESI = unaff_EBX;
  }
  *(undefined1 *)((int)unaff_ESI + _Size) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: Catch@1000d6ab at 1000d6ab

void Catch_1000d6ab(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  if (0xf < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 0xf;
  puVar1[4] = 0;
  *(undefined1 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// Function: FUN_1000d6e0 at 1000d6e0

int __thiscall FUN_1000d6e0(void *this,LPCWSTR param_1,LPCWSTR param_2)

{
  LONG *lpAddend;
  LPCWSTR pWVar1;
  void *_Src;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  LONG LVar7;
  wchar_t *_Dst;
  int iVar8;
  wchar_t *pwVar9;
  int iVar10;
  int local_10;
  LPCWSTR local_c;
  
  if ((param_1 != (LPCWSTR)0x0) && (iVar3 = lstrlenW(param_1), iVar3 != 0)) {
    if (param_2 == (LPCWSTR)0x0) {
      local_c = param_2;
    }
    else {
      local_c = (LPCWSTR)lstrlenW(param_2);
    }
                    /* WARNING: Load size is inaccurate */
    pwVar9 = *this;
    pWVar1 = pwVar9 + *(int *)(pwVar9 + -4);
    local_10 = 0;
    if (pwVar9 < pWVar1) {
      do {
        pwVar4 = wcsstr(pwVar9,param_1);
        while (pwVar4 != (wchar_t *)0x0) {
          local_10 = local_10 + 1;
          pwVar9 = pwVar4 + iVar3;
          pwVar4 = wcsstr(pwVar9,param_1);
        }
        iVar5 = lstrlenW(pwVar9);
        pwVar9 = pwVar9 + iVar5 + 1;
      } while (pwVar9 < pWVar1);
      if (0 < local_10) {
        FUN_1000cf60((int *)this);
                    /* WARNING: Load size is inaccurate */
        _Src = *this;
        iVar5 = *(int *)((int)_Src + -8);
        iVar10 = ((int)local_c - iVar3) * local_10 + iVar5;
        if ((*(int *)((int)_Src + -4) < iVar10) || (1 < *(int *)((int)_Src + -0xc))) {
          lpAddend = (LONG *)((int)_Src + -0xc);
          iVar6 = FUN_1000c140(this,iVar10);
          if (iVar6 == 0) {
            return -1;
          }
          uVar2 = *(int *)((int)_Src + -8) * 2;
          if (uVar2 <= iVar10 * 2 + 2U) {
                    /* WARNING: Load size is inaccurate */
            memcpy(*this,_Src,uVar2);
          }
          if ((lpAddend != (LONG *)PTR_DAT_1002f6b8) &&
             (LVar7 = InterlockedDecrement(lpAddend), LVar7 < 1)) {
            operator_delete__(lpAddend);
          }
        }
                    /* WARNING: Load size is inaccurate */
        pwVar4 = *this;
        pwVar9 = pwVar4 + *(int *)(pwVar4 + -4);
        for (; pwVar4 < pwVar9; pwVar4 = pwVar4 + iVar6 + 1) {
          _Dst = wcsstr(pwVar4,param_1);
          while (_Dst != (wchar_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
            iVar6 = (int)_Dst - *this >> 1;
            iVar8 = (iVar5 - iVar6) - iVar3;
            iVar6 = *(int *)(*this + -4) - iVar6;
            uVar2 = iVar8 * 2;
            if (uVar2 <= (iVar6 - (int)local_c) * 2 + 2U) {
              memmove(_Dst + (int)local_c,_Dst + iVar3,uVar2);
            }
            if ((uint)((int)local_c * 2) <= iVar6 * 2 + 2U) {
              memcpy(_Dst,param_2,(int)local_c * 2);
            }
            pwVar4 = _Dst + (int)local_c;
            iVar5 = (int)local_c + (iVar5 - iVar3);
            pwVar4[iVar8] = L'\0';
            _Dst = wcsstr(pwVar4,param_1);
          }
          iVar6 = lstrlenW(pwVar4);
        }
                    /* WARNING: Load size is inaccurate */
        *(int *)(*this + -8) = iVar10;
      }
    }
    return local_10;
  }
  return 0;
}



// Function: FUN_1000d900 at 1000d900

void __thiscall FUN_1000d900(void *this,int param_1,void *param_2)

{
  uint _Size;
  LONG LVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  iVar2 = *this;
  if ((1 < *(int *)(iVar2 + -0xc)) || (*(int *)(iVar2 + -4) < param_1)) {
    if ((undefined *)(iVar2 + -0xc) != PTR_DAT_1002f6b8) {
      LVar1 = InterlockedDecrement((LONG *)(iVar2 + -0xc));
      if (LVar1 < 1) {
                    /* WARNING: Load size is inaccurate */
        operator_delete__((void *)(*this + -0xc));
      }
      *(undefined **)this = PTR_DAT_1002f6bc;
    }
    iVar2 = FUN_1000c140(this,param_1);
    if (iVar2 == 0) {
      return;
    }
  }
  _Size = param_1 * 2;
  if (_Size <= _Size + 2) {
                    /* WARNING: Load size is inaccurate */
    memcpy(*this,param_2,_Size);
  }
                    /* WARNING: Load size is inaccurate */
  *(int *)(*this + -8) = param_1;
                    /* WARNING: Load size is inaccurate */
  *(undefined2 *)(_Size + *this) = 0;
  return;
}



// Function: FUN_1000d990 at 1000d990

void __fastcall FUN_1000d990(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b067;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CComErrorHandler::vftable;
  local_8 = 3;
  if (7 < (uint)param_1[0xb]) {
    operator_delete((void *)param_1[6]);
  }
  param_1[0xb] = 7;
  param_1[10] = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 2;
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  local_8._0_1_ = 1;
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000da70 at 1000da70

void __fastcall FUN_1000da70(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) != 0) {
    Ordinal_30(piVar1,0);
  }
  (**(code **)**(undefined4 **)(param_1 + 0xc))
            (*(undefined4 **)(param_1 + 0xc),&DAT_100234f0,piVar1);
  Ordinal_201(0,*piVar1);
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    Ordinal_30((int *)(param_1 + 0xc),0);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    Ordinal_30(param_1 + 0x10,0);
  }
  if (*(int *)(param_1 + 4) != 0) {
    Ordinal_30((int *)(param_1 + 4),0);
  }
  return;
}



// Function: FUN_1000daf0 at 1000daf0

HRESULT __fastcall FUN_1000daf0(int param_1)

{
  int *piVar1;
  int iVar2;
  HRESULT HVar3;
  LPVOID *ppv;
  
  piVar1 = (int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) != 0) {
    Ordinal_30(piVar1,0);
  }
  iVar2 = Ordinal_200(0,piVar1);
  if (iVar2 == 1) {
    HVar3 = CoCreateInstance((IID *)&DAT_10023490,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10023500,
                             (LPVOID *)(param_1 + 0xc));
    return HVar3;
  }
  ppv = (LPVOID *)(param_1 + 0xc);
  if (*ppv != (LPVOID)0x0) {
    Ordinal_30(ppv,0);
  }
  iVar2 = (*(code *)**(undefined4 **)*piVar1)((undefined4 *)*piVar1,&DAT_10023500,ppv);
  if (iVar2 < 0) {
    if (*piVar1 != 0) {
      Ordinal_30(piVar1,0);
    }
    iVar2 = CoCreateInstance((IID *)&DAT_10023490,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10023500,ppv);
  }
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0);
  }
  return iVar2;
}



// Function: FUN_1000db90 at 1000db90

undefined4 * __thiscall FUN_1000db90(void *this,byte param_1)

{
  FUN_1000d990((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_1000dbc0 at 1000dbc0

void FUN_1000dbc0(undefined4 param_1)

{
  FUN_10004580(DAT_10030e30,0x66,param_1,(int *)0x0);
  return;
}



// Function: FUN_1000dbe0 at 1000dbe0

void __fastcall FUN_1000dbe0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b0b6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    FreeStdCallThunk(*(void **)(param_1 + 0x14));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000dc40 at 1000dc40

void __fastcall FUN_1000dc40(undefined4 *param_1)

{
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// Function: FUN_1000dc70 at 1000dc70

undefined4 * __fastcall FUN_1000dc70(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b137;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 + 1 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = param_1 + -10;
  }
  puVar3[0xc] = 0;
  puVar3[0xf] = 0;
  puVar3[0x10] = 0;
  puVar3[0x11] = 0;
  puVar3[0x12] = 0;
  puVar3[0x13] = 0;
  puVar3[0x14] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  puVar3[0x15] = 0;
  puVar3[1] = 0;
  *param_1 = CComECMPropertyPageImpl<class_CVehicleClassificationPageImpl>::vftable;
  param_1[1] = CComECMPropertyPageImpl<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  piVar1 = param_1 + 0xe;
  *piVar1 = 0;
  param_1[0xf] = 0;
  local_8 = 8;
  if (*piVar1 != 0) {
    Ordinal_30(piVar1,0,uVar2);
  }
  param_1[0x10] = 0;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_1000dd40 at 1000dd40

void __cdecl FUN_1000dd40(wchar_t *param_1,ushort param_2,uint *param_3,uint *param_4)

{
  HDC hdc;
  int nNumerator;
  HFONT h;
  uint uVar1;
  int nDenominator;
  tagSIZE local_b0;
  HGDIOBJ local_a8;
  uint *local_a4;
  tagTEXTMETRICW local_a0;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
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
      FUN_10003e50(local_64.lfFaceName,0x20,param_1,0xffffffff);
      h = CreateFontIndirectW(&local_64);
      if (h != (HFONT)0x0) {
        local_a8 = SelectObject(hdc,h);
        GetTextMetricsW(hdc,&local_a0);
        GetTextExtentPointW(hdc,L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",0x34,
                            &local_b0);
        SelectObject(hdc,local_a8);
        DeleteObject(h);
        *local_a4 = local_a0.tmHeight;
        param_3[1] = local_a0.tmExternalLeading + local_a0.tmHeight;
        *param_3 = (local_b0.cx + 0x1a) / 0x34;
        ReleaseDC((HWND)0x0,hdc);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      ReleaseDC((HWND)0x0,hdc);
    }
  }
  uVar1 = GetDialogBaseUnits();
  *param_3 = uVar1 & 0xffff;
  param_3[1] = uVar1 >> 0x10;
  *local_a4 = uVar1 >> 0x10;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000deb0 at 1000deb0

void __cdecl FUN_1000deb0(int param_1)

{
  short sVar1;
  short *psVar2;
  
  if (*(short *)(param_1 + 2) == -1) {
    psVar2 = (short *)(param_1 + 0x1a);
  }
  else {
    psVar2 = (short *)(param_1 + 0x12);
  }
  if (*psVar2 == -1) {
    psVar2 = psVar2 + 2;
  }
  else {
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  if (*psVar2 == -1) {
    psVar2 = psVar2 + 2;
  }
  else {
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return;
}



// Function: FUN_1000df10 at 1000df10

undefined4 __thiscall FUN_1000df10(void *this,int param_1)

{
  if (param_1 == 1) {
    return *(undefined4 *)((int)this + 0x30);
  }
  if (param_1 != 2) {
    return 0;
  }
  return *(undefined4 *)((int)this + 0x34);
}



// Function: FUN_1000df30 at 1000df30

undefined4 FUN_1000df30(undefined4 param_1,undefined2 *param_2)

{
  if (param_2 == (undefined2 *)0x0) {
    return 0x80070057;
  }
  *param_2 = 0;
  return 0;
}



// Function: FUN_1000df50 at 1000df50

void FUN_1000df50(int *param_1,short *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2);
  if ((-1 < iVar1) && (*param_2 == 0)) {
    (**(code **)(*param_1 + 0x28))(param_1,param_2);
  }
  return;
}



// Function: FUN_1000df80 at 1000df80

undefined4 FUN_1000df80(void)

{
  return 0x80004001;
}



// Function: FUN_1000df90 at 1000df90

int FUN_1000df90(undefined4 param_1,int param_2)

{
  return (uint)(param_2 == 0) * 2 + -0x7fffbfff;
}



// Function: FUN_1000dfb0 at 1000dfb0

undefined4 FUN_1000dfb0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x2c;
  }
  if (param_2 == (int *)0x0) {
    piVar1 = *(int **)(iVar2 + 0x30);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(iVar2 + 0x30) = 0;
      return 0;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x30) != 0) {
      return 0x8000ffff;
    }
    *(int **)(iVar2 + 0x30) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
  }
  return 0;
}



// Function: FUN_1000e010 at 1000e010

undefined4 FUN_1000e010(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b160;
  local_10 = ExceptionList;
  if (param_1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = param_1 + -0x2c;
  }
  if (param_3 != 0) {
    ExceptionList = &local_10;
    if ((*(int *)(iVar5 + 0x34) != 0) && (*(int *)(iVar5 + 0x38) != 0)) {
      uVar4 = 0;
      if (*(int *)(iVar5 + 0x38) != 0) {
        do {
          piVar1 = *(int **)(*(int *)(iVar5 + 0x34) + uVar4 * 4);
          (**(code **)(*piVar1 + 8))(piVar1);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(iVar5 + 0x38));
      }
      operator_delete__(*(void **)(iVar5 + 0x34));
    }
    *(undefined4 *)(iVar5 + 0x34) = 0;
    local_8 = 0;
    pvVar2 = operator_new__(-(uint)((int)((ulonglong)param_2 * 4 >> 0x20) != 0) |
                            (uint)((ulonglong)param_2 * 4));
    *(void **)(iVar5 + 0x34) = pvVar2;
    local_8 = 0xffffffff;
    uVar3 = FUN_1000e0e3();
    return uVar3;
  }
  return 0x80004003;
}



// Function: Catch@1000e0d0 at 1000e0d0

undefined * Catch_1000e0d0(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_1000e0dd;
}



// Function: FUN_1000e0e3 at 1000e0e3

undefined4 FUN_1000e0e3(void)

{
  int *piVar1;
  uint unaff_EBX;
  int unaff_EBP;
  uint uVar2;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x34) == 0) {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  uVar2 = 0;
  if (unaff_EBX != 0) {
    do {
      piVar1 = *(int **)(*(int *)(unaff_EBP + 0x10) + uVar2 * 4);
      (**(code **)(*piVar1 + 4))(piVar1);
      *(undefined4 *)(*(int *)(unaff_EDI + 0x34) + uVar2 * 4) =
           *(undefined4 *)(*(int *)(unaff_EBP + 0x10) + uVar2 * 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < unaff_EBX);
  }
  *(uint *)(unaff_EDI + 0x38) = unaff_EBX;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}



// Function: FUN_1000e140 at 1000e140

undefined4 FUN_1000e140(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x2c;
  }
  if (*(HWND *)(iVar1 + 4) == (HWND)0x0) {
    return 0x8000ffff;
  }
  ShowWindow(*(HWND *)(iVar1 + 4),param_2);
  return 0;
}



// Function: FUN_1000e180 at 1000e180

undefined4 FUN_1000e180(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 + -0x2c;
  }
  if (*(HWND *)(iVar1 + 4) == (HWND)0x0) {
    return 0x8000ffff;
  }
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  MoveWindow(*(HWND *)(iVar1 + 4),*param_2,param_2[1],param_2[2] - *param_2,param_2[3] - param_2[1],
             1);
  return 0;
}



// Function: FUN_1000e1e0 at 1000e1e0

bool FUN_1000e1e0(int param_1)

{
  if (param_1 != 0) {
    return *(int *)(param_1 + 0x28) == 0;
  }
  return iRam00000054 == 0;
}



// Function: FUN_1000e210 at 1000e210

undefined4 FUN_1000e210(void)

{
  return 0;
}



// Function: FUN_1000e220 at 1000e220

bool FUN_1000e220(int param_1,LPMSG param_2)

{
  uint uVar1;
  BOOL BVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x2c;
  }
  uVar1 = param_2->message;
  if (((uVar1 < 0x100) || (0x109 < uVar1)) && ((uVar1 < 0x200 || (0x20d < uVar1)))) {
    return true;
  }
  BVar2 = IsDialogMessageW(*(HWND *)(iVar3 + 4),param_2);
  return (bool)('\x01' - (BVar2 != 0));
}



// Function: FUN_1000e270 at 1000e270

void __cdecl FUN_1000e270(int *param_1,size_t param_2,void *param_3,int param_4)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80070057);
  }
  if ((int)param_2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80070057);
  }
  if (param_3 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80070057);
  }
  pvVar1 = (void *)*param_1;
  if (pvVar1 == param_3) {
    if ((int)param_2 <= param_4) goto LAB_1000e2d8;
    pvVar1 = calloc(param_2,2);
  }
  else {
    if ((int)param_2 <= param_4) {
      free(pvVar1);
LAB_1000e2d8:
      *param_1 = (int)param_3;
      goto LAB_1000e2da;
    }
    pvVar1 = _recalloc(pvVar1,param_2,2);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x8007000e);
    }
  }
  *param_1 = (int)pvVar1;
LAB_1000e2da:
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x8007000e);
  }
  return;
}



// Function: FUN_1000e310 at 1000e310

void __thiscall FUN_1000e310(void *this,byte param_1)

{
  FUN_1000e4b0((void *)((int)this + -4),param_1);
  return;
}



// Function: FUN_1000e320 at 1000e320

void __fastcall FUN_1000e320(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != param_1 + 1) {
    free((undefined4 *)*param_1);
  }
  return;
}



// Function: FUN_1000e340 at 1000e340

undefined4 FUN_1000e340(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x30);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10022c74,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_1000e380 at 1000e380

undefined4 FUN_1000e380(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x34);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10022c74,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_1000e3c0 at 1000e3c0

undefined4 FUN_1000e3c0(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1 + -0x2c;
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



// Function: FUN_1000e400 at 1000e400

void __fastcall FUN_1000e400(undefined4 *param_1)

{
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  return;
}



// Function: FUN_1000e420 at 1000e420

void FUN_1000e420(HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  HANDLE hProcess;
  undefined4 *lpBaseAddress;
  SIZE_T dwSize;
  
  piVar2 = (int *)Ordinal_44(&DAT_100312d0);
  if (piVar2 == (int *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*piVar2 + 8);
  piVar2[1] = (int)param_1;
  iVar3 = (*pcVar1)();
  if (piVar2[5] == 0) {
    pvVar4 = __AllocStdCallThunk_cmn();
    piVar2[5] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_1000e487;
  }
  lpBaseAddress = (undefined4 *)piVar2[5];
  dwSize = 0xd;
  *lpBaseAddress = 0x42444c7;
  lpBaseAddress[1] = piVar2;
  *(undefined1 *)(lpBaseAddress + 2) = 0xe9;
  *(int *)((int)lpBaseAddress + 9) = (iVar3 - (int)lpBaseAddress) + -0xd;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,lpBaseAddress,dwSize);
LAB_1000e487:
  pcVar1 = (code *)piVar2[5];
  SetWindowLongW(param_1,4,(LONG)pcVar1);
  (*pcVar1)(param_1,param_2,param_3,param_4);
  return;
}



// Function: FUN_1000e4b0 at 1000e4b0

void * __thiscall FUN_1000e4b0(void *this,byte param_1)

{
  FUN_1000d140((int)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// Function: FUN_1000e4e0 at 1000e4e0

void __fastcall FUN_1000e4e0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b188;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e530 at 1000e530

HWND __thiscall FUN_1000e530(void *this,HWND param_1,LPARAM param_2)

{
  void *pvVar1;
  HANDLE hProcess;
  HWND pHVar2;
  undefined4 *lpBaseAddress;
  SIZE_T dwSize;
  
  if (*(int *)((int)this + 0x14) == 0) {
    pvVar1 = __AllocStdCallThunk_cmn();
    *(void **)((int)this + 0x14) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      SetLastError(0xe);
      return (HWND)0x0;
    }
  }
  lpBaseAddress = *(undefined4 **)((int)this + 0x14);
  dwSize = 0xd;
  *lpBaseAddress = 0x42444c7;
  lpBaseAddress[1] = 0;
  *(undefined1 *)(lpBaseAddress + 2) = 0xe9;
  *(int *)((int)lpBaseAddress + 9) = -0xd - (int)lpBaseAddress;
  hProcess = GetCurrentProcess();
  FlushInstructionCache(hProcess,lpBaseAddress,dwSize);
  Ordinal_43(&DAT_100312d0,(int)this + 8,this);
  pHVar2 = CreateDialogParamW(DAT_1003129c,(LPCWSTR)0x65,param_1,FUN_1000e420,param_2);
  return pHVar2;
}



// Function: FUN_1000e5c0 at 1000e5c0

void __cdecl FUN_1000e5c0(uint *param_1,wchar_t *param_2,undefined2 *param_3)

{
  LPCWSTR lpString;
  wchar_t wVar1;
  rsize_t _DstSize;
  uint uVar2;
  undefined2 *puVar3;
  wchar_t *pwVar4;
  int iVar5;
  errno_t eVar6;
  wchar_t *local_118;
  wchar_t local_114 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b1bb;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == (uint *)0x0) {
switchD_1000e756_caseD_1:
                    /* WARNING: Subroutine does not return */
    FUN_10001690(0x80004005);
  }
  if (*(short *)((int)param_1 + 2) == -1) {
    uVar2 = param_1[3];
  }
  else {
    uVar2 = *param_1;
  }
  if ((uVar2 & 0x40) != 0) {
    if (param_2 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x80004005);
    }
    if (param_3 == (undefined2 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x80004005);
    }
    puVar3 = (undefined2 *)FUN_1000deb0((int)param_1);
    *param_3 = *puVar3;
    local_118 = local_114;
    lpString = puVar3 + (uint)(*(short *)((int)param_1 + 2) == -1) * 2 + 1;
    if (lpString != (LPCWSTR)0x0) {
      iVar5 = lstrlenW(lpString);
      FUN_1000e270((int *)&local_118,iVar5 + 1U,local_114,0x80);
      _DstSize = (iVar5 + 1U) * 2;
      eVar6 = memcpy_s(local_118,_DstSize,lpString,_DstSize);
      switch(eVar6) {
      case 0:
      case 0x50:
        goto switchD_1000e756_caseD_0;
      default:
        goto switchD_1000e756_caseD_1;
      case 0xc:
                    /* WARNING: Subroutine does not return */
        FUN_10001690(0x8007000e);
      case 0x16:
      case 0x22:
                    /* WARNING: Subroutine does not return */
        FUN_10001690(0x80070057);
      }
    }
    local_118 = (wchar_t *)0x0;
switchD_1000e756_caseD_0:
    local_8 = 0;
    FUN_10003e50(param_2,0x20,local_118,0xffffffff);
    pwVar4 = param_2;
    do {
      wVar1 = *pwVar4;
      pwVar4 = pwVar4 + 1;
    } while (wVar1 != L'\0');
    if (0x1f < (uint)((int)pwVar4 - (int)(param_2 + 1) >> 1)) {
      param_2[0x1f] = L'\0';
    }
    local_8 = 0xffffffff;
    if (local_118 != local_114) {
      free(local_118);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000e7e0 at 1000e7e0

undefined4 FUN_1000e7e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x38);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10022e58,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_1000e820 at 1000e820

undefined4 FUN_1000e820(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    Ordinal_30(param_1 + 0x38,0);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    Ordinal_30(param_1 + 0x30,0);
  }
  return 0;
}



// Function: FUN_1000e860 at 1000e860

undefined4 FUN_1000e860(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)(param_1 + 0x3c);
    if (*piVar2 != 0) {
      Ordinal_30(piVar2,0);
    }
    uVar1 = (**(code **)*param_2)(param_2,&DAT_10023734,piVar2);
    return uVar1;
  }
  return 0x80004003;
}



// Function: FUN_1000e8a0 at 1000e8a0

undefined4 FUN_1000e8a0(int *param_1,HWND param_2,int *param_3)

{
  HWND pHVar1;
  int *this;
  
  if (param_1 == (int *)0x0) {
    this = (int *)0x0;
  }
  else {
    this = param_1 + -0xb;
  }
  if (param_3 == (int *)0x0) {
    return 0x80004003;
  }
  pHVar1 = FUN_1000e530(this,param_2,0);
  this[1] = (int)pHVar1;
  (**(code **)(*param_1 + 0x24))(param_1,param_3);
  param_1[4] = param_3[2] - *param_3;
  param_1[5] = param_3[3] - param_3[1];
  return 0;
}



// Function: FUN_1000e900 at 1000e900

void __fastcall FUN_1000e900(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b200;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  CoTaskMemFree((LPVOID)*param_1);
  *param_1 = 0;
  ExceptionList = local_10;
  return;
}



// Function: FUN_1000e950 at 1000e950

LPVOID FUN_1000e950(uint param_1)

{
  HMODULE pHVar1;
  HRSRC pHVar2;
  ushort *puVar3;
  LPVOID pvVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pHVar1 = DAT_1003129c;
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b248;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pHVar2 = FindResourceW(DAT_1003129c,(LPCWSTR)((param_1 >> 4) + 1 & 0xffff),(LPCWSTR)0x6);
  if ((pHVar2 != (HRSRC)0x0) &&
     (puVar3 = (ushort *)FUN_1000b5f0(pHVar1,pHVar2,param_1), puVar3 != (ushort *)0x0)) {
    local_8 = 2;
    pvVar4 = CoTaskMemAlloc((*puVar3 + 1) * 2);
    if (pvVar4 != (LPVOID)0x0) {
      FUN_1000b530(pvVar4,(uint)*puVar3 * 2 + 2,puVar3 + 1,(uint)*puVar3 * 2);
      *(undefined2 *)((int)pvVar4 + (uint)*puVar3 * 2) = 0;
    }
    local_8 = 0xffffffff;
    CoTaskMemFree((LPVOID)0x0);
    ExceptionList = local_10;
    return pvVar4;
  }
  ExceptionList = local_10;
  return (LPVOID)0x0;
}



// Function: FUN_1000ea40 at 1000ea40

undefined4 __thiscall FUN_1000ea40(void *this,int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uStack_30;
  undefined4 local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b290;
  local_10 = ExceptionList;
  uStack_30 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  local_1c = 1;
  puVar1 = &uStack_30;
  if (param_1 != (int *)0x0) {
    local_18 = (int *)0x0;
    local_8 = 3;
    iVar2 = FUN_1000d460(this);
    FUN_1000bbf0(&local_18,iVar2);
    if (local_18 != (int *)0x0) {
      local_1c = (**(code **)(*local_18 + 0xc))(local_18,param_1);
      if (local_18 != (int *)0x0) {
        Ordinal_30(&local_18,0);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10005400((int *)&local_18);
    local_8 = 0;
    puVar1 = (uint *)local_14;
    if (param_1 != (int *)0x0) {
      Ordinal_30(&param_1,0);
      puVar1 = (uint *)local_14;
    }
  }
  local_14 = (undefined1 *)puVar1;
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return local_1c;
}



// Function: Catch@1000eb0c at 1000eb0c

undefined * Catch_1000eb0c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_1000eb22;
}



// Function: Catch@1000eb24 at 1000eb24

undefined4 Catch_1000eb24(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1000eacd;
}



// Function: FUN_1000eb40 at 1000eb40

void __fastcall FUN_1000eb40(int *param_1)

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



// Function: FUN_1000eb80 at 1000eb80

void __cdecl FUN_1000eb80(wchar_t *param_1,ushort param_2,int *param_3,char param_4)

{
  HMODULE hModule;
  HRSRC hResInfo;
  uint *puVar1;
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
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  FUN_1000dd40(param_1,param_2,&local_54,&local_58);
  if (param_4 != '\0') {
    hModule = LoadLibraryW(L"COMCTL32.DLL");
    if (hModule != (HMODULE)0x0) {
      hResInfo = FindResourceW(hModule,(LPCWSTR)0x3ee,(LPCWSTR)0x5);
      if (hResInfo != (HRSRC)0x0) {
        puVar1 = (uint *)LoadResource(hModule,hResInfo);
        if (puVar1 != (uint *)0x0) {
          iVar2 = FUN_1000e5c0(puVar1,local_48,(undefined2 *)&local_4c);
          FreeLibrary(hModule);
          if (iVar2 != 0) {
            FUN_1000dd40(local_48,(ushort)local_4c,&local_60,&local_4c);
            pcVar3 = MulDiv_exref;
            iVar2 = MulDiv(*param_3,local_54,4);
            *param_3 = iVar2;
            iVar2 = MulDiv(param_3[1],local_5c,8);
            param_3[1] = iVar2;
            goto LAB_1000ec68;
          }
        }
      }
    }
  }
  pcVar3 = MulDiv_exref;
  iVar2 = MulDiv(*param_3,local_54,4);
  *param_3 = iVar2;
  iVar2 = param_3[1];
  local_4c = 8;
  local_58 = local_50;
LAB_1000ec68:
  iVar2 = (*pcVar3)(iVar2,local_58,local_4c);
  param_3[1] = iVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ec80 at 1000ec80

void __thiscall FUN_1000ec80(void *this,UINT param_1)

{
  int iVar1;
  LPWSTR lpBuffer;
  int iVar2;
  int cchBufferMax;
  WCHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  iVar1 = LoadStringW(DAT_1003129c,param_1,local_208,0x100);
  if (iVar1 == 0) {
    local_208[0] = L'\0';
  }
  if (0x100 - iVar1 < 2) {
    iVar1 = 0x100;
    do {
      cchBufferMax = iVar1 + 0x100;
      lpBuffer = (LPWSTR)FUN_1000ced0(this,iVar1 + 0xff);
      if (lpBuffer == (LPWSTR)0x0) break;
      iVar2 = LoadStringW(DAT_1003129c,param_1,lpBuffer,cchBufferMax);
      if (iVar2 == 0) {
        *lpBuffer = L'\0';
      }
      iVar1 = cchBufferMax;
    } while (cchBufferMax - iVar2 < 2);
    FUN_1000cf60((int *)this);
                    /* WARNING: Load size is inaccurate */
    iVar1 = lstrlenW(*this);
                    /* WARNING: Load size is inaccurate */
    *(int *)(*this + -8) = iVar1;
                    /* WARNING: Load size is inaccurate */
    *(undefined2 *)(*this + iVar1 * 2) = 0;
  }
  else {
    iVar1 = lstrlenW(local_208);
    FUN_1000d900(this,iVar1,local_208);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000ed70 at 1000ed70

void __thiscall FUN_1000ed70(void *this,LPCWSTR param_1)

{
  uint uVar1;
  void **ppvVar2;
  uint uVar3;
  undefined2 *puVar4;
  LPCWSTR pWVar5;
  int iVar6;
  HWND hDlg;
  BOOL BVar7;
  LONG LVar8;
  int iVar9;
  LPCWSTR pWVar10;
  undefined4 local_38;
  int local_34;
  int local_30;
  LPCWSTR local_2c;
  undefined4 *local_18;
  LPCWSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b2c0;
  uVar3 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  iVar6 = *(int *)param_1;
  ppvVar2 = &local_10;
  local_18 = (undefined4 *)this;
  pWVar10 = param_1;
  local_10 = ExceptionList;
  do {
    ExceptionList = ppvVar2;
    if (iVar6 == 0) {
      ExceptionList = local_10;
      return;
    }
    local_14 = (LPCWSTR)0x0;
    local_8 = 1;
    iVar6 = *(int *)pWVar10;
    iVar9 = -0x7fffbffb;
    param_1 = (LPCWSTR)PTR_DAT_1002f6bc;
    if (((iVar6 == 0x1f5) || (iVar6 == 0x192)) || (iVar6 == 0x193)) {
LAB_1000ee26:
      iVar9 = 0;
    }
    else {
      uVar1 = *(uint *)(pWVar10 + 4);
      Ordinal_6(0,uVar3);
      local_14 = (LPCWSTR)0x0;
      puVar4 = (undefined2 *)FUN_1000b660(uVar1);
      if (puVar4 == (undefined2 *)0x0) {
        local_14 = (LPCWSTR)0x0;
      }
      else {
        pWVar5 = (LPCWSTR)Ordinal_4(puVar4 + 1,*puVar4);
        local_14 = pWVar5;
        if (pWVar5 != (LPCWSTR)0x0) {
          iVar6 = lstrlenW(pWVar5);
          FUN_1000d900(&param_1,iVar6,pWVar5);
          goto LAB_1000ee26;
        }
      }
    }
    hDlg = (HWND)*local_18;
    if (*(int *)pWVar10 == 100) {
LAB_1000ef74:
      SetWindowTextW(hDlg,param_1);
    }
    else {
      hDlg = GetDlgItem(hDlg,*(int *)(pWVar10 + 2));
      if (((-1 < iVar9) && (BVar7 = IsWindow((HWND)*local_18), BVar7 != 0)) &&
         (BVar7 = IsWindow(hDlg), BVar7 != 0)) {
        iVar6 = *(int *)pWVar10;
        if ((iVar6 == 200) || (iVar6 == 300)) {
          FUN_1000d6e0(&param_1,L"\\r\\n",L"\r\n");
          goto LAB_1000ef74;
        }
        if (iVar6 == 500) {
          local_30 = *(int *)(pWVar10 + 8);
          local_34 = *(int *)(pWVar10 + 10);
          local_38 = 7;
          local_2c = param_1;
          SendMessageW(hDlg,0x1061,*(WPARAM *)(pWVar10 + 6),(LPARAM)&local_38);
        }
        else if (iVar6 == 0x1f5) {
          SendMessageW(hDlg,0x101e,*(WPARAM *)(pWVar10 + 6),(uint)(ushort)pWVar10[8]);
        }
        else if (iVar6 == 400) {
          SendMessageW(hDlg,0x143,0,(LPARAM)param_1);
        }
        else if (iVar6 == 0x191) {
          SendMessageW(hDlg,0x14a,*(WPARAM *)(pWVar10 + 6),(LPARAM)param_1);
        }
        else if (iVar6 == 0x192) {
          SendMessageW(hDlg,0x14e,*(WPARAM *)(pWVar10 + 6),0);
        }
        else if (iVar6 == 0x193) {
          SendMessageW(hDlg,0x151,*(WPARAM *)(pWVar10 + 6),*(LPARAM *)(pWVar10 + 8));
        }
      }
    }
    pWVar10 = pWVar10 + 0xc;
    local_8 = local_8 & 0xffffff00;
    if (param_1 + -6 != (LPCWSTR)PTR_DAT_1002f6b8) {
      pWVar5 = param_1 + -6;
      LVar8 = InterlockedDecrement((LONG *)pWVar5);
      if (LVar8 < 1) {
        operator_delete__(pWVar5);
      }
    }
    local_8 = 0xffffffff;
    Ordinal_6(local_14);
    iVar6 = *(int *)pWVar10;
    ppvVar2 = (void **)ExceptionList;
  } while( true );
}



// Function: FUN_1000efe0 at 1000efe0

void __thiscall FUN_1000efe0(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0x14) = param_1;
  FUN_1000daf0((int)this);
  FUN_1000cfd0(this);
  FUN_1000c200((int)this);
  return;
}



// Function: FUN_1000f010 at 1000f010

void FUN_1000f010(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  LPCWSTR pWVar3;
  HDC hdc;
  HFONT pHVar4;
  HWND pHVar5;
  BOOL BVar6;
  int *piVar7;
  int iVar8;
  int nDenominator;
  undefined1 *local_2c;
  HFONT local_28;
  tagRECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b2f8;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar7 = *(int **)(param_1 + -0xb8);
  local_2c = &stack0xffffffc0;
  local_28 = (HFONT)&stack0xffffffc0;
  puVar1 = &stack0xffffffc0;
  pHVar4 = (HFONT)&stack0xffffffc0;
  if (piVar7 != (int *)0x0) {
    (**(code **)(*piVar7 + 4))(piVar7);
    puVar1 = local_2c;
    pHVar4 = local_28;
  }
  local_28 = pHVar4;
  local_2c = puVar1;
  local_8 = 0xffffffff;
  uVar2 = FUN_10017980(piVar7);
  *(undefined4 *)(param_1 + 0x70) = uVar2;
  local_2c = *(undefined1 **)(param_1 + -0x10c);
  pWVar3 = (LPCWSTR)(**(code **)(*(int *)(param_1 + -0x110) + 0x10))();
  FUN_1000ed70(&local_2c,pWVar3);
  FUN_10001070((void *)(param_1 + 0x34),*(undefined4 *)(param_1 + -0x10c));
  GetClientRect(*(HWND *)(param_1 + -0x10c),&local_24);
  FUN_10001040((void *)(param_1 + 0x34),local_24.left,local_24.top,local_24.right,local_24.bottom);
  local_28 = (HFONT)0x0;
  local_8 = 2;
  nDenominator = 0x48;
  iVar8 = 0x5a;
  hdc = GetDC((HWND)0x0);
  iVar8 = GetDeviceCaps(hdc,iVar8);
  iVar8 = MulDiv(0xc,iVar8,nDenominator);
  pWVar3 = DAT_1002fe40;
  if (DAT_1002fe54 < 8) {
    pWVar3 = (LPCWSTR)&DAT_1002fe40;
  }
  pHVar4 = CreateFontW(-iVar8,0,0,0,700,0,0,0,1,0,0,0,0,pWVar3);
  local_28 = pHVar4;
  pHVar5 = GetDlgItem(*(HWND *)(param_1 + -0x10c),0x3ea);
  SendMessageW(pHVar5,0x30,(WPARAM)pHVar4,1);
  pHVar5 = GetDlgItem(*(HWND *)(param_1 + -0x10c),0x3f0);
  *(HWND *)(param_1 + 0x20) = pHVar5;
  pHVar5 = GetDlgItem(*(HWND *)(param_1 + -0x10c),0x3f2);
  *(HWND *)(param_1 + 0x24) = pHVar5;
  pHVar5 = GetDlgItem(*(HWND *)(param_1 + -0x10c),0x3f4);
  *(HWND *)(param_1 + 0x28) = pHVar5;
  pHVar5 = GetDlgItem(*(HWND *)(param_1 + -0x10c),0x3ee);
  *(HWND *)(param_1 + 0x2c) = pHVar5;
  pHVar5 = GetDlgItem(*(HWND *)(param_1 + -0x10c),0x3ec);
  *(HWND *)(param_1 + 0x30) = pHVar5;
  if (*(int *)(param_1 + 0x70) == 3) {
    EnableWindow(*(HWND *)(param_1 + 0x28),0);
  }
  local_8 = 0xffffffff;
  if (pHVar4 != (HFONT)0x0) {
    BVar6 = DeleteObject(pHVar4);
    if (BVar6 != 0) {
      local_28 = (HFONT)0x0;
    }
  }
  ExceptionList = local_10;
  local_2c = (undefined1 *)0x1000f201;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f210 at 1000f210

int FUN_1000f210(LPCWSTR param_1,LPCWSTR param_2)

{
  LPCWSTR pWVar1;
  LPCWSTR lpString;
  uint uVar2;
  int iVar3;
  int local_18;
  LPCWSTR local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b388;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == (LPCWSTR)0x0) {
    local_14 = (LPCWSTR)0x0;
  }
  else {
    local_14 = param_1 + -0x16;
  }
  local_18 = 0;
  local_8 = 0;
  if (param_2 == (LPCWSTR)0x0) {
    param_1 = (LPCWSTR)0x0;
  }
  else {
    param_1 = (LPCWSTR)Ordinal_2(param_2,DAT_10030e10 ^ (uint)&stack0xfffffffc);
    if (param_1 == (LPCWSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x8007000e);
    }
  }
  pWVar1 = param_1;
  local_8._0_1_ = 1;
  lpString = (LPCWSTR)FUN_1000e950(*(uint *)(local_14 + 0x24));
  local_8._0_1_ = 4;
  param_2 = lpString;
  if (lpString == (LPCWSTR)0x0) {
    local_8._0_1_ = 1;
    CoTaskMemFree((LPVOID)0x0);
    param_2 = (LPCWSTR)0x0;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(pWVar1);
    ExceptionList = local_10;
    return -0x7ff8fff2;
  }
  uVar2 = lstrlenW(L"\\");
  iVar3 = FUN_1000bf10(&param_1,&DAT_10023774,uVar2);
  if (iVar3 < 0) {
    local_8._0_1_ = 1;
    CoTaskMemFree(lpString);
    param_2 = (LPCWSTR)0x0;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(param_1);
    ExceptionList = local_10;
    return iVar3;
  }
  uVar2 = lstrlenW(lpString);
  iVar3 = FUN_1000bf10(&param_1,lpString,uVar2);
  pWVar1 = param_1;
  if (iVar3 < 0) {
    local_8._0_1_ = 1;
    CoTaskMemFree(lpString);
    param_2 = (LPCWSTR)0x0;
    local_8 = (uint)local_8._1_3_ << 8;
    Ordinal_6(param_1);
    local_8 = 0xffffffff;
    FUN_10005140(&local_18);
    ExceptionList = local_10;
    return iVar3;
  }
  WinHelpW(*(HWND *)(local_14 + 2),param_1,8,0);
  local_8._0_1_ = 1;
  CoTaskMemFree(lpString);
  param_2 = (LPCWSTR)0x0;
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(pWVar1);
  local_8 = 0xffffffff;
  FUN_10005140(&local_18);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000f3d0 at 1000f3d0

/* WARNING: Removing unreachable block (ram,0x1000f43d) */
/* WARNING: Removing unreachable block (ram,0x1000f458) */

undefined4 __thiscall FUN_1000f3d0(void *this,int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b3f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (int *)0x0;
  local_8 = 1;
  if (param_1 == 0) {
    local_8 = 3;
    Ordinal_200(0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else if (param_1 != 0) {
    Ordinal_30(&local_14);
  }
  piVar2 = local_14;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 4))(local_14);
  }
  local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
  uVar1 = FUN_1000ea40(this,piVar2);
  local_8 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))();
  }
  ExceptionList = local_10;
  return uVar1;
}



// Function: FUN_1000f4c0 at 1000f4c0

int * __thiscall FUN_1000f4c0(void *this,uint param_1,char param_2)

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
    if (uVar1 == 0xffffffff) {
      std::_Xlength_error("string too long");
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_1000d590(this,uVar1);
      if (uVar1 == 0) {
        return (int *)this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        **this = 0;
        return (int *)this;
      }
      *(undefined1 *)this = 0;
      return (int *)this;
    }
    FUN_1000c850(this,*(int *)((int)this + 0x10),param_1,param_2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined1 *)(*this + uVar1) = 0;
      return (int *)this;
    }
    *(undefined1 *)((int)this + uVar1) = 0;
  }
  return (int *)this;
}



// Function: FUN_1000f570 at 1000f570

void __fastcall FUN_1000f570(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  BOOL BVar4;
  tagPOINT local_a4;
  tagPOINT local_9c;
  tagPOINT local_94;
  tagPOINT local_8c;
  tagPOINT local_84;
  tagPOINT local_7c;
  HDWP local_74;
  int *local_70;
  HWND local_6c;
  tagRECT local_68;
  tagRECT local_58;
  tagRECT local_48;
  tagRECT local_38;
  tagRECT local_28;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  iVar3 = __RTDynamicCast(param_1,0,
                          &CResizingDialog<class_CVehicleClassificationPageImpl>::
                           RTTI_Type_Descriptor,
                          &CVehicleClassificationPageImpl::RTTI_Type_Descriptor,0);
  local_6c = *(HWND *)(iVar3 + 4);
  local_48.left = 0;
  local_48.top = 0;
  local_48.right = 0;
  local_48.bottom = 0;
  GetClientRect(local_6c,&local_48);
  piVar1 = (int *)**(int **)(param_1 + 0x5c);
  local_70 = piVar1;
  local_74 = BeginDeferWindowPos(*(int *)(param_1 + 0x60));
  if (piVar1 != *(int **)(param_1 + 0x5c)) {
    do {
      puVar2 = (undefined4 *)local_70[2];
      if (puVar2 != (undefined4 *)0x0) {
        local_28.left = 0;
        local_28.top = 0;
        local_28.right = 0;
        local_28.bottom = 0;
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        BVar4 = GetWindowRect((HWND)*puVar2,&local_28);
        if (BVar4 != 0) {
          local_8c.y = local_28.top;
          local_94.x = local_28.left;
          local_8c.x = local_28.right;
          local_94.y = local_28.bottom;
          ScreenToClient((HWND)*puVar2,&local_8c);
          ScreenToClient((HWND)*puVar2,&local_94);
          local_28.top = local_8c.y;
          local_28.left = local_94.x;
          local_28.right = local_8c.x;
          local_28.bottom = local_94.y;
          local_68.left = 0;
          local_68.top = 0;
          local_68.right = 0;
          local_68.bottom = 0;
          GetWindowRect(local_6c,&local_68);
          if ((HWND)puVar2[0xb] == (HWND)0x0) {
            local_18.left = ((local_48.right - local_48.left) * puVar2[3]) / 100 + puVar2[5];
            local_18.top = ((local_48.bottom - local_48.top) * puVar2[4]) / 100 + puVar2[6];
          }
          else {
            local_38.left = 0;
            local_38.top = 0;
            local_38.right = 0;
            local_38.bottom = 0;
            GetWindowRect((HWND)puVar2[0xb],&local_38);
            local_84.y = local_38.top;
            local_7c.x = local_38.right;
            local_84.x = local_38.left;
            local_7c.y = local_38.bottom;
            ScreenToClient(local_6c,&local_84);
            ScreenToClient(local_6c,&local_7c);
            local_38.right = local_7c.x;
            local_18.left = puVar2[5];
            local_38.top = local_84.y;
            local_38.bottom = local_7c.y;
            local_18.top = local_7c.y;
            local_38.left = local_84.x;
          }
          if ((HWND)puVar2[0xc] == (HWND)0x0) {
            local_18.right = ((local_48.right - local_48.left) * puVar2[7]) / 100 + puVar2[9];
            local_18.bottom = ((local_48.bottom - local_48.top) * puVar2[8]) / 100 + puVar2[10];
          }
          else {
            local_58.left = 0;
            local_58.top = 0;
            local_58.right = 0;
            local_58.bottom = 0;
            GetWindowRect((HWND)puVar2[0xc],&local_58);
            local_a4.y = local_58.top;
            local_9c.x = local_58.right;
            local_a4.x = local_58.left;
            local_9c.y = local_58.bottom;
            ScreenToClient(local_6c,&local_a4);
            ScreenToClient(local_6c,&local_9c);
            local_58.left = local_a4.x;
            local_58.top = local_a4.y;
            local_58.right = local_9c.x;
            local_58.bottom = local_9c.y;
            local_18.right = local_9c.x;
            local_18.bottom = local_a4.y;
          }
          BVar4 = EqualRect(&local_18,&local_28);
          if (BVar4 == 0) {
            iVar3 = puVar2[1];
            if (iVar3 != 0) {
              MoveWindow((HWND)*puVar2,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar2,&local_18,1);
              UpdateWindow(local_6c);
            }
            if (puVar2[2] == 0) {
              if (iVar3 == 0) {
                DeferWindowPos(local_74,(HWND)*puVar2,(HWND)0x0,local_18.left,local_18.top,
                               local_18.right - local_18.left,local_18.bottom - local_18.top,0x14);
              }
            }
            else {
              MoveWindow((HWND)*puVar2,local_18.left,local_18.top,local_18.right - local_18.left,
                         local_18.bottom - local_18.top,0);
              InvalidateRect((HWND)*puVar2,&local_18,1);
              UpdateWindow(local_6c);
            }
          }
        }
      }
      local_70 = (int *)*local_70;
    } while (local_70 != (int *)*(int *)(param_1 + 0x5c));
  }
  EndDeferWindowPos(local_74);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000f920 at 1000f920

void __thiscall FUN_1000f920(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
                    /* WARNING: Load size is inaccurate */
  if ((param_2 == (int *)**this) && (param_3 == *this)) {
    FUN_1000eb40((int *)this);
                    /* WARNING: Load size is inaccurate */
    *param_1 = *this;
    return;
  }
  if (param_2 != param_3) {
    do {
      piVar1 = (int *)*param_2;
                    /* WARNING: Load size is inaccurate */
      if (param_2 != *this) {
        *(int **)param_2[1] = piVar1;
        *(int *)(*param_2 + 4) = param_2[1];
        operator_delete(param_2);
        *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
      }
      param_2 = piVar1;
    } while (piVar1 != param_3);
  }
  *param_1 = (int)param_3;
  return;
}



// Function: FUN_1000f990 at 1000f990

void __cdecl FUN_1000f990(uint *param_1,int *param_2,char param_3)

{
  short sVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  undefined4 local_4c;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_4c = 0;
  if (*(short *)((int)param_1 + 2) == -1) {
    *param_2 = (int)*(short *)((int)param_1 + 0x16);
    sVar1 = (short)param_1[6];
  }
  else {
    *param_2 = (int)*(short *)((int)param_1 + 0xe);
    sVar1 = (short)param_1[4];
  }
  param_2[1] = (int)sVar1;
  iVar2 = FUN_1000e5c0(param_1,local_48,(undefined2 *)&local_4c);
  if (iVar2 == 0) {
    uVar4 = 0;
    pwVar3 = (wchar_t *)0x0;
  }
  else {
    pwVar3 = local_48;
    uVar4 = local_4c;
  }
  FUN_1000eb80(pwVar3,(ushort)uVar4,param_2,param_3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fa20 at 1000fa20

undefined4 * __thiscall FUN_1000fa20(void *this,LPCWSTR param_1)

{
  uint _Size;
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_1002f6bc;
  if (param_1 != (LPCWSTR)0x0) {
    if ((uint)param_1 >> 0x10 == 0) {
      FUN_1000ec80(this,(uint)param_1 & 0xffff);
      return (undefined4 *)this;
    }
    iVar1 = lstrlenW(param_1);
    if (((iVar1 != 0) && (iVar2 = FUN_1000c140(this,iVar1), iVar2 != 0)) &&
       (_Size = iVar1 * 2, _Size <= _Size + 2)) {
                    /* WARNING: Load size is inaccurate */
      memcpy(*this,param_1,_Size);
    }
  }
  return (undefined4 *)this;
}



// Function: FUN_1000fa90 at 1000fa90

void __fastcall FUN_1000fa90(int *param_1)

{
  wchar_t *pwVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  LPCWSTR lpLibFileName;
  HMODULE hLibModule;
  errno_t eVar5;
  int iVar6;
  undefined2 *puVar7;
  wchar_t *pwVar8;
  LPCWSTR **lpString;
  uint local_60;
  uint local_5c;
  int local_4c;
  uint local_44;
  wchar_t *local_40;
  int *local_3c;
  char local_35;
  wchar_t *local_34;
  LPCWSTR *local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b430;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pwVar8 = (wchar_t *)0x0;
  local_35 = '\0';
  local_34 = (wchar_t *)0x0;
  local_8 = 0;
  local_3c = param_1;
  local_14 = uVar2;
  FUN_1000b750(param_1,&local_60,param_1[5]);
  if (local_5c == 0) {
    if (local_44 != 0) {
      FUN_1000c0c0(&local_34,local_44);
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (LPCWSTR *)((uint)local_30[0] & 0xffff0000);
      local_8 = CONCAT31(local_8._1_3_,1);
      (**(code **)(*param_1 + 8))(local_30);
      uVar3 = lstrlenW(L"_");
      FUN_1000bf10(&local_34,&DAT_10023890,uVar3);
      if (local_20 == 0) {
        FUN_10002d40(local_30,(int *)&DAT_10023888,2);
      }
      lpString = (LPCWSTR **)local_30[0];
      if (local_1c < 8) {
        lpString = local_30;
      }
      uVar3 = lstrlenW((LPCWSTR)lpString);
      FUN_1000bf10(&local_34,lpString,uVar3);
      uVar3 = lstrlenW(L".dll");
      FUN_1000bf10(&local_34,L".dll",uVar3);
      pwVar8 = local_34;
      piVar4 = FUN_10005730(&local_40,(int)local_34);
      local_8._0_1_ = 2;
      if ((undefined4 *)*piVar4 == (undefined4 *)0x0) {
        lpLibFileName = (LPCWSTR)0x0;
      }
      else {
        lpLibFileName = *(LPCWSTR *)*piVar4;
      }
      hLibModule = LoadLibraryW(lpLibFileName);
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_10008070(&local_40);
      if (hLibModule != (HMODULE)0x0) {
        local_35 = FUN_1000c040(&local_34,hLibModule,local_3c[5] - local_4c);
        FreeLibrary(hLibModule);
        pwVar8 = local_34;
      }
      local_8 = local_8 & 0xffffff00;
      if (7 < local_1c) {
        operator_delete(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (LPCWSTR *)((uint)local_30[0] & 0xffff0000);
      param_1 = local_3c;
      pwVar1 = local_34;
      if (local_35 != '\0') goto LAB_1000fd19;
    }
    local_40 = (wchar_t *)operator_new__(0x40);
    if (pwVar8 != 
        L"<ErrorInfo><Description>No description has been defined or could be loaded for error identifier "
       ) {
      Ordinal_6(pwVar8,uVar2);
      local_34 = (wchar_t *)
                 Ordinal_2(
                          L"<ErrorInfo><Description>No description has been defined or could be loaded for error identifier "
                          );
      if (local_34 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_10001690(0x8007000e);
      }
    }
    if (local_40 != (wchar_t *)0x0) {
      eVar5 = _ltow_s(param_1[5],local_40,0x20,10);
      if (eVar5 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_10001690(0x80070057);
      }
      if (eVar5 == 0) {
        local_3c = (int *)0x0;
      }
      else {
        local_3c = (int *)Ordinal_4(0,eVar5);
        if (local_3c == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_10001690(0x8007000e);
        }
      }
      piVar4 = local_3c;
      local_8._0_1_ = 3;
      FUN_1000b6d0(&local_34,&local_3c);
      local_8 = (uint)local_8._1_3_ << 8;
      Ordinal_6(piVar4);
    }
    uVar2 = lstrlenW(L".");
    iVar6 = FUN_1000bf10(&local_34,&DAT_100237b0,uVar2);
    if (iVar6 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(iVar6);
    }
    uVar2 = lstrlenW(L"</Description></ErrorInfo>");
    iVar6 = FUN_1000bf10(&local_34,L"</Description></ErrorInfo>",uVar2);
    if (iVar6 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(iVar6);
    }
    operator_delete__(local_40);
    pwVar8 = local_34;
    pwVar1 = local_34;
  }
  else {
    Ordinal_6(0,uVar2);
    local_34 = (wchar_t *)0x0;
    puVar7 = (undefined2 *)FUN_1000b660(local_5c);
    pwVar1 = pwVar8;
    if (puVar7 != (undefined2 *)0x0) {
      pwVar8 = (wchar_t *)Ordinal_4(puVar7 + 1,*puVar7);
      pwVar1 = pwVar8;
    }
  }
LAB_1000fd19:
  local_34 = pwVar1;
  (**(code **)(*(int *)param_1[4] + 0x14))((int *)param_1[4],pwVar8);
  local_8 = 0xffffffff;
  Ordinal_6(pwVar8);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1000fd50 at 1000fd50

undefined4 FUN_1000fd50(int param_1,LPCWSTR param_2)

{
  LONG LVar1;
  LPCWSTR pWVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b468;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000fa20(&param_2,param_2);
  local_8 = 0;
  FUN_1000d6e0(&param_2,L"\\r\\n",L"\r\n");
  pWVar2 = param_2;
  SetWindowTextW(*(HWND *)(param_1 + 0x30),param_2);
  local_8 = 0xffffffff;
  if (pWVar2 + -6 != (LPCWSTR)PTR_DAT_1002f6b8) {
    pWVar2 = pWVar2 + -6;
    LVar1 = InterlockedDecrement((LONG *)pWVar2);
    if (LVar1 < 1) {
      operator_delete__(pWVar2);
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000fdf0 at 1000fdf0

undefined4 FUN_1000fdf0(int param_1,LPCWSTR param_2,LPCWSTR param_3,uint param_4,int *param_5)

{
  undefined2 *puVar1;
  LPCWSTR lpCaption;
  int iVar2;
  LONG LVar3;
  uint uType;
  LPCWSTR pWVar4;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b4a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  Ordinal_6(0,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  puVar1 = (undefined2 *)FUN_1000b660(0x96);
  if (puVar1 == (undefined2 *)0x0) {
    lpCaption = (LPCWSTR)0x0;
  }
  else {
    lpCaption = (LPCWSTR)Ordinal_4(puVar1 + 1,*puVar1);
  }
  uType = (uint)param_3 | param_4;
  FUN_1000fa20(&param_3,param_2);
  local_8._0_1_ = 1;
  FUN_1000d6e0(&param_3,L"\\r\\n",L"\r\n");
  pWVar4 = param_3;
  iVar2 = MessageBoxW(*(HWND *)(param_1 + -0x10c),param_3,lpCaption,uType);
  *param_5 = iVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  if (pWVar4 + -6 != (LPCWSTR)PTR_DAT_1002f6b8) {
    pWVar4 = pWVar4 + -6;
    LVar3 = InterlockedDecrement((LONG *)pWVar4);
    if (LVar3 < 1) {
      operator_delete__(pWVar4);
    }
  }
  local_8 = 0xffffffff;
  Ordinal_6(lpCaption);
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000fee0 at 1000fee0

undefined4 FUN_1000fee0(int param_1,LPCWSTR param_2,LPCWSTR param_3,uint param_4,uint param_5)

{
  LONG LVar1;
  LPCWSTR pWVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b4c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1000fa20(&param_3,param_3);
  local_8 = 0;
  FUN_1000d6e0(&param_3,L"\\r\\n",L"\r\n");
  pWVar2 = param_3;
  MessageBoxW(*(HWND *)(param_1 + -0x10c),param_3,param_2,param_4 | param_5);
  local_8 = 0xffffffff;
  if (pWVar2 + -6 != (LPCWSTR)PTR_DAT_1002f6b8) {
    pWVar2 = pWVar2 + -6;
    LVar1 = InterlockedDecrement((LONG *)pWVar2);
    if (LVar1 < 1) {
      operator_delete__(pWVar2);
    }
  }
  ExceptionList = local_10;
  return 0;
}



// Function: FUN_1000ff90 at 1000ff90

void FUN_1000ff90(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  LPARAM *pLVar3;
  int iVar4;
  LONG LVar5;
  int iVar6;
  undefined **local_2c [3];
  LPARAM *local_20;
  char *local_1c;
  LPARAM *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b514;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  SendMessageW((HWND)*param_1,0x14b,0,0);
  SendMessageW((HWND)*param_1,0x303,0,0);
  iVar6 = 0;
  if (0 < *(int *)(param_2[4] + 0x10)) {
    if (*(int *)(param_2[4] + 0x10) < 1) {
      local_1c = "index is out of range";
      std::exception::exception((exception *)local_2c,&local_1c);
      local_2c[0] = std::out_of_range::vftable;
      local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_2c,(ThrowInfo *)&DAT_10027fd4);
    }
    do {
      local_14 = iVar6;
      iVar2 = (**(code **)(*param_2 + 4))(&local_14,uVar1);
      pLVar3 = (LPARAM *)operator_new(0xc);
      local_8 = 2;
      local_20 = pLVar3;
      if (pLVar3 == (LPARAM *)0x0) goto LAB_1001004b;
      pLVar3[1] = 0;
      pLVar3[2] = 1;
      iVar4 = Ordinal_2(iVar2);
      *pLVar3 = iVar4;
      if (iVar4 != 0) goto LAB_1001004d;
      if (iVar2 == 0) goto LAB_1001004d;
      do {
        FUN_10018b30(0x8007000e);
LAB_1001004b:
        pLVar3 = (LPARAM *)0x0;
LAB_1001004d:
        local_8 = 0xffffffff;
        local_18 = pLVar3;
      } while (pLVar3 == (LPARAM *)0x0);
      local_8 = 3;
      SendMessageW((HWND)*param_1,0x143,0,*pLVar3);
      local_8 = 0xffffffff;
      LVar5 = InterlockedDecrement(pLVar3 + 2);
      if (LVar5 == 0) {
        if (*pLVar3 != 0) {
          Ordinal_6(*pLVar3);
        }
        if ((void *)pLVar3[1] != (void *)0x0) {
          operator_delete__((void *)pLVar3[1]);
        }
        operator_delete(pLVar3);
      }
      iVar6 = iVar6 + 1;
      local_18 = (LPARAM *)0x0;
    } while (iVar6 < *(int *)(param_2[4] + 0x10));
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10010130 at 10010130

void __fastcall FUN_10010130(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  int iVar1;
  char *****pppppcVar2;
  char *pcVar3;
  wchar_t *local_3c;
  char *local_38;
  wchar_t local_34;
  wchar_t local_32;
  char ****local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b538;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((**(int **)(param_1 + 0x20) == 0) ||
     (**(uint **)(param_1 + 0x20) + **(int **)(param_1 + 0x30) * 2 <= **(uint **)(param_1 + 0x20)))
  {
    if (*(int *)(param_1 + 0x54) != 0) {
      if ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)**(int **)(param_1 + 0x10)
          == param_1 + 0x48) {
        std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                  (param_1,*(wchar_t **)(param_1 + 0x3c),*(wchar_t **)(param_1 + 0x40),
                   *(wchar_t **)(param_1 + 0x40));
      }
      if (*(int *)(param_1 + 0x44) == 0) {
        fgetwc(*(FILE **)(param_1 + 0x54));
      }
      else {
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (char ****)((uint)local_30[0] & 0xffffff00);
        local_8 = 0;
        iVar1 = fgetc(*(FILE **)(param_1 + 0x54));
        if (iVar1 != -1) {
          do {
            FUN_1000f4c0(local_30,1,(char)iVar1);
            pppppcVar2 = (char *****)local_30[0];
            if (local_1c < 0x10) {
              pppppcVar2 = local_30;
            }
            iVar1 = std::codecvt<wchar_t,char,int>::in
                              (*(codecvt<wchar_t,char,int> **)(param_1 + 0x44),
                               (int *)(param_1 + 0x4c),(char *)pppppcVar2,
                               (char *)((int)pppppcVar2 + local_20),&local_38,&local_34,&local_32,
                               &local_3c);
            if (iVar1 < 0) break;
            if (iVar1 < 2) {
              if (local_3c != &local_34) {
                pppppcVar2 = (char *****)local_30[0];
                if (local_1c < 0x10) {
                  pppppcVar2 = local_30;
                }
                for (pcVar3 = (char *)((int)pppppcVar2 + (local_20 - (int)local_38));
                    0 < (int)pcVar3; pcVar3 = pcVar3 + -1) {
                  ungetc((int)local_38[(int)(pcVar3 + -1)],*(FILE **)(param_1 + 0x54));
                }
LAB_10010311:
                local_8 = 0xffffffff;
                FUN_1000dc40(local_30);
                goto LAB_100102c2;
              }
              pppppcVar2 = (char *****)local_30[0];
              if (local_1c < 0x10) {
                pppppcVar2 = local_30;
              }
              FUN_1000d3d0(local_30,0,(int)local_38 - (int)pppppcVar2);
            }
            else {
              if (iVar1 != 3) break;
              if (1 < local_20) {
                pppppcVar2 = (char *****)local_30[0];
                if (local_1c < 0x10) {
                  pppppcVar2 = local_30;
                }
                memcpy_s(&local_34,2,pppppcVar2,2);
                goto LAB_10010311;
              }
            }
            iVar1 = fgetc(*(FILE **)(param_1 + 0x54));
          } while (iVar1 != -1);
        }
        local_8 = 0xffffffff;
        FUN_1000dc40(local_30);
      }
    }
  }
  else {
    std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Gninc(param_1);
  }
LAB_100102c2:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010330 at 10010330

undefined4 FUN_10010330(int param_1,undefined4 *param_2)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  uint *puVar1;
  LPVOID pvVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1 + -0x2c;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  hResInfo = FindResourceW(DAT_1003129c,(LPCWSTR)0x65,(LPCWSTR)0x5);
  if (hResInfo != (HRSRC)0x0) {
    hResData = LoadResource(DAT_1003129c,hResInfo);
    if (hResData != (HGLOBAL)0x0) {
      puVar1 = (uint *)LockResource(hResData);
      if (puVar1 != (uint *)0x0) {
        FUN_1000f990(puVar1,(int *)(param_1 + 0x10),'\x01');
        *param_2 = 0x1c;
        pvVar2 = FUN_1000e950(*(uint *)(iVar3 + 0x44));
        param_2[1] = pvVar2;
        param_2[2] = *(int *)(param_1 + 0x10);
        param_2[3] = *(undefined4 *)(param_1 + 0x14);
        pvVar2 = FUN_1000e950(*(uint *)(iVar3 + 0x48));
        param_2[5] = pvVar2;
        pvVar2 = FUN_1000e950(*(uint *)(iVar3 + 0x4c));
        param_2[4] = pvVar2;
        param_2[6] = *(undefined4 *)(iVar3 + 0x50);
        return 0;
      }
    }
  }
  return 0x8000ffff;
}



// Function: FUN_10010400 at 10010400

void __fastcall FUN_10010400(int *param_1)

{
  short sVar1;
  int iVar2;
  char ****ppppcVar3;
  size_t sVar4;
  size_t _Count;
  char *local_34;
  char ***local_30;
  undefined4 local_2c;
  undefined1 local_28;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b568;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((param_1[0x11] != 0) && (*(char *)((int)param_1 + 0x4a) != '\0')) &&
     (sVar1 = (**(code **)(*param_1 + 0xc))(0xffff,local_14), sVar1 != -1)) {
    local_1c = 0xf;
    local_30 = (char ***)0x0;
    local_2c = 0;
    local_20 = 8;
    local_28 = 0;
    local_8 = 0;
    while( true ) {
      ppppcVar3 = (char ****)local_30;
      if (local_1c < 0x10) {
        ppppcVar3 = &local_30;
      }
      iVar2 = std::codecvt<wchar_t,char,int>::unshift
                        ((codecvt<wchar_t,char,int> *)param_1[0x11],param_1 + 0x13,(char *)ppppcVar3
                         ,(char *)((int)ppppcVar3 + local_20),&local_34);
      if (iVar2 != 0) break;
      *(undefined1 *)((int)param_1 + 0x4a) = 0;
LAB_100104cf:
      ppppcVar3 = (char ****)local_30;
      if (local_1c < 0x10) {
        ppppcVar3 = &local_30;
      }
      _Count = (int)local_34 - (int)ppppcVar3;
      if (_Count != 0) {
        ppppcVar3 = (char ****)local_30;
        if (local_1c < 0x10) {
          ppppcVar3 = &local_30;
        }
        sVar4 = fwrite(ppppcVar3,1,_Count,(FILE *)param_1[0x15]);
        if (_Count != sVar4) goto LAB_100104b9;
      }
      if (*(char *)((int)param_1 + 0x4a) == '\0') goto LAB_10010526;
      if (_Count == 0) {
        FUN_1000f4c0(&local_30,8,'\0');
      }
    }
    if (iVar2 == 1) goto LAB_100104cf;
    if (iVar2 != 3) {
LAB_100104b9:
      local_8 = 0xffffffff;
      FUN_1000dc40(&local_30);
      goto LAB_10010537;
    }
LAB_10010526:
    local_8 = 0xffffffff;
    FUN_1000dc40(&local_30);
  }
LAB_10010537:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010560 at 10010560

void __thiscall
FUN_10010560(void *this,undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  HWND hWnd;
  int iVar1;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  iVar1 = __RTDynamicCast(this,0,&CResizingDialog<class_CVehicleClassificationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CVehicleClassificationPageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar1 + 4);
  if ((param_2 != 4) && (param_2 != 3)) {
    if (*(int *)((int)this + 0x18) != 0) {
      FUN_1000bec0((int)this);
      InvalidateRect(hWnd,(RECT *)((int)this + 0x44),1);
      *(undefined4 *)((int)this + 0x20) = 1;
    }
    FUN_1000f570((int)this);
    FUN_1000f570((int)this);
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0x6c;
  }
  GetWindowRect(*(HWND *)(iVar1 + 4),&local_18);
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0x6c;
  }
  InvalidateRect(*(HWND *)(iVar1 + 4),&local_18,1);
  if (this == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)this + -0x6c;
  }
  UpdateWindow(*(HWND *)(iVar1 + 4));
  *param_4 = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10010640 at 10010640

void __fastcall FUN_10010640(int *param_1)

{
  int *piVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b598;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
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
  local_8 = 0xffffffff;
  operator_delete((void *)*param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100106c0 at 100106c0

void __thiscall FUN_100106c0(void *this,void *param_1)

{
  int *piVar1;
  uint uStack_84;
  int *local_74;
  int local_70;
  undefined4 local_6c [7];
  ushort local_50 [14];
  ushort local_34 [14];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b5f8;
  local_10 = ExceptionList;
  uStack_84 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_84;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_84;
  __RTDynamicCast(this,0,&CContextSensitiveHelpProvider<class_CVehicleClassificationPageImpl>::
                          RTTI_Type_Descriptor,&CVehicleClassificationPageImpl::RTTI_Type_Descriptor
                  ,0);
  FUN_1000cca0(&local_74,(GUID *)&DAT_10024ca8);
  local_8._0_1_ = 1;
  FUN_10017be0((undefined2 *)local_6c,local_74);
  local_8._0_1_ = 2;
  FUN_10002f70(local_34,(int *)&PTR_10022cc0);
  local_8._0_1_ = 3;
  FUN_10002f70(local_50,(int *)&DAT_10023898);
  local_8._0_1_ = 4;
  FUN_10017b20(local_6c,local_50,(undefined4 *)local_34);
  local_8._0_1_ = 3;
  FUN_10002570((undefined4 *)local_50);
  local_8._0_1_ = 2;
  FUN_10002570((undefined4 *)local_34);
  FUN_10002f70(local_50,(int *)&PTR_10022cc0);
  local_8._0_1_ = 5;
  FUN_10002f70(local_34,(int *)&DAT_10023894);
  local_8._0_1_ = 6;
  FUN_10017b20(local_6c,local_34,(undefined4 *)local_50);
  local_8._0_1_ = 5;
  FUN_10002570((undefined4 *)local_34);
  local_8._0_1_ = 2;
  FUN_10002570((undefined4 *)local_50);
  piVar1 = FUN_10017aa0(&local_70,local_6c);
  local_8._0_1_ = 7;
  FUN_10004b00(param_1,piVar1);
  local_8._0_1_ = 2;
  Ordinal_6(local_70);
  local_8._0_1_ = 1;
  FUN_10002570(local_6c);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(local_74);
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: Catch@10010836 at 10010836

undefined4 Catch_10010836(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10010816;
}



// Function: FUN_10010850 at 10010850

undefined4 * __thiscall
FUN_10010850(void *this,int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b62b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = CComErrorHandlerException::vftable;
  *(undefined4 *)((int)this + 0x24) = 7;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined2 *)((int)this + 0x10) = 0;
  local_8 = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = param_2;
  *(uint *)((int)this + 4) = -(uint)(param_1 != 0) & 0x80004005;
  piVar2 = param_3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10002d40((undefined2 *)((int)this + 0x10),param_3,(int)piVar2 - ((int)param_3 + 2) >> 1);
  *(undefined4 *)((int)this + 0x2c) = param_4;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10010900 at 10010900

undefined4 FUN_10010900(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined **local_30 [2];
  undefined2 local_28 [4];
  int local_20;
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b678;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_30[0] = safearray<wchar_t*,8>::vftable;
  Ordinal_8(local_28,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  local_18[0] = 0;
  if (param_2 != 0) {
    local_28[0] = 0x2008;
    local_20 = param_2;
    Ordinal_23(param_2,local_18);
    local_30[0] = bstrarrayT<wchar_t*>::vftable;
    local_8 = 2;
    FUN_1000ff90((undefined4 *)(param_1 + 0x20),(int *)local_30);
    local_30[0] = safearray<wchar_t*,8>::vftable;
    local_8 = 0xffffffff;
    Ordinal_9(local_28);
    ExceptionList = local_10;
    return 0;
  }
  FUN_10018b30(0x80004003);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_100109c0 at 100109c0

undefined4 FUN_100109c0(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined **local_30 [2];
  undefined2 local_28 [4];
  int local_20;
  undefined4 local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b678;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_30[0] = safearray<wchar_t*,8>::vftable;
  Ordinal_8(local_28,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  local_18[0] = 0;
  if (param_2 != 0) {
    local_28[0] = 0x2008;
    local_20 = param_2;
    Ordinal_23(param_2,local_18);
    local_30[0] = bstrarrayT<wchar_t*>::vftable;
    local_8 = 2;
    FUN_1000ff90((undefined4 *)(param_1 + 0x24),(int *)local_30);
    local_30[0] = safearray<wchar_t*,8>::vftable;
    local_8 = 0xffffffff;
    Ordinal_9(local_28);
    ExceptionList = local_10;
    return 0;
  }
  FUN_10018b30(0x80004003);
  pcVar1 = (code *)swi(3);
  uVar2 = (*pcVar1)();
  return uVar2;
}



// Function: FUN_10010a80 at 10010a80

void __thiscall FUN_10010a80(void *this,wchar_t param_1)

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
  char ***local_30;
  undefined4 local_2c;
  undefined1 local_28;
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b538;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != L'\xffff') {
    uVar1 = **(uint **)((int)this + 0x24);
    if ((uVar1 == 0) || (uVar1 + **(int **)((int)this + 0x34) * 2 <= uVar1)) {
      if (*(int *)((int)this + 0x54) != 0) {
        if (**(int **)((int)this + 0x10) == (int)this + 0x48) {
          std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::setg
                    ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this,
                     *(wchar_t **)((int)this + 0x3c),*(wchar_t **)((int)this + 0x40),
                     *(wchar_t **)((int)this + 0x40));
        }
        if (*(int *)((int)this + 0x44) != 0) {
          local_1c = 0xf;
          local_34 = (uint)(ushort)param_1;
          local_30 = (char ***)0x0;
          local_2c = 0;
          local_20 = 8;
          local_28 = 0;
          local_8 = 0;
LAB_10010b7b:
          ppppcVar4 = (char ****)local_30;
          if (local_1c < 0x10) {
            ppppcVar4 = &local_30;
          }
          iVar3 = std::codecvt<wchar_t,char,int>::out
                            (*(codecvt<wchar_t,char,int> **)((int)this + 0x44),
                             (int *)((int)this + 0x4c),(wchar_t *)&local_34,
                             (wchar_t *)((int)&local_34 + 2),&local_3c,(char *)ppppcVar4,
                             (char *)((int)ppppcVar4 + local_20),&local_38);
          if (iVar3 < 0) goto LAB_10010c6b;
          if (iVar3 < 2) {
            ppppcVar4 = (char ****)local_30;
            if (local_1c < 0x10) {
              ppppcVar4 = &local_30;
            }
            _Count = (int)local_38 - (int)ppppcVar4;
            if (_Count != 0) {
              ppppcVar4 = (char ****)local_30;
              if (local_1c < 0x10) {
                ppppcVar4 = &local_30;
              }
              sVar5 = fwrite(ppppcVar4,1,_Count,*(FILE **)((int)this + 0x54));
              if (_Count != sVar5) goto LAB_10010c6b;
            }
            *(undefined1 *)((int)this + 0x4a) = 1;
            if (local_3c == (wchar_t *)&local_34) goto code_r0x10010bfd;
            local_8 = 0xffffffff;
            FUN_1000dc40(&local_30);
          }
          else {
            if (iVar3 != 3) goto LAB_10010c6b;
            FUN_1000c4d0((wchar_t)local_34,*(FILE **)((int)this + 0x54));
            local_8 = 0xffffffff;
            FUN_1000dc40(&local_30);
          }
          goto LAB_10010c7f;
        }
        fputwc(param_1,*(FILE **)((int)this + 0x54));
      }
    }
    else {
      pwVar2 = std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Pninc
                         ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
      *pwVar2 = param_1;
    }
  }
LAB_10010c7f:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
code_r0x10010bfd:
  if (_Count == 0) {
    if (0x1f < local_20) {
LAB_10010c6b:
      local_8 = 0xffffffff;
      FUN_1000dc40(&local_30);
      goto LAB_10010c7f;
    }
    FUN_1000f4c0(&local_30,8,'\0');
  }
  goto LAB_10010b7b;
}



// Function: FUN_10010ca0 at 10010ca0

void __thiscall FUN_10010ca0(void *this,undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int unaff_EDI;
  
  uVar4 = param_2;
  iVar3 = param_3;
  if (((**(int **)((int)this + 0x20) == (int)this + 0x48) && (param_4 == 1)) &&
     (*(int *)((int)this + 0x44) == 0)) {
    uVar4 = param_2 - 2;
    iVar3 = param_3 + -1 + (uint)(1 < param_2);
  }
  if ((((*(int *)((int)this + 0x54) != 0) && (cVar2 = FUN_10010400((int *)this), cVar2 != '\0')) &&
      (((uVar4 == 0 && iVar3 == 0 && (param_4 == 1)) ||
       (iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(param_4,iVar3),unaff_EDI),
       iVar3 == 0)))) &&
     (iVar3 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&param_2), iVar3 == 0)) {
    Reset_back((int)this);
    param_1[2] = param_2;
    uVar1 = *(undefined4 *)((int)this + 0x4c);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = param_3;
    param_1[4] = uVar1;
    return;
  }
  uVar1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = *(undefined4 *)(_BADOFF_exref + 4);
  *param_1 = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// Function: FUN_10010d70 at 10010d70

void __thiscall
FUN_10010d70(void *this,undefined4 *param_1,int param_2,int param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_4;
  local_8 = param_5;
  if ((((*(int *)((int)this + 0x54) != 0) && (cVar2 = FUN_10010400((int *)this), cVar2 != '\0')) &&
      (iVar3 = fsetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c), iVar3 == 0)) &&
     (((param_2 == 0 && param_3 == 0 ||
       (iVar3 = _fseeki64(*(FILE **)((int)this + 0x54),CONCAT44(1,param_3),unaff_EDI), iVar3 == 0))
      && (iVar3 = fgetpos(*(FILE **)((int)this + 0x54),(fpos_t *)&local_c), iVar3 == 0)))) {
    *(int *)((int)this + 0x4c) = param_6;
    Reset_back((int)this);
    param_1[2] = local_c;
    uVar1 = *(undefined4 *)((int)this + 0x4c);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[4] = uVar1;
    param_1[3] = local_8;
    return;
  }
  uVar1 = *(undefined4 *)(_BADOFF_exref + 4);
  *param_1 = *(undefined4 *)_BADOFF_exref;
  param_1[1] = uVar1;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}



// Function: FUN_10010e50 at 10010e50

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __fastcall
FUN_10010e50(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    cVar2 = FUN_10010400((int *)param_1);
    pbVar4 = param_1;
    if (cVar2 == '\0') {
      pbVar4 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
    }
    iVar3 = fclose(*(FILE **)(param_1 + 0x54));
    if (iVar3 == 0) goto LAB_10010e7c;
  }
  pbVar4 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0;
LAB_10010e7c:
  param_1[0x50] = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0;
  param_1[0x4a] = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init(param_1);
  *(undefined4 *)(param_1 + 0x54) = 0;
  uVar1 = DAT_10030ea8;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  return pbVar4;
}



// Function: FUN_10010ea0 at 10010ea0

undefined4 * __fastcall FUN_10010ea0(undefined4 *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined **local_28 [3];
  int *local_1c;
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b6bc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = param_1 + 0x17;
  *param_1 = CResizingDialog<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x18] = 0;
  local_1c = piVar1;
  local_18 = param_1;
  pvVar2 = operator_new(0xc);
  if (pvVar2 != (void *)0x0) {
    *piVar1 = (int)pvVar2;
    *(void **)pvVar2 = pvVar2;
    *(int *)(*piVar1 + 4) = *piVar1;
    local_8 = 2;
    param_1[5] = 1;
    param_1[2] = 1;
    param_1[1] = 0;
    param_1[3] = 0;
    param_1[6] = 0;
    param_1[7] = 1;
    param_1[8] = 0;
    local_14 = (char *)GetSystemMetrics(0x14);
    iVar3 = GetSystemMetrics(2);
    param_1[0x15] = iVar3;
    param_1[0x16] = local_14;
    param_1[4] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_10027634);
}



// Function: FUN_10010f80 at 10010f80

undefined4 __thiscall FUN_10010f80(void *this,undefined4 param_1,undefined4 param_2,int param_3)

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



// Function: FUN_10010ff0 at 10010ff0

void __thiscall FUN_10010ff0(void *this)

{
  LPRECT lpRect;
  HWND hWnd;
  HWND hWnd_00;
  int iVar1;
  int iVar2;
  HDC hDC;
  undefined4 *in_stack_00000010;
  tagPAINTSTRUCT local_48;
  uint local_8;
  
  local_8 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  iVar2 = __RTDynamicCast(this,0,&CResizingDialog<class_CVehicleClassificationPageImpl>::
                                  RTTI_Type_Descriptor,
                          &CVehicleClassificationPageImpl::RTTI_Type_Descriptor,0);
  hWnd = *(HWND *)(iVar2 + 4);
  hDC = GetDC(hWnd);
  BeginPaint(hWnd,&local_48);
  if (((*(int *)((int)this + 0x1c) != 0) && (*(int *)((int)this + 0x18) != 0)) ||
     (*(int *)((int)this + 0x20) != 0)) {
    iVar2 = __RTDynamicCast(this,0,&CResizingDialog<class_CVehicleClassificationPageImpl>::
                                    RTTI_Type_Descriptor,
                            &CVehicleClassificationPageImpl::RTTI_Type_Descriptor,0);
    hWnd_00 = *(HWND *)(iVar2 + 4);
    lpRect = (LPRECT)((int)this + 0x44);
    GetClientRect(hWnd_00,lpRect);
    InvalidateRect(hWnd_00,lpRect,1);
    iVar2 = *(int *)((int)this + 0x50);
    iVar1 = *(int *)((int)this + 0x58);
    lpRect->left = *(int *)((int)this + 0x4c) - *(int *)((int)this + 0x54);
    *(int *)((int)this + 0x48) = iVar2 - iVar1;
    UpdateWindow(hWnd_00);
    DrawFrameControl(hDC,lpRect,3,8);
    *(undefined4 *)((int)this + 0x1c) = 0;
    *(undefined4 *)((int)this + 0x20) = 0;
  }
  EndPaint(hWnd,&local_48);
  ReleaseDC(hWnd,hDC);
  *in_stack_00000010 = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100110f0 at 100110f0

void __fastcall FUN_100110f0(undefined4 *param_1)

{
  int *this;
  int *piVar1;
  int *piVar2;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b6f3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = CResizingDialog<class_CVehicleClassificationPageImpl>::vftable;
  local_8 = 0;
  piVar2 = *(int **)param_1[0x17];
  this = param_1 + 0x17;
  local_14 = param_1;
  if (piVar2 != (int *)param_1[0x17]) {
    do {
      operator_delete((void *)piVar2[2]);
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*this);
  }
  FUN_1000f920(this,(int *)&local_18,*(int **)*this,(int *)*this);
  local_8 = 1;
  piVar2 = (int *)*this;
  piVar1 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*this + 4) = *this;
  param_1[0x18] = 0;
  local_18 = this;
  if (piVar1 != (int *)*this) {
    do {
      piVar2 = (int *)*piVar1;
      operator_delete(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != (int *)*this);
  }
  local_8 = 0xffffffff;
  operator_delete((void *)*this);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100111c0 at 100111c0

undefined4 __thiscall FUN_100111c0(void *this)

{
  int *this_00;
  int *piVar1;
  undefined4 *in_stack_00000010;
  void *local_8;
  
  piVar1 = (int *)**(int **)((int)this + 0x5c);
  this_00 = (int *)((int)this + 0x5c);
  local_8 = this;
  if (piVar1 != *(int **)((int)this + 0x5c)) {
    do {
      operator_delete((void *)piVar1[2]);
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*this_00);
  }
  FUN_1000f920(this_00,(int *)&local_8,*(int **)*this_00,(int *)*this_00);
  *in_stack_00000010 = 0;
  return 0;
}



// Function: FUN_10011210 at 10011210

undefined4 __thiscall FUN_10011210(void *this,void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uStack_30;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b720;
  local_10 = ExceptionList;
  uStack_30 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 2;
  puVar1 = (undefined4 *)((int)this + 0x10);
  iVar2 = Ordinal_7(*puVar1);
  if (iVar2 == 0) {
    FUN_100106c0(this,puVar1);
  }
  FUN_1000cd00(param_1,puVar1);
                    /* WARNING: Load size is inaccurate */
  uVar3 = (**(code **)(*this + 0x10))(&local_18);
  iVar2 = Ordinal_7(local_18);
  if (iVar2 != 0) {
    uVar4 = lstrlenW(L"-");
    FUN_1000bf10(param_1,&DAT_100238a4,uVar4);
    FUN_1000cd00(param_1,&local_18);
  }
  local_8._0_1_ = 1;
  Ordinal_6(local_18);
  local_8 = (uint)local_8._1_3_ << 8;
  Ordinal_6(0);
  ExceptionList = local_10;
  return uVar3;
}



// Function: Catch@100112ee at 100112ee

undefined4 Catch_100112ee(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x100112d7;
}



// Function: FUN_10011300 at 10011300

void FUN_10011300(int param_1,undefined4 param_2)

{
  undefined1 local_74 [4];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_64 [7];
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
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b750;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10010850(local_74,param_1,param_2,(int *)&PTR_10022cc0,0);
  local_8 = 0;
  local_40 = local_70;
  local_3c = local_6c;
  local_38 = local_68;
  local_44 = CComErrorHandlerException::vftable;
  local_20 = 7;
  local_24 = 0;
  local_34[0] = 0;
  FUN_10002b20(local_34,local_64,0,0xffffffff);
  local_18 = local_48;
  local_8 = local_8 & 0xffffff00;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_44,(ThrowInfo *)&DAT_100289f4);
}



// Function: FUN_100113a0 at 100113a0

undefined4 * __fastcall FUN_100113a0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001b853;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[0x4a] = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  local_8 = 4;
  param_1[9] = 0;
  FUN_1000dc70(param_1 + 10);
  local_8._0_1_ = 5;
  FUN_10010ea0(param_1 + 0x1b);
  param_1[0x36] = CComErrorHandler::vftable;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x41] = 7;
  param_1[0x40] = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  param_1[0x43] = CComErrorDisplay<class_CVehicleClassificationPageImpl>::vftable;
  local_8._0_1_ = 0x11;
  FUN_1000cbd0(param_1 + 0x45);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  *param_1 = CVehicleClassificationPageImpl::vftable;
  param_1[8] = CVehicleClassificationPageImpl::vftable;
  param_1[10] = CVehicleClassificationPageImpl::vftable;
  param_1[0xb] = CVehicleClassificationPageImpl::vftable;
  param_1[0x1b] = CVehicleClassificationPageImpl::vftable;
  param_1[0x35] = CVehicleClassificationPageImpl::vftable;
  param_1[0x36] = CVehicleClassificationPageImpl::vftable;
  param_1[0x43] = CVehicleClassificationPageImpl::vftable;
  param_1[0x44] = CVehicleClassificationPageImpl::vftable;
  param_1[0x45] = CVehicleClassificationPageImpl::vftable;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  FUN_10001000(param_1 + 0x51);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10011520 at 10011520

undefined4 __fastcall FUN_10011520(int param_1)

{
  BOOL BVar1;
  
  if ((DAT_1003129c != (HMODULE)0x0) && (*(int *)(param_1 + 4) == 1)) {
    BVar1 = FreeLibrary(DAT_1003129c);
    if (BVar1 != 1) {
      return 0x80004005;
    }
  }
  return 0;
}



// Function: FUN_10011550 at 10011550

undefined2 __fastcall FUN_10011550(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x18))();
  return *(undefined2 *)(&DAT_100232c0 + (uVar1 & 0xffff) * 2);
}



// Function: FUN_10011570 at 10011570

void FUN_10011570(int param_1)

{
  if (param_1 != 0) {
    InterlockedExchange(&DAT_1003129c,param_1);
  }
  return;
}



// Function: FUN_10011590 at 10011590

undefined4 FUN_10011590(void)

{
  return DAT_1003129c;
}



// Function: FUN_100115a0 at 100115a0

undefined4 FUN_100115a0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_2 = 1;
  return 0;
}



// Function: FUN_100115c0 at 100115c0

uint __thiscall FUN_100115c0(void *this,ushort *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  void *pvVar4;
  ushort *puVar5;
  uint uVar6;
  ushort *puVar7;
  
  uVar6 = *(uint *)((int)this + 0x10);
  if (param_3 == 0) {
    if (param_2 < uVar6) {
      return param_2;
    }
  }
  else {
    if (param_3 <= uVar6) {
      uVar2 = uVar6 - param_3;
      if (param_2 < uVar6 - param_3) {
        uVar2 = param_2;
      }
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      puVar7 = (ushort *)((int)pvVar4 + uVar2 * 2);
      uVar1 = *param_1;
      do {
        if (*puVar7 == uVar1) {
          puVar3 = puVar7;
          puVar5 = param_1;
          uVar6 = param_3;
          if (param_3 == 0) {
LAB_10011644:
            if (*(uint *)((int)this + 0x14) < 8) {
              return (int)puVar7 - (int)this >> 1;
            }
                    /* WARNING: Load size is inaccurate */
            return (int)puVar7 - *this >> 1;
          }
          while (*puVar3 == *puVar5) {
            uVar6 = uVar6 - 1;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
            if (uVar6 == 0) goto LAB_10011644;
          }
          if ((-(uint)(*puVar3 < *puVar5) & 0xfffffffe) == 0xffffffff) goto LAB_10011644;
        }
        puVar3 = (ushort *)FUN_100017e0((undefined4 *)this);
        if (puVar7 == puVar3) break;
        puVar7 = puVar7 + -1;
      } while( true );
    }
    uVar6 = 0xffffffff;
  }
  return uVar6;
}



// Function: FUN_100116a0 at 100116a0

int FUN_100116a0(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar5 = param_2;
  piVar4 = param_1;
  uVar1 = param_1[6];
  local_28 = param_1[1];
  local_1c = param_4;
  local_18 = 0;
  local_10 = 0;
  local_14 = 0;
  param_1 = (int *)0x0;
  piVar4[6] = (int)&local_28;
  local_20 = param_3;
  local_c = 0x24;
  local_8 = 1;
  local_24 = param_2;
  param_2 = uVar1;
  piVar6 = (int *)(**(code **)*piVar4)(local_28,uVar5,param_3,param_4,&param_1,0);
  piVar4[6] = param_2;
  piVar7 = piVar6;
  if (piVar6 == (int *)0x0) {
    if (uVar5 == 0x82) {
      piVar4[7] = piVar4[7] | 1;
    }
  }
  else {
    piVar7 = param_1;
    if (uVar5 < 0x3a) {
      if ((uVar5 == 0x39) || ((0x2d < uVar5 && ((uVar5 < 0x30 || (uVar5 == 0x37))))))
      goto LAB_10011763;
    }
    else if ((uVar5 == 0x110) || ((0x131 < uVar5 && (uVar5 < 0x139)))) goto LAB_10011763;
    piVar7 = piVar6;
    if ((*(byte *)(piVar4 + 7) & 1) == 0) {
      SetWindowLongW((HWND)piVar4[1],0,(LONG)param_1);
    }
  }
LAB_10011763:
  if (((piVar4[7] & 1U) != 0) && (piVar4[6] == 0)) {
    iVar2 = piVar4[1];
    piVar4[7] = piVar4[7] & 0xfffffffe;
    pcVar3 = *(code **)(*piVar4 + 0xc);
    piVar4[1] = 0;
    (*pcVar3)(iVar2);
  }
  return (int)piVar7;
}



// Function: FUN_100117a0 at 100117a0

void __thiscall FUN_100117a0(void *this,byte param_1)

{
  FUN_100144b0((void *)((int)this + -0x114),param_1);
  return;
}



// Function: FUN_100117b0 at 100117b0

void __thiscall FUN_100117b0(void *this,byte param_1)

{
  FUN_100144b0((void *)((int)this + -0xd8),param_1);
  return;
}



// Function: FUN_100117c0 at 100117c0

void __thiscall FUN_100117c0(void *this,byte param_1)

{
  FUN_100144b0((void *)((int)this + -0x2c),param_1);
  return;
}



// Function: FUN_100117d0 at 100117d0

void __thiscall FUN_100117d0(void *this,byte param_1)

{
  FUN_100144b0((void *)((int)this + -0x10c),param_1);
  return;
}



// Function: FUN_100117e0 at 100117e0

undefined * FUN_100117e0(void)

{
  return FUN_100116a0;
}



// Function: FUN_100117f0 at 100117f0

void __thiscall FUN_100117f0(void *this,LPCWSTR param_1)

{
  LPCWSTR *ppWVar1;
  int iVar2;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  HKEY local_434;
  undefined4 local_430;
  undefined4 local_42c;
  uint local_428;
  BYTE local_424 [520];
  BYTE local_21c [520];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b883;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_434 = (HKEY)0x0;
  local_430 = 0;
  local_42c = 0;
  local_8 = 1;
  local_21c[0] = '\0';
  local_21c[1] = '\0';
  memset(local_21c + 2,0,0x206);
  local_424[0] = '\0';
  local_424[1] = '\0';
  memset(local_424 + 2,0,0x206);
  local_428 = 0x208;
  ppWVar1 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar1 = &param_1;
  }
  iVar2 = FUN_10004fb0(&local_434,(HKEY)0x80000002,(LPCWSTR)ppWVar1,0x2001f);
  if (iVar2 == 0) {
    iVar2 = FUN_10005060(&local_434,L"XMLResource",local_21c,&local_428);
    local_428 = 0x208;
  }
  FUN_10005060(&local_434,L"FriendlyName",local_424,&local_428);
  if ((iVar2 == 0) && (local_428 != 0)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0xc))(local_21c,in_stack_00000020);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_434 != (HKEY)0x0) {
    RegCloseKey(local_434);
    local_434 = (HKEY)0x0;
  }
  local_430 = 0;
  local_8 = 0xffffffff;
  if (7 < in_stack_00000018) {
    operator_delete(param_1);
  }
  in_stack_00000018 = 7;
  uStack00000014 = 0;
  param_1 = (LPCWSTR)((uint)param_1 & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10011990 at 10011990

int * __thiscall
FUN_10011990(void *this,uint param_1,uint param_2,int *param_3,uint param_4,uint param_5)

{
  code *pcVar1;
  uint uVar2;
  uint extraout_EAX;
  uint extraout_EAX_00;
  undefined2 *puVar3;
  void *pvVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  uint extraout_ECX;
  uint uVar8;
  
  uVar7 = *(uint *)((int)this + 0x10);
  if ((uVar7 < param_1) || ((uint)param_3[4] < param_4)) {
    std::_Xout_of_range("invalid string position");
    pcVar1 = (code *)swi(3);
    piVar6 = (int *)(*pcVar1)();
    return piVar6;
  }
  uVar2 = uVar7 - param_1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  uVar8 = param_3[4] - param_4;
  if (uVar8 < param_5) {
    param_5 = uVar8;
  }
  uVar7 = uVar7 - param_2;
  if (-param_5 - 1 <= uVar7) {
    std::_Xlength_error("string too long");
    uVar2 = extraout_EAX;
    uVar7 = extraout_ECX;
  }
  uVar2 = uVar2 - param_2;
  uVar7 = uVar7 + param_5;
  if (*(uint *)((int)this + 0x10) < uVar7) {
    uVar8 = uVar7;
    if (0x7ffffffe < uVar7) {
      std::_Xlength_error("string too long");
      uVar8 = extraout_EAX_00;
    }
    if (*(uint *)((int)this + 0x14) < uVar8) {
      FUN_10001f90(this,uVar7);
    }
    else if (uVar8 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      puVar3 = (undefined2 *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        puVar3 = *this;
      }
      *puVar3 = 0;
    }
  }
  if ((int *)this == param_3) {
    if (param_2 < param_5) {
      if (param_1 < param_4) {
        uVar8 = param_2 + param_1;
        if (param_4 < uVar8) {
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10001670((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),
                       param_2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10001670((void *)((int)pvVar5 + (param_1 + param_5) * 2),
                       (void *)((int)pvVar4 + uVar8 * 2),uVar2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          uVar2 = param_5 - param_2;
          pvVar4 = (void *)((int)pvVar4 + (param_4 + param_5) * 2);
          pvVar5 = (void *)((int)pvVar5 + uVar8 * 2);
        }
        else {
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          FUN_10001670((void *)((int)pvVar5 + (param_1 + param_5) * 2),
                       (void *)((int)pvVar4 + uVar8 * 2),uVar2);
          pvVar5 = this;
          pvVar4 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
            pvVar5 = *this;
            pvVar4 = *this;
          }
          pvVar4 = (void *)((int)pvVar4 + ((param_4 - param_2) + param_5) * 2);
          pvVar5 = (void *)((int)pvVar5 + param_1 * 2);
          uVar2 = param_5;
        }
      }
      else {
        pvVar5 = this;
        pvVar4 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          pvVar5 = *this;
          pvVar4 = *this;
        }
        FUN_10001670((void *)((int)pvVar5 + (param_1 + param_5) * 2),
                     (void *)((int)pvVar4 + (param_2 + param_1) * 2),uVar2);
        if (*(uint *)((int)this + 0x14) < 8) {
          pvVar4 = (void *)((int)this + param_4 * 2);
          pvVar5 = (void *)((int)this + param_1 * 2);
          uVar2 = param_5;
        }
        else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          pvVar4 = (void *)(*this + param_4 * 2);
          pvVar5 = (void *)(*this + param_1 * 2);
          uVar2 = param_5;
        }
      }
    }
    else {
      pvVar5 = this;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar5 = *this;
        pvVar4 = *this;
      }
      FUN_10001670((void *)((int)pvVar5 + param_1 * 2),(void *)((int)pvVar4 + param_4 * 2),param_5);
      pvVar5 = this;
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        pvVar5 = *this;
        pvVar4 = *this;
      }
      pvVar4 = (void *)((int)pvVar4 + (param_2 + param_1) * 2);
      pvVar5 = (void *)((int)pvVar5 + (param_1 + param_5) * 2);
    }
    FUN_10001670(pvVar5,pvVar4,uVar2);
  }
  else {
    pvVar5 = this;
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      pvVar5 = *this;
      pvVar4 = *this;
    }
    memmove((void *)((int)pvVar5 + (param_1 + param_5) * 2),
            (void *)((int)pvVar4 + (param_2 + param_1) * 2),uVar2 * 2);
    if (7 < (uint)param_3[5]) {
      param_3 = (int *)*param_3;
    }
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    memcpy((void *)((int)pvVar4 + param_1 * 2),(void *)((int)param_3 + param_4 * 2),param_5 * 2);
  }
  *(uint *)((int)this + 0x10) = uVar7;
  if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    *(undefined2 *)(*this + uVar7 * 2) = 0;
    return (int *)this;
  }
  *(undefined2 *)((int)this + uVar7 * 2) = 0;
  return (int *)this;
}



// Function: FUN_10011cc0 at 10011cc0

int * __thiscall FUN_10011cc0(void *this,uint param_1,int *param_2,int *param_3,uint param_4)

{
  int *piVar1;
  int *extraout_EAX;
  void *pvVar2;
  uint extraout_ECX;
  uint uVar3;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar4;
  uint extraout_EDX;
  int *piVar5;
  uint uVar6;
  
  if (param_3 != (int *)0x0) {
    uVar6 = *(uint *)((int)this + 0x14);
    piVar1 = (int *)this;
    if (7 < uVar6) {
                    /* WARNING: Load size is inaccurate */
      piVar1 = *this;
    }
    if (piVar1 <= param_3) {
      pvVar2 = this;
      if (7 < uVar6) {
                    /* WARNING: Load size is inaccurate */
        pvVar2 = *this;
      }
      if (param_3 < (int *)((int)pvVar2 + *(int *)((int)this + 0x10) * 2)) {
        pvVar2 = this;
        if (7 < uVar6) {
                    /* WARNING: Load size is inaccurate */
          pvVar2 = *this;
        }
        piVar1 = FUN_10011990(this,param_1,(uint)param_2,(int *)this,(int)param_3 - (int)pvVar2 >> 1
                              ,param_4);
        return piVar1;
      }
    }
  }
  uVar6 = *(uint *)((int)this + 0x10);
  uVar3 = param_1;
  if (uVar6 < param_1) {
    std::_Xout_of_range("invalid string position");
    uVar3 = extraout_ECX;
    uVar6 = extraout_EDX;
  }
  piVar1 = (int *)(uVar6 - uVar3);
  piVar5 = param_2;
  if (piVar1 < param_2) {
    piVar5 = piVar1;
  }
  piVar4 = (int *)param_4;
  if (-param_4 - 1 <= uVar6 - (int)piVar5) {
    std::_Xlength_error("string too long");
    piVar1 = extraout_EAX;
    piVar4 = extraout_ECX_00;
  }
  if (piVar4 < piVar5) {
    pvVar2 = this;
    param_2 = (int *)this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      param_2 = *this;
      pvVar2 = *this;
    }
    memmove((void *)((int)param_2 + (param_1 + (int)piVar4) * 2),
            (void *)((int)pvVar2 + (param_1 + (int)piVar5) * 2),((int)piVar1 - (int)piVar5) * 2);
    piVar4 = (int *)param_4;
  }
  if ((piVar4 != (int *)0x0) || (piVar5 != (int *)0x0)) {
    uVar6 = (*(int *)((int)this + 0x10) - (int)piVar5) + (int)piVar4;
    if (0x7ffffffe < uVar6) {
      std::_Xlength_error("string too long");
      piVar4 = extraout_ECX_01;
    }
    if (*(uint *)((int)this + 0x14) < uVar6) {
      FUN_10001f90(this,uVar6);
      piVar4 = (int *)param_4;
      if (uVar6 == 0) {
        return (int *)this;
      }
    }
    else if (uVar6 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (*(uint *)((int)this + 0x14) < 8) {
        *(undefined2 *)this = 0;
        return (int *)this;
      }
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int *)this;
    }
    if (piVar5 < piVar4) {
      pvVar2 = this;
      param_2 = (int *)this;
      if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
        param_2 = *this;
                    /* WARNING: Load size is inaccurate */
        pvVar2 = *this;
      }
      FUN_10001670((void *)((int)pvVar2 + (param_1 + (int)piVar4) * 2),
                   (void *)((int)param_2 + (param_1 + (int)piVar5) * 2),(int)piVar1 - (int)piVar5);
      piVar4 = (int *)param_4;
    }
    pvVar2 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar2 = *this;
    }
    memcpy((void *)((int)pvVar2 + param_1 * 2),param_3,(int)piVar4 * 2);
    *(uint *)((int)this + 0x10) = uVar6;
    if (7 < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      *(undefined2 *)(*this + uVar6 * 2) = 0;
      return (int *)this;
    }
    *(undefined2 *)((int)this + uVar6 * 2) = 0;
  }
  return (int *)this;
}



// Function: FUN_10011eb0 at 10011eb0

void FUN_10011eb0(LPCWSTR param_1)

{
  short sVar1;
  LPCWSTR *ppWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  void *in_stack_00000020;
  HKEY local_22c;
  undefined4 local_228;
  undefined4 local_224;
  uint local_220;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b8c3;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_22c = (HKEY)0x0;
  local_228 = 0;
  local_224 = 0;
  local_8 = 1;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_220 = 0x208;
  ppWVar2 = (LPCWSTR *)param_1;
  if (in_stack_00000018 < 8) {
    ppWVar2 = &param_1;
  }
  iVar3 = FUN_10004fb0(&local_22c,(HKEY)0x80000002,(LPCWSTR)ppWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10005060(&local_22c,L"ResourceDLL",(LPBYTE)&local_21c,&local_220);
    if ((LVar4 == 0) && (local_220 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10002d40(in_stack_00000020,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (local_22c != (HKEY)0x0) {
    RegCloseKey(local_22c);
    local_22c = (HKEY)0x0;
  }
  local_228 = 0;
  local_8 = 0xffffffff;
  if (7 < in_stack_00000018) {
    operator_delete(param_1);
  }
  param_1 = (LPCWSTR)((uint)param_1 & 0xffff0000);
  in_stack_00000018 = 7;
  uStack00000014 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012010 at 10012010

undefined4 FUN_10012010(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    return 0x8002000b;
  }
  if (param_4 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  uVar1 = 0;
  if (DAT_100304fc == (int *)0x0) {
    uVar1 = FUN_10007020(&PTR_DAT_100304f0,param_3);
  }
  *param_4 = DAT_100304fc;
  if (DAT_100304fc != (int *)0x0) {
    (**(code **)(*DAT_100304fc + 4))(DAT_100304fc);
    uVar1 = 0;
  }
  return uVar1;
}



// Function: FUN_10012070 at 10012070

void FUN_10012070(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  FUN_10007950(&PTR_DAT_100304f0,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_100120a0 at 100120a0

void FUN_100120a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  if ((DAT_100304fc == (int *)0x0) || (DAT_10030504 == 0)) {
    FUN_10007020(&PTR_DAT_100304f0,param_4);
  }
  if (DAT_100304fc != (int *)0x0) {
    (**(code **)(*DAT_100304fc + 0x2c))
              (DAT_100304fc,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}



// Function: FUN_10012100 at 10012100

void __thiscall FUN_10012100(void *this,uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10011cc0(this,param_1,param_2,param_3,(int)piVar2 - ((int)param_3 + 2) >> 1);
  return;
}



// Function: FUN_10012140 at 10012140

/* WARNING: Removing unreachable block (ram,0x1001248c) */

void __thiscall FUN_10012140(void *this,void *param_1)

{
  short sVar1;
  int iVar2;
  HMODULE pHVar3;
  int ****ppppiVar4;
  LPCWSTR ***ppppWVar5;
  int ****ppppiVar6;
  undefined4 uStack00000014;
  uint in_stack_00000018;
  uint uStack_12c;
  LPCWSTR **pppWStack_128;
  undefined2 local_10c [8];
  undefined4 local_fc;
  undefined4 local_f8;
  LPCWSTR **pppWStack_f0;
  uint uStack_ec;
  undefined4 local_a0;
  undefined4 local_90;
  uint local_8c;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  int ***local_4c [4];
  int local_3c;
  uint local_38;
  LPCWSTR **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001b94f;
  local_10 = ExceptionList;
  uStack_ec = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_8._1_3_ = 0;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8._0_1_ = 3;
  pppWStack_f0 = (LPCWSTR **)local_30;
  local_f8 = 7;
  local_fc = 0;
  local_10c[0] = 0;
  local_14 = uStack_ec;
  FUN_10002b20(local_10c,(int *)&param_1,0,0xffffffff);
                    /* WARNING: Load size is inaccurate */
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar2 = (**(code **)(*this + 0x40))();
  ppppWVar5 = (LPCWSTR ***)local_30[0];
  if (local_1c < 8) {
    ppppWVar5 = local_30;
  }
  pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
  if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
                    /* WARNING: Load size is inaccurate */
    iVar2 = (**(code **)(*this + 0x28))();
    ppppWVar5 = (LPCWSTR ***)local_30[0];
    if (local_1c < 8) {
      ppppWVar5 = local_30;
    }
    pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
    if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
                    /* WARNING: Load size is inaccurate */
      iVar2 = (**(code **)(*this + 0x14))();
                    /* WARNING: Load size is inaccurate */
      if (((iVar2 != 0) || (local_3c == 0)) &&
         ((iVar2 = (**(code **)(*this + 0x10))(), iVar2 != 0 || (local_3c == 0)))) {
        FUN_10002d40(local_4c,(int *)&DAT_10022954,2);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68._2_2_ << 0x10);
      FUN_10002d40(&local_68,(int *)&DAT_10023890,1);
      local_8._0_1_ = 5;
      ppppiVar6 = (int ****)local_4c[0];
      if (local_38 < 8) {
        ppppiVar6 = local_4c;
      }
      ppppiVar4 = ppppiVar6;
      do {
        sVar1 = *(short *)ppppiVar4;
        ppppiVar4 = (int ****)((int)ppppiVar4 + 2);
      } while (sVar1 != 0);
      FUN_100075a0(&local_68,(int *)ppppiVar6,(int)ppppiVar4 - ((int)ppppiVar6 + 2) >> 1);
      FUN_100075a0(&local_68,(int *)&DAT_100237b0,1);
      local_a0 = (void *)((uint)local_a0._2_2_ << 0x10);
      local_8c = 7;
      local_90 = 0;
      FUN_10002d40(&local_a0,(int *)L"_EN.",4);
      local_8._0_1_ = 6;
                    /* WARNING: Load size is inaccurate */
      (**(code **)(*this + 0x38))();
      local_8._0_1_ = 5;
      if (7 < local_8c) {
        operator_delete(local_a0);
      }
      local_a0 = (void *)((uint)local_a0 & 0xffff0000);
      local_8c = 7;
      local_90 = 0;
      local_70 = 7;
      local_74 = 0;
      local_84 = (void *)((uint)local_84._2_2_ << 0x10);
      pppWStack_128 = (LPCWSTR **)0x1001237c;
      FUN_10002d40(&local_84,(int *)L"_en.",4);
      local_8._0_1_ = 7;
                    /* WARNING: Load size is inaccurate */
      pppWStack_128 = (LPCWSTR **)local_30;
      uStack_12c = 0x10012395;
      (**(code **)(*this + 0x38))();
      local_8._0_1_ = 5;
      if (7 < local_70) {
        operator_delete(local_84);
      }
      local_70 = 7;
      local_74 = 0;
      local_84 = (void *)((uint)local_84 & 0xffff0000);
      ppppWVar5 = (LPCWSTR ***)local_30[0];
      if (local_1c < 8) {
        ppppWVar5 = local_30;
      }
      pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (7 < local_54) {
        operator_delete(local_68);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68 & 0xffff0000);
      if (pHVar3 == (HMODULE)0x0) {
        GetLastError();
        goto LAB_1001240f;
      }
    }
  }
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 0x20))();
  *(undefined4 *)((int)this + 4) = 1;
LAB_1001240f:
  local_8._0_1_ = 8;
  uStack_12c = uStack_12c & 0xffff0000;
  FUN_10002b20(&uStack_12c,(int *)&param_1,0,0xffffffff);
                    /* WARNING: Load size is inaccurate */
  local_8._0_1_ = 8;
  (**(code **)(*this + 0x44))();
  local_8._0_1_ = 2;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0xffffffff;
  if (7 < in_stack_00000018) {
    operator_delete(param_1);
  }
  param_1 = (void *)((uint)param_1 & 0xffff0000);
  in_stack_00000018 = 7;
  uStack00000014 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012560 at 10012560

void FUN_10012560(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  uint local_248;
  HKEY local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ba06;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_244 = (HKEY)0x0;
  local_240 = 0;
  local_23c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_248 = 0x208;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10002d40(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100075a0(&local_238,(int *)L"{56B5B650-57C6-4EA6-BB8A-F3BAED9668F7}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10004fb0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10005060(&local_244,L"ResourceDLL",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10002d40(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_244 != (HKEY)0x0) {
    RegCloseKey(local_244);
    local_244 = (HKEY)0x0;
  }
  local_240 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012710 at 10012710

void __thiscall FUN_10012710(void *this,int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001b988;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  piVar3 = param_1;
  do {
    iVar1 = *piVar3;
    piVar3 = (int *)((int)piVar3 + 2);
  } while ((short)iVar1 != 0);
  local_14 = uVar2;
  FUN_10002d40(local_30,param_1,(int)piVar3 - ((int)param_1 + 2) >> 1);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  (**(code **)(*this + 8))(local_30,param_2,uVar2);
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



// Function: FUN_100127e0 at 100127e0

void __thiscall FUN_100127e0(void *this,int *param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int ***pppiVar4;
  bool bVar5;
  ushort local_50 [2];
  void *local_4c [4];
  undefined4 local_3c;
  uint local_38;
  int **local_30 [4];
  int *local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001b9c0;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = (int *)0x0;
  local_30[0] = (int **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 0x14))(local_30,local_14);
  if (iVar1 == 0) {
    bVar5 = local_20 == (int *)0x0;
    if (bVar5) goto LAB_10012843;
  }
  else {
LAB_10012843:
                    /* WARNING: Load size is inaccurate */
    iVar1 = (**(code **)(*this + 0x10))(local_30);
    if (iVar1 == 0) {
      bVar5 = local_20 == (int *)0x0;
      if (!bVar5) goto LAB_10012873;
    }
    FUN_10002b20(param_2,param_1,0,0xffffffff);
    if (iVar1 != 0) goto LAB_1001292e;
    bVar5 = local_20 == (int *)0x0;
  }
LAB_10012873:
  if (!bVar5) {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_10002b20(local_4c,param_1,0,0xffffffff);
    local_50[0] = 0x5f;
    local_50[1] = 0;
    uVar2 = FUN_100115c0(local_4c,local_50,0xffffffff,1);
    local_50[0] = 0x2e;
    local_50[1] = 0;
    uVar3 = FUN_100115c0(local_4c,local_50,0xffffffff,1);
    if ((uVar2 != 0xffffffff) && ((int *)((uVar3 - uVar2) + -1) == local_20)) {
      pppiVar4 = (int ***)local_30[0];
      if (local_1c < 8) {
        pppiVar4 = local_30;
      }
      FUN_10012100(local_4c,uVar2 + 1,local_20,(int *)pppiVar4);
    }
    FUN_10002b20(param_2,(int *)local_4c,0,0xffffffff);
    local_8 = local_8 & 0xffffff00;
    if (7 < local_38) {
      operator_delete(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = (void *)((uint)local_4c[0] & 0xffff0000);
  }
LAB_1001292e:
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = (int *)0x0;
  local_30[0] = (int **)((uint)local_30[0] & 0xffff0000);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012980 at 10012980

void FUN_10012980(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  uint local_248;
  HKEY local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ba06;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_244 = (HKEY)0x0;
  local_240 = 0;
  local_23c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_248 = 0x208;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10002d40(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\cs\\",
               0x36);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100075a0(&local_238,(int *)L"Locale",6);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10004fb0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10005060(&local_244,L"LanguageExt",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10002d40(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_244 != (HKEY)0x0) {
    RegCloseKey(local_244);
    local_244 = (HKEY)0x0;
  }
  local_240 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012b30 at 10012b30

void FUN_10012b30(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  HKEY local_264;
  undefined4 local_260;
  undefined4 local_25c;
  uint local_258;
  undefined4 local_254;
  undefined4 local_244;
  uint local_240;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ba81;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_264 = (HKEY)0x0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_258 = 0x208;
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254._2_2_ << 0x10);
  FUN_10002d40(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10002d40(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_100068a0(&local_238,&local_254,0,0xffffffff);
  FUN_100075a0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_100075a0(&local_238,(int *)L"{56B5B650-57C6-4EA6-BB8A-F3BAED9668F7}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10004fb0(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10005060(&local_264,L"LanguageExt",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10002d40(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8._0_1_ = 1;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_240) {
    operator_delete(local_254);
  }
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_264 != (HKEY)0x0) {
    RegCloseKey(local_264);
    local_264 = (HKEY)0x0;
  }
  local_260 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10012d70 at 10012d70

void __fastcall FUN_10012d70(int *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  undefined **ppuVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  void *local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001ba38;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  iVar3 = (**(code **)(*param_1 + 0x10))(local_30,local_14);
  if ((iVar3 != 0) || (local_20 == 0)) {
    FUN_10002d40(local_30,(int *)&DAT_10022954,2);
  }
  uVar7 = 0;
  if (PTR_DAT_1002f6c0 != (undefined *)0x0) {
    ppuVar4 = &PTR_DAT_1002f6c0;
    do {
      puVar2 = (ushort *)*ppuVar4;
      puVar5 = puVar2;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
      } while (uVar1 != 0);
      uVar6 = FUN_10006080(local_30,0,local_20,puVar2,(int)puVar5 - (int)(puVar2 + 1) >> 1);
      if (uVar6 == 0) break;
      uVar7 = uVar7 + 1;
      ppuVar4 = &PTR_DAT_1002f6c0 + (uVar7 & 0xffff);
    } while ((&PTR_DAT_1002f6c0)[uVar7 & 0xffff] != (undefined *)0x0);
  }
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



// Function: FUN_10012e80 at 10012e80

void FUN_10012e80(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  HKEY local_264;
  undefined4 local_260;
  undefined4 local_25c;
  uint local_258;
  undefined4 local_254;
  undefined4 local_244;
  uint local_240;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001ba81;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_264 = (HKEY)0x0;
  local_260 = 0;
  local_25c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_258 = 0x208;
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254._2_2_ << 0x10);
  FUN_10002d40(&local_254,(int *)L"Administrator",0xd);
  local_8._0_1_ = 1;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10002d40(&local_238,(int *)L"software\\cummins\\intelect\\insite\\6.0\\users\\",0x2b);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_100068a0(&local_238,&local_254,0,0xffffffff);
  FUN_100075a0(&local_238,(int *)L"\\AddIns\\",8);
  FUN_100075a0(&local_238,(int *)L"{56B5B650-57C6-4EA6-BB8A-F3BAED9668F7}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10004fb0(&local_264,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10005060(&local_264,L"ResourceDLL",(LPBYTE)&local_21c,&local_258);
    if ((LVar4 == 0) && (local_258 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10002d40(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8._0_1_ = 1;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_240) {
    operator_delete(local_254);
  }
  local_240 = 7;
  local_244 = 0;
  local_254 = (void *)((uint)local_254 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_264 != (HKEY)0x0) {
    RegCloseKey(local_264);
    local_264 = (HKEY)0x0;
  }
  local_260 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100130c0 at 100130c0

void __thiscall FUN_100130c0(void *this,undefined4 param_1)

{
  LPCWSTR pWVar1;
  int iVar2;
  HKEY local_450;
  undefined4 local_44c;
  undefined4 local_448;
  uint local_444;
  undefined4 local_440;
  undefined4 local_430;
  uint local_42c;
  BYTE local_424 [520];
  BYTE local_21c [520];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001bac6;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_450 = (HKEY)0x0;
  local_44c = 0;
  local_448 = 0;
  local_8 = 0;
  local_21c[0] = '\0';
  local_21c[1] = '\0';
  memset(local_21c + 2,0,0x206);
  local_424[0] = '\0';
  local_424[1] = '\0';
  memset(local_424 + 2,0,0x206);
  local_444 = 0x208;
  local_42c = 7;
  local_430 = 0;
  local_440 = (LPCWSTR)((uint)local_440._2_2_ << 0x10);
  FUN_10002d40(&local_440,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100075a0(&local_440,(int *)L"{56B5B650-57C6-4EA6-BB8A-F3BAED9668F7}",0x26);
  pWVar1 = local_440;
  if (local_42c < 8) {
    pWVar1 = (LPCWSTR)&local_440;
  }
  iVar2 = FUN_10004fb0(&local_450,(HKEY)0x80000002,pWVar1,0x2001f);
  if (iVar2 == 0) {
    iVar2 = FUN_10005060(&local_450,L"XMLResource",local_21c,&local_444);
    local_444 = 0x208;
  }
  FUN_10005060(&local_450,L"FriendlyName",local_424,&local_444);
  if ((iVar2 == 0) && (local_444 != 0)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 0xc))(local_21c,param_1);
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_42c) {
    operator_delete(local_440);
  }
  local_42c = 7;
  local_430 = 0;
  local_440 = (LPCWSTR)((uint)local_440 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_450 != (HKEY)0x0) {
    RegCloseKey(local_450);
    local_450 = (HKEY)0x0;
  }
  local_44c = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_100132b0 at 100132b0

void FUN_100132b0(void *param_1)

{
  short sVar1;
  LPCWSTR pWVar2;
  int iVar3;
  LSTATUS LVar4;
  short *psVar5;
  uint local_248;
  HKEY local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1001ba06;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_244 = (HKEY)0x0;
  local_240 = 0;
  local_23c = 0;
  local_8 = 0;
  local_21c._0_2_ = 0;
  memset((void *)((int)&local_21c + 2),0,0x206);
  local_248 = 0x208;
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238._2_2_ << 0x10);
  FUN_10002d40(&local_238,
               (int *)L"software\\cummins\\intelect\\insite\\6.0\\system\\kernel\\aif\\addins\\",
               0x3e);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_100075a0(&local_238,(int *)L"{56B5B650-57C6-4EA6-BB8A-F3BAED9668F7}",0x26);
  pWVar2 = local_238;
  if (local_224 < 8) {
    pWVar2 = (LPCWSTR)&local_238;
  }
  iVar3 = FUN_10004fb0(&local_244,(HKEY)0x80000002,pWVar2,0x2001f);
  if (iVar3 == 0) {
    LVar4 = FUN_10005060(&local_244,L"BaseName",(LPBYTE)&local_21c,&local_248);
    if ((LVar4 == 0) && (local_248 != 0)) {
      psVar5 = (short *)&local_21c;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_10002d40(param_1,&local_21c,(int)psVar5 - ((int)&local_21c + 2) >> 1);
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (7 < local_224) {
    operator_delete(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = (LPCWSTR)((uint)local_238 & 0xffff0000);
  local_8 = 0xffffffff;
  if (local_244 != (HKEY)0x0) {
    RegCloseKey(local_244);
    local_244 = (HKEY)0x0;
  }
  local_240 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10013460 at 10013460

void FUN_10013460(void *param_1,ushort *param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ushort *puVar5;
  int *piVar6;
  ushort *puVar7;
  
  puVar7 = param_2;
  if (7 < *(uint *)(param_2 + 10)) {
    puVar7 = *(ushort **)param_2;
  }
  puVar5 = puVar7;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  } while (uVar1 != 0);
  for (uVar3 = FUN_10005d50(param_1,puVar7,0,(int)puVar5 - (int)(puVar7 + 1) >> 1);
      uVar3 != 0xffffffff;
      uVar3 = FUN_10005d50(param_1,puVar5,param_3[4] + uVar3,(int)puVar7 - (int)(puVar5 + 1) >> 1))
  {
    piVar4 = FUN_100017e0(param_3);
    piVar6 = piVar4;
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar2 != 0);
    FUN_10011cc0(param_1,uVar3,*(int **)(param_2 + 8),piVar4,(int)piVar6 - ((int)piVar4 + 2) >> 1);
    puVar5 = (ushort *)FUN_100017e0((undefined4 *)param_2);
    puVar7 = puVar5;
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
    } while (uVar1 != 0);
  }
  return;
}



// Function: FUN_10013520 at 10013520

void __fastcall FUN_10013520(int *param_1)

{
  short sVar1;
  int iVar2;
  HMODULE pHVar3;
  int ****ppppiVar4;
  LPCWSTR ***ppppWVar5;
  int ****ppppiVar6;
  int local_c0;
  void *local_bc [4];
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_a0;
  undefined4 local_90;
  uint local_8c;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  int ***local_4c [4];
  int local_3c;
  uint local_38;
  LPCWSTR **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001bb26;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_a8 = 7;
  local_ac = 0;
  local_bc[0] = (void *)((uint)local_bc[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8 = 2;
  iVar2 = (**(code **)(*param_1 + 0x24))(local_30,local_14);
  ppppWVar5 = (LPCWSTR ***)local_30[0];
  if (local_1c < 8) {
    ppppWVar5 = local_30;
  }
  pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
  if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
    iVar2 = (**(code **)(*param_1 + 0x28))(local_30);
    ppppWVar5 = (LPCWSTR ***)local_30[0];
    if (local_1c < 8) {
      ppppWVar5 = local_30;
    }
    pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
    if ((iVar2 != 0) || (pHVar3 == (HMODULE)0x0)) {
      iVar2 = (**(code **)(*param_1 + 0x14))(local_4c);
      if (((iVar2 != 0) || (local_c0 = 0, local_3c == 0)) &&
         ((local_c0 = (**(code **)(*param_1 + 0x10))(local_4c), local_c0 != 0 || (local_3c == 0))))
      {
        FUN_10002d40(local_4c,(int *)&DAT_10022954,2);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68._2_2_ << 0x10);
      FUN_10002d40(&local_68,(int *)&DAT_10023890,1);
      local_8._0_1_ = 3;
      ppppiVar6 = (int ****)local_4c[0];
      if (local_38 < 8) {
        ppppiVar6 = local_4c;
      }
      ppppiVar4 = ppppiVar6;
      do {
        sVar1 = *(short *)ppppiVar4;
        ppppiVar4 = (int ****)((int)ppppiVar4 + 2);
      } while (sVar1 != 0);
      FUN_100075a0(&local_68,(int *)ppppiVar6,(int)ppppiVar4 - ((int)ppppiVar6 + 2) >> 1);
      FUN_100075a0(&local_68,(int *)&DAT_100237b0,1);
      local_84 = (void *)((uint)local_84._2_2_ << 0x10);
      local_70 = 7;
      local_74 = 0;
      FUN_10002d40(&local_84,(int *)L"_EN.",4);
      local_8._0_1_ = 4;
      (**(code **)(*param_1 + 0x38))(local_30,&local_84,&local_68);
      local_8._0_1_ = 3;
      if (7 < local_70) {
        operator_delete(local_84);
      }
      local_84 = (void *)((uint)local_84 & 0xffff0000);
      local_70 = 7;
      local_74 = 0;
      local_8c = 7;
      local_90 = 0;
      local_a0 = (void *)((uint)local_a0._2_2_ << 0x10);
      FUN_10002d40(&local_a0,(int *)L"_en.",4);
      local_8._0_1_ = 5;
      (**(code **)(*param_1 + 0x38))(local_30,&local_a0,&local_68);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (7 < local_8c) {
        operator_delete(local_a0);
      }
      local_8c = 7;
      local_90 = 0;
      local_a0 = (void *)((uint)local_a0 & 0xffff0000);
      ppppWVar5 = (LPCWSTR ***)local_30[0];
      if (local_1c < 8) {
        ppppWVar5 = local_30;
      }
      pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
      if (((local_c0 != 0) || (pHVar3 == (HMODULE)0x0)) &&
         (iVar2 = (**(code **)(*param_1 + 0x30))(local_bc), iVar2 == 0)) {
        FUN_10002b20(local_30,(int *)local_bc,0,0xffffffff);
        FUN_100075a0(local_30,(int *)L"Res_",4);
        FUN_100068a0(local_30,local_4c,0,0xffffffff);
        FUN_100075a0(local_30,(int *)L".dll",4);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if (7 < local_54) {
        operator_delete(local_68);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (void *)((uint)local_68 & 0xffff0000);
      if (pHVar3 == (HMODULE)0x0) {
        ppppWVar5 = (LPCWSTR ***)local_30[0];
        if (local_1c < 8) {
          ppppWVar5 = local_30;
        }
        pHVar3 = LoadLibraryW((LPCWSTR)ppppWVar5);
        if (pHVar3 == (HMODULE)0x0) {
          GetLastError();
          goto LAB_10013854;
        }
      }
    }
  }
  (**(code **)(*param_1 + 0x20))(pHVar3);
  param_1[1] = 1;
LAB_10013854:
  local_8._0_1_ = 1;
  if (7 < local_38) {
    operator_delete(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (int ***)((uint)local_4c[0] & 0xffff0000);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_a8) {
    operator_delete(local_bc[0]);
  }
  local_a8 = 7;
  local_ac = 0;
  local_bc[0] = (void *)((uint)local_bc[0] & 0xffff0000);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10013910 at 10013910

void __fastcall FUN_10013910(undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001bbfd;
  local_10 = ExceptionList;
  uVar3 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CVehicleClassificationPageImpl::vftable;
  param_1[8] = CVehicleClassificationPageImpl::vftable;
  param_1[10] = CVehicleClassificationPageImpl::vftable;
  param_1[0xb] = CVehicleClassificationPageImpl::vftable;
  param_1[0x1b] = CVehicleClassificationPageImpl::vftable;
  param_1[0x35] = CVehicleClassificationPageImpl::vftable;
  param_1[0x36] = CVehicleClassificationPageImpl::vftable;
  param_1[0x43] = CVehicleClassificationPageImpl::vftable;
  param_1[0x44] = CVehicleClassificationPageImpl::vftable;
  param_1[0x45] = CVehicleClassificationPageImpl::vftable;
  local_8 = 6;
  pvVar1 = (void *)param_1[0x4b];
  if (pvVar1 != (void *)0x0) {
    FUN_10016e10((int)pvVar1);
    operator_delete(pvVar1);
  }
  local_8._0_1_ = 5;
  FUN_10001030(param_1 + 0x51);
  param_1[0x45] = CContextSensitiveHelpProvider<class_CVehicleClassificationPageImpl>::vftable;
  local_8._0_1_ = 8;
  Ordinal_6(param_1[0x49],uVar3);
  local_8._0_1_ = 7;
  piVar2 = (int *)param_1[0x48];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8._0_1_ = 4;
  piVar2 = (int *)param_1[0x47];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  param_1[0x43] = CComErrorDisplay<class_CVehicleClassificationPageImpl>::vftable;
  local_8._0_1_ = 2;
  FUN_1000d990(param_1 + 0x36);
  local_8._0_1_ = 1;
  FUN_100110f0(param_1 + 0x1b);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_1000d140((int)(param_1 + 10));
  local_8 = 0xffffffff;
  if ((void *)param_1[5] != (void *)0x0) {
    FreeStdCallThunk((void *)param_1[5]);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013a80 at 10013a80

void __fastcall FUN_10013a80(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = param_1 + 6;
  if (param_1[0x1b] != 0) {
    cVar1 = FUN_10010400(param_1 + 6);
    if (cVar1 == '\0') {
      piVar3 = (int *)0x0;
    }
    iVar2 = fclose((FILE *)param_1[0x1b]);
    if (iVar2 == 0) goto LAB_10013aaf;
  }
  piVar3 = (int *)0x0;
LAB_10013aaf:
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined1 *)((int)param_1 + 0x62) = 0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + 6));
  param_1[0x1b] = 0;
  param_1[0x19] = DAT_10030ea8;
  param_1[0x17] = 0;
  if (piVar3 == (int *)0x0) {
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(*param_1 + 4) + (int)param_1),2,false);
  }
  return;
}



// Function: FUN_10013af0 at 10013af0

void __fastcall FUN_10013af0(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018e19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  local_8 = 0;
  if ((*(int *)(param_1 + 0x54) != 0) &&
     ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)**(int **)(param_1 + 0x10) ==
      param_1 + 0x48)) {
    uVar1 = *(undefined4 *)(param_1 + 0x40);
    **(int **)(param_1 + 0x10) = *(int *)(param_1 + 0x3c);
    **(undefined4 **)(param_1 + 0x20) = uVar1;
    **(undefined4 **)(param_1 + 0x30) = 0;
  }
  if (param_1[0x50] != (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>)0x0) {
    FUN_10010e50(param_1);
  }
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013b80 at 10013b80

undefined4 __thiscall
FUN_10013b80(void *this,undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  undefined4 uVar1;
  
  if (param_6 == 0) {
    if (param_2 == 0xf) {
      param_6 = 1;
      uVar1 = FUN_10010ff0(this);
      *param_5 = uVar1;
      if (param_6 != 0) {
        return 1;
      }
    }
    else if (param_2 == 5) {
      param_6 = 1;
      uVar1 = FUN_10010560(this,5,param_3,param_4,&param_6);
      *param_5 = uVar1;
      if (param_6 != 0) {
        return 1;
      }
    }
    else {
      if (param_2 == 0x24) {
        uVar1 = FUN_10010f80(this,0x24,param_3,param_4);
        *param_5 = uVar1;
        return 1;
      }
      if (param_2 == 2) {
        param_6 = 1;
        uVar1 = FUN_100111c0(this);
        *param_5 = uVar1;
        if (param_6 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}



// Function: FUN_10013c50 at 10013c50

basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_10013c50(void *this,byte param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10018e19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)this = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  local_8 = 0;
  if ((*(int *)((int)this + 0x54) != 0) && (**(int **)((int)this + 0x10) == (int)this + 0x48)) {
    uVar1 = *(undefined4 *)((int)this + 0x40);
    **(int **)((int)this + 0x10) = *(int *)((int)this + 0x3c);
    **(undefined4 **)((int)this + 0x20) = uVar1;
    **(undefined4 **)((int)this + 0x30) = 0;
  }
  if (*(char *)((int)this + 0x50) != '\0') {
    FUN_10010e50((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  }
  local_8 = 0xffffffff;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_10013cf0 at 10013cf0

undefined4 * __fastcall FUN_10013cf0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bc58;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100113a0(param_1);
  local_8 = 0;
  *param_1 = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[8] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[10] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0xb] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x1b] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x35] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x36] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x43] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x44] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x45] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  (**(code **)(*DAT_10030e30 + 4))(uVar1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10013db0 at 10013db0

undefined4 FUN_10013db0(int param_1)

{
  *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
  return *(undefined4 *)(param_1 + 0x100);
}



// Function: FUN_10013dd0 at 10013dd0

undefined4 FUN_10013dd0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0x100);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0x100);
  if ((*piVar1 == 0) && ((int *)(param_1 + -0x28) != (int *)0x0)) {
    (**(code **)(*(int *)(param_1 + -0x28) + 4))(1);
  }
  return uVar2;
}



// Function: FUN_10013e00 at 10013e00

void FUN_10013e00(int param_1)

{
  FUN_10013db0(param_1 + -4);
  return;
}



// Function: FUN_10013e10 at 10013e10

void FUN_10013e10(int param_1)

{
  FUN_10013dd0(param_1 + -0xe8);
  return;
}



// Function: FUN_10013e20 at 10013e20

void __thiscall FUN_10013e20(void *this,byte param_1)

{
  FUN_10013fc0((void *)((int)this + -0x2c),param_1);
  return;
}



// Function: FUN_10013e30 at 10013e30

void FUN_10013e30(int param_1)

{
  FUN_10013dd0(param_1 + -0xac);
  return;
}



// Function: FUN_10013e40 at 10013e40

void FUN_10013e40(int param_1)

{
  FUN_10013db0(param_1 + -0xe8);
  return;
}



// Function: FUN_10013e50 at 10013e50

void __thiscall FUN_10013e50(void *this,byte param_1)

{
  FUN_10013fc0((void *)((int)this + -0x10c),param_1);
  return;
}



// Function: FUN_10013e60 at 10013e60

void FUN_10013e60(int param_1)

{
  FUN_10013db0(param_1 + -0xac);
  return;
}



// Function: FUN_10013e70 at 10013e70

void __thiscall FUN_10013e70(void *this,byte param_1)

{
  FUN_10013fc0((void *)((int)this + -0x114),param_1);
  return;
}



// Function: FUN_10013e80 at 10013e80

void __thiscall FUN_10013e80(void *this,byte param_1)

{
  FUN_10013fc0((void *)((int)this + -0xd8),param_1);
  return;
}



// Function: FUN_10013e90 at 10013e90

void FUN_10013e90(int param_1)

{
  FUN_10013dd0(param_1 + -4);
  return;
}



// Function: FUN_10013ea0 at 10013ea0

void FUN_10013ea0(int param_1,undefined4 param_2,undefined4 param_3)

{
  Ordinal_32(param_1 + -0x28,&PTR_DAT_10023e48,param_2,param_3);
  return;
}



// Function: FUN_10013ed0 at 10013ed0

void FUN_10013ed0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10013ea0(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10013ee0 at 10013ee0

void FUN_10013ee0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10013ea0(param_1 + -0xe8,param_2,param_3);
  return;
}



// Function: FUN_10013ef0 at 10013ef0

void FUN_10013ef0(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10013ea0(param_1 + -0xac,param_2,param_3);
  return;
}



// Function: FUN_10013f00 at 10013f00

void __fastcall FUN_10013f00(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc58;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[8] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[10] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0xb] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x1b] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x35] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x36] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x43] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x44] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  param_1[0x45] = ATL::CComObject<class_CVehicleClassificationPageImpl>::vftable;
  local_8 = 0;
  param_1[0x4a] = 0xc0000001;
  (**(code **)(*DAT_10030e30 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10013910(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10013fc0 at 10013fc0

undefined4 * __thiscall FUN_10013fc0(void *this,byte param_1)

{
  FUN_10013f00((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_10013ff0 at 10013ff0

void __fastcall FUN_10013ff0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10013910(param_1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014040 at 10014040

undefined4 * __thiscall FUN_10014040(void *this,undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bc58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100113a0((undefined4 *)this);
  *(undefined ***)this = ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x20) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x28) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x2c) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x6c) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0xd4) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0xd8) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x10c) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x110) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined ***)((int)this + 0x114) =
       ATL::CComContainedObject<class_CVehicleClassificationPageImpl>::vftable;
  *(undefined4 *)((int)this + 0x128) = param_1;
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_100140f0 at 100140f0

void FUN_100140f0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x100) + 4))(*(int **)(param_1 + 0x100));
  return;
}



// Function: FUN_10014110 at 10014110

void FUN_10014110(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x100) + 8))(*(int **)(param_1 + 0x100));
  return;
}



// Function: FUN_10014130 at 10014130

void FUN_10014130(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)**(undefined4 **)(param_1 + 0x100))(*(undefined4 **)(param_1 + 0x100),param_2,param_3)
  ;
  return;
}



// Function: FUN_10014150 at 10014150

void __thiscall FUN_10014150(void *this,byte param_1)

{
  FUN_10014220((void *)((int)this + -0x114),param_1);
  return;
}



// Function: FUN_10014160 at 10014160

void __thiscall FUN_10014160(void *this,byte param_1)

{
  FUN_10014220((void *)((int)this + -0xd8),param_1);
  return;
}



// Function: FUN_10014170 at 10014170

void FUN_10014170(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10014130(param_1 + -0xe8,param_2,param_3);
  return;
}



// Function: FUN_10014180 at 10014180

void FUN_10014180(int param_1)

{
  FUN_10014110(param_1 + -4);
  return;
}



// Function: FUN_10014190 at 10014190

void FUN_10014190(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10014130(param_1 + -0xac,param_2,param_3);
  return;
}



// Function: FUN_100141a0 at 100141a0

void FUN_100141a0(int param_1)

{
  FUN_100140f0(param_1 + -4);
  return;
}



// Function: FUN_100141b0 at 100141b0

void FUN_100141b0(int param_1)

{
  FUN_10014110(param_1 + -0xe8);
  return;
}



// Function: FUN_100141c0 at 100141c0

void __thiscall FUN_100141c0(void *this,byte param_1)

{
  FUN_10014220((void *)((int)this + -0x2c),param_1);
  return;
}



// Function: FUN_100141d0 at 100141d0

void FUN_100141d0(int param_1)

{
  FUN_10014110(param_1 + -0xac);
  return;
}



// Function: FUN_100141e0 at 100141e0

void FUN_100141e0(int param_1)

{
  FUN_100140f0(param_1 + -0xe8);
  return;
}



// Function: FUN_100141f0 at 100141f0

void __thiscall FUN_100141f0(void *this,byte param_1)

{
  FUN_10014220((void *)((int)this + -0x10c),param_1);
  return;
}



// Function: FUN_10014200 at 10014200

void FUN_10014200(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_10014130(param_1 + -4,param_2,param_3);
  return;
}



// Function: FUN_10014210 at 10014210

void FUN_10014210(int param_1)

{
  FUN_100140f0(param_1 + -0xac);
  return;
}



// Function: FUN_10014220 at 10014220

undefined4 * __thiscall FUN_10014220(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bc58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10013910((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014280 at 10014280

undefined4 __thiscall
FUN_10014280(void *this,undefined4 param_1,int param_2,int param_3,int param_4,int *param_5,
            int param_6)

{
  short sVar1;
  int iVar2;
  short sVar3;
  int local_8;
  
  local_8 = 1;
  if (param_6 != 0) {
    return 0;
  }
  if (param_2 == 0x110) {
    local_8 = 1;
    iVar2 = FUN_10017250(*(void **)((int)this + 300));
LAB_100142c8:
    *param_5 = iVar2;
  }
  else {
    if (param_2 == 5) {
      local_8 = 1;
      iVar2 = FUN_100178e0(*(void **)((int)this + 300),5,param_3,param_4);
      goto LAB_100142c8;
    }
    if (param_2 == 0x114) {
      local_8 = 1;
      iVar2 = FUN_10017840(*(void **)((int)this + 300),0x114,param_3,param_4);
      goto LAB_100142c8;
    }
    if (param_2 == 0x115) {
      local_8 = 1;
      iVar2 = FUN_10017840(*(void **)((int)this + 300),0x115,param_3,param_4);
      goto LAB_100142c8;
    }
    if (param_2 != 0x111) goto LAB_1001444e;
    sVar1 = (short)param_3;
    sVar3 = (short)((uint)param_3 >> 0x10);
    if (sVar1 == 0x3f4) {
      if (sVar3 != 0) goto LAB_1001444e;
      local_8 = 1;
      iVar2 = FUN_100174e0(*(void **)((int)this + 300));
      goto LAB_100142c8;
    }
    if (sVar1 == 0x3f0) {
      if (sVar3 != 1) goto LAB_1001444e;
      local_8 = 1;
      iVar2 = FUN_100169d0(*(void **)((int)this + 300));
      goto LAB_100142c8;
    }
    if (sVar1 == 0x3f2) {
      if (sVar3 != 1) goto LAB_1001444e;
      local_8 = 1;
      iVar2 = FUN_100176c0(*(void **)((int)this + 300));
      goto LAB_100142c8;
    }
    if (param_3 != 0x3f6) goto LAB_1001444e;
    local_8 = 1;
    iVar2 = FUN_1000b950((int)this);
    *param_5 = iVar2;
  }
  if (local_8 != 0) {
    return 1;
  }
  local_8 = 0;
LAB_1001444e:
  iVar2 = FUN_10013b80((void *)((int)this + 0x6c),param_1,param_2,param_3,param_4,param_5,0);
  if (iVar2 != 0) {
    return 1;
  }
  if (param_2 == 0x53) {
    local_8 = 1;
    iVar2 = (**(code **)(*(int *)((int)this + 0x114) + 4))(0x53,param_3,param_4,&local_8);
    *param_5 = iVar2;
    if (local_8 != 0) {
      return 1;
    }
  }
  return 0;
}



// Function: FUN_100144b0 at 100144b0

undefined4 * __thiscall FUN_100144b0(void *this,byte param_1)

{
  FUN_10013910((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}



// Function: FUN_100144e0 at 100144e0

basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> * __thiscall
FUN_100144e0(void *this,int param_1)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bcc6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    *(undefined **)this = &DAT_10024088;
    *(undefined ***)((int)this + 0x10) = &PTR_10024080;
    *(undefined4 *)((int)this + 0x70) = _vftable__exref;
    *(undefined4 *)((int)this + 0x70) = _vftable__exref;
    local_8 = 1;
  }
  this_00 = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)((int)this + 0x18);
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this,this_00);
  local_8 = 2;
                    /* WARNING: Load size is inaccurate */
  *(undefined ***)((int)this + *(int *)(*this + 4)) =
       std::basic_fstream<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this_00);
  local_8 = CONCAT31(local_8._1_3_,3);
  *(undefined ***)this_00 = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  *(undefined1 *)((int)this + 0x68) = 0;
  *(undefined1 *)((int)this + 0x62) = 0;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::_Init(this_00);
  *(undefined4 *)((int)this + 0x6c) = 0;
  *(undefined4 *)((int)this + 100) = DAT_10030ea8;
  *(undefined4 *)((int)this + 0x5c) = 0;
  ExceptionList = local_10;
  return (basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this;
}



// Function: FUN_100145c0 at 100145c0

void __fastcall FUN_100145c0(int param_1)

{
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *this;
  undefined4 uVar1;
  uint3 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001bd10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x70) + 4) + -0x70 + param_1) =
       std::basic_fstream<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  this = (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(param_1 + -0x58);
  *(undefined ***)this = std::basic_filebuf<wchar_t,struct_std::char_traits<wchar_t>_>::vftable;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  if ((*(int *)(param_1 + -4) != 0) && (**(int **)(param_1 + -0x48) == param_1 + -0x10)) {
    uVar1 = *(undefined4 *)(param_1 + -0x18);
    **(int **)(param_1 + -0x48) = *(int *)(param_1 + -0x1c);
    **(undefined4 **)(param_1 + -0x38) = uVar1;
    **(undefined4 **)(param_1 + -0x28) = 0;
  }
  if (*(char *)(param_1 + -8) != '\0') {
    FUN_10010e50(this);
    uVar2 = local_8._1_3_;
  }
  local_8._1_3_ = uVar2;
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>(this);
  local_8 = 0xffffffff;
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)this);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014670 at 10014670

int FUN_10014670(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd30;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  puVar1 = (undefined4 *)operator_new(0x184);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_10013cf0(puVar1);
    local_8 = 0xffffffff;
    iVar2 = FUN_1001471d();
    return iVar2;
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_1001471d();
  return iVar2;
}



// Function: Catch@10014707 at 10014707

undefined * Catch_10014707(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10014714;
}



// Function: FUN_1001471d at 1001471d

int FUN_1001471d(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    unaff_ESI[0x4a] = unaff_ESI[0x4a] + 1;
    unaff_EDI = FUN_1000d200((int)unaff_ESI);
    if (-1 < unaff_EDI) {
      unaff_EDI = 0;
    }
    unaff_ESI[0x4a] = unaff_ESI[0x4a] + -1;
    if (unaff_EDI == 0) {
      unaff_EDI = (**(code **)unaff_ESI[10])(unaff_ESI + 10,*(undefined4 *)(unaff_EBP + 0xc));
      if (unaff_EDI == 0) goto LAB_10014760;
    }
    (**(code **)(*unaff_ESI + 4))(1);
  }
LAB_10014760:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_10014780 at 10014780

undefined4 * __thiscall FUN_10014780(void *this,undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bd5b;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<class_CVehicleClassificationPageImpl>::vftable;
  FUN_10014040((void *)((int)this + 8),param_1);
  local_8 = 0;
  (**(code **)(*DAT_10030e30 + 4))(uVar1);
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014800 at 10014800

undefined4 FUN_10014800(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}



// Function: FUN_10014810 at 10014810

int FUN_10014810(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[1];
  if ((*piVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0xc))(1);
  }
  return iVar2;
}



// Function: FUN_10014840 at 10014840

undefined4 FUN_10014840(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  *param_3 = 0;
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
     ) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  uVar1 = Ordinal_32(param_1 + 2,&PTR_DAT_10023e48,param_2,param_3);
  return uVar1;
}



// Function: FUN_100148b0 at 100148b0

undefined4 * __thiscall FUN_100148b0(void *this,byte param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bd93;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ATL::CComAggObject<class_CVehicleClassificationPageImpl>::vftable;
  local_8 = 0;
  *(undefined4 *)((int)this + 4) = 0xc0000001;
  (**(code **)(*DAT_10030e30 + 8))(uVar1);
  local_8 = 0xffffffff;
  FUN_10013910((undefined4 *)((int)this + 8));
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10014940 at 10014940

void __thiscall FUN_10014940(void *this,int param_1)

{
  *(int *)((int)this + 0xc) = param_1;
  if ((*(char *)((int)this + 4) == '\0') && (param_1 != 0)) {
    *(undefined1 *)((int)this + 4) = 1;
    FUN_10011300(param_1,*(undefined4 *)((int)this + 8));
  }
  return;
}



// Function: FUN_10014970 at 10014970

/* WARNING: Removing unreachable block (ram,0x10014afe) */
/* WARNING: Removing unreachable block (ram,0x10014b11) */
/* WARNING: Removing unreachable block (ram,0x10014b24) */
/* WARNING: Removing unreachable block (ram,0x10014b3a) */

undefined4 __thiscall FUN_10014970(void *this,undefined4 *param_1)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  uint uStack_48;
  undefined **local_38;
  undefined1 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001be28;
  local_10 = ExceptionList;
  uStack_48 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  local_1c = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  local_28 = (int *)0x0;
  local_24 = (int *)0x0;
  local_34 = 0;
  local_30 = 0;
  local_38 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_2c = 0x80004005;
  local_8._1_3_ = 0;
  if (*(int *)((int)this + 0xc) != 0) {
    local_8._0_1_ = 9;
    ExceptionList = &local_10;
    iVar1 = (**(code **)**(undefined4 **)((int)this + 0xc))
                      (*(undefined4 **)((int)this + 0xc),&DAT_10023320,&local_24);
    FUN_10008d20(&local_38,iVar1);
    local_20 = (undefined4 *)0x0;
    local_8._0_1_ = 0xb;
    iVar1 = (**(code **)(*local_24 + 0x20))(local_24,&local_20);
    FUN_10008d20(&local_38,iVar1);
    iVar1 = (**(code **)*local_20)(local_20,&DAT_1002356c,&local_28);
    FUN_10008d20(&local_38,iVar1);
    HVar2 = CoCreateInstance((IID *)&DAT_10023310,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_10022c74,&local_1c
                            );
    FUN_10008d20(&local_38,HVar2);
    iVar1 = (**(code **)*local_1c)(local_1c,&DAT_10023544,&local_18);
    FUN_10008d20(&local_38,iVar1);
    iVar1 = (**(code **)(*local_18 + 0x10))(local_18,*param_1);
    FUN_10008d20(&local_38,iVar1);
    iVar1 = (**(code **)(*local_18 + 0x20))(local_18,*(undefined4 *)((int)this + 4));
    FUN_10008d20(&local_38,iVar1);
    iVar1 = (**(code **)(*local_28 + 0xc))(local_28,local_1c);
    FUN_10008d20(&local_38,iVar1);
    local_8 = CONCAT31(local_8._1_3_,9);
    FUN_10005400((int *)&local_20);
    local_8 = 8;
    uVar3 = FUN_10014ae8();
    return uVar3;
  }
  return 0x80004005;
}



// Function: Catch@10014ad9 at 10014ad9

undefined * Catch_10014ad9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 8;
  return &DAT_10014ae6;
}



// Function: FUN_10014ae8 at 10014ae8

undefined4 FUN_10014ae8(void)

{
  int *piVar1;
  int *unaff_EBX;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined ***)(unaff_EBP + -0x34) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  piVar1 = *(int **)(unaff_EBP + -0x20);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  piVar1 = *(int **)(unaff_EBP + -0x24);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + -0x18);
  if (piVar1 != unaff_EBX) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x28);
}



// Function: FUN_10014b60 at 10014b60

undefined4 __fastcall FUN_10014b60(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  uint uStack_4c;
  undefined **local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001be90;
  local_10 = ExceptionList;
  uStack_4c = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_4c;
  ExceptionList = &local_10;
  local_24 = 0xffffffff;
  local_38 = 0;
  local_34 = 0;
  local_3c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_30 = 0x80004005;
  local_20 = (int *)0x0;
  local_1c = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  uStack_7 = 0;
  local_8 = 7;
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar3 = &uStack_4c;
  if (puVar1 != (undefined4 *)0x0) {
    iVar4 = (**(code **)*puVar1)(puVar1,&DAT_100235e8,&local_20);
    FUN_10008d20(&local_3c,iVar4);
    piVar2 = local_20;
    piVar5 = FUN_10017aa0(&local_2c,&DAT_1002fcf4);
    local_8 = 8;
    iVar4 = (**(code **)(*piVar2 + 0x24))(piVar2,*piVar5,&local_1c);
    FUN_10008d20(&local_3c,iVar4);
    local_8 = 7;
    Ordinal_6(local_2c);
    iVar4 = (**(code **)*local_1c)(local_1c,&DAT_100235f8,&local_18);
    FUN_10008d20(&local_3c,iVar4);
    local_28 = 0xffffffff;
    (**(code **)(*local_18 + 0x88))(local_18,&local_28);
    puVar3 = (uint *)local_14;
    if (local_18 != (int *)0x0) {
      if ((short)local_28 == -1) {
        local_24 = 0xffffffff;
      }
      else {
        iVar4 = (**(code **)(*local_18 + 0x5c))(local_18,&local_24);
        FUN_10008d20(&local_3c,iVar4);
        puVar3 = (uint *)local_14;
      }
    }
  }
  local_14 = (undefined1 *)puVar3;
  local_8 = 5;
  FUN_10005400((int *)&local_18);
  local_8 = 3;
  FUN_10005400((int *)&local_1c);
  _local_8 = CONCAT31(uStack_7,1);
  FUN_10005400((int *)&local_20);
  ExceptionList = local_10;
  return local_24;
}



// Function: Catch@10014cdc at 10014cdc

undefined4 Catch_10014cdc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014cb9;
}



// Function: FUN_10014cf0 at 10014cf0

void __thiscall
FUN_10014cf0(void *this,undefined4 param_1,int param_2,int param_3,int param_4,int *param_5,
            int param_6)

{
  FUN_10014280((void *)((int)this + -0x6c),param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function: FUN_10014d00 at 10014d00

void __fastcall FUN_10014d00(int param_1)

{
  ios_base *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001beb9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (ios_base *)(param_1 + 0x70);
  FUN_100145c0((int)piVar1);
  *(code **)piVar1 = _vftable__exref;
  local_8 = 0xffffffff;
  *(code **)piVar1 = _vftable__exref;
  std::ios_base::_Ios_base_dtor(piVar1);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10014d70 at 10014d70

undefined4 FUN_10014d70(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  uint uStack_38;
  undefined **local_28;
  undefined1 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bee8;
  local_10 = ExceptionList;
  uStack_38 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  local_24 = 0;
  local_20 = 0;
  local_28 = CSmartResult<struct_WINERRORPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_1c = 0xffffffff;
  local_18 = 1;
  local_8 = 1;
  iVar1 = FUN_100011f0((void *)(param_1 + 0x34),param_2,param_3);
  FUN_10014940(&local_28,iVar1);
  ExceptionList = local_10;
  return local_1c;
}



// Function: Catch@10014e0b at 10014e0b

undefined4 Catch_10014e0b(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014de6;
}



// Function: FUN_10014e20 at 10014e20

undefined4 FUN_10014e20(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uStack_38;
  undefined **local_28;
  undefined1 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bf18;
  local_10 = ExceptionList;
  uStack_38 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  local_24 = 0;
  local_20 = 0;
  local_28 = CSmartResult<struct_WINERRORPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_1c = 0xffffffff;
  local_18 = 1;
  local_8 = 1;
  iVar1 = FUN_100014b0((void *)(param_1 + 0x34),param_4 & 0xffff,param_4 >> 0x10);
  FUN_10014940(&local_28,iVar1);
  iVar1 = FUN_10010560((void *)(param_1 + -0xa4),param_2,param_3,param_4,&local_18);
  FUN_10014940(&local_28,iVar1);
  ExceptionList = local_10;
  return local_1c;
}



// Function: Catch@10014ed9 at 10014ed9

undefined4 Catch_10014ed9(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10014eb4;
}



// Function: FUN_10014ef0 at 10014ef0

void FUN_10014ef0(undefined4 param_1,wchar_t *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  wchar_t *unaff_EDI;
  int local_cc [38];
  undefined1 *local_34;
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bf5b;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_10002c20(local_cc,2,1);
  local_8 = 0;
  __RTDynamicCast(param_1,0);
  piVar2 = (int *)FUN_100020e0(local_cc,param_2);
  FUN_100020e0(piVar2,unaff_EDI);
  iVar3 = __RTDynamicCast();
  piVar2 = (int *)FUN_10003260(local_cc,(undefined2 *)local_30);
  local_8._0_1_ = 1;
  if (7 < (uint)piVar2[5]) {
    piVar2 = (int *)*piVar2;
  }
  piVar4 = piVar2;
  do {
    iVar1 = *piVar4;
    piVar4 = (int *)((int)piVar4 + 2);
  } while ((short)iVar1 != 0);
  local_34 = &stack0xffffff18;
  FUN_10002d40(&stack0xffffff18,piVar2,(int)piVar4 - ((int)piVar2 + 2) >> 1);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)(iVar3 + 0x20) + 0x3c))();
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_1c) {
    operator_delete(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffff0000);
  local_8 = 0xffffffff;
  FUN_10002a70(local_cc);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10015050 at 10015050

ios_base * __thiscall FUN_10015050(void *this,byte param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001bf99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100145c0((int)this);
  *(code **)this = _vftable__exref;
  local_8 = 0xffffffff;
  *(code **)this = _vftable__exref;
  std::ios_base::_Ios_base_dtor((ios_base *)this);
  if ((param_1 & 1) != 0) {
    operator_delete((ios_base *)((int)this + -0x70));
  }
  ExceptionList = local_10;
  return (ios_base *)((int)this + -0x70);
}



// Function: FUN_100150d0 at 100150d0

int * FUN_100150d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001bfcb;
  local_10 = ExceptionList;
  if (param_3 == (undefined4 *)0x0) {
    return (int *)0x80004003;
  }
  ExceptionList = &local_10;
  *param_3 = 0;
  local_8 = 0;
  this = operator_new(0x18c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (void *)0x0) {
    FUN_10014780(this,param_1);
    local_8 = 0xffffffff;
    piVar1 = FUN_10015189();
    return piVar1;
  }
  local_8 = 0xffffffff;
  piVar1 = FUN_10015189();
  return piVar1;
}



// Function: Catch@10015174 at 10015174

undefined * Catch_10015174(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return &DAT_10015181;
}



// Function: FUN_10015189 at 10015189

int * FUN_10015189(void)

{
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    unaff_EDI = (int *)FUN_1000d200((int)(unaff_ESI + 2));
    if ((int)unaff_EBX <= (int)unaff_EDI) {
      unaff_EDI = (int *)(**(code **)*unaff_ESI)();
      if (unaff_EDI == unaff_EBX) goto LAB_100151bb;
    }
    (**(code **)(*unaff_ESI + 0xc))(1);
  }
LAB_100151bb:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return unaff_EDI;
}



// Function: FUN_100151e0 at 100151e0

int __thiscall FUN_100151e0(void *this)

{
  int iVar1;
  undefined4 *in_stack_00000010;
  undefined4 uStack_4c;
  uint uStack_40;
  undefined **local_30;
  undefined1 local_2c;
  undefined4 local_28;
  int local_24;
  undefined1 *local_20;
  int local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001c010;
  local_10 = ExceptionList;
  uStack_40 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_40;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = 0;
  local_30 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_24 = -0x7fffbffb;
  local_1c = 0;
  uStack_7 = 0;
  local_8 = 2;
                    /* WARNING: Load size is inaccurate */
  iVar1 = (**(code **)(*this + 8))();
  uStack_4c = 0x10015247;
  FUN_10008d20(&local_30,iVar1);
  local_18 = 0;
  local_8 = 3;
  local_20 = (undefined1 *)&uStack_4c;
  FUN_1000ce90(&uStack_4c,&local_1c);
                    /* WARNING: Load size is inaccurate */
  _local_8 = CONCAT31(uStack_7,3);
  iVar1 = (**(code **)(*this + 0xc))();
  FUN_10008d20(&local_30,iVar1);
  if (local_24 == 0) {
    iVar1 = FUN_10014970(this,&local_18);
    FUN_10008d20(&local_30,iVar1);
  }
  local_8 = 2;
  Ordinal_6(local_18);
  _local_8 = CONCAT31(uStack_7,1);
  Ordinal_6(local_1c);
  *in_stack_00000010 = 1;
  ExceptionList = local_10;
  return local_24;
}



// Function: Catch@100152df at 100152df

undefined4 Catch_100152df(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100152b1;
}



// Function: FUN_100152f0 at 100152f0

void __thiscall FUN_100152f0(void *this,undefined4 param_1,CComBSTR *param_2)

{
  HRESULT HVar1;
  undefined4 uVar2;
  int iVar3;
  uint uStack_3c;
  undefined **local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  wchar_t *local_1c;
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c050;
  local_10 = ExceptionList;
  uStack_3c = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_28 = 0;
  local_24 = 0;
  local_2c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_20 = 0;
  local_18 = (int *)0x0;
  local_8._1_3_ = 0;
  local_8._0_1_ = 4;
  HVar1 = CoCreateInstance((IID *)&DAT_10023300,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_100235d8,&local_18);
  FUN_10008d20(&local_2c,HVar1);
  uVar2 = FUN_10014b60((int)this);
  iVar3 = (**(code **)(*local_18 + 0xc))(local_18,uVar2);
  FUN_10008d20(&local_2c,iVar3);
  FUN_1000cc80((undefined4 *)param_2);
  iVar3 = (**(code **)(*local_18 + 0x18))(local_18,param_1,0,&local_1c);
  FUN_10008d20(&local_2c,iVar3);
  ATL::CComBSTR::Attach(param_2,local_1c);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_10005400((int *)&local_18);
  local_8 = 1;
  FUN_100153de();
  return;
}



// Function: Catch@100153cf at 100153cf

undefined * Catch_100153cf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_100153dc;
}



// Function: FUN_100153de at 100153de

undefined4 FUN_100153de(void)

{
  undefined1 unaff_BL;
  int unaff_EBP;
  
  *(undefined1 *)(unaff_EBP + -4) = unaff_BL;
  *(undefined ***)(unaff_EBP + -0x28) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  Ordinal_6(*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x1c);
}



// Function: FUN_10015410 at 10015410

void __thiscall
FUN_10015410(void *this,long param_1,long param_2,undefined4 param_3,wchar_t *param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar4;
  basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *pbVar5;
  int iVar6;
  LPWSTR lpDateStr;
  int *piVar7;
  char *unaff_EDI;
  wchar_t *pwVar8;
  wchar_t *in_stack_fffffd14;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd20;
  wchar_t *in_stack_fffffd24;
  wchar_t *in_stack_fffffd30;
  wchar_t *in_stack_fffffd3c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd48;
  wchar_t *in_stack_fffffd4c;
  int in_stack_fffffd58;
  wchar_t *in_stack_fffffd5c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd68;
  wchar_t *in_stack_fffffd6c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd78;
  wchar_t *in_stack_fffffd7c;
  int in_stack_fffffd80;
  code *pcVar9;
  code *local_27c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd88;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd8c;
  _func_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr_basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>_ptr
  *in_stack_fffffd90;
  HKEY local_230;
  undefined4 local_22c;
  undefined4 local_228;
  ios_base *local_224;
  uint local_220;
  undefined4 local_21c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c0b5;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_224 = (ios_base *)param_3;
  FUN_100144e0(&stack0xfffffd14,1);
  local_8 = 0;
  if (*(int *)((int)this + 0x28) == 0) {
    local_230 = (HKEY)0x0;
    local_22c = 0;
    local_228 = 0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_10004fb0(&local_230,(HKEY)0x80000002,
                 L"Software\\Cummins\\Intelect\\INSITE\\6.0\\System\\Kernel\\CS\\Paths\\",0x2001f);
    local_220 = 0x208;
    FUN_10005060(&local_230,L"ErrorLog",(LPBYTE)&local_21c,&local_220);
    psVar3 = (short *)&local_21c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_10002d40((void *)((int)this + 0x18),&local_21c,(int)psVar3 - ((int)&local_21c + 2) >> 1);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_230 != (HKEY)0x0) {
      RegCloseKey(local_230);
      local_230 = (HKEY)0x0;
    }
    local_22c = 0;
    if (*(int *)((int)this + 0x28) != 0) goto LAB_10015567;
    local_8 = 0xffffffff;
    FUN_100145c0((int)&local_27c);
  }
  else {
LAB_10015567:
    pwVar8 = (wchar_t *)((int)this + 0x18);
    if (7 < *(uint *)((int)this + 0x2c)) {
      pwVar8 = *(wchar_t **)pwVar8;
    }
    pbVar4 = FUN_1000c750(&stack0xfffffd2c,pwVar8,10,(facet *)0x40);
    if (pbVar4 == (basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)0x0) {
      std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::setstate
                ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
                 (&stack0xfffffd14 + *(int *)(in_stack_fffffd14 + 2)),2,false);
    }
    else {
      std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::clear
                ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
                 (&stack0xfffffd14 + *(int *)(in_stack_fffffd14 + 2)),0,false);
    }
    if (in_stack_fffffd80 != 0) {
      pwVar8 = L" Error Log Entry:";
      pbVar5 = FUN_1000c920((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
                            &stack0xfffffd24,&DAT_1002418c);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_100020e0((int *)pbVar5,pwVar8);
      pbVar5 = FUN_1000c920(pbVar5,unaff_EDI);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_100020e0((int *)pbVar5,in_stack_fffffd14);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd20);
      iVar6 = GetDateFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,(LPWSTR)0x0,0);
      lVar2 = (ulonglong)(iVar6 + 1) * 2;
      lpDateStr = (LPWSTR)operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2
                                        );
      GetDateFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,lpDateStr,iVar6);
      piVar7 = (int *)FUN_100020e0((int *)&stack0xfffffd24,L"On ");
      piVar7 = (int *)FUN_100020e0(piVar7,in_stack_fffffd24);
      FUN_100020e0(piVar7,in_stack_fffffd30);
      operator_delete__(lpDateStr);
      iVar6 = GetTimeFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,(LPWSTR)0x0,0);
      lVar2 = (ulonglong)(iVar6 + 1) * 2;
      pwVar8 = (wchar_t *)
               operator_new__(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
      GetTimeFormatW(0x800,0x80000000,(SYSTEMTIME *)0x0,(LPCWSTR)0x0,pwVar8,iVar6);
      piVar7 = (int *)FUN_100020e0((int *)&stack0xfffffd24,pwVar8);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_100020e0(piVar7,in_stack_fffffd3c);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd48);
      operator_delete__(pwVar8);
      piVar7 = (int *)FUN_100020e0((int *)&stack0xfffffd24,L"In file ");
      piVar7 = (int *)FUN_100020e0(piVar7,param_4);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_100020e0(piVar7,in_stack_fffffd4c);
      pbVar5 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                         (pbVar5,in_stack_fffffd58);
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_100020e0((int *)pbVar5,in_stack_fffffd5c);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd68);
      pwVar8 = (wchar_t *)operator_new__(0x20);
      _ltow_s(param_1,pwVar8,0x10,0x10);
      piVar7 = (int *)FUN_100020e0((int *)&stack0xfffffd24,L"The HRESULT was: 0x");
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_100020e0(piVar7,in_stack_fffffd6c);
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd78);
      _ltow_s(param_2,pwVar8,0x10,0x10);
      piVar7 = (int *)FUN_100020e0((int *)&stack0xfffffd24,L"The result of the expression was: 0x");
      pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
               FUN_100020e0(piVar7,in_stack_fffffd7c);
      local_27c = (code *)0x1001581d;
      std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                (pbVar5,in_stack_fffffd88);
      local_27c = (code *)0x10015823;
      operator_delete__(pwVar8);
      if (*(int *)((int)this + 8) != 0) {
        local_220 = 0;
        local_8._0_1_ = 4;
        local_27c = *(code **)((int)this + 8);
        (**(code **)(*(int *)local_27c + 0x14))();
        pcVar9 = endl_exref;
        piVar7 = (int *)FUN_100020e0((int *)&stack0xfffffd24,L"Description of error: ");
        pbVar5 = (basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
                 FUN_100020e0(piVar7,(wchar_t *)pcVar9);
        pbVar5 = std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                           (pbVar5,in_stack_fffffd8c);
        std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::operator<<
                  (pbVar5,in_stack_fffffd90);
        local_8 = (uint)local_8._1_3_ << 8;
        Ordinal_6();
      }
      FUN_10013a80((int *)&stack0xfffffd14);
      local_8 = 0xffffffff;
      FUN_100145c0((int)&local_27c);
      local_224 = (ios_base *)&local_27c;
      local_8 = 0xffffffff;
      local_27c = (code *)0x100158e3;
      std::ios_base::_Ios_base_dtor(local_224);
      goto LAB_100158e8;
    }
    local_8 = 0xffffffff;
    FUN_100145c0((int)&local_27c);
  }
  local_8 = 0xffffffff;
  local_224 = (ios_base *)&local_27c;
  local_27c = _vftable__exref;
  std::ios_base::_Ios_base_dtor(local_224);
LAB_100158e8:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10015910 at 10015910

void FUN_10015910(int param_1,int param_2)

{
  int iVar1;
  uint uStack_94;
  undefined **local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c129;
  local_10 = ExceptionList;
  uStack_94 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_94;
  ExceptionList = &local_10;
  local_54 = 0;
  local_50 = 0;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_4c = 0;
  local_8 = 1;
  local_18 = uStack_94;
  iVar1 = FUN_1000f3d0((void *)(param_1 + 0x10c),param_2);
  local_50 = 0x7f;
  FUN_10008d20(&local_58,iVar1);
  local_8 = 0xffffffff;
  local_58 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_1001598d at 1001598d

void FUN_1001598d(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x54) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x100159b6;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@100159bc at 100159bc

undefined1 * Catch_100159bc(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x74);
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0xd8);
  FUN_1000efe0(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000fa90(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_10015410(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000da70((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    FUN_10008d20((void *)(unaff_EBP + -0x54),*(int *)(iVar1 + 4));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_10015a50;
}



// Function: Catch@10015a55 at 10015a55

undefined1 * Catch_10015a55(void)

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
    iVar2 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x5c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    FUN_10008d20((void *)(unaff_EBP + -0x54),*(int *)(*(int *)(unaff_EBP + -0x5c) + 4));
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0xd8);
  uVar5 = 0x82;
  pcVar4 = "VehicleClassificationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10008440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x48),
               *(undefined4 *)(unaff_EBP + -0x48),uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_1000efe0(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000fa90(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_10015410(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000da70((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_10015b1b;
}



// Function: Catch@10015b20 at 10015b20

undefined4 Catch_10015b20(void)

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
    iVar2 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_10008600(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      uVar3 = FUN_1001598d();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0xd8);
  uVar5 = 0x82;
  pcVar4 = "VehicleClassificationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10008440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_1000efe0(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000fa90(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_10015410(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000da70((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::exception::~exception((exception *)(unaff_EBP + -0x80));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10015c12;
}



// Function: Catch@10015c17 at 10015c17

undefined * Catch_10015c17(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x54);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x48) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x50) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x50) = 1;
      FUN_10008600(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x4c));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x58) + 0xd8);
  uVar7 = 0x82;
  pcVar6 = "VehicleClassificationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10008440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000efe0(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000fa90(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_10015410(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000da70((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_1001598d;
}



// Function: FUN_10015d00 at 10015d00

/* WARNING: Removing unreachable block (ram,0x10015d6c) */
/* WARNING: Removing unreachable block (ram,0x10015dca) */

void FUN_10015d00(int *param_1,wchar_t *param_2)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c198;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1[0x41] != 0) {
    local_8 = 1;
    (*(code *)**(undefined4 **)param_1[0xe])();
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
    FUN_10016ed0((void *)param_1[0x41],(int *)0x0);
    piVar1 = (int *)(**(code **)(*param_1 + 0x4c))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
    local_8 = CONCAT31((int3)((uint)local_8 >> 8),1);
    FUN_10016f40((void *)param_1[0x41],piVar1);
  }
  local_8 = 0xffffffff;
  FUN_10014ef0(param_1,param_2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10015df0 at 10015df0

void __fastcall FUN_10015df0(void *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)((int)param_1 + -0xec) + 0x4c))(1);
  if (*(int *)((int)param_1 + 8) != iVar1) {
    Ordinal_30((int)param_1 + 8,iVar1);
  }
  iVar1 = (**(code **)(*(int *)((int)param_1 + -0xec) + 0x4c))(2);
  if (*(int *)((int)param_1 + 0xc) != iVar1) {
    Ordinal_30((int)param_1 + 0xc,iVar1);
  }
  FUN_100151e0(param_1);
  return;
}



// Function: FUN_10015e60 at 10015e60

void FUN_10015e60(int param_1)

{
  uint uStack_94;
  undefined **local_5c;
  undefined1 local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c209;
  local_10 = ExceptionList;
  uStack_94 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_94;
  ExceptionList = &local_10;
  local_4c = param_1;
  local_58 = 0;
  local_5c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_50 = -0x7fffbffb;
  local_8 = 1;
  local_54 = 0x7f;
  local_18 = uStack_94;
  FUN_10008d20(&local_5c,-0x7fffbffb);
  local_8 = 0;
  if (local_50 < 0) {
    FUN_1000f3d0((void *)(local_4c + -4),0);
  }
  local_8 = 0xffffffff;
  local_5c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10015ed0 at 10015ed0

void FUN_10015ed0(void)

{
  uint unaff_EBP;
  undefined4 uStack0000000c;
  
  if (*(int *)(unaff_EBP - 0x4c) < 0) {
    FUN_1000f3d0((void *)(*(int *)(unaff_EBP - 0x48) + -4),0);
  }
  *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
  *(undefined ***)(unaff_EBP - 0x58) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x10015f09;
  __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



// Function: Catch@10015f0f at 10015f0f

undefined1 * Catch_10015f0f(void)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int unaff_EBP;
  int *this;
  
  iVar1 = *(int *)(unaff_EBP + -0x74);
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x38);
  FUN_1000efe0(this,*(undefined4 *)(iVar1 + 0xc));
  FUN_1000fa90(this);
  piVar3 = (int *)(iVar1 + 0x10);
  if (7 < *(uint *)(iVar1 + 0x24)) {
    piVar3 = (int *)*piVar3;
  }
  FUN_10015410(this,*(long *)(iVar1 + 4),*(long *)(iVar1 + 8),piVar3,*(wchar_t **)(iVar1 + 0x2c));
  FUN_1000da70((int)this);
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar4 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    FUN_10008d20((void *)(unaff_EBP + -0x58),*(int *)(iVar1 + 4));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_10015f9d;
}



// Function: Catch@10015fa2 at 10015fa2

undefined1 * Catch_10015fa2(void)

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
    iVar2 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(unaff_EBP + -0x5c) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    FUN_10008d20((void *)(unaff_EBP + -0x58),*(int *)(*(int *)(unaff_EBP + -0x5c) + 4));
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x38);
  uVar5 = 0x1de;
  pcVar4 = "VehicleClassificationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10008440((void *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x4c),
               *(undefined4 *)(unaff_EBP + -0x4c),uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_1000efe0(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000fa90(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_10015410(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000da70((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &LAB_10016068;
}



// Function: Catch@1001606d at 1001606d

undefined4 Catch_1001606d(void)

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
    iVar2 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    *(undefined4 *)(iVar2 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_10008600(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      uVar3 = FUN_10015ed0();
      return uVar3;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x38);
  uVar5 = 0x1de;
  pcVar4 = "VehicleClassificationPageImpl.cpp";
  uVar3 = (**(code **)(*this + 4))();
  FUN_10008440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar3,(int *)pcVar4,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_1000efe0(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000fa90(this);
  iVar2 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar2 = unaff_EBP + -0x34;
  }
  FUN_10015410(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar2,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000da70((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  std::exception::~exception((exception *)(unaff_EBP + -0x80));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10016160;
}



// Function: Catch@10016165 at 10016165

undefined * Catch_10016165(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int unaff_EBP;
  int *this;
  char *pcVar6;
  undefined4 uVar7;
  
  bVar2 = type_info::operator==
                    ((type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor,
                     (type_info *)
                     &CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::
                      RTTI_Type_Descriptor);
  if (bVar2) {
    iVar3 = FUN_1000b870((void *)(unaff_EBP + -0x70),unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(iVar3 + 0xc) = 0x8000ffff;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x70) =
         CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x4c) = 0x8000ffff;
    if (*(char *)(unaff_EBP + -0x54) == '\0') {
      *(undefined1 *)(unaff_EBP + -0x54) = 1;
      FUN_10008600(0x8000ffff,*(undefined4 *)(unaff_EBP + -0x50));
      pcVar1 = (code *)swi(3);
      puVar5 = (undefined *)(*pcVar1)();
      return puVar5;
    }
  }
  this = (int *)(*(int *)(unaff_EBP + -0x48) + -0x38);
  uVar7 = 0x1de;
  pcVar6 = "VehicleClassificationPageImpl.cpp";
  uVar4 = (**(code **)(*this + 4))();
  FUN_10008440((void *)(unaff_EBP + -0x44),0x8000ffff,0x8000ffff,uVar4,(int *)pcVar6,uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_1000efe0(this,*(undefined4 *)(unaff_EBP + -0x38));
  FUN_1000fa90(this);
  iVar3 = *(int *)(unaff_EBP + -0x34);
  if (*(uint *)(unaff_EBP + -0x20) < 8) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_10015410(this,*(long *)(unaff_EBP + -0x40),*(long *)(unaff_EBP + -0x3c),iVar3,
               *(wchar_t **)(unaff_EBP + -0x18));
  FUN_1000da70((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return FUN_10015ed0;
}



// Function: FUN_10016250 at 10016250

void FUN_10016250(int param_1,undefined4 param_2,undefined4 *param_3)

{
  if (param_1 == 0) {
    FUN_10014670(0,param_2,param_3);
    return;
  }
  FUN_100150d0(param_1,param_2,param_3);
  return;
}



// Function: FUN_10016280 at 10016280

void __thiscall FUN_10016280(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = param_1;
  uVar1 = Ordinal_15(8,1,&local_c);
  *(undefined4 *)((int)this + 0x10) = uVar1;
  return;
}



// Function: FUN_100162b0 at 100162b0

void __thiscall FUN_100162b0(void *this,char *param_1,undefined4 param_2)

{
  exception local_10 [12];
  
  if ((*(int *)((int)this + 0x10) != 0) && (*(short *)((int)this + 8) != 0)) {
    if ((int)param_1 < *(int *)(*(int *)((int)this + 0x10) + 0x10)) {
                    /* WARNING: Load size is inaccurate */
      (**(code **)(*this + 8))(&param_1,param_2);
      return;
    }
    FUN_10004a40(local_10,"index is out of range");
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_10,(ThrowInfo *)&DAT_10027fd4);
  }
  param_1 = "array not initialized";
  std::exception::exception(local_10,&param_1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_10,(ThrowInfo *)&DAT_10027fc4);
}



// Function: FUN_10016330 at 10016330

void __thiscall FUN_10016330(void *this,char *param_1)

{
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c251;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((int)param_1 < *(int *)(*(int *)((int)this + 0x10) + 0x10)) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(*this + 4))(&param_1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
    ExceptionList = local_10;
    return;
  }
  param_1 = "index is out of range";
  std::exception::exception((exception *)local_1c,&param_1);
  local_1c[0] = std::out_of_range::vftable;
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_1c,(ThrowInfo *)&DAT_10027fd4);
}



// Function: FUN_100163d0 at 100163d0

void __thiscall FUN_100163d0(void *this,uint param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c278;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  local_8 = 0;
  Ordinal_6(0,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  puVar1 = (undefined2 *)FUN_1000b660(param_1);
  if (puVar1 != (undefined2 *)0x0) {
    uVar2 = Ordinal_4(puVar1 + 1,*puVar1);
  }
  (**(code **)(**(int **)((int)this + 4) + 0x28))(*(int **)((int)this + 4),uVar2);
  local_8 = 0xffffffff;
  Ordinal_6(uVar2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016460 at 10016460

undefined4 __thiscall FUN_10016460(void *this,uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c2a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  local_14 = 0;
  local_8 = 0;
  Ordinal_6(0,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  local_14 = 0;
  puVar1 = (undefined2 *)FUN_1000b660(param_1);
  if (puVar1 != (undefined2 *)0x0) {
    uVar2 = Ordinal_4(puVar1 + 1,*puVar1);
  }
  local_14 = uVar2;
  (**(code **)(**(int **)((int)this + 4) + 0x50))
            (*(int **)((int)this + 4),uVar2,param_2,param_3,&local_18);
  local_8 = 0xffffffff;
  Ordinal_6(uVar2);
  ExceptionList = local_10;
  return local_18;
}



// Function: FUN_10016500 at 10016500

void __thiscall FUN_10016500(void *this,uint param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c2e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(**(int **)((int)this + 4) + 0x30))
            (*(int **)((int)this + 4),DAT_10030e10 ^ (uint)&stack0xfffffffc);
  uVar2 = 0;
  local_14 = 0;
  local_8 = 0;
  Ordinal_6(0);
  local_14 = 0;
  puVar1 = (undefined2 *)FUN_1000b660(param_1);
  if (puVar1 != (undefined2 *)0x0) {
    uVar2 = Ordinal_4(puVar1 + 1,*puVar1);
  }
  local_14 = uVar2;
  (**(code **)(**(int **)((int)this + 4) + 0x28))(*(int **)((int)this + 4),uVar2);
  local_8 = 0xffffffff;
  Ordinal_6(uVar2);
  uVar2 = 0;
  local_14 = 0;
  local_8 = 1;
  Ordinal_6(0);
  local_14 = 0;
  puVar1 = (undefined2 *)FUN_1000b660(param_1);
  if (puVar1 != (undefined2 *)0x0) {
    uVar2 = Ordinal_4(puVar1 + 1,*puVar1);
  }
  local_14 = uVar2;
  (**(code **)(**(int **)((int)this + 4) + 0x50))(*(int **)((int)this + 4),uVar2,0x30,0,local_18);
  local_8 = 0xffffffff;
  Ordinal_6(uVar2);
  ExceptionList = local_10;
  return;
}



// Function: FUN_100165f0 at 100165f0

void __fastcall FUN_100165f0(void *param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c2a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(**(int **)((int)param_1 + 4) + 0x44))
            (*(int **)((int)param_1 + 4),1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  uVar2 = 0;
  (**(code **)(**(int **)((int)param_1 + 4) + 0x38))(*(int **)((int)param_1 + 4),0);
  (**(code **)(**(int **)((int)param_1 + 4) + 0x48))(*(int **)((int)param_1 + 4),0);
  (**(code **)(**(int **)((int)param_1 + 4) + 0x40))(*(int **)((int)param_1 + 4),0);
  (**(code **)(**(int **)((int)param_1 + 4) + 0x4c))(*(int **)((int)param_1 + 4),0);
  (**(code **)(**(int **)((int)param_1 + 8) + 0x38))(*(int **)((int)param_1 + 8),&local_18);
  if (local_18 == -1) {
    local_14 = 0;
    local_8 = 0;
    Ordinal_6(0);
    local_14 = 0;
    puVar1 = (undefined2 *)FUN_1000b660(0x94);
    if (puVar1 != (undefined2 *)0x0) {
      uVar2 = Ordinal_4(puVar1 + 1,*puVar1);
    }
    local_14 = uVar2;
    (**(code **)(**(int **)((int)param_1 + 4) + 0x28))(*(int **)((int)param_1 + 4),uVar2);
    local_8 = 0xffffffff;
    Ordinal_6(uVar2);
    ExceptionList = local_10;
    return;
  }
  if (local_18 == 0) {
    uVar3 = 0xa7;
  }
  else {
    if (local_18 != 1) {
      ExceptionList = local_10;
      return;
    }
    uVar3 = 0xa8;
  }
  FUN_100163d0(param_1,uVar3);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016700 at 10016700

undefined4 __fastcall FUN_10016700(int param_1)

{
  Ordinal_24(*(undefined4 *)(param_1 + 0x10));
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return *(undefined4 *)(param_1 + 0x10);
}



// Function: FUN_10016720 at 10016720

undefined4 * __thiscall FUN_10016720(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c30b;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = safearray<enum_VehiclePurposeEnum,3>::vftable;
  Ordinal_8((undefined2 *)((int)this + 8),uVar2);
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  if (param_1 != 0) {
    *(undefined2 *)((int)this + 8) = 0x2003;
    *(int *)((int)this + 0x10) = param_1;
    Ordinal_23(param_1,(undefined4 *)((int)this + 0x18));
    ExceptionList = local_10;
    return (undefined4 *)this;
  }
  FUN_10018b30(0x80004003);
  pcVar1 = (code *)swi(3);
  puVar3 = (undefined4 *)(*pcVar1)();
  return puVar3;
}



// Function: FUN_100167b0 at 100167b0

undefined4 * __fastcall FUN_100167b0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c343;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = safearray<wchar_t*,8>::vftable;
  Ordinal_8(param_1 + 2,uVar1);
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0x2008;
  *param_1 = bstrarrayT<wchar_t*>::vftable;
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10016830 at 10016830

undefined4 * __thiscall FUN_10016830(void *this,int param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c30b;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = safearray<enum_GVWRangeEnum,3>::vftable;
  Ordinal_8((undefined2 *)((int)this + 8),uVar2);
  local_8 = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  if (param_1 != 0) {
    *(undefined2 *)((int)this + 8) = 0x2003;
    *(int *)((int)this + 0x10) = param_1;
    Ordinal_23(param_1,(undefined4 *)((int)this + 0x18));
    ExceptionList = local_10;
    return (undefined4 *)this;
  }
  FUN_10018b30(0x80004003);
  pcVar1 = (code *)swi(3);
  puVar3 = (undefined4 *)(*pcVar1)();
  return puVar3;
}



// Function: FUN_100168c0 at 100168c0

undefined4 * __thiscall FUN_100168c0(void *this,int *param_1,int *param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c3b9;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  *(undefined4 *)this = 0;
  *(int **)((int)this + 4) = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1,uVar1);
  }
  local_8._0_1_ = 3;
  *(int **)((int)this + 8) = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016980 at 10016980

void __fastcall FUN_10016980(int *param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c3f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_10030e10 ^ (uint)&stack0xfffffffc,param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_100169d0 at 100169d0

undefined4 __fastcall FUN_100169d0(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uStack_8c;
  undefined4 local_7c [4];
  int local_6c;
  undefined4 local_5c [8];
  undefined **local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001c430;
  local_10 = ExceptionList;
  uStack_8c = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_8c;
  ExceptionList = &local_10;
  local_38 = 0;
  local_34 = 0;
  local_3c = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_30 = 0x80004005;
  local_8 = 1;
  uStack_7 = 0;
  local_1c = 0;
  local_2c = param_1;
  (**(code **)(**(int **)((int)param_1 + 4) + 0x34))(*(int **)((int)param_1 + 4),&local_1c);
  local_28 = local_1c;
  if ((local_1c == 1) || (local_1c == 2)) {
    (**(code **)(**(int **)((int)param_1 + 8) + 0x48))
              (*(int **)((int)param_1 + 8),local_1c,&local_24);
    FUN_10016830(local_7c,local_24);
    local_8 = 2;
    FUN_100167b0(local_5c);
    _local_8 = CONCAT31(uStack_7,3);
    FUN_10016280(local_5c,*(undefined4 *)(local_6c + 0x10));
    for (local_18 = 0; pcVar4 = (char *)(int)(short)local_18,
        (int)pcVar4 < *(int *)(local_6c + 0x10); local_18 = local_18 + 1) {
      iVar2 = FUN_10016330(local_7c,pcVar4);
      local_20 = 0;
      local_8 = 4;
      FUN_1000c0c0(&local_20,iVar2 + 0x71);
      uVar3 = local_20;
      FUN_100162b0(local_5c,pcVar4,local_20);
      _local_8 = CONCAT31(uStack_7,3);
      Ordinal_6(uVar3);
    }
    piVar1 = *(int **)((int)param_1 + 4);
    iVar2 = *piVar1;
    uVar3 = FUN_10016700((int)local_5c);
    (**(code **)(iVar2 + 0x24))(piVar1,uVar3);
    (**(code **)(**(int **)((int)param_1 + 4) + 0x40))(*(int **)((int)param_1 + 4),0);
    (**(code **)(**(int **)((int)param_1 + 4) + 0x48))(*(int **)((int)param_1 + 4),1);
    (**(code **)(**(int **)((int)param_1 + 8) + 0x2c))(*(int **)((int)param_1 + 8),local_28);
    FUN_100163d0(param_1,0x95);
    local_8 = 2;
    FUN_1000c300(local_5c);
    local_8 = 1;
    FUN_10004c60(local_7c);
  }
  else {
    (**(code **)(**(int **)((int)param_1 + 4) + 0x48))(*(int **)((int)param_1 + 4),0);
  }
  (**(code **)(**(int **)((int)param_1 + 4) + 0x4c))(*(int **)((int)param_1 + 4),0);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@10016b6f at 10016b6f

undefined4 Catch_10016b6f(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(*(int *)(unaff_EBP + -0x28) + 4);
  (**(code **)(*piVar1 + 0x5c))(piVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x10016b4b;
}



// Function: FUN_10016b90 at 10016b90

void __thiscall FUN_10016b90(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined **local_44 [2];
  short local_3c [4];
  int local_34;
  undefined4 local_2c;
  char *local_24;
  undefined **local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c491;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_44[0] = safearray<wchar_t*,8>::vftable;
  local_24 = (char *)this;
  Ordinal_8(local_3c,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  iVar5 = 0;
  local_2c = 0;
  local_3c[0] = 0x2008;
  local_44[0] = bstrarrayT<wchar_t*>::vftable;
  local_8 = 2;
  local_1c = *(undefined4 *)(param_1[4] + 0x10);
  local_18 = 0;
  local_34 = Ordinal_15(8,1,&local_1c);
  local_14 = 0;
  if (0 < *(int *)(param_1[4] + 0x10)) {
    do {
      local_18 = iVar5;
      iVar2 = (**(code **)(*param_1 + 4))(&local_18);
      local_8 = CONCAT31(local_8._1_3_,5);
      Ordinal_6(0);
      puVar3 = (undefined2 *)FUN_1000b660(iVar2 + 0x6e);
      if (puVar3 == (undefined2 *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = Ordinal_4(puVar3 + 1,*puVar3);
      }
      if ((local_34 == 0) || (local_3c[0] == 0)) {
        local_24 = "array not initialized";
        std::exception::exception((exception *)&local_20,&local_24);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fc4);
      }
      if (*(int *)(local_34 + 0x10) <= iVar5) {
        local_24 = "index is out of range";
        std::exception::exception((exception *)&local_20,&local_24);
        local_20 = std::out_of_range::vftable;
        local_8 = CONCAT31((int3)((uint)local_8 >> 8),5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_20,(ThrowInfo *)&DAT_10027fd4);
      }
      local_18 = iVar5;
      FUN_1000d340(local_44,&local_18,uVar4);
      local_8 = CONCAT31(local_8._1_3_,2);
      Ordinal_6(0);
      local_14 = local_14 + 1;
      iVar5 = (int)(short)local_14;
      this = local_24;
    } while (iVar5 < *(int *)(param_1[4] + 0x10));
  }
  piVar1 = *(int **)((int)this + 4);
  Ordinal_24(local_34);
  local_3c[0] = 0;
  local_2c = 0;
  (**(code **)(*piVar1 + 0x20))(piVar1,local_34);
  (**(code **)(**(int **)((int)this + 4) + 0x38))(*(int **)((int)this + 4),0);
  local_44[0] = safearray<wchar_t*,8>::vftable;
  local_8 = 0xffffffff;
  Ordinal_9(local_3c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016da0 at 10016da0

undefined4 * __thiscall FUN_10016da0(void *this,undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c4c0;
  local_10 = ExceptionList;
  uVar1 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  local_8 = 1;
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(param_1,&DAT_100235f8,this,uVar1);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}



// Function: FUN_10016e10 at 10016e10

void __fastcall FUN_10016e10(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c519;
  local_10 = ExceptionList;
  uVar2 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  if (*(int *)(param_1 + 8) != 0) {
    Ordinal_30((int *)(param_1 + 8),0,uVar2);
  }
  if (*(int *)(param_1 + 4) != 0) {
    Ordinal_30((int *)(param_1 + 4),0,uVar2);
  }
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 1;
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016ed0 at 10016ed0

void __thiscall FUN_10016ed0(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c550;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((*(int *)((int)this + 8) == 0) && (*(int **)((int)this + 8) != param_1)) {
    Ordinal_30((int *)((int)this + 8),param_1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016f40 at 10016f40

void __thiscall FUN_10016f40(void *this,int *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c550;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((*(int *)((int)this + 0xc) == 0) && (*(int **)((int)this + 0xc) != param_1)) {
    Ordinal_30((int *)((int)this + 0xc),param_1,DAT_10030e10 ^ (uint)&stack0xfffffffc);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: FUN_10016fb0 at 10016fb0

void __thiscall FUN_10016fb0(void *this,long param_1,int param_2)

{
  int *piVar1;
  wchar_t *_Src;
  LONG LVar2;
  int *piVar3;
  undefined4 uVar4;
  int *local_218;
  wchar_t local_214;
  undefined1 local_212 [510];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c586;
  local_10 = ExceptionList;
  local_14 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_214 = L'\0';
  memset(local_212,0,0x1fe);
  _ltow_s(param_1,&local_214,0x100,10);
  wcscat_s(&local_214,0x100,L" ");
  piVar1 = FUN_10005730(&local_218,param_2);
  local_8 = 0;
  if ((undefined4 *)*piVar1 == (undefined4 *)0x0) {
    _Src = (wchar_t *)0x0;
  }
  else {
    _Src = *(wchar_t **)*piVar1;
  }
  wcscat_s(&local_214,0x100,_Src);
  local_8 = 0xffffffff;
  if (local_218 != (int *)0x0) {
    LVar2 = InterlockedDecrement(local_218 + 2);
    if ((LVar2 == 0) && (local_218 != (int *)0x0)) {
      if (*local_218 != 0) {
        Ordinal_6(*local_218);
      }
      if ((void *)local_218[1] != (void *)0x0) {
        operator_delete__((void *)local_218[1]);
      }
      operator_delete(local_218);
    }
    local_218 = (int *)0x0;
  }
  piVar1 = *(int **)((int)this + 4);
  piVar3 = FUN_10005730(&local_218,(int)&local_214);
  local_8 = 1;
  if ((undefined4 *)*piVar3 == (undefined4 *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)*piVar3;
  }
  (**(code **)(*piVar1 + 0x1c))(piVar1,uVar4);
  piVar1 = local_218;
  local_8 = 0xffffffff;
  if (local_218 != (int *)0x0) {
    LVar2 = InterlockedDecrement(local_218 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    local_218 = (int *)0x0;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



// Function: FUN_10017160 at 10017160

void __fastcall FUN_10017160(void *param_1)

{
  uint uStack_3c;
  long local_2c;
  int local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c5b0;
  local_10 = ExceptionList;
  uStack_3c = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = param_1;
  (**(code **)(**(int **)((int)param_1 + 8) + 0x20))(*(int **)((int)param_1 + 8),&local_2c);
  (**(code **)(**(int **)((int)param_1 + 8) + 0x38))(*(int **)((int)param_1 + 8),&local_18);
  (**(code **)(**(int **)((int)param_1 + 8) + 0x28))(*(int **)((int)param_1 + 8),local_20);
  (**(code **)(**(int **)((int)param_1 + 8) + 0x30))(*(int **)((int)param_1 + 8),local_24);
  FUN_10016fb0(param_1,local_2c,local_28);
  if (local_2c < 0) {
    (**(code **)(**(int **)((int)param_1 + 4) + 0x30))(*(int **)((int)param_1 + 4));
    if (local_18 == -1) {
      FUN_100163d0(param_1,0x7f);
    }
    FUN_100163d0(param_1,0x7d);
  }
  else {
    FUN_100165f0(param_1);
  }
  ExceptionList = local_10;
  return;
}



// Function: Catch@1001722d at 1001722d

undefined4 Catch_1001722d(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(*(int *)(unaff_EBP + -0x18) + 4);
  (**(code **)(*piVar1 + 0x5c))(piVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x1001721b;
}



// Function: FUN_10017250 at 10017250

undefined4 __fastcall FUN_10017250(void *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  undefined4 *puVar5;
  uint uVar6;
  uint uStack_98;
  int local_88 [8];
  undefined4 local_68 [8];
  undefined **local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  long local_38;
  int local_34;
  void *local_30;
  undefined1 *local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  short local_1c;
  short local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_1001c60b;
  local_10 = ExceptionList;
  uStack_98 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_98;
  ExceptionList = &local_10;
  local_44 = 0;
  local_40 = 0;
  local_48 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_3c = 0x80004005;
  local_8 = 1;
  uStack_7 = 0;
  local_30 = param_1;
  iVar3 = (**(code **)(**(int **)((int)param_1 + 4) + 0x2c))();
  FUN_10008d20(&local_48,iVar3);
  iVar3 = (**(code **)(**(int **)((int)param_1 + 8) + 0x1c))();
  FUN_10008d20(&local_48,iVar3);
  if (local_18 == -1) {
    iVar3 = (**(code **)(**(int **)((int)param_1 + 8) + 0x4c))();
    FUN_10008d20(&local_48,iVar3);
    iVar3 = (**(code **)(**(int **)((int)param_1 + 8) + 0x20))
                      (*(int **)((int)param_1 + 8),&local_38);
    FUN_10008d20(&local_48,iVar3);
    FUN_10016fb0(param_1,local_38,local_34);
    local_2c = &stack0xffffff54;
    puVar5 = extraout_ECX;
    FUN_1000b980(&stack0xffffff54,(int *)((int)param_1 + 0xc));
    local_8 = 1;
    iVar3 = FUN_10017980(puVar5);
    if (iVar3 == 3) {
      ExceptionList = local_10;
      return 0;
    }
    if (local_1c == -1) {
      if (0 < local_38) {
        local_24 = 0;
        iVar3 = (**(code **)(**(int **)((int)param_1 + 8) + 0x44))();
        FUN_10008d20(&local_48,iVar3);
        FUN_10016720(local_88,local_24);
        local_8 = 3;
        FUN_10016b90(param_1,local_88);
        local_20 = 0;
        local_8 = 4;
        FUN_100167b0(local_68);
        local_8 = 5;
        FUN_10016280(local_68,1);
        FUN_1000c0c0(&local_20,0x71);
        FUN_100162b0(local_68,(char *)0x0,local_20);
        piVar1 = *(int **)((int)param_1 + 4);
        iVar3 = *piVar1;
        uVar4 = FUN_10016700((int)local_68);
        (**(code **)(iVar3 + 0x24))(piVar1,uVar4);
        (**(code **)(**(int **)((int)param_1 + 4) + 0x40))(*(int **)((int)param_1 + 4),0);
        (**(code **)(**(int **)((int)param_1 + 4) + 0x48))(*(int **)((int)param_1 + 4),0);
        FUN_10017160(param_1);
        local_8 = 4;
        FUN_1000c300(local_68);
        local_8 = 3;
        Ordinal_6(local_20);
        _local_8 = CONCAT31(uStack_7,1);
        FUN_10004cb0(local_88);
        ExceptionList = local_10;
        return 0;
      }
      local_2c = (undefined1 *)0x0;
      local_8 = 6;
      FUN_1000c0c0(&local_2c,0x66);
      local_28 = 0;
      local_8 = 7;
      FUN_1000c0c0(&local_28,0x7d);
      uVar4 = local_28;
      puVar2 = local_2c;
      (**(code **)(**(int **)((int)param_1 + 4) + 0x60))
                (*(int **)((int)param_1 + 4),local_2c,local_28);
      (**(code **)(**(int **)((int)param_1 + 4) + 0x30))(*(int **)((int)param_1 + 4));
      FUN_100163d0(param_1,0x7d);
      local_8 = 6;
      Ordinal_6(uVar4);
      _local_8 = CONCAT31(uStack_7,1);
      Ordinal_6(puVar2);
      ExceptionList = local_10;
      return 0;
    }
    uVar6 = 0x97;
  }
  else {
    uVar6 = 0x7e;
  }
  FUN_10016500(param_1,uVar6);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100174c1 at 100174c1

undefined4 Catch_100174c1(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(*(int *)(unaff_EBP + -0x2c) + 4);
  (**(code **)(*piVar1 + 0x5c))(piVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001749d;
}



// Function: FUN_100174e0 at 100174e0

int __fastcall FUN_100174e0(void *param_1)

{
  int iVar1;
  uint uStack_58;
  undefined4 local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  void *local_24;
  int *local_20;
  int *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c668;
  local_10 = ExceptionList;
  uStack_58 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_58;
  ExceptionList = &local_10;
  local_28 = -0x7fffbffb;
  local_8 = 0;
  local_24 = param_1;
  iVar1 = FUN_10016460(param_1,0x3f3,0x30,1);
  if (iVar1 == 1) {
    local_28 = (**(code **)(**(int **)((int)param_1 + 8) + 0x40))(*(int **)((int)param_1 + 8));
    if (local_28 == 0) {
      FUN_10005f50(local_48);
      local_1c = (int *)0x0;
      local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
      local_8._0_1_ = 4;
      iVar1 = (**(code **)**(undefined4 **)((int)param_1 + 0xc))
                        (*(undefined4 **)((int)param_1 + 0xc),&DAT_100235e8,&local_1c);
      FUN_10008d20(local_48,iVar1);
      local_18 = (undefined4 *)0x0;
      local_8._0_1_ = 6;
      iVar1 = (**(code **)(*local_1c + 0x24))(local_1c,DAT_10030f18,&local_18);
      FUN_10008d20(local_48,iVar1);
      FUN_10016da0(&local_20,local_18);
      local_38 = CONCAT22(local_38._2_2_,3);
      local_30 = 0x1e;
      local_8._0_1_ = 8;
      iVar1 = (**(code **)(*local_20 + 0x3c))(local_20,local_38,local_34,0x1e,local_2c);
      FUN_10008d20(local_48,iVar1);
      local_8._0_1_ = 7;
      Ordinal_9(&local_38);
      local_8._0_1_ = 6;
      FUN_10016980((int *)&local_20);
      local_8._0_1_ = 4;
      FUN_10005400((int *)&local_18);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_10005400((int *)&local_1c);
      local_8 = 1;
      iVar1 = FUN_10017649();
      return iVar1;
    }
    FUN_10016460(param_1,0x8d,0x10,0);
  }
  ExceptionList = local_10;
  return local_28;
}



// Function: Catch@10017639 at 10017639

undefined * Catch_10017639(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  return &DAT_10017646;
}



// Function: FUN_10017649 at 10017649

undefined4 FUN_10017649(void)

{
  int unaff_EBP;
  void *unaff_ESI;
  
  FUN_10016460(unaff_ESI,0x92,0x40,0);
  FUN_100165f0(unaff_ESI);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined ***)(unaff_EBP + -0x44) =
       CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x24);
}



// Function: Catch@1001769a at 1001769a

undefined4 Catch_1001769a(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(*(int *)(unaff_EBP + -0x20) + 4);
  (**(code **)(*piVar1 + 0x5c))(piVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  return 0x10017683;
}



// Function: FUN_100176c0 at 100176c0

undefined4 __fastcall FUN_100176c0(void *param_1)

{
  int iVar1;
  uint uVar2;
  uint uStack_40;
  undefined **local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c698;
  local_10 = ExceptionList;
  uStack_40 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_40;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = 0;
  local_30 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_24 = 0x80004005;
  local_8 = 1;
  local_18 = 0;
  local_20 = param_1;
  (**(code **)(**(int **)((int)param_1 + 4) + 0x3c))(*(int **)((int)param_1 + 4),&local_18);
  iVar1 = local_18;
  if (local_18 == 0) {
    (**(code **)(**(int **)((int)param_1 + 4) + 0x4c))(*(int **)((int)param_1 + 4),0);
    uVar2 = 0x95;
  }
  else {
    (**(code **)(**(int **)((int)param_1 + 8) + 0x28))(*(int **)((int)param_1 + 8),&local_1c);
    if (local_1c == 1) {
      iVar1 = (local_18 != 1) + 1;
    }
    else if (local_1c == 2) {
      iVar1 = (local_18 != 1) + 3;
    }
    else {
      FUN_10008d20(&local_30,-0x7ffcffff);
    }
    (**(code **)(**(int **)((int)param_1 + 8) + 0x34))(*(int **)((int)param_1 + 8),iVar1);
    (**(code **)(**(int **)((int)param_1 + 4) + 0x4c))(*(int **)((int)param_1 + 4),1);
                    /* WARNING: Could not find normalized switch variable to match jumptable */
    switch(iVar1) {
    case 3:
      uVar2 = 0x7a;
      break;
    case 5:
                    /* WARNING: This code block may not be properly labeled as switch case */
      uVar2 = 0x7c;
      break;
    default:
      goto switchD_1001778d_default;
    }
  }
  FUN_100163d0(param_1,uVar2);
switchD_1001778d_default:
  ExceptionList = local_10;
  return local_24;
}



// Function: Catch@100177e9 at 100177e9

undefined4 Catch_100177e9(void)

{
  int *piVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x20) = 0x80004005;
  if (*(char *)(unaff_EBP + -0x28) == '\0') {
    *(undefined1 *)(unaff_EBP + -0x28) = 1;
    FUN_10008600(0x80004005,*(undefined4 *)(unaff_EBP + -0x24));
  }
  piVar1 = *(int **)(*(int *)(unaff_EBP + -0x1c) + 4);
  (**(code **)(*piVar1 + 0x5c))(piVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100177c4;
}



// Function: FUN_10017840 at 10017840

undefined4 __thiscall
FUN_10017840(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uStack_34;
  undefined **local_24;
  undefined1 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c6c8;
  local_10 = ExceptionList;
  uStack_34 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  local_20 = 0;
  local_1c = 0;
  local_24 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_18 = 0x80004005;
  local_8 = 1;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x54))
                    (*(int **)((int)this + 4),param_1,param_2,param_3);
  FUN_10008d20(&local_24,iVar1);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@100178cf at 100178cf

undefined4 Catch_100178cf(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x100178ab;
}



// Function: FUN_100178e0 at 100178e0

undefined4 __thiscall
FUN_100178e0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uStack_34;
  undefined **local_24;
  undefined1 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001c6f8;
  local_10 = ExceptionList;
  uStack_34 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  local_20 = 0;
  local_1c = 0;
  local_24 = CSmartResult<struct_HRESULTPolicy<struct_ErrorCallbackClass>_>::vftable;
  local_18 = 0x80004005;
  local_8 = 1;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x58))
                    (*(int **)((int)this + 4),param_1,param_2,param_3);
  FUN_10008d20(&local_24,iVar1);
  ExceptionList = local_10;
  return 0;
}



// Function: Catch@1001796f at 1001796f

undefined4 Catch_1001796f(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return 0x1001794b;
}



// Function: FUN_10017980 at 10017980

void FUN_10017980(undefined4 *param_1)

{
  uint3 uVar1;
  uint *puVar2;
  uint uStack_54;
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_1001c748;
  local_10 = ExceptionList;
  uStack_54 = DAT_10030e10 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_54;
  ExceptionList = &local_10;
  local_18 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  puVar2 = &uStack_54;
  if (param_1 != (undefined4 *)0x0) {
    FUN_10009670(&local_28,param_1);
    uVar1 = local_8._1_3_;
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_24 != (int *)0x0) {
      local_30 = 7;
      local_34 = 0;
      local_44[0] = 0;
      local_8._0_1_ = 3;
      local_8._1_3_ = uVar1;
      FUN_100092b0(&local_20,local_24,(undefined4 *)local_44);
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_10002570((undefined4 *)local_44);
      if (local_1c != 0) {
        local_18 = FUN_10009460((int)&local_20);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_100058f0(&local_20);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_100059f0(&local_28);
    puVar2 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar2;
  local_8 = 0;
  FUN_10017a43();
  return;
}



// Function: Catch@10017a31 at 10017a31

undefined * Catch_10017a31(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  return &DAT_10017a3e;
}



// Function: FUN_10017a43 at 10017a43

void FUN_10017a43(void)

{
  int *piVar1;
  int unaff_EBP;
  int *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piVar1 = *(int **)(unaff_EBP + 8);
  if (piVar1 != unaff_ESI) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}



// Function: FUN_10017a70 at 10017a70

void __cdecl FUN_10017a70(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    param_3 = param_2;
  }
  Ordinal_147(param_3,param_2,param_4,0,param_1);
  return;
}



// Function: FUN_10017aa0 at 10017aa0

int * __cdecl FUN_10017aa0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c789;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (param_2 == (undefined4 *)0x0) {
    *param_1 = 0;
  }
  else {
    iVar1 = Ordinal_2(param_2,DAT_10030e10 ^ (uint)&stack0xfffffffc,0);
    *param_1 = iVar1;
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_10001690(0x8007000e);
    }
  }
  ExceptionList = local_10;
  return param_1;
}



// Function: FUN_10017b20 at 10017b20

void __cdecl FUN_10017b20(void *param_1,ushort *param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ushort *puVar5;
  int *piVar6;
  ushort *puVar7;
  
  puVar7 = param_2;
  if (7 < *(uint *)(param_2 + 10)) {
    puVar7 = *(ushort **)param_2;
  }
  puVar5 = puVar7;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  } while (uVar1 != 0);
  for (uVar3 = FUN_10005d50(param_1,puVar7,0,(int)puVar5 - (int)(puVar7 + 1) >> 1);
      uVar3 != 0xffffffff;
      uVar3 = FUN_10005d50(param_1,puVar5,param_3[4] + uVar3,(int)puVar7 - (int)(puVar5 + 1) >> 1))
  {
    piVar4 = FUN_100017e0(param_3);
    piVar6 = piVar4;
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 2);
    } while ((short)iVar2 != 0);
    FUN_10011cc0(param_1,uVar3,*(int **)(param_2 + 8),piVar4,(int)piVar6 - ((int)piVar4 + 2) >> 1);
    puVar5 = (ushort *)FUN_100017e0((undefined4 *)param_2);
    puVar7 = puVar5;
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
    } while (uVar1 != 0);
  }
  return;
}



// Function: FUN_10017be0 at 10017be0

undefined2 * __cdecl FUN_10017be0(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001c7c9;
  local_10 = ExceptionList;
  if (param_2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    return param_1;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  piVar2 = param_2;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 2);
  } while ((short)iVar1 != 0);
  FUN_10002d40(param_1,param_2,(int)piVar2 - ((int)param_2 + 2) >> 1);
  ExceptionList = local_10;
  return param_1;
}



// Function: FID_conflict:`vector_deleting_destructor' at 10017ca0

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



// Function: __security_check_cookie at 10017cec

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_10030e10) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___report_gsfailure();
}



// Function: __ArrayUnwind at 10017d2c

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



// Function: `eh_vector_destructor_iterator' at 10017d8a

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
  FUN_10017dd5();
  return;
}



// Function: FUN_10017dd5 at 10017dd5

void FUN_10017dd5(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// Function: __onexit at 10017df4

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
  
  local_8 = &DAT_1002b6a0;
  uStack_c = 0x10017e00;
  local_20[0] = DecodePointer(DAT_10031314);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_10031314);
    local_24 = DecodePointer(DAT_10031310);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_10031314 = EncodePointer(local_20[0]);
    DAT_10031310 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_10017e8c();
  }
  return p_Var1;
}



// Function: FUN_10017e8c at 10017e8c

void FUN_10017e8c(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 10017e95

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: `eh_vector_constructor_iterator' at 10017eb2

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
  FUN_10017eff();
  return;
}



// Function: FUN_10017eff at 10017eff

void FUN_10017eff(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + -0x1c),
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// Function: __alloca_probe_16 at 10017f60

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



// Function: __alloca_probe_8 at 10017f76

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



// Function: __CRT_INIT@12 at 10017fdf

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
    if (DAT_10030f38 < 1) {
      return 0;
    }
    DAT_10030f38 = DAT_10030f38 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10031308,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10031304 == 2) {
      param_2 = (int *)DecodePointer(DAT_10031314);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_10031310);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_10031314);
            piVar8 = (int *)DecodePointer(DAT_10031310);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_10031310 = (PVOID)encoded_null();
        DAT_10031314 = DAT_10031310;
      }
      DAT_10031304 = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_10031308,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_10031308,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_10031304 == 0) {
      DAT_10031304 = 1;
      iVar5 = initterm_e(&DAT_100227dc,&DAT_100227e4);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_10022414,&DAT_100227d8);
      DAT_10031304 = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_10031308,0);
    }
    if ((DAT_1003130c != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1003130c), BVar2 != 0)) {
      (*DAT_1003130c)(param_1,2,param_3);
    }
    DAT_10030f38 = DAT_10030f38 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 100181e9

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10018289) */
/* WARNING: Removing unreachable block (ram,0x10018236) */
/* WARNING: Removing unreachable block (ram,0x100182b6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_10030e20 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_10030f38 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(param_3,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_100044c0(param_3,(int)param_2);
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_100044c0(param_3,0);
      __CRT_INIT_12(param_3,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(param_3,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_100182f4();
  return local_20;
}



// Function: FUN_100182f4 at 100182f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100182f4(void)

{
  _DAT_10030e20 = 0xffffffff;
  return;
}



// Function: entry at 100182ff

void entry(int *param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: ___report_gsfailure at 10018322

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
  
  _DAT_10031058 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)(&stack0x00000000 == (undefined1 *)0x32c) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT((uint)&local_32c & 0xff) & 1U) == 0) * 4 |
       (uint)(&stack0xfffffffc < (undefined1 *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_1003105c = &stack0x00000004;
  _DAT_10030f98 = 0x10001;
  _DAT_10030f40 = 0xc0000409;
  _DAT_10030f44 = 1;
  local_32c = DAT_10030e10;
  local_328 = DAT_10030e14;
  _DAT_10030f4c = unaff_retaddr;
  _DAT_10031024 = in_GS;
  _DAT_10031028 = in_FS;
  _DAT_1003102c = in_ES;
  _DAT_10031030 = in_DS;
  _DAT_10031034 = unaff_EDI;
  _DAT_10031038 = unaff_ESI;
  _DAT_1003103c = unaff_EBX;
  _DAT_10031040 = in_EDX;
  _DAT_10031044 = in_ECX;
  _DAT_10031048 = in_EAX;
  _DAT_1003104c = unaff_EBP;
  DAT_10031050 = unaff_retaddr;
  _DAT_10031054 = in_CS;
  _DAT_10031060 = in_SS;
  DAT_10030f90 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&PTR_DAT_10024d04);
  if (DAT_10030f90 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// Function: __SEH_prolog4 at 10018430

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10030e10 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 10018475

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



// Function: __alloca_probe at 100184b0

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



// Function: __ValidateImageBase at 10018540

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



// Function: __FindPESection at 10018580

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



// Function: __IsNonwritableInCurrentImage at 100185d0

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
  
  puStack_10 = &LAB_10017f36;
  local_14 = ExceptionList;
  local_c = DAT_10030e10 ^ 0x1002b708;
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



// Function: ___security_init_cookie at 100186a4

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
  if ((DAT_10030e10 == 0xbb40e64e) || ((DAT_10030e10 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_10030e10 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_10030e10 == 0xbb40e64e) {
      DAT_10030e10 = 0xbb40e64f;
    }
    else if ((DAT_10030e10 & 0xffff0000) == 0) {
      DAT_10030e10 = DAT_10030e10 | (DAT_10030e10 | 0x4711) << 0x10;
    }
    DAT_10030e14 = ~DAT_10030e10;
  }
  else {
    DAT_10030e14 = ~DAT_10030e10;
  }
  return;
}



// Function: FUN_10018752 at 10018752

void __fastcall FUN_10018752(int *param_1)

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



// Function: FUN_10018796 at 10018796

int __fastcall FUN_10018796(int param_1)

{
  memset((void *)(param_1 + 0x10),0,0x18);
  return param_1;
}



// Function: FUN_100187af at 100187af

undefined4 * __fastcall FUN_100187af(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_10018796((int)param_1);
  *param_1 = 0;
  param_1[1] = 0x10000000;
  param_1[2] = &PTR_PTR_1002b788;
  param_1[3] = &DAT_1002b790;
  uVar1 = FUN_100043b0((LPCRITICAL_SECTION)(param_1 + 4));
  if ((int)uVar1 < 0) {
    DAT_10030e50 = 1;
  }
  else {
    *param_1 = 0x28;
  }
  return param_1;
}



// Function: FUN_100187f0 at 100187f0

void __fastcall FUN_100187f0(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// Function: FUN_1001880f at 1001880f

int __fastcall FUN_1001880f(int param_1)

{
  memset((void *)(param_1 + 0x14),0,0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return param_1;
}



// Function: FUN_10018834 at 10018834

void __fastcall FUN_10018834(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));
  FUN_100187f0((undefined4 *)(param_1 + 0x2c));
  return;
}



// Function: GetHInstanceAt at 1001884c

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
LAB_1001889a:
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
        goto LAB_1001889a;
      }
      pHVar2 = *(HINSTANCE__ **)(*(int *)(this + 0x2c) + param_1 * 4);
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return pHVar2;
}



// Function: FUN_100188a9 at 100188a9

undefined4 * __fastcall FUN_100188a9(undefined4 *param_1)

{
  uint uVar1;
  
  FUN_1001880f((int)param_1);
  *param_1 = 0x38;
  param_1[2] = 0x10000000;
  param_1[1] = 0x10000000;
  param_1[3] = 0xa00;
  param_1[4] = &DAT_10024d2c;
  uVar1 = FUN_100043b0((LPCRITICAL_SECTION)(param_1 + 5));
  if ((int)uVar1 < 0) {
    DAT_10030e50 = 1;
  }
  return param_1;
}



// Function: __FreeStdCallThunk_cmn at 100188e9

/* Library Function - Single Match
    void __cdecl __FreeStdCallThunk_cmn(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void __cdecl __FreeStdCallThunk_cmn(void *param_1)

{
  HANDLE hHeap;
  DWORD dwFlags;
  
  if (DAT_100312cc == (PSLIST_HEADER)0x1) {
    dwFlags = 0;
    hHeap = GetProcessHeap();
    HeapFree(hHeap,dwFlags,param_1);
    return;
  }
  InterlockedPushEntrySList(DAT_100312cc,(PSINGLE_LIST_ENTRY)param_1);
  return;
}



// Function: __InitializeThunkPool at 10018915

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
    DAT_100312cc = 1;
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
  DAT_100312cc = DVar4;
  return 1;
}



// Function: FreeStdCallThunk at 10018983

/* Library Function - Multiple Matches With Same Base Name
    void __stdcall __FreeStdCallThunk(void *)
    void __stdcall ATL::__FreeStdCallThunk(void *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2015 Release */

void FreeStdCallThunk(void *param_1)

{
  __FreeStdCallThunk_cmn(param_1);
  return;
}



// Function: __AllocStdCallThunk_cmn at 10018995

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
  
  if ((DAT_100312cc != (PSLIST_HEADER)0x0) || (iVar1 = __InitializeThunkPool(), iVar1 != 0)) {
    if (DAT_100312cc == (PSLIST_HEADER)0x1) {
      dwBytes = 0xd;
      dwFlags = 0;
      hHeap = GetProcessHeap();
      pvVar2 = HeapAlloc(hHeap,dwFlags,dwBytes);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
    }
    else {
      p_Var3 = InterlockedPopEntrySList(DAT_100312cc);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        return p_Var3;
      }
      p_Var3 = (PSINGLE_LIST_ENTRY)VirtualAlloc((LPVOID)0x0,0x1000,0x1000,0x40);
      if (p_Var3 != (PSINGLE_LIST_ENTRY)0x0) {
        p_Var4 = InterlockedPopEntrySList(DAT_100312cc);
        if (p_Var4 != (PSINGLE_LIST_ENTRY)0x0) {
          VirtualFree(p_Var3,0,0x8000);
          return p_Var4;
        }
        p_Var4 = p_Var3 + 0x3fc;
        do {
          InterlockedPushEntrySList(DAT_100312cc,p_Var3);
          p_Var3 = p_Var3 + 4;
        } while (p_Var3 < p_Var4);
        return p_Var3;
      }
    }
  }
  return (void *)0x0;
}



// Function: AtlWinModuleInit at 10018a38

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleInit(struct ATL::_ATL_WIN_MODULE70 *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

long ATL::AtlWinModuleInit(_ATL_WIN_MODULE70 *param_1)

{
  uint uVar1;
  
  if ((param_1 == (_ATL_WIN_MODULE70 *)0x0) || (*(int *)param_1 != 0x2c)) {
    uVar1 = 0x80070057;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    uVar1 = FUN_100043b0((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return uVar1;
}



// Function: FUN_10018a60 at 10018a60

int __fastcall FUN_10018a60(int param_1)

{
  memset((void *)(param_1 + 4),0,0x18);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return param_1;
}



// Function: AtlWinModuleTerm at 10018a85

/* Library Function - Single Match
    long __stdcall ATL::AtlWinModuleTerm(struct ATL::_ATL_WIN_MODULE70 *,struct HINSTANCE__ *)
   
   Library: Visual Studio 2010 Release */

long ATL::AtlWinModuleTerm(_ATL_WIN_MODULE70 *param_1,HINSTANCE__ *param_2)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  
  if (param_1 == (_ATL_WIN_MODULE70 *)0x0) {
LAB_10018a92:
    lVar2 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)param_1 != 0) {
      if (*(int *)param_1 != 0x2c) goto LAB_10018a92;
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
      FUN_10003f60((undefined4 *)(param_1 + 0x20));
      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
      *(undefined4 *)param_1 = 0;
    }
    lVar2 = 0;
  }
  return lVar2;
}



// Function: FUN_10018afb at 10018afb

_ATL_WIN_MODULE70 * __fastcall FUN_10018afb(_ATL_WIN_MODULE70 *param_1)

{
  long lVar1;
  
  FUN_10018a60((int)param_1);
  *(undefined4 *)param_1 = 0x2c;
  lVar1 = ATL::AtlWinModuleInit(param_1);
  if (lVar1 < 0) {
    DAT_10030e50 = 1;
    *(undefined4 *)param_1 = 0;
  }
  return param_1;
}



// Function: FUN_10018b30 at 10018b30

void FUN_10018b30(undefined4 param_1)

{
  (*(code *)PTR_FUN_10030e28)(param_1,0);
  return;
}



// Function: FUN_10018b80 at 10018b80

void FUN_10018b80(undefined4 param_1,undefined4 param_2)

{
  undefined **local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = &PTR__scalar_deleting_destructor__10024d3c;
  local_10 = param_1;
  local_c = param_2;
  local_8 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_14,(ThrowInfo *)&DAT_1002b724);
}



// Function: _com_error at 10018bc0

/* Library Function - Single Match
    public: __thiscall _com_error::_com_error(class _com_error const &)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

_com_error * __thiscall _com_error::_com_error(_com_error *this,_com_error *param_1)

{
  int *piVar1;
  
  *(undefined ***)this = &PTR__scalar_deleting_destructor__10024d3c;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(int **)(this + 8) = piVar1;
  *(undefined4 *)(this + 0xc) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}



// Function: `scalar_deleting_destructor' at 10018c00

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2010 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 8);
  *(undefined ***)this = &PTR__scalar_deleting_destructor__10024d3c;
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



// Function: FUN_10018c78 at 10018c78

void __fastcall FUN_10018c78(int param_1)

{
  facet *pfVar1;
  
  pfVar1 = std::locale::facet::_Decref(*(facet **)(param_1 + 4));
  if (pfVar1 != (facet *)0x0) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}



// Function: Facet_Register at 10018c8e

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
    *puVar1 = DAT_100312fc;
    puVar1[1] = param_1;
  }
  DAT_100312fc = puVar1;
  return;
}



// Function: FUN_10018cb8 at 10018cb8

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_10018cb8(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  FUN_10018d08(4);
  std::_Lockit::_Lockit((_Lockit *)(unaff_EBP + -0x10),0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (puVar1 = DAT_100312fc, DAT_100312fc != (undefined4 *)0x0) {
    DAT_100312fc = (undefined4 *)*DAT_100312fc;
    FUN_10018c78((int)puVar1);
    operator_delete(puVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_10018d08 at 10018d08

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_1 */

void __cdecl FUN_10018d08(int param_1)

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_10030e10 ^ (uint)&param_1;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __EH_epilog3 at 10018d3b

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



// Function: Unwind@10018d50 at 10018d50

void Unwind_10018d50(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018d53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018d80 at 10018d80

void Unwind_10018d80(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018db0 at 10018db0

void Unwind_10018db0(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018dbb at 10018dbb

void Unwind_10018dbb(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018de0 at 10018de0

void Unwind_10018de0(void)

{
  int unaff_EBP;
  
  FUN_100017f0(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e10 at 10018e10

void Unwind_10018e10(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018e13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018e60 at 10018e60

void Unwind_10018e60(void)

{
  int unaff_EBP;
  
  FUN_100017f0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018e68 at 10018e68

void Unwind_10018e68(void)

{
  int unaff_EBP;
  
  FUN_10001a50((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018e70 at 10018e70

void Unwind_10018e70(void)

{
  int unaff_EBP;
  
  FUN_100017f0((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018ea0 at 10018ea0

void Unwind_10018ea0(void)

{
  int unaff_EBP;
  
  FUN_100017f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018ea8 at 10018ea8

void Unwind_10018ea8(void)

{
  int unaff_EBP;
  
  FUN_10001a50((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018eb0 at 10018eb0

void Unwind_10018eb0(void)

{
  int unaff_EBP;
  
  FUN_100017f0((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10018ee0 at 10018ee0

void Unwind_10018ee0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018ee8 at 10018ee8

void Unwind_10018ee8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018ef0 at 10018ef0

void Unwind_10018ef0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018ef8 at 10018ef8

void Unwind_10018ef8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018f00 at 10018f00

void Unwind_10018f00(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10018f08 at 10018f08

void Unwind_10018f08(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@10018f10 at 10018f10

void Unwind_10018f10(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10018f18 at 10018f18

void Unwind_10018f18(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10018f20 at 10018f20

void Unwind_10018f20(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10018f50 at 10018f50

void Unwind_10018f50(void)

{
  int unaff_EBP;
  
  FUN_10006120(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10018f58 at 10018f58

void Unwind_10018f58(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10018f63 at 10018f63

void Unwind_10018f63(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10018f6e at 10018f6e

void Unwind_10018f6e(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018f76 at 10018f76

void Unwind_10018f76(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018fa0 at 10018fa0

void Unwind_10018fa0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018fa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x48));
  return;
}



// Function: Unwind@10018fac at 10018fac

void Unwind_10018fac(void)

{
  int unaff_EBP;
  
  FUN_10001ad0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x4c));
  return;
}



// Function: Unwind@10018fb7 at 10018fb7

void Unwind_10018fb7(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018fba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018fc0 at 10018fc0

void Unwind_10018fc0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018fc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10018ff0 at 10018ff0

void Unwind_10018ff0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10018ff3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10018ff9 at 10018ff9

void Unwind_10018ff9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001900f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x50));
    return;
  }
  return;
}



// Function: Unwind@10019016 at 10019016

void Unwind_10019016(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001901c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@10019022 at 10019022

void Unwind_10019022(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019025. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001902b at 1001902b

void Unwind_1001902b(void)

{
  int unaff_EBP;
  
  FUN_10001ad0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019060 at 10019060

void Unwind_10019060(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019068 at 10019068

void Unwind_10019068(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019073 at 10019073

void Unwind_10019073(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@1001907e at 1001907e

void Unwind_1001907e(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019086 at 10019086

void Unwind_10019086(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019091 at 10019091

void Unwind_10019091(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019099 at 10019099

void Unwind_10019099(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@100190a4 at 100190a4

void Unwind_100190a4(void)

{
  int unaff_EBP;
  
  FUN_10006120(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100190ac at 100190ac

void Unwind_100190ac(void)

{
  int unaff_EBP;
  
  FUN_100029f0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100190d0 at 100190d0

void Unwind_100190d0(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 0x10);
  return;
}



// Function: Unwind@100190db at 100190db

void Unwind_100190db(void)

{
  int unaff_EBP;
  
  FUN_100029f0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100190e3 at 100190e3

void Unwind_100190e3(void)

{
  int unaff_EBP;
  
  FUN_10006120(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100190eb at 100190eb

void Unwind_100190eb(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100190f6 at 100190f6

void Unwind_100190f6(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019101 at 10019101

void Unwind_10019101(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019109 at 10019109

void Unwind_10019109(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019111 at 10019111

void Unwind_10019111(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001911c at 1001911c

void Unwind_1001911c(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019140 at 10019140

void Unwind_10019140(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019148 at 10019148

void Unwind_10019148(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_10002570(*(undefined4 **)(unaff_EBP + -0x34));
    return;
  }
  return;
}



// Function: Unwind@10019161 at 10019161

void Unwind_10019161(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019169 at 10019169

void Unwind_10019169(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100191a0 at 100191a0

void Unwind_100191a0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002570(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@100191e0 at 100191e0

void Unwind_100191e0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100191e8 at 100191e8

void Unwind_100191e8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@100191f0 at 100191f0

void Unwind_100191f0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@100191f8 at 100191f8

void Unwind_100191f8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019200 at 10019200

void Unwind_10019200(void)

{
  int unaff_EBP;
  
  FUN_10002a70((int *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001920b at 1001920b

void Unwind_1001920b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019213 at 10019213

void Unwind_10019213(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001921b at 1001921b

void Unwind_1001921b(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019223 at 10019223

void Unwind_10019223(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019260 at 10019260

void Unwind_10019260(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019268 at 10019268

void Unwind_10019268(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019270 at 10019270

void Unwind_10019270(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019278 at 10019278

void Unwind_10019278(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019280 at 10019280

void Unwind_10019280(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019288 at 10019288

void Unwind_10019288(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019290 at 10019290

void Unwind_10019290(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019298 at 10019298

void Unwind_10019298(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100192a0 at 100192a0

void Unwind_100192a0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100192a8 at 100192a8

void Unwind_100192a8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100192b0 at 100192b0

void Unwind_100192b0(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x3c);
  return;
}



// Function: Unwind@100192b8 at 100192b8

void Unwind_100192b8(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100192c0 at 100192c0

void Unwind_100192c0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100192c8 at 100192c8

void Unwind_100192c8(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100192d0 at 100192d0

void Unwind_100192d0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@100192d8 at 100192d8

void Unwind_100192d8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100192e0 at 100192e0

void Unwind_100192e0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100192e8 at 100192e8

void Unwind_100192e8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@10019310 at 10019310

void Unwind_10019310(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019318 at 10019318

void Unwind_10019318(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019320 at 10019320

void Unwind_10019320(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019328 at 10019328

void Unwind_10019328(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019330 at 10019330

void Unwind_10019330(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019338 at 10019338

void Unwind_10019338(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019340 at 10019340

void Unwind_10019340(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019348 at 10019348

void Unwind_10019348(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019350 at 10019350

void Unwind_10019350(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x20);
  return;
}



// Function: Unwind@10019358 at 10019358

void Unwind_10019358(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019360 at 10019360

void Unwind_10019360(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@10019368 at 10019368

void Unwind_10019368(void)

{
  int unaff_EBP;
  
  FUN_10003730((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@10019370 at 10019370

void Unwind_10019370(void)

{
  int unaff_EBP;
  
  FUN_10002570(*(undefined4 **)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019378 at 10019378

void Unwind_10019378(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019380 at 10019380

void Unwind_10019380(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019388 at 10019388

void Unwind_10019388(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x7c));
  return;
}



// Function: Unwind@10019390 at 10019390

void Unwind_10019390(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019398 at 10019398

void Unwind_10019398(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x50);
  return;
}



// Function: Unwind@100193a0 at 100193a0

void Unwind_100193a0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100193a8 at 100193a8

void Unwind_100193a8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@100193b0 at 100193b0

void Unwind_100193b0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100193b8 at 100193b8

void Unwind_100193b8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@100193c0 at 100193c0

void Unwind_100193c0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100193c8 at 100193c8

void Unwind_100193c8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@100193d0 at 100193d0

void Unwind_100193d0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100193d8 at 100193d8

void Unwind_100193d8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@100193e0 at 100193e0

void Unwind_100193e0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@100193e8 at 100193e8

void Unwind_100193e8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100193f0 at 100193f0

void Unwind_100193f0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@100193f8 at 100193f8

void Unwind_100193f8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@10019400 at 10019400

void Unwind_10019400(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@10019408 at 10019408

void Unwind_10019408(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@10019410 at 10019410

void Unwind_10019410(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10019418 at 10019418

void Unwind_10019418(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@10019420 at 10019420

void Unwind_10019420(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@10019428 at 10019428

void Unwind_10019428(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@10019430 at 10019430

void Unwind_10019430(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@10019438 at 10019438

void Unwind_10019438(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@10019470 at 10019470

void Unwind_10019470(void)

{
  int unaff_EBP;
  
  FUN_10002570(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@100194a0 at 100194a0

void Unwind_100194a0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100194a8 at 100194a8

void Unwind_100194a8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194b0 at 100194b0

void Unwind_100194b0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194b8 at 100194b8

void Unwind_100194b8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194c0 at 100194c0

void Unwind_100194c0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100194f0 at 100194f0

void Unwind_100194f0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@100194fb at 100194fb

void Unwind_100194fb(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019506 at 10019506

void Unwind_10019506(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019511 at 10019511

void Unwind_10019511(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x224));
  return;
}



// Function: Unwind@1001951c at 1001951c

void Unwind_1001951c(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019527 at 10019527

void Unwind_10019527(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019560 at 10019560

void Unwind_10019560(void)

{
  int unaff_EBP;
  
  FUN_10004470(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019590 at 10019590

void Unwind_10019590(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019598 at 10019598

void Unwind_10019598(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195a0 at 100195a0

void Unwind_100195a0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195a8 at 100195a8

void Unwind_100195a8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195b0 at 100195b0

void Unwind_100195b0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195e0 at 100195e0

void Unwind_100195e0(void)

{
  int unaff_EBP;
  
  FUN_10004470(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100195e8 at 100195e8

void Unwind_100195e8(void)

{
  int unaff_EBP;
  
  FUN_10004500(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019610 at 10019610

void Unwind_10019610(void)

{
  int unaff_EBP;
  
  FUN_10004500(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019618 at 10019618

void Unwind_10019618(void)

{
  int unaff_EBP;
  
  FUN_10004470(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019640 at 10019640

void Unwind_10019640(void)

{
  int unaff_EBP;
  
  FUN_10004700(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019670 at 10019670

void Unwind_10019670(void)

{
  FUN_10004700(0x10030e5c);
  return;
}



// Function: Unwind@100196a0 at 100196a0

void Unwind_100196a0(void)

{
  int unaff_EBP;
  
  FUN_100049f0(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100196a8 at 100196a8

void Unwind_100196a8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100196ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100196d0 at 100196d0

void Unwind_100196d0(void)

{
  int unaff_EBP;
  
  FUN_10001700(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019700 at 10019700

void Unwind_10019700(void)

{
  int unaff_EBP;
  
  FUN_10002ed0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019730 at 10019730

void Unwind_10019730(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019733. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019760 at 10019760

void Unwind_10019760(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019763. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019790 at 10019790

void Unwind_10019790(void)

{
  int unaff_EBP;
  
  FUN_100049f0(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019798 at 10019798

void Unwind_10019798(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001979b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100197c0 at 100197c0

void Unwind_100197c0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019810 at 10019810

void Unwind_10019810(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001981b at 1001981b

void Unwind_1001981b(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@10019840 at 10019840

void Unwind_10019840(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019870 at 10019870

void Unwind_10019870(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019878 at 10019878

void Unwind_10019878(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019880 at 10019880

void Unwind_10019880(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019888 at 10019888

void Unwind_10019888(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019890 at 10019890

void Unwind_10019890(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019898 at 10019898

void Unwind_10019898(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100198c0 at 100198c0

void Unwind_100198c0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100198cb at 100198cb

void Unwind_100198cb(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@100198f0 at 100198f0

void Unwind_100198f0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@100198fb at 100198fb

void Unwind_100198fb(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019920 at 10019920

void Unwind_10019920(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019923. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019929 at 10019929

void Unwind_10019929(void)

{
  int unaff_EBP;
  
  FUN_100049f0(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019970 at 10019970

void Unwind_10019970(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001997b at 1001997b

void Unwind_1001997b(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@10019986 at 10019986

void Unwind_10019986(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001998e at 1001998e

void Unwind_1001998e(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@100199c0 at 100199c0

void Unwind_100199c0(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@100199c8 at 100199c8

void Unwind_100199c8(void)

{
  int unaff_EBP;
  
  FUN_10004cb0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@100199d0 at 100199d0

void Unwind_100199d0(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@100199d8 at 100199d8

void Unwind_100199d8(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x100199db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@100199e1 at 100199e1

void Unwind_100199e1(void)

{
  int unaff_EBP;
  
  FUN_100049f0((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019a10 at 10019a10

void Unwind_10019a10(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019a1b at 10019a1b

void Unwind_10019a1b(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019a26 at 10019a26

void Unwind_10019a26(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019a50 at 10019a50

void Unwind_10019a50(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019a5b at 10019a5b

void Unwind_10019a5b(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019a66 at 10019a66

void Unwind_10019a66(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019a90 at 10019a90

void Unwind_10019a90(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019a98 at 10019a98

void Unwind_10019a98(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019aa3 at 10019aa3

void Unwind_10019aa3(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019aae at 10019aae

void Unwind_10019aae(void)

{
  int unaff_EBP;
  
  FUN_10006360(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019ae0 at 10019ae0

void Unwind_10019ae0(void)

{
  int unaff_EBP;
  
  FUN_10006360(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019ae8 at 10019ae8

void Unwind_10019ae8(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019af3 at 10019af3

void Unwind_10019af3(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@10019afe at 10019afe

void Unwind_10019afe(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019b30 at 10019b30

void Unwind_10019b30(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 0x14);
  return;
}



// Function: Unwind@10019b3b at 10019b3b

void Unwind_10019b3b(void)

{
  int unaff_EBP;
  
  FUN_10006120(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019b46 at 10019b46

void Unwind_10019b46(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@10019b51 at 10019b51

void Unwind_10019b51(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@10019b5c at 10019b5c

void Unwind_10019b5c(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019b64 at 10019b64

void Unwind_10019b64(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019b6c at 10019b6c

void Unwind_10019b6c(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019b77 at 10019b77

void Unwind_10019b77(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@10019b82 at 10019b82

void Unwind_10019b82(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019b8a at 10019b8a

void Unwind_10019b8a(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019b92 at 10019b92

void Unwind_10019b92(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@10019b9d at 10019b9d

void Unwind_10019b9d(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019bc0 at 10019bc0

void Unwind_10019bc0(void)

{
  int unaff_EBP;
  
  FUN_10006760(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019bf0 at 10019bf0

void Unwind_10019bf0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019c40 at 10019c40

void Unwind_10019c40(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10019c48 at 10019c48

void Unwind_10019c48(void)

{
  int unaff_EBP;
  
  FUN_10004c60((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@10019c50 at 10019c50

void Unwind_10019c50(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x40);
  return;
}



// Function: Unwind@10019c58 at 10019c58

void Unwind_10019c58(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019c5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019c61 at 10019c61

void Unwind_10019c61(void)

{
  int unaff_EBP;
  
  FUN_100049f0((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019c69 at 10019c69

void Unwind_10019c69(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019c6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019c72 at 10019c72

void Unwind_10019c72(void)

{
  int unaff_EBP;
  
  FUN_100049f0((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019c7a at 10019c7a

void Unwind_10019c7a(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x10019c7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019c83 at 10019c83

void Unwind_10019c83(void)

{
  int unaff_EBP;
  
  FUN_100049f0((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019cb0 at 10019cb0

void Unwind_10019cb0(void)

{
  int unaff_EBP;
  
  FUN_100057e0((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@10019cbb at 10019cbb

void Unwind_10019cbb(void)

{
  int unaff_EBP;
  
  FUN_10005140((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019cc6 at 10019cc6

void Unwind_10019cc6(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10019cd1 at 10019cd1

void Unwind_10019cd1(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10019cdc at 10019cdc

void Unwind_10019cdc(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019ce7 at 10019ce7

void Unwind_10019ce7(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019cf2 at 10019cf2

void Unwind_10019cf2(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019cfd at 10019cfd

void Unwind_10019cfd(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019d08 at 10019d08

void Unwind_10019d08(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@10019d13 at 10019d13

void Unwind_10019d13(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@10019d1e at 10019d1e

void Unwind_10019d1e(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@10019d60 at 10019d60

void Unwind_10019d60(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019d90 at 10019d90

void Unwind_10019d90(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019d98 at 10019d98

void Unwind_10019d98(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019da0 at 10019da0

void Unwind_10019da0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019da8 at 10019da8

void Unwind_10019da8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019db0 at 10019db0

void Unwind_10019db0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019db8 at 10019db8

void Unwind_10019db8(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@10019dc0 at 10019dc0

void Unwind_10019dc0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + 8) + 4));
  return;
}



// Function: Unwind@10019dcb at 10019dcb

void Unwind_10019dcb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_10005970(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@10019de4 at 10019de4

void Unwind_10019de4(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019dec at 10019dec

void Unwind_10019dec(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e10 at 10019e10

void Unwind_10019e10(void)

{
  int unaff_EBP;
  
  FUN_100016b0(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019e18 at 10019e18

void Unwind_10019e18(void)

{
  int unaff_EBP;
  
  FUN_10001790((LPCRITICAL_SECTION)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@10019e23 at 10019e23

void Unwind_10019e23(void)

{
  int unaff_EBP;
  
  FUN_100019d0(*(int *)(unaff_EBP + -0x10) + 0x14);
  return;
}



// Function: Unwind@10019e2e at 10019e2e

void Unwind_10019e2e(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e36 at 10019e36

void Unwind_10019e36(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@10019e41 at 10019e41

void Unwind_10019e41(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019e49 at 10019e49

void Unwind_10019e49(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x18) + 8));
  return;
}



// Function: Unwind@10019e54 at 10019e54

void Unwind_10019e54(void)

{
  int unaff_EBP;
  
  FUN_10006120(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@10019e5f at 10019e5f

void Unwind_10019e5f(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019e67 at 10019e67

void Unwind_10019e67(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x48));
  return;
}



// Function: Unwind@10019e72 at 10019e72

void Unwind_10019e72(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@10019e7a at 10019e7a

void Unwind_10019e7a(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x4c));
  return;
}



// Function: Unwind@10019ea0 at 10019ea0

void Unwind_10019ea0(void)

{
  int unaff_EBP;
  
  FUN_10006760(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019ef0 at 10019ef0

void Unwind_10019ef0(void)

{
  int unaff_EBP;
  
  FUN_10006760(*(int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@10019ef8 at 10019ef8

void Unwind_10019ef8(void)

{
  int unaff_EBP;
  
  FUN_10006850(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10019f20 at 10019f20

void Unwind_10019f20(void)

{
  int unaff_EBP;
  
  FUN_10006850(*(int *)(unaff_EBP + -0x10) + 0xc);
  return;
}



// Function: Unwind@10019f2b at 10019f2b

void Unwind_10019f2b(void)

{
  int unaff_EBP;
  
  FUN_10006760(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@10019f50 at 10019f50

void Unwind_10019f50(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@10019f80 at 10019f80

void Unwind_10019f80(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@10019fb0 at 10019fb0

void Unwind_10019fb0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@10019fb8 at 10019fb8

void Unwind_10019fb8(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@10019fc0 at 10019fc0

void Unwind_10019fc0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@10019ff0 at 10019ff0

void Unwind_10019ff0(void)

{
  FUN_10005130();
  return;
}



// Function: Unwind@1001a040 at 1001a040

void Unwind_1001a040(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a048 at 1001a048

void Unwind_1001a048(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001a050 at 1001a050

void Unwind_1001a050(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001a05b at 1001a05b

void Unwind_1001a05b(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001a066 at 1001a066

void Unwind_1001a066(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a06e at 1001a06e

void Unwind_1001a06e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x8c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x8c) = *(uint *)(unaff_EBP + -0x8c) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001a08a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)(unaff_EBP + -0xf4));
    return;
  }
  return;
}



// Function: Unwind@1001a091 at 1001a091

void Unwind_1001a091(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a097. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)(unaff_EBP + -0x13c));
  return;
}



// Function: Unwind@1001a09d at 1001a09d

void Unwind_1001a09d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a0a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001a0a9 at 1001a0a9

void Unwind_1001a0a9(void)

{
  int unaff_EBP;
  
  FUN_10001ad0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)(unaff_EBP + -0x140));
  return;
}



// Function: Unwind@1001a0b4 at 1001a0b4

void Unwind_1001a0b4(void)

{
  int unaff_EBP;
  
  FUN_10002a70((int *)(unaff_EBP + -0x144));
  return;
}



// Function: Unwind@1001a0bf at 1001a0bf

void Unwind_1001a0bf(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001a0c7 at 1001a0c7

void Unwind_1001a0c7(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// Function: Unwind@1001a0d2 at 1001a0d2

void Unwind_1001a0d2(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001a0dd at 1001a0dd

void Unwind_1001a0dd(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a0e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0xa4) + -0x48));
  return;
}



// Function: Unwind@1001a0ec at 1001a0ec

void Unwind_1001a0ec(void)

{
  int unaff_EBP;
  
  FUN_10001ad0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0xa4) + -0x4c));
  return;
}



// Function: Unwind@1001a0fa at 1001a0fa

void Unwind_1001a0fa(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001a100. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0xa8));
  return;
}



// Function: Unwind@1001a106 at 1001a106

void Unwind_1001a106(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x88));
  return;
}



// Function: Unwind@1001a111 at 1001a111

void Unwind_1001a111(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001a150 at 1001a150

void Unwind_1001a150(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a158 at 1001a158

void Unwind_1001a158(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001a163 at 1001a163

void Unwind_1001a163(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a16b at 1001a16b

void Unwind_1001a16b(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a173 at 1001a173

void Unwind_1001a173(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a17b at 1001a17b

void Unwind_1001a17b(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a183 at 1001a183

void Unwind_1001a183(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a18b at 1001a18b

void Unwind_1001a18b(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a193 at 1001a193

void Unwind_1001a193(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a1c0 at 1001a1c0

void Unwind_1001a1c0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a1c8 at 1001a1c8

void Unwind_1001a1c8(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a1f0 at 1001a1f0

void Unwind_1001a1f0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a1f8 at 1001a1f8

void Unwind_1001a1f8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a200 at 1001a200

void Unwind_1001a200(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a208 at 1001a208

void Unwind_1001a208(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a210 at 1001a210

void Unwind_1001a210(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a218 at 1001a218

void Unwind_1001a218(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a220 at 1001a220

void Unwind_1001a220(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a228 at 1001a228

void Unwind_1001a228(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + 8) + 4));
  return;
}



// Function: Unwind@1001a233 at 1001a233

void Unwind_1001a233(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
    FUN_10005970(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a24c at 1001a24c

void Unwind_1001a24c(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a254 at 1001a254

void Unwind_1001a254(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a280 at 1001a280

void Unwind_1001a280(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a288 at 1001a288

void Unwind_1001a288(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005400(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a2a1 at 1001a2a1

void Unwind_1001a2a1(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a2a9 at 1001a2a9

void Unwind_1001a2a9(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a2d0 at 1001a2d0

void Unwind_1001a2d0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a2d8 at 1001a2d8

void Unwind_1001a2d8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x18) + 4));
  return;
}



// Function: Unwind@1001a2e3 at 1001a2e3

void Unwind_1001a2e3(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a2eb at 1001a2eb

void Unwind_1001a2eb(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a2f3 at 1001a2f3

void Unwind_1001a2f3(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a2fb at 1001a2fb

void Unwind_1001a2fb(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a303 at 1001a303

void Unwind_1001a303(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a30b at 1001a30b

void Unwind_1001a30b(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001a313 at 1001a313

void Unwind_1001a313(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a340 at 1001a340

void Unwind_1001a340(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a370 at 1001a370

void Unwind_1001a370(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a378 at 1001a378

void Unwind_1001a378(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a380 at 1001a380

void Unwind_1001a380(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_10002570(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a3c0 at 1001a3c0

void Unwind_1001a3c0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a3c8 at 1001a3c8

void Unwind_1001a3c8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a3d3 at 1001a3d3

void Unwind_1001a3d3(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a400 at 1001a400

void Unwind_1001a400(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a408 at 1001a408

void Unwind_1001a408(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001a413 at 1001a413

void Unwind_1001a413(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a41b at 1001a41b

void Unwind_1001a41b(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a423 at 1001a423

void Unwind_1001a423(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a42b at 1001a42b

void Unwind_1001a42b(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a433 at 1001a433

void Unwind_1001a433(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a460 at 1001a460

void Unwind_1001a460(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a468 at 1001a468

void Unwind_1001a468(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004c50(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a4a0 at 1001a4a0

void Unwind_1001a4a0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a4a8 at 1001a4a8

void Unwind_1001a4a8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001a4b3 at 1001a4b3

void Unwind_1001a4b3(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a4bb at 1001a4bb

void Unwind_1001a4bb(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001a4c6 at 1001a4c6

void Unwind_1001a4c6(void)

{
  int unaff_EBP;
  
  FUN_10006450((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001a4d1 at 1001a4d1

void Unwind_1001a4d1(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a4d9 at 1001a4d9

void Unwind_1001a4d9(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001a4e4 at 1001a4e4

void Unwind_1001a4e4(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a4ec at 1001a4ec

void Unwind_1001a4ec(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x14));
  return;
}



// Function: Unwind@1001a4f7 at 1001a4f7

void Unwind_1001a4f7(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a4ff at 1001a4ff

void Unwind_1001a4ff(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001a50a at 1001a50a

void Unwind_1001a50a(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a512 at 1001a512

void Unwind_1001a512(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x1c));
  return;
}



// Function: Unwind@1001a540 at 1001a540

void Unwind_1001a540(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x34) + 4));
  return;
}



// Function: Unwind@1001a54b at 1001a54b

void Unwind_1001a54b(void)

{
  int unaff_EBP;
  
  FUN_10006450((undefined4 *)(*(int *)(unaff_EBP + -0x34) + 8));
  return;
}



// Function: Unwind@1001a556 at 1001a556

void Unwind_1001a556(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x34) + 0x10));
  return;
}



// Function: Unwind@1001a561 at 1001a561

void Unwind_1001a561(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x34) + 0x14));
  return;
}



// Function: Unwind@1001a56c at 1001a56c

void Unwind_1001a56c(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x34) + 0x18));
  return;
}



// Function: Unwind@1001a577 at 1001a577

void Unwind_1001a577(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x34) + 0x1c));
  return;
}



// Function: Unwind@1001a582 at 1001a582

void Unwind_1001a582(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001a58a at 1001a58a

void Unwind_1001a58a(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001a592 at 1001a592

void Unwind_1001a592(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a59a at 1001a59a

void Unwind_1001a59a(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a5a2 at 1001a5a2

void Unwind_1001a5a2(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a5aa at 1001a5aa

void Unwind_1001a5aa(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a5b2 at 1001a5b2

void Unwind_1001a5b2(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x30) + 4));
  return;
}



// Function: Unwind@1001a5bd at 1001a5bd

void Unwind_1001a5bd(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a5c5 at 1001a5c5

void Unwind_1001a5c5(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001a600 at 1001a600

void Unwind_1001a600(void)

{
  int unaff_EBP;
  
  FUN_10005970((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a608 at 1001a608

void Unwind_1001a608(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a610 at 1001a610

void Unwind_1001a610(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10005400(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a629 at 1001a629

void Unwind_1001a629(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a631 at 1001a631

void Unwind_1001a631(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a660 at 1001a660

void Unwind_1001a660(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a668 at 1001a668

void Unwind_1001a668(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004c50(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a681 at 1001a681

void Unwind_1001a681(void)

{
  int unaff_EBP;
  
  FUN_10004e40((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a689 at 1001a689

void Unwind_1001a689(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001a6b0 at 1001a6b0

void Unwind_1001a6b0(void)

{
  int unaff_EBP;
  
  FUN_10009ac0((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a6b8 at 1001a6b8

void Unwind_1001a6b8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10004c50(*(undefined4 *)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001a6f0 at 1001a6f0

void Unwind_1001a6f0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a6f8 at 1001a6f8

void Unwind_1001a6f8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a700 at 1001a700

void Unwind_1001a700(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a708 at 1001a708

void Unwind_1001a708(void)

{
  int unaff_EBP;
  
  FUN_100059f0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001a710 at 1001a710

void Unwind_1001a710(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a718 at 1001a718

void Unwind_1001a718(void)

{
  int unaff_EBP;
  
  FUN_100058f0((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001a720 at 1001a720

void Unwind_1001a720(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// Function: Unwind@1001a72b at 1001a72b

void Unwind_1001a72b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a733 at 1001a733

void Unwind_1001a733(void)

{
  int unaff_EBP;
  
  FUN_10006450((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001a73b at 1001a73b

void Unwind_1001a73b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// Function: Unwind@1001a746 at 1001a746

void Unwind_1001a746(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x74);
  return;
}



// Function: Unwind@1001a74e at 1001a74e

void Unwind_1001a74e(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x38) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x38) = *(uint *)(unaff_EBP + -0x38) & 0xfffffffe;
    FUN_10001700((undefined4 *)(unaff_EBP + -0x48));
    return;
  }
  return;
}



// Function: Unwind@1001a767 at 1001a767

void Unwind_1001a767(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x38) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x38) = *(uint *)(unaff_EBP + -0x38) & 0xfffffffd;
    FUN_10001700((undefined4 *)(unaff_EBP + -0x48));
    return;
  }
  return;
}



// Function: Unwind@1001a7b0 at 1001a7b0

void Unwind_1001a7b0(void)

{
  int unaff_EBP;
  
  FUN_100059f0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001a7b8 at 1001a7b8

void Unwind_1001a7b8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a7c0 at 1001a7c0

void Unwind_1001a7c0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001a7c8 at 1001a7c8

void Unwind_1001a7c8(void)

{
  int unaff_EBP;
  
  FUN_10006450((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001a7d0 at 1001a7d0

void Unwind_1001a7d0(void)

{
  int unaff_EBP;
  
  FUN_10005970((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001a7d8 at 1001a7d8

void Unwind_1001a7d8(void)

{
  int unaff_EBP;
  
  FUN_10005970((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001a7e0 at 1001a7e0

void Unwind_1001a7e0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a7e8 at 1001a7e8

void Unwind_1001a7e8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a7f0 at 1001a7f0

void Unwind_1001a7f0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001a7f8 at 1001a7f8

void Unwind_1001a7f8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a800 at 1001a800

void Unwind_1001a800(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a808 at 1001a808

void Unwind_1001a808(void)

{
  int unaff_EBP;
  
  FUN_10005a70((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001a813 at 1001a813

void Unwind_1001a813(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001a81b at 1001a81b

void Unwind_1001a81b(void)

{
  int unaff_EBP;
  
  FUN_10008070((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001a850 at 1001a850

void Unwind_1001a850(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a858 at 1001a858

void Unwind_1001a858(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x2c);
  return;
}



// Function: Unwind@1001a8a0 at 1001a8a0

void Unwind_1001a8a0(void)

{
  int unaff_EBP;
  
  FUN_100059f0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a8a8 at 1001a8a8

void Unwind_1001a8a8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x5c));
  return;
}



// Function: Unwind@1001a8b0 at 1001a8b0

void Unwind_1001a8b0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001a8b8 at 1001a8b8

void Unwind_1001a8b8(void)

{
  int unaff_EBP;
  
  FUN_10006450((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a8c0 at 1001a8c0

void Unwind_1001a8c0(void)

{
  int unaff_EBP;
  
  FUN_10005970((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a8c8 at 1001a8c8

void Unwind_1001a8c8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001a8d0 at 1001a8d0

void Unwind_1001a8d0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a8d8 at 1001a8d8

void Unwind_1001a8d8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a8e0 at 1001a8e0

void Unwind_1001a8e0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a8e8 at 1001a8e8

void Unwind_1001a8e8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a8f0 at 1001a8f0

void Unwind_1001a8f0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a920 at 1001a920

void Unwind_1001a920(void)

{
  int unaff_EBP;
  
  FUN_100059f0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001a928 at 1001a928

void Unwind_1001a928(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// Function: Unwind@1001a930 at 1001a930

void Unwind_1001a930(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001a938 at 1001a938

void Unwind_1001a938(void)

{
  int unaff_EBP;
  
  FUN_10006450((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001a940 at 1001a940

void Unwind_1001a940(void)

{
  int unaff_EBP;
  
  FUN_10005970((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001a948 at 1001a948

void Unwind_1001a948(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001a950 at 1001a950

void Unwind_1001a950(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a958 at 1001a958

void Unwind_1001a958(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001a960 at 1001a960

void Unwind_1001a960(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a968 at 1001a968

void Unwind_1001a968(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a970 at 1001a970

void Unwind_1001a970(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001a9c0 at 1001a9c0

void Unwind_1001a9c0(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001a9c8 at 1001a9c8

void Unwind_1001a9c8(void)

{
  int unaff_EBP;
  
  FUN_100059f0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001a9d0 at 1001a9d0

void Unwind_1001a9d0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001a9d8 at 1001a9d8

void Unwind_1001a9d8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// Function: Unwind@1001a9e0 at 1001a9e0

void Unwind_1001a9e0(void)

{
  int unaff_EBP;
  
  FUN_10006450((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001aa10 at 1001aa10

void Unwind_1001aa10(void)

{
  FUN_10005130();
  return;
}



// Function: Unwind@1001aa21 at 1001aa21

void Unwind_1001aa21(void)

{
  FUN_10005130();
  return;
}



// Function: Unwind@1001aa50 at 1001aa50

void Unwind_1001aa50(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001aa58 at 1001aa58

void Unwind_1001aa58(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001aa90 at 1001aa90

void Unwind_1001aa90(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001aa98 at 1001aa98

void Unwind_1001aa98(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0xa3c));
  return;
}



// Function: Unwind@1001aaa3 at 1001aaa3

void Unwind_1001aaa3(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0xa2c));
  return;
}



// Function: Unwind@1001aae0 at 1001aae0

void Unwind_1001aae0(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0xa58));
  return;
}



// Function: Unwind@1001aaeb at 1001aaeb

void Unwind_1001aaeb(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0xa2c));
  return;
}



// Function: Unwind@1001aaf6 at 1001aaf6

void Unwind_1001aaf6(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0xa48));
  return;
}



// Function: Unwind@1001ab30 at 1001ab30

void Unwind_1001ab30(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ab60 at 1001ab60

void Unwind_1001ab60(void)

{
  int unaff_EBP;
  
  FUN_10004c50(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001ab90 at 1001ab90

void Unwind_1001ab90(void)

{
  int unaff_EBP;
  
  FUN_1000b720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001abc0 at 1001abc0

void Unwind_1001abc0(void)

{
  int unaff_EBP;
  
  FUN_10004c50(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001abf0 at 1001abf0

void Unwind_1001abf0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001abf3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001abf9 at 1001abf9

void Unwind_1001abf9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001abfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ac40 at 1001ac40

void Unwind_1001ac40(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ac48 at 1001ac48

void Unwind_1001ac48(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ac50 at 1001ac50

void Unwind_1001ac50(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001ac80 at 1001ac80

void Unwind_1001ac80(void)

{
  int unaff_EBP;
  
  FUN_1000b9e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ac88 at 1001ac88

void Unwind_1001ac88(void)

{
  int unaff_EBP;
  
  FUN_10004c50(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001acb0 at 1001acb0

void Unwind_1001acb0(void)

{
  int unaff_EBP;
  
  FUN_1000bad0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001acbb at 1001acbb

void Unwind_1001acbb(void)

{
  int unaff_EBP;
  
  FUN_1000b720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001acf0 at 1001acf0

void Unwind_1001acf0(void)

{
  int unaff_EBP;
  
  FUN_1000b730((undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001ad20 at 1001ad20

void Unwind_1001ad20(void)

{
  int unaff_EBP;
  
  FUN_100017f0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ad28 at 1001ad28

void Unwind_1001ad28(void)

{
  int unaff_EBP;
  
  FUN_10001a50((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ad30 at 1001ad30

void Unwind_1001ad30(void)

{
  int unaff_EBP;
  
  FUN_1000b730((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001ad38 at 1001ad38

void Unwind_1001ad38(void)

{
  int unaff_EBP;
  
  FUN_100017f0((int *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001ad60 at 1001ad60

void Unwind_1001ad60(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad68 at 1001ad68

void Unwind_1001ad68(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001ad73 at 1001ad73

void Unwind_1001ad73(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ad7b at 1001ad7b

void Unwind_1001ad7b(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001ad86 at 1001ad86

void Unwind_1001ad86(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001adb0 at 1001adb0

void Unwind_1001adb0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001adbb at 1001adbb

void Unwind_1001adbb(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001adc6 at 1001adc6

void Unwind_1001adc6(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001add1 at 1001add1

void Unwind_1001add1(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001add9 at 1001add9

void Unwind_1001add9(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae00 at 1001ae00

void Unwind_1001ae00(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae08 at 1001ae08

void Unwind_1001ae08(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae10 at 1001ae10

void Unwind_1001ae10(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae18 at 1001ae18

void Unwind_1001ae18(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001ae40 at 1001ae40

void Unwind_1001ae40(void)

{
  int unaff_EBP;
  
  FUN_1000ba70(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001ae4b at 1001ae4b

void Unwind_1001ae4b(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001ae56 at 1001ae56

void Unwind_1001ae56(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@1001ae61 at 1001ae61

void Unwind_1001ae61(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001ae6c at 1001ae6c

void Unwind_1001ae6c(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001ae77 at 1001ae77

void Unwind_1001ae77(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae7f at 1001ae7f

void Unwind_1001ae7f(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae87 at 1001ae87

void Unwind_1001ae87(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001ae8f at 1001ae8f

void Unwind_1001ae8f(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aec0 at 1001aec0

void Unwind_1001aec0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001aecb at 1001aecb

void Unwind_1001aecb(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001aed3 at 1001aed3

void Unwind_1001aed3(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001aedb at 1001aedb

void Unwind_1001aedb(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001aee3 at 1001aee3

void Unwind_1001aee3(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001af10 at 1001af10

void Unwind_1001af10(void)

{
  int unaff_EBP;
  
  FUN_1000c450(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af18 at 1001af18

void Unwind_1001af18(void)

{
  int unaff_EBP;
  
  FUN_1000bad0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001af23 at 1001af23

void Unwind_1001af23(void)

{
  int unaff_EBP;
  
  FUN_1000b720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001af50 at 1001af50

void Unwind_1001af50(void)

{
  int unaff_EBP;
  
  FUN_1000b9e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af58 at 1001af58

void Unwind_1001af58(void)

{
  int unaff_EBP;
  
  FUN_10004c50(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001af80 at 1001af80

void Unwind_1001af80(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af88 at 1001af88

void Unwind_1001af88(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001af90 at 1001af90

void Unwind_1001af90(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001af98 at 1001af98

void Unwind_1001af98(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001afa0 at 1001afa0

void Unwind_1001afa0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001afa8 at 1001afa8

void Unwind_1001afa8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001afb0 at 1001afb0

void Unwind_1001afb0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001afb8 at 1001afb8

void Unwind_1001afb8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001afc0 at 1001afc0

void Unwind_1001afc0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b010 at 1001b010

void Unwind_1001b010(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001b01b at 1001b01b

void Unwind_1001b01b(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001b026 at 1001b026

void Unwind_1001b026(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b031 at 1001b031

void Unwind_1001b031(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001b03c at 1001b03c

void Unwind_1001b03c(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x18));
  return;
}



// Function: Unwind@1001b047 at 1001b047

void Unwind_1001b047(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b04f at 1001b04f

void Unwind_1001b04f(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b057 at 1001b057

void Unwind_1001b057(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b05f at 1001b05f

void Unwind_1001b05f(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b090 at 1001b090

void Unwind_1001b090(void)

{
  int unaff_EBP;
  
  FUN_1000d2b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b098 at 1001b098

void Unwind_1001b098(void)

{
  int unaff_EBP;
  
  FUN_1000c450(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b0a0 at 1001b0a0

void Unwind_1001b0a0(void)

{
  int unaff_EBP;
  
  FUN_1000bad0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b0ab at 1001b0ab

void Unwind_1001b0ab(void)

{
  int unaff_EBP;
  
  FUN_1000b720((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001b0e0 at 1001b0e0

void Unwind_1001b0e0(void)

{
  int unaff_EBP;
  
  FUN_1000ba70(*(int *)(unaff_EBP + -0x10) + 4);
  return;
}



// Function: Unwind@1001b0eb at 1001b0eb

void Unwind_1001b0eb(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b0f3 at 1001b0f3

void Unwind_1001b0f3(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x30));
  return;
}



// Function: Unwind@1001b0fe at 1001b0fe

void Unwind_1001b0fe(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b106 at 1001b106

void Unwind_1001b106(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// Function: Unwind@1001b111 at 1001b111

void Unwind_1001b111(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b119 at 1001b119

void Unwind_1001b119(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x38));
  return;
}



// Function: Unwind@1001b124 at 1001b124

void Unwind_1001b124(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b12c at 1001b12c

void Unwind_1001b12c(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0x3c));
  return;
}



// Function: Unwind@1001b180 at 1001b180

void Unwind_1001b180(void)

{
  int unaff_EBP;
  
  FUN_1000e400(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b1b0 at 1001b1b0

void Unwind_1001b1b0(void)

{
  int unaff_EBP;
  
  FUN_1000e320((undefined4 *)(unaff_EBP + -0x114));
  return;
}



// Function: Unwind@1001b1f0 at 1001b1f0

void Unwind_1001b1f0(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b1f8 at 1001b1f8

void Unwind_1001b1f8(void)

{
  int unaff_EBP;
  
  FUN_1000e400(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b220 at 1001b220

void Unwind_1001b220(void)

{
  int unaff_EBP;
  
  FUN_1000e400((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b228 at 1001b228

void Unwind_1001b228(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b230 at 1001b230

void Unwind_1001b230(void)

{
  int unaff_EBP;
  
  FUN_1000e900((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b238 at 1001b238

void Unwind_1001b238(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b240 at 1001b240

void Unwind_1001b240(void)

{
  int unaff_EBP;
  
  FUN_1000e400((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b270 at 1001b270

void Unwind_1001b270(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b278 at 1001b278

void Unwind_1001b278(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b280 at 1001b280

void Unwind_1001b280(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b288 at 1001b288

void Unwind_1001b288(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b2b0 at 1001b2b0

void Unwind_1001b2b0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b2b8 at 1001b2b8

void Unwind_1001b2b8(void)

{
  int unaff_EBP;
  
  FUN_1000c110((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b2e0 at 1001b2e0

void Unwind_1001b2e0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b2e8 at 1001b2e8

void Unwind_1001b2e8(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b2f0 at 1001b2f0

void Unwind_1001b2f0(void)

{
  int unaff_EBP;
  
  FUN_1000c4b0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b320 at 1001b320

void Unwind_1001b320(void)

{
  int unaff_EBP;
  
  FUN_10005140((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b328 at 1001b328

void Unwind_1001b328(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b330 at 1001b330

void Unwind_1001b330(void)

{
  int unaff_EBP;
  
  FUN_1000e400((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b338 at 1001b338

void Unwind_1001b338(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b340 at 1001b340

void Unwind_1001b340(void)

{
  int unaff_EBP;
  
  FUN_1000e900((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b348 at 1001b348

void Unwind_1001b348(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b350 at 1001b350

void Unwind_1001b350(void)

{
  int unaff_EBP;
  
  FUN_1000e400((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b358 at 1001b358

void Unwind_1001b358(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b360 at 1001b360

void Unwind_1001b360(void)

{
  int unaff_EBP;
  
  FUN_1000e400((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b368 at 1001b368

void Unwind_1001b368(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b370 at 1001b370

void Unwind_1001b370(void)

{
  int unaff_EBP;
  
  FUN_1000e400((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b378 at 1001b378

void Unwind_1001b378(void)

{
  int unaff_EBP;
  
  FUN_1000e4e0((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b380 at 1001b380

void Unwind_1001b380(void)

{
  int unaff_EBP;
  
  FUN_1000e400((undefined4 *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b3b0 at 1001b3b0

void Unwind_1001b3b0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3b8 at 1001b3b8

void Unwind_1001b3b8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b3c0 at 1001b3c0

void Unwind_1001b3c0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3c8 at 1001b3c8

void Unwind_1001b3c8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3d0 at 1001b3d0

void Unwind_1001b3d0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3d8 at 1001b3d8

void Unwind_1001b3d8(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b3e0 at 1001b3e0

void Unwind_1001b3e0(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b3e8 at 1001b3e8

void Unwind_1001b3e8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b410 at 1001b410

void Unwind_1001b410(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b418 at 1001b418

void Unwind_1001b418(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b420 at 1001b420

void Unwind_1001b420(void)

{
  int unaff_EBP;
  
  FUN_10008070((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Function: Unwind@1001b428 at 1001b428

void Unwind_1001b428(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001b460 at 1001b460

void Unwind_1001b460(void)

{
  int unaff_EBP;
  
  FUN_1000c110((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001b490 at 1001b490

void Unwind_1001b490(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b498 at 1001b498

void Unwind_1001b498(void)

{
  int unaff_EBP;
  
  FUN_1000c110((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b4c0 at 1001b4c0

void Unwind_1001b4c0(void)

{
  int unaff_EBP;
  
  FUN_1000c110((int *)(unaff_EBP + 0x10));
  return;
}



// Function: Unwind@1001b4f0 at 1001b4f0

void Unwind_1001b4f0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b4fb at 1001b4fb

void Unwind_1001b4fb(void)

{
  int unaff_EBP;
  
  FUN_10008070((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b503 at 1001b503

void Unwind_1001b503(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b506. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b50c at 1001b50c

void Unwind_1001b50c(void)

{
  int unaff_EBP;
  
  FUN_100049f0((exception *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001b530 at 1001b530

void Unwind_1001b530(void)

{
  int unaff_EBP;
  
  FUN_1000dc40((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b560 at 1001b560

void Unwind_1001b560(void)

{
  int unaff_EBP;
  
  FUN_1000dc40((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b590 at 1001b590

void Unwind_1001b590(void)

{
  int unaff_EBP;
  
  FUN_1000ce80(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b5c0 at 1001b5c0

void Unwind_1001b5c0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001b5c8 at 1001b5c8

void Unwind_1001b5c8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// Function: Unwind@1001b5d0 at 1001b5d0

void Unwind_1001b5d0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b5d8 at 1001b5d8

void Unwind_1001b5d8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b5e0 at 1001b5e0

void Unwind_1001b5e0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Function: Unwind@1001b5e8 at 1001b5e8

void Unwind_1001b5e8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b5f0 at 1001b5f0

void Unwind_1001b5f0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x6c));
  return;
}



// Function: Unwind@1001b620 at 1001b620

void Unwind_1001b620(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10));
  return;
}



// Function: Unwind@1001b650 at 1001b650

void Unwind_1001b650(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1001b658 at 1001b658

void Unwind_1001b658(void)

{
  int unaff_EBP;
  
  FUN_1000b9e0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b660 at 1001b660

void Unwind_1001b660(void)

{
  int unaff_EBP;
  
  FUN_1000c300((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b668 at 1001b668

void Unwind_1001b668(void)

{
  int unaff_EBP;
  
  FUN_1000b9e0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b670 at 1001b670

void Unwind_1001b670(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x24);
  return;
}



// Function: Unwind@1001b6a0 at 1001b6a0

void Unwind_1001b6a0(void)

{
  int unaff_EBP;
  
  FUN_1000ce80(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b6a8 at 1001b6a8

void Unwind_1001b6a8(void)

{
  int unaff_EBP;
  
  FUN_10010640((int *)(*(int *)(unaff_EBP + -0x14) + 0x5c));
  return;
}



// Function: Unwind@1001b6b3 at 1001b6b3

void Unwind_1001b6b3(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001b6b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001b6e0 at 1001b6e0

void Unwind_1001b6e0(void)

{
  int unaff_EBP;
  
  FUN_10010640((int *)(*(int *)(unaff_EBP + -0x10) + 0x5c));
  return;
}



// Function: Unwind@1001b6eb at 1001b6eb

void Unwind_1001b6eb(void)

{
  int unaff_EBP;
  
  FUN_1000ce80(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b710 at 1001b710

void Unwind_1001b710(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001b718 at 1001b718

void Unwind_1001b718(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001b740 at 1001b740

void Unwind_1001b740(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001b748 at 1001b748

void Unwind_1001b748(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001b780 at 1001b780

void Unwind_1001b780(void)

{
  int unaff_EBP;
  
  FUN_1000b720((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001b78b at 1001b78b

void Unwind_1001b78b(void)

{
  int unaff_EBP;
  
  FUN_1000bad0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001b796 at 1001b796

void Unwind_1001b796(void)

{
  int unaff_EBP;
  
  FUN_1000c450(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b79e at 1001b79e

void Unwind_1001b79e(void)

{
  int unaff_EBP;
  
  FUN_1000d2b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b7a6 at 1001b7a6

void Unwind_1001b7a6(void)

{
  int unaff_EBP;
  
  FUN_1000dbe0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001b7ae at 1001b7ae

void Unwind_1001b7ae(void)

{
  int unaff_EBP;
  
  FUN_1000d140(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@1001b7b9 at 1001b7b9

void Unwind_1001b7b9(void)

{
  int unaff_EBP;
  
  FUN_100110f0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001b7c4 at 1001b7c4

void Unwind_1001b7c4(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b7cc at 1001b7cc

void Unwind_1001b7cc(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// Function: Unwind@1001b7d7 at 1001b7d7

void Unwind_1001b7d7(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b7df at 1001b7df

void Unwind_1001b7df(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1001b7ea at 1001b7ea

void Unwind_1001b7ea(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b7f2 at 1001b7f2

void Unwind_1001b7f2(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001b7fd at 1001b7fd

void Unwind_1001b7fd(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001b805 at 1001b805

void Unwind_1001b805(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 0x10));
  return;
}



// Function: Unwind@1001b810 at 1001b810

void Unwind_1001b810(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001b81b at 1001b81b

void Unwind_1001b81b(void)

{
  int unaff_EBP;
  
  FUN_1000d990((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@1001b829 at 1001b829

void Unwind_1001b829(void)

{
  int unaff_EBP;
  
  FUN_1000bac0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10c));
  return;
}



// Function: Unwind@1001b837 at 1001b837

void Unwind_1001b837(void)

{
  int unaff_EBP;
  
  FUN_1000cd50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x114));
  return;
}



// Function: Unwind@1001b845 at 1001b845

void Unwind_1001b845(void)

{
  int unaff_EBP;
  
  FUN_10001030((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144));
  return;
}



// Function: Unwind@1001b870 at 1001b870

void Unwind_1001b870(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b878 at 1001b878

void Unwind_1001b878(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0x430));
  return;
}



// Function: Unwind@1001b8b0 at 1001b8b0

void Unwind_1001b8b0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b8b8 at 1001b8b8

void Unwind_1001b8b8(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0x228));
  return;
}



// Function: Unwind@1001b8f0 at 1001b8f0

void Unwind_1001b8f0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001b8f8 at 1001b8f8

void Unwind_1001b8f8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b900 at 1001b900

void Unwind_1001b900(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0xd4));
  return;
}



// Function: Unwind@1001b90b at 1001b90b

void Unwind_1001b90b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b913 at 1001b913

void Unwind_1001b913(void)

{
  int unaff_EBP;
  
  FUN_10002570(*(undefined4 **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001b91e at 1001b91e

void Unwind_1001b91e(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001b926 at 1001b926

void Unwind_1001b926(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001b931 at 1001b931

void Unwind_1001b931(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001b939 at 1001b939

void Unwind_1001b939(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001b944 at 1001b944

void Unwind_1001b944(void)

{
  int unaff_EBP;
  
  FUN_10002570(*(undefined4 **)(unaff_EBP + -0xd8));
  return;
}



// Function: Unwind@1001b980 at 1001b980

void Unwind_1001b980(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b9b0 at 1001b9b0

void Unwind_1001b9b0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001b9b8 at 1001b9b8

void Unwind_1001b9b8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001b9f0 at 1001b9f0

void Unwind_1001b9f0(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0x240));
  return;
}



// Function: Unwind@1001b9fb at 1001b9fb

void Unwind_1001b9fb(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1001ba30 at 1001ba30

void Unwind_1001ba30(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001ba60 at 1001ba60

void Unwind_1001ba60(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0x260));
  return;
}



// Function: Unwind@1001ba6b at 1001ba6b

void Unwind_1001ba6b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x250));
  return;
}



// Function: Unwind@1001ba76 at 1001ba76

void Unwind_1001ba76(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x234));
  return;
}



// Function: Unwind@1001bab0 at 1001bab0

void Unwind_1001bab0(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0x44c));
  return;
}



// Function: Unwind@1001babb at 1001babb

void Unwind_1001babb(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x43c));
  return;
}



// Function: Unwind@1001baf0 at 1001baf0

void Unwind_1001baf0(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001baf8 at 1001baf8

void Unwind_1001baf8(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0xb8));
  return;
}



// Function: Unwind@1001bb03 at 1001bb03

void Unwind_1001bb03(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Function: Unwind@1001bb0b at 1001bb0b

void Unwind_1001bb0b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001bb13 at 1001bb13

void Unwind_1001bb13(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001bb1b at 1001bb1b

void Unwind_1001bb1b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Function: Unwind@1001bb50 at 1001bb50

void Unwind_1001bb50(void)

{
  int unaff_EBP;
  
  FUN_1000dbe0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bb58 at 1001bb58

void Unwind_1001bb58(void)

{
  int unaff_EBP;
  
  FUN_1000d140(*(int *)(unaff_EBP + -0x10) + 0x28);
  return;
}



// Function: Unwind@1001bb63 at 1001bb63

void Unwind_1001bb63(void)

{
  int unaff_EBP;
  
  FUN_100110f0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x6c));
  return;
}



// Function: Unwind@1001bb6e at 1001bb6e

void Unwind_1001bb6e(void)

{
  int unaff_EBP;
  
  FUN_1000d990((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xd8));
  return;
}



// Function: Unwind@1001bb7c at 1001bb7c

void Unwind_1001bb7c(void)

{
  int unaff_EBP;
  
  FUN_1000bac0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10c));
  return;
}



// Function: Unwind@1001bb8a at 1001bb8a

void Unwind_1001bb8a(void)

{
  int unaff_EBP;
  
  FUN_1000cd50((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x114));
  return;
}



// Function: Unwind@1001bb98 at 1001bb98

void Unwind_1001bb98(void)

{
  int unaff_EBP;
  
  FUN_10001030((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144));
  return;
}



// Function: Unwind@1001bba6 at 1001bba6

void Unwind_1001bba6(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// Function: Unwind@1001bbb1 at 1001bbb1

void Unwind_1001bbb1(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x14) + 0xc));
  return;
}



// Function: Unwind@1001bbbc at 1001bbbc

void Unwind_1001bbbc(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x10));
  return;
}



// Function: Unwind@1001bbc7 at 1001bbc7

void Unwind_1001bbc7(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bbcf at 1001bbcf

void Unwind_1001bbcf(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bbd7 at 1001bbd7

void Unwind_1001bbd7(void)

{
  int unaff_EBP;
  
  FUN_1000d2b0(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bbdf at 1001bbdf

void Unwind_1001bbdf(void)

{
  int unaff_EBP;
  
  FUN_1000c450(*(int *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bbe7 at 1001bbe7

void Unwind_1001bbe7(void)

{
  int unaff_EBP;
  
  FUN_1000bad0(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001bbf2 at 1001bbf2

void Unwind_1001bbf2(void)

{
  int unaff_EBP;
  
  FUN_1000b720((undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc));
  return;
}



// Function: Unwind@1001bc20 at 1001bc20

void Unwind_1001bc20(void)

{
  int unaff_EBP;
  
  FUN_10013910(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bc50 at 1001bc50

void Unwind_1001bc50(void)

{
  int unaff_EBP;
  
  FUN_10013910(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bc80 at 1001bc80

void Unwind_1001bc80(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bc83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bc89 at 1001bc89

void Unwind_1001bc89(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x1001bc9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    std::basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>::
    ~basic_ios<wchar_t,struct_std::char_traits<wchar_t>_>
              ((basic_ios<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x70));
    return;
  }
  return;
}



// Function: Unwind@1001bca6 at 1001bca6

void Unwind_1001bca6(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bcac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001bcb2 at 1001bcb2

void Unwind_1001bcb2(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bcb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001bcbb at 1001bcbb

void Unwind_1001bcbb(void)

{
  int unaff_EBP;
  
  FUN_10013af0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x14) + 0x18));
  return;
}



// Function: Unwind@1001bcf0 at 1001bcf0

void Unwind_1001bcf0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bcf6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_>
            ((basic_iostream<wchar_t,struct_std::char_traits<wchar_t>_> *)
             (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1001bcfc at 1001bcfc

void Unwind_1001bcfc(void)

{
  int unaff_EBP;
  
  FUN_10013af0((basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> *)
               (*(int *)(unaff_EBP + -0x10) + -0x58));
  return;
}



// Function: Unwind@1001bd07 at 1001bd07

void Unwind_1001bd07(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bd0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>::
  ~basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>
            (*(basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bd50 at 1001bd50

void Unwind_1001bd50(void)

{
  int unaff_EBP;
  
  FUN_10013ff0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001bd80 at 1001bd80

void Unwind_1001bd80(void)

{
  int unaff_EBP;
  
  FUN_10013ff0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001bd8b at 1001bd8b

void Unwind_1001bd8b(void)

{
  int unaff_EBP;
  
  FUN_10013910(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bdb0 at 1001bdb0

void Unwind_1001bdb0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bdb8 at 1001bdb8

void Unwind_1001bdb8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001bdc0 at 1001bdc0

void Unwind_1001bdc0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bdc8 at 1001bdc8

void Unwind_1001bdc8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001bdd0 at 1001bdd0

void Unwind_1001bdd0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bdd8 at 1001bdd8

void Unwind_1001bdd8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bde0 at 1001bde0

void Unwind_1001bde0(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001bde8 at 1001bde8

void Unwind_1001bde8(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001bdf0 at 1001bdf0

void Unwind_1001bdf0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x34));
  return;
}



// Function: Unwind@1001bdf8 at 1001bdf8

void Unwind_1001bdf8(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001be00 at 1001be00

void Unwind_1001be00(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001be08 at 1001be08

void Unwind_1001be08(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001be10 at 1001be10

void Unwind_1001be10(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001be18 at 1001be18

void Unwind_1001be18(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be20 at 1001be20

void Unwind_1001be20(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001be50 at 1001be50

void Unwind_1001be50(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001be58 at 1001be58

void Unwind_1001be58(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001be60 at 1001be60

void Unwind_1001be60(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001be68 at 1001be68

void Unwind_1001be68(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001be70 at 1001be70

void Unwind_1001be70(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001be78 at 1001be78

void Unwind_1001be78(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be80 at 1001be80

void Unwind_1001be80(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001be88 at 1001be88

void Unwind_1001be88(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001beb0 at 1001beb0

void Unwind_1001beb0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001beb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bee0 at 1001bee0

void Unwind_1001bee0(void)

{
  int unaff_EBP;
  
  FUN_1000bd50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bf10 at 1001bf10

void Unwind_1001bf10(void)

{
  int unaff_EBP;
  
  FUN_1000bd50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001bf40 at 1001bf40

void Unwind_1001bf40(void)

{
  int unaff_EBP;
  
  FUN_10002a70((int *)(unaff_EBP + -200));
  return;
}



// Function: Unwind@1001bf4b at 1001bf4b

void Unwind_1001bf4b(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001bf53 at 1001bf53

void Unwind_1001bf53(void)

{
  int unaff_EBP;
  
  FUN_10002570(*(undefined4 **)(unaff_EBP + -0x30));
  return;
}



// Function: Unwind@1001bf90 at 1001bf90

void Unwind_1001bf90(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001bf93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001bfc0 at 1001bfc0

void Unwind_1001bfc0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001bff0 at 1001bff0

void Unwind_1001bff0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001bff8 at 1001bff8

void Unwind_1001bff8(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c000 at 1001c000

void Unwind_1001c000(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c008 at 1001c008

void Unwind_1001c008(void)

{
  int unaff_EBP;
  
  FUN_10001700(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c030 at 1001c030

void Unwind_1001c030(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c038 at 1001c038

void Unwind_1001c038(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c040 at 1001c040

void Unwind_1001c040(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c048 at 1001c048

void Unwind_1001c048(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c070 at 1001c070

void Unwind_1001c070(void)

{
  int unaff_EBP;
  
  FUN_10014d00(unaff_EBP + -0x2e8);
  return;
}



// Function: Unwind@1001c07b at 1001c07b

void Unwind_1001c07b(void)

{
  int unaff_EBP;
  
  FUN_100053e0((undefined4 *)(unaff_EBP + -0x22c));
  return;
}



// Function: Unwind@1001c086 at 1001c086

void Unwind_1001c086(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c08c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001c092 at 1001c092

void Unwind_1001c092(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c098. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001c09e at 1001c09e

void Unwind_1001c09e(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Function: Unwind@1001c0a9 at 1001c0a9

void Unwind_1001c0a9(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c0af. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::ios_base::~ios_base(*(ios_base **)(unaff_EBP + -0x220));
  return;
}



// Function: Unwind@1001c0e0 at 1001c0e0

void Unwind_1001c0e0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Function: Unwind@1001c0e8 at 1001c0e8

void Unwind_1001c0e8(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c0f0 at 1001c0f0

void Unwind_1001c0f0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c0f8 at 1001c0f8

void Unwind_1001c0f8(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c100 at 1001c100

void Unwind_1001c100(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c103. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001c109 at 1001c109

void Unwind_1001c109(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c111 at 1001c111

void Unwind_1001c111(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c119 at 1001c119

void Unwind_1001c119(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c121 at 1001c121

void Unwind_1001c121(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c160 at 1001c160

void Unwind_1001c160(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c168 at 1001c168

void Unwind_1001c168(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c170 at 1001c170

void Unwind_1001c170(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c178 at 1001c178

void Unwind_1001c178(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c180 at 1001c180

void Unwind_1001c180(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c188 at 1001c188

void Unwind_1001c188(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c190 at 1001c190

void Unwind_1001c190(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c1c0 at 1001c1c0

void Unwind_1001c1c0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c1c8 at 1001c1c8

void Unwind_1001c1c8(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c1d0 at 1001c1d0

void Unwind_1001c1d0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c1d8 at 1001c1d8

void Unwind_1001c1d8(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c1e0 at 1001c1e0

void Unwind_1001c1e0(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c1e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x80));
  return;
}



// Function: Unwind@1001c1e9 at 1001c1e9

void Unwind_1001c1e9(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c1f1 at 1001c1f1

void Unwind_1001c1f1(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c1f9 at 1001c1f9

void Unwind_1001c1f9(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// Function: Unwind@1001c201 at 1001c201

void Unwind_1001c201(void)

{
  int unaff_EBP;
  
  FUN_10006b30((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c240 at 1001c240

void Unwind_1001c240(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c243. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c249 at 1001c249

void Unwind_1001c249(void)

{
  int unaff_EBP;
  
  FUN_100049f0((exception *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c270 at 1001c270

void Unwind_1001c270(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c2a0 at 1001c2a0

void Unwind_1001c2a0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c2d0 at 1001c2d0

void Unwind_1001c2d0(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c2d8 at 1001c2d8

void Unwind_1001c2d8(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c300 at 1001c300

void Unwind_1001c300(void)

{
  int unaff_EBP;
  
  FUN_10004c50(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001c330 at 1001c330

void Unwind_1001c330(void)

{
  int unaff_EBP;
  
  FUN_10004c50(*(int *)(unaff_EBP + -0x10) + 8);
  return;
}



// Function: Unwind@1001c33b at 1001c33b

void Unwind_1001c33b(void)

{
  int unaff_EBP;
  
  FUN_1000b9e0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c360 at 1001c360

void Unwind_1001c360(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c368 at 1001c368

void Unwind_1001c368(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c370 at 1001c370

void Unwind_1001c370(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c378 at 1001c378

void Unwind_1001c378(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c383 at 1001c383

void Unwind_1001c383(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c38b at 1001c38b

void Unwind_1001c38b(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001c396 at 1001c396

void Unwind_1001c396(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c39e at 1001c39e

void Unwind_1001c39e(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001c3a9 at 1001c3a9

void Unwind_1001c3a9(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c3b1 at 1001c3b1

void Unwind_1001c3b1(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 0xc));
  return;
}



// Function: Unwind@1001c3e0 at 1001c3e0

void Unwind_1001c3e0(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c3e8 at 1001c3e8

void Unwind_1001c3e8(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c410 at 1001c410

void Unwind_1001c410(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// Function: Unwind@1001c418 at 1001c418

void Unwind_1001c418(void)

{
  int unaff_EBP;
  
  FUN_10004c60((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// Function: Unwind@1001c420 at 1001c420

void Unwind_1001c420(void)

{
  int unaff_EBP;
  
  FUN_1000c300((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// Function: Unwind@1001c428 at 1001c428

void Unwind_1001c428(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c450 at 1001c450

void Unwind_1001c450(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001c458 at 1001c458

void Unwind_1001c458(void)

{
  int unaff_EBP;
  
  FUN_1000b9e0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c460 at 1001c460

void Unwind_1001c460(void)

{
  int unaff_EBP;
  
  FUN_1000c300((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c468 at 1001c468

void Unwind_1001c468(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c470 at 1001c470

void Unwind_1001c470(void)

{
  int unaff_EBP;
  
  FUN_1000b9e0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c478 at 1001c478

void Unwind_1001c478(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x38);
  return;
}



// Function: Unwind@1001c480 at 1001c480

void Unwind_1001c480(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c483. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::exception::~exception((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c489 at 1001c489

void Unwind_1001c489(void)

{
  int unaff_EBP;
  
  FUN_100049f0((exception *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c4b0 at 1001c4b0

void Unwind_1001c4b0(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c4b8 at 1001c4b8

void Unwind_1001c4b8(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x10));
  return;
}



// Function: Unwind@1001c4e0 at 1001c4e0

void Unwind_1001c4e0(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



// Function: Unwind@1001c4eb at 1001c4eb

void Unwind_1001c4eb(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



// Function: Unwind@1001c4f6 at 1001c4f6

void Unwind_1001c4f6(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(*(int *)(unaff_EBP + -0x10) + 0xc));
  return;
}



// Function: Unwind@1001c501 at 1001c501

void Unwind_1001c501(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c509 at 1001c509

void Unwind_1001c509(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c511 at 1001c511

void Unwind_1001c511(void)

{
  int unaff_EBP;
  
  FUN_10004c40(*(int **)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c540 at 1001c540

void Unwind_1001c540(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c548 at 1001c548

void Unwind_1001c548(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c570 at 1001c570

void Unwind_1001c570(void)

{
  int unaff_EBP;
  
  FUN_10008070((undefined4 *)(unaff_EBP + -0x214));
  return;
}



// Function: Unwind@1001c57b at 1001c57b

void Unwind_1001c57b(void)

{
  int unaff_EBP;
  
  FUN_10008070((undefined4 *)(unaff_EBP + -0x214));
  return;
}



// Function: Unwind@1001c5d0 at 1001c5d0

void Unwind_1001c5d0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c5d8 at 1001c5d8

void Unwind_1001c5d8(void)

{
  int unaff_EBP;
  
  FUN_10005400(*(int **)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c5e0 at 1001c5e0

void Unwind_1001c5e0(void)

{
  int unaff_EBP;
  
  FUN_10004cb0((undefined4 *)(unaff_EBP + -0x84));
  return;
}



// Function: Unwind@1001c5eb at 1001c5eb

void Unwind_1001c5eb(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c5f3 at 1001c5f3

void Unwind_1001c5f3(void)

{
  int unaff_EBP;
  
  FUN_1000c300((undefined4 *)(unaff_EBP + -100));
  return;
}



// Function: Unwind@1001c5fb at 1001c5fb

void Unwind_1001c5fb(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Function: Unwind@1001c603 at 1001c603

void Unwind_1001c603(void)

{
  int unaff_EBP;
  
  FUN_10001700((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c630 at 1001c630

void Unwind_1001c630(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// Function: Unwind@1001c638 at 1001c638

void Unwind_1001c638(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c640 at 1001c640

void Unwind_1001c640(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x18));
  return;
}



// Function: Unwind@1001c648 at 1001c648

void Unwind_1001c648(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c650 at 1001c650

void Unwind_1001c650(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + -0x14));
  return;
}



// Function: Unwind@1001c658 at 1001c658

void Unwind_1001c658(void)

{
  int unaff_EBP;
  
  FUN_10016980((int *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c660 at 1001c660

void Unwind_1001c660(void)

{
  int unaff_EBP;
  
  FUN_10004c50(unaff_EBP + -0x34);
  return;
}



// Function: Unwind@1001c690 at 1001c690

void Unwind_1001c690(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// Function: Unwind@1001c6c0 at 1001c6c0

void Unwind_1001c6c0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c6f0 at 1001c6f0

void Unwind_1001c6f0(void)

{
  int unaff_EBP;
  
  FUN_10004e50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// Function: Unwind@1001c720 at 1001c720

void Unwind_1001c720(void)

{
  int unaff_EBP;
  
  FUN_10005400((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c728 at 1001c728

void Unwind_1001c728(void)

{
  int unaff_EBP;
  
  FUN_100059f0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// Function: Unwind@1001c730 at 1001c730

void Unwind_1001c730(void)

{
  int unaff_EBP;
  
  FUN_10002570((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Function: Unwind@1001c738 at 1001c738

void Unwind_1001c738(void)

{
  int unaff_EBP;
  
  FUN_100058f0((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Function: Unwind@1001c740 at 1001c740

void Unwind_1001c740(void)

{
  int unaff_EBP;
  
  FUN_10004c40((int *)(unaff_EBP + 8));
  return;
}



// Function: Unwind@1001c770 at 1001c770

void Unwind_1001c770(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10001700(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c7b0 at 1001c7b0

void Unwind_1001c7b0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_10002570(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}



// Function: Unwind@1001c7e4 at 1001c7e4

void Unwind_1001c7e4(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x1001c7e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::_Lockit::~_Lockit((_Lockit *)(unaff_EBP + -0x10));
  return;
}



// Function: FUN_1001cb40 at 1001cb40

void FUN_1001cb40(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1001967a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10004650(0x10030e5c);
  DAT_10030e5c = CVehicleClassificationModule::vftable;
  local_8 = 0xffffffff;
  _atexit(FUN_1001ed20);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001e7b0 at 1001e7b0

void FUN_1001e7b0(void)

{
  Ordinal_6(DAT_10030e44);
  return;
}



// Function: FUN_1001e7c0 at 1001e7c0

void FUN_1001e7c0(void)

{
  Ordinal_6(DAT_10030e48);
  return;
}



// Function: FUN_1001e7d0 at 1001e7d0

void FUN_1001e7d0(void)

{
  Ordinal_6(DAT_10030e4c);
  return;
}



// Function: FUN_1001e7e0 at 1001e7e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e7e0(void)

{
  if (7 < DAT_1002e274) {
    operator_delete(DAT_1002e260);
  }
  DAT_1002e274 = 7;
  _DAT_1002e270 = 0;
  DAT_1002e260 = (void *)((uint)DAT_1002e260 & 0xffff0000);
  return;
}



// Function: FUN_1001e820 at 1001e820

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e820(void)

{
  if (7 < DAT_1002e290) {
    operator_delete(DAT_1002e27c);
  }
  DAT_1002e290 = 7;
  _DAT_1002e28c = 0;
  DAT_1002e27c = (void *)((uint)DAT_1002e27c & 0xffff0000);
  return;
}



// Function: FUN_1001e860 at 1001e860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e860(void)

{
  if (7 < DAT_1002e2ac) {
    operator_delete(DAT_1002e298);
  }
  DAT_1002e2ac = 7;
  _DAT_1002e2a8 = 0;
  DAT_1002e298 = (void *)((uint)DAT_1002e298 & 0xffff0000);
  return;
}



// Function: FUN_1001e8a0 at 1001e8a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e8a0(void)

{
  if (7 < DAT_1002e2c8) {
    operator_delete(DAT_1002e2b4);
  }
  DAT_1002e2c8 = 7;
  _DAT_1002e2c4 = 0;
  DAT_1002e2b4 = (void *)((uint)DAT_1002e2b4 & 0xffff0000);
  return;
}



// Function: FUN_1001e8e0 at 1001e8e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e8e0(void)

{
  if (7 < DAT_1002e2e4) {
    operator_delete(DAT_1002e2d0);
  }
  DAT_1002e2e4 = 7;
  _DAT_1002e2e0 = 0;
  DAT_1002e2d0 = (void *)((uint)DAT_1002e2d0 & 0xffff0000);
  return;
}



// Function: FUN_1001e920 at 1001e920

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e920(void)

{
  if (7 < DAT_1002e300) {
    operator_delete(DAT_1002e2ec);
  }
  DAT_1002e300 = 7;
  _DAT_1002e2fc = 0;
  DAT_1002e2ec = (void *)((uint)DAT_1002e2ec & 0xffff0000);
  return;
}



// Function: FUN_1001e960 at 1001e960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e960(void)

{
  if (7 < DAT_1002e31c) {
    operator_delete(DAT_1002e308);
  }
  DAT_1002e31c = 7;
  _DAT_1002e318 = 0;
  DAT_1002e308 = (void *)((uint)DAT_1002e308 & 0xffff0000);
  return;
}



// Function: FUN_1001e9a0 at 1001e9a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e9a0(void)

{
  if (7 < DAT_1002e338) {
    operator_delete(DAT_1002e324);
  }
  DAT_1002e338 = 7;
  _DAT_1002e334 = 0;
  DAT_1002e324 = (void *)((uint)DAT_1002e324 & 0xffff0000);
  return;
}



// Function: FUN_1001e9e0 at 1001e9e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e9e0(void)

{
  if (7 < DAT_1002e354) {
    operator_delete(DAT_1002e340);
  }
  DAT_1002e354 = 7;
  _DAT_1002e350 = 0;
  DAT_1002e340 = (void *)((uint)DAT_1002e340 & 0xffff0000);
  return;
}



// Function: FUN_1001ea20 at 1001ea20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ea20(void)

{
  if (7 < DAT_1002e370) {
    operator_delete(DAT_1002e35c);
  }
  DAT_1002e370 = 7;
  _DAT_1002e36c = 0;
  DAT_1002e35c = (void *)((uint)DAT_1002e35c & 0xffff0000);
  return;
}



// Function: FUN_1001ea60 at 1001ea60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ea60(void)

{
  if (7 < DAT_1002e38c) {
    operator_delete(DAT_1002e378);
  }
  DAT_1002e38c = 7;
  _DAT_1002e388 = 0;
  DAT_1002e378 = (void *)((uint)DAT_1002e378 & 0xffff0000);
  return;
}



// Function: FUN_1001eaa0 at 1001eaa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eaa0(void)

{
  if (7 < DAT_1002e3a8) {
    operator_delete(DAT_1002e394);
  }
  DAT_1002e3a8 = 7;
  _DAT_1002e3a4 = 0;
  DAT_1002e394 = (void *)((uint)DAT_1002e394 & 0xffff0000);
  return;
}



// Function: FUN_1001eae0 at 1001eae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eae0(void)

{
  if (7 < DAT_1002e3c4) {
    operator_delete(DAT_1002e3b0);
  }
  DAT_1002e3c4 = 7;
  _DAT_1002e3c0 = 0;
  DAT_1002e3b0 = (void *)((uint)DAT_1002e3b0 & 0xffff0000);
  return;
}



// Function: FUN_1001eb20 at 1001eb20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eb20(void)

{
  if (7 < DAT_1002e3e0) {
    operator_delete(DAT_1002e3cc);
  }
  DAT_1002e3e0 = 7;
  _DAT_1002e3dc = 0;
  DAT_1002e3cc = (void *)((uint)DAT_1002e3cc & 0xffff0000);
  return;
}



// Function: FUN_1001eb60 at 1001eb60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eb60(void)

{
  if (7 < DAT_1002e3fc) {
    operator_delete(DAT_1002e3e8);
  }
  DAT_1002e3fc = 7;
  _DAT_1002e3f8 = 0;
  DAT_1002e3e8 = (void *)((uint)DAT_1002e3e8 & 0xffff0000);
  return;
}



// Function: FUN_1001eba0 at 1001eba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eba0(void)

{
  if (7 < DAT_1002e418) {
    operator_delete(DAT_1002e404);
  }
  DAT_1002e418 = 7;
  _DAT_1002e414 = 0;
  DAT_1002e404 = (void *)((uint)DAT_1002e404 & 0xffff0000);
  return;
}



// Function: FUN_1001ebe0 at 1001ebe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ebe0(void)

{
  if (7 < DAT_1002e434) {
    operator_delete(DAT_1002e420);
  }
  DAT_1002e434 = 7;
  _DAT_1002e430 = 0;
  DAT_1002e420 = (void *)((uint)DAT_1002e420 & 0xffff0000);
  return;
}



// Function: FUN_1001ec20 at 1001ec20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ec20(void)

{
  if (7 < DAT_1002e450) {
    operator_delete(DAT_1002e43c);
  }
  DAT_1002e450 = 7;
  _DAT_1002e44c = 0;
  DAT_1002e43c = (void *)((uint)DAT_1002e43c & 0xffff0000);
  return;
}



// Function: FUN_1001ec60 at 1001ec60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ec60(void)

{
  if (7 < DAT_1002e46c) {
    operator_delete(DAT_1002e458);
  }
  DAT_1002e46c = 7;
  _DAT_1002e468 = 0;
  DAT_1002e458 = (void *)((uint)DAT_1002e458 & 0xffff0000);
  return;
}



// Function: FUN_1001eca0 at 1001eca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eca0(void)

{
  if (7 < DAT_1002e488) {
    operator_delete(DAT_1002e474);
  }
  DAT_1002e488 = 7;
  _DAT_1002e484 = 0;
  DAT_1002e474 = (void *)((uint)DAT_1002e474 & 0xffff0000);
  return;
}



// Function: FUN_1001ece0 at 1001ece0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ece0(void)

{
  if (7 < DAT_1002e4a4) {
    operator_delete(DAT_1002e490);
  }
  DAT_1002e4a4 = 7;
  _DAT_1002e4a0 = 0;
  DAT_1002e490 = (void *)((uint)DAT_1002e490 & 0xffff0000);
  return;
}



// Function: FUN_1001ed20 at 1001ed20

void FUN_1001ed20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1001967a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0xffffffff;
  FUN_10004700(0x10030e5c);
  ExceptionList = local_10;
  return;
}



// Function: FUN_1001ed70 at 1001ed70

void FUN_1001ed70(void)

{
  Ordinal_6(DAT_10030e88);
  return;
}



// Function: FUN_1001ed80 at 1001ed80

void FUN_1001ed80(void)

{
  Ordinal_6(DAT_10030e8c);
  return;
}



// Function: FUN_1001ed90 at 1001ed90

void FUN_1001ed90(void)

{
  Ordinal_6(DAT_10030e90);
  return;
}



// Function: FUN_1001eda0 at 1001eda0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eda0(void)

{
  if (7 < DAT_1002f1d0) {
    operator_delete(DAT_1002f1bc);
  }
  DAT_1002f1d0 = 7;
  _DAT_1002f1cc = 0;
  DAT_1002f1bc = (void *)((uint)DAT_1002f1bc & 0xffff0000);
  return;
}



// Function: FUN_1001ede0 at 1001ede0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ede0(void)

{
  if (7 < DAT_1002f1ec) {
    operator_delete(DAT_1002f1d8);
  }
  DAT_1002f1ec = 7;
  _DAT_1002f1e8 = 0;
  DAT_1002f1d8 = (void *)((uint)DAT_1002f1d8 & 0xffff0000);
  return;
}



// Function: FUN_1001ee20 at 1001ee20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ee20(void)

{
  if (7 < DAT_1002f208) {
    operator_delete(DAT_1002f1f4);
  }
  DAT_1002f208 = 7;
  _DAT_1002f204 = 0;
  DAT_1002f1f4 = (void *)((uint)DAT_1002f1f4 & 0xffff0000);
  return;
}



// Function: FUN_1001ee60 at 1001ee60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ee60(void)

{
  if (7 < DAT_1002f224) {
    operator_delete(DAT_1002f210);
  }
  DAT_1002f224 = 7;
  _DAT_1002f220 = 0;
  DAT_1002f210 = (void *)((uint)DAT_1002f210 & 0xffff0000);
  return;
}



// Function: FUN_1001eea0 at 1001eea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eea0(void)

{
  if (7 < DAT_1002f240) {
    operator_delete(DAT_1002f22c);
  }
  DAT_1002f240 = 7;
  _DAT_1002f23c = 0;
  DAT_1002f22c = (void *)((uint)DAT_1002f22c & 0xffff0000);
  return;
}



// Function: FUN_1001eee0 at 1001eee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eee0(void)

{
  if (7 < DAT_1002f25c) {
    operator_delete(DAT_1002f248);
  }
  DAT_1002f25c = 7;
  _DAT_1002f258 = 0;
  DAT_1002f248 = (void *)((uint)DAT_1002f248 & 0xffff0000);
  return;
}



// Function: FUN_1001ef20 at 1001ef20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ef20(void)

{
  if (7 < DAT_1002f278) {
    operator_delete(DAT_1002f264);
  }
  DAT_1002f278 = 7;
  _DAT_1002f274 = 0;
  DAT_1002f264 = (void *)((uint)DAT_1002f264 & 0xffff0000);
  return;
}



// Function: FUN_1001ef60 at 1001ef60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ef60(void)

{
  if (7 < DAT_1002f294) {
    operator_delete(DAT_1002f280);
  }
  DAT_1002f294 = 7;
  _DAT_1002f290 = 0;
  DAT_1002f280 = (void *)((uint)DAT_1002f280 & 0xffff0000);
  return;
}



// Function: FUN_1001efa0 at 1001efa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001efa0(void)

{
  if (7 < DAT_1002f2b0) {
    operator_delete(DAT_1002f29c);
  }
  DAT_1002f2b0 = 7;
  _DAT_1002f2ac = 0;
  DAT_1002f29c = (void *)((uint)DAT_1002f29c & 0xffff0000);
  return;
}



// Function: FUN_1001efe0 at 1001efe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001efe0(void)

{
  if (7 < DAT_1002f2cc) {
    operator_delete(DAT_1002f2b8);
  }
  DAT_1002f2cc = 7;
  _DAT_1002f2c8 = 0;
  DAT_1002f2b8 = (void *)((uint)DAT_1002f2b8 & 0xffff0000);
  return;
}



// Function: FUN_1001f020 at 1001f020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f020(void)

{
  if (7 < DAT_1002f2e8) {
    operator_delete(DAT_1002f2d4);
  }
  DAT_1002f2e8 = 7;
  _DAT_1002f2e4 = 0;
  DAT_1002f2d4 = (void *)((uint)DAT_1002f2d4 & 0xffff0000);
  return;
}



// Function: FUN_1001f060 at 1001f060

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f060(void)

{
  if (7 < DAT_1002f304) {
    operator_delete(DAT_1002f2f0);
  }
  DAT_1002f304 = 7;
  _DAT_1002f300 = 0;
  DAT_1002f2f0 = (void *)((uint)DAT_1002f2f0 & 0xffff0000);
  return;
}



// Function: FUN_1001f0a0 at 1001f0a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f0a0(void)

{
  if (7 < DAT_1002f320) {
    operator_delete(DAT_1002f30c);
  }
  DAT_1002f320 = 7;
  _DAT_1002f31c = 0;
  DAT_1002f30c = (void *)((uint)DAT_1002f30c & 0xffff0000);
  return;
}



// Function: FUN_1001f0e0 at 1001f0e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f0e0(void)

{
  if (7 < DAT_1002f33c) {
    operator_delete(DAT_1002f328);
  }
  DAT_1002f33c = 7;
  _DAT_1002f338 = 0;
  DAT_1002f328 = (void *)((uint)DAT_1002f328 & 0xffff0000);
  return;
}



// Function: FUN_1001f120 at 1001f120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f120(void)

{
  if (7 < DAT_1002f358) {
    operator_delete(DAT_1002f344);
  }
  DAT_1002f358 = 7;
  _DAT_1002f354 = 0;
  DAT_1002f344 = (void *)((uint)DAT_1002f344 & 0xffff0000);
  return;
}



// Function: FUN_1001f160 at 1001f160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f160(void)

{
  if (7 < DAT_1002f374) {
    operator_delete(DAT_1002f360);
  }
  DAT_1002f374 = 7;
  _DAT_1002f370 = 0;
  DAT_1002f360 = (void *)((uint)DAT_1002f360 & 0xffff0000);
  return;
}



// Function: FUN_1001f1a0 at 1001f1a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f1a0(void)

{
  if (7 < DAT_1002f390) {
    operator_delete(DAT_1002f37c);
  }
  DAT_1002f390 = 7;
  _DAT_1002f38c = 0;
  DAT_1002f37c = (void *)((uint)DAT_1002f37c & 0xffff0000);
  return;
}



// Function: FUN_1001f1e0 at 1001f1e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f1e0(void)

{
  if (7 < DAT_1002f3ac) {
    operator_delete(DAT_1002f398);
  }
  DAT_1002f3ac = 7;
  _DAT_1002f3a8 = 0;
  DAT_1002f398 = (void *)((uint)DAT_1002f398 & 0xffff0000);
  return;
}



// Function: FUN_1001f220 at 1001f220

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f220(void)

{
  if (7 < DAT_1002f3c8) {
    operator_delete(DAT_1002f3b4);
  }
  DAT_1002f3c8 = 7;
  _DAT_1002f3c4 = 0;
  DAT_1002f3b4 = (void *)((uint)DAT_1002f3b4 & 0xffff0000);
  return;
}



// Function: FUN_1001f260 at 1001f260

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f260(void)

{
  if (7 < DAT_1002f3e4) {
    operator_delete(DAT_1002f3d0);
  }
  DAT_1002f3e4 = 7;
  _DAT_1002f3e0 = 0;
  DAT_1002f3d0 = (void *)((uint)DAT_1002f3d0 & 0xffff0000);
  return;
}



// Function: FUN_1001f2a0 at 1001f2a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f2a0(void)

{
  if (7 < DAT_1002f400) {
    operator_delete(DAT_1002f3ec);
  }
  DAT_1002f400 = 7;
  _DAT_1002f3fc = 0;
  DAT_1002f3ec = (void *)((uint)DAT_1002f3ec & 0xffff0000);
  return;
}



// Function: FUN_1001f2e0 at 1001f2e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f2e0(void)

{
  if (7 < DAT_1002f41c) {
    operator_delete(DAT_1002f408);
  }
  DAT_1002f41c = 7;
  _DAT_1002f418 = 0;
  DAT_1002f408 = (void *)((uint)DAT_1002f408 & 0xffff0000);
  return;
}



// Function: FUN_1001f320 at 1001f320

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f320(void)

{
  if (7 < DAT_1002f438) {
    operator_delete(DAT_1002f424);
  }
  DAT_1002f438 = 7;
  _DAT_1002f434 = 0;
  DAT_1002f424 = (void *)((uint)DAT_1002f424 & 0xffff0000);
  return;
}



// Function: FUN_1001f360 at 1001f360

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f360(void)

{
  if (7 < DAT_1002f454) {
    operator_delete(DAT_1002f440);
  }
  DAT_1002f454 = 7;
  _DAT_1002f450 = 0;
  DAT_1002f440 = (void *)((uint)DAT_1002f440 & 0xffff0000);
  return;
}



// Function: FUN_1001f3a0 at 1001f3a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f3a0(void)

{
  if (7 < DAT_1002f470) {
    operator_delete(DAT_1002f45c);
  }
  DAT_1002f470 = 7;
  _DAT_1002f46c = 0;
  DAT_1002f45c = (void *)((uint)DAT_1002f45c & 0xffff0000);
  return;
}



// Function: FUN_1001f3e0 at 1001f3e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f3e0(void)

{
  if (7 < DAT_1002f48c) {
    operator_delete(DAT_1002f478);
  }
  DAT_1002f48c = 7;
  _DAT_1002f488 = 0;
  DAT_1002f478 = (void *)((uint)DAT_1002f478 & 0xffff0000);
  return;
}



// Function: FUN_1001f420 at 1001f420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f420(void)

{
  if (7 < DAT_1002f4a8) {
    operator_delete(DAT_1002f494);
  }
  DAT_1002f4a8 = 7;
  _DAT_1002f4a4 = 0;
  DAT_1002f494 = (void *)((uint)DAT_1002f494 & 0xffff0000);
  return;
}



// Function: FUN_1001f460 at 1001f460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f460(void)

{
  if (7 < DAT_1002f4c4) {
    operator_delete(DAT_1002f4b0);
  }
  DAT_1002f4c4 = 7;
  _DAT_1002f4c0 = 0;
  DAT_1002f4b0 = (void *)((uint)DAT_1002f4b0 & 0xffff0000);
  return;
}



// Function: FUN_1001f4a0 at 1001f4a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f4a0(void)

{
  if (7 < DAT_1002f4e0) {
    operator_delete(DAT_1002f4cc);
  }
  DAT_1002f4e0 = 7;
  _DAT_1002f4dc = 0;
  DAT_1002f4cc = (void *)((uint)DAT_1002f4cc & 0xffff0000);
  return;
}



// Function: FUN_1001f4e0 at 1001f4e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f4e0(void)

{
  if (7 < DAT_1002f4fc) {
    operator_delete(DAT_1002f4e8);
  }
  DAT_1002f4fc = 7;
  _DAT_1002f4f8 = 0;
  DAT_1002f4e8 = (void *)((uint)DAT_1002f4e8 & 0xffff0000);
  return;
}



// Function: FUN_1001f520 at 1001f520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f520(void)

{
  if (7 < DAT_1002f518) {
    operator_delete(DAT_1002f504);
  }
  DAT_1002f518 = 7;
  _DAT_1002f514 = 0;
  DAT_1002f504 = (void *)((uint)DAT_1002f504 & 0xffff0000);
  return;
}



// Function: FUN_1001f560 at 1001f560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f560(void)

{
  if (7 < DAT_1002f534) {
    operator_delete(DAT_1002f520);
  }
  DAT_1002f534 = 7;
  _DAT_1002f530 = 0;
  DAT_1002f520 = (void *)((uint)DAT_1002f520 & 0xffff0000);
  return;
}



// Function: FUN_1001f5a0 at 1001f5a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f5a0(void)

{
  if (7 < DAT_1002f550) {
    operator_delete(DAT_1002f53c);
  }
  DAT_1002f550 = 7;
  _DAT_1002f54c = 0;
  DAT_1002f53c = (void *)((uint)DAT_1002f53c & 0xffff0000);
  return;
}



// Function: FUN_1001f5e0 at 1001f5e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f5e0(void)

{
  if (7 < DAT_1002f56c) {
    operator_delete(DAT_1002f558);
  }
  DAT_1002f56c = 7;
  _DAT_1002f568 = 0;
  DAT_1002f558 = (void *)((uint)DAT_1002f558 & 0xffff0000);
  return;
}



// Function: FUN_1001f620 at 1001f620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f620(void)

{
  if (7 < DAT_1002f588) {
    operator_delete(DAT_1002f574);
  }
  DAT_1002f588 = 7;
  _DAT_1002f584 = 0;
  DAT_1002f574 = (void *)((uint)DAT_1002f574 & 0xffff0000);
  return;
}



// Function: FUN_1001f660 at 1001f660

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f660(void)

{
  if (7 < DAT_1002f5a4) {
    operator_delete(DAT_1002f590);
  }
  DAT_1002f5a4 = 7;
  _DAT_1002f5a0 = 0;
  DAT_1002f590 = (void *)((uint)DAT_1002f590 & 0xffff0000);
  return;
}



// Function: FUN_1001f6a0 at 1001f6a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f6a0(void)

{
  if (7 < DAT_1002f5c0) {
    operator_delete(DAT_1002f5ac);
  }
  DAT_1002f5c0 = 7;
  _DAT_1002f5bc = 0;
  DAT_1002f5ac = (void *)((uint)DAT_1002f5ac & 0xffff0000);
  return;
}



// Function: FUN_1001f6e0 at 1001f6e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f6e0(void)

{
  if (7 < DAT_1002f5dc) {
    operator_delete(DAT_1002f5c8);
  }
  DAT_1002f5dc = 7;
  _DAT_1002f5d8 = 0;
  DAT_1002f5c8 = (void *)((uint)DAT_1002f5c8 & 0xffff0000);
  return;
}



// Function: FUN_1001f720 at 1001f720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f720(void)

{
  if (7 < DAT_1002f5f8) {
    operator_delete(DAT_1002f5e4);
  }
  DAT_1002f5f8 = 7;
  _DAT_1002f5f4 = 0;
  DAT_1002f5e4 = (void *)((uint)DAT_1002f5e4 & 0xffff0000);
  return;
}



// Function: FUN_1001f760 at 1001f760

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f760(void)

{
  if (7 < DAT_1002f614) {
    operator_delete(DAT_1002f600);
  }
  DAT_1002f614 = 7;
  _DAT_1002f610 = 0;
  DAT_1002f600 = (void *)((uint)DAT_1002f600 & 0xffff0000);
  return;
}



// Function: FUN_1001f7a0 at 1001f7a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f7a0(void)

{
  if (7 < DAT_1002f630) {
    operator_delete(DAT_1002f61c);
  }
  DAT_1002f630 = 7;
  _DAT_1002f62c = 0;
  DAT_1002f61c = (void *)((uint)DAT_1002f61c & 0xffff0000);
  return;
}



// Function: FUN_1001f7e0 at 1001f7e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f7e0(void)

{
  if (7 < DAT_1002f64c) {
    operator_delete(DAT_1002f638);
  }
  DAT_1002f64c = 7;
  _DAT_1002f648 = 0;
  DAT_1002f638 = (void *)((uint)DAT_1002f638 & 0xffff0000);
  return;
}



// Function: FUN_1001f820 at 1001f820

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f820(void)

{
  if (7 < DAT_1002f668) {
    operator_delete(DAT_1002f654);
  }
  DAT_1002f668 = 7;
  _DAT_1002f664 = 0;
  DAT_1002f654 = (void *)((uint)DAT_1002f654 & 0xffff0000);
  return;
}



// Function: FUN_1001f860 at 1001f860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f860(void)

{
  if (7 < DAT_1002f684) {
    operator_delete(DAT_1002f670);
  }
  DAT_1002f684 = 7;
  _DAT_1002f680 = 0;
  DAT_1002f670 = (void *)((uint)DAT_1002f670 & 0xffff0000);
  return;
}



// Function: FUN_1001f8a0 at 1001f8a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f8a0(void)

{
  if (7 < DAT_1002f6a0) {
    operator_delete(DAT_1002f68c);
  }
  DAT_1002f6a0 = 7;
  _DAT_1002f69c = 0;
  DAT_1002f68c = (void *)((uint)DAT_1002f68c & 0xffff0000);
  return;
}



// Function: FUN_1001f8e0 at 1001f8e0

void FUN_1001f8e0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030e94;
  if (DAT_10030e94 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030e94 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030e94 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001f930 at 1001f930

void FUN_1001f930(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030e98;
  if (DAT_10030e98 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030e98 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030e98 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001f980 at 1001f980

void FUN_1001f980(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030e9c;
  if (DAT_10030e9c != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030e9c + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030e9c = (int *)0x0;
  }
  return;
}



// Function: FUN_1001f9d0 at 1001f9d0

void FUN_1001f9d0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ea0;
  if (DAT_10030ea0 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ea0 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ea0 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001fa20 at 1001fa20

void FUN_1001fa20(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ea4;
  if (DAT_10030ea4 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ea4 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ea4 = (int *)0x0;
  }
  return;
}



// Function: FUN_1001fa70 at 1001fa70

void FUN_1001fa70(void)

{
  Ordinal_6(DAT_10030eb4);
  return;
}



// Function: FUN_1001fa80 at 1001fa80

void FUN_1001fa80(void)

{
  Ordinal_6(DAT_10030eb8);
  return;
}



// Function: FUN_1001fa90 at 1001fa90

void FUN_1001fa90(void)

{
  Ordinal_6(DAT_10030ebc);
  return;
}



// Function: FUN_1001faa0 at 1001faa0

void FUN_1001faa0(void)

{
  Ordinal_6(DAT_10030ed4);
  return;
}



// Function: FUN_1001fab0 at 1001fab0

void FUN_1001fab0(void)

{
  Ordinal_6(DAT_10030ed8);
  return;
}



// Function: FUN_1001fac0 at 1001fac0

void FUN_1001fac0(void)

{
  Ordinal_6(DAT_10030edc);
  return;
}



// Function: FUN_1001fad0 at 1001fad0

void FUN_1001fad0(void)

{
  Ordinal_6(DAT_10030ee0);
  return;
}



// Function: FUN_1001fae0 at 1001fae0

void FUN_1001fae0(void)

{
  Ordinal_6(DAT_10030ee4);
  return;
}



// Function: FUN_1001faf0 at 1001faf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001faf0(void)

{
  if (7 < DAT_1002f758) {
    operator_delete(DAT_1002f744);
  }
  DAT_1002f758 = 7;
  _DAT_1002f754 = 0;
  DAT_1002f744 = (void *)((uint)DAT_1002f744 & 0xffff0000);
  return;
}



// Function: FUN_1001fb30 at 1001fb30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fb30(void)

{
  if (7 < DAT_1002f774) {
    operator_delete(DAT_1002f760);
  }
  DAT_1002f774 = 7;
  _DAT_1002f770 = 0;
  DAT_1002f760 = (void *)((uint)DAT_1002f760 & 0xffff0000);
  return;
}



// Function: FUN_1001fb70 at 1001fb70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fb70(void)

{
  if (7 < DAT_1002f790) {
    operator_delete(DAT_1002f77c);
  }
  DAT_1002f790 = 7;
  _DAT_1002f78c = 0;
  DAT_1002f77c = (void *)((uint)DAT_1002f77c & 0xffff0000);
  return;
}



// Function: FUN_1001fbb0 at 1001fbb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fbb0(void)

{
  if (7 < DAT_1002f7ac) {
    operator_delete(DAT_1002f798);
  }
  DAT_1002f7ac = 7;
  _DAT_1002f7a8 = 0;
  DAT_1002f798 = (void *)((uint)DAT_1002f798 & 0xffff0000);
  return;
}



// Function: FUN_1001fbf0 at 1001fbf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fbf0(void)

{
  if (7 < DAT_1002f7c8) {
    operator_delete(DAT_1002f7b4);
  }
  DAT_1002f7c8 = 7;
  _DAT_1002f7c4 = 0;
  DAT_1002f7b4 = (void *)((uint)DAT_1002f7b4 & 0xffff0000);
  return;
}



// Function: FUN_1001fc30 at 1001fc30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fc30(void)

{
  if (7 < DAT_1002f7e4) {
    operator_delete(DAT_1002f7d0);
  }
  DAT_1002f7e4 = 7;
  _DAT_1002f7e0 = 0;
  DAT_1002f7d0 = (void *)((uint)DAT_1002f7d0 & 0xffff0000);
  return;
}



// Function: FUN_1001fc70 at 1001fc70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fc70(void)

{
  if (7 < DAT_1002f800) {
    operator_delete(DAT_1002f7ec);
  }
  DAT_1002f800 = 7;
  _DAT_1002f7fc = 0;
  DAT_1002f7ec = (void *)((uint)DAT_1002f7ec & 0xffff0000);
  return;
}



// Function: FUN_1001fcb0 at 1001fcb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fcb0(void)

{
  if (7 < DAT_1002f81c) {
    operator_delete(DAT_1002f808);
  }
  DAT_1002f81c = 7;
  _DAT_1002f818 = 0;
  DAT_1002f808 = (void *)((uint)DAT_1002f808 & 0xffff0000);
  return;
}



// Function: FUN_1001fcf0 at 1001fcf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fcf0(void)

{
  if (7 < DAT_1002f838) {
    operator_delete(DAT_1002f824);
  }
  DAT_1002f838 = 7;
  _DAT_1002f834 = 0;
  DAT_1002f824 = (void *)((uint)DAT_1002f824 & 0xffff0000);
  return;
}



// Function: FUN_1001fd30 at 1001fd30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fd30(void)

{
  if (7 < DAT_1002f854) {
    operator_delete(DAT_1002f840);
  }
  DAT_1002f854 = 7;
  _DAT_1002f850 = 0;
  DAT_1002f840 = (void *)((uint)DAT_1002f840 & 0xffff0000);
  return;
}



// Function: FUN_1001fd70 at 1001fd70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fd70(void)

{
  if (7 < DAT_1002f870) {
    operator_delete(DAT_1002f85c);
  }
  DAT_1002f870 = 7;
  _DAT_1002f86c = 0;
  DAT_1002f85c = (void *)((uint)DAT_1002f85c & 0xffff0000);
  return;
}



// Function: FUN_1001fdb0 at 1001fdb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fdb0(void)

{
  if (7 < DAT_1002f88c) {
    operator_delete(DAT_1002f878);
  }
  DAT_1002f88c = 7;
  _DAT_1002f888 = 0;
  DAT_1002f878 = (void *)((uint)DAT_1002f878 & 0xffff0000);
  return;
}



// Function: FUN_1001fdf0 at 1001fdf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fdf0(void)

{
  if (7 < DAT_1002f8a8) {
    operator_delete(DAT_1002f894);
  }
  DAT_1002f8a8 = 7;
  _DAT_1002f8a4 = 0;
  DAT_1002f894 = (void *)((uint)DAT_1002f894 & 0xffff0000);
  return;
}



// Function: FUN_1001fe30 at 1001fe30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fe30(void)

{
  if (7 < DAT_1002f8c4) {
    operator_delete(DAT_1002f8b0);
  }
  DAT_1002f8c4 = 7;
  _DAT_1002f8c0 = 0;
  DAT_1002f8b0 = (void *)((uint)DAT_1002f8b0 & 0xffff0000);
  return;
}



// Function: FUN_1001fe70 at 1001fe70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fe70(void)

{
  if (7 < DAT_1002f8e0) {
    operator_delete(DAT_1002f8cc);
  }
  DAT_1002f8e0 = 7;
  _DAT_1002f8dc = 0;
  DAT_1002f8cc = (void *)((uint)DAT_1002f8cc & 0xffff0000);
  return;
}



// Function: FUN_1001feb0 at 1001feb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001feb0(void)

{
  if (7 < DAT_1002f8fc) {
    operator_delete(DAT_1002f8e8);
  }
  DAT_1002f8fc = 7;
  _DAT_1002f8f8 = 0;
  DAT_1002f8e8 = (void *)((uint)DAT_1002f8e8 & 0xffff0000);
  return;
}



// Function: FUN_1001fef0 at 1001fef0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fef0(void)

{
  if (7 < DAT_1002f918) {
    operator_delete(DAT_1002f904);
  }
  DAT_1002f918 = 7;
  _DAT_1002f914 = 0;
  DAT_1002f904 = (void *)((uint)DAT_1002f904 & 0xffff0000);
  return;
}



// Function: FUN_1001ff30 at 1001ff30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ff30(void)

{
  if (7 < DAT_1002f934) {
    operator_delete(DAT_1002f920);
  }
  DAT_1002f934 = 7;
  _DAT_1002f930 = 0;
  DAT_1002f920 = (void *)((uint)DAT_1002f920 & 0xffff0000);
  return;
}



// Function: FUN_1001ff70 at 1001ff70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ff70(void)

{
  if (7 < DAT_1002f950) {
    operator_delete(DAT_1002f93c);
  }
  DAT_1002f950 = 7;
  _DAT_1002f94c = 0;
  DAT_1002f93c = (void *)((uint)DAT_1002f93c & 0xffff0000);
  return;
}



// Function: FUN_1001ffb0 at 1001ffb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ffb0(void)

{
  if (7 < DAT_1002f96c) {
    operator_delete(DAT_1002f958);
  }
  DAT_1002f96c = 7;
  _DAT_1002f968 = 0;
  DAT_1002f958 = (void *)((uint)DAT_1002f958 & 0xffff0000);
  return;
}



// Function: FUN_1001fff0 at 1001fff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001fff0(void)

{
  if (7 < DAT_1002f988) {
    operator_delete(DAT_1002f974);
  }
  DAT_1002f988 = 7;
  _DAT_1002f984 = 0;
  DAT_1002f974 = (void *)((uint)DAT_1002f974 & 0xffff0000);
  return;
}



// Function: FUN_10020030 at 10020030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020030(void)

{
  if (7 < DAT_1002f9a4) {
    operator_delete(DAT_1002f990);
  }
  DAT_1002f9a4 = 7;
  _DAT_1002f9a0 = 0;
  DAT_1002f990 = (void *)((uint)DAT_1002f990 & 0xffff0000);
  return;
}



// Function: FUN_10020070 at 10020070

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020070(void)

{
  if (7 < DAT_1002f9c0) {
    operator_delete(DAT_1002f9ac);
  }
  DAT_1002f9c0 = 7;
  _DAT_1002f9bc = 0;
  DAT_1002f9ac = (void *)((uint)DAT_1002f9ac & 0xffff0000);
  return;
}



// Function: FUN_100200b0 at 100200b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100200b0(void)

{
  if (7 < DAT_1002f9dc) {
    operator_delete(DAT_1002f9c8);
  }
  DAT_1002f9dc = 7;
  _DAT_1002f9d8 = 0;
  DAT_1002f9c8 = (void *)((uint)DAT_1002f9c8 & 0xffff0000);
  return;
}



// Function: FUN_100200f0 at 100200f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100200f0(void)

{
  if (7 < DAT_1002f9f8) {
    operator_delete(DAT_1002f9e4);
  }
  DAT_1002f9f8 = 7;
  _DAT_1002f9f4 = 0;
  DAT_1002f9e4 = (void *)((uint)DAT_1002f9e4 & 0xffff0000);
  return;
}



// Function: FUN_10020130 at 10020130

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020130(void)

{
  if (7 < DAT_1002fa14) {
    operator_delete(DAT_1002fa00);
  }
  DAT_1002fa14 = 7;
  _DAT_1002fa10 = 0;
  DAT_1002fa00 = (void *)((uint)DAT_1002fa00 & 0xffff0000);
  return;
}



// Function: FUN_10020170 at 10020170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020170(void)

{
  if (7 < DAT_1002fa30) {
    operator_delete(DAT_1002fa1c);
  }
  DAT_1002fa30 = 7;
  _DAT_1002fa2c = 0;
  DAT_1002fa1c = (void *)((uint)DAT_1002fa1c & 0xffff0000);
  return;
}



// Function: FUN_100201b0 at 100201b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100201b0(void)

{
  if (7 < DAT_1002fa4c) {
    operator_delete(DAT_1002fa38);
  }
  DAT_1002fa4c = 7;
  _DAT_1002fa48 = 0;
  DAT_1002fa38 = (void *)((uint)DAT_1002fa38 & 0xffff0000);
  return;
}



// Function: FUN_100201f0 at 100201f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100201f0(void)

{
  if (7 < DAT_1002fa68) {
    operator_delete(DAT_1002fa54);
  }
  DAT_1002fa68 = 7;
  _DAT_1002fa64 = 0;
  DAT_1002fa54 = (void *)((uint)DAT_1002fa54 & 0xffff0000);
  return;
}



// Function: FUN_10020230 at 10020230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020230(void)

{
  if (7 < DAT_1002fa84) {
    operator_delete(DAT_1002fa70);
  }
  DAT_1002fa84 = 7;
  _DAT_1002fa80 = 0;
  DAT_1002fa70 = (void *)((uint)DAT_1002fa70 & 0xffff0000);
  return;
}



// Function: FUN_10020270 at 10020270

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020270(void)

{
  if (7 < DAT_1002faa0) {
    operator_delete(DAT_1002fa8c);
  }
  DAT_1002faa0 = 7;
  _DAT_1002fa9c = 0;
  DAT_1002fa8c = (void *)((uint)DAT_1002fa8c & 0xffff0000);
  return;
}



// Function: FUN_100202b0 at 100202b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100202b0(void)

{
  if (7 < DAT_1002fabc) {
    operator_delete(DAT_1002faa8);
  }
  DAT_1002fabc = 7;
  _DAT_1002fab8 = 0;
  DAT_1002faa8 = (void *)((uint)DAT_1002faa8 & 0xffff0000);
  return;
}



// Function: FUN_100202f0 at 100202f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100202f0(void)

{
  if (7 < DAT_1002fad8) {
    operator_delete(DAT_1002fac4);
  }
  DAT_1002fad8 = 7;
  _DAT_1002fad4 = 0;
  DAT_1002fac4 = (void *)((uint)DAT_1002fac4 & 0xffff0000);
  return;
}



// Function: FUN_10020330 at 10020330

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020330(void)

{
  if (7 < DAT_1002faf4) {
    operator_delete(DAT_1002fae0);
  }
  DAT_1002faf4 = 7;
  _DAT_1002faf0 = 0;
  DAT_1002fae0 = (void *)((uint)DAT_1002fae0 & 0xffff0000);
  return;
}



// Function: FUN_10020370 at 10020370

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020370(void)

{
  if (7 < DAT_1002fb10) {
    operator_delete(DAT_1002fafc);
  }
  DAT_1002fb10 = 7;
  _DAT_1002fb0c = 0;
  DAT_1002fafc = (void *)((uint)DAT_1002fafc & 0xffff0000);
  return;
}



// Function: FUN_100203b0 at 100203b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100203b0(void)

{
  if (7 < DAT_1002fb2c) {
    operator_delete(DAT_1002fb18);
  }
  DAT_1002fb2c = 7;
  _DAT_1002fb28 = 0;
  DAT_1002fb18 = (void *)((uint)DAT_1002fb18 & 0xffff0000);
  return;
}



// Function: FUN_100203f0 at 100203f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100203f0(void)

{
  if (7 < DAT_1002fb48) {
    operator_delete(DAT_1002fb34);
  }
  DAT_1002fb48 = 7;
  _DAT_1002fb44 = 0;
  DAT_1002fb34 = (void *)((uint)DAT_1002fb34 & 0xffff0000);
  return;
}



// Function: FUN_10020430 at 10020430

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020430(void)

{
  if (7 < DAT_1002fb64) {
    operator_delete(DAT_1002fb50);
  }
  DAT_1002fb64 = 7;
  _DAT_1002fb60 = 0;
  DAT_1002fb50 = (void *)((uint)DAT_1002fb50 & 0xffff0000);
  return;
}



// Function: FUN_10020470 at 10020470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020470(void)

{
  if (7 < DAT_1002fb80) {
    operator_delete(DAT_1002fb6c);
  }
  DAT_1002fb80 = 7;
  _DAT_1002fb7c = 0;
  DAT_1002fb6c = (void *)((uint)DAT_1002fb6c & 0xffff0000);
  return;
}



// Function: FUN_100204b0 at 100204b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100204b0(void)

{
  if (7 < DAT_1002fb9c) {
    operator_delete(DAT_1002fb88);
  }
  DAT_1002fb9c = 7;
  _DAT_1002fb98 = 0;
  DAT_1002fb88 = (void *)((uint)DAT_1002fb88 & 0xffff0000);
  return;
}



// Function: FUN_100204f0 at 100204f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100204f0(void)

{
  if (7 < DAT_1002fbb8) {
    operator_delete(DAT_1002fba4);
  }
  DAT_1002fbb8 = 7;
  _DAT_1002fbb4 = 0;
  DAT_1002fba4 = (void *)((uint)DAT_1002fba4 & 0xffff0000);
  return;
}



// Function: FUN_10020530 at 10020530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020530(void)

{
  if (7 < DAT_1002fbd4) {
    operator_delete(DAT_1002fbc0);
  }
  DAT_1002fbd4 = 7;
  _DAT_1002fbd0 = 0;
  DAT_1002fbc0 = (void *)((uint)DAT_1002fbc0 & 0xffff0000);
  return;
}



// Function: FUN_10020570 at 10020570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020570(void)

{
  if (7 < DAT_1002fbf0) {
    operator_delete(DAT_1002fbdc);
  }
  DAT_1002fbf0 = 7;
  _DAT_1002fbec = 0;
  DAT_1002fbdc = (void *)((uint)DAT_1002fbdc & 0xffff0000);
  return;
}



// Function: FUN_100205b0 at 100205b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100205b0(void)

{
  if (7 < DAT_1002fc0c) {
    operator_delete(DAT_1002fbf8);
  }
  DAT_1002fc0c = 7;
  _DAT_1002fc08 = 0;
  DAT_1002fbf8 = (void *)((uint)DAT_1002fbf8 & 0xffff0000);
  return;
}



// Function: FUN_100205f0 at 100205f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100205f0(void)

{
  if (7 < DAT_1002fc28) {
    operator_delete(DAT_1002fc14);
  }
  DAT_1002fc28 = 7;
  _DAT_1002fc24 = 0;
  DAT_1002fc14 = (void *)((uint)DAT_1002fc14 & 0xffff0000);
  return;
}



// Function: FUN_10020630 at 10020630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020630(void)

{
  if (7 < DAT_1002fc44) {
    operator_delete(DAT_1002fc30);
  }
  DAT_1002fc44 = 7;
  _DAT_1002fc40 = 0;
  DAT_1002fc30 = (void *)((uint)DAT_1002fc30 & 0xffff0000);
  return;
}



// Function: FUN_10020670 at 10020670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020670(void)

{
  if (7 < DAT_1002fc60) {
    operator_delete(DAT_1002fc4c);
  }
  DAT_1002fc60 = 7;
  _DAT_1002fc5c = 0;
  DAT_1002fc4c = (void *)((uint)DAT_1002fc4c & 0xffff0000);
  return;
}



// Function: FUN_100206b0 at 100206b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100206b0(void)

{
  if (7 < DAT_1002fc7c) {
    operator_delete(DAT_1002fc68);
  }
  DAT_1002fc7c = 7;
  _DAT_1002fc78 = 0;
  DAT_1002fc68 = (void *)((uint)DAT_1002fc68 & 0xffff0000);
  return;
}



// Function: FUN_100206f0 at 100206f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100206f0(void)

{
  if (7 < DAT_1002fc98) {
    operator_delete(DAT_1002fc84);
  }
  DAT_1002fc98 = 7;
  _DAT_1002fc94 = 0;
  DAT_1002fc84 = (void *)((uint)DAT_1002fc84 & 0xffff0000);
  return;
}



// Function: FUN_10020730 at 10020730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020730(void)

{
  if (7 < DAT_1002fcb4) {
    operator_delete(DAT_1002fca0);
  }
  DAT_1002fcb4 = 7;
  _DAT_1002fcb0 = 0;
  DAT_1002fca0 = (void *)((uint)DAT_1002fca0 & 0xffff0000);
  return;
}



// Function: FUN_10020770 at 10020770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020770(void)

{
  if (7 < DAT_1002fcd0) {
    operator_delete(DAT_1002fcbc);
  }
  DAT_1002fcd0 = 7;
  _DAT_1002fccc = 0;
  DAT_1002fcbc = (void *)((uint)DAT_1002fcbc & 0xffff0000);
  return;
}



// Function: FUN_100207b0 at 100207b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100207b0(void)

{
  if (7 < DAT_1002fcec) {
    operator_delete(DAT_1002fcd8);
  }
  DAT_1002fcec = 7;
  _DAT_1002fce8 = 0;
  DAT_1002fcd8 = (void *)((uint)DAT_1002fcd8 & 0xffff0000);
  return;
}



// Function: FUN_100207f0 at 100207f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100207f0(void)

{
  if (7 < DAT_1002fd08) {
    operator_delete(DAT_1002fcf4);
  }
  DAT_1002fd08 = 7;
  _DAT_1002fd04 = 0;
  DAT_1002fcf4 = (void *)((uint)DAT_1002fcf4 & 0xffff0000);
  return;
}



// Function: FUN_10020830 at 10020830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020830(void)

{
  if (7 < DAT_1002fd24) {
    operator_delete(DAT_1002fd10);
  }
  DAT_1002fd24 = 7;
  _DAT_1002fd20 = 0;
  DAT_1002fd10 = (void *)((uint)DAT_1002fd10 & 0xffff0000);
  return;
}



// Function: FUN_10020870 at 10020870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020870(void)

{
  if (7 < DAT_1002fd40) {
    operator_delete(DAT_1002fd2c);
  }
  DAT_1002fd40 = 7;
  _DAT_1002fd3c = 0;
  DAT_1002fd2c = (void *)((uint)DAT_1002fd2c & 0xffff0000);
  return;
}



// Function: FUN_100208b0 at 100208b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100208b0(void)

{
  if (7 < DAT_1002fd5c) {
    operator_delete(DAT_1002fd48);
  }
  DAT_1002fd5c = 7;
  _DAT_1002fd58 = 0;
  DAT_1002fd48 = (void *)((uint)DAT_1002fd48 & 0xffff0000);
  return;
}



// Function: FUN_100208f0 at 100208f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100208f0(void)

{
  if (7 < DAT_1002fd78) {
    operator_delete(DAT_1002fd64);
  }
  DAT_1002fd78 = 7;
  _DAT_1002fd74 = 0;
  DAT_1002fd64 = (void *)((uint)DAT_1002fd64 & 0xffff0000);
  return;
}



// Function: FUN_10020930 at 10020930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020930(void)

{
  if (7 < DAT_1002fd94) {
    operator_delete(DAT_1002fd80);
  }
  DAT_1002fd94 = 7;
  _DAT_1002fd90 = 0;
  DAT_1002fd80 = (void *)((uint)DAT_1002fd80 & 0xffff0000);
  return;
}



// Function: FUN_10020970 at 10020970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020970(void)

{
  if (7 < DAT_1002fdb0) {
    operator_delete(DAT_1002fd9c);
  }
  DAT_1002fdb0 = 7;
  _DAT_1002fdac = 0;
  DAT_1002fd9c = (void *)((uint)DAT_1002fd9c & 0xffff0000);
  return;
}



// Function: FUN_100209b0 at 100209b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100209b0(void)

{
  if (7 < DAT_1002fe54) {
    operator_delete(DAT_1002fe40);
  }
  DAT_1002fe54 = 7;
  _DAT_1002fe50 = 0;
  DAT_1002fe40 = (void *)((uint)DAT_1002fe40 & 0xffff0000);
  return;
}



// Function: FUN_100209f0 at 100209f0

void FUN_100209f0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ec0;
  if (DAT_10030ec0 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ec0 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ec0 = (int *)0x0;
  }
  return;
}



// Function: FUN_10020a40 at 10020a40

void FUN_10020a40(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ec4;
  if (DAT_10030ec4 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ec4 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ec4 = (int *)0x0;
  }
  return;
}



// Function: FUN_10020a90 at 10020a90

void FUN_10020a90(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ec8;
  if (DAT_10030ec8 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ec8 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ec8 = (int *)0x0;
  }
  return;
}



// Function: FUN_10020ae0 at 10020ae0

void FUN_10020ae0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ecc;
  if (DAT_10030ecc != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ecc + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ecc = (int *)0x0;
  }
  return;
}



// Function: FUN_10020b30 at 10020b30

void FUN_10020b30(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ed0;
  if (DAT_10030ed0 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ed0 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ed0 = (int *)0x0;
  }
  return;
}



// Function: FUN_10020b80 at 10020b80

void FUN_10020b80(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030ee8;
  if (DAT_10030ee8 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030ee8 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030ee8 = (int *)0x0;
  }
  return;
}



// Function: FUN_10020bd0 at 10020bd0

void FUN_10020bd0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030eec;
  if (DAT_10030eec != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030eec + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030eec = (int *)0x0;
  }
  return;
}



// Function: FUN_10020c20 at 10020c20

void FUN_10020c20(void)

{
  Ordinal_6(DAT_10030ef8);
  return;
}



// Function: FUN_10020c30 at 10020c30

void FUN_10020c30(void)

{
  Ordinal_6(DAT_10030efc);
  return;
}



// Function: FUN_10020c40 at 10020c40

void FUN_10020c40(void)

{
  Ordinal_6(DAT_10030f00);
  return;
}



// Function: FUN_10020c50 at 10020c50

void FUN_10020c50(void)

{
  Ordinal_6(DAT_10030f18);
  return;
}



// Function: FUN_10020c60 at 10020c60

void FUN_10020c60(void)

{
  Ordinal_6(DAT_10030f1c);
  return;
}



// Function: FUN_10020c70 at 10020c70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020c70(void)

{
  if (7 < DAT_100306b8) {
    operator_delete(DAT_100306a4);
  }
  DAT_100306b8 = 7;
  _DAT_100306b4 = 0;
  DAT_100306a4 = (void *)((uint)DAT_100306a4 & 0xffff0000);
  return;
}



// Function: FUN_10020cb0 at 10020cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020cb0(void)

{
  if (7 < DAT_100306d4) {
    operator_delete(DAT_100306c0);
  }
  DAT_100306d4 = 7;
  _DAT_100306d0 = 0;
  DAT_100306c0 = (void *)((uint)DAT_100306c0 & 0xffff0000);
  return;
}



// Function: FUN_10020cf0 at 10020cf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020cf0(void)

{
  if (7 < DAT_100306f0) {
    operator_delete(DAT_100306dc);
  }
  DAT_100306f0 = 7;
  _DAT_100306ec = 0;
  DAT_100306dc = (void *)((uint)DAT_100306dc & 0xffff0000);
  return;
}



// Function: FUN_10020d30 at 10020d30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020d30(void)

{
  if (7 < DAT_1003070c) {
    operator_delete(DAT_100306f8);
  }
  DAT_1003070c = 7;
  _DAT_10030708 = 0;
  DAT_100306f8 = (void *)((uint)DAT_100306f8 & 0xffff0000);
  return;
}



// Function: FUN_10020d70 at 10020d70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020d70(void)

{
  if (7 < DAT_10030728) {
    operator_delete(DAT_10030714);
  }
  DAT_10030728 = 7;
  _DAT_10030724 = 0;
  DAT_10030714 = (void *)((uint)DAT_10030714 & 0xffff0000);
  return;
}



// Function: FUN_10020db0 at 10020db0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020db0(void)

{
  if (7 < DAT_10030744) {
    operator_delete(DAT_10030730);
  }
  DAT_10030744 = 7;
  _DAT_10030740 = 0;
  DAT_10030730 = (void *)((uint)DAT_10030730 & 0xffff0000);
  return;
}



// Function: FUN_10020df0 at 10020df0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020df0(void)

{
  if (7 < DAT_10030760) {
    operator_delete(DAT_1003074c);
  }
  DAT_10030760 = 7;
  _DAT_1003075c = 0;
  DAT_1003074c = (void *)((uint)DAT_1003074c & 0xffff0000);
  return;
}



// Function: FUN_10020e30 at 10020e30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020e30(void)

{
  if (7 < DAT_1003077c) {
    operator_delete(DAT_10030768);
  }
  DAT_1003077c = 7;
  _DAT_10030778 = 0;
  DAT_10030768 = (void *)((uint)DAT_10030768 & 0xffff0000);
  return;
}



// Function: FUN_10020e70 at 10020e70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020e70(void)

{
  if (7 < DAT_10030798) {
    operator_delete(DAT_10030784);
  }
  DAT_10030798 = 7;
  _DAT_10030794 = 0;
  DAT_10030784 = (void *)((uint)DAT_10030784 & 0xffff0000);
  return;
}



// Function: FUN_10020eb0 at 10020eb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020eb0(void)

{
  if (7 < DAT_100307b4) {
    operator_delete(DAT_100307a0);
  }
  DAT_100307b4 = 7;
  _DAT_100307b0 = 0;
  DAT_100307a0 = (void *)((uint)DAT_100307a0 & 0xffff0000);
  return;
}



// Function: FUN_10020ef0 at 10020ef0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020ef0(void)

{
  if (7 < DAT_100307d0) {
    operator_delete(DAT_100307bc);
  }
  DAT_100307d0 = 7;
  _DAT_100307cc = 0;
  DAT_100307bc = (void *)((uint)DAT_100307bc & 0xffff0000);
  return;
}



// Function: FUN_10020f30 at 10020f30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020f30(void)

{
  if (7 < DAT_100307ec) {
    operator_delete(DAT_100307d8);
  }
  DAT_100307ec = 7;
  _DAT_100307e8 = 0;
  DAT_100307d8 = (void *)((uint)DAT_100307d8 & 0xffff0000);
  return;
}



// Function: FUN_10020f70 at 10020f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020f70(void)

{
  if (7 < DAT_10030808) {
    operator_delete(DAT_100307f4);
  }
  DAT_10030808 = 7;
  _DAT_10030804 = 0;
  DAT_100307f4 = (void *)((uint)DAT_100307f4 & 0xffff0000);
  return;
}



// Function: FUN_10020fb0 at 10020fb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020fb0(void)

{
  if (7 < DAT_10030824) {
    operator_delete(DAT_10030810);
  }
  DAT_10030824 = 7;
  _DAT_10030820 = 0;
  DAT_10030810 = (void *)((uint)DAT_10030810 & 0xffff0000);
  return;
}



// Function: FUN_10020ff0 at 10020ff0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10020ff0(void)

{
  if (7 < DAT_10030840) {
    operator_delete(DAT_1003082c);
  }
  DAT_10030840 = 7;
  _DAT_1003083c = 0;
  DAT_1003082c = (void *)((uint)DAT_1003082c & 0xffff0000);
  return;
}



// Function: FUN_10021030 at 10021030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021030(void)

{
  if (7 < DAT_1003085c) {
    operator_delete(DAT_10030848);
  }
  DAT_1003085c = 7;
  _DAT_10030858 = 0;
  DAT_10030848 = (void *)((uint)DAT_10030848 & 0xffff0000);
  return;
}



// Function: FUN_10021070 at 10021070

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021070(void)

{
  if (7 < DAT_10030878) {
    operator_delete(DAT_10030864);
  }
  DAT_10030878 = 7;
  _DAT_10030874 = 0;
  DAT_10030864 = (void *)((uint)DAT_10030864 & 0xffff0000);
  return;
}



// Function: FUN_100210b0 at 100210b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100210b0(void)

{
  if (7 < DAT_10030894) {
    operator_delete(DAT_10030880);
  }
  DAT_10030894 = 7;
  _DAT_10030890 = 0;
  DAT_10030880 = (void *)((uint)DAT_10030880 & 0xffff0000);
  return;
}



// Function: FUN_100210f0 at 100210f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100210f0(void)

{
  if (7 < DAT_100308b0) {
    operator_delete(DAT_1003089c);
  }
  DAT_100308b0 = 7;
  _DAT_100308ac = 0;
  DAT_1003089c = (void *)((uint)DAT_1003089c & 0xffff0000);
  return;
}



// Function: FUN_10021130 at 10021130

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021130(void)

{
  if (7 < DAT_100308cc) {
    operator_delete(DAT_100308b8);
  }
  DAT_100308cc = 7;
  _DAT_100308c8 = 0;
  DAT_100308b8 = (void *)((uint)DAT_100308b8 & 0xffff0000);
  return;
}



// Function: FUN_10021170 at 10021170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021170(void)

{
  if (7 < DAT_100308e8) {
    operator_delete(DAT_100308d4);
  }
  DAT_100308e8 = 7;
  _DAT_100308e4 = 0;
  DAT_100308d4 = (void *)((uint)DAT_100308d4 & 0xffff0000);
  return;
}



// Function: FUN_100211b0 at 100211b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100211b0(void)

{
  if (7 < DAT_10030904) {
    operator_delete(DAT_100308f0);
  }
  DAT_10030904 = 7;
  _DAT_10030900 = 0;
  DAT_100308f0 = (void *)((uint)DAT_100308f0 & 0xffff0000);
  return;
}



// Function: FUN_100211f0 at 100211f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100211f0(void)

{
  if (7 < DAT_10030920) {
    operator_delete(DAT_1003090c);
  }
  DAT_10030920 = 7;
  _DAT_1003091c = 0;
  DAT_1003090c = (void *)((uint)DAT_1003090c & 0xffff0000);
  return;
}



// Function: FUN_10021230 at 10021230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021230(void)

{
  if (7 < DAT_1003093c) {
    operator_delete(DAT_10030928);
  }
  DAT_1003093c = 7;
  _DAT_10030938 = 0;
  DAT_10030928 = (void *)((uint)DAT_10030928 & 0xffff0000);
  return;
}



// Function: FUN_10021270 at 10021270

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021270(void)

{
  if (7 < DAT_10030958) {
    operator_delete(DAT_10030944);
  }
  DAT_10030958 = 7;
  _DAT_10030954 = 0;
  DAT_10030944 = (void *)((uint)DAT_10030944 & 0xffff0000);
  return;
}



// Function: FUN_100212b0 at 100212b0

void FUN_100212b0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030f04;
  if (DAT_10030f04 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030f04 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030f04 = (int *)0x0;
  }
  return;
}



// Function: FUN_10021300 at 10021300

void FUN_10021300(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030f08;
  if (DAT_10030f08 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030f08 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030f08 = (int *)0x0;
  }
  return;
}



// Function: FUN_10021350 at 10021350

void FUN_10021350(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030f0c;
  if (DAT_10030f0c != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030f0c + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030f0c = (int *)0x0;
  }
  return;
}



// Function: FUN_100213a0 at 100213a0

void FUN_100213a0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030f10;
  if (DAT_10030f10 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030f10 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030f10 = (int *)0x0;
  }
  return;
}



// Function: FUN_100213f0 at 100213f0

void FUN_100213f0(void)

{
  int *piVar1;
  LONG LVar2;
  
  piVar1 = DAT_10030f14;
  if (DAT_10030f14 != (int *)0x0) {
    LVar2 = InterlockedDecrement(DAT_10030f14 + 2);
    if ((LVar2 == 0) && (piVar1 != (int *)0x0)) {
      if (*piVar1 != 0) {
        Ordinal_6(*piVar1);
      }
      if ((void *)piVar1[1] != (void *)0x0) {
        operator_delete__((void *)piVar1[1]);
      }
      operator_delete(piVar1);
    }
    DAT_10030f14 = (int *)0x0;
  }
  return;
}



// Function: FUN_10021440 at 10021440

void FUN_10021440(void)

{
  Ordinal_6(DAT_10030f20);
  return;
}



// Function: FUN_10021450 at 10021450

void FUN_10021450(void)

{
  Ordinal_6(DAT_10030f24);
  return;
}



// Function: FUN_10021460 at 10021460

void FUN_10021460(void)

{
  Ordinal_6(DAT_10030f28);
  return;
}



// Function: FUN_10021470 at 10021470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021470(void)

{
  if (7 < DAT_10030974) {
    operator_delete(DAT_10030960);
  }
  DAT_10030974 = 7;
  _DAT_10030970 = 0;
  DAT_10030960 = (void *)((uint)DAT_10030960 & 0xffff0000);
  return;
}



// Function: FUN_100214b0 at 100214b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100214b0(void)

{
  if (7 < DAT_10030990) {
    operator_delete(DAT_1003097c);
  }
  DAT_10030990 = 7;
  _DAT_1003098c = 0;
  DAT_1003097c = (void *)((uint)DAT_1003097c & 0xffff0000);
  return;
}



// Function: FUN_100214f0 at 100214f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100214f0(void)

{
  if (7 < DAT_100309ac) {
    operator_delete(DAT_10030998);
  }
  DAT_100309ac = 7;
  _DAT_100309a8 = 0;
  DAT_10030998 = (void *)((uint)DAT_10030998 & 0xffff0000);
  return;
}



// Function: FUN_10021530 at 10021530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021530(void)

{
  if (7 < DAT_100309c8) {
    operator_delete(DAT_100309b4);
  }
  DAT_100309c8 = 7;
  _DAT_100309c4 = 0;
  DAT_100309b4 = (void *)((uint)DAT_100309b4 & 0xffff0000);
  return;
}



// Function: FUN_10021570 at 10021570

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021570(void)

{
  if (7 < DAT_100309e4) {
    operator_delete(DAT_100309d0);
  }
  DAT_100309e4 = 7;
  _DAT_100309e0 = 0;
  DAT_100309d0 = (void *)((uint)DAT_100309d0 & 0xffff0000);
  return;
}



// Function: FUN_100215b0 at 100215b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100215b0(void)

{
  if (7 < DAT_10030a00) {
    operator_delete(DAT_100309ec);
  }
  DAT_10030a00 = 7;
  _DAT_100309fc = 0;
  DAT_100309ec = (void *)((uint)DAT_100309ec & 0xffff0000);
  return;
}



// Function: FUN_100215f0 at 100215f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100215f0(void)

{
  if (7 < DAT_10030a1c) {
    operator_delete(DAT_10030a08);
  }
  DAT_10030a1c = 7;
  _DAT_10030a18 = 0;
  DAT_10030a08 = (void *)((uint)DAT_10030a08 & 0xffff0000);
  return;
}



// Function: FUN_10021630 at 10021630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021630(void)

{
  if (7 < DAT_10030a38) {
    operator_delete(DAT_10030a24);
  }
  DAT_10030a38 = 7;
  _DAT_10030a34 = 0;
  DAT_10030a24 = (void *)((uint)DAT_10030a24 & 0xffff0000);
  return;
}



// Function: FUN_10021670 at 10021670

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021670(void)

{
  if (7 < DAT_10030a54) {
    operator_delete(DAT_10030a40);
  }
  DAT_10030a54 = 7;
  _DAT_10030a50 = 0;
  DAT_10030a40 = (void *)((uint)DAT_10030a40 & 0xffff0000);
  return;
}



// Function: FUN_100216b0 at 100216b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100216b0(void)

{
  if (7 < DAT_10030a70) {
    operator_delete(DAT_10030a5c);
  }
  DAT_10030a70 = 7;
  _DAT_10030a6c = 0;
  DAT_10030a5c = (void *)((uint)DAT_10030a5c & 0xffff0000);
  return;
}



// Function: FUN_100216f0 at 100216f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100216f0(void)

{
  if (7 < DAT_10030a8c) {
    operator_delete(DAT_10030a78);
  }
  DAT_10030a8c = 7;
  _DAT_10030a88 = 0;
  DAT_10030a78 = (void *)((uint)DAT_10030a78 & 0xffff0000);
  return;
}



// Function: FUN_10021730 at 10021730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021730(void)

{
  if (7 < DAT_10030aa8) {
    operator_delete(DAT_10030a94);
  }
  DAT_10030aa8 = 7;
  _DAT_10030aa4 = 0;
  DAT_10030a94 = (void *)((uint)DAT_10030a94 & 0xffff0000);
  return;
}



// Function: FUN_10021770 at 10021770

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021770(void)

{
  if (7 < DAT_10030ac4) {
    operator_delete(DAT_10030ab0);
  }
  DAT_10030ac4 = 7;
  _DAT_10030ac0 = 0;
  DAT_10030ab0 = (void *)((uint)DAT_10030ab0 & 0xffff0000);
  return;
}



// Function: FUN_100217b0 at 100217b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100217b0(void)

{
  if (7 < DAT_10030ae0) {
    operator_delete(DAT_10030acc);
  }
  DAT_10030ae0 = 7;
  _DAT_10030adc = 0;
  DAT_10030acc = (void *)((uint)DAT_10030acc & 0xffff0000);
  return;
}



// Function: FUN_100217f0 at 100217f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100217f0(void)

{
  if (7 < DAT_10030afc) {
    operator_delete(DAT_10030ae8);
  }
  DAT_10030afc = 7;
  _DAT_10030af8 = 0;
  DAT_10030ae8 = (void *)((uint)DAT_10030ae8 & 0xffff0000);
  return;
}



// Function: FUN_10021830 at 10021830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021830(void)

{
  if (7 < DAT_10030b18) {
    operator_delete(DAT_10030b04);
  }
  DAT_10030b18 = 7;
  _DAT_10030b14 = 0;
  DAT_10030b04 = (void *)((uint)DAT_10030b04 & 0xffff0000);
  return;
}



// Function: FUN_10021870 at 10021870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021870(void)

{
  if (7 < DAT_10030b34) {
    operator_delete(DAT_10030b20);
  }
  DAT_10030b34 = 7;
  _DAT_10030b30 = 0;
  DAT_10030b20 = (void *)((uint)DAT_10030b20 & 0xffff0000);
  return;
}



// Function: FUN_100218b0 at 100218b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100218b0(void)

{
  if (7 < DAT_10030b50) {
    operator_delete(DAT_10030b3c);
  }
  DAT_10030b50 = 7;
  _DAT_10030b4c = 0;
  DAT_10030b3c = (void *)((uint)DAT_10030b3c & 0xffff0000);
  return;
}



// Function: FUN_100218f0 at 100218f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100218f0(void)

{
  if (7 < DAT_10030b6c) {
    operator_delete(DAT_10030b58);
  }
  DAT_10030b6c = 7;
  _DAT_10030b68 = 0;
  DAT_10030b58 = (void *)((uint)DAT_10030b58 & 0xffff0000);
  return;
}



// Function: FUN_10021930 at 10021930

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021930(void)

{
  if (7 < DAT_10030b88) {
    operator_delete(DAT_10030b74);
  }
  DAT_10030b88 = 7;
  _DAT_10030b84 = 0;
  DAT_10030b74 = (void *)((uint)DAT_10030b74 & 0xffff0000);
  return;
}



// Function: FUN_10021970 at 10021970

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021970(void)

{
  if (7 < DAT_10030ba4) {
    operator_delete(DAT_10030b90);
  }
  DAT_10030ba4 = 7;
  _DAT_10030ba0 = 0;
  DAT_10030b90 = (void *)((uint)DAT_10030b90 & 0xffff0000);
  return;
}



// Function: FUN_100219b0 at 100219b0

void FUN_100219b0(void)

{
  Ordinal_6(DAT_10030f2c);
  return;
}



// Function: FUN_100219c0 at 100219c0

void FUN_100219c0(void)

{
  Ordinal_6(DAT_10030f30);
  return;
}



// Function: FUN_100219d0 at 100219d0

void FUN_100219d0(void)

{
  Ordinal_6(DAT_10030f34);
  return;
}



// Function: FUN_100219e0 at 100219e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100219e0(void)

{
  if (7 < DAT_10030bc0) {
    operator_delete(DAT_10030bac);
  }
  DAT_10030bc0 = 7;
  _DAT_10030bbc = 0;
  DAT_10030bac = (void *)((uint)DAT_10030bac & 0xffff0000);
  return;
}



// Function: FUN_10021a20 at 10021a20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021a20(void)

{
  if (7 < DAT_10030bdc) {
    operator_delete(DAT_10030bc8);
  }
  DAT_10030bdc = 7;
  _DAT_10030bd8 = 0;
  DAT_10030bc8 = (void *)((uint)DAT_10030bc8 & 0xffff0000);
  return;
}



// Function: FUN_10021a60 at 10021a60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021a60(void)

{
  if (7 < DAT_10030bf8) {
    operator_delete(DAT_10030be4);
  }
  DAT_10030bf8 = 7;
  _DAT_10030bf4 = 0;
  DAT_10030be4 = (void *)((uint)DAT_10030be4 & 0xffff0000);
  return;
}



// Function: FUN_10021aa0 at 10021aa0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021aa0(void)

{
  if (7 < DAT_10030c14) {
    operator_delete(DAT_10030c00);
  }
  DAT_10030c14 = 7;
  _DAT_10030c10 = 0;
  DAT_10030c00 = (void *)((uint)DAT_10030c00 & 0xffff0000);
  return;
}



// Function: FUN_10021ae0 at 10021ae0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ae0(void)

{
  if (7 < DAT_10030c30) {
    operator_delete(DAT_10030c1c);
  }
  DAT_10030c30 = 7;
  _DAT_10030c2c = 0;
  DAT_10030c1c = (void *)((uint)DAT_10030c1c & 0xffff0000);
  return;
}



// Function: FUN_10021b20 at 10021b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021b20(void)

{
  if (7 < DAT_10030c4c) {
    operator_delete(DAT_10030c38);
  }
  DAT_10030c4c = 7;
  _DAT_10030c48 = 0;
  DAT_10030c38 = (void *)((uint)DAT_10030c38 & 0xffff0000);
  return;
}



// Function: FUN_10021b60 at 10021b60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021b60(void)

{
  if (7 < DAT_10030c68) {
    operator_delete(DAT_10030c54);
  }
  DAT_10030c68 = 7;
  _DAT_10030c64 = 0;
  DAT_10030c54 = (void *)((uint)DAT_10030c54 & 0xffff0000);
  return;
}



// Function: FUN_10021ba0 at 10021ba0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ba0(void)

{
  if (7 < DAT_10030c84) {
    operator_delete(DAT_10030c70);
  }
  DAT_10030c84 = 7;
  _DAT_10030c80 = 0;
  DAT_10030c70 = (void *)((uint)DAT_10030c70 & 0xffff0000);
  return;
}



// Function: FUN_10021be0 at 10021be0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021be0(void)

{
  if (7 < DAT_10030ca0) {
    operator_delete(DAT_10030c8c);
  }
  DAT_10030ca0 = 7;
  _DAT_10030c9c = 0;
  DAT_10030c8c = (void *)((uint)DAT_10030c8c & 0xffff0000);
  return;
}



// Function: FUN_10021c20 at 10021c20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021c20(void)

{
  if (7 < DAT_10030cbc) {
    operator_delete(DAT_10030ca8);
  }
  DAT_10030cbc = 7;
  _DAT_10030cb8 = 0;
  DAT_10030ca8 = (void *)((uint)DAT_10030ca8 & 0xffff0000);
  return;
}



// Function: FUN_10021c60 at 10021c60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021c60(void)

{
  if (7 < DAT_10030cd8) {
    operator_delete(DAT_10030cc4);
  }
  DAT_10030cd8 = 7;
  _DAT_10030cd4 = 0;
  DAT_10030cc4 = (void *)((uint)DAT_10030cc4 & 0xffff0000);
  return;
}



// Function: FUN_10021ca0 at 10021ca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ca0(void)

{
  if (7 < DAT_10030cf4) {
    operator_delete(DAT_10030ce0);
  }
  DAT_10030cf4 = 7;
  _DAT_10030cf0 = 0;
  DAT_10030ce0 = (void *)((uint)DAT_10030ce0 & 0xffff0000);
  return;
}



// Function: FUN_10021ce0 at 10021ce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ce0(void)

{
  if (7 < DAT_10030d10) {
    operator_delete(DAT_10030cfc);
  }
  DAT_10030d10 = 7;
  _DAT_10030d0c = 0;
  DAT_10030cfc = (void *)((uint)DAT_10030cfc & 0xffff0000);
  return;
}



// Function: FUN_10021d20 at 10021d20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021d20(void)

{
  if (7 < DAT_10030d2c) {
    operator_delete(DAT_10030d18);
  }
  DAT_10030d2c = 7;
  _DAT_10030d28 = 0;
  DAT_10030d18 = (void *)((uint)DAT_10030d18 & 0xffff0000);
  return;
}



// Function: FUN_10021d60 at 10021d60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021d60(void)

{
  if (7 < DAT_10030d48) {
    operator_delete(DAT_10030d34);
  }
  DAT_10030d48 = 7;
  _DAT_10030d44 = 0;
  DAT_10030d34 = (void *)((uint)DAT_10030d34 & 0xffff0000);
  return;
}



// Function: FUN_10021da0 at 10021da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021da0(void)

{
  if (7 < DAT_10030d64) {
    operator_delete(DAT_10030d50);
  }
  DAT_10030d64 = 7;
  _DAT_10030d60 = 0;
  DAT_10030d50 = (void *)((uint)DAT_10030d50 & 0xffff0000);
  return;
}



// Function: FUN_10021de0 at 10021de0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021de0(void)

{
  if (7 < DAT_10030d80) {
    operator_delete(DAT_10030d6c);
  }
  DAT_10030d80 = 7;
  _DAT_10030d7c = 0;
  DAT_10030d6c = (void *)((uint)DAT_10030d6c & 0xffff0000);
  return;
}



// Function: FUN_10021e20 at 10021e20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021e20(void)

{
  if (7 < DAT_10030d9c) {
    operator_delete(DAT_10030d88);
  }
  DAT_10030d9c = 7;
  _DAT_10030d98 = 0;
  DAT_10030d88 = (void *)((uint)DAT_10030d88 & 0xffff0000);
  return;
}



// Function: FUN_10021e60 at 10021e60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021e60(void)

{
  if (7 < DAT_10030db8) {
    operator_delete(DAT_10030da4);
  }
  DAT_10030db8 = 7;
  _DAT_10030db4 = 0;
  DAT_10030da4 = (void *)((uint)DAT_10030da4 & 0xffff0000);
  return;
}



// Function: FUN_10021ea0 at 10021ea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ea0(void)

{
  if (7 < DAT_10030dd4) {
    operator_delete(DAT_10030dc0);
  }
  DAT_10030dd4 = 7;
  _DAT_10030dd0 = 0;
  DAT_10030dc0 = (void *)((uint)DAT_10030dc0 & 0xffff0000);
  return;
}



// Function: FUN_10021ee0 at 10021ee0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021ee0(void)

{
  if (7 < DAT_10030df0) {
    operator_delete(DAT_10030ddc);
  }
  DAT_10030df0 = 7;
  _DAT_10030dec = 0;
  DAT_10030ddc = (void *)((uint)DAT_10030ddc & 0xffff0000);
  return;
}



// Function: FUN_10021f15 at 10021f15

void FUN_10021f15(void)

{
  FUN_10018752((int *)&DAT_1003126c);
  return;
}



// Function: FUN_10021f1f at 10021f1f

void FUN_10021f1f(void)

{
  FUN_10018834(0x10031294);
  return;
}



// Function: FUN_10021f29 at 10021f29

void FUN_10021f29(void)

{
  ATL::AtlWinModuleTerm((_ATL_WIN_MODULE70 *)&DAT_100312d0,DAT_10031298);
  FUN_10003f60((undefined4 *)&DAT_100312f0);
  return;
}



// Function: FUN_10021f43 at 10021f43

void FUN_10021f43(void)

{
  FUN_10018cb8();
  return;
}



