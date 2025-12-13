/*
 * Decompiled from: WiggleTest_en.dll
 * Using Ghidra 11.4.1
 */

// Function: FUN_6f3e1000 at 6f3e1000

undefined4 FUN_6f3e1000(void)

{
  return 1;
}



// Function: __CRT_INIT@12 at 6f3e1056

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
    if (DAT_6f3e3018 < 1) {
      return 0;
    }
    DAT_6f3e3018 = DAT_6f3e3018 + -1;
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_6f3e3350,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_6f3e334c == 2) {
      param_2 = (int *)DecodePointer(DAT_6f3e3358);
      if (param_2 != (int *)0x0) {
        piVar4 = (int *)DecodePointer(DAT_6f3e3354);
        param_1 = piVar4;
        param_3 = param_2;
        while (piVar4 = piVar4 + -1, param_2 <= piVar4) {
          if ((*piVar4 != 0) && (iVar5 = encoded_null(), *piVar4 != iVar5)) {
            pcVar6 = (code *)DecodePointer((PVOID)*piVar4);
            iVar5 = encoded_null();
            *piVar4 = iVar5;
            (*pcVar6)();
            piVar7 = (int *)DecodePointer(DAT_6f3e3358);
            piVar8 = (int *)DecodePointer(DAT_6f3e3354);
            if ((param_3 != piVar7) || (param_1 != piVar8)) {
              piVar4 = piVar8;
              param_1 = piVar8;
              param_2 = piVar7;
              param_3 = piVar7;
            }
          }
        }
        free(param_2);
        DAT_6f3e3354 = (PVOID)encoded_null();
        DAT_6f3e3358 = DAT_6f3e3354;
      }
      DAT_6f3e334c = 0;
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_6f3e3350,0);
      }
    }
    else {
      _amsg_exit(0x1f);
    }
  }
  else if (param_2 == (int *)0x1) {
    bVar1 = false;
    while (pvVar3 = (void *)InterlockedCompareExchange((LONG *)&DAT_6f3e3350,(LONG)Exchange,0),
          pvVar3 != (void *)0x0) {
      if (pvVar3 == Exchange) {
        bVar1 = true;
        break;
      }
      Sleep(1000);
    }
    if (DAT_6f3e334c == 0) {
      DAT_6f3e334c = 1;
      iVar5 = initterm_e(&DAT_6f3e2084,&DAT_6f3e208c);
      if (iVar5 != 0) {
        return 0;
      }
      initterm(&DAT_6f3e207c,&DAT_6f3e2080);
      DAT_6f3e334c = 2;
    }
    else {
      _amsg_exit(0x1f);
    }
    if (!bVar1) {
      InterlockedExchange((LONG *)&DAT_6f3e3350,0);
    }
    if ((DAT_6f3e335c != (code *)0x0) &&
       (BVar2 = __IsNonwritableInCurrentImage((PBYTE)&DAT_6f3e335c), BVar2 != 0)) {
      (*DAT_6f3e335c)(param_1,2,param_3);
    }
    DAT_6f3e3018 = DAT_6f3e3018 + 1;
  }
  return 1;
}



// Function: ___DllMainCRTStartup at 6f3e1260

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x6f3e1300) */
/* WARNING: Removing unreachable block (ram,0x6f3e12ad) */
/* WARNING: Removing unreachable block (ram,0x6f3e132d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2010 Release */

int __fastcall ___DllMainCRTStartup(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_20;
  
  _DAT_6f3e3000 = param_2;
  if ((param_2 == (int *)0x0) && (DAT_6f3e3018 == 0)) {
    local_20 = 0;
  }
  else if (((param_2 != (int *)0x1) && (param_2 != (int *)0x2)) ||
          (local_20 = __CRT_INIT_12(param_3,param_2,param_1), local_20 != 0)) {
    local_20 = FUN_6f3e1000();
    if ((param_2 == (int *)0x1) && (local_20 == 0)) {
      FUN_6f3e1000();
      __CRT_INIT_12(param_3,(int *)0x0,param_1);
    }
    if (((param_2 == (int *)0x0) || (param_2 == (int *)0x3)) &&
       (iVar1 = __CRT_INIT_12(param_3,param_2,param_1), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  FUN_6f3e136b();
  return local_20;
}



// Function: FUN_6f3e136b at 6f3e136b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_6f3e136b(void)

{
  _DAT_6f3e3000 = 0xffffffff;
  return;
}



// Function: entry at 6f3e1376

void entry(int *param_1,int *param_2,int *param_3)

{
  if (param_2 == (int *)0x1) {
    ___security_init_cookie();
  }
  ___DllMainCRTStartup(param_3,param_2,param_1);
  return;
}



// Function: __onexit at 6f3e13a5

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
  
  local_8 = &DAT_6f3e2130;
  uStack_c = 0x6f3e13b1;
  local_20[0] = DecodePointer(DAT_6f3e3358);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_6f3e3358);
    local_24 = DecodePointer(DAT_6f3e3354);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_6f3e3358 = EncodePointer(local_20[0]);
    DAT_6f3e3354 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_6f3e143d();
  }
  return p_Var1;
}



// Function: FUN_6f3e143d at 6f3e143d

void FUN_6f3e143d(void)

{
  _unlock(8);
  return;
}



// Function: _atexit at 6f3e1446

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 2010 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// Function: __ValidateImageBase at 6f3e14b0

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



// Function: __FindPESection at 6f3e14f0

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



// Function: __IsNonwritableInCurrentImage at 6f3e1540

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
  
  pcStack_10 = FUN_6f3e1679;
  local_14 = ExceptionList;
  local_c = DAT_6f3e3010 ^ 0x6f3e2150;
  ExceptionList = &local_14;
  local_8 = 0;
  BVar1 = __ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_6f3e0000);
  if (BVar1 != 0) {
    p_Var2 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_6f3e0000,(DWORD_PTR)(pTarget + -0x6f3e0000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      ExceptionList = local_14;
      return ~(p_Var2->Characteristics >> 0x1f) & 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}



// Function: __SEH_prolog4 at 6f3e1620

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
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_6f3e3010 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// Function: __SEH_epilog4 at 6f3e1665

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



// Function: FUN_6f3e1679 at 6f3e1679

void __cdecl
FUN_6f3e1679(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_6f3e3010,&LAB_6f3e1752,param_1,param_2,param_3,param_4);
  return;
}



// Function: ___security_init_cookie at 6f3e169e

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
  if ((DAT_6f3e3010 == 0xbb40e64e) || ((DAT_6f3e3010 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter(&local_14);
    DAT_6f3e3010 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
    if (DAT_6f3e3010 == 0xbb40e64e) {
      DAT_6f3e3010 = 0xbb40e64f;
    }
    else if ((DAT_6f3e3010 & 0xffff0000) == 0) {
      DAT_6f3e3010 = DAT_6f3e3010 | (DAT_6f3e3010 | 0x4711) << 0x10;
    }
    DAT_6f3e3014 = ~DAT_6f3e3010;
  }
  else {
    DAT_6f3e3014 = ~DAT_6f3e3010;
  }
  return;
}



